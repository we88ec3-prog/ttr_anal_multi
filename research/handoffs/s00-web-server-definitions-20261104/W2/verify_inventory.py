#!/usr/bin/env python3
"""Read-only W2 evidence verification against the original ZIP, Table and Base.

Requires Python 3 and jsonschema. Inputs are read as bytes and SHA-pinned before
parsing. STP members are decoded in memory; no mirror, Client, historical script,
or game/server process is created or executed. --report is the only output write.
"""
from __future__ import annotations

import argparse
from collections import Counter, defaultdict
from copy import deepcopy
import csv
import hashlib
from importlib.metadata import version
import io
import json
from pathlib import Path, PurePosixPath
import re
import struct
import subprocess
import sys
from xml.parsers import expat
import xml.etree.ElementTree as ET
from zipfile import ZipFile
import zlib

from jsonschema import Draft202012Validator, ValidationError

AI_FIELDS = {'chase', 'perception', 'return', 'skill_selection', 'windup',
             'hit', 'cooldown', 'hurt', 'death'}
TARGETS = (1001, 1009, 1004)
TABLES = ['local-resources/Table/' + x for x in
          ['_ActorList.xml', 'CharSkill.xml', 'SkillActiveTable.xml',
           'Skill/SkillMatrix.xml', 'IndependentSkillEffect.xml']]
GENERAL = 'git-evidence/kr/evidence/3d714c4c995d1d6c33cced5d70af3ebf1246a46583fb5f0cdbf65f280453f5f2.txt'
ZIP_SHA = '7587e67dd012a020f0276c8cfd6b791ad07f8f5e7867931481c94aa30abf3e1a'
TABLE_SHA = '09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442'
BASE_SHA = '1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957'
MATRIX_MEMBER = 'Table/Skill/Matrix/MonsterMatrices.xml'
BODY_MEMBERS = {1001: 'Mon/00_HokyPoky.abf', 1009: 'Mon/01_Moose.abf',
                1004: 'Mon/01_Nepenths.abf'}
BODY_SHAS = {
    1001: '3d817eb1d3c2e0839853f3d233771a3829470b8fdb9cd8391d920485cb95f633',
    1009: 'd0ba2a3b0cd941e7a267f24c6ce68cb5f727d2f72a7ae9f21b1b51cd8cd3aa6b',
    1004: '6a581ad59dc5b009a8b155d7ef4aa45ec44c1753fb3936b2223f98dab50eca71',
}


def require(condition, message):
    if not condition:
        raise ValueError(message)


def digest(data):
    return hashlib.sha256(data).hexdigest()


def blob(data):
    return hashlib.sha1(b'blob ' + str(len(data)).encode() + b'\0' + data).hexdigest()


def load_json(path):
    return json.loads(path.read_bytes())


def load_csv(path):
    with path.open(encoding='utf-8', newline='') as f:
        return list(csv.DictReader(f))


def safe_member(path):
    return (isinstance(path, str) and bool(path) and '\\' not in path
            and not PurePosixPath(path).is_absolute()
            and '..' not in PurePosixPath(path).parts)


def xml_records(raw):
    # Every caller hashes/verifies the original bytes before this strict decode.
    declaration = re.search(br'encoding=[\"\x27]([^\"\x27]+)', raw[:200])
    encoding = declaration.group(1).decode('ascii') if declaration else 'utf-8'
    text = raw.decode(encoding, errors='strict')
    root = ET.fromstring(text)
    records, stack = [], []
    parser = expat.ParserCreate()

    def start(tag, attrs):
        record = {'tag': tag, 'attrs': attrs, 'line': parser.CurrentLineNumber,
                  'ancestors': list(stack)}
        records.append(record)
        stack.append({'tag': tag, 'attrs': attrs})

    def end(tag):
        require(stack[-1]['tag'] == tag, 'XML stack mismatch')
        stack.pop()

    parser.StartElementHandler, parser.EndElementHandler = start, end
    parser.Parse(text, True)
    return root, records, encoding


def walk_refs(value):
    if isinstance(value, dict):
        if {'package_path', 'sha256', 'evidence_basis'} <= set(value):
            yield value
        for child in value.values():
            yield from walk_refs(child)
    elif isinstance(value, list):
        for child in value:
            yield from walk_refs(child)


def read_package(path):
    """Read the original ZIP without extraction; retain old directory CLI support."""
    zip_sha = None
    if path.is_file():
        zip_bytes = path.read_bytes()
        zip_sha = digest(zip_bytes)
        require(zip_sha == ZIP_SHA, 'Original input ZIP SHA-256 mismatch')
        archive = ZipFile(io.BytesIO(zip_bytes))
        files = [i for i in archive.infolist() if not i.is_dir()]
        require(len(files) == len({i.filename for i in files}), 'Duplicate ZIP member')
        require(all(safe_member(i.filename) for i in files), 'Unsafe ZIP member path')
        manifest_raw = archive.read('MANIFEST.json')
        actual = {i.filename for i in files}
        get = archive.read
    else:
        require(path.is_dir(), 'Input must be the supplied ZIP or its extracted directory')
        manifest_raw = (path / 'MANIFEST.json').read_bytes()
        actual = {str(p.relative_to(path)) for p in path.rglob('*') if p.is_file()}

        def get(name):
            source = (path / name).resolve()
            require(source.is_relative_to(path), f'Unsafe input path: {name}')
            return source.read_bytes()

    manifest = json.loads(manifest_raw)
    records = manifest['files']
    require(len(records) == 130, 'Unexpected source manifest file count')
    expected = {r['path']: r for r in records}
    require(len(expected) == len(records), 'Duplicate input manifest paths')
    require(actual == set(expected) | {'MANIFEST.json'}, 'Unexpected missing or extra input files')
    raw = {}
    for name, item in expected.items():
        require(safe_member(name), f'Unsafe manifest path: {name}')
        data = get(name)
        require(len(data) == item['bytes'] and digest(data) == item['sha256'], f'Input mismatch: {name}')
        raw[name] = data
    return manifest_raw, manifest, expected, raw, zip_sha


class STPArchive:
    """Bounded STPD/STPI + EX decoder; it never extracts members to disk.

    The record layout is the same observed format documented by the archived
    Table audit. This implementation verifies the supplied carrier independently
    and uses explicit checks (including all stored-body MD5s), never assert.
    """
    def __init__(self, path, expected_sha, carrier_names):
        raw = path.read_bytes()
        self.sha256 = digest(raw)
        self.bytes = len(raw)
        self.carrier_names = set(carrier_names) | {path.name}
        require(self.sha256 == expected_sha, f'Carrier SHA-256 mismatch: {path.name}')
        require(len(raw) >= 16 and raw[:4] == b'STPD', f'STPD header: {path.name}')
        data = bytes(value ^ 255 for value in raw)
        index = struct.unpack_from('<I', data, 4)[0]
        table = struct.unpack_from('>I', data, 12)[0]
        require(16 <= table < index <= len(data) - 8, 'STP index/table bounds')
        require(raw[index:index + 4] == b'STPI', 'STPI header')
        count = struct.unpack_from('<I', data, table)[0]
        require(table + 4 + count * 32 == index, 'STP block table length')
        self.blocks, self.members, self.decoded = {}, {}, {}
        for i in range(count):
            rec = table + 4 + i * 32
            identity, size, first, last = struct.unpack_from('<4I', data, rec)
            require(last >= first and size <= (last - first + 1) * 1024, 'STP block span')
            start = 16 + first * 1024
            require(16 <= start and start + size <= table, 'STP body bounds')
            stored = data[start:start + size]
            md5 = data[rec + 16:rec + 32].hex()
            require(hashlib.md5(stored).hexdigest() == md5, f'STP stored MD5: {identity}')
            require(identity not in self.blocks, 'Duplicate STP block ID')
            self.blocks[identity] = dict(stored=stored, member_id=identity, stored_size=size,
                                        raw_body_offset=start, index_record_offset=rec,
                                        stored_md5=md5, stored_md5_verified=True)
        pos, directories = index + 8, []

        def node(parent='', depth=0):
            nonlocal pos
            require(depth < 64 and pos + 2 <= len(data), 'STP directory depth/bounds')
            length = struct.unpack_from('<H', data, pos)[0]
            pos += 2
            require(pos + length + 1 <= len(data), 'STP entry name bounds')
            name = data[pos:pos + length].decode('ascii', errors='strict').rstrip('\0')
            pos += length
            kind = data[pos]
            pos += 1
            member = '/'.join(filter(None, [parent, name]))
            require(not member or safe_member(member), 'Unsafe STP member name')
            if kind in (1, 2):
                require(pos + 12 <= len(data), 'STP directory record bounds')
                children = struct.unpack_from('<I', data, pos)[0]
                pos += 12
                require(children <= len(data) - pos, 'STP directory child count')
                directories.append(member)
                for _ in range(children):
                    node(member, depth + 1)
            elif kind == 0:
                require(pos + 16 <= len(data), 'STP file record bounds')
                _, identity = struct.unpack_from('<II', data, pos)
                pos += 16
                require(member and member not in self.members, 'Empty/duplicate STP member')
                self.members[member] = identity
            else:
                raise ValueError(f'Unknown STP entry kind: {kind}')

        node()
        require(pos == len(data), 'STP index did not end at EOF')
        require(len(self.members) == count and set(self.members.values()) == set(self.blocks),
                'STP directory/block table mismatch')
        self.metadata = dict(directory_index_offset=index, block_table_offset=table,
                             directory_count=len(directories), member_count=len(self.members),
                             block_count=count, all_stored_member_md5_verified=True,
                             index_parsed_to_eof=True)

    def read(self, member):
        require(member in self.members, f'Missing exact archive member: {member}')
        if member not in self.decoded:
            stored = self.blocks[self.members[member]]['stored']
            decoded = stored
            if stored[:2] == b'EX':
                require(len(stored) >= 16, 'Short EX header')
                mode = stored[2]
                compressed, expanded, offset = struct.unpack_from('<III', stored, 4)
                require(mode in (0, 1) and offset >= 16 and offset + compressed == len(stored),
                        'EX header/mode/body length')
                require(expanded < 50_000_000, 'EX decoded size outside bounded resource scope')
                payload = stored[offset:offset + compressed]
                if mode == 1:
                    key = [0x30, 0xe7]
                    for i in range(2, 1024):
                        key.append((key[i - 2] + key[i - 1] + 0x13
                                    - (0x56 if i == 0x17c else 0)) & 255)
                    payload = bytes(value ^ key[i % 1024] for i, value in enumerate(payload))
                decoder = zlib.decompressobj()
                decoded = decoder.decompress(payload, expanded + 1)
                require(decoder.eof and not decoder.unused_data and not decoder.unconsumed_tail,
                        'EX zlib incomplete/overlong stream')
                require(len(decoded) == expanded, 'EX expanded length mismatch')
            # Retain the raw digest before any XML decode or normalization.
            self.decoded[member] = (decoded, digest(decoded))
        return self.decoded[member][0]

    def member_sha(self, member):
        self.read(member)
        return self.decoded[member][1]


def check_source(src, source_map, raw, archives):
    """Keep original manifest declarations separate from actual archive reads."""
    path = src.get('package_path')
    if path is not None:
        require(path in source_map, f'Unknown package source: {path}')
        item = source_map[path]
        for key in ('sha256', 'source_commit', 'git_blob_sha1', 'repository_path', 'member'):
            require(src.get(key) == item.get(key), f'Source ref {key}: {path}')
        require(src.get('carrier_sha256_declared') == item.get('carrier_sha256_declared'),
                f'Changed manifest carrier declaration: {path}')
        require(src['evidence_basis'] in {'raw_member_literal', 'existing_report_not_raw_reverified',
                                        'package_scope', 'package_search_scope'}, 'Package evidence classification')
        if src['evidence_basis'] == 'existing_report_not_raw_reverified':
            require(path.startswith('git-evidence/'), 'Historical report attributed to raw archive')
        if src['evidence_basis'] == 'raw_member_literal':
            require(path.startswith('local-resources/'), 'Raw member literal attributed to historical report')
        body = raw[path]
        verified = src.get('carrier_sha256_verified')
        if verified:
            require(verified in archives, 'Unknown verified supplemental carrier')
            arc = archives[verified]
            require(src.get('carrier') in arc.carrier_names, 'Package ref supplemental carrier name')
            require(arc.member_sha(src['member']) == src['sha256'], 'Package ref direct-member mismatch')
    else:
        require(src['evidence_basis'] in {'raw_archive_member_literal', 'raw_archive_member_search'},
                'Archive source must explicitly identify its evidence class')
        require(all(src.get(k) is None for k in ('source_commit', 'git_blob_sha1', 'repository_path')),
                'Raw archive falsely attributed to Git')
        verified = src.get('carrier_sha256_verified')
        require(verified in archives, 'Archive source missing actual carrier SHA')
        arc = archives[verified]
        require(src.get('carrier') in arc.carrier_names, 'Wrong archive carrier name')
        member = src.get('member')
        if member is None:
            require(src['evidence_basis'] == 'raw_archive_member_search' and src['sha256'] == arc.sha256,
                    'Archive search source must identify its full carrier digest')
            require(src.get('line') is None, 'Archive index search has no XML line')
            body = None
        else:
            body = arc.read(member)
            require(src['sha256'] == arc.member_sha(member), f'Archive member SHA: {member}')
    if src.get('line') is not None:
        require(type(src['line']) is int and 0 < src['line'] <= len(body.splitlines()),
                f'Invalid source line: {path or src.get("member")}')


def literal_source(src, member, sha, line, selector, carrier_sha):
    require(src.get('package_path') is None and src.get('member') == member
            and src['sha256'] == sha and src.get('carrier_sha256_verified') == carrier_sha
            and src['evidence_basis'] == 'raw_archive_member_literal'
            and src.get('line') == line and src.get('selector') == selector,
            f'Raw archive row/source selector mismatch: {member}: {selector}')


def csv_source(row):
    """Select the primary ref by its flattened columns, not list position.

    A body/stem link carries both the actor-table ref and the ABF ref. Its
    primary columns describe the ABF, which is the second source in that list.
    The human-readable carrier!member label is never treated as a package path.
    """
    refs = json.loads(row['source_refs'])
    require(isinstance(refs, list) and refs, f'Missing link source_refs: {row["link_id"]}')
    mappings = {'source_sha256': 'sha256', 'source_commit': 'source_commit',
                'source_blob_sha1': 'git_blob_sha1', 'source_member': 'member',
                'carrier_sha256_declared': 'carrier_sha256_declared',
                'carrier': 'carrier', 'carrier_sha256_verified': 'carrier_sha256_verified',
                'selector': 'selector', 'evidence_basis': 'evidence_basis'}
    matches = []
    for src in refs:
        label = src.get('package_path')
        if label is None:
            label = src['carrier'] + ('!' + src['member'] if src.get('member') else '')
        if (row['source_path'] == label
                and row['line'] == (str(src['line']) if src.get('line') is not None else '')
                and all(row[column] == (src.get(key) or '') for column, key in mappings.items())):
            matches.append(src)
    require(len(matches) == 1, f'Link primary columns disagree with source_refs: {row["link_id"]}')
    return matches[0]


def source_address(src):
    return tuple(src.get(k) for k in ('package_path', 'carrier_sha256_verified',
                                     'member', 'sha256', 'selector', 'line'))


def raw_resource(aid, member, sha, row, selector, kind, file, folder='', relative='', slot=''):
    """One literal reference occurrence derived from an already verified ABF."""
    return dict(actor_id=str(aid), animation_slot=str(slot), kind=kind,
                file_literal=file, folder_literal=folder, relative_root_literal=relative,
                resource_reference=(folder or relative) + file,
                path_semantics=('FOLDER_PLUS_FILE_LITERAL' if folder else
                                'RELATIVEPATH_PLUS_FILE_ROOT_UNVERIFIED'),
                source_member=member, source_sha256=sha,
                source_carrier='Character/Mon/Base.stp', source_carrier_sha256=BASE_SHA,
                source_selector=selector, source_line=str(row['line']))


def verify_archive_registry(index, archives, out, source_map, raw):
    expected_members = {(TABLE_SHA, p.removeprefix('local-resources/')) for p in TABLES}
    expected_members.update((TABLE_SHA, p) for p in
                            (MATRIX_MEMBER, 'Table/Skill/Matrix/CharacterMatrices.xml'))
    expected_members.update((BASE_SHA, p) for p in BODY_MEMBERS.values())
    expected_reports = {TABLE_SHA: 'table-stp-presence-audit.json', BASE_SHA: 'base-stp-audit.json'}
    declared = index['uploaded_archive_sources']
    require(len(declared) == 2 and {r['sha256'] for r in declared} == set(archives),
            'Source index must list the two actual uploaded archives')
    audits = {}
    for item in declared:
        sha = item['sha256']
        arc = archives[sha]
        require(item['carrier'] in arc.carrier_names and item['bytes'] == arc.bytes
                and item['member_count'] == len(arc.members), 'Source-index carrier metadata mismatch')
        require(item['audit_report'] == expected_reports[sha], 'Wrong archive audit reference')
        audit = load_json(out / expected_reports[sha])
        require(audit['archive_sha256'] == sha and audit['archive_bytes'] == arc.bytes,
                'Audit carrier digest/size differs from actual input')
        meta = audit['archive_index'] if sha == BASE_SHA else audit
        for key, value in arc.metadata.items():
            require(meta[key] == value, f'Archive audit metadata {key}: {item["carrier"]}')
        require(meta['all_member_names'] == sorted(arc.members), 'Archive audit member-name coverage')
        audits[sha] = audit

    members = index['direct_archive_members']
    indexed = {(r['carrier_sha256'], r['member']): r for r in members}
    require(len(indexed) == len(members) == 10 and set(indexed) == expected_members,
            'Source index must cover exactly the ten directly read members')
    for (sha, member), item in indexed.items():
        arc = archives[sha]
        data = arc.read(member)
        require(item['carrier'] in arc.carrier_names and item['sha256'] == arc.member_sha(member)
                and item['bytes'] == len(data) and item['source_audit'] == expected_reports[sha],
                f'Direct archive source-index record: {member}')
        targets = [r for r in audits[sha]['targets'] if r['member'] == member]
        require(len(targets) == 1, f'Audit target missing or duplicated: {member}')
        target = targets[0]
        require(target['decoded_sha256' if sha == BASE_SHA else 'sha256'] == item['sha256']
                and target['decoded_size'] == len(data), f'Audit decoded member bytes: {member}')
        block = arc.blocks[arc.members[member]]
        for key in ('member_id', 'stored_size', 'raw_body_offset', 'index_record_offset',
                    'stored_md5', 'stored_md5_verified'):
            require(target[key] == block[key], f'Audit stored block metadata {key}: {member}')
        root, _, _ = xml_records(data)
        if sha == TABLE_SHA:
            require(target['xml_root'] == root.tag
                    and target['element_counts'] == dict(Counter(n.tag for n in root.iter())),
                    f'Audit decoded XML structure: {member}')

    updated = {p for p, item in source_map.items() if 'original_archive_reverification' in item}
    require(updated == set(TABLES), 'Direct re-verification scope must be the five inspected ZIP tables')
    for path in TABLES:
        item = source_map[path]['original_archive_reverification']
        require(item['carrier_sha256'] == TABLE_SHA and item['carrier'] in archives[TABLE_SHA].carrier_names
                and item['decoded_sha256'] == digest(raw[path])
                and item['decoded_bytes_equal_package_member'] is True
                and item['audit_report'] == expected_reports[TABLE_SHA]
                and archives[TABLE_SHA].read(source_map[path]['member']) == raw[path],
                f'Original-table re-verification declaration: {path}')
    return audits


def verify_resources(out, expected, profile_links, links, requirements, source_map, raw, archives):
    rows = load_csv(out / 'resource-references.csv')
    require(len(rows) == len({r['reference_id'] for r in rows}) == len(expected),
            'Resource occurrence count/ID uniqueness')
    expected_by_source = {(r['source_member'], r['source_selector']): r for r in expected}
    actual_by_source = {(r['source_member'], r['source_selector']): r for r in rows}
    require(len(expected_by_source) == len(actual_by_source) == len(rows)
            and set(expected_by_source) == set(actual_by_source), 'Resource source occurrence coverage')
    groups = defaultdict(list)
    refs_checked = 0
    for key, row in actual_by_source.items():
        observed = expected_by_source[key]
        require(all(row[k] == value for k, value in observed.items()), f'Changed raw resource literal/source: {key}')
        require(all(not row[k] for k in ('referenced_carrier', 'referenced_member', 'referenced_member_sha256'))
                and row['availability'] == 'NOT_RESOLVED_IN_UPLOADED_ARCHIVES'
                and row['purpose'] == 'PRESENTATION_ONLY_NO_SERVER_POLICY_INFERENCE',
                f'Unproven resource acquisition or Server policy promotion: {key}')
        # Scope is these two exact indices, including suffix paths for the
        # relative references; this does not assert absence from other carriers.
        literal = row['resource_reference']
        require(all(not any(p == literal or p.endswith('/' + literal) for p in arc.members)
                    for arc in archives.values()), f'Referenced resource is actually present: {literal}')
        refs = json.loads(row['source_refs'])
        require(isinstance(refs, list) and len(refs) == 1, 'Resource occurrence must have one exact ABF source')
        src = refs[0]
        check_source(src, source_map, raw, archives)
        literal_source(src, row['source_member'], row['source_sha256'], int(row['source_line']),
                       row['source_selector'], BASE_SHA)
        require(row['link_id'] == profile_links[int(row['actor_id']), row['source_selector']],
                f'Resource/profile link mismatch: {key}')
        require(row['link_id'] in links and source_address(csv_source(links[row['link_id']])) == source_address(src),
                f'Resource/link source mismatch: {key}')
        groups[row['kind'], literal].append(row)
        refs_checked += 1

    optional_kind = {'exact_folder_file_reference': 'effect',
                     'exact_relative_animation_reference': 'animation_clip'}
    expected_optional = {key for key in groups if key[0] in {'effect', 'animation_clip'}}
    optional = [r for r in requirements.values() if r['bundle_phase'] == 'OPTIONAL_PRESENTATION']
    optional_by_key = {}
    body_requests = {1001: 'W2-M02', 1009: 'W2-M03', 1004: 'W2-M04'}
    for row in optional:
        require(row['requirement_kind'] in optional_kind, 'Unknown optional resource kind')
        key = (optional_kind[row['requirement_kind']], row['resource_reference'])
        require(key in expected_optional and key not in optional_by_key, 'Extra/duplicate optional resource request')
        optional_by_key[key] = row
        occurrences = groups[key]
        require(row['priority'] == 'P2' and row['actor_category'] == '1'
                and row['actor_pres'] == 'PRE_APPLICABILITY_NOT_PROVEN'
                and row['availability'] == 'NOT_IN_UPLOADED_ARCHIVES'
                and row['server_policy_design_blocked'] == 'false', 'Optional resource priority/scope changed')
        require(all(not row[k] for k in ('carrier', 'carrier_sha256', 'member', 'member_sha256', 'stem')),
                'Optional literal incorrectly promoted to an exact carrier/member')
        require(set(row['actor_ids'].split(';')) == {r['actor_id'] for r in occurrences},
                'Optional resource actor coverage')
        require(set(row['prerequisite'].split(';')) == {body_requests[int(r['actor_id'])] for r in occurrences},
                'Optional resource body prerequisites')
        require({row['relative_root']} == {r['relative_root_literal'] for r in occurrences},
                'Optional resource relative-root literal')
        refs = json.loads(row['source_refs'])
        wanted = Counter((None, BASE_SHA, r['source_member'], r['source_sha256'],
                          r['source_selector'], int(r['source_line'])) for r in occurrences)
        require(Counter(source_address(src) for src in refs) == wanted,
                f'Optional request source occurrences incomplete: {row["request_id"]}')
    require(set(optional_by_key) == expected_optional and len(optional) == 36,
            'Optional requests must be exactly the six effects and thirty animation clips')
    require(set(requirements) == {f'W2-M{i:02}' for i in range(1, 8)}
            | {r['request_id'] for r in optional}, 'Unexpected non-resource requirement')
    for row in rows:
        request = optional_by_key.get((row['kind'], row['resource_reference']))
        rid = request['request_id'] if request else ''
        require(row['required_member_id'] == rid and links[row['link_id']]['required_member_ids'] == rid,
                f'Resource/optional request linkage: {row["reference_id"]}')
    return dict(occurrences=len(rows), distinct=len(groups), source_refs_checked=refs_checked,
                by_kind=dict(Counter(r['kind'] for r in rows)),
                distinct_by_kind=dict(Counter(k[0] for k in groups)),
                optional_requests=len(optional))


def typed_link(index, lid, aid, source, from_domain, from_key, relationship, to_domain, to_key,
               status='KNOWN_SOURCE_VALUE', pre=None):
    require(lid in index, f'Dangling typed link: {lid}')
    row = index[lid]
    require((row['from_domain'], row['relationship'], row['to_domain'], row['status'])
            == (from_domain, relationship, to_domain, status), f'Typed relationship/status: {lid}')
    require(json.loads(row['from_key']) == from_key and json.loads(row['to_key']) == to_key,
            f'Typed link value: {lid}')
    require(row['actor_id'] == (str(aid) if aid is not None else '')
            and row['actor_category'] == ('1' if aid is not None else '')
            and row['actor_pre'] == (str(pre) if pre is not None else ''), f'Typed link actor domain: {lid}')
    require(source_address(csv_source(row)) == source_address(source), f'Typed link primary source: {lid}')
    return lid


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--input', type=Path, required=True, help='Original uploaded input ZIP (or its extracted root)')
    ap.add_argument('--table-archive', type=Path, required=True, help='Pinned original KR Table.stp')
    ap.add_argument('--base-archive', type=Path, required=True, help='User-supplied Character/Mon/Base.stp')
    ap.add_argument('--output', type=Path, default=Path(__file__).resolve().parent,
                    help='W2 deliverable directory to verify')
    ap.add_argument('--git-repo', type=Path, help='Optional existing repo for source commit tree verification')
    ap.add_argument('--report', type=Path, help='Optional output JSON report; never overwrites any input')
    args = ap.parse_args()
    package, out = args.input.resolve(), args.output.resolve()
    if args.report:
        dest = args.report.resolve()
        require(dest not in {package, args.table_archive.resolve(), args.base_archive.resolve(),
                             Path(__file__).resolve()}, 'Report may not overwrite an input or verifier')
        require(not package.is_dir() or not dest.is_relative_to(package), 'Report may not overwrite input package')
    manifest_raw, manifest, expected, raw, zip_sha = read_package(package)
    table = STPArchive(args.table_archive.resolve(), TABLE_SHA, {'Table.stp', '07-Table.stp'})
    base = STPArchive(args.base_archive.resolve(), BASE_SHA, {'Character/Mon/Base.stp', 'Base.stp'})
    archives = {TABLE_SHA: table, BASE_SHA: base}
    require(table.metadata['member_count'] == 1026, 'Pinned Table member count')

    source_index = load_json(out / 'source-index.json')
    source_entries = [r for r in source_index['sources'] if r.get('package_path') is not None]
    source_map = {r['package_path']: r for r in source_entries}
    require(len(source_entries) == len(source_map) == len(source_index['sources'])
            and set(source_map) == set(expected),
            'Source index is not the exact original input manifest set')
    require(source_index['input_manifest_sha256'] == digest(manifest_raw), 'Manifest digest mismatch')
    require(source_index['input_zip_sha256'] == ZIP_SHA, 'Source index input ZIP pin')
    require(source_index['source_analysis_commit'] == manifest['source_analysis_commit'], 'Source index commit')
    for path, item in source_map.items():
        require(item['sha256'] == digest(raw[path]) and item['bytes'] == len(raw[path]), f'Source index bytes: {path}')
        require(item['original_member_sha_match_declared'] == expected[path].get('original_member_sha_match'),
                f'Original-member snapshot classification changed: {path}')
        require(item['carrier_sha256_declared'] == expected[path].get('carrier_sha256'), f'Carrier declaration: {path}')
        if path.startswith('git-evidence/'):
            require(item['git_blob_sha1'] == blob(raw[path]), f'Git blob mismatch: {path}')
            require(item['source_commit'] == manifest['source_analysis_commit'], f'Git source commit: {path}')
        else:
            require(item['source_commit'] is None and item['git_blob_sha1'] is None, f'Raw resource falsely attributed to Git: {path}')
    audits = verify_archive_registry(source_index, archives, out, source_map, raw)
    git_checks = 0
    if args.git_repo:
        tree_bytes = subprocess.run(['git', '-C', str(args.git_repo.resolve()), 'ls-tree', '-rz',
                                     manifest['source_analysis_commit']], check=True, capture_output=True).stdout
        tree = {}
        for entry in tree_bytes.split(b'\0'):
            if entry:
                meta, path = entry.split(b'\t', 1)
                tree[path.decode()] = meta.split()[2].decode()
        for path, item in source_map.items():
            if path.startswith('git-evidence/'):
                require(tree.get(item['repository_path']) == blob(raw[path]), f'Commit tree mismatch: {path}')
                git_checks += 1
        require(git_checks == 110, 'Expected110 Git evidence copies')

    doc = load_json(out / 'monster-profiles.json')
    schema = load_json(out / 'monster-profile.schema.json')
    Draft202012Validator.check_schema(schema)
    validator = Draft202012Validator(schema)
    validator.validate(doc)
    require(doc['format'] == 'W2_MONSTER_PROFILE_INVENTORY_V2' and doc['schema_version'] == '2.0.0',
            'This verifier requires the reviewed V2 archive-backed inventory')
    require(doc['technical_scope'] == 'UPLOADED_PACKAGE_AND_PINNED_TABLE_BASE_ARCHIVES', 'V2 source scope')
    require(doc['source_archives'] == source_index['uploaded_archive_sources'], 'Profile/source-index archive descriptors')
    require(doc['input_manifest_sha256'] == digest(manifest_raw), 'Profiles input manifest SHA')
    require(doc['source_analysis_commit'] == manifest['source_analysis_commit'], 'Profiles source commit')
    profiles = {p['actor_key']['actor_id']: p for p in doc['profiles']}
    require(len(doc['profiles']) == 3 and set(profiles) == set(TARGETS), 'Missing or duplicated target actor')

    # Recheck all five XML bodies against the actual original Table archive.
    for path in TABLES:
        require(table.read(path.removeprefix('local-resources/')) == raw[path], f'ZIP/original Table bytes: {path}')
    parsed = {p: xml_records(raw[p]) for p in TABLES}
    actors = {}
    for rec in parsed[TABLES[0]][1]:
        if rec['tag'] == 'ACTOR':
            key = (int(rec['ancestors'][-1]['attrs']['ID']), int(rec['attrs']['ID']), int(rec['attrs']['PRE']))
            require(key not in actors, f'Duplicate category/ActorID/PRE: {key}')
            actors[key] = rec
    require(len(actors) == 5361, 'Actor table row count')
    require((0, 1, 1) in actors and (3, 1, 1) in actors, 'Naked ActorID/PRE namespace counterexample disappeared')
    variants = 0
    for aid, profile in profiles.items():
        expected_keys = {k for k in actors if k[:2] == (1, aid)}
        emitted_keys = {(v['key']['category'], v['key']['actor_id'], v['key']['pre']) for v in profile['variants']}
        require(expected_keys == emitted_keys and len(emitted_keys) == len(profile['variants']), f'Variant coverage: {aid}')
        for v in profile['variants']:
            key = (v['key']['category'], v['key']['actor_id'], v['key']['pre'])
            row = actors[key]
            require(v['raw_attributes'] == row['attrs'], f'Changed or defaulted raw actor field: {key}')
            require(v['source']['line'] == row['line'], f'Actor row line: {key}')
            require(v['source']['selector'] == f"/ACTORLIST/OBJCATEGORY[@ID='1']/ACTOR[@ID='{aid}'][@PRE='{key[2]}']", f'Actor selector: {key}')
            require(profile['file_stem'] == row['attrs']['FILE'], f'FILE stem: {key}')
            require(v['absent_attributes'] == ([] if 'SCALE' in row['attrs'] else ['SCALE']), f'Absent SCALE: {key}')
            variants += 1
        require(set(profile['ai_fields']) == AI_FIELDS, f'AI field coverage: {aid}')
        for field in profile['ai_fields'].values():
            require(field['source_status'] == '無來源' and field['value'] is None and field['unit'] is None,
                    f'Unsupported AI value on actor {aid}')
        require(profile['runtime_ready'] is False, f'Unproven runtime promotion: {aid}')
    require(variants == 12, 'Expected12 target variants')
    require(actors[1, 1001, 7]['attrs']['NAMECOLOR'] == '#FFOO2C', 'Raw letter-O NAMECOLOR silently repaired')

    char_ids = {int(x.get('ID')) for x in parsed[TABLES[1]][0]}
    skill_nos = {int(x.get('no')) for x in parsed[TABLES[2]][0]}
    effects = {int(x.get('Index')): x.get('File') for x in parsed[TABLES[4]][0]}
    require(char_ids == set(range(1, 10)), 'CharSkill domain changed')
    require(not char_ids.intersection(TARGETS), 'A target CharSkill row now exists; re-analyze')
    require(not skill_nos.intersection({76, 307, 371, *TARGETS}), 'Old reported SkillActive numeric counterexample changed')
    require(not set(effects).intersection({76, 307, 371, *TARGETS}), 'Old reported effect numeric counterexample changed')
    require(len(skill_nos) == 469 and len(effects) == 92 and sum(bool(x) for x in effects.values()) == 55,
            'Skill/effect inventory counts')
    matrix_imports = [x.get('File') for x in parsed[TABLES[3]][0]]
    require({x['member'] for x in doc['matrix_imports']} == set(matrix_imports), 'Matrix import literals differ')
    for item in doc['matrix_imports']:
        member = item['member']
        require('local-resources/' + member not in expected and item['present_in_package'] is False,
                f'Original ZIP presence incorrectly rewritten: {member}')
        require(item['present_in_uploaded_archive'] is True and item['member_sha256'] == table.member_sha(member),
                f'Original Table matrix acquisition: {member}')
        require(item['carrier_sha256_verified'] == TABLE_SHA and item['carrier'] in table.carrier_names,
                f'Matrix actual carrier: {member}')
        require(item['member_source']['member'] == member
                and item['member_source']['sha256'] == table.member_sha(member), f'Matrix member source: {member}')

    matrix_raw = table.read(MATRIX_MEMBER)
    matrix_sha = table.member_sha(MATRIX_MEMBER)
    matrix_records = xml_records(matrix_raw)[1]
    matrix_rows = {}
    for row in matrix_records:
        if row['tag'] != 'Key' or len(row['ancestors']) < 4:
            continue
        lineage = {r['tag']: r['attrs'] for r in row['ancestors']}
        aid = int(lineage['SkillMatrix']['CharID'])
        if aid in TARGETS:
            key = (aid, int(lineage['Matrix']['ID']), int(lineage['Tier']['tier']), int(row['attrs']['key']))
            require(key not in matrix_rows, f'Duplicate raw matrix coordinate: {key}')
            matrix_rows[key] = row
    require(len(matrix_rows) == 11, 'Expected11 raw target matrix cells')
    emitted_matrix = set()
    for aid, profile in profiles.items():
        for cell in profile['matrix_cells']:
            key = (aid, cell['matrix_variant'], cell['matrix_tier'], cell['matrix_key'])
            require(key in matrix_rows and key not in emitted_matrix, f'Extra/duplicate matrix coordinate: {key}')
            emitted_matrix.add(key)
            row = matrix_rows[key]
            word = int(row['attrs']['skill'])
            selector = (f"/MatrixList/SkillMatrix[@CharID='{aid}']/Matrix[@ID='{key[1]}']"
                        f"/Tier[@tier='{key[2]}']/Key[@key='{key[3]}']/@skill")
            require(cell['skill_word'] == word and cell['actor_pre'] is None
                    and cell['raw_matrix_sha256'] == matrix_sha, f'Raw matrix value/PRE/hash: {key}')
            require(cell['evidence_kind'] == 'raw_archive_member_literal', f'Raw matrix evidence class: {key}')
            require(cell['skillactive_no_present_in_supplied_member'] is (word in skill_nos),
                    f'Matrix WORD/SkillActive numeric lookup: {key}')
            require(cell['effect_index_present_in_supplied_member'] is (word in effects),
                    f'Matrix WORD/effect Index numeric lookup: {key}')
            require(cell['skill_action_effect_binding'] == 'UNKNOWN', f'Unsupported cross-domain matrix join: {key}')
            literal_source(cell['source'], MATRIX_MEMBER, matrix_sha, row['line'], selector, TABLE_SHA)
        require(sum(k[0] == aid for k in emitted_matrix) == sum(k[0] == aid for k in matrix_rows),
                f'Incomplete matrix coverage: {aid}')
    require(emitted_matrix == set(matrix_rows), 'Incomplete raw matrix coverage')
    words = {int(row['attrs']['skill']) for row in matrix_rows.values()}
    require(not words.intersection(skill_nos), 'New SkillActive numeric hit requires re-analysis')
    require(words.intersection(effects) == {92, 93} and effects[92] == ''
            and effects[93] == 'B_Self-BasisDestructionTrap01.eff', 'Effect92/93 collision counterexample changed')

    animation_count, effect_count, sound_count = 0, 0, 0
    expected_optional_refs = {'effects': set(), 'clips': set()}
    expected_resources, profile_resource_links = [], {}
    raw_animations = {}
    for aid, profile in profiles.items():
        member = BODY_MEMBERS[aid]
        body = base.read(member)
        body_sha = base.member_sha(member)
        require(body_sha == BODY_SHAS[aid], f'Pinned target body SHA: {aid}')
        require(profile['body_carrier'] == 'Character/Mon/Base.stp'
                and profile['body_carrier_sha256'] == BASE_SHA
                and profile['body_member'] == member and profile['body_extension'] == '.abf'
                and profile['body_member_sha256'] == body_sha
                and profile['body_resolution'] == 'EXACT_MEMBER_RAW_VERIFIED', f'Exact body resolution: {aid}')
        require(PurePosixPath(member).stem == profile['file_stem'], f'Actor stem/exact body mismatch: {aid}')
        require([p for p in base.members if PurePosixPath(p).stem == profile['file_stem']] == [member],
                f'Body stem is not a unique exact member match: {aid}')
        body_root, body_records, _ = xml_records(body)
        characters = [r for r in body_records if r['tag'] == 'Character']
        require(body_root.tag == 'CharacterList' and len(characters) == 1, f'Body Character root: {aid}')
        character = characters[0]
        require(profile['body_character_attributes'] == character['attrs'], f'Changed raw Character attributes: {aid}')
        literal_source(profile['body_source'], member, body_sha, character['line'],
                       '/CharacterList/Character', BASE_SHA)
        relative = character['attrs']['RelativePath']
        other_rows = [raw_resource(aid, member, body_sha, character,
                                   '/CharacterList/Character/@BaseFile', 'base_model',
                                   character['attrs']['BaseFile'], relative=relative)]
        textures = [r for r in body_records if r['tag'] == 'Texture']
        for number, row in enumerate(textures, 1):
            require(row['ancestors'][-1]['tag'] == 'TextureList', 'Unexpected Texture parent')
            selector = f'/CharacterList/Character/TextureList/Texture[{number}]/@File'
            other_rows.append(raw_resource(aid, member, body_sha, row, selector, 'texture',
                                           row['attrs']['File'], relative=relative))
        expected_other = {(r['kind'], r['source_selector']): r for r in other_rows}
        emitted_other = set()
        for reference in profile['other_resource_refs']:
            key = (reference['kind'], reference['source']['selector'])
            require(key in expected_other and key not in emitted_other, f'Extra/duplicate body reference: {aid}')
            emitted_other.add(key)
            row = expected_other[key]
            require(reference['resource_reference'] == row['resource_reference'], f'Body resource literal: {aid}/{key}')
            literal_source(reference['source'], member, body_sha, int(row['source_line']),
                           row['source_selector'], BASE_SHA)
            profile_resource_links[aid, row['source_selector']] = reference['link_id']
        require(emitted_other == set(expected_other), f'Incomplete BaseFile/Texture references: {aid}')
        expected_resources.extend(other_rows)
        require(all(r['tag'] in {'Texture', 'Animation', 'Effect', 'Sound'}
                    for r in body_records if 'File' in r['attrs']), 'Uninventoried ABF File reference')
        animation_rows = {int(r['attrs']['ID']): r for r in body_records if r['tag'] == 'Animation'}
        require(len(animation_rows) == len([r for r in body_records if r['tag'] == 'Animation']), 'Duplicate animation slot')
        require(len(animation_rows) == (15 if aid == 1001 else 16), f'Animation count: {aid}')
        emitted_slots = set()
        for animation in profile['animations']:
            slot = animation['slot']
            require(slot in animation_rows and slot not in emitted_slots, f'Extra/duplicate animation slot: {aid}/{slot}')
            emitted_slots.add(slot)
            row = animation_rows[slot]
            attrs = row['attrs']
            raw_animations[aid, slot] = attrs
            selector = f"/CharacterList/Character/AnimationList/Animation[@ID='{slot}']"
            require(animation['name'] == attrs['File'] and animation['raw_attributes'] == attrs,
                    f'Changed animation File/attributes: {aid}/{slot}')
            require(animation['relative_clip_reference'] == relative + attrs['File'],
                    f'Changed relative animation reference: {aid}/{slot}')
            require(animation['frame_speed_raw'] == attrs['FrameSpeed'], f'FrameSpeed literal: {aid}/{slot}')
            require(all(animation[k] is None for k in ('actor_pre', 'frame_speed_unit', 'frames', 'fps',
                                                       'presentation_duration_ms', 'server_ai_duration_ms')),
                    f'Inferred PRE/frame/AI timing: {aid}/{slot}')
            require(animation['raw_body_sha256'] == body_sha
                    and animation['evidence_kind'] == 'raw_archive_member_literal', f'Animation evidence source: {aid}/{slot}')
            literal_source(animation['source'], member, body_sha, row['line'], selector, BASE_SHA)
            expected_optional_refs['clips'].add(relative + attrs['File'])
            expected_resources.append(raw_resource(aid, member, body_sha, row, selector,
                                                   'animation_clip', attrs['File'], relative=relative, slot=slot))
            profile_resource_links[aid, selector] = animation['link_id']
            for field, tag in [('effects', 'Effect'), ('sounds', 'Sound')]:
                child_rows = [r for r in body_records if r['tag'] == tag
                              and r['ancestors'][-1]['tag'] == 'Animation'
                              and r['ancestors'][-1]['attrs']['ID'] == str(slot)]
                children = animation[field]
                require(len(children) == len(child_rows), f'Missing/extra {tag} children: {aid}/{slot}')
                for number, (child, raw_child) in enumerate(zip(children, child_rows), 1):
                    require(child['raw_attributes'] == raw_child['attrs'], f'Changed {tag} attributes: {aid}/{slot}')
                    child_selector = selector + f'/{tag}[{number}]'
                    literal_source(child['source'], member, body_sha, raw_child['line'], child_selector, BASE_SHA)
                    resource = raw_child['attrs']['Folder'] + raw_child['attrs']['File']
                    require(child['resource_path'] == resource and child['timing'] is None
                            and child['timing_unit'] is None and child['referenced_member_verified'] is False,
                            f'Inferred {tag} resource acquisition/timing: {aid}/{slot}')
                    expected_resources.append(raw_resource(aid, member, body_sha, raw_child, child_selector,
                                                           tag.lower(), raw_child['attrs']['File'],
                                                           folder=raw_child['attrs']['Folder'], slot=slot))
                    profile_resource_links[aid, child_selector] = child['link_id']
                    if tag == 'Effect':
                        expected_optional_refs['effects'].add(resource)
                if tag == 'Effect':
                    effect_count += len(children)
                else:
                    sound_count += len(children)
            animation_count += 1
        require(emitted_slots == set(animation_rows), f'Incomplete animation slots: {aid}')
    require((animation_count, effect_count, sound_count) == (47, 8, 9), 'Raw animation/Effect/Sound coverage')
    require(len(expected_optional_refs['effects']) == 6 and len(expected_optional_refs['clips']) == 30,
            'Unique presentation reference inventory')
    require(len(expected_resources) == len(profile_resource_links) == 70
            and len({r['resource_reference'] for r in expected_resources}) == 50,
            'Complete raw resource reference occurrence/unique count')

    # These arrays are immutable historical report snapshots. Their null raw
    # fields describe that evidence class, not the current archive availability.
    report_lines = raw[GENERAL].decode('utf-8-sig').splitlines()
    require('1001：tier 0 的 key 1／2／3 → 76／307／371' in report_lines[41], 'Reported skill source text changed')
    require([(c['matrix_tier'], c['matrix_key'], c['skill_word']) for c in profiles[1001]['reported_matrix_cells']]
            == [(0, 1, 76), (0, 2, 307), (0, 3, 371)], 'Historical matrix cells differ')
    require(all(not profiles[aid]['reported_matrix_cells'] for aid in [1009, 1004]), 'Invented historical skill cells')
    require([(a['slot'], a['name']) for a in profiles[1001]['reported_animation_refs']] == [(4, 'HokyPoky_MOVE01')], '1001 historical animation')
    require([(a['slot'], a['name']) for a in profiles[1004]['reported_animation_refs']]
            == [(4, 'Nepenths_WAIT01'), (6, 'Nepenths_WAIT01')], '1004 historical animation')
    require(not profiles[1009]['reported_animation_refs'], 'Invented1009 historical animation')
    for aid, profile in profiles.items():
        for cell in profile['reported_matrix_cells']:
            require(cell['matrix_variant'] is None and cell['actor_pre'] is None
                    and cell['raw_matrix_sha256'] is None
                    and cell['evidence_kind'] == 'existing_report_not_raw_reverified', 'Historical matrix scope rewritten')
        for animation in profile['reported_animation_refs']:
            require(animation['raw_body_sha256'] is None and animation['actor_pre'] is None
                    and animation['evidence_kind'] == 'existing_report_not_raw_reverified', 'Historical animation scope rewritten')
            require(animation['name'] == PurePosixPath(raw_animations[aid, animation['slot']]['File']).stem,
                    'Historical animation disagrees with acquired raw member')

    inv = load_json(out / 'table-inventory.json')
    require(len(inv['table_inventory']) == 5
            and {r['source_path'] for r in inv['table_inventory']} == set(TABLES), 'Five-table inventory coverage')
    for item in inv['table_inventory']:
        root = parsed[item['source_path']][0]
        counts, attributes = Counter(), defaultdict(set)
        for node in root.iter():
            counts[node.tag] += 1
            attributes[node.tag].update(node.attrib)
        require(dict(counts) == item['element_counts'], f'Table inventory counts: {item["source_path"]}')
        require({k: sorted(v) for k, v in attributes.items()} == item['attributes_by_tag'], 'Table attribute inventory')
    cluster_rows = {}
    for path in expected:
        if path.startswith('local-resources/Field/Cluster/'):
            _, rows, _ = xml_records(raw[path])
            for row in rows:
                if row['tag'] == 'OBJECT' and int(row['attrs']['ID']) in TARGETS:
                    cluster_rows[path, row['line']] = row['attrs']
    require(len(cluster_rows) == 55 and len(inv['cluster_target_mentions']) == 55, 'Cluster occurrence count')
    emitted_cluster_rows = {(r['source_path'], r['line']): r['raw_attributes'] for r in inv['cluster_target_mentions']}
    require(cluster_rows == emitted_cluster_rows, 'Cluster source occurrence coverage/raw fields')
    for aid, profile in profiles.items():
        seen = {int(attrs['PRE']) for attrs in cluster_rows.values() if int(attrs['ID']) == aid}
        require(sorted(seen) == profile['cluster_pre_literals'], f'Cluster PRE coverage: {aid}')

    links = load_csv(out / 'monster-skill-links.csv')
    link_index = {r['link_id']: r for r in links}
    require(len(links) == len(link_index) and {f'W2-L{i:03}' for i in range(1, 39)} <= set(link_index),
            'Link uniqueness/original38 IDs')
    required = load_csv(out / 'required-members.csv')
    req_index = {r['request_id']: r for r in required}
    require(len(required) == len(req_index) and {f'W2-M{i:02}' for i in range(1, 8)} <= set(req_index),
            'Requirement uniqueness/original IDs')
    link_ref_count = 0
    for row in links:
        csv_source(row)
        for src in json.loads(row['source_refs']):
            check_source(src, source_map, raw, archives)
            link_ref_count += 1
        require(set(filter(None, row['required_member_ids'].split(';'))) <= set(req_index), 'Dangling required member ID')
        for key in ['from_key', 'to_key']:
            json.loads(row[key])
    verified_links = set()
    for item in doc['matrix_imports']:
        lid = 'W2-L001' if item['required_member_id'] == 'W2-M06' else 'W2-L002'
        verified_links.add(typed_link(link_index, lid, None, item['source'],
                          'MatrixImportCatalog', 'Table/Skill/SkillMatrix.xml',
                          'imports', 'ResourceMember', item['member']))
    for profile in profiles.values():
        aid = profile['actor_key']['actor_id']
        for lid in profile['link_ids']:
            require(lid in link_index and link_index[lid]['actor_id'] == str(aid), 'Wrong-actor/dangling profile link')
        require(len(profile['link_ids']) == len(set(profile['link_ids'])), 'Duplicate profile link')
        require(set(profile['required_member_ids']) <= set(req_index), 'Dangling profile member request')
        require(set(profile['open_requirement_ids']) == {'W2-M05', 'W2-M07'}, 'Profile unresolved source roles')
        for field in profile['ai_fields'].values():
            require(set(field['related_report_link_ids']) <= set(profile['link_ids']), 'Wrong field report hint')
            require(set(field.get('related_source_link_ids', [])) <= set(profile['link_ids']), 'Wrong field raw-source hint')
            require(all(link_index[x]['evidence_basis'] == 'existing_report_not_raw_reverified'
                        for x in field['related_report_link_ids']), 'Raw evidence mislabeled as historical report')
        for variant in profile['variants']:
            vkey = variant['key']
            verified_links.add(typed_link(link_index, variant['file_link_id'], aid, variant['source'],
                               'ActorResourceKey', {k: vkey[k] for k in ('category', 'actor_id', 'pre')},
                               'FILE', 'ResourceFileStem', profile['file_stem'], pre=vkey['pre']))
        verified_links.add(typed_link(link_index, profile['body_link_id'], aid, profile['body_source'],
                           'ResourceFileStem', profile['file_stem'], 'exact_stem_unique_member_match',
                           'ArchiveMember', {'carrier': profile['body_carrier'], 'member': profile['body_member']}))
        require(profile['body_link_id'] in profile['link_ids'], 'Unlisted body/profile link')
        body_sources = json.loads(link_index[profile['body_link_id']]['source_refs'])
        require(len(body_sources) == 2 and source_address(profile['body_source']) in
                {source_address(s) for s in body_sources}
                and any(source_address(s) in {source_address(v['source']) for v in profile['variants']}
                        for s in body_sources), 'Body binding must cite both actor FILE and exact member')
        for cell in profile['matrix_cells']:
            verified_links.add(typed_link(link_index, cell['link_id'], aid, cell['source'],
                               'MonsterMatrixCell', {'char_id': aid, 'matrix_id': cell['matrix_variant'],
                               'tier': cell['matrix_tier'], 'key': cell['matrix_key']},
                               'skill_word_literal', 'MonsterSkillWord', cell['skill_word']))
        for cell in profile['reported_matrix_cells']:
            verified_links.add(typed_link(link_index, cell['link_id'], aid, cell['source'],
                               'ReportedMonsterMatrixCell', {'actor_id': aid, 'variant': None,
                               'tier': cell['matrix_tier'], 'key': cell['matrix_key']},
                               'reports_skill_word', 'MatrixSkillWord', cell['skill_word'],
                               status='HISTORICAL_REPORTED_VALUE'))
        for animation in profile['reported_animation_refs']:
            verified_links.add(typed_link(link_index, animation['link_id'], aid, animation['source'],
                               'ReportedAnimationSlot', animation['slot'], 'reports_animation_name',
                               'AnimationName', animation['name'], status='HISTORICAL_REPORTED_VALUE'))
        relative = profile['body_character_attributes']['RelativePath']
        for reference in profile['other_resource_refs']:
            verified_links.add(typed_link(link_index, reference['link_id'], aid, reference['source'],
                               'ActorBodyCharacter', {'body_member': profile['body_member']},
                               reference['kind'] + '_reference', 'RelativeResourceReference',
                               {'relative_path': relative, 'file': reference['resource_reference'].removeprefix(relative)}))
            require(reference['link_id'] in profile['link_ids'], 'Unlisted body resource link')
        for animation in profile['animations']:
            from_key = {'body_member': profile['body_member'], 'animation_id': animation['slot']}
            verified_links.add(typed_link(link_index, animation['link_id'], aid, animation['source'],
                               'BodyAnimationKey', from_key, 'animation_file_literal',
                               'AnimationClipRelativeReference', {'relative_path': relative, 'file': animation['name']}))
            for kind in ('effects', 'sounds'):
                for child in animation[kind]:
                    tag = kind[:-1]
                    verified_links.add(typed_link(link_index, child['link_id'], aid, child['source'],
                                       'BodyAnimationKey', from_key, tag + '_file_literal',
                                       tag.capitalize() + 'ResourcePath', child['resource_path']))
                    require(child['link_id'] in profile['link_ids'], 'Unlisted animation child link')
        for row in [*profile['matrix_cells'], *profile['animations']]:
            require(row['link_id'] in profile['link_ids'], 'Dangling raw row link')
            linked = link_index[row['link_id']]
            require(linked['source_sha256'] == row['source']['sha256']
                    and linked['source_member'] == row['source']['member']
                    and linked['selector'] == row['source']['selector'], 'Raw row/link source disagreement')
    unresolved_types = {('ActorResourceKey', 'PRE_to_matrix_variant_or_tier_unresolved', 'MonsterMatrixKey'),
                        ('MonsterSkillBinding', 'skill_to_action_unresolved', 'AnimationSlot'),
                        ('AnimationSlot', 'animation_to_independent_effect_index_unresolved', 'IndependentEffectIndex')}
    seen_unresolved = set()
    for row in links:
        if row['link_id'] in verified_links:
            continue
        src = csv_source(row)
        aid = int(row['actor_id'])
        require(aid in TARGETS and row['actor_category'] == '1' and not row['actor_pre'],
                'Unknown/absence link actor domain')
        if row['status'] == 'ABSENT_IN_SUPPLIED_MEMBER':
            require(src['evidence_basis'] == 'package_search_scope', 'Numeric absence source classification')
            from_key, to_key = json.loads(row['from_key']), json.loads(row['to_key'])
            require(type(from_key) is int and from_key == to_key, 'Numeric absence is not an identity binding')
            if row['to_domain'] == 'CharSkillCharId':
                require(row['from_domain'] == 'ActorId' and row['relationship'] == 'no_target_char_row'
                        and from_key == aid and from_key not in char_ids
                        and src['package_path'] == TABLES[1], 'False CharSkill absence')
            else:
                domain = row['to_domain']
                require(domain in {'SkillActiveNo', 'IndependentEffectIndex'}
                        and row['from_domain'] == 'MatrixSkillWord'
                        and row['relationship'] == 'numeric_lookup_no_hit_not_a_domain_binding',
                        'Unsupported absence relationship')
                numbers = skill_nos if domain == 'SkillActiveNo' else set(effects)
                path = TABLES[2] if domain == 'SkillActiveNo' else TABLES[4]
                require(from_key not in numbers and src['package_path'] == path, 'False skill/effect numeric absence')
        elif row['status'] == 'UNRESOLVED':
            require(src['evidence_basis'] in {'package_search_scope', 'raw_archive_member_search'},
                    'Unresolved relationship source classification')
            kind = (row['from_domain'], row['relationship'], row['to_domain'])
            require(kind in unresolved_types and (aid, kind) not in seen_unresolved
                    and json.loads(row['from_key']) == {'actor_id': aid, 'pre': None}
                    and json.loads(row['to_key']) is None, 'Unsupported resolution of a typed domain gap')
            seen_unresolved.add((aid, kind))
        else:
            raise ValueError(f'Link has no validated source relationship: {row["link_id"]}')
        verified_links.add(row['link_id'])
    require(seen_unresolved == {(aid, kind) for aid in TARGETS for kind in unresolved_types},
            'Missing explicit PRE/skill-action/independent-effect domain gaps')
    require(verified_links == set(link_index), 'Unverified typed link remains')
    for rid, member in [('W2-M01', MATRIX_MEMBER),
                        ('W2-M06', 'Table/Skill/Matrix/CharacterMatrices.xml')]:
        r = req_index[rid]
        require(r['member'] == member and r['availability'] == 'ACQUIRED_AND_VERIFIED'
                and r['carrier_sha256'] == TABLE_SHA and r['member_sha256'] == table.member_sha(member),
                f'Acquired Table member request: {rid}')
    require(req_index['W2-M06']['bundle_phase'] == 'OPTIONAL_COMPARISON', 'Character matrix incorrectly required')
    for rid, aid in [('W2-M02', 1001), ('W2-M03', 1009), ('W2-M04', 1004)]:
        r = req_index[rid]
        require(r['stem'] == profiles[aid]['file_stem'] and r['member'] == BODY_MEMBERS[aid]
                and r['carrier'] == 'Character/Mon/Base.stp' and r['carrier_sha256'] == BASE_SHA
                and r['member_sha256'] == BODY_SHAS[aid] and r['availability'] == 'ACQUIRED_AND_VERIFIED',
                f'Acquired exact body request: {rid}')
    for rid in ('W2-M05', 'W2-M07'):
        r = req_index[rid]
        require(not r['member'] and not r['member_sha256'] and r['availability'] != 'ACQUIRED_AND_VERIFIED',
                f'Invented Monster/skill provider filename: {rid}')
    required_ref_count = 0
    for r in required:
        require(r['server_policy_design_blocked'] == 'false', 'Official Server unknown turned into design blocker')
        for src in json.loads(r['source_refs']):
            check_source(src, source_map, raw, archives)
            required_ref_count += 1
    resources = verify_resources(out, expected_resources, profile_resource_links, link_index,
                                 req_index, source_map, raw, archives)
    ref_count = 0
    for src in walk_refs(doc):
        check_source(src, source_map, raw, archives)
        ref_count += 1
    policy_ids = {p['id'] for p in doc['server_policy_candidates']}
    require(len(policy_ids) == 9 and {p['field'] for p in doc['server_policy_candidates']} == AI_FIELDS,
            'Candidate policy coverage')
    require(all(f['server_requirement'] in policy_ids for p in profiles.values() for f in p['ai_fields'].values()),
            'Dangling Server requirement')

    negative_checks = []
    mutants = []
    mutant = deepcopy(doc)
    mutant['profiles'][0]['ai_fields']['cooldown']['value'] = 0
    mutants.append(('reject_unknown_cooldown_as_zero', mutant))
    mutant = deepcopy(doc)
    del mutant['profiles'][1]['ai_fields']['death']
    mutants.append(('reject_missing_ai_field', mutant))
    mutant = deepcopy(doc)
    mutant['profiles'][0]['body_extension'] = '.exe'
    mutants.append(('reject_unobserved_body_extension', mutant))
    mutant = deepcopy(doc)
    mutant['runtime_ready'] = True
    mutants.append(('reject_runtime_promotion', mutant))
    mutant = deepcopy(doc)
    mutant['profiles'][0]['reported_matrix_cells'][0]['matrix_variant'] = 1
    mutants.append(('reject_rewritten_historical_matrix_variant', mutant))
    mutant = deepcopy(doc)
    mutant['profiles'][0]['matrix_cells'][0]['actor_pre'] = 1
    mutants.append(('reject_invented_actor_PRE_matrix_binding', mutant))
    mutant = deepcopy(doc)
    mutant['profiles'][0]['animations'][0]['fps'] = 40
    mutants.append(('reject_FrameSpeed_as_fps', mutant))
    for label, mutant in mutants:
        require(not validator.is_valid(mutant), f'Schema failed mutation check: {label}')
        negative_checks.append(label)

    artifacts = {p.name: digest(p.read_bytes()) for p in sorted(out.iterdir())
                 if p.is_file() and p.name != 'validation-report.json'
                 and (not args.report or p.resolve() != args.report.resolve())}
    result = dict(format='W2_DATA_VALIDATION_V2', result='PASS',
        scope='source integrity, schema, archive-backed rows, typed evidence and unknown preservation only',
        input_manifest_sha256=digest(manifest_raw), input_zip_sha256=zip_sha,
        input_zip_bytes_verified=zip_sha is not None, manifest_files_verified=len(raw),
        git_commit_tree_blobs_verified_this_run=git_checks,
        git_check_scope='not_requested' if not args.git_repo else manifest['source_analysis_commit'],
        original_carrier_reread=True, table_archive_sha256=table.sha256, base_archive_sha256=base.sha256,
        archive_integrity={table.sha256: table.metadata, base.sha256: base.metadata},
        direct_archive_members_verified=len(source_index['direct_archive_members']),
        package_table_members_directly_compared=5, imported_raw_matrix_members_verified=2,
        raw_matrix_cells_verified=len(matrix_rows), raw_body_members_verified=3,
        raw_animation_rows_verified=animation_count, raw_effect_children_verified=effect_count,
        raw_sound_children_verified=sound_count,
        optional_effect_references=len(expected_optional_refs['effects']),
        optional_presentation_references=len(expected_optional_refs['clips']),
        resource_reference_occurrences=resources['occurrences'],
        unique_resource_references=resources['distinct'],
        resource_occurrences_by_kind=resources['by_kind'],
        unique_resource_references_by_kind=resources['distinct_by_kind'],
        resource_source_refs_checked=resources['source_refs_checked'],
        optional_presentation_requirements=resources['optional_requests'],
        bin_native_reverification=False, old_evidence_scripts_executed=False,
        game_or_server_executed=False, profile_count=3, actor_variant_count=variants,
        ai_field_count=27, unresolved_ai_numeric_values=27, link_count=len(links),
        typed_links_verified=len(verified_links), link_source_refs_checked=link_ref_count,
        link_status_counts=dict(Counter(r['status'] for r in links)),
        required_member_rows=len(required), required_rows_are_not_a_physical_file_count=True,
        required_member_availability_counts=dict(Counter(r['availability'] for r in required)),
        required_member_source_refs_checked=required_ref_count,
        cluster_target_occurrences=len(cluster_rows), profile_source_refs_checked=ref_count,
        schema_validator='jsonschema '+version('jsonschema')+' / Draft 2020-12',
        negative_schema_cases=negative_checks,
        formal_acceptance='No T01 FULL-PASS/RR acceptance/S00 SPEC or ADR promotion',
        runtime_validation='NOT_PERFORMED', artifact_sha256=artifacts)
    if args.report:
        args.report.parent.mkdir(parents=True, exist_ok=True)
        args.report.write_text(json.dumps(result, ensure_ascii=False, indent=2)+'\n', encoding='utf-8')
    print(json.dumps({k: v for k, v in result.items() if k != 'artifact_sha256'}, ensure_ascii=False, indent=2))


if __name__ == '__main__':
    try:
        main()
    except (ValueError, OSError, KeyError, ValidationError, ET.ParseError, expat.ExpatError,
            struct.error, zlib.error, subprocess.CalledProcessError) as exc:
        print(f'W2 validation failed: {exc}', file=sys.stderr)
        raise SystemExit(1)
