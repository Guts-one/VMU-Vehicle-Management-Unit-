# VMU - Vehicle Management Unit

## Overview

This repository contains the current VMU project baseline for a power-split hybrid electric vehicle (HEV).

It combines:

- an adapted Simulink model used as the system reference
- a manual C implementation of the VMU mode logic
- transition documentation for the state machine
- unit tests and CI validation for the C baseline

The VMU supervisory logic is responsible for selecting operating modes such as `STANDSTILL`, `EV`, `REGENB`, `START`, `ICE`, and `HYBRID` based on driver power demand, vehicle speed, battery state of charge, and engine speed.

## Repository Structure

```text
.
|-- .github/
|   `-- workflows/
|       `-- ci.yaml
|-- inc/
|   |-- mode_logic.h
|   `-- mode_logic_team.h
|-- Model/
|   `-- HEV_powersplit_adapted/
|       |-- HEV_powersplit_adapted.slx
|       |-- README.md
|       |-- Overview/
|       |-- Scripts_Data/
|       |-- Images/
|       |-- Workflows/
|       `-- slprj/
|-- src/
|   |-- mode_logic.c
|   |-- mode_logic_team.c
|   `-- transicoes_estados_mode_logic.md
|-- test/
|   `-- test_mode_logic.c
|-- mode_logic_sim.html
`-- README.md
```

## Main Components

### Simulink Model

The adapted hybrid vehicle model is located in:

- `Model/HEV_powersplit_adapted/HEV_powersplit_adapted.slx`

This folder also includes:

- overview material for model navigation
- scripts and data files used by the model
- image assets and workflow support files
- generated Simulink artifacts currently versioned with the project

### C Mode Logic Baseline

The reference(Initial) C implementation is located in:

- `src/mode_logic.c`
- `inc/mode_logic.h`

This implementation defines:

- mode enumeration and I/O structures
- threshold constants for transitions
- step-based state machine behavior
- output enable mapping for motor, generator, and ICE

### Team-Oriented Mode Logic Structure

A modular team-oriented version is also included in:

- `src/mode_logic_team.c`
- `inc/mode_logic_team.h`

This version restructures the mode logic into smaller handlers per state and is aligned with a more traceable and MISRA-oriented coding style. It also centralizes output mapping to avoid one-step output delay.

Important:

- `src/mode_logic_team.c` is currently a development-oriented structure
- some transitions are still marked with `TODO` comments for task ownership and completion

### Transition Documentation

The transition mapping between the Simulink model and the C implementation is documented in:

- `src/transicoes_estados_mode_logic.md`

This document summarizes:

- state names in model and code
- threshold mapping
- transition priorities
- expected behavior for each mode

### Tests

Unit tests for the C baseline are available in:

- `test/test_mode_logic.c`

The current automated test flow validates the baseline implementation in `src/mode_logic.c`.

### CI

GitHub Actions CI is configured in:

- `.github/workflows/ci.yaml`

The workflow builds and runs the C unit tests automatically on pull requests.

## Getting Started

### Open the Simulink Model

1. Open MATLAB.
2. Navigate to `Model/HEV_powersplit_adapted`.
3. Open `HEV_powersplit_adapted.slx`.
4. Review the local `README.md` inside the model folder for model-specific notes.

### Build and Run the C Tests

From the repository root:

```bash
gcc -Iinc -o test_mode_logic src/mode_logic.c test/test_mode_logic.c
./test_mode_logic
```

On Windows with MinGW or equivalent:

```powershell
gcc -Iinc -o test_mode_logic.exe src/mode_logic.c test/test_mode_logic.c
.\test_mode_logic.exe
```

## Current Scope

This repository currently serves as:

- the VMU model baseline in Simulink
- the baseline C implementation for mode transitions
- a workspace for evolving the team-oriented mode logic structure
- a traceable reference for future integration and validation work

## Notes

- `mode_logic.c` is the implementation currently covered by the test and CI pipeline.
- `mode_logic_team.c` reflects the newer modular structure and transition split by responsibility.
- `mode_logic_sim.html` is included as an additional project artifact for mode-logic visualization or demonstration.
- The repository contains generated model artifacts under `Model/HEV_powersplit_adapted/slprj`, which are currently versioned in the branch structure.

## License

Model content derived from MathWorks example assets includes its own license file under:

- `Model/HEV_powersplit_adapted/LICENSE.md`
