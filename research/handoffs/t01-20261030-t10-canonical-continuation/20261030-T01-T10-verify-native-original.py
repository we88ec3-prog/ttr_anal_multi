#!/usr/bin/env python3
"""T01 bounded KR Tartaros PE32 native source validation. Read-only; no game execution."""
import hashlib, json, struct, pathlib, datetime
from zoneinfo import ZoneInfo
BIN = pathlib.Path('/mnt/data/Tartaros.bin')
EXE = pathlib.Path('/mnt/data/Tartaros.exe')
B_SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
E_SHA = '03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f'

def sha(x): return hashlib.sha256(x).hexdigest()
def raw(va):
    if 0x401000 <= va < 0xbd2000: return va - 0x400c00
    if 0xbd2000 <= va < 0xd61000: return va - 0x401a00
    raise ValueError('VA must be in verified KR .text or .rdata')

def chunk(b,a,z):return b[raw(a):raw(z)]
def u32(b,v):return struct.unpack_from('<I',b,raw(v))[0]

b=BIN.read_bytes();e=EXE.read_bytes()
assert len(b)==12472320 and sha(b)==B_SHA
assert len(e)==2594816 and sha(e)==E_SHA
assert b[raw(0x6d191b):raw(0x6d1920)] == bytes.fromhex('05 d4 07 00 00')
assert b[raw(0x6d19f2):raw(0x6d19f9)] == bytes.fromhex('88 8c 13 d4 07 00 00')
assert b[raw(0x6d4d93):raw(0x6d4d98)] == bytes.fromhex('83 fe 27 77 16')
assert b[raw(0x6d4d05):raw(0x6d4d15)] == bytes.fromhex('8d 86 ef d8 ff ff 3d 0e 27 00 00 b8 01 00 00 00')
assert b[raw(0x547305):raw(0x54730f)] == bytes.fromhex('2b 46 04 3d f4 01 00 00 76 4f')
assert b[raw(0x5467f1):raw(0x5467f7)] == bytes.fromhex('8b 55 10 66 89 1a')
assert b[raw(0x59642e):raw(0x596433)] == bytes.fromhex('e9 7a 01 00 00')
assert b[raw(0x59643f):raw(0x596444)] == bytes.fromhex('e8 9c e8 13 00')
assert b[raw(0x54897e):raw(0x548992)] == bytes.fromhex('83 3d 98 a7 fb 00 00 b9 68 00 00 00 8d 53 01 66 89 4c 24 14')
assert b[raw(0x545b38):raw(0x545b45)] == bytes.fromhex('83 3d d0 48 fe 00 06 8b 74 24 14 76 2e')
assert b[raw(0x4b01fb):raw(0x4b0204)] == bytes.fromhex('b8 39 8e e3 38 f7 e1 d1 ea')
assert b[raw(0x4b039e):raw(0x4b03a1)] == bytes.fromhex('83 c7 09')
assert b[raw(0x4c8c33):raw(0x4c8c40)] == bytes.fromhex('8a 45 08 88 81 b0 00 00 00 5d c2 04 00')
V=[0xC07554,0xC076AC,0xC07B44,0xC0C824,0xC0C8C4,0xC0C9DC,0xC0CA9C]
assert all(u32(b,v+0x58)==0x4c8c30 for v in V)
assert u32(b,0xC51758)==0x8069a0 and u32(b,0xC51754)==0x8068b0
assert all(u32(b,0x547370+4*k)==v for k,v in enumerate([0x5472a7,0x5472db,0x5472f6,0x54734b]))
S=[(0x4914a0,0x4914c0),(0x6d1480,0x6d1a10),(0x6d1915,0x6d1a0d),(0x6d4a30,0x6d4b10),(0x6d4bac,0x6d4bd0),(0x6d4ce0,0x6d4dbe),(0x547240,0x54735e),(0x5467f1,0x546807),(0x548918,0x5489b9),(0x59642e,0x596457),(0x545b38,0x545b73),(0x4b01f0,0x4b0215),(0x4b0250,0x4b031f),(0x4b0390,0x4b03b0),(0x4c8c30,0x4c8c40)]
wins=[{'va_begin':f'0x{a:08X}','va_end_exclusive':f'0x{z:08X}','byte_count':z-a,'sha256':sha(chunk(b,a,z))} for a,z in S]
result={'timestamp_taipei':datetime.datetime.now(ZoneInfo('Asia/Taipei')).isoformat(timespec='seconds'),'mode':'KR offline raw byte verification only','main_baseline':'5a38070c762855b73f5fb563f0e673df5e1f940f','bin_bytes':len(b),'bin_sha256':sha(b),'exe_bytes':len(e),'exe_sha256':sha(e),'windows':wins,'assertions_passed':15,'vtable_candidates':[hex(v) for v in V],'vtable_slot_58':'0x4c8c30','transport_table_0xc51748':{'slot_0xc':'0x8068b0','slot_0x10':'0x8069a0'},'scope_warning':'Native byte and bounded instruction windows, not whole-document R3 or Server protocol verification.'}
out=pathlib.Path('/mnt/data/T01_T10_20261030_native_validation.json')
out.write_text(json.dumps(result,indent=2,ensure_ascii=False)+'\n',encoding='utf-8')
print(json.dumps({'success':True,'windows':len(wins),'results':str(out),'target_sha256':result['bin_sha256']},ensure_ascii=False))
