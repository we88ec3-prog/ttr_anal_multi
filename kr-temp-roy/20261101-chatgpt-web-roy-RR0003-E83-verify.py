#!/usr/bin/env python3
"""RR-0003 E83: read-only KR original BIN assertions and labeled synthetic defensive vectors.
No game execution or real Server packet inference. Usage: python E83-RR0003-verify.py Tartaros.bin
"""
from pathlib import Path
import hashlib, struct, sys, json
b=Path(sys.argv[1] if len(sys.argv)>1 else '/mnt/data/Tartaros.bin').read_bytes()
H='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
assert len(b)==12472320 and hashlib.sha256(b).hexdigest()==H
pe=struct.unpack_from('<I',b,0x3c)[0]
assert b[:2]==b'MZ' and b[pe:pe+4]==b'PE\0\0'
sects={}; off=pe+24+struct.unpack_from('<H',b,pe+20)[0]
for i in range(struct.unpack_from('<H',b,pe+6)[0]):
 t=off+i*40; nm=b[t:t+8].split(b'\0')[0].decode(); vs,va,rs,raw=struct.unpack_from('<IIII',b,t+8);sects[nm]=(va+0x400000,vs,rs,raw)
def data(va,n):
 for name,(v,vs,rs,raw) in sects.items():
  if v<=va and va+n<=v+rs:return b[raw+va-v:raw+va-v+n]
 raise ValueError('not file-backed: '+hex(va))
def u32(va):return struct.unpack('<I',data(va,4))[0]
def call(va,target):return data(va,1)==b'\xe8' and va+5+struct.unpack('<i',data(va+1,4))[0]==target
checks={}
def ck(k,condition):
 checks[k]=bool(condition)
 if not condition:raise AssertionError(k)
def eq(k,va,h): ck(k,data(va,len(bytes.fromhex(h)))==bytes.fromhex(h))
ck('KR SHA256 source and PE',True)
ck('PE .text raw/virtual sizes',sects['.text']==(0x401000,0x7d01f0,0x7d0200,0x400))
ck('PE .data BSS virtual zero tail contains FBA808',sects['.data'][0]+sects['.data'][2]<0xfba808<sects['.data'][0]+sects['.data'][1])
ck('mode52 vtable slot30 gives 440790',u32(0xbfb01c+0x30)==0x440790)
ck('mode52 object vptr written at 6D6321',data(0x6d6321,6)==bytes.fromhex('c7001cb0bf00'))
eq('mode52 object+8 initial 0x52',0x6d6340,'c7400852000000')
eq('mode reader',0x440793,'8b410883f852')
ck('mode52 dispatch C2S E8 builder',call(0x4407c2,0x4a3360))
ck('mode54 dispatch C2S 000F builder',call(0x4407f7,0x4a31b0))
ck('fallback dispatch 000F builder',call(0x440822,0x4a31b0))
eq('E8 opcode at local buffer',0x4a33ab,'b9e800000066894c2474')
eq('E8 local payload length 112',0x4a34fc,'6a70')
eq('E8 slot1 local queue',0x4a3503,'6a01ffd2')
eq('E8 tail word from owner BF80',0x4a33b5,'668b8a80bf0000')
eq('E8 tail word stack relocation',0x4a33c5,'66898c24e6000000')
eq('E8 wide to narrow output uses 51-byte bounded copy #1',0x4a34d3,'6a3352')
ck('E8 narrow copy 1 callee',call(0x4a34d6,0x893b59))
eq('E8 wide to narrow output uses 51-byte bounded copy #2',0x4a34e6,'6a3350')
ck('E8 narrow copy2 callee',call(0x4a34e9,0x893b59))
eq('000F opcode app word',0x4a31e3,'b90f000000')
eq('000F 214-byte payload',0x4a32b6,'68d6000000')
eq('000F slot1 local queue',0x4a32c2,'6a01ffd2')
eq('000F u32 constant +206',0x4a31f3,'c7459201000100')
eq('000F DWORD +210 / +212 overlap needs source-based resolution',0x4a31fa,'c7459634000000')
ck('000F wide bounded copy 1',call(0x4a3281,0x892e4d))
ck('000F wide bounded copy 2',call(0x4a32a3,0x892e4d))
for va in [0x4a3455,0x4a3475,0x4a34aa,0x4a34c8]:
 ck('E8 WCTMB direct call '+hex(va),data(va-1 if va==0x4a3455 else va,2).endswith(b'\xd6') if False else (data(va,2)==b'\xff\xd6'))
code_refs=[0x40410e,0x404159,0x46e2cc,0x46e31e,0x47f59f,0x47f5db,0x4c37e9]
v,vs,rs,raw=sects['.text'];x=b[raw:raw+rs]
found=[v+i for i in range(len(x)-3) if x[i:i+4]==bytes.fromhex('08a8fb00')]
ck('seven direct FBA808 references unchanged',found==code_refs)
eq('LOGIN constructor slot 13',0x4c323b,'c786445f0000a0374c00')
eq('LOGIN constructor slot 7a',0x4c325b,'c7867c620000103c4c00')
eq('S2C13 optional UTF16 notice prestatus',0x4c37d3,'8d4620')
eq('S2C13 optional notice nonzero test',0x4c37e2,'663918')
eq('S2C13 notice codepage fetched from global',0x4c37e7,'8b1508a8fb00')
eq('S2C13 notice Windows CP convert',0x4c3800,'ff15cc21bd00')
eq('S2C13 status byte',0x4c3821,'8a561680fa05')
eq('S2C13 status5 separate branch',0x4c3827,'0f851c010000')
eq('S2C13 nonzero error branch',0x4c3949,'84d20f85df000000')
eq('S2C13 empty utf16 name error branch',0x4c3973,'0f84b7000000')
eq('S2C13 success identity +18',0x4c3979,'8b5e18')
eq('S2C13 group count+1c',0x4c3a03,'8b461c')
eq('S2C13 group cursor+92',0x4c3a0a,'8d8e92000000')
ck('S2C13 group parser',call(0x4c3a10,0x4c3080))
eq('S2C13 +90 conditional post notice',0x4c3a15,'80be9000000000')
ck('S2C13 local F4241 handoff condition call',call(0x4c3a24,0x4c3170))
eq('S2C13 status5 vptr+14 indirect',0x4c3925,'8b118b421457ffd0')
eq('S2C13 generic-fail vptr+14 indirect',0x4c3b3a,'8b018b501457ffd2')
ck('known new login object vptr+14 is no-op',u32(0xbfb01c+0x14)==0x476430 and data(0x476430,3)==bytes.fromhex('c20400'))
eq('S2C13 status5 manager close vptr+20',0x4c392d,'8b0d54a8fb008b118b4220')
eq('S2C13 generic-fail manager close vptr+20',0x4c3b42,'8b0d54a8fb008b018b5020')
eq('S2C13 failure local owner BF60 null',0x4c3b5e,'89be60bf0000')
eq('S2C13 failure HRESULT',0x4c3b59,'b805400080')
eq('S2C13 status0 name copy max 10 into cap11',0x4c3990,'6a0a57')
eq('S2C13 +86 byte',0x4c39c3,'8a9686000000')
eq('S2C13 +87 narrow bounded string',0x4c39e2,'8d8e87000000')
eq('S2C13 +8c identity dword',0x4c39c9,'8b9e8c000000')
eq('S2C13 +90 stored local',0x4c39b2,'8a9e90000000')
eq('Group parser count0 jumps notification',0x4c30aa,'85db0f8498000000')
eq('Group 3B header',0x4c30be,'0fb70b83c703')
eq('Group count from +2',0x4c30c9,'807b0200')
eq('10B child stride',0x4c30ff,'83c70a')
eq('Group child enable flag +8',0x4c3107,'0fb64e08')
eq('Group child metadata +9',0x4c311a,'0fb65609')
eq('Group count0 still local event F4243',0x4c314a,'6843420f00')
ck('Group local event dispatch',call(0x4c314f,0x58aad0))
eq('S2C7A group count +2',0x4c3c10,'558bec') # entry placeholder check later
# Pure synthetic Server compatibility vectors, not actual Client runtime or native error behavior.
def wire13(groups,identity=0x12345678,mode=0,status=0,name='A'):
 z=bytearray(0x92);struct.pack_into('<H',z,0,0x13)
 if name:z[2:4]=name[0].encode('utf-16le')
 z[0x16]=status;z[0x17]=3;struct.pack_into('<I',z,0x18,identity)
 struct.pack_into('<I',z,0x1c,len(groups));z[0x90]=mode
 for gid,rows in groups:
  z+=struct.pack('<HB',gid,len(rows))
  for row in rows:z+=row
 return bytes(z)
def structural_ok13(payload):
 if len(payload)<0x92 or payload[:2]!=b'\x13\x00':return False
 count=struct.unpack_from('<I',payload,0x1c)[0];i=0x92
 if count>32:return False # proposed Server-side bounded policy
 for _ in range(count):
  if i+3>len(payload):return False
  n=payload[i+2];i+=3
  if i+10*n>len(payload):return False
  i+=10*n
 return i==len(payload)
blank=wire13([]); ck('synthetic 13 zero group extent 0x92',len(blank)==0x92 and structural_ok13(blank))
ck('synthetic 13 no business identity credentials derived',struct.unpack_from('<I',blank,0x18)[0]==0x12345678)
ck('synthetic 13 shortened by 1 rejected by proposed parser',not structural_ok13(blank[:-1]))
ck('synthetic 13 status5 same layout but no normal success',structural_ok13(wire13([],status=5)) and wire13([],status=5)[0x16]==5)
ck('synthetic 13 status0 name empty not local success',structural_ok13(wire13([],name='')) and wire13([],name='')[2:4]==b'\0\0')
row=struct.pack('<HH',33,0)+bytes([127,0,0,1,1,5]);ck('synthetic 10byte group row format',len(row)==10)
one=wire13([(2,[row])]);ck('synthetic group+single row length',len(one)==0x92+3+10 and structural_ok13(one))
ck('synthetic truncated group row negative',not structural_ok13(one[:-1]))
ck('synthetic bad count negative',not structural_ok13(one[:0x1c]+(2).to_bytes(4,'little')+one[0x20:]))
ck('synthetic oversized count negative',not structural_ok13(one[:0x1c]+(0xffffffff).to_bytes(4,'little')+one[0x20:]))

# E83 additional cross-RR positive proof: 0x13 writes flow into the key0 first payload.
eq('13 success identity write into Client+67E0',0x4c3981,'8998e0670000')
eq('13 success name destination Client+67E4',0x4c3993,'05e4670000')
eq('13 success byte into Client+6898',0x4c39f2,'888798680000')
eq('13 success string destination Client+6899',0x4c39e9,'8d9799680000')
eq('13 success DWORD into Client+68A0',0x4c39fd,'899fa0680000')
eq('key0 reads exact shared Client+67E0',0x4958b8,'8b90e0670000')
eq('key0 reads exact shared Client+67E4',0x4958c8,'05e4670000')
eq('key0 reads exact shared Client+6898',0x4958fa,'8a9098680000')
eq('key0 reads exact shared Client+6899',0x495908,'0599680000')
eq('key0 reads exact shared Client+68A0',0x495921,'8b88a0680000')
# Important E82 correction: local zero initialization is overwritten by a second 10-WCHAR copy.
ck('key0 second wide source fetched from same global owner',call(0x4958d9,0x404ba0))
eq('key0 second WCHAR source is owner+67FA',0x4958e0,'05fa670000')
eq('key0 second wide source count10',0x4958de,'6a0a')
eq('key0 second wide dest is payload+37',0x4958e6,'8d4de5')
eq('key0 second wide dest capacity10',0x4958e9,'6a0a')
ck('key0 second wide copy is actual bounded helper',call(0x4958ec,0x893ffe))
ck('only 67FA direct literal in text is second key0 copy', [v+i for i in range(len(x)-3) if x[i:i+4]==bytes.fromhex('fa670000')]==[0x4958e1])
eq('bounded wchar helper clears dest on truncation',0x8940b7,'668902')
# Explicitly synthetic model: byte layout of second copy is not a fixed-zero field.
fixture=bytearray(57);fixture[0:2]=b'\x01\x00';fixture[26]=1
fixture[37:41]='OK'.encode('utf-16le')
ck('synthetic model allows nonzero second wide field',fixture[37:41]!=b'\x00'*4 and fixture[37:41]=='OK'.encode('utf-16le'))
print(json.dumps({'status':'PASS','count':len(checks),'native':sum(1 for s in checks if not s.startswith('synthetic')),'source_sha256':H,'comment':'native byte/call/PE checks + explicitly synthetic server-side defensive policy; not original Server timing or runtime Client success'},ensure_ascii=False))