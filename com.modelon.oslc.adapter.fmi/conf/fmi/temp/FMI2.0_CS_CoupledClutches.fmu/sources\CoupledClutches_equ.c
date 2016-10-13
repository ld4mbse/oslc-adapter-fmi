#include "CoupledClutches_base.h"
static char* StateSelect_0_e[] = { "", "never", "avoid", "default", "prefer", "always" };




static int dae_block_0(jmi_t* jmi, jmi_real_t* x, jmi_real_t* residual, int evaluation_mode) {
    /***** Block: 1 *****/
    jmi_real_t** res = &residual;
    int ef = 0;
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_7, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_8, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_9, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_10, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_11, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_12, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_13, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_14, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_15, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_16, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_17, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_18, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_19, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_20, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_21, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_22, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_23, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_24, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_25, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_26, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_27, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_28, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_29, 1, 1)
    JMI_ARR(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_30, 1, 1)
    if (evaluation_mode == JMI_BLOCK_NOMINAL) {
    } else if (evaluation_mode == JMI_BLOCK_START) {
    } else if (evaluation_mode == JMI_BLOCK_MIN) {
    } else if (evaluation_mode == JMI_BLOCK_MAX) {
    } else if (evaluation_mode == JMI_BLOCK_VALUE_REFERENCE) {
        x[0] = 137;
        x[1] = 163;
        x[2] = 148;
        x[3] = 159;
    } else if (evaluation_mode == JMI_BLOCK_SOLVED_REAL_VALUE_REFERENCE) {
        x[0] = 168;
        x[1] = 115;
        x[2] = 173;
        x[3] = 113;
        x[4] = 171;
        x[5] = 111;
        x[6] = 169;
        x[7] = 170;
        x[8] = 172;
        x[9] = 174;
        x[10] = 117;
        x[11] = 156;
        x[12] = 167;
        x[13] = 145;
        x[14] = 165;
        x[15] = 134;
    } else if (evaluation_mode == JMI_BLOCK_SOLVED_NON_REAL_VALUE_REFERENCE) {
        x[0] = 536871092;
        x[1] = 536871093;
        x[2] = 268435632;
        x[3] = 536871096;
        x[4] = 536871097;
        x[5] = 268435633;
        x[6] = 536871100;
        x[7] = 536871101;
        x[8] = 268435634;
        x[9] = 536871102;
        x[10] = 536871098;
        x[11] = 536871094;
    } else if (evaluation_mode == JMI_BLOCK_DIRECTLY_IMPACTING_NON_REAL_VALUE_REFERENCE) {
        x[0] = 536871102;
        x[1] = 536871100;
        x[2] = 536871101;
        x[3] = 536871098;
        x[4] = 536871096;
        x[5] = 536871097;
        x[6] = 536871094;
        x[7] = 536871092;
        x[8] = 536871093;
    } else if (evaluation_mode == JMI_BLOCK_ACTIVE_SWITCH_INDEX) {
        x[0] = jmi->offs_sw + 1;
        x[1] = jmi->offs_sw + 2;
        x[2] = jmi->offs_sw + 5;
        x[3] = jmi->offs_sw + 6;
        x[4] = jmi->offs_sw + 10;
        x[5] = jmi->offs_sw + 11;
        x[6] = jmi->offs_sw + 14;
        x[7] = jmi->offs_sw + 15;
        x[8] = jmi->offs_sw + 19;
        x[9] = jmi->offs_sw + 20;
        x[10] = jmi->offs_sw + 23;
        x[11] = jmi->offs_sw + 24;
    } else if (evaluation_mode == JMI_BLOCK_DIRECTLY_ACTIVE_SWITCH_INDEX) {
    } else if (evaluation_mode == JMI_BLOCK_EQUATION_NOMINAL) {
    } else if (evaluation_mode == JMI_BLOCK_INITIALIZE) {
        x[0] = _clutch1_sa_29;
        x[1] = _der_J1_w_158;
        x[2] = _clutch2_sa_75;
        x[3] = _clutch3_sa_112;
    } else if (evaluation_mode==JMI_BLOCK_EVALUATE_JACOBIAN) {
        jmi_real_t* Q1 = calloc(64, sizeof(jmi_real_t));
        jmi_real_t* Q2 = calloc(64, sizeof(jmi_real_t));
        jmi_real_t* Q3 = residual;
        int i;
        char trans = 'N';
        double alpha = -1;
        double beta = 1;
        int n1 = 16;
        int n2 = 4;
        Q1[5] = - COND_EXP_EQ(_clutch1_locked_32, JMI_TRUE, AD_WRAP_LITERAL(0), AD_WRAP_LITERAL(1.0));
        Q1[15] = - COND_EXP_EQ(_clutch1_locked_32, JMI_TRUE, AD_WRAP_LITERAL(1.0), AD_WRAP_LITERAL(0.0));
        Q1[16] = 1.0;
        Q1[35] = - COND_EXP_EQ(_clutch2_locked_78, JMI_TRUE, AD_WRAP_LITERAL(0), AD_WRAP_LITERAL(1.0));
        Q1[45] = - COND_EXP_EQ(_clutch2_locked_78, JMI_TRUE, AD_WRAP_LITERAL(1.0), AD_WRAP_LITERAL(0.0));
        Q1[49] = - COND_EXP_EQ(_clutch3_locked_115, JMI_TRUE, AD_WRAP_LITERAL(0), AD_WRAP_LITERAL(1.0));
        Q1[59] = - COND_EXP_EQ(_clutch3_locked_115, JMI_TRUE, AD_WRAP_LITERAL(1.0), AD_WRAP_LITERAL(0.0));
        for (i = 0; i < 64; i += 16) {
            Q1[i + 0] = (Q1[i + 0]) / (-1.0);
            Q1[i + 1] = (Q1[i + 1]) / (1.0);
            Q1[i + 2] = (Q1[i + 2] - (1.0) * Q1[i + 1]) / (-1.0);
            Q1[i + 3] = (Q1[i + 3]) / (1.0);
            Q1[i + 4] = (Q1[i + 4] - (1.0) * Q1[i + 3]) / (-1.0);
            Q1[i + 5] = (Q1[i + 5]) / (1.0);
            Q1[i + 6] = (Q1[i + 6] - (1.0) * Q1[i + 5]) / (-1.0);
            Q1[i + 7] = (Q1[i + 7] - (1.0) * Q1[i + 0] - (1.0) * Q1[i + 6]) / (-1.0);
            Q1[i + 8] = (Q1[i + 8] - (1.0) * Q1[i + 4] - (1.0) * Q1[i + 7]) / (-1.0);
            Q1[i + 9] = (Q1[i + 9] - (1.0) * Q1[i + 2] - (1.0) * Q1[i + 8]) / (-1.0);
            Q1[i + 10] = (Q1[i + 10] - (-1.0) * Q1[i + 9]) / (1.0);
            Q1[i + 11] = (Q1[i + 11]) / (1.0);
            Q1[i + 12] = (Q1[i + 12] - (-1.0) * Q1[i + 8]) / (1.0);
            Q1[i + 13] = (Q1[i + 13]) / (1.0);
            Q1[i + 14] = (Q1[i + 14] - (-1.0) * Q1[i + 7]) / (1.0);
            Q1[i + 15] = (Q1[i + 15]) / (1.0);
        }
        Q2[40] = _J4_J_127;
        Q2[44] = 1.0;
        Q2[45] = -1.0;
        Q2[49] = _J3_J_89;
        Q2[53] = 1.0;
        Q2[54] = -1.0;
        Q2[58] = _J2_J_52;
        Q2[62] = 1.0;
        Q2[63] = -1.0;
        memset(Q3, 0, 16 * sizeof(jmi_real_t));
        Q3[7] = _J1_J_3;
        dgemm_(&trans, &trans, &n2, &n2, &n1, &alpha, Q2, &n2, Q1, &n1, &beta, Q3, &n2);
        free(Q1);
        free(Q2);
    } else if (evaluation_mode & JMI_BLOCK_EVALUATE || evaluation_mode & JMI_BLOCK_WRITE_BACK) {
        if ((evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) == 0) {
            _clutch1_sa_29 = x[0];
            _der_J1_w_158 = x[1];
            _clutch2_sa_75 = x[2];
            _clutch3_sa_112 = x[3];
        }
        if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(1) = jmi_turn_switch(_clutch1_sa_29 - (_clutch1_tau0_max_27), _sw(1), jmi->events_epsilon, JMI_REL_GT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(2) = jmi_turn_switch(_clutch1_sa_29 - (_clutch1_tau0_26), _sw(2), jmi->events_epsilon, JMI_REL_GT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(3) = jmi_turn_switch(_der_clutch1_phi_rel_170 - (_clutch1_w_small_25), _sw(3), jmi->events_epsilon, JMI_REL_GT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(4) = jmi_turn_switch(_der_clutch1_phi_rel_170 - (0), _sw(4), jmi->events_epsilon, JMI_REL_GT);
            }
            _clutch1_startForward_30 = LOG_EXP_OR(LOG_EXP_OR(LOG_EXP_AND(COND_EXP_EQ(pre_clutch1_mode_38, 0, JMI_TRUE, JMI_FALSE), LOG_EXP_OR(_sw(1), LOG_EXP_AND(pre_clutch1_startForward_30, _sw(2)))), LOG_EXP_AND(COND_EXP_EQ(pre_clutch1_mode_38, -1, JMI_TRUE, JMI_FALSE), _sw(3))), LOG_EXP_AND(_atInitial, _sw(4)));
        }
        if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(5) = jmi_turn_switch(_clutch1_sa_29 - (- _clutch1_tau0_max_27), _sw(5), jmi->events_epsilon, JMI_REL_LT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(6) = jmi_turn_switch(_clutch1_sa_29 - (- _clutch1_tau0_26), _sw(6), jmi->events_epsilon, JMI_REL_LT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(7) = jmi_turn_switch(_der_clutch1_phi_rel_170 - (- _clutch1_w_small_25), _sw(7), jmi->events_epsilon, JMI_REL_LT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(8) = jmi_turn_switch(_der_clutch1_phi_rel_170 - (0), _sw(8), jmi->events_epsilon, JMI_REL_LT);
            }
            _clutch1_startBackward_31 = LOG_EXP_OR(LOG_EXP_OR(LOG_EXP_AND(COND_EXP_EQ(pre_clutch1_mode_38, 0, JMI_TRUE, JMI_FALSE), LOG_EXP_OR(_sw(5), LOG_EXP_AND(pre_clutch1_startBackward_31, _sw(6)))), LOG_EXP_AND(COND_EXP_EQ(pre_clutch1_mode_38, 1, JMI_TRUE, JMI_FALSE), _sw(7))), LOG_EXP_AND(_atInitial, _sw(8)));
        }
        if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(4) = jmi_turn_switch(_der_clutch1_phi_rel_170 - (AD_WRAP_LITERAL(0)), _sw(4), jmi->events_epsilon, JMI_REL_GT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(8) = jmi_turn_switch(_der_clutch1_phi_rel_170 - (AD_WRAP_LITERAL(0)), _sw(8), jmi->events_epsilon, JMI_REL_LT);
            }
            _clutch1_mode_38 = COND_EXP_EQ(_clutch1_free_28, JMI_TRUE, AD_WRAP_LITERAL(2), COND_EXP_EQ(LOG_EXP_AND(LOG_EXP_OR(LOG_EXP_OR(COND_EXP_EQ(pre_clutch1_mode_38, AD_WRAP_LITERAL(1), JMI_TRUE, JMI_FALSE), COND_EXP_EQ(pre_clutch1_mode_38, AD_WRAP_LITERAL(2), JMI_TRUE, JMI_FALSE)), _clutch1_startForward_30), _sw(4)), JMI_TRUE, AD_WRAP_LITERAL(1), COND_EXP_EQ(LOG_EXP_AND(LOG_EXP_OR(LOG_EXP_OR(COND_EXP_EQ(pre_clutch1_mode_38, AD_WRAP_LITERAL(-1), JMI_TRUE, JMI_FALSE), COND_EXP_EQ(pre_clutch1_mode_38, AD_WRAP_LITERAL(2), JMI_TRUE, JMI_FALSE)), _clutch1_startBackward_31), _sw(8)), JMI_TRUE, AD_WRAP_LITERAL(-1), AD_WRAP_LITERAL(0))));
        }
        _der_2_J1_phi_163 = _der_J1_w_158;
        if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(10) = jmi_turn_switch(_clutch2_sa_75 - (_clutch2_tau0_max_73), _sw(10), jmi->events_epsilon, JMI_REL_GT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(11) = jmi_turn_switch(_clutch2_sa_75 - (_clutch2_tau0_72), _sw(11), jmi->events_epsilon, JMI_REL_GT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(12) = jmi_turn_switch(_der_clutch2_phi_rel_172 - (_clutch2_w_small_71), _sw(12), jmi->events_epsilon, JMI_REL_GT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(13) = jmi_turn_switch(_der_clutch2_phi_rel_172 - (0), _sw(13), jmi->events_epsilon, JMI_REL_GT);
            }
            _clutch2_startForward_76 = LOG_EXP_OR(LOG_EXP_OR(LOG_EXP_AND(COND_EXP_EQ(pre_clutch2_mode_84, 0, JMI_TRUE, JMI_FALSE), LOG_EXP_OR(_sw(10), LOG_EXP_AND(pre_clutch2_startForward_76, _sw(11)))), LOG_EXP_AND(COND_EXP_EQ(pre_clutch2_mode_84, -1, JMI_TRUE, JMI_FALSE), _sw(12))), LOG_EXP_AND(_atInitial, _sw(13)));
        }
        if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(14) = jmi_turn_switch(_clutch2_sa_75 - (- _clutch2_tau0_max_73), _sw(14), jmi->events_epsilon, JMI_REL_LT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(15) = jmi_turn_switch(_clutch2_sa_75 - (- _clutch2_tau0_72), _sw(15), jmi->events_epsilon, JMI_REL_LT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(16) = jmi_turn_switch(_der_clutch2_phi_rel_172 - (- _clutch2_w_small_71), _sw(16), jmi->events_epsilon, JMI_REL_LT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(17) = jmi_turn_switch(_der_clutch2_phi_rel_172 - (0), _sw(17), jmi->events_epsilon, JMI_REL_LT);
            }
            _clutch2_startBackward_77 = LOG_EXP_OR(LOG_EXP_OR(LOG_EXP_AND(COND_EXP_EQ(pre_clutch2_mode_84, 0, JMI_TRUE, JMI_FALSE), LOG_EXP_OR(_sw(14), LOG_EXP_AND(pre_clutch2_startBackward_77, _sw(15)))), LOG_EXP_AND(COND_EXP_EQ(pre_clutch2_mode_84, 1, JMI_TRUE, JMI_FALSE), _sw(16))), LOG_EXP_AND(_atInitial, _sw(17)));
        }
        if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(13) = jmi_turn_switch(_der_clutch2_phi_rel_172 - (AD_WRAP_LITERAL(0)), _sw(13), jmi->events_epsilon, JMI_REL_GT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(17) = jmi_turn_switch(_der_clutch2_phi_rel_172 - (AD_WRAP_LITERAL(0)), _sw(17), jmi->events_epsilon, JMI_REL_LT);
            }
            _clutch2_mode_84 = COND_EXP_EQ(_clutch2_free_74, JMI_TRUE, AD_WRAP_LITERAL(2), COND_EXP_EQ(LOG_EXP_AND(LOG_EXP_OR(LOG_EXP_OR(COND_EXP_EQ(pre_clutch2_mode_84, AD_WRAP_LITERAL(1), JMI_TRUE, JMI_FALSE), COND_EXP_EQ(pre_clutch2_mode_84, AD_WRAP_LITERAL(2), JMI_TRUE, JMI_FALSE)), _clutch2_startForward_76), _sw(13)), JMI_TRUE, AD_WRAP_LITERAL(1), COND_EXP_EQ(LOG_EXP_AND(LOG_EXP_OR(LOG_EXP_OR(COND_EXP_EQ(pre_clutch2_mode_84, AD_WRAP_LITERAL(-1), JMI_TRUE, JMI_FALSE), COND_EXP_EQ(pre_clutch2_mode_84, AD_WRAP_LITERAL(2), JMI_TRUE, JMI_FALSE)), _clutch2_startBackward_77), _sw(17)), JMI_TRUE, AD_WRAP_LITERAL(-1), AD_WRAP_LITERAL(0))));
        }
        if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(19) = jmi_turn_switch(_clutch3_sa_112 - (_clutch3_tau0_max_110), _sw(19), jmi->events_epsilon, JMI_REL_GT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(20) = jmi_turn_switch(_clutch3_sa_112 - (_clutch3_tau0_109), _sw(20), jmi->events_epsilon, JMI_REL_GT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(21) = jmi_turn_switch(_der_clutch3_phi_rel_174 - (_clutch3_w_small_108), _sw(21), jmi->events_epsilon, JMI_REL_GT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(22) = jmi_turn_switch(_der_clutch3_phi_rel_174 - (0), _sw(22), jmi->events_epsilon, JMI_REL_GT);
            }
            _clutch3_startForward_113 = LOG_EXP_OR(LOG_EXP_OR(LOG_EXP_AND(COND_EXP_EQ(pre_clutch3_mode_121, 0, JMI_TRUE, JMI_FALSE), LOG_EXP_OR(_sw(19), LOG_EXP_AND(pre_clutch3_startForward_113, _sw(20)))), LOG_EXP_AND(COND_EXP_EQ(pre_clutch3_mode_121, -1, JMI_TRUE, JMI_FALSE), _sw(21))), LOG_EXP_AND(_atInitial, _sw(22)));
        }
        if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(23) = jmi_turn_switch(_clutch3_sa_112 - (- _clutch3_tau0_max_110), _sw(23), jmi->events_epsilon, JMI_REL_LT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(24) = jmi_turn_switch(_clutch3_sa_112 - (- _clutch3_tau0_109), _sw(24), jmi->events_epsilon, JMI_REL_LT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(25) = jmi_turn_switch(_der_clutch3_phi_rel_174 - (- _clutch3_w_small_108), _sw(25), jmi->events_epsilon, JMI_REL_LT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(26) = jmi_turn_switch(_der_clutch3_phi_rel_174 - (0), _sw(26), jmi->events_epsilon, JMI_REL_LT);
            }
            _clutch3_startBackward_114 = LOG_EXP_OR(LOG_EXP_OR(LOG_EXP_AND(COND_EXP_EQ(pre_clutch3_mode_121, 0, JMI_TRUE, JMI_FALSE), LOG_EXP_OR(_sw(23), LOG_EXP_AND(pre_clutch3_startBackward_114, _sw(24)))), LOG_EXP_AND(COND_EXP_EQ(pre_clutch3_mode_121, 1, JMI_TRUE, JMI_FALSE), _sw(25))), LOG_EXP_AND(_atInitial, _sw(26)));
        }
        if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(22) = jmi_turn_switch(_der_clutch3_phi_rel_174 - (AD_WRAP_LITERAL(0)), _sw(22), jmi->events_epsilon, JMI_REL_GT);
            }
            if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
                _sw(26) = jmi_turn_switch(_der_clutch3_phi_rel_174 - (AD_WRAP_LITERAL(0)), _sw(26), jmi->events_epsilon, JMI_REL_LT);
            }
            _clutch3_mode_121 = COND_EXP_EQ(_clutch3_free_111, JMI_TRUE, AD_WRAP_LITERAL(2), COND_EXP_EQ(LOG_EXP_AND(LOG_EXP_OR(LOG_EXP_OR(COND_EXP_EQ(pre_clutch3_mode_121, AD_WRAP_LITERAL(1), JMI_TRUE, JMI_FALSE), COND_EXP_EQ(pre_clutch3_mode_121, AD_WRAP_LITERAL(2), JMI_TRUE, JMI_FALSE)), _clutch3_startForward_113), _sw(22)), JMI_TRUE, AD_WRAP_LITERAL(1), COND_EXP_EQ(LOG_EXP_AND(LOG_EXP_OR(LOG_EXP_OR(COND_EXP_EQ(pre_clutch3_mode_121, AD_WRAP_LITERAL(-1), JMI_TRUE, JMI_FALSE), COND_EXP_EQ(pre_clutch3_mode_121, AD_WRAP_LITERAL(2), JMI_TRUE, JMI_FALSE)), _clutch3_startBackward_114), _sw(26)), JMI_TRUE, AD_WRAP_LITERAL(-1), AD_WRAP_LITERAL(0))));
        }
        if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
            _clutch3_locked_115 = LOG_EXP_AND(LOG_EXP_NOT(_clutch3_free_111), LOG_EXP_NOT(LOG_EXP_OR(LOG_EXP_OR(LOG_EXP_OR(COND_EXP_EQ(pre_clutch3_mode_121, 1, JMI_TRUE, JMI_FALSE), _clutch3_startForward_113), COND_EXP_EQ(pre_clutch3_mode_121, -1, JMI_TRUE, JMI_FALSE)), _clutch3_startBackward_114)));
        }
        _der_clutch3_w_rel_175 = COND_EXP_EQ(_clutch3_locked_115, JMI_TRUE, AD_WRAP_LITERAL(0), COND_EXP_EQ(_clutch3_free_111, JMI_TRUE, _clutch3_sa_112, COND_EXP_EQ(_clutch3_startForward_113, JMI_TRUE, _clutch3_sa_112 - _clutch3_tau0_max_110, COND_EXP_EQ(_clutch3_startBackward_114, JMI_TRUE, _clutch3_sa_112 + _clutch3_tau0_max_110, COND_EXP_EQ(COND_EXP_EQ(pre_clutch3_mode_121, AD_WRAP_LITERAL(1), JMI_TRUE, JMI_FALSE), JMI_TRUE, _clutch3_sa_112 - _clutch3_tau0_max_110, _clutch3_sa_112 + _clutch3_tau0_max_110)))));
        _der_2_clutch3_phi_rel_168 = _der_clutch3_w_rel_175;
        if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
            _clutch2_locked_78 = LOG_EXP_AND(LOG_EXP_NOT(_clutch2_free_74), LOG_EXP_NOT(LOG_EXP_OR(LOG_EXP_OR(LOG_EXP_OR(COND_EXP_EQ(pre_clutch2_mode_84, 1, JMI_TRUE, JMI_FALSE), _clutch2_startForward_76), COND_EXP_EQ(pre_clutch2_mode_84, -1, JMI_TRUE, JMI_FALSE)), _clutch2_startBackward_77)));
        }
        _der_clutch2_w_rel_173 = COND_EXP_EQ(_clutch2_locked_78, JMI_TRUE, AD_WRAP_LITERAL(0), COND_EXP_EQ(_clutch2_free_74, JMI_TRUE, _clutch2_sa_75, COND_EXP_EQ(_clutch2_startForward_76, JMI_TRUE, _clutch2_sa_75 - _clutch2_tau0_max_73, COND_EXP_EQ(_clutch2_startBackward_77, JMI_TRUE, _clutch2_sa_75 + _clutch2_tau0_max_73, COND_EXP_EQ(COND_EXP_EQ(pre_clutch2_mode_84, AD_WRAP_LITERAL(1), JMI_TRUE, JMI_FALSE), JMI_TRUE, _clutch2_sa_75 - _clutch2_tau0_max_73, _clutch2_sa_75 + _clutch2_tau0_max_73)))));
        _der_2_clutch2_phi_rel_166 = _der_clutch2_w_rel_173;
        if (evaluation_mode & JMI_BLOCK_EVALUATE_NON_REALS) {
            _clutch1_locked_32 = LOG_EXP_AND(LOG_EXP_NOT(_clutch1_free_28), LOG_EXP_NOT(LOG_EXP_OR(LOG_EXP_OR(LOG_EXP_OR(COND_EXP_EQ(pre_clutch1_mode_38, 1, JMI_TRUE, JMI_FALSE), _clutch1_startForward_30), COND_EXP_EQ(pre_clutch1_mode_38, -1, JMI_TRUE, JMI_FALSE)), _clutch1_startBackward_31)));
        }
        _der_clutch1_w_rel_171 = COND_EXP_EQ(_clutch1_locked_32, JMI_TRUE, AD_WRAP_LITERAL(0), COND_EXP_EQ(_clutch1_free_28, JMI_TRUE, _clutch1_sa_29, COND_EXP_EQ(_clutch1_startForward_30, JMI_TRUE, _clutch1_sa_29 - _clutch1_tau0_max_27, COND_EXP_EQ(_clutch1_startBackward_31, JMI_TRUE, _clutch1_sa_29 + _clutch1_tau0_max_27, COND_EXP_EQ(COND_EXP_EQ(pre_clutch1_mode_38, AD_WRAP_LITERAL(1), JMI_TRUE, JMI_FALSE), JMI_TRUE, _clutch1_sa_29 - _clutch1_tau0_max_27, _clutch1_sa_29 + _clutch1_tau0_max_27)))));
        _der_2_clutch1_phi_rel_164 = _der_clutch1_w_rel_171;
        _der_2_J2_phi_165 = _der_2_clutch1_phi_rel_164 + _der_2_J1_phi_163;
        _der_2_J3_phi_167 = _der_2_clutch2_phi_rel_166 + _der_2_J2_phi_165;
        _der_2_J4_phi_169 = _der_2_clutch3_phi_rel_168 + _der_2_J3_phi_167;
        _der_J4_w_177 = _der_2_J4_phi_169;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_7, 1, 1, 1)
        jmi_array_ref_1(tmp_7, 1) = _clutch3_mue_pos_1_1_94;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_8, 1, 1, 1)
        jmi_array_ref_1(tmp_8, 1) = _clutch3_mue_pos_1_2_95;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_9, 1, 1, 1)
        jmi_array_ref_1(tmp_9, 1) = _clutch3_mue_pos_1_1_94;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_10, 1, 1, 1)
        jmi_array_ref_1(tmp_10, 1) = _clutch3_mue_pos_1_2_95;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_11, 1, 1, 1)
        jmi_array_ref_1(tmp_11, 1) = _clutch3_mue_pos_1_1_94;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_12, 1, 1, 1)
        jmi_array_ref_1(tmp_12, 1) = _clutch3_mue_pos_1_2_95;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_13, 1, 1, 1)
        jmi_array_ref_1(tmp_13, 1) = _clutch3_mue_pos_1_1_94;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_14, 1, 1, 1)
        jmi_array_ref_1(tmp_14, 1) = _clutch3_mue_pos_1_2_95;
        _clutch3_tau_105 = COND_EXP_EQ(_clutch3_locked_115, JMI_TRUE, _clutch3_sa_112, COND_EXP_EQ(_clutch3_free_111, JMI_TRUE, AD_WRAP_LITERAL(0), _clutch3_cgeo_97 * _clutch3_fn_100 * COND_EXP_EQ(_clutch3_startForward_113, JMI_TRUE, func_Modelica_Math_Vectors_interpolate_exp0(tmp_7, tmp_8, _der_clutch3_phi_rel_174, AD_WRAP_LITERAL(1)), COND_EXP_EQ(_clutch3_startBackward_114, JMI_TRUE, - func_Modelica_Math_Vectors_interpolate_exp0(tmp_9, tmp_10, _der_clutch3_phi_rel_174, AD_WRAP_LITERAL(1)), COND_EXP_EQ(COND_EXP_EQ(pre_clutch3_mode_121, AD_WRAP_LITERAL(1), JMI_TRUE, JMI_FALSE), JMI_TRUE, func_Modelica_Math_Vectors_interpolate_exp0(tmp_11, tmp_12, _der_clutch3_phi_rel_174, AD_WRAP_LITERAL(1)), - func_Modelica_Math_Vectors_interpolate_exp0(tmp_13, tmp_14, - _der_clutch3_phi_rel_174, AD_WRAP_LITERAL(1)))))));
        _der_J3_w_162 = _der_2_J3_phi_167;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_15, 1, 1, 1)
        jmi_array_ref_1(tmp_15, 1) = _clutch2_mue_pos_1_1_57;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_16, 1, 1, 1)
        jmi_array_ref_1(tmp_16, 1) = _clutch2_mue_pos_1_2_58;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_17, 1, 1, 1)
        jmi_array_ref_1(tmp_17, 1) = _clutch2_mue_pos_1_1_57;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_18, 1, 1, 1)
        jmi_array_ref_1(tmp_18, 1) = _clutch2_mue_pos_1_2_58;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_19, 1, 1, 1)
        jmi_array_ref_1(tmp_19, 1) = _clutch2_mue_pos_1_1_57;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_20, 1, 1, 1)
        jmi_array_ref_1(tmp_20, 1) = _clutch2_mue_pos_1_2_58;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_21, 1, 1, 1)
        jmi_array_ref_1(tmp_21, 1) = _clutch2_mue_pos_1_1_57;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_22, 1, 1, 1)
        jmi_array_ref_1(tmp_22, 1) = _clutch2_mue_pos_1_2_58;
        _clutch2_tau_68 = COND_EXP_EQ(_clutch2_locked_78, JMI_TRUE, _clutch2_sa_75, COND_EXP_EQ(_clutch2_free_74, JMI_TRUE, AD_WRAP_LITERAL(0), _clutch2_cgeo_60 * _clutch2_fn_63 * COND_EXP_EQ(_clutch2_startForward_76, JMI_TRUE, func_Modelica_Math_Vectors_interpolate_exp0(tmp_15, tmp_16, _der_clutch2_phi_rel_172, AD_WRAP_LITERAL(1)), COND_EXP_EQ(_clutch2_startBackward_77, JMI_TRUE, - func_Modelica_Math_Vectors_interpolate_exp0(tmp_17, tmp_18, _der_clutch2_phi_rel_172, AD_WRAP_LITERAL(1)), COND_EXP_EQ(COND_EXP_EQ(pre_clutch2_mode_84, AD_WRAP_LITERAL(1), JMI_TRUE, JMI_FALSE), JMI_TRUE, func_Modelica_Math_Vectors_interpolate_exp0(tmp_19, tmp_20, _der_clutch2_phi_rel_172, AD_WRAP_LITERAL(1)), - func_Modelica_Math_Vectors_interpolate_exp0(tmp_21, tmp_22, - _der_clutch2_phi_rel_172, AD_WRAP_LITERAL(1)))))));
        _der_J2_w_160 = _der_2_J2_phi_165;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_23, 1, 1, 1)
        jmi_array_ref_1(tmp_23, 1) = _clutch1_mue_pos_1_1_11;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_24, 1, 1, 1)
        jmi_array_ref_1(tmp_24, 1) = _clutch1_mue_pos_1_2_12;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_25, 1, 1, 1)
        jmi_array_ref_1(tmp_25, 1) = _clutch1_mue_pos_1_1_11;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_26, 1, 1, 1)
        jmi_array_ref_1(tmp_26, 1) = _clutch1_mue_pos_1_2_12;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_27, 1, 1, 1)
        jmi_array_ref_1(tmp_27, 1) = _clutch1_mue_pos_1_1_11;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_28, 1, 1, 1)
        jmi_array_ref_1(tmp_28, 1) = _clutch1_mue_pos_1_2_12;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_29, 1, 1, 1)
        jmi_array_ref_1(tmp_29, 1) = _clutch1_mue_pos_1_1_11;
        JMI_ARRAY_INIT_1(STATREAL, jmi_ad_var_t, jmi_array_t, tmp_30, 1, 1, 1)
        jmi_array_ref_1(tmp_30, 1) = _clutch1_mue_pos_1_2_12;
        _clutch1_tau_22 = COND_EXP_EQ(_clutch1_locked_32, JMI_TRUE, _clutch1_sa_29, COND_EXP_EQ(_clutch1_free_28, JMI_TRUE, AD_WRAP_LITERAL(0), _clutch1_cgeo_14 * _clutch1_fn_17 * COND_EXP_EQ(_clutch1_startForward_30, JMI_TRUE, func_Modelica_Math_Vectors_interpolate_exp0(tmp_23, tmp_24, _der_clutch1_phi_rel_170, AD_WRAP_LITERAL(1)), COND_EXP_EQ(_clutch1_startBackward_31, JMI_TRUE, - func_Modelica_Math_Vectors_interpolate_exp0(tmp_25, tmp_26, _der_clutch1_phi_rel_170, AD_WRAP_LITERAL(1)), COND_EXP_EQ(COND_EXP_EQ(pre_clutch1_mode_38, AD_WRAP_LITERAL(1), JMI_TRUE, JMI_FALSE), JMI_TRUE, func_Modelica_Math_Vectors_interpolate_exp0(tmp_27, tmp_28, _der_clutch1_phi_rel_170, AD_WRAP_LITERAL(1)), - func_Modelica_Math_Vectors_interpolate_exp0(tmp_29, tmp_30, - _der_clutch1_phi_rel_170, AD_WRAP_LITERAL(1)))))));
        if (evaluation_mode & JMI_BLOCK_EVALUATE) {
            (*res)[0] = - _clutch3_tau_105 - (_J4_J_127 * _der_J4_w_177);
            (*res)[1] = - _clutch2_tau_68 + _clutch3_tau_105 - (_J3_J_89 * _der_J3_w_162);
            (*res)[2] = - _clutch1_tau_22 + _clutch2_tau_68 - (_J2_J_52 * _der_J2_w_160);
            (*res)[3] = _torque_tau_8 + _clutch1_tau_22 - (_J1_J_3 * _der_J1_w_158);
        }
    }
    return ef;
}





void model_add_blocks(jmi_t** jmi) {
    jmi_dae_add_equation_block(*jmi, dae_block_0, NULL, 4, 16, 12, 9, 12, 0, JMI_DISCRETE_VARIABILITY, JMI_CONSTANT_VARIABILITY, JMI_LINEAR_SOLVER, 0, "1", -1);



}

int model_ode_derivatives(jmi_t* jmi) {
    int ef = 0;
    model_ode_guards(jmi);
    /********* Initialize reinits *******/
    /************* ODE section *********/
    _der_clutch1_phi_rel_170 = _clutch1_w_rel_20;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(29) = jmi_turn_switch_time(_time - (_sin2_startTime_136), _sw(29), JMI_ALMOST_EPS, JMI_REL_LT);
    }
    _clutch1_f_normalized_18 = _sin2_offset_135 + COND_EXP_EQ(_sw(29), JMI_TRUE, AD_WRAP_LITERAL(0), _sin2_amplitude_132 * sin(AD_WRAP_LITERAL(6.283185307179586) * _sin2_freqHz_16 * (_time - _sin2_startTime_136) + _sin2_phase_134));
    _clutch1_fn_17 = _clutch1_fn_max_15 * _clutch1_f_normalized_18;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(0) = jmi_turn_switch(_clutch1_fn_17 - (0), _sw(0), jmi->events_epsilon, JMI_REL_LEQ);
    }
    _clutch1_free_28 = _sw(0);
    pre_clutch1_free_28 = _clutch1_free_28;
    _clutch1_tau0_26 = _clutch1_mue0_51 * _clutch1_cgeo_14 * _clutch1_fn_17;
    _clutch1_tau0_max_27 = _clutch1_peak_13 * _clutch1_tau0_26;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(28) = jmi_turn_switch_time(_time - (_step1_startTime_10), _sw(28), JMI_ALMOST_EPS, JMI_REL_LT);
    }
    _clutch2_f_normalized_64 = _step1_offset_50 + COND_EXP_EQ(_sw(28), JMI_TRUE, AD_WRAP_LITERAL(0), _step1_height_49);
    _clutch2_fn_63 = _clutch2_fn_max_61 * _clutch2_f_normalized_64;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(9) = jmi_turn_switch(_clutch2_fn_63 - (0), _sw(9), jmi->events_epsilon, JMI_REL_LEQ);
    }
    _clutch2_free_74 = _sw(9);
    pre_clutch2_free_74 = _clutch2_free_74;
    _der_clutch2_phi_rel_172 = _clutch2_w_rel_66;
    _clutch2_tau0_72 = _clutch2_mue0_62 * _clutch2_cgeo_60 * _clutch2_fn_63;
    _clutch2_tau0_max_73 = _clutch2_peak_59 * _clutch2_tau0_72;
    _clutch3_f_normalized_101 = _u_138;
    _clutch3_fn_100 = _clutch3_fn_max_98 * _clutch3_f_normalized_101;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(18) = jmi_turn_switch(_clutch3_fn_100 - (0), _sw(18), jmi->events_epsilon, JMI_REL_LEQ);
    }
    _clutch3_free_111 = _sw(18);
    pre_clutch3_free_111 = _clutch3_free_111;
    _der_clutch3_phi_rel_174 = _clutch3_w_rel_103;
    _clutch3_tau0_109 = _clutch3_mue0_99 * _clutch3_cgeo_97 * _clutch3_fn_100;
    _clutch3_tau0_max_110 = _clutch3_peak_96 * _clutch3_tau0_109;
    if (jmi->atInitial || jmi->atEvent) {
        _sw(27) = jmi_turn_switch_time(_time - (_sin1_startTime_47), _sw(27), JMI_ALMOST_EPS, JMI_REL_LT);
    }
    _torque_tau_8 = _sin1_offset_46 + COND_EXP_EQ(_sw(27), JMI_TRUE, AD_WRAP_LITERAL(0), _sin1_amplitude_43 * sin(AD_WRAP_LITERAL(6.283185307179586) * _sin1_freqHz_44 * (_time - _sin1_startTime_47) + _sin1_phase_45));
    if (jmi->atInitial || jmi->atEvent) {
        _sw(3) = jmi_turn_switch(_der_clutch1_phi_rel_170 - (_clutch1_w_small_25), _sw(3), jmi->events_epsilon, JMI_REL_GT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(4) = jmi_turn_switch(_der_clutch1_phi_rel_170 - (0), _sw(4), jmi->events_epsilon, JMI_REL_GT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(7) = jmi_turn_switch(_der_clutch1_phi_rel_170 - (- _clutch1_w_small_25), _sw(7), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(8) = jmi_turn_switch(_der_clutch1_phi_rel_170 - (0), _sw(8), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(12) = jmi_turn_switch(_der_clutch2_phi_rel_172 - (_clutch2_w_small_71), _sw(12), jmi->events_epsilon, JMI_REL_GT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(13) = jmi_turn_switch(_der_clutch2_phi_rel_172 - (0), _sw(13), jmi->events_epsilon, JMI_REL_GT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(16) = jmi_turn_switch(_der_clutch2_phi_rel_172 - (- _clutch2_w_small_71), _sw(16), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(17) = jmi_turn_switch(_der_clutch2_phi_rel_172 - (0), _sw(17), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(21) = jmi_turn_switch(_der_clutch3_phi_rel_174 - (_clutch3_w_small_108), _sw(21), jmi->events_epsilon, JMI_REL_GT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(22) = jmi_turn_switch(_der_clutch3_phi_rel_174 - (0), _sw(22), jmi->events_epsilon, JMI_REL_GT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(25) = jmi_turn_switch(_der_clutch3_phi_rel_174 - (- _clutch3_w_small_108), _sw(25), jmi->events_epsilon, JMI_REL_LT);
    }
    if (jmi->atInitial || jmi->atEvent) {
        _sw(26) = jmi_turn_switch(_der_clutch3_phi_rel_174 - (0), _sw(26), jmi->events_epsilon, JMI_REL_LT);
    }
    ef |= jmi_solve_block_residual(jmi->dae_block_residuals[0]);
    _der_J4_phi_176 = _J4_w_130;
    /************ Real outputs *********/
    /****Integer and boolean outputs ***/
    /**** Other variables ***/
    _J3_phi_91 = - _clutch3_phi_rel_102 + _J4_phi_129;
    _J2_phi_54 = - _clutch2_phi_rel_65 + _J3_phi_91;
    _J1_phi_5 = - _clutch1_phi_rel_19 + _J2_phi_54;
    _der_J3_phi_161 = - _der_clutch3_phi_rel_174 + _der_J4_phi_176;
    _der_J2_phi_159 = - _der_clutch2_phi_rel_172 + _der_J3_phi_161;
    _der_J1_phi_157 = - _der_clutch1_phi_rel_170 + _der_J2_phi_159;
    _J1_w_6 = _der_J1_phi_157;
    _J1_a_7 = _der_J1_w_158;
    _clutch1_a_rel_21 = _der_clutch1_w_rel_171;
    _clutch1_lossPower_42 = _clutch1_tau_22 * _der_clutch1_phi_rel_170;
    _J2_w_55 = _der_J2_phi_159;
    _J2_a_56 = _der_J2_w_160;
    _clutch2_a_rel_67 = _der_clutch2_w_rel_173;
    _clutch2_lossPower_88 = _clutch2_tau_68 * _der_clutch2_phi_rel_172;
    _J3_w_92 = _der_J3_phi_161;
    _J3_a_93 = _der_J3_w_162;
    _clutch3_a_rel_104 = _der_clutch3_w_rel_175;
    _clutch3_lossPower_125 = _clutch3_tau_105 * _der_clutch3_phi_rel_174;
    _J4_a_131 = _der_J4_w_177;
    /********* Write back reinits *******/

    return ef;
}

int model_dae_R(jmi_t* jmi, jmi_real_t** res) {
    (*res)[0] = _clutch1_fn_17 - (0);
    (*res)[1] = _clutch1_sa_29 - (_clutch1_tau0_max_27);
    (*res)[2] = _clutch1_sa_29 - (_clutch1_tau0_26);
    (*res)[3] = _der_clutch1_phi_rel_170 - (_clutch1_w_small_25);
    (*res)[4] = _der_clutch1_phi_rel_170 - (0);
    (*res)[5] = _clutch1_sa_29 - (- _clutch1_tau0_max_27);
    (*res)[6] = _clutch1_sa_29 - (- _clutch1_tau0_26);
    (*res)[7] = _der_clutch1_phi_rel_170 - (- _clutch1_w_small_25);
    (*res)[8] = _der_clutch1_phi_rel_170 - (0);
    (*res)[9] = _clutch2_fn_63 - (0);
    (*res)[10] = _clutch2_sa_75 - (_clutch2_tau0_max_73);
    (*res)[11] = _clutch2_sa_75 - (_clutch2_tau0_72);
    (*res)[12] = _der_clutch2_phi_rel_172 - (_clutch2_w_small_71);
    (*res)[13] = _der_clutch2_phi_rel_172 - (0);
    (*res)[14] = _clutch2_sa_75 - (- _clutch2_tau0_max_73);
    (*res)[15] = _clutch2_sa_75 - (- _clutch2_tau0_72);
    (*res)[16] = _der_clutch2_phi_rel_172 - (- _clutch2_w_small_71);
    (*res)[17] = _der_clutch2_phi_rel_172 - (0);
    (*res)[18] = _clutch3_fn_100 - (0);
    (*res)[19] = _clutch3_sa_112 - (_clutch3_tau0_max_110);
    (*res)[20] = _clutch3_sa_112 - (_clutch3_tau0_109);
    (*res)[21] = _der_clutch3_phi_rel_174 - (_clutch3_w_small_108);
    (*res)[22] = _der_clutch3_phi_rel_174 - (0);
    (*res)[23] = _clutch3_sa_112 - (- _clutch3_tau0_max_110);
    (*res)[24] = _clutch3_sa_112 - (- _clutch3_tau0_109);
    (*res)[25] = _der_clutch3_phi_rel_174 - (- _clutch3_w_small_108);
    (*res)[26] = _der_clutch3_phi_rel_174 - (0);

    return 0;
}
