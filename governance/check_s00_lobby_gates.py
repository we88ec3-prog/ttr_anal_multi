#!/usr/bin/env python3
"""Read-only L00–L08 design gate checks using canonical S00 indices.

A green structural check says nothing about original Client compatibility.
"""
import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
INPUTS = {
    "requirement_ids": "design/requirements/index.json",
    "rr_ids": "research/requests/index.json",
    "gap_ids": "design/gaps/index.json",
    "spec_ids": "spec/spec-index.json",
}
STAGES = {"L" + str(n).zfill(2) for n in range(9)}
TEST_LEVELS = {"OFFLINE_SYNTHETIC_PLANNED", "SOURCE_BACKED_VECTOR_PROPOSED",
               "DESIGN_ONLY", "ORIGINAL_CLIENT_COMPATIBILITY_PENDING_AUTHORIZATION"}


def _read(root, p):
    return json.loads((root / p).read_text(encoding="utf-8"))


def assess(root=ROOT):
    errors = []
    try:
        matrix = _read(root, "governance/s00-lobby-gates.json")
        tests = _read(root, "governance/s00-iteration12-lobby-test-plan.json")
        references = {
            key: {x["id"]: x for x in _read(root, path)["items"]}
            for key, path in INPUTS.items()
        }
        target = _read(root, "shared/targets.json")
    except (OSError, ValueError, KeyError, TypeError) as e:
        return {"errors": [f"missing/invalid source: {e}"], "gates": []}
    if matrix.get("schema") != "s00-lobby-gates-v1" or matrix.get("kind") != "NON_NORMATIVE_DESIGN_OVERLAY":
        errors.append("unexpected lobby gate schema/kind")
    if tests.get("schema") != "s00-iteration12-lobby-test-plan-v1" or tests.get("status") != "DESIGN_ONLY_NOT_EXECUTED":
        errors.append("Iteration12 test plan must remain explicitly unexecuted")
    if matrix.get("client_version") != "kr" or matrix.get("target_sha256") != target.get("kr", {}).get("sha256"):
        errors.append("matrix Client version/SHA not pinned to registered KR")
    if tests.get("client_version") != "kr" or tests.get("target_sha256") != matrix.get("target_sha256"):
        errors.append("test plan Client SHA/version mismatch")
    cases = tests.get("cases", [])
    if not isinstance(cases, list):
        return {"errors": errors + ["test cases not a list"], "gates": []}
    test_ids = {}
    for t in cases:
        if not isinstance(t, dict) or not isinstance(t.get("id"), str):
            errors.append("invalid planned test")
            continue
        if t["id"] in test_ids:
            errors.append("duplicate test case " + t["id"])
        test_ids[t["id"]] = t
        if t.get("level") not in TEST_LEVELS:
            errors.append("unknown planned test level: " + t["id"])
        if not isinstance(t.get("evidence"), list) or not t["evidence"]:
            errors.append("planned test missing provenance: " + t["id"])
        else:
            for item in t["evidence"]:
                if not any(item in table for table in references.values()) and item not in {
                    x["id"] for x in _read(root, "conformance/test-index.json")["items"]
                }:
                    errors.append(f"{t['id']} unknown evidence link {item}")
        if not t.get("blocker"):
            errors.append(f"{t['id']} missing blocker")
    gates = matrix.get("gates")
    if not isinstance(gates, list) or not gates:
        return {"errors": errors + ["gates not populated"], "gates": []}
    by_id = {}
    used_cases = set()
    output = []
    for g in gates:
        if not isinstance(g, dict) or not isinstance(g.get("id"), str):
            errors.append("malformed gate")
            continue
        gid = g["id"]
        if gid in by_id:
            errors.append("duplicate gate " + gid)
        by_id[gid] = g
        if gid not in STAGES:
            errors.append("unrecognized gate " + gid)
        for field in ("known", "unproven", "next_action", "title"):
            if not isinstance(g.get(field), str) or not g[field].strip():
                errors.append(f"{gid} missing {field}")
        if not isinstance(g.get("owners"), list) or not g["owners"]:
            errors.append(f"{gid} missing owners")
        current = []
        blockers = []
        for field, table in references.items():
            ids = g.get(field)
            if not isinstance(ids, list) or len(ids) != len(set(map(str, ids))):
                errors.append(f"{gid} invalid {field}")
                continue
            for ref_id in ids:
                ref = table.get(ref_id)
                if ref is None:
                    errors.append(f"{gid} unknown {field}={ref_id}")
                    continue
                if ref.get("client_version") not in {None, "kr"}:
                    errors.append(f"{gid} cross-version {ref_id}")
                if field == "requirement_ids" and ref.get("status") != "APPROVED":
                    blockers.append(f"{ref_id}={ref.get('status','UNKNOWN')}")
                if field == "rr_ids" and ref.get("dispatch", {}).get("state") != "ACCEPTED":
                    blockers.append(f"{ref_id}={ref.get('dispatch', {}).get('state','UNKNOWN')}")
                if field == "gap_ids" and ref.get("status") != "RESOLVED":
                    blockers.append(f"{ref_id}={ref.get('status','UNKNOWN')}")
                if field == "spec_ids" and (ref.get("maturity") not in {"REVIEWED","STABLE"}
                                           or ref.get("contract_status") != "DEFINED"):
                    blockers.append(f"{ref_id}={ref.get('maturity','UNKNOWN')}/{ref.get('contract_status','UNKNOWN')}")
                current.append(ref_id)
        refs = g.get("test_case_ids")
        if not isinstance(refs, list) or len(refs) != len(set(map(str, refs))):
            errors.append(f"{gid} invalid test refs")
            refs = []
        for cid in refs:
            if cid not in test_ids:
                errors.append(f"{gid} unknown test {cid}")
            elif test_ids[cid].get("checkpoint") != gid:
                errors.append(f"{gid} mismatched checkpoint on {cid}")
            used_cases.add(cid)
        if gid == "L08":
            if not refs or any(test_ids.get(cid, {}).get("level") !=
                               "ORIGINAL_CLIENT_COMPATIBILITY_PENDING_AUTHORIZATION" for cid in refs):
                errors.append("L08 needs only explicitly authorization-pending runtime plans")
            blockers.append("ORIGINAL_CLIENT_RUNTIME_NOT_AUTHORIZED_OR_OBSERVED")
        elif gid == "L07":
            blockers.append("UI_EVENT_TO_RENDER_CHAIN_NOT_PROVEN")
        if g.get("unproven"):
            blockers.append("NATIVE_UNPROVEN_REQUIREMENTS")
        output.append({"id": gid, "title": g.get("title"), "state": "BLOCKED",
                       "refs": current, "test_cases": refs, "blockers": sorted(set(blockers)),
                       "next_action": g.get("next_action")})
    if set(by_id) != STAGES:
        errors.append("lobby gates must cover exactly L00..L08")
    if used_cases != set(test_ids):
        errors.append("some planned tests not assigned to a gate: " + repr(sorted(set(test_ids)-used_cases)))
    output.sort(key=lambda g: g["id"])
    return {"schema": "s00-lobby-gate-report-v1",
            "note": "All gates remain BLOCKED pending native review/contract proof and permitted runtime tests. No states mutated.",
            "errors": sorted(set(errors)), "gates": output,
            "summary": {"gates": len(output), "planned_unexecuted_tests": len(test_ids),
                        "blocked": len(output)}}


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--root", type=Path, default=ROOT)
    p.add_argument("--check", action="store_true")
    p.add_argument("--json", action="store_true")
    args = p.parse_args()
    out = assess(args.root.resolve())
    if args.json:
        print(json.dumps(out, ensure_ascii=False, indent=2))
    else:
        print("S00 LOBBY (DESIGN-ONLY)")
        for r in out["gates"]:
            print(f"{r['id']} {r['state']} ({len(r['blockers'])} unresolved) — {r['next_action']}")
        for error in out["errors"]:
            print("ERROR:", error)
    if args.check and out["errors"]:
        raise SystemExit(1)


if __name__ == "__main__":
    main()
