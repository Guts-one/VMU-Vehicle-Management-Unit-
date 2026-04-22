# MISRA C 2012 Quick Start Guide

## For Developers

### Before You Code

1. **Review MISRA rules** in [MISRA_COMPLIANCE.md](MISRA_COMPLIANCE.md)
2. **Enable IDE warnings**: Ensure your IDE is configured to catch potential issues

### While Coding

Follow these key practices:

#### 1. Always Use `const` for Input Parameters
```c
// ✓ Good
void process(const Inputs_t *in) { ... }

// ✗ Bad
void process(Inputs_t *in) { ... }
```

#### 2. Use Unsigned Suffixes
```c
// ✓ Good
uint8_t value = 1U;
out->Enable = 0U;

// ✗ Bad
uint8_t value = 1;
out->Enable = 0;
```

#### 3. Proper Type Declarations
```c
// ✓ Good - Explicit sizes
typedef struct {
    uint8_t enable;      // 1 byte
    uint16_t counter;    // 2 bytes
    uint32_t timestamp;  // 4 bytes
} Registers_t;

// ✗ Bad - Implicit sizes
typedef struct {
    int enable;          // Platform-dependent
    int counter;
    int timestamp;
} Registers_t;
```

#### 4. Always End if/else-if with else
```c
// ✓ Good
if (condition1) {
    action1();
} else if (condition2) {
    action2();
} else {
    // explicit default case
}

// ✗ Bad - Missing else
if (condition1) {
    action1();
} else if (condition2) {
    action2();
}
```

#### 5. Static Functions for Internal Use
```c
// ✓ Good - Internal function is static
static Mode_t handle_standstill(const Inputs_t *in) { ... }

// ✗ Bad - Unneeded global visibility
Mode_t handle_standstill(const Inputs_t *in) { ... }
```

### Before You Commit

**Run local MISRA check:**
```bash
cppcheck --enable=all \
         --suppress=missingIncludeSystem \
         --addon=misra \
         -Iinc \
         src/ inc/ test/
```

**OR on macOS with Homebrew:**
```bash
brew install cppcheck
# Then run the command above
```

**OR on Windows:**
```bash
# Download from: http://cppcheck.sourceforge.net/
# Install and add to PATH, then:
cppcheck --enable=all --addon=misra -Iinc src/ inc/ test/
```

### Handling Violations

If you get a violation:

1. **Read the error message carefully** - it explains the rule and line
2. **Check [MISRA_COMPLIANCE.md](MISRA_COMPLIANCE.md)** for common patterns
3. **Fix the code** - most violations have straightforward fixes
4. **Use suppressions sparingly** - only for legitimate false positives:
   ```c
   // cppcheck-suppress misra-c2012-16.7
   static void my_function(int * const ptr) { ... }
   ```

## For CI/CD

GitHub Actions automatically runs MISRA checks on every pull request.

### View Results

1. Go to your PR on GitHub
2. Click "Checks" tab
3. Look for "Static Analysis (MISRA C 2012)"
4. Download the artifact "misra-analysis-report" to see the full report

### Fixing CI Failures

If the MISRA check fails:
1. Download the report artifact
2. Review violations in `cppcheck-report.txt`
3. Fix issues locally
4. Run local check to verify: `cppcheck --addon=misra -Iinc src/`
5. Commit and push

## Environment Setup

### Linux (Ubuntu/Debian)
```bash
sudo apt-get update
sudo apt-get install cppcheck
cppcheck --version
```

### macOS
```bash
brew install cppcheck
cppcheck --version
```

### Windows
1. Download from: [cppcheck releases](http://cppcheck.sourceforge.net/)
2. Install to a standard location (e.g., `C:\cppcheck`)
3. Add to PATH or use full path

## Recommended IDE Configuration

### VS Code
Add to `.vscode/settings.json`:
```json
{
  "C_Cpp.codeAnalysisEngine": "clangTidy",
  "C_Cpp.clangTidy.enabled": true
}
```

### CLion
- Settings → Languages & Frameworks → C/C++ → Code Analysis
- Enable: "Perform code analysis"

### Visual Studio
- Analyze → Run Code Analysis on Solution
- Enable: "Microsoft Native Recommended Rules"

## Troubleshooting

### "cppcheck: command not found"
→ Install cppcheck or check it's in your PATH

### "MISRA addon not found"
→ Update cppcheck to latest version

### False positives in report
→ Add to `.cppcheckignore` or use inline suppressions

### Build succeeds but MISRA fails
→ Some violations are code quality issues, not syntax errors. Fix the reported lines.

## Resources

- Full documentation: [MISRA_COMPLIANCE.md](MISRA_COMPLIANCE.md)
- MISRA C 2012 Standard: https://www.misra.org.uk/
- Cppcheck: http://cppcheck.sourceforge.net/
