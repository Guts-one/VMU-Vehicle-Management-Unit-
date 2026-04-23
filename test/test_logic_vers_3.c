/*
 * test_logic_vers_3.c
 *
 * Test suite for mode_logic_team (Stateflow compliant).
 * Compile with:
 * gcc -Iunity -Iinc -I../inc unity/unity.c stub_mode_logic_team1.c test_logic_vers_3.c -o executar_testes.exe
 */

#include "unity.h"
#include "../inc/mode_logic_team.h"
#include <stdint.h>

/* --------------------------------------------------------------------------
 * Helper: Executes one cycle of the state machine and returns the new mode
 * -------------------------------------------------------------------------- */
static Mode_t step(Mode_t mode, float speed, float P_dem, float SOC, float wEng)
{
    State_t   st  = { mode };
    Inputs_t  in  = { speed, P_dem, SOC, wEng };
    Outputs_t out;
    ModeLogic_Step(&st, &in, &out);
    return st.current_mode;
}

void setUp(void) {}
void tearDown(void) {}

/* =========================================================================
 * GROUP A – Transitions from StandStill (Model §StandStill exits)
 * ========================================================================= */

/* §StandStill->EV_mode: nominal conditions */
void test_standstill_to_ev_nominal_conditions(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_STANDSTILL, 10.0f, 0.0f, 0.5f, 0.0f));
}

/* §StandStill->EV_mode: speed exactly at SPEED_STOP (0.5) -> should remain StandStill */
void test_standstill_stays_when_vehicle_stopped(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, step(MODE_STANDSTILL, 0.5f, 0.0f, 0.5f, 0.0f));
}

/* §StandStill->EV_mode: speed just above SPEED_STOP -> EV */
void test_standstill_to_ev_on_speed_just_above_stop(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_STANDSTILL, 0.51f, 0.0f, 0.5f, 0.0f));
}

/* §StandStill->EV_mode: SOC exactly at SOC_EV_IN (0.37) -> EV */
void test_standstill_to_ev_on_soc_at_entry_boundary(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_STANDSTILL, 10.0f, 0.0f, 0.37f, 0.0f));
}

/* §StandStill->Motion_mode_ICE: SOC just below SOC_EV_IN (0.37) -> START (ICE superstate) */
void test_standstill_to_start_on_soc_just_below_entry(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_STANDSTILL, 10.0f, 0.0f, 0.369f, 0.0f));
}

/* §StandStill->EV_mode: speed exactly at SPEED_EV_MAX (35.0) -> EV */
void test_standstill_to_ev_on_speed_at_ev_max(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_STANDSTILL, 35.0f, 0.0f, 0.5f, 0.0f));
}

/* §StandStill->Motion_mode_ICE: speed just above SPEED_EV_MAX -> START */
void test_standstill_to_start_on_speed_just_above_ev_max(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_STANDSTILL, 35.01f, 0.0f, 0.5f, 0.0f));
}

/* MC/DC for condition speed > SPEED_STOP */
void test_mcdc_standstill_speed_stop_condition(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, step(MODE_STANDSTILL, 0.5f, 0.0f, 0.5f, 0.0f));
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_STANDSTILL, 0.51f, 0.0f, 0.5f, 0.0f));
}

/* MC/DC for condition speed <= SPEED_EV_MAX */
void test_mcdc_standstill_speed_ev_max_condition(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_STANDSTILL, 35.01f, 0.0f, 0.5f, 0.0f));
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_STANDSTILL, 35.0f, 0.0f, 0.5f, 0.0f));
}

/* MC/DC for condition SOC >= SOC_EV_IN */
void test_mcdc_standstill_soc_condition(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_STANDSTILL, 10.0f, 0.0f, 0.369f, 0.0f));
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_STANDSTILL, 10.0f, 0.0f, 0.37f, 0.0f));
}

/* MC/DC for condition P_dem > PDEM_REGEN (-5.0) */
void test_mcdc_standstill_power_demand_condition(void)
{
    /* P = -5.0 -> not > -5.0, EV blocked (StandStill remains) */
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, step(MODE_STANDSTILL, 10.0f, -5.0f, 0.5f, 0.0f));
    /* P = -4.99 -> EV allowed */
    TEST_ASSERT_EQUAL_INT(MODE_EV,         step(MODE_STANDSTILL, 10.0f, -4.99f, 0.5f, 0.0f));
}

/* =========================================================================
 * GROUP B – Transitions from EV_mode (Model §EV_mode exits)
 * ========================================================================= */

/* §EV_mode->RegenB_mode: braking demand at PDEM_REGEN boundary */
void test_ev_to_regenb_on_braking_demand_boundary(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, step(MODE_EV, 10.0f, -5.0f, 0.5f, 0.0f));
}

/* §EV_mode->RegenB_mode: speed just above SPEED_REGEN, P_dem <= -5 */
void test_ev_to_regenb_speed_above_regen(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, step(MODE_EV, 5.01f, -5.0f, 0.5f, 0.0f));
}

/* §EV_mode->RegenB_mode: speed exactly at SPEED_REGEN (5.0) -> condition false, EV stays */
void test_ev_stays_at_speed_regen_boundary(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_EV, 5.0f, -5.0f, 0.5f, 0.0f));
}

/* §EV_mode->StandStill: speed at SPEED_STOP, P_dem within neutral band */
void test_ev_to_standstill_on_speed_at_stop_boundary(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, step(MODE_EV, 0.5f, 0.0f, 0.5f, 0.0f));
}

/* §EV_mode->StandStill: speed just above SPEED_STOP -> remains EV */
void test_ev_stays_on_speed_just_above_stop_boundary(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_EV, 0.51f, 0.0f, 0.5f, 0.0f));
}

/* §EV_mode->Motion_mode_ICE: SOC just below SOC_EV_OUT (0.35) -> START */
void test_ev_to_start_on_soc_just_below_sustain(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_EV, 10.0f, 0.0f, 0.349f, 0.0f));
}

/* §EV_mode->Motion_mode_ICE: speed just above SPEED_EV_MAX -> START */
void test_ev_to_start_on_speed_just_above_ev_max(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_EV, 35.01f, 0.0f, 0.5f, 0.0f));
}

/* §EV_mode exits priority: RegenB_mode evaluated before Motion_mode_ICE */
void test_mcdc_ev_regenb_priority_over_start(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, step(MODE_EV, 35.01f, -5.0f, 0.5f, 0.0f));
}

/* §EV_mode->StandStill: P_dem at PDEM_STOP_HIGH (1.0) -> not < 1.0, StandStill blocked */
void test_mcdc_ev_high_power_blocks_standstill(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_EV, 0.5f, 1.0f, 0.5f, 0.0f));
}

/* §EV_mode->StandStill: P_dem at PDEM_STOP_LOW (-1.0) -> not > -1.0, StandStill blocked */
void test_mcdc_ev_negative_power_blocks_standstill(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_EV, 0.5f, -1.0f, 0.5f, 0.0f));
}

/* §EV_mode->RegenB_mode: SOC is not part of condition; low SOC does not block */
void test_mcdc_ev_low_soc_does_not_block_regenb(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, step(MODE_EV, 10.0f, -5.0f, 0.2f, 0.0f));
}

/* §EV_mode->StandStill: exact neutral band boundaries */
void test_ev_to_standstill_on_power_demand_at_neutral_stop_max_boundary(void)
{
    /* P = 0.99 (< 1.0) and > -1.0 -> StandStill allowed */
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, step(MODE_EV, 0.5f, 0.99f, 0.5f, 0.0f));
    /* P = -0.99 -> StandStill allowed */
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, step(MODE_EV, 0.5f, -0.99f, 0.5f, 0.0f));
}

/* =========================================================================
 * GROUP C – Transitions from RegenB_mode (Model §RegenB_mode exits)
 * ========================================================================= */

/* §RegenB_mode->StandStill: speed exactly at SPEED_STOP */
void test_regenb_to_standstill_on_speed_at_stop_boundary(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, step(MODE_REGENB, 0.5f, -5.0f, 0.5f, 0.0f));
}

/* §RegenB_mode->StandStill: speed just above SPEED_STOP -> remains RegenB */
void test_regenb_stays_on_speed_just_above_stop_boundary(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, step(MODE_REGENB, 0.51f, -5.0f, 0.5f, 0.0f));
}

/* §RegenB_mode->Motion_mode_ICE: SOC just below SOC_EV_OUT (0.35) -> START */
void test_regenb_to_start_on_soc_just_below_entry(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_REGENB, 10.0f, -5.0f, 0.349f, 0.0f));
}

/* §RegenB_mode->EV_mode: P_dem exactly at PDEM_STOP_LOW (-1.0) allows exit */
void test_regenb_to_ev_on_power_demand_at_regen_exit_boundary(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_REGENB, 10.0f, -1.0f, 0.4f, 0.0f));
}

/* §RegenB_mode->EV_mode: P_dem just above -1.0, other conditions met -> EV */
void test_regenb_to_ev_nominal(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_REGENB, 10.0f, -0.99f, 0.4f, 0.0f));
}

/* §RegenB_mode exits priority: Motion_mode_ICE before StandStill */
void test_mcdc_regenb_start_priority_over_standstill(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_REGENB, 0.5f, -5.0f, 0.34f, 0.0f));
}

/* §RegenB_mode exits priority: Motion_mode_ICE before EV_mode */
void test_mcdc_regenb_start_priority_over_ev(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_REGENB, 10.0f, 0.0f, 0.34f, 0.0f));
}

/* §RegenB_mode exits priority: StandStill before EV_mode */
void test_mcdc_regenb_standstill_priority_over_ev(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, step(MODE_REGENB, 0.5f, 0.0f, 0.4f, 0.0f));
}

/* §RegenB_mode->Motion_mode_ICE: high speed without braking -> START */
void test_regenb_to_start_on_high_speed_no_braking(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_REGENB, 35.01f, 0.0f, 0.4f, 0.0f));
}

/* MC/DC for RegenB->Motion_mode_ICE: (speed>35 && P_dem>=-1) */
void test_mcdc_regenb_start_clause_speed_demand_combo(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_REGENB, 35.01f, -1.0f, 0.4f, 0.0f));
}

/* MC/DC for RegenB->Motion_mode_ICE: P_dem >= PDEM_HYB_IN (50.0) */
void test_mcdc_regenb_start_clause_high_demand_only(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_REGENB, 10.0f, 50.0f, 0.4f, 0.0f));
}

/* =========================================================================
 * GROUP D – Transitions from Motion_mode_ICE internal states (Model §Start_mode, ICE_mode, Hybrid_mode)
 * ========================================================================= */

/* §Start_mode->Hybrid_mode: speed just above SPEED_EV_MAX */
void test_start_to_hybrid_on_speed_just_above_ev_max(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, step(MODE_START, 35.01f, 0.0f, 0.4f, 1000.0f));
}

/* §Start_mode->Hybrid_mode: P_dem at PDEM_HYB_MID (15.0) */
void test_start_to_hybrid_on_power_demand_at_hybrid_boundary(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, step(MODE_START, 10.0f, 15.0f, 0.4f, 1000.0f));
}

/* §ICE_mode->Start_mode: engine speed at ENG_OFF (790.0) triggers reset */
void test_ice_to_start_on_engine_speed_at_stall_boundary(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_ICE, 10.0f, 0.0f, 0.2f, 790.0f));
}

/* §ICE_mode: engine speed just above ENG_OFF -> remains ICE */
void test_ice_stays_on_engine_speed_just_above_stall(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_ICE, step(MODE_ICE, 10.0f, 0.0f, 0.2f, 790.01f));
}

/* §Hybrid_mode->Start_mode: engine speed at ENG_OFF -> reset */
void test_hybrid_to_start_on_engine_speed_at_stall_boundary(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_HYBRID, 30.0f, 15.0f, 0.4f, 790.0f));
}

/* §Hybrid_mode: engine speed just above ENG_OFF -> remains Hybrid */
void test_hybrid_stays_on_engine_speed_just_above_stall(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, step(MODE_HYBRID, 30.0f, 15.0f, 0.4f, 790.01f));
}

/* §Start_mode->Hybrid_mode: SOC exactly at SOC_MID (0.30) -> Hybrid */
void test_start_to_hybrid_on_soc_at_mid_boundary(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, step(MODE_START, 35.01f, 0.0f, 0.30f, 1000.0f));
}

/* §Start_mode->ICE_mode: SOC just below SOC_MID -> ICE */
void test_start_to_ice_on_soc_just_below_mid(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_ICE, step(MODE_START, 35.01f, 0.0f, 0.299f, 1000.0f));
}

/* MC/DC for condition wEng > ENG_ON */
void test_mcdc_start_engine_running_condition(void)
{
    /* wEng == 800.0 (not > ENG_ON): no internal transition, stay START */
    TEST_ASSERT_EQUAL_INT(MODE_START,  step(MODE_START, 30.0f, 0.0f, 0.4f, 800.0f));
    /* wEng > ENG_ON, but (speed<=35 && P_dem<15) forces ICE (Hybrid guard fails) */
    TEST_ASSERT_EQUAL_INT(MODE_ICE,    step(MODE_START, 30.0f, 0.0f, 0.4f, 800.01f));
}

/* MC/DC for condition SOC >= SOC_MID (properly isolated with speed > 35) */
void test_mcdc_start_soc_mid_condition(void)
{
    /* SOC = 0.299 (< SOC_MID) -> ICE */
    TEST_ASSERT_EQUAL_INT(MODE_ICE,    step(MODE_START, 36.0f, 0.0f, 0.299f, 1000.0f));
    /* SOC = 0.30, speed > 35 -> Hybrid */
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, step(MODE_START, 36.0f, 0.0f, 0.30f, 1000.0f));
}

/* §Start_mode exits priority: Hybrid_mode before ICE_mode */
void test_mcdc_start_hybrid_priority_over_ice(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, step(MODE_START, 30.0f, 15.0f, 0.4f, 1000.0f));
}

/* §ICE_mode->Hybrid_mode: P_dem >= 15 and SOC >= 0.30 */
void test_ice_to_hybrid_on_conditions_met(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, step(MODE_ICE, 10.0f, 15.0f, 0.30f, 1000.0f));
}

/* §Hybrid_mode->ICE_mode: P_dem <= 10 or SOC < 0.25 */
void test_hybrid_to_ice_on_low_power(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_ICE, step(MODE_HYBRID, 10.0f, 10.0f, 0.4f, 1000.0f));
}

void test_hybrid_to_ice_on_low_soc(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_ICE, step(MODE_HYBRID, 10.0f, 20.0f, 0.249f, 1000.0f));
}

/* =========================================================================
 * GROUP E – Common Exits from Motion_mode_ICE (Model §Motion_mode_ICE external exits)
 * ========================================================================= */

/* §Motion_mode_ICE->RegenB_mode: priority 1 */
void test_ce01_to_regenb_priority(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, step(MODE_START, 50.0f, -5.0f, 0.5f, 2000.0f));
}

/* §Motion_mode_ICE->EV_mode: priority 2, when CE01 false */
void test_ce02_to_ev_when_ce01_false(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_EV, step(MODE_START, 15.0f, 10.0f, 0.5f, 2000.0f));
}

/* §Motion_mode_ICE->StandStill: priority 3 */
void test_ce03_to_standstill_when_others_false(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, step(MODE_START, 0.0f, 0.0f, 0.5f, 2000.0f));
}

/* External exit overrides internal Start transitions */
void test_common_exit_overrides_start_internal(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, step(MODE_START, 60.0f, -10.0f, 0.5f, 2000.0f));
}

/* MC/DC for EV->Motion_mode_ICE (via P_dem >= 50) */
void test_ev_to_start_by_pdem_only(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_EV, 40.0f, 50.0f, 0.5f, 0.0f));
}

/* MC/DC for RegenB->Motion_mode_ICE: P_dem >= 50 alone */
void test_regenb_to_start_c_only(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_START, step(MODE_REGENB, 10.0f, 50.0f, 0.5f, 0.0f));
}

/* §Motion_mode_ICE->EV_mode: speed <= SPEED_STOP blocks exit */
void test_ce02_speed_isolation(void)
{
    TEST_ASSERT_NOT_EQUAL_INT(MODE_EV, step(MODE_START, 0.0f, 10.0f, 0.5f, 2000.0f));
}

/* §Motion_mode_ICE->EV_mode: SOC <= SOC_EV_IN (0.37) blocks exit */
void test_ce02_soc_isolation(void)
{
    TEST_ASSERT_NOT_EQUAL_INT(MODE_EV, step(MODE_START, 40.0f, 10.0f, 0.369f, 2000.0f));
}

/* §Start_mode->ICE_mode: low SOC forces ICE */
void test_start_to_ice_branch_isolation(void)
{
    TEST_ASSERT_EQUAL_INT(MODE_ICE, step(MODE_START, 40.0f, 0.0f, 0.29f, 2000.0f));
}

/* =========================================================================
 * INTEGRATION TESTS – Multi‑step driving scenarios
 * ========================================================================= */

void test_urban_cycle_standstill_to_ev_to_standstill(void)
{
    Mode_t mode = MODE_STANDSTILL;
    mode = step(mode, 10.0f, 0.0f, 0.5f, 0.0f);
    TEST_ASSERT_EQUAL_INT(MODE_EV, mode);
    mode = step(mode, 0.0f, 0.0f, 0.5f, 0.0f);
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, mode);
}

void test_battery_degradation_ev_to_start_to_ice(void)
{
    Mode_t mode = MODE_EV;
    mode = step(mode, 10.0f, 0.0f, 0.34f, 0.0f);  // SOC < 0.35 -> START
    TEST_ASSERT_EQUAL_INT(MODE_START, mode);
    mode = step(mode, 10.0f, 0.0f, 0.2f, 1000.0f); // low SOC -> ICE
    TEST_ASSERT_EQUAL_INT(MODE_ICE, mode);
}

void test_full_acceleration_standstill_to_ev_to_start_to_hybrid(void)
{
    Mode_t mode = MODE_STANDSTILL;
    mode = step(mode, 10.0f, 0.0f, 0.5f, 0.0f);
    TEST_ASSERT_EQUAL_INT(MODE_EV, mode);
    mode = step(mode, 35.01f, 0.0f, 0.5f, 0.0f);
    TEST_ASSERT_EQUAL_INT(MODE_START, mode);
    mode = step(mode, 40.0f, 15.0f, 0.4f, 1000.0f);
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, mode);
}

void test_braking_ev_to_regenb_to_ev(void)
{
    Mode_t mode = MODE_EV;
    mode = step(mode, 10.0f, -5.0f, 0.5f, 0.0f);
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, mode);
    mode = step(mode, 10.0f, 0.0f, 0.5f, 0.0f);
    TEST_ASSERT_EQUAL_INT(MODE_EV, mode);
}

void test_braking_to_stop_ev_to_regenb_to_standstill(void)
{
    Mode_t mode = MODE_EV;
    mode = step(mode, 10.0f, -5.0f, 0.5f, 0.0f);
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, mode);
    mode = step(mode, 0.5f, -5.0f, 0.5f, 0.0f);
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, mode);
}

void test_engine_restart_ice_to_start_to_hybrid(void)
{
    Mode_t mode = MODE_ICE;
    /* ICE -> START (engine stalled) */
    mode = step(mode, 10.0f, 0.0f, 0.5f, 790.0f);
    TEST_ASSERT_EQUAL_INT(MODE_START, mode);
    /* START -> HYBRID: engine running, speed > 35 triggers Hybrid */
    mode = step(mode, 36.0f, 0.0f, 0.5f, 800.01f);
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, mode);
}

/* Main function for Unity test runner */
int main(void)
{
    UNITY_BEGIN();
    
    /* GROUP A - StandStill transitions */
    RUN_TEST(test_standstill_stays_when_vehicle_stopped);
    RUN_TEST(test_standstill_to_ev_nominal_conditions);
    RUN_TEST(test_standstill_to_ev_on_speed_just_above_stop);
    RUN_TEST(test_standstill_to_ev_on_soc_at_entry_boundary);
    RUN_TEST(test_standstill_to_start_on_soc_just_below_entry);
    RUN_TEST(test_standstill_to_ev_on_speed_at_ev_max);
    RUN_TEST(test_standstill_to_start_on_speed_just_above_ev_max);
    RUN_TEST(test_mcdc_standstill_speed_stop_condition);
    RUN_TEST(test_mcdc_standstill_speed_ev_max_condition);
    RUN_TEST(test_mcdc_standstill_soc_condition);
    RUN_TEST(test_mcdc_standstill_power_demand_condition);
    
    /* GROUP B - EV transitions */
    RUN_TEST(test_ev_to_regenb_on_braking_demand_boundary);
    RUN_TEST(test_ev_to_regenb_speed_above_regen);
    RUN_TEST(test_ev_stays_at_speed_regen_boundary);
    RUN_TEST(test_ev_to_standstill_on_speed_at_stop_boundary);
    RUN_TEST(test_ev_stays_on_speed_just_above_stop_boundary);
    RUN_TEST(test_ev_to_start_on_soc_just_below_sustain);
    RUN_TEST(test_ev_to_start_on_speed_just_above_ev_max);
    RUN_TEST(test_mcdc_ev_regenb_priority_over_start);
    RUN_TEST(test_mcdc_ev_high_power_blocks_standstill);
    RUN_TEST(test_mcdc_ev_negative_power_blocks_standstill);
    RUN_TEST(test_mcdc_ev_low_soc_does_not_block_regenb);
    RUN_TEST(test_ev_to_standstill_on_power_demand_at_neutral_stop_max_boundary);
    
    /* GROUP C - RegenB transitions */
    RUN_TEST(test_regenb_to_standstill_on_speed_at_stop_boundary);
    RUN_TEST(test_regenb_stays_on_speed_just_above_stop_boundary);
    RUN_TEST(test_regenb_to_start_on_soc_just_below_entry);
    RUN_TEST(test_regenb_to_ev_on_power_demand_at_regen_exit_boundary);
    RUN_TEST(test_regenb_to_ev_nominal);
    RUN_TEST(test_mcdc_regenb_start_priority_over_standstill);
    RUN_TEST(test_mcdc_regenb_start_priority_over_ev);
    RUN_TEST(test_mcdc_regenb_standstill_priority_over_ev);
    RUN_TEST(test_regenb_to_start_on_high_speed_no_braking);
    RUN_TEST(test_mcdc_regenb_start_clause_speed_demand_combo);
    RUN_TEST(test_mcdc_regenb_start_clause_high_demand_only);
    
    /* GROUP D - Motion_mode_ICE internal transitions */
    RUN_TEST(test_start_to_hybrid_on_speed_just_above_ev_max);
    RUN_TEST(test_start_to_hybrid_on_power_demand_at_hybrid_boundary);
    RUN_TEST(test_ice_to_start_on_engine_speed_at_stall_boundary);
    RUN_TEST(test_ice_stays_on_engine_speed_just_above_stall);
    RUN_TEST(test_hybrid_to_start_on_engine_speed_at_stall_boundary);
    RUN_TEST(test_hybrid_stays_on_engine_speed_just_above_stall);
    RUN_TEST(test_start_to_hybrid_on_soc_at_mid_boundary);
    RUN_TEST(test_start_to_ice_on_soc_just_below_mid);
    RUN_TEST(test_mcdc_start_engine_running_condition);
    RUN_TEST(test_mcdc_start_soc_mid_condition);
    RUN_TEST(test_mcdc_start_hybrid_priority_over_ice);
    RUN_TEST(test_ice_to_hybrid_on_conditions_met);
    RUN_TEST(test_hybrid_to_ice_on_low_power);
    RUN_TEST(test_hybrid_to_ice_on_low_soc);
    
    /* GROUP E - Common exits */
    RUN_TEST(test_ce01_to_regenb_priority);
    RUN_TEST(test_ce02_to_ev_when_ce01_false);
    RUN_TEST(test_ce03_to_standstill_when_others_false);
    RUN_TEST(test_common_exit_overrides_start_internal);
    RUN_TEST(test_ev_to_start_by_pdem_only);
    RUN_TEST(test_regenb_to_start_c_only);
    RUN_TEST(test_ce02_speed_isolation);
    RUN_TEST(test_ce02_soc_isolation);
    RUN_TEST(test_start_to_ice_branch_isolation);
    
    /* Integration tests */
    RUN_TEST(test_urban_cycle_standstill_to_ev_to_standstill);
    RUN_TEST(test_battery_degradation_ev_to_start_to_ice);
    RUN_TEST(test_full_acceleration_standstill_to_ev_to_start_to_hybrid);
    RUN_TEST(test_braking_ev_to_regenb_to_ev);
    RUN_TEST(test_braking_to_stop_ev_to_regenb_to_standstill);
    RUN_TEST(test_engine_restart_ice_to_start_to_hybrid);
    
    return UNITY_END();
}