"""Read-only STPD index/EX decoding and town/map correlation. No game execution.
Independent analyst utility; archive format reference: anal/stp_resources.py (read only).
"""
import hashlib, json, struct, zlib, pathlib, xml.etree.ElementTree as ET
ROOT = pathlib.Path(__file__).resolve().parents[3]
OUT = pathlib.Path(__file__).resolve().parent / 'evidence'
def sha(b): return hashlib.sha256(b).hexdigest()
def archive(path):
    raw=path.read_bytes()
    assert raw[:4]==b'STPD'
    data=bytes(x^255 for x in raw)
    index=struct.unpack_from('<I',data,4)[0]
    assert raw[index:index+4]==b'STPI'
    pos=index+8; files={}
    def node(parent):
        nonlocal pos
        n=struct.unpack_from('<H',data,pos)[0];pos+=2
        name=data[pos:pos+n].decode('ascii').rstrip('\0');pos+=n
        kind=data[pos];pos+=1
        full='/'.join(x for x in (parent,name) if x)
        if kind in (1,2):
            count=struct.unpack_from('<I',data,pos)[0];pos+=12
            for _ in range(count):node(full)
        else:
            assert kind==0
            ident=struct.unpack_from('<I',data,pos+4)[0];pos+=16
            files[full]=ident
    node('');assert pos==len(data)
    table=struct.unpack_from('>I',data,12)[0]
    count=struct.unpack_from('<I',data,table)[0]
    blocks={}
    for i in range(count):
        ident,size,first,last=struct.unpack_from('<4I',data,table+4+i*32)
        assert ident not in blocks
        blocks[ident]=(size,first,last)
    return raw,data,files,blocks
def read_member(data,blocks,ident):
    size,first,last=blocks[ident];assert size<=(last-first+1)*1024
    payload=data[16+first*1024:16+first*1024+size]
    packed_sha=sha(payload)
    if payload[:2]==b'EX':
        mode=payload[2];compressed,expanded,offset=struct.unpack_from('<III',payload,4)
        assert mode in (0,1) and offset>=16 and offset+compressed<=len(payload)
        body=payload[offset:offset+compressed]
        if mode:
            key=[0x30,0xe7]
            for i in range(2,1024):key.append((key[i-2]+key[i-1]+0x13-(0x56 if i==0x17c else 0))&255)
            body=bytes(x^key[i%1024] for i,x in enumerate(body))
        payload=zlib.decompress(body);assert len(payload)==expanded
    return payload,packed_sha
def main():
    raw,data,files,blocks=archive(ROOT/'Table.stp')
    result={'status':'待整合','source':{'path':'Table.stp','sha256':sha(raw)},'tool':'inspect_town_resources.py v1; Python stdlib','members':{},'limits':['Current archive identity does not establish original build pairing','Town/map equal ID is a candidate join until native consumer verified','Archive member names are resource presence only, not successful load or playability']}
    docs={}
    for name in ('_MapList.xml','_TownList.xml'):
        matches=[p for p in files if p.rsplit('/',1)[-1].lower()==name.lower()]
        assert len(matches)==1,matches
        path=matches[0];payload,packed=read_member(data,blocks,files[path])
        (OUT/name).write_bytes(payload)
        result['members'][name]={'archive_path':path,'block_id':files[path],'block':blocks[files[path]],'packed_sha256':packed,'decoded_sha256':sha(payload),'bytes':len(payload)}
        docs[name]=ET.fromstring(payload)
    maps={int(x.attrib['ID']):dict(x.attrib) for x in docs['_MapList.xml']}
    towns=[]
    for x in docs['_TownList.xml']:
        tid=int(x.attrib['ID']);towns.append({'town':dict(x.attrib),'npc_count':len(x.findall('./NPCLIST/NPC')),'same_id_map_candidate':maps.get(tid)})
    result['towns']=towns
    result['town_named_maps']=[m for m in maps.values() if 'town' in m.get('MAP','').lower() or 'square' in m.get('MAP','').lower()]
    inventories=[];names={}
    for path in sorted((ROOT/'Map').rglob('*.stp'))+[ROOT/'Field.stp']:
        r,d,f,b=archive(path)
        inventories.append({'path':str(path.relative_to(ROOT)),'sha256':sha(r),'members':len(f)})
        for member,ident in f.items():
            names.setdefault(member.rsplit('/',1)[-1].lower(),[]).append({'archive':str(path.relative_to(ROOT)),'member':member,'block_id':ident})
    result['archive_inventory']=inventories
    for m in result['town_named_maps']:
        m['resource_name_candidates']={key:[row for name,rows in names.items() if name.rsplit('.',1)[0]==m[key].lower() for row in rows] for key in ('MAP','BOUND')}
        bundle=[path for path in (ROOT/'Map').rglob('*.stp') if path.stem.lower()==m['MAP'].lower()]
        m['model_bundle_candidates']=[{'path':str(path.relative_to(ROOT)),'sha256':sha(path.read_bytes())} for path in bundle]
    (OUT/'town-resource-audit.json').write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({'towns':len(towns),'town_named_maps':len(result['town_named_maps']),'table_sha256':result['source']['sha256'],'output':str(OUT/'town-resource-audit.json')}))
if __name__=='__main__':main()
