"""Bounded read-only loading frontend/resource evidence, never executes a target."""
import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path
import xml.etree.ElementTree as ET
from inspect_tutorial_bounds_resource import members
from inspect_first_tutorial_cluster import decode

TARGET = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
TABLE = 'ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c'
TEXTURES = '2a04d6bbb5687a9a680a66d75703ef1cb4a04b941f9501af9ab1b185060c0f67'


def main():
    p = argparse.ArgumentParser(description=__doc__)
    p.add_argument('--binary', type=Path, required=True)
    p.add_argument('--workspace', type=Path, required=True)
    p.add_argument('--capstone-path', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    assert not a.output.exists() and a.output.suffix == '.json'
    sys.path.insert(0, str(a.capstone_path))
    import capstone
    b = a.binary.read_bytes()
    assert hashlib.sha256(b).hexdigest() == TARGET
    pe = struct.unpack_from('<I', b, 0x3c)[0]
    base = struct.unpack_from('<I', b, pe + 52)[0]
    opt = struct.unpack_from('<H', b, pe + 20)[0]
    sections = []
    for i in range(struct.unpack_from('<H', b, pe + 6)[0]):
        at = pe + 24 + opt + 40 * i
        _, rva, size, raw = struct.unpack_from('<4I', b, at + 8)
        sections.append((base + rva, size, raw))
    def read(va, size):
        for start, count, raw in sections:
            if start <= va and va + size <= start + count:
                return b[raw + va - start:raw + va - start + size]
        raise ValueError(hex(va))
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    windows = []
    # Every decode starts at a saved function entry. These are bounded windows,
    # not a whole-function/CFG review. Data strings use their own PE sections.
    for va, size in [(0x48AAD0, 0x96), (0x493170, 0x90), (0x494860, 0x96),
                     (0x494A90, 0x225), (0x55D7E0, 0x5B7), (0x8DC2F0, 3)]:
        raw = read(va, size)
        instructions = list(md.disasm(raw, va))
        if va == 0x55D7E0:
            instructions = [i for i in instructions if 0x55DD30 <= i.address <= 0x55DD96]
        windows.append(dict(start_va=hex(va), size=size, sha256=hashlib.sha256(raw).hexdigest(),
                            instructions=[dict(va=hex(i.address), asm=i.mnemonic + ' ' + i.op_str) for i in instructions]))
    assert read(0x8DC2F0, 3) == bytes.fromhex('33c0c3')
    assert read(0xC10458, 13) == b'StartLoading\0'
    assert read(0xC10468, 11) == b'EndLoading\0'
    name = 'Table/_LoadDisplay.xml'
    data = decode(members((a.workspace / 'Table.stp').read_bytes(), TABLE, [name])[name])
    assert hashlib.sha256(data).hexdigest() == '49aba61c484fc27964e2c75ecd487e9a1e6a4fdcf9b52173cbed3088167ee265'
    tree = ET.fromstring(data.decode('utf-8-sig'))
    categories = {int(c.get('Num')): [x.get('Texture') for x in c.findall('Param')]
                  for c in tree.findall('./BackGround/Category')}
    assert categories[3][0] == 'UI/Texture/Loading/Loading_Square_01.dds'
    texture_names = ['Texture/Loading/Loading_General_01.etf',
                     'Texture/Loading/Loading_Misson_01.etf', 'Texture/Loading/Loading_Square_01.etf']
    textures = [dict(member=n, size=len(r), sha256=hashlib.sha256(r).hexdigest()) for n, r in
                members((a.workspace / 'UI/Texture.stp').read_bytes(), TEXTURES, texture_names).items()]
    result = dict(schema='s00-loading-display-evidence-v1', target_sha256=TARGET,
                  classification='BOUNDED_SOURCE_AND_RESOURCE_NOT_RUNTIME_ACCEPTANCE', client_execution=False,
                  windows=windows, table_carrier_sha256=TABLE, load_display_member_sha256=hashlib.sha256(data).hexdigest(),
                  selected_categories={1: [categories[1][0], categories[1][5]], 2: categories[2], 3: categories[3]},
                  texture_carrier_sha256=TEXTURES, selected_texture_members=textures,
                  limits=['ETF basenames present; native DDS-to-ETF resolution not established by this check',
                          'No official backend timing, MEF transfer, render duration or playable acceptance'])
    a.output.write_bytes((json.dumps(result, ensure_ascii=False, indent=2) + '\n').encode('utf8'))
    print(json.dumps(dict(windows=len(windows), texture_members=len(textures), runtime_acceptance=False)))


if __name__ == '__main__':
    main()
