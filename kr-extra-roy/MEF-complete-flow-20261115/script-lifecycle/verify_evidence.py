#!/usr/bin/env python3
"""Read-only reconstruction of the selected Lua/native lifecycle evidence.

This parses bytes as data. It never starts Client, a Lua interpreter, or a Lua
compiler. It does not certify runtime behavior, the missing MoCo body, or a
whole-program absence of indirect loaders.
"""
import argparse
import hashlib
import importlib.util
import json
from pathlib import Path
import struct
import sys

sys.dont_write_bytecode = True


def check(ok, message):
    if not ok:
        raise ValueError(message)


def sha(data):
    return hashlib.sha256(data).hexdigest()


def read_json(path):
    return json.loads(path.read_text())


def module(name, path):
    spec = importlib.util.spec_from_file_location(name, path)
    value = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(value)
    return value


def selected_record(proto, ops):
    instructions = []
    for pc, word in enumerate(proto['words']):
        op = ops[word & 63]
        item = dict(pc=pc, chunk_offset=proto['code_offset'] + pc * 4,
                    word=f'{word:08x}', op=op, A=(word >> 6) & 255,
                    B=(word >> 23) & 511, C=(word >> 14) & 511, Bx=word >> 14)
        if op in ('LOADK', 'GETGLOBAL', 'SETGLOBAL'):
            item['constant'] = proto['constants'][word >> 14]
        if op == 'CLOSURE':
            item['child_prototype'] = proto['children'][word >> 14]
        if op == 'JMP':
            item['destination_pc'] = pc + 1 + (word >> 14) - 131071
        instructions.append(item)
    return dict(index=proto['index'], parent=proto['parent'],
                code_offset=proto['code_offset'], first_line=proto['first'],
                last_line=proto['last'], params=proto['params'], stack=proto['stack'],
                constants=proto['constants'], words=proto['words'], instructions=instructions)


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--originals', required=True, type=Path)
    ap.add_argument('--repo', required=True, type=Path)
    ap.add_argument('--evidence-dir', type=Path, default=Path(__file__).resolve().parent)
    ap.add_argument('--reference-text-cache', type=Path,
                    help='Optional {repository path: exact text} for sparse checkout references')
    ap.add_argument('--out', type=Path, help='Optional result JSON outside original input paths')
    args = ap.parse_args()
    e = args.evidence_dir
    manifest = read_json(e / 'source-manifest.json')
    helper_path = args.repo / manifest['helper']['path']
    check(sha(helper_path.read_bytes()) == manifest['helper']['sha256'], 'Pinned parser identity')
    parser = module('pinned_static_parser', helper_path)
    analyzer_path = e / 'lua_call_sources.py'
    if 'analysis_helper' in manifest:
        check(sha(analyzer_path.read_bytes()) == manifest['analysis_helper']['sha256'],
              'Register-origin analyzer identity')
    analyzer = module('bounded_call_origins', analyzer_path)
    cache = read_json(args.reference_text_cache) if args.reference_text_cache else {}
    reference_checks = []
    for ref in manifest['references']:
        path = args.repo / ref['path']
        if path.is_file():
            content = path.read_bytes()
        elif ref['path'] in cache:
            content = cache[ref['path']].encode()
        else:
            reference_checks.append(dict(path=ref['path'], status='NOT_READ',
                                         reason='Sparse checkout; pinned identity remains in manifest'))
            continue
        check(len(content) == ref['bytes'] and sha(content) == ref['sha256'],
              'Reference content identity: ' + ref['path'])
        blob = hashlib.sha1(b'blob ' + str(len(content)).encode() + b'\0' + content).hexdigest()
        check(blob == ref['git_blob'], 'Reference Git blob: ' + ref['path'])
        reference_checks.append(dict(path=ref['path'], status='EXACT_CONTENT_MATCH'))

    native = read_json(e / 'native-windows.json')
    pe = parser.PE(args.originals / native['binary']['file'], native['binary'])
    for window in native['windows']:
        pe.verify_window(window)
        check(int(window['end_exclusive'], 0) == int(window['va'], 0) + window['length'],
              'Native window end ' + window['id'])

    reused_tags = [
        'parser:global_lua_ctor_and_global_DoFile',
        'parser:execution_thunk_not_error_handler',
        'parser:protected_call_restore_on_error',
        'parser:call_engine_then_VM',
        'parser:coroutine_resume_gate_and_guard',
        'parser:coroutine_yield_C_boundary_gate',
        'parser:lb_DoFile_registration',
        'executor:lua-c-result-count',
        'executor:lua-result-slot-copy',
        'executor:prepass-new-state',
        'executor:prepass-register-immediate-call',
        'executor:prepass-six-overrides-and-load',
        'executor:prepass-default-bindings',
        'executor:prepass-q-table',
        'executor:prepass-empty-callback',
        'executor:named-protected-call',
    ]
    old_dir = args.repo / 'kr-extra-roy/MEF-parser-executor-storage-20261114'
    old_native = read_json(old_dir / 'native-windows.json')
    reused = []
    for tag in reused_tags:
        record = next(w for w in old_native['windows'] if w['tag'] == tag)
        pe.verify_window(record)
        reused.append(dict(tag=tag, va=record['va'], length=record['length'], sha256=record['sha256']))
    bindings = read_json(old_dir / 'prepass-bindings.json')
    check(len(bindings['default_global_bindings']) == 72, '72 prepass default globals')
    check(len(bindings['per_load_bindings']) == 6, 'Six prepass overrides/additions')
    initial_names = {x['name'] for x in bindings['default_global_bindings'] + bindings['per_load_bindings']}
    check('DoFile' not in initial_names and 'lb' not in initial_names, 'Known initial prepass bindings')
    for rec in bindings['default_global_bindings'] + bindings['per_load_bindings']:
        text = rec['name'].encode('ascii') + b'\0'
        check(pe.at(int(rec['name_va'], 0), len(text)) == text, 'Prepass original binding name')
    check(pe.at(int(bindings['empty_callback'], 0), 3).hex() == bindings['empty_callback_bytes'],
          'Prepass wait/yield empty callback')

    native_assertions = []

    def bytes_at(va, expected, label):
        wanted = bytes.fromhex(expected)
        check(pe.at(va, len(wanted)) == wanted, label)
        native_assertions.append(dict(label=label, va=hex(va), hex=expected))

    def rel(va, prefix, target, label):
        op = bytes.fromhex(prefix)
        raw = pe.at(va, len(op) + 4)
        check(raw[:len(op)] == op, label + ' opcode')
        actual = va + len(raw) + struct.unpack_from('<i', raw, len(op))[0]
        check(actual == target, label + ' target')
        native_assertions.append(dict(label=label, va=hex(va), target=hex(target)))

    for va, expected, label in [
        (0x6f4a94, 'be01000000', 'native path loader default failure flag = 1'),
        (0x6f4bb4, '33f6', 'native path loader success flag = 0'),
        (0x6f4bb8, 'be01000000', 'native path loader parse/run failure flag = 1'),
        (0x6f4c07, '8bc6', 'native path loader returns its flag through EAX'),
        (0x891001, '3b0d201fd6007502f3c3', 'cookie normal return preserves EAX'),
        (0x6f49d6, '8944240c', 'global DoFile userdata.function = chunk stack slot'),
        (0x6f49ec, 'c744241cffffffff', 'global DoFile userdata.nresults = MULTRET'),
        (0x6f4a0a, 'c744240c00000000', 'global DoFile success value = 0'),
        (0x6f4a16, 'c744240c01000000', 'global DoFile failure value = 1'),
        (0x6f4a33, 'db44240c', 'global DoFile converts integer flag to number'),
        (0x6f4a37, 'c7400803000000dd18', 'global DoFile writes number tag and double'),
        (0x6f4a40, '83470810', 'global DoFile appends status to top'),
        (0x6f4a46, 'b801000000', 'global DoFile returns one public Lua result'),
        (0x6f5a56, '8b48048b10', 'execution thunk reads wanted results and function from userdata'),
        (0x6fe375, 'c1e0048bc88b46082bc1', 'C callback result count selects top minus count times 16'),
        (0x4a2acf, 'db4508', 'lb bridge converts native int to Lua number'),
        (0x4a2ad8, 'c7410803000000', 'lb bridge number tag'),
        (0x4a12e2, 'bfc8f3fd00', 'lb uses fixed global main wrapper'),
        (0x4a1316, '33c0', 'lb native open failure returns zero'),
        (0x6f4883, '834008f0', 'named-call failure reporter pops error value'),
        (0x6f488c, '33c0', 'named-call failure reporter returns zero'),
        (0x4ad0ff, '897b04b801000000', 'named-call success records wanted results and returns one'),
        (0x4a8baf, '83c8ff', 'Tutorial tick overwrites wrapper status with stack index minus one'),
        (0x5618ef, '897328', 'normal Q marks active before lookup/load'),
        (0x561c82, '33db', 'normal Q first post-load instruction is not status test'),
        (0x6fe55b, '66ff4634', 'nested protected call increases C depth'),
        (0x6fe70e, '406689473466894736', 'resume records C depth as yield base'),
        (0x70748b, '668b47342b770c663b4736760e', 'yield compares current depth with resume base'),
    ]:
        bytes_at(va, expected, label)
    for va, op, target, label in [
        (0x6f49f4, 'e8', 0x6fe770, 'DoFile protected execution'),
        (0x6f5a61, 'e8', 0x6fe550, 'execution thunk delegates to call engine'),
        (0x6fe380, 'e8', 0x6fe4c0, 'public C callback results copied to Lua caller'),
        (0x4a8a36, 'e8', 0x6f4a50, 'Synopsis file load'),
        (0x4a8a46, 'e8', 0x6f4dd0, 'Synopsis subsequent fixed global call'),
        (0x4a8b64, 'e8', 0x6f4a50, 'Tutorial file load'),
        (0x4a8b74, 'e8', 0x6f4dd0, 'Tutorial subsequent fixed global call'),
        (0x4a8ba6, 'e8', 0x4ad0a0, 'Tutorial tick named call'),
        (0x4a8bb2, 'e8', 0x6f50f0, 'Tutorial tick fetches current top regardless of wrapper result'),
        (0x5615d8, 'e8', 0x6f4dd0, 'Q tick named call'),
        (0x561a85, '0f84', 0x561d7f, 'normal Q missing-row exit'),
        (0x561d81, 'e8', 0x561db0, 'normal Q missing-row calls EndCutScene'),
        (0x561c7d, 'e8', 0x6f4a50, 'normal Q formal load'),
        (0x565926, '0f84', 0x565a65, 'review Q missing-row reaches epilogue'),
        (0x5659d9, 'e8', 0x6f4a50, 'review Q formal load'),
        (0x5659de, 'e8', 0x434250, 'review Q next call overwrites EAX without status branch'),
        (0x70749e, 'e8', 0x6f8b60, 'yield over C boundary raises Lua error'),
    ]:
        rel(va, op, target, label)

    st_id = next(x for x in manifest['originals'] if x['file'] == '06-Event.stp')
    st_path = args.originals / st_id['file']
    st = parser.STPD(st_path, st_id)
    raw_stp = st_path.read_bytes()
    saved_index = read_json(e / 'lua-call-source-index.json')
    saved_selected = read_json(e / 'selected-lua-evidence.json')
    observed_index = []
    raw_protos = {}
    chunk_checks = []
    for item in saved_index:
        meta = item['member']
        ident = st.files[meta['path']]
        length, first, last = st.blocks[ident]
        offset = 16 + first * 1024
        data = parser.ex_decode(st.data[offset:offset + length])
        observed_meta = dict(path=meta['path'], block_id=ident, stored_offset=offset,
                             stored_length=length, first_block=first, last_block=last,
                             raw_stored_sha256=sha(raw_stp[offset:offset + length]),
                             decoded_size=len(data), decoded_sha256=sha(data))
        check(observed_meta == meta, 'Lua member source identity: ' + meta['path'])
        protos = parser.read_lua51_prototypes(data)
        raw_protos[meta['path']] = protos
        records = [analyzer.analyze(p) for p in protos]
        observed_index.append(dict(member=meta, prototypes=records))
        selected = next(x for x in saved_selected if x['member']['path'] == meta['path'])
        check(selected['member'] == meta, 'Selected and index source identity')
        for evidence in selected['selected_prototypes']:
            check(selected_record(protos[evidence['index']], analyzer.OPS) == evidence,
                  f'Selected original operands: {meta["path"]} #{evidence["index"]}')
        raw_calls = sum((w & 63) in (28, 29) for p in protos for w in p['words'])
        origin_calls = sum(len(p['calls']) for p in records)
        check(raw_calls == origin_calls, 'All call/ tailcall instructions covered by bounded CFG')
        names = {v for p in records for c in p['calls'] for v in c['callee_origins']}
        check(all(v.startswith('global:') or v.startswith('field(global:') for v in names),
              'Selected callable origin classification')
        chunk_checks.append(dict(path=meta['path'], prototypes=len(protos),
                                 instruction_words=sum(len(p['words']) for p in protos),
                                 call_sites=origin_calls,
                                 selected_prototypes=len(selected['selected_prototypes'])))
    check(observed_index == saved_index, 'Full bounded callable-origin index reconstruction')

    by_name = {x['member']['path']: x['prototypes'] for x in observed_index}
    lua_assertions = []

    def call(path, proto, pc, origins, label):
        record = next(x for x in by_name[path][proto]['calls'] if x['pc'] == pc)
        check(record['callee_origins'] == origins, label)
        lua_assertions.append(dict(label=label, member=path, prototype=proto, pc=pc,
                                   chunk_offset=record['chunk_offset'], word=record['word']))

    q = 'Event/qbase.lua'
    base = 'Event/TutorialBase.lua'
    tutorial = 'Event/TutorialMain.lua'
    for path, proto, pc, origins, label in [
        (q, 75, 4, ['field(global:coroutine,constant:"create")'], 'formal Register creates coroutine from argument'),
        (q, 75, 5, ['global:f_registerCoroutine'], 'formal Register sends created coroutine to scheduler'),
        (q, 2, 4, ['field(global:qco,constant:"doCoTask")'], 'Q tick enters qco scheduler'),
        (q, 4, 2, ['global:wait'], 'qbase yield is wait(0), wait body remains external'),
        (q, 74, 61, ['field(global:Q,constant:"EndCutScene")'], 'RevPhase1 explicitly ends cutscene'),
        (base, 1, 5, ['field(global:tco,constant:"createCoroutine")'], 'Tutorial entry creates task'),
        (base, 1, 6, ['field(global:tco,constant:"registerCoroutine")'], 'Tutorial entry returns registration result'),
        (tutorial, 7, 18, ['global:t_removeCoroutine'], 'Synopsis skip removes selected child'),
        (tutorial, 7, 26, ['global:EndSynopsis'], 'Synopsis ordinary flow explicitly performs cleanup'),
        (tutorial, 8, 37, ['field(global:Tutorial,constant:"StopCutScene")'], 'Tutorial Part1 skip stops cutscene first'),
        (tutorial, 8, 40, ['global:t_removeCoroutine'], 'Tutorial Part1 skip then removes selected child'),
        (tutorial, 8, 76, ['global:Tutorial_Part2'], 'Tutorial Part2 is direct call in parent'),
        (tutorial, 9, 2, ['global:t_executeCoFunction'], 'Tutorial entry unconditionally requests task'),
        (tutorial, 10, 2, ['global:t_executeCoFunction'], 'Synopsis entry unconditionally requests task'),
    ]:
        call(path, proto, pc, origins, label)
    for path, proto in [(q, 2), (base, 2)]:
        c = next(x for x in by_name[path][proto]['calls'] if x['pc'] == 4)
        check(c['argument_origins'][-1] == ['field(global:Q,constant:"EndCutScene")'],
              'Scheduler receives Q.EndCutScene function value')
    tutorial_writes = {x['name'] for x in by_name[tutorial][0]['global_writes']}
    check('tco' not in tutorial_writes, 'Reload TutorialMain does not recreate tco')
    for proto in [9, 10]:
        p = raw_protos[tutorial][proto]
        check([analyzer.OPS[w & 63] for w in p['words']] == ['GETGLOBAL', 'GETGLOBAL', 'CALL', 'RETURN'],
              'Tutorial/Synopsis entry has no Lua guard branch')

    totals = dict(lua_members=len(chunk_checks), lua_prototypes=sum(x['prototypes'] for x in chunk_checks),
                  instruction_words=sum(x['instruction_words'] for x in chunk_checks),
                  callable_origin_sites=sum(x['call_sites'] for x in chunk_checks),
                  selected_prototypes=sum(x['selected_prototypes'] for x in chunk_checks),
                  evidence_windows=len(native['windows']),
                  evidence_window_bytes=sum(x['length'] for x in native['windows']),
                  reused_native_anchors=len(reused),
                  native_contract_assertions=len(native_assertions),
                  lua_contract_assertions=len(lua_assertions))
    check((totals['lua_members'], totals['lua_prototypes'], totals['instruction_words'],
           totals['callable_origin_sites'], totals['selected_prototypes']) == (3, 93, 1536, 255, 20),
          'Declared selected read-set totals')
    result = dict(status='PASS_FOR_BOUNDED_STATIC_EVIDENCE', totals=totals,
                  originals=manifest['originals'], reference_checks=reference_checks,
                  chunks=chunk_checks, reused_native_anchors=reused,
                  native_contract_assertions=native_assertions, lua_contract_assertions=lua_assertions,
                  limitations=[
                      'No Client or Lua execution; no resource or repository mutation.',
                      'CALL origins are lookup names, not immutable global/table target identities.',
                      'Open argument lists are register-bound overapproximations, not exact runtime arity.',
                      'No claim about unavailable Coroutine.lua 13-prototype operands or its internal policies.',
                      'Reused anchors are explicitly separate; an evidence match is not FULL-PASS.',
                      'Hypothetical new content bridge remains a design inference subject to project policy.',
                  ])
    if args.out:
        inputs = [(args.originals / x['file']).resolve() for x in manifest['originals']]
        check(args.out.resolve() not in inputs, 'Result must not overwrite originals')
        args.out.write_text(json.dumps(result, ensure_ascii=False, indent=2) + '\n')
    print(json.dumps(dict(status=result['status'], totals=totals,
                          references_verified=sum(x['status'] == 'EXACT_CONTENT_MATCH' for x in reference_checks),
                          references_not_read=sum(x['status'] == 'NOT_READ' for x in reference_checks)),
                     ensure_ascii=False))


if __name__ == '__main__':
    main()
