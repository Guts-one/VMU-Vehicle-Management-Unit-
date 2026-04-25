## Pre requesites

```txt
 PREREQUISITES
 -------------
 1. Unity test framework (single-file, MIT):
      https://github.com/ThrowTheSwitch/Unity
    Only three files are needed:
      unity/src/unity.c
      unity/src/unity.h
      unity/src/unity_internals.h```

Place the files as:

    ── unity/
       └── src/
           ├── unity.c
           ├── unity.h
           └── unity_internals.h

## Step 1 - Compile with coverage instrumentation

```bash
gcc -std=c99 -Wall -Wextra \
    --coverage -fprofile-arcs -ftest-coverage \
    -O0 \
    -I inc/ \
    -I unity/src/ \
    src/mode_logic_team.c \
    unity/src/unity.c \
    test/<TEST_FILE> \
    -o test_runner
```

## Step 2 - Run the tests

```bash
./test_runner
```

## Step 4 - Rename the generated files and move them to src/ folder

The generated files
```txt
test_runner-mode_logic_team.gcda
test_runner-mode_logic_team.gcno
```

Should be renamed to
```txt
mode_logic_team.gcda
mode_logic_team.gcno
```
and should be moved to the src/ directory


## Step 4 Collect gcov coverage data

```bash
gcov -b -c src/mode_logic_team.c
```

## Step 5 Generate HTM report with lcov

```bash
    lcov --capture \
         --directory . \
         --output-file coverage.info
 
    genhtml coverage.info \
            --branch-coverage \
            --output-directory coverage_html/
 
    open coverage_html/index.html
```