#!/usr/bin/env python3
"""Iteration36 bounded PG v4 source delta; verifies planning identity, not DB/runtime."""
import argparse
import hashlib
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
MODEL = "governance/s00-iterations/S00-ITERATION-36-POSTGRES-V4-DELTA.json"
REPORT = "governance/s00-iterations/S00-20261031-ITERATION-36-POSTGRES-V4-DELTA.md"
HISTORICAL = "governance/s00-iterations/S00-ITERATION-35-C05-EVIDENCE-INTAKE.json"
T01_REPORT = "research/handoffs/t01-20261031-t16-branch-integration/README.md"
SERVER_FILES = {
    "db/migrations/004_web_admin.sql": "3f32910fd005be4f4f09fb70cd4e068fa9cb5bf7",
    "docs/WEB-ADMIN-POSTGRES.md": "290d81e61ed0cdc8628bcff51de63f735cd1e031",
    "src/Tartaros.Persistence/PostgresAccountAdministration.cs": "e4cb6882c2016605d4aa46cee55acba40bc6285d",
    "src/Tartaros.Persistence/PostgresAdminMigrator.cs": "e3274463ecda272ce42bf206c876d4e2d5e76b1b",
    "src/Tartaros.Persistence/PostgresAdminSchemaVerifier.cs": "6efb8da11d3b1af0d634aec09d0fdd60e505a7ad",
    "src/Tartaros.Persistence/PostgresSessionRegistry.cs": "721441fe3858516638c845ed6ab84b7745ff08da",
    "src/Tartaros.Persistence/PostgresCharacterActions.cs": "19e4853f3e2e0367510637683b185d2f511350cb",
    "tests/Tartaros.DatabaseTests/PostgresWebAdminTests.cs": "8a08be0ba98296c0e318d0d99871739db2308196",
    "src/Tartaros.Admin.Web/WebAdminBackend.cs": "4b92ae53a87ea27cde24eb4aa464a9f13670db79"
}
EXPECTED_CASES = [f"I36-T{i:02d}" for i in range(1,13)]
EXPECTED_RUNS = {41185325497, 41185325522, 41185325525, 41185325530}
SHA = re.compile(r"^[0-9a-f]{40}$")


def git_blob(data):
    return hashlib.sha1(b"blob " + str(len(data)).encode() + b"\0" + data).hexdigest()


def validate(root=ROOT):
    errors = []
    try:
        d = json.loads((root / MODEL).read_text(encoding="utf-8"))
        old = json.loads((root / HISTORICAL).read_text(encoding="utf-8"))
        target = json.loads((root / "shared/targets.json").read_text(encoding="utf-8"))["kr"]["sha256"]
        requirements = json.loads((root / "design/requirements/index.json").read_text(encoding="utf-8"))["items"]
        decisions = json.loads((root / "design/decisions/index.json").read_text(encoding="utf-8"))["items"]
        legacy_checker = (root / "governance/check_s00_iteration35.py").read_text(encoding="utf-8")
        legacy_tests = (root / "governance/tests/test_s00_iteration35.py").read_text(encoding="utf-8")
        report = (root / REPORT).read_text(encoding="utf-8")
    except (OSError, KeyError, ValueError, TypeError) as exc:
        return ["Missing I36 prerequisite: " + str(exc)]
    if d.get("schema") != "s00-iteration36-postgres-v4-delta-v1" or d.get("kind") != "NON_NORMATIVE_SOURCE_SCOPED_DELTA":
        errors.append("Iteration36 must remain source-scoped and non-normative")
    s00 = d.get("s00_base", {})
    if (s00.get("repo") != "we88ec3-prog/ttr_anal_multi"
        or s00.get("main_sha") != "5897c5058a7386686efaeb6173c8ac11bd83c78b"
        or s00.get("iteration35_state_path") != HISTORICAL
        or s00.get("iteration35_state_blob") != git_blob((root / HISTORICAL).read_bytes())):
        errors.append("Iteration35 historical blob or latest S00 baseline mismatch")
    previous = old.get("server_last_observed", {})
    if (previous.get("head_sha") != "3e0b7e3a8666f363f747dbf68c2fd462a8777b09"
        or previous.get("postgres_current_version") != 3
        or any(x.get("state") != "NO_RECEIPT" for x in old.get("slots", []))):
        errors.append("Iteration35 historical snapshot must be preserved")
    server = d.get("server_delta", {})
    if (server.get("repo") != "we88ec3-prog/ttr_server_roy"
        or server.get("base_sha") != previous.get("head_sha")
        or server.get("head_sha") != "68186e8c63187c87f5957d3260574aaad04307d2"
        or server.get("ahead") != 32 or server.get("behind") != 0
        or server.get("changed_files") != 28
        or server.get("server_snapshot_only") is not True or server.get("read_only") is not True):
        errors.append("Source-pinned actual Server diff changed")
    sources = server.get("sources", [])
    if (not isinstance(sources,list) or len(sources) != len(SERVER_FILES)
        or len({x.get("path") for x in sources if isinstance(x,dict)}) != len(SERVER_FILES)
        or any(SERVER_FILES.get(x.get("path")) != x.get("git_blob_sha") for x in sources if isinstance(x,dict))):
        errors.append("Nine exact actual Server source blobs required")
    ci = server.get("ci", [])
    if (not isinstance(ci, list) or {x.get("id") for x in ci if isinstance(x,dict)} != EXPECTED_RUNS
        or len(ci)!=4 or any(x.get("conclusion")!="success" for x in ci if isinstance(x,dict))):
        errors.append("Four bounded Server CI receipts required")
    pg = server.get("postgres_v4", {})
    if (pg.get("migration_path") != "db/migrations/004_web_admin.sql"
        or pg.get("version") != 4 or pg.get("allocated_to") != "WEB_ADMIN_MODERATION"
        or pg.get("present_in_source") is not True
        or pg.get("migration_tested_in_isolated_schema") is not True
        or pg.get("production_db_migrated") != "NOT_OBSERVED"):
        errors.append("Postgres v4 is source allocation, not a production DB observation")
    for k in ("server_owned_account_suspension","server_owned_session_claim_renew_fencing",
              "character_operation_suspension_guard","postgres_web_admin"):
        if pg.get(k) != "SOURCE_BACKED_OFFLINE_TESTED":
            errors.append("PG v4 local source-only test boundary violated: " + k)
    if (pg.get("web_bind") != "127.0.0.1_ONLY"
        or pg.get("web_backup_restore") != "NOT_IMPLEMENTED"
        or pg.get("operator_identity") != "NOT_IMPLEMENTED"
        or pg.get("remote_ip_cidr") != "NOT_IMPLEMENTED"):
        errors.append("Unproven remote or production WEB Admin claim")
    if (server.get("sqlite_local", {}).get("observed_schema_version") != 2
        or server.get("sqlite_local", {}).get("c05_schema") != "NOT_ALLOCATED"):
        errors.append("SQLite C05 schema not allocated")
    c05 = server.get("c05", {})
    if (c05.get("p01") != "NOT_IMPLEMENTED"
        or c05.get("r0_policy") != "NOT_APPROVED"
        or c05.get("r0_pg_new_migration") != "NOT_ALLOCATED"
        or c05.get("postgres_next_candidate_lower_bound") != 5
        or c05.get("postgres_next_version_assigned") is not False
        or c05.get("native_adapter_enabled") is not False
        or c05.get("original_client_tested") is not False):
        errors.append("PG 004 reserved: C05 v5 not allocated or approved")
    revision = server.get("revision35", {})
    if not all(revision.get(k) is True for k in (
        "historical_no_receipt_snapshot_preserved","receipt_is_structural_only")) or (
        revision.get("candidate_validator_pg_new_baseline") != 4
        or revision.get("old_receipt_v3") != "HISTORICAL_SNAPSHOT_ONLY"):
        errors.append("Iteration35 receipt baseline transition not documented")
    if 'baseline = 2 if provider == "SQLITE" else 4' not in legacy_checker:
        errors.append("Iteration35 candidate still accepts stale PG3 migration baseline")
    if 'test_pg_v3_no_longer_valid_for_new_c05' not in legacy_tests:
        errors.append("Iteration35 regression missing PG4 baseline negative")
    t01 = d.get("t01_concurrent_source", {})
    if (t01.get("path") != T01_REPORT
        or t01.get("git_blob_sha") != git_blob((root / T01_REPORT).read_bytes())
        or t01.get("t16_134_src") != "SRC-0590" or t01.get("status") != "REGISTERED"
        or t01.get("native_full_pass") is not False
        or t01.get("quest15_native_compatibility_confirmed") is not False):
        errors.append("T01/T16-134 source intake falsely promoted")
    formal = d.get("formal_registry", {})
    req = {x["id"]:x for x in requirements}
    adr = {x["id"]:x for x in decisions}
    if (formal.get("req_ids") != ["REQ-0006","REQ-0007","REQ-0008"]
        or formal.get("req_status") != "CANDIDATE"
        or any(req.get(i,{}).get("status")!="CANDIDATE" for i in formal.get("req_ids",[]))
        or formal.get("adr_ids") != ["ADR-0004","ADR-0005","ADR-0006","ADR-0007"]
        or formal.get("adr_status") != "PROPOSED"
        or any(adr.get(i,{}).get("status")!="PROPOSED" for i in formal.get("adr_ids",[]))
        or any(formal.get(i) is not False for i in
               ("rr_changed","clm_changed","spec_changed","gap_changed","test_changed"))):
        errors.append("Formal REQ/ADR/RR/CLM/SPEC/GAP/TEST cannot auto-promote")
    harness = d.get("harness", {})
    if (harness.get("canonical_checker") != "governance/check_s00_iteration36.py"
        or harness.get("legacy_receipt_checker") != "governance/check_s00_iteration35.py"
        or harness.get("acceptance_cases") != 12
        or any(harness.get(i) is not False for i in
               ("server_tests_run_by_s00","original_client_executed","approval_auto_granted"))):
        errors.append("Checker cannot claim actual Server tests or approvals")
    cases = d.get("cases",[])
    if (not isinstance(cases,list) or [x.get("id") for x in cases if isinstance(x,dict)] != EXPECTED_CASES
        or any(x.get("state")!="PLAN_ONLY" or x.get("execution")!="NOT_RUN" for x in cases if isinstance(x,dict))):
        errors.append("All twelve I36 downstream tests must remain NOT_RUN")
    if "PostgreSQL" not in report or "UNALLOCATED" not in report or "I36-T12" not in report:
        errors.append("Iteration36 detailed handoff missing")
    return errors


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--check", action="store_true")
    p.add_argument("--json", action="store_true")
    args = p.parse_args()
    problems = validate()
    if args.json:
        print(json.dumps({"ok":not problems,"errors":problems},ensure_ascii=False,indent=2))
    else:
        print("Iteration36 source-scoped PG v4 delta: " + ("PASS" if not problems else "FAIL"))
        for problem in problems: print(" - " + problem)
    return 1 if problems else 0


if __name__ == "__main__":
    raise SystemExit(main())
