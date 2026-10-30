#!/usr/bin/env python3
"""T01 2026-10-30: independent KR native spot checks, not complete Conn+14 xref scan."""
import hashlib,json,struct,sys
from pathlib import Path
b=Path(sys.argv[1] if len(sys.argv)>1 else '/mnt/data/Tartaros.bin').read_bytes()
digest=hashlib.sha256(b).hexdigest()
assert len(b)==12472320 and digest=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
pe=struct.unpack_from('<I',b,0x3c)[0]
assert b[pe:pe+4]==bytes([80,69,0,0])
base=struct.unpack_from('<I',b,pe+24+28)[0]
assert base==0x400000
sec=pe+24+struct.unpack_from('<H',b,pe+20)[0]
sections={}
for i in range(struct.unpack_from('<H',b,pe+6)[0]):
    off=sec+i*40
    name=b[off:off+8].split(bytes([0]))[0].decode('ascii')
    size,rva,rawsize,raw=struct.unpack_from('<IIII',b,off+8)
    sections[name]=(base+rva,raw,rawsize)
assert sections['.text'][:2]==(0x401000,0x400)
assert sections['.rdata'][:2]==(0xBD2000,0x7D0600)
def native(va,size,section='.text'):
    start,raw,count=sections[section]
    p=raw+va-start
    assert raw<=p and p+size<=raw+count
    return b[p:p+size]
checks={
0x490fe0:'55 8b ec',0x49104b:'8b 41 34',0x49104f:'ff 15 4c 22 bd 00',
0x49108c:'8b 58 08',0x49108f:'39 b3 ac a0 00 00',0x4910c5:'39 98 58 bf 00 00',
0x49117c:'ff 48 44',0x491193:'e8 68 c5 2b 00',0x4911b7:'c7 43 14 00 00 00 00',
0x491203:'e8 38 49 37 00',0x805b30:'c7 42 14 00 00 00 00',
0x806778:'c7 40 14 00 00 00 00',0x805f6d:'89 5e 14',
0x805b58:'83 79 14 00',0x805ba6:'8b 8e b8 a0 00 00',
0x805bb7:'e8 94 03 00 00',0x805fda:'e8 01 04 00 00',
0x7b6ac7:'e8 40 a7 0d 00',0x891212:'e9 e5 0e 00 00',
0x5009d8:'83 78 04 01',0x500a58:'83 78 04 02',0x5008f3:'e8 08 01 00 00'}
for va,hexdump in checks.items():
    x=bytes.fromhex(hexdump)
    assert native(va,len(x))==x,hex(va)
rel={
0x491193:0x74d700,0x491203:0x805b40,0x805bb7:0x805f50,
0x805fda:0x8063e0,0x7b6ac7:0x89120c,0x891212:0x8920fc,0x5008f3:0x500a00}
for va,to in rel.items():
    op=native(va,5)
    assert op[0] in (0xe8,0xe9)
    actual=(va+5+struct.unpack('<i',op[1:])[0])&0xffffffff
    assert actual==to,(hex(va),hex(actual),hex(to))
assert struct.unpack('<I',native(0xc05ad4,4,'.rdata'))[0]==0x490fe0
print(json.dumps({'status':'PASS','target_sha256':digest,'native_bytes':len(checks),
'direct_rel32':len(rel),'vtable':'0xC05AD4->0x490FE0',
'limitation':'R2 limited bytes, not complete CFG/ownership/FULL-PASS'},ensure_ascii=False))
