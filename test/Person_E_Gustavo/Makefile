# ============================================================================
# Makefile - Person E unit tests (Gustavo)
#
# Main targets:
#   make            -> builds and runs the tests without coverage
#   make run        -> same
#   make coverage   -> builds with instrumentation, runs the suite, and
#                      generates text and HTML coverage reports when
#                      lcov/genhtml are available
#   make clean      -> removes build artifacts
#
# Requirements:
#   - gcc (MSYS2 / MinGW-w64)
#   - gcov (shipped with gcc)
#   - optional: lcov + genhtml for the HTML report
# ============================================================================

# --- paths (relative to this Makefile, under tests/Person_E_Gustavo/) --------
ROOT     := ../..
SRC_DIR  := $(ROOT)/src
INC_DIR  := $(ROOT)/inc
UNITY    := $(ROOT)/unity

# --- toolchain ---------------------------------------------------------------
CC       := gcc
CSTD     := -std=c99
WARN     := -Wall -Wextra -Wpedantic
INC      := -I$(INC_DIR) -I$(UNITY)

CFLAGS_BASE := $(CSTD) $(WARN) $(INC)

# Coverage instrumentation for gcov (lines + branches).
CFLAGS_COV  := $(CFLAGS_BASE) -O0 -g --coverage -fprofile-arcs -ftest-coverage
LDFLAGS_COV := --coverage

# Plain execution.
CFLAGS_RUN  := $(CFLAGS_BASE) -O0 -g

# --- files -------------------------------------------------------------------
SRCS := \
	$(SRC_DIR)/mode_logic_team.c \
	$(UNITY)/unity.c              \
	test_person_e.c

BIN_RUN := test_person_e.exe
BIN_COV := test_person_e_cov.exe

# --- targets -----------------------------------------------------------------
.PHONY: all run coverage clean

all: run

$(BIN_RUN): $(SRCS)
	$(CC) $(CFLAGS_RUN) $(SRCS) -o $@

run: $(BIN_RUN)
	./$(BIN_RUN)

# -- coverage ----------------------------------------------------------------
# Objects are generated separately so the .gcno/.gcda files stay next to them
# and gcov can find the sources reliably.

COV_DIR := build_cov
COV_OBJS := \
	$(COV_DIR)/mode_logic_team.o \
	$(COV_DIR)/unity.o           \
	$(COV_DIR)/test_person_e.o

$(COV_DIR):
	mkdir -p $(COV_DIR)

$(COV_DIR)/mode_logic_team.o: $(SRC_DIR)/mode_logic_team.c | $(COV_DIR)
	$(CC) $(CFLAGS_COV) -c $< -o $@

$(COV_DIR)/unity.o: $(UNITY)/unity.c | $(COV_DIR)
	$(CC) $(CFLAGS_COV) -c $< -o $@

$(COV_DIR)/test_person_e.o: test_person_e.c | $(COV_DIR)
	$(CC) $(CFLAGS_COV) -c $< -o $@

$(BIN_COV): $(COV_OBJS)
	$(CC) $(LDFLAGS_COV) $(COV_OBJS) -o $@

coverage: $(BIN_COV)
	./$(BIN_COV)
	@echo ""
	@echo "======================================================================"
	@echo "Coverage for mode_logic_team.c (gcov - lines + branches)"
	@echo "======================================================================"
	gcov -b -c -o $(COV_DIR) $(SRC_DIR)/mode_logic_team.c
	@echo ""
	@echo "======================================================================"
	@echo "Coverage for the Person E scope (excludes handle_standstill/ev/regenb)"
	@echo "======================================================================"
	@python scope_coverage.py mode_logic_team.c.gcov 2>/dev/null || \
	  python3 scope_coverage.py mode_logic_team.c.gcov 2>/dev/null || \
	  echo "(python not found - the raw gcov output above still shows lines per function)"
	@echo ""
	@if command -v lcov >/dev/null 2>&1; then \
	  echo "Generating lcov/HTML report..."; \
	  lcov --capture --directory $(COV_DIR) --output-file $(COV_DIR)/cov.info --rc lcov_branch_coverage=1 --ignore-errors source; \
	  lcov --remove $(COV_DIR)/cov.info '*/unity/*' '*/tests/*' --output-file $(COV_DIR)/cov.filtered.info --rc lcov_branch_coverage=1; \
	  genhtml $(COV_DIR)/cov.filtered.info --output-directory $(COV_DIR)/html --branch-coverage; \
	  echo "HTML: $(COV_DIR)/html/index.html"; \
	else \
	  echo "(lcov not found - skipped HTML. Install lcov to generate the report)"; \
	fi

clean:
	-rm -f $(BIN_RUN) $(BIN_COV)
	-rm -rf $(COV_DIR)
	-rm -f *.gcno *.gcda *.gcov *.info
