#ifndef MODE_LOGIC_H
#define MODE_LOGIC_H

/* ============================================================
 * VMU - Mode Logic (Original Implementation)
 *
 * Requirements attended:
 *   SysHLR03 - Calibratable and Hysteretic Mode Transitions
 *   SwHLR01  - Execution Interface
 *   SwHLR10  - Unique Output Mapping
 *   SwHLR11  - Manual-Code Structure and Traceability
 *
 * MISRA C 2012 Compliance:
 *   - Uses uint8_t for boolean outputs (Rule 10.1)
 *   - const input parameters (Rule 8.13)
 * ============================================================ */

#include <stdint.h>

/* Calibratable threshold values for mode transitions */
#define ENG_ON          (800.0f)
#define ENG_OFF         (790.0f)
#define SPEED_STOP      (0.5f)
#define SPEED_REGEN     (5.0f)
#define SPEED_EV_MAX    (35.0f)
#define PDEM_REGEN      (-5.0f)
#define PDEM_STOP_LOW   (-1.0f)
#define PDEM_STOP_HIGH  (1.0f)
#define PDEM_HYB_IN     (55.0f)
#define PDEM_HYB_OUT    (40.0f)
#define SOC_EV_IN       (0.37f)
#define SOC_EV_OUT      (0.35f)
#define SOC_LOW         (0.25f)
#define SOC_MID         (0.30f)

/* VMU operating modes */
typedef enum {
    MODE_STANDSTILL = 0,
    MODE_EV         = 1,
    MODE_REGENB     = 2,
    MODE_START      = 3,
    MODE_ICE        = 4,
    MODE_HYBRID     = 5
} Mode_t;

/* External inputs for mode logic calculation */
typedef struct {
    float speed;   /* km/h */
    float P_dem;   /* kW   */
    float SOC;     /* 0..1 */
    float wEng;    /* rpm  */
} Inputs_t;

/* Binary enable outputs for motor, generator, and ICE */
typedef struct {
    uint8_t Mot_Enable;
    uint8_t Gen_Enable;
    uint8_t ICE_Enable;
} Outputs_t;

/* Internal state machine state */
typedef struct {
    Mode_t current_mode;
} State_t;

void ModeLogic_Init(State_t *state);
void ModeLogic_Step(State_t *state, const Inputs_t *in, Outputs_t *out);

#endif