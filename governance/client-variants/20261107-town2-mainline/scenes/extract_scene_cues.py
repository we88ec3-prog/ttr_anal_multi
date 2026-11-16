"""Read-only Scene/sequence metadata extraction. Never executes Lua or Client."""
from pathlib import Path
import sys,json,re,hashlib,csv,xml.etree.ElementTree as E
R=Path(__file__).resolve().parents[4];D=Path(__file__).resolve().parent
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
archives={};members=[]
def read(rel,n):
 if rel not in archives:archives[rel]=(Archive(Path(r'E:\Tartaros\origin')/rel),Archive(R/rel))
 a,w=archives[rel];b=a.read(n);wb=w.read(n);members.append({'carrier':rel,'member':n,'originalSha256':sha(b),'workingSha256':sha(wb),'equal':b==wb});return b
def xml(b):
 enc='euc-kr' if b'euc-kr' in b[:120].lower() else 'utf-8-sig';s=b.decode(enc);return E.fromstring(re.sub(r'^\s*<\?xml[^?]*\?>','',s))
t=xml(read('Event.stp','Event/SceneList.xml'));chapters=xml(read('Table.stp','Table/SceneList.xml'));read('Event.stp','Event/qbase.lua')
baseline=R/'CLIENT/evidence/20261107-alsmeer-mainline/resources/resource-baseline.json';br=json.loads(baseline.read_text(encoding='utf-8'));mapmodels={x['map']:x['model'] for x in br['maps']};cases={x['field']:x for x in br['scenarios']}
handoff=R/'s00-runtime-dev/research/handoffs/kr-quest-runtime-20261103-v0.1.0/quest-scenes.csv';old=list(csv.DictReader(handoff.open(encoding='utf-8-sig')));oldkeys={(int(x['quest_id']),int(x['scene_index'])) for x in old}
rows=[]
for x in sorted([x for x in t if 133<=int(x.get('questIdx'))<=144],key=lambda x:(int(x.get('questIdx')),int(x.get('sceneIdx')))):
 q=int(x.get('questIdx'));idx=int(x.get('sceneIdx'));fn=x.get('funcName');n='Event/Sequences/'+fn+'.seq';b=read('Event.stp',n);s=b.decode('euc-kr');calls=[]
 for line,text in enumerate(s.splitlines(),1):
  z=text.strip()
  if z.startswith('--') or z.startswith('function '):continue
  m=re.match(r'([A-Za-z_][\w.]*)\s*\((.*)\)\s*$',z)
  if m:calls.append({'line':line,'function':m.group(1),'argsRaw':m.group(2),'source':z})
 name=fn.lower();cue='blank' if name.endswith('_blank') else 'return_candidate' if name.endswith('_after') else 'clear_candidate' if 'clear' in name else 'boss_intro_candidate' if 'boss' in name else 'stage_intro_candidate' if 'stage' in name else 'talk_candidate'
 loads=[json.loads(c['argsRaw']) for c in calls if c['function']=='LoadMap'];model=Path(loads[0]).stem if loads and loads[0] else None
 rows.append({'questId':q,'scene':idx,'function':fn,'endBehaviorRaw':int(x.get('endBehavior')),'member':n,'sha256':sha(b),'resourceCue':cue,'cueAuthority':'NAME_DERIVED_CLASSIFICATION_NOT_TRIGGER_PROOF','loadMap':loads[0] if loads else None,'temporaryMapModel':model,'calls':calls,'talkCalls':[c for c in calls if c['function'] in ['OpenTalkScene','OpenAutoTalkScene']],'prologCalls':[c for c in calls if c['function']=='DoProlog'],'restoresMap':any(c['function']=='RestoreMap' for c in calls),'controlFlowStatements':[z.strip() for z in s.splitlines() if re.match(r'\s*(if|for|while|repeat)\b',z)],'explicitBeginScenarioCalls':[c for c in calls if c['function'] in ['BeginScenario','RequestStartScenario']],'explicitMoveToTownCalls':[c for c in calls if c['function']=='MoveToTown'],'explicitCharacterJoinCalls':[c for c in calls if c['function'] in ['AddCharacter','EmployChar','RecruitCharacter','RegisterCharacter']],'existingHandoffCovered':(q,idx) in oldkeys})
intro={133:[1],134:[1],135:[1,2],136:[1],137:[1],138:[1],139:[1,2,3],140:[1],141:[1],142:[1],143:[1],144:[1]};returns={134:[2],136:[2],138:[6],142:[8],144:[5]};fields={134:21,136:29,138:30,140:31,142:20,144:22};plans=[]
for q in range(133,145):
 scenes=[x for x in rows if x['questId']==q];field=fields.get(q);sc=cases.get(field);nodes=[]
 if sc:
  for node in sc['nodes']:
   matches=[x for x in scenes if x['temporaryMapModel'] and x['temporaryMapModel'].lower()==mapmodels[node['map']].lower() and x['scene'] not in returns.get(q,[])]
   nodes.append({'sourceNode':node['sourceNode'],'map':node['map'],'mapModel':mapmodels[node['map']],'enterSceneCandidates':[x['scene'] for x in matches if x['resourceCue'] in ['stage_intro_candidate','boss_intro_candidate']],'clearSceneCandidates':[x['scene'] for x in matches if x['resourceCue']=='clear_candidate'],'allModelMatchScenes':[x['scene'] for x in matches],'matchingAuthority':'EXACT_MODEL_NAME_JOIN_ONLY_NOT_EVENT_BINDING','limitations':(['multipleScenesShareSameModel_orderAndTriggerNotProven'] if len([x for x in matches if x['resourceCue'] in ['stage_intro_candidate','boss_intro_candidate']])>1 else [])+([] if matches else ['noSceneModelMatch'])})
 plans.append({'questId':q,'kind':'SINGLE_PLAYER_SCENARIO_CANDIDATE' if field else 'STORY_ONLY_CANDIDATE','fieldUsedForBattleCandidate':field,'introScenes':intro[q],'returnScenes':returns.get(q,[]),'returnTownCandidate':3 if q==144 else 2,'returnTownAuthority':'SERVER_RECONSTRUCTION_NOT_LOADMAP_OR_DOPROLOG_PERSISTENCE','assignmentAuthority':'S00_DECLARED_TEMPLATE_RECONSTRUCTION_FROM_RESOURCE_CUES_NOT_NATIVE_DISPATCH','nodeSceneCandidates':nodes,'unmatchedNonIntroReturnScenes':[x['scene'] for x in scenes if x['scene'] not in intro[q]+returns.get(q,[]) and not any(x['scene'] in n['allModelMatchScenes'] for n in nodes)],'sceneOrderIsTrigger':False,'characterJoinProven':False,'knownIncompatibilities':[]})
for p in plans:
 q=p['questId']
 if q in [133,135,137]:p['knownIncompatibilities'].append('QuestInfo field exists but this Quest is declared story-only; field presence does not authorize combat.')
 if q==139:p['knownIncompatibilities'].append('Three temporary presentation maps include dungeon models but this is a no-field story Quest, not three playable combat nodes.')
 if q in [134,136]:p['knownIncompatibilities'].append('Blank intro1 precedes formation; Clear2 returns town presentation and must not be attached as map-enter scene.')
 if q==138:p['knownIncompatibilities'].append('First two scenario maps have no matching sequence; scenes2/3 match later barley06X/barley09X nodes.')
 if q==142:p['knownIncompatibilities'].append('Scenes4 and5 both use salomanjud02X(map196); map195 useskeep13X and has no matching scene. Do not attach one scene per node by array index.')
 if q==144:p['knownIncompatibilities']+=['Scene3 usesiceman02D but node3/map306 usesiceman15D: no exact match, candidate override must be separately declared.','Return5 uses town003N +DoProlog3 thenRestoreMap; persistentTown3 must be Server reconstruction.']
for p in plans:
 p['settlementFromReturnScene']=False
 p['declaredNodeSceneOverrides']=[]
 if p['questId']==142:p['declaredNodeSceneOverrides']=[{'sourceNode':3,'enterScenes':[4,5],'authority':'USER_DELEGATED_S00_SERVER_RECONSTRUCTION','reason':'Both exact model matches retained in resource scene-index order; native trigger/order unproven.'}]
 if p['questId']==144:p['declaredNodeSceneOverrides']=[{'sourceNode':3,'enterScenes':[3],'authority':'USER_DELEGATED_S00_SERVER_RECONSTRUCTION','sceneTemporaryMap':'iceman02D','actualCombatMap':'iceman15D','restoreThenRebuildCombatMap':True,'reason':'Explicit root S00 candidate, not model match; preserve scene3 instead of dropping it.'}]
chapterrows=[{'chapter':dict(c.attrib),'scenario':dict(s.attrib),'scenes':[dict(x.attrib) for x in s]} for c in chapters for s in c if 133<=int(s.get('questId'))<=144]
out={'schema':'ALSMEER_SCENE_CUE_PROJECTION_V1','authority':'CLIENT_RESOURCE_DIRECT_AND_SEPARATELY_DECLARED_SERVER_RECONSTRUCTION','questIds':list(range(133,145)),'sceneCount':len(rows),'scenes':rows,'questPlans':plans,'chapterMembershipOnly':chapterrows,'sourceMembers':members,'resourceBaselinePath':str(baseline.relative_to(R)),'resourceBaselineSha256':sha(baseline.read_bytes()),'existingHandoffSha256':sha(handoff.read_bytes()),'existingHandoffCoveredScenes':[(x['questId'],x['scene']) for x in rows if x['existingHandoffCovered']],'limits':['No Lua execution. SceneList membership/name/order is not dispatch proof.','No BeginScenario/MoveToTown/character-join explicit calls in these35 sequences.','Every sequence RestoreMap is local presentation return, not persistent town or reward.','All Event endBehavior0 values are raw data, not automatic settlement.','No new opcode,reward or character unlock is invented.']}
(D/'scene-cue-projection.json').write_text(json.dumps(out,ensure_ascii=True,indent=2),encoding='utf-8')
public={'schema':'ALSMEER_SCENE_CUE_PUBLIC_METADATA_V1','authority':out['authority'],'questIds':out['questIds'],'sceneCount':out['sceneCount'],'questPlans':plans,'chapterMembershipOnly':chapterrows,'sourceMembers':members,'resourceBaselineSha256':out['resourceBaselineSha256'],'existingHandoffSha256':out['existingHandoffSha256'],'existingHandoffCoveredScenes':out['existingHandoffCoveredScenes'],'limits':out['limits'],'sceneMetadata':[]}
for row in rows:
 public['sceneMetadata'].append({'questId':row['questId'],'scene':row['scene'],'function':row['function'],'member':row['member'],'sha256':row['sha256'],'endBehaviorRaw':row['endBehaviorRaw'],'resourceCue':row['resourceCue'],'cueAuthority':row['cueAuthority'],'temporaryMapModel':row['temporaryMapModel'],'talkIds':[{'table':int(c['argsRaw'].split(',')[0]),'entry':int(c['argsRaw'].split(',')[1])} for c in row['talkCalls']],'prologIds':[int(c['argsRaw']) for c in row['prologCalls']],'restoresMap':row['restoresMap'],'explicitBeginScenarioPresent':bool(row['explicitBeginScenarioCalls']),'explicitMoveToTownPresent':bool(row['explicitMoveToTownCalls']),'explicitCharacterJoinPresent':bool(row['explicitCharacterJoinCalls']),'existingHandoffCovered':row['existingHandoffCovered']})
(D/'scene-cue-public-projection.json').write_text(json.dumps(public,ensure_ascii=True,indent=2),encoding='utf-8')
ids=[Path(__file__),handoff,baseline,R/'s00-runtime-dev/kr-temp-roy/20261030-171913-chatgpt-web-roy-T16-133-KR-Quest15-four-Lua-qbase-bytecode-talk-prolog-phases-return-native.md'];(D/'source-identities.json').write_text(json.dumps([{'path':str(x.relative_to(R)),'sha256':sha(x.read_bytes())} for x in ids],indent=2),encoding='utf-8')
print(json.dumps({'scenes':len(rows),'quests':len(plans),'sourceMembers':len(members),'allOriginalWorkingEqual':all(x['equal'] for x in members),'coveredByHandoff':out['existingHandoffCoveredScenes']}))
