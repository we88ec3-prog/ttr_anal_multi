#!/usr/bin/env python3
"""Read-only verification of pinned MEF world-result native evidence.

Reads the original PE, immutable Git objects, and sibling analysis files.
Runs host objdump only; never imports/executes the target Client, Lua or Server.
Prints a JSON receipt to stdout. Does not write input/source/repository files.
"""
import argparse
import datetime
import hashlib
import json
from pathlib import Path
import re
import struct
import subprocess
import sys

sys.dont_write_bytecode = True
BASELINE = '5ed4833b805949fabe260aea77e3fe0fd8e86bfa'
BIN_SHA = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
BIN_BYTES = 12472320
HERE = Path(__file__).resolve().parent


def sha(data):
    return hashlib.sha256(data).hexdigest()


def require(ok, message):
    if not ok:
        raise ValueError(message)


def normal(text):
    return ' '.join(text.split())


class PE:
    def __init__(self, path):
        self.path = Path(path)
        self.b = self.path.read_bytes()
        require(len(self.b) == BIN_BYTES and sha(self.b) == BIN_SHA, 'original BIN bytes/SHA mismatch')
        require(self.b[:2] == b'MZ', 'MZ header')
        p = struct.unpack_from('<I', self.b, 60)[0]
        require(self.b[p:p+4] == b'PE\0\0', 'PE signature')
        require(struct.unpack_from('<H', self.b, p+4)[0] == 0x14c, 'i386 machine')
        o = p+24
        require(struct.unpack_from('<H', self.b, o)[0] == 0x10b, 'PE32 optional header')
        self.base = struct.unpack_from('<I', self.b, o+28)[0]
        require(self.base == 0x400000, 'image base')
        h = o + struct.unpack_from('<H', self.b, p+20)[0]
        self.sections = []
        for i in range(struct.unpack_from('<H', self.b, p+6)[0]):
            z = h+40*i
            _, rv, n, ro = struct.unpack_from('<4I', self.b, z+8)
            name = self.b[z:z+8].rstrip(b'\0').decode('ascii')
            require(ro+n <= len(self.b), 'section raw extent')
            self.sections.append((name, self.base+rv, n, ro))

    def raw(self, va, length=1):
        found = [raw+va-start for _, start, size, raw in self.sections if start <= va and va+length <= start+size]
        require(len(found) == 1, f'VA is not one complete raw-backed section: {va:#x}, {length}')
        return found[0]

    def at(self, va, length):
        r = self.raw(va, length)
        return self.b[r:r+length]

    def u32(self, va):
        return struct.unpack('<I', self.at(va, 4))[0]

    def string(self, va):
        r = self.raw(va)
        end = self.b.index(0, r)
        return self.b[r:end].decode('ascii')

    def refs(self, target):
        literal, relative = [], []
        for name, start, size, raw in self.sections:
            data = self.b[raw:raw+size]
            if name in ('.text', '.data', '.rdata'):
                k = -1
                while True:
                    k = data.find(struct.pack('<I', target), k+1)
                    if k < 0:
                        break
                    literal.append([name, hex(start+k)])
            if name == '.text':
                for op in (0xe8, 0xe9):
                    k = -1
                    while True:
                        k = data.find(bytes([op]), k+1)
                        if k < 0 or k+5 > len(data):
                            break
                        if (start+k+5+struct.unpack_from('<i', data, k+1)[0]) & 0xffffffff == target:
                            relative.append([hex(start+k), hex(op)])
        return {'relative': relative, 'literal': literal}

    def decode(self, start, end):
        output = subprocess.check_output([
            'objdump', '-D', '-Mintel', '--insn-width=16',
            '--start-address='+hex(start), '--stop-address='+hex(end+15), str(self.path)
        ], text=True)
        rows, cursor = [], start
        for line in output.splitlines():
            m = re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)$', line)
            if not m or not start <= int(m[1], 16) < end:
                continue
            va, data, asm = int(m[1], 16), bytes.fromhex(m[2]), m[3].strip()
            require(va == cursor and va+len(data) <= end, f'noncontiguous/overrun instruction {va:#x}')
            require(data == self.at(va, len(data)) and '(bad)' not in asm, f'instruction raw mismatch/bad {va:#x}')
            rows.append({'va': hex(va), 'hex': data.hex(), 'asm': asm})
            cursor += len(data)
        require(cursor == end, f'endpoint is not an instruction boundary: {cursor:#x} vs {end:#x}')
        return rows


def run(args):
    native = json.loads((HERE/'native-evidence.json').read_text())
    sources = json.loads((HERE/'source-manifest.json').read_text())
    contracts = json.loads((HERE/'contracts.json').read_text())
    readset = json.loads((HERE/'read-set.json').read_text())
    p = PE(args.bin)
    require(sources['baseline_commit'] == contracts['baseline_commit'] == readset['baseline'] == BASELINE, 'source baseline agreement')
    require(native['binary_sha256'] == contracts['binary_sha256'] == sources['original']['sha256'] == BIN_SHA, 'original source identity agreement')
    require(native['binary_bytes'] == sources['original']['bytes'] == BIN_BYTES, 'original byte count agreement')
    require(len(native['windows']) == 31 and len(native['data']) == 38, 'expected research window inventory')
    byid, instructions, decoded_count, code_bytes = {}, {}, 0, 0
    for window in native['windows']:
        start, end = int(window['start'], 16), int(window['end'], 16)
        data = p.at(start, end-start)
        require(window['id'] not in byid, 'duplicate window ID')
        byid[window['id']] = window
        require(window['bytes'] == len(data), f"window length {window['id']}")
        require(int(window['raw'], 16) == p.raw(start, len(data)), f"window raw offset {window['id']}")
        require(window['sha256'] == sha(data) and window['hex'] == data.hex(), f"window bytes {window['id']}")
        decoded = p.decode(start, end)
        require(len(decoded) == len(window['instructions']), f"instruction count {window['id']}")
        for actual, saved in zip(decoded, window['instructions']):
            require(actual['va'] == saved['va'] and actual['hex'] == saved['hex'] and normal(actual['asm']) == normal(saved['asm']), f"instruction {saved['va']}")
            instructions[int(actual['va'], 16)] = actual
        decoded_count += len(decoded)
        code_bytes += len(data)
    require(code_bytes == 21123 and decoded_count == 5955, 'instruction/byte inventory')
    for record in native['data']:
        va, length = int(record['va'], 16), record['bytes']
        data = p.at(va, length)
        require(p.raw(va, length) == int(record['raw'], 16), f"data raw offset {record['id']}")
        require(record['sha256'] == sha(data) and record['hex'] == data.hex(), f"data bytes {record['id']}")
    require(readset['new_native_windows'] == [{k: w[k] for k in ('id', 'start', 'end', 'scope')} for w in native['windows']], 'read-set window consistency')
    require(readset['reused_windows'] == native['reused_windows'], 'read-set reused windows')

    # Immutable object pins: these do not depend on current HEAD/worktree contents.
    immutable = {}
    for ref in sources['references']:
        require(ref['commit'] == BASELINE, 'source ref commit')
        data = subprocess.check_output(['git', 'show', ref['commit']+':'+ref['path']], cwd=args.repo)
        blob = hashlib.sha1(b'blob '+str(len(data)).encode()+b'\0'+data).hexdigest()
        require(len(data) == ref['bytes'] and sha(data) == ref['sha256'] and blob == ref['git_blob'], 'immutable source pin '+ref['path'])
        immutable[ref['path']] = data
    require(len(immutable) == 75, 'source pin inventory')
    for reused in native['reused_windows']:
        source = json.loads(immutable[reused['path']])
        previous = next(w for w in source['windows'] if w['id'] == reused['id'])
        start, end = int(reused['start'], 16), int(reused['end'], 16)
        require(start == int(previous.get('start', previous.get('va')), 16) and end == int(previous['end'], 16), 'reuse source range '+reused['id'])
        require(sha(p.at(start, end-start)) == reused['sha256'] == previous['sha256'], 'reuse original bytes '+reused['id'])
        require(reused['bytes'] == end-start, 'reuse byte length')
        if 'hex' in previous:
            require(p.at(start, end-start).hex() == previous['hex'], 'reuse saved hex '+reused['id'])
    require(len(native['reused_windows']) == 17, 'reuse inventory')
    instruction_status = 'NOT_REQUESTED'
    if args.shared_instructions:
        data = Path(args.shared_instructions).read_bytes()
        require(len(data) == sources['shared_instructions']['bytes'] and sha(data) == sources['shared_instructions']['sha256'], 'shared instructions pin')
        instruction_status = 'PASS'

    # These are literal/E8/E9 candidate scans, not a complete alias or execution proof.
    for target, expected in native['candidate_census'].items():
        require(p.refs(int(target, 16)) == expected, 'finite candidate census '+target)
    require(len(native['candidate_census']) == 9, 'candidate census inventory')

    # Independent fixed anchors encode concrete typed-field, caller and ABI findings.
    anchors = {
        0x4afb20:'0fb756fe', 0x4afb38:'e8c3f33700', 0x4afb5b:'0fb74602',
        0x4afb61:'8b522c', 0x4afb65:'0fb706', 0x4afb69:'ffd2', 0x4afb6b:'83c606',
        0x4d1e3b:'8986b0030000', 0x4d1e64:'d9580c',
        0x4b313c:'8990bc030000', 0x4b3142:'8988c8030000', 0x4b3148:'899830040000',
        0x4b31f5:'8987c4030000', 0x4b31fb:'898fd0030000',
        0x4b321c:'8987c0030000', 0x4b3222:'898fcc030000',
        0x4b3243:'8987bc030000', 0x4b3249:'898fc8030000',
        0x5d478f:'e85cd4ffff',
        0x549bb6:'8b88c8030000', 0x549bc2:'8b90cc030000', 0x549bcc:'8b80d0030000',
        0x54ae83:'e8f8eaffff',
        0x530ebc:'83c060', 0x530ec5:'8985e4feffff',
        0x5310ea:'689cf0c000', 0x53111e:'68a0f0c000', 0x531152:'68a4f0c000',
        0x53150c:'8b55dc', 0x53150f:'8b4de0', 0x531512:'8910', 0x531517:'894804',
        0x53059e:'0fbf00', 0x53062e:'0fbf4002', 0x5306be:'0fbf4004',
        0x6d89ed:'f30f1145fc', 0x6d89f2:'f30f1145f8',
        0x6d89f7:'66894de6', 0x6d89fb:'668955e4', 0x6d89ff:'e80c000000',
        0x6d85a4:'d94218', 0x6d85b1:'d95218',
        0x6d87e2:'d94318', 0x6d87e5:'d87314', 0x6d8968:'e893420f00',
        0x4928a8:'e8d35b2400', 0x492ebd:'e89e572400',
        0x4b1860:'e89b8bfdff', 0x4b186c:'e84f712200',
    }
    for va, expected in anchors.items():
        require(va in instructions and instructions[va]['hex'] == expected, f'fixed semantic anchor {va:#x}')
    asm_anchors = {
        0x5d1c77:'mov eax,DWORD PTR [ebx+0x158]',
        0x5d1c81:'cmp DWORD PTR [eax+0x34],0x0',
        0x6d8a6c:'mov ecx,0x7',
        0x6d8a71:'rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]',
        0x6d8a73:'add DWORD PTR [ebx+0x4],0x1c',
        0x6d8a07:'ret 0x1c',
        0x4b18c7:'xor edx,edx',
        0x4b18c9:'add eax,0xb4',
        0x4b0e55:'jmp 0x4b18c9',
        0x4b1186:'jmp 0x4b18c9',
    }
    for va, expected in asm_anchors.items():
        require(va in instructions and normal(instructions[va]['asm']) == normal(expected), f'typed/control-flow anchor {va:#x}')

    slots = {
        0xc0c9dc:{0:0x4d18d0,0x14:0x4d1f80,0x2c:0x4d1e10,0x50:0x4c8fa0,0x70:0x4c7040,0x74:0x4c7060},
        0xc07b44:{0x2c:0x4ce7f0,0x50:0x4c8fa0,0x70:0x4cd010,0x74:0x4c7060},
        0xc21b64:{0x198:0x5d4780},0xc0fc84:{4:0x54ae70},
        0xc0fac4:{0x3c:0x545c50},0xc0fa14:{0x3c:0x545c50},
    }
    slot_count = 0
    for vt, bindings in slots.items():
        for offset, target in bindings.items():
            require(p.u32(vt+offset) == target, f'typed virtual slot {vt:#x}+{offset:#x}')
            slot_count += 1
    expected_types = {0xc0c9dc:'.?AVCMonster@@',0xc07b44:'.?AVCCharacter@@',0xc21b64:'.?AVCBottomMenuFrameField@FUI@@',0xc0fc84:'.?AVCSkillCheckCondition@SubAI@@'}
    for vt, name in expected_types.items():
        col = p.u32(vt-4)
        require(p.string(p.u32(col+12)+8) == name, f'RTTI type {vt:#x}')
    for va, value in ((0xc556d8,9.999999747378752e-05),(0xc557f8,0.009999999776482582),(0xc557e8,100.0)):
        require(struct.unpack('<d', p.at(va,8))[0] == value, f'double constant {va:#x}')
    for va, value in ((0xc5596c,0.4),(0xc0c7f8,2.0),(0xc55a24,0.2),(0xc55cf0,1.2)):
        require(abs(struct.unpack('<f', p.at(va,4))[0]-value) < 1e-6, f'float constant {va:#x}')
    require([p.string(a) for a in (0xc0f09c,0xc0f0a0,0xc0f0a4)] == ['hp','sp','mp'], 'skill cost parser field names')
    targets = list(struct.unpack('<9I', p.at(0x4b1914,36)))
    require(targets == [0x4b0b69,0x4b118b,0x4b0eec,0x4b0e5a,0x4b0d14,0x4b15b7,0x4b1313,0x4b18d9,0x4b1673], 'result jump-table targets')
    require(all(t in instructions for t in targets) and 0x4b1914 not in instructions, 'result data table is not code; targets are instruction boundaries')

    wire = {x['id']:x for x in contracts['wire_contracts']}
    require([(wire[x]['header_bytes'],wire[x]['row_bytes']) for x in ('S2C_0000','S2C_0034','S2C_000E')] == [(2,6),(2,18),(2,13)], 'typed packet contract lengths')
    pair = next(x for x in contracts['native_records'] if x['id']=='visual_pair28')
    require(pair['bytes'] == 28 and [(f['offset'],f['type']) for f in pair['fields']] == [(0,'u16'),(2,'u16'),(4,'f32'),(8,'f32'),(12,'f32'),(16,'f32'),(20,'f32'),(24,'f32')], 'pair record schema')
    require(contracts['classification']['ordinary_world_to_same_run_generation_lua'] == 'NOT_CLOSED_NO_PROVEN_ENDPOINT', 'no unsupported Lua endpoint promotion')
    require(contracts['classification']['official_native_complete'] is False and contracts['classification']['target_executed'] is False, 'no unsupported completion/runtime promotion')
    require(len(contracts['unclosed_endpoints']) == 1 and contracts['unclosed_endpoints'][0]['status']=='NOT_CLOSED', 'precise endpoint blocker retained')
    require(all(r['design_not_original_wire'] is True for r in contracts['server_development_requirements']), 'Server proposal distinguished from original wire')
    asm_text = '; '+native['windows'][0]['id']
    require((HERE/'native-evidence.asm').read_text().startswith(asm_text), 'readable native evidence identity')
    artifact_inputs = []
    for name in ('native-evidence.json','source-manifest.json','contracts.json','read-set.json','native-evidence.asm','verify_evidence.py'):
        data = (HERE/name).read_bytes()
        artifact_inputs.append({'path':name,'bytes':len(data),'sha256':sha(data)})
    return {
        'schema':'MEF-P1-WORLD-LUA-VERIFY-1','status':'PASS',
        'verified_at_utc':datetime.datetime.now(datetime.timezone.utc).isoformat(),
        'baseline_commit':BASELINE,'original_bin':{'sha256':sha(p.b),'bytes':len(p.b),'image_base':hex(p.base)},
        'checks':{'new_code_windows':31,'new_code_bytes':code_bytes,'decoded_instructions':decoded_count,'data_windows':38,'immutable_git_source_pins':75,'reused_native_windows':17,'finite_candidate_censuses':9,'fixed_byte_anchors':len(anchors),'typed_control_flow_anchors':len(asm_anchors),'typed_virtual_slots':slot_count,'typed_rtti_classes':len(expected_types),'result_table_targets':len(targets),'shared_instructions':instruction_status,'typed_contract_and_no_promotion_guards':'PASS'},
        'host_decoder':subprocess.check_output(['objdump','--version'],text=True).splitlines()[0],
        'verification_inputs':artifact_inputs,
        'claims':{'original_source_rechecked':True,'target_client_lua_server_executed':False,'ordinary_world_lua_bridge_proven':False,'same_run_generation_event_endpoint_closed':False,'whole_program_alias_absence_proven':False,'official_native_complete_promoted':False},
        'limits':['PASS is evidence consistency and selected native semantics, not a Lua bridge or runtime completion.','All native negative conclusions are bounded by read-set.json and the reused finite observation catalog.','Census results are literal/E8/E9 candidates; they do not exclude computed pointers, aliases or external modules.','Generation, event sequencing, removal reason and authoritative business logic are Server development requirements.']
    }


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin', required=True, help='read-only original Tartaros.bin')
    ap.add_argument('--repo', required=True, help='repository containing immutable source baseline')
    ap.add_argument('--shared-instructions', help='optional original shared-instructions file to verify')
    args = ap.parse_args()
    try:
        receipt = run(args)
    except Exception as error:
        print(json.dumps({'schema':'MEF-P1-WORLD-LUA-VERIFY-1','status':'FAIL','error':str(error),'target_executed':False},ensure_ascii=False,indent=2))
        return 1
    print(json.dumps(receipt,ensure_ascii=False,indent=2))
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
