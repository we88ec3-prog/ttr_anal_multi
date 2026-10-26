"""Read-only source checks; never imports historical fixture scripts."""
import hashlib
import json
from pathlib import Path
import platform

ROOT = Path(__file__).resolve().parents[2]
OUT = Path(__file__).resolve().parent / 'evidence'
catalog = json.loads((ROOT / 'shared/catalog.json').read_text(encoding='utf-8'))
task = json.loads((ROOT / 'kr/tasks/T02/task.json').read_text(encoding='utf-8'))
artifacts = {a['id']: a for a in catalog['artifacts']}
records = []
for eid in task['evidence_ids']:
    a = artifacts[eid]
    p = ROOT / a['path']
    measured = hashlib.sha256(p.read_bytes()).hexdigest()
    records.append({'id': eid, 'path': a['path'], 'sha256': measured,
                    'expected': a['sha256'], 'ok': measured == a['sha256']})
result = {'status': '待整合', 'tool': 'Python ' + platform.python_version(),
          'purpose': 'T02 packaged source identity only; no semantic acceptance',
          'all_ok': all(r['ok'] for r in records), 'records': records}
(OUT / 'source-checks.json').write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
print(json.dumps({'all_ok': result['all_ok'], 'records': len(records)}))
