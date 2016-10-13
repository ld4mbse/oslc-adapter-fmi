/*
* FMIModelStructure.java    1.1.0  2016-07-23
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
@OslcName("ModelStructure")
@OslcResourceShape(title = "ModelStructure Resource Shape", describes = Constants.TYPE_FMI_MODELSTRUCTURE)
public class FMIModelStructure extends AbstractResource {

  public FMIModelStructure() throws URISyntaxException {
    super();
  }

  public FMIModelStructure(URI about) throws URISyntaxException {
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

  @OslcDescription("Description of ModelStructure::identifier TBD")
  @OslcName("identifier")
  @OslcOccurs(Occurs.ZeroOrOne)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelStructure_identifier")
  @OslcTitle("identifier")
  @OslcValueType(ValueType.XMLLiteral)
  public String getIdentifier() {
    return this.identifier;
  }


  // ********* Reference: derivative *********
  private List<FMIDerivative> fmiDerivativeList;
  private final Set<Link> derivatives = new HashSet<Link>();

  public void setDerivatives(final Link[] derivatives) {
    this.derivatives.clear();
    if (derivatives != null) {
      this.derivatives.addAll(Arrays.asList(derivatives));
    }
  }

  @OslcDescription("Description of ModelStructure::derivative TBD")
  @OslcName("derivative")
  @OslcOccurs(Occurs.ZeroOrMany)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelStructure_derivative")
  @OslcTitle("derivative")
  @OslcReadOnly(false)
  public Link[]  getDerivatives() {
  return this.derivatives.toArray(new Link[this.derivatives.size()]);
  }

  // ********* Reference: initialUnknown *********
  private List<FMIInitialUnknown> fmiInitialUnknownList;
  private final Set<Link> initialUnknowns = new HashSet<Link>();

  public void setInitialUnknowns(final Link[] initialUnknowns) {
    this.initialUnknowns.clear();
    if (initialUnknowns != null) {
      this.initialUnknowns.addAll(Arrays.asList(initialUnknowns));
    }
  }

  @OslcDescription("Description of ModelStructure::initialUnknown TBD")
  @OslcName("initialUnknown")
  @OslcOccurs(Occurs.ZeroOrMany)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelStructure_initialUnknown")
  @OslcTitle("initialUnknown")
  @OslcReadOnly(false)
  public Link[]  getInitialUnknowns() {
  return this.initialUnknowns.toArray(new Link[this.initialUnknowns.size()]);
  }

  // ********* Reference: output *********
  private List<FMIOutput> fmiOutputList;
  private final Set<Link> outputs = new HashSet<Link>();

  public void setOutputs(final Link[] outputs) {
    this.outputs.clear();
    if (outputs != null) {
      this.outputs.addAll(Arrays.asList(outputs));
    }
  }

  @OslcDescription("Description of ModelStructure::output TBD")
  @OslcName("output")
  @OslcOccurs(Occurs.ZeroOrMany)
  @OslcPropertyDefinition("http://localhost:8686/oslc4jfmi/services/rdfvocabulary#ModelStructure_output")
  @OslcTitle("output")
  @OslcReadOnly(false)
  public Link[]  getOutputs() {
  return this.outputs.toArray(new Link[this.outputs.size()]);
  }

}

