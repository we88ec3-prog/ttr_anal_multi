#!/usr/bin/env python3
"""Verify the MEF end-to-end research package against original bytes and Git pins.

This tool reads the original files, this package and pinned local Git objects.
It does not fetch, modify Git, run Lua/Client/Server, transmit packets, compile
game content or grant a formal research acceptance status. JSON goes to stdout.
--recheck-prior also re-runs the already published R6/R7/R8 evidence verifiers;
its temporary Coroutine carrier is removed automatically after use.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
import tempfile
from urllib.parse import unquote

sys.dont_write_bytecode = True


def require(condition, label):
    if not condition:
        raise ValueError(label)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def blob(data):
    return hashlib.sha1(b'blob ' + str(len(data)).encode() + b'\0' + data).hexdigest()


def read_json(path):
    return json.loads(path.read_text(encoding='utf-8'))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--originals', type=Path, required=True)
    ap.add_argument('--repo', type=Path, required=True)
    ap.add_argument('--recheck-prior', action='store_true')
    args = ap.parse_args()
    repo = args.repo.resolve()
    originals = args.originals.resolve()
    package = Path(__file__).resolve().parent
    manifest = read_json(package / 'source-manifest.json')
    inventory = read_json(package / 'artifact-manifest.json')
    flow = read_json(package / 'flow-contract.json')
    prior = read_json(package / 'prior-analysis-index.json')
    env = dict(os.environ, GIT_NO_LAZY_FETCH='1', GIT_OPTIONAL_LOCKS='0',
               GIT_NO_REPLACE_OBJECTS='1', GIT_TERMINAL_PROMPT='0',
               PYTHONDONTWRITEBYTECODE='1')
    git_cmd = ['git', '-c', 'remote.origin.promisor=false',
               '-c', 'maintenance.auto=false', '-C', str(repo)]

    def git(*parts):
        return subprocess.run(git_cmd + list(parts), env=env, check=True,
                              capture_output=True).stdout

    def exists_in_tree(path):
        result = subprocess.run(git_cmd + ['cat-file', '-e',
            manifest['git']['work_parent'] + ':' + path], env=env,
            stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        return result.returncode == 0

    def repo_path(relative):
        resolved = (repo / relative).resolve()
        require(resolved.is_relative_to(repo), 'Path escapes repository: ' + relative)
        return resolved

    original_results = []
    for item in manifest['originals'] + [manifest['provided_instructions']]:
        payload = (originals / item['file']).read_bytes()
        require(len(payload) == item['bytes'] and sha(payload) == item['sha256'],
                'Original identity: ' + item['file'])
        original_results.append(item['file'])

    g = manifest['git']
    parents = git('show', '-s', '--format=%P', g['work_parent']).decode().strip().split()
    require(parents == [g['published_r8_commit'], g['main_baseline']],
            'Recorded merge has the actual two parents')
    require(git('rev-parse', g['published_r8_commit'] + '^{tree}').decode().strip()
            == g['published_r8_tree'], 'Published R8 preserves the original research tree')
    require(git('rev-parse', g['work_parent'] + '^{tree}').decode().strip()
            == g['published_merge_tree'], 'Published merge preserves the original merged tree')
    require(git('show', '-s', '--format=%P', g['published_r8_commit']).decode().strip()
            == g['initial_remote_branch'], 'Published R8 retains the remote branch parent')
    for ancestor in [g['main_baseline'], g['published_r8_commit'], g['initial_remote_branch']]:
        git('merge-base', '--is-ancestor', ancestor, g['work_parent'])
    require(git('merge-base', g['published_r8_commit'], g['main_baseline']).decode().strip()
            == g['merge_base'], 'Pinned historical merge base')

    files = inventory['files']
    recorded_paths = set()
    for item in files:
        rel = item['path']
        require(rel == manifest['primary_report'] or rel.startswith(manifest['package_path'] + '/'),
                'Artifact belongs to this research scope: ' + rel)
        require(rel not in recorded_paths, 'Duplicate artifact path: ' + rel)
        recorded_paths.add(rel)
        payload = repo_path(rel).read_bytes()
        require(len(payload) == item['bytes'] and sha(payload) == item['sha256'],
                'Artifact identity: ' + rel)
    excluded = set(inventory['excluded_self_or_generated_paths'])
    actual_paths = {p.relative_to(repo).as_posix() for p in package.rglob('*') if p.is_file()}
    actual_paths.add(manifest['primary_report'])
    require(actual_paths - excluded == recorded_paths, 'Complete package file inventory')
    require(not any(p.endswith(('.bin', '.exe', '.stp', '.lua', '.seq', '.mef', '.pyc'))
                    for p in actual_paths), 'No raw originals or deployable game resources in deliverable')

    pins = []
    pins.extend(read_json(package / 'governance-source-pins.json'))
    pins.extend(prior['prior_primary_reports'])
    pins.extend(prior['detailed_reused_sources'])
    entry_source = read_json(package / 'entry/source-manifest.json')
    pins.extend(entry_source['references'])
    pins.append(entry_source['coroutine_original'])
    pins.extend(read_json(package / 'runner/source-manifest.json')['source_pins'])
    pins.extend(read_json(package / 'world/source-manifest.json')['git_sources'])
    normalized = {}
    for p in pins:
        key = (p['commit'], p['path'])
        identity = dict(commit=p['commit'], path=p['path'],
            git_blob=p.get('git_blob', p.get('blob')), sha256=p['sha256'],
            bytes=p.get('bytes', p.get('size')))
        require(identity['git_blob'] and identity['bytes'] is not None,
                'Complete source identity: ' + p['path'])
        if key in normalized:
            require(normalized[key] == identity, 'Conflicting source pin: ' + str(key))
        normalized[key] = identity
    cache = {}
    for p in normalized.values():
        resolved = git('rev-parse', p['commit'] + ':' + p['path']).decode().strip()
        require(resolved == p['git_blob'], 'Commit/path/blob identity: ' + p['path'])
        if resolved not in cache:
            cache[resolved] = git('cat-file', 'blob', resolved)
        payload = cache[resolved]
        require(blob(payload) == resolved and len(payload) == p['bytes']
                and sha(payload) == p['sha256'], 'Source contents: ' + p['path'])

    # A public-surface index is a reuse of the original pinned binding table,
    # not a new native discovery or an exhaustive semantic audit of every API.
    public = read_json(package / 'runner/public-surface-review.json')
    ps = public['source']
    raw = git('show', ps['commit'] + ':' + ps['path'])
    require(sha(raw) == ps['sha256'], 'Public-surface original source hash')
    source_bindings = json.loads(raw)
    require(len(public['q_public_bindings']) == len(source_bindings['q_regular_bindings']) == 63,
            'Exactly 63 regular Q bindings reused')
    native_records = {x['id'] for x in read_json(package / 'runner/native-windows.json')['records']}
    for copied, source in zip(public['q_public_bindings'], source_bindings['q_regular_bindings']):
        expected = dict(name=source['strings'][0]['value'], native=source['stores'][0]['value'],
                        registrar=source['registrar'], closure=source['callbacks'][0]['callback'])
        require(all(copied[k] == v for k, v in expected.items()), 'Q binding reuse: ' + copied['name'])
        window = copied.get('direct_bin_window_for_missing_bulk_body')
        if window:
            require(window in native_records, 'Missing-body native evidence: ' + copied['name'])

    allowed = {'CLIENT_CONFIRMED_BOUNDED', 'DESIGN_CONDITIONAL', 'SERVER_DEVELOPMENT'}
    stages = {x['id']: x for x in flow['stages']}
    require(len(stages) == len(flow['stages']), 'Unique flow stages')
    require(flow['original_sha256'] == manifest['originals'][0]['sha256'], 'Flow original BIN identity')
    require(flow['work_parent'] == g['work_parent'] == prior['work_parent'], 'Shared work-parent identity')
    for s in stages.values():
        require(s['classification'] in allowed and s['owner'] and s['preconditions'] and s['limits'],
                'Explicit stage classification and limits: ' + s['id'])
        require(repo_path(s['evidence']).is_file() or exists_in_tree(s['evidence']),
                'Flow source exists: ' + s['evidence'])
    adjacency = {key: set() for key in stages}
    for edge in flow['edges']:
        require(edge['source'] in stages and edge['target'] in stages and edge['condition'],
                'Defined conditional flow edge')
        adjacency[edge['source']].add(edge['target'])
    visited, todo = {'deliver'}, ['deliver']
    while todo:
        for target in adjacency[todo.pop()] - visited:
            visited.add(target)
            todo.append(target)
    require(visited == set(stages), 'Every stated flow stage is reachable in analysis graph')
    require(stages['new_module']['classification'] == 'DESIGN_CONDITIONAL', 'New caller remains a design')
    require(flow['original_mef_entry']['classification'] == 'CLIENT_UNRESOLVED', 'Native MEF first caller remains open')
    require(flow['ordinary_gameplay']['classification'] == 'CLIENT_UNRESOLVED'
            and len(flow['ordinary_gameplay']['required_joins']) == 3, 'Ordinary gameplay joins remain open')
    require(all(value is False for value in flow['validation'].values()), 'No execution/deployment/formal acceptance asserted')

    link_count, tree_links = 0, set()
    for item in files:
        if not item['path'].endswith('.md'):
            continue
        source = repo_path(item['path'])
        for match in re.finditer(r'\[[^\]\n]*\]\(([^)\n]+)\)', source.read_text(encoding='utf-8')):
            target = match.group(1).split('#', 1)[0]
            if not target or re.match(r'^[A-Za-z][A-Za-z0-9+.-]*:', target):
                continue
            target_path = (source.parent / unquote(target)).resolve()
            require(target_path.is_relative_to(repo), 'Markdown link stays in repository: ' + target)
            rel = target_path.relative_to(repo).as_posix()
            if not target_path.exists():
                require(exists_in_tree(rel), 'Markdown target absent: ' + item['path'] + ' -> ' + target)
                tree_links.add(rel)
            link_count += 1

    def run(script, options):
        result = subprocess.run([sys.executable, '-B', str(script)] + [str(x) for x in options],
                                env=env, cwd=repo, capture_output=True, text=True)
        require(result.returncode == 0,
                'Verifier failed: ' + str(script) + '\n' + result.stdout[-5000:] + result.stderr[-5000:])
        parsed = json.loads(result.stdout)
        require(parsed['status'] == 'PASS', 'Subgroup did not pass: ' + str(script))
        return parsed

    groups = {}
    for name in ['entry', 'runner', 'world']:
        options = ['--bin', originals / '02-Tartaros.bin', '--repo', repo]
        if name != 'runner':
            options += ['--event-stp', originals / '06-Event.stp']
        groups[name] = run(package / name / 'verify_evidence.py', options)
        saved = read_json(package / name / 'verification-result.json')
        require(groups[name] == saved, 'Current subgroup result equals recorded output: ' + name)

    previous = {}
    names = {'r6': 'MEF-runtime-contracts-20261115', 'r7': 'MEF-world-integration-20261115',
             'r8': 'MEF-content-contracts-20261116'}
    for key in names:
        saved = read_json(package / ('previous-' + key + '-verification.json'))
        require(saved['status'] == 'PASS', 'Recorded baseline PASS: ' + key)
        previous[key] = dict(recorded_status=saved['status'], rechecked_this_run=False,
                            artifact_files=saved['artifact_files'], source_pins=saved['unique_commit_path_pins'])
    if args.recheck_prior:
        carrier = entry_source['coroutine_original']
        payload = cache[carrier['git_blob']]
        with tempfile.TemporaryDirectory(prefix='mef-r9-verifier-') as temp:
            coroutine_path = Path(temp) / 'Coroutine-original.bin'
            coroutine_path.write_bytes(payload)
            for key, folder in names.items():
                options = ['--originals', originals, '--repo', repo]
                if key == 'r6':
                    options += ['--coroutine', coroutine_path]
                result = run(repo / 'kr-extra-roy' / folder / 'verify_evidence.py', options)
                saved = read_json(package / ('previous-' + key + '-verification.json'))
                require(result == saved, 'Baseline result equals recorded full output: ' + key)
                previous[key]['rechecked_this_run'] = True

    output = dict(status='PASS',
        scope='Read-only original-byte, pinned source, package integrity and bounded structural-contract checks. No Client/Lua/Server execution or formal semantic certification.',
        git=g, original_identities=original_results,
        artifact_files=len(files), unique_commit_path_pins=len(normalized), unique_source_blobs=len(cache),
        source_commits=sorted({key[0] for key in normalized}),
        flow=dict(stages=len(stages), conditional_edges=len(flow['edges']), failure_boundaries=len(flow['failure_boundaries'])),
        q_public_bindings_reused=63,
        markdown_links=dict(checked=link_count, sparse_tree_only_targets=sorted(tree_links)),
        subgroup_results=groups, previous_rounds=previous,
        client_executed=False, lua_executed=False, server_executed=False,
        network_transmitted=False, game_resources_modified=False,
        limits=['Evidence-window counts are not whole-program coverage',
                'Original MapList MEF first caller and ordinary gameplay integration remain open',
                'New lexical-phase caller is a conditional design, not a deployed game resource',
                'PASS is not T01 FULL-PASS, RR ACCEPTED, SPEC STABLE, server implementation or gameplay acceptance'])
    print(json.dumps(output, ensure_ascii=False, indent=2))


if __name__ == '__main__':
    try:
        main()
    except (ValueError, KeyError, OSError, subprocess.CalledProcessError) as error:
        print(json.dumps(dict(status='FAIL', error=str(error)), ensure_ascii=False, indent=2), file=sys.stderr)
        sys.exit(1)
