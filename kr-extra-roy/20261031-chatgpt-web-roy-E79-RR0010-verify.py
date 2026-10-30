#!/usr/bin/env python3
"""E79/RR-0010: exact KR BIN evidence for 0x2B network ingress -> global
Client handler -> 2+53N rows -> SAME slot array as S2C app2.
Only static original-machine-code assertions; does NOT pair any original Server transaction.
Usage: python -B 20261031-chatgpt-web-roy-E79-RR0010-verify.py Tartaros.bin
"""
from pathlib import Path
import hashlib, struct, sys
p = Path(sys.argv[1] if len(sys.argv)>1 else '/mnt/data/Tartaros.bin')
b = p.read_bytes()
expected = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
checks=[]
def ck(name, test):
    if not test: raise AssertionError(name)
    checks.append(name)
def u16(pos):return struct.unpack_from('<H',b,pos)[0]
def u32(pos):return struct.unpack_from('<I',b,pos)[0]
ck('size',len(b)==12472320)
ck('source SHA256',hashlib.sha256(b).hexdigest()==expected)
ck('PE header',b[:2]==b'MZ' and b[u32(0x3c):u32(0x3c)+4]==b'PE\0\0')
pe=u32(0x3c);opt=pe+24
ck('x86 machine',u16(pe+4)==0x14c)
ck('image base',u32(opt+28)==0x400000)
sections={}
for i in range(u16(pe+6)):
    s=opt+u16(pe+20)+40*i
    sections[b[s:s+8].rstrip(b'\x00').decode()]=(u32(s+12),u32(s+20),u32(s+16))
ck('text section VA/raw/size',sections['.text']==(0x1000,0x400,0x7d0200))
ck('rdata section VA/raw',sections['.rdata'][:2]==(0x7d2000,0x7d0600))
def off(va):
    rva=va-0x400000
    for rv,raw,n in sections.values():
        if rv<=rva<rv+n:return raw+(rva-rv)
    raise ValueError(hex(va))
def bits(va,length):return b[off(va):off(va)+length]
def match(va,hex_data,label):
    exp=bytes.fromhex(hex_data)
    ck(label,bits(va,len(exp))==exp)
def val(va):return u32(off(va))
def call(va,target):
    at=off(va)
    ck('direct E8 '+hex(va)+'→'+hex(target),b[at]==0xe8 and va+5+struct.unpack_from('<i',b,at+1)[0]==target)

# Network manager route: default 16-byte callback table; app 0x2B override.
match(0x493170,'535657bf6043490033db8d9010020000bed50b0000b97523bf00','network manager table setup')
match(0x493190,'897af8895afc890a83c2104e75f2','16-byte stride default entries')
ck('network override offset is index 0x2B',0x208+0x10*0x2b==0x4b8)
match(0x493375,'bab04349008990b8040000','network 0x2B override target 4943B0')
match(0x4943b0,'558bec83e4f86aff','F8D9E0 callback entry')
match(0x49440c,'8b45108b4d0c8b550850a1e0d9f80051528b5004b9e0d9f800ffd2','callback forwards original payload/len/app command to F8D9E0 vtable+4')
match(0x4e15c4,'c705e0d9f8005cd1c000','F8D9E0 ctor installs vptr C0D15C')
ck('F8D9E0 vptr method+4 = 4FDA30',val(0xC0D160)==0x4fda30)
match(0x4fda30,'558bec51568bf18b4d10570fbff98b44fe04','F8D9E0 dispatcher signed app index handler')
match(0x4fda63,'8b4cfe08536a068d5cfe08','F8D9E0 handler context/metadata')
match(0x4fda85,'5250518bceff55fc','invoke selected handler with F8D9E0 owner')
# Handler table is built lazily, not static PE data prepopulated.
match(0x4e1af4,'b8e0d9f800891d1443f900e89c020000','F8D9E0 lazy initialization selects table base')
call(0x4e1aff,0x4e1da0)
match(0x4e1da0,'568d5008bed50b0000b97523bf00','F8D9E0 app-handler table ctor')
match(0x4e1db0,'c742fc407d4b00890a83c2084e75f1','8-byte handler entries default to virtual trampoline')
ck('0x2B handler offset',4+8*0x2b==0x15c)
match(0x4e1e3f,'c7805c01000030274e00','F8D9E0 index0x2B assigned 4E2730')
ck('registered handler value',val(0x4e1e3f+6)==0x4e2730)
# Real handler: 2-byte prefix plus 53-byte character records; alias proof.
match(0x4e2730,'558bec518b450c568bf18975fc83f802','2+53N packet consumer and owner ESI=ECX')
match(0x4e2746,'8d48feb8b3cf2135f7e1','2-byte prefix count formula')
match(0x4e275f,'8b7d0883c702','first record begins at buffer+2')
match(0x4e2767,'0fb6472e83f809771a','row+2e index <=9 gate')
match(0x4e2770,'69c010020000038624690000','index*0x210 + [owner+0x6924]')
call(0x4e2782,0x4d4150)
match(0x4e278a,'83c7354b75d7','advance 53 bytes and loop')
call(0x4e2794,0x4e5fb0)
ck('same *address* for pointer F94304',0xf8d9e0+0x6924==0xf94304)
match(0x4e19d8,'c645fc046a7489350443f900','Client singleton allocation/write F94304 slot array')
match(0x4b899a,'69c01002000003050443f900','app2 uses [F94304] and same stride')
match(0x4d4150,'578d7e0cc7465c01000000','common 53-byte writer makes local record+5C=1')
match(0x4b8a97,'b9e0d9f800','app2 post-processing calls same F8D9E0 owner')
call(0x4b8a9c,0x4e5fb0)
# Negative controls: this report doesn't claim matching responses.
match(0x6bf2f5,'e88653d5ffe8d145deff','other state CEmployNewCharacter calls C2S0x33')
call(0x6bf2fa,0x4a38d0)
match(0x4a38db,'b833000000','C2S0x33 command 2-byte candidate')
match(0x67250a,'b93e000000','different C2S0x3E name creation opcode')
match(0x4c21d6,'0fbf4802','S2C0x4A separate signed result path')
match(0x4b5e27,'6878420f00','S2C0xB6 event F4278 separate')
print('E79 RR-0010: PASS',len(checks),'native BIN assertions; SHA256',expected)
print('S2C app0x2B bounded dispatch -> F8D9E0 -> 4E2730 -> same F94304 record-array cell as app2')
print('not proven: original Server C2S33/3E to S2C2B/4A/B6 transaction pairing or chronology')
