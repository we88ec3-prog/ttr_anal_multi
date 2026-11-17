#!/usr/bin/env python3
"""Read-only verification of the bounded MEF complete-flow research package.

Checks original bytes, the package identity, source tree pins, and each finite
substudy. Does not run Client/Lua or claim functional/gameplay acceptance.
"""
import argparse
import hashlib
import json
from pathlib import Path
import re
import subprocess
import sys

sys.dont_write_bytecode = True


def check(ok, message):
    if not ok:
        raise ValueError(message)


def read(path):
    return json.loads(path.read_text())


def digest(data):
    return hashlib.sha256(data).hexdigest()


def check_lua_native_windows(folder, binary):
    """Independently decode the lifecycle package's new native windows."""
    records = read(folder / 'native-windows.json')['windows']
    count = 0
    for row in records:
        start = int(row['va'], 0)
        end = int(row['end_exclusive'], 0)
        output = subprocess.check_output([
            'objdump', '-d', '-M', 'intel', '--insn-width=16',
            '--start-address='+hex(start), '--stop-address='+hex(end+15), str(binary)
        ], text=True)
        cursor = start
        raw = bytearray()
        for line in output.splitlines():
            m = re.match(r'^\s*([0-9a-f]+):\s*((?:[0-9a-f]{2}\s+)+)\s*(.*)$', line)
            if not m:
                continue
            address = int(m[1], 16)
            if address >= end:
                break
            check(address == cursor, 'Instruction continuity: '+row['id'])
            check('(bad)' not in m[3] and not m[3].startswith('.byte'), 'Decode: '+row['id'])
            code = bytes.fromhex(m[2])
            cursor += len(code)
            raw.extend(code)
            count += 1
        check(cursor == end and raw.hex() == row['hex'], 'Full instruction window: '+row['id'])
    return dict(code_windows=len(records), decoded_instructions=count)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--originals', type=Path, required=True)
    ap.add_argument('--repo', type=Path, required=True)
    ap.add_argument('--evidence-dir', type=Path, default=Path(__file__).resolve().parent)
    ap.add_argument('--reference-text-cache', type=Path,
                    help='Optional exact previously read reference texts for a sparse checkout')
    args = ap.parse_args()
    root = args.evidence_dir
    manifest = read(root / 'source-manifest.json')
    artifacts = read(root / 'artifact-manifest.json')
    for row in artifacts['files']:
        content = (args.repo / row['path']).read_bytes()
        check(len(content) == row['bytes'] and digest(content) == row['sha256'], 'Artifact: '+row['path'])
    for row in manifest['originals']:
        content = (args.originals / row['file']).read_bytes()
        check(len(content) == row['size'] and digest(content) == row['sha256'], 'Original: '+row['file'])
    grouped = {}
    for row in manifest['sources']:
        grouped.setdefault(row['commit'], []).append(row)
    pins = 0
    for commit, rows in grouped.items():
        output = subprocess.check_output(['git', 'ls-tree', '-r', commit, '--']+[x['path'] for x in rows],
                                         cwd=args.repo, text=True)
        observed = {line.split('\t', 1)[1]: line.split()[2] for line in output.splitlines()}
        for row in rows:
            check(observed.get(row['path']) == row['git_blob'], 'Source pin: '+row['path'])
            pins += 1
    binary = args.originals / '02-Tartaros.bin'
    common = ['--originals', str(args.originals), '--repo', str(args.repo)]
    script_command = [sys.executable, '-B', str(root/'script-lifecycle/verify_evidence.py')]+common
    if args.reference_text_cache:
        script_command += ['--reference-text-cache', str(args.reference_text_cache)]
    commands = {
        'resource_gates': [sys.executable, '-B', str(root/'resource-gates/verify_evidence.py')]+common,
        'parser_executor': [sys.executable, '-B', str(root/'parser-executor/reproduce.py'),
                            '--bin', str(binary), '--repo', str(args.repo)],
        'native_aliases': [sys.executable, '-B', str(root/'native-aliases/verify_native.py'),
                           '--bin', str(binary), '--repo', str(args.repo), '--check-disassembly'],
        'script_lifecycle': script_command,
        'scene_cancellation': [sys.executable, '-B', str(root/'scene-cancellation/reproduce.py'),
                               '--bin', str(binary), '--repo', str(args.repo)],
    }
    branches = {name: json.loads(subprocess.check_output(command, text=True))
                for name, command in commands.items()}
    script_decode = check_lua_native_windows(root/'script-lifecycle', binary)
    links = 0
    for row in artifacts['files']:
        path = args.repo / row['path']
        if path.suffix != '.md':
            continue
        for target in re.findall(r'\[[^\]]+\]\(([^)]+)\)', path.read_text()):
            if re.match(r'^[a-zA-Z][a-zA-Z0-9+.-]*:', target) or target.startswith('#'):
                continue
            target = target.split('#', 1)[0]
            check((path.parent / target).exists(), 'Local report link: '+str(path)+' -> '+target)
            links += 1
    print(json.dumps(dict(
        status='PASS_BOUNDED_STATIC_EVIDENCE', originals_checked=len(manifest['originals']),
        artifacts_checked=len(artifacts['files']), unique_pinned_git_tree_entries=pins,
        local_report_links_checked=links, branches=branches,
        independent_script_native_decode=script_decode,
        scope='Original identities and bounded bytes/instructions, selected Lua data, finite sources and target bindings.',
        exclusions=['No Client or Lua execution', 'No new resource deployment', 'No gameplay acceptance',
                    'No whole-program negative proof', 'No native MEF first-load caller proven',
                    'No T01 FULL-PASS or RR ACCEPTED claim']), ensure_ascii=False, indent=2))


if __name__ == '__main__':
    main()
