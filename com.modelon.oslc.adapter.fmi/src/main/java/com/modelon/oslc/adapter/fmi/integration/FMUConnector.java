/*
* FMUConnector.java    1.1.0  2016-07-22
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

import com.fasterxml.jackson.databind.ObjectMapper;
import com.fasterxml.jackson.databind.DeserializationFeature;

import java.io.BufferedReader;
import java.io.File;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;

public class FMUConnector {

  public static File[] finder(String dirName, String fileExtension) {
    File dir = new File(dirName);
    return  dir.listFiles(new FilenameFilter() {
      public boolean accept(File dir1, String filename) {
        return filename.endsWith(fileExtension);
      }
    });
  }
  
  public static FMU loadSingleFMU(String fmuInterfaceCMDPath, String fmuPath, String unzipTempDir) throws IOException {
    File cmd = new File(fmuInterfaceCMDPath);
    File fmu = new File(fmuPath);
    File fmuTempDir = new File(unzipTempDir + File.separator + fmu.getName());
    fmuTempDir.mkdirs();

    try {
      ProcessBuilder builder = new ProcessBuilder(cmd.getPath(), "read", fmu.getPath(), fmuTempDir.getPath());
      builder.redirectErrorStream(true);
      Process p = builder.start();
      
      BufferedReader reader = new BufferedReader(new InputStreamReader(p.getInputStream()));
      StringBuilder sbuilder = new StringBuilder();
      String aux = "";

      while ((aux = reader.readLine()) != null) {
        aux = aux.replaceAll("\\\\", "\\\\\\\\");
        aux += "\r\n";
        sbuilder.append(aux);
      }

      String json = sbuilder.toString();
      ObjectMapper mapper = new ObjectMapper();
      mapper.disable(DeserializationFeature.FAIL_ON_UNKNOWN_PROPERTIES);
      FMU fmuObject = mapper.readValue(json, FMU.class);
      if (fmuObject.fmiVersion != null) return mapper.readValue(json, FMU.class);
      else return null;
    } catch(Exception e) {
      e.printStackTrace();
      return null;
    }
  }
  
  public static String readableFileSize(long size) {
    if(size <= 0) return "0";
    final String[] units = new String[] { "B", "kB", "MB", "GB", "TB" };
    int digitGroups = (int) (Math.log10(size)/Math.log10(1024));
    return new DecimalFormat("#,##0.#").format(size/Math.pow(1024, digitGroups)) + " " + units[digitGroups];
 }

  public static List<FMU> loadFMUsFromDir(String fmuInterfaceCMDPath, String dir, String unzipTempDir) throws IOException {

    File[] fmuFiles = finder(dir, ".fmu");
    
    if (fmuFiles == null) {
      throw new IOException(dir + " does not exist!");
    }
    
    List<FMU> discoveredFMUs = new ArrayList<>();
    int index = 0;
    int numOfFMUFile = fmuFiles.length;
    System.out.println("\nFound " + numOfFMUFile + " FMUs in " + dir + "*.fmu \n");
    for (File fmuFile : fmuFiles) {
      index++;
      System.out.println("FMU file (" + index + "/" + numOfFMUFile +"): " + fmuFile.getPath() + " (" + readableFileSize(fmuFile.length()) + ")");

      try {
        FMU fmu = FMUConnector.loadSingleFMU(fmuInterfaceCMDPath, fmuFile.getPath(), unzipTempDir);
        if (fmu != null) { 
          discoveredFMUs.add(fmu);
          System.out.println("\tPublishable?: Yes ");
        } else {
          System.out.println("\tPublishable?: No ");
        }
        System.out.println("");
      } catch(NullPointerException e) {
        throw new IOException(fmuInterfaceCMDPath + " or " + fmuFile.getPath() + " or " +  unzipTempDir + " does not exist;");
      }
    }
    
    System.out.println("Total: " + numOfFMUFile + ", Publishable: " + discoveredFMUs.size() + "\n");
    return discoveredFMUs;
  }
  
  public static void printFMUInfo(List<FMU> allDiscoveredFMUs) {
    for (FMU discoveredFMU : allDiscoveredFMUs) {
       System.out.println("\n-------------- FMU File = " + discoveredFMU.fmiModelDescription.fmuPath + " --------------\n");
       printFMUInfo(discoveredFMU);
    }
  }
  
  public static void printFMUInfo(FMU fmu) {
    
  System.out.println("fmiVersion = " + fmu.fmiVersion);
  System.out.println("isModelExchangeFMU = " + fmu.isModelExchangeFMU);
  System.out.println("isCoSimulationFMU = " + fmu.isCoSimulationFMU);
      
    ModelDescription model = fmu.fmiModelDescription;
    System.out.println("fmuPath = " + model.fmuPath);
    System.out.println("tmpPath = " + model.tmpPath);
    System.out.println("status = " + model.status);
    System.out.println("statusText = " + model.statusText);
    System.out.println("guid = " + model.guid);
    System.out.println("modelName = " + model.modelName);
    System.out.println("modelName = " + model.modelIdentifier);
    System.out.println("kind = " + model.kind);
    System.out.println("description = " + model.description);
    System.out.println("author = " + model.author);
    System.out.println("version = " + model.version);
    System.out.println("copyright = " + model.copyright);
    System.out.println("license = " + model.license);
    System.out.println("fmiVersion = " + model.fmiVersion);
    System.out.println("generationTool = " + model.generationTool);
    System.out.println("generationDateAndTime = " + model.generationDateAndTime);
    System.out.println("variableNamingConvention = " + model.variableNamingConvention);
    System.out.println("numberOfContinuousStates = " + model.numberOfContinuousStates);
    System.out.println("numberOfEventIndicators = " + model.numberOfEventIndicators);
    

    if (model.defaultExperiment != null) {
      System.out.println("defaultExperiment.startTime = " + model.defaultExperiment.startTime);
      System.out.println("defaultExperiment.stopTime = " + model.defaultExperiment.stopTime);
      System.out.println("defaultExperiment.tolerance = " + model.defaultExperiment.tolerance);
      System.out.println("defaultExperiment.step = " + model.defaultExperiment.step);
    }
    
    if (model.modelExchange != null) {
        System.out.println("modelExchange.modelIdentifier = " + model.modelExchange.modelIdentifier);
        System.out.println("modelExchange.canBeInstantiatedOnlyOncePerProcess = " + model.modelExchange.canBeInstantiatedOnlyOncePerProcess);
        System.out.println("modelExchange.canGetAndSetFMUstate = " + model.modelExchange.canGetAndSetFMUstate);
        System.out.println("modelExchange.canNotUseMemoryManagementFunctions = " + model.modelExchange.canNotUseMemoryManagementFunctions);
        System.out.println("modelExchange.canSerializeFMUstate = " + model.modelExchange.canSerializeFMUstate);
        System.out.println("modelExchange.completedEventIterationIsProvided = " + model.modelExchange.completedEventIterationIsProvided);
        System.out.println("modelExchange.completedIntegratorStepNotNeeded = " + model.modelExchange.completedIntegratorStepNotNeeded);
        System.out.println("modelExchange.needsExecutionTool = " + model.modelExchange.needsExecutionTool);
        System.out.println("modelExchange.providesDirectionalDerivatives = " + model.modelExchange.providesDirectionalDerivatives);
        if (model.modelExchange.sourceFiles != null) {
          for (SourceFile sourcefile : model.modelExchange.sourceFiles) {
            System.out.println("\tsourcefile.file = " + sourcefile.file);
          }
        }
      }
    
    if (model.modelStructure != null) {
      
      if (model.modelStructure.derivatives != null) {
        for (Derivative derivative : model.modelStructure.derivatives) {
          System.out.println("\tderivative.name = " + derivative.name);
          System.out.println("\tderivative.index = " + derivative.index);
          }
      }
        
      if (model.modelStructure.derivativesDependencies != null) {
        for (DerivativeDependencies derivativeDependencies : model.modelStructure.derivativesDependencies) {
          System.out.println("\tderivativeDependencies.dependencies = " + derivativeDependencies.dependencies);
          System.out.println("\tderivativeDependencies.dependenciesKind = " + derivativeDependencies.dependenciesKind);
        }
      }
        
      if ( model.modelStructure.initialUnknowns != null) {
        for (InitialUnknown initialUnknow : model.modelStructure.initialUnknowns) {
          System.out.println("\tinitialUnknow.name = " + initialUnknow.name);
          System.out.println("\tinitialUnknow.index = " + initialUnknow.index);
        }
      }
      
      if (model.modelStructure.initialUnknownsDependencies != null) {
        for (InitialUnknownDependencies initialUnknowsDependencies : model.modelStructure.initialUnknownsDependencies) {
          System.out.println("\tinitialUnknowsDependencies.dependencies = " + initialUnknowsDependencies.dependencies);
          System.out.println("\tinitialUnknowsDependencies.dependenciesKind = " + initialUnknowsDependencies.dependenciesKind);
        }
      }
        
      if (model.modelStructure.outputs != null) {
        for (Output output : model.modelStructure.outputs) {
          System.out.println("\toutput.name = " + output.name);
          System.out.println("\toutput.index = " + output.index);
        }
      }
        
      if (model.modelStructure.outputsDependencies != null) {
        for (OutputDependencies outputsDependencies : model.modelStructure.outputsDependencies) {
              System.out.println("\toutputsDependencies.dependencies = " + outputsDependencies.dependencies);
              System.out.println("\toutputsDependencies.dependenciesKind = " + outputsDependencies.dependenciesKind);
          }
      }
      }
    
    if (model.coSimulation != null) {
        System.out.println("coSimulation.canBeInstantiatedOnlyOncePerProcess = " + model.coSimulation.canBeInstantiatedOnlyOncePerProcess);
        System.out.println("coSimulation.canGetAndSetFMUstate = " + model.coSimulation.canGetAndSetFMUstate);
        System.out.println("coSimulation.canHandleVariableCommunicationStepSize = " + model.coSimulation.canHandleVariableCommunicationStepSize);
        System.out.println("coSimulation.canInterpolateInputs = " + model.coSimulation.canInterpolateInputs);
        System.out.println("coSimulation.canNotUseMemoryManagementFunctions = " + model.coSimulation.canNotUseMemoryManagementFunctions);
        System.out.println("coSimulation.canRunAsynchronuously = " + model.coSimulation.canRunAsynchronuously);
        System.out.println("coSimulation.canSerializeFMUstate = " + model.coSimulation.canSerializeFMUstate);
        System.out.println("coSimulation.maxOutputDerivativeOrder = " + model.coSimulation.maxOutputDerivativeOrder);
        System.out.println("coSimulation.modelIdentifier = " + model.coSimulation.modelIdentifier);
        System.out.println("coSimulation.needsExecutionTool = " + model.coSimulation.needsExecutionTool);
        System.out.println("coSimulation.providesDirectionalDerivatives = " + model.coSimulation.providesDirectionalDerivatives);
        if (model.coSimulation.sourceFiles != null) {
          for (SourceFile sourcefile : model.coSimulation.sourceFiles) {
            System.out.println("\tsourcefile.file = " + sourcefile.file);
          }
        }
      }

    if (model.vendorAnnotations != null) {
      System.out.println("==== VendorAnnotations (" + model.vendorAnnotations.size() + ") ==== ");
      for (VendorAnnotation va : model.vendorAnnotations) {
        System.out.println("\tTool.name = " + va.tool.name);
        if (va.tool.annotations != null) {
          for (Annotation toolAnno : va.tool.annotations) {
                System.out.println("\ttoolAnno.nam = " + toolAnno.name);
                System.out.println("\ttoolAnno.value = " + toolAnno.value);
            }
        }
        
        System.out.println("\t------------------");
      }
    } else {
      System.out.println("==== VendorAnnotations (0) ==== ");
    }


    if (model.typeDefinitions != null) {
      System.out.println("==== TypeDefinitions (" + model.typeDefinitions.size() + ") ==== ");
      for (TypeDefinition td : model.typeDefinitions) {
        System.out.println("\tname = " + td.name);
        System.out.println("\tdescription = " + td.description);
        System.out.println("\tbaseType = " + td.baseType);
        System.out.println("\tquantity = " + td.quantity);
        System.out.println("\ttype.name = " + td.type.name);
        System.out.println("\ttype.min = " + td.type.min);
        System.out.println("\ttype.max = " + td.type.max);
        if (td.type.enumerations != null) {
          System.out.println("\ttype.enumeration (" + td.type.enumerations.size() + ")");
          for (EnumerationItem enumItem : td.type.enumerations) {
            System.out.println("\t\ttypeEnum.name = " + enumItem.name);
            System.out.println("\t\ttypeEnum.value = " + enumItem.value);
            System.out.println("\t\ttypeEnum.description = " + enumItem.description);
          }
        }
        System.out.println("\t------------------");
      }
    } else {
      System.out.println("==== TypeDefinitions (0) ==== ");
    }
  
    if (model.unitDefinitions != null) {
      System.out.println("==== UnitDefinitions (" + model.unitDefinitions.size() + ") ==== ");
      for (UnitDefinition ud : model.unitDefinitions) {
        System.out.println("\tname = " + ud.name);
        System.out.println("\tbaseUnit.unit = " + ud.baseUnit.unit);
        System.out.println("\tbaseUnit.displayUnitNumber = " + ud.baseUnit.displayUnitNumber);
        System.out.println("\tbaseUnit.factor = " + ud.baseUnit.factor);
        System.out.println("\tbaseUnit.offset = " + ud.baseUnit.offset);
        if (ud.baseUnit.baseUnitDefinition != null) {
          System.out.println("\tbaseUnit.baseUnitDefinition.displayUnit = " + ud.baseUnit.baseUnitDefinition.displayUnit);
        }
        System.out.println("\t------------------");
      }
    } else {
      System.out.println("==== UnitDefinitions (0) ==== ");
    }
    
    if (model.modelVariables != null && model.modelVariables.scalarVariables != null) {
        System.out.println("==== ModelVariables.ScalarVariables (" + model.modelVariables.scalarVariables.size() + ") ==== ");
        for (ScalarVariable sv : model.modelVariables.scalarVariables) {
          System.out.println("\tname = " + sv.name);
          System.out.println("\tdescription = " + sv.description);
          System.out.println("\tvalueReference = " + sv.valueReference);
          System.out.println("\tvariability = " + sv.variability);
          System.out.println("\tcausality = " + sv.causality);
          System.out.println("\tinitial = " + sv.initial);
          System.out.println("\tisAlias = " + sv.isAlias);
          System.out.println("\taliasBase = " + sv.aliasBase);

          if (sv.type != null) {
            System.out.println("\t type.name = " + sv.type.name);
            System.out.println("\t type.start = " + sv.type.start);
            System.out.println("\t type.min = " + sv.type.min);
            System.out.println("\t type.max = " + sv.type.max);
            System.out.println("\t type.nominal = " + sv.type.nominal);
            System.out.println("\t type.declaredType = " + sv.type.declaredType);
            System.out.println("\t type.unit = " + sv.type.unit);
            System.out.println("\t type.displayUnit = " + sv.type.displayUnit);
          }
  
          if (sv.listingAliases != null) {
            for (ListingAlias listingAlias : sv.listingAliases) {
              System.out.println("\tlistingAlias.name = " + listingAlias.name);
            }
          }
          
          if (sv.listingDirectDependencies != null) {
            for (ListingDirectDependency listingDirectDependency : sv.listingDirectDependencies) {
              System.out.println("\tlistingDirectDependency.nam = " + listingDirectDependency.name);
            }
          }
          System.out.println("\t------------------");
        }
      } else {
        System.out.println("==== ModelVariables.ScalarVariables (0) ==== ");
      }
  }
}