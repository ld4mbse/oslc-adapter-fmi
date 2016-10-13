/*
* FMIScalarVariable.java    1.1.0  2016-07-23
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
@OslcName("ScalarVariable")
@OslcResourceShape(title = "ScalarVariable Resource Shape", describes = Constants.TYPE_FMI_SCALARVARIABLE)
public class FMIScalarVariable extends AbstractResource {

  public FMIScalarVariable() throws URISyntaxException {
    super();
  }

  public FMIScalarVariable(URI about) throws URISyntaxException {
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

  @OslcDescription("Description of ScalarVariable::identifier TBD")
  @OslcName("identifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariable_identifier")
  @OslcTitle("identifier")
  @OslcValueType(ValueType.XMLLiteral)
  public String getIdentifier() {
    return this.identifier;
  }

  // ********* Attribute: index *********
  private String index;

  public void setIndex(String index) {
    this.index = index;
  }

  @OslcDescription("Description of ScalarVariable::index TBD")
  @OslcName("index")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariable_index")
  @OslcTitle("index")
  @OslcValueType(ValueType.XMLLiteral)
  public String getIndex() {
    return this.index;
  }

  // ********* Attribute: name *********
  private String name;

  public void setName(String name) {
    this.name = name;
  }

  @OslcDescription("Description of ScalarVariable::name TBD")
  @OslcName("name")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariable_name")
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

  @OslcDescription("Description of ScalarVariable::description TBD")
  @OslcName("description")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariable_description")
  @OslcTitle("description")
  @OslcValueType(ValueType.XMLLiteral)
  public String getDescription() {
    return this.description;
  }

  // ********* Attribute: valueReference *********
  private String valueReference;

  public void setValueReference(String valueReference) {
    this.valueReference = valueReference;
  }

  @OslcDescription("Description of ScalarVariable::valueReference TBD")
  @OslcName("valueReference")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariable_valueReference")
  @OslcTitle("valueReference")
  @OslcValueType(ValueType.XMLLiteral)
  public String getValueReference() {
    return this.valueReference;
  }

  // ********* Attribute: variability *********
  private String variability;

  public void setVariability(String variability) {
    this.variability = variability;
  }

  @OslcDescription("Description of ScalarVariable::variability TBD")
  @OslcName("variability")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariable_variability")
  @OslcTitle("variability")
  @OslcValueType(ValueType.XMLLiteral)
  public String getVariability() {
    return this.variability;
  }

  // ********* Attribute: causality *********
  private String causality;

  public void setCausality(String causality) {
    this.causality = causality;
  }

  @OslcDescription("Description of ScalarVariable::causality TBD")
  @OslcName("causality")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariable_causality")
  @OslcTitle("causality")
  @OslcValueType(ValueType.XMLLiteral)
  public String getCausality() {
    return this.causality;
  }

  // ********* Attribute: initial *********
  private String initial;

  public void setInitial(String initial) {
    this.initial = initial;
  }

  @OslcDescription("Description of ScalarVariable::initial TBD")
  @OslcName("initial")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariable_initial")
  @OslcTitle("initial")
  @OslcValueType(ValueType.XMLLiteral)
  public String getInitial() {
    return this.initial;
  }

  // ********* Attribute: isAlias *********
  private String isAlias;

  public void setIsAlias(String isAlias) {
    this.isAlias = isAlias;
  }

  @OslcDescription("Description of ScalarVariable::isAlias TBD")
  @OslcName("isAlias")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariable_isAlias")
  @OslcTitle("isAlias")
  @OslcValueType(ValueType.XMLLiteral)
  public String getIsAlias() {
    return this.isAlias;
  }

  // ********* Attribute: aliasBase *********
  private String aliasBase;

  public void setAliasBase(String aliasBase) {
    this.aliasBase = aliasBase;
  }

  @OslcDescription("Description of ScalarVariable::aliasBase TBD")
  @OslcName("aliasBase")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariable_aliasBase")
  @OslcTitle("aliasBase")
  @OslcValueType(ValueType.XMLLiteral)
  public String getAliasBase() {
    return this.aliasBase;
  }


  // ********* Reference: listingAlias *********
  private List<FMIListingAlias> fmiListingAliasList;
  private final Set<Link> listingAliases = new HashSet<Link>();

  public void setListingAliases(final Link[] listingAliases) {
    this.listingAliases.clear();
    if (listingAliases != null) {
      this.listingAliases.addAll(Arrays.asList(listingAliases));
    }
  }

  @OslcDescription("Description of ScalarVariable::listingAlias TBD")
  @OslcName("listingAlias")
  @OslcOccurs(Occurs.ZeroOrMany)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariable_listingAlias")
  @OslcTitle("listingAlias")
  @OslcReadOnly(false)
  public Link[]  getListingAliases() {
  return this.listingAliases.toArray(new Link[this.listingAliases.size()]);
  }

  // ********* Reference: listingDirectDependency *********
  private List<FMIListingDirectDependency> fmiListingDirectDependencyList;
  private final Set<Link> listingDirectDependencies = new HashSet<Link>();

  public void setListingDirectDependencies(final Link[] listingDirectDependencies) {
    this.listingDirectDependencies.clear();
    if (listingDirectDependencies != null) {
      this.listingDirectDependencies.addAll(Arrays.asList(listingDirectDependencies));
    }
  }

  @OslcDescription("Description of ScalarVariable::listingDirectDependency TBD")
  @OslcName("listingDirectDependency")
  @OslcOccurs(Occurs.ZeroOrMany)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariable_listingDirectDependency")
  @OslcTitle("listingDirectDependency")
  @OslcReadOnly(false)
  public Link[]  getListingDirectDependencies() {
  return this.listingDirectDependencies.toArray(new Link[this.listingDirectDependencies.size()]);
  }

  // ********* Reference: scalarVariableType *********
  private FMIScalarVariableType fmiScalarVariableType;
  private URI scalarVariableType;

  public void setScalarVariableType(final URI scalarVariableType) {
    this.scalarVariableType = scalarVariableType;
  }

  @OslcDescription("Description of ScalarVariable::scalarVariableType TBD")
  @OslcName("scalarVariableType")
  @OslcOccurs(Occurs.ExactlyOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariable/scalarVariableType")
  @OslcTitle("scalarVariableType")
  @OslcRange("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ScalarVariableType")
  public URI getScalarVariableType() {
  return this.scalarVariableType;
  }

}

