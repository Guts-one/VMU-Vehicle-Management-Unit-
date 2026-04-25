#include "unity.h"
#include "../inc/mode_logic_team.h"

/* ====================================================================
 * FUNCOES AUXILIARES
 * ==================================================================== */

static Mode_t run_from_ice(const Inputs_t *in, Outputs_t *out)
{
    State_t st;

    st.current_mode = MODE_ICE;
    ModeLogic_Step(&st, in, out);
    return st.current_mode;
}

static Mode_t run_from_hybrid(const Inputs_t *in, Outputs_t *out)
{
    State_t st;

    st.current_mode = MODE_HYBRID;
    ModeLogic_Step(&st, in, out);
    return st.current_mode;
}

static Inputs_t make_inputs(float speed, float p_dem, float soc, float w_eng)
{
    Inputs_t in;

    in.speed = speed;
    in.P_dem = p_dem;
    in.SOC = soc;
    in.wEng = w_eng;

    return in;
}

void setUp(void)
{
}

void tearDown(void)
{
}

/* ====================================================================
 * TESTES MC/DC PARA handle_ice
 * ==================================================================== */

/* ----------------------------------------
 * Testes para motion_ice_common_exit saindo de ICE
 * ---------------------------------------- */

/* D1: (wEng > ENG_ON) && (speed > SPEED_REGEN) && (P_dem <= PDEM_REGEN) -> REGENB */
void test_ice_mcdc_common_exit_to_regenb_weng_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -6.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_regenb_weng_false_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -6.0f, 0.40f, 790.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_regenb_speed_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -6.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_regenb_speed_false_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(3.0f, -6.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_regenb_pdem_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -6.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_regenb_pdem_false_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -4.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_ice(&in, &out));
}

/* D2: (wEng > ENG_ON) && (P_dem <= PDEM_HYB_OUT) && (P_dem >= PDEM_STOP_LOW) &&
       (speed > SPEED_STOP) && (speed <= SPEED_EV_MAX) && (SOC >= SOC_EV_IN) -> EV */

void test_ice_mcdc_common_exit_to_ev_weng_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 5.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_ev_weng_false_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 5.0f, 0.40f, 790.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_ev_pdem_le_hyb_out_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 40.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_ev_pdem_le_hyb_out_false_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 45.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_ev_pdem_ge_stop_low_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 5.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_ev_pdem_ge_stop_low_false_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -2.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_ev_speed_gt_stop_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 5.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_ev_speed_gt_stop_false_to_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.3f, 0.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_ev_speed_le_ev_max_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(35.0f, 5.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_ev_speed_le_ev_max_false_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 5.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_ev_soc_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 5.0f, 0.37f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_ev_soc_false_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 5.0f, 0.36f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_ice(&in, &out));
}

/* D3: (speed <= SPEED_STOP) && (P_dem <= PDEM_STOP_HIGH) && (P_dem >= PDEM_STOP_LOW) -> STANDSTILL */

void test_ice_mcdc_common_exit_to_standstill_speed_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_standstill_speed_false_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(1.0f, 0.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_standstill_pdem_le_high_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 1.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_standstill_pdem_le_high_false_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 2.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_standstill_pdem_ge_low_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_ice(&in, &out));
}

void test_ice_mcdc_common_exit_to_standstill_pdem_ge_low_false_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, -2.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_ice(&in, &out));
}

/* ----------------------------------------
 * Testes para internal_motion_ice_reset de ICE
 * ---------------------------------------- */

/* Reset: wEng <= ENG_OFF -> START */
void test_ice_mcdc_reset_to_start_weng_le_eng_off(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 12.0f, 0.28f, 790.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_ice(&in, &out));
}

void test_ice_mcdc_reset_to_start_weng_le_eng_off_at_limit(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 12.0f, 0.28f, 790.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_ice(&in, &out));
}

void test_ice_mcdc_reset_weng_gt_eng_off_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 12.0f, 0.28f, 810.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_ice(&in, &out));
}

/* ----------------------------------------
 * Testes para transicao especifica ICE -> HYBRID
 * ---------------------------------------- */

/* D4: (P_dem >= PDEM_HYB_MID) && (SOC >= SOC_MID) -> HYBRID */

void test_ice_mcdc_to_hybrid_pdem_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 15.0f, 0.35f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_ice(&in, &out));
}

void test_ice_mcdc_to_hybrid_pdem_false_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 14.0f, 0.35f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_ice(&in, &out));
}

void test_ice_mcdc_to_hybrid_soc_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.30f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_ice(&in, &out));
}

void test_ice_mcdc_to_hybrid_soc_false_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.29f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_ice(&in, &out));
}

void test_ice_mcdc_to_hybrid_at_limits(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 15.0f, 0.30f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_ice(&in, &out));
}

/* ----------------------------------------
 * Teste para permanecer em ICE
 * ---------------------------------------- */

void test_ice_stays_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 12.0f, 0.28f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_ice(&in, &out));
}

/* ====================================================================
 * TESTES MC/DC PARA handle_hybrid
 * ==================================================================== */

/* ----------------------------------------
 * Testes para motion_ice_common_exit saindo de HYBRID
 * ---------------------------------------- */

/* D1: (wEng > ENG_ON) && (speed > SPEED_REGEN) && (P_dem <= PDEM_REGEN) -> REGENB */

void test_hybrid_mcdc_common_exit_to_regenb_weng_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -6.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_regenb_weng_false_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -6.0f, 0.40f, 790.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_regenb_speed_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -6.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_regenb_speed_false_stays_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(3.0f, -6.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_regenb_pdem_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -6.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_regenb_pdem_false_stays_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -4.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_hybrid(&in, &out));
}

/* D2: (wEng > ENG_ON) && (P_dem <= PDEM_HYB_OUT) && (P_dem >= PDEM_STOP_LOW) &&
       (speed > SPEED_STOP) && (speed <= SPEED_EV_MAX) && (SOC >= SOC_EV_IN) -> EV */

void test_hybrid_mcdc_common_exit_to_ev_weng_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 5.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_ev_weng_false_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 5.0f, 0.40f, 790.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_ev_pdem_le_hyb_out_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 40.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_ev_pdem_le_hyb_out_false_stays_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 45.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_ev_pdem_ge_stop_low_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 5.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_ev_pdem_ge_stop_low_false_stays_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -2.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_ev_speed_gt_stop_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 5.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_ev_speed_gt_stop_false_to_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.3f, 0.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_ev_speed_le_ev_max_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(35.0f, 5.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_ev_speed_le_ev_max_false_stays_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 5.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_ev_soc_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 5.0f, 0.37f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_ev_soc_false_stays_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 5.0f, 0.36f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_hybrid(&in, &out));
}

/* D3: (speed <= SPEED_STOP) && (P_dem <= PDEM_STOP_HIGH) && (P_dem >= PDEM_STOP_LOW) -> STANDSTILL */

void test_hybrid_mcdc_common_exit_to_standstill_speed_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_standstill_speed_false_stays_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(1.0f, 0.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_standstill_pdem_le_high_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 1.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_standstill_pdem_le_high_false_stays_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 2.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_standstill_pdem_ge_low_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_common_exit_to_standstill_pdem_ge_low_false_stays_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, -2.0f, 0.40f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_hybrid(&in, &out));
}

/* ----------------------------------------
 * Testes para internal_motion_ice_reset de HYBRID
 * ---------------------------------------- */

/* Reset: wEng <= ENG_OFF -> START */
void test_hybrid_mcdc_reset_to_start_weng_le_eng_off(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.35f, 790.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_reset_to_start_weng_le_eng_off_at_limit(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.35f, 790.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_reset_weng_gt_eng_off_stays_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.35f, 810.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_hybrid(&in, &out));
}

/* ----------------------------------------
 * Testes para transicao especifica HYBRID -> ICE
 * ---------------------------------------- */

/* D4: (P_dem <= PDEM_HYB_LOW) || (SOC < SOC_LOW) -> ICE */

void test_hybrid_mcdc_to_ice_pdem_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 10.0f, 0.35f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_to_ice_pdem_false_stays_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 11.0f, 0.30f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_to_ice_soc_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.24f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_to_ice_soc_false_stays_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.26f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_to_ice_at_limits_pdem(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 10.0f, 0.30f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_to_ice_at_limits_soc(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 15.0f, 0.24f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_hybrid(&in, &out));
}

void test_hybrid_mcdc_to_ice_both_conditions_true(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 10.0f, 0.24f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_ICE, run_from_hybrid(&in, &out));
}

/* ----------------------------------------
 * Teste para permanecer em HYBRID
 * ---------------------------------------- */

void test_hybrid_stays_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.35f, 850.0f);

    TEST_ASSERT_EQUAL(MODE_HYBRID, run_from_hybrid(&in, &out));
}

/* ====================================================================
 * MAIN
 * ==================================================================== */

int main(void)
{
    UNITY_BEGIN();

    /* Testes para handle_ice */
    RUN_TEST(test_ice_mcdc_common_exit_to_regenb_weng_true);
    RUN_TEST(test_ice_mcdc_common_exit_to_regenb_weng_false_stays_ice);
    RUN_TEST(test_ice_mcdc_common_exit_to_regenb_speed_true);
    RUN_TEST(test_ice_mcdc_common_exit_to_regenb_speed_false_stays_ice);
    RUN_TEST(test_ice_mcdc_common_exit_to_regenb_pdem_true);
    RUN_TEST(test_ice_mcdc_common_exit_to_regenb_pdem_false_stays_ice);
    
    RUN_TEST(test_ice_mcdc_common_exit_to_ev_weng_true);
    RUN_TEST(test_ice_mcdc_common_exit_to_ev_weng_false_stays_ice);
    RUN_TEST(test_ice_mcdc_common_exit_to_ev_pdem_le_hyb_out_true);
    RUN_TEST(test_ice_mcdc_common_exit_to_ev_pdem_le_hyb_out_false_stays_ice);
    RUN_TEST(test_ice_mcdc_common_exit_to_ev_pdem_ge_stop_low_true);
    RUN_TEST(test_ice_mcdc_common_exit_to_ev_pdem_ge_stop_low_false_stays_ice);
    RUN_TEST(test_ice_mcdc_common_exit_to_ev_speed_gt_stop_true);
    RUN_TEST(test_ice_mcdc_common_exit_to_ev_speed_gt_stop_false_to_standstill);
    RUN_TEST(test_ice_mcdc_common_exit_to_ev_speed_le_ev_max_true);
    RUN_TEST(test_ice_mcdc_common_exit_to_ev_speed_le_ev_max_false_stays_ice);
    RUN_TEST(test_ice_mcdc_common_exit_to_ev_soc_true);
    RUN_TEST(test_ice_mcdc_common_exit_to_ev_soc_false_stays_ice);
    
    RUN_TEST(test_ice_mcdc_common_exit_to_standstill_speed_true);
    RUN_TEST(test_ice_mcdc_common_exit_to_standstill_speed_false_stays_ice);
    RUN_TEST(test_ice_mcdc_common_exit_to_standstill_pdem_le_high_true);
    RUN_TEST(test_ice_mcdc_common_exit_to_standstill_pdem_le_high_false_stays_ice);
    RUN_TEST(test_ice_mcdc_common_exit_to_standstill_pdem_ge_low_true);
    RUN_TEST(test_ice_mcdc_common_exit_to_standstill_pdem_ge_low_false_stays_ice);
    
    RUN_TEST(test_ice_mcdc_reset_to_start_weng_le_eng_off);
    RUN_TEST(test_ice_mcdc_reset_to_start_weng_le_eng_off_at_limit);
    RUN_TEST(test_ice_mcdc_reset_weng_gt_eng_off_stays_ice);
    
    RUN_TEST(test_ice_mcdc_to_hybrid_pdem_true);
    RUN_TEST(test_ice_mcdc_to_hybrid_pdem_false_stays_ice);
    RUN_TEST(test_ice_mcdc_to_hybrid_soc_true);
    RUN_TEST(test_ice_mcdc_to_hybrid_soc_false_stays_ice);
    RUN_TEST(test_ice_mcdc_to_hybrid_at_limits);
    
    RUN_TEST(test_ice_stays_ice);

    /* Testes para handle_hybrid */
    RUN_TEST(test_hybrid_mcdc_common_exit_to_regenb_weng_true);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_regenb_weng_false_to_start);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_regenb_speed_true);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_regenb_speed_false_stays_hybrid);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_regenb_pdem_true);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_regenb_pdem_false_stays_hybrid);
    
    RUN_TEST(test_hybrid_mcdc_common_exit_to_ev_weng_true);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_ev_weng_false_to_start);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_ev_pdem_le_hyb_out_true);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_ev_pdem_le_hyb_out_false_stays_hybrid);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_ev_pdem_ge_stop_low_true);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_ev_pdem_ge_stop_low_false_stays_hybrid);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_ev_speed_gt_stop_true);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_ev_speed_gt_stop_false_to_standstill);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_ev_speed_le_ev_max_true);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_ev_speed_le_ev_max_false_stays_hybrid);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_ev_soc_true);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_ev_soc_false_stays_hybrid);
    
    RUN_TEST(test_hybrid_mcdc_common_exit_to_standstill_speed_true);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_standstill_speed_false_stays_hybrid);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_standstill_pdem_le_high_true);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_standstill_pdem_le_high_false_stays_hybrid);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_standstill_pdem_ge_low_true);
    RUN_TEST(test_hybrid_mcdc_common_exit_to_standstill_pdem_ge_low_false_stays_hybrid);
    
    RUN_TEST(test_hybrid_mcdc_reset_to_start_weng_le_eng_off);
    RUN_TEST(test_hybrid_mcdc_reset_to_start_weng_le_eng_off_at_limit);
    RUN_TEST(test_hybrid_mcdc_reset_weng_gt_eng_off_stays_hybrid);
    
    RUN_TEST(test_hybrid_mcdc_to_ice_pdem_true);
    RUN_TEST(test_hybrid_mcdc_to_ice_pdem_false_stays_hybrid);
    RUN_TEST(test_hybrid_mcdc_to_ice_soc_true);
    RUN_TEST(test_hybrid_mcdc_to_ice_soc_false_stays_hybrid);
    RUN_TEST(test_hybrid_mcdc_to_ice_at_limits_pdem);
    RUN_TEST(test_hybrid_mcdc_to_ice_at_limits_soc);
    RUN_TEST(test_hybrid_mcdc_to_ice_both_conditions_true);
    
    RUN_TEST(test_hybrid_stays_hybrid);

    return UNITY_END();
}
