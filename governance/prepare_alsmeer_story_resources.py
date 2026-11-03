"""Read-only original resources -> local derived scenario metadata and pinned BND copies.
Positions/cluster selection are explicit Server reconstruction, not original MEF.
No Client execution, modification, official reward/quest completion inference.
"""
import argparse, hashlib, json, struct, zlib, csv
from array import array
from pathlib import Path
import xml.etree.ElementTree as E
from inspect_tutorial_bounds_resource import members
from inspect_first_tutorial_cluster import decode
TABLE = 'ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c'
FIELD = '18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a'
BOUNDS = '07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8'
CHAIN = [117,118,119,120,121,122,123,124,131,132]

def read_archive(path, pin, names):
    return {n:decode(v,max_expanded=8_000_000) for n,v in members(path.read_bytes(),pin,names).items()}

def layout(data, town=False):
    assert data[:21] == b'MapTool Reinforce 1.0'
    version,w,h,wx,wy = struct.unpack_from('<IIIff',data,0x20)
    assert version in (0,2) and 0<w<=2048 and 0<h<=2048
    blocked=bytearray(w*h);cursor=0x234;layer_ids=[]
    for layer in range(32):
        offset,size,expanded,count=struct.unpack_from('<4I',data,0x34+layer*16)
        if not count:continue
        assert layer in (0,1) and count==w*h and expanded==count*4 and offset==cursor
        d=zlib.decompressobj();raw=d.decompress(data[offset:offset+size]);assert d.eof and not d.unused_data and len(raw)==expanded
        values=array('I');values.frombytes(raw)
        for i,v in enumerate(values):
            if v:blocked[i]=1
        cursor+=size;layer_ids.append(layer)
    assert layer_ids==[0,1] and cursor==len(data)
    prefix=array('I',[0])*((w+1)*(h+1))
    for y in range(h):
        row=0
        for x in range(w):
            row+=blocked[y*w+x];prefix[(y+1)*(w+1)+x+1]=prefix[y*(w+1)+x+1]+row
    def total(x0,y0,x1,y1):return prefix[y1*(w+1)+x1]-prefix[y0*(w+1)+x1]-prefix[y1*(w+1)+x0]+prefix[y0*(w+1)+x0]
    half=max(1,int((36 if town else 18)*w/wx)+1)
    candidates=((x,y) for y in range(half,h-half,2) for x in range(half,w-half,2) if total(x-half,y-half,x+half+1,y+half+1)==0)
    x,y=min(candidates,key=lambda v:(v[0]-w/2)**2+(v[1]-h/2)**2)
    sx,sy=(x+0.5)*wx/w,(y+0.5)*wy/h
    return {'version':version,'width':w,'height':h,'worldWidth':wx,'worldHeight':wy,'spawnX':sx,'spawnY':sy,'portalX':sx+12,'portalY':sy,'clearHalfWorld':half*wx/w}

def main():
    a=argparse.ArgumentParser(description=__doc__);a.add_argument('--workspace',type=Path,required=True);a.add_argument('--output',type=Path,required=True);args=a.parse_args()
    root=args.workspace;out=args.output;out.mkdir(parents=True,exist_ok=True)
    tn=['Table/_MapList.xml','Table/_CaseList.xml','Table/_TownList.xml','Table/QuestInfo.xml'];td=read_archive(root/'Table.stp',TABLE,tn);trees={n:E.fromstring(d.decode('utf-8-sig')) for n,d in td.items()}
    original_member_pins={
        'Table/_MapList.xml':'cd47d8ca42f4297f6584a2c0c8807ae76352e3b353855b3989f660e64fd27f8c',
        'Table/_CaseList.xml':'a6282323e287900512e515be01927ae3f75fa0c1540e0261473530eb0487043a',
        'Table/_TownList.xml':'bba254efd72fac0be6c51c6135423601effcbad02448f46aadec3324e449d660',
        'Table/QuestInfo.xml':'5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60'}
    # Carrier differs from the T01 original Table.stp; only these exact
    # original-matching members are used. Translated NPC names are excluded.
    assert all(hashlib.sha256(td[n]).hexdigest()==pin for n,pin in original_member_pins.items())
    cases=[e for e in trees[tn[1]] if e.get('STAGE') in ('17','26','27','28')];paths=[]
    for c in cases:paths += ['Field/MapFlow/'+c.get('MAPFLOW'),'Field/Cluster/'+c.get('CLUSTER')]
    fd=read_archive(root/'Field.stp',FIELD,paths);mapids={182,183};scenarios=[]
    for c in cases:
        chart=E.fromstring(fd['Field/MapFlow/'+c.get('MAPFLOW')].decode('euc-kr'));clusters=E.fromstring(fd['Field/Cluster/'+c.get('CLUSTER')].decode('euc-kr'))
        nodes={int(n.get('id')):n for n in chart.findall('./NodeList/Node')};walk=chart.find('NodeLink/Node');ordered=[]
        while walk is not None:
            n=nodes[int(walk.get('id'))];choices=n.findall('Map');assert len(choices)==1 and choices[0].get('percent')=='100';mid=int(choices[0].get('id'));mapids.add(mid);ordered.append({'sourceNode':int(n.get('id')),'map':mid});walk=walk.find('Node')
        sets=clusters.findall('CLUSTERSET');assert sets
        groups=[{'cluster':int(g.get('ID')),'members':[dict(model=int(o.get('ID')),pre=int(o.get('PRE')),count=int(o.get('COUNT'))) for o in g.findall('OBJECT')]} for g in sets[0].findall('CLUSTER')]
        assert len(groups)>=len(ordered)
        for i,n in enumerate(ordered):
            group=groups[i];n['selectedCluster']=group['cluster'];n['encounterModels']=[m['model'] for m in group['members'] for _ in range(m['count'])];assert 0<len(n['encounterModels'])<=20
        scenarios.append({'field':int(c.get('STAGE')),'case':int(c.get('ID')),'mapFlow':c.get('MAPFLOW'),'cluster':c.get('CLUSTER'),'nodes':ordered,'sourceClusters':groups,'clusterSelectionPolicy':'FIRST_CLUSTER_PER_ORDERED_NODE_SERVER_CANDIDATE_NOT_MEF'})
    maps=[e.attrib for e in trees[tn[0]] if int(e.get('ID','0')) in mapids];bn=sorted({'BoundMap/'+e['BOUND']+'.bnd' for e in maps});bd=read_archive(root/'Map/BoundMap.stp',BOUNDS,bn);maprows=[]
    for m in maps:
        name=m['BOUND']+'.bnd';d=bd['BoundMap/'+name];destination=out/name
        if destination.exists():assert destination.read_bytes()==d
        else:destination.write_bytes(d)
        maprows.append({'map':int(m['ID']),'model':m['MAP'],'bound':name,'sha256':hashlib.sha256(d).hexdigest(),**layout(d,int(m['ID']) in (182,183))})
    scenes=[]
    with (Path(__file__).resolve().parents[1]/'research/handoffs/kr-quest-runtime-20261103-v0.1.0/quest-scenes.csv').open(encoding='utf-8-sig',newline='') as f:
        for s in csv.DictReader(f):
            if int(s['quest_id']) in CHAIN:scenes.append({'quest':int(s['quest_id']),'scene':int(s['scene_index']),'function':s['function_name'],'calls':json.loads(s['selected_calls']),'sha256':s['sequence_sha256']})
    quests=[]
    for qid in CHAIN:
        q=trees[tn[3]].find(".//Quest[@id='%s']"%qid);assert q is not None
        quests.append({'quest':qid,'giver':int(q.get('giver')),'finisher':int(q.get('finisher')),'levelRaw':int(q.get('level')),'fieldRaw':int(q.get('field')) if q.get('field') else None,'demands':[int(d.get('id')) for d in q.findall('./Demands/Demand')]})
    result={'schema':'SERVER_STORY_RESOURCE_BASELINE_V1_NOT_NATIVE_MEF','carriers':{'table':TABLE,'field':FIELD,'bounds':BOUNDS},'sourceMembers':{n:hashlib.sha256(d).hexdigest() for n,d in {**td,**fd}.items()},'town2Npcs':[int(n.get('ID')) for n in trees[tn[2]].findall("./TOWN[@ID='2']/NPCLIST/NPC")],'quests':quests,'scenes':scenes,'scenarios':scenarios,'maps':maprows,'limits':['Finite selected clusters and legal positions are Server reconstruction; not MEF placement/waves','MapChart editor x/y not world spawn','Raw quest rewards and levels are not settlement policy','Q118 field presence does not alone authorize a scenario']}
    (out/'resource-baseline.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode())
    print(json.dumps({'quests':len(quests),'scenarios':len(scenarios),'maps':len(maprows),'town2':183}))
if __name__=='__main__':main()
