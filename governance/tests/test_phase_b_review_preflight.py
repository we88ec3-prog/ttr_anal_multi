"""S00 Phase B submission preflight: integrity only, not a native verifier."""
import hashlib
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from phase_b_review_preflight import evaluate, markdown  # noqa: E402

FILES = [
    "research/requests/index.json", "design/gaps/index.json",
    "spec/spec-index.json", "conformance/test-index.json",
    "conformance/contract-coverage.json", "governance/s00-roadmap.json",
    "shared/targets.json",
]


def blob(data):
    return hashlib.sha1(b"blob " + str(len(data)).encode() + b"\x00" + data).hexdigest()


class SubmissionPreflightTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        for name in FILES:
            dst = self.root / name
            dst.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / name, dst)

    def update(self, name, fn):
        path = self.root / name
        value = json.loads(path.read_text(encoding="utf-8"))
        fn(value)
        path.write_text(json.dumps(value, ensure_ascii=False), encoding="utf-8")

    def submitted(self, state="SUBMITTED", path="research/handoffs/synthetic.md",
                  reported_blob=None, content=b"synthetic-only research"):
        report = self.root / path
        if ".." not in path and not path.startswith("/"):
            report.parent.mkdir(parents=True, exist_ok=True)
            report.write_bytes(content)
        def edit(data):
            record = next(x for x in data["items"] if x["id"] == "RR-0001")
            record["dispatch"]["state"] = state
            record["dispatch"]["submission"] = {
                "report_path": path,
                "report_blob_sha": reported_blob or blob(content),
            }
        self.update("research/requests/index.json", edit)

    def test_baseline_no_artifacts_or_fake_approval(self):
        result = evaluate(self.root)
        self.assertEqual(result["errors"], [])
        self.assertEqual(result["summary"]["selected"], 8)
        self.assertEqual(result["summary"]["not_submitted"], 8)
        self.assertEqual(result["summary"]["pending_manual_review"], 0)
        self.assertTrue(all(row["mechanical_preflight"] == "NOT_SUBMITTED" for row in result["items"]))

    def test_exact_blob_is_reviewable_not_approved(self):
        self.submitted()
        result = evaluate(self.root, rr_id="RR-0001")
        self.assertEqual(result["errors"], [])
        self.assertEqual(result["summary"]["pending_manual_review"], 1)
        row = result["items"][0]
        self.assertEqual(row["mechanical_preflight"], "ARTIFACT_PRESENT_FOR_MANUAL_REVIEW")
        self.assertEqual(row["direct_specs"][0]["maturity"], "DRAFT")
        self.assertEqual(row["tests"][0]["status"], "OFFLINE_SYNTHETIC")
        self.assertIn("does not establish native", markdown(result).lower())
        self.assertIn("UNKNOWN:", markdown(result))
        self.assertIn("resolution:", markdown(result))
        self.assertIn("facets:", markdown(result))

    def test_blob_tampering_is_detected(self):
        self.submitted(reported_blob="f" * 40)
        result = evaluate(self.root, rr_id="RR-0001")
        self.assertEqual(result["summary"]["invalid_submissions"], 1)
        self.assertTrue(any("Git blob SHA mismatch" in x for x in result["errors"]))

    def test_path_escape_is_rejected(self):
        self.submitted(path="../../outside.md")
        result = evaluate(self.root, rr_id="RR-0001")
        self.assertTrue(any("unsafe" in x for x in result["errors"]))

    def test_cross_version_scope_is_not_assumed(self):
        r = evaluate(self.root, rr_id="RR-0001", version="tc")
        self.assertEqual(r["summary"]["selected"], 0)
        self.assertTrue(any("not found in selected Task/version" in x for x in r["errors"]))

    def test_unknown_rr_is_not_invented(self):
        r = evaluate(self.root, rr_id="RR-9999")
        self.assertTrue(any("not found in selected" in x for x in r["errors"]))

    def test_decided_rr_does_not_automatically_approve_spec(self):
        self.submitted(state="ACCEPTED")
        row = evaluate(self.root, rr_id="RR-0001")["items"][0]
        self.assertEqual(row["mechanical_preflight"], "RECORDED_DECISION_NOT_SPEC_APPROVAL")
        self.assertTrue(all(x["maturity"] == "DRAFT" for x in row["direct_specs"]))

    def test_non_submitted_state_with_spurious_artifact_is_not_a_review(self):
        self.submitted(state="CLAIMED")
        r = evaluate(self.root, rr_id="RR-0001")
        self.assertEqual(r["summary"]["pending_manual_review"], 0)
        self.assertEqual(r["items"][0]["mechanical_preflight"], "NOT_SUBMITTED")

    def test_worklist_scope_is_specific_not_all_milestone_specs(self):
        self.submitted()
        auth = evaluate(self.root, rr_id="RR-0003")
        self.assertEqual(auth["errors"], [])
        self.assertEqual([x["id"] for x in auth["items"][0]["direct_specs"]],
                         ["SPEC-AUTH-0001", "SPEC-FLOW-0001"])
        self.assertTrue(all(x["id"] != "SPEC-NET-0001" for x in auth["items"][0]["direct_specs"]))

    def test_all_index_bytes_remain_unchanged(self):
        initial = {p: (self.root / p).read_bytes() for p in FILES}
        _ = evaluate(self.root)
        self.assertEqual(initial, {p: (self.root / p).read_bytes() for p in FILES})


if __name__ == "__main__":
    unittest.main()
