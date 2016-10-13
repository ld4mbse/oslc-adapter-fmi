/*
* CoSimulation.java    1.1.0  2016-07-22
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

public class CoSimulation {
  public String modelIdentifier;
  // FMI 2.0
  public String needsExecutionTool;
  public String canGetAndSetFMUstate;
  public String canSerializeFMUstate;
  public String providesDirectionalDerivatives;
  // FMI 1.0
  public String canHandleVariableCommunicationStepSize;
  public String canHandleEvents;
  public String canRejectSteps;
  public String canInterpolateInputs;
  public String maxOutputDerivativeOrder;
  public String canRunAsynchronuously;
  public String canSignalEvents;
  public String canBeInstantiatedOnlyOncePerProcess;
  public String canNotUseMemoryManagementFunctions;
  public List<SourceFile> sourceFiles;
}
