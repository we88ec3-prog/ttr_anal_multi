#!/usr/bin/env python3
"""Read-only verification of R11 selected audiovisual capability evidence.

Reads the original PE/STPD, this evidence package and fixed local Git blobs.
Never launches the game or Lua, changes originals/repository, or fetches objects.
Prints derived JSON to stdout. PASS is static evidence verification, not gameplay.
Requirements: Python 3, git and GNU objdump. No third-party Python package.
"""
import argparse
from collections import Counter
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
import types

sys.dont_write_bytecode = True
CHECKS = Counter()
MAIN = '03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc'
PARENT = 'af97bbd29c892e031eef7a3bc3a98cb79f1be729'
BIN_SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
EVENT_SHA = '2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b'
PARSER_SHA = '8eb16bbc06940769197b2a3446c66a024a3e98d1c44f035ce69c4fee36212a56'


def check(ok, label, group='structure'):
    if not ok:
        raise ValueError(label)
    CHECKS[group] += 1


def digest(data):
    return hashlib.sha256(data).hexdigest()


def num(value):
    return int(value, 0) if isinstance(value, str) else value


def read_json(path):
    return json.loads(path.read_text())


def git_blob(repo, commit, path):
    env = dict(os.environ, GIT_NO_LAZY_FETCH='1', GIT_TERMINAL_PROMPT='0')
    return subprocess.check_output(
        ['git', '-c', 'maintenance.auto=false', 'show', commit + ':' + path],
        cwd=repo, env=env)


def disassemble(path, start, end, raw_of):
    raw = subprocess.check_output([
        'objdump', '-D', '-Mintel', '--insn-width=16',
        '--start-address=' + hex(start), '--stop-address=' + hex(end + 15),
        str(path)], text=True)
    result = []
    for line in raw.splitlines():
        m = re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)', line)
        if m and start <= int(m[1], 16) < end:
            va = int(m[1], 16)
            code = bytes.fromhex(m[2])
            result.append(dict(va=hex(va), raw=hex(raw_of(va, len(code))),
                               hex=code.hex(), asm=m[3].strip()))
    return result


OPNAMES = ('MOVE LOADK LOADBOOL LOADNIL GETUPVAL GETGLOBAL GETTABLE SETGLOBAL '
           'SETUPVAL SETTABLE NEWTABLE SELF ADD SUB MUL DIV MOD POW UNM NOT LEN '
           'CONCAT JMP EQ LT LE TEST TESTSET CALL TAILCALL RETURN FORLOOP FORPREP '
           'TFORLOOP SETLIST CLOSE CLOSURE VARARG').split()


def decode(proto):
    out = []
    for pc, word in enumerate(proto['words']):
        op = word & 63
        a, c, b = (word >> 6) & 255, (word >> 14) & 511, (word >> 23) & 511
        bx, sbx = word >> 14, (word >> 14) - 131071
        d = dict(pc=pc, word=hex(word), raw_offset=proto['code_offset'] + pc * 4,
                 op=OPNAMES[op], A=a, B=b, C=c, Bx=bx, sBx=sbx)
        if op in (1, 5, 7):
            d['constant'] = proto['constants'][bx]
        if op in (6, 9, 12, 13, 14, 15, 16, 17, 23, 24, 25):
            if b >= 256:
                d['RK_B'] = proto['constants'][b - 256]
            if c >= 256:
                d['RK_C'] = proto['constants'][c - 256]
        if op in (22, 31, 32):
            d['target'] = pc + 1 + sbx
        if op in (28, 29):
            d['arguments'], d['results'] = b - 1, c - 1
        if op == 36:
            d['child_prototype'] = proto['children'][bx]
        out.append(d)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin', required=True, type=Path)
    ap.add_argument('--event-stp', required=True, type=Path)
    ap.add_argument('--repo', required=True, type=Path)
    ap.add_argument('--evidence-dir', type=Path, default=Path(__file__).resolve().parent)
    args = ap.parse_args()
    e = args.evidence_dir
    sources = read_json(e / 'source-manifest.json')
    native = read_json(e / 'native-windows.json')
    bindings = read_json(e / 'bindings.json')
    contracts = read_json(e / 'contracts.json')
    lua = read_json(e / 'lua-evidence.json')
    check(sources['base_main'] == MAIN and sources['parent_analysis'] == PARENT,
          'Fixed main and R10 parent pins', 'identities')
    check(native['binary']['sha256'] == BIN_SHA and lua['carrier']['sha256'] == EVENT_SHA,
          'Fixed original identities', 'identities')

    blobs = {}
    for pin in sources['references']:
        check(pin['commit'] in (MAIN, PARENT), 'Allowed exact commit', 'git_pins')
        data = git_blob(args.repo, pin['commit'], pin['path'])
        check(len(data) == pin['bytes'] and digest(data) == pin['sha256'],
              'Git bytes/hash: ' + pin['path'], 'git_pins')
        oid = hashlib.sha1(b'blob ' + str(len(data)).encode() + b'\0' + data).hexdigest()
        check(oid == pin['git_blob'], 'Git blob identity: ' + pin['path'], 'git_pins')
        blobs[pin['commit'] + ':' + pin['path']] = data
    pp = sources['parser_source']
    helper = blobs[pp['commit'] + ':' + pp['path']]
    check(digest(helper) == PARSER_SHA, 'Pinned data-only parser', 'identities')
    parser = types.ModuleType('pinned_audiovisual_byte_parser')
    parser.__file__ = pp['path']
    exec(compile(helper, pp['path'], 'exec'), parser.__dict__)
    expected = dict(native['binary'], size=native['binary']['bytes'])
    pe = parser.PE(args.bin, expected)
    check(len(pe.data) == 12472320 and digest(pe.data) == BIN_SHA,
          'Actual original BIN identity and PE32 mapping', 'identities')
    records = {r['id']: r for r in native['records']}
    check(len(records) == len(native['records']), 'Unique native record IDs')
    boundaries, instruction_map = set(), {}
    asm_text = []
    for r in native['records']:
        pe.verify_window(r)
        check(num(r['end']) - num(r['va']) == r['length'],
              r['id'] + ' exact extent/raw/hex/hash', 'windows')
        asm_text.append('; ' + r['id'] + ' ' + r['role'] + '\n; VA ' + r['va'] +
                        '..' + r['end'] + ' raw ' + r['raw'] + ' length ' +
                        str(r['length']) + ' SHA256 ' + r['sha256'])
        if r['kind'] == 'code':
            ins = disassemble(args.bin, num(r['va']), num(r['end']), pe.raw_of)
            check(ins == r['instructions'], r['id'] + ' regenerated ASM', 'disassembly')
            cursor = num(r['va'])
            for row in ins:
                check(num(row['va']) == cursor and '(bad)' not in row['asm'],
                      r['id'] + ' continuous complete instruction', 'boundaries')
                boundaries.add(cursor)
                if cursor in instruction_map:
                    check(instruction_map[cursor] == row,
                          row['va'] + ' overlapping excerpts agree', 'overlaps')
                instruction_map[cursor] = row
                cursor += len(bytes.fromhex(row['hex']))
            check(cursor == num(r['end']), r['id'] + ' final boundary', 'boundaries')
            asm_text.extend(x['va'] + '  ' + x['hex'].ljust(32) + '  ' + x['asm'] for x in ins)
        else:
            check(r['kind'] == 'data', r['id'] + ' known record kind')
            asm_text.append('; bytes ' + r['hex'])
        asm_text.append('')
    check((e / 'native-windows.asm').read_text() == '\n'.join(asm_text),
          'Human ASM file equals verified native records', 'disassembly')

    def at(va, count):
        return pe.at(num(va), count)

    def u32(va):
        return struct.unpack('<I', at(va, 4))[0]

    def cstr(va):
        off = pe.raw_of(num(va), 1)
        return pe.data[off:pe.data.index(0, off)].decode('ascii')

    def direct(site, target, role, kind='call'):
        site, target = num(site), num(target)
        code = at(site, 5)
        opcode = 0xe8 if kind == 'call' else 0xe9
        check(site in boundaries and code[0] == opcode and
              site + 5 + struct.unpack_from('<i', code, 1)[0] == target,
              role, 'direct_edges')

    for edge in contracts['direct_edges']:
        r = records[edge['record']]
        check(num(r['va']) <= num(edge['va']) < num(r['end']),
              'Direct edge belongs to selected record', 'contract_records')
        direct(edge['va'], edge['target'], edge['role'], edge['kind'])
    for anchor in contracts['semantic_anchors']:
        va = num(anchor['va'])
        r = records[anchor['record']]
        check(num(r['va']) <= va < num(r['end']) and va in boundaries and
              at(va, len(bytes.fromhex(anchor['hex']))).hex() == anchor['hex'] and
              instruction_map[va]['asm'] == anchor['asm'], anchor['role'], 'semantic_anchors')

    namespaces = {
        'Q': ('B_Q_root', 'B_Q_namespace', 0x560600, 0x565e40, 0xfe2778),
        'CameraWorks': ('C01', 'C02', 0x54e750, 0x54ea20, 0xfe1e28),
        'Tutorial': ('B_TUT_root', 'U09', 0x4a88e0, 0x4aa5a0, 0xfe1804),
        'Fade': ('F01', 'F02', 0x55e680, 0x55e850, 0xfe1f30),
    }
    counts = Counter()
    names = {}
    for row in bindings['members']:
        name = row['namespace'] + '.' + row['name']
        check(name not in names, 'Unique selected binding ' + name, 'bindings')
        names[name] = row
        counts[row['namespace']] += 1
        reg, slot, target = num(row['registrar']), num(row['slot']), num(row['native'])
        direct(row['callsite'], reg, name + ' actual registrar call')
        check(at(reg + 0x18, 2) == b'\xc7\x05' and u32(reg + 0x1a) == slot and
              u32(reg + 0x1e) == target, name + ' native slot producer', 'bindings')
        check(at(reg + 0x58, 1) == b'\x68' and u32(reg + 0x59) == num(row['name_va']) and
              cstr(row['name_va']) == row['name'], name + ' name', 'bindings')
        check(at(reg + 0x69, 1) == b'\x68' and u32(reg + 0x6a) == num(row['closure']),
              name + ' Lua closure', 'bindings')
        root_id, ns_id, root, init, receiver_slot = namespaces[row['namespace']]
        rr = records[root_id]
        check(num(row['root']) == root and num(row['namespace_initializer']) == init and
              num(row['receiver_slot']) == receiver_slot and
              num(rr['va']) <= num(row['callsite']) < num(rr['end']),
              name + ' root/namespace/receiver tuple', 'bindings')
        closure = records[row['closure_record']]
        chain_bytes = bytes.fromhex(closure['hex'])
        if row['marshaller'] is not None:
            target_helper = num(row['marshaller'])
            helpers = [x for x in records.values() if x['id'].startswith('A_') and
                       num(x['va']) == target_helper]
            check(len(helpers) == 1, name + ' bounded marshaller record', 'bindings')
            chain_bytes += bytes.fromhex(helpers[0]['hex'])
            matches = []
            for ins in closure['instructions']:
                code = bytes.fromhex(ins['hex'])
                if len(code) == 5 and code[0] == 0xe8 and (
                        num(ins['va']) + 5 + struct.unpack('<i', code[1:])[0] == target_helper):
                    matches.append(ins)
            check(len(matches) == 1, name + ' exact argument marshaller call', 'bindings')
        check(num(closure['va']) == num(row['closure']) and
              struct.pack('<I', slot) in chain_bytes and
              struct.pack('<I', receiver_slot) in chain_bytes,
              name + ' closure/marshaller chain reads selected slot and receiver', 'bindings')
        check(records[row['registrar_record']]['va'] == row['registrar'] and
              records[row['call_record']]['va'] == row['callsite'] and
              records[row['name_record']]['va'] == row['name_va'],
              name + ' referenced original record identities', 'bindings')
    check(counts == dict(Q=16, CameraWorks=5, Tutorial=5, Fade=2) and len(names) == 28,
          'Selected 28-entry surface', 'bindings')
    check(names['Q.MoveCamera']['native'] == names['Q.SetCameraPoint']['native'] == '0x562e10',
          'MoveCamera and SetCameraPoint alias immediate setter', 'selected_contracts')
    check(at(0x54f00c, 7) == bytes.fromhex('c7400803000000') and
          at(0x54f013, 2) == bytes.fromhex('dd18') and
          at(0x54f015, 4) == bytes.fromhex('83460810'),
          'IsEnded pushes numeric Lua TValue', 'selected_contracts')
    check(at(0x55e868, 10) == bytes.fromhex('c705301ffe004427fe00'),
          'Fade formal receiver is FE2744 shared overlay', 'selected_contracts')

    for vt in native['vtables']:
        va, col, td = num(vt['va']), num(vt['col']), num(vt['type_descriptor'])
        check(u32(va - 4) == col and u32(col + 12) == td and cstr(td + 8) == vt['type_name'],
              vt['id'] + ' COL/RTTI identity', 'types')
        for slot in vt['slots']:
            check(u32(va + num(slot['offset'])) == num(slot['target']),
                  vt['id'] + ' slot ' + slot['offset'], 'types')
    for edge in contracts['typed_virtual_targets']:
        check(u32(num(edge['va']) + num(edge['offset'])) == num(edge['target']),
              edge['role'], 'typed_virtual_targets')
    for const in native['constants']:
        size = struct.calcsize('<' + const['format'])
        check(struct.unpack('<' + const['format'], at(const['va'], size))[0] == const['value'],
              const['id'] + ' original numeric value', 'constants')
    for string in native['strings']:
        check(cstr(string['va']) == string['value'], string['value'], 'strings')
    check(u32(0xbd2618) + pe.base == 0xd5ed5a and cstr(0xd5ed5c) == 'D3DXCreateTexture',
          'Texture-creation selected PE import identity', 'selected_contracts')
    check(at(0x561582, 5)[0] == 0xe8 and 0x561582 < 0x561587 and
          at(0x561587, 4) == bytes.fromhex('837f2800'),
          'Fade update precedes Q active condition', 'selected_contracts')
    check(at(0x562da8, 6) == bytes.fromhex('f30f2c742410') and
          at(0x562dae, 2) == bytes.fromhex('03f0'),
          'SkipCamera truncated relative increment', 'selected_contracts')
    check(at(0x564ef9, 3) == bytes.fromhex('8b4e04') and
          at(0x564efc, 3) == bytes.fromhex('894108'),
          'TalkSound group belongs to referenced SoundFile', 'selected_contracts')

    stp = parser.STPD(args.event_stp, lua['carrier'])
    member = lua['member']
    chunk = stp.verify_member(member)
    original_stp = args.event_stp.read_bytes()
    check(digest(original_stp[member['stored_offset']:member['stored_offset'] + member['stored_length']])
          == member['stored_sha256'], 'Original member stored SHA', 'lua_identity')
    protos = parser.read_lua51_prototypes(chunk)
    check(len(protos) == member['prototype_count'] == 76 and
          sum(len(p['words']) for p in protos) == member['instruction_count'] == 906,
          'Original qbase complete structural parse 76 prototypes/906 words', 'lua_identity')
    root = decode(protos[0])
    assignments = {}
    for current, following in zip(root, root[1:]):
        if current['op'] == 'CLOSURE' and following['op'] == 'SETGLOBAL' and current['A'] == following['A']:
            assignments[current['child_prototype']] = (following['constant'], [current, following])
    selected = {}
    for q in lua['selected_prototypes']:
        idx = q['index']
        check(idx not in selected, 'Unique selected prototype', 'lua_prototypes')
        selected[idx] = q
        real = protos[idx]
        for key, value in real.items():
            check(q[key] == value, 'P' + str(idx) + ' ' + key, 'lua_prototypes')
        check(decode(real) == q['decoded'], 'P' + str(idx) + ' original operands', 'lua_prototypes')
        check(assignments[idx] == (q['name'], q['root_assignment']),
              'P' + str(idx) + ' actual root global assignment', 'lua_prototypes')
    required = {11:'WaitForCamera',14:'PlayCameraNoWait',15:'PlayCamera',16:'SkipCamera',
                21:'PlayMusic',22:'StopMusic',23:'StopMusicWithFadeOut',37:'Transition',
                44:'MoveCamera',45:'RotCamera',47:'PlaySound',48:'PlayTalkSound',49:'FadeOut',
                50:'FadeIn',51:'FadeColor',52:'CameraEffect',64:'SetFinalMusic',67:'Phase1',74:'RevPhase1'}
    check({idx: q['name'] for idx, q in selected.items()} == required,
          'Exact selected 19 helpers only', 'lua_prototypes')
    q = selected[11]['decoded']
    check(q[0].get('constant') == 'yield' and q[3].get('RK_C') == 'IsEnded' and
          q[4]['results'] == 1 and q[5]['op'] == 'EQ' and q[5]['A'] == 0 and
          q[5].get('RK_C') == 0 and q[6]['target'] == 11 and
          q[7].get('constant') == 'wait' and q[8].get('constant') == 100 and q[10]['target'] == 2,
          'WaitForCamera initial yield then while numeric zero wait100', 'lua_contracts')
    q = selected[14]['decoded']
    check(selected[14]['params'] == 5 and q[3]['op'] == 'EQ' and q[3]['A'] == 1 and
          q[3].get('RK_C') == 0 and q[4]['target'] == 20 and
          [q[i].get('RK_C') for i in (6,11,16)] == ['GetLeaderPosN'] * 3 and
          q[20].get('constant') == 'Event/CameraWorks/' and q[24].get('RK_C') == 'LoadRel' and
          q[29]['arguments'] == 4 and q[29]['results'] == 0 and q[31].get('RK_C') == 'Play',
          'Five-argument helper, conditional leader offset, explicit LoadRel then Play', 'lua_contracts')
    q = selected[15]['decoded']
    check(q[0].get('constant') == 'PlayCameraNoWait' and q[6]['arguments'] == 5 and
          q[7].get('constant') == 'WaitForCamera', 'PlayCamera actually waits', 'lua_contracts')
    q = selected[37]['decoded']
    check(selected[37]['params'] == 0 and q[1].get('RK_C') == 'Transition' and
          q[2].get('constant') == 2 and q[3].get('constant') == 120 and
          q[4]['arguments'] == 2 and q[4]['results'] == 0 and q[5].get('constant') == 'yield',
          'Transition helper fixed2,120 and yield only', 'lua_contracts')
    q = selected[21]['decoded']
    check(q[0].get('constant') == 'Sound/' and q[4].get('RK_C') == 'PlayMusic' and
          q[6].get('constant') == 'TRUE' and q[7]['arguments'] == 2,
          'Music prefix and original TRUE loop value', 'lua_contracts')
    for idx in (16,21,22,23,37,47,48,49,50,51):
        q = selected[idx]['decoded']
        check(sum(x.get('constant') == 'yield' for x in q) == 1 and
              not any(x.get('constant') == 'wait' for x in q) and
              all(x['results'] == 0 for x in q if x['op'] == 'CALL'),
              'P' + str(idx) + ' one yield, no completion polling', 'lua_contracts')
    for idx in (44,45,64):
        q = selected[idx]['decoded']
        check(not any(x.get('constant') in ('yield','wait') for x in q) and
              all(x['results'] == 0 for x in q if x['op'] == 'CALL'),
              'P' + str(idx) + ' immediate helper', 'lua_contracts')
    for idx in (47,48):
        q = selected[idx]['decoded']
        check(not any(x['op'] == 'CONCAT' for x in q) and selected[idx]['params'] == 1,
              'P' + str(idx) + ' sound path unchanged', 'lua_contracts')
    q = selected[52]['decoded']
    check(selected[52]['params'] == 4 and q[5]['arguments'] == 3 and
          q[6].get('constant') == 'TRUE' and q[9].get('constant') == 'wait' and
          q[10]['op'] == 'MUL' and q[10].get('RK_C') == 33.333333333333336 and
          q[13].get('constant') == 'yield', 'CameraEffect helper extra wait flag/estimate', 'lua_contracts')
    for idx, pcs, direction in [(67,(42,43,44,45,47,48),0),(74,(27,28,29,30,32,33),1)]:
        q = selected[idx]['decoded']
        count, namespace, method, dir_pc, call, wait = pcs
        check(q[count].get('constant') == 30 and q[namespace].get('constant') == 'Fade' and
              q[method].get('RK_C') == 'Start' and q[dir_pc].get('constant') == direction and
              q[call]['arguments'] == 2 and q[call]['results'] == 0 and
              q[wait].get('constant') == 'wait',
              'P' + str(idx) + ' Fade direction/count30 plus wait30 content', 'lua_contracts')

    covered = set()
    binding_ids = {x['id'] for x in bindings['members']}
    for capability in contracts['capabilities']:
        check(all(x in names for x in capability['entries']) and
              all(x in binding_ids for x in capability['bindings']) and
              all(x in records for x in capability['native_records']) and
              all(x in selected for x in capability['lua_prototypes']),
              capability['id'] + ' actual source references', 'contract_records')
        check([names[x]['id'] for x in capability['entries']] == capability['bindings'],
              capability['id'] + ' binding identities', 'contract_records')
        covered.update(capability['entries'])
    check(covered == set(names) and len(contracts['capabilities']) == 11,
          'All selected bindings have explicit capability/limits/Server contract', 'contract_records')

    result = dict(
        status='PASS', validation='Original bytes, regenerated ASM, fixed Git blobs, original qbase parse and selected capability contracts',
        binary_sha256=BIN_SHA, event_stp_sha256=EVENT_SHA, main_commit=MAIN, parent_commit=PARENT,
        counts=dict(native_records=len(records), code_records=sum(r['kind']=='code' for r in records.values()),
                    excerpt_bytes=sum(r['length'] for r in records.values()),
                    instructions=sum(len(r.get('instructions', [])) for r in records.values()),
                    unique_instruction_starts=len(boundaries), selected_bindings=len(names),
                    selected_lua_prototypes=len(selected), git_source_pins=len(sources['references']),
                    typed_vtables=len(native['vtables']), capabilities=len(contracts['capabilities']),
                    direct_edges=len(contracts['direct_edges']), semantic_anchors=len(contracts['semantic_anchors']),
                    typed_virtual_targets=len(contracts['typed_virtual_targets']), checks=sum(CHECKS.values())),
        checks_by_group=dict(CHECKS), verifier_sha256=digest(Path(__file__).read_bytes()),
        limits=['Static evidence PASS only; no actual audiovisual/gameplay/Server acceptance',
                'No Client, Lua or Server execution; no network fetch or input/repository write',
                'Original MEF format/first-load caller remains outside this positive binding analysis',
                'Resource validity, device/output readiness and native owner gates remain required',
                'Unproven additional observer/callback is a Client research boundary, not invented Server wire'])
    print(json.dumps(result, ensure_ascii=False, indent=2))


if __name__ == '__main__':
    try:
        main()
    except (ValueError, KeyError, OSError, AssertionError, IndexError, struct.error,
            subprocess.CalledProcessError) as exc:
        print(json.dumps(dict(status='FAIL', error=str(exc), checks_by_group=dict(CHECKS)),
                         ensure_ascii=False, indent=2), file=sys.stderr)
        sys.exit(1)
