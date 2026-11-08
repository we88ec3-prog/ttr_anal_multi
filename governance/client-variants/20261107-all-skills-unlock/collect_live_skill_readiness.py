"""Read-only loopback HTTP catalogue snapshot. Never logs in or controls a Client."""
from pathlib import Path
import hashlib, json, urllib.request, collections

BASE = 'http://127.0.0.1:5082'
def read(path):
    raw = urllib.request.urlopen(BASE+path, timeout=15).read()
    return json.loads(raw), hashlib.sha256(raw).hexdigest()

profiles, skills_hash = read('/local-test/skills/catalog')
actions, actions_hash = read('/local-test/actions/catalog')
groups = {}
for profile in profiles:
    for key in profile['keys']:
        identity = (profile['role'], key['active'])
        row = groups.setdefault(identity, {'role': identity[0], 'active': identity[1],
            'name': key['name'], 'enabledInAnySlot': False, 'slots': []})
        row['enabledInAnySlot'] |= key['enabled']
        row['slots'].append({'matrix': profile['matrix'], 'tier': profile['tier'],
            'mask': key['mask'], 'practice': key['practice'], 'enabled': key['enabled'],
            'status': key['status']})
missing = []
for identity, row in sorted(groups.items()):
    if row['enabledInAnySlot']: continue
    row['videoReferences'] = [v for v in actions['videos']
                             if (v.get('role'), v.get('active')) == identity]
    missing.append(row)
roles = []
for role in sorted({p['role'] for p in profiles}):
    rows = [r for (rrole,_),r in groups.items() if rrole == role]
    roles.append({'role': role, 'matrixActives': len(rows),
                  'comparisonActives': sum(r['enabledInAnySlot'] for r in rows),
                  'missingMotionAssignments': sum(not r['enabledInAnySlot'] for r in rows),
                  'rawPreviewActions': sum(a['role'] == role for a in actions['actions'])})
out = {'schema': 'LIVE_SKILL_READINESS_NOT_NATIVE_COMPLETION_V1',
       'authority': 'HTTP_CATALOGUE_SNAPSHOT_NOT_RENDERED_SKILL_ACCEPTANCE',
       'skillsHttpSha256': skills_hash, 'actionsHttpSha256': actions_hash,
       'profiles': len(profiles), 'matrixActives': len(groups),
       'comparisonActives': sum(r['enabledInAnySlot'] for r in groups.values()),
       'readySlots': sum(k['enabled'] for p in profiles for k in p['keys']),
       'rawPreviewActions': len(actions['actions']), 'videoReferences': len(actions['videos']),
       'roles': roles, 'missingMotionAssignments': missing,
       'limitations': ['Enabled means an admitted comparison motion, not complete native gameplay.',
                      'Exact video title joins are references, not proof of a numeric motion ID.',
                      'Raw preview actions are not assigned to skills by role, number or order.',
                      'Actual native Client skill rendering and normal village entry remain pending.']}
dest = Path(__file__).with_name('live-skill-readiness-v78.json')
dest.write_text(json.dumps(out, ensure_ascii=False, indent=2)+'\n', encoding='utf8')
print(json.dumps({'profiles': len(profiles), 'actives': len(groups), 'missing': len(missing),
                  'missingWithVideo': sum(bool(r['videoReferences']) for r in missing),
                  'sha256': hashlib.sha256(dest.read_bytes()).hexdigest()}))
