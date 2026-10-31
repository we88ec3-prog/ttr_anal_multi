"""S00 Iteration39 regression: native-gated login receive must not be silently marked complete."""
from __future__ import annotations

import json
import shutil
import sys
import tempfile
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "governance"))
from check_s00_iteration39 import evaluate  # noqa: E402

FILES = [
    "governance/s00-iterations/S00-ITERATION-39-C04-LOGIN-RECEIVE-GATES.json",
    "governance/s00-iterations/S00-20261101-ITERATION-39-C04-LOGIN-RECEIVE-IMPLEMENTATION-CONTRACT.md",
    "design/requirements/index.json",
    "research/requests/index.json",
    "design/gaps/index.json",
    "shared/targets.json",
]

class Iteration39Tests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        for name in FILES:
            destination = self.root / name
            destination.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(ROOT / name, destination)

    def mutate(self, callback):
        path = self.root / FILES[0]
        doc = json.loads(path.read_text(encoding="utf-8"))
        callback(doc)
        path.write_text(json.dumps(doc, ensure_ascii=False), encoding="utf-8")

    def test_baseline_consistent_and_source_gated(self):
        checked = evaluate(self.root)
        self.assertEqual(checked["errors"], [])
        self.assertEqual(checked["summary"]["gates"], 18)
        self.assertEqual(checked["summary"]["stages"], 4)
        self.assertIs(checked["summary"]["native_adapter_enabled"], False)

    def test_original_client_native_pass_not_self_certified(self):
        self.mutate(lambda d: d["gates"][14].update(status="PASS"))
        self.assertTrue(any("cannot be marked passed" in s for s in evaluate(self.root)["errors"]))

    def test_unregistered_rr_rejected(self):
        self.mutate(lambda d: d["reused_rrs"].append("RR-9999"))
        self.assertTrue(any("unknown ID" in s for s in evaluate(self.root)["errors"]))

    def test_client_build_sha_cannot_be_silently_changed(self):
        self.mutate(lambda d: d.update(client_bin_sha256="0" * 64))
        self.assertTrue(any("target does not match" in s for s in evaluate(self.root)["errors"]))

    def test_no_unreviewed_native_enablement(self):
        self.mutate(lambda d: d.update(native_adapter_enabled=True))
        self.assertTrue(any("must remain false" in s for s in evaluate(self.root)["errors"]))

    def test_gate_count_mismatch_rejected(self):
        self.mutate(lambda d: d["gates"].pop())
        self.assertTrue(any("exactly eighteen gates" in s for s in evaluate(self.root)["errors"]))

    def test_handoff_doc_required(self):
        (self.root / FILES[1]).unlink()
        self.assertTrue(any("inputs unavailable" in s for s in evaluate(self.root)["errors"]))

if __name__ == "__main__":
    unittest.main()
