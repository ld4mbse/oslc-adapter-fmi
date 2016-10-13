#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fmiCSFunctions.h"
#include "fmi1_functions.h"
#include <jmi.h>
#include <jmi_block_residual.h>
#include <fmi1_me.h>
#include <fmi1_cs.h>
#include "jmi_log.h"
#include "ModelicaUtilities.h"
#include "ModelicaStandardTables.h"

#define MODEL_IDENTIFIER PID_Controller



extern void dgemm_(char* TRANSA, char* TRANSB, int* M, int* N, int* K, double* ALPHA, double* A, int* LDA, double* B, int* LDB, double* BETA, double* C, int* LDC);

const char *C_GUID = "5689bdeaba783fe34ccf0fb3fb0a4b6a";

static int model_ode_guards_init(jmi_t* jmi);
static int model_init_R0(jmi_t* jmi, jmi_real_t** res);
static int model_ode_initialize(jmi_t* jmi);

static const int N_real_ci = 4;
static const int N_real_cd = 0;
static const int N_real_pi = 48;
static const int N_real_pi_s = 3;
static const int N_real_pi_f = 0;
static const int N_real_pi_e = 0;
static const int N_real_pd = 22;

static const int N_integer_ci = 0 + 0;
static const int N_integer_cd = 0 + 0;
static const int N_integer_pi = 7 + 7;
static const int N_integer_pi_s = 1 + 4;
static const int N_integer_pi_f = 0 + 0;
static const int N_integer_pi_e = 0 + 0;
static const int N_integer_pd = 0 + 0;

static const int N_boolean_ci = 0;
static const int N_boolean_cd = 0;
static const int N_boolean_pi = 17;
static const int N_boolean_pi_s = 9;
static const int N_boolean_pi_f = 0;
static const int N_boolean_pi_e = 0;
static const int N_boolean_pd = 1;

static const int N_string_ci = 0;
static const int N_string_cd = 0;
static const int N_string_pi = 0;
static const int N_string_pi_s = 0;
static const int N_string_pi_f = 0;
static const int N_string_pi_e = 0;
static const int N_string_pd = 0;

static const int N_real_dx = 6;
static const int N_real_x = 6;
static const int N_real_u = 0;
static const int N_real_w = 27;

static const int N_real_d = 0;

static const int N_integer_d = 0 + 0;
static const int N_integer_u = 0 + 0;

static const int N_boolean_d = 0;
static const int N_boolean_u = 0;

static const int N_string_d = 0;
static const int N_string_u = 0;

static const int N_ext_objs = 0;

static const int N_sw = 11;
static const int N_delay_sw = 0;
static const int N_eq_F = 33;
static const int N_eq_R = 11;

static const int N_dae_blocks = 0;
static const int N_dae_init_blocks = 2;
static const int N_guards = 0;

static const int N_eq_F0 = 33 + 6;
static const int N_eq_F1 = 36;
static const int N_eq_Fp = 0;
static const int N_eq_R0 = 11 + 0;
static const int N_sw_init = 0;
static const int N_guards_init = 0;

static const int N_delays = 0;

static const int Scaling_method = JMI_SCALING_NONE;

#define sf(i) (jmi->variable_scaling_factors[i])

static const int N_outputs = 0;
static const int Output_vrefs[1] = {-1};

static int CAD_dae_n_nz = 1;
static const int CAD_dae_nz_rows[1] = {-1};
static const int CAD_dae_nz_cols[1] = {-1};


static const int CAD_ODE_A_n_nz = 0;
static const int CAD_ODE_B_n_nz = 0;
static const int CAD_ODE_C_n_nz = 0;
static const int CAD_ODE_D_n_nz = 0;
static const int CAD_ODE_A_nz_rows[1] = {-1};
static const int CAD_ODE_A_nz_cols[1] = {-1};
static const int CAD_ODE_B_nz_rows[1] = {-1};
static const int CAD_ODE_B_nz_cols[1] = {-1};
static const int CAD_ODE_C_nz_rows[1] = {-1};
static const int CAD_ODE_C_nz_cols[1] = {-1};
static const int CAD_ODE_D_nz_rows[1] = {-1};
static const int CAD_ODE_D_nz_cols[1] = {-1};


static const int N_initial_relations = 0;
static const int DAE_initial_relations[] = { -1 };

static const int N_relations = 11;
static const int DAE_relations[] = { JMI_REL_GEQ, JMI_REL_LEQ, JMI_REL_GT, JMI_REL_LT, JMI_REL_GEQ, JMI_REL_LEQ, JMI_REL_LT, JMI_REL_LT, JMI_REL_LT, JMI_REL_LT, JMI_REL_LT };

static const int N_nominals = 6;
static const jmi_real_t DAE_nominals[] = { 1.0, 1.0, 1.0, 1.0E-4, 1.0, 1.0 };

#define _PI_unitTime_18 ((*(jmi->z))[jmi->offs_real_ci+0])
#define _torque_phi_support_59 ((*(jmi->z))[jmi->offs_real_ci+1])
#define _speedSensor_flange_tau_101 ((*(jmi->z))[jmi->offs_real_ci+2])
#define _loadTorque_phi_support_105 ((*(jmi->z))[jmi->offs_real_ci+3])
#define _driveAngle_0 ((*(jmi->z))[jmi->offs_real_pi+0])
#define _PI_k_3 ((*(jmi->z))[jmi->offs_real_pi+1])
#define _PI_Ti_4 ((*(jmi->z))[jmi->offs_real_pi+2])
#define _PI_Td_5 ((*(jmi->z))[jmi->offs_real_pi+3])
#define _PI_wp_8 ((*(jmi->z))[jmi->offs_real_pi+4])
#define _PI_wd_9 ((*(jmi->z))[jmi->offs_real_pi+5])
#define _PI_Ni_10 ((*(jmi->z))[jmi->offs_real_pi+6])
#define _PI_Nd_11 ((*(jmi->z))[jmi->offs_real_pi+7])
#define _PI_xi_start_14 ((*(jmi->z))[jmi->offs_real_pi+8])
#define _PI_xd_start_15 ((*(jmi->z))[jmi->offs_real_pi+9])
#define _PI_addP_k2_20 ((*(jmi->z))[jmi->offs_real_pi+10])
#define _PI_P_k_21 ((*(jmi->z))[jmi->offs_real_pi+11])
#define _PI_addPID_k1_30 ((*(jmi->z))[jmi->offs_real_pi+12])
#define _PI_addPID_k2_31 ((*(jmi->z))[jmi->offs_real_pi+13])
#define _PI_addPID_k3_32 ((*(jmi->z))[jmi->offs_real_pi+14])
#define _PI_addI_k1_34 ((*(jmi->z))[jmi->offs_real_pi+15])
#define _PI_addI_k2_35 ((*(jmi->z))[jmi->offs_real_pi+16])
#define _PI_addI_k3_36 ((*(jmi->z))[jmi->offs_real_pi+17])
#define _PI_addSat_k1_38 ((*(jmi->z))[jmi->offs_real_pi+18])
#define _PI_addSat_k2_39 ((*(jmi->z))[jmi->offs_real_pi+19])
#define _PI_limiter_uMax_43 ((*(jmi->z))[jmi->offs_real_pi+20])
#define _PI_limiter_uMin_44 ((*(jmi->z))[jmi->offs_real_pi+21])
#define _PI_Dzero_k_49 ((*(jmi->z))[jmi->offs_real_pi+22])
#define _inertia1_J_52 ((*(jmi->z))[jmi->offs_real_pi+23])
#define _spring_c_60 ((*(jmi->z))[jmi->offs_real_pi+24])
#define _spring_d_61 ((*(jmi->z))[jmi->offs_real_pi+25])
#define _spring_phi_rel0_62 ((*(jmi->z))[jmi->offs_real_pi+26])
#define _spring_phi_nominal_69 ((*(jmi->z))[jmi->offs_real_pi+27])
#define _inertia2_J_73 ((*(jmi->z))[jmi->offs_real_pi+28])
#define _kinematicPTP_qd_max_1_79 ((*(jmi->z))[jmi->offs_real_pi+29])
#define _kinematicPTP_qdd_max_1_80 ((*(jmi->z))[jmi->offs_real_pi+30])
#define _kinematicPTP_startTime_81 ((*(jmi->z))[jmi->offs_real_pi+31])
#define _integrator_k_96 ((*(jmi->z))[jmi->offs_real_pi+32])
#define _integrator_y_start_98 ((*(jmi->z))[jmi->offs_real_pi+33])
#define _loadTorque_tau_constant_102 ((*(jmi->z))[jmi->offs_real_pi+34])
#define __block_jacobian_check_tol_113 ((*(jmi->z))[jmi->offs_real_pi+35])
#define __cs_rel_tol_115 ((*(jmi->z))[jmi->offs_real_pi+36])
#define __cs_step_size_117 ((*(jmi->z))[jmi->offs_real_pi+37])
#define __events_default_tol_119 ((*(jmi->z))[jmi->offs_real_pi+38])
#define __events_tol_factor_120 ((*(jmi->z))[jmi->offs_real_pi+39])
#define __nle_solver_default_tol_124 ((*(jmi->z))[jmi->offs_real_pi+40])
#define __nle_solver_min_tol_126 ((*(jmi->z))[jmi->offs_real_pi+41])
#define __nle_solver_regularization_tolerance_127 ((*(jmi->z))[jmi->offs_real_pi+42])
#define __nle_solver_step_limit_factor_128 ((*(jmi->z))[jmi->offs_real_pi+43])
#define __nle_solver_tol_factor_129 ((*(jmi->z))[jmi->offs_real_pi+44])
#define _PI_yMax_6 ((*(jmi->z))[jmi->offs_real_pi+45])
#define _PI_yMin_7 ((*(jmi->z))[jmi->offs_real_pi+46])
#define _PI_y_start_16 ((*(jmi->z))[jmi->offs_real_pi+47])
#define _PI_addP_k1_19 ((*(jmi->z))[jmi->offs_real_pd+0])
#define _PI_I_k_24 ((*(jmi->z))[jmi->offs_real_pd+1])
#define _PI_I_y_start_26 ((*(jmi->z))[jmi->offs_real_pd+2])
#define _PI_gainPID_k_29 ((*(jmi->z))[jmi->offs_real_pd+3])
#define _PI_gainTrack_k_42 ((*(jmi->z))[jmi->offs_real_pd+4])
#define _kinematicPTP_deltaq_1_50 ((*(jmi->z))[jmi->offs_real_pd+5])
#define _kinematicPTP_p_qd_max_1_78 ((*(jmi->z))[jmi->offs_real_pd+6])
#define _kinematicPTP_p_qdd_max_1_82 ((*(jmi->z))[jmi->offs_real_pd+7])
#define _PI_Dzero_y_83 ((*(jmi->z))[jmi->offs_real_pd+8])
#define _loadTorque_tau_84 ((*(jmi->z))[jmi->offs_real_pd+9])
#define _kinematicPTP_p_deltaq_1_85 ((*(jmi->z))[jmi->offs_real_pd+10])
#define _PI_addPID_u2_86 ((*(jmi->z))[jmi->offs_real_pd+11])
#define _loadTorque_flange_tau_88 ((*(jmi->z))[jmi->offs_real_pd+12])
#define _inertia2_flange_b_tau_89 ((*(jmi->z))[jmi->offs_real_pd+13])
#define _kinematicPTP_aux1_1_90 ((*(jmi->z))[jmi->offs_real_pd+14])
#define _kinematicPTP_aux2_1_91 ((*(jmi->z))[jmi->offs_real_pd+15])
#define _kinematicPTP_sd_max_92 ((*(jmi->z))[jmi->offs_real_pd+16])
#define _kinematicPTP_sdd_max_93 ((*(jmi->z))[jmi->offs_real_pd+17])
#define _kinematicPTP_Ta1_94 ((*(jmi->z))[jmi->offs_real_pd+18])
#define _kinematicPTP_Ta2_103 ((*(jmi->z))[jmi->offs_real_pd+19])
#define _kinematicPTP_Tv_107 ((*(jmi->z))[jmi->offs_real_pd+20])
#define _kinematicPTP_Te_108 ((*(jmi->z))[jmi->offs_real_pd+21])
#define __block_solver_experimental_mode_114 ((*(jmi->z))[jmi->offs_integer_pi+0])
#define __cs_solver_116 ((*(jmi->z))[jmi->offs_integer_pi+1])
#define __iteration_variable_scaling_121 ((*(jmi->z))[jmi->offs_integer_pi+2])
#define __log_level_122 ((*(jmi->z))[jmi->offs_integer_pi+3])
#define __nle_solver_max_iter_125 ((*(jmi->z))[jmi->offs_integer_pi+4])
#define __residual_equation_scaling_132 ((*(jmi->z))[jmi->offs_integer_pi+5])
#define _inertia1_stateSelect_53 ((*(jmi->z))[jmi->offs_integer_pi+6])
#define _spring_stateSelect_70 ((*(jmi->z))[jmi->offs_integer_pi+7])
#define _inertia2_stateSelect_74 ((*(jmi->z))[jmi->offs_integer_pi+8])
#define _kinematicPTP_nout_95 ((*(jmi->z))[jmi->offs_integer_pi+9])
#define _PI_controllerType_2 ((*(jmi->z))[jmi->offs_integer_pi+10])
#define _PI_initType_12 ((*(jmi->z))[jmi->offs_integer_pi+11])
#define _PI_I_initType_25 ((*(jmi->z))[jmi->offs_integer_pi+12])
#define _integrator_initType_97 ((*(jmi->z))[jmi->offs_integer_pi+13])
#define __block_jacobian_check_112 ((*(jmi->z))[jmi->offs_boolean_pi+0])
#define __enforce_bounds_118 ((*(jmi->z))[jmi->offs_boolean_pi+1])
#define __nle_solver_check_jac_cond_123 ((*(jmi->z))[jmi->offs_boolean_pi+2])
#define __rescale_after_singular_jac_130 ((*(jmi->z))[jmi->offs_boolean_pi+3])
#define __rescale_each_step_131 ((*(jmi->z))[jmi->offs_boolean_pi+4])
#define __runtime_log_to_file_133 ((*(jmi->z))[jmi->offs_boolean_pi+5])
#define __use_Brent_in_1d_134 ((*(jmi->z))[jmi->offs_boolean_pi+6])
#define __use_jacobian_equilibration_135 ((*(jmi->z))[jmi->offs_boolean_pi+7])
#define _PI_limitsAtInit_13 ((*(jmi->z))[jmi->offs_boolean_pi+8])
#define _PI_strict_17 ((*(jmi->z))[jmi->offs_boolean_pi+9])
#define _PI_limiter_strict_45 ((*(jmi->z))[jmi->offs_boolean_pi+10])
#define _PI_limiter_limitsAtInit_46 ((*(jmi->z))[jmi->offs_boolean_pi+11])
#define _PI_with_I_47 ((*(jmi->z))[jmi->offs_boolean_pi+12])
#define _PI_with_D_48 ((*(jmi->z))[jmi->offs_boolean_pi+13])
#define _torque_useSupport_58 ((*(jmi->z))[jmi->offs_boolean_pi+14])
#define _spring_useHeatPort_71 ((*(jmi->z))[jmi->offs_boolean_pi+15])
#define _loadTorque_useSupport_104 ((*(jmi->z))[jmi->offs_boolean_pi+16])
#define _kinematicPTP_noWphase_106 ((*(jmi->z))[jmi->offs_boolean_pd+0])
#define _der_spring_w_rel_139 ((*(jmi->z))[jmi->offs_real_dx+0])
#define _der_PI_I_y_140 ((*(jmi->z))[jmi->offs_real_dx+1])
#define _der_inertia1_phi_141 ((*(jmi->z))[jmi->offs_real_dx+2])
#define _der_spring_phi_rel_142 ((*(jmi->z))[jmi->offs_real_dx+3])
#define _der_integrator_y_143 ((*(jmi->z))[jmi->offs_real_dx+4])
#define _der_inertia1__der_phi_144 ((*(jmi->z))[jmi->offs_real_dx+5])
#define _spring_w_rel_66 ((*(jmi->z))[jmi->offs_real_x+0])
#define _PI_I_y_28 ((*(jmi->z))[jmi->offs_real_x+1])
#define _inertia1_phi_54 ((*(jmi->z))[jmi->offs_real_x+2])
#define _spring_phi_rel_65 ((*(jmi->z))[jmi->offs_real_x+3])
#define _integrator_y_100 ((*(jmi->z))[jmi->offs_real_x+4])
#define _inertia1__der_phi_136 ((*(jmi->z))[jmi->offs_real_x+5])
#define _PI_controlError_1 ((*(jmi->z))[jmi->offs_real_w+0])
#define _PI_P_u_22 ((*(jmi->z))[jmi->offs_real_w+1])
#define _PI_P_y_23 ((*(jmi->z))[jmi->offs_real_w+2])
#define _PI_I_u_27 ((*(jmi->z))[jmi->offs_real_w+3])
#define _PI_addPID_y_33 ((*(jmi->z))[jmi->offs_real_w+4])
#define _PI_addI_u3_37 ((*(jmi->z))[jmi->offs_real_w+5])
#define _PI_addSat_u2_40 ((*(jmi->z))[jmi->offs_real_w+6])
#define _PI_addSat_y_41 ((*(jmi->z))[jmi->offs_real_w+7])
#define _PI_u_m_51 ((*(jmi->z))[jmi->offs_real_w+8])
#define _inertia1_w_55 ((*(jmi->z))[jmi->offs_real_w+9])
#define _inertia1_a_56 ((*(jmi->z))[jmi->offs_real_w+10])
#define _torque_tau_57 ((*(jmi->z))[jmi->offs_real_w+11])
#define _spring_tau_c_63 ((*(jmi->z))[jmi->offs_real_w+12])
#define _spring_tau_d_64 ((*(jmi->z))[jmi->offs_real_w+13])
#define _spring_a_rel_67 ((*(jmi->z))[jmi->offs_real_w+14])
#define _spring_tau_68 ((*(jmi->z))[jmi->offs_real_w+15])
#define _spring_lossPower_72 ((*(jmi->z))[jmi->offs_real_w+16])
#define _inertia2_phi_75 ((*(jmi->z))[jmi->offs_real_w+17])
#define _inertia2_w_76 ((*(jmi->z))[jmi->offs_real_w+18])
#define _inertia2_a_77 ((*(jmi->z))[jmi->offs_real_w+19])
#define _kinematicPTP_sdd_87 ((*(jmi->z))[jmi->offs_real_w+20])
#define _integrator_u_99 ((*(jmi->z))[jmi->offs_real_w+21])
#define _der_inertia1_w_109 ((*(jmi->z))[jmi->offs_real_w+22])
#define _der_inertia2_phi_110 ((*(jmi->z))[jmi->offs_real_w+23])
#define _der_inertia2_w_111 ((*(jmi->z))[jmi->offs_real_w+24])
#define _der_2_spring_phi_rel_137 ((*(jmi->z))[jmi->offs_real_w+25])
#define _der_2_inertia2_phi_138 ((*(jmi->z))[jmi->offs_real_w+26])
#define _time ((*(jmi->z))[jmi->offs_t])
#define pre_der_spring_w_rel_139 ((*(jmi->z))[jmi->offs_pre_real_dx+0])
#define pre_der_PI_I_y_140 ((*(jmi->z))[jmi->offs_pre_real_dx+1])
#define pre_der_inertia1_phi_141 ((*(jmi->z))[jmi->offs_pre_real_dx+2])
#define pre_der_spring_phi_rel_142 ((*(jmi->z))[jmi->offs_pre_real_dx+3])
#define pre_der_integrator_y_143 ((*(jmi->z))[jmi->offs_pre_real_dx+4])
#define pre_der_inertia1__der_phi_144 ((*(jmi->z))[jmi->offs_pre_real_dx+5])
#define pre_spring_w_rel_66 ((*(jmi->z))[jmi->offs_pre_real_x+0])
#define pre_PI_I_y_28 ((*(jmi->z))[jmi->offs_pre_real_x+1])
#define pre_inertia1_phi_54 ((*(jmi->z))[jmi->offs_pre_real_x+2])
#define pre_spring_phi_rel_65 ((*(jmi->z))[jmi->offs_pre_real_x+3])
#define pre_integrator_y_100 ((*(jmi->z))[jmi->offs_pre_real_x+4])
#define pre_inertia1__der_phi_136 ((*(jmi->z))[jmi->offs_pre_real_x+5])
#define pre_PI_controlError_1 ((*(jmi->z))[jmi->offs_pre_real_w+0])
#define pre_PI_P_u_22 ((*(jmi->z))[jmi->offs_pre_real_w+1])
#define pre_PI_P_y_23 ((*(jmi->z))[jmi->offs_pre_real_w+2])
#define pre_PI_I_u_27 ((*(jmi->z))[jmi->offs_pre_real_w+3])
#define pre_PI_addPID_y_33 ((*(jmi->z))[jmi->offs_pre_real_w+4])
#define pre_PI_addI_u3_37 ((*(jmi->z))[jmi->offs_pre_real_w+5])
#define pre_PI_addSat_u2_40 ((*(jmi->z))[jmi->offs_pre_real_w+6])
#define pre_PI_addSat_y_41 ((*(jmi->z))[jmi->offs_pre_real_w+7])
#define pre_PI_u_m_51 ((*(jmi->z))[jmi->offs_pre_real_w+8])
#define pre_inertia1_w_55 ((*(jmi->z))[jmi->offs_pre_real_w+9])
#define pre_inertia1_a_56 ((*(jmi->z))[jmi->offs_pre_real_w+10])
#define pre_torque_tau_57 ((*(jmi->z))[jmi->offs_pre_real_w+11])
#define pre_spring_tau_c_63 ((*(jmi->z))[jmi->offs_pre_real_w+12])
#define pre_spring_tau_d_64 ((*(jmi->z))[jmi->offs_pre_real_w+13])
#define pre_spring_a_rel_67 ((*(jmi->z))[jmi->offs_pre_real_w+14])
#define pre_spring_tau_68 ((*(jmi->z))[jmi->offs_pre_real_w+15])
#define pre_spring_lossPower_72 ((*(jmi->z))[jmi->offs_pre_real_w+16])
#define pre_inertia2_phi_75 ((*(jmi->z))[jmi->offs_pre_real_w+17])
#define pre_inertia2_w_76 ((*(jmi->z))[jmi->offs_pre_real_w+18])
#define pre_inertia2_a_77 ((*(jmi->z))[jmi->offs_pre_real_w+19])
#define pre_kinematicPTP_sdd_87 ((*(jmi->z))[jmi->offs_pre_real_w+20])
#define pre_integrator_u_99 ((*(jmi->z))[jmi->offs_pre_real_w+21])
#define pre_der_inertia1_w_109 ((*(jmi->z))[jmi->offs_pre_real_w+22])
#define pre_der_inertia2_phi_110 ((*(jmi->z))[jmi->offs_pre_real_w+23])
#define pre_der_inertia2_w_111 ((*(jmi->z))[jmi->offs_pre_real_w+24])
#define pre_der_2_spring_phi_rel_137 ((*(jmi->z))[jmi->offs_pre_real_w+25])
#define pre_der_2_inertia2_phi_138 ((*(jmi->z))[jmi->offs_pre_real_w+26])


const char *fmi_runtime_options_map_names[] = {
    "_block_jacobian_check",
    "_block_jacobian_check_tol",
    "_block_solver_experimental_mode",
    "_cs_rel_tol",
    "_cs_solver",
    "_cs_step_size",
    "_enforce_bounds",
    "_events_default_tol",
    "_events_tol_factor",
    "_iteration_variable_scaling",
    "_log_level",
    "_nle_solver_check_jac_cond",
    "_nle_solver_default_tol",
    "_nle_solver_max_iter",
    "_nle_solver_min_tol",
    "_nle_solver_regularization_tolerance",
    "_nle_solver_step_limit_factor",
    "_nle_solver_tol_factor",
    "_rescale_after_singular_jac",
    "_rescale_each_step",
    "_residual_equation_scaling",
    "_runtime_log_to_file",
    "_use_Brent_in_1d",
    "_use_jacobian_equilibration",
    NULL
};

const int fmi_runtime_options_map_vrefs[] = {
    536871000, 39, 268435530, 40, 268435531, 41, 536871001, 42, 43, 268435532,
    268435533, 536871002, 44, 268435534, 45, 46, 47, 48, 536871003, 536871004,
    268435535, 536871005, 536871006, 536871007, 0
};

const int fmi_runtime_options_map_length = 24;

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



char* SimpleController_0_e[] = { "", "P", "PI", "PD", "PID" };
char* InitPID_1_e[] = { "", "NoInit", "SteadyState", "InitialState", "InitialOutput", "DoNotUse_InitialIntegratorState" };
char* Init_2_e[] = { "", "NoInit", "SteadyState", "InitialState", "InitialOutput" };
char* StateSelect_3_e[] = { "", "never", "avoid", "default", "prefer", "always" };








static int dae_init_block_0(jmi_t* jmi, jmi_real_t* x, jmi_real_t* residual, int evaluation_mode) {
    /***** Init block: 1 *****/
    jmi_real_t** res = &residual;
    int ef = 0;
    if (evaluation_mode == JMI_BLOCK_NOMINAL) {
    } else if (evaluation_mode == JMI_BLOCK_START) {
    } else if (evaluation_mode == JMI_BLOCK_MIN) {
    } else if (evaluation_mode == JMI_BLOCK_MAX) {
    } else if (evaluation_mode == JMI_BLOCK_VALUE_REFERENCE) {
        x[0] = 124;
    } else if (evaluation_mode == JMI_BLOCK_NON_REAL_VALUE_REFERENCE) {
    } else if (evaluation_mode == JMI_BLOCK_ACTIVE_SWITCH_INDEX) {
        x[0] = jmi->offs_sw + 2;
        x[1] = jmi->offs_sw + 3;
    } else if (evaluation_mode == JMI_BLOCK_EQUATION_NOMINAL) {
    } else if (evaluation_mode == JMI_BLOCK_INITIALIZE) {
        x[0] = _PI_addSat_u2_40;
    } else if (evaluation_mode & JMI_BLOCK_EVALUATE || evaluation_mode & JMI_BLOCK_WRITE_BACK) {
        if ((evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) == 0) {
            _PI_addSat_u2_40 = x[0];
        }
        if (evaluation_mode & JMI_BLOCK_EVALUATE) {
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(2) = jmi_turn_switch(_PI_addSat_u2_40 - (_PI_limiter_uMax_43), _sw(2), jmi->events_epsilon, JMI_REL_GT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(3) = jmi_turn_switch(_PI_addSat_u2_40 - (_PI_limiter_uMin_44), _sw(3), jmi->events_epsilon, JMI_REL_LT);
            }
            (*res)[0] = COND_EXP_EQ(LOG_EXP_AND(_atInitial, JMI_TRUE), JMI_TRUE, _PI_addSat_u2_40, (COND_EXP_EQ(_sw(2), JMI_TRUE, _PI_limiter_uMax_43, COND_EXP_EQ(_sw(3), JMI_TRUE, _PI_limiter_uMin_44, _PI_addSat_u2_40)))) - (_torque_tau_57);
        }
    }
    return ef;
}

static int dae_init_block_1(jmi_t* jmi, jmi_real_t* x, jmi_real_t* residual, int evaluation_mode) {
    /***** Init block: 2 *****/
    jmi_real_t** res = &residual;
    int ef = 0;
    if (evaluation_mode == JMI_BLOCK_NOMINAL) {
        x[0] = 1.0E-4;
    } else if (evaluation_mode == JMI_BLOCK_START) {
    } else if (evaluation_mode == JMI_BLOCK_MIN) {
    } else if (evaluation_mode == JMI_BLOCK_MAX) {
    } else if (evaluation_mode == JMI_BLOCK_VALUE_REFERENCE) {
        x[0] = 115;
    } else if (evaluation_mode == JMI_BLOCK_NON_REAL_VALUE_REFERENCE) {
    } else if (evaluation_mode == JMI_BLOCK_ACTIVE_SWITCH_INDEX) {
    } else if (evaluation_mode == JMI_BLOCK_EQUATION_NOMINAL) {
    } else if (evaluation_mode == JMI_BLOCK_INITIALIZE) {
        x[0] = _spring_phi_rel_65;
    } else if (evaluation_mode==JMI_BLOCK_EVALUATE_JACOBIAN) {
        memset(residual, 0, 1 * sizeof(jmi_real_t));
        residual[0] = (- _spring_c_60);
    } else if (evaluation_mode & JMI_BLOCK_EVALUATE || evaluation_mode & JMI_BLOCK_WRITE_BACK) {
        if ((evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) == 0) {
            _spring_phi_rel_65 = x[0];
        }
        if (evaluation_mode & JMI_BLOCK_EVALUATE) {
            (*res)[0] = _spring_c_60 * (_spring_phi_rel_65 - _spring_phi_rel0_62) - (_spring_tau_c_63);
        }
    }
    return ef;
}














static int model_ode_guards(jmi_t* jmi) {

    return 0;
}

static int model_ode_next_time_event(jmi_t* jmi, jmi_real_t* nextTime) {
  jmi_real_t nextTimeEvent;
  jmi_real_t nextTimeEventTmp;
  jmi_real_t nSamp;
  nextTimeEvent = JMI_INF;
  *nextTime = nextTimeEvent;

    return 0;
}

static int model_ode_derivatives(jmi_t* jmi) {
    int ef = 0;
    model_ode_guards(jmi);
/************* ODE section *********/
    _spring_tau_c_63 = _spring_c_60 * (_spring_phi_rel_65 - _spring_phi_rel0_62);
    _spring_tau_d_64 = _spring_d_61 * _spring_w_rel_66;
    _spring_tau_68 = _spring_tau_c_63 + _spring_tau_d_64;
    _inertia2_a_77 = jmi_divide_equation(jmi, (- _spring_tau_68 + _loadTorque_tau_84),_inertia2_J_73,"(- spring.tau + loadTorque.tau) / inertia2.J");
    _der_inertia2_w_111 = _inertia2_a_77;
    _der_2_inertia2_phi_138 = _der_inertia2_w_111;
    _der_inertia1_phi_141 = _inertia1__der_phi_136;
    _PI_u_m_51 = _der_inertia1_phi_141;
    _PI_P_u_22 = _PI_addP_k1_19 * _integrator_y_100 + _PI_addP_k2_20 * _PI_u_m_51;
    _PI_P_y_23 = _PI_P_k_21 * _PI_P_u_22;
    _PI_addPID_y_33 = _PI_addPID_k1_30 * _PI_P_y_23 + _PI_addPID_k2_31 * _PI_Dzero_y_83 + _PI_addPID_k3_32 * _PI_I_y_28;
    _PI_addSat_u2_40 = _PI_gainPID_k_29 * _PI_addPID_y_33;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(2) = jmi_turn_switch(_PI_addSat_u2_40 - (_PI_limiter_uMax_43), _sw(2), jmi->events_epsilon, JMI_REL_GT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(3) = jmi_turn_switch(_PI_addSat_u2_40 - (_PI_limiter_uMin_44), _sw(3), jmi->events_epsilon, JMI_REL_LT);
    }
    _torque_tau_57 = COND_EXP_EQ(LOG_EXP_AND(_atInitial, JMI_TRUE), JMI_TRUE, _PI_addSat_u2_40, (COND_EXP_EQ(_sw(2), JMI_TRUE, _PI_limiter_uMax_43, COND_EXP_EQ(_sw(3), JMI_TRUE, _PI_limiter_uMin_44, _PI_addSat_u2_40))));
    _inertia1_a_56 = jmi_divide_equation(jmi, (_torque_tau_57 + _spring_tau_68),_inertia1_J_52,"(torque.tau + spring.tau) / inertia1.J");
    _der_inertia1_w_109 = _inertia1_a_56;
    _der_inertia1__der_phi_144 = _der_inertia1_w_109;
    _der_2_spring_phi_rel_137 = _der_2_inertia2_phi_138 + (- _der_inertia1__der_phi_144);
    _der_spring_w_rel_139 = _der_2_spring_phi_rel_137;
    _PI_addSat_y_41 = _PI_addSat_k1_38 * _torque_tau_57 + _PI_addSat_k2_39 * _PI_addSat_u2_40;
    _PI_addI_u3_37 = _PI_gainTrack_k_42 * _PI_addSat_y_41;
    _PI_I_u_27 = _PI_addI_k1_34 * _integrator_y_100 + _PI_addI_k2_35 * _PI_u_m_51 + _PI_addI_k3_36 * _PI_addI_u3_37;
    _der_PI_I_y_140 = _PI_I_k_24 * _PI_I_u_27;
    _der_spring_phi_rel_142 = _spring_w_rel_66;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(6) = jmi_turn_switch(_time - (_kinematicPTP_startTime_81), _sw(6), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(7) = jmi_turn_switch(_time - (_kinematicPTP_Ta1_94 + _kinematicPTP_startTime_81), _sw(7), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(8) = jmi_turn_switch(_time - (_kinematicPTP_Te_108 + _kinematicPTP_startTime_81), _sw(8), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(9) = jmi_turn_switch(_time - (_kinematicPTP_Ta2_103 + _kinematicPTP_startTime_81), _sw(9), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(10) = jmi_turn_switch(_time - (_kinematicPTP_Tv_107 + _kinematicPTP_startTime_81), _sw(10), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(8) = jmi_turn_switch(_time - (_kinematicPTP_Te_108 + _kinematicPTP_startTime_81), _sw(8), jmi->events_epsilon, JMI_REL_LT);
    }
    _kinematicPTP_sdd_87 = COND_EXP_EQ(_sw(6), JMI_TRUE, AD_WRAP_LITERAL(0), COND_EXP_EQ(_kinematicPTP_noWphase_106, JMI_TRUE, COND_EXP_EQ(_sw(7), JMI_TRUE, _kinematicPTP_sdd_max_93, COND_EXP_EQ(_sw(8), JMI_TRUE, - _kinematicPTP_sdd_max_93, AD_WRAP_LITERAL(0))), COND_EXP_EQ(_sw(9), JMI_TRUE, _kinematicPTP_sdd_max_93, COND_EXP_EQ(_sw(10), JMI_TRUE, AD_WRAP_LITERAL(0), COND_EXP_EQ(_sw(8), JMI_TRUE, - _kinematicPTP_sdd_max_93, AD_WRAP_LITERAL(0))))));
    _integrator_u_99 = _kinematicPTP_p_deltaq_1_85 * _kinematicPTP_sdd_87;
    _der_integrator_y_143 = _integrator_k_96 * _integrator_u_99;
/************ Real outputs *********/
/****Integer and boolean outputs ***/
/**** Other variables ***/
    _PI_controlError_1 = _integrator_y_100 + (- _PI_u_m_51);
    _inertia1_w_55 = _der_inertia1_phi_141;
    _spring_a_rel_67 = _der_spring_w_rel_139;
    _spring_lossPower_72 = _spring_tau_d_64 * _spring_w_rel_66;
    _inertia2_phi_75 = - (- _spring_phi_rel_65 + (- _inertia1_phi_54));
    _der_inertia2_phi_110 = - (- _der_spring_phi_rel_142 + (- _der_inertia1_phi_141));
    _inertia2_w_76 = _der_inertia2_phi_110;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(0) = jmi_turn_switch(_torque_tau_57 - (AD_WRAP_LITERAL(-12.0)), _sw(0), jmi->events_epsilon, JMI_REL_GEQ);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(1) = jmi_turn_switch(_torque_tau_57 - (AD_WRAP_LITERAL(12.0)), _sw(1), jmi->events_epsilon, JMI_REL_LEQ);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(0) = jmi_turn_switch(_torque_tau_57 - (AD_WRAP_LITERAL(-12.0)), _sw(0), jmi->events_epsilon, JMI_REL_GEQ);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(1) = jmi_turn_switch(_torque_tau_57 - (AD_WRAP_LITERAL(12.0)), _sw(1), jmi->events_epsilon, JMI_REL_LEQ);
    }
    if (LOG_EXP_OR(JMI_FALSE, LOG_EXP_AND(LOG_EXP_AND(JMI_TRUE, _sw(0)), _sw(1))) == JMI_FALSE) {
        JMI_DEF_STR_STAT(tmp_1, 182)
        JMI_INI_STR_STAT(tmp_1)
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%s", "LimPID: During initialization the limits have been switched off.\nAfter initialization, the output y (=");
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%-.*g", (int) 6, _torque_tau_57);
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%s", ") is outside of the limits of yMin (=");
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%s", "-12.0000");
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%s", ") and yMax (=");
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%s", "12.0000");
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%s", ")");
        jmi_assert_failed(tmp_1, JMI_ASSERT_ERROR);
    }
    if (COND_EXP_GE(_PI_limiter_uMax_43, _PI_limiter_uMin_44, JMI_TRUE, JMI_FALSE) == JMI_FALSE) {
        JMI_DEF_STR_STAT(tmp_2, 90)
        JMI_INI_STR_STAT(tmp_2)
        snprintf(JMI_STR_END(tmp_2), JMI_STR_LEFT(tmp_2), "%s", "Limiter: Limits must be consistent. However, uMax (=");
        snprintf(JMI_STR_END(tmp_2), JMI_STR_LEFT(tmp_2), "%-.*g", (int) 6, _PI_limiter_uMax_43);
        snprintf(JMI_STR_END(tmp_2), JMI_STR_LEFT(tmp_2), "%s", ") < uMin (=");
        snprintf(JMI_STR_END(tmp_2), JMI_STR_LEFT(tmp_2), "%-.*g", (int) 6, _PI_limiter_uMin_44);
        snprintf(JMI_STR_END(tmp_2), JMI_STR_LEFT(tmp_2), "%s", ")");
        jmi_assert_failed(tmp_2, JMI_ASSERT_ERROR);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(4) = jmi_turn_switch(_PI_addSat_u2_40 - (_PI_limiter_uMin_44 - AD_WRAP_LITERAL(0.01) * jmi_abs(_PI_limiter_uMin_44)), _sw(4), jmi->events_epsilon, JMI_REL_GEQ);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(5) = jmi_turn_switch(_PI_addSat_u2_40 - (_PI_limiter_uMax_43 + AD_WRAP_LITERAL(0.01) * jmi_abs(_PI_limiter_uMax_43)), _sw(5), jmi->events_epsilon, JMI_REL_LEQ);
    }
    if (LOG_EXP_AND(_atInitial, JMI_TRUE)) {
        if (jmi->atInitial || jmi->atEvent) {
            _sw(4) = jmi_turn_switch(_PI_addSat_u2_40 - (_PI_limiter_uMin_44 - AD_WRAP_LITERAL(0.01) * jmi_abs(_PI_limiter_uMin_44)), _sw(4), jmi->events_epsilon, JMI_REL_GEQ);
        }
        if (jmi->atInitial || jmi->atEvent) {
            _sw(5) = jmi_turn_switch(_PI_addSat_u2_40 - (_PI_limiter_uMax_43 + AD_WRAP_LITERAL(0.01) * jmi_abs(_PI_limiter_uMax_43)), _sw(5), jmi->events_epsilon, JMI_REL_LEQ);
        }
        if (LOG_EXP_AND(_sw(4), _sw(5)) == JMI_FALSE) {
            JMI_DEF_STR_STAT(tmp_3, 201)
            JMI_INI_STR_STAT(tmp_3)
            snprintf(JMI_STR_END(tmp_3), JMI_STR_LEFT(tmp_3), "%s", "Limiter: During initialization the limits have been ignored.\nHowever, the result is that the input u is not within the required limits:\n  u = ");
            snprintf(JMI_STR_END(tmp_3), JMI_STR_LEFT(tmp_3), "%-.*g", (int) 6, _PI_addSat_u2_40);
            snprintf(JMI_STR_END(tmp_3), JMI_STR_LEFT(tmp_3), "%s", ", uMin = ");
            snprintf(JMI_STR_END(tmp_3), JMI_STR_LEFT(tmp_3), "%-.*g", (int) 6, _PI_limiter_uMin_44);
            snprintf(JMI_STR_END(tmp_3), JMI_STR_LEFT(tmp_3), "%s", ", uMax = ");
            snprintf(JMI_STR_END(tmp_3), JMI_STR_LEFT(tmp_3), "%-.*g", (int) 6, _PI_limiter_uMax_43);
            jmi_assert_failed(tmp_3, JMI_ASSERT_ERROR);
        }
    }
/********* Write back reinits *******/

    return ef;
}

static int model_ode_derivatives_dir_der(jmi_t* jmi) {
    int ef = 0;

    return ef;
}

static int model_ode_outputs(jmi_t* jmi) {
    int ef = 0;

    return ef;
}

static int model_ode_guards_init(jmi_t* jmi) {

    return 0;
}

static int model_ode_initialize(jmi_t* jmi) {
    int ef = 0;
    model_ode_guards(jmi);
    _der_PI_I_y_140 = 0;
    _PI_I_u_27 = jmi_divide_equation(jmi, (- _der_PI_I_y_140),(- _PI_I_k_24),"(- der(PI.I.y)) / (- PI.I.k)");
    _inertia1_a_56 = 0;
    _der_spring_w_rel_139 = 0;
    _der_2_spring_phi_rel_137 = _der_spring_w_rel_139;
    _der_inertia1_w_109 = _inertia1_a_56;
    _der_inertia1__der_phi_144 = _der_inertia1_w_109;
    _der_2_inertia2_phi_138 = - (- _der_2_spring_phi_rel_137 + (- _der_inertia1__der_phi_144));
    _der_inertia2_w_111 = _der_2_inertia2_phi_138;
    _inertia2_a_77 = _der_inertia2_w_111;
    _spring_tau_68 = jmi_divide_equation(jmi, (- _inertia2_J_73 * _inertia2_a_77 + _loadTorque_tau_84),1.0,"(- inertia2.J * inertia2.a + loadTorque.tau) / 1.0");
    _torque_tau_57 = - (- _inertia1_J_52 * _inertia1_a_56 + _spring_tau_68);
    ef |= jmi_solve_block_residual(jmi->dae_init_block_residuals[0]);
    _PI_addSat_y_41 = _PI_addSat_k1_38 * _torque_tau_57 + _PI_addSat_k2_39 * _PI_addSat_u2_40;
    _PI_addI_u3_37 = _PI_gainTrack_k_42 * _PI_addSat_y_41;
    _integrator_y_100 = _integrator_y_start_98;
    _PI_u_m_51 = jmi_divide_equation(jmi, (- _PI_I_u_27 + _PI_addI_k1_34 * _integrator_y_100 + _PI_addI_k3_36 * _PI_addI_u3_37),(- _PI_addI_k2_35),"(- PI.I.u + PI.addI.k1 * integrator.y + PI.addI.k3 * PI.addI.u3) / (- PI.addI.k2)");
    _PI_P_u_22 = _PI_addP_k1_19 * _integrator_y_100 + _PI_addP_k2_20 * _PI_u_m_51;
    _PI_P_y_23 = _PI_P_k_21 * _PI_P_u_22;
    _PI_addPID_y_33 = jmi_divide_equation(jmi, (- _PI_addSat_u2_40),(- _PI_gainPID_k_29),"(- PI.addSat.u2) / (- PI.gainPID.k)");
    _PI_I_y_28 = jmi_divide_equation(jmi, (- _PI_addPID_y_33 + _PI_addPID_k1_30 * _PI_P_y_23 + _PI_addPID_k2_31 * _PI_Dzero_y_83),(- _PI_addPID_k3_32),"(- PI.addPID.y + PI.addPID.k1 * PI.P.y + PI.addPID.k2 * PI.Dzero.y) / (- PI.addPID.k3)");
    _der_inertia1_phi_141 = _PI_u_m_51;
    _inertia1_w_55 = _der_inertia1_phi_141;
    _spring_w_rel_66 = 0;
    _spring_tau_d_64 = _spring_d_61 * _spring_w_rel_66;
    _spring_tau_c_63 = - (- _spring_tau_68 + _spring_tau_d_64);
    ef |= jmi_solve_block_residual(jmi->dae_init_block_residuals[1]);
    _spring_lossPower_72 = _spring_tau_d_64 * _spring_w_rel_66;
    _inertia1_phi_54 = 0;
    _inertia2_phi_75 = - (- _spring_phi_rel_65 + (- _inertia1_phi_54));
    _der_spring_phi_rel_142 = _spring_w_rel_66;
    _spring_a_rel_67 = _der_spring_w_rel_139;
    _der_inertia2_phi_110 = - (- _der_spring_phi_rel_142 + (- _der_inertia1_phi_141));
    _inertia2_w_76 = _der_inertia2_phi_110;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(6) = jmi_turn_switch(_time - (_kinematicPTP_startTime_81), _sw(6), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(7) = jmi_turn_switch(_time - (_kinematicPTP_Ta1_94 + _kinematicPTP_startTime_81), _sw(7), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(8) = jmi_turn_switch(_time - (_kinematicPTP_Te_108 + _kinematicPTP_startTime_81), _sw(8), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(9) = jmi_turn_switch(_time - (_kinematicPTP_Ta2_103 + _kinematicPTP_startTime_81), _sw(9), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(10) = jmi_turn_switch(_time - (_kinematicPTP_Tv_107 + _kinematicPTP_startTime_81), _sw(10), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(8) = jmi_turn_switch(_time - (_kinematicPTP_Te_108 + _kinematicPTP_startTime_81), _sw(8), jmi->events_epsilon, JMI_REL_LT);
    }
    _kinematicPTP_sdd_87 = COND_EXP_EQ(_sw(6), JMI_TRUE, AD_WRAP_LITERAL(0), COND_EXP_EQ(_kinematicPTP_noWphase_106, JMI_TRUE, COND_EXP_EQ(_sw(7), JMI_TRUE, _kinematicPTP_sdd_max_93, COND_EXP_EQ(_sw(8), JMI_TRUE, - _kinematicPTP_sdd_max_93, AD_WRAP_LITERAL(0))), COND_EXP_EQ(_sw(9), JMI_TRUE, _kinematicPTP_sdd_max_93, COND_EXP_EQ(_sw(10), JMI_TRUE, AD_WRAP_LITERAL(0), COND_EXP_EQ(_sw(8), JMI_TRUE, - _kinematicPTP_sdd_max_93, AD_WRAP_LITERAL(0))))));
    _integrator_u_99 = _kinematicPTP_p_deltaq_1_85 * _kinematicPTP_sdd_87;
    _der_integrator_y_143 = _integrator_k_96 * _integrator_u_99;
    _PI_controlError_1 = _integrator_y_100 + (- _PI_u_m_51);
    _inertia1__der_phi_136 = _der_inertia1_phi_141;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(0) = jmi_turn_switch(_torque_tau_57 - (AD_WRAP_LITERAL(-12.0)), _sw(0), jmi->events_epsilon, JMI_REL_GEQ);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(1) = jmi_turn_switch(_torque_tau_57 - (AD_WRAP_LITERAL(12.0)), _sw(1), jmi->events_epsilon, JMI_REL_LEQ);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(0) = jmi_turn_switch(_torque_tau_57 - (AD_WRAP_LITERAL(-12.0)), _sw(0), jmi->events_epsilon, JMI_REL_GEQ);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(1) = jmi_turn_switch(_torque_tau_57 - (AD_WRAP_LITERAL(12.0)), _sw(1), jmi->events_epsilon, JMI_REL_LEQ);
    }
    if (LOG_EXP_OR(JMI_FALSE, LOG_EXP_AND(LOG_EXP_AND(JMI_TRUE, _sw(0)), _sw(1))) == JMI_FALSE) {
        JMI_DEF_STR_STAT(tmp_1, 182)
        JMI_INI_STR_STAT(tmp_1)
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%s", "LimPID: During initialization the limits have been switched off.\nAfter initialization, the output y (=");
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%-.*g", (int) 6, _torque_tau_57);
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%s", ") is outside of the limits of yMin (=");
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%s", "-12.0000");
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%s", ") and yMax (=");
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%s", "12.0000");
        snprintf(JMI_STR_END(tmp_1), JMI_STR_LEFT(tmp_1), "%s", ")");
        jmi_assert_failed(tmp_1, JMI_ASSERT_ERROR);
    }
    if (COND_EXP_GE(_PI_limiter_uMax_43, _PI_limiter_uMin_44, JMI_TRUE, JMI_FALSE) == JMI_FALSE) {
        JMI_DEF_STR_STAT(tmp_2, 90)
        JMI_INI_STR_STAT(tmp_2)
        snprintf(JMI_STR_END(tmp_2), JMI_STR_LEFT(tmp_2), "%s", "Limiter: Limits must be consistent. However, uMax (=");
        snprintf(JMI_STR_END(tmp_2), JMI_STR_LEFT(tmp_2), "%-.*g", (int) 6, _PI_limiter_uMax_43);
        snprintf(JMI_STR_END(tmp_2), JMI_STR_LEFT(tmp_2), "%s", ") < uMin (=");
        snprintf(JMI_STR_END(tmp_2), JMI_STR_LEFT(tmp_2), "%-.*g", (int) 6, _PI_limiter_uMin_44);
        snprintf(JMI_STR_END(tmp_2), JMI_STR_LEFT(tmp_2), "%s", ")");
        jmi_assert_failed(tmp_2, JMI_ASSERT_ERROR);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(4) = jmi_turn_switch(_PI_addSat_u2_40 - (_PI_limiter_uMin_44 - AD_WRAP_LITERAL(0.01) * jmi_abs(_PI_limiter_uMin_44)), _sw(4), jmi->events_epsilon, JMI_REL_GEQ);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(5) = jmi_turn_switch(_PI_addSat_u2_40 - (_PI_limiter_uMax_43 + AD_WRAP_LITERAL(0.01) * jmi_abs(_PI_limiter_uMax_43)), _sw(5), jmi->events_epsilon, JMI_REL_LEQ);
    }
    if (LOG_EXP_AND(_atInitial, JMI_TRUE)) {
        if (jmi->atInitial || jmi->atEvent) {
            _sw(4) = jmi_turn_switch(_PI_addSat_u2_40 - (_PI_limiter_uMin_44 - AD_WRAP_LITERAL(0.01) * jmi_abs(_PI_limiter_uMin_44)), _sw(4), jmi->events_epsilon, JMI_REL_GEQ);
        }
        if (jmi->atInitial || jmi->atEvent) {
            _sw(5) = jmi_turn_switch(_PI_addSat_u2_40 - (_PI_limiter_uMax_43 + AD_WRAP_LITERAL(0.01) * jmi_abs(_PI_limiter_uMax_43)), _sw(5), jmi->events_epsilon, JMI_REL_LEQ);
        }
        if (LOG_EXP_AND(_sw(4), _sw(5)) == JMI_FALSE) {
            JMI_DEF_STR_STAT(tmp_3, 201)
            JMI_INI_STR_STAT(tmp_3)
            snprintf(JMI_STR_END(tmp_3), JMI_STR_LEFT(tmp_3), "%s", "Limiter: During initialization the limits have been ignored.\nHowever, the result is that the input u is not within the required limits:\n  u = ");
            snprintf(JMI_STR_END(tmp_3), JMI_STR_LEFT(tmp_3), "%-.*g", (int) 6, _PI_addSat_u2_40);
            snprintf(JMI_STR_END(tmp_3), JMI_STR_LEFT(tmp_3), "%s", ", uMin = ");
            snprintf(JMI_STR_END(tmp_3), JMI_STR_LEFT(tmp_3), "%-.*g", (int) 6, _PI_limiter_uMin_44);
            snprintf(JMI_STR_END(tmp_3), JMI_STR_LEFT(tmp_3), "%s", ", uMax = ");
            snprintf(JMI_STR_END(tmp_3), JMI_STR_LEFT(tmp_3), "%-.*g", (int) 6, _PI_limiter_uMax_43);
            jmi_assert_failed(tmp_3, JMI_ASSERT_ERROR);
        }
    }

    return ef;
}


static int model_ode_initialize_dir_der(jmi_t* jmi) {
    int ef = 0;
    /* This function is not needed - no derivatives of the initialization system is exposed.*/
    return ef;
}

static int model_dae_F(jmi_t* jmi, jmi_real_t** res) {

    return 0;
}

static int model_dae_dir_dF(jmi_t* jmi, jmi_real_t** res, jmi_real_t** dF, jmi_real_t** dz) {

    return 0;
}

static int model_dae_R(jmi_t* jmi, jmi_real_t** res) {
    (*res)[0] = _torque_tau_57 - (AD_WRAP_LITERAL(-12.0));
    (*res)[1] = _torque_tau_57 - (AD_WRAP_LITERAL(12.0));
    (*res)[2] = _PI_addSat_u2_40 - (_PI_limiter_uMax_43);
    (*res)[3] = _PI_addSat_u2_40 - (_PI_limiter_uMin_44);
    (*res)[4] = _PI_addSat_u2_40 - (_PI_limiter_uMin_44 - AD_WRAP_LITERAL(0.01) * jmi_abs(_PI_limiter_uMin_44));
    (*res)[5] = _PI_addSat_u2_40 - (_PI_limiter_uMax_43 + AD_WRAP_LITERAL(0.01) * jmi_abs(_PI_limiter_uMax_43));
    (*res)[6] = _time - (_kinematicPTP_startTime_81);
    (*res)[7] = _time - (_kinematicPTP_Ta1_94 + _kinematicPTP_startTime_81);
    (*res)[8] = _time - (_kinematicPTP_Te_108 + _kinematicPTP_startTime_81);
    (*res)[9] = _time - (_kinematicPTP_Ta2_103 + _kinematicPTP_startTime_81);
    (*res)[10] = _time - (_kinematicPTP_Tv_107 + _kinematicPTP_startTime_81);

    return 0;
}

static int model_init_F0(jmi_t* jmi, jmi_real_t** res) {

    return 0;
}

static int model_init_F1(jmi_t* jmi, jmi_real_t** res) {
    (*res)[0] = 0.0 - _PI_controlError_1;
    (*res)[1] = 0.0 - _PI_P_u_22;
    (*res)[2] = 0.0 - _PI_P_y_23;
    (*res)[3] = 0.0 - _PI_I_u_27;
    (*res)[4] = _PI_I_y_start_26 - _PI_I_y_28;
    (*res)[5] = 0.0 - _PI_addPID_y_33;
    (*res)[6] = 0.0 - _PI_addI_u3_37;
    (*res)[7] = 0.0 - _PI_addSat_u2_40;
    (*res)[8] = 0.0 - _PI_addSat_y_41;
    (*res)[9] = 0.0 - _PI_u_m_51;
    (*res)[10] = 0.0 - _inertia1_w_55;
    (*res)[11] = 0.0 - _torque_tau_57;
    (*res)[12] = 0.0 - _spring_tau_c_63;
    (*res)[13] = 0.0 - _spring_tau_d_64;
    (*res)[14] = 0 - _spring_phi_rel_65;
    (*res)[15] = 0 - _spring_a_rel_67;
    (*res)[16] = 0.0 - _spring_tau_68;
    (*res)[17] = 0.0 - _spring_lossPower_72;
    (*res)[18] = 0.0 - _inertia2_phi_75;
    (*res)[19] = 0.0 - _inertia2_w_76;
    (*res)[20] = 0.0 - _inertia2_a_77;
    (*res)[21] = 0.0 - _kinematicPTP_sdd_87;
    (*res)[22] = 0.0 - _integrator_u_99;
    (*res)[23] = _integrator_y_start_98 - _integrator_y_100;
    (*res)[24] = 0.0 - _der_inertia1_w_109;
    (*res)[25] = 0.0 - _der_inertia2_phi_110;
    (*res)[26] = 0.0 - _der_inertia2_w_111;
    (*res)[27] = 0.0 - _inertia1__der_phi_136;
    (*res)[28] = 0.0 - _der_2_spring_phi_rel_137;
    (*res)[29] = 0.0 - _der_2_inertia2_phi_138;

    return 0;
}

static int model_init_Fp(jmi_t* jmi, jmi_real_t** res) {
    /* C_DAE_initial_dependent_parameter_residuals */
    return -1;
}

static int model_init_eval_parameters(jmi_t* jmi) {
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

    return 0;
}

static int model_init_R0(jmi_t* jmi, jmi_real_t** res) {
    (*res)[0] = _torque_tau_57 - (AD_WRAP_LITERAL(-12.0));
    (*res)[1] = _torque_tau_57 - (AD_WRAP_LITERAL(12.0));
    (*res)[2] = _PI_addSat_u2_40 - (_PI_limiter_uMax_43);
    (*res)[3] = _PI_addSat_u2_40 - (_PI_limiter_uMin_44);
    (*res)[4] = _PI_addSat_u2_40 - (_PI_limiter_uMin_44 - AD_WRAP_LITERAL(0.01) * jmi_abs(_PI_limiter_uMin_44));
    (*res)[5] = _PI_addSat_u2_40 - (_PI_limiter_uMax_43 + AD_WRAP_LITERAL(0.01) * jmi_abs(_PI_limiter_uMax_43));
    (*res)[6] = _time - (_kinematicPTP_startTime_81);
    (*res)[7] = _time - (_kinematicPTP_Ta1_94 + _kinematicPTP_startTime_81);
    (*res)[8] = _time - (_kinematicPTP_Te_108 + _kinematicPTP_startTime_81);
    (*res)[9] = _time - (_kinematicPTP_Ta2_103 + _kinematicPTP_startTime_81);
    (*res)[10] = _time - (_kinematicPTP_Tv_107 + _kinematicPTP_startTime_81);

    return 0;
}

static int model_init_delay(jmi_t* jmi) {

    return 0;
}

static int model_sample_delay(jmi_t* jmi) {

    return 0;
}

int jmi_new(jmi_t** jmi, jmi_callbacks_t* jmi_callbacks) {

    jmi_init(jmi, N_real_ci, N_real_cd,  N_real_pi,    N_real_pi_s,    N_real_pi_f,    N_real_pi_e,    N_real_pd,
             N_integer_ci, N_integer_cd, N_integer_pi, N_integer_pi_s, N_integer_pi_f, N_integer_pi_e, N_integer_pd,
             N_boolean_ci, N_boolean_cd, N_boolean_pi, N_boolean_pi_s, N_boolean_pi_f, N_boolean_pi_e, N_boolean_pd,
             N_string_ci,  N_string_cd,  N_string_pi,  N_string_pi_s,  N_string_pi_f,  N_string_pi_e,  N_string_pd,
             N_real_dx, N_real_x, N_real_u, N_real_w,
             N_real_d, N_integer_d, N_integer_u, N_boolean_d, N_boolean_u,
             N_string_d, N_string_u, N_outputs, (int (*))Output_vrefs,
             N_sw, N_sw_init, N_guards, N_guards_init,
             N_dae_blocks, N_dae_init_blocks,
             N_initial_relations, (int (*))DAE_initial_relations,
             N_relations, (int (*))DAE_relations,
             (jmi_real_t *) DAE_nominals,
             Scaling_method, N_ext_objs, jmi_callbacks);



    jmi_dae_init_add_equation_block(*jmi, dae_init_block_0, NULL, 1, 0, 2, JMI_CONTINUOUS_VARIABILITY, JMI_CONSTANT_VARIABILITY, JMI_KINSOL_SOLVER, 0, "1", -1);
    jmi_dae_init_add_equation_block(*jmi, dae_init_block_1, NULL, 1, 0, 0, JMI_PARAMETER_VARIABILITY, JMI_CONSTANT_VARIABILITY, JMI_LINEAR_SOLVER, 1, "2", -1);






    /* Initialize the DAE interface */
    jmi_dae_init(*jmi, *model_dae_F, N_eq_F, NULL, 0, NULL, NULL,
                 *model_dae_dir_dF,
                 CAD_dae_n_nz,(int (*))CAD_dae_nz_rows,(int (*))CAD_dae_nz_cols,
                 CAD_ODE_A_n_nz, (int (*))CAD_ODE_A_nz_rows, (int(*))CAD_ODE_A_nz_cols,
                 CAD_ODE_B_n_nz, (int (*))CAD_ODE_B_nz_rows, (int(*))CAD_ODE_B_nz_cols,
                 CAD_ODE_C_n_nz, (int (*))CAD_ODE_C_nz_rows, (int(*))CAD_ODE_C_nz_cols,
                 CAD_ODE_D_n_nz, (int (*))CAD_ODE_D_nz_rows, (int(*))CAD_ODE_D_nz_cols,
                 *model_dae_R, N_eq_R, NULL, 0, NULL, NULL,*model_ode_derivatives,
                 *model_ode_derivatives_dir_der,
                 *model_ode_outputs,*model_ode_initialize,*model_ode_guards,
                 *model_ode_guards_init,*model_ode_next_time_event);

    /* Initialize the Init interface */
    jmi_init_init(*jmi, *model_init_F0, N_eq_F0, NULL,
                  0, NULL, NULL,
                  *model_init_F1, N_eq_F1, NULL,
                  0, NULL, NULL,
                  *model_init_Fp, N_eq_Fp, NULL,
                  0, NULL, NULL,
                  *model_init_eval_parameters,
                  *model_init_R0, N_eq_R0, NULL,
                  0, NULL, NULL);
    
    /* Initialize the delay interface */
    jmi_init_delay_if(*jmi, N_delays, *model_init_delay, *model_sample_delay, N_delay_sw);

    return 0;
}

int jmi_terminate(jmi_t* jmi) {

    return 0;
}

int jmi_set_start_values(jmi_t* jmi) {
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
    __block_jacobian_check_112 = (JMI_FALSE);
    __block_jacobian_check_tol_113 = (1.0E-6);
    __block_solver_experimental_mode_114 = (0);
    __cs_rel_tol_115 = (1.0E-6);
    __cs_solver_116 = (0);
    __cs_step_size_117 = (0.001);
    __enforce_bounds_118 = (JMI_TRUE);
    __events_default_tol_119 = (1.0E-10);
    __events_tol_factor_120 = (1.0E-4);
    __iteration_variable_scaling_121 = (1);
    __log_level_122 = (3);
    __nle_solver_check_jac_cond_123 = (JMI_FALSE);
    __nle_solver_default_tol_124 = (1.0E-10);
    __nle_solver_max_iter_125 = (100);
    __nle_solver_min_tol_126 = (1.0E-12);
    __nle_solver_regularization_tolerance_127 = (-1.0);
    __nle_solver_step_limit_factor_128 = (10.0);
    __nle_solver_tol_factor_129 = (1.0E-4);
    __rescale_after_singular_jac_130 = (JMI_TRUE);
    __rescale_each_step_131 = (JMI_FALSE);
    __residual_equation_scaling_132 = (1);
    __runtime_log_to_file_133 = (JMI_FALSE);
    __use_Brent_in_1d_134 = (JMI_FALSE);
    __use_jacobian_equilibration_135 = (JMI_FALSE);
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
    model_init_eval_parameters(jmi);
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
    _inertia1__der_phi_136 = (0.0);
    _der_2_spring_phi_rel_137 = (0.0);
    _der_2_inertia2_phi_138 = (0.0);
    _der_spring_w_rel_139 = (0.0);
    _der_PI_I_y_140 = (0.0);
    _der_inertia1_phi_141 = (0.0);
    _der_spring_phi_rel_142 = (0.0);
    _der_integrator_y_143 = (0.0);
    _der_inertia1__der_phi_144 = (0.0);

    return 0;
}

const char *jmi_get_model_identifier() {
    return "PID_Controller";
}


/* FMI for co-simulation Functions*/

/* Inquire version numbers of header files */
DllExport const char* fmiGetTypesPlatform() {
    return fmi1_cs_get_types_platform();
}
DllExport const char* fmiGetVersion() {
    return fmi1_cs_get_version();
}

DllExport void fmiFreeSlaveInstance(fmiComponent c) {
    fmi1_cs_free_slave_instance(c);
}

/* Creation and destruction of model instances and setting debug status */
DllExport fmiComponent fmiInstantiateSlave(fmiString instanceName, fmiString GUID, fmiString fmuLocation, fmiString mimeType, 
                                   fmiReal timeout, fmiBoolean visible, fmiBoolean interactive, fmiCallbackFunctions functions, 
                                   fmiBoolean loggingOn) {
    return fmi1_cs_instantiate_slave(instanceName, GUID, fmuLocation, mimeType, timeout, visible, interactive, functions, loggingOn);
}


DllExport fmiStatus fmiTerminateSlave(fmiComponent c) {
    return fmi1_cs_terminate_slave(c);
}

DllExport fmiStatus fmiInitializeSlave(fmiComponent c, fmiReal tStart,
                                    fmiBoolean StopTimeDefined, fmiReal tStop){
    return fmi1_cs_initialize_slave(c,tStart,StopTimeDefined,tStop);
}

DllExport fmiStatus fmiSetDebugLogging(fmiComponent c, fmiBoolean loggingOn) {
    return fmi1_cs_set_debug_logging(c, loggingOn);
}

DllExport fmiStatus fmiDoStep(fmiComponent c,
			      fmiReal      currentCommunicationPoint,
			      fmiReal      communicationStepSize,
			      fmiBoolean   newStep) {
  return fmi1_cs_do_step(c, currentCommunicationPoint, communicationStepSize, newStep);
}

DllExport fmiStatus fmiCancelStep(fmiComponent c){
    return fmi1_cs_cancel_step(c);
}

DllExport fmiStatus fmiResetSlave(fmiComponent c) {
    return fmi1_cs_reset_slave(c);
}

DllExport fmiStatus fmiGetRealOutputDerivatives(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiInteger order[], fmiReal value[]){
    return fmi1_cs_get_real_output_derivatives(c, vr, nvr, order, value);
}

DllExport fmiStatus fmiSetRealInputDerivatives(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiInteger order[], const fmiReal value[]){
    return fmi1_cs_set_real_input_derivatives(c,vr,nvr,order,value);
}

DllExport fmiStatus fmiSetReal(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiReal value[]) {
    return fmi1_cs_set_real(c, vr, nvr, value);
}

DllExport fmiStatus fmiSetInteger(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiInteger value[]) {
    return fmi1_cs_set_integer(c, vr, nvr, value);
}

DllExport fmiStatus fmiSetBoolean(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiBoolean value[]) {
    return fmi1_cs_set_boolean(c, vr, nvr, value);
}

DllExport fmiStatus fmiSetString(fmiComponent c, const fmiValueReference vr[], size_t nvr, const fmiString  value[]) {
    return fmi1_cs_set_string(c, vr, nvr, value);
}

DllExport fmiStatus fmiGetReal(fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiReal value[]) {
    return fmi1_cs_get_real(c, vr, nvr, value);
}

DllExport fmiStatus fmiGetInteger(fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiInteger value[]) {
    return fmi1_cs_get_integer(c, vr, nvr, value);
}

DllExport fmiStatus fmiGetBoolean(fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiBoolean value[]) {
    return fmi1_cs_get_boolean(c, vr, nvr, value);
}

DllExport fmiStatus fmiGetString(fmiComponent c, const fmiValueReference vr[], size_t nvr, fmiString  value[]) {
    return fmi1_cs_get_string(c, vr, nvr, value);
}

DllExport fmiStatus fmiGetStatus(fmiComponent c, const fmiStatusKind s, fmiStatus* value){
    return fmi1_cs_get_status(c,s,value);
}

DllExport fmiStatus fmiGetRealStatus(fmiComponent c, const fmiStatusKind s, fmiReal* value){
    return fmi1_cs_get_real_status(c, s, value);
}

DllExport fmiStatus fmiGetIntegerStatus(fmiComponent c, const fmiStatusKind s, fmiInteger* value){
    return fmi1_cs_get_integer_status(c, s, value);
}

DllExport fmiStatus fmiGetBooleanStatus(fmiComponent c, const fmiStatusKind s, fmiBoolean* value){
    return fmi1_cs_get_boolean_status(c, s, value);
}

DllExport fmiStatus fmiGetStringStatus(fmiComponent c, const fmiStatusKind s, fmiString* value){
    return fmi1_cs_get_string_status(c,s,value);
}

/* NOTE IN THE FILE FMICSFUNCTIONS.H WHY? */
/*
DLLExport fmiStatus fmiSaveState(fmiComponent c, size_t index){
    return fmi_save_state(c,index);
}

DLLExport fmiStatus fmiRestoreState(fmiComponent c, size_t index){
    return fmi_restore_state(c,index);
}
*/
