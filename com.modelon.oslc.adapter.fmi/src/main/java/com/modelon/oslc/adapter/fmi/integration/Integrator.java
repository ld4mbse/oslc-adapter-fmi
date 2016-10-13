/*
* Integrator.java    1.1.0  2016-07-22
*  
* Copyright (c) 2016 Modelon AB  http://www.modelon.com
* 
*  All rights reserved. This program and the accompanying materials
*  are made available under the terms of the Eclipse Public License v1.0
*  and Eclipse Distribution License v. 1.0 which accompanies this distribution.
*
*  The Eclipse Public License is available at http://www.eclipse.org/legal/epl-v10.html
*  and the Eclipse Distribution License is available at
*  http://www.eclipse.org/org/documents/edl-v10.php.
* 
*  @author Vorachet Jaroensawas, Koneksys (vorachet.jaroensawas@koneksys.com)
*/

package com.modelon.oslc.adapter.fmi.integration;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.StringReader;
import java.net.URI;
import java.net.URLEncoder;
import java.nio.ByteBuffer;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

import com.modelon.oslc.adapter.fmi.application.Domain2OSLCManager;
import com.modelon.oslc.adapter.fmi.integration.OSUtils.OSType;
import com.modelon.oslc.adapter.fmi.resources.*;

public class Integrator {

  public static List<FMU> loadedFMUObjects;
  public static String cIntfPath;
  public static String fmuRepoDir;
  public static String fmuTempDir;


  public static String USER_HOME_CONF_FILE_PATH = System.getProperty("user.home") + File.separator + "fmi";
  public static String TOMCAT_DEV_MODE_CONF_FILE_PATH = "conf" + File.separator + "fmi";
  public static String TOMCAT_PROD_MODE_CONF_FILE_PATH = ".." + File.separator + "fmi";

  private static String runtimeConfDirPath;
  private static String runtimeConfFilePath;

  private static void loadConfFile() throws Exception {
    Properties prop = new Properties();
    InputStream fis = null;
    String fileContent = "";
    
    try {
        runtimeConfDirPath = USER_HOME_CONF_FILE_PATH;
        System.out.println("USER_HOME_CONF_FILE_PATH = " + USER_HOME_CONF_FILE_PATH);
        runtimeConfFilePath = runtimeConfDirPath + File.separator + "conf" + File.separator + "conf.properties";
        System.out.println("USER_HOME_CONF_FILE_PATH runtimeConfFilePath = " + runtimeConfFilePath);
        fis = new FileInputStream(runtimeConfFilePath); 
      } catch (FileNotFoundException e) {
        try {
          runtimeConfDirPath = TOMCAT_DEV_MODE_CONF_FILE_PATH;
          System.out.println("TOMCAT_DEV_MODE_CONF_FILE_PATH = " + TOMCAT_DEV_MODE_CONF_FILE_PATH);
          runtimeConfFilePath = runtimeConfDirPath + File.separator + "conf" + File.separator + "conf.properties";
          System.out.println("TOMCAT_DEV_MODE_CONF_FILE_PATH runtimeConfFilePath = " + runtimeConfFilePath);
          fis = new FileInputStream(runtimeConfFilePath);
        } catch (FileNotFoundException e1) {
          try {
            runtimeConfDirPath = TOMCAT_PROD_MODE_CONF_FILE_PATH;
            System.out.println("TOMCAT_PROD_MODE_CONF_FILE_PATH = " + TOMCAT_PROD_MODE_CONF_FILE_PATH);
            runtimeConfFilePath = runtimeConfDirPath + File.separator + "conf" + File.separator + "conf.properties";
            System.out.println("TOMCAT_PROD_MODE_CONF_FILE_PATH runtimeConfFilePath = " + runtimeConfFilePath);
            fis = new FileInputStream(runtimeConfFilePath);
          } catch(FileNotFoundException e2) {
            throw new IOException(
                "Configuration directory at USER_HOME_CONF_FILE_PATH = " + USER_HOME_CONF_FILE_PATH +
                " or TOMCAT_DEV_MODE_CONF_FILE_PATH = " + TOMCAT_DEV_MODE_CONF_FILE_PATH +
                " or TOMCAT_PROD_MODE_CONF_FILE_PATH = " + TOMCAT_PROD_MODE_CONF_FILE_PATH + " cannot be found"
            );
        }
      }
      
      if (fis != null) {
        try {
          fileContent = readFile(runtimeConfFilePath, Charset.defaultCharset());
          prop.load(new StringReader(fileContent));
          fmuRepoDir = prop.getProperty("repository");
          if (fmuRepoDir == null) {
            throw new IOException(
              "ConfigFile: " + runtimeConfFilePath  + " must contain 'repository' variable"
            );
          }
          
          if (fmuRepoDir == null || fmuRepoDir.equals("")) {
            fmuRepoDir = runtimeConfDirPath + File.separator + "fmu" + File.separator;
          }

          OSType osType = OSUtils.getOperatingSystemType();
          String cpuBit = OSUtils.getCPU();
          System.out.println("Detected cpuBit: " + cpuBit);

          if (osType == OSType.Windows) {
            System.out.println("Detected OS: Windows");
            cIntfPath = runtimeConfDirPath + File.separator + "bin" +
                File.separator + "win" + cpuBit + File.separator + "FMIClient.exe";

          } else if (osType == OSType.MacOS) {
            System.out.println("Detected OS: MacOS");
            cIntfPath = runtimeConfDirPath + File.separator + "bin" +
                File.separator + "darwin" + cpuBit + File.separator + "FMIClient";

          } else if (osType == OSType.Linux) {
            System.out.println("Detected OS: Linux");
            cIntfPath = runtimeConfDirPath + File.separator + "bin" +
                File.separator + "linux" + cpuBit + File.separator + "FMIClient";

          } else if (osType == OSType.Other) { 
            System.out.println("Detected OS: Other");
            throw new IOException("The current operating system is not supported");

          } else {
            throw new IOException("Operating system cannot be detected");
          }
          
          System.out.println("FMIClient: " + cIntfPath);
          System.out.println("ConfigFile: " + runtimeConfFilePath  + " (repository = " + fmuRepoDir + ")");

          fmuTempDir = runtimeConfDirPath + File.separator + "temp";
          System.out.println("BaseTempDir: " + fmuTempDir + " (Each modelDescription.xml will be unzipped to this directory)");

        } catch(IOException e3) {
          throw new IOException(e.getMessage());
        } finally {
          try {
            fis.close();
          } catch (IOException e4) {
            e.printStackTrace();
          }
        }
      }
    }
  }

  static String readFile(String path, Charset encoding) throws IOException {
  byte[] encoded = Files.readAllBytes(Paths.get(path));
    return encoding.decode(ByteBuffer.wrap(encoded)).toString();
  }
  
  public static boolean isNullOrEmpty(String str) {
    if(str != null && !str.isEmpty() && !str.equals("(null)") && !str.equals("null")) return false;
    else return true;
  }

  public static String getValue(String str) {
    return isNullOrEmpty(str) ? "NotFound" : str;
  }

  public static void initialize() throws Exception {
  loadConfFile();
    loadFMUObjectsFromFMURepoDirectory(cIntfPath, fmuRepoDir, fmuTempDir);
    tranformsFMUObjectsToOSLCResources();
  }

  public static String generateServiceProviderIdentifierFromTopLevelInstance(int index) {
      FMU fmu = loadedFMUObjects.get(index);
      String fmiVersion = fmu.fmiVersion;
      String fmuModelIdentifier = fmu.fmiModelDescription.modelIdentifier;
      String profile = fmu.isCoSimulationFMU.equals("true") ? "CS" : "ME";
      String uniqueFMIIdentifier = "FMI" + fmiVersion + "_" + profile + "_" + fmuModelIdentifier;
      return uniqueFMIIdentifier;
  }

  private static void loadFMUObjectsFromFMURepoDirectory(
    String userCIntfPath, String userFMURepoDir, String userFMUTempDir) throws Exception {
    try {
      cIntfPath = userCIntfPath;
      fmuRepoDir = userFMURepoDir;
      fmuTempDir = userFMUTempDir;
      loadedFMUObjects = FMUConnector.loadFMUsFromDir(
        cIntfPath, fmuRepoDir, fmuTempDir);
    } catch (IOException e) {
      throw new Exception("ERROR: Please check this error detail: " + e.toString());
    }
  }

  private static String fixIdentifier(String identifier) throws Exception {
    // These character not valid with Wink. It sohuld be converted to URL encoded text.
    if (identifier.contains(" ") || identifier.contains("[") || identifier.contains("]")) {
      return URLEncoder.encode(identifier, "UTF-8");
    } else {
      return identifier;
    }
  }

  private static void tranformsFMUObjectsToOSLCResources() throws Exception {
    if (loadedFMUObjects == null || loadedFMUObjects.size() == 0) {
      throw new Exception(
        "No FMU files in " + fmuRepoDir + ". The adapter will not be started by default"
      );
    }
    
    int runningNumberForModelNotFound = 0;
    for (FMU fmu : loadedFMUObjects) {

      // FMU
      FMIFMU fmiFMU = new FMIFMU();
      String profile = fmu.isCoSimulationFMU.equals("true") ? "CS" : "ME";
      String fmiFMUUniqueId = "FMI" + fmu.fmiVersion + "_" + profile + "_" + fmu.fmiModelDescription.modelIdentifier;

      String fmiFMUIdentifier = fixIdentifier(fmiFMUUniqueId);
      fmiFMU.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/FMU/" + fmiFMUIdentifier));
      fmiFMU.setIdentifier(fmiFMUIdentifier);
      fmiFMU.setFmiVersion(getValue(fmu.fmiVersion));
      fmiFMU.setIsModelExchangeFMU(getValue(fmu.isModelExchangeFMU));
      fmiFMU.setIsCoSimulationFMU(getValue(fmu.isCoSimulationFMU));
    
      List<FMIFMU> _fmuList = new ArrayList<FMIFMU>();
      _fmuList.add(fmiFMU);
      Domain2OSLCManager.fmiFMUMap.put(fmiFMUIdentifier, _fmuList);
      Domain2OSLCManager.fmiFMUMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiFMUIdentifier, fmiFMU);
      Domain2OSLCManager.topLevelConceptList.add(fmiFMU);

      // FMU->ModelDescription
      FMIModelDescription theFMIModelDescription = new FMIModelDescription();

      String fmiModelDescriptionIdentifier = fixIdentifier(fmu.fmiModelDescription.modelName);
      theFMIModelDescription.setIdentifier(fmiModelDescriptionIdentifier);
      theFMIModelDescription.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/ModelDescription/" + fmiModelDescriptionIdentifier));
      theFMIModelDescription.setAuthor(getValue(fmu.fmiModelDescription.author));
      theFMIModelDescription.setCopyright(getValue(fmu.fmiModelDescription.copyright));
      theFMIModelDescription.setDescription(getValue(fmu.fmiModelDescription.description ));
      theFMIModelDescription.setFmiVersion(getValue(fmu.fmiModelDescription.fmiVersion));
      theFMIModelDescription.setGenerationDateAndTime(getValue(fmu.fmiModelDescription.generationDateAndTime));
      theFMIModelDescription.setGenerationTool(getValue(fmu.fmiModelDescription.generationTool));
      theFMIModelDescription.setGuid(getValue(fmu.fmiModelDescription.guid));
      theFMIModelDescription.setKind(getValue(fmu.fmiModelDescription.kind));
      theFMIModelDescription.setModelIdentifier(getValue(fmu.fmiModelDescription.modelIdentifier));
      theFMIModelDescription.setLicense(getValue(fmu.fmiModelDescription.license));
      theFMIModelDescription.setVersion(getValue(fmu.fmiModelDescription.version));
      if (isNullOrEmpty(fmu.fmiModelDescription.modelName)) {
        runningNumberForModelNotFound++;
        theFMIModelDescription.setModelName("ModelNameNotfound" + runningNumberForModelNotFound);
      } else {
        theFMIModelDescription.setModelName(fmu.fmiModelDescription.modelName);
      }

      theFMIModelDescription.setVariableNamingConvention(getValue(fmu.fmiModelDescription.variableNamingConvention));
      theFMIModelDescription.setNumberOfContinuousStates(getValue(fmu.fmiModelDescription.numberOfContinuousStates));
      theFMIModelDescription.setNumberOfEventIndicators(getValue(fmu.fmiModelDescription.numberOfEventIndicators));
      theFMIModelDescription.setFmuPath(getValue(fmu.fmiModelDescription.fmuPath));
      theFMIModelDescription.setTmpPath(getValue(fmu.fmiModelDescription.tmpPath));
      
      fmiFMU.setModelDescription(theFMIModelDescription.getAbout());

      List<FMIModelDescription> _modelDescriptionList = new ArrayList<FMIModelDescription>();
      _modelDescriptionList.add(theFMIModelDescription);
      Domain2OSLCManager.fmiModelDescriptionMap.put(fmiFMUIdentifier, _modelDescriptionList);
      Domain2OSLCManager.fmiModelDescriptionMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiModelDescriptionIdentifier, theFMIModelDescription);

      // Model Structure
      if (fmu.fmiModelDescription.modelStructure != null) {
        FMIModelStructure theModelStructure = new FMIModelStructure();
        String fmiModelStructureIdentifier = fmiModelDescriptionIdentifier;
        theModelStructure.setIdentifier(fmiModelStructureIdentifier);
        theModelStructure.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/ModelStructure/" + fmiModelStructureIdentifier));

        // Model Structure -> Derivative
        List<FMIDerivative> allDerivatives = new ArrayList<FMIDerivative>();
        if (fmu.fmiModelDescription.modelStructure.derivatives != null) {
          int index = 0;
          for(Derivative fromFile: fmu.fmiModelDescription.modelStructure.derivatives) {
            FMIDerivative theDerivative = new FMIDerivative();

            String fmiDerivativedentifier = fixIdentifier(fromFile.name);
            DerivativeDependencies fromFileHelper = fmu.fmiModelDescription.modelStructure.derivativesDependencies.get(index);
            theDerivative.setIdentifier(fmiDerivativedentifier);
            theDerivative.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/Derivative/" + fmiDerivativedentifier));
            theDerivative.setIndex(fromFile.index);
            theDerivative.setName(fromFile.name);
            theDerivative.setDependencies(fromFileHelper.dependencies);
            theDerivative.setDependenciesKind(fromFileHelper.dependenciesKind);
            allDerivatives.add(theDerivative);
            index++;
            
            Domain2OSLCManager.fmiDerivativeMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiDerivativedentifier, theDerivative);
          }
        }

        Domain2OSLCManager.fmiDerivativeMap.put(fmiFMUIdentifier, allDerivatives);
        theModelStructure.setDerivatives(Domain2OSLCManager.getLinkArray(allDerivatives));
        
        // Model Structure -> InitialUnknown
        List<FMIInitialUnknown> allInitialUnknowns = new ArrayList<FMIInitialUnknown>();
        if (fmu.fmiModelDescription.modelStructure.initialUnknowns != null) {
          int index = 0;
          for(InitialUnknown fromFile: fmu.fmiModelDescription.modelStructure.initialUnknowns) {
            InitialUnknownDependencies fromFileHelper = fmu.fmiModelDescription.modelStructure.initialUnknownsDependencies.get(index);
            FMIInitialUnknown theInitialUnknown = new FMIInitialUnknown();

            String initialUnknownIdentifier = fixIdentifier(fromFile.name);
            theInitialUnknown.setIdentifier(initialUnknownIdentifier);
            theInitialUnknown.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/InitialUnknown/" + initialUnknownIdentifier));
            theInitialUnknown.setIndex(fromFile.index);
            theInitialUnknown.setName(fromFile.name);
            theInitialUnknown.setDependencies(fromFileHelper.dependencies);
            theInitialUnknown.setDependenciesKind(fromFileHelper.dependenciesKind);
            index++;
            allInitialUnknowns.add(theInitialUnknown);
            
            Domain2OSLCManager.fmiInitialUnknownMapByIdentifier.put(fmiFMUIdentifier + "_" + initialUnknownIdentifier, theInitialUnknown);
          }
        }

        Domain2OSLCManager.fmiInitialUnknownMap.put(fmiFMUIdentifier, allInitialUnknowns);
        theModelStructure.setInitialUnknowns(Domain2OSLCManager.getLinkArray(allInitialUnknowns));

        // Model Structure -> Output
        List<FMIOutput> allOutputs = new ArrayList<FMIOutput>();
        if (fmu.fmiModelDescription.modelStructure.outputs != null) {
          int index = 0;
            for(Output fromFile: fmu.fmiModelDescription.modelStructure.outputs) {
              OutputDependencies fromFileHelper = fmu.fmiModelDescription.modelStructure.outputsDependencies.get(index);

              String outputIdentifier = fixIdentifier(fromFile.name);

              FMIOutput theOutput = new FMIOutput();
              theOutput.setIdentifier(outputIdentifier);
              theOutput.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/Output/" + outputIdentifier));
              theOutput.setIndex(fromFile.index);
              theOutput.setName(fromFile.name);
              theOutput.setDependencies(fromFileHelper.dependencies);
              theOutput.setDependenciesKind(fromFileHelper.dependenciesKind);
              index++;
              allOutputs.add(theOutput);
              
              Domain2OSLCManager.fmiOutputMapByIdentifier.put(fmiFMUIdentifier + "_" + outputIdentifier, theOutput);
            }
        }

        Domain2OSLCManager.fmiOutputMap.put(fmiFMUIdentifier, allOutputs);
        theModelStructure.setOutputs(Domain2OSLCManager.getLinkArray(allOutputs));

        theFMIModelDescription.setModelStructure(theModelStructure.getAbout());

        List<FMIModelStructure> _modelStructureList = new ArrayList<FMIModelStructure>();
        _modelStructureList.add(theModelStructure);
        Domain2OSLCManager.fmiModelStructureMap.put(fmiFMUIdentifier, _modelStructureList);
        Domain2OSLCManager.fmiModelStructureMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiModelStructureIdentifier, theModelStructure);
      }

      // ModelExchange
      if (fmu.fmiModelDescription.modelExchange != null) {
        FMIModelExchange theFMIModelExchange = new FMIModelExchange();

        String fmiModelExchangeIdentifier = fmiModelDescriptionIdentifier;
        theFMIModelExchange.setIdentifier(fmiModelExchangeIdentifier);
        theFMIModelExchange.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/ModelExchange/" + fmiModelExchangeIdentifier));
        theFMIModelExchange.setModelIdentifier(getValue(fmu.fmiModelDescription.modelExchange.modelIdentifier));
        theFMIModelExchange.setCanBeInstantiatedOnlyOncePerProcess(getValue(fmu.fmiModelDescription.modelExchange.canBeInstantiatedOnlyOncePerProcess));
        theFMIModelExchange.setCanGetAndSetFMUstate(getValue(fmu.fmiModelDescription.modelExchange.canGetAndSetFMUstate));
        theFMIModelExchange.setCanNotUseMemoryManagementFunctions(getValue(fmu.fmiModelDescription.modelExchange.canNotUseMemoryManagementFunctions));
        theFMIModelExchange.setCanSerializeFMUstate(getValue(fmu.fmiModelDescription.modelExchange.canSerializeFMUstate));
        theFMIModelExchange.setCompletedEventIterationIsProvided(getValue(fmu.fmiModelDescription.modelExchange.completedEventIterationIsProvided));
        theFMIModelExchange.setCompletedIntegratorStepNotNeeded(getValue(fmu.fmiModelDescription.modelExchange.completedIntegratorStepNotNeeded));
        theFMIModelExchange.setNeedsExecutionTool(getValue(fmu.fmiModelDescription.modelExchange.needsExecutionTool));
        theFMIModelExchange.setProvidesDirectionalDerivatives(getValue(fmu.fmiModelDescription.modelExchange.providesDirectionalDerivatives));

        // Model Exchange > Source Files
        List<FMISourceFile> allScalarFiles = new ArrayList<FMISourceFile>();
        if (fmu.fmiModelDescription.modelExchange.sourceFiles != null) {
            for(SourceFile sourceFile: fmu.fmiModelDescription.modelExchange.sourceFiles) {
              FMISourceFile theSourceFile = new FMISourceFile();

              String sourceFileIdentifier = fixIdentifier(sourceFile.file);
              theSourceFile.setIdentifier(sourceFileIdentifier);
              theSourceFile.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/ModelExchange/SourceFile/" + sourceFileIdentifier));
              theSourceFile.setFile(sourceFile.file);
              allScalarFiles.add(theSourceFile);
              
              Domain2OSLCManager.fmiSourceFileMapByIdentifier.put(fmiFMUIdentifier + "_" + sourceFileIdentifier, theSourceFile);
            }
        }

        theFMIModelExchange.setSourceFiles(Domain2OSLCManager.getLinkArray(allScalarFiles));
        Domain2OSLCManager.fmiSourceFileMap.put(fmiFMUIdentifier, allScalarFiles);
       
        theFMIModelDescription.setModelExchange(theFMIModelExchange.getAbout());

        List<FMIModelExchange> _modelExchangeList = new ArrayList<FMIModelExchange>();
        _modelExchangeList.add(theFMIModelExchange);
        Domain2OSLCManager.fmiModelExchangeMap.put(fmiFMUIdentifier, _modelExchangeList);
        Domain2OSLCManager.fmiModelExchangeMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiModelExchangeIdentifier, theFMIModelExchange);

      }

      // CoSimulation
      if (fmu.fmiModelDescription.coSimulation != null) {
        FMICoSimulation theFMICoSimulation = new FMICoSimulation();
        String fmiCoSimulationIdentifier = fmiModelDescriptionIdentifier;
        theFMICoSimulation.setIdentifier(fmiCoSimulationIdentifier);
        theFMICoSimulation.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/CoSimulation/" + fmiCoSimulationIdentifier));
        theFMICoSimulation.setModelIdentifier(getValue(fmu.fmiModelDescription.coSimulation.modelIdentifier));
        theFMICoSimulation.setNeedsExecutionTool(getValue(fmu.fmiModelDescription.coSimulation.needsExecutionTool));
        theFMICoSimulation.setCanGetAndSetFMUstate(getValue(fmu.fmiModelDescription.coSimulation.canGetAndSetFMUstate));
        theFMICoSimulation.setCanSerializeFMUstate(getValue(fmu.fmiModelDescription.coSimulation.canSerializeFMUstate));
        theFMICoSimulation.setProvidesDirectionalDerivatives(getValue(fmu.fmiModelDescription.coSimulation.providesDirectionalDerivatives));
        theFMICoSimulation.setCanHandleVariableCommunicationStepSize(getValue(fmu.fmiModelDescription.coSimulation.canHandleVariableCommunicationStepSize));
        theFMICoSimulation.setCanHandleEvents(getValue(fmu.fmiModelDescription.coSimulation.canHandleEvents));
        theFMICoSimulation.setCanRejectSteps(getValue(fmu.fmiModelDescription.coSimulation.canRejectSteps));
        theFMICoSimulation.setCanInterpolateInputs(getValue(fmu.fmiModelDescription.coSimulation.canInterpolateInputs));
        theFMICoSimulation.setMaxOutputDerivativeOrder(getValue(fmu.fmiModelDescription.coSimulation.maxOutputDerivativeOrder));
        theFMICoSimulation.setCanRunAsynchronuously(getValue(fmu.fmiModelDescription.coSimulation.canRunAsynchronuously));
        theFMICoSimulation.setCanSignalEvents(getValue(fmu.fmiModelDescription.coSimulation.canSignalEvents));
        theFMICoSimulation.setCanBeInstantiatedOnlyOncePerProcess(getValue(fmu.fmiModelDescription.coSimulation.canBeInstantiatedOnlyOncePerProcess));
        theFMICoSimulation.setCanNotUseMemoryManagementFunctions(getValue(fmu.fmiModelDescription.coSimulation.canNotUseMemoryManagementFunctions));

        // CoSimulation > Source Files
        List<FMISourceFile> allScalarFiles = new ArrayList<FMISourceFile>();
        if (fmu.fmiModelDescription.modelExchange.sourceFiles != null) {
            for(SourceFile sourceFile: fmu.fmiModelDescription.modelExchange.sourceFiles) {
              FMISourceFile theSourceFile = new FMISourceFile();
              // We currently choose source file name for OSLC FMISourceFile resource identifier 
              String sourceFileIdentifier = fixIdentifier(sourceFile.file);
              theSourceFile.setIdentifier(sourceFileIdentifier);
              theSourceFile.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/CoSimulation/SourceFile/" + sourceFileIdentifier));
              theSourceFile.setFile(sourceFile.file);
              allScalarFiles.add(theSourceFile);
              
              Domain2OSLCManager.fmiSourceFileMapByIdentifier.put(fmiFMUIdentifier + "_" + sourceFileIdentifier, theSourceFile);
            }
        }

        theFMICoSimulation.setSourceFiles(Domain2OSLCManager.getLinkArray(allScalarFiles));
        Domain2OSLCManager.fmiSourceFileMap.put(fmiFMUIdentifier, allScalarFiles);
       
        theFMIModelDescription.setCoSimulation(theFMICoSimulation.getAbout());

        List<FMICoSimulation> _coSimulationList = new ArrayList<FMICoSimulation>();
        _coSimulationList.add(theFMICoSimulation);
        Domain2OSLCManager.fmiCoSimulationMap.put(fmiFMUIdentifier, _coSimulationList);
        Domain2OSLCManager.fmiCoSimulationMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiCoSimulationIdentifier, theFMICoSimulation);
      }

      // DefaultExperiment
      if (fmu.fmiModelDescription.defaultExperiment != null) {
        FMIDefaultExperiment theFMIDefaultExperiment = new FMIDefaultExperiment();
        String fmiDefaultExperimentIdentifier = fmiModelDescriptionIdentifier;
        theFMIDefaultExperiment.setIdentifier(fmiDefaultExperimentIdentifier);
        theFMIDefaultExperiment.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/DefaultExperiment/" + fmiDefaultExperimentIdentifier));
        theFMIDefaultExperiment.setStartTime(getValue(fmu.fmiModelDescription.defaultExperiment.startTime));
        theFMIDefaultExperiment.setStopTime(getValue(fmu.fmiModelDescription.defaultExperiment.stopTime ));
        theFMIDefaultExperiment.setTolerance(getValue(fmu.fmiModelDescription.defaultExperiment.tolerance));
        theFMIDefaultExperiment.setStep(getValue(fmu.fmiModelDescription.defaultExperiment.step));

        theFMIModelDescription.setDefaultExperiment(theFMIDefaultExperiment.getAbout());

        List<FMIDefaultExperiment> _defaultExperimentList = new ArrayList<FMIDefaultExperiment>();
        _defaultExperimentList.add(theFMIDefaultExperiment);
        Domain2OSLCManager.fmiDefaultExperimentMap.put(fmiFMUIdentifier, _defaultExperimentList);
        Domain2OSLCManager.fmiDefaultExperimentMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiDefaultExperimentIdentifier, theFMIDefaultExperiment);
      }


      // FMIModelVariables
      FMIModelVariables theFMIModelVariables = new FMIModelVariables();
      String fmiModelVariablesIdentifier = fmiModelDescriptionIdentifier;
      theFMIModelVariables.setIdentifier(fmiModelVariablesIdentifier);
      theFMIModelVariables.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/ModelVariables/" + fmiModelVariablesIdentifier));

      // FMIModelVariables -----> FMIScalarVariable
      if (fmu.fmiModelDescription.modelVariables != null && fmu.fmiModelDescription.modelVariables.scalarVariables != null) {
        List<FMIScalarVariable> allFMIScalarVariables = new ArrayList<FMIScalarVariable>();
        int varIndex = 0;
        for(ScalarVariable scalarVariable: fmu.fmiModelDescription.modelVariables.scalarVariables) {
          varIndex++; 
          // The initial original var index that used in ModelSturcture must be 1
          // We currently choose Scalavariable Name for OSLC FMIScalarVariable resource identifier 
          String scalarVariableIdentifier = fixIdentifier(scalarVariable.name);

          // We currently choose Scalavariable index for additional OSLC FMIScalarVariable resource identifier 
          // This demonstrate query by index
          String scalarVariableIdentifierByIndex = "" + varIndex;

          // We currently choose Scalavariable name for additional OSLC FMIScalarVariable resource identifier 
          // This demonstrate query by name
          String scalarVariableIdentifierByName = scalarVariableIdentifier;

          FMIScalarVariable theFMIScalarVariable = new FMIScalarVariable();
          theFMIScalarVariable.setIdentifier(scalarVariableIdentifier);
          theFMIScalarVariable.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/ScalarVariable/" + scalarVariableIdentifier));
          theFMIScalarVariable.setIndex("" + varIndex);
          theFMIScalarVariable.setCausality(getValue(scalarVariable.causality));
          theFMIScalarVariable.setDescription(getValue(scalarVariable.description));
          theFMIScalarVariable.setInitial(getValue(scalarVariable.initial));
          theFMIScalarVariable.setName(getValue(scalarVariable.name));
          theFMIScalarVariable.setValueReference(getValue(scalarVariable.valueReference));
          theFMIScalarVariable.setVariability(getValue(scalarVariable.variability));
          theFMIScalarVariable.setIsAlias(getValue(scalarVariable.isAlias));
          theFMIScalarVariable.setAliasBase(getValue(scalarVariable.aliasBase));

          // FMIModelVariables > FMIScalarVariable > ListingAlias
          if (scalarVariable.listingAliases != null) {
            List<FMIListingAlias> allListingAliases = new ArrayList<FMIListingAlias>();
            for(ListingAlias listingAlias: scalarVariable.listingAliases) {
              FMIListingAlias theListingAlias = new FMIListingAlias();
              // We currently choose ListingAliases Name for OSLC FMIListingAlias resource identifier 
              String listingAliasIdentifier = fixIdentifier(listingAlias.name);
              theListingAlias.setIdentifier(listingAliasIdentifier);
              theListingAlias.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/ListingAlias/" + listingAliasIdentifier));
              theListingAlias.setName(listingAlias.name);

              Domain2OSLCManager.fmiListingAliasMapByIdentifier.put(fmiFMUIdentifier + "_" + listingAliasIdentifier, theListingAlias);
            }
            theFMIScalarVariable.setListingAliases(Domain2OSLCManager.getLinkArray(allListingAliases));
            Domain2OSLCManager.fmiListingAliasMap.put(fmiFMUIdentifier, allListingAliases);
          }

          
          // FMIModelVariables > FMIScalarVariable > ListingDirectDependency
          if (scalarVariable.listingDirectDependencies != null) {
            List<FMIListingDirectDependency> allListingDirectDependencies = new ArrayList<FMIListingDirectDependency>();
            for(ListingDirectDependency listingDirectDependency: scalarVariable.listingDirectDependencies) {
              FMIListingDirectDependency theFMIListingDirectDependency = new FMIListingDirectDependency();
              // We currently choose ListingDirectDependency Name for OSLC FMIListingDirectDependency resource identifier 
              String listingDirectDependencyIdentifier = fixIdentifier(listingDirectDependency.name);
              theFMIListingDirectDependency.setIdentifier(listingDirectDependencyIdentifier);
              theFMIListingDirectDependency.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/ListingDirectDependency/" + listingDirectDependencyIdentifier));
              theFMIListingDirectDependency.setName(listingDirectDependency.name);

              Domain2OSLCManager.fmiListingDirectDependencyMapByIdentifier.put(fmiFMUIdentifier + "_" + listingDirectDependencyIdentifier, theFMIListingDirectDependency);
            }
            theFMIScalarVariable.setListingDirectDependencies(Domain2OSLCManager.getLinkArray(allListingDirectDependencies));
            Domain2OSLCManager.fmiListingDirectDependencyMap.put(fmiFMUIdentifier, allListingDirectDependencies);
          }


          // FMIModelVariables > FMIScalarVariable > FMIScalarVariableType
          if (scalarVariable.type != null) {
            FMIScalarVariableType theFMIScalarVariableType = new FMIScalarVariableType();
            // We currently choose scalarVariableIdentifier for OSLC FMIScalarVariableType resource identifier 
            String scalarVariableTypeIdentifier = scalarVariableIdentifier;
            theFMIScalarVariableType.setIdentifier(scalarVariableTypeIdentifier);
            theFMIScalarVariableType.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/ScalarVariableType/" + scalarVariableTypeIdentifier));
            theFMIScalarVariableType.setStart(getValue(scalarVariable.type.start));
            theFMIScalarVariableType.setDeclaredType(getValue(scalarVariable.type.declaredType));
            theFMIScalarVariableType.setDisplayUnit(getValue(scalarVariable.type.displayUnit));
            theFMIScalarVariableType.setMax(getValue(scalarVariable.type.max));
            theFMIScalarVariableType.setMin(getValue(scalarVariable.type.min));
            theFMIScalarVariableType.setName(getValue(scalarVariable.type.name));
            theFMIScalarVariableType.setNominal(getValue(scalarVariable.type.nominal));
            theFMIScalarVariableType.setUnit(getValue(scalarVariable.type.unit));

            theFMIScalarVariable.setScalarVariableType(theFMIScalarVariableType.getAbout());

            List<FMIScalarVariableType> _scalarVariablesTypeList = new ArrayList<FMIScalarVariableType>();
            _scalarVariablesTypeList.add(theFMIScalarVariableType);
            Domain2OSLCManager.fmiScalarVariableTypeMap.put(fmiFMUIdentifier, _scalarVariablesTypeList);
            Domain2OSLCManager.fmiScalarVariableTypeMapByIdentifier.put(fmiFMUIdentifier + "_" + scalarVariableIdentifier, theFMIScalarVariableType);
          }


          allFMIScalarVariables.add(theFMIScalarVariable);

          List<FMIScalarVariable> _scalarVariablesList = new ArrayList<FMIScalarVariable>();
          _scalarVariablesList.add(theFMIScalarVariable);
          Domain2OSLCManager.fmiScalarVariableMapByIdentifier.put(fmiFMUIdentifier + "_" + scalarVariableIdentifier, theFMIScalarVariable);
          Domain2OSLCManager.fmiScalarVariableMapByIndex.put(fmiFMUIdentifier + "_" + scalarVariableIdentifierByIndex, _scalarVariablesList);
          Domain2OSLCManager.fmiScalarVariableMapByName.put(fmiFMUIdentifier + "_" + scalarVariableIdentifierByName, _scalarVariablesList);
        }

        theFMIModelVariables.setScalarVariables(Domain2OSLCManager.getLinkArray(allFMIScalarVariables));
        Domain2OSLCManager.fmiScalarVariableMap.put(fmiFMUIdentifier, allFMIScalarVariables);
      }

      theFMIModelDescription.setModelVariables(theFMIModelVariables.getAbout());

      List<FMIModelVariables> _modelVariablesList = new ArrayList<FMIModelVariables>();
      _modelVariablesList.add(theFMIModelVariables);
      Domain2OSLCManager.fmiModelVariablesMap.put(fmiFMUIdentifier, _modelVariablesList);
      Domain2OSLCManager.fmiModelVariablesMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiModelVariablesIdentifier, theFMIModelVariables);



      // FMIUnitDefinition
      List<FMIUnitDefinition> allUnitDefinitions = new ArrayList<FMIUnitDefinition>();
      if (fmu.fmiModelDescription.unitDefinitions != null) {
        for(UnitDefinition unitDefinition: fmu.fmiModelDescription.unitDefinitions) {
          FMIUnitDefinition theFMIUnitDefinition = new FMIUnitDefinition();
          String fmiUnitDefinitionIdentifier = fixIdentifier(unitDefinition.name);
          fmiUnitDefinitionIdentifier = fmiUnitDefinitionIdentifier.replace("/", "Per");
          fmiUnitDefinitionIdentifier = fixIdentifier(fmiUnitDefinitionIdentifier);
          theFMIUnitDefinition.setIdentifier(fmiUnitDefinitionIdentifier);
          theFMIUnitDefinition.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/UnitDefinition/" + fmiUnitDefinitionIdentifier));
          theFMIUnitDefinition.setName(getValue(unitDefinition.name));

          // FMIUnitDefinition --0..1-> FMIBaseUnit
          if (unitDefinition.baseUnit != null) {
            FMIBaseUnit theFMIBaseUnit = new FMIBaseUnit();
            String fmiBaseUnitIdentifier = fmiUnitDefinitionIdentifier;
            theFMIBaseUnit.setIdentifier(fmiBaseUnitIdentifier);
            theFMIBaseUnit.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/BaseUnit/" + fmiBaseUnitIdentifier));
            theFMIBaseUnit.setUnit(getValue(unitDefinition.baseUnit.unit));
            theFMIBaseUnit.setFactor(getValue(unitDefinition.baseUnit.factor));
            theFMIBaseUnit.setOffset(getValue(unitDefinition.baseUnit.offset));
            theFMIBaseUnit.setDisplayUnitNumber(getValue(unitDefinition.baseUnit.displayUnitNumber));

            // FMIUnitDefinition --0..1--> FMIBaseUnit ----- 0..1---> FMIBaseUnitDefinition
            if (unitDefinition.baseUnit.baseUnitDefinition != null) {
              FMIBaseUnitDefinition theFMIBaseUnitDefinition = new FMIBaseUnitDefinition();
              String fmiBaseUnitDefinitionIdentifier = fmiUnitDefinitionIdentifier;
              theFMIBaseUnitDefinition.setIdentifier(fmiBaseUnitDefinitionIdentifier);
              theFMIBaseUnitDefinition.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/BaseUnitDefinition/" + fmiBaseUnitDefinitionIdentifier));
              theFMIBaseUnitDefinition.setDisplayUnit(getValue(unitDefinition.baseUnit.baseUnitDefinition.displayUnit));

              theFMIBaseUnit.setBaseUnitDefinition(theFMIBaseUnitDefinition.getAbout());

              List<FMIBaseUnitDefinition> theFMIBaseUnitDefinitionList = new ArrayList<FMIBaseUnitDefinition>();
              theFMIBaseUnitDefinitionList.add(theFMIBaseUnitDefinition);
              Domain2OSLCManager.fmiBaseUnitDefinitionMap.put(fmiFMUIdentifier, theFMIBaseUnitDefinitionList);
              Domain2OSLCManager.fmiBaseUnitDefinitionMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiBaseUnitDefinitionIdentifier, theFMIBaseUnitDefinition);
            }

            theFMIUnitDefinition.setBaseUnit(theFMIBaseUnit.getAbout());

            List<FMIBaseUnit> theFMIBaseUnitList = new ArrayList<FMIBaseUnit>();
            theFMIBaseUnitList.add(theFMIBaseUnit);
            Domain2OSLCManager.fmiBaseUnitMap.put(fmiFMUIdentifier, theFMIBaseUnitList);
            Domain2OSLCManager.fmiBaseUnitMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiBaseUnitIdentifier, theFMIBaseUnit);
          }

        allUnitDefinitions.add(theFMIUnitDefinition);
        Domain2OSLCManager.fmiUnitDefinitionMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiUnitDefinitionIdentifier, theFMIUnitDefinition);
        }
      }

      theFMIModelDescription.setUnitDefinitions(Domain2OSLCManager.getLinkArray(allUnitDefinitions));
      Domain2OSLCManager.fmiUnitDefinitionMap.put(fmiFMUIdentifier, allUnitDefinitions);


      // FMITypeDefinition
      if (fmu.fmiModelDescription.typeDefinitions != null) {
        List<FMITypeDefinition> allTypeDefinitions = new ArrayList<FMITypeDefinition>();
        for(TypeDefinition typeDefinition : fmu.fmiModelDescription.typeDefinitions) {
          FMITypeDefinition theFMItTypeDefinition = new FMITypeDefinition();
          String fmiTypeDefinitionIdentifier = fixIdentifier(typeDefinition.name);
          theFMItTypeDefinition.setIdentifier(fmiTypeDefinitionIdentifier);
          theFMItTypeDefinition.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI  + "/" + fmiFMUIdentifier  + "/TypeDefinition/" + fmiTypeDefinitionIdentifier));
          theFMItTypeDefinition.setDescription(getValue(typeDefinition.description));
          theFMItTypeDefinition.setName(getValue(typeDefinition.name));
          theFMItTypeDefinition.setBaseType(getValue(typeDefinition.baseType));
          theFMItTypeDefinition.setQuantity(getValue(typeDefinition.quantity));

          // FMITypeDefinition --0..1--> FMITypeDef
          if (typeDefinition.type != null) {
            FMITypeDef theFMITypeDef = new FMITypeDef();
            String fmiTypeDefIdentifier = fixIdentifier(typeDefinition.type.name);
            theFMITypeDef.setIdentifier(fmiTypeDefIdentifier);
            theFMITypeDef.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI  + "/" + fmiFMUIdentifier  + "/TypeDef/" + fmiTypeDefIdentifier));
            theFMITypeDef.setName(getValue(typeDefinition.type.name));
            theFMITypeDef.setMax(getValue(typeDefinition.type.max));
            theFMITypeDef.setMin(getValue(typeDefinition.type.min));

            // FMITypeDefinition --0..1--> FMITypeDef --0..1--> FMIEnumeration
            if ( typeDefinition.type.enumerations != null) {
              List<FMIEnumeration> allEnumerations = new ArrayList<FMIEnumeration>();
              for(EnumerationItem enumItem : typeDefinition.type.enumerations) {
                FMIEnumeration theFMIEnumeration = new FMIEnumeration();
                String fmiEnumerationIdentifier = fixIdentifier(enumItem.name);
                theFMIEnumeration.setIdentifier(fmiEnumerationIdentifier);
                theFMIEnumeration.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI  + "/" + fmiFMUIdentifier  + "/Enumeration/" + fmiEnumerationIdentifier));
                theFMIEnumeration.setName(getValue(enumItem.name));
                theFMIEnumeration.setValue(getValue(enumItem.value));
                theFMIEnumeration.setDescription(getValue(enumItem.description));

                allEnumerations.add(theFMIEnumeration);
                Domain2OSLCManager.fmiEnumerationMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiEnumerationIdentifier, theFMIEnumeration);
              }
              theFMITypeDef.setEnumerations(Domain2OSLCManager.getLinkArray(allEnumerations));
              Domain2OSLCManager.fmiEnumerationMap.put(fmiFMUIdentifier, allEnumerations);
            }

            theFMItTypeDefinition.setTypeDef(theFMITypeDef.getAbout());
            List<FMITypeDef> _typeDefList = new ArrayList<FMITypeDef>();
            _typeDefList.add(theFMITypeDef);
            Domain2OSLCManager.fmiTypeDefMap.put(fmiFMUIdentifier, _typeDefList);
            Domain2OSLCManager.fmiTypeDefMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiTypeDefIdentifier, theFMITypeDef);
          }

          allTypeDefinitions.add(theFMItTypeDefinition);
          Domain2OSLCManager.fmiTypeDefinitionMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiTypeDefinitionIdentifier, theFMItTypeDefinition);
        }

        theFMIModelDescription.setTypeDefinitions(Domain2OSLCManager.getLinkArray(allTypeDefinitions));
        Domain2OSLCManager.fmiTypeDefinitionMap.put(fmiFMUIdentifier, allTypeDefinitions);
      }


      // VendorAnnotation
      if (fmu.fmiModelDescription.vendorAnnotations != null) {
        List<FMIVendorAnnotation> allVendorAnnotations = new ArrayList<FMIVendorAnnotation>();
        for(VendorAnnotation vendorAnnotation: fmu.fmiModelDescription.vendorAnnotations) {
          FMIVendorAnnotation theFMIVendorAnnotation = new FMIVendorAnnotation();
          String fmiVendorAnnotationIdentifier = fixIdentifier(vendorAnnotation.tool.name);
          theFMIVendorAnnotation.setIdentifier(fmiVendorAnnotationIdentifier);
          theFMIVendorAnnotation.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/VendorAnnotation/" + fmiVendorAnnotationIdentifier));
 
          // VendorAnnotation --1..1--> FMIVendorTool
          if (vendorAnnotation.tool != null) {
            FMIVendorTool theFMIVendorTool = new FMIVendorTool();
            String fmiVendorToolIdentifier = fmiVendorAnnotationIdentifier;
            theFMIVendorTool.setIdentifier(fmiVendorToolIdentifier);
            theFMIVendorTool.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/VendorTool/" + fmiVendorToolIdentifier));
            theFMIVendorTool.setName(getValue(vendorAnnotation.tool.name));


            if (vendorAnnotation.tool.annotations != null) {
              List<FMIAnnotation> allAnnotations = new ArrayList<FMIAnnotation>();
              for(Annotation annotation : vendorAnnotation.tool.annotations) {
                FMIAnnotation theFMIAnnotation = new FMIAnnotation();
                String fmiAnnotationdentifier = fmiVendorAnnotationIdentifier;
                theFMIAnnotation.setIdentifier(fmiAnnotationdentifier);
                theFMIAnnotation.setAbout(URI.create(Domain2OSLCManager.SERVICE_PROVIDER_BASE_URI + "/" + fmiFMUIdentifier + "/Annotation/" + fmiAnnotationdentifier));
                theFMIAnnotation.setName(getValue(annotation.name));
                theFMIAnnotation.setValue(getValue(annotation.value));

                Domain2OSLCManager.fmiAnnotationMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiAnnotationdentifier, theFMIAnnotation);
              }

              theFMIVendorTool.setAnnotations(Domain2OSLCManager.getLinkArray(allAnnotations));
              Domain2OSLCManager.fmiAnnotationMap.put(fmiFMUIdentifier, allAnnotations);
            }

            theFMIVendorAnnotation.setVendorTool(theFMIVendorTool.getAbout());
            List<FMIVendorTool> _vendorToolList = new ArrayList<FMIVendorTool>();
            _vendorToolList.add(theFMIVendorTool);
            Domain2OSLCManager.fmiVendorToolMap.put(fmiFMUIdentifier, _vendorToolList);
            Domain2OSLCManager.fmiVendorToolMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiVendorToolIdentifier, theFMIVendorTool);
          }
          Domain2OSLCManager.fmiVendorAnnotationMapByIdentifier.put(fmiFMUIdentifier + "_" + fmiVendorAnnotationIdentifier, theFMIVendorAnnotation);
        }

        theFMIModelDescription.setVendorAnnotations(Domain2OSLCManager.getLinkArray(allVendorAnnotations));
        Domain2OSLCManager.fmiVendorAnnotationMap.put(fmiFMUIdentifier, allVendorAnnotations);
      }
    }
  }
}
