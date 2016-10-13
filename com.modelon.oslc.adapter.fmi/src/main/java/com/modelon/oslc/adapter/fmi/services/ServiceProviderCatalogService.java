/*
* ServiceProviderCatalogService.java    1.1.0  2016-07-23
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

package com.modelon.oslc.adapter.fmi.services;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

import javax.servlet.http.HttpServletResponse;
import javax.servlet.RequestDispatcher;
import javax.servlet.http.HttpServletRequest;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.WebApplicationException;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response.Status;
import javax.ws.rs.core.UriInfo;
import javax.ws.rs.core.Response;

import org.eclipse.lyo.oslc4j.core.annotation.OslcQueryCapability;
import org.eclipse.lyo.oslc4j.core.annotation.OslcService;
import org.eclipse.lyo.oslc4j.core.model.OslcConstants;
import org.eclipse.lyo.oslc4j.core.model.OslcMediaType;
import org.eclipse.lyo.oslc4j.core.model.ServiceProviderCatalog;

import com.modelon.oslc.adapter.fmi.application.Domain2OSLCManager;
import com.modelon.oslc.adapter.fmi.resources.Constants;

@OslcService(OslcConstants.OSLC_CORE_DOMAIN)
@Path("catalog")
public class ServiceProviderCatalogService {
  @Context private HttpServletRequest httpServletRequest;
  @Context private HttpServletResponse httpServletResponse;
  @Context private UriInfo uriInfo;
  @OslcQueryCapability
  (
    title = "Service Provider Catalog Query Capability",
    label = "Service Provider Catalog Query",
    resourceShape = OslcConstants.PATH_RESOURCE_SHAPES + "/" + OslcConstants.PATH_SERVICE_PROVIDER_CATALOG,
    resourceTypes = {OslcConstants.TYPE_SERVICE_PROVIDER_CATALOG},
    usages = {OslcConstants.OSLC_USAGE_DEFAULT}
  )
  @GET
  @Produces({OslcMediaType.APPLICATION_RDF_XML, OslcMediaType.APPLICATION_XML, OslcMediaType.APPLICATION_JSON})
  public Response getServiceProviderCatalogs() throws IOException, URISyntaxException {
    String forwardUri = uriInfo.getAbsolutePath() + "/singleton";
    httpServletResponse.sendRedirect(forwardUri);
    return Response.seeOther(new URI(forwardUri)).build();
  }

  @GET
  @Path("{serviceProviderCatalogId}")
  @Produces({OslcMediaType.APPLICATION_RDF_XML, OslcMediaType.APPLICATION_XML, OslcMediaType.APPLICATION_JSON})
  public ServiceProviderCatalog getServiceProviderCatalog() {
    try { 
      ServiceProviderCatalog catalog = Domain2OSLCManager.getServiceProviderCatalog() ;
      if (catalog != null) {
        httpServletResponse.addHeader(Constants.HDR_OSLC_VERSION,"2.0");
        return catalog;
      }
      throw new WebApplicationException(Status.NOT_FOUND);
    } catch (Exception e) {
      e.printStackTrace();
      throw new WebApplicationException(Status.INTERNAL_SERVER_ERROR);
    }
  }

  @GET
  @Produces(MediaType.TEXT_HTML)
  public void getHtmlServiceProviderCatalogs() throws WebApplicationException {
    this.html();  }

  @GET
  @Path("{serviceProviderCatalogId}")
  @Produces(MediaType.TEXT_HTML)
  public void getHtmlServiceProvider(@PathParam("fmuFileName") final String fmuFileName) {
    this.html();  }

  private void html() {
    try {
      RequestDispatcher rd = httpServletRequest.getRequestDispatcher("/fmiProviderList.jsp");
      rd.forward(httpServletRequest, httpServletResponse);
    } catch (Exception e) {
      e.printStackTrace();
      throw new WebApplicationException(e);
    }
  }
}
