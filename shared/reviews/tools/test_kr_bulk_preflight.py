import pathlib
import tempfile
import unittest
from kr_bulk_preflight import SHA, check

class PreflightTests(unittest.TestCase):
    def setUp(self):
        self.tmp = tempfile.TemporaryDirectory()
        self.root = pathlib.Path(self.tmp.name)
        self.base = self.root / 'kr-bulk-roy' / SHA
        self.base.mkdir(parents=True)
    def tearDown(self):
        self.tmp.cleanup()
    def test_missing_index(self):
        self.assertEqual(check(self.root)['status'], 'BLOCKED_NO_COMPLETE_INDEX')
    def test_missing_directories(self):
        (self.base / 'index.jsonl').write_text('{}\n')
        self.assertEqual(check(self.root)['status'], 'BLOCKED_MISSING_DIRECTORY')
    def test_empty_index(self):
        (self.base / 'index.jsonl').touch()
        (self.base / 'functions').mkdir()
        (self.base / 'raw').mkdir()
        self.assertEqual(check(self.root)['status'], 'BLOCKED_EMPTY_INDEX')
    def test_present_index(self):
        (self.base / 'index.jsonl').write_text('{}\n')
        (self.base / 'functions').mkdir()
        (self.base / 'raw').mkdir()
        result = check(self.root)
        self.assertTrue(result['ready_for_full_audit'])
        self.assertEqual(result['index_bytes'], 3)
        self.assertEqual(len(result['index_sha256']), 64)
        self.assertEqual(result['status'], 'PREFLIGHT_ONLY_READY_FOR_FULL_AUDIT')

if __name__ == '__main__':
    unittest.main()
