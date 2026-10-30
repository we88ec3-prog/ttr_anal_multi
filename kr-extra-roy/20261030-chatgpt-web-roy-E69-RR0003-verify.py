#!/usr/bin/env python3
"""E69 RR-0003 first-hand KR PE static assertions (NOT runtime/wire tests).
Run: python 20261030-chatgpt-web-roy-E69-RR0003-verify.py /path/to/Tartaros.bin
"""
import sys,struct,hashlib,json
from pathlib import Path
p=Path(sys.argv[1] if len(sys.argv)>1 else "Tartaros.bin")
b=p.read_bytes()
assert hashlib.sha256(b).hexdigest()=="9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91"
pe=struct.unpack_from("<I",b,0x3c)[0]
assert b[:2]==b"MZ" and b[pe:pe+4]==b"PE\x00\x00"
assert struct.unpack_from("<H",b,pe+24)[0]==0x10b
num=struct.unpack_from("<H",b,pe+6)[0]
off=pe+24+struct.unpack_from("<H",b,pe+20)[0]
sections={}
for i in range(num):
    t=off+40*i
    name=b[t:t+8].split(b"\x00")[0].decode()
    virt,va,rawsize,raw=struct.unpack_from("<IIII",b,t+8)
    sections[name]=(0x400000+va,virt,rawsize,raw)
def read(addr,n):
    for name,(v,virt,rs,raw) in sections.items():
        if v<=addr and addr+n<=v+rs:
            return b[raw+addr-v:raw+addr-v+n]
    raise ValueError("VA not backed by raw file: "+hex(addr))
def hit(addr,hexval): return read(addr,len(bytes.fromhex(hexval)))==bytes.fromhex(hexval)
def direct_e8(target):
    va,vs,rs,raw=sections[".text"]
    d=b[raw:raw+rs]
    return [va+i for i in range(len(d)-4) if d[i]==0xe8 and va+i+5+struct.unpack_from("<i",d,i+1)[0]==target]
test=[]
def ck(label,good):
    test.append((label,bool(good)))
    if not good:raise AssertionError(label)
ck("mode 52 → builder E8",hit(0x440796,"83f852") and direct_e8(0x4A3360)==[0x4407c2])
ck("mode 54/default → builder 000F",direct_e8(0x4A31B0)==[0x4407f7,0x440822])
ck("E8 opcode",hit(0x4A33AB,"b9e8000000") and hit(0x4A33B0,"66894c2474"))
ck("E8 last WORD source +BF80",hit(0x4A33B5,"668b8a80bf0000") and hit(0x4A33C5,"66898c24e6000000"))
ck("E8 narrow fields 51+51",hit(0x4A34D3,"6a3352e87e063f00") and hit(0x4A34E6,"6a3350e86b063f00"))
ck("E8 send pointer and length 0x70",hit(0x4A34FC,"6a708d442478506a01ffd2"))
ck("E8 WCTMB four calls",all(hit(v,"ffd6") for v in (0x4A3455,0x4A3475,0x4A34AA,0x4A34C8)))
ck("E8 WCTMB import",hit(0x4A344E,"8b35cc21bd00"))
ck("E8 WCTMB CodePage zero stack",hit(0x4A343E,"535353536aff5653") and hit(0x4A3470,"6aff505353"))
ck("000F opcode store",hit(0x4A31EC,"66898dc4feffff"))
ck("000F trailer fixed 10001/34",hit(0x4A31F3,"c7459201000100") and hit(0x4A31FA,"c7459634000000"))
ck("000F +BF80 state WORD",hit(0x4A3266,"8b0d1813fb00") and hit(0x4A327D,"66895598"))
ck("000F wide copy count 0x33",hit(0x4A327A,"6a3350") and hit(0x4A32A0,"6a3351"))
ck("000F length 0xD6",hit(0x4A32B6,"68d6000000"))
ck("input conversion reads global FBA808",hit(0x47F59E,"a108a8fb00") and hit(0x47F5D9,"8b1508a8fb00"))
ck("input conversion first/second WCTMB",hit(0x47F5A5,"ff15cc21bd00") and hit(0x47F5F3,"ff15cc21bd00"))
ck("conversion probe failure branch",hit(0x47F5AD,"3bde751f") and hit(0x47F5BC,"687523bf00"))
ck("MD5/text widening global CP",hit(0x46E2CA,"8b0d08a8fb00") and hit(0x46E31C,"8b1508a8fb00"))
ck("0x13 optional notice before status",hit(0x4C37E7,"8b1508a8fb00") and hit(0x4C3800,"ff15cc21bd00") and hit(0x4C3821,"8a561680fa05"))
ck("0x13 status 0 with UTF16 terminator scan",hit(0x4C3949,"84d2") and hit(0x4C3960,"668b0883c0026685c975f5"))
ck("0x13 count +1C cursor +92",hit(0x4C3A03,"8b461c") and hit(0x4C3A0A,"8d8e92000000"))
ck("0x7A count +2 cursor +6",hit(0x4C3C10,"558bec8b45088b4802") and hit(0x4C3C1A,"8d4806e85ef4ffff"))
ck("group 3 header 10 row",hit(0x4C30BE,"0fb70b") and hit(0x4C30C1,"83c703") and hit(0x4C30FF,"83c70a"))
ck("row +8 filter +9 callee data",hit(0x4C3107,"0fb64e08") and hit(0x4C311A,"0fb65609"))
ck("count0 still F4243",hit(0x4C30AA,"85db") and hit(0x4C314A,"6843420f00"))
ck("0x13 +90 handoff state/event",hit(0x4C3A15,"80be9000000000") and hit(0x4C31E4,"c78754bd000001000000") and hit(0x4C31F4,"6841420f00"))
v,vs,rs,raw=sections[".data"];cp=0xFBA808
ck("CodePage global in virtual zero tail",v+rs<=cp<v+vs)
tv,tvs,trs,traw=sections[".text"]
d=b[traw:traw+trs];tok=bytes.fromhex("08a8fb00")
refs=[tv+i for i in range(len(d)-3) if d[i:i+4]==tok]
assert refs==[0x40410E,0x404159,0x46E2CC,0x46E31E,0x47F59F,0x47F5DB,0x4C37E9],refs
assert 0x92+3+10*2==0xA9 and 6+3+10*2==29
print(json.dumps({"sha256":hashlib.sha256(b).hexdigest(),"checks":len(test),"passed":all(x[1] for x in test),"direct_cp_operands":[hex(x) for x in refs],"tests":[dict(name=n,ok=x) for n,x in test],"client_executed":False,"server_wire_tested":False},ensure_ascii=False,indent=2))
