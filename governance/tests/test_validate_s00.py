"""S00 validator regression tests: valid pilot and deliberate invalid mutations."""
import copy
import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from validate_s00 import FILES, validate  # noqa: E402

class S00IndexTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        paths = [value[0] for value in FILES.values()]
        paths += ["shared/targets.json", "spec/protocol/SPEC-NET-0001.md",
                  "spec/session-account/SPEC-CHAR-0001.md",
                  "kr/tasks/T02/task.json", "kr/tasks/T03/task.json"]
        for path in paths:
            dest = self.root / path
            dest.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(ROOT / path, dest)

    def edit(self, path, change):
        p = self.root / path
        obj = json.loads(p.read_text(encoding="utf-8"))
        change(obj)
        p.write_text(json.dumps(obj, ensure_ascii=False), encoding="utf-8")

    def test_pilot_indexes_valid(self):
        self.assertEqual(validate(self.root), [])

    def test_missing_gap_rejected(self):
        self.edit("spec/spec-index.json", lambda d: d["items"][0]["gap_ids"].append("GAP-FAKE"))
        self.assertTrue(any("unresolved" in x for x in validate(self.root)))

    def test_unproven_stable_rejected(self):
        self.edit("spec/spec-index.json", lambda d: d["items"][0].update({"maturity":"STABLE"}))
        self.assertTrue(any("STABLE requires" in x for x in validate(self.root)))

    def test_cross_version_target_rejected(self):
        self.edit("spec/spec-index.json", lambda d: d["items"][0].update({"client_version":"tc"}))
        self.assertTrue(any("target SHA differs" in x for x in validate(self.root)))

if __name__ == "__main__":
    unittest.main()
