#!/usr/bin/env python3
"""E84 read-only BIN-native bounded RR-0007 dispatch audit. No Client execution.
Usage: python -B 20261101-chatgpt-web-roy-E84-RR0007-verify.py Tartaros.bin
"""
import hashlib,struct,sys,json
from pathlib import Path
b=Path(sys.argv[1] if len(sys.argv)>1 else 'Tartaros.bin').read_bytes()
H='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
assert len(b)==12472320 and hashlib.sha256(b).hexdigest()==H
pe=struct.unpack_from('<I',b,0x3c)[0]
assert b[:2]==b'MZ' and b[pe:pe+4]==b'PE\0\0'
n=struct.unpack_from('<H',b,pe+6)[0]; o=pe+24+struct.unpack_from('<H',b,pe+20)[0]
s={}
for i in range(n):
 p=o+i*40;name=b[p:p+8].split(b'\0')[0].decode()
 vs,va,rawsize,raw=struct.unpack_from('<IIII',b,p+8);s[name]=(va+0x400000,vs,rawsize,raw)
def rd(va,n):
 for name,(start,virtual,sz,raw) in s.items():
  if start<=va and va+n<=start+sz: return b[raw+va-start:raw+va-start+n]
 raise ValueError(f'not in raw PE section: {va:x} +{n}')
def u32(va):return struct.unpack('<I',rd(va,4))[0]
def hx(addr,hexstr):return rd(addr,len(bytes.fromhex(hexstr)))==bytes.fromhex(hexstr)
def relcall(addr,target):return rd(addr,1)==b'\xe8' and addr+5+struct.unpack('<i',rd(addr+1,4))[0]==target
c={}
def ck(key,cond):
 c[key]=bool(cond)
 if not cond:raise AssertionError(f'{key}: failed')
ck('PE .text VA,raw & size',s['.text'][0]==0x401000 and s['.text'][2]==0x7d0200 and s['.text'][3]==0x400)
ck('producer builds 3029 slots',hx(0x493180,'bed50b0000'))
ck('producer default pointer 494360',hx(0x493173,'bf60434900'))
ck('producer default slot and marker',hx(0x493190,'897af8') and hx(0x493193,'895afc') and hx(0x493196,'890a'))
ck('producer stride16',hx(0x493198,'83c210'))
ck('producer loop',hx(0x49319b,'4e') and hx(0x49319c,'75f2'))
ck('factory uses router producer',relcall(0x48c02a,0x493170) and hx(0x48c027,'8d43f8'))
# Known x86 instruction form BA imm32; 89 90 disp32, not an exhaustive disassembler.
va=0x493170; raw=rd(va,0x494360-va)
slots={}
for off in range(len(raw)-11):
 if raw[off]==0xBA and raw[off+5:off+7]==b'\x89\x90':
  target=struct.unpack_from('<I',raw,off+1)[0]
  disp=struct.unpack_from('<I',raw,off+7)[0]
  if disp>=0x208 and (disp-0x208)%16==0:
   slots[(disp-0x208)//16]=target
ck('roster app2 uses generic router slot',slots.get(0x2) is None)
ck('login app13 uses generic router slot',slots.get(0x13) is None)
ck('login app7A uses generic router slot',slots.get(0x7A) is None)
ck('scene app42 uses generic router slot',slots.get(0x42) is None)
ck('scene app43 uses generic router slot',slots.get(0x43) is None)
ck('scene app69 uses generic router slot',slots.get(0x69) is None)
ck('app2B branch overrides to 4943B0',slots.get(0x2B)==0x4943B0)
ck('app2B exact store offset',hx(0x49337a,'8990b8040000'))
ck('generic and other routers distinct',0x494360!=0x4943B0)
ck('first hop lazy FD2CF8 singleton',hx(0x494376,'c705f82cfd00b46ec000') and relcall(0x49438a,0x4b7dc0))
ck('generic router directs to FD2CF8',hx(0x49439c,'b9f82cfd00') and hx(0x4943a1,'a1f82cfd00') and hx(0x4943a6,'8b5004'))
ck('alternative hop F8D9E0 singleton',hx(0x494416,'a1e0d9f800') and hx(0x494420,'b9e0d9f800'))
ck('alternative vptr+4 call',hx(0x49441d,'8b5004') and hx(0x494425,'ffd2'))
ck('FD2CF8 vtable+4=4FDA30',u32(0xC06EB4+4)==0x4FDA30)
ck('first-layer table initial default',hx(0x4b7dc0,'b8002dfd00') and hx(0x4b7dc5,'bac07e4b00'))
ck('first-layer default stride8',hx(0x4b7dd5,'83c008'))
ck('first-layer direct command2',hx(0x4b7ddf,'c7050c2dfd00007f4b00'))
ck('first-layer command2 lookup index and direct handler',0xfd2d0c == 0xfd2cf8+4+2*8 and relcall(0x4b89ad,0x4d4150))
ck('FD2CF8 dispatcher signed command index',hx(0x4fda3b,'0fbff9'))
ck('FD2CF8 nonzero handler lookup',hx(0x4fda3e,'8b44fe04'))
ck('FD2CF8 default vtable slot+c',hx(0x4fda49,'8b06') and hx(0x4fda4e,'8b400c'))
ck('scene pointer null default',hx(0x4b7ec3,'83b9ac5e000000') and hx(0x4b7eca,'740e'))
ck('scene current pointer and vptr+4',hx(0x4b7ecc,'8b89ac5e0000') and hx(0x4b7ed4,'8b4004'))
ck('scene LOGIN vptr+4 route',u32(0xc072fc+4)==0x4c4670)
ck('scene signed index',hx(0x4c4679,'0fbff8'))
ck('scene second-table stride8',hx(0x4c467e,'8b9cfeac5e0000'))
ck('scene second-table no override falls to base',relcall(0x4c4694,0x4fda30))
ck('scene second-table nonzero handler',hx(0x4c46a0,'8b94feb05e0000') and hx(0x4c46c5,'ffd3'))
ck('LOGIN second-table slot13',hx(0x4c323b,'c786445f0000a0374c00') and (0x5f44-0x5eac)//8==0x13)
ck('LOGIN second-table slot7A',hx(0x4c325b,'c7867c620000103c4c00') and (0x627c-0x5eac)//8==0x7a)
ck('app2B special handler 2+53n',hx(0x4e273d,'83f802') and hx(0x4e2749,'b8b3cf2135') and hx(0x4e278a,'83c735'))
ck('app2B role id boundary',hx(0x4e2767,'0fb6472e') and hx(0x4e276b,'83f809'))
ck('app2B direct role copy',relcall(0x4e2782,0x4d4150))
ck('app2B common role post',relcall(0x4e2794,0x4e5fb0))
ck('app2B mapped slot2B in F8D9E0 table',hx(0x4e1e3f,'c7805c01000030274e00') and (0x15c-4)//8==0x2b)
ck('main callback reads app WORD before nonzero length check',hx(0x4930ed,'0fb738') and hx(0x4930f6,'85db'))
ck('main callback requires lane2',hx(0x493105,'8b451483e802') and hx(0x49310b,'7547'))
ck('main callback [client+B8] vptr+4 dispatch',hx(0x493120,'8b96b8000000') and hx(0x493129,'8b5204'))
ck('BE8C only checked after forwarding',hx(0x49313f,'81ff00010000') and hx(0x493147,'83be8cbe000000'))
ck('generic no-scene returns zero',hx(0x4b7eec,'33c0') and hx(0x4b7eef,'c20c00'))
ck('S2C13 status-read',hx(0x4c3821,'8a5616'))
ck('S2C7A group-list origin',hx(0x4c3c10,'55') and hx(0x4c3c16,'8b4802'))
ck('alias semantics distinguished',0xfd2cf8!=0xf8d9e0 and 0x4fda30!=0x4e2730)
print(json.dumps({'status':'PASS','assertions':len(c),'source_sha256':H,'explicit_override_records':len(slots),'selection':{hex(i):hex(slots[i]) if i in slots else 'generic 0x494360' for i in [2,0x13,0x42,0x43,0x69,0x7a,0x2b]},'runtime_tested':False,'original_server_traced':False},ensure_ascii=False))
