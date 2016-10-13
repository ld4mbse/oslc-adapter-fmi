/*
* Domain2OSLCManager.java    1.1.0  2016-07-23
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

package com.modelon.oslc.adapter.fmi.application;

import java.io.UnsupportedEncodingException;
import java.net.URI;
import java.net.URLDecoder;
import java.net.URLEncoder;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.SortedMap;
import java.util.SortedSet;
import java.util.TreeMap;
import java.util.TreeSet;

import org.eclipse.lyo.oslc4j.core.model.OslcConstants;
import org.eclipse.lyo.oslc4j.core.model.Link;
import org.eclipse.lyo.oslc4j.core.model.AbstractResource;
import org.eclipse.lyo.oslc4j.client.ServiceProviderRegistryURIs;
import org.eclipse.lyo.oslc4j.core.model.Publisher;
import org.eclipse.lyo.oslc4j.core.model.ServiceProviderCatalog;
import org.eclipse.lyo.oslc4j.core.model.ServiceProviderFactory;
import org.eclipse.lyo.oslc4j.core.model.Service;
import org.eclipse.lyo.oslc4j.core.model.ServiceProvider;
import org.eclipse.lyo.oslc4j.core.model.PrefixDefinition;

import com.modelon.oslc.adapter.fmi.resources.Constants;
import com.modelon.oslc.adapter.fmi.integration.Integrator;

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

public class Domain2OSLCManager { 

  public static List<FMIFMU> topLevelConceptList = new ArrayList<FMIFMU>();
  public static Map<String, List<FMIFMU>> fmiFMUMap = new HashMap<String, List<FMIFMU>>();
  public static Map<String, FMIFMU> fmiFMUMapByIdentifier = new HashMap<String, FMIFMU>();
  public static Map<String, List<FMIModelDescription>> fmiModelDescriptionMap = new HashMap<String, List<FMIModelDescription>>();
  public static Map<String, FMIModelDescription> fmiModelDescriptionMapByIdentifier = new HashMap<String, FMIModelDescription>();
  public static Map<String, List<FMIDefaultExperiment>> fmiDefaultExperimentMap = new HashMap<String, List<FMIDefaultExperiment>>();
  public static Map<String, FMIDefaultExperiment> fmiDefaultExperimentMapByIdentifier = new HashMap<String, FMIDefaultExperiment>();
  public static Map<String, List<FMIModelExchange>> fmiModelExchangeMap = new HashMap<String, List<FMIModelExchange>>();
  public static Map<String, FMIModelExchange> fmiModelExchangeMapByIdentifier = new HashMap<String, FMIModelExchange>();
  public static Map<String, List<FMICoSimulation>> fmiCoSimulationMap = new HashMap<String, List<FMICoSimulation>>();
  public static Map<String, FMICoSimulation> fmiCoSimulationMapByIdentifier = new HashMap<String, FMICoSimulation>();
  public static Map<String, List<FMISourceFile>> fmiSourceFileMap = new HashMap<String, List<FMISourceFile>>();
  public static Map<String, FMISourceFile> fmiSourceFileMapByIdentifier = new HashMap<String, FMISourceFile>();
  public static Map<String, List<FMIUnitDefinition>> fmiUnitDefinitionMap = new HashMap<String, List<FMIUnitDefinition>>();
  public static Map<String, FMIUnitDefinition> fmiUnitDefinitionMapByIdentifier = new HashMap<String, FMIUnitDefinition>();
  public static Map<String, List<FMIBaseUnit>> fmiBaseUnitMap = new HashMap<String, List<FMIBaseUnit>>();
  public static Map<String, FMIBaseUnit> fmiBaseUnitMapByIdentifier = new HashMap<String, FMIBaseUnit>();
  public static Map<String, List<FMIBaseUnitDefinition>> fmiBaseUnitDefinitionMap = new HashMap<String, List<FMIBaseUnitDefinition>>();
  public static Map<String, FMIBaseUnitDefinition> fmiBaseUnitDefinitionMapByIdentifier = new HashMap<String, FMIBaseUnitDefinition>();
  public static Map<String, List<FMIVendorAnnotation>> fmiVendorAnnotationMap = new HashMap<String, List<FMIVendorAnnotation>>();
  public static Map<String, FMIVendorAnnotation> fmiVendorAnnotationMapByIdentifier = new HashMap<String, FMIVendorAnnotation>();
  public static Map<String, List<FMIVendorTool>> fmiVendorToolMap = new HashMap<String, List<FMIVendorTool>>();
  public static Map<String, FMIVendorTool> fmiVendorToolMapByIdentifier = new HashMap<String, FMIVendorTool>();
  public static Map<String, List<FMIAnnotation>> fmiAnnotationMap = new HashMap<String, List<FMIAnnotation>>();
  public static Map<String, FMIAnnotation> fmiAnnotationMapByIdentifier = new HashMap<String, FMIAnnotation>();
  public static Map<String, List<FMITypeDefinition>> fmiTypeDefinitionMap = new HashMap<String, List<FMITypeDefinition>>();
  public static Map<String, FMITypeDefinition> fmiTypeDefinitionMapByIdentifier = new HashMap<String, FMITypeDefinition>();
  public static Map<String, List<FMITypeDef>> fmiTypeDefMap = new HashMap<String, List<FMITypeDef>>();
  public static Map<String, FMITypeDef> fmiTypeDefMapByIdentifier = new HashMap<String, FMITypeDef>();
  public static Map<String, List<FMIEnumeration>> fmiEnumerationMap = new HashMap<String, List<FMIEnumeration>>();
  public static Map<String, FMIEnumeration> fmiEnumerationMapByIdentifier = new HashMap<String, FMIEnumeration>();
  public static Map<String, List<FMIModelVariables>> fmiModelVariablesMap = new HashMap<String, List<FMIModelVariables>>();
  public static Map<String, FMIModelVariables> fmiModelVariablesMapByIdentifier = new HashMap<String, FMIModelVariables>();
  public static Map<String, List<FMIScalarVariable>> fmiScalarVariableMap = new HashMap<String, List<FMIScalarVariable>>();
  public static Map<String, FMIScalarVariable> fmiScalarVariableMapByIdentifier = new HashMap<String, FMIScalarVariable>();
  public static Map<String, List<FMIScalarVariable>> fmiScalarVariableMapByIndex = new HashMap<String, List<FMIScalarVariable>>();
  public static Map<String, List<FMIScalarVariable>> fmiScalarVariableMapByName = new HashMap<String, List<FMIScalarVariable>>();
  public static Map<String, List<FMIScalarVariableType>> fmiScalarVariableTypeMap = new HashMap<String, List<FMIScalarVariableType>>();
  public static Map<String, FMIScalarVariableType> fmiScalarVariableTypeMapByIdentifier = new HashMap<String, FMIScalarVariableType>();
  public static Map<String, List<FMIListingAlias>> fmiListingAliasMap = new HashMap<String, List<FMIListingAlias>>();
  public static Map<String, FMIListingAlias> fmiListingAliasMapByIdentifier = new HashMap<String, FMIListingAlias>();
  public static Map<String, List<FMIListingDirectDependency>> fmiListingDirectDependencyMap = new HashMap<String, List<FMIListingDirectDependency>>();
  public static Map<String, FMIListingDirectDependency> fmiListingDirectDependencyMapByIdentifier = new HashMap<String, FMIListingDirectDependency>();
  public static Map<String, List<FMIModelStructure>> fmiModelStructureMap = new HashMap<String, List<FMIModelStructure>>();
  public static Map<String, FMIModelStructure> fmiModelStructureMapByIdentifier = new HashMap<String, FMIModelStructure>();
  public static Map<String, List<FMIDerivative>> fmiDerivativeMap = new HashMap<String, List<FMIDerivative>>();
  public static Map<String, FMIDerivative> fmiDerivativeMapByIdentifier = new HashMap<String, FMIDerivative>();
  public static Map<String, List<FMIInitialUnknown>> fmiInitialUnknownMap = new HashMap<String, List<FMIInitialUnknown>>();
  public static Map<String, FMIInitialUnknown> fmiInitialUnknownMapByIdentifier = new HashMap<String, FMIInitialUnknown>();
  public static Map<String, List<FMIOutput>> fmiOutputMap = new HashMap<String, List<FMIOutput>>();
  public static Map<String, FMIOutput> fmiOutputMapByIdentifier = new HashMap<String, FMIOutput>();

  private static Class<?>[] RESOURCE_CLASSES = { 
    FMIFMUService.class,
    FMIModelDescriptionService.class,
    FMIDefaultExperimentService.class,
    FMIModelExchangeService.class,
    FMICoSimulationService.class,
    FMISourceFileService.class,
    FMIUnitDefinitionService.class,
    FMIBaseUnitService.class,
    FMIBaseUnitDefinitionService.class,
    FMIVendorAnnotationService.class,
    FMIVendorToolService.class,
    FMIAnnotationService.class,
    FMITypeDefinitionService.class,
    FMITypeDefService.class,
    FMIEnumerationService.class,
    FMIModelVariablesService.class,
    FMIScalarVariableService.class,
    FMIScalarVariableTypeService.class,
    FMIListingAliasService.class,
    FMIListingDirectDependencyService.class,
    FMIModelStructureService.class,
    FMIDerivativeService.class,
    FMIInitialUnknownService.class,
    FMIOutputService.class
  };

  public static String SERVICE_PROVIDER_BASE_URI = "http://localhost:8686/oslc4jfmi/services";
  public static String PUBLISHER = "modelon";
  public static String PUBLISHER_PACKAGE = "com.modelon.oslc";
  public static String PUBLISHER_ICON_URI = "http://open-services.net/css/images/logo-forflip.png";
  private static PrefixDefinition[] PREFIX_DEFINITIONS;

  private Domain2OSLCManager() throws Exception {
  }

  private static Domain2OSLCManager instance;
  private static ServiceProviderCatalog serviceProviderCatalog;
  private static SortedMap<String, ServiceProvider> serviceProviders = new TreeMap<String, ServiceProvider>();

  public static Domain2OSLCManager getInstance(String serverPort) throws Exception {
    if(instance == null) {
      instance = new Domain2OSLCManager();
      if (serverPort != "" && serverPort != null) {
        String replacedServerPortbaseURI = SERVICE_PROVIDER_BASE_URI.replace(":8686", ":" + serverPort);
        SERVICE_PROVIDER_BASE_URI = replacedServerPortbaseURI;
      }
      Integrator.initialize();
      instance.buildServiceCatalog();
    }
    return instance;
  }

  public static SortedSet<URI> getServiceProviderDomains(final ServiceProvider serviceProvider) {
    final SortedSet<URI> domains = new TreeSet<URI>();
    if (serviceProvider != null) {
      final Service[] services = serviceProvider.getServices();
      for (final Service service : services) {
        final URI domain = service.getDomain();
        domains.add(domain);
      }
    }
    return domains;
  }

  private ServiceProvider buildServiceProvider(String serviceProviderIdentifier) throws Exception {
    Map<String, Object> parameterMap = new HashMap<String, Object>();
    parameterMap.put("fmuFileName", serviceProviderIdentifier);
    ServiceProvider serviceProvider = ServiceProviderFactory
     .createServiceProvider(
       SERVICE_PROVIDER_BASE_URI,
       ServiceProviderRegistryURIs.getUIURI(),
       serviceProviderIdentifier,
       "Service provider for " + serviceProviderIdentifier,
       new Publisher(PUBLISHER, PUBLISHER_PACKAGE),
       RESOURCE_CLASSES,
       parameterMap
    );
    URI detailsURIs[] = { new URI(SERVICE_PROVIDER_BASE_URI + "/details") };
    serviceProvider.setDetails(detailsURIs);
    return serviceProvider;
  }

  private void buildServiceCatalog() throws Exception {
    System.out.println("Creating OSLC resources...");

    PREFIX_DEFINITIONS = new PrefixDefinition[30];
    PREFIX_DEFINITIONS[0] = new PrefixDefinition(OslcConstants.DCTERMS_NAMESPACE_PREFIX,new URI(OslcConstants.DCTERMS_NAMESPACE));
    PREFIX_DEFINITIONS[1] = new PrefixDefinition(OslcConstants.OSLC_CORE_NAMESPACE_PREFIX,new URI(OslcConstants.OSLC_CORE_NAMESPACE));
    PREFIX_DEFINITIONS[2] = new PrefixDefinition(OslcConstants.OSLC_DATA_NAMESPACE_PREFIX,new URI(OslcConstants.OSLC_DATA_NAMESPACE));
    PREFIX_DEFINITIONS[3] = new PrefixDefinition(OslcConstants.RDF_NAMESPACE_PREFIX,new URI(OslcConstants.RDF_NAMESPACE));
    PREFIX_DEFINITIONS[4] = new PrefixDefinition(OslcConstants.RDFS_NAMESPACE_PREFIX,new URI(OslcConstants.RDFS_NAMESPACE));
    PREFIX_DEFINITIONS[5] = new PrefixDefinition(Constants.FMI_PREFIX, new URI(Constants.FMI_NAMESPACE));
    PREFIX_DEFINITIONS[6] = new PrefixDefinition(Constants.FMI_FMU_PREFIX, new URI(Constants.FMI_FMU_NAMESPACE));
    PREFIX_DEFINITIONS[7] = new PrefixDefinition(Constants.FMI_MODELDESCRIPTION_PREFIX, new URI(Constants.FMI_MODELDESCRIPTION_NAMESPACE));
    PREFIX_DEFINITIONS[8] = new PrefixDefinition(Constants.FMI_DEFAULTEXPERIMENT_PREFIX, new URI(Constants.FMI_DEFAULTEXPERIMENT_NAMESPACE));
    PREFIX_DEFINITIONS[9] = new PrefixDefinition(Constants.FMI_MODELEXCHANGE_PREFIX, new URI(Constants.FMI_MODELEXCHANGE_NAMESPACE));
    PREFIX_DEFINITIONS[10] = new PrefixDefinition(Constants.FMI_COSIMULATION_PREFIX, new URI(Constants.FMI_COSIMULATION_NAMESPACE));
    PREFIX_DEFINITIONS[11] = new PrefixDefinition(Constants.FMI_SOURCEFILE_PREFIX, new URI(Constants.FMI_SOURCEFILE_NAMESPACE));
    PREFIX_DEFINITIONS[12] = new PrefixDefinition(Constants.FMI_UNITDEFINITION_PREFIX, new URI(Constants.FMI_UNITDEFINITION_NAMESPACE));
    PREFIX_DEFINITIONS[13] = new PrefixDefinition(Constants.FMI_BASEUNIT_PREFIX, new URI(Constants.FMI_BASEUNIT_NAMESPACE));
    PREFIX_DEFINITIONS[14] = new PrefixDefinition(Constants.FMI_BASEUNITDEFINITION_PREFIX, new URI(Constants.FMI_BASEUNITDEFINITION_NAMESPACE));
    PREFIX_DEFINITIONS[15] = new PrefixDefinition(Constants.FMI_VENDORANNOTATION_PREFIX, new URI(Constants.FMI_VENDORANNOTATION_NAMESPACE));
    PREFIX_DEFINITIONS[16] = new PrefixDefinition(Constants.FMI_VENDORTOOL_PREFIX, new URI(Constants.FMI_VENDORTOOL_NAMESPACE));
    PREFIX_DEFINITIONS[17] = new PrefixDefinition(Constants.FMI_ANNOTATION_PREFIX, new URI(Constants.FMI_ANNOTATION_NAMESPACE));
    PREFIX_DEFINITIONS[18] = new PrefixDefinition(Constants.FMI_TYPEDEFINITION_PREFIX, new URI(Constants.FMI_TYPEDEFINITION_NAMESPACE));
    PREFIX_DEFINITIONS[19] = new PrefixDefinition(Constants.FMI_TYPEDEF_PREFIX, new URI(Constants.FMI_TYPEDEF_NAMESPACE));
    PREFIX_DEFINITIONS[20] = new PrefixDefinition(Constants.FMI_ENUMERATION_PREFIX, new URI(Constants.FMI_ENUMERATION_NAMESPACE));
    PREFIX_DEFINITIONS[21] = new PrefixDefinition(Constants.FMI_MODELVARIABLES_PREFIX, new URI(Constants.FMI_MODELVARIABLES_NAMESPACE));
    PREFIX_DEFINITIONS[22] = new PrefixDefinition(Constants.FMI_SCALARVARIABLE_PREFIX, new URI(Constants.FMI_SCALARVARIABLE_NAMESPACE));
    PREFIX_DEFINITIONS[23] = new PrefixDefinition(Constants.FMI_SCALARVARIABLETYPE_PREFIX, new URI(Constants.FMI_SCALARVARIABLETYPE_NAMESPACE));
    PREFIX_DEFINITIONS[24] = new PrefixDefinition(Constants.FMI_LISTINGALIAS_PREFIX, new URI(Constants.FMI_LISTINGALIAS_NAMESPACE));
    PREFIX_DEFINITIONS[25] = new PrefixDefinition(Constants.FMI_LISTINGDIRECTDEPENDENCY_PREFIX, new URI(Constants.FMI_LISTINGDIRECTDEPENDENCY_NAMESPACE));
    PREFIX_DEFINITIONS[26] = new PrefixDefinition(Constants.FMI_MODELSTRUCTURE_PREFIX, new URI(Constants.FMI_MODELSTRUCTURE_NAMESPACE));
    PREFIX_DEFINITIONS[27] = new PrefixDefinition(Constants.FMI_DERIVATIVE_PREFIX, new URI(Constants.FMI_DERIVATIVE_NAMESPACE));
    PREFIX_DEFINITIONS[28] = new PrefixDefinition(Constants.FMI_INITIALUNKNOWN_PREFIX, new URI(Constants.FMI_INITIALUNKNOWN_NAMESPACE));
    PREFIX_DEFINITIONS[29] = new PrefixDefinition(Constants.FMI_OUTPUT_PREFIX, new URI(Constants.FMI_OUTPUT_NAMESPACE));

    serviceProviderCatalog = new ServiceProviderCatalog();
    serviceProviderCatalog.setAbout(new URI(ServiceProviderRegistryURIs.getServiceProviderRegistryURI()));
    serviceProviderCatalog.setTitle("OSLC Service Provider Catalog");
    serviceProviderCatalog.setDescription("OSLC Service Provider Catalog");
    serviceProviderCatalog.setPublisher(new Publisher(PUBLISHER, PUBLISHER_PACKAGE));
    serviceProviderCatalog.getPublisher().setIcon(new URI(PUBLISHER_ICON_URI));

    List<FMIFMU> fmifmuList = getTopLevelConcept();
    int total = fmifmuList.size();
    System.out.println("");
    System.out.println("OSLC Service Providers: (total=" + total + ")");

    for(int index = 0 ; index < total ; index++) {
      String serviceProviderIdentifier = Integrator.generateServiceProviderIdentifierFromTopLevelInstance(index);

      URI serviceProviderURI = new URI(SERVICE_PROVIDER_BASE_URI + "/serviceProviders/" + serviceProviderIdentifier);

      ServiceProvider serviceProvider = buildServiceProvider(serviceProviderIdentifier);
      serviceProvider.setAbout(serviceProviderURI);
      serviceProvider.setIdentifier(serviceProviderIdentifier);
      serviceProvider.setCreated(new Date());
      serviceProviderCatalog.addServiceProvider(serviceProvider);

      final SortedSet<URI> serviceProviderDomains = getServiceProviderDomains(serviceProvider);
      serviceProviderCatalog.addDomains(serviceProviderDomains);
      serviceProviders.put(serviceProviderIdentifier, serviceProvider);

      System.out.println("	OSLC Service Provider (" + index + "/" + total + "): " + serviceProviderURI.toString());
    }
    System.out.println("");
    System.out.println("OSLC Service Catalog: ");
    System.out.println("	" + SERVICE_PROVIDER_BASE_URI + "/catalog");
    System.out.println("");
  }

  public static ServiceProviderCatalog getServiceProviderCatalog() {
    return serviceProviderCatalog;
  }

  public static ServiceProvider[] getServiceProviders() {
    return serviceProviders.values().toArray(new ServiceProvider[serviceProviders.size()]);
  }

  public static String getVariableName(String uri) {
    return uri.substring(uri.lastIndexOf("/") + 1);
  }

  public static String decodeURL(String uri) throws Exception { 
    return URLDecoder.decode(uri, "UTF-8");
  }

  public static ServiceProvider getServiceProvider(String serviceProviderIdentifier) throws Exception {
    ServiceProvider serviceProvider = serviceProviders.get(serviceProviderIdentifier);
    if (serviceProvider != null) {
      return serviceProvider;
     }
    throw new Exception("Not found ServiceProviderId (serviceProviderIdentifier) = " + serviceProviderIdentifier);
  }

  public static Link[] getLinkArray(Collection<? extends AbstractResource> elementCollection) {
    int linksCount = elementCollection.size();
    Link[] linksArray = null;
    if (linksCount > 0) {
      linksArray = new Link[linksCount];
    }
    int linksArrayIndex = 0;
    for (AbstractResource resource : elementCollection) {
      Link link = new Link(resource.getAbout());
      linksArray[linksArrayIndex] = link;
      linksArrayIndex++;
    }
    return linksArray;
  }

  public static List<FMIFMU> getTopLevelConcept() throws Exception {
    return topLevelConceptList; 
  }

  public static List<FMIFMU> getFMIFMUMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiFMUMap.get(fmuFileName);
  }

  public static FMIFMU getFMIFMUMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiFMUMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIModelDescription> getFMIModelDescriptionMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiModelDescriptionMap.get(fmuFileName);
  }

  public static FMIModelDescription getFMIModelDescriptionMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiModelDescriptionMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIDefaultExperiment> getFMIDefaultExperimentMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiDefaultExperimentMap.get(fmuFileName);
  }

  public static FMIDefaultExperiment getFMIDefaultExperimentMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiDefaultExperimentMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIModelExchange> getFMIModelExchangeMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiModelExchangeMap.get(fmuFileName);
  }

  public static FMIModelExchange getFMIModelExchangeMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiModelExchangeMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMICoSimulation> getFMICoSimulationMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiCoSimulationMap.get(fmuFileName);
  }

  public static FMICoSimulation getFMICoSimulationMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiCoSimulationMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMISourceFile> getFMISourceFileMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiSourceFileMap.get(fmuFileName);
  }

  public static FMISourceFile getFMISourceFileMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiSourceFileMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIUnitDefinition> getFMIUnitDefinitionMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiUnitDefinitionMap.get(fmuFileName);
  }

  public static FMIUnitDefinition getFMIUnitDefinitionMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiUnitDefinitionMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIBaseUnit> getFMIBaseUnitMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiBaseUnitMap.get(fmuFileName);
  }

  public static FMIBaseUnit getFMIBaseUnitMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiBaseUnitMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIBaseUnitDefinition> getFMIBaseUnitDefinitionMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiBaseUnitDefinitionMap.get(fmuFileName);
  }

  public static FMIBaseUnitDefinition getFMIBaseUnitDefinitionMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiBaseUnitDefinitionMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIVendorAnnotation> getFMIVendorAnnotationMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiVendorAnnotationMap.get(fmuFileName);
  }

  public static FMIVendorAnnotation getFMIVendorAnnotationMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiVendorAnnotationMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIVendorTool> getFMIVendorToolMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiVendorToolMap.get(fmuFileName);
  }

  public static FMIVendorTool getFMIVendorToolMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiVendorToolMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIAnnotation> getFMIAnnotationMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiAnnotationMap.get(fmuFileName);
  }

  public static FMIAnnotation getFMIAnnotationMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiAnnotationMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMITypeDefinition> getFMITypeDefinitionMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiTypeDefinitionMap.get(fmuFileName);
  }

  public static FMITypeDefinition getFMITypeDefinitionMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiTypeDefinitionMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMITypeDef> getFMITypeDefMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiTypeDefMap.get(fmuFileName);
  }

  public static FMITypeDef getFMITypeDefMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiTypeDefMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIEnumeration> getFMIEnumerationMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiEnumerationMap.get(fmuFileName);
  }

  public static FMIEnumeration getFMIEnumerationMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiEnumerationMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIModelVariables> getFMIModelVariablesMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiModelVariablesMap.get(fmuFileName);
  }

  public static FMIModelVariables getFMIModelVariablesMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiModelVariablesMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIScalarVariable> getFMIScalarVariableMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiScalarVariableMap.get(fmuFileName);
  }

  public static FMIScalarVariable getFMIScalarVariableMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiScalarVariableMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIScalarVariable> getFMIScalarVariableMapByIndex(String fmuFileName, String index) throws UnsupportedEncodingException {
    return fmiScalarVariableMapByIndex.get(fmuFileName + "_" + index);
  }

  public static List<FMIScalarVariable> getFMIScalarVariableMapByName(String fmuFileName, String name) throws UnsupportedEncodingException {
    return fmiScalarVariableMapByName.get(fmuFileName + "_" + name);
  }

  public static List<FMIScalarVariableType> getFMIScalarVariableTypeMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiScalarVariableTypeMap.get(fmuFileName);
  }

  public static FMIScalarVariableType getFMIScalarVariableTypeMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiScalarVariableTypeMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIListingAlias> getFMIListingAliasMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiListingAliasMap.get(fmuFileName);
  }

  public static FMIListingAlias getFMIListingAliasMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiListingAliasMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIListingDirectDependency> getFMIListingDirectDependencyMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiListingDirectDependencyMap.get(fmuFileName);
  }

  public static FMIListingDirectDependency getFMIListingDirectDependencyMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiListingDirectDependencyMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIModelStructure> getFMIModelStructureMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiModelStructureMap.get(fmuFileName);
  }

  public static FMIModelStructure getFMIModelStructureMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiModelStructureMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIDerivative> getFMIDerivativeMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiDerivativeMap.get(fmuFileName);
  }

  public static FMIDerivative getFMIDerivativeMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiDerivativeMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIInitialUnknown> getFMIInitialUnknownMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiInitialUnknownMap.get(fmuFileName);
  }

  public static FMIInitialUnknown getFMIInitialUnknownMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiInitialUnknownMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

  public static List<FMIOutput> getFMIOutputMap(String fmuFileName) throws UnsupportedEncodingException {
    return fmiOutputMap.get(fmuFileName);
  }

  public static FMIOutput getFMIOutputMapByIdentifier(String fmuFileName, String identifier) throws UnsupportedEncodingException {
    return fmiOutputMapByIdentifier.get(fmuFileName + "_" + identifier);
  }

}
