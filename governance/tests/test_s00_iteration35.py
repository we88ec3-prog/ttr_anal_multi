"""Offline validator tests: synthetic receipts are NOT actual Server or KR proof."""
import copy
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_iteration35 import (STATE, PLAN, SLOTS, P01_TESTS, MIGRATION_TESTS,
                                   validate_baseline, validate_candidate)

BASE_FILES = [
    STATE, PLAN, "shared/targets.json",
    "governance/s00-iterations/S00-20261031-ITERATION-34-C05-R0-SERVER-DELTA-PREFLIGHT.md",
    "governance/s00-iterations/S00-ITERATION-34-C05-R0-SERVER-DELTA-CONTRACT.json",
]
SHA = "a" * 40
SHA256 = "b" * 64


def fabricated(slot="P01-SQLITE"):
    """Only a fictional, deliberately untrusted structure validator fixture."""
    tests = sorted(P01_TESTS if slot.startswith("P01") else
                   MIGRATION_TESTS if slot.endswith("MIGRATION") else {"approval_record"})
    details = {}
    if slot == "R0-POLICY":
        details = {"policy_revision": "synthetic-not-real", "decisions": [
            {"id": f"D33-{i:02d}", "decision": "synthetic-not-real",
             "approval_ref": f"docs/approval-{i}.md", "approval_git_blob_sha": SHA}
            for i in range(1, 9)]}
    elif slot.startswith("R0-"):
        provider = "SQLITE" if "SQLITE" in slot else "POSTGRES"
        baseline = 2 if provider == "SQLITE" else 3
        details = {"provider": provider, "base_version": baseline,
                   "manifest_sha256": SHA256,
                   "allocations": [{"version": baseline + 1, "module": "Encounter",
                                    "path": "db/migrations/mock.sql", "sha256": SHA256}]}
    else:
        details = {
            "provider": "SQLITE" if slot.endswith("SQLITE") else "POSTGRES",
            "policy_revision": "synthetic-not-real",
            "migration_manifest_sha256": SHA256,
            "atomic_same_transaction": True, "fingerprint_collision_rejected": True,
            "postresurrection_old_epoch_rejected": True,
            "admission_key_fields": ["AdmissionId", "AccountId", "SessionRevision"],
            "authority_fields": ["AccountId", "SessionId", "ConnectionId", "SessionRevision",
                                 "ExpiresAt", "RoleId", "Suspension"],
        }
    return {
        "schema": "s00-iteration35-server-c05-receipt-v1", "slot": slot,
        "repository": "we88ec3-prog/ttr_server_roy", "server_commit": SHA,
        "owner": "synthetic fixture maintainer",
        "source_files": [{"path": "src/MockAdmission.cs", "git_blob_sha": SHA}],
        "ci_runs": [{"run_id": 12345, "head_sha": SHA,
                     "url": "https://github.com/we88ec3-prog/ttr_server_roy/actions/runs/12345",
                     "conclusion": "success", "scope": "SERVER_OFFLINE_TEST",
                     "test_ids": tests}],
        "native_adapter_enabled": False,
        "original_client_executed": False, "domain": "SERVER_MOCK_ONLY",
        "details": details,
    }


class Iteration35Tests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        for path in BASE_FILES:
            out = self.root / path
            out.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / path, out)

    def edit(self, path, change):
        file = self.root / path
        x = json.loads(file.read_text(encoding="utf-8"))
        change(x)
        file.write_text(json.dumps(x, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")

    def baseline_rejects(self, text):
        errors = validate_baseline(self.root)
        self.assertTrue(any(text in e for e in errors), errors)

    def candidate_rejects(self, candidate, text):
        errors = validate_candidate(candidate)
        self.assertTrue(any(text in e for e in errors), errors)

    def test_unsubmitted_baseline_is_valid(self):
        self.assertEqual(validate_baseline(self.root), [])

    def test_native_claim_fails(self):
        self.edit(STATE, lambda x: x["client"].update(native_adapter_enabled=True))
        self.baseline_rejects("Native Client")

    def test_source_blob_tampering_fails(self):
        self.edit(STATE, lambda x: x["source_blobs"][0].update(sha="0" * 40))
        self.baseline_rejects("Original Git blob mismatch")

    def test_upstream_source_mutation_fails(self):
        p = self.root / BASE_FILES[3]
        p.write_text(p.read_text(encoding="utf-8") + "tamper\n", encoding="utf-8")
        self.baseline_rejects("Original Git blob mismatch")

    def test_no_receipt_cannot_be_approved(self):
        self.edit(STATE, lambda x: x["slots"][0].update(state="APPROVED"))
        self.baseline_rejects("Unverified evidence slot")

    def test_d33_approval_cannot_be_invented(self):
        self.edit(STATE, lambda x: x["decisions"].update({"D33-01": "APPROVED"}))
        self.baseline_rejects("D33 decisions")

    def test_planned_tests_not_executed(self):
        self.edit(STATE, lambda x: x["planned_acceptance_tests"][0].update(execution="PASS"))
        self.baseline_rejects("Planned acceptance")

    def test_server_implementation_cannot_be_asserted(self):
        self.edit(STATE, lambda x: x["server_last_observed"].update(actual_c05_p01_implementation_verified=True))
        self.baseline_rejects("Historical Server snapshot")

    def test_all_five_synthetic_candidate_shapes_reviewable_only(self):
        for slot in SLOTS:
            with self.subTest(slot=slot):
                self.assertEqual([], validate_candidate(fabricated(slot)))

    def test_forged_native_enable_rejected(self):
        d = fabricated()
        d["native_adapter_enabled"] = True
        self.candidate_rejects(d, "Native/Client")

    def test_bad_git_sha_rejected(self):
        d = fabricated()
        d["server_commit"] = "abc"
        self.candidate_rejects(d, "full commit SHA")

    def test_cross_commit_ci_rejected(self):
        d = fabricated()
        d["ci_runs"][0]["head_sha"] = "c" * 40
        self.candidate_rejects(d, "CI run head")

    def test_fake_native_ci_scope_rejected(self):
        d = fabricated()
        d["ci_runs"][0]["scope"] = "NATIVE_CLIENT_PASS"
        self.candidate_rejects(d, "CI run head")

    def test_traversal_source_path_rejected(self):
        d = fabricated()
        d["source_files"][0]["path"] = "../secrets.txt"
        self.candidate_rejects(d, "Malformed source file")

    def test_duplicate_ci_run_rejected(self):
        d = fabricated()
        d["ci_runs"].append(copy.deepcopy(d["ci_runs"][0]))
        self.candidate_rejects(d, "Duplicate CI run ID")

    def test_missing_atomic_authority_rejected(self):
        d = fabricated()
        d["details"]["atomic_same_transaction"] = False
        self.candidate_rejects(d, "P01 atomic")

    def test_missing_expiry_fencing_rejected(self):
        d = fabricated()
        d["details"]["authority_fields"].remove("ExpiresAt")
        self.candidate_rejects(d, "P01 exact lease")

    def test_missing_replay_negative_rejected(self):
        d = fabricated()
        d["ci_runs"][0]["test_ids"].remove("replay_conflict")
        self.candidate_rejects(d, "P01 concurrency")

    def test_migration_duplicate_version_rejected(self):
        d = fabricated("R0-POSTGRES-MIGRATION")
        d["details"]["allocations"].append(dict(d["details"]["allocations"][0]))
        self.candidate_rejects(d, "Migration versions")

    def test_migration_without_restore_rejected(self):
        d = fabricated("R0-SQLITE-MIGRATION")
        d["ci_runs"][0]["test_ids"].remove("backup_restore")
        self.candidate_rejects(d, "Migration positive")

    def test_wrong_provider_baseline_rejected(self):
        d = fabricated("R0-POSTGRES-MIGRATION")
        d["details"]["base_version"] = 2
        self.candidate_rejects(d, "Migration provider")

    def test_missing_policy_approval_reference_rejected(self):
        d = fabricated("R0-POLICY")
        d["details"]["decisions"][0]["approval_ref"] = ""
        self.candidate_rejects(d, "Policy decision")


if __name__ == "__main__":
    unittest.main()
