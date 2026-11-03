"""Pinned Town1/Chapter1 inventory for parallel Web analysis, not story acceptance."""
import argparse
import hashlib
import json
import re
import xml.etree.ElementTree as ET
from pathlib import Path
from inspect_tutorial_bounds_resource import members
from inspect_first_tutorial_cluster import decode


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--original-table', type=Path, required=True)
    p.add_argument('--event', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    assert not a.output.exists() and a.output.suffix == '.json'
    table_sha = '09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442'
    pins = {'Table/QuestInfo.xml': '5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60',
            'Table/SceneList.xml': '1b702eacdf536437605e846825e6a2384b6f2623d1b43a9010cafce5388cd037'}
    trees = {}
    for name, raw in members(a.original_table.read_bytes(), table_sha, pins).items():
        raw = decode(raw, max_expanded=3_000_000)
        assert hashlib.sha256(raw).hexdigest() == pins[name]
        trees[name] = ET.fromstring(raw.decode('utf-8-sig'))
    quests = list(trees['Table/QuestInfo.xml'])
    town_quests = [q for q in quests if q.get('town') == '1']
    chapter = trees['Table/SceneList.xml'].find("./CHAPTER[@chapterIdx='1']")
    assert chapter is not None and chapter.get('townId') == '1'
    chapter_ids = {q.get('questId') for q in chapter}
    selected = [q for q in quests if q in town_quests or q.get('id') in chapter_ids]
    def quest_row(q):
        return {'attributes': {k: v for k, v in q.attrib.items() if k != 'subject'},
                'elements': [{'tag': e.tag, 'attributes': e.attrib,
                              'children': [{'tag': c.tag, 'attributes': c.attrib} for c in e]} for e in q]}
    event_sha = '2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b'
    name = 'Event/SceneList.xml'
    raw = decode(members(a.event.read_bytes(), event_sha, [name])[name], max_expanded=3_000_000)
    assert hashlib.sha256(raw).hexdigest() == '8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25'
    scene_index = {(e.get('questIdx'), e.get('sceneIdx')): e.attrib for e in ET.fromstring(raw.decode('utf-8-sig'))}
    scenes = [scene_index[(q.get('questId'), e.get('sceneIdx'))] for q in chapter for e in q]
    assert len(town_quests) == 77 and len(chapter) == 9 and len(scenes) == 28
    sequence_paths = ['Event/Sequences/' + row['funcName'] + '.seq' for row in scenes]
    sequence_data = members(a.event.read_bytes(), event_sha, sequence_paths)
    sequences = []
    for scene, path in zip(scenes, sequence_paths):
        body = decode(sequence_data[path], max_expanded=3_000_000)
        try:
            text = body.decode('utf-8-sig'); encoding = 'utf-8-sig'
        except UnicodeDecodeError:
            text = body.decode('euc-kr'); encoding = 'euc-kr'
        calls, other = [], []
        for line in text.splitlines():
            if not line.strip() or line.lstrip().startswith(('--', 'function ')) or line.strip() == 'end':
                continue
            match = re.fullmatch(r'\s*([\w.]+)\((.*)\)\s*', line)
            if match: calls.append({'function': match[1], 'arguments': match[2]})
            else: other.append(line.strip())
        sequences.append({'scene': scene, 'member': path, 'sha256': hashlib.sha256(body).hexdigest(),
                          'decoded_as': encoding, 'calls': calls, 'unparsed_line_count': len(other),
                          'limitation': 'Literal call inventory, not helper semantics or verified runtime control flow.'})
    owned_ids = {q.get('id') for q in town_quests}
    cross = [quest_row(q) for q in quests if q.get('town') != '1' and
             any(e.get('id') in owned_ids for e in q.findall('./Demands/Demand'))]
    result = {'classification': 'STATIC_SCOPE_INVENTORY_NOT_ALL_STORY_BOUNDARIES_VERIFIED',
              'table_carrier_sha256': table_sha, 'table_members': pins,
              'event_carrier_sha256': event_sha, 'event_scene_member_sha256': hashlib.sha256(raw).hexdigest(),
              'counts': {'town1_quests': 77, 'chapter1_scenarios': 9, 'chapter1_scenes': 28},
              'chapter1_scene_rows': scenes, 'quest_rows': [quest_row(q) for q in selected],
              'chapter1_sequence_metadata': sequences,
              'cross_town_demand_candidates': cross,
              'limits': ['Town1 membership is not proof every row is a required story quest.',
                         'Chapter1 membership alone is not a full village-content or exit boundary.',
                         'Local Event archive may contain historical translations; not certified pristine.',
                         'Raw reward types, objectives and scene IDs still require consumer/policy verification.',
                         'No resource mutation, Client execution or Server change by this inspector.']}
    with a.output.open('x', encoding='utf-8', newline='\n') as f:
        json.dump(result, f, ensure_ascii=False, indent=2)
        f.write('\n')
    print(json.dumps(result['counts']))


if __name__ == '__main__':
    main()
