#!/usr/bin/env python3
"""Structural checks for S00 Iteration30: never prove original Client or Server gameplay."""
import argparse
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MATRIX = "governance/s00-iterations/S00-ITERATION-30-OBJECTIVE-SETTLEMENT-CONTRACT.json"
CASES = "governance/s00-iterations/S00-20261031-ITERATION-30-ACCEPTANCE.md"
PARENTS = [
    "governance/s00-iterations/S00-ITERATION-29-C05-COMBAT-CONTRACT.json",
    "governance/s00-iterations/S00-ITERATION-27-C05-DELIVERY-MATRIX.json",
    "governance/s00-iterations/S00-ITERATION-18-TUTORIAL-COMBAT-GATES.json",
    "governance/s00-iterations/S00-ITERATION-17-TUTORIAL-COMPLETION-GATES.json",
    "governance/s00-iterations/S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json",
]
GATES = ("E17-G", "E17-H", "E17-I", "E17-J", "E18", "E19", "E20")
WORK = tuple(f"S30-{i:02d}" for i in range(1, 5))
TESTS = {f"I30-T{i:02d}" for i in range(1, 25)}


def read(root, p):
    return json.loads((root / p).read_text(encoding="utf-8"))


def sha(data):
    return hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest()


def validate(root=ROOT):
    errors = []
    try:
        doc = read(root, MATRIX)
        parent = [read(root, p) for p in PARENTS]
        parent_blobs = [sha((root / p).read_bytes()) for p in PARENTS]
        targets = read(root, "shared/targets.json")
        decisions = {x["id"]: x for x in read(root, "design/decisions/index.json")["items"]}
        acceptance = (root / CASES).read_text(encoding="utf-8")
    except (ValueError, OSError, TypeError, KeyError) as exc:
        return [f"Cannot load Iteration30 sources: {exc}"]
    if doc.get("schema") != "s00-iteration30-objective-settlement-outbox-v1" or doc.get("kind") != "NON_NORMATIVE_DOMAIN_DESIGN":
        errors.append("Iteration30 non-normative schema mismatch")
    if doc.get("client_build") != "kr" or doc.get("client_sha256") != targets["kr"]["sha256"]:
        errors.append("KR target identity mismatch")
    sources = doc.get("source_blobs")
    if not isinstance(sources, list) or len(sources) != len(PARENTS):
        errors.append("Exactly five source Git blob records required")
    else:
        for got, expected_path, blob_sha in zip(sources, PARENTS, parent_blobs):
            if not isinstance(got, dict) or got.get("path") != expected_path or got.get("git_blob_sha") != blob_sha:
                errors.append(f"Source Git blob mismatch: {expected_path}")
    if len(parent[0].get("work_packages", [])) != 4 or parent[0].get("kind") != "NON_NORMATIVE_DOMAIN_DESIGN":
        errors.append("Iteration29 source contract was changed/promoted")
    w05 = next((x for x in parent[1].get("packages", []) if x.get("id") == "S27-W05"), None)
    if not w05 or set(w05.get("existing_gate_ids", [])) != {"E17-H", "E17-I", "E18", "E19"}:
        errors.append("Expected S27-W05 exact original gate scope")
    original = {x["id"]: x for d in (parent[2], parent[3]) for x in d.get("gates", [])}
    overlay = {x["id"]: x for x in parent[4].get("gates", [])}
    gate_snaps = doc.get("original_gate_snapshots")
    if not isinstance(gate_snaps, list) or tuple(x.get("id") for x in gate_snaps if isinstance(x, dict)) != GATES:
        errors.append("Seven ordered E17-G..J/E18..20 evidence snapshots required")
    else:
        for x in gate_snaps:
            src = original.get(x["id"], {})
            ov = overlay.get(x["id"], {})
            if (x.get("evidence_state") != src.get("evidence_state")
                    or x.get("blocking_unknown") != src.get("blocking_unknown")
                    or x.get("owners") != (src.get("owners") or src.get("owner_tasks"))
                    or x.get("native_compatibility_confirmed") is not False
                    or ov.get("original_evidence_state") != src.get("evidence_state")
                    or ov.get("source_blocker") != src.get("blocking_unknown")):
                errors.append(f"{x['id']}: original gate evidence/owners/blocker promoted or altered")
    server = doc.get("server_snapshot", {})
    if server.get("repo") != "we88ec3-prog/ttr_server_roy" or not re.fullmatch(r"[0-9a-f]{40}", str(server.get("observed_main", ""))):
        errors.append("Server snapshot missing/malformed")
    if server.get("ci_checks_remote_main") is not False or server.get("ci_conclusion_at_observation") != "IN_PROGRESS_NOT_CLAIMED_SUCCESS":
        errors.append("Server CI cannot be falsely marked verified by S00")
    if server.get("latest_change") != "C00-OPS_SQLITE_MAINTENANCE_ONLY_NO_C05_IMPLEMENTATION":
        errors.append("C00-OPS must not be misreported as C05")
    anchors = server.get("anchors", [])
    required = {"docs/OPS-LOCAL-SQLITE.md", "src/Tartaros.Persistence/SqliteLocalOperations.cs",
                "src/Tartaros.Persistence/SqliteLocalDatabase.cs", "contracts/spec-revision.json"}
    if not isinstance(anchors, list) or len(anchors) < 7:
        errors.append("Seven Server blob references required")
        anchors = []
    paths = []
    for a in anchors:
        if not isinstance(a, dict):
            errors.append("Malformed Server anchor")
            continue
        path, b = a.get("path"), a.get("git_blob_sha")
        paths.append(path)
        if (not isinstance(path, str) or not path.startswith(("src/", "docs/", "contracts/"))
                or ".." in path.split("/") or not re.fullmatch("[0-9a-f]{40}", str(b))):
            errors.append("Malformed Server blob SHA/path")
    if len(paths) != len(set(paths)) or not required.issubset(set(paths)):
        errors.append("Required real Server OPS/C03 anchors absent/duplicated")
    if doc.get("parent_workstream") != "S27-W05" or doc.get("next_handoff") != "S27-W06_QUEST14_POLICY_SEPARATE":
        errors.append("W05→W06 authority boundary changed")
    if doc.get("required_upstream_workstreams") != ["S28-01", "S28-02", "S28-03", "S29-03", "S29-04"]:
        errors.append("Combat/Encounter upstream dependencies lost")
    p = doc.get("policies", {})
    if p.get("adr_status") != "PROPOSED_NOT_APPROVED" or p.get("mode") != "SERVER_MOCK_ONLY":
        errors.append("Policy must remain proposed mock-only")
    for name in ("original_client_runtime_executed", "original_server_trace_verified",
                 "server_c05_implemented", "domain_tests_executed", "native_adapter_enabled",
                 "formal_rr_clm_req_test_promotion"):
        if p.get(name) is not False:
            errors.append(f"Unearned implementation/native claim: {name}")
    if p.get("ci_does_not_test_remote_server") is not True:
        errors.append("S00 CI cannot claim remote Server tests")
    for id_ in ("ADR-0006", "ADR-0007"):
        a = decisions.get(id_, {})
        if id_ not in p.get("adr_ids", []) or a.get("status") != "PROPOSED" or a.get("normative") is not False:
            errors.append(f"{id_} not PROPOSED/NON_NORMATIVE")
    t = doc.get("transaction_model", {})
    if (t.get("server_owned_only") is not True
            or t.get("sqlite_existing_version") != 2 or t.get("postgres_existing_migrations") != 3
            or t.get("migration_sqlite_next") != "PROPOSED_V3_NOT_APPLIED"
            or t.get("migration_pg_next") != "PROPOSED_V4_NOT_APPLIED"):
        errors.append("Mock-only DB/current provider or proposed migration status changed")
    if (t.get("native_result_adapter") != "DISABLED_UNTIL_SOURCE_PROVEN_AND_SEPARATE_RUNTIME_AUTHORIZATION"
            or t.get("quest_boundary") != "Scenario outcome -> independently reviewed Quest14 eligibility only, not Quest14 completed or turned in"
            or "at-least-once" not in t.get("outbox", "")):
        errors.append("Outbox/native/Quest separation weakened")
    tables = t.get("tables", [])
    if not isinstance(tables, list) or len(set(tables)) != 6 or len(tables) != 6:
        errors.append("Six distinct proposed mock persistence structures required")
    packages = doc.get("packages")
    if not isinstance(packages, list):
        return errors + ["packages missing"]
    if tuple(x.get("id") for x in packages if isinstance(x, dict)) != WORK:
        errors.append("Expected S30-01..04 ordered work packages")
    found = re.findall(r"^\|\s*(I30-T\d{2})\s*\|", acceptance, re.M)
    if len(found) != 24 or set(found) != TESTS or doc.get("expected_case_count") != 24 or "PLAN_ONLY / NOT_RUN" not in acceptance:
        errors.append("Expected 24 unique NOT_RUN cases I30-T01..24")
    assigned = []
    deps = {}
    for x in packages:
        if not isinstance(x, dict):
            errors.append("Invalid package object")
            continue
        key = x.get("id", "?")
        d = x.get("depends_on")
        if not isinstance(d, list) or len(d) != len(set(d)) or key in d or not set(d).issubset(set(WORK)):
            errors.append(f"{key}: missing/invalid work dependency")
            d = []
        deps[key] = d
        if x.get("parent") != "S27-W05" or not x.get("native_missing"):
            errors.append(f"{key}: original W05/native gap missing")
        if not isinstance(x.get("gates"), list) or not x["gates"] or not set(x["gates"]).issubset(set(GATES)):
            errors.append(f"{key}: invalid original native gate reference")
        if (not isinstance(x.get("apis"), list) or not x["apis"]
                or not isinstance(x.get("must"), list) or len(x["must"]) < 5):
            errors.append(f"{key}: incomplete proposed API/invariant")
        own = x.get("cases")
        if not isinstance(own, list) or len(own) != 6 or len(set(own)) != 6:
            errors.append(f"{key}: six planned cases required")
        else:
            assigned.extend(own)
    if len(assigned) != 24 or len(set(assigned)) != 24 or set(assigned) != TESTS:
        errors.append("Case coverage must be one work package per planned case")
    visiting, completed = set(), set()
    def walk(node):
        if node in visiting:
            errors.append(f"Dependency cycle at {node}")
            return
        if node in completed:
            return
        visiting.add(node)
        for dep in deps.get(node, []):
            walk(dep)
        visiting.remove(node)
        completed.add(node)
    for node in deps:
        walk(node)
    for rule in ("NO_CLIENT_REPORTED_KILL_AS_AUTHORITY", "NO_TIMER_BASED_AUTOWIN",
                 "NO_SCENARIO_SUCCESS_EQUALS_QUEST14_COMPLETE", "NO_ADR_AUTO_APPROVAL",
                 "NO_DOUBLE_TERMINAL_OR_REWARD"):
        if rule not in doc.get("prohibitions", []):
            errors.append(f"Mandatory no-go guard absent: {rule}")
    return errors


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=ROOT)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    errors = validate(args.root)
    for error in errors:
        print("ERROR:", error)
    if errors:
        raise SystemExit(1)
    print("Iteration30: 4 source-linked W05 proposals, 7 source gate snapshots, 24 NOT_RUN cases validated.")
    print("Does NOT run Server C05, original Client, or promote original source evidence.")


if __name__ == "__main__":
    main()
