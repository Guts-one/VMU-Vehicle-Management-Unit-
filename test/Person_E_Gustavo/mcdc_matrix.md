# MC/DC Matrix - Person E (Gustavo)

For each decision predicate with more than one condition, MC/DC requires a set
of test cases showing that **each condition, by itself, changes the predicate
result**. This document maps each requirement to the involved conditions and to
the tests in `test_person_e.c` that cover each one.

Conventions:

- `T` = true condition, `F` = false condition.
- "vector" = tuple with the value of each condition in the order they appear in
  the requirement guard.
- "positive test" = vector with all conditions true; confirms that the
  transition **occurs**.
- "MC/DC X=F test" = vector with only condition `X` false; confirms that the
  transition **does not occur**. Combined with the positive test, this proves
  that `X` alone decides the result.

Thresholds from `inc/mode_logic_team.h`:

| Symbol | Value |
|---|---|
| `ENG_ON` | 800.0 |
| `ENG_OFF` | 790.0 |
| `SPEED_STOP` | 0.5 |
| `SPEED_REGEN` | 5.0 |
| `SPEED_EV_MAX` | 35.0 |
| `PDEM_REGEN` | -5.0 |
| `PDEM_STOP_LOW` | -1.0 |
| `PDEM_STOP_HIGH` | 1.0 |
| `PDEM_HYB_OUT` | 40.0 |
| `PDEM_HYB_MID` | 15.0 |
| `PDEM_HYB_LOW` | 10.0 |
| `SOC_EV_IN` | 0.37 |
| `SOC_MID` | 0.30 |
| `SOC_LOW` | 0.25 |

---

## SwLLR09 / SwLLR10 / SwLLR11 - Start/ICE/Hybrid -> RegenB

Guard: `wEng > ENG_ON && speed > SPEED_REGEN && P_dem <= PDEM_REGEN`

| Condition | Symbol | Positive test (TTT) | MC/DC flip test |
|---|---|---|---|
| A | `wEng > ENG_ON` | `*_to_RegenB_positive` | `*_blocked_by_wEng*` (A=F) |
| B | `speed > SPEED_REGEN` | same | `*_blocked_by_speed*` (B=F) |
| C | `P_dem <= PDEM_REGEN` | same | `*_blocked_by_P_dem*` (C=F) |

Each family (Start, ICE, Hybrid) has its own test set using the prefixes
`SwLLR09_Start_`, `SwLLR10_ICE_`, and `SwLLR11_Hybrid_`.

**4 vectors per requirement x 3 requirements = 12 tests.**

---

## SwLLR12 / SwLLR13 / SwLLR14 - Start/ICE/Hybrid -> EV

Guard: `wEng > ENG_ON && P_dem <= PDEM_HYB_OUT && P_dem >= PDEM_STOP_LOW
         && speed > SPEED_STOP && speed <= SPEED_EV_MAX && SOC >= SOC_EV_IN`

| Condition | Symbol | Positive test (TTTTTT) | MC/DC flip test |
|---|---|---|---|
| A | `wEng > ENG_ON` | `*_to_EV_positive` | `*_EV_blocked_by_wEng` (A=F, wEng=800) |
| B | `P_dem <= PDEM_HYB_OUT` | same | `*_EV_blocked_by_P_dem_over_HYB_OUT` (B=F, P_dem=45) |
| C | `P_dem >= PDEM_STOP_LOW` | same | `*_EV_blocked_by_P_dem_under_STOP_LOW` (C=F, P_dem=-3) |
| D | `speed > SPEED_STOP` | same | `*_EV_blocked_by_speed_not_over_SPEED_STOP` (D=F, speed=0.3) |
| E | `speed <= SPEED_EV_MAX` | same | `*_EV_blocked_by_speed_over_SPEED_EV_MAX` (E=F, speed=40) |
| F | `SOC >= SOC_EV_IN` | same | `*_EV_blocked_by_SOC_under_SOC_EV_IN` (F=F, SOC=0.36) |

**7 vectors per requirement x 3 requirements = 21 tests.**

---

## SwLLR15 / SwLLR16 / SwLLR17 - Start/ICE/Hybrid -> StandStill

Guard: `speed <= SPEED_STOP && P_dem <= PDEM_STOP_HIGH && P_dem >= PDEM_STOP_LOW`

Negative vectors use `wEng = 800` to ensure that neither Regen nor EV can fire
for unrelated reasons, since both require `wEng > 800`. This leaves the
StandStill guard as the only relevant predicate.

| Condition | Symbol | Positive test | MC/DC flip test |
|---|---|---|---|
| A | `speed <= SPEED_STOP` | `*_to_StandStill_positive` | `*_StandStill_blocked_by_speed_over_SPEED_STOP` (A=F, speed=1.0) |
| B | `P_dem <= PDEM_STOP_HIGH` | same | `*_StandStill_blocked_by_P_dem_over_STOP_HIGH` (B=F, P_dem=2) |
| C | `P_dem >= PDEM_STOP_LOW` | same | `*_StandStill_blocked_by_P_dem_under_STOP_LOW` (C=F, P_dem=-2) |

**4 vectors per requirement x 3 requirements = 12 tests.**

---

## SwLLR21 - ICE -> Hybrid

Guard, evaluated after external transitions and reset fail:
`P_dem >= PDEM_HYB_MID && SOC >= SOC_MID`

| Condition | Symbol | Positive test | MC/DC flip test |
|---|---|---|---|
| A | `P_dem >= PDEM_HYB_MID` | `SwLLR21_ICE_to_Hybrid_positive` | `SwLLR21_ICE_Hybrid_blocked_by_P_dem_under_HYB_MID` (A=F) |
| B | `SOC >= SOC_MID` | same | `SwLLR21_ICE_Hybrid_blocked_by_SOC_under_SOC_MID` (B=F) |

`speed = 40` blocks EV/StandStill external transitions and `wEng = 900`
prevents reset, so the internal guard is the only decisive factor.

**3 tests.**

---

## SwLLR23 - Hybrid -> ICE

OR guard: `P_dem <= PDEM_HYB_LOW || SOC < SOC_LOW`

For an OR decision, MC/DC requires:

1. `TF` (A=T, B=F) - transition occurs because of A;
2. `FT` (A=F, B=T) - transition occurs because of B;
3. `FF` - transition does not occur.

`TT` would be redundant for OR MC/DC.

| Case | Test | Vector |
|---|---|---|
| TF (A decides) | `SwLLR23_Hybrid_to_ICE_positive_low_P_dem` | `P_dem=5, SOC=0.5` |
| FT (B decides) | `SwLLR23_Hybrid_to_ICE_positive_low_SOC` | `P_dem=20, SOC=0.20` |
| FF (does not occur) | `SwLLR23_Hybrid_stays_when_both_conditions_false` | `P_dem=20, SOC=0.5` |

**3 tests.**

---

## SwHLR06 - External Transitions Before Internal Transitions in Start/ICE/Hybrid

These tests create inputs where external and internal guards are true at the
same time and verify that the external transition wins:

| Test | Source | Winning external transition | Internal transition that would be possible |
|---|---|---|---|
| `SwHLR06_ICE_external_EV_beats_internal_Hybrid` | ICE | EV | ICE->Hybrid |
| `SwHLR06_Hybrid_external_EV_beats_internal_ICE` | Hybrid | EV | Hybrid->ICE |
| `SwHLR06_Start_external_Regen_beats_internal_Hybrid` | Start | RegenB | Start->Hybrid |
| `SwHLR06_Hybrid_external_StandStill_beats_internal_ICE` | Hybrid | StandStill | Hybrid->ICE |

**4 tests.**

---

## SwHLR08 / SwHLR09 - Reset Before Internal Transitions in ICE/Hybrid

| Test | Source | Reset | Internal transition that would be possible |
|---|---|---|---|
| `SwHLR08_ICE_reset_to_Start_beats_ICE_to_Hybrid` | ICE | ICE->Start | ICE->Hybrid |
| `SwHLR09_Hybrid_reset_to_Start_beats_Hybrid_to_ICE` | Hybrid | Hybrid->Start | Hybrid->ICE |

**2 tests.**

---

## Complementary Tests (Boundaries and Outputs)

In addition to the per-requirement MC/DC cases, the suite also contains:

- **Sanity** (3): correct `ModeLogic_Init` behavior and `NULL` robustness.
- **Output mapping** (5): `Mot_Enable`/`Gen_Enable`/`ICE_Enable` for each mode
  touched by Person E (RegenB, EV, StandStill, Hybrid, ICE).
- **Boundaries** (10): exact threshold values (`ENG_ON`, `SPEED_REGEN`,
  `SPEED_EV_MAX`, `SPEED_STOP`, `PDEM_REGEN`, `PDEM_STOP_LOW`,
  `PDEM_HYB_MID`, `PDEM_HYB_LOW`, `SOC_EV_IN`, `SOC_LOW`). These confirm that
  comparison operators (`<`, `<=`, `>`, `>=`) are implemented correctly.
- **Start priority with low SOC** (1): covers the edge where no external
  transition fires and the logic falls through to the internal transition.

---

## Total Count

| Group | # |
|---|---|
| Sanity | 3 |
| SwLLR09/10/11 (RegenB) | 12 |
| SwLLR12/13/14 (EV) | 21 |
| SwLLR15/16/17 (StandStill) | 12 |
| SwLLR21 / SwLLR23 | 6 |
| SwHLR06 / 08 / 09 | 7 |
| Output mapping | 5 |
| Boundaries | 10 |
| **Total** | **76** |

Result: **76/76 pass, with 100% line and branch coverage in the Person E
scope**.
