/* =========================================================================
 * Unit tests - Person E (Gustavo)
 *
 * Coverage for the requirements assigned in
 * doc/mapeamento_transicoes_secao4_por_responsavel.md
 *
 *   Section 4.2:
 *     SwHLR06 - Priority: external transitions before internal ones in the
 *               Motion_mode_ICE (Start, ICE, Hybrid).
 *     SwHLR08 - (shared) internal transitions from ICE.
 *     SwHLR09 - (shared) internal transitions from Hybrid.
 *
 *   Section 4.3:
 *     SwLLR09 - Start   -> RegenB
 *     SwLLR10 - ICE     -> RegenB
 *     SwLLR11 - Hybrid  -> RegenB
 *     SwLLR12 - Start   -> EV
 *     SwLLR13 - ICE     -> EV
 *     SwLLR14 - Hybrid  -> EV
 *     SwLLR15 - Start   -> StandStill
 *     SwLLR16 - ICE     -> StandStill
 *     SwLLR17 - Hybrid  -> StandStill
 *     SwLLR21 - ICE     -> Hybrid
 *     SwLLR23 - Hybrid  -> ICE
 *
 * Coverage strategy:
 *   - Each requirement has a positive case where the transition occurs.
 *   - For MC/DC, each condition in the decision has one case where that
 *     condition alone changes the decision result while the other conditions
 *     are held true.
 *   - OR rules (SwLLR23) cover both branches.
 *   - Priority tests (SwHLR06/08/09) verify that evaluation follows the
 *     order expected by the model.
 * ========================================================================= */

#include "unity.h"
#include "mode_logic_team.h"

/* ---------------------- fixtures ----------------------------------------- */

static State_t   g_state;
static Outputs_t g_out;

void setUp(void)
{
    ModeLogic_Init(&g_state);
    g_out.Mot_Enable = 0U;
    g_out.Gen_Enable = 0U;
    g_out.ICE_Enable = 0U;
}

void tearDown(void)
{
}

/* Runs one step from a declared initial mode and returns the next mode
 * calculated by the state machine. */
static Mode_t step_from(Mode_t start_mode, Inputs_t in)
{
    g_state.current_mode = start_mode;
    ModeLogic_Step(&g_state, &in, &g_out);
    return g_state.current_mode;
}

/* Helper to build inputs in one line. */
static Inputs_t make_inputs(float speed, float P_dem, float SOC, float wEng)
{
    Inputs_t in;
    in.speed = speed;
    in.P_dem = P_dem;
    in.SOC   = SOC;
    in.wEng  = wEng;
    return in;
}

/* ========================================================================= *
 *  Sanity
 * ========================================================================= */

void test_ModeLogic_Init_sets_standstill(void)
{
    State_t s;
    s.current_mode = MODE_HYBRID; /* dirty */
    ModeLogic_Init(&s);
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, s.current_mode);
}

void test_ModeLogic_Init_tolerates_null(void)
{
    /* Must not crash. */
    ModeLogic_Init(NULL);
    TEST_PASS();
}

void test_ModeLogic_Step_tolerates_null_args(void)
{
    State_t  s; s.current_mode = MODE_ICE;
    Inputs_t in = make_inputs(10.0f, 20.0f, 0.5f, 900.0f);
    Outputs_t out = {0};

    ModeLogic_Step(NULL, &in, &out);
    ModeLogic_Step(&s,   NULL, &out);
    ModeLogic_Step(&s,   &in,  NULL);

    /* State does not change when a pointer is null. */
    TEST_ASSERT_EQUAL_INT(MODE_ICE, s.current_mode);
}

/* ========================================================================= *
 *  SwLLR09 - Start -> RegenB
 *    Guard: wEng > ENG_ON && speed > SPEED_REGEN && P_dem <= PDEM_REGEN
 * ========================================================================= */

/* positive case (TTT) */
void test_SwLLR09_Start_to_RegenB_positive(void)
{
    Inputs_t in = make_inputs(10.0f, -10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, next);
}

/* MC/DC - false wEng condition (FTT) */
void test_SwLLR09_Start_blocked_by_wEng_not_over_ENG_ON(void)
{
    /* wEng = 800.0 does not satisfy wEng > ENG_ON (strictly greater). */
    Inputs_t in = make_inputs(10.0f, -10.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_NOT_EQUAL(MODE_REGENB, next);
}

/* MC/DC - false speed condition (TFT) */
void test_SwLLR09_Start_blocked_by_speed_not_over_SPEED_REGEN(void)
{
    Inputs_t in = make_inputs(5.0f, -10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_NOT_EQUAL(MODE_REGENB, next);
}

/* MC/DC - false P_dem condition (TTF) */
void test_SwLLR09_Start_blocked_by_P_dem_not_under_PDEM_REGEN(void)
{
    Inputs_t in = make_inputs(10.0f, -4.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_NOT_EQUAL(MODE_REGENB, next);
}

/* ========================================================================= *
 *  SwLLR10 - ICE -> RegenB
 * ========================================================================= */

void test_SwLLR10_ICE_to_RegenB_positive(void)
{
    Inputs_t in = make_inputs(10.0f, -10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, next);
}

void test_SwLLR10_ICE_blocked_by_wEng(void)
{
    Inputs_t in = make_inputs(10.0f, -10.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_REGENB, next);
}

void test_SwLLR10_ICE_blocked_by_speed(void)
{
    Inputs_t in = make_inputs(5.0f, -10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_REGENB, next);
}

void test_SwLLR10_ICE_blocked_by_P_dem(void)
{
    Inputs_t in = make_inputs(10.0f, -4.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_REGENB, next);
}

/* ========================================================================= *
 *  SwLLR11 - Hybrid -> RegenB
 * ========================================================================= */

void test_SwLLR11_Hybrid_to_RegenB_positive(void)
{
    Inputs_t in = make_inputs(10.0f, -10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, next);
}

void test_SwLLR11_Hybrid_blocked_by_wEng(void)
{
    Inputs_t in = make_inputs(10.0f, -10.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_NOT_EQUAL(MODE_REGENB, next);
}

void test_SwLLR11_Hybrid_blocked_by_speed(void)
{
    Inputs_t in = make_inputs(5.0f, -10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_NOT_EQUAL(MODE_REGENB, next);
}

void test_SwLLR11_Hybrid_blocked_by_P_dem(void)
{
    Inputs_t in = make_inputs(10.0f, -4.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_NOT_EQUAL(MODE_REGENB, next);
}

/* ========================================================================= *
 *  SwLLR12 - Start -> EV
 *    Guard: wEng > ENG_ON && P_dem <= PDEM_HYB_OUT && P_dem >= PDEM_STOP_LOW
 *            && speed > SPEED_STOP && speed <= SPEED_EV_MAX && SOC >= SOC_EV_IN
 * ========================================================================= */

void test_SwLLR12_Start_to_EV_positive(void)
{
    Inputs_t in = make_inputs(20.0f, 10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_EQUAL_INT(MODE_EV, next);
}

void test_SwLLR12_Start_EV_blocked_by_wEng(void)
{
    Inputs_t in = make_inputs(20.0f, 10.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR12_Start_EV_blocked_by_P_dem_over_HYB_OUT(void)
{
    Inputs_t in = make_inputs(20.0f, 45.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR12_Start_EV_blocked_by_P_dem_under_STOP_LOW(void)
{
    Inputs_t in = make_inputs(20.0f, -3.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR12_Start_EV_blocked_by_speed_not_over_SPEED_STOP(void)
{
    Inputs_t in = make_inputs(0.3f, 10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR12_Start_EV_blocked_by_speed_over_SPEED_EV_MAX(void)
{
    Inputs_t in = make_inputs(40.0f, 10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR12_Start_EV_blocked_by_SOC_under_SOC_EV_IN(void)
{
    Inputs_t in = make_inputs(20.0f, 10.0f, 0.36f, 900.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

/* ========================================================================= *
 *  SwLLR13 - ICE -> EV
 * ========================================================================= */

void test_SwLLR13_ICE_to_EV_positive(void)
{
    Inputs_t in = make_inputs(20.0f, 10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_INT(MODE_EV, next);
}

void test_SwLLR13_ICE_EV_blocked_by_wEng(void)
{
    Inputs_t in = make_inputs(20.0f, 10.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR13_ICE_EV_blocked_by_P_dem_over_HYB_OUT(void)
{
    Inputs_t in = make_inputs(20.0f, 45.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR13_ICE_EV_blocked_by_P_dem_under_STOP_LOW(void)
{
    Inputs_t in = make_inputs(20.0f, -3.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR13_ICE_EV_blocked_by_speed_not_over_SPEED_STOP(void)
{
    Inputs_t in = make_inputs(0.3f, 10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR13_ICE_EV_blocked_by_speed_over_SPEED_EV_MAX(void)
{
    Inputs_t in = make_inputs(40.0f, 10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR13_ICE_EV_blocked_by_SOC_under_SOC_EV_IN(void)
{
    Inputs_t in = make_inputs(20.0f, 10.0f, 0.36f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

/* ========================================================================= *
 *  SwLLR14 - Hybrid -> EV
 * ========================================================================= */

void test_SwLLR14_Hybrid_to_EV_positive(void)
{
    Inputs_t in = make_inputs(20.0f, 10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_INT(MODE_EV, next);
}

void test_SwLLR14_Hybrid_EV_blocked_by_wEng(void)
{
    Inputs_t in = make_inputs(20.0f, 10.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR14_Hybrid_EV_blocked_by_P_dem_over_HYB_OUT(void)
{
    Inputs_t in = make_inputs(20.0f, 45.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR14_Hybrid_EV_blocked_by_P_dem_under_STOP_LOW(void)
{
    Inputs_t in = make_inputs(20.0f, -3.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR14_Hybrid_EV_blocked_by_speed_not_over_SPEED_STOP(void)
{
    Inputs_t in = make_inputs(0.3f, 10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR14_Hybrid_EV_blocked_by_speed_over_SPEED_EV_MAX(void)
{
    Inputs_t in = make_inputs(40.0f, 10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

void test_SwLLR14_Hybrid_EV_blocked_by_SOC_under_SOC_EV_IN(void)
{
    Inputs_t in = make_inputs(20.0f, 10.0f, 0.36f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
}

/* ========================================================================= *
 *  SwLLR15 - Start -> StandStill
 *    Guard: speed <= SPEED_STOP && P_dem <= PDEM_STOP_HIGH
 *            && P_dem >= PDEM_STOP_LOW
 *
 *  Note: negative cases use wEng = 800 (not > ENG_ON) so Regen and EV
 *        cannot be triggered for unrelated reasons.
 * ========================================================================= */

void test_SwLLR15_Start_to_StandStill_positive(void)
{
    Inputs_t in = make_inputs(0.3f, 0.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, next);
}

void test_SwLLR15_Start_StandStill_blocked_by_speed_over_SPEED_STOP(void)
{
    Inputs_t in = make_inputs(1.0f, 0.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_NOT_EQUAL(MODE_STANDSTILL, next);
}

void test_SwLLR15_Start_StandStill_blocked_by_P_dem_over_STOP_HIGH(void)
{
    Inputs_t in = make_inputs(0.3f, 2.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_NOT_EQUAL(MODE_STANDSTILL, next);
}

void test_SwLLR15_Start_StandStill_blocked_by_P_dem_under_STOP_LOW(void)
{
    Inputs_t in = make_inputs(0.3f, -2.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_NOT_EQUAL(MODE_STANDSTILL, next);
}

/* ========================================================================= *
 *  SwLLR16 - ICE -> StandStill
 * ========================================================================= */

void test_SwLLR16_ICE_to_StandStill_positive(void)
{
    Inputs_t in = make_inputs(0.3f, 0.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, next);
}

void test_SwLLR16_ICE_StandStill_blocked_by_speed_over_SPEED_STOP(void)
{
    Inputs_t in = make_inputs(1.0f, 0.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_STANDSTILL, next);
}

void test_SwLLR16_ICE_StandStill_blocked_by_P_dem_over_STOP_HIGH(void)
{
    Inputs_t in = make_inputs(0.3f, 2.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_STANDSTILL, next);
}

void test_SwLLR16_ICE_StandStill_blocked_by_P_dem_under_STOP_LOW(void)
{
    Inputs_t in = make_inputs(0.3f, -2.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_STANDSTILL, next);
}

/* ========================================================================= *
 *  SwLLR17 - Hybrid -> StandStill
 * ========================================================================= */

void test_SwLLR17_Hybrid_to_StandStill_positive(void)
{
    Inputs_t in = make_inputs(0.3f, 0.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, next);
}

void test_SwLLR17_Hybrid_StandStill_blocked_by_speed_over_SPEED_STOP(void)
{
    Inputs_t in = make_inputs(1.0f, 0.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_NOT_EQUAL(MODE_STANDSTILL, next);
}

void test_SwLLR17_Hybrid_StandStill_blocked_by_P_dem_over_STOP_HIGH(void)
{
    Inputs_t in = make_inputs(0.3f, 2.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_NOT_EQUAL(MODE_STANDSTILL, next);
}

void test_SwLLR17_Hybrid_StandStill_blocked_by_P_dem_under_STOP_LOW(void)
{
    Inputs_t in = make_inputs(0.3f, -2.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_NOT_EQUAL(MODE_STANDSTILL, next);
}

/* ========================================================================= *
 *  SwLLR21 - ICE -> Hybrid
 *    Guard: P_dem >= PDEM_HYB_MID && SOC >= SOC_MID
 *    (evaluated after external transitions and reset fail)
 *
 *    To isolate the guard, use speed=40 (blocks EV/Standstill by speed)
 *    and wEng=900 (prevents reset).
 * ========================================================================= */

void test_SwLLR21_ICE_to_Hybrid_positive(void)
{
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, next);
}

void test_SwLLR21_ICE_Hybrid_blocked_by_P_dem_under_HYB_MID(void)
{
    /* P_dem below PDEM_HYB_MID blocks ICE->Hybrid, so it stays in ICE. */
    Inputs_t in = make_inputs(40.0f, 12.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_INT(MODE_ICE, next);
}

void test_SwLLR21_ICE_Hybrid_blocked_by_SOC_under_SOC_MID(void)
{
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.29f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_INT(MODE_ICE, next);
}

/* ========================================================================= *
 *  SwLLR23 - Hybrid -> ICE
 *    Guard: P_dem <= PDEM_HYB_LOW || SOC < SOC_LOW
 *    (OR - both branches tested)
 * ========================================================================= */

/* positive branch A: low P_dem */
void test_SwLLR23_Hybrid_to_ICE_positive_low_P_dem(void)
{
    Inputs_t in = make_inputs(40.0f, 5.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_INT(MODE_ICE, next);
}

/* positive branch B: low SOC */
void test_SwLLR23_Hybrid_to_ICE_positive_low_SOC(void)
{
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.20f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_INT(MODE_ICE, next);
}

/* negative case: both conditions are false, so it stays in Hybrid. */
void test_SwLLR23_Hybrid_stays_when_both_conditions_false(void)
{
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, next);
}

/* ========================================================================= *
 *  SwHLR06 - external transitions are evaluated before internal transitions
 *
 *  Case where both external and internal guards are TRUE: the external one
 *  must win.
 * ========================================================================= */

/* In ICE: the EV guard (external) and ICE->Hybrid guard (internal) are both
 * true. The external EV transition must win. */
void test_SwHLR06_ICE_external_EV_beats_internal_Hybrid(void)
{
    /* P_dem = 20 satisfies EV (>=-1, <=40) and Hybrid (>=15).
     * SOC=0.5 satisfies EV (>=0.37) and Hybrid (>=0.30). */
    Inputs_t in = make_inputs(10.0f, 20.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_INT(MODE_EV, next);
}

/* In Hybrid: the EV guard (external) and Hybrid->ICE guard (internal) are
 * true. The external EV transition must win. */
void test_SwHLR06_Hybrid_external_EV_beats_internal_ICE(void)
{
    /* P_dem = 5 satisfies Hybrid->ICE (<=10) and EV (>=-1 && <=40). */
    Inputs_t in = make_inputs(10.0f, 5.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_INT(MODE_EV, next);
}

/* In Start: the external Regen guard and the internal Start->Hybrid guard
 * are true. The external transition must win.
 * Regen: wEng>800, speed>5, P_dem<=-5.
 * Start->Hybrid: wEng>800, SOC>=0.30, (speed>35 or P_dem>=15).
 * Use speed=40 (satisfies speed>35 for Hybrid and speed>5 for Regen) and
 * P_dem=-10 (satisfies Regen). */
void test_SwHLR06_Start_external_Regen_beats_internal_Hybrid(void)
{
    Inputs_t in = make_inputs(40.0f, -10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, next);
}

/* In ICE: combining the external StandStill guard and internal ICE->Hybrid
 * guard is not possible. Hybrid needs P_dem>=15 and StandStill needs
 * P_dem<=1, so this combination is intentionally omitted. */

/* In Hybrid: external StandStill vs. internal Hybrid->ICE by P_dem<=10.
 *   speed=0.3, P_dem=0 -> StandStill TRUE; Hybrid->ICE (P_dem<=10) TRUE.
 *   StandStill must win. */
void test_SwHLR06_Hybrid_external_StandStill_beats_internal_ICE(void)
{
    Inputs_t in = make_inputs(0.3f, 0.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, next);
}

/* ========================================================================= *
 *  SwHLR08 - In ICE, reset to Start has priority over ICE->Hybrid.
 *
 *  (Requirement shared with Person D, but the priority evaluation between
 *  internal and external/reset paths also crosses the Person E scope, so it
 *  is validated here.)
 * ========================================================================= */

void test_SwHLR08_ICE_reset_to_Start_beats_ICE_to_Hybrid(void)
{
    /* wEng = 700 (<=ENG_OFF) -> reset. P_dem=20 and SOC=0.5 would allow
     * ICE->Hybrid, but reset must win. External transitions do not fire
     * because wEng<=800. */
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.5f, 700.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_INT(MODE_START, next);
}

/* ========================================================================= *
 *  SwHLR09 - In Hybrid, reset to Start has priority over Hybrid->ICE.
 * ========================================================================= */

void test_SwHLR09_Hybrid_reset_to_Start_beats_Hybrid_to_ICE(void)
{
    /* wEng = 700 resets. P_dem=5 would also satisfy Hybrid->ICE, but reset
     * wins. */
    Inputs_t in = make_inputs(40.0f, 5.0f, 0.5f, 700.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_INT(MODE_START, next);
}

/* ========================================================================= *
 *  Auxiliary external/internal priority case in Start with low SOC.
 *
 *  Goal: when no external transition fires in Start and SOC is below SOC_MID,
 *  the logic must fall through to the internal reset/ICE transition
 *  (Person D), not to an unintended external transition. This case also
 *  covers the SOC<SOC_MID boundary of the Start family shared with Person D.
 * ========================================================================= */

void test_SwHLR06_Start_with_low_SOC_no_external_goes_to_internal(void)
{
    /* SOC=0.25 blocks EV (needs SOC>=0.37) and Start->Hybrid
     * (needs SOC>=0.30). Regen and Standstill are already blocked by
     * speed/P_dem. */
    Inputs_t in = make_inputs(10.0f, 0.0f, 0.25f, 900.0f);
    Mode_t next = step_from(MODE_START, in);
    /* No external transition fired; it falls through to the internal path. */
    TEST_ASSERT_NOT_EQUAL(MODE_REGENB, next);
    TEST_ASSERT_NOT_EQUAL(MODE_EV, next);
    TEST_ASSERT_NOT_EQUAL(MODE_STANDSTILL, next);
}

/* ========================================================================= *
 *  Output mapping for the modes touched by Person E.
 *  Checks `Mot_Enable`, `Gen_Enable`, and `ICE_Enable` after the transition.
 * ========================================================================= */

void test_outputs_after_transition_to_RegenB(void)
{
    Inputs_t in = make_inputs(10.0f, -10.0f, 0.5f, 900.0f);
    (void)step_from(MODE_START, in);
    TEST_ASSERT_EQUAL_UINT8(1U, g_out.Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(0U, g_out.Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(0U, g_out.ICE_Enable);
}

void test_outputs_after_transition_to_EV(void)
{
    Inputs_t in = make_inputs(20.0f, 10.0f, 0.5f, 900.0f);
    (void)step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_UINT8(1U, g_out.Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(0U, g_out.Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(0U, g_out.ICE_Enable);
}

void test_outputs_after_transition_to_StandStill(void)
{
    Inputs_t in = make_inputs(0.3f, 0.0f, 0.5f, 900.0f);
    (void)step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_UINT8(0U, g_out.Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(0U, g_out.Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(0U, g_out.ICE_Enable);
}

void test_outputs_after_transition_to_Hybrid(void)
{
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.5f, 900.0f);
    (void)step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_UINT8(1U, g_out.Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(1U, g_out.Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(1U, g_out.ICE_Enable);
}

void test_outputs_after_transition_to_ICE(void)
{
    Inputs_t in = make_inputs(40.0f, 5.0f, 0.5f, 900.0f);
    (void)step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_UINT8(0U, g_out.Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(1U, g_out.Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(1U, g_out.ICE_Enable);
}

/* ========================================================================= *
 *  Boundaries (exact thresholds)
 *  Important to show that the correct operator (strictly greater vs.
 *  greater-than-or-equal) is implemented.
 * ========================================================================= */

/* wEng exactly at ENG_ON does not satisfy wEng > ENG_ON. Regen does not fire. */
void test_boundary_wEng_equal_ENG_ON_blocks_Regen(void)
{
    Inputs_t in = make_inputs(10.0f, -10.0f, 0.5f, 800.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_REGENB, next);
}

/* speed exactly at SPEED_REGEN does not satisfy speed > SPEED_REGEN. */
void test_boundary_speed_equal_SPEED_REGEN_blocks_Regen(void)
{
    Inputs_t in = make_inputs(5.0f, -10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_NOT_EQUAL(MODE_REGENB, next);
}

/* P_dem exactly at PDEM_REGEN satisfies P_dem <= PDEM_REGEN (inclusive edge). */
void test_boundary_P_dem_equal_PDEM_REGEN_allows_Regen(void)
{
    Inputs_t in = make_inputs(10.0f, -5.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, next);
}

/* speed exactly at SPEED_EV_MAX (=35) satisfies speed <= SPEED_EV_MAX (EV). */
void test_boundary_speed_equal_SPEED_EV_MAX_allows_EV(void)
{
    Inputs_t in = make_inputs(35.0f, 10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_INT(MODE_EV, next);
}

/* speed exactly at SPEED_STOP (=0.5) satisfies speed <= SPEED_STOP. */
void test_boundary_speed_equal_SPEED_STOP_allows_StandStill(void)
{
    Inputs_t in = make_inputs(0.5f, 0.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, next);
}

/* P_dem = PDEM_STOP_LOW (=-1) satisfies P_dem >= PDEM_STOP_LOW. */
void test_boundary_P_dem_equal_STOP_LOW_allows_StandStill(void)
{
    Inputs_t in = make_inputs(0.3f, -1.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, next);
}

/* SOC = SOC_EV_IN (=0.37) satisfies SOC >= SOC_EV_IN (EV). */
void test_boundary_SOC_equal_SOC_EV_IN_allows_EV(void)
{
    Inputs_t in = make_inputs(20.0f, 10.0f, 0.37f, 900.0f);
    Mode_t next = step_from(MODE_START, in);
    TEST_ASSERT_EQUAL_INT(MODE_EV, next);
}

/* P_dem = PDEM_HYB_MID (=15) satisfies P_dem >= PDEM_HYB_MID (ICE->Hybrid). */
void test_boundary_P_dem_equal_HYB_MID_allows_ICE_to_Hybrid(void)
{
    Inputs_t in = make_inputs(40.0f, 15.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_ICE, in);
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, next);
}

/* P_dem = PDEM_HYB_LOW (=10) satisfies P_dem <= PDEM_HYB_LOW (Hybrid->ICE). */
void test_boundary_P_dem_equal_HYB_LOW_allows_Hybrid_to_ICE(void)
{
    Inputs_t in = make_inputs(40.0f, 10.0f, 0.5f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_INT(MODE_ICE, next);
}

/* SOC = SOC_LOW (=0.25) does not satisfy SOC < SOC_LOW (exclusive edge). */
void test_boundary_SOC_equal_SOC_LOW_blocks_Hybrid_to_ICE_via_SOC(void)
{
    /* High P_dem prevents branch A. If branch B fired on the boundary alone,
     * the transition would occur. With SOC=0.25, SOC<0.25 is false, so both
     * branches fail and the mode must stay Hybrid. */
    Inputs_t in = make_inputs(40.0f, 20.0f, 0.25f, 900.0f);
    Mode_t next = step_from(MODE_HYBRID, in);
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, next);
}

/* ========================================================================= *
 *  Test runner
 * ========================================================================= */

int main(void)
{
    UNITY_BEGIN();

    /* Sanity */
    RUN_TEST(test_ModeLogic_Init_sets_standstill);
    RUN_TEST(test_ModeLogic_Init_tolerates_null);
    RUN_TEST(test_ModeLogic_Step_tolerates_null_args);

    /* SwLLR09 */
    RUN_TEST(test_SwLLR09_Start_to_RegenB_positive);
    RUN_TEST(test_SwLLR09_Start_blocked_by_wEng_not_over_ENG_ON);
    RUN_TEST(test_SwLLR09_Start_blocked_by_speed_not_over_SPEED_REGEN);
    RUN_TEST(test_SwLLR09_Start_blocked_by_P_dem_not_under_PDEM_REGEN);

    /* SwLLR10 */
    RUN_TEST(test_SwLLR10_ICE_to_RegenB_positive);
    RUN_TEST(test_SwLLR10_ICE_blocked_by_wEng);
    RUN_TEST(test_SwLLR10_ICE_blocked_by_speed);
    RUN_TEST(test_SwLLR10_ICE_blocked_by_P_dem);

    /* SwLLR11 */
    RUN_TEST(test_SwLLR11_Hybrid_to_RegenB_positive);
    RUN_TEST(test_SwLLR11_Hybrid_blocked_by_wEng);
    RUN_TEST(test_SwLLR11_Hybrid_blocked_by_speed);
    RUN_TEST(test_SwLLR11_Hybrid_blocked_by_P_dem);

    /* SwLLR12 */
    RUN_TEST(test_SwLLR12_Start_to_EV_positive);
    RUN_TEST(test_SwLLR12_Start_EV_blocked_by_wEng);
    RUN_TEST(test_SwLLR12_Start_EV_blocked_by_P_dem_over_HYB_OUT);
    RUN_TEST(test_SwLLR12_Start_EV_blocked_by_P_dem_under_STOP_LOW);
    RUN_TEST(test_SwLLR12_Start_EV_blocked_by_speed_not_over_SPEED_STOP);
    RUN_TEST(test_SwLLR12_Start_EV_blocked_by_speed_over_SPEED_EV_MAX);
    RUN_TEST(test_SwLLR12_Start_EV_blocked_by_SOC_under_SOC_EV_IN);

    /* SwLLR13 */
    RUN_TEST(test_SwLLR13_ICE_to_EV_positive);
    RUN_TEST(test_SwLLR13_ICE_EV_blocked_by_wEng);
    RUN_TEST(test_SwLLR13_ICE_EV_blocked_by_P_dem_over_HYB_OUT);
    RUN_TEST(test_SwLLR13_ICE_EV_blocked_by_P_dem_under_STOP_LOW);
    RUN_TEST(test_SwLLR13_ICE_EV_blocked_by_speed_not_over_SPEED_STOP);
    RUN_TEST(test_SwLLR13_ICE_EV_blocked_by_speed_over_SPEED_EV_MAX);
    RUN_TEST(test_SwLLR13_ICE_EV_blocked_by_SOC_under_SOC_EV_IN);

    /* SwLLR14 */
    RUN_TEST(test_SwLLR14_Hybrid_to_EV_positive);
    RUN_TEST(test_SwLLR14_Hybrid_EV_blocked_by_wEng);
    RUN_TEST(test_SwLLR14_Hybrid_EV_blocked_by_P_dem_over_HYB_OUT);
    RUN_TEST(test_SwLLR14_Hybrid_EV_blocked_by_P_dem_under_STOP_LOW);
    RUN_TEST(test_SwLLR14_Hybrid_EV_blocked_by_speed_not_over_SPEED_STOP);
    RUN_TEST(test_SwLLR14_Hybrid_EV_blocked_by_speed_over_SPEED_EV_MAX);
    RUN_TEST(test_SwLLR14_Hybrid_EV_blocked_by_SOC_under_SOC_EV_IN);

    /* SwLLR15 */
    RUN_TEST(test_SwLLR15_Start_to_StandStill_positive);
    RUN_TEST(test_SwLLR15_Start_StandStill_blocked_by_speed_over_SPEED_STOP);
    RUN_TEST(test_SwLLR15_Start_StandStill_blocked_by_P_dem_over_STOP_HIGH);
    RUN_TEST(test_SwLLR15_Start_StandStill_blocked_by_P_dem_under_STOP_LOW);

    /* SwLLR16 */
    RUN_TEST(test_SwLLR16_ICE_to_StandStill_positive);
    RUN_TEST(test_SwLLR16_ICE_StandStill_blocked_by_speed_over_SPEED_STOP);
    RUN_TEST(test_SwLLR16_ICE_StandStill_blocked_by_P_dem_over_STOP_HIGH);
    RUN_TEST(test_SwLLR16_ICE_StandStill_blocked_by_P_dem_under_STOP_LOW);

    /* SwLLR17 */
    RUN_TEST(test_SwLLR17_Hybrid_to_StandStill_positive);
    RUN_TEST(test_SwLLR17_Hybrid_StandStill_blocked_by_speed_over_SPEED_STOP);
    RUN_TEST(test_SwLLR17_Hybrid_StandStill_blocked_by_P_dem_over_STOP_HIGH);
    RUN_TEST(test_SwLLR17_Hybrid_StandStill_blocked_by_P_dem_under_STOP_LOW);

    /* SwLLR21 */
    RUN_TEST(test_SwLLR21_ICE_to_Hybrid_positive);
    RUN_TEST(test_SwLLR21_ICE_Hybrid_blocked_by_P_dem_under_HYB_MID);
    RUN_TEST(test_SwLLR21_ICE_Hybrid_blocked_by_SOC_under_SOC_MID);

    /* SwLLR23 */
    RUN_TEST(test_SwLLR23_Hybrid_to_ICE_positive_low_P_dem);
    RUN_TEST(test_SwLLR23_Hybrid_to_ICE_positive_low_SOC);
    RUN_TEST(test_SwLLR23_Hybrid_stays_when_both_conditions_false);

    /* SwHLR06/08/09 */
    RUN_TEST(test_SwHLR06_ICE_external_EV_beats_internal_Hybrid);
    RUN_TEST(test_SwHLR06_Hybrid_external_EV_beats_internal_ICE);
    RUN_TEST(test_SwHLR06_Start_external_Regen_beats_internal_Hybrid);
    RUN_TEST(test_SwHLR06_Hybrid_external_StandStill_beats_internal_ICE);
    RUN_TEST(test_SwHLR08_ICE_reset_to_Start_beats_ICE_to_Hybrid);
    RUN_TEST(test_SwHLR09_Hybrid_reset_to_Start_beats_Hybrid_to_ICE);
    RUN_TEST(test_SwHLR06_Start_with_low_SOC_no_external_goes_to_internal);

    /* Outputs */
    RUN_TEST(test_outputs_after_transition_to_RegenB);
    RUN_TEST(test_outputs_after_transition_to_EV);
    RUN_TEST(test_outputs_after_transition_to_StandStill);
    RUN_TEST(test_outputs_after_transition_to_Hybrid);
    RUN_TEST(test_outputs_after_transition_to_ICE);

    /* Boundaries */
    RUN_TEST(test_boundary_wEng_equal_ENG_ON_blocks_Regen);
    RUN_TEST(test_boundary_speed_equal_SPEED_REGEN_blocks_Regen);
    RUN_TEST(test_boundary_P_dem_equal_PDEM_REGEN_allows_Regen);
    RUN_TEST(test_boundary_speed_equal_SPEED_EV_MAX_allows_EV);
    RUN_TEST(test_boundary_speed_equal_SPEED_STOP_allows_StandStill);
    RUN_TEST(test_boundary_P_dem_equal_STOP_LOW_allows_StandStill);
    RUN_TEST(test_boundary_SOC_equal_SOC_EV_IN_allows_EV);
    RUN_TEST(test_boundary_P_dem_equal_HYB_MID_allows_ICE_to_Hybrid);
    RUN_TEST(test_boundary_P_dem_equal_HYB_LOW_allows_Hybrid_to_ICE);
    RUN_TEST(test_boundary_SOC_equal_SOC_LOW_blocks_Hybrid_to_ICE_via_SOC);

    return UNITY_END();
}
