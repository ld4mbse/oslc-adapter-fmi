#include "IntegerNetwork1_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "IntegerNetwork1_literals.h"
#include "IntegerNetwork1_includes.h"


DLLExport
modelica_integer omc_Modelica_Math_BooleanVectors_firstTrueIndex(threadData_t *threadData, boolean_array _b)
{
  modelica_integer _index;
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  _tailrecursive: OMC_LABEL_UNUSED
  _index = (modelica_integer) 0;

  tmp4 = size_of_dimension_base_array(_b, (modelica_integer) 1);
  tmp1 = (modelica_integer) 1; tmp2 = 1; tmp3 = tmp4;
  if(!tmp2)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert(threadData, info, "assertion range step != 0 failed");
  }
  else if(!(((tmp2 > 0) && (tmp1 > tmp3)) || ((tmp2 < 0) && (tmp1 < tmp3))))
  {
    modelica_integer _i;
    for(_i = (modelica_integer) 1; in_range_integer(_i, tmp1, tmp3); _i += tmp2)
    {
      if((*boolean_array_element_addr(&_b, 1, /* modelica_integer */ (modelica_integer)_i)))
      {
        _index = (modelica_integer)_i;

        goto _return;
      }
    }
  }
  _return: OMC_LABEL_UNUSED
  return _index;
}
modelica_metatype boxptr_Modelica_Math_BooleanVectors_firstTrueIndex(threadData_t *threadData, modelica_metatype _b)
{
  modelica_integer _index;
  modelica_metatype out_index;
  _index = omc_Modelica_Math_BooleanVectors_firstTrueIndex(threadData, *((base_array_t*)_b));
  out_index = mmc_mk_icon(_index);
  return out_index;
}

#ifdef __cplusplus
}
#endif
