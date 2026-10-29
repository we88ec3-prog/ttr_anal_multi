"""Independent full-source/code-block evidence capture; no target execution.

Requires Capstone 5.0.6 and an independently supplied original BIN. Set
T01_CAPSTONE_ROOT and T01_TARGET as documented by the previous native reader.
"""
import pathlib,json,sys,re,hashlib,struct,collections,shutil,subprocess
D=pathlib.Path(__file__).resolve().parent;R=D.parents[3]
OLD=R/'shared/integrations/T01-20261029-semantic-review/t08-new'
sys.path.insert(0,str(OLD))
from native_reader import B,H,sections,data,offset,cfg,md,save
PATHS={177:'kr-temp-roy/20261028-094900-chatgpt-web-roy-T08-177-owner-mode-caller-drain-closure.md',197:'kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-197-secondary-tree-key-removal.md',200:'kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-200-registration-identity-and-duplicate.md'}
ROOTS={177:[0x7b7fd0,0x7b8030,0x7aad40,0x7ab020,0x7dd100,0x7dd1a0,0x7dd1f0,0x7b8090,0x7a86b0,0x7be5f0],197:[0x4dfc30,0x4dfc90],200:[0x4dff30,0x4dfbc0,0x4dfc30]}
SUPPORT=[0x7b7f30,0x7bb350,0x7bd850,0x7be0f0,0x89120c,0x7dc510,0x7dcf40,0x7b8680,0x8438c0,0x82ef00,0x82f200,0x7b6890,0x49e6a0,0x43e670,0x763f60,0x823b80,0x44bd00,0x57ef20,0x6edb60,0x6ed980,0x4dfe90,0x4c7db0,0x4c8360]
def blob(b):return hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()
def norm(s):
    s=s.lower().strip();s=re.sub(r'\b(?:byte|word|dword|qword|tbyte|xmmword)\s+ptr\s*','',s)
    s=re.sub(r'ds:(0x[0-9a-f]+)',r'[\1]',s);s=s.replace('ds:','')
    s=re.sub(r'fs:(0x[0-9a-f]+)',r'fs:[\1]',s)
    s=re.sub(r'(?<![a-z0-9_])(-?0x[0-9a-f]+|-?\d+)',lambda m:str(int(m[0],16) if '0x' in m[0] else int(m[0])),s)
    s=s.replace('+0] ','] ').replace('+0]',']').replace(' ','')
    # Push -1 and push 0xffffffff encode the same 32-bit argument.
    if s.startswith('push4294967295'):s='push-1'
    return s
def capture():
    entries=sorted(set(SUPPORT+[a for aa in ROOTS.values() for a in aa]));allcfg={a:cfg(a) for a in entries}
    for a,d in allcfg.items():save(D/'native-cfg'/f'{a:08x}.json',d)
    reports=[]
    for num,p in PATHS.items():
        b=(R/p).read_bytes();lines=b.decode('utf-8-sig').splitlines();blocks=[];opened=None;lang=None
        for k,line in enumerate(lines,1):
            if line.startswith('```'):
                if opened is None:opened=k;lang=line[3:].strip()
                else:blocks.append(dict(id=f'T08-{num}-BLOCK-{len(blocks)+1}',fence_start=opened,fence_end=k,content_start=opened+1,content_end=k-1,language=lang,content='\n'.join(lines[opened:k-1])));opened=None
        assert opened is None
        insmap={int(i['va'],16):(a,i) for a in ROOTS[num] for i in allcfg[a]['instructions']}
        for block in blocks:
            checks=[];previous=None
            if block['language']=='asm':
                for ln in range(block['content_start'],block['content_end']+1):
                    line=lines[ln-1];m=re.match(r'\s*([0-9a-fA-F]{6,8}):\s+((?:[0-9a-fA-F]{2}(?:\s+|$))+)(.*)',line)
                    if not m:continue
                    a=int(m[1],16);bs=bytes.fromhex(m[2]);quoted=m[3].strip();assert data(a,len(bs))==bs,(num,ln)
                    if not quoted:
                        kind='continuation-bytes';full=previous
                        assert full and full['address']<a<full['address']+full['size'],(num,ln)
                        canonical=full['canonical'];consistent=True
                    elif quoted.startswith('.byte'):
                        kind='explicit-raw-byte-directive';full=None;canonical=None;consistent=True
                    else:
                        i=next(md.disasm(data(a,15),a,count=1));canonical=i.mnemonic+' '+i.op_str
                        consistent=norm(quoted)==norm(canonical)
                        kind='complete-instruction' if len(bs)==i.size else 'byte-truncated-instruction-window'
                        if len(bs)>i.size:kind='unexpected-multiinstruction-span'
                        full=dict(address=a,size=i.size,canonical=canonical)
                        previous=full
                    qw=re.findall(r'\b(byte|word|dword|qword|tbyte|xmmword)\s+ptr',quoted.lower())
                    nw=re.findall(r'\b(byte|word|dword|qword|tbyte|xmmword)\s+ptr',(canonical or '').lower())
                    widths_match=not qw or qw==nw
                    checks.append(dict(line=ln,va=hex(a),raw=hex(offset(a)),quoted_bytes=bs.hex(' '),actual_bytes=data(a,len(bs)).hex(' '),quoted_assembly=quoted,full_native_instruction=canonical,kind=kind,normalized_assembly_matches=consistent,explicit_operand_width_matches=widths_match,entry_root=hex(insmap[a][0]) if a in insmap else None,boundary_scope='reachable-from-listed-root' if a in insmap else 'explicit-raw-window-or-padding; not assumed callable'))
                block['instruction_rows']=checks
                block['mechanical_status']='MATCH' if all(c['normalized_assembly_matches'] and c['explicit_operand_width_matches'] for c in checks) else 'MANUAL_REVIEW_REQUIRED'
            block['content_sha256']=hashlib.sha256(block['content'].encode()).hexdigest()
        row=dict(number=num,source=p,source_sha256=hashlib.sha256(b).hexdigest(),git_blob_sha=blob(b),bytes=len(b),line_count=len(lines),blocks=blocks)
        save(D/'sources'/f'T08-{num}-line-index.json',dict(**{k:v for k,v in row.items() if k!='blocks'},lines=[dict(line=k,text=t) for k,t in enumerate(lines,1)]))
        reports.append(row)
    save(D/'code-block-audit.json',dict(target_sha256=H,reports=reports,limitation='Mechanical byte/operand consistency does not decide semantic claims; see claim matrices and manual judgments.'))
    save(D/'target.json',dict(path='Original KR Tartaros.bin separately supplied',sha256=H,bytes=len(B),sections=sections,decoder='Capstone 5.0.6; no target execution',roots={str(n):list(map(hex,aa)) for n,aa in ROOTS.items()}))
    # Preserve the prior exact index metadata as independent entry provenance;
    # new functions are bound below from the immutable acquisition index.
    corpus=pathlib.Path('E:/Tartaros/workspace/anal-multi/kr-bulk-roy')/H
    idx={int(r['address'],16):r for r in map(json.loads,(corpus/'index.jsonl').open(encoding='utf-8')) if r.get('status')=='ok'}
    refs=[]
    for a in entries:
        r=idx.get(a);assert r,hex(a);refs.append(dict(entry=hex(a),cached_index_record=r))
    save(D/'entry-provenance.json',dict(target_sha256=H,functions=refs))
    raw=next(s for s in sections if s['name']=='.text');cs=collections.defaultdict(list);bb=B[raw['raw']:raw['raw']+raw['virtual_size']]
    for k in range(len(bb)-4):
        if bb[k]==0xe8:
            site=raw['va']+k;target=site+5+struct.unpack_from('<i',bb,k+1)[0];cs[target].append(dict(site=hex(site),bytes=bb[k:k+5].hex(' ')))
    targets=[0x7b7fd0,0x7b8030,0x7dd100,0x7dd1a0,0x7dd1f0,0x7be5f0,0x4dff30,0x4dfbc0,0x4dfe90]
    save(D/'direct-e8-candidates.json',dict(target_sha256=H,targets=[dict(target=hex(a),count=len(cs[a]),sites=cs[a]) for a in targets],limitation='Raw byte candidates; indirect and external callers excluded.'))
    pe=struct.unpack_from('<I',B,0x3c)[0];opt=pe+24;irva=struct.unpack_from('<I',B,opt+104)[0];p=offset(0x400000+irva);imports=[]
    def cstr(a):o=offset(a);return B[o:B.index(0,o)].decode('ascii')
    while any(B[p:p+20]):
        original,_,_,name,first=struct.unpack_from('<IIIII',B,p);p+=20;dll=cstr(0x400000+name);q=offset(0x400000+(original or first));k=0
        while True:
            v=struct.unpack_from('<I',B,q+k*4)[0]
            if not v:break
            imports.append(dict(iat=hex(0x400000+first+k*4),dll=dll,name='#'+str(v&0xffff) if v&0x80000000 else cstr(0x400000+v+2)));k+=1
    save(D/'imports.json',dict(target_sha256=H,imports=imports))
    strings=[]
    for a in [0xc0cef0,0xc4209c]:
        o=offset(a);bs=B[o:B.index(0,o)];strings.append(dict(va=hex(a),raw=hex(o),bytes=bs.hex(' '),text_cp949=bs.decode('cp949',errors='replace'),encoding_status='decoding view; not a source-language identity proof'))
    save(D/'diagnostic-strings.json',dict(target_sha256=H,strings=strings))
    save(D/'frozen-sources.json',dict(base_commit=subprocess.check_output(['git','rev-parse','HEAD'],cwd=R,text=True).strip(),target_sha256=H,sources=[dict(number=r['number'],path=r['source'],sha256=r['source_sha256'],git_blob_sha=r['git_blob_sha'],git_verified_blob=subprocess.check_output(['git','rev-parse','HEAD:'+r['source']],cwd=R,text=True).strip()) for r in reports]))
    for r in reports:
        checks=[c for b in r['blocks'] for c in b.get('instruction_rows',[])];mismatch=[c for c in checks if not c['normalized_assembly_matches']]
        print('T08',r['number'],'blocks',len(r['blocks']),'asmrows',len(checks),'mismatches',[(c['line'],c['quoted_assembly'],c['full_native_instruction']) for c in mismatch])
if __name__=='__main__':capture()
