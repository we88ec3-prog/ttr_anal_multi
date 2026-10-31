#!/usr/bin/env python3
"""Read-only T10 W03 KR original BIN audit; never executes target."""
import sys,pathlib,json,hashlib,struct
if len(sys.argv)!=3:sys.exit("usage: python verify_w03.py Tartaros.bin W03-native-audit.json")
a=json.loads(pathlib.Path(sys.argv[2]).read_text(encoding="utf-8"))
b=pathlib.Path(sys.argv[1]).read_bytes()
assert len(b)==a["bin_size"] and hashlib.sha256(b).hexdigest()==a["bin_sha256"]
bias=int(a["text_va_file_bias"],16)
for x in a["anchors"]:
    o=int(x["va"],16)-bias; v=bytes.fromhex(x["hex"])
    assert b[o:o+len(v)]==v,x["va"]
for x in a["windows"]:
    lo=int(x["va_start"],16)-bias
    hi=int(x["va_end"],16)-bias
    assert hashlib.sha256(b[lo:hi]).hexdigest()==x["sha256"],x["id"]
c=a["transport_vtable"]
assert struct.unpack_from("<I",b,int(c["at_va"],16)-int(a["rdata_va_file_bias"],16))[0]==int(c["target"],16)
print("PASS",len(a["anchors"]),"anchors,",len(a["windows"]),"hash windows, vtable")
