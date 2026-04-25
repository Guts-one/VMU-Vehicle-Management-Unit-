# VMU — Vehicle Management Unit

## Overview

This repository hosts the VMU (Vehicle Management Unit) baseline for a power-split hybrid electric vehicle (HEV).
It brings together the system reference model, a manual C implementation of the supervisory mode logic, the requirements/transition documentation, an interactive web simulator, and a complete test and CI infrastructure aligned with **MISRA C 2012**.

The VMU supervisory logic selects operating modes — `STANDSTILL`, `EV`, `REGENB`, `START`, `ICE`, `HYBRID` — based on driver power demand, vehicle speed, battery state of charge, and engine speed.

## Repository Structure

```text
.
├── .github/workflows/
│   └── ci.yaml                      # Build, unit tests, and MISRA static analysis
├── Model/
│   └── HEV_powersplit_adapted/      # Adapted Simulink reference model
├── inc/
│   ├── mode_logic.h                 # Original API (kept for reference/headers)
│   └── mode_logic_team.h            # Modular team-oriented API (current baseline)
├── src/
│   ├── mode_logic_team.c            # C implementation of the supervisory logic
│   └── transicoes_estados_mode_logic.md
├── test/
│   ├── Person_E_Gustavo/            # Person E test suite + Makefile + coverage tooling
│   ├── shared_tests/                # Cross-cutting requirement tests
│   ├── test_mcdc_bruna.c            # Persona-specific MC/DC suites
│   ├── test_mcdc_danilo.c
│   ├── test_mcdc_hugo.c
│   ├── test_mcdc_marinel.c
│   ├── test_mode_logic.c
│   ├── test_mode_logic_team_hugo.c
│   └── test_mode_logic_team_update.c
├── doc/
│   ├── Requisitos_preview.pdf
│   ├── Tests_verification.xlsx
│   ├── Tests_verification_Person_E_and_shared_tests.xlsx
│   └── mapeamento_transicoes_secao4_por_responsavel.md
├── mode_logic_sim.html              # Interactive web simulator
├── misra.py                         # MISRA C 2012 verification script
├── MISRA_COMPLIANCE.md              # Detailed MISRA rules and patterns
├── MISRA_QUICKSTART.md              # Developer quick-start for MISRA
├── UnityExecution.md                # Unity build/coverage instructions
└── README.md
```

## Main Components

### Simulink Reference Model

Located in `Model/HEV_powersplit_adapted/`. It contains the supervisory model that the C baseline mirrors, along with overview material, scripts, image assets, and workflow support files.

### C Mode Logic Baseline

The current C implementation lives in:

- `src/mode_logic_team.c`
- `inc/mode_logic_team.h`

The implementation provides:

- mode enumeration and I/O structures
- calibratable threshold constants for transitions (aligned with the Simulink model)
- per-state handlers structured for traceability
- centralized output mapping for motor, generator, and ICE enables (no one-step delay)
- MISRA-oriented coding style: `const` inputs, explicit `uint8_t` booleans, structured control flow

### Transition Documentation

- `src/transicoes_estados_mode_logic.md` — state names, threshold mapping, transition priorities, and expected behavior per mode.
- `doc/mapeamento_transicoes_secao4_por_responsavel.md` — Section 4 transitions mapped per responsible team member.
- `doc/Requisitos_preview.pdf` — requirements preview.

### Test Suite

The repository ships a layered test infrastructure built on the **Unity** framework with **MC/DC** and line-coverage reporting via `gcov`/`lcov`.

| Suite | File / Directory | Scope |
|---|---|---|
| Persona Bruna | `test/test_mcdc_bruna.c` | MC/DC + line coverage |
| Persona Danilo | `test/test_mcdc_danilo.c` | MC/DC + line coverage |
| Persona Hugo | `test/test_mcdc_hugo.c`, `test/test_mode_logic_team_hugo.c` | MC/DC and team-level integration |
| Persona Marinel | `test/test_mcdc_marinel.c` | MC/DC for Marinel's transitions |
| Persona E (Gustavo) | `test/Person_E_Gustavo/` | Only Persona E requirements are covered + MC/DC suite with dedicated Makefile and coverage report |
| Shared requirements | `test/shared_tests/` | Cross-cutting tests covering SwHLR01/02/10, SysHLR01/02/03, NfHLR02/04 |
| Baseline | `test/test_mode_logic.c`, `test/test_mode_logic_team_update.c` | Smoke tests for the baseline implementation |

Test verification spreadsheets are kept under `doc/` for traceability between requirements and tests.

### Interactive Web Simulator

`mode_logic_sim.html` is a standalone, dependency-free simulator that mirrors the C state machine in JavaScript.

Features:

- Real-time dashboard for the active mode and powertrain enables
- Animated gauges for vehicle speed (km/h) and engine speed (RPM)
- Telemetry charts: vehicle speed, power demand (`P_dem`), state of charge (`SOC`), engine speed (`wEng`), and mode-transition history
- Manual control panel for all state variables
- Pre-configured scenarios (EV, regenerative braking)
- Automated drive cycles (short cycle and 1-minute continuous cycle) with automatic phase display
- Transition history table with input/output values

Open it in any modern browser — no build step or server required.

## Getting Started

### Open the Simulink Model

1. Open MATLAB.
2. Navigate to `Model/HEV_powersplit_adapted`.
3. Open `HEV_powersplit_adapted.slx`.
4. See the local `README.md` inside the model folder for model-specific notes.

### Build and Run the C Tests

The full build and coverage flow is documented in [UnityExecution.md](UnityExecution.md). A typical persona suite is built with the Unity sources placed at `unity/src/` and a one-line GCC invocation:

```bash
gcc -std=c99 -Wall -Wextra \
    --coverage -fprofile-arcs -ftest-coverage -O0 \
    -Iinc -Iunity/src \
    src/mode_logic_team.c \
    unity/src/unity.c \
    test/<TEST_FILE>.c \
    -o test_runner
./test_runner
```

The Person E and shared-tests suites ship with their own Makefiles:

```bash
# Person E
make -C test/Person_E_Gustavo            # build and run
make -C test/Person_E_Gustavo coverage   # build, run, and emit lcov/HTML report

# Shared (cross-cutting) tests
make -C test/shared_tests
```

Coverage reports (when `lcov`/`genhtml` are available) are generated under each suite's `build_cov/html/` directory.

## Code Quality & Standards

### MISRA C 2012 Compliance

The project follows **MISRA C 2012** to ensure reliability and safety, with automated verification on every pull request.

**Status:**
- Minimum: 0 high-severity violations
- Desirable: 0 high + 0 medium violations
- Goal: zero violations

**Key guidelines applied:**
- `const` for input parameters (Rule 8.13)
- Unsigned-integer suffixes (Rule 10.1)
- Explicit type declarations (Rule 10)
- Structured control flow (Rules 15, 16) — including the Rule 15.5 single-exit pattern
- Static scope for internal functions (Rule 8.7)

**References:**
- [MISRA_QUICKSTART.md](MISRA_QUICKSTART.md) — developer quick-start
- [MISRA_COMPLIANCE.md](MISRA_COMPLIANCE.md) — detailed rules and patterns

**Local verification:**

1. Install `cppcheck`:
   ```bash
   # Windows
   winget install Cppcheck.Cppcheck
   # macOS
   brew install cppcheck
   # Linux (Ubuntu/Debian)
   sudo apt-get install cppcheck
   ```

2. Run static analysis with the project's MISRA addon:
   ```bash
   cppcheck --enable=all --addon=misra --suppress=missingIncludeSystem -Iinc src/ inc/ test/
   # or use the bundled script
   python misra.py
   ```

3. Build with strict warnings:
   ```bash
   gcc -Wall -Wextra -Werror -Iinc -o test_runner src/mode_logic_team.c test/<TEST_FILE>.c
   ```

### Continuous Integration

GitHub Actions (`.github/workflows/ci.yaml`) runs on every pull request and performs:

1. **Static analysis** — MISRA C 2012 verification via `cppcheck` + `misra.py`.
2. **Build and test** — compilation with strict flags and execution of the Unity suites.

PR checks and downloadable analysis reports are available under the workflow run's "Checks" / "Artifacts" tabs.

## Notes

- `src/mode_logic_team.c` is the single C implementation maintained on `main`. The legacy `src/mode_logic.c` was removed during the development cycle; its header remains for compatibility and reference.
- `mode_logic_sim.html` is kept in sync with the thresholds and transition logic of `mode_logic_team.c`.
- Generated Simulink artifacts under `Model/HEV_powersplit_adapted/slprj/` are intentionally not versioned; they are produced locally on first build.

## License

Model content derived from MathWorks example assets is governed by its own license file under:

- `Model/HEV_powersplit_adapted/LICENSE.md`
