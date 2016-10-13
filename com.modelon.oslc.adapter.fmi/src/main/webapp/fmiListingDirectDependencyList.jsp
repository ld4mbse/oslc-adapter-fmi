
<%--
/*
* fmiListingDirectDependencyList.jsp    1.1.0  2016-07-24
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
--%>

<%@ page contentType="text/html" language="java" pageEncoding="UTF-8"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.ServiceProviderCatalog"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.ServiceProvider"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.Link"%>
<%@ page import="java.util.List" %>
<%@ page import="java.util.ArrayList" %>
<%@ page import="java.util.Map" %>
<%@ page import="java.net.URLDecoder" %>
<%@ page import="java.net.URLEncoder" %>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.ServiceProviderCatalog"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.ServiceProvider"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.Link"%>
<%@ page import="com.modelon.oslc.adapter.fmi.resources.FMIListingDirectDependency" %>
<%@ page import="com.modelon.oslc.adapter.fmi.application.Domain2OSLCManager" %>

<%
  String fmuFileName = (String)request.getAttribute("fmuFileName");
  String pageString = (String)request.getAttribute("pageString");
  String identifier = (String)request.getAttribute("identifier");
  ServiceProvider provider = (ServiceProvider)request.getAttribute("provider");
  String serviceProvidersURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + 
    "/oslc4jfmi/services/catalog/";

  String servicesURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + "/oslc4jfmi/services/serviceProviders/" + fmuFileName;
  List<FMIListingDirectDependency> fmiListingDirectDependencyList = null;
  if (identifier != null) {
    List<FMIListingDirectDependency> obj = new ArrayList<FMIListingDirectDependency>();
    obj.add(Domain2OSLCManager.getFMIListingDirectDependencyMapByIdentifier(fmuFileName, identifier));
    fmiListingDirectDependencyList = obj;
  } else { 
    fmiListingDirectDependencyList = Domain2OSLCManager.getFMIListingDirectDependencyMap(fmuFileName);
  }
  String listingdirectdependencyURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + 
    "/oslc4jfmi/services/Resource/" + fmuFileName + "/ListingDirectDependency";
%>

<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>OSLC FMIADAPTER 1.1.0</title>
  <link rel="shortcut icon" href="<%=request.getContextPath()%>/images/favicon.ico" />
  <link href="<%=request.getContextPath()%>/css/style.css" rel="stylesheet">
  <link href="<%=request.getContextPath()%>/css/bootstrap.min.css" rel="stylesheet">
</head>
<body class="container">

<div class="row" style="z-index:100; position: fixed;top:0;"><ol class="breadcrumb">
  <li><a href="<%= serviceProvidersURI %>">Service Catalog</a></li>
  <li class="active"><b><%= fmuFileName %></b></li>
  <li><a href="<%= servicesURI %>">OSLC Services</a></li>
  <li class="active"><b>ListingDirectDependency Query Capability</b></li>
</ol></div>

<div class="row alert alert-success">
  <h1 style="margin-top:0px;">ListingDirectDependency Query Capability</h1>
  <p class="lead"><b><%= fmuFileName %></b></p>
  This document: <a href="<%= listingdirectdependencyURI %>"> <%= listingdirectdependencyURI %></a>
</div>

<%  if (fmiListingDirectDependencyList != null && fmiListingDirectDependencyList.size() > 0) { %>
      <% for (FMIListingDirectDependency fmiListingDirectDependency : fmiListingDirectDependencyList) { %>
        <div class="col-md-12"><h4>ListingDirectDependency : <%= Domain2OSLCManager.decodeURL(Domain2OSLCManager.getVariableName(fmiListingDirectDependency.getAbout().toString())) %></h4><a href="<%= fmiListingDirectDependency.getAbout().toString() %>"><%= fmiListingDirectDependency.getAbout().toString() %></a></div>
      <% } %> 
<%  } else { %> 
      <b>No resources</b>
<%  } %>

</body>
</html>
