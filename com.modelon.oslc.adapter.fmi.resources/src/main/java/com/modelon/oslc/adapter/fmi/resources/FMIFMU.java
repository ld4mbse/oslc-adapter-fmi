/*
* FMIFMU.java    1.1.0  2016-07-23
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
@OslcName("FMU")
@OslcResourceShape(title = "FMU Resource Shape", describes = Constants.TYPE_FMI_FMU)
public class FMIFMU extends AbstractResource {

  public FMIFMU() throws URISyntaxException {
    super();
  }

  public FMIFMU(URI about) throws URISyntaxException {
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

  @OslcDescription("Description of FMU::identifier TBD")
  @OslcName("identifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#FMU_identifier")
  @OslcTitle("identifier")
  @OslcValueType(ValueType.XMLLiteral)
  public String getIdentifier() {
    return this.identifier;
  }

  // ********* Attribute: fmiVersion *********
  private String fmiVersion;

  public void setFmiVersion(String fmiVersion) {
    this.fmiVersion = fmiVersion;
  }

  @OslcDescription("Description of FMU::fmiVersion TBD")
  @OslcName("fmiVersion")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#FMU_fmiVersion")
  @OslcTitle("fmiVersion")
  @OslcValueType(ValueType.XMLLiteral)
  public String getFmiVersion() {
    return this.fmiVersion;
  }

  // ********* Attribute: isModelExchangeFMU *********
  private String isModelExchangeFMU;

  public void setIsModelExchangeFMU(String isModelExchangeFMU) {
    this.isModelExchangeFMU = isModelExchangeFMU;
  }

  @OslcDescription("Description of FMU::isModelExchangeFMU TBD")
  @OslcName("isModelExchangeFMU")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#FMU_isModelExchangeFMU")
  @OslcTitle("isModelExchangeFMU")
  @OslcValueType(ValueType.XMLLiteral)
  public String getIsModelExchangeFMU() {
    return this.isModelExchangeFMU;
  }

  // ********* Attribute: isCoSimulationFMU *********
  private String isCoSimulationFMU;

  public void setIsCoSimulationFMU(String isCoSimulationFMU) {
    this.isCoSimulationFMU = isCoSimulationFMU;
  }

  @OslcDescription("Description of FMU::isCoSimulationFMU TBD")
  @OslcName("isCoSimulationFMU")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#FMU_isCoSimulationFMU")
  @OslcTitle("isCoSimulationFMU")
  @OslcValueType(ValueType.XMLLiteral)
  public String getIsCoSimulationFMU() {
    return this.isCoSimulationFMU;
  }


  // ********* Reference: modelDescription *********
  private FMIModelDescription fmiModelDescription;
  private URI modelDescription;

  public void setModelDescription(final URI modelDescription) {
    this.modelDescription = modelDescription;
  }

  @OslcDescription("Description of FMU::modelDescription TBD")
  @OslcName("modelDescription")
  @OslcOccurs(Occurs.ExactlyOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#FMU/modelDescription")
  @OslcTitle("modelDescription")
  @OslcRange("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelDescription")
  public URI getModelDescription() {
  return this.modelDescription;
  }

}

