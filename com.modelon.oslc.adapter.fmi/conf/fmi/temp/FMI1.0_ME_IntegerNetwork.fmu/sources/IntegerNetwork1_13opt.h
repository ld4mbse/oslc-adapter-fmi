#if defined(__cplusplus)
  extern "C" {
#endif
  int IntegerNetwork1_mayer(DATA* data, modelica_real** res, short*);
  int IntegerNetwork1_lagrange(DATA* data, modelica_real** res, short *, short *);
  int IntegerNetwork1_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int IntegerNetwork1_setInputData(DATA *data);
  int IntegerNetwork1_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif