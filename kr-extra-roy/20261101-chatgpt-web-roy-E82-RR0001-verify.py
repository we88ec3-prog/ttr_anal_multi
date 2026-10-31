#!/usr/bin/env python3
"""E82 KR RR-0001 first local key0 payload/causality native byte audit.
Read-only original BIN; synthetic vectors are not original Server observations.
Usage: python -B E82-RR0001-verify.py /path/Tartaros.bin
"""
from pathlib import Path
import hashlib,struct,sys,json
p=Path(sys.argv[1] if len(sys.argv)>1 else 'Tartaros.bin')
b=p.read_bytes()
H='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
assert hashlib.sha256(b).hexdigest()==H and len(b)==12472320
pe=struct.unpack_from('<I',b,0x3c)[0]
assert b[:2]==b'MZ' and b[pe:pe+4]==b'PE\x00\x00'
base=0x400000;s=pe+24+struct.unpack_from('<H',b,pe+20)[0]
sec={}
for i in range(struct.unpack_from('<H',b,pe+6)[0]):
 o=s+i*40;n=b[o:o+8].split(b'\x00')[0].decode();vs,va,sz,raw=struct.unpack_from('<IIII',b,o+8);sec[n]=(base+va,sz,raw)
def rd(va,n):
 for q,(st,sz,raw) in sec.items():
  if st<=va and va+n<=st+sz:return b[raw+va-st:raw+va-st+n]
 raise ValueError(f'outside PE raw {va:#x} len {n}')
check=[]
def ck(name,expr):
 check.append((name,bool(expr)))
 if not expr:raise AssertionError(f'{name} failed')
def eq(addr,h,name):ck(name,rd(addr,len(bytes.fromhex(h)))==bytes.fromhex(h))
def call(addr,target):return rd(addr,1)==b'\xe8' and addr+5+struct.unpack('<i',rd(addr+1,4))[0]==target
ck('PE text section mapping',sec['.text'][:2]==(0x401000,0x7d0200))
eq(0x4957e0,'6a026a0068e020000053','key0 connect args lane2,key0,8416 and destination')
eq(0x4957f2,'6a026a02','key2 connect args lane2,key2')
eq(0x4957fd,'68de20000053','key2 port8414 and same destination')
eq(0x495807,'85ff','test key0 ptr')
eq(0x49580f,'85db','test key2 ptr')
eq(0x495817,'83be60bf000000','existing key1 descriptor gate')
ck('key1 prior local 7E emitter through queue',call(0x495853,0x8060d0))
eq(0x495848,'66894dbe','existing key1 opcode 0x7e')
eq(0x495843,'6a02','old key1 payload len2')
eq(0x49585e,'c780b0a0000001000000','old key1 closing marker')
eq(0x495868,'c78660bf000000000000','remove key1 owner ptr')
eq(0x495872,'6890010000','Sleep(400) arg')
eq(0x495877,'ff150423bd00','Sleep import invocation')
eq(0x49587f,'b901000000','cmd0x0001 setup')
eq(0x495884,'66894dc0','cmd opcode payload+0')
eq(0x495888,'8945c6','payload +6..+9 initialized 0')
eq(0x49588b,'8945ca','payload +10..+13 initialized 0')
eq(0x49588e,'8945ce','payload +14..+17 initialized 0')
eq(0x495891,'8945d2','payload +18..+21 initialized 0')
eq(0x495894,'8945d6','payload +22..+25 initialized 0')
eq(0x495897,'66894dda','payload +26/27 initialized 0x0001')
eq(0x49589b,'8945dc','payload +28..31 initialized 0')
eq(0x49589e,'8845e0','payload +32 initialized 0')
for addr,opcode in [(0x4958a1,'8945e1'),(0x4958a4,'8945e5'),(0x4958a7,'8945e9'),(0x4958aa,'8945ed'),(0x4958ad,'8945f1')]:
 eq(addr,opcode,f'payload tail dword initialized at {addr:#x}')
eq(0x4958b0,'8945f5','payload +53..56 initialized 0')
ck('payload +2 comes from object +0x67e0',rd(0x4958b8,6)==bytes.fromhex('8b90e0670000') and rd(0x4958be,3)==bytes.fromhex('8955c2'))
eq(0x4958c6,'6a0a','wide source copy max-count10')
eq(0x4958c8,'05e4670000','wide copy source object+0x67e4')
eq(0x4958ce,'8d45c6','wide copy dest payload+6')
eq(0x4958d1,'6a0a','wide dest wchar capacity10')
ck('wide bounded-copy helper actual call target',call(0x4958d4,0x893ffe))
eq(0x4958f1,'c645da01','payload+26 forced byte1')
eq(0x4958fa,'8a9098680000','payload+27 source object+0x6898')
eq(0x495900,'8855db','payload+27 stored')
eq(0x495908,'0599680000','byte copy source object+0x6899')
eq(0x49590e,'8d45dc','byte copy destination payload+28')
eq(0x495911,'6a05','byte copy capacity5')
ck('narrow bounded-copy helper target',call(0x495914,0x893b59))
eq(0x495921,'8b88a0680000','payload +33 dword source object+0x68a0')
eq(0x495927,'894de1','payload+33 dword stored')
eq(0x495935,'6a39','payload length57')
eq(0x495937,'8d45c0','payload base stack EBP-40')
eq(0x49593b,'6a00','queue slot0')
eq(0x49593d,'ffd2','manager indirect virtual+10')
eq(0x49594a,'57ffd2','key0 vtable+14 follow-up')
eq(0x495958,'53ffd2','key2 vtable+14 follow-up')
eq(0x49595b,'89be64bf0000','key0 connection recorded')
eq(0x495962,'899e68bf0000','key2 connection recorded')
eq(0x495968,'b801000000','local helper return1')
eq(0x49597e,'8b0d54a8fb00','partial failure missing key2')
eq(0x4959b0,'681c5ac000','partial failure missing key0')
eq(0x894000,'55','wide helper stack frame')
eq(0x89407a,'0fb70c06','wide helper reads WORD')
eq(0x89407e,'668908','wide helper writes WORD')
eq(0x8940b7,'668902','wide capacity failure clears first WORD')
eq(0x893b90,'8a08','byte helper reads one byte')
eq(0x893b92,'880c06','byte helper writes one byte')
eq(0x893ba1,'c60200','byte capacity exhaustion clears first byte')
eq(0x805d02,'c6862ca0000002','fresh Conn A02C=2')
eq(0x806202,'0fbe862ca00000','outbound A02C read')
ck('encoded writer called after mode !=0',call(0x806223,0x807830))
ck('plain fallback writer called',call(0x80623a,0x807a70))
eq(0x807d66,'66394b04','inbound BBB checksum compare')
eq(0x8068de,'8d8650a00000','WSASend overlapped Conn+A050')
eq(0x8068f7,'8d4814','WSABUF begins Conn+A064')
fields=[(0,2,'command'),(2,4,'object+67e0'),(6,20,'UTF16 10 slots'),(26,1,'constant1'),(27,1,'object+6898'),(28,5,'narrow 5 slots'),(33,4,'object+68a0'),(37,20,'zero-initialized')]
ck('57B extent partitioned with no overlaps',sorted(i for start,n,_ in fields for i in range(start,start+n))==list(range(57)))
def enc0(payload):
 x=bytes([payload[0]^0xb6]+[payload[i]^payload[i-1] for i in range(1,len(payload))])
 return struct.pack('<HHH',len(payload),0x0bbb,sum(payload)&0xffff)+x
mock=bytearray(57);mock[:2]=b'\x01\x00';mock[26]=1
frame=enc0(mock)
ck('synthetic key0 encoded frame length',len(frame)==63)
ck('synthetic checksum on controlled zero-value fixture',struct.unpack_from('<H',frame,4)[0]==2)
ck('synthetic key0 plain frame length',len(struct.pack('<HH',57,0x1a68)+mock)==61)
print(json.dumps({'source':str(p),'original_bin_sha256':H,'checks':len(check),'result':'PASS','scope':'native static first local key0 payload + bounded synthetic frame, NOT real Server first reply or wire ordering','layout':fields},ensure_ascii=False))
