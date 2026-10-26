import pathlib,json,hashlib,runpy,xml.etree.ElementTree as ET
OUT=pathlib.Path(__file__).resolve().parent;ROOT=OUT.parents[1].parent;EV=OUT/'evidence'
n=runpy.run_path(str(OUT/'inspect_town_resources.py'))
source=ROOT/'anal/backups/Table.original-kr.stp';raw,data,files,blocks=n['archive'](source)
manifest=json.loads((EV/'resource-manifest-consistency.json').read_text(encoding='utf-8'));expected=next(x for x in manifest['files'] if x['path']=='Table.stp')['declaration']
assert len(raw)==int(expected['FileLength']) and hashlib.md5(raw).hexdigest()==expected['Checksum']
rows=[];docs={}
for name in ('_MapList.xml','_TownList.xml','_TownTypeList.xml','TownWorldListTable.xml','_SysMapList.xml'):
    member=next(x for x in files if x.endswith('/'+name));blob,packed=n['read_member'](data,blocks,files[member]);dest=EV/('original-'+name);dest.write_bytes(blob);doc=ET.fromstring(blob);docs[name]=doc
    current=EV/name
    rows.append({'member':member,'block_id':files[member],'block':blocks[files[member]],'packed_sha256':packed,'decoded_sha256':hashlib.sha256(blob).hexdigest(),'decoded_bytes':len(blob),'output':dest.name,'root':doc.tag,'rows':len(doc),'equal_current_decoded':current.exists() and current.read_bytes()==blob,'current_decoded_sha256':hashlib.sha256(current.read_bytes()).hexdigest() if current.exists() else None})
maps={m.get('ID'):dict(m.attrib) for m in docs['_MapList.xml']}
selected={k:maps.get(k) for k in ('1','2','182','183','511','4514')}
r={'status':'待整合','source_path':str(source.relative_to(ROOT)),'source_sha256':hashlib.sha256(raw).hexdigest(),'source_md5':hashlib.md5(raw).hexdigest(),'manifest_carrier_sha256':manifest['carrier']['sha256'],'manifest_declared_table_match':True,'members':rows,'map_rows':selected,'town_rows':[dict(x.attrib) for x in docs['_TownList.xml'] if x.get('ID') in ('1','2')],'towntype_rows':[dict(x.attrib) for x in docs['_TownTypeList.xml'] if x.get('ID') in ('1','2')],'limits':['Name of backup not used as proof; exact declaration length/MD5 checked','Unsigned local manifest consistency is not publisher authenticity proof','Individual decoded table equality is distinct from complete archive equality','No Town->Map relation inferred merely from equal IDs or names']}
(EV/'original-table-comparison.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps({'archive_sha256':r['source_sha256'],'tables':[{k:x[k] for k in ('member','rows','equal_current_decoded')} for x in rows],'map_rows':selected},ensure_ascii=True))
