
// define class name and unique id
#define MODEL_IDENTIFIER IntegerNetwork1
#define MODEL_GUID "{8c4e810f-3df3-4a00-8276-176fa3c9f9e0}"

// include fmu header files, typedefs and macros
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "util/omc_error.h"
#include "IntegerNetwork1_functions.h"
#include "IntegerNetwork1_literals.h"
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
#define NUMBER_OF_STATES 0
#define NUMBER_OF_EVENT_INDICATORS 8
#define NUMBER_OF_REALS 18
#define NUMBER_OF_INTEGERS 42
#define NUMBER_OF_STRINGS 0
#define NUMBER_OF_BOOLEANS 17
#define NUMBER_OF_EXTERNALFUNCTIONS 0

// define variable data for model
#define $Py5_ 0 
#define $PbooleanPulse1$PpulsStart_ 1 // "Start time of pulse"
#define $PbooleanPulse2$PpulsStart_ 2 // "Start time of pulse"
#define $PbooleanPulse1$PTwidth_ 3 // "width of one pulse"
#define $PbooleanPulse1$Pperiod_ 4 // "Time for one period"
#define $PbooleanPulse1$PstartTime_ 5 // "Time instant of first pulse"
#define $PbooleanPulse1$Pwidth_ 6 // "Width of pulse in % of period"
#define $PbooleanPulse2$PTwidth_ 7 // "width of one pulse"
#define $PbooleanPulse2$Pperiod_ 8 // "Time for one period"
#define $PbooleanPulse2$PstartTime_ 9 // "Time instant of first pulse"
#define $PbooleanPulse2$Pwidth_ 10 // "Width of pulse in % of period"
#define $Psine$Pamplitude_ 11 // "Amplitude of sine wave"
#define $Psine$PfreqHz_ 12 // "Frequency of sine wave"
#define $Psine$Poffset_ 13 // "Offset of output signal"
#define $Psine$Pphase_ 14 // "Phase of sine wave"
#define $Psine$PstartTime_ 15 // "Output = offset for time < startTime"
#define $PrealToInteger$Pu_ 16 // "Connector of Real input signal"
#define $Psine$Py_ 17 // "Connector of Real output signal"
#define $PintegerStep_ 0 
#define $PmultiSwitch1$Pexpr$lB1$rB_ 1 // "y = if u[i] then expr[i] elseif use_pre_as_default then pre(y) else y_default"
#define $PmultiSwitch1$Pexpr$lB2$rB_ 2 // "y = if u[i] then expr[i] elseif use_pre_as_default then pre(y) else y_default"
#define $PmultiSwitch1$PfirstActiveIndex_ 3 
#define $PmultiSwitch1$Py_ 4 // "Output depending on expression"
#define $PshowValue$Pnumber_ 5 // "Number to visualize if use_numberPort=false (time varying)"
#define $PshowValue1$Pnumber_ 6 // "Number to visualize if use_numberPort=false (time varying)"
#define $PshowValue2$Pnumber_ 7 // "Number to visualize if use_numberPort=false (time varying)"
#define $PtriggeredAdd$Plocal_set_ 8 
#define $PtriggeredAdd$Py_ 9 // "Integer output signal"
#define $Py_ 10 
#define $Py1_ 11 
#define $Py2_ 12 
#define $Py3_ 13 
#define $Py4_ 14 
#define $PintegerConstant$Pk_ 15 // "Constant output value"
#define $PmultiSwitch1$Pnu_ 16 // "Number of input connections"
#define $PmultiSwitch1$Py_default_ 17 // "Default value of output y if use_pre_as_default=false, as well as pre(y) at initial time"
#define $Pproduct$Pnu_ 18 // "Number of input connections"
#define $Psum$Pk$lB1$rB_ 19 // "Input gains"
#define $Psum$Pk$lB2$rB_ 20 // "Input gains"
#define $Psum$Pk$lB3$rB_ 21 // "Input gains"
#define $Psum$Pnu_ 22 // "Number of input connections"
#define $PtriggeredAdd$Py_start_ 23 // "Initial and reset value of y if set port is not used"
#define $PintegerConstant$Py_ 24 // "Connector of Integer output signal"
#define $Pproduct$Pu$lB1$rB_ 25 // "Vector of Integer input signals"
#define $Pproduct$Pu$lB2$rB_ 26 // "Vector of Integer input signals"
#define $Pproduct$Py_ 27 // "Integer output signal"
#define $PrealToInteger$Py_ 28 // "Connector of Integer output signal"
#define $PshowValue$PnumberPort_ 29 // "Number to be shown in diagram layer if use_numberPort = true"
#define $PshowValue$PshowNumber_ 30 
#define $PshowValue1$PnumberPort_ 31 // "Number to be shown in diagram layer if use_numberPort = true"
#define $PshowValue1$PshowNumber_ 32 
#define $PshowValue2$PnumberPort_ 33 // "Number to be shown in diagram layer if use_numberPort = true"
#define $PshowValue2$PshowNumber_ 34 
#define $PshowValue3$Pnumber_ 35 // "Number to visualize if use_numberPort=false (time varying)"
#define $PshowValue3$PshowNumber_ 36 
#define $Psum$Pu$lB1$rB_ 37 // "Vector of Integer input signals"
#define $Psum$Pu$lB2$rB_ 38 // "Vector of Integer input signals"
#define $Psum$Pu$lB3$rB_ 39 // "Vector of Integer input signals"
#define $Psum$Py_ 40 // "Integer output signal"
#define $PtriggeredAdd$Pu_ 41 // "Integer input signal"
#define $P$whenCondition1_ 0 
#define $P$whenCondition2_ 1 
#define $P$whenCondition3_ 2 
#define $P$whenCondition4_ 3 
#define $PmultiSwitch1$Pu$lB1$rB_ 4 // "Set y = expr[i], if u[i] = true"
#define $PmultiSwitch1$Pu$lB2$rB_ 5 // "Set y = expr[i], if u[i] = true"
#define $PtriggeredAdd$Plocal_reset_ 6 
#define $PmultiSwitch1$Puse_pre_as_default_ 7 // "= true, y holds its last value if all u[i]=false, otherwise y=y_default"
#define $PshowValue$Puse_numberPort_ 8 // "= true, if numberPort enabled"
#define $PshowValue1$Puse_numberPort_ 9 // "= true, if numberPort enabled"
#define $PshowValue2$Puse_numberPort_ 10 // "= true, if numberPort enabled"
#define $PshowValue3$Puse_numberPort_ 11 // "= true, if numberPort enabled"
#define $PtriggeredAdd$Puse_reset_ 12 // "=true, if reset port enabled"
#define $PtriggeredAdd$Puse_set_ 13 // "=true, if set port enabled and used as default value when reset"
#define $PbooleanPulse1$Py_ 14 // "Connector of Boolean output signal"
#define $PbooleanPulse2$Py_ 15 // "Connector of Boolean output signal"
#define $PtriggeredAdd$Ptrigger_ 16 


// define initial state vector as vector of value references
#define STATES {  }
#define STATESDERIVATIVES {  }


// implementation of the Model Exchange functions
  extern void IntegerNetwork1_setupDataStruc(DATA *data);
  #define fmu1_model_interface_setupDataStruc IntegerNetwork1_setupDataStruc
  #include "fmu1_model_interface.c"

// Set values for all variables that define a start value
void setDefaultStartValues(ModelInstance *comp) {

comp->fmuData->modelData.realVarsData[0].attribute.start = 0;
comp->fmuData->modelData.realVarsData[1].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[2].attribute.start = 0.0;
comp->fmuData->modelData.integerVarsData[0].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[1].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[2].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[3].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[4].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[5].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[6].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[7].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[8].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[9].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[10].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[11].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[12].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[13].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[14].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[0].attribute.start = 1;
comp->fmuData->modelData.booleanVarsData[1].attribute.start = 1;
comp->fmuData->modelData.booleanVarsData[2].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[3].attribute.start = 1;
comp->fmuData->modelData.booleanVarsData[4].attribute.start = 1;
comp->fmuData->modelData.booleanVarsData[5].attribute.start = 1;
comp->fmuData->modelData.booleanVarsData[6].attribute.start = 0;
comp->fmuData->modelData.realParameterData[0].attribute.start = 0.5;
comp->fmuData->modelData.realParameterData[1].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[2].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[3].attribute.start = 50.0;
comp->fmuData->modelData.realParameterData[4].attribute.start = 1.6;
comp->fmuData->modelData.realParameterData[5].attribute.start = 2.0;
comp->fmuData->modelData.realParameterData[6].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[7].attribute.start = 80.0;
comp->fmuData->modelData.realParameterData[8].attribute.start = 3.0;
comp->fmuData->modelData.realParameterData[9].attribute.start = 0.1;
comp->fmuData->modelData.realParameterData[10].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[11].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[12].attribute.start = 0.0;
comp->fmuData->modelData.integerParameterData[0].attribute.start = 1;
comp->fmuData->modelData.integerParameterData[1].attribute.start = 2;
comp->fmuData->modelData.integerParameterData[2].attribute.start = 2;
comp->fmuData->modelData.integerParameterData[3].attribute.start = 2;
comp->fmuData->modelData.integerParameterData[4].attribute.start = 1;
comp->fmuData->modelData.integerParameterData[5].attribute.start = 1;
comp->fmuData->modelData.integerParameterData[6].attribute.start = 1;
comp->fmuData->modelData.integerParameterData[7].attribute.start = 3;
comp->fmuData->modelData.integerParameterData[8].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[0].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[1].attribute.start = 1;
comp->fmuData->modelData.booleanParameterData[2].attribute.start = 1;
comp->fmuData->modelData.booleanParameterData[3].attribute.start = 1;
comp->fmuData->modelData.booleanParameterData[4].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[5].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[6].attribute.start = 0;
}
// Set values for all variables that define a start value
void setStartValues(ModelInstance *comp) {

  comp->fmuData->modelData.realVarsData[0].attribute.start =  comp->fmuData->localData[0]->realVars[0];
  comp->fmuData->modelData.realVarsData[1].attribute.start =  comp->fmuData->localData[0]->realVars[1];
  comp->fmuData->modelData.realVarsData[2].attribute.start =  comp->fmuData->localData[0]->realVars[2];
  comp->fmuData->modelData.integerVarsData[0].attribute.start =  comp->fmuData->localData[0]->integerVars[0];
  comp->fmuData->modelData.integerVarsData[1].attribute.start =  comp->fmuData->localData[0]->integerVars[1];
  comp->fmuData->modelData.integerVarsData[2].attribute.start =  comp->fmuData->localData[0]->integerVars[2];
  comp->fmuData->modelData.integerVarsData[3].attribute.start =  comp->fmuData->localData[0]->integerVars[3];
  comp->fmuData->modelData.integerVarsData[4].attribute.start =  comp->fmuData->localData[0]->integerVars[4];
  comp->fmuData->modelData.integerVarsData[5].attribute.start =  comp->fmuData->localData[0]->integerVars[5];
  comp->fmuData->modelData.integerVarsData[6].attribute.start =  comp->fmuData->localData[0]->integerVars[6];
  comp->fmuData->modelData.integerVarsData[7].attribute.start =  comp->fmuData->localData[0]->integerVars[7];
  comp->fmuData->modelData.integerVarsData[8].attribute.start =  comp->fmuData->localData[0]->integerVars[8];
  comp->fmuData->modelData.integerVarsData[9].attribute.start =  comp->fmuData->localData[0]->integerVars[9];
  comp->fmuData->modelData.integerVarsData[10].attribute.start =  comp->fmuData->localData[0]->integerVars[10];
  comp->fmuData->modelData.integerVarsData[11].attribute.start =  comp->fmuData->localData[0]->integerVars[11];
  comp->fmuData->modelData.integerVarsData[12].attribute.start =  comp->fmuData->localData[0]->integerVars[12];
  comp->fmuData->modelData.integerVarsData[13].attribute.start =  comp->fmuData->localData[0]->integerVars[13];
  comp->fmuData->modelData.integerVarsData[14].attribute.start =  comp->fmuData->localData[0]->integerVars[14];
  comp->fmuData->modelData.booleanVarsData[0].attribute.start =  comp->fmuData->localData[0]->booleanVars[0];
  comp->fmuData->modelData.booleanVarsData[1].attribute.start =  comp->fmuData->localData[0]->booleanVars[1];
  comp->fmuData->modelData.booleanVarsData[2].attribute.start =  comp->fmuData->localData[0]->booleanVars[2];
  comp->fmuData->modelData.booleanVarsData[3].attribute.start =  comp->fmuData->localData[0]->booleanVars[3];
  comp->fmuData->modelData.booleanVarsData[4].attribute.start =  comp->fmuData->localData[0]->booleanVars[4];
  comp->fmuData->modelData.booleanVarsData[5].attribute.start =  comp->fmuData->localData[0]->booleanVars[5];
  comp->fmuData->modelData.booleanVarsData[6].attribute.start =  comp->fmuData->localData[0]->booleanVars[6];
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
comp->fmuData->modelData.integerParameterData[0].attribute.start = comp->fmuData->simulationInfo.integerParameter[0];
comp->fmuData->modelData.integerParameterData[1].attribute.start = comp->fmuData->simulationInfo.integerParameter[1];
comp->fmuData->modelData.integerParameterData[2].attribute.start = comp->fmuData->simulationInfo.integerParameter[2];
comp->fmuData->modelData.integerParameterData[3].attribute.start = comp->fmuData->simulationInfo.integerParameter[3];
comp->fmuData->modelData.integerParameterData[4].attribute.start = comp->fmuData->simulationInfo.integerParameter[4];
comp->fmuData->modelData.integerParameterData[5].attribute.start = comp->fmuData->simulationInfo.integerParameter[5];
comp->fmuData->modelData.integerParameterData[6].attribute.start = comp->fmuData->simulationInfo.integerParameter[6];
comp->fmuData->modelData.integerParameterData[7].attribute.start = comp->fmuData->simulationInfo.integerParameter[7];
comp->fmuData->modelData.integerParameterData[8].attribute.start = comp->fmuData->simulationInfo.integerParameter[8];
comp->fmuData->modelData.booleanParameterData[0].attribute.start = comp->fmuData->simulationInfo.booleanParameter[0];
comp->fmuData->modelData.booleanParameterData[1].attribute.start = comp->fmuData->simulationInfo.booleanParameter[1];
comp->fmuData->modelData.booleanParameterData[2].attribute.start = comp->fmuData->simulationInfo.booleanParameter[2];
comp->fmuData->modelData.booleanParameterData[3].attribute.start = comp->fmuData->simulationInfo.booleanParameter[3];
comp->fmuData->modelData.booleanParameterData[4].attribute.start = comp->fmuData->simulationInfo.booleanParameter[4];
comp->fmuData->modelData.booleanParameterData[5].attribute.start = comp->fmuData->simulationInfo.booleanParameter[5];
comp->fmuData->modelData.booleanParameterData[6].attribute.start = comp->fmuData->simulationInfo.booleanParameter[6];
}
  // Used to set the next time event, if any.
  void eventUpdate(ModelInstance* comp, fmiEventInfo* eventInfo) {
  }
  
  fmiReal getReal(ModelInstance* comp, const fmiValueReference vr) {
    switch (vr) {
        case $Py5_ : return comp->fmuData->localData[0]->realVars[0]; break;
        case $PbooleanPulse1$PpulsStart_ : return comp->fmuData->localData[0]->realVars[1]; break;
        case $PbooleanPulse2$PpulsStart_ : return comp->fmuData->localData[0]->realVars[2]; break;
        case $PbooleanPulse1$PTwidth_ : return comp->fmuData->simulationInfo.realParameter[0]; break;
        case $PbooleanPulse1$Pperiod_ : return comp->fmuData->simulationInfo.realParameter[1]; break;
        case $PbooleanPulse1$PstartTime_ : return comp->fmuData->simulationInfo.realParameter[2]; break;
        case $PbooleanPulse1$Pwidth_ : return comp->fmuData->simulationInfo.realParameter[3]; break;
        case $PbooleanPulse2$PTwidth_ : return comp->fmuData->simulationInfo.realParameter[4]; break;
        case $PbooleanPulse2$Pperiod_ : return comp->fmuData->simulationInfo.realParameter[5]; break;
        case $PbooleanPulse2$PstartTime_ : return comp->fmuData->simulationInfo.realParameter[6]; break;
        case $PbooleanPulse2$Pwidth_ : return comp->fmuData->simulationInfo.realParameter[7]; break;
        case $Psine$Pamplitude_ : return comp->fmuData->simulationInfo.realParameter[8]; break;
        case $Psine$PfreqHz_ : return comp->fmuData->simulationInfo.realParameter[9]; break;
        case $Psine$Poffset_ : return comp->fmuData->simulationInfo.realParameter[10]; break;
        case $Psine$Pphase_ : return comp->fmuData->simulationInfo.realParameter[11]; break;
        case $Psine$PstartTime_ : return comp->fmuData->simulationInfo.realParameter[12]; break;
        case $PrealToInteger$Pu_ : return getReal(comp, $Py5_); break;
        case $Psine$Py_ : return getReal(comp, $Py5_); break;
        default:
            return 0;
    }
  }
  
  fmiStatus setReal(ModelInstance* comp, const fmiValueReference vr, const fmiReal value) {
    switch (vr) {
        case $Py5_ : comp->fmuData->localData[0]->realVars[0]=value; break;
        case $PbooleanPulse1$PpulsStart_ : comp->fmuData->localData[0]->realVars[1]=value; break;
        case $PbooleanPulse2$PpulsStart_ : comp->fmuData->localData[0]->realVars[2]=value; break;
        case $PbooleanPulse1$PTwidth_ : comp->fmuData->simulationInfo.realParameter[0]=value; break;
        case $PbooleanPulse1$Pperiod_ : comp->fmuData->simulationInfo.realParameter[1]=value; break;
        case $PbooleanPulse1$PstartTime_ : comp->fmuData->simulationInfo.realParameter[2]=value; break;
        case $PbooleanPulse1$Pwidth_ : comp->fmuData->simulationInfo.realParameter[3]=value; break;
        case $PbooleanPulse2$PTwidth_ : comp->fmuData->simulationInfo.realParameter[4]=value; break;
        case $PbooleanPulse2$Pperiod_ : comp->fmuData->simulationInfo.realParameter[5]=value; break;
        case $PbooleanPulse2$PstartTime_ : comp->fmuData->simulationInfo.realParameter[6]=value; break;
        case $PbooleanPulse2$Pwidth_ : comp->fmuData->simulationInfo.realParameter[7]=value; break;
        case $Psine$Pamplitude_ : comp->fmuData->simulationInfo.realParameter[8]=value; break;
        case $Psine$PfreqHz_ : comp->fmuData->simulationInfo.realParameter[9]=value; break;
        case $Psine$Poffset_ : comp->fmuData->simulationInfo.realParameter[10]=value; break;
        case $Psine$Pphase_ : comp->fmuData->simulationInfo.realParameter[11]=value; break;
        case $Psine$PstartTime_ : comp->fmuData->simulationInfo.realParameter[12]=value; break;
        case $PrealToInteger$Pu_ : return setReal(comp, $Py5_, value); break;
        case $Psine$Py_ : return setReal(comp, $Py5_, value); break;
        default:
            return fmiError;
    }
    return fmiOK;
  }
  
  fmiInteger getInteger(ModelInstance* comp, const fmiValueReference vr) {
    switch (vr) {
        case $PintegerStep_ : return comp->fmuData->localData[0]->integerVars[0]; break;
        case $PmultiSwitch1$Pexpr$lB1$rB_ : return comp->fmuData->localData[0]->integerVars[1]; break;
        case $PmultiSwitch1$Pexpr$lB2$rB_ : return comp->fmuData->localData[0]->integerVars[2]; break;
        case $PmultiSwitch1$PfirstActiveIndex_ : return comp->fmuData->localData[0]->integerVars[3]; break;
        case $PmultiSwitch1$Py_ : return comp->fmuData->localData[0]->integerVars[4]; break;
        case $PshowValue$Pnumber_ : return comp->fmuData->localData[0]->integerVars[5]; break;
        case $PshowValue1$Pnumber_ : return comp->fmuData->localData[0]->integerVars[6]; break;
        case $PshowValue2$Pnumber_ : return comp->fmuData->localData[0]->integerVars[7]; break;
        case $PtriggeredAdd$Plocal_set_ : return comp->fmuData->localData[0]->integerVars[8]; break;
        case $PtriggeredAdd$Py_ : return comp->fmuData->localData[0]->integerVars[9]; break;
        case $Py_ : return comp->fmuData->localData[0]->integerVars[10]; break;
        case $Py1_ : return comp->fmuData->localData[0]->integerVars[11]; break;
        case $Py2_ : return comp->fmuData->localData[0]->integerVars[12]; break;
        case $Py3_ : return comp->fmuData->localData[0]->integerVars[13]; break;
        case $Py4_ : return comp->fmuData->localData[0]->integerVars[14]; break;
        case $PintegerConstant$Pk_ : return comp->fmuData->simulationInfo.integerParameter[0]; break;
        case $PmultiSwitch1$Pnu_ : return comp->fmuData->simulationInfo.integerParameter[1]; break;
        case $PmultiSwitch1$Py_default_ : return comp->fmuData->simulationInfo.integerParameter[2]; break;
        case $Pproduct$Pnu_ : return comp->fmuData->simulationInfo.integerParameter[3]; break;
        case $Psum$Pk$lB1$rB_ : return comp->fmuData->simulationInfo.integerParameter[4]; break;
        case $Psum$Pk$lB2$rB_ : return comp->fmuData->simulationInfo.integerParameter[5]; break;
        case $Psum$Pk$lB3$rB_ : return comp->fmuData->simulationInfo.integerParameter[6]; break;
        case $Psum$Pnu_ : return comp->fmuData->simulationInfo.integerParameter[7]; break;
        case $PtriggeredAdd$Py_start_ : return comp->fmuData->simulationInfo.integerParameter[8]; break;
        case $PintegerConstant$Py_ : return getInteger(comp, $PintegerConstant$Pk_); break;
        case $Pproduct$Pu$lB1$rB_ : return getInteger(comp, $Py3_); break;
        case $Pproduct$Pu$lB2$rB_ : return getInteger(comp, $PintegerStep_); break;
        case $Pproduct$Py_ : return getInteger(comp, $Py1_); break;
        case $PrealToInteger$Py_ : return getInteger(comp, $Py2_); break;
        case $PshowValue$PnumberPort_ : return getInteger(comp, $Py3_); break;
        case $PshowValue$PshowNumber_ : return getInteger(comp, $Py3_); break;
        case $PshowValue1$PnumberPort_ : return getInteger(comp, $Py1_); break;
        case $PshowValue1$PshowNumber_ : return getInteger(comp, $Py1_); break;
        case $PshowValue2$PnumberPort_ : return getInteger(comp, $PtriggeredAdd$Py_); break;
        case $PshowValue2$PshowNumber_ : return getInteger(comp, $PtriggeredAdd$Py_); break;
        case $PshowValue3$Pnumber_ : return getInteger(comp, $Py_); break;
        case $PshowValue3$PshowNumber_ : return getInteger(comp, $Py_); break;
        case $Psum$Pu$lB1$rB_ : return getInteger(comp, $Py2_); break;
        case $Psum$Pu$lB2$rB_ : return getInteger(comp, $PintegerStep_); break;
        case $Psum$Pu$lB3$rB_ : return getInteger(comp, $PintegerConstant$Pk_); break;
        case $Psum$Py_ : return getInteger(comp, $Py3_); break;
        case $PtriggeredAdd$Pu_ : return getInteger(comp, $PintegerConstant$Pk_); break;
        default:
            return 0;
    }
  }
  fmiStatus setInteger(ModelInstance* comp, const fmiValueReference vr, const fmiInteger value) {
    switch (vr) {
        case $PintegerStep_ : comp->fmuData->localData[0]->integerVars[0]=value; break;
        case $PmultiSwitch1$Pexpr$lB1$rB_ : comp->fmuData->localData[0]->integerVars[1]=value; break;
        case $PmultiSwitch1$Pexpr$lB2$rB_ : comp->fmuData->localData[0]->integerVars[2]=value; break;
        case $PmultiSwitch1$PfirstActiveIndex_ : comp->fmuData->localData[0]->integerVars[3]=value; break;
        case $PmultiSwitch1$Py_ : comp->fmuData->localData[0]->integerVars[4]=value; break;
        case $PshowValue$Pnumber_ : comp->fmuData->localData[0]->integerVars[5]=value; break;
        case $PshowValue1$Pnumber_ : comp->fmuData->localData[0]->integerVars[6]=value; break;
        case $PshowValue2$Pnumber_ : comp->fmuData->localData[0]->integerVars[7]=value; break;
        case $PtriggeredAdd$Plocal_set_ : comp->fmuData->localData[0]->integerVars[8]=value; break;
        case $PtriggeredAdd$Py_ : comp->fmuData->localData[0]->integerVars[9]=value; break;
        case $Py_ : comp->fmuData->localData[0]->integerVars[10]=value; break;
        case $Py1_ : comp->fmuData->localData[0]->integerVars[11]=value; break;
        case $Py2_ : comp->fmuData->localData[0]->integerVars[12]=value; break;
        case $Py3_ : comp->fmuData->localData[0]->integerVars[13]=value; break;
        case $Py4_ : comp->fmuData->localData[0]->integerVars[14]=value; break;
        case $PintegerConstant$Pk_ : comp->fmuData->simulationInfo.integerParameter[0]=value; break;
        case $PmultiSwitch1$Pnu_ : comp->fmuData->simulationInfo.integerParameter[1]=value; break;
        case $PmultiSwitch1$Py_default_ : comp->fmuData->simulationInfo.integerParameter[2]=value; break;
        case $Pproduct$Pnu_ : comp->fmuData->simulationInfo.integerParameter[3]=value; break;
        case $Psum$Pk$lB1$rB_ : comp->fmuData->simulationInfo.integerParameter[4]=value; break;
        case $Psum$Pk$lB2$rB_ : comp->fmuData->simulationInfo.integerParameter[5]=value; break;
        case $Psum$Pk$lB3$rB_ : comp->fmuData->simulationInfo.integerParameter[6]=value; break;
        case $Psum$Pnu_ : comp->fmuData->simulationInfo.integerParameter[7]=value; break;
        case $PtriggeredAdd$Py_start_ : comp->fmuData->simulationInfo.integerParameter[8]=value; break;
        case $PintegerConstant$Py_ : return setInteger(comp, $PintegerConstant$Pk_, value); break;
        case $Pproduct$Pu$lB1$rB_ : return setInteger(comp, $Py3_, value); break;
        case $Pproduct$Pu$lB2$rB_ : return setInteger(comp, $PintegerStep_, value); break;
        case $Pproduct$Py_ : return setInteger(comp, $Py1_, value); break;
        case $PrealToInteger$Py_ : return setInteger(comp, $Py2_, value); break;
        case $PshowValue$PnumberPort_ : return setInteger(comp, $Py3_, value); break;
        case $PshowValue$PshowNumber_ : return setInteger(comp, $Py3_, value); break;
        case $PshowValue1$PnumberPort_ : return setInteger(comp, $Py1_, value); break;
        case $PshowValue1$PshowNumber_ : return setInteger(comp, $Py1_, value); break;
        case $PshowValue2$PnumberPort_ : return setInteger(comp, $PtriggeredAdd$Py_, value); break;
        case $PshowValue2$PshowNumber_ : return setInteger(comp, $PtriggeredAdd$Py_, value); break;
        case $PshowValue3$Pnumber_ : return setInteger(comp, $Py_, value); break;
        case $PshowValue3$PshowNumber_ : return setInteger(comp, $Py_, value); break;
        case $Psum$Pu$lB1$rB_ : return setInteger(comp, $Py2_, value); break;
        case $Psum$Pu$lB2$rB_ : return setInteger(comp, $PintegerStep_, value); break;
        case $Psum$Pu$lB3$rB_ : return setInteger(comp, $PintegerConstant$Pk_, value); break;
        case $Psum$Py_ : return setInteger(comp, $Py3_, value); break;
        case $PtriggeredAdd$Pu_ : return setInteger(comp, $PintegerConstant$Pk_, value); break;
        default:
            return fmiError;
    }
    return fmiOK;
  }
  fmiBoolean getBoolean(ModelInstance* comp, const fmiValueReference vr) {
    switch (vr) {
        case $P$whenCondition1_ : return comp->fmuData->localData[0]->booleanVars[0]; break;
        case $P$whenCondition2_ : return comp->fmuData->localData[0]->booleanVars[1]; break;
        case $P$whenCondition3_ : return comp->fmuData->localData[0]->booleanVars[2]; break;
        case $P$whenCondition4_ : return comp->fmuData->localData[0]->booleanVars[3]; break;
        case $PmultiSwitch1$Pu$lB1$rB_ : return comp->fmuData->localData[0]->booleanVars[4]; break;
        case $PmultiSwitch1$Pu$lB2$rB_ : return comp->fmuData->localData[0]->booleanVars[5]; break;
        case $PtriggeredAdd$Plocal_reset_ : return comp->fmuData->localData[0]->booleanVars[6]; break;
        case $PmultiSwitch1$Puse_pre_as_default_ : return comp->fmuData->simulationInfo.booleanParameter[0]; break;
        case $PshowValue$Puse_numberPort_ : return comp->fmuData->simulationInfo.booleanParameter[1]; break;
        case $PshowValue1$Puse_numberPort_ : return comp->fmuData->simulationInfo.booleanParameter[2]; break;
        case $PshowValue2$Puse_numberPort_ : return comp->fmuData->simulationInfo.booleanParameter[3]; break;
        case $PshowValue3$Puse_numberPort_ : return comp->fmuData->simulationInfo.booleanParameter[4]; break;
        case $PtriggeredAdd$Puse_reset_ : return comp->fmuData->simulationInfo.booleanParameter[5]; break;
        case $PtriggeredAdd$Puse_set_ : return comp->fmuData->simulationInfo.booleanParameter[6]; break;
        case $PbooleanPulse1$Py_ : return getBoolean(comp, $PmultiSwitch1$Pu$lB1$rB_); break;
        case $PbooleanPulse2$Py_ : return getBoolean(comp, $PmultiSwitch1$Pu$lB2$rB_); break;
        case $PtriggeredAdd$Ptrigger_ : return getBoolean(comp, $PmultiSwitch1$Pu$lB1$rB_); break;
        default:
            return fmiFalse;
    }
  }
  
  fmiStatus setBoolean(ModelInstance* comp, const fmiValueReference vr, const fmiBoolean value) {
    switch (vr) {
        case $P$whenCondition1_ : comp->fmuData->localData[0]->booleanVars[0]=value; break;
        case $P$whenCondition2_ : comp->fmuData->localData[0]->booleanVars[1]=value; break;
        case $P$whenCondition3_ : comp->fmuData->localData[0]->booleanVars[2]=value; break;
        case $P$whenCondition4_ : comp->fmuData->localData[0]->booleanVars[3]=value; break;
        case $PmultiSwitch1$Pu$lB1$rB_ : comp->fmuData->localData[0]->booleanVars[4]=value; break;
        case $PmultiSwitch1$Pu$lB2$rB_ : comp->fmuData->localData[0]->booleanVars[5]=value; break;
        case $PtriggeredAdd$Plocal_reset_ : comp->fmuData->localData[0]->booleanVars[6]=value; break;
        case $PmultiSwitch1$Puse_pre_as_default_ : comp->fmuData->simulationInfo.booleanParameter[0]=value; break;
        case $PshowValue$Puse_numberPort_ : comp->fmuData->simulationInfo.booleanParameter[1]=value; break;
        case $PshowValue1$Puse_numberPort_ : comp->fmuData->simulationInfo.booleanParameter[2]=value; break;
        case $PshowValue2$Puse_numberPort_ : comp->fmuData->simulationInfo.booleanParameter[3]=value; break;
        case $PshowValue3$Puse_numberPort_ : comp->fmuData->simulationInfo.booleanParameter[4]=value; break;
        case $PtriggeredAdd$Puse_reset_ : comp->fmuData->simulationInfo.booleanParameter[5]=value; break;
        case $PtriggeredAdd$Puse_set_ : comp->fmuData->simulationInfo.booleanParameter[6]=value; break;
        case $PbooleanPulse1$Py_ : return setBoolean(comp, $PmultiSwitch1$Pu$lB1$rB_, value); break;
        case $PbooleanPulse2$Py_ : return setBoolean(comp, $PmultiSwitch1$Pu$lB2$rB_, value); break;
        case $PtriggeredAdd$Ptrigger_ : return setBoolean(comp, $PmultiSwitch1$Pu$lB1$rB_, value); break;
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

