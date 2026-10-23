"""Incremental, journaled inventory; existing anal is read only."""
import collections,concurrent.futures,gzip,hashlib,json,pathlib,time
from inventory import TARGETS
ROOT=pathlib.Path(__file__).resolve().parent.parent
SRC=ROOT.parent/'anal'
OUT=ROOT/'shared/manifests'
def scan(item):
    p,st=item;h=hashlib.sha256();seen=set();tail=b''
    with p.open('rb') as f:
        for b in iter(lambda:f.read(4*1024*1024),b''):
            h.update(b);buf=(tail+b).lower()
            for v,d in TARGETS.items():
                if d.encode() in buf:seen.add(v)
            tail=b[-128:]
    end=p.stat()
    if (end.st_size,end.st_mtime_ns)!=(st.st_size,st.st_mtime_ns):raise RuntimeError('Source changed '+str(p))
    return {'path':p.relative_to(SRC).as_posix(),'bytes':st.st_size,'mtime_ns':st.st_mtime_ns,'sha256':h.hexdigest(),'identity_hash_mentions':sorted(seen),'classification':'reference-'+next(iter(seen)) if len(seen)==1 else 'mixed-references' if seen else 'unclassified','classification_authority':'hash mention only; not proof of every assertion','default_action':'exclude-unless-selected','exclusion_reason':'Outside selected handoff scope; original retained'}
def main():
    old={};start=time.time()
    complete=OUT/'source-inventory.complete.jsonl.gz'
    if complete.exists():
        with gzip.open(complete,'rt',encoding='utf-8') as f:
            for line in f:r=json.loads(line);old[r['path']]=r
    for name in ('source-inventory.jsonl','inventory-resume-journal.jsonl'):
        p=OUT/name
        if p.exists():
            for line in p.open(encoding='utf-8'):
                r=json.loads(line);old[r['path']]=r
    for r in json.loads((OUT/'selection-plan.json').read_text(encoding='utf-8'))['entries']:
        old.setdefault(r['path'],{k:v for k,v in r.items() if k not in ('tasks','roles','via','version','identity_basis','action')})
    current={};pending=[];reused=0
    for p in SRC.rglob('*'):
        if not p.is_file():continue
        st=p.stat();rel=p.relative_to(SRC).as_posix();prior=old.get(rel)
        if prior and (prior['bytes'],prior['mtime_ns'])==(st.st_size,st.st_mtime_ns):current[rel]=prior;reused+=1
        else:pending.append((p,st))
    print(json.dumps({'reused':reused,'pending':len(pending),'pending_GiB':sum(s.st_size for p,s in pending)/2**30}),flush=True)
    with (OUT/'inventory-resume-journal.jsonl').open('a',encoding='utf-8') as dst,concurrent.futures.ThreadPoolExecutor(max_workers=4) as pool:
        for i,r in enumerate(pool.map(scan,pending)):
            current[r['path']]=r;dst.write(json.dumps(r,ensure_ascii=False)+'\n')
            if i%500==0:dst.flush();print(json.dumps({'new_hashed':i+1,'pending':len(pending),'seconds':round(time.time()-start)}),flush=True)
    with gzip.open(OUT/'source-inventory.complete.jsonl.gz','wt',encoding='utf-8') as dst:
        for rel in sorted(current):dst.write(json.dumps(current[rel],ensure_ascii=False)+'\n')
    result={'complete':True,'source_files':len(current),'source_bytes':sum(r['bytes'] for r in current.values()),'reused_unchanged_size_mtime':reused,'new_hashes':len(pending),'classification_counts':dict(collections.Counter(r['classification'] for r in current.values())),'seconds':time.time()-start,'limits':['Reused hashes require unchanged size and mtime; metadata equality is not adversarial tamper proof.','Content hash mention does not establish semantics or version of all assertions.'],'manifest':'source-inventory.complete.jsonl.gz'}
    (OUT/'inventory-summary.json').write_text(json.dumps(result,ensure_ascii=False,indent=2),encoding='utf-8');print(json.dumps(result),flush=True)
if __name__=='__main__':main()
