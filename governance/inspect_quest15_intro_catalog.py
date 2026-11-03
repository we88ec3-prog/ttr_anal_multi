"""Read-only resource linkage for NPC10338 and Scene15/1 dialogue group3/22."""
import argparse
import hashlib
import json
import xml.etree.ElementTree as ET
from pathlib import Path
from inspect_tutorial_bounds_resource import members
from inspect_first_tutorial_cluster import decode

PINS = {
    'Table/npctable.xml': 'a727fceb64a8b58dc98983619fc73b131c15a6be1eec132c1124f2c57b4aa31d',
    'Table/ScenarioTalkTable.xml': 'f86baf72fd317d5d30e9aae931526a823b613db50545dc6074e3648eb984a1df',
    'Table/TalkTableSet.xml': '544aa2bfed37965a5a95deace0f084738d2f60a2c2ecfdded5030a575b17bcb1',
    'Table/TalkTable/02_Lenart.xml': '2ef48ba17f62a343e5152cf98485d39fa80502f2d50791c1e0ea667a5f348d03',
}


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--original-table', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    assert not a.output.exists() and a.output.suffix == '.json'
    carrier = '09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442'
    roots = {}
    for name, raw in members(a.original_table.read_bytes(), carrier, PINS).items():
        raw = decode(raw, max_expanded=3_000_000)
        assert hashlib.sha256(raw).hexdigest() == PINS[name]
        roots[name] = ET.fromstring(raw.decode('utf-8-sig'))
    npc = roots['Table/npctable.xml'].find("./NPC[@ID='10338']")
    assert npc is not None and npc.get('TYPE') == '10'
    group = roots['Table/ScenarioTalkTable.xml'].find("./Scenario[@id='3'][@scene='22']")
    assert group is not None
    rows = [e.attrib for e in group.findall('./TalkList/Talk')]
    assert rows == [{'char': '10338', 'talk': str(i)} for i in range(2314, 2320)]
    path = 'Table/TalkTable/02_Lenart.xml'
    assert any(e.get('PATH') == path for e in roots['Table/TalkTableSet.xml'])
    records = []
    for i in range(2314, 2320):
        e = roots[path].find(f"./Talk[@id='{i}']")
        assert e is not None
        records.append({'id': i, 'member': path, 'attributes': e.attrib,
                        'child_element_count': len(e), 'has_text': bool((e.text or '').strip())})
    result = {'classification': 'PINNED_RESOURCE_CROSS_REFERENCE_NOT_NATIVE_DISPATCH_CONTRACT',
              'carrier_sha256': carrier, 'members': PINS, 'npc': npc.attrib,
              'npc_talk_ids': [e.attrib for e in npc.findall('.//TALK')],
              'scenario_dialogue_group': group.attrib, 'dialogue_rows': rows, 'text_record_metadata': records,
              'limits': ['NPC table TYPE10 is not actor category or scene mode.',
                         'Scenario dialogue key3 is not proven TalkTableSet file index3.',
                         'Matching text records establish resource presence, not runtime helper lookup success.',
                         'No dialogue text, Client execution, mutation or quest completion published.']}
    with a.output.open('x', encoding='utf-8', newline='\n') as f:
        json.dump(result, f, ensure_ascii=False, indent=2)
        f.write('\n')
    print(json.dumps({'npc': 10338, 'npc_table_type': 10, 'dialogue_records': len(records), 'text_member': path}))


if __name__ == '__main__':
    main()
