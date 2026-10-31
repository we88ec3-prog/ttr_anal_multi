"""Iteration32 planning-only fail-closed unit regression suite."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_iteration32 import MATRIX, CASES, SOURCES, validate  # noqa:E402

FILES = [MATRIX, CASES, *SOURCES, "shared/targets.json", "design/decisions/index.json"]


class Iteration32Tests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        for item in FILES:
            f = self.root / item
            f.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / item, f)

    def change(self, name, fn):
        file = self.root / name
        d = json.loads(file.read_text(encoding="utf-8"))
        fn(d)
        file.write_text(json.dumps(d, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")

    def reject(self, text):
        errors = validate(self.root)
        self.assertTrue(any(text in e for e in errors), errors)

    def test_valid_scope_remains_not_executed(self):
        self.assertEqual(validate(self.root), [])
        d = json.loads((self.root / MATRIX).read_text(encoding="utf-8"))
        self.assertEqual(len(d["packages"]), 4)
        self.assertFalse(d["policy"]["server_c05_implemented"])

    def test_source_blob_change_is_rejected(self):
        self.change(MATRIX, lambda d: d["sources"][0].update(git_blob_sha="0"*40))
        self.reject("Source Git blob mismatch")

    def test_parent_modified_without_repin_is_rejected(self):
        self.change(SOURCES[0], lambda d: d.update(kind="NORMATIVE"))
        self.reject("Source Git blob mismatch")

    def test_original_e25_source_status_is_unchanged(self):
        self.change(MATRIX, lambda d: d["original_gates"][2].update(evidence_state="NATIVE_VERIFIED"))
        self.reject("original source gate evidence/owner/status upgraded")

    def test_e26_owner_must_not_be_replaced(self):
        self.change(MATRIX, lambda d: d["original_gates"][3].update(owners=["S00"]))
        self.reject("original source gate evidence/owner/status upgraded")

    def test_missing_native_adapter_quarantine_rejected(self):
        self.change(MATRIX, lambda d: d.update(native_adapter_parent="S27-W09_IMPLEMENTED"))
        self.reject("Tutorial/quest/native dependency separation broken")

    def test_world_ready_cannot_be_claimed_from_mock(self):
        self.change(MATRIX, lambda d: d["state_dimensions"].update(world_ready_policy="ORIGINAL_CLIENT_READY"))
        self.reject("Tutorial/scene/native observation state axes collapsed")

    def test_client_runtime_false_success_rejected(self):
        self.change(MATRIX, lambda d: d["policy"].update(original_client_runtime_executed=True))
        self.reject("Unearned native/Server result")

    def test_c05_server_completion_false_claim_rejected(self):
        self.change(MATRIX, lambda d: d["policy"].update(server_c05_implemented=True))
        self.reject("Unearned native/Server result")

    def test_adr_cannot_be_approved_by_a_plan(self):
        self.change("design/decisions/index.json", lambda d: next(x for x in d["items"] if x["id"]=="ADR-0006").update(status="APPROVED"))
        self.reject("ADR-0006 must be PROPOSED")

    def test_server_snapshot_cannot_be_native_success(self):
        self.change(MATRIX, lambda d: d["server_snapshot"].update(ci_conclusion="NATIVE_VERIFIED"))
        self.reject("Independent Server snapshot cannot mean native verified")

    def test_migration_number_not_auto_allocated(self):
        self.change(MATRIX, lambda d: d["persistence"].update(sqlite_next="V3_APPLIED"))
        self.reject("C05 migration sequence or actual provider baseline")

    def test_provider_baseline_must_not_be_downgraded(self):
        self.change(MATRIX, lambda d: d["persistence"].update(sqlite_existing_version=1))
        self.reject("C05 migration sequence or actual provider baseline")

    def test_quest15_not_tutorial_complete(self):
        self.change(MATRIX, lambda d: d["no_go"].remove("NO_QUEST15_AVAILABLE_EQUALS_TUTORIAL_COMPLETED"))
        self.reject("Missing no-go")

    def test_one_case_cannot_be_owned_twice(self):
        self.change(MATRIX, lambda d: d["packages"][1].update(cases=["I32-T01", *d["packages"][1]["cases"][1:]]))
        self.reject("Every I32 case must belong to exactly one package")

    def test_cyclic_dependencies_rejected(self):
        self.change(MATRIX, lambda d: d["packages"][0].update(depends_on=["S32-04"]))
        self.reject("Dependency cycle")

    def test_missing_case_row_rejected(self):
        f = self.root / CASES
        f.write_text(f.read_text(encoding="utf-8").replace("| I32-T24 |","| REMOVED-T24 |"), encoding="utf-8")
        self.reject("Expected 24 planned NOT_RUN cases")

    def test_invalid_server_source_anchor_rejected(self):
        self.change(MATRIX, lambda d: d["server_snapshot"]["anchors"][0].update(git_blob_sha="bogus"))
        self.reject("Invalid Server Git blob anchor")


if __name__ == "__main__":
    unittest.main()
