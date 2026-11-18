#!/usr/bin/env python3
"""Read-only evidence replay; writes only an explicitly requested receipt.

Never starts a Server, Client, Lua interpreter, database, or network request.
The Python projection is not the Server's typed loader or tick simulation.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import sys

sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent


def require(ok, message):
    if not ok:
        raise ValueError(message)


def read_json(path):
    return json.loads(path.read_text(encoding='utf-8'))


def sha(data):
    return hashlib.sha256(data).hexdigest()


def verify_artifacts():
    manifest = read_json(HERE / 'artifact-manifest.json')
    declared = set()
    for row in manifest['files']:
        p = HERE / row['path']
        require(p.resolve().is_relative_to(HERE), 'artifact path traversal')
        require(row['path'] not in declared, 'duplicate artifact')
        declared.add(row['path'])
        data = p.read_bytes()
        require(len(data) == row['bytes'] and sha(data) == row['sha256'],
                'artifact mismatch: ' + row['path'])
    actual = {p.relative_to(HERE).as_posix() for p in HERE.rglob('*') if p.is_file()
              and '__pycache__' not in p.parts and p.suffix != '.pyc'
              and p.name not in ('artifact-manifest.json', 'verification-result.json')}
    require(actual == declared, 'undeclared or missing package file')
    require(not any(Path(p).suffix.lower() in ('.cs', '.bin', '.stp') for p in actual),
            'private implementation or original carrier entered public package')
    return len(declared)


def verify_contracts():
    evidence = read_json(HERE / 'server-code-evidence.json')
    ids = {s['id'] for s in evidence['spans']}
    require(len(ids) == len(evidence['spans']), 'duplicate source span')
    checked = 0
    def references(value):
        nonlocal checked
        if isinstance(value, dict):
            for key, item in value.items():
                if key == 'evidence':
                    require(isinstance(item, list) and set(item) <= ids, 'unknown evidence reference')
                    checked += len(item)
                else:
                    references(item)
        elif isinstance(value, list):
            for item in value:
                references(item)
    for name in ('execution-contract.json', 'extension-contracts.json', 'optimization-contracts.json'):
        references(read_json(HERE / name))
    execution = read_json(HERE / 'execution-contract.json')
    require([t['id'] for t in execution['timers']] == ['C1','C2','C3','C4','C5','C6'], 'six timer semantics')
    require(execution['duration_conversion']['status'] == 'RESOLVED_FROM_PINNED_IMPLEMENTATION', 'timer source resolution')
    require(execution['duration_conversion']['combat_deadline'] ==
            'checked(at + (long)(seconds * clock.TimestampFrequency))', 'combat conversion contract')
    require(execution['clear_gate']['all_projectile_types_are_gate'] is False, 'projectile scope')
    require(execution['clear_gate']['consumers']['functional_lab'] == 'ReadyToReturn', 'lab clear scope')
    require(set(execution['scope_completion']) == {'P0-5','P0-6','P0-7','P0-8'}, 'scope map')
    extension = read_json(HERE / 'extension-contracts.json')
    require(extension['new_server_runtime_implemented'] is False, 'extension deployment claim')
    require([x['id'] for x in extension['items']] == ['E1','E2','E3','E4','E5'], 'extension identities')
    optimization = read_json(HERE / 'optimization-contracts.json')
    require(optimization['measured_performance'] is False, 'unsupported measurement claim')
    return checked


def verify(repo, sources, server_sources):
    artifacts = verify_artifacts()
    spec = importlib.util.spec_from_file_location('p0_rules_example_replay', HERE / 'analyze_examples.py')
    analysis = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(analysis)
    actual = analysis.analyze(repo, sources, server_sources)
    expected = read_json(HERE / 'analysis-result.json')
    require(actual == expected, 'stored analysis result differs from current source replay')
    require(actual['server_or_client_or_lua_executed'] is False and actual['deployed'] is False,
            'runtime scope')
    refs = verify_contracts()
    examples = read_json(HERE / 'examples/manifest.json')
    for row in examples['files']:
        require(sha((HERE / 'examples' / row['path']).read_bytes()) == row['sha256'],
                'author manifest identity')
    geometry = actual['geometry']
    return {'schema': 'MEF_P0_RULE_VERIFICATION_RECEIPT_V1',
            'result': 'PASS_READ_ONLY_EVIDENCE_REPLAY',
            'artifact_files': artifacts, 'source_verification': actual['source_verification'],
            'contract_evidence_references': refs,
            'definition_count': actual['definition_count'], 'node_count': actual['node_count'],
            'coverage': actual['coverage'],
            'geometry_points': len(geometry),
            'route_samples': sum(x['spawn_segment']['samples'] for x in geometry),
            'circle_samples': sum(x.get('disk_samples',{}).get('samples',0) for x in geometry),
            'analysis_result_sha256': sha((HERE / 'analysis-result.json').read_bytes()),
            'artifact_manifest_sha256': sha((HERE / 'artifact-manifest.json').read_bytes()),
            'server_or_client_or_lua_executed': False,
            'server_typed_loader_executed': False, 'deployed': False,
            'formal_ledger_changed': False,
            'limits': actual['limitations']}


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--repo', type=Path, default=HERE.parents[2])
    parser.add_argument('--sources', type=Path, required=True)
    parser.add_argument('--server-sources', type=Path, required=True)
    parser.add_argument('--receipt', type=Path)
    args = parser.parse_args()
    result = verify(args.repo.resolve(), args.sources.resolve(), args.server_sources.resolve())
    text = json.dumps(result, ensure_ascii=False, indent=2) + '\n'
    if args.receipt:
        target = args.receipt.resolve()
        require(not target.is_relative_to(HERE) or target == HERE/'verification-result.json',
                'receipt cannot replace package evidence')
        target.write_text(text, encoding='utf-8')
    print(text, end='')


if __name__ == '__main__':
    main()
