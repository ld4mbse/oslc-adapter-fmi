/* Asserts */
/* Simulation code for CoupledClutches generated by the OpenModelica Compiler 1.9.2+dev (r24999). */

#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "simulation/simulation_info_xml.h"
#include "simulation/simulation_runtime.h"
#include "util/omc_error.h"
#include "simulation/solver/model_help.h"
#include "simulation/solver/delay.h"
#include "simulation/solver/linearSystem.h"
#include "simulation/solver/nonlinearSystem.h"
#include "simulation/solver/mixedSystem.h"

#include <assert.h>
#include <string.h>

#include "CoupledClutches_functions.h"
#include "CoupledClutches_model.h"
#include "CoupledClutches_literals.h"




#if defined(HPCOM) && !defined(_OPENMP)
  #error "HPCOM requires OpenMP or the results are wrong"
#endif
#if defined(_OPENMP)
  #include <omp.h>
#else
  /* dummy omp defines */
  #define omp_get_max_threads() 1
#endif

#define threadData data->threadData

#if defined(__cplusplus)
extern "C" {
#endif


/*
 equation index: 170
 type: ALGORITHM
 
   assert(clutch1.mode >= -1 and clutch1.mode <= 3, "Variable clutch1.mode out of [min, max] interval: clutch1.mode >= -1 and clutch1.mode <= 3 has value: " + String(clutch1.mode, "d"));
 */
void CoupledClutches_eqFunction_170(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,170};
  modelica_boolean tmp99;
  modelica_boolean tmp100;
  static const MMC_DEFSTRINGLIT(tmp101,102,"Variable clutch1.mode out of [min, max] interval: clutch1.mode >= -1 and clutch1.mode <= 3 has value: ");
  modelica_string tmp102;
  static int tmp103 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp103)
  {
    tmp99 = GreaterEq((modelica_integer)$Pclutch1$Pmode,(modelica_integer) -1);
    tmp100 = LessEq((modelica_integer)$Pclutch1$Pmode,(modelica_integer) 3);
    if(!(tmp99 && tmp100))
    {
      tmp102 = modelica_integer_to_modelica_string_format((modelica_integer)$Pclutch1$Pmode, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp101),tmp102);
      FILE_INFO info = {"C:/OpenModelica/trunk/build/lib/omlibrary/Modelica 3.2.1/Mechanics/Rotational.mo",7587,7,7591,20,0};
      omc_assert_warning(info, "The following assertion has been violated at time %f\nclutch1.mode >= -1 and clutch1.mode <= 3", time);
      omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      tmp103 = 1;
    }
  }
  TRACE_POP
}
/*
 equation index: 171
 type: ALGORITHM
 
   assert(clutch2.mode >= -1 and clutch2.mode <= 3, "Variable clutch2.mode out of [min, max] interval: clutch2.mode >= -1 and clutch2.mode <= 3 has value: " + String(clutch2.mode, "d"));
 */
void CoupledClutches_eqFunction_171(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,171};
  modelica_boolean tmp104;
  modelica_boolean tmp105;
  static const MMC_DEFSTRINGLIT(tmp106,102,"Variable clutch2.mode out of [min, max] interval: clutch2.mode >= -1 and clutch2.mode <= 3 has value: ");
  modelica_string tmp107;
  static int tmp108 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp108)
  {
    tmp104 = GreaterEq((modelica_integer)$Pclutch2$Pmode,(modelica_integer) -1);
    tmp105 = LessEq((modelica_integer)$Pclutch2$Pmode,(modelica_integer) 3);
    if(!(tmp104 && tmp105))
    {
      tmp107 = modelica_integer_to_modelica_string_format((modelica_integer)$Pclutch2$Pmode, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp106),tmp107);
      FILE_INFO info = {"C:/OpenModelica/trunk/build/lib/omlibrary/Modelica 3.2.1/Mechanics/Rotational.mo",7587,7,7591,20,0};
      omc_assert_warning(info, "The following assertion has been violated at time %f\nclutch2.mode >= -1 and clutch2.mode <= 3", time);
      omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      tmp108 = 1;
    }
  }
  TRACE_POP
}
/*
 equation index: 172
 type: ALGORITHM
 
   assert(clutch3.mode >= -1 and clutch3.mode <= 3, "Variable clutch3.mode out of [min, max] interval: clutch3.mode >= -1 and clutch3.mode <= 3 has value: " + String(clutch3.mode, "d"));
 */
void CoupledClutches_eqFunction_172(DATA *data)
{
  TRACE_PUSH
  const int equationIndexes[2] = {1,172};
  modelica_boolean tmp109;
  modelica_boolean tmp110;
  static const MMC_DEFSTRINGLIT(tmp111,102,"Variable clutch3.mode out of [min, max] interval: clutch3.mode >= -1 and clutch3.mode <= 3 has value: ");
  modelica_string tmp112;
  static int tmp113 = 0;
  modelica_metatype tmpMeta[1] __attribute__((unused)) = {0};
  if(!tmp113)
  {
    tmp109 = GreaterEq((modelica_integer)$Pclutch3$Pmode,(modelica_integer) -1);
    tmp110 = LessEq((modelica_integer)$Pclutch3$Pmode,(modelica_integer) 3);
    if(!(tmp109 && tmp110))
    {
      tmp112 = modelica_integer_to_modelica_string_format((modelica_integer)$Pclutch3$Pmode, (modelica_string) mmc_strings_len1[100]);
      tmpMeta[0] = stringAppend(MMC_REFSTRINGLIT(tmp111),tmp112);
      FILE_INFO info = {"C:/OpenModelica/trunk/build/lib/omlibrary/Modelica 3.2.1/Mechanics/Rotational.mo",7587,7,7591,20,0};
      omc_assert_warning(info, "The following assertion has been violated at time %f\nclutch3.mode >= -1 and clutch3.mode <= 3", time);
      omc_assert_warning_withEquationIndexes(info, equationIndexes, MMC_STRINGDATA(tmpMeta[0]));
      tmp113 = 1;
    }
  }
  TRACE_POP
}
/* function to check assert after a step is done */
int CoupledClutches_checkForAsserts(DATA *data)
{
  TRACE_PUSH

  CoupledClutches_eqFunction_170(data);

  CoupledClutches_eqFunction_171(data);

  CoupledClutches_eqFunction_172(data);
  
  TRACE_POP
  return 0;
}

#if defined(__cplusplus)
}
#endif
