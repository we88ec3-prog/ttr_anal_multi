"""Bound CSquare initializer/controller and progress notification, not Town1 routing."""
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
    locator = struct.unpack('<I', read(0xc06fac, 4))[0]
    descriptor = struct.unpack('<I', read(locator + 12, 4))[0]
    assert read(descriptor + 8, 80).split(b'\0')[0] == b'.?AVCSquare@Scene@@'
    assert struct.unpack('<I', read(0xc06fb0 + 0x10, 4))[0] == 0x4bbc10
    start, end = 0x4bbc10, 0x4bbf09
    raw = read(start, end - start)
    ins = list(md.disasm(raw, start))
    assert sum(i.size for i in ins) == len(raw) and ins[-1].mnemonic == 'ret'
    boundaries = {i.address for i in ins}
    for i in ins:
        if i.mnemonic.startswith('j') and i.op_str.startswith('0x'):
            target = int(i.op_str, 16)
            if start <= target < end: assert target in boundaries
    ops = {hex(i.address): i.mnemonic + ' ' + i.op_str for i in ins}
    expected = {'0x4bbcc4': 'mov esi, 2', '0x4bbd43': 'cmp dword ptr [0xfba7ac], esi',
                '0x4bbd4d': 'call 0x544f50', '0x4bbd8f': 'call 0x548540',
                '0x4bbe86': 'mov eax, 0x43', '0x4bbe90': 'mov byte ptr [esp + 0x16], bl',
                '0x4bbe94': 'mov byte ptr [esp + 0x17], 0xa', '0x4bbea6': 'push 4'}
    assert all(ops[k] == v for k, v in expected.items())
    result = {'classification': 'BOUNDED_CSQUARE_INITIALIZER_NOT_NORMAL_TOWN1_SCENE_PROOF',
              'target_sha256': sha, 'vtable': '0xc06fb0', 'initializer': hex(start),
              'end_exclusive': hex(end), 'initializer_sha256': hashlib.sha256(raw).hexdigest(),
              'instructions': [{'va': hex(i.address), 'op': i.mnemonic + ' ' + i.op_str} for i in ins],
              'limits': ['Initializer selects/reset controller kind2 or calls548540; not host/P2P identity.',
                         'C2S43 four-byte progress includes opaque middle byte and final10; not world-ready ACK.',
                         'No claim that Town1 necessarily enters through this exact scene or opcode order.',
                         'Callees and all side effects are not exhaustively semantically verified.',
                         'No Client execution, modification or runtime transfer.']}
    with a.output.open('x', encoding='utf-8', newline='\n') as f:
        json.dump(result, f, ensure_ascii=False, indent=2)
        f.write('\n')
    print(json.dumps({'initializer': hex(start), 'bytes': len(raw), 'assertions': len(expected), 'controller_kind': 2}))


if __name__ == '__main__':
    main()
