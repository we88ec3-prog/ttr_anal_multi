"""Bounded source review: eight existing skill/Buff names, not a tick formula."""
from pathlib import Path
import argparse, hashlib, json, sys, xml.etree.ElementTree as E

p = argparse.ArgumentParser()
p.add_argument('workspace', type=Path)
p.add_argument('output', type=Path)
a = p.parse_args()
sys.path.insert(0, str(a.workspace / 'anal'))
from stp_resources import Archive

sha = lambda b: hashlib.sha256(b).hexdigest()
members = ['Table/SkillActiveTable.xml', 'Table/skillexplaintable.xml',
           'Table/BuffExplainTable.xml', 'Table/_BuffList.xml']
roots = [('kr', a.workspace), ('originalKr', a.workspace.parent / 'origin'),
         ('tc', a.workspace.parent / 'tc_workspace')]
archives = {label: Archive(root / 'Table.stp') for label, root in roots}
tables, sources = {}, []
for label, root in roots:
    tables[label] = {}
    for member in members:
        data = archives[label].read(member)
        if label == 'originalKr':
            assert data == archives['kr'].read(member)
        sources.append({'version': label, 'member': member, 'sha256': sha(data)})
        tables[label][member] = E.fromstring(data.decode('utf-8-sig'))

# Explicit review set, not a claim to cover every recovery skill.
config = [(5, 41, 73, 9, ['HP','SP','MP']), (6, 52, 84, 11, ['HP']),
          (6, 54, 87, 10, ['HP']), (7, 335, 99, 35, ['MP']),
          (8, 965, 123, 77, ['SP','MP']), (9, 1404, 132, 85, ['SP']),
          (4, 475, 59, 53, ['SP']), (6, 482, 92, 58, ['SP','MP'])]
rows = []
projection_path = Path(__file__).parent / 'source-effect-coefficients.json'
projection = json.loads(projection_path.read_text(encoding='utf8'))
for role, active_id, practice, buff_id, resources in config:
    versions = []
    for label in ['kr','tc']:
        t = tables[label]
        active = next(n for n in t[members[0]] if n.get('no') == str(active_id))
        explain = next(n for n in t[members[1]] if n.get('no') == str(active_id))
        buffs = [n for n in t[members[2]] if n.get('name') == active.get('name')]
        exact_name = len(buffs) == 1 and buffs[0].get('no') == str(buff_id)
        # TC475 has a different Active/Buff spelling. Compare the KR-candidate
        # numeric ID explicitly; do not silently manufacture an exact-name join.
        assert exact_name or (label == 'tc' and active_id == 475 and not buffs)
        buff = next(n for n in t[members[2]] if n.get('no') == str(buff_id))
        entry = next(n for n in t[members[3]] if n.get('ID') == str(buff_id))
        versions.append({'version': label, 'exactActiveBuffNameMatch': exact_name,
            'buffComparisonBasis': 'EXACT_NAME' if exact_name else 'KR_CANDIDATE_NUMERIC_ID_ONLY_TC_NAME_MISMATCH',
            'activeIdentity': dict(active.attrib),
            'fullActiveText': ''.join(explain.find('EXPLAIN').itertext()),
            'activeLevels': [{'level': int(n.get('val')), 'declarations':
                [{'tag': c.tag, 'attributes': dict(c.attrib)} for c in n]}
                for n in active.findall('LEVEL')],
            'buffIdentity': dict(buff.attrib), 'buffListEntry': dict(entry.attrib),
            'buffLevels': [{'level': int(n.get('val')), 'rawTime': n.get('time'),
                'fullText': ''.join(n.itertext())} for n in buff.findall('LEVEL')]})
    # Practice links are verified against the existing exact resource projection.
    levels = [n for n in projection['rows'] if n['role'] == role and n['active'] == active_id]
    assert levels and all(n['practice'] == practice for n in levels)
    for level in levels:
        declarations = next(n['declarations'] for n in versions[0]['activeLevels'] if n['level'] == level['activeLevel'])
        effects = [{'kind': n['tag'], 'ratio': int(n['attributes']['ratio']),
            'revision': int(n['attributes']['rev'])} for n in declarations if n['tag'] in ['ATTACK','HEAL']]
        assert effects == level['effects'] and {n['kind'] for n in effects} == {'ATTACK'}
    rows.append({'role': role, 'active': active_id, 'practice': practice,
        'sameNameBuffCandidate': buff_id, 'reviewedRecoveryResources': resources,
        'versions': versions, 'sourceLearnedLevels': levels,
        'numericRecoveryStatPresent': active_id in [475,482],
        'nativeGrantEstablished': False, 'nativeTickAmountEstablished': False,
        'nativeTickIntervalEstablished': False})

out = {'schema': 'PERIODIC_RESOURCE_BUFF_TEXT_BOUNDARY_V1',
    'authority': 'BOUNDED_TABLE_TEXT_AND_EXISTING_LEVEL_JOINS_NOT_NATIVE_GRANT_OR_REGEN_FORMULA',
    'rows': rows, 'sourceMembers': sources,
    'effectProjectionSha256': sha(projection_path.read_bytes()),
    'limits': ['Only these eight skills; no exhaustive recovery-skill claim.',
        'Same Active/Buff names do not prove grant, target selection, level conversion or publication.',
        'All eight source Active rows declare ATTACK; lack of HEAL does not negate the described recovery Buff.',
        'Recovery stat increase is not independently a flat per-tick amount.',
        'User temporary global resource regeneration is separate from skill-induced recovery.',
        'No native provider, game execution, raw member export, Client or Host modification.']}
a.output.write_bytes((json.dumps(out, ensure_ascii=False, indent=2) + '\n').encode('utf8'))
print(json.dumps({'rows': len(rows), 'sha256': sha(a.output.read_bytes())}))
