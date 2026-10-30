"""Synthetic-only KR auth 0x13/0x7A group cursor/extent model.

Does NOT execute or emulate original Client. The bounds check below is a
conservative independent fixture-parser policy, not an attributed native guard.
"""
import json
import unittest
from pathlib import Path

VECTORS = Path(__file__).with_name("kr-auth-group-cursor-synthetic.json")


def encode(groups):
    out = bytearray()
    for group in groups:
        assert 0 <= group["id"] <= 0xffff
        assert len(group["children"]) <= 255
        out.extend(group["id"].to_bytes(2, "little"))
        out.append(len(group["children"]))
        for child in group["children"]:
            row = (list(child["id"].to_bytes(2, "little"))
                   + child["opaque"] + child["ip"]
                   + [child["include"], child["meta"]])
            assert len(row) == 10
            assert all(0 <= b <= 255 for b in row)
            out.extend(row)
    return bytes(out)


def conservative_walk(data, count):
    """Length-checked *test* walker. Native 0x4C3080 is not proved to guard."""
    idx = 0
    parsed = []
    for _ in range(count):
        if idx + 3 > len(data):
            raise ValueError("short group header")
        group_id = int.from_bytes(data[idx:idx+2], "little")
        children = data[idx+2]
        idx += 3
        accepted = []
        for _ in range(children):
            if idx + 10 > len(data):
                raise ValueError("short child record")
            row = data[idx:idx+10]
            idx += 10
            if row[8]:
                accepted.append((int.from_bytes(row[:2], "little"),
                                 tuple(row[4:8]), row[9]))
        parsed.append((group_id, accepted))
    return idx, parsed


class SyntheticAuthCursorTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.doc = json.loads(VECTORS.read_text(encoding="utf-8"))
        assert cls.doc["provenance"] == "OFFLINE_SYNTHETIC"

    def test_group_extent_and_two_distinct_command_origins(self):
        for case in self.doc["cases"]:
            with self.subTest(case=case["name"]):
                payload = encode(case["groups"])
                self.assertEqual(len(payload), case["group_bytes"])
                self.assertEqual(0x92 + len(payload), case["extent_13"])
                self.assertEqual(6 + len(payload), case["extent_7a"])
                consumed, parsed = conservative_walk(payload, len(case["groups"]))
                self.assertEqual(consumed, len(payload))
                self.assertEqual(len(parsed), len(case["groups"]))

    def test_filtered_record_advances_cursor_but_not_accepted_count(self):
        case = next(x for x in self.doc["cases"] if x["name"] == "two-child-filter")
        raw = encode(case["groups"])
        consumed, parsed = conservative_walk(raw, 1)
        self.assertEqual(consumed, 3 + 2*10)
        self.assertEqual(len(parsed[0][1]), 1)
        self.assertEqual(parsed[0][1][0][1], (192, 0, 2, 10))
        self.assertEqual(parsed[0][1][0][2], 9)

    def test_conservative_guard_is_not_assigned_to_native_client(self):
        case = next(x for x in self.doc["cases"] if x["name"] == "two-child-filter")
        raw = encode(case["groups"])
        for truncated in (raw[:2], raw[:-1], raw[:12]):
            with self.subTest(length=len(truncated)):
                with self.assertRaises(ValueError):
                    conservative_walk(truncated, 1)
        self.assertIn("NOT a captured", self.doc["note"])

    def test_fixture_is_not_real_original_server_packet(self):
        self.assertEqual(self.doc["provenance"], "OFFLINE_SYNTHETIC")
        self.assertEqual(self.doc["source_claim_ids"], ["CLM-AUTH-0004", "CLM-AUTH-0005"])
        self.assertEqual(self.doc["cases"][0]["extent_13"], 0x92)
        self.assertEqual(self.doc["cases"][0]["extent_7a"], 6)


if __name__ == "__main__":
    unittest.main()
