"""Build local metadata content only; source-fact scene cues remain declared policy."""
from pathlib import Path
import argparse,json,hashlib,copy,re
R=Path(r'E:\Tartaros\workspace');D=Path(__file__).parent
sha=lambda b:hashlib.sha256(b).hexdigest()
PIN='59a0e6221e76171ef9618b787dbf25c6ba0db61180866458317025916ef35678'
def elements(raw,key):
 text=raw.decode('utf-8-sig');at=text.index('[',text.index('"'+key+'"'))+1;decoder=json.JSONDecoder();out=[]
 while True:
  while text[at].isspace() or text[at]==',':at+=1
  if text[at]==']':return out
  _,end=decoder.raw_decode(text,at);out.append(text[at:end].encode('utf-8'));at=end
def main():
 p=argparse.ArgumentParser();p.add_argument('--policy',type=Path,default=D/'explicit-boss-choices.json');args=p.parse_args()
 oldpath=R/'server-runtime-dev/content/alsmeer-story-route-v1.json';oldraw=oldpath.read_bytes();assert sha(oldraw)==PIN;old=json.loads(oldraw)
 bpath=D/'resource-baseline.json';sp=R/'CLIENT/evidence/20261107-alsmeer-mainline/scenes/scene-cue-public-projection.json';b=json.loads(bpath.read_text(encoding='utf-8-sig'));s=json.loads(sp.read_text(encoding='utf-8-sig'))
 modelPath=D/'scene-created-models.json';modelMetadata=json.loads(modelPath.read_text(encoding='utf-8-sig'));sceneModels={(n['questId'],n['scene']):n for n in modelMetadata['rows']}
 policy=json.loads(args.policy.read_text(encoding='utf-8-sig')) if args.policy else {'nodeOverrides':[]};plans={p['questId']:p for p in s['questPlans']};scenarios={c['field']:c for c in b['scenarios']};maps={m['map']:m for m in b['maps']};bossAudit=[]
 for scene in s['sceneMetadata']:
  if scene['resourceCue']!='boss_intro_candidate':continue
  qp=plans[scene['questId']];scenario=scenarios[qp['fieldUsedForBattleCandidate']];modelRow=sceneModels[(scene['questId'],scene['scene'])];assert modelRow['sequenceSha256']==scene['sha256'];models=modelRow['createdObjectModelIds'];assert models
  bossAudit.append({'quest':scene['questId'],'scene':scene['scene'],'sequence':scene['member'],'sequenceSha256':scene['sha256'],'field':scenario['field'],'case':scenario['case'],'terminalMap':scenario['nodes'][-1]['map'],'terminalSourceNode':scenario['nodes'][-1]['sourceNode'],'sceneActorModels':[{'model':m,'actualClusterGroups':[g['cluster'] for cs in scenario['allClusterSets'] for g in cs['clusters'] if any(o['model']==m for o in g['objects'])],'inPreloadOnly':m in scenario['preloadIds'] and not any(o['model']==m for cs in scenario['allClusterSets'] for g in cs['clusters'] for o in g['objects'])} for m in models],'allSourceClusters':scenario['allClusterSets'],'selectionAuthority':'NO_AUTO_MONSTER_ADMISSION_FROM_SCENE_ACTOR_OR_PRELOAD'})
 content=copy.deepcopy(old);content['version']='alsmeer-full-mainline-20261107-candidate-v1';content['sourceBaselineSha256']=sha(bpath.read_bytes());content['goalTown']=3;content['goalMap']=199
 for m in b['maps']:
  if any(o['map']==m['map'] for o in content['maps']):continue
  content['maps'].append({k:m[k] for k in ['map','bound','sha256','spawnX','spawnY','portalX','portalY']}|{'direction':64})
 town3=maps[199];assert len(town3['candidateTownNpcPoints'])>=len(b['town3NpcIds'])
 npcs3=[{'model':ident,**point} for ident,point in zip(b['town3NpcIds'],town3['candidateTownNpcPoints'])]
 cls=R/'server-runtime-dev/src/Tartaros.Network/LocalPhindosTownCandidates.cs';raw=cls.read_text(encoding='utf-8-sig');npcs1=[{'model':int(m),'x':float(x),'y':float(y)} for m,x,y in re.findall(r'new\((\d+), (\d+), (\d+)\)',raw)];assert len(npcs1)==9
 content['towns']=[{'town':1,'map':182,'npcs':npcs1},{'town':2,'map':183,'npcs':copy.deepcopy(old['goalNpcs'])},{'town':3,'map':199,'npcs':npcs3}];content['goalNpcs']=npcs3
 assert next(m for m in content['maps'] if m['map']==183)==next(m for m in old['maps'] if m['map']==183)
 for q in b['quests']:
  qp=plans[q['quest']];field=qp['fieldUsedForBattleCandidate'];scenario=None
  if field is not None:
   src=scenarios[field];nodes=[];cues={n['sourceNode']:n for n in qp['nodeSceneCandidates']}
   for n in src['nodes']:
    cue=cues[n['sourceNode']];row={'sourceNode':n['sourceNode'],'map':n['map'],'selectedCluster':n['candidateSelectedCluster'],'encounterModels':n['candidateEncounterModels'],'enterScenes':cue['enterSceneCandidates'],'clearScenes':cue['clearSceneCandidates']}
    for override in qp.get('declaredNodeSceneOverrides',[]):
     if override['sourceNode']==n['sourceNode']:row['enterScenes']=override['enterScenes']
    for override in policy.get('nodeOverrides',[]):
     if override['quest']==q['quest'] and override['sourceNode']==n['sourceNode']:
      assert override.get('authority')=='EXPLICIT_S00_FINITE_RECONSTRUCTION_NOT_MEF'
      if 'selectedCluster' in override:
       groups=[g for cs in src['allClusterSets'] for g in cs['clusters'] if g['cluster']==override['selectedCluster']];assert len(groups)==1;row['selectedCluster']=override['selectedCluster'];row['encounterModels']=[o['model'] for o in groups[0]['objects'] for _ in range(o['count'])]
      if 'selectedClusters' in override:
       ids=override['selectedClusters'];assert ids[0]==row['selectedCluster'] and len(ids)==len(set(ids));groups=[g for ident in ids for cs in src['allClusterSets'] for g in cs['clusters'] if g['cluster']==ident];assert len(groups)==len(ids);row['selectedClusters']=ids;row['encounterModels']=[o['model'] for g in groups for o in g['objects'] for _ in range(o['count'])]
      if 'encounterModels' in override:row['encounterModels']=override['encounterModels']
    assert 0<len(row['encounterModels'])<=20;nodes.append(row)
   scenario={'field':field,'case':src['case'],'nodes':nodes}
  content['quests'].append({'quest':q['quest'],'npc':q['giver'],'finisherNpc':q['finisher'],'levelRaw':int(q['attributes']['level']),'introScenes':qp['introScenes'],'returnScenes':qp['returnScenes'],'returnTown':qp['returnTownCandidate'],'formationToken':2011+len(content['quests'])-len(old['quests']),'scenario':scenario,'town':2})
 content['previousVersions']=[{'contentSha256':PIN,'questIds':[q['quest'] for q in old['quests']]}]
 content['limits']+=['Town2 twelve-quest narrative completion is a local reconstruction, not formal acceptance/settlement/rewards/EXP.','Town3 persistence after Q144 is explicit S00 reconstruction; LoadMap+DoProlog then RestoreMap is not persistence proof.','Q144 Scene3 uses iceman02D while actual node3 uses iceman15D; explicit candidate scene before node3, then rebuild actual combat map.','Q142 map196 scenes4 then5 are retained by explicit candidate order, not proven native trigger order.','Default node clusters remain finite reconstruction. Boss actor-to-cluster audit is separate; no scene actor/preload automatically becomes a monster.']
 output=(json.dumps(content,ensure_ascii=False,indent=2)+'\n').encode();newfragments=elements(output,'quests');oldfragments=elements(oldraw,'quests');assert len(newfragments)==22 and newfragments[:10]==oldfragments
 target=D/'alsmeer-full-mainline-content-candidate.json';target.write_bytes(output)
 runtime=R/'runtime-observations/20261107-alsmeer-mainline/story-content-v34.json'
 if runtime.exists():assert runtime.read_bytes()==output,'Refuse overwriting an existing differing runtime content'
 else:
  with runtime.open('xb') as f:f.write(output)
 (D/'boss-cluster-audit.json').write_bytes((json.dumps(bossAudit,ensure_ascii=False,indent=2)+'\n').encode())
 provenance={'oldContentSha256':PIN,'oldQuestPrefixExactBytes':True,'oldQuestCount':10,'newQuestCount':22,'oldTown2MapAndNpcsPreserved':True,'resourceBaselineSha256':sha(bpath.read_bytes()),'sceneProjectionSha256':sha(sp.read_bytes()),'sceneCreatedModelMetadataSha256':sha(modelPath.read_bytes()),'town1NpcClassSha256':sha(cls.read_bytes()),'outputSha256':sha(output),'nodeOverridePolicy':policy,'goalTownPersistenceAuthority':'EXPLICIT_S00_RECONSTRUCTION_NOT_NATIVE_CLOSURE','rawBndPublication':False}
 (D/'content-build-manifest.json').write_bytes((json.dumps(provenance,indent=2)+'\n').encode());print(json.dumps(provenance))
 catalogPath=R/'server-runtime-dev/content/scenario-source-catalog-v1.json';catalogRaw=catalogPath.read_bytes();catalog=json.loads(catalogRaw);oldCases=copy.deepcopy(catalog['cases'])
 for sc in b['scenarios']:
  assert not any(c['case']==sc['case'] for c in catalog['cases'])
  catalog['cases'].append({'case':sc['case'],'field':sc['field'],'nodeOrder':[n['sourceNode'] for n in sc['nodes']],'nodes':[{'sourceNode':n['sourceNode'],'choices':[{'map':n['map'],'percent':100}]} for n in sc['nodes']],'groups':[{'set':int(cs['attributes']['ID']),'group':g['cluster'],'members':[{'model':o['model'],'pre':o['preRaw'],'count':o['count']} for o in g['objects']]} for cs in sc['allClusterSets'] for g in cs['clusters']]})
 assert catalog['cases'][:len(oldCases)]==oldCases
 catalog['town2ResourceBaselineSha256']=sha(bpath.read_bytes());catalog['sourceKind']='OLD_SOURCE_LINEAGE_PRESERVED_PLUS_ORIGINAL_MATCHING_TOWN2_RESOURCE_METADATA';catalog['previousSourceCatalogSha256']=sha(catalogRaw)
 (D/'scenario-source-catalog-v2.json').write_bytes((json.dumps(catalog,ensure_ascii=False,indent=2)+'\n').encode())
if __name__=='__main__':main()
