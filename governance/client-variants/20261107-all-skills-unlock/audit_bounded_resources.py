"""Finite nine-role index and four ambiguous clip-family audit, read-only."""
from pathlib import Path
import json,hashlib,sys,struct,re,collections
R=Path(r'E:\Tartaros\workspace');O=R.parent/'origin';D=Path(__file__).parent;B=R/'runtime-observations/2026-11-05-all-skills'
sha=lambda b:hashlib.sha256(b).hexdigest();j=json.loads((B/'all-role-motion-joins.json').read_text(encoding='utf-8-sig'));c=json.loads((B/'all-skills-catalog.json').read_text(encoding='utf-8-sig'));runtime=json.loads((R/'CLIENT/evidence/20261107-all-matrices/runtime-matrix-rows.json').read_text())
def index(path):
 with path.open('rb') as f:
  header=f.read(16);assert header[:4]==b'STPD';at=int.from_bytes(bytes(v^255 for v in header[4:8]),'little');f.seek(at);raw=f.read()
 assert raw[:4]==b'STPI';data=bytes(v^255 for v in raw);pos=8;names=[]
 def walk(parent):
  nonlocal pos
  n=struct.unpack_from('<H',data,pos)[0];pos+=2;name=data[pos:pos+n].decode('ascii').rstrip('\0');pos+=n;kind=data[pos];pos+=1;path='/'.join(filter(None,[parent,name]))
  if kind in [1,2]:
   count=struct.unpack_from('<I',data,pos)[0];pos+=12
   for _ in range(count):walk(path)
  else:assert kind==0;pos+=16;names.append(path)
 walk('');assert pos==len(data);return names,sha(raw)
indices=[]
for role in j['roles']:
 carriers=sorted({m['asd_carrier'] for m in role['motion_metadata']});known={m['asd_member'].casefold() for m in role['motion_metadata']}
 for carrier in carriers:
  on,oh=index(O/carrier);wn,wh=index(R/carrier);assert on==wn and oh==wh
  asds=[n for n in on if n.casefold().endswith('.asd')];unlisted=[n for n in asds if n.casefold() not in known]
  indices.append({'role':role['role'],'carrier':carrier,'originalIndexSha256':oh,'workingIndexSha256':wh,'equal':True,'members':len(on),'asdMembers':len(asds),'knownMotionAsds':len(known),'asdNotInExistingMotionMetadata':unlisted})
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
arcs={};clips=[]
for role,ids in [(1,[110,111,112,146,147,148]),(2,[112,113,114,184,145,146,147])]:
 rr=next(r for r in j['roles'] if r['role']==role)
 for ident in ids:
  m=next(m for m in rr['motion_metadata'] if m['motion_id']==ident);carrier=m['asd_carrier']
  if carrier not in arcs:arcs[carrier]=(Archive(O/carrier),Archive(R/carrier))
  a,w=arcs[carrier];raw,wr=a.read(m['asd_member']),w.read(m['asd_member']);assert raw==wr and sha(raw)==m['asd_sha256']
  text=raw.decode('euc-kr');tags=collections.Counter(re.findall(r'<\s*([A-Za-z_][\w:-]*)',text));attrs=collections.Counter(re.findall(r'([A-Za-z_][\w:-]*)\s*=',text));interesting=[]
  for line in text.splitlines():
   if re.search(r'(repeat|loop|transition|next|cancel|frame|delay|effect|header)',line,re.I):interesting.append(line.strip())
  clips.append({'role':role,'motion':ident,'member':m['asd_member'],'originalSha256':sha(raw),'workingSha256':sha(wr),'tags':dict(tags),'attributeNames':dict(attrs),'relevantStructuralLines':interesting,'nominalDuration':m['duration_seconds_candidate_sum_end_plus_delay_over_fps'],'effects':m['effects'],'authority':'RESOURCE_CLIP_STRUCTURE_ONLY_NO_PHASE_TRANSITION_OR_PAYMENT_POLICY'})
blocked=[];seen=set()
for r in runtime['rows']:
 key=(r['role'],r['active'])
 if not r['blocked'] or key in seen:continue
 seen.add(key);blocked.append(r)
result={'schema':'ALL_SKILLS_UNLOCK_BOUNDED_RESOURCE_AUDIT_V1','inputMotionJoinsSha256':sha((B/'all-role-motion-joins.json').read_bytes()),'inputRuntimeRowsSha256':sha((R/'CLIENT/evidence/20261107-all-matrices/runtime-matrix-rows.json').read_bytes()),'roleIndices':indices,'ambiguousClipStructures':clips,'blockedDistinctRows':blocked,'limitations':['No filename-nearness aliases or active=motion numeric assumption.','Unlisted ASD names alone are not callable skill bindings.','ASD repeat flag does not prove phase ordering, input-held policy, target, impact or once-only payment.','Original/working read-only; no Client/Server edits, target execution/attach, provider retry or MEF search.']}
D.mkdir(parents=True,exist_ok=True);(D/'bounded-resource-audit.json').write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode());print(json.dumps({'roleIndices':len(indices),'unlistedAsds':sum(len(r['asdNotInExistingMotionMetadata']) for r in indices),'clipStructures':len(clips),'blockedDistinct':len(blocked)}))
