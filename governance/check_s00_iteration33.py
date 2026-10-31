#!/usr/bin/env python3
"""S00 Iteration33: source-pinned 19-PR C05 design DAG checks, not Server gameplay."""
import argparse
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MATRIX = "governance/s00-iterations/S00-ITERATION-33-C05-INTEGRATION-CONTRACT.json"
CASES = "governance/s00-iterations/S00-20261031-ITERATION-33-ACCEPTANCE.md"
SOURCES = [
    "governance/s00-iterations/S00-ITERATION-27-C05-DELIVERY-MATRIX.json",
    "governance/s00-iterations/S00-ITERATION-28-C05-W01-W03-CONTRACT.json",
    "governance/s00-iterations/S00-ITERATION-29-C05-COMBAT-CONTRACT.json",
    "governance/s00-iterations/S00-ITERATION-30-OBJECTIVE-SETTLEMENT-CONTRACT.json",
    "governance/s00-iterations/S00-ITERATION-31-QUEST-REWARD-CONTRACT.json",
    "governance/s00-iterations/S00-ITERATION-32-TUTORIAL-EXIT-RELOG-CONTRACT.json",
    "governance/s00-iterations/S00-ITERATION-17-TUTORIAL-COMPLETION-GATES.json",
    "governance/s00-iterations/S00-ITERATION-18-TUTORIAL-COMBAT-GATES.json",
]
WORK_IDS = tuple(f"C05-P{i:02d}" for i in range(1, 20))
GATE_IDS = ("E17-A", "E17-J", "E23", "E24", "E25", "E26")
TEST_IDS = {f"I33-T{i:02d}" for i in range(1, 25)}
RELEASE_IDS = tuple(f"R{i}" for i in range(7))


def read_json(root, name):
    return json.loads((root / name).read_text(encoding="utf-8"))


def git_blob_sha(data):
    return hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest()


def validate(root=ROOT):
    errors = []
    try:
        model = read_json(root, MATRIX)
        upstream = [read_json(root, p) for p in SOURCES]
        shas = [git_blob_sha((root / p).read_bytes()) for p in SOURCES]
        original = read_json(root, "shared/targets.json")["kr"]["sha256"]
        adrs = {x["id"]: x for x in read_json(root, "design/decisions/index.json")["items"]}
        test_md = (root / CASES).read_text(encoding="utf-8")
    except (KeyError, TypeError, OSError, ValueError) as err:
        return [f"Missing or invalid S33 prerequisites: {err}"]
    if model.get("schema") != "s00-iteration33-c05-integrated-delivery-v1" or model.get("kind") != "NON_NORMATIVE_PLANNING_OVERLAY":
        errors.append("Iteration33 must remain non-normative planning")
    if model.get("client_version") != "kr" or model.get("client_sha256") != original:
        errors.append("Original KR Client source SHA mismatch")
    sources = model.get("source_blobs")
    if not isinstance(sources, list) or len(sources) != len(SOURCES):
        errors.append("Eight source pin records required")
    else:
        for record, path, sha in zip(sources, SOURCES, shas):
            if not isinstance(record, dict) or record.get("path") != path or record.get("git_blob_sha") != sha:
                errors.append(f"Source Git blob mismatch: {path}")
    w = {x["id"]: x for x in upstream[0].get("packages", [])}
    if set(w) != {f"S27-W{i:02d}" for i in range(1, 10)} or w.get("S27-W09", {}).get("mode") != "SOURCE_GATED_NO_IMPLEMENTATION":
        errors.append("Nine original W01-W09 or native quarantine missing")
    sources_by_group = (
        upstream[1].get("packages", []),
        upstream[2].get("work_packages", []),
        upstream[3].get("packages", []),
        upstream[4].get("packages", []),
        upstream[5].get("packages", []),
    )
    expected_ids = [f"S28-{i:02d}" for i in range(1,4)]
    for index, (part, length) in enumerate(zip(sources_by_group, (3,4,4,4,4))):
        group_ids = [x.get("id") for x in part]
        expected = [f"S{28+index}-{i:02d}" for i in range(1,length+1)]
        if group_ids != expected:
            errors.append(f"Iteration{28+index} parent source packages changed")
    if model.get("integration", {}).get("total_prs") != 19:
        errors.append("Exactly 19 C05 mock implementation PRs must be planned")
    gate_src = {g["id"]: g for parent in (upstream[6], upstream[7]) for g in parent.get("gates", [])}
    gate_snapshots = model.get("gate_snapshots")
    if not isinstance(gate_snapshots, list) or tuple(g.get("id") for g in gate_snapshots if isinstance(g, dict)) != GATE_IDS:
        errors.append("Six ordered original native source gate snapshots required")
    else:
        for snap in gate_snapshots:
            gate = gate_src.get(snap["id"], {})
            if (snap.get("evidence_state") != gate.get("evidence_state")
                or snap.get("blocking_unknown") != gate.get("blocking_unknown")
                or snap.get("owners") != (gate.get("owners") or gate.get("owner_tasks"))
                or snap.get("native_compatibility_confirmed") is not False
                or snap.get("original_client_runtime_executed") is not False):
                errors.append(f"{snap['id']}: original gate state/owner/blocker promoted")
    server = model.get("server_snapshot", {})
    if (server.get("repo") != "we88ec3-prog/ttr_server_roy"
        or not re.fullmatch(r"[0-9a-f]{40}", str(server.get("main_sha", "")))
        or server.get("ci_conclusion") != "SUCCESS_OFFLINE_ONLY"
        or server.get("ci_live_revalidates_remote") is not False):
        errors.append("Independent Server snapshot must not claim live/native proof")
    if server.get("state") != "C00_OPS_C02D_C03_OFFLINE_C04_BOUNDED_C05_NOT_IMPLEMENTED":
        errors.append("C05 Server incorrectly represented as implemented")
    anchors = server.get("source_blobs", [])
    required = {"src/Tartaros.Persistence/SqliteLocalDatabase.cs", "src/Tartaros.Persistence/PostgresCharacterActions.cs",
                "docs/OPS-LOCAL-SQLITE.md", "contracts/spec-revision.json", "db/migrations/003_c03_selection.sql"}
    if not isinstance(anchors, list) or len(anchors) != 8:
        errors.append("Eight observed independent Server source blob anchors required")
        anchors = []
    names = []
    for item in anchors:
        if not isinstance(item, dict):
            errors.append("Invalid Server blob anchor")
            continue
        path, sha = item.get("path"), item.get("git_blob_sha")
        names.append(path)
        if (not isinstance(path, str) or not path.startswith(("src/", "docs/", "contracts/", "db/"))
                or ".." in path.split("/") or not re.fullmatch(r"[0-9a-f]{40}", str(sha))):
            errors.append("Malformed independent Server blob anchor")
    if len(names) != len(set(names)) or not required.issubset(set(names)):
        errors.append("Required independent Server source anchors missing")
    plan = model.get("pr_plan")
    if not isinstance(plan, list):
        return errors + ["pr_plan missing"]
    if tuple(p.get("id") for p in plan if isinstance(p, dict)) != WORK_IDS:
        errors.append("PR IDs must exactly be ordered C05-P01..P19")
    expected_source_ids = [*expected_ids]
    for offset, length in ((29,4),(30,4),(31,4),(32,4)):
        expected_source_ids.extend(f"S{offset}-{i:02d}" for i in range(1,length+1))
    if [p.get("source_work_id") for p in plan] != expected_source_ids:
        errors.append("Every C05 PR must map once to the 19 actual prior work packages")
    deps = {}
    mapping = {}
    for item in plan:
        if not isinstance(item, dict):
            errors.append("Invalid PR record")
            continue
        key = item.get("id", "?")
        predecessors = item.get("depends_on", [])
        if (not isinstance(predecessors, list) or len(predecessors) != len(set(predecessors))
            or key in predecessors or not set(predecessors).issubset(set(WORK_IDS))):
            errors.append(f"{key}: invalid, duplicate, or unknown PR dependency")
            predecessors = []
        deps[key] = predecessors
        mapping[key] = item
        if (item.get("implementation_status") != "NOT_STARTED" or item.get("domain_ci") != "NOT_RUN"
            or item.get("native_ci") != "SOURCE_GATED_NOT_RUN" or item.get("native_adapter_enabled") is not False):
            errors.append(f"{key}: unearned Server/native implementation claim")
        if not item.get("scope") or not item.get("acceptance") or item.get("release_slice") not in {"R1","R2","R3","R4","R5"}:
            errors.append(f"{key}: missing release scope/acceptance")
    for i in range(1, 20):
        key = f"C05-P{i:02d}"
        if i > 1 and key in deps and not deps[key]:
            errors.append(f"{key}: missing inter-PR dependency")
    if model.get("integration", {}).get("workpack_order_policy") != "TOPOLOGICAL_WITH_APPROVED_PARALLEL_READ_ONLY_PREP":
        errors.append("Must respect topological workpack order")
    visited, visiting = set(), set()
    def visit(node):
        if node in visiting:
            errors.append(f"C05 dependency cycle at {node}")
            return
        if node in visited:
            return
        visiting.add(node)
        for dep in deps.get(node, []):
            visit(dep)
        visiting.remove(node)
        visited.add(node)
    for k in deps:
        visit(k)
    if model.get("integration", {}).get("no_runtime_timeline_commitment") is not True:
        errors.append("No ungrounded production time commitment")
    release = model.get("release_gates", [])
    if not isinstance(release, list) or tuple(r.get("id") for r in release if isinstance(r,dict)) != RELEASE_IDS:
        errors.append("Seven ordered R0..R6 release gates required")
    else:
        allocated = []
        for gate in release:
            assigned = gate.get("work_ids", [])
            if not isinstance(assigned, list) or len(assigned) != len(set(assigned)):
                errors.append(f"{gate['id']}: invalid release assignment")
                continue
            allocated.extend(assigned)
            if not gate.get("required") or gate.get("status") not in ("PLAN_ONLY", "NOT_RUN", "BLOCKED_BY_EVIDENCE"):
                errors.append(f"{gate['id']}: missing release checks or false pass")
            for ref in assigned:
                if mapping.get(ref, {}).get("release_slice") != gate.get("id"):
                    errors.append(f"{ref}: mismatched release dependency")
        if len(allocated)!=19 or len(set(allocated))!=19 or set(allocated)!=set(WORK_IDS):
            errors.append("Each of 19 PRs must appear in exactly one R1..R5 release")
        if release[0].get("status")!="PLAN_ONLY" or release[-1].get("status")!="BLOCKED_BY_EVIDENCE" or release[-1].get("level")!="NATIVE_COMPATIBILITY_SEPARATE" or release[-1].get("work_ids")!=[]:
            errors.append("R0 and R6 policy/native boundaries cannot be marked passed")
    policies = model.get("policy_decisions", [])
    if (not isinstance(policies,list) or [d.get("id") for d in policies if isinstance(d,dict)] !=
        [f"D33-{i:02d}" for i in range(1,9)]):
        errors.append("Eight explicit D33-01..08 policy decisions required")
    else:
        for d in policies:
            if not d.get("owner") or not d.get("subject") or not d.get("default_if_unresolved") or not d.get("dependencies"):
                errors.append(f"{d['id']}: missing owner/default/dependencies")
    mig = model.get("migration_control", {})
    provider = mig.get("provider_current", {})
    new_versions = mig.get("new_versions", {})
    if (mig.get("db_owner_required") is not True
        or provider.get("sqlite_local_user_version")!=2
        or provider.get("postgres_migrations_applied_through")!=3
        or provider.get("postgres_c02d_suspend_equivalence_verified") is not False
        or new_versions.get("sqlite")!="UNALLOCATED_NOT_APPLIED"
        or new_versions.get("postgres")!="UNALLOCATED_NOT_APPLIED"
        or mig.get("single_allocator")!="SERVER_REPO_C05_SCHEMA_RELEASE_MANIFEST_REQUIRED"
        or len(mig.get("rules", []))<5):
        errors.append("Current DB provider baseline/migration single allocator violated")
    native = model.get("native_admission", {})
    if (native.get("adapter")!="SOURCE_GATED_NO_IMPLEMENTATION"
        or native.get("version_sha_required") is not True
        or native.get("individual_feature_proof_required") is not True
        or native.get("original_client_run_authorization_required") is not True
        or len(native.get("proof_fields",[]))<6):
        errors.append("Native adapter remains source-gated, no original Client runtime")
    state = model.get("governance", {})
    if state.get("adr_state")!="PROPOSED_NOT_APPROVED" or state.get("actual_server_prs_completed")!=0:
        errors.append("No C05 PR/ADR approval may be invented")
    if state.get("no_formal_rr_req_gap_claim_test_promotion") is not True:
        errors.append("Formal evidence registers must remain unpromoted")
    for key in ("actual_server_c05_implemented","domain_gameplay_tests_executed","original_client_runtime_executed",
                "original_server_trace_verified","original_native_compatibility_confirmed","native_adapter_enabled",
                "source_evidence_upgraded"):
        if state.get(key) is not False:
            errors.append(f"Unproven native/Server completion claim: {key}")
    for adr in ("ADR-0006","ADR-0007"):
        if adr not in state.get("adrs",[]) or adrs.get(adr,{}).get("status")!="PROPOSED" or adrs.get(adr,{}).get("normative") is not False:
            errors.append(f"{adr} must remain PROPOSED/NON-NORMATIVE")
    found = re.findall(r"^\|\s*(I33-T\d{2})\s*\|",test_md,re.M)
    if (model.get("expected_acceptance_cases")!=24 or len(found)!=24 or set(found)!=TEST_IDS
        or "PLAN_ONLY／NOT_RUN" not in test_md):
        errors.append("Exactly 24 distinct I33-T01..24 NOT_RUN cases required")
    for guard in ("NO_SERVER_IMPL_CLAIM_FROM_PLAN","NO_AUTOMATIC_ADR_APPROVAL",
                  "NO_NATIVE_CLIENT_READY_FROM_MOCK","NO_QUEST_AUTO_COMPLETION_FROM_SCENARIO",
                  "NO_REWARD_TYPE2_ASSUMPTION","NO_DUPLICATE_C05_MIGRATION_VERSION",
                  "NO_PROVIDER_POLICY_PARITY_ASSUMPTION","NO_ORIGINAL_CLIENT_RUNTIME_WITHOUT_AUTHORIZATION"):
        if guard not in model.get("no_go",[]):
            errors.append(f"Mandatory no-go guard missing: {guard}")
    return errors


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=ROOT)
    parser.add_argument("--check", action="store_true")
    args = parser.parse_args()
    errors = validate(args.root)
    for error in errors:
        print("ERROR:",error)
    if errors:
        raise SystemExit(1)
    print("Iteration33: 19 C05 mock PRs mapped, acyclic, R0..R6, 8 policy decisions, 24 NOT_RUN cases: PASS")
    print("No original Client runtime, no Server C05 implementation, no ADR approval, no remote Server revalidation.")


if __name__=="__main__":
    main()
