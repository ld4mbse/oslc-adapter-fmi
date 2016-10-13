
<%--
/*
* fmiModelDescription.jsp    1.1.0  2016-07-24
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
<%@ page import="com.modelon.oslc.adapter.fmi.resources.FMIModelDescription" %>
<%@ page import="com.modelon.oslc.adapter.fmi.application.Domain2OSLCManager" %>

<%
  String fmuFileName = (String)request.getAttribute("fmuFileName");
  String identifier = (String)request.getAttribute("identifier");
  String pageString = (String)request.getAttribute("pageString");
  FMIModelDescription fmiModelDescription = Domain2OSLCManager.getFMIModelDescriptionMapByIdentifier(fmuFileName, identifier);
  ServiceProvider provider = (ServiceProvider)request.getAttribute("provider");
  String serviceProvidersURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + 
    "/oslc4jfmi/services/catalog/";

  String servicesURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + "/oslc4jfmi/services/serviceProviders/" + fmuFileName;
  String modeldescriptionURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + 
    "/oslc4jfmi/services/" + fmuFileName + "/ModelDescription/" + identifier;
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

<div class="row" style="z-index:100;position: fixed;top:0;"><ol class="breadcrumb">
  <li><a href="<%= serviceProvidersURI %>">Service Catalog</a></li>
  <li class="active"><b><%= fmuFileName %></b></li>
  <li><a href="<%= servicesURI %>">OSLC Services</a></li>
  <li class="active"><b>ModelDescription Query Capability</b></li>
</ol></div>

<div class="row alert alert-success">
<h1 style="margin-top:0px;">ModelDescription Query Capability</h1>
<p class="lead"><b><%= fmuFileName %></b></p>
This document: <a href="<%= modeldescriptionURI %>"> <%= modeldescriptionURI %></a>
</div>

<h4>ResourceLinks</h4> 
  <div class="container">
  <% if (fmiModelDescription != null && fmiModelDescription.getDefaultExperiment() != null) { %>
    <div class="col-md-12"><h4>DefaultExperiment</h4>
    <a href="<%= fmiModelDescription.getDefaultExperiment().toString() %>"><%= fmiModelDescription.getDefaultExperiment().toString() %></a></div>
  <% } %>
  <% if (fmiModelDescription != null && fmiModelDescription.getModelStructure() != null) { %>
    <div class="col-md-12"><h4>ModelStructure</h4>
    <a href="<%= fmiModelDescription.getModelStructure().toString() %>"><%= fmiModelDescription.getModelStructure().toString() %></a></div>
  <% } %>
  <% if (fmiModelDescription != null && fmiModelDescription.getCoSimulation() != null) { %>
    <div class="col-md-12"><h4>CoSimulation</h4>
    <a href="<%= fmiModelDescription.getCoSimulation().toString() %>"><%= fmiModelDescription.getCoSimulation().toString() %></a></div>
  <% } %>
  <% if (fmiModelDescription != null && fmiModelDescription.getModelExchange() != null) { %>
    <div class="col-md-12"><h4>ModelExchange</h4>
    <a href="<%= fmiModelDescription.getModelExchange().toString() %>"><%= fmiModelDescription.getModelExchange().toString() %></a></div>
  <% } %>
  <% if (fmiModelDescription != null && fmiModelDescription.getModelVariables() != null) { %>
    <div class="col-md-12"><h4>ModelVariables</h4>
    <a href="<%= fmiModelDescription.getModelVariables().toString() %>"><%= fmiModelDescription.getModelVariables().toString() %></a></div>
  <% } %>
  <% if (fmiModelDescription != null && fmiModelDescription.getUnitDefinitions() != null) { %>
  <div class="col-md-12"><h4>UnitDefinitions</h4>
    <div class="container">
<% for (Link link : fmiModelDescription.getUnitDefinitions()) { %>
        <div class="col-md-12"><b><%= Domain2OSLCManager.decodeURL(Domain2OSLCManager.getVariableName(link.getValue().toString())) %></b><br>
        <a href="<%= link.getValue().toString() %>"><%= link.getValue().toString() %></a></div>
      <% } %>
  </div></div>
<% } %>
  <% if (fmiModelDescription != null && fmiModelDescription.getVendorAnnotations() != null) { %>
  <div class="col-md-12"><h4>VendorAnnotations</h4>
    <div class="container">
<% for (Link link : fmiModelDescription.getVendorAnnotations()) { %>
        <div class="col-md-12"><b><%= Domain2OSLCManager.decodeURL(Domain2OSLCManager.getVariableName(link.getValue().toString())) %></b><br>
        <a href="<%= link.getValue().toString() %>"><%= link.getValue().toString() %></a></div>
      <% } %>
  </div></div>
<% } %>
  <% if (fmiModelDescription != null && fmiModelDescription.getTypeDefinitions() != null) { %>
  <div class="col-md-12"><h4>TypeDefinitions</h4>
    <div class="container">
<% for (Link link : fmiModelDescription.getTypeDefinitions()) { %>
        <div class="col-md-12"><b><%= Domain2OSLCManager.decodeURL(Domain2OSLCManager.getVariableName(link.getValue().toString())) %></b><br>
        <a href="<%= link.getValue().toString() %>"><%= link.getValue().toString() %></a></div>
      <% } %>
  </div></div>
<% } %>
  </div>
<h4>Attributes</h4> 
  <div class="container">
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>Identifier</b><br>
  <%= fmiModelDescription.getIdentifier() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>FmuPath</b><br>
  <%= fmiModelDescription.getFmuPath() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>TmpPath</b><br>
  <%= fmiModelDescription.getTmpPath() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>FmiVersion</b><br>
  <%= fmiModelDescription.getFmiVersion() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>ModelName</b><br>
  <%= fmiModelDescription.getModelName() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>ModelIdentifier</b><br>
  <%= fmiModelDescription.getModelIdentifier() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>Guid</b><br>
  <%= fmiModelDescription.getGuid() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>Description</b><br>
  <%= fmiModelDescription.getDescription() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>Author</b><br>
  <%= fmiModelDescription.getAuthor() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>Version</b><br>
  <%= fmiModelDescription.getVersion() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>Copyright</b><br>
  <%= fmiModelDescription.getCopyright() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>License</b><br>
  <%= fmiModelDescription.getLicense() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>Kind</b><br>
  <%= fmiModelDescription.getKind() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>GenerationTool</b><br>
  <%= fmiModelDescription.getGenerationTool() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>GenerationDateAndTime</b><br>
  <%= fmiModelDescription.getGenerationDateAndTime() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>VariableNamingConvention</b><br>
  <%= fmiModelDescription.getVariableNamingConvention() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>NumberOfContinuousStates</b><br>
  <%= fmiModelDescription.getNumberOfContinuousStates() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiModelDescription != null) { %>
  <div class="col-md-12"><b>NumberOfEventIndicators</b><br>
  <%= fmiModelDescription.getNumberOfEventIndicators() %>&nbsp;</div><hr>
  <%  } %>
  </div>
</body>
</html>
