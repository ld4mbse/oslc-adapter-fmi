/*
* TestFMIListingDirectDependencyBase.java    1.1.0  2016-07-23
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
import com.modelon.oslc.adapter.fmi.resources.FMIListingDirectDependency;

import static org.junit.Assert.*;

public class TestFMIListingDirectDependencyBase {
  private static final Set<Class<?>> PROVIDERS = new HashSet<Class<?>>();
  static {
    PROVIDERS.addAll(JenaProvidersRegistry.getProviders());
    PROVIDERS.addAll(Json4JProvidersRegistry.getProviders());
  }

  protected TestFMIListingDirectDependencyBase() throws Exception {
    super();
  }

  private static void verifyFMIListingDirectDependency(final String   mediaType, final FMIListingDirectDependency theFMIListingDirectDependency) {
    System.out.println("verifyFMIListingDirectDependency");
    assertNotNull(theFMIListingDirectDependency);
 
    final URI  aboutURI     = theFMIListingDirectDependency.getAbout();
    final String identifier  = theFMIListingDirectDependency.getIdentifier();
    final String name  = theFMIListingDirectDependency.getName();

    System.out.println("ListingDirectDependency Query Capability : " + aboutURI);
    System.out.println("    identifier = " + identifier);
    System.out.println("    name = " + name);
    
    assertTrue(aboutURI.toString().endsWith(identifier));
    assertNotNull(aboutURI);
    assertNotNull(identifier);
    assertNotNull(name);
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

        if (Constants.FMI_LISTINGDIRECTDEPENDENCY_DOMAIN.equals(String.valueOf(service.getDomain()))) {

          final QueryCapability[] queryCapabilities = service.getQueryCapabilities();

          for (final QueryCapability queryCapability : queryCapabilities) {

            final OslcRestClient oslcRestClient = 
                new OslcRestClient(PROVIDERS,
                queryCapability.getQueryBase(),
                mediaType);

            final FMIListingDirectDependency[] theFMIListingDirectDependencyArray = oslcRestClient.getOslcResources(FMIListingDirectDependency[].class);
            
            
            if (theFMIListingDirectDependencyArray != null) {
              if (theFMIListingDirectDependencyArray.length < 1) {
                System.out.println("    No FMIListingDirectDependency Resources");
              }
              for (final FMIListingDirectDependency theFMIListingDirectDependency : theFMIListingDirectDependencyArray) {
                verifyFMIListingDirectDependency(mediaType, theFMIListingDirectDependency);
              }
            } else { 
              System.out.println("    No FMIListingDirectDependency Resources");
            } 
          }
        }
      }
    }
  }
}
