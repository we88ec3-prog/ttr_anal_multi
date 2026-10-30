"""Read-only source/byte preflight. Does not produce semantic FULL_PASS."""
import sys,pathlib,re,json,hashlib,collections
sys.path.insert(0,str(pathlib.Path(__file__).resolve().parents[1]/'support'))
from audit import R,W,B,H,data,md,save,sections
D=pathlib.Path(__file__).resolve().parent
Q=json.loads((W/'review-queue.json').read_text(encoding='utf-8'))
rows=[]
for q in Q['rows']:
    if q['task']!='T10':continue
    p=R/q['source'];raw=p.read_bytes();assert hashlib.sha256(raw).hexdigest()==q['sha256']
    text=raw.decode('utf-8-sig');checks=[]
    for n,line in enumerate(text.splitlines(),1):
        m=re.match(r'\s*([0-9a-fA-F]{6,8}):\s+((?:[0-9a-fA-F]{2}(?:\s+|$))+)(.*)',line)
        if not m:continue
        a=int(m[1],16);h=' '.join(m[2].split());expected=bytes.fromhex(h)
        try:actual=data(a,len(expected));ins=next(md.disasm(data(a,15),a,count=1),None)
        except ValueError:actual=b'';ins=None
        checks.append(dict(line=n,va=hex(a),expected=h,actual=actual.hex(' '),bytes_match=actual==expected,source_asm=m[3].strip(),decoded=(ins.mnemonic+' '+ins.op_str) if ins else None,decoded_size=ins.size if ins else None,partial_instruction=bool(ins and len(expected)<ins.size)))
    narrative=re.sub(r'```[^\n]*\n.*?```','[code block separately checked in preflight]',text,flags=re.S)
    row={**q,'asm_checks':checks,'byte_mismatch_count':sum(not c['bytes_match'] for c in checks),'narrative_lines':len(narrative.splitlines()),'current_verdict':'PENDING_SEMANTIC_REVIEW','all_affirmative_claims_reviewed':False}
    rows.append(row)
    (D/'narratives').mkdir(exist_ok=True)
    (D/'narratives'/p.name).write_text(narrative,encoding='utf-8')
save(D/'preflight.json',dict(source_binary_sha256=H,source_binary_bytes=len(B),sections=sections,scope='Every quoted address/byte row in all 98 T10 drafts; no automatic semantic promotion',rows=rows))
print(json.dumps({'reports':len(rows),'asm_rows':sum(len(x['asm_checks']) for x in rows),'reports_with_mismatch':[(x['number'],x['source'],x['byte_mismatch_count']) for x in rows if x['byte_mismatch_count']],'total_narrative_chars':sum((D/'narratives'/pathlib.Path(x['source']).name).stat().st_size for x in rows)},ensure_ascii=False))
