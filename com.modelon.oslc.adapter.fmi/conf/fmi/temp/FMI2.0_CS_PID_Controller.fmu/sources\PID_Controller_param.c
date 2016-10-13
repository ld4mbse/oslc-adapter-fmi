#include "PID_Controller_base.h"
static char* SimpleController_0_e[] = { "", "P", "PI", "PD", "PID" };
static char* InitPID_1_e[] = { "", "NoInit", "SteadyState", "InitialState", "InitialOutput", "DoNotUse_InitialIntegratorState" };
static char* Init_2_e[] = { "", "NoInit", "SteadyState", "InitialState", "InitialOutput" };
static char* StateSelect_3_e[] = { "", "never", "avoid", "default", "prefer", "always" };


void model_init_eval_parameters_0(jmi_t* jmi) {
    _PI_addP_k1_19 = (_PI_wp_8);
    _PI_I_k_24 = (jmi_divide_equation(jmi, 1.0,_PI_Ti_4,"1.0 / PI.Ti"));
    _PI_I_y_start_26 = (_PI_xi_start_14);
    _PI_gainPID_k_29 = (_PI_k_3);
    _PI_gainTrack_k_42 = (jmi_divide_equation(jmi, 1,(_PI_k_3 * _PI_Ni_10),"1 / (PI.k * PI.Ni)"));
    _kinematicPTP_deltaq_1_50 = (_driveAngle_0);
    _kinematicPTP_p_qd_max_1_78 = (_kinematicPTP_qd_max_1_79);
    _kinematicPTP_p_qdd_max_1_82 = (_kinematicPTP_qdd_max_1_80);
    _PI_Dzero_y_83 = (_PI_Dzero_k_49);
    _loadTorque_tau_84 = (_loadTorque_tau_constant_102);
    _kinematicPTP_p_deltaq_1_85 = (_kinematicPTP_deltaq_1_50);
    _PI_addPID_u2_86 = (_PI_Dzero_y_83);
    _loadTorque_flange_tau_88 = (- _loadTorque_tau_84);
    _inertia2_flange_b_tau_89 = (_loadTorque_tau_84);
    _kinematicPTP_aux1_1_90 = (jmi_divide_equation(jmi, _kinematicPTP_p_deltaq_1_85,_kinematicPTP_p_qd_max_1_78,"kinematicPTP.p_deltaq[1] / kinematicPTP.p_qd_max[1]"));
    _kinematicPTP_aux2_1_91 = (jmi_divide_equation(jmi, _kinematicPTP_p_deltaq_1_85,_kinematicPTP_p_qdd_max_1_82,"kinematicPTP.p_deltaq[1] / kinematicPTP.p_qdd_max[1]"));
    _kinematicPTP_sd_max_92 = (jmi_divide_equation(jmi, 1,jmi_abs(_kinematicPTP_aux1_1_90),"1 / abs(kinematicPTP.aux1[1])"));
    _kinematicPTP_sdd_max_93 = (jmi_divide_equation(jmi, 1,jmi_abs(_kinematicPTP_aux2_1_91),"1 / abs(kinematicPTP.aux2[1])"));
    _kinematicPTP_Ta1_94 = (sqrt(jmi_divide_equation(jmi, AD_WRAP_LITERAL(1),_kinematicPTP_sdd_max_93,"1 / kinematicPTP.sdd_max")));
    _kinematicPTP_Ta2_103 = (jmi_divide_equation(jmi, _kinematicPTP_sd_max_92,_kinematicPTP_sdd_max_93,"kinematicPTP.sd_max / kinematicPTP.sdd_max"));
    _kinematicPTP_noWphase_106 = (COND_EXP_GE(_kinematicPTP_Ta2_103, _kinematicPTP_Ta1_94, JMI_TRUE, JMI_FALSE));
    _kinematicPTP_Tv_107 = (COND_EXP_EQ(_kinematicPTP_noWphase_106, JMI_TRUE, _kinematicPTP_Ta1_94, jmi_divide_equation(jmi, AD_WRAP_LITERAL(1),_kinematicPTP_sd_max_92,"1 / kinematicPTP.sd_max")));
    _kinematicPTP_Te_108 = (COND_EXP_EQ(_kinematicPTP_noWphase_106, JMI_TRUE, _kinematicPTP_Ta1_94 + _kinematicPTP_Ta1_94, _kinematicPTP_Tv_107 + _kinematicPTP_Ta2_103));
}

void model_init_eval_parameters_base(jmi_t* jmi) {
    model_init_eval_parameters_0(jmi);
}


int model_init_eval_parameters(jmi_t* jmi) {
    model_init_eval_parameters_base(jmi);
    return 0;
}
