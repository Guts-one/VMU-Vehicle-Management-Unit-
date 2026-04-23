# Mapeamento de requisitos da secao 4 por responsavel

Este arquivo usa como fonte os requisitos da Secao 4 e os aloca por responsavel com base na divisao de tarefas declarada em `mode_logic_team.c`.

Observacoes:
- Os requisitos `SysHLR01`, `SysHLR02` e `SysHLR03` nao foram alocados individualmente, porque o particionamento do codigo foi feito por familias de transicao e por transicoes de software.
- Os requisitos `SwHLR08` e `SwHLR09` aparecem como compartilhados entre `Pessoa D` e `Pessoa E`, porque essas familias foram divididas entre o reset para `Start` e as trocas internas `ICE <-> HYBRID`.

## Danilo - Person A

### Requisitos da secao 4.2

| ID | Vinculo | Requirement statement |
| --- | --- | --- |
| `SwHLR03` | principal | While the active software mode is the standstill mode, the software shall evaluate exits to EV mode and Start mode in the priority order defined by the model. |

### Requisitos da secao 4.3

| ID | Requirement statement |
| --- | --- |
| `SwLLR01` | When the active software mode is the standstill mode and speed > SPEED_STOP && speed <= SPEED_EV_MAX && SOC >= SOC_EV_IN, the software shall transition to EV mode. |
| `SwLLR02` | When the active software mode is the standstill mode and speed > SPEED_STOP && (speed > SPEED_EV_MAX || SOC < SOC_EV_IN), the software shall transition to Start mode. |

## Marinel - Person B

### Requisitos da secao 4.2

| ID | Vinculo | Requirement statement |
| --- | --- | --- |
| `SwHLR04` | principal | While the active software mode is EV mode, the software shall evaluate exits to regenerative-braking mode, Start mode, and standstill mode in the priority order defined by the model. |

### Requisitos da secao 4.3

| ID | Requirement statement |
| --- | --- |
| `SwLLR03` | When the active software mode is EV mode and speed > SPEED_REGEN && P_dem <= PDEM_REGEN, the software shall transition to the regenerative-braking mode. |
| `SwLLR04` | When the active software mode is EV mode and (speed > SPEED_EV_MAX || P_dem >= PDEM_HYB_IN || SOC < SOC_EV_OUT), the software shall transition to Start mode. |
| `SwLLR05` | When the active software mode is EV mode and speed <= SPEED_STOP && P_dem <= PDEM_STOP_HIGH && P_dem >= PDEM_STOP_LOW, the software shall transition to the standstill mode. |

## Bruna - Person C

### Requisitos da secao 4.2

| ID | Vinculo | Requirement statement |
| --- | --- | --- |
| `SwHLR05` | principal | While the active software mode is the regenerative-braking mode, the software shall evaluate exits to Start mode, standstill mode, and EV mode in the priority order defined by the model. |

### Requisitos da secao 4.3

| ID | Requirement statement |
| --- | --- |
| `SwLLR06` | When the active software mode is the regenerative-braking mode and (((speed > SPEED_EV_MAX) && (P_dem >= PDEM_STOP_LOW)) || SOC < SOC_EV_OUT), the software shall transition to Start mode. |
| `SwLLR07` | When the active software mode is the regenerative-braking mode and speed <= SPEED_STOP && P_dem <= PDEM_STOP_HIGH && P_dem >= PDEM_STOP_LOW, the software shall transition to the standstill mode. |
| `SwLLR08` | When the active software mode is the regenerative-braking mode and P_dem >= PDEM_STOP_LOW && speed > SPEED_STOP && speed <= SPEED_EV_MAX && SOC >= SOC_EV_OUT, the software shall transition to EV mode. |

## Hugo - Person D

### Requisitos da secao 4.2

| ID | Vinculo | Requirement statement |
| --- | --- | --- |
| `SwHLR07` | principal | While the active software mode is Start and no higher-priority engine-supported external exit is active, the software shall evaluate internal transitions to Hybrid mode and ICE mode in the priority order defined by the model. |
| `SwHLR08` | compartilhado | While the active software mode is ICE and no higher-priority engine-supported external exit is active, the software shall evaluate internal transitions to Start mode and Hybrid mode in the priority order defined by the model. |
| `SwHLR09` | compartilhado | While the active software mode is Hybrid and no higher-priority engine-supported external exit is active, the software shall evaluate internal transitions to Start mode and ICE mode in the priority order defined by the model. |

### Requisitos da secao 4.3

| ID | Requirement statement |
| --- | --- |
| `SwLLR18` | When the active software mode is Start mode and wEng > ENG_ON && SOC >= SOC_MID && (speed > SPEED_EV_MAX || P_dem >= PDEM_HYB_MID), the software shall transition to Hybrid mode. |
| `SwLLR19` | When the active software mode is Start mode and wEng > ENG_ON && (SOC < SOC_MID || (speed <= SPEED_EV_MAX && P_dem < PDEM_HYB_MID)), the software shall transition to ICE mode. |
| `SwLLR20` | When the active software mode is ICE mode and wEng <= ENG_OFF, the software shall transition to Start mode. |
| `SwLLR22` | When the active software mode is Hybrid mode and wEng <= ENG_OFF, the software shall transition to Start mode. |

## Gustavo - Person E

### Requisitos da secao 4.2

| ID | Vinculo | Requirement statement |
| --- | --- | --- |
| `SwHLR06` | principal | While the active software mode is Start, ICE, or Hybrid, the software shall evaluate exits to regenerative-braking mode, EV mode, and standstill mode before any internal transition within the engine-supported mode representation. |
| `SwHLR08` | compartilhado | While the active software mode is ICE and no higher-priority engine-supported external exit is active, the software shall evaluate internal transitions to Start mode and Hybrid mode in the priority order defined by the model. |
| `SwHLR09` | compartilhado | While the active software mode is Hybrid and no higher-priority engine-supported external exit is active, the software shall evaluate internal transitions to Start mode and ICE mode in the priority order defined by the model. |

### Requisitos da secao 4.3

| ID | Requirement statement |
| --- | --- |
| `SwLLR09` | When the active software mode is Start mode and wEng > ENG_ON && speed > SPEED_REGEN && P_dem <= PDEM_REGEN, the software shall transition to the regenerative-braking mode. |
| `SwLLR10` | When the active software mode is ICE mode and wEng > ENG_ON && speed > SPEED_REGEN && P_dem <= PDEM_REGEN, the software shall transition to the regenerative-braking mode. |
| `SwLLR11` | When the active software mode is Hybrid mode and wEng > ENG_ON && speed > SPEED_REGEN && P_dem <= PDEM_REGEN, the software shall transition to the regenerative-braking mode. |
| `SwLLR12` | When the active software mode is Start mode and wEng > ENG_ON && P_dem <= PDEM_HYB_OUT && P_dem >= PDEM_STOP_LOW && speed > SPEED_STOP && speed <= SPEED_EV_MAX && SOC >= SOC_EV_IN, the software shall transition to EV mode. |
| `SwLLR13` | When the active software mode is ICE mode and wEng > ENG_ON && P_dem <= PDEM_HYB_OUT && P_dem >= PDEM_STOP_LOW && speed > SPEED_STOP && speed <= SPEED_EV_MAX && SOC >= SOC_EV_IN, the software shall transition to EV mode. |
| `SwLLR14` | When the active software mode is Hybrid mode and wEng > ENG_ON && P_dem <= PDEM_HYB_OUT && P_dem >= PDEM_STOP_LOW && speed > SPEED_STOP && speed <= SPEED_EV_MAX && SOC >= SOC_EV_IN, the software shall transition to EV mode. |
| `SwLLR15` | When the active software mode is Start mode and speed <= SPEED_STOP && P_dem <= PDEM_STOP_HIGH && P_dem >= PDEM_STOP_LOW, the software shall transition to the standstill mode. |
| `SwLLR16` | When the active software mode is ICE mode and speed <= SPEED_STOP && P_dem <= PDEM_STOP_HIGH && P_dem >= PDEM_STOP_LOW, the software shall transition to the standstill mode. |
| `SwLLR17` | When the active software mode is Hybrid mode and speed <= SPEED_STOP && P_dem <= PDEM_STOP_HIGH && P_dem >= PDEM_STOP_LOW, the software shall transition to the standstill mode. |
| `SwLLR21` | When the active software mode is ICE mode and P_dem >= PDEM_HYB_MID && SOC >= SOC_MID, the software shall transition to Hybrid mode. |
| `SwLLR23` | When the active software mode is Hybrid mode and (P_dem <= PDEM_HYB_LOW || SOC < SOC_LOW), the software shall transition to ICE mode. |
