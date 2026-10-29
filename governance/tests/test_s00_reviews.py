"""Conservative S00 current-decision review ledger checks."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_reviews import evaluate

PATHS = [
    "governance/reviews/index.json", "research/requests/index.json",
    "shared/targets.json", "spec/spec-index.json",
    "research/claims/index.json", "design/gaps/index.json",
    "conformance/test-index.json",
]

class ReviewLedgerTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.addCleanup(self.tmp.cleanup)
        self.root = Path(self.tmp.name)
        for relative in PATHS:
            target = self.root / relative
            target.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / relative, target)

    def edit(self, path, fn):
        file = self.root / path
        data = json.loads(file.read_text(encoding="utf-8"))
        fn(data)
        file.write_text(json.dumps(data), encoding="utf-8")

    def test_empty_ledger_is_not_a_review(self):
        data = evaluate(self.root)
        self.assertEqual(data["errors"], [])
        self.assertEqual(data["summary"]["review_records"], 0)

    def test_accepted_rr_cannot_lack_review_record(self):
        self.edit("research/requests/index.json", lambda d: d["items"][0]["dispatch"].update(state="ACCEPTED"))
        self.assertTrue(any("requires S00 review ledger" in e for e in evaluate(self.root)["errors"]))

    def test_fake_record_cannot_replace_original_report_or_decision(self):
        self.edit("governance/reviews/index.json", lambda d: d["items"].append({
            "id": "REV-0001", "rr_id": "RR-0001", "decision": "ACCEPTED",
            "actor": "S00", "client_version": "kr",
            "target_sha256": json.loads((self.root / "shared/targets.json").read_text())["kr"]["sha256"],
            "outcome_refs": ["SPEC-NET-0001"],
            "review_path": "governance/reviews/nonexistent.md", "review_blob_sha": "a"*40,
        }))
        errors = evaluate(self.root)["errors"]
        self.assertTrue(any("decision differs" in e for e in errors))
        self.assertTrue(any("missing/unverifiable" in e for e in errors))

    def test_invalid_target_version(self):
        self.edit("governance/reviews/index.json", lambda d: d["items"].append({
            "id": "REV-0001", "rr_id": "RR-0001", "decision": "NEEDS_REVISION",
            "actor": "S00", "client_version": "tc", "target_sha256": "0"*64,
            "outcome_refs": ["SPEC-NET-0001"],
            "review_path": "governance/reviews/nonexistent.md", "review_blob_sha": "a"*40,
        }))
        self.assertTrue(any("version/target mismatch" in e for e in evaluate(self.root)["errors"]))

if __name__ == "__main__":
    unittest.main()
