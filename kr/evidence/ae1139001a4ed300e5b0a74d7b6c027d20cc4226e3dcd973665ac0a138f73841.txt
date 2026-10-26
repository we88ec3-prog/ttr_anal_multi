"""Manifest consistency check; unsigned manifest is not authenticity proof."""
import pathlib,struct,zlib,hashlib,xml.etree.ElementTree as ET,json
OUT=pathlib.Path(__file__).resolve().parent;ROOT=OUT.parents[1].parent;EV=OUT/'evidence'
raw=(ROOT/'Integrity.xml').read_bytes();assert raw[:3]==b'EX\x00'
compressed,expanded,offset=struct.unpack_from('<III',raw,4)
assert offset>=16 and offset+compressed<=len(raw)
decoded=zlib.decompress(raw[offset:offset+compressed]);assert len(decoded)==expanded
root=ET.fromstring(decoded.decode('euc-kr'));entries={}
def walk(node,parent=''):
    current=parent
    if node.tag=='FOLDER' and node.get('name'):current='/'.join(filter(None,(parent,node.get('name'))))
    if node.tag=='FILE':entries['/'.join(filter(None,(current,node.get('name'))))]=dict(node.attrib)
    for child in node:walk(child,current)
walk(root)
selected=['Tartaros.bin','Table.stp','Master.stp','Field.stp','Map/Map/Town.stp','Map/BoundMap.stp','Map/MiniMap.stp']
rows=[]
for name in selected:
    item=entries[name];data=(ROOT/name).read_bytes();md5=hashlib.md5(data).hexdigest()
    rows.append({'path':name,'declaration':item,'actual_bytes':len(data),'actual_md5':md5,'actual_sha256':hashlib.sha256(data).hexdigest(),'length_matches':len(data)==int(item['FileLength']),'md5_matches':md5.lower()==item['Checksum'].lower()})
r={'status':'待整合','tool_version':'check_resource_manifest.py v1 / Python stdlib','carrier':{'path':'Integrity.xml','sha256':hashlib.sha256(raw).hexdigest(),'bytes':len(raw)},'decoded':{'sha256':hashlib.sha256(decoded).hexdigest(),'bytes':len(decoded),'encoding':'euc-kr'},'declared_patch_attributes':root.attrib,'files':rows,'observed':'Current files compared to exact manifest declarations','limits':['Manifest is unsigned/untrusted; match means consistency with this manifest only','No file changes or network fetching','MD5 is retained manifest format; SHA256 also measured','No original Table contents recovered by mismatch','Town->Map mapping and playable switching remain unproven']}
(EV/'resource-manifest-consistency.json').write_text(json.dumps(r,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
print(json.dumps({'results':[{k:x[k] for k in ('path','length_matches','md5_matches')} for x in rows]}))
