import json
import unittest
from pathlib import Path
from kr_frame_subset import (encode_plain,encode_xor,decode_one,decode_available,
                             FrameError,ChecksumMismatch,UnsupportedMarker)
DATA=json.loads(Path(__file__).with_name("kr-framing-vectors.json").read_text(encoding="utf-8"))
class FrameSubsetTests(unittest.TestCase):
    def test_exact_offline_vectors(self):
        self.assertEqual(DATA["provenance"],"SYNTHETIC_STATIC_DERIVED")
        for c in DATA["cases"]:
            with self.subTest(c=c["id"]):
                payload=bytes.fromhex(c["payload_hex"])
                raw=bytes.fromhex(c["frame_hex"])
                self.assertEqual((encode_plain if c["mode"]=="plain" else encode_xor)(payload),raw)
                result=decode_one(raw)
                self.assertEqual((result[0].payload,result[1]),(payload,len(raw)))
    def test_split_and_coalesced(self):
        x=encode_plain(b"\x10\x20")
        y=encode_xor(b"\x01\x02\x03")
        self.assertEqual(decode_available(x[:3]),([],x[:3]))
        frames,rest=decode_available(x+y[:5])
        self.assertEqual([v.payload for v in frames],[b"\x10\x20"])
        self.assertEqual(rest,y[:5])
        frames,rest=decode_available(x+y)
        self.assertEqual([v.payload for v in frames],[b"\x10\x20",b"\x01\x02\x03"])
        self.assertEqual(rest,b"")
    def test_limits_sender_vs_receiver(self):
        self.assertEqual(len(encode_plain(b"\x00"*4092)),4096)
        self.assertEqual(len(encode_xor(b"\x00"*4090)),4096)
        for f,p in [(encode_plain,b""),(encode_xor,b""),
                    (encode_plain,b"\x00"*4093),(encode_xor,b"\x00"*4091)]:
            with self.assertRaises(FrameError): f(p)
        self.assertEqual(len(decode_one(b"\x00\x10\x68\x1a"+b"\x00"*4096)[0].payload),4096)
        for invalid in (b"\x00\x00\x68\x1a",b"\x01\x10\x68\x1a"):
            with self.assertRaises(FrameError):decode_one(invalid)
    def test_conservative_harness_policy(self):
        with self.assertRaises(ChecksumMismatch):decode_one(bytes.fromhex("0300bb0b0700b70301"))
        with self.assertRaises(UnsupportedMarker):decode_one(bytes.fromhex("0100d72200"))
        with self.assertRaises(UnsupportedMarker):decode_one(bytes.fromhex("010033260000000000"))
    def test_sum_wrap(self):
        p=b"\xff"*4090
        x=encode_xor(p)
        self.assertEqual(int.from_bytes(x[4:6],"little"),sum(p)&0xffff)
        self.assertEqual(decode_one(x)[0].payload,p)
if __name__=="__main__":unittest.main()
