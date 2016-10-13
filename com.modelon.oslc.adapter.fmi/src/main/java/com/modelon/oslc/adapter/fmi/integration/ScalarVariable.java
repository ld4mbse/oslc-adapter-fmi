/*
* ScalarVariable.java    1.1.0  2016-07-22
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

public class ScalarVariable {
  public String name;
  public String description;
  public String valueReference;
  public String variability;
  public String causality;
  public String initial;
  public String isAlias;
  public String aliasBase;
  public List<ListingAlias> listingAliases;
  public List<ListingDirectDependency> listingDirectDependencies;
  public ScalarVariableType type;
}
