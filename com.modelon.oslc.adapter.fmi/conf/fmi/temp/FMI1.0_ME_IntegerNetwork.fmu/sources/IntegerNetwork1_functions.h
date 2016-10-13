#ifndef IntegerNetwork1__H
#define IntegerNetwork1__H
#include "meta/meta_modelica.h"
#include "util/modelica.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "simulation/simulation_runtime.h"
#ifdef __cplusplus
extern "C" {
#endif


DLLExport
modelica_integer omc_Modelica_Math_BooleanVectors_firstTrueIndex(threadData_t *threadData, boolean_array _b);
DLLExport
modelica_metatype boxptr_Modelica_Math_BooleanVectors_firstTrueIndex(threadData_t *threadData, modelica_metatype _b);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_BooleanVectors_firstTrueIndex,2,0) {(void*) boxptr_Modelica_Math_BooleanVectors_firstTrueIndex,0}};
#define boxvar_Modelica_Math_BooleanVectors_firstTrueIndex MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_BooleanVectors_firstTrueIndex)


#ifdef __cplusplus
}
#endif
#endif

