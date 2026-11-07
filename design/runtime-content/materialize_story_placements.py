"""Materialize existing Server candidate placements; does not read native MEF."""
from pathlib import Path
import argparse,hashlib,json,math
ap=argparse.ArgumentParser()
ap.add_argument('--input',type=Path,required=True)
ap.add_argument('--expected-sha256',required=True)
ap.add_argument('--output',type=Path,required=True)
a=ap.parse_args();raw=a.input.read_bytes();old_hash=hashlib.sha256(raw).hexdigest()
if old_hash.lower()!=a.expected_sha256.lower():raise ValueError('Input identity mismatch')
c=json.loads(raw)
if c['schema']!='LOCAL_STORY_NAVIGATION_CANDIDATE_V1_NOT_MEF':raise ValueError('Unsupported Server content schema')
maps={m['map']:m for m in c['maps']};count=0
for q in c['quests']:
 for i,n in enumerate((q.get('scenario') or {}).get('nodes',[])):
  m=maps[n['map']]
  if n.get('encounterSpawns') is None:
   n['encounterSpawns']=[dict(model=model,x=m['spawnX']+6+(j%4)*2,y=m['spawnY']-6+(j//4)*2) for j,model in enumerate(n['encounterModels'])]
  if n.get('portal') is None:n['portal']=dict(x=m['portalX'],y=m['portalY'],radius=6,key=i+1)
  if [e['model'] for e in n['encounterSpawns']]!=n['encounterModels']:raise ValueError('Model lineage mismatch')
  if not all(math.isfinite(e[k]) for e in n['encounterSpawns'] for k in ['x','y']):raise ValueError('Non-finite placement')
  count+=1
previous=c.setdefault('previousVersions',[])
if not any(v['contentSha256']==old_hash for v in previous):previous.append(dict(contentSha256=old_hash,questIds=[q['quest'] for q in c['quests']]))
c['version']+='-explicit-placements-v1'
out=(json.dumps(c,ensure_ascii=False,indent=2)+'\n').encode('utf-8')
with a.output.open('xb') as f:f.write(out)
print(json.dumps(dict(authority='SERVER_RECONSTRUCTION_NOT_NATIVE_MEF',inputSha256=old_hash,outputSha256=hashlib.sha256(out).hexdigest(),materializedNodes=count,boundsValidation='REQUIRES_SERVER_LOADER_NOT_PERFORMED_BY_THIS_CONVERTER')))
