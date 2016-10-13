/*
* FMIBaseUnit.java    1.1.0  2016-07-23
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
@OslcName("BaseUnit")
@OslcResourceShape(title = "BaseUnit Resource Shape", describes = Constants.TYPE_FMI_BASEUNIT)
public class FMIBaseUnit extends AbstractResource {

  public FMIBaseUnit() throws URISyntaxException {
    super();
  }

  public FMIBaseUnit(URI about) throws URISyntaxException {
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

  @OslcDescription("Description of BaseUnit::identifier TBD")
  @OslcName("identifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#BaseUnit_identifier")
  @OslcTitle("identifier")
  @OslcValueType(ValueType.XMLLiteral)
  public String getIdentifier() {
    return this.identifier;
  }

  // ********* Attribute: unit *********
  private String unit;

  public void setUnit(String unit) {
    this.unit = unit;
  }

  @OslcDescription("Description of BaseUnit::unit TBD")
  @OslcName("unit")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#BaseUnit_unit")
  @OslcTitle("unit")
  @OslcValueType(ValueType.XMLLiteral)
  public String getUnit() {
    return this.unit;
  }

  // ********* Attribute: factor *********
  private String factor;

  public void setFactor(String factor) {
    this.factor = factor;
  }

  @OslcDescription("Description of BaseUnit::factor TBD")
  @OslcName("factor")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#BaseUnit_factor")
  @OslcTitle("factor")
  @OslcValueType(ValueType.XMLLiteral)
  public String getFactor() {
    return this.factor;
  }

  // ********* Attribute: offset *********
  private String offset;

  public void setOffset(String offset) {
    this.offset = offset;
  }

  @OslcDescription("Description of BaseUnit::offset TBD")
  @OslcName("offset")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#BaseUnit_offset")
  @OslcTitle("offset")
  @OslcValueType(ValueType.XMLLiteral)
  public String getOffset() {
    return this.offset;
  }

  // ********* Attribute: displayUnitNumber *********
  private String displayUnitNumber;

  public void setDisplayUnitNumber(String displayUnitNumber) {
    this.displayUnitNumber = displayUnitNumber;
  }

  @OslcDescription("Description of BaseUnit::displayUnitNumber TBD")
  @OslcName("displayUnitNumber")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#BaseUnit_displayUnitNumber")
  @OslcTitle("displayUnitNumber")
  @OslcValueType(ValueType.XMLLiteral)
  public String getDisplayUnitNumber() {
    return this.displayUnitNumber;
  }


  // ********* Reference: baseUnitDefinition *********
  private FMIBaseUnitDefinition fmiBaseUnitDefinition;
  private URI baseUnitDefinition;

  public void setBaseUnitDefinition(final URI baseUnitDefinition) {
    this.baseUnitDefinition = baseUnitDefinition;
  }

  @OslcDescription("Description of BaseUnit::baseUnitDefinition TBD")
  @OslcName("baseUnitDefinition")
  @OslcOccurs(Occurs.ExactlyOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#BaseUnit/baseUnitDefinition")
  @OslcTitle("baseUnitDefinition")
  @OslcRange("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#BaseUnitDefinition")
  public URI getBaseUnitDefinition() {
  return this.baseUnitDefinition;
  }

}

