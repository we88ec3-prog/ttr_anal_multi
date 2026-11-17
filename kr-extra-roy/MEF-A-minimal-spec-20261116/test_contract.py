#!/usr/bin/env python3
"""Synthetic OFFLINE format/policy tests. No legal map coordinates or runtime claims."""
import unittest
from contract import (BIN_SHA, ROW, START, END_REPORT, RELEASE, ContractError,
                      Exchange, digest, parse_snapshot, validate_binding)


def synthetic():
    data = b"\x27\x00" + ROW.pack(7, 0, 0, 1., 2., 3., 0, 0)
    b = dict(profile_id="A1-v1", client_bin_sha256=BIN_SHA,
             field_type="Scenario", field_instance="SYN_ONLY_INSTANCE",
             connection_id="SYN_CONNECTION", client_epoch="SYN_CLIENT_EPOCH",
             snapshot_generation=1, snapshot_sha256=digest(data),
             snapshot_evidence="SYN_NOT_LEGAL_MAP_DATA", point_key=7, point_category=0,
             expected_before=0, desired=1, release_id="SYN_NOT_DEPLOYED",
             release_point_key=7, release_point_category=0,
             sequence_sha256=digest(b"SYN_NOT_A_SEQUENCE"),
             scene_list_sha256=digest(b"SYN_NOT_A_SCENELIST"),
             release_evidence="SYN_NO_ASSETS", timeout_ms=1000)
    return b, data

class ContractTests(unittest.TestCase):
    def reject(self, field, value):
        b, data = synthetic(); b[field] = value
        with self.assertRaises(ContractError): validate_binding(b, data)

    def test_01_vectors(self):
        self.assertEqual(ROW.size, 18)
        self.assertEqual(START.hex(), "47000000f87f")
        self.assertEqual(END_REPORT.hex(), "3f000000f87f0100")
        self.assertEqual(RELEASE.hex(), "eb00")

    def test_02_valid_synthetic(self):
        b, data = synthetic(); p = validate_binding(b, data)
        self.assertFalse(p["deployed"] or p["point_verified"] or p["input_restored"])

    def test_03_truncated_row(self):
        with self.assertRaises(ContractError): parse_snapshot(b"\x27\x00\x01")

    def test_04_wrong_opcode(self):
        with self.assertRaises(ContractError): parse_snapshot(b"\x48\x00")

    def test_05_missing_target(self):
        b, data = synthetic(); b["point_key"] = b["release_point_key"] = 8
        with self.assertRaises(ContractError): validate_binding(b, data)
    def test_06_boolean_not_integer(self): self.reject("desired", True)
    def test_07_tutorial_rejected(self): self.reject("field_type", "Tutorial")
    def test_08_category4_rejected(self): self.reject("point_category", 4)
    def test_09_negative_key_rejected(self): self.reject("point_key", -1)
    def test_10_runtime_target_change(self): self.reject("release_point_key", 8)
    def test_11_no_timeout_default(self): self.reject("timeout_ms", 0)
    def test_12_digest_mismatch(self): self.reject("snapshot_sha256", "0" * 64)
    def test_13_not_toggle(self): self.reject("desired", 0)

    def test_14_duplicate(self):
        b, data = synthetic(); data += data[2:]; b["snapshot_sha256"] = digest(data)
        with self.assertRaises(ContractError): validate_binding(b, data)

    def test_15_bad_geometry(self):
        b, _ = synthetic(); data = b"\x27\x00" + ROW.pack(7,0,0,float("nan"),2.,3.,0,0)
        b["snapshot_sha256"] = digest(data)
        with self.assertRaises(ContractError): validate_binding(b, data)

    def test_16_already_enabled(self):
        b, _ = synthetic(); data = b"\x27\x00" + ROW.pack(7,0,1,1.,2.,3.,0,0)
        b["snapshot_sha256"] = digest(data)
        with self.assertRaises(ContractError): validate_binding(b, data)

    def test_17_missing_field(self):
        b, data = synthetic(); del b["release_evidence"]
        with self.assertRaises(ContractError): validate_binding(b, data)

    def test_18_no_phantom_ack_field(self):
        b, data = synthetic(); b["client_setter_success"] = True
        with self.assertRaises(ContractError): validate_binding(b, data)

    def test_19_normal_report_is_not_success(self):
        e = Exchange("c", "e", "f", 1); used = set()
        self.assertEqual(e.dispatch(used), START)
        self.assertEqual(e.accept_report(END_REPORT, e.context()), RELEASE)
        self.assertEqual(e.state, "END_REPORTED")
        e.mark_release_enqueued()
        self.assertEqual(e.state, "RELEASE_ENQUEUED_UNVERIFIED")
        self.assertFalse(e.point_verified or e.input_restored)

    def test_20_no_retry_same_epoch(self):
        used = set(); e = Exchange("c", "e", "f", 1); e.dispatch(used); e.fail()
        with self.assertRaises(ContractError): Exchange("new_connection","e","f",1).dispatch(used)

    def test_21_duplicate_does_not_unlock_twice(self):
        e = Exchange("c", "e", "f", 1); e.dispatch(set())
        self.assertEqual(e.accept_report(END_REPORT, e.context()), RELEASE)
        self.assertIsNone(e.accept_report(END_REPORT, e.context()))

    def test_22_wrong_scene_ignored(self):
        e = Exchange("c", "e", "f", 1); e.dispatch(set())
        self.assertIsNone(e.accept_report(bytes.fromhex("3f00000001000100"), e.context()))
        self.assertEqual(e.state, "SENT")

    def test_23_cross_field_not_released(self):
        e = Exchange("c", "e", "f", 1); e.dispatch(set())
        self.assertIsNone(e.accept_report(END_REPORT, ("c","e","other",1)))
        self.assertEqual(e.state, "UNCERTAIN")

    def test_24_collection_rebuild_not_released(self):
        e = Exchange("c", "e", "f", 1); e.dispatch(set())
        self.assertIsNone(e.accept_report(END_REPORT, ("c","e","f",2)))

    def test_25_timeout_late_ack_ignored(self):
        e = Exchange("c", "e", "f", 1); e.dispatch(set()); e.fail()
        self.assertIsNone(e.accept_report(END_REPORT, e.context()))

    def test_26_bad_report_length(self):
        e = Exchange("c", "e", "f", 1); e.dispatch(set())
        self.assertIsNone(e.accept_report(END_REPORT[:-1], e.context()))
        self.assertIsNone(e.accept_report(END_REPORT+b"\x00", e.context()))

    def test_27_wrong_report_constant(self):
        e = Exchange("c", "e", "f", 1); e.dispatch(set())
        self.assertIsNone(e.accept_report(END_REPORT[:-2]+b"\x00\x00", e.context()))

    def test_28_both_ordinary_fields(self):
        b, data = synthetic(); b["field_type"] = "Mission"
        self.assertEqual(validate_binding(b,data)["scene"], [0,32760])

if __name__ == "__main__":
    unittest.main(verbosity=2)
