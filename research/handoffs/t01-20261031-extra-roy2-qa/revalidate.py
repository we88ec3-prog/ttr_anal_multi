#!/usr/bin/env python3
"""T01 independent bounded QA validation; no Client execution or frozen bulk mutation."""
import hashlib,json,struct,sys
from pathlib import Path
if len(sys.argv)!=3:raise SystemExit("Usage: python revalidate.py /path/Tartaros.bin /path/repository-root")
b=Path(sys.argv[1]).read_bytes(); root=Path(sys.argv[2])
sha="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
assert hashlib.sha256(b).hexdigest()==sha
pe=struct.unpack_from("<I",b,0x3c)[0]
assert pe==0x120 and struct.unpack_from("<H",b,pe+6)[0]==4
assert struct.unpack_from("<I",b,pe+24+28)[0]==0x400000
psec=pe+24+struct.unpack_from("<H",b,pe+20)[0]
sections={}
for i in range(4):
 o=psec+40*i
 name=b[o:o+8].split(b"\0")[0].decode("ascii")
 vs,rva,rsz,raw=struct.unpack_from("<IIII",b,o+8)
 sections[name]={"va":0x400000+rva,"vsize":vs,"raw":raw,"rsize":rsz}
assert sections[".text"]["raw"]==0x400 and sections[".text"]["va"]==0x401000
assert sections[".rdata"]["raw"]==0x7d0600 and sections[".rdata"]["va"]==0xbd2000
def native(va,n):
 s=sections[".text"]; offset=va-s["va"]+s["raw"];assert 0<=offset<len(b)-n
 return b[offset:offset+n]
def rdata(va,n):
 s=sections[".rdata"]; offset=va-s["va"]+s["raw"];assert 0<=offset<len(b)-n
 return b[offset:offset+n]
doc=json.loads((root/"shared/reviews/KR-BULK-CENTRAL-QA-ROUND-14-20261029-keys.json").read_text(encoding="utf-8"))
assert doc["source_sha256"]==sha and doc["count"]==len(doc["items"])==72
for i,rec in enumerate(doc["items"],1):
 assert rec["index"]==i
 va=int(rec["mov_va"],16);ptr=int(rec["string_va"],16);name=rec["string"].encode("utf-8")
 assert native(va,5)==b"\xbf"+struct.pack("<I",ptr),(i,"mov edi",hex(va))
 assert rdata(ptr,len(name)+1)==name+b"\0",(i,"rdata",hex(ptr))
slice=native(0x55d7e0,0x55e410-0x55d7e0)
pair=bytes.fromhex("6a0068f0c28d00")
assert slice.count(pair)==72
assert native(0x8dc2f0,3)==bytes.fromhex("33c0c3")
assert native(0x8dc2f3,1)==bytes.fromhex("cc")
assert native(0x5f5d10,1)==bytes.fromhex("c3")
assert native(0x55e590,18)==bytes.fromhex("a1201ffe00e81646f4ffa3241ffe0033c0c3")
assert native(0x55e4f0+0x18,10)==bytes.fromhex("c705281ffe00105d5f00")
assert native(0x55e620+0x3c,6)==bytes.fromhex("ff15281ffe00")
doc2=json.loads((root/"shared/reviews/KR-BULK-CENTRAL-QA-ROUND-02-20261029.json").read_text(encoding="utf-8"))
assert doc2["source_sha256"]==sha and len(doc2["samples"])==4
for d in doc2["samples"]:
 assert native(int(d["va"],16),48).hex()==d["entry_48_hex"]
print("PASS: source SHA, PE mapping, 72 EDI/.rdata strings, 72 push pairs, 4 original 48-byte samples, precise return stub and bounded Rebind writers.")
print("NOT COVERED: 111054 full index, whole VM lifecycle, original Server, runtime gameplay.")
