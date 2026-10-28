#!/usr/bin/env python3
"""Preflight a full KR bulk audit without executing the target program."""
import argparse
import hashlib
import json
from pathlib import Path

SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'

def check(root):
    root = Path(root).resolve()
    base = root / 'kr-bulk-roy' / SHA
    index = base / 'index.jsonl'
    result = {'schema': 'kr-bulk-audit-preflight-v1', 'source_sha256': SHA,
              'index_exists': index.is_file(), 'index_bytes': None,
              'index_sha256': None, 'ready_for_full_audit': False,
              'status': 'BLOCKED_NO_COMPLETE_INDEX'}
    if not index.is_file():
        return result
    if not (base / 'functions').is_dir() or not (base / 'raw').is_dir():
        result['status'] = 'BLOCKED_MISSING_DIRECTORY'
        return result
    h = hashlib.sha256()
    with index.open('rb') as f:
        for block in iter(lambda: f.read(1024 * 1024), b''):
            h.update(block)
    result['index_bytes'] = index.stat().st_size
    result['index_sha256'] = h.hexdigest()
    if not result['index_bytes']:
        result['status'] = 'BLOCKED_EMPTY_INDEX'
        return result
    result['ready_for_full_audit'] = True
    result['status'] = 'PREFLIGHT_ONLY_READY_FOR_FULL_AUDIT'
    return result

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('repository_root')
    parser.add_argument('--output')
    args = parser.parse_args()
    result = check(args.repository_root)
    output = json.dumps(result, indent=2, ensure_ascii=False) + '\n'
    if args.output:
        Path(args.output).write_text(output, encoding='utf-8')
    print(output, end='')
    return 0 if result['ready_for_full_audit'] else 2

if __name__ == '__main__':
    raise SystemExit(main())
