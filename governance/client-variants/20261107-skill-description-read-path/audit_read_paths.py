"""Static translation-only proposal; no EXE or companion output creation."""
from pathlib import Path
import sys,json,hashlib,re,struct,xml.etree.ElementTree as E
R=Path(r'E:\Tartaros\workspace');D=Path(__file__).parent
sys.path.insert(0,str(R/'anal'));from build_native_index import PE
from stp_resources import Archive
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
sha=lambda b:hashlib.sha256(b).hexdigest()
files={'originalBin':R/'Tartaros.bin','v6':R/'Tartaros.ip-zh-tw-v6.exe'};pes={k:PE(p) for k,p in files.items()}
specs=[{'old':'Table/SkillExplainTable.xml','new':'TC_UI/SkillExplainText7.xml','member':'Table/skillexplaintable.xml','offset':0x80d5ec,'consumer':0x52fc50,'literalInstruction':0x52fc88,'rangeBytes':448}, {'old':'Table/PracticeExplainTable.xml','new':'TC_UI/PracticeDescription7.xml','member':'Table/PracticeExplainTable.xml','offset':0x80d3ec,'consumer':0x529d50,'literalInstruction':0x529d88,'rangeBytes':448}]
manifest=[];md=Cs(CS_ARCH_X86,CS_MODE_32)
for s in specs:
 assert len(s['old'])==len(s['new'])
 evidence=[]
 for name,p in pes.items():
  old=s['old'].encode();off=s['offset'];assert p.data[off:off+len(old)+1]==old+b'\0' and p.data.count(old+b'\0')==1
  va=p.va(off);inst=p.read(s['literalInstruction'],5);assert inst==b'\xb9'+struct.pack('<I',va)
  data=p.read(s['consumer'],s['rangeBytes']);evidence.append({'file':str(files[name].relative_to(R)),'fileSha256':sha(p.data),'fileOffset':hex(off),'literalVA':hex(va),'literalLength':len(old),'consumerStart':hex(s['consumer']),'literalInstruction':hex(s['literalInstruction']),'consumerRangeSha256':sha(data),'rangeBytes':len(data)})
  (D/(hex(s['consumer'])[2:]+'-'+name+'.txt')).write_bytes(('\n'.join(f'{i.address:x} {i.mnemonic} {i.op_str}' for i in md.disasm(data,s['consumer']))+'\n').encode())
 assert evidence[0]['consumerRangeSha256']==evidence[1]['consumerRangeSha256']
 manifest.append({**s,'offset':hex(s['offset']),'consumer':hex(s['consumer']),'literalInstruction':hex(s['literalInstruction']),'equalLength':True,'evidence':evidence})
sources={'approvedV5':R/'TC_UI/Table.story-zh-tw-v5.stp','originalKR':R.parent/'origin/Table.stp','originalTC':Path(r'E:\Tartaros\tc_workspace\Table.stp')};arcs={k:Archive(p) for k,p in sources.items()};payloads=[];trees={}
for s in specs:
 members=[]
 for name,a in arcs.items():
  member=next(n for n in a.files if n.casefold()==s['member'].casefold());b=a.read(member);root=E.fromstring(b);trees[(name,s['member'])]=root
  texts=[' '.join(n.itertext())+' '+str(n.attrib) for n in root]
  members.append({'source':name,'sourceArchive':str(sources[name]),'archiveSha256':sha(sources[name].read_bytes()),'member':member,'decodedBytes':len(b),'decodedSha256':sha(b),'root':root.tag,'rows':len(root),'rowsContainingHangul':sum(bool(re.search('[\uac00-\ud7af]',t)) for t in texts)})
 payloads.append({'proposedCompanion':s['new'],'copyRule':'Exact decoded approvedV5 member; no newly composed gameplay description.','sources':members})
c=json.loads((R/'runtime-observations/2026-11-05-all-skills/all-skills-catalog.json').read_text(encoding='utf-8-sig'));special=[]
for ch in c['characters']:
 entries=[e for e in ch['matrix_entries'] if e['matrix']==0 and e['column'] in [7,8,10]];ids=sorted({e['active_skill'] for e in entries})
 for active in ids:
  values=[]
  for src in ['approvedV5','originalTC','originalKR']:
   root=trees[(src,'Table/skillexplaintable.xml')];n=next((n for n in root if n.get('no')==str(active)),None);text=' '.join(' '.join(n.itertext()).split()) if n is not None else None
   values.append({'source':src,'present':n is not None,'textExcerpt':text[:220] if text else text,'textSha256':sha(text.encode()) if text else None})
  special.append({'role':ch['role'],'active':active,'matrix0Slots':[{'tier':e['tier'],'column':e['column']} for e in entries if e['active_skill']==active],'descriptions':values})
result={'schema':'tartaros-skill-description-direct-path-v7-proposal-v1','proposalOnly':True,'patches':manifest,'companionSources':payloads,'specialColumns7_8_10':special,'unchangedOnScreenKeyTable':'Original KR, original TC and approvedV5 have identical decoded OnScreenKeyTable hash4c214534202b1a3e3dc6a1209df263c2cf74e28ee12b8bc8ba5c30c2652d7f33; not the translated skill description source.','limitations':['Direct literal readers are statically proven, but observed cache/precedence cause remains a hypothesis until human runtime check.','Column7/8/10 declarations identify active IDs; physical Tab/V key dispatch is not newly proven by this audit.','Any fallback Hangul rows remain declared, not claimed translated.','No original/existing executable, companion or archive was modified; no target execution/attach or provider retry.']}
residual=[]
for spec in specs:
 member=spec['member'];key='ID' if 'Practice' in member else 'no';tr=trees[('originalTC',member)];ti={n.get(key):n for n in tr}
 for n in trees[('approvedV5',member)]:
  if not re.search('[\uac00-\ud7af]',' '.join(n.itertext())+str(n.attrib)):continue
  t=ti.get(n.get(key));residual.append({'member':member,'id':n.get(key),'v5NodeSha256':sha(E.tostring(n,encoding='utf-8')),'tcNodeSha256':sha(E.tostring(t,encoding='utf-8')) if t is not None else None,'v5Attributes':dict(n.attrib),'tcAttributes':dict(t.attrib) if t is not None else None,'v5Children':[{'tag':ch.tag,'attributes':dict(ch.attrib)} for ch in n],'tcChildren':[{'tag':ch.tag,'attributes':dict(ch.attrib),'textExcerpt':' '.join(' '.join(ch.itertext()).split())[:180]} for ch in t] if t is not None else []})
(D/'residual-tc-matches.json').write_bytes((json.dumps(residual,ensure_ascii=False,indent=2)+'\n').encode())
(D/'proposal.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode());print(json.dumps({'patches':[(s['old'],s['new']) for s in specs],'companionHashes':[(p['proposedCompanion'],p['sources'][0]['decodedSha256']) for p in payloads],'specialRows':len(special)}))
