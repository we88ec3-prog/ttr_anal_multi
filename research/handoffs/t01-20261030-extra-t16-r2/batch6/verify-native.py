#!/usr/bin/env python3
"""KR T01 R2 Batch6, read-only selected native bytes/branches/vtable. Does NOT prove full CFG."""
from pathlib import Path
import json,struct,hashlib,sys
here=Path(__file__).resolve().parent
spec=json.loads((here/'native-verification-manifest.json').read_text(encoding='utf8'))
b=Path(sys.argv[1] if len(sys.argv)>1 else '/mnt/data/Tartaros.bin').read_bytes()
assert len(b)==spec['size_bytes'] and hashlib.sha256(b).hexdigest()==spec['target_sha256']
pe=struct.unpack_from('<I',b,0x3c)[0]
assert b[pe:pe+4]==bytes([80,69,0,0])
ib=struct.unpack_from('<I',b,pe+24+28)[0]; assert ib==0x400000
sec=pe+24+struct.unpack_from('<H',b,pe+20)[0];sects={}
for i in range(struct.unpack_from('<H',b,pe+6)[0]):
 a=sec+i*40
 name=b[a:a+8].split(bytes([0]))[0].decode('ascii')
 vs,rva,rawsize,raw=struct.unpack_from('<IIII',b,a+8)
 sects[name]=(ib+rva,raw,rawsize)
assert sects['.text'][:2]==(0x401000,0x400)
assert sects['.rdata'][:2]==(0xbd2000,0x7d0600)
def read(va,n,s='.text'):
 start,raw,size=sects[s];p=raw+va-start
 assert raw<=p and p+n<=raw+size
 return b[p:p+n]
for t in spec['checks']:
 va=int(t['va'],16);expect=bytes.fromhex(t['hex']);assert read(va,len(expect))==expect,(hex(va),expect.hex())
for e in spec['branch_edges']:
 va=int(e['va'],16);b6=read(va,6)
 if b6[0] in (0xe8,0xe9):n=5;dis=struct.unpack_from('<i',b6,1)[0]
 elif b6[0] in (0x74,0x75):n=2;dis=struct.unpack_from('<b',b6,1)[0]
 elif b6[0]==0x0f and 0x80<=b6[1]<=0x8f:n=6;dis=struct.unpack_from('<i',b6,2)[0]
 else:raise AssertionError(('Unsupported opcode',hex(va),b6.hex()))
 assert ((va+n+dis)&0xffffffff)==int(e['to'],16),e
for va,dst in spec['critical_vtable'].items():
 assert struct.unpack('<I',read(int(va,16),4,'.rdata'))[0]==int(dst,16)
print(json.dumps({'status':'PASS','native_checks':len(spec['checks']),'direct_edges':len(spec['branch_edges']),'vtable':len(spec['critical_vtable']),'scope':'selected R2 evidence only'},ensure_ascii=False))
