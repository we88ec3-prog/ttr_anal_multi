import json,pathlib,tempfile,unittest
from kr_bulk_preflight import SHA,check
class PreflightV2Tests(unittest.TestCase):
 def setUp(self):
  self.tmp=tempfile.TemporaryDirectory();self.root=pathlib.Path(self.tmp.name);self.base=self.root/'kr-bulk-roy'/SHA;self.base.mkdir(parents=True)
 def tearDown(self):self.tmp.cleanup()
 def prep(self,rows):
  (self.base/'functions').mkdir();(self.base/'raw').mkdir()
  (self.base/'index.jsonl').write_text(''.join(json.dumps(x)+'\n' if not isinstance(x,str) else x+'\n' for x in rows))
 def row(self,addr='0x401000'):return {'address':addr,'source_sha256':SHA,'status':'ok'}
 def test_missing(self):self.assertEqual(check(self.root)['status'],'BLOCKED_NO_COMPLETE_INDEX')
 def test_missing_directory(self):
  (self.base/'index.jsonl').write_text('{}\n');self.assertEqual(check(self.root)['status'],'BLOCKED_MISSING_DIRECTORY')
 def test_empty(self):self.prep([]);self.assertEqual(check(self.root)['status'],'BLOCKED_EMPTY_INDEX')
 def test_valid(self):
  self.prep([self.row()]);self.assertTrue(check(self.root,1)['ready_for_full_audit'])
 def test_incomplete_rows(self):self.prep([self.row()]);self.assertEqual(check(self.root)['status'],'BLOCKED_UNEXPECTED_ROW_COUNT')
 def test_duplicate(self):self.prep([self.row(),self.row()]);self.assertEqual(check(self.root,2)['duplicate_addresses'],1)
 def test_invalid_json(self):self.prep([self.row(),'{bad']);self.assertEqual(check(self.root,2)['malformed_rows'],1)
 def test_source_mismatch(self):self.prep([dict(self.row(),source_sha256='bad')]);self.assertEqual(check(self.root,1)['source_sha_mismatch'],1)
 def test_address_mismatch(self):self.prep([self.row('INVALID')]);self.assertEqual(check(self.root,1)['invalid_addresses'],1)
if __name__=='__main__':unittest.main()
