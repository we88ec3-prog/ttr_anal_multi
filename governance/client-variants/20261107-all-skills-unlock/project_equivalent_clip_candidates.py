"""Content-equivalent ASD families can yield a single isolated preview candidate.
This does not infer phase sequencing, gameplay or native dispatch.
"""
from pathlib import Path
import sys,json,hashlib,xml.etree.ElementTree as E,collections
R=Path(r'E:\Tartaros\workspace');O=R.parent/'origin';D=Path(__file__).parent;B=R/'runtime-observations/2026-11-05-all-skills'
sha=lambda b:hashlib.sha256(b).hexdigest();j=json.loads((B/'all-role-motion-joins.json').read_text(encoding='utf-8-sig'));cat=json.loads((B/'all-skills-catalog.json').read_text(encoding='utf-8-sig'));runtime=json.loads((R/'CLIENT/evidence/20261107-all-matrices/runtime-matrix-rows.json').read_text())
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
arcs={};manifest={};motions={(r['role'],m['motion_id']):m for r in j['roles'] for m in r['motion_metadata']}
def read(carrier,member,pin=None):
 if carrier not in arcs:arcs[carrier]=(Archive(O/carrier),Archive(R/carrier))
 a,w=arcs[carrier];rb,wb=a.read(member),w.read(member);assert rb==wb
 if pin:assert sha(rb)==pin
 manifest[(carrier,member)]={'carrier':carrier,'member':member,'originalSha256':sha(rb),'workingSha256':sha(wb),'equal':True}
 return rb
def canonical(n):
 attrs={k:v for k,v in n.attrib.items() if not (n.tag=='AnimationHeader' and k in ['ID','NAME'])}
 return {'tag':n.tag,'attributes':attrs,'text':(n.text or '').strip(),'tail':(n.tail or '').strip(),'children':[canonical(c) for c in n]}
def clip(role,mid):
 m=motions[(role,mid)];raw=read(m['asd_carrier'],m['asd_member'],m['asd_sha256']);root=E.fromstring('<ROOT>'+raw.decode('euc-kr')+'</ROOT>');normal=canonical(root)
 signature={'ASD':normal,'ABFLength':m['abf_length_frame_units'],'headerMatchesAbf':m['header_matches_abf']}
 effects=[]
 for e in m['effects']:
  assert e['present_in_effect_archive'];read('Effect/Effect.stp',e['path'],e['sha256']);effects.append({'member':e['path'],'sha256':e['sha256']})
 animation=root.find('.//AnimationData');assert animation is not None
 return {'motion':mid,'member':m['asd_member'],'sha256':sha(raw),'equivalenceSha256':sha(json.dumps(signature,sort_keys=True,separators=(',',':')).encode()),'repeat':animation.get('Repeat'),'repeatStartFrame':animation.get('RepeatStartFrame'),'nominalDuration':m['duration_seconds_candidate_sum_end_plus_delay_over_fps'],'effects':effects,'abfLengthFrameUnits':m['abf_length_frame_units'],'canonicalStructure':normal}
groups=[];promotions=[]
for role,active in [(1,5),(1,1287),(2,19),(2,1289)]:
 rows=[r for r in runtime['rows'] if r['role']==role and r['active']==active];assert rows;ids=rows[0]['motions'];clips=[clip(role,i) for i in ids];byhash=collections.defaultdict(list)
 for q in clips:byhash[q['equivalenceSha256']].append(q['motion'])
 ready=len(byhash)==1 and all(c['repeat']=='false' for c in clips)
 groups.append({'role':role,'active':active,'clips':clips,'equivalentMotionGroups':list(byhash.values()),'entireFamilyEquivalent':ready,'transitionPolicy':'NO_SEQUENCE_OR_REPEAT_INFERRED'})
 if ready:
  representative=min(clips,key=lambda c:c['motion']);row=rows[0]
  promotions.append({'role':role,'active':active,'practice':row['practice'],'hp':row['hp'],'sp':row['sp'],'mp':row['mp'],'rawCooldown':row['rawCooldown'],'motions':[representative['motion']],'durationSeq':[representative['nominalDuration']],'status':'EQUIVALENT_BASIS_SINGLE_CLIP_RESOURCE_CANDIDATE','playbackKinds':['SingleClip'],'equivalentMotionIds':[c['motion'] for c in clips],'equivalenceSha256':representative['equivalenceSha256'],'variant':'Basis resource tag only','scriptLevelAdmission':'UNRESOLVED_NOT_ASSIGNED','repeat':False,'startNode':representative['motion'],'followupNodes':[],'finishNode':None,'phaseTransitionEvidence':None,'targetRequirement':'UNRESOLVED','paymentPolicy':'ONE_REQUEST_ONCE_CANDIDATE_ADAPTER_POLICY_NOT_NATIVE_PROOF','impactTiming':'UNRESOLVED_DO_NOT_REUSE_GENERIC_0_2_SECONDS_AS_PROOF','nativeDispatchClosed':False,'labPreviewCandidate':True,'allMatrixSlots':[{'matrix':r['matrix'],'tier':r['tier'],'mask':r['mask']} for r in rows],'authority':'EXACT_RESOURCE_EQUIVALENCE_NOT_OFFICIAL_SKILL_DISPATCH'})
# Full exact schema audit only for the72 newly named advanced Practices, not all archives.
advanced=[]
for p in cat['practices']:
 if p['category']!='ActiveSkill' or not 208<=p['id']<=279:continue
 data=read('Table.stp',p['source'],cat['members'][p['source']]['original_sha256']);root=E.fromstring(data);attrs=collections.Counter(k for n in root.iter() for k in n.attrib);types=collections.Counter(n.get('Type') for n in root.iter() if n.get('Type'));bridge=[{'tag':n.tag,'attributes':dict(n.attrib)} for n in root.iter() if any(s in k.casefold() for k in n.attrib for s in ['motion','animation','effect','alias','file'])]
 advanced.append({'role':p['role'],'practice':p['id'],'source':p['source'],'attributeNames':dict(attrs),'typeValues':dict(types),'explicitResourceBridgeFields':bridge})
# The five unlisted ASD files are examined but have no verified ABF activation/ActiveID join.
audit=json.loads((D/'bounded-resource-audit.json').read_text(encoding='utf-8-sig'));unlisted=[]
for rr in audit['roleIndices']:
 for name in rr['asdNotInExistingMotionMetadata']:
  raw=read(rr['carrier'],name);root=E.fromstring('<ROOT>'+raw.decode('euc-kr')+'</ROOT>');header=root.find('.//AnimationHeader');unlisted.append({'role':rr['role'],'member':name,'sha256':sha(raw),'header':dict(header.attrib),'effects':[dict(e.attrib) for e in root.findall('.//Effect')],'activeJoin':'UNRESOLVED','abfCallableIdProof':'UNRESOLVED','promoted':False})
result={'schema':'ALL_SKILLS_UNLOCK_EQUIVALENT_CLIP_CANDIDATES_V1','readyPromotionCount':len(promotions),'candidateRows':promotions,'reviewedFamilies':groups,'advancedPracticeAudits':advanced,'unlistedAsds':unlisted,'sourceMembers':list(manifest.values()),'limitations':['Candidates are only isolated animation previews, not complete gameplay skills.','Equality removes only AnimationHeader ID/NAME; remaining full parsed ASD structure and ABF length must agree.','No nearest-name aliases. No blanket Basic Z mapping from generic SKILL01 filename.','Four reviewed multi-Basis families are not assumed sequences; non-equivalent families stay blocked.','Targeting, script-level variant dispatch, impact/damage, projectile semantics and held input remain unresolved.']}
(D/'equivalent-clip-candidates.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode());print(json.dumps({'newCandidates':[(p['role'],p['active'],p['motions']) for p in promotions],'advancedPractices':len(advanced),'advancedExplicitBridgeFields':sum(len(a['explicitResourceBridgeFields']) for a in advanced),'sourceMembers':len(manifest)}))
