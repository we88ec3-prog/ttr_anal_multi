from review import *
import struct
def u(a):return int.from_bytes(audit.data(a,4),'little')
def z(a):return audit.B[audit.offset(a):].split(b'\0',1)[0].decode('ascii',errors='replace')
iat=[]
rva=struct.unpack_from('<I',audit.B,audit.opt+104)[0];a=audit.ib+rva
while any(audit.data(a,20)):
    original,timestamp,chain,dll,first=struct.unpack('<IIIII',audit.data(a,20));name=z(audit.ib+dll);p=audit.ib+(original or first);slot=audit.ib+first
    while u(p):
        v=u(p);iat.append(dict(dll=name,iat_va=hex(slot),import_name=('#'+str(v&0xffff)) if v&0x80000000 else z(audit.ib+v+2)));p+=4;slot+=4
    a+=20
tables=[]
for va,n in [(0xc51748,11)]:tables.append(dict(va=hex(va),raw=hex(audit.offset(va)),entries=[hex(u(va+i*4)) for i in range(n)]))
text=next(x for x in audit.sections if x['name']=='.text');b=audit.B[text['raw']:text['raw']+text['raw_size']];edges=[]
for target in [0x4a89c0,0x4a8a60,0x4a8b90,0x6f4a50,0x6f4dd0,0x504740,0x505570,0x804100,0x804740,0x8076f0,0x8040a0]:
    sites=[]
    for i in range(len(b)-4):
        if b[i]==0xe8 and text['va']+i+5+struct.unpack_from('<i',b,i+1)[0]==target:sites.append(hex(text['va']+i))
    edges.append(dict(target=hex(target),raw_e8_candidates=sites,limits='Raw E8 candidates, full instruction alignment/CFG decisions remain separate.'))
bad=[]
for x in Q:
    for s in set(re.findall('26e5[0-9a-f]+',(R/x['source']).read_text(encoding='utf8'))):
        if len(s)!=64:bad.append(dict(source=x['source'],git_blob_sha=x['git_blob_sha'],claimed_sha256=s,length=len(s),correct_sha256='26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744'))
audit.save(D/'tables-and-xrefs.json',dict(binary_sha256=audit.H,imports=iat,tables=tables,e8=edges,invalid_resource_hashes=bad))
print('imports',len(iat),'vtable',tables,'invalid hashes',len(bad))
