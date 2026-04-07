#include <stddef.h>
#include "../inc/mode_logic.h"

void ModeLogic_Init(State_t* state)
{
    if (state != NULL) {
        state->current_mode = MODE_STANDSTILL;
    }
}

void ModeLogic_Step(State_t* state, Inputs_t* in, Outputs_t* out)
{
    if ((state == NULL) || (in == NULL) || (out == NULL)) {
        return;
    }

    /* Default outputs for all modes, updated below as needed */
    out->Mot_Enable = 0;
    out->Gen_Enable = 0;
    out->ICE_Enable = 0;

    switch (state->current_mode) {
        case MODE_STANDSTILL:
            if ((in->speed > SPEED_STOP) &&
                ((in->speed > SPEED_EV_MAX) || (in->SOC < SOC_EV_IN))) {
                state->current_mode = MODE_START;
            } else if ((in->speed > SPEED_STOP) &&
                       (in->speed <= SPEED_EV_MAX) &&
                       (in->SOC >= SOC_EV_IN) &&
                       (in->P_dem > PDEM_REGEN)) {
                state->current_mode = MODE_EV;
            }

            out->Mot_Enable = 0;
            out->Gen_Enable = 0;
            out->ICE_Enable = 0;
            break;

        case MODE_EV:
            if ((in->speed <= SPEED_STOP) &&
                (in->P_dem < PDEM_STOP_HIGH) &&
                (in->P_dem > PDEM_STOP_LOW)) {
                state->current_mode = MODE_STANDSTILL;
            } else if ((in->speed > SPEED_REGEN) &&
                       (in->P_dem <= PDEM_REGEN)) {
                state->current_mode = MODE_REGENB;
            } else if ((in->speed > SPEED_EV_MAX) ||
                       (in->P_dem >= PDEM_HYB_IN) ||
                       (in->SOC < SOC_EV_OUT)) {
                state->current_mode = MODE_START;
            }

            out->Mot_Enable = 1;
            out->Gen_Enable = 0;
            out->ICE_Enable = 0;
            break;

        case MODE_REGENB:
        case MODE_START:
        case MODE_ICE:
        case MODE_HYBRID:
        default:
            /* Preserve default outputs for unspecified modes. */
            break;
    }
}
