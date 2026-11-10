"""Test-card integrity only; not native skill mapping or human acceptance."""
import argparse
import json
from pathlib import Path

parser = argparse.ArgumentParser()
parser.add_argument('--bindings', type=Path, required=True)
args = parser.parse_args()
root = Path(__file__).parent
queue = json.loads((root / 'pending-human-comparison-20261110.json').read_text(encoding='utf-8'))
bindings = json.loads(args.bindings.read_text(encoding='utf-8-sig'))
actions = json.loads((root / 'action-preview-catalogue-v2.json').read_text(encoding='utf-8-sig'))['entries']
seen = set()
for group in queue['readyGroups']:
    identity = (group['role'], group['active'])
    assert identity not in seen
    seen.add(identity)
    rows = [r for r in bindings if (r['Role'], r['Matrix'], r['Tier'], r['Mask']) ==
            (group['role'], group['matrix'], group['tier'], group['mask'])]
    assert len(rows) == 1
    row = rows[0]
    assert (row['Active'], row['Practice'], row['Name'].strip()) == (group['active'], group['practice'], group['name'].strip())
    assert row['Motions'] == group['motions'] and len(row['Motions']) > 1
    available = set(row['Motions']) | {a['motion'] for a in actions if a['role'] == group['role']}
    assert set(group['firstBatch']) <= available
    assert set(group['firstBatch']) <= set(row['Motions'])
    assert group['status'] in ('WAITING_USER_ENDPOINT_COMPARISON', 'QUEUED_NOT_DISPATCHED')
assert not seen.intersection((r['role'], r['active']) for r in queue['excluded'])
assert sum(len(g['firstBatch']) for g in queue['readyGroups'] if g['status'] == 'WAITING_USER_ENDPOINT_COMPARISON') == queue['expectedDispatchedCasts']
print(str(len(seen))+' remaining groups; '+str(queue['expectedDispatchedCasts'])+' dispatched endpoint casts; '+str(len(queue['completedVisualComparisons']))+' observed pairs excluded. Not full gameplay acceptance.')
