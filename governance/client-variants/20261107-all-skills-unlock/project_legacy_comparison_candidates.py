"""Six explicit lab policies; do not infer native combos or effect selection."""
from pathlib import Path
import argparse
import hashlib
import json

parser = argparse.ArgumentParser()
parser.add_argument("bindings", type=Path)
parser.add_argument("output", type=Path)
args = parser.parse_args()
assert args.bindings.resolve() != args.output.resolve()
D = Path(__file__).parent

def load(name, digest):
    raw = (D / name).read_bytes()
    assert hashlib.sha256(raw).hexdigest() == digest
    return json.loads(raw)["groups"]

basic = load("three-basic-resource-family-review.json", "d34ad582e23a091ff0e4b681c06ff79232ecfc7b4977fe243db04d549656fd46")
symmetry = load("aelt-symmetry-family-review.json", "f33dd8f3fb1fd1fdbb0d06d4be38f57adf400c80b59c7733e39e5f7e69362503")
visual = load("multi-basis-variant-differences-v1.json", "53a4c0bb16c3d7933fd1a3acb5e8ed96bae47d89817ab9bffd2a420b9a7fcbb4")
specs = [(2,10,17,[101,102,103,104,105],7,"BASIC"),
         (5,38,65,[101,102,103,104,105],7,"BASIC"),
         (7,332,97,[101],4,"BASIC"),
         (5,44,71,[113],4,"BASIS"),
         (1,5,5,[110,111,112],4,"VISUAL"),
         (2,19,26,[112,113,114,184],6,"VISUAL")]
raw = args.bindings.read_bytes()
rows = json.loads(raw)
applied = []
for role, active, practice, motions, slots, policy in specs:
    group = next(g for g in basic+symmetry+visual if (g["role"],g["active"],g["practice"]) == (role,active,practice))
    clips = {c["motion"]:c for c in group["clips"]}
    durations = []
    for motion in motions:
        clip = clips[motion]
        assert clip["animationData"]["Repeat"] == "false"
        splits = clip.get("splitData",clip.get("splitRows"))
        estimate = sum((float(s["EndFrame"])+float(s["Delay"]))/float(s["FPS"]) for s in splits)
        assert estimate > 0
        durations.append(estimate)  # Existing unverified lab estimate, not native timing.
    if policy == "BASIS":
        assert group["uniqueBasisResourceMotion"] == motions[0]
    if policy == "VISUAL":
        assert not group["selectionRuleFound"]
        assert {d["path"].rsplit("/@",1)[-1] for d in group["asdCanonicalDifferencesExcludingHeaderIdName"]} == {"File"}
    selected = [r for r in rows if (r["Role"],r["Practice"],r["Active"]) == (role,practice,active)]
    assert len(selected) == slots
    status = {"BASIC":"SERVER_OWNED_ROLE_BASIC_SEQUENCE_CANDIDATE",
              "BASIS":"SERVER_OWNED_NAMING_BASIS_COMPARISON_CANDIDATE",
              "VISUAL":"SERVER_OWNED_VISUAL_VARIANT_COMPARISON_CANDIDATE"}[policy]
    for row in selected:
        assert not row["Motions"] or row["Status"] == status
        if policy == "BASIC":
            assert row["Tier"] == 0 and row["Mask"] == 1
        if active == 19:
            assert row["Tier"] == 1
        row.update(Motions=motions,Durations=durations,Status=status)
    applied.append({"role":role,"active":active,"motions":motions,"slots":slots,"policy":policy})
result = (json.dumps(rows,ensure_ascii=False,indent=2)+"\n").encode("utf-8")
args.output.write_bytes(result)
print(json.dumps({"applied":applied,"inputSha256":hashlib.sha256(raw).hexdigest(),
                  "outputSha256":hashlib.sha256(result).hexdigest(),
                  "nativeMappingClosed":False,"nativeVariantSelectionClosed":False}))
