/*
* FMITypeDefinition.java    1.1.0  2016-07-23
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
@OslcName("TypeDefinition")
@OslcResourceShape(title = "TypeDefinition Resource Shape", describes = Constants.TYPE_FMI_TYPEDEFINITION)
public class FMITypeDefinition extends AbstractResource {

  public FMITypeDefinition() throws URISyntaxException {
    super();
  }

  public FMITypeDefinition(URI about) throws URISyntaxException {
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

  @OslcDescription("Description of TypeDefinition::identifier TBD")
  @OslcName("identifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#TypeDefinition_identifier")
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

  @OslcDescription("Description of TypeDefinition::name TBD")
  @OslcName("name")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#TypeDefinition_name")
  @OslcTitle("name")
  @OslcValueType(ValueType.XMLLiteral)
  public String getName() {
    return this.name;
  }

  // ********* Attribute: description *********
  private String description;

  public void setDescription(String description) {
    this.description = description;
  }

  @OslcDescription("Description of TypeDefinition::description TBD")
  @OslcName("description")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#TypeDefinition_description")
  @OslcTitle("description")
  @OslcValueType(ValueType.XMLLiteral)
  public String getDescription() {
    return this.description;
  }

  // ********* Attribute: baseType *********
  private String baseType;

  public void setBaseType(String baseType) {
    this.baseType = baseType;
  }

  @OslcDescription("Description of TypeDefinition::baseType TBD")
  @OslcName("baseType")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#TypeDefinition_baseType")
  @OslcTitle("baseType")
  @OslcValueType(ValueType.XMLLiteral)
  public String getBaseType() {
    return this.baseType;
  }

  // ********* Attribute: quantity *********
  private String quantity;

  public void setQuantity(String quantity) {
    this.quantity = quantity;
  }

  @OslcDescription("Description of TypeDefinition::quantity TBD")
  @OslcName("quantity")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#TypeDefinition_quantity")
  @OslcTitle("quantity")
  @OslcValueType(ValueType.XMLLiteral)
  public String getQuantity() {
    return this.quantity;
  }


  // ********* Reference: typeDef *********
  private FMITypeDef fmiTypeDef;
  private URI typeDef;

  public void setTypeDef(final URI typeDef) {
    this.typeDef = typeDef;
  }

  @OslcDescription("Description of TypeDefinition::typeDef TBD")
  @OslcName("typeDef")
  @OslcOccurs(Occurs.ExactlyOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#TypeDefinition/typeDef")
  @OslcTitle("typeDef")
  @OslcRange("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#TypeDef")
  public URI getTypeDef() {
  return this.typeDef;
  }

}

