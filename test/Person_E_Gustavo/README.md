# Unit Tests - Person E (Gustavo)

Unity unit tests for the requirements assigned in
`doc/mapeamento_transicoes_secao4_por_responsavel.md`.

## Scope

Covered requirements:

- **Section 4.2**: `SwHLR06`, `SwHLR08` (shared), `SwHLR09` (shared).
- **Section 4.3**: `SwLLR09`, `SwLLR10`, `SwLLR11`, `SwLLR12`, `SwLLR13`,
  `SwLLR14`, `SwLLR15`, `SwLLR16`, `SwLLR17`, `SwLLR21`, `SwLLR23`.

Code under test: `src/mode_logic_team.c`, limited to the transition families
assigned to Person E. Other functions such as `handle_standstill`, `handle_ev`,
and `handle_regenb` belong to Persons A, B, and C.

## How to Run

Requirements:

- `gcc` (MSYS2 / MinGW-w64) and `mingw32-make`.
- `python` (3.8+) for the per-person coverage filter.
- Optional: `lcov` + `genhtml` for the HTML report.

Commands from this folder (`tests/Person_E_Gustavo/`):

```bash
mingw32-make run         # builds and runs the suite
mingw32-make coverage    # same, plus coverage report
mingw32-make clean       # removes artifacts
```

In other environments (`make` + gcc), replace `mingw32-make` with `make`.

## Files

| File | Purpose |
|---|---|
| `test_person_e.c` | 76 Unity tests covering the Person E requirements. |
| `Makefile` | Build, execution, and `gcov` coverage generation. |
| `scope_coverage.py` | Filters the `gcov` report to show only the Person E scope. |
| `scope_debug.py` | Lists which scoped branches were not taken. |
| `mcdc_matrix.md` | MC/DC matrix by requirement, mapping tests to conditions. |

## Current Result

- **76 tests / 0 failures**.
- **Full-file coverage**: 65.45% lines, 63.08% branches.
  The remaining code belongs to Persons A, B, and C in the same `.c` file.
- **Person E scoped coverage**: **100% lines, 100% branches**.
  Unreachable branches such as MISRA defaults and dispatch cases for other
  persons' modes are explicitly excluded in `scope_coverage.py`.

## Coverage Levels Reached

Reference: delivery 4/4 statement, branch, and MC/DC targets
(minimum 50%, desired 80%, super-delivery 100%).

| Type | Result in the Person E scope |
|---|---|
| Statement | 100% (89/89 executable lines) |
| Branch | 100% (55/55 scoped branches) |
| MC/DC | See `mcdc_matrix.md` for individual coverage of each condition in multi-operand guards. |
