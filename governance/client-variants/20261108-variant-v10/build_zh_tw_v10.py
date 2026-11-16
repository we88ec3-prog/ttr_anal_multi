"""Translation-only v10 from pinned v7: source-backed direct XML paths.
No new executable instructions/sections or native API execution. Preserve all
old versions/resources and every non-display XML field.
"""
from pathlib import Path
import sys,hashlib,json,re,struct,xml.etree.ElementTree as E
from xml.sax.saxutils import escape
R=Path(__file__).resolve().parents[2];sys.path[:0]=[str(R/'anal'),str(R/'anal/python_deps')]
from stp_resources import Archive
from build_native_index import PE
from build_zh_tw_v3_text_resources import index_xml,valid_text
from check_zh_tw_v3_glyphs import cmap
sha=lambda b:hashlib.sha256(b).hexdigest()
SPECS=[('Table/Messages/UIText.xml','TC_UI/UITextLabelsV10.xml','messages'),
 ('Table/Messages/CommonMessages.xml','TC_UI/CommonMsgTranslations10.xml','messages'),
 ('Table/Messages/SystemMessages.xml','TC_UI/SystemMsgTranslations10.xml','messages'),
 ('Table/ScenarioBookContents.xml','TC_UI/ScenarioTextTableV10.xml','summary'),
 ('Table/AreaDescription.xml','TC_UI/AreaTextListV10.xml','area'),
 ('Table/_TownList.xml','TC_UI/TownTxt10.xml','town')]
def immutable(p,b):
 p.parent.mkdir(parents=True,exist_ok=True)
 if p.exists():assert p.read_bytes()==b,('Preserve existing',p)
 else:
  with p.open('xb') as f:f.write(b)
def safe(old,new):return bool(new and new.strip() and valid_text(old,new) is None and not re.search('[\uac00-\ud7af]',new))
def escaped(v):return escape(v,{'"':'&quot;',"'":'&apos;'}).encode('utf-8')
def overlay(raw,donor,kind,area):
 before=index_xml(raw);other=index_xml(donor);changes=[];edits=[];expected={};skips=[]
 dmsg={n.get('key'):n.get('value') for n in E.fromstring(donor)} if kind=='messages' else {}
 summaries={q.get('idx'):q.findtext('Summary') for q in E.fromstring(donor)} if kind=='summary' else {}
 townnames={q.get('ID'):q.get('NAME') for q in E.fromstring(area)}
 for path,n in before.items():
  fields={}
  if kind=='messages' and n['tag']=='Text':fields={'value':dmsg.get(n['attrs'].get('key'))}
  elif kind=='summary' and n['tag']=='Summary':
   qp=path[:-1];q=before[qp];new=summaries.get(q['attrs'].get('idx'));old=n['text'];new=new.replace('\u318d','\u00b7') if new else new
   if new!=old:
    if safe(old,new):edits.append((n['open_end'],n['close_start'],escaped(new)));expected[(path,'text')]=new;changes.append({'identity':q['attrs'].get('idx'),'field':'Summary'})
    else:skips.append({'path':repr(path),'reason':'missing-or-format-or-untranslated'})
  elif kind=='town' and n['tag']=='TOWN':fields={'NAME':townnames.get(n['attrs'].get('ID'))}
  elif kind=='area' and n['tag'] in ['TOWN_DESC','FIELD_DESC'] and path in other:
   d=other[path]
   # AREA field IDs/levels must agree; extra donor difficulties/drops are never imported.
   if any(n['attrs'].get(k)!=d['attrs'].get(k) for k in ['ID','LEVEL_LIMIT','MINLV','MAXLV']):continue
   fields={k:d['attrs'].get(k) for k in ['NAME','DESC'] if k in n['attrs']}
   if fields.get('DESC') and '※入場條件' in fields['DESC'] and '※' not in n['attrs'].get('DESC',''):
    fields['DESC']=fields['DESC'].split('※入場條件')[0].rstrip().removesuffix('<br><br>').rstrip()
  opening=raw[n['start']:n['open_end']];updated=opening
  for key,new in fields.items():
   old=n['attrs'].get(key);new=new.replace('\u318d','\u00b7') if new else new
   if old==new:continue
   if old is None or not safe(old,new):skips.append({'path':repr(path),'field':key,'reason':'missing-or-format-or-untranslated'});continue
   pat=rb'(\b'+key.encode()+rb'=)(["\'])(.*?)\2'
   updated,count=re.subn(pat,lambda m:m[1]+m[2]+escaped(new)+m[2],updated,flags=re.S);assert count==1
   expected[(path,key)]=new;changes.append({'identity':n['attrs'].get('key',n['attrs'].get('ID')),'field':key})
  if updated!=opening:edits.append((n['start'],n['open_end'],updated))
 result=raw
 for start,end,b in sorted(edits,reverse=True):result=result[:start]+b+result[end:]
 after=index_xml(result);assert before.keys()==after.keys()
 for path,a in before.items():
  b=after[path];assert a['tag']==b['tag'] and a['children']==b['children'] and a['attrs'].keys()==b['attrs'].keys()
  for key,value in a['attrs'].items():assert b['attrs'][key]==expected.get((path,key),value)
  assert b['text']==expected.get((path,'text'),a['text'])
 display=''.join(expected.values())
 return result,changes,skips,display

def build():
 source=(R/'Tartaros.ip-zh-tw-v7.exe').read_bytes();assert sha(source)=='937486b989d0a1adcddd86f5224011f8b22907c61dd30c3772ad4179891299ec'
 base=R/'TC_UI/Table.story-zh-tw-v5.stp';assert sha(base.read_bytes())=='aedba24dc9a0e828c275ebdce192f3af8661ded1b77d5088c2ea992965ec62ae'
 donor=R.parent/'tc_workspace/Table.stp';assert sha(donor.read_bytes())=='d0a7980cfa72d41f18ed21da4804b7a5939e86a93d40f07bdcb68d0645a76a84'
 protected={str(p.relative_to(R)):sha(p.read_bytes()) for folder in [R,R/'TC_UI',R/'UI',R/'UI/Font',R/'U8'] if folder.is_dir() for p in folder.iterdir() if p.is_file() and p.suffix.lower() in {'.exe','.bin','.xml','.stp','.gms','.flu','.ttf','.ini','.cfg','.dll'}}
 a=Archive(base);tc=Archive(donor);area=tc.read('Table/AreaDescription.xml');outputs={};reports=[];display='';image=bytearray(source);allowed=set();paths=[]
 for old,new,kind in SPECS:
  assert len(old)==len(new),(old,new,len(old),len(new))
  raw=a.read(old);data,changes,skips,text=overlay(raw,tc.read(old),kind,area);display+=text;outputs[new]=data
  needle=old.encode()+b'\0';assert source.count(needle)==1;at=source.index(needle);image[at:at+len(old)]=new.encode();allowed.update(range(at,at+len(old)))
  paths.append({'before':old,'after':new,'offset':hex(at),'kind':kind});reports.append({'member':old,'kind':kind,'sourceMemberSha256':sha(raw),'donorMemberSha256':sha(tc.read(old)),'outputSha256':sha(data),'changes':len(changes),'changedFields':dict(__import__('collections').Counter(c['field'] for c in changes)),'skips':len(skips),'nonDisplayValuesAndStructureUnchanged':True})
 quest=(R/'TC_UI/QuestTxt8.xml').read_bytes();assert sha(quest)=='16566b01aaf788741bd230716ca5eea4705fb0a6f6e9fc547986614ac96fc48b'
 old=b'Table/QuestInfo.xml';new=b'TC_UI/QuestTxt8.xml';assert len(old)==len(new) and source.count(old+b'\0')==1;at=source.index(old+b'\0');image[at:at+len(old)]=new;allowed.update(range(at,at+len(old)))
 # Reuse only the already source-checked v9 display-name replacements, not its preload code.
 names=json.loads((R/'CLIENT/evidence/20261108-variant-v9/build-manifest.json').read_text(encoding='utf-8'))['speakers']
 for row in names:
  old=row['before'].encode('utf-16le');new=row['after'].encode('utf-16le');at=int(row['offset'],16);assert source[at:at+len(old)]==old and len(new)<=len(old)
  image[at:at+len(old)]=new+bytes(len(old)-len(new));allowed.update(range(at,at+len(old)));display+=row['after']
 diff=[i for i,(x,y) in enumerate(zip(source,image)) if x!=y];assert len(source)==len(image) and set(diff)<=allowed
 pe=PE(R/'Tartaros.ip-zh-tw-v7.exe');header=pe.u32(pe.opt+60);assert image[:header]==source[:header]
 for section in pe.sections:
  if section['flags']&0x20000000:assert image[section['raw']:section['raw']+section['size']]==source[section['raw']:section['raw']+section['size']],'Executable code section changed'
 need={ord(c) for c in display if ord(c)>31 and not c.isspace()};fonts=[]
 for f in ['v4jh.ttf','v4jhbd.ttf']:
  missing=need-cmap(R/'UI/Font'/f);assert not missing,('new translation glyphs',f,[hex(c) for c in missing]);fonts.append({'name':f,'missingNewTranslationGlyphs':0,'sha256':sha((R/'UI/Font'/f).read_bytes())})
 ui=E.fromstring(outputs[SPECS[0][1]]);uv={n.get('key'):n.get('value') for n in ui};assert uv['kQuestListBtnOk2']=='接受任務' and uv['kMissionSuccess']=='任務成功'
 towns=E.fromstring(outputs[SPECS[-1][1]]);assert next(n for n in towns if n.get('ID')=='1').get('NAME')=='馮德斯村'
 book=E.fromstring(outputs[SPECS[3][1]]);assert not re.search('[\uac00-\ud7af]',next(n for n in book if n.get('idx')=='120').findtext('Summary'))
 outputs['Tartaros.ip-zh-tw-v10.exe']=bytes(image)
 for name,b in outputs.items():immutable(R/name,b)
 for name,h in protected.items():assert sha((R/name).read_bytes())==h,('Prior file changed',name)
 result={'schema':'ZH_TW_V10_DIRECT_TEXT_READERS','sourceExeSha256':sha(source),'sourceBaseTableSha256':sha(base.read_bytes()),'taiwanSourceSha256':sha(donor.read_bytes()),'outputs':[{'path':k,'sha256':sha(b),'bytes':len(b)} for k,b in outputs.items()],'paths':paths,'members':reports,'speakers':names,'headersAndAllCodeSectionsUnchanged':True,'newSectionsOrRuntimeMemoryWrites':False,'allPreviousFilesUnchanged':True,'fonts':fonts,'gameExecutedOrAttached':False,'runtime':'PENDING_USER','limitations':['Matched display fields only; missing keys/format changes remain in KR.','ScenarioBook summary-to-screenshot attribution remains bounded until human checked.','No village unlock, room, skill or level gameplay change.','No graphics/rendering runtime claim from static checks.']}
 d=R/'CLIENT/evidence/20261108-variant-v10';d.mkdir(exist_ok=True);(d/'build-manifest.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode());print(json.dumps(result))
if __name__=='__main__':build()
