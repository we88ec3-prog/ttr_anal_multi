#!/usr/bin/env python3
"""E73 RR-0010 raw KR BIN native boundary checks, source-only; no runtime claim.

Usage: python 20261031-chatgpt-web-roy-E73-RR0010-verify.py Tartaros.bin
"""
from __future__ import annotations
import hashlib,struct,sys,re
from pathlib import Path
P=Path(sys.argv[1]) if len(sys.argv)>1 else Path('Tartaros.bin')
b=P.read_bytes()
assert hashlib.sha256(b).hexdigest()=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91', 'Incorrect KR source'
pe=struct.unpack_from('<I',b,0x3c)[0];base=struct.unpack_from('<I',b,pe+52)[0];sects=[]
for i in range(struct.unpack_from('<H',b,pe+6)[0]):
    p=pe+24+struct.unpack_from('<H',b,pe+20)[0]+i*40
    vsize,vaddr,rsize,roff=struct.unpack_from('<IIII',b,p+8)
    sects.append((b[p:p+8].rstrip(b'\0').decode('ascii'),base+vaddr,roff,rsize))
def roff(va):
    for name,v,raw,size in sects:
        if v<=va<v+size:return raw+va-v
    raise AssertionError(f'unmapped VA {va:x}')
def get(va,size):return b[roff(va):roff(va)+size]
def u32(va):return struct.unpack('<I',get(va,4))[0]
def expect(va,data,note):
    bb=bytes.fromhex(data)
    assert get(va,len(bb))==bb,f'{note} at {va:#x}: actual={get(va,len(bb)).hex()} expected={bb.hex()}'
    checks.append((hex(va),note))
def has(start,end,data,note):
    assert bytes.fromhex(data) in b[roff(start):roff(end)],f'{note} {start:#x}..{end:#x}'
    checks.append((hex(start),note))
def callat(src,tgt):
    q=get(src,5)
    assert q[0]==0xE8 and src+5+struct.unpack_from('<i',q,1)[0]==tgt,f'call {src:#x}->{tgt:#x}'
    checks.append((hex(src),f'direct call->{tgt:#x}'))
checks=[]
assert ('.text',0x401000,0x400,0x7d0200) in sects
# RTTI / FUI vtable identification
assert b'\x2e\x3f\x41\x56\x43\x45\x78\x70\x65\x64\x69\x74\x69\x6f\x6e\x43\x72\x65\x61\x74\x65\x44\x69\x61\x6c\x6f\x67\x40\x46\x55\x49\x40\x40' in b
expect(0x671f35,'c7 06 84 57 c3 00','Expedition dialog vptr 0xC35784')
assert u32(0xC35784+87*4)==0x671fd0;checks.append(('vptr[87]','Expedition UI callback'))
assert u32(0xC3F024+87*4)==0x6bf2a0;checks.append(('employ vptr[87]','different event sender'))
# Control event and confirmation chain
expect(0x672004,'3d 78 05 00 00','GUI click event 0x578')
expect(0x67206f,'c7 40 10 44 42 0f 00','emits local F4244 confirmation/event')
expect(0x672154,'3d 44 42 0f 00','F4244 event result')
expect(0x67215b,'81 79 14 a7 06 00 00','confirmation subcode 0x6A7')
callat(0x672165,0x672180)
# Name input and validation
expect(0x6721ba,'8b b0 f0 00 00 00','dialog text control')
expect(0x6721da,'83 be 1c 01 00 00 08','SSO buffer branch, NOT max name')
expect(0x672240,'0f b7 06','read UTF16 code unit')
expect(0x672243,'b9 80 00 00 00','ASCII/nonASCII threshold')
expect(0x672358,'8d 48 d0','ASCII numeric class')
expect(0x672364,'8d 50 bf','ASCII uppercase class')
expect(0x672370,'83 c0 9f','ASCII lowercase class')
for va in (0x672274,0x672288,0x67229c,0x6722b0):
    callat(va,0x81eb80)
# Positive C2S opcode and field layout
expect(0x672505,'56','push name source')
expect(0x672506,'8d 54 24 2a','wide-char name field dest: S+0x26')
expect(0x67250a,'b9 3e 00 00 00','app opcode 0x003E')
expect(0x67250f,'6a 15','21 WCHAR units')
expect(0x672512,'66 89 4c 24 2c','inner payload [S+0x20] = opcode; name begins at +6')
callat(0x672517,0x892e4d)
expect(0x67251f,'83 3d 98 a7 fb 00 00','send gating FBA798==0')
expect(0x672528,'8b 0d 54 a8 fb 00','network queue object FBA854')
expect(0x672530,'8b 40 10','virtual send +0x10')
expect(0x672533,'6a 30','inner payload len48')
expect(0x672535,'8d 54 24 24','inner payload ptr S+0x20')
expect(0x67253a,'6a 00','queue slot0')
expect(0x67253c,'ff d0','virtual send/enqueue')
# wcsncpy-like helper, bounded units, not a byte-copy
expect(0x892e87,'0f b7 08','name helper loads WCHAR')
expect(0x892e8a,'66 89 0c 02','name helper writes WCHAR')
expect(0x892e96,'4f','name helper decrements count')
# inbound handler: Scene registration 0x4A, non-symmetric with 0x003E
expect(0x4c14e1,'c7 86 fc 60 00 00 d0 21 4c 00','LOGIN scene dispatch index 0x4A -> 4C21D0')
assert (0x60fc-0x5eac)//8==0x4a and (0x60fc-0x5eac)%8==0;checks.append(('scene+60fc','index0x4a from handler offset base scene+5eac'))
expect(0x4c14eb,'c7 86 ec 61 00 00 f0 21 4c 00','separate index0x68 handler')
expect(0x4c21d6,'0f bf 48 02','result = signed WORD at incoming+2')
expect(0x4c21db,'68 45 42 0f 00','local event F4245')
callat(0x4c21e0,0x58ab80)
# Local event switch (0xF4245 -> case0)
expect(0x5a680e,'05 bb bd f0 ff','switch input minus 0xF4245')
assert u32(0x5a6988)==0x5a6886 and get(0x5a69a0,4)==b'\x00\x01\x02\x03'
checks.append(('5A6988','F4245 dispatch->5A6886'))
callat(0x5a6895,0x672570)
expect(0x5a689a,'83 7b 14 01','outer successful context status==1')
callat(0x5a68aa,0x5f4910);callat(0x5a68b5,0x5f4950)
expect(0x5a68ba,'c7 87 44 01 00 00 01 00 00 00','sets UI local ready flag')
# Result callback status and name persistence
expect(0x67259f,'8b 45 0c','reads event ptr')
expect(0x6725a2,'8b 40 14','reads local event+0x14 status')
expect(0x6725a5,'b9 01 00 00 00','success==1')
expect(0x672617,'6a 14 56 6a 15 68 f2 38 f9 00','on success UTF16 field copied to global F938F2, cap21')
expect(0x67264a,'83 cf ff','-1 fallback marker')
expect(0x6727af,'83 f8 fe','-2 distinct failure')
expect(0x672817,'83 f8 fd','-3 distinct failure')
expect(0x5f49b8,'ba f2 38 f9 00','UI name render from persisted local name')
# Distinguish 0x3E name creation from C2S0x42 select and 0x33 employ
expect(0x4a38db,'b8 33 00 00 00','employ sends 0x33')
expect(0x4a3b80,'55','C2S0x42 separate builder exists')
print(f'PASS: {len(checks)} distinct native structural checks, {P.name}, sha256 {hashlib.sha256(b).hexdigest()}')
for va,note in checks:print(va,note)
print('SCOPE: native Client-only C2S0x3E builder / S2C0x4A scene handler / F4245 event; no original Server trace, no roster causal claim')
