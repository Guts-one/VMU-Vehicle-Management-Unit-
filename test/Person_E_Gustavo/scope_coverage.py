"""
scope_coverage.py

Reads a .gcov file produced by gcov for `mode_logic_team.c` and reports line
and branch coverage ONLY for the scope assigned to Person E.

Person E scope (source-file lines):
  - motion_ice_common_exit (Start/ICE/Hybrid external transitions) : 87-110
  - internal_motion_ice_reset (shared, used here)                  : 113-123
  - handle_start                                                   : 126-149
  - handle_ice                                                     : 152-173
  - handle_hybrid                                                  : 176-197
  - write_outputs (output mapping for touched modes)               : 200-245
  - ModeLogic_Init / ModeLogic_Step (public interface)             : 247-296

Outside the scope (Persons A, B, and C):
  - handle_standstill : 7-27
  - handle_ev         : 30-55
  - handle_regenb     : 58-84

Usage:
  python scope_coverage.py mode_logic_team.c.gcov
"""

from __future__ import annotations

import re
import sys
from pathlib import Path


PERSON_E_RANGES = [
    ("motion_ice_common_exit",     87, 110),
    ("internal_motion_ice_reset", 113, 123),
    ("handle_start",              126, 149),
    ("handle_ice",                152, 173),
    ("handle_hybrid",             176, 197),
    ("write_outputs",            200, 245),
    ("ModeLogic_Init",            247, 253),
    ("ModeLogic_Step",            255, 296),
]

# Lines that are inside the ranges above but do not belong to Person E
# (owned by other assignees or unreachable MISRA fallbacks). They are excluded
# from the scoped coverage calculation.
EXCLUDED_LINES = set()

# write_outputs default branch: unreachable in normal operation (MISRA 16.4).
EXCLUDED_LINES.update(range(239, 244))

# ModeLogic_Step switch: cases for modes that do not belong to Person E
# (MODE_STANDSTILL -> Person A, MODE_EV -> B, MODE_REGENB -> C) and the safety
# default.
EXCLUDED_LINES.update(range(263, 274))  # MODE_STANDSTILL, MODE_EV, MODE_REGENB
EXCLUDED_LINES.update(range(287, 290))  # default

# Internal Start->Hybrid and Start->ICE transitions belong to Person D
# (SwLLR18 / SwLLR19).
EXCLUDED_LINES.update(range(133, 145))

# Reset to Start inside the Motion_mode_ICE block belongs to Person D
# (SwLLR20 - ICE->Start, SwLLR22 - Hybrid->Start).
# Calls to internal_motion_ice_reset inside handle_ice and handle_hybrid are
# evaluated here; the function lines themselves are too.
EXCLUDED_LINES.update(range(113, 124))  # internal_motion_ice_reset (Person D)
EXCLUDED_LINES.update(range(158, 162))  # call in handle_ice
EXCLUDED_LINES.update(range(182, 186))  # call in handle_hybrid

# Individual branches to exclude by line.
# Switches with out-of-scope cases (or MISRA defaults) generate branches that
# point to code outside Person E, even when the switch header line itself is in
# scope.
#
# gcov orders switch branches in the same order as the case labels in source.
#
# write_outputs (line 202): order MODE_STANDSTILL, EV, REGENB, START, ICE,
#   HYBRID, default. Branch 6 (default) is the MISRA fallback.
#
# ModeLogic_Step (line 262): same order. Branches 0, 1, and 2 are for
#   Standstill/EV/RegenB (Persons A, B, C). Branch 6 is the MISRA default.
EXCLUDED_BRANCHES = {
    202: {6},           # write_outputs default
    262: {0, 1, 2, 6},  # dispatch to other persons' modes + default
}


def in_scope(lineno: int) -> bool:
    if lineno in EXCLUDED_LINES:
        return False
    return any(lo <= lineno <= hi for _, lo, hi in PERSON_E_RANGES)


def branch_in_scope(lineno: int, branch_idx: int) -> bool:
    if not in_scope(lineno):
        return False
    return branch_idx not in EXCLUDED_BRANCHES.get(lineno, set())


def parse_gcov(path: Path):
    """
    Returns lists:
      lines_in_scope     : [(count, lineno), ...]
      branches_in_scope  : [(taken, total), ...] where total=2 (taken or not)
    Line-by-line coverage considers only executable lines (numeric counts,
    excluding lines marked with '-').
    """
    lines = []
    branches = []

    current_line = None

    with path.open("r", encoding="utf-8", errors="replace") as fh:
        for raw in fh:
            line = raw.rstrip("\n")

            # gcov line layout: "  <count>: <lineno>: <source>"
            m = re.match(r"\s*([#\-\d]+)\s*:\s*(\d+)\s*:", line)
            if m:
                count_s, lineno_s = m.group(1), m.group(2)
                lineno = int(lineno_s)
                current_line = lineno
                if in_scope(lineno) and count_s not in ("-",):
                    if count_s == "#####":
                        count = 0
                    else:
                        try:
                            count = int(count_s)
                        except ValueError:
                            count = 0
                    lines.append((count, lineno))
                continue

            # gcov branch layout: "branch  N taken X (fallthrough)" or "never executed"
            m = re.match(r"\s*branch\s+(\d+)\s+(.*)", line)
            if m and current_line is not None:
                branch_idx = int(m.group(1))
                if not branch_in_scope(current_line, branch_idx):
                    continue
                tail = m.group(2)
                if "never executed" in tail:
                    branches.append((0, 1))
                else:
                    m2 = re.search(r"taken\s+(\d+)", tail)
                    if m2:
                        taken = int(m2.group(1))
                        branches.append((1 if taken > 0 else 0, 1))

    return lines, branches


def summarize(lines, branches):
    exec_lines_total = len(lines)
    exec_lines_hit = sum(1 for c, _ in lines if c > 0)

    branch_total = len(branches)
    branch_hit = sum(1 for h, _ in branches if h)

    def pct(hit, total):
        return 0.0 if total == 0 else (100.0 * hit / total)

    print("Executable lines in scope : {} / {} ({:.2f}%)".format(
        exec_lines_hit, exec_lines_total, pct(exec_lines_hit, exec_lines_total)))
    print("Branches in scope (taken>=1): {} / {} ({:.2f}%)".format(
        branch_hit, branch_total, pct(branch_hit, branch_total)))

    uncovered = [ln for c, ln in lines if c == 0]
    if uncovered:
        print("Uncovered executable lines: {}".format(
            ", ".join(str(ln) for ln in uncovered)))
    else:
        print("All executable lines in scope were covered.")


def main(argv):
    if len(argv) < 2:
        print("usage: python scope_coverage.py <file.gcov>", file=sys.stderr)
        return 2
    path = Path(argv[1])
    if not path.exists():
        print("file not found: {}".format(path), file=sys.stderr)
        return 2

    lines, branches = parse_gcov(path)
    summarize(lines, branches)
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv))
