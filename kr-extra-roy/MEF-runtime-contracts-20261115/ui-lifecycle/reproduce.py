#!/usr/bin/env python3
"""Read-only verifier for the bounded F4355 / F4322 native evidence package.

Only Python's standard library, objdump, and locally available Git trees are
used. This program does not execute the Client/Lua, write files, fetch, or
checkout. Shell redirection of its JSON output is the caller's choice.
"""
import argparse
import collections
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys

EXPECTED_SHA256 = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
EXPECTED_SIZE = 12472320
HERE = Path(__file__).resolve().parent
INS_RE = re.compile(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}(?:\s+|$))+)(.*?)\s*$')


def require(ok, message):
    if not ok:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def hx(value):
    return f'0x{value:08X}'


def integer(value):
    return int(value, 16)


def git_blob(data):
    return hashlib.sha1(f'blob {len(data)}\0'.encode() + data).hexdigest()


def load(name):
    return json.loads((HERE / name).read_text())


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin', required=True, type=Path)
    ap.add_argument('--repo', required=True, type=Path)
    ap.add_argument('--navigation-dir', type=Path,
                    help='Optional acquisition copies of the 45 pinned .c files')
    ap.add_argument('--check-deliverables', action='store_true',
                    help='Also verify the final eight artifact hashes')
    args = ap.parse_args()
    binpath = args.bin.resolve()
    repo = args.repo.resolve()
    data = binpath.read_bytes()
    require(len(data) == EXPECTED_SIZE, 'BIN size mismatch')
    require(digest(data) == EXPECTED_SHA256, 'BIN SHA-256 mismatch')
    u16 = lambda p: struct.unpack_from('<H', data, p)[0]
    u32 = lambda p: struct.unpack_from('<I', data, p)[0]
    pe = u32(0x3C)
    require(data[:2] == b'MZ' and data[pe:pe+4] == b'PE\0\0', 'Not a PE image')
    require(u16(pe+4) == 0x14C, 'Not i386')
    opt = pe+24
    require(u16(opt) == 0x10B, 'Not PE32')
    base = u32(opt+28)
    require(base == 0x400000, 'Unexpected ImageBase')
    secpos = opt+u16(pe+20)
    sections = []
    for number in range(u16(pe+6)):
        at = secpos+number*40
        sections.append(dict(
            name=data[at:at+8].rstrip(b'\0').decode(),
            va=base+u32(at+12), virtual_size=u32(at+8),
            raw=u32(at+20), raw_size=u32(at+16)))

    def raw(va):
        for sec in sections:
            if sec['va'] <= va < sec['va']+sec['raw_size']:
                return sec['raw']+va-sec['va'], sec['name']
        raise ValueError(f'VA has no file-backed mapping: {hx(va)}')

    def read(va, length):
        offset, section = raw(va)
        require(length > 0 and raw(va+length-1)[1] == section,
                f'Window crosses raw section boundary at {hx(va)}')
        return data[offset:offset+length]

    def word(va):
        return struct.unpack('<I', read(va, 4))[0]

    evidence = load('native-windows.json')
    routes = load('routes.json')
    sources = load('source-manifest.json')
    require(evidence['target_sha256'] == EXPECTED_SHA256, 'Evidence target mismatch')
    require(evidence['target_size'] == EXPECTED_SIZE, 'Evidence target size mismatch')
    require(evidence['imagebase'] == hx(base), 'Evidence ImageBase mismatch')
    require(evidence['sections'] == sections, 'Evidence PE sections mismatch')
    windows = evidence['windows']
    require(len({w['id'] for w in windows}) == len(windows), 'Duplicate window IDs')
    navigation_starts = {
        int(Path(p['path']).stem, 16) for p in sources['source_pins']
        if p['role'] == 'navigation_only'}
    instructions = {}
    calls = []
    disassembly_lines = []
    counts = collections.Counter()

    for w in windows:
        start, end = integer(w['va']), integer(w['end_exclusive'])
        content = read(start, end-start)
        offset, section = raw(start)
        require(w['raw'] == hx(offset) and w['section'] == section,
                f'{w["id"]}: raw mapping mismatch')
        require(w['length'] == end-start and w['hex'] == content.hex(),
                f'{w["id"]}: native bytes mismatch')
        require(w['sha256'] == digest(content), f'{w["id"]}: hash mismatch')
        counts['records'] += 1
        counts['window_bytes_with_overlap'] += len(content)
        if w['kind'] != 'code':
            require('instructions' not in w, 'Data window has instructions')
            continue
        origin = integer(w['decode_origin'])
        require(origin <= start, f'{w["id"]}: decode origin after start')
        require(origin in navigation_starts, f'{w["id"]}: unpinned function origin')
        text = subprocess.check_output([
            'objdump', '-D', '-Mintel', '--insn-width=16',
            f'--start-address={origin}', f'--stop-address={end+15}',
            str(binpath)], text=True)
        observed = []
        cursor = start
        for line in text.splitlines():
            match = INS_RE.match(line)
            if not match:
                continue
            va = int(match[1], 16)
            if not start <= va < end:
                continue
            b = bytes.fromhex(match[2])
            require(va == cursor, f'{w["id"]}: start/interior instruction boundary')
            require(b == read(va, len(b)), f'{w["id"]}: objdump bytes mismatch')
            cursor += len(b)
            require(cursor <= end, f'{w["id"]}: end cuts an instruction')
            observed.append(dict(va=hx(va), bytes=b.hex(), asm=match[3]))
        require(cursor == end, f'{w["id"]}: incomplete decode')
        require(observed == w['instructions'], f'{w["id"]}: decode differs')
        counts['code_windows'] += 1
        counts['decoded_instructions_with_overlap'] += len(observed)
        disassembly_lines.append(
            f'\n## {w["id"]} VA {w["va"]}..{w["end_exclusive"]} '
            f'raw {w["raw"]} SHA256 {w["sha256"]}\n')
        for ins in observed:
            disassembly_lines.append(f'{ins["va"]}  {ins["bytes"]:<32} {ins["asm"]}')
            va = integer(ins['va'])
            if va in instructions:
                require(instructions[va] == ins, 'Overlapping decode mismatch')
            instructions[va] = ins
            b = bytes.fromhex(ins['bytes'])
            if len(b) == 5 and b[0] in (0xE8, 0xE9):
                target = (va+5+struct.unpack_from('<i', b, 1)[0]) & 0xFFFFFFFF
                calls.append(dict(window=w['id'], va=ins['va'],
                                  kind='call' if b[0] == 0xE8 else 'tail_or_jump',
                                  target=hx(target), bytes=b.hex()))
            elif ins['asm'].startswith('call '):
                calls.append(dict(window=w['id'], va=ins['va'],
                                  kind='indirect_call', operand=ins['asm'][5:].strip(),
                                  bytes=b.hex()))
    require(('\n'.join(disassembly_lines)+'\n').encode() ==
            (HERE/'native-disassembly.txt').read_bytes(), 'Readable disassembly mismatch')
    require(calls == routes['bounded_call_sites'], 'Bounded call set mismatch')
    counts['bounded_call_or_jump_entries'] = len(calls)
    require(routes['owners']['ui_state'] == dict(
        va=hx(0xFAADD8), current_code=hx(0xFAADEC), pending_code=hx(0xFAADF0),
        page_map_pointer_offset='0x2C'), 'UI state owner metadata mismatch')
    require(routes['owners']['FXUI'] == dict(
        va=hx(0xF94810), current_page_offset='0x13C4', current_page_global=hx(0xF95BD4),
        event_deque_offset='0x145C', event_deque_global=hx(0xF95C6C),
        template_map_offset='0x1410', template_map_global=hx(0xF95C20),
        active_dialog_list_offset='0x1420'), 'FXUI owner metadata mismatch')
    require(routes['queued_event']['size'] == 20 and
            routes['queued_event']['vtable'] == hx(0xC47B0C) and
            routes['queued_event']['field_values'] == {
                '0x04': '0xFFFFFFFF', '0x08': '0xFFFFFFFF',
                '0x0C': '0x00000000', '0x10': '0x000F4355'},
            'F4355 payload metadata mismatch')

    expected_vtables = {
        'FXUI': (0xC4790C, {0x14: 0x74F000}),
        'CMissionFieldPage': (0xC1D1AC, {0x15C: 0x595D20, 0x18C: 0x5AC590,
                                       0x190: 0x5AC5C0, 0x170: 0x5A3950,
                                       0x174: 0x595E30}),
        'CScenarioFieldPage': (0xC1D62C, {0x15C: 0x595D20, 0x18C: 0x5AC590,
                                        0x190: 0x5AC5C0, 0x170: 0x5A3950,
                                        0x174: 0x595E30}),
        'FXUIEvent': (0xC47B0C, {0x10: 0x753A00}),
        'CMsgBoxWaitAndEnableChat': (0xC19764, {0x28: 0x585BC0, 0xD4: 0x757000,
                                             0x114: 0x755E50, 0x15C: 0x476430}),
        'CClient': (0xC05AA4, {0x30: 0x490FE0}),
    }
    require({t['name'] for t in routes['vtables']} == set(expected_vtables),
            'Vtable set mismatch')
    for table in routes['vtables']:
        va = integer(table['va'])
        expected_va, expected_slots = expected_vtables[table['name']]
        require(va == expected_va, 'Unexpected vtable address')
        col = word(va-4)
        require(col == integer(table['col']), 'COL pointer mismatch')
        td = word(col+12)
        require(td == integer(table['type_descriptor']), 'Type descriptor mismatch')
        at, _ = raw(td+8)
        name = data[at:data.index(b'\0', at)].decode()
        require(name == table['rtti'], 'RTTI name mismatch')
        for slot, target in table['slots'].items():
            require(word(va+integer(slot)) == integer(target), 'Vtable slot mismatch')
        for slot, target in expected_slots.items():
            require(word(va+slot) == target, 'Required semantic vtable edge mismatch')
        counts['vtable_rtti_chains'] += 1

    expected_switches = {
        0xF4355: (0xF434B, 0x59B9D0, 0x59B9B0, 7, 0x59B9A8),
        0xF4322: (0xF42D8, 0x59B854, 0x59B79C, 0x2D, 0x59B795),
        0xF43DB: (0xF43DB, 0x596698, 0x596684, 0, 0x596653),
        0xF43DC: (0xF43DB, 0x596698, 0x596684, 1, 0x59665D),
        0xF43FF: (0xF43DB, 0x596698, 0x596684, 3, 0x596677),
    }
    require({integer(s['event']) for s in routes['switch_selections']} ==
            set(expected_switches), 'Switch event set mismatch')
    for selection in routes['switch_selections']:
        event = integer(selection['event'])
        switch_base, indices, target_table, slot, target = expected_switches[event]
        index = event-switch_base
        require(selection == dict(event=hx(event), base=hx(switch_base), index=index,
                                  index_va=hx(indices+index), slot=slot,
                                  target_va=hx(target_table+slot*4), target=hx(target)),
                'Switch metadata mismatch')
        require(read(indices+index, 1)[0] == slot and
                word(target_table+slot*4) == target, 'Switch bytes mismatch')
        counts['switch_selections'] += 1

    anchors = {
        0x4C485D: 'a3f0adfa00', 0x4BC8F4: 'a3f0adfa00',
        0x58A9D4: 'c7000c7bc400', 0x58A9DA: 'c74004ffffffff',
        0x58A9E1: 'c74008ffffffff', 0x58A9E8: '89480c',
        0x58A9EB: 'c7401055430f00', 0x58AA2E: 'be6c5cf900',
        0x58AA33: 'e828982700', 0x5874D6: '8935ecadfa00',
        0x5874DC: '8935f0adfa00', 0x49152B: 'e8208d0f00',
        0x58A315: 'c782c413000000000000', 0x58A399: '89b2c4130000',
        0x58A423: '894b14', 0x58A429: 'c74318ffffffff',
        0x58A721: 'be1048f900', 0x58A729: 'e8225e1c00',
        0x74D9C3: 'c7051048f9000c79c400', 0x75062E: 'ffd0',
        0x74F067: '8b8bc4130000', 0x74F076: 'ffd0',
        0x597285: 'ffd0', 0x56210C: '830d3088fb0002',
        0x562157: 'c7401022430f00', 0x562226: '68c8000000',
        0x562232: 'e839900200', 0x58B2F3: 'e8b87f1c00',
        0x753374: '8988d4000000', 0x7533E5: '8988d0000000',
        0x5622D1: '6822430f00', 0x5622D6: 'b81048f900',
        0x5622DB: 'e860111f00', 0x562307: '83253088fb00fd',
        0x753491: '394a10', 0x7534AF: 'ffd0', 0x7534C0: 'ffd0',
        0x755E85: '898680000000', 0x476430: 'c20400',
    }
    for va, expected_hex in anchors.items():
        b = bytes.fromhex(expected_hex)
        require(read(va, len(b)) == b, f'Anchor bytes mismatch {hx(va)}')
        require(instructions.get(va, {}).get('bytes') == expected_hex,
                f'Anchor not a decoded instruction {hx(va)}')
    counts['semantic_instruction_anchors'] = len(anchors)

    env = dict(os.environ, GIT_NO_LAZY_FETCH='1', GIT_OPTIONAL_LOCKS='0',
               GIT_NO_REPLACE_OBJECTS='1', GIT_TERMINAL_PROMPT='0')

    def git(*args):
        return subprocess.check_output(['git', *args], cwd=repo, env=env)

    require(sources['binary']['sha256'] == EXPECTED_SHA256 and
            sources['binary']['bytes'] == EXPECTED_SIZE, 'Source target mismatch')
    for pin in sources['source_pins']:
        line = git('ls-tree', pin['commit'], '--', pin['path']).decode().strip()
        require(bool(line), f'Missing tree pin {pin["path"]}')
        meta, path = line.split('\t', 1)
        mode, kind, oid = meta.split()
        require(kind == 'blob' and path == pin['path'] and oid == pin['blob'],
                f'Tree pin mismatch {pin["path"]}')
        counts['source_tree_pins'] += 1
        if pin['role'] != 'navigation_only':
            content = git('show', f'{pin["commit"]}:{pin["path"]}')
            require(len(content) == pin['bytes'] and digest(content) == pin['sha256']
                    and git_blob(content) == pin['blob'], 'Pinned text content mismatch')
            counts['pinned_text_contents'] += 1
        elif args.navigation_dir:
            content = (args.navigation_dir/Path(pin['path']).name).read_bytes()
            require(len(content) == pin['bytes'] and digest(content) == pin['sha256']
                    and git_blob(content) == pin['blob'], 'Navigation copy mismatch')
            counts['navigation_contents'] += 1

    gov_paths = ['governance/MEF-FUNCTIONAL-COMPLETION.md',
                 'governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md']
    diff = git('diff', '--no-ext-diff', '--no-textconv', sources['previous_main'],
               sources['main'], '--', *gov_paths)
    require(diff == (HERE/'governance-diff.patch').read_bytes(), 'Governance diff mismatch')
    require(digest(diff) == sources['governance_diff']['sha256'], 'Governance diff hash')

    if args.check_deliverables:
        package = load('deliverables-manifest.json')
        require({i['path'] for i in package['files']} == {
            'report.md', 'native-windows.json', 'native-disassembly.txt',
            'routes.json', 'source-manifest.json', 'governance-diff.patch',
            'reproduce.py', 'validation.json'}, 'Artifact set mismatch')
        for item in package['files']:
            require(Path(item['path']).name == item['path'], 'Unexpected artifact path')
            content = (HERE/item['path']).read_bytes()
            require(len(content) == item['bytes'] and digest(content) == item['sha256'],
                    f'Artifact mismatch: {item["path"]}')
            counts['artifact_hashes'] += 1

    expected_counts = dict(records=66, window_bytes_with_overlap=8820,
                           code_windows=45, decoded_instructions_with_overlap=2248,
                           vtable_rtti_chains=6, switch_selections=5,
                           bounded_call_or_jump_entries=206, source_tree_pins=51,
                           pinned_text_contents=6, semantic_instruction_anchors=39)
    for key, value in expected_counts.items():
        require(counts[key] == value, f'Unexpected {key}: {counts[key]}')
    print(json.dumps(dict(
        status='PASS', binary_sha256=EXPECTED_SHA256,
        counts=dict(counts),
        navigation_content_check=('45 acquisition copies verified' if args.navigation_dir
                                  else 'not supplied; 45 navigation tree/blob pins verified'),
        artifact_hash_check=('final package hashes verified' if args.check_deliverables
                             else 'not requested; use --check-deliverables after packaging'),
        scope='Bounded native evidence; dynamic window/subcontrol callbacks remain bounded; '
              'not a whole-program absence proof',
        read_only=True, client_or_lua_executed=False, network_fetch=False,
    ), ensure_ascii=False, indent=2))


if __name__ == '__main__':
    try:
        main()
    except (ValueError, OSError, subprocess.CalledProcessError, KeyError) as exc:
        print(json.dumps(dict(status='FAIL', error=str(exc)), ensure_ascii=False,
                         indent=2), file=sys.stderr)
        raise SystemExit(1)
