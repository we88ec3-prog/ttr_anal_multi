#!/usr/bin/env python3
"""Validate Iteration40 source-bounded C04 login receive plan without promoting KR native status."""
from __future__ import annotations
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
P = "governance/s00-iterations/S00-ITERATION-40-C04-LOGIN-M2-ACCEPTANCE.json"
D = "governance/s00-iterations/S00-20261101-ITERATION-40-T01-SYNC-C04-LOGIN-RECEIVE-DELIVERY.md"

def read(root, name):
    return json.loads((root / name).read_text(encoding="utf-8"))

def evaluate(root: Path = ROOT):
    errors = []
    try:
        plan = read(root, P)
        req = read(root, "design/requirements/index.json")
        rr = read(root, "research/requests/index.json")
        gap = read(root, "design/gaps/index.json")
        claims = read(root, "research/claims/index.json")
        intake = read(root, "research/intake/index.json")
        targets = read(root, "shared/targets.json")
        doc = (root / D).read_text(encoding="utf-8")
    except (OSError, ValueError, TypeError, KeyError) as e:
        return {"errors": [f"Iteration40 missing/malformed input: {e}"], "summary": {}}
    if plan.get("schema") != "s00-iteration40-c04-login-m2-acceptance-v1" or plan.get("kind") != "NON_NORMATIVE_READINESS_OVERLAY":
        errors.append("Iteration40 nonnormative schema mismatch")
    if plan.get("kr_bin_sha256") != targets["kr"]["sha256"]:
        errors.append("KR target pin mismatch")
    if plan.get("t01_branch_head_fast_forwarded_to_main") != "8c93012edc4b76103a72d8b2f8868d6357034978":
        errors.append("T01 sync SHA mismatch")
    for key in ("original_client_test_performed", "server_code_changed", "original_client_changed", "session_wire_claim_approved"):
        if plan.get("authorization", {}).get(key) is not False:
            errors.append(f"Iteration40 cannot self-certify {key}")
    for key in ("new_rr", "new_req", "new_gap", "new_test", "promote_spec"):
        if plan.get("formal_registry_mutations", {}).get(key) != 0:
            errors.append(f"cannot change formal registry via plan: {key}")
    for key, catalog in (("reused_requirements",req),("reused_rrs",rr),("open_gaps",gap)):
        values = plan.get(key, [])
        available = {r["id"] for r in catalog["items"]}
        if not isinstance(values,list) or len(values) != len(set(values)) or any(v not in available for v in values):
            errors.append(f"{key} missing/duplicated/unknown")
    for gid in plan.get("open_gaps", []):
        row = next((x for x in gap["items"] if x["id"] == gid), {})
        if row.get("status") != "OPEN":
            errors.append(f"source-pinned plan assumes {gid} OPEN")
    if plan.get("baseline_server_impl",{}).get("E0") != "NATIVE_GATE_DISABLED":
        errors.append("native contract admission must remain disabled")
    expected = ["M0","M1","M2","M3","M4"]
    milestones = plan.get("milestones",[])
    if [m.get("id") for m in milestones] != expected:
        errors.append("Iteration40 milestones must be ordered M0..M4")
    for m in milestones:
        if m.get("is_original_client_verified") is not False:
            errors.append(f"milestone {m.get('id')} falsely claims original Client verified")
    if len(plan.get("gates",[])) != 15 or plan.get("gates_count") != 15:
        errors.append("Iteration40 gates must contain exactly 15")
    ids=[x.get("id") for x in plan.get("gates",[])]
    if ids != [f"I40-{i:02d}" for i in range(1,16)]:
        errors.append("Iteration40 gate order/identities wrong")
    allowed={"MERGED_SOURCE_BOUNDED","OFFLINE_IMPLEMENTED","PLANNED_NOT_IMPLEMENTED",
             "BLOCKED_BY_NATIVE_CONTRACT","BLOCKED_BY_NATIVE_CONTRACT_AND_AUTHORIZATION","NOT_RUN"}
    if any(x.get("status") not in allowed for x in plan.get("gates",[])):
        errors.append("Cannot declare I40 original Client PASS in plan")
    index_claims={x["id"]:x for x in claims["items"]}
    index_intake={x["id"]:x for x in intake["items"]}
    for row in plan.get("known_source_claims", []):
        c=index_claims.get(row["id"])
        if c is None or c.get("evidence_level")!="PARTIAL" or c.get("source_intake_id")!=row["source"]:
            errors.append(f"source claim not correctly bounded {row['id']}")
        src=index_intake.get(row["source"])
        if src is None or src.get("integration_status")!="CONFLICT_CHECKED":
            errors.append(f"source not conflict-checked {row['source']}")
    for s in ("C04-E1b","C04-E2a","C04-E2b","C04-E3a","C04-E3b","CLM-NET-0037",
              "RR-0006","0x807C81","0BBB","0x2633","C04-F0","T01"):
        if s not in doc:
            errors.append(f"handoff lacks scope: {s}")
    return {"errors":sorted(set(errors)), "summary":{
        "gates":len(plan.get("gates",[])), "milestones":len(milestones),
        "claims":len(plan.get("known_source_claims",[])), "original_client_verified":False}}

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument("--check",action="store_true")
    p.add_argument("--json",action="store_true")
    p.add_argument("--root",type=Path,default=ROOT)
    a=p.parse_args()
    r=evaluate(a.root.resolve())
    if a.json: print(json.dumps(r,indent=2,ensure_ascii=False))
    else:
        print("S00 Iteration40:",r["summary"])
        for x in r["errors"]:print("ERROR",x)
    if a.check and r["errors"]: raise SystemExit(1)

if __name__=="__main__":
    main()
