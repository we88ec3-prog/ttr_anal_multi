#!/usr/bin/env python3
"""Restore 25 exact research files from a lossless research-only package.
Python 3 standard library only. No network, game originals, disassembler or
execution of archived code. Existing destinations are refused.
"""
import argparse
import hashlib
import io
import json
from pathlib import Path, PurePosixPath
import tarfile


def digest(data):
    return hashlib.sha256(data).hexdigest()


def restore(root: Path, destination: Path) -> dict:
    manifest = json.loads((root / 'publication-manifest.json').read_text(encoding='utf-8'))
    pieces = []
    for item in manifest['parts']:
        name = PurePosixPath(item['path'])
        if name.is_absolute() or len(name.parts) != 1:
            raise ValueError('Unsafe part path')
        data = (root / item['path']).read_bytes()
        if len(data) != item['bytes'] or digest(data) != item['sha256']:
            raise ValueError('Part identity mismatch: ' + item['path'])
        pieces.append(data)
    archive = b''.join(pieces)
    if len(archive) != manifest['archive_bytes'] or digest(archive) != manifest['archive_sha256']:
        raise ValueError('Archive identity mismatch')
    files = {}
    with tarfile.open(fileobj=io.BytesIO(archive), mode='r:xz') as tar:
        for item in tar.getmembers():
            path = PurePosixPath(item.name)
            if not item.isfile() or path.is_absolute() or '..' in path.parts:
                raise ValueError('Unexpected archive member')
            if item.name in files:
                raise ValueError('Duplicate member')
            source = tar.extractfile(item)
            if source is None:
                raise ValueError('Unreadable member')
            files[item.name] = source.read()
    packed = manifest['packed_previous_native']
    native = json.loads(files.pop(packed))
    blocks = []
    for window in native['windows']:
        code = bytes.fromhex(window['hex'])
        if len(code) != window['bytes'] or digest(code) != window['sha256']:
            raise ValueError('Window mismatch: ' + window['id'])
        cursor = int(window['va'], 0)
        offset = 0
        instructions = []
        for size, text in window['instructions']:
            if not isinstance(size, int) or not 1 <= size <= 15 or offset + size > len(code):
                raise ValueError('Invalid instruction extent')
            instructions.append(dict(va=hex(cursor), hex=code[offset:offset+size].hex(), asm=text))
            offset += size
            cursor += size
        if offset != len(code) or cursor != int(window['end'], 0):
            raise ValueError('Incomplete window')
        window['instructions'] = instructions
        a, z = int(window['va'], 0), int(window['end'], 0)
        blocks.append(f"\n; {window['id']}: {a:08X}..{z:08X} (end exclusive), {window['role']}\n" +
                      '\n'.join(f"{int(x['va'],0):08X}  {x['hex']:<32} {x['asm']}" for x in instructions))
    prefix = 'MEF-one-shot-study-20261116/'
    files[prefix + 'native-evidence.json'] = (json.dumps(native, ensure_ascii=False, indent=2)+'\n').encode('utf-8')
    files[prefix + 'native-evidence.asm'] = ('\n'.join(blocks)+'\n').encode('utf-8')
    expected = {entry['path']: entry for entry in manifest['originals']}
    if set(files) != set(expected) or len(files) != manifest['original_file_count']:
        raise ValueError('Restored file inventory mismatch')
    for name, data in files.items():
        entry = expected[name]
        if len(data) != entry['bytes'] or digest(data) != entry['sha256']:
            raise ValueError('Restored identity mismatch: ' + name)
    if destination.exists():
        raise FileExistsError('Choose a new destination; no overwrite is performed')
    destination.mkdir(parents=True)
    for name, data in files.items():
        target = destination.joinpath(*PurePosixPath(name).parts)
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(data)
    return {'status': 'PASS', 'restored_files': len(files), 'all_original_hashes_match': True,
            'archive_sha256': digest(archive), 'game_code_executed': False,
            'original_game_files_required_for_restoration': False}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--out', type=Path, required=True, help='New output directory')
    args = parser.parse_args()
    print(json.dumps(restore(Path(__file__).resolve().parent, args.out), ensure_ascii=False, indent=2))
