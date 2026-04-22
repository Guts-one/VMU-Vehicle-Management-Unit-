#include <assert.h>
#include <stdio.h>

#include "../inc/mode_logic_team.h"

static Mode_t run_step(Mode_t initial_mode, const Inputs_t *in, Outputs_t *out)
{
    State_t state;

    state.current_mode = initial_mode;
    ModeLogic_Step(&state, in, out);
    return state.current_mode;
}

static Inputs_t make_inputs(float speed, float p_dem, float soc, float weng)
{
    Inputs_t in;

    in.speed = speed;
    in.P_dem = p_dem;
    in.SOC = soc;
    in.wEng = weng;

    return in;
}

static void test_standstill_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 0.0f, 0.40f, 0.0f);

    assert(run_step(MODE_STANDSTILL, &in, &out) == MODE_EV);
}

static void test_standstill_ev_guard_needs_pdem_gt_regen(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, -5.0f, 0.40f, 0.0f);

    assert(run_step(MODE_STANDSTILL, &in, &out) == MODE_STANDSTILL);
}

static void test_standstill_to_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(10.0f, 0.0f, 0.30f, 0.0f);

    assert(run_step(MODE_STANDSTILL, &in, &out) == MODE_START);
}

static void test_ev_priority_regen_over_start(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(40.0f, -6.0f, 0.40f, 0.0f);

    assert(run_step(MODE_EV, &in, &out) == MODE_REGENB);
}

static void test_ev_to_start_high_pdem(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 50.0f, 0.40f, 0.0f);

    assert(run_step(MODE_EV, &in, &out) == MODE_START);
}

static void test_ev_to_standstill_strict_neutral_band(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t neutral_inside = make_inputs(0.5f, 0.0f, 0.40f, 0.0f);
    Inputs_t neutral_edge = make_inputs(0.5f, -1.0f, 0.40f, 0.0f);

    assert(run_step(MODE_EV, &neutral_inside, &out) == MODE_STANDSTILL);
    assert(run_step(MODE_EV, &neutral_edge, &out) == MODE_EV);
}

static void test_regenb_priority_start_over_standstill(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(0.3f, 0.0f, 0.30f, 0.0f);

    assert(run_step(MODE_REGENB, &in, &out) == MODE_START);
}

static void test_regenb_to_ev(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, -0.5f, 0.40f, 0.0f);

    assert(run_step(MODE_REGENB, &in, &out) == MODE_EV);
}

static void test_regenb_stays_when_no_transition_matches(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, -2.0f, 0.40f, 0.0f);

    assert(run_step(MODE_REGENB, &in, &out) == MODE_REGENB);
}

static void test_start_external_exits(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t to_regen = make_inputs(10.0f, -6.0f, 0.40f, 900.0f);
    Inputs_t to_ev = make_inputs(20.0f, 0.0f, 0.40f, 900.0f);
    Inputs_t to_standstill = make_inputs(0.3f, 0.0f, 0.40f, 900.0f);

    assert(run_step(MODE_START, &to_regen, &out) == MODE_REGENB);
    assert(run_step(MODE_START, &to_ev, &out) == MODE_EV);
    assert(run_step(MODE_START, &to_standstill, &out) == MODE_STANDSTILL);
}

static void test_start_internal_to_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(36.0f, 20.0f, 0.35f, 900.0f);

    assert(run_step(MODE_START, &in, &out) == MODE_HYBRID);
}

static void test_start_internal_to_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(30.0f, 10.0f, 0.29f, 900.0f);

    assert(run_step(MODE_START, &in, &out) == MODE_ICE);
}

static void test_ice_reset_priority_over_ice_to_hybrid(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 20.0f, 0.35f, 780.0f);

    assert(run_step(MODE_ICE, &in, &out) == MODE_START);
}

static void test_ice_to_hybrid_when_engine_on(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 20.0f, 0.35f, 900.0f);

    assert(run_step(MODE_ICE, &in, &out) == MODE_HYBRID);
}

static void test_hybrid_reset_priority_over_hybrid_to_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 5.0f, 0.24f, 780.0f);

    assert(run_step(MODE_HYBRID, &in, &out) == MODE_START);
}

static void test_hybrid_to_ice(void)
{
    Outputs_t out = {0U, 0U, 0U};
    Inputs_t in = make_inputs(20.0f, 9.0f, 0.40f, 900.0f);

    assert(run_step(MODE_HYBRID, &in, &out) == MODE_ICE);
}

int main(void)
{
    printf("Running team update mode-logic tests...\n");

    test_standstill_to_ev();
    test_standstill_ev_guard_needs_pdem_gt_regen();
    test_standstill_to_start();

    test_ev_priority_regen_over_start();
    test_ev_to_start_high_pdem();
    test_ev_to_standstill_strict_neutral_band();

    test_regenb_priority_start_over_standstill();
    test_regenb_to_ev();
    test_regenb_stays_when_no_transition_matches();

    test_start_external_exits();
    test_start_internal_to_hybrid();
    test_start_internal_to_ice();

    test_ice_reset_priority_over_ice_to_hybrid();
    test_ice_to_hybrid_when_engine_on();

    test_hybrid_reset_priority_over_hybrid_to_ice();
    test_hybrid_to_ice();

    printf("All team update tests passed.\n");
    return 0;
}
