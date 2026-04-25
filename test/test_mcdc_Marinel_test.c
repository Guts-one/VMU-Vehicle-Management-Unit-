#include "unity.h"
#include "../inc/mode_logic_team.h"

void test_ICE_A_true(void)
{
    force_mode(MODE_ICE);
    Inputs_t in = make_in(SPD_NORMAL, SOC_NEUTRAL, PDEM_HIGH, WENG_RUNNING);
    TEST_ASSERT_EQUAL(MODE_HYBRID, do_step(&in));
}

void test_ICE_A_false(void)
{
    force_mode(MODE_ICE);
    Inputs_t in = make_in(SPD_NORMAL, SOC_NEUTRAL, PDEM_NEUTRAL, WENG_RUNNING);
    TEST_ASSERT_EQUAL(MODE_ICE, do_step(&in));
}

void test_ICE_B_true(void)
{
    force_mode(MODE_ICE);
    Inputs_t in = make_in(SPD_NORMAL, SOC_NEUTRAL, PDEM_HIGH, WENG_RUNNING);
    TEST_ASSERT_EQUAL(MODE_HYBRID, do_step(&in));
}

void test_ICE_B_false(void)
{
    force_mode(MODE_ICE);
    Inputs_t in = make_in(SPD_NORMAL, SOC_BELOW_MID, PDEM_HIGH, WENG_RUNNING);
    TEST_ASSERT_EQUAL(MODE_ICE, do_step(&in));
}

void test_HYB_C_true(void)
{
    force_mode(MODE_HYBRID);
    Inputs_t in = make_in(SPD_NORMAL, SOC_NEUTRAL, PDEM_NEUTRAL, WENG_RUNNING);
    TEST_ASSERT_EQUAL(MODE_ICE, do_step(&in));
}

void test_HYB_C_false(void)
{
    force_mode(MODE_HYBRID);
    Inputs_t in = make_in(SPD_NORMAL, SOC_NEUTRAL, PDEM_MID, WENG_RUNNING);
    TEST_ASSERT_EQUAL(MODE_HYBRID, do_step(&in));
}

void test_HYB_D_true(void)
{
    force_mode(MODE_HYBRID);
    Inputs_t in = make_in(SPD_NORMAL, SOC_BELOW_LOW, PDEM_MID, WENG_RUNNING);
    TEST_ASSERT_EQUAL(MODE_ICE, do_step(&in));
}

void test_HYB_D_false(void)
{
    force_mode(MODE_HYBRID);
    Inputs_t in = make_in(SPD_NORMAL, SOC_NEUTRAL, PDEM_MID, WENG_RUNNING);
    TEST_ASSERT_EQUAL(MODE_HYBRID, do_step(&in));
}