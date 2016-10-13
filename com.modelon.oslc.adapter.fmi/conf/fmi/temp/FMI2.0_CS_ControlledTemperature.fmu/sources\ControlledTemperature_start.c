#include "ControlledTemperature_base.h"


void jmi_set_start_values_0_0(jmi_t* jmi) {
    _constantVoltage_n_v_7 = (0);
    _temperatureSensor_port_Q_flow_23 = (0);
    _idealSwitch_unitVoltage_31 = (1);
    _idealSwitch_unitCurrent_32 = (1);
    _idealSwitch_T_heatPort_37 = (293.15);
    _ground_p_v_49 = (0);
    _heatingResistor_n_v_50 = (0);
    _TAmb_0 = (293.15);
    _TDif_1 = (2);
    _constantVoltage_V_4 = (10);
    _heatCapacitor_C_8 = (1);
    _heatingResistor_R_ref_12 = (10);
    _heatingResistor_T_ref_13 = (293.15);
    _heatingResistor_alpha_14 = (0.00392156862745098);
    _thermalConductor_G_24 = (0.1);
    _idealSwitch_Ron_27 = (1.0E-5);
    _idealSwitch_Goff_28 = (1.0E-5);
    _ramp_height_38 = (25);
    _ramp_duration_39 = (6);
    _ramp_offset_40 = (25);
    _ramp_startTime_41 = (2);
    _onOffController_pre_y_start_45 = (JMI_FALSE);
    __block_jacobian_check_54 = (JMI_FALSE);
    __block_jacobian_check_tol_55 = (1.0E-6);
    __block_solver_experimental_mode_56 = (0);
    __cs_rel_tol_57 = (1.0E-6);
    __cs_solver_58 = (0);
    __cs_step_size_59 = (0.001);
    __enforce_bounds_60 = (JMI_TRUE);
    __events_default_tol_61 = (1.0E-10);
    __events_tol_factor_62 = (1.0E-4);
    __iteration_variable_scaling_63 = (1);
    __log_level_64 = (3);
    __nle_solver_check_jac_cond_65 = (JMI_FALSE);
    __nle_solver_default_tol_66 = (1.0E-10);
    __nle_solver_max_iter_67 = (100);
    __nle_solver_max_residual_scaling_factor_68 = (1.0E10);
    __nle_solver_min_residual_scaling_factor_69 = (1.0E-10);
    __nle_solver_min_tol_70 = (1.0E-12);
    __nle_solver_regularization_tolerance_71 = (-1.0);
    __nle_solver_step_limit_factor_72 = (10.0);
    __nle_solver_tol_factor_73 = (1.0E-4);
    __rescale_after_singular_jac_74 = (JMI_TRUE);
    __rescale_each_step_75 = (JMI_FALSE);
    __residual_equation_scaling_76 = (1);
    __runtime_log_to_file_77 = (JMI_FALSE);
    __use_Brent_in_1d_78 = (JMI_TRUE);
    __use_jacobian_equilibration_79 = (JMI_FALSE);
    __use_newton_for_brent_80 = (JMI_TRUE);
    _heatingResistor_useHeatPort_18 = (JMI_TRUE);
    _idealSwitch_useHeatPort_34 = (JMI_FALSE);
    _idealSwitch_T_35 = (293.15);
}

void jmi_set_start_values_1_0(jmi_t* jmi) {
    _TRes_2 = (288.15);
    _ground_p_i_3 = (0.0);
    _heatCapacitor_T_9 = (_TAmb_0);
    _heatCapacitor_der_T_10 = (0);
    _heatCapacitor_port_Q_flow_11 = (0.0);
    _heatingResistor_R_15 = (0.0);
    _heatingResistor_v_16 = (0.0);
    _heatingResistor_i_17 = (0.0);
    _heatingResistor_LossPower_20 = (0.0);
    _thermalConductor_Q_flow_25 = (0.0);
    _thermalConductor_dT_26 = (0.0);
    _idealSwitch_control_29 = (JMI_FALSE);
    _idealSwitch_s_30 = (0.0);
    _idealSwitch_v_33 = (0.0);
    _idealSwitch_LossPower_36 = (0.0);
    _onOffController_reference_42 = (0.0);
    _onOffController_u_43 = (0.0);
    _logicalNot_u_46 = (JMI_FALSE);
    _der_heatCapacitor_T_53 = (0.0);
    pre_idealSwitch_control_29 = (JMI_FALSE);
    pre_logicalNot_u_46 = (JMI_FALSE);
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
