"""Iteration27 non-normative Server C05 work package design is never native proof."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_iteration27 import PLAN, SOURCE, CASES, validate  # noqa:E402

FILES = [
    PLAN, SOURCE, CASES, "shared/targets.json", "design/decisions/index.json",
]


class Iteration27Tests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        for rel in FILES:
            dest = self.root / rel
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(ROOT / rel, dest)

    def change(self, path, fn):
        dest = self.root / path
        j = json.loads(dest.read_text(encoding="utf-8"))
        fn(j)
        dest.write_text(json.dumps(j, ensure_ascii=False, indent=2), encoding="utf-8")

    def reject(self, needle):
        errors = validate(self.root)
        self.assertTrue(any(needle in e for e in errors), errors)

    def test_current_plan_is_structurally_valid_not_executed(self):
        self.assertEqual(validate(self.root), [])
        doc = json.loads((self.root / PLAN).read_text(encoding="utf-8"))
        self.assertEqual(len(doc["packages"]), 9)
        self.assertEqual(len({case for p in doc["packages"] for case in p["synthetic_cases"]}), 18)
        self.assertEqual(doc["governance"]["required_adr_status"], "PROPOSED")

    def test_source_matrix_blob_change_rejected(self):
        self.change(PLAN, lambda d: d["source_matrix"].update(git_blob_sha="a"*40))
        self.reject("source-matrix Git blob changed")

    def test_snapshot_c05_premature_promotion_rejected(self):
        self.change(PLAN, lambda d: d["observed_server_state"].update(C05="CLIENT_COMPATIBLE"))
        self.reject("Server C04/C05 evidence baseline")

    def test_native_adapter_default_on_rejected(self):
        self.change(PLAN, lambda d: d["governance"].update(client_adapter_default_enabled=True))
        self.reject("unsafe formal/native flag")

    def test_no_approval_by_merely_changing_planning_record(self):
        self.change(PLAN, lambda d: d["governance"].update(required_adr_status="APPROVED"))
        self.reject("unapproved ADR or unexecuted")

    def test_original_adr_still_must_be_proposed(self):
        self.change("design/decisions/index.json", lambda d: next(x for x in d["items"] if x["id"]=="ADR-0007").update(status="APPROVED"))
        self.reject("ADR-0007 is not unapproved PROPOSED")

    def test_external_snapshot_not_presented_as_ci_remote_verified(self):
        self.change(PLAN, lambda d: d["server_snapshot"].update(source_access="AUTO_LIVE_VERIFIED"))
        self.reject("must not claim remote Server")

    def test_invented_gate_rejected(self):
        self.change(PLAN, lambda d: d["packages"][1].update(existing_gate_ids=["E17-Z"]))
        self.reject("unresolved Iteration26 native gate")

    def test_duplicate_test_case_workpack_rejected(self):
        self.change(PLAN, lambda d: d["packages"][1].update(synthetic_cases=["I27-T01", "I27-T02"]))
        self.reject("I27 case coverage not exactly one")

    def test_native_workpack_must_be_gated(self):
        self.change(PLAN, lambda d: d["packages"][8].update(mode="DOMAIN_OFFLINE_PROTOTYPE"))
        self.reject("native adapter quarantine missing")

    def test_dependency_cycle_rejected(self):
        self.change(PLAN, lambda d: d["packages"][0].update(depends_on=["S27-W08"]))
        self.reject("dependency cycle")

    def test_invented_server_blob_reference_rejected(self):
        self.change(PLAN, lambda d: d["server_snapshot"]["file_blobs"][0].update(blob_sha="NOT_REAL"))
        self.reject("unsafe/missing Server blob reference")

    def test_missing_acceptance_case_rejected(self):
        dest = self.root / CASES
        dest.write_text(dest.read_text(encoding="utf-8").replace("| I27-T18 |", "| LOST-T18 |"), encoding="utf-8")
        self.reject("expected 18 NOT_RUN")

    def test_changed_source_matrix_detected(self):
        self.change(SOURCE, lambda d: d.update(kind="NORMATIVE"))
        self.reject("source-matrix Git blob changed")

    def test_compromised_server_c03_lease_boundary_rejected(self):
        self.change(PLAN, lambda d: d["observed_server_state"].update(C03="UNVERIFIED"))
        self.reject("C03 verified offline seam missing")


if __name__ == "__main__":
    unittest.main()
