
<%--
/*
* fmiProvider.jsp    1.1.0  2016-07-22
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
<%@ page import="java.util.Map" %>
<%@ page import="java.net.URLDecoder" %>
<%@ page import="java.net.URLEncoder" %>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.ServiceProviderCatalog"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.ServiceProvider"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.Service"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.QueryCapability"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.Link"%>
<%@ page import="com.modelon.oslc.adapter.fmi.resources.FMIFMU" %>
<%@ page import="com.modelon.oslc.adapter.fmi.application.Domain2OSLCManager" %>

<%
String fmuFileName = (String)request.getAttribute("fmuFileName");
ServiceProvider provider = (ServiceProvider)request.getAttribute("provider");
Service [] services = provider.getServices();
String serviceProvidersURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + 
  "/oslc4jfmi/services/catalog";
FMIFMU fmiFMU = Domain2OSLCManager.getFMIFMUMapByIdentifier(fmuFileName, fmuFileName);
%>

<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>OSLC FMI ADAPTER 1.1.0</title>
    <link rel="shortcut icon" href="<%=request.getContextPath()%>/images/favicon.ico" />
    <link href="<%=request.getContextPath()%>/css/style.css" rel="stylesheet">
    <link href="<%=request.getContextPath()%>/css/bootstrap.min.css" rel="stylesheet">
  </head>
  <body class="container">

    <div class="row" style="z-index:100;position: fixed;top:0;">
      <ol class="breadcrumb">
        <li><a href="<%= serviceProvidersURI %>">&#171; Service Catalog</a></li>
      </ol>
    </div>

    <div class="row alert alert-success">
      <h1 style="margin-top:0px;">Service Provider</h1>
      <p class="lead">
        <%
          if (fmiFMU.getFmiVersion().equals("1.0")) {
            %>
              <span class="label label-primary">FMI 1.0</span>
            <%
          } else if (fmiFMU.getFmiVersion().equals("2.0")) {
            %>
              <span class="label label-success">FMI 2.0</span>
            <%
          } else {
            %>
              <span class="label label-danger">Unknown FMI version</span>
            <%
          }
          %>

          <%
          if (fmiFMU.getIsModelExchangeFMU().equals("true")) {
            %>
              <span class="label label-warning">ME</span>
            <%
          } else if (fmiFMU.getIsCoSimulationFMU().equals("true")) {
            %>
              <span class="label label-info">CS</span>
            <%
          } else {
            %>
              <span class="label label-danger">Unknown</span>
            <%
          }
          %>
          <b><%= provider.getTitle() %>.fmu</b>
      </p>
      <p>&nbsp;<a href="<%= provider.getAbout().toString()%>"> <span class="glyphicon glyphicon-globe" aria-hidden="true"></span> <%= provider.getAbout().toString()%></a></p>
    </div>
    <div class="row">
        <%
        if (services != null && services.length > 0) {
          for (Service service : services) {
            QueryCapability [] queryCapabilities = service.getQueryCapabilities();
            if (queryCapabilities != null && queryCapabilities.length > 0) {
              for(QueryCapability qc : queryCapabilities) {
              %>
               <div class="col-md-4"><h5><a href="<%= qc.getQueryBase().toString() %>"><%= qc.getTitle() %></a></h5></div>
              <%
              }
            }
          }
          
        }
        %>
    </div>
  </body>
</html>
