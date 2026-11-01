"""Read-only checks of selected legacy claims, NOT a full function/Server audit.

No target execution, process attachment, API calls, patching or legacy test runs.
Capstone is an explicit external verification dependency; no automatic install.
"""
import argparse
import hashlib
import importlib
import json
import struct
import sys
from pathlib import Path

EXPECTED = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'

def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--binary', required=True, type=Path)
    parser.add_argument('--capstone-path', type=Path)
    parser.add_argument('--output', required=True, type=Path)
    args = parser.parse_args()
    if args.capstone_path:
        sys.path.insert(0, str(args.capstone_path.resolve()))
    capstone = importlib.import_module('capstone')
    image = args.binary.read_bytes()
    digest = hashlib.sha256(image).hexdigest()
    if digest != EXPECTED:
        raise ValueError('Wrong original KR binary; no checks performed')
    pe = struct.unpack_from('<I', image, 0x3C)[0]
    assert image[pe:pe + 4] == b'PE\0\0'
    assert struct.unpack_from('<H', image, pe + 4)[0] == 0x14C
    image_base = struct.unpack_from('<I', image, pe + 52)[0]
    optional_size = struct.unpack_from('<H', image, pe + 20)[0]
    sections = []
    for index in range(struct.unpack_from('<H', image, pe + 6)[0]):
        pos = pe + 24 + optional_size + 40 * index
        virtual_size, rva, size, raw = struct.unpack_from('<IIII', image, pos + 8)
        assert raw + size <= len(image)
        sections.append((image_base + rva, raw, size))

    def read(address, size):
        for start, raw, length in sections:
            if start <= address and address + size <= start + length:
                offset = raw + address - start
                return offset, image[offset:offset + size]
        raise ValueError(f'Unmapped source bytes: {address:#x}')

    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    checks = []
    def exact(address, expected_hex, claim):
        expected = bytes.fromhex(expected_hex)
        offset, actual = read(address, len(expected))
        matched = actual == expected
        instructions = [{'address': hex(i.address), 'bytes': i.bytes.hex(),
                         'mnemonic': i.mnemonic, 'operands': i.op_str}
                        for i in md.disasm(actual, address)]
        checks.append({'address': hex(address), 'file_offset': offset,
                       'claim_scope': claim, 'expected_hex': expected.hex(),
                       'actual_hex': actual.hex(), 'matched': matched,
                       'instructions': instructions})
    def relative_call(address, destination, claim):
        _, code = read(address, 5)
        exact(address, (b'\xe8' + struct.pack('<i', destination - address - 5)).hex(), claim)

    # Existing E74 byte assertions, rechecked against the actual frozen target.
    exact(0x4B803F, '8b5702', 'app2 reads DWORD at payload+2; business meaning not proven')
    exact(0x4B8075, '6a14', 'app2 name source count20 WCHAR')
    exact(0x4B8077, '8d470c', 'app2 name source starts payload+0x0C')
    exact(0x4B807D, '68f238f900', 'app2 name destination F938F2')
    exact(0x4B8926, '83f941', '65-byte row count guard occurs after these header reads')
    exact(0x4B8956, '83c76f', 'first row slot position app+0x6F, not a name field')
    exact(0x4B899A, '69c010020000', 'slot stride0x210 in local role store')
    exact(0x67250A, 'b93e000000', 'name request app3E constant')
    exact(0x672506, '8d54242a', 'name destination stack expression; full +6 derivation stays E74 scope')
    exact(0x672533, '6a30', 'name request length48')
    exact(0x4C14E1, 'c786fc600000d0214c00', 'scene-local app4A registration relative to +5EAC')
    exact(0x4C21D6, '0fbf4802', 'app4A reads signed16 at payload+2')
    exact(0x4C21DB, '6845420f00', 'app4A constructs local event F4245')
    relative_call(0x4C21E0, 0x58AB80, 'app4A local event helper, not proof of3E/4A wire pairing')
    exact(0x5A689A, '837b1401', 'local name result consumer tests1')
    exact(0x672617, '6a14566a1568f238f900', 'name result success path references same F938F2')
    # Legacy docs explicitly identify this table assignment; no original reply order inferred.
    exact(0x4B7DFF, 'c705fc2ffd00508f4b00', 'shared callback cell FD2FFC stores4B8F50; index60 from FD2CFC/8')

    windows = []
    for address, size, scope in [
        (0x4B8F50, 0x140, 'app60 handler constructor/scene/parser and outbound F5 local path'),
        (0x4C22C0, 0x80, 'scene list prelude, two-byte prefix and27-byte record division'),
        (0x5A6510, 0x180, 'ExpeditionPage name-ready initialization/display conditions'),
        (0x4B9260, 0x160, 'tutorial scene consumer; official post-name pairing unknown')]:
        offset, code = read(address, size)
        rows = []
        for i in md.disasm(code, address):
            rows.append({'address': hex(i.address), 'bytes': i.bytes.hex(),
                         'mnemonic': i.mnemonic, 'operands': i.op_str})
            if i.mnemonic in ('ret', 'retf'):
                break
        windows.append({'start': hex(address), 'file_offset': offset, 'requested_bytes': size,
                        'scope': scope, 'instructions': rows,
                        'limitation': 'Linear static decode from stated entry, stops at first return; not complete CFG or dynamic reachability'})
    result = {'schema': 's00-legacy-static-recheck-v1', 'target_sha256': digest,
              'authority': 'READ_ONLY_SHIPPED_BYTES_BOUNDED_RECHECK',
              'tool': {'name': 'Capstone', 'version': capstone.__version__},
              'checks': checks, 'windows': windows,
              'limitations': ['Selected claims only, not T01 FULL-PASS or whole-function semantics',
                              'No original Server trace, opcode pairing, initial role policy or runtime UI proof',
                              'Historical Client patches and old fixture values are not authorized/native requirements']}
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_bytes((json.dumps(result, ensure_ascii=False, indent=2) + '\n').encode('utf-8'))
    print(json.dumps({'target_sha256': digest, 'matched': sum(c['matched'] for c in checks),
                      'checks': len(checks), 'windows': len(windows), 'output': str(args.output)}))
    if not all(c['matched'] for c in checks):
        raise SystemExit(1)

if __name__ == '__main__':
    main()
