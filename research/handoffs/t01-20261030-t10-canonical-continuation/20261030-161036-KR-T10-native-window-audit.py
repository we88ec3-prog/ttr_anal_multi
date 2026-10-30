#!/usr/bin/env python3
# T01 scoped KR BIN checks; no program execution, no FULL-PASS.
import json,hashlib,struct,sys,pathlib
data=json.load(open(sys.argv[2],encoding="utf-8"))
b=pathlib.Path(sys.argv[1]).read_bytes()
assert hashlib.sha256(b).hexdigest()==data["bin_sha256"]
for q in data["windows"]:
 s=int(q["start"],16)-0x400c00; e=int(q["end_exclusive"],16)-0x400c00
 assert 0<=s<e<=len(b) and hashlib.sha256(b[s:e]).hexdigest()==q["sha256"],q["label"]
for q in data["assertions"]:
 o=int(q["va"],16)-0x400c00
 assert b[o:o+len(bytes.fromhex(q["hex"]))]==bytes.fromhex(q["hex"]),q["label"]
for va,v in data["little_endian_u32_rdata"].items():
 o=int(va,16)-0x401a00
 assert struct.unpack_from("<I",b,o)[0]==int(v,16)
lo,hi=0x7d0600,0x95e800
pat=struct.pack("<I",int(data["equal_dword_pointer_scan"]["value"],16))
addrs=[i+0x401a00 for i in range(lo,hi-3) if b[i:i+4]==pat]
assert len(addrs)==data["equal_dword_pointer_scan"]["candidate_count"]
assert set(addrs)==set(int(x,16) for x in data["equal_dword_pointer_scan"]["verified_addresses"])
print("OK:",len(data["windows"]),"raw windows,",len(data["assertions"]),"opcode assertions,",len(addrs),"pointer candidates; scope-only")
