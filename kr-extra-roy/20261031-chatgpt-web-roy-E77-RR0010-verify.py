#!/usr/bin/env python3
"""E77 / RR-0010: read-only KR original BIN provenance checks.

Use: python -B 20261031-chatgpt-web-roy-E77-RR0010-verify.py /path/Tartaros.bin
Checks validate bytes, registered handler slot arithmetic, event switch, and branch
sources. They do NOT run Client or establish an original Server transaction.
"""
from __future__ import annotations
import hashlib
import struct
import sys
from pathlib import Path

SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
B = Path(sys.argv[1] if len(sys.argv)>1 else 'Tartaros.bin').read_bytes()
checks=[]
def must(label, value):
    if not value: raise AssertionError(label)
    checks.append(label)

def u16(p):return struct.unpack_from('<H', B, p)[0]
def u32(p):return struct.unpack_from('<I', B, p)[0]

must('file length 12472320',len(B)==12472320)
must('original SHA256',hashlib.sha256(B).hexdigest()==SHA)
must('DOS PE',B[:2]==b'MZ' and B[u32(0x3c):u32(0x3c)+4]==b'PE\0\0')
pe=u32(0x3c)
must('x86',u16(pe+4)==0x14c)
opt=pe+24
must('ImageBase 400000',u32(opt+28)==0x400000)
sections={}
for i in range(u16(pe+6)):
    q=opt+u16(pe+20)+i*40
    sections[B[q:q+8].rstrip(b'\0').decode('ascii')]=(u32(q+12),u32(q+20),u32(q+16))
sec=sections.get('.text')
must('text section mapped',sec is not None and sec[0]==0x1000 and sec[1]==0x400 and sec[2]==0x7d0200)

def raw(va):
    rva=va-0x400000
    for rv,off,sz in sections.values():
        if rv <= rva < rv+sz:return off+rva-rv
    raise ValueError(hex(va))

def bytes_at(va,h):
    exp=bytes.fromhex(h);return B[raw(va):raw(va)+len(exp)]==exp

def eq(va,h,label):must(label,bytes_at(va,h))
def w(va):return u32(raw(va))
def direct_call(va,target):
    off=raw(va)
    return B[off]==0xe8 and va+5+struct.unpack_from('<i',B,off+1)[0]==target

eq(0x4ae11d,'c780b4050000d05d4b00','base scene table B6 handler instruction')
eq(0x4ae12d,'c780bc050000505e4b00','base scene table B7 handler instruction')
must('B6 slot relative offset (4+8*0xb6)',4+8*0xb6==0x5b4)
must('B7 slot relative offset (4+8*0xb7)',4+8*0xb7==0x5bc)
must('S2C B6 target 4b5dd0',w(0x4ae11d+6)==0x4b5dd0)
must('S2C B7 target 4b5e50',w(0x4ae12d+6)==0x4b5e50)
eq(0x4b5dd0,'558bec6aff','B6 handler entry')
eq(0x4b5e25,'6a006878420f00','B6 pushes zero and F4278')
must('B6 to local event writer',direct_call(0x4b5e2c,0x58ab80))
eq(0x4b5e34,'33c0','B6 returns zero')
eq(0x4b5e41,'8be55dc20c00','B6 handler ret12')
eq(0x4b5e50,'558bec6aff','B7 handler separate entry')
eq(0x4b5ea8,'8b4508','B7 reads payload')
eq(0x4b5eae,'d94003','B7 floats payload+3')
eq(0x4b5eb1,'8a4802','B7 reads payload+2')
must('F4278 delta from F4245',0xf4278-0xf4245==0x33)
eq(0x5a680e,'05bbbdf0ff','ExpeditionPage event normalized from F4245')
eq(0x5a6813,'83f833','ExpeditionPage event delta upper bound')
eq(0x5a681c,'0fb680a0695a00','ExpeditionPage byte mapping lookup')
eq(0x5a6823,'ff248588695a00','ExpeditionPage jump table lookup')
must('F4278 map index 0x33 to slot4',B[raw(0x5a69a0)+0x33]==4)
must('slot4 target 5a68d8',w(0x5a6988+4*4)==0x5a68d8)
must('slot0 F4245 target 5a6886',w(0x5a6988)==0x5a6886)
must('default slot5 5a6973',w(0x5a6988+4*5)==0x5a6973)
must('F4278 page local result helper 40afc0',direct_call(0x5a68d8,0x40afc0))
eq(0x5a68dd,'83781400','F4278 local status must be zero')
eq(0x5a68e7,'8b9738010000','F4278 page child owner at +138')
eq(0x5a68ed,'5233c9','F4278 invokes with ECX=0')
must('F4278 actual child caller 672f00',direct_call(0x5a68f0,0x672f00))
eq(0x672f00,'558bec83e4f8','role UI helper entry')
eq(0x672f37,'8b5d08','role UI helper reads child dialog arg')
eq(0x672f3e,'89742418','role helper initial owner stored')
eq(0x672f42,'3bf7','role helper ECX zero guard')
eq(0x672f46,'8b83d8000000','role helper reads child+0xd8 index if ECX zero')
eq(0x672f80,'83fe09','role index <=9')
eq(0x672f83,'771e','out of range skips slot lookup')
eq(0x672f85,'8b0d0443f900','role global base F94304')
eq(0x672f8b,'69f610020000','role stride 0x210')
eq(0x672f91,'8b44315c','role +0x5C readiness read')
eq(0x672f95,'03ce','base-plus-index address')
eq(0x672f97,'f7d81bc023c1','conditional mask ready slot pointer')
eq(0x67315e,'85f6','role pointer non-null branch gate')
eq(0x673160,'0f84f0030000','role null branch to 673556')
eq(0x673556,'8b4c241853','null-role path passes owner to helper')
must('null-role path to 673790',direct_call(0x67355b,0x673790))
eq(0x673790,'558bec6aff','unavailable-role UI helper entry')
eq(0x6737f3,'8d46fb','unavailable-role index-5 switch')
eq(0x6737fa,'83f804','unavailable-role switch range 5..9')
eq(0x6737ff,'ff2485883d6700','unavailable-role jump table')
# Creation outcome is a different dispatch and local event: do not confuse F4278 with F4245.
eq(0x4c14be,'c70574a6d60044505845','Expedition scene marker EXPD')
eq(0x4c14e1,'c786fc600000d0214c00','EXPD S2C4A scene slot registration')
eq(0x4c14eb,'c786ec610000f0214c00','EXPD S2C68 separate registration')
eq(0x4c21d6,'0fbf4802','EXPD S2C4A signed status word')
eq(0x4c21db,'6845420f00','EXPD S2C4A posts F4245 not F4278')
eq(0x5a64e9,'813d74a6d60044505845','page unready checks EXPD scene tag')
eq(0x5a64f5,'a1a48bfd0085c07406','page conditional global owner pointer')
must('page calls 4c1e10 if conditional satisfied',direct_call(0x5a64ff,0x4c1e10))
eq(0x5a66b3,'e8f8fdffff','page not-ready controls call 5a64b0')
must('page not-ready calls 5a64b0',direct_call(0x5a66b3,0x5a64b0))
eq(0x5a68ba,'c7874401000001000000','F4245 status1 sets page+144')
eq(0x4b8082,'e877bf3d00','S2C app2 name copy helper established by E74')
eq(0x4d4154,'c7465c01000000','S2C app2 row writer sets +5c')
# Other code also exposes this event ID: no exclusivity claim.
eq(0x60b200,'b878420f00c3','second F4278 immediate is local getter')
print(f'RR-0010 E77: PASS {len(checks)} read-only original BIN assertions; verified_sha256={SHA}')
print('scope: original bytes, scene table B6/B7, local F4278 event, role UI availability branch, EXPD scene gate')
print('not_verified: original Server pairing; B6 relation to C2S 3E / S2C 4A / S2C2 roster timing; playable character creation')
