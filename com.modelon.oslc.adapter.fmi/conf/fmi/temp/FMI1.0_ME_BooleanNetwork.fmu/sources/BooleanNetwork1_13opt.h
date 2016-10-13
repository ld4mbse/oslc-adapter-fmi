#if defined(__cplusplus)
  extern "C" {
#endif
  int BooleanNetwork1_mayer(DATA* data, modelica_real** res, short*);
  int BooleanNetwork1_lagrange(DATA* data, modelica_real** res, short *, short *);
  int BooleanNetwork1_pickUpBoundsForInputsInOptimization(DATA* data, modelica_real* min, modelica_real* max, modelica_real*nominal, modelica_boolean *useNominal, char ** name, modelica_real * start, modelica_real * startTimeOpt);
  int BooleanNetwork1_setInputData(DATA *data);
  int BooleanNetwork1_getTimeGrid(DATA *data, modelica_integer * nsi, modelica_real**t);
#if defined(__cplusplus)
}
#endif