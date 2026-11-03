"""Read-only selected Phindos resource metadata; no quest/AI/runtime authority."""
import argparse, hashlib, json, struct
from pathlib import Path
import xml.etree.ElementTree as ET
from inspect_tutorial_bounds_resource import members
from inspect_first_tutorial_cluster import decode

TABLE='ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c'
FIELD='18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a'
BOUNDS='07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8'

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--workspace',type=Path,required=True);p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();assert not a.output.exists() and a.output.suffix=='.json'
    sources=[]
    def read(path,pin,names):
        result={}
        for n,r in members(path.read_bytes(),pin,names).items():
            d=decode(r,max_expanded=3_000_000);result[n]=d
            sources.append(dict(carrier_sha256=pin,member=n,sha256=hashlib.sha256(d).hexdigest()))
        return result
    names=['Table/QuestInfo.xml','Table/_CaseList.xml','Table/_MapList.xml','Table/_TownTypeList.xml','Table/_TownList.xml']
    data=read(a.workspace/'Table.stp',TABLE,names)
    assert hashlib.sha256(data[names[0]]).hexdigest()=='5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60'
    trees={n:ET.fromstring(d.decode('utf-8-sig')) for n,d in data.items()}
    qs=trees[names[0]].findall('.//Quest');chain=[q for q in qs if q.get('town')=='1' and q.get('type')=='2']
    assert [int(q.get('id')) for q in chain]==[117,118,119,120,121,122,123,124,131,132]
    rows=[dict(attributes={k:v for k,v in q.attrib.items() if k!='subject'},demands=[x.attrib for x in q.findall('./Demands/Demand')],raw_rewards=[x.attrib for x in q.findall('./RewardsEtc/Reward')]) for q in qs if q in chain or q.get('id') in ['15','133']]
    chart_name='Field/MapFlow/CHART_S_pathofpindus_01.xml';chart=read(a.workspace/'Field.stp',FIELD,[chart_name])[chart_name]
    assert hashlib.sha256(chart).hexdigest()=='79f79516d68183a0f8efb44664139f2c69813c4c190f5e89bbacfef82e6d5049'
    ct=ET.fromstring(chart.decode('euc-kr'));chart_rows=[dict(node=x.attrib,maps=[m.attrib for m in x.findall('Map')]) for x in ct.findall('./NodeList/Node')]
    headers=[]
    for n,r in read(a.workspace/'Map/BoundMap.stp',BOUNDS,['BoundMap/town001.bnd','BoundMap/scenario_pathofpindus01.bnd','BoundMap/scenario_pathofpindus02.bnd']).items():
        assert r[:21]==b'MapTool Reinforce 1.0'
        v,w,h,x,y=struct.unpack_from('<IIIff',r,0x20);headers.append(dict(member=n,version=v,width=w,height=h,world_x=x,world_y=y))
    town=trees[names[3]].find("./TOWN[@ID='1']")
    result=dict(schema='s00-phindos-planning-resource-v1',classification='STATIC_RESOURCE_FACTS_NOT_PROTOCOL_OR_GAMEPLAY_ACCEPTANCE',sources=sources,quest_rows=rows,
                cases=[e.attrib for e in trees[names[1]] if e.get('STAGE') in ['19','17','26','27','28']],maps=[e.attrib for e in trees[names[2]] if e.get('ID') in ['182','191','192']],
                town1={k:v for k,v in town.attrib.items() if k!='NAME'},town1_npcs=[e.attrib for e in trees[names[4]].findall("./TOWN[@ID='1']/NPCLIST/NPC")],bridge_chart_nodes=chart_rows,bounds_headers=headers,
                limits=['Town1/type2 mainline scope must be confirmed with Chapter/SceneList','Raw reward types do not prove currency/EXP','Graph coordinates are not spawn','Version2 BND layout is not interpreted','No Client execution/resource modification or MEF/AI rules inferred'])
    a.output.write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
    print(json.dumps(dict(town1_type2=len(chain),bounds_versions=[r['version'] for r in headers])))

if __name__=='__main__':main()
