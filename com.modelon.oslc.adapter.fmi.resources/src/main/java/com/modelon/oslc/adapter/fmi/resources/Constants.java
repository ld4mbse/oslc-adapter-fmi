/*
* Constants.java    1.1.0  2016-07-23
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

public interface Constants {

  public static String HDR_OSLC_VERSION = "OSLC-Core-Version";
  public static String FMI_PREFIX = "fmi";
  public static String FMI_NAMESPACE = "http://localhost:8686/oslc4jfmi/services/rdfvocabulary#";

  public static String FMI_FMU_PREFIX = "fmi_fmu";
  public static String FMI_FMU_NAMESPACE = FMI_NAMESPACE + "FMU/";
  public static String TYPE_FMI_FMU = FMI_NAMESPACE + "FMU";
  public static String FMI_FMU_DOMAIN = "https://www.fmi-standard.org/fmu/rdf#";
  public static String PATH_FMI_FMU = "FMU";

  public static String FMI_MODELDESCRIPTION_PREFIX = "fmi_modeldescription";
  public static String FMI_MODELDESCRIPTION_NAMESPACE = FMI_NAMESPACE + "ModelDescription/";
  public static String TYPE_FMI_MODELDESCRIPTION = FMI_NAMESPACE + "ModelDescription";
  public static String FMI_MODELDESCRIPTION_DOMAIN = "https://www.fmi-standard.org/modeldescription/rdf#";
  public static String PATH_FMI_MODELDESCRIPTION = "ModelDescription";

  public static String FMI_DEFAULTEXPERIMENT_PREFIX = "fmi_defaultexperiment";
  public static String FMI_DEFAULTEXPERIMENT_NAMESPACE = FMI_NAMESPACE + "DefaultExperiment/";
  public static String TYPE_FMI_DEFAULTEXPERIMENT = FMI_NAMESPACE + "DefaultExperiment";
  public static String FMI_DEFAULTEXPERIMENT_DOMAIN = "https://www.fmi-standard.org/defaultexperiment/rdf#";
  public static String PATH_FMI_DEFAULTEXPERIMENT = "DefaultExperiment";

  public static String FMI_MODELEXCHANGE_PREFIX = "fmi_modelexchange";
  public static String FMI_MODELEXCHANGE_NAMESPACE = FMI_NAMESPACE + "ModelExchange/";
  public static String TYPE_FMI_MODELEXCHANGE = FMI_NAMESPACE + "ModelExchange";
  public static String FMI_MODELEXCHANGE_DOMAIN = "https://www.fmi-standard.org/modelexchange/rdf#";
  public static String PATH_FMI_MODELEXCHANGE = "ModelExchange";

  public static String FMI_COSIMULATION_PREFIX = "fmi_cosimulation";
  public static String FMI_COSIMULATION_NAMESPACE = FMI_NAMESPACE + "CoSimulation/";
  public static String TYPE_FMI_COSIMULATION = FMI_NAMESPACE + "CoSimulation";
  public static String FMI_COSIMULATION_DOMAIN = "https://www.fmi-standard.org/cosimulation/rdf#";
  public static String PATH_FMI_COSIMULATION = "CoSimulation";

  public static String FMI_SOURCEFILE_PREFIX = "fmi_sourcefile";
  public static String FMI_SOURCEFILE_NAMESPACE = FMI_NAMESPACE + "SourceFile/";
  public static String TYPE_FMI_SOURCEFILE = FMI_NAMESPACE + "SourceFile";
  public static String FMI_SOURCEFILE_DOMAIN = "https://www.fmi-standard.org/sourcefile/rdf#";
  public static String PATH_FMI_SOURCEFILE = "SourceFile";

  public static String FMI_UNITDEFINITION_PREFIX = "fmi_unitdefinition";
  public static String FMI_UNITDEFINITION_NAMESPACE = FMI_NAMESPACE + "UnitDefinition/";
  public static String TYPE_FMI_UNITDEFINITION = FMI_NAMESPACE + "UnitDefinition";
  public static String FMI_UNITDEFINITION_DOMAIN = "https://www.fmi-standard.org/unitdefinition/rdf#";
  public static String PATH_FMI_UNITDEFINITION = "UnitDefinition";

  public static String FMI_BASEUNIT_PREFIX = "fmi_baseunit";
  public static String FMI_BASEUNIT_NAMESPACE = FMI_NAMESPACE + "BaseUnit/";
  public static String TYPE_FMI_BASEUNIT = FMI_NAMESPACE + "BaseUnit";
  public static String FMI_BASEUNIT_DOMAIN = "https://www.fmi-standard.org/baseunit/rdf#";
  public static String PATH_FMI_BASEUNIT = "BaseUnit";

  public static String FMI_BASEUNITDEFINITION_PREFIX = "fmi_baseunitdefinition";
  public static String FMI_BASEUNITDEFINITION_NAMESPACE = FMI_NAMESPACE + "BaseUnitDefinition/";
  public static String TYPE_FMI_BASEUNITDEFINITION = FMI_NAMESPACE + "BaseUnitDefinition";
  public static String FMI_BASEUNITDEFINITION_DOMAIN = "https://www.fmi-standard.org/baseunitdefinition/rdf#";
  public static String PATH_FMI_BASEUNITDEFINITION = "BaseUnitDefinition";

  public static String FMI_VENDORANNOTATION_PREFIX = "fmi_vendorannotation";
  public static String FMI_VENDORANNOTATION_NAMESPACE = FMI_NAMESPACE + "VendorAnnotation/";
  public static String TYPE_FMI_VENDORANNOTATION = FMI_NAMESPACE + "VendorAnnotation";
  public static String FMI_VENDORANNOTATION_DOMAIN = "https://www.fmi-standard.org/vendorannotation/rdf#";
  public static String PATH_FMI_VENDORANNOTATION = "VendorAnnotation";

  public static String FMI_VENDORTOOL_PREFIX = "fmi_vendortool";
  public static String FMI_VENDORTOOL_NAMESPACE = FMI_NAMESPACE + "VendorTool/";
  public static String TYPE_FMI_VENDORTOOL = FMI_NAMESPACE + "VendorTool";
  public static String FMI_VENDORTOOL_DOMAIN = "https://www.fmi-standard.org/vendortool/rdf#";
  public static String PATH_FMI_VENDORTOOL = "VendorTool";

  public static String FMI_ANNOTATION_PREFIX = "fmi_annotation";
  public static String FMI_ANNOTATION_NAMESPACE = FMI_NAMESPACE + "Annotation/";
  public static String TYPE_FMI_ANNOTATION = FMI_NAMESPACE + "Annotation";
  public static String FMI_ANNOTATION_DOMAIN = "https://www.fmi-standard.org/annotation/rdf#";
  public static String PATH_FMI_ANNOTATION = "Annotation";

  public static String FMI_TYPEDEFINITION_PREFIX = "fmi_typedefinition";
  public static String FMI_TYPEDEFINITION_NAMESPACE = FMI_NAMESPACE + "TypeDefinition/";
  public static String TYPE_FMI_TYPEDEFINITION = FMI_NAMESPACE + "TypeDefinition";
  public static String FMI_TYPEDEFINITION_DOMAIN = "https://www.fmi-standard.org/typedefinition/rdf#";
  public static String PATH_FMI_TYPEDEFINITION = "TypeDefinition";

  public static String FMI_TYPEDEF_PREFIX = "fmi_typedef";
  public static String FMI_TYPEDEF_NAMESPACE = FMI_NAMESPACE + "TypeDef/";
  public static String TYPE_FMI_TYPEDEF = FMI_NAMESPACE + "TypeDef";
  public static String FMI_TYPEDEF_DOMAIN = "https://www.fmi-standard.org/typedef/rdf#";
  public static String PATH_FMI_TYPEDEF = "TypeDef";

  public static String FMI_ENUMERATION_PREFIX = "fmi_enumeration";
  public static String FMI_ENUMERATION_NAMESPACE = FMI_NAMESPACE + "Enumeration/";
  public static String TYPE_FMI_ENUMERATION = FMI_NAMESPACE + "Enumeration";
  public static String FMI_ENUMERATION_DOMAIN = "https://www.fmi-standard.org/enumeration/rdf#";
  public static String PATH_FMI_ENUMERATION = "Enumeration";

  public static String FMI_MODELVARIABLES_PREFIX = "fmi_modelvariables";
  public static String FMI_MODELVARIABLES_NAMESPACE = FMI_NAMESPACE + "ModelVariables/";
  public static String TYPE_FMI_MODELVARIABLES = FMI_NAMESPACE + "ModelVariables";
  public static String FMI_MODELVARIABLES_DOMAIN = "https://www.fmi-standard.org/modelvariables/rdf#";
  public static String PATH_FMI_MODELVARIABLES = "ModelVariables";

  public static String FMI_SCALARVARIABLE_PREFIX = "fmi_scalarvariable";
  public static String FMI_SCALARVARIABLE_NAMESPACE = FMI_NAMESPACE + "ScalarVariable/";
  public static String TYPE_FMI_SCALARVARIABLE = FMI_NAMESPACE + "ScalarVariable";
  public static String FMI_SCALARVARIABLE_DOMAIN = "https://www.fmi-standard.org/scalarvariable/rdf#";
  public static String PATH_FMI_SCALARVARIABLE = "ScalarVariable";

  public static String FMI_SCALARVARIABLETYPE_PREFIX = "fmi_scalarvariabletype";
  public static String FMI_SCALARVARIABLETYPE_NAMESPACE = FMI_NAMESPACE + "ScalarVariableType/";
  public static String TYPE_FMI_SCALARVARIABLETYPE = FMI_NAMESPACE + "ScalarVariableType";
  public static String FMI_SCALARVARIABLETYPE_DOMAIN = "https://www.fmi-standard.org/scalarvariabletype/rdf#";
  public static String PATH_FMI_SCALARVARIABLETYPE = "ScalarVariableType";

  public static String FMI_LISTINGALIAS_PREFIX = "fmi_listingalias";
  public static String FMI_LISTINGALIAS_NAMESPACE = FMI_NAMESPACE + "ListingAlias/";
  public static String TYPE_FMI_LISTINGALIAS = FMI_NAMESPACE + "ListingAlias";
  public static String FMI_LISTINGALIAS_DOMAIN = "https://www.fmi-standard.org/listingalias/rdf#";
  public static String PATH_FMI_LISTINGALIAS = "ListingAlias";

  public static String FMI_LISTINGDIRECTDEPENDENCY_PREFIX = "fmi_listingdirectdependency";
  public static String FMI_LISTINGDIRECTDEPENDENCY_NAMESPACE = FMI_NAMESPACE + "ListingDirectDependency/";
  public static String TYPE_FMI_LISTINGDIRECTDEPENDENCY = FMI_NAMESPACE + "ListingDirectDependency";
  public static String FMI_LISTINGDIRECTDEPENDENCY_DOMAIN = "https://www.fmi-standard.org/listingdirectdependency/rdf#";
  public static String PATH_FMI_LISTINGDIRECTDEPENDENCY = "ListingDirectDependency";

  public static String FMI_MODELSTRUCTURE_PREFIX = "fmi_modelstructure";
  public static String FMI_MODELSTRUCTURE_NAMESPACE = FMI_NAMESPACE + "ModelStructure/";
  public static String TYPE_FMI_MODELSTRUCTURE = FMI_NAMESPACE + "ModelStructure";
  public static String FMI_MODELSTRUCTURE_DOMAIN = "https://www.fmi-standard.org/modelstructure/rdf#";
  public static String PATH_FMI_MODELSTRUCTURE = "ModelStructure";

  public static String FMI_DERIVATIVE_PREFIX = "fmi_derivative";
  public static String FMI_DERIVATIVE_NAMESPACE = FMI_NAMESPACE + "Derivative/";
  public static String TYPE_FMI_DERIVATIVE = FMI_NAMESPACE + "Derivative";
  public static String FMI_DERIVATIVE_DOMAIN = "https://www.fmi-standard.org/derivative/rdf#";
  public static String PATH_FMI_DERIVATIVE = "Derivative";

  public static String FMI_INITIALUNKNOWN_PREFIX = "fmi_initialunknown";
  public static String FMI_INITIALUNKNOWN_NAMESPACE = FMI_NAMESPACE + "InitialUnknown/";
  public static String TYPE_FMI_INITIALUNKNOWN = FMI_NAMESPACE + "InitialUnknown";
  public static String FMI_INITIALUNKNOWN_DOMAIN = "https://www.fmi-standard.org/initialunknown/rdf#";
  public static String PATH_FMI_INITIALUNKNOWN = "InitialUnknown";

  public static String FMI_OUTPUT_PREFIX = "fmi_output";
  public static String FMI_OUTPUT_NAMESPACE = FMI_NAMESPACE + "Output/";
  public static String TYPE_FMI_OUTPUT = FMI_NAMESPACE + "Output";
  public static String FMI_OUTPUT_DOMAIN = "https://www.fmi-standard.org/output/rdf#";
  public static String PATH_FMI_OUTPUT = "Output";

}
