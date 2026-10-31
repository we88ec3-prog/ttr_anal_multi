#!/usr/bin/env python3
"""T10 W05 offline native audit; reads BIN, does NOT execute client."""
import hashlib,json,pathlib,struct,sys
if len(sys.argv)!=3:sys.exit("usage: python verify-native.py Tartaros.bin W05-native-audit.json")
m=json.loads(pathlib.Path(sys.argv[2]).read_text(encoding="utf-8"))
b=pathlib.Path(sys.argv[1]).read_bytes()
assert len(b)==m["originalKRBinSize"] and hashlib.sha256(b).hexdigest()==m["originalKRBinSHA256"], "wrong KR BIN"
textBias=int(m["textVArawBias"],16);rdataBias=int(m["rdataVArawBias"],16)
for w in m["windows"]:
    p=int(w["beginVA"],16)-textBias;q=int(w["endVAexclusive"],16)-textBias
    assert hashlib.sha256(b[p:q]).hexdigest()==w["sha256"],w["id"]
for a in m["anchors"]:
    p=int(a["va"],16)-textBias;expected=bytes.fromhex(a["hex"])
    assert b[p:p+len(expected)]==expected,a["va"]
for v in m["vtables"]:
    p=int(v["va"],16)-rdataBias
    assert struct.unpack_from("<I",b,p)[0]==int(v["value"],16),v["va"]
print("PASS",len(m["windows"]),"SHA256 code windows,",len(m["anchors"]),"native byte anchors,",len(m["vtables"]),"vtable pointer values")
