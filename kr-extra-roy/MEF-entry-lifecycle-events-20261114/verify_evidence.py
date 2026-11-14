#!/usr/bin/env python3
"""Verify recorded native and resource evidence without executing Client or Lua.

Uses the earlier, pinned read-only PE/STPD/Lua data parser in this repository.
No game process is launched or attached. --out may only create/replace the
verification receipt, never any original or evidence input.
"""
import argparse
from collections import Counter
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import sys
import xml.etree.ElementTree as ET


def check(value, message):
    if not value:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def num(value):
    return int(value, 0) if isinstance(value, str) else value


def read_json(path):
    return json.loads(path.read_text())


def load_parser(evidence):
    helper = evidence.parent / 'MEF-parser-executor-storage-20261114' / 'verify_evidence.py'
    check(digest(helper.read_bytes()) ==
          '8eb16bbc06940769197b2a3446c66a024a3e98d1c44f035ce69c4fee36212a56',
          'Prior read-only parser identity differs')
    spec = importlib.util.spec_from_file_location('pinned_data_parser', helper)
    module = importlib.util.module_from_spec(spec)
    sys.dont_write_bytecode = True
    spec.loader.exec_module(module)
    return module


def scan_targets(pe, targets):
    """Reproduce only the recorded targets, not a whole-function call graph."""
    result = {hex(t): {'direct': [], 'literal': []} for t in targets}
    section = next(s for s in pe.sections if s['name'] == '.text')
    data = pe.data[section['raw']:section['raw'] + section['raw_size']]
    at = -1
    while True:
        at = data.find(b'\xe8', at + 1)
        if at < 0 or at + 5 > len(data):
            break
        va = section['va'] + at
        target = (va + 5 + struct.unpack_from('<i', data, at + 1)[0]) & 0xffffffff
        if target in targets:
            result[hex(target)]['direct'].append({'va': hex(va), 'raw': hex(section['raw'] + at)})
    for target in targets:
        needle = struct.pack('<I', target)
        for section in pe.sections:
            if section['name'] not in ('.text', '.rdata', '.data'):
                continue
            at = section['raw'] - 1
            while True:
                at = pe.data.find(needle, at + 1, section['raw'] + section['raw_size'])
                if at < 0:
                    break
                result[hex(target)]['literal'].append({
                    'va': hex(section['va'] + at - section['raw']),
                    'raw': hex(at), 'section': section['name']})
    return result


def member_data(archive, record, parser):
    path = record.get('path', record.get('virtual_path'))
    ident = archive.files[path]
    size, first, last = archive.blocks[ident]
    offset = 16 + first * 1024
    check(last >= first and size <= (last - first + 1) * 1024, 'STPD member bounds')
    for key, value in [('block_id', ident), ('stored_length', size),
                       ('first_block', first), ('last_block', last), ('stored_offset', offset)]:
        if key in record:
            check(record[key] == value, f'Member {path}: {key}')
    decoded = parser.ex_decode(archive.data[offset:offset + size])
    check(len(decoded) == record.get('decoded_size', record.get('decoded_length')), f'Member size: {path}')
    check(digest(decoded) == record['decoded_sha256'], f'Member hash: {path}')
    return decoded


def compare_prototype(observed, expected):
    for key in ('index', 'parent', 'start', 'source', 'first', 'last', 'nups',
                'params', 'vararg', 'stack', 'code_offset', 'words', 'constants', 'children', 'end'):
        check(observed[key] == expected[key], f'Lua prototype {expected["index"]}: {key}')


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin', type=Path, required=True)
    ap.add_argument('--event-stp', type=Path, required=True)
    ap.add_argument('--table-stp', type=Path, required=True)
    ap.add_argument('--repo', type=Path, help='Also verify all pinned source blobs and complete prior Lua decodings')
    ap.add_argument('--evidence-dir', type=Path, default=Path(__file__).resolve().parent)
    ap.add_argument('--out', type=Path)
    args = ap.parse_args()
    e = args.evidence_dir
    parser = load_parser(e)
    native = read_json(e / 'native-windows.json')
    pe = parser.PE(args.bin, native['binary'])
    for row in native['windows']:
        pe.verify_window(row)

    relations = read_json(e / 'native-relations.json')
    for table in relations['vtables']:
        vt = num(table['vtable_va'])
        col = num(table['complete_object_locator_va'])
        td = num(table['type_descriptor_va'])
        check(struct.unpack('<I', pe.at(vt - 4, 4))[0] == col, 'RTTI locator')
        check(struct.unpack('<I', pe.at(col + 12, 4))[0] == td, 'RTTI descriptor')
        name = table['type_name'].encode('ascii') + b'\0'
        check(pe.at(td + 8, len(name)) == name, 'RTTI name')
        for slot in table['slots']:
            check(struct.unpack('<I', pe.at(vt + num(slot['offset']), 4))[0] ==
                  num(slot['target']), 'Vtable slot')
    for row in relations['zero_initialized_globals']:
        va = num(row['va'])
        section = next(s for s in pe.sections if s['va'] <= va < s['va'] + s['virtual_size'])
        check(section['name'] == row['section'] and va >= section['va'] + section['raw_size'],
              'Global must be in the zero initialized virtual tail')
    for row in relations['direct_calls']:
        va, target = num(row['va']), num(row['target'])
        b = pe.at(va, 5)
        check(b[0] == 0xe8 and (va + 5 + struct.unpack('<i', b[1:])[0]) & 0xffffffff == target,
              f'Direct call {va:#x}')

    bindings = read_json(e / 'lb-bindings.json')
    for row in bindings:
        va = num(row['registration_va'])
        check(pe.at(va + 0x18, 10) == b'\xc7\x05' +
              struct.pack('<II', num(row['native_slot']), num(row['target'])), 'lb callback registration')
        check(pe.at(va + 0x58, 5) == b'\x68' + struct.pack('<I', num(row['name_va'])), 'lb name push')
        check(pe.at(va + 0x69, 5) == b'\x68' + struct.pack('<I', num(row['wrapper'])), 'lb wrapper push')
        check(pe.at(num(row['name_va']), len(row['name']) + 1) == row['name'].encode() + b'\0', 'lb name')

    entry_xrefs = read_json(e / 'upstream-xrefs.json')
    event_xrefs = read_json(e / 'death-targeted-call-candidates.json')
    targets = {num(x) for x in entry_xrefs['targets']} | {num(x) for x in event_xrefs} | {0x4a8b90}
    found = scan_targets(pe, targets)
    for key, expected in entry_xrefs['targets'].items():
        check(found[key] == expected, f'Bounded upstream candidates {key}')
    for key, expected in event_xrefs.items():
        check([x['va'] for x in found[key]['direct']] == expected, f'Bounded event candidates {key}')
    check([num(x['va']) for x in found['0x4a8b90']['direct']] ==
          [0x47ca45, 0x4c19ae, 0x4c4e8a], 'Three direct tco caller candidates')

    counter = read_json(e / 'local-counter-literal-refs.json')
    ts = next(s for s in pe.sections if s['name'] == '.text')
    literal = struct.pack('<I', num(counter['address']))
    positions = []
    at = ts['raw'] - 1
    while True:
        at = pe.data.find(literal, at + 1, ts['raw'] + ts['raw_size'])
        if at < 0:
            break
        positions.append((at, ts['va'] + at - ts['raw']))
    check(positions == [(num(x['operand_raw']), num(x['operand_va'])) for x in counter['references']],
          'Local counter literal operand scope')
    check(struct.unpack('<I', pe.at(0xf7de04, 4))[0] == 1001, 'Local counter file initializer')

    resources = read_json(e / 'selected-entry-resources.json')
    supplied = {'06-Event.stp': args.event_stp, '07-Table.stp': args.table_stp}
    archives = {}
    for row in resources['carriers']:
        name = Path(row['path']).name
        archives[name] = parser.STPD(supplied[name], {'bytes': row['size'], 'sha256': row['sha256']})
    selected_rows = selected_lines = 0
    for row in resources['members'] + resources['selected_scene_scripts']:
        decoded = member_data(archives[row['carrier']], row, parser)
        if 'selection' in row:
            encoding = 'euc_kr' if row['path'] == 'Event/SceneList.xml' else 'utf-8-sig'
            tree = ET.fromstring(decoded.decode(encoding))
            selection = row['selection']
            matches = [x.attrib for x in tree.iter(selection['tag'])
                       if x.attrib.get(selection['key']) in selection['values']]
            check(len(matches) == len(row['selected']), 'Selected XML row count')
            for actual, expected in zip(matches, row['selected']):
                check(all(actual.get(k) == v for k, v in expected.items()), 'Selected XML attributes')
            selected_rows += len(matches)
        if 'selected_lines' in row:
            lines = decoded.decode(row['source_encoding']).splitlines()
            for line in row['selected_lines']:
                check(lines[line['line'] - 1] == line['text'], 'Selected source line')
                selected_lines += 1

    lua = read_json(e / 'lua-prototypes-evidence.json')
    lua_protos = lua_words = selected_protos = selected_words = 0
    lua_full_sources = 0
    event_raw = args.event_stp.read_bytes()
    parsed_by_hash = {}
    for item in lua:
        source = item['source']
        start, size = source['raw_offset'], source['stored_size']
        raw = event_raw[start:start + size]
        check(digest(raw) == source['stored_sha256'], 'Lua stored member hash')
        chunk = bytes(v ^ 255 for v in raw)
        check(digest(chunk) == source['chunk_sha256'], 'Lua decoded member hash')
        protos = parser.read_lua51_prototypes(chunk)
        parsed_by_hash[source['chunk_sha256']] = (chunk, protos)
        check(len(protos) == source['prototypes'], 'Lua prototype count')
        words = sum(len(x['words']) for x in protos)
        check(words == source['instruction_words'], 'Lua instruction count')
        lua_protos += len(protos)
        lua_words += words
        for expected in item['selected_prototypes']:
            compare_prototype(protos[expected['index']], expected)
            packed = struct.pack('<' + 'I' * len(expected['words']), *expected['words'])
            check(packed.hex() == expected['code_words_hex'] and
                  digest(packed) == expected['code_words_sha256'], 'Selected Lua code bytes')
            for instruction in expected['decoded']:
                pc = instruction['pc']
                word = expected['words'][pc]
                check(num(instruction['word']) == word and
                      instruction['raw_offset'] == expected['code_offset'] + pc * 4,
                      'Decoded Lua instruction offset/word')
                for field, value in [('A', word >> 6 & 255), ('B', word >> 23 & 511),
                                     ('C', word >> 14 & 511), ('Bx', word >> 14),
                                     ('sBx', (word >> 14) - 131071)]:
                    check(instruction[field] == value, f'Decoded Lua {field}')
            selected_protos += 1
            selected_words += len(expected['words'])
        if args.repo:
            prior = subprocess.check_output(['git', 'cat-file', 'blob', source['repo_blob']], cwd=args.repo)
            check(digest(prior) == source['source_json_sha256'], 'Full Lua JSON source identity')
            previous = json.loads(prior)['prototypes']
            check(len(previous) == len(protos), 'Full Lua prior count')
            for observed, expected in zip(protos, previous):
                compare_prototype(observed, expected)
            lua_full_sources += 1

    event_selections = 0
    tutorial = read_json(e / 'tutorial-script-evidence.json')
    for member in tutorial['members']:
        start, size = num(member['stored_offset']), num(member['stored_length'])
        check(digest(event_raw[start:start + size]) == member['stored_sha256'], 'Event consumer stored hash')
        chunk, protos = parsed_by_hash[member['decoded_sha256']]
        check(len(protos) == member['verified_prototypes'], 'Event consumer proto count')
        for selected in member['selected']:
            proto = protos[selected['prototype']]
            if 'constants' in selected:
                check(proto['constants'] == selected['constants'], 'Event consumer constants')
            if 'decoded_hex' in selected:
                at, length = selected['decoded_offset'], selected['length']
                check(at == proto['code_offset'] + selected['pc_start'] * 4 and
                      length == (selected['pc_end_exclusive'] - selected['pc_start']) * 4,
                      'Event consumer PC range')
                check(chunk[at:at + length].hex() == selected['decoded_hex'] and
                      digest(chunk[at:at + length]) == selected['decoded_sha256'], 'Event consumer bytes')
                check(selected['stored_offset'] == start + at and
                      event_raw[start + at:start + at + length].hex() == selected['stored_hex'],
                      'Event consumer stored bytes')
            for instruction in selected['instructions']:
                word = proto['words'][instruction['pc']]
                check(num(instruction['word']) == word and instruction['raw_offset'] ==
                      proto['code_offset'] + instruction['pc'] * 4, 'Event consumer instruction')
            event_selections += 1

    source_count = 0
    manifest = read_json(e / 'source-manifest.json')
    if args.repo:
        for row in manifest['repository_sources']:
            b = subprocess.check_output(['git', 'cat-file', 'blob', row['git_blob']], cwd=args.repo)
            blob = hashlib.sha1(b'blob ' + str(len(b)).encode() + b'\0' + b).hexdigest()
            check(blob == row['git_blob'] and digest(b) == row['sha256'] and
                  len(b) == row['bytes'], f'Source blob: {row["path"]}')
            listing = subprocess.check_output(['git', 'ls-tree', row['commit'], '--', row['path']],
                                              cwd=args.repo, text=True)
            check(listing.split()[2] == blob, f'Source commit/path: {row["path"]}')
            source_count += 1

    result = {
        'status': 'PASS', 'client_or_lua_executed': False,
        'native_records': len(native['windows']),
        'native_bytes_including_overlap': sum(x['length'] for x in native['windows']),
        'records_by_group': dict(Counter(x['group'] for x in native['windows'])),
        'rtti_vtables': len(relations['vtables']),
        'zero_initialized_globals': len(relations['zero_initialized_globals']),
        'explicit_direct_calls': len(relations['direct_calls']),
        'lb_bindings': len(bindings), 'entry_target_scopes': len(entry_xrefs['targets']),
        'event_target_scopes': len(event_xrefs), 'tco_direct_callers': 3,
        'counter_literal_operands': len(positions), 'selected_entry_members': 7,
        'selected_xml_rows': selected_rows, 'selected_script_lines': selected_lines,
        'lua_resources': len(lua), 'lua_structure_prototypes': lua_protos,
        'lua_structure_instruction_words': lua_words, 'lua_selected_prototypes': selected_protos,
        'lua_selected_instruction_words': selected_words, 'lua_full_prior_sources_compared': lua_full_sources,
        'event_consumer_selections': event_selections,
        'repository_source_blobs_verified': source_count,
        'scope': 'Pinned source identity, recorded original bytes/PE mapping, bounded candidate scopes, selected resources and Lua data only. No Client/Lua execution, exhaustive-negative proof, native MEF grammar, FULL-PASS or gameplay acceptance.'}
    if args.out:
        protected = {x.resolve() for x in (args.bin, args.event_stp, args.table_stp)}
        protected.update(p.resolve() for p in e.iterdir() if p.name != 'verification-result.json')
        check(args.out.resolve() not in protected, 'Output must not overwrite an input')
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps(result, ensure_ascii=False, indent=2))


if __name__ == '__main__':
    main()
