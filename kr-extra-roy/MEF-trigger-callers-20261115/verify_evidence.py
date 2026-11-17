#!/usr/bin/env python3
"""Read-only verification of bounded MEF trigger evidence.

Only original data, explicitly pinned parsing code, and this package's verifiers
are read. No Client, Lua chunk, game packet or arbitrary historical script runs.
Git checks use tree metadata and do not fetch missing source blobs.
"""
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


def check(ok, message):
    if not ok:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def read(path):
    return json.loads(path.read_text())


def verify_named_calls(folder, pe, binary):
    data = read(folder / 'native-windows.json')
    for row in data['windows'] + data['strings']:
        pe.verify_window(row)
    for row in data['strings']:
        check(bytes.fromhex(row['hex']) == row['text'].encode() + b'\0', 'Name text')
    decoded = 0
    for row in data['windows']:
        start = int(row['va'], 0)
        end = start + row['length']
        out = subprocess.check_output([
            'objdump', '-d', '-M', 'intel', '--insn-width=16',
            '--start-address=' + hex(start), '--stop-address=' + hex(end), str(binary)
        ], text=True)
        cursor = start
        instructions = bytearray()
        for line in out.splitlines():
            m = re.match(r'^\s*([0-9a-f]+):\s*((?:[0-9a-f]{2}\s+)+)\s*(.*)$', line)
            if not m:
                continue
            check(int(m[1], 16) == cursor, 'Instruction continuity: ' + row['id'])
            check('(bad)' not in m[3] and not m[3].startswith('.byte'), 'Instruction boundary')
            value = bytes.fromhex(m[2])
            instructions.extend(value)
            cursor += len(value)
            decoded += 1
        check(cursor == end and instructions.hex() == row['hex'], 'Complete code window')

    caller_sets = read(folder / 'call-wrapper-candidates.json')
    caller_sets['0x4ad0a0'] = dict(direct=read(folder / 'callback-wrapper-candidates.json'), literal=[])
    tails = read(folder / 'wrapper-address-taken-and-tail.json')
    direct = {int(target, 0): [] for target in caller_sets}
    jumps = {target: [] for target in direct}
    literals = {target: [] for target in direct}
    for section in pe.sections:
        chunk = pe.data[section['raw']:section['raw'] + section['raw_size']]
        if section['name'] == '.text':
            for offset in range(len(chunk) - 4):
                op = chunk[offset]
                if op not in (0xe8, 0xe9):
                    continue
                va = section['va'] + offset
                target = (va + 5 + struct.unpack_from('<i', chunk, offset + 1)[0]) & 0xffffffff
                if target in direct:
                    (direct if op == 0xe8 else jumps)[target].append(va)
        if section['name'] in ('.text', '.rdata', '.data'):
            for target in literals:
                pattern = struct.pack('<I', target)
                offset = chunk.find(pattern)
                while offset >= 0:
                    literals[target].append(section['va'] + offset)
                    offset = chunk.find(pattern, offset + 1)
    for name, row in caller_sets.items():
        target = int(name, 0)
        check(direct[target] == [int(r['call'], 0) for r in row['direct']], 'Direct candidates: ' + name)
        check(jumps[target] == tails[name]['tail_jumps'] == [], 'Tail-jump candidates: ' + name)
        check(literals[target] == row['literal'] == tails[name]['literal'] == [], 'Literal pointers: ' + name)
        for call in row['direct']:
            va = int(call['call'], 0)
            check(pe.at(va, 5).hex() == call['hex'], 'Original call instruction')
            check(pe.raw_of(va, 5) == int(call['raw'], 0), 'Call raw mapping')
    # Fixed-name arguments and the shared wrapper bridge, independently of prose.
    fixed = {
        0x4a8a41: '689468c000', 0x4a8b6f: '68a868c000',
        0x5615d3: '68a006c100', 0x67302a: '682c59c300', 0x6bf7db: '682c59c300',
        0x49b27e: 'b8c8f3fd00', 0x4ad0ae: 'b8eed8ffff', 0x4ad0ef: '6a00',
    }
    # Use the saved call windows for these machine-code anchors; no source execution.
    for va, value in fixed.items():
        check(pe.at(va, len(value)//2).hex() == value, 'Named-call anchor: ' + hex(va))
    check(pe.at(0x561f84, 1) == b'\xe8' and
          0x561f84 + 5 + struct.unpack('<i', pe.at(0x561f85, 4))[0] == 0x49b230,
          'Confirm callback formal wrapper getter')
    return dict(
        code_windows=len(data['windows']), code_bytes=sum(r['length'] for r in data['windows']),
        strings=len(data['strings']), decoded_instructions=decoded,
        direct_call_sites=sum(len(x) for x in direct.values()),
        bounded_targets=len(direct), tail_jump_candidates=0, literal_pointer_candidates=0)


def verify_sources(repo, manifest):
    by_commit = {}
    for row in manifest['sources']:
        by_commit.setdefault(row['commit'], []).append(row)
    checked = 0
    for commit, rows in by_commit.items():
        listing = subprocess.check_output(
            ['git', 'ls-tree', '-r', commit, '--'] + [r['path'] for r in rows],
            cwd=repo, text=True)
        entries = {line.split('\t', 1)[1]: line.split()[2] for line in listing.splitlines()}
        for row in rows:
            check(entries.get(row['path']) == row['git_blob'], 'Pinned source tree: ' + row['path'])
            checked += 1
    return checked


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--originals', type=Path, required=True)
    ap.add_argument('--repo', type=Path, required=True)
    ap.add_argument('--evidence-dir', type=Path, default=Path(__file__).resolve().parent)
    args = ap.parse_args()
    package_dir = args.evidence_dir
    manifest = read(package_dir / 'source-manifest.json')
    for row in manifest['originals']:
        content = (args.originals / row['file']).read_bytes()
        check(len(content) == row['size'] and digest(content) == row['sha256'], 'Original identity')
    helper = args.repo / manifest['parser_helper']['path']
    check(digest(helper.read_bytes()) == manifest['parser_helper']['sha256'], 'Pinned data parser')
    spec = importlib.util.spec_from_file_location('pinned_data_parser', helper)
    parser = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(parser)
    original = next(r for r in manifest['originals'] if r['file'] == '02-Tartaros.bin')
    binary = args.originals / original['file']
    pe = parser.PE(binary, original)
    artifact_index = read(package_dir / 'artifact-manifest.json')
    for row in artifact_index['files']:
        content = (args.repo / row['path']).read_bytes()
        check(len(content) == row['bytes'] and digest(content) == row['sha256'], 'Artifact identity: ' + row['path'])
    source_pins = verify_sources(args.repo, manifest)
    named = verify_named_calls(package_dir / 'named-calls', pe, binary)
    commands = {
        'native_root': [
            sys.executable, '-B', str(package_dir / 'native-root/verify_native.py'),
            str(binary), '--repo', str(args.repo)],
        'alternate_entry': [
            sys.executable, '-B', str(package_dir / 'alternate-entry/reproduce.py'),
            '--bin', str(binary), '--repo', str(args.repo)],
        'script_consumers': [
            sys.executable, '-B', str(package_dir / 'script-consumers/verify_evidence.py'),
            '--originals', str(args.originals), '--repo', str(args.repo)],
    }
    branches = {}
    for name, command in commands.items():
        branches[name] = json.loads(subprocess.check_output(command, text=True))
    print(json.dumps(dict(
        status='PASS_BOUNDED_STATIC_EVIDENCE',
        originals_checked=len(manifest['originals']),
        artifact_identities_checked=len(artifact_index['files']),
        pinned_git_tree_entries=source_pins,
        named_calls=named, branches=branches,
        scope='Original bytes, finite source/candidate sets and selected Lua data only.',
        exclusions=['No Client or Lua execution', 'No gameplay validation',
                    'No full-program negative proof', 'No new MEF first-load caller proven',
                    'No T01 FULL-PASS or RR acceptance claim'],
    ), ensure_ascii=False, indent=2))


if __name__ == '__main__':
    main()
