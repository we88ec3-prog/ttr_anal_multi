#!/usr/bin/env python3
"""Reproducible KR T08-203 PE-native source identity, dispatch and constructors.

Run: python -B kr-temp-roy/T08-203-native-bin-verifier.py /path/to/Tartaros.bin
Does not establish T01 FULL-PASS, entire CFG, runtime behavior, or wire opcode.
"""
import hashlib
import struct
import sys
from pathlib import Path

TARGET_SHA = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
# VA -> exact original machine bytes; intentionally includes the corrected
# type6 row[1] accessor and new/duplicate/error controls.
ANCHORS = {
    0x4ADD7E: "c7 40 3c d0 e4 4a 00",
    0x4AE4D0: "55 8b ec", 0x4AE51F: "8d 48 fe",
    0x4AE522: "b8 4f ec c4 4e",0x4AE527: "f7 e1",
    0x4AE529: "c1 ea 03",0x4AE540:"83 c3 06",
    0x4AE58F:"0f b7 53 fc",0x4AE5A5:"e8 56 09 38 00",
    0x4AE5AC:"3b 0d 3c b1 fa 00",0x4AE5B2:"0f 85 8a 07 00 00",
    0x4AE5B8:"0f b6 43 fc",0x4AE5BC:"0f b6 7b fe",
    0x4AE5C0:"0f b7 0b",0x4AE5DD:"ff 24 85 90 ed 4a 00",
    0x4AE5E4:"68 44 04 00 00",0x4AE609:"e8 e2 f0 01 00",
    0x4AE671:"68 34 04 00 00",0x4AE692:"e8 79 30 02 00",
    0x4AE69D:"6a 48",0x4AE6C7:"0f b7 46 04",
    0x4AE80A:"68 2c 04 00 00",0x4AE82B:"e8 f0 38 02 00",
    0x4AE8A2:"8a 43 fd",  # EBX=R+4 -> EBX-3=R+1, NOT R+3
    0x4AE8D6:"68 28 04 00 00",0x4AE8F7:"e8 64 27 02 00",
    0x4AE90F:"89 88 20 04 00 00",
    0x4AEB1C:"89 86 9c 00 00 00",0x4AEB26:"89 86 90 00 00 00",
    0x4AEB30:"66 89 46 04",0x4AEB34:"8b 42 3c",
    0x4AEB3E:"8b 52 44",0x4AEB43:"8d 43 02",
    0x4AEB49:"ff d2",0x4AEB51:"8b 50 58",
    0x4AEB5B:"d9 43 0a",0x4AEB5E:"8b 50 5c",
    0x4AEB69:"80 7b 15 18",0x4AEB6F:"c6 86 bc 00 00 00 01",
    0x4AEB78:"8b 50 30",0x4AEB7D:"ff d2",
    0x4AEBFC:"68 30 b1 fa 00",0x4AEC03:"e8 28 13 03 00",
    0x4AEC5A:"b9 48 b1 fa 00",0x4AEC77:"83 79 04 00",
    0x4AEC83:"e8 c8 81 01 00",0x4AED47:"83 c3 1a",
    0x4AED58:"b8 00 01 00 00",0x4AED83:"68 c0 69 c0 00",
    0x4C6FB0:"55 8b ec",0x4C6FB6:"89 81 88 00 00 00",
    0x4C6FBC:"89 81 8c 00 00 00",
    0x4C8B90:"55 8b ec",0x4C8BA0:"e8 db 1f 00 00",
    0x4CAB80:"55 8b ec",0x4CABB1:"89 81 a0 00 00 00",
    0x4CABBA:"89 91 a4 00 00 00",
    0x4C8C30:"55 8b ec",0x4C8C36:"88 81 b0 00 00 00",
    0x4C8C40:"55 8b ec",
    0x4DFF30:"55 8b ec",0x4DFF4C:"0f b7 47 04",
    0x4DFF82:"e8 79 f2 34 00",
}
JUMP={0:0x4AE5E4,1:0x4AE671,2:0x4AED83,3:0x4AED83,
      4:0x4AED83,5:0x4AED83,6:0x4AE80A,7:0x4AE8D6}
TYPES={"Character":0xC07B44,"Monster":0xC0C9DC,
       "NPC":0xC0CA9C,"EventObject":0xC0C8C4}
METHODS={0x3C:0x4C6FB0,0x44:0x4C8B90,0x58:0x4C8C30,0x5C:0x4C8C40}
DIFFERENT_THIRTY={0xC07B44:0x4CDBA0,0xC0C9DC:0x4D1910,
                  0xC0CA9C:0x4D2820,0xC0C8C4:0x4D1370}

def main(path):
    binary=Path(path).read_bytes()
    assert len(binary)==12472320, "not the original KR binary length"
    assert hashlib.sha256(binary).hexdigest()==TARGET_SHA,"wrong KR BIN source"
    for va,hexbytes in ANCHORS.items():
        off=va-0x400C00
        expected=bytes.fromhex(hexbytes)
        assert binary[off:off+len(expected)]==expected, f"code {va:08x}"
    for index,destination in JUMP.items():
        off=0x4AED90-0x400C00+index*4
        assert struct.unpack_from("<I",binary,off)[0]==destination, f"type {index}"
    for name,vptr in TYPES.items():
        for off,expected in METHODS.items():
            got=struct.unpack_from("<I",binary,vptr-0x401A00+off)[0]
            assert got==expected, (name,hex(off),hex(got))
        assert struct.unpack_from("<I",binary,vptr-0x401A00+0x30)[0]==DIFFERENT_THIRTY[vptr]
    print("KR BIN SHA PASS")
    print(f"{len(ANCHORS)} code anchors PASS, {len(JUMP)} jump entries PASS, "
          f"{len(TYPES)*len(METHODS)} common virtual slots PASS, "
          f"{len(TYPES)} type-specific +30 slots PASS")
    print("LIMIT: no original server rules, no complete socket/wire opcode, "
          "no T01 full-pass, no real-time Client acceptance")
if __name__=="__main__":
    if len(sys.argv)!=2: raise SystemExit("Usage: verify.py /path/to/Tartaros.bin")
    main(sys.argv[1])
