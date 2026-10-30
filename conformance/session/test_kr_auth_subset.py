import json
import unittest
from pathlib import Path
from kr_auth_subset import inspect_local_auth
DATA=json.loads(Path(__file__).with_name("kr-auth-vectors.json").read_text(encoding="utf-8"))
class AuthShapeTests(unittest.TestCase):
    def test_e8_and_0f_synthetic_slot_geometry(self):
        self.assertEqual(DATA["provenance"],"SYNTHETIC_STATIC_DERIVED")
        for item in DATA["cases"]:
            with self.subTest(item=item["id"]):
                payload=bytes.fromhex(item["raw_hex"])
                self.assertEqual(len(payload),item["expected_length"])
                o=inspect_local_auth(payload)
                self.assertEqual(o.command,item["command"])
                self.assertEqual((len(o.slot_a),len(o.slot_b)),(item["first"],item["second"]))
    def test_outside_subset_rejected_by_harness(self):
        e8=bytes.fromhex(DATA["cases"][0]["raw_hex"])
        with self.assertRaises(ValueError):inspect_local_auth(e8[:-1])
        f=bytearray(bytes.fromhex(DATA["cases"][1]["raw_hex"]))
        f[210]=0
        with self.assertRaises(ValueError):inspect_local_auth(bytes(f))
if __name__=="__main__":unittest.main()
