"""Lists which scoped branches were not taken, with their source line."""
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from scope_coverage import branch_in_scope  # noqa

path = Path(sys.argv[1])

current_line = None
out = []

with path.open("r", encoding="utf-8", errors="replace") as fh:
    for raw in fh:
        line = raw.rstrip("\n")
        m = re.match(r"\s*([#\-\d]+)\s*:\s*(\d+)\s*:(.*)", line)
        if m:
            current_line = int(m.group(2))
            continue
        m = re.match(r"\s*branch\s+(\d+)\s+(.*)", line)
        if m and current_line is not None:
            idx = int(m.group(1))
            if not branch_in_scope(current_line, idx):
                continue
            tail = m.group(2)
            if "never executed" in tail or re.search(r"taken\s+0\b", tail):
                out.append((current_line, m.group(0).strip()))

for lineno, b in out:
    print("L{}  {}".format(lineno, b))
print("total scoped branches not taken:", len(out))
