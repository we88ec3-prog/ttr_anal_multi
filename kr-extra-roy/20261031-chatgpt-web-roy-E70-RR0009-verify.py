#!/usr/bin/env python3
"""RR-0009 KR native static 30-check audit; no Client execution.
Run: python E70-RR0009-verify.py /path/Tartaros.bin /path/Table.stp
"""
import hashlib,struct,sys,json
from pathlib import Path
p=Path(sys.argv[1] if len(sys.argv)>1 else "Tartaros.bin")
q=Path(sys.argv[2] if len(sys.argv)>2 else "Table.stp")
b=p.read_bytes();table=q.read_bytes()
assert hashlib.sha256(b).hexdigest()=="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
assert hashlib.sha256(table).hexdigest()=="09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442"
pe=struct.unpack_from("<I",b,0x3c)[0]
assert b[:2]==b"MZ" and b[pe:pe+4]==b"PE\x00\x00"
n=struct.unpack_from("<H",b,pe+6)[0]
off=pe+24+struct.unpack_from("<H",b,pe+20)[0]
sections={}
for i in range(n):
    t=off+i*40
    name=b[t:t+8].split(b"\x00")[0].decode()
    virt,va,rs,raw=struct.unpack_from("<IIII",b,t+8)
    sections[name]=(0x400000+va,virt,rs,raw)
def read(va,n):
    for name,(base,virt,rs,raw) in sections.items():
        if base<=va and va+n<=base+rs: return b[raw+va-base:raw+va-base+n]
    raise ValueError(hex(va))
def dword(va):return struct.unpack("<I",read(va,4))[0]
def has(va,s):
    d=bytes.fromhex(s)
    return read(va,len(d))==d
v,_,rs,raw=sections[".text"]
def calls(target):
    a=b[raw:raw+rs]
    return [v+i for i in range(len(a)-4) if a[i]==0xE8 and v+i+5+struct.unpack_from("<i",a,i+1)[0]==target]
def rtti(vptr):
    col=dword(vptr-4); typ=dword(col+12)
    return read(typ+8,96).split(b"\x00")[0].decode("ascii")
checks={}
def ck(name,condition):
    checks[name]=bool(condition)
    if not condition: raise AssertionError(name)
ck("binary source hash and PE",True)
ck("STPD source hash/header",table[:4]==b"STPD")
ck("roster min 65 bytes",has(0x4B8923,"8b4d0c83f941"))
ck("roster 65+53*n",has(0x4B892F,"83c1bf") and has(0x4B8932,"b8b3cf2135") and has(0x4B893F,"c1e905"))
ck("N0 skips row loop",has(0x4B894A,"85c9") and has(0x4B894C,"0f84ce000000"))
ck("N-positive row pointer",has(0x4B8952,"8b7c2428") and has(0x4B8956,"83c76f"))
ck("row id <=9, record stride 0x210",has(0x4B8992,"0fb607") and has(0x4B8995,"83f809") and has(0x4B899A,"69c010020000"))
ck("row writer call 4D4150",has(0x4B89A8,"8d57d2") and has(0x4B89AD,"e89eb70100"))
ck("53 byte row increment/decrement",has(0x4B8A0E,"83c735") and has(0x4B8A16,"ff4c2410"))
ck("common post path saves mask",has(0x4B8A5B,"668b442414") and has(0x4B8A60,"66a34042f900"))
ck("common post calls 4E5FB0",has(0x4B8A97,"b9e0d9f800") and has(0x4B8A9C,"e80fd50200"))
ck("network cmd24 is not UI event",has(0x4B8AC4,"b924000000") and has(0x4B8ADB,"6a02"))
ck("record+5C flag only",has(0x4D4154,"c7465c01000000"))
ck("4E5FB0 local record lookup",has(0x4E5FE2,"8b8f24690000") and has(0x4E5FEB,"e8a0e5feff"))
ck("4E5FB0 no-entry branch",has(0x4E5FF5,"3bde") and has(0x4E5FF7,"0f8424010000"))
ck("4E5FB0 cached state tests",has(0x4E6064,"399fcc680000") and has(0x4E6075,"83b84c5f000000"))
ck("EmployNewCharacter RTTI",rtti(0xC3F024)==".?AVCEmployNewCharacter@FUI@@")
ck("Employ cache vtable/type index",has(0x5AB2E4,"c70724f0c300") and has(0x5AB2EE,"897e0c") and has(0x5AB2F1,"c746041b010000"))
ck("Employ lazy cache",has(0x5AB047,"a19c2dfe00") and has(0x5AB06D,"e80e020000"))
ck("UI owner cache retrieval",has(0x5C30F7,"8db330020000") and has(0x5C30FD,"e81e7ffeff"))
ck("UI owner register object +230",has(0x5C3102,"56") and has(0x5C3105,"e8366efeff"))
ck("UI owner +230 final registration",has(0x5C3156,"8b8330020000") and has(0x5C316A,"e8013cfdff"))
ck("Employ local event 0x387",has(0x65D556,"81781087030000"))
ck("Employ event F4350",has(0x65D585,"c7401050430f00") and has(0x65D592,"e8099ddaff"))
ck("F42EF two local producers",has(0x6602F0,"c74010ef420f00") and has(0x673E13,"c74010ef420f00"))
ck("F42EF consumer -> 665150",has(0x5A69E8,"817e10ef420f00") and has(0x5A6A28,"e823e70b00"))
ck("F4246 selection local event",has(0x5F4760,"c7401046420f00"))
ck("F4278 separate local event",has(0x4B5E27,"6878420f00"))
ck("direct cache and row writer xrefs",calls(0x5AB280)==[0x5AB06D] and calls(0x4D4150)==[0x4B89AD,0x4E2782])
ck("no direct roster to employ lazy cache",not any(0x4B7F00<=a<0x4B8F40 for a in calls(0x5AB020)))
assert len(checks)==30
print(json.dumps({"source_sha256":hashlib.sha256(b).hexdigest(),"table_sha256":hashlib.sha256(table).hexdigest(),"count":len(checks),"pass":all(checks.values()),"items":checks,"direct_cache_callers":[hex(x) for x in calls(0x5AB020)],"client_executed":False,"server_wire_tested":False,"N0_to_gui_open_proven":False},ensure_ascii=False,indent=2))
