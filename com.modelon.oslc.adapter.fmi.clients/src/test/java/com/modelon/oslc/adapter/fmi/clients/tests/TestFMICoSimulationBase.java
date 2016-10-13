/*
* TestFMICoSimulationBase.java    1.1.0  2016-07-23
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
import com.modelon.oslc.adapter.fmi.resources.FMICoSimulation;

import static org.junit.Assert.*;

public class TestFMICoSimulationBase {
  private static final Set<Class<?>> PROVIDERS = new HashSet<Class<?>>();
  static {
    PROVIDERS.addAll(JenaProvidersRegistry.getProviders());
    PROVIDERS.addAll(Json4JProvidersRegistry.getProviders());
  }

  protected TestFMICoSimulationBase() throws Exception {
    super();
  }

  private static void verifyFMICoSimulation(final String   mediaType, final FMICoSimulation theFMICoSimulation) {
    System.out.println("verifyFMICoSimulation");
    assertNotNull(theFMICoSimulation);
 
    final URI  aboutURI     = theFMICoSimulation.getAbout();
    final String identifier  = theFMICoSimulation.getIdentifier();
    final String modelIdentifier  = theFMICoSimulation.getModelIdentifier();
    final String needsExecutionTool  = theFMICoSimulation.getNeedsExecutionTool();
    final String canGetAndSetFMUstate  = theFMICoSimulation.getCanGetAndSetFMUstate();
    final String canSerializeFMUstate  = theFMICoSimulation.getCanSerializeFMUstate();
    final String providesDirectionalDerivatives  = theFMICoSimulation.getProvidesDirectionalDerivatives();
    final String canHandleVariableCommunicationStepSize  = theFMICoSimulation.getCanHandleVariableCommunicationStepSize();
    final String canHandleEvents  = theFMICoSimulation.getCanHandleEvents();
    final String canRejectSteps  = theFMICoSimulation.getCanRejectSteps();
    final String canInterpolateInputs  = theFMICoSimulation.getCanInterpolateInputs();
    final String maxOutputDerivativeOrder  = theFMICoSimulation.getMaxOutputDerivativeOrder();
    final String canRunAsynchronuously  = theFMICoSimulation.getCanRunAsynchronuously();
    final String canSignalEvents  = theFMICoSimulation.getCanSignalEvents();
    final String canBeInstantiatedOnlyOncePerProcess  = theFMICoSimulation.getCanBeInstantiatedOnlyOncePerProcess();
    final String canNotUseMemoryManagementFunctions  = theFMICoSimulation.getCanNotUseMemoryManagementFunctions();

    System.out.println("CoSimulation Query Capability : " + aboutURI);
    System.out.println("    identifier = " + identifier);
    System.out.println("    modelIdentifier = " + modelIdentifier);
    System.out.println("    needsExecutionTool = " + needsExecutionTool);
    System.out.println("    canGetAndSetFMUstate = " + canGetAndSetFMUstate);
    System.out.println("    canSerializeFMUstate = " + canSerializeFMUstate);
    System.out.println("    providesDirectionalDerivatives = " + providesDirectionalDerivatives);
    System.out.println("    canHandleVariableCommunicationStepSize = " + canHandleVariableCommunicationStepSize);
    System.out.println("    canHandleEvents = " + canHandleEvents);
    System.out.println("    canRejectSteps = " + canRejectSteps);
    System.out.println("    canInterpolateInputs = " + canInterpolateInputs);
    System.out.println("    maxOutputDerivativeOrder = " + maxOutputDerivativeOrder);
    System.out.println("    canRunAsynchronuously = " + canRunAsynchronuously);
    System.out.println("    canSignalEvents = " + canSignalEvents);
    System.out.println("    canBeInstantiatedOnlyOncePerProcess = " + canBeInstantiatedOnlyOncePerProcess);
    System.out.println("    canNotUseMemoryManagementFunctions = " + canNotUseMemoryManagementFunctions);
    
    assertTrue(aboutURI.toString().endsWith(identifier));
    assertNotNull(aboutURI);
    assertNotNull(identifier);
    assertNotNull(modelIdentifier);
    assertNotNull(needsExecutionTool);
    assertNotNull(canGetAndSetFMUstate);
    assertNotNull(canSerializeFMUstate);
    assertNotNull(providesDirectionalDerivatives);
    assertNotNull(canHandleVariableCommunicationStepSize);
    assertNotNull(canHandleEvents);
    assertNotNull(canRejectSteps);
    assertNotNull(canInterpolateInputs);
    assertNotNull(maxOutputDerivativeOrder);
    assertNotNull(canRunAsynchronuously);
    assertNotNull(canSignalEvents);
    assertNotNull(canBeInstantiatedOnlyOncePerProcess);
    assertNotNull(canNotUseMemoryManagementFunctions);
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

        if (Constants.FMI_COSIMULATION_DOMAIN.equals(String.valueOf(service.getDomain()))) {

          final QueryCapability[] queryCapabilities = service.getQueryCapabilities();

          for (final QueryCapability queryCapability : queryCapabilities) {

            final OslcRestClient oslcRestClient = 
                new OslcRestClient(PROVIDERS,
                queryCapability.getQueryBase(),
                mediaType);

            final FMICoSimulation[] theFMICoSimulationArray = oslcRestClient.getOslcResources(FMICoSimulation[].class);
            
            
            if (theFMICoSimulationArray != null) {
              if (theFMICoSimulationArray.length < 1) {
                System.out.println("    No FMICoSimulation Resources");
              }
              for (final FMICoSimulation theFMICoSimulation : theFMICoSimulationArray) {
                verifyFMICoSimulation(mediaType, theFMICoSimulation);
              }
            } else { 
              System.out.println("    No FMICoSimulation Resources");
            } 
          }
        }
      }
    }
  }
}
