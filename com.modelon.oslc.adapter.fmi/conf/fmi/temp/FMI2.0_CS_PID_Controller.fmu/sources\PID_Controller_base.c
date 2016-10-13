#include "PID_Controller_base.h"
static const int N_real_ci = 4;
static const int N_real_cd = 0;
static const int N_real_pi = 50;
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
static const int N_boolean_pi = 18;
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

static const int N_time_sw = 5;
static const int N_state_sw = 6;
static const int N_sw = 5 + 6;
static const int N_delay_sw = 0;
static const int N_eq_F = 33;
static const int N_eq_R = 6;

static const int N_dae_blocks = 0;
static const int N_dae_init_blocks = 2;
static const int N_guards = 0;

static const int N_dynamic_state_sets = 0;

static const int N_eq_F0 = 33 + 6;
static const int N_eq_F1 = 36;
static const int N_eq_Fp = 0;
static const int N_eq_R0 = 6 + 0;
static const int N_sw_init = 0;
static const int N_guards_init = 0;

static const int N_delays = 0;
static const int N_spatialdists = 0;

static const int N_outputs = 0;

static const int Scaling_method = JMI_SCALING_NONE;

const char *C_GUID = "c7c28fabee3f64e0c0f852a1a5f752d7";

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

static const int N_relations = 6;
static const int DAE_relations[] = { JMI_REL_GEQ, JMI_REL_LEQ, JMI_REL_GT, JMI_REL_LT, JMI_REL_GEQ, JMI_REL_LEQ };

static const int N_nominals = 6;
static const jmi_real_t DAE_nominals[] = { 1.0, 1.0, 1.0, 1.0E-4, 1.0, 1.0 };

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
    536871002, 39, 268435532, 40, 268435533, 41, 536871003, 42, 43, 268435534,
    268435535, 536871004, 44, 268435536, 45, 46, 47, 48, 49, 50,
    536871005, 536871006, 268435537, 536871007, 536871008, 536871009, 536871010, 0
};

const int fmi_runtime_options_map_length = 27;




static char* SimpleController_0_e[] = { "", "P", "PI", "PD", "PID" };
static char* InitPID_1_e[] = { "", "NoInit", "SteadyState", "InitialState", "InitialOutput", "DoNotUse_InitialIntegratorState" };
static char* Init_2_e[] = { "", "NoInit", "SteadyState", "InitialState", "InitialOutput" };
static char* StateSelect_3_e[] = { "", "never", "avoid", "default", "prefer", "always" };


int model_ode_guards(jmi_t* jmi) {

    return 0;
}

static int model_ode_next_time_event(jmi_t* jmi, jmi_time_event_t* event) {
    jmi_time_event_t nextEvent = {0};
    jmi_real_t nSamp;
    if (SURELY_LT_ZERO(_time - (_kinematicPTP_startTime_81))) {
        jmi_min_time_event(&nextEvent, 1, 0, _kinematicPTP_startTime_81);
    }
    if (SURELY_LT_ZERO(_time - (_kinematicPTP_Ta1_94 + _kinematicPTP_startTime_81))) {
        jmi_min_time_event(&nextEvent, 1, 0, _kinematicPTP_Ta1_94 + _kinematicPTP_startTime_81);
    }
    if (SURELY_LT_ZERO(_time - (_kinematicPTP_Te_108 + _kinematicPTP_startTime_81))) {
        jmi_min_time_event(&nextEvent, 1, 0, _kinematicPTP_Te_108 + _kinematicPTP_startTime_81);
    }
    if (SURELY_LT_ZERO(_time - (_kinematicPTP_Ta2_103 + _kinematicPTP_startTime_81))) {
        jmi_min_time_event(&nextEvent, 1, 0, _kinematicPTP_Ta2_103 + _kinematicPTP_startTime_81);
    }
    if (SURELY_LT_ZERO(_time - (_kinematicPTP_Tv_107 + _kinematicPTP_startTime_81))) {
        jmi_min_time_event(&nextEvent, 1, 0, _kinematicPTP_Tv_107 + _kinematicPTP_startTime_81);
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
    (*res)[27] = 0.0 - _inertia1__der_phi_112;
    (*res)[28] = 0.0 - _der_2_spring_phi_rel_113;
    (*res)[29] = 0.0 - _der_2_inertia2_phi_114;

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
    return "PID_Controller";
}
