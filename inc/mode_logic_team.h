#ifndef MODE_LOGIC_TEAM_H
#define MODE_LOGIC_TEAM_H

/* ============================================================
 * VMU - mode logic
 *
 * Embedded fixed-point interface:
 *   speed_dkph   = vehicle speed in 0.1 km/h
 *   p_dem_dkw    = demanded power in 0.1 kW
 *   soc_q10000   = battery state of charge in 0..10000
 *   weng_rpm     = engine speed in rpm
 *
 * Requisitos atendidos:
 *   SysHLR03 - Calibratable and Hysteretic Mode Transitions
 *   SwHLR01  - Execution Interface
 *   SwHLR10  - Unique Output Mapping
 *   SwHLR11  - Manual-Code Structure and Traceability
 *
 * ============================================================ */

#include <stdint.h>  

/* Thresholds calibraveis em escala inteira.
 * Valores fisicos alinhados com o modelo HEV_powersplit_adapted. */

#define ENG_ON_RPM             (800U)
#define ENG_OFF_RPM            (790U)
#define SPEED_STOP_DKPH        (5U)
#define SPEED_REGEN_DKPH       (50U)
#define SPEED_EV_MAX_DKPH      (350U)
#define PDEM_REGEN_DKW         (-50)
#define PDEM_STOP_LOW_DKW      (-10)
#define PDEM_STOP_HIGH_DKW     (10)
#define PDEM_HYB_IN_DKW        (500)
#define PDEM_HYB_OUT_DKW       (400)
#define PDEM_HYB_MID_DKW       (150)
#define PDEM_HYB_LOW_DKW       (100)
#define SOC_EV_IN_Q10000       (3700U)
#define SOC_EV_OUT_Q10000      (3500U)
#define SOC_LOW_Q10000         (2500U)
#define SOC_MID_Q10000         (3000U)

/* Modos internos da VMU. */
typedef enum {
    MODE_STANDSTILL = 0,
    MODE_EV         = 1,
    MODE_REGENB     = 2,
    MODE_START      = 3,
    MODE_ICE        = 4,
    MODE_HYBRID     = 5
} Mode_t;

/* Entradas externas em fixed-point. O step nao depende de globais. */
typedef struct {
    uint16_t speed_dkph;
    int16_t p_dem_dkw;
    uint16_t soc_q10000;
    uint16_t weng_rpm;
} Inputs_t;

/* Saidas binarias.
 * uint8_t reduz o tamanho da struct em relacao a int. */
typedef struct {
    uint8_t Mot_Enable;
    uint8_t Gen_Enable;
    uint8_t ICE_Enable;
} Outputs_t;

/* Estado interno da maquina. */
typedef struct {
    Mode_t current_mode;
} State_t;

/* Inputs_t entra como const para reforcar que o step nao altera as entradas. */
void ModeLogic_Init(State_t *state);
void ModeLogic_Step(State_t *state, const Inputs_t *in, Outputs_t *out);

#endif 
