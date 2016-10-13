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

public class PrintFMUDerivatives {

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

          for (Service service : serviceProvider.getServices()) {

            for (QueryCapability queryCapability : service.getQueryCapabilities()) {

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
                    String derivativeName = derivative.getName();
                    derivativeName = derivativeName.replace("der(", "");
                    derivativeName = derivativeName.replace(")", "");

                    System.out.println("Derivative: " + derivativeName);
                  }
                } else {
                  System.out.println("No Derivatives");
                }
              }

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
