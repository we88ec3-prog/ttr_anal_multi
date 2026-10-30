#!/usr/bin/env python3
"""E80 KR RR-0002 read-only original BIN bounded assertions & synthetic input tests.
No original client/server execution and no official Server reply pairing assertion.
"""
import hashlib, struct, sys
from pathlib import Path

EXPECTED_SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
path=Path(sys.argv[1]) if len(sys.argv)>1 else Path('Tartaros.bin')
b=path.read_bytes()
checks=[]
def must(desc,cond):
    if not cond:raise AssertionError(desc)
    checks.append(desc)
must('KR BIN exact SHA256',hashlib.sha256(b).hexdigest()==EXPECTED_SHA)
pe=struct.unpack_from('<I',b,0x3c)[0]
must('PE signature',b[pe:pe+4]==b'PE\0\0')
must('PE machine x86',struct.unpack_from('<H',b,pe+4)[0]==0x14c)
must('PE imagebase',struct.unpack_from('<I',b,pe+0x34)[0]==0x400000)
sections={}
sec=pe+24+struct.unpack_from('<H',b,pe+20)[0]
for i in range(struct.unpack_from('<H',b,pe+6)[0]):
    at=sec+i*40
    n=b[at:at+8].split(b'\0')[0].decode()
    vsize,rva,rawsize,rawptr=struct.unpack_from('<IIII',b,at+8)
    sections[n]=(0x400000+rva,rawptr,rawsize)
must('.text section header',sections['.text']==(0x401000,0x400,0x7d0200))
must('.rdata section header',sections['.rdata']==(0xbd2000,0x7d0600,0x18e200))
must('.data section header',sections['.data']==(0xd61000,0x95e800,0x22b800))
def raw(va,n=1):
    for base,off,sz in sections.values():
        if base<=va and va+n<=base+sz:
            return off+va-base
    raise ValueError(f'VA {va:#x} outside file-backed sections')
def u32(va):return struct.unpack_from('<I',b,raw(va,4))[0]
def expect(va,hexs,desc):
    bs=bytes.fromhex(hexs)
    must(desc,b[raw(va,len(bs)):raw(va,len(bs))+len(bs)]==bs)
def call(va,dst,desc):
    at=raw(va,5)
    op=b[at];delta=struct.unpack_from('<i',b,at+1)[0]
    must(desc,op==0xe8 and ((va+5+delta)&0xffffffff)==dst)
def rtti(vbase,fn,slot,descriptor,name):
    must('vtable slot matches '+name,u32(vbase+slot*4)==fn)
    col=u32(vbase-4)
    must('RTTI TypeDescriptor matches '+name,u32(col+12)==descriptor)
    needle=name.encode('ascii')+b'\0'
    must('RTTI name bytes match '+name,b[raw(descriptor+8,len(needle)):raw(descriptor+8,len(needle))+len(needle)]==needle)

# C2S role select instruction, queue and event branching
expect(0x4a3b84,'833d98a7fb0000','C2S42 send-gate checks FBA798')
expect(0x4a3b8b,'8a4d08','C2S42 first byte source arg+8')
expect(0x4a3b8e,'8a550c','C2S42 second byte source arg+C')
expect(0x4a3b91,'b842000000668945fc','C2S42 opcode u16 at local -4')
expect(0x4a3b9a,'884dfe','C2S42 selected role byte destination -2')
expect(0x4a3b9d,'8855ff','C2S42 mode byte destination -1')
expect(0x4a3bad,'6a048d55fc526a00ffd0','C2S42 queue 4-byte slot0 virtual send')
expect(0x4a3bba,'c20800','C2S42 two arguments ret8')
rtti(0xc280f4,0x5f46d0,87,0xf8462c,'.?AVCExpeditionScene@FUI@@')
rtti(0xc3594c,0x673da0,87,0xf865c4,'.?AVCExpeditionDialog@FUI@@')
expect(0x5f46d9,'8b481081e978050000','Scene event 0x578 discriminator')
expect(0x5f46e8,'81e992010000','Scene event adjusted 0x70A discriminator')
expect(0x5f47a4,'8b4020','Scene selected widget index from child+20')
expect(0x5f47ac,'40','Scene widget index ++')
expect(0x5f47c4,'83f809','Scene selected role max9')
expect(0x5f47cd,'69c010020000','Scene 0x210 record stride')
expect(0x5f47d5,'83785c00','Scene record available flag +0x5C')
expect(0x5f47f2,'6a0050','Scene role-click pushes mode 0 then role index')
call(0x5f47f5,0x4a3b80,'Scene role click C2S42 actual call')
expect(0x5f486a,'80becc000000','Scene secondary action gated by pending flag')
expect(0x5f48e0,'80becc000000','Scene alternate action same pending flag')
expect(0x5f487c,'6a00','Scene mode 0 button')
expect(0x5f48ee,'6a02','Scene mode 2 button')
call(0x5f48f7,0x4a3b80,'Scene pending-action C2S42 actual call')
expect(0x5f48fc,'c686cc00000001','Scene local pending byte set even if manager refuses queue')
expect(0x673dc9,'8b481081f978050000','Dialog event 0x578')
expect(0x673e9c,'e8df07daff','Dialog pre-queue helper')
expect(0x673ea7,'6a0052','Dialog mode0 and index saved at +D8')
call(0x673eaa,0x4a3b80,'Dialog C2S42 actual call')

# Initial roster write and per-row selection/secondary queries
expect(0x4b803f,'8b5702','Roster header DWORD at +2')
expect(0x4b8075,'6a148d470c506a15','Roster header name at +0C, 20 source WCHAR,21 dest')
expect(0x4b80c5,'0fb74f38','Roster header WORD +38')
expect(0x4b8103,'0fb75736','Roster header WORD +36')
expect(0x4b813a,'66837f3a00','Roster header WORD +3A as bool')
expect(0x4b817d,'384f3c','Roster header BYTE +3C')
expect(0x4b81c0,'8b573d','Roster header DWORD +3D')
expect(0x4b8923,'8b4d0c83f941','Roster length 65 comparator')
expect(0x4b894c,'0f84ce000000','Roster zero row count skips row loop')
expect(0x4b8956,'83c76f','Roster row slot pointer +0x6F = start+0x41+0x2E')
expect(0x4b8992,'0fb607','Roster row index byte')
expect(0x4b8995,'83f809','Roster row index only bound <=9')
expect(0x4b899a,'69c010020000','Roster role record stride 0x210')
call(0x4b89ad,0x4d4150,'Roster row record writer')
expect(0x4b89dc,'ba26000000','Roster per-row C2S 0x26')
expect(0x4b89f7,'6a038d54241c526a00ffd0','Roster per-row queue 3 bytes slot0')
expect(0x4b8a02,'0fb60f49ba0100000066d3e2','Roster mask (index-1) variable 16-bit shift')
expect(0x4b8a0e,'83c735','Roster records 53-byte stride')
expect(0x4b8a60,'66a34042f900','Roster stores local index mask')
expect(0x4b8a97,'b9e0d9f800','Roster passes global client record owner')
call(0x4b8a9c,0x4e5fb0,'Roster common postprocess')
expect(0x4b8ac4,'b924000000','Roster list-end C2S24')
expect(0x4b8adb,'6a028d442432506a00ffd2','Roster list-end 2-byte queue slot0')

# S2C scene change and a distinct post-entry C2S handshake
expect(0x4b90c1,'0fbe4802','S2C69 reads signed subtype byte +2')
expect(0x4b90c5,'8d41f9','S2C69 subtract subtype7')
expect(0x4b90df,'6854bd0000','S2C69 subtype7 case')
call(0x4b90f0,0x4bbb70,'S2C69 subtype7 allocates Square')
call(0x4b90fd,0x4b7d50,'S2C69 subtype7 scene manager')
expect(0x4b9107,'c780a869000007000000','S2C69 local scene state +69A8=7')
expect(0x4b91f1,'0fbe4102','S2C69 subtype set local f9392c')
expect(0x4b9202,'0fb65103','S2C69 channel-state field reads +3')
expect(0x4b920e,'0fb64904','S2C69 channel-state field reads +4')
expect(0x4bbbdb,'c786ec61000050c04b00','CSquare scene app68 handler table')
expect(0x4bbbeb,'c786fc610000a0bf4b00','CSquare scene app6A handler table')
expect(0x4bbe60,'8b15a01afe00','CSquare reads distinct user-data owner FE1AA0')
expect(0x4bbe66,'8b5a18','CSquare current index at user-data +18')
expect(0x4bbe86,'b843000000','CSquare C2S43 command')
expect(0x4bbe94,'c64424170a','CSquare C2S43 suffix mode 0xA')
expect(0x4bbea6,'6a048d442418506a00ffd2','CSquare C2S43 4-byte slot0 enqueue')
expect(0x506bbe,'a3a01afe00','CSquareUserData singleton assignment')
expect(0x506bc3,'895818','CSquareUserData initial current index zero')
expect(0x506bc6,'c7401c01000000','CSquareUserData initial count one')
expect(0x506c0f,'a3881afe00','Distinct CSquareChannelState singleton assignment')
expect(0x508977,'83fbff','CSquare index setter -1 sentinel')
expect(0x508981,'3b581c','CSquare index setter checks count upper')
expect(0x5089b0,'b843000000','CSquare setter C2S43')
expect(0x5089bc,'c6450b0a','CSquare setter mode 0x0A')
expect(0x4b1a90,'6a06','S2C43 base handler is type-6 effect')
call(0x4b1a92,0x40f060,'S2C43 gets type-6 owner')
call(0x4b1a99,0x4dfd40,'S2C43 performs effect cleanup')

# Synthetic compatibility smoke tests deliberately NOT native traffic captures.
def enc_select(role,variant):
    if not isinstance(role,int) or not 1<=role<=9 or variant not in (0,2):
        raise ValueError('conservative proposed Server selection input policy')
    return struct.pack('<HBB',0x42,role,variant)
def parse_select(p):
    if len(p)!=4 or p[:2]!=b'\x42\0':raise ValueError('invalid selection body')
    role,variant=p[2],p[3]
    if role not in range(1,10) or variant not in (0,2):raise ValueError('server-defined strict allowlist')
    return role,variant
for role in range(1,10):
    for var in (0,2):
        must(f'synthetic select roundtrip role{role} mode{var}',parse_select(enc_select(role,var))==(role,var))
for data in (b'',b'\x42\0\x01',b'\x42\0\x01\0\0',b'\x41\0\x01\0',b'\x42\0\0\0',b'\x42\0\x01\x03',b'\x42\0\xff\0'):
    try:parse_select(data);ok=False
    except ValueError:ok=True
    must(f'synthetic malformed select rejected {data.hex()}',ok)
# The synthetic safe policy must be identified as a new Server policy, not a KR Client native guard.
must('synthetic 65+53*N geometry', all((65+53*n-65)//53==n for n in range(10)))
must('synthetic 53B row highest DWORD stays within row', 0x31+4==53)
print(f'E80 RR-0002 PASS: {len(checks)} assertions (original BIN + explicit synthetic policy checks)')
print('ORIGINAL-SERVER SELECTION ACK/ERROR ORDER: UNVERIFIED; S00 REVIEW REQUIRED')
