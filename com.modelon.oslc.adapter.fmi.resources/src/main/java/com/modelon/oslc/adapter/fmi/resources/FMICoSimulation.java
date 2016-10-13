/*
* FMICoSimulation.java    1.1.0  2016-07-23
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
@OslcName("CoSimulation")
@OslcResourceShape(title = "CoSimulation Resource Shape", describes = Constants.TYPE_FMI_COSIMULATION)
public class FMICoSimulation extends AbstractResource {

  public FMICoSimulation() throws URISyntaxException {
    super();
  }

  public FMICoSimulation(URI about) throws URISyntaxException {
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

  @OslcDescription("Description of CoSimulation::identifier TBD")
  @OslcName("identifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_identifier")
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

  @OslcDescription("Description of CoSimulation::modelIdentifier TBD")
  @OslcName("modelIdentifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_modelIdentifier")
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

  @OslcDescription("Description of CoSimulation::needsExecutionTool TBD")
  @OslcName("needsExecutionTool")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_needsExecutionTool")
  @OslcTitle("needsExecutionTool")
  @OslcValueType(ValueType.XMLLiteral)
  public String getNeedsExecutionTool() {
    return this.needsExecutionTool;
  }

  // ********* Attribute: canGetAndSetFMUstate *********
  private String canGetAndSetFMUstate;

  public void setCanGetAndSetFMUstate(String canGetAndSetFMUstate) {
    this.canGetAndSetFMUstate = canGetAndSetFMUstate;
  }

  @OslcDescription("Description of CoSimulation::canGetAndSetFMUstate TBD")
  @OslcName("canGetAndSetFMUstate")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_canGetAndSetFMUstate")
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

  @OslcDescription("Description of CoSimulation::canSerializeFMUstate TBD")
  @OslcName("canSerializeFMUstate")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_canSerializeFMUstate")
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

  @OslcDescription("Description of CoSimulation::providesDirectionalDerivatives TBD")
  @OslcName("providesDirectionalDerivatives")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_providesDirectionalDerivatives")
  @OslcTitle("providesDirectionalDerivatives")
  @OslcValueType(ValueType.XMLLiteral)
  public String getProvidesDirectionalDerivatives() {
    return this.providesDirectionalDerivatives;
  }

  // ********* Attribute: canHandleVariableCommunicationStepSize *********
  private String canHandleVariableCommunicationStepSize;

  public void setCanHandleVariableCommunicationStepSize(String canHandleVariableCommunicationStepSize) {
    this.canHandleVariableCommunicationStepSize = canHandleVariableCommunicationStepSize;
  }

  @OslcDescription("Description of CoSimulation::canHandleVariableCommunicationStepSize TBD")
  @OslcName("canHandleVariableCommunicationStepSize")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_canHandleVariableCommunicationStepSize")
  @OslcTitle("canHandleVariableCommunicationStepSize")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCanHandleVariableCommunicationStepSize() {
    return this.canHandleVariableCommunicationStepSize;
  }

  // ********* Attribute: canHandleEvents *********
  private String canHandleEvents;

  public void setCanHandleEvents(String canHandleEvents) {
    this.canHandleEvents = canHandleEvents;
  }

  @OslcDescription("Description of CoSimulation::canHandleEvents TBD")
  @OslcName("canHandleEvents")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_canHandleEvents")
  @OslcTitle("canHandleEvents")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCanHandleEvents() {
    return this.canHandleEvents;
  }

  // ********* Attribute: canRejectSteps *********
  private String canRejectSteps;

  public void setCanRejectSteps(String canRejectSteps) {
    this.canRejectSteps = canRejectSteps;
  }

  @OslcDescription("Description of CoSimulation::canRejectSteps TBD")
  @OslcName("canRejectSteps")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_canRejectSteps")
  @OslcTitle("canRejectSteps")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCanRejectSteps() {
    return this.canRejectSteps;
  }

  // ********* Attribute: canInterpolateInputs *********
  private String canInterpolateInputs;

  public void setCanInterpolateInputs(String canInterpolateInputs) {
    this.canInterpolateInputs = canInterpolateInputs;
  }

  @OslcDescription("Description of CoSimulation::canInterpolateInputs TBD")
  @OslcName("canInterpolateInputs")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_canInterpolateInputs")
  @OslcTitle("canInterpolateInputs")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCanInterpolateInputs() {
    return this.canInterpolateInputs;
  }

  // ********* Attribute: maxOutputDerivativeOrder *********
  private String maxOutputDerivativeOrder;

  public void setMaxOutputDerivativeOrder(String maxOutputDerivativeOrder) {
    this.maxOutputDerivativeOrder = maxOutputDerivativeOrder;
  }

  @OslcDescription("Description of CoSimulation::maxOutputDerivativeOrder TBD")
  @OslcName("maxOutputDerivativeOrder")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_maxOutputDerivativeOrder")
  @OslcTitle("maxOutputDerivativeOrder")
  @OslcValueType(ValueType.XMLLiteral)
  public String getMaxOutputDerivativeOrder() {
    return this.maxOutputDerivativeOrder;
  }

  // ********* Attribute: canRunAsynchronuously *********
  private String canRunAsynchronuously;

  public void setCanRunAsynchronuously(String canRunAsynchronuously) {
    this.canRunAsynchronuously = canRunAsynchronuously;
  }

  @OslcDescription("Description of CoSimulation::canRunAsynchronuously TBD")
  @OslcName("canRunAsynchronuously")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_canRunAsynchronuously")
  @OslcTitle("canRunAsynchronuously")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCanRunAsynchronuously() {
    return this.canRunAsynchronuously;
  }

  // ********* Attribute: canSignalEvents *********
  private String canSignalEvents;

  public void setCanSignalEvents(String canSignalEvents) {
    this.canSignalEvents = canSignalEvents;
  }

  @OslcDescription("Description of CoSimulation::canSignalEvents TBD")
  @OslcName("canSignalEvents")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_canSignalEvents")
  @OslcTitle("canSignalEvents")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCanSignalEvents() {
    return this.canSignalEvents;
  }

  // ********* Attribute: canBeInstantiatedOnlyOncePerProcess *********
  private String canBeInstantiatedOnlyOncePerProcess;

  public void setCanBeInstantiatedOnlyOncePerProcess(String canBeInstantiatedOnlyOncePerProcess) {
    this.canBeInstantiatedOnlyOncePerProcess = canBeInstantiatedOnlyOncePerProcess;
  }

  @OslcDescription("Description of CoSimulation::canBeInstantiatedOnlyOncePerProcess TBD")
  @OslcName("canBeInstantiatedOnlyOncePerProcess")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_canBeInstantiatedOnlyOncePerProcess")
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

  @OslcDescription("Description of CoSimulation::canNotUseMemoryManagementFunctions TBD")
  @OslcName("canNotUseMemoryManagementFunctions")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_canNotUseMemoryManagementFunctions")
  @OslcTitle("canNotUseMemoryManagementFunctions")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCanNotUseMemoryManagementFunctions() {
    return this.canNotUseMemoryManagementFunctions;
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

  @OslcDescription("Description of CoSimulation::sourceFile TBD")
  @OslcName("sourceFile")
  @OslcOccurs(Occurs.ZeroOrMany)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#CoSimulation_sourceFile")
  @OslcTitle("sourceFile")
  @OslcReadOnly(false)
  public Link[]  getSourceFiles() {
  return this.sourceFiles.toArray(new Link[this.sourceFiles.size()]);
  }

}

