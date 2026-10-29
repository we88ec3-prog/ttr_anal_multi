from audit import *
q=json.loads((W/'review-queue.json').read_text(encoding='utf-8'))
out=R/'shared/integrations/T01-20261029-semantic-review/t08-early';out.mkdir(parents=True,exist_ok=True)
results=[]
for row in q['rows']:
    if row['task']!='T08' or row['number']>=170:continue
    t=(R/row['source']).read_text(encoding='utf-8-sig');errors=[];checks=0
    for line in t.splitlines():
        m=re.match(r'\s*(?:0x)?([0-9a-fA-F]{6,8}):?\s+((?:[0-9a-fA-F]{2}(?:\s+|$))+)',line)
        if not m:continue
        va=int(m[1],16);b=bytes.fromhex(m[2]);
        try:actual=data(va,len(b))
        except ValueError:continue
        checks+=1
        if b!=actual:errors.append(dict(line=line,va=hex(va),expected=b.hex(' '),actual=actual.hex(' ')))
    results.append(dict(source=row['source'],number=row['number'],sha256=row['sha256'],git_blob_sha=row['git_blob_sha'],byte_rows=checks,mismatches=errors))
save(out/'preflight.json',results)
print('reports',len(results),'byte rows',sum(x['byte_rows'] for x in results),'mismatches',sum(len(x['mismatches']) for x in results))
for x in results:
    if x['mismatches']:print(x['number'],len(x['mismatches']),x['mismatches'][:2])
for n in [153,155,157,158,159]:
    row=next(x for x in results if x['number']==n);t=(R/row['source']).read_text(encoding='utf-8-sig')
    (out/f'{n}-narrative.txt').write_text(re.sub(r'```[\s\S]*?```','[code block separately audited]',t),encoding='utf-8')
