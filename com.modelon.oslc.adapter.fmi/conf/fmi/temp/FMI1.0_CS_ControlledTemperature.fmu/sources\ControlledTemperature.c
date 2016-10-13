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

#define MODEL_IDENTIFIER ControlledTemperature



extern void dgemm_(char* TRANSA, char* TRANSB, int* M, int* N, int* K, double* ALPHA, double* A, int* LDA, double* B, int* LDB, double* BETA, double* C, int* LDC);

const char *C_GUID = "cf3dbbc4ed55a9fb3c99363aa5bee4ea";

static int model_ode_guards_init(jmi_t* jmi);
static int model_init_R0(jmi_t* jmi, jmi_real_t** res);
static int model_ode_initialize(jmi_t* jmi);

static const int N_real_ci = 7;
static const int N_real_cd = 0;
static const int N_real_pi = 25;
static const int N_real_pi_s = 1;
static const int N_real_pi_f = 0;
static const int N_real_pi_e = 0;
static const int N_real_pd = 8;

static const int N_integer_ci = 0 + 0;
static const int N_integer_cd = 0 + 0;
static const int N_integer_pi = 6 + 0;
static const int N_integer_pi_s = 0 + 0;
static const int N_integer_pi_f = 0 + 0;
static const int N_integer_pi_e = 0 + 0;
static const int N_integer_pd = 0 + 0;

static const int N_boolean_ci = 0;
static const int N_boolean_cd = 0;
static const int N_boolean_pi = 11;
static const int N_boolean_pi_s = 2;
static const int N_boolean_pi_f = 0;
static const int N_boolean_pi_e = 0;
static const int N_boolean_pd = 0;

static const int N_string_ci = 0;
static const int N_string_cd = 0;
static const int N_string_pi = 0;
static const int N_string_pi_s = 0;
static const int N_string_pi_f = 0;
static const int N_string_pi_e = 0;
static const int N_string_pd = 0;

static const int N_real_dx = 1;
static const int N_real_x = 1;
static const int N_real_u = 0;
static const int N_real_w = 15;

static const int N_real_d = 0;

static const int N_integer_d = 0 + 0;
static const int N_integer_u = 0 + 0;

static const int N_boolean_d = 2;
static const int N_boolean_u = 0;

static const int N_string_d = 0;
static const int N_string_u = 0;

static const int N_ext_objs = 0;

static const int N_sw = 5;
static const int N_delay_sw = 0;
static const int N_eq_F = 18;
static const int N_eq_R = 5;

static const int N_dae_blocks = 1;
static const int N_dae_init_blocks = 1;
static const int N_guards = 0;

static const int N_eq_F0 = 18 + 3;
static const int N_eq_F1 = 16;
static const int N_eq_Fp = 0;
static const int N_eq_R0 = 5 + 0;
static const int N_sw_init = 0;
static const int N_guards_init = 0;

static const int N_delays = 0;

static const int Scaling_method = JMI_SCALING_NONE;

#define sf(i) (jmi->variable_scaling_factors[i])

static const int N_outputs = 1;
static const int Output_vrefs[1] = {59};


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

static const int N_relations = 5;
static const int DAE_relations[] = { JMI_REL_GEQ, JMI_REL_LT, JMI_REL_LT, JMI_REL_LT, JMI_REL_LT };

static const int N_nominals = 1;
static const jmi_real_t DAE_nominals[] = { 300.0 };

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
#define __nle_solver_min_tol_68 ((*(jmi->z))[jmi->offs_real_pi+20])
#define __nle_solver_regularization_tolerance_69 ((*(jmi->z))[jmi->offs_real_pi+21])
#define __nle_solver_step_limit_factor_70 ((*(jmi->z))[jmi->offs_real_pi+22])
#define __nle_solver_tol_factor_71 ((*(jmi->z))[jmi->offs_real_pi+23])
#define _idealSwitch_T_35 ((*(jmi->z))[jmi->offs_real_pi+24])
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
#define __residual_equation_scaling_74 ((*(jmi->z))[jmi->offs_integer_pi+5])
#define _onOffController_pre_y_start_45 ((*(jmi->z))[jmi->offs_boolean_pi+0])
#define __block_jacobian_check_54 ((*(jmi->z))[jmi->offs_boolean_pi+1])
#define __enforce_bounds_60 ((*(jmi->z))[jmi->offs_boolean_pi+2])
#define __nle_solver_check_jac_cond_65 ((*(jmi->z))[jmi->offs_boolean_pi+3])
#define __rescale_after_singular_jac_72 ((*(jmi->z))[jmi->offs_boolean_pi+4])
#define __rescale_each_step_73 ((*(jmi->z))[jmi->offs_boolean_pi+5])
#define __runtime_log_to_file_75 ((*(jmi->z))[jmi->offs_boolean_pi+6])
#define __use_Brent_in_1d_76 ((*(jmi->z))[jmi->offs_boolean_pi+7])
#define __use_jacobian_equilibration_77 ((*(jmi->z))[jmi->offs_boolean_pi+8])
#define _heatingResistor_useHeatPort_18 ((*(jmi->z))[jmi->offs_boolean_pi+9])
#define _idealSwitch_useHeatPort_34 ((*(jmi->z))[jmi->offs_boolean_pi+10])
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
    536870959, 21, 268435496, 22, 268435497, 23, 536870960, 24, 25, 268435498,
    268435499, 536870961, 26, 268435500, 27, 28, 29, 30, 536870962, 536870963,
    268435501, 536870964, 536870965, 536870966, 0
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









static int dae_block_0(jmi_t* jmi, jmi_real_t* x, jmi_real_t* residual, int evaluation_mode) {
    /***** Block: 1 *****/
    jmi_real_t** res = &residual;
    int ef = 0;
    if (evaluation_mode == JMI_BLOCK_NOMINAL) {
    } else if (evaluation_mode == JMI_BLOCK_START) {
    } else if (evaluation_mode == JMI_BLOCK_MIN) {
    } else if (evaluation_mode == JMI_BLOCK_MAX) {
    } else if (evaluation_mode == JMI_BLOCK_VALUE_REFERENCE) {
        x[0] = 69;
    } else if (evaluation_mode == JMI_BLOCK_NON_REAL_VALUE_REFERENCE) {
    } else if (evaluation_mode == JMI_BLOCK_ACTIVE_SWITCH_INDEX) {
    } else if (evaluation_mode == JMI_BLOCK_EQUATION_NOMINAL) {
    } else if (evaluation_mode == JMI_BLOCK_INITIALIZE) {
        x[0] = _idealSwitch_s_30;
    } else if (evaluation_mode==JMI_BLOCK_EVALUATE_JACOBIAN) {
        jmi_real_t* Q1 = calloc(3, sizeof(jmi_real_t));
        jmi_real_t* Q2 = calloc(3, sizeof(jmi_real_t));
        jmi_real_t* Q3 = residual;
        int i;
        char trans = 'N';
        double alpha = -1;
        double beta = 1;
        int n1 = 3;
        int n2 = 1;
        Q1[0] = (- COND_EXP_EQ(_idealSwitch_control_29, JMI_TRUE, _idealSwitch_Goff_28, AD_WRAP_LITERAL(1)));
        for (i = 0; i < 3; i += 3) {
            Q1[i + 0] = (Q1[i + 0]) / (1.0);
            Q1[i + 1] = (Q1[i + 1] - ((- _heatingResistor_R_15)) * Q1[i + 0]) / (1.0);
            Q1[i + 2] = (Q1[i + 2] - (1.0) * Q1[i + 1]) / (1.0);
        }
        Q2[2] = 1.0;
        memset(Q3, 0, 1 * sizeof(jmi_real_t));
        Q3[0] = (- COND_EXP_EQ(_idealSwitch_control_29, JMI_TRUE, AD_WRAP_LITERAL(1), _idealSwitch_Ron_27));
        dgemm_(&trans, &trans, &n2, &n2, &n1, &alpha, Q2, &n2, Q1, &n1, &beta, Q3, &n2);
        free(Q1);
        free(Q2);
    } else if (evaluation_mode & JMI_BLOCK_EVALUATE || evaluation_mode & JMI_BLOCK_WRITE_BACK) {
        if ((evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) == 0) {
            _idealSwitch_s_30 = x[0];
        }
        _heatingResistor_i_17 = _idealSwitch_s_30 * COND_EXP_EQ(_idealSwitch_control_29, JMI_TRUE, _idealSwitch_Goff_28, AD_WRAP_LITERAL(1));
        _heatingResistor_v_16 = _heatingResistor_R_15 * _heatingResistor_i_17;
        _idealSwitch_v_33 = _constantVoltage_p_v_44 + (- _heatingResistor_v_16);
        if (evaluation_mode & JMI_BLOCK_EVALUATE) {
            (*res)[0] = _idealSwitch_s_30 * COND_EXP_EQ(_idealSwitch_control_29, JMI_TRUE, AD_WRAP_LITERAL(1), _idealSwitch_Ron_27) - (_idealSwitch_v_33);
        }
    }
    return ef;
}



static int dae_init_block_0(jmi_t* jmi, jmi_real_t* x, jmi_real_t* residual, int evaluation_mode) {
    /***** Init block: 1 *****/
    jmi_real_t** res = &residual;
    int ef = 0;
    if (evaluation_mode == JMI_BLOCK_NOMINAL) {
    } else if (evaluation_mode == JMI_BLOCK_START) {
    } else if (evaluation_mode == JMI_BLOCK_MIN) {
    } else if (evaluation_mode == JMI_BLOCK_MAX) {
    } else if (evaluation_mode == JMI_BLOCK_VALUE_REFERENCE) {
        x[0] = 69;
    } else if (evaluation_mode == JMI_BLOCK_NON_REAL_VALUE_REFERENCE) {
    } else if (evaluation_mode == JMI_BLOCK_ACTIVE_SWITCH_INDEX) {
    } else if (evaluation_mode == JMI_BLOCK_EQUATION_NOMINAL) {
    } else if (evaluation_mode == JMI_BLOCK_INITIALIZE) {
        x[0] = _idealSwitch_s_30;
    } else if (evaluation_mode==JMI_BLOCK_EVALUATE_JACOBIAN) {
        jmi_real_t* Q1 = calloc(3, sizeof(jmi_real_t));
        jmi_real_t* Q2 = calloc(3, sizeof(jmi_real_t));
        jmi_real_t* Q3 = residual;
        int i;
        char trans = 'N';
        double alpha = -1;
        double beta = 1;
        int n1 = 3;
        int n2 = 1;
        Q1[0] = (- COND_EXP_EQ(_idealSwitch_control_29, JMI_TRUE, _idealSwitch_Goff_28, AD_WRAP_LITERAL(1)));
        for (i = 0; i < 3; i += 3) {
            Q1[i + 0] = (Q1[i + 0]) / (1.0);
            Q1[i + 1] = (Q1[i + 1] - ((- _heatingResistor_R_15)) * Q1[i + 0]) / (1.0);
            Q1[i + 2] = (Q1[i + 2] - (1.0) * Q1[i + 1]) / (1.0);
        }
        Q2[2] = 1.0;
        memset(Q3, 0, 1 * sizeof(jmi_real_t));
        Q3[0] = (- COND_EXP_EQ(_idealSwitch_control_29, JMI_TRUE, AD_WRAP_LITERAL(1), _idealSwitch_Ron_27));
        dgemm_(&trans, &trans, &n2, &n2, &n1, &alpha, Q2, &n2, Q1, &n1, &beta, Q3, &n2);
        free(Q1);
        free(Q2);
    } else if (evaluation_mode & JMI_BLOCK_EVALUATE || evaluation_mode & JMI_BLOCK_WRITE_BACK) {
        if ((evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) == 0) {
            _idealSwitch_s_30 = x[0];
        }
        _heatingResistor_i_17 = _idealSwitch_s_30 * COND_EXP_EQ(_idealSwitch_control_29, JMI_TRUE, _idealSwitch_Goff_28, AD_WRAP_LITERAL(1));
        _heatingResistor_v_16 = _heatingResistor_R_15 * _heatingResistor_i_17;
        _idealSwitch_v_33 = _constantVoltage_p_v_44 + (- _heatingResistor_v_16);
        if (evaluation_mode & JMI_BLOCK_EVALUATE) {
            (*res)[0] = _idealSwitch_s_30 * COND_EXP_EQ(_idealSwitch_control_29, JMI_TRUE, AD_WRAP_LITERAL(1), _idealSwitch_Ron_27) - (_idealSwitch_v_33);
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
    _onOffController_u_43 = _heatCapacitor_T_9 + -273.15;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(1) = jmi_turn_switch(_time - (_ramp_startTime_41), _sw(1), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(2) = jmi_turn_switch(_time - (_ramp_startTime_41 + _ramp_duration_39), _sw(2), jmi->events_epsilon, JMI_REL_LT);
    }
    _onOffController_reference_42 = _ramp_offset_40 + COND_EXP_EQ(_sw(1), JMI_TRUE, AD_WRAP_LITERAL(0), COND_EXP_EQ(_sw(2), JMI_TRUE, jmi_divide_equation(jmi, (_time - _ramp_startTime_41) * _ramp_height_38,_ramp_duration_39,"(time - ramp.startTime) * ramp.height / ramp.duration"), _ramp_height_38));
    if (jmi->atInitial || jmi->atEvent) {
        _sw(3) = jmi_turn_switch(_onOffController_u_43 - (_onOffController_reference_42 + jmi_divide_equation(jmi, _onOffController_bandwidth_19,2,"onOffController.bandwidth / 2")), _sw(3), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(4) = jmi_turn_switch(_onOffController_u_43 - (_onOffController_reference_42 - jmi_divide_equation(jmi, _onOffController_bandwidth_19,2,"onOffController.bandwidth / 2")), _sw(4), jmi->events_epsilon, JMI_REL_LT);
    }
    _logicalNot_u_46 = LOG_EXP_OR(LOG_EXP_AND(pre_logicalNot_u_46, _sw(3)), _sw(4));
    _idealSwitch_control_29 = LOG_EXP_NOT(_logicalNot_u_46);
    _heatingResistor_R_15 = _heatingResistor_R_ref_12 * (1 + _heatingResistor_alpha_14 * (_heatCapacitor_T_9 - _heatingResistor_T_ref_13));
    ef |= jmi_solve_block_residual(jmi->dae_block_residuals[0]);
    _heatingResistor_LossPower_20 = _heatingResistor_v_16 * _heatingResistor_i_17;
    _thermalConductor_dT_26 = _heatCapacitor_T_9 + (- _fixedTemperature_port_T_22);
    _thermalConductor_Q_flow_25 = _thermalConductor_G_24 * _thermalConductor_dT_26;
    _heatCapacitor_port_Q_flow_11 = _heatingResistor_LossPower_20 + (- _thermalConductor_Q_flow_25);
    _der_heatCapacitor_T_53 = jmi_divide_equation(jmi, _heatCapacitor_port_Q_flow_11,_heatCapacitor_C_8,"heatCapacitor.port.Q_flow / heatCapacitor.C");
/************ Real outputs *********/
    _TRes_2 = _heatCapacitor_T_9;
/****Integer and boolean outputs ***/
/**** Other variables ***/
    _ground_p_i_3 = - _heatingResistor_i_17 + _heatingResistor_i_17;
    _heatCapacitor_der_T_10 = _der_heatCapacitor_T_53;
    _idealSwitch_LossPower_36 = _idealSwitch_v_33 * _heatingResistor_i_17;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(0) = jmi_turn_switch(AD_WRAP_LITERAL(1) + _heatingResistor_alpha_14 * (_heatCapacitor_T_9 - _heatingResistor_T_ref_13) - (AD_WRAP_LITERAL(1.0E-15)), _sw(0), jmi->events_epsilon, JMI_REL_GEQ);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(0) = jmi_turn_switch(AD_WRAP_LITERAL(1) + _heatingResistor_alpha_14 * (_heatCapacitor_T_9 - _heatingResistor_T_ref_13) - (AD_WRAP_LITERAL(1.0E-15)), _sw(0), jmi->events_epsilon, JMI_REL_GEQ);
    }
    if (_sw(0) == JMI_FALSE) {
        jmi_assert_failed("Temperature outside scope of model!", JMI_ASSERT_ERROR);
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
    _heatCapacitor_T_9 = _TAmb_0;
    _heatingResistor_R_15 = _heatingResistor_R_ref_12 * (1 + _heatingResistor_alpha_14 * (_heatCapacitor_T_9 - _heatingResistor_T_ref_13));
    _onOffController_u_43 = _heatCapacitor_T_9 + -273.15;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(1) = jmi_turn_switch(_time - (_ramp_startTime_41), _sw(1), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(2) = jmi_turn_switch(_time - (_ramp_startTime_41 + _ramp_duration_39), _sw(2), jmi->events_epsilon, JMI_REL_LT);
    }
    _onOffController_reference_42 = _ramp_offset_40 + COND_EXP_EQ(_sw(1), JMI_TRUE, AD_WRAP_LITERAL(0), COND_EXP_EQ(_sw(2), JMI_TRUE, jmi_divide_equation(jmi, (_time - _ramp_startTime_41) * _ramp_height_38,_ramp_duration_39,"(time - ramp.startTime) * ramp.height / ramp.duration"), _ramp_height_38));
    pre_logicalNot_u_46 = _onOffController_pre_y_start_45;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(3) = jmi_turn_switch(_onOffController_u_43 - (_onOffController_reference_42 + jmi_divide_equation(jmi, _onOffController_bandwidth_19,2,"onOffController.bandwidth / 2")), _sw(3), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(4) = jmi_turn_switch(_onOffController_u_43 - (_onOffController_reference_42 - jmi_divide_equation(jmi, _onOffController_bandwidth_19,2,"onOffController.bandwidth / 2")), _sw(4), jmi->events_epsilon, JMI_REL_LT);
    }
    _logicalNot_u_46 = LOG_EXP_OR(LOG_EXP_AND(pre_logicalNot_u_46, _sw(3)), _sw(4));
    _idealSwitch_control_29 = LOG_EXP_NOT(_logicalNot_u_46);
    ef |= jmi_solve_block_residual(jmi->dae_init_block_residuals[0]);
    _heatingResistor_LossPower_20 = _heatingResistor_v_16 * _heatingResistor_i_17;
    _thermalConductor_dT_26 = _heatCapacitor_T_9 + (- _fixedTemperature_port_T_22);
    _thermalConductor_Q_flow_25 = _thermalConductor_G_24 * _thermalConductor_dT_26;
    _heatCapacitor_port_Q_flow_11 = _heatingResistor_LossPower_20 + (- _thermalConductor_Q_flow_25);
    _der_heatCapacitor_T_53 = jmi_divide_equation(jmi, _heatCapacitor_port_Q_flow_11,_heatCapacitor_C_8,"heatCapacitor.port.Q_flow / heatCapacitor.C");
    _heatCapacitor_der_T_10 = _der_heatCapacitor_T_53;
    _idealSwitch_LossPower_36 = _idealSwitch_v_33 * _heatingResistor_i_17;
    _ground_p_i_3 = - _heatingResistor_i_17 + _heatingResistor_i_17;
    _TRes_2 = _heatCapacitor_T_9;
    pre_idealSwitch_control_29 = JMI_FALSE;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(0) = jmi_turn_switch(AD_WRAP_LITERAL(1) + _heatingResistor_alpha_14 * (_heatCapacitor_T_9 - _heatingResistor_T_ref_13) - (AD_WRAP_LITERAL(1.0E-15)), _sw(0), jmi->events_epsilon, JMI_REL_GEQ);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(0) = jmi_turn_switch(AD_WRAP_LITERAL(1) + _heatingResistor_alpha_14 * (_heatCapacitor_T_9 - _heatingResistor_T_ref_13) - (AD_WRAP_LITERAL(1.0E-15)), _sw(0), jmi->events_epsilon, JMI_REL_GEQ);
    }
    if (_sw(0) == JMI_FALSE) {
        jmi_assert_failed("Temperature outside scope of model!", JMI_ASSERT_ERROR);
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
    (*res)[0] = AD_WRAP_LITERAL(1) + _heatingResistor_alpha_14 * (_heatCapacitor_T_9 - _heatingResistor_T_ref_13) - (AD_WRAP_LITERAL(1.0E-15));
    (*res)[1] = _time - (_ramp_startTime_41);
    (*res)[2] = _time - (_ramp_startTime_41 + _ramp_duration_39);
    (*res)[3] = _onOffController_u_43 - (_onOffController_reference_42 + jmi_divide_equation(jmi, _onOffController_bandwidth_19,2,"onOffController.bandwidth / 2"));
    (*res)[4] = _onOffController_u_43 - (_onOffController_reference_42 - jmi_divide_equation(jmi, _onOffController_bandwidth_19,2,"onOffController.bandwidth / 2"));

    return 0;
}

static int model_init_F0(jmi_t* jmi, jmi_real_t** res) {

    return 0;
}

static int model_init_F1(jmi_t* jmi, jmi_real_t** res) {
    (*res)[0] = 288.15 - _TRes_2;
    (*res)[1] = 0.0 - _ground_p_i_3;
    (*res)[2] = 0 - _heatCapacitor_der_T_10;
    (*res)[3] = 0.0 - _heatCapacitor_port_Q_flow_11;
    (*res)[4] = 0.0 - _heatingResistor_R_15;
    (*res)[5] = 0.0 - _heatingResistor_v_16;
    (*res)[6] = 0.0 - _heatingResistor_i_17;
    (*res)[7] = 0.0 - _heatingResistor_LossPower_20;
    (*res)[8] = 0.0 - _thermalConductor_Q_flow_25;
    (*res)[9] = 0.0 - _thermalConductor_dT_26;
    (*res)[10] = 0.0 - _idealSwitch_s_30;
    (*res)[11] = 0.0 - _idealSwitch_v_33;
    (*res)[12] = 0.0 - _idealSwitch_LossPower_36;
    (*res)[13] = 0.0 - _onOffController_reference_42;
    (*res)[14] = 0.0 - _onOffController_u_43;

    return 0;
}

static int model_init_Fp(jmi_t* jmi, jmi_real_t** res) {
    /* C_DAE_initial_dependent_parameter_residuals */
    return -1;
}

static int model_init_eval_parameters(jmi_t* jmi) {
    _heatingResistor_T_5 = (_heatingResistor_T_ref_13);
    _fixedTemperature_T_6 = (_TAmb_0);
    _onOffController_bandwidth_19 = (_TDif_1);
    _constantVoltage_v_21 = (_constantVoltage_V_4);
    _fixedTemperature_port_T_22 = (_fixedTemperature_T_6);
    _constantVoltage_p_v_44 = (_constantVoltage_v_21);
    _thermalConductor_port_b_T_51 = (_fixedTemperature_port_T_22);
    _idealSwitch_p_v_52 = (_constantVoltage_p_v_44);

    return 0;
}

static int model_init_R0(jmi_t* jmi, jmi_real_t** res) {
    (*res)[0] = AD_WRAP_LITERAL(1) + _heatingResistor_alpha_14 * (_heatCapacitor_T_9 - _heatingResistor_T_ref_13) - (AD_WRAP_LITERAL(1.0E-15));
    (*res)[1] = _time - (_ramp_startTime_41);
    (*res)[2] = _time - (_ramp_startTime_41 + _ramp_duration_39);
    (*res)[3] = _onOffController_u_43 - (_onOffController_reference_42 + jmi_divide_equation(jmi, _onOffController_bandwidth_19,2,"onOffController.bandwidth / 2"));
    (*res)[4] = _onOffController_u_43 - (_onOffController_reference_42 - jmi_divide_equation(jmi, _onOffController_bandwidth_19,2,"onOffController.bandwidth / 2"));

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

    jmi_dae_add_equation_block(*jmi, dae_block_0, NULL, 1, 0, 0, JMI_CONTINUOUS_VARIABILITY, JMI_CONSTANT_VARIABILITY, JMI_LINEAR_SOLVER, 0, "1", -1);


    jmi_dae_init_add_equation_block(*jmi, dae_init_block_0, NULL, 1, 0, 0, JMI_CONTINUOUS_VARIABILITY, JMI_CONSTANT_VARIABILITY, JMI_LINEAR_SOLVER, 0, "1", -1);






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
    __nle_solver_min_tol_68 = (1.0E-12);
    __nle_solver_regularization_tolerance_69 = (-1.0);
    __nle_solver_step_limit_factor_70 = (10.0);
    __nle_solver_tol_factor_71 = (1.0E-4);
    __rescale_after_singular_jac_72 = (JMI_TRUE);
    __rescale_each_step_73 = (JMI_FALSE);
    __residual_equation_scaling_74 = (1);
    __runtime_log_to_file_75 = (JMI_FALSE);
    __use_Brent_in_1d_76 = (JMI_FALSE);
    __use_jacobian_equilibration_77 = (JMI_FALSE);
    _heatingResistor_useHeatPort_18 = (JMI_TRUE);
    _idealSwitch_useHeatPort_34 = (JMI_FALSE);
    _idealSwitch_T_35 = (293.15);
    model_init_eval_parameters(jmi);
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

    return 0;
}

const char *jmi_get_model_identifier() {
    return "ControlledTemperature";
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
