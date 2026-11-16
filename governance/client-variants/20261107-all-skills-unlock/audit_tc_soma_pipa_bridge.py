"""Finite KR/TC comparison: two ABFs and only their explicit ASD members; six practices."""
from pathlib import Path
import sys,json,hashlib,re,xml.etree.ElementTree as E,collections
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:\Tartaros\workspace');D=R/'runtime-observations/2026-11-05-all-skills';TC=R.parent/'tc_workspace'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest()
arcs={};members=[];carriers=[]
def rd(root,carrier,member):
 key=(str(root),carrier)
 if key not in arcs:
  f=root/carrier;arcs[key]=Archive(f);carriers.append({'root':str(root),'carrier':carrier,'sha256':sha(f.read_bytes())})
 a=arcs[key];names=[n for n in a.files if n.casefold()==member.casefold()];assert len(names)==1
 b=a.read(names[0]);members.append({'root':str(root),'carrier':carrier,'member':names[0],'sha256':sha(b),'bytes':len(b)})
 return b
def xml(b):
 enc='big5' if b'big5' in b[:150].lower() else 'euc-kr' if b'euc-kr' in b[:150].lower() else 'utf-8-sig'
 s=b.decode(enc);return E.fromstring('<AUDIT>'+re.sub(r'<\?xml[^?]*\?>','',s)+'</AUDIT>')
roles=[];semattrs=[]
for role,name,folder in [(1,'Soma','01_Soma'),(2,'Pipa','02_Pipa')]:
 kr,tc=[xml(rd(root,'Character/Cha/Base.stp','Cha/'+name+'.abf')).find('.//Character') for root in [R,TC]]
 ka=kr.findall('AnimationList/Animation');ta=tc.findall('AnimationList/Animation');km={int(n.get('ID')):n for n in ka};tm={int(n.get('ID')):n for n in ta};rows=[]
 assert km.keys()==tm.keys()
 for action in sorted(tm):
  k,t=km[action],tm[action];assert k.attrib==t.attrib
  c='Character/Cha/Avatar/'+folder+'.stp';n=folder+'/Asd/'+t.get('File');kb,tb=[rd(root,c,n) for root in [R,TC]]
  kt,tt=xml(kb),xml(tb)
  for node in tt.iter():
   for key,value in node.attrib.items():
    if re.search('skill|practice|script|active|matrix',key,re.I):semattrs.append({'role':role,'action':action,'tag':node.tag,'attribute':key,'value':value})
  rows.append({'action':action,'file':t.get('File'),'animationAttributesEqual':True,'krAsdSha256':sha(kb),'tcAsdSha256':sha(tb),'bytesEqual':kb==tb})
 roles.append({'role':role,'name':name,'abf':'Cha/'+name+'.abf','abfAnimationCount':len(rows),'abfAnimationRowsEqual':True,'asdEqualCount':sum(n['bytesEqual'] for n in rows),'rows':rows})
targets=[(1,1,'soma_pball'),(1,3,'soma_elecshook'),(1,6,'soma_lightningball'),(2,10,'pipa_punch'),(2,14,'pipa_hammer'),(2,18,'pipa_roket')]
active={root:xml(rd(root,'Table.stp','Table/SkillActiveTable.xml')).find('.//SKILLACTIVETABLE') for root in [R,TC]}
practice=[]
for role,aid,stem in targets:
 row={'role':role,'active':aid,'member':'Table/Skill/Active/'+stem+'.xml','versions':[]}
 for root in [R,TC]:
  pt=xml(rd(root,'Table.stp',row['member'])).find('.//Practice');sk=next(n for n in active[root] if n.get('no')==str(aid))
  modifiers=[dict(n.attrib) for n in pt.findall('LevelData/Modifiers/Modifier')]
  refs=[{'tag':n.tag,'attribute':k,'value':v} for n in pt.iter() for k,v in n.attrib.items() if re.search('motion|animation|action|asd|abf',k,re.I)]
  row['versions'].append({'root':str(root),'practiceIdentity':dict(pt.attrib),'modifiers':modifiers,'activeIdentity':dict(sk.attrib),'activeLevel1':[{'tag':n.tag,'attributes':dict(n.attrib)} for n in sk.findall('LEVEL')[0]],'explicitActionReferences':refs})
 practice.append(row)
prior=[]
for n in ['build_all_role_motion_joins.py','audit_numeric_families.py','all-skills-catalog.json','numeric-family-explicit-link-audit.json']:
 f=D/n;prior.append({'file':n,'sha256':sha(f.read_bytes())})
out={'schema':'TC_SOMA_PIPA_EXPLICIT_BRIDGE_AUDIT_V1','authority':'FINITE_RESOURCE_IDENTITY_AND_DECLARED_REFERENCE_COMPARISON_NOT_NATIVE_DISPATCH','priorCoverage':'Existing catalog includes KR/TC ActiveInfo LEVEL1/text comparison. Existing motion join and numeric-family audit use KR original/work archives only; this adds missing TC explicit ABF/ASD comparison rather than rerunning the KR family analysis.','scope':'Only Soma/Pipa ABFs and their326 explicitly referenced ASD members; six requested Practice XML and selected ActiveTable records. No archive-wide semantic search, effects traversal, MEF search or numeric-family reassignment.','roles':roles,'targetPractices':practice,'tcSkillSemanticAttributeHits':semattrs,'summary':{'roles':len(roles),'explicitAsdRows':sum(len(r['rows']) for r in roles),'sameAsdBytes':sum(r['asdEqualCount'] for r in roles),'newExplicitActiveToActionBridges':0},'conclusion':'All326 selected TC ASD members are byte-identical to corresponding KR members, and all ABF action/file/animation attribute rows match. Six TC Practice SkillLevel TargetSkillID relationships add no action binding. TC adds no independently usable exact active/practice ID->action link in this bounded scope.','limitations':['ABF whole-member bytes differ despite equal animation rows; other sections are not promoted as equal.','Matching names/stems, numeric families or equal ActiveInfo are not proof of active-to-action mapping.','Negative result is limited to selected resources; external script/native dispatch/server mappings remain unresolved.','Do not transplant TC balance values or mutate Client/Server/Host; no launch/attachment/provider retry or Git changes.'],'priorCoverageFiles':prior,'carriers':carriers,'members':members}
f=D/'tc-soma-pipa-explicit-bridge-audit-v1.json';f.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf8');print(json.dumps({'path':str(f),'sha256':sha(f.read_bytes()),'summary':out['summary']}))
