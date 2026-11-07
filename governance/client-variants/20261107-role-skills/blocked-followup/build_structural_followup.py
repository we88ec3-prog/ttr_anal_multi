"""Bounded read-only schema/identity follow-up for16 blocked lab bindings.
Does not select nearest names or export raw game members.
"""
from pathlib import Path
import sys,json,hashlib,xml.etree.ElementTree as ET,re,collections
R=Path(r'E:\Tartaros\workspace');O=R.parent/'origin';D=R/'runtime-observations/2026-11-05-all-skills';OUT=R/'CLIENT/evidence/20261107-role-skills/blocked-followup'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
c=json.loads((D/'all-skills-catalog.json').read_text(encoding='utf-8-sig'));j=json.loads((D/'all-role-motion-joins.json').read_text(encoding='utf-8-sig'))
blocked=json.loads((OUT.parent/'blocked-rows.json').read_text(encoding='utf-8-sig'))
practices={p['id']:p for p in c['practices'] if p['category']=='ActiveSkill'}
archives={};identities=[]
def read(carrier,member):
 if carrier not in archives:archives[carrier]=(Archive(O/carrier),Archive(R/carrier))
 a,b=archives[carrier];n=next(n for n in a.files if n.casefold()==member.casefold());m=next(n for n in b.files if n.casefold()==member.casefold());raw,working=a.read(n),b.read(m);assert raw==working
 identities.append({'carrier':carrier,'member':n,'original_sha256':sha(raw),'working_sha256':sha(working),'matched':True});return raw
def xml(raw,fragment=False):
 text=raw.decode('euc-kr' if b'euc-kr' in raw[:120].lower() else 'utf-8-sig');text=re.sub(r'^\s*<\?xml[^?]*\?>','',text)
 return ET.fromstring('<R>'+text+'</R>' if fragment else text)
def inventory(root):
 return {'tags':dict(collections.Counter(n.tag for n in root.iter())),'attribute_names':sorted({k for n in root.iter() for k in n.attrib})}
practice_scans=[]
for z in blocked:
 pr=practices[z['practice']];raw=read('Table.stp',pr['source']);t=xml(raw)
 fields=[{'tag':n.tag,'attribute':k,'value':v} for n in t.iter() for k,v in n.attrib.items() if re.search(r'(motion|anim|effect|alias|file)',k,re.I)]
 practice_scans.append({'role':z['role'],'tier':z['tier'],'mask':z['mask'],'practice':z['practice'],'active':z['active'],'member':pr['source'],**inventory(t),'explicit_motion_animation_effect_alias_file_fields':fields,'level1_skill_targets':[n.attrib for n in t.findall("Practice/LevelData[@Level='1']/Modifiers/Modifier")]})
active=xml(read('Table.stp','Table/SkillActiveTable.xml'));active_rows=[]
for z in blocked:
 n=next(n for n in active if n.get('no')==str(z['active']));active_rows.append({'role':z['role'],'active':z['active'],**inventory(n),'explicit_motion_fields':[{k:v for k,v in e.attrib.items() if re.search(r'(motion|anim|effect|alias|file)',k,re.I)} for e in n.iter() if any(re.search(r'(motion|anim|effect|alias|file)',k,re.I) for k in e.attrib)]})
extra=[]
for member in ['Table/CharSkill.xml','Table/EffectList.xml','Table/EffectCategoryMapper.xml','Table/IndependentSkillEffect.xml','Table/AI/Soma_Dealer.xml','Table/AI/Pipa_Dealer.xml','Table/AI/Grnt_Dealer.xml']:
 t=xml(read('Table.stp',member));extra.append({'member':member,**inventory(t)})
# Filename contrasts are diagnostic inventory only, not proposed mappings.
diag={1:[101,113],2:[101,108],5:[101,116],6:[105,108],7:[101]};motion_scans=[]
for role in j['roles']:
 if role['role'] not in diag:continue
 abf=xml(read('Character/Cha/Base.stp',role['abf_member']))
 extra.append({'role':role['role'],'member':role['abf_member'],**inventory(abf)})
 for m in role['motion_metadata']:
  if m['motion_id'] not in diag[role['role']]:continue
  t=xml(read(m['asd_carrier'],m['asd_member']),True);heads=[n.attrib for n in t.iter('AnimationHeader')]
  motion_scans.append({'role':role['role'],'motion':m['motion_id'],'member':m['asd_member'],**inventory(t),'header_id_names':[{'ID':h.get('ID'),'NAME':h.get('NAME')} for h in heads],'not_a_skill_binding':True})
effect_scans=[]
for member in ['Effect/Character/C_Soma-BasisAttack01.eff','Effect/Character/C_Soma-BasisElecshock01.eff','Effect/Character/C_Pipa-BasisHammering01.eff']:
 raw=read('Effect/Effect.stp',member);t=xml(raw);effect_scans.append({'member':member,**inventory(t),'explicit_skill_motion_id_fields':[{'tag':n.tag,'key':k,'value':v} for n in t.iter() for k,v in n.attrib.items() if re.search(r'(skill|motion|animation)',k,re.I)]})
source=R/'anal-multi/kr-bulk-roy/9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91/functions'
code=[{'path':str((source/n).relative_to(R/'anal-multi')).replace('\\','/'),'sha256':sha((source/n).read_bytes())} for n in ['0x530890.c','0x546100.c','0x4b01c0.c','0x4c8a90.c']]
result={'schema':'blocked-skill-bindings-structural-followup-v1','ready_promotions':[],
        'scope':'16 blocked Practice and ActiveSkill entries;7 auxiliary Table members;5 role ABFs;9 selected ASD filename contrasts;3 selected EFFs;4 existing source functions.',
        'practice_scans':practice_scans,'active_scans':active_rows,'auxiliary_scans':extra,'motion_filename_contrasts':motion_scans,'effect_scans':effect_scans,
        'identities':identities,'existing_source_identities':code,'conclusion':'No explicit ActiveSkillID-to-motion or declared alias bridge found in this bounded scope. Preserve all16 blocked rows; do not infer equivalence from names.',
        'not_claimed':'No whole-client/whole-resource absence claim. No game/Server files changed, no target execution/attachment, no MEF search.'}
OUT.mkdir(parents=True,exist_ok=True);(OUT/'structural-followup.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode('utf-8'))
print('scans',len(practice_scans),len(active_rows),len(motion_scans),'original-working member checks',len(identities),'READY',len(result['ready_promotions']))
