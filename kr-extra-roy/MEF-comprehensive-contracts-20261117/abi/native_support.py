"""Data-only PE mapping and objdump evidence reader. Never executes the target."""
from pathlib import Path
import hashlib,re,struct,subprocess
BIN_SHA='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
def sha(b):return hashlib.sha256(b).hexdigest()
def need(c,m):
 if not c:raise ValueError(m)
class PE:
 def __init__(self,path):
  self.path=Path(path);self.b=self.path.read_bytes();need(sha(self.b)==BIN_SHA,'KR BIN SHA')
  p=struct.unpack_from('<I',self.b,60)[0];o=p+24
  need(self.b[:2]==b'MZ' and self.b[p:p+4]==b'PE\0\0','PE identity')
  need(struct.unpack_from('<H',self.b,p+4)[0]==0x14c and struct.unpack_from('<H',self.b,o)[0]==0x10b,'PE32 i386')
  self.base=struct.unpack_from('<I',self.b,o+28)[0];need(self.base==0x400000,'ImageBase')
  st=o+struct.unpack_from('<H',self.b,p+20)[0];self.sections=[]
  for i in range(struct.unpack_from('<H',self.b,p+6)[0]):
   s=st+40*i;vs,rv,rs,ro=struct.unpack_from('<IIII',self.b,s+8);self.sections.append((self.b[s:s+8].rstrip(b'\0').decode(),self.base+rv,rs,ro))
 def raw(self,a,n=1):
  x=[o+a-v for _,v,s,o in self.sections if v<=a and a+n<=v+s]
  need(len(x)==1,'Unique raw backing '+hex(a));return x[0]
 def at(self,a,n):o=self.raw(a,n);return self.b[o:o+n]
 def decode(self,a,z):
  s=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16','--start-address='+hex(a),'--stop-address='+hex(z+15),str(self.path)],text=True)
  out=[]
  for line in s.splitlines():
   m=re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)$',line)
   if not m:continue
   v=int(m[1],16)
   if v>=z:continue
   b=bytes.fromhex(m[2]);need(b==self.at(v,len(b)),'Decoded byte identity');out.append(dict(va=hex(v),hex=b.hex(),asm=m[3].strip()))
  return out
 def function(self,a,limit=0x1400):
  rows=self.decode(a,a+limit);idx={int(x['va'],16):x for x in rows};seen=set();todo=[a]
  while todo:
   v=todo.pop()
   if v in seen:continue
   need(v in idx,'Branch target boundary '+hex(v));seen.add(v);x=idx[v];asm=x['asm'];mn=asm.split()[0];b=bytes.fromhex(x['hex']);n=v+len(b)
   need('(bad)'not in asm and mn not in ('int3','int','hlt'),'Unexpected reachable data/trap '+hex(v))
   if mn.startswith('ret'):continue
   if mn.startswith('j') or mn.startswith('loop'):
    q=re.search(r'0x([0-9a-f]+)',asm)
    need(q is not None,'Computed branch not supported '+hex(v));t=int(q[1],16)
    if a<=t<a+limit:todo.append(t)
    else:need(mn=='jmp','Conditional branch escaped bound')
    if mn=='jmp':continue
   need(n<a+limit,'Function exceeds bound');todo.append(n)
  z=max(v+len(bytes.fromhex(idx[v]['hex']))for v in seen)
  contiguous=[x for x in rows if int(x['va'],16)<z];cursor=a
  for x in contiguous:
   need(int(x['va'],16)==cursor and '(bad)'not in x['asm'],'Contiguous decoded evidence');cursor+=len(bytes.fromhex(x['hex']))
  need(cursor==z,'Exact function end')
  data=self.at(a,z-a)
  return dict(id='F_'+format(a,'08X'),va=hex(a),end_exclusive=hex(z),raw=hex(self.raw(a)),size=z-a,sha256=sha(data),hex=data.hex(),reachable_instruction_count=len(seen),instructions=contiguous)
