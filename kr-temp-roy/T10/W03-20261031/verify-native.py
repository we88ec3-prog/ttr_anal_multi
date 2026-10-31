#!/usr/bin/env python3
"""Read-only W03 combo static audit for the original KR Tartaros.bin. No target execution."""
import hashlib,json,pathlib,struct,sys
if len(sys.argv)!=3:
    sys.exit("usage: python verify-native.py Tartaros.bin W03-combo-native-audit.json")
b=pathlib.Path(sys.argv[1]).read_bytes()
a=json.loads(pathlib.Path(sys.argv[2]).read_text(encoding="utf-8"))
assert len(b)==a["file_size"] and hashlib.sha256(b).hexdigest()==a["source_sha256"],"wrong BIN"
text_bias=int(a["text_va_minus_raw"],16)
rdata_bias=int(a["rdata_va_minus_raw"],16)
for item in a["anchors"]:
    p=int(item["va"],16)-text_bias
    v=bytes.fromhex(item["bytes"])
    assert b[p:p+len(v)]==v,item["va"]
for item in a["windows"]:
    p=int(item["start_va"],16)-text_bias
    q=int(item["end_exclusive_va"],16)-text_bias
    assert hashlib.sha256(b[p:q]).hexdigest()==item["sha256"],item["label"]
for k,target in a["vtable"].items():
    base=int(k[:6],16)
    off=int(k.split("plus")[1],16)
    assert struct.unpack_from("<I",b,base+off-rdata_bias)[0]==int(target,16),k
# A pure symbolic unit-test of the observed 0x54f270 ordering. NOT a runtime Client test.
def matrix(mask):
    if mask & 0xC0: return "fast_path"
    if mask & 1 and mask & 2: return 4
    if mask & 1 and mask & 4: return 5
    if mask & 2 and mask & 4: return 6
    if mask & 1: return 1
    if mask & 2: return 2
    if mask & 4: return 3
    if mask & 8: return 7
    if mask & 16: return 10
    return "fast_path"
for value,expected in [(3,4),(5,5),(6,6),(7,4)]:
    assert matrix(value)==expected,(value,expected)
print("PASS",len(a["anchors"]),"bytes;",len(a["windows"]),"hash windows;",len(a["vtable"]),"vtable slots; 4 symbolic matrix tests")
