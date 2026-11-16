"""Four explicit component hypotheses, not native dispatch or phase selection."""
from pathlib import Path
import argparse, hashlib, json

p = argparse.ArgumentParser()
p.add_argument('bindings', type=Path)
p.add_argument('output', type=Path)
a = p.parse_args()
assert a.bindings.resolve() != a.output.resolve()
root = Path(__file__).parent
raw = (root / 'four-numeric-token-candidates-v1.json').read_bytes()
assert hashlib.sha256(raw).hexdigest() == 'c12c18d2fa0cda37211bb7196019336a9b048c0f2543bfd5c6d92ff58379b432'
review = (root / 'four-token-root-canonical-review.json').read_bytes()
assert hashlib.sha256(review).hexdigest() == '401daecd39aa886c6a4bfbab86bb5a2b575d51dc277c8311f8ea6a9bf70a47a4'
groups = json.loads(raw)['groups']
checked = json.loads(review)['groups']
matrix_raw = (root / 'four-token-matrix-text-semantics-review-v1.json').read_bytes()
assert hashlib.sha256(matrix_raw).hexdigest() == '1962dd761cdf05ff5b7c711213f6eb1b7f23226a1d7f8c99f8673cab6039ccfd'
matrix_rows = json.loads(matrix_raw)['rows']
rows = json.loads(a.bindings.read_bytes())
for role, active, practice, matrix, tier, mask, motions in [
    (4, 3018, 239, 6, 2, 4, [210, 211, 212, 213]),
    (8, 3041, 262, 6, 2, 1, [201]),
    (9, 3047, 268, 5, 0, 2, [216, 217, 218, 219]),
    (2, 2997, 218, 4, 0, 5, [188, 189, 190, 191]),
]:
    g = next(g for g in groups if (g['role'], g['active'], g['practice']) == (role, active, practice))
    c = next(c for c in checked if (c['role'], c['active']) == (role, active))
    exact = next(c for c in matrix_rows if (c['role'], c['active'], c['practice']) == (role, active, practice))
    assert len(exact['exactKrMatrixSlots']) == 1
    slot = exact['exactKrMatrixSlots'][0]
    identity = slot['resourceIdentity']
    assert (identity['CharID'], identity['MatrixID'], identity['tier'], identity['skill']) == (role, matrix, tier, active)
    assert slot['existingCatalogInputProjection']['mask'] == mask
    assert len(motions) == 1 or c['onlyEffectOrSoundDeltas']
    durations = []
    for motion in motions:
        clip = next(clip for clip in g['clips'] if clip['motion'] == motion)
        assert clip['animationData']['Repeat'] == 'false'
        assert any(effect['hypothesisTokenMatches'] for effect in clip['effects'])
        duration = sum((float(s['EndFrame']) + float(s['Delay'])) / float(s['FPS']) for s in clip['rawSplitRows'])
        assert duration > 0
        durations.append(duration)  # Existing unverified resource estimate, not native cancel timing.
    selected = [r for r in rows if (r['Role'], r['Practice'], r['Active']) == (role, practice, active)]
    assert len(selected) == 1
    row = selected[0]
    assert (row['Matrix'], row['Tier'], row['Mask']) == (matrix, tier, mask)
    row.update(Motions=motions, Durations=durations,
               Status='SERVER_OWNED_COMPONENT_ANCHOR_VISUAL_COMPARISON_CANDIDATE')
data = (json.dumps(rows, ensure_ascii=False, indent=2) + '\n').encode()
a.output.write_bytes(data)
print(json.dumps({'outputSha256': hashlib.sha256(data).hexdigest(),
                  'authority': 'FOUR_EXPLICIT_LAB_COMPONENT_HYPOTHESES_NOT_NATIVE_MAPPING'}))
