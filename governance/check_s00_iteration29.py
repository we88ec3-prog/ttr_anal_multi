#!/usr/bin/env python3
"""Read-only Iteration29 plan guard, NOT a gameplay/native Client test."""
import argparse
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MATRIX = "governance/s00-iterations/S00-ITERATION-29-C05-COMBAT-CONTRACT.json"
CASES = "governance/s00-iterations/S00-20261031-ITERATION-29-COMBAT-ACCEPTANCE.md"
PARENTS = [
    "governance/s00-iterations/S00-ITERATION-28-C05-W01-W03-CONTRACT.json",
    "governance/s00-iterations/S00-ITERATION-27-C05-DELIVERY-MATRIX.json",
    "governance/s00-iterations/S00-ITERATION-18-TUTORIAL-COMBAT-GATES.json",
    "governance/s00-iterations/S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json",
]
EXPECTED_PACKAGES = [f"S29-{i:02d}" for i in range(1, 5)]
EXPECTED_CASES = {f"I29-T{i:02d}" for i in range(1, 25)}
EXPECTED_GATES = {"E17-E", "E17-F", "E17-G"}


def _read(root, file):
    return json.loads((root / file).read_text(encoding="utf-8"))


def _blob(data):
    return hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest()


def validate(root=ROOT):
    errors = []
    try:
        data = _read(root, MATRIX)
        previous = [_read(root, p) for p in PARENTS]
        raw = [(root / p).read_bytes() for p in PARENTS]
        adr = {a["id"]: a for a in _read(root, "design/decisions/index.json")["items"]}
        target = _read(root, "shared/targets.json")["kr"]["sha256"]
        cases_text = (root / CASES).read_text(encoding="utf-8")
    except (OSError, TypeError, ValueError, KeyError) as exc:
        return [f"cannot read Iteration29 prerequisites: {exc}"]
    if data.get("schema") != "s00-iteration29-c05-combat-domain-v1" or data.get("kind") != "NON_NORMATIVE_DOMAIN_DESIGN":
        errors.append("Invalid non-normative Iteration29 schema")
    if data.get("client_build") != "kr" or data.get("client_sha256") != target:
        errors.append("Original Client identity altered")
    sources = data.get("source_files")
    if not isinstance(sources, list) or len(sources) != len(PARENTS):
        errors.append("Four source-pin records required")
    else:
        for source, path, original in zip(sources, PARENTS, raw):
            if source.get("path") != path or source.get("git_blob_sha") != _blob(original):
                errors.append(f"Upstream source Git blob altered: {path}")
    if previous[0].get("kind") != "NON_NORMATIVE_DOMAIN_DESIGN" or len(previous[0].get("packages", [])) != 3:
        errors.append("Iteration28 W01-W03 not source-valid")
    previous_w04 = next((x for x in previous[1].get("packages", []) if x.get("id")=="S27-W04"), None)
    if not previous_w04 or set(previous_w04.get("existing_gate_ids", [])) != EXPECTED_GATES:
        errors.append("Missing original S27-W04 E17-E/F/G scope")
    original = {x["id"]: x for x in previous[2].get("gates", [])}
    overlay = {x["id"]: x for x in previous[3].get("gates", [])}
    expected_states = data.get("gate_evidence_snapshot")
    if not isinstance(expected_states, list) or {x.get("gate_id") for x in expected_states} != EXPECTED_GATES:
        errors.append("Expected E17-E/F/G native evidence snapshot")
    else:
        for snap in expected_states:
            gid = snap["gate_id"]
            src = original.get(gid, {})
            over = overlay.get(gid, {})
            if (snap.get("source_evidence_state") != src.get("evidence_state")
                or snap.get("source_blocking_unknown") != src.get("blocking_unknown")
                or snap.get("native_compatibility_confirmed") is not False
                or over.get("original_evidence_state") != src.get("evidence_state")
                or snap.get("owners") != src.get("owners")):
                errors.append(f"{gid}: native evidence/blocker/owner promoted or misrepresented")
    server = data.get("server_snapshot", {})
    if server.get("repo") != "we88ec3-prog/ttr_server_roy" or not re.fullmatch(r"[0-9a-f]{40}", str(server.get("main_sha", ""))):
        errors.append("Incorrect independent Server snapshot")
    if server.get("ci_checks_source_snapshot_against_remote") is not False:
        errors.append("S00 CI cannot claim remote Server revalidation")
    if server.get("status") != "C02_D_LOCAL_SQLITE_MODERATION_C03_OFFLINE_C04_BOUND_ONLY_C05_NOT_IMPLEMENTED":
        errors.append("C05 Server implementation improperly promoted")
    anchors = server.get("git_blobs", [])
    required_paths = {"src/Tartaros.Persistence/SqliteLocalDatabase.cs",
                      "src/Tartaros.Persistence/SqliteCharacterStore.cs",
                      "src/Tartaros.Session/InMemorySessionRegistry.cs",
                      "docs/C02-D-LOCAL-ACCOUNT-ADMIN.md",
                      "contracts/spec-revision.json"}
    if not isinstance(anchors, list) or len(anchors) < 8:
        errors.append("Eight real independent Server source blob anchors required")
        anchors = []
    paths = []
    for x in anchors:
        if not isinstance(x, dict):
            errors.append("Invalid Server source anchor")
            continue
        path, sha = x.get("path"), x.get("git_blob_sha")
        paths.append(path)
        if (not isinstance(path, str) or not isinstance(sha, str)
                or ".." in path.split("/") or not path.startswith(("src/", "docs/", "contracts/"))
                or not re.fullmatch(r"[0-9a-f]{40}", sha)):
            errors.append("Malformed Server source Git blob anchor")
    if len(paths) != len(set(paths)) or not required_paths.issubset(set(paths)):
        errors.append("Duplicate/missing Server C02-D/C03 source anchors")
    db = data.get("migration_proposal", {})
    if (db.get("sqlite_current_schema_version") != 2 or db.get("sqlite_v1_document_snapshot_superseded") is not True
            or db.get("postgres_current_migration") != 3
            or db.get("sqlite_next") != "PROPOSED_V3_NOT_APPLIED"
            or db.get("postgres_next") != "PROPOSED_V4_NOT_APPLIED"):
        errors.append("SQLite v2 / PostgreSQL 003 and unapplied next migrations must remain accurate")
    if len(db.get("proposed_tables", [])) != 5 or len(set(db["proposed_tables"])) != 5:
        errors.append("Five distinct proposed mock combat tables required")
    model = data.get("domain_model", {})
    if (model.get("client_authority") != "INTENT_ONLY" or model.get("same_transaction_requirement") is not True
            or model.get("damage_authority") != "MOCK_SERVER_RULES_ONLY"
            or model.get("objective_handoff") != "S27-W05_ONLY_VERIFIED_DOMAIN_EVENTS"):
        errors.append("Unapproved combat domain authority promoted")
    governance = data.get("governance", {})
    if governance.get("adr_status") != "PROPOSED_NOT_APPROVED":
        errors.append("ADR status must stay PROPOSED")
    for flag in ("server_implementation_executed", "domain_test_executed", "original_client_executed",
                 "original_server_trace", "native_compatibility_confirmed", "native_adapter_enabled",
                 "policy_approved", "formal_registers_modified"):
        if governance.get(flag) is not False:
            errors.append(f"Forbidden completion/native assertion: {flag}")
    for id_ in ("ADR-0006", "ADR-0007"):
        if (id_ not in governance.get("adr_ids", []) or adr.get(id_, {}).get("status") != "PROPOSED"
                or adr.get(id_, {}).get("normative") is not False):
            errors.append(f"{id_} must remain PROPOSED/NON-NORMATIVE")
    packages = data.get("work_packages")
    if not isinstance(packages, list):
        return errors + ["work_packages must be list"]
    ids = [p.get("id") for p in packages if isinstance(p, dict)]
    if ids != EXPECTED_PACKAGES:
        errors.append("Expected S29-01..04 in exact order")
    found_cases = re.findall(r"^\|\s*(I29-T\d{2})\s*\|", cases_text, re.M)
    if (len(found_cases) != 24 or set(found_cases) != EXPECTED_CASES
            or data.get("expected_case_count") != 24 or "PLAN_ONLY / NOT_RUN" not in cases_text):
        errors.append("Expected 24 NOT_RUN I29-T01..T24 cases")
    assigned = []
    dep_graph = {}
    for item in packages:
        if not isinstance(item, dict):
            errors.append("Invalid work package")
            continue
        pid = item.get("id", "?")
        deps = item.get("depends_on")
        if not isinstance(deps, list) or len(set(deps)) != len(deps) or pid in deps or not set(deps).issubset(set(EXPECTED_PACKAGES)):
            errors.append(f"{pid}: unknown or duplicate work dependencies")
            deps = []
        dep_graph[pid] = deps
        if item.get("parent_id") != "S27-W04" or item.get("mode") != "DOMAIN_MOCK_PROPOSED":
            errors.append(f"{pid}: non-mock/unknown W04 parent")
        gate_ids = item.get("gate_ids", [])
        if not isinstance(gate_ids, list) or not gate_ids or not set(gate_ids).issubset(EXPECTED_GATES):
            errors.append(f"{pid}: unregistered native gate")
        if (not isinstance(item.get("interfaces"), list) or not item["interfaces"]
                or not isinstance(item.get("acceptance"), list) or len(item["acceptance"]) < 5
                or not item.get("native_evidence_required")):
            errors.append(f"{pid}: missing API, policy invariant or native blocker")
        tests = item.get("tests", [])
        if not isinstance(tests, list) or len(tests) != 6 or len(set(tests)) != 6:
            errors.append(f"{pid}: expected six distinct cases")
        else:
            assigned.extend(tests)
    if len(assigned) != 24 or set(assigned) != EXPECTED_CASES or len(set(assigned)) != 24:
        errors.append("I29 cases not one-to-one linked to work packages")
    visiting, visited = set(), set()
    def check_cycle(key):
        if key in visiting:
            errors.append(f"Work dependency cycle: {key}")
            return
        if key in visited:
            return
        visiting.add(key)
        for dep in dep_graph.get(key, []):
            check_cycle(dep)
        visiting.remove(key)
        visited.add(key)
    for key in dep_graph:
        check_cycle(key)
    for need in ("NO_CLIENT_REPORTED_DAMAGE_OR_VICTORY","NO_STALE_LEASE_HIT",
                 "NO_AUTOMATIC_QUEST_OR_SCENARIO_TERMINAL","NO_ADR_AUTO_APPROVAL",
                 "NO_REMOTE_SERVER_REVALIDATION_BY_S00_CI"):
        if need not in data.get("no_go", []):
            errors.append(f"Missing required no-go: {need}")
    return errors


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=ROOT)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    errors = validate(args.root)
    for error in errors:
        print("ERROR", error)
    if errors:
        raise SystemExit(1)
    print("S00 Iteration29: 4 mock-domain packages, 24 NOT_RUN planned cases, 3 original native gates; integrity OK.")
    print("No Server build/runtime, no original Client compatibility, and no ADR approval are implied.")


if __name__ == "__main__":
    main()
