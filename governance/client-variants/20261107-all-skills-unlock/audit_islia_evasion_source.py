"""Finite Practice54/Active34/Buff6 review; no game or source-resource export."""
from pathlib import Path
import hashlib,json,re,sys,xml.etree.ElementTree as E

ROOT=Path(__file__).resolve().parents[4]
sys.path.insert(0,str(ROOT/'anal'))
from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
here=Path(__file__).parent
prior_path=ROOT/'runtime-observations/2026-11-05-all-skills/named-defensive-buff-text-candidates-v1.json'
raw=prior_path.read_bytes()
assert sha(raw)=='e1a10b5ea0fab9eaf52dfaaea46c264f6ce5f3d05aa640db2cb827a22439f419'
prior=next(r for r in json.loads(raw)['rows'] if r['sameNameBuffIdCandidate']==6)
versions=[];original_members={}
for label,root in [('originalKr',ROOT.parent/'origin'),('workingKr',ROOT),('tc',ROOT.parent/'tc_workspace')]:
    archive=Archive(root/'Table.stp')
    member='Table/Skill/Active/isla_dodge.xml'
    data=archive.read(member)
    if label=='originalKr':original_members[member]=data
    if label=='workingKr':assert data==original_members[member]
    tree=E.fromstring('<R>'+re.sub(r'<\?xml.*?\?>','',data.decode('utf-8-sig'))+'</R>')
    practice=tree.find('.//Practice')
    assert practice.get('ID')=='54' and practice.get('CharID')=='4'
    levels=[]
    for level in practice.findall('LevelData'):
        modifiers=[dict(m.attrib) for m in level.findall('Modifiers/Modifier') if m.get('Type')=='SkillLevel']
        assert len(modifiers)==1 and modifiers[0]['TargetSkillID']=='34'
        levels.append({'learnedLevel':int(level.get('Level')),'activeLevel':int(modifiers[0]['Value'])})
    assert levels==[{'learnedLevel':i,'activeLevel':i} for i in range(1,6)]
    versions.append({'version':label,'member':member,'memberSha256':sha(data),'declaredLevels':levels})

original=Archive(ROOT.parent/'origin/Effect/Effect.stp')
member='Effect/Assist/Buff/S_Buff_BasisEvasion01.eff'
effect=original.read(member)
assert effect==Archive(ROOT/'Effect/Effect.stp').read(member)
levels=[{'buffLevel':r['level'],'rawTime':float(r['rawTime']),**r['numbersAsWritten']}
        for r in prior['versions'][0]['levels']]
assert not prior['numericOrRawTimeVersionDifferences']
out={'schema':'ISLIA_EVASION_SOURCE_BOUNDARY_V1_NOT_NATIVE_MEF',
     'authority':'SOURCE_TEXT_LEVELS_AND_EXACT_PRACTICE_DECLARATIONS_NOT_NATIVE_EVASION_FORMULA',
     'priorBuffReviewSha256':sha(raw),'role':4,'practice':54,'active':34,'sameNameBuffCandidate':6,
     'practiceVersions':versions,'sourceBuffLevels':levels,
     'directEffect':{'carrier':'Effect/Effect.stp','member':member,'sha256':sha(effect),'originalWorkingEqual':True},
     'limits':['OnlyPractice learned1..5 are admitted; BuffExplain6..11 do not grant more learned/Active levels.',
               'Same-name Active/Buff association, same-level grant and raw seconds are explicit lab policies.',
               'Base evasion20 and relative-increase formula are Server hypotheses, not source hit formulas.',
               'Direct EFF presence is not complete loader/dependency/rendering acceptance.']}
dest=here/'islia-evasion-source-boundary-v1.json'
dest.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8')
print(json.dumps({'declaredPracticeLevels':5,'sourceBuffLevels':len(levels),'sha256':sha(dest.read_bytes())}))
