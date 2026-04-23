# MISRA C 2012 Compliance Guidelines

## Overview

This project adheres to MISRA C 2012 coding standards to ensure code reliability, maintainability, and safety. The static analysis is automated via GitHub Actions using **cppcheck** with MISRA addon.

## Compliance Status

- **Minimum Requirement**: 0 high-level violations
- **Desirable Target**: 0 high + 0 medium violations
- **Ideal State**: Zero violations

## Automated Verification

### GitHub Actions Workflow

The `.github/workflows/ci.yaml` file contains two jobs:

1. **Static Analysis (MISRA C 2012)**
   - Runs cppcheck with MISRA addon on all source files
   - Generates report artifact for each run
   - Exits with error code if violations are found

2. **Build and Test**
   - Compiles code with strict warning flags (`-Wall -Wextra -Werror`)
   - Runs unit tests

### Running Locally

To check for MISRA violations on your machine:

```bash
# Install cppcheck (Ubuntu/Debian)
sudo apt-get install cppcheck

# Run MISRA analysis
cppcheck --enable=all \
         --suppress=missingIncludeSystem \
         --inline-suppr \
         --addon=misra \
         -Iinc \
         src/ inc/ test/
```

## Key MISRA C 2012 Rules Applied

### Observed Rules

| Rule | Category | Description | Implementation |
|------|----------|-------------|-----------------|
| **8.7** | Best Practices | Static scope for internal functions | All helper functions declared `static` |
| **8.8** | Best Practices | External function declarations | All exported functions have header declarations |
| **8.13** | Best Practices | `const` for input parameters | Input parameters use `const` pointers |
| **10.1** | Type Safety | Implicit type conversions | Explicit `U` suffix for unsigned literals |
| **11.9** | Pointer Handling | NULL comparisons | `!= NULL` and `== NULL` used explicitly |
| **14.4** | Control Flow | Boolean conditions | Conditions written as boolean expressions |
| **15.5** | Function Return | Single return point | All functions return at end of body |
| **15.6** | Control Structure | Statement blocks | All `if`/`switch` bodies have braces |
| **15.7** | If-Else Chains | Termination | `if...else if` chains end with `else` |
| **16.1** | Switch Statements | Structure | `switch` statements well-formed |
| **16.3** | Case Statements | Breaks | All cases have explicit `break` |
| **16.4** | Default Case | Coverage | `default` case always present |
| **16.6** | Case Values | Type | Case expressions match switch type |
| **17.2** | Recursion | Avoidance | No recursive functions |

### Type System Compliance

**Before (Non-compliant):**
```c
typedef struct {
    int Mot_Enable;      // Non-standard size
    int Gen_Enable;
    int ICE_Enable;
} Outputs_t;

out->Mot_Enable = 0;     // Missing U suffix
```

**After (Compliant):**
```c
typedef struct {
    uint8_t Mot_Enable;  // Explicit size, standard unsigned type
    uint8_t Gen_Enable;
    uint8_t ICE_Enable;
} Outputs_t;

out->Mot_Enable = 0U;    // Explicit unsigned suffix
```

### Input Parameter Compliance

**Before (Non-compliant):**
```c
void ModeLogic_Step(State_t *state, Inputs_t *in, Outputs_t *out)
{
    // No indication that inputs won't be modified
    in->speed = 0;  // Accidental modification possible
}
```

**After (Compliant):**
```c
void ModeLogic_Step(State_t *state, const Inputs_t *in, Outputs_t *out)
{
    // Compiler prevents accidental modification of inputs
    // in->speed = 0;  // ERROR: assignment to read-only member
}
```

## Adding Inline Suppressions

For legitimate exceptions to MISRA rules, use inline comments:

```c
// cppcheck-suppress misra-c2012-16.7
static void example_function(int * const ptr)
{
    // Non-const parameter required by API contract
}
```

**Important**: Use suppressions sparingly and document why the exception is necessary.

## Common Violations and Fixes

### Violation: Implicit Integer Conversion (Rule 10.1)

**Error Message**: `Implicit conversion from floating point to unsigned integer`

**Fix**: Add explicit cast or use appropriate suffix
```c
// ❌ Non-compliant
uint8_t value = 5;          // implicit conversion

// ✓ Compliant
uint8_t value = 5U;         // explicit unsigned literal
```

### Violation: Missing `else` Clause (Rule 15.7)

**Error Message**: `if...else if chain does not have a final else`

**Fix**: Add explicit `else` clause
```c
// ❌ Non-compliant
if (condition1) {
    // action 1
} else if (condition2) {
    // action 2
}

// ✓ Compliant
if (condition1) {
    // action 1
} else if (condition2) {
    // action 2
} else {
    // default action or comment
}
```

### Violation: Function Not Declared Static (Rule 8.7)

**Error Message**: `Unused function declared non-static`

**Fix**: Make internal functions static
```c
// ❌ Non-compliant
Mode_t handle_standstill(const Inputs_t *in) { ... }

// ✓ Compliant
static Mode_t handle_standstill(const Inputs_t *in) { ... }
```

## Maintenance Checklist

Before committing code:

- [ ] Run local MISRA check: `cppcheck --addon=misra -Iinc src/`
- [ ] All conditions in `if`/`switch` are boolean expressions
- [ ] All unsigned integer literals have `U` suffix
- [ ] All input parameters use `const` where applicable
- [ ] All functions have proper return statements
- [ ] All `switch` cases have `break` or `default`
- [ ] No recursive function calls
- [ ] Function prototypes match implementations

## CI/CD Integration

The GitHub Actions workflow automatically:
1. Checks out the code
2. Installs cppcheck
3. Runs MISRA C 2012 analysis
4. Generates a report artifact
5. Fails the build if high-level violations are found

**View Reports**: Check the "Artifacts" section in completed workflow runs to download analysis reports.

## Resources

- [MISRA C 2012 Standard](https://www.misra.org.uk/misra-c-2012/)
- [Cppcheck Documentation](http://cppcheck.sourceforge.net/)
- [MISRA C 2012 Addendum 1](https://www.misra.org.uk/misra-c-2012-addendum-1/)
- [Safe C Coding Practices](https://www.securecoding.cert.org/confluence/display/c/)

## Questions or Issues

If you encounter MISRA violations that seem incorrect:
1. Document the violation with context
2. Check the cppcheck-generated report for details
3. Consult the MISRA C 2012 standard
4. Use inline suppressions only if the violation is a false positive
