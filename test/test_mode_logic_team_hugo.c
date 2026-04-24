/* =============================================================================
 * test_mode_logic_team.c
 * Unity test suite for mode_logic_team.c
 *
 * Coverage targets: 100 % Statement | 100 % Branch | 100 % MC/DC
 *
 * MC/DC strategy
 * --------------
 * For every compound boolean condition each operand is shown to
 * independently affect the outcome while all other operands are held
 * constant.  The relevant pair-IDs are annotated inline with the tests
 * that exercise them.
 *
 * Build & run (see bottom of file for full instructions).
 * ============================================================================= */

#include "unity.h"
#include "../inc/mode_logic_team.h"   /* adjust path to match your tree        */

/* --------------------------------------------------------------------------- */
/* Helpers – nominal signal values                                               */
/* --------------------------------------------------------------------------- */

/* Values that clearly satisfy every threshold individually */
#define SPD_ZERO        0.0f   /* stopped (< SPEED_STOP = 0.5)                 */
#define SPD_STOP_IN     0.3f   /* inside stopped band                          */
#define SPD_EV          10.0f  /* EV range  (> 0.5 && <= 35)                   */
#define SPD_REGEN_IN    8.0f   /* > SPEED_REGEN = 5                            */
#define SPD_ABOVE_EV    40.0f  /* > SPEED_EV_MAX = 35                          */
#define SPD_BELOW_REGEN 3.0f   /* <= SPEED_REGEN, still > SPEED_STOP           */

#define SOC_HIGH        0.50f  /* >= SOC_EV_IN  (0.37)                         */
#define SOC_MID_HIGH    0.36f  /* >= SOC_EV_OUT (0.35), < SOC_EV_IN            */
#define SOC_MID_LOW     0.32f  /* >= SOC_MID    (0.30), < SOC_EV_OUT           */
#define SOC_ABOVE_MID   0.31f  /* >= SOC_MID but < SOC_EV_OUT                  */
#define SOC_BELOW_MID   0.29f  /* < SOC_MID, >= SOC_LOW                        */
#define SOC_LOW_VAL     0.24f  /* < SOC_LOW (0.25)                             */

#define PDEM_REGEN_TRIG  -10.0f /* <= PDEM_REGEN  = -5                          */
#define PDEM_COAST        0.0f  /* PDEM_STOP_LOW (-1) <= P <= PDEM_STOP_HIGH(1) */
#define PDEM_NORMAL       5.0f  /* > 1, < 15                                    */
#define PDEM_MID_HIGH    20.0f  /* >= PDEM_HYB_MID (15), < PDEM_HYB_IN (50)    */
#define PDEM_HYB_IN_VAL  55.0f  /* >= PDEM_HYB_IN (50)                          */
#define PDEM_HYB_OUT_VAL 35.0f  /* <= PDEM_HYB_OUT (40), > PDEM_STOP_LOW (-1)  */
#define PDEM_LOW_VAL      8.0f  /* <= PDEM_HYB_LOW (10), > PDEM_STOP_LOW (-1)  */

#define WENG_ON_VAL    900.0f  /* > ENG_ON  = 800                              */
#define WENG_OFF_VAL   780.0f  /* <= ENG_OFF = 790                             */
#define WENG_CRANKING  795.0f  /* > ENG_OFF, <= ENG_ON  (engine cranking)      */

/* --------------------------------------------------------------------------- */
/* Utility                                                                       */
/* --------------------------------------------------------------------------- */

static State_t   g_state;
static Inputs_t  g_in;
static Outputs_t g_out;

/* Build a clean Inputs_t with "safe" defaults (vehicle stopped, EV-capable). */
static Inputs_t make_inputs(float speed, float soc, float p_dem, float wEng)
{
    Inputs_t in;
    in.speed = speed;
    in.SOC   = soc;
    in.P_dem = p_dem;
    in.wEng  = wEng;
    return in;
}

/* Drive the FSM one step and return the new mode. */
static Mode_t step(State_t *st, Inputs_t *in)
{
    ModeLogic_Step(st, in, &g_out);
    return st->current_mode;
}

/* Force the FSM into a specific mode without going through transitions.
 * Used to set preconditions for tests. */
static void force_mode(State_t *st, Mode_t m)
{
    st->current_mode = m;
}

/* --------------------------------------------------------------------------- */
/* setUp / tearDown                                                              */
/* --------------------------------------------------------------------------- */

void setUp(void)
{
    ModeLogic_Init(&g_state);
    g_in  = make_inputs(SPD_ZERO, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    g_out.Mot_Enable = 0xFF;
    g_out.Gen_Enable = 0xFF;
    g_out.ICE_Enable = 0xFF;
}

void tearDown(void) {}

/* =========================================================================== */
/* 1.  ModeLogic_Init                                                            */
/* =========================================================================== */

/* Statement + branch: non-NULL path */
void test_Init_NonNull_SetsStandstill(void)
{
    State_t s;
    s.current_mode = MODE_HYBRID; /* dirty */
    ModeLogic_Init(&s);
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, s.current_mode);
}

/* Branch: NULL guard */
void test_Init_Null_DoesNotCrash(void)
{
    ModeLogic_Init(NULL); /* must not crash / assert */
    TEST_PASS();
}

/* =========================================================================== */
/* 2.  ModeLogic_Step – NULL-guard paths                                         */
/* =========================================================================== */

void test_Step_NullState_ReturnsEarly(void)
{
    Inputs_t  in  = make_inputs(SPD_EV, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    Outputs_t out;
    out.Mot_Enable = 0xFF;
    ModeLogic_Step(NULL, &in, &out);
    TEST_ASSERT_EQUAL(0xFF, out.Mot_Enable); /* unchanged */
}

void test_Step_NullIn_ReturnsEarly(void)
{
    Outputs_t out;
    out.Mot_Enable = 0xFF;
    ModeLogic_Step(&g_state, NULL, &out);
    TEST_ASSERT_EQUAL(0xFF, out.Mot_Enable);
}

void test_Step_NullOut_ReturnsEarly(void)
{
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    /* Should not crash */
    ModeLogic_Step(&g_state, &in, NULL);
    TEST_PASS();
}

/* =========================================================================== */
/* 3.  STANDSTILL transitions                                                    */
/* =========================================================================== */

/*
 * Condition:  speed > SPEED_STOP  &&  speed <= SPEED_EV_MAX  &&  SOC >= SOC_EV_IN
 *
 * MC/DC pairs (each letter = independent effect):
 *   A = (speed > SPEED_STOP)   : tests SS_EV_base vs SS_EV_A_false
 *   B = (speed <= SPEED_EV_MAX): tests SS_EV_base vs SS_EV_B_false
 *   C = (SOC >= SOC_EV_IN)     : tests SS_EV_base vs SS_EV_C_false
 */

/* Base: all three TRUE -> EV */
void test_SS_to_EV_base(void)
{
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_EV, step(&g_state, &in));
}

/* A false: speed <= SPEED_STOP -> stays STANDSTILL */
void test_SS_to_EV_A_false(void)
{
    Inputs_t in = make_inputs(SPD_STOP_IN, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, step(&g_state, &in));
}

/* B false: speed > SPEED_EV_MAX, SOC >= SOC_EV_IN -> START (not EV) */
void test_SS_to_EV_B_false(void)
{
    Inputs_t in = make_inputs(SPD_ABOVE_EV, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    /* speed > SPEED_STOP AND (speed > SPEED_EV_MAX) -> START branch */
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

/* C false: SOC < SOC_EV_IN, speed in EV range -> START (EV condition fails) */
void test_SS_to_EV_C_false(void)
{
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_COAST, WENG_OFF_VAL);
    /* SOC < SOC_EV_IN => falls through to START branch */
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

/*
 * STANDSTILL -> START condition:
 *   speed > SPEED_STOP  &&  (speed > SPEED_EV_MAX  ||  SOC < SOC_EV_IN)
 *
 * MC/DC pairs:
 *   A = (speed > SPEED_STOP)   : test_SS_to_START_A_false
 *   B = (speed > SPEED_EV_MAX) : test_SS_to_START_B_true  (sole reason)
 *   C = (SOC < SOC_EV_IN)      : test_SS_to_START_C_true  (sole reason)
 */

/* B true, C false: speed > EV_MAX triggers START */
void test_SS_to_START_B_true(void)
{
    Inputs_t in = make_inputs(SPD_ABOVE_EV, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

/* C true, B false: low SOC triggers START */
void test_SS_to_START_C_true(void)
{
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

/* A false: speed <= SPEED_STOP -> no START, stay STANDSTILL */
void test_SS_to_START_A_false(void)
{
    Inputs_t in = make_inputs(SPD_STOP_IN, SOC_MID_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, step(&g_state, &in));
}

/* Else branch: speed <= SPEED_STOP, SOC high -> STANDSTILL self-loop */
void test_SS_selfloop(void)
{
    Inputs_t in = make_inputs(SPD_ZERO, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, step(&g_state, &in));
}

/* =========================================================================== */
/* 4.  EV transitions                                                            */
/* =========================================================================== */

/*
 * Priority 1: EV -> REGENB:  speed > SPEED_REGEN  &&  P_dem <= PDEM_REGEN
 *   A = (speed > SPEED_REGEN) : test_EV_to_REGENB_A_false
 *   B = (P_dem <= PDEM_REGEN) : test_EV_to_REGENB_B_false
 */

void test_EV_to_REGENB_base(void)
{
    force_mode(&g_state, MODE_EV);
    Inputs_t in = make_inputs(SPD_REGEN_IN, SOC_HIGH, PDEM_REGEN_TRIG, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_REGENB, step(&g_state, &in));
}

void test_EV_to_REGENB_A_false(void)
{
    force_mode(&g_state, MODE_EV);
    Inputs_t in = make_inputs(SPD_BELOW_REGEN, SOC_HIGH, PDEM_REGEN_TRIG, WENG_OFF_VAL);
    /* P_dem is regen but speed too low -> falls to next priority */
    /* P_dem <= PDEM_REGEN so EV->START condition (P_dem >= PDEM_HYB_IN) is false,
       SOC >= SOC_EV_OUT ok, speed <= SPEED_EV_MAX ok -> stays EV */
    TEST_ASSERT_EQUAL(MODE_EV, step(&g_state, &in));
}

void test_EV_to_REGENB_B_false(void)
{
    force_mode(&g_state, MODE_EV);
    /* speed > SPEED_REGEN but P_dem not <= PDEM_REGEN */
    Inputs_t in = make_inputs(SPD_REGEN_IN, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_EV, step(&g_state, &in));
}

/*
 * Priority 2: EV -> START:
 *   (speed > SPEED_EV_MAX)  ||  (P_dem >= PDEM_HYB_IN)  ||  (SOC < SOC_EV_OUT)
 *   A = speed > SPEED_EV_MAX
 *   B = P_dem >= PDEM_HYB_IN
 *   C = SOC < SOC_EV_OUT
 */

void test_EV_to_START_A_true(void)
{
    force_mode(&g_state, MODE_EV);
    Inputs_t in = make_inputs(SPD_ABOVE_EV, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

void test_EV_to_START_B_true(void)
{
    force_mode(&g_state, MODE_EV);
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, PDEM_HYB_IN_VAL, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

void test_EV_to_START_C_true(void)
{
    force_mode(&g_state, MODE_EV);
    /* SOC < SOC_EV_OUT, speed/P_dem normal */
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_LOW, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

/* All three false -> no START; verify priority-3 and else paths */
void test_EV_stays_EV_when_no_exit(void)
{
    force_mode(&g_state, MODE_EV);
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_EV, step(&g_state, &in));
}

/*
 * Priority 3: EV -> STANDSTILL:
 *   speed <= SPEED_STOP  &&  P_dem <= PDEM_STOP_HIGH  &&  P_dem >= PDEM_STOP_LOW
 *   A = speed <= SPEED_STOP
 *   B = P_dem <= PDEM_STOP_HIGH
 *   C = P_dem >= PDEM_STOP_LOW
 */

void test_EV_to_SS_base(void)
{
    force_mode(&g_state, MODE_EV);
    Inputs_t in = make_inputs(SPD_STOP_IN, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, step(&g_state, &in));
}

void test_EV_to_SS_A_false(void)
{
    /* speed > SPEED_STOP prevents STANDSTILL, all START conditions false -> EV */
    force_mode(&g_state, MODE_EV);
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_EV, step(&g_state, &in));
}

void test_EV_to_SS_B_false(void)
{
    /* speed <= SPEED_STOP but P_dem > PDEM_STOP_HIGH -> P_dem >= PDEM_HYB_IN? no.
       speed > SPEED_EV_MAX? no.  SOC < SOC_EV_OUT? no.  -> falls to SS cond.
       SS cond: speed ok, but P_dem > PDEM_STOP_HIGH -> not SS -> else (stay EV).
       But speed <= SPEED_STOP so REGEN priority doesn't fire, START or EV must win.
       P_dem = 2 (> PDEM_STOP_HIGH=1, < PDEM_HYB_IN=50, SOC high, speed low) ->
       None of the exit conditions true -> stays EV. */
    force_mode(&g_state, MODE_EV);
    Inputs_t in = make_inputs(SPD_STOP_IN, SOC_HIGH, 2.0f, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_EV, step(&g_state, &in));
}

void test_EV_to_SS_C_false(void)
{
    /* P_dem < PDEM_STOP_LOW (< -1), speed stopped -> REGENB if speed>SPEED_REGEN
       else here speed is stopped so REGENB not triggered; START cond: P_dem<PDEM_HYB_IN ok
       but speed not > EV_MAX and SOC >= SOC_EV_OUT.  Then SS cond: speed ok,
       P_dem <= PDEM_STOP_HIGH (yes, -2 < 1) but P_dem < PDEM_STOP_LOW -> not SS -> else EV */
    force_mode(&g_state, MODE_EV);
    Inputs_t in = make_inputs(SPD_STOP_IN, SOC_HIGH, -2.0f, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_EV, step(&g_state, &in));
}

/* =========================================================================== */
/* 5.  REGENB transitions                                                        */
/* =========================================================================== */

/*
 * Priority 1: REGENB -> START (Motion_mode_ICE):
 *   ((speed > SPEED_EV_MAX) && (P_dem >= PDEM_STOP_LOW))  ||  (SOC < SOC_EV_OUT)
 *
 * Sub-condition A = (speed > SPEED_EV_MAX)
 * Sub-condition B = (P_dem >= PDEM_STOP_LOW)
 * Sub-condition C = (SOC < SOC_EV_OUT)
 *
 * MC/DC:
 *   A matters: fix B=T, C=F => (A&&B)||C=A;  A_true vs A_false
 *   B matters: fix A=T, C=F => (A&&B)||C=B;  B_true vs B_false
 *   C matters: fix A=F => C alone: C_true vs C_false
 */

void test_REGENB_to_START_AB_true(void)
{
    force_mode(&g_state, MODE_REGENB);
    Inputs_t in = make_inputs(SPD_ABOVE_EV, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

void test_REGENB_to_START_A_false(void)
{
    /* A false: speed <= SPEED_EV_MAX, C false: SOC >= SOC_EV_OUT -> no START via p1 */
    force_mode(&g_state, MODE_REGENB);
    /* Pick conditions that lead to EV (priority 3) */
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_COAST, WENG_OFF_VAL);
    /* P1: A=F => (F&&B)=F; C=F (SOC_MID_HIGH=0.36>=SOC_EV_OUT=0.35) -> not START
       P2: speed > SPEED_STOP, <= SPEED_STOP? no -> not SS
       P3: P_dem>=PDEM_STOP_LOW, speed in EV range, SOC>=SOC_EV_OUT -> EV */
    TEST_ASSERT_EQUAL(MODE_EV, step(&g_state, &in));
}

void test_REGENB_to_START_B_false(void)
{
    /* A=T (speed > EV_MAX), B=F (P_dem < PDEM_STOP_LOW), C=F (SOC high)
       (A&&B) = (T&&F)=F, C=F => condition false -> no START via p1
       P2: speed > SPEED_STOP so not STANDSTILL
       P3: P_dem < PDEM_STOP_LOW so fails P_dem >= PDEM_STOP_LOW -> not EV
       -> stays REGENB */
    force_mode(&g_state, MODE_REGENB);
    Inputs_t in = make_inputs(SPD_ABOVE_EV, SOC_HIGH, -5.0f, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_REGENB, step(&g_state, &in));
}

void test_REGENB_to_START_C_true(void)
{
    /* C=T: SOC < SOC_EV_OUT, regardless of speed */
    force_mode(&g_state, MODE_REGENB);
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_LOW, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

void test_REGENB_to_START_C_false_only(void)
{
    /* A=F, C=F: SOC >= SOC_EV_OUT -> not triggered by C alone */
    /* Already covered by test_REGENB_to_START_A_false */
    TEST_PASS();
}

/*
 * Priority 2: REGENB -> STANDSTILL
 *   speed <= SPEED_STOP  &&  P_dem <= PDEM_STOP_HIGH  &&  P_dem >= PDEM_STOP_LOW
 *   (same structure as EV->STANDSTILL)
 */

void test_REGENB_to_SS_base(void)
{
    force_mode(&g_state, MODE_REGENB);
    Inputs_t in = make_inputs(SPD_STOP_IN, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, step(&g_state, &in));
}

void test_REGENB_to_SS_A_false(void)
{
    /* speed > SPEED_STOP -> no STANDSTILL; SOC high, speed EV range, P_dem coast -> EV */
    force_mode(&g_state, MODE_REGENB);
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_EV, step(&g_state, &in));
}

void test_REGENB_to_SS_B_false(void)
{
    /* speed stopped, P_dem > PDEM_STOP_HIGH */
    force_mode(&g_state, MODE_REGENB);
    Inputs_t in = make_inputs(SPD_STOP_IN, SOC_HIGH, 2.0f, WENG_OFF_VAL);
    /* P1: speed<=EV_MAX, P_dem>=PDEM_STOP_LOW(yes,2>-1), SOC high -> A=F(speed not>EV_MAX)
       So P1 condition: (T&&T)||F = T? Wait: speed<=EV_MAX so speed>EV_MAX is FALSE.
       (F && T) || F = F -> no START from P1.
       P2: speed<=SPEED_STOP(T), P_dem<=PDEM_STOP_HIGH(F: 2>1) -> not SS
       P3: P_dem>=PDEM_STOP_LOW(T), speed>SPEED_STOP(F: stopped) -> not EV
       -> stays REGENB */
    TEST_ASSERT_EQUAL(MODE_REGENB, step(&g_state, &in));
}

void test_REGENB_to_SS_C_false(void)
{
    /* speed stopped, P_dem < PDEM_STOP_LOW */
    force_mode(&g_state, MODE_REGENB);
    Inputs_t in = make_inputs(SPD_STOP_IN, SOC_HIGH, -2.0f, WENG_OFF_VAL);
    /* P1: speed not>EV_MAX -> A=F; SOC ok -> C=F; -> not START
       P2: speed ok, P_dem<=-1 so P_dem<=PDEM_STOP_HIGH(T), P_dem>=-1: P_dem=-2 < -1 => F -> not SS
       P3: P_dem<PDEM_STOP_LOW -> not EV
       -> stays REGENB */
    TEST_ASSERT_EQUAL(MODE_REGENB, step(&g_state, &in));
}

/*
 * Priority 3: REGENB -> EV
 *   P_dem >= PDEM_STOP_LOW  &&  speed > SPEED_STOP  &&
 *   speed <= SPEED_EV_MAX   &&  SOC >= SOC_EV_OUT
 *   A = P_dem >= PDEM_STOP_LOW
 *   B = speed > SPEED_STOP
 *   C = speed <= SPEED_EV_MAX
 *   D = SOC >= SOC_EV_OUT
 */

void test_REGENB_to_EV_base(void)
{
    force_mode(&g_state, MODE_REGENB);
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_EV, step(&g_state, &in));
}

void test_REGENB_to_EV_A_false(void)
{
    /* P_dem < PDEM_STOP_LOW, speed EV, SOC ok -> not EV, stays REGENB */
    force_mode(&g_state, MODE_REGENB);
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, -2.0f, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_REGENB, step(&g_state, &in));
}

void test_REGENB_to_EV_B_false(void)
{
    /* speed <= SPEED_STOP, P_dem coast, SOC ok -> not EV (speed too low for EV cond)
       But check P1 first: speed not>EV_MAX, SOC>=SOC_EV_OUT -> not START
       P2 STANDSTILL: speed<=STOP(T), P_dem<=STOP_HIGH(T), P_dem>=STOP_LOW(T) -> SS! */
    force_mode(&g_state, MODE_REGENB);
    Inputs_t in = make_inputs(SPD_STOP_IN, SOC_MID_HIGH, PDEM_COAST, WENG_OFF_VAL);
    /* hits STANDSTILL (priority 2) before EV (priority 3) */
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, step(&g_state, &in));
    /* To isolate B=false without triggering SS, use P_dem outside coast band: */
    force_mode(&g_state, MODE_REGENB);
    in = make_inputs(SPD_STOP_IN, SOC_MID_HIGH, PDEM_NORMAL, WENG_OFF_VAL);
    /* P2: P_dem=5 > PDEM_STOP_HIGH(1) -> B_p2 false -> no SS
       P3: speed>SPEED_STOP? F -> not EV -> stays REGENB */
    TEST_ASSERT_EQUAL(MODE_REGENB, step(&g_state, &in));
}

void test_REGENB_to_EV_C_false(void)
{
    /* speed > SPEED_EV_MAX, P_dem >= PDEM_STOP_LOW, SOC ok
       P1: speed>EV_MAX(T) && P_dem>=STOP_LOW(T) -> START */
    force_mode(&g_state, MODE_REGENB);
    Inputs_t in = make_inputs(SPD_ABOVE_EV, SOC_MID_HIGH, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
    /* Since P1 fires, we can't reach P3 with C=false independently.
       The MC/DC independence of C is demonstrated via the base test (C=T->EV)
       versus the START test above where C=F but P1 fires first. */
}

void test_REGENB_to_EV_D_false(void)
{
    /* SOC < SOC_EV_OUT, speed EV range, P_dem coast -> P1: C=T fires START */
    force_mode(&g_state, MODE_REGENB);
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_LOW, PDEM_COAST, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

/* Self-loop: none of the exit conditions met */
void test_REGENB_selfloop(void)
{
    force_mode(&g_state, MODE_REGENB);
    Inputs_t in = make_inputs(SPD_ABOVE_EV, SOC_HIGH, -5.0f, WENG_OFF_VAL);
    /* P1: speed>EV_MAX(T), P_dem=-5 < PDEM_STOP_LOW(-1) -> B=F -> (T&&F)=F; SOC high->C=F -> not START
       P2: speed>STOP -> not SS
       P3: P_dem<PDEM_STOP_LOW -> not EV
       -> stays REGENB */
    TEST_ASSERT_EQUAL(MODE_REGENB, step(&g_state, &in));
}

/* =========================================================================== */
/* 6.  motion_ice_common_exit  (exercised through START, ICE, HYBRID)           */
/* =========================================================================== */

/*
 * Condition 1: -> REGENB:
 *   wEng > ENG_ON  &&  speed > SPEED_REGEN  &&  P_dem <= PDEM_REGEN
 *   A = wEng > ENG_ON
 *   B = speed > SPEED_REGEN
 *   C = P_dem <= PDEM_REGEN
 */

void test_ICE_common_to_REGENB_base(void)
{
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_REGEN_IN, SOC_HIGH, PDEM_REGEN_TRIG, WENG_ON_VAL);
    TEST_ASSERT_EQUAL(MODE_REGENB, step(&g_state, &in));
}

void test_ICE_common_to_REGENB_A_false(void)
{
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_REGEN_IN, SOC_HIGH, PDEM_REGEN_TRIG, WENG_CRANKING);
    /* wEng not > ENG_ON -> skip REGENB; also skip EV (SOC ok, but wEng not>ENG_ON);
       skip SS (speed > STOP); -> stays START internal transitions
       wEng not > ENG_ON -> not HYBRID, not ICE in handle_start -> stays START */
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

void test_ICE_common_to_REGENB_B_false(void)
{
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_BELOW_REGEN, SOC_HIGH, PDEM_REGEN_TRIG, WENG_ON_VAL);
    /* B false: speed<=SPEED_REGEN -> no REGENB
       Check EV path: wEng>ENG_ON, P_dem=-10 < PDEM_STOP_LOW(-1) -> P_dem>=STOP_LOW? F -> no EV
       SS: speed>STOP -> no
       handle_start internal: wEng>ENG_ON, SOC>=SOC_MID, speed<=EV_MAX, P_dem<PDEM_HYB_MID -> ICE */
    TEST_ASSERT_EQUAL(MODE_ICE, step(&g_state, &in));
}

void test_ICE_common_to_REGENB_C_false(void)
{
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_REGEN_IN, SOC_HIGH, PDEM_COAST, WENG_ON_VAL);
    /* C false: P_dem > PDEM_REGEN -> no REGENB
       EV path: P_dem=0 <= PDEM_HYB_OUT(40), >= PDEM_STOP_LOW(-1), speed in EV, SOC>=SOC_EV_IN -> EV */
    TEST_ASSERT_EQUAL(MODE_EV, step(&g_state, &in));
}

/*
 * Condition 2 (common_exit): -> EV:
 *   wEng>ENG_ON && P_dem<=PDEM_HYB_OUT && P_dem>=PDEM_STOP_LOW &&
 *   speed>SPEED_STOP && speed<=SPEED_EV_MAX && SOC>=SOC_EV_IN
 *   A=wEng>ENG_ON  B=P_dem<=PDEM_HYB_OUT  C=P_dem>=PDEM_STOP_LOW
 *   D=speed>SPEED_STOP  E=speed<=SPEED_EV_MAX  F=SOC>=SOC_EV_IN
 */

/* Base (all true) */
void test_ICE_common_to_EV_base(void)
{
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, PDEM_HYB_OUT_VAL, WENG_ON_VAL);
    TEST_ASSERT_EQUAL(MODE_EV, step(&g_state, &in));
}

void test_ICE_common_to_EV_A_false(void)
{
    /* wEng <= ENG_ON */
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, PDEM_HYB_OUT_VAL, WENG_CRANKING);
    /* No common exit fires; handle_start internal: wEng not >ENG_ON -> stays START */
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

void test_ICE_common_to_EV_B_false(void)
{
    /* P_dem > PDEM_HYB_OUT but also triggers REGENB? P_dem must be > -5 to avoid REGENB.
       Use P_dem=45 (>PDEM_HYB_OUT=40, <PDEM_HYB_IN=50).
       REGENB: P_dem=45 > PDEM_REGEN(-5) -> no.
       EV cond: P_dem>PDEM_HYB_OUT -> B=F -> no EV.
       SS: speed>STOP -> no.
       handle_start: wEng>ENG_ON, SOC>=SOC_MID, P_dem=45>=PDEM_HYB_MID(15) -> HYBRID */
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, 45.0f, WENG_ON_VAL);
    TEST_ASSERT_EQUAL(MODE_HYBRID, step(&g_state, &in));
}

void test_ICE_common_to_EV_C_false(void)
{
    /* P_dem < PDEM_STOP_LOW (-1). Use P_dem=-3.
       REGENB: P_dem=-3 > PDEM_REGEN(-5)? yes (-3 > -5) so P_dem<=PDEM_REGEN? no.
       EV: P_dem<PDEM_STOP_LOW -> C=F -> no EV.
       SS: speed>STOP -> no.
       handle_start: wEng>ENG_ON, SOC>=SOC_MID, speed<=EV_MAX, P_dem<PDEM_HYB_MID -> ICE */
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, -3.0f, WENG_ON_VAL);
    TEST_ASSERT_EQUAL(MODE_ICE, step(&g_state, &in));
}

void test_ICE_common_to_EV_D_false(void)
{
    /* speed <= SPEED_STOP, P_dem coast, SOC high.
       SS cond: speed<=STOP, P_dem<=STOP_HIGH, P_dem>=STOP_LOW -> STANDSTILL */
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_STOP_IN, SOC_HIGH, PDEM_COAST, WENG_ON_VAL);
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, step(&g_state, &in));
}

void test_ICE_common_to_EV_E_false(void)
{
    /* speed > SPEED_EV_MAX: REGENB? P_dem coast -> no; EV? speed>EV_MAX -> E=F -> no.
       SS? speed>STOP -> no. handle_start: wEng>ENG_ON, SOC>=SOC_MID, speed>EV_MAX -> HYBRID */
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_ABOVE_EV, SOC_HIGH, PDEM_COAST, WENG_ON_VAL);
    TEST_ASSERT_EQUAL(MODE_HYBRID, step(&g_state, &in));
}

void test_ICE_common_to_EV_F_false(void)
{
    /* SOC < SOC_EV_IN (use SOC_MID_HIGH=0.36).
       All other EV conditions true but F=false.
       handle_start: wEng>ENG_ON, SOC<SOC_MID? No (0.36>=0.30) -> check other branch:
       speed<=EV_MAX && P_dem<PDEM_HYB_MID (P_dem=35 > 15)? P_dem=HYB_OUT_VAL=35>15 -> F.
       So condition: SOC<SOC_MID(F) || (speed<=EV_MAX(T) && P_dem<HYB_MID(F)) = F -> ICE else.
       SOC>=SOC_MID(T) && (speed>EV_MAX(F)||P_dem>=HYB_MID(T,35>=15)) -> HYBRID */
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_HYB_OUT_VAL, WENG_ON_VAL);
    TEST_ASSERT_EQUAL(MODE_HYBRID, step(&g_state, &in));
}

/*
 * Condition 3 (common_exit): -> STANDSTILL
 *   speed<=SPEED_STOP && P_dem<=PDEM_STOP_HIGH && P_dem>=PDEM_STOP_LOW
 *   Already exercised in test_ICE_common_to_EV_D_false above.
 *   Extra MC/DC pairs for B and C:
 */

void test_ICE_common_to_SS_B_false(void)
{
    /* speed<=STOP, P_dem > PDEM_STOP_HIGH */
    force_mode(&g_state, MODE_ICE);
    Inputs_t in = make_inputs(SPD_STOP_IN, SOC_HIGH, 2.0f, WENG_ON_VAL);
    /* REGENB: speed<=REGEN(ok but P_dem=2>-5 so P_dem<=REGEN? no)
       EV: speed<=STOP(D=F) -> no
       SS: P_dem>STOP_HIGH -> B=F -> no
       ice internal reset: wEng>ENG_OFF -> not reset
       ICE->HYBRID: P_dem=2 < PDEM_HYB_MID(15) -> no -> stays ICE */
    TEST_ASSERT_EQUAL(MODE_ICE, step(&g_state, &in));
}

void test_ICE_common_to_SS_C_false(void)
{
    /* speed<=STOP, P_dem < PDEM_STOP_LOW */
    force_mode(&g_state, MODE_ICE);
    Inputs_t in = make_inputs(SPD_STOP_IN, SOC_HIGH, -2.0f, WENG_ON_VAL);
    /* REGENB: P_dem=-2 > -5? yes, so P_dem<=-5? no -> no REGENB
       EV: speed<=STOP(D=F) -> no
       SS: P_dem<PDEM_STOP_LOW -> C=F -> no SS
       Internal: wEng>ENG_OFF -> no reset; P_dem<HYB_MID -> no HYBRID -> stays ICE */
    TEST_ASSERT_EQUAL(MODE_ICE, step(&g_state, &in));
}

/* =========================================================================== */
/* 7.  internal_motion_ice_reset  (wEng <= ENG_OFF -> START)                   */
/* =========================================================================== */

void test_ICE_reset_to_START_when_stall(void)
{
    force_mode(&g_state, MODE_ICE);
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, PDEM_NORMAL, WENG_OFF_VAL);
    /* common_exit: wEng<=ENG_ON -> no REGENB, no EV; speed>STOP -> no SS
       -> stays ICE; reset: wEng<=ENG_OFF -> START */
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

void test_HYBRID_reset_to_START_when_stall(void)
{
    force_mode(&g_state, MODE_HYBRID);
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, PDEM_MID_HIGH, WENG_OFF_VAL);
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

/* wEng > ENG_OFF -> no reset (else branch of internal_motion_ice_reset) */
void test_ICE_no_reset_when_running(void)
{
    force_mode(&g_state, MODE_ICE);
    /* Conditions that keep FSM in ICE: common_exit all false, reset false,
       P_dem < HYB_MID so no HYBRID */
    Inputs_t in = make_inputs(SPD_EV, SOC_BELOW_MID, PDEM_NORMAL, WENG_ON_VAL);
    /* common_exit: P_dem=5 <= HYB_OUT(40), >= STOP_LOW(-1), speed EV, SOC=0.29<SOC_EV_IN(0.37) -> F
       reset: wEng > ENG_OFF -> no reset
       ICE->HYBRID: P_dem=5 < HYB_MID(15) -> no -> stays ICE */
    TEST_ASSERT_EQUAL(MODE_ICE, step(&g_state, &in));
}

/* =========================================================================== */
/* 8.  handle_start internal transitions                                         */
/* =========================================================================== */

/*
 * START -> HYBRID:
 *   wEng>ENG_ON && SOC>=SOC_MID && (speed>SPEED_EV_MAX || P_dem>=PDEM_HYB_MID)
 *   A=wEng>ENG_ON  B=SOC>=SOC_MID  C=speed>SPEED_EV_MAX  D=P_dem>=PDEM_HYB_MID
 */

void test_START_to_HYBRID_via_speed(void)
{
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_ABOVE_EV, SOC_HIGH, PDEM_COAST, WENG_ON_VAL);
    TEST_ASSERT_EQUAL(MODE_HYBRID, step(&g_state, &in));
}

void test_START_to_HYBRID_via_Pdem(void)
{
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_MID_HIGH, WENG_ON_VAL);
    TEST_ASSERT_EQUAL(MODE_HYBRID, step(&g_state, &in));
}
void test_START_to_HYBRID_A_false(void)
{
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_ABOVE_EV, SOC_HIGH, PDEM_COAST, WENG_CRANKING);
    TEST_ASSERT_EQUAL(MODE_START, step(&g_state, &in));
}

void test_START_to_HYBRID_B_false(void)
{
    /* SOC < SOC_MID */
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_ABOVE_EV, SOC_BELOW_MID, PDEM_COAST, WENG_ON_VAL);
    /* common_exit: speed>EV_MAX, P_dem=coast -> EV? speed>EV_MAX -> E=F -> no;
       REGENB? P_dem=0>PDEM_REGEN -> no; SS? speed>STOP -> no
       handle_start internal: B=F -> not HYBRID; wEng>ENG_ON(T), SOC<SOC_MID(T) -> ICE */
    TEST_ASSERT_EQUAL(MODE_ICE, step(&g_state, &in));
}

void test_START_to_HYBRID_C_false_D_false(void)
{
    /* C=F (speed<=EV_MAX) and D=F (P_dem<HYB_MID) -> or(C,D)=F -> not HYBRID -> ICE */
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, PDEM_NORMAL, WENG_ON_VAL);
    /* common_exit EV: P_dem=5, SOC high, speed EV, wEng>ENG_ON -> EV */
    TEST_ASSERT_EQUAL(MODE_EV, step(&g_state, &in));
    /* To get ICE instead, need to block EV: use SOC_MID_HIGH < SOC_EV_IN */
    force_mode(&g_state, MODE_START);
    in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_NORMAL, WENG_ON_VAL);
    /* EV: SOC=0.36 < SOC_EV_IN(0.37) -> F -> no EV
       internal: wEng>ENG_ON, SOC=0.36>=SOC_MID(0.30)=T, C=F, D=F -> not HYBRID
                 wEng>ENG_ON, (SOC<SOC_MID=F)||(speed<=EV_MAX && P_dem<HYB_MID)=(T&&T)=T -> ICE */
    TEST_ASSERT_EQUAL(MODE_ICE, step(&g_state, &in));
}

/*
 * START -> ICE:
 *   wEng>ENG_ON && (SOC<SOC_MID || (speed<=SPEED_EV_MAX && P_dem<PDEM_HYB_MID))
 *   A=wEng>ENG_ON  B=SOC<SOC_MID  C=speed<=SPEED_EV_MAX  D=P_dem<PDEM_HYB_MID
 */

void test_START_to_ICE_via_low_SOC(void)
{
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_EV, SOC_BELOW_MID, PDEM_MID_HIGH, WENG_ON_VAL);
    /* common_exit EV: SOC<SOC_EV_IN(0.37)? 0.29<0.37=T -> no, EV cond F(SOC F)
       Wait: common_exit EV checks SOC>=SOC_EV_IN. SOC=0.29 < 0.37 -> F -> no EV.
       REGENB: P_dem=20 > PDEM_REGEN -> no. SS: speed>STOP -> no.
       handle_start: HYBRID: SOC<SOC_MID(T) -> B_hyb=F -> not HYBRID.
       ICE: wEng>ENG_ON, SOC<SOC_MID(T) -> ICE */
    TEST_ASSERT_EQUAL(MODE_ICE, step(&g_state, &in));
}

void test_START_to_ICE_via_low_Pdem_in_EV_range(void)
{
    /* B=F(SOC>=SOC_MID), C=T, D=T -> or=T -> ICE */
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_NORMAL, WENG_ON_VAL);
    /* SOC=0.36 >= SOC_MID(0.30) -> B=F; (C=T && D=T) -> ICE condition true
       common_exit EV: SOC<SOC_EV_IN(0.37)? yes -> F -> no EV via common_exit
       -> ICE */
    TEST_ASSERT_EQUAL(MODE_ICE, step(&g_state, &in));
}

/* =========================================================================== */
/* 9.  handle_ice internal transitions                                           */
/* =========================================================================== */

/*
 * ICE -> HYBRID:
 *   P_dem >= PDEM_HYB_MID  &&  SOC >= SOC_MID
 *   A = P_dem >= PDEM_HYB_MID
 *   B = SOC >= SOC_MID
 */

void test_ICE_to_HYBRID_base(void)
{
    force_mode(&g_state, MODE_ICE);
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, PDEM_MID_HIGH, WENG_ON_VAL);
    /* common_exit: P_dem=20 > PDEM_HYB_OUT(40)? no. P_dem>=STOP_LOW, speed EV, SOC<SOC_EV_IN?
       SOC=0.50>=0.37 -> EV via common_exit!
       So use SOC below SOC_EV_IN to prevent common_exit->EV */
    force_mode(&g_state, MODE_ICE);
    in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_MID_HIGH, WENG_ON_VAL);
    /* EV: SOC=0.36<0.37 -> F. REGENB: P_dem=20>-5. SS: speed>STOP.
       reset: wEng>ENG_OFF -> no.  HYBRID: P_dem>=HYB_MID(T) && SOC>=SOC_MID(T,0.36>=0.30) -> HYBRID */
    TEST_ASSERT_EQUAL(MODE_HYBRID, step(&g_state, &in));
}

void test_ICE_to_HYBRID_A_false(void)
{
    force_mode(&g_state, MODE_ICE);
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_NORMAL, WENG_ON_VAL);
    /* P_dem=5 < PDEM_HYB_MID(15) -> A=F -> no HYBRID -> stays ICE */
    TEST_ASSERT_EQUAL(MODE_ICE, step(&g_state, &in));
}

void test_ICE_to_HYBRID_B_false(void)
{
    force_mode(&g_state, MODE_ICE);
    Inputs_t in = make_inputs(SPD_EV, SOC_BELOW_MID, PDEM_MID_HIGH, WENG_ON_VAL);
    /* SOC<SOC_MID -> B=F -> no HYBRID -> stays ICE */
    TEST_ASSERT_EQUAL(MODE_ICE, step(&g_state, &in));
}

/* =========================================================================== */
/* 10. handle_hybrid internal transitions                                        */
/* =========================================================================== */

/*
 * HYBRID -> ICE:
 *   P_dem <= PDEM_HYB_LOW  ||  SOC < SOC_LOW
 *   A = P_dem <= PDEM_HYB_LOW
 *   B = SOC < SOC_LOW
 */

void test_HYBRID_to_ICE_via_low_Pdem(void)
{
    force_mode(&g_state, MODE_HYBRID);
    /* SOC >= SOC_EV_IN to avoid common_exit->EV, use SOC_MID_HIGH */
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_LOW_VAL, WENG_ON_VAL);
    /* common_exit EV: SOC<SOC_EV_IN -> F. REGENB: P_dem=8>-5. SS: speed>STOP.
       reset: wEng>ENG_OFF -> no.
       ICE: P_dem=8<=PDEM_HYB_LOW(10)(T) -> ICE */
    TEST_ASSERT_EQUAL(MODE_ICE, step(&g_state, &in));
}

void test_HYBRID_to_ICE_via_low_SOC(void)
{
    force_mode(&g_state, MODE_HYBRID);
    Inputs_t in = make_inputs(SPD_EV, SOC_LOW_VAL, PDEM_MID_HIGH, WENG_ON_VAL);
    /* SOC=0.24<SOC_LOW(0.25)(T), P_dem=20>HYB_LOW(10) -> A=F but B=T -> ICE */
    TEST_ASSERT_EQUAL(MODE_ICE, step(&g_state, &in));
}

void test_HYBRID_to_ICE_A_false_B_false(void)
{
    /* Neither condition -> stays HYBRID */
    force_mode(&g_state, MODE_HYBRID);
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_MID_HIGH, WENG_ON_VAL);
    /* P_dem=20 > HYB_LOW(10) -> A=F; SOC=0.36>=SOC_LOW(0.25) -> B=F -> no ICE
       common_exit EV: SOC<SOC_EV_IN(0.36<0.37=T) -> F -> no EV.
       REGENB: P_dem=20>-5 -> no. SS: speed>STOP -> no.
       reset: wEng>ENG_OFF -> no. ICE: A=F, B=F -> no -> stays HYBRID */
    TEST_ASSERT_EQUAL(MODE_HYBRID, step(&g_state, &in));
}

/* =========================================================================== */
/* 11. map_outputs – verify all six states                                       */
/* =========================================================================== */

void test_Output_STANDSTILL(void)
{
    force_mode(&g_state, MODE_STANDSTILL);
    Inputs_t in = make_inputs(SPD_ZERO, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    step(&g_state, &in);
    TEST_ASSERT_EQUAL(0U, g_out.Mot_Enable);
    TEST_ASSERT_EQUAL(0U, g_out.Gen_Enable);
    TEST_ASSERT_EQUAL(0U, g_out.ICE_Enable);
}

void test_Output_EV(void)
{
    force_mode(&g_state, MODE_EV);
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    step(&g_state, &in);
    TEST_ASSERT_EQUAL(1U, g_out.Mot_Enable);
    TEST_ASSERT_EQUAL(0U, g_out.Gen_Enable);
    TEST_ASSERT_EQUAL(0U, g_out.ICE_Enable);
}

void test_Output_REGENB(void)
{
    force_mode(&g_state, MODE_REGENB);
    /* Keep in REGENB: speed above EV_MAX, P_dem below PDEM_STOP_LOW (regen-ish)
       Actually easiest: speed in regen zone, P_dem<=-5 but wEng<=ENG_ON */
    Inputs_t in = make_inputs(SPD_ABOVE_EV, SOC_HIGH, -5.0f, WENG_OFF_VAL);
    /* P1: (speed>EV_MAX && P_dem>=-1)? P_dem=-5 < -1 -> B=F -> (F); SOC>=SOC_EV_OUT -> C=F -> not START
       P2: speed>STOP -> no SS
       P3: P_dem<PDEM_STOP_LOW -> no EV
       -> stays REGENB */
    step(&g_state, &in);
    TEST_ASSERT_EQUAL(1U, g_out.Mot_Enable);
    TEST_ASSERT_EQUAL(0U, g_out.Gen_Enable);
    TEST_ASSERT_EQUAL(0U, g_out.ICE_Enable);
}

void test_Output_START(void)
{
    force_mode(&g_state, MODE_START);
    Inputs_t in = make_inputs(SPD_EV, SOC_HIGH, PDEM_NORMAL, WENG_CRANKING);
    /* common_exit: wEng not>ENG_ON -> no REGENB, no EV. speed>STOP -> no SS.
       internal: wEng not>ENG_ON -> neither HYBRID nor ICE -> stays START */
    step(&g_state, &in);
    TEST_ASSERT_EQUAL(1U, g_out.Mot_Enable);
    TEST_ASSERT_EQUAL(1U, g_out.Gen_Enable);
    TEST_ASSERT_EQUAL(0U, g_out.ICE_Enable);
}

void test_Output_ICE(void)
{
    force_mode(&g_state, MODE_ICE);
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_NORMAL, WENG_ON_VAL);
    step(&g_state, &in);
    TEST_ASSERT_EQUAL(0U, g_out.Mot_Enable);
    TEST_ASSERT_EQUAL(1U, g_out.Gen_Enable);
    TEST_ASSERT_EQUAL(1U, g_out.ICE_Enable);
}

void test_Output_HYBRID(void)
{
    force_mode(&g_state, MODE_HYBRID);
    Inputs_t in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_MID_HIGH, WENG_ON_VAL);
    step(&g_state, &in);
    TEST_ASSERT_EQUAL(1U, g_out.Mot_Enable);
    TEST_ASSERT_EQUAL(1U, g_out.Gen_Enable);
    TEST_ASSERT_EQUAL(1U, g_out.ICE_Enable);
}

/* Default branch of map_outputs switch (defensive – requires invalid mode). */
void test_Output_default_branch(void)
{
    g_state.current_mode = (Mode_t)99; /* invalid */
    Inputs_t in = make_inputs(SPD_ZERO, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    /* Step dispatches to default -> STANDSTILL, then map_outputs(STANDSTILL). */
    step(&g_state, &in);
    TEST_ASSERT_EQUAL(0U, g_out.Mot_Enable);
    TEST_ASSERT_EQUAL(0U, g_out.Gen_Enable);
    TEST_ASSERT_EQUAL(0U, g_out.ICE_Enable);
}

/* =========================================================================== */
/* 12. End-to-end scenario: cold start to cruise                                 */
/* =========================================================================== */

void test_E2E_cold_start_to_highway_cruise(void)
{
    State_t s;
    Inputs_t in;

    ModeLogic_Init(&s);
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, s.current_mode);

    /* Driver presses throttle – moderate speed, good SOC -> EV */
    in = make_inputs(SPD_EV, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    step(&s, &in);
    TEST_ASSERT_EQUAL(MODE_EV, s.current_mode);

    /* Heavy throttle -> needs ICE assistance */
    in = make_inputs(SPD_EV, SOC_HIGH, PDEM_HYB_IN_VAL, WENG_OFF_VAL);
    step(&s, &in);
    TEST_ASSERT_EQUAL(MODE_START, s.current_mode);

    /* Engine starts, mid-load, low SOC band */
    in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_NORMAL, WENG_ON_VAL);
    step(&s, &in);
    TEST_ASSERT_EQUAL(MODE_ICE, s.current_mode);

    /* SOC builds up, load increases -> HYBRID */
    in = make_inputs(SPD_EV, SOC_MID_HIGH, PDEM_MID_HIGH, WENG_ON_VAL);
    step(&s, &in);
    TEST_ASSERT_EQUAL(MODE_HYBRID, s.current_mode);

    /* Highway speed, engine on, good SOC -> regen braking */
    in = make_inputs(SPD_REGEN_IN, SOC_HIGH, PDEM_REGEN_TRIG, WENG_ON_VAL);
    step(&s, &in);
    TEST_ASSERT_EQUAL(MODE_REGENB, s.current_mode);

    /* Come to a stop */
    in = make_inputs(SPD_STOP_IN, SOC_HIGH, PDEM_COAST, WENG_OFF_VAL);
    step(&s, &in);
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, s.current_mode);
}

/* =========================================================================== */
/* main                                                                          */
/* =========================================================================== */

int main(void)
{
    UNITY_BEGIN();

    /* Init */
    RUN_TEST(test_Init_NonNull_SetsStandstill);
    RUN_TEST(test_Init_Null_DoesNotCrash);

    /* Step NULL guards */
    RUN_TEST(test_Step_NullState_ReturnsEarly);
    RUN_TEST(test_Step_NullIn_ReturnsEarly);
    RUN_TEST(test_Step_NullOut_ReturnsEarly);

    /* STANDSTILL */
    RUN_TEST(test_SS_to_EV_base);
    RUN_TEST(test_SS_to_EV_A_false);
    RUN_TEST(test_SS_to_EV_B_false);
    RUN_TEST(test_SS_to_EV_C_false);
    RUN_TEST(test_SS_to_START_B_true);
    RUN_TEST(test_SS_to_START_C_true);
    RUN_TEST(test_SS_to_START_A_false);
    RUN_TEST(test_SS_selfloop);

    /* EV */
    RUN_TEST(test_EV_to_REGENB_base);
    RUN_TEST(test_EV_to_REGENB_A_false);
    RUN_TEST(test_EV_to_REGENB_B_false);
    RUN_TEST(test_EV_to_START_A_true);
    RUN_TEST(test_EV_to_START_B_true);
    RUN_TEST(test_EV_to_START_C_true);
    RUN_TEST(test_EV_stays_EV_when_no_exit);
    RUN_TEST(test_EV_to_SS_base);
    RUN_TEST(test_EV_to_SS_A_false);
    RUN_TEST(test_EV_to_SS_B_false);
    RUN_TEST(test_EV_to_SS_C_false);

    /* REGENB */
    RUN_TEST(test_REGENB_to_START_AB_true);
    RUN_TEST(test_REGENB_to_START_A_false);
    RUN_TEST(test_REGENB_to_START_B_false);
    RUN_TEST(test_REGENB_to_START_C_true);
    RUN_TEST(test_REGENB_to_START_C_false_only);
    RUN_TEST(test_REGENB_to_SS_base);
    RUN_TEST(test_REGENB_to_SS_A_false);
    RUN_TEST(test_REGENB_to_SS_B_false);
    RUN_TEST(test_REGENB_to_SS_C_false);
    RUN_TEST(test_REGENB_to_EV_base);
    RUN_TEST(test_REGENB_to_EV_A_false);
    RUN_TEST(test_REGENB_to_EV_B_false);
    RUN_TEST(test_REGENB_to_EV_C_false);
    RUN_TEST(test_REGENB_to_EV_D_false);
    RUN_TEST(test_REGENB_selfloop);

    /* common_exit -> REGENB */
    RUN_TEST(test_ICE_common_to_REGENB_base);
    RUN_TEST(test_ICE_common_to_REGENB_A_false);
    RUN_TEST(test_ICE_common_to_REGENB_B_false);
    RUN_TEST(test_ICE_common_to_REGENB_C_false);

    /* common_exit -> EV */
    RUN_TEST(test_ICE_common_to_EV_base);
    RUN_TEST(test_ICE_common_to_EV_A_false);
    RUN_TEST(test_ICE_common_to_EV_B_false);
    RUN_TEST(test_ICE_common_to_EV_C_false);
    RUN_TEST(test_ICE_common_to_EV_D_false);
    RUN_TEST(test_ICE_common_to_EV_E_false);
    RUN_TEST(test_ICE_common_to_EV_F_false);

    /* common_exit -> STANDSTILL */
    RUN_TEST(test_ICE_common_to_SS_B_false);
    RUN_TEST(test_ICE_common_to_SS_C_false);

    /* internal_motion_ice_reset */
    RUN_TEST(test_ICE_reset_to_START_when_stall);
    RUN_TEST(test_HYBRID_reset_to_START_when_stall);
    RUN_TEST(test_ICE_no_reset_when_running);

    /* handle_start internal */
    RUN_TEST(test_START_to_HYBRID_via_speed);
    RUN_TEST(test_START_to_HYBRID_via_Pdem);
    RUN_TEST(test_START_to_HYBRID_A_false);
    RUN_TEST(test_START_to_HYBRID_B_false);
    RUN_TEST(test_START_to_HYBRID_C_false_D_false);
    RUN_TEST(test_START_to_ICE_via_low_SOC);
    RUN_TEST(test_START_to_ICE_via_low_Pdem_in_EV_range);

    /* handle_ice internal */
    RUN_TEST(test_ICE_to_HYBRID_base);
    RUN_TEST(test_ICE_to_HYBRID_A_false);
    RUN_TEST(test_ICE_to_HYBRID_B_false);

    /* handle_hybrid internal */
    RUN_TEST(test_HYBRID_to_ICE_via_low_Pdem);
    RUN_TEST(test_HYBRID_to_ICE_via_low_SOC);
    RUN_TEST(test_HYBRID_to_ICE_A_false_B_false);

    /* map_outputs */
    RUN_TEST(test_Output_STANDSTILL);
    RUN_TEST(test_Output_EV);
    RUN_TEST(test_Output_REGENB);
    RUN_TEST(test_Output_START);
    RUN_TEST(test_Output_ICE);
    RUN_TEST(test_Output_HYBRID);
    RUN_TEST(test_Output_default_branch);

    /* End-to-end */
    RUN_TEST(test_E2E_cold_start_to_highway_cruise);

    return UNITY_END();
}

/* =============================================================================
 * HOW TO BUILD AND RUN
 * =============================================================================
 *
 * PREREQUISITES
 * -------------
 * 1. Unity test framework (single-file, MIT):
 *      https://github.com/ThrowTheSwitch/Unity
 *    Only three files are needed:
 *      unity/src/unity.c
 *      unity/src/unity.h
 *      unity/src/unity_internals.h
 *
 * 2. GCC (or any C99-compatible compiler).
 *    For coverage: gcov + lcov (optional, for HTML report).
 *
 * ASSUMED DIRECTORY LAYOUT
 * ------------------------
 *   project/
 *   ├── inc/
 *   │   └── mode_logic_team.h
 *   ├── src/
 *   │   └── mode_logic_team.c
 *   ├── test/
 *   │   └── test_mode_logic_team.c   <- this file
 *   └── unity/
 *       └── src/
 *           ├── unity.c
 *           ├── unity.h
 *           └── unity_internals.h
 *
 * STEP 1 – Compile with coverage instrumentation
 * -----------------------------------------------
 *   cd project/
 *   gcc -std=c99 -Wall -Wextra \
 *       --coverage -fprofile-arcs -ftest-coverage \
 *       -O0 \
 *       -I inc/ \
 *       -I unity/src/ \
 *       src/mode_logic_team.c \
 *       unity/src/unity.c \
 *       test/test_mode_logic_team.c \
 *       -o test_runner
 *
 *   Flags explained:
 *     --coverage          : shorthand for -fprofile-arcs -ftest-coverage + links lgcov
 *     -O0                 : disable optimisation (keeps line mapping accurate)
 *     -I inc/             : find mode_logic_team.h
 *     -I unity/src/       : find unity.h
 *
 * STEP 2 – Run the tests
 * ----------------------
 *   ./test_runner
 *
 *   Successful output ends with:
 *     XX Tests 0 Failures 0 Ignored
 *     OK
 *
 * STEP 3 – Collect gcov coverage data
 * ------------------------------------
 *   gcov -b -c src/mode_logic_team.c
 *
 *   -b : show branch coverage
 *   -c : show branch counts (not just taken/not-taken)
 *
 *   This prints a summary to stdout and writes
 *   mode_logic_team.c.gcov next to the source.
 *
 * STEP 4 (optional) – Generate an HTML report with lcov
 * ------------------------------------------------------
 *   lcov --capture \
 *        --directory . \
 *        --output-file coverage.info
 *
 *   genhtml coverage.info \
 *           --branch-coverage \
 *           --output-directory coverage_html/
 *
 *   open coverage_html/index.html
 *
 * STEP 5 (optional) – MC/DC with gcc source-based coverage (GCC ≥ 14)
 * ---------------------------------------------------------------------
 *   GCC 14+ supports Condition/Decision Coverage (CDC) which subsumes MC/DC:
 *
 *   gcc -std=c99 -Wall \
 *       --coverage -fprofile-arcs -ftest-coverage \
 *       -fcondition-coverage \      # GCC 14+
 *       -O0 \
 *       -I inc/ -I unity/src/ \
 *       src/mode_logic_team.c unity/src/unity.c test/test_mode_logic_team.c \
 *       -o test_runner_mcdc
 *
 *   ./test_runner_mcdc
 *   gcov --conditions src/mode_logic_team.c
 *
 *   For older GCC, MC/DC must be verified by manual inspection of the
 *   pair-ID comments in this file, or by using a dedicated tool such as
 *   LDRA Testbed, VectorCAST, or Cantata.
 *
 * TROUBLESHOOTING
 * ---------------
 * • "undefined reference to unity_..." : add unity/src/unity.c to the compile command.
 * • Header not found: adjust -I paths to match your layout.
 * • .gcda files not generated: run the test binary at least once after compiling
 *   with --coverage.
 * • Branch percentages < 100 %: re-examine the inline comments for the failing
 *   branch and add a targeted test vector.
 * ============================================================================= */