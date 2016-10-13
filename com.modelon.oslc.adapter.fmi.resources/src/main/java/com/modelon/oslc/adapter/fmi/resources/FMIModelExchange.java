/*
* FMIModelExchange.java    1.1.0  2016-07-23
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
@OslcName("ModelExchange")
@OslcResourceShape(title = "ModelExchange Resource Shape", describes = Constants.TYPE_FMI_MODELEXCHANGE)
public class FMIModelExchange extends AbstractResource {

  public FMIModelExchange() throws URISyntaxException {
    super();
  }

  public FMIModelExchange(URI about) throws URISyntaxException {
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

  @OslcDescription("Description of ModelExchange::identifier TBD")
  @OslcName("identifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelExchange_identifier")
  @OslcTitle("identifier")
  @OslcValueType(ValueType.XMLLiteral)
  public String getIdentifier() {
    return this.identifier;
  }

  // ********* Attribute: modelIdentifier *********
  private String modelIdentifier;

  public void setModelIdentifier(String modelIdentifier) {
    this.modelIdentifier = modelIdentifier;
  }

  @OslcDescription("Description of ModelExchange::modelIdentifier TBD")
  @OslcName("modelIdentifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelExchange_modelIdentifier")
  @OslcTitle("modelIdentifier")
  @OslcValueType(ValueType.XMLLiteral)
  public String getModelIdentifier() {
    return this.modelIdentifier;
  }

  // ********* Attribute: needsExecutionTool *********
  private String needsExecutionTool;

  public void setNeedsExecutionTool(String needsExecutionTool) {
    this.needsExecutionTool = needsExecutionTool;
  }

  @OslcDescription("Description of ModelExchange::needsExecutionTool TBD")
  @OslcName("needsExecutionTool")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelExchange_needsExecutionTool")
  @OslcTitle("needsExecutionTool")
  @OslcValueType(ValueType.XMLLiteral)
  public String getNeedsExecutionTool() {
    return this.needsExecutionTool;
  }

  // ********* Attribute: completedIntegratorStepNotNeeded *********
  private String completedIntegratorStepNotNeeded;

  public void setCompletedIntegratorStepNotNeeded(String completedIntegratorStepNotNeeded) {
    this.completedIntegratorStepNotNeeded = completedIntegratorStepNotNeeded;
  }

  @OslcDescription("Description of ModelExchange::completedIntegratorStepNotNeeded TBD")
  @OslcName("completedIntegratorStepNotNeeded")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelExchange_completedIntegratorStepNotNeeded")
  @OslcTitle("completedIntegratorStepNotNeeded")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCompletedIntegratorStepNotNeeded() {
    return this.completedIntegratorStepNotNeeded;
  }

  // ********* Attribute: canBeInstantiatedOnlyOncePerProcess *********
  private String canBeInstantiatedOnlyOncePerProcess;

  public void setCanBeInstantiatedOnlyOncePerProcess(String canBeInstantiatedOnlyOncePerProcess) {
    this.canBeInstantiatedOnlyOncePerProcess = canBeInstantiatedOnlyOncePerProcess;
  }

  @OslcDescription("Description of ModelExchange::canBeInstantiatedOnlyOncePerProcess TBD")
  @OslcName("canBeInstantiatedOnlyOncePerProcess")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelExchange_canBeInstantiatedOnlyOncePerProcess")
  @OslcTitle("canBeInstantiatedOnlyOncePerProcess")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCanBeInstantiatedOnlyOncePerProcess() {
    return this.canBeInstantiatedOnlyOncePerProcess;
  }

  // ********* Attribute: canNotUseMemoryManagementFunctions *********
  private String canNotUseMemoryManagementFunctions;

  public void setCanNotUseMemoryManagementFunctions(String canNotUseMemoryManagementFunctions) {
    this.canNotUseMemoryManagementFunctions = canNotUseMemoryManagementFunctions;
  }

  @OslcDescription("Description of ModelExchange::canNotUseMemoryManagementFunctions TBD")
  @OslcName("canNotUseMemoryManagementFunctions")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelExchange_canNotUseMemoryManagementFunctions")
  @OslcTitle("canNotUseMemoryManagementFunctions")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCanNotUseMemoryManagementFunctions() {
    return this.canNotUseMemoryManagementFunctions;
  }

  // ********* Attribute: canGetAndSetFMUstate *********
  private String canGetAndSetFMUstate;

  public void setCanGetAndSetFMUstate(String canGetAndSetFMUstate) {
    this.canGetAndSetFMUstate = canGetAndSetFMUstate;
  }

  @OslcDescription("Description of ModelExchange::canGetAndSetFMUstate TBD")
  @OslcName("canGetAndSetFMUstate")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelExchange_canGetAndSetFMUstate")
  @OslcTitle("canGetAndSetFMUstate")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCanGetAndSetFMUstate() {
    return this.canGetAndSetFMUstate;
  }

  // ********* Attribute: canSerializeFMUstate *********
  private String canSerializeFMUstate;

  public void setCanSerializeFMUstate(String canSerializeFMUstate) {
    this.canSerializeFMUstate = canSerializeFMUstate;
  }

  @OslcDescription("Description of ModelExchange::canSerializeFMUstate TBD")
  @OslcName("canSerializeFMUstate")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelExchange_canSerializeFMUstate")
  @OslcTitle("canSerializeFMUstate")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCanSerializeFMUstate() {
    return this.canSerializeFMUstate;
  }

  // ********* Attribute: providesDirectionalDerivatives *********
  private String providesDirectionalDerivatives;

  public void setProvidesDirectionalDerivatives(String providesDirectionalDerivatives) {
    this.providesDirectionalDerivatives = providesDirectionalDerivatives;
  }

  @OslcDescription("Description of ModelExchange::providesDirectionalDerivatives TBD")
  @OslcName("providesDirectionalDerivatives")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelExchange_providesDirectionalDerivatives")
  @OslcTitle("providesDirectionalDerivatives")
  @OslcValueType(ValueType.XMLLiteral)
  public String getProvidesDirectionalDerivatives() {
    return this.providesDirectionalDerivatives;
  }

  // ********* Attribute: completedEventIterationIsProvided *********
  private String completedEventIterationIsProvided;

  public void setCompletedEventIterationIsProvided(String completedEventIterationIsProvided) {
    this.completedEventIterationIsProvided = completedEventIterationIsProvided;
  }

  @OslcDescription("Description of ModelExchange::completedEventIterationIsProvided TBD")
  @OslcName("completedEventIterationIsProvided")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelExchange_completedEventIterationIsProvided")
  @OslcTitle("completedEventIterationIsProvided")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCompletedEventIterationIsProvided() {
    return this.completedEventIterationIsProvided;
  }


  // ********* Reference: sourceFile *********
  private List<FMISourceFile> fmiSourceFileList;
  private final Set<Link> sourceFiles = new HashSet<Link>();

  public void setSourceFiles(final Link[] sourceFiles) {
    this.sourceFiles.clear();
    if (sourceFiles != null) {
      this.sourceFiles.addAll(Arrays.asList(sourceFiles));
    }
  }

  @OslcDescription("Description of ModelExchange::sourceFile TBD")
  @OslcName("sourceFile")
  @OslcOccurs(Occurs.ZeroOrMany)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelExchange_sourceFile")
  @OslcTitle("sourceFile")
  @OslcReadOnly(false)
  public Link[]  getSourceFiles() {
  return this.sourceFiles.toArray(new Link[this.sourceFiles.size()]);
  }

}

