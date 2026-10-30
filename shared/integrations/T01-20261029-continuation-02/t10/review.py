"""Read-only full-source/code-block audit for the three frozen T10 drafts.

No target execution; Capstone decodes original file bytes. Native instruction
boundaries are rooted in identified entries, not in arbitrary quote starts.
"""
import pathlib,sys,re,json,hashlib,struct,collections
D=pathlib.Path(__file__).resolve().parent
S=D.parents[1]/'T01-20261029-semantic-review'/'support'
sys.path.insert(0,str(S))
from audit import R,B,H,data,offset,cfg,save,sections,md
BASE='fd8507169932ee9cb9d9362fcab07a5a3bd9bfa5'
SOURCE_SHA256={53:'e527d144471dfa118f90b3d99c2134242d5335521a933c1757259268ecfe0089',55:'3b3a2dcf12540643499faa3f00770b61e9e74669fe6048744f0313503280f84a',56:'0d0b9f07373355c959291cb9ac8fddc5ad840b05167e5222b9001f8626f549a5'}
ENTRIES=[0x548730,0x6d0750,0x6d08c0,0x6d1a70,0x6d4a30,0x6d4ce0,0x6d4dc0,0x5961c0,0x82ef00]
graphs={a:cfg(a) for a in ENTRIES}
for a,g in graphs.items():
    assert not g['overlaps'],hex(a)
    save(D/'cfg'/f'{a:08x}.json',g)
native={int(i['va'],16):{**i,'entry':hex(a)} for a,g in graphs.items() for i in g['instructions']}
cover={p:i for a,i in native.items() for p in range(a,a+i['size'])}
target_section=next(s for s in sections if s['name']=='.text')
textbytes=B[target_section['raw']:target_section['raw']+target_section['raw_size']]
literal=[];idx=0
while (idx:=textbytes.find(struct.pack('<I',0xfb9004),idx))>=0:
    literal.append(dict(raw=hex(target_section['raw']+idx),va=hex(target_section['va']+idx)));idx+=1
assert len(literal)==7
calls=[]
for i in range(len(textbytes)-4):
    if textbytes[i]==0xe8 and target_section['va']+i+5+struct.unpack_from('<i',textbytes,i+1)[0]==0x6d4ce0:calls.append(hex(target_section['va']+i))
assert calls==['0x59624e','0x59643f']
cache=pathlib.Path('E:/Tartaros/workspace/anal-multi/kr-bulk-roy')/H
cache_rows=[]
for l in (cache/'index.jsonl').open(encoding='utf-8'):
    q=json.loads(l)
    if q.get('status')=='ok' and int(q['address'],16) in ENTRIES:
        assert q['source_sha256']==H
        for pk,hk in [('pseudocode_path','pseudocode_sha256'),('batch_path','batch_sha256')]:
            if pk in q:assert hashlib.sha256((cache/q[pk]).read_bytes()).hexdigest()==q[hk]
        cache_rows.append(q)
save(D/'cached-evidence-index.json',dict(binary_sha256=H,cache_root=str(cache),rows=cache_rows,notes='Existing Ghidra outputs verified by hash; used as entry/pseudocode cross-reference, not automatic semantics. 6D08C0 is a statically passed callback pointer in6D0750, not a claimed new cache entry.'))
results=[]
def norm_asm(s):
    s=s.lower().strip()
    s=re.sub(r'\b(?:byte|word|dword|qword)\s+ptr\s*','',s)
    s=re.sub(r'\b(ds|fs|gs|cs|ss|es):(0x[0-9a-f]+)',r'\1:[\2]',s)
    s=s.replace('ds:','')
    s=re.sub(r'0x[0-9a-f]+',lambda m:str(int(m[0],16)),s)
    s=s.replace('+0x0','').replace('+0] ','] ')
    s=s.replace('+0]',']')
    return re.sub(r'\s+','',s)
for n in [53,55,56]:
    p=next((R/'kr-temp-roy').glob(f'*-T10-{n:03d}-*.md'))
    raw=p.read_bytes();assert hashlib.sha256(raw).hexdigest()==SOURCE_SHA256[n],('Frozen source changed',str(p))
    t=raw.decode('utf-8-sig');lines=t.splitlines();blocks=[];ranges=[]
    for k,m in enumerate(re.finditer(r'```([^\n]*)\n(.*?)```',t,re.S),1):
        first=t[:m.start()].count('\n')+1;last=t[:m.end()].count('\n')+1
        header=next((z for z in reversed(lines[:first-1]) if z.startswith('### VA ')),None)
        h=re.search(r'VA `0x([0-9A-Fa-f]+)`.*raw `0x([0-9A-Fa-f]+)`.*?（(\d+) bytes）',header or '')
        assert h,(p,k,header)
        start=int(h[1],16);end=start+int(h[3]);assert offset(start)==int(h[2],16)
        r=[]
        for lineno,l in enumerate(m[2].splitlines(),first+1):
            a=re.match(r'\s*([0-9A-Fa-f]{6,8}):\s+((?:[0-9A-Fa-f]{2}(?:\s+|$))+)(.*)',l)
            if not a:continue
            va=int(a[1],16);expected=bytes.fromhex(a[2]);assert data(va,len(expected))==expected
            assert start<=va and va+len(expected)<=end,(p,k,hex(va))
            i=cover.get(va)
            if not i and all(x==0xcc for x in expected):
                i=dict(va=hex(va),raw=hex(offset(va)),bytes=expected.hex(' '),size=len(expected),mnemonic='int3',operands='',entry='unreached-padding-observation')
            if not i and (expected.hex() in ['8d9b00000000','8da42400000000','90']):
                decoded=next(md.disasm(data(va,15),va,count=1));assert decoded.size==len(expected)
                i=dict(va=hex(va),raw=hex(offset(va)),bytes=expected.hex(' '),size=decoded.size,mnemonic=decoded.mnemonic,operands=decoded.op_str,entry='unreached-alignment-encoding')
            if not i:raise AssertionError(('No canonical coverage',p,k,hex(va)))
            r.append(dict(source_line=lineno,va=hex(va),raw=hex(offset(va)),quoted_bytes=expected.hex(' '),source_asm=a[3].strip(),canonical=i,byte_equality=True))
        first_native=next((int(x['va'],16) for x in r if x['va']==x['canonical']['va']),end)
        cut_inst=next((i for i in native.values() if int(i['va'],16)<end<int(i['va'],16)+i['size']),None)
        tail_start=int(cut_inst['va'],16) if cut_inst else end
        has_explicit_truncation=any(x['source_asm'].startswith('.byte') or x['source_asm'] in ['fs','ds','es','cs','ss','gs'] for x in r if int(x['va'],16)>=tail_start)
        for x in r:
            a=int(x['va'],16);i=x['canonical'];sz=len(bytes.fromhex(x['quoted_bytes']));native_start=int(i['va'],16)
            if a<first_native:
                x['classification']='EXPLICIT_BAD_DECODER_OUTPUT_AT_MISALIGNED_HEAD' if x['source_asm']=='(bad)' else 'MISALIGNED_WINDOW_HEAD_LINEAR_DECODE'
                x['native_instruction_assertion_pass']=None if x['source_asm']=='(bad)' else False
            elif a>=tail_start and has_explicit_truncation:
                x['classification']='EXPLICIT_END_TRUNCATION_FRAGMENT'
                x['native_instruction_assertion_pass']=None
            elif not x['source_asm']:
                x['classification']='DISPLAY_BYTE_CONTINUATION'
                x['native_instruction_assertion_pass']=None
            elif a==native_start:
                if sz==i['size']:kind='CANONICAL_NATIVE_INSTRUCTION'
                else:
                    assert sz<i['size'],(p,k,hex(a),sz,i['size'])
                    kind='SPLIT_DISPLAY_INSTRUCTION_HEAD'
                x['classification']=kind;x['native_instruction_assertion_pass']=True
                x['operand_text_equivalence']=norm_asm(x['source_asm'])==norm_asm(i['mnemonic']+' '+i['operands'])
                if not x['operand_text_equivalence'] and norm_asm(x['source_asm'])=='push4294967295' and norm_asm(i['mnemonic']+' '+i['operands'])=='push-1':
                    assert i['bytes']=='6a ff'
                    x['operand_text_equivalence']=True;x['display_alias_resolution']='x86 PUSH imm8 FF sign-extends to32-bit FFFFFFFF; -1 and0xFFFFFFFF are equivalent displays.'
            else:
                raise AssertionError(('Unexpected internal misalignment',p,k,x))
        counts=dict(collections.Counter(x['classification'] for x in r))
        block=dict(index=k,source_lines=[first,last],language=m[1].strip(),heading=header,window_start=hex(start),window_end_exclusive=hex(end),window_raw=hex(offset(start)),window_bytes=int(h[3]),source_block_sha256=hashlib.sha256(m[2].encode()).hexdigest(),all_quoted_bytes_match=True,rows=r,classification_counts=counts,all_native_instruction_claims_pass=not counts.get('MISALIGNED_WINDOW_HEAD_LINEAR_DECODE'),full_block_examined=True,tail_fragments_explicitly_not_native_instructions=has_explicit_truncation)
        blocks.append(block);ranges.append([first,last])
    outside=[]
    for lineno,l in enumerate(lines,1):
        if not any(a<=lineno<=b for a,b in ranges) and l.strip():outside.append(dict(line=lineno,text=l))
    result=dict(source=p.relative_to(R).as_posix(),sha256=hashlib.sha256(raw).hexdigest(),git_blob_sha=hashlib.sha1(b'blob '+str(len(raw)).encode()+b'\0'+raw).hexdigest(),bytes=len(raw),line_count=len(lines),all_codeblocks_examined=True,blocks=blocks,non_code_lines=outside)
    results.append(result)
save(D/'source-codeblock-audit.json',dict(schema='t01-three-source-codeblock-audit-v1',base_commit=BASE,binary_sha256=H,binary_bytes=len(B),sections=sections,literal_fb9004_positions=literal,direct_E8_candidates_to_6d4ce0=calls,sources=results,method='All quoted byte rows checked. Canonical boundaries from rooted reachable CFG; padding independently recognized. Explicit .byte/prefix tail fragments never treated as native instruction failures. Every starting-window misdecode is separated from semantic core claims.'))
print(json.dumps({x['source']:dict(blocks=len(x['blocks']),rows=sum(len(b['rows']) for b in x['blocks']),categories=dict(sum((collections.Counter(b['classification_counts']) for b in x['blocks']),collections.Counter())),operand_text_mismatches=[(r['source_line'],r['source_asm'],r['canonical']['mnemonic']+' '+r['canonical']['operands']) for b in x['blocks'] for r in b['rows'] if r.get('operand_text_equivalence') is False]) for x in results},ensure_ascii=False))
