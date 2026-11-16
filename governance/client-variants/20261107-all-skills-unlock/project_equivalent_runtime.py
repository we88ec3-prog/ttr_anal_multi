"""Admit only the two independently equivalent single-clip lab projections."""
from pathlib import Path
import json,hashlib,argparse
p=argparse.ArgumentParser();p.add_argument('bindings',type=Path);p.add_argument('output',type=Path);a=p.parse_args()
source=Path(__file__).with_name('runtime-unlock-candidates-v1.json')
raw=a.bindings.read_bytes();rows=json.loads(raw);evidence=json.loads(source.read_text(encoding='utf-8'))
admitted=[]
for candidate in evidence['candidateRows']:
 assert candidate['labPreviewCandidate'] and not candidate['nativeDispatchClosed'] and candidate['repeat'] is False
 assert len(candidate['motions'])==1 and candidate['followupNodes']==[]
 selected=[r for r in rows if (r['Role'],r['Practice'],r['Active'])==(candidate['role'],candidate['practice'],candidate['active'])]
 assert len(selected)==7
 assert {(r['Matrix'],r['Tier'],r['Mask']) for r in selected}=={(v['matrix'],v['tier'],v['mask']) for v in candidate['allMatrixSlots']}
 for r in selected:
  assert (r['Hp'],r['Sp'],r['Mp'],r['RawCooltime'])==(candidate['hp'],candidate['sp'],candidate['mp'],candidate['rawCooldown'])
  r.update(Motions=candidate['motions'],Durations=candidate['durationSeq'],Status=candidate['status'])
 admitted.append({'role':candidate['role'],'active':candidate['active'],'practice':candidate['practice'],'slots':len(selected),'equivalenceSha256':candidate['equivalenceSha256']})
result=(json.dumps(rows,ensure_ascii=False,indent=2)+'\n').encode('utf-8');a.output.write_bytes(result)
print(json.dumps({'inputSha256':hashlib.sha256(raw).hexdigest(),'evidenceSha256':hashlib.sha256(source.read_bytes()).hexdigest(),'outputSha256':hashlib.sha256(result).hexdigest(),'admitted':admitted}))
