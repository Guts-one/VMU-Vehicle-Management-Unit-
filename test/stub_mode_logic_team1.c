#include <stddef.h>
#include "../inc/mode_logic_team.h"

/* ===================================================================
 * handle_standstill
 * Transições: STANDSTILL -> EV / START
 * =================================================================== */
static Mode_t handle_standstill(const Inputs_t *in)
{
    Mode_t next = MODE_STANDSTILL;

    /* STANDSTILL -> EV */
    if ((in->speed > SPEED_STOP) &&
        (in->speed <= SPEED_EV_MAX) &&
        (in->P_dem > PDEM_REGEN) &&
        (in->SOC >= SOC_EV_IN))
    {
        next = MODE_EV;
    }
    /* STANDSTILL -> START (Motion_mode_ICE) */
    else if ((in->speed > SPEED_STOP) &&
             ((in->speed > SPEED_EV_MAX) || (in->SOC < SOC_EV_IN)))
    {
        next = MODE_START;
    }
    else
    {
        /* permanece em STANDSTILL */
    }

    return next;
}

/* ===================================================================
 * handle_ev
 * Transições: EV -> REGENB / START / STANDSTILL
 * IMPORTANTE: ordem de prioridade corrigida (documento)
 * =================================================================== */
static Mode_t handle_ev(const Inputs_t *in)
{
    Mode_t next = MODE_EV;

    /* 1. REGENB (maior prioridade) */
    if ((in->P_dem <= PDEM_REGEN) &&
        (in->speed > SPEED_REGEN))
    {
        next = MODE_REGENB;
    }
    /* 2. Motion_mode_ICE (START) – prioridade sobre StandStill */
    else if ((in->speed > SPEED_EV_MAX) ||
             (in->P_dem >= PDEM_HYB_IN) ||
             (in->SOC < SOC_EV_OUT))
    {
        next = MODE_START;
    }
    /* 3. STANDSTILL */
    else if ((in->speed <= SPEED_STOP) &&
             (in->P_dem < PDEM_STOP_HIGH) &&
             (in->P_dem > PDEM_STOP_LOW))
    {
        next = MODE_STANDSTILL;
    }

    return next;
}

/* ===================================================================
 * handle_regenb
 * Transições: REGENB -> START / STANDSTILL / EV
 * =================================================================== */
static Mode_t handle_regenb(const Inputs_t *in)
{
    Mode_t next = MODE_REGENB;

    /* 1. REGENB -> START */
    if ((in->SOC < SOC_EV_OUT) ||
        (in->P_dem >= PDEM_HYB_IN) ||
        ((in->speed > SPEED_EV_MAX) && (in->P_dem >= PDEM_STOP_LOW)))
    {
        next = MODE_START;
    }
    /* 2. REGENB -> STANDSTILL */
    else if (in->speed <= SPEED_STOP)
    {
        next = MODE_STANDSTILL;
    }
    /* 3. REGENB -> EV (COMPLETO) */
    else if ((in->P_dem >= PDEM_STOP_LOW) &&
             (in->speed > SPEED_STOP) &&
             (in->speed <= SPEED_EV_MAX) &&
             (in->SOC > SOC_EV_IN))
    {
        next = MODE_EV;
    }

    return next;
}

/* ===================================================================
 * handle_start
 * =================================================================== */
static Mode_t handle_start(const Inputs_t *in)
{
    /* =========================
       TRANSIÇÕES EXTERNAS PRIMEIRO
       ========================= */

    /* -> REGENB */
    if ((in->wEng > ENG_ON) &&
        (in->speed > SPEED_REGEN) &&
        (in->P_dem <= PDEM_REGEN))
    {
        return MODE_REGENB;
    }

    /* -> EV (CORREÇÃO: SOC > SOC_EV_IN, conforme documento) */
    if ((in->wEng > ENG_ON) &&
        (in->P_dem <= PDEM_HYB_OUT) &&
        (in->P_dem >= PDEM_STOP_LOW) &&
        (in->speed > SPEED_STOP) &&
        (in->speed <= SPEED_EV_MAX) &&
        (in->SOC > SOC_EV_IN))
    {
        return MODE_EV;
    }

    /* -> STANDSTILL */
    if ((in->speed <= SPEED_STOP) &&
        (in->P_dem < PDEM_STOP_HIGH) &&
        (in->P_dem > PDEM_STOP_LOW))
    {
        return MODE_STANDSTILL;
    }

    /* =========================
       TRANSIÇÕES INTERNAS
       ========================= */

    if (in->wEng > ENG_ON)
    {
        /* PRIORIDADE: HYBRID sobre ICE */
        if ((in->SOC >= SOC_MID) &&
            ((in->speed > SPEED_EV_MAX) ||
             (in->P_dem >= PDEM_HYB_MID)))
        {
            return MODE_HYBRID;
        }

        return MODE_ICE;
    }

    return MODE_START;
}


/* ===================================================================
 * handle_ice
 * Ordem: RESET → REGENB → EV → STANDSTILL → ICE→HYBRID
 * =================================================================== */
static Mode_t handle_ice(const Inputs_t *in)
{
    /* 0. Motor desligou? Volta para START */
    if (in->wEng <= ENG_OFF)
    {
        return MODE_START;
    }

    /* 1. REGENB */
    if ((in->wEng > ENG_ON) &&
        (in->speed > SPEED_REGEN) &&
        (in->P_dem <= PDEM_REGEN))
    {
        return MODE_REGENB;
    }

    /* 2. EV */
    if ((in->wEng > ENG_ON) &&
        (in->P_dem <= PDEM_HYB_OUT) &&
        (in->P_dem >= PDEM_STOP_LOW) &&
        (in->speed > SPEED_STOP) &&
        (in->speed <= SPEED_EV_MAX) &&
        (in->SOC > SOC_EV_IN))
    {
        return MODE_EV;
    }

    /* 3. STANDSTILL */
    if ((in->speed <= SPEED_STOP) &&
        (in->P_dem < PDEM_STOP_HIGH) &&
        (in->P_dem > PDEM_STOP_LOW))
    {
        return MODE_STANDSTILL;
    }

    /* 4. Transição interna ICE → HYBRID */
    if ((in->P_dem >= PDEM_HYB_MID) && (in->SOC >= SOC_MID))
    {
        return MODE_HYBRID;
    }

    /* Permanece em ICE */
    return MODE_ICE;
}

/* ===================================================================
 * handle_hybrid
 * Ordem: RESET → REGENB → EV → STANDSTILL → HYBRID→ICE
 * =================================================================== */
static Mode_t handle_hybrid(const Inputs_t *in)
{
    /* 0. Motor desligou? */
    if (in->wEng <= ENG_OFF)
    {
        return MODE_START;
    }

    /* 1. REGENB */
    if ((in->wEng > ENG_ON) &&
        (in->speed > SPEED_REGEN) &&
        (in->P_dem <= PDEM_REGEN))
    {
        return MODE_REGENB;
    }

    /* 2. EV */
    if ((in->wEng > ENG_ON) &&
        (in->P_dem <= PDEM_HYB_OUT) &&
        (in->P_dem >= PDEM_STOP_LOW) &&
        (in->speed > SPEED_STOP) &&
        (in->speed <= SPEED_EV_MAX) &&
        (in->SOC > SOC_EV_IN))
    {
        return MODE_EV;
    }

    /* 3. STANDSTILL */
    if ((in->speed <= SPEED_STOP) &&
        (in->P_dem < PDEM_STOP_HIGH) &&
        (in->P_dem > PDEM_STOP_LOW))
    {
        return MODE_STANDSTILL;
    }

    /* 4. Transição interna HYBRID → ICE */
    if ((in->P_dem <= PDEM_HYB_LOW) || (in->SOC < SOC_LOW))
    {
        return MODE_ICE;
    }

    /* Permanece em HYBRID */
    return MODE_HYBRID;
}

/* ===================================================================
 * map_outputs
 * Único ponto de escrita dos enables.
 * =================================================================== */
static void map_outputs(Mode_t mode, Outputs_t *out)
{
    switch (mode) {
        case MODE_STANDSTILL:
            out->Mot_Enable = 0U;
            out->Gen_Enable = 0U;
            out->ICE_Enable = 0U;
            break;
        case MODE_EV:
            out->Mot_Enable = 1U;
            out->Gen_Enable = 0U;
            out->ICE_Enable = 0U;
            break;
        case MODE_REGENB:
            out->Mot_Enable = 1U;
            out->Gen_Enable = 0U;
            out->ICE_Enable = 0U;
            break;
        case MODE_START:
            out->Mot_Enable = 1U;
            out->Gen_Enable = 1U;
            out->ICE_Enable = 0U;
            break;
        case MODE_ICE:
            out->Mot_Enable = 0U;
            out->Gen_Enable = 1U;
            out->ICE_Enable = 1U;
            break;
        case MODE_HYBRID:
            out->Mot_Enable = 1U;
            out->Gen_Enable = 1U;
            out->ICE_Enable = 1U;
            break;
        default:
            out->Mot_Enable = 0U;
            out->Gen_Enable = 0U;
            out->ICE_Enable = 0U;
            break;
    }
}

/* ===================================================================
 * Interface pública
 * =================================================================== */
void ModeLogic_Init(State_t *state)
{
    if (state != NULL)
    {
        state->current_mode = MODE_STANDSTILL;
    }
}

void ModeLogic_Step(State_t *state, const Inputs_t *in, Outputs_t *out)
{
    Mode_t next;

    if ((state == NULL) || (in == NULL) || (out == NULL))
    {
        return;
    }

    next = state->current_mode;
    switch (state->current_mode) {
        case MODE_STANDSTILL:
            next = handle_standstill(in);
            break;
        case MODE_EV:
            next = handle_ev(in);
            break;
        case MODE_REGENB:
            next = handle_regenb(in);
            break;
        case MODE_START:
            next = handle_start(in);
            break;
        case MODE_ICE:
            next = handle_ice(in);
            break;
        case MODE_HYBRID:
            next = handle_hybrid(in);
            break;
        default:
            next = MODE_STANDSTILL;
            break;
    }

    state->current_mode = next;
    map_outputs(state->current_mode, out);
}