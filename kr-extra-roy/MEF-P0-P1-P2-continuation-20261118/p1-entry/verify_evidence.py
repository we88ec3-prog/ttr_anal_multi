#!/usr/bin/env python3
"""Read-only replay of typed UI resource 212 and the remaining P1-B boundary.

Python standard library, immutable Git object reads and GNU objdump only.
No target/Lua/DLL/Server execution; no network; no Git or resource mutation.
The JSON receipt is printed to stdout. Run with python -B and without -O.
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
    raise RuntimeError('Run without -O: evidence checks must remain active')
sys.dont_write_bytecode = True
HERE = Path(__file__).resolve().parent
BASE = '15d9501c203c6f656461b64f578a50c96e38a5ff'
BIN_SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
MASTER_SHA = 'f59edc403213de3a3923cc47ebf44eb1812705e8693c3c196d122f51ab0c919d'


def sha(data):
    return hashlib.sha256(data).hexdigest()


def read_json(name):
    return json.loads((HERE/name).read_text())


def pe_sections(data):
    assert data[:2] == b'MZ'
    pos = struct.unpack_from('<I', data, 60)[0]
    assert data[pos:pos+4] == b'PE\0\0'
    assert struct.unpack_from('<H', data, pos+4)[0] == 0x14c
    optional = pos+24
    assert struct.unpack_from('<H', data, optional)[0] == 0x10b
    base = struct.unpack_from('<I', data, optional+28)[0]
    first = optional+struct.unpack_from('<H', data, pos+20)[0]
    records = []
    for index in range(struct.unpack_from('<H', data, pos+6)[0]):
        p = first+index*40
        vs, rva, length, raw = struct.unpack_from('<IIII', data, p+8)
        records.append(dict(name=data[p:p+8].rstrip(b'\0').decode(),
                            va=base+rva, raw=raw, bytes=length, virtual_bytes=vs))
    return base, records


def raw_for(sections, va, length):
    for sec in sections:
        if sec['va'] <= va and va+length <= sec['va']+sec['bytes']:
            return sec['raw']+va-sec['va']
    raise AssertionError(('not raw-backed', hex(va), length))


def disassemble(path, start, end):
    output = subprocess.check_output([
        'objdump', '-d', '-M', 'intel', '--insn-width=16',
        f'--start-address={start}', f'--stop-address={end}', str(path)
    ], text=True)
    result = []
    for line in output.splitlines():
        m = re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)$', line)
        if m:
            result.append(dict(va=hex(int(m[1],16)), hex=''.join(m[2].split()), asm=m[3].strip()))
    return result


def parse_packing_rules(data):
    """Structural parse in memory only; no decoded member is exported."""
    assert len(data) >= 4
    count = struct.unpack_from('<I', data)[0]
    pos = 4

    def read_text():
        nonlocal pos
        assert pos+2 <= len(data)
        n = struct.unpack_from('<H', data, pos)[0]
        pos += 2
        assert pos+n <= len(data)
        value = data[pos:pos+n].decode('ascii')
        pos += n
        return value

    rows = []
    for ordinal in range(count):
        start = pos
        package = read_text()
        source = read_text()
        assert pos+2 <= len(data)
        flags = list(data[pos:pos+2])
        pos += 2
        extensions = [read_text() for _ in range(8)]
        rows.append(dict(ordinal=ordinal, start=start, end=pos, package=package,
                         source=source, flags=flags, extensions=extensions))
    assert pos == len(data), ('unconsumed bytes', len(data)-pos)
    return rows


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--repo', type=Path, required=True)
    parser.add_argument('--sources', type=Path, required=True)
    parser.add_argument('--require-b', action='store_true', help='return 2 while ordinary B remains unproven')
    args = parser.parse_args()
    native = read_json('native-evidence.json')
    master_evidence = read_json('master-evidence.json')
    sources = read_json('source-manifest.json')
    readset = read_json('read-set.json')
    contract = read_json('candidate-contracts.json')
    artifact_manifest = read_json('artifact-manifest.json')
    assert native['baseline_commit'] == sources['baseline_commit'] == readset['baseline_commit'] == contract['baseline_commit'] == BASE
    assert sources['branch'] == contract['branch'] == 'extra/roy1'

    originals = {}
    for record in sources['original_sources']:
        payload = (args.sources/record['filename']).read_bytes()
        assert len(payload) == record['bytes'] and sha(payload) == record['sha256'], record['filename']
        originals[record['filename']] = payload
    binary = originals['02-Tartaros.bin']
    master = originals['11-Master.stp']
    assert sha(binary) == BIN_SHA and len(binary) == 12472320
    assert sha(master) == MASTER_SHA and len(master) == 1094887
    assert native['binary']['sha256'] == BIN_SHA
    assert master_evidence['source']['sha256'] == MASTER_SHA
    base, sections = pe_sections(binary)
    assert base == 0x400000 and sections == native['binary']['sections']

    git_bodies = {}
    for record in sources['git_sources']:
        assert record['commit'] == BASE
        spec = BASE+':'+record['path']
        blob = subprocess.check_output(['git','-C',str(args.repo),'rev-parse',spec],text=True).strip()
        payload = subprocess.check_output(['git','-C',str(args.repo),'show',spec])
        assert blob == record['blob']
        assert len(payload) == record['bytes'] and sha(payload) == record['sha256'], spec
        git_bodies[record['path']] = payload
    assert len(git_bodies) == len(sources['git_sources']) == len(readset['git_reads'])
    assert {x['path'] for x in readset['git_reads']} == set(git_bodies)

    def u32(va):
        return struct.unpack_from('<I', binary, raw_for(sections, va, 4))[0]

    instructions = {}
    def verify_window(record, keep=True):
        start, n = int(record['va'],16), record['bytes']
        raw = raw_for(sections, start, n)
        payload = binary[raw:raw+n]
        assert raw == int(record['raw'],16)
        assert payload.hex() == record['hex'] and sha(payload) == record['sha256'], record['id']
        if 'instructions' not in record:
            if 'dwords' in record:
                assert [hex(x) for x in struct.unpack('<'+'I'*(n//4),payload)] == record['dwords']
            if 'name' in record:
                assert payload[8:-1].decode('ascii') == record['name'] and payload[-1] == 0
            if record.get('encoding') == 'utf-16le':
                assert payload[-2:] == b'\0\0' and payload[:-2].decode('utf-16le') == record['value']
            return
        end = int(record['end'],16)
        assert end-start == n
        assert b''.join(bytes.fromhex(x['hex']) for x in record['instructions']) == payload
        cursor = start
        for item in record['instructions']:
            assert int(item['va'],16) == cursor
            fragment = bytes.fromhex(item['hex'])
            assert int(item['raw'],16) == raw_for(sections,cursor,len(fragment))
            assert '(bad)' not in item['asm'] and not item['asm'].startswith('.byte')
            if keep:
                assert item['va'] not in instructions or instructions[item['va']] == item
                instructions[item['va']] = item
            cursor += len(fragment)
        assert cursor == end
        expected = [{k:x[k] for k in ('va','hex','asm')} for x in record['instructions']]
        assert disassemble(args.sources/'02-Tartaros.bin',start,end) == expected, record['id']

    for row in native['windows']+native['data']:
        verify_window(row)
    reused_windows = []
    for record in native['reused_windows']:
        old = json.loads(git_bodies[record['source']])
        row = next(x for x in old['windows'] if x['id'] == record['id'])
        assert all(record[key] == row[key] for key in ('id','va','bytes','sha256'))
        verify_window(row)
        reused_windows.append(row)
    assert len(native['windows']) == 51 and len(native['data']) == 38 and len(reused_windows) == 11

    def instruction(va, expected):
        actual = instructions[hex(va)]['asm']
        assert actual == expected, (hex(va),actual,expected)

    def direct_call(va, target):
        row = instructions[hex(va)]
        code = bytes.fromhex(row['hex'])
        assert code[0] == 0xe8 and len(code) == 5
        assert va+5+struct.unpack_from('<i',code,1)[0] == target

    # Receiver provenance, not just a copied vtable-name claim.
    for at, expected in [
        (0x596045,'mov    DWORD PTR [ebp-0x20],0xc1920c'),
        (0x596066,'lea    ecx,[esi+0xb4]'),
        (0x59606f,'lea    edi,[ebp-0x20]'),
        (0x5a9f7a,'mov    ecx,edi'),
        (0x5a3888,'mov    DWORD PTR [ecx],edi'),
        (0x5a38a2,'push   ecx'),
        (0x5a38b1,'mov    eax,DWORD PTR [edi+0x28]'),
        (0x5856de,'mov    eax,0xfaafd8'),
        (0x44dfea,'mov    DWORD PTR ds:0xfaafd8,0xbfc9d8'),
        (0xad2991,'push   0xbef0c8'),
        (0xad2996,'mov    ecx,0xe577e8'),
        (0x585706,'lea    ecx,[eax*8+0x0]'),
        (0x58570d,'sub    ecx,eax'),
        (0x585717,'lea    eax,[ecx*4+0xe560b8]'),
        (0x7645d1,'mov    DWORD PTR [ebx+0x18],ebx'),
        (0x776c87,'cmp    DWORD PTR [ebp-0x4],eax'),
        (0x776c8e,'mov    eax,DWORD PTR [edx+0x14]'),
        (0x748ff1,'mov    ecx,DWORD PTR [ebx+0x18]'),
        (0x748ff4,'mov    DWORD PTR [esp+0x18],0x0'),
        (0x749013,'mov    eax,DWORD PTR [eax+0x110]'),
        (0x74901b,'mov    eax,DWORD PTR [esp+0x18]'),
        (0x749025,'mov    eax,DWORD PTR [edx+0x60]'),
        (0x749044,'mov    DWORD PTR [eax+0x18],ecx'),
        (0x49ae10,'ret    0xc'),
        (0x40ecf0,'mov    eax,0xcf08'),
        (0x409510,'mov    eax,DWORD PTR [ecx+0x8]'),
        (0x409526,'mov    DWORD PTR [ecx+0x8],eax'),
        (0x44e220,'mov    eax,DWORD PTR [edx+0xc]'),
        (0x44e223,'push   0x1'),
        (0x44e247,'mov    eax,DWORD PTR [edx+0x10]'),
        (0x44e265,'mov    DWORD PTR [edi+0x20],esi'),
        (0x5960f9,'push   0xd4'),
        (0x409631,'mov    ecx,DWORD PTR [eax+0x60]'),
        (0x40963b,'mov    eax,DWORD PTR [edx+0x74]'),
        (0x40964d,'mov    eax,DWORD PTR [edx+0x30]'),
        (0x746737,'mov    DWORD PTR [eax+0x60],0x0'),
        (0x44e42a,'mov    edx,DWORD PTR [esi+0x4]'),
        (0x44e431,'lea    ecx,[edi+0x14]'),
        (0x44e441,'cmp    ecx,DWORD PTR [edi+0x18]'),
        (0x44e444,'jne    0x44e45f'),
        (0x44e456,'mov    eax,DWORD PTR [edx+0x1c]'),
        (0x745685,'mov    edx,DWORD PTR [eax+0x10c]'),
        (0x74568b,'xor    DWORD PTR [esi+0x28],0x200000'),
        (0x745607,'mov    edx,DWORD PTR [eax+0x108]'),
        (0x74566b,'or     DWORD PTR [edi+0x28],0x200000'),
        (0x5f5d10,'ret'),
        (0x74711b,'mov    DWORD PTR [esi],0xc49c6c'),
        (0x745048,'mov    DWORD PTR [esi],0xc4697c')
    ]:
        instruction(at,expected)
    calls = [
        (0x596072,0x5a9f40),(0x5a9f7c,0x5a3840),(0x5856cc,0x44dfb0),
        (0xad299f,0x402250),(0x44e1db,0x764cf0),(0x764d45,0x72f110),
        (0x72f189,0x714770),(0x72f19f,0x72f260),(0x44e217,0x764520),
        (0x44e369,0x764520),(0x7645d4,0x776c60),(0x44e25c,0x44e6c0),
        (0x44e276,0x443d10),(0x59607a,0x40b670),(0x5ad076,0x5ac500),
        (0x5afde6,0x5ac500),(0x5ac526,0x599590),(0x5995b7,0x5a3cc0),
        (0x5a3cec,0x5960b0),(0x596108,0x4095e0),(0x44e425,0x745680),
        (0x44e468,0x7b6890),(0x40b6d1,0x745590),(0x40b6dc,0x745600),
        (0x747116,0x754880),(0x7476eb,0x745040)
    ]
    for at,target in calls:
        direct_call(at,target)

    slots = [
        (0xc1920c,0x14,0x585690),(0xc1920c,0x18,0x404aa0),(0xc1920c,0x1c,0x585700),
        (0xbfc9d8,0x28,0x44e120),(0xbfc9d8,0x30,0x44e3f0),
        (0xc1b514,0x8,0x409510),(0xc1b514,0xc,0x409520),(0xc1b514,0x10,0x5ade20),
        (0xc3eb44,0x4,0x40ecf0),(0xc3eb44,0x14,0x748c40),
        (0xc3eb44,0x108,0x5f5d10),(0xc3eb44,0x10c,0x5f5d10),(0xc3eb44,0x110,0x49ae10),
        (0xc3eb44,0x114,0x6bd4f0),
        (0xc1d1ac,0x10c,0x5ad050),(0xc1d62c,0x10c,0x5afdc0),
        (0xc1d1ac,0x74,0x746700),(0xc1d62c,0x74,0x746700),
        (0xc49c6c,0x14,0x75eb80),(0xc4697c,0x14,0x744450),
        (0xc4d474,0x14,0x76e160),(0xc4d4b4,0x14,0x76e4f0),(0xc4d4f4,0x14,0x76e160)
    ]
    for vt,offset,target in slots:
        assert u32(vt+offset) == target
    for vt in [0xc49c6c,0xc4697c]:
        for offset in [0x104,0x108,0x10c,0x114]:
            assert u32(vt+offset) == 0x5f5d10
        assert u32(vt+0x110) == 0x49ae10
    assert 0xe560b8+212*28 == 0xe577e8
    assert binary[raw_for(sections,0x7481f4,1)] == 0 and u32(0x7481bc) == 0x7470f3
    assert 0x7482e8+(1400-1301) == 0x74834b
    assert binary[raw_for(sections,0x74834b,1)] == 1 and u32(0x7482d4) == 0x7476ca

    for row in master_evidence['windows']:
        start,n=int(row['raw'],16),row['bytes']
        physical=master[start:start+n]
        decoded=bytes(x^255 for x in physical)
        assert sha(physical)==row['physical_sha256'] and sha(decoded)==row['decoded_sha256']
        if row['representation']=='identity-and-hashes-only':
            assert row['id']=='M01' and 'physical_hex' not in row and 'decoded_hex' not in row
            assert row['complete_member_bytes_exported'] is False
            assert decoded.decode('ascii')+'.stp'==row['derived_provider']=='UI/Component.stp'
        else:
            assert row['representation']=='bounded-record-excerpt' and row['id']=='M02'
            assert physical.hex()==row['physical_hex'] and decoded.hex()==row['decoded_hex']
    rules = master_evidence['packing_rules']
    raw=int(rules['raw'],16)
    decoded=bytes(x^255 for x in master[raw:raw+rules['bytes']])
    rows=parse_packing_rules(decoded)
    assert len(rows)==rules['count']==897
    chosen=rows[rules['selected_ordinal']]
    assert chosen['start']==rules['selected_offset']==90777 and chosen['end']==rules['selected_end']==90845
    assert chosen['package']=='UI/Component' and chosen['source']=='UI\\Component\\'
    assert chosen['flags']==[1,1] and chosen['extensions']==['ftc','fft','fcs','fis','fsd','etf','obj','']

    status=contract['status']
    assert status['ordinary_B']=='NOT_CLOSED' and status['ordinary_B_enabled'] is False
    assert status['new_typed_UI_resource_lifecycle']=='BOUNDED_STATIC_CLOSED'
    for key in ['native_MEF_grammar_complete','script_owner_cancel_and_reentry_proven',
                'runtime_resource_load_observed','target_execution','server_implemented_by_this_package','T01_FULL_PASS_claimed']:
        assert status[key] is False
    assert len(contract['new_candidates'])==5
    assert all(x['ordinary_B_positive'] is False for x in contract['new_candidates'])
    assert contract['selected_resource']['path']=='UI/Component/TalkBox_Scenario_Panel.FTC'
    assert contract['selected_resource']['supplied_payload'] is False
    assert contract['selected_resource']['actual_children'] is None
    assert contract['selected_resource']['loaded_payload_hash'] is None
    assert contract['selected_resource']['declared_provider']=='UI/Component.stp'
    assert [(x['lookup_id'],x['required_class_id']) for x in contract['required_child_contracts']]==[(1100,200),(1200,200),(2000,1400),(2100,1400)]

    for record in artifact_manifest['files']:
        assert '/' not in record['path'] and record['path'] not in ['artifact-manifest.json','verification-result.json']
        payload=(HERE/record['path']).read_bytes()
        assert len(payload)==record['bytes'] and sha(payload)==record['sha256'],record['path']
    assert len(artifact_manifest['files'])==9
    receipt=dict(
        schema='mef.p1-ui-resource-entry.verification.v1',
        checked_at_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),
        result='PASS',baseline_commit=BASE,branch='extra/roy1',
        checks=dict(original_sources=len(originals),immutable_git_sources=len(git_bodies),
                    code_windows=len(native['windows']),code_bytes=sum(x['bytes'] for x in native['windows']),
                    instructions=sum(len(x['instructions']) for x in native['windows']),
                    data_windows=len(native['data']),reused_native_windows=len(reused_windows),
                    semantic_direct_calls=len(calls),typed_vtable_slots=len(slots)+10,
                    master_evidence_records=len(master_evidence['windows']),master_member_identity_only=1,
                    master_bounded_record_excerpts=1,packing_rules_structurally_replayed=len(rows),
                    selected_factory_routes=2,contract_candidates=len(contract['new_candidates']),artifact_files=len(artifact_manifest['files'])),
        ordinary_B='NOT_CLOSED',ordinary_B_enabled=False,
        typed_UI_resource_lifecycle='BOUNDED_STATIC_CLOSED',
        resource_selected_child_graph='BLOCKED_ON_IDENTIFIED_SOURCE',
        actual_target_execution=False,complete_decoded_members_exported=False,
        verification_scope='Byte identity, immutable sources, instruction boundaries, explicit typed dataflow and conservative contract state; not global semantic completeness, T01 FULL-PASS, gameplay or Server acceptance.')
    if args.require_b:
        receipt['result']='NOT_READY'
        receipt['evidence_checks']='PASS'
        receipt['required_gate']='ordinary_B'
        print(json.dumps(receipt,ensure_ascii=False,indent=2))
        return 2
    print(json.dumps(receipt,ensure_ascii=False,indent=2))
    return 0


if __name__=='__main__':
    raise SystemExit(main())
