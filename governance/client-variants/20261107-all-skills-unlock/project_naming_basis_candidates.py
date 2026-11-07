"""Eight individually admitted Server lab hypotheses; no fuzzy name mapper."""
from pathlib import Path
import argparse
import hashlib
import json

parser = argparse.ArgumentParser()
parser.add_argument("bindings", type=Path)
parser.add_argument("output", type=Path)
args = parser.parse_args()
assert args.bindings.resolve() != args.output.resolve(), "Use a separate reviewable output"
D = Path(__file__).parent

def evidence(name, digest):
    data = (D / name).read_bytes()
    assert hashlib.sha256(data).hexdigest() == digest
    return json.loads(data)["groups"]

spelling = evidence("spelling-skill-family-review.json", "cc0f8e670762fb1c3b2b688000135fa3d6c2bec3a11ae0a08c7c43950c06aa5c")
other = evidence("three-basic-skill-family-comparison-v1.json", "c1cdfbf996b38040f71cb8cf7ab4c57f253704b8faf8c56107cf22791fdb1ff9")
electric_bytes = (D / "soma-active6-electric-family-review.json").read_bytes()
assert hashlib.sha256(electric_bytes).hexdigest() == "ce831582fc60deed7725d93af5f3080d8f3f16c3edb6cfeb47d67144427cc1bb"
electric = json.loads(electric_bytes)
# Explicit root policy: Basis means the labelled resource, not learned/script level1.
specs = [(1,3,3,113,4),(2,14,20,108,6),(2,18,25,115,4),
         (3,471,43,116,6),(6,49,82,105,6),(6,54,87,108,7),(8,2530,184,164,3),(1,6,6,114,6)]
raw = args.bindings.read_bytes()
rows = json.loads(raw)
admitted = []
for role, active, practice, motion, slots in specs:
    group = next(g for g in spelling + other + [electric] if (g["role"],g["active"],g["practice"]) == (role,active,practice))
    if "clips" in group:
        basis = ([c for c in group["clips"] if {e["explicitVariantLabel"].lower() for e in c["effects"] if e["explicitVariantLabel"]} == {"basis"}]
                 if group is electric else [c for c in group["clips"] if c["explicitResourceVariantLabels"] == ["basis"]])
        assert len(basis) == 1 and basis[0]["motion"] == motion
        assert basis[0]["animationData"]["Repeat"] == "false"
        splits = basis[0]["splitData"]
    else:
        basis = [c for c in group["candidates"] if {e["declaredVariantLabel"].lower() for e in c["effects"] if e["declaredVariantLabel"]} == {"basis"}]
        assert len(basis) == 1 and basis[0]["action"] == motion
        assert basis[0]["abfAnimation"]["Repeat"] == "false"
        splits = basis[0]["splitRows"]
    estimate = sum((float(s["EndFrame"])+float(s["Delay"]))/float(s["FPS"]) for s in splits)
    assert estimate > 0
    selected = [r for r in rows if (r["Role"],r["Practice"],r["Active"]) == (role,practice,active)]
    assert len(selected) == slots
    # Preserve the matrix's actual tier. No charge-stage bypass is introduced.
    if active == 18:
        assert all(r["Tier"] == 2 for r in selected)
    if active in (6,471):
        assert all(r["Tier"] == 1 for r in selected)
    for row in selected:
        row.update(Motions=[motion],Durations=[estimate],Status="SERVER_OWNED_NAMING_BASIS_COMPARISON_CANDIDATE")
    admitted.append({"role":role,"active":active,"practice":practice,"motion":motion,"slots":slots})
result = (json.dumps(rows,ensure_ascii=False,indent=2)+"\n").encode("utf-8")
args.output.write_bytes(result)
print(json.dumps({"policy":"INDIVIDUALLY_REVIEWED_SERVER_LAB_BASIS_ONLY_NOT_NATIVE_MAPPING",
                  "admitted":admitted,"inputSha256":hashlib.sha256(raw).hexdigest(),
                  "outputSha256":hashlib.sha256(result).hexdigest(),
                  "sourceMappingClosed":False,"advancedVariantAssignment":False,
                  "timingFormulaVerified":False}))
