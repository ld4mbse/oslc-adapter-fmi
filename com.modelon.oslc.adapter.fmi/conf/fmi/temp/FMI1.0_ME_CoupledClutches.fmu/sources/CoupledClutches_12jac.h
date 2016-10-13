/* Jacobians */
static const REAL_ATTRIBUTE dummyREAL_ATTRIBUTE = omc_dummyRealAttribute;
/* Jacobian Variables */
#if defined(__cplusplus)
extern "C" {
#endif
  #define CoupledClutches_INDEX_JAC_D 3
  int CoupledClutches_functionJacD_column(void* data);
  int CoupledClutches_initialAnalyticJacobianD(void* data);
#if defined(__cplusplus)
}
#endif
/* D */

#if defined(__cplusplus)
extern "C" {
#endif
  #define CoupledClutches_INDEX_JAC_C 2
  int CoupledClutches_functionJacC_column(void* data);
  int CoupledClutches_initialAnalyticJacobianC(void* data);
#if defined(__cplusplus)
}
#endif
/* C */

#if defined(__cplusplus)
extern "C" {
#endif
  #define CoupledClutches_INDEX_JAC_B 1
  int CoupledClutches_functionJacB_column(void* data);
  int CoupledClutches_initialAnalyticJacobianB(void* data);
#if defined(__cplusplus)
}
#endif
/* B */

#if defined(__cplusplus)
extern "C" {
#endif
  #define CoupledClutches_INDEX_JAC_A 0
  int CoupledClutches_functionJacA_column(void* data);
  int CoupledClutches_initialAnalyticJacobianA(void* data);
#if defined(__cplusplus)
}
#endif
/* A */
#define $PJ3_phiSeedA data->simulationInfo.analyticJacobians[0].seedVars[0]
#define $PJ3_phiSeedA__varInfo dummyVAR_INFO
#define $PJ3_wSeedA data->simulationInfo.analyticJacobians[0].seedVars[1]
#define $PJ3_wSeedA__varInfo dummyVAR_INFO
#define $Pclutch1_phi_relSeedA data->simulationInfo.analyticJacobians[0].seedVars[2]
#define $Pclutch1_phi_relSeedA__varInfo dummyVAR_INFO
#define $Pclutch1_w_relSeedA data->simulationInfo.analyticJacobians[0].seedVars[3]
#define $Pclutch1_w_relSeedA__varInfo dummyVAR_INFO
#define $Pclutch2_phi_relSeedA data->simulationInfo.analyticJacobians[0].seedVars[4]
#define $Pclutch2_phi_relSeedA__varInfo dummyVAR_INFO
#define $Pclutch2_w_relSeedA data->simulationInfo.analyticJacobians[0].seedVars[5]
#define $Pclutch2_w_relSeedA__varInfo dummyVAR_INFO
#define $Pclutch3_phi_relSeedA data->simulationInfo.analyticJacobians[0].seedVars[6]
#define $Pclutch3_phi_relSeedA__varInfo dummyVAR_INFO
#define $Pclutch3_w_relSeedA data->simulationInfo.analyticJacobians[0].seedVars[7]
#define $Pclutch3_w_relSeedA__varInfo dummyVAR_INFO


