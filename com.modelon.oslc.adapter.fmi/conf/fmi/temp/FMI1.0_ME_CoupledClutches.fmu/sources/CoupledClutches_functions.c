#include "CoupledClutches_functions.h"
#ifdef __cplusplus
extern "C" {
#endif

#include "CoupledClutches_literals.h"
#include "CoupledClutches_includes.h"


DLLExport
modelica_real omc_Modelica_Math_tempInterpol1(threadData_t *threadData, modelica_real _u, real_array _table, modelica_integer _icol)
{
  modelica_real _y;
  modelica_integer _i;
  modelica_integer _n;
  modelica_real _u1;
  modelica_real _u2;
  modelica_real _y1;
  modelica_real _y2;
  modelica_integer tmp1;
  static int tmp2 = 0;
  modelica_real tmp3;
  _tailrecursive: OMC_LABEL_UNUSED
  tmp1 = size_of_dimension_base_array(_table, (modelica_integer) 1);
  _n = tmp1;

  if(((modelica_integer)_n <= (modelica_integer) 1))
  {
    _y = (*real_array_element_addr(&_table, 2, /* modelica_integer */ (modelica_integer) 1, /* modelica_integer */ (modelica_integer)_icol));
  }
  else
  {
    if((_u <= (*real_array_element_addr(&_table, 2, /* modelica_integer */ (modelica_integer) 1, /* modelica_integer */ (modelica_integer) 1))))
    {
      _i = (modelica_integer) 1;
    }
    else
    {
      _i = (modelica_integer) 2;

      while(1)
      {
        if(!(((modelica_integer)_i < (modelica_integer)_n) && (_u >= (*real_array_element_addr(&_table, 2, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ (modelica_integer) 1))))) break;
        _i = ((modelica_integer) 1 + (modelica_integer)_i);
      }

      _i = ((modelica_integer)_i + (modelica_integer) -1);
    }

    _u1 = (*real_array_element_addr(&_table, 2, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ (modelica_integer) 1));

    _u2 = (*real_array_element_addr(&_table, 2, /* modelica_integer */ ((modelica_integer) 1 + (modelica_integer)_i), /* modelica_integer */ (modelica_integer) 1));

    _y1 = (*real_array_element_addr(&_table, 2, /* modelica_integer */ (modelica_integer)_i, /* modelica_integer */ (modelica_integer)_icol));

    _y2 = (*real_array_element_addr(&_table, 2, /* modelica_integer */ ((modelica_integer) 1 + (modelica_integer)_i), /* modelica_integer */ (modelica_integer)_icol));

    {
      if(!(_u2 > _u1))
      {
        FILE_INFO info = {"C:/OpenModelica/trunk/build/lib/omlibrary/Modelica 3.2.1/Math/package.mo",12709,5,12709,54,0};
        omc_assert(threadData, info, MMC_STRINGDATA(_OMC_LIT2));
      }
    }

    tmp3 = (_u2 - _u1);
    if (tmp3 == 0) {throwStreamPrint(threadData, "Division by zero %s", "(u - u1) / (u2 - u1)");}
    _y = (_y1 + ((_y2 - _y1) * ((_u - _u1) / (_u2 - _u1))));
  }
  _return: OMC_LABEL_UNUSED
  return _y;
}
modelica_metatype boxptr_Modelica_Math_tempInterpol1(threadData_t *threadData, modelica_metatype _u, modelica_metatype _table, modelica_metatype _icol)
{
  modelica_real tmp1;
  modelica_integer tmp2;
  modelica_real _y;
  modelica_metatype out_y;
  tmp1 = mmc_unbox_real(_u);
  tmp2 = mmc_unbox_integer(_icol);
  _y = omc_Modelica_Math_tempInterpol1(threadData, tmp1, *((base_array_t*)_table), tmp2);
  out_y = mmc_mk_rcon(_y);
  return out_y;
}

#ifdef __cplusplus
}
#endif
