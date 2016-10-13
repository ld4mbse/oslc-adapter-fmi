/*
* FMIScalarVariableType.java    1.1.0  2016-07-23
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
@OslcName("ScalarVariableType")
@OslcResourceShape(title = "ScalarVariableType Resource Shape", describes = Constants.TYPE_FMI_SCALARVARIABLETYPE)
public class FMIScalarVariableType extends AbstractResource {

  public FMIScalarVariableType() throws URISyntaxException {
    super();
  }

  public FMIScalarVariableType(URI about) throws URISyntaxException {
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

  @OslcDescription("Description of ScalarVariableType::identifier TBD")
  @OslcName("identifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariableType_identifier")
  @OslcTitle("identifier")
  @OslcValueType(ValueType.XMLLiteral)
  public String getIdentifier() {
    return this.identifier;
  }

  // ********* Attribute: name *********
  private String name;

  public void setName(String name) {
    this.name = name;
  }

  @OslcDescription("Description of ScalarVariableType::name TBD")
  @OslcName("name")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariableType_name")
  @OslcTitle("name")
  @OslcValueType(ValueType.XMLLiteral)
  public String getName() {
    return this.name;
  }

  // ********* Attribute: start *********
  private String start;

  public void setStart(String start) {
    this.start = start;
  }

  @OslcDescription("Description of ScalarVariableType::start TBD")
  @OslcName("start")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariableType_start")
  @OslcTitle("start")
  @OslcValueType(ValueType.XMLLiteral)
  public String getStart() {
    return this.start;
  }

  // ********* Attribute: min *********
  private String min;

  public void setMin(String min) {
    this.min = min;
  }

  @OslcDescription("Description of ScalarVariableType::min TBD")
  @OslcName("min")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariableType_min")
  @OslcTitle("min")
  @OslcValueType(ValueType.XMLLiteral)
  public String getMin() {
    return this.min;
  }

  // ********* Attribute: max *********
  private String max;

  public void setMax(String max) {
    this.max = max;
  }

  @OslcDescription("Description of ScalarVariableType::max TBD")
  @OslcName("max")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariableType_max")
  @OslcTitle("max")
  @OslcValueType(ValueType.XMLLiteral)
  public String getMax() {
    return this.max;
  }

  // ********* Attribute: nominal *********
  private String nominal;

  public void setNominal(String nominal) {
    this.nominal = nominal;
  }

  @OslcDescription("Description of ScalarVariableType::nominal TBD")
  @OslcName("nominal")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariableType_nominal")
  @OslcTitle("nominal")
  @OslcValueType(ValueType.XMLLiteral)
  public String getNominal() {
    return this.nominal;
  }

  // ********* Attribute: declaredType *********
  private String declaredType;

  public void setDeclaredType(String declaredType) {
    this.declaredType = declaredType;
  }

  @OslcDescription("Description of ScalarVariableType::declaredType TBD")
  @OslcName("declaredType")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariableType_declaredType")
  @OslcTitle("declaredType")
  @OslcValueType(ValueType.XMLLiteral)
  public String getDeclaredType() {
    return this.declaredType;
  }

  // ********* Attribute: unit *********
  private String unit;

  public void setUnit(String unit) {
    this.unit = unit;
  }

  @OslcDescription("Description of ScalarVariableType::unit TBD")
  @OslcName("unit")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariableType_unit")
  @OslcTitle("unit")
  @OslcValueType(ValueType.XMLLiteral)
  public String getUnit() {
    return this.unit;
  }

  // ********* Attribute: displayUnit *********
  private String displayUnit;

  public void setDisplayUnit(String displayUnit) {
    this.displayUnit = displayUnit;
  }

  @OslcDescription("Description of ScalarVariableType::displayUnit TBD")
  @OslcName("displayUnit")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariableType_displayUnit")
  @OslcTitle("displayUnit")
  @OslcValueType(ValueType.XMLLiteral)
  public String getDisplayUnit() {
    return this.displayUnit;
  }


}

