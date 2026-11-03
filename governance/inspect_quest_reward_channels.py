"""Read-only Quest RewardsEtc storage and selected UI label linkage; no reward grant."""
import argparse
import hashlib
import json
import struct
import sys
import xml.etree.ElementTree as ET
from pathlib import Path
from verify_working_copy_login_ranges import mapped, ORIGINAL
from inspect_tutorial_bounds_resource import members
from inspect_first_tutorial_cluster import decode

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary', type=Path, required=True)
    p.add_argument('--original-table', type=Path, required=True)
    p.add_argument('--capstone-path', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    assert not a.output.exists()
    digest, read = mapped(a.binary)
    assert digest == ORIGINAL
    sys.path.insert(0, str(a.capstone_path))
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    targets = struct.unpack('<6I', read(0x505554, 24))
    assert targets == (0x504de2, 0x504df4, 0x504deb, 0x504dfd, 0x504e06, 0x504e0f)
    offsets = (0x80, 0x88, 0x84, 0x7c, 0x8c, 0x90)
    labels = {}
    for va in range(0xd6891c, 0xd6891c+7*12, 12):
        key, ptr, _ = struct.unpack('<3I', read(va, 12))
        labels[hex(key)] = read(ptr, 80).split(b'\0')[0].decode('ascii')
    assert labels['0x15f'] == 'kQuestRewardPartyExp'
    assert labels['0x163'] == 'kQuestRewardLeeloo'
    windows = []
    spans = [(0x5048c0, 10), (0x504d96, 15)] + [(target, 7) for target in targets]
    spans += [(0x6342e7, 0x32), (0x63478a, 10), (0x634e66, 0x17),
              (0x634ec1, 0x10), (0x634f2b, 8), (0x6350ec, 0x12), (0x63515b, 8)]
    for va, size in spans:
        ins = list(md.disasm(read(va, size), va))
        count = sum(i.size for i in ins)
        windows.append({'start': hex(va), 'end_exclusive': hex(va+count),
                        'bytes': read(va, count).hex(), 'sha256': hashlib.sha256(read(va, count)).hexdigest(),
                        'instructions': [{'va': hex(i.address), 'op': i.mnemonic+' '+i.op_str} for i in ins]})
    ops = {i['va']: i['op'] for w in windows for i in w['instructions']}
    for target, offset in zip(targets, offsets):
        assert ops[hex(target)] == f'mov dword ptr [esp + {hex(offset+0x64)}], eax'
    assert ops['0x634e6a'] == 'cmp dword ptr [eax + 0x88], 0'
    assert ops['0x634e71'] == 'lea esi, [eax + 0x88]'
    assert ops['0x634ec3'] == 'fmul dword ptr [0xf94364]'
    assert ops['0x634f2b'] == 'mov dword ptr [esp + 0x34], 0x15f'
    assert ops['0x6350f0'] == 'fild dword ptr [ecx + 0x7c]'
    assert ops['0x63515b'] == 'mov dword ptr [esp + 0x34], 0x163'
    carrier = '09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442'
    name = 'Table/QuestInfo.xml'
    data = decode(members(a.original_table.read_bytes(), carrier, [name])[name], max_expanded=3_000_000)
    member_sha = hashlib.sha256(data).hexdigest()
    assert member_sha == '5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60'
    tree = ET.fromstring(data.decode('utf-8-sig'))
    quests = []
    for ident in ('14', '16', '15'):
        q = tree.find(f".//Quest[@id='{ident}']")
        assert q is not None
        quests.append({'id': ident, 'prerequisites': [e.attrib for e in q.findall('./Demands/*')],
                       'rewards_etc': [e.attrib for e in q.findall('./RewardsEtc/*')]})
    result = {'target_sha256': digest, 'tool': 'Capstone '+capstone.__version__,
              'classification': 'bounded storage/UI linkage, not award authority, units or FULL-PASS',
              'rewards_etc_type_to_record_offset': {str(i+1): hex(o) for i,o in enumerate(offsets)},
              'selected_text_labels': labels, 'windows': windows,
              'quest_resource': {'carrier_sha256': carrier, 'member_sha256': member_sha, 'rows': quests},
              'limits': ['Type2 is linked to kQuestRewardPartyExp display; type4 to kQuestRewardLeeloo display.',
                         'F94364 display multiplier is not proven Server award scaling.',
                         'No quest completion, wallet credit, level conversion or wire update inferred.',
                         'No Client execution, modification or raw assets published.']}
    a.output.write_bytes((json.dumps(result, ensure_ascii=False, indent=2)+'\n').encode('utf-8'))
    print(json.dumps({'windows': len(windows), 'type2_label': labels['0x15f'], 'quests': quests}))

if __name__ == '__main__':
    main()
