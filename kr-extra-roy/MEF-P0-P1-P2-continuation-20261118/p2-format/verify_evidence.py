#!/usr/bin/env python3
"""Read-only P2 evidence replay; never execute Client, Lua or archive members.

Requires Python standard library and GNU objdump. Optional --repo verifies
exact Git object pins with lazy fetching disabled. This script prints a JSON
receipt to stdout and does not write files, extract members, mutate Git,
connect to a network, or certify whole-function semantics/T01/gameplay.

--require-native-mef intentionally exits 2 while the documented source and
native-consumer gates remain unresolved; an evidence PASS is not MEF ready.
"""
import argparse
import datetime
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys

sys.dont_write_bytecode = True
if sys.flags.optimize:
    raise RuntimeError('Do not use -O; assertions verify evidence.')

HERE = Path(__file__).resolve().parent
BIN_SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
MASTER_SHA = 'f59edc403213de3a3923cc47ebf44eb1812705e8693c3c196d122f51ab0c919d'


def sha(data):
    return hashlib.sha256(data).hexdigest()


def read_json(name):
    return json.loads((HERE/name).read_text())


def pe_sections(data):
    assert data[:2] == b'MZ'
    pe = struct.unpack_from('<I', data, 0x3c)[0]
    assert data[pe:pe+4] == b'PE\0\0'
    assert struct.unpack_from('<H', data, pe+4)[0] == 0x14c
    op = pe+24
    assert struct.unpack_from('<H', data, op)[0] == 0x10b
    base = struct.unpack_from('<I', data, op+28)[0]
    st = op+struct.unpack_from('<H', data, pe+20)[0]
    sections = []
    for i in range(struct.unpack_from('<H', data, pe+6)[0]):
        p = st+i*40
        vs, rva, rs, raw = struct.unpack_from('<4I', data, p+8)
        sections.append(dict(name=data[p:p+8].split(b'\0')[0].decode(),
                             va=base+rva, virtual_size=vs, raw=raw, raw_size=rs))
    return base, sections


def disassemble(path, start, end):
    text = subprocess.check_output([
        'objdump', '-d', '-Mintel', '--insn-width=16',
        f'--start-address={start}', f'--stop-address={end+15}', str(path)
    ], text=True)
    answer = []
    for line in text.splitlines():
        match = re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)$', line)
        if match and int(match[1], 16) < end:
            answer.append(dict(va=hex(int(match[1], 16)),
                               hex=''.join(match[2].split()), asm=match[3].strip()))
    return answer


def parse_rule(data):
    pos = 0

    def string():
        nonlocal pos
        assert pos+2 <= len(data)
        n = struct.unpack_from('<H', data, pos)[0]
        pos += 2
        assert pos+n <= len(data)
        value = data[pos:pos+n].decode('ascii')
        pos += n
        return value

    package, directory = string(), string()
    assert pos+2 <= len(data)
    flags = list(data[pos:pos+2])
    pos += 2
    extensions = [string() for _ in range(8)]
    assert pos == len(data)
    return dict(package=package, source_directory=directory,
                unassigned_flag_bytes=flags, extensions=extensions,
                consumed=pos)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--bin', type=Path, required=True)
    parser.add_argument('--master', type=Path, required=True)
    parser.add_argument('--repo', type=Path)
    parser.add_argument('--require-native-mef', action='store_true')
    args = parser.parse_args()
    native = read_json('native-windows.json')
    manifest = read_json('source-manifest.json')
    master_evidence = read_json('master-rule-evidence.json')
    capability = read_json('format-capability.json')
    binary = args.bin.read_bytes()
    master = args.master.read_bytes()
    assert sha(binary) == native['binary_sha256'] == BIN_SHA
    assert len(binary) == native['binary_bytes'] == 12472320
    assert sha(master) == master_evidence['source']['sha256'] == MASTER_SHA
    assert len(master) == master_evidence['source']['bytes'] == 1094887
    assert master[:4] == b'STPD'
    base, sections = pe_sections(binary)
    assert base == native['image_base'] == 0x400000
    assert sections == native['sections']

    def get(va, count):
        for section in sections:
            if section['va'] <= va and va+count <= section['va']+section['raw_size']:
                raw = section['raw']+va-section['va']
                return raw, binary[raw:raw+count]
        raise AssertionError(('not raw-backed', hex(va), count))

    windows = native['windows']
    assert len({w['id'] for w in windows}) == len(windows)
    all_instructions = {}
    for window in windows:
        start, end = int(window['va'], 16), int(window['end_exclusive'], 16)
        assert end-start == window['length']
        raw, data = get(start, end-start)
        assert raw == int(window['raw'], 16)
        assert data.hex() == window['hex'] and sha(data) == window['sha256']
        actual = disassemble(args.bin, start, end)
        assert actual == window['instructions']
        cursor = start
        for ins in actual:
            assert int(ins['va'], 16) == cursor
            encoded = bytes.fromhex(ins['hex'])
            assert data[cursor-start:cursor-start+len(encoded)] == encoded
            assert '(bad)' not in ins['asm'] and '.byte' not in ins['asm']
            cursor += len(encoded)
            all_instructions[int(ins['va'], 16)] = ins
        assert cursor == end, ('truncated final instruction', window['id'])
    for string in native['strings']:
        raw, data = get(int(string['va'], 16), string['length'])
        assert raw == int(string['raw'], 16)
        assert data == string['ascii'].encode()+b'\0'
        assert data.hex() == string['hex'] and sha(data) == string['sha256']

    anchors = {
        0x71360d: '83f801',  # directory-kind gate
        0x713610: '0f85f8000000',  # other kinds go directly to sibling iteration
        0x713632: '685841c400',  # AttachedPackage property, not a .mef file
        0x7136ba: '8d95f0fdffff',  # basename buffer passed in EDX
        0x7136d2: '89bb00010000',  # success-only provider assignment
        0x7156fe: '683056c000',  # append .stp
        0x71586b: '81fe44505453',  # STPD container marker comparison
        0x7159ce: '3d49505453',  # STPI container marker comparison
        0x4bad73: 'bf7074fb00',
        0x4bad84: '8bd8',  # resource name stored in EBX
        0x4badc2: '668b3dea90fb00',  # DI, not EDI, is overwritten
        0x4bae70: '0fbfd7',  # numeric sign extension of the overwritten DI
        0x4bae92: '53'  # filename argument is EBX
    }
    for va, expected in anchors.items():
        assert get(va, len(expected)//2)[1].hex() == expected
        assert all_instructions[va]['hex'] == expected
    calls = {
        0x713626: 0x714d50, 0x7136c9: 0x715620,
        0x713706: 0x7135b0, 0x713893: 0x7135b0,
        0x71570d: 0x401fc0, 0x715787: 0x714770,
        0x7158f7: 0x714770, 0x71479e: 0x713910,
        0x4bad78: 0x4f6e80, 0x4bae9d: 0x6d9b30
    }
    for site, target in calls.items():
        data = get(site, 5)[1]
        assert data[0] == 0xe8
        assert (site+5+struct.unpack_from('<i', data, 1)[0]) & 0xffffffff == target

    rules = []
    for window in master_evidence['rule_windows']:
        pos, count = int(window['raw'], 16), window['bytes']
        stored = master[pos:pos+count]
        decoded = bytes(value ^ 0xff for value in stored)
        assert stored.hex() == window['stored_hex'] and sha(stored) == window['stored_sha256']
        assert decoded.hex() == window['decoded_hex'] and sha(decoded) == window['decoded_sha256']
        rule = parse_rule(decoded)
        rules.append(rule)
    assert rules[0] == dict(package='Field', source_directory='Field\\',
                            unassigned_flag_bytes=[0, 1],
                            extensions=['xml', 'mef', '', '', '', '', '', ''], consumed=39)
    assert rules[1] == dict(package='UI/LUA', source_directory='UI\\LUA\\',
                            unassigned_flag_bytes=[1, 1],
                            extensions=['ftc', 'fft', 'fcs', 'fis', 'fsd', 'etf', 'obj', 'lua'], consumed=59)
    for binding in master_evidence['attached_package_identity_only']:
        pos, count = int(binding['raw'], 16), binding['bytes']
        stored = master[pos:pos+count]
        assert sha(stored) == binding['stored_sha256']
        assert sha(bytes(value ^ 0xff for value in stored)) == binding['decoded_sha256']

    checked_pins = 0
    if args.repo:
        env = dict(os.environ, GIT_NO_LAZY_FETCH='1', GIT_OPTIONAL_LOCKS='0')
        pinned_bytes = {}
        for pin in manifest['git_sources']:
            output = subprocess.check_output([
                'git', 'ls-tree', pin['commit'], '--', pin['path']
            ], cwd=args.repo, env=env, text=True)
            assert len(output.splitlines()) == 1
            header, path = output.rstrip('\n').split('\t', 1)
            assert path == pin['path'] and header.split()[2] == pin['git_blob']
            data = subprocess.check_output(['git', 'cat-file', 'blob', pin['git_blob']],
                                           cwd=args.repo, env=env)
            assert len(data) == pin['bytes'] and sha(data) == pin['sha256']
            pinned_bytes[pin['path']] = data
            checked_pins += 1
        # Validate both correction-window starts against the prior caller's
        # continuous instruction list, not arbitrary offset disassembly.
        old = json.loads(pinned_bytes['kr-extra-roy/MEF-trigger-callers-20261115/native-root/native-records.json'])
        caller = next(r for r in old['records'] if r['id'] == 'literal-tail-4bad73')
        prior = {int(i['va'], 16): i['hex'] for i in caller['instructions']}
        for window in windows:
            if window['change'].startswith('NEW_CORRECTION'):
                for ins in window['instructions']:
                    assert prior[int(ins['va'], 16)] == ins['hex']
        summary = json.loads(pinned_bytes['kr-extra-roy/MEF-P0-P1-master-continuation-20261117/master-resource-closure/master-summary.json'])
        assert summary['file_members'] == 899 and summary['attached_packages'] == 897
        assert summary['root_encsetting_present'] is False
        assert summary['resource_ready'] is False

    assert capability['p2_overall'] == 'BLOCKED'
    assert capability['official_mef']['verified_payload_count'] == 0
    assert capability['official_mef']['native_format_complete'] is False
    assert capability['official_mef']['parser_address'] is None
    assert capability['official_mef']['executor_address'] is None
    assert capability['full_program_absence_proved'] is False
    assert capability['target_execution'] is False
    assert capability['client_modified'] is False and capability['server_modified'] is False
    assert len(capability['chain_review']) == 8 and len(capability['blockers']) == 3
    assert all(not x['official_mef_grammar'] for x in capability['identified_other_formats'])
    gate = capability['official_mef']['native_format_complete']
    receipt = dict(
        schema='MEF_P2_READ_ONLY_RECEIPT_V1',
        generated_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        status='PASS', native_mef_gate='BLOCKED' if not gate else 'PASS',
        requested_native_mef_gate=args.require_native_mef,
        expected_exit_code=2 if args.require_native_mef and not gate else 0,
        binary_sha256=BIN_SHA, master_sha256=MASTER_SHA,
        native_windows=len(windows), native_bytes=sum(w['length'] for w in windows),
        instructions=sum(len(w['instructions']) for w in windows),
        native_strings=len(native['strings']), exact_instruction_anchors=len(anchors),
        direct_call_edges=len(calls), bounded_master_rule_records=len(rules),
        bounded_master_rule_bytes=sum(r['consumed'] for r in rules),
        attached_package_identity_checks=len(master_evidence['attached_package_identity_only']),
        source_pins_checked=checked_pins,
        prior_caller_start_boundaries_checked=bool(args.repo),
        official_mef_verified_samples=0, target_execution=False,
        game_member_execution=False, complete_decoded_members_exported=False,
        git_mutation=False, network_access=False,
        scope='Exact bytes, mappings, instruction boundaries, selected source pins and explicit status gate only; no T01 FULL-PASS, full-program semantic proof or gameplay result.'
    )
    print(json.dumps(receipt, ensure_ascii=False, indent=2))
    return receipt['expected_exit_code']


if __name__ == '__main__':
    raise SystemExit(main())
