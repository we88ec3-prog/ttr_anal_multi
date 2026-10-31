#!/usr/bin/env python3
"""E81 bounded read-only static checks, not Client runtime or UI acceptance."""
import hashlib, struct, sys
from pathlib import Path
p=Path(sys.argv[1] if len(sys.argv)>1 else '/mnt/data/Tartaros.bin')
b=p.read_bytes()
H='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
assert len(b)==12472320 and hashlib.sha256(b).hexdigest()==H
pe=struct.unpack_from('<I',b,0x3c)[0];assert b[:2]==b'MZ' and b[pe:pe+4]==b'PE\x00\x00'
sec={}; off=pe+24+struct.unpack_from('<H',b,pe+20)[0]
for i in range(struct.unpack_from('<H',b,pe+6)[0]):
 t=off+i*40
 nm=b[t:t+8].split(b'\0')[0].decode()
 virt,va,rawsize,raw=struct.unpack_from('<IIII',b,t+8)
 sec[nm]=(0x400000+va,rawsize,raw)
def data(va,n):
 for name,(start,size,off) in sec.items():
  if start<=va and va+n<=start+size:return b[off+va-start:off+va-start+n]
 raise ValueError(hex(va))
def u32(va): return struct.unpack('<I',data(va,4))[0]
def e8(where,target):return data(where,1)==b'\xe8' and where+5+struct.unpack('<i',data(where+1,4))[0]==target
v,sz,raw=sec['.text'];text=b[raw:raw+sz]
def calls(target):
 return [v+i for i in range(len(text)-4) if text[i]==0xe8 and v+i+5+struct.unpack_from('<i',text,i+1)[0]==target]
checks={}
def ck(name,test):
 checks[name]=bool(test)
 if not test:raise AssertionError(name)
def hx(name,va,s): ck(name,data(va,len(bytes.fromhex(s)))==bytes.fromhex(s))
ck('PE identity and fixed original hash',True)
hx('roster N0 control-flow gate',0x4B894C,'0f84ce000000')
hx('roster common post after skipped rows',0x4B8A60,'66a34042f900')
ck('roster post call 4E5FB0',e8(0x4B8A9C,0x4E5FB0))
hx('roster per-record only sets ready',0x4D4154,'c7465c01000000')
ck('Employ RTTI',data(u32(u32(0xC3F024-4)+12)+8,31).startswith(b'.?AVCEmployNewCharacter@FUI@@'))
ck('owner caches Employ at +230',e8(0x5C30FD,0x5AB020) and data(0x5C30F7,6)==bytes.fromhex('8db330020000'))
ck('owner registers Employ at +230',e8(0x5C316A,0x596D70))
ck('owner UI type roster includes 0x11B',e8(0x5C32A2,0x4095E0) and data(0x5C329A,5)==bytes.fromhex('681b010000'))
hx('owner event decoder uses F42DB',0x5C32E0,'8b47102ddb420f00')
ck('owner event route to 5C36D0',e8(0x5C32F6,0x5C36D0))
ck('owner F42DD branch calls 5C34B0',e8(0x5C3303,0x5C34B0))
ck('owner event F431F branch shift arithmetic',data(0x5C32EF,5)==bytes.fromhex('83e842754c'))
ck('owner UI input reaches Employ update',e8(0x5C36DE,0x6BF310))
ck('owner updates popup visibility',e8(0x5C36EB,0x596E00))
hx('owner client-local F43FD creation',0x5C370E,'c74010fd430f00')
ck('controller F431F consumer',data(0x5AAEA9,7)==bytes.fromhex('817f101f430f00'))
ck('controller F431F nonzero result UI update',e8(0x5AAED2,0x6BF310))
hx('controller F431F zero result 0x33 builder',0x5AAF11,'ba330000006689550a')
ck('controller 0x33 queue virtual only if gate',data(0x5AAF0A,7)==bytes.fromhex('833d98a7fb0000'))
ck('controller local event producer 4A98D0',data(0x4A992A,5)==bytes.fromhex('681f430f00'))
ck('local F431F producer delegates event helper',e8(0x4A992F,0x58AB80))
ck('callback installed at FE1838',data(0x4AAE18,10)==bytes.fromhex('c7053818fe00d0984a00'))
ck('callback FE1838 read into local wrapper',data(0x4AC376,6)==bytes.fromhex('8b0d3818fe00'))
ck('indirect wrapper invokes 4ACB70',e8(0x4AC380,0x4ACB70))
ck('direct refs to 4A98D0 are absent E8',not calls(0x4A98D0))
ck('local F431F literal sites exact', [hex(v+i) for i in range(len(text)-3) if text[i:i+4]==(0xf431f).to_bytes(4,'little')]==['0x4a992b','0x5aaeac','0x6ba33c'])
ck('Employ event still gated by existing UI control',data(0x6BF2A6,7)==bytes.fromhex('81781078050000'))
ck('Employ callback dispatches 0x33 producer',e8(0x6BF2FA,0x4A38D0))
ck('no direct N0 roster to Employ cache',not any(0x4B7F00<=i<0x4B8F40 for i in calls(0x5AB020)))
ck('N0 roster has no direct F431F producer',not any(0x4B7F00<=v+i<0x4B8F40 for i in range(len(text)-3) if text[i:i+4]==(0xf431f).to_bytes(4,'little')))
print(f'E81 PASS {len(checks)} bounded first-hand BIN assertions; hash={H}')
print('UI flow: F431F local event -> two conditional consumers -> Employ update/0x33; not proof N0 triggers F431F or visible create GUI')
