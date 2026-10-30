#!/usr/bin/env python3
"""KR T01/T10 116-118 bounded native validation; never execute the target."""
import json,hashlib,pathlib,struct,sys
b=pathlib.Path(sys.argv[1]).read_bytes()
d=json.loads(pathlib.Path(sys.argv[2]).read_text(encoding="utf8"))
assert hashlib.sha256(b).hexdigest()==d["bin_sha256"]
for w in d["windows"]:
    a=int(w["start"],16)-0x400C00;z=int(w["end_exclusive"],16)-0x400C00
    assert 0x400<=a<z<=0x7D0600 and hashlib.sha256(b[a:z]).hexdigest()==w["sha256"],w["label"]
for item in d["byte_assertions"]:
    a=int(item["va"],16)-0x400C00;seq=bytes.fromhex(item["hex"])
    assert b[a:a+len(seq)]==seq,item["label"]
for entry in d["vtable"]:
    a=int(entry["entry_va"],16)-0x401A00
    assert struct.unpack_from("<I",b,a)[0]==int(entry["target_va"],16),entry
print("PASS: scoped",len(d["windows"]),"windows",len(d["byte_assertions"]),"assertions",len(d["vtable"]),"vtable pointers. NOT FULL-PASS.")
