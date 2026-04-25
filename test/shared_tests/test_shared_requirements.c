/* ============================================================================
 * test_shared_requirements.c
 *
 * Tests for CROSS-CUTTING requirements that do not belong to a single
 * individual person according to the
 * "mapeamento_transicoes_secao4_por_responsavel.md" map.
 *
 * Coverage:
 *   - SwHLR01  Initialization Behavior                (shared)
 *   - SwHLR02  Deterministic Output Mapping           (shared)
 *   - SwHLR10  Init + invalid-mode recovery           (shared)
 *   - SysHLR01 Single valid mode per cycle            (derived from the set)
 *   - SysHLR02 Deterministic Powertrain Enable        (derived via SwHLR02)
 *   - SysHLR03 Calibratable and Hysteretic Strategy   (derived; structural part)
 *   - NfHLR02  Transition Stability and Hysteresis    (unit-testable part)
 *   - NfHLR04  Deterministic Outputs / Reproducibility
 *
 * Outside the unit-test scope:
 *   - NfHLR01  (0.1 s period)       -> integration gate (SIL/HIL)
 *   - NfHLR03  (static allocation)  -> MISRA C gate
 * ============================================================================ */

#include "unity.h"
#include "mode_logic_team.h"

#include <stddef.h>

/* ----------------------------------------------------------------------------
 * setUp / tearDown
 * -------------------------------------------------------------------------- */

static State_t   g_state;
static Inputs_t  g_in;
static Outputs_t g_out;

void setUp(void)
{
    ModeLogic_Init(&g_state);
    g_in.speed = 0.0f;
    g_in.P_dem = 0.0f;
    g_in.SOC   = 0.0f;
    g_in.wEng  = 0.0f;
    g_out.Mot_Enable = 0U;
    g_out.Gen_Enable = 0U;
    g_out.ICE_Enable = 0U;
}

void tearDown(void) { }

/* ----------------------------------------------------------------------------
 * Helpers - drive the state machine to a target mode using only the public
 * API (ModeLogic_Init + ModeLogic_Step). These helpers do not rely on static
 * functions or on a specific order of the internal `case` labels.
 * -------------------------------------------------------------------------- */

static Inputs_t make_in(float speed, float P_dem, float SOC, float wEng)
{
    Inputs_t in;
    in.speed = speed;
    in.P_dem = P_dem;
    in.SOC   = SOC;
    in.wEng  = wEng;
    return in;
}

/* One step from a known state. */
static Mode_t step_with(State_t *s, Outputs_t *o, Inputs_t in)
{
    ModeLogic_Step(s, &in, o);
    return s->current_mode;
}

/* After Init, the state is already STANDSTILL. No extra step is required. */
static void drive_to_standstill(State_t *s, Outputs_t *o)
{
    ModeLogic_Init(s);
    /* Neutral step to update outputs to the mode default. */
    (void)step_with(s, o, make_in(0.0f, 0.0f, 0.5f, 0.0f));
    /* speed<=SPEED_STOP => stays in STANDSTILL. */
}

static void drive_to_EV(State_t *s, Outputs_t *o)
{
    ModeLogic_Init(s);
    /* STANDSTILL -> EV: speed>SPEED_STOP, speed<=SPEED_EV_MAX, SOC>=SOC_EV_IN */
    (void)step_with(s, o, make_in(10.0f, 0.0f, 0.50f, 0.0f));
}

static void drive_to_REGENB(State_t *s, Outputs_t *o)
{
    drive_to_EV(s, o);
    /* EV -> REGENB: speed>SPEED_REGEN, P_dem<=PDEM_REGEN */
    (void)step_with(s, o, make_in(20.0f, -10.0f, 0.50f, 0.0f));
}

static void drive_to_Start(State_t *s, Outputs_t *o)
{
    ModeLogic_Init(s);
    /* STANDSTILL -> START: speed>SPEED_STOP && (speed>SPEED_EV_MAX || SOC<SOC_EV_IN) */
    (void)step_with(s, o, make_in(10.0f, 0.0f, 0.20f, 0.0f));
}

static void drive_to_ICE(State_t *s, Outputs_t *o)
{
    drive_to_Start(s, o);
    /* START -> ICE: wEng>ENG_ON && (SOC<SOC_MID || (speed<=SPEED_EV_MAX && P_dem<PDEM_HYB_MID))
     * Inputs chosen so external regen/ev/standstill paths are NOT satisfied. */
    (void)step_with(s, o, make_in(10.0f, 0.0f, 0.20f, 900.0f));
}

static void drive_to_Hybrid(State_t *s, Outputs_t *o)
{
    drive_to_Start(s, o);
    /* START -> HYBRID: wEng>ENG_ON && SOC>=SOC_MID && (speed>SPEED_EV_MAX || P_dem>=PDEM_HYB_MID)
     * speed=40 > SPEED_EV_MAX blocks the external EV branch; SOC>=SOC_EV_IN is not enough.
     * P_dem=20 > PDEM_REGEN blocks external Regen. speed>SPEED_STOP blocks StandStill. */
    (void)step_with(s, o, make_in(40.0f, 20.0f, 0.50f, 900.0f));
}

/* ============================================================================
 * SwHLR01 - Initialization Behavior
 * ========================================================================== */

void test_SwHLR01_init_sets_current_mode_to_standstill(void)
{
    State_t s;
    s.current_mode = MODE_HYBRID;  /* arbitrary different initial value */
    ModeLogic_Init(&s);
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, (int)s.current_mode);
}

void test_SwHLR01_init_is_idempotent(void)
{
    State_t s;
    ModeLogic_Init(&s);
    Mode_t after_first = s.current_mode;
    ModeLogic_Init(&s);
    TEST_ASSERT_EQUAL_INT((int)after_first, (int)s.current_mode);
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, (int)s.current_mode);
}

/* ============================================================================
 * SwHLR02 / SysHLR02 - Deterministic Output Mapping by Active Mode
 *
 * PDF pattern (Section 4.1.2, SysHLR02):
 *   Standstill {0,0,0}, EV {1,0,0}, RegenB {1,0,0}, Start {1,1,0},
 *   ICE {0,1,1}, Hybrid {1,1,1}.
 * ========================================================================== */

static void assert_outputs(uint8_t mot, uint8_t gen, uint8_t ice,
                           const Outputs_t *o, const char *mode_name)
{
    char msg[128];
    (void)mode_name;
    (void)msg;
    TEST_ASSERT_EQUAL_UINT8(mot, o->Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(gen, o->Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(ice, o->ICE_Enable);
}

void test_SwHLR02_standstill_outputs_000(void)
{
    drive_to_standstill(&g_state, &g_out);
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, (int)g_state.current_mode);
    assert_outputs(0U, 0U, 0U, &g_out, "STANDSTILL");
}

void test_SwHLR02_EV_outputs_100(void)
{
    drive_to_EV(&g_state, &g_out);
    TEST_ASSERT_EQUAL_INT(MODE_EV, (int)g_state.current_mode);
    assert_outputs(1U, 0U, 0U, &g_out, "EV");
}

void test_SwHLR02_RegenB_outputs_100(void)
{
    drive_to_REGENB(&g_state, &g_out);
    TEST_ASSERT_EQUAL_INT(MODE_REGENB, (int)g_state.current_mode);
    assert_outputs(1U, 0U, 0U, &g_out, "REGENB");
}

void test_SwHLR02_Start_outputs_110(void)
{
    drive_to_Start(&g_state, &g_out);
    TEST_ASSERT_EQUAL_INT(MODE_START, (int)g_state.current_mode);
    assert_outputs(1U, 1U, 0U, &g_out, "START");
}

void test_SwHLR02_ICE_outputs_011(void)
{
    drive_to_ICE(&g_state, &g_out);
    TEST_ASSERT_EQUAL_INT(MODE_ICE, (int)g_state.current_mode);
    assert_outputs(0U, 1U, 1U, &g_out, "ICE");
}

void test_SwHLR02_Hybrid_outputs_111(void)
{
    drive_to_Hybrid(&g_state, &g_out);
    TEST_ASSERT_EQUAL_INT(MODE_HYBRID, (int)g_state.current_mode);
    assert_outputs(1U, 1U, 1U, &g_out, "HYBRID");
}

/* ============================================================================
 * SwHLR10 - Initialization and Invalid-Mode Recovery
 * ========================================================================== */

void test_SwHLR10_init_null_state_does_not_crash(void)
{
    ModeLogic_Init(NULL);
    /* If execution gets here without a segfault, the defensive requirement is met. */
    TEST_PASS();
}

void test_SwHLR10_step_null_state_does_not_crash(void)
{
    Inputs_t in = make_in(10.0f, 0.0f, 0.5f, 0.0f);
    Outputs_t out = { 0xFFU, 0xFFU, 0xFFU };
    ModeLogic_Step(NULL, &in, &out);
    /* With state==NULL, Step must return immediately without touching anything. */
    TEST_ASSERT_EQUAL_UINT8(0xFFU, out.Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(0xFFU, out.Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(0xFFU, out.ICE_Enable);
}

void test_SwHLR10_step_null_inputs_does_not_crash(void)
{
    State_t s;
    ModeLogic_Init(&s);
    Outputs_t out = { 0xFFU, 0xFFU, 0xFFU };
    ModeLogic_Step(&s, NULL, &out);
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, (int)s.current_mode);
}

void test_SwHLR10_step_null_outputs_does_not_crash(void)
{
    State_t s;
    ModeLogic_Init(&s);
    Inputs_t in = make_in(10.0f, 0.0f, 0.5f, 0.0f);
    ModeLogic_Step(&s, &in, NULL);
    /* Step must not have changed the state (early return due to NULL `out`). */
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, (int)s.current_mode);
}

void test_SwHLR10_invalid_mode_value_recovers_to_standstill(void)
{
    /* Simulate state corruption by assigning a value outside the enum range. */
    State_t s;
    s.current_mode = (Mode_t)99;
    Inputs_t in = make_in(0.0f, 0.0f, 0.0f, 0.0f);
    Outputs_t out = { 0xFFU, 0xFFU, 0xFFU };

    ModeLogic_Step(&s, &in, &out);

    /* switch default in ModeLogic_Step: next = MODE_STANDSTILL.
     * Then write_outputs(MODE_STANDSTILL) -> (0,0,0). */
    TEST_ASSERT_EQUAL_INT(MODE_STANDSTILL, (int)s.current_mode);
    TEST_ASSERT_EQUAL_UINT8(0U, out.Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(0U, out.Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(0U, out.ICE_Enable);
}

/* ============================================================================
 * SysHLR01 - Exactly one mode per cycle
 * ========================================================================== */

void test_SysHLR01_every_step_leaves_valid_mode(void)
{
    const Inputs_t sequence[] = {
        {  0.0f,   0.0f, 0.50f,   0.0f },
        { 10.0f,   0.0f, 0.50f,   0.0f },
        { 20.0f, -10.0f, 0.50f,   0.0f },
        { 40.0f,  20.0f, 0.50f, 900.0f },
        {  0.0f,   0.0f, 0.20f,   0.0f },
        { 40.0f,  50.0f, 0.30f, 900.0f },
        { 10.0f,   0.0f, 0.20f, 900.0f },
        { 10.0f,   0.0f, 0.20f, 780.0f },
        { 0.30f,   0.5f, 0.36f,   0.0f },
        { 40.0f,   0.0f, 0.28f, 900.0f },
    };
    const size_t n = sizeof(sequence) / sizeof(sequence[0]);

    for (size_t i = 0U; i < n; ++i) {
        Inputs_t in = sequence[i];
        ModeLogic_Step(&g_state, &in, &g_out);
        int m = (int)g_state.current_mode;
        TEST_ASSERT_TRUE_MESSAGE(
            (m == MODE_STANDSTILL) || (m == MODE_EV)     || (m == MODE_REGENB) ||
            (m == MODE_START)      || (m == MODE_ICE)    || (m == MODE_HYBRID),
            "after each step the mode must be exactly one of the 6 valid modes");
    }
}

/* ============================================================================
 * SysHLR03 - Calibratable and Hysteretic Transition Strategy
 *
 * This section tests structural threshold properties. If the order/separation
 * defined by the model is broken by a wrong calibration, hysteresis disappears.
 * NfHLR02 complements this with cycle tests below.
 * ========================================================================== */

void test_SysHLR03_SOC_EV_hysteresis_window_is_positive(void)
{
    TEST_ASSERT_TRUE_MESSAGE(SOC_EV_IN > SOC_EV_OUT,
        "SOC_EV_IN (EV entry) must be > SOC_EV_OUT (EV exit)");
}

void test_SysHLR03_ENG_hysteresis_window_is_positive(void)
{
    TEST_ASSERT_TRUE_MESSAGE(ENG_ON > ENG_OFF,
        "ENG_ON must be > ENG_OFF for engine hysteresis to exist");
}

void test_SysHLR03_PDEM_STOP_window_is_coherent(void)
{
    TEST_ASSERT_TRUE_MESSAGE(PDEM_STOP_HIGH > PDEM_STOP_LOW,
        "standstill P_dem window: HIGH must be > LOW");
}

void test_SysHLR03_PDEM_HYB_ordering(void)
{
    TEST_ASSERT_TRUE_MESSAGE(PDEM_HYB_MID > PDEM_HYB_LOW,
        "PDEM_HYB_MID (Hybrid entry) must be > PDEM_HYB_LOW (exit)");
    TEST_ASSERT_TRUE_MESSAGE(PDEM_HYB_OUT > PDEM_HYB_MID,
        "PDEM_HYB_OUT (external EV ceiling) must be > PDEM_HYB_MID");
    TEST_ASSERT_TRUE_MESSAGE(PDEM_HYB_IN > PDEM_HYB_OUT,
        "PDEM_HYB_IN > PDEM_HYB_OUT preserves hysteresis in the EV->Start branch");
}

void test_SysHLR03_SOC_ordering(void)
{
    TEST_ASSERT_TRUE(SOC_EV_IN > SOC_MID);
    TEST_ASSERT_TRUE(SOC_MID   > SOC_LOW);
}

void test_SysHLR03_SPEED_ordering(void)
{
    TEST_ASSERT_TRUE(SPEED_EV_MAX > SPEED_REGEN);
    TEST_ASSERT_TRUE(SPEED_REGEN  > SPEED_STOP);
}

/* ============================================================================
 * NfHLR02 - Transition Stability and Hysteresis Preservation (cycles)
 *
 * These tests force a cycle across the threshold pair. Inside the hysteresis
 * window, the mode must persist. The mode changes only after crossing the
 * exit threshold.
 * ========================================================================== */

void test_NfHLR02_SOC_EV_hysteresis_cycle(void)
{
    /* Phase 1: STANDSTILL -> EV at SOC >= SOC_EV_IN (0.37). */
    Inputs_t enter = make_in(10.0f, 0.0f, SOC_EV_IN, 0.0f);
    ModeLogic_Step(&g_state, &enter, &g_out);
    TEST_ASSERT_EQUAL_INT_MESSAGE(MODE_EV, (int)g_state.current_mode,
        "with SOC = SOC_EV_IN, the state must enter EV");

    /* Phase 2: SOC inside the window (SOC_EV_OUT < SOC < SOC_EV_IN). It must
     * stay in EV because EV->Start is not triggered by SOC < SOC_EV_OUT and
     * it does not return to Standstill because speed > SPEED_STOP. */
    Inputs_t middle = make_in(10.0f, 0.0f, 0.36f, 0.0f);
    ModeLogic_Step(&g_state, &middle, &g_out);
    TEST_ASSERT_EQUAL_INT_MESSAGE(MODE_EV, (int)g_state.current_mode,
        "inside the SOC hysteresis window, the state must stay in EV");

    /* Phase 3: SOC < SOC_EV_OUT -> EV -> START (SwLLR04). */
    Inputs_t exit_win = make_in(10.0f, 0.0f, 0.34f, 0.0f);
    ModeLogic_Step(&g_state, &exit_win, &g_out);
    TEST_ASSERT_EQUAL_INT_MESSAGE(MODE_START, (int)g_state.current_mode,
        "below SOC_EV_OUT, the state must leave EV");
}

void test_NfHLR02_ENG_hysteresis_cycle(void)
{
    /* Phase 1: STANDSTILL -> START (speed > SPEED_STOP, SOC < SOC_EV_IN). */
    Inputs_t to_start = make_in(10.0f, 0.0f, 0.20f, 0.0f);
    ModeLogic_Step(&g_state, &to_start, &g_out);
    TEST_ASSERT_EQUAL_INT(MODE_START, (int)g_state.current_mode);

    /* Phase 2: START -> ICE (wEng > ENG_ON, SOC < SOC_MID). */
    Inputs_t to_ice = make_in(10.0f, 0.0f, 0.20f, 900.0f);
    ModeLogic_Step(&g_state, &to_ice, &g_out);
    TEST_ASSERT_EQUAL_INT(MODE_ICE, (int)g_state.current_mode);

    /* Phase 3: wEng inside the window (ENG_OFF < wEng <= ENG_ON). ICE is
     * already "on", does not reset, and does not move to Hybrid (low P_dem). */
    Inputs_t stay_ice = make_in(10.0f, 0.0f, 0.20f, 795.0f);
    ModeLogic_Step(&g_state, &stay_ice, &g_out);
    TEST_ASSERT_EQUAL_INT_MESSAGE(MODE_ICE, (int)g_state.current_mode,
        "with ENG_OFF < wEng <= ENG_ON, the state must stay in ICE");

    /* Phase 4: wEng <= ENG_OFF -> ICE -> START (SwLLR20 reset). */
    Inputs_t eng_off = make_in(10.0f, 0.0f, 0.20f, 780.0f);
    ModeLogic_Step(&g_state, &eng_off, &g_out);
    TEST_ASSERT_EQUAL_INT_MESSAGE(MODE_START, (int)g_state.current_mode,
        "wEng <= ENG_OFF must reset ICE to START");
}

/* ============================================================================
 * NfHLR04 - Deterministic Outputs and Reproducibility
 *
 * Same input -> same output across repeated executions.
 * ========================================================================== */

void test_NfHLR04_same_sequence_produces_same_outputs(void)
{
    const Inputs_t sequence[] = {
        { 10.0f,   0.0f, 0.50f,   0.0f },
        { 20.0f, -10.0f, 0.50f,   0.0f },
        { 40.0f,  50.0f, 0.30f, 900.0f },
        {  0.0f,   0.0f, 0.25f,   0.0f },
        { 10.0f,   0.0f, 0.40f, 900.0f },
    };
    const size_t n = sizeof(sequence) / sizeof(sequence[0]);

    Mode_t    modes_A[5];
    Outputs_t outs_A[5];
    Mode_t    modes_B[5];
    Outputs_t outs_B[5];

    /* Execution A */
    State_t sA; Outputs_t oA;
    ModeLogic_Init(&sA);
    for (size_t i = 0U; i < n; ++i) {
        Inputs_t in = sequence[i];
        ModeLogic_Step(&sA, &in, &oA);
        modes_A[i] = sA.current_mode;
        outs_A[i]  = oA;
    }

    /* Execution B (different state object, same sequence) */
    State_t sB; Outputs_t oB;
    ModeLogic_Init(&sB);
    for (size_t i = 0U; i < n; ++i) {
        Inputs_t in = sequence[i];
        ModeLogic_Step(&sB, &in, &oB);
        modes_B[i] = sB.current_mode;
        outs_B[i]  = oB;
    }

    for (size_t i = 0U; i < n; ++i) {
        TEST_ASSERT_EQUAL_INT((int)modes_A[i], (int)modes_B[i]);
        TEST_ASSERT_EQUAL_UINT8(outs_A[i].Mot_Enable, outs_B[i].Mot_Enable);
        TEST_ASSERT_EQUAL_UINT8(outs_A[i].Gen_Enable, outs_B[i].Gen_Enable);
        TEST_ASSERT_EQUAL_UINT8(outs_A[i].ICE_Enable, outs_B[i].ICE_Enable);
    }
}

/* ============================================================================
 * Runner
 * ========================================================================== */

int main(void)
{
    UNITY_BEGIN();

    /* SwHLR01 */
    RUN_TEST(test_SwHLR01_init_sets_current_mode_to_standstill);
    RUN_TEST(test_SwHLR01_init_is_idempotent);

    /* SwHLR02 / SysHLR02 */
    RUN_TEST(test_SwHLR02_standstill_outputs_000);
    RUN_TEST(test_SwHLR02_EV_outputs_100);
    RUN_TEST(test_SwHLR02_RegenB_outputs_100);
    RUN_TEST(test_SwHLR02_Start_outputs_110);
    RUN_TEST(test_SwHLR02_ICE_outputs_011);
    RUN_TEST(test_SwHLR02_Hybrid_outputs_111);

    /* SwHLR10 */
    RUN_TEST(test_SwHLR10_init_null_state_does_not_crash);
    RUN_TEST(test_SwHLR10_step_null_state_does_not_crash);
    RUN_TEST(test_SwHLR10_step_null_inputs_does_not_crash);
    RUN_TEST(test_SwHLR10_step_null_outputs_does_not_crash);
    RUN_TEST(test_SwHLR10_invalid_mode_value_recovers_to_standstill);

    /* SysHLR01 */
    RUN_TEST(test_SysHLR01_every_step_leaves_valid_mode);

    /* SysHLR03 */
    RUN_TEST(test_SysHLR03_SOC_EV_hysteresis_window_is_positive);
    RUN_TEST(test_SysHLR03_ENG_hysteresis_window_is_positive);
    RUN_TEST(test_SysHLR03_PDEM_STOP_window_is_coherent);
    RUN_TEST(test_SysHLR03_PDEM_HYB_ordering);
    RUN_TEST(test_SysHLR03_SOC_ordering);
    RUN_TEST(test_SysHLR03_SPEED_ordering);

    /* NfHLR02 */
    RUN_TEST(test_NfHLR02_SOC_EV_hysteresis_cycle);
    RUN_TEST(test_NfHLR02_ENG_hysteresis_cycle);

    /* NfHLR04 */
    RUN_TEST(test_NfHLR04_same_sequence_produces_same_outputs);

    return UNITY_END();
}
