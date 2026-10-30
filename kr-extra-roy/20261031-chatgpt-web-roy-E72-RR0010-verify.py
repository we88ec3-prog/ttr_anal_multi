#!/usr/bin/env python3
"""RR-0010 E72: KR native static checks, never starts or patches client.
Usage: python RR0010-E72-verify.py /path/to/Tartaros.bin
No native server wire/result pairing is implied by a PASS.
"""
import hashlib
import json
import struct
import sys
from pathlib import Path

p=Path(sys.argv[1]) if len(sys.argv)>1 else Path('Tartaros.bin')
b=p.read_bytes()
EXPECTED='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
assert hashlib.sha256(b).hexdigest()==EXPECTED
pe=struct.unpack_from('<I',b,0x3c)[0]
assert b[:2]==b'MZ' and b[pe:pe+4]==b'PE\0\0'
assert struct.unpack_from('<H',b,pe+24)[0]==0x10b
n=struct.unpack_from('<H',b,pe+6)[0]
s=pe+24+struct.unpack_from('<H',b,pe+20)[0]
sections={}
for k in range(n):
    off=s+k*40
    name=b[off:off+8].split(b'\0')[0].decode()
    virtual_size,rva,raw_size,raw=struct.unpack_from('<IIII',b,off+8)
    sections[name]=(0x400000+rva,raw_size,raw)
def read(va,size):
    for start,raw_size,raw in sections.values():
        if start<=va and va+size<=start+raw_size:
            return b[raw+va-start:raw+va-start+size]
    raise ValueError(f'VA outside raw sections: {va:#x}')
def checked(addr,hexbytes):
    actual=read(addr,len(bytes.fromhex(hexbytes)))
    return actual==bytes.fromhex(hexbytes)
def u32(addr):return struct.unpack('<I',read(addr,4))[0]
assert sections['.text'][:1]==(0x401000,)
checks={}
def ck(name,truth):
    checks[name]=bool(truth)
    if not truth:raise AssertionError(name)

ck('second table initial base/counter',checked(0x4e1da0,'568d5008bed50b0000'))
ck('second table default handler',checked(0x4e1db0,'c742fc407d4b00'))
ck('second table 8byte stride',checked(0x4e1db9,'83c208'))
ck('second table 0x2b-specific override',checked(0x4e1e3f,'c7805c01000030274e00'))
ck('second table 0x67-specific override',checked(0x4e1e2f,'c7803c03000010274e00'))
ck('default handler delegates scene virtual+0x0c',checked(0x4b7d40,'8b01ff600c'))
initializer=read(0x4e1da0,0x4e23d1-0x4e1da0)
overrides=[]
for i in range(len(initializer)-9):
    if initializer[i:i+2]==b'\xc7\x80':
        disp,target=struct.unpack_from('<II',initializer,i+2)
        if 0<=disp<0x5ee0 and 0x401000<=target<0xbd2000:
            overrides.append((0x4e1da0+i,disp,target))
ck('97 explicit native overrides in second init',len(overrides)==97)
ck('second table index0x33 lacks explicit init override',not any(disp==4+8*0x33 for _,disp,_ in overrides))
ck('second table index0x2b points 4e2730',any(disp==4+8*0x2b and target==0x4e2730 for _,disp,target in overrides))

ck('alternate 53byte entry length >=2 test',checked(0x4e273d,'83f802'))
ck('alternate row cursor begins +2',checked(0x4e275f,'8b7d0883c702'))
ck('alternate slot index from row+2e',checked(0x4e2767,'0fb6472e'))
ck('alternate slot index <=9',checked(0x4e276b,'83f809') and checked(0x4e276e,'771a'))
ck('alternate destination Client+6924',checked(0x4e2770,'69c010020000') and checked(0x4e2776,'038624690000'))
ck('alternate copy uses shared record writer',checked(0x4e277e,'8bd78bf0') and checked(0x4e2782,'e8c919ffff'))
ck('alternate advances 0x35 bytes',checked(0x4e278a,'83c735'))
ck('alternate common post even when no rows',checked(0x4e2759,'85c9') and checked(0x4e275b,'7435') and checked(0x4e2794,'e817380000'))

ck('command2 header minimum 65',checked(0x4b8926,'83f941'))
ck('command2 row cursor +0x6f relative enclosing buffer',checked(0x4b8952,'8b7c2428') and checked(0x4b8956,'83c76f'))
ck('command2 copy source row start = cursor-0x2e',checked(0x4b89a8,'8d57d2'))
ck('command2 destination global F94304',checked(0x4b899a,'69c010020000') and checked(0x4b89a0,'03050443f900'))
ck('command2 N0 bypass row loop',checked(0x4b894a,'85c9') and checked(0x4b894c,'0f84ce000000'))

ck('record writer enabled flag',checked(0x4d4154,'c7465c01000000'))
ck('record writer copies UTF16 until NUL with no visible in-loop length gate',checked(0x4d4160,'0fb70866890c0783c0026685c975f1'))
ck('record attributes +2a/+2e/+2f/+30/+31',checked(0x4d416f,'0fb6422e') and checked(0x4d4176,'0fb64a2f') and checked(0x4d4180,'0fb64230') and checked(0x4d418a,'8b4a31') and checked(0x4d4190,'8b522a'))

ck('global first table default handler',checked(0x4b7dc0,'b8002dfd00bac07e4b00'))
ck('global first table command2 explicit',checked(0x4b7ddf,'c7050c2dfd00007f4b00'))
ck('global app 0x33 has no direct init override',bytes.fromhex('942efd00') not in read(0x4b7dc0,0x100))
ck('global fallback scene gate and virtual +4',checked(0x4b7ec3,'83b9ac5e000000') and checked(0x4b7ed2,'8b01') and checked(0x4b7ed4,'8b4004'))

ck('employ ctrl sends only fixed app33 in !mode1',checked(0x6bf2c5,'83b84c5f000001') and checked(0x6bf2fa,'e8d145deff'))
ck('app33 send len2 and slot0',checked(0x4a38db,'b833000000') and checked(0x4a38f1,'6a02') and checked(0x4a38f7,'6a00'))
ck('employ mode1 local alternate path',checked(0x6bf2ce,'e85dbfddff') and checked(0x6bf2d5,'e806080000'))
ck('mode1 helper writes double 1.0 and tag3 to local object',checked(0x6bfae9,'8b02d9e88b4808dd19') and checked(0x6bfaf4,'c7410803000000'))

# Synthetic structure arithmetic only: not a native runtime execution.
for header in [2,65]:
    for count in [0,1,2,10]:
        size=header+53*count
        assert (size-header)//53==count
print(json.dumps({'kr_bin_sha256':EXPECTED,'checks':len(checks),'passed':all(checks.values()),'second_dispatch_overrides':len(overrides),'second_dispatch_0x33_explicit':False,'alternate_parser_slot_index':'0x2b (table local; not a proven wire opcode)','original_server_create_positive_pair':False,'client_executed':False,'checks_detail':checks},ensure_ascii=False,indent=2))