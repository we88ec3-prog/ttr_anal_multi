#!/usr/bin/env python3
"""Read-only verification of bounded original evidence; never execute Client/Lua.

The STPD/EX reader follows the pinned earlier reader in source-manifest.json.
Only the six named members in selected-resource-evidence.json are selected.
Lua parsing here inspects a fixed, hash-identified 5.1 chunk as data only.
"""
import argparse
from collections import Counter
import hashlib
import json
from pathlib import Path
import struct
import subprocess
import xml.etree.ElementTree as ET
import zlib


def check(ok, message):
    if not ok:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def number(value):
    return int(value, 0) if isinstance(value, str) else value


def read_json(path):
    return json.loads(path.read_text())


class PE:
    def __init__(self, path, expected):
        self.data = path.read_bytes()
        check(len(self.data) == expected['size'], 'BIN size mismatch')
        check(digest(self.data) == expected['sha256'], 'BIN hash mismatch')
        b = self.data
        check(b[:2] == b'MZ', 'DOS header')
        pe = struct.unpack_from('<I', b, 0x3c)[0]
        check(b[pe:pe + 4] == b'PE\0\0', 'PE signature')
        check(struct.unpack_from('<H', b, pe + 4)[0] == 0x14c, 'PE machine')
        check(struct.unpack_from('<H', b, pe + 24)[0] == 0x10b, 'PE32')
        self.base = struct.unpack_from('<I', b, pe + 52)[0]
        check(self.base == number(expected['image_base']), 'Image base')
        optional_size = struct.unpack_from('<H', b, pe + 20)[0]
        self.sections = []
        for i in range(struct.unpack_from('<H', b, pe + 6)[0]):
            at = pe + 24 + optional_size + i * 40
            name = b[at:at + 8].split(b'\0')[0].decode('ascii')
            vs, rva, rs, raw = struct.unpack_from('<IIII', b, at + 8)
            self.sections.append(dict(name=name, va=self.base + rva, raw=raw,
                                      raw_size=rs, virtual_size=vs))

    def raw_of(self, va, size):
        for s in self.sections:
            if s['va'] <= va and va + size <= s['va'] + s['raw_size']:
                return s['raw'] + va - s['va']
        raise ValueError(f'Not raw-backed: {va:#x}+{size:#x}')

    def at(self, va, size):
        raw = self.raw_of(va, size)
        return self.data[raw:raw + size]

    def verify_window(self, record):
        va = number(record['va'])
        raw = number(record.get('raw', record.get('raw_offset')))
        b = bytes.fromhex(record['hex'])
        check(len(b) == record['length'], f'Length {va:#x}')
        check(self.raw_of(va, len(b)) == raw, f'PE mapping {va:#x}')
        check(self.at(va, len(b)) == b, f'Bytes {va:#x}')
        check(digest(b) == record['sha256'], f'Window hash {va:#x}')


def ex_decode(data):
    if data[:2] != b'EX':
        return data
    mode = data[2]
    compressed, expanded, offset = struct.unpack_from('<III', data, 4)
    check(mode in (0, 1) and offset >= 16 and offset + compressed <= len(data), 'EX bounds')
    payload = data[offset:offset + compressed]
    if mode:
        key = [0x30, 0xe7]
        for i in range(2, 1024):
            key.append((key[i - 2] + key[i - 1] + 0x13 - (0x56 if i == 0x17c else 0)) & 255)
        payload = bytes(v ^ key[i % 1024] for i, v in enumerate(payload))
    result = zlib.decompress(payload)
    check(len(result) == expanded, 'EX expanded size')
    return result


class STPD:
    def __init__(self, path, expected):
        raw = path.read_bytes()
        check(len(raw) == expected['bytes'] and digest(raw) == expected['sha256'], 'STP identity')
        check(raw[:4] == b'STPD', 'STPD header')
        self.data = bytes(v ^ 255 for v in raw)
        b = self.data
        index = struct.unpack_from('<I', b, 4)[0]
        check(raw[index:index + 4] == b'STPI', 'STPI header')
        pos = index + 8
        self.files = {}

        def node(parent):
            nonlocal pos
            length = struct.unpack_from('<H', b, pos)[0]
            pos += 2
            name = b[pos:pos + length].decode('ascii').rstrip('\0')
            pos += length
            kind = b[pos]
            pos += 1
            path = '/'.join(filter(None, (parent, name)))
            if kind in (1, 2):
                count = struct.unpack_from('<I', b, pos)[0]
                pos += 12
                for _ in range(count):
                    node(path)
            elif kind == 0:
                _, ident = struct.unpack_from('<II', b, pos)
                pos += 16
                self.files[path] = ident
            else:
                raise ValueError(f'STPI kind {kind}')

        node('')
        check(pos == len(b), 'STPI full consumption')
        table = struct.unpack_from('>I', b, 12)[0]
        count = struct.unpack_from('<I', b, table)[0]
        self.blocks = {}
        for i in range(count):
            ident, size, first, last = struct.unpack_from('<4I', b, table + 4 + i * 32)
            check(ident not in self.blocks, 'Duplicate block id')
            self.blocks[ident] = (size, first, last)

    def verify_member(self, record):
        ident = self.files[record['virtual_path']]
        size, first, last = self.blocks[ident]
        at = 16 + first * 1024
        check(ident == record['block_id'], 'Member id')
        check((size, first, last, at) == (record['stored_length'], record['first_block'],
              record['last_block'], record['stored_offset']), 'Member physical mapping')
        check(last >= first and size <= (last - first + 1) * 1024, 'Member bounds')
        stored = self.data[at:at + size]
        check(stored.startswith(bytes.fromhex(record['xor_restored_prefix_hex'])), 'Stored prefix')
        decoded = ex_decode(stored)
        check(len(decoded) == record['decoded_length'] and digest(decoded) == record['decoded_sha256'], 'Decoded member identity')
        check(decoded.startswith(bytes.fromhex(record['decoded_prefix_hex'])), 'Decoded prefix')
        if 'lua_header_hex' in record:
            check(decoded[:12].hex() == record['lua_header_hex'], 'Lua header')
        return decoded


def read_lua51_prototypes(data):
    """Inspect the fixed little-endian/int4/size_t4/number8 chunk, without execution."""
    check(data[:12].hex() == '1b4c75615100010404040800', 'Lua chunk header')
    pos = 12
    protos = []

    def take(fmt):
        nonlocal pos
        result = struct.unpack_from('<' + fmt, data, pos)
        pos += struct.calcsize('<' + fmt)
        return result

    def string():
        nonlocal pos
        size = take('I')[0]
        if size == 0:
            return None
        check(pos + size <= len(data) and data[pos + size - 1] == 0, 'Lua string bounds')
        value = data[pos:pos + size - 1].decode('ascii')
        pos += size
        return value

    def proto(parent):
        nonlocal pos
        index = len(protos)
        p = dict(index=index, parent=parent, start=pos)
        protos.append(p)
        p['source'] = string()
        p['first'], p['last'] = take('II')
        p['nups'], p['params'], p['vararg'], p['stack'] = take('BBBB')
        count = take('I')[0]
        p['code_offset'] = pos
        p['words'] = list(take('I' * count))
        constants = []
        for _ in range(take('I')[0]):
            kind = take('B')[0]
            if kind == 0:
                value = None
            elif kind == 1:
                value = bool(take('B')[0])
            elif kind == 3:
                value = take('d')[0]
            elif kind == 4:
                value = string()
            else:
                raise ValueError(f'Lua constant type {kind}')
            constants.append(value)
        p['constants'] = constants
        p['children'] = [proto(index) for _ in range(take('I')[0])]
        line_count = take('I')[0]
        p['lines'] = list(take('I' * line_count))
        p['locals'] = []
        for _ in range(take('I')[0]):
            name = string()
            start, end = take('II')
            p['locals'].append(dict(name=name, start=start, end=end))
        p['upvalue_names'] = [string() for _ in range(take('I')[0])]
        p['end'] = pos
        return index

    proto(None)
    check(pos == len(data), 'Lua chunk full consumption')
    return protos


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin', required=True, type=Path)
    ap.add_argument('--event-stp', required=True, type=Path)
    ap.add_argument('--table-stp', required=True, type=Path)
    ap.add_argument('--evidence-dir', type=Path, default=Path(__file__).resolve().parent)
    ap.add_argument('--qbase-json', type=Path, help='Optional pinned full 76-prototype prior decoding')
    ap.add_argument('--repo', type=Path, help='Optional Git checkout: verify pinned repository source blobs')
    ap.add_argument('--out', type=Path, help='Optional derived JSON result; never an input path')
    args = ap.parse_args()
    e = args.evidence_dir
    m = read_json(e / 'native-windows.json')
    pe = PE(args.bin, m['binary'])
    for x in m['windows'] + m['strings']:
        pe.verify_window(x)
    for g in m['zero_initialized_globals']:
        va = number(g['va'])
        s = next(s for s in pe.sections if s['name'] == g['section'])
        check(s['va'] + s['raw_size'] <= va < s['va'] + s['virtual_size'], 'BSS tail claim')
        check(g['raw_offset'] is None and g['zero_initialized_virtual_tail'], 'BSS metadata')

    aliases = read_json(e / 'alias-census.json')
    for x in aliases['initializer'] + aliases['accessor']:
        pe.verify_window(x)
    xrefs = read_json(e / 'parser-xrefs.json')
    for item in xrefs['absolute_pointers']:
        for hit in item['hits']:
            check(pe.at(number(hit['va']), 4) == struct.pack('<I', number(item['target'])), 'Absolute pointer xref')
    for item in xrefs['direct_calls']:
        for address in item['E8_rel32_candidates']:
            va = number(address)
            b = pe.at(va, 5)
            check(b[0] == 0xe8 and va + 5 + struct.unpack_from('<i', b, 1)[0] == number(item['target']), 'Direct call xref')

    bindings = read_json(e / 'prepass-bindings.json')
    check(pe.at(number(bindings['empty_callback']), 3).hex() == bindings['empty_callback_bytes'], 'Empty callback')
    for x in bindings['default_global_bindings']:
        name = x['name'].encode('ascii') + b'\0'
        check(pe.at(number(x['name_va']), len(name)) == name, 'Prepass name')
        instruction = pe.at(number(x['registration_name_instruction']), 5)
        check(instruction == b'\xbf' + struct.pack('<I', number(x['name_va'])), 'Prepass registration name')
    for x in bindings['per_load_bindings']:
        check(pe.at(number(x['callback_push_va']), 5) == b'\x68' + struct.pack('<I', number(x['callback_va'])), 'Effective prepass callback')

    resources = read_json(e / 'selected-resource-evidence.json')
    supplied = {'06-Event.stp': args.event_stp, '07-Table.stp': args.table_stp}
    archives = {x['file']: STPD(supplied[x['file']], x) for x in resources['carriers']}
    decoded = {x['virtual_path']: archives[x['carrier']].verify_member(x) for x in resources['members']}
    maps = ET.fromstring(decoded['Table/_MapList.xml'].decode('utf-8-sig'))
    for row in resources['selected_map_rows']:
        check(any(all(node.attrib.get(k) == v for k, v in row.items()) for node in maps.iter()), 'Selected MapList row')
    scenes = ET.fromstring(decoded['Event/SceneList.xml'].decode('euc_kr'))
    row = resources['selected_scene_row']
    check(any(all(node.attrib.get(k) == v for k, v in row.items()) for node in scenes.iter()), 'Selected SceneList row')

    q = read_json(e / 'qbase-prototypes-evidence.json')
    chunk = decoded['Event/qbase.lua']
    protos = read_lua51_prototypes(chunk)
    check(len(protos) == 76 and sum(len(x['words']) for x in protos) == 906, 'qbase structure count')
    selected_words = 0
    for expected in q['prototypes']:
        observed = protos[expected['index']]
        for key in ('index', 'parent', 'start', 'source', 'first', 'last', 'nups', 'params',
                    'vararg', 'stack', 'code_offset', 'words', 'constants', 'children', 'end'):
            check(observed[key] == expected[key], f'qbase selected proto {expected["index"]} field {key}')
        selected_words += len(expected['words'])
    full_qbase = False
    if args.qbase_json:
        b = args.qbase_json.read_bytes()
        check(digest(b) == q['json_source_sha256'], 'Prior full qbase JSON identity')
        old = json.loads(b)
        check(len(old['prototypes']) == len(protos), 'Prior full proto count')
        for expected, observed in zip(old['prototypes'], protos):
            for key in ('index', 'parent', 'code_offset', 'words', 'constants', 'children', 'start', 'end'):
                check(observed[key] == expected[key], f'qbase full proto {expected["index"]} field {key}')
        full_qbase = True

    source_count = 0
    source_manifest = read_json(e / 'source-manifest.json')
    if args.repo:
        for x in source_manifest['repository_sources']:
            b = subprocess.check_output(['git', 'cat-file', 'blob', x['git_blob']], cwd=args.repo)
            check(hashlib.sha1(b'blob ' + str(len(b)).encode() + b'\0' + b).hexdigest() == x['git_blob'], 'Git blob identity')
            if 'sha256' in x:
                check(digest(b) == x['sha256'], f'Source SHA256 {x["path"]}')
            if 'bytes' in x:
                check(len(b) == x['bytes'], f'Source length {x["path"]}')
            source_count += 1

    result = dict(
        schema='ttr-mef-parser-executor-storage-verification-v1', all_matched=True,
        bin_sha256=digest(pe.data), native_windows=len(m['windows']),
        native_window_bytes_including_overlap=sum(x['length'] for x in m['windows']),
        windows_by_group=dict(Counter(x['group'] for x in m['windows'])),
        named_strings=len(m['strings']), zero_initialized_globals=len(m['zero_initialized_globals']),
        alias_candidate_windows=len(aliases['initializer']) + len(aliases['accessor']),
        prepass_stub_names=len(bindings['default_global_bindings']), effective_callbacks=len(bindings['per_load_bindings']),
        selected_resource_members=len(decoded), selected_map_rows=len(resources['selected_map_rows']),
        qbase_structure_prototypes=len(protos), qbase_structure_instruction_words=906,
        qbase_selected_prototypes=len(q['prototypes']), qbase_selected_instruction_words=selected_words,
        qbase_selected_constants_and_structure_match=True, qbase_full_prior_json_compared=full_qbase,
        repository_source_blobs_verified=source_count,
        scope='Source identity, bounded bytes/PE mapping, recorded positive xrefs, known resources, and qbase data inspection only. No Client/Lua execution, exhaustive-negative proof, original MEF grammar, semantic FULL-PASS, or runtime acceptance.')
    if args.out:
        protected = {p.resolve() for p in (args.bin, args.event_stp, args.table_stp)}
        protected.update(p.resolve() for p in e.iterdir() if p.name != 'verification-result.json')
        if args.qbase_json:
            protected.add(args.qbase_json.resolve())
        check(args.out.resolve() not in protected, 'Output would overwrite an input')
        args.out.parent.mkdir(parents=True, exist_ok=True)
        args.out.write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps(result, ensure_ascii=False, indent=2))


if __name__ == '__main__':
    main()
