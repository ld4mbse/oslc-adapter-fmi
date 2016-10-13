#ifndef BooleanNetwork1__H
#define BooleanNetwork1__H
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
modelica_integer omc_Modelica_Math_BooleanVectors_countTrue(threadData_t *threadData, boolean_array _b);
DLLExport
modelica_metatype boxptr_Modelica_Math_BooleanVectors_countTrue(threadData_t *threadData, modelica_metatype _b);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_BooleanVectors_countTrue,2,0) {(void*) boxptr_Modelica_Math_BooleanVectors_countTrue,0}};
#define boxvar_Modelica_Math_BooleanVectors_countTrue MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_BooleanVectors_countTrue)

DLLExport
modelica_boolean omc_Modelica_Math_BooleanVectors_allTrue(threadData_t *threadData, boolean_array _b);
DLLExport
modelica_metatype boxptr_Modelica_Math_BooleanVectors_allTrue(threadData_t *threadData, modelica_metatype _b);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_BooleanVectors_allTrue,2,0) {(void*) boxptr_Modelica_Math_BooleanVectors_allTrue,0}};
#define boxvar_Modelica_Math_BooleanVectors_allTrue MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_BooleanVectors_allTrue)

modelica_integer omc_Modelica_Blocks_Sources_BooleanTable$booleanTable_getFirstIndex(threadData_t *threadData, real_array _table, modelica_real _simulationStartTime, modelica_boolean _startValue, modelica_real *out_nextTime, modelica_boolean *out_y);
modelica_metatype boxptr_Modelica_Blocks_Sources_BooleanTable$booleanTable_getFirstIndex(threadData_t *threadData, modelica_metatype _table, modelica_metatype _simulationStartTime, modelica_metatype _startValue, modelica_metatype *out_nextTime, modelica_metatype *out_y);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Sources_BooleanTable$booleanTable_getFirstIndex,2,0) {(void*) boxptr_Modelica_Blocks_Sources_BooleanTable$booleanTable_getFirstIndex,0}};
#define boxvar_Modelica_Blocks_Sources_BooleanTable$booleanTable_getFirstIndex MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Blocks_Sources_BooleanTable$booleanTable_getFirstIndex)
 /* boxvar early */
DLLExport
modelica_boolean omc_Modelica_Math_BooleanVectors_anyTrue(threadData_t *threadData, boolean_array _b);
DLLExport
modelica_metatype boxptr_Modelica_Math_BooleanVectors_anyTrue(threadData_t *threadData, modelica_metatype _b);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_BooleanVectors_anyTrue,2,0) {(void*) boxptr_Modelica_Math_BooleanVectors_anyTrue,0}};
#define boxvar_Modelica_Math_BooleanVectors_anyTrue MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_BooleanVectors_anyTrue)

DLLExport
modelica_boolean omc_Modelica_Math_BooleanVectors_oneTrue(threadData_t *threadData, boolean_array _b);
DLLExport
modelica_metatype boxptr_Modelica_Math_BooleanVectors_oneTrue(threadData_t *threadData, modelica_metatype _b);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_BooleanVectors_oneTrue,2,0) {(void*) boxptr_Modelica_Math_BooleanVectors_oneTrue,0}};
#define boxvar_Modelica_Math_BooleanVectors_oneTrue MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_BooleanVectors_oneTrue)

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

