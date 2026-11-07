"""Known Table-only name candidates and per-level buff text values; not Active->Buff dispatch."""
from pathlib import Path
import sys,json,hashlib,re,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace');D=R/'runtime-observations/2026-11-05-all-skills';O=R.parent/'origin';TC=R.parent/'tc_workspace'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();tables={};sources=[];carriers=[]
names=['Table/SkillActiveTable.xml','Table/skillexplaintable.xml','Table/BuffExplainTable.xml','Table/_BuffList.xml']
for root in [R,O,TC]:
 a=Archive(root/'Table.stp');tables[root]={};carriers.append({'root':str(root),'carrier':'Table.stp','sha256':sha((root/'Table.stp').read_bytes())})
 for member in names:
  b=a.read(member);sources.append({'root':str(root),'member':member,'sha256':sha(b)});tables[root][member]=E.fromstring(b.decode('utf-8-sig'))
for n in names:assert next(s['sha256'] for s in sources if s['root']==str(R) and s['member']==n)==next(s['sha256'] for s in sources if s['root']==str(O) and s['member']==n)
assert next(s['sha256'] for s in sources if s['root']==str(R) and s['member']=='Table/BuffExplainTable.xml')=='d6634058bfb5b7b577e47b092fb487dd47a154b0bc1b551c1cbdcd585136c57c'
def values(buffid,level,text):
 nums=[int(n) for n in re.findall(r'\d+',text)];pc=[int(n) for n in re.findall(r'(\d+)\s*%',text)]
 if buffid==1:assert len(pc)==2;return {'damageReductionPercentText':pc[0],'damageReductionMaximumPercentText':pc[1]}
 if buffid==2:assert len(nums)==3;return {'physicalAttackIncreaseText':nums[0],'damageReductionPercentText':nums[1],'damageReductionMaximumPercentText':nums[2]}
 if buffid in [3,4]:assert len(nums)==1;return {'blockedAttackCountText':nums[0]}
 if buffid==6:
  assert len(pc)==(2 if 6<=level<=10 else 1);return {'evasionIncreasePercentText':pc[0],'attackSpeedIncreasePercentText':pc[1] if len(pc)==2 else None}
 raise AssertionError(buffid)
cfg=[(1,4,1),(2,13,2),(2,15,3),(3,25,4),(4,34,6)];rows=[]
for role,aid,bid in cfg:
 versions=[]
 for root in [R,TC]:
  active=next(n for n in tables[root][names[0]] if n.get('no')==str(aid));ex=next(n for n in tables[root][names[1]] if n.get('no')==str(aid));activeName=active.get('name');same=[n for n in tables[root][names[2]] if n.get('name')==activeName];assert len(same)==1;buff=same[0];assert int(buff.get('no'))==bid
  bl=[dict(n.attrib) for n in tables[root][names[3]] if n.get('ID')==str(bid)];assert len(bl)==1
  levs=[]
  for n in buff.findall('LEVEL'):
   lv=int(n.get('val'));text=''.join(n.itertext());levs.append({'level':lv,'rawTime':n.get('time'),'fullText':text,'numbersAsWritten':values(bid,lv,text)})
  versions.append({'root':str(root),'activeIdentity':dict(active.attrib),'activeFullExplainText':''.join(ex.find('EXPLAIN').itertext()),'buffExplainIdentity':dict(buff.attrib),'buffListBySameId':bl[0],'levels':levs})
 kr,tc=versions;kd={n['level']:n for n in kr['levels']};td={n['level']:n for n in tc['levels']};diff=[]
 for lv in sorted(kd.keys()|td.keys()):
  k,t=kd.get(lv),td.get(lv)
  if k is None or t is None or k['rawTime']!=t['rawTime'] or k['numbersAsWritten']!=t['numbersAsWritten']:diff.append({'level':lv,'kr':k,'tc':t})
 notes=[]
 if bid==3:notes.append('Both BuffExplain versions explicitly restrict blocks to bullets/ordinary attacks, refining the more general TC Active explanation; do not widen to all attacks.')
 if bid==4:notes.append('KR says completely block all attacks until the count is consumed; TC says a fixed number of invincible states. This does not prove uninterrupted invulnerability for the fulltime.')
 if bid==6:notes.append('Level11 literally declares200% evasion increase in both versions; unusual value retained, not clamped or silently admitted as normal gameplay. Levels6..10 also add attack speed; level11 does not state attack speed.')
 rows.append({'role':role,'active':aid,'sameNameBuffIdCandidate':bid,'linkAuthority':'EXACT_NAME_MATCH_ACTIVE_TO_BUFF_CANDIDATE_NOT_NATIVE_DISPATCH; BuffExplain.no toBuffList.ID is an exact shared identifier join','versions':versions,'numericOrRawTimeVersionDifferences':diff,'semanticNotes':notes,'timeAuthority':'XML time attribute raw value only; seconds/lifetime consumption not reverified natively in this task','officialActiveBuffDispatchEstablished':False})
healing=[]
for root in [R,TC]:
 active=next(n for n in tables[root][names[0]] if n.get('no')=='478');ex=next(n for n in tables[root][names[1]] if n.get('no')=='478');exact=[dict(n.attrib) for n in tables[root][names[2]] if n.get('name')==active.get('name')];healing.append({'root':str(root),'active':478,'activeName':active.get('name'),'fullExplainText':''.join(ex.find('EXPLAIN').itertext()),'sameNameBuffExplainMatches':exact,'buffExplainEntriesInspectedForName':len(tables[root][names[2]]),'timingNumbersRecovered':None})
out={'schema':'NAMED_DEFENSIVE_BUFF_TEXT_CANDIDATES_V1','authority':'EXACT_TABLE_TEXT_VALUES_AND_SHARED_BUFF_IDENTIFIER_NOT_ACTIVE_TO_BUFF_NATIVE_DISPATCH','rows':rows,'optionalHealingField478':{'status':'NO_EXACT_SAME_NAME_BUFFEXPLAIN_ROW_IN_KNOWN_MEMBERS','versions':healing,'adoption':'NOT_PART_OF_THIS_BATCH; no tick interval/heal amount inferred by nearby name or ID'},'limits':['Name equality creates a reviewable candidate, not evidence that Active dispatch grants thatBuffID or uses same learnedLevel.','BuffExplain no and_BuffList ID agree; referenced EFF names are metadata only, not opened or geometry proof.','Text percentages/counts/rawtime do not prove additive/multiplicative stacking, ordering, duration units, event categories or native success packets.','Descriptions support defensive gameplay intent; emptyATTACK/HEAL must not become a no-effect claim.','No native/provider/game/Host/Client/Server/shared/Git actions; known Table members only.'],'sourceMembers':sources,'carriers':carriers}
f=D/'named-defensive-buff-text-candidates-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(str(f));print(sha(f.read_bytes()));print([(r['active'],r['sameNameBuffIdCandidate'],len(r['numericOrRawTimeVersionDifferences'])) for r in rows])
