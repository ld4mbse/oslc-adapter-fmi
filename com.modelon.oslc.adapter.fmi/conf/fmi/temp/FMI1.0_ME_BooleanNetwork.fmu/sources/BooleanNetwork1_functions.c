#include "BooleanNetwork1_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "BooleanNetwork1_literals.h"
#include "BooleanNetwork1_includes.h"


DLLExport
modelica_integer omc_Modelica_Math_BooleanVectors_countTrue(threadData_t *threadData, boolean_array _b)
{
  modelica_integer _n;
  modelica_integer tmp1;
  _tailrecursive: OMC_LABEL_UNUSED
  {
    modelica_integer _$tmpVar3;
    modelica_integer _$tmpVar2;
    int tmp2;
    integer_array i_loopVar;
    int tmp3;
    modelica_integer tmp4;
    integer_array tmp5;
    modelica_integer _i;
    tmp4 = size_of_dimension_base_array(_b, (modelica_integer) 1);
    create_integer_array_from_range(&tmp5, (modelica_integer) 1, 1, tmp4);
    i_loopVar = tmp5;
    tmp3 = 1;
    _$tmpVar3 = (modelica_integer) 0; /* defaultValue */
    while(1) {
      tmp2 = 1;
      while(tmp3 <= size_of_dimension_base_array(i_loopVar, 1)) {
        _i = *(integer_array_element_addr1(&i_loopVar, 1, tmp3++));
        if(1) { /* found non-guarded */
          tmp2--;
          break;
        }
      }
      if (tmp2 == 0) {
        _$tmpVar2 = ((*boolean_array_element_addr(&_b, 1, /* modelica_integer */ (modelica_integer)_i))?(modelica_integer) 1:(modelica_integer) 0);
        _$tmpVar3 = ((modelica_integer)_$tmpVar3 + (modelica_integer)_$tmpVar2);
      } else if (tmp2 == 1) {
        break;
      } else {
        MMC_THROW_INTERNAL();
      }
    }
    tmp1 = _$tmpVar3;
  }
  _n = tmp1;
  _return: OMC_LABEL_UNUSED
  return _n;
}
modelica_metatype boxptr_Modelica_Math_BooleanVectors_countTrue(threadData_t *threadData, modelica_metatype _b)
{
  modelica_integer _n;
  modelica_metatype out_n;
  _n = omc_Modelica_Math_BooleanVectors_countTrue(threadData, *((base_array_t*)_b));
  out_n = mmc_mk_icon(_n);
  return out_n;
}
DLLExport
modelica_boolean omc_Modelica_Math_BooleanVectors_allTrue(threadData_t *threadData, boolean_array _b)
{
  modelica_boolean _result;
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  modelica_integer tmp5;
  _tailrecursive: OMC_LABEL_UNUSED
  tmp1 = size_of_dimension_base_array(_b, (modelica_integer) 1);
  _result = (tmp1 > (modelica_integer) 0);

  tmp5 = size_of_dimension_base_array(_b, (modelica_integer) 1);
  tmp2 = (modelica_integer) 1; tmp3 = 1; tmp4 = tmp5;
  if(!tmp3)
  {
    FILE_INFO info = omc_dummyFileInfo;
    omc_assert(threadData, info, "assertion range step != 0 failed");
  }
  else if(!(((tmp3 > 0) && (tmp2 > tmp4)) || ((tmp3 < 0) && (tmp2 < tmp4))))
  {
    modelica_integer _i;
    for(_i = (modelica_integer) 1; in_range_integer(_i, tmp2, tmp4); _i += tmp3)
    {
      _result = (_result && (*boolean_array_element_addr(&_b, 1, /* modelica_integer */ (modelica_integer)_i)));
    }
  }
  _return: OMC_LABEL_UNUSED
  return _result;
}
modelica_metatype boxptr_Modelica_Math_BooleanVectors_allTrue(threadData_t *threadData, modelica_metatype _b)
{
  modelica_boolean _result;
  modelica_metatype out_result;
  _result = omc_Modelica_Math_BooleanVectors_allTrue(threadData, *((base_array_t*)_b));
  out_result = mmc_mk_icon(_result);
  return out_result;
}
modelica_integer omc_Modelica_Blocks_Sources_BooleanTable$booleanTable_getFirstIndex(threadData_t *threadData, real_array _table, modelica_real _simulationStartTime, modelica_boolean _startValue, modelica_real *out_nextTime, modelica_boolean *out_y)
{
  modelica_integer _index;
  modelica_real _nextTime;
  modelica_boolean _y;
  modelica_integer _j;
  modelica_integer _n;
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_string tmp4;
  modelica_string tmp5;
  modelica_string tmp6;
  modelica_string tmp7;
  static int tmp8 = 0;
  modelica_integer tmp9;
  modelica_integer tmp10;
  modelica_integer tmp11;
  modelica_metatype tmpMeta[7] __attribute__((unused)) = {0};
  _tailrecursive: OMC_LABEL_UNUSED
  tmp1 = size_of_dimension_base_array(_table, (modelica_integer) 1);
  _n = tmp1;
  tmp2 = size_of_dimension_base_array(_table, (modelica_integer) 1);
  if((tmp2 == (modelica_integer) 0))
  {
    _index = (modelica_integer) 0;

    _nextTime = 9.999999999999999e+059;

    _y = _startValue;
  }
  else
  {
    tmp3 = size_of_dimension_base_array(_table, (modelica_integer) 1);
    if((tmp3 == (modelica_integer) 1))
    {
      _index = (modelica_integer) 1;

      if(((*real_array_element_addr(&_table, 1, /* modelica_integer */ (modelica_integer) 1)) > _simulationStartTime))
      {
        _nextTime = (*real_array_element_addr(&_table, 1, /* modelica_integer */ (modelica_integer) 1));

        _y = _startValue;
      }
      else
      {
        _nextTime = 9.999999999999999e+059;

        _y = (!_startValue);
      }
    }
    else
    {
      tmp9 = (modelica_integer) 2; tmp10 = 1; tmp11 = (modelica_integer)_n;
      if(!tmp10)
      {
        FILE_INFO info = omc_dummyFileInfo;
        omc_assert(threadData, info, "assertion range step != 0 failed");
      }
      else if(!(((tmp10 > 0) && (tmp9 > tmp11)) || ((tmp10 < 0) && (tmp9 < tmp11))))
      {
        modelica_integer _i;
        for(_i = (modelica_integer) 2; in_range_integer(_i, tmp9, tmp11); _i += tmp10)
        {
          {
            if(!((*real_array_element_addr(&_table, 1, /* modelica_integer */ (modelica_integer)_i)) > (*real_array_element_addr(&_table, 1, /* modelica_integer */ ((modelica_integer)_i + (modelica_integer) -1)))))
            {
              tmp4 = modelica_integer_to_modelica_string(((modelica_integer)_i + (modelica_integer) -1), (modelica_integer) 0, 1);
              tmpMeta[0] = stringAppend(_OMC_LIT2,tmp4);
              tmpMeta[1] = stringAppend(tmpMeta[0],_OMC_LIT3);
              tmp5 = modelica_real_to_modelica_string((*real_array_element_addr(&_table, 1, /* modelica_integer */ ((modelica_integer)_i + (modelica_integer) -1))), (modelica_integer) 0, 1, (modelica_integer) 6);
              tmpMeta[2] = stringAppend(tmpMeta[1],tmp5);
              tmpMeta[3] = stringAppend(tmpMeta[2],_OMC_LIT4);
              tmp6 = modelica_integer_to_modelica_string((modelica_integer)_i, (modelica_integer) 0, 1);
              tmpMeta[4] = stringAppend(tmpMeta[3],tmp6);
              tmpMeta[5] = stringAppend(tmpMeta[4],_OMC_LIT3);
              tmp7 = modelica_real_to_modelica_string((*real_array_element_addr(&_table, 1, /* modelica_integer */ (modelica_integer)_i)), (modelica_integer) 0, 1, (modelica_integer) 6);
              tmpMeta[6] = stringAppend(tmpMeta[5],tmp7);
              FILE_INFO info = {"C:/OpenModelica/trunk/build/lib/omlibrary/Modelica 3.2.1/Blocks/Sources.mo",3003,11,3006,51,0};
              omc_assert(threadData, info, MMC_STRINGDATA(tmpMeta[6]));
            }
          }
        }
      }

      _j = (modelica_integer) 1;

      _y = _startValue;

      while(1)
      {
        if(!(((modelica_integer)_j <= (modelica_integer)_n) && ((*real_array_element_addr(&_table, 1, /* modelica_integer */ (modelica_integer)_j)) <= _simulationStartTime))) break;
        _y = (!_y);

        _j = ((modelica_integer) 1 + (modelica_integer)_j);
      }

      if(((modelica_integer)_j > (modelica_integer)_n))
      {
        _nextTime = 9.999999999999999e+059;
      }
      else
      {
        _nextTime = (*real_array_element_addr(&_table, 1, /* modelica_integer */ (modelica_integer)_j));
      }

      _index = (modelica_integer)_j;
    }
  }
  _return: OMC_LABEL_UNUSED
  if (out_nextTime) { *out_nextTime = _nextTime; }
  if (out_y) { *out_y = _y; }
  return _index;
}
modelica_metatype boxptr_Modelica_Blocks_Sources_BooleanTable$booleanTable_getFirstIndex(threadData_t *threadData, modelica_metatype _table, modelica_metatype _simulationStartTime, modelica_metatype _startValue, modelica_metatype *out_nextTime, modelica_metatype *out_y)
{
  modelica_real tmp1;
  modelica_integer tmp2;
  modelica_real _nextTime;
  modelica_boolean _y;
  modelica_integer _index;
  modelica_metatype out_index;
  tmp1 = mmc_unbox_real(_simulationStartTime);
  tmp2 = mmc_unbox_integer(_startValue);
  _index = omc_Modelica_Blocks_Sources_BooleanTable$booleanTable_getFirstIndex(threadData, *((base_array_t*)_table), tmp1, tmp2, &_nextTime, &_y);
  out_index = mmc_mk_icon(_index);
  if (out_nextTime) { *out_nextTime = mmc_mk_rcon(_nextTime); }
  if (out_y) { *out_y = mmc_mk_icon(_y); }
  return out_index;
}
DLLExport
modelica_boolean omc_Modelica_Math_BooleanVectors_anyTrue(threadData_t *threadData, boolean_array _b)
{
  modelica_boolean _result;
  modelica_integer tmp1;
  modelica_integer tmp2;
  modelica_integer tmp3;
  modelica_integer tmp4;
  _tailrecursive: OMC_LABEL_UNUSED
  _result = 0;

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
      _result = (_result || (*boolean_array_element_addr(&_b, 1, /* modelica_integer */ (modelica_integer)_i)));
    }
  }
  _return: OMC_LABEL_UNUSED
  return _result;
}
modelica_metatype boxptr_Modelica_Math_BooleanVectors_anyTrue(threadData_t *threadData, modelica_metatype _b)
{
  modelica_boolean _result;
  modelica_metatype out_result;
  _result = omc_Modelica_Math_BooleanVectors_anyTrue(threadData, *((base_array_t*)_b));
  out_result = mmc_mk_icon(_result);
  return out_result;
}
DLLExport
modelica_boolean omc_Modelica_Math_BooleanVectors_oneTrue(threadData_t *threadData, boolean_array _b)
{
  modelica_boolean _result;
  _tailrecursive: OMC_LABEL_UNUSED
  _result = (omc_Modelica_Math_BooleanVectors_countTrue(threadData, _b) == (modelica_integer) 1);
  _return: OMC_LABEL_UNUSED
  return _result;
}
modelica_metatype boxptr_Modelica_Math_BooleanVectors_oneTrue(threadData_t *threadData, modelica_metatype _b)
{
  modelica_boolean _result;
  modelica_metatype out_result;
  _result = omc_Modelica_Math_BooleanVectors_oneTrue(threadData, *((base_array_t*)_b));
  out_result = mmc_mk_icon(_result);
  return out_result;
}
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
