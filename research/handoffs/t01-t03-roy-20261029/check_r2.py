"""Focused original-PE check against already saved REA/Ghidra evidence; no target execution."""
import pathlib,json,hashlib,struct,os
D=pathlib.Path(__file__).resolve().parent;R=D.parents[2]
B=pathlib.Path(os.environ.get('T01_TARGET','E:/Tartaros/workspace/Tartaros.bin')).read_bytes();H=hashlib.sha256(B).hexdigest();assert H=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
pe=struct.unpack_from('<I',B,0x3c)[0];opt=pe+24;ib=struct.unpack_from('<I',B,opt+28)[0];st=opt+struct.unpack_from('<H',B,pe+20)[0];sections=[]
for n in range(struct.unpack_from('<H',B,pe+6)[0]):
    p=st+40*n;vs,rva,size,raw=struct.unpack_from('<IIII',B,p+8);sections.append(dict(va=ib+rva,raw=raw,size=size,name=B[p:p+8].split(b'\0')[0].decode()))
def off(a):
    for s in sections:
        if s['va']<=a<s['va']+s['size']:return s['raw']+a-s['va']
    raise ValueError(hex(a))
def u(a):return struct.unpack_from('<I',B,off(a))[0]
def cstr(a):p=off(a);return B[p:B.index(b'\0',p)].decode('ascii')
imports=[];descriptor=ib+struct.unpack_from('<I',B,opt+104)[0]
while any(struct.unpack_from('<IIIII',B,off(descriptor))):
    original,_,_,name,first=struct.unpack_from('<IIIII',B,off(descriptor));dll=cstr(ib+name);n=0
    while value:=u(ib+(original or first)+4*n):
        item=dict(iat_va=hex(ib+first+4*n),dll=dll)
        item.update(ordinal=value&0xffff) if value&0x80000000 else item.update(name=cstr(ib+value+2))
        imports.append(item);n+=1
    descriptor+=20
lookup={int(x['iat_va'],16):x for x in imports}
assert lookup[0xbd2284]['name']=='InterlockedIncrement'
assert lookup[0xbd2478]['name']=='GetAsyncKeyState'
assert lookup[0xbd25f4]['name']=='D3DXSaveSurfaceToFileW'
assert lookup[0xbd2618]['name']=='D3DXCreateTexture'
assert lookup[0xbd2614]['name']=='D3DXLoadSurfaceFromSurface'
P=R/'shared/integrations/T01-20261029-continuation-02/t16'
cache=json.loads((P/'native-evidence.json').read_text(encoding='utf8'));assert cache['binary_sha256']==H
f=cache['functions']['0x8068b0'];index=f['index'];bulk=pathlib.Path(os.environ.get('T01_BULK_ROOT','E:/Tartaros/workspace/anal-multi/kr-bulk-roy'))/H
for key,digest in [('pseudocode_path','pseudocode_sha256'),('batch_path','batch_sha256')]:assert hashlib.sha256((bulk/index[key]).read_bytes()).hexdigest()==index[digest]
assert index['source_sha256']==H
for i in f['cfg']['instructions']:
    p=off(int(i['va'],16));raw=bytes.fromhex(i['bytes']);assert B[p:p+len(raw)]==raw
addresses=[0x8068de,0x8068f3,0x8068f7,0x806903,0x806909,0x806912,0x806961,0x806968,0x80697a,0x806981]
ins=[i for i in f['cfg']['instructions'] if int(i['va'],16) in addresses];assert len(ins)==len(addresses)
out=dict(ok=True,target_sha256=H,scope='T03-6 API layout correction and T03-18 import identity only; no whole-document or gameplay promotion',sections=sections,imports=[lookup[a] for a in [0xbd2284,0xbd2478,0xbd25f4,0xbd2618,0xbd2614]],prior_rea_cache_index=index,prior_cfg_source='shared/integrations/T01-20261029-continuation-02/t16/native-evidence.json',instructions=ins,findings=['8068DE EAX=connection+A050;8068F3 pushesEAX as OVERLAPPED;8068F7 ECX=EAX+14 then806909 pushesWSABUF pointer connection+A064.','806961/80697A formconnection+A0B8 then806968/806981 callInterlockedIncrement. A0B8 is the DWORD atomic-counter address passed here, not the OVERLAPPED argument.','GetAsyncKeyState and D3DX imports independently agree with T03-18 exclusion of screenshot branch from selection reply provenance.'],limitations=['Static valid-call argument/dataflow; no runtime observation or historical DLL loading claim.','Source-derived screenshot functional interpretation remains inference; precise COM interface and worker target unknown.'])
(D/'r2-evidence.json').write_bytes((json.dumps(out,ensure_ascii=False,indent=2)+'\n').encode())
print(json.dumps(dict(ok=True,prior_function_instructions_matched=len(f['cfg']['instructions']),focused_instructions=len(ins),named_imports=5,new_fullpass=0)))
