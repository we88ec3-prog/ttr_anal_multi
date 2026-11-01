"""Bounded offline KR input/FSM/action recheck; no target execution or native-rule inference."""
import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path

PIN = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'

def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary', type=Path, required=True)
    p.add_argument('--capstone-path', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    assert not a.output.exists() and a.output.suffix == '.json'
    sys.path.insert(0, str(a.capstone_path))
    import capstone
    data = a.binary.read_bytes()
    assert hashlib.sha256(data).hexdigest() == PIN
    pe = struct.unpack_from('<I', data, 60)[0]
    image = struct.unpack_from('<I', data, pe + 52)[0]
    section_start = pe + 24 + struct.unpack_from('<H', data, pe + 20)[0]
    sections = []
    for n in range(struct.unpack_from('<H', data, pe + 6)[0]):
        _, rva, size, raw = struct.unpack_from('<4I', data, section_start + 40*n + 8)
        sections.append((image+rva, size, raw))
    def read(va, size):
        for start, length, raw in sections:
            if start <= va and va+size <= start+length:
                return data[raw+va-start:raw+va-start+size]
        raise ValueError(hex(va))
    mappings = [(0xc07554, 0x68, 0x4c8da0), (0xc07b44, 0x68, 0x4c8da0),
                (0xc078ec, 4, 0x4cbb00), (0xc078ec, 8, 0x476430)]
    for table, slot, target in mappings:
        assert struct.unpack('<I', read(table+slot, 4))[0] == target
    assert read(0x4c75f6, 6).hex() == 'c700ec78c000'
    assert read(0x4cd728, 6).hex() == 'c707447bc000'
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    windows = []
    for va, size in [(0x546100, 0x1a0), (0x4c8a90, 0x100), (0x4c8da0, 0x30),
                     (0x4c75f6, 6), (0x4cd728, 6), (0x4cb230, 0xd0),
                     (0x4cbb00, 0xb), (0x476430, 1), (0x806060, 0x6c)]:
        instructions = list(md.disasm(read(va, size), va))
        decoded = sum(i.size for i in instructions)
        raw = read(va, decoded)
        windows.append({'start': hex(va), 'end_exclusive': hex(va+decoded),
                        'sha256': hashlib.sha256(raw).hexdigest(), 'bytes': raw.hex(),
                        'instructions': [{'va': hex(i.address), 'op': i.mnemonic+' '+i.op_str}
                                         for i in instructions]})
    result = {'target_sha256': PIN, 'tool': 'Capstone '+capstone.__version__,
              'classification': 'bounded byte and vtable checks; not FULL-PASS or official timing',
              'vtable_slots': [{'table': hex(t), 'slot': hex(s), 'target': hex(v)} for t,s,v in mappings],
              'windows': windows,
              'limits': ['Actor FSM control flags are not ASD clip duration or recovered combo windows.',
                         'Generic actor action receive is not an official Server chain scheduler.',
                         'Connection send queue does not prove retained combat intent.',
                         'No Client execution, packet capture, MEF parser or official timing recovered.']}
    a.output.write_bytes((json.dumps(result, ensure_ascii=False, indent=2)+'\n').encode('utf8'))
    print(json.dumps({'windows': len(windows), 'vtable_slots': len(mappings), 'output': str(a.output)}))

if __name__ == '__main__':
    main()
