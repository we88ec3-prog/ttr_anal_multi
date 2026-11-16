"""Three existing component anchors; canonical deltas and explicit slot evidence only."""
from pathlib import Path
import sys,json,re,hashlib,collections,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:\Tartaros\workspace');O=R.parent/'origin';TC=R.parent/'tc_workspace';D=R/'runtime-observations/2026-11-05-all-skills'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();arcs={};sources={}
old=json.loads((D/'numeric-stem-family-review.json').read_text(encoding='utf-8'));previous=json.loads((D/'numeric-family-explicit-link-audit.json').read_text(encoding='utf-8'));cat=json.loads((D/'all-skills-catalog.json').read_text(encoding='utf-8'));pidx={p['id']:p for p in cat['practices']};joins=json.loads((D/'all-role-motion-joins.json').read_text(encoding='utf-8'))
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
def flatten(n,path='',out=None):
 if out is None:out={}
 for k,v in n.attrib.items():
  if not(n.tag=='AnimationHeader' and k in ['ID','NAME']):out[path+'/@'+k]=v
 if (n.text or '').strip():out[path+'/#text']=(n.text or '').strip()
 if (n.tail or '').strip():out[path+'/#tail']=(n.tail or '').strip()
 counts=collections.Counter()
 for child in n:
  index=counts[child.tag];counts[child.tag]+=1;flatten(child,path+'/'+child.tag+'['+str(index)+']',out)
 return out
matrix=xml(read('KR','Table.stp','Table/Skill/Matrix/CharacterMatrices.xml'));active=xml(read('KR','Table.stp','Table/SkillActiveTable.xml'));explain={k:xml(read(k,'Table.stp','Table/skillexplaintable.xml')) for k in ['KR','TC']};groups=[]
for oldg in old['groups']:
 rid,aid,pid=oldg['role'],oldg['active'],oldg['practice'];practice=pidx[pid];pn=next(n for n in xml(read('KR','Table.stp',practice['source'])) if n.get('ID')==str(pid));levels=[{'attributes':dict(ld.attrib),'modifiers':[dict(m.attrib) for m in ld.findall('Modifiers/Modifier')]} for ld in pn.findall('LevelData')];assert any(m.get('Type')=='SkillLevel' and m.get('TargetSkillID')==str(aid) for m in pn.findall("LevelData[@Level='1']/Modifiers/Modifier"))
 slots=[]
 for role in matrix:
  if int(role.get('CharID'))!=rid:continue
  for mx in role.findall('Matrix'):
   matching=[{'tierAttributes':dict(tier.attrib),'keyAttributes':dict(key.attrib)} for tier in mx.findall('KeyInfo/Tier') for key in tier if key.get('skill')==str(aid)]
   if not matching:continue
   builtin=[]
   for decl in mx.findall('BuiltinPracticeList/Practice'):
    bid=int(decl.get('PracticeID'));bp=pidx[bid];bn=next(n for n in xml(read('KR','Table.stp',bp['source'])) if n.get('ID')==str(bid));bl=bn.find("LevelData[@Level='"+decl.get('Level')+"']")
    builtin.append({'declaration':dict(decl.attrib),'practiceMember':bp['source'],'practiceAttributes':dict(bn.attrib),'selectedLevelModifiers':[dict(n.attrib) for n in bl.findall('Modifiers/Modifier')] if bl is not None else None})
   slots.append({'matrixAttributes':dict(mx.attrib),'slots':matching,'builtinPractices':builtin})
 clips=[];baseline=None;baselineid=None
 for oldclip in oldg['clips']:
  md=next(m for role in joins['roles'] if role['role']==rid for m in role['motion_metadata'] if m['motion_id']==oldclip['motion']);b=read('KR',md['asd_carrier'],md['asd_member']);assert sha(b)==oldclip['asdSha256'];root=xml(b,True);h=root.find('.//AnimationHeader');flat=flatten(root)
  if baseline is None:baseline=flat;baselineid=md['motion_id']
  diffs=[{'path':key,'baseline':baseline.get(key),'thisClip':flat.get(key)} for key in sorted(baseline.keys()|flat.keys()) if baseline.get(key)!=flat.get(key)]
  fx=[]
  for e in oldclip['effects']:
   eb=read('KR','Effect/Effect.stp',e['member']);assert sha(eb)==e['sha256'];fx.append(e)
  clips.append({'motion':md['motion_id'],'asdMember':md['asd_member'],'asdSha256':sha(b),'header':dict(h.attrib),'animationData':dict(h.find('AnimationData').attrib),'rawSplits':[dict(n.attrib) for n in h.findall('ReferIndex/SpliteData')],'abfLengthFrameUnits':md['abf_length_frame_units'],'timingAuthority':'RAW_ONLY_NOT_NEW_FORMULA','canonicalFlatSha256':sha(json.dumps(flat,sort_keys=True,separators=(',',':')).encode()),'canonicalComparisonBaselineMotion':baselineid,'baselineIsOnlyForDiffNotSelectedCandidate':True,'canonicalDeltasExcludingHeaderIdName':diffs,'effects':fx})
 a=next(n for n in active if n.get('no')==str(aid));desc=[]
 for kind,et in explain.items():
  n=next(n for n in et if n.get('no')==str(aid));s=''.join(n.find('EXPLAIN').itertext());desc.append({'kind':kind,'sha256':sha(s.encode('utf-8')),'shortText':s[:220]})
 groups.append({'role':rid,'active':aid,'practice':pid,'practiceMember':practice['source'],'practiceAttributes':dict(pn.attrib),'allPracticeLevelModifiers':levels,'activeAttributes':dict(a.attrib),'activeLEVEL1':[{'tag':n.tag,'attributes':dict(n.attrib)} for n in a.find("LEVEL[@val='1']")],'descriptions':desc,'exactMatrixAndBuiltinReferences':slots,'clips':clips,'allClipsNonRepeat':all(cl['animationData'].get('Repeat')=='false' for cl in clips),'existingComponentAnchor':{'stem':oldg['exactComponentStem'],'object':oldg['componentObject'],'confidence':oldg['confidence']},'officialMapping':'UNRESOLVED','selectedMotion':None,'nativeVariantOrPhaseOrder':'UNRESOLVED','labReviewEligibility':'ROOT_EXPLICIT_REVIEW_REQUIRED_FOR_ALL_LISTED_CLIPS; resource comparison set, not established caster binding'})
for g in groups:
 deltas=[d for c in g['clips'] for d in c['canonicalDeltasExcludingHeaderIdName']]
 g['canonicalDeltaSummary']={'onlyEffectAndSoundReferencePathsDiffer':all('/Effect[' in d['path'] or '/Sound[' in d['path'] for d in deltas),'differentPaths':sorted({d['path'] for d in deltas}),'fullClipsEquivalent':False,'interpretation':'All reviewed pose ReferIndex/split/AnimationData fields are equal within each family; full ASD remains non-equivalent due to EFF/sound references. This does not establish native variant selection.'}
 g['descriptionComparison']={3036:{'support':'Both KR/TC describe moving behind the highest-HP front enemy and attacking repeatedly; component Rukoambushes is compatible with an Ambush visual comparison.','unresolved':'Target selection/teleport/strikes/status and V emission are not established by resource family. KR groggy increases physical damage received while TC describes reduced physical defense; do not silently normalize.'},3045:{'support':'Both KR/TC describe a protective ice shield and frost debuff, supporting IceShield component relation.','unresolved':'KR also explicitly mentions attacking front enemies and knockback resistance; TC emphasizes blocking/protection. Shield instance/target and status policy stay unresolved. Both require first charge stage.'},3049:{'support':'Both KR/TC describe an ice hammer strike against front enemies plus freezing, supporting Hammer component relation.','unresolved':'Charge requirement differs: KR says one charge-button press, TC says continued V/emission. Current KR Matrix6 tier1/key5 is exact selection evidence, not native timing/admission proof.'}}[g['active']]
out={'schema':'TARTAROS_THREE_NUMERIC_ANCHOR_CYCLE_REVIEW_V1','priorAnchorReviewSha256':sha((D/'numeric-stem-family-review.json').read_bytes()),'groups':groups,'sourceMembers':list(sources.values()),'proposedServerOwnedComparisonPolicy':{'status':'PROPOSAL_ONLY_NOT_APPLIED','meaning':'Each successful, explicitly requested lab cast plays one complete approved candidate clip. A Server-owned cursor selects the next approved candidate for the next successful cast; the set cycles only for comparison.','notNativeVariantSelection':True,'candidateSet':['Ruko3036 motions177/178/179/180/218','Epds3045 motions208/209/210/211','Epds3049 motions224/225/226/227'],'requirements':['Root must approve each entire finite candidate set as a component-stem hypothesis; no automatic mapping admission.','Expose current motion and cursor in lab diagnostics; numeric ordering is an arbitrary lab enumeration, never interpreted as phase, skill level or power.','Only advance cursor after actual acceptance and one complete clip starts successfully; rejection, insufficient resource, duplicate request or failed playback must not advance.','One request must not automatically play the whole family, chain phases or charge additional costs for variants.','Cursor must be isolated by test session/role/active and reset on explicit lab reset or context change; no normal character progression persistence.','Do not apply damage/target/projectile/summon/shield/buff semantics solely from component names or Counter values.','Keep normal skill acceptance and official active-to-motion mapping unresolved.'],'caveat':'The referenced Ruko duplicate, Epds shield or hammer object may be a summon/weapon/target visual, not the caster action. The proposed cycle can compare the hypothesis, not establish it.'},'summary':{'groups':3,'clips':sum(len(g['clips']) for g in groups),'allGroupsNonRepeat':all(g['allClipsNonRepeat'] for g in groups),'newOfficialMappings':0},'limitations':['Only existing13-anchor clips/EFF and exact three Practice/Active/descriptions plus selected Matrix/builtin records checked; no294 scan.','Canonical deltas exclude only Header ID/NAME; baseline is not a minimum-motion selection.','No original changes, target execution/attach, provider retry, MEF search, Client/Server/Host/shared changes or Git commit.']}
p=D/'numeric-anchor-cycle-review.json';p.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');print(json.dumps({'file':str(p),'sha256':sha(p.read_bytes()),'summary':out['summary']}))
