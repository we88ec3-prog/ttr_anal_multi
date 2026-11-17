#!/usr/bin/env python3
"""Read-only verification of bounded P1 entry-B evidence.

Only Python standard library, git object reads and GNU objdump are used.
The target executable, Lua, Server, and archive members are never executed.
No network access, Git mutation, extraction output or game-resource writes.
Run with python -B and without -O. JSON receipt is printed to stdout.
"""
import argparse
import datetime
import hashlib
import json
import re
import struct
import subprocess
import sys
from pathlib import Path

if sys.flags.optimize:
    raise RuntimeError('Run without -O: assertions are evidence checks')
sys.dont_write_bytecode = True

HERE = Path(__file__).resolve().parent
BASELINE = '5ed4833b805949fabe260aea77e3fe0fd8e86bfa'
BIN_SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
MASTER_SHA = 'f59edc403213de3a3923cc47ebf44eb1812705e8693c3c196d122f51ab0c919d'


def sha(data):
    return hashlib.sha256(data).hexdigest()


def read_json(name):
    return json.loads((HERE / name).read_text())


def pe_sections(data):
    assert data[:2] == b'MZ'
    header = struct.unpack_from('<I', data, 60)[0]
    assert data[header:header+4] == b'PE\0\0'
    assert struct.unpack_from('<H', data, header+4)[0] == 0x14c
    optional = header+24
    assert struct.unpack_from('<H', data, optional)[0] == 0x10b
    base = struct.unpack_from('<I', data, optional+28)[0]
    start = optional+struct.unpack_from('<H', data, header+20)[0]
    sections = []
    for index in range(struct.unpack_from('<H', data, header+6)[0]):
        pos = start+index*40
        _, rva, length, offset = struct.unpack_from('<IIII', data, pos+8)
        sections.append(dict(name=data[pos:pos+8].rstrip(b'\0').decode(),
                             va=base+rva, raw=offset, bytes=length))
    return base, sections


def raw_for(sections, va, length):
    for sec in sections:
        if sec['va'] <= va and va+length <= sec['va']+sec['bytes']:
            return sec['raw']+va-sec['va']
    raise AssertionError(('VA not raw-backed', hex(va), length))


def native_census(data, sections, targets, literal_targets):
    answer = {hex(t): dict(relative=[], literal=[]) for t in literal_targets}
    wanted = set(targets)
    for sec in sections:
        if sec['name'] not in ('.text', '.rdata', '.data'):
            continue
        block = data[sec['raw']:sec['raw']+sec['bytes']]
        for target in literal_targets:
            pos = 0
            needle = struct.pack('<I', target)
            while True:
                pos = block.find(needle, pos)
                if pos < 0:
                    break
                answer[hex(target)]['literal'].append(
                    dict(section=sec['name'], va=hex(sec['va']+pos)))
                pos += 1
        if sec['name'] == '.text':
            for pos in range(len(block)-4):
                if block[pos] not in (0xe8, 0xe9):
                    continue
                dest = sec['va']+pos+5+struct.unpack_from('<i', block, pos+1)[0]
                if dest in wanted:
                    answer[hex(dest)]['relative'].append(
                        dict(va=hex(sec['va']+pos), opcode=hex(block[pos])))
    return answer


def original_disassembly(binary_path, start, end):
    output = subprocess.check_output([
        'objdump', '-d', '-M', 'intel', '--insn-width=16',
        f'--start-address={start}', f'--stop-address={end}', str(binary_path)
    ], text=True)
    result = []
    for line in output.splitlines():
        match = re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)$', line)
        if match:
            result.append(dict(va=hex(int(match[1], 16)),
                               hex=''.join(match[2].split()), asm=match[3].strip()))
    return result


def direct_stores(window, register):
    result = []
    pattern = (r'^(mov|or|and|xor|add|sub|inc|dec)\s+(BYTE|DWORD|WORD) PTR \['
               + register + r'(?:\+0x([0-9a-f]+))?\]')
    for instruction in window['instructions']:
        match = re.match(pattern, instruction['asm'])
        if match:
            result.append(dict(va=instruction['va'],
                               offset=hex(int(match[3] or '0', 16)),
                               width={'BYTE': 1, 'WORD': 2, 'DWORD': 4}[match[2]],
                               asm=instruction['asm']))
    return result


def parse_rule(data):
    pos = 0

    def text():
        nonlocal pos
        assert pos+2 <= len(data)
        length = struct.unpack_from('<H', data, pos)[0]
        pos += 2
        assert pos+length <= len(data)
        value = data[pos:pos+length].decode('ascii')
        pos += length
        return value

    package = text()
    source = text()
    assert pos+2 <= len(data)
    flags = list(data[pos:pos+2])
    pos += 2
    extensions = [text() for _ in range(8)]
    assert pos == len(data)
    return dict(package=package, source_directory=source,
                flag_bytes=flags, extensions=extensions, bytes_consumed=pos)


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--binary', type=Path, required=True)
    parser.add_argument('--master', type=Path, required=True)
    parser.add_argument('--repo', type=Path, default=HERE.parents[2])
    args = parser.parse_args()

    native = read_json('native-evidence.json')
    masters = read_json('master-carrier-evidence.json')
    contract = read_json('candidate-contracts.json')
    sources = read_json('source-manifest.json')
    artifacts = read_json('artifact-manifest.json')
    binary = args.binary.read_bytes()
    master = args.master.read_bytes()
    assert len(binary) == 12472320 and sha(binary) == BIN_SHA
    assert len(master) == 1094887 and sha(master) == MASTER_SHA
    assert native['baseline_commit'] == sources['baseline_commit'] == BASELINE
    assert native['binary']['sha256'] == BIN_SHA
    assert masters['source']['sha256'] == MASTER_SHA
    assert sources['branch'] == 'extra/roy1'

    source_count = 0
    for record in sources['git_sources']:
        assert record['commit'] == BASELINE
        spec = record['commit']+':'+record['path']
        blob = subprocess.check_output(['git', '-C', str(args.repo), 'rev-parse', spec], text=True).strip()
        body = subprocess.check_output(['git', '-C', str(args.repo), 'show', spec])
        assert blob == record['blob'], spec
        assert len(body) == record['bytes'] and sha(body) == record['sha256'], spec
        source_count += 1

    image_base, sections = pe_sections(binary)
    assert image_base == 0x400000
    assert sections == native['binary']['sections']
    windows = {record['id']: record for record in native['windows']}
    assert len(windows) == len(native['windows'])
    instructions = {}
    instruction_count = 0
    for record in native['windows']+native['data']:
        start, length = int(record['va'], 16), record['bytes']
        offset = raw_for(sections, start, length)
        original = binary[offset:offset+length]
        assert offset == int(record['raw'], 16), record['id']
        assert original.hex() == record['hex'] and sha(original) == record['sha256'], record['id']
        if 'instructions' not in record:
            if 'dwords' in record:
                assert [hex(x) for x in struct.unpack('<'+'I'*(length//4), original)] == record['dwords']
            if 'name' in record:
                assert original[8:-1].decode('ascii') == record['name'] and original[-1] == 0
            continue
        end = int(record['end'], 16)
        assert end-start == length
        current = start
        assert b''.join(bytes.fromhex(x['hex']) for x in record['instructions']) == original
        for item in record['instructions']:
            assert int(item['va'], 16) == current
            item_bytes = bytes.fromhex(item['hex'])
            assert int(item['raw'], 16) == raw_for(sections, current, len(item_bytes))
            assert '(bad)' not in item['asm'] and not item['asm'].startswith('.byte')
            assert item['va'] not in instructions
            instructions[item['va']] = item
            current += len(item_bytes)
        assert current == end
        expected = [{k: x[k] for k in ('va', 'hex', 'asm')} for x in record['instructions']]
        assert original_disassembly(args.binary, start, end) == expected, record['id']
        instruction_count += len(expected)

    targets = [0x6bce70, 0x597d20, 0x597bc0, 0x596010, 0x6bda20, 0x6bde20]
    assert native_census(binary, sections, targets, targets+[0xfe3180, 0xfe2c5c]) == native['candidate_census']

    def u32(va):
        return struct.unpack_from('<I', binary, raw_for(sections, va, 4))[0]

    def instruction(va, expected):
        actual = instructions[hex(va)]['asm']
        assert actual == expected, (hex(va), actual, expected)

    def call(va, target):
        data = bytes.fromhex(instructions[hex(va)]['hex'])
        assert data[0] == 0xe8 and len(data) == 5
        assert va+5+struct.unpack_from('<i', data, 1)[0] == target

    for at, target in [
        (0x596061, 0x597bc0), (0x597c0d, 0x597d20), (0x597d7d, 0x6bce70),
        (0x6bcf16, 0x6bda20), (0x5a39b9, 0x596010),
        (0x5a65ca, 0x596010), (0x5a714a, 0x596010),
        (0x6bde25, 0x4a2bb0), (0x748d2b, 0x755d10),
        (0x748d39, 0x755d10), (0x40eba6, 0x404de0)
    ]:
        call(at, target)
    for va, target in {
        0xc1d1ac+0x108: 0x5acea0, 0xc1d62c+0x108: 0x5afc30,
        0xc1b514+0x10: 0x5ade20, 0xc1b514+4: 0x7b3250,
        0xc3eb44+0x14: 0x748c40, 0xc3eb44+0x28: 0x40eb40,
        0xc3eb44+0x34: 0x7456f0, 0xc3eb44+0x114: 0x6bd4f0,
        0xc4909c+0x114: 0x5f5d10,
        0xc3eb44+0x50: 0x749890, 0xc3eb44+0x60: 0x746fe0,
        0xc3eb44+0x64: 0x746fd0, 0xc3eb44+0x70: 0x746640,
    }.items():
        assert u32(va) == target, hex(va)
    for at, expected in {
        0x596066: 'lea    ecx,[esi+0xb4]',
        0x597d5e: 'push   0xac',
        0x597d86: 'mov    DWORD PTR [esi+0xc],eax',
        0x597d89: 'mov    DWORD PTR [esi+0x4],0xd4',
        0x5a3888: 'mov    DWORD PTR [ecx],edi',
        0x6bcf0e: 'push   0xfdf3c8',
        0x6bcf14: 'mov    eax,esi',
        0x6bda2b: 'mov    ds:0xfe3180,eax',
        0x6bda37: 'mov    DWORD PTR ds:0xfe317c,ebx',
        0x6bde2a: 'mov    ds:0xfe3180,eax',
        0x4a2bba: 'or     eax,0xffffffff',
        0x4a2bc5: 'cmp    ecx,0x3',
        0x4a2bca: 'cmp    ecx,0x4',
        0x4a2bf8: 'fistp  DWORD PTR [ebp-0x4]',
        0x748c83: 'mov    ebx,ecx',
        0x748d23: 'lea    edi,[ebx+0x8]',
        0x748d31: 'lea    edi,[ebx+0x2c]',
        0x40eb67: 'push   0x80',
        0x40eb8b: 'mov    DWORD PTR [edi],0xc4909c',
        0x43c5ed: 'cmp    eax,0xc8',
        0x43c646: 'mov    DWORD PTR [edi],esi',
        0x46b76d: 'cmp    eax,0x578',
        0x46b7c6: 'mov    DWORD PTR [edi],esi',
    }.items():
        instruction(at, expected)

    expected_refs = native['candidate_census']['0xfe3180']['literal']
    assert {x['va'] for x in expected_refs} == {x['literal'] for x in contract['absolute_receiver_references']}
    assert len(expected_refs) == 8
    for reference in contract['absolute_receiver_references']:
        item = instructions[reference['instruction']]
        assert int(reference['instruction'], 16) <= int(reference['literal'], 16) < int(reference['instruction'], 16)+len(bytes.fromhex(item['hex']))
        if reference['role'] == 'marshaller read':
            assert item['asm'] == 'mov    ecx,DWORD PTR ds:0xfe3180'
        else:
            assert item['asm'].startswith(('mov    ds:0xfe3180,', 'mov    DWORD PTR ds:0xfe3180,'))

    reader_stores = direct_stores(windows['B09'], 'ebx')
    copy_stores = direct_stores(windows['B11'], 'edi')
    assert reader_stores == contract['inherited_read_direct_this_stores']
    assert copy_stores == contract['inherited_copy_direct_destination_stores']
    assert {int(x['offset'], 16) for x in reader_stores} == {0x1c, 0x20, 0x28, 0x3c, 0x48, 0x5c, 0x68}
    assert max(int(x['offset'], 16)+x['width'] for x in copy_stores) <= 0x74
    assert not any(int(x['offset'], 16) <= 0x9c < int(x['offset'], 16)+x['width'] for x in reader_stores+copy_stores)
    register_writes = [x for x in windows['B09']['instructions'] if re.match(r'^(mov|lea|pop|xor|add|sub|and|or|inc|dec|movzx|movsx|xchg|shl|shr|sar|rol|ror|imul)\s+ebx\b', x['asm'])]
    assert [(x['va'], x['asm']) for x in register_writes] == [('0x748c83', 'mov    ebx,ecx'), ('0x749448', 'pop    ebx')]
    rect_offsets = {int(x['offset'], 16) for x in direct_stores(windows['B10'], 'edi')}
    assert rect_offsets == {0, 4, 8, 12}

    decoded_master = {}
    for record in masters['windows']:
        offset, size = int(record['raw'], 16), record['bytes']
        stored = master[offset:offset+size]
        decoded = bytes(x ^ 255 for x in stored)
        assert stored.hex() == record['stored_hex'] and sha(stored) == record['stored_sha256']
        assert decoded.hex() == record['decoded_hex'] and sha(decoded) == record['decoded_sha256']
        decoded_master[record['id']] = decoded
        if 'parsed_record' in record:
            assert parse_rule(decoded) == record['parsed_record']
    assert decoded_master['M01'] == b'Field'
    assert decoded_master['M02'] == b'UI/LUA'
    assert struct.unpack('<I', decoded_master['M03'])[0] == 897
    field = parse_rule(decoded_master['M04'])
    ui = parse_rule(decoded_master['M05'])
    assert field == dict(package='Field', source_directory='Field\\', flag_bytes=[0, 1], extensions=['xml', 'mef', '', '', '', '', '', ''], bytes_consumed=39)
    assert ui['package'] == 'UI/LUA' and ui['extensions'][7] == 'lua' and ui['bytes_consumed'] == 59

    assert contract['status'] == dict(selected_static_analysis='COMPLETE', ordinary_entry_B='NOT_CLOSED', runtime_ready=False, formal_acceptance='UNCHANGED')
    assert len(contract['new_candidates']) == 5
    assert sum(x['state'] == 'MISSING' for x in contract['ordinary_B_required_edges']) == 3
    assert all(x['outcome'] != 'POSITIVE_ENTRY_B' for x in contract['new_candidates'])
    artifact_count = 0
    for record in artifacts['files']:
        target = HERE/record['path']
        assert target.resolve().parent == HERE
        content = target.read_bytes()
        assert len(content) == record['bytes'] and sha(content) == record['sha256'], record['path']
        artifact_count += 1

    # These final reads guard against accidental source modification during verification.
    assert sha(args.binary.read_bytes()) == BIN_SHA
    assert sha(args.master.read_bytes()) == MASTER_SHA
    receipt = dict(
        status='PASS',
        verified_at_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        baseline_commit=BASELINE,
        binary_sha256=BIN_SHA,
        master_sha256=MASTER_SHA,
        checks=dict(git_source_pins=source_count, code_windows=len(windows),
                    code_bytes=sum(x['bytes'] for x in windows.values()),
                    instruction_bytes_and_disassembly=instruction_count,
                    native_data_windows=len(native['data']), bounded_census_targets=len(native['candidate_census']),
                    absolute_receiver_refs=8, master_windows=len(masters['windows']),
                    selected_complete_packing_rows=2, candidate_decisions=5,
                    artifact_hashes=artifact_count),
        tools=dict(python=sys.version.split()[0], objdump=subprocess.check_output(['objdump', '--version'], text=True).splitlines()[0]),
        effects=dict(target_execution=False, resource_execution=False, network=False,
                     source_writes=False, git_writes=False),
        conclusion=dict(selected_static_analysis='COMPLETE', ordinary_entry_B='NOT_CLOSED',
                        runtime_ready=False, formal_acceptance='UNCHANGED'),
        meaning='Bounded original evidence, source pins and declared contracts match; not a whole-program proof or playable acceptance.'
    )
    print(json.dumps(receipt, ensure_ascii=False, indent=2))


if __name__ == '__main__':
    main()
