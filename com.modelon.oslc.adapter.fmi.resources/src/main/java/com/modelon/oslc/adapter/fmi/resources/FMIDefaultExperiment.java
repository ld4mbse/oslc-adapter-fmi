/*
* FMIDefaultExperiment.java    1.1.0  2016-07-23
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
@OslcName("DefaultExperiment")
@OslcResourceShape(title = "DefaultExperiment Resource Shape", describes = Constants.TYPE_FMI_DEFAULTEXPERIMENT)
public class FMIDefaultExperiment extends AbstractResource {

  public FMIDefaultExperiment() throws URISyntaxException {
    super();
  }

  public FMIDefaultExperiment(URI about) throws URISyntaxException {
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

  @OslcDescription("Description of DefaultExperiment::identifier TBD")
  @OslcName("identifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#DefaultExperiment_identifier")
  @OslcTitle("identifier")
  @OslcValueType(ValueType.XMLLiteral)
  public String getIdentifier() {
    return this.identifier;
  }

  // ********* Attribute: startTime *********
  private String startTime;

  public void setStartTime(String startTime) {
    this.startTime = startTime;
  }

  @OslcDescription("Description of DefaultExperiment::startTime TBD")
  @OslcName("startTime")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#DefaultExperiment_startTime")
  @OslcTitle("startTime")
  @OslcValueType(ValueType.XMLLiteral)
  public String getStartTime() {
    return this.startTime;
  }

  // ********* Attribute: stopTime *********
  private String stopTime;

  public void setStopTime(String stopTime) {
    this.stopTime = stopTime;
  }

  @OslcDescription("Description of DefaultExperiment::stopTime TBD")
  @OslcName("stopTime")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#DefaultExperiment_stopTime")
  @OslcTitle("stopTime")
  @OslcValueType(ValueType.XMLLiteral)
  public String getStopTime() {
    return this.stopTime;
  }

  // ********* Attribute: tolerance *********
  private String tolerance;

  public void setTolerance(String tolerance) {
    this.tolerance = tolerance;
  }

  @OslcDescription("Description of DefaultExperiment::tolerance TBD")
  @OslcName("tolerance")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#DefaultExperiment_tolerance")
  @OslcTitle("tolerance")
  @OslcValueType(ValueType.XMLLiteral)
  public String getTolerance() {
    return this.tolerance;
  }

  // ********* Attribute: step *********
  private String step;

  public void setStep(String step) {
    this.step = step;
  }

  @OslcDescription("Description of DefaultExperiment::step TBD")
  @OslcName("step")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#DefaultExperiment_step")
  @OslcTitle("step")
  @OslcValueType(ValueType.XMLLiteral)
  public String getStep() {
    return this.step;
  }


}

