import hashlib, json, pathlib, tempfile, unittest
from bulk_integrity_audit import audit

SHA = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
class TestAudit(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = pathlib.Path(self.tmp.name)
        self.target = self.root / "kr-bulk-roy" / SHA
        self.target.mkdir(parents=True)
        (self.target / "functions").mkdir()
        (self.target / "raw").mkdir()
        (self.target / "functions/a.c").write_bytes(b"hello")
        (self.target / "raw/a.json").write_bytes(b"{}")
        self.row = dict(address="0x401000", status="ok", source_sha256=SHA,
            pseudocode_path="functions/a.c", pseudocode_sha256=hashlib.sha256(b"hello").hexdigest(),
            batch_path="raw/a.json", batch_sha256=hashlib.sha256(b"{}").hexdigest())
    def tearDown(self):
        self.tmp.cleanup()
    def write(self, *rows):
        (self.target / "index.jsonl").write_text("".join(
            (json.dumps(r) if not isinstance(r, str) else r) + "\n" for r in rows))
    def test_clean(self):
        self.write(self.row)
        result = audit(self.root, SHA)
        self.assertEqual(result["unique_addresses"], 1)
        self.assertEqual(result["counts"]["files_checked"], 2)
        self.assertFalse(result["exceptions"])
    def test_duplicate(self):
        self.write(self.row, self.row)
        self.assertEqual(audit(self.root, SHA)["counts"]["issue_duplicate_address"], 1)
    def test_invalid_json(self):
        self.write(self.row, "{bad")
        self.assertEqual(audit(self.root, SHA)["counts"]["issue_invalid_json"], 1)
    def test_hash_mismatch(self):
        self.write(dict(self.row, pseudocode_sha256="0"*64))
        self.assertEqual(audit(self.root, SHA)["counts"]["issue_hash_mismatch"], 1)
    def test_path_escape(self):
        self.write(dict(self.row, pseudocode_path="../../../../outside"))
        self.assertEqual(audit(self.root, SHA)["counts"]["issue_path_escape"], 1)
    def test_missing(self):
        self.write(dict(self.row, pseudocode_path="functions/missing.c"))
        self.assertEqual(audit(self.root, SHA)["counts"]["issue_missing_file"], 1)
    def test_invalid_digest_format(self):
        self.write(dict(self.row, pseudocode_sha256="z"*64))
        self.assertEqual(audit(self.root, SHA)["counts"]["issue_bad_reference"], 1)
    def test_missing_pseudocode_reference(self):
        item = dict(self.row)
        del item["pseudocode_path"]
        self.write(item)
        self.assertEqual(audit(self.root, SHA)["counts"]["issue_missing_pseudocode_reference"], 1)
    def test_ambiguous_evidence_reference(self):
        self.write(dict(self.row, seed_evidence="seed.json", seed_evidence_sha256="0"*64))
        self.assertEqual(audit(self.root, SHA)["counts"]["issue_ambiguous_evidence_reference"], 1)
    def test_duplicate_conflict_flag(self):
        self.write(self.row, dict(self.row, pseudocode_sha256="0"*64))
        issues = audit(self.root, SHA)["exceptions"]
        self.assertFalse(next(x for x in issues if x["kind"] == "duplicate_address")["identical"])
    def test_exception_truncation(self):
        self.write(self.row, self.row, self.row)
        result = audit(self.root, SHA, max_exceptions=1)
        self.assertEqual(len(result["exceptions"]), 1)
        self.assertTrue(result["exceptions_truncated"])
        self.assertEqual(result["issues_total"], 2)
    def test_invalid_address_rejected(self):
        self.write(dict(self.row, address="INVALID"))
        result = audit(self.root, SHA)
        self.assertEqual(result["counts"]["issue_invalid_address"], 1)
    def test_source_sha_mismatch(self):
        self.write(dict(self.row, source_sha256="0"*64))
        self.assertEqual(audit(self.root, SHA)["counts"]["issue_source_sha_mismatch"], 1)
    def test_duplicate_identical_flag(self):
        self.write(self.row, self.row)
        issues = audit(self.root, SHA)["exceptions"]
        self.assertTrue(next(x for x in issues if x["kind"] == "duplicate_address")["identical"])
if __name__ == "__main__":
    unittest.main()
