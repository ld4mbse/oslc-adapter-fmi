#include "PID_Controller_base.h"
static char* SimpleController_0_e[] = { "", "P", "PI", "PD", "PID" };
static char* InitPID_1_e[] = { "", "NoInit", "SteadyState", "InitialState", "InitialOutput", "DoNotUse_InitialIntegratorState" };
static char* Init_2_e[] = { "", "NoInit", "SteadyState", "InitialState", "InitialOutput" };
static char* StateSelect_3_e[] = { "", "never", "avoid", "default", "prefer", "always" };


void jmi_set_start_values_0_0(jmi_t* jmi) {
    _PI_unitTime_18 = (1);
    _torque_phi_support_59 = (0);
    _speedSensor_flange_tau_101 = (0);
    _loadTorque_phi_support_105 = (0);
    _driveAngle_0 = (1.57);
    _PI_k_3 = (100);
    _PI_Ti_4 = (0.1);
    _PI_Td_5 = (0.1);
    _PI_wp_8 = (1);
    _PI_wd_9 = (0);
    _PI_Ni_10 = (0.1);
    _PI_Nd_11 = (10);
    _PI_xi_start_14 = (0);
    _PI_xd_start_15 = (0);
    _PI_addP_k2_20 = (-1);
    _PI_P_k_21 = (1);
    _PI_addPID_k1_30 = (1);
    _PI_addPID_k2_31 = (1);
    _PI_addPID_k3_32 = (1);
    _PI_addI_k1_34 = (1);
    _PI_addI_k2_35 = (-1);
    _PI_addI_k3_36 = (1);
    _PI_addSat_k1_38 = (1);
    _PI_addSat_k2_39 = (-1);
    _PI_limiter_uMax_43 = (12.0);
    _PI_limiter_uMin_44 = (-12.0);
    _PI_Dzero_k_49 = (0);
    _inertia1_J_52 = (1);
    _inertia1_stateSelect_53 = (3);
    _spring_c_60 = (10000.0);
    _spring_d_61 = (100);
    _spring_phi_rel0_62 = (0);
    _spring_phi_nominal_69 = (1.0E-4);
    _spring_stateSelect_70 = (4);
    _inertia2_J_73 = (2);
    _inertia2_stateSelect_74 = (3);
    _kinematicPTP_qd_max_1_79 = (1);
    _kinematicPTP_qdd_max_1_80 = (1);
    _kinematicPTP_startTime_81 = (0.5);
    _integrator_k_96 = (1);
    _integrator_y_start_98 = (0);
    _loadTorque_tau_constant_102 = (10);
    __block_jacobian_check_121 = (JMI_FALSE);
    __block_jacobian_check_tol_122 = (1.0E-6);
    __block_solver_experimental_mode_123 = (0);
    __cs_rel_tol_124 = (1.0E-6);
    __cs_solver_125 = (0);
    __cs_step_size_126 = (0.001);
    __enforce_bounds_127 = (JMI_TRUE);
    __events_default_tol_128 = (1.0E-10);
    __events_tol_factor_129 = (1.0E-4);
    __iteration_variable_scaling_130 = (1);
    __log_level_131 = (3);
    __nle_solver_check_jac_cond_132 = (JMI_FALSE);
    __nle_solver_default_tol_133 = (1.0E-10);
    __nle_solver_max_iter_134 = (100);
    __nle_solver_max_residual_scaling_factor_135 = (1.0E10);
    __nle_solver_min_residual_scaling_factor_136 = (1.0E-10);
    __nle_solver_min_tol_137 = (1.0E-12);
    __nle_solver_regularization_tolerance_138 = (-1.0);
    __nle_solver_step_limit_factor_139 = (10.0);
    __nle_solver_tol_factor_140 = (1.0E-4);
    __rescale_after_singular_jac_141 = (JMI_TRUE);
    __rescale_each_step_142 = (JMI_FALSE);
    __residual_equation_scaling_143 = (1);
    __runtime_log_to_file_144 = (JMI_FALSE);
    __use_Brent_in_1d_145 = (JMI_TRUE);
    __use_jacobian_equilibration_146 = (JMI_FALSE);
    __use_newton_for_brent_147 = (JMI_TRUE);
    _PI_controllerType_2 = (2);
    _PI_yMax_6 = (12);
    _PI_yMin_7 = (-12.0);
    _PI_initType_12 = (2);
    _PI_limitsAtInit_13 = (JMI_FALSE);
    _PI_y_start_16 = (0);
    _PI_strict_17 = (JMI_FALSE);
    _PI_I_initType_25 = (2);
    _PI_limiter_strict_45 = (JMI_FALSE);
    _PI_limiter_limitsAtInit_46 = (JMI_FALSE);
    _PI_with_I_47 = (JMI_TRUE);
    _PI_with_D_48 = (JMI_FALSE);
    _torque_useSupport_58 = (JMI_FALSE);
    _spring_useHeatPort_71 = (JMI_FALSE);
    _kinematicPTP_nout_95 = (1);
    _integrator_initType_97 = (3);
    _loadTorque_useSupport_104 = (JMI_FALSE);
}

void jmi_set_start_values_1_0(jmi_t* jmi) {
    _PI_controlError_1 = (0.0);
    _PI_P_u_22 = (0.0);
    _PI_P_y_23 = (0.0);
    _PI_I_u_27 = (0.0);
    _PI_I_y_28 = (_PI_I_y_start_26);
    _PI_addPID_y_33 = (0.0);
    _PI_addI_u3_37 = (0.0);
    _PI_addSat_u2_40 = (0.0);
    _PI_addSat_y_41 = (0.0);
    _PI_u_m_51 = (0.0);
    _inertia1_phi_54 = (0);
    _inertia1_w_55 = (0.0);
    _inertia1_a_56 = (0);
    _torque_tau_57 = (0.0);
    _spring_tau_c_63 = (0.0);
    _spring_tau_d_64 = (0.0);
    _spring_phi_rel_65 = (0);
    _spring_w_rel_66 = (0);
    _spring_a_rel_67 = (0);
    _spring_tau_68 = (0.0);
    _spring_lossPower_72 = (0.0);
    _inertia2_phi_75 = (0.0);
    _inertia2_w_76 = (0.0);
    _inertia2_a_77 = (0.0);
    _kinematicPTP_sdd_87 = (0.0);
    _integrator_u_99 = (0.0);
    _integrator_y_100 = (_integrator_y_start_98);
    _der_inertia1_w_109 = (0.0);
    _der_inertia2_phi_110 = (0.0);
    _der_inertia2_w_111 = (0.0);
    _inertia1__der_phi_112 = (0.0);
    _der_2_spring_phi_rel_113 = (0.0);
    _der_2_inertia2_phi_114 = (0.0);
    _der_spring_w_rel_115 = (0.0);
    _der_PI_I_y_116 = (0.0);
    _der_inertia1_phi_117 = (0.0);
    _der_spring_phi_rel_118 = (0.0);
    _der_integrator_y_119 = (0.0);
    _der_inertia1__der_phi_120 = (0.0);
}

void jmi_set_start_values_base(jmi_t* jmi) {
    jmi_set_start_values_0_0(jmi);
    model_init_eval_parameters(jmi);
    jmi_set_start_values_1_0(jmi);
}


int jmi_set_start_values(jmi_t* jmi) {
    jmi_set_start_values_base(jmi);
    return 0;
}
