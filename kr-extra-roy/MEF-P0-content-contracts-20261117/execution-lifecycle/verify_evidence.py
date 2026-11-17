#!/usr/bin/env python3
"""Read-only verification of the P0 execution/cleanup analysis package.

Original BIN and Event data are never executed. The fixed, reviewed historical
Python reader parses STPD/Lua bytecode as data. The only executable model is the
local, clearly labelled SYN projection. This is not a Server or gameplay test.
Without --out this command only reads files and prints deterministic JSON.
"""
from pathlib import Path
import argparse
import hashlib
import importlib.util
import json
import os
import re
import struct
import subprocess
import sys

sys.dont_write_bytecode = True
BIN_SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
EVENT_SHA = '2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b'
BASE_COMMIT = 'ac7e668ef19b91f86f05074d660aba10612c9a5f'
PARSER_SHA = '8eb16bbc06940769197b2a3446c66a024a3e98d1c44f035ce69c4fee36212a56'
BOOT_SHA = 'cae368ebe57828f9201d7db7f71d95130b5dbc0d908d2d7759e4226bd3ac2bce'


def check(ok, why):
    if not ok:
        raise ValueError(why)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def num(value):
    return int(value, 0) if isinstance(value, str) else value


def readj(path):
    return json.loads(path.read_text(encoding='utf-8'))


def load_module(path, name):
    spec = importlib.util.spec_from_file_location(name, path)
    module = importlib.util.module_from_spec(spec)
    sys.modules[name] = module
    spec.loader.exec_module(module)
    return module


class PE:
    """Raw-backed PE32 mapping; objdump byte boundaries are checked in full."""
    def __init__(self, path):
        self.path = path
        self.data = path.read_bytes()
        check(len(self.data) == 12472320 and sha(self.data) == BIN_SHA,
              'Original BIN identity')
        b = self.data
        p = struct.unpack_from('<I', b, 0x3c)[0]
        o = p + 24
        check(b[:2] == b'MZ' and b[p:p+4] == b'PE\0\0', 'PE headers')
        check(struct.unpack_from('<H', b, p+4)[0] == 0x14c
              and struct.unpack_from('<H', b, o)[0] == 0x10b, 'PE32 i386')
        self.base = struct.unpack_from('<I', b, o+28)[0]
        check(self.base == 0x400000, 'PE image base')
        h = o + struct.unpack_from('<H', b, p+20)[0]
        self.sections = []
        for i in range(struct.unpack_from('<H', b, p+6)[0]):
            _, rv, rs, ro = struct.unpack_from('<IIII', b, h+40*i+8)
            self.sections.append((self.base+rv, rs, ro))

    def raw(self, va, size):
        hits = [ro+va-a for a, rs, ro in self.sections
                if a <= va and va+size <= a+rs]
        check(len(hits) == 1, 'Unique raw mapping: '+hex(va))
        return hits[0]

    def at(self, va, size):
        at = self.raw(va, size)
        return self.data[at:at+size]

    def decode(self, a, z):
        output = subprocess.check_output([
            'objdump', '-D', '-Mintel', '--insn-width=16',
            '--start-address='+hex(a), '--stop-address='+hex(z+15),
            str(self.path)], text=True)
        rows = []
        cursor = a
        for line in output.splitlines():
            m = re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)', line)
            if not m or not a <= int(m[1], 16) < z:
                continue
            va = int(m[1], 16)
            b = bytes.fromhex(m[2])
            asm = m[3].strip()
            check(va == cursor and '(bad)' not in asm
                  and b == self.at(va, len(b)), 'Continuous decode: '+hex(va))
            cursor += len(b)
            rows.append([hex(va), b.hex(), asm])
        check(cursor == z, 'Instruction endpoint: '+hex(z))
        return rows


def native_records(obj):
    for key in ('windows', 'records', 'code_windows'):
        if key in obj:
            return obj[key]
    raise ValueError('Unsupported pinned native record format')


def normalize_instructions(rows):
    out = []
    for row in rows:
        if isinstance(row, dict):
            out.append([hex(num(row['va'])), row['hex'], row.get('asm', row.get('text'))])
        else:
            out.append([hex(num(row[0])), row[1], row[2]])
    return out


def verify_sources(repo, sources):
    check(sources['source_commit'] == BASE_COMMIT, 'Fixed baseline commit')
    env = dict(os.environ, GIT_NO_LAZY_FETCH='1', GIT_OPTIONAL_LOCKS='0',
               GIT_TERMINAL_PROMPT='0', GIT_NO_REPLACE_OBJECTS='1')
    cmd = ['git', '-c', 'remote.origin.promisor=false']
    out = {}
    for source in sources['repository_sources']:
        check(source['id'] not in out, 'Unique source id')
        blob = subprocess.check_output(
            cmd+['rev-parse', BASE_COMMIT+':'+source['path']],
            cwd=repo, env=env, text=True).strip()
        check(blob == source['git_blob'], 'Git path/blob: '+source['path'])
        b = subprocess.check_output(cmd+['cat-file', 'blob', blob], cwd=repo, env=env)
        check(len(b) == source['bytes'] and sha(b) == source['sha256'],
              'Source bytes: '+source['id'])
        check(hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest() == blob,
              'Git object identity: '+source['id'])
        out[source['id']] = {'metadata': source, 'bytes': b}
    return out


def verify_native(pe, proof, pinned, root):
    check(proof['binary']['sha256'] == BIN_SHA, 'Native manifest target')
    instructions = {}
    asm_blocks = []
    for w in proof['windows']:
        a, z = num(w['va']), num(w['end_exclusive'])
        b = pe.at(a, z-a)
        check(num(w['decoding_origin']) == a, 'Decode origin: '+w['id'])
        check(w['length'] == z-a and num(w['raw_offset']) == pe.raw(a, z-a),
              'Window mapping: '+w['id'])
        check(w['hex'] == b.hex() and w['sha256'] == sha(b),
              'New window original bytes: '+w['id'])
        rows = pe.decode(a, z)
        recorded = normalize_instructions(w['instructions'])
        check(len(rows) == w['instruction_count']
              and [r[:2] for r in rows] == [r[:2] for r in recorded],
              'New window boundaries: '+w['id'])
        instructions.update({num(row[0]): row for row in rows})
        asm_blocks.append('; '+w['id']+' ['+w['role']+'] '+w['va']+'..'
                          +w['end_exclusive']+' exclusive\n'
                          +'\n'.join(f'{num(v):08X}  {h:<32} {t}' for v, h, t in recorded))
    check((root/'native-evidence.asm').read_text() == '\n\n'.join(asm_blocks)+'\n',
          'New evidence ASM transcription')
    for ref in proof['reused_windows']:
        obj = json.loads(pinned[ref['source_id']]['bytes'])
        hits = [w for w in native_records(obj) if w['id'] == ref['window_id']]
        check(len(hits) == 1, 'Unique reused native window')
        w = hits[0]
        a = num(w['va'])
        z = num(w.get('end_exclusive', w.get('end', w.get('end_va'))))
        b = pe.at(a, z-a)
        check((num(ref['va']), num(ref['end_exclusive']), ref['length']) == (a, z, z-a),
              'Reused interval: '+ref['window_id'])
        check(b.hex() == w['hex'] and sha(b) == w['sha256'] == ref['sha256'],
              'Reused original bytes: '+ref['window_id'])
        check(num(w['raw_offset'] if 'raw_offset' in w else w['raw']) == pe.raw(a, z-a),
              'Reused raw mapping')
        rows = pe.decode(a, z)
        recorded = normalize_instructions(w['instructions'])
        check(len(rows) == ref['instruction_count']
              and [r[:2] for r in rows] == [r[:2] for r in recorded],
              'Reused boundaries: '+ref['window_id'])
        instructions.update({num(row[0]): row for row in rows})
    for anchor in proof['anchors']:
        va = num(anchor['va'])
        check(va in instructions and instructions[va][1] == anchor['hex'],
              'Instruction anchor: '+anchor['id'])
    for call in proof['direct_calls']:
        va = num(call['va'])
        b = pe.at(va, 5)
        check(va in instructions and b[0] == 0xe8 and b.hex() == call['hex'],
              'Direct call instruction: '+call['id'])
        check(va+5+struct.unpack_from('<i', b, 1)[0] == num(call['target']),
              'Direct call target: '+call['id'])
    for d in proof['data']:
        va, size = num(d['va']), d['length']
        b = pe.at(va, size)
        check(num(d['raw_offset']) == pe.raw(va, size) and d['hex'] == b.hex()
              and d['sha256'] == sha(b), 'Raw data: '+d['id'])
    # Non-negotiable bounded claims: both virtual slots, shifted receiver,
    # state1 cleanup gate and reset, separate assign vs append entrypoints.
    hard = {
        0xc0c838: '60834c00', 0xc4f6b8: 'c0577a00',
        0x4c836f: '8d4808', 0x7a580c: '39731c',
        0x7a5949: '897b1c', 0x7a594c: 'c6432001',
        0x4d0fe1: '6a01', 0x561a06: '6a00',
        0xd62868: 'a83cbd00', 0xbd3ca8: '2000',
        0xbd3cba: '28002800280028002800', 0xbd3ce8: '4800',
        0x553ec0: '894620', 0x553ec9: '89462c',
        0x553c05: '8b412c', 0x553c08: '85c0', 0x553c0a: '7e35',
        0x553c22: 'da7120', 0x553c41: 'c6413800',
        0x553c45: 'c7413400000000', 0x553b79: 'c7411400000000',
        0x553c50: '793b5500843b55009a3b5500e93b5500053c5500',
        0xc10748: '403e5500', 0xc1074c: '30005600',
        0xc10750: 'e03d5500', 0xc1075c: '603b5500', 0xc1076c: '10f08000',
    }
    for va, h in hard.items():
        check(pe.at(va, len(bytes.fromhex(h))).hex() == h, 'Native obligation: '+hex(va))
    call_targets = {c['id']: num(c['target']) for c in proof['direct_calls']}
    check(call_targets['start_assign_empty'] == call_targets['setter_assign_empty'] == 0x402a70
          and call_targets['setter_append'] == 0x401fc0
          and call_targets['q_initial_immediate_init'] == 0x4d0fe0
          and call_targets['cleanup_enqueue_release'] == 0x79de00,
          'Distinct native transition targets')


def verify_lua_and_scenes(args, pinned, root):
    parser_source = pinned['parser']
    check(parser_source['metadata']['sha256'] == PARSER_SHA, 'Reviewed Python parser identity')
    parser_path = args.repo/parser_source['metadata']['path']
    check(parser_path.read_bytes() == parser_source['bytes'], 'Checked-out parser equals pinned bytes')
    parser = load_module(parser_path, 'p0_lifecycle_data_reader')
    q = readj(root/'qbase-lifecycle.json')
    check(q['carrier']['sha256'] == EVENT_SHA, 'qbase Event identity')
    archive = parser.STPD(args.event, q['carrier'])
    qbytes = archive.verify_member(q['member'])
    protos = parser.read_lua51_prototypes(qbytes)
    check(len(protos) == q['prototype_count'] == 76
          and sum(len(p['words']) for p in protos) == q['instruction_word_count'] == 906,
          'Complete data-only qbase parse')
    exports = {e['prototype']: e for e in json.loads(pinned['helper_index']['bytes'])['exports']}
    rootp = protos[0]
    for s in q['selected']:
        p = protos[s['index']]
        for key in ('params', 'code_offset', 'words', 'constants'):
            check(p[key] == s[key], 'qbase selected '+key+': '+s['name'])
        words = struct.pack('<'+'I'*len(p['words']), *p['words'])
        check(sha(words) == s['code_sha256'], 'qbase selected code SHA')
        export = exports[s['index']]
        check(all(s[k] == export[k] for k in ('name', 'root_closure_pc', 'root_setglobal_pc')),
              'qbase export metadata')
        cw = rootp['words'][s['root_closure_pc']]
        sw = rootp['words'][s['root_setglobal_pc']]
        check(cw & 63 == 36 and rootp['children'][cw >> 14] == s['index'],
              'qbase CLOSURE root binding')
        check(sw & 63 == 7 and rootp['constants'][sw >> 14] == s['name']
              and ((cw >> 6) & 255) == ((sw >> 6) & 255), 'qbase SETGLOBAL root binding')
    boot = q['numeric_bootstrap']
    bb = pinned['boot_chunk']['bytes']
    check(sha(bb) == BOOT_SHA == boot['sha256'] and len(bb) == boot['bytes'] == 179,
          'Original Boot chunk identity')
    bp = parser.read_lua51_prototypes(bb)
    check(len(bp) == boot['prototype_count'] == 1 and len(bp[0]['words']) == 11,
          'Boot data-only prototype count')
    check(bp[0]['words'][:4] == boot['selected_root_prefix_words'] == [0x4001, 7, 0xc001, 0x8007]
          and bp[0]['constants'][:4] == boot['selected_constants'] == ['TRUE', 1.0, 'FALSE', 0.0],
          'Boot numeric assignments, not Lua boolean literals')
    source_map = json.loads(pinned['source_map']['bytes'])
    def entries(value):
        if isinstance(value, dict):
            yield value
            for v in value.values():
                yield from entries(v)
        elif isinstance(value, list):
            for v in value:
                yield from entries(v)
    matches = [x for x in entries(source_map)
               if x.get('portable_path') == pinned['boot_chunk']['metadata']['path']
               and x.get('sha256') == BOOT_SHA and x.get('version') == 'kr'
               and x.get('original_path')
               == 'kr-temp-roy/T16-local-20261028/evidence/resources/kr/boot.lua']
    check(len(matches) == 1,
          'Boot source-map provenance')
    selected = readj(root/'selected-scene-lifecycle.json')
    check(selected['carrier'] == q['carrier'] and selected['deployment_ready'] is False,
          'Selected scenes use same source, not readiness promotion')
    expected = {(119, 3): (3, '05abe5f9773c3b0b40d5a849f7d984b4f06f57d2e5a5fe8c931e83ec2d7b857a'),
                (2440, 5): (14, '22131443cd236fd9498847353da3e7b8f8862f05cfab3258932e8158c9be3258')}
    check({(s['quest'], s['scene']) for s in selected['scenes']} == set(expected), 'Exact scenes')
    scene_payloads = {}
    for scene in selected['scenes']:
        payload = archive.verify_member(scene['member'])
        scene_payloads[(scene['quest'], scene['scene'])] = payload
        count, digest = expected[(scene['quest'], scene['scene'])]
        check(sha(payload) == digest, 'Selected original SEQ identity')
        lines = payload.decode('cp949').splitlines()
        check(sum(l.strip().startswith('CreateObject(') for l in lines)
              == scene['direct_create_calls'] == count, 'Selected create count')
        for statement in scene['lifecycle_statements']:
            check(lines[statement['line']-1].strip() == statement['text'],
                  'Exact bounded original lifecycle statement')
        seq = scene['lifecycle_statements']
        check([s['line'] for s in seq] == sorted(s['line'] for s in seq), 'Original statement order')
        check([s['text'] for s in seq[-6:]] == ['RevPhase4()', 'RevPhase3()', 'RevPhase2()',
              'Q.DeleteAllObject()', 'RestoreMap()', 'RevPhase1()'], 'Selected original cleanup tail')
    image = readj(root/'selected-image-contract.json')
    image_payload = scene_payloads[(image['quest'], image['scene'])]
    check(sha(image_payload) == image['member_sha256'], 'Selected image original member')
    check(image_payload.decode('cp949').splitlines()[image['line']-1].strip()
          == image['bounded_statement'], 'Selected original image invocation')
    check(image['arguments'] == {
        'path': 'Image/Prologue/Aisen00_1.dds', 'x_percent': 50, 'y_percent': 30,
        'fade_in': 100, 'hold': 100, 'fade_out': 0, 'hold_forever_integer': 0},
        'Exact selected image arguments')
    check(image['constructor_contract']['initial_fields']['+0x20_total_out'] == 0
          and image['constructor_contract']['initial_fields']['+0x2c_remaining_out'] == 0
          and image['constructor_contract']['initial_fields']['+0x30_hold'] == 100
          and image['constructor_contract']['hold_minus_one_override'] is False,
          'Selected image paired constructor counters')
    phase4 = next(p for p in image['phase_contract'] if p['phase'] == 4)
    check(phase4['remaining_out'] == 0 and num(phase4['signed_nonpositive_branch_va']) == 0x553c0a
          and num(phase4['taken_target']) == 0x553c41 and num(phase4['skipped_division_va']) == 0x553c22
          and phase4['division_by_zero_reachable_for_selected_values'] is False,
          'Selected zero fadeout JLE branch before division')
    check(image['selected_zero_fadeout_native_branch_closed'] is True
          and image['image_visible_proved'] is False and image['fixed_elapsed_time_proved'] is False
          and image['lua_completion_token_proved'] is False,
          'Finite image native branch closed without runtime promotion')
    return q, selected


def verify_contracts(root, sources, proof):
    owners = readj(root/'owner-ledger.json')
    dag = readj(root/'cleanup-order.json')
    runs = readj(root/'run-contracts.json')
    completion = readj(root/'completion-boundaries.json')
    owner_ids = [o['id'] for o in owners['owners']]
    check(len(owner_ids) == len(set(owner_ids)) == 22, 'Unique owner ledger')
    allowed_refs = {s['id'] for s in sources['repository_sources']}
    allowed_refs |= {w['id'] for w in proof['windows']}
    allowed_refs |= {'qbase-lifecycle'}
    for owner in owners['owners']:
        check(set(owner['evidence']) <= allowed_refs and owner['evidence'], 'Owner references: '+owner['id'])
        check(owner['native_run_token_proved'] is False, 'No invented native owner token')
    check(owners['runtime_readiness_proved'] is False and owners['formal_status_changed'] is False,
          'Owner status boundary')
    nodes = dag['nodes']
    check(len(nodes) == len(set(nodes)), 'Unique cleanup nodes')
    edges = [(e['before'], e['after']) for e in dag['conditional_edges']]
    check(len(edges) == len(set(edges)) == 20
          and all(a in nodes and b in nodes and a != b for a, b in edges), 'Cleanup edge domain')
    indegree = {n: 0 for n in nodes}
    for _, b in edges:
        indegree[b] += 1
    ready = [n for n in nodes if indegree[n] == 0]
    visited = []
    while ready:
        n = ready.pop()
        visited.append(n)
        for a, b in edges:
            if a == n:
                indegree[b] -= 1
                if indegree[b] == 0:
                    ready.append(b)
    check(len(visited) == len(nodes), 'Cleanup DAG acyclic')
    pair = dag['unconstrained_pair']['nodes']
    check(tuple(pair) not in edges and tuple(reversed(pair)) not in edges,
          'No invented universal actor-clear/map-restore order')
    profiles = runs['profiles']
    check({p['id'] for p in profiles} == {'finite_native_effect', 'same_run_multiphase', 'independent_runs'}
          and len(profiles) == 3, 'Three distinct run strategies')
    check(len(runs['original_scene_profiles']) == 2 and all(
        p['chosen_execution_profile'] == 'EXISTING_SINGLE_RUN_ORIGINAL_FLOW'
        for p in runs['original_scene_profiles']), 'Original scenes each use their own single run')
    for p in profiles:
        check(p['selected_scene_pair'] is None and p['unresolved_for_deployment'], 'No invented concrete pair')
        check(set(p['native_deferred_work_to_account_for']) <= set(owner_ids), 'Strategy owner references')
    check({p['id'] for p in runs['pending_work_producers']} == {
        'normal_initial_q_create', 'selected_item_update', 'conditional_non_immediate_request', 'queued_release'},
        'Explicit conditional pending-work producers')
    producer = {p['id']: p for p in runs['pending_work_producers']}
    check(producer['normal_initial_q_create']['mode'] == 'immediate1'
          and producer['conditional_non_immediate_request']['selected_scene_reachability']
          == 'NOT_PROVED_FOR_NORMAL_INITIAL_Q_CREATE', 'Q immediate versus conditional deferred scope')
    for key in ('all_profiles_deployment_ready', 'all_profiles_gameplay_verified', 'global_queue_drain_proved',
                'official_mef_grammar_proved', 'server_implemented_this_turn'):
        check(runs[key] is False, 'No completion promotion: '+key)
    check(len(completion['obligations']) == 7
          and all(v is False for v in completion['no_completion_promotion'].values()), 'Completion boundaries')
    check(set(completion['remaining_by_layer']) == {'client_reverse_engineering', 'server_development',
          'integration', 'gameplay'}, 'Separate remaining layers')
    model = load_module(root/'reference_model.py', 'p0_lifecycle_syn')
    examples = model.run_examples(dag)
    check(len(examples) == 12 and all(e['kind'] == 'SYN' and e['pass'] for e in examples), 'SYN projections')
    return owners, dag, runs, examples


def output_path(args, root):
    if args.out is None:
        return None
    dest = args.out.resolve()
    check(dest not in {args.bin.resolve(), args.event.resolve()}, 'Cannot overwrite original source')
    check(not dest.is_relative_to(args.bin.resolve().parent)
          and not dest.is_relative_to(args.event.resolve().parent), 'Output outside original source directories')
    if dest.is_relative_to(args.repo.resolve()):
        check(dest == root/'verification-result.json', 'Only fixed lifecycle receipt may be written in repository')
    if dest.exists():
        try:
            prior = readj(dest)
        except (OSError, ValueError):
            raise ValueError('Existing output is not a lifecycle verification receipt')
        check(prior.get('schema') == 'ttr-mef-p0-lifecycle-verification-v1', 'Cannot overwrite unrelated output')
    return dest


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    for name in ('bin', 'event', 'repo'):
        ap.add_argument('--'+name, required=True, type=Path)
    ap.add_argument('--out', type=Path)
    args = ap.parse_args()
    check(not sys.flags.optimize, 'Do not disable checks with optimized Python')
    root = Path(__file__).resolve().parent
    dest = output_path(args, root)
    manifest = readj(root/'artifact-manifest.json')
    check(manifest['schema'] == 'ttr-mef-p0-lifecycle-artifacts-v1', 'Artifact manifest schema')
    names = [f['name'] for f in manifest['files']]
    check(len(names) == len(set(names)), 'Unique artifact paths')
    for item in manifest['files']:
        path = root/item['name']
        check(path.resolve().parent == root and path.name == item['name'], 'Safe direct artifact path')
        b = path.read_bytes()
        check(len(b) == item['bytes'] and sha(b) == item['sha256'], 'Artifact integrity: '+item['name'])
    expected_artifacts = {p.name for p in root.iterdir() if p.is_file()
                          and p.name not in {'artifact-manifest.json', 'verification-result.json'}}
    check(set(names) == expected_artifacts and {'verify_evidence.py', 'reference_model.py'} <= set(names),
          'Manifest covers all deliverables before execution')
    sources = readj(root/'source-manifest.json')
    pinned = verify_sources(args.repo, sources)
    pe = PE(args.bin)
    event = args.event.read_bytes()
    check(len(event) == 11241597 and sha(event) == EVENT_SHA, 'Original Event identity')
    proof = readj(root/'native-evidence.json')
    verify_native(pe, proof, pinned, root)
    q, selected = verify_lua_and_scenes(args, pinned, root)
    owners, dag, runs, examples = verify_contracts(root, sources, proof)
    result = {
        'schema': 'ttr-mef-p0-lifecycle-verification-v1', 'all_matched': True,
        'scope': 'Pinned original bytes/PE mappings/decoded boundaries, bounded calls/data, original STPD and Lua-as-data, source identities, authoring DAG and SYN projections. Not whole-function semantic acceptance, native runtime or Server implementation.',
        'source_commit': BASE_COMMIT, 'bin_sha256': BIN_SHA, 'event_sha256': EVENT_SHA,
        'new_native_windows': len(proof['windows']),
        'new_native_window_bytes': sum(w['length'] for w in proof['windows']),
        'new_native_instructions': sum(w['instruction_count'] for w in proof['windows']),
        'reused_native_windows': len(proof['reused_windows']),
        'reused_native_window_bytes': sum(w['length'] for w in proof['reused_windows']),
        'reused_native_instructions': sum(w['instruction_count'] for w in proof['reused_windows']),
        'anchors': len(proof['anchors']), 'direct_calls': len(proof['direct_calls']),
        'data_records': len(proof['data']), 'source_pins': len(pinned),
        'qbase_total_prototypes': q['prototype_count'], 'qbase_total_instruction_words': q['instruction_word_count'],
        'qbase_selected_prototypes': len(q['selected']),
        'qbase_selected_instruction_words': sum(len(p['words']) for p in q['selected']),
        'boot_prefix_instruction_words': 4,
        'selected_original_image_zero_fadeout_branch_closed': True,
        'selected_original_scenes': [{'quest': s['quest'], 'scene': s['scene'],
            'member_sha256': s['member']['decoded_sha256'], 'direct_create_calls': s['direct_create_calls'],
            'bounded_lifecycle_statements': len(s['lifecycle_statements'])} for s in selected['scenes']],
        'owners': len(owners['owners']), 'cleanup_edges': len(dag['conditional_edges']),
        'run_profiles': len(runs['profiles']), 'artifact_integrity_files': len(names),
        'synthetic_examples': examples,
        'client_executed': False, 'lua_executed': False, 'server_executed': False,
        'deployment_ready': False, 'gameplay_tested': False, 'formal_status_changed': False,
        'official_mef_grammar_proved': False, 'global_queue_drain_proved': False,
    }
    rendered = json.dumps(result, ensure_ascii=False, indent=2)+'\n'
    if dest is not None:
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_text(rendered, encoding='utf-8')
    print(rendered, end='')


if __name__ == '__main__':
    main()
