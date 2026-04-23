/* ============================================================
 * VMU - mode logic 
 *
 * Cada integrante consegue preencher sua parte sem mexer no arquivo inteiro.
 *
 * Divisao de tarefas:
 *   [PESSOA A] handle_standstill()   STANDSTILL -> EV / START
 *   [PESSOA B] handle_ev()           EV -> STANDSTILL / REGENB / START
 *   [PESSOA C] handle_regenb()       REGENB -> STANDSTILL / EV / START
 *   [PESSOA D] internal_motion_ice_reset()
 *               handle_start()       START -> HYBRID / ICE
 *               reset ICE/HYBRID -> START quando o motor cair
 *   [GUSTAVO ] motion_ice_common_exit()
 *               handle_ice()         ICE <-> HYBRID
 *               handle_hybrid()      HYBRID <-> ICE
 *
 * Sobre as saidas:
 *   Mot_Enable, Gen_Enable e ICE_Enable sao escritos so em
 *   map_outputs(), depois que o proximo estado ja foi escolhido.
 *   Isso evita o atraso de um passo observado em mode_logic.c.
 *
 * Notas MISRA C 2012 usadas aqui:
 *   8.7 / 8.8   helpers internos declarados como static
 *   8.13        entradas recebidas por ponteiro const
 *   11.9        NULL em comparacoes de ponteiro
 *   14.4        condicoes de if escritas como expressoes booleanas
 *   15.5        retorno no fim da funcao
 *   15.6        corpo de if/switch sempre com chaves
 *   15.7        cadeia if ... else if termina com else
 *   16.1/3/4/6  switch estruturado, com default e break
 *   17.2        sem recursao
 * ============================================================ */

#include <stddef.h>            
#include "../inc/mode_logic_team.h"

/* Helpers internos de transicao. */

/* [PESSOA A] STANDSTILL
 * Transitions:
 *   STANDSTILL -> EV     : Moving vehicle, inside EV's mode range
 *                          and SOC is enough for EV.
 *   STANDSTILL -> START  : Moving vehicle but way too fast for EV
 *                          or SOC is not enough.
 *
 * Priority: EV before START (EV mode is the main target).
 *
 * Hotfix applied:
 *   - Removed the P_dem > PDEM_REGEN guard from STANDSTILL -> EV
 *     (overly restrictive for some edge cases in the model).
 *   - SOC comparison now uses >= to match the updated model spec.
 *   - START branch uses strict < on SOC so both branches stay
 *     mutually exclusive at the SOC_EV_IN boundary.
 */
static Mode_t handle_standstill(const Inputs_t *in)
{
    Mode_t next = MODE_STANDSTILL;

    /* STANDSTILL -> EV */
    if ((in->speed >  SPEED_STOP)   &&
        (in->speed <= SPEED_EV_MAX) &&
        (in->SOC   >= SOC_EV_IN)) {
        next = MODE_EV;
    }
    /* STANDSTILL -> START */
    else if ((in->speed > SPEED_STOP) &&
             ((in->speed > SPEED_EV_MAX) ||
              (in->SOC   <  SOC_EV_IN))) {
        next = MODE_START;
    }
    else {
        /* stays in STANDSTILL */
    }

    return next;
}

/* [PESSOA B] EV
 * Transitions (priority order):
 *   1. EV -> REGENB     : speed above regen threshold and
 *                         power demand entered regen range.
 *   2. EV -> START      : speed too high for EV, or power demand
 *                         requires hybrid, or SOC dropped below
 *                         EV sustain threshold (hysteresis exit).
 *   3. EV -> STANDSTILL : vehicle stopped and demand inside the
 *                         neutral stop band.
 *
 * Hysteresis note:
 *   EV entry uses SOC_EV_IN (0.37) in handle_standstill;
 *   EV exit uses SOC_EV_OUT (0.35) here. The gap between the
 *   two thresholds is what prevents chattering in and out of EV.
 *
 * Hotfix applied:
 *   - EV -> STANDSTILL: P_dem band is now inclusive on both sides
 *     (<= PDEM_STOP_HIGH and >= PDEM_STOP_LOW) to match the
 *     updated model. The other two transitions are unchanged.
 */
static Mode_t handle_ev(const Inputs_t *in)
{
    Mode_t next = MODE_EV;

    /* EV -> REGENB */
    if ((in->speed >  SPEED_REGEN) &&
        (in->P_dem <= PDEM_REGEN)) {
        next = MODE_REGENB;
    }
    /* EV -> START */
    else if ((in->speed > SPEED_EV_MAX) ||
             (in->P_dem >= PDEM_HYB_IN) ||
             (in->SOC   <  SOC_EV_OUT)) {
        next = MODE_START;
    }
    /* EV -> STANDSTILL */
    else if ((in->speed <= SPEED_STOP)     &&
             (in->P_dem <= PDEM_STOP_HIGH) &&
             (in->P_dem >= PDEM_STOP_LOW)) {
        next = MODE_STANDSTILL;
    }
    else {
        /* stays in EV */
    }

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

    /* REGENB -> START */
    if (((in->speed > SPEED_EV_MAX) && (in->P_dem >= PDEM_STOP_LOW)) ||
        (in->P_dem >= PDEM_HYB_IN) ||
        (in->SOC < SOC_EV_OUT)) {
        next = MODE_START;
    }
    /* REGENB -> STANDSTILL */
    else if (in->speed <= SPEED_STOP) {
        next = MODE_STANDSTILL;
    }
    /* REGENB -> EV */
    else if ((in->P_dem >= PDEM_STOP_LOW) &&
             (in->speed > SPEED_STOP) &&
             (in->speed <= SPEED_EV_MAX) &&
             (in->SOC > SOC_EV_IN)) {
        next = MODE_EV;
    }
    else {
        /* permanece em REGENB */
    }

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
               (in->SOC >= SOC_EV_IN)) {
        next = MODE_EV;
    } else if ((in->speed <= SPEED_STOP) &&
               (in->P_dem <= PDEM_STOP_HIGH) &&
               (in->P_dem >= PDEM_STOP_LOW)) {
        next = MODE_STANDSTILL;
    } else {
        /* continua no bloco interno atual */
    }

    return next;
}

/* [PESSOA D]
 * Reset comum de ICE/HYBRID para START quando o motor desliga.
 * Este teste entra antes das trocas internas ICE <-> HYBRID. */
static Mode_t internal_motion_ice_reset(const Inputs_t *in, Mode_t current_in_block)
{
    Mode_t next = current_in_block;

    if (in->wEng <= ENG_OFF) {
        next = MODE_START;
    } else {
        /* permanece no estado atual */
    }

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
        if ((in->wEng > ENG_ON) &&
            (in->SOC >= SOC_MID) &&
            ((in->speed > SPEED_EV_MAX) ||
             (in->P_dem >= PDEM_HYB_MID))) {
            next = MODE_HYBRID;
        } else if ((in->wEng > ENG_ON) &&
                   ((in->SOC < SOC_MID) ||
                    ((in->speed <= SPEED_EV_MAX) &&
                     (in->P_dem < PDEM_HYB_MID)))) {
            next = MODE_ICE;
        } else {
            /* permanece em START */
        }
    } else {
        /* ja saiu do bloco */
    }

    return next;
}

/* handle_ice
 * Ordem:
 *   1) tenta sair do bloco
 *   2) se ficar em ICE, verifica reset para START
 *   3) se ainda ficar em ICE, verifica ICE -> HYBRID
 */
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
            /* permanece em HYBRID */
        }
    } else {
        /* saiu de HYBRID por reset ou por saida externa do bloco */
    }

    return next;
}

/* Unico lugar que escreve os enables.
 * O mapeamento acontece depois da decisao de proximo estado. */
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
            /* modo invalido: desliga tudo por seguranca */
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
        /* ponteiro nulo: nada a fazer */
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
