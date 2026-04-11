#ifndef MODE_LOGIC_H
#define MODE_LOGIC_H

// Program routine for Person 1 - Header and shared definitions #21
// Requirements attended
// SysHLR03 - Calibratable and Hysteretic Mode Transitions
// SwHLR01  - Execution Interface
// SwHLR10  - Unique Output Mapping
// SwHLR11  - Manual-Code Structure and Traceability

#include <stdint.h>   /* uint8_t, int8_t */

// Defining all constants thresholds
#define ENG_ON          800.0f
#define ENG_OFF         790.0f
#define SPEED_STOP      0.5f
#define SPEED_REGEN     5.0f
#define SPEED_EV_MAX    35.0f
#define PDEM_REGEN      -5.0f
#define PDEM_STOP_LOW   -1.0f
#define PDEM_STOP_HIGH  1.0f
#define PDEM_HYB_IN     55.0f
#define PDEM_HYB_OUT    40.0f
#define SOC_EV_IN       0.37f
#define SOC_EV_OUT      0.35f
#define SOC_LOW         0.25f
#define SOC_MID         0.30f

// VMU STATEFLOW MODES
typedef enum {
    MODE_STANDSTILL = 0,
    MODE_EV,
    MODE_REGEN,
    MODE_START,
    MODE_ICE,
    MODE_HYBRID
} Mode_t;

// External inputs (local copies)
typedef struct {
    float   speed;
    float   P_dem;
    float   SOC;
    float   wEng;
} Inputs_t;

// Internal mode outputs — uint8_t: flags binárias 0/1, sem sinal
typedef struct {
    uint8_t Mot_Enable;   /* 0 = disabled, 1 = enabled */
    uint8_t Gen_Enable;   /* 0 = disabled, 1 = enabled */
    uint8_t ICE_Enable;   /* 0 = disabled, 1 = enabled */
} Outputs_t;

// State — uint8_t: enum Mode_t cabe em 0–5, tamanho fixo para embedded
typedef struct {
    uint8_t current_mode; /* cast para Mode_t ao usar: (Mode_t)state.current_mode */
} State_t;

void ModeLogic_Init(State_t* state);
void ModeLogic_Step(State_t* state, Inputs_t* in, Outputs_t* out);

#endif /* MODE_LOGIC_H */
