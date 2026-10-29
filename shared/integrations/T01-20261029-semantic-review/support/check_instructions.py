from audit import *
D=R/'shared/integrations/T01-20261029-semantic-review/t08-early'
q=json.loads((W/'review-queue.json').read_text(encoding='utf-8'))['rows']
interesting={153:[0x4dfbc0,0x4dfc30,0x4dfc90,0x4dfd40,0x4dfe90],155:[0x7b6890,0x49e6a0],157:[0x4b28d0,0x4b3710],158:[0x40f060,0x4b3710,0x4dfc90],159:[0x4dfbc0,0x4dfc30,0x4dfd40,0x4dfe90]}
if '--geometry' in sys.argv:
    roots=[int(p.stem,16) for p in (W/'cfg').glob('*.json')]
    interesting={n:roots for n in range(101,130)}
results=[]
for n,roots in interesting.items():
    x=next(x for x in q if x['task']=='T08' and x['number']==n);t=(R/x['source']).read_text(encoding='utf-8-sig');known={};interiors={}
    for root in roots:
        c=cfg(root)
        for i in c['instructions']:
            a=int(i['va'],16);known[a]=i
            for z in range(a+1,a+i['size']):interiors[z]=a
    errors=[];valid=0
    for line in t.splitlines():
        m=re.match(r'\s*(?:0x)?([0-9a-fA-F]{6,8}):?\s+((?:[0-9a-fA-F]{2}\s+)*)(\S.*)',line)
        if not m:continue
        if re.fullmatch(r'(?:[0-9a-fA-F]{2}\s*)+',m[3]):continue
        a=int(m[1],16)
        if a in interiors:errors.append(dict(line=line,claimed=hex(a),actual_instruction=hex(interiors[a]),reason='inside rooted reachable instruction'))
        elif a in known:valid+=1
    results.append(dict(source=x['source'],git_blob_sha=x['git_blob_sha'],decoded_rows=valid,errors=errors))
save(D/('geometry-instruction-boundaries.json' if '--geometry' in sys.argv else 'actor-instruction-boundaries.json'),results);print([(x['source'].split('-T08-')[1][:3],x['decoded_rows'],x['errors']) for x in results])
