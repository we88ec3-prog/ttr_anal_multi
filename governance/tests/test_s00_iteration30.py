"""Iteration30 planning boundaries: negative tests prevent unearned proof claims."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_iteration30 import MATRIX, CASES, PARENTS, validate  # noqa:E402

FILES = [MATRIX, CASES, *PARENTS, "shared/targets.json", "design/decisions/index.json"]


class Iteration30Tests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        for path in FILES:
            dest = self.root / path
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / path, dest)

    def mutate(self, path, fn):
        dest = self.root / path
        data = json.loads(dest.read_text(encoding="utf-8"))
        fn(data)
        dest.write_text(json.dumps(data, ensure_ascii=False, indent=2) + "\n", encoding="utf-8")

    def assert_reject(self, snippet):
        errors = validate(self.root)
        self.assertTrue(any(snippet in error for error in errors), errors)

    def test_current_contract_is_a_mock_plan(self):
        self.assertEqual(validate(self.root), [])
        data = json.loads((self.root / MATRIX).read_text(encoding="utf-8"))
        self.assertEqual([x["id"] for x in data["packages"]], ["S30-01","S30-02","S30-03","S30-04"])
        self.assertFalse(data["policies"]["server_c05_implemented"])
        self.assertEqual(data["transaction_model"]["sqlite_existing_version"], 2)

    def test_parent_git_blob_is_immutable_without_review(self):
        self.mutate(MATRIX, lambda d: d["source_blobs"][0].update(git_blob_sha="0"*40))
        self.assert_reject("Source Git blob mismatch")

    def test_source_content_mutation_is_detected(self):
        self.mutate(PARENTS[2], lambda d: d.update(schema="changed"))
        self.assert_reject("Source Git blob mismatch")

    def test_original_evidence_cannot_be_promoted(self):
        self.mutate(MATRIX, lambda d: d["original_gate_snapshots"][1].update(evidence_state="NATIVE_VERIFIED"))
        self.assert_reject("original gate evidence/owners/blocker promoted")

    def test_native_evidence_owner_falsified(self):
        self.mutate(MATRIX, lambda d: d["original_gate_snapshots"][4].update(owners=["S00"]))
        self.assert_reject("original gate evidence/owners/blocker promoted")

    def test_c00_ops_is_not_c05(self):
        self.mutate(MATRIX, lambda d: d["server_snapshot"].update(latest_change="C05_IMPLEMENTED"))
        self.assert_reject("C00-OPS must not be misreported")

    def test_unchecked_server_ci_cannot_be_declared_success(self):
        self.mutate(MATRIX, lambda d: d["server_snapshot"].update(ci_conclusion_at_observation="SUCCESS"))
        self.assert_reject("Server CI cannot be falsely marked verified")

    def test_early_server_c05_success_rejected(self):
        self.mutate(MATRIX, lambda d: d["policies"].update(server_c05_implemented=True))
        self.assert_reject("Unearned implementation/native claim")

    def test_runtime_native_adapter_cannot_enable(self):
        self.mutate(MATRIX, lambda d: d["policies"].update(native_adapter_enabled=True))
        self.assert_reject("Unearned implementation/native claim")

    def test_adr_must_remain_proposed(self):
        self.mutate("design/decisions/index.json",
                    lambda d: next(x for x in d["items"] if x["id"]=="ADR-0007").update(status="APPROVED"))
        self.assert_reject("ADR-0007 not PROPOSED")

    def test_quest_boundary_must_be_separate(self):
        self.mutate(MATRIX, lambda d: d["transaction_model"].update(quest_boundary="Scenario14 success is Quest14 COMPLETED"))
        self.assert_reject("Outbox/native/Quest separation weakened")

    def test_original_client_opcode_wont_be_enabled(self):
        self.mutate(MATRIX, lambda d: d["transaction_model"].update(native_result_adapter="SEND_0x004C"))
        self.assert_reject("Outbox/native/Quest separation weakened")

    def test_db_next_schema_unapplied(self):
        self.mutate(MATRIX, lambda d: d["transaction_model"].update(migration_sqlite_next="V3_APPLIED"))
        self.assert_reject("Mock-only DB/current provider")

    def test_unregistered_native_gate_rejected(self):
        self.mutate(MATRIX, lambda d: d["packages"][0].update(gates=["E17-Z"]))
        self.assert_reject("invalid original native gate reference")

    def test_duplicate_case_rejected(self):
        self.mutate(MATRIX, lambda d: d["packages"][1].update(cases=["I30-T01",*d["packages"][1]["cases"][1:]]))
        self.assert_reject("Case coverage must be one work package")

    def test_cycle_rejected(self):
        self.mutate(MATRIX, lambda d: d["packages"][0].update(depends_on=["S30-04"]))
        self.assert_reject("Dependency cycle")

    def test_missing_case_rejected(self):
        dest = self.root / CASES
        dest.write_text(dest.read_text(encoding="utf-8").replace("| I30-T24 |","| REMOVED-T24 |"),encoding="utf-8")
        self.assert_reject("Expected 24 unique NOT_RUN cases")

    def test_missing_source_git_blob_rejected(self):
        self.mutate(MATRIX, lambda d: d["server_snapshot"]["anchors"][0].update(git_blob_sha="bogus"))
        self.assert_reject("Malformed Server blob SHA/path")


if __name__ == "__main__":
    unittest.main()
