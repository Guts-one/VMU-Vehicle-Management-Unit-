# Transicoes de estados - `HEV_powersplit_adapted`

## Escopo

Este documento resume a maquina de estados do chart Stateflow `Control/Mode Logic`, extraida do modelo:

## Mapeamento de nomes entre o modelo e o codigo C

| Modelo | Codigo C |
| --- | --- |
| `StandStill` | `MODE_STANDSTILL` |
| `EV_mode` | `MODE_EV` |
| `RegenB_mode` | `MODE_REGENB` |
| `Motion_mode_ICE/Start_mode` | `MODE_START` |
| `Motion_mode_ICE/ICE_mode` | `MODE_ICE` |
| `Motion_mode_ICE/Hybrid_mode` | `MODE_HYBRID` |
| `charge` | `SOC` |
| `engine_speed` | `wEng` |
| `speed` | `speed` |
| `P_dem` | `P_dem` |

## Limiares usados pelo modelo

Os valores abaixo batem com `mode_logic_team.h`.

| Nome usado no C | Valor | Papel no modelo |
| --- | ---: | --- |
| `ENG_ON` | `800.0` | `EngOnRPM` |
| `ENG_OFF` | `790.0` | `EngOffRPM` |
| `SPEED_STOP` | `0.5` | parada / retorno para `StandStill` |
| `SPEED_REGEN` | `5.0` | entrada ou saida de `RegenB_mode` |
| `SPEED_EV_MAX` | `35.0` | limite superior da faixa EV |
| `PDEM_REGEN` | `-5.0` | limiar de frenagem regenerativa |
| `PDEM_STOP_LOW` | `-1.0` | faixa neutra inferior |
| `PDEM_STOP_HIGH` | `1.0` | faixa neutra superior |
| `PDEM_HYB_IN` | `50.0` | EV/RegenB para `Motion_mode_ICE` |
| `PDEM_HYB_OUT` | `40.0` | `Motion_mode_ICE` para EV |
| `PDEM_HYB_MID` | `15.0` | `Start`/`ICE` para `Hybrid` |
| `PDEM_HYB_LOW` | `10.0` | `Hybrid` para `ICE` |
| `SOC_EV_IN` | `0.37` | entrada/manutencao em EV |
| `SOC_EV_OUT` | `0.35` | saida de EV para `Motion_mode_ICE` |
| `SOC_MID` | `0.30` | divisao `Hybrid` x `ICE` |
| `SOC_LOW` | `0.25` | queda de `Hybrid` para `ICE` |

## Estado inicial

- Entrada do chart principal: `StandStill`
- Entrada de `Motion_mode_ICE`: `Start_mode`

## Saidas por estado

| Estado no modelo | Estado no C | `Mot_Enable` | `Gen_Enable` | `ICE_Enable` |
| --- | --- | ---: | ---: | ---: |
| `StandStill` | `MODE_STANDSTILL` | 0 | 0 | 0 |
| `EV_mode` | `MODE_EV` | 1 | 0 | 0 |
| `RegenB_mode` | `MODE_REGENB` | 1 | 0 | 0 |
| `Start_mode` | `MODE_START` | 1 | 1 | 0 |
| `ICE_mode` | `MODE_ICE` | 0 | 1 | 1 |
| `Hybrid_mode` | `MODE_HYBRID` | 1 | 1 | 1 |


## Transicoes do nivel principal

### Saidas de `StandStill`

Prioridade de avaliacao:

1. `StandStill -> EV_mode`
   - Guarda do modelo: `[speed>0.5 && speed<=35 && charge>=0.37]`
   - Equivalente no C: `speed > SPEED_STOP && speed <= SPEED_EV_MAX && SOC >= SOC_EV_IN`

2. `StandStill -> Motion_mode_ICE`
   - Guarda do modelo: `[speed>0.5 && (speed>35 || charge<0.37)]`
   - Equivalente no C: `speed > SPEED_STOP && (speed > SPEED_EV_MAX || SOC < SOC_EV_IN)`

### Saidas de `EV_mode`

Prioridade de avaliacao:

1. `EV_mode -> RegenB_mode`
   - Guarda do modelo: `[speed>5 && P_dem<=-5]`
   - Equivalente no C: `speed > SPEED_REGEN && P_dem <= PDEM_REGEN`

2. `EV_mode -> Motion_mode_ICE`
   - Guarda do modelo: `[speed>35 || P_dem>=50 || charge<0.35]`
   - Equivalente no C: `speed > SPEED_EV_MAX || P_dem >= PDEM_HYB_IN || SOC < SOC_EV_OUT`

3. `EV_mode -> StandStill`
   - Guarda do modelo: `[speed<=0.5 && P_dem<=1 && P_dem>=-1]`
   - Equivalente no C: `speed <= SPEED_STOP && P_dem <= PDEM_STOP_HIGH && P_dem >= PDEM_STOP_LOW`

### Saídas de `RegenB_mode`

Prioridade de avaliação:

1. `RegenB_mode -> Motion_mode_ICE`
   - Guarda do modelo: `[ ((speed>35) && (P_dem>=-1)) || charge<0.35 ]`
   - Equivalente no C: `((speed > SPEED_EV_MAX) && (P_dem >= PDEM_STOP_LOW)) || (SOC < SOC_EV_OUT)`

2. `RegenB_mode -> StandStill`
   - Guarda do modelo: `[speed<=0.5 && P_dem<=1 && P_dem>=-1]`
   - Equivalente no C: `speed <= SPEED_STOP && P_dem <= PDEM_STOP_HIGH && P_dem >= PDEM_STOP_LOW`

3. `RegenB_mode -> EV_mode`
   - Guarda do modelo: `[P_dem>=-1 && speed>0.5 && speed<=35 && charge>=0.35]`
   - Equivalente no C: `P_dem >= PDEM_STOP_LOW && speed > SPEED_STOP && speed <= SPEED_EV_MAX && SOC >= SOC_EV_OUT`

### Saidas de `Motion_mode_ICE` para estados externos

Prioridade de avaliacao:

1. `Motion_mode_ICE -> RegenB_mode`
   - Guarda do modelo: `[engine_speed>EngOnRPM && speed>5 && P_dem<=-5]`
   - Equivalente no C: `wEng > ENG_ON && speed > SPEED_REGEN && P_dem <= PDEM_REGEN`

2. `Motion_mode_ICE -> EV_mode`
   - Guarda do modelo: `[engine_speed>EngOnRPM && P_dem<=40 && P_dem>=-1 && speed>0.5 && speed<=35 && charge>=0.37]`
   - Equivalente no C: `wEng > ENG_ON && P_dem <= PDEM_HYB_OUT && P_dem >= PDEM_STOP_LOW && speed > SPEED_STOP && speed <= SPEED_EV_MAX && SOC >= SOC_EV_IN`

3. `Motion_mode_ICE -> StandStill`
   - Guarda do modelo: `[speed<=0.5 && P_dem<=1 && P_dem>=-1]`
   - Equivalente no C: `speed <= SPEED_STOP && P_dem <= PDEM_STOP_HIGH && P_dem >= PDEM_STOP_LOW`

## Transições internas de `Motion_mode_ICE`

### Estado inicial interno

- `ENTRY -> Start_mode`

### Saidas de `Start_mode`

Prioridade de avaliacao:

1. `Start_mode -> Hybrid_mode`
   - Guarda do modelo: `[engine_speed>EngOnRPM && charge>=0.30 && (speed>35 || P_dem>=15)]`
   - Equivalente no C: `wEng > ENG_ON && SOC >= SOC_MID && (speed > SPEED_EV_MAX || P_dem >= PDEM_HYB_MID)`

2. `Start_mode -> ICE_mode`
   - Guarda do modelo: `[engine_speed>EngOnRPM && (charge<0.30 || (speed<=35 && P_dem<15))]`
   - Equivalente no C: `wEng > ENG_ON && (SOC < SOC_MID || (speed <= SPEED_EV_MAX && P_dem < PDEM_HYB_MID))`

### Saidas de `ICE_mode`

Prioridade de avaliacao:

1. `ICE_mode -> Start_mode`
   - Guarda do modelo: `[engine_speed<=EngOffRPM]`
   - Equivalente no C: `wEng <= ENG_OFF`

2. `ICE_mode -> Hybrid_mode`
   - Guarda do modelo: `[P_dem>=15 && charge>=0.30]`
   - Equivalente no C: `P_dem >= PDEM_HYB_MID && SOC >= SOC_MID`

### Saidas de `Hybrid_mode`

Prioridade de avaliacao:

1. `Hybrid_mode -> Start_mode`
   - Guarda do modelo: `[engine_speed<=EngOffRPM]`
   - Equivalente no C: `wEng <= ENG_OFF`

2. `Hybrid_mode -> ICE_mode`
   - Guarda do modelo: `[P_dem<=10 || charge<0.25]`
   - Equivalente no C: `P_dem <= PDEM_HYB_LOW || SOC < SOC_LOW`


