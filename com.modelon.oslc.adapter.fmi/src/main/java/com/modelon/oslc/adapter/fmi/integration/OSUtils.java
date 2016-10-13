/*
* OSUtils.java    1.1.0  2016-07-22
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

package com.modelon.oslc.adapter.fmi.integration;

import java.util.Locale;

public class OSUtils {

  public enum OSType {
    Windows, MacOS, Linux, Other
  };

  protected static OSType detectedOS;
  protected static String detectedCPU;

  public static OSType getOperatingSystemType() throws Exception {
    if (detectedOS == null) {
      String OS = System.getProperty("os.name", "generic").toLowerCase(Locale.ENGLISH);
      System.out.println("Detected OS = " + OS);

      if ((OS.indexOf("mac") >= 0) || (OS.indexOf("darwin") >= 0)) {
        detectedOS = OSType.MacOS;
      } else if (OS.indexOf("win") >= 0) {
        detectedOS = OSType.Windows;
      } else if (OS.indexOf("nux") >= 0) {
        detectedOS = OSType.Linux;
      } else {
        detectedOS = OSType.Other;
      }

    }
    return detectedOS;
  }

  public static String getCPU() throws Exception {
    if (detectedCPU == null) {

      String OSArch = System.getProperty("os.arch").toLowerCase(Locale.ENGLISH);
      System.out.println("Detected OSArch = " + OSArch);

      if (OSArch.indexOf("64") >= 0) {
        detectedCPU = "64";
      } else if (OSArch.indexOf("32") >= 0 || OSArch.indexOf("x86") >= 0) {
        detectedCPU = "32";
      } else {
        throw new Exception("CPU bit cannot be detected");
      }
    }
    return detectedCPU;
  }
}