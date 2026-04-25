# Shared Tests - Cross-Cutting Requirements

This suite covers requirements from the PDF that **do not belong to any single
individual person** in `doc/mapeamento_transicoes_secao4_por_responsavel.md`,
as declared in the final sections of that document: shared responsibility,
derived system requirements, and non-functional requirements.

## Scope

| Group | Requirements | Status |
|---|---|---|
| Shared responsibility (section 4.2) | `SwHLR01`, `SwHLR02`, `SwHLR10` | tested |
| System (section 4.1) | `SysHLR01`, `SysHLR02`, `SysHLR03` | tested (structural part) |
| Non-functional (section 5) | `NfHLR02`, `NfHLR04` | tested |
| Non-functional (outside unit-test scope) | `NfHLR01`, `NfHLR03` | **not tested here** |

- `NfHLR01` (0.1 s period) requires scheduler/RTOS verification at the
  integration gate (SIL/HIL).
- `NfHLR03` (static allocation) requires static analysis at the MISRA C gate
  (delivery 3).

## How to Run

From this folder (`tests/shared_tests/`):

```bash
mingw32-make run     # builds and runs the suite
mingw32-make clean   # removes artifacts
```

In other environments (`make` + gcc), replace `mingw32-make` with `make`.

## Files

| File | Purpose |
|---|---|
| `test_shared_requirements.c` | 23 Unity tests covering the scope above. |
| `Makefile` | Build and execution recipe. |

## Test-to-Requirement Map

| # | Test | Requirement | What it verifies |
|---|---|---|---|
| 1 | `test_SwHLR01_init_sets_current_mode_to_standstill` | SwHLR01 | `ModeLogic_Init` sets the mode to `MODE_STANDSTILL` starting from a different value. |
| 2 | `test_SwHLR01_init_is_idempotent` | SwHLR01 | Two consecutive `Init` calls produce the same state. |
| 3 | `test_SwHLR02_standstill_outputs_000` | SwHLR02 / SysHLR02 | Standstill -> `{Mot=0, Gen=0, ICE=0}`. |
| 4 | `test_SwHLR02_EV_outputs_100` | SwHLR02 / SysHLR02 | EV -> `{1, 0, 0}`. |
| 5 | `test_SwHLR02_RegenB_outputs_100` | SwHLR02 / SysHLR02 | RegenB -> `{1, 0, 0}`. |
| 6 | `test_SwHLR02_Start_outputs_110` | SwHLR02 / SysHLR02 | Start -> `{1, 1, 0}`. |
| 7 | `test_SwHLR02_ICE_outputs_011` | SwHLR02 / SysHLR02 | ICE -> `{0, 1, 1}`. |
| 8 | `test_SwHLR02_Hybrid_outputs_111` | SwHLR02 / SysHLR02 | Hybrid -> `{1, 1, 1}`. |
| 9 | `test_SwHLR10_init_null_state_does_not_crash` | SwHLR10 | `Init(NULL)` does not crash. |
| 10 | `test_SwHLR10_step_null_state_does_not_crash` | SwHLR10 | `Step(NULL, in, out)` returns early without touching `out`. |
| 11 | `test_SwHLR10_step_null_inputs_does_not_crash` | SwHLR10 | `Step(state, NULL, out)` does not change `state`. |
| 12 | `test_SwHLR10_step_null_outputs_does_not_crash` | SwHLR10 | `Step(state, in, NULL)` does not change `state`. |
| 13 | `test_SwHLR10_invalid_mode_value_recovers_to_standstill` | SwHLR10 | Corrupted state (`current_mode=99`) -> `default` recovers to `STANDSTILL` with outputs `{0,0,0}`. |
| 14 | `test_SysHLR01_every_step_leaves_valid_mode` | SysHLR01 | Runs a sequence of varied inputs and checks that `current_mode` remains in `{0..5}` after each step. |
| 15 | `test_SysHLR03_SOC_EV_hysteresis_window_is_positive` | SysHLR03 | `SOC_EV_IN > SOC_EV_OUT` (window exists). |
| 16 | `test_SysHLR03_ENG_hysteresis_window_is_positive` | SysHLR03 | `ENG_ON > ENG_OFF`. |
| 17 | `test_SysHLR03_PDEM_STOP_window_is_coherent` | SysHLR03 | `PDEM_STOP_HIGH > PDEM_STOP_LOW`. |
| 18 | `test_SysHLR03_PDEM_HYB_ordering` | SysHLR03 | `PDEM_HYB_IN > PDEM_HYB_OUT > PDEM_HYB_MID > PDEM_HYB_LOW`. |
| 19 | `test_SysHLR03_SOC_ordering` | SysHLR03 | `SOC_EV_IN > SOC_MID > SOC_LOW`. |
| 20 | `test_SysHLR03_SPEED_ordering` | SysHLR03 | `SPEED_EV_MAX > SPEED_REGEN > SPEED_STOP`. |
| 21 | `test_NfHLR02_SOC_EV_hysteresis_cycle` | NfHLR02 | Real cycle: enters EV with `SOC=SOC_EV_IN`, stays with `SOC=0.36` inside the window, exits with `SOC=0.34 < SOC_EV_OUT`. |
| 22 | `test_NfHLR02_ENG_hysteresis_cycle` | NfHLR02 | Real cycle: enters ICE with `wEng=900`, stays with `wEng=795` inside `ENG_OFF..ENG_ON`, exits to START with `wEng=780 <= ENG_OFF`. |
| 23 | `test_NfHLR04_same_sequence_produces_same_outputs` | NfHLR04 | Two independent executions with the same input sequence produce identical modes and outputs. |

## Current Result

```text
23 Tests 0 Failures 0 Ignored
OK
```

## Relationship with Individual Suites

These tests **do not replace** the per-person suites. They verify only
cross-cutting behavior. In particular:

- **SwHLR01** also appears as a sanity test in the Person E suite. This is not
  a redundant error: each suite must guarantee that its setup starts in
  `STANDSTILL` before an individual transition test.
- **SwHLR02** is tested here for all 6 modes, giving complete coverage of the
  PDF table. Suites A, B, C, D, and E verify only the outputs for the modes
  each person touches.
- **SwHLR10** also appears as NULL sanity checks in several suites, but the
  invalid-mode recovery test (`current_mode=99`) exists only here because it is
  a defensive-code test with shared responsibility.
- **NfHLR02** (hysteresis) complements the individual suites' boundary tests:
  individual suites cross **one** threshold at a time, while this suite runs the
  **cycle** crossing the two thresholds that form the window.
- **NfHLR04** does not require new production code, only observation: the
  existence of a deterministic suite already demonstrates the requirement; this
  test formalizes that observation.
