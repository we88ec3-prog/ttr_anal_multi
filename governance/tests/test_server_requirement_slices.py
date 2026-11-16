"""S00 Server slice planning: no fake readiness, no canonical registry mutation."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from server_requirement_slices import assess, markdown  # noqa: E402

FILES = ["governance/s00-requirement-slices.json", "design/requirements/index.json",
         "research/requests/index.json", "design/gaps/index.json",
         "spec/spec-index.json", "shared/targets.json"]


class RequirementSliceTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        for path in FILES:
            to = self.root / path
            to.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / path, to)

    def edit(self, path, fn):
        src = self.root / path
        obj = json.loads(src.read_text(encoding="utf-8"))
        fn(obj)
        src.write_text(json.dumps(obj), encoding="utf-8")

    def test_baseline_reports_separate_lobby_create_and_world(self):
        a = assess(self.root)
        self.assertEqual(a["errors"], [])
        self.assertEqual([r["id"] for r in a["slices"]],
                         ["SLICE-LOBBY", "SLICE-CREATE", "SLICE-ENTER-WORLD"])
        self.assertEqual(a["summary"]["selected"], 3)
        self.assertEqual(a["summary"]["blocked"], 2)
        self.assertEqual(a["summary"]["discovery_required"], 1)

    def test_creation_is_not_fake_existing_requirement(self):
        a = assess(self.root, "SLICE-CREATE")
        self.assertEqual(a["errors"], [])
        row = a["slices"][0]
        self.assertEqual(row["requirement_ids"], [])
        self.assertEqual(row["status"], "DISCOVERY_REQUIRED")
        self.assertEqual(row["context_rr"][0]["state"], "BLOCKED")

    def test_accepted_rr_is_not_full_slice_approval(self):
        row = assess(self.root, "SLICE-LOBBY")["slices"][0]
        self.assertIn({"id": "RR-0005", "state": "ACCEPTED"}, row["blocking_rr"])
        self.assertEqual(row["status"], "BLOCKED")
        self.assertIn("REQ-0002=CANDIDATE", row["blockers"])

    def test_selection_remains_blocked_without_guessing_s2c(self):
        row = assess(self.root, "SLICE-ENTER-WORLD")["slices"][0]
        self.assertIn({"id": "RR-0002", "state": "BLOCKED"}, row["blocking_rr"])
        self.assertIn("GAP-SCENE-0001", row["open_gaps"])
        self.assertEqual(row["status"], "BLOCKED")

    def test_no_approved_runtime_discovery_is_invented(self):
        row = assess(self.root, "SLICE-LOBBY")["slices"][0]
        registry = json.loads((self.root / "design/requirements/index.json").read_text(encoding="utf-8"))
        self.assertEqual(row["discovery_channels"], [
            "CODE_ANALYSIS", "GAME_RUNTIME_OBSERVATION", "PLAYER_ADMIN_REQUEST",
        ])
        # An authorized modified-copy transport failure must not approve the
        # original Client contract or remove the actual lobby blockers.
        self.assertEqual(row["status"], "BLOCKED")
        self.assertIn("REQ-0001=CANDIDATE", row["blockers"])
        req = next(r for r in registry["items"] if r["id"] == "REQ-0001")
        runtime = next(d for d in req["discoveries"] if d["channel"] == "GAME_RUNTIME_OBSERVATION")
        self.assertEqual(runtime["tested_build_kind"], "MODIFIED_WORKING_COPY_NOT_ORIGINAL_CLIENT")
        self.assertNotEqual(runtime["tested_executable_sha256"], runtime["target_sha256"])

    def test_unknown_ids_fail_even_when_status_blocked(self):
        self.edit(FILES[0], lambda d: d["slices"][0]["requirement_ids"].append("REQ-9000"))
        self.assertTrue(any("REQ-9000" in e for e in assess(self.root)["errors"]))

    def test_mismatched_client_version_fails(self):
        self.edit(FILES[0], lambda d: d.update(client_version="tc"))
        self.assertTrue(any("target SHA/version mismatch" in e for e in assess(self.root)["errors"]))
        self.assertTrue(any("cross-version" in e for e in assess(self.root)["errors"]))

    def test_dependency_cycle_fails_closed(self):
        self.edit(FILES[0], lambda d: d["slices"][0].update(depends_on=["SLICE-CREATE"]))
        self.assertTrue(any("cycle" in e for e in assess(self.root)["errors"]))

    def test_stable_topology_when_plan_rows_reordered(self):
        first = [r["id"] for r in assess(self.root)["slices"]]
        self.edit(FILES[0], lambda d: d["slices"].reverse())
        self.assertEqual(first, [r["id"] for r in assess(self.root)["slices"]])

    def test_duplicate_rr_roles_rejected(self):
        self.edit(FILES[0], lambda d: d["slices"][0]["context_rr_ids"].append("RR-0001"))
        self.assertTrue(any("repeats RR" in e for e in assess(self.root)["errors"]))

    def test_markdown_has_evidence_caveat_and_manual_review(self):
        txt = markdown(assess(self.root))
        self.assertIn("not silently treated", txt)
        self.assertIn("DISCOVERY_REQUIRED", txt)
        self.assertIn("no original Client execution", txt)

    def test_checker_does_not_modify_source_files(self):
        before = {p: (self.root / p).read_bytes() for p in FILES}
        _ = assess(self.root)
        self.assertEqual(before, {p: (self.root / p).read_bytes() for p in FILES})


if __name__ == "__main__":
    unittest.main()
