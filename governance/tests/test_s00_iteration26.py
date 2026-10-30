"""Iteration26 only: draft gate provenance / deliberate non-promotion regression."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_iteration26 import PLAN, CASES, SRC17, SRC18, validate  # noqa:E402

FILES = [
    PLAN, CASES, SRC17, SRC18,
    "shared/targets.json", "research/requests/index.json",
    "design/gaps/index.json", "spec/spec-index.json",
]


class Iteration26Tests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        for path in FILES:
            dest = self.root / path
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(ROOT / path, dest)

    def mutate(self, path, callback):
        fp = self.root / path
        doc = json.loads(fp.read_text(encoding="utf-8"))
        callback(doc)
        fp.write_text(json.dumps(doc, ensure_ascii=False, indent=2), encoding="utf-8")

    def assert_rejects(self, needle):
        errors = validate(self.root)
        self.assertTrue(any(needle in err for err in errors), errors)

    def test_current_overlay_valid_but_not_a_runtime_verdict(self):
        self.assertEqual(validate(self.root), [])
        plan = json.loads((self.root / PLAN).read_text(encoding="utf-8"))
        self.assertEqual(len(plan["gates"]), 19)
        self.assertTrue(all(not x["native_compatibility_confirmed"] for x in plan["gates"]))
        self.assertTrue(all(not x["domain_test_executed"] for x in plan["gates"]))

    def test_source_gate_state_promotion_rejected(self):
        self.mutate(PLAN, lambda d: d["gates"][0].update(original_evidence_state="NATIVE_VERIFIED"))
        self.assert_rejects("source evidence state altered/promoted")

    def test_source_blob_mismatch_rejected(self):
        self.mutate(PLAN, lambda d: d["source_gate_blobs"].update({SRC18: "0" * 40}))
        self.assert_rejects("source Git blob SHA mismatch")

    def test_missing_original_blocker_rejected(self):
        self.mutate(PLAN, lambda d: d["gates"][3].update(source_blocker="resolved"))
        self.assert_rejects("original source blocker altered")

    def test_unknown_research_request_rejected(self):
        self.mutate(PLAN, lambda d: d["gates"][0]["existing_rr_refs"].append("RR-9999"))
        self.assert_rejects("unresolved existing_rr_refs")

    def test_unapproved_policy_cannot_be_pretended_approved(self):
        self.mutate(PLAN, lambda d: d["gates"][0].update(policy_status="APPROVED"))
        self.assert_rejects("Server policy not explicitly PROPOSED")

    def test_original_client_unearned_native_proof_rejected(self):
        self.mutate(PLAN, lambda d: d["gates"][0].update(native_compatibility_confirmed=True))
        self.assert_rejects("cannot claim executed/compatible")

    def test_domain_test_unearned_pass_rejected(self):
        self.mutate(PLAN, lambda d: d["gates"][0].update(domain_test_executed=True))
        self.assert_rejects("cannot claim executed/compatible")

    def test_native_adapter_must_stay_off(self):
        self.mutate(PLAN, lambda d: d["gates"][0].update(handoff="NATIVE_ADAPTER_ON"))
        self.assert_rejects("original Client adapter must remain OFF")

    def test_duplicate_gate_rejected(self):
        self.mutate(PLAN, lambda d: d["gates"][1].update(id="E17-A"))
        self.assert_rejects("expected 19 unique")

    def test_unproven_planning_dependency_cycle_rejected(self):
        self.mutate(PLAN, lambda d: d["gates"][0].update(planning_dependencies=["E17-B"]))
        self.assert_rejects("planning dependency cycle")

    def test_missing_planned_test_case_rejected(self):
        path = self.root / CASES
        path.write_text(path.read_text(encoding="utf-8").replace("| I26-T18 |", "| REMOVED-T18 |"),
                        encoding="utf-8")
        self.assert_rejects("expected 18 unique")

    def test_source_plan_mutation_rejected(self):
        self.mutate(SRC17, lambda d: d["gates"][0].update(evidence_state="NATIVE_VERIFIED"))
        self.assert_rejects("source Git blob SHA mismatch")


if __name__ == "__main__":
    unittest.main()
