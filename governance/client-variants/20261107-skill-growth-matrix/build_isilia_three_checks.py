"""Read only three exact Talent files and reuse already checked descriptions."""
from pathlib import Path
import json,sys,hashlib,xml.etree.ElementTree as E
R=Path(r'E:\Tartaros\workspace');D=Path(__file__).parent
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
a,w=Archive(R.parent/'origin/Table.stp'),Archive(R/'Table.stp');src=json.loads((D/'isilia-27.json').read_text(encoding='utf-8-sig'))
sha=lambda b:hashlib.sha256(b).hexdigest()
def node(n):return {'tag':n.tag,'attributes':dict(n.attrib),'children':[node(x) for x in n]}
rows=[];members=[]
for active in [32,474,2505]:
 r=next(r for r in src['rows'] if r['active']==active);member=r['talentScriptLevels'][0]['source'];b,wb=a.read(member),w.read(member);assert b==wb
 members.append({'member':member,'originalSha256':sha(b),'workingSha256':sha(wb),'equal':True})
 pr=E.fromstring(b).find('Practice')
 for l in pr.findall('LevelData'):
  lev=int(l.get('Level'));t=next(t for t in r['talentScriptLevels'] if t['talentLearnedLevel']==lev)
  rows.append({'role':4,'active':active,'talentPractice':int(pr.get('ID')),'talentLearnedLevel':lev,'source':member,'modifiers':[dict(m.attrib) for m in l.findall('Modifiers/Modifier')],'interrupts':[node(i) for i in l.findall('Interrupts/Interrupt')],'descriptions':t['descriptions'],'numericTextCheck':{32:'KR/TC both cooldown reduction1/2 seconds; typed Consume interrupt Cooltime=-10/-20 exists independently of SkillScriptLevel.',474:'KR/TC both contain4/5, but KR says count increases4/5 while TC says increases TO4/5. Delta versus total remains unresolved.',2505:'KR/TC both explicitly increase target count TO2/3/4.'}[active]})
result={'schema':'tartaros-isilia-three-talent-source-checks-v1','rows':rows,'newMemberIdentities':members,'limitations':['No ScriptLevel number to Basis/Average/Exper/Master/Super mapping inferred.','Cooltime raw integer to seconds is supported by aligned description, not a new native consumer proof.','1427 numeric tokens agree but delta/total semantics are not interchangeable.']}
(D/'isilia-three-source-checks.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode())
print('three talent checks rows',len(rows))
