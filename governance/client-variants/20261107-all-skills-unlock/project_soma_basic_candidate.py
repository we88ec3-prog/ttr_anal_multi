"""Apply an explicit Server-owned Soma lab policy; not recovered native dispatch."""
from pathlib import Path
import argparse
import hashlib
import json

parser = argparse.ArgumentParser()
parser.add_argument("bindings", type=Path)
parser.add_argument("output", type=Path)
args = parser.parse_args()
assert args.bindings.resolve() != args.output.resolve(), "Use a separate reviewable output"
evidence_path = Path(__file__).with_name("soma-basic-projectile-resource-boundary.json")
evidence_bytes = evidence_path.read_bytes()
assert hashlib.sha256(evidence_bytes).hexdigest() == "873672a2cec4a47148cfdd6c02be938815bdfe332d5a3d14fc92ddc657e0ccfe"
evidence = json.loads(evidence_bytes)
clips = evidence["clips"]
assert [clip["motion"] for clip in clips] == [101, 102, 103, 104, 105, 106]
assert all(clip["animationData"]["Repeat"] == "false" for clip in clips)
# Preserve the existing lab's unverified timing estimate, not a native formula.
estimates = [sum((float(row["EndFrame"]) + float(row["Delay"])) / float(row["FPS"])
                 for row in clip["referIndex"]) for clip in clips]
raw = args.bindings.read_bytes()
rows = json.loads(raw)
selected = [r for r in rows if (r["Role"], r["Practice"], r["Active"], r["Tier"], r["Mask"]) == (1, 1, 1, 0, 1)]
assert len(selected) == 7 and {r["Matrix"] for r in selected} == set(range(7))
for row in selected:
    assert (row["Hp"], row["Sp"], row["Mp"], row["RawCooltime"]) == (0, 0, 0, 0)
    row.update(Motions=[101, 102, 103, 104, 105, 106], Durations=estimates,
               Status="SERVER_OWNED_SOMA_BASIC_SEQUENCE_CANDIDATE")
result = (json.dumps(rows, ensure_ascii=False, indent=2) + "\n").encode("utf-8")
args.output.write_bytes(result)
print(json.dumps({"inputSha256": hashlib.sha256(raw).hexdigest(),
                  "outputSha256": hashlib.sha256(result).hexdigest(),
                  "policy": "SERVER_OWNED_ISOLATED_COMPARISON_NOT_NATIVE_MAPPING",
                  "slots": len(selected), "sourceMappingClosed": False,
                  "projectileImplemented": False, "timingFormulaVerified": False}))
