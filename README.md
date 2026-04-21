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

### Team-Oriented Mode Logic Structure + adaptation for improved simulink model - issue: #36

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

## Code Quality & Standards

### MISRA C 2012 Compliance

This project follows **MISRA C 2012** coding standards to ensure reliability and safety.

**Status:**
- ✓ Minimum: 0 high-level violations
- ✓ Desirable: 0 high + 0 medium violations
- Goal: Zero violations

**Key Guidelines:**
- `const` for input parameters (Rule 8.13)
- Unsigned integer suffixes (Rule 10.1)
- Explicit type declarations (Rule 10)
- Structured control flow (Rules 15, 16)
- Static scope for internal functions (Rule 8.7)

**Quick Start:**
- See [MISRA_QUICKSTART.md](MISRA_QUICKSTART.md) for developer guidelines
- See [MISRA_COMPLIANCE.md](MISRA_COMPLIANCE.md) for detailed rules and patterns

**Automated Verification:**

GitHub Actions runs MISRA C 2012 static analysis on every pull request using **cppcheck**.

**Running Locally:**

1. **Install cppcheck:**
   ```bash
   # Windows
   winget install Cppcheck.Cppcheck

   # macOS
   brew install cppcheck

   # Linux (Ubuntu/Debian)
   sudo apt-get install cppcheck
   ```

2. **Run static analysis:**
   ```bash
   cppcheck --enable=all --suppress=missingIncludeSystem -Iinc src/ inc/ test/
   ```

3. **Build with strict warnings:**
   ```bash
   gcc -Wall -Wextra -Werror -Iinc -o test_mode_logic src/mode_logic.c test/test_mode_logic.c
   ```

4. **Run tests:**
   ```bash
   # Linux/macOS
   ./test_mode_logic

   # Windows
   .\test_mode_logic.exe
   ```

**Complete Local Verification (All Steps):**
```bash
# 1. Static analysis
cppcheck --enable=all --suppress=missingIncludeSystem -Iinc src/ inc/ test/

# 2. Compile
gcc -Wall -Wextra -Werror -Iinc -o test_mode_logic src/mode_logic.c test/test_mode_logic.c

# 3. Test
./test_mode_logic
```

### Continuous Integration

GitHub Actions workflow (`.github/workflows/ci.yaml`):
1. **Static Analysis** - Checks for MISRA C 2012 violations
2. **Build and Test** - Compiles with strict flags and runs unit tests

View results:
- Pull requests show status under "Checks"
- Download analysis reports from workflow artifacts

## Notes

- `mode_logic.c` is the implementation currently covered by the test and CI pipeline.
- `mode_logic_team.c` reflects the newer modular structure and transition split by responsibility.
- `mode_logic_sim.html` is included as an additional project artifact for mode-logic visualization or demonstration.
- The repository contains generated model artifacts under `Model/HEV_powersplit_adapted/slprj`, which are currently versioned in the branch structure.

## License

Model content derived from MathWorks example assets includes its own license file under:

- `Model/HEV_powersplit_adapted/LICENSE.md`
