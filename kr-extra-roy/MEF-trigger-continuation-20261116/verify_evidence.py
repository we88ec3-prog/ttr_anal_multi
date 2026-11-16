#!/usr/bin/env python3
"""KR MEF interaction-trigger witness verifier; read-only and does not execute game assets."""
import argparse, hashlib, json, struct
from pathlib import Path

KNOWN_SHA = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
def verify(binary_path, evidence_path):
    b = Path(binary_path).read_bytes()
    if hashlib.sha256(b).hexdigest() != KNOWN_SHA:
        raise ValueError("KR BIN SHA mismatch")
    pe = struct.unpack_from("<I", b, 0x3c)[0]
    assert b[:2] == b"MZ" and b[pe:pe+4] == b"PE\x00\x00"
    assert struct.unpack_from("<H", b, pe+4)[0] == 0x14c
    assert struct.unpack_from("<H", b, pe+24)[0] == 0x10b
    assert struct.unpack_from("<I", b, pe+24+28)[0] == 0x400000
    sections_n = struct.unpack_from("<H", b, pe+6)[0]
    optional_size = struct.unpack_from("<H", b, pe+20)[0]
    sections = []
    for i in range(sections_n):
        o = pe+24+optional_size+40*i
        va_size, va, raw_size, raw = struct.unpack_from("<IIII", b, o+8)
        sections.append((va, raw_size, raw))
    e = json.loads(Path(evidence_path).read_text(encoding="utf-8"))
    assert e["binary_sha256"] == KNOWN_SHA
    assert len(e["anchors"]) == 12
    for x in e["anchors"]:
        va = int(x["va"],16)
        span = bytes.fromhex(x["hex"])
        matches = [raw+va-0x400000-section_va for section_va, size, raw in sections
                   if 0x400000+section_va <= va and va+len(span) <= 0x400000+section_va+size]
        assert len(matches)==1, x["name"]
        assert matches[0] == int(x["raw"],16), x["name"]
        assert b[matches[0]:matches[0]+len(span)] == span, x["name"]
    return {"status":"PASS","scope":"12 bounded KR BIN native byte windows and address mapping",
            "anchors_checked":len(e["anchors"]),"original_sha256":KNOWN_SHA,
            "client_executed":False,"server_executed":False,"lua_executed":False,
            "limits":"Not whole-program coverage, a Lua getter proof, T01 FULL-PASS, or gameplay acceptance"}
if __name__ == "__main__":
    p=argparse.ArgumentParser()
    p.add_argument("--bin", required=True); p.add_argument("--evidence", required=True)
    args=p.parse_args()
    print(json.dumps(verify(args.bin,args.evidence), ensure_ascii=False, indent=2))
