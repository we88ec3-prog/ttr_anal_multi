#!/usr/bin/env python3
"""Read-only authored input/schema/dependency/BND analysis.

This is a static projection of cited Server contracts, not the actual typed
Server loader, not an event/tick simulator and not gameplay acceptance.
"""
import argparse
from collections import Counter, defaultdict, deque
import hashlib
import importlib.util
import json
from pathlib import Path
import subprocess
import sys
import xml.etree.ElementTree as ET

from jsonschema import Draft202012Validator

HERE = Path(__file__).resolve().parent
DEFAULT_REPO = HERE.parents[2]
sys.dont_write_bytecode = True


def require(ok, message):
    if not ok: raise ValueError(message)


def sha(data): return hashlib.sha256(data).hexdigest()


def load_module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    return module


def json_file(path): return json.loads(path.read_text(encoding='utf-8'))


def verify_sources(repo, originals, server_sources):
    manifest = json_file(HERE / 'source-manifest.json')
    for row in manifest['git_sources']:
        data = subprocess.check_output(['git','show',row['commit']+':'+row['path']],cwd=repo)
        require(len(data)==row['bytes'] and sha(data)==row['sha256'], 'Git source '+row['path'])
        require(hashlib.sha1(b'blob '+str(len(data)).encode()+b'\0'+data).hexdigest()==row['git_blob'], 'Git blob '+row['path'])
        if row['live_input']:
            require((repo/row['path']).read_bytes()==data, 'live input drift '+row['path'])
    for row in manifest['originals']:
        data=(originals/row['file']).read_bytes()
        require(len(data)==row['bytes'] and sha(data)==row['sha256'], 'original '+row['file'])
    external = json_file(HERE/'server-code-evidence.json')
    for row in external['sources']:
        data=(server_sources/row['path']).read_bytes()
        require(len(data)==row['bytes'] and sha(data)==row['sha256'], 'Server source '+row['path'])
        require(hashlib.sha1(b'blob '+str(len(data)).encode()+b'\0'+data).hexdigest()==row['git_blob'], 'Server blob '+row['path'])
    for span in external['spans']:
        data=(server_sources/span['path']).read_bytes()
        part=data[span['byte_offset']:span['byte_offset']+span['bytes']]
        require(sha(part)==span['sha256'], 'Server bounded span '+span['id'])
        require(part==b''.join(data.splitlines(keepends=True)[span['first_line']-1:span['last_line']]), 'Server line/byte mapping '+span['id'])
    return {'git_sources':len(manifest['git_sources']),'originals':len(manifest['originals']),
            'server_sources':len(external['sources']),'server_spans':len(external['spans'])}


def exits(node):
    r=next(r for r in node['rules'] if r['event']=='InteractZ')
    return [{'portal':node['portal'],'action':r['action'],'targetNode':r.get('targetNode')}] + node.get('alternativeExits',[])


def flags(value): return set((value or {}).get('requiredFlags',[]))


def dependency_projection(definition):
    nodes={n['node']:n for n in definition['nodes']}
    require(len(nodes)==len(definition['nodes']), 'duplicate node')
    require(len({n['encounterGroup'] for n in nodes.values()})==len(nodes), 'duplicate group')
    all_signals=[s for n in nodes.values() for s in n.get('signals',[])]
    by_flag={s['flag']:s for s in all_signals}
    require(len(by_flag)==len(all_signals)<=64, 'unique bounded flag producers')
    incoming=defaultdict(list); graph=defaultdict(list); degrees={i:0 for i in nodes}
    for nid,n in nodes.items():
        require(Counter(r['event'] for r in n['rules'])==Counter({'Entry':1,'GroupCleared':1,'InteractZ':1}), 'event spine')
        rules={r['event']:r for r in n['rules']}
        require(rules['Entry']['action']=='SpawnGroup' and rules['GroupCleared']['action']=='UnlockPortal','event action spine')
        keys=[x['portal']['key'] for x in exits(n)]
        require(len(keys)==len(set(keys)), 'unique portal keys')
        for e in exits(n):
            require(e['action'] in ('NextNode','Result'),'exit action')
            require((e.get('targetNode') is not None)==(e['action']=='NextNode'),'exit target consistency')
            if e['action']=='NextNode':
                t=e['targetNode'];require(t in nodes,'missing target');graph[nid].append(t);degrees[t]+=1
                incoming[t].append((nid,e))
    q=deque(i for i in nodes if degrees[i]==0); order=[]
    while q:
        i=q.popleft();order.append(i)
        for t in graph[i]:
            degrees[t]-=1
            if degrees[t]==0:q.append(t)
    require(len(order)==len(nodes),'cyclic graph')
    seen=set(); q=deque([definition['entryNode']])
    while q:
        i=q.popleft()
        if i in seen:continue
        seen.add(i);q.extend(graph[i])
    require(seen==set(nodes),'unreachable node')
    after_edges={}; out=[]
    for nid in order:
        n=nodes[nid]; rows=n.get('signals',[])
        seq=n.get('reinforcements',[]); timed=n.get('timedReinforcements',[]); waves=seq+timed
        require(bool(n['encounters']) or bool(waves),'node must have an eventual encounter')
        ids=[w['id'] for w in waves]
        require(len(ids)==len(set(ids))<=31,'wave identities/capacity')
        require(len(n['encounters'])+sum(len(w['encounters']) for w in waves)<=255,'actor capacity')
        boss=n.get('requiredBoss'); boss_wave=None
        if boss:
            matches=[]
            for wid,actors in [(None,n['encounters'])]+[(w['id'],w['encounters']) for w in waves]:
                matches += [wid for a in actors if a['model']==boss['model'] and a.get('pre',1)==boss['pre']
                            and (boss.get('waveId') is None or boss['waveId']==wid)]
            require(len(matches)==1,'requiredBoss must match exactly one actor across selected scope')
            boss_wave=matches[0]
        for s in rows:
            if s['event'] in ('WaveCleared','WaveHealthReached'):
                require(s.get('waveId') in ids or s.get('waveId') is None and bool(n['encounters']), 'wave signal needs nonempty referenced wave')
            if s['event']=='BossDefeated':require(boss is not None,'BossDefeated requires boss')
        parents=[after_edges[(p,e['portal']['key'])] for p,e in incoming[nid]]
        guaranteed=set.intersection(*parents) if parents else set()
        available=guaranteed|{s['flag'] for s in rows if s['event'] in ('RegionEntered','RegionHeld','NodeDelayElapsed')}
        spawned=set();si=0
        def wave_flags(wid):
            spawned.add(wid)
            available.update(s['flag'] for s in rows if s['event'] in ('WaveCleared','WaveHealthReached') and s.get('waveId')==wid)
            if boss is not None and boss_wave==wid:
                available.update(s['flag'] for s in rows if s['event']=='BossDefeated')
        def interactions(postclear):
            for s in rows:
                i=s.get('interaction')
                if i and (postclear or not i.get('requireGroupCleared',False)) and flags(i)<=available:
                    available.add(s['flag'])
        if n['encounters']:wave_flags(None)
        while True:
            old=(set(available),set(spawned),si); interactions(False)
            for w in timed:
                if w['id'] not in spawned and flags(w)<=available:wave_flags(w['id'])
            while si<len(seq) and flags(seq[si])<=available:
                wave_flags(seq[si]['id']);si+=1
            if old==(available,spawned,si):break
        require(set(ids)<=spawned,'unreachable required wave')
        preclear=set(available)
        available.update(s['flag'] for s in rows if s['event'] in ('GroupCleared','ClearDelayElapsed'))
        while True:
            old=set(available);interactions(True)
            if old==available:break
        require({s['flag'] for s in rows}<=available,'unreachable signal')
        node_exits=[]
        for e in exits(n):
            needed=flags(e['portal'].get('condition'));require(needed<=available,'unreachable exit condition')
            after=guaranteed|needed
            after.update(s['flag'] for s in rows if s['event'] in ('GroupCleared','BossDefeated','WaveCleared','WaveHealthReached'))
            for w in waves:after.update(flags(w))
            while True:
                old=set(after)
                for f in list(after):
                    if by_flag.get(f,{}).get('interaction'):after.update(flags(by_flag[f]['interaction']))
                if old==after:break
            after_edges[(nid,e['portal']['key'])]=after
            node_exits.append({'key':e['portal']['key'],'action':e['action'],'target':e.get('targetNode'),
                               'guaranteed_after_exit':sorted(after)})
        out.append({'node':nid,'guaranteed_flags_on_entry':sorted(guaranteed),
                    'preclear_possible_flags':sorted(preclear),'postclear_possible_flags':sorted(available),
                    'boss_wave':boss_wave,'spawnable_wave_ids':sorted(x for x in spawned if x is not None),
                    'exits':node_exits})
    return {'definition':definition['id'],'node_count':len(nodes),'topological_order':order,
            'flag_count':len(by_flag),'nodes':out,'result_endpoints':sum(e['action']=='Result' for n in nodes.values() for e in exits(n)),
            'assumptions':['accepted combat can defeat each actor','required regions/interactions can be reached','eligible clock observations progress'],
            'scope':'static dependency possibility; not actual Server loader or execution'}


def analyze(repo, originals, server_sources):
    sources=verify_sources(repo,originals,server_sources)
    builder=load_module('p0_authoring_builder',HERE/'build_authoring.py')
    builder.REPO=repo
    for rel,expected in builder.build().items():
        require(json_file(HERE/rel)==expected,'authored projection drift '+rel)
    schema=json_file(repo/'design/scenario-content/local-scenario-definition.schema.json')
    validator=Draft202012Validator(schema)
    spatial=load_module('p0_spatial_helper',repo/'kr-extra-roy/MEF-level-functional-closure-20261118/space-mechanisms/audit_spatial.py')
    reader=load_module('p0_stp_reader',repo/'kr-extra-roy/MEF-world-identity-scene-interaction-20261117/stp_reader.py')
    table=reader.STP(originals/'07-Table.stp'); bnd=reader.STP(originals/'10-BoundMap.stp')
    raw,metadata=table.get('Table/_MapList.xml'); root=ET.fromstring(raw)
    maprows=root.findall('.//MAP') or list(root)
    row=next(r.attrib for r in maprows if int(r.attrib['ID'])==193)
    member='BoundMap/'+row['BOUND']+'.bnd';data,bmeta=bnd.get(member)
    bound=spatial.Bound(data,bmeta)
    profiles={p['id'] for p in json_file(repo/'design/scenario-content/functional-lab.monster-behavior.json')['profiles']}
    projections=[]; geometry=[]; coverage=Counter(); schemas=[]
    for path in sorted((HERE/'examples').glob('*.scenario.json')):
        doc=json_file(path);errors=list(validator.iter_errors(doc));require(not errors,'schema '+path.name+': '+str(errors[:1]))
        schemas.append(path.name)
        for d in doc['definitions']:
            projections.append(dependency_projection(d))
            for n in d['nodes']:
                require(n['map']==193,'unselected map')
                require(n['aiProfile'] in profiles,'missing profile')
                coverage.update(s['event'] for s in n.get('signals',[]))
                coverage['empty_initial_nodes']+=not bool(n['encounters'])
                coverage['named_required_boss_nodes']+=bool((n.get('requiredBoss') or {}).get('waveId'))
                for loc,kind,point in spatial.all_points(n):
                    require(bound.walkable(point) and bound.connected(n['spawn'],point),'BND point '+d['id']+'/'+loc)
                    route=bound.segment(n['spawn'],point)
                    require(route['blocked_samples']==0,'BND route samples '+d['id']+'/'+loc)
                    item={'definition':d['id'],'node':n['node'],'location':loc,'kind':kind,
                          'point':{k:point[k] for k in ('x','y')},'reachable':True,'spawn_segment':route}
                    if 'radius' in point:
                        item['disk_samples']=bound.disk_samples(point)
                        require(item['disk_samples']['blocked_samples']==0,'BND circle samples '+d['id']+'/'+loc)
                    geometry.append(item)
    require(all(coverage[k]>0 for k in ('RegionEntered','BossDefeated','empty_initial_nodes','named_required_boss_nodes')),'four missing coverages')
    repeated=next(p for p in projections if p['definition']=='p0-fixed-three-visits-candidate')
    require(repeated['node_count']==3 and repeated['result_endpoints']==1,'finite repetition endpoint')
    carry=next(p for p in projections if p['definition']=='p0-cross-node-wave-guarantees-candidate')
    require({'boss-defeated','boss-wave-cleared'}<=set(carry['nodes'][1]['guaranteed_flags_on_entry']),'cross-node guarantees')
    weighted=json_file(HERE/'examples/weighted-entry.plan.json');acc=0;intervals=[]
    require(weighted['catalog_sha256']==sha((HERE/'examples'/weighted['catalog_file']).read_bytes()),'selected catalog identity')
    choices={d['id'] for d in json_file(HERE/'examples/missing-coverage.scenario.json')['definitions']}
    for row in weighted['entries']:
        require(row['definitionId'] in choices and type(row['weight']) is int and row['weight']>0,'weighted entry')
        intervals.append({'definition':row['definitionId'],'inclusive_lower':acc,'exclusive_upper':acc+row['weight']});acc+=row['weight']
    require(0<acc<=2147483647,'bounded entry weight sum')
    require(len({x['definition'] for x in intervals})==len(intervals),'duplicate entry choice')
    return {'schema':'MEF_P0_RULE_EXAMPLE_ANALYSIS_V1','result':'PASS_STATIC_AUTHORING_DEPENDENCIES_AND_BND',
            'source_verification':sources,'scenario_files':schemas,'definition_count':len(projections),
            'node_count':sum(x['node_count'] for x in projections),'coverage':dict(coverage),'projections':projections,
            'map_join':{'map':193,'bound_member':member,'map_list_member':metadata,'bnd':bound.metadata},
            'geometry':geometry,'weighted_entry_intervals':intervals,'total_weight':acc,
            'server_or_client_or_lua_executed':False,'deployed':False,
            'limitations':['no actual Server loader, tick simulation or gameplay',
                          'BND checks 2D point connectivity and samples, not actor width or Client 3D collision',
                          'new author definitions require explicit content/selector registration before use']}


def main():
    parser=argparse.ArgumentParser()
    parser.add_argument('--repo',type=Path,default=DEFAULT_REPO)
    parser.add_argument('--sources',type=Path,required=True)
    parser.add_argument('--server-sources',type=Path,required=True)
    parser.add_argument('--output',type=Path)
    args=parser.parse_args()
    value=analyze(args.repo,args.sources,args.server_sources)
    if args.output:args.output.write_text(json.dumps(value,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps({k:value[k] for k in ('result','source_verification','definition_count','node_count','coverage')},ensure_ascii=False,indent=2))


if __name__=='__main__':main()
