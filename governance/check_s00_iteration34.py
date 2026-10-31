#!/usr/bin/env python3
"""Iteration34: read-only source pinned Server delta and C05 R0/P01 guardrails.

Structural provenance, not an independent Server or original Client test.
"""
import argparse
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MATRIX = "governance/s00-iterations/S00-ITERATION-34-C05-R0-SERVER-DELTA-CONTRACT.json"
CASES = "governance/s00-iterations/S00-20261031-ITERATION-34-ACCEPTANCE.md"
PLAN = "governance/s00-iterations/S00-20261031-ITERATION-34-C05-R0-SERVER-DELTA-PREFLIGHT.md"
SOURCE33 = (
    "governance/s00-iterations/S00-20261031-ITERATION-33-C05-INTEGRATED-DELIVERY-PLAN.md",
    "governance/s00-iterations/S00-ITERATION-33-C05-INTEGRATION-CONTRACT.json",
)
TEST_IDS = tuple(f"I34-T{i:02d}" for i in range(1, 17))
R0_IDS = tuple(f"R0-34-{i:02d}" for i in range(1, 9))
SHA = re.compile(r"^[0-9a-f]{40}$")


def blob(data):
    return hashlib.sha1(b"blob " + str(len(data)).encode() + b"\0" + data).hexdigest()


def read_json(root, path):
    return json.loads((root / path).read_text(encoding="utf-8"))


def validate(root=ROOT):
    errors = []
    try:
        m = read_json(root, MATRIX)
        source33 = read_json(root, SOURCE33[1])
        target = read_json(root, "shared/targets.json")["kr"]["sha256"]
        req = read_json(root, "design/requirements/index.json")
        adr = {x["id"]: x for x in read_json(root, "design/decisions/index.json")["items"]}
        acceptance = (root / CASES).read_text(encoding="utf-8")
        plan = (root / PLAN).read_text(encoding="utf-8")
    except (OSError, KeyError, ValueError, TypeError) as e:
        return ["Iteration34 prerequisites missing: " + str(e)]
    if m.get("schema") != "s00-iteration34-c05-r0-server-delta-v1" or m.get("kind") != "NON_NORMATIVE_PLANNING_OVERLAY":
        errors.append("Iteration34 must remain non-normative")
    if m.get("client_version") != "kr" or m.get("client_sha256") != target:
        errors.append("KR Client source version changed")
    base = m.get("s00_baseline", {})
    if base.get("main_sha") != "e80b06d8cc7160b5624fa057c8635198fee9df29":
        errors.append("S00 Iteration33 baseline identity changed")
    for key, src in zip(("iteration33_plan", "iteration33_contract"), SOURCE33):
        record = base.get(key, {})
        if record.get("path") != src or record.get("git_blob_sha") != blob((root / src).read_bytes()):
            errors.append("Source Git blob mismatch: " + src)
    if source33.get("governance", {}).get("actual_server_c05_implemented") is not False:
        errors.append("Iteration33 native/Server baseline promoted")
    d = m.get("server_delta", {})
    if (d.get("repo") != "we88ec3-prog/ttr_server_roy"
        or d.get("base_sha") != "272079cc69b124870af303d711931ec20bce2229"
        or d.get("head_sha") != "3e0b7e3a8666f363f747dbf68c2fd462a8777b09"
        or d.get("compare_ahead") != 21 or d.get("compare_behind") != 0
        or d.get("changed_paths") != 14):
        errors.append("Fixed actual Server comparison snapshot drifted")
    obs = d.get("observed_paths", [])
    names = [o.get("path") for o in obs if isinstance(o, dict)]
    expected = {
        "docs/DEVELOPMENT-PLAN.md", "docs/WEB-ADMIN-LOCAL.md",
        "src/Tartaros.Admin.Web/Program.cs",
        "src/Tartaros.Admin.Web/AdminDatabasePath.cs",
        "src/Tartaros.Persistence/SqliteWebAdminReader.cs",
        "contracts/spec-revision.json",
        "src/Tartaros.Persistence/SqliteLocalDatabase.cs",
    }
    if len(names) != 7 or set(names) != expected:
        errors.append("Seven Server snapshot source paths required")
    if any(not SHA.fullmatch(str(o.get("git_blob_sha", ""))) for o in obs if isinstance(o, dict)):
        errors.append("Invalid Server source Git blob SHA")
    ci = d.get("ci_results", [])
    if (len(ci) != 4 or len({c.get("run_id") for c in ci if isinstance(c, dict)}) != 4
        or any(c.get("conclusion") != "SUCCESS" or c.get("scope") != "OFFLINE_OR_SOURCE_SCOPED"
               or c.get("url") != f"https://github.com/we88ec3-prog/ttr_server_roy/actions/runs/{c.get('run_id')}"
               for c in ci if isinstance(c, dict))):
        errors.append("Server CI snapshot must be offline-scoped and traceable")
    for key in ("snapshot_only",):
        if d.get(key) is not True:
            errors.append("Server snapshot cannot be represented as live")
    for key in ("ci_live_revalidates_remote", "postgres_web_admin_implemented",
                "remote_ip_cidr_implemented", "game_tcp_exposed_by_web_admin",
                "c05_implemented", "native_client_compatibility_verified"):
        if d.get(key) is not False:
            errors.append("Unearned Server/Client implemented or compatible status: " + key)
    if d.get("web_admin_provider") != "SQLITE_LOCAL_V2_ONLY" or d.get("web_admin_binding") != "127.0.0.1_ONLY" or d.get("implemented_wire_contracts") != []:
        errors.append("WEB Admin scope or native wire invented")
    align = m.get("alignment", [])
    if [a.get("id") for a in align] != ["REQ-0006", "REQ-0007", "REQ-0008"]:
        errors.append("Duplicate or missing REQ reuse")
    if [a.get("observed") for a in align] != ["PARTIAL_LOCAL_ONLY", "OFFLINE_LOCAL_IMPLEMENTED_SCOPE", "OFFLINE_LOCAL_IMPLEMENTED_SCOPE"]:
        errors.append("Admin scope promoted beyond local evidence")
    existing = {x.get("id") for x in req.get("items", [])}
    if not {"REQ-0006", "REQ-0007", "REQ-0008"}.issubset(existing):
        errors.append("Canonical REQ entries not present")
    gates = m.get("r0_preflight", [])
    if tuple(g.get("id") for g in gates) != R0_IDS:
        errors.append("Eight ordered R0 preflight gates required")
    elif any(g.get("blocking") is not True or g.get("state") in ("PASS", "VERIFIED", "APPROVED")
             or not g.get("required_evidence") for g in gates):
        errors.append("R0 preflight silently approved")
    api = m.get("p01_proposed_api", {})
    if (api.get("name") != "IEncounterAdmission.TryReserveAsync"
        or api.get("kind") != "SERVER_DOMAIN_DESIGN_NOT_NATIVE" or api.get("native_wire") is not False
        or api.get("atomic_with_authority_checks") is not True
        or api.get("reservation_initial_state") != "RESERVED"
        or len(set(api.get("input_fields", []))) != 8
        or "RequestFingerprint" not in api.get("input_fields", [])
        or "ConflictFingerprint" not in api.get("results", [])):
        errors.append("P01 cannot bypass atomic authority or native no-go")
    cases = m.get("cases", [])
    if tuple(c.get("id") for c in cases) != TEST_IDS:
        errors.append("Exactly sixteen ordered planned acceptance cases required")
    else:
        for c in cases:
            if (c.get("design_status") != "PLAN_ONLY" or c.get("execution_status") != "NOT_RUN"
                or c.get("evidence_class") != "PLANNED_NOT_EVIDENCE" or not c.get("goal")):
                errors.append("Iteration34 scenario may not claim runtime test success")
            if acceptance.count("| " + c["id"] + " |") != 1:
                errors.append("Acceptance Markdown/JSON mismatch: " + c["id"])
    gov = m.get("governance", {})
    for k in ("client_bin_executed", "original_client_runtime_executed",
              "server_c05_implemented", "server_repo_modified", "formal_req_rr_gap_spec_claim_test_changed",
              "adr_0006_0007_approved", "native_adapter_enabled",
              "release_r0_pass", "release_r1_pass", "server_tests_run_by_s00"):
        if gov.get(k) is not False:
            errors.append("Unearned governance, native or Server completion: " + k)
    if gov.get("next_migrations") != "UNALLOCATED_NOT_APPLIED" or gov.get("main_contract_status") != "DRAFT_PARTIAL":
        errors.append("Unapproved C05 migration or source contract")
    for key in ("ADR-0006", "ADR-0007"):
        if adr.get(key, {}).get("status") != "PROPOSED":
            errors.append(key + " must remain PROPOSED")
    if "C05-P01" not in plan or "Iteration 34" not in plan or "NOT_RUN" not in acceptance:
        errors.append("Plan or acceptance narrative missing")
    return errors


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--check", action="store_true")
    p.add_argument("--json", action="store_true")
    args = p.parse_args()
    errors = validate()
    if args.json:
        print(json.dumps({"ok": not errors, "errors": errors}, ensure_ascii=False, indent=2))
    else:
        print("Iteration34 source-pinned preflight: " + ("PASS" if not errors else "FAIL"))
        for e in errors:
            print("  - " + e)
    return 1 if errors else 0


if __name__ == "__main__":
    raise SystemExit(main())
