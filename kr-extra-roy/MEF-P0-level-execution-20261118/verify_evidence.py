#!/usr/bin/env python3
"""Reproduce bounded source, catalog and subtopic analyses without running targets."""
from __future__ import annotations

import argparse
import ast
import hashlib
import json
import re
import subprocess
import sys
import tempfile
from datetime import datetime, timezone
from pathlib import Path
from urllib.parse import unquote, urlsplit

HERE = Path(__file__).resolve().parent
BASE = '19005c9f8a8180e6f0deb00faf008a11ef98023f'
PACKAGE = 'kr-extra-roy/MEF-P0-level-execution-20261118'
NAV = {'kr-extra-roy/MEF-CURRENT-DIRECTION.md', 'kr-extra-roy/README.md'}
EXPECTED = {'P0-3': 'L03', 'P0-4': 'L04', 'P0-5': 'L05', 'P0-6': 'L06',
            'P0-7': 'L07', 'P0-8': 'L08', 'P0-9': 'L10', 'P0-10': 'L13'}


def unique_object(pairs):
    d = {}
    for k, v in pairs:
        if k in d:
            raise ValueError(f'Duplicate JSON key: {k}')
        d[k] = v
    return d


def load(path):
    return json.loads(Path(path).read_text(), object_pairs_hook=unique_object,
                      parse_constant=lambda x: (_ for _ in ()).throw(ValueError(f'Nonfinite JSON: {x}')))


def git(repo, *args):
    return subprocess.check_output(['git', *args], cwd=repo)


def identity(data, expected, label):
    assert len(data) == expected['bytes'], f'Length mismatch: {label}'
    assert hashlib.sha256(data).hexdigest() == expected['sha256'], f'SHA256 mismatch: {label}'
    blob = expected.get('git_blob', expected.get('blob'))
    if blob:
        actual = hashlib.sha1(b'blob ' + str(len(data)).encode() + b'\0' + data).hexdigest()
        assert actual == blob, f'Git blob mismatch: {label}'


def verify_sources(repo, originals, server):
    manifest = load(HERE / 'source-manifest.json')
    assert manifest['base_commit'] == BASE
    for item in manifest['git_sources']:
        data = git(repo, 'show', f'{item["commit"]}:{item["path"]}')
        identity(data, item, item['path'])
        if item['worktree_required']:
            assert (repo / item['path']).read_bytes() == data, f'Changed actual input: {item["path"]}'
    for item in manifest['originals'] + [manifest['shared_instructions']]:
        identity((originals / item['name']).read_bytes(), item, item['name'])
    external = load(HERE / 'server-source-manifest.json')
    assert external['repository'] == 'we88ec3-prog/ttr_server_roy'
    assert external['commit'] == 'e88ac0ad5fd6e911b28b1e61b6eedab3bfdfb4b4'
    assert external['tree'] == '1c42df357de7385bb0263732c9c8a33550a8f571'
    for item in external['files']:
        identity((server / item['path']).read_bytes(), item, item['path'])
    return {'git_sources': len(manifest['git_sources']), 'originals': len(manifest['originals']),
            'shared_instructions': 'MATCH', 'server_repository': external['repository'],
            'server_commit': external['commit'], 'server_files': len(external['files']),
            'server_source_bytes_and_blobs': 'MATCH', 'server_executed': False}


def verify_artifacts(repo):
    manifest = load(HERE / 'artifact-manifest.json')
    entries = manifest['files']
    expected = {i['path'] for i in entries}
    actual = {str(p.relative_to(repo)) for p in HERE.rglob('*') if p.is_file()
              and p != HERE / 'artifact-manifest.json' and p != HERE / 'verification-result.json'} | NAV
    assert expected == actual, f'Artifact set differs: {expected ^ actual}'
    docs = links = json_count = python_count = 0
    for item in entries:
        path = repo / item['path']
        assert item['path'].startswith(PACKAGE + '/') or item['path'] in NAV
        assert not path.is_symlink(), f'Unexpected symlink: {path}'
        assert path.suffix in {'.md', '.json', '.py', '.asm', '.svg', '.txt'}, f'Unexpected payload: {path}'
        data = path.read_bytes()
        identity(data, item, item['path'])
        if path.is_relative_to(HERE):
            if path.suffix == '.json':
                load(path); json_count += 1
            elif path.suffix == '.py':
                ast.parse(data.decode(), filename=str(path)); python_count += 1
            elif path.suffix == '.md':
                docs += 1
                for target in re.findall(r'\]\(([^)]+)\)', data.decode()):
                    target = target.strip().split(' "', 1)[0]
                    parsed = urlsplit(target)
                    if parsed.scheme or parsed.netloc or not parsed.path:
                        continue
                    destination = (path.parent / unquote(parsed.path)).resolve()
                    assert destination.exists(), f'Broken local link: {path.name} -> {target}'
                    links += 1
    return {'sealed_files': len(entries), 'sha256_and_sizes': 'MATCH',
            'markdown_documents': docs, 'local_link_targets': links,
            'strict_json_files': json_count, 'python_ast_files': python_count,
            'no_original_or_private_source_payloads': True}


def verify_catalog(repo):
    cp = subprocess.run([sys.executable, '-B', str(HERE / 'build_catalog.py'), '--repo', str(repo), '--check'],
                        check=True, capture_output=True, text=True)
    rebuilt = json.loads(cp.stdout)
    catalog = load(HERE / 'mef-types.json')
    assert rebuilt['status'] == 'PASS_COMPOSABLE_TYPE_CATALOG'
    assert catalog['not_a_native_file_format_count'] is True
    assert catalog['server_development_includes_mef'] is True
    assert catalog['official_format_recovery_required'] is False
    assert catalog['optional_ordinary_background_profile']['counted_as_available_route'] is False
    plan = load(HERE / 'acceptance-plan.json')
    progress = load(HERE / 'p0-progress.json')
    for document in (plan, progress):
        assert {x['id']: x['prior_feature'] for x in document['items']} == EXPECTED
        assert len(document['items']) == 8
    for row in progress['items']:
        assert row['evidence'] and row['remaining']
        assert row['new_implementation_or_deployment_claimed'] is False
        for path in row['evidence']:
            assert (HERE / path).is_file(), path
    return {'requested_items': 8, 'numbering': 'P0-3..10 / original L03..08,L10,L13',
            **catalog['counts'], 'optional_client_gaps_retained': True,
            'new_runtime_pass_claimed': False}


def verify_subtopics(repo, originals, server):
    results = {}
    with tempfile.TemporaryDirectory(prefix='mef-p0-level-readonly-') as tmp:
        for name in ['actors-combat', 'rules-scheduling', 'gates-transitions']:
            receipt = Path(tmp) / f'{name}.json'
            script = 'verify.py' if name == 'gates-transitions' else 'verify_evidence.py'
            command = [sys.executable, '-B', str(HERE / name / script),
                       '--repo', str(repo), '--sources', str(originals),
                       '--server-sources', str(server), '--receipt', str(receipt)]
            cp = subprocess.run(command, check=False, capture_output=True, text=True)
            if cp.returncode:
                raise RuntimeError(f'{name} failed ({cp.returncode})\n{cp.stdout}\n{cp.stderr}')
            fresh = load(receipt)
            status = fresh.get('status', fresh.get('result'))
            assert isinstance(status, str) and status.startswith('PASS'), f'Non-PASS child: {name}'
            results[name] = fresh
    return results


def main():
    p = argparse.ArgumentParser()
    p.add_argument('--repo', type=Path, default=HERE.parents[1])
    p.add_argument('--sources', type=Path, required=True)
    p.add_argument('--server-sources', type=Path, required=True)
    p.add_argument('--receipt', type=Path)
    args = p.parse_args()
    repo, originals, server = args.repo.resolve(), args.sources.resolve(), args.server_sources.resolve()
    assert HERE == repo / PACKAGE
    sources = verify_sources(repo, originals, server)
    artifacts = verify_artifacts(repo)
    coverage = verify_catalog(repo)
    children = verify_subtopics(repo, originals, server)
    result = {
        'schema': 'MEF_P0_LEVEL_ROOT_VERIFICATION_V1',
        'status': 'PASS_BOUNDED_P0_LEVEL_EXECUTION_ANALYSIS',
        'verified_utc': datetime.now(timezone.utc).isoformat(), 'base_commit': BASE,
        'sources': sources, 'artifacts': artifacts, 'coverage': coverage, 'subtopics': children,
        'target_executed': False, 'lua_executed': False, 'server_executed': False,
        'deployed': False, 'formal_status_changed': False,
        'scope': 'Reproduced source/native/static-content/geometry analyses with explicit remaining interfaces; not gameplay acceptance.'
    }
    text = json.dumps(result, ensure_ascii=False, indent=2) + '\n'
    if args.receipt:
        receipt = args.receipt.resolve()
        assert not receipt.is_relative_to(HERE) or receipt == HERE / 'verification-result.json', \
            'Receipt must not replace package evidence'
        receipt.parent.mkdir(parents=True, exist_ok=True)
        receipt.write_text(text)
    print(text, end='')


if __name__ == '__main__':
    main()
