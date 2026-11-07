"""Bounded active6/lightningball vs ELECTRIC family comparison; no applied alias."""
from pathlib import Path
import sys,json,re,hashlib,collections,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:\Tartaros\workspace');O=R.parent/'origin';TC=R.parent/'tc_workspace';D=R/'runtime-observations/2026-11-05-all-skills'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();arcs={};sources={}
j=json.loads((D/'all-role-motion-joins.json').read_text(encoding='utf-8'));role=j['roles'][0];assert role['role']==1
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
 s=b.decode('euc-kr' if b'euc-kr' in b[:150].lower() else 'utf-8-sig');s=re.sub(r'^\s*<\?xml[^?]*\?>','',s)
 return E.fromstring('<ROOT>'+s+'</ROOT>' if fragment else s)
def canonical(n):return {'tag':n.tag,'attributes':{k:v for k,v in n.attrib.items() if not(n.tag=='AnimationHeader' and k in ['ID','NAME'])},'text':(n.text or '').strip(),'tail':(n.tail or '').strip(),'children':[canonical(x) for x in n]}
read('KR','Character/Cha/Base.stp','Cha/Soma.abf');clips=[]
for mid in [114,130,140]:
 m=next(m for m in role['motion_metadata'] if m['motion_id']==mid);b=read('KR',m['asd_carrier'],m['asd_member']);assert sha(b)==m['asd_sha256'];t=xml(b,True);h=t.find('.//AnimationHeader');fx=[]
 for e in m['effects']:
  eb=read('KR','Effect/Effect.stp',e['path']);assert sha(eb)==e['sha256'];et=xml(eb);v=re.search(r'-(Basis|Average|Exper|Master|Super)',e['path'],re.I)
  fx.append({'member':e['path'],'sha256':sha(eb),'explicitVariantLabel':v[1] if v else None,'header':dict(et.find('Header').attrib),'elements':[{'tag':n.tag,'attributes':dict(n.attrib),'children':[{'tag':x.tag,'attributes':dict(x.attrib)} for x in n]} for n in et.findall('.//Element')],'declaredObjectFiles':sorted({n.get('File') for n in et.iter() if n.get('File')}),'attachFlags':dict(collections.Counter(n.get('isAttach','UNDECLARED') for n in et.findall('.//Element'))),'explicitSkillOrProjectileFields':[{'tag':n.tag,'attribute':k,'value':v} for n in et.iter() for k,v in n.attrib.items() if re.search('skillid|activeid|practiceid|projectile|velocity|target|trajectory|homing',k,re.I)]})
 sig={'ASD':canonical(t),'ABFLength':m['abf_length_frame_units'],'headerMatchesAbf':m['header_matches_abf']}
 clips.append({'motion':mid,'abfFile':m['abf_file'],'asdMember':m['asd_member'],'asdSha256':sha(b),'header':dict(h.attrib),'animationData':dict(h.find('AnimationData').attrib),'splitData':[dict(n.attrib) for n in h.findall('ReferIndex/SpliteData')],'abfLengthFrameUnits':m['abf_length_frame_units'],'timingAuthority':'RAW_FRAMES_FPS_DELAY; no new timing formula','soundReferences':[dict(n.attrib) for n in h.findall('Sound')],'effects':fx,'equivalenceSha256':sha(json.dumps(sig,sort_keys=True,separators=(',',':')).encode())})
table=[]
active=xml(read('KR','Table.stp','Table/SkillActiveTable.xml'));explain={kind:xml(read(kind,'Table.stp','Table/skillexplaintable.xml')) for kind in ['KR','TC']}
for ident,member in [(6,'Table/Skill/Active/soma_lightningball.xml'),(5,'Table/Skill/Active/soma_chain.xml')]:
 pt=xml(read('KR','Table.stp',member));p=next(n for n in pt if n.get('ID')==str(ident));lev=p.find("LevelData[@Level='1']");mods=[dict(n.attrib) for n in lev.findall('Modifiers/Modifier')];assert any(n.get('Type')=='SkillLevel' and n.get('TargetSkillID')==str(ident) for n in lev.findall('Modifiers/Modifier'))
 a=next(n for n in active if n.get('no')==str(ident));summaries=[]
 for kind,et in explain.items():
  ex=next(n for n in et if n.get('no')==str(ident));text=''.join(ex.find('EXPLAIN').itertext());summaries.append({'kind':kind,'textSha256':sha(text.encode('utf-8')),'shortText':text[:200]})
 table.append({'practice':ident,'active':ident,'practiceMember':member,'practiceAttributes':dict(p.attrib),'LEVEL1Modifiers':mods,'activeAttributes':dict(a.attrib),'activeLEVEL1':[{'tag':n.tag,'attributes':dict(n.attrib)} for n in a.find("LEVEL[@val='1']")],'explanations':summaries})
excluded=[{'motion':m['motion_id'],'abfFile':m['abf_file'],'asdSha256':m['asd_sha256'],'effects':m['effects']} for m in role['motion_metadata'] if re.fullmatch(r'Soma_LIGHTNING\d+_\d+\.asd',m['abf_file'],re.I)]
groups=collections.defaultdict(list)
for cl in clips:groups[cl['equivalenceSha256']].append(cl['motion'])
out={'schema':'TARTAROS_SOMA_ACTIVE6_ELECTRIC_FAMILY_REVIEW_V1','role':1,'practice':6,'active':6,'clips':clips,'tableComparison':table,'sourceMembers':list(sources.values()),'excludedLIGHTNINGFamilyFromPinnedPriorMetadata':{'sourceFile':'all-role-motion-joins.json','sha256':sha((D/'all-role-motion-joins.json').read_bytes()),'rows':excluded,'relation':'LIGHTNING multi-clip family already separately associated with active5 soma_chain as resource naming candidate; not reused for active6.'},'videoEvidenceReceivedFromParent':{'status':'PARENT_OBSERVATION_NOT_REVIEWED_BY_THIS_AGENT','active6':{'video':'gQIwpnFx-Ac','durationSeconds':3.421,'reportedObservation':'1.01s hands gather blue ball overhead; 2.3567s blue light at front enemy plus damage numbers'},'comparisonActive3':{'video':'UdAiM3CAN9I','reportedObservation':'large frontal blue ground ring'},'limitation':'These summaries differentiate observed visuals but do not label internal animation IDs or establish projectile protocol.'},'equivalentMotionGroups':list(groups.values()),'uniqueBasisResourceMotion':114,'allClipsRepeatFalse':all(c['animationData'].get('Repeat')=='false' for c in clips),'officialActive6ToMotion':'UNRESOLVED','selectedMotion':None,'applied':False,'serverOwnedCandidateBoundary':{'status':'ROOT_MAY_EXPLICITLY_ACCEPT_ROLE1_ACTIVE6_LIGHTNINGBALL_TO_ELECTRIC_BASIS_HYPOTHESIS_FOR_ISOLATED_LAB','candidateMotion':114,'whyReviewable':'One explicit BasisLighting effect variant in the role-specific ELECTRIC family and the separately labelled active6 visual observation; no minimum-ID rule used.','notProved':['Practice lightningball→ELECTRIC is a semantic/resource-family hypothesis, not a declared active alias.','EFF spelling Lighting and ASD ELECTRIC are distinct from LIGHTNING/Chain; do not merge these names globally.','Visual effects do not establish moving projectile identity/opcode, launch frame, target, trajectory, hit timing or damage.','Root acceptance creates a Server-owned test policy and does not close officialmapping or normal skill acceptance.']},'limitations':['Only3 specified ASD and their3 explicit EFF plus exact Practice5/6 and Active/Explanation5/6 entries read; prior LIGHTNING metadata not reread.','No broad resource scan, MEF search, Client/Server/Host/shared modification, target execution/attach, REA/provider retry or Git commit.']}
out['descriptionComparison']={'active6':'KR/TC both describe a ranged punch/electric ball with electric-shock debuff reducing movement and continuously reducing SP; KR requires one charge-button press, TC explicitly V charge stage1.','active5':'KR/TC describe electrical attack/waves against multiple enemies in front, with electric-shock debuff.','support':'Parent reports active6 raised-hands blue-ball visual and distinct frontal ring for active3; this supports a separately reviewable family hypothesis, not motion identity.','normalGameplayUnresolved':['V stage1 admission and successful consumption/reset','ranged projectile producer, flight/target and once-only impact','electric-shock probability, duration and SP-drain tick policy'],'labPolicy':'If charge gate is bypassed for isolated visual inspection, name it as a test-policy bypass; do not count as normal skill verification.'}
p=D/'soma-active6-electric-family-review.json';p.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');print(json.dumps({'file':str(p),'sha256':sha(p.read_bytes()),'motions':[c['motion'] for c in clips],'groups':list(groups.values()),'allRepeatFalse':out['allClipsRepeatFalse']}))
