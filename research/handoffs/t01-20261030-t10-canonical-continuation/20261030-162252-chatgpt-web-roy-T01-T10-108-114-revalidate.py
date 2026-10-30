#!/usr/bin/env python3
"""Recheck KR T10-108..114 bounded native byte assertions. Read only."""
import sys,json,hashlib,pathlib,struct
b=pathlib.Path(sys.argv[1]).read_bytes()
d=json.loads(pathlib.Path(sys.argv[2]).read_text(encoding="utf8"))
assert hashlib.sha256(b).hexdigest()==d["target_sha256"]
for w in d["windows"]:
  a=int(w["begin_va"],16)-0x400C00
  z=int(w["end_exclusive_va"],16)-0x400C00
  assert 0x400<=a<z<=len(b) and hashlib.sha256(b[a:z]).hexdigest()==w["sha256"],w["label"]
for r in d["instruction_assertions"]:
  a=int(r["va"],16)-0x400C00;v=bytes.fromhex(r["hex"])
  assert b[a:a+len(v)]==v,r["name"]
for s in d["rdata_c51748_vtable"]:
  a=int(s["entry_va"],16)-0x401A00
  assert struct.unpack_from("<I",b,a)[0]==int(s["target_va"],16),s
for api in d["ff15_iat_direct_search"]:
  if not isinstance(d["ff15_iat_direct_search"][api],dict): continue
  item=d["ff15_iat_direct_search"][api]
  pattern=b"\xff\x15"+struct.pack("<I",int(item["iat_va"],16))
  hits=[hex(i+0x400C00) for i in range(0x400,0x7D0600-5) if b.startswith(pattern,i)]
  assert set(map(int,item["hits"],[16]*len(item["hits"])))==set(int(z,16) for z in hits),api
print("R2 BOUNDED PASS",len(d["windows"]),"windows",len(d["instruction_assertions"]),"byte asserts",len(d["rdata_c51748_vtable"]),"vt entries")
