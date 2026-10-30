"""Iteration28 W01-W03 gate must never report fake implementation/native success."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_iteration28 import PLAN, SOURCE, CASES, assess  # noqa: E402

FILES = [PLAN, SOURCE, CASES, "shared/targets.json", "design/decisions/index.json"]


class Iteration28Tests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        for rel in FILES:
            dest = self.root / rel
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(ROOT / rel, dest)

    def edit(self, path, mutate):
        f = self.root / path
        obj = json.loads(f.read_text(encoding="utf-8"))
        mutate(obj)
        f.write_text(json.dumps(obj, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")

    def reject(self, text):
        errors = assess(self.root)
        self.assertTrue(any(text in e for e in errors), errors)

    def test_new_work_contract_is_valid_plan_not_code(self):
        self.assertEqual(assess(self.root), [])
        doc = json.loads((self.root / PLAN).read_text(encoding="utf-8"))
        self.assertEqual([p["id"] for p in doc["packages"]], ["S28-01","S28-02","S28-03"])
        self.assertFalse(doc["policy"]["server_impl_completed"])

    def test_unverified_source_blob_is_detected(self):
        self.edit(PLAN, lambda d: d["parent"].update(git_blob_sha="0"*40))
        self.reject("Iteration27 source Git blob mismatch")

    def test_parent_source_modified_without_review(self):
        self.edit(SOURCE, lambda d: d.update(kind="NORMATIVE"))
        self.reject("Iteration27 source Git blob mismatch")

    def test_native_wire_enabled_fails(self):
        self.edit(PLAN, lambda d: d["policy"].update(wire_adapter_enabled=True))
        self.reject("Disallowed completion/native claim")

    def test_unexecuted_server_still_unexecuted(self):
        self.edit(PLAN, lambda d: d["policy"].update(server_impl_completed=True))
        self.reject("Disallowed completion/native claim")

    def test_adr_draft_must_not_turn_normative(self):
        self.edit("design/decisions/index.json",
                  lambda d: next(x for x in d["items"] if x["id"]=="ADR-0006").update(normative=True))
        self.reject("ADR-0006 is not unapproved PROPOSED")

    def test_remote_server_snapshot_cannot_be_ci_verified(self):
        self.edit(PLAN, lambda d: d["server_snapshot"].update(ci_revalidates_remote_repo=True))
        self.reject("CI cannot claim to revalidate remote")

    def test_fake_actual_server_blob_fails(self):
        self.edit(PLAN, lambda d: d["server_snapshot"]["git_blobs"][0].update(git_blob_sha="bogus"))
        self.reject("Unsafe/duplicate Server blob anchor")

    def test_migration_not_claimed_applied(self):
        self.edit(PLAN, lambda d: d["storage_proposals"]["sqlite"].update(next_version="PRODUCTION_V2_APPLIED"))
        self.reject("Proposed migrations must remain unapplied")

    def test_unknown_native_gate_not_proven(self):
        self.edit(PLAN, lambda d: d["packages"][2].update(source_native_gates=["E17-X"]))
        self.reject("source native gate not linked")

    def test_wrong_work_package_is_rejected(self):
        self.edit(PLAN, lambda d: d["packages"][1].update(source="S27-W09"))
        self.reject("incorrect parent package")

    def test_duplicate_acceptance_case_rejected(self):
        self.edit(PLAN, lambda d: d["packages"][1].update(cases=["I28-T01","I28-T06","I28-T07","I28-T08"]))
        self.reject("I28 cases must be assigned to exactly one")

    def test_cycle_rejected(self):
        self.edit(PLAN, lambda d: d["packages"][0].update(depends_on=["S28-03"]))
        self.reject("Cycle at")

    def test_missing_acceptance_case_rejected(self):
        f = self.root / CASES
        f.write_text(f.read_text(encoding="utf-8").replace("| I28-T16 |","| CASE_REMOVED |"),encoding="utf-8")
        self.reject("Expected 16 distinct NOT_RUN")

    def test_broken_kr_sha_rejected(self):
        self.edit(PLAN, lambda d: d.update(client_sha256="a"*64))
        self.reject("KR client version/SHA mismatch")

    def test_mock_policy_false_rejected(self):
        self.edit(PLAN, lambda d: d["policy"].update(proposed_mock_only=False))
        self.reject("Must stay mock-only")


if __name__ == "__main__":
    unittest.main()
