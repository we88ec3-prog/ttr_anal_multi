#!/usr/bin/env python3
"""Read-only W3-07 evidence checks. Never starts, patches, or attaches to the game.
Hash matches and optional disassembly are not semantic FULL-PASS or play validation.
Python 3.10+, standard library; GNU objdump is optional, only for --assembly-dir.
"""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import struct
import subprocess
import sys
import zlib


def require(ok: bool, message: str) -> None:
    if not ok:
        raise ValueError(message)


def sha(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def pe_sections(data: bytes) -> list[tuple[int, int, int]]:
    require(data[:2] == b'MZ', 'Expected MZ executable')
    pe = struct.unpack_from('<I', data, 0x3c)[0]
    require(data[pe:pe+4] == b'PE\0\0', 'Expected PE signature')
    coff = pe + 4
    machine, count = struct.unpack_from('<HH', data, coff)
    optional_size = struct.unpack_from('<H', data, coff + 16)[0]
    optional = coff + 20
    require(machine == 0x14c and struct.unpack_from('<H', data, optional)[0] == 0x10b,
            'Expected i386 PE32')
    imagebase = struct.unpack_from('<I', data, optional + 28)[0]
    result = []
    for i in range(count):
        pos = optional + optional_size + i * 40
        _, rva, size, raw = struct.unpack_from('<4I', data, pos + 8)
        require(raw + size <= len(data), 'Section exceeds original file')
        result.append((imagebase + rva, raw, size))
    return result


def raw_offset(sections: list[tuple[int, int, int]], va: int, size: int) -> int:
    for base, raw, raw_size in sections:
        if base <= va and va + size <= base + raw_size:
            return raw + va - base
    raise ValueError(f'VA {va:#x} not backed by a single raw section; BSS is not file data')


def decode_member(data: bytes) -> bytes:
    if data[:2] != b'EX':
        return data
    require(len(data) >= 16, 'Truncated EX header')
    mode = data[2]
    compressed, expanded, offset = struct.unpack_from('<III', data, 4)
    require(mode in (0, 1) and offset >= 16 and offset + compressed <= len(data), 'Invalid EX metadata')
    require(expanded <= 32_000_000, 'EX expansion limit exceeded')
    body = data[offset:offset+compressed]
    if mode:
        key = [0x30, 0xe7]
        for i in range(2, 1024):
            key.append((key[i-2] + key[i-1] + 0x13 - (0x56 if i == 0x17c else 0)) & 255)
        body = bytes(v ^ key[i % 1024] for i, v in enumerate(body))
    dz = zlib.decompressobj()
    result = dz.decompress(body, expanded + 1)
    require(len(result) == expanded and dz.eof and not dz.unconsumed_tail,
            'EX decoded size/stream mismatch')
    return result


def stp_selected(raw: bytes, selected: set[str]) -> dict[str, bytes]:
    require(raw[:4] == b'STPD', 'Expected STPD')
    data = raw.translate(bytes(i ^ 255 for i in range(256)))
    index = struct.unpack_from('<I', data, 4)[0]
    require(raw[index:index+4] == b'STPI', 'Expected STPI')
    cursor = index + 8
    files: dict[str, int] = {}

    def node(parent: str, depth: int = 0) -> None:
        nonlocal cursor
        require(depth < 64, 'Index recursion limit')
        length = struct.unpack_from('<H', data, cursor)[0]
        cursor += 2
        name = data[cursor:cursor+length].decode('ascii').rstrip('\0')
        cursor += length
        kind = data[cursor]
        cursor += 1
        name = '/'.join(filter(None, (parent, name)))
        if kind in (1, 2):
            count = struct.unpack_from('<I', data, cursor)[0]
            cursor += 12
            require(count < 100_000, 'Index count limit')
            for _ in range(count):
                node(name, depth + 1)
        elif kind == 0:
            _, identity = struct.unpack_from('<II', data, cursor)
            cursor += 16
            files[name] = identity
        else:
            raise ValueError(f'Unsupported STPD kind {kind}')

    node('')
    require(cursor == len(data), 'Index length mismatch')
    require(selected <= files.keys(), 'Selected member missing')
    table = struct.unpack_from('>I', data, 12)[0]
    count = struct.unpack_from('<I', data, table)[0]
    require(table + 4 + count * 32 <= len(data), 'Block table exceeds file')
    needed = {files[name] for name in selected}
    blocks: dict[int, bytes] = {}
    for i in range(count):
        identity, size, first, last = struct.unpack_from('<4I', data, table + 4 + i * 32)
        if identity in needed:
            start = 16 + first * 1024
            require(last >= first and size <= (last-first+1)*1024 and start+size <= len(data),
                    'Member block bounds invalid')
            blocks[identity] = decode_member(data[start:start+size])
    return {name: blocks[files[name]] for name in selected}


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin', type=Path, required=True)
    ap.add_argument('--manifest', type=Path, default=Path(__file__).with_name('manifest.json'))
    ap.add_argument('--table', type=Path)
    ap.add_argument('--event', type=Path)
    ap.add_argument('--exe', type=Path)
    ap.add_argument('--assembly-dir', type=Path)
    args = ap.parse_args()
    manifest = json.loads(args.manifest.read_text(encoding='utf-8'))
    binary = args.bin.read_bytes()
    for name, path in [('Tartaros.bin', args.bin), ('Table.stp', args.table),
                       ('Event.stp', args.event), ('Tartaros.exe', args.exe)]:
        if path is None:
            continue
        data = binary if name == 'Tartaros.bin' else path.read_bytes()
        expected = manifest['sources'][name]
        require(len(data) == expected['bytes'] and sha(data) == expected['sha256'], name + ' source mismatch')
    sections = pe_sections(binary)
    rows = manifest['code_slices'] + manifest['data_slices']
    for row in rows:
        a, z = int(row['va'], 16), int(row['end_exclusive'], 16)
        pos = raw_offset(sections, a, z-a)
        require(pos == int(row['raw'], 16) and z-a == row['size'], row['id'] + ' mapping mismatch')
        require(sha(binary[pos:pos+row['size']]) == row['sha256'], row['id'] + ' byte mismatch')
    checked_members = 0
    if args.table:
        resources = manifest['resource_members']
        actual = stp_selected(args.table.read_bytes(), {r['name'] for r in resources})
        for row in resources:
            value = actual[row['name']]
            require(len(value) == row['size'] and sha(value) == row['sha256'], row['name'] + ' mismatch')
        checked_members = len(resources)
    if args.assembly_dir:
        objdump = shutil.which('objdump')
        require(objdump is not None, 'objdump not installed; omit --assembly-dir to check hashes only')
        require(not args.assembly_dir.exists(), 'Output directory already exists; choose a NEW directory')
        args.assembly_dir.mkdir(parents=True)
        for row in manifest['code_slices']:
            a, raw = int(row['va'], 16), int(row['raw'], 16)
            cmd = [objdump, '-D', '-b', 'binary', '-m', 'i386', '-M', 'intel',
                   f'--adjust-vma={a-raw:#x}', f'--start-address={row["va"]}',
                   f'--stop-address={row["end_exclusive"]}', str(args.bin)]
            result = subprocess.run(cmd, check=True, capture_output=True, text=True)
            (args.assembly_dir / (row['id'] + '.asm')).write_text(result.stdout, encoding='utf-8')
    print(json.dumps({'source_and_slice_hash_check': 'PASS', 'code_slices': len(manifest['code_slices']),
                      'data_slices': len(manifest['data_slices']), 'table_members': checked_members,
                      'runtime': 'NOT_RUN', 'legal_spawn': 'NOT_ESTABLISHED',
                      'full_semantic_review': 'NOT_CLAIMED'}, ensure_ascii=False))


if __name__ == '__main__':
    try:
        main()
    except (OSError, ValueError, KeyError, struct.error, zlib.error, subprocess.SubprocessError) as exc:
        print(f'W3-07 verification failed: {exc}', file=sys.stderr)
        sys.exit(1)
