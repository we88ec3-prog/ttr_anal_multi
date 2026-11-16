from pathlib import Path
import sys,json,hashlib,xml.etree.ElementTree as E
R=Path(__file__).resolve().parents[2];sys.path.insert(0,str(R/'anal'))
from stp_resources import Archive
from build_native_index import PE
m=json.loads((R/'CLIENT/evidence/20261108-variant-v10/build-manifest.json').read_text(encoding='utf-8'));sha=lambda b:hashlib.sha256(b).hexdigest()
a=Archive(R/'TC_UI/Table.story-zh-tw-v5.stp');checks=[]
for spec,summary in zip(m['paths'],m['members']):
 before=E.fromstring(a.read(spec['before']));after=E.fromstring((R/spec['after']).read_bytes())
 aa=list(before.iter());bb=list(after.iter());assert len(aa)==len(bb);changed=0
 for x,y in zip(aa,bb):
  assert x.tag==y.tag and len(x)==len(y) and x.attrib.keys()==y.attrib.keys()
  allowed=set()
  if spec['kind']=='messages' and x.tag=='Text':allowed={'value'}
  if spec['kind']=='area' and x.tag in ['TOWN_DESC','FIELD_DESC']:allowed={'NAME','DESC'}
  if spec['kind']=='town' and x.tag=='TOWN':allowed={'NAME'}
  for k,v in x.attrib.items():
   if k not in allowed:assert y.attrib[k]==v,(spec['before'],x.tag,k)
   changed+=v!=y.attrib[k]
  if spec['kind']=='summary' and x.tag=='Summary':changed+=x.text!=y.text
  else:assert x.text==y.text
  assert x.tail==y.tail
 assert changed==summary['changes'];checks.append({'member':spec['before'],'displayChanges':changed,'allOtherFieldsAndStructureEqual':True})
source=PE(R/'Tartaros.ip-zh-tw-v7.exe');out=PE(R/'Tartaros.ip-zh-tw-v10.exe')
assert len(source.data)==len(out.data) and source.sections==out.sections
assert source.data[:source.u32(source.opt+60)]==out.data[:out.u32(out.opt+60)]
for section in source.sections:
 if section['flags']&0x20000000:assert source.read(section['va'],section['size'])==out.read(section['va'],section['size'])
for f in m['outputs']:assert sha((R/f['path']).read_bytes())==f['sha256']
prior=json.loads((R/'CLIENT/evidence/20261108-variant-v9/build-manifest.json').read_text(encoding='utf-8'))
for f in ['fcs.flu','pack.gms','Tartaros.ip-zh-tw-v7.exe','Tartaros.ip-zh-tw-v8.exe']:
 assert sha((R/f).read_bytes())==prior['preservedExistingFiles'][f]
result={'schema':'V10_INDEPENDENT_TREE_AND_PE_CHECK','members':checks,'headersAndCodeIdenticalToV7':True,'fcsFluAndPackGmsAndOldVersionsPreserved':True,'outputHashesVerified':True,'runtime':'PENDING_USER'}
(R/'CLIENT/evidence/20261108-variant-v10/static-check.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode());print(json.dumps(result))
