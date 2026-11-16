"""Public metadata for exact fields and matrix-slot replacements; never aliases."""
from pathlib import Path
import sys,json,hashlib,re,collections,xml.etree.ElementTree as E
R=Path(r'E:\Tartaros\workspace');O=R.parent/'origin';D=Path(__file__).parent;B=R/'runtime-observations/2026-11-05-all-skills';sha=lambda b:hashlib.sha256(b).hexdigest()
c=json.loads((B/'all-skills-catalog.json').read_text(encoding='utf-8-sig'));runtime=json.loads((R/'CLIENT/evidence/20261107-all-matrices/runtime-matrix-rows.json').read_text());j=json.loads((B/'all-role-motion-joins.json').read_text(encoding='utf-8-sig'));practices={p['id']:p for p in c['practices']}
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
a,w=Archive(O/'Table.stp'),Archive(R/'Table.stp');members={}
def read(member):
 raw,work=a.read(member),w.read(member);assert raw==work
 if member in c['members']:assert sha(raw)==c['members'][member]['original_sha256']
 members[member]={'member':member,'originalSha256':sha(raw),'workingSha256':sha(work),'equal':True};return E.fromstring(raw)
actroot=read('Table/SkillActiveTable.xml');act={int(n.get('no')):n for n in actroot};rows=[];seen=set();base={(r['role'],r['tier'],r['mask']):r for r in runtime['rows'] if r['matrix']==0}
needles=['motion','animation','style','wave','skillcode','scriptfile','filename','baseskill','parent','alias','icon']
for r in runtime['rows']:
 key=(r['role'],r['active'])
 if not r['blocked'] or key in seen:continue
 seen.add(key);p=practices[r['practice']];root=read(p['source']);practice=root.find('Practice');sk=act[r['active']];levels=[];references=[];bridge=[]
 for lev in practice.findall('LevelData'):
  levels.append({'level':int(lev.get('Level')),'requirements':[dict(n.attrib) for n in lev.findall('Requirements/Require')],'grants':[dict(n.attrib) for n in lev.findall('Modifiers/Modifier')]})
  for n in lev.iter():
   if any(k in n.attrib for k in ['SkillID','TargetSkillID']) or n.get('Type')=='SkillCooltimeReset':references.append({'level':int(lev.get('Level')),'nodeTag':n.tag,'attributes':dict(n.attrib)})
 for domain,xml in [('Practice',practice),('ActiveInfo',sk)]:
  for n in xml.iter():
   for k,v in n.attrib.items():
    if any(t in k.casefold() for t in needles):bridge.append({'domain':domain,'nodeTag':n.tag,'attribute':k,'value':v})
 replacement=[]
 for slot in runtime['rows']:
  if (slot['role'],slot['active'])!=key:continue
  original=base.get((r['role'],slot['tier'],slot['mask']))
  if original and original['active']!=r['active']:replacement.append({'matrix':slot['matrix'],'tier':slot['tier'],'mask':slot['mask'],'matrix0Active':original['active'],'matrix0Practice':original['practice'],'relation':'EXACT_SAME_MATRIX_SLOT_REPLACEMENT_NOT_ANIMATION_INHERITANCE'})
 rows.append({'role':r['role'],'active':r['active'],'practice':r['practice'],'practiceMember':p['source'],'sourcePracticeSha256':members[p['source']]['originalSha256'],'activeAttributes':dict(sk.attrib),'activeChildTags':dict(collections.Counter(n.tag for n in sk.iter())),'activeAttributeNames':dict(collections.Counter(k for n in sk.iter() for k in n.attrib)),'allPracticeLevelModifiers':levels,'explicitSkillIdReferences':references,'matrix0SlotReplacements':replacement,'potentialBridgeFields':bridge,'motionBridgeClosed':False,'presentationRequirement':'NO_AUTOMATIC_BORROWING_FROM_SAME_KEY_OR_STRONG_NAME'})
aux=[]
for member in ['Table/CharSkill.xml','Table/Skill/PracticeGroup.xml','Table/Skill/SkillMatrix.xml','Table/EffectList.xml','Table/EffectCategoryMapper.xml','Table/IndependentSkillEffect.xml']:
 root=read(member);aux.append({'member':member,'rootTag':root.tag,'tags':dict(collections.Counter(n.tag for n in root.iter())),'attributes':dict(collections.Counter(k for n in root.iter() for k in n.attrib)),'explicitSkillIdAttributes':[{'tag':n.tag,'attributes':dict(n.attrib)} for n in root.iter() if any(k.casefold() in ['skillid','targetskillid','baseskillid','skillcode','style','wave'] for k in n.attrib)]})
binary=O/'Tartaros.bin';raw=binary.read_bytes();terms={}
for term in ['SkillCode','SkillStyle','SkillWave','BaseSkill','MotionAlias','SkillScriptLevel']:
 terms[term]=[hex(m.start()) for m in re.finditer(re.escape(term.encode()),raw,re.I)]
result={'schema':'ALL_SKILLS_UNLOCK_EXPLICIT_LINKS_V1','rows':rows,'sourceMembers':list(members.values()),'auxiliarySchemas':aux,'boundedBinaryLiteralChecks':{'path':str(binary),'sha256':sha(raw),'literalOffsets':terms,'scope':'Exact ASCII literals only; not native absence proof.'},'sourceIdentitiesOnlyNoRawXml':True,'limitations':['Same-slot matrix replacement is exact UI/skill selection evidence, not base-animation or enhanced-skill inheritance.','TargetSkillID in SkillLevel grants identifies the granted active; unrelated interrupt conditions/cooldown resets do not identify its animation.','No Style/Wave/SkillCode/alias field found in these exact blocked entries does not prove absence in all modules/versions.']}
(D/'explicit-links-public.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode())
# Minimal public runtime proposal excludes full canonical ASD structures.
eq=json.loads((D/'equivalent-clip-candidates.json').read_text(encoding='utf-8-sig'));public={'schema':'ALL_SKILLS_UNLOCK_RUNTIME_CANDIDATES_V1','candidateRows':eq['candidateRows'],'sourceMembers':eq['sourceMembers'],'equivalenceProofs':[{'role':g['role'],'active':g['active'],'entireFamilyEquivalent':g['entireFamilyEquivalent'],'equivalentMotionGroups':g['equivalentMotionGroups'],'clips':[{k:v for k,v in q.items() if k!='canonicalStructure'} for q in g['clips']]} for g in eq['reviewedFamilies']],'privateDetailedEvidenceSha256':sha((D/'equivalent-clip-candidates.json').read_bytes()),'nativeDispatchClosed':False}
(D/'runtime-unlock-candidates-v1.json').write_bytes((json.dumps(public,ensure_ascii=False,indent=2)+'\n').encode());print(json.dumps({'blockedRows':len(rows),'sameSlotAdvancedRows':sum(bool(r['matrix0SlotReplacements']) for r in rows),'potentialBridgeFields':sum(len(r['potentialBridgeFields']) for r in rows),'auxSchemas':len(aux),'binaryLiteralCounts':{k:len(v) for k,v in terms.items()},'runtimeCandidateRows':len(public['candidateRows'])}))
