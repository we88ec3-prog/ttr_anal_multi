"""Bounded growth metadata from existing projections plus two explain tables."""
from pathlib import Path
import json,sys,hashlib,re,collections,xml.etree.ElementTree as E
R=Path(r'E:\Tartaros\workspace');D=Path(__file__).parent;B=R/'runtime-observations/2026-11-05-all-skills';L=R/'CLIENT/evidence/20261107-skill-levels'
sha=lambda b:hashlib.sha256(b).hexdigest()
inputs={}
def load(p):
 b=p.read_bytes();inputs[str(p.relative_to(R))]=sha(b);return json.loads(b.decode('utf-8-sig'))
c=load(B/'all-skills-catalog.json');j=load(B/'all-role-motion-joins.json');perf=load(L/'practice-level-performance.json');tal=load(L/'talent-script-levels.json');slots=load(R/'CLIENT/evidence/20261107-all-matrices/runtime-matrix-rows.json')
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
archives={'original':Archive(R.parent/'origin/Table.stp'),'working':Archive(R/'Table.stp'),'taiwan':Archive(Path(r'E:\Tartaros\tc_workspace\Table.stp'))};members=[];expl={}
for member in ['Table/PracticeExplainTable.xml','Table/skillexplaintable.xml']:
 b=archives['original'].read(member);w=archives['working'].read(member);t=archives['taiwan'].read(member)
 assert b==w
 old=c['members'][member];assert sha(b)==old['original_sha256'] and sha(t)==old['taiwan_sha256']
 members.append({'member':member,'original_sha256':sha(b),'working_sha256':sha(w),'taiwan_sha256':sha(t),'originalWorkingEqual':True})
 for lang,data in [('kr',b),('tc',t)]:expl[(member,lang)]={int(n.get('ID',n.get('no','0'))):n for n in E.fromstring(data)}
terms={'attack_count':['攻擊次數','打擊次數','連續次數','攻擊段','타격 횟수','공격 횟수','연타'], 'projectile_count':['發射數','發射體','投射','飛彈數','발사 개수','발사체'], 'charge_time':['蓄力','集氣','蓄氣','充能','차지','충전'], 'travel_range':['移動距離','進攻距離','突進距離','位移','이동 거리','전진 거리'], 'attack_speed':['攻擊速度','공격 속도'], 'range':['攻擊範圍','공격 범위']}
def texts(member,ident):
 out=[]
 for lang in ['kr','tc']:
  n=expl[(member,lang)].get(ident)
  if n is None:continue
  for x in n:
   value=' '.join(''.join(x.itertext()).split())
   if not value:continue
   cats=[k for k,words in terms.items() if any(word in value for word in words)]
   out.append({'language':lang,'element':x.tag,'level':x.get('ID',x.get('val')),'textExcerpt':value[:240],'truncated':len(value)>240,'textSha256':sha(value.encode()),'presentationTopics':cats,'numericTokens':re.findall(r'\d+(?:\.\d+)?',value),'authority':'SOURCE_DESCRIPTION_NOT_NUMERIC_DISPATCH'})
 return out
pract={p['id']:p for p in c['practices']};motion={(r['role'],m['motion_id']):m for r in j['roles'] for m in r['motion_metadata']};joins=collections.defaultdict(list)
for z in j['active_practice_joins']:joins[(z['role'],z['active_skill_id'])].append(z)
index=collections.defaultdict(list)
for p in perf['practices']:
 for active in sorted(set(x['active'] for x in p['levels'])):index[(p['role'],active)].append((p,[x for x in p['levels'] if x['active']==active]))
talindex=collections.defaultdict(list)
for row in tal['rows']:talindex[(row['role'],row['active'])].append(row)
slotidx=collections.defaultdict(list)
for s in slots['rows']:slotidx[(s['role'],s['active'])].append({k:s[k] for k in ['matrix','tier','mask','status','blocked']})
def flattened(level):
 d={'ACTIVEINFO.'+k:v for k,v in level['activeInfo'].items()}
 for i,p in enumerate(level['performance']):
  for k,v in p['attributes'].items():d[f'{p["tag"]}[{i}].{k}']=v
 return d
rows=[]
for (role,active),groups in sorted(index.items()):
 normal=[]
 for p,levels in groups:
  fs=[flattened(x) for x in levels];changes={}
  for key in sorted(set().union(*(x.keys() for x in fs))):
   values=[x.get(key) for x in fs]
   if len(set(map(str,values)))>1:changes[key]=[{'learnedLevel':l['learnedLevel'],'activeLevel':l['activeLevel'],'value':v} for l,v in zip(levels,values)]
  normal.append({'practice':p['practice'],'source':p['source'],'nameTc':pract[p['practice']]['taiwan_name'],'levels':[{'learnedLevel':x['learnedLevel'],'activeLevel':x['activeLevel']} for x in levels],'changedNumericFields':changes,'descriptions':texts('Table/PracticeExplainTable.xml',p['practice'])})
 talent=[]
 for t in talindex[(role,active)]:
  talent.append({**t,'nameTc':pract[t['talentPractice']]['taiwan_name'],'descriptions':[x for x in texts('Table/PracticeExplainTable.xml',t['talentPractice']) if x['level'] is None or x['level']==str(t['talentLearnedLevel'])]})
 variants=[]
 for z in joins[(role,active)]:
  for cand in z['available_motion_candidates']:
   m=motion[(role,cand['motion_id'])];effects=[]
   for e in m['effects']:
    tags=sorted(set(q.lower() for q in re.findall(r'-(Basis|Average|Exper|Master|Super)',e['path'],re.I)))
    effects.append({'path':e['path'],'present':e['present_in_effect_archive'],'sha256':e.get('sha256'),'variantTags':tags})
   variants.append({'practice':z['practice_id'],'motion':m['motion_id'],'asdMember':m['asd_member'],'asdSha256':m['asd_sha256'],'abfFile':m['abf_file'],'nominalDuration':m['duration_seconds_candidate_sum_end_plus_delay_over_fps'],'nameEvidence':m['name_evidence'],'effects':effects,'authority':'EXACT_STEM_RESOURCE_CANDIDATE_NOT_NATIVE_SCRIPTLEVEL_DISPATCH'})
 rows.append({'role':role,'active':active,'sixKeySelected':bool(slotidx[(role,active)]),'slots':slotidx[(role,active)],'ordinarySkillLevels':normal,'talentScriptLevels':talent,'motionEffectCandidates':variants,'activeDescriptions':texts('Table/skillexplaintable.xml',active),'axisBridge':'UNRESOLVED_NO_NUMERIC_LEVEL_TO_VARIANT_MAPPING_ASSERTED'})
def save(name,obj):(D/name).write_bytes((json.dumps(obj,ensure_ascii=False,indent=2)+'\n').encode('utf-8'))
save('growth-matrix.json',{'schema':'tartaros-skill-growth-three-axes-v1','rows':rows,'sourceProjectionHashes':inputs,'newExplainMemberIdentities':members,'limitations':['Numeric levels, Talent ScriptLevel and resource variants remain separate axes.','TC explanation is a different regional description, not proof KR runtime does exactly the same.','No description-only numeric rule is executed by Server.','No new motion/effect scan; existing bounded joins and their pinned evidence are reused.']})
save('isilia-27.json',{'role':4,'rows':[r for r in rows if r['role']==4 and r['sixKeySelected']]})
summary={'activeRolePairs':len(rows),'sixKeyActiveRolePairs':sum(r['sixKeySelected'] for r in rows),'isiliaSixKeyActives':sum(r['role']==4 and r['sixKeySelected'] for r in rows),'explicitTalentScriptRows':sum(len(r['talentScriptLevels']) for r in rows),'withAnyMotionCandidate':sum(bool(r['motionEffectCandidates']) for r in rows),'numericVariantMappingsInferred':0}
save('summary.json',summary);print(json.dumps(summary))
