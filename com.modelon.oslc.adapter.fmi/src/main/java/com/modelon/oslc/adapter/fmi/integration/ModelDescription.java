/*
* ModelDescription.java    1.1.0  2016-07-22
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
*/

package com.modelon.oslc.adapter.fmi.integration;

import java.util.List;

public class ModelDescription {
  public String fmuPath;
  public String tmpPath;
  public String status;
  public String statusText;
  public String fmiVersion;
  public String modelName;
  public String modelIdentifier;
  public String guid;
  public String description;
  public String author;
  public String version;
  public String copyright;
  public String license;
  public String kind;
  public String generationTool;
  public String generationDateAndTime;
  public String variableNamingConvention;
  public String numberOfContinuousStates;
  public String numberOfEventIndicators;
  public DefaultExperiment defaultExperiment;
  public CoSimulation coSimulation;
  public ModelExchange modelExchange;
  public ModelStructure modelStructure;
  public ModelVariables modelVariables;
  public List<TypeDefinition> typeDefinitions;
  public List<UnitDefinition> unitDefinitions;
  public List<VendorAnnotation> vendorAnnotations;
}
