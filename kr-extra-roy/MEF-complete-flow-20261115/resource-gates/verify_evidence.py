#!/usr/bin/env python3
"""Verify bounded resource evidence without executing the Client or Lua."""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import re
import struct
import subprocess
import sys

sys.dont_write_bytecode = True


def check(ok, reason):
    if not ok:
        raise ValueError(reason)


def read(path):
    return json.loads(path.read_text())


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--originals', required=True, type=Path)
    ap.add_argument('--repo', required=True, type=Path)
    ap.add_argument('--evidence-dir', type=Path, default=Path(__file__).resolve().parent)
    args = ap.parse_args()
    folder = args.evidence_dir
    manifest = read(folder / 'source-manifest.json')
    helper_path = args.repo / manifest['parser_helper']['path']
    check(hashlib.sha256(helper_path.read_bytes()).hexdigest() == manifest['parser_helper']['sha256'], 'Pinned parser helper')
    spec = importlib.util.spec_from_file_location('pinned_resource_reader', helper_path)
    helper = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(helper)
    binary = args.originals / manifest['originals'][0]['file']
    pe = helper.PE(binary, manifest['originals'][0])
    windows = read(folder / 'native-windows.json')['windows']
    instructions = 0
    for row in windows:
        pe.verify_window(row)
        if row['kind'] == 'string':
            check(bytes.fromhex(row['hex']) == row['text'].encode() + b'\0', 'String evidence')
        if row['kind'] != 'code':
            continue
        start = int(row['va'], 0)
        end = start + row['length']
        out = subprocess.check_output(['objdump', '-d', '-M', 'intel', '--insn-width=16',
                                       '--start-address='+hex(start), '--stop-address='+hex(end+15), str(binary)], text=True)
        cursor = start
        decoded = bytearray()
        for line in out.splitlines():
            m = re.match(r'^\s*([0-9a-f]+):\s*((?:[0-9a-f]{2}\s+)+)\s*(.*)$', line)
            if not m:
                continue
            if int(m[1], 16) >= end:
                break
            check(int(m[1], 16) == cursor, 'Contiguous decode: '+row['id'])
            check('(bad)' not in m[3] and not m[3].startswith('.byte'), 'Complete instruction: '+row['id'])
            code = bytes.fromhex(m[2])
            cursor += len(code)
            decoded.extend(code)
            instructions += 1
        check(cursor == end and decoded.hex() == row['hex'], 'Full decode: '+row['id'])
    candidates = read(folder / 'candidate-sets.json')
    literal = {int(x, 0): [] for x in candidates['literal_targets']}
    calls = {int(x, 0): dict(direct=[], tail=[], literal=[]) for x in candidates['call_targets']}
    for section in pe.sections:
        block = pe.data[section['raw']:section['raw']+section['raw_size']]
        if section['name'] in candidates['literal_sections']:
            for target in set(literal) | set(calls):
                needle = struct.pack('<I', target)
                offset = block.find(needle)
                while offset >= 0:
                    entry = dict(va=hex(section['va']+offset), raw=hex(section['raw']+offset), section=section['name'])
                    if target in literal:
                        literal[target].append(entry)
                    if target in calls:
                        calls[target]['literal'].append(entry)
                    offset = block.find(needle, offset+1)
        if section['name'] in candidates['call_sections']:
            for offset in range(len(block)-4):
                op = block[offset]
                if op not in (0xe8, 0xe9):
                    continue
                va = section['va']+offset
                target = (va+5+struct.unpack_from('<i', block, offset+1)[0]) & 0xffffffff
                if target in calls:
                    calls[target]['direct' if op == 0xe8 else 'tail'].append(va)
    for target, rows in literal.items():
        check(rows == candidates['literal_targets'][hex(target)], 'Literal candidate scope: '+hex(target))
    for target, actual in calls.items():
        expected = candidates['call_targets'][hex(target)]
        for kind in ('direct', 'tail'):
            check(actual[kind] == [int(x['va'], 0) for x in expected[kind]], 'Call candidates: '+hex(target))
        check(actual['literal'] == expected['literal'], 'Function pointer candidates: '+hex(target))
        for row in expected['direct'] + expected['tail']:
            check(pe.at(int(row['va'], 0), 5).hex() == row['hex'], 'Call original bytes')
    # These anchors identify the receiver and the decision edges, independently of pseudocode signatures.
    anchors = {
        0x48b311: 'c705a037fe008c5ac000',
        0x48b362: 'e8c9030000',
        0x48b459: '83f820',
        0x48bb1d: 'b001',
        0x48bb3f: '32c0',
        0x48bdda: 'a31ca8fb00',
        0x713d74: '84c07438',
        0x713dab: '83f8107cf0',
        0x713dd4: '33c0',
        0x71400f: 'c6054836fe0000',
        0x7142ae: 'b87c4cfe00',
        0x714348: '881d944cfe00',
        0x7147dd: '803d944cfe0000',
    }
    for address, value in anchors.items():
        check(pe.at(address, len(value)//2).hex() == value, 'Contract anchor: '+hex(address))
    check(struct.unpack('<III', pe.at(0xc05a8c, 12)) == (0x48b9c0, 0x48bb60, 0x48bb80), 'Checksum vtable')
    rtti_name = b'.?AUMD5ChecksumProvider@@\0'
    check(struct.unpack('<I', pe.at(0xc05a88, 4))[0] == 0xc69568 and
          struct.unpack('<I', pe.at(0xc69568+12, 4))[0] == 0xf7dd54 and
          pe.at(0xf7dd5c, len(rtti_name)) == rtti_name, 'Checksum provider RTTI chain')
    check(pe.at(0x809bc8, 10).hex() == '8d8c0b78a46ad7c1c107', 'MD5 first-round constant and rotation')
    check(struct.unpack('<I', pe.at(0xc44204+0x38, 4))[0] == 0x713f90, 'StdFile content pointer target')
    paths = [x['path'] for x in manifest['sources']]
    listing = subprocess.check_output(['git', 'ls-tree', '-r', manifest['main_commit'], '--']+paths, cwd=args.repo, text=True)
    tree = {line.split('\t', 1)[1]: line.split()[2] for line in listing.splitlines()}
    for row in manifest['sources']:
        check(tree.get(row['path']) == row['git_blob'], 'Pinned source tree: '+row['path'])
    print(json.dumps(dict(
        status='PASS_BOUNDED_RESOURCE_EVIDENCE', original_sha256=manifest['originals'][0]['sha256'],
        records=len(windows), bytes=sum(x['length'] for x in windows),
        code_windows=sum(x['kind']=='code' for x in windows), decoded_instructions=instructions,
        literal_targets=len(literal), literal_candidates=sum(len(x) for x in literal.values()),
        call_targets=len(calls), direct_calls=sum(len(x['direct']) for x in calls.values()),
        pinned_source_tree_entries=len(paths),
        scope='Read-only byte identity, complete selected disassembly, finite candidate census, explicit receiver/branch anchors.',
        excludes=['Client/Lua execution', 'Full-program alias absence', 'Actual deployment or manifest contents', 'MEF first-load caller proof']),
        ensure_ascii=False, indent=2))


if __name__ == '__main__':
    main()
