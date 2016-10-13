/*
* package-info.java    1.1.0  2016-07-23
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

@OslcSchema ({
  @OslcNamespaceDefinition(prefix = OslcConstants.DCTERMS_NAMESPACE_PREFIX, namespaceURI = OslcConstants.DCTERMS_NAMESPACE),
  @OslcNamespaceDefinition(prefix = OslcConstants.OSLC_CORE_NAMESPACE_PREFIX, namespaceURI = OslcConstants.OSLC_CORE_NAMESPACE),
  @OslcNamespaceDefinition(prefix = OslcConstants.OSLC_DATA_NAMESPACE_PREFIX, namespaceURI = OslcConstants.OSLC_DATA_NAMESPACE),
  @OslcNamespaceDefinition(prefix = OslcConstants.RDF_NAMESPACE_PREFIX, namespaceURI = OslcConstants.RDF_NAMESPACE),
  @OslcNamespaceDefinition(prefix = OslcConstants.RDFS_NAMESPACE_PREFIX, namespaceURI = OslcConstants.RDFS_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_FMU_PREFIX, namespaceURI = Constants.FMI_FMU_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_MODELDESCRIPTION_PREFIX, namespaceURI = Constants.FMI_MODELDESCRIPTION_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_DEFAULTEXPERIMENT_PREFIX, namespaceURI = Constants.FMI_DEFAULTEXPERIMENT_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_MODELEXCHANGE_PREFIX, namespaceURI = Constants.FMI_MODELEXCHANGE_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_COSIMULATION_PREFIX, namespaceURI = Constants.FMI_COSIMULATION_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_SOURCEFILE_PREFIX, namespaceURI = Constants.FMI_SOURCEFILE_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_UNITDEFINITION_PREFIX, namespaceURI = Constants.FMI_UNITDEFINITION_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_BASEUNIT_PREFIX, namespaceURI = Constants.FMI_BASEUNIT_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_BASEUNITDEFINITION_PREFIX, namespaceURI = Constants.FMI_BASEUNITDEFINITION_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_VENDORANNOTATION_PREFIX, namespaceURI = Constants.FMI_VENDORANNOTATION_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_VENDORTOOL_PREFIX, namespaceURI = Constants.FMI_VENDORTOOL_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_ANNOTATION_PREFIX, namespaceURI = Constants.FMI_ANNOTATION_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_TYPEDEFINITION_PREFIX, namespaceURI = Constants.FMI_TYPEDEFINITION_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_TYPEDEF_PREFIX, namespaceURI = Constants.FMI_TYPEDEF_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_ENUMERATION_PREFIX, namespaceURI = Constants.FMI_ENUMERATION_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_MODELVARIABLES_PREFIX, namespaceURI = Constants.FMI_MODELVARIABLES_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_SCALARVARIABLE_PREFIX, namespaceURI = Constants.FMI_SCALARVARIABLE_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_SCALARVARIABLETYPE_PREFIX, namespaceURI = Constants.FMI_SCALARVARIABLETYPE_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_LISTINGALIAS_PREFIX, namespaceURI = Constants.FMI_LISTINGALIAS_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_LISTINGDIRECTDEPENDENCY_PREFIX, namespaceURI = Constants.FMI_LISTINGDIRECTDEPENDENCY_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_MODELSTRUCTURE_PREFIX, namespaceURI = Constants.FMI_MODELSTRUCTURE_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_DERIVATIVE_PREFIX, namespaceURI = Constants.FMI_DERIVATIVE_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_INITIALUNKNOWN_PREFIX, namespaceURI = Constants.FMI_INITIALUNKNOWN_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_OUTPUT_PREFIX, namespaceURI = Constants.FMI_OUTPUT_NAMESPACE),
  @OslcNamespaceDefinition(prefix = Constants.FMI_PREFIX, namespaceURI = Constants.FMI_NAMESPACE)
})

package com.modelon.oslc.adapter.fmi.resources;

import org.eclipse.lyo.oslc4j.core.annotation.OslcNamespaceDefinition;
import org.eclipse.lyo.oslc4j.core.annotation.OslcSchema;
import org.eclipse.lyo.oslc4j.core.model.OslcConstants;

import com.modelon.oslc.adapter.fmi.resources.Constants;
