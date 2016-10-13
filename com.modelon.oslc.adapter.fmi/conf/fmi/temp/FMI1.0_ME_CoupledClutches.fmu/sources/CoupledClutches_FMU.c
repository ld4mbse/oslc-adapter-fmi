
// define class name and unique id
#define MODEL_IDENTIFIER CoupledClutches
#define MODEL_GUID "{8c4e810f-3df3-4a00-8276-176fa3c9f9e0}"

// include fmu header files, typedefs and macros
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "util/omc_error.h"
#include "CoupledClutches_functions.h"
#include "CoupledClutches_literals.h"
#include "simulation/solver/initialization/initialization.h"
#include "simulation/solver/events.h"
#include "fmu1_model_interface.h"

#ifdef __cplusplus
extern "C" {
#endif

void setStartValues(ModelInstance *comp);
void setDefaultStartValues(ModelInstance *comp);
void eventUpdate(ModelInstance* comp, fmiEventInfo* eventInfo);
fmiReal getReal(ModelInstance* comp, const fmiValueReference vr);
fmiStatus setReal(ModelInstance* comp, const fmiValueReference vr, const fmiReal value);
fmiInteger getInteger(ModelInstance* comp, const fmiValueReference vr);
fmiStatus setInteger(ModelInstance* comp, const fmiValueReference vr, const fmiInteger value);
fmiBoolean getBoolean(ModelInstance* comp, const fmiValueReference vr);
fmiStatus setBoolean(ModelInstance* comp, const fmiValueReference vr, const fmiBoolean value);
fmiString getString(ModelInstance* comp, const fmiValueReference vr);
fmiStatus setString(ModelInstance* comp, const fmiValueReference vr, fmiString value);
fmiStatus setExternalFunction(ModelInstance* c, const fmiValueReference vr, const void* value);

// define model size
#define NUMBER_OF_STATES 8
#define NUMBER_OF_EVENT_INDICATORS 18
#define NUMBER_OF_REALS 151
#define NUMBER_OF_INTEGERS 10
#define NUMBER_OF_STRINGS 0
#define NUMBER_OF_BOOLEANS 16
#define NUMBER_OF_EXTERNALFUNCTIONS 0

// define variable data for model
#define $PJ3$Pphi_ 0 // "Absolute rotation angle of component"
#define $PJ3$Pw_ 1 // "Absolute angular velocity of component (= der(phi))"
#define $Pclutch1$Pphi_rel_ 2 // "Relative rotation angle (= flange_b.phi - flange_a.phi)"
#define $Pclutch1$Pw_rel_ 3 // "Relative angular velocity (= der(phi_rel))"
#define $Pclutch2$Pphi_rel_ 4 // "Relative rotation angle (= flange_b.phi - flange_a.phi)"
#define $Pclutch2$Pw_rel_ 5 // "Relative angular velocity (= der(phi_rel))"
#define $Pclutch3$Pphi_rel_ 6 // "Relative rotation angle (= flange_b.phi - flange_a.phi)"
#define $Pclutch3$Pw_rel_ 7 // "Relative angular velocity (= der(phi_rel))"
#define $P$DER$PJ3$Pphi_ 8 // "Absolute rotation angle of component"
#define $P$DER$PJ3$Pw_ 9 // "Absolute angular velocity of component (= der(phi))"
#define $P$DER$Pclutch1$Pphi_rel_ 10 // "Relative rotation angle (= flange_b.phi - flange_a.phi)"
#define $P$DER$Pclutch1$Pw_rel_ 11 // "Relative angular velocity (= der(phi_rel))"
#define $P$DER$Pclutch2$Pphi_rel_ 12 // "Relative rotation angle (= flange_b.phi - flange_a.phi)"
#define $P$DER$Pclutch2$Pw_rel_ 13 // "Relative angular velocity (= der(phi_rel))"
#define $P$DER$Pclutch3$Pphi_rel_ 14 // "Relative rotation angle (= flange_b.phi - flange_a.phi)"
#define $P$DER$Pclutch3$Pw_rel_ 15 // "Relative angular velocity (= der(phi_rel))"
#define $PJ1$Pa_ 16 // "Absolute angular acceleration of component (= der(w))"
#define $PJ1$Pphi_ 17 // "Absolute rotation angle of component"
#define $PJ1_w1_ 18 
#define $PJ2$Pa_ 19 // "Absolute angular acceleration of component (= der(w))"
#define $PJ2$Pphi_ 20 // "Absolute rotation angle of component"
#define $PJ2_w1_ 21 
#define $PJ3$Pa_ 22 // "Absolute angular acceleration of component (= der(w))"
#define $PJ3_w1_ 23 
#define $PJ4$Pa_ 24 // "Absolute angular acceleration of component (= der(w))"
#define $PJ4$Pflange_b$Ptau_ 25 // "Cut torque in the flange"
#define $PJ4$Pphi_ 26 // "Absolute rotation angle of component"
#define $PJ4_w1_ 27 
#define $Pclutch1$Pa_relfric_ 28 // "Relative angular acceleration between frictional surfaces"
#define $Pclutch1$Pf_normalized_ 29 // "Normalized force signal 0..1 (normal force = fn_max*f_normalized; clutch is engaged if > 0)"
#define $Pclutch1$Pfn_ 30 // "Normal force (fn=fn_max*f_normalized)"
#define $Pclutch1$PlossPower_ 31 // "Loss power leaving component via heatPort (> 0, if heat is flowing out of component)"
#define $Pclutch1$Pmue0_ 32 // "Friction coefficient for w=0 and forward sliding"
#define $Pclutch1$Psa_ 33 // "Path parameter of friction characteristic tau = f(a_relfric)"
#define $Pclutch1$Ptau_ 34 // "Torque between flanges (= flange_b.tau)"
#define $Pclutch1$Ptau0_ 35 // "Friction torque for w=0 and forward sliding"
#define $Pclutch1$Ptau0_max_ 36 // "Maximum friction torque for w=0 and locked"
#define $Pclutch2$Pa_relfric_ 37 // "Relative angular acceleration between frictional surfaces"
#define $Pclutch2$Pf_normalized_ 38 // "Normalized force signal 0..1 (normal force = fn_max*f_normalized; clutch is engaged if > 0)"
#define $Pclutch2$Pfn_ 39 // "Normal force (fn=fn_max*f_normalized)"
#define $Pclutch2$PlossPower_ 40 // "Loss power leaving component via heatPort (> 0, if heat is flowing out of component)"
#define $Pclutch2$Pmue0_ 41 // "Friction coefficient for w=0 and forward sliding"
#define $Pclutch2$Psa_ 42 // "Path parameter of friction characteristic tau = f(a_relfric)"
#define $Pclutch2$Ptau_ 43 // "Torque between flanges (= flange_b.tau)"
#define $Pclutch2$Ptau0_ 44 // "Friction torque for w=0 and forward sliding"
#define $Pclutch2$Ptau0_max_ 45 // "Maximum friction torque for w=0 and locked"
#define $Pclutch3$Pa_relfric_ 46 // "Relative angular acceleration between frictional surfaces"
#define $Pclutch3$Pfn_ 47 // "Normal force (fn=fn_max*f_normalized)"
#define $Pclutch3$PlossPower_ 48 // "Loss power leaving component via heatPort (> 0, if heat is flowing out of component)"
#define $Pclutch3$Pmue0_ 49 // "Friction coefficient for w=0 and forward sliding"
#define $Pclutch3$Psa_ 50 // "Path parameter of friction characteristic tau = f(a_relfric)"
#define $Pclutch3$Ptau_ 51 // "Torque between flanges (= flange_b.tau)"
#define $Pclutch3$Ptau0_ 52 // "Friction torque for w=0 and forward sliding"
#define $Pclutch3$Ptau0_max_ 53 // "Maximum friction torque for w=0 and locked"
#define $Psin1$Py_ 54 // "Connector of Real output signal"
#define $Pstep2_ 55 
#define $PJ1$PJ_ 56 // "Moment of inertia"
#define $PJ2$PJ_ 57 // "Moment of inertia"
#define $PJ3$PJ_ 58 // "Moment of inertia"
#define $PJ4$PJ_ 59 // "Moment of inertia"
#define $PT2_ 60 // "Time when clutch2 is invoked"
#define $PT3_ 61 // "Time when clutch3 is invoked"
#define $Pclutch1$Pcgeo_ 62 // "Geometry constant containing friction distribution assumption"
#define $Pclutch1$Pfn_max_ 63 // "Maximum normal force"
#define $Pclutch1$Pmue_pos$lB1$c1$rB_ 64 // "[w,mue] positive sliding friction coefficient (w_rel>=0)"
#define $Pclutch1$Pmue_pos$lB1$c2$rB_ 65 // "[w,mue] positive sliding friction coefficient (w_rel>=0)"
#define $Pclutch1$Ppeak_ 66 // "peak*mue_pos[1,2] = maximum value of mue for w_rel==0"
#define $Pclutch1$Pphi_nominal_ 67 // "Nominal value of phi_rel (used for scaling)"
#define $Pclutch1$Pw_small_ 68 // "Relative angular velocity near to zero if jumps due to a reinit(..) of the velocity can occur (set to low value only if such impulses can occur)"
#define $Pclutch2$Pcgeo_ 69 // "Geometry constant containing friction distribution assumption"
#define $Pclutch2$Pfn_max_ 70 // "Maximum normal force"
#define $Pclutch2$Pmue_pos$lB1$c1$rB_ 71 // "[w,mue] positive sliding friction coefficient (w_rel>=0)"
#define $Pclutch2$Pmue_pos$lB1$c2$rB_ 72 // "[w,mue] positive sliding friction coefficient (w_rel>=0)"
#define $Pclutch2$Ppeak_ 73 // "peak*mue_pos[1,2] = maximum value of mue for w_rel==0"
#define $Pclutch2$Pphi_nominal_ 74 // "Nominal value of phi_rel (used for scaling)"
#define $Pclutch2$Pw_small_ 75 // "Relative angular velocity near to zero if jumps due to a reinit(..) of the velocity can occur (set to low value only if such impulses can occur)"
#define $Pclutch3$Pcgeo_ 76 // "Geometry constant containing friction distribution assumption"
#define $Pclutch3$Pfn_max_ 77 // "Maximum normal force"
#define $Pclutch3$Pmue_pos$lB1$c1$rB_ 78 // "[w,mue] positive sliding friction coefficient (w_rel>=0)"
#define $Pclutch3$Pmue_pos$lB1$c2$rB_ 79 // "[w,mue] positive sliding friction coefficient (w_rel>=0)"
#define $Pclutch3$Ppeak_ 80 // "peak*mue_pos[1,2] = maximum value of mue for w_rel==0"
#define $Pclutch3$Pphi_nominal_ 81 // "Nominal value of phi_rel (used for scaling)"
#define $Pclutch3$Pw_small_ 82 // "Relative angular velocity near to zero if jumps due to a reinit(..) of the velocity can occur (set to low value only if such impulses can occur)"
#define $Pfixed$Pphi0_ 83 // "Fixed offset angle of housing"
#define $PfreqHz_ 84 // "Frequency of sine function to invoke clutch1"
#define $Psin1$Pamplitude_ 85 // "Amplitude of sine wave"
#define $Psin1$PfreqHz_ 86 // "Frequency of sine wave"
#define $Psin1$Poffset_ 87 // "Offset of output signal"
#define $Psin1$Pphase_ 88 // "Phase of sine wave"
#define $Psin1$PstartTime_ 89 // "Output = offset for time < startTime"
#define $Psin2$Pamplitude_ 90 // "Amplitude of sine wave"
#define $Psin2$PfreqHz_ 91 // "Frequency of sine wave"
#define $Psin2$Poffset_ 92 // "Offset of output signal"
#define $Psin2$Pphase_ 93 // "Phase of sine wave"
#define $Psin2$PstartTime_ 94 // "Output = offset for time < startTime"
#define $Pstep1$Pheight_ 95 // "Height of step"
#define $Pstep1$Poffset_ 96 // "Offset of output signal y"
#define $Pstep1$PstartTime_ 97 // "Output y = offset for time < startTime"
#define $P$DER$PJ1$Pphi_ 98 // "Absolute rotation angle of component"
#define $P$DER$PJ1$Pw_ 99 // "Absolute angular velocity of component (= der(phi))"
#define $P$DER$PJ2$Pphi_ 100 // "Absolute rotation angle of component"
#define $P$DER$PJ2$Pw_ 101 // "Absolute angular velocity of component (= der(phi))"
#define $P$DER$PJ4$Pphi_ 102 // "Absolute rotation angle of component"
#define $P$DER$PJ4$Pw_ 103 // "Absolute angular velocity of component (= der(phi))"
#define $PJ1$Pflange_a$Pphi_ 104 // "Absolute rotation angle of flange"
#define $PJ1$Pflange_a$Ptau_ 105 // "Cut torque in the flange"
#define $PJ1$Pflange_b$Pphi_ 106 // "Absolute rotation angle of flange"
#define $PJ1$Pflange_b$Ptau_ 107 // "Cut torque in the flange"
#define $PJ1$Pw_ 108 // "Absolute angular velocity of component (= der(phi))"
#define $PJ2$Pflange_a$Pphi_ 109 // "Absolute rotation angle of flange"
#define $PJ2$Pflange_a$Ptau_ 110 // "Cut torque in the flange"
#define $PJ2$Pflange_b$Pphi_ 111 // "Absolute rotation angle of flange"
#define $PJ2$Pflange_b$Ptau_ 112 // "Cut torque in the flange"
#define $PJ2$Pw_ 113 // "Absolute angular velocity of component (= der(phi))"
#define $PJ3$Pflange_a$Pphi_ 114 // "Absolute rotation angle of flange"
#define $PJ3$Pflange_a$Ptau_ 115 // "Cut torque in the flange"
#define $PJ3$Pflange_b$Pphi_ 116 // "Absolute rotation angle of flange"
#define $PJ3$Pflange_b$Ptau_ 117 // "Cut torque in the flange"
#define $PJ4$Pflange_a$Pphi_ 118 // "Absolute rotation angle of flange"
#define $PJ4$Pflange_a$Ptau_ 119 // "Cut torque in the flange"
#define $PJ4$Pflange_b$Pphi_ 120 // "Absolute rotation angle of flange"
#define $PJ4$Pw_ 121 // "Absolute angular velocity of component (= der(phi))"
#define $Pclutch1$Pa_rel_ 122 // "Relative angular acceleration (= der(w_rel))"
#define $Pclutch1$Pflange_a$Pphi_ 123 // "Absolute rotation angle of flange"
#define $Pclutch1$Pflange_a$Ptau_ 124 // "Cut torque in the flange"
#define $Pclutch1$Pflange_b$Pphi_ 125 // "Absolute rotation angle of flange"
#define $Pclutch1$Pflange_b$Ptau_ 126 // "Cut torque in the flange"
#define $Pclutch1$Pw_relfric_ 127 // "Relative angular velocity between frictional surfaces"
#define $Pclutch2$Pa_rel_ 128 // "Relative angular acceleration (= der(w_rel))"
#define $Pclutch2$Pflange_a$Pphi_ 129 // "Absolute rotation angle of flange"
#define $Pclutch2$Pflange_a$Ptau_ 130 // "Cut torque in the flange"
#define $Pclutch2$Pflange_b$Pphi_ 131 // "Absolute rotation angle of flange"
#define $Pclutch2$Pflange_b$Ptau_ 132 // "Cut torque in the flange"
#define $Pclutch2$Pw_relfric_ 133 // "Relative angular velocity between frictional surfaces"
#define $Pclutch3$Pa_rel_ 134 // "Relative angular acceleration (= der(w_rel))"
#define $Pclutch3$Pf_normalized_ 135 // "Normalized force signal 0..1 (normal force = fn_max*f_normalized; clutch is engaged if > 0)"
#define $Pclutch3$Pflange_a$Pphi_ 136 // "Absolute rotation angle of flange"
#define $Pclutch3$Pflange_a$Ptau_ 137 // "Cut torque in the flange"
#define $Pclutch3$Pflange_b$Pphi_ 138 // "Absolute rotation angle of flange"
#define $Pclutch3$Pflange_b$Ptau_ 139 // "Cut torque in the flange"
#define $Pclutch3$Pw_relfric_ 140 // "Relative angular velocity between frictional surfaces"
#define $Pfixed$Pflange$Pphi_ 141 // "Absolute rotation angle of flange"
#define $Pfixed$Pflange$Ptau_ 142 // "Cut torque in the flange"
#define $Psin2$Py_ 143 // "Connector of Real output signal"
#define $Pstep1$Py_ 144 // "Connector of Real output signal"
#define $Ptorque$Pflange$Pphi_ 145 // "Absolute rotation angle of flange"
#define $Ptorque$Pflange$Ptau_ 146 // "Cut torque in the flange"
#define $Ptorque$Pphi_support_ 147 // "Absolute angle of support flange"
#define $Ptorque$Psupport$Pphi_ 148 // "Absolute rotation angle of the support/housing"
#define $Ptorque$Psupport$Ptau_ 149 // "Reaction torque in the support/housing"
#define $Ptorque$Ptau_ 150 // "Accelerating torque acting at flange (= -flange.tau)"
#define $Pclutch1$Pmode_ 0 
#define $Pclutch2$Pmode_ 1 
#define $Pclutch3$Pmode_ 2 
#define $PJ1$PstateSelect_ 3 // "Priority to use phi and w as states"
#define $PJ2$PstateSelect_ 4 // "Priority to use phi and w as states"
#define $PJ3$PstateSelect_ 5 // "Priority to use phi and w as states"
#define $PJ4$PstateSelect_ 6 // "Priority to use phi and w as states"
#define $Pclutch1$PstateSelect_ 7 // "Priority to use phi_rel and w_rel as states"
#define $Pclutch2$PstateSelect_ 8 // "Priority to use phi_rel and w_rel as states"
#define $Pclutch3$PstateSelect_ 9 // "Priority to use phi_rel and w_rel as states"
#define $Pclutch1$Pfree_ 0 // "true, if frictional element is not active"
#define $Pclutch1$Plocked_ 1 // "true, if w_rel=0 and not sliding"
#define $Pclutch1$PstartBackward_ 2 // "true, if w_rel=0 and start of backward sliding"
#define $Pclutch1$PstartForward_ 3 // "true, if w_rel=0 and start of forward sliding"
#define $Pclutch2$Pfree_ 4 // "true, if frictional element is not active"
#define $Pclutch2$Plocked_ 5 // "true, if w_rel=0 and not sliding"
#define $Pclutch2$PstartBackward_ 6 // "true, if w_rel=0 and start of backward sliding"
#define $Pclutch2$PstartForward_ 7 // "true, if w_rel=0 and start of forward sliding"
#define $Pclutch3$Pfree_ 8 // "true, if frictional element is not active"
#define $Pclutch3$Plocked_ 9 // "true, if w_rel=0 and not sliding"
#define $Pclutch3$PstartBackward_ 10 // "true, if w_rel=0 and start of backward sliding"
#define $Pclutch3$PstartForward_ 11 // "true, if w_rel=0 and start of forward sliding"
#define $Pclutch1$PuseHeatPort_ 12 // "=true, if heatPort is enabled"
#define $Pclutch2$PuseHeatPort_ 13 // "=true, if heatPort is enabled"
#define $Pclutch3$PuseHeatPort_ 14 // "=true, if heatPort is enabled"
#define $Ptorque$PuseSupport_ 15 // "= true, if support flange enabled, otherwise implicitly grounded"


// define initial state vector as vector of value references
#define STATES { $PJ3$Pphi_, $PJ3$Pw_, $Pclutch1$Pphi_rel_, $Pclutch1$Pw_rel_, $Pclutch2$Pphi_rel_, $Pclutch2$Pw_rel_, $Pclutch3$Pphi_rel_, $Pclutch3$Pw_rel_ }
#define STATESDERIVATIVES { $P$DER$PJ3$Pphi_, $P$DER$PJ3$Pw_, $P$DER$Pclutch1$Pphi_rel_, $P$DER$Pclutch1$Pw_rel_, $P$DER$Pclutch2$Pphi_rel_, $P$DER$Pclutch2$Pw_rel_, $P$DER$Pclutch3$Pphi_rel_, $P$DER$Pclutch3$Pw_rel_ }


// implementation of the Model Exchange functions
  extern void CoupledClutches_setupDataStruc(DATA *data);
  #define fmu1_model_interface_setupDataStruc CoupledClutches_setupDataStruc
  #include "fmu1_model_interface.c"

// Set values for all variables that define a start value
void setDefaultStartValues(ModelInstance *comp) {

comp->fmuData->modelData.realVarsData[0].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[1].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[2].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[3].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[4].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[5].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[6].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[7].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[8].attribute.start = 0;
comp->fmuData->modelData.realVarsData[9].attribute.start = 0;
comp->fmuData->modelData.realVarsData[10].attribute.start = 0;
comp->fmuData->modelData.realVarsData[11].attribute.start = 0;
comp->fmuData->modelData.realVarsData[12].attribute.start = 0;
comp->fmuData->modelData.realVarsData[13].attribute.start = 0;
comp->fmuData->modelData.realVarsData[14].attribute.start = 0;
comp->fmuData->modelData.realVarsData[15].attribute.start = 0;
comp->fmuData->modelData.realVarsData[16].attribute.start = 0;
comp->fmuData->modelData.realVarsData[17].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[18].attribute.start = 10.0;
comp->fmuData->modelData.realVarsData[19].attribute.start = 0;
comp->fmuData->modelData.realVarsData[20].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[21].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[22].attribute.start = 0;
comp->fmuData->modelData.realVarsData[23].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[24].attribute.start = 0;
comp->fmuData->modelData.realVarsData[25].attribute.start = 0;
comp->fmuData->modelData.realVarsData[26].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[27].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[28].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[29].attribute.start = 0;
comp->fmuData->modelData.realVarsData[30].attribute.start = 0;
comp->fmuData->modelData.realVarsData[31].attribute.start = 0;
comp->fmuData->modelData.realVarsData[32].attribute.start = 0;
comp->fmuData->modelData.realVarsData[33].attribute.start = 0;
comp->fmuData->modelData.realVarsData[34].attribute.start = 0;
comp->fmuData->modelData.realVarsData[35].attribute.start = 0;
comp->fmuData->modelData.realVarsData[36].attribute.start = 0;
comp->fmuData->modelData.realVarsData[37].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[38].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[39].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[40].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[41].attribute.start = 0;
comp->fmuData->modelData.realVarsData[42].attribute.start = -0.0;
comp->fmuData->modelData.realVarsData[43].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[44].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[45].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[46].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[47].attribute.start = 0;
comp->fmuData->modelData.realVarsData[48].attribute.start = 0;
comp->fmuData->modelData.realVarsData[49].attribute.start = 0;
comp->fmuData->modelData.realVarsData[50].attribute.start = 0;
comp->fmuData->modelData.realVarsData[51].attribute.start = 0;
comp->fmuData->modelData.realVarsData[52].attribute.start = 0;
comp->fmuData->modelData.realVarsData[53].attribute.start = 0;
comp->fmuData->modelData.realVarsData[54].attribute.start = 0;
comp->fmuData->modelData.realVarsData[55].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[0].attribute.start = 3;
comp->fmuData->modelData.integerVarsData[1].attribute.start = 3;
comp->fmuData->modelData.integerVarsData[2].attribute.start = 3;
comp->fmuData->modelData.booleanVarsData[0].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[1].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[2].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[3].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[4].attribute.start = 1;
comp->fmuData->modelData.booleanVarsData[5].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[6].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[7].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[8].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[9].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[10].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[11].attribute.start = 0;
comp->fmuData->modelData.realParameterData[0].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[1].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[2].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[3].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[4].attribute.start = 0.4;
comp->fmuData->modelData.realParameterData[5].attribute.start = 0.9;
comp->fmuData->modelData.realParameterData[6].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[7].attribute.start = 20.0;
comp->fmuData->modelData.realParameterData[8].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[9].attribute.start = 0.5;
comp->fmuData->modelData.realParameterData[10].attribute.start = 1.1;
comp->fmuData->modelData.realParameterData[11].attribute.start = 0.0001;
comp->fmuData->modelData.realParameterData[12].attribute.start = 10000000000.0;
comp->fmuData->modelData.realParameterData[13].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[14].attribute.start = 20.0;
comp->fmuData->modelData.realParameterData[15].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[16].attribute.start = 0.5;
comp->fmuData->modelData.realParameterData[17].attribute.start = 1.1;
comp->fmuData->modelData.realParameterData[18].attribute.start = 0.0001;
comp->fmuData->modelData.realParameterData[19].attribute.start = 10000000000.0;
comp->fmuData->modelData.realParameterData[20].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[21].attribute.start = 20.0;
comp->fmuData->modelData.realParameterData[22].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[23].attribute.start = 0.5;
comp->fmuData->modelData.realParameterData[24].attribute.start = 1.1;
comp->fmuData->modelData.realParameterData[25].attribute.start = 0.0001;
comp->fmuData->modelData.realParameterData[26].attribute.start = 10000000000.0;
comp->fmuData->modelData.realParameterData[27].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[28].attribute.start = 0.2;
comp->fmuData->modelData.realParameterData[29].attribute.start = 10.0;
comp->fmuData->modelData.realParameterData[30].attribute.start = 5.0;
comp->fmuData->modelData.realParameterData[31].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[32].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[33].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[34].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[35].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[36].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[37].attribute.start = 1.57;
comp->fmuData->modelData.realParameterData[38].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[39].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[40].attribute.start = 0.0;
comp->fmuData->modelData.integerParameterData[0].attribute.start = 3;
comp->fmuData->modelData.integerParameterData[1].attribute.start = 3;
comp->fmuData->modelData.integerParameterData[2].attribute.start = 3;
comp->fmuData->modelData.integerParameterData[3].attribute.start = 3;
comp->fmuData->modelData.integerParameterData[4].attribute.start = 4;
comp->fmuData->modelData.integerParameterData[5].attribute.start = 4;
comp->fmuData->modelData.integerParameterData[6].attribute.start = 4;
comp->fmuData->modelData.booleanParameterData[0].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[1].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[2].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[3].attribute.start = 1;
}
// Set values for all variables that define a start value
void setStartValues(ModelInstance *comp) {

  comp->fmuData->modelData.realVarsData[0].attribute.start =  comp->fmuData->localData[0]->realVars[0];
  comp->fmuData->modelData.realVarsData[1].attribute.start =  comp->fmuData->localData[0]->realVars[1];
  comp->fmuData->modelData.realVarsData[2].attribute.start =  comp->fmuData->localData[0]->realVars[2];
  comp->fmuData->modelData.realVarsData[3].attribute.start =  comp->fmuData->localData[0]->realVars[3];
  comp->fmuData->modelData.realVarsData[4].attribute.start =  comp->fmuData->localData[0]->realVars[4];
  comp->fmuData->modelData.realVarsData[5].attribute.start =  comp->fmuData->localData[0]->realVars[5];
  comp->fmuData->modelData.realVarsData[6].attribute.start =  comp->fmuData->localData[0]->realVars[6];
  comp->fmuData->modelData.realVarsData[7].attribute.start =  comp->fmuData->localData[0]->realVars[7];
  comp->fmuData->modelData.realVarsData[8].attribute.start =  comp->fmuData->localData[0]->realVars[8];
  comp->fmuData->modelData.realVarsData[9].attribute.start =  comp->fmuData->localData[0]->realVars[9];
  comp->fmuData->modelData.realVarsData[10].attribute.start =  comp->fmuData->localData[0]->realVars[10];
  comp->fmuData->modelData.realVarsData[11].attribute.start =  comp->fmuData->localData[0]->realVars[11];
  comp->fmuData->modelData.realVarsData[12].attribute.start =  comp->fmuData->localData[0]->realVars[12];
  comp->fmuData->modelData.realVarsData[13].attribute.start =  comp->fmuData->localData[0]->realVars[13];
  comp->fmuData->modelData.realVarsData[14].attribute.start =  comp->fmuData->localData[0]->realVars[14];
  comp->fmuData->modelData.realVarsData[15].attribute.start =  comp->fmuData->localData[0]->realVars[15];
  comp->fmuData->modelData.realVarsData[16].attribute.start =  comp->fmuData->localData[0]->realVars[16];
  comp->fmuData->modelData.realVarsData[17].attribute.start =  comp->fmuData->localData[0]->realVars[17];
  comp->fmuData->modelData.realVarsData[18].attribute.start =  comp->fmuData->localData[0]->realVars[18];
  comp->fmuData->modelData.realVarsData[19].attribute.start =  comp->fmuData->localData[0]->realVars[19];
  comp->fmuData->modelData.realVarsData[20].attribute.start =  comp->fmuData->localData[0]->realVars[20];
  comp->fmuData->modelData.realVarsData[21].attribute.start =  comp->fmuData->localData[0]->realVars[21];
  comp->fmuData->modelData.realVarsData[22].attribute.start =  comp->fmuData->localData[0]->realVars[22];
  comp->fmuData->modelData.realVarsData[23].attribute.start =  comp->fmuData->localData[0]->realVars[23];
  comp->fmuData->modelData.realVarsData[24].attribute.start =  comp->fmuData->localData[0]->realVars[24];
  comp->fmuData->modelData.realVarsData[25].attribute.start =  comp->fmuData->localData[0]->realVars[25];
  comp->fmuData->modelData.realVarsData[26].attribute.start =  comp->fmuData->localData[0]->realVars[26];
  comp->fmuData->modelData.realVarsData[27].attribute.start =  comp->fmuData->localData[0]->realVars[27];
  comp->fmuData->modelData.realVarsData[28].attribute.start =  comp->fmuData->localData[0]->realVars[28];
  comp->fmuData->modelData.realVarsData[29].attribute.start =  comp->fmuData->localData[0]->realVars[29];
  comp->fmuData->modelData.realVarsData[30].attribute.start =  comp->fmuData->localData[0]->realVars[30];
  comp->fmuData->modelData.realVarsData[31].attribute.start =  comp->fmuData->localData[0]->realVars[31];
  comp->fmuData->modelData.realVarsData[32].attribute.start =  comp->fmuData->localData[0]->realVars[32];
  comp->fmuData->modelData.realVarsData[33].attribute.start =  comp->fmuData->localData[0]->realVars[33];
  comp->fmuData->modelData.realVarsData[34].attribute.start =  comp->fmuData->localData[0]->realVars[34];
  comp->fmuData->modelData.realVarsData[35].attribute.start =  comp->fmuData->localData[0]->realVars[35];
  comp->fmuData->modelData.realVarsData[36].attribute.start =  comp->fmuData->localData[0]->realVars[36];
  comp->fmuData->modelData.realVarsData[37].attribute.start =  comp->fmuData->localData[0]->realVars[37];
  comp->fmuData->modelData.realVarsData[38].attribute.start =  comp->fmuData->localData[0]->realVars[38];
  comp->fmuData->modelData.realVarsData[39].attribute.start =  comp->fmuData->localData[0]->realVars[39];
  comp->fmuData->modelData.realVarsData[40].attribute.start =  comp->fmuData->localData[0]->realVars[40];
  comp->fmuData->modelData.realVarsData[41].attribute.start =  comp->fmuData->localData[0]->realVars[41];
  comp->fmuData->modelData.realVarsData[42].attribute.start =  comp->fmuData->localData[0]->realVars[42];
  comp->fmuData->modelData.realVarsData[43].attribute.start =  comp->fmuData->localData[0]->realVars[43];
  comp->fmuData->modelData.realVarsData[44].attribute.start =  comp->fmuData->localData[0]->realVars[44];
  comp->fmuData->modelData.realVarsData[45].attribute.start =  comp->fmuData->localData[0]->realVars[45];
  comp->fmuData->modelData.realVarsData[46].attribute.start =  comp->fmuData->localData[0]->realVars[46];
  comp->fmuData->modelData.realVarsData[47].attribute.start =  comp->fmuData->localData[0]->realVars[47];
  comp->fmuData->modelData.realVarsData[48].attribute.start =  comp->fmuData->localData[0]->realVars[48];
  comp->fmuData->modelData.realVarsData[49].attribute.start =  comp->fmuData->localData[0]->realVars[49];
  comp->fmuData->modelData.realVarsData[50].attribute.start =  comp->fmuData->localData[0]->realVars[50];
  comp->fmuData->modelData.realVarsData[51].attribute.start =  comp->fmuData->localData[0]->realVars[51];
  comp->fmuData->modelData.realVarsData[52].attribute.start =  comp->fmuData->localData[0]->realVars[52];
  comp->fmuData->modelData.realVarsData[53].attribute.start =  comp->fmuData->localData[0]->realVars[53];
  comp->fmuData->modelData.realVarsData[54].attribute.start =  comp->fmuData->localData[0]->realVars[54];
  comp->fmuData->modelData.realVarsData[55].attribute.start =  comp->fmuData->localData[0]->realVars[55];
  comp->fmuData->modelData.integerVarsData[0].attribute.start =  comp->fmuData->localData[0]->integerVars[0];
  comp->fmuData->modelData.integerVarsData[1].attribute.start =  comp->fmuData->localData[0]->integerVars[1];
  comp->fmuData->modelData.integerVarsData[2].attribute.start =  comp->fmuData->localData[0]->integerVars[2];
  comp->fmuData->modelData.booleanVarsData[0].attribute.start =  comp->fmuData->localData[0]->booleanVars[0];
  comp->fmuData->modelData.booleanVarsData[1].attribute.start =  comp->fmuData->localData[0]->booleanVars[1];
  comp->fmuData->modelData.booleanVarsData[2].attribute.start =  comp->fmuData->localData[0]->booleanVars[2];
  comp->fmuData->modelData.booleanVarsData[3].attribute.start =  comp->fmuData->localData[0]->booleanVars[3];
  comp->fmuData->modelData.booleanVarsData[4].attribute.start =  comp->fmuData->localData[0]->booleanVars[4];
  comp->fmuData->modelData.booleanVarsData[5].attribute.start =  comp->fmuData->localData[0]->booleanVars[5];
  comp->fmuData->modelData.booleanVarsData[6].attribute.start =  comp->fmuData->localData[0]->booleanVars[6];
  comp->fmuData->modelData.booleanVarsData[7].attribute.start =  comp->fmuData->localData[0]->booleanVars[7];
  comp->fmuData->modelData.booleanVarsData[8].attribute.start =  comp->fmuData->localData[0]->booleanVars[8];
  comp->fmuData->modelData.booleanVarsData[9].attribute.start =  comp->fmuData->localData[0]->booleanVars[9];
  comp->fmuData->modelData.booleanVarsData[10].attribute.start =  comp->fmuData->localData[0]->booleanVars[10];
  comp->fmuData->modelData.booleanVarsData[11].attribute.start =  comp->fmuData->localData[0]->booleanVars[11];
comp->fmuData->modelData.realParameterData[0].attribute.start = comp->fmuData->simulationInfo.realParameter[0];
comp->fmuData->modelData.realParameterData[1].attribute.start = comp->fmuData->simulationInfo.realParameter[1];
comp->fmuData->modelData.realParameterData[2].attribute.start = comp->fmuData->simulationInfo.realParameter[2];
comp->fmuData->modelData.realParameterData[3].attribute.start = comp->fmuData->simulationInfo.realParameter[3];
comp->fmuData->modelData.realParameterData[4].attribute.start = comp->fmuData->simulationInfo.realParameter[4];
comp->fmuData->modelData.realParameterData[5].attribute.start = comp->fmuData->simulationInfo.realParameter[5];
comp->fmuData->modelData.realParameterData[6].attribute.start = comp->fmuData->simulationInfo.realParameter[6];
comp->fmuData->modelData.realParameterData[7].attribute.start = comp->fmuData->simulationInfo.realParameter[7];
comp->fmuData->modelData.realParameterData[8].attribute.start = comp->fmuData->simulationInfo.realParameter[8];
comp->fmuData->modelData.realParameterData[9].attribute.start = comp->fmuData->simulationInfo.realParameter[9];
comp->fmuData->modelData.realParameterData[10].attribute.start = comp->fmuData->simulationInfo.realParameter[10];
comp->fmuData->modelData.realParameterData[11].attribute.start = comp->fmuData->simulationInfo.realParameter[11];
comp->fmuData->modelData.realParameterData[12].attribute.start = comp->fmuData->simulationInfo.realParameter[12];
comp->fmuData->modelData.realParameterData[13].attribute.start = comp->fmuData->simulationInfo.realParameter[13];
comp->fmuData->modelData.realParameterData[14].attribute.start = comp->fmuData->simulationInfo.realParameter[14];
comp->fmuData->modelData.realParameterData[15].attribute.start = comp->fmuData->simulationInfo.realParameter[15];
comp->fmuData->modelData.realParameterData[16].attribute.start = comp->fmuData->simulationInfo.realParameter[16];
comp->fmuData->modelData.realParameterData[17].attribute.start = comp->fmuData->simulationInfo.realParameter[17];
comp->fmuData->modelData.realParameterData[18].attribute.start = comp->fmuData->simulationInfo.realParameter[18];
comp->fmuData->modelData.realParameterData[19].attribute.start = comp->fmuData->simulationInfo.realParameter[19];
comp->fmuData->modelData.realParameterData[20].attribute.start = comp->fmuData->simulationInfo.realParameter[20];
comp->fmuData->modelData.realParameterData[21].attribute.start = comp->fmuData->simulationInfo.realParameter[21];
comp->fmuData->modelData.realParameterData[22].attribute.start = comp->fmuData->simulationInfo.realParameter[22];
comp->fmuData->modelData.realParameterData[23].attribute.start = comp->fmuData->simulationInfo.realParameter[23];
comp->fmuData->modelData.realParameterData[24].attribute.start = comp->fmuData->simulationInfo.realParameter[24];
comp->fmuData->modelData.realParameterData[25].attribute.start = comp->fmuData->simulationInfo.realParameter[25];
comp->fmuData->modelData.realParameterData[26].attribute.start = comp->fmuData->simulationInfo.realParameter[26];
comp->fmuData->modelData.realParameterData[27].attribute.start = comp->fmuData->simulationInfo.realParameter[27];
comp->fmuData->modelData.realParameterData[28].attribute.start = comp->fmuData->simulationInfo.realParameter[28];
comp->fmuData->modelData.realParameterData[29].attribute.start = comp->fmuData->simulationInfo.realParameter[29];
comp->fmuData->modelData.realParameterData[30].attribute.start = comp->fmuData->simulationInfo.realParameter[30];
comp->fmuData->modelData.realParameterData[31].attribute.start = comp->fmuData->simulationInfo.realParameter[31];
comp->fmuData->modelData.realParameterData[32].attribute.start = comp->fmuData->simulationInfo.realParameter[32];
comp->fmuData->modelData.realParameterData[33].attribute.start = comp->fmuData->simulationInfo.realParameter[33];
comp->fmuData->modelData.realParameterData[34].attribute.start = comp->fmuData->simulationInfo.realParameter[34];
comp->fmuData->modelData.realParameterData[35].attribute.start = comp->fmuData->simulationInfo.realParameter[35];
comp->fmuData->modelData.realParameterData[36].attribute.start = comp->fmuData->simulationInfo.realParameter[36];
comp->fmuData->modelData.realParameterData[37].attribute.start = comp->fmuData->simulationInfo.realParameter[37];
comp->fmuData->modelData.realParameterData[38].attribute.start = comp->fmuData->simulationInfo.realParameter[38];
comp->fmuData->modelData.realParameterData[39].attribute.start = comp->fmuData->simulationInfo.realParameter[39];
comp->fmuData->modelData.realParameterData[40].attribute.start = comp->fmuData->simulationInfo.realParameter[40];
comp->fmuData->modelData.realParameterData[41].attribute.start = comp->fmuData->simulationInfo.realParameter[41];
comp->fmuData->modelData.integerParameterData[0].attribute.start = comp->fmuData->simulationInfo.integerParameter[0];
comp->fmuData->modelData.integerParameterData[1].attribute.start = comp->fmuData->simulationInfo.integerParameter[1];
comp->fmuData->modelData.integerParameterData[2].attribute.start = comp->fmuData->simulationInfo.integerParameter[2];
comp->fmuData->modelData.integerParameterData[3].attribute.start = comp->fmuData->simulationInfo.integerParameter[3];
comp->fmuData->modelData.integerParameterData[4].attribute.start = comp->fmuData->simulationInfo.integerParameter[4];
comp->fmuData->modelData.integerParameterData[5].attribute.start = comp->fmuData->simulationInfo.integerParameter[5];
comp->fmuData->modelData.integerParameterData[6].attribute.start = comp->fmuData->simulationInfo.integerParameter[6];
comp->fmuData->modelData.booleanParameterData[0].attribute.start = comp->fmuData->simulationInfo.booleanParameter[0];
comp->fmuData->modelData.booleanParameterData[1].attribute.start = comp->fmuData->simulationInfo.booleanParameter[1];
comp->fmuData->modelData.booleanParameterData[2].attribute.start = comp->fmuData->simulationInfo.booleanParameter[2];
comp->fmuData->modelData.booleanParameterData[3].attribute.start = comp->fmuData->simulationInfo.booleanParameter[3];
}
  // Used to set the next time event, if any.
  void eventUpdate(ModelInstance* comp, fmiEventInfo* eventInfo) {
  }
  
  fmiReal getReal(ModelInstance* comp, const fmiValueReference vr) {
    switch (vr) {
        case $PJ3$Pphi_ : return comp->fmuData->localData[0]->realVars[0]; break;
        case $PJ3$Pw_ : return comp->fmuData->localData[0]->realVars[1]; break;
        case $Pclutch1$Pphi_rel_ : return comp->fmuData->localData[0]->realVars[2]; break;
        case $Pclutch1$Pw_rel_ : return comp->fmuData->localData[0]->realVars[3]; break;
        case $Pclutch2$Pphi_rel_ : return comp->fmuData->localData[0]->realVars[4]; break;
        case $Pclutch2$Pw_rel_ : return comp->fmuData->localData[0]->realVars[5]; break;
        case $Pclutch3$Pphi_rel_ : return comp->fmuData->localData[0]->realVars[6]; break;
        case $Pclutch3$Pw_rel_ : return comp->fmuData->localData[0]->realVars[7]; break;
        case $P$DER$PJ3$Pphi_ : return comp->fmuData->localData[0]->realVars[8]; break;
        case $P$DER$PJ3$Pw_ : return comp->fmuData->localData[0]->realVars[9]; break;
        case $P$DER$Pclutch1$Pphi_rel_ : return comp->fmuData->localData[0]->realVars[10]; break;
        case $P$DER$Pclutch1$Pw_rel_ : return comp->fmuData->localData[0]->realVars[11]; break;
        case $P$DER$Pclutch2$Pphi_rel_ : return comp->fmuData->localData[0]->realVars[12]; break;
        case $P$DER$Pclutch2$Pw_rel_ : return comp->fmuData->localData[0]->realVars[13]; break;
        case $P$DER$Pclutch3$Pphi_rel_ : return comp->fmuData->localData[0]->realVars[14]; break;
        case $P$DER$Pclutch3$Pw_rel_ : return comp->fmuData->localData[0]->realVars[15]; break;
        case $PJ1$Pa_ : return comp->fmuData->localData[0]->realVars[16]; break;
        case $PJ1$Pphi_ : return comp->fmuData->localData[0]->realVars[17]; break;
        case $PJ1_w1_ : return comp->fmuData->localData[0]->realVars[18]; break;
        case $PJ2$Pa_ : return comp->fmuData->localData[0]->realVars[19]; break;
        case $PJ2$Pphi_ : return comp->fmuData->localData[0]->realVars[20]; break;
        case $PJ2_w1_ : return comp->fmuData->localData[0]->realVars[21]; break;
        case $PJ3$Pa_ : return comp->fmuData->localData[0]->realVars[22]; break;
        case $PJ3_w1_ : return comp->fmuData->localData[0]->realVars[23]; break;
        case $PJ4$Pa_ : return comp->fmuData->localData[0]->realVars[24]; break;
        case $PJ4$Pflange_b$Ptau_ : return comp->fmuData->localData[0]->realVars[25]; break;
        case $PJ4$Pphi_ : return comp->fmuData->localData[0]->realVars[26]; break;
        case $PJ4_w1_ : return comp->fmuData->localData[0]->realVars[27]; break;
        case $Pclutch1$Pa_relfric_ : return comp->fmuData->localData[0]->realVars[28]; break;
        case $Pclutch1$Pf_normalized_ : return comp->fmuData->localData[0]->realVars[29]; break;
        case $Pclutch1$Pfn_ : return comp->fmuData->localData[0]->realVars[30]; break;
        case $Pclutch1$PlossPower_ : return comp->fmuData->localData[0]->realVars[31]; break;
        case $Pclutch1$Pmue0_ : return comp->fmuData->localData[0]->realVars[32]; break;
        case $Pclutch1$Psa_ : return comp->fmuData->localData[0]->realVars[33]; break;
        case $Pclutch1$Ptau_ : return comp->fmuData->localData[0]->realVars[34]; break;
        case $Pclutch1$Ptau0_ : return comp->fmuData->localData[0]->realVars[35]; break;
        case $Pclutch1$Ptau0_max_ : return comp->fmuData->localData[0]->realVars[36]; break;
        case $Pclutch2$Pa_relfric_ : return comp->fmuData->localData[0]->realVars[37]; break;
        case $Pclutch2$Pf_normalized_ : return comp->fmuData->localData[0]->realVars[38]; break;
        case $Pclutch2$Pfn_ : return comp->fmuData->localData[0]->realVars[39]; break;
        case $Pclutch2$PlossPower_ : return comp->fmuData->localData[0]->realVars[40]; break;
        case $Pclutch2$Pmue0_ : return comp->fmuData->localData[0]->realVars[41]; break;
        case $Pclutch2$Psa_ : return comp->fmuData->localData[0]->realVars[42]; break;
        case $Pclutch2$Ptau_ : return comp->fmuData->localData[0]->realVars[43]; break;
        case $Pclutch2$Ptau0_ : return comp->fmuData->localData[0]->realVars[44]; break;
        case $Pclutch2$Ptau0_max_ : return comp->fmuData->localData[0]->realVars[45]; break;
        case $Pclutch3$Pa_relfric_ : return comp->fmuData->localData[0]->realVars[46]; break;
        case $Pclutch3$Pfn_ : return comp->fmuData->localData[0]->realVars[47]; break;
        case $Pclutch3$PlossPower_ : return comp->fmuData->localData[0]->realVars[48]; break;
        case $Pclutch3$Pmue0_ : return comp->fmuData->localData[0]->realVars[49]; break;
        case $Pclutch3$Psa_ : return comp->fmuData->localData[0]->realVars[50]; break;
        case $Pclutch3$Ptau_ : return comp->fmuData->localData[0]->realVars[51]; break;
        case $Pclutch3$Ptau0_ : return comp->fmuData->localData[0]->realVars[52]; break;
        case $Pclutch3$Ptau0_max_ : return comp->fmuData->localData[0]->realVars[53]; break;
        case $Psin1$Py_ : return comp->fmuData->localData[0]->realVars[54]; break;
        case $Pstep2_ : return comp->fmuData->localData[0]->realVars[55]; break;
        case $PJ1$PJ_ : return comp->fmuData->simulationInfo.realParameter[0]; break;
        case $PJ2$PJ_ : return comp->fmuData->simulationInfo.realParameter[1]; break;
        case $PJ3$PJ_ : return comp->fmuData->simulationInfo.realParameter[2]; break;
        case $PJ4$PJ_ : return comp->fmuData->simulationInfo.realParameter[3]; break;
        case $PT2_ : return comp->fmuData->simulationInfo.realParameter[4]; break;
        case $PT3_ : return comp->fmuData->simulationInfo.realParameter[5]; break;
        case $Pclutch1$Pcgeo_ : return comp->fmuData->simulationInfo.realParameter[6]; break;
        case $Pclutch1$Pfn_max_ : return comp->fmuData->simulationInfo.realParameter[7]; break;
        case $Pclutch1$Pmue_pos$lB1$c1$rB_ : return comp->fmuData->simulationInfo.realParameter[8]; break;
        case $Pclutch1$Pmue_pos$lB1$c2$rB_ : return comp->fmuData->simulationInfo.realParameter[9]; break;
        case $Pclutch1$Ppeak_ : return comp->fmuData->simulationInfo.realParameter[10]; break;
        case $Pclutch1$Pphi_nominal_ : return comp->fmuData->simulationInfo.realParameter[11]; break;
        case $Pclutch1$Pw_small_ : return comp->fmuData->simulationInfo.realParameter[12]; break;
        case $Pclutch2$Pcgeo_ : return comp->fmuData->simulationInfo.realParameter[13]; break;
        case $Pclutch2$Pfn_max_ : return comp->fmuData->simulationInfo.realParameter[14]; break;
        case $Pclutch2$Pmue_pos$lB1$c1$rB_ : return comp->fmuData->simulationInfo.realParameter[15]; break;
        case $Pclutch2$Pmue_pos$lB1$c2$rB_ : return comp->fmuData->simulationInfo.realParameter[16]; break;
        case $Pclutch2$Ppeak_ : return comp->fmuData->simulationInfo.realParameter[17]; break;
        case $Pclutch2$Pphi_nominal_ : return comp->fmuData->simulationInfo.realParameter[18]; break;
        case $Pclutch2$Pw_small_ : return comp->fmuData->simulationInfo.realParameter[19]; break;
        case $Pclutch3$Pcgeo_ : return comp->fmuData->simulationInfo.realParameter[20]; break;
        case $Pclutch3$Pfn_max_ : return comp->fmuData->simulationInfo.realParameter[21]; break;
        case $Pclutch3$Pmue_pos$lB1$c1$rB_ : return comp->fmuData->simulationInfo.realParameter[22]; break;
        case $Pclutch3$Pmue_pos$lB1$c2$rB_ : return comp->fmuData->simulationInfo.realParameter[23]; break;
        case $Pclutch3$Ppeak_ : return comp->fmuData->simulationInfo.realParameter[24]; break;
        case $Pclutch3$Pphi_nominal_ : return comp->fmuData->simulationInfo.realParameter[25]; break;
        case $Pclutch3$Pw_small_ : return comp->fmuData->simulationInfo.realParameter[26]; break;
        case $Pfixed$Pphi0_ : return comp->fmuData->simulationInfo.realParameter[27]; break;
        case $PfreqHz_ : return comp->fmuData->simulationInfo.realParameter[28]; break;
        case $Psin1$Pamplitude_ : return comp->fmuData->simulationInfo.realParameter[29]; break;
        case $Psin1$PfreqHz_ : return comp->fmuData->simulationInfo.realParameter[30]; break;
        case $Psin1$Poffset_ : return comp->fmuData->simulationInfo.realParameter[31]; break;
        case $Psin1$Pphase_ : return comp->fmuData->simulationInfo.realParameter[32]; break;
        case $Psin1$PstartTime_ : return comp->fmuData->simulationInfo.realParameter[33]; break;
        case $Psin2$Pamplitude_ : return comp->fmuData->simulationInfo.realParameter[34]; break;
        case $Psin2$PfreqHz_ : return comp->fmuData->simulationInfo.realParameter[35]; break;
        case $Psin2$Poffset_ : return comp->fmuData->simulationInfo.realParameter[36]; break;
        case $Psin2$Pphase_ : return comp->fmuData->simulationInfo.realParameter[37]; break;
        case $Psin2$PstartTime_ : return comp->fmuData->simulationInfo.realParameter[38]; break;
        case $Pstep1$Pheight_ : return comp->fmuData->simulationInfo.realParameter[39]; break;
        case $Pstep1$Poffset_ : return comp->fmuData->simulationInfo.realParameter[40]; break;
        case $Pstep1$PstartTime_ : return comp->fmuData->simulationInfo.realParameter[41]; break;
        case $P$DER$PJ1$Pphi_ : return getReal(comp, $PJ1_w1_); break;
        case $P$DER$PJ1$Pw_ : return getReal(comp, $PJ1$Pa_); break;
        case $P$DER$PJ2$Pphi_ : return getReal(comp, $PJ2_w1_); break;
        case $P$DER$PJ2$Pw_ : return getReal(comp, $PJ2$Pa_); break;
        case $P$DER$PJ4$Pphi_ : return getReal(comp, $PJ4_w1_); break;
        case $P$DER$PJ4$Pw_ : return getReal(comp, $PJ4$Pa_); break;
        case $PJ1$Pflange_a$Pphi_ : return getReal(comp, $PJ1$Pphi_); break;
        case $PJ1$Pflange_a$Ptau_ : return getReal(comp, $Psin1$Py_); break;
        case $PJ1$Pflange_b$Pphi_ : return getReal(comp, $PJ1$Pphi_); break;
        case $PJ1$Pflange_b$Ptau_ : return getReal(comp, $Pclutch1$Ptau_); break;
        case $PJ1$Pw_ : return getReal(comp, $PJ1_w1_); break;
        case $PJ2$Pflange_a$Pphi_ : return getReal(comp, $PJ2$Pphi_); break;
        case $PJ2$Pflange_a$Ptau_ : return (- getReal(comp, $Pclutch1$Ptau_)); break;
        case $PJ2$Pflange_b$Pphi_ : return getReal(comp, $PJ2$Pphi_); break;
        case $PJ2$Pflange_b$Ptau_ : return getReal(comp, $Pclutch2$Ptau_); break;
        case $PJ2$Pw_ : return getReal(comp, $PJ2_w1_); break;
        case $PJ3$Pflange_a$Pphi_ : return getReal(comp, $PJ3$Pphi_); break;
        case $PJ3$Pflange_a$Ptau_ : return (- getReal(comp, $Pclutch2$Ptau_)); break;
        case $PJ3$Pflange_b$Pphi_ : return getReal(comp, $PJ3$Pphi_); break;
        case $PJ3$Pflange_b$Ptau_ : return getReal(comp, $Pclutch3$Ptau_); break;
        case $PJ4$Pflange_a$Pphi_ : return getReal(comp, $PJ4$Pphi_); break;
        case $PJ4$Pflange_a$Ptau_ : return (- getReal(comp, $Pclutch3$Ptau_)); break;
        case $PJ4$Pflange_b$Pphi_ : return getReal(comp, $PJ4$Pphi_); break;
        case $PJ4$Pw_ : return getReal(comp, $PJ4_w1_); break;
        case $Pclutch1$Pa_rel_ : return getReal(comp, $Pclutch1$Pa_relfric_); break;
        case $Pclutch1$Pflange_a$Pphi_ : return getReal(comp, $PJ1$Pphi_); break;
        case $Pclutch1$Pflange_a$Ptau_ : return (- getReal(comp, $Pclutch1$Ptau_)); break;
        case $Pclutch1$Pflange_b$Pphi_ : return getReal(comp, $PJ2$Pphi_); break;
        case $Pclutch1$Pflange_b$Ptau_ : return getReal(comp, $Pclutch1$Ptau_); break;
        case $Pclutch1$Pw_relfric_ : return getReal(comp, $Pclutch1$Pw_rel_); break;
        case $Pclutch2$Pa_rel_ : return getReal(comp, $Pclutch2$Pa_relfric_); break;
        case $Pclutch2$Pflange_a$Pphi_ : return getReal(comp, $PJ2$Pphi_); break;
        case $Pclutch2$Pflange_a$Ptau_ : return (- getReal(comp, $Pclutch2$Ptau_)); break;
        case $Pclutch2$Pflange_b$Pphi_ : return getReal(comp, $PJ3$Pphi_); break;
        case $Pclutch2$Pflange_b$Ptau_ : return getReal(comp, $Pclutch2$Ptau_); break;
        case $Pclutch2$Pw_relfric_ : return getReal(comp, $Pclutch2$Pw_rel_); break;
        case $Pclutch3$Pa_rel_ : return getReal(comp, $Pclutch3$Pa_relfric_); break;
        case $Pclutch3$Pf_normalized_ : return getReal(comp, $Pstep2_); break;
        case $Pclutch3$Pflange_a$Pphi_ : return getReal(comp, $PJ3$Pphi_); break;
        case $Pclutch3$Pflange_a$Ptau_ : return (- getReal(comp, $Pclutch3$Ptau_)); break;
        case $Pclutch3$Pflange_b$Pphi_ : return getReal(comp, $PJ4$Pphi_); break;
        case $Pclutch3$Pflange_b$Ptau_ : return getReal(comp, $Pclutch3$Ptau_); break;
        case $Pclutch3$Pw_relfric_ : return getReal(comp, $Pclutch3$Pw_rel_); break;
        case $Pfixed$Pflange$Pphi_ : return getReal(comp, $Pfixed$Pphi0_); break;
        case $Pfixed$Pflange$Ptau_ : return (- getReal(comp, $Psin1$Py_)); break;
        case $Psin2$Py_ : return getReal(comp, $Pclutch1$Pf_normalized_); break;
        case $Pstep1$Py_ : return getReal(comp, $Pclutch2$Pf_normalized_); break;
        case $Ptorque$Pflange$Pphi_ : return getReal(comp, $PJ1$Pphi_); break;
        case $Ptorque$Pflange$Ptau_ : return (- getReal(comp, $Psin1$Py_)); break;
        case $Ptorque$Pphi_support_ : return getReal(comp, $Pfixed$Pphi0_); break;
        case $Ptorque$Psupport$Pphi_ : return getReal(comp, $Pfixed$Pphi0_); break;
        case $Ptorque$Psupport$Ptau_ : return getReal(comp, $Psin1$Py_); break;
        case $Ptorque$Ptau_ : return getReal(comp, $Psin1$Py_); break;
        default:
            return 0;
    }
  }
  
  fmiStatus setReal(ModelInstance* comp, const fmiValueReference vr, const fmiReal value) {
    switch (vr) {
        case $PJ3$Pphi_ : comp->fmuData->localData[0]->realVars[0]=value; break;
        case $PJ3$Pw_ : comp->fmuData->localData[0]->realVars[1]=value; break;
        case $Pclutch1$Pphi_rel_ : comp->fmuData->localData[0]->realVars[2]=value; break;
        case $Pclutch1$Pw_rel_ : comp->fmuData->localData[0]->realVars[3]=value; break;
        case $Pclutch2$Pphi_rel_ : comp->fmuData->localData[0]->realVars[4]=value; break;
        case $Pclutch2$Pw_rel_ : comp->fmuData->localData[0]->realVars[5]=value; break;
        case $Pclutch3$Pphi_rel_ : comp->fmuData->localData[0]->realVars[6]=value; break;
        case $Pclutch3$Pw_rel_ : comp->fmuData->localData[0]->realVars[7]=value; break;
        case $P$DER$PJ3$Pphi_ : comp->fmuData->localData[0]->realVars[8]=value; break;
        case $P$DER$PJ3$Pw_ : comp->fmuData->localData[0]->realVars[9]=value; break;
        case $P$DER$Pclutch1$Pphi_rel_ : comp->fmuData->localData[0]->realVars[10]=value; break;
        case $P$DER$Pclutch1$Pw_rel_ : comp->fmuData->localData[0]->realVars[11]=value; break;
        case $P$DER$Pclutch2$Pphi_rel_ : comp->fmuData->localData[0]->realVars[12]=value; break;
        case $P$DER$Pclutch2$Pw_rel_ : comp->fmuData->localData[0]->realVars[13]=value; break;
        case $P$DER$Pclutch3$Pphi_rel_ : comp->fmuData->localData[0]->realVars[14]=value; break;
        case $P$DER$Pclutch3$Pw_rel_ : comp->fmuData->localData[0]->realVars[15]=value; break;
        case $PJ1$Pa_ : comp->fmuData->localData[0]->realVars[16]=value; break;
        case $PJ1$Pphi_ : comp->fmuData->localData[0]->realVars[17]=value; break;
        case $PJ1_w1_ : comp->fmuData->localData[0]->realVars[18]=value; break;
        case $PJ2$Pa_ : comp->fmuData->localData[0]->realVars[19]=value; break;
        case $PJ2$Pphi_ : comp->fmuData->localData[0]->realVars[20]=value; break;
        case $PJ2_w1_ : comp->fmuData->localData[0]->realVars[21]=value; break;
        case $PJ3$Pa_ : comp->fmuData->localData[0]->realVars[22]=value; break;
        case $PJ3_w1_ : comp->fmuData->localData[0]->realVars[23]=value; break;
        case $PJ4$Pa_ : comp->fmuData->localData[0]->realVars[24]=value; break;
        case $PJ4$Pflange_b$Ptau_ : comp->fmuData->localData[0]->realVars[25]=value; break;
        case $PJ4$Pphi_ : comp->fmuData->localData[0]->realVars[26]=value; break;
        case $PJ4_w1_ : comp->fmuData->localData[0]->realVars[27]=value; break;
        case $Pclutch1$Pa_relfric_ : comp->fmuData->localData[0]->realVars[28]=value; break;
        case $Pclutch1$Pf_normalized_ : comp->fmuData->localData[0]->realVars[29]=value; break;
        case $Pclutch1$Pfn_ : comp->fmuData->localData[0]->realVars[30]=value; break;
        case $Pclutch1$PlossPower_ : comp->fmuData->localData[0]->realVars[31]=value; break;
        case $Pclutch1$Pmue0_ : comp->fmuData->localData[0]->realVars[32]=value; break;
        case $Pclutch1$Psa_ : comp->fmuData->localData[0]->realVars[33]=value; break;
        case $Pclutch1$Ptau_ : comp->fmuData->localData[0]->realVars[34]=value; break;
        case $Pclutch1$Ptau0_ : comp->fmuData->localData[0]->realVars[35]=value; break;
        case $Pclutch1$Ptau0_max_ : comp->fmuData->localData[0]->realVars[36]=value; break;
        case $Pclutch2$Pa_relfric_ : comp->fmuData->localData[0]->realVars[37]=value; break;
        case $Pclutch2$Pf_normalized_ : comp->fmuData->localData[0]->realVars[38]=value; break;
        case $Pclutch2$Pfn_ : comp->fmuData->localData[0]->realVars[39]=value; break;
        case $Pclutch2$PlossPower_ : comp->fmuData->localData[0]->realVars[40]=value; break;
        case $Pclutch2$Pmue0_ : comp->fmuData->localData[0]->realVars[41]=value; break;
        case $Pclutch2$Psa_ : comp->fmuData->localData[0]->realVars[42]=value; break;
        case $Pclutch2$Ptau_ : comp->fmuData->localData[0]->realVars[43]=value; break;
        case $Pclutch2$Ptau0_ : comp->fmuData->localData[0]->realVars[44]=value; break;
        case $Pclutch2$Ptau0_max_ : comp->fmuData->localData[0]->realVars[45]=value; break;
        case $Pclutch3$Pa_relfric_ : comp->fmuData->localData[0]->realVars[46]=value; break;
        case $Pclutch3$Pfn_ : comp->fmuData->localData[0]->realVars[47]=value; break;
        case $Pclutch3$PlossPower_ : comp->fmuData->localData[0]->realVars[48]=value; break;
        case $Pclutch3$Pmue0_ : comp->fmuData->localData[0]->realVars[49]=value; break;
        case $Pclutch3$Psa_ : comp->fmuData->localData[0]->realVars[50]=value; break;
        case $Pclutch3$Ptau_ : comp->fmuData->localData[0]->realVars[51]=value; break;
        case $Pclutch3$Ptau0_ : comp->fmuData->localData[0]->realVars[52]=value; break;
        case $Pclutch3$Ptau0_max_ : comp->fmuData->localData[0]->realVars[53]=value; break;
        case $Psin1$Py_ : comp->fmuData->localData[0]->realVars[54]=value; break;
        case $Pstep2_ : comp->fmuData->localData[0]->realVars[55]=value; break;
        case $PJ1$PJ_ : comp->fmuData->simulationInfo.realParameter[0]=value; break;
        case $PJ2$PJ_ : comp->fmuData->simulationInfo.realParameter[1]=value; break;
        case $PJ3$PJ_ : comp->fmuData->simulationInfo.realParameter[2]=value; break;
        case $PJ4$PJ_ : comp->fmuData->simulationInfo.realParameter[3]=value; break;
        case $PT2_ : comp->fmuData->simulationInfo.realParameter[4]=value; break;
        case $PT3_ : comp->fmuData->simulationInfo.realParameter[5]=value; break;
        case $Pclutch1$Pcgeo_ : comp->fmuData->simulationInfo.realParameter[6]=value; break;
        case $Pclutch1$Pfn_max_ : comp->fmuData->simulationInfo.realParameter[7]=value; break;
        case $Pclutch1$Pmue_pos$lB1$c1$rB_ : comp->fmuData->simulationInfo.realParameter[8]=value; break;
        case $Pclutch1$Pmue_pos$lB1$c2$rB_ : comp->fmuData->simulationInfo.realParameter[9]=value; break;
        case $Pclutch1$Ppeak_ : comp->fmuData->simulationInfo.realParameter[10]=value; break;
        case $Pclutch1$Pphi_nominal_ : comp->fmuData->simulationInfo.realParameter[11]=value; break;
        case $Pclutch1$Pw_small_ : comp->fmuData->simulationInfo.realParameter[12]=value; break;
        case $Pclutch2$Pcgeo_ : comp->fmuData->simulationInfo.realParameter[13]=value; break;
        case $Pclutch2$Pfn_max_ : comp->fmuData->simulationInfo.realParameter[14]=value; break;
        case $Pclutch2$Pmue_pos$lB1$c1$rB_ : comp->fmuData->simulationInfo.realParameter[15]=value; break;
        case $Pclutch2$Pmue_pos$lB1$c2$rB_ : comp->fmuData->simulationInfo.realParameter[16]=value; break;
        case $Pclutch2$Ppeak_ : comp->fmuData->simulationInfo.realParameter[17]=value; break;
        case $Pclutch2$Pphi_nominal_ : comp->fmuData->simulationInfo.realParameter[18]=value; break;
        case $Pclutch2$Pw_small_ : comp->fmuData->simulationInfo.realParameter[19]=value; break;
        case $Pclutch3$Pcgeo_ : comp->fmuData->simulationInfo.realParameter[20]=value; break;
        case $Pclutch3$Pfn_max_ : comp->fmuData->simulationInfo.realParameter[21]=value; break;
        case $Pclutch3$Pmue_pos$lB1$c1$rB_ : comp->fmuData->simulationInfo.realParameter[22]=value; break;
        case $Pclutch3$Pmue_pos$lB1$c2$rB_ : comp->fmuData->simulationInfo.realParameter[23]=value; break;
        case $Pclutch3$Ppeak_ : comp->fmuData->simulationInfo.realParameter[24]=value; break;
        case $Pclutch3$Pphi_nominal_ : comp->fmuData->simulationInfo.realParameter[25]=value; break;
        case $Pclutch3$Pw_small_ : comp->fmuData->simulationInfo.realParameter[26]=value; break;
        case $Pfixed$Pphi0_ : comp->fmuData->simulationInfo.realParameter[27]=value; break;
        case $PfreqHz_ : comp->fmuData->simulationInfo.realParameter[28]=value; break;
        case $Psin1$Pamplitude_ : comp->fmuData->simulationInfo.realParameter[29]=value; break;
        case $Psin1$PfreqHz_ : comp->fmuData->simulationInfo.realParameter[30]=value; break;
        case $Psin1$Poffset_ : comp->fmuData->simulationInfo.realParameter[31]=value; break;
        case $Psin1$Pphase_ : comp->fmuData->simulationInfo.realParameter[32]=value; break;
        case $Psin1$PstartTime_ : comp->fmuData->simulationInfo.realParameter[33]=value; break;
        case $Psin2$Pamplitude_ : comp->fmuData->simulationInfo.realParameter[34]=value; break;
        case $Psin2$PfreqHz_ : comp->fmuData->simulationInfo.realParameter[35]=value; break;
        case $Psin2$Poffset_ : comp->fmuData->simulationInfo.realParameter[36]=value; break;
        case $Psin2$Pphase_ : comp->fmuData->simulationInfo.realParameter[37]=value; break;
        case $Psin2$PstartTime_ : comp->fmuData->simulationInfo.realParameter[38]=value; break;
        case $Pstep1$Pheight_ : comp->fmuData->simulationInfo.realParameter[39]=value; break;
        case $Pstep1$Poffset_ : comp->fmuData->simulationInfo.realParameter[40]=value; break;
        case $Pstep1$PstartTime_ : comp->fmuData->simulationInfo.realParameter[41]=value; break;
        case $P$DER$PJ1$Pphi_ : return setReal(comp, $PJ1_w1_, value); break;
        case $P$DER$PJ1$Pw_ : return setReal(comp, $PJ1$Pa_, value); break;
        case $P$DER$PJ2$Pphi_ : return setReal(comp, $PJ2_w1_, value); break;
        case $P$DER$PJ2$Pw_ : return setReal(comp, $PJ2$Pa_, value); break;
        case $P$DER$PJ4$Pphi_ : return setReal(comp, $PJ4_w1_, value); break;
        case $P$DER$PJ4$Pw_ : return setReal(comp, $PJ4$Pa_, value); break;
        case $PJ1$Pflange_a$Pphi_ : return setReal(comp, $PJ1$Pphi_, value); break;
        case $PJ1$Pflange_a$Ptau_ : return setReal(comp, $Psin1$Py_, value); break;
        case $PJ1$Pflange_b$Pphi_ : return setReal(comp, $PJ1$Pphi_, value); break;
        case $PJ1$Pflange_b$Ptau_ : return setReal(comp, $Pclutch1$Ptau_, value); break;
        case $PJ1$Pw_ : return setReal(comp, $PJ1_w1_, value); break;
        case $PJ2$Pflange_a$Pphi_ : return setReal(comp, $PJ2$Pphi_, value); break;
        case $PJ2$Pflange_a$Ptau_ : return setReal(comp, $Pclutch1$Ptau_, (- value)); break;
        case $PJ2$Pflange_b$Pphi_ : return setReal(comp, $PJ2$Pphi_, value); break;
        case $PJ2$Pflange_b$Ptau_ : return setReal(comp, $Pclutch2$Ptau_, value); break;
        case $PJ2$Pw_ : return setReal(comp, $PJ2_w1_, value); break;
        case $PJ3$Pflange_a$Pphi_ : return setReal(comp, $PJ3$Pphi_, value); break;
        case $PJ3$Pflange_a$Ptau_ : return setReal(comp, $Pclutch2$Ptau_, (- value)); break;
        case $PJ3$Pflange_b$Pphi_ : return setReal(comp, $PJ3$Pphi_, value); break;
        case $PJ3$Pflange_b$Ptau_ : return setReal(comp, $Pclutch3$Ptau_, value); break;
        case $PJ4$Pflange_a$Pphi_ : return setReal(comp, $PJ4$Pphi_, value); break;
        case $PJ4$Pflange_a$Ptau_ : return setReal(comp, $Pclutch3$Ptau_, (- value)); break;
        case $PJ4$Pflange_b$Pphi_ : return setReal(comp, $PJ4$Pphi_, value); break;
        case $PJ4$Pw_ : return setReal(comp, $PJ4_w1_, value); break;
        case $Pclutch1$Pa_rel_ : return setReal(comp, $Pclutch1$Pa_relfric_, value); break;
        case $Pclutch1$Pflange_a$Pphi_ : return setReal(comp, $PJ1$Pphi_, value); break;
        case $Pclutch1$Pflange_a$Ptau_ : return setReal(comp, $Pclutch1$Ptau_, (- value)); break;
        case $Pclutch1$Pflange_b$Pphi_ : return setReal(comp, $PJ2$Pphi_, value); break;
        case $Pclutch1$Pflange_b$Ptau_ : return setReal(comp, $Pclutch1$Ptau_, value); break;
        case $Pclutch1$Pw_relfric_ : return setReal(comp, $Pclutch1$Pw_rel_, value); break;
        case $Pclutch2$Pa_rel_ : return setReal(comp, $Pclutch2$Pa_relfric_, value); break;
        case $Pclutch2$Pflange_a$Pphi_ : return setReal(comp, $PJ2$Pphi_, value); break;
        case $Pclutch2$Pflange_a$Ptau_ : return setReal(comp, $Pclutch2$Ptau_, (- value)); break;
        case $Pclutch2$Pflange_b$Pphi_ : return setReal(comp, $PJ3$Pphi_, value); break;
        case $Pclutch2$Pflange_b$Ptau_ : return setReal(comp, $Pclutch2$Ptau_, value); break;
        case $Pclutch2$Pw_relfric_ : return setReal(comp, $Pclutch2$Pw_rel_, value); break;
        case $Pclutch3$Pa_rel_ : return setReal(comp, $Pclutch3$Pa_relfric_, value); break;
        case $Pclutch3$Pf_normalized_ : return setReal(comp, $Pstep2_, value); break;
        case $Pclutch3$Pflange_a$Pphi_ : return setReal(comp, $PJ3$Pphi_, value); break;
        case $Pclutch3$Pflange_a$Ptau_ : return setReal(comp, $Pclutch3$Ptau_, (- value)); break;
        case $Pclutch3$Pflange_b$Pphi_ : return setReal(comp, $PJ4$Pphi_, value); break;
        case $Pclutch3$Pflange_b$Ptau_ : return setReal(comp, $Pclutch3$Ptau_, value); break;
        case $Pclutch3$Pw_relfric_ : return setReal(comp, $Pclutch3$Pw_rel_, value); break;
        case $Pfixed$Pflange$Pphi_ : return setReal(comp, $Pfixed$Pphi0_, value); break;
        case $Pfixed$Pflange$Ptau_ : return setReal(comp, $Psin1$Py_, (- value)); break;
        case $Psin2$Py_ : return setReal(comp, $Pclutch1$Pf_normalized_, value); break;
        case $Pstep1$Py_ : return setReal(comp, $Pclutch2$Pf_normalized_, value); break;
        case $Ptorque$Pflange$Pphi_ : return setReal(comp, $PJ1$Pphi_, value); break;
        case $Ptorque$Pflange$Ptau_ : return setReal(comp, $Psin1$Py_, (- value)); break;
        case $Ptorque$Pphi_support_ : return setReal(comp, $Pfixed$Pphi0_, value); break;
        case $Ptorque$Psupport$Pphi_ : return setReal(comp, $Pfixed$Pphi0_, value); break;
        case $Ptorque$Psupport$Ptau_ : return setReal(comp, $Psin1$Py_, value); break;
        case $Ptorque$Ptau_ : return setReal(comp, $Psin1$Py_, value); break;
        default:
            return fmiError;
    }
    return fmiOK;
  }
  
  fmiInteger getInteger(ModelInstance* comp, const fmiValueReference vr) {
    switch (vr) {
        case $Pclutch1$Pmode_ : return comp->fmuData->localData[0]->integerVars[0]; break;
        case $Pclutch2$Pmode_ : return comp->fmuData->localData[0]->integerVars[1]; break;
        case $Pclutch3$Pmode_ : return comp->fmuData->localData[0]->integerVars[2]; break;
        case $PJ1$PstateSelect_ : return comp->fmuData->simulationInfo.integerParameter[0]; break;
        case $PJ2$PstateSelect_ : return comp->fmuData->simulationInfo.integerParameter[1]; break;
        case $PJ3$PstateSelect_ : return comp->fmuData->simulationInfo.integerParameter[2]; break;
        case $PJ4$PstateSelect_ : return comp->fmuData->simulationInfo.integerParameter[3]; break;
        case $Pclutch1$PstateSelect_ : return comp->fmuData->simulationInfo.integerParameter[4]; break;
        case $Pclutch2$PstateSelect_ : return comp->fmuData->simulationInfo.integerParameter[5]; break;
        case $Pclutch3$PstateSelect_ : return comp->fmuData->simulationInfo.integerParameter[6]; break;
        default:
            return 0;
    }
  }
  fmiStatus setInteger(ModelInstance* comp, const fmiValueReference vr, const fmiInteger value) {
    switch (vr) {
        case $Pclutch1$Pmode_ : comp->fmuData->localData[0]->integerVars[0]=value; break;
        case $Pclutch2$Pmode_ : comp->fmuData->localData[0]->integerVars[1]=value; break;
        case $Pclutch3$Pmode_ : comp->fmuData->localData[0]->integerVars[2]=value; break;
        case $PJ1$PstateSelect_ : comp->fmuData->simulationInfo.integerParameter[0]=value; break;
        case $PJ2$PstateSelect_ : comp->fmuData->simulationInfo.integerParameter[1]=value; break;
        case $PJ3$PstateSelect_ : comp->fmuData->simulationInfo.integerParameter[2]=value; break;
        case $PJ4$PstateSelect_ : comp->fmuData->simulationInfo.integerParameter[3]=value; break;
        case $Pclutch1$PstateSelect_ : comp->fmuData->simulationInfo.integerParameter[4]=value; break;
        case $Pclutch2$PstateSelect_ : comp->fmuData->simulationInfo.integerParameter[5]=value; break;
        case $Pclutch3$PstateSelect_ : comp->fmuData->simulationInfo.integerParameter[6]=value; break;
        default:
            return fmiError;
    }
    return fmiOK;
  }
  fmiBoolean getBoolean(ModelInstance* comp, const fmiValueReference vr) {
    switch (vr) {
        case $Pclutch1$Pfree_ : return comp->fmuData->localData[0]->booleanVars[0]; break;
        case $Pclutch1$Plocked_ : return comp->fmuData->localData[0]->booleanVars[1]; break;
        case $Pclutch1$PstartBackward_ : return comp->fmuData->localData[0]->booleanVars[2]; break;
        case $Pclutch1$PstartForward_ : return comp->fmuData->localData[0]->booleanVars[3]; break;
        case $Pclutch2$Pfree_ : return comp->fmuData->localData[0]->booleanVars[4]; break;
        case $Pclutch2$Plocked_ : return comp->fmuData->localData[0]->booleanVars[5]; break;
        case $Pclutch2$PstartBackward_ : return comp->fmuData->localData[0]->booleanVars[6]; break;
        case $Pclutch2$PstartForward_ : return comp->fmuData->localData[0]->booleanVars[7]; break;
        case $Pclutch3$Pfree_ : return comp->fmuData->localData[0]->booleanVars[8]; break;
        case $Pclutch3$Plocked_ : return comp->fmuData->localData[0]->booleanVars[9]; break;
        case $Pclutch3$PstartBackward_ : return comp->fmuData->localData[0]->booleanVars[10]; break;
        case $Pclutch3$PstartForward_ : return comp->fmuData->localData[0]->booleanVars[11]; break;
        case $Pclutch1$PuseHeatPort_ : return comp->fmuData->simulationInfo.booleanParameter[0]; break;
        case $Pclutch2$PuseHeatPort_ : return comp->fmuData->simulationInfo.booleanParameter[1]; break;
        case $Pclutch3$PuseHeatPort_ : return comp->fmuData->simulationInfo.booleanParameter[2]; break;
        case $Ptorque$PuseSupport_ : return comp->fmuData->simulationInfo.booleanParameter[3]; break;
        default:
            return fmiFalse;
    }
  }
  
  fmiStatus setBoolean(ModelInstance* comp, const fmiValueReference vr, const fmiBoolean value) {
    switch (vr) {
        case $Pclutch1$Pfree_ : comp->fmuData->localData[0]->booleanVars[0]=value; break;
        case $Pclutch1$Plocked_ : comp->fmuData->localData[0]->booleanVars[1]=value; break;
        case $Pclutch1$PstartBackward_ : comp->fmuData->localData[0]->booleanVars[2]=value; break;
        case $Pclutch1$PstartForward_ : comp->fmuData->localData[0]->booleanVars[3]=value; break;
        case $Pclutch2$Pfree_ : comp->fmuData->localData[0]->booleanVars[4]=value; break;
        case $Pclutch2$Plocked_ : comp->fmuData->localData[0]->booleanVars[5]=value; break;
        case $Pclutch2$PstartBackward_ : comp->fmuData->localData[0]->booleanVars[6]=value; break;
        case $Pclutch2$PstartForward_ : comp->fmuData->localData[0]->booleanVars[7]=value; break;
        case $Pclutch3$Pfree_ : comp->fmuData->localData[0]->booleanVars[8]=value; break;
        case $Pclutch3$Plocked_ : comp->fmuData->localData[0]->booleanVars[9]=value; break;
        case $Pclutch3$PstartBackward_ : comp->fmuData->localData[0]->booleanVars[10]=value; break;
        case $Pclutch3$PstartForward_ : comp->fmuData->localData[0]->booleanVars[11]=value; break;
        case $Pclutch1$PuseHeatPort_ : comp->fmuData->simulationInfo.booleanParameter[0]=value; break;
        case $Pclutch2$PuseHeatPort_ : comp->fmuData->simulationInfo.booleanParameter[1]=value; break;
        case $Pclutch3$PuseHeatPort_ : comp->fmuData->simulationInfo.booleanParameter[2]=value; break;
        case $Ptorque$PuseSupport_ : comp->fmuData->simulationInfo.booleanParameter[3]=value; break;
        default:
            return fmiError;
    }
    return fmiOK;
  }
  
  fmiString getString(ModelInstance* comp, const fmiValueReference vr) {
    switch (vr) {
        default:
            return "";
    }
  }
  
  fmiStatus setString(ModelInstance* comp, const fmiValueReference vr, fmiString value) {
    switch (vr) {
        default:
            return fmiError;
    }
    return fmiOK;
  }
  
  fmiStatus setExternalFunction(ModelInstance* c, const fmiValueReference vr, const void* value){
    switch (vr) {
        default:
            return fmiError;
    }
    return fmiOK;
  }
  

#ifdef __cplusplus
}
#endif

