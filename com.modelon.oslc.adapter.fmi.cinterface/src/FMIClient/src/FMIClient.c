
/*********************************************************************************************
* Copyright (c) 2016 Modelon AB   http://www.modelon.com
*
*  This program is free software: you can redistribute it and/or modify
*  it under the terms of the BSD style license.
*
*  This program is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  
*
*  FILENAME : FMIClient.c
*
*  DESCRIPTION: OSLC FMI Adapter's C interface. This CLI will be executed by 
*   Java for reading FMU's modelDescription.xml. It supports FMI 1.0 and 2.0
*   CS/ME. This CLI provides a unified JSON as output that contains information for 
*   all kind of FMUs. The user can use this CLI to read a FMU file and get JSON 
*   in return.
* 
* AUTHOR : Vorachet Jaroensawas, Koneksys (vorachet.jaroensawas@koneksys.com) 
*
* VERSION    DATE
* 1.1.0      22July2016
*******************************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>

#include <fmilib.h>

#define TRUE 1
#define FALSE 0

int annotation_start_handle(void *context, const char *parentName, void *parent, const char *elm, const char **attr) {
  return 0;
}

int annotation_data_handle(void* context, const char *s, int len) {
  return 0;
}

int annotation_end_handle(void *context, const char *elm) {
  return 0;
}

fmi2_xml_callbacks_t annotation_callbacks = {
  annotation_start_handle,
  annotation_data_handle,
  annotation_end_handle, NULL};

void readBaseType(fmi2_import_variable_typedef_t* vt) {
  switch(fmi2_import_get_base_type(vt)) {
    case fmi2_base_type_real: {

      fmi2_import_real_typedef_t* rt = fmi2_import_get_type_as_real(vt);
      fmi2_real_t min = fmi2_import_get_real_type_min(rt);
      fmi2_real_t max = fmi2_import_get_real_type_max(rt);
      fmi2_real_t nom = fmi2_import_get_real_type_nominal(rt);
      fmi2_import_unit_t* u = fmi2_import_get_real_type_unit(rt);
      fmi2_import_display_unit_t* du = fmi2_import_get_type_display_unit(rt);

      printf(
        "\n\t\"type\": {\n\t\t\"name\": \"Real\", \n\t\t\"min\": \"%g\", \n\t\t\"max\": \"%g\", \n\t\t\"nominal\": \"%g\"",
        min,
        max,
        nom);

      if (u) {
        char buf[1000];
        fmi2_SI_base_unit_exp_to_string(fmi2_import_get_SI_unit_exponents(u), 1000, buf);

        printf(
          ",\n\t\t\"unitDefinition\": {\"unit\": \"%s\", \"baseUnit\": \"%s\", \"factor\": \"%g\", \"offset\": \"%g\", \"displayUnitNumber\": \"%d\"}",
          fmi2_import_get_unit_name(u),
          buf,
          fmi2_import_get_SI_unit_factor(u),
          fmi2_import_get_SI_unit_offset(u),
          fmi2_import_get_unit_display_unit_number(u)
        );
      } else {
        printf(
          ",\n\t\t\"unitDefinition\": {\"unit\": \"\", \"baseUnit\": \"\", \"factor\": \"\", \"offset\": \"\", \"displayUnitNumber\": \"\"}");
        
      }

      if (du) {
        printf(
          ",\"displayUnitDefinition\": {\"displayUnit\": \"%s\", \"factor\": \"%g\", \"offset\": \"%g\", \"relative\": \"%s\"}",
          fmi2_import_get_display_unit_name(du),
          fmi2_import_get_display_unit_factor(du),
          fmi2_import_get_display_unit_offset(du),
          fmi2_import_get_real_type_is_relative_quantity(rt)?"yes":"no"
        );
      }else {
        printf(
          ",\n\t\t\"displayUnitDefinition\": {\"displayUnit\": \"\", \"factor\": \"\", \"offset\": \"\", \"relative\": \"\"}");
        
      }

      printf("\n\t\t}");
      break;
    }
    case fmi2_base_type_int:{
      fmi2_import_integer_typedef_t* it = fmi2_import_get_type_as_int(vt);
      int min = fmi2_import_get_integer_type_min(it);
      int max = fmi2_import_get_integer_type_max(it);

      printf("\n\t\"type\": {\n\t\t\"name\": \"Integer\", \n\t\t\"min\": \"%d\", \n\t\t\"max\": \"%d\"\n\t\t}", min, max);
      break;
    }
    case fmi2_base_type_bool:{
      printf("\n\t\"type\": {\n\t\t\"name\": \"Boolean\"}");
      break;
    }
    case fmi2_base_type_str:{
      printf("\n\t\"type\": {\n\t\t\"name\": \"Srting\"}");
      break;
    }
    case fmi2_base_type_enum:{
      fmi2_import_enumeration_typedef_t* et = fmi2_import_get_type_as_enum(vt);
      int min = fmi2_import_get_enum_type_min(et);
      int max = fmi2_import_get_enum_type_max(et);

      printf("\n\t\"type\": {\n\t\t\"name\": \"Enumeration\", \n\t\t\"min\": \"%d\", \n\t\t\"max\": \"%d\", \n\t\t\"enumerations\": [", min, max);

      {
        unsigned ni, i;
        ni = fmi2_import_get_enum_type_size(et);
        for(i = 1; i <= ni; i++) {
          int val = fmi2_import_get_enum_type_item_value(et, i);
          const char* str = fmi2_import_get_enum_type_value_name(et, val);
          const char* itnm = fmi2_import_get_enum_type_item_name(et, i);
          printf("\n\t\t\t{\"name\": \"%s\", \"value\": \"%d\", \"description\": \"%s\"}",
            itnm,
            val,
            fmi2_import_get_enum_type_item_description(et, i)
          );
          if (i < ni) printf(", ");
        }
      }
      printf("\n\t\t\t]\n\t\t}");
      break;
    }
    default: {
    }
  }
}

void readFMI2TypeDefinitions(fmi2_import_variable_typedef_t* vt) {

  const char* quan;
  if(!vt) {
    return;
  }

  quan = !fmi2_import_get_type_quantity(vt) ? "" : fmi2_import_get_type_quantity(vt);
  printf("   {\n\t\"name\": \"%s\", \n\t\"description\": \"%s\", \n\t\"baseType\": \"%s\", \n\t\"quantity\": \"%s\",", 
    (char*) fmi2_import_get_type_name(vt),
    (char*) fmi2_import_get_type_description(vt),
    (char*) fmi2_base_type_to_string(fmi2_import_get_base_type(vt)),
    (char*) quan
  );

  readBaseType(vt);

  printf("\n\t}");
}

static void readFMI2ModelVariables(fmi2_import_t* fmu, fmi2_import_variable_t* v) {
  fmi2_base_type_enu_t bt;
  size_t vr = fmi2_import_get_variable_vr(v);
  bt = fmi2_import_get_variable_base_type(v);

  printf("   {\n\t\"name\": \"%s\", \n\t\"description\": \"%s\", \n\t\"valueReference\": \"%u\", \n\t\"variability\": \"%s\", \n\t\"causality\": \"%s\", \n\t\"initial\": \"%s\",",
    fmi2_import_get_variable_name(v),
    !fmi2_import_get_variable_description(v) ? "" : fmi2_import_get_variable_description(v),
    (unsigned)vr,
    fmi2_variability_to_string(fmi2_import_get_variability(v)),
    fmi2_causality_to_string(fmi2_import_get_causality(v)),
    fmi2_initial_to_string(fmi2_import_get_initial(v))
  );

  if(bt == fmi2_base_type_real) {
      fmi2_import_real_variable_t *rv = fmi2_import_get_variable_as_real(v);
      fmi2_import_unit_t * u = fmi2_import_get_real_variable_unit(rv);
      fmi2_import_display_unit_t * du = fmi2_import_get_real_variable_display_unit(rv);

      printf("\n\t\"type\": {\"name\": \"Real\"");

      if (u != NULL) {
        printf(",\"unit\": \"%s\"", fmi2_import_get_unit_name(u));
      } else {
        printf(",\"unit\": \"%d\"", 0);
      }

      if (du != NULL) {
        printf(",\"displayUnit\": \"%s\"", fmi2_import_get_display_unit_name(du));
      } else {
        printf(",\"displayUnit\": \"%s\"", "");
      }
  } 

  if(bt == fmi2_base_type_bool) {
    printf("\n\t\"type\": {\"name\": \"Boolean\"");
  }

  if(bt == fmi2_base_type_int) {
    printf("\n\t\"type\": {\"name\": \"Integer\"");
  }

  if(bt == fmi2_base_type_str) {
    printf("\n\t\"type\": {\"name\": \"String\"");
  }

  if(bt == fmi2_base_type_enum) {
    printf("\n\t\"type\": {\"name\": \"Enumeration\"");
  }

  if(fmi2_import_get_variable_has_start(v)) {

    switch(fmi2_import_get_variable_base_type(v)) {
    case fmi2_base_type_real: {
        
        fmi2_import_real_variable_t *rv = fmi2_import_get_variable_as_real(v);
        printf(",\"start\": \"%g\", \"nominal\": \"%g\", \"min\": \"%g\", \"max\": \"%g\"", 
          fmi2_import_get_real_variable_start(rv),
          fmi2_import_get_real_variable_nominal(rv),
          fmi2_import_get_real_variable_min(rv),
          fmi2_import_get_real_variable_max(rv)
        );
        break;
    }
    case fmi2_base_type_int:{
        printf(",\"start\": \"%d\"", fmi2_import_get_integer_variable_start(fmi2_import_get_variable_as_integer(v)));
        break;
    }
    case fmi2_base_type_bool:{
        printf(",\"start\": \"%d\"", fmi2_import_get_boolean_variable_start(fmi2_import_get_variable_as_boolean(v)));
        break;
    }
    case fmi2_base_type_str:{
        printf(",\"start\": \"%s\"", fmi2_import_get_string_variable_start(fmi2_import_get_variable_as_string(v)));

        break;
    }
    case fmi2_base_type_enum:{
        printf(",\"start\": \"%d\"", fmi2_import_get_enum_variable_start(fmi2_import_get_variable_as_enum(v)));
        break;
    }
    default: {
      }
    }
  }

  if (fmi2_import_get_variable_declared_type(v)) {
    printf(",\"declaredType\": \"%s\"", fmi2_import_get_type_name(fmi2_import_get_variable_declared_type(v)));
  } else {
    printf(",\"declaredType\": \"\"");
  }

  printf("}");

  if(fmi2_import_get_variable_alias_kind(v) != fmi2_variable_is_not_alias) {
    printf(",\n\t\"isAlias\": \"true\"");
    printf(",\n\t\"aliasBase\": \"%s\"", fmi2_import_get_variable_name( fmi2_import_get_variable_alias_base(fmu, v)));
  } else {
    printf(",\n\t\"isAlias\": \"false\"");
    printf(",\n\t\"aliasBase\": \"\"");
  }

  {
    fmi2_import_variable_list_t* vl = fmi2_import_get_variable_aliases(fmu, v);
    size_t i, n = fmi2_import_get_variable_list_size(vl);
    printf(",\n\t\"listingAliases\": [");
    if(n>1) {
      for(i = 0;i<n;i++) {
        printf("\n\t\t\t{\"name\": \"%s\"}", fmi2_import_get_variable_name(fmi2_import_get_variable(vl, i)));
        if ((i + 1) < n) printf(", ");
      }
    }
    printf("\n\t\t]\n");
    fmi2_import_free_variable_list(vl);
  }

  printf("\t}\n");
}

static int startsWith(const char *a, const char *b) {
   if(strncmp(a, b, strlen(b)) == 0) return 1;
   return 0;
}

static char* replace(char const * const original,  char const * const pattern, char const * const replacement) {
  size_t const replen = strlen(replacement);
  size_t const patlen = strlen(pattern);
  size_t const orilen = strlen(original);
  size_t patcnt = 0;
  const char * oriptr;
  const char * patloc;

  for (oriptr = original; (patloc = strstr(oriptr, pattern)); oriptr = patloc + patlen) {
    patcnt++;
  }

  {
    size_t const retlen = orilen + patcnt * (replen - patlen);
    char * const returned = (char *) malloc( sizeof(char) * (retlen + 1) );

    if (returned != NULL) {
      char * retptr = returned;
      for (oriptr = original; (patloc = strstr(oriptr, pattern)); oriptr = patloc + patlen) {
        size_t const skplen = patloc - oriptr;
        strncpy(retptr, oriptr, skplen);
        retptr += skplen;
        strncpy(retptr, replacement, replen);
        retptr += replen;
      }
      strcpy(retptr, oriptr);
    }
    return returned;
  }
}

static void printCapabilitiesInfoFMI1(fmi1_import_capabilities_t* capabilities, const char* modelIdentifier) {
  printf(" \"coSimulation\": {\n");
  printf("   \"modelIdentifier\": \"%s\",\n", modelIdentifier);
  printf("   \"canHandleVariableCommunicationStepSize\": \"%s\",\n", fmi1_import_get_canHandleVariableCommunicationStepSize(capabilities ) == 0 ? "false" : "true");
  printf("   \"canHandleEvents\": \"%s\",\n", fmi1_import_get_canHandleEvents(capabilities ) == 0 ? "false" : "true");
  printf("   \"canRejectSteps\": \"%s\",\n", fmi1_import_get_canRejectSteps(capabilities ) == 0 ? "false" : "true");
  printf("   \"canInterpolateInputs\": \"%s\",\n", fmi1_import_get_canInterpolateInputs(capabilities ) == 0 ? "false" : "true");
  printf("   \"maxOutputDerivativeOrder\": \"%s\",\n", fmi1_import_get_maxOutputDerivativeOrder(capabilities ) == 0 ? "false" : "true");
  printf("   \"canRunAsynchronuously\": \"%s\",\n", fmi1_import_get_canRunAsynchronuously(capabilities ) == 0 ? "false" : "true");
  printf("   \"canSignalEvents\": \"%s\",\n", fmi1_import_get_canSignalEvents(capabilities ) == 0 ? "false" : "true");
  printf("   \"canBeInstantiatedOnlyOncePerProcess\": \"%s\",\n", fmi1_import_get_canBeInstantiatedOnlyOncePerProcess(capabilities ) == 0 ? "false" : "true");
  printf("   \"canNotUseMemoryManagementFunctions\": \"%s\",\n", fmi1_import_get_canNotUseMemoryManagementFunctions(capabilities ) == 0 ? "false" : "true");
  printf("   \"sourceFiles\": []\n");
  printf(" },\n");
}

static void printCapabilitiesInfo(fmi2_import_t* fmu, char* modelIdentifier) {
  size_t i;
  char* key;
  char modifiedKey[100];
  int num;
  char* flag;

  printf(" \"modelExchange\": {\n");
  printf("   \"modelIdentifier\": \"%s\",\n", modelIdentifier);
  for( i = 0; i < fmi2_capabilities_Num; ++i) {
    num = fmi2_import_get_capability(fmu, (fmi2_capabilities_enu_t)i);
    key = (char*) fmi2_capability_to_string((fmi2_capabilities_enu_t)i);
    flag = num == 0 ? "false" : "true";
    if (startsWith(key, "me_") == 1) {
      printf("   \"%s\": \"%s\",\n", replace(key, "me_", ""), flag);
    }
  }
  printf("   \"sourceFiles\": [\n");
  {
    int n_sources = fmi2_import_get_source_files_me_num(fmu);
    int k;
    for (k=0; k < n_sources; k++) {
      printf("     {\"file\": {\"name\": \"%s\"}}", (char*) fmi2_import_get_source_file_me(fmu, k));
      if ((k + 1) < n_sources) printf(",");
      printf("\n");
    }
  }
  printf("   ]\n");
  printf(" },\n");


  printf(" \"coSimulation\": {\n");
  printf("   \"modelIdentifier\": \"%s\",\n", modelIdentifier);
  for( i = 0; i < fmi2_capabilities_Num; ++i) {
    num = fmi2_import_get_capability(fmu, (fmi2_capabilities_enu_t)i);
    key = (char*) fmi2_capability_to_string((fmi2_capabilities_enu_t)i);
    flag = num == 0 ? "false" : "true";
    if (startsWith(key, "cs_") == 1) {
      printf("   \"%s\": \"%s\",\n", replace(key, "cs_", ""), flag);
    }
  }

  printf("   \"sourceFiles\": [\n");
  {
    int n_sources = fmi2_import_get_source_files_cs_num(fmu);
    int k;
    for (k=0; k < n_sources; k++) {
      printf("     {\"file\": {\"name\": \"%s\"}}", (char*) fmi2_import_get_source_file_cs(fmu, k));
      if ((k + 1) < n_sources) printf(",");
      printf("\n");
    }
  }
  printf("   ]\n");
  printf(" },\n");
}

void readFMI1TypeDefinitions(fmi1_import_variable_typedef_t* vt) {
    const char* quan;

    if(!vt) return;

    quan = fmi1_import_get_type_quantity(vt);

    printf("\t{\n\t\t\"name\": \"%s\", \n\t\t\"description\": \"%s\", \n\t\t\"baseType\": \"%s\"",
      fmi1_import_get_type_name(vt),
      fmi1_import_get_type_description(vt),
      fmi1_base_type_to_string(fmi1_import_get_base_type(vt)));

    if(quan) {
      printf(",\n\t\t\"quantity\": \"%s\"", quan);
    } else {
      printf(",\n\t\t\"quantity\": \"\"");
    }

    switch(fmi1_import_get_base_type(vt)) {
    case fmi1_base_type_real: {
        fmi1_import_real_typedef_t* rt = fmi1_import_get_type_as_real(vt);
        fmi1_real_t min = fmi1_import_get_real_type_min(rt);
        fmi1_real_t max = fmi1_import_get_real_type_max(rt);
        fmi1_real_t nom = fmi1_import_get_real_type_nominal(rt);
        fmi1_import_unit_t* u = fmi1_import_get_real_type_unit(rt);
        fmi1_import_display_unit_t* du = fmi1_import_get_type_display_unit(rt);

        printf(",\n\t\t\"type\": {\"name\": \"Real\", \"min\": \"%g\", \"max\": \"%g\", \"nominal\": \"%g\"",
          min,
          max,
          nom
        );

        if(u) {
          printf(", \"unit\": {\"name\": \"%s\"}", fmi1_import_get_unit_name(u));
        } else {
          printf(", \"unit\": {}");
        }

        if(du) {
            printf(",\"displayUnit\": {\"name\": \"%s\", \"gain\": \"%g\", \"offset\": \"%g\", \"relative\": \"%s\"}",
              fmi1_import_get_display_unit_name(du),
              fmi1_import_get_display_unit_gain(du),
              fmi1_import_get_display_unit_offset(du),
              fmi1_import_get_real_type_is_relative_quantity(rt)?"yes":"no"
              );
        } else {
          printf(", \"displayUnit\": {}");

        }
        printf("}\n\t}");
        break;
    }
    case fmi1_base_type_int:{
        fmi1_import_integer_typedef_t* it = fmi1_import_get_type_as_int(vt);
        int min = fmi1_import_get_integer_type_min(it);
        int max = fmi1_import_get_integer_type_max(it);

        printf(",\n\t\t\"type\": {\"name\": \"Integer\", \"min\": \"%d\", \"max\": \"%d\"",
          min,
          max
        );
        printf("}\n\t}");
        break;
    }
    case fmi1_base_type_bool:{
        printf(",\n\t\t\"type\": {\"name\": \"Boolean\", \"min\": \"\", \"max\": \"\"");
        printf("}\n\t}");
        break;
    }
    case fmi1_base_type_str:{
        printf(",\n\t\t\"type\": {\"name\": \"String\", \"min\": \"\", \"max\": \"\"");
        printf("}\n\t}");
        break;
    }
    case fmi1_base_type_enum:{
        fmi1_import_enumeration_typedef_t* et = fmi1_import_get_type_as_enum(vt);
        int min = fmi1_import_get_enum_type_min(et);
        int max = fmi1_import_get_enum_type_max(et);
        printf(",\n\t\t\"type\": {\n\t\t\t\"name\": \"Enumeration\", \n\t\t\t\"min\": \"%d\", \n\t\t\t\"max\": \"%d\", \n\t\t\t\"enumerations\": [",
          min, max);
        {
            size_t ni;
            unsigned i;
            ni = fmi1_import_get_enum_type_size(et);
            i = (unsigned)(ni);
            for(i = 1; i <= ni; i++) {
              printf("\n\t\t\t\t{\"name\": \"%s\", \"description\": \"%s\"}",
                fmi1_import_get_enum_type_item_name(et, i),
                fmi1_import_get_enum_type_item_description(et, i)
              );
              if (i < ni) printf(", ");
            }
        }
        printf("\n\t\t\t]\n\t\t}\n\t}");
        break;
    }
    default: {}
    }
}

void readFMI1ModelVariables(fmi1_import_t* fmu, fmi1_import_variable_t* v) {
  fmi1_base_type_enu_t bt = fmi1_import_get_variable_base_type(v);

  printf("   {\"name\": \"%s\", \n\t\"description\": \"%s\", \n\t\"valueReference\": \"%d\", \n\t\"variability\": \"%s\", \n\t\"causality\": \"%s\", \n\t\"baseType\": \"%s\",",
    fmi1_import_get_variable_name(v),
    !fmi1_import_get_variable_description(v) ? "" : replace(fmi1_import_get_variable_description(v), "\"", "'"),
    fmi1_import_get_variable_vr(v),
    fmi1_variability_to_string(fmi1_import_get_variability(v)),
    fmi1_causality_to_string(fmi1_import_get_causality(v)),
    fmi1_base_type_to_string(bt)
  );

  if(bt == fmi1_base_type_real) {
      fmi1_import_real_variable_t *rv = fmi1_import_get_variable_as_real(v);
      fmi1_import_unit_t * u = fmi1_import_get_real_variable_unit(rv);
      fmi1_import_display_unit_t * du = fmi1_import_get_real_variable_display_unit(rv);

      printf("\n\t\"type\": {\"name\": \"Real\"");
      printf(", \"unit\": \"%s\", \"displayUnit\": \"%s\"",
        u ? fmi1_import_get_unit_name(u): 0,
        du ? fmi1_import_get_display_unit_name(du) : 0);
  }

  if(bt == fmi1_base_type_bool) {
    printf("\n\t\"type\": {\"name\": \"Boolean\"");
  }

  if(bt == fmi1_base_type_int) {
    printf("\n\t\"type\": {\"name\": \"Integer\"");
  }

  if(bt == fmi1_base_type_str) {
    printf("\n\t\"type\": {\"name\": \"String\"");
  }

  if(bt == fmi1_base_type_enum) {
    printf("\n\t\"type\": {\"name\": \"Enumeration\"");
  }

  if(fmi1_import_get_variable_has_start(v)) {
    switch(fmi1_import_get_variable_base_type(v)) {
      case fmi1_base_type_real: {
        fmi1_import_real_variable_t *rv = fmi1_import_get_variable_as_real(v);
        printf(",\"start\": \"%g\"", fmi1_import_get_real_variable_start(rv));
        break;
      }
      case fmi1_base_type_int:{
        printf(",\"start\": \"%d\"", fmi1_import_get_integer_variable_start(fmi1_import_get_variable_as_integer(v)));
        break;
      }
      case fmi1_base_type_bool:{
        printf(",\"start\": \"%d\"", fmi1_import_get_boolean_variable_start(fmi1_import_get_variable_as_boolean(v)));
        break;
      }
      case fmi1_base_type_str:{
        printf(",\"start\": \"%s\"", fmi1_import_get_string_variable_start(fmi1_import_get_variable_as_string(v)));
        break;
      }
      case fmi1_base_type_enum:{
        printf(",\"start\": \"%d\"", fmi1_import_get_enum_variable_start(fmi1_import_get_variable_as_enum(v)));
        break;
      }
      default: {}
    }
  }

  if (fmi1_import_get_variable_declared_type(v)) {
    printf(",\"declaredType\": \"%s\"", fmi1_import_get_type_name(fmi1_import_get_variable_declared_type(v)));
  } else {
    printf(",\"declaredType\": \"\"");
  }

  printf("}");

  if (fmi1_import_get_variable_alias_kind(v) != fmi1_variable_is_not_alias) {
    printf(",\n\t\"isAlias\": \"true\"");
    printf(",\n\t\"aliasBase\": \"%s\"", fmi1_import_get_variable_name( fmi1_import_get_variable_alias_base(fmu, v)));
  } else {
    printf(",\n\t\"isAlias\": \"false\"");
    printf(",\n\t\"aliasBase\": \"\"");
  }

  {
    fmi1_import_variable_list_t* vl = fmi1_import_get_variable_aliases(fmu, v);
    size_t n = fmi1_import_get_variable_list_size(vl);
    unsigned i = (unsigned)n;
    printf(",\n\t\"listingAliases\": [");
    if(n>1) {
      for(i = 0;i<n;i++) {
        printf("\n\t\t\t{\"name\": \"%s\"}", fmi1_import_get_variable_name(fmi1_import_get_variable(vl, i)));
        if ((i + 1) < n) printf(", ");
      }
    }
    printf("\n\t\t]");
    fmi1_import_free_variable_list(vl);
  }

  {
    fmi1_import_variable_list_t* vl = fmi1_import_get_direct_dependency( fmu, v);
    size_t n = 0;
    unsigned i;
    if(vl) n = fmi1_import_get_variable_list_size(vl);
    i = (unsigned)n;
    printf(",\n\t\"listingDirectDependencies\": [");
    if(vl) {
      for(i = 0;i<n;i++) {
        printf("\n\t\t\t{\"name\": \"%s\"}", fmi1_import_get_variable_name(fmi1_import_get_variable(vl, i)));
        if ((i + 1) < n) printf(", ");
      }
    }
    printf("\n\t\t]\n");
    fmi1_import_free_variable_list(vl);
  }

  printf("\t}\n ");
}


void printDependenciesInfo( fmi2_import_t* fmu, fmi2_import_variable_list_t* rows, fmi2_import_variable_list_t* cols, size_t* start, size_t *dep, char* factor) {
  size_t i, j, nr;
  if(!rows || !cols || !start) {
    printf("Dependencies are not available\n");
    if(rows) {
      nr = fmi2_import_get_variable_list_size(rows);
      for(i = 0; i < nr; i++) {
        printf("\t%s\n",fmi2_import_get_variable_name(fmi2_import_get_variable(rows, i)));
      }
    }
    return;
  }
  nr = fmi2_import_get_variable_list_size(rows);
  for(i = 0; i < nr; i++) {
    if(start[i] == start[i+1]) {
      printf("\t%s has no dependencies\n",fmi2_import_get_variable_name(fmi2_import_get_variable(rows, i)));
    }
    else if((start[i] + 1 == start[i+1]) && (dep[start[i]] == 0)) {
      printf("\t%s depends on all\n",fmi2_import_get_variable_name(fmi2_import_get_variable(rows, i)));
    }
    else {
      printf("\t%s depends on:\n",fmi2_import_get_variable_name(fmi2_import_get_variable(rows, i)));
      for(j = start[i]; j < start[i+1]; j++) {
        printf("\t\t%s (factor kind: %s)\n",fmi2_import_get_variable_name(fmi2_import_get_variable(cols, dep[j]-1)), 
          fmi2_dependency_factor_kind_to_string((fmi2_dependency_factor_kind_enu_t)factor[j]));
      }
    }
  }
}

void printFactorKind(fmi2_dependency_factor_kind_enu_t factorKind) {
  if(fmi2_dependency_factor_kind_dependent == factorKind) {
    printf("dependent ");
  }

  if(fmi2_dependency_factor_kind_constant == factorKind) {
    printf("constant ");
  }

  if(fmi2_dependency_factor_kind_fixed == factorKind) {
    printf("fixed ");
  }

  if(fmi2_dependency_factor_kind_tunable == factorKind) {
    printf("tunable ");
  }

  if(fmi2_dependency_factor_kind_discrete == factorKind) {
    printf("discrete ");
  }

  if(fmi2_dependency_factor_kind_num == factorKind) {
    printf("num ");
  }
}

int read(char* fmuPath, char* tmpPath) {

  fmi2_import_t* fmu;
  fmi1_import_t* fmu1; 

  fmi_import_context_t* context;
  fmi_version_enu_t version;
  jm_status_enu_t status;

  jm_callbacks* callbacks;

  callbacks = (jm_callbacks*)malloc(sizeof(jm_callbacks));
  callbacks->malloc = malloc;
  callbacks->calloc = calloc;
  callbacks->realloc = realloc;
  callbacks->free = free;
  callbacks->logger = jm_default_logger;
  callbacks->log_level = jm_log_level_nothing;
  callbacks->context = 0;

  context = fmi_import_allocate_context(callbacks);
  version = fmi_import_get_fmi_version(context, fmuPath, tmpPath);

  int isFMI1 = FALSE;
  int isFMI2 = TRUE;

  if(version != fmi_version_2_0_enu) {
    isFMI2 = FALSE;
    isFMI1 = TRUE;
    fmu1 = fmi1_import_parse_xml(context, tmpPath);
    if(!fmu1) {
      printf("{\"status\": \"false\", \"statusText\": \"Error parsing XML FMI1.0\"}\n");
      fmi_import_free_context(context);
      return(EXIT_FAILURE);
    } 
  } else {
    isFMI2 = TRUE;
    isFMI1 = FALSE;
    fmu = fmi2_import_parse_xml(context, tmpPath, &annotation_callbacks);
    fmu = fmi2_import_parse_xml(context, tmpPath,0);
    if(!fmu) {
      printf("{\"status\": \"false\", \"statusText\": \"Error parsing XML FMI2.0\"}\n");
      fmi_import_free_context(context);
      return (EXIT_FAILURE);
    }
  }


  if (isFMI1 == TRUE) {

    printf("{\"fmiVersion\": \"%s\",\n", fmi1_import_get_model_standard_version(fmu1));

    if (fmi1_import_get_fmu_kind(fmu1) == fmi1_fmu_kind_enu_me) {
      printf(" \"isModelExchangeFMU\": \"true\",\n");
      printf(" \"isCoSimulationFMU\": \"false\",\n");
    } else if (fmi1_import_get_fmu_kind(fmu1) == fmi1_fmu_kind_enu_cs_standalone || fmi1_import_get_fmu_kind(fmu1) == fmi1_fmu_kind_enu_cs_tool) {
      printf(" \"isModelExchangeFMU\": \"false\",\n");
      printf(" \"isCoSimulationFMU\": \"true\",\n");
    }

    printf(" \"fmiModelDescription\": {\n");
    printf(" \"fmuPath\": \"%s\",\n", fmuPath);
    printf(" \"tmpPath\": \"%s\",\n", tmpPath);
    printf(" \"status\": \"true\",\n");
    printf(" \"statusText\": \"success\",\n");
    printf(" \"fmiVersion\": \"%s\",\n", fmi1_import_get_model_standard_version(fmu1));
    printf(" \"modelName\": \"%s\",\n", fmi1_import_get_model_name(fmu1));
    printf(" \"modelIdentifier\": \"%s\",\n", fmi1_import_get_model_identifier(fmu1));
    printf(" \"guid\": \"%s\",\n", fmi1_import_get_GUID(fmu1));
    printf(" \"kind\": \"%s\",\n", fmi1_fmu_kind_to_string(fmi1_import_get_fmu_kind(fmu1)));
    printf(" \"description\": \"%s\",\n", fmi1_import_get_description(fmu1));
    printf(" \"author\": \"%s\",\n", fmi1_import_get_author(fmu1));
    printf(" \"generationTool\": \"%s\",\n", fmi1_import_get_generation_tool(fmu1));
    printf(" \"generationDateAndTime\": \"%s\",\n", fmi1_import_get_generation_date_and_time(fmu1));
    printf(" \"version\": \"%s\",\n", fmi1_import_get_model_version(fmu1));
    printf(" \"variableNamingConvention\": \"%s\",\n", fmi1_naming_convention_to_string(fmi1_import_get_naming_convention(fmu1)));
    printf(" \"numberOfEventIndicators\": \"%d\",\n",
      fmi1_import_get_number_of_event_indicators(fmu1));
    printf(" \"numberOfContinuousStates\": \"%d\",\n",
      fmi1_import_get_number_of_continuous_states(fmu1));
    printf(" \"defaultExperiment\": {\"startTime\": \"%g\", \"stopTime\": \"%g\", \"tolerance\": \"%g\"},\n",
      fmi1_import_get_default_experiment_start(fmu1),
      fmi1_import_get_default_experiment_stop(fmu1),
      fmi1_import_get_default_experiment_tolerance(fmu1)
    );

    // FMI 1.0 ModelExchange & CoSimulation
    if(fmi1_import_get_fmu_kind(fmu1) != fmi1_fmu_kind_enu_me) {
      printf(" \"modelExchange\": {},\n");
      const char* modelIdentifier = fmi1_import_get_model_identifier(fmu1);
      printCapabilitiesInfoFMI1(fmi1_import_get_capabilities(fmu1), modelIdentifier);
    } else {
      printf(" \"modelExchange\": {},\n");
      printf(" \"coSimulation\": {},\n");
    }

    // FMI 1.0 VendorAnnotations
    {
      printf(" \"vendorAnnotations\": [\n");
      fmi1_import_vendor_list_t* vl = fmi1_import_get_vendor_list(fmu1);
      size_t nv = fmi1_import_get_number_of_vendors(vl);
      unsigned i;
      i = (unsigned)nv;
      for( i = 0; i < nv; i++) {
        fmi1_import_vendor_t* vendor = fmi1_import_get_vendor(vl, i);
        if(!vendor) break;
        printf("   {\"tool\": {\"name\": \"%s\"",
          (char*) fmi1_import_get_vendor_name(vendor)
        );
        if ((i + 1) < nv) printf(",");
        printf(", \"annotations\": [");
        unsigned j, na = fmi1_import_get_number_of_vendor_annotations(vendor);
        for(j = 0; j< na; j++) {
          fmi1_import_annotation_t* a = fmi1_import_get_vendor_annotation(vendor, j);
          if(!a) break;
          printf("{\"annotation\": {\"name\": \"%s\", \"value\": \"%s\"}}", fmi1_import_get_annotation_name(a), fmi1_import_get_annotation_value(a));
          if ((j + 1) < na) printf(",");
        }
        printf("] } }\n");
      }
      printf(" ],\n");
    }

    // FMI 1.0 UnitDefinitions
    {
      printf(" \"unitDefinitions\": [\n");
      fmi1_import_unit_definitions_t* ud = fmi1_import_get_unit_definitions(fmu1);
      if(ud) {
          unsigned  i, nu = fmi1_import_get_unit_definitions_number(ud);
          for(i = 0; i < nu; i++) {
              fmi1_import_unit_t* u = fmi1_import_get_unit(ud, i);

              if(!u) break;

              printf("   {\"name\": \"%s\", \"baseUnit\":  {\"unit\": \"%s\", \"factor\": \"\", \"offset\": \"\", \"displayUnitNumber\": \"%d\"",
                fmi1_import_get_unit_name(u),
                fmi1_import_get_unit_name(u),
                fmi1_import_get_unit_display_unit_number(u));

              if (fmi1_import_get_unit_display_unit_number(u) > 0) {
                printf(", \"baseUnitDefinition\": {\"displayUnit\": \"UNKNOWN\"}");
              } else {
                printf(", \"baseUnitDefinition\": {}");
              }

              printf("} }");

              if ((i + 1) < nu) printf(",");
              printf("\n");
          }
      }
      printf(" ],\n");
    }

    {
      printf(" \"typeDefinitions\": [\n");
      fmi1_import_type_definitions_t* td = fmi1_import_get_type_definitions(fmu1);
      if(td) {
        {
          unsigned i, ntd = (unsigned)fmi1_import_get_type_definition_number(td);
          for(i = 0; i < ntd; i++) {
            fmi1_import_variable_typedef_t* vt = fmi1_import_get_typedef(td, i);
            if(!vt) break;
            readFMI1TypeDefinitions(vt);
            if ((i + 1) < ntd) printf(",\n");
          }
        }
      }
      printf(" ],\n");
    }

    printf(" \"modelVariables\": { \"scalarVariables\": [\n");
    {
      size_t nv;
      unsigned i;
      fmi1_import_variable_list_t* vl = fmi1_import_get_variable_list(fmu1);
      nv = fmi1_import_get_variable_list_size(vl);
      i = (unsigned)nv;
      for(i = 0; i < nv; i++) {
        fmi1_import_variable_t* var = fmi1_import_get_variable(vl, i);
        if(!var) break;
        readFMI1ModelVariables(fmu1, var);
        if ((i + 1) < nv) printf(",\n");
      }
      fmi1_import_free_variable_list(vl);
    }

    printf(" ] }\n");
    printf("}}\n");

    return (EXIT_SUCCESS);

  } else if (isFMI2 == TRUE) {


    printf("{\"fmiVersion\": \"%s\",\n", (char*) fmi2_import_get_model_standard_version(fmu));

    char* modelIdentifier = "";
    if(fmi2_import_get_fmu_kind(fmu) != fmi2_fmu_kind_cs) {
      printf(" \"isModelExchangeFMU\": \"true\",\n");
      printf(" \"isCoSimulationFMU\": \"false\",\n");
      modelIdentifier = (char*) fmi2_import_get_model_identifier_ME(fmu);
    } else {
      printf(" \"isModelExchangeFMU\": \"false\",\n");
      printf(" \"isCoSimulationFMU\": \"true\",\n");
      modelIdentifier = (char*) fmi2_import_get_model_identifier_CS(fmu);
    }


    printf(" \"fmiModelDescription\": {\n");
    printf(" \"fmuPath\": \"%s\",\n", fmuPath);
    printf(" \"tmpPath\": \"%s\",\n", tmpPath);
    printf(" \"status\": \"true\",\n");
    printf(" \"statusText\": \"success\",\n");
    printf(" \"fmiVersion\": \"%s\",\n", (char*) fmi2_import_get_model_standard_version(fmu));
    printf(" \"modelName\": \"%s\",\n", (char*) fmi2_import_get_model_name(fmu));
    printf(" \"modelIdentifier\": \"%s\",\n", modelIdentifier);
    printf(" \"guid\": \"%s\",\n", (char*) fmi2_import_get_GUID(fmu));
    printf(" \"description\": \"%s\",\n", (char*) fmi2_import_get_description(fmu));
    printf(" \"author\": \"%s\",\n", (char*) fmi2_import_get_author(fmu));
    printf(" \"version\": \"%s\",\n", (char*) fmi2_import_get_model_version(fmu));
    printf(" \"copyright\": \"%s\",\n", (char*) fmi2_import_get_copyright(fmu));
    printf(" \"license\": \"%s\",\n", (char*) fmi2_import_get_license(fmu));
    printf(" \"kind\": \"%s\",\n", (char*) fmi2_fmu_kind_to_string(fmi2_import_get_fmu_kind(fmu)));
    printf(" \"generationTool\": \"%s\",\n", (char*) fmi2_import_get_generation_tool(fmu));
    printf(" \"generationDateAndTime\": \"%s\",\n", (char*) fmi2_import_get_generation_date_and_time(fmu));
    printf(" \"variableNamingConvention\": \"%s\",\n",
      (char*) fmi2_naming_convention_to_string(fmi2_import_get_naming_convention(fmu)));
    printf(" \"numberOfEventIndicators\": \"%lu\",\n",
      fmi2_import_get_number_of_event_indicators(fmu));
    printf(" \"numberOfContinuousStates\": \"%lu\",\n",
      fmi2_import_get_number_of_continuous_states(fmu));

    printf(" \"defaultExperiment\": {\"startTime\": \"%g\", \"stopTime\": \"%g\", \"tolerance\": \"%g\", \"step\": \"%g\"},\n",
      fmi2_import_get_default_experiment_start(fmu),
      fmi2_import_get_default_experiment_stop(fmu),
      fmi2_import_get_default_experiment_tolerance(fmu),
      fmi2_import_get_default_experiment_step(fmu)
    );

    printCapabilitiesInfo(fmu, modelIdentifier);

    printf(" \"modelStructure\": {\n");
    int ii, jj;
    size_t* startIndex;
    size_t* dependency;
    char* factorKind = "";
    int start;
    int lastStart;

    fmi2_import_variable_list_t* vl = fmi2_import_get_variable_list(fmu, 0);
    fmi2_import_get_derivatives_dependencies(fmu, &startIndex, &dependency, &factorKind);
    {
      size_t nv, i;
      fmi2_import_variable_list_t* derivatives = fmi2_import_get_derivatives_list( fmu); 
      nv = fmi2_import_get_variable_list_size(derivatives);
      printf("\t\"derivatives\": [\n");
      for(i = 0; i < nv; i++) {
        printf("\t\t{\"name\": \"%s\", \"index\": \"%u\"",
          fmi2_import_get_variable_name(fmi2_import_get_variable(derivatives, i)),
          (unsigned)fmi2_import_get_variable_original_order(fmi2_import_get_variable(derivatives, i)) + 1
        );
        if ((i + 1) < nv) printf("},\n");
        else printf("}\n");
      }
      printf("\t],\n");
      lastStart = 0;
      printf("\t\"derivativesDependencies\": [\n");
      if (nv > 0) {
        for ( ii = 0; ii <= nv; ii++ ) {
          start = *(startIndex + ii);
          if (start > 0) {
            printf("\t\t{\"dependencies\": \"");
            for (jj = lastStart; jj < start; jj++) {
              printf("%d ",  *(dependency + jj) );
            }
            printf("\", \"dependenciesKind\": \"");
            for (jj = lastStart; jj < start; jj++) {
              printFactorKind(*(factorKind + jj));
            }
            
            if ((ii + 1) <= nv) printf("\"},\n");
            else printf("\"}\n");
            lastStart = start;
          }
        }
      }
      printf("\t], \n");

      fmi2_import_get_initial_unknowns_dependencies(fmu, &startIndex, &dependency, &factorKind);
      fmi2_import_variable_list_t* unknows = fmi2_import_get_initial_unknowns_list( fmu); 
      nv = fmi2_import_get_variable_list_size(unknows);

      printf("\t\"initialUnknowns\": [\n");
      for(i = 0; i < nv; i++) {
        printf("\t\t{\"name\": \"%s\", \"index\": \"%u\"",
          fmi2_import_get_variable_name(fmi2_import_get_variable(unknows, i)),
          (unsigned)fmi2_import_get_variable_original_order(fmi2_import_get_variable(unknows, i)) + 1
        );
        if ((i + 1) < nv) printf("},\n");
        else printf("}\n");
      }
      printf("\t],\n");
      lastStart = 0;
      printf("\t\"initialUnknownsDependencies\": [\n");
      if (nv > 0) {
        for ( ii = 0; ii <= nv; ii++ ) {
          start = *(startIndex + ii);
          if (start > 0) {
            printf("\t\t{\"dependencies\": \"");
            for (jj = lastStart; jj < start; jj++) {
              printf("%d ",  *(dependency + jj) );
            }
            printf("\", \"dependenciesKind\": \"");
            for (jj = lastStart; jj < start; jj++) {
              printFactorKind(*(factorKind + jj));
            }
            
            if ((ii + 1) <= nv) printf("\"},\n");
            else printf("\"}\n");
            lastStart = start;
          }
        }
      }
      printf("\t], \n");

      fmi2_import_get_outputs_dependencies(fmu, &startIndex, &dependency, &factorKind);
      fmi2_import_variable_list_t* outputs = fmi2_import_get_outputs_list( fmu); 
      nv = fmi2_import_get_variable_list_size(outputs);
      printf("\t\"outputs\": [\n");
      for(i = 0; i < nv; i++) {
        printf("\t\t{\"name\": \"%s\", \"index\": \"%u\"",
          fmi2_import_get_variable_name(fmi2_import_get_variable(outputs, i)),
          (unsigned)fmi2_import_get_variable_original_order(fmi2_import_get_variable(outputs, i)) + 1
        );
        if ((i + 1) < nv) printf("},\n");
        else printf("}\n");
      }
      printf("\t],\n");
      lastStart = 0;
      printf("\t\"outputsDependencies\": [\n");
      if (nv > 0) {
        for ( ii = 0; ii <= nv; ii++ ) {
          start = *(startIndex + ii);
          if (start) {
            if (start > 0) {
              printf("\t\t{\"dependencies\": \"");
              for (jj = lastStart; jj < start; jj++) {
                printf("%d ",  *(dependency + jj) );
              }
              printf("\", \"dependenciesKind\": \"");
              for (jj = lastStart; jj < start; jj++) {
                printFactorKind(*(factorKind + jj));
              }
              
              if ((ii + 1) <= nv) printf("\"},\n");
              else printf("\"}\n");
              lastStart = start;
            }
          }
        }
      }
      printf("\t] \n");

      fmi2_import_free_variable_list(derivatives);
      fmi2_import_free_variable_list(unknows);
      fmi2_import_free_variable_list(outputs);
    }
    printf(" },\n");

    printf(" \"vendorAnnotations\": [\n");
    {
      size_t i, nv = fmi2_import_get_vendors_num(fmu);
      for (i = 0; i < nv; i++) {
        printf(
          "   {\"tool\": {\"name\": \"%s\"} }",
          (char*) fmi2_import_get_vendor_name(fmu, i));
        if ((i + 1) < nv) printf(",");
        printf("\n");
      }
    }
    printf(" ],\n");

    printf(" \"unitDefinitions\": [\n");
    {
      fmi2_import_unit_definitions_t* ud = fmi2_import_get_unit_definitions(fmu);
      if (ud) {
        unsigned  i, nu = fmi2_import_get_unit_definitions_number(ud);
        for(i = 0; i < nu; i++) {
          fmi2_import_unit_t* u = fmi2_import_get_unit(ud, i);
          char buf[1000];

          if(!u) {
            break;
          }

          fmi2_SI_base_unit_exp_to_string(fmi2_import_get_SI_unit_exponents(u), 1000, buf);
          printf("   {\"name\": \"%s\", \"baseUnit\":  {\"unit\": \"%s\", \"factor\": \"%g\", \"offset\": \"%g\", \"displayUnitNumber\": \"%d\"} }",
            fmi2_import_get_unit_name(u),
            buf,
            fmi2_import_get_SI_unit_factor(u),
            fmi2_import_get_SI_unit_offset(u),
            fmi2_import_get_unit_display_unit_number(u));
          if ((i + 1) < nu) printf(",");
          printf("\n");
        }
      } 
    }
    printf(" ],\n");

    printf(" \"typeDefinitions\": [\n");
    {
      fmi2_import_type_definitions_t* td = fmi2_import_get_type_definitions(fmu);
      if(td) {
        {
          unsigned i, ntd = fmi2_import_get_type_definition_number(td);
          for(i = 0; i < ntd; i++) {
            fmi2_import_variable_typedef_t* vt = fmi2_import_get_typedef(td, i);
            if(!vt) {
              break;
            }
            readFMI2TypeDefinitions(vt);
            if ((i + 1) < ntd) printf(",\n");
          }
        }
      }
    }
    printf(" ],\n");

    printf(" \"modelVariables\": { \"scalarVariables\": [\n");
    {
      size_t nv, i;
      fmi2_import_variable_list_t* vl = fmi2_import_get_variable_list(fmu, 0);
      const fmi2_value_reference_t* vrl = fmi2_import_get_value_referece_list(vl);

      nv = fmi2_import_get_variable_list_size(vl);
      for(i = 0; i < nv; i++) {
          fmi2_import_variable_t* var = fmi2_import_get_variable(vl, i);
          if(!var) {
            printf("{\"status\": \"false\", \"statusText\": \"Something wrong with variable\"}");
            return (EXIT_FAILURE);
          } else {
            readFMI2ModelVariables(fmu, var);
            if ((i + 1) < nv) printf(",\n");
          }
      }
      fmi2_import_free_variable_list(vl);
    }
    printf(" ] }\n");

    printf("}}\n");

    fmi2_import_destroy_dllfmu(fmu);
    fmi2_import_free(fmu);
    fmi_import_free_context(context);
    return (EXIT_SUCCESS);
  } else {
    printf("{\"status\": \"false\", \"statusText\": \"Not found both FMI 1.0 and 2.0 FMU\"}\n");
    fmi_import_free_context(context);
    return (EXIT_FAILURE);
  }
}


int main(int argc, char** argv) {

  if(argc < 2) {
    printf("{\"status\": \"false\", \"statusText\": \"FMIClient <cliName>}\n");
    printf("Available cliNames:  write, read\n");
    return (EXIT_FAILURE);
  }

  char* cliName = argv[1];

  if (cliName) {

    // cliName = WRITE
    if(strcmp(cliName,"write") == 0) {
      char* fmuPath = argv[2];
      char* attributeName = argv[3];
      char* attributeValue = argv[4];

      if (!fmuPath || !attributeName || !attributeValue) {
        printf("cliName=write  Missing args!  Usage:  FMIClient write <fmuPath> <attributeName> <attributeValue> \n");
        return (EXIT_FAILURE);
      }

      printf("performing cliName=write fmuPath=%s attributeName=%s attributeValue=%s\n", fmuPath, attributeName, attributeValue);

      // Implement FMU writing function here
      return (EXIT_SUCCESS);

    // cliName = READ
    } else if(strcmp(cliName,"read") == 0) {
      char* fmuPath = argv[2];
      char* tmpPath = argv[3];

      if (!fmuPath || !tmpPath) {
        printf("cliName=set  Missing args!  Usage:  FMIClient read <fmuPath> <tmpPath> \n");
        return (EXIT_FAILURE);
      }

      read(fmuPath, tmpPath);
      return (EXIT_SUCCESS);
    } else {
      printf("unknown cliName=%s\n", cliName);
      return (EXIT_SUCCESS);
    }
  }
}
