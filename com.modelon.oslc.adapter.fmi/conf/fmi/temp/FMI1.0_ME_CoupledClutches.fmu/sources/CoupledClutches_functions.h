#ifndef CoupledClutches__H
#define CoupledClutches__H
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
modelica_real omc_Modelica_Math_tempInterpol1(threadData_t *threadData, modelica_real _u, real_array _table, modelica_integer _icol);
DLLExport
modelica_metatype boxptr_Modelica_Math_tempInterpol1(threadData_t *threadData, modelica_metatype _u, modelica_metatype _table, modelica_metatype _icol);
static const MMC_DEFSTRUCTLIT(boxvar_lit_Modelica_Math_tempInterpol1,2,0) {(void*) boxptr_Modelica_Math_tempInterpol1,0}};
#define boxvar_Modelica_Math_tempInterpol1 MMC_REFSTRUCTLIT(boxvar_lit_Modelica_Math_tempInterpol1)


#ifdef __cplusplus
}
#endif
#endif

