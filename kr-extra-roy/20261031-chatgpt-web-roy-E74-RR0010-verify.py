#!/usr/bin/env python3
"""E74 RR-0010 original-KR-BIN evidence checks (static-only, not original-Server trace).

python -B 20261031-chatgpt-web-roy-E74-RR0010-verify.py /path/to/Tartaros.bin
"""
from pathlib import Path
import hashlib,struct,sys
p=Path(sys.argv[1]) if len(sys.argv)>1 else Path('Tartaros.bin')
b=p.read_bytes()
expected='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
assert hashlib.sha256(b).hexdigest()==expected,'wrong original KR BIN'
pe=struct.unpack_from('<I',b,0x3c)[0];base=struct.unpack_from('<I',b,pe+52)[0]
sections=[]
for i in range(struct.unpack_from('<H',b,pe+6)[0]):
    q=pe+24+struct.unpack_from('<H',b,pe+20)[0]+i*40
    vs,va,sz,raw=struct.unpack_from('<IIII',b,q+8)
    sections.append((b[q:q+8].rstrip(b'\x00').decode(),base+va,raw,sz))
assert ('.text',0x401000,0x400,0x7d0200) in sections

def at(va,size):
    for name,lo,raw,sz in sections:
        if lo<=va and va+size<=lo+sz:
            return b[raw+va-lo:raw+va-lo+size]
    raise AssertionError(f'unmapped {va:#x} ({size})')
checks=[]
def chk(va,hexd,note):
    want=bytes.fromhex(hexd);got=at(va,len(want))
    assert got==want, f'{note}@{va:x}: got {got.hex()} expected {want.hex()}'
    checks.append((va,note))
def call(va,dst,note):
    bb=at(va,5)
    assert bb[0]==0xe8 and va+5+struct.unpack('<i',bb[1:])[0]==dst,(hex(va),hex(dst),bb.hex())
    checks.append((va,note))
# Native sender and name buffer layout
for va,s,n in [
    (0x672180,'55 8b ec 83 e4 f8','create-dialog name checker entry'),
    (0x672194,'83 ec 48','local stack reserve'),
    (0x6721a2,'53 56 57','saved registers before local stack base'),
    (0x6721ac,'50','cookie push defining ESP at stack base'),
    (0x6724b1,'8b 7c 24 18','successful name-validation branch'),
    (0x6724e8,'f6 05 14 13 fb 00 01','unrelated static initialization gate'),
    (0x672505,'56','push source wchar_t pointer'),
    (0x672506,'8d 54 24 2a','name dest at S+0x26'),
    (0x67250a,'b9 3e 00 00 00','app0x003e'),
    (0x67250f,'6a 15','21 wchar copy cap'),
    (0x672512,'66 89 4c 24 2c','opcode at S+0x20'),
    (0x67251f,'83 3d 98 a7 fb 00 00','network manager gate'),
    (0x672533,'6a 30','48 byte app payload'),
    (0x672535,'8d 54 24 24','payload pointer S+0x20'),
    (0x67253a,'6a 00','slot0'),
    (0x67253c,'ff d0','indirect queue/send'),
    (0x67253e,'8b 17','local post-request UI virtual'),
    (0x892e77,'8b 45 10','copy: source pointer'),
    (0x892e87,'0f b7 08','copy: wchar read'),
    (0x892e8a,'66 89 0c 02','copy: wchar write'),
    (0x892e96,'4f','copy: capacity decrement'),
    (0x892e9f,'66 89 06','copy: truncation clears first wchar'),
    (0x892ea7,'6a 22','copy error 34 on capacity exhaustion'),
]: chk(va,s,n)
call(0x672517,0x892e4d,'caller invokes bounded wchar copy')
# Response relay: no automatic app+1 assumption
for va,s,n in [
    (0x4c14e1,'c7 86 fc 60 00 00 d0 21 4c 00','LOGIN scene index 0x4a registration'),
    (0x4c21d6,'0f bf 48 02','S2C app0x4a signed16 at payload+2'),
    (0x4c21db,'68 45 42 0f 00','translate to local event F4245'),
    (0x58aba4,'6a 18','local 24-byte event allocation'),
    (0x58abb4,'8b 55 08','local event code argument'),
    (0x58abb7,'89 50 10','event+0x10=code'),
    (0x58abba,'8b 55 0c','local result argument'),
    (0x58abd4,'89 50 14','event+0x14=signed result'),
    (0x58ac0c,'8d 45 f0','event queued to local dispatch'),
    (0x5a680e,'05 bb bd f0 ff','switch minus F4245'),
    (0x5a689a,'83 7b 14 01','only result1 triggers follow-up UI ready'),
    (0x6725a2,'8b 40 14','dialog result consumes event+0x14'),
    (0x6725aa,'3b c1','branch on result=1'),
    (0x672617,'6a 14 56 6a 15 68 f2 38 f9 00','success copies local name to global F938F2'),
    (0x67264d,'3b c7','-1 branch'),
    (0x6727af,'83 f8 fe','-2 branch'),
    (0x672817,'83 f8 fd','-3 branch'),
    (0x5f49b8,'ba f2 38 f9 00','UI renders global F938F2'),
]: chk(va,s,n)
call(0x4c21e0,0x58ab80,'S2C creates local event object')
call(0x58ac18,0x804260,'local event queue publisher')
call(0x5a6895,0x672570,'F4245 dispatches to expedition name result consumer')
call(0x5a68aa,0x5f4910,'successful UI controls update')
call(0x5a68b5,0x5f4950,'successful UI name update')
# Same S2C app2 consumes fixed header + expedition name + 53N record rows
for va,s,n in [
    (0x4b7f37,'8b 7d 08','app2 buffer pointer'),
    (0x4b803f,'8b 57 02','app2 reads u32 payload+2 into global'),
    (0x4b8042,'89 15 30 39 f9 00','app2 records header field'),
    (0x4b8075,'6a 14','app2 name source count20 wchar'),
    (0x4b8077,'8d 47 0c','app2 name at payload+12'),
    (0x4b807b,'6a 15','destination 21 wchar'),
    (0x4b807d,'68 f2 38 f9 00','same F938F2 name target as 0x4a success'),
    (0x4b8923,'8b 4d 0c','app2 handler payload length'),
    (0x4b8926,'83 f9 41','record count guard 65 bytes after name copy'),
    (0x4b8952,'8b 7c 24 28','record source from saved app buffer'),
    (0x4b8956,'83 c7 6f','record+0x2e slot source at app+0x6f'),
    (0x4b8992,'0f b6 07','read row slot'),
    (0x4b8995,'83 f8 09','slot bound <=9 for row copy'),
    (0x4b899a,'69 c0 10 02 00 00','slot*0x210'),
    (0x4b89a0,'03 05 04 43 f9 00','global roster base'),
    (0x4b89a8,'8d 57 d2','row source at app+0x41'),
    (0x4b89d2,'83 3d 98 a7 fb 00 00','per-row outbound manager gate'),
    (0x4b89dc,'ba 26 00 00 00','per-row request 0x0026'),
    (0x4b89e1,'66 89 54 24 18','per-row request opcode'),
    (0x4b89e6,'88 44 24 1a','per-row request slot byte'),
    (0x4b89f7,'6a 03','per-row request 3 bytes'),
    (0x4b89fe,'6a 00','per-row outbound slot0'),
    (0x4b8a0e,'83 c7 35','advance 53byte row'),
    (0x4b8a54,'f6 05 90 43 f9 00 01','post-roster static gate'),
    (0x4b8a60,'66 a3 40 42 f9 00','roster mask local global'),
    (0x4b8a97,'b9 e0 d9 f8 00','post-roster owner'),
    (0x4b8abd,'83 3d 98 a7 fb 00 00','post-roster outbound gate'),
    (0x4b8ac4,'b9 24 00 00 00','post-roster request 0x0024'),
    (0x4b8ac9,'66 89 4c 24 2e','post-roster request opcode'),
    (0x4b8adb,'6a 02','post-roster request 2byte inner payload'),
    (0x4b8ae2,'6a 00','post-roster outbound slot0'),
]:chk(va,s,n)
call(0x4b8082,0x893ffe,'app2 name header copied to same global as create success')
call(0x4b89ad,0x4d4150,'app2 copies 53-byte role record')
call(0x4b8a9c,0x4e5fb0,'app2 roster post-processing')
print(f'PASS {len(checks)} source-byte and direct-call assertions | {p} | SHA256 {expected}')
for a,n in checks:print(f'{a:#010x} {n}')
print('LIMITS: no actual original-Server request/reply/roster causal trace; app2 and 0x4a independently write common name, not proof of temporal order; no Client runtime')
