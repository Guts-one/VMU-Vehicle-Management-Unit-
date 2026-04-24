#include "unity.h"
#include "../inc/mode_logic_team.h"

static Mode_t run_from_ev(const Inputs_t *in, Outputs_t *out)
{
    State_t st;

    st.current_mode = MODE_EV;
    ModeLogic_Step(&st, in, out);
    return st.current_mode;
}

static Mode_t run_from_standstill(const Inputs_t *in, Outputs_t *out)
{
    State_t st;

    st.current_mode = MODE_STANDSTILL;
    ModeLogic_Step(&st, in, out);
    return st.current_mode;
}

static Mode_t run_from_regenb(const Inputs_t *in, Outputs_t *out)
{
    State_t st;

    st.current_mode = MODE_REGENB;
    ModeLogic_Step(&st, in, out);
    return st.current_mode;
}

static Mode_t run_from_start(const Inputs_t *in, Outputs_t *out)
{
    State_t st;

    st.current_mode = MODE_START;
    ModeLogic_Step(&st, in, out);
    return st.current_mode;
}

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

/* D1: (speed > SPEED_REGEN) && (P_dem <= PDEM_REGEN) */
void test_ev_mcdc_d1_speed_true_to_regen(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -6.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_ev(&in, &out));
}

void test_ev_mcdc_d1_speed_false_stays_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(2.0f, -6.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ev(&in, &out));
}

void test_ev_mcdc_d1_pdem_true_to_regen(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -6.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_ev(&in, &out));
}

void test_ev_mcdc_d1_pdem_false_stays_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -4.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ev(&in, &out));
}

/* D2: (speed > SPEED_EV_MAX) || (P_dem >= PDEM_HYB_IN) || (SOC < SOC_EV_OUT) */
void test_ev_mcdc_d2_speed_high_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, 0.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_ev(&in, &out));
}

void test_ev_mcdc_d2_speed_not_high_stays_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 0.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ev(&in, &out));
}

void test_ev_mcdc_d2_pdem_high_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 50.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_ev(&in, &out));
}

void test_ev_mcdc_d2_pdem_not_high_stays_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 0.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ev(&in, &out));
}

void test_ev_mcdc_d2_soc_low_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 0.0f, 0.34f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_ev(&in, &out));
}

void test_ev_mcdc_d2_soc_not_low_stays_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 0.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ev(&in, &out));
}

/* D3: (speed <= SPEED_STOP) && (P_dem <= PDEM_STOP_HIGH) && (P_dem >= PDEM_STOP_LOW) */
void test_ev_mcdc_d3_speed_stop_to_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_ev(&in, &out));
}

void test_ev_mcdc_d3_speed_not_stop_stays_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(1.0f, 0.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ev(&in, &out));
}

void test_ev_mcdc_d3_pdem_le_high_to_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_ev(&in, &out));
}

void test_ev_mcdc_d3_pdem_gt_high_stays_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 2.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ev(&in, &out));
}

void test_ev_mcdc_d3_pdem_ge_low_to_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_ev(&in, &out));
}

void test_ev_mcdc_d3_pdem_lt_low_stays_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, -2.0f, 0.40f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_ev(&in, &out));
}

/* ====================================================================
 * TESTES MC/DC PARA handle_standstill
 * ==================================================================== */

/* D1: (speed > SPEED_STOP) && (speed <= SPEED_EV_MAX) && (SOC >= SOC_EV_IN) -> EV */
void test_standstill_mcdc_d1_speed_gt_stop_true_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(1.0f, 0.0f, 0.37f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_standstill(&in, &out));
}

void test_standstill_mcdc_d1_speed_gt_stop_false_stays_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.37f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_standstill(&in, &out));
}

void test_standstill_mcdc_d1_speed_le_ev_max_true_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(35.0f, 0.0f, 0.37f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_standstill(&in, &out));
}

void test_standstill_mcdc_d1_speed_le_ev_max_false_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(36.0f, 0.0f, 0.37f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_standstill(&in, &out));
}

void test_standstill_mcdc_d1_soc_ge_ev_in_true_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 0.0f, 0.37f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_standstill(&in, &out));
}

void test_standstill_mcdc_d1_soc_ge_ev_in_false_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 0.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_standstill(&in, &out));
}

/* D2: (speed > SPEED_STOP) && ((speed > SPEED_EV_MAX) || (SOC < SOC_EV_IN)) -> START */
void test_standstill_mcdc_d2_speed_gt_stop_true_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(1.0f, 0.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_standstill(&in, &out));
}

void test_standstill_mcdc_d2_speed_gt_stop_false_stays_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_standstill(&in, &out));
}

void test_standstill_mcdc_d2_speed_gt_ev_max_true_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(36.0f, 0.0f, 0.37f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_standstill(&in, &out));
}

void test_standstill_mcdc_d2_speed_gt_ev_max_false_soc_low_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 0.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_standstill(&in, &out));
}

void test_standstill_mcdc_d2_soc_lt_ev_in_true_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 0.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_standstill(&in, &out));
}

void test_standstill_mcdc_d2_soc_lt_ev_in_false_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 0.0f, 0.37f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_standstill(&in, &out));
}

/* ====================================================================
 * TESTES MC/DC PARA handle_regenb
 * ==================================================================== */

/* D1: ((speed > SPEED_EV_MAX) && (P_dem >= PDEM_STOP_LOW)) || (SOC < SOC_EV_OUT) -> START */
void test_regenb_mcdc_d1_speed_gt_ev_max_true_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(36.0f, 0.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d1_speed_gt_ev_max_false_soc_low_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 0.0f, 0.34f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d1_pdem_ge_stop_low_true_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(36.0f, -1.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d1_pdem_ge_stop_low_false_stays_regenb(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(36.0f, -2.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d1_soc_lt_ev_out_true_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, -6.0f, 0.34f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d1_soc_lt_ev_out_false_stays_regenb(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, -6.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_regenb(&in, &out));
}

/* D2: (speed <= SPEED_STOP) && (P_dem <= PDEM_STOP_HIGH) && (P_dem >= PDEM_STOP_LOW) -> STANDSTILL */
void test_regenb_mcdc_d2_speed_le_stop_true_to_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d2_speed_le_stop_false_stays_regenb(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(1.0f, -2.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d2_pdem_le_stop_high_true_to_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 1.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d2_pdem_le_stop_high_false_stays_regenb(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 2.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d2_pdem_ge_stop_low_true_to_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, -1.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d2_pdem_ge_stop_low_false_stays_regenb(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, -2.0f, 0.36f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_regenb(&in, &out));
}

/* D3: (P_dem >= PDEM_STOP_LOW) && (speed > SPEED_STOP) && (speed <= SPEED_EV_MAX) && (SOC >= SOC_EV_OUT) -> EV */
void test_regenb_mcdc_d3_pdem_ge_stop_low_true_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, -1.0f, 0.35f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d3_pdem_ge_stop_low_false_stays_regenb(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, -2.0f, 0.35f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d3_speed_gt_stop_true_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(1.0f, 0.0f, 0.35f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d3_speed_gt_stop_false_to_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.35f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d3_speed_le_ev_max_true_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(35.0f, 0.0f, 0.35f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d3_speed_le_ev_max_false_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(36.0f, 0.0f, 0.35f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d3_soc_ge_ev_out_true_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 0.0f, 0.35f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_regenb(&in, &out));
}

void test_regenb_mcdc_d3_soc_ge_ev_out_false_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 0.0f, 0.34f, 0.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_regenb(&in, &out));
}

/* ====================================================================
 * TESTES MC/DC PARA motion_ice_common_exit (usando START, ICE, HYBRID)
 * ==================================================================== */

/* D1: (wEng > ENG_ON) && (speed > SPEED_REGEN) && (P_dem <= PDEM_REGEN) -> REGENB */
void test_motion_ice_mcdc_d1_weng_gt_eng_on_true_to_regenb(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -6.0f, 0.30f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d1_weng_gt_eng_on_false_stays_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -6.0f, 0.30f, 700.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d1_speed_gt_regen_true_to_regenb(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(6.0f, -6.0f, 0.30f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d1_speed_gt_regen_false_stays_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(4.0f, -6.0f, 0.30f, 700.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d1_pdem_le_regen_true_to_regenb(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -5.0f, 0.30f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d1_pdem_le_regen_false_stays_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -4.0f, 0.30f, 700.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_start(&in, &out));
}

/* D2: (wEng > ENG_ON) && (P_dem <= PDEM_HYB_OUT) && (P_dem >= PDEM_STOP_LOW) &&
       (speed > SPEED_STOP) && (speed <= SPEED_EV_MAX) && (SOC >= SOC_EV_IN) -> EV */
void test_motion_ice_mcdc_d2_weng_gt_eng_on_true_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 30.0f, 0.37f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d2_weng_gt_eng_on_false_stays_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 30.0f, 0.37f, 700.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d2_pdem_le_hyb_out_true_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 40.0f, 0.37f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d2_pdem_le_hyb_out_false_stays_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 41.0f, 0.37f, 700.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d2_pdem_ge_stop_low_true_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, -1.0f, 0.37f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d2_pdem_ge_stop_low_false_to_regenb(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, -5.0f, 0.37f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_REGENB, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d2_speed_gt_stop_true_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(1.0f, 30.0f, 0.37f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d2_speed_gt_stop_false_to_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.37f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d2_speed_le_ev_max_true_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(35.0f, 30.0f, 0.37f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d2_speed_le_ev_max_false_stays_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(36.0f, 30.0f, 0.37f, 700.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d2_soc_ge_ev_in_true_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 30.0f, 0.37f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_EV, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d2_soc_ge_ev_in_false_stays_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 30.0f, 0.36f, 700.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_start(&in, &out));
}

/* D3: (speed <= SPEED_STOP) && (P_dem <= PDEM_STOP_HIGH) && (P_dem >= PDEM_STOP_LOW) -> STANDSTILL */
void test_motion_ice_mcdc_d3_speed_le_stop_true_to_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.30f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d3_speed_le_stop_false_stays_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(1.0f, 0.0f, 0.30f, 700.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d3_pdem_le_stop_high_true_to_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 1.0f, 0.30f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d3_pdem_le_stop_high_false_stays_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, 2.0f, 0.30f, 700.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d3_pdem_ge_stop_low_true_to_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, -1.0f, 0.30f, 801.0f);

    TEST_ASSERT_EQUAL(MODE_STANDSTILL, run_from_start(&in, &out));
}

void test_motion_ice_mcdc_d3_pdem_ge_stop_low_false_stays_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.5f, -2.0f, 0.30f, 700.0f);

    TEST_ASSERT_EQUAL(MODE_START, run_from_start(&in, &out));
}

int main(void)
{
    UNITY_BEGIN();

    /* Testes EV */
    RUN_TEST(test_ev_mcdc_d1_speed_true_to_regen);
    RUN_TEST(test_ev_mcdc_d1_speed_false_stays_ev);
    RUN_TEST(test_ev_mcdc_d1_pdem_true_to_regen);
    RUN_TEST(test_ev_mcdc_d1_pdem_false_stays_ev);

    RUN_TEST(test_ev_mcdc_d2_speed_high_to_start);
    RUN_TEST(test_ev_mcdc_d2_speed_not_high_stays_ev);
    RUN_TEST(test_ev_mcdc_d2_pdem_high_to_start);
    RUN_TEST(test_ev_mcdc_d2_pdem_not_high_stays_ev);
    RUN_TEST(test_ev_mcdc_d2_soc_low_to_start);
    RUN_TEST(test_ev_mcdc_d2_soc_not_low_stays_ev);

    RUN_TEST(test_ev_mcdc_d3_speed_stop_to_standstill);
    RUN_TEST(test_ev_mcdc_d3_speed_not_stop_stays_ev);
    RUN_TEST(test_ev_mcdc_d3_pdem_le_high_to_standstill);
    RUN_TEST(test_ev_mcdc_d3_pdem_gt_high_stays_ev);
    RUN_TEST(test_ev_mcdc_d3_pdem_ge_low_to_standstill);
    RUN_TEST(test_ev_mcdc_d3_pdem_lt_low_stays_ev);

    /* Testes STANDSTILL */
    RUN_TEST(test_standstill_mcdc_d1_speed_gt_stop_true_to_ev);
    RUN_TEST(test_standstill_mcdc_d1_speed_gt_stop_false_stays_standstill);
    RUN_TEST(test_standstill_mcdc_d1_speed_le_ev_max_true_to_ev);
    RUN_TEST(test_standstill_mcdc_d1_speed_le_ev_max_false_to_start);
    RUN_TEST(test_standstill_mcdc_d1_soc_ge_ev_in_true_to_ev);
    RUN_TEST(test_standstill_mcdc_d1_soc_ge_ev_in_false_to_start);

    RUN_TEST(test_standstill_mcdc_d2_speed_gt_stop_true_to_start);
    RUN_TEST(test_standstill_mcdc_d2_speed_gt_stop_false_stays_standstill);
    RUN_TEST(test_standstill_mcdc_d2_speed_gt_ev_max_true_to_start);
    RUN_TEST(test_standstill_mcdc_d2_speed_gt_ev_max_false_soc_low_to_start);
    RUN_TEST(test_standstill_mcdc_d2_soc_lt_ev_in_true_to_start);
    RUN_TEST(test_standstill_mcdc_d2_soc_lt_ev_in_false_to_ev);

    /* Testes REGENB */
    RUN_TEST(test_regenb_mcdc_d1_speed_gt_ev_max_true_to_start);
    RUN_TEST(test_regenb_mcdc_d1_speed_gt_ev_max_false_soc_low_to_start);
    RUN_TEST(test_regenb_mcdc_d1_pdem_ge_stop_low_true_to_start);
    RUN_TEST(test_regenb_mcdc_d1_pdem_ge_stop_low_false_stays_regenb);
    RUN_TEST(test_regenb_mcdc_d1_soc_lt_ev_out_true_to_start);
    RUN_TEST(test_regenb_mcdc_d1_soc_lt_ev_out_false_stays_regenb);

    RUN_TEST(test_regenb_mcdc_d2_speed_le_stop_true_to_standstill);
    RUN_TEST(test_regenb_mcdc_d2_speed_le_stop_false_stays_regenb);
    RUN_TEST(test_regenb_mcdc_d2_pdem_le_stop_high_true_to_standstill);
    RUN_TEST(test_regenb_mcdc_d2_pdem_le_stop_high_false_stays_regenb);
    RUN_TEST(test_regenb_mcdc_d2_pdem_ge_stop_low_true_to_standstill);
    RUN_TEST(test_regenb_mcdc_d2_pdem_ge_stop_low_false_stays_regenb);

    RUN_TEST(test_regenb_mcdc_d3_pdem_ge_stop_low_true_to_ev);
    RUN_TEST(test_regenb_mcdc_d3_pdem_ge_stop_low_false_stays_regenb);
    RUN_TEST(test_regenb_mcdc_d3_speed_gt_stop_true_to_ev);
    RUN_TEST(test_regenb_mcdc_d3_speed_gt_stop_false_to_standstill);
    RUN_TEST(test_regenb_mcdc_d3_speed_le_ev_max_true_to_ev);
    RUN_TEST(test_regenb_mcdc_d3_speed_le_ev_max_false_to_start);
    RUN_TEST(test_regenb_mcdc_d3_soc_ge_ev_out_true_to_ev);
    RUN_TEST(test_regenb_mcdc_d3_soc_ge_ev_out_false_to_start);

    /* Testes MOTION_ICE_COMMON_EXIT */
    RUN_TEST(test_motion_ice_mcdc_d1_weng_gt_eng_on_true_to_regenb);
    RUN_TEST(test_motion_ice_mcdc_d1_weng_gt_eng_on_false_stays_start);
    RUN_TEST(test_motion_ice_mcdc_d1_speed_gt_regen_true_to_regenb);
    RUN_TEST(test_motion_ice_mcdc_d1_speed_gt_regen_false_stays_start);
    RUN_TEST(test_motion_ice_mcdc_d1_pdem_le_regen_true_to_regenb);
    RUN_TEST(test_motion_ice_mcdc_d1_pdem_le_regen_false_stays_start);

    RUN_TEST(test_motion_ice_mcdc_d2_weng_gt_eng_on_true_to_ev);
    RUN_TEST(test_motion_ice_mcdc_d2_weng_gt_eng_on_false_stays_start);
    RUN_TEST(test_motion_ice_mcdc_d2_pdem_le_hyb_out_true_to_ev);
    RUN_TEST(test_motion_ice_mcdc_d2_pdem_le_hyb_out_false_stays_start);
    RUN_TEST(test_motion_ice_mcdc_d2_pdem_ge_stop_low_true_to_ev);
    RUN_TEST(test_motion_ice_mcdc_d2_pdem_ge_stop_low_false_to_regenb);
    RUN_TEST(test_motion_ice_mcdc_d2_speed_gt_stop_true_to_ev);
    RUN_TEST(test_motion_ice_mcdc_d2_speed_gt_stop_false_to_standstill);
    RUN_TEST(test_motion_ice_mcdc_d2_speed_le_ev_max_true_to_ev);
    RUN_TEST(test_motion_ice_mcdc_d2_speed_le_ev_max_false_stays_start);
    RUN_TEST(test_motion_ice_mcdc_d2_soc_ge_ev_in_true_to_ev);
    RUN_TEST(test_motion_ice_mcdc_d2_soc_ge_ev_in_false_stays_start);

    RUN_TEST(test_motion_ice_mcdc_d3_speed_le_stop_true_to_standstill);
    RUN_TEST(test_motion_ice_mcdc_d3_speed_le_stop_false_stays_start);
    RUN_TEST(test_motion_ice_mcdc_d3_pdem_le_stop_high_true_to_standstill);
    RUN_TEST(test_motion_ice_mcdc_d3_pdem_le_stop_high_false_stays_start);
    RUN_TEST(test_motion_ice_mcdc_d3_pdem_ge_stop_low_true_to_standstill);
    RUN_TEST(test_motion_ice_mcdc_d3_pdem_ge_stop_low_false_stays_start);

    return UNITY_END();
}
