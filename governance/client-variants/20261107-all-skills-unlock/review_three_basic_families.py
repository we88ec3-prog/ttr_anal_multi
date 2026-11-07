"""11 exact basic clips and three named skill hypotheses, no animation assignment."""
from pathlib import Path
import sys,json,re,hashlib,collections,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:\Tartaros\workspace');O=R.parent/'origin';TC=R.parent/'tc_workspace';D=R/'runtime-observations/2026-11-05-all-skills'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();arcs={};sources={}
j=json.loads((D/'all-role-motion-joins.json').read_text(encoding='utf-8'));cat=json.loads((D/'all-skills-catalog.json').read_text(encoding='utf-8'))
def read(kind,carrier,member):
 key=(kind,carrier)
 if key not in arcs:arcs[key]=Archive((O if kind=='KR' else TC)/carrier)
 b=arcs[key].read(member);row={'kind':kind,'carrier':carrier,'member':member,'sha256':sha(b)}
 if kind=='KR':
  wk=('WORK',carrier)
  if wk not in arcs:arcs[wk]=Archive(R/carrier)
  w=arcs[wk].read(member);assert b==w;row.update(workingSha256=sha(w),workingEqual=True)
 sources[(kind,carrier,member)]=row;return b
def xml(b,fragment=False):
 text=b.decode('euc-kr' if b'euc-kr' in b[:150].lower() else 'utf-8-sig');text=re.sub(r'^\s*<\?xml[^?]*\?>','',text)
 return E.fromstring('<ROOT>'+text+'</ROOT>' if fragment else text)
def canonical(n):return {'tag':n.tag,'attributes':{k:v for k,v in n.attrib.items() if not(n.tag=='AnimationHeader' and k in ['ID','NAME'])},'text':(n.text or '').strip(),'tail':(n.tail or '').strip(),'children':[canonical(x) for x in n]}
active=xml(read('KR','Table.stp','Table/SkillActiveTable.xml'));explain={kind:xml(read(kind,'Table.stp','Table/skillexplaintable.xml')) for kind in ['KR','TC']};groups=[]
for rid,aid,pid,stem,count in [(2,10,17,'pipa_punch',5),(5,38,65,'aelt_shadow',5),(7,332,97,'crmd_attack',1)]:
 role=next(r for r in j['roles'] if r['role']==rid);read('KR','Character/Cha/Base.stp',role['abf_member'])
 p=next(p for p in cat['practices'] if p['id']==pid and p['role']==rid);assert Path(p['source']).stem.casefold()==stem
 pt=xml(read('KR','Table.stp',p['source']));pn=next(n for n in pt if n.get('ID')==str(pid));mods=[dict(n.attrib) for n in pn.findall("LevelData[@Level='1']/Modifiers/Modifier")];assert any(m.get('Type')=='SkillLevel' and m.get('TargetSkillID')==str(aid) for m in mods)
 a=next(n for n in active if n.get('no')==str(aid));descs=[]
 for kind,et in explain.items():
  node=next(n for n in et if n.get('no')==str(aid));s=''.join(node.find('EXPLAIN').itertext());descs.append({'kind':kind,'textSha256':sha(s.encode('utf-8')),'shortText':s[:180]})
 clips=[]
 for index in range(1,count+1):
  matches=[m for m in role['motion_metadata'] if re.fullmatch('[A-Za-z]+_SKILL01_'+f'{index:02}'+r'\.asd',m['abf_file'],re.I)];assert len(matches)==1;m=matches[0]
  raw=read('KR',m['asd_carrier'],m['asd_member']);assert sha(raw)==m['asd_sha256'];t=xml(raw,True);h=t.find('.//AnimationHeader');effects=[]
  for e in m['effects']:
   eb=read('KR','Effect/Effect.stp',e['path']);assert sha(eb)==e['sha256'];et=xml(eb);variant=re.search(r'-(Basis|Average|Exper|Master|Super)',e['path'],re.I)
   effects.append({'member':e['path'],'sha256':sha(eb),'explicitVariantLabel':variant[1] if variant else None,'header':dict(et.find('Header').attrib),'elementCount':len(et.findall('.//Element')),'elements':[{'attributes':dict(n.attrib),'children':[{'tag':x.tag,'attributes':dict(x.attrib)} for x in n]} for n in et.findall('.//Element')],'objectReferences':sorted({n.get('File') for n in et.iter() if n.get('File')}),'attachFlags':dict(collections.Counter(n.get('isAttach','UNDECLARED') for n in et.findall('.//Element'))),'explicitSkillOrProjectileFields':[{'tag':n.tag,'attribute':k,'value':v} for n in et.iter() for k,v in n.attrib.items() if re.search('skillid|activeid|practiceid|projectile|velocity|target|trajectory|homing',k,re.I)]})
  sig={'ASD':canonical(t),'ABFLength':m['abf_length_frame_units'],'headerMatchesAbf':m['header_matches_abf']}
  clips.append({'motion':m['motion_id'],'abfFile':m['abf_file'],'asdMember':m['asd_member'],'asdSha256':sha(raw),'header':dict(h.attrib),'animationData':dict(h.find('AnimationData').attrib),'splitData':[dict(n.attrib) for n in h.findall('ReferIndex/SpliteData')],'abfLengthFrameUnits':m['abf_length_frame_units'],'timingAuthority':'RAW_FRAMES_FPS_DELAY_ONLY','soundReferences':[dict(n.attrib) for n in h.findall('Sound')],'effects':effects,'equivalenceSha256':sha(json.dumps(sig,sort_keys=True,separators=(',',':')).encode())})
 byhash=collections.defaultdict(list)
 for clip in clips:byhash[clip['equivalenceSha256']].append(clip['motion'])
 groups.append({'role':rid,'active':aid,'practice':pid,'practiceMember':p['source'],'practiceAttributes':dict(pn.attrib),'LEVEL1Modifiers':mods,'activeAttributes':dict(a.attrib),'activeLEVEL1':[{'tag':n.tag,'attributes':dict(n.attrib)} for n in a.find("LEVEL[@val='1']")],'shortDescriptions':descs,'clips':clips,'equivalentMotionGroups':list(byhash.values()),'allClipsRepeatFalse':all(cl['animationData'].get('Repeat')=='false' for cl in clips),'officialMapping':'UNRESOLVED','selectedMotion':None,'comboOrder':'NOT_PROVEN_BY_NUMERIC_SUFFIX_OR_COUNTER','resourceRelation':'Role-specific SKILL01/BasisAttack or BasisFireball family; Practice name does not explicitly declare these action IDs.','isolatedServerOwnedPolicyRequirements':['Root must explicitly accept this named role/Practice/active to listed resource family hypothesis for lab comparison.','Show Server-owned candidate and officialmapping unresolved labels; not generic101 or same-key proof.','For multi-clip families, per-clip comparison does not establish combo order, timing/cancel/impact, transition or reset policy.','For Crmd single clip, unique file plus Fireball label does not establish projectile launch/target/flight/hit protocol.','No arbitrary min-motion or cross-role borrowing; no normal skill completion claimed from animation playback.'],'applied':False})
for g in groups:
 g['counterInterpretation']='Counter is a raw AnimationData value, not asserted as hit count, combo index or number of damage events.'
 g['descriptionComparison']={2:{'support':'KR/TC both say Tanky punches nearby enemies and applies brief stun. BasisAttack effects attach=1, with LeaveBlunt and impact/ground effect references, are a reviewable role-specific visual comparison.','unknown':'No Practice punch->SKILL01 action ID declaration; hit count/timing, area and stun are not proved by the five clips.'},5:{'support':'KR/TC describe a sword formation/magic circle attacking front enemies and suppressing physical attack skills. All five explicit EFF include U3_FE_IndicationShadow_CenterScaleA_A01b.gb3, an additional Shadow word token matching Practice aelt_shadow.','unknown':'A Shadow-labelled effect component is stronger naming evidence but still does not declare active38/action mapping. All clips differ; Counter3 on last clip is not adopted as three hits.'},7:{'support':'KR/TC explicitly describe flame pillars attacking enemies along a line in front. Single clip references BasisFireball effect, whose components include BurstCrush_UpScale and SpoutSpring_UpScale.','unknown':'Fireball EFF name does not prove a flying fireball entity; description specifies flame pillar/line. Counter2 is not adopted as two hits or two projectiles. Unique role-local file is not official active332->motion101 proof.'}}[g['role']]
out={'schema':'TARTAROS_THREE_ROLE_BASIC_RESOURCE_REVIEW_V1','groups':groups,'sourceMembers':list(sources.values()),'summary':{'groups':3,'clips':sum(len(g['clips']) for g in groups),'originalWorkingComparisons':sum(s['kind']=='KR' for s in sources.values()),'newOfficialMappings':0},'limitations':['Exactly11 specified clips and explicit EFF, three ABF identities and exact Practice/Active/Explanation rows; no new matrix scan.','No timing formula adopted; Counter/Repeat/split data retained as raw fields.','No game execution/attach, provider retry, MEF search, Client/Server/Host/shared changes or Git commit.']}
p=D/'three-basic-resource-family-review.json';p.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');print(json.dumps({'file':str(p),'sha256':sha(p.read_bytes()),'summary':out['summary'],'groups':[(g['role'],g['active'],[(cl['motion'],cl['animationData'].get('Repeat'),cl['animationData'].get('Counter')) for cl in g['clips']]) for g in groups]}))
