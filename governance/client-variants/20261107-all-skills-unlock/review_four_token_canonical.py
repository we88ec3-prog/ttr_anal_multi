"""Bounded original/work comparison; no family-number-to-skill mapping."""
from pathlib import Path
import collections, hashlib, json, re, sys, xml.etree.ElementTree as E

R = Path(sys.argv[1]) if len(sys.argv) > 1 else Path(r'E:/Tartaros/workspace')
D = R / 'runtime-observations/2026-11-05-all-skills'
sys.path.insert(0, str(R / 'anal'))
from stp_resources import Archive

raw = (D / 'four-numeric-token-candidates-v1.json').read_bytes()
assert hashlib.sha256(raw).hexdigest() == 'c12c18d2fa0cda37211bb7196019336a9b048c0f2543bfd5c6d92ff58379b432'
prior = json.loads(raw)
joins = json.loads((D / 'all-role-motion-joins.json').read_bytes())
arcs = {}

def read(root, carrier, member):
    key = (root, carrier)
    if key not in arcs:
        arcs[key] = Archive(root / carrier)
    return arcs[key].read(member)

def flatten(n, path='', out=None):
    if out is None:
        out = {}
    for k, v in n.attrib.items():
        if not (n.tag == 'AnimationHeader' and k in ['ID', 'NAME']):
            out[path + '/@' + k] = v
    if (n.text or '').strip():
        out[path + '/#text'] = n.text.strip()
    if (n.tail or '').strip():
        out[path + '/#tail'] = n.tail.strip()
    counts = collections.Counter()
    for child in n:
        i = counts[child.tag]
        counts[child.tag] += 1
        flatten(child, path + '/' + child.tag + '[' + str(i) + ']', out)
    return out

results = []
for group in prior['groups']:
    baseline = None
    clips = []
    for clip in group['clips']:
        md = next(m for role in joins['roles'] if role['role'] == group['role']
                  for m in role['motion_metadata'] if m['motion_id'] == clip['motion'])
        data = read(R.parent / 'origin', md['asd_carrier'], md['asd_member'])
        assert data == read(R, md['asd_carrier'], md['asd_member'])
        assert hashlib.sha256(data).hexdigest() == clip['asdSha256']
        node = E.fromstring('<ROOT>' + re.sub(r'<\?xml[^?]*\?>', '', data.decode('utf-8-sig')) + '</ROOT>')
        fields = flatten(node)
        if baseline is None:
            baseline = fields
        deltas = [{'path': k, 'baseline': baseline.get(k), 'thisClip': fields.get(k)}
                  for k in sorted(baseline.keys() | fields.keys()) if baseline.get(k) != fields.get(k)]
        for effect in clip['effects']:
            data = read(R.parent / 'origin', 'Effect/Effect.stp', effect['member'])
            assert data == read(R, 'Effect/Effect.stp', effect['member'])
            assert hashlib.sha256(data).hexdigest() == effect['sha256']
        clips.append({'motion': clip['motion'], 'asdSha256': clip['asdSha256'],
                      'canonicalDeltas': deltas,
                      'hasNamedComponent': any(e['hypothesisTokenMatches'] for e in clip['effects']),
                      'repeat': clip['animationData']['Repeat']})
    paths = sorted({d['path'] for c in clips for d in c['canonicalDeltas']})
    results.append({'role': group['role'], 'active': group['active'], 'practice': group['practice'],
                    'clips': clips, 'differencePaths': paths,
                    'onlyEffectOrSoundDeltas': all('/Effect[' in p or '/Sound[' in p for p in paths)})
output = {'schema': 'FOUR_TOKEN_ROOT_CANONICAL_REVIEW_V1', 'inputSha256': hashlib.sha256(raw).hexdigest(),
          'scope': '16 explicit ASD and their EFF hashes, original/work equality; excludes only Header ID/NAME',
          'groups': results, 'newOfficialMappings': 0}
target = D / 'four-token-root-canonical-review.json'
target.write_text(json.dumps(output, ensure_ascii=False, indent=2) + '\n', encoding='utf8')
print(hashlib.sha256(target.read_bytes()).hexdigest())
