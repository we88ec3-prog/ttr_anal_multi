"""Read-only source inventory. Writes only beneath the caller's new output root."""
import argparse, collections, hashlib, json, pathlib, time
TARGETS={'kr':'9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91','tc':'f181071094286fe4e72cb12863edbe7e83f8fa825cfb65604143cb53ae2cd873'}
def sha(path):
    h=hashlib.sha256()
    with open(path,'rb') as f:
        for b in iter(lambda:f.read(4*1024*1024),b''): h.update(b)
    return h.hexdigest()
def run(source,out):
    source=source.resolve(); out=out.resolve()
    assert not out.is_relative_to(source)
    out.mkdir(parents=True,exist_ok=True)
    if (out/'source-inventory.jsonl').exists() or (out/'source-inventory.complete.jsonl.gz').exists():
        raise RuntimeError('Existing partial/full inventory preserved. Do not restart or truncate. Implement incremental resume using CHECKPOINT.json before continuing.')
    files=sorted(p for p in source.rglob('*') if p.is_file())
    total=0; counts=collections.Counter(); started=time.time()
    with (out/'source-inventory.jsonl').open('w',encoding='utf-8') as dst:
        for i,p in enumerate(files):
            st=p.stat(); h=hashlib.sha256(); seen=set(); tail=b''
            with p.open('rb') as f:
                for chunk in iter(lambda:f.read(4*1024*1024),b''):
                    h.update(chunk); buf=tail+chunk
                    for ver,digest in TARGETS.items():
                        if digest.encode() in buf.lower(): seen.add(ver)
                    tail=buf[-128:]
            end=p.stat()
            if (st.st_size,st.st_mtime_ns)!=(end.st_size,end.st_mtime_ns): raise RuntimeError('Source changed: '+str(p))
            # A hash mention is a discovery hint, NOT an identity proof for every assertion.
            group='reference-'+next(iter(seen)) if len(seen)==1 else 'mixed-references' if seen else 'unclassified'
            r={'path':p.relative_to(source).as_posix(),'bytes':st.st_size,'sha256':h.hexdigest(),'mtime_ns':st.st_mtime_ns,'identity_hash_mentions':sorted(seen),'classification':group,'classification_authority':'content-reference-only; selected sources require separate provenance review','default_action':'exclude-unless-selected','exclusion_reason':'Not required by selected handoff scope; original retained'}
            dst.write(json.dumps(r,ensure_ascii=False)+'\n'); total+=st.st_size; counts[group]+=1
            if i%10000==0: print(json.dumps({'scanned':i,'total':len(files),'GiB':round(total/2**30,3)}),flush=True)
    summary={'source_files':len(files),'source_bytes':total,'classification_counts':dict(counts),'seconds':time.time()-started,'target_hashes':TARGETS,'original_source_root':str(source),'source_modification_policy':'read only; original hashes are in source-inventory.jsonl'}
    (out/'inventory-summary.json').write_text(json.dumps(summary,ensure_ascii=False,indent=2),encoding='utf-8')
    print(json.dumps(summary),flush=True)
if __name__=='__main__':
    ap=argparse.ArgumentParser();ap.add_argument('source',type=pathlib.Path);ap.add_argument('output',type=pathlib.Path);a=ap.parse_args();run(a.source,a.output)
