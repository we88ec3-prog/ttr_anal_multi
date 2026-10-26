import pathlib,runpy,json,hashlib
OUT=pathlib.Path(__file__).resolve().parent;EV=OUT/'evidence';ROOT=OUT.parents[1].parent
n=runpy.run_path(str(OUT/'inspect_town_resources.py'))
audit=json.loads((EV/'town-resource-audit.json').read_text(encoding='utf-8'))
selected=[r for r in audit['town_named_maps'] if r['ID'] in ('182','183')]
assert len(selected)==2
cache={};rows=[]
for m in selected:
    result={'map_row':{k:m[k] for k in ('ID','TRIGGER','MAP','BOUND')},'resources':[]}
    candidates=m['resource_name_candidates']['MAP']+m['resource_name_candidates']['BOUND']
    for item in candidates:
        if not item['member'].lower().endswith(('.fld','.mre','.bnd','.mmt')):continue
        path=ROOT/item['archive']
        if str(path) not in cache:cache[str(path)]=n['archive'](path)
        raw,data,files,blocks=cache[str(path)];payload,packed=n['read_member'](data,blocks,item['block_id'])
        result['resources'].append({**item,'archive_sha256':hashlib.sha256(raw).hexdigest(),'block':blocks[item['block_id']],'packed_sha256':packed,'decoded_sha256':hashlib.sha256(payload).hexdigest(),'decoded_size':len(payload),'prefix_64_hex':payload[:64].hex(),'semantic_status':'raw bytes observed; header/coordinates not interpreted'})
    rows.append(result)
r={'integration_status':'待整合','priority':'城鎮1/2切換','source_table_sha256':audit['source']['sha256'],'source_binary_sha256':'9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91','observed_map_candidates':rows,'inference':'town001/town002 names suggest first two town candidates; TownList ID join and scene/packet fields not proven','blocking_gaps':['Native Town1/2 -> map182/183 relation','0012/0038/0069 order and controller handoff; T05/T07','Map load path/dependencies and legal spawn; T06/T09','Party instance selection/return and persistence backend policy'],'limits':['No target execution','No original build pairing claim','No safe coordinate guessed','Event plaza unresolved: alternate map versus decoration']}
(EV/'town12-resource-bytes.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps({'maps':[m['map_row']['ID'] for m in rows],'resource_records':[len(m['resources']) for m in rows]}))
