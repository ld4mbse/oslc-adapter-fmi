/*  
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
*  @author Axel Reichwein, Koneksys (axel.reichwein@koneksys.com)
*/

package adapter.clients;

import java.net.URI;

import javax.ws.rs.client.Client;
import javax.ws.rs.client.ClientBuilder;
import javax.ws.rs.core.Response;

import org.eclipse.lyo.oslc4j.core.model.Link;
import org.eclipse.lyo.oslc4j.core.model.QueryCapability;
import org.eclipse.lyo.oslc4j.core.model.Service;
import org.eclipse.lyo.oslc4j.core.model.ServiceProvider;
import org.eclipse.lyo.oslc4j.core.model.ServiceProviderCatalog;
import org.eclipse.lyo.oslc4j.provider.jena.JenaProvidersRegistry;
import org.glassfish.jersey.client.ClientConfig;

import com.modelon.oslc.adapter.fmi.resources.FMIDerivative;

public class PrintMainFMUData {

  public static void main(String[] args) {
    Thread thread = new Thread() {
      public void start() {

        String serviceProviderCatalogURI = "http://localhost:8686/oslc4jfmi/services/catalog";
        ClientConfig clientConfig = new ClientConfig();
        for (Class<?> providerClass : JenaProvidersRegistry.getProviders()) {
          clientConfig.register(providerClass);
        }
        Client rdfclient = ClientBuilder.newClient(clientConfig);
        Response response = rdfclient.target(serviceProviderCatalogURI).request("application/rdf+xml").get(); 
        ServiceProviderCatalog oslcServiceProviderCatalog = response.readEntity(ServiceProviderCatalog.class);
        
        for (ServiceProvider serviceProvider : oslcServiceProviderCatalog.getServiceProviders()) {
          System.out.println("");
          System.out.println("FMU " + serviceProvider.getAbout());

          // get FMU version
          String fmuID = serviceProvider.getAbout().toString()
              .replace("http://localhost:8686/oslc4jfmi/services/serviceProviders/", "");
          
          // http://localhost:8686/oslc4jfmi/services/serviceProviders/FMI1.0_CS_CoupledClutches
          Response fmuQueryCapabilityResponse = rdfclient
              .target("http://localhost:8686/oslc4jfmi/services/" + fmuID + "/FMU")
              .request("application/rdf+xml").get();
          com.modelon.oslc.adapter.fmi.resources.FMIFMU fmu = fmuQueryCapabilityResponse
              .readEntity(com.modelon.oslc.adapter.fmi.resources.FMIFMU.class);
          String fmuVersion = fmu.getFmiVersion();
          System.out.println(fmuVersion);

          for (Service service : serviceProvider.getServices()) {

            for (QueryCapability queryCapability : service.getQueryCapabilities()) {

//              if (fmuVersion.equals("1.0")) {

                // checking all ScalarVariables that have
                // causality input
                // get model variables, then scalar variables,
                // and check causality
                if (queryCapability.getQueryBase().toString().endsWith("/ModelVariables")) {

                  Response queryCapabilityResponse = rdfclient.target(queryCapability.getQueryBase())
                      .request("application/rdf+xml").get();
                  com.modelon.oslc.adapter.fmi.resources.FMIModelVariables modelVariables = queryCapabilityResponse
                      .readEntity(com.modelon.oslc.adapter.fmi.resources.FMIModelVariables.class);

                  if (modelVariables != null) {
                    Link[] scalarVariables = modelVariables.getScalarVariables();

                    for (Link scalarVariableLink : scalarVariables) {
                      URI scalarVariableURI = scalarVariableLink.getValue();
                      Response scalarVariableResponse = rdfclient.target(scalarVariableURI)
                          .request("application/rdf+xml").get();
                      com.modelon.oslc.adapter.fmi.resources.FMIScalarVariable scalarVariable = scalarVariableResponse
                          .readEntity(
                              com.modelon.oslc.adapter.fmi.resources.FMIScalarVariable.class);
                      if (scalarVariable != null) {
                        String causality = scalarVariable.getCausality();
                        if (causality.equals("input")) {
                          System.out.println("Input: " + scalarVariable.getName());
                        } else if (causality.equals("output")) {
                          System.out.println("Output: " + scalarVariable.getName());
                        }
                        if (causality.equals("parameter")) {
                          System.out.println("Parameter: " + scalarVariable.getName());
                        }
                      }

                    }
                  }
                }
//              } else if (fmuVersion.equals("2.0")) {

                // checking FMI 2.0 derivatives (states)
                if (queryCapability.getQueryBase().toString().endsWith("/ModelStructure")) {

                  Response queryCapabilityResponse = rdfclient.target(queryCapability.getQueryBase())
                      .request("application/rdf+xml").get();
                  com.modelon.oslc.adapter.fmi.resources.FMIModelStructure modelStructure = queryCapabilityResponse
                      .readEntity(com.modelon.oslc.adapter.fmi.resources.FMIModelStructure.class);

                  if (modelStructure != null) {
                    Link[] derivatives = modelStructure.getDerivatives();
                    for (Link derivativeLink : derivatives) {
                      URI derivativeURI = derivativeLink.getValue();
                      Response derivativeResponse = rdfclient.target(derivativeURI)
                          .request("application/rdf+xml").get();
                      com.modelon.oslc.adapter.fmi.resources.FMIDerivative derivative = derivativeResponse
                          .readEntity(FMIDerivative.class);
                      
                      if (derivative != null) {
                        String derivativeName = derivative.getName();
                        derivativeName = derivativeName.replace("der(", "");
                        derivativeName = derivativeName.replace(")", "");
  
                        System.out.println("Derivative: " + derivativeName);
                      }
                    }

                    Link[] outputs = modelStructure.getOutputs();
                    for (Link outputLink : outputs) {
                      URI outputURI = outputLink.getValue();
                      Response outputResponse = rdfclient.target(outputURI)
                          .request("application/rdf+xml").get();
                      com.modelon.oslc.adapter.fmi.resources.FMIOutput output = outputResponse
                          .readEntity(com.modelon.oslc.adapter.fmi.resources.FMIOutput.class);
                      String outputName = output.getName();
                      System.out.println("Output: " + outputName);
                    }
                    
//                    Link[] initialUnknowns = modelStructure.getInitialUnknowns();
//                    for (Link initialUnknownLink : initialUnknowns) {
//                      URI initialUnknownURI = initialUnknownLink.getValue();
//                      Response initialUnknownResponse = rdfclient.target(initialUnknownURI)
//                          .request("application/rdf+xml").get();
//                      com.modelon.oslc.adapter.fmi.resources.FMIInitialUnknown initialUnknown = initialUnknownResponse
//                          .readEntity(com.modelon.oslc.adapter.fmi.resources.FMIInitialUnknown.class);          
//                      String initialUnknownName = initialUnknown.getName();
//                      System.out.println("InitialUnknown: " + initialUnknownName);
//                    }

                  }

                }
//              }

            }
          }
        }
      }
    };
    thread.start();
    try {
      thread.join();

    } catch (InterruptedException e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }

  }

}
