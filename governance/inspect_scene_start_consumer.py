"""Bounded KR scene-start receiver registration and signed field consumer."""
import argparse, hashlib, json, struct, sys
from pathlib import Path
from verify_working_copy_login_ranges import mapped, ORIGINAL


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary', type=Path, required=True)
    p.add_argument('--capstone-path', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    assert not a.output.exists()
    sha, read = mapped(a.binary)
    assert sha == ORIGINAL
    sys.path.insert(0, str(a.capstone_path))
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    windows = []
    for va, size in [(0x5020b0, 0xbc), (0x503040, 0x7f), (0x4fda30, 0x83)]:
        raw = read(va, size)
        ins = list(md.disasm(raw, va))
        assert sum(i.size for i in ins) == size
        windows.append({'start': hex(va), 'end_exclusive': hex(va+size),
                        'sha256': hashlib.sha256(raw).hexdigest(), 'bytes': raw.hex(),
                        'instructions': [{'va': hex(i.address), 'op': i.mnemonic+' '+i.op_str} for i in ins]})
    ops = {i['va']: i['op'] for w in windows for i in w['instructions']}
    expected = {'0x50210b': 'mov dword ptr [0xfab4dc], 0x503040',
                '0x4fda3e': 'mov eax, dword ptr [esi + edi*8 + 4]',
                '0x4fda8a': 'call dword ptr [ebp - 4]',
                '0x503098': 'movsx ecx, word ptr [eax + 4]',
                '0x50309c': 'movsx edx, word ptr [eax + 2]',
                '0x5030a0': 'push ecx', '0x5030a1': 'push edx',
                '0x5030a2': 'mov ecx, 0xfb73c0', '0x5030a7': 'call 0x561760'}
    assert all(ops[k] == v for k,v in expected.items())
    base, slot = 0xfab2a0, 0xfab4dc
    assert (slot-base-4) % 8 == 0
    command = (slot-base-4)//8
    assert command == 0x47
    result = {'classification': 'BOUNDED_SOURCE_BACKED_SCENE_START_CONSUMER_NOT_OFFICIAL_SCHEDULING',
              'target_sha256': sha, 'tool': 'Capstone '+capstone.__version__, 'windows': windows,
              'registration': {'object_base': hex(base), 'handler_slot': hex(slot), 'command': hex(command)},
              'consumer_minimum_bytes': 6, 'fields': {'2': 'signed WORD argument1', '4': 'signed WORD argument2'},
              'source_shaped_examples_not_sent': [struct.pack('<Hhh', command, 15, s).hex() for s in (2,3,4)],
              'limits': ['Minimum consumed bytes is not an upstream exact-length validation proof.',
                         'The handler sign-extends both words; no unsigned ID domain inferred.',
                         'Registration object base follows existing QuestMgr/dispatcher analysis; no full subsystem review.',
                         'No official timing, quest acceptance/completion, spawn or next-scene authorization inferred.',
                         'C2S3F literal1 can be cleanup; never use it alone as permission to advance.',
                         'No Client execution, modification, network traffic or live Host change.']}
    with a.output.open('x', encoding='utf-8', newline='\n') as f:
        json.dump(result, f, ensure_ascii=False, indent=2)
        f.write('\n')
    print(json.dumps({'windows': len(windows), 'assertions': len(expected)+2, 'command': hex(command)}))


if __name__ == '__main__':
    main()
