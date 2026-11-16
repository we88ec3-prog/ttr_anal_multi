"""Read-only presence audit of the SHA-pinned, user-supplied KR Table.stp.

Only metadata and the three requested matrix summaries may be written.
No original archive, decoded resource, game process, or historical script is run
or modified. Format references are recorded in the output.
"""
import argparse
from collections import Counter
from datetime import datetime
import hashlib
import json
from pathlib import Path
import struct
import xml.etree.ElementTree as ET
from zoneinfo import ZoneInfo
import zlib

ARCHIVE_SHA = '09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442'
TARGETS = (
    'Table/Skill/Matrix/MonsterMatrices.xml',
    'Table/Skill/Matrix/CharacterMatrices.xml',
    'Table/Skill/SkillMatrix.xml',
    'Table/_ActorList.xml',
    'Table/CharSkill.xml',
    'Table/SkillActiveTable.xml',
    'Table/IndependentSkillEffect.xml',
)
STEMS = {'1001': '00_HokyPoky', '1009': '01_Moose', '1004': '01_Nepenths'}


def read_archive(raw):
    assert raw[:4] == b'STPD' and hashlib.sha256(raw).hexdigest() == ARCHIVE_SHA
    data = bytes(value ^ 255 for value in raw)
    index = struct.unpack_from('<I', data, 4)[0]
    assert raw[index:index + 4] == b'STPI'
    pos = index + 8
    members, directories = {}, []

    def node(parent='', depth=0):
        nonlocal pos
        assert depth < 64 and pos + 2 <= len(data)
        length = struct.unpack_from('<H', data, pos)[0]
        pos += 2
        assert pos + length + 1 <= len(data)
        name = data[pos:pos + length].decode('ascii').rstrip('\0')
        pos += length
        kind = data[pos]
        pos += 1
        path = '/'.join(filter(None, [parent, name]))
        if kind in (1, 2):
            assert pos + 12 <= len(data)
            count = struct.unpack_from('<I', data, pos)[0]
            pos += 12
            directories.append(path)
            for _ in range(count):
                node(path, depth + 1)
        elif kind == 0:
            assert pos + 16 <= len(data)
            _, identity = struct.unpack_from('<II', data, pos)
            pos += 16
            assert path not in members
            members[path] = identity
        else:
            raise ValueError((path, kind))

    node()
    assert pos == len(data)
    table = struct.unpack_from('>I', data, 12)[0]
    count = struct.unpack_from('<I', data, table)[0]
    assert table + 4 + count * 32 == index
    blocks = {}
    for i in range(count):
        rec = table + 4 + i * 32
        identity, size, first, last = struct.unpack_from('<4I', data, rec)
        assert last >= first and size <= (last - first + 1) * 1024
        start = 16 + first * 1024
        assert 16 <= start and start + size <= table
        stored = data[start:start + size]
        expected_md5 = data[rec + 16:rec + 32].hex()
        assert hashlib.md5(stored).hexdigest() == expected_md5, identity
        assert identity not in blocks
        blocks[identity] = dict(stored=stored, member_id=identity,
                               stored_size=size, raw_body_offset=start,
                               index_record_offset=rec, stored_md5=expected_md5,
                               stored_md5_verified=True)
    assert len(members) == count and set(members.values()) == set(blocks)
    metadata = dict(directory_index_offset=index, block_table_offset=table,
                    directory_count=len(directories), member_count=len(members),
                    block_count=count, all_stored_member_md5_verified=True,
                    index_parsed_to_eof=True)
    return members, blocks, metadata


def decode(stored):
    if stored[:2] != b'EX':
        return stored
    mode = stored[2]
    compressed, expanded, offset = struct.unpack_from('<III', stored, 4)
    assert mode in (0, 1) and offset >= 16
    assert offset + compressed == len(stored) and expanded < 50_000_000
    payload = stored[offset:offset + compressed]
    if mode == 1:
        key = [0x30, 0xe7]
        for i in range(2, 1024):
            key.append((key[i-2] + key[i-1] + 0x13 - (0x56 if i == 0x17c else 0)) & 255)
        payload = bytes(value ^ key[i % 1024] for i, value in enumerate(payload))
    decomp = zlib.decompressobj()
    decoded = decomp.decompress(payload, expanded + 1)
    assert decomp.eof and not decomp.unused_data and not decomp.unconsumed_tail
    assert len(decoded) == expanded
    return decoded


def xml_root(decoded):
    try:
        return ET.fromstring(decoded)
    except (ET.ParseError, LookupError, ValueError):
        return ET.fromstring(decoded.decode('euc-kr'))


def audit(archive, package):
    raw = archive.read_bytes()
    members, blocks, metadata = read_archive(raw)
    targets, matrix_rows = [], []
    active_ids = set()
    for name in TARGETS:
        entry = dict(member=name, present=name in members)
        if name in members:
            block = blocks[members[name]]
            decoded = decode(block['stored'])
            entry.update({key: value for key, value in block.items() if key != 'stored'})
            entry.update(decoded_size=len(decoded), sha256=hashlib.sha256(decoded).hexdigest())
            root = xml_root(decoded)
            entry['xml_root'] = root.tag
            entry['element_counts'] = dict(Counter(elem.tag for elem in root.iter()))
            local = package / 'local-resources' / name
            entry['in_w2_zip'] = local.is_file()
            if local.is_file():
                entry['matches_w2_zip_bytes'] = local.read_bytes() == decoded
                assert entry['matches_w2_zip_bytes'], name
            if name.endswith('/MonsterMatrices.xml'):
                for actor in root.iter('SkillMatrix'):
                    if actor.get('CharID') not in STEMS:
                        continue
                    for matrix in actor.findall('Matrix'):
                        for tier in matrix.findall('Tier'):
                            for key in tier.findall('Key'):
                                matrix_rows.append(dict(
                                    char_id=actor.get('CharID'), matrix_id=matrix.get('ID'),
                                    tier=tier.get('tier'), key=key.get('key'), skill_word=key.get('skill'),
                                    actor_pre=None,
                                    selector=(f"/MatrixList/SkillMatrix[@CharID='{actor.get('CharID')}']"
                                              f"/Matrix[@ID='{matrix.get('ID')}']/Tier[@tier='{tier.get('tier')}']"
                                              f"/Key[@key='{key.get('key')}']/@skill")))
            if name.endswith('/SkillActiveTable.xml'):
                active_ids = {elem.get('no') for elem in root.findall('SKILL')}
        targets.append(entry)
    words = sorted({row['skill_word'] for row in matrix_rows}, key=int)
    return dict(
        schema='w2-table-stp-presence-v1', generated_at=datetime.now(ZoneInfo('Asia/Taipei')).isoformat(),
        status='BOUNDED_RESOURCE_AUDIT_NOT_FULL_PASS',
        scope='User follow-up about uploaded Table.stp; separate from the original ZIP-only W2 inventory',
        archive=archive.name, archive_sha256=ARCHIVE_SHA, archive_bytes=len(raw), **metadata,
        format_sources=[
            dict(path='governance/inspect_tutorial_bounds_resource.py',
                 git_blob_sha1='e39cb00a9db90fbbea00844449b4b4da56520fae'),
            dict(path='governance/inspect_first_tutorial_cluster.py',
                 git_blob_sha1='3a8d1507c35d356c3b395c171a85249765c6a6a5'),
        ],
        targets=targets, target_matrix_rows=matrix_rows,
        target_skill_words=words,
        target_skill_words_found_as_skillactive_no=sorted(set(words) & active_ids, key=int),
        stem_matches={stem: [name for name in sorted(members) if stem.lower() in name.lower()]
                      for stem in STEMS.values()},
        abf_members=[name for name in sorted(members) if name.lower().endswith('.abf')],
        monster_named_members=[name for name in sorted(members) if 'monster' in name.lower()],
        all_member_names=sorted(members),
        limitations=[
            'Absence refers only to member paths in this exact archive; renamed or embedded bodies are not ruled out.',
            'Monster metadata provider and matrix skill-word definition provider remain unidentified.',
            'Filename search is not proof that no other table contains monster-related data.',
            'Matrix ID, tier, key, skill WORD and Actor PRE are separate domains; PRE mapping is unproven.',
            'No AI decision, cooldown unit, animation event, original Server algorithm or runtime behavior is established.',
            'The ZIP-only profiles/schema/required-members remain a historical source-scope snapshot.',
        ])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--archive', required=True, type=Path)
    parser.add_argument('--input', required=True, type=Path, help='Unpacked original W1/W2/W3 input ZIP')
    parser.add_argument('--report', required=True, type=Path)
    args = parser.parse_args()
    destination = args.report.resolve()
    package = args.input.resolve()
    assert destination.suffix == '.json' and destination != args.archive.resolve()
    assert destination != Path(__file__).resolve() and not destination.is_relative_to(package)
    report = audit(args.archive, package)
    destination.parent.mkdir(parents=True, exist_ok=True)
    destination.write_text(json.dumps(report, ensure_ascii=False, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(dict(result='PASS', archive_sha256=ARCHIVE_SHA,
                         members=report['member_count'], target_matrix_rows=len(report['target_matrix_rows']),
                         zip_members_compared=sum('matches_w2_zip_bytes' in row for row in report['targets']),
                         stem_matches=report['stem_matches']), ensure_ascii=False))


if __name__ == '__main__':
    main()
