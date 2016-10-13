
// define class name and unique id
#define MODEL_IDENTIFIER BooleanNetwork1
#define MODEL_GUID "{8c4e810f-3df3-4a00-8276-176fa3c9f9e0}"

// include fmu header files, typedefs and macros
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "openmodelica.h"
#include "openmodelica_func.h"
#include "simulation_data.h"
#include "util/omc_error.h"
#include "BooleanNetwork1_functions.h"
#include "BooleanNetwork1_literals.h"
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
#define NUMBER_OF_EVENT_INDICATORS 4
#define NUMBER_OF_REALS 24
#define NUMBER_OF_INTEGERS 19
#define NUMBER_OF_STRINGS 0
#define NUMBER_OF_BOOLEANS 101
#define NUMBER_OF_EXTERNALFUNCTIONS 0

// define variable data for model
#define $PbooleanPulse1$PpulsStart_ 0 // "Start time of pulse"
#define $PbooleanPulse2$PpulsStart_ 1 // "Start time of pulse"
#define $PbooleanTable$PnextTime_ 2 
#define $PonDelay$Pt_next_ 3 
#define $PbooleanPulse1$PTwidth_ 4 // "width of one pulse"
#define $PbooleanPulse1$Pperiod_ 5 // "Time for one period"
#define $PbooleanPulse1$PstartTime_ 6 // "Time instant of first pulse"
#define $PbooleanPulse1$Pwidth_ 7 // "Width of pulse in % of period"
#define $PbooleanPulse2$PTwidth_ 8 // "width of one pulse"
#define $PbooleanPulse2$Pperiod_ 9 // "Time for one period"
#define $PbooleanPulse2$PstartTime_ 10 // "Time instant of first pulse"
#define $PbooleanPulse2$Pwidth_ 11 // "Width of pulse in % of period"
#define $PbooleanTable$Ptable$lB1$rB_ 12 // "Vector of time points. At every time point, the output y gets its opposite value (e.g., table={0,1})"
#define $PbooleanTable$Ptable$lB2$rB_ 13 // "Vector of time points. At every time point, the output y gets its opposite value (e.g., table={0,1})"
#define $PbooleanTable$Ptable$lB3$rB_ 14 // "Vector of time points. At every time point, the output y gets its opposite value (e.g., table={0,1})"
#define $PbooleanTable$Ptable$lB4$rB_ 15 // "Vector of time points. At every time point, the output y gets its opposite value (e.g., table={0,1})"
#define $PbooleanTable$Ptable$lB5$rB_ 16 // "Vector of time points. At every time point, the output y gets its opposite value (e.g., table={0,1})"
#define $PbooleanTable$Ptable$lB6$rB_ 17 // "Vector of time points. At every time point, the output y gets its opposite value (e.g., table={0,1})"
#define $PbooleanTable$Ptable$lB7$rB_ 18 // "Vector of time points. At every time point, the output y gets its opposite value (e.g., table={0,1})"
#define $PonDelay$PdelayTime_ 19 // "Delay time"
#define $PsampleTriggerReset$Pperiod_ 20 // "Sample period"
#define $PsampleTriggerReset$PstartTime_ 21 // "Time instant of first sample trigger"
#define $PsampleTriggerSet$Pperiod_ 22 // "Sample period"
#define $PsampleTriggerSet$PstartTime_ 23 // "Time instant of first sample trigger"
#define $PbooleanTable$Pindex_ 0 // "Index of actual table entry"
#define $Pset1$PfirstActiveIndex_ 1 
#define $PshowValue1$Pnumber_ 2 // "Number to visualize if use_numberPort=false (time varying)"
#define $PtriggeredAdd$Plocal_set_ 3 
#define $PtriggeredAdd$Py_ 4 // "Integer output signal"
#define $Py1_ 5 
#define $Pand1$Pnu_ 6 // "Number of input connections"
#define $PbooleanTable$Pn_ 7 // "Number of table points"
#define $PintegerConstant$Pk_ 8 // "Constant output value"
#define $Pnand1$Pnu_ 9 // "Number of input connections"
#define $Por1$Pnu_ 10 // "Number of input connections"
#define $Por2$Pnu_ 11 // "Number of input connections"
#define $Pset1$Pnu_ 12 // "Number of input connections"
#define $PtriggeredAdd$Py_start_ 13 // "Initial and reset value of y if set port is not used"
#define $Pxor1$Pnu_ 14 // "Number of input connections"
#define $PintegerConstant$Py_ 15 // "Connector of Integer output signal"
#define $PshowValue1$PnumberPort_ 16 // "Number to be shown in diagram layer if use_numberPort = true"
#define $PshowValue1$PshowNumber_ 17 
#define $PtriggeredAdd$Pu_ 18 // "Integer input signal"
#define $P$whenCondition1_ 0 
#define $P$whenCondition2_ 1 
#define $P$whenCondition3_ 2 
#define $P$whenCondition4_ 3 
#define $P$whenCondition5_ 4 
#define $P$whenCondition6_ 5 
#define $P$whenCondition7_ 6 
#define $PQ_ 7 
#define $PQI_ 8 
#define $Pand1$Pu$lB1$rB_ 9 // "Vector of Boolean input signals"
#define $PbooleanStep_ 10 
#define $PbooleanTable$Py_ 11 // "Connector of Boolean output signal"
#define $Pchanging$Pu_ 12 // "Boolean input signal"
#define $Pchanging$Py_ 13 // "Boolean output signal"
#define $Pfalling$Pnot_u_ 14 
#define $Pnand1$Pu$lB1$rB_ 15 // "Vector of Boolean input signals"
#define $Pnor1$Py_ 16 // "Boolean output signal"
#define $PonDelay$PdelaySignal_ 17 
#define $PonDelay$Pu_ 18 // "Boolean input signal"
#define $Por2$Pu$lB1$rB_ 19 // "Vector of Boolean input signals"
#define $PrSFlipFlop$PR_ 20 
#define $PrSFlipFlop$PS_ 21 
#define $PrSFlipFlop$Ppre$Pu_ 22 // "Connector of Boolean input signal"
#define $Prising$Pu_ 23 // "Boolean input signal"
#define $Pset1$Pexpr$lB1$rB_ 24 // "y = if u[i] then expr[i] else y_default (time varying)"
#define $Pset1$Pexpr$lB2$rB_ 25 // "y = if u[i] then expr[i] else y_default (time varying)"
#define $Pset1$Pu$lB1$rB_ 26 // "Set y = expr[i], if u[i] = true"
#define $Pset1$Pu$lB2$rB_ 27 // "Set y = expr[i], if u[i] = true"
#define $Pset1$Py_ 28 // "Output depending on expression"
#define $PshowValue$Pactive_ 29 // "Boolean variable to visualize if use_activePort=false (time varying)"
#define $PshowValue2$Pactive_ 30 // "Boolean variable to visualize if use_activePort=false (time varying)"
#define $PshowValue3$Pactive_ 31 // "Boolean variable to visualize if use_activePort=false (time varying)"
#define $PshowValue4$Pactive_ 32 // "Boolean variable to visualize if use_activePort=false (time varying)"
#define $PshowValue5$Pactive_ 33 // "Boolean variable to visualize if use_activePort=false (time varying)"
#define $PshowValue6$Pactive_ 34 // "Boolean variable to visualize if use_activePort=false (time varying)"
#define $PtriggeredAdd$Plocal_reset_ 35 
#define $Pxor1$Pu$lB1$rB_ 36 // "Vector of Boolean input signals"
#define $Py_ 37 
#define $Py2_ 38 
#define $Py3_ 39 
#define $Py4_ 40 
#define $PbooleanTable$PstartValue_ 41 // "Start value of y. At time = table[1], y changes to 'not startValue'"
#define $Pchanging$Ppre_u_start_ 42 // "Value of pre(u) at initial time"
#define $Pfalling$Ppre_u_start_ 43 // "Value of pre(u) at initial time"
#define $PrSFlipFlop$PQini_ 44 // "Start value of Q at initial time"
#define $PrSFlipFlop$Ppre$Ppre_u_start_ 45 // "Start value of pre(u) at initial time"
#define $Prising$Ppre_u_start_ 46 // "Value of pre(u) at initial time"
#define $Pset1$Puse_pre_as_default_ 47 // "set true to hold last value as default (y_default = pre(y))"
#define $Pset1$Py_default_ 48 // "Default value of output y if all u[i] = false"
#define $PshowValue$Puse_activePort_ 49 // "= true, if activePort enabled"
#define $PshowValue1$Puse_numberPort_ 50 // "= true, if numberPort enabled"
#define $PshowValue2$Puse_activePort_ 51 // "= true, if activePort enabled"
#define $PshowValue3$Puse_activePort_ 52 // "= true, if activePort enabled"
#define $PshowValue4$Puse_activePort_ 53 // "= true, if activePort enabled"
#define $PshowValue5$Puse_activePort_ 54 // "= true, if activePort enabled"
#define $PshowValue6$Puse_activePort_ 55 // "= true, if activePort enabled"
#define $PtriggeredAdd$Puse_reset_ 56 // "=true, if reset port enabled"
#define $PtriggeredAdd$Puse_set_ 57 // "=true, if set port enabled and used as default value when reset"
#define $Pand1$Pu$lB2$rB_ 58 // "Vector of Boolean input signals"
#define $Pand1$Pu$lB3$rB_ 59 // "Vector of Boolean input signals"
#define $Pand1$Py_ 60 // "Boolean output signal"
#define $PbooleanPulse1$Py_ 61 // "Connector of Boolean output signal"
#define $PbooleanPulse2$Py_ 62 // "Connector of Boolean output signal"
#define $Pfalling$Pu_ 63 // "Boolean input signal"
#define $Pfalling$Py_ 64 // "Boolean output signal"
#define $Pnand1$Pu$lB2$rB_ 65 // "Vector of Boolean input signals"
#define $Pnand1$Py_ 66 // "Boolean output signal"
#define $Pnor1$Pu_ 67 // "Boolean input signal"
#define $PonDelay$Py_ 68 // "Boolean output signal"
#define $Por1$Pu$lB1$rB_ 69 // "Vector of Boolean input signals"
#define $Por1$Pu$lB2$rB_ 70 // "Vector of Boolean input signals"
#define $Por1$Py_ 71 // "Boolean output signal"
#define $Por2$Pu$lB2$rB_ 72 // "Vector of Boolean input signals"
#define $Por2$Py_ 73 // "Boolean output signal"
#define $PrSFlipFlop$PQ_ 74 
#define $PrSFlipFlop$PQI_ 75 
#define $PrSFlipFlop$Pnor$Pu1_ 76 // "Connector of first Boolean input signal"
#define $PrSFlipFlop$Pnor$Pu2_ 77 // "Connector of second Boolean input signal"
#define $PrSFlipFlop$Pnor$Py_ 78 // "Connector of Boolean output signal"
#define $PrSFlipFlop$Pnor1$Pu1_ 79 // "Connector of first Boolean input signal"
#define $PrSFlipFlop$Pnor1$Pu2_ 80 // "Connector of second Boolean input signal"
#define $PrSFlipFlop$Pnor1$Py_ 81 // "Connector of Boolean output signal"
#define $PrSFlipFlop$Ppre$Py_ 82 // "Connector of Boolean output signal"
#define $Prising$Py_ 83 // "Boolean output signal"
#define $PsampleTriggerReset$Py_ 84 // "Connector of Boolean output signal"
#define $PsampleTriggerSet$Py_ 85 // "Connector of Boolean output signal"
#define $PshowValue$PactivePort_ 86 // "Boolean variable to be shown in diagram layer if use_activePort = true"
#define $PshowValue$PshowActive_ 87 
#define $PshowValue2$PactivePort_ 88 // "Boolean variable to be shown in diagram layer if use_activePort = true"
#define $PshowValue2$PshowActive_ 89 
#define $PshowValue3$PactivePort_ 90 // "Boolean variable to be shown in diagram layer if use_activePort = true"
#define $PshowValue3$PshowActive_ 91 
#define $PshowValue4$PactivePort_ 92 // "Boolean variable to be shown in diagram layer if use_activePort = true"
#define $PshowValue4$PshowActive_ 93 
#define $PshowValue5$PactivePort_ 94 // "Boolean variable to be shown in diagram layer if use_activePort = true"
#define $PshowValue5$PshowActive_ 95 
#define $PshowValue6$PactivePort_ 96 // "Boolean variable to be shown in diagram layer if use_activePort = true"
#define $PshowValue6$PshowActive_ 97 
#define $PtriggeredAdd$Ptrigger_ 98 
#define $Pxor1$Pu$lB2$rB_ 99 // "Vector of Boolean input signals"
#define $Pxor1$Py_ 100 // "Boolean output signal"


// define initial state vector as vector of value references
#define STATES {  }
#define STATESDERIVATIVES {  }


// implementation of the Model Exchange functions
  extern void BooleanNetwork1_setupDataStruc(DATA *data);
  #define fmu1_model_interface_setupDataStruc BooleanNetwork1_setupDataStruc
  #include "fmu1_model_interface.c"

// Set values for all variables that define a start value
void setDefaultStartValues(ModelInstance *comp) {

comp->fmuData->modelData.realVarsData[0].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[1].attribute.start = 0.0;
comp->fmuData->modelData.realVarsData[2].attribute.start = 0;
comp->fmuData->modelData.realVarsData[3].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[0].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[1].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[2].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[3].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[4].attribute.start = 0;
comp->fmuData->modelData.integerVarsData[5].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[0].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[1].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[2].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[3].attribute.start = 1;
comp->fmuData->modelData.booleanVarsData[4].attribute.start = 1;
comp->fmuData->modelData.booleanVarsData[5].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[6].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[7].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[8].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[9].attribute.start = 1;
comp->fmuData->modelData.booleanVarsData[10].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[11].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[12].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[13].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[14].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[15].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[16].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[17].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[18].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[19].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[20].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[21].attribute.start = 1;
comp->fmuData->modelData.booleanVarsData[22].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[23].attribute.start = 1;
comp->fmuData->modelData.booleanVarsData[24].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[25].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[26].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[27].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[28].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[29].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[30].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[31].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[32].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[33].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[34].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[35].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[36].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[37].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[38].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[39].attribute.start = 0;
comp->fmuData->modelData.booleanVarsData[40].attribute.start = 0;
comp->fmuData->modelData.realParameterData[0].attribute.start = 0.2;
comp->fmuData->modelData.realParameterData[1].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[2].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[3].attribute.start = 20.0;
comp->fmuData->modelData.realParameterData[4].attribute.start = 0.8;
comp->fmuData->modelData.realParameterData[5].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[6].attribute.start = 0.0;
comp->fmuData->modelData.realParameterData[7].attribute.start = 80.0;
comp->fmuData->modelData.realParameterData[8].attribute.start = 2.0;
comp->fmuData->modelData.realParameterData[9].attribute.start = 4.0;
comp->fmuData->modelData.realParameterData[10].attribute.start = 6.0;
comp->fmuData->modelData.realParameterData[11].attribute.start = 6.5;
comp->fmuData->modelData.realParameterData[12].attribute.start = 7.0;
comp->fmuData->modelData.realParameterData[13].attribute.start = 9.0;
comp->fmuData->modelData.realParameterData[14].attribute.start = 11.0;
comp->fmuData->modelData.realParameterData[15].attribute.start = 1.0;
comp->fmuData->modelData.realParameterData[16].attribute.start = 0.5;
comp->fmuData->modelData.realParameterData[17].attribute.start = 0.3;
comp->fmuData->modelData.realParameterData[18].attribute.start = 0.5;
comp->fmuData->modelData.realParameterData[19].attribute.start = 0.0;
comp->fmuData->modelData.integerParameterData[0].attribute.start = 3;
comp->fmuData->modelData.integerParameterData[1].attribute.start = 7;
comp->fmuData->modelData.integerParameterData[2].attribute.start = 2;
comp->fmuData->modelData.integerParameterData[3].attribute.start = 2;
comp->fmuData->modelData.integerParameterData[4].attribute.start = 2;
comp->fmuData->modelData.integerParameterData[5].attribute.start = 2;
comp->fmuData->modelData.integerParameterData[6].attribute.start = 2;
comp->fmuData->modelData.integerParameterData[7].attribute.start = 0;
comp->fmuData->modelData.integerParameterData[8].attribute.start = 2;
comp->fmuData->modelData.booleanParameterData[0].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[1].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[2].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[3].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[5].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[6].attribute.start = 1;
comp->fmuData->modelData.booleanParameterData[7].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[8].attribute.start = 1;
comp->fmuData->modelData.booleanParameterData[9].attribute.start = 1;
comp->fmuData->modelData.booleanParameterData[10].attribute.start = 1;
comp->fmuData->modelData.booleanParameterData[11].attribute.start = 1;
comp->fmuData->modelData.booleanParameterData[12].attribute.start = 1;
comp->fmuData->modelData.booleanParameterData[13].attribute.start = 1;
comp->fmuData->modelData.booleanParameterData[14].attribute.start = 1;
comp->fmuData->modelData.booleanParameterData[15].attribute.start = 0;
comp->fmuData->modelData.booleanParameterData[16].attribute.start = 0;
}
// Set values for all variables that define a start value
void setStartValues(ModelInstance *comp) {

  comp->fmuData->modelData.realVarsData[0].attribute.start =  comp->fmuData->localData[0]->realVars[0];
  comp->fmuData->modelData.realVarsData[1].attribute.start =  comp->fmuData->localData[0]->realVars[1];
  comp->fmuData->modelData.realVarsData[2].attribute.start =  comp->fmuData->localData[0]->realVars[2];
  comp->fmuData->modelData.realVarsData[3].attribute.start =  comp->fmuData->localData[0]->realVars[3];
  comp->fmuData->modelData.integerVarsData[0].attribute.start =  comp->fmuData->localData[0]->integerVars[0];
  comp->fmuData->modelData.integerVarsData[1].attribute.start =  comp->fmuData->localData[0]->integerVars[1];
  comp->fmuData->modelData.integerVarsData[2].attribute.start =  comp->fmuData->localData[0]->integerVars[2];
  comp->fmuData->modelData.integerVarsData[3].attribute.start =  comp->fmuData->localData[0]->integerVars[3];
  comp->fmuData->modelData.integerVarsData[4].attribute.start =  comp->fmuData->localData[0]->integerVars[4];
  comp->fmuData->modelData.integerVarsData[5].attribute.start =  comp->fmuData->localData[0]->integerVars[5];
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
  comp->fmuData->modelData.booleanVarsData[12].attribute.start =  comp->fmuData->localData[0]->booleanVars[12];
  comp->fmuData->modelData.booleanVarsData[13].attribute.start =  comp->fmuData->localData[0]->booleanVars[13];
  comp->fmuData->modelData.booleanVarsData[14].attribute.start =  comp->fmuData->localData[0]->booleanVars[14];
  comp->fmuData->modelData.booleanVarsData[15].attribute.start =  comp->fmuData->localData[0]->booleanVars[15];
  comp->fmuData->modelData.booleanVarsData[16].attribute.start =  comp->fmuData->localData[0]->booleanVars[16];
  comp->fmuData->modelData.booleanVarsData[17].attribute.start =  comp->fmuData->localData[0]->booleanVars[17];
  comp->fmuData->modelData.booleanVarsData[18].attribute.start =  comp->fmuData->localData[0]->booleanVars[18];
  comp->fmuData->modelData.booleanVarsData[19].attribute.start =  comp->fmuData->localData[0]->booleanVars[19];
  comp->fmuData->modelData.booleanVarsData[20].attribute.start =  comp->fmuData->localData[0]->booleanVars[20];
  comp->fmuData->modelData.booleanVarsData[21].attribute.start =  comp->fmuData->localData[0]->booleanVars[21];
  comp->fmuData->modelData.booleanVarsData[22].attribute.start =  comp->fmuData->localData[0]->booleanVars[22];
  comp->fmuData->modelData.booleanVarsData[23].attribute.start =  comp->fmuData->localData[0]->booleanVars[23];
  comp->fmuData->modelData.booleanVarsData[24].attribute.start =  comp->fmuData->localData[0]->booleanVars[24];
  comp->fmuData->modelData.booleanVarsData[25].attribute.start =  comp->fmuData->localData[0]->booleanVars[25];
  comp->fmuData->modelData.booleanVarsData[26].attribute.start =  comp->fmuData->localData[0]->booleanVars[26];
  comp->fmuData->modelData.booleanVarsData[27].attribute.start =  comp->fmuData->localData[0]->booleanVars[27];
  comp->fmuData->modelData.booleanVarsData[28].attribute.start =  comp->fmuData->localData[0]->booleanVars[28];
  comp->fmuData->modelData.booleanVarsData[29].attribute.start =  comp->fmuData->localData[0]->booleanVars[29];
  comp->fmuData->modelData.booleanVarsData[30].attribute.start =  comp->fmuData->localData[0]->booleanVars[30];
  comp->fmuData->modelData.booleanVarsData[31].attribute.start =  comp->fmuData->localData[0]->booleanVars[31];
  comp->fmuData->modelData.booleanVarsData[32].attribute.start =  comp->fmuData->localData[0]->booleanVars[32];
  comp->fmuData->modelData.booleanVarsData[33].attribute.start =  comp->fmuData->localData[0]->booleanVars[33];
  comp->fmuData->modelData.booleanVarsData[34].attribute.start =  comp->fmuData->localData[0]->booleanVars[34];
  comp->fmuData->modelData.booleanVarsData[35].attribute.start =  comp->fmuData->localData[0]->booleanVars[35];
  comp->fmuData->modelData.booleanVarsData[36].attribute.start =  comp->fmuData->localData[0]->booleanVars[36];
  comp->fmuData->modelData.booleanVarsData[37].attribute.start =  comp->fmuData->localData[0]->booleanVars[37];
  comp->fmuData->modelData.booleanVarsData[38].attribute.start =  comp->fmuData->localData[0]->booleanVars[38];
  comp->fmuData->modelData.booleanVarsData[39].attribute.start =  comp->fmuData->localData[0]->booleanVars[39];
  comp->fmuData->modelData.booleanVarsData[40].attribute.start =  comp->fmuData->localData[0]->booleanVars[40];
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
comp->fmuData->modelData.booleanParameterData[7].attribute.start = comp->fmuData->simulationInfo.booleanParameter[7];
comp->fmuData->modelData.booleanParameterData[8].attribute.start = comp->fmuData->simulationInfo.booleanParameter[8];
comp->fmuData->modelData.booleanParameterData[9].attribute.start = comp->fmuData->simulationInfo.booleanParameter[9];
comp->fmuData->modelData.booleanParameterData[10].attribute.start = comp->fmuData->simulationInfo.booleanParameter[10];
comp->fmuData->modelData.booleanParameterData[11].attribute.start = comp->fmuData->simulationInfo.booleanParameter[11];
comp->fmuData->modelData.booleanParameterData[12].attribute.start = comp->fmuData->simulationInfo.booleanParameter[12];
comp->fmuData->modelData.booleanParameterData[13].attribute.start = comp->fmuData->simulationInfo.booleanParameter[13];
comp->fmuData->modelData.booleanParameterData[14].attribute.start = comp->fmuData->simulationInfo.booleanParameter[14];
comp->fmuData->modelData.booleanParameterData[15].attribute.start = comp->fmuData->simulationInfo.booleanParameter[15];
comp->fmuData->modelData.booleanParameterData[16].attribute.start = comp->fmuData->simulationInfo.booleanParameter[16];
}
  // Used to set the next time event, if any.
  void eventUpdate(ModelInstance* comp, fmiEventInfo* eventInfo) {
  }
  
  fmiReal getReal(ModelInstance* comp, const fmiValueReference vr) {
    switch (vr) {
        case $PbooleanPulse1$PpulsStart_ : return comp->fmuData->localData[0]->realVars[0]; break;
        case $PbooleanPulse2$PpulsStart_ : return comp->fmuData->localData[0]->realVars[1]; break;
        case $PbooleanTable$PnextTime_ : return comp->fmuData->localData[0]->realVars[2]; break;
        case $PonDelay$Pt_next_ : return comp->fmuData->localData[0]->realVars[3]; break;
        case $PbooleanPulse1$PTwidth_ : return comp->fmuData->simulationInfo.realParameter[0]; break;
        case $PbooleanPulse1$Pperiod_ : return comp->fmuData->simulationInfo.realParameter[1]; break;
        case $PbooleanPulse1$PstartTime_ : return comp->fmuData->simulationInfo.realParameter[2]; break;
        case $PbooleanPulse1$Pwidth_ : return comp->fmuData->simulationInfo.realParameter[3]; break;
        case $PbooleanPulse2$PTwidth_ : return comp->fmuData->simulationInfo.realParameter[4]; break;
        case $PbooleanPulse2$Pperiod_ : return comp->fmuData->simulationInfo.realParameter[5]; break;
        case $PbooleanPulse2$PstartTime_ : return comp->fmuData->simulationInfo.realParameter[6]; break;
        case $PbooleanPulse2$Pwidth_ : return comp->fmuData->simulationInfo.realParameter[7]; break;
        case $PbooleanTable$Ptable$lB1$rB_ : return comp->fmuData->simulationInfo.realParameter[8]; break;
        case $PbooleanTable$Ptable$lB2$rB_ : return comp->fmuData->simulationInfo.realParameter[9]; break;
        case $PbooleanTable$Ptable$lB3$rB_ : return comp->fmuData->simulationInfo.realParameter[10]; break;
        case $PbooleanTable$Ptable$lB4$rB_ : return comp->fmuData->simulationInfo.realParameter[11]; break;
        case $PbooleanTable$Ptable$lB5$rB_ : return comp->fmuData->simulationInfo.realParameter[12]; break;
        case $PbooleanTable$Ptable$lB6$rB_ : return comp->fmuData->simulationInfo.realParameter[13]; break;
        case $PbooleanTable$Ptable$lB7$rB_ : return comp->fmuData->simulationInfo.realParameter[14]; break;
        case $PonDelay$PdelayTime_ : return comp->fmuData->simulationInfo.realParameter[15]; break;
        case $PsampleTriggerReset$Pperiod_ : return comp->fmuData->simulationInfo.realParameter[16]; break;
        case $PsampleTriggerReset$PstartTime_ : return comp->fmuData->simulationInfo.realParameter[17]; break;
        case $PsampleTriggerSet$Pperiod_ : return comp->fmuData->simulationInfo.realParameter[18]; break;
        case $PsampleTriggerSet$PstartTime_ : return comp->fmuData->simulationInfo.realParameter[19]; break;
        default:
            return 0;
    }
  }
  
  fmiStatus setReal(ModelInstance* comp, const fmiValueReference vr, const fmiReal value) {
    switch (vr) {
        case $PbooleanPulse1$PpulsStart_ : comp->fmuData->localData[0]->realVars[0]=value; break;
        case $PbooleanPulse2$PpulsStart_ : comp->fmuData->localData[0]->realVars[1]=value; break;
        case $PbooleanTable$PnextTime_ : comp->fmuData->localData[0]->realVars[2]=value; break;
        case $PonDelay$Pt_next_ : comp->fmuData->localData[0]->realVars[3]=value; break;
        case $PbooleanPulse1$PTwidth_ : comp->fmuData->simulationInfo.realParameter[0]=value; break;
        case $PbooleanPulse1$Pperiod_ : comp->fmuData->simulationInfo.realParameter[1]=value; break;
        case $PbooleanPulse1$PstartTime_ : comp->fmuData->simulationInfo.realParameter[2]=value; break;
        case $PbooleanPulse1$Pwidth_ : comp->fmuData->simulationInfo.realParameter[3]=value; break;
        case $PbooleanPulse2$PTwidth_ : comp->fmuData->simulationInfo.realParameter[4]=value; break;
        case $PbooleanPulse2$Pperiod_ : comp->fmuData->simulationInfo.realParameter[5]=value; break;
        case $PbooleanPulse2$PstartTime_ : comp->fmuData->simulationInfo.realParameter[6]=value; break;
        case $PbooleanPulse2$Pwidth_ : comp->fmuData->simulationInfo.realParameter[7]=value; break;
        case $PbooleanTable$Ptable$lB1$rB_ : comp->fmuData->simulationInfo.realParameter[8]=value; break;
        case $PbooleanTable$Ptable$lB2$rB_ : comp->fmuData->simulationInfo.realParameter[9]=value; break;
        case $PbooleanTable$Ptable$lB3$rB_ : comp->fmuData->simulationInfo.realParameter[10]=value; break;
        case $PbooleanTable$Ptable$lB4$rB_ : comp->fmuData->simulationInfo.realParameter[11]=value; break;
        case $PbooleanTable$Ptable$lB5$rB_ : comp->fmuData->simulationInfo.realParameter[12]=value; break;
        case $PbooleanTable$Ptable$lB6$rB_ : comp->fmuData->simulationInfo.realParameter[13]=value; break;
        case $PbooleanTable$Ptable$lB7$rB_ : comp->fmuData->simulationInfo.realParameter[14]=value; break;
        case $PonDelay$PdelayTime_ : comp->fmuData->simulationInfo.realParameter[15]=value; break;
        case $PsampleTriggerReset$Pperiod_ : comp->fmuData->simulationInfo.realParameter[16]=value; break;
        case $PsampleTriggerReset$PstartTime_ : comp->fmuData->simulationInfo.realParameter[17]=value; break;
        case $PsampleTriggerSet$Pperiod_ : comp->fmuData->simulationInfo.realParameter[18]=value; break;
        case $PsampleTriggerSet$PstartTime_ : comp->fmuData->simulationInfo.realParameter[19]=value; break;
        default:
            return fmiError;
    }
    return fmiOK;
  }
  
  fmiInteger getInteger(ModelInstance* comp, const fmiValueReference vr) {
    switch (vr) {
        case $PbooleanTable$Pindex_ : return comp->fmuData->localData[0]->integerVars[0]; break;
        case $Pset1$PfirstActiveIndex_ : return comp->fmuData->localData[0]->integerVars[1]; break;
        case $PshowValue1$Pnumber_ : return comp->fmuData->localData[0]->integerVars[2]; break;
        case $PtriggeredAdd$Plocal_set_ : return comp->fmuData->localData[0]->integerVars[3]; break;
        case $PtriggeredAdd$Py_ : return comp->fmuData->localData[0]->integerVars[4]; break;
        case $Py1_ : return comp->fmuData->localData[0]->integerVars[5]; break;
        case $Pand1$Pnu_ : return comp->fmuData->simulationInfo.integerParameter[0]; break;
        case $PbooleanTable$Pn_ : return comp->fmuData->simulationInfo.integerParameter[1]; break;
        case $PintegerConstant$Pk_ : return comp->fmuData->simulationInfo.integerParameter[2]; break;
        case $Pnand1$Pnu_ : return comp->fmuData->simulationInfo.integerParameter[3]; break;
        case $Por1$Pnu_ : return comp->fmuData->simulationInfo.integerParameter[4]; break;
        case $Por2$Pnu_ : return comp->fmuData->simulationInfo.integerParameter[5]; break;
        case $Pset1$Pnu_ : return comp->fmuData->simulationInfo.integerParameter[6]; break;
        case $PtriggeredAdd$Py_start_ : return comp->fmuData->simulationInfo.integerParameter[7]; break;
        case $Pxor1$Pnu_ : return comp->fmuData->simulationInfo.integerParameter[8]; break;
        case $PintegerConstant$Py_ : return getInteger(comp, $PintegerConstant$Pk_); break;
        case $PshowValue1$PnumberPort_ : return getInteger(comp, $PtriggeredAdd$Py_); break;
        case $PshowValue1$PshowNumber_ : return getInteger(comp, $PtriggeredAdd$Py_); break;
        case $PtriggeredAdd$Pu_ : return getInteger(comp, $PintegerConstant$Pk_); break;
        default:
            return 0;
    }
  }
  fmiStatus setInteger(ModelInstance* comp, const fmiValueReference vr, const fmiInteger value) {
    switch (vr) {
        case $PbooleanTable$Pindex_ : comp->fmuData->localData[0]->integerVars[0]=value; break;
        case $Pset1$PfirstActiveIndex_ : comp->fmuData->localData[0]->integerVars[1]=value; break;
        case $PshowValue1$Pnumber_ : comp->fmuData->localData[0]->integerVars[2]=value; break;
        case $PtriggeredAdd$Plocal_set_ : comp->fmuData->localData[0]->integerVars[3]=value; break;
        case $PtriggeredAdd$Py_ : comp->fmuData->localData[0]->integerVars[4]=value; break;
        case $Py1_ : comp->fmuData->localData[0]->integerVars[5]=value; break;
        case $Pand1$Pnu_ : comp->fmuData->simulationInfo.integerParameter[0]=value; break;
        case $PbooleanTable$Pn_ : comp->fmuData->simulationInfo.integerParameter[1]=value; break;
        case $PintegerConstant$Pk_ : comp->fmuData->simulationInfo.integerParameter[2]=value; break;
        case $Pnand1$Pnu_ : comp->fmuData->simulationInfo.integerParameter[3]=value; break;
        case $Por1$Pnu_ : comp->fmuData->simulationInfo.integerParameter[4]=value; break;
        case $Por2$Pnu_ : comp->fmuData->simulationInfo.integerParameter[5]=value; break;
        case $Pset1$Pnu_ : comp->fmuData->simulationInfo.integerParameter[6]=value; break;
        case $PtriggeredAdd$Py_start_ : comp->fmuData->simulationInfo.integerParameter[7]=value; break;
        case $Pxor1$Pnu_ : comp->fmuData->simulationInfo.integerParameter[8]=value; break;
        case $PintegerConstant$Py_ : return setInteger(comp, $PintegerConstant$Pk_, value); break;
        case $PshowValue1$PnumberPort_ : return setInteger(comp, $PtriggeredAdd$Py_, value); break;
        case $PshowValue1$PshowNumber_ : return setInteger(comp, $PtriggeredAdd$Py_, value); break;
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
        case $P$whenCondition5_ : return comp->fmuData->localData[0]->booleanVars[4]; break;
        case $P$whenCondition6_ : return comp->fmuData->localData[0]->booleanVars[5]; break;
        case $P$whenCondition7_ : return comp->fmuData->localData[0]->booleanVars[6]; break;
        case $PQ_ : return comp->fmuData->localData[0]->booleanVars[7]; break;
        case $PQI_ : return comp->fmuData->localData[0]->booleanVars[8]; break;
        case $Pand1$Pu$lB1$rB_ : return comp->fmuData->localData[0]->booleanVars[9]; break;
        case $PbooleanStep_ : return comp->fmuData->localData[0]->booleanVars[10]; break;
        case $PbooleanTable$Py_ : return comp->fmuData->localData[0]->booleanVars[11]; break;
        case $Pchanging$Pu_ : return comp->fmuData->localData[0]->booleanVars[12]; break;
        case $Pchanging$Py_ : return comp->fmuData->localData[0]->booleanVars[13]; break;
        case $Pfalling$Pnot_u_ : return comp->fmuData->localData[0]->booleanVars[14]; break;
        case $Pnand1$Pu$lB1$rB_ : return comp->fmuData->localData[0]->booleanVars[15]; break;
        case $Pnor1$Py_ : return comp->fmuData->localData[0]->booleanVars[16]; break;
        case $PonDelay$PdelaySignal_ : return comp->fmuData->localData[0]->booleanVars[17]; break;
        case $PonDelay$Pu_ : return comp->fmuData->localData[0]->booleanVars[18]; break;
        case $Por2$Pu$lB1$rB_ : return comp->fmuData->localData[0]->booleanVars[19]; break;
        case $PrSFlipFlop$PR_ : return comp->fmuData->localData[0]->booleanVars[20]; break;
        case $PrSFlipFlop$PS_ : return comp->fmuData->localData[0]->booleanVars[21]; break;
        case $PrSFlipFlop$Ppre$Pu_ : return comp->fmuData->localData[0]->booleanVars[22]; break;
        case $Prising$Pu_ : return comp->fmuData->localData[0]->booleanVars[23]; break;
        case $Pset1$Pexpr$lB1$rB_ : return comp->fmuData->localData[0]->booleanVars[24]; break;
        case $Pset1$Pexpr$lB2$rB_ : return comp->fmuData->localData[0]->booleanVars[25]; break;
        case $Pset1$Pu$lB1$rB_ : return comp->fmuData->localData[0]->booleanVars[26]; break;
        case $Pset1$Pu$lB2$rB_ : return comp->fmuData->localData[0]->booleanVars[27]; break;
        case $Pset1$Py_ : return comp->fmuData->localData[0]->booleanVars[28]; break;
        case $PshowValue$Pactive_ : return comp->fmuData->localData[0]->booleanVars[29]; break;
        case $PshowValue2$Pactive_ : return comp->fmuData->localData[0]->booleanVars[30]; break;
        case $PshowValue3$Pactive_ : return comp->fmuData->localData[0]->booleanVars[31]; break;
        case $PshowValue4$Pactive_ : return comp->fmuData->localData[0]->booleanVars[32]; break;
        case $PshowValue5$Pactive_ : return comp->fmuData->localData[0]->booleanVars[33]; break;
        case $PshowValue6$Pactive_ : return comp->fmuData->localData[0]->booleanVars[34]; break;
        case $PtriggeredAdd$Plocal_reset_ : return comp->fmuData->localData[0]->booleanVars[35]; break;
        case $Pxor1$Pu$lB1$rB_ : return comp->fmuData->localData[0]->booleanVars[36]; break;
        case $Py_ : return comp->fmuData->localData[0]->booleanVars[37]; break;
        case $Py2_ : return comp->fmuData->localData[0]->booleanVars[38]; break;
        case $Py3_ : return comp->fmuData->localData[0]->booleanVars[39]; break;
        case $Py4_ : return comp->fmuData->localData[0]->booleanVars[40]; break;
        case $PbooleanTable$PstartValue_ : return comp->fmuData->simulationInfo.booleanParameter[0]; break;
        case $Pchanging$Ppre_u_start_ : return comp->fmuData->simulationInfo.booleanParameter[1]; break;
        case $Pfalling$Ppre_u_start_ : return comp->fmuData->simulationInfo.booleanParameter[2]; break;
        case $PrSFlipFlop$PQini_ : return comp->fmuData->simulationInfo.booleanParameter[3]; break;
        case $PrSFlipFlop$Ppre$Ppre_u_start_ : return comp->fmuData->simulationInfo.booleanParameter[4]; break;
        case $Prising$Ppre_u_start_ : return comp->fmuData->simulationInfo.booleanParameter[5]; break;
        case $Pset1$Puse_pre_as_default_ : return comp->fmuData->simulationInfo.booleanParameter[6]; break;
        case $Pset1$Py_default_ : return comp->fmuData->simulationInfo.booleanParameter[7]; break;
        case $PshowValue$Puse_activePort_ : return comp->fmuData->simulationInfo.booleanParameter[8]; break;
        case $PshowValue1$Puse_numberPort_ : return comp->fmuData->simulationInfo.booleanParameter[9]; break;
        case $PshowValue2$Puse_activePort_ : return comp->fmuData->simulationInfo.booleanParameter[10]; break;
        case $PshowValue3$Puse_activePort_ : return comp->fmuData->simulationInfo.booleanParameter[11]; break;
        case $PshowValue4$Puse_activePort_ : return comp->fmuData->simulationInfo.booleanParameter[12]; break;
        case $PshowValue5$Puse_activePort_ : return comp->fmuData->simulationInfo.booleanParameter[13]; break;
        case $PshowValue6$Puse_activePort_ : return comp->fmuData->simulationInfo.booleanParameter[14]; break;
        case $PtriggeredAdd$Puse_reset_ : return comp->fmuData->simulationInfo.booleanParameter[15]; break;
        case $PtriggeredAdd$Puse_set_ : return comp->fmuData->simulationInfo.booleanParameter[16]; break;
        case $Pand1$Pu$lB2$rB_ : return getBoolean(comp, $PbooleanStep_); break;
        case $Pand1$Pu$lB3$rB_ : return getBoolean(comp, $Prising$Pu_); break;
        case $Pand1$Py_ : return getBoolean(comp, $Py_); break;
        case $PbooleanPulse1$Py_ : return getBoolean(comp, $Pand1$Pu$lB1$rB_); break;
        case $PbooleanPulse2$Py_ : return getBoolean(comp, $Prising$Pu_); break;
        case $Pfalling$Pu_ : return getBoolean(comp, $Prising$Pu_); break;
        case $Pfalling$Py_ : return getBoolean(comp, $Pset1$Pu$lB2$rB_); break;
        case $Pnand1$Pu$lB2$rB_ : return getBoolean(comp, $Prising$Pu_); break;
        case $Pnand1$Py_ : return getBoolean(comp, $Por2$Pu$lB1$rB_); break;
        case $Pnor1$Pu_ : return (! getBoolean(comp, $Pnor1$Py_)); break;
        case $PonDelay$Py_ : return getBoolean(comp, $Py4_); break;
        case $Por1$Pu$lB1$rB_ : return getBoolean(comp, $Py_); break;
        case $Por1$Pu$lB2$rB_ : return getBoolean(comp, $Prising$Pu_); break;
        case $Por1$Py_ : return getBoolean(comp, $Pxor1$Pu$lB1$rB_); break;
        case $Por2$Pu$lB2$rB_ : return getBoolean(comp, $Prising$Pu_); break;
        case $Por2$Py_ : return (! getBoolean(comp, $Pnor1$Py_)); break;
        case $PrSFlipFlop$PQ_ : return getBoolean(comp, $PQ_); break;
        case $PrSFlipFlop$PQI_ : return getBoolean(comp, $PQI_); break;
        case $PrSFlipFlop$Pnor$Pu1_ : return getBoolean(comp, $PrSFlipFlop$PS_); break;
        case $PrSFlipFlop$Pnor$Pu2_ : return getBoolean(comp, $PQ_); break;
        case $PrSFlipFlop$Pnor$Py_ : return getBoolean(comp, $PrSFlipFlop$Ppre$Pu_); break;
        case $PrSFlipFlop$Pnor1$Pu1_ : return getBoolean(comp, $PQI_); break;
        case $PrSFlipFlop$Pnor1$Pu2_ : return getBoolean(comp, $PrSFlipFlop$PR_); break;
        case $PrSFlipFlop$Pnor1$Py_ : return getBoolean(comp, $PQ_); break;
        case $PrSFlipFlop$Ppre$Py_ : return getBoolean(comp, $PQI_); break;
        case $Prising$Py_ : return getBoolean(comp, $Pset1$Pu$lB1$rB_); break;
        case $PsampleTriggerReset$Py_ : return getBoolean(comp, $PrSFlipFlop$PR_); break;
        case $PsampleTriggerSet$Py_ : return getBoolean(comp, $PrSFlipFlop$PS_); break;
        case $PshowValue$PactivePort_ : return getBoolean(comp, $Py_); break;
        case $PshowValue$PshowActive_ : return getBoolean(comp, $Py_); break;
        case $PshowValue2$PactivePort_ : return getBoolean(comp, $Pxor1$Pu$lB1$rB_); break;
        case $PshowValue2$PshowActive_ : return getBoolean(comp, $Pxor1$Pu$lB1$rB_); break;
        case $PshowValue3$PactivePort_ : return getBoolean(comp, $Pnand1$Pu$lB1$rB_); break;
        case $PshowValue3$PshowActive_ : return getBoolean(comp, $Pnand1$Pu$lB1$rB_); break;
        case $PshowValue4$PactivePort_ : return getBoolean(comp, $Pnor1$Py_); break;
        case $PshowValue4$PshowActive_ : return getBoolean(comp, $Pnor1$Py_); break;
        case $PshowValue5$PactivePort_ : return getBoolean(comp, $Pset1$Py_); break;
        case $PshowValue5$PshowActive_ : return getBoolean(comp, $Pset1$Py_); break;
        case $PshowValue6$PactivePort_ : return getBoolean(comp, $Py4_); break;
        case $PshowValue6$PshowActive_ : return getBoolean(comp, $Py4_); break;
        case $PtriggeredAdd$Ptrigger_ : return getBoolean(comp, $Pchanging$Py_); break;
        case $Pxor1$Pu$lB2$rB_ : return getBoolean(comp, $Prising$Pu_); break;
        case $Pxor1$Py_ : return getBoolean(comp, $Pnand1$Pu$lB1$rB_); break;
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
        case $P$whenCondition5_ : comp->fmuData->localData[0]->booleanVars[4]=value; break;
        case $P$whenCondition6_ : comp->fmuData->localData[0]->booleanVars[5]=value; break;
        case $P$whenCondition7_ : comp->fmuData->localData[0]->booleanVars[6]=value; break;
        case $PQ_ : comp->fmuData->localData[0]->booleanVars[7]=value; break;
        case $PQI_ : comp->fmuData->localData[0]->booleanVars[8]=value; break;
        case $Pand1$Pu$lB1$rB_ : comp->fmuData->localData[0]->booleanVars[9]=value; break;
        case $PbooleanStep_ : comp->fmuData->localData[0]->booleanVars[10]=value; break;
        case $PbooleanTable$Py_ : comp->fmuData->localData[0]->booleanVars[11]=value; break;
        case $Pchanging$Pu_ : comp->fmuData->localData[0]->booleanVars[12]=value; break;
        case $Pchanging$Py_ : comp->fmuData->localData[0]->booleanVars[13]=value; break;
        case $Pfalling$Pnot_u_ : comp->fmuData->localData[0]->booleanVars[14]=value; break;
        case $Pnand1$Pu$lB1$rB_ : comp->fmuData->localData[0]->booleanVars[15]=value; break;
        case $Pnor1$Py_ : comp->fmuData->localData[0]->booleanVars[16]=value; break;
        case $PonDelay$PdelaySignal_ : comp->fmuData->localData[0]->booleanVars[17]=value; break;
        case $PonDelay$Pu_ : comp->fmuData->localData[0]->booleanVars[18]=value; break;
        case $Por2$Pu$lB1$rB_ : comp->fmuData->localData[0]->booleanVars[19]=value; break;
        case $PrSFlipFlop$PR_ : comp->fmuData->localData[0]->booleanVars[20]=value; break;
        case $PrSFlipFlop$PS_ : comp->fmuData->localData[0]->booleanVars[21]=value; break;
        case $PrSFlipFlop$Ppre$Pu_ : comp->fmuData->localData[0]->booleanVars[22]=value; break;
        case $Prising$Pu_ : comp->fmuData->localData[0]->booleanVars[23]=value; break;
        case $Pset1$Pexpr$lB1$rB_ : comp->fmuData->localData[0]->booleanVars[24]=value; break;
        case $Pset1$Pexpr$lB2$rB_ : comp->fmuData->localData[0]->booleanVars[25]=value; break;
        case $Pset1$Pu$lB1$rB_ : comp->fmuData->localData[0]->booleanVars[26]=value; break;
        case $Pset1$Pu$lB2$rB_ : comp->fmuData->localData[0]->booleanVars[27]=value; break;
        case $Pset1$Py_ : comp->fmuData->localData[0]->booleanVars[28]=value; break;
        case $PshowValue$Pactive_ : comp->fmuData->localData[0]->booleanVars[29]=value; break;
        case $PshowValue2$Pactive_ : comp->fmuData->localData[0]->booleanVars[30]=value; break;
        case $PshowValue3$Pactive_ : comp->fmuData->localData[0]->booleanVars[31]=value; break;
        case $PshowValue4$Pactive_ : comp->fmuData->localData[0]->booleanVars[32]=value; break;
        case $PshowValue5$Pactive_ : comp->fmuData->localData[0]->booleanVars[33]=value; break;
        case $PshowValue6$Pactive_ : comp->fmuData->localData[0]->booleanVars[34]=value; break;
        case $PtriggeredAdd$Plocal_reset_ : comp->fmuData->localData[0]->booleanVars[35]=value; break;
        case $Pxor1$Pu$lB1$rB_ : comp->fmuData->localData[0]->booleanVars[36]=value; break;
        case $Py_ : comp->fmuData->localData[0]->booleanVars[37]=value; break;
        case $Py2_ : comp->fmuData->localData[0]->booleanVars[38]=value; break;
        case $Py3_ : comp->fmuData->localData[0]->booleanVars[39]=value; break;
        case $Py4_ : comp->fmuData->localData[0]->booleanVars[40]=value; break;
        case $PbooleanTable$PstartValue_ : comp->fmuData->simulationInfo.booleanParameter[0]=value; break;
        case $Pchanging$Ppre_u_start_ : comp->fmuData->simulationInfo.booleanParameter[1]=value; break;
        case $Pfalling$Ppre_u_start_ : comp->fmuData->simulationInfo.booleanParameter[2]=value; break;
        case $PrSFlipFlop$PQini_ : comp->fmuData->simulationInfo.booleanParameter[3]=value; break;
        case $PrSFlipFlop$Ppre$Ppre_u_start_ : comp->fmuData->simulationInfo.booleanParameter[4]=value; break;
        case $Prising$Ppre_u_start_ : comp->fmuData->simulationInfo.booleanParameter[5]=value; break;
        case $Pset1$Puse_pre_as_default_ : comp->fmuData->simulationInfo.booleanParameter[6]=value; break;
        case $Pset1$Py_default_ : comp->fmuData->simulationInfo.booleanParameter[7]=value; break;
        case $PshowValue$Puse_activePort_ : comp->fmuData->simulationInfo.booleanParameter[8]=value; break;
        case $PshowValue1$Puse_numberPort_ : comp->fmuData->simulationInfo.booleanParameter[9]=value; break;
        case $PshowValue2$Puse_activePort_ : comp->fmuData->simulationInfo.booleanParameter[10]=value; break;
        case $PshowValue3$Puse_activePort_ : comp->fmuData->simulationInfo.booleanParameter[11]=value; break;
        case $PshowValue4$Puse_activePort_ : comp->fmuData->simulationInfo.booleanParameter[12]=value; break;
        case $PshowValue5$Puse_activePort_ : comp->fmuData->simulationInfo.booleanParameter[13]=value; break;
        case $PshowValue6$Puse_activePort_ : comp->fmuData->simulationInfo.booleanParameter[14]=value; break;
        case $PtriggeredAdd$Puse_reset_ : comp->fmuData->simulationInfo.booleanParameter[15]=value; break;
        case $PtriggeredAdd$Puse_set_ : comp->fmuData->simulationInfo.booleanParameter[16]=value; break;
        case $Pand1$Pu$lB2$rB_ : return setBoolean(comp, $PbooleanStep_, value); break;
        case $Pand1$Pu$lB3$rB_ : return setBoolean(comp, $Prising$Pu_, value); break;
        case $Pand1$Py_ : return setBoolean(comp, $Py_, value); break;
        case $PbooleanPulse1$Py_ : return setBoolean(comp, $Pand1$Pu$lB1$rB_, value); break;
        case $PbooleanPulse2$Py_ : return setBoolean(comp, $Prising$Pu_, value); break;
        case $Pfalling$Pu_ : return setBoolean(comp, $Prising$Pu_, value); break;
        case $Pfalling$Py_ : return setBoolean(comp, $Pset1$Pu$lB2$rB_, value); break;
        case $Pnand1$Pu$lB2$rB_ : return setBoolean(comp, $Prising$Pu_, value); break;
        case $Pnand1$Py_ : return setBoolean(comp, $Por2$Pu$lB1$rB_, value); break;
        case $Pnor1$Pu_ : return setBoolean(comp, $Pnor1$Py_, (! value)); break;
        case $PonDelay$Py_ : return setBoolean(comp, $Py4_, value); break;
        case $Por1$Pu$lB1$rB_ : return setBoolean(comp, $Py_, value); break;
        case $Por1$Pu$lB2$rB_ : return setBoolean(comp, $Prising$Pu_, value); break;
        case $Por1$Py_ : return setBoolean(comp, $Pxor1$Pu$lB1$rB_, value); break;
        case $Por2$Pu$lB2$rB_ : return setBoolean(comp, $Prising$Pu_, value); break;
        case $Por2$Py_ : return setBoolean(comp, $Pnor1$Py_, (! value)); break;
        case $PrSFlipFlop$PQ_ : return setBoolean(comp, $PQ_, value); break;
        case $PrSFlipFlop$PQI_ : return setBoolean(comp, $PQI_, value); break;
        case $PrSFlipFlop$Pnor$Pu1_ : return setBoolean(comp, $PrSFlipFlop$PS_, value); break;
        case $PrSFlipFlop$Pnor$Pu2_ : return setBoolean(comp, $PQ_, value); break;
        case $PrSFlipFlop$Pnor$Py_ : return setBoolean(comp, $PrSFlipFlop$Ppre$Pu_, value); break;
        case $PrSFlipFlop$Pnor1$Pu1_ : return setBoolean(comp, $PQI_, value); break;
        case $PrSFlipFlop$Pnor1$Pu2_ : return setBoolean(comp, $PrSFlipFlop$PR_, value); break;
        case $PrSFlipFlop$Pnor1$Py_ : return setBoolean(comp, $PQ_, value); break;
        case $PrSFlipFlop$Ppre$Py_ : return setBoolean(comp, $PQI_, value); break;
        case $Prising$Py_ : return setBoolean(comp, $Pset1$Pu$lB1$rB_, value); break;
        case $PsampleTriggerReset$Py_ : return setBoolean(comp, $PrSFlipFlop$PR_, value); break;
        case $PsampleTriggerSet$Py_ : return setBoolean(comp, $PrSFlipFlop$PS_, value); break;
        case $PshowValue$PactivePort_ : return setBoolean(comp, $Py_, value); break;
        case $PshowValue$PshowActive_ : return setBoolean(comp, $Py_, value); break;
        case $PshowValue2$PactivePort_ : return setBoolean(comp, $Pxor1$Pu$lB1$rB_, value); break;
        case $PshowValue2$PshowActive_ : return setBoolean(comp, $Pxor1$Pu$lB1$rB_, value); break;
        case $PshowValue3$PactivePort_ : return setBoolean(comp, $Pnand1$Pu$lB1$rB_, value); break;
        case $PshowValue3$PshowActive_ : return setBoolean(comp, $Pnand1$Pu$lB1$rB_, value); break;
        case $PshowValue4$PactivePort_ : return setBoolean(comp, $Pnor1$Py_, value); break;
        case $PshowValue4$PshowActive_ : return setBoolean(comp, $Pnor1$Py_, value); break;
        case $PshowValue5$PactivePort_ : return setBoolean(comp, $Pset1$Py_, value); break;
        case $PshowValue5$PshowActive_ : return setBoolean(comp, $Pset1$Py_, value); break;
        case $PshowValue6$PactivePort_ : return setBoolean(comp, $Py4_, value); break;
        case $PshowValue6$PshowActive_ : return setBoolean(comp, $Py4_, value); break;
        case $PtriggeredAdd$Ptrigger_ : return setBoolean(comp, $Pchanging$Py_, value); break;
        case $Pxor1$Pu$lB2$rB_ : return setBoolean(comp, $Prising$Pu_, value); break;
        case $Pxor1$Py_ : return setBoolean(comp, $Pnand1$Pu$lB1$rB_, value); break;
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

