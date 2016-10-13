#include "ControlledTemperature_base.h"
static const int N_real_ci = 7;
static const int N_real_cd = 0;
static const int N_real_pi = 27;
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
static const int N_boolean_pi = 12;
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

static const int N_time_sw = 2;
static const int N_state_sw = 3;
static const int N_sw = 2 + 3;
static const int N_delay_sw = 0;
static const int N_eq_F = 18;
static const int N_eq_R = 3;

static const int N_dae_blocks = 1;
static const int N_dae_init_blocks = 1;
static const int N_guards = 0;

static const int N_dynamic_state_sets = 0;

static const int N_eq_F0 = 18 + 3;
static const int N_eq_F1 = 16;
static const int N_eq_Fp = 0;
static const int N_eq_R0 = 3 + 0;
static const int N_sw_init = 0;
static const int N_guards_init = 0;

static const int N_delays = 0;
static const int N_spatialdists = 0;

static const int N_outputs = 1;

static const int Scaling_method = JMI_SCALING_NONE;

const char *C_GUID = "14ac906d8d18e8da4c3d119d0c9a8a4";

static const int Output_vrefs[1] = {62};


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

static const int N_relations = 3;
static const int DAE_relations[] = { JMI_REL_GEQ, JMI_REL_LT, JMI_REL_LT };

static const int N_nominals = 1;
static const jmi_real_t DAE_nominals[] = { 300.0 };

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
    "_nle_solver_max_residual_scaling_factor",
    "_nle_solver_min_residual_scaling_factor",
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
    "_use_newton_for_brent",
    NULL
};

const int fmi_runtime_options_map_vrefs[] = {
    536870961, 21, 268435498, 22, 268435499, 23, 536870962, 24, 25, 268435500,
    268435501, 536870963, 26, 268435502, 27, 28, 29, 30, 31, 32,
    536870964, 536870965, 268435503, 536870966, 536870967, 536870968, 536870969, 0
};

const int fmi_runtime_options_map_length = 27;






int model_ode_guards(jmi_t* jmi) {

    return 0;
}

static int model_ode_next_time_event(jmi_t* jmi, jmi_time_event_t* event) {
    jmi_time_event_t nextEvent = {0};
    jmi_real_t nSamp;
    if (SURELY_LT_ZERO(_time - (_ramp_startTime_41))) {
        jmi_min_time_event(&nextEvent, 1, 0, _ramp_startTime_41);
    }
    if (SURELY_LT_ZERO(_time - (_ramp_startTime_41 + _ramp_duration_39))) {
        jmi_min_time_event(&nextEvent, 1, 0, _ramp_startTime_41 + _ramp_duration_39);
    }
    *event = nextEvent;


    return 0;
}

static int model_ode_derivatives_dir_der(jmi_t* jmi) {
    int ef = 0;

    return ef;
}

static int model_ode_outputs(jmi_t* jmi) {
    int ef = 0;

    return ef;
}

int model_ode_guards_init(jmi_t* jmi) {

    return 0;
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
             N_sw, N_sw_init, N_time_sw,N_state_sw, N_guards, N_guards_init,
             N_dae_blocks, N_dae_init_blocks,
             N_initial_relations, (int (*))DAE_initial_relations,
             N_relations, (int (*))DAE_relations, N_dynamic_state_sets,
             (jmi_real_t *) DAE_nominals,
             Scaling_method, N_ext_objs, jmi_callbacks);



    model_add_blocks(jmi);
    
    model_init_add_blocks(jmi);

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
    jmi_init_delay_if(*jmi, N_delays, N_spatialdists, *model_init_delay, *model_sample_delay, N_delay_sw);

    return 0;
}

int jmi_destruct_external_objs(jmi_t* jmi) {

    return 0;
}

const char *jmi_get_model_identifier() {
    return "ControlledTemperature";
}
