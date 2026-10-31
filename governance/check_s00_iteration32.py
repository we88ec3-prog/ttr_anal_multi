#!/usr/bin/env python3
"""Iteration32 design integrity: read-only check, no Server/Client runtime."""
import argparse
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MATRIX = "governance/s00-iterations/S00-ITERATION-32-TUTORIAL-EXIT-RELOG-CONTRACT.json"
CASES = "governance/s00-iterations/S00-20261031-ITERATION-32-ACCEPTANCE.md"
SOURCES = [
    "governance/s00-iterations/S00-ITERATION-31-QUEST-REWARD-CONTRACT.json",
    "governance/s00-iterations/S00-ITERATION-27-C05-DELIVERY-MATRIX.json",
    "governance/s00-iterations/S00-ITERATION-17-TUTORIAL-COMPLETION-GATES.json",
    "governance/s00-iterations/S00-ITERATION-18-TUTORIAL-COMBAT-GATES.json",
    "governance/s00-iterations/S00-ITERATION-26-ENCOUNTER-QUEST-EXIT-MATRIX.json",
]
GATE_IDS = ("E23", "E24", "E25", "E26", "E17-J")
WORK = tuple(f"S32-{i:02d}" for i in range(1, 5))
TESTS = {f"I32-T{i:02d}" for i in range(1, 25)}


def load(root, path):
    return json.loads((root / path).read_text(encoding="utf-8"))


def blob(data):
    return hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest()


def validate(root=ROOT):
    errors = []
    try:
        doc = load(root, MATRIX)
        parents = [load(root, p) for p in SOURCES]
        shas = [blob((root / p).read_bytes()) for p in SOURCES]
        target = load(root, "shared/targets.json")["kr"]["sha256"]
        adrs = {x["id"]: x for x in load(root, "design/decisions/index.json")["items"]}
        case_text = (root / CASES).read_text(encoding="utf-8")
    except (OSError, ValueError, KeyError, TypeError) as error:
        return [f"Required source unreadable: {error}"]
    if doc.get("schema") != "s00-iteration32-tutorial-exit-relog-v1" or doc.get("kind") != "NON_NORMATIVE_DOMAIN_DESIGN":
        errors.append("Invalid non-normative contract type")
    if doc.get("client_build") != "kr" or doc.get("client_sha256") != target:
        errors.append("KR Client SHA/source identity mismatch")
    ss = doc.get("sources")
    if not isinstance(ss, list) or len(ss) != 5:
        errors.append("Expected five pinned source blobs")
    else:
        for row, p, sha in zip(ss, SOURCES, shas):
            if not isinstance(row, dict) or row.get("path") != p or row.get("git_blob_sha") != sha:
                errors.append(f"Source Git blob mismatch: {p}")
    if len(parents[0].get("packages", [])) != 4 or parents[0].get("kind") != "NON_NORMATIVE_DOMAIN_DESIGN":
        errors.append("Iteration31 proposed four-pack prerequisite missing")
    w08 = next((p for p in parents[1].get("packages", []) if p.get("id") == "S27-W08"), {})
    w09 = next((p for p in parents[1].get("packages", []) if p.get("id") == "S27-W09"), {})
    if w08.get("mode") != "DOMAIN_OFFLINE_PROTOTYPE" or set(w08.get("existing_gate_ids", [])) != {"E23", "E25", "E26", "E17-J"}:
        errors.append("S27-W08 original proposed scope missing or changed")
    if w09.get("mode") != "SOURCE_GATED_NO_IMPLEMENTATION":
        errors.append("S27-W09 native adapter quarantine missing")
    source_gates = {x["id"]: x for parent in parents[2:4] for x in parent.get("gates", [])}
    overlays = {x["id"]: x for x in parents[4].get("gates", [])}
    snapshots = doc.get("original_gates")
    if not isinstance(snapshots, list) or tuple(x.get("id") for x in snapshots if isinstance(x, dict)) != GATE_IDS:
        errors.append("Five ordered source-backed E23-E26/E17-J gates required")
    else:
        for x in snapshots:
            raw, overlay = source_gates.get(x["id"], {}), overlays.get(x["id"], {})
            source_owner = raw.get("owner_tasks") or raw.get("owners")
            if (x.get("evidence_state") != raw.get("evidence_state")
                or x.get("blocking_unknown") != raw.get("blocking_unknown")
                or x.get("owners") != source_owner
                or x.get("official_status") != (raw.get("official_status") or "PLAN_ONLY")
                or x.get("native_compatibility_confirmed") is not False
                or x.get("original_runtime_executed") is not False
                or overlay.get("original_evidence_state") != raw.get("evidence_state")
                or overlay.get("source_blocker") != raw.get("blocking_unknown")):
                errors.append(f"{x['id']}: original source gate evidence/owner/status upgraded")
    server = doc.get("server_snapshot", {})
    if (server.get("repo") != "we88ec3-prog/ttr_server_roy"
            or not re.fullmatch(r"[0-9a-f]{40}", str(server.get("main_sha", "")))
            or server.get("ci_conclusion") != "SUCCESS_OFFLINE_ONLY" or server.get("ci_rechecks_remote") is not False):
        errors.append("Independent Server snapshot cannot mean native verified")
    if server.get("state") != "C00_OPS_C02D_C03_OFFLINE_C04_PARTIAL_C05_NOT_IMPLEMENTED":
        errors.append("Incorrect C05 implementation claim")
    anchors = server.get("anchors", [])
    required = {"src/Tartaros.Session/ISessionLeaseRegistry.cs",
                "src/Tartaros.Persistence/SqliteLocalDatabase.cs",
                "src/Tartaros.Persistence/PostgresCharacterActions.cs",
                "contracts/spec-revision.json"}
    if not isinstance(anchors, list) or len(anchors) != 8:
        errors.append("Eight Server Git blob source anchors required")
        anchors = []
    paths = []
    for a in anchors:
        if not isinstance(a, dict):
            errors.append("Invalid Server anchor")
            continue
        p, h = a.get("path"), a.get("git_blob_sha")
        paths.append(p)
        if (not isinstance(p, str) or not p.startswith(("src/", "docs/", "contracts/"))
                or ".." in p.split("/") or not re.fullmatch("[0-9a-f]{40}", str(h))):
            errors.append("Invalid Server Git blob anchor")
    if len(paths) != len(set(paths)) or not required.issubset(set(paths)):
        errors.append("Missing or duplicate Server source anchors")
    if (doc.get("parent") != "S27-W08"
            or doc.get("dependencies") != ["S31-01","S31-02","S31-03","S31-04"]
            or doc.get("native_adapter_parent") != "S27-W09_SOURCE_GATED_NO_IMPLEMENTATION"):
        errors.append("Tutorial/quest/native dependency separation broken")
    pol = doc.get("policy", {})
    if pol.get("status") != "PROPOSED_NOT_APPROVED" or pol.get("mode") != "SERVER_MOCK_ONLY":
        errors.append("Mock-only policy must remain proposed")
    for flag in ("server_c05_implemented","domain_tests_executed","original_client_runtime_executed",
                 "original_server_trace_verified","original_native_compatibility_confirmed",
                 "native_adapter_enabled","formal_registry_promoted"):
        if pol.get(flag) is not False:
            errors.append(f"Unearned native/Server result: {flag}")
    for name in ("ADR-0006","ADR-0007"):
        a = adrs.get(name, {})
        if name not in pol.get("adr_ids", []) or a.get("status") != "PROPOSED" or a.get("normative") is not False:
            errors.append(f"{name} must be PROPOSED/NON-NORMATIVE")
    dims = doc.get("state_dimensions", {})
    if (dims.get("world_ready_policy") != "MOCK_DOMAIN_ONLY_NOT_ORIGINAL_CLIENT_WORLD_READY"
            or "client observation" not in dims.get("source_of_truth", "")
            or len(dims.get("role_tutorial", [])) != 4
            or len(dims.get("scene_transfer", [])) != 6
            or len(dims.get("native_observation", [])) != 3):
        errors.append("Tutorial/scene/native observation state axes collapsed")
    persistence = doc.get("persistence", {})
    if (persistence.get("sqlite_existing_version") != 2
            or persistence.get("postgres_existing_migration") != 3
            or persistence.get("sqlite_next") != "UNALLOCATED_NOT_APPLIED"
            or persistence.get("postgres_next") != "UNALLOCATED_NOT_APPLIED"
            or persistence.get("migration_policy") != "CENTRAL_C05_REVISION_SEQUENCER_REQUIRED"):
        errors.append("C05 migration sequence or actual provider baseline misrepresented")
    tables = persistence.get("proposed_tables", [])
    if not isinstance(tables, list) or len(tables) != 6 or len(set(tables)) != 6:
        errors.append("Six unique proposed mock persistence tables required")
    if "at-least-once" not in persistence.get("transport_rule", ""):
        errors.append("Outbox delivery must not claim exactly-once network")
    packs = doc.get("packages")
    if not isinstance(packs, list):
        return errors + ["Packages missing"]
    if tuple(x.get("id") for x in packs if isinstance(x, dict)) != WORK:
        errors.append("Expected four ordered S32-01..04 packages")
    found = re.findall(r"^\|\s*(I32-T\d{2})\s*\|", case_text, re.M)
    if len(found) != 24 or set(found) != TESTS or "PLAN_ONLY / NOT_RUN" not in case_text or doc.get("expected_case_count") != 24:
        errors.append("Expected 24 planned NOT_RUN cases I32-T01..24")
    cases = []
    graph = {}
    for p in packs:
        if not isinstance(p, dict):
            errors.append("Invalid work package")
            continue
        pid, deps = p.get("id", "?"), p.get("depends_on", [])
        if not isinstance(deps, list) or len(set(deps)) != len(deps) or pid in deps or not set(deps).issubset(set(WORK)):
            errors.append(f"{pid}: invalid dependencies")
            deps = []
        graph[pid] = deps
        if p.get("parent") != "S27-W08" or p.get("mode") != "SERVER_MOCK_PROPOSED":
            errors.append(f"{pid}: unknown or native implementation mode")
        gs = p.get("gate_ids", [])
        if not isinstance(gs, list) or not gs or not set(gs).issubset(set(GATE_IDS)):
            errors.append(f"{pid}: invalid source gate")
        if (not isinstance(p.get("interfaces"), list) or not p["interfaces"]
                or not isinstance(p.get("invariants"), list) or len(p["invariants"]) < 5
                or not p.get("native_blocker")):
            errors.append(f"{pid}: incomplete safety/implementation contract")
        ts = p.get("cases", [])
        if not isinstance(ts, list) or len(ts) != 6 or len(set(ts)) != 6:
            errors.append(f"{pid}: six unique cases required")
        else:
            cases.extend(ts)
    if len(cases) != 24 or len(set(cases)) != 24 or set(cases) != TESTS:
        errors.append("Every I32 case must belong to exactly one package")
    visited, visiting = set(), set()
    def visit(node):
        if node in visiting:
            errors.append(f"Dependency cycle {node}")
            return
        if node in visited:
            return
        visiting.add(node)
        for d in graph.get(node, []):
            visit(d)
        visiting.remove(node)
        visited.add(node)
    for n in graph:
        visit(n)
    for rule in ("NO_QUEST15_AVAILABLE_EQUALS_TUTORIAL_COMPLETED","NO_SCENE_EXIT_EQUALS_WORLD_READY",
                 "NO_STALE_SESSION_REENTRY","NO_DUPLICATE_REWARD_ON_RELOG",
                 "NO_GUESSED_NATIVE_FIELD_OR_COORDINATES","NO_C05_MIGRATION_VERSION_COLLISION",
                 "NO_ADR_AUTO_APPROVAL","NO_C05_IMPLEMENTATION_FALSE_CLAIM"):
        if rule not in doc.get("no_go", []):
            errors.append(f"Missing no-go: {rule}")
    return errors


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=ROOT)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    errors = validate(args.root)
    for e in errors:
        print("ERROR:", e)
    if errors:
        raise SystemExit(1)
    print("Iteration32: 4 mock W08 packages, 5 source-gate snapshots, 24 NOT_RUN cases: PASS")
    print("This checks planning only; it does NOT test the original KR Client or implement C05.")


if __name__ == "__main__":
    main()
