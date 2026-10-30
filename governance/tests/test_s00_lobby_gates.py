"""Tests for the L00-L08 conservative, read-only lobby requirements matrix."""
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_lobby_gates import assess  # noqa: E402

FILES = [
    "governance/s00-lobby-gates.json",
    "governance/s00-iteration12-lobby-test-plan.json",
    "design/requirements/index.json",
    "research/requests/index.json",
    "design/gaps/index.json",
    "spec/spec-index.json",
    "conformance/test-index.json",
    "shared/targets.json",
]


class LobbyGateTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        for f in FILES:
            p = self.root / f
            p.parent.mkdir(parents=True, exist_ok=True)
            shutil.copyfile(ROOT / f, p)

    def edit(self, path, action):
        f = self.root / path
        doc = json.loads(f.read_text("utf-8"))
        action(doc)
        f.write_text(json.dumps(doc, ensure_ascii=False), "utf-8")

    def test_all_nine_gates_link_all_twelve_unexecuted_scenarios(self):
        out = assess(self.root)
        self.assertEqual(out["errors"], [])
        self.assertEqual(out["summary"]["gates"], 9)
        self.assertEqual(out["summary"]["planned_unexecuted_tests"], 12)
        self.assertEqual([g["id"] for g in out["gates"]],
                         [f"L{k:02d}" for k in range(9)])

    def test_every_gate_stays_blocked_even_if_synthetic_tests_exist(self):
        self.assertEqual({g["state"] for g in assess(self.root)["gates"]}, {"BLOCKED"})

    def test_selection_rr_blocked_is_not_auto_accepted(self):
        g = {g["id"]: g for g in assess(self.root)["gates"]}
        self.assertIn("RR-0002=BLOCKED", g["L05"]["blockers"])
        self.assertIn("RR-0002=BLOCKED", g["L06"]["blockers"])

    def test_ui_ready_is_not_data_record_present(self):
        g = {g["id"]: g for g in assess(self.root)["gates"]}
        self.assertIn("UI_EVENT_TO_RENDER_CHAIN_NOT_PROVEN", g["L07"]["blockers"])

    def test_runtime_only_never_auto_authorized(self):
        g = {g["id"]: g for g in assess(self.root)["gates"]}
        self.assertIn("ORIGINAL_CLIENT_RUNTIME_NOT_AUTHORIZED_OR_OBSERVED", g["L08"]["blockers"])

    def test_unknown_requirement_fails_closed(self):
        self.edit(FILES[0], lambda d: d["gates"][0]["requirement_ids"].append("REQ-9999"))
        self.assertTrue(any("REQ-9999" in e for e in assess(self.root)["errors"]))

    def test_unknown_test_fails_closed(self):
        self.edit(FILES[0], lambda d: d["gates"][2]["test_case_ids"].append("L12-NO"))
        self.assertTrue(any("unknown test" in e for e in assess(self.root)["errors"]))

    def test_mismatched_checkpoint_fails_closed(self):
        self.edit(FILES[1], lambda d: d["cases"][0].update(checkpoint="L07"))
        self.assertTrue(any("mismatched checkpoint" in e for e in assess(self.root)["errors"]))

    def test_pending_runtime_test_cannot_be_demoted_to_synthetic(self):
        self.edit(FILES[1], lambda d: d["cases"][-1].update(level="OFFLINE_SYNTHETIC_PLANNED"))
        self.assertTrue(any("authorization-pending" in e for e in assess(self.root)["errors"]))

    def test_source_version_mismatch_is_a_failure(self):
        self.edit(FILES[0], lambda d: d.update(target_sha256="0"*64))
        self.assertTrue(any("version/SHA" in e for e in assess(self.root)["errors"]))

    def test_synthetic_test_being_labeled_executed_fails_closed(self):
        self.edit(FILES[1], lambda d: d.update(status="TESTS_PASSED"))
        self.assertTrue(any("explicitly unexecuted" in e for e in assess(self.root)["errors"]))

    def test_missing_one_gate_fails_closed(self):
        self.edit(FILES[0], lambda d: d["gates"].pop())
        self.assertTrue(any("exactly L00..L08" in e for e in assess(self.root)["errors"]))

    def test_checker_never_mutates_indices(self):
        before = {f: (self.root / f).read_bytes() for f in FILES}
        _ = assess(self.root)
        self.assertEqual(before, {f: (self.root / f).read_bytes() for f in FILES})


if __name__ == "__main__":
    unittest.main()
