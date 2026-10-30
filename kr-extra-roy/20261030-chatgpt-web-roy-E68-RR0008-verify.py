#!/usr/bin/env python3
"""KR RR-0008 bounded STATIC assertions. No Client/Server execution.
Usage: python E68-RR0008-verify.py /path/to/Tartaros.bin /path/to/Event.stp
"""
from pathlib import Path
from hashlib import sha256
import sys,struct,json
binpath=Path(sys.argv[1]) if len(sys.argv)>1 else Path('/mnt/data/Tartaros.bin')
stppath=Path(sys.argv[2]) if len(sys.argv)>2 else Path('/mnt/data/Event.stp')
b=binpath.read_bytes();s=stppath.read_bytes()
assert sha256(b).hexdigest()=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
assert sha256(s).hexdigest()=='2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b'
sections=[('text',0x401000,0x400,0x7d01f0),('rdata',0xbd2000,0x7d0600,0x18e07c),('data',0xd61000,0x95e800,0x22b800)]
def read(va,n):
    for name,v,offset,sz in sections:
        if v<=va and va+n<=v+sz: return b[offset+va-v:offset+va-v+n]
    raise ValueError(hex(va))
def u32(va): return struct.unpack('<I',read(va,4))[0]
def call_sites(target):
    first=0x401000; blob=read(first,0x7d01f0)
    return [first+i for i in range(len(blob)-4) if blob[i]==0xE8 and (first+i+5+struct.unpack_from('<i',blob,i+1)[0])==target]
def rtti(vptr):
    col=u32(vptr-4); t=u32(col+12)
    return read(t+8,80).split(b'\0')[0].decode('ascii')
checks={}
def check(k,condition):
    checks[k]=bool(condition)
    if not condition:raise AssertionError(k)
check('PE text mapping', read(0x4B21FD,4)==bytes.fromhex('0f bf 76 02'))
check('S2C42 base-table writer',read(0x4ADF3D,10)==bytes.fromhex('c7 80 14 02 00 00 90 21 4b 00'))
check('S2C42 signed WORD payload+2',read(0x4B21FD,4)==bytes.fromhex('0f bf 76 02'))
check('S2C42 length guard len>4',read(0x4B2210,8)==bytes.fromhex('3b fb 0f 86 ae 00 00 00'))
check('S2C42 reads payload+5 after len>4',read(0x4B221C,4)==bytes.fromhex('0f b6 48 01'))
check('S2C42 directs to 20-entry set',read(0x4B2206,5)==bytes.fromhex('e8 05 df 04 00') and read(0x50012b,3)==bytes.fromhex('83 f8 14'))
check('review UI uses 0xFAB2A0', read(0x47D693,5)==bytes.fromhex('68 a0 b2 fa 00'))
check('SceneItem ctor sentinel writer',read(0x47B4C9,6)==bytes.fromhex('89 86 48 02 00 00'))
check('SceneItem record writer',read(0x47B2EF,6)==bytes.fromhex('89 83 48 02 00 00'))
check('SceneItem RTTI',rtti(0xC02F3C)=='.?AVCScenarioReviewSceneItem@FUI@@')
check('ChapterItem RTTI',rtti(0xC02D9C)=='.?AVCScenarioReviewChapterItem@FUI@@')
check('SceneItem writer direct callsite',call_sites(0x47B2B0)==[0x47D36D])
check('review scene reader direct callsite',call_sites(0x47B5C0)==[0x47D5B7])
check('review scene upstream direct callsite',call_sites(0x47D530)==[0x47D9DA])
check('scene double-key entry callsites',call_sites(0x565720)==[0x47B64A,0x561EF3])
check('S2C42 no E8 direct callsite',call_sites(0x4B2190)==[])
check('EndCutScene 47E640 result writer',read(0x561EDE,5)==bytes.fromhex('e8 5d c7 f1 ff') and read(0x561EE5,3)==bytes.fromhex('89 47 3c'))
check('EndCutScene distinct state+38/3c into 565720',read(0x561EEC,9)==bytes.fromhex('8b 57 38 50 52 8b f7 e8 28') )
check('565720 reentrant +28 guard',read(0x565756,4)==bytes.fromhex('83 7e 28 00'))
check('C2S42 request writer',read(0x4A3B91,5)==bytes.fromhex('b8 42 00 00 00'))
check('S2C69 first-level handler writer',read(0x4B7E0F,10)==bytes.fromhex('c7 05 44 30 fd 00 90 90 4b 00'))
check('SceneList tutorial Lua decoded raw source',s[:4]==b'STPD' and sha256(bytes(x^0xff for x in s[0xa1c010:0xa1c21a])).hexdigest()=='1fc158a28915b6f0047941cb8a5c00534aa81c5538d153f1f05b5b2ff012eedc')
check('tutorial source says 1001/1 and register',b'Quest #1001 / Scene #1 - Function tutorial_start' in bytes(x^0xff for x in s[0xa1c010:0xa1c21a]) and b'Register(tutorial_start)' in bytes(x^0xff for x in s[0xa1c010:0xa1c21a]))
print(json.dumps({'source':'KR Tartaros.bin and Event.stp','client_runtime_tested':False,'server_wire_tested':False,'exact_assertions':len(checks),'passed':all(checks.values()),'checks':checks,'E8_callers':{hex(x):[hex(y) for y in call_sites(x)] for x in (0x47B2B0,0x47B5C0,0x47D530,0x565720,0x4B2190)}},ensure_ascii=False,indent=2))
