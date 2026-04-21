#include <stddef.h>
#include "../inc/mode_logic.h"

void ModeLogic_Init(State_t *state)
{
    if (state != NULL) {
        state->current_mode = MODE_STANDSTILL;
    }
}

void ModeLogic_Step(State_t *state, const Inputs_t *in, Outputs_t *out)
{
    if ((state == NULL) || (in == NULL) || (out == NULL)) {
        return;
    }

    /* Default outputs for all modes, updated below as needed */
    out->Mot_Enable = 0U;
    out->Gen_Enable = 0U;
    out->ICE_Enable = 0U;

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
            } else {
                /* remains in STANDSTILL */
            }

            out->Mot_Enable = 0U;
            out->Gen_Enable = 0U;
            out->ICE_Enable = 0U;
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
            } else {
                /* remains in EV */
            }

            out->Mot_Enable = 1U;
            out->Gen_Enable = 0U;
            out->ICE_Enable = 0U;
            break;

        case MODE_REGENB:
            if (in->speed <= SPEED_STOP) {
                state->current_mode = MODE_STANDSTILL;
            } else if (((in->speed > SPEED_EV_MAX) && (in->P_dem >= PDEM_STOP_LOW)) ||
                       (in->P_dem >= PDEM_HYB_IN) ||
                       (in->SOC < SOC_EV_OUT)) {
                state->current_mode = MODE_START;
            } else if ((in->P_dem >= PDEM_STOP_LOW) &&
                       (in->speed > SPEED_STOP) &&
                       (in->speed <= SPEED_EV_MAX) &&
                       (in->SOC > SOC_EV_IN)) {
                state->current_mode = MODE_EV;
            } else {
                /* remains in REGENB */
            }

            out->Mot_Enable = 1U;
            out->Gen_Enable = 0U;
            out->ICE_Enable = 0U;
            break;

        case MODE_START:
            if ((in->wEng > ENG_ON) && (in->SOC < SOC_LOW)) {
                state->current_mode = MODE_ICE;
            } else if ((in->wEng > ENG_ON) &&
                       ((in->P_dem >= PDEM_HYB_IN) || (in->speed > SPEED_EV_MAX)) &&
                       (in->SOC >= SOC_LOW)) {
                state->current_mode = MODE_HYBRID;
            } else {
                /* remains in START */
            }

            out->Mot_Enable = 1U;
            out->Gen_Enable = 1U;
            out->ICE_Enable = 0U;
            break;

        case MODE_ICE:
        case MODE_HYBRID:
        default:
            /* Preserve default outputs for unspecified modes */
            break;
    }
}
