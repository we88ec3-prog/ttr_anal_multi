"""18 structural regressions: a plan cannot silently approve C05/native compatibility."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_iteration33 import MATRIX, SOURCES, CASES, validate  # noqa:E402

FILES = [MATRIX, CASES, *SOURCES, "shared/targets.json", "design/decisions/index.json"]


class Iteration33Tests(unittest.TestCase):
    def setUp(self):
        self.t = tempfile.TemporaryDirectory()
        self.addCleanup(self.t.cleanup)
        self.root = Path(self.t.name)
        for path in FILES:
            p = self.root / path
            p.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / path, p)

    def change(self, path, fn):
        p = self.root / path
        d = json.loads(p.read_text(encoding="utf-8"))
        fn(d)
        p.write_text(json.dumps(d, indent=2, ensure_ascii=False)+"\n", encoding="utf-8")

    def fail_has(self, text):
        errs = validate(self.root)
        self.assertTrue(any(text in e for e in errs), errs)

    def test_current_19_pr_plan_is_unimplemented(self):
        self.assertEqual(validate(self.root), [])
        d = json.loads((self.root / MATRIX).read_text(encoding="utf-8"))
        self.assertEqual(len(d["pr_plan"]), 19)
        self.assertEqual(len(d["release_gates"]), 7)
        self.assertFalse(d["governance"]["actual_server_c05_implemented"])

    def test_source_blob_tamper_rejected(self):
        self.change(MATRIX, lambda d: d["source_blobs"][0].update(git_blob_sha="0"*40))
        self.fail_has("Source Git blob mismatch")

    def test_upstream_source_content_mutation_rejected(self):
        self.change(SOURCES[5], lambda d: d.update(kind="NORMATIVE"))
        self.fail_has("Source Git blob mismatch")

    def test_false_native_gate_e25_upgrade_rejected(self):
        self.change(MATRIX, lambda d: d["gate_snapshots"][4].update(evidence_state="NATIVE_VERIFIED"))
        self.fail_has("original gate state/owner/blocker promoted")

    def test_change_original_e17j_owner_rejected(self):
        self.change(MATRIX, lambda d: d["gate_snapshots"][1].update(owners=["S00"]))
        self.fail_has("original gate state/owner/blocker promoted")

    def test_duplicate_pr_identifier_rejected(self):
        self.change(MATRIX, lambda d: d["pr_plan"][1].update(id="C05-P01"))
        self.fail_has("PR IDs must exactly be ordered")

    def test_duplicate_source_work_package_rejected(self):
        self.change(MATRIX, lambda d: d["pr_plan"][4].update(source_work_id="S29-01"))
        self.fail_has("Every C05 PR must map once")

    def test_unknown_dependency_rejected(self):
        self.change(MATRIX, lambda d: d["pr_plan"][3].update(depends_on=["C05-P99"]))
        self.fail_has("invalid, duplicate, or unknown PR dependency")

    def test_cross_release_dependency_cycle_rejected(self):
        self.change(MATRIX, lambda d: d["pr_plan"][0].update(depends_on=["C05-P19"]))
        self.fail_has("C05 dependency cycle")

    def test_release_assignment_duplicate_rejected(self):
        self.change(MATRIX, lambda d: d["release_gates"][2]["work_ids"].append("C05-P01"))
        self.fail_has("Each of 19 PRs must appear in exactly one")

    def test_r6_cannot_be_marked_native_pass(self):
        self.change(MATRIX, lambda d: d["release_gates"][-1].update(status="SUCCESS",level="NATIVE_APPROVED"))
        self.fail_has("R0 and R6 policy/native boundaries")

    def test_unearned_c05_server_implementation_rejected(self):
        self.change(MATRIX,lambda d:d["governance"].update(actual_server_c05_implemented=True))
        self.fail_has("Unproven native/Server completion claim")

    def test_original_client_runtime_false_pass_rejected(self):
        self.change(MATRIX,lambda d:d["governance"].update(original_client_runtime_executed=True))
        self.fail_has("Unproven native/Server completion claim")

    def test_original_adr_must_remain_proposed(self):
        self.change("design/decisions/index.json",
                    lambda d: next(x for x in d["items"] if x["id"]=="ADR-0007").update(status="APPROVED"))
        self.fail_has("ADR-0007 must remain PROPOSED")

    def test_sqlite_schema_versions_cannot_be_preallocated(self):
        self.change(MATRIX,lambda d:d["migration_control"]["new_versions"].update(sqlite="v3_APPLIED"))
        self.fail_has("migration single allocator violated")

    def test_provider_ban_parity_must_not_be_assumed(self):
        self.change(MATRIX,lambda d:d["migration_control"]["provider_current"].update(postgres_c02d_suspend_equivalence_verified=True))
        self.fail_has("migration single allocator violated")

    def test_missing_integration_test_case_rejected(self):
        path=self.root/CASES
        path.write_text(path.read_text(encoding="utf-8").replace("| I33-T24 |","| REMOVED-T24 |"),encoding="utf-8")
        self.fail_has("Exactly 24 distinct")

    def test_native_adapter_source_gate_cannot_be_removed(self):
        self.change(MATRIX,lambda d:d["native_admission"].update(adapter="NATIVE_ENABLED"))
        self.fail_has("Native adapter remains source-gated")


if __name__ == "__main__":
    unittest.main()
