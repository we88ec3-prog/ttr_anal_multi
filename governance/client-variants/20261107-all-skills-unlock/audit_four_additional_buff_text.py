"""Four known Active/Practice/Buff text candidates, without native dispatch or gameplay formula."""
from pathlib import Path
import sys,json,hashlib,re,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace');D=R/'runtime-observations/2026-11-05-all-skills';O=R.parent/'origin';TC=R.parent/'tc_workspace'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();arcs={};sources=[];tables={}
base=['Table/SkillActiveTable.xml','Table/skillexplaintable.xml','Table/BuffExplainTable.xml','Table/_BuffList.xml']
for root in [R,O,TC]:
 arcs[root]=Archive(root/'Table.stp');tables[root]={}
 for n in base:
  b=arcs[root].read(n);sources.append({'root':str(root),'member':n,'sha256':sha(b)});tables[root][n]=E.fromstring(b.decode('utf-8-sig'))
for n in base:assert arcs[R].read(n)==arcs[O].read(n)
def readPractice(root,n):
 b=arcs[root].read(n);sources.append({'root':str(root),'member':n,'sha256':sha(b)});return E.fromstring(b.decode('utf-8-sig')).find('Practice')
def nums(bid,lv,text):
 pc=[int(x) for x in re.findall(r'(\d+)\s*%',text)];count=re.search(r'(\d+)\s*(?:회|次)',text)
 if bid==107:return {'blockedAttackCountText':int(count[1])}
 if bid==97:return {'physicalDamageReductionPercentText':pc[0],'damageReductionMaximumPercentText':pc[1]}
 if bid==8:return {'receivedDamageRecoveryPercentText':pc[0],'attackCountUntilExpireText':int(count[1])}
 if bid==86:
  defense=re.search(r'(?:모든 방어력이|所有防禦力)\s*(\d+)',text);assert defense
  assert len(pc)==(4 if lv>=6 else 1)
  return {'allDefenseStatIncreaseText':int(defense[1]),'damageReductionPercentText':pc[2] if lv>=6 else pc[0],'criticalChanceIncreasePercentText':pc[0] if lv>=6 else None,'accuracyIncreasePercentText':pc[1] if lv>=6 else None,'damageReductionMaximumPercentText':pc[3] if lv>=6 else None}
 raise AssertionError(bid)
notes={
 2492:{'selfTarget':'KR/TC explicitly caster defensive buff; surrounding enemies attacked.','mechanic':'PowerDefence blocks a specified count. FullActive text ALSO names ordinaryDefence damage reduction; same-nameBuff107 alone does not establish the secondBuff1 grant, itslevel or ordering.','limits':'Do not claim full2492 mechanics from107 alone. Block categories/count consumption, duration units and dispatch are not native-verified.'},
 1297:{'selfTarget':'NeitherKR norTC explicitly includes caster: KR says allies within the circle, TC says teammates. Caster inclusion remains unresolved; no automaticself grant on thistext alone.','mechanic':'Buff97 explicitly PHYSICAL damage reduction, with stated maximum50%; not generic/magic/all-damage reduction. Summoned pixie attack and binding are separate mechanics.','limits':'No ally radius/ownership, conditionalcaster inclusion, summon behavior, durationunits or native dispatch established.'},
 1409:{'selfTarget':'KR explicitly caster and nearby allies; TC describes teammates more generally.','mechanic':'Buff86 separately increases all-defenseSTAT and damage-reductionPERCENT; levels6..10 also grant criticalchance/accuracy. Defense stat cannot be directly added/subtracted to damage without a stat/damageformula.','limits':'Do not turn+20defense into20flat damage reduction, and do not grantBufflevels6..10 as extra learnedlevels absentPractice source.'},
 42:{'selfTarget':'KR/TC explicitly caster buff, with surroundingenemyattack.','mechanic':'KR Buff8 healsHP for70/90/110/130/150% of damage received and expires after5/6/7/8/9 attacks, rawtime12. Recoveryover100% is preserved as text, not clamped.','versionConflict':'KR Active explicitly HP; TC Active says allenergybars. TC BuffExplain says damage-proportion recovery butdoesnotindependentlyestablishMP/SP. Do not restoreallresources fromTC prose.','limits':'Pre/postmitigation damagebasis, lethalhit survival/order, zero/blockedhit count, HPcap, consumption/expiry order and interruption are unknown. Practice69 learned6->Activelevel6 exists butBuff8 level6 explanationdoesnot; no silentclamp/levelreuse.'}
}
cfg=[(1,2492,157,107,'soma_powerdefence'),(6,1297,94,97,'gren_Revival'),(9,1409,136,86,'Epds_HolyShield'),(5,42,69,8,'aelt_reverse')];rows=[]
for role,aid,pid,bid,stem in cfg:
 pm='Table/Skill/Active/'+stem+'.xml';assert arcs[R].read(pm)==arcs[O].read(pm);versions=[]
 for root in [R,TC]:
  active=next(n for n in tables[root][base[0]] if n.get('no')==str(aid));ex=next(n for n in tables[root][base[1]] if n.get('no')==str(aid));buffs=[n for n in tables[root][base[2]] if n.get('name')==active.get('name')];assert len(buffs)==1;buff=buffs[0];assert int(buff.get('no'))==bid;bl=next(n for n in tables[root][base[3]] if n.get('ID')==str(bid));pr=readPractice(root,pm);assert int(pr.get('ID'))==pid and int(pr.get('CharID'))==role
  levs=[]
  for l in pr.findall('LevelData'):
   mods=[dict(m.attrib) for m in l.findall('Modifiers/Modifier')];target=[m for m in mods if m.get('Type')=='SkillLevel' and m.get('TargetSkillID')==str(aid)];assert len(target)==1
   al=int(target[0]['Value']);an=next(n for n in active.findall('LEVEL') if n.get('val')==str(al));levs.append({'levelDataAttributes':dict(l.attrib),'requirements':[dict(n.attrib) for n in l.findall('Requirements/*')],'modifiers':mods,'activeLevel':al,'activeLevelDeclarations':[{'tag':n.tag,'attributes':dict(n.attrib)} for n in an]})
  bv=[{'level':int(l.get('val')),'rawTime':l.get('time'),'fullText':''.join(l.itertext()),'numbersAsWritten':nums(bid,int(l.get('val')),''.join(l.itertext()))} for l in buff.findall('LEVEL')]
  versions.append({'root':str(root),'activeIdentity':dict(active.attrib),'activeFullExplainText':''.join(ex.find('EXPLAIN').itertext()),'practiceIdentity':dict(pr.attrib),'allLevelDataToActive':levs,'sameNameBuffExplainIdentity':dict(buff.attrib),'buffExplainLevels':bv,'buffListSharedIdEntry':dict(bl.attrib),'activeLevelsWithoutEqualNumberBuffExplanation':sorted({l['activeLevel'] for l in levs}-{b['level'] for b in bv}),'extraBuffExplanationLevelsWithoutEqualPracticeActiveLevel':sorted({b['level'] for b in bv}-{l['activeLevel'] for l in levs})})
  # Alllevels remain observed text declarations, not a claimed equal-level grant.
 kr,tc=versions;kb={n['level']:n for n in kr['buffExplainLevels']};tb={n['level']:n for n in tc['buffExplainLevels']};diff=[]
 for lv in sorted(kb.keys()|tb.keys()):
  k,t=kb.get(lv),tb.get(lv)
  if k is None or t is None or k['rawTime']!=t['rawTime'] or k['numbersAsWritten']!=t['numbersAsWritten']:diff.append({'level':lv,'kr':k,'tc':t})
 rows.append({'role':role,'active':aid,'practice':pid,'practiceMember':pm,'sameNameBuffIdCandidate':bid,'linkAuthority':'ExactActive.name==BuffExplain.name candidate; sharedBuffExplain.no->_BuffList.ID exactjoin; NOActive->Buffdispatch claim','versions':versions,'numericOrRawTimeDifferences':diff,'mechanicalReview':notes[aid],'officialDispatchEstablished':False})
out={'schema':'FOUR_ADDITIONAL_BUFF_TEXT_CANDIDATES_V1','authority':'KNOWN_TABLE_ONLY_LEVEL_AND_TEXT_RELATIONS_NOT_NATIVE_DISPATCH_OR_FORMULA','rows':rows,'timeBoundary':'BuffExplain rawtime values recorded; seconds/native expiryclock not reverified.','limits':['No native/motion/EFF/provider/game/Host/Server/shared/Git investigation or changes. Root independently checks referencedEFF resources.','Practice learnedlevel->Activelevel is explicit; Activelevel->same-numberBufflevel is NOTestablished by theseTables.','Percent/count/stat words are descriptive source values; mitigationstacking, targetfilter, damageformula, timers and native publicationtriggers remain separate.'],'sourceMembers':sources,'carrierSha256':[{'root':str(root),'sha256':sha((root/'Table.stp').read_bytes())} for root in arcs]}
f=D/'four-additional-buff-text-candidates-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(str(f));print(sha(f.read_bytes()))
