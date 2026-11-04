"""Audit the supplied, pinned Base.stp; decode only three requested ABF bodies.

Writes structural metadata, never an entire XML body, to the JSON report.
Optional decoded copies must be outside this repository and preserve original
bytes. No old evidence script, game process, loader, BIN, MEF or other archive
is executed or inspected. Python's standard library is sufficient.
"""
import argparse
from collections import Counter, defaultdict
from datetime import datetime
import hashlib
import json
from pathlib import Path, PurePosixPath
import re
import struct
import xml.etree.ElementTree as ET
from xml.parsers import expat
from zoneinfo import ZoneInfo
import zlib

ARCHIVE_SHA = '1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957'
ARCHIVE_BYTES = 946961
TARGETS = (
    ('1001', 'Mon/00_HokyPoky.abf', '3d817eb1d3c2e0839853f3d233771a3829470b8fdb9cd8391d920485cb95f633'),
    ('1009', 'Mon/01_Moose.abf', 'd0ba2a3b0cd941e7a267f24c6ce68cb5f727d2f72a7ae9f21b1b51cd8cd3aa6b'),
    ('1004', 'Mon/01_Nepenths.abf', '6a581ad59dc5b009a8b155d7ef4aa45ec44c1753fb3936b2223f98dab50eca71'),
)
FORMAT_SOURCES = [
    {'path': 'governance/inspect_tutorial_bounds_resource.py',
     'git_blob_sha1': 'e39cb00a9db90fbbea00844449b4b4da56520fae',
     'role': 'STPD/STPI layout; read as text only'},
    {'path': 'governance/inspect_first_tutorial_cluster.py',
     'git_blob_sha1': '3a8d1507c35d356c3b395c171a85249765c6a6a5',
     'role': 'EX mode 1 XOR1024/zlib layout; read as text only'},
    {'path': 'governance/inspect_field19_actor_resources.py',
     'git_blob_sha1': 'd1e9455789a6bdcd0e8097aaee1be0309fab8648',
     'role': 'Historical carrier/member/hash declarations, now checked against the uploaded bytes'},
]


def require(condition, message):
    """Keep validation active even when Python is invoked with -O."""
    if not condition:
        raise ValueError(message)


def read_archive(raw):
    require(len(raw) == ARCHIVE_BYTES, 'Unexpected archive byte count')
    require(hashlib.sha256(raw).hexdigest() == ARCHIVE_SHA, 'Archive SHA256 mismatch')
    require(raw[:4] == b'STPD', 'Missing STPD header')
    data = bytes(value ^ 255 for value in raw)
    index = struct.unpack_from('<I', data, 4)[0]
    table = struct.unpack_from('>I', data, 12)[0]
    require(16 <= table < index <= len(data) - 8, 'Invalid archive offsets')
    require(raw[index:index + 4] == b'STPI', 'Missing STPI index signature')
    pos = index + 8
    members, directories = {}, []

    def node(parent='', depth=0):
        nonlocal pos
        require(depth < 64 and pos + 2 <= len(data), 'Invalid directory recursion')
        length = struct.unpack_from('<H', data, pos)[0]
        pos += 2
        require(pos + length + 1 <= len(data), 'Truncated index name')
        name = data[pos:pos + length].decode('ascii').rstrip('\0')
        require('\0' not in name and '/' not in name and '\\' not in name,
                'Unexpected directory node name')
        pos += length
        kind = data[pos]
        pos += 1
        path = '/'.join(part for part in (parent, name) if part)
        if kind in (1, 2):
            require(pos + 12 <= len(data), 'Truncated directory node')
            child_count = struct.unpack_from('<I', data, pos)[0]
            pos += 12
            directories.append({'path': path, 'kind': kind, 'child_count': child_count})
            for _ in range(child_count):
                node(path, depth + 1)
        elif kind == 0:
            require(pos + 16 <= len(data), 'Truncated file node')
            _, identity = struct.unpack_from('<II', data, pos)
            pos += 16
            require(path not in members, 'Duplicate member path')
            members[path] = identity
        else:
            raise ValueError(f'Unsupported index node kind {kind}')

    node()
    require(pos == len(data), 'Index does not terminate exactly at EOF')
    count = struct.unpack_from('<I', data, table)[0]
    require(table + 4 + count * 32 == index, 'Block table extent mismatch')
    blocks, extents = {}, []
    for i in range(count):
        rec = table + 4 + i * 32
        identity, size, first, last = struct.unpack_from('<4I', data, rec)
        require(last >= first and 0 < size <= (last - first + 1) * 1024,
                f'Invalid block extent for member {identity}')
        start = 16 + first * 1024
        require(start + size <= table, f'Body outside data region: {identity}')
        stored = data[start:start + size]
        expected = data[rec + 16:rec + 32]
        require(hashlib.md5(stored).digest() == expected, f'Stored MD5 mismatch: {identity}')
        require(identity not in blocks, 'Duplicate block identity')
        blocks[identity] = {
            'stored': stored, 'member_id': identity, 'stored_size': size,
            'first_block': first, 'last_block': last, 'raw_body_offset': start,
            'index_record_offset': rec, 'stored_md5': expected.hex(),
            'stored_md5_verified': True, 'stored_sha256': hashlib.sha256(stored).hexdigest(),
            'archive_raw_member_span_sha256': hashlib.sha256(raw[start:start + size]).hexdigest(),
        }
        extents.append((first, last))
    require(len(members) == count == len(set(members.values())), 'Member IDs are not one-to-one')
    require(set(members.values()) == set(blocks), 'Unresolved index member or orphan block')
    extents.sort()
    require(all(left[1] < right[0] for left, right in zip(extents, extents[1:])),
            'Overlapping block allocations')
    metadata = {
        'directory_index_offset': index, 'block_table_offset': table,
        'directory_count': len(directories), 'directories': directories,
        'member_count': len(members), 'block_count': count,
        'unique_member_ids': len(set(members.values())),
        'index_parsed_to_eof': True, 'index_member_ids_equal_block_ids': True,
        'block_allocations_do_not_overlap': True,
        'stored_md5_verified_count': count, 'all_stored_member_md5_verified': True,
        'stored_md5_basis': 'Member bytes after archive-wide XOR 0xff, before EX decode; digest from XOR-decoded block record',
        'member_count_by_extension': dict(sorted(Counter(PurePosixPath(name).suffix.lower() for name in members).items())),
        'all_member_names': sorted(members),
    }
    return members, blocks, metadata


def decode(stored):
    if stored[:2] != b'EX':
        return stored, {'wrapped': False}
    require(len(stored) >= 16, 'Truncated EX header')
    mode = stored[2]
    compressed, expanded, offset = struct.unpack_from('<III', stored, 4)
    require(mode in (0, 1) and offset >= 16, 'Unsupported EX mode or offset')
    require(offset + compressed == len(stored) and 0 < expanded < 1000000,
            'Unexpected selected ABF extent')
    payload = stored[offset:]
    if mode == 1:
        key = [0x30, 0xe7]
        for i in range(2, 1024):
            key.append((key[i - 2] + key[i - 1] + 0x13 - (0x56 if i == 0x17c else 0)) & 255)
        payload = bytes(value ^ key[i % 1024] for i, value in enumerate(payload))
    decoder = zlib.decompressobj()
    decoded = decoder.decompress(payload, expanded + 1)
    require(decoder.eof and not decoder.unused_data and not decoder.unconsumed_tail,
            'Incomplete EX zlib stream or trailing data')
    require(len(decoded) == expanded, 'EX decoded size mismatch')
    return decoded, {
        'wrapped': True, 'mode': mode, 'compressed_size': compressed,
        'declared_expanded_size': expanded, 'payload_offset': offset,
        'zlib_eof': True, 'zlib_unused_data_bytes': 0, 'zlib_unconsumed_tail_bytes': 0,
    }


def parse_xml(decoded):
    declaration = re.match(br'<\?xml\s+([^?]+)\?>', decoded)
    require(declaration is not None, 'Missing XML declaration')
    encoding = re.search(br'encoding="([^"]+)"', declaration.group(1)).group(1).decode('ascii')
    require(encoding == 'euc-kr', 'Unexpected selected ABF encoding')
    text = decoded.decode(encoding)
    require(text.encode(encoding) == decoded, 'Text decode does not round-trip exactly')
    parser = expat.ParserCreate(encoding='utf-8')
    nodes, stack, comments, instructions = [], [], [], []

    def start(tag, attributes):
        index = len(nodes)
        node = {'tag': tag, 'attributes': dict(attributes), 'line': parser.CurrentLineNumber,
                'column_1based': parser.CurrentColumnNumber + 1, 'child_indices': [],
                'parent_index': stack[-1] if stack else None, 'text_parts': []}
        if stack:
            nodes[stack[-1]]['child_indices'].append(index)
        nodes.append(node)
        stack.append(index)

    def end(tag):
        node = nodes[stack.pop()]
        require(node['tag'] == tag, 'XML stack mismatch')
        node['end_line'] = parser.CurrentLineNumber

    def character_data(value):
        if stack:
            nodes[stack[-1]]['text_parts'].append(value)

    parser.StartElementHandler = start
    parser.EndElementHandler = end
    parser.CharacterDataHandler = character_data
    parser.CommentHandler = lambda value: comments.append({'line': parser.CurrentLineNumber, 'text': value})
    parser.ProcessingInstructionHandler = lambda target, value: instructions.append({'line': parser.CurrentLineNumber, 'target': target, 'data': value})
    parser.ExternalEntityRefHandler = lambda *unused: 0
    parser.Parse(text, True)
    require(not stack and nodes[0]['tag'] == 'CharacterList', 'Unexpected XML root')
    require(all(not ''.join(node['text_parts']).strip() for node in nodes),
            'Unexpected non-whitespace text needs an explicit report policy')
    require(not comments and not instructions, 'Unexpected XML annotation needs explicit inventory')

    def selectors(index, path):
        node = nodes[index]
        node['selector'] = path
        counts = Counter()
        ids = Counter((nodes[i]['tag'], nodes[i]['attributes'].get('ID')) for i in node['child_indices'])
        for child_index in node['child_indices']:
            child = nodes[child_index]
            tag, identity = child['tag'], child['attributes'].get('ID')
            counts[tag] += 1
            if identity is not None and ids[(tag, identity)] == 1:
                require("'" not in identity, 'Unsupported quote in identity selector')
                component = f"{tag}[@ID='{identity}']"
            else:
                component = f'{tag}[{counts[tag]}]'
            selectors(child_index, path + '/' + component)

    selectors(0, '/CharacterList')
    inventory = []
    for i, node in enumerate(nodes):
        inventory.append({
            'node_id': f'n{i + 1:03d}', 'tag': node['tag'], 'selector': node['selector'],
            'line': node['line'], 'end_line': node['end_line'], 'column_1based': node['column_1based'],
            'attributes': node['attributes'], 'child_count': len(node['child_indices']),
            'children': [f'n{child + 1:03d}' for child in node['child_indices']],
        })
    # Independently parse the same decoded text to check complete element/attribute coverage.
    tree = ET.fromstring(text)
    require([(node['tag'], node['attributes']) for node in inventory]
            == [(elem.tag, dict(elem.attrib)) for elem in tree.iter()], 'XML inventory coverage mismatch')
    fields = defaultdict(list)
    for node in inventory:
        for key, value in node['attributes'].items():
            fields[(node['tag'], key)].append(value)
    return {
        'root': tree.tag, 'declared_encoding': encoding, 'line_count': len(decoded.splitlines()),
        'line_number_basis': '1-based lines of the exact decoded member, before XML reserialization',
        'line_endings': {'crlf_count': decoded.count(b'\r\n'), 'lf_count': decoded.count(b'\n')},
        'node_count': len(inventory), 'element_counts': dict(Counter(node['tag'] for node in inventory)),
        'attribute_occurrence_count': sum(len(node['attributes']) for node in inventory),
        'attribute_inventory': [
            {'element': tag, 'attribute': name, 'occurrences': len(values), 'distinct_raw_values': sorted(set(values))}
            for (tag, name), values in sorted(fields.items())
        ],
        'non_whitespace_text_nodes': 0, 'comments': [], 'processing_instructions': [],
        'nodes': inventory,
    }


def analyze_target(actor_id, member, decoded, xml, member_names):
    nodes = xml['nodes']
    characters = [node for node in nodes if node['tag'] == 'Character']
    require(len(characters) == 1, 'Expected one Character declaration')
    character = characters[0]
    relative = character['attributes']['RelativePath']
    require(relative.rstrip('/') == PurePosixPath(member).stem, 'Body path/stem declaration mismatch')
    by_id = {node['node_id']: node for node in nodes}
    animations, references = [], []
    for node in nodes:
        attributes = node['attributes']
        if node['tag'] == 'Animation':
            children = [by_id[identity] for identity in node['children']]
            animations.append({
                'animation_id': attributes['ID'], 'selector': node['selector'],
                'line': node['line'], 'end_line': node['end_line'], 'raw_attributes': attributes,
                'effects': [{'selector': child['selector'], 'line': child['line'], 'raw_attributes': child['attributes']}
                            for child in children if child['tag'] == 'Effect'],
                'sounds': [{'selector': child['selector'], 'line': child['line'], 'raw_attributes': child['attributes']}
                           for child in children if child['tag'] == 'Sound'],
                'other_child_elements': [child['tag'] for child in children if child['tag'] not in ('Effect', 'Sound')],
                'frames_per_second': None, 'total_frames': None, 'duration_seconds': None,
                'hit_frame': None, 'matrix_skill_word': None,
            })
        if node['tag'] == 'Character':
            kind, attribute, file = 'base_model', 'BaseFile', attributes['BaseFile']
        elif 'File' in attributes:
            require(node['tag'] in ('Texture', 'Animation', 'Effect', 'Sound'), 'Unknown resource reference tag')
            kind = {'Texture': 'texture', 'Animation': 'animation_clip', 'Effect': 'effect', 'Sound': 'sound'}[node['tag']]
            attribute, file = 'File', attributes['File']
        else:
            continue
        folder = attributes.get('Folder')
        literal_path = (folder if folder is not None else relative) + file
        references.append({
            'kind': kind, 'file': file, 'folder': folder,
            'character_relative_path': relative if folder is None else None,
            'literal_path_from_attributes': literal_path,
            'path_basis': 'Folder + File' if folder is not None else 'Character/@RelativePath + file attribute',
            'source_selector': node['selector'] + '/@' + attribute, 'line': node['line'],
            'base_index_exact_literal_matches': [name for name in member_names if name == literal_path],
            'base_index_basename_matches': [name for name in member_names if PurePosixPath(name).name == file],
            'loader_resolved_path': None, 'carrier': None, 'resource_content_read': False,
        })
    ids = [row['animation_id'] for row in animations]
    require(len(ids) == len(set(ids)), 'Duplicate Animation ID')
    field_occurrences = [
        {'selector': node['selector'] + '/@' + key, 'line': node['line'], 'raw_value': value}
        for node in nodes for key, value in node['attributes'].items()
        if re.fullmatch(r'(?:skill(?:id|no|_id|_no|word|_word)?|cooldown|duration|fps|framecount|numframes|totalframes|hitframe)', key, re.I)
    ]
    return {
        'actor_id_context': actor_id,
        'actor_id_basis': 'Requested Actor ID to FILE stem association from Table inventory; ABF itself has no Actor ID field',
        'character': {'selector': character['selector'], 'line': character['line'], 'raw_attributes': character['attributes']},
        'animation_count': len(animations), 'animation_ids': ids,
        'unique_animation_clip_count': len({row['raw_attributes']['File'] for row in animations}),
        'animations': animations, 'resource_references': references,
        'empty_containers': [{'selector': node['selector'], 'line': node['line']}
                             for node in nodes if node['tag'].endswith('List') and node['child_count'] == 0],
        'explicit_skill_id_or_duration_fps_frame_count_hit_frame_fields': field_occurrences,
        'explicit_event_elements': [{'selector': node['selector'], 'line': node['line'], 'tag': node['tag']}
                                    for node in nodes if re.search(r'event|trigger|notify', node['tag'], re.I)],
        'timing_boundary': {
            'raw_FrameSpeed_values': sorted({row['raw_attributes']['FrameSpeed'] for row in animations}),
            'FrameSpeed_unit': None,
            'raw_RepeatStartFrame_values': sorted({row['raw_attributes']['RepeatStartFrame'] for row in animations}),
            'raw_LagtimeType_values': sorted({row['raw_attributes']['LagtimeType'] for row in animations}),
            'frames_per_second': None, 'frame_count': None, 'duration_seconds': None,
            'hit_time': None, 'effect_or_sound_start_time': None,
            'meaning': 'Raw field names and values only; no proven FPS conversion, clip length, damage event or AI policy',
        },
    }


def audit(archive):
    raw = archive.read_bytes()
    members, blocks, index = read_archive(raw)
    targets, decoded_members = [], {}
    for actor, member, expected in TARGETS:
        require(member in members, f'Missing selected member: {member}')
        block = blocks[members[member]]
        decoded, wrapper = decode(block['stored'])
        digest = hashlib.sha256(decoded).hexdigest()
        require(digest == expected, f'Decoded member SHA256 mismatch: {member}')
        xml = parse_xml(decoded)
        target = {
            'member': member, 'decoded_sha256': digest, 'decoded_size': len(decoded),
            'historical_declared_sha256': expected, 'historical_declared_sha256_matches': True,
            **{key: value for key, value in block.items() if key != 'stored'},
            'ex_wrapper': wrapper, 'xml': xml,
            **analyze_target(actor, member, decoded, xml, sorted(members)),
        }
        targets.append(target)
        decoded_members[member] = decoded
    dependencies = {}
    for target in targets:
        for ref in target['resource_references']:
            identity = (ref['kind'], ref['literal_path_from_attributes'])
            dependency = dependencies.setdefault(identity, {
                'kind': ref['kind'], 'file': ref['file'],
                'literal_path_from_attributes': ref['literal_path_from_attributes'],
                'base_index_exact_literal_matches': ref['base_index_exact_literal_matches'],
                'base_index_basename_matches': ref['base_index_basename_matches'],
                'carrier': None, 'content_read': False, 'references': [],
            })
            dependency['references'].append({
                'member': target['member'], 'decoded_sha256': target['decoded_sha256'],
                'selector': ref['source_selector'], 'line': ref['line'],
            })
    report = {
        'schema': 'w2-base-stp-body-audit-v1',
        'generated_at': datetime.now(ZoneInfo('Asia/Taipei')).isoformat(),
        'status': 'BOUNDED_DIRECT_RESOURCE_AUDIT_NOT_T01_FULL_PASS',
        'archive': archive.name, 'logical_carrier': 'Character/Mon/Base.stp',
        'archive_sha256': ARCHIVE_SHA, 'archive_bytes': len(raw),
        'auditor_sha256': hashlib.sha256(Path(__file__).read_bytes()).hexdigest(),
        'format_sources': FORMAT_SOURCES, 'archive_index': index,
        'read_scope': {
            'whole_archive_hashed': True, 'whole_member_index_parsed': True,
            'all_stored_member_md5_checked': True, 'decoded_and_fully_parsed_members': list(decoded_members),
            'other_member_bodies_decoded': False, 'downstream_resource_bodies_read': False,
            'Table_or_other_archives_opened_by_this_auditor': False,
            'game_BIN_MEF_loader_inspected_or_executed': False,
            'raw_member_bytes_in_report': False,
        },
        'targets': targets,
        'totals': {
            'decoded_bodies': len(targets), 'xml_nodes': sum(t['xml']['node_count'] for t in targets),
            'attribute_occurrences': sum(t['xml']['attribute_occurrence_count'] for t in targets),
            'animation_slots': sum(t['animation_count'] for t in targets),
            'distinct_animation_clips': sum(t['unique_animation_clip_count'] for t in targets),
            'effect_nodes': sum(t['xml']['element_counts'].get('Effect', 0) for t in targets),
            'sound_nodes': sum(t['xml']['element_counts'].get('Sound', 0) for t in targets),
            'reference_occurrences': sum(len(t['resource_references']) for t in targets),
            'distinct_referenced_resources': len(dependencies),
            'distinct_referenced_resources_by_kind': dict(sorted(Counter(d['kind'] for d in dependencies.values()).items())),
        },
        'referenced_resources': [dependencies[key] for key in sorted(dependencies)],
        'limitations': [
            'Only the three pinned ABF bodies are semantically inventoried; other Base members are index/hash checked only.',
            'Actor ID is contextual. Matching FILE/member/RelativePath stems does not establish every PRE loader or runtime path.',
            'Animation ID, matrix ID/tier/key/skill WORD and Actor PRE remain distinct domains; no numeric equality join is asserted.',
            'File/Folder/RelativePath literals are references, not evidence the referenced asset was supplied or opened.',
            'Zero exact-name/basename matches applies only to this Base index; existence in other archives is untested.',
            'FrameSpeed=40.000000 is not promoted to proven 40 FPS; no duration, total frames, hit frame or cooldown is derived.',
            'Effect/Sound child presence is not a timed damage event; these nodes have only File and Folder attributes.',
            'Nepenths slots 4/6 referencing WAIT01 does not prove immobility or an original Server AI rule.',
            'No new T01 certification, RR acceptance, S00 approved rule, Server implementation or playable result is implied.',
        ],
    }
    return report, decoded_members


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--archive', required=True, type=Path)
    parser.add_argument('--report', required=True, type=Path)
    parser.add_argument('--extract-dir', type=Path, help='Optional local decoded copies, strictly outside this repository')
    args = parser.parse_args()
    archive, destination = args.archive.resolve(), args.report.resolve()
    script = Path(__file__).resolve()
    require(destination.suffix == '.json' and destination not in (archive, script), 'Unsafe report destination')
    report, decoded_members = audit(archive)
    if args.extract_dir is not None:
        root = args.extract_dir.resolve()
        repository = next((parent for parent in script.parents if (parent / '.git').exists()), script.parents[4])
        require(not root.is_relative_to(repository), 'Decoded raw resources must remain outside Git repository')
        destinations = [(root / name, body) for name, body in decoded_members.items()]
        for output, body in destinations:
            require(output.resolve().is_relative_to(root), 'Unsafe decoded resource path')
            require(output.resolve() not in (archive, destination, script), 'Decoded output overlaps an input/report')
            if output.exists():
                require(output.is_file() and output.read_bytes() == body, 'Existing decoded copy differs; not overwritten')
        for output, body in destinations:
            if not output.exists():
                output.parent.mkdir(parents=True, exist_ok=True)
                with output.open('xb') as handle:
                    handle.write(body)
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({'result': 'PASS', 'archive_sha256': ARCHIVE_SHA,
                      'members_and_stored_md5_verified': report['archive_index']['member_count'],
                      **report['totals']}, ensure_ascii=False))


if __name__ == '__main__':
    main()
