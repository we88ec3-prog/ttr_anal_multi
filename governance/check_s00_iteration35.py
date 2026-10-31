#!/usr/bin/env python3
"""S00 Iteration35: static evidence-intake preflight, NEVER Server/native approval."""
import argparse
import hashlib
import json
import re
from pathlib import Path, PurePosixPath

ROOT = Path(__file__).resolve().parents[1]
STATE = "governance/s00-iterations/S00-ITERATION-35-C05-EVIDENCE-INTAKE.json"
PLAN = "governance/s00-iterations/S00-20261031-ITERATION-35-R0-P01-EVIDENCE-INTAKE-PLAN.md"
SLOTS = ("R0-POLICY", "R0-SQLITE-MIGRATION", "R0-POSTGRES-MIGRATION",
         "P01-SQLITE", "P01-POSTGRES")
CASES = tuple(f"I35-T{i:02d}" for i in range(1, 13))
DECISIONS = tuple(f"D33-{i:02d}" for i in range(1, 9))
SHA40 = re.compile(r"^[a-f0-9]{40}$")
SHA64 = re.compile(r"^[a-f0-9]{64}$")
SERVER = "we88ec3-prog/ttr_server_roy"
CI_BASE = "https://github.com/we88ec3-prog/ttr_server_roy/actions/runs/"
MIGRATION_TESTS = {"fresh", "upgrade", "duplicate_version", "mixed_old_new",
                   "backup_restore", "crash_recovery"}
P01_TESTS = {"lease_race", "role_reselect", "ban_race", "replay_same",
             "replay_conflict", "crash_recovery", "transaction_atomic"}
P01_AUTHORITY = {"AccountId", "SessionId", "ConnectionId", "SessionRevision",
                 "ExpiresAt", "RoleId", "Suspension"}


def load(root, path):
    return json.loads((root / path).read_text(encoding="utf-8"))


def blob(data):
    return hashlib.sha1(b"blob " + str(len(data)).encode("ascii") + b"\0" + data).hexdigest()


def safe_repo_path(path):
    return (isinstance(path, str) and len(path) > 2 and len(path) < 256
            and "\\" not in path and not path.startswith("/")
            and all(segment not in (".", "..", "") for segment in PurePosixPath(path).parts)
            and re.fullmatch(r"[A-Za-z0-9_.@+/-]+", path) is not None)


def validate_baseline(root=ROOT):
    errors = []
    try:
        state = load(root, STATE)
        kr = load(root, "shared/targets.json")["kr"]["sha256"]
        note = (root / PLAN).read_text(encoding="utf-8")
    except (OSError, ValueError, KeyError, TypeError) as exc:
        return [f"Iteration35 prerequisites missing: {exc}"]
    if state.get("schema") != "s00-iteration35-c05-evidence-intake-state-v1" or state.get("kind") != "DESIGN_ONLY_EVIDENCE_GATE":
        errors.append("Must remain design-only evidence intake")
    if state.get("s00_baseline_sha") != "bfaca5b7690e4d1deba95ca68ae3feccb946ba85":
        errors.append("Iteration34 main baseline changed")
    client = state.get("client", {})
    if client.get("version") != "kr" or client.get("sha256") != kr:
        errors.append("Original KR source SHA/version drift")
    if client.get("original_client_executed") is not False or client.get("native_adapter_enabled") is not False:
        errors.append("Native Client cannot be promoted")
    pins = state.get("source_blobs", [])
    expected_paths = (
        "governance/s00-iterations/S00-20261031-ITERATION-34-C05-R0-SERVER-DELTA-PREFLIGHT.md",
        "governance/s00-iterations/S00-ITERATION-34-C05-R0-SERVER-DELTA-CONTRACT.json",
    )
    if not isinstance(pins, list) or len(pins) != 2:
        errors.append("Exactly two Iteration34 source blob pins required")
    else:
        for index, path in enumerate(expected_paths):
            record = pins[index]
            try:
                if record.get("path") != path or record.get("sha") != blob((root / path).read_bytes()):
                    errors.append(f"Original Git blob mismatch: {path}")
            except (AttributeError, OSError):
                errors.append(f"Missing original Git blob source: {path}")
    server = state.get("server_last_observed", {})
    if (server.get("repo") != SERVER
        or server.get("head_sha") != "3e0b7e3a8666f363f747dbf68c2fd462a8777b09"
        or server.get("observation") != "UNCHANGED_FROM_ITERATION34"
        or server.get("snapshot_not_live") is not True
        or server.get("actual_c05_p01_implementation_verified") is not False
        or server.get("postgres_moderation_parity_verified") is not False
        or server.get("sqlite_current_version") != 2 or server.get("postgres_current_version") != 3):
        errors.append("Historical Server snapshot not a live implementation receipt")
    slots = state.get("slots", [])
    if not isinstance(slots, list) or tuple(s.get("id") for s in slots if isinstance(s, dict)) != SLOTS:
        errors.append("Five immutable no-receipt slot IDs required")
    else:
        for s in slots:
            if (s.get("state") != "NO_RECEIPT" or s.get("review") != "NOT_REVIEWED"
                or not s.get("requires") or not s.get("owner")):
                errors.append(f"Unverified evidence slot promoted: {s.get('id')}")
    if state.get("decisions") != dict.fromkeys(DECISIONS, "AWAITING_MAINTAINER_APPROVAL"):
        errors.append("D33 decisions silently approved")
    native = state.get("native_gate", {})
    if (native.get("status") != "SOURCE_GATED_OFF"
        or native.get("original_client_runtime") != "NOT_RUN"
        or native.get("wire_contracts_implemented") != []
        or native.get("not_derived_from_mock_pass") is not True):
        errors.append("Native R6 no-go bypassed")
    policy = state.get("policy", {})
    if any(policy.get(x) is not True for x in (
        "no_commit_or_ci_equals_approval", "github_validation_requires_human_external_readback",
        "all_receipts_currently_absent", "formal_req_rr_gap_clm_spec_test_unchanged",
        "adr_0006_0007_not_approved", "server_repo_not_modified_by_s00")):
        errors.append("Evidence acceptance boundary or formal status promoted")
    cases = state.get("planned_acceptance_tests", [])
    if not isinstance(cases, list) or tuple(c.get("id") for c in cases if isinstance(c, dict)) != CASES:
        errors.append("Twelve ordered Iteration35 acceptance plans required")
    elif any(c.get("status") != "PLAN_ONLY" or c.get("execution") != "NOT_RUN" for c in cases):
        errors.append("Planned acceptance cannot be marked executed")
    if "STRUCTURALLY_REVIEWABLE_NOT_APPROVED" not in note or "NO_RECEIPT" not in note:
        errors.append("Evidence gate narrative must distinguish review from approval")
    return errors


def validate_candidate(receipt):
    """Syntactic preflight ONLY. A valid result is NOT verified Git, CI or policy."""
    errors = []
    if not isinstance(receipt, dict):
        return ["Receipt must be JSON object"]
    slot = receipt.get("slot")
    if receipt.get("schema") != "s00-iteration35-server-c05-receipt-v1" or slot not in SLOTS:
        errors.append("Unknown receipt schema/slot")
        return errors
    if receipt.get("repository") != SERVER or not SHA40.fullmatch(str(receipt.get("server_commit", ""))):
        errors.append("Server repo or full commit SHA invalid")
    if not isinstance(receipt.get("owner"), str) or not receipt["owner"].strip():
        errors.append("Owner required")
    if (receipt.get("native_adapter_enabled") is not False
        or receipt.get("original_client_executed") is not False
        or receipt.get("domain") != "SERVER_MOCK_ONLY"):
        errors.append("Native/Client execution claims forbidden from R0/P01 receipt")
    files = receipt.get("source_files")
    if not isinstance(files, list) or not files:
        errors.append("Non-empty source_files required")
        files = []
    paths = []
    for item in files:
        if not isinstance(item, dict) or not safe_repo_path(item.get("path")) or not SHA40.fullmatch(str(item.get("git_blob_sha", ""))):
            errors.append("Malformed source file path/Git blob")
        else:
            paths.append(item["path"])
    if len(paths) != len(set(paths)):
        errors.append("Duplicate source file")
    runs = receipt.get("ci_runs")
    if not isinstance(runs, list) or not runs:
        errors.append("At least one actual Server CI receipt required")
        runs = []
    ids = []
    covered = set()
    for run in runs:
        if not isinstance(run, dict):
            errors.append("Invalid CI record")
            continue
        ident = run.get("run_id")
        if not isinstance(ident, int) or isinstance(ident, bool) or ident <= 0:
            errors.append("Positive CI run ID required")
            continue
        ids.append(ident)
        if (run.get("url") != CI_BASE + str(ident)
            or run.get("head_sha") != receipt.get("server_commit")
            or run.get("conclusion") != "success"
            or run.get("scope") != "SERVER_OFFLINE_TEST"):
            errors.append("CI run head/SHA/scope/URL must match submitted Server commit")
        tests = run.get("test_ids")
        if not isinstance(tests, list) or not tests or any(not isinstance(t, str) for t in tests):
            errors.append("CI tests must be explicitly named")
        else:
            covered.update(tests)
    if len(ids) != len(set(ids)):
        errors.append("Duplicate CI run ID")
    detail = receipt.get("details")
    if not isinstance(detail, dict):
        return errors + ["Slot-specific details required"]
    if slot == "R0-POLICY":
        if not str(detail.get("policy_revision", "")).strip():
            errors.append("Policy revision required")
        decisions = detail.get("decisions", [])
        if not isinstance(decisions, list) or sorted(d.get("id") for d in decisions if isinstance(d, dict)) != sorted(DECISIONS):
            errors.append("Eight owner-approved D33 decision IDs required")
        else:
            for d in decisions:
                if (not str(d.get("decision", "")).strip()
                    or not safe_repo_path(d.get("approval_ref"))
                    or not SHA40.fullmatch(str(d.get("approval_git_blob_sha", "")))):
                    errors.append("Policy decision needs source-pinned approval reference")
    elif slot.startswith("R0-"):
        provider = "SQLITE" if "SQLITE" in slot else "POSTGRES"
        # The historical Iteration35 snapshot remains PG3, but future C05 receipts\n        # must start after actual Server WEB-ADMIN-PG schema 004.\n        baseline = 2 if provider == "SQLITE" else 4
        if detail.get("provider") != provider or detail.get("base_version") != baseline:
            errors.append("Migration provider or observed baseline mismatch")
        if not SHA64.fullmatch(str(detail.get("manifest_sha256", ""))):
            errors.append("Migration manifest SHA256 required")
        allocs = detail.get("allocations")
        if not isinstance(allocs, list) or not allocs:
            errors.append("At least one migration allocation required")
        else:
            versions = []
            for a in allocs:
                if not isinstance(a, dict):
                    errors.append("Malformed migration allocation")
                    continue
                version = a.get("version")
                if not isinstance(version, int) or isinstance(version, bool) or version <= baseline:
                    errors.append("Migration version must be greater than observed baseline")
                else:
                    versions.append(version)
                if (not safe_repo_path(a.get("path")) or not SHA64.fullmatch(str(a.get("sha256", "")))
                    or not str(a.get("module", "")).strip()):
                    errors.append("Migration source SHA256/path/module missing")
            if versions != sorted(set(versions)) or len(versions) != len(allocs):
                errors.append("Migration versions must be increasing and unique")
        if not MIGRATION_TESTS.issubset(covered):
            errors.append("Migration positive/negative/recovery test IDs missing")
    else:
        provider = "SQLITE" if slot == "P01-SQLITE" else "POSTGRES"
        if detail.get("provider") != provider or not str(detail.get("policy_revision", "")).strip():
            errors.append("P01 provider/policy revision required")
        if not SHA64.fullmatch(str(detail.get("migration_manifest_sha256", ""))):
            errors.append("P01 pinned migration manifest SHA256 required")
        if (detail.get("atomic_same_transaction") is not True
            or detail.get("fingerprint_collision_rejected") is not True
            or detail.get("postresurrection_old_epoch_rejected") is not True):
            errors.append("P01 atomic/stale-epoch/fingerprint assertions required")
        if (detail.get("admission_key_fields") != ["AdmissionId", "AccountId", "SessionRevision"]
            or not P01_AUTHORITY.issubset(set(detail.get("authority_fields", [])))):
            errors.append("P01 exact lease/role/ban/idempotency authority missing")
        if not P01_TESTS.issubset(covered):
            errors.append("P01 concurrency/replay/crash test IDs missing")
    return errors


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    options = parser.add_mutually_exclusive_group(required=True)
    options.add_argument("--check", action="store_true", help="Verify canonical NO_RECEIPT state")
    options.add_argument("--candidate", type=Path, help="Syntax review a proposed Server receipt JSON")
    options.add_argument("--json", action="store_true", help="Machine-readable baseline NO_RECEIPT check")
    args = parser.parse_args()
    if args.candidate:
        try:
            candidate = json.loads(args.candidate.read_text(encoding="utf-8"))
            problems = validate_candidate(candidate)
        except (OSError, ValueError) as exc:
            problems = [f"Cannot parse candidate: {exc}"]
        status = "STRUCTURALLY_REVIEWABLE_NOT_APPROVED" if not problems else "REJECTED_NOT_REVIEWABLE"
    else:
        problems = validate_baseline()
        status = "BASELINE_NO_RECEIPT_INTEGRITY_OK" if not problems else "BASELINE_INTEGRITY_FAILED"
    result = {"status": status, "errors": problems, "external_verification_performed": False,
              "server_tests_executed": False, "original_client_executed": False,
              "formal_approval_granted": False}
    if args.json:
        print(json.dumps(result, ensure_ascii=False, indent=2))
    else:
        print(status)
        for problem in problems:
            print(" - " + problem)
        if args.candidate and not problems:
            print("WARNING: source SHA, CI execution and policy approval are NOT checked online.")
    return 1 if problems else 0


if __name__ == "__main__":
    raise SystemExit(main())
