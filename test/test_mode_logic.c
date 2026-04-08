#include <assert.h>
#include <stdio.h>

#include "../inc/mode_logic.h"

static void test_init_starts_in_standstill(void)
{
    State_t state;
    Inputs_t inputs = {0};
    Outputs_t outputs = {0};

    ModeLogic_Init(&state);
    assert(state.current_mode == MODE_STANDSTILL);

    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_STANDSTILL);
    assert(outputs.Mot_Enable == 0);
    assert(outputs.Gen_Enable == 0);
    assert(outputs.ICE_Enable == 0);
}

static void test_transition_to_start(void)
{
    State_t state;
    Inputs_t inputs = {
        .speed = 36.0f,
        .P_dem = 0.0f,
        .SOC = 0.40f,
        .wEng = 0.0f
    };
    Outputs_t outputs = {0};

    ModeLogic_Init(&state);
    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_START);
}

static void test_transition_to_ev(void)
{
    State_t state;
    Inputs_t inputs = {
        .speed = 20.0f,
        .P_dem = 0.0f,
        .SOC = 0.40f,
        .wEng = 0.0f
    };
    Outputs_t outputs = {0};

    ModeLogic_Init(&state);
    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_EV);
    
    /* Step again to get MODE_EV outputs */
    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_EV);
    assert(outputs.Mot_Enable == 1);
    assert(outputs.Gen_Enable == 0);
    assert(outputs.ICE_Enable == 0);
}

static void test_ev_to_standstill(void)
{
    State_t state;
    Inputs_t inputs = {
        .speed = 20.0f,
        .P_dem = 0.0f,
        .SOC = 0.40f,
        .wEng = 0.0f
    };
    Outputs_t outputs = {0};

    /* First enter MODE_EV */
    ModeLogic_Init(&state);
    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_EV);

    /* Now transition to STANDSTILL: speed <= 0.5 && -1 < P_dem < 1 */
    inputs.speed = 0.3f;
    inputs.P_dem = -0.5f;
    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_STANDSTILL);
}

static void test_ev_to_regenb(void)
{
    State_t state;
    Inputs_t inputs = {
        .speed = 20.0f,
        .P_dem = 0.0f,
        .SOC = 0.40f,
        .wEng = 0.0f
    };
    Outputs_t outputs = {0};

    /* First enter MODE_EV */
    ModeLogic_Init(&state);
    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_EV);

    /* Now transition to REGENB: speed > 5 && P_dem <= -5 */
    inputs.speed = 10.0f;
    inputs.P_dem = -5.5f;
    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_REGENB);
}

static void test_ev_to_start(void)
{
    State_t state;
    Inputs_t inputs = {
        .speed = 20.0f,
        .P_dem = 0.0f,
        .SOC = 0.40f,
        .wEng = 0.0f
    };
    Outputs_t outputs = {0};

    /* First enter MODE_EV */
    ModeLogic_Init(&state);
    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_EV);

    /* Now transition to START: speed > 35 */
    inputs.speed = 36.0f;
    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_START);
}

static void test_ev_to_start_high_pdem(void)
{
    State_t state;
    Inputs_t inputs = {
        .speed = 20.0f,
        .P_dem = 0.0f,
        .SOC = 0.40f,
        .wEng = 0.0f
    };
    Outputs_t outputs = {0};

    /* First enter MODE_EV */
    ModeLogic_Init(&state);
    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_EV);

    /* Now transition to START: P_dem >= 55 */
    inputs.P_dem = 60.0f;
    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_START);
}

static void test_ev_to_start_low_soc(void)
{
    State_t state;
    Inputs_t inputs = {
        .speed = 20.0f,
        .P_dem = 0.0f,
        .SOC = 0.40f,
        .wEng = 0.0f
    };
    Outputs_t outputs = {0};

    /* First enter MODE_EV */
    ModeLogic_Init(&state);
    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_EV);

    /* Now transition to START: SOC < 0.35 */
    inputs.SOC = 0.30f;
    ModeLogic_Step(&state, &inputs, &outputs);
    assert(state.current_mode == MODE_START);
}

int main(void)
{
    printf("Running ModeLogic tests...\n");

    test_init_starts_in_standstill();
    test_transition_to_start();
    test_transition_to_ev();
    test_ev_to_standstill();
    test_ev_to_regenb();
    test_ev_to_start();
    test_ev_to_start_high_pdem();
    test_ev_to_start_low_soc();

    printf("All ModeLogic tests passed.\n");
    return 0;
}
