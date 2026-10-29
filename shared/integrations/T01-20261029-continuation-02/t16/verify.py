import pathlib,sys,os,json,re,hashlib,bisect,struct,collections
D=pathlib.Path(__file__).resolve().parent
R=D.parents[3]
S=R/'shared/integrations/T01-20261029-semantic-review/support'
if not os.environ.get('T01_CAPSTONE_ROOT'):
    os.environ['T01_CAPSTONE_ROOT']='E:/Tartaros/workspace/t01-work-20261029/vendor'
sys.path.insert(0,str(S))
import audit
Q=[x for x in json.loads((S/'review-queue.json').read_text(encoding='utf8'))['rows'] if x['task']=='T16' and x['number'] in [69,70,71]]
P=R/'kr-bulk-roy'/audit.H
if not (P/'index.jsonl').exists():P=pathlib.Path(os.environ.get('T01_BULK_ROOT','E:/Tartaros/workspace/anal-multi/kr-bulk-roy'))/audit.H
I={int(x['address'],16):x for x in map(json.loads,(P/'index.jsonl').read_text(encoding='utf8').splitlines())}
starts=sorted(I)
def cached(a):
    row=I[a]; path=P/row['pseudocode_path']
    assert hashlib.sha256(path.read_bytes()).hexdigest()==row['pseudocode_sha256']
    assert row['source_sha256']==audit.H
    if row.get('batch_path'):
        assert hashlib.sha256((P/row['batch_path']).read_bytes()).hexdigest()==row['batch_sha256']
    return dict(index=row,pseudocode=path.read_text(encoding='utf8'),cfg=audit.cfg(a))
def normalize(s):
    s=s.split(';')[0].lower()
    s=re.sub(r'(ds:|fs:)(0x[0-9a-f]+)',lambda m:('fs:' if m[1]=='fs:' else '')+'['+m[2]+']',s).replace('ds:','')
    s=re.sub(r'0x[0-9a-f]+',lambda m:str(int(m[0],16)),s)
    s=s.replace('4294967295','-1')
    return re.sub(r'\s+','',s)
def tables():
    def u(a):return int.from_bytes(audit.data(a,4),'little')
    def z(a):return audit.B[audit.offset(a):].split(b'\0',1)[0].decode('ascii')
    a=audit.ib+struct.unpack_from('<I',audit.B,audit.opt+104)[0];imports=[]
    while any(audit.data(a,20)):
        orig,ts,chain,dll,first=struct.unpack('<IIIII',audit.data(a,20));p=audit.ib+(orig or first);slot=audit.ib+first
        while u(p):
            value=u(p);imports.append(dict(dll=z(audit.ib+dll),iat_va=hex(slot),raw=hex(audit.offset(slot)),name=('#'+str(value&0xffff)) if value&0x80000000 else z(audit.ib+value+2)));p+=4;slot+=4
        a+=20
    entries=list(struct.unpack('<11I',audit.data(0xc51748,44)))
    exe=pathlib.Path(os.environ.get('T01_EXE','E:/Tartaros/workspace/Tartaros.exe')).read_bytes()
    dllpath=pathlib.Path(os.environ.get('T01_WS2_DLL','C:/Windows/SysWOW64/ws2_32.dll')); dllbytes=dllpath.read_bytes()
    pe=struct.unpack_from('<I',dllbytes,0x3c)[0]; opt=pe+24; count=struct.unpack_from('<H',dllbytes,pe+6)[0]; st=opt+struct.unpack_from('<H',dllbytes,pe+20)[0]
    sec=[struct.unpack_from('<IIII',dllbytes,st+40*k+8) for k in range(count)]
    def raw(rva):
        for vs,va,size,start in sec:
            if va<=rva<va+size:return start+rva-va
        raise ValueError(hex(rva))
    export=raw(struct.unpack_from('<I',dllbytes,opt+96)[0]); base,fncount,namecount,funcs,names,ordinals=struct.unpack_from('<IIIIII',dllbytes,export+16); ordinal111=[]
    for k in range(namecount):
        index=struct.unpack_from('<H',dllbytes,raw(ordinals)+k*2)[0]
        if base+index==111:
            off=raw(struct.unpack_from('<I',dllbytes,raw(names)+k*4)[0]);ordinal111.append(dllbytes[off:].split(b'\0',1)[0].decode('ascii'))
    assert ordinal111==['WSAGetLastError']
    result=dict(binary_sha256=audit.H,binary_bytes=len(audit.B),exe_sha256=hashlib.sha256(exe).hexdigest(),exe_bytes=len(exe),sections=audit.sections,imports=imports,ordinal111_resolution=dict(path=str(dllpath),sha256=hashlib.sha256(dllbytes).hexdigest(),bytes=len(dllbytes),machine=hex(struct.unpack_from('<H',dllbytes,pe+4)[0]),export_ordinal=111,names=ordinal111,scope='Independent current local x86 Windows export mapping; target PE itself imports ordinal111, not the string WSAGetLastError. Not proof of historical runtime DLL loading.'),vtable=dict(va='0xc51748',raw=hex(audit.offset(0xc51748)),bytes=audit.data(0xc51748,44).hex(' '),entries=[hex(a) for a in entries]),incorrect_raw_852d48_bytes=audit.B[0x852d48:0x852d48+44].hex(' '),api_references=['https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsasend','https://learn.microsoft.com/en-us/windows/win32/api/winsock2/nf-winsock2-wsarecv','https://learn.microsoft.com/en-us/windows/win32/api/minwinbase/ns-minwinbase-overlapped'])
    audit.save(D/'pe-data-and-imports.json',result)
    return result
def prepare():
    reports=[]; roots=set([0x4aa4d0,0x4ab8a0,0x4ac9e0,0x4acb70,0x8438c0,0x803d60,0x8060d0,0x806060,0x807470,0x8061a0,0x807a70,0x807830,0x807b40,0x8068b0,0x806850,0x806a00,0x805190,0x806ad0,0x804310,0x489920,0x807e50,0x8076f0,0x8040a0,0x74d700])
    for q in Q:
        blob=(R/q['source']).read_bytes();assert hashlib.sha256(blob).hexdigest()==q['sha256']; assert hashlib.sha1(b'blob '+str(len(blob)).encode()+b'\0'+blob).hexdigest()==q['git_blob_sha']
        lines=blob.decode('utf8').splitlines(); blocks=[];checks=[];begin=None
        for n,line in enumerate(lines,1):
            if line.startswith('```'):
                if begin is None: begin=(n,line[3:])
                else:blocks.append(dict(start=begin[0],end=n,language=begin[1]));begin=None
            m=re.match(r'\s*([0-9a-fA-F]{6,8}):\s*(.*)',line)
            if not m:continue
            va=int(m[1],16);body=m[2]
            if not body or body.startswith('...'):continue
            bytepart=re.match(r'((?:[0-9a-fA-F]{2}\s+)+)(.*)',body)
            if bytepart:
                expected=bytes.fromhex(bytepart[1]);body=bytepart[2]
                if not body:continue
                eq=audit.data(va,len(expected))==expected
            else:expected=None;eq=None
            ins=next(audit.md.disasm(audit.data(va,15),va,count=1))
            root=starts[bisect.bisect_right(starts,va)-1]; roots.add(root)
            checks.append(dict(line=n,va=hex(va),source=body,actual=f'{ins.mnemonic} {ins.op_str}',normalized_instruction_equal=normalize(body)==normalize(f'{ins.mnemonic} {ins.op_str}'),raw=hex(audit.offset(va)),bytes=ins.bytes.hex(' '),explicit_bytes_equal=eq,candidate_root=hex(root)))
        reports.append(q|dict(lines=len(lines),code_blocks=blocks,instruction_rows=checks))
    evidence={hex(a):cached(a) for a in sorted(roots) if a in I}
    for r in reports:
        for row in r['instruction_rows']:
            f=evidence[row['candidate_root']]['cfg']; row['rooted_instruction_boundary']=any(x['va']==row['va'] for x in f['instructions'])
    audit.save(D/'source-block-instruction-audit.json',dict(reports=reports))
    audit.save(D/'native-evidence.json',dict(binary_sha256=audit.H,sections=audit.sections,functions=evidence))
    print('roots',list(evidence));print('rows',[(r['number'],len(r['instruction_rows']),r['code_blocks']) for r in reports])
    for r in reports:
        for x in r['instruction_rows']:
            if not x['rooted_instruction_boundary'] or x['explicit_bytes_equal'] is False or not x['normalized_instruction_equal']:print('ISSUE',r['number'],x)
if __name__=='__main__':prepare();tables()
