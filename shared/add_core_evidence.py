import hashlib,json,pathlib,sqlite3
from refine_delivery import ROOT,SRC,dump
def main():
    c=json.loads((ROOT/'shared/catalog.json').read_text(encoding='utf-8'));amap={a['id']:a for a in c['artifacts']};srcmap={p:a['id'] for a in c['artifacts'] for p in a['original_sources']};added=[]
    def add(rel,task,basis,proof=None):
        raw=(SRC/rel).read_bytes();h=hashlib.sha256(raw).hexdigest()
        if h not in amap:
            path=f'kr/evidence/{h}.txt';(ROOT/path).write_bytes(raw)
            a={'id':h,'path':path,'sha256':h,'bytes':len(raw),'original_sources':[rel],'version':'kr','roles':['selected-core-evidence'],'identity_basis':basis,'attributions':[{'source':rel,'version':'kr','identity_basis':basis}],'identity_evidence_ids':[proof] if proof else []};c['artifacts'].append(a);amap[h]=a;added.append(h)
        srcmap[rel]=h
        t=next(t for t in c['tasks'] if t['version']=='kr' and t['id']==task)
        t['evidence_ids']=sorted(set(t['evidence_ids']+[h]+([proof] if proof else [])))
        return h
    groups=[('T08','lb-create-object-abi-audit.json'),('T08','script-object-lifecycle-audit.json'),('T09','script-object-motion-audit.json'),('T09','position-update-reset-audit.json')]
    known={e['id'] for e in c['entities']}
    for task,name in groups:
        rel='native-index/'+name;d=json.loads((SRC/rel).read_text(encoding='utf-8'));assert d['sha256']==c['targets']['kr']['sha256'];proof=add(rel,task,'Explicit original KR SHA in historical audit')
        for f in d['functions']:
            fid=add('native-index/'+f['name']+'.txt',task,'Historical generator association via functions[].name; newly hashed copy, not a rerun of semantic checks',proof)
            va=int(f['start'],16);key=c['targets']['kr']['sha256']+':Tartaros.bin:'+hex(va-0x400000)
            if key not in known:
                c['entities'].append({'id':key,'version':'kr','module':'Tartaros.bin','source_sha256':c['targets']['kr']['sha256'],'va':hex(va),'rva':hex(va-0x400000),'primary_task':task,'person_owner':None,'kind':'retained-bounded-method','ranges':[{'start':f['start'],'end_exclusive':f['endExclusive']}],'evidence_ids':[proof,fid],'boundary_status':'historical bounded audit; not rerun'});known.add(key)
    stage='kr-frame-dispatch-20261023/';identity=json.loads((SRC/stage/'identity.json').read_text(encoding='utf-8'));assert identity['source_sha256']==c['targets']['kr']['sha256'];proof=add(stage+'identity.json','T09','Exact KR source SHA plus per-evidence SHA manifest')
    for suffix in ('native/mcp-evidence/03-function-490fe0.json','native/mcp-evidence/04-function-4e0060.json'):
        row=next(r for r in identity['evidence'] if r['file'].replace('\\','/')==suffix)
        assert hashlib.sha256((SRC/stage/suffix).read_bytes()).hexdigest()==row['sha256']
        add(stage+suffix,'T09','Exact file SHA matches KR identity manifest; native stage still pending closeout validation',proof)
    add(stage+'instruction-evidence.json','T09','Historical instruction excerpts from same stage; full control-flow evidence also included',proof)
    for r in c['reference_status']:
        if r.get('source_path') in srcmap:r['target_artifact']=srcmap[r['source_path']];r['status']='packaged'
    # Retained Evidence IDs can now resolve to the exact files just added.
    import re
    for aid in added:
        a=amap[aid]
        if '/mcp-evidence/' not in a['original_sources'][0]:continue
        ids=re.findall(r'ev_[0-9a-f]{64}',(ROOT/a['path']).read_text(encoding='utf-8')[:32768])
        if ids:
            for r in c['reference_status']:
                if r['reference']==ids[0]:r['target_artifact']=aid;r['status']='packaged'
    for t in c['tasks']:
        t['unresolved_dependencies']=[r for r in c['reference_status'] if r['from_artifact'] in t['evidence_ids'] and r['status']!='packaged'];t['archival_reference_count']=len(t['unresolved_dependencies'])
        p=ROOT/t['version']/'tasks'/t['id'];dump(p/'task.json',t)
        if t['version']=='kr' and t['id'] in ('T08','T09'):
            with (p/'README.md').open('a',encoding='utf-8') as f:
                f.write('\n## 本輪補入的直接證據\n\n')
                for aid in added:
                    if aid in t['evidence_ids']:f.write(f'- [{amap[aid]["original_sources"][0]}](../../../{amap[aid]["path"]})\n')
    dump(ROOT/'shared/catalog.json',c)
    db=ROOT/'shared/catalog.sqlite';db.unlink();con=sqlite3.connect(db)
    for table in ('artifacts','tasks','claims','entities','corrections'):
        con.execute(f'create table {table}(id text,version text,task text,record text)')
        for r in c[table]:con.execute(f'insert into {table} values(?,?,?,?)',(r['id'],r.get('version'),r.get('task',r.get('primary_task')),json.dumps(r,ensure_ascii=False)))
    con.commit();con.close();dump(ROOT/'validation/core-evidence-additions.json',{'added_ids':added,'count':len(added),'native_semantics_revalidated':False});print(json.dumps({'added':len(added),'entities':len(c['entities'])}))
if __name__=='__main__':main()
