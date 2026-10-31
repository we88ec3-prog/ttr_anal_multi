#!/usr/bin/env python3
"""S00 Iteration28 W01-W03 read-only implementation-planning integrity.

Checks source Git blob and local references; never runs original Client or
remote Server, never approves ADR, never treats proposed interface as code.
"""
import argparse
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
PLAN = "governance/s00-iterations/S00-ITERATION-28-C05-W01-W03-CONTRACT.json"
SOURCE = "governance/s00-iterations/S00-ITERATION-27-C05-DELIVERY-MATRIX.json"
CASES = "governance/s00-iterations/S00-20261031-ITERATION-28-W01-W03-ACCEPTANCE.md"
EXPECTED = ("S28-01", "S28-02", "S28-03")
EXPECTED_TESTS = {f"I28-T{i:02d}" for i in range(1, 17)}


def read_json(root, path):
    return json.loads((root / path).read_text(encoding="utf-8"))


def blob(data):
    return hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest()


def assess(root=ROOT):
    errors = []
    try:
        d = read_json(root, PLAN)
        source = read_json(root, SOURCE)
        target = read_json(root, "shared/targets.json")["kr"]["sha256"]
        adrs = {x["id"]: x for x in read_json(root, "design/decisions/index.json")["items"]}
        text = (root / CASES).read_text(encoding="utf-8")
        source_blob = blob((root / SOURCE).read_bytes())
    except (OSError, TypeError, ValueError, KeyError) as exc:
        return [f"source/plan could not load: {exc}"]
    if d.get("schema") != "s00-iteration28-c05-w01-w03-contract-v1" or d.get("kind") != "NON_NORMATIVE_DOMAIN_DESIGN":
        errors.append("Invalid non-normative contract schema")
    if d.get("client_build") != "kr" or d.get("client_sha256") != target:
        errors.append("KR client version/SHA mismatch")
    parent = d.get("parent", {})
    if parent.get("path") != SOURCE or parent.get("git_blob_sha") != source_blob:
        errors.append("Iteration27 source Git blob mismatch")
    if source.get("kind") != "NON_NORMATIVE_PLANNING_OVERLAY" or len(source.get("packages", [])) != 9:
        errors.append("Parent must be nine non-normative work packages")
    if parent.get("work_ids") != ["S27-W01", "S27-W02", "S27-W03"]:
        errors.append("Wrong W01-W03 parent scope")
    upstream = {x["id"]: x for x in source["packages"]}
    server = d.get("server_snapshot", {})
    if server.get("repo") != "we88ec3-prog/ttr_server_roy":
        errors.append("Unexpected Server repo")
    if not re.fullmatch("[0-9a-f]{40}", str(server.get("main_sha", ""))):
        errors.append("Unverifiable Server snapshot SHA")
    if server.get("ci_revalidates_remote_repo") is not False:
        errors.append("CI cannot claim to revalidate remote Server snapshot")
    if server.get("state") != "C03_VERIFIED_OFFLINE_C04_BOUNDED_C05_NOT_IMPLEMENTED":
        errors.append("Server C05 implementation falsely promoted")
    anchors = server.get("git_blobs", [])
    if not isinstance(anchors, list) or len(anchors) < 8:
        errors.append("Eight observed Server blob anchors required")
        anchors = []
    seen = set()
    for x in anchors:
        if not isinstance(x, dict):
            errors.append("Bad Server source anchor")
            continue
        path, sha = x.get("path"), x.get("git_blob_sha")
        if (not isinstance(path, str) or path in seen or ".." in path.split("/")
                or not path.startswith(("src/", "db/", "contracts/"))
                or not re.fullmatch("[0-9a-f]{40}", str(sha))):
            errors.append("Unsafe/duplicate Server blob anchor")
        seen.add(path)
    for required in ("src/Tartaros.Character/IAtomicCharacterActions.cs",
                     "src/Tartaros.Session/ISessionLeaseRegistry.cs",
                     "src/Tartaros.Persistence/SqliteCharacterStore.cs",
                     "src/Tartaros.Persistence/PostgresCharacterActions.cs"):
        if required not in seen:
            errors.append(f"Missing actual Server API anchor: {required}")
    policy = d.get("policy", {})
    if policy.get("status") != "PROPOSED_NOT_APPROVED":
        errors.append("Business ADR approval falsely claimed")
    for name in ("original_client_runtime_authorized", "wire_adapter_enabled",
                 "server_impl_completed", "domain_tests_executed",
                 "formal_registry_promoted", "exactly_once_network_claim"):
        if policy.get(name) is not False:
            errors.append(f"Disallowed completion/native claim: {name}")
    if policy.get("proposed_mock_only") is not True:
        errors.append("Must stay mock-only proposed domain")
    for adr in ("ADR-0006", "ADR-0007"):
        if adr not in policy.get("adr_ids", []) or adrs.get(adr, {}).get("status") != "PROPOSED" or adrs.get(adr, {}).get("normative") is not False:
            errors.append(f"{adr} is not unapproved PROPOSED")
    storage = d.get("storage_proposals", {})
    if (storage.get("sqlite", {}).get("existing_user_version") != 1
            or storage.get("postgresql", {}).get("existing_migration_through") != 3):
        errors.append("Wrong source-observed DB baseline")
    if ("NOT_APPLIED" not in storage.get("sqlite", {}).get("next_version", "")
            or "NOT_APPLIED" not in storage.get("postgresql", {}).get("next_version", "")):
        errors.append("Proposed migrations must remain unapplied")
    tables = storage.get("tables", [])
    if {x.get("name") for x in tables if isinstance(x, dict)} != {"mock_encounter", "mock_actor", "mock_event_dedup"}:
        errors.append("Expected 3 mock-only table proposals")
    packages = d.get("packages")
    if not isinstance(packages, list):
        return errors + ["packages is not a list"]
    ids = [p.get("id") for p in packages if isinstance(p, dict)]
    if tuple(ids) != EXPECTED or len(packages) != 3:
        errors.append("Expected ordered S28-01..03 packages")
    doc_cases = re.findall(r"^\|\s*(I28-T\d{2})\s*\|", text, re.M)
    if (len(doc_cases) != 16 or set(doc_cases) != EXPECTED_TESTS
            or "PLAN_ONLY / NOT_RUN" not in text
            or d.get("expected_case_count") != 16):
        errors.append("Expected 16 distinct NOT_RUN I28 test cases")
    names = {g["id"] for g in source["packages"]}
    native_gates = {g for p in source["packages"] for g in p["existing_gate_ids"]}
    taken = []
    edges = {}
    for p in packages:
        if not isinstance(p, dict):
            errors.append("Bad package")
            continue
        pid = p.get("id", "?")
        deps = p.get("depends_on")
        if not isinstance(deps, list) or len(set(deps)) != len(deps) or any(dep not in EXPECTED or dep == pid for dep in deps):
            errors.append(f"{pid}: invalid dependencies")
            deps = []
        edges[pid] = deps
        if p.get("mode") != "DOMAIN_MOCK_PROPOSED":
            errors.append(f"{pid}: package not explicitly mock-proposed")
        parent_id = p.get("source")
        if parent_id not in names or parent_id != f"S27-W{int(pid.split('-')[1]):02d}":
            errors.append(f"{pid}: incorrect parent package")
        elif not set(p.get("source_native_gates", [])).issubset(set(upstream[parent_id]["existing_gate_ids"])):
            errors.append(f"{pid}: source native gate not linked to parent")
        if not p.get("source_native_gates") or not set(p.get("source_native_gates", [])).issubset(native_gates):
            errors.append(f"{pid}: unknown native gate")
        if not isinstance(p.get("api"), list) or not p["api"]:
            errors.append(f"{pid}: missing proposed API")
        if not isinstance(p.get("invariants"), list) or len(p["invariants"]) < 4:
            errors.append(f"{pid}: missing safety invariants")
        if not p.get("native_blocker"):
            errors.append(f"{pid}: missing original Client blocker")
        cases = p.get("cases")
        if not isinstance(cases, list) or len(cases) < 4 or len(set(cases)) != len(cases):
            errors.append(f"{pid}: invalid case coverage")
        else:
            taken.extend(cases)
    if sorted(taken) != sorted(EXPECTED_TESTS) or len(set(taken)) != len(EXPECTED_TESTS):
        errors.append("I28 cases must be assigned to exactly one package")
    active, done = set(), set()
    def visit(node):
        if node in active:
            errors.append(f"Cycle at {node}")
            return
        if node in done:
            return
        active.add(node)
        for dep in edges.get(node, []):
            visit(dep)
        active.remove(node)
        done.add(node)
    for n in edges:
        visit(n)
    for required in ("NO_CLIENT_WIRE","NO_C03_CHECK_THEN_ACT","NO_MIGRATION_AUTO_APPLY","NO_ADR_AUTO_APPROVAL"):
        if required not in d.get("no_go", []):
            errors.append(f"Missing no-go rule {required}")
    return errors


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument("--root", type=Path, default=ROOT)
    p.add_argument("--check", action="store_true")
    args = p.parse_args()
    errors = assess(args.root)
    for err in errors:
        print("ERROR:", err)
    if errors:
        raise SystemExit(1)
    print("Iteration28: 3 W01-W03 mock domain contracts, source-gate/DB provenance, 16 NOT_RUN tests: PASS")
    print("This does NOT run Server code, original Client, approve ADR or validate remote Server main.")


if __name__ == "__main__":
    main()
