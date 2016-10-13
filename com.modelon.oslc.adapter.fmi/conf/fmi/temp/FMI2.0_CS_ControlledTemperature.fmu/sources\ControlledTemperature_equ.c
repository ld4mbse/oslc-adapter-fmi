#include "ControlledTemperature_base.h"




static int dae_block_0(jmi_t* jmi, jmi_real_t* x, jmi_real_t* residual, int evaluation_mode) {
    /***** Block: 1 *****/
    jmi_real_t** res = &residual;
    int ef = 0;
    if (evaluation_mode == JMI_BLOCK_NOMINAL) {
    } else if (evaluation_mode == JMI_BLOCK_START) {
    } else if (evaluation_mode == JMI_BLOCK_MIN) {
    } else if (evaluation_mode == JMI_BLOCK_MAX) {
    } else if (evaluation_mode == JMI_BLOCK_VALUE_REFERENCE) {
        x[0] = 72;
    } else if (evaluation_mode == JMI_BLOCK_SOLVED_REAL_VALUE_REFERENCE) {
        x[0] = 68;
        x[1] = 67;
        x[2] = 73;
    } else if (evaluation_mode == JMI_BLOCK_SOLVED_NON_REAL_VALUE_REFERENCE) {
    } else if (evaluation_mode == JMI_BLOCK_DIRECTLY_IMPACTING_NON_REAL_VALUE_REFERENCE) {
    } else if (evaluation_mode == JMI_BLOCK_ACTIVE_SWITCH_INDEX) {
    } else if (evaluation_mode == JMI_BLOCK_DIRECTLY_ACTIVE_SWITCH_INDEX) {
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





void model_add_blocks(jmi_t** jmi) {
    jmi_dae_add_equation_block(*jmi, dae_block_0, NULL, 1, 3, 0, 0, 0, 0, JMI_CONTINUOUS_VARIABILITY, JMI_CONSTANT_VARIABILITY, JMI_LINEAR_SOLVER, 0, "1", -1);



}

int model_ode_derivatives(jmi_t* jmi) {
    int ef = 0;
    model_ode_guards(jmi);
    /********* Initialize reinits *******/
    /************* ODE section *********/
    _onOffController_u_43 = _heatCapacitor_T_9 + -273.15;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(3) = jmi_turn_switch_time(_time - (_ramp_startTime_41), _sw(3), JMI_ALMOST_EPS, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(4) = jmi_turn_switch_time(_time - (_ramp_startTime_41 + _ramp_duration_39), _sw(4), JMI_ALMOST_EPS, JMI_REL_LT);
    }
    _onOffController_reference_42 = _ramp_offset_40 + COND_EXP_EQ(_sw(3), JMI_TRUE, AD_WRAP_LITERAL(0), COND_EXP_EQ(_sw(4), JMI_TRUE, jmi_divide_equation(jmi, (_time - _ramp_startTime_41) * _ramp_height_38,_ramp_duration_39,"(time - ramp.startTime) * ramp.height / ramp.duration"), _ramp_height_38));
    if (jmi->atInitial || jmi->atEvent) {
        _sw(1) = jmi_turn_switch(_onOffController_u_43 - (_onOffController_reference_42 + jmi_divide_equation(jmi, _onOffController_bandwidth_19,2,"onOffController.bandwidth / 2")), _sw(1), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(2) = jmi_turn_switch(_onOffController_u_43 - (_onOffController_reference_42 - jmi_divide_equation(jmi, _onOffController_bandwidth_19,2,"onOffController.bandwidth / 2")), _sw(2), jmi->events_epsilon, JMI_REL_LT);
    }
    _logicalNot_u_46 = LOG_EXP_OR(LOG_EXP_AND(pre_logicalNot_u_46, _sw(1)), _sw(2));
    pre_logicalNot_u_46 = _logicalNot_u_46;
    _idealSwitch_control_29 = LOG_EXP_NOT(_logicalNot_u_46);
    pre_idealSwitch_control_29 = _idealSwitch_control_29;
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

int model_dae_R(jmi_t* jmi, jmi_real_t** res) {
    (*res)[0] = AD_WRAP_LITERAL(1) + _heatingResistor_alpha_14 * (_heatCapacitor_T_9 - _heatingResistor_T_ref_13) - (AD_WRAP_LITERAL(1.0E-15));
    (*res)[1] = _onOffController_u_43 - (_onOffController_reference_42 + jmi_divide_equation(jmi, _onOffController_bandwidth_19,2,"onOffController.bandwidth / 2"));
    (*res)[2] = _onOffController_u_43 - (_onOffController_reference_42 - jmi_divide_equation(jmi, _onOffController_bandwidth_19,2,"onOffController.bandwidth / 2"));

    return 0;
}
