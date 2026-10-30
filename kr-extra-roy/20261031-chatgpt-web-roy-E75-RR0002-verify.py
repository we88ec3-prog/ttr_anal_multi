#!/usr/bin/env python3
"""E75 RR-0002: bounded original KR BIN native evidence verifier; no target execution."""
from pathlib import Path
import hashlib, struct, sys

EXPECTED_SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
SOURCE = Path(sys.argv[1] if len(sys.argv)>1 else '/mnt/data/Tartaros.bin')
b = SOURCE.read_bytes()
passed=[]
def eq(name, got, expected):
    if got!=expected: raise AssertionError(f'{name}: {got!r} != {expected!r}')
    passed.append(name)

eq('KR sha256', hashlib.sha256(b).hexdigest(), EXPECTED_SHA)
eq('KR file size', len(b), 12472320)
nt = struct.unpack_from('<I',b,0x3c)[0]
eq('PE signature', b[nt:nt+4], b'PE\0\0')
num=struct.unpack_from('<H',b,nt+6)[0]
opt=struct.unpack_from('<H',b,nt+20)[0]
image=struct.unpack_from('<I',b,nt+24+28)[0]
eq('ImageBase',image,0x400000)
sections=[]
for i in range(num):
    o=nt+24+opt+i*40
    name=b[o:o+8].split(b'\0')[0].decode('ascii','replace')
    virt, rva, rawsize, raw=struct.unpack_from('<IIII',b,o+8)
    sections.append((name,image+rva,raw,rawsize))

def va2raw(v):
    for name, addr,raw,rawsize in sections:
        if addr<=v<addr+rawsize:return raw+v-addr
    raise ValueError(f'VA {v:08x} not mapped')

def bytes_at(v,count):return b[va2raw(v):va2raw(v)+count]
def check(v,pattern,name):eq(name,bytes_at(v,len(bytes.fromhex(pattern))),bytes.fromhex(pattern))
def u32(v):return struct.unpack_from('<I',b,va2raw(v))[0]
def check_call(v,dest,name):
    op=bytes_at(v,5)
    eq(name+' opcode',op[:1],b'\xe8')
    eq(name+' destination',(v+5+struct.unpack('<i',op[1:])[0])&0xffffffff,dest)

eq('.text section', next((x[1],x[2]) for x in sections if x[0]=='.text'),(0x401000,0x400))
# Sender and exact roster local processing are previous E61/E74, repeated only as bounded chain anchors.
check(0x4A3B91,'b842000000','C2S selection 0x42 local builder')
check(0x4A3BAD,'6a04','C2S 42 four-byte length')
check(0x4A3BB3,'6a00','C2S 42 queue slot0')
check(0x4B89DC,'ba26000000','roster per-row opcode 0x26')
check(0x4B89F7,'6a03','roster per-row length3')
check(0x4B89FE,'6a00','roster per-row queue slot0')
check(0x4B8AC4,'b924000000','roster post opcode 0x24')
check(0x4B8ADB,'6a02','roster post length2')
# First-level BASE scene index26 is explicit; index24 not an override in bounded initializer.
check(0x4ADEED,'c7803401000060304b00','base scene index 0x26 -> 4B3060')
eq('0x26 index arithmetic',(0x134-4)//8,0x26)
baseinit=bytes_at(0x4ADD50,0x4AE380-0x4ADD50)
present=[]
for i in range(len(baseinit)-10):
    if baseinit[i:i+2]==b'\xc7\x80':
        d,h=struct.unpack_from('<II',baseinit,i+2)
        if d>=4 and (d-4)%8==0:present.append((d-4)//8)
eq('base index 0x24 lacks explicit C7 80 override',0x24 in present,False)
check(0x4B3063,'e8f8bff5ff','S2C26 delegate calls global CGameInfo getter')
check_call(0x4B3063,0x40F060,'S2C26 getter call')
check(0x4B3068,'8b55108b088b018b4004','S2C26 virtual slot 1 from CGameInfo')
check(0x4B3072,'528b550c528b550852ffd0','S2C26 passes payload,length,id to slot1')
check(0x40F0B4,'b830b1fa00','singleton getter returns &FAB130')
check(0x4DECDD,'6a40a330b1fa00','singleton CGameInfo allocated pointer saved at FAB130')
check_call(0x4DECD4,0x4DD700,'singleton CGameInfo ctor')
check(0x4DD702,'c701a0cec000','CGameInfo vtable assigned')
eq('CGameInfo RTTI COL',u32(0xC0CEA0-4),0xC6AE2C)
eq('CGameInfo RTTI descriptor',u32(0xC6AE2C+12),0xF7E8E0)
eq('CGameInfo RTTI class',bytes_at(0xF7E8E0+8,15),b'.?AVCGameInfo@@')
eq('CGameInfo slot1 dispatch method',u32(0xC0CEA0+4),0x4FDA30)
eq('CGameInfo slot3 missing-handler method',u32(0xC0CEA0+12),0x4227F0)
check_call(0x4DD7A1,0x4DD8F0,'CGameInfo ctor table init')
check(0x4DD8F1,'8d4108','CGameInfo handler table starts object+4')
check(0x4DD8F4,'bad50b0000','CGameInfo 0xBD5 table slots initialized')
check(0x4DD900,'c740fc407d4b00','CGameInfo default 4B7D40')
check(0x4DD963,'c7813401000020e04d00','CGameInfo index0x26 -> 4DE020')
check(0x4FDA37,'8b4d1057','CGameInfo dispatcher reads 3rd argument')
check(0x4FDA3B,'0fbff9','CGameInfo signextends command index')
check(0x4FDA3E,'8b44fe04','CGameInfo loads indexed callback')
check(0x4FDA45,'85c0','CGameInfo null callback gate')
check(0x4FDA4E,'8b400c','CGameInfo null falls to vtable+0xC')
check(0x4FDA63,'8b4cfe08','CGameInfo non-null reads indexed cookie')
check(0x4FDA85,'5250518bceff55fc','CGameInfo callback forwards 3 args')
check(0x4FDA8F,'81fe05400080','CGameInfo compares failure HRESULT')
check(0x4227F3,'0fbf4510','CGameInfo fallback formats incoming id')
check(0x422805,'b805400080','CGameInfo fallback returns 80004005')
# The actual indexed response handler 0x26, not just a guessed request+1 pairing.
check(0x4DE045,'8b450c','S2C26 handler reads payload length')
check(0x4DE048,'83f804','S2C26 len >=4 gate')
check(0x4DE054,'b8cdcccccc','S2C26 divide by 5 reciprocal')
check(0x4DE05E,'8bb1dc5e0000','S2C26 record-list end pointer')
check(0x4DE091,'8b750883c604','S2C26 rows begin payload+4')
check_call(0x4DE0A2,0x4DE9C0,'S2C26 five-byte row appender')
check(0x4DE0A7,'83c605','S2C26 rows advance 5B')
check(0x4DE0DD,'6861420f00','S2C26 emits local F4261')
check_call(0x4DE0E2,0x58AAD0,'S2C26 local notify call')
check(0x4DE9FA,'8b108911','five-byte appender copies first DWORD')
check(0x4DE9FE,'8a4004884104','five-byte appender copies last byte')
check(0x5DE800,'b861420f00','F4261 typed local event id getter')
print('E75 native checks PASS',len(passed),'file',str(SOURCE))
