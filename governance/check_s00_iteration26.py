#!/usr/bin/env python3
"""Iteration26 static, read-only planning overlay integrity check.

This checker cannot validate original Tartaros Client semantics, Server packet
compatibility, or execute proposed test cases. No registry maturity is changed.
"""
import argparse
import hashlib
import json
import re
from pathlib import Path

PLAN = "governance/s00-iterations/S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json"
CASES = "governance/s00-iterations/S00-20261031-ITERATION-26-ACCEPTANCE.md"
SRC17 = "governance/s00-iterations/S00-ITERATION-17-TUTORIAL-COMPLETION-GATES.json"
SRC18 = "governance/s00-iterations/S00-ITERATION-18-TUTORIAL-COMBAT-GATES.json"
EXPECTED_GATES = tuple([f"E17-{chr(65+i)}" for i in range(10)] +
                       [f"E{i}" for i in range(18, 27)])


def _load(root, rel):
    return json.loads((root / rel).read_text(encoding="utf-8"))


def _blob_sha(data):
    prefix = b"blob " + str(len(data)).encode("ascii") + b"\0"
    return hashlib.sha1(prefix + data).hexdigest()


def validate(root: Path):
    """Return errors (empty means structural plan consistency, NOT native proof)."""
    issues = []
    try:
        plan = _load(root, PLAN)
        src17 = _load(root, SRC17)
        src18 = _load(root, SRC18)
        targets = _load(root, "shared/targets.json")
        rr = {x["id"] for x in _load(root, "research/requests/index.json")["items"]}
        gaps = {x["id"] for x in _load(root, "design/gaps/index.json")["items"]}
        specs = {x["id"] for x in _load(root, "spec/spec-index.json")["items"]}
    except (OSError, ValueError, KeyError, TypeError) as exc:
        return [f"cannot load source/registry: {exc}"]
    if plan.get("schema") != "s00-iteration26-encounter-quest-exit-overlay-v1":
        issues.append("invalid overlay schema")
    if plan.get("kind") != "NON_NORMATIVE_PLANNING_OVERLAY":
        issues.append("overlay must remain NON_NORMATIVE")
    if plan.get("client_version") != "kr" or plan.get("client_sha256") != targets["kr"]["sha256"]:
        issues.append("Client version/SHA mismatch")
    sources = {SRC17: src17, SRC18: src18}
    for path in sources:
        data = (root / path).read_bytes()
        if plan.get("source_gate_blobs", {}).get(path) != _blob_sha(data):
            issues.append(f"source Git blob SHA mismatch: {path}")
    authoritative = {path: {g["id"]: g for g in obj["gates"]}
                     for path, obj in sources.items()}
    rows = plan.get("gates")
    if not isinstance(rows, list):
        return issues + ["gates must be array"]
    if tuple(g.get("id") for g in rows if isinstance(g, dict)) != EXPECTED_GATES:
        issues.append("expected 19 unique E17-A..J/E18..E26 gates in canonical order")
    if plan.get("validation", {}).get("expected_gate_count") != 19:
        issues.append("expected_gate_count must equal 19")
    for field in ("formal_rr_modified", "formal_claim_modified", "original_binary_rerun",
                  "original_client_runtime_authorized"):
        if plan.get("validation", {}).get(field) is not False:
            issues.append(f"{field} cannot be represented as completed in a planning overlay")
    ids = {g.get("id") for g in rows if isinstance(g, dict)}
    for gate in rows:
        if not isinstance(gate, dict):
            issues.append("gate is not an object")
            continue
        gid = gate.get("id", "?")
        src_path = gate.get("source_gate_file")
        source = authoritative.get(src_path, {}).get(gid)
        if source is None:
            issues.append(f"{gid}: source gate missing or source file mismatch")
        else:
            if gate.get("original_evidence_state") != source.get("evidence_state"):
                issues.append(f"{gid}: source evidence state altered/promoted")
            if gate.get("source_blocker") != source.get("blocking_unknown"):
                issues.append(f"{gid}: original source blocker altered")
        if gate.get("policy_status") != "PROPOSED_NON_NORMATIVE":
            issues.append(f"{gid}: Server policy not explicitly PROPOSED")
        if gate.get("handoff") != "SERVER_DOMAIN_MOCK_FIRST_NATIVE_ADAPTER_OFF":
            issues.append(f"{gid}: original Client adapter must remain OFF")
        for f in ("native_compatibility_confirmed", "original_client_runtime_executed",
                  "domain_test_executed"):
            if gate.get(f) is not False:
                issues.append(f"{gid}: cannot claim executed/compatible in plan: {f}")
        for key, allowed in (("existing_rr_refs", rr), ("existing_gap_refs", gaps),
                             ("existing_spec_refs", specs)):
            arr = gate.get(key)
            if not isinstance(arr, list) or len(arr) != len(set(arr)):
                issues.append(f"{gid}: invalid/duplicate {key}")
            elif not set(arr).issubset(allowed):
                issues.append(f"{gid}: unresolved {key}: {sorted(set(arr)-allowed)}")
        if not isinstance(gate.get("research_owners"), list) or not gate["research_owners"]:
            issues.append(f"{gid}: missing research owners")
        if not gate.get("proposed_domain_action") or not gate.get("required_native_proof"):
            issues.append(f"{gid}: missing proposed action or native unblock evidence")
        deps = gate.get("planning_dependencies")
        if not isinstance(deps, list) or not deps or not set(deps).issubset(ids | {"E16"}):
            issues.append(f"{gid}: invalid planning dependency")
    # Planning dependencies are proposals, never official packet causality.
    edges = {g["id"]: [x for x in g.get("planning_dependencies", []) if x in ids]
             for g in rows if isinstance(g, dict) and g.get("id")}
    visiting, done = set(), set()
    def walk(node):
        if node in visiting:
            issues.append(f"planning dependency cycle at {node}")
            return
        if node in done:
            return
        visiting.add(node)
        for prev in edges.get(node, []):
            walk(prev)
        visiting.remove(node)
        done.add(node)
    for node in edges:
        walk(node)
    try:
        doc = (root / CASES).read_text(encoding="utf-8")
    except OSError as exc:
        return issues + [f"cannot read planned cases: {exc}"]
    cases = re.findall(r"^\|\s*(I26-T\d{2})\s*\|", doc, re.M)
    if (len(cases) != 18 or len(set(cases)) != 18 or
            set(cases) != {f"I26-T{i:02d}" for i in range(1, 19)} or
            plan.get("validation", {}).get("expected_test_case_count") != 18):
        issues.append("expected 18 unique I26-T01..T18 planned acceptance cases")
    if "PLAN_ONLY / NOT_RUN" not in doc:
        issues.append("acceptance cases cannot be shown as executed")
    return issues


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=Path(__file__).resolve().parents[1])
    parser.add_argument("--check", action="store_true", help="fail on structural error")
    args = parser.parse_args()
    issues = validate(args.root)
    for issue in issues:
        print("ERROR", issue)
    if issues:
        raise SystemExit(1)
    print("Iteration26: 19 source-pinned draft gates, 18 NOT_RUN cases, references and evidence fences OK.")
    print("This is NOT original-client runtime/native validation or Server implementation acceptance.")


if __name__ == "__main__":
    main()
