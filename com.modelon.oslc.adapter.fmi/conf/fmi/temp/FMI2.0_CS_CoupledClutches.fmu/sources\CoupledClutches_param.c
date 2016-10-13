#include "CoupledClutches_base.h"
static char* StateSelect_0_e[] = { "", "never", "avoid", "default", "prefer", "always" };


void model_init_eval_parameters_0(jmi_t* jmi) {
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_1, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_2, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_3, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_4, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_5, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_6, 1, 1)
    _step1_startTime_10 = (_T2_1);
    _sin2_freqHz_16 = (_freqHz_0);
    JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_1, 1, 1, 1)
    jmi_array_ref_1(tmp_1, 1) = _clutch1_mue_pos_1_1_11;
    JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_2, 1, 1, 1)
    jmi_array_ref_1(tmp_2, 1) = _clutch1_mue_pos_1_2_12;
    _clutch1_mue0_51 = (func_Modelica_Math_Vectors_interpolate_exp0(tmp_1, tmp_2, AD_WRAP_LITERAL(0), AD_WRAP_LITERAL(1)));
    JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_3, 1, 1, 1)
    jmi_array_ref_1(tmp_3, 1) = _clutch2_mue_pos_1_1_57;
    JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_4, 1, 1, 1)
    jmi_array_ref_1(tmp_4, 1) = _clutch2_mue_pos_1_2_58;
    _clutch2_mue0_62 = (func_Modelica_Math_Vectors_interpolate_exp0(tmp_3, tmp_4, AD_WRAP_LITERAL(0), AD_WRAP_LITERAL(1)));
    JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_5, 1, 1, 1)
    jmi_array_ref_1(tmp_5, 1) = _clutch3_mue_pos_1_1_94;
    JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_6, 1, 1, 1)
    jmi_array_ref_1(tmp_6, 1) = _clutch3_mue_pos_1_2_95;
    _clutch3_mue0_99 = (func_Modelica_Math_Vectors_interpolate_exp0(tmp_5, tmp_6, AD_WRAP_LITERAL(0), AD_WRAP_LITERAL(1)));
    _torque_phi_support_133 = (_fixed_phi0_139);
    _fixed_flange_phi_155 = (_torque_phi_support_133);
    _torque_support_phi_156 = (_torque_phi_support_133);
}

void model_init_eval_parameters_base(jmi_t* jmi) {
    model_init_eval_parameters_0(jmi);
}


int model_init_eval_parameters(jmi_t* jmi) {
    model_init_eval_parameters_base(jmi);
    return 0;
}
