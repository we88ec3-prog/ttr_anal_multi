import json
import unittest
from pathlib import Path
from kr_roster_subset import HEADER,RECORD,UnsafeRoster,parse_synthetic_roster
DATA=json.loads(Path(__file__).with_name("kr-roster-vectors.json").read_text(encoding="utf-8"))
class RosterShapeTests(unittest.TestCase):
    def test_synthetic_geometry(self):
        self.assertEqual(DATA["provenance"],"SYNTHETIC_STATIC_DERIVED")
        raw=bytes.fromhex(DATA["header_hex"]+DATA["record_hex"])
        self.assertEqual(len(raw),118)
        arr,tail=parse_synthetic_roster(raw)
        self.assertEqual(len(arr),1)
        self.assertEqual(tail,b"")
        for name in ("name","offset","raw_id","byte_2f","byte_30","dword_2a","dword_31"):
            self.assertEqual(getattr(arr[0],name),DATA["expected"][name])
    def test_only_complete_records(self):
        h=bytes.fromhex(DATA["header_hex"])
        r=bytes.fromhex(DATA["record_hex"])
        self.assertEqual((len(h),len(r)),(HEADER,RECORD))
        self.assertEqual(parse_synthetic_roster(h),([],b""))
        a,tail=parse_synthetic_roster(h+r+b"\x7f")
        self.assertEqual(len(a),1)
        self.assertEqual(tail,b"\x7f")
    def test_strict_harness_is_not_native_error_rule(self):
        with self.assertRaises(UnsafeRoster):parse_synthetic_roster(b"\x02\x00")
        r=bytearray(bytes.fromhex(DATA["record_hex"]))
        for i in range(0,0x2A,2):r[i:i+2]=b"A\x00"
        with self.assertRaises(UnsafeRoster):parse_synthetic_roster(bytes.fromhex(DATA["header_hex"])+r)
if __name__=="__main__":unittest.main()
