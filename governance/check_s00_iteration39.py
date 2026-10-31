#!/usr/bin/env python3
"""Validate non-normative S00 Iteration39 login receive work-pack and evidence gates."""
from __future__ import annotations

import argparse
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PLAN = "governance/s00-iterations/S00-ITERATION-39-C04-LOGIN-RECEIVE-GATES.json"
PLAN_DOC = "governance/s00-iterations/S00-20261101-ITERATION-39-C04-LOGIN-RECEIVE-IMPLEMENTATION-CONTRACT.md"

def _read(root: Path, p: str):
    return json.loads((root / p).read_text(encoding="utf-8"))

def evaluate(root: Path = ROOT):
    errors = []
    try:
        p = _read(root, PLAN)
        req = _read(root, "design/requirements/index.json")
        rr = _read(root, "research/requests/index.json")
        gaps = _read(root, "design/gaps/index.json")
        targets = _read(root, "shared/targets.json")
        doc = (root / PLAN_DOC).read_text(encoding="utf-8")
    except (OSError, ValueError, KeyError, TypeError) as exc:
        return {"errors": [f"Iteration39 inputs unavailable: {exc}"], "summary": {}}
    if p.get("schema") != "s00-iteration39-login-receive-plan-v1":
        errors.append("unexpected Iteration39 schema")
    if p.get("kind") != "NON_NORMATIVE_SERVER_IMPLEMENTATION_PLAN":
        errors.append("Iteration39 plan cannot become normative through a JSON edit")
    if p.get("client_version") != "kr" or p.get("client_bin_sha256") != targets["kr"]["sha256"]:
        errors.append("KR Client target does not match canonical target")
    for key in ("reported_client_build_verified", "original_client_executed_by_s00",
                "server_code_changed", "native_adapter_enabled"):
        if p.get(key) is not False:
            errors.append(f"{key} must remain false in this planning-only snapshot")
    mutations = p.get("formal_registry_mutations", {})
    for key in ("new_reqs", "new_rr", "new_gaps", "new_tests", "promoted_specs"):
        if mutations.get(key) != 0:
            errors.append(f"no registry promotion allowed here: {key}")
    for key, index, ids in (
        ("reused_requirements", req, "REQ-"),
        ("reused_rrs", rr, "RR-"),
        ("reused_open_gaps", gaps, "GAP-"),
    ):
        known = {row["id"] for row in index["items"]}
        refs = p.get(key, [])
        if not isinstance(refs, list) or len(refs) != len(set(refs)):
            errors.append(f"{key} must be unique list")
            continue
        for ref in refs:
            if not ref.startswith(ids) or ref not in known:
                errors.append(f"{key} references unknown ID {ref}")
    gates = p.get("gates", [])
    if not isinstance(gates, list) or p.get("gates_count") != 18 or len(gates) != 18:
        errors.append("Iteration39 must define exactly eighteen gates")
        gates = []
    gate_ids = [row.get("id") for row in gates if isinstance(row, dict)]
    if gate_ids != [f"I39-{i:02d}" for i in range(1, 19)]:
        errors.append("I39 gate IDs must be exact sequential I39-01..18")
    allowed = {"NOT_IMPLEMENTED", "NOT_RUN", "BLOCKED_BY_NATIVE_CONTRACT"}
    if any(row.get("status") not in allowed for row in gates):
        errors.append("planning-only gate cannot be marked passed or approved")
    if any(not row.get("acceptance") or not row.get("evidence_target")
           or not row.get("owner") or not row.get("work_package") for row in gates):
        errors.append("gate lacks acceptance, evidence target, owner or work package")
    stages = p.get("stages", [])
    if [s.get("id") for s in stages] != ["M0", "M1", "M2", "M3"]:
        errors.append("M0..M3 stages must be ordered and complete")
    for stage in stages:
        if not stage.get("required_gate_ids") or any(g not in gate_ids for g in stage["required_gate_ids"]):
            errors.append(f"{stage.get('id')}: unknown/missing gate reference")
        if stage.get("status") not in ("PLAN_ONLY", "BLOCKED_BY_NATIVE_CONTRACT"):
            errors.append(f"{stage.get('id')}: unauthorized stage promotion")
    if p.get("package_dependencies", {}).get("C04-E3") is None:
        errors.append("missing C04-E3 trusted auth dependencies")
    for name in ("C04-D1", "C04-D2", "C04-D3", "C04-E0", "C04-E1", "C04-E2", "C04-E3", "C04-F0"):
        if name not in doc:
            errors.append(f"handoff document lacks work package {name}")
    for keyword in ("REQ-0009", "RR-0003", "FrameCodecCatalog", "LocalLoginCoordinator",
                    "T01", "NOT_RUN", "GAP-AUTH-0001"):
        if keyword not in doc:
            errors.append(f"handoff document lacks evidence caveat {keyword}")
    return {"errors": sorted(set(errors)),
            "summary": {"gates": len(gates), "stages": len(stages),
                        "source_version": p.get("client_version"),
                        "native_adapter_enabled": p.get("native_adapter_enabled")}}

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--check", action="store_true")
    parser.add_argument("--json", action="store_true")
    parser.add_argument("--root", type=Path, default=ROOT)
    args = parser.parse_args()
    result = evaluate(args.root.resolve())
    if args.json:
        print(json.dumps(result, ensure_ascii=False, indent=2))
    else:
        print("S00 Iteration39:", result["summary"])
        for err in result["errors"]:
            print("ERROR", err)
    if args.check and result["errors"]:
        raise SystemExit(1)

if __name__ == "__main__":
    main()
