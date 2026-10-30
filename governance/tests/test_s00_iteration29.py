"""Regression tests that protect Iteration29 plans from fake native/server success."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_iteration29 import MATRIX, CASES, PARENTS, validate  # noqa:E402

FILES = [MATRIX, CASES, *PARENTS, "shared/targets.json", "design/decisions/index.json"]


class Iteration29Tests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        for name in FILES:
            path = self.root / name
            path.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / name, path)

    def change(self, name, modify):
        path = self.root / name
        doc = json.loads(path.read_text(encoding="utf-8"))
        modify(doc)
        path.write_text(json.dumps(doc, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")

    def assert_error(self, snippet):
        errs = validate(self.root)
        self.assertTrue(any(snippet in err for err in errs), errs)

    def test_current_s29_contract_is_a_proposal(self):
        self.assertEqual(validate(self.root), [])
        d = json.loads((self.root / MATRIX).read_text(encoding="utf-8"))
        self.assertEqual(len(d["work_packages"]), 4)
        self.assertFalse(d["governance"]["server_implementation_executed"])
        self.assertEqual(d["migration_proposal"]["sqlite_current_schema_version"], 2)

    def test_source_pinned_hash_detects_change(self):
        self.change(MATRIX, lambda d: d["source_files"][0].update(git_blob_sha="0"*40))
        self.assert_error("Upstream source Git blob altered")

    def test_original_e17_f_evidence_cannot_be_promoted(self):
        self.change(MATRIX, lambda d: d["gate_evidence_snapshot"][1].update(source_evidence_state="NATIVE_VERIFIED"))
        self.assert_error("native evidence/blocker/owner promoted")

    def test_original_gate_owner_falsification_rejected(self):
        self.change(MATRIX, lambda d: d["gate_evidence_snapshot"][2].update(owners=["S00"]))
        self.assert_error("native evidence/blocker/owner promoted")

    def test_client_native_adapter_cannot_be_enabled(self):
        self.change(MATRIX, lambda d: d["governance"].update(native_adapter_enabled=True))
        self.assert_error("Forbidden completion/native assertion")

    def test_server_implementation_cannot_be_claimed(self):
        self.change(MATRIX, lambda d: d["governance"].update(server_implementation_executed=True))
        self.assert_error("Forbidden completion/native assertion")

    def test_synthetic_tests_cannot_be_marked_executed(self):
        self.change(MATRIX, lambda d: d["governance"].update(domain_test_executed=True))
        self.assert_error("Forbidden completion/native assertion")

    def test_adr_silently_approved_rejected(self):
        self.change("design/decisions/index.json",lambda d: next(x for x in d["items"] if x["id"]=="ADR-0007").update(status="APPROVED"))
        self.assert_error("ADR-0007 must remain PROPOSED")

    def test_new_sqlite_v2_factual_baseline_cannot_regress(self):
        self.change(MATRIX, lambda d: d["migration_proposal"].update(sqlite_current_schema_version=1))
        self.assert_error("SQLite v2 / PostgreSQL 003")

    def test_sqlite_v3_not_migrated_claim(self):
        self.change(MATRIX,lambda d: d["migration_proposal"].update(sqlite_next="V3_APPLIED"))
        self.assert_error("unapplied next migrations")

    def test_remote_server_ci_not_automatically_verified(self):
        self.change(MATRIX,lambda d: d["server_snapshot"].update(ci_checks_source_snapshot_against_remote=True))
        self.assert_error("S00 CI cannot claim remote Server revalidation")

    def test_fake_server_blob_rejected(self):
        self.change(MATRIX,lambda d: d["server_snapshot"]["git_blobs"][0].update(git_blob_sha="bogus"))
        self.assert_error("Malformed Server source Git blob anchor")

    def test_client_as_damage_authority_rejected(self):
        self.change(MATRIX,lambda d: d["domain_model"].update(damage_authority="CLIENT_REPORTED_DAMAGE"))
        self.assert_error("Unapproved combat domain authority promoted")

    def test_wrong_native_gate_rejected(self):
        self.change(MATRIX,lambda d: d["work_packages"][1].update(gate_ids=["E17-H"]))
        self.assert_error("unregistered native gate")

    def test_cyclic_dependencies_rejected(self):
        self.change(MATRIX,lambda d: d["work_packages"][0].update(depends_on=["S29-04"]))
        self.assert_error("Work dependency cycle")

    def test_duplicate_work_case_assignment_rejected(self):
        self.change(MATRIX,lambda d: d["work_packages"][0].update(tests=["I29-T07","I29-T02","I29-T03","I29-T04","I29-T05","I29-T06"]))
        self.assert_error("I29 cases not one-to-one linked")

    def test_missing_acceptance_case_rejected(self):
        path = self.root / CASES
        path.write_text(path.read_text(encoding="utf-8").replace("| I29-T24 |","| MISSING-T24 |"),encoding="utf-8")
        self.assert_error("Expected 24 NOT_RUN")

    def test_stale_server_baseline_claim_rejected(self):
        self.change(MATRIX,lambda d: d["server_snapshot"].update(status="C05_IMPLEMENTED"))
        self.assert_error("C05 Server implementation improperly promoted")


if __name__ == "__main__":
    unittest.main()
