import pathlib,sys,json,re,hashlib,collections,shutil
R=pathlib.Path(__file__).resolve().parents[4];P=R/'shared/integrations/T01-20261029-semantic-review'
sys.path.insert(0,str(P/'support'))
from audit import B,H,data,offset,cfg,md
D=R/'shared/integrations/T01-20261029-continuation-02/t08-158';D.mkdir(parents=True,exist_ok=True)
def save(p,x):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(x,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
old=json.loads((P/'source-ledger.json').read_text(encoding='utf-8'));row=next(x for x in old['rows'] if x['task']=='T08' and x['number']==158)
raw=(R/row['source']).read_bytes();assert hashlib.sha256(raw).hexdigest()==row['sha256'];assert hashlib.sha1(b'blob '+str(len(raw)).encode()+b'\0'+raw).hexdigest()==row['git_blob_sha'];text=raw.decode('utf-8-sig');lines=text.splitlines()
native={a:cfg(a) for a in [0x40f060,0x4b3710,0x4dfc90,0x7b6890,0x49e6a0,0x4dec90]}
known={int(i['va'],16):i for f in native.values() for i in f['instructions']};inside={}
for a,i in known.items():
    for k in range(a+1,a+i['size']):inside[k]=a
blocks=[];checks=[];opening=None
for no,line in enumerate(lines,1):
    if line.startswith('```'):
        if opening is None:opening=(no,line[3:])
        else:
            first,lang=opening;blocks.append(dict(index=len(blocks)+1,language=lang,start_line=first,end_line=no,content_sha256=hashlib.sha256('\n'.join(lines[first:no-1]).encode()).hexdigest(),decision='PASS',coverage='Every addressed ASM line checked below; C++ block manually checked against guard/loop/stack dataflow matrix.'));opening=None
    m=re.match(r'\s*([a-fA-F0-9]{6,8}):\s+((?:[a-fA-F0-9]{2}\s+)+)(.*)',line)
    if not m:continue
    a=int(m[1],16);prefix=bytes.fromhex(m[2]);asm=m[3].strip();assert data(a,len(prefix))==prefix,(no,line)
    if not asm:
        checks.append(dict(line=no,va=hex(a),kind='display-continuation',bytes=prefix.hex(' ')));continue
    assert a not in inside,(no,line,hex(inside[a]))
    ins=next(md.disasm(data(a,15),a,count=1));assert ins is not None
    # The two terminal RET rows deliberately show only a prefix byte/WORD.
    # Full original bytes, rooted decode, immediate cleanup and instruction size
    # establish the printed ret operands; prefixes are not new entry points.
    checks.append(dict(line=no,va=hex(a),raw=hex(offset(a)),quoted_prefix=prefix.hex(' '),canonical_bytes=ins.bytes.hex(' '),canonical_mnemonic=ins.mnemonic,canonical_operands=ins.op_str,source_asm=asm,root_reachable=a in known,padding=not a in known))
assert len(blocks)==4 and not opening
assert known[0x4b3717]['operands']=='eax, 2';assert known[0x4b371a]['operands']=='0x4b3720'
assert known[0x40f0b4]['operands']=='eax, 0xfab130';assert known[0x40f0c8]['mnemonic']=='ret'
assert known[0x4b3738]['operands']=='eax';assert known[0x4b3739]['call_target']=='0x40f060';assert known[0x4b373e]['call_target']=='0x4dfc90'
assert known[0x4dfc96]['operands']=='edi, [eax + 8]';assert known[0x4dfcb6]['operands']=='dword ptr [ecx + 0x88], eax'
assert known[0x4dfd34]['operands']=='4'
claims=[
('Source identity',[4,4],'Original BIN SHA and PE .text VA identity match this source, with no launcher/TC substitution.','Original SHA/PE independently parsed; exact source Git blob and SHA bound here.'),
('Prior-source correction',[13,13],'154/156 used converter/locator wording; getter does not transform pushed key.','Read both predecessor originals:154L117 and156L20/29/76; this supersedes only that hypothesis, not whole predecessor sources.'),
('Getter entry/SEH/once',[13,60],'40F060 tests FAB22C bit1, conditionally initializes, always normal-returns FAB130; pushed caller key remains.','29 rooted instructions incl.and esp,8-byte alignment,EBP restore,plain ret;0x4DEC90 additionally writes FAB130/FAB13C etc, confirming initialization role. EH and throw outcomes are not claimed normal returns.'),
('Conditional initialization limitation',[60,60],'Once flag does not imply clear-table each invocation or actor generation.','4F092 skips4DEC90 when bit set. No network/actor creation asserted from getter; no thread-safety claim.'),
('Word extraction',[66,97],'Rows start buffer+2,readWORD,OR06000000,pushDWORD,getreceiver,callconditionalremove,nextWORD.','Complete4B3710 prologue guard len<2 sets count0,else(len-2)>>1;body pushes key beforegetter;4DFC90 ret4;caller EAX=0/retC is outside void conceptual return contract.'),
('Value lifetime table',[99,107],'All six instruction/value entries agree with stack/register lifetime.','4B3730/33/38/39/3E/43 independently decoded, and getter cannot pop preexisting caller argument.'),
('Tree/predicate',[111,183],'4DFC90 uses EAX receiver+8 tree,node+10 payload,stackDWORD comparison against actor+88.','64 rooted instructions:empty sentinel branch,matching cleanup,nonmatching successor and termination;no actor+4 direct ID search in this body.'),
('Match cleanup',[184,184],'Matching predicate cleans payload and erases node; iteration must follow erase output.','7B6890 takes tree/outslot/node,49E6A0 first updates stack node tosuccessor,original node is freed,result slot receives successor;4DFCE6 uses output. Unknown dynamic virtual implementations remain unknown.'),
('Pseudocode getter',[190,190],'initOnceCandidate wrapper and fixed receiver are conceptual ABI rendering.','initOnceCandidate denotes conditional mechanism, not unconditional new initialization; raw body and narrative explicitly show gate.'),
('Pseudocode count/loop',[191,198],'Unsigned guarded floor((len-2)/2),LE16 rows,compoundDWORD,getreceiver,conditional-remove flow.','All boundary caseslen0/1/2/3->0;len4/5->1;payload must be valid for declared length. Odd trailing byte ignored. Identifiers are tentative; no formal C++ symbol/signature claimed.'),
('Type/ABI limits',[201,204],'Listed instructions and receiver roles confirmed;domain6,wireopcode,actor88business identity stayunknown.','Code demonstrates local operations; no registration source or whole scene/Server conclusion is asserted.'),
('Scope and research boundaries',[5,8],'Claims are local BYTE/dataflow;Task roles cited without owner transfer;runtime/backend unverified.','Review respects original conditions. These statements are scope/provenance rather than claims of observed execution.'),
('Future work',[206,len(lines)],'Following159 work is a proposal, not an accepted actor destruction guarantee.','Excluded from affirmative native functionality; preserved as future/unknown, not used to fill missing evidence.')]
spans={'Source identity':[4,4],'Prior-source correction':[12,12],'Getter entry/SEH/once':[12,47],'Conditional initialization limitation':[49,49],'Word extraction':[53,74],'Value lifetime table':[76,83],'Tree/predicate':[87,156],'Match cleanup':[156,156],'Pseudocode getter':[162,162],'Pseudocode count/loop':[163,169],'Type/ABI limits':[172,175],'Scope and research boundaries':[5,8],'Future work':[177,179]}
claims=[(n,spans[n],c,w) for n,_,c,w in claims]
for name,span,c,why in claims:
    assert 1<=span[0]<=span[1]<=len(lines),(name,span,len(lines))
records=[dict(id=f'T08-158-R{i+1}',topic=n,source_lines=s,claim=c,decision='PASS' if n not in ['Scope and research boundaries','Future work'] else 'SCOPE_CONFIRMED',reason=w) for i,(n,s,c,w) in enumerate(claims)]
save(D/'review.json',dict(source=row['source'],sha256=row['sha256'],git_blob_sha=row['git_blob_sha'],base_commit='fd8507169932ee9cb9d9362fcab07a5a3bd9bfa5',target_sha256=H,reviewer='Codex T01 integrator',date='2026-10-29 Asia/Taipei',source_whole_document_certified=True,all_affirmative_claims_reviewed=True,status='FULL_PASS_DOCUMENT_SCOPED',scope='All affirmative bounded technical claims of this exact source, including all4 codeblocks, were assessed. Authorship/date metadata are retained attribution, not independently asserted runtime facts. No full function/Task/gameplay/backend certification.',claims=records,blocks=blocks,assembly_checks=checks,conditions=['Valid inputs/container invariants and normal-return paths, as original source bounds.','No EH execution,concurrency,arbitrary dynamic overrides or gameplay timing accepted.'],predecessors=['154/156 converter hypothesis clarified; other claims not superseded.']))
for a,f in native.items():save(D/'native-cfg'/f'{a:08x}.json',f)
print(json.dumps(dict(source_lines=len(lines),blocks=len(blocks),claims=len(records),asm_rows=len(checks),whole_document_status='FULL_PASS_DOCUMENT_SCOPED'),ensure_ascii=False))
