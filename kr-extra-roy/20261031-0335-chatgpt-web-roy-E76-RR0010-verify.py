#!/usr/bin/env python3
"""E76: KR BIN first-hand Client Expedition page dual name-ready paths and negative gates.

Run: python -B 20261031-0335-chatgpt-web-roy-E76-RR0010-verify.py /path/to/Tartaros.bin
Static-only. Does not prove original Server pairing or order.
"""
import hashlib
import struct
import sys
from pathlib import Path

p = Path(sys.argv[1]) if len(sys.argv)>1 else Path('Tartaros.bin')
b = p.read_bytes()
sha='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
assert hashlib.sha256(b).hexdigest()==sha, 'KR BIN SHA mismatch'
pe = struct.unpack_from('<I',b,0x3c)[0]
base = struct.unpack_from('<I',b,pe+52)[0]
section_count = struct.unpack_from('<H',b,pe+6)[0]
section_header = pe+24+struct.unpack_from('<H',b,pe+20)[0]
sections = {}
for i in range(section_count):
    q=section_header+40*i
    name=b[q:q+8].rstrip(b'\0').decode('ascii')
    virtual_size, rva, rawsize, rawoff = struct.unpack_from('<IIII',b,q+8)
    sections[name]=(base+rva,rawsize,rawoff)
assert base==0x400000
assert sections['.text']==(0x401000,0x7D0200,0x400)

def read(va,n):
    for low,sz,raw in sections.values():
        if low<=va and va+n<=low+sz: return b[raw+(va-low):raw+(va-low)+n]
    raise AssertionError(f'unmapped VA {va:#x} {n}')
def u32(va): return struct.unpack('<I',read(va,4))[0]
checks=[]
def chk(va,data,meaning):
    want=bytes.fromhex(data)
    got=read(va,len(want))
    assert got==want,(meaning,hex(va),want.hex(),got.hex())
    checks.append(meaning)
def call(va,target,meaning):
    ins=read(va,5)
    assert ins[0]==0xe8 and va+5+struct.unpack('<i',ins[1:])[0]==target,(hex(va),hex(target),ins.hex())
    checks.append(meaning)
def equal(actual,expected,meaning):
    assert actual==expected,(meaning,actual,expected)
    checks.append(meaning)

# Class identity, members and true virtual ownership. RTTI TypeDescriptor string.
col=u32(0xc1c1a0)
td=u32(col+12)
name=read(td+8,64).split(b'\0',1)[0]
equal(name,b'.?AVCExpeditionPage@FUI@@','RTTI Expedition page (not EmployNewCharacter)')
equal(u32(0xc1c1a4+92*4),0x5a6510,'page vtable+0x170 = name flag initialization')
equal(u32(0xc1c1a4+66*4),0x5a65a0,'page vtable+0x108 = control init')
equal(u32(0xc1c1a4+101*4),0x5a67d0,'page vtable+0x194 = local event receiver')
chk(0x5a6486,'c7 06 a4 c1 c1 00','page destructor installs vptr C1C1A4')
chk(0x5a6566,'b8 f2 38 f9 00','page name flag reads global F938F2')
chk(0x5a6570,'66 8b 08','name scan reads UTF16 word')
chk(0x5a6576,'66 85 c9','name scan checks WORD NUL')
chk(0x5a657b,'2b c2','name count after NUL scan')
chk(0x5a657d,'d1 f8','name length measured in WORDs')
chk(0x5a657f,'74 0a','zero-length does not set ready flag')
chk(0x5a6581,'c7 86 44 01 00 00 01 00 00 00','nonzero name sets page+0x144=1')
chk(0x5a665f,'83 bb 44 01 00 00 00','control initialization reads same ready flag')
chk(0x5a6666,'75 52','nonzero ready branch to enabled controls')
for va,hexd,note in [
    (0x5a668b,'6a 00','name absent: UI B0 off'),
    (0x5a669d,'6a 00','name absent: UI B4 off'),
    (0x5a66af,'6a 00','name absent: UI B8 off'),
    (0x5a66ce,'6a 01','name exists: UI B0 on'),
    (0x5a66e0,'6a 01','name exists: UI B4 on'),
    (0x5a66f2,'6a 01','name exists: UI B8 on'),
    (0x5a68ba,'c7 87 44 01 00 00 01 00 00 00','result success writes identical page flag'),
    (0x5a689a,'83 7b 14 01','only positive result1 enters ready-change path'),
    (0x5a67fb,'81 7e 10 a3 42 0f 00','page event dispatch exact local code F42A3 check'),
    (0x5a680e,'05 bb bd f0 ff','page event dispatch switch base F4245'),
    (0x5a6813,'83 f8 33','page event jump table max event delta 0x33'),
    (0x5a681c,'0f b6 80 a0 69 5a 00','page event switch maps code through lookup table'),
    (0x5a6823,'ff 24 85 88 69 5a 00','page event switch jumps through table'),
    (0x4b8075,'6a 14','roster name source max20 UTF16 words'),
    (0x4b8077,'8d 47 0c','roster reads payload+0xC'),
    (0x4b807d,'68 f2 38 f9 00','roster targets shared page name'),
    (0x67261c,'68 f2 38 f9 00','name result success targets same page name'),
    (0x6725aa,'3b c1','name result checks status1'),
    (0x67264d,'3b c7','name result negative status -1'),
    (0x6727af,'83 f8 fe','name result negative status -2'),
    (0x672817,'83 f8 fd','name result negative status -3'),
    (0x672790,'33 c0','failed status input recovery initializes zero'),
    (0x672792,'89 87 68 01 00 00','failed status recovery edit+168=0'),
    (0x672798,'89 87 60 01 00 00','failed status recovery edit+160=0'),
    (0x67279e,'89 87 64 01 00 00','failed status recovery edit+164=0'),
    (0x6727a4,'89 87 4c 01 00 00','failed status recovery edit+14C=0'),
    (0x6728d6,'8b 13','failed status common dialog virtual call'),
    (0x6728d8,'8b 82 90 00 00 00','failed status common virtual+90'),
    (0x6728de,'6a 01','failed status common virtual arg1'),
    (0x4de0dd,'68 61 42 0f 00','S2C0x26 local event F4261 emitted'),
    (0x5de800,'b8 61 42 0f 00','unrelated UI class returns F4261'),
]:chk(va,hexd,note)
for at,to,n in [
    (0x4b8082,0x893ffe,'app2 shared name copy helper'),
    (0x672621,0x893ffe,'name result shared name copy helper'),
    (0x5a6895,0x672570,'page result arrives at create dialog'),
    (0x5a68aa,0x5f4910,'success enables explicit UI controls'),
    (0x5a68b5,0x5f4950,'success refreshes displayed global name'),
    (0x5a66b3,0x5a64b0,'not-ready branch invokes distinct cleanup helper'),
    (0x5a696e,0x5a64b0,'other page local event invokes same cleanup helper'),
]:call(at,to,n)
# F4261 is in page event-range but maps to its default/no-op switch path,
# unlike F4245 (index0) on the Expedition page. This is limited to this
# vtable receiver, not an exhaustive search of other event subscribers.
event_map=read(0x5a69a0,0x34)
page_event_4a=0xf4245
idx_26=0xf4261-page_event_4a
assert len(event_map)==0x34
assert idx_26==0x1c
assert event_map[0]==0
assert event_map[idx_26]==5
assert event_map[0x33]==4
checks.append('F4261 page event lookup index0x1C resolves default slot5')
for i,(ix,expect) in enumerate([(0,0x5a6886),(4,0x5a68d8),(5,0x5a6973)]):
    equal(u32(0x5a6988+4*ix),expect,f'page event jump index{ix} target exact')
# RTTI check for F4261 getter: 0xC252B4 vtable belongs to the *different*
# CItemSlotShopDismantle1, not the Expedition page.
col2=u32(0xc252b0)
td2=u32(col2+12)
equal(read(td2+8,64).split(b'\0',1)[0],b'.?AVCItemSlotShopDismantle1@FUI@@','other F4261 getter RTTI = shop dismantle1')
equal(u32(0xc252b4+2*4),0x5de800,'other class vtable slot2 F4261 getter')
print('PASS',len(checks),'KR SHA',sha)
print('Native static only. No Server request/reply capture, no Client runtime, no T01 FULL-PASS, no confirmed create-result to app2 network sequence.')
