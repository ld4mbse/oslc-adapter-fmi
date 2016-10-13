/*
* FMIModelDescription.java    1.1.0  2016-07-23
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

package com.modelon.oslc.adapter.fmi.resources;

import java.net.URI;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.HashSet;
import java.util.Set;

import org.eclipse.lyo.oslc4j.core.annotation.OslcDescription;
import org.eclipse.lyo.oslc4j.core.annotation.OslcName;
import org.eclipse.lyo.oslc4j.core.annotation.OslcOccurs;
import org.eclipse.lyo.oslc4j.core.annotation.OslcNamespace;
import org.eclipse.lyo.oslc4j.core.annotation.OslcReadOnly;
import org.eclipse.lyo.oslc4j.core.annotation.OslcPropertyDefinition;
import org.eclipse.lyo.oslc4j.core.annotation.OslcRange;
import org.eclipse.lyo.oslc4j.core.annotation.OslcRepresentation;
import org.eclipse.lyo.oslc4j.core.annotation.OslcResourceShape;
import org.eclipse.lyo.oslc4j.core.annotation.OslcTitle;
import org.eclipse.lyo.oslc4j.core.annotation.OslcValueType;
import org.eclipse.lyo.oslc4j.core.model.AbstractResource;
import org.eclipse.lyo.oslc4j.core.model.OslcConstants;
import org.eclipse.lyo.oslc4j.core.model.Occurs;
import org.eclipse.lyo.oslc4j.core.model.Representation;
import org.eclipse.lyo.oslc4j.core.model.ValueType;
import org.eclipse.lyo.oslc4j.core.model.Link;

@OslcNamespace(Constants.FMI_NAMESPACE)
@OslcName("ModelDescription")
@OslcResourceShape(title = "ModelDescription Resource Shape", describes = Constants.TYPE_FMI_MODELDESCRIPTION)
public class FMIModelDescription extends AbstractResource {

  public FMIModelDescription() throws URISyntaxException {
    super();
  }

  public FMIModelDescription(URI about) throws URISyntaxException {
    super(about);
  }

  // ********* ServiceProvider: *********
  private URI serviceProvider;

  public void setServiceProvider(final URI serviceProvider) {
    this.serviceProvider = serviceProvider;
  }

  @OslcDescription("The scope of a resource is a URI for the resource's OSLC Service Provider.")
  @OslcPropertyDefinition(OslcConstants.OSLC_CORE_NAMESPACE + "serviceProvider")
  @OslcRange(OslcConstants.TYPE_SERVICE_PROVIDER)
  @OslcTitle("Service Provider")
  public URI getServiceProvider() {
    return serviceProvider;
  }

  // ********* Attribute: identifier *********
  private String identifier;

  public void setIdentifier(String identifier) {
    this.identifier = identifier;
  }

  @OslcDescription("Description of ModelDescription::identifier TBD")
  @OslcName("identifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_identifier")
  @OslcTitle("identifier")
  @OslcValueType(ValueType.XMLLiteral)
  public String getIdentifier() {
    return this.identifier;
  }

  // ********* Attribute: fmuPath *********
  private String fmuPath;

  public void setFmuPath(String fmuPath) {
    this.fmuPath = fmuPath;
  }

  @OslcDescription("Description of ModelDescription::fmuPath TBD")
  @OslcName("fmuPath")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_fmuPath")
  @OslcTitle("fmuPath")
  @OslcValueType(ValueType.XMLLiteral)
  public String getFmuPath() {
    return this.fmuPath;
  }

  // ********* Attribute: tmpPath *********
  private String tmpPath;

  public void setTmpPath(String tmpPath) {
    this.tmpPath = tmpPath;
  }

  @OslcDescription("Description of ModelDescription::tmpPath TBD")
  @OslcName("tmpPath")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_tmpPath")
  @OslcTitle("tmpPath")
  @OslcValueType(ValueType.XMLLiteral)
  public String getTmpPath() {
    return this.tmpPath;
  }

  // ********* Attribute: fmiVersion *********
  private String fmiVersion;

  public void setFmiVersion(String fmiVersion) {
    this.fmiVersion = fmiVersion;
  }

  @OslcDescription("Description of ModelDescription::fmiVersion TBD")
  @OslcName("fmiVersion")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_fmiVersion")
  @OslcTitle("fmiVersion")
  @OslcValueType(ValueType.XMLLiteral)
  public String getFmiVersion() {
    return this.fmiVersion;
  }

  // ********* Attribute: modelName *********
  private String modelName;

  public void setModelName(String modelName) {
    this.modelName = modelName;
  }

  @OslcDescription("Description of ModelDescription::modelName TBD")
  @OslcName("modelName")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_modelName")
  @OslcTitle("modelName")
  @OslcValueType(ValueType.XMLLiteral)
  public String getModelName() {
    return this.modelName;
  }

  // ********* Attribute: modelIdentifier *********
  private String modelIdentifier;

  public void setModelIdentifier(String modelIdentifier) {
    this.modelIdentifier = modelIdentifier;
  }

  @OslcDescription("Description of ModelDescription::modelIdentifier TBD")
  @OslcName("modelIdentifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_modelIdentifier")
  @OslcTitle("modelIdentifier")
  @OslcValueType(ValueType.XMLLiteral)
  public String getModelIdentifier() {
    return this.modelIdentifier;
  }

  // ********* Attribute: guid *********
  private String guid;

  public void setGuid(String guid) {
    this.guid = guid;
  }

  @OslcDescription("Description of ModelDescription::guid TBD")
  @OslcName("guid")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_guid")
  @OslcTitle("guid")
  @OslcValueType(ValueType.XMLLiteral)
  public String getGuid() {
    return this.guid;
  }

  // ********* Attribute: description *********
  private String description;

  public void setDescription(String description) {
    this.description = description;
  }

  @OslcDescription("Description of ModelDescription::description TBD")
  @OslcName("description")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_description")
  @OslcTitle("description")
  @OslcValueType(ValueType.XMLLiteral)
  public String getDescription() {
    return this.description;
  }

  // ********* Attribute: author *********
  private String author;

  public void setAuthor(String author) {
    this.author = author;
  }

  @OslcDescription("Description of ModelDescription::author TBD")
  @OslcName("author")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_author")
  @OslcTitle("author")
  @OslcValueType(ValueType.XMLLiteral)
  public String getAuthor() {
    return this.author;
  }

  // ********* Attribute: version *********
  private String version;

  public void setVersion(String version) {
    this.version = version;
  }

  @OslcDescription("Description of ModelDescription::version TBD")
  @OslcName("version")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_version")
  @OslcTitle("version")
  @OslcValueType(ValueType.XMLLiteral)
  public String getVersion() {
    return this.version;
  }

  // ********* Attribute: copyright *********
  private String copyright;

  public void setCopyright(String copyright) {
    this.copyright = copyright;
  }

  @OslcDescription("Description of ModelDescription::copyright TBD")
  @OslcName("copyright")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_copyright")
  @OslcTitle("copyright")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCopyright() {
    return this.copyright;
  }

  // ********* Attribute: license *********
  private String license;

  public void setLicense(String license) {
    this.license = license;
  }

  @OslcDescription("Description of ModelDescription::license TBD")
  @OslcName("license")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_license")
  @OslcTitle("license")
  @OslcValueType(ValueType.XMLLiteral)
  public String getLicense() {
    return this.license;
  }

  // ********* Attribute: kind *********
  private String kind;

  public void setKind(String kind) {
    this.kind = kind;
  }

  @OslcDescription("Description of ModelDescription::kind TBD")
  @OslcName("kind")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_kind")
  @OslcTitle("kind")
  @OslcValueType(ValueType.XMLLiteral)
  public String getKind() {
    return this.kind;
  }

  // ********* Attribute: generationTool *********
  private String generationTool;

  public void setGenerationTool(String generationTool) {
    this.generationTool = generationTool;
  }

  @OslcDescription("Description of ModelDescription::generationTool TBD")
  @OslcName("generationTool")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_generationTool")
  @OslcTitle("generationTool")
  @OslcValueType(ValueType.XMLLiteral)
  public String getGenerationTool() {
    return this.generationTool;
  }

  // ********* Attribute: generationDateAndTime *********
  private String generationDateAndTime;

  public void setGenerationDateAndTime(String generationDateAndTime) {
    this.generationDateAndTime = generationDateAndTime;
  }

  @OslcDescription("Description of ModelDescription::generationDateAndTime TBD")
  @OslcName("generationDateAndTime")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_generationDateAndTime")
  @OslcTitle("generationDateAndTime")
  @OslcValueType(ValueType.XMLLiteral)
  public String getGenerationDateAndTime() {
    return this.generationDateAndTime;
  }

  // ********* Attribute: variableNamingConvention *********
  private String variableNamingConvention;

  public void setVariableNamingConvention(String variableNamingConvention) {
    this.variableNamingConvention = variableNamingConvention;
  }

  @OslcDescription("Description of ModelDescription::variableNamingConvention TBD")
  @OslcName("variableNamingConvention")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_variableNamingConvention")
  @OslcTitle("variableNamingConvention")
  @OslcValueType(ValueType.XMLLiteral)
  public String getVariableNamingConvention() {
    return this.variableNamingConvention;
  }

  // ********* Attribute: numberOfContinuousStates *********
  private String numberOfContinuousStates;

  public void setNumberOfContinuousStates(String numberOfContinuousStates) {
    this.numberOfContinuousStates = numberOfContinuousStates;
  }

  @OslcDescription("Description of ModelDescription::numberOfContinuousStates TBD")
  @OslcName("numberOfContinuousStates")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_numberOfContinuousStates")
  @OslcTitle("numberOfContinuousStates")
  @OslcValueType(ValueType.XMLLiteral)
  public String getNumberOfContinuousStates() {
    return this.numberOfContinuousStates;
  }

  // ********* Attribute: numberOfEventIndicators *********
  private String numberOfEventIndicators;

  public void setNumberOfEventIndicators(String numberOfEventIndicators) {
    this.numberOfEventIndicators = numberOfEventIndicators;
  }

  @OslcDescription("Description of ModelDescription::numberOfEventIndicators TBD")
  @OslcName("numberOfEventIndicators")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_numberOfEventIndicators")
  @OslcTitle("numberOfEventIndicators")
  @OslcValueType(ValueType.XMLLiteral)
  public String getNumberOfEventIndicators() {
    return this.numberOfEventIndicators;
  }


  // ********* Reference: defaultExperiment *********
  private FMIDefaultExperiment fmiDefaultExperiment;
  private URI defaultExperiment;

  public void setDefaultExperiment(final URI defaultExperiment) {
    this.defaultExperiment = defaultExperiment;
  }

  @OslcDescription("Description of ModelDescription::defaultExperiment TBD")
  @OslcName("defaultExperiment")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription/defaultExperiment")
  @OslcTitle("defaultExperiment")
  @OslcRange("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#DefaultExperiment")
  public URI getDefaultExperiment() {
  return this.defaultExperiment;
  }

  // ********* Reference: modelStructure *********
  private FMIModelStructure fmiModelStructure;
  private URI modelStructure;

  public void setModelStructure(final URI modelStructure) {
    this.modelStructure = modelStructure;
  }

  @OslcDescription("Description of ModelDescription::modelStructure TBD")
  @OslcName("modelStructure")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription/modelStructure")
  @OslcTitle("modelStructure")
  @OslcRange("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelStructure")
  public URI getModelStructure() {
  return this.modelStructure;
  }

  // ********* Reference: coSimulation *********
  private FMICoSimulation fmiCoSimulation;
  private URI coSimulation;

  public void setCoSimulation(final URI coSimulation) {
    this.coSimulation = coSimulation;
  }

  @OslcDescription("Description of ModelDescription::coSimulation TBD")
  @OslcName("coSimulation")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription/coSimulation")
  @OslcTitle("coSimulation")
  @OslcRange("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation")
  public URI getCoSimulation() {
  return this.coSimulation;
  }

  // ********* Reference: modelExchange *********
  private FMIModelExchange fmiModelExchange;
  private URI modelExchange;

  public void setModelExchange(final URI modelExchange) {
    this.modelExchange = modelExchange;
  }

  @OslcDescription("Description of ModelDescription::modelExchange TBD")
  @OslcName("modelExchange")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription/modelExchange")
  @OslcTitle("modelExchange")
  @OslcRange("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelExchange")
  public URI getModelExchange() {
  return this.modelExchange;
  }

  // ********* Reference: modelVariables *********
  private FMIModelVariables fmiModelVariables;
  private URI modelVariables;

  public void setModelVariables(final URI modelVariables) {
    this.modelVariables = modelVariables;
  }

  @OslcDescription("Description of ModelDescription::modelVariables TBD")
  @OslcName("modelVariables")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription/modelVariables")
  @OslcTitle("modelVariables")
  @OslcRange("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelVariables")
  public URI getModelVariables() {
  return this.modelVariables;
  }

  // ********* Reference: unitDefinition *********
  private List<FMIUnitDefinition> fmiUnitDefinitionList;
  private final Set<Link> unitDefinitions = new HashSet<Link>();

  public void setUnitDefinitions(final Link[] unitDefinitions) {
    this.unitDefinitions.clear();
    if (unitDefinitions != null) {
      this.unitDefinitions.addAll(Arrays.asList(unitDefinitions));
    }
  }

  @OslcDescription("Description of ModelDescription::unitDefinition TBD")
  @OslcName("unitDefinition")
  @OslcOccurs(Occurs.ZeroOrMany)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_unitDefinition")
  @OslcTitle("unitDefinition")
  @OslcReadOnly(false)
  public Link[]  getUnitDefinitions() {
  return this.unitDefinitions.toArray(new Link[this.unitDefinitions.size()]);
  }

  // ********* Reference: vendorAnnotation *********
  private List<FMIVendorAnnotation> fmiVendorAnnotationList;
  private final Set<Link> vendorAnnotations = new HashSet<Link>();

  public void setVendorAnnotations(final Link[] vendorAnnotations) {
    this.vendorAnnotations.clear();
    if (vendorAnnotations != null) {
      this.vendorAnnotations.addAll(Arrays.asList(vendorAnnotations));
    }
  }

  @OslcDescription("Description of ModelDescription::vendorAnnotation TBD")
  @OslcName("vendorAnnotation")
  @OslcOccurs(Occurs.ZeroOrMany)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_vendorAnnotation")
  @OslcTitle("vendorAnnotation")
  @OslcReadOnly(false)
  public Link[]  getVendorAnnotations() {
  return this.vendorAnnotations.toArray(new Link[this.vendorAnnotations.size()]);
  }

  // ********* Reference: typeDefinition *********
  private List<FMITypeDefinition> fmiTypeDefinitionList;
  private final Set<Link> typeDefinitions = new HashSet<Link>();

  public void setTypeDefinitions(final Link[] typeDefinitions) {
    this.typeDefinitions.clear();
    if (typeDefinitions != null) {
      this.typeDefinitions.addAll(Arrays.asList(typeDefinitions));
    }
  }

  @OslcDescription("Description of ModelDescription::typeDefinition TBD")
  @OslcName("typeDefinition")
  @OslcOccurs(Occurs.ZeroOrMany)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription_typeDefinition")
  @OslcTitle("typeDefinition")
  @OslcReadOnly(false)
  public Link[]  getTypeDefinitions() {
  return this.typeDefinitions.toArray(new Link[this.typeDefinitions.size()]);
  }

}

