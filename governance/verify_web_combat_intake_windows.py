"""Read-only byte-window corroboration of a pinned Web handoff, not semantic review."""
import argparse
import hashlib
import json
from pathlib import Path

TARGET = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
COMMIT = '4064846ff77fbf3884fc84830ed35f60c9d8781d'
WINDOWS = [
    ('row_a', 0x545895, 0x54593E, '728054a73b1e1430660351bb7964e8be652243dc2c6d65501d14488d0302bdd1'),
    ('row_b', 0x545A54, 0x545B1A, '061507199083913b66dc8b0a3efcbfd9bdb884c8cb361d5eadaa3f3b90e2f26d'),
    ('conditional_sender', 0x545B38, 0x545B73, '170e1d95e58df6a123a3f6bd63e7a28ed0d97a42895078d7e0d3d8adcb89fe6c'),
    ('timer_receiver', 0x545E20, 0x545F29, '5001977eb515729a846cf24e4d6be76ace6644ac6c8da0c9d365739f66e0fc08'),
    ('timer_decrement', 0x54F200, 0x54F267, '977731b2d09a4d9ae74f41c48f9b004b246607d1e4cb16bef5077f9544d8f9d5'),
    ('availability', 0x54F270, 0x54F32E, '977d4ddb33d52769fb63f3661db57651548fcb38057ff86f046c799d2823a999'),
    ('hero_helper', 0x549980, 0x549C4F, 'a20410dbf2495b8172aab9c6c99d328c0e4d84c05f9e5b8cf89d9ed724863537'),
]


def verify(path):
    data = path.read_bytes()
    if hashlib.sha256(data).hexdigest() != TARGET:
        raise ValueError('Original KR target SHA mismatch')
    rows = []
    # Mapping is pinned to this exact PE: .text VA401000/raw400.
    for name, start, end, expected in WINDOWS:
        raw = start - 0x400C00
        selected = data[raw:raw + end - start]
        actual = hashlib.sha256(selected).hexdigest()
        if len(selected) != end - start or actual != expected:
            raise ValueError(f'Window mismatch: {name}')
        rows.append(dict(name=name, start_va=hex(start), end_va_exclusive=hex(end),
                         size=len(selected), sha256=actual, hash_matches=True))
    return dict(schema='s00-web-combat-window-corroboration-v1', target_sha256=TARGET,
                source_commit=COMMIT, classification='BYTE_HASH_ONLY_NOT_SEMANTIC_FULL_PASS',
                client_execution=False, windows=rows)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('original_bin', type=Path)
    parser.add_argument('--output', type=Path)
    args = parser.parse_args()
    output = json.dumps(verify(args.original_bin), ensure_ascii=False, indent=2) + '\n'
    if args.output:
        if args.output.resolve() == args.original_bin.resolve():
            raise ValueError('Cannot overwrite original')
        args.output.write_bytes(output.encode('utf8'))
    else:
        print(output, end='')
