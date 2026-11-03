"""Read-only selected Town5 NPC facts and explicit Server placement checks, no game execution."""
import argparse, hashlib, json, struct, zlib
from pathlib import Path
import xml.etree.ElementTree as ET
from inspect_tutorial_bounds_resource import members, ARCHIVE_SHA, SQUARE
from inspect_first_tutorial_cluster import decode

TABLE='ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c'
ORIGINAL_TABLE='09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442'
NPC_BASE='1b74183c48f7ca3c0e7185d3f814b31f4e2825e34d49087fc0c85115f2e0f92b'
TOWN='ccd66c13d6b0613372fe2d1f4c77f9ef906f12cb50b23ca791e1d429da55b0c8'
IDS=[10013,10014,10015,10016,10049,10050,10051,10069,10094,10101,10026,10338]
MODELS=[10338]+IDS[:-1]
POSITIONS=[(920,900),(850,940),(870,940),(890,940),(910,940),(930,940),
           (930,910),(850,965),(850,910),(870,910),(910,965),(930,965)]

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--workspace',type=Path,required=True)
    p.add_argument('--original-table',type=Path,required=True)
    p.add_argument('--output',type=Path,required=True)
    a=p.parse_args(); assert a.output.suffix=='.json' and not a.output.exists()
    sources=[]
    def selected(path,pin,names):
        result={}
        for name,raw in members(path.read_bytes(),pin,names).items():
            data=decode(raw); result[name]=data
            sources.append({'carrier_sha256':pin,'member':name,'member_sha256':hashlib.sha256(data).hexdigest()})
        return result
    names=['Table/_TownList.xml','Table/_ActorList.xml','Table/npctable.xml']
    current=selected(a.workspace/'Table.stp',TABLE,names)
    original=selected(a.original_table,ORIGINAL_TABLE,names)
    trees={n:ET.fromstring(b.decode('utf-8-sig')) for n,b in current.items()}
    oldtrees={n:ET.fromstring(b.decode('utf-8-sig')) for n,b in original.items()}
    assert current[names[0]]==original[names[0]] and current[names[1]]==original[names[1]]
    town=trees[names[0]].find("./TOWN[@ID='5']")
    assert [int(e.get('ID')) for e in town.findall('./NPCLIST/NPC')]==IDS
    npcs=[]; base_names=[]
    for model in MODELS:
        actor=trees[names[1]].find(f".//ACTOR[@ID='{model}'][@PRE='1']")
        info=trees[names[2]].find(f"./NPC[@ID='{model}']")
        old=oldtrees[names[2]].find(f"./NPC[@ID='{model}']")
        assert actor is not None and info is not None and old is not None
        without_name=lambda e:{k:v for k,v in e.attrib.items() if k!='NAME'}
        assert without_name(info)==without_name(old)
        base_names.append('Npc/'+actor.get('FILE')+'.abf')
        npcs.append({'model':model,'pre':1,'file':actor.get('FILE'),'scale_raw':actor.get('SCALE'),
                     'selected_npc_fields_equal_except_name':True})
    bases=selected(a.workspace/'Character/Npc/Base.stp',NPC_BASE,base_names)
    for npc,name in zip(npcs,base_names):
        tree=ET.fromstring(bases[name].decode('euc-kr'))
        ids={e.get('ID') for e in tree.iter('Animation')}
        assert '1' in ids
        npc.update(idle_motion1_present=True,motion7_present='7' in ids)
    bnd=selected(a.workspace/'Map/BoundMap.stp',ARCHIVE_SHA,SQUARE)['BoundMap/square001.bnd']
    assert hashlib.sha256(bnd).hexdigest()==SQUARE['BoundMap/square001.bnd']
    assert struct.unpack_from('<IIIff',bnd,0x20)==(0,768,768,1536.,1536.)
    layers=[]
    for i in range(2):
        off,comp,exp,count=struct.unpack_from('<4I',bnd,0x34+16*i)
        data=zlib.decompress(bnd[off:off+comp]); assert len(data)==exp==768*768*4 and count==768*768
        layers.append(data)
    def sample(x,y):
        return [struct.unpack_from('<I',l,(int(y/2)*768+int(x/2))*4)[0] for l in layers]
    old_positions=[(920,900)]+[(850+(i-1)%6*20,940+(i-1)//6*25) for i in range(1,12)]
    old_samples=[{'model':m,'xy':[x,y],'layer_values':sample(x,y)} for m,(x,y) in zip(MODELS,old_positions)]
    for npc,(x,y) in zip(npcs,POSITIONS):
        values=sample(x,y); assert values==[0,0]
        npc.update(server_candidate_xy=[x,y],layer_values=values)
    fld_name='Town/square001D.fld'
    fld=selected(a.workspace/'Map/Map/Town.stp',TOWN,[fld_name])[fld_name]
    assert hashlib.sha256(fld).hexdigest()=='0b0ce7cf428c9aa4affc68a7b02aaae2feca963436bdd8c7a0054a93f7eb05f1'
    tree=ET.fromstring(fld.decode('euc-kr'))
    result={'schema':'s00-square-npc-selected-facts-v1','classification':'Resource facts plus explicit Server placement policy, not official NPC placement',
            'sources':sources,'town':5,'town_membership':IDS,'npcs':npcs,'legacy_server_position_samples':old_samples,
            'fld_scope':{'member':fld_name,'object_tag_count':len(list(tree.iter('Object'))),
                         'selected_npc_id_strings_present':[i for i in IDS if str(i).encode('ascii') in fld]},
            'limits':['Current/original selected NPC fields compare equal except NAME; this is not all-resource integrity proof.',
                      'Town5 membership does not prove Town5->map511 or official placements.',
                      'Visual NPC actors do not imply interaction, quest completion, loading or runtime visibility.',
                      'Static point checks exclude dynamic collision, character radius, height and full navigation.',
                      'A missing literal ID in one FLD is not global NPC/MEF absence proof.']}
    a.output.write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode('utf8'))
    print(json.dumps({'npcs':len(npcs),'legacy_blocked':sum(any(r['layer_values']) for r in old_samples),'output':str(a.output)}))

if __name__=='__main__':main()
