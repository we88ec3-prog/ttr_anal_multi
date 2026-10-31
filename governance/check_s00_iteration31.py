#!/usr/bin/env python3
"""Read-only S00 Iteration31 design integrity. Never runs Server/Client gameplay."""
import argparse
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MATRIX = "governance/s00-iterations/S00-ITERATION-31-QUEST-REWARD-CONTRACT.json"
CASES = "governance/s00-iterations/S00-20261031-ITERATION-31-ACCEPTANCE.md"
SOURCES = [
    "governance/s00-iterations/S00-ITERATION-30-OBJECTIVE-SETTLEMENT-CONTRACT.json",
    "governance/s00-iterations/S00-ITERATION-27-C05-DELIVERY-MATRIX.json",
    "governance/s00-iterations/S00-ITERATION-17-TUTORIAL-COMPLETION-GATES.json",
    "governance/s00-iterations/S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json",
]
GATE_IDS = ("E20", "E21", "E22", "E23", "E24", "E26")
PACKAGE_IDS = tuple(f"S31-{i:02d}" for i in range(1, 5))
CASE_IDS = {f"I31-T{i:02d}" for i in range(1, 25)}


def read_json(root, name):
    return json.loads((root / name).read_text(encoding="utf-8"))


def git_blob_sha(data):
    return hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest()


def check(root=ROOT):
    errs = []
    try:
        d = read_json(root, MATRIX)
        sources = [read_json(root, p) for p in SOURCES]
        blobs = [git_blob_sha((root / p).read_bytes()) for p in SOURCES]
        target = read_json(root, "shared/targets.json")["kr"]["sha256"]
        adrs = {a["id"]: a for a in read_json(root, "design/decisions/index.json")["items"]}
        acceptance = (root / CASES).read_text(encoding="utf-8")
    except (OSError, ValueError, KeyError, TypeError) as ex:
        return [f"Missing/unreadable Iteration31 prerequisite: {ex}"]
    if d.get("schema") != "s00-iteration31-quest-reward-ledger-v1" or d.get("kind") != "NON_NORMATIVE_DOMAIN_DESIGN":
        errs.append("Invalid non-normative S31 schema")
    if d.get("client_build") != "kr" or d.get("client_sha256") != target:
        errs.append("KR Client source identity mismatch")
    records = d.get("source_blobs")
    if not isinstance(records, list) or len(records) != 4:
        errs.append("Exactly four source Git blob records required")
    else:
        for record, path, sha in zip(records, SOURCES, blobs):
            if not isinstance(record, dict) or record.get("path") != path or record.get("git_blob_sha") != sha:
                errs.append(f"Source Git blob mismatch: {path}")
    if len(sources[0].get("packages", [])) != 4 or sources[0].get("kind") != "NON_NORMATIVE_DOMAIN_DESIGN":
        errs.append("S30 upstream is no longer the four-pack proposed plan")
    old = {x.get("id"): x for x in sources[1].get("packages", [])}
    if any(old.get(id_, {}).get("mode") != "DOMAIN_OFFLINE_PROTOTYPE" for id_ in ("S27-W06", "S27-W07")):
        errs.append("S27 W06/W07 proposed original workstream missing")
    if d.get("parents") != ["S27-W06", "S27-W07"] or d.get("predecessors") != ["S30-03", "S30-04"]:
        errs.append("Quest/Reward dependencies or upstream scope changed")
    if d.get("following_work") != "S27-W08_TUTORIAL_TERMINAL_AND_WORLD_EXIT_SEPARATE":
        errs.append("Quest state cannot claim tutorial/world completion")
    gates = {g["id"]: g for g in sources[2].get("gates", [])}
    overlay = {g["id"]: g for g in sources[3].get("gates", [])}
    snapshots = d.get("original_gates_snapshot")
    if not isinstance(snapshots, list) or tuple(x.get("id") for x in snapshots if isinstance(x, dict)) != GATE_IDS:
        errs.append("Six source-pinned native E20-E24/E26 gates required")
    else:
        for x in snapshots:
            g, o = gates.get(x["id"], {}), overlay.get(x["id"], {})
            if (x.get("evidence_state") != g.get("evidence_state")
                    or x.get("blocking_unknown") != g.get("blocking_unknown")
                    or x.get("owner_tasks") != g.get("owner_tasks")
                    or x.get("official_status") != "PLAN_ONLY" or x.get("executed") is not False
                    or o.get("original_evidence_state") != g.get("evidence_state")
                    or o.get("source_blocker") != g.get("blocking_unknown")):
                errs.append(f"{x['id']}: original gate evidence/owner/status promoted")
    srv = d.get("server_snapshot", {})
    if srv.get("repo") != "we88ec3-prog/ttr_server_roy" or not re.fullmatch("[0-9a-f]{40}", str(srv.get("main_sha", ""))):
        errs.append("Independent Server snapshot provenance invalid")
    if srv.get("ci_rechecks_remote") is not False or srv.get("ci_conclusion") != "SUCCESS_OFFLINE_ONLY":
        errs.append("Remote Server CI falsely represented as native proof")
    if srv.get("latest_capabilities") != "C00_OPS_SQLITE_MAINTENANCE_AND_C02D_ADMIN_C03_OFFLINE_C04_PARTIAL_C05_NOT_IMPLEMENTED":
        errs.append("Server C05 incorrectly represented as implemented")
    anchors = srv.get("anchors", [])
    required = {"src/Tartaros.Persistence/SqliteLocalDatabase.cs",
                "src/Tartaros.Persistence/PostgresCharacterActions.cs",
                "docs/OPS-LOCAL-SQLITE.md", "contracts/spec-revision.json"}
    if not isinstance(anchors, list) or len(anchors) != 8:
        errs.append("Eight observed independent Server file blobs required")
        anchors = []
    paths = []
    for entry in anchors:
        if not isinstance(entry, dict):
            errs.append("Malformed Server blob record")
            continue
        p, s = entry.get("path"), entry.get("git_blob_sha")
        paths.append(p)
        if (not isinstance(p, str) or not p.startswith(("src/", "docs/", "contracts/"))
                or ".." in p.split("/") or not re.fullmatch("[0-9a-f]{40}", str(s))):
            errs.append("Unsafe/malformed Server blob record")
    if len(paths) != len(set(paths)) or not required.issubset(set(paths)):
        errs.append("Real Server source anchors missing/duplicated")
    policy = d.get("policy", {})
    if policy.get("mode") != "SERVER_MOCK_ONLY" or policy.get("adr_status") != "PROPOSED_NOT_APPROVED":
        errs.append("Proposal incorrectly promoted to official native policy")
    for k in ("original_client_executed", "server_c05_implemented", "domain_tests_executed",
              "native_adapter_enabled", "original_server_trace_verified", "formal_registry_promoted",
              "source_evidence_upgraded"):
        if policy.get(k) is not False:
            errs.append(f"Forbidden native/completion claim: {k}")
    for id_ in ("ADR-0006", "ADR-0007"):
        a = adrs.get(id_, {})
        if id_ not in policy.get("adr_ids", []) or a.get("status") != "PROPOSED" or a.get("normative") is not False:
            errs.append(f"{id_} must remain PROPOSED/NON-NORMATIVE")
    states = d.get("states", {})
    if (states.get("separation") != "Scenario14 SUCCEEDED != Quest14 TURNED_IN != Quest16 TURNED_IN != Quest15 AVAILABLE != TutorialCompleted != WorldReady"
            or states.get("example_policy_only") is not True):
        errs.append("Quest/Scenario/Tutorial/World separation violated")
    if not {"AVAILABLE", "ACCEPTED", "COMPLETED", "TURNED_IN"}.issubset(set(states.get("quest_states", []))):
        errs.append("Quest available/accepted/completed/turned-in must be distinct")
    migration = d.get("migration", {})
    if (migration.get("sqlite_base_version") != 2 or migration.get("postgres_base_migration") != 3
        or migration.get("revision_allocation") != "CENTRAL_SEQUENCER_REQUIRED_AFTER_EARLIER_C05_MIGRATIONS"
        or migration.get("sqlite_next_number") != "UNALLOCATED_NOT_APPLIED"
        or migration.get("postgres_next_number") != "UNALLOCATED_NOT_APPLIED"):
        errs.append("Provider migration versions must be centrally allocated and unapplied")
    if len(migration.get("proposed_tables", [])) != 6 or len(set(migration["proposed_tables"])) != 6:
        errs.append("Six unique mock quest/reward tables required")
    if "NOT_VERIFIED" not in migration.get("provider_policy", ""):
        errs.append("PostgreSQL ban policy not independently verified")
    items = d.get("packages")
    if not isinstance(items, list):
        return errs + ["Missing packages"]
    ids = [x.get("id") for x in items if isinstance(x, dict)]
    if tuple(ids) != PACKAGE_IDS:
        errs.append("Expected S31-01..04 in exact order")
    found = re.findall(r"^\|\s*(I31-T\d{2})\s*\|", acceptance, re.M)
    if len(found) != 24 or set(found) != CASE_IDS or "PLAN_ONLY / NOT_RUN" not in acceptance or d.get("expected_case_count") != 24:
        errs.append("Expected 24 unique NOT_RUN I31-T01..24 cases")
    used = []
    graph = {}
    for item in items:
        if not isinstance(item, dict):
            errs.append("Invalid work package")
            continue
        key = item.get("id", "?")
        deps = item.get("depends_on", [])
        if not isinstance(deps, list) or len(deps) != len(set(deps)) or key in deps or not set(deps).issubset(set(PACKAGE_IDS)):
            errs.append(f"{key}: bad dependencies")
            deps = []
        graph[key] = deps
        if item.get("mode") != "PROPOSED_SERVER_MOCK_ONLY" or item.get("parent") not in ("S27-W06", "S27-W07"):
            errs.append(f"{key}: work package may not assert official native policy")
        gates_here = item.get("gate_ids", [])
        if not isinstance(gates_here, list) or not gates_here or not set(gates_here).issubset(set(GATE_IDS)):
            errs.append(f"{key}: unregistered native evidence gate")
        if not isinstance(item.get("interfaces"), list) or not item["interfaces"] or not isinstance(item.get("requirements"), list) or len(item["requirements"]) < 5 or not item.get("native_blocker"):
            errs.append(f"{key}: missing safety requirements/API/native blocker")
        cases = item.get("test_cases", [])
        if not isinstance(cases, list) or len(cases) != 6 or len(set(cases)) != 6:
            errs.append(f"{key}: six cases required")
        else:
            used.extend(cases)
    if len(used) != 24 or len(set(used)) != 24 or set(used) != CASE_IDS:
        errs.append("Every I31 case must belong to exactly one work package")
    active, complete = set(), set()
    def visit(x):
        if x in active:
            errs.append(f"Dependency cycle at {x}")
            return
        if x in complete:
            return
        active.add(x)
        for dep in graph.get(x, []):
            visit(dep)
        active.remove(x)
        complete.add(x)
    for x in graph:
        visit(x)
    for no_go in ("NO_SCENARIO14_SUCCESS_AS_QUEST14_TURNIN", "NO_QUEST16_REWARD_TYPE2_AS_CURRENCY",
                  "NO_QUEST15_AUTO_ACCEPT", "NO_DOUBLE_REWARD", "NO_AUTO_MIGRATION_VERSION_REUSE",
                  "NO_ADR_AUTO_APPROVAL", "NO_TUTORIAL_COMPLETE_FROM_QUEST_ONLY"):
        if no_go not in d.get("prohibitions", []):
            errs.append(f"Missing mandatory no-go: {no_go}")
    return errs


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=ROOT)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    errs = check(args.root)
    for e in errs:
        print("ERROR:", e)
    if errs:
        raise SystemExit(1)
    print("Iteration31: 4 source-linked mock W06/W07 packages, 6 unchanged native gates, 24 NOT_RUN cases PASS.")
    print("This does not run C05 Server code or original KR Client, and does not approve ADRs.")


if __name__ == "__main__":
    main()
