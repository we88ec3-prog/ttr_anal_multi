"""S00 Phase B worklist remains source-derived, scoped and read-only."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from phase_b_worklist import evaluate, markdown  # noqa: E402

FILES = [
    "research/requests/index.json", "design/gaps/index.json",
    "spec/spec-index.json", "conformance/test-index.json",
    "conformance/contract-coverage.json",
    "governance/s00-roadmap.json", "shared/targets.json",
]


class PhaseBWorklistTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        for rel in FILES:
            dest = self.root / rel
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / rel, dest)

    def mutate(self, name, operation):
        dest = self.root / name
        j = json.loads(dest.read_text(encoding="utf-8"))
        operation(j)
        dest.write_text(json.dumps(j, ensure_ascii=False), encoding="utf-8")

    def test_baseline_eight_queued_no_submissions(self):
        result = evaluate(self.root)
        self.assertEqual(result["errors"], [])
        self.assertEqual(result["summary"]["selected_requests"], 8)
        self.assertEqual(result["summary"]["new_submissions"], 0)
        self.assertEqual(result["summary"]["ready_to_be_claimed"], 8)
        self.assertEqual(result["summary"]["blocked_phase_b_packages"], 5)
        self.assertEqual({x["rr_id"] for x in result["requests"]},
                         {f"RR-{n:04}" for n in range(1, 9)})
        self.assertTrue(all(not x["has_submission"] for x in result["requests"]))
        self.assertEqual(result["summary"]["research_backlog_without_milestone"], 1)
        self.assertEqual(next(x for x in result["requests"] if x["rr_id"] == "RR-0006")["delivery_mapping"],
                         "RESEARCH_BACKLOG")
        self.assertTrue(all(x["blocked_milestones"] for x in result["requests"]
                            if x["delivery_mapping"] == "MILESTONE"))

    def test_task_filter_keeps_correct_owners_and_scope(self):
        t02 = evaluate(self.root, task="T02")
        t03 = evaluate(self.root, task="T03")
        self.assertEqual(t02["errors"], [])
        self.assertEqual(t03["errors"], [])
        self.assertEqual({x["rr_id"] for x in t02["requests"]},
                         {"RR-0001", "RR-0004", "RR-0005", "RR-0006", "RR-0007"})
        self.assertEqual({x["rr_id"] for x in t03["requests"]},
                         {"RR-0002", "RR-0003", "RR-0008"})
        self.assertTrue(all(x["client_version"] == "kr" for x in t03["requests"]))
        self.assertTrue(all("COV-" in ",".join(x["coverage_ids"]) for x in t02["requests"]))

        # The broad B-CONTRACT milestone must not make T03 auth touch NET/CHAR.
        auth = next(x for x in t03["requests"] if x["rr_id"] == "RR-0003")
        self.assertEqual(auth["spec_ids"], ["SPEC-AUTH-0001", "SPEC-FLOW-0001"])
        self.assertIn("SPEC-NET-0001", auth["milestone_spec_ids"])
        self.assertNotIn("SPEC-NET-0001", auth["spec_ids"])
        self.assertEqual(auth["test_ids"], ["TEST-AUTH-0001"])

    def test_tc_scope_does_not_inherit_kr_requests(self):
        result = evaluate(self.root, version="tc")
        self.assertEqual(result["errors"], [])
        self.assertEqual(result["requests"], [])
        self.assertEqual(result["summary"]["selected_requests"], 0)

    def test_submitted_goes_before_new_claims_but_is_not_accepted(self):
        self.mutate("research/requests/index.json",
                    lambda d: d["items"][7]["dispatch"].update(
                        state="SUBMITTED", submission={"report_path": "unverified.md"}))
        rows = evaluate(self.root)["requests"]
        self.assertEqual(rows[0]["rr_id"], "RR-0008")
        self.assertEqual(rows[0]["dispatch_state"], "SUBMITTED")
        self.assertTrue(rows[0]["has_submission"])
        self.assertEqual(evaluate(self.root)["summary"]["new_submissions"], 1)
        self.assertIn("review", rows[0]["next_action"].lower())

    def test_corrupt_version_or_missing_gap_is_reported(self):
        self.mutate("research/requests/index.json",
                    lambda d: d["items"][0].update(client_version="tc"))
        errors = evaluate(self.root)["errors"]
        self.assertTrue(any("cross-version GAP" in e for e in errors))
        self.assertTrue(any("coverage version/target mismatch" in e for e in errors))

    def test_unknown_coverage_link_is_rejected(self):
        self.mutate("conformance/contract-coverage.json",
                    lambda d: d["items"][0]["spec_ids"].append("SPEC-NONEXISTENT"))
        self.assertTrue(any("unknown coverage SPEC" in x for x in evaluate(self.root)["errors"]))

    def test_roadmap_row_reorder_keeps_queue_order(self):
        before = [x["rr_id"] for x in evaluate(self.root)["requests"]]
        self.mutate("governance/s00-roadmap.json", lambda d: d["milestones"].reverse())
        result = evaluate(self.root)
        self.assertEqual(result["errors"], [])
        self.assertEqual([x["rr_id"] for x in result["requests"]], before)

    def test_markdown_stays_scope_labeled_and_read_only(self):
        content = markdown(evaluate(self.root, task="T03"))
        self.assertIn("not a claim", content.lower())
        self.assertIn("RR-0008", content)
        self.assertIn("S2C", content)
        self.assertIn("SPEC-", content)

    def test_no_mutation_of_registry_bytes(self):
        before = {p: (self.root / p).read_bytes() for p in FILES}
        _ = evaluate(self.root)
        self.assertEqual(before, {p: (self.root / p).read_bytes() for p in FILES})


if __name__ == "__main__":
    unittest.main()
