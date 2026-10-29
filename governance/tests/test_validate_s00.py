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

    def test_intake_invalid_source_sha_rejected(self):
        def add(d):
            d["items"].append({
                "id":"SRC-0001", "client_version":"kr",
                "target_sha256":"9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91",
                "source_file":"kr/tasks/T02/task.json", "source_blob_sha":"0"*40,
                "source_sha256":"0"*64, "integration_status":"REGISTERED", "claim_ids":[],
            })
        self.edit("research/intake/index.json", add)
        self.assertTrue(any("source SHA256 mismatch" in x for x in validate(self.root)))

    def test_intake_promotion_without_claim_rejected(self):
        def add(d):
            import hashlib
            s=(self.root/"kr/tasks/T02/task.json").read_bytes()
            d["items"].append({
                "id":"SRC-0001", "client_version":"kr",
                "target_sha256":"9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91",
                "source_file":"kr/tasks/T02/task.json",
                "source_blob_sha":hashlib.sha1(b"blob "+str(len(s)).encode()+b"\\x00"+s).hexdigest(),
                "source_sha256":hashlib.sha256(s).hexdigest(),
                "integration_status":"SPEC_CONSUMABLE","claim_ids":[],
            })
        self.edit("research/intake/index.json", add)
        self.assertTrue(any("promoted source must" in x for x in validate(self.root)))

    def test_cross_version_target_rejected(self):
        self.edit("spec/spec-index.json", lambda d: d["items"][0].update({"client_version":"tc"}))
        self.assertTrue(any("target SHA differs" in x for x in validate(self.root)))

if __name__ == "__main__":
    unittest.main()
