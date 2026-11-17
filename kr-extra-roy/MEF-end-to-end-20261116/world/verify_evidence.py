#!/usr/bin/env python3
"""Read-only verification of selected MEF round9 world/tutorial evidence.

Reads original PE/STPD, local pinned Git objects and this evidence package.
Never launches Client/Lua, fetches Git objects, or writes original inputs.
An optional --out writes only a derived JSON verification result.
PASS is byte/structure/selected-contract verification, not gameplay acceptance.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
import types

CHECKS = {}


def check(condition, label, group='structure'):
    if not condition:
        raise ValueError(label)
    CHECKS[group] = CHECKS.get(group, 0) + 1


def digest(data):
    return hashlib.sha256(data).hexdigest()


def number(value):
    return int(value, 0) if isinstance(value, str) else value


def read_json(path):
    return json.loads(path.read_text())


def git_blob(repo, commit, path):
    env = dict(os.environ, GIT_NO_LAZY_FETCH='1', GIT_TERMINAL_PROMPT='0')
    return subprocess.check_output(['git', '-c', 'maintenance.auto=false',
                                    'show', commit + ':' + path], cwd=repo, env=env)


def disassemble(binary, start, end, raw_of):
    result = subprocess.check_output(
        ['objdump', '-D', '-Mintel', '--insn-width=16',
         '--start-address=' + hex(start), '--stop-address=' + hex(end + 15), str(binary)],
        text=True)
    out = []
    for line in result.splitlines():
        m = re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)', line)
        if m and int(m[1], 16) < end:
            va = int(m[1], 16)
            b = bytes.fromhex(m[2])
            out.append(dict(va=hex(va), raw=hex(raw_of(va, len(b))),
                            hex=b.hex(), asm=m[3].strip()))
    return out


OPNAMES = ('MOVE LOADK LOADBOOL LOADNIL GETUPVAL GETGLOBAL GETTABLE SETGLOBAL '
           'SETUPVAL SETTABLE NEWTABLE SELF ADD SUB MUL DIV MOD POW UNM NOT LEN '
           'CONCAT JMP EQ LT LE TEST TESTSET CALL TAILCALL RETURN FORLOOP FORPREP '
           'TFORLOOP SETLIST CLOSE CLOSURE VARARG').split()


def decode(p):
    out = []
    for pc, word in enumerate(p['words']):
        op = word & 63
        a, c, b = (word >> 6) & 255, (word >> 14) & 511, (word >> 23) & 511
        bx, sbx = word >> 14, (word >> 14) - 131071
        d = dict(pc=pc, decoded_member_offset=p['code_offset'] + pc * 4,
                 hex=struct.pack('<I', word).hex(), word=hex(word), op=OPNAMES[op],
                 A=a, B=b, C=c, Bx=bx, sBx=sbx)
        if op in (1, 5, 7):
            d['constant'] = p['constants'][bx]
        if op in (6, 9, 12, 13, 14, 15, 16, 17, 23, 24, 25):
            if b >= 256:
                d['RK_B'] = p['constants'][b - 256]
            if c >= 256:
                d['RK_C'] = p['constants'][c - 256]
        if op in (22, 31, 32):
            d['target'] = pc + 1 + sbx
        if op in (28, 29):
            d['arguments'], d['results'] = b - 1, c - 1
        if op == 36:
            d['child_prototype'] = p['children'][bx]
        out.append(d)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin', required=True, type=Path)
    ap.add_argument('--event-stp', required=True, type=Path)
    ap.add_argument('--repo', required=True, type=Path)
    ap.add_argument('--evidence-dir', type=Path, default=Path(__file__).resolve().parent)
    ap.add_argument('--out', type=Path)
    args = ap.parse_args()
    e = args.evidence_dir
    source = read_json(e / 'source-manifest.json')
    native = read_json(e / 'native-windows.json')
    contracts = read_json(e / 'contracts.json')
    lua = read_json(e / 'lua-evidence.json')

    blobs = {}
    for pin in source['git_sources']:
        data = git_blob(args.repo, pin['commit'], pin['path'])
        check(len(data) == pin['bytes'] and digest(data) == pin['sha256'],
              'Git content pin: ' + pin['path'], 'git_pins')
        oid = hashlib.sha1(b'blob ' + str(len(data)).encode() + b'\0' + data).hexdigest()
        check(oid == pin['blob'], 'Git blob id: ' + pin['path'], 'git_pins')
        blobs[pin['commit'] + ':' + pin['path']] = data
    request_pin = next(p for p in source['git_sources'] if p['path'] == 'research/requests/index.json')
    req = json.loads(blobs[request_pin['commit'] + ':' + request_pin['path']])
    item = next(x for x in req['items'] if x['id'] == 'RR-0013')
    check(item == source['selected_request'], 'Exact RR-0013 selected item', 'scope')
    check(item['owner_task'] == 'T13' and item['dispatch']['state'] == 'QUEUED'
          and item['dispatch']['priority'] == 'P0' and item['dispatch']['claim'] is None,
          'RR-0013 pinned ownership/status; this does not assert latest remote status', 'scope')

    helper_pin = source['parser_source']
    helper = blobs[helper_pin['commit'] + ':' + helper_pin['path']]
    check(digest(helper) == '8eb16bbc06940769197b2a3446c66a024a3e98d1c44f035ce69c4fee36212a56',
          'Trusted read-only parser exact pin', 'source_parser')
    parser = types.ModuleType('pinned_world_parser')
    parser.__file__ = helper_pin['path']
    exec(compile(helper, helper_pin['path'], 'exec'), parser.__dict__)
    pe = parser.PE(args.bin, native['binary'])
    all_boundaries = set()
    for w in native['windows']:
        pe.verify_window(w)
        check(number(w['end']) - number(w['va']) == w['length'], w['id'] + ' extent', 'windows')
        if w['kind'] == 'code':
            actual = disassemble(args.bin, number(w['va']), number(w['end']), pe.raw_of)
            check(actual == w['instructions'], w['id'] + ' regenerated asm', 'disassembly')
            cursor = number(w['va'])
            for ins in actual:
                check(number(ins['va']) == cursor, w['id'] + ' continuous instruction', 'boundaries')
                check('(bad)' not in ins['asm'], w['id'] + ' valid decoding', 'boundaries')
                all_boundaries.add(cursor)
                cursor += len(bytes.fromhex(ins['hex']))
            check(cursor == number(w['end']), w['id'] + ' final boundary', 'boundaries')

    def at(va, size):
        return pe.at(number(va), size)

    def u32(va):
        return struct.unpack('<I', at(va, 4))[0]

    def cstr(va):
        raw = pe.raw_of(number(va), 1)
        return pe.data[raw:pe.data.index(0, raw)].decode('ascii')

    def direct(va, target, label):
        va, target = number(va), number(target)
        b = at(va, 5)
        check(va in all_boundaries and b[0] == 0xe8
              and va + 5 + struct.unpack_from('<i', b, 1)[0] == target, label, 'calls')

    for x in contracts['direct_calls']:
        direct(x['va'], x['target'], x['role'])
    for x in contracts['bindings']:
        r = number(x['registrar'])
        direct(x['call_site'], r, x['name'] + ' actual root registrar call')
        check(at(r + 0x18, 2) == b'\xc7\x05' and u32(r + 0x1a) == number(x['slot'])
              and u32(r + 0x1e) == number(x['native']), x['name'] + ' native slot', 'bindings')
        check(at(r + 0x58, 1) == b'\x68' and u32(r + 0x59) == number(x['name_va'])
              and cstr(x['name_va']) == x['name'].split('.', 1)[1], x['name'] + ' name', 'bindings')
        check(at(r + 0x69, 1) == b'\x68' and u32(r + 0x6a) == number(x['closure']),
              x['name'] + ' closure', 'bindings')
    for x in contracts['anchors']:
        check(number(x['va']) in all_boundaries
              and at(x['va'], len(bytes.fromhex(x['hex']))) == bytes.fromhex(x['hex']),
              x['role'], 'contract_anchors')
    for t in contracts['types']:
        v = number(t['vptr'])
        check(u32(v - 4) == number(t['col']), t['name'] + ' COL pointer', 'types')
        check(u32(number(t['col']) + 12) == number(t['type_descriptor'])
              and cstr(number(t['type_descriptor']) + 8) == t['type_name'], t['name'] + ' RTTI', 'types')
        for slot, target in t['slots'].items():
            check(u32(v + number(slot)) == number(target), t['name'] + ' slot' + slot, 'types')
    check(u32(0xc3f194 + 0x15c) == 0x6bfe90 and u32(0xc3f194 + 0x114) == 0x6bfca0,
          'dummy real handler and child initialize slots', 'contract_anchors')
    check(u32(0xc1f5f4 + 0x108) == 0x5c3040 and u32(0xc1f5f4 + 0x198) == 0x5c3370,
          'same CTutorialPage initialize and callback table', 'contract_anchors')
    tag_target = u32(0xc47bcc + 4)
    check(at(tag_target, 6) == bytes.fromhex('b8ba050100c3'), 'producer FXUIEventI2 matches consumer105BA', 'contract_anchors')
    check(at(0x5ade20, 4) == bytes.fromhex('8b410cc3') and u32(0xc1d988 + 0x10) == 0x5ade20,
          'descriptor returns exact dummy+C allocation', 'contract_anchors')
    for x in contracts['floats']:
        check(struct.unpack('<' + x['format'], at(x['va'], struct.calcsize(x['format'])))[0] == x['value'],
              'visibility constant ' + x['id'], 'contract_anchors')
    for x in contracts['integer_argument_examples']:
        check(((x['input_integer'] & 255) << 8) == x['expected_entity_id'],
              'lowbyte identity arithmetic ' + str(x['input_integer']), 'identity_examples')
    reset = next(w for w in native['windows'] if w['id'] == 'controller_common_reset')
    check(not any('[edi+0x134]' in q['asm'] for q in reset['instructions']),
          'only selected common-reset body has no direct EDI+134 access; not all callees/writers', 'bounded_negative')

    stp = parser.STPD(args.event_stp, lua['carrier'])
    actual_event = args.event_stp.read_bytes()
    chunks = {}
    for record in lua['members']:
        m = record['member']
        chunk = stp.verify_member(m)
        stored = actual_event[m['stored_offset']:m['stored_offset'] + m['stored_length']]
        check(digest(stored) == m['stored_sha256'], m['virtual_path'] + ' physical member', 'lua_identity')
        protos = parser.read_lua51_prototypes(chunk)
        check(len(protos) == m['prototype_count'] and sum(len(p['words']) for p in protos) == m['instruction_count'],
              m['virtual_path'] + ' parse counts', 'lua_identity')
        chunks[m['virtual_path']] = protos
        for p in record['selected_prototypes']:
            real = protos[p['index']]
            for key, value in real.items():
                check(p[key] == value, m['virtual_path'] + ' P' + str(p['index']) + ' ' + key, 'lua_prototypes')
            b = chunk[p['code_offset']:p['code_offset'] + 4 * len(p['words'])]
            check(b.hex() == p['code_hex'] and digest(b) == p['code_sha256'], 'Lua selected code bytes', 'lua_prototypes')
            check(decode(real) == p['decoded'], 'Lua selected decoded words', 'lua_prototypes')

    base = decode(chunks['Event/TutorialBase.lua'][0])
    main_protos = chunks['Event/TutorialMain.lua']
    root, p5, p8 = decode(main_protos[0]), decode(main_protos[5]), decode(main_protos[8])
    check(base[23].get('RK_B') == 'TUTORIAL_CHANGEKEYTYPE' and base[23].get('RK_C') == 9,
          'original enum9', 'lua_contracts')
    check(root[12]['child_prototype'] == 5 and root[13]['constant'] == 'Tutorial_Part1'
          and root[18]['child_prototype'] == 8 and root[19]['constant'] == 'TutorialMain',
          'actual root function bindings', 'lua_contracts')
    check(p5[13].get('RK_C') == 'PostUIMessage_TutoMsg'
          and p5[15].get('RK_C') == 'TUTORIAL_CHANGEKEYTYPE' and p5[16]['constant'] == 0
          and p5[19].get('RK_C') == 'GetTutorialState' and p5[21]['constant'] == 'FALSE'
          and p5[23]['target'] == 27 and p5[26]['target'] == 18,
          'original UI request and state wait consumer', 'lua_contracts')
    check(p5[108].get('RK_C') == 'InsertIsilia' and p5[111].get('RK_C') == 'IsIsiliaFound'
          and p5[113]['constant'] == 'FALSE' and p5[118]['target'] == 110,
          'original fixed-actor insert and visibility wait', 'lua_contracts')
    check(p5[135].get('RK_C') == 'CheckLeader' and p5[161]['target'] == 134,
          'original leader model wait consumer', 'lua_contracts')
    check(p8[24].get('RK_C') == 'GetControlStatus' and p8[25]['constant'] == 0
          and p8[31].get('RK_C') == 'SetControlStatus'
          and p8[36].get('RK_C') == 'StopCutScene' and p8[38]['constant'] == 't_removeCoroutine',
          'original skip flag consumer and coroutine removal', 'lua_contracts')
    check(p8[72].get('RK_C') == 'DeleteObject' and p8[73]['constant'] == 240
          and p8[74]['arguments'] == 1 and p8[74]['results'] == 0
          and p8[75]['constant'] == 'Tutorial_Part2', 'original cleanup240 thenPart2', 'lua_contracts')

    result = dict(status='PASS',validation='static bytes, local source pins, disassembly and selected structural contracts',
                  binary_sha256=native['binary']['sha256'],event_sha256=lua['carrier']['sha256'],
                  main_commit=source['main_commit'],previous_round_commit=source['previous_round_commit'],
                  counts=dict(windows=len(native['windows']),code_windows=sum(w['kind']=='code' for w in native['windows']),
                              selected_bindings=len(contracts['bindings']),git_sources=len(source['git_sources']),
                              selected_lua_prototypes=sum(len(r['selected_prototypes']) for r in lua['members']),
                              checks=sum(CHECKS.values())),checks_by_group=CHECKS,
                  verifier_sha256=digest(Path(__file__).read_bytes()),
                  limits=['Not T01 FULL-PASS or runtime/gameplay acceptance',
                          'No Client/Lua execution, no network fetch or original writes',
                          'Ordinary death/group/result callback remains unclosed',
                          'No global proof that controller+134 has no other reset/writer',
                          'UI dispatch, allocation success, valid runtime owner/resource contexts remain required'])
    output = json.dumps(result, ensure_ascii=False, indent=2) + '\n'
    if args.out:
        protected = {args.bin.resolve(), args.event_stp.resolve(), Path(__file__).resolve()}
        protected.update(p.resolve() for p in e.iterdir() if p.is_file() and p.name != 'verification-result.json')
        check(args.out.resolve() not in protected, 'Derived output must not overwrite an input', 'output_guard')
        args.out.write_text(output)
    print(output, end='')


if __name__ == '__main__':
    try:
        main()
    except (AssertionError, ValueError, OSError, KeyError, subprocess.CalledProcessError) as exc:
        print(json.dumps(dict(status='FAIL',error=str(exc),checks_by_group=CHECKS),ensure_ascii=False,indent=2),file=sys.stderr)
        sys.exit(1)
