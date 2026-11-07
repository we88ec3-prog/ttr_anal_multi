"""Exactly six Soma basic clips, their EFF and six relevant table records."""
from pathlib import Path
import sys,json,re,hashlib,collections,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:\Tartaros\workspace');O=R.parent/'origin';TC=R.parent/'tc_workspace';D=R/'runtime-observations/2026-11-05-all-skills'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();arcs={};sources=[]
def read(kind,carrier,member):
 key=(kind,carrier)
 if key not in arcs:arcs[key]=Archive((O if kind=='KR' else TC)/carrier)
 b=arcs[key].read(member);row={'kind':kind,'carrier':carrier,'member':member,'sha256':sha(b)}
 if kind=='KR':
  wk=('WORK',carrier)
  if wk not in arcs:arcs[wk]=Archive(R/carrier)
  w=arcs[wk].read(member);row['workingSha256']=sha(w);row['workingEqual']=b==w;assert b==w
 sources.append(row);return b
def parse(b,fragment=False):
 text=b.decode('euc-kr' if b'euc-kr' in b[:150].lower() else 'utf-8-sig');text=re.sub(r'^\s*<\?xml[^?]*\?>','',text)
 return E.fromstring('<ROOT>'+text+'</ROOT>' if fragment else text)
rows=[]
for i in range(1,7):
 am=f'01_Soma/Asd/Soma_SKILL01_{i:02}.asd';raw=read('KR','Character/Cha/Avatar/01_Soma.stp',am);t=parse(raw,True);h=t.find('.//AnimationHeader');effects=[]
 for ef in h.findall('Effect'):
  path=ef.get('Folder').replace('\\','/')+ef.get('File');eb=read('KR','Effect/Effect.stp',path);et=parse(eb)
  elements=[]
  for n in et.findall('.//Element'):
   elements.append({'attributes':dict(n.attrib),'children':[{'tag':c.tag,'attributes':dict(c.attrib)} for c in n]})
  names=sorted({n.get('File') for n in et.iter() if n.get('File')});fields=collections.Counter(k for n in et.iter() for k in n.attrib)
  explicit=[{'tag':n.tag,'attribute':k,'value':v} for n in et.iter() for k,v in n.attrib.items() if re.search(r'projectile|missile|velocity|target|skillid|actorid|launch|trajectory|homing|pball',k+'='+v,re.I) or k.casefold()=='speed']
  effects.append({'member':path,'sha256':sha(eb),'header':dict(et.find('Header').attrib),'elementCount':len(elements),'attributeNames':dict(fields),'declaredObjectFiles':names,'attachFlags':dict(collections.Counter(n.get('isAttach','UNDECLARED') for n in et.findall('.//Element'))),'elements':elements,'explicitProjectileOrSkillIdReferences':explicit})
 rows.append({'motion':int(h.get('ID')),'asdMember':am,'asdSha256':sha(raw),'header':dict(h.attrib),'animationData':dict(h.find('AnimationData').attrib),'referIndex':[dict(n.attrib) for n in h.findall('ReferIndex/SpliteData')],'soundReferences':[dict(n.attrib) for n in h.findall('Sound')],'effects':effects})
records=[]
specs=[('KR','Table/SkillActiveTable.xml','no','1'),('KR','Table/Skill/Active/soma_pball.xml','ID','1'),('KR','Table/skillexplaintable.xml','no','1'),('TC','Table/skillexplaintable.xml','no','1'),('KR','Table/PracticeExplainTable.xml','ID','1'),('TC','Table/PracticeExplainTable.xml','ID','1')]
for kind,member,k,val in specs:
 b=read(kind,'Table.stp',member);root=parse(b);node=next(n for n in root if n.get(k)==val)
 record={'kind':kind,'member':member,'entrySelector':{k:val},'entryTag':node.tag,'entryAttributes':dict(node.attrib),'entryCanonicalSha256':sha(E.tostring(node,encoding='utf-8'))}
 if member.endswith('SkillActiveTable.xml'):
  record['LEVEL1']=[{'tag':n.tag,'attributes':dict(n.attrib)} for n in node.find("LEVEL[@val='1']")]
  record['numericEnumInterpretation']='type1/form2/attribute4 are exact raw classifications; names/meaning require independent enum proof.'
 elif 'soma_pball' in member:
  record['LEVEL1']=[{'tag':n.tag,'attributes':dict(n.attrib),'children':[{'tag':x.tag,'attributes':dict(x.attrib)} for x in n]} for n in node.find("LevelData[@Level='1']")]
 else:
  explain=''.join(node.find('EXPLAIN' if 'skillexplain' in member else 'Explain').itertext())
  record['explanationSha256']=sha(explain.encode('utf-8'));record['explanationCharacters']=len(explain)
  record['semanticSummary']='TC Skill1 explicitly describes punching to launch electric balls, with electric-shock additional effect lowering movement speed and continuously reducing SP.' if kind=='TC' and 'skillexplain' in member else 'Explanation retained as source hash; not substituted for motion/projectile protocol.'
 records.append(record)
result={'schema':'TARTAROS_SOMA_BASIC_Z_PROJECTILE_RESOURCE_BOUNDARY_V1','scope':'6 exact Soma_SKILL01 ASD + their 6 explicitly declared EFF + 6 exact table records; no archive or projectile asset search','clips':rows,'tableRecords':records,'sourceMembers':sources,
 'review':{'resourceFacts':['Soma_SKILL01_01..06 declare IDs101..106 and C_Soma-BasisAttack01..06 EFF respectively.','EFF are composite visual elements with Delay/Scale/FrameSpeedRatio/isAttach/RepeatCount/File and position/rotation fields; these fields alone do not define an authoritative projectile entity, damage, velocity, range or collision.','Practice1 LEVEL1 SkillLevel grants active1. KR Active1 classifications are type1/form2/attribute4, with zero HP/SP/MP raw cost and zero cooldown.','TC skill1 explanation explicitly describes emitted electric balls; this establishes described skill behavior, not a wire motionID mapping.'],
 'officialActive1ToMotion101_106':'UNRESOLVED; no activeID/pball reference in the reviewed ASD/EFF binding fields.',
 'serverOwnedLabCandidate':{'reviewable':True,'status':'PROPOSAL_ONLY_NOT_APPLIED_OR_OFFICIAL_MAPPING','inputSkill':{'role':1,'practice':1,'active':1},'candidateClipFamily':[101,102,103,104,105,106],'basis':'Role-specific 6-clip SKILL01 and BasisAttack visual family; separate user-supplied skill-labelled video behavior. This is an explicitly Server-owned hypothesis for isolated comparison, not recovered active-to-motion proof.','requiredBeforeAcceptance':['Root/user must explicitly accept use of the unproven family as a Server-owned isolated lab candidate under current admission rules.','Visually confirm caster pose/electric ball visuals against the labelled reference; no generic101 transfer.','Projectile instance producer, launch time, travel/target/collision and once-only hit/payment remain separately unresolved.'],'selectedMotion':None,'phaseOrder':'NOT_CLOSED; numeric suffixes do not prove combo transitions.'},
 'notAProjectileProducerProof':['EFF isAttach=0 is a visual attachment flag, not evidence of a moving server projectile.','A component named FrontStay/VolleyFlash is a visual filename, not a target/trajectory opcode.','Do not synthesize native projectile packets or claim native projectile AI from composite effect playback.']},
 'summary':{'clips':len(rows),'effects':sum(len(r['effects']) for r in rows),'tableRecords':len(records),'explicitProjectileOrSkillIdReferences':sum(len(e['explicitProjectileOrSkillIdReferences']) for r in rows for e in r['effects']),'newOfficialMappings':0},'limitations':['No Client/Server/Host/shared modifications, game execution/attachment, provider retry, MEF search or Git commit.','No interpretation of raw enum numbers without enum source.','No sound or GB3 content exported or executed; references retained only as metadata.']}
p=D/'soma-basic-projectile-resource-boundary.json';p.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');print(json.dumps({'file':str(p),'sha256':sha(p.read_bytes()),'summary':result['summary']}))
