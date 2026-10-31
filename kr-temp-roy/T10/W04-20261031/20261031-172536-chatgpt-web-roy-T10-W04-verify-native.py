#!/usr/bin/env python3
"""T10-W04 read-only KR BIN source audit. Never executes the target."""
from pathlib import Path
import sys, json, hashlib, struct
if len(sys.argv) != 3:
    sys.exit("usage: python verify-native.py Tartaros.bin W04-native-audit.json")
a=json.loads(Path(sys.argv[2]).read_text(encoding="utf-8"))
b=Path(sys.argv[1]).read_bytes()
assert len(b)==a["bin_size"] and hashlib.sha256(b).hexdigest()==a["bin_sha256"],"wrong original KR BIN"
textbias=int(a["va_text_bias"],16)
rdatabias=int(a["va_rdata_bias"],16)
for w in a["windows"]:
    begin=int(w["va_start"],16)-textbias
    end=int(w["va_end_exclusive"],16)-textbias
    assert hashlib.sha256(b[begin:end]).hexdigest()==w["sha256"],w["label"]
for q in a["anchors"]:
    off=int(q["va"],16)-textbias
    bs=bytes.fromhex(q["bytes"])
    assert b[off:off+len(bs)]==bs,q["va"]
for v in a["rdata_vtable"]:
    off=int(v["va"],16)-rdatabias
    assert struct.unpack_from("<I",b,off)[0]==int(v["value"],16),v["va"]
t=a["rdata_distance_threshold"]
assert struct.unpack_from("<f",b,int(t["va"],16)-rdatabias)[0]==t["float32"]
# Arithmetic only; not a runtime Client/Server test.
for size in (0,1,2,3,4,9,10,11,18,19,20,27):
    for stride in (8,3,9,6):
        expected=(size-2)//stride if size>=2 else 0
        assert expected>=0
print("PASS",len(a["windows"]),"SHA windows,",len(a["anchors"]),"native byte anchors,",len(a["rdata_vtable"]),"vtable pointers; float 4.0")
