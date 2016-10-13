/*
* OSLC4JFMIApplication.java    1.1.0  2016-07-23
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
*  @author Axel Reichwein, Koneksys (axel.reichwein@koneksys.com)
*/

package com.modelon.oslc.adapter.fmi.application;

import java.lang.management.ManagementFactory;

import java.net.InetAddress;
import java.net.UnknownHostException;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import javax.management.AttributeNotFoundException;
import javax.management.InstanceNotFoundException;
import javax.management.MBeanException;
import javax.management.MBeanServer;
import javax.management.MalformedObjectNameException;
import javax.management.ObjectName;
import javax.management.Query;
import javax.management.ReflectionException;

import org.eclipse.lyo.oslc4j.application.OslcWinkApplication;
import org.eclipse.lyo.oslc4j.provider.jena.JenaProvidersRegistry;
import org.eclipse.lyo.oslc4j.provider.json4j.Json4JProvidersRegistry;
import org.eclipse.lyo.oslc4j.core.model.OslcConstants;

import com.modelon.oslc.adapter.fmi.services.ServiceProviderCatalogService;
import com.modelon.oslc.adapter.fmi.services.ServiceProviderService;
import com.modelon.oslc.adapter.fmi.services.FMIFMUService;
import com.modelon.oslc.adapter.fmi.services.FMIModelDescriptionService;
import com.modelon.oslc.adapter.fmi.services.FMIDefaultExperimentService;
import com.modelon.oslc.adapter.fmi.services.FMIModelExchangeService;
import com.modelon.oslc.adapter.fmi.services.FMICoSimulationService;
import com.modelon.oslc.adapter.fmi.services.FMISourceFileService;
import com.modelon.oslc.adapter.fmi.services.FMIUnitDefinitionService;
import com.modelon.oslc.adapter.fmi.services.FMIBaseUnitService;
import com.modelon.oslc.adapter.fmi.services.FMIBaseUnitDefinitionService;
import com.modelon.oslc.adapter.fmi.services.FMIVendorAnnotationService;
import com.modelon.oslc.adapter.fmi.services.FMIVendorToolService;
import com.modelon.oslc.adapter.fmi.services.FMIAnnotationService;
import com.modelon.oslc.adapter.fmi.services.FMITypeDefinitionService;
import com.modelon.oslc.adapter.fmi.services.FMITypeDefService;
import com.modelon.oslc.adapter.fmi.services.FMIEnumerationService;
import com.modelon.oslc.adapter.fmi.services.FMIModelVariablesService;
import com.modelon.oslc.adapter.fmi.services.FMIScalarVariableService;
import com.modelon.oslc.adapter.fmi.services.FMIScalarVariableTypeService;
import com.modelon.oslc.adapter.fmi.services.FMIListingAliasService;
import com.modelon.oslc.adapter.fmi.services.FMIListingDirectDependencyService;
import com.modelon.oslc.adapter.fmi.services.FMIModelStructureService;
import com.modelon.oslc.adapter.fmi.services.FMIDerivativeService;
import com.modelon.oslc.adapter.fmi.services.FMIInitialUnknownService;
import com.modelon.oslc.adapter.fmi.services.FMIOutputService;
import com.modelon.oslc.adapter.fmi.services.FMIRDFVocabularyService;
import com.modelon.oslc.adapter.fmi.services.FMIResourceShapeService;
import com.modelon.oslc.adapter.fmi.resources.Constants;
import com.modelon.oslc.adapter.fmi.resources.FMIFMU;
import com.modelon.oslc.adapter.fmi.resources.FMIModelDescription;
import com.modelon.oslc.adapter.fmi.resources.FMIDefaultExperiment;
import com.modelon.oslc.adapter.fmi.resources.FMIModelExchange;
import com.modelon.oslc.adapter.fmi.resources.FMICoSimulation;
import com.modelon.oslc.adapter.fmi.resources.FMISourceFile;
import com.modelon.oslc.adapter.fmi.resources.FMIUnitDefinition;
import com.modelon.oslc.adapter.fmi.resources.FMIBaseUnit;
import com.modelon.oslc.adapter.fmi.resources.FMIBaseUnitDefinition;
import com.modelon.oslc.adapter.fmi.resources.FMIVendorAnnotation;
import com.modelon.oslc.adapter.fmi.resources.FMIVendorTool;
import com.modelon.oslc.adapter.fmi.resources.FMIAnnotation;
import com.modelon.oslc.adapter.fmi.resources.FMITypeDefinition;
import com.modelon.oslc.adapter.fmi.resources.FMITypeDef;
import com.modelon.oslc.adapter.fmi.resources.FMIEnumeration;
import com.modelon.oslc.adapter.fmi.resources.FMIModelVariables;
import com.modelon.oslc.adapter.fmi.resources.FMIScalarVariable;
import com.modelon.oslc.adapter.fmi.resources.FMIScalarVariableType;
import com.modelon.oslc.adapter.fmi.resources.FMIListingAlias;
import com.modelon.oslc.adapter.fmi.resources.FMIListingDirectDependency;
import com.modelon.oslc.adapter.fmi.resources.FMIModelStructure;
import com.modelon.oslc.adapter.fmi.resources.FMIDerivative;
import com.modelon.oslc.adapter.fmi.resources.FMIInitialUnknown;
import com.modelon.oslc.adapter.fmi.resources.FMIOutput;

public class OSLC4JFMIApplication extends OslcWinkApplication {

  public static final Set<Class<?>> RESOURCE_CLASSES = new HashSet<Class<?>>();
  public static final Map<String, Class<?>> RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP = new HashMap<String, Class<?>>();

  static {
    RESOURCE_CLASSES.addAll(JenaProvidersRegistry.getProviders());
    RESOURCE_CLASSES.addAll(Json4JProvidersRegistry.getProviders());
    RESOURCE_CLASSES.add(ServiceProviderCatalogService.class);
    RESOURCE_CLASSES.add(ServiceProviderService.class);
    RESOURCE_CLASSES.add(FMIFMUService.class);
    RESOURCE_CLASSES.add(FMIModelDescriptionService.class);
    RESOURCE_CLASSES.add(FMIDefaultExperimentService.class);
    RESOURCE_CLASSES.add(FMIModelExchangeService.class);
    RESOURCE_CLASSES.add(FMICoSimulationService.class);
    RESOURCE_CLASSES.add(FMISourceFileService.class);
    RESOURCE_CLASSES.add(FMIUnitDefinitionService.class);
    RESOURCE_CLASSES.add(FMIBaseUnitService.class);
    RESOURCE_CLASSES.add(FMIBaseUnitDefinitionService.class);
    RESOURCE_CLASSES.add(FMIVendorAnnotationService.class);
    RESOURCE_CLASSES.add(FMIVendorToolService.class);
    RESOURCE_CLASSES.add(FMIAnnotationService.class);
    RESOURCE_CLASSES.add(FMITypeDefinitionService.class);
    RESOURCE_CLASSES.add(FMITypeDefService.class);
    RESOURCE_CLASSES.add(FMIEnumerationService.class);
    RESOURCE_CLASSES.add(FMIModelVariablesService.class);
    RESOURCE_CLASSES.add(FMIScalarVariableService.class);
    RESOURCE_CLASSES.add(FMIScalarVariableTypeService.class);
    RESOURCE_CLASSES.add(FMIListingAliasService.class);
    RESOURCE_CLASSES.add(FMIListingDirectDependencyService.class);
    RESOURCE_CLASSES.add(FMIModelStructureService.class);
    RESOURCE_CLASSES.add(FMIDerivativeService.class);
    RESOURCE_CLASSES.add(FMIInitialUnknownService.class);
    RESOURCE_CLASSES.add(FMIOutputService.class);
    RESOURCE_CLASSES.add(FMIResourceShapeService.class);
    RESOURCE_CLASSES.add(FMIRDFVocabularyService.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_FMU, FMIFMU.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_MODELDESCRIPTION, FMIModelDescription.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_DEFAULTEXPERIMENT, FMIDefaultExperiment.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_MODELEXCHANGE, FMIModelExchange.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_COSIMULATION, FMICoSimulation.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_SOURCEFILE, FMISourceFile.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_UNITDEFINITION, FMIUnitDefinition.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_BASEUNIT, FMIBaseUnit.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_BASEUNITDEFINITION, FMIBaseUnitDefinition.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_VENDORANNOTATION, FMIVendorAnnotation.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_VENDORTOOL, FMIVendorTool.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_ANNOTATION, FMIAnnotation.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_TYPEDEFINITION, FMITypeDefinition.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_TYPEDEF, FMITypeDef.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_ENUMERATION, FMIEnumeration.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_MODELVARIABLES, FMIModelVariables.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_SCALARVARIABLE, FMIScalarVariable.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_SCALARVARIABLETYPE, FMIScalarVariableType.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_LISTINGALIAS, FMIListingAlias.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_LISTINGDIRECTDEPENDENCY, FMIListingDirectDependency.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_MODELSTRUCTURE, FMIModelStructure.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_DERIVATIVE, FMIDerivative.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_INITIALUNKNOWN, FMIInitialUnknown.class);
    RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP.put(Constants.PATH_FMI_OUTPUT, FMIOutput.class);
  }

  public OSLC4JFMIApplication() throws Exception {
    super(RESOURCE_CLASSES, OslcConstants.PATH_RESOURCE_SHAPES, RESOURCE_SHAPE_PATH_TO_RESOURCE_CLASS_MAP);
    System.out.println("");
    System.out.println("");
    System.out.println("***********************************************************************");
    System.out.println("");
    System.out.println(" OSLC FMI ADAPTER 1.1.0");
    System.out.println("");
    System.out.println("***********************************************************************");
    System.out.println("");
    System.out.println("");
    boot(getPort());
  }

  private String getPort() 
    throws MalformedObjectNameException,
    NullPointerException, UnknownHostException, AttributeNotFoundException,
    InstanceNotFoundException, MBeanException, ReflectionException {
    String port = "";
    MBeanServer mbs = ManagementFactory.getPlatformMBeanServer();
    Set<ObjectName> objs =  mbs.queryNames(
        new ObjectName("*:type=Connector,*"),
        Query.match(Query.attr("protocol"), Query.value("HTTP/1.1"))
      );
    String hostname = InetAddress.getLocalHost().getHostName();
    InetAddress[] addresses = InetAddress.getAllByName(hostname);
    ArrayList<String> endPoints = new ArrayList<String>();
    for (Iterator<ObjectName> i = objs.iterator(); i.hasNext();) {
      ObjectName obj = i.next();
      String scheme = mbs.getAttribute(obj, "scheme").toString();
      port = obj.getKeyProperty("port");
      for (InetAddress addr : addresses) {
        String host = addr.getHostAddress();
        String ep = scheme + "://" + host + ":" + port;
        endPoints.add(ep);
      }
    }
    System.out.println("Detected PlatformMBeanServer Port = " + port);
    return port;
  }

  private void boot(String serverPort) throws Exception {
    System.out.println("Booting ...");
    try {
      Domain2OSLCManager.getInstance(serverPort);
    } catch(Exception e) {
      throw new Exception(e.toString());
    }
   }
}
