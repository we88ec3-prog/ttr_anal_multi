#!/usr/bin/env python3
"""T14 WP02 bounded native-byte witness. Read-only; does not execute Client."""
import hashlib
import json
import struct
import sys
from pathlib import Path

SHA = "9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
ANCHORS = {
  0x4C4F75:"0f b7 48 02", 0x4C4F84:"e8 f7 d8 ff ff",
  0x4C4F89:"c7 00 01 00 00 00", 0x4AA513:"8d 41 04",
  0x4AA519:"e8 62 83 01 00", 0x4AA4DF:"b8 40 00 00 00",
  0x4AA4F9:"6a 04", 0x4AA501:"ff d2",
  0x54409E:"0f b7 86 f4 00 00 00", 0x5443C0:"bb 04 00 00 00",
  0x5443CA:"39 1d ac a7 fb 00", 0x5443DD:"8b 0d a4 a7 fb 00",
  0x5443E3:"c7 84 81 b4 00 00 00 01 00 00 00",
  0x544739:"80 b9 05 01 00 00 00", 0x5447A3:"83 7d 10 00",
  0x502C11:"0f b7 43 04", 0x502C15:"66 85 c0",
  0x503199:"83 7f 04 00", 0x5031A3:"0f bf 77 02",
  0x5031A9:"e8 22 cf ff ff", 0x5031BB:"e8 80 d0 ff ff"
}
def u16(b, at): return struct.unpack_from("<H", b, at)[0]
def u32(b, at): return struct.unpack_from("<I", b, at)[0]
def verify(path):
    data = Path(path).read_bytes()
    actual = hashlib.sha256(data).hexdigest()
    if actual != SHA: raise RuntimeError(f"wrong KR BIN SHA256: {actual}")
    pe = u32(data,0x3c)
    assert data[:2] == b"MZ" and data[pe:pe+4] == b"PE\x00\x00"
    assert u16(data,pe+4) == 0x14c
    opt=pe+24
    assert u16(data,opt) == 0x10b
    image=u32(data,opt+28)
    sh=opt+u16(data,pe+20)
    sections=[]
    for i in range(u16(data,pe+6)):
        off=sh+40*i
        sections.append(dict(name=data[off:off+8].split(b"\0")[0].decode(),
            va=image+u32(data,off+12),raw=u32(data,off+20),
            size=u32(data,off+16)))
    matches=[]
    for va,hexstr in ANCHORS.items():
        expected=bytes.fromhex(hexstr)
        sect=[s for s in sections if s["va"]<=va and va+len(expected)<=s["va"]+s["size"]]
        if len(sect)!=1: raise RuntimeError(f"nonunique mapping at {va:#x}")
        s=sect[0];raw=s["raw"]+va-s["va"]
        actual=data[raw:raw+len(expected)]
        if actual!=expected: raise RuntimeError(f"mismatch at {va:#x}: {actual.hex()}")
        matches.append({"va":f"0x{va:08X}","raw":f"0x{raw:X}","hex":actual.hex()})
    return {"source_sha256":SHA,"size":len(data),"matched":len(matches),"windows":matches,
      "limitation":"Only bounded bytes; not whole-function semantic, wire or runtime validation"}
if __name__ == "__main__":
    print(json.dumps(verify(sys.argv[1] if len(sys.argv)>1 else "Tartaros.bin"),indent=2))
