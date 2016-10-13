/*
* FMIDerivative.java    1.1.0  2016-07-23
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
@OslcName("Derivative")
@OslcResourceShape(title = "Derivative Resource Shape", describes = Constants.TYPE_FMI_DERIVATIVE)
public class FMIDerivative extends AbstractResource {

  public FMIDerivative() throws URISyntaxException {
    super();
  }

  public FMIDerivative(URI about) throws URISyntaxException {
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

  @OslcDescription("Description of Derivative::identifier TBD")
  @OslcName("identifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#Derivative_identifier")
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

  @OslcDescription("Description of Derivative::name TBD")
  @OslcName("name")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#Derivative_name")
  @OslcTitle("name")
  @OslcValueType(ValueType.XMLLiteral)
  public String getName() {
    return this.name;
  }

  // ********* Attribute: index *********
  private String index;

  public void setIndex(String index) {
    this.index = index;
  }

  @OslcDescription("Description of Derivative::index TBD")
  @OslcName("index")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#Derivative_index")
  @OslcTitle("index")
  @OslcValueType(ValueType.XMLLiteral)
  public String getIndex() {
    return this.index;
  }

  // ********* Attribute: dependencies *********
  private String dependencies;

  public void setDependencies(String dependencies) {
    this.dependencies = dependencies;
  }

  @OslcDescription("Description of Derivative::dependencies TBD")
  @OslcName("dependencies")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#Derivative_dependencies")
  @OslcTitle("dependencies")
  @OslcValueType(ValueType.XMLLiteral)
  public String getDependencies() {
    return this.dependencies;
  }

  // ********* Attribute: dependenciesKind *********
  private String dependenciesKind;

  public void setDependenciesKind(String dependenciesKind) {
    this.dependenciesKind = dependenciesKind;
  }

  @OslcDescription("Description of Derivative::dependenciesKind TBD")
  @OslcName("dependenciesKind")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#Derivative_dependenciesKind")
  @OslcTitle("dependenciesKind")
  @OslcValueType(ValueType.XMLLiteral)
  public String getDependenciesKind() {
    return this.dependenciesKind;
  }


}

