/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define BooleanNetwork1_INDEX_JAC_D 3
  int BooleanNetwork1_functionJacD_column(void* data);
  int BooleanNetwork1_initialAnalyticJacobianD(void* data);
#if defined(__cplusplus)
}
#endif
/* D */

#if defined(__cplusplus)
extern "C" {
#endif
  #define BooleanNetwork1_INDEX_JAC_C 2
  int BooleanNetwork1_functionJacC_column(void* data);
  int BooleanNetwork1_initialAnalyticJacobianC(void* data);
#if defined(__cplusplus)
}
#endif
/* C */

#if defined(__cplusplus)
extern "C" {
#endif
  #define BooleanNetwork1_INDEX_JAC_B 1
  int BooleanNetwork1_functionJacB_column(void* data);
  int BooleanNetwork1_initialAnalyticJacobianB(void* data);
#if defined(__cplusplus)
}
#endif
/* B */

#if defined(__cplusplus)
extern "C" {
#endif
  #define BooleanNetwork1_INDEX_JAC_A 0
  int BooleanNetwork1_functionJacA_column(void* data);
  int BooleanNetwork1_initialAnalyticJacobianA(void* data);
#if defined(__cplusplus)
}
#endif
/* A */


