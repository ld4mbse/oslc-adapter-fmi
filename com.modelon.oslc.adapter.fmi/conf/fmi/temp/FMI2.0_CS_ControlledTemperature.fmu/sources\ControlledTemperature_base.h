#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <jmi.h>
#include <jmi_block_residual.h>
#include "jmi_log.h"
#include "ModelicaUtilities.h"
#include "ModelicaStandardTables.h"

extern void dgemm_(char* TRANSA, char* TRANSB, int* M, int* N, int* K, double* ALPHA, double* A, int* LDA, double* B, int* LDB, double* BETA, double* C, int* LDC);

int model_ode_derivatives(jmi_t* jmi);
int model_ode_initialize(jmi_t* jmi);
int model_dae_R(jmi_t* jmi, jmi_real_t** res);
int model_init_R0(jmi_t* jmi, jmi_real_t** res);
void model_add_blocks(jmi_t** jmi);
void model_init_add_blocks(jmi_t** jmi);
int model_init_eval_parameters(jmi_t* jmi);
int jmi_set_start_values(jmi_t* jmi);
int model_ode_guards(jmi_t* jmi);
int model_ode_guards_init(jmi_t* jmi);


#define _constantVoltage_n_v_7 ((*(jmi->z))[jmi->offs_real_ci+0])
#define _temperatureSensor_port_Q_flow_23 ((*(jmi->z))[jmi->offs_real_ci+1])
#define _idealSwitch_unitVoltage_31 ((*(jmi->z))[jmi->offs_real_ci+2])
#define _idealSwitch_unitCurrent_32 ((*(jmi->z))[jmi->offs_real_ci+3])
#define _idealSwitch_T_heatPort_37 ((*(jmi->z))[jmi->offs_real_ci+4])
#define _ground_p_v_49 ((*(jmi->z))[jmi->offs_real_ci+5])
#define _heatingResistor_n_v_50 ((*(jmi->z))[jmi->offs_real_ci+6])
#define _TAmb_0 ((*(jmi->z))[jmi->offs_real_pi+0])
#define _TDif_1 ((*(jmi->z))[jmi->offs_real_pi+1])
#define _constantVoltage_V_4 ((*(jmi->z))[jmi->offs_real_pi+2])
#define _heatCapacitor_C_8 ((*(jmi->z))[jmi->offs_real_pi+3])
#define _heatingResistor_R_ref_12 ((*(jmi->z))[jmi->offs_real_pi+4])
#define _heatingResistor_T_ref_13 ((*(jmi->z))[jmi->offs_real_pi+5])
#define _heatingResistor_alpha_14 ((*(jmi->z))[jmi->offs_real_pi+6])
#define _thermalConductor_G_24 ((*(jmi->z))[jmi->offs_real_pi+7])
#define _idealSwitch_Ron_27 ((*(jmi->z))[jmi->offs_real_pi+8])
#define _idealSwitch_Goff_28 ((*(jmi->z))[jmi->offs_real_pi+9])
#define _ramp_height_38 ((*(jmi->z))[jmi->offs_real_pi+10])
#define _ramp_duration_39 ((*(jmi->z))[jmi->offs_real_pi+11])
#define _ramp_offset_40 ((*(jmi->z))[jmi->offs_real_pi+12])
#define _ramp_startTime_41 ((*(jmi->z))[jmi->offs_real_pi+13])
#define __block_jacobian_check_tol_55 ((*(jmi->z))[jmi->offs_real_pi+14])
#define __cs_rel_tol_57 ((*(jmi->z))[jmi->offs_real_pi+15])
#define __cs_step_size_59 ((*(jmi->z))[jmi->offs_real_pi+16])
#define __events_default_tol_61 ((*(jmi->z))[jmi->offs_real_pi+17])
#define __events_tol_factor_62 ((*(jmi->z))[jmi->offs_real_pi+18])
#define __nle_solver_default_tol_66 ((*(jmi->z))[jmi->offs_real_pi+19])
#define __nle_solver_max_residual_scaling_factor_68 ((*(jmi->z))[jmi->offs_real_pi+20])
#define __nle_solver_min_residual_scaling_factor_69 ((*(jmi->z))[jmi->offs_real_pi+21])
#define __nle_solver_min_tol_70 ((*(jmi->z))[jmi->offs_real_pi+22])
#define __nle_solver_regularization_tolerance_71 ((*(jmi->z))[jmi->offs_real_pi+23])
#define __nle_solver_step_limit_factor_72 ((*(jmi->z))[jmi->offs_real_pi+24])
#define __nle_solver_tol_factor_73 ((*(jmi->z))[jmi->offs_real_pi+25])
#define _idealSwitch_T_35 ((*(jmi->z))[jmi->offs_real_pi+26])
#define _heatingResistor_T_5 ((*(jmi->z))[jmi->offs_real_pd+0])
#define _fixedTemperature_T_6 ((*(jmi->z))[jmi->offs_real_pd+1])
#define _onOffController_bandwidth_19 ((*(jmi->z))[jmi->offs_real_pd+2])
#define _constantVoltage_v_21 ((*(jmi->z))[jmi->offs_real_pd+3])
#define _fixedTemperature_port_T_22 ((*(jmi->z))[jmi->offs_real_pd+4])
#define _constantVoltage_p_v_44 ((*(jmi->z))[jmi->offs_real_pd+5])
#define _thermalConductor_port_b_T_51 ((*(jmi->z))[jmi->offs_real_pd+6])
#define _idealSwitch_p_v_52 ((*(jmi->z))[jmi->offs_real_pd+7])
#define __block_solver_experimental_mode_56 ((*(jmi->z))[jmi->offs_integer_pi+0])
#define __cs_solver_58 ((*(jmi->z))[jmi->offs_integer_pi+1])
#define __iteration_variable_scaling_63 ((*(jmi->z))[jmi->offs_integer_pi+2])
#define __log_level_64 ((*(jmi->z))[jmi->offs_integer_pi+3])
#define __nle_solver_max_iter_67 ((*(jmi->z))[jmi->offs_integer_pi+4])
#define __residual_equation_scaling_76 ((*(jmi->z))[jmi->offs_integer_pi+5])
#define _onOffController_pre_y_start_45 ((*(jmi->z))[jmi->offs_boolean_pi+0])
#define __block_jacobian_check_54 ((*(jmi->z))[jmi->offs_boolean_pi+1])
#define __enforce_bounds_60 ((*(jmi->z))[jmi->offs_boolean_pi+2])
#define __nle_solver_check_jac_cond_65 ((*(jmi->z))[jmi->offs_boolean_pi+3])
#define __rescale_after_singular_jac_74 ((*(jmi->z))[jmi->offs_boolean_pi+4])
#define __rescale_each_step_75 ((*(jmi->z))[jmi->offs_boolean_pi+5])
#define __runtime_log_to_file_77 ((*(jmi->z))[jmi->offs_boolean_pi+6])
#define __use_Brent_in_1d_78 ((*(jmi->z))[jmi->offs_boolean_pi+7])
#define __use_jacobian_equilibration_79 ((*(jmi->z))[jmi->offs_boolean_pi+8])
#define __use_newton_for_brent_80 ((*(jmi->z))[jmi->offs_boolean_pi+9])
#define _heatingResistor_useHeatPort_18 ((*(jmi->z))[jmi->offs_boolean_pi+10])
#define _idealSwitch_useHeatPort_34 ((*(jmi->z))[jmi->offs_boolean_pi+11])
#define _der_heatCapacitor_T_53 ((*(jmi->z))[jmi->offs_real_dx+0])
#define _heatCapacitor_T_9 ((*(jmi->z))[jmi->offs_real_x+0])
#define _TRes_2 ((*(jmi->z))[jmi->offs_real_w+0])
#define _ground_p_i_3 ((*(jmi->z))[jmi->offs_real_w+1])
#define _heatCapacitor_der_T_10 ((*(jmi->z))[jmi->offs_real_w+2])
#define _heatCapacitor_port_Q_flow_11 ((*(jmi->z))[jmi->offs_real_w+3])
#define _heatingResistor_R_15 ((*(jmi->z))[jmi->offs_real_w+4])
#define _heatingResistor_v_16 ((*(jmi->z))[jmi->offs_real_w+5])
#define _heatingResistor_i_17 ((*(jmi->z))[jmi->offs_real_w+6])
#define _heatingResistor_LossPower_20 ((*(jmi->z))[jmi->offs_real_w+7])
#define _thermalConductor_Q_flow_25 ((*(jmi->z))[jmi->offs_real_w+8])
#define _thermalConductor_dT_26 ((*(jmi->z))[jmi->offs_real_w+9])
#define _idealSwitch_s_30 ((*(jmi->z))[jmi->offs_real_w+10])
#define _idealSwitch_v_33 ((*(jmi->z))[jmi->offs_real_w+11])
#define _idealSwitch_LossPower_36 ((*(jmi->z))[jmi->offs_real_w+12])
#define _onOffController_reference_42 ((*(jmi->z))[jmi->offs_real_w+13])
#define _onOffController_u_43 ((*(jmi->z))[jmi->offs_real_w+14])
#define _time ((*(jmi->z))[jmi->offs_t])
#define _idealSwitch_control_29 ((*(jmi->z))[jmi->offs_boolean_d+0])
#define _logicalNot_u_46 ((*(jmi->z))[jmi->offs_boolean_d+1])
#define pre_der_heatCapacitor_T_53 ((*(jmi->z))[jmi->offs_pre_real_dx+0])
#define pre_heatCapacitor_T_9 ((*(jmi->z))[jmi->offs_pre_real_x+0])
#define pre_TRes_2 ((*(jmi->z))[jmi->offs_pre_real_w+0])
#define pre_ground_p_i_3 ((*(jmi->z))[jmi->offs_pre_real_w+1])
#define pre_heatCapacitor_der_T_10 ((*(jmi->z))[jmi->offs_pre_real_w+2])
#define pre_heatCapacitor_port_Q_flow_11 ((*(jmi->z))[jmi->offs_pre_real_w+3])
#define pre_heatingResistor_R_15 ((*(jmi->z))[jmi->offs_pre_real_w+4])
#define pre_heatingResistor_v_16 ((*(jmi->z))[jmi->offs_pre_real_w+5])
#define pre_heatingResistor_i_17 ((*(jmi->z))[jmi->offs_pre_real_w+6])
#define pre_heatingResistor_LossPower_20 ((*(jmi->z))[jmi->offs_pre_real_w+7])
#define pre_thermalConductor_Q_flow_25 ((*(jmi->z))[jmi->offs_pre_real_w+8])
#define pre_thermalConductor_dT_26 ((*(jmi->z))[jmi->offs_pre_real_w+9])
#define pre_idealSwitch_s_30 ((*(jmi->z))[jmi->offs_pre_real_w+10])
#define pre_idealSwitch_v_33 ((*(jmi->z))[jmi->offs_pre_real_w+11])
#define pre_idealSwitch_LossPower_36 ((*(jmi->z))[jmi->offs_pre_real_w+12])
#define pre_onOffController_reference_42 ((*(jmi->z))[jmi->offs_pre_real_w+13])
#define pre_onOffController_u_43 ((*(jmi->z))[jmi->offs_pre_real_w+14])
#define pre_idealSwitch_control_29 ((*(jmi->z))[jmi->offs_pre_boolean_d+0])
#define pre_logicalNot_u_46 ((*(jmi->z))[jmi->offs_pre_boolean_d+1])


#define sf(i) (jmi->variable_scaling_factors[i])

#define _real_ci(i) ((*(jmi->z))[jmi->offs_real_ci+i])
#define _real_cd(i) ((*(jmi->z))[jmi->offs_real_cd+i])
#define _real_pi(i) ((*(jmi->z))[jmi->offs_real_pi+i])
#define _real_pd(i) ((*(jmi->z))[jmi->offs_real_pd+i])
#define _real_dx(i) ((*(jmi->z))[jmi->offs_real_dx+i])
#define _real_x(i) ((*(jmi->z))[jmi->offs_real_x+i])
#define _real_u(i) ((*(jmi->z))[jmi->offs_real_u+i])
#define _real_w(i) ((*(jmi->z))[jmi->offs_real_w+i])
#define _t ((*(jmi->z))[jmi->offs_t])

#define _real_d(i) ((*(jmi->z))[jmi->offs_real_d+i])
#define _integer_d(i) ((*(jmi->z))[jmi->offs_integer_d+i])
#define _integer_u(i) ((*(jmi->z))[jmi->offs_integer_u+i])
#define _boolean_d(i) ((*(jmi->z))[jmi->offs_boolean_d+i])
#define _boolean_u(i) ((*(jmi->z))[jmi->offs_boolean_u+i])

#define _pre_real_dx(i) ((*(jmi->z))[jmi->offs_pre_real_dx+i])
#define _pre_real_x(i) ((*(jmi->z))[jmi->offs_pre_real_x+i])
#define _pre_real_u(i) ((*(jmi->z))[jmi->offs_pre_real_u+i])
#define _pre_real_w(i) ((*(jmi->z))[jmi->offs_pre_real_w+i])

#define _pre_real_d(i) ((*(jmi->z))[jmi->offs_pre_real_d+i])
#define _pre_integer_d(i) ((*(jmi->z))[jmi->offs_pre_integer_d+i])
#define _pre_integer_u(i) ((*(jmi->z))[jmi->offs_pre_integer_u+i])
#define _pre_boolean_d(i) ((*(jmi->z))[jmi->offs_pre_boolean_d+i])
#define _pre_boolean_u(i) ((*(jmi->z))[jmi->offs_pre_boolean_u+i])

#define _sw(i) ((*(jmi->z))[jmi->offs_sw + i])
#define _sw_init(i) ((*(jmi->z))[jmi->offs_sw_init + i])
#define _pre_sw(i) ((*(jmi->z))[jmi->offs_pre_sw + i])
#define _pre_sw_init(i) ((*(jmi->z))[jmi->offs_pre_sw_init + i])
#define _guards(i) ((*(jmi->z))[jmi->offs_guards + i])
#define _guards_init(i) ((*(jmi->z))[jmi->offs_guards_init + i])
#define _pre_guards(i) ((*(jmi->z))[jmi->offs_pre_guards + i])
#define _pre_guards_init(i) ((*(jmi->z))[jmi->offs_pre_guards_init + i])

#define _atInitial (jmi->atInitial)







