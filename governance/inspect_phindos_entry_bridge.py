"""Read-only original Quest15 entry metadata; no inferred quest/network success."""
import argparse
import hashlib
import json
import xml.etree.ElementTree as ET
from pathlib import Path
from inspect_tutorial_bounds_resource import members
from inspect_first_tutorial_cluster import decode

PINS = {
    'Table/QuestInfo.xml': '5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60',
    'Table/QuestTalk.xml': 'b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28',
    'Table/SceneList.xml': '1b702eacdf536437605e846825e6a2384b6f2623d1b43a9010cafce5388cd037',
}
CARRIER = '09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442'


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--original-table', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    assert a.output.suffix == '.json' and not a.output.exists()
    trees = {}
    for name, raw in members(a.original_table.read_bytes(), CARRIER, PINS).items():
        data = decode(raw, max_expanded=3_000_000)
        assert hashlib.sha256(data).hexdigest() == PINS[name]
        trees[name] = ET.fromstring(data.decode('utf-8-sig'))
    q = trees['Table/QuestInfo.xml'].find("./Quest[@id='15']")
    assert q is not None
    scenes = []
    for chapter in trees['Table/SceneList.xml']:
        for scenario in chapter:
            if scenario.get('questId') == '15':
                scenes.append({'chapter': {k: v for k, v in chapter.attrib.items() if k != 'chapterName'},
                               'quest_id': '15', 'scenes': [e.attrib for e in scenario]})
    assert scenes == [{'chapter': {'chapterIdx': '1', 'townId': '1'}, 'quest_id': '15',
                       'scenes': [{'sceneIdx': str(i)} for i in range(1, 5)]}]
    talks = [e.attrib for e in trees['Table/QuestTalk.xml'].iter() if e.get('id') == '15']
    assert not talks
    result = {'classification': 'PINNED_RESOURCE_METADATA_NOT_RUNTIME_OR_OFFICIAL_SERVER_SEQUENCE',
              'carrier_sha256': CARRIER, 'members': PINS,
              'quest': {k: v for k, v in q.attrib.items() if k != 'subject'},
              'demands': [e.attrib for e in q.findall('./Demands/Demand')],
              'scene_membership': scenes, 'quest_talk_rows': talks,
              'limits': ['Resource scene membership is not proven wire order or completion conditions.',
                         'No QuestTalk id15 row does not prove no NPC interaction.',
                         'Chapter town1 is distinct from QuestInfo town5 and physical map182.',
                         'No Client execution, resource change, quest completion or transfer performed.']}
    with a.output.open('x', encoding='utf-8', newline='\n') as f:
        json.dump(result, f, ensure_ascii=False, indent=2)
        f.write('\n')
    print(json.dumps({'quest': '15', 'chapter': '1', 'scene_ids': [1, 2, 3, 4], 'quest_talk_rows': len(talks)}))


if __name__ == '__main__':
    main()
