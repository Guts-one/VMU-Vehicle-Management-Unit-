# ============================================================================
# Makefile - CROSS-CUTTING requirement tests (shared)
#
# Covers: SwHLR01, SwHLR02, SwHLR10, SysHLR01/02/03, NfHLR02, and NfHLR04.
# See `README.md` in this folder.
#
# Targets:
#   make            -> builds and runs the suite without coverage
#   make run        -> same
#   make clean      -> removes artifacts
# ============================================================================

# --- paths (relative to this folder: tests/shared_tests/) --------------------
ROOT     := ../..
SRC_DIR  := $(ROOT)/src
INC_DIR  := $(ROOT)/inc
UNITY    := $(ROOT)/unity

# --- toolchain ---------------------------------------------------------------
CC       := gcc
CSTD     := -std=c99
WARN     := -Wall -Wextra -Wpedantic
INC      := -I$(INC_DIR) -I$(UNITY)

CFLAGS   := $(CSTD) $(WARN) $(INC) -O0 -g

# --- files -------------------------------------------------------------------
SRCS := \
	$(SRC_DIR)/mode_logic_team.c \
	$(UNITY)/unity.c              \
	test_shared_requirements.c

BIN  := test_shared.exe

# --- targets -----------------------------------------------------------------
.PHONY: all run clean

all: run

$(BIN): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $@

run: $(BIN)
	./$(BIN)

clean:
	-rm -f $(BIN)
	-rm -f *.gcno *.gcda *.gcov
