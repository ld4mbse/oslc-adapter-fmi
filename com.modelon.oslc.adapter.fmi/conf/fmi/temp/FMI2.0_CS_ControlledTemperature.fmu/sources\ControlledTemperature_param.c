#include "ControlledTemperature_base.h"


void model_init_eval_parameters_0(jmi_t* jmi) {
    _heatingResistor_T_5 = (_heatingResistor_T_ref_13);
    _fixedTemperature_T_6 = (_TAmb_0);
    _onOffController_bandwidth_19 = (_TDif_1);
    _constantVoltage_v_21 = (_constantVoltage_V_4);
    _fixedTemperature_port_T_22 = (_fixedTemperature_T_6);
    _constantVoltage_p_v_44 = (_constantVoltage_v_21);
    _thermalConductor_port_b_T_51 = (_fixedTemperature_port_T_22);
    _idealSwitch_p_v_52 = (_constantVoltage_p_v_44);
}

void model_init_eval_parameters_base(jmi_t* jmi) {
    model_init_eval_parameters_0(jmi);
}


int model_init_eval_parameters(jmi_t* jmi) {
    model_init_eval_parameters_base(jmi);
    return 0;
}
