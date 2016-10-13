
<%--
/*
* fmiProviderList.jsp    1.1.0  2016-07-22
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
<%@ page import="java.util.List" %>
<%@ page import="java.util.Map" %>
<%@ page import="java.net.URLDecoder" %>
<%@ page import="java.net.URLEncoder" %>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.ServiceProviderCatalog"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.ServiceProvider"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.Link"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.ServiceProviderCatalog"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.ServiceProvider"%>
<%@ page import="org.eclipse.lyo.oslc4j.core.model.Link"%>
<%@ page import="com.modelon.oslc.adapter.fmi.application.Domain2OSLCManager" %>
<%@ page import="com.modelon.oslc.adapter.fmi.resources.FMIFMU" %>

<%
ServiceProviderCatalog catalog = Domain2OSLCManager.getServiceProviderCatalog();
String serviceProviderCatalogURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + 
  "/oslc4jfmi/services/catalog";
String serviceProvidersURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + 
  "/oslc4jfmi/services/serviceProviders";
String rdfVocabularyURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + 
  "/oslc4jfmi/services/rdfvocabulary";
String resourceShapesURI = request.getScheme() + "://" + request.getServerName() + ":" + request.getServerPort() + 
  "/oslc4jfmi/services/resourceShapes";
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

    <div class="col-md-12 media alert alert-success">
      <h1 style="margin-top:0px;">Service Provider Catalog</h1>
      <p>
      <a href="<%= serviceProviderCatalogURI %>"> <span class="glyphicon glyphicon-globe" aria-hidden="true"></span> <%= serviceProviderCatalogURI %></a>
      <br>Adapter Publisher: <a href="#" target="_blank"><%= catalog.getPublisher().getTitle() %></a>
      <br>Adapter Identity: <%= catalog.getPublisher().getIdentifier() %>
      </p>
    </div>
    
    <div class="col-md-12 alert alert-success">
      <h1 style="margin-top:0px;">Service Providers</h1>
      <p>
      <a href="<%= serviceProvidersURI %>"> <span class="glyphicon glyphicon-globe" aria-hidden="true"></span> <%= serviceProvidersURI %></a>
      </p>
    </div>

    <div class="col-md-12 row">
    <% 
      for(FMIFMU theFMIFMU : Domain2OSLCManager.getTopLevelConcept()) {
        String serviceProviderIdentifier = theFMIFMU.getIdentifier();
        ServiceProvider serviceProvider = Domain2OSLCManager.getServiceProvider(serviceProviderIdentifier);
    %>
        <div class="col-md-12">
          
          <h4>
            <%
            if (theFMIFMU.getFmiVersion().equals("1.0")) {
              %>
                <span class="label label-primary">FMI 1.0</span>
              <%
            } else if (theFMIFMU.getFmiVersion().equals("2.0")) {
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
            if (theFMIFMU.getIsModelExchangeFMU().equals("true")) {
              %>
                <span class="label label-warning">ME</span>
              <%
            } else if (theFMIFMU.getIsCoSimulationFMU().equals("true")) {
              %>
                <span class="label label-info">CS</span>
              <%
            } else {
              %>
                <span class="label label-danger">Unknown</span>
              <%
            }
            %>
            <a href="<%= serviceProvider.getAbout().toString() %>">
              <%= serviceProviderIdentifier %>.fmu
            </a>
          </h4>
        </div>
    <%
     }
    %>
    </div>

  </body>
</html>
