"""Create approved v5 EXE/Table without overwriting existing game files."""
from pathlib import Path
import sys,json,hashlib,re,collections,xml.etree.ElementTree as ET
from xml.sax.saxutils import escape
R=Path(__file__).resolve().parents[2];sys.path.insert(0,str(R/'anal'))
from stp_resources import Archive
from build_zh_tw_v3_font import pack_overlay
from build_zh_tw_v3_text_resources import index_xml
from check_zh_tw_v3_glyphs import cmap
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def build():
 baseexe=R/'Tartaros.ip-zh-tw-v4.exe';basetable=R/'TC_UI/Table.story-zh-tw-v4.stp';tcpath=R.parent/'tc_workspace/Table.stp'
 assert sha(baseexe)=='008712b39d367c1c7b5f5b962d94ec9cafdc97111f4742d7d874ce16525f5770'
 assert sha(basetable)=='2a5f74af1f779879ffd2bd0a051178f3d5e8ddbf214113c36fad6c0ed93ebaf5'
 assert sha(tcpath)=='d0a7980cfa72d41f18ed21da4804b7a5939e86a93d40f07bdcb68d0645a76a84'
 outputs=[R/'Tartaros.ip-zh-tw-v5.exe',R/'TC_UI/Table.story-zh-tw-v5.stp']
 assert all(not p.exists() for p in outputs),'Refuse existing output'
 protected={str(p.relative_to(R)):sha(p) for directory in [R,R/'TC_UI',R/'UI',R/'UI/Font',R/'TC_UI/Font']
            for p in directory.iterdir() if p.is_file() and p.suffix.lower() in {'.exe','.bin','.dll','.stp','.flu','.gms','.ttf'}}
 a,t=Archive(basetable),Archive(tcpath);member='Table/npctable.xml';raw=a.read(member)
 def groups(archive):
  result=collections.defaultdict(list)
  for n in ET.fromstring(archive.read(member)).iter('NPC'):result[n.get('ID')].append(n.attrib)
  return result
 def actors(archive):
  result=collections.defaultdict(list)
  for cat in ET.fromstring(archive.read('Table/_ActorList.xml')).iter('OBJCATEGORY'):
   if cat.get('ID')=='6':
    for n in cat.iter('ACTOR'):result[n.get('ID')].append(n.attrib)
  return result
 old,donor=groups(a),groups(t);oa,ta=actors(a),actors(t);safe={}
 for ident,rows in old.items():
  ds=donor.get(ident,[])
  if len(rows)!=1 or len(ds)!=1 or len(oa.get(ident,[]))!=1 or len(ta.get(ident,[]))!=1:continue
  if rows[0].get('TYPE')!=ds[0].get('TYPE') or oa[ident][0].get('FILE')!=ta[ident][0].get('FILE'):continue
  safe[ident]=ds[0]
 edits=[];changes=[];counts=collections.Counter()
 for node in index_xml(raw).values():
  ident=node['attrs'].get('ID')
  if node['tag']!='NPC' or ident not in safe:continue
  tag=raw[node['start']:node['open_end']]
  for key in ['NAME','GUILD']:
   value=safe[ident].get(key,'');prior=node['attrs'].get(key,'')
   if not value.strip() or value==prior:continue
   assert key in node['attrs']
   pattern=rb'(\b'+key.encode()+rb'=)(["\'])(.*?)\2'
   def replace(m):
    quote=m[2];escaped=escape(value,{'"':'&quot;',"'":'&apos;'})
    return m[1]+quote+escaped.encode('utf-8')+quote
   tag,n=re.subn(pattern,replace,tag);assert n==1
   counts[key]+=1;changes.append({'id':ident,'field':key})
  if tag!=raw[node['start']:node['open_end']]:edits.append((node['start'],node['open_end'],tag))
 modified=raw
 for start,end,payload in sorted(edits,reverse=True):modified=modified[:start]+payload+modified[end:]
 before=index_xml(raw);after=index_xml(modified);assert before.keys()==after.keys()
 for path,node in before.items():
  other=after[path];attrs=dict(node['attrs'])
  if node['tag']=='NPC' and attrs.get('ID') in safe:
   for field in ['NAME','GUILD']:
    value=safe[attrs['ID']].get(field,'')
    if value.strip() and field in attrs:attrs[field]=value
  assert other['attrs']==attrs and other['text']==node['text'] and other['children']==node['children']
 assert dict(counts)=={'NAME':327,'GUILD':11}
 packed=pack_overlay(a,{member:modified})
 exe=baseexe.read_bytes();oldpath=b'TC_UI/Table.story-zh-tw-v4\0';newpath=b'TC_UI/Table.story-zh-tw-v5\0'
 assert exe.count(oldpath)==1;newexe=exe.replace(oldpath,newpath);diff=[i for i,(x,y) in enumerate(zip(exe,newexe)) if x!=y];assert diff==[0xbe8a19]
 needed={ord(c) for n in ET.fromstring(modified).iter('NPC') for k in ['NAME','GUILD'] for c in n.get(k,'') if not c.isspace()}
 fonts=[]
 for name in ['v4jh.ttf','v4jhbd.ttf']:
  missing=needed-cmap(R/'UI/Font'/name);fonts.append({'name':name,'required_npc_codepoints':len(needed),'missing':len(missing)})
  # Preserve original unresolved Korean rows; do not silently widen the approved fonts.
 changed_pairs={(x['id'],x['field']) for x in changes}
 changed_text=''.join(n.get(k,'') for n in ET.fromstring(modified).iter('NPC') for k in ['NAME','GUILD'] if (n.get('ID'),k) in changed_pairs)
 changed_needed={ord(c) for c in changed_text if not c.isspace()}
 for name in ['v4jh.ttf','v4jhbd.ttf']:assert not changed_needed-cmap(R/'UI/Font'/name),'New translated text has missing glyphs'
 for p,data in zip(outputs,[newexe,packed]):
  with p.open('xb') as f:f.write(data)
 verify=Archive(outputs[1]);assert verify.files==a.files
 for name in a.files:assert verify.read(name)==(modified if name==member else a.read(name))
 assert all(sha(R/name)==h for name,h in protected.items())
 report={'authorization':'User explicitly approved v5 nameplate NAME/GUILD proposal, retain v4 and original files.',
         'source_exe_sha256':sha(baseexe),'source_table_sha256':sha(basetable),'taiwan_table_sha256':sha(tcpath),
         'outputs':[{'path':str(p.relative_to(R)),'sha256':sha(p),'bytes':p.stat().st_size} for p in outputs],
         'exe_diff_vs_v4':[hex(i) for i in diff],'archive_members_verified':len(a.files),'changed_member':member,
         'eligible_ids':len(safe),'changed_fields':dict(counts),'changed_ids_fields':changes,
         'excluded_duplicate_ids':[k for k,v in old.items() if len(v)>1],
         'existing_files_sha256':protected,'existing_files_unchanged':True,'font_coverage':fonts,
         'fonts_modified':False,'status':'STATIC_CHECKED_PENDING_HUMAN','native_nameplate_read_chain':'not newly fully audited'}
 e=R/'CLIENT/evidence/20261107-variant-v5';e.mkdir(parents=True,exist_ok=True)
 (e/'build-manifest.json').write_bytes((json.dumps(report,indent=2)+'\n').encode('utf-8'))
 print(json.dumps({k:v for k,v in report.items() if k not in ['existing_files_sha256','changed_ids_fields']}))
if __name__=='__main__':build()
