/* VMU - mode logic */

#include <stddef.h>
#include "../inc/mode_logic_team.h"

static uint8_t flag_speed_gt_stop(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->speed_dkph > SPEED_STOP_DKPH) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_speed_le_stop(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->speed_dkph <= SPEED_STOP_DKPH) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_speed_gt_regen(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->speed_dkph > SPEED_REGEN_DKPH) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_speed_gt_ev_max(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->speed_dkph > SPEED_EV_MAX_DKPH) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_speed_le_ev_max(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->speed_dkph <= SPEED_EV_MAX_DKPH) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_p_dem_le_regen(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->p_dem_dkw <= PDEM_REGEN_DKW) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_p_dem_ge_hyb_in(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->p_dem_dkw >= PDEM_HYB_IN_DKW) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_p_dem_le_hyb_out(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->p_dem_dkw <= PDEM_HYB_OUT_DKW) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_p_dem_le_stop_high(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->p_dem_dkw <= PDEM_STOP_HIGH_DKW) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_p_dem_ge_stop_low(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->p_dem_dkw >= PDEM_STOP_LOW_DKW) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_p_dem_ge_hyb_mid(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->p_dem_dkw >= PDEM_HYB_MID_DKW) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_p_dem_le_hyb_low(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->p_dem_dkw <= PDEM_HYB_LOW_DKW) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_soc_ge_ev_in(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->soc_q10000 >= SOC_EV_IN_Q10000) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_soc_lt_ev_out(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->soc_q10000 < SOC_EV_OUT_Q10000) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_soc_ge_mid(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->soc_q10000 >= SOC_MID_Q10000) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_soc_lt_low(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->soc_q10000 < SOC_LOW_Q10000) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_weng_gt_on(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->weng_rpm > ENG_ON_RPM) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t flag_weng_le_off(const Inputs_t *in)
{
    uint8_t result = 0U;

    if (in->weng_rpm <= ENG_OFF_RPM) {
        result = 1U;
    } else {
    }

    return result;
}

static uint8_t guard_standstill_to_ev(const Inputs_t *in)
{
    const uint8_t speed_gt_stop = flag_speed_gt_stop(in);
    const uint8_t speed_le_ev_max = flag_speed_le_ev_max(in);
    const uint8_t soc_ge_ev_in = flag_soc_ge_ev_in(in);

    return (uint8_t)((uint8_t)(speed_gt_stop & speed_le_ev_max) & soc_ge_ev_in);
}

static uint8_t guard_standstill_to_start(const Inputs_t *in)
{
    const uint8_t speed_gt_stop = flag_speed_gt_stop(in);

    return speed_gt_stop;
}

static uint8_t guard_to_regenb(const Inputs_t *in)
{
    const uint8_t speed_gt_regen = flag_speed_gt_regen(in);
    const uint8_t p_dem_le_regen = flag_p_dem_le_regen(in);

    return (uint8_t)(speed_gt_regen & p_dem_le_regen);
}

static uint8_t guard_ev_to_start(const Inputs_t *in)
{
    const uint8_t speed_gt_ev_max = flag_speed_gt_ev_max(in);
    const uint8_t p_dem_ge_hyb_in = flag_p_dem_ge_hyb_in(in);
    const uint8_t soc_lt_ev_out = flag_soc_lt_ev_out(in);

    return (uint8_t)((uint8_t)(speed_gt_ev_max | p_dem_ge_hyb_in) | soc_lt_ev_out);
}

static uint8_t guard_to_standstill(const Inputs_t *in)
{
    const uint8_t speed_le_stop = flag_speed_le_stop(in);
    const uint8_t p_dem_le_stop_high = flag_p_dem_le_stop_high(in);
    const uint8_t p_dem_ge_stop_low = flag_p_dem_ge_stop_low(in);

    return (uint8_t)((uint8_t)(speed_le_stop & p_dem_le_stop_high) & p_dem_ge_stop_low);
}

static uint8_t guard_regenb_to_start(const Inputs_t *in)
{
    const uint8_t speed_gt_ev_max = flag_speed_gt_ev_max(in);
    const uint8_t p_dem_ge_stop_low = flag_p_dem_ge_stop_low(in);
    const uint8_t soc_lt_ev_out = flag_soc_lt_ev_out(in);
    const uint8_t high_speed_positive_demand =
        (uint8_t)(speed_gt_ev_max & p_dem_ge_stop_low);

    return (uint8_t)(high_speed_positive_demand | soc_lt_ev_out);
}

static uint8_t guard_regenb_to_ev(const Inputs_t *in)
{
    const uint8_t p_dem_ge_stop_low = flag_p_dem_ge_stop_low(in);
    const uint8_t speed_gt_stop = flag_speed_gt_stop(in);

    return (uint8_t)(p_dem_ge_stop_low & speed_gt_stop);
}

static uint8_t guard_motion_to_ev(const Inputs_t *in)
{
    const uint8_t weng_gt_on = flag_weng_gt_on(in);
    const uint8_t p_dem_le_hyb_out = flag_p_dem_le_hyb_out(in);
    const uint8_t p_dem_ge_stop_low = flag_p_dem_ge_stop_low(in);
    const uint8_t speed_gt_stop = flag_speed_gt_stop(in);
    const uint8_t speed_le_ev_max = flag_speed_le_ev_max(in);
    const uint8_t soc_ge_ev_in = flag_soc_ge_ev_in(in);

    return (uint8_t)((uint8_t)((uint8_t)((uint8_t)((uint8_t)(weng_gt_on &
                                                                  p_dem_le_hyb_out) &
                                                        p_dem_ge_stop_low) &
                                              speed_gt_stop) &
                                    speed_le_ev_max) &
                     soc_ge_ev_in);
}

static uint8_t guard_start_to_hybrid(const Inputs_t *in)
{
    const uint8_t weng_gt_on = flag_weng_gt_on(in);
    const uint8_t soc_ge_mid = flag_soc_ge_mid(in);
    const uint8_t speed_gt_ev_max = flag_speed_gt_ev_max(in);
    const uint8_t p_dem_ge_hyb_mid = flag_p_dem_ge_hyb_mid(in);
    const uint8_t high_load = (uint8_t)(speed_gt_ev_max | p_dem_ge_hyb_mid);

    return (uint8_t)((uint8_t)(weng_gt_on & soc_ge_mid) & high_load);
}

static uint8_t guard_start_to_ice(const Inputs_t *in)
{
    const uint8_t weng_gt_on = flag_weng_gt_on(in);

    return weng_gt_on;
}

static uint8_t guard_ice_to_hybrid(const Inputs_t *in)
{
    const uint8_t p_dem_ge_hyb_mid = flag_p_dem_ge_hyb_mid(in);
    const uint8_t soc_ge_mid = flag_soc_ge_mid(in);

    return (uint8_t)(p_dem_ge_hyb_mid & soc_ge_mid);
}

static uint8_t guard_hybrid_to_ice(const Inputs_t *in)
{
    const uint8_t p_dem_le_hyb_low = flag_p_dem_le_hyb_low(in);
    const uint8_t soc_lt_low = flag_soc_lt_low(in);

    return (uint8_t)(p_dem_le_hyb_low | soc_lt_low);
}

/* Priority: EV before START. */
static Mode_t handle_standstill(const Inputs_t *in)
{
    Mode_t next = MODE_STANDSTILL;
    const uint8_t to_ev = guard_standstill_to_ev(in);
    const uint8_t to_start = guard_standstill_to_start(in);

    if (to_ev != 0U) {
        next = MODE_EV;
    } else if (to_start != 0U) {
        next = MODE_START;
    } else {
    }

    return next;
}

/* EV entry: SOC_EV_IN, exit: SOC_EV_OUT -- hysteresis gap. */
static Mode_t handle_ev(const Inputs_t *in)
{
    Mode_t next = MODE_EV;
    const uint8_t to_regenb = guard_to_regenb(in);
    const uint8_t to_start = guard_ev_to_start(in);
    const uint8_t to_standstill = guard_to_standstill(in);

    if (to_regenb != 0U) {
        next = MODE_REGENB;
    } else if (to_start != 0U) {
        next = MODE_START;
    } else if (to_standstill != 0U) {
        next = MODE_STANDSTILL;
    } else {
    }

    return next;
}

static Mode_t handle_regenb(const Inputs_t *in)
{
    Mode_t next = MODE_REGENB;
    const uint8_t to_start = guard_regenb_to_start(in);
    const uint8_t to_standstill = guard_to_standstill(in);
    const uint8_t to_ev = guard_regenb_to_ev(in);

    if (to_start != 0U) {
        next = MODE_START;
    } else if (to_standstill != 0U) {
        next = MODE_STANDSTILL;
    } else if (to_ev != 0U) {
        next = MODE_EV;
    } else {
    }

    return next;
}

/* Common exit from Motion_mode_ICE (shared by START, ICE, HYBRID). */
static Mode_t motion_ice_common_exit(const Inputs_t *in, Mode_t current_in_block)
{
    Mode_t next = current_in_block;
    const uint8_t to_regenb = (uint8_t)(flag_weng_gt_on(in) & guard_to_regenb(in));
    const uint8_t to_ev = guard_motion_to_ev(in);
    const uint8_t to_standstill = guard_to_standstill(in);

    if (to_regenb != 0U) {
        next = MODE_REGENB;
    } else if (to_ev != 0U) {
        next = MODE_EV;
    } else if (to_standstill != 0U) {
        next = MODE_STANDSTILL;
    } else {
    }

    return next;
}

/* Reset to START when engine stalls (checked before ICE <-> HYBRID). */
static Mode_t internal_motion_ice_reset(const Inputs_t *in, Mode_t current_in_block)
{
    Mode_t next = current_in_block;

    if (flag_weng_le_off(in) != 0U) {
        next = MODE_START;
    } else {
    }

    return next;
}

static Mode_t handle_start(const Inputs_t *in)
{
    Mode_t next;

    next = motion_ice_common_exit(in, MODE_START);

    if (next == MODE_START) {
        const uint8_t to_hybrid = guard_start_to_hybrid(in);
        const uint8_t to_ice = guard_start_to_ice(in);

        if (to_hybrid != 0U) {
            next = MODE_HYBRID;
        } else if (to_ice != 0U) {
            next = MODE_ICE;
        } else {
        }
    } else {
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
    }

    if (next == MODE_ICE) {
        if (guard_ice_to_hybrid(in) != 0U) {
            next = MODE_HYBRID;
        } else {
        }
    } else {
    }

    return next;
}

static Mode_t handle_hybrid(const Inputs_t *in)
{
    Mode_t next;

    next = motion_ice_common_exit(in, MODE_HYBRID);

    if (next == MODE_HYBRID) {
        next = internal_motion_ice_reset(in, next);
    } else {
    }

    if (next == MODE_HYBRID) {
        if (guard_hybrid_to_ice(in) != 0U) {
            next = MODE_ICE;
        } else {
        }
    } else {
    }

    return next;
}

static void write_outputs(Mode_t mode, Outputs_t *out)
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

/* Public API consumed by test/ and external clients */
/* cppcheck-suppress misra-c2012-8.7 */
/* cppcheck-suppress unusedFunction */
void ModeLogic_Init(State_t *state)
{
    if (state != NULL) {
        state->current_mode = MODE_STANDSTILL;
    } else {
    }
}

/* Public API consumed by test/ and external clients */
/* cppcheck-suppress misra-c2012-8.7 */
/* cppcheck-suppress unusedFunction */
void ModeLogic_Step(State_t *state, const Inputs_t *in, Outputs_t *out)
{
    if ((state != NULL) && (in != NULL) && (out != NULL)) {
        Mode_t next = state->current_mode;

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
        write_outputs(next, out);
    } else {
    }
}
