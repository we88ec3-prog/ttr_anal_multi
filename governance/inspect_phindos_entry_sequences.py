"""Selected pinned local Event scripts; metadata only, never execute Lua."""
import argparse
import hashlib
import json
import re
import xml.etree.ElementTree as ET
from pathlib import Path
from inspect_tutorial_bounds_resource import members
from inspect_first_tutorial_cluster import decode

CARRIER = '2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b'
PINS = {
    'Event/SceneList.xml': '8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25',
    'Event/Sequences/Square_Tutorial01.seq': 'f5ef433ed019fa3e018b1643705400c4428a07504881bb1bc5d78ee177dfea1b',
    'Event/Sequences/scenario_tuto1_1.seq': 'a4a308265b97fa9e048ebf4a30abb40f5fe8a7a3dc934ab911dd47fc3a7341f8',
    'Event/Sequences/pindos_talkevent.seq': '347b3a4cbd41e3e4d74f3c39a4adf8fb814d8bc361890858e0f87c8576f051b7',
    'Event/Sequences/scenario_tuto2_1.seq': '42b6205dd8b526db96f2339607a6235efdf360a08f30e0e4d1747ab7f8452bf8',
}


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--event', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    assert not a.output.exists() and a.output.suffix == '.json'
    data = {}
    for name, raw in members(a.event.read_bytes(), CARRIER, PINS).items():
        raw = decode(raw, max_expanded=3_000_000)
        assert hashlib.sha256(raw).hexdigest() == PINS[name]
        data[name] = raw.decode('utf-8-sig')
    rows = [e.attrib for e in ET.fromstring(data['Event/SceneList.xml']) if e.get('questIdx') == '15']
    assert [r['sceneIdx'] for r in rows] == ['1', '2', '3', '4']
    scripts = []
    for row in rows:
        path = 'Event/Sequences/' + row['funcName'] + '.seq'
        text = data[path]
        calls = [{'function': m[1], 'arguments': m[2]} for line in text.splitlines()
                 if (m := re.fullmatch(r'\s*([\w.]+)\((.*)\)\s*', line))]
        assert calls[-1]['function'] == 'Register'
        assert any(c['function'] == 'RestoreMap' for c in calls)
        scripts.append({'scene': row, 'member': path, 'calls': calls})
    result = {'classification': 'LOCAL_PINNED_EVENT_SCRIPT_FACTS_NOT_ORIGINAL_RESOURCE_CERTIFICATION',
              'carrier_sha256': CARRIER, 'member_sha256': PINS, 'scripts': scripts,
              'limits': ['Local Event archive may contain earlier translations; its hash is pinned, not certified pristine.',
                         'Calls and literal arguments only; helper semantics and network scheduling not fully traced.',
                         'No explicit spawn/battle call in these four bodies does not prove no required battle elsewhere.',
                         'Cutscene objects and RestoreMap do not establish normal town spawn or readiness.',
                         'No scripts executed, no Client/resource mutation or original MEF inferred.']}
    with a.output.open('x', encoding='utf-8', newline='\n') as f:
        json.dump(result, f, ensure_ascii=False, indent=2)
        f.write('\n')
    print(json.dumps({'scenes': len(scripts), 'functions': [r['scene']['funcName'] for r in scripts]}))


if __name__ == '__main__':
    main()
