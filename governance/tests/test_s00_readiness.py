"""Roadmap checks do not change or promote S00 maturity."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_readiness import assess  # noqa:E402
from s00_test_fixtures import reset_queued_fixture


PATHS = [
    "governance/s00-roadmap.json",
    "spec/spec-index.json",
    "design/gaps/index.json",
    "research/requests/index.json",
    "conformance/test-index.json",
    "shared/targets.json",
]


class ReadinessTests(unittest.TestCase):
    def setUp(self):
        self.temporary = tempfile.TemporaryDirectory()
        self.addCleanup(self.temporary.cleanup)
        self.root = Path(self.temporary.name)
        for rel in PATHS:
            f = self.root / rel
            f.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / rel, f)

        reset_queued_fixture(self.root)

    def overwrite(self, rel, mutate):
        path = self.root / rel
        data = json.loads(path.read_text(encoding="utf-8"))
        mutate(data)
        path.write_text(json.dumps(data, ensure_ascii=False), encoding="utf-8")

    def test_current_roadmap_is_structurally_consistent_but_not_ready(self):
        data = assess(self.root)
        self.assertEqual(data["errors"], [], data["errors"])
        plan = json.loads((self.root / "governance/s00-roadmap.json").read_text(encoding="utf-8"))
        self.assertEqual(len(data["packages"]), len(plan["milestones"]))
        tutorial = next(x for x in data["packages"] if x["id"] == "C-TUTORIAL-DOMAIN")
        self.assertEqual(tutorial["phase"], "C")
        self.assertEqual(tutorial["status"], "BLOCKED")
        self.assertIn("EXTERNAL_REVIEW_REQUIRED", tutorial["blockers"])
        self.assertEqual(data["summary"]["specs"], 7)
        gaps = json.loads((self.root / "design/gaps/index.json").read_text(encoding="utf-8"))["items"]
        requests = json.loads((self.root / "research/requests/index.json").read_text(encoding="utf-8"))["items"]
        self.assertTrue({"GAP-CHAR-0002", "GAP-CHAR-0003"}.issubset({g["id"] for g in gaps}))
        self.assertTrue({"RR-0009", "RR-0010"}.issubset({r["id"] for r in requests}))
        self.assertEqual(data["summary"]["gaps_open"], sum(g["status"] != "RESOLVED" for g in gaps))
        self.assertEqual(data["summary"]["requests_queued"], len(requests))
        self.assertEqual(data["summary"]["tests_offline_synthetic"], 6)
        self.assertTrue(all(x["status"] == "BLOCKED" for x in data["packages"]))
        self.assertTrue(any("OFFLINE_SYNTHETIC_ONLY" in b for b in data["packages"][0]["blockers"]))

    def test_roadmap_detects_missing_rr_and_unassigned_owner(self):
        def change(data):
            data["milestones"][0]["rr_ids"].append("RR-9999")
            data["milestones"][0]["research_owners"] = []
        self.overwrite("governance/s00-roadmap.json", change)
        errors = assess(self.root)["errors"]
        self.assertTrue(any("unresolved rr_ids RR-9999" in e for e in errors))
        self.assertTrue(any("missing origin research owner" in e for e in errors))

    def test_roadmap_detects_cycle(self):
        def change(data):
            data["milestones"][0]["depends_on"].append("B-CONTRACT")
        self.overwrite("governance/s00-roadmap.json", change)
        self.assertTrue(any("dependency cycle" in e for e in assess(self.root)["errors"]))

    def test_wrong_client_sha_is_rejected(self):
        self.overwrite("governance/s00-roadmap.json", lambda data: data.update(target_sha256="0"*64))
        self.assertTrue(any("Client SHA" in e for e in assess(self.root)["errors"]))

    def test_roadmap_permutation_preserves_blocker_decisions(self):
        before = assess(self.root)
        self.overwrite("governance/s00-roadmap.json",
                       lambda data: data["milestones"].reverse())
        after = assess(self.root)
        self.assertEqual(after["errors"], [], after["errors"])
        self.assertEqual(after["packages"], before["packages"])
        self.assertEqual(after["summary"], before["summary"])

    def test_unreviewed_test_status_remains_blocked(self):
        self.overwrite("conformance/test-index.json",
                       lambda data: data["items"][0].update(status="FORGED_PASSED"))
        report = assess(self.root)
        self.assertTrue(any("UNREVIEWED_TEST_PROVENANCE" in reason
                            for pkg in report["packages"]
                            for reason in pkg["blockers"]))
        self.assertEqual(report["summary"]["packages_blocked"], len(report["packages"]))

if __name__ == "__main__":
    unittest.main()
