/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define IntegerNetwork1_INDEX_JAC_D 3
  int IntegerNetwork1_functionJacD_column(void* data);
  int IntegerNetwork1_initialAnalyticJacobianD(void* data);
#if defined(__cplusplus)
}
#endif
/* D */

#if defined(__cplusplus)
extern "C" {
#endif
  #define IntegerNetwork1_INDEX_JAC_C 2
  int IntegerNetwork1_functionJacC_column(void* data);
  int IntegerNetwork1_initialAnalyticJacobianC(void* data);
#if defined(__cplusplus)
}
#endif
/* C */

#if defined(__cplusplus)
extern "C" {
#endif
  #define IntegerNetwork1_INDEX_JAC_B 1
  int IntegerNetwork1_functionJacB_column(void* data);
  int IntegerNetwork1_initialAnalyticJacobianB(void* data);
#if defined(__cplusplus)
}
#endif
/* B */

#if defined(__cplusplus)
extern "C" {
#endif
  #define IntegerNetwork1_INDEX_JAC_A 0
  int IntegerNetwork1_functionJacA_column(void* data);
  int IntegerNetwork1_initialAnalyticJacobianA(void* data);
#if defined(__cplusplus)
}
#endif
/* A */


