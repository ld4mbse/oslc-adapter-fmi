/*
* TestFMIModelDescriptionBase.java    1.1.0  2016-07-23
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

package com.modelon.oslc.adapter.fmi.clients.tests;

import java.net.URI;
import java.util.HashSet;
import java.util.Set;

import javax.ws.rs.client.Client;
import javax.ws.rs.client.ClientBuilder;
import javax.ws.rs.core.Response;

import org.eclipse.lyo.oslc4j.client.OslcRestClient;
import org.eclipse.lyo.oslc4j.core.model.QueryCapability;
import org.eclipse.lyo.oslc4j.core.model.Service;
import org.eclipse.lyo.oslc4j.core.model.ServiceProvider;
import org.eclipse.lyo.oslc4j.core.model.ServiceProviderCatalog;
import org.eclipse.lyo.oslc4j.provider.jena.JenaProvidersRegistry;
import org.eclipse.lyo.oslc4j.provider.json4j.Json4JProvidersRegistry;
import org.glassfish.jersey.client.ClientConfig;

import com.modelon.oslc.adapter.fmi.resources.Constants;
import com.modelon.oslc.adapter.fmi.resources.FMIModelDescription;

import static org.junit.Assert.*;

public class TestFMIModelDescriptionBase {
  private static final Set<Class<?>> PROVIDERS = new HashSet<Class<?>>();
  static {
    PROVIDERS.addAll(JenaProvidersRegistry.getProviders());
    PROVIDERS.addAll(Json4JProvidersRegistry.getProviders());
  }

  protected TestFMIModelDescriptionBase() throws Exception {
    super();
  }

  private static void verifyFMIModelDescription(final String   mediaType, final FMIModelDescription theFMIModelDescription) {
    System.out.println("verifyFMIModelDescription");
    assertNotNull(theFMIModelDescription);
 
    final URI  aboutURI     = theFMIModelDescription.getAbout();
    final String identifier  = theFMIModelDescription.getIdentifier();
    final String fmuPath  = theFMIModelDescription.getFmuPath();
    final String tmpPath  = theFMIModelDescription.getTmpPath();
    final String fmiVersion  = theFMIModelDescription.getFmiVersion();
    final String modelName  = theFMIModelDescription.getModelName();
    final String modelIdentifier  = theFMIModelDescription.getModelIdentifier();
    final String guid  = theFMIModelDescription.getGuid();
    final String description  = theFMIModelDescription.getDescription();
    final String author  = theFMIModelDescription.getAuthor();
    final String version  = theFMIModelDescription.getVersion();
    final String copyright  = theFMIModelDescription.getCopyright();
    final String license  = theFMIModelDescription.getLicense();
    final String kind  = theFMIModelDescription.getKind();
    final String generationTool  = theFMIModelDescription.getGenerationTool();
    final String generationDateAndTime  = theFMIModelDescription.getGenerationDateAndTime();
    final String variableNamingConvention  = theFMIModelDescription.getVariableNamingConvention();
    final String numberOfContinuousStates  = theFMIModelDescription.getNumberOfContinuousStates();
    final String numberOfEventIndicators  = theFMIModelDescription.getNumberOfEventIndicators();

    System.out.println("ModelDescription Query Capability : " + aboutURI);
    System.out.println("    identifier = " + identifier);
    System.out.println("    fmuPath = " + fmuPath);
    System.out.println("    tmpPath = " + tmpPath);
    System.out.println("    fmiVersion = " + fmiVersion);
    System.out.println("    modelName = " + modelName);
    System.out.println("    modelIdentifier = " + modelIdentifier);
    System.out.println("    guid = " + guid);
    System.out.println("    description = " + description);
    System.out.println("    author = " + author);
    System.out.println("    version = " + version);
    System.out.println("    copyright = " + copyright);
    System.out.println("    license = " + license);
    System.out.println("    kind = " + kind);
    System.out.println("    generationTool = " + generationTool);
    System.out.println("    generationDateAndTime = " + generationDateAndTime);
    System.out.println("    variableNamingConvention = " + variableNamingConvention);
    System.out.println("    numberOfContinuousStates = " + numberOfContinuousStates);
    System.out.println("    numberOfEventIndicators = " + numberOfEventIndicators);
    
    assertTrue(aboutURI.toString().endsWith(identifier));
    assertNotNull(aboutURI);
    assertNotNull(identifier);
    assertNotNull(fmuPath);
    assertNotNull(tmpPath);
    assertNotNull(fmiVersion);
    assertNotNull(modelName);
    assertNotNull(modelIdentifier);
    assertNotNull(guid);
    assertNotNull(description);
    assertNotNull(author);
    assertNotNull(version);
    assertNotNull(copyright);
    assertNotNull(license);
    assertNotNull(kind);
    assertNotNull(generationTool);
    assertNotNull(generationDateAndTime);
    assertNotNull(variableNamingConvention);
    assertNotNull(numberOfContinuousStates);
    assertNotNull(numberOfEventIndicators);
  }

  protected void testRetrieves(final String mediaType) {
    String serviceProviderCatalogURI = "http://localhost:8686/oslc4jfmi/services/catalog";
    ClientConfig clientConfig = new ClientConfig();
    for (Class<?> providerClass : JenaProvidersRegistry.getProviders()) {
      clientConfig.register(providerClass);
    }
    Client rdfclient = ClientBuilder.newClient(clientConfig);
    Response response = null;
    try {
      response = rdfclient.target(serviceProviderCatalogURI).request("application/rdf+xml").get(); 
    } catch(Exception e) { 
      System.out.println("OSLC FMI ADAPTER is not running. Please start the adpater with sample FMU files before running this test case.");
      fail("OSLC FMI ADAPTER is not running. Please start the adpater with sample FMU files before running this test case.");
    } 

    ServiceProviderCatalog oslcServiceProviderCatalog = response.readEntity(ServiceProviderCatalog.class);

    if (oslcServiceProviderCatalog == null) {
      System.out.println("No Service Provider Catalog at " + serviceProviderCatalogURI);
      fail("No Service Provider Catalog at " + serviceProviderCatalogURI);
    }

    for (ServiceProvider serviceProvider : oslcServiceProviderCatalog.getServiceProviders()) {
      System.out.println("OSLC Service Provider: " + serviceProvider.getIdentifier());
      final Service[] services = serviceProvider.getServices();

      for (final Service service : services) {

        if (Constants.FMI_MODELDESCRIPTION_DOMAIN.equals(String.valueOf(service.getDomain()))) {

          final QueryCapability[] queryCapabilities = service.getQueryCapabilities();

          for (final QueryCapability queryCapability : queryCapabilities) {

            final OslcRestClient oslcRestClient = 
                new OslcRestClient(PROVIDERS,
                queryCapability.getQueryBase(),
                mediaType);

            final FMIModelDescription[] theFMIModelDescriptionArray = oslcRestClient.getOslcResources(FMIModelDescription[].class);
            
            
            if (theFMIModelDescriptionArray != null) {
              if (theFMIModelDescriptionArray.length < 1) {
                System.out.println("    No FMIModelDescription Resources");
              }
              for (final FMIModelDescription theFMIModelDescription : theFMIModelDescriptionArray) {
                verifyFMIModelDescription(mediaType, theFMIModelDescription);
              }
            } else { 
              System.out.println("    No FMIModelDescription Resources");
            } 
          }
        }
      }
    }
  }
}
