#!/usr/bin/env python3
"""Read-only verifier for the R11 MEF capabilities research package.

Checks supplied original identities, fixed local Git sources, the complete
publication allowlist, all 121 normal binding tuples, qbase helper metadata,
four sub-verifiers, shared native bytes and documented flow classifications.
No network, Git mutation, original extraction, Lua/Client/Server execution or
game resource generation. JSON goes to stdout. PASS is bounded static evidence,
not gameplay, full native MEF format recovery or formal project acceptance.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
from urllib.parse import unquote
sys.dont_write_bytecode = True


def require(ok, why):
    if not ok:
        raise ValueError(why)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def blob_sha(data):
    return hashlib.sha1(b'blob ' + str(len(data)).encode() + b'\0' + data).hexdigest()


def load(path):
    return json.loads(path.read_text())


def num(value):
    return int(value, 0) if isinstance(value, str) else value


def normalize_binding(row):
    keys = ('namespace', 'name', 'registrar', 'root', 'slot', 'native', 'name_va', 'closure')
    return {key: row[key] for key in keys} | {'call_site': row.get('call_site', row.get('callsite'))}


class PE:
    def __init__(self, data):
        self.data = data
        require(data[:2] == b'MZ', 'DOS signature')
        pe = struct.unpack_from('<I', data, 0x3c)[0]
        require(data[pe:pe + 4] == b'PE\0\0', 'PE signature')
        machine, count = struct.unpack_from('<HH', data, pe + 4)
        optional_size = struct.unpack_from('<H', data, pe + 20)[0]
        opt = pe + 24
        require(machine == 0x14c and struct.unpack_from('<H', data, opt)[0] == 0x10b, 'Original i386 PE32')
        self.base = struct.unpack_from('<I', data, opt + 28)[0]
        self.sections = []
        for index in range(count):
            section = opt + optional_size + index * 40
            virtual_size, rva, raw_size, raw_offset = struct.unpack_from('<IIII', data, section + 8)
            self.sections.append((self.base + rva, raw_size, raw_offset))

    def raw(self, va, size):
        for start, raw_size, offset in self.sections:
            if start <= va and va + size <= start + raw_size:
                return offset + va - start
        raise ValueError('VA lacks raw backing: ' + hex(va))

    def at(self, va, size):
        offset = self.raw(va, size)
        return self.data[offset:offset + size]

    def cstr(self, va):
        offset = self.raw(va, 1)
        end = self.data.index(0, offset)
        return self.data[offset:end].decode('ascii')


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--originals', type=Path, required=True)
    parser.add_argument('--repo', type=Path, required=True)
    parser.add_argument('--recheck-r10', action='store_true', help='Repeat the already saved R10 rerun; does not recursively repeat R9')
    args = parser.parse_args()
    repo = args.repo.resolve()
    originals = args.originals.resolve()
    package = Path(__file__).resolve().parent
    manifest = load(package / 'source-manifest.json')
    inventory = load(package / 'artifact-manifest.json')
    flow = load(package / 'flow-contract.json')
    index = load(package / 'capability-index.json')
    groups = ['control', 'audiovisual', 'dialogue-ui', 'world-npc']
    env = dict(os.environ, GIT_NO_LAZY_FETCH='1', GIT_OPTIONAL_LOCKS='0', GIT_NO_REPLACE_OBJECTS='1', GIT_TERMINAL_PROMPT='0', PYTHONDONTWRITEBYTECODE='1')
    git_cmd = ['git', '-c', 'remote.origin.promisor=false', '-c', 'maintenance.auto=false', '-C', str(repo)]

    def git(*parts):
        return subprocess.run(git_cmd + list(parts), env=env, capture_output=True, check=True).stdout

    def repo_path(rel):
        path = (repo / rel).resolve()
        require(path.is_relative_to(repo), 'Path escapes repository: ' + rel)
        return path

    def exists(rel):
        if repo_path(rel).exists():
            return True
        return subprocess.run(git_cmd + ['cat-file', '-e', manifest['git']['work_parent'] + ':' + rel], env=env, stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL).returncode == 0

    original_names = []
    for original in manifest['originals'] + [manifest['provided_instructions']]:
        data = (originals / original['file']).read_bytes()
        require(len(data) == original['bytes'] and sha(data) == original['sha256'], 'Original identity: ' + original['file'])
        original_names.append(original['file'])
    g = manifest['git']
    require(g['repository'] == 'we88ec3-prog/ttr_anal_multi' and g['branch'] == 'extra/roy1', 'Authorized existing destination')
    require(g['new_branch_created'] is False and g['formal_task_statuses_modified'] is False, 'Branch and governance boundaries')
    require(git('rev-parse', g['work_parent'] + '^{tree}').decode().strip() == g['work_parent_tree'], 'Fixed public R10 parent tree')
    git('merge-base', '--is-ancestor', g['main_baseline'], g['work_parent'])
    require(g['main_already_ancestor'] is True, 'Synchronized main baseline')

    recorded = set()
    for artifact in inventory['files']:
        rel = artifact['path']
        require(rel == manifest['primary_report'] or rel.startswith(manifest['package_path'] + '/'), 'Owned deliverable scope')
        require(rel not in recorded, 'Duplicate artifact path')
        recorded.add(rel)
        data = repo_path(rel).read_bytes()
        require(len(data) == artifact['bytes'] and sha(data) == artifact['sha256'], 'Artifact identity: ' + rel)
        require(b'\0' not in data, 'Only text research artifacts: ' + rel)
        data.decode('utf-8')
    excluded = set(inventory['excluded_self_or_generated_paths'])
    require(excluded == {manifest['package_path'] + '/artifact-manifest.json', manifest['package_path'] + '/verification-result.json'}, 'Only inventory self and aggregate generated output excluded')
    actual = {p.relative_to(repo).as_posix() for p in package.rglob('*') if p.is_file()}
    actual.add(manifest['primary_report'])
    require(actual - excluded == recorded and excluded <= actual, 'Exact complete publication allowlist')
    require(all(Path(path).suffix in {'.md', '.json', '.asm', '.py'} for path in actual), 'Only analysis, excerpts and verifiers')
    require(not any('/_work/' in path or '/__pycache__/' in path for path in actual), 'No work/cache/full unpack directory')
    require(manifest['publication']['user_authorized'] is True, 'Recorded explicit publication authorization')
    require(all(manifest['publication'][key] is False for key in ('raw_originals_included', 'full_unpacked_resources_included', 'new_deployable_game_resources_included')), 'Publication exclusions retained')

    subgroup_sources = {name: load(package / name / 'source-manifest.json') for name in groups}
    pins = list(manifest['references'])
    pins += subgroup_sources['control']['references'] + [subgroup_sources['control']['parser_source']]
    pins += subgroup_sources['audiovisual']['references'] + [subgroup_sources['audiovisual']['parser_source']]
    pins += subgroup_sources['dialogue-ui']['git_pins']
    pins += subgroup_sources['world-npc']['pins']
    normalized = {}
    for pin in pins:
        p = dict(commit=pin['commit'], path=pin['path'], git_blob=pin.get('git_blob', pin.get('git_blob_sha1', pin.get('blob'))), bytes=pin.get('bytes', pin.get('size')), sha256=pin['sha256'])
        require(p['git_blob'] and p['bytes'] is not None, 'Complete source identity')
        require(p['commit'] in {g['main_baseline'], g['work_parent']}, 'Direct sources fixed to public main or R10')
        key = (p['commit'], p['path'])
        if key in normalized:
            require(normalized[key] == p, 'Consistent overlapping source pin: ' + p['path'])
        normalized[key] = p
    source_blobs = {}
    for pin in normalized.values():
        identity = git('rev-parse', pin['commit'] + ':' + pin['path']).decode().strip()
        require(identity == pin['git_blob'], 'Source path/blob: ' + pin['path'])
        if identity not in source_blobs:
            source_blobs[identity] = git('cat-file', 'blob', identity)
        data = source_blobs[identity]
        require(len(data) == pin['bytes'] and sha(data) == pin['sha256'] and blob_sha(data) == identity, 'Source bytes: ' + pin['path'])

    def pinned_json(path):
        return json.loads(source_blobs[normalized[(g['work_parent'], path)]['git_blob']])

    previous = load(package / 'previous-r10-verification.json')
    expected_previous = pinned_json('kr-extra-roy/MEF-control-flow-20261116/verification-result.json')
    expected_previous['previous_r9']['rechecked_this_invocation'] = False
    require(previous == expected_previous and previous['status'] == 'PASS', 'Saved actual R10 rerun agrees with public result except explicit recursive-rerun flag')

    baseline_path = 'kr-extra-roy/MEF-control-flow-20261116/world/bindings.json'
    old_rows = pinned_json(baseline_path)['rows']
    original_bindings = {row['full_name']: normalize_binding(row) for row in old_rows}
    require(len(original_bindings) == 109, 'R10 normal binding baseline')
    for group in groups:
        document = load(package / group / 'bindings.json')
        for row in document.get('rows', document.get('members', [])):
            name = row['namespace'] + '.' + row['name']
            normalized_row = normalize_binding(row)
            if name in original_bindings:
                require(original_bindings[name] == normalized_row, 'No contradictory subgroup binding: ' + name)
            else:
                original_bindings[name] = normalized_row
    require(index['total_bindings'] == len(index['rows']) == len(original_bindings) == 121, 'All 121 names covered exactly once')
    require(index['counts'] == dict(Q=63, Tutorial=31, lb=14, Prolog=1, CameraWorks=5, ScenarioTalkTable=5, Fade=2), 'Seven enumerated registration roots')
    require(index['counts'] == {namespace: sum(row['binding']['namespace'] == namespace for row in index['rows']) for namespace in index['counts']}, 'Namespace counts derived from actual indexed rows')
    require(index['rebind_is_gameplay_capability'] is False, 'Rebind excluded from gameplay count')
    pe = PE((originals / '02-Tartaros.bin').read_bytes())
    require(index['source_bin_sha256'] == sha(pe.data), 'Capability index original identity')
    names = set()
    for row in index['rows']:
        name = row['full_name']
        require(name not in names and name in original_bindings, 'Unique known binding: ' + name)
        names.add(name)
        binding = row['binding']
        require(binding == original_bindings[name], 'Indexed binding tuple: ' + name)
        require(name == binding['namespace'] + '.' + binding['name'], 'Binding qualified name')
        require(row['capability'] and row['conditions_and_limits'] and row['evidence'], 'Capability description has limits and evidence')
        registrar = num(binding['registrar'])
        call = num(binding['call_site'])
        instruction = pe.at(call, 5)
        require(instruction[0] == 0xe8 and call + 5 + struct.unpack_from('<i', instruction, 1)[0] == registrar, 'Original registration caller: ' + name)
        require(pe.at(registrar + 0x18, 10) == b'\xc7\x05' + struct.pack('<II', num(binding['slot']), num(binding['native'])), 'Original target assignment: ' + name)
        require(pe.at(registrar + 0x69, 5) == b'\x68' + struct.pack('<I', num(binding['closure'])), 'Original closure push: ' + name)
        require(pe.cstr(num(binding['name_va'])) == binding['name'], 'Original member name: ' + name)
        require(b'\x68' + struct.pack('<I', num(binding['name_va'])) in pe.at(registrar, 153), 'Original name push: ' + name)
        for evidence in row['evidence']:
            rel = (package / evidence).resolve().relative_to(repo).as_posix()
            require(exists(rel), 'Capability evidence link: ' + name)
    require(names == set(original_bindings), 'Complete capability names, without invented binding')
    stubs = {'Q.DeleteObject': (0x476430, 'c20400'), 'Q.BalloonTalk': (0x550450, 'c20800'), 'lb.PrintCurrSceneID': (0x5f5d10, 'c3'), 'Tutorial.InsertObject': (0x476430, 'c20400')}
    for name, (va, encoded) in stubs.items():
        require(num(original_bindings[name]['native']) == va and pe.at(va, len(bytes.fromhex(encoded))).hex() == encoded, 'Actual entry stub: ' + name)
    require({r['full_name'] for r in index['rows'] if r['status'] == 'ENTRY_STUB'} == set(stubs), 'All four stubs separately classified')
    require({r['full_name'] for r in index['rows'] if r['status'] == 'NOT_A_COUNT_QUERY'} == {'lb.GetObjectCount'}, 'GetObjectCount is not promoted to count query')
    require(all(r['status'] in {'CONFIRMED_BOUNDED', 'ENTRY_STUB', 'NOT_A_COUNT_QUERY'} for r in index['rows']), 'Bounded capability classifications')
    helper_index = load(package / 'control/helper-index.json')
    require(len(helper_index['exports']) == 75 and len({r['name'] for r in helper_index['exports']}) == 75, 'All qbase root exports indexed')
    catalog = (package / 'capability-catalog.md').read_text()
    helper_catalog = (package / 'helper-catalog.md').read_text()
    require(all(len(re.findall(r'^\| `' + re.escape(name) + r'` \|', catalog, re.M)) == 1 for name in names), 'Human catalog covers each binding exactly once')
    require(all(len(re.findall(r'^\| `' + re.escape(row['name']) + r'` \|', helper_catalog, re.M)) == 1 for row in helper_index['exports']), 'Human helper catalog covers all 75 names')

    stages = {stage['id']: stage for stage in flow['stages']}
    require(len(stages) == len(flow['stages']) == 12 and flow['work_parent'] == g['work_parent'], 'Twelve unique flow stages and fixed parent')
    for stage in stages.values():
        require(stage['classification'] in {'CLIENT_CONFIRMED_BOUNDED', 'DESIGN_CONDITIONAL', 'SERVER_DEVELOPMENT'} and stage['owner'] and stage['preconditions'] and stage['limits'], 'Classified stage with owner and conditions')
        require(exists((package / stage['evidence']).resolve().relative_to(repo).as_posix()), 'Flow evidence: ' + stage['id'])
    adjacent = {name: set() for name in stages}
    for edge in flow['edges']:
        require(edge['source'] in stages and edge['target'] in stages and edge['condition'], 'Conditional flow edge')
        adjacent[edge['source']].add(edge['target'])
    reachable = {'content'}
    pending = ['content']
    while pending:
        for target in adjacent[pending.pop()] - reachable:
            reachable.add(target)
            pending.append(target)
    require(reachable == set(stages), 'All described stages reachable')
    require(all(stages[name]['classification'] == 'DESIGN_CONDITIONAL' for name in ('module', 'supervisor', 'cleanup')), 'New adapters and cleanup policy remain designs')
    require(all(stages[name]['classification'] == 'SERVER_DEVELOPMENT' for name in ('content', 'commit')), 'Server development requirements explicit')
    require(flow['original_mef_entry']['classification'] == 'CLIENT_UNRESOLVED', 'Original first entry/format not silently promoted')
    require(flow['acceptance']['requires_total_ordinary_battle_replacement'] is False, 'User capability objective retained')
    require(all(value is False for value in flow['validation'].values()), 'No execution or formal acceptance claim')

    link_count = 0
    tree_only = set()
    for rel in sorted(recorded):
        if not rel.endswith('.md'):
            continue
        source = repo_path(rel)
        for target in re.findall(r'\[[^\]\n]*\]\(([^)\n]+)\)', source.read_text()):
            target = target.split('#', 1)[0]
            if not target or re.match(r'^[A-Za-z][A-Za-z0-9+.-]*:', target):
                continue
            target_path = (source.parent / unquote(target)).resolve()
            require(target_path.is_relative_to(repo), 'Markdown link stays in repository')
            linked = target_path.relative_to(repo).as_posix()
            require(exists(linked), 'Missing Markdown link: ' + rel + ' -> ' + target)
            if not target_path.exists():
                tree_only.add(linked)
            link_count += 1

    def run(script, options):
        result = subprocess.run([sys.executable, '-B', str(script)] + [str(x) for x in options], env=env, cwd=repo, capture_output=True, text=True)
        require(result.returncode == 0, 'Verifier failed: ' + str(script) + '\n' + result.stdout[-5000:] + result.stderr[-5000:])
        parsed = json.loads(result.stdout)
        require(parsed['status'] == 'PASS', 'Sub-verifier status: ' + str(script))
        return parsed

    def subgroup(name):
        if name == 'dialogue-ui':
            options = ['--originals', originals, '--repo', repo]
        else:
            options = ['--bin', originals / '02-Tartaros.bin', '--repo', repo]
            if name == 'world-npc':
                options += ['--table', originals / '07-Table.stp']
            else:
                options += ['--event-stp', originals / '06-Event.stp']
        result = run(package / name / 'verify_evidence.py', options)
        require(result == load(package / name / 'verification-result.json'), 'Actual subgroup result equals saved output: ' + name)
        return result

    subgroup_results = {}
    with ThreadPoolExecutor(max_workers=4) as pool:
        jobs = {pool.submit(subgroup, name): name for name in groups}
        for job in as_completed(jobs):
            subgroup_results[jobs[job]] = job.result()
    subgroup_results = {name: subgroup_results[name] for name in sorted(subgroup_results)}
    if args.recheck_r10:
        repeated = run(repo / 'kr-extra-roy/MEF-control-flow-20261116/verify_evidence.py', ['--originals', originals, '--repo', repo])
        require(repeated == previous, 'Repeated R10 result matches saved actual rerun')

    # Every group proves its own decode. Compare overlapping native bytes and
    # instruction boundaries across groups without treating repeated ranges as
    # new coverage. Dialogue keeps code and data records in separate arrays.
    instructions = {}
    instruction_owner = {}
    byte_map = {}
    native_counts = {}
    for group in groups:
        native = load(package / group / 'native-windows.json')
        records = native.get('records', native.get('windows', []))
        if group == 'dialogue-ui':
            records = records + native['data']
        native_counts[group] = dict(records=len(records),code_windows=sum(bool(r.get('instructions')) for r in records),bytes_with_overlap=sum(r['length'] for r in records),instructions_with_overlap=sum(len(r.get('instructions', [])) for r in records))
        for record in records:
            start = num(record.get('va', record.get('start')))
            raw = bytes.fromhex(record['hex'])
            require(len(raw) == record['length'] and sha(raw) == record['sha256'], 'Native excerpt internal hash: ' + group + '/' + record['id'])
            require(pe.at(start, len(raw)) == raw, 'Native excerpt against original: ' + group + '/' + record['id'])
            for offset, byte in enumerate(raw):
                va = start + offset
                if va in byte_map:
                    require(byte_map[va] == byte, 'Cross-group raw byte conflict: ' + hex(va))
                byte_map[va] = byte
            for instruction in record.get('instructions', []):
                va = num(instruction['va'])
                extent = len(bytes.fromhex(instruction['hex']))
                boundary = (va, va + extent, instruction['hex'])
                for location in range(va, va + extent):
                    if location in instruction_owner:
                        require(instruction_owner[location] == boundary, 'Overlapping instruction boundary conflict: ' + hex(va))
                    instruction_owner[location] = boundary
                if va in instructions:
                    require(instructions[va] == instruction['hex'], 'Cross-group instruction conflict: ' + hex(va))
                instructions[va] = instruction['hex']

    result = dict(status='PASS',scope='Read-only original identities, fixed Git provenance, complete publication integrity, native registration and cross-group evidence consistency; not runtime or formal acceptance',git=g,original_identities=original_names,artifact_files=len(recorded),total_deliverable_files=len(actual),unique_commit_path_pins=len(normalized),unique_source_blobs=len(source_blobs),source_commits=sorted({pin['commit'] for pin in normalized.values()}),capabilities=dict(binding_names=121,namespace_counts=index['counts'],stub_names=sorted(stubs),unreliable_count_query='lb.GetObjectCount',qbase_root_exports=75,rebind_counted_as_gameplay=False),flow=dict(stages=len(stages),conditional_edges=len(flow['edges']),requires_total_ordinary_battle_replacement=False),markdown_links=dict(checked=link_count,sparse_tree_only_targets=sorted(tree_only)),native_summary=native_counts,unique_native_instruction_starts=len(instructions),unique_excerpted_native_bytes=len(byte_map),subgroup_results=subgroup_results,previous_r10=dict(recorded_status=previous['status'],saved_rerun_sha256=sha((package/'previous-r10-verification.json').read_bytes()),compared_to_pinned_public_result=True,rechecked_this_invocation=args.recheck_r10,earlier_rounds_recursively_repeated=False),client_executed=False,lua_executed=False,server_executed=False,game_resources_modified=False,limits=manifest['coverage_notes']+['Counts are bounded surfaces and selected excerpts, not independent features or whole-program semantic coverage','PASS is not T01 FULL-PASS, RR ACCEPTED, implemented Server or gameplay validation'])
    print(json.dumps(result, ensure_ascii=False, indent=2))


if __name__ == '__main__':
    try:
        main()
    except (ValueError, KeyError, OSError, subprocess.CalledProcessError) as error:
        print(json.dumps(dict(status='FAIL', error=str(error)), ensure_ascii=False, indent=2), file=sys.stderr)
        sys.exit(1)
