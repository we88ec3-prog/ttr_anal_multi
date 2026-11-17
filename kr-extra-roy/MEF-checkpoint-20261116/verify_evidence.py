#!/usr/bin/env python3
"""Read-only bounded original-byte evidence validation; never executes game resources."""
import argparse
import hashlib
import json
import struct
from pathlib import Path

EXPECTED = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"

def run(binary_path, evidence_path):
    binary = Path(binary_path).read_bytes()
    assert hashlib.sha256(binary).hexdigest() == EXPECTED, "wrong KR binary"
    assert binary[:2] == b"MZ", "missing MZ header"
    pe = struct.unpack_from("<I", binary, 0x3c)[0]
    assert binary[pe:pe+4] == b"PE\x00\x00"
    assert struct.unpack_from("<H", binary, pe+4)[0] == 0x14c, "not i386"
    sections_count = struct.unpack_from("<H", binary, pe+6)[0]
    optional_size = struct.unpack_from("<H", binary, pe+20)[0]
    optional = pe + 24
    assert struct.unpack_from("<H", binary, optional)[0] == 0x10b, "not PE32"
    imagebase = struct.unpack_from("<I", binary, optional+28)[0]
    assert imagebase == 0x400000
    section_table = optional + optional_size
    sections = []
    for i in range(sections_count):
        off = section_table + i*40
        virtual_size, va, raw_size, raw_offset = struct.unpack_from("<IIII", binary, off+8)
        sections.append((va, raw_size, raw_offset))

    evidence = json.loads(Path(evidence_path).read_text(encoding="utf-8"))
    assert evidence["original_sha256"] == EXPECTED
    assert len(evidence["anchors"]) == 25
    for name, entry in evidence["anchors"].items():
        va = int(entry["va"], 16)
        expected_bytes = bytes.fromhex(entry["hex"])
        backing = next(
            ((v, raw_size, raw_offset) for v, raw_size, raw_offset in sections
             if imagebase+v <= va < imagebase+v+raw_size),
            None,
        )
        assert backing is not None, ("unmapped", name)
        v, raw_size, raw_offset = backing
        raw = raw_offset + (va - imagebase - v)
        assert raw == int(entry["raw"], 16), ("offset", name)
        assert binary[raw:raw+len(expected_bytes)] == expected_bytes, ("bytes", name)
    assert struct.calcsize("<HBBfffBB") == 18
    assert evidence["protocol"]["0027"]["row_bytes"] == 18
    assert evidence["protocol"]["0048"]["application_bytes"] == 6
    assert evidence["protocol"]["001C"]["application_bytes"] == 6
    return {
      "status":"PASS","binary_sha256":EXPECTED,
      "anchors_checked":25, "record_size":18,
      "client_executed":False, "lua_executed":False, "server_executed":False,
      "limits":["No full-program semantic verification","No gameplay or packet-capture acceptance",
                "No original MEF grammar or first loader proof"]}

if __name__ == "__main__":
    p = argparse.ArgumentParser()
    p.add_argument("--bin", required=True)
    p.add_argument("--evidence", required=True)
    args = p.parse_args()
    print(json.dumps(run(args.bin, args.evidence), ensure_ascii=False, indent=2))
