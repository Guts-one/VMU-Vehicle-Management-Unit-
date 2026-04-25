#include "unity.h"
#include "../inc/mode_logic_team.h"
#include <stddef.h>

void setUp(void)
{
}

void tearDown(void)
{
}

void test_ModeLogic_Init_ValidPointer(void)
{
    State_t state;
    state.current_mode = MODE_HYBRID;
    
    ModeLogic_Init(&state);
    
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, state.current_mode);
}

void test_ModeLogic_Init_NullPointer(void)
{
    ModeLogic_Init(NULL);
    TEST_PASS();
}

void test_map_outputs_MODE_STANDSTILL(void)
{
    State_t state;
    Inputs_t in = {0.0f, 0.0f, 0.5f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_STANDSTILL;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL_UINT8(0, out.Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(0, out.Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(0, out.ICE_Enable);
}

void test_map_outputs_MODE_EV(void)
{
    State_t state;
    Inputs_t in = {10.0f, 5.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_EV;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL_UINT8(1, out.Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(0, out.Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(0, out.ICE_Enable);
}

void test_map_outputs_MODE_REGENB(void)
{
    State_t state;
    Inputs_t in = {10.0f, -6.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_REGENB;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL_UINT8(1, out.Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(0, out.Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(0, out.ICE_Enable);
}

void test_map_outputs_MODE_START(void)
{
    State_t state;
    Inputs_t in = {40.0f, 20.0f, 0.40f, 750.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL_UINT8(1, out.Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(1, out.Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(0, out.ICE_Enable);
}

void test_map_outputs_MODE_ICE(void)
{
    State_t state;
    Inputs_t in = {40.0f, 12.0f, 0.28f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_ICE;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL_UINT8(0, out.Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(1, out.Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(1, out.ICE_Enable);
}

void test_map_outputs_MODE_HYBRID(void)
{
    State_t state;
    Inputs_t in = {40.0f, 20.0f, 0.35f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_HYBRID;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL_UINT8(1, out.Mot_Enable);
    TEST_ASSERT_EQUAL_UINT8(1, out.Gen_Enable);
    TEST_ASSERT_EQUAL_UINT8(1, out.ICE_Enable);
}

void test_ModeLogic_Step_NullState(void)
{
    Inputs_t in = {10.0f, 5.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    ModeLogic_Step(NULL, &in, &out);
    TEST_PASS();
}

void test_ModeLogic_Step_NullInputs(void)
{
    State_t state;
    Outputs_t out;
    
    state.current_mode = MODE_STANDSTILL;
    ModeLogic_Step(&state, NULL, &out);
    TEST_PASS();
}

void test_ModeLogic_Step_NullOutputs(void)
{
    State_t state;
    Inputs_t in = {10.0f, 5.0f, 0.40f, 0.0f};
    
    state.current_mode = MODE_STANDSTILL;
    ModeLogic_Step(&state, &in, NULL);
    TEST_PASS();
}

void test_STANDSTILL_to_EV_AllTrue(void)
{
    State_t state;
    Inputs_t in = {10.0f, 5.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_STANDSTILL;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_EV, state.current_mode);
}

void test_STANDSTILL_to_EV_SpeedAtMax(void)
{
    State_t state;
    Inputs_t in = {35.0f, 5.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_STANDSTILL;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_EV, state.current_mode);
}

void test_STANDSTILL_to_EV_SOCAtMin(void)
{
    State_t state;
    Inputs_t in = {10.0f, 5.0f, 0.37f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_STANDSTILL;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_EV, state.current_mode);
}

void test_STANDSTILL_to_START_HighSpeed(void)
{
    State_t state;
    Inputs_t in = {40.0f, 5.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_STANDSTILL;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_START, state.current_mode);
}

void test_STANDSTILL_to_START_LowSOC(void)
{
    State_t state;
    Inputs_t in = {10.0f, 5.0f, 0.36f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_STANDSTILL;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_START, state.current_mode);
}

void test_STANDSTILL_Stay_LowSpeed(void)
{
    State_t state;
    Inputs_t in = {0.3f, 0.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_STANDSTILL;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, state.current_mode);
}

void test_EV_to_REGENB_AllTrue(void)
{
    State_t state;
    Inputs_t in = {10.0f, -6.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_EV;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_REGENB, state.current_mode);
}

void test_EV_to_REGENB_SpeedAtLimit(void)
{
    State_t state;
    Inputs_t in = {5.1f, -6.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_EV;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_REGENB, state.current_mode);
}

void test_EV_to_REGENB_PDemAtLimit(void)
{
    State_t state;
    Inputs_t in = {10.0f, -5.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_EV;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_REGENB, state.current_mode);
}

void test_EV_to_START_HighSpeed(void)
{
    State_t state;
    Inputs_t in = {40.0f, 5.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_EV;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_START, state.current_mode);
}

void test_EV_to_START_HighPDem(void)
{
    State_t state;
    Inputs_t in = {10.0f, 50.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_EV;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_START, state.current_mode);
}

void test_EV_to_START_LowSOC(void)
{
    State_t state;
    Inputs_t in = {10.0f, 5.0f, 0.34f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_EV;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_START, state.current_mode);
}

void test_EV_to_STANDSTILL_AllTrue(void)
{
    State_t state;
    Inputs_t in = {0.3f, 0.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_EV;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, state.current_mode);
}

void test_EV_to_STANDSTILL_AtLimits(void)
{
    State_t state;
    Inputs_t in = {0.5f, 1.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_EV;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, state.current_mode);
}

void test_EV_Stay(void)
{
    State_t state;
    Inputs_t in = {10.0f, 5.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_EV;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_EV, state.current_mode);
}

void test_REGENB_to_START_HighSpeed(void)
{
    State_t state;
    Inputs_t in = {40.0f, 0.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_REGENB;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_START, state.current_mode);
}

void test_REGENB_to_START_LowSOC(void)
{
    State_t state;
    Inputs_t in = {10.0f, -6.0f, 0.34f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_REGENB;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_START, state.current_mode);
}

void test_REGENB_to_STANDSTILL_AllTrue(void)
{
    State_t state;
    Inputs_t in = {0.3f, 0.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_REGENB;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, state.current_mode);
}

void test_REGENB_to_EV_AllTrue(void)
{
    State_t state;
    Inputs_t in = {10.0f, 0.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_REGENB;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_EV, state.current_mode);
}

void test_REGENB_to_EV_AtLimits(void)
{
    State_t state;
    Inputs_t in = {35.0f, -1.0f, 0.35f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_REGENB;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_EV, state.current_mode);
}

void test_REGENB_Stay(void)
{
    State_t state;
    Inputs_t in = {10.0f, -6.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_REGENB;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_REGENB, state.current_mode);
}

void test_START_to_HYBRID_HighSpeed(void)
{
    State_t state;
    Inputs_t in = {40.0f, 20.0f, 0.35f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_HYBRID, state.current_mode);
}

void test_START_to_HYBRID_HighPDem(void)
{
    State_t state;
    Inputs_t in = {30.0f, 15.0f, 0.35f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_HYBRID, state.current_mode);
}

void test_START_to_HYBRID_AtLimits(void)
{
    State_t state;
    Inputs_t in = {35.1f, 15.0f, 0.30f, 800.1f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_HYBRID, state.current_mode);
}

void test_START_to_ICE_LowSOC(void)
{
    State_t state;
    Inputs_t in = {40.0f, 20.0f, 0.28f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_ICE, state.current_mode);
}

void test_START_to_ICE_LowSpeedAndPDem(void)
{
    State_t state;
    Inputs_t in = {30.0f, 10.0f, 0.35f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_ICE, state.current_mode);
}

void test_START_to_REGENB_CommonExit(void)
{
    State_t state;
    Inputs_t in = {10.0f, -6.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_REGENB, state.current_mode);
}

void test_START_to_EV_CommonExit(void)
{
    State_t state;
    Inputs_t in = {10.0f, 5.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_EV, state.current_mode);
}

void test_START_to_STANDSTILL_CommonExit(void)
{
    State_t state;
    Inputs_t in = {0.3f, 0.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, state.current_mode);
}

void test_START_Stay_EngineNotOn(void)
{
    State_t state;
    Inputs_t in = {40.0f, 20.0f, 0.35f, 750.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_START, state.current_mode);
}

void test_ICE_to_START_EngineStall(void)
{
    State_t state;
    Inputs_t in = {40.0f, 12.0f, 0.28f, 790.0f};
    Outputs_t out;
    
    state.current_mode = MODE_ICE;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_START, state.current_mode);
}

void test_ICE_to_HYBRID_HighPDemAndSOC(void)
{
    State_t state;
    Inputs_t in = {40.0f, 15.0f, 0.35f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_ICE;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_HYBRID, state.current_mode);
}

void test_ICE_to_HYBRID_AtLimits(void)
{
    State_t state;
    Inputs_t in = {40.0f, 15.0f, 0.30f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_ICE;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_HYBRID, state.current_mode);
}

void test_ICE_to_REGENB_CommonExit(void)
{
    State_t state;
    Inputs_t in = {10.0f, -6.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_ICE;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_REGENB, state.current_mode);
}

void test_ICE_to_EV_CommonExit(void)
{
    State_t state;
    Inputs_t in = {10.0f, 5.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_ICE;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_EV, state.current_mode);
}

void test_ICE_to_STANDSTILL_CommonExit(void)
{
    State_t state;
    Inputs_t in = {0.3f, 0.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_ICE;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, state.current_mode);
}

void test_ICE_Stay(void)
{
    State_t state;
    Inputs_t in = {40.0f, 12.0f, 0.28f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_ICE;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_ICE, state.current_mode);
}

void test_HYBRID_to_START_EngineStall(void)
{
    State_t state;
    Inputs_t in = {40.0f, 20.0f, 0.35f, 790.0f};
    Outputs_t out;
    
    state.current_mode = MODE_HYBRID;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_START, state.current_mode);
}

void test_HYBRID_to_ICE_LowPDem(void)
{
    State_t state;
    Inputs_t in = {40.0f, 10.0f, 0.35f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_HYBRID;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_ICE, state.current_mode);
}

void test_HYBRID_to_ICE_LowSOC(void)
{
    State_t state;
    Inputs_t in = {40.0f, 20.0f, 0.24f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_HYBRID;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_ICE, state.current_mode);
}

void test_HYBRID_to_ICE_AtLimits(void)
{
    State_t state;
    Inputs_t in = {40.0f, 10.0f, 0.25f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_HYBRID;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_ICE, state.current_mode);
}

void test_HYBRID_to_REGENB_CommonExit(void)
{
    State_t state;
    Inputs_t in = {10.0f, -6.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_HYBRID;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_REGENB, state.current_mode);
}

void test_HYBRID_to_EV_CommonExit(void)
{
    State_t state;
    Inputs_t in = {10.0f, 5.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_HYBRID;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_EV, state.current_mode);
}

void test_HYBRID_to_STANDSTILL_CommonExit(void)
{
    State_t state;
    Inputs_t in = {0.3f, 0.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_HYBRID;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, state.current_mode);
}

void test_HYBRID_Stay(void)
{
    State_t state;
    Inputs_t in = {40.0f, 20.0f, 0.35f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_HYBRID;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_HYBRID, state.current_mode);
}

void test_STANDSTILL_SpeedBoundary(void)
{
    State_t state;
    Inputs_t in = {0.5f, 0.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_STANDSTILL;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, state.current_mode);
}

void test_EV_PDemBoundaryHigh(void)
{
    State_t state;
    Inputs_t in = {0.3f, -1.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_EV;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, state.current_mode);
}

void test_REGENB_SpeedAtEVMax(void)
{
    State_t state;
    Inputs_t in = {35.0f, -6.0f, 0.40f, 0.0f};
    Outputs_t out;
    
    state.current_mode = MODE_REGENB;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_REGENB, state.current_mode);
}

void test_START_wEngAtEngOn(void)
{
    State_t state;
    Inputs_t in = {40.0f, 20.0f, 0.35f, 800.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_START, state.current_mode);
}

void test_ICE_wEngAtEngOff(void)
{
    State_t state;
    Inputs_t in = {40.0f, 12.0f, 0.28f, 790.0f};
    Outputs_t out;
    
    state.current_mode = MODE_ICE;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_START, state.current_mode);
}

void test_HYBRID_PDemAtHybLow(void)
{
    State_t state;
    Inputs_t in = {40.0f, 10.0f, 0.35f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_HYBRID;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_ICE, state.current_mode);
}

void test_START_to_ICE_SOCBelowMid(void)
{
    State_t state;
    Inputs_t in = {40.0f, 20.0f, 0.29f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_ICE, state.current_mode);
}

void test_CommonExit_SpeedAtStop(void)
{
    State_t state;
    Inputs_t in = {0.5f, 0.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, state.current_mode);
}

void test_CommonExit_PDemAtStopHigh(void)
{
    State_t state;
    Inputs_t in = {0.3f, 1.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, state.current_mode);
}

void test_CommonExit_PDemAtStopLow(void)
{
    State_t state;
    Inputs_t in = {0.3f, -1.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_STANDSTILL, state.current_mode);
}

void test_CommonExit_PDemAtHybOut(void)
{
    State_t state;
    Inputs_t in = {10.0f, 40.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_EV, state.current_mode);
}

void test_CommonExit_SOCAtEVIn(void)
{
    State_t state;
    Inputs_t in = {10.0f, 5.0f, 0.37f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_EV, state.current_mode);
}

void test_CommonExit_SpeedAtEVMax(void)
{
    State_t state;
    Inputs_t in = {35.0f, 5.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_EV, state.current_mode);
}

void test_CommonExit_PDemAtRegen(void)
{
    State_t state;
    Inputs_t in = {10.0f, -5.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_REGENB, state.current_mode);
}

void test_CommonExit_SpeedAtRegen(void)
{
    State_t state;
    Inputs_t in = {5.0f, -6.0f, 0.40f, 850.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_NOT_EQUAL(MODE_REGENB, state.current_mode);
}

void test_CommonExit_wEngAtEngOn(void)
{
    State_t state;
    Inputs_t in = {10.0f, 5.0f, 0.40f, 800.0f};
    Outputs_t out;
    
    state.current_mode = MODE_START;
    ModeLogic_Step(&state, &in, &out);
    
    TEST_ASSERT_EQUAL(MODE_START, state.current_mode);
}

int main(void)
{
    UNITY_BEGIN();
    
    RUN_TEST(test_ModeLogic_Init_ValidPointer);
    RUN_TEST(test_ModeLogic_Init_NullPointer);
    
    RUN_TEST(test_map_outputs_MODE_STANDSTILL);
    RUN_TEST(test_map_outputs_MODE_EV);
    RUN_TEST(test_map_outputs_MODE_REGENB);
    RUN_TEST(test_map_outputs_MODE_START);
    RUN_TEST(test_map_outputs_MODE_ICE);
    RUN_TEST(test_map_outputs_MODE_HYBRID);
    
    RUN_TEST(test_ModeLogic_Step_NullState);
    RUN_TEST(test_ModeLogic_Step_NullInputs);
    RUN_TEST(test_ModeLogic_Step_NullOutputs);
    
    RUN_TEST(test_STANDSTILL_to_EV_AllTrue);
    RUN_TEST(test_STANDSTILL_to_EV_SpeedAtMax);
    RUN_TEST(test_STANDSTILL_to_EV_SOCAtMin);
    RUN_TEST(test_STANDSTILL_to_START_HighSpeed);
    RUN_TEST(test_STANDSTILL_to_START_LowSOC);
    RUN_TEST(test_STANDSTILL_Stay_LowSpeed);
    RUN_TEST(test_STANDSTILL_SpeedBoundary);
    
    RUN_TEST(test_EV_to_REGENB_AllTrue);
    RUN_TEST(test_EV_to_REGENB_SpeedAtLimit);
    RUN_TEST(test_EV_to_REGENB_PDemAtLimit);
    RUN_TEST(test_EV_to_START_HighSpeed);
    RUN_TEST(test_EV_to_START_HighPDem);
    RUN_TEST(test_EV_to_START_LowSOC);
    RUN_TEST(test_EV_to_STANDSTILL_AllTrue);
    RUN_TEST(test_EV_to_STANDSTILL_AtLimits);
    RUN_TEST(test_EV_Stay);
    RUN_TEST(test_EV_PDemBoundaryHigh);
    
    RUN_TEST(test_REGENB_to_START_HighSpeed);
    RUN_TEST(test_REGENB_to_START_LowSOC);
    RUN_TEST(test_REGENB_to_STANDSTILL_AllTrue);
    RUN_TEST(test_REGENB_to_EV_AllTrue);
    RUN_TEST(test_REGENB_to_EV_AtLimits);
    RUN_TEST(test_REGENB_Stay);
    RUN_TEST(test_REGENB_SpeedAtEVMax);
    
    RUN_TEST(test_START_to_HYBRID_HighSpeed);
    RUN_TEST(test_START_to_HYBRID_HighPDem);
    RUN_TEST(test_START_to_HYBRID_AtLimits);
    RUN_TEST(test_START_to_ICE_LowSOC);
    RUN_TEST(test_START_to_ICE_LowSpeedAndPDem);
    RUN_TEST(test_START_to_ICE_SOCBelowMid);
    RUN_TEST(test_START_to_REGENB_CommonExit);
    RUN_TEST(test_START_to_EV_CommonExit);
    RUN_TEST(test_START_to_STANDSTILL_CommonExit);
    RUN_TEST(test_START_Stay_EngineNotOn);
    RUN_TEST(test_START_wEngAtEngOn);
    
    RUN_TEST(test_ICE_to_START_EngineStall);
    RUN_TEST(test_ICE_to_HYBRID_HighPDemAndSOC);
    RUN_TEST(test_ICE_to_HYBRID_AtLimits);
    RUN_TEST(test_ICE_to_REGENB_CommonExit);
    RUN_TEST(test_ICE_to_EV_CommonExit);
    RUN_TEST(test_ICE_to_STANDSTILL_CommonExit);
    RUN_TEST(test_ICE_Stay);
    RUN_TEST(test_ICE_wEngAtEngOff);
    
    RUN_TEST(test_HYBRID_to_START_EngineStall);
    RUN_TEST(test_HYBRID_to_ICE_LowPDem);
    RUN_TEST(test_HYBRID_to_ICE_LowSOC);
    RUN_TEST(test_HYBRID_to_ICE_AtLimits);
    RUN_TEST(test_HYBRID_to_REGENB_CommonExit);
    RUN_TEST(test_HYBRID_to_EV_CommonExit);
    RUN_TEST(test_HYBRID_to_STANDSTILL_CommonExit);
    RUN_TEST(test_HYBRID_Stay);
    RUN_TEST(test_HYBRID_PDemAtHybLow);
    
    RUN_TEST(test_CommonExit_SpeedAtStop);
    RUN_TEST(test_CommonExit_PDemAtStopHigh);
    RUN_TEST(test_CommonExit_PDemAtStopLow);
    RUN_TEST(test_CommonExit_PDemAtHybOut);
    RUN_TEST(test_CommonExit_SOCAtEVIn);
    RUN_TEST(test_CommonExit_SpeedAtEVMax);
    RUN_TEST(test_CommonExit_PDemAtRegen);
    RUN_TEST(test_CommonExit_SpeedAtRegen);
    RUN_TEST(test_CommonExit_wEngAtEngOn);
    
    return UNITY_END();
}
