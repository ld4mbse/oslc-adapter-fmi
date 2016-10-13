
<%--
/*
* fmiScalarVariable.jsp    1.1.0  2016-07-24
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
<%@ page import="com.modelon.oslc.adapter.fmi.resources.FMIScalarVariable" %>
<%@ page import="com.modelon.oslc.adapter.fmi.application.Domain2OSLCManager" %>

<%
  String fmuFileName = (String)request.getAttribute("fmuFileName");
  String identifier = (String)request.getAttribute("identifier");
  String pageString = (String)request.getAttribute("pageString");
  FMIScalarVariable fmiScalarVariable = Domain2OSLCManager.getFMIScalarVariableMapByIdentifier(fmuFileName, identifier);
  ServiceProvider provider = (ServiceProvider)request.getAttribute("provider");
  String serviceProvidersURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + 
    "/oslc4jfmi/services/catalog/";

  String servicesURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + "/oslc4jfmi/services/serviceProviders/" + fmuFileName;
  String scalarvariableURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + 
    "/oslc4jfmi/services/" + fmuFileName + "/ScalarVariable/" + identifier;
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
  <li class="active"><b>ScalarVariable Query Capability</b></li>
</ol></div>

<div class="row alert alert-success">
<h1 style="margin-top:0px;">ScalarVariable Query Capability</h1>
<p class="lead"><b><%= fmuFileName %></b></p>
This document: <a href="<%= scalarvariableURI %>"> <%= scalarvariableURI %></a>
</div>

<h4>ResourceLinks</h4> 
  <div class="container">
  <% if (fmiScalarVariable != null && fmiScalarVariable.getListingAliases() != null) { %>
  <div class="col-md-12"><h4>ListingAliases</h4>
    <div class="container">
<% for (Link link : fmiScalarVariable.getListingAliases()) { %>
        <div class="col-md-12"><b><%= Domain2OSLCManager.decodeURL(Domain2OSLCManager.getVariableName(link.getValue().toString())) %></b><br>
        <a href="<%= link.getValue().toString() %>"><%= link.getValue().toString() %></a></div>
      <% } %>
  </div></div>
<% } %>
  <% if (fmiScalarVariable != null && fmiScalarVariable.getListingDirectDependencies() != null) { %>
  <div class="col-md-12"><h4>ListingDirectDependencies</h4>
    <div class="container">
<% for (Link link : fmiScalarVariable.getListingDirectDependencies()) { %>
        <div class="col-md-12"><b><%= Domain2OSLCManager.decodeURL(Domain2OSLCManager.getVariableName(link.getValue().toString())) %></b><br>
        <a href="<%= link.getValue().toString() %>"><%= link.getValue().toString() %></a></div>
      <% } %>
  </div></div>
<% } %>
  <% if (fmiScalarVariable != null && fmiScalarVariable.getScalarVariableType() != null) { %>
    <div class="col-md-12"><h4>ScalarVariableType</h4>
    <a href="<%= fmiScalarVariable.getScalarVariableType().toString() %>"><%= fmiScalarVariable.getScalarVariableType().toString() %></a></div>
  <% } %>
  </div>
<h4>Attributes</h4> 
  <div class="container">
  <%  if (fmiScalarVariable != null) { %>
  <div class="col-md-12"><b>Identifier</b><br>
  <%= fmiScalarVariable.getIdentifier() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiScalarVariable != null) { %>
  <div class="col-md-12"><b>Index</b><br>
  <%= fmiScalarVariable.getIndex() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiScalarVariable != null) { %>
  <div class="col-md-12"><b>Name</b><br>
  <%= fmiScalarVariable.getName() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiScalarVariable != null) { %>
  <div class="col-md-12"><b>Description</b><br>
  <%= fmiScalarVariable.getDescription() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiScalarVariable != null) { %>
  <div class="col-md-12"><b>ValueReference</b><br>
  <%= fmiScalarVariable.getValueReference() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiScalarVariable != null) { %>
  <div class="col-md-12"><b>Variability</b><br>
  <%= fmiScalarVariable.getVariability() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiScalarVariable != null) { %>
  <div class="col-md-12"><b>Causality</b><br>
  <%= fmiScalarVariable.getCausality() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiScalarVariable != null) { %>
  <div class="col-md-12"><b>Initial</b><br>
  <%= fmiScalarVariable.getInitial() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiScalarVariable != null) { %>
  <div class="col-md-12"><b>IsAlias</b><br>
  <%= fmiScalarVariable.getIsAlias() %>&nbsp;</div><hr>
  <%  } %>
  <%  if (fmiScalarVariable != null) { %>
  <div class="col-md-12"><b>AliasBase</b><br>
  <%= fmiScalarVariable.getAliasBase() %>&nbsp;</div><hr>
  <%  } %>
  </div>
</body>
</html>
