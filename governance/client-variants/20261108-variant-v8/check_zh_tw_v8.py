"""Bounded checks of new translation wrapper with mocked mount helpers only.
No native game code or operating-system API is executed.
"""
from pathlib import Path
import sys,json,struct,hashlib
R=Path(__file__).resolve().parents[2];sys.path[:0]=[str(R/'anal'),str(R/'anal/python_deps')]
from build_native_index import PE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from capstone.x86_const import X86_OP_REG,X86_OP_IMM
m=json.loads((R/'CLIENT/evidence/20261108-variant-v8/build-manifest.json').read_text(encoding='utf-8'))
pe=PE(R/'Tartaros.ip-zh-tw-v8.exe');md=Cs(CS_ARCH_X86,CS_MODE_32);md.detail=True
rows=m['exe']['preloaderInstructions'];start=int(m['exe']['preloaderEntry'],16);end=int(rows[-1]['va'],16)+len(bytes.fromhex(rows[-1]['bytes']))
ins={i.address:i for i in md.disasm(pe.read(start,end-start),start)}
assert all(pe.read(int(r['va'],16),len(bytes.fromhex(r['bytes'])))==bytes.fromhex(r['bytes']) for r in rows)
sec=next(s for s in pe.sections if s['va']==start);mem={start+i:v for i,v in enumerate(pe.read(start,sec['size']))}
def write(a,n,v):
 for j in range(n):mem[a+j]=(v>>(j*8))&255
def read(a,n):return sum(mem.get(a+j,0)<<(j*8) for j in range(n))
def string(a):
 out=[]
 while read(a,1):out.append(read(a,1));a+=1
 return bytes(out).decode('ascii')
regs=dict(eax=0x12345678,ecx=0x20000000,edx=0x87654321,ebx=0x11111111,esp=0x30000000,ebp=0x44444444,esi=0x22222222,edi=0x33333333)
before=regs.copy();flags=0x202;original_flags=flags;baseline=int(m['exe']['baselinePathVa'],16)
for i,v in enumerate('UI/StringTable/English(United States).FCS\0'.encode('utf-16le')):mem[baseline+i]=v
write(0xfba814,4,0x21000000);write(regs['esp'],4,0xdeadbeef);write(regs['esp']+4,4,0x20000000)
def push(v):regs['esp']-=4;write(regs['esp'],4,v)
def pop():
 v=read(regs['esp'],4);regs['esp']+=4;return v
def reg(n):return regs[n]
def addr(op):return ((reg(md.reg_name(op.mem.base)) if op.mem.base else 0)+(reg(md.reg_name(op.mem.index))*op.mem.scale if op.mem.index else 0)+op.mem.disp)&0xffffffff
def val(op):
 if op.type==X86_OP_REG:return reg(md.reg_name(op.reg))
 if op.type==X86_OP_IMM:return op.imm&0xffffffff
 return read(addr(op),op.size)
def assign(op,v):
 if op.type==X86_OP_REG:regs[md.reg_name(op.reg)]=v&0xffffffff
 else:write(addr(op),op.size,v)
pc=start;calls=[]
for step in range(500):
 if pc==int(m['exe']['oldLoader'],16):break
 i=ins[pc];op=i.operands;nxt=pc+i.size
 if i.mnemonic=='pushfd':push(flags)
 elif i.mnemonic=='popfd':flags=pop()
 elif i.mnemonic=='pushal':
  initial=regs.copy()
  for n in ['eax','ecx','edx','ebx','esp','ebp','esi','edi']:push(initial[n])
 elif i.mnemonic=='popal':
  for n in ['edi','esi','ebp','SKIP','ebx','edx','ecx','eax']:
   v=pop()
   if n!='SKIP':regs[n]=v
 elif i.mnemonic=='push':push(val(op[0]))
 elif i.mnemonic=='mov':assign(op[0],val(op[1]))
 elif i.mnemonic=='lea':assign(op[0],addr(op[1]))
 elif i.mnemonic=='add':assign(op[0],val(op[0])+val(op[1]))
 elif i.mnemonic in ['cmp','test']:
  a,b=val(op[0]),val(op[1]);zero=(a==b if i.mnemonic=='cmp' else a&b==0);flags=(flags&~0x40)|(0x40 if zero else 0)
 elif i.mnemonic in ['je','jne','jmp']:
  if i.mnemonic=='jmp' or (bool(flags&0x40)==(i.mnemonic=='je')):nxt=val(op[0])
 elif i.mnemonic=='call':
  a=val(op[0]);arg=read(regs['esp'],4);cleanup=4;calls.append(a)
  if op[0].type!=X86_OP_IMM:assert string(arg)=='U8/StringTable.stp';regs['eax']=0
  elif a==0x714d50:
   if string(arg)=='U8':assert regs['ecx']==0x21000004;regs['eax']=0x24000000
   else:assert string(arg)=='StringTable' and regs['ecx']==0x24000000;regs['eax']=0x25000000
  elif a==0x891268:assert arg==0x178;cleanup=0;regs['eax']=0x26000000
  elif a==0x715270:assert arg==0x26000000;regs['eax']=arg
  elif a==0x715620:assert string(regs['edx'])=='U8/StringTable' and regs['ecx']==0x26000000 and arg==1;regs['eax']=0
  else:raise AssertionError(hex(a))
  regs['esp']+=cleanup
 else:raise AssertionError(i.mnemonic)
 pc=nxt
else:raise AssertionError('Instruction bound')
assert regs==before and flags==original_flags
assert read(0x25000100,4)==0x26000000 and read(baseline+2,2)==ord('8')
assert ''.join(chr(read(baseline+j,2)) for j in range(0,82,2))=='U8/StringTable/English(United States).FCS'
for f in m['outputs']:assert hashlib.sha256((R/f['path']).read_bytes()).hexdigest()==f['sha256']
for f,h in m['preservedExistingFiles'].items():assert hashlib.sha256((R/f).read_bytes()).hexdigest()==h
result={'check':'POSITIVE_TRANSLATION_WRAPPER_MOCK_ABI_ONLY','instructions':step,'calls':len(calls),'registersFlagsStackPreserved':True,'localePathRedirectAfterSuccessfulMount':True,'outputsAndPreservedSourcesMatchManifest':True,'actualNativeResourceLoading':'NOT_EXECUTED','runtime':'PENDING_USER'}
(R/'CLIENT/evidence/20261108-variant-v8/static-check.json').write_bytes((json.dumps(result,indent=2)+'\n').encode());print(json.dumps(result))
