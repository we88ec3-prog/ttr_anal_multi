#!/usr/bin/env python3
"""KR T08-202: exact original PE byte audit, not T01 FULL-PASS/runtime proof.

Usage: python -B kr-temp-roy/T08-202-native-final-reference-audit.py /path/to/Tartaros.bin
Scope: all literal 0xFAB148 references in .text, selected original function
boundaries, primary vtable pointers and three direct E8 edges.
"""
import hashlib
import struct
import sys
from pathlib import Path

EXPECTED_SHA = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
RESET_SITES = "42447a 48c4f5 4af595 4bb65c 4bbd22 4bcd0b 4be5e1 4c173b 4c33a5 4c4c11 4c5ada"
LOOKUP_SITES = "4ae9ee 4aec5a 4af0a0 4af612 4b06ff 4bd6ff 4d6f00 4d70ab 5086e8 54b95d 695476 6aeda7 6c19b4 6c1a20 6c65b1 6c66e1"
OTHER_SITES = "4df124 4df13b 6c646b"
REFERENCES = [int(x,16) for z in (RESET_SITES, LOOKUP_SITES, OTHER_SITES) for x in z.split()]
CODE = {
    0x5451d0:"55 8b ec",0x5451f7:"e8 24 74 fb ff",
    0x5452c0:"55 8b ec",0x54537d:"8b 4b 34",0x545380:"2b 4b 30",
    0x54539a:"8d 34 fa",0x5453d4:"0f b7 0e",0x5459b7:"8b 44 24 18",
    0x5459fc:"0f b7 16",0x545a49:"8b 70 10",0x545a86:"0f b7 40 02",
    0x545a93:"88 5c 24 28",0x545a97:"ff d2",
    0x545aeb:"66 8b 56 04",0x545b0e:"89 10",0x545b10:"88 48 04",
    0x545b13:"83 05 d0 48 fe 00 05",
    0x4c8360:"53 56 57",0x4c8365:"8b 87 5c 01 00 00",
    0x4c836f:"8d 48 08",0x4c8374:"8b 50 08",0x4c8377:"ff d2",
    0x7a57c0:"55 8b ec 83 e4 f8",0x7a57ec:"8b d9",
    0x7a57ee:"8b 8b 18 01 00 00",0x7a57ff:"ff d2",
    0x7a5911:"c7 43 14 00 00 00 00",0x7a5949:"89 7b 1c",
    0x7a594c:"c6 43 20 01",
    0x4bd728:"8b 48 04",0x4bd742:"e8 b9 17 37 00",
    0x4bd766:"89 8b e0 5e 00 00",
    0x4d6f1a:"8b 70 10",0x4d6f2c:"8b 5e 04",
    0x4d70c5:"8b 70 10",0x4d70d7:"8b 7e 04",
    0x4bbdff:"89 58 04",0x4bbe02:"89 58 08",
    0x4c1897:"89 58 04",0x4c346f:"89 79 04",
    0x5450a2:"89 78 0c",0x5450a5:"0f b7 5f 04",
    0x5451b6:"89 59 10",0x545212:"89 41 0c",
    0x545256:"89 51 34",0x4af649:"89 70 04",
    0x4af64c:"89 70 08",0x4aec77:"83 79 04 00",
    0x4c6e57:"89 47 04",0x4c6e89:"89 4f 08",
    0x4afa48:"89 70 04",0x4afa7d:"89 50 08",
    0x4afa85:"c7 41 08 00 00 00 00",
    0x4dfc39:"8d 5e 18",0x4dfc72:"e8 95 15 3b 00",
    0x4dfcc0:"8b 42 14",0x4dfcc3:"ff d0",
    0x4b2a84:"8b 50 14",0x4b2a87:"ff d2",
}
CONTROLLERS={"Controller":0xc0f944,"Empty":0xc0f99c,"Mission":0xc0fa6c,
             "Single":0xc0fac4,"Tutorial":0xc0fb1c,"Tag":0xbfb5a4}
CALLS=((0x5451f7,0x4fc620),(0x4bd742,0x82ef00),(0x4dfc72,0x89120c))

def audit(path):
    b=Path(path).read_bytes()
    assert len(b)==12472320, "target BIN length differs"
    assert hashlib.sha256(b).hexdigest()==EXPECTED_SHA, "target BIN SHA differs"
    text=b[0x400:0x7D0600]
    literal=bytes.fromhex("48 b1 fa 00")
    starts=[]
    pos=0
    while (pos:=text.find(literal,pos)) != -1:
        starts.append(pos+0x401000)
        pos+=1
    expected_literal_sites=[site+(3 if site==0x4df124 else 1) for site in REFERENCES]
    assert sorted(starts)==sorted(expected_literal_sites), ("global literal site mismatch", len(starts))
    assert len(RESET_SITES.split())==11
    assert len(LOOKUP_SITES.split())==16
    assert len(OTHER_SITES.split())==3
    for va,pattern in CODE.items():
        raw=va-0x400c00
        expected=bytes.fromhex(pattern)
        assert b[raw:raw+len(expected)]==expected, f"code mismatch 0x{va:x}"
    for name,vptr in CONTROLLERS.items():
        offset=vptr+0x44-0x401a00
        assert struct.unpack_from("<I",b,offset)[0]==0x546ef0, name
    assert struct.unpack_from("<I",b,0xc4f6b8-0x401a00)[0]==0x7a57c0
    for site,target in CALLS:
        raw=site-0x400c00
        assert b[raw]==0xe8
        delta=int.from_bytes(b[raw+1:raw+5],"little",signed=True)
        assert (site+5+delta)&0xffffffff==target, f"E8 at {site:x}"
    print(f"BIN_SHA_PASS; DIRECT_FAB148_LITERAL_SITES_PASS={len(starts)} (11 reset,16 lookup,3 other)")
    print(f"CODE_BYTE_PASS={len(CODE)}; VTABLE_PASS={len(CONTROLLERS)+1}; E8_PASS={len(CALLS)}")
    print("LIMIT: This validates literal references and listed bytes, NOT complete CFG,")
    print("indirect aliases, original Server policy, T01 FULL-PASS, or playable state.")
if __name__=="__main__":
    if len(sys.argv)!=2:
        raise SystemExit("Usage: verify_script.py /path/to/Tartaros.bin")
    audit(sys.argv[1])
