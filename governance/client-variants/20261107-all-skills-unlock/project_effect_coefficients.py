"""Project source effect coefficients, without inventing damage/heal formulas.

Reads original/working members only. Output contains numeric metadata, no raw XML.
"""
from pathlib import Path
import collections
import hashlib
import json
import sys
import xml.etree.ElementTree as E

R = Path(sys.argv[1]) if len(sys.argv) > 1 else Path(r"E:\Tartaros\workspace")
D = Path(__file__).parent
sys.path.insert(0, str(R / "anal"))
from stp_resources import Archive

sha = lambda value: hashlib.sha256(value).hexdigest()
member = "Table/SkillActiveTable.xml"
original = Archive(R.parent / "origin/Table.stp").read(member)
working = Archive(R / "Table.stp").read(member)
assert original == working, "Active gameplay source differs; review before projection"
assert sha(original) == "1ea831f270df757d760f4ff87d6bf509a64326a23614a305c8d767580f2a2139"
root = E.fromstring(original)
active = {int(node.get("no")): node for node in root}
cost_path = R / "CLIENT/evidence/20261107-skill-levels/active-practice-level-costs.json"
cost_bytes = cost_path.read_bytes()
assert sha(cost_bytes) == "75095ecd0c61abadd931eb9dc36114d2898d04997c6b41790a19a0771f55a779"
costs = json.loads(cost_bytes.decode("utf-8-sig"))["rows"]
rows = []
def optional_integer(node, name):
    value = node.get(name)
    return int(value) if value is not None else None

for cost in costs:
    skill = active[cost["active"]]
    level = skill.find(f"LEVEL[@val='{cost['activeLevel']}']")
    assert level is not None
    effects = []
    for child in level:
        if child.tag == "ACTIVEINFO":
            continue
        assert child.tag in ("ATTACK", "HEAL"), child.tag
        assert set(child.attrib) == {"ratio", "rev"}
        effects.append({"kind": child.tag, "ratio": int(child.get("ratio")),
                        "revision": int(child.get("rev"))})
    rows.append({key: cost[key] for key in
                 ("role", "practice", "learnedLevel", "active", "activeLevel")} |
                {"effects": effects, "skillType": optional_integer(skill, "type"),
                 "form": optional_integer(skill, "form"), "attribute": optional_integer(skill, "attribute"),
                 "attackLevel": optional_integer(skill, "AtkLevel"),
                 "defenseLevel": optional_integer(skill, "DefLevel")})
assert len({(r["role"], r["practice"], r["learnedLevel"]) for r in rows}) == len(rows)
by_active = {}
for row in rows:
    by_active.setdefault((row["role"], row["active"]), row["effects"])
summary = {"levelRows": len(rows), "uniqueRoleActive": len(by_active),
           "effectKindsByLevel": dict(collections.Counter(
               e["kind"] for r in rows for e in r["effects"])),
           "healSkills": [{"role": role, "active": ident}
                          for (role, ident), effects in sorted(by_active.items())
                          if any(e["kind"] == "HEAL" for e in effects)]}
output = {"schema": "SOURCE_SKILL_EFFECT_COEFFICIENTS_V1",
          "authority": "EXACT_RESOURCE_LEVEL_JOIN_NOT_COMBAT_FORMULA",
          "sourceMember": member, "originalSha256": sha(original),
          "workingSha256": sha(working), "levelCostProjectionSha256": sha(cost_bytes),
          "summary": summary, "rows": rows,
          "limitations": [
              "ATTACK and HEAL are source tags, not proven target-selection policies.",
              "ratio/rev units, attack stat, defenses, criticals, hit count and timing remain unresolved.",
              "No same-key fallback, motion inheritance or runtime effect formula is introduced.",
              "No Client execution/modification or original-resource changes."]}
dest = D / "source-effect-coefficients.json"
dest.write_text(json.dumps(output, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")
print(json.dumps({"output": str(dest), "sha256": sha(dest.read_bytes()), **summary}))
