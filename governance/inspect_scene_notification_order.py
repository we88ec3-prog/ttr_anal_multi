"""Bounded KR NPC-local scene call / notification and C2S3F producer checks."""
import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path
from verify_working_copy_login_ranges import mapped, ORIGINAL


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary', type=Path, required=True)
    p.add_argument('--capstone-path', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    assert not a.output.exists() and a.output.suffix == '.json'
    sha, read = mapped(a.binary)
    assert sha == ORIGINAL
    sys.path.insert(0, str(a.capstone_path))
    import capstone
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    windows = []
    for va, size in [(0x5b943f, 0x48), (0x4a39a0, 0x46)]:
        raw = read(va, size)
        ins = list(md.disasm(raw, va))
        assert sum(i.size for i in ins) == size
        windows.append({'start': hex(va), 'end_exclusive': hex(va + size),
                        'sha256': hashlib.sha256(raw).hexdigest(), 'bytes': raw.hex(),
                        'instructions': [{'va': hex(i.address), 'op': i.mnemonic + ' ' + i.op_str} for i in ins]})
    ops = {i['va']: i['op'] for w in windows for i in w['instructions']}
    expected = {
        '0x5b9447': 'call 0x561760', '0x5b9453': 'mov eax, 0x1c',
        '0x5b945c': 'mov cx, word ptr [esi + 0x18]',
        '0x5b9464': 'mov dx, word ptr [esi + 0x1c]', '0x5b947d': 'push 6',
        '0x4a39ad': 'mov cx, word ptr [ebp + 8]',
        '0x4a39b1': 'mov dx, word ptr [ebp + 0xc]', '0x4a39b5': 'mov eax, 0x3f',
        '0x4a39be': 'mov eax, 1', '0x4a39c3': 'mov word ptr [ebp - 6], cx',
        '0x4a39c7': 'mov word ptr [ebp - 4], dx', '0x4a39cb': 'mov word ptr [ebp - 2], ax',
        '0x4a39dc': 'push 8',
    }
    assert all(ops[k] == v for k, v in expected.items())
    result = {'classification': 'BOUNDED_NATIVE_CALL_ORDER_AND_FIELD_LAYOUT_NOT_SERVER_ACK_CONTRACT',
              'target_sha256': sha, 'tool': 'Capstone ' + capstone.__version__, 'windows': windows,
              'scene_report_layout': {'command': '0x3f', 'length': 8, 'offsets': {'2': 'WORD argument1', '4': 'WORD argument2', '6': 'WORD literal1'}},
              'normal_report_examples': [struct.pack('<4H', 0x3f, 15, i, 1).hex() for i in range(1, 5)],
              'limits': ['5B943F is an explicit basic-block anchor, not a function entry.',
                         'This NPC branch calls561760 before packing/sending1C; no unique Server reply inferred.',
                         '1C event-derived fields are not proven Quest/scene IDs by this window.',
                         '3F value1 is not successful playback or quest completion authority.',
                         'Examples are source-shaped fixtures, not captured official packets.',
                         'No Client execution, modification or network transmission.']}
    with a.output.open('x', encoding='utf-8', newline='\n') as f:
        json.dump(result, f, ensure_ascii=False, indent=2)
        f.write('\n')
    print(json.dumps({'windows': len(windows), 'assertions': len(expected), 'scene_report_bytes': 8}))


if __name__ == '__main__':
    main()
