"""Four explicit spelling/word-form hypotheses, not automatic filename aliases."""
from pathlib import Path
import sys,json,re,hashlib,collections,xml.etree.ElementTree as E
R=Path(sys.argv[1]) if len(sys.argv)>1 else Path(r'E:\Tartaros\workspace');O=R.parent/'origin';TC=R.parent/'tc_workspace';D=R/'runtime-observations/2026-11-05-all-skills'
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
sha=lambda b:hashlib.sha256(b).hexdigest();arcs={};sources={}
catalog=json.loads((D/'all-skills-catalog.json').read_text(encoding='utf-8'));joins=json.loads((D/'all-role-motion-joins.json').read_text(encoding='utf-8'))
def read(kind,carrier,member):
 key=(kind,carrier)
 if key not in arcs:arcs[key]=Archive((O if kind=='KR' else TC)/carrier)
 b=arcs[key].read(member);row={'kind':kind,'carrier':carrier,'member':member,'sha256':sha(b)}
 if kind=='KR':
  wk=('WORK',carrier)
  if wk not in arcs:arcs[wk]=Archive(R/carrier)
  w=arcs[wk].read(member);assert b==w;row.update(workingSha256=sha(w),workingEqual=True)
 sources[(kind,carrier,member)]=row;return b
def xml(b,fragment=False):
 text=b.decode('euc-kr' if b'euc-kr' in b[:150].lower() else 'utf-8-sig');text=re.sub(r'^\s*<\?xml[^?]*\?>','',text)
 return E.fromstring('<ROOT>'+text+'</ROOT>' if fragment else text)
def canonical(n):
 return {'tag':n.tag,'attributes':{k:v for k,v in n.attrib.items() if not(n.tag=='AnimationHeader' and k in ['ID','NAME'])},'text':(n.text or '').strip(),'tail':(n.tail or '').strip(),'children':[canonical(x) for x in n]}
kractive=xml(read('KR','Table.stp','Table/SkillActiveTable.xml'));tcexplain=xml(read('TC','Table.stp','Table/skillexplaintable.xml'))
specs=[(1,3,3,'soma_elecshook','ELECSHOCK','Typographic difference elecshook vs elecshock; not interchangeable with ELECTRIC/ELECARMOR.'),(2,14,20,'pipa_hammer','HAMMERING','Word-form difference hammer vs hammering; specific role2 family only.'),(2,18,25,'pipa_roket','ROCKET','Typographic difference roket vs rocket; specific role2 family only.'),(3,471,43,'sblm_breakthrought','BREAKTHROUGH','Typographic trailing t; not REGBREAK or other break-labelled actions.')]
groups=[]
for role,active,pid,practiceStem,family,reason in specs:
 p=next(p for p in catalog['practices'] if p['id']==pid and p['role']==role);assert Path(p['source']).stem.casefold()==practiceStem.casefold()
 pt=xml(read('KR','Table.stp',p['source']));pn=next(n for n in pt if n.get('ID')==str(pid));pl=pn.find("LevelData[@Level='1']");mods=[dict(n.attrib) for n in pl.findall('Modifiers/Modifier')];assert any(n.get('Type')=='SkillLevel' and n.get('TargetSkillID')==str(active) for n in pl.findall('Modifiers/Modifier'))
 a=next(n for n in kractive if n.get('no')==str(active));a1=a.find("LEVEL[@val='1']");ex=next(n for n in tcexplain if n.get('no')==str(active));text=''.join(ex.find('EXPLAIN').itertext());clips=[]
 roledata=next(r for r in joins['roles'] if r['role']==role);read('KR','Character/Cha/Base.stp',roledata['abf_member'])
 for m in roledata['motion_metadata']:
  if not re.fullmatch('[A-Za-z]+_'+family+r'\d+\.asd',m['abf_file'],re.I):continue
  raw=read('KR',m['asd_carrier'],m['asd_member']);assert sha(raw)==m['asd_sha256'];t=xml(raw,True);h=t.find('.//AnimationHeader');fx=[];labels=[]
  for e in m['effects']:
   eb=read('KR','Effect/Effect.stp',e['path']);assert sha(eb)==e['sha256'];et=xml(eb);variant=re.search(r'-(Basis|Average|Exper|Master|Super)',e['path'],re.I)
   if variant:labels.append(variant[1].lower())
   fx.append({'member':e['path'],'sha256':sha(eb),'resourceVariantLabel':variant[1] if variant else None,'header':dict(et.find('Header').attrib),'elements':[{'tag':n.tag,'attributes':dict(n.attrib),'children':[{'tag':c.tag,'attributes':dict(c.attrib)} for c in n]} for n in et.findall('.//Element')],'declaredObjectFiles':sorted({n.get('File') for n in et.iter() if n.get('File')}),'explicitSkillOrActionReferences':[{'tag':n.tag,'attribute':k,'value':v} for n in et.iter() for k,v in n.attrib.items() if re.search('skillid|motionid|activeid|practiceid|scriptlevel',k,re.I)]})
  sig={'ASD':canonical(t),'ABFLength':m['abf_length_frame_units'],'headerMatchesAbf':m['header_matches_abf']}
  clips.append({'motion':m['motion_id'],'abfFile':m['abf_file'],'asdMember':m['asd_member'],'asdSha256':sha(raw),'headerAttributes':dict(h.attrib),'animationData':dict(h.find('AnimationData').attrib),'splitData':[dict(n.attrib) for n in h.findall('ReferIndex/SpliteData')],'abfLengthFrameUnits':m['abf_length_frame_units'],'timingAuthority':'RAW_FRAMES_FPS_DELAY_ONLY; no timing formula adopted by this review','effects':fx,'explicitResourceVariantLabels':sorted(set(labels)),'equivalenceSha256':sha(json.dumps(sig,sort_keys=True,separators=(',',':')).encode())})
 assert clips
 byhash=collections.defaultdict(list)
 for cl in clips:byhash[cl['equivalenceSha256']].append(cl['motion'])
 basis=[cl['motion'] for cl in clips if cl['explicitResourceVariantLabels']==['basis']]
 group={'role':role,'active':active,'practice':pid,'practiceMember':p['source'],'practiceAttributes':dict(pn.attrib),'LEVEL1Modifiers':mods,'exactActiveGrantClosed':True,'activeAttributes':dict(a.attrib),'activeLEVEL1':[{'tag':n.tag,'attributes':dict(n.attrib)} for n in a1],'tcExplanationSha256':sha(text.encode('utf-8')),'tcShortExplanation':text[:150],'proposedSpellingRelation':reason,'resourceFamily':family,'clips':clips,'equivalentMotionGroups':list(byhash.values()),'entireFamilyEquivalent':len(byhash)==1,'uniqueBasisResourceMotion':basis[0] if len(basis)==1 else None,'basisAdmissionRequiresNonRepeat':all(cl['animationData'].get('Repeat')=='false' for cl in clips if cl['motion'] in basis),'officialActiveToMotionMapping':'UNRESOLVED','resourceRelationAuthority':'ROLE_SPECIFIC_HUMAN_REVIEWABLE_SPELLING_OR_WORD_FORM_HYPOTHESIS_AND_EXPLICIT_EFFECT_VARIANT_LABEL; not exact declared active alias','isolatedServerOwnedPolicyRequirements':['Root must explicitly accept this one named Practice-to-family spelling hypothesis; no generic fuzzy matcher or global typo normalization.','Only a uniquely explicit Basis clip with non-repeat may be proposed for an isolated lab; no minimum-ID rule, numeric family rank or ScriptLevel assumption.','Report candidate/official distinction in test UI and metadata. Target, hitbox, projectile, damage timing, multi-phase behavior remain separately unproven.','No Client modification or official native mapping completion claimed; this review applies no Server changes.'],'selectedMotion':None,'applied':False}
 semantics={3:{'support':'TC says a quick frontal attack with a high chance to knock enemies into the air; this is compatible with testing a role1 ELECSHOCK visual hypothesis.','notClosed':'TC description does not name ELECSHOCK or specify motion113; launch/knock-up, reach and effect application are not recovered by a non-repeat clip.'},14:{'support':'TC says Tanky punches nearby enemies repeatedly with a brief stun; HAMMERING is a plausible role-specific word-form comparison.','notClosed':'A single non-repeat animation does not prove number/times of hits, area, stun or command/payment behavior.'},18:{'support':'TC describes a punch knocking enemies down; ROCKET is a plausible spelling correction for the Practice filename roket.','notClosed':'TC explicitly requires V charge/emission state. Direct isolated playback cannot be called a complete normal skill or proof of its charge gate/consumption/projectile behavior.'},471:{'support':'TC describes rushing forward, knocking nearby enemies down and applying defensive/support effects; BREAKTHROUGH is a plausible spelling correction.','notClosed':'TC explicitly requires V charge stage1, dash/displacement, knock-down and buffs/debuffs; a motion116 preview does not implement or verify these gameplay rules.'}}
 group['descriptionComparison']=semantics[active]
 groups.append(group)
out={'schema':'TARTAROS_ROLE_SKILL_SPELLING_FAMILY_REVIEW_V1','groups':groups,'sourceMembers':list(sources.values()),'summary':{'groups':len(groups),'clips':sum(len(g['clips']) for g in groups),'uniqueExplicitBasisGroups':sum(g['uniqueBasisResourceMotion'] is not None for g in groups),'newOfficialMappings':0},'limitations':['Original and working member bytes compared; original assets readonly.','No execution/attachment/provider retry, MEF search, Client/Server/Host/shared modifications or Git commit.','Descriptions support a comparison hypothesis; they do not identify animation IDs.','Time values preserved raw so this independent review does not conflict with separate SpliteData timing audit.']}
p=D/'spelling-skill-family-review.json';p.write_text(json.dumps(out,ensure_ascii=False,indent=2)+'\n',encoding='utf-8');print(json.dumps({'file':str(p),'sha256':sha(p.read_bytes()),'summary':out['summary'],'groups':[(g['role'],g['active'],g['uniqueBasisResourceMotion'],[(c['motion'],c['animationData'].get('Repeat')) for c in g['clips']]) for g in groups]}))
