#ifndef MODE_LOGIC_TEAM_H
#define MODE_LOGIC_TEAM_H

/* ============================================================
 * VMU - mode logic 
 *
 *
 * Pontos mantidos desta versao:
 *   1) saidas em uint8_t
 *   2) entradas recebidas por ponteiro const
 *   3) um unico ponto para escrever Mot/Gen/ICE_Enable
 *
 * Requisitos atendidos:
 *   SysHLR03 - Calibratable and Hysteretic Mode Transitions
 *   SwHLR01  - Execution Interface
 *   SwHLR10  - Unique Output Mapping
 *   SwHLR11  - Manual-Code Structure and Traceability
 *
 * ============================================================ */

#include <stdint.h>  

/* Thresholds calibraveis.
 * Valores alinhados com o modelo HEV_powersplit_adapted. */

#define ENG_ON          (800.0f)
#define ENG_OFF         (790.0f)
#define SPEED_STOP      (0.5f)
#define SPEED_REGEN     (5.0f)
#define SPEED_EV_MAX    (35.0f)
#define PDEM_REGEN      (-5.0f)
#define PDEM_STOP_LOW   (-1.0f)
#define PDEM_STOP_HIGH  (1.0f)
#define PDEM_HYB_IN     (50.0f)   /* no stateflow novo: era 55 */
#define PDEM_HYB_OUT    (40.0f)
#define PDEM_HYB_MID    (15.0f)   /* Start<->Hybrid e ICE->Hybrid */
#define PDEM_HYB_LOW    (10.0f)   /* retorno de Hybrid para ICE */
#define SOC_EV_IN       (0.37f)
#define SOC_EV_OUT      (0.35f)
#define SOC_LOW         (0.25f)
#define SOC_MID         (0.30f)

/* Modos internos da VMU. */
typedef enum {
    MODE_STANDSTILL = 0,
    MODE_EV         = 1,
    MODE_REGENB     = 2,
    MODE_START      = 3,
    MODE_ICE        = 4,
    MODE_HYBRID     = 5
} Mode_t;

/* Entradas externas.
 * O step nao depende de globais; tudo entra por esta struct. */
typedef struct {
    float speed;   /* km/h */
    float P_dem;   /* kW   */
    float SOC;     /* 0..1 */
    float wEng;    /* rpm  */
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

/* Inputs_t entra como const para reforcar que o step nao
 * altera as entradas recebidas. (misra c) */
void ModeLogic_Init(State_t *state);
void ModeLogic_Step(State_t *state, const Inputs_t *in, Outputs_t *out);

#endif 
