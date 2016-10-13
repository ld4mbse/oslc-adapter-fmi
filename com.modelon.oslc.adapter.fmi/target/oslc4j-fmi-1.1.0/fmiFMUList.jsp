
<%--
/*
* fmiFMUList.jsp    1.1.0  2016-07-24
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
<%@ page import="com.modelon.oslc.adapter.fmi.resources.FMIFMU" %>
<%@ page import="com.modelon.oslc.adapter.fmi.application.Domain2OSLCManager" %>

<%
  String fmuFileName = (String)request.getAttribute("fmuFileName");
  String pageString = (String)request.getAttribute("pageString");
  String identifier = (String)request.getAttribute("identifier");
  ServiceProvider provider = (ServiceProvider)request.getAttribute("provider");
  String serviceProvidersURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + 
    "/oslc4jfmi/services/catalog/";

  String servicesURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + "/oslc4jfmi/services/serviceProviders/" + fmuFileName;
  List<FMIFMU> fmiFMUList = null;
  if (identifier != null) {
    List<FMIFMU> obj = new ArrayList<FMIFMU>();
    obj.add(Domain2OSLCManager.getFMIFMUMapByIdentifier(fmuFileName, identifier));
    fmiFMUList = obj;
  } else { 
    fmiFMUList = Domain2OSLCManager.getFMIFMUMap(fmuFileName);
  }
  String fmuURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + 
    "/oslc4jfmi/services/Resource/" + fmuFileName + "/FMU";
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
  <li class="active"><b>FMU Query Capability</b></li>
</ol></div>

<div class="row alert alert-success">
  <h1 style="margin-top:0px;">FMU Query Capability</h1>
  <p class="lead"><b><%= fmuFileName %></b></p>
  This document: <a href="<%= fmuURI %>"> <%= fmuURI %></a>
</div>

<%  if (fmiFMUList != null && fmiFMUList.size() > 0) { %>
      <% for (FMIFMU fmiFMU : fmiFMUList) { %>
        <div class="col-md-12"><h4>FMU : <%= Domain2OSLCManager.decodeURL(Domain2OSLCManager.getVariableName(fmiFMU.getAbout().toString())) %></h4><a href="<%= fmiFMU.getAbout().toString() %>"><%= fmiFMU.getAbout().toString() %></a></div>
      <% } %> 
<%  } else { %> 
      <b>No resources</b>
<%  } %>

</body>
</html>
