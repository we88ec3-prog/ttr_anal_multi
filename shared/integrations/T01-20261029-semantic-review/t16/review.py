import sys,pathlib,json,re,hashlib,collections
W=pathlib.Path(__file__).resolve().parents[1]/'support'
sys.path.insert(0,str(W))
import audit
R=audit.R;D=pathlib.Path(__file__).resolve().parent
Q=[x for x in json.loads((W/'review-queue.json').read_text(encoding='utf8'))['rows'] if x['task']=='T16']
def instruction_audit():
    result=[]
    for x in Q:
        text=(R/x['source']).read_text(encoding='utf8');checks=[]
        for no,line in enumerate(text.splitlines(),1):
            m=re.match(r'\s*(?:0x)?([0-9a-fA-F]{6,8}):?\s+(?:\t?)([0-9a-fA-F]{2}(?:\s+[0-9a-fA-F]{2})*)\s+\t?([a-z][a-z0-9]+)(?:\s+(.*))?$',line)
            if not m or re.fullmatch('[0-9a-f]{2}',m[3]):continue
            va=int(m[1],16);expected=bytes.fromhex(m[2]);actual=audit.data(va,len(expected));ins=next(audit.md.disasm(audit.data(va,15),va,count=1),None)
            checks.append(dict(line=no,va=hex(va),expected=m[2],actual=actual.hex(' '),bytes_equal=expected==actual,source_mnemonic=m[3],decoded_mnemonic=ins.mnemonic if ins else None,decoded_operands=ins.op_str if ins else None,source_line=line))
        result.append(dict(source=x['source'],sha256=x['sha256'],git_blob_sha=x['git_blob_sha'],checks=checks,byte_mismatch_count=sum(not c['bytes_equal'] for c in checks),semantic_verdict='NOT_IMPLIED_BY_BYTE_CHECKS'))
    audit.save(D/'instruction-source-audit.json',dict(binary_sha256=audit.H,sections=audit.sections,reports=result))
    print('asm rows',sum(len(x['checks']) for x in result),'mismatches',sum(x['byte_mismatch_count'] for x in result))
    for x in result:
        if x['byte_mismatch_count']:print(x['source'],x['byte_mismatch_count'])
def cfg_audit():
    import bisect
    P=pathlib.Path('E:/Tartaros/workspace/anal-multi/kr-bulk-roy')/audit.H
    idx={int(x['address'],16):x for x in map(json.loads,(P/'index.jsonl').read_text(encoding='utf8').splitlines())}
    starts=sorted(idx)
    checks=json.loads((D/'instruction-source-audit.json').read_text(encoding='utf8'))['reports']
    roots=set()
    for report in checks:
        for row in report['checks']:
            va=int(row['va'],16);i=bisect.bisect_right(starts,va)-1
            if i>=0:roots.add(starts[i])
    evidence=[]
    for root in sorted(roots):
        row=idx[root]
        if row.get('status')!='ok':continue
        cfg=audit.cfg(root)
        raw=P/row['batch_path'] if 'batch_path' in row else P.parent.parent/row['seed_evidence']
        assert hashlib.sha256(raw.read_bytes()).hexdigest()==row.get('batch_sha256',row.get('seed_evidence_sha256'))
        pseudo=P/row['pseudocode_path'];assert hashlib.sha256(pseudo.read_bytes()).hexdigest()==row['pseudocode_sha256']
        evidence.append(dict(index=row,recursive_cfg=cfg,pseudocode=pseudo.read_text(encoding='utf8')))
    audit.save(D/'native-functions.json',dict(binary_sha256=audit.H,source_identity=json.loads((W/'identity.json').read_text()),functions=evidence,limits='Function-root index used as candidate navigation, not acceptance. Pseudocode reviewed against recursive raw CFG. No target execution.'))
    print('source-related candidate functions',len(evidence),'instructions',sum(len(x['recursive_cfg']['instructions']) for x in evidence))
    overlaps=[]
    containing={}
    for f in evidence:
        for row in f['recursive_cfg']['instructions']:
            va=int(row['va'],16)
            for a in range(va+1,va+row['size']):containing[a]=row
    for report in checks:
        bad=[]
        for row in report['checks']:
            va=int(row['va'],16)
            if va in containing:bad.append(dict(source_line=row['line'],claimed_va=row['va'],containing_instruction=containing[va]))
        if bad:overlaps.append(dict(source=report['source'],interior_instruction_rows=bad))
    audit.save(D/'instruction-boundary-candidates.json',overlaps)
    for row in overlaps:print(row['source'],len(row['interior_instruction_rows']))
if __name__=='__main__':
    if sys.argv[1:]==['audit']:instruction_audit()
    elif sys.argv[1:]==['cfg']:cfg_audit()
    elif len(sys.argv)==1:
        for x in Q:print(x['number'],x['bytes'],x['source'])
    else:
        lo,hi=map(int,sys.argv[1:3])
        for x in Q:
            if lo<=x['number']<=hi:
                text=(R/x['source']).read_text(encoding='utf8')
                text=re.sub(r'```(?:asm|text|bash|sh).*?```','[assembly/tool appendix omitted here; audited separately]',text,flags=re.S)
                print('\nSOURCE',x['source'],'BLOB',x['git_blob_sha'],'\n',text)
