#!/usr/bin/env python3
"""T01 batch3: read-only exact KR .text byte/edge reproducibility (not full CFG)."""
import json,sys,hashlib,struct
from pathlib import Path
here=Path(__file__).resolve().parent
spec=json.loads((here/'native-batch3-expectations.json').read_text(encoding='utf-8'))
file=Path(sys.argv[1]) if len(sys.argv)>1 else Path('/mnt/data/Tartaros.bin')
b=file.read_bytes()
assert len(b)==spec['size_bytes'] and hashlib.sha256(b).hexdigest()==spec['target_sha256']
pe=struct.unpack_from('<I',b,0x3c)[0]
assert b[pe:pe+4]==bytes([80,69,0,0])
imagebase=struct.unpack_from('<I',b,pe+24+28)[0]
sec_base=pe+24+struct.unpack_from('<H',b,pe+20)[0]
count=struct.unpack_from('<H',b,pe+6)[0]
sections={}
for i in range(count):
 o=sec_base+40*i
 name=b[o:o+8].split(bytes([0]))[0].decode('ascii','replace')
 virtual_size,rva,raw_size,raw_off=struct.unpack_from('<IIII',b,o+8)
 sections[name]=(imagebase+rva,raw_off,raw_size)
va_base,raw_base,raw_len=sections['.text']
assert (va_base,raw_base)==(0x401000,0x400)
def at(va,n):
 raw=raw_base+va-va_base
 assert raw_base<=raw and raw+n<=raw_base+raw_len
 return b[raw:raw+n]
for test in spec['checks']:
 va=int(test['va'],16)
 expected=bytes.fromhex(test['hex'])
 got=at(va,len(expected))
 assert got==expected,(hex(va),got.hex(),expected.hex(),test['description'])
for edge in spec['edges']:
 va=int(edge['from'],16);to=int(edge['to'],16);op=at(va,6)
 if op[0]==0xe8: n=5;dis=1
 elif op[0]==0x74: n=2;dis=1
 elif op[:2]==bytes.fromhex('0f84'): n=6;dis=2
 else:raise AssertionError(('unsupported edge opcode',hex(va),op.hex()))
 actual=(va+n+int.from_bytes(op[dis:n],'little',signed=True))&0xffffffff
 assert actual==to,(hex(va),hex(actual),hex(to))
print(json.dumps({'target_sha256':spec['target_sha256'],'checked_bytes':len(spec['checks']),'checked_edges':len(spec['edges']),'status':'PASS','limitation':'R2 selected paths only'},ensure_ascii=False))
