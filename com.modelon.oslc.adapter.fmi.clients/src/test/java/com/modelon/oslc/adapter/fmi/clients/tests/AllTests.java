/*
* AllTests.java    1.1.0  2016-07-23
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

package com.modelon.oslc.adapter.fmi.clients.tests;

import org.junit.runner.RunWith;
import org.junit.runners.Suite;

@RunWith(Suite.class)

@Suite.SuiteClasses({
  TestFMIFMURdfXml.class,
  TestFMIModelDescriptionRdfXml.class,
  TestFMIDefaultExperimentRdfXml.class,
  TestFMIModelExchangeRdfXml.class,
  TestFMICoSimulationRdfXml.class,
  TestFMISourceFileRdfXml.class,
  TestFMIUnitDefinitionRdfXml.class,
  TestFMIBaseUnitRdfXml.class,
  TestFMIBaseUnitDefinitionRdfXml.class,
  TestFMIVendorAnnotationRdfXml.class,
  TestFMIVendorToolRdfXml.class,
  TestFMIAnnotationRdfXml.class,
  TestFMITypeDefinitionRdfXml.class,
  TestFMITypeDefRdfXml.class,
  TestFMIEnumerationRdfXml.class,
  TestFMIModelVariablesRdfXml.class,
  TestFMIScalarVariableRdfXml.class,
  TestFMIScalarVariableTypeRdfXml.class,
  TestFMIListingAliasRdfXml.class,
  TestFMIListingDirectDependencyRdfXml.class,
  TestFMIModelStructureRdfXml.class,
  TestFMIDerivativeRdfXml.class,
  TestFMIInitialUnknownRdfXml.class,
  TestFMIOutputRdfXml.class})
public class AllTests {

}
