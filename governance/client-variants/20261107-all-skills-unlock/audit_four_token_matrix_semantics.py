"""Independent Table-only matrix/text validation for four token hypotheses."""
from pathlib import Path
import sys,json,hashlib,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:/Tartaros/workspace');D=R/'runtime-observations/2026-11-05-all-skills';O=R.parent/'origin';TC=R.parent/'tc_workspace'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();arcs={};members=[]
def rd(root,n):
 if root not in arcs:arcs[root]=Archive(root/'Table.stp')
 b=arcs[root].read(n);members.append({'root':str(root),'member':n,'sha256':sha(b)});return b
def original(n):
 a,b=rd(O,n),rd(R,n);assert a==b;return a
matrixMember='Table/Skill/Matrix/CharacterMatrices.xml';matrix=E.fromstring(original(matrixMember).decode('utf-8-sig'));catPath=D/'all-skills-catalog.json';cat=json.loads(catPath.read_text(encoding='utf8'));hypPath=D/'four-numeric-token-candidates-v1.json';hyp=json.loads(hypPath.read_text(encoding='utf8'))
tables={root:{n:E.fromstring((original(n) if root==R else rd(root,n)).decode('utf-8-sig')) for n in ['Table/SkillActiveTable.xml','Table/skillexplaintable.xml','Table/PracticeExplainTable.xml']} for root in [R,TC]}
review={
 3018:{'support':'KR/TC both describe repeated forward sword-energy attacks plus a temporary caster duplicate attacking again. extinction component token is semantically compatible with BladesExtinction, beyond mere family-number ordering.','conflict':'A token/duplicate-looking effect does not prove server spawn, hit sequence or exact active->action dispatch.','chargeText':'KR explicitly says hold the energy button continuously to reach emission; TC wording says repeatedly click V. This translation discrepancy cannot redefine native hold semantics.','variants':'All210/211/212/213 remain separate; no level/ScriptLevel assignment supplied.'},
 3041:{'support':'KR describes pulling nearby enemies, backward evasion then many forward throwing stars. TC retains backward evasion/forward stars but omits the pulling clause. dancesuri token only supports variant201 as an individual semantic candidate.','conflict':'202/203/204 lack literal dancesuri token and have distinct raw split sequences; do not inherit201 confidence or treat them as equivalent variants. No pull/movement/hit implementation follows from text alone.','chargeText':'KR says hold continuously for emission; TC repeatedly-click V wording conflicts as an input instruction. Keep KR text and native input evidence distinct from translation.','variants':'201 candidate only on this token evidence;202/203/204 remain unassigned, not a recovered sequence.'},
 3047:{'support':'KR/TC describe an ice explosion and ice shield flying forward along a line to attack targets, with freezing and Holy Spirit punishment/judgment interactions. holyshield component is compatible with an offensive shield projectile.','conflict':'This is NOT text support for a stationary self-only defense shield/buff. Mapping it to generic self shield mechanics would contradict both full descriptions. Targeting, projectile motion and effects are still not recovered native dispatch.','chargeText':'No hold/emission requirement in full EXPLAIN; exact matrix row is tier0. Do not add V prerequisite merely because a component says holyshield.','variants':'216/217/218/219 all retain separate effect/variant identities; no default or level assignment.'},
 2997:{'support':'KR explicitly throws a fire bottle forward with chance of ignition; TC says a forward fire projectile with burning. C_Pipa_firebottle component is a direct semantic match to the KR meaning.','conflict':'Do not collapse this new active into old grenade19 merely because both are thrown explosives; IDs, Practice and explanation differ. Component remains presentation evidence rather than official action linkage.','chargeText':'Full EXPLAIN has no V prerequisite; matrix4 tier0.','variants':'188/189/190/191 remain separate; no minimum or suffix-based assignment.'}
}
keys={1:('Z',1),2:('X',2),3:('C',4),4:('Z+X',3),5:('Z+C',5),6:('X+C',6)}
rows=[]
for g in hyp['groups']:
 role,active,pid=g['role'],g['active'],g['practice'];pm=g['practiceMember'];p=E.fromstring(original(pm).decode('utf-8-sig')).find('Practice');assert int(p.get('ID'))==pid and int(p.get('CharID'))==role
 modifiers=[dict(n.attrib) for n in p.findall('LevelData/Modifiers/Modifier') if n.get('Type')=='SkillLevel'];assert {int(n['TargetSkillID']) for n in modifiers}=={active}
 slots=[]
 for char in matrix:
  if char.get('CharID')!=str(role):continue
  for mx in char.findall('Matrix'):
   for tier in mx.findall('KeyInfo/Tier'):
    for key in tier:
     if key.get('skill')!=str(active):continue
     col=int(key.get('key'));name,mask=keys[col]
     prior=next(e for c in cat['characters'] if c['role']==role for e in c['matrix_entries'] if e['active_skill']==active and e['matrix']==int(mx.get('ID')) and e['tier']==int(tier.get('tier')) and e['column']==col);assert mask==prior['input_mask_candidate']
     slots.append({'resourceIdentity':{'CharID':role,'MatrixID':int(mx.get('ID')),'tier':int(tier.get('tier')),'key':col,'skill':active},'keyElement':dict(key.attrib),'existingCatalogInputProjection':{'buttons':name,'mask':mask,'kind':prior['input_kind'],'authority':'Existing catalog input_mask_candidate projection, checked equal; key column itself is exact resource data, not a new packet ABI claim.'}})
 versions=[]
 for root in [R,TC]:
  a=next(n for n in tables[root]['Table/SkillActiveTable.xml'] if n.get('no')==str(active));e=next(n for n in tables[root]['Table/skillexplaintable.xml'] if n.get('no')==str(active));pn=next(n for n in tables[root]['Table/PracticeExplainTable.xml'] if n.get('ID')==str(pid));text=''.join(e.find('EXPLAIN').itertext());versions.append({'root':str(root),'practiceName':pn.get('NAME'),'activeIdentity':dict(a.attrib),'fullExplainText':text,'explainUtf8Sha256':sha(text.encode('utf8'))})
 rows.append({'role':role,'active':active,'practice':pid,'practiceMember':pm,'practiceIdentity':dict(p.attrib),'skillLevelModifiers':modifiers,'exactKrMatrixSlots':slots,'versions':versions,'semanticReview':review[active],'officialMotionMappingEstablished':False,'selectedMotion':None})
out={'schema':'FOUR_TOKEN_MATRIX_TEXT_SEMANTICS_REVIEW_V1','authority':'EXACT_KR_TABLE_RELATIONS_AND_FULL_KR_TC_EXPLAIN_WITH_EXPLICIT_REVIEW_INFERENCES','candidateInputSha256':sha(hypPath.read_bytes()),'catalogInputSha256':sha(catPath.read_bytes()),'rows':rows,'summary':'All four Practice->Active IDs and unique KR matrix slots are confirmed. Semantic component candidates remain unproven active-to-action links.3047 is offensive ice-shield projectile, not generic self shield.3041 token evidence does not transfer to its other variants.','scope':'Known Table members only, complete skill EXPLAIN nodes (not abbreviated); no ASD/EFF rescan,294 audit, clock or native dispatch claim.','limits':['Full descriptions establish documented intent, not operational Server values or verified gameplay implementation.','Input mask uses prior catalog projection; exact matrix key/tier identity is separately preserved.','No Client/Server/Host/shared edits, game/provider/attachment/Git actions.'],'sourceMembers':members,'carrierIdentities':[{'root':str(root),'carrier':'Table.stp','sha256':sha((root/'Table.stp').read_bytes())} for root in arcs]}
f=D/'four-token-matrix-text-semantics-review-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(str(f));print(sha(f.read_bytes()));print([(r['role'],r['active'],r['exactKrMatrixSlots'][0]['resourceIdentity']) for r in rows])
