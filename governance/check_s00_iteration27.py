#!/usr/bin/env python3
"""Read-only structural validation of S00 Iteration27 C05 implementation handoff.

DOES NOT test Server code, load original Client/Server, approve ADR or inspect
remote Server repo's current head. External Server file blobs are pinned
snapshots and must be rechecked manually when taking up a work package.
"""
import argparse
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PLAN = "governance/s00-iterations/S00-ITERATION-27-C05-DELIVERY-MATRIX.json"
CASES = "governance/s00-iterations/S00-20261031-ITERATION-27-C05-ACCEPTANCE.md"
SOURCE = "governance/s00-iterations/S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json"
EXPECTED_IDS = tuple(f"S27-W{i:02d}" for i in range(1, 10))


def _read(root, path):
    return json.loads((root / path).read_text(encoding="utf-8"))


def _git_blob_sha(data: bytes):
    return hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest()


def validate(root=ROOT):
    errors = []
    try:
        doc = _read(root, PLAN)
        source = _read(root, SOURCE)
        targets = _read(root, "shared/targets.json")
        adrs = {x["id"]: x for x in _read(root, "design/decisions/index.json")["items"]}
        acceptance = (root / CASES).read_text(encoding="utf-8")
    except (KeyError, ValueError, OSError, TypeError) as exc:
        return [f"unreadable Iteration27 prerequisites: {exc}"]
    if doc.get("schema") != "s00-iteration27-c05-implementation-handoff-v1":
        errors.append("schema mismatch")
    if doc.get("kind") != "NON_NORMATIVE_PLANNING_OVERLAY":
        errors.append("must remain non-normative")
    if doc.get("client_build") != "kr" or doc.get("client_sha256") != targets["kr"]["sha256"]:
        errors.append("KR client target identity mismatch")
    if doc.get("source_matrix", {}).get("path") != SOURCE:
        errors.append("wrong upstream Iteration26 gate path")
    if doc.get("source_matrix", {}).get("git_blob_sha") != _git_blob_sha((root / SOURCE).read_bytes()):
        errors.append("source-matrix Git blob changed without review")
    if source.get("kind") != "NON_NORMATIVE_PLANNING_OVERLAY" or len(source.get("gates", [])) != 19:
        errors.append("upstream must remain 19 draft gates")
    known_gate_ids = {g["id"] for g in source["gates"]}
    snap = doc.get("server_snapshot", {})
    if snap.get("repository") != "we88ec3-prog/ttr_server_roy":
        errors.append("Server repository reference mismatch")
    if not re.fullmatch(r"[0-9a-f]{40}", str(snap.get("commit", ""))):
        errors.append("Server snapshot commit invalid")
    if snap.get("source_access") != "READ_ONLY_GITHUB_SNAPSHOT_NOT_CI_REMOTE_VALIDATED":
        errors.append("must not claim remote Server snapshot continuously reverified by CI")
    anchors = snap.get("file_blobs")
    if not isinstance(anchors, list) or len(anchors) < 5:
        errors.append("missing observed Server file anchor provenance")
        anchors = []
    paths = [a.get("path") for a in anchors if isinstance(a, dict)]
    if len(paths) != len(set(paths)):
        errors.append("duplicate Server snapshot file anchor")
    for a in anchors:
        if (not isinstance(a, dict) or not isinstance(a.get("path"), str)
                or not a["path"].startswith(("src/", "contracts/", "docs/"))
                or ".." in a["path"].split("/")
                or not re.fullmatch(r"[0-9a-f]{40}", str(a.get("blob_sha", "")))):
            errors.append("unsafe/missing Server blob reference")
    statuses = doc.get("observed_server_state", {})
    if statuses.get("C03") != "VERIFIED_OFFLINE_CHARACTER_AND_SELECTION":
        errors.append("C03 verified offline seam missing")
    if statuses.get("C04") != "SOURCE_BOUNDED_OFFLINE_ONLY" or statuses.get("C05") != "NOT_IMPLEMENTED_EVIDENCE_BLOCKED":
        errors.append("Server C04/C05 evidence baseline was promoted or altered")
    gov = doc.get("governance", {})
    for flag in ("normative", "client_adapter_default_enabled", "implemented_wire_contracts",
                 "original_client_run_authorized", "formal_rr_claim_req_test_changes"):
        if gov.get(flag) is not False:
            errors.append(f"unsafe formal/native flag {flag}")
    if gov.get("required_adr_status") != "PROPOSED" or gov.get("test_status") != "PLAN_ONLY_NOT_RUN":
        errors.append("unapproved ADR or unexecuted tests misrepresented")
    if gov.get("phase_c_status") != "EXTERNAL_REVIEW_REQUIRED":
        errors.append("Phase C review not recorded as required")
    for adr_id in ("ADR-0006", "ADR-0007"):
        if adr_id not in gov.get("adr_ids", []) or adrs.get(adr_id, {}).get("status") != "PROPOSED" or adrs[adr_id].get("normative") is not False:
            errors.append(f"{adr_id} is not unapproved PROPOSED")
    packages = doc.get("packages")
    if not isinstance(packages, list):
        return errors + ["packages must be list"]
    ids = [p.get("id") for p in packages if isinstance(p, dict)]
    if tuple(ids) != EXPECTED_IDS or len(packages) != 9:
        errors.append("expected ordered unique 9 S27-W01..W09 packages")
    cases = re.findall(r"^\|\s*(I27-T\d{2})\s*\|", acceptance, re.M)
    if (len(cases) != 18 or len(set(cases)) != 18
            or set(cases) != {f"I27-T{i:02d}" for i in range(1, 19)}
            or "PLAN_ONLY / NOT_RUN" not in acceptance):
        errors.append("expected 18 NOT_RUN I27-T01..T18 cases")
    case_set = set(cases)
    dependencies = {}
    for p in packages:
        if not isinstance(p, dict):
            errors.append("invalid work package object")
            continue
        pid = p.get("id", "?")
        deps = p.get("depends_on", [])
        if not isinstance(deps, list) or len(deps) != len(set(deps)):
            errors.append(f"{pid}: missing/duplicate dependency list")
            deps = []
        if any(d not in EXPECTED_IDS or d == pid for d in deps):
            errors.append(f"{pid}: dependency unknown/self reference")
        dependencies[pid] = deps
        if p.get("mode") not in ("DOMAIN_OFFLINE_PROTOTYPE", "SOURCE_GATED_NO_IMPLEMENTATION"):
            errors.append(f"{pid}: invalid delivery mode")
        if pid == "S27-W09" and p.get("mode") != "SOURCE_GATED_NO_IMPLEMENTATION":
            errors.append(f"{pid}: native adapter quarantine missing")
        if pid != "S27-W09" and p.get("mode") != "DOMAIN_OFFLINE_PROTOTYPE":
            errors.append(f"{pid}: cannot claim Client-native implementation")
        if not isinstance(p.get("existing_gate_ids"), list) or not p["existing_gate_ids"] or not set(p["existing_gate_ids"]).issubset(known_gate_ids):
            errors.append(f"{pid}: unresolved Iteration26 native gate")
        if not isinstance(p.get("synthetic_cases"), list) or len(p["synthetic_cases"]) != 2 or not set(p["synthetic_cases"]).issubset(case_set):
            errors.append(f"{pid}: missing/invalid work package test coverage")
        if not isinstance(p.get("interfaces"), list) or not p["interfaces"]:
            errors.append(f"{pid}: missing proposed interface")
        if not isinstance(p.get("acceptance"), list) or len(p["acceptance"]) < 3 or not p.get("blocked_native"):
            errors.append(f"{pid}: unscoped acceptance/native blocker")
        if any(anchor not in paths for anchor in p.get("existing_server_anchors", [])):
            errors.append(f"{pid}: Server anchor not in observed snapshot")
    all_cases = [c for p in packages if isinstance(p, dict) for c in p.get("synthetic_cases", [])]
    if len(all_cases) != 18 or set(all_cases) != case_set or len(set(all_cases)) != 18:
        errors.append("I27 case coverage not exactly one work package each")
    active, done = set(), set()
    def dfs(node):
        if node in active:
            errors.append(f"dependency cycle at {node}")
            return
        if node in done:
            return
        active.add(node)
        for pred in dependencies.get(node, []):
            dfs(pred)
        active.remove(node)
        done.add(node)
    for key in dependencies:
        dfs(key)
    for name in ("NO_NATIVE_KR_WIRE_ADAPTER", "NO_NORMATIVE_ADR_PROMOTION", "NO_ORIGINAL_CLIENT_RUN"):
        if name not in doc.get("global_no_go", []):
            errors.append(f"missing no-go rule {name}")
    return errors


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=ROOT)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    errors = validate(args.root)
    for err in errors:
        print("ERROR", err)
    if errors:
        raise SystemExit(1)
    print("Iteration27: 9 source-linked proposed Server C05 work packages, 18 NOT_RUN tests, native adapter OFF.")
    print("Server repo blob refs are historical read-only GitHub observations; current Server state NOT revalidated by this check.")


if __name__ == "__main__":
    main()
