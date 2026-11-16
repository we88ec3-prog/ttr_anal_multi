"""v9 translation-only companions; preserve original files and gameplay fields.
No game launch/attach. A pre-loader mounts a text-only locale13 clone so numeric
UI captions also use Taiwan text; existing translation fallback stays intact.
"""
from pathlib import Path
import sys,json,hashlib,re,struct,collections,xml.etree.ElementTree as E
from xml.sax.saxutils import escape
R=Path(__file__).resolve().parents[2]
sys.path[:0]=[str(R/'anal'),str(R/'anal/python_deps')]
from stp_resources import Archive
from build_native_index import PE
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
from build_zh_tw_v3_text_resources import pack_archive,index_xml,valid_text
from check_zh_tw_v3_glyphs import cmap
sha=lambda b:hashlib.sha256(b).hexdigest()
PINS={'Tartaros.ip-zh-tw-v7.exe':'937486b989d0a1adcddd86f5224011f8b22907c61dd30c3772ad4179891299ec',
 'TC_UI/Table.story-zh-tw-v5.stp':'aedba24dc9a0e828c275ebdce192f3af8661ded1b77d5088c2ea992965ec62ae',
 'UI/StringTable.stp':'05a1a7ee26e343e1a016a37d1de2418a6da8fc5a71d5322587c49741d1162ef0',
 'TC_UI/StringTable.stp':'18710722f1d18d8e7b82ae52083929e5665fc0f671b2aa64eb17651439ec61f3'}
TC_SHA='d0a7980cfa72d41f18ed21da4804b7a5939e86a93d40f07bdcb68d0645a76a84'

def immutable(p,b):
 p.parent.mkdir(parents=True,exist_ok=True)
 if p.exists():assert p.read_bytes()==b,('Refuse overwrite',p)
 else:
  with p.open('xb') as f:f.write(b)

def fragment(b):return E.fromstring('<R>'+re.sub(r'^\s*<\?xml[^?]*\?>','',b.decode('utf-8-sig'))+'</R>')
def esc(s):return escape(s,{'"':'&quot;',"'":'&apos;'}).encode('utf-8')
def data_shape(n):return [(x.tag,{k:v for k,v in x.attrib.items() if not(x.tag=='Contents' and k=='Data')},len(x)) for x in n.iter()]

def fcs_overlay(raw,donor):
 tc={n.get('Code'):n for n in fragment(donor).iter('CHARSETITEM')};changes=[];skips=[]
 pat=rb'<CHARSETITEM\b[^>]*\bCode="(\d+)"[^>]*>.*?</CHARSETITEM>'
 def row(m):
  code=m[1].decode();old=E.fromstring(m[0]);new=tc.get(code)
  if new is None or data_shape(old)!=data_shape(new):skips.append({'code':code,'reason':'missing-or-shape'});return m[0]
  oldtexts=[x.get('Data','') for x in old.iter('Contents')];newtexts=[x.get('Data','').replace('\u318d','\u00b7') for x in new.iter('Contents')]
  if len(oldtexts)!=len(newtexts) or any(valid_text(a,b) or re.search('[\uac00-\ud7af]',b) for a,b in zip(oldtexts,newtexts)):
   skips.append({'code':code,'reason':'text-or-placeholder'});return m[0]
  i=iter(newtexts)
  value=re.sub(rb'(<Contents\b[^>]*\bData=)(["\'])(.*?)\2',lambda x:x[1]+x[2]+esc(next(i))+x[2],m[0],flags=re.S)
  assert data_shape(E.fromstring(value))==data_shape(old)
  if value!=m[0]:changes.append({'code':code,'before':oldtexts,'after':newtexts})
  return value
 out=re.sub(pat,row,raw,flags=re.S)
 before=list(fragment(raw).iter('CHARSETITEM'));after=list(fragment(out).iter('CHARSETITEM'))
 assert len(before)==len(after)
 for a,b in zip(before,after):assert data_shape(a)==data_shape(b)
 assert [x.attrib for x in fragment(raw).iter('CHARSET')]==[x.attrib for x in fragment(out).iter('CHARSET')]
 by={x.get('Code'):''.join(y.get('Data','') for y in x.iter('Contents')) for x in after}
 assert by['279']=='任務成功' and by['495']=='技能熟練度' and by['142']=='接受任務'
 return out,changes,skips

def quest_overlay(raw,donor):
 tc={n.get('id'):n for n in E.fromstring(donor)};ix=index_xml(raw);root=E.fromstring(raw);edits=[];changes=[];skips=[];approved={}
 quest_nodes={n['attrs']['id']:(path,n) for path,n in ix.items() if n['tag']=='Quest'}
 content_nodes={}
 quest_prefixes={path for path,n in quest_nodes.values()}
 for path,n in ix.items():
  if n['tag']=='Content':
   parent=next(path[:i] for i in range(1,len(path)) if path[:i] in quest_prefixes)
   content_nodes[(parent,n['attrs'].get('id'))]=(path,n)
 # Match quests by ID, not ordinal. Only subject and named display Content text.
 for q in root:
  ident=q.get('id');t=tc.get(ident)
  if t is None or any(q.get(k)!=t.get(k) for k in ['type','town','giver','finisher','subtype']):continue
  path,n=quest_nodes[ident];value=t.get('subject');prior=q.get('subject','')
  if value and value!=prior and valid_text(prior,value) is None and not re.search('[\uac00-\ud7af]',value):
   opening=raw[n['start']:n['open_end']];new,count=re.subn(rb'(\bsubject=)(["\'])(.*?)\2',lambda m:m[1]+m[2]+esc(value)+m[2],opening);assert count==1
   edits.append((n['start'],n['open_end'],new));approved[(path,'subject')]=value;changes.append({'quest':ident,'field':'subject'})
  for leaf in q.findall('Contents/Content'):
   ds=[x for x in t.findall('Contents/Content') if x.get('id')==leaf.get('id')]
   if len(ds)!=1 or len(leaf) or len(ds[0]):continue
   old=leaf.text or '';new=(ds[0].text or '').replace('\u318d','\u00b7')
   if new==old:continue
   if valid_text(old,new) or re.search('[\uac00-\ud7af]',new) or re.findall(r'\d+',old)!=re.findall(r'\d+',new):skips.append({'quest':ident,'content':leaf.get('id'),'reason':'text-format-or-numeric-display-difference'});continue
   lp,ln=content_nodes[(path,leaf.get('id'))];edits.append((ln['open_end'],ln['close_start'],esc(new)));approved[(lp,'text')]=new;changes.append({'quest':ident,'content':leaf.get('id'),'field':'text'})
 out=raw
 for start,end,b in sorted(edits,reverse=True):out=out[:start]+b+out[end:]
 after=index_xml(out);assert ix.keys()==after.keys()
 for path,a in ix.items():
  b=after[path];expected=dict(a['attrs'])
  if (path,'subject') in approved:expected['subject']=approved[(path,'subject')]
  assert b['attrs']==expected and b['text']==approved.get((path,'text'),a['text']) and b['children']==a['children']
 for ident in ['119','120','121']:
  q=next(n for n in E.fromstring(out) if n.get('id')==ident);assert not re.search('[\uac00-\ud7af]',q.get('subject',''))
 assert next(n for n in E.fromstring(out) if n.get('id')=='120').get('level')=='8'
 return out,changes,skips

def build():
 for f,h in PINS.items():assert sha((R/f).read_bytes())==h,('Source identity',f)
 tcp=R.parent/'tc_workspace/Table.stp';assert sha(tcp.read_bytes())==TC_SHA
 protected={str(p.relative_to(R)):sha(p.read_bytes()) for folder in [R,R/'TC_UI',R/'UI',R/'UI/Font'] for p in folder.iterdir() if p.is_file() and p.suffix.lower() in {'.exe','.bin','.stp','.dll','.gms','.flu','.ttf','.xml','.ini','.cfg'}}
 ui=Archive(R/'UI/StringTable.stp');tcui=Archive(R/'TC_UI/StringTable.stp');table=Archive(R/'TC_UI/Table.story-zh-tw-v5.stp');tc=Archive(tcp)
 fcs,fc,fs=fcs_overlay(ui.read('StringTable/English(United States).FCS'),tcui.read('StringTable/Chinese(Taiwan).FCS'))
 uibytes=pack_archive(ui,{'StringTable/English(United States).FCS':fcs})
 quest,qc,qs=quest_overlay(table.read('Table/QuestInfo.xml'),tc.read('Table/QuestInfo.xml'))
 source=(R/'Tartaros.ip-zh-tw-v7.exe').read_bytes();image=bytearray(source);pe=PE(R/'Tartaros.ip-zh-tw-v7.exe');allowed=set();patches=[]
 at=source.index(b'Table/QuestInfo.xml\0');old=b'Table/QuestInfo.xml';new=b'TC_UI/QuestTxt8.xml';assert len(old)==len(new) and source.count(old+b'\0')==1
 image[at:at+len(old)]=new;allowed.update(range(at,at+len(old)));patches.append({'kind':'quest-display-path','offset':hex(at),'before':old.decode(),'after':new.decode()})
 krnames=['소마','핑코&탱이','슈발만','이실리아','아엘로트','그래니트','크로모도','루코','엘핀도스'];actors=E.fromstring(tc.read('Table/_ActorList.xml'));cat=next(n for n in actors.iter('OBJCATEGORY') if n.get('ID')=='0')
 kractors=E.fromstring(table.read('Table/_ActorList.xml'));krcat=next(n for n in kractors.iter('OBJCATEGORY') if n.get('ID')=='0')
 names=[]
 for i,old in enumerate(krnames,1):
  donor=next(n for n in cat if n.get('ID')==str(i) and n.get('PRE')=='1');assert next(n for n in krcat if n.get('ID')==str(i)).get('FILE')==donor.get('FILE');new=donor.get('NAME');prior=old.encode('utf-16le');assert len(new.encode('utf-16le'))<=len(prior)
  assert source.count(prior+b'\0\0')==1;at=source.index(prior+b'\0\0');b=new.encode('utf-16le')+bytes(len(prior)-len(new.encode('utf-16le')))
  image[at:at+len(prior)]=b;allowed.update(range(at,at+len(prior)));names.append({'role':i,'before':old,'after':new,'offset':hex(at),'sourceFile':donor.get('FILE')})
 # Translation pre-loader. Mount a new U8/StringTable archive BEFORE the existing
 # locale13 baseline loads; redirect only its writable custom path after success.
 hdr=struct.unpack_from('<I',source,60)[0];opt=hdr+24;assert not struct.unpack_from('<H',source,opt+70)[0]&0x40,'Absolute translation wrapper requires pinned non-ASLR build';count=struct.unpack_from('<H',source,hdr+6)[0];tab=opt+struct.unpack_from('<H',source,hdr+20)[0];slot=tab+count*40
 assert slot+40<=struct.unpack_from('<I',source,opt+60)[0] and source[slot:slot+40]==bytes(40)
 sa,fa=struct.unpack_from('<II',source,opt+32);align=lambda n,a:(n+a-1)//a*a
 rva=align(max(s['va']-pe.base+max(s['virtualSize'],s['size']) for s in pe.sections),sa);raw=align(len(source),fa);start=pe.base+rva
 baseline=0x1048780;assert pe.read(baseline,90).startswith('UI/StringTable/English(United States).FCS\0'.encode('utf-16le'))
 payload=bytearray();labels={};fix=[]
 def emit(h):payload.extend(bytes.fromhex(h))
 def mark(n):labels[n]=start+len(payload)
 def ptr(n):fix.append((len(payload),n,False));payload.extend(bytes(4))
 def jump(op,n):emit(op);fix.append((len(payload),n,True));payload.extend(bytes(4))
 def call(a):emit('e8');payload.extend(struct.pack('<i',a-(start+len(payload)+4)))
 # GetFileAttributesA reuses the pinned import referenced by existing TC loader.
 oldloader=0x1049000;loaderbytes=pe.read(oldloader,80);pos=loaderbytes.index(bytes.fromhex('ff15'));getattrs=struct.unpack_from('<I',loaderbytes,pos+2)[0]
 mark('preload');emit('9c60 a1 14a8fb00 85c0');jump('0f84','done')
 emit('68');ptr('disk');emit('ff15');payload.extend(struct.pack('<I',getattrs));emit('83f8ff');jump('0f84','done')
 emit('a1 14a8fb00 8d4804 68');ptr('folder');call(0x714d50);emit('8bc8 68');ptr('leaf');call(0x714d50)
 emit('8bf8 68 78010000');call(0x891268);emit('83c404 85c0');jump('0f84','done')
 emit('50');call(0x715270);emit('8bd8 ba');ptr('prefix');emit('8bcb 6a01');call(0x715620);emit('85c0');jump('0f85','failed')
 emit('899f00010000 c705');ptr('baseline_pointer');ptr('translated_baseline');jump('e9','done')
 mark('failed');emit('8bcb 6a01');call(0x715350)
 mark('done');emit('619d e9');payload.extend(struct.pack('<i',oldloader-(start+len(payload)+4)))
 mark('baseline_dispatch');emit('8b0d');ptr('baseline_pointer');emit('e9');payload.extend(struct.pack('<i',0x75f030-(start+len(payload)+4)))
 mark('code_end')
 for name,text in [('disk','U8/StringTable.stp'),('folder','U8'),('leaf','StringTable'),('prefix','U8/StringTable')]:mark(name);payload.extend(text.encode()+b'\0')
 while len(payload)%4:emit('00')
 mark('baseline_pointer');payload.extend(struct.pack('<I',baseline))
 mark('translated_baseline');payload.extend('U8/StringTable/English(United States).FCS\0'.encode('utf-16le'))
 for at,label,rel in fix:struct.pack_into('<i' if rel else '<I',payload,at,labels[label]-start-at-4 if rel else labels[label])
 code=payload[:labels['code_end']-start];ins=list(Cs(CS_ARCH_X86,CS_MODE_32).disasm(code,start));assert sum(i.size for i in ins)==len(code)
 addresses={i.address for i in ins}
 for i in ins:
  if i.mnemonic.startswith('j') and i.op_str.startswith('0x'):
   target=int(i.op_str,16);assert target in [oldloader,0x75f030] or target in addresses
 site=0x58894d;at=pe.offset(site);assert source[at]==0xe8 and site+5+struct.unpack_from('<i',source,at+1)[0]==oldloader
 image[at:at+5]=b'\xe8'+struct.pack('<i',start-site-5);allowed.update(range(at,at+5))
 dispatch_site=0x1045000;at=pe.offset(dispatch_site)
 assert source[at:at+5]==b'\xb9'+struct.pack('<I',baseline)
 image[at:at+5]=b'\xe9'+struct.pack('<i',labels['baseline_dispatch']-dispatch_site-5);allowed.update(range(at,at+5))
 assert bytes(image[pe.offset(baseline):pe.offset(baseline)+84])==pe.read(baseline,84),'Original readonly path must remain unchanged'
 size=align(len(payload),fa);image[slot:slot+40]=struct.pack('<8sIIIIIIHHI',b'.tctx9\0\0',len(payload),rva,size,raw,0,0,0,0,0xe0000060)
 struct.pack_into('<H',image,hdr+6,count+1);struct.pack_into('<I',image,opt+56,align(rva+len(payload),sa));struct.pack_into('<I',image,opt+64,0)
 allowed.update(range(slot,slot+40));allowed.update(range(hdr+6,hdr+8));allowed.update(range(opt+56,opt+60));allowed.update(range(opt+64,opt+68))
 image.extend(bytes(raw-len(image)));image.extend(payload);image.extend(bytes(size-len(payload)))
 diffs=[i for i,(a,b) in enumerate(zip(source,image)) if a!=b];assert set(diffs)<=allowed
 qmap={q.get('id'):q for q in E.fromstring(quest)}
 text=''.join(''.join(x['after']) for x in fc)+''.join(x['after'] for x in names)
 for change in qc:
  q=qmap[change['quest']]
  text+=q.get('subject','') if change['field']=='subject' else next(n for n in q.findall('Contents/Content') if n.get('id')==change['content']).text or ''
 needed={ord(c) for c in text if not c.isspace() and ord(c)>31};font=[]
 for f in ['v4jh.ttf','v4jhbd.ttf']:
  missing=needed-cmap(R/'UI/Font'/f);assert not missing,('Font coverage',f,[hex(x) for x in sorted(missing)]);font.append({'name':f,'sha256':sha((R/'UI/Font'/f).read_bytes()),'missing':0})
 outputs={'U8/StringTable.stp':uibytes,'TC_UI/QuestTxt8.xml':quest,'Tartaros.ip-zh-tw-v9.exe':bytes(image)}
 for f,b in outputs.items():immutable(R/f,b)
 a=Archive(R/'U8/StringTable.stp');assert a.files==ui.files
 for m in ui.files:assert a.read(m)==(fcs if m=='StringTable/English(United States).FCS' else ui.read(m))
 for f,h in protected.items():assert sha((R/f).read_bytes())==h,('Existing file changed',f)
 assert sha(tcp.read_bytes())==TC_SHA
 manifest={'schema':'ZH_TW_V9_TRANSLATION_ONLY','sourcePins':PINS,'taiwanTableSha256':TC_SHA,'outputs':[{'path':f,'sha256':sha(b),'bytes':len(b)} for f,b in outputs.items()],
 'fcs':{'translatedRows':len(fc),'changes':fc,'skips':fs,'locale13AndAllCodeClassAndStructurePreserved':True,'punctuationNormalization':'Taiwan U+318D bullet -> U+00B7 middle dot for existing approved font coverage'},'quests':{'displayChanges':len(qc),'changes':qc,'skips':qs,'allNonDisplayValuesUnchanged':True,'quest120Level':8},
 'speakers':names,'exe':{'preloaderEntry':hex(start),'oldLoader':hex(oldloader),'baselinePathVa':hex(baseline),'baselinePointerVa':hex(labels['baseline_pointer']),'translatedBaselinePathVa':hex(labels['translated_baseline']),'baselineDispatchSite':hex(dispatch_site),'baselineDispatchEntry':hex(labels['baseline_dispatch']),'runtimeWritesOnlyToOwnWritablePointer':True,'hookSite':hex(site),'allowedChanges':patches,'sourceDiffOffsets':[hex(i) for i in diffs],'onlyTranslationHookDataAndPEAppendChanged':True,'preloaderInstructions':[{'va':hex(i.address),'bytes':i.bytes.hex(),'instruction':i.mnemonic+' '+i.op_str} for i in ins]},
 'fonts':font,'preservedExistingFiles':protected,'originalResourcesUnchanged':True,'gameExecutedOrAttached':False,'runtime':'PENDING_USER','limitations':['New translation mount/lookup path requires human display verification.','Unmatched quest IDs/text/numeric differences retain KR.','No XP/level/rewards/gameplay fix included.','Font coverage is checked for newly introduced translations; unmatched original Korean fields retain existing v7 fallback/glyph limitations.']}
 d=R/'CLIENT/evidence/20261108-variant-v9';d.mkdir(parents=True,exist_ok=True);(d/'build-manifest.json').write_bytes((json.dumps(manifest,ensure_ascii=False,indent=2)+'\n').encode())
 print(json.dumps({'outputs':manifest['outputs'],'fcsRows':len(fc),'questDisplayChanges':len(qc),'speakers':len(names),'runtime':'PENDING_USER'}))
if __name__=='__main__':build()
