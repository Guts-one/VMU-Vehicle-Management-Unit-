/* ============================================================
 * VMU - mode logic 
 *
 * 
 *
 * Divisao de tarefas:
 *   [PESSOA A] handle_standstill()   STANDSTILL -> EV / START */
#include <stddef.h>            
#include "../inc/mode_logic_team.h"

/* Helpers internos de transicao. */

/* [PESSOA A] STANDSTILL
 * Transitions:
 *   STANDSTILL -> EV     : Moving vehicle, inside EV's mode range,
 *                          SOC enough and does not demand regen.
 *   STANDSTILL -> START  : Moving vehicle but way too fast for EV mode
 *                          or SOC is not enough.
 *
 * Priority: EV before START (EV mode is the main target).
 */
static Mode_t handle_standstill(const Inputs_t *in)
{
    Mode_t next = MODE_STANDSTILL;

    /* STANDSTILL -> EV */
    if ((in->speed >  SPEED_STOP)   &&
        (in->speed <= SPEED_EV_MAX) &&
        (in->SOC   >  SOC_EV_IN)    &&
        (in->P_dem >  PDEM_REGEN)) {
        next = MODE_EV;
    }
    /* STANDSTILL -> START */
    else if ((in->speed > SPEED_STOP) &&
             ((in->speed > SPEED_EV_MAX) ||
              (in->SOC   <= SOC_EV_IN))) {
        next = MODE_START;
    }
    else {
        /* Stays in STANDSTILL */
    }

    return next;
}

/* [PESSOA B] EV
 * Transicoes esperadas:
 *   - EV -> STANDSTILL
 *   - EV -> REGENB
 *   - EV -> START
 */
static Mode_t handle_ev(const Inputs_t *in)
{
    Mode_t next = MODE_EV;

    /* TODO PESSOA B: escrever as condicoes aqui. */
    (void)in;

    return next;
}

/* [PESSOA C] REGENB
 * Transicoes esperadas:
 *   - REGENB -> STANDSTILL
 *   - REGENB -> EV
 *   - REGENB -> START
 */
static Mode_t handle_regenb(const Inputs_t *in)
{
    Mode_t next = MODE_REGENB;

    /* TODO PESSOA C: escrever as condicoes aqui. */
    (void)in;

    return next;
}

/* Motion_mode_ICE (Gustavo + Pessoa D) */

/* [GUSTAVO]
 * Saidas do superestado Motion_mode_ICE para fora do bloco.
 * O mesmo teste vale para START, ICE e HYBRID, por isso ficou
 * concentrado aqui. Se nenhuma saida disparar, o estado segue
 * no mesmo subestado interno. */
static Mode_t motion_ice_common_exit(const Inputs_t *in, Mode_t current_in_block)
{
    Mode_t next = current_in_block;

    if ((in->wEng > ENG_ON) &&
        (in->speed > SPEED_REGEN) &&
        (in->P_dem <= PDEM_REGEN)) {
        next = MODE_REGENB;
    } else if ((in->wEng > ENG_ON) &&
               (in->P_dem <= PDEM_HYB_OUT) &&
               (in->P_dem >= PDEM_STOP_LOW) &&
               (in->speed > SPEED_STOP) &&
               (in->speed <= SPEED_EV_MAX) &&
               (in->SOC > SOC_EV_IN)) {
        next = MODE_EV;
    } else if ((in->speed <= SPEED_STOP) &&
               (in->P_dem < PDEM_STOP_HIGH) &&
               (in->P_dem > PDEM_STOP_LOW)) {
        next = MODE_STANDSTILL;
    } else {
        /* continua no bloco interno atual */
    }

    return next;
}

/* [TODO PESSOA D]
 * Reset comum de ICE/HYBRID para START quando o motor desliga.
 * Este teste entra antes das trocas internas ICE <-> HYBRID. */
static Mode_t internal_motion_ice_reset(const Inputs_t *in, Mode_t current_in_block)
{
    Mode_t next = current_in_block;

    /* TODO PESSOA D: preencher o reset aqui.
     * Exemplo:
     *   if (in->wEng <= ENG_OFF) {
     *       next = MODE_START;
     *   } else {
     *       // permanece no estado atual
     *   }
     */
    (void)in;

    return next;
}

/* handle_start
 * Ordem:
 *   1) tenta sair do bloco Motion_mode_ICE
 *   2) se continuar dentro do bloco, faz START -> HYBRID / ICE
 */
static Mode_t handle_start(const Inputs_t *in)
{
    Mode_t next;

    next = motion_ice_common_exit(in, MODE_START);

    if (next == MODE_START) {
        /* [TODO PESSOA D] transicoes internas:
         *   START -> HYBRID quando:
         *     wEng > ENG_ON, SOC >= SOC_MID e
         *     (speed > SPEED_EV_MAX || P_dem >= PDEM_HYB_MID)
         *
         *   START -> ICE quando:
         *     wEng > ENG_ON e
         *     (SOC < SOC_MID ||
         *      (speed <= SPEED_EV_MAX && P_dem < PDEM_HYB_MID))
         *
         * Manter o formato if / else if / else para ficar alinhado
         * com a prioridade do modelo e com a observacao da MISRA 15.7.
         */
    } else {
        /* ja saiu do bloco */
    }

    return next;
}


static Mode_t handle_ice(const Inputs_t *in)
{
    Mode_t next;

    next = motion_ice_common_exit(in, MODE_ICE);

    if (next == MODE_ICE) {
        next = internal_motion_ice_reset(in, next);
    } else {
        /* ja saiu do bloco */
    }

    if (next == MODE_ICE) {
        if ((in->P_dem >= PDEM_HYB_MID) &&
            (in->SOC   >= SOC_MID)) {
            next = MODE_HYBRID;
        } else {
            /* permanece em ICE */
        }
    } else {
        /* saiu de ICE por reset ou por saida externa do bloco */
    }

    return next;
}

/* handle_hybrid
 * Ordem:
 *   1) tenta sair do bloco
 *   2) se ficar em HYBRID, verifica reset para START
 *   3) se ainda ficar em HYBRID, verifica HYBRID -> ICE
 */
static Mode_t handle_hybrid(const Inputs_t *in)
{
    Mode_t next;

    next = motion_ice_common_exit(in, MODE_HYBRID);

    if (next == MODE_HYBRID) {
        next = internal_motion_ice_reset(in, next);
    } else {
        /* ja saiu do bloco */
    }

    if (next == MODE_HYBRID) {
        if ((in->P_dem <= PDEM_HYB_LOW) ||
            (in->SOC   <  SOC_LOW)) {
            next = MODE_ICE;
        } else {
            /* stays  HYBRID */
        }
    } else {
        /* Exits HYBRID */
    }

    return next;
}


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
            /* Every thing turn off (safe mode)*/
            out->Mot_Enable = 0U;
            out->Gen_Enable = 0U;
            out->ICE_Enable = 0U;
            break;
    }
}

void ModeLogic_Init(State_t *state)
{
    if (state != NULL) {
        state->current_mode = MODE_STANDSTILL;
    } else {
        
    }
}

void ModeLogic_Step(State_t *state, const Inputs_t *in, Outputs_t *out)
{
    Mode_t next;

    if ((state == NULL) || (in == NULL) || (out == NULL)) {
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
