#!/usr/bin/env python3
"""Read-only verification of ordinary field/page native evidence; never runs the Client or Lua."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys


def digest(data):
    return hashlib.sha256(data).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--bin', required=True, help='Original 02-Tartaros.bin')
    parser.add_argument('--repo', required=True, help='Existing local repository with pinned Git objects')
    args = parser.parse_args()
    base = Path(__file__).resolve().parent
    pack = json.loads((base/'native-windows.json').read_text())
    tables = json.loads((base/'tables.json').read_text())
    manifest = json.loads((base/'source-manifest.json').read_text())
    original = Path(args.bin).read_bytes()
    errors = []
    checks = {}

    def must(condition, description):
        if not condition:
            errors.append(description)

    expected_sha = '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
    must(digest(original) == expected_sha == pack['binary']['sha256'], 'original SHA256')
    must(len(original) == 12472320 == pack['binary']['size'], 'original size')
    pe = struct.unpack_from('<I', original, 0x3c)[0]
    must(original[:2] == b'MZ' and original[pe:pe+4] == b'PE\0\0', 'PE signatures')
    must(struct.unpack_from('<H', original, pe+4)[0] == 0x14c, 'PE i386')
    opt = pe+24
    must(struct.unpack_from('<H', original, opt)[0] == 0x10b, 'PE32')
    image_base = struct.unpack_from('<I', original, opt+28)[0]
    must(image_base == 0x400000 == int(pack['binary']['image_base'],16), 'image base')
    number = struct.unpack_from('<H', original, pe+6)[0]
    section_start = opt+struct.unpack_from('<H', original, pe+20)[0]
    sections = []
    for index in range(number):
        p = section_start+40*index
        virtual_size, rva, raw_size, raw_offset = struct.unpack_from('<4I', original, p+8)
        sections.append((image_base+rva, raw_size, raw_offset))

    def read(va, length):
        for start, size, offset in sections:
            if start <= va and va+length <= start+size:
                raw = offset+va-start
                return raw, original[raw:raw+length]
        raise ValueError('VA is not wholly raw-backed: '+hex(va))

    def u32(va):
        return struct.unpack('<I', read(va,4)[1])[0]

    records = pack['records']
    must(len({r['id'] for r in records}) == len(records), 'unique record IDs')
    code_count = instruction_count = 0
    insn_map = {}
    for record in records:
        ident = record['id']
        va, end = int(record['va'],16), int(record['end'],16)
        raw, data = read(va,record['length'])
        must(raw == int(record['raw'],16), ident+' VA/raw mapping')
        must(end-va == record['length'], ident+' extent')
        must(data.hex() == record['hex'] and digest(data) == record['sha256'], ident+' original bytes')
        if record['kind'] != 'code':
            continue
        code_count += 1
        position = va
        joined = bytearray()
        for insn in record['instructions']:
            address = int(insn['va'],16)
            payload = bytes.fromhex(insn['hex'])
            must(address == position, ident+' continuity at '+hex(address))
            actual_raw, actual_bytes = read(address,len(payload))
            must(actual_raw == int(insn['raw'],16) and actual_bytes == payload, ident+' instruction bytes/raw')
            must('(bad)' not in insn['asm'] and '.byte' not in insn['asm'], ident+' valid instruction decode')
            position += len(payload)
            joined.extend(payload)
            insn_map[address] = insn
            instruction_count += 1
        must(position == end and bytes(joined) == data, ident+' complete instruction coverage')
        result = subprocess.run(['objdump','-D','-Mintel','--insn-width=16',
            '--start-address='+hex(va),'--stop-address='+hex(end+15),str(Path(args.bin))],
            check=True,capture_output=True,text=True)
        decoded = []
        for line in result.stdout.splitlines():
            match = re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
            if match and va <= int(match[1],16) < end:
                decoded.append((int(match[1],16),bytes.fromhex(match[2]).hex(),match[3].strip()))
        expected = [(int(i['va'],16),i['hex'],i['asm']) for i in record['instructions']]
        must(decoded == expected, ident+' independent objdump reproduction')
    checks.update(native_records=len(records),code_records=code_count,
        instruction_records=instruction_count,native_bytes=sum(r['length'] for r in records))

    for table in tables['vtables']:
        va, col, td = (int(table[k],16) for k in ['vtable','col','type_descriptor'])
        must(u32(va-4) == col, table['label']+' COL pointer')
        must(u32(col+12) == td, table['label']+' RTTI type pointer')
        name = table['type_name'].encode()+b'\0'
        must(read(td+8,len(name))[1] == name, table['label']+' RTTI name')
        for offset, target in table['slots'].items():
            must(u32(va+int(offset,16)) == int(target,16), table['label']+' vtable slot '+offset)
    checks['vtables'] = len(tables['vtables'])

    # Fixed edges independently constrain the interpretation of the saved
    # windows; these are not a whole-program call graph or a register emulator.
    edges = {
        0x423067:0x4adb10, 0x4c48eb:0x4d7a20, 0x4d7a97:0x4d6c90,
        0x4d6cc3:0x4072a0, 0x4b2bd5:0x543700, 0x4cb004:0x4ca890,
        0x4cb015:0x550780, 0x4caaea:0x4cad60, 0x5ad6ce:0x59b1f0,
        0x5afeb3:0x59b1f0, 0x5ac40a:0x598890, 0x5aceca:0x5ac3e0,
        0x5afc5e:0x5ac3e0, 0x5acf24:0x5adc60, 0x598a67:0x59e0b0,
        0x598a73:0x5a9f40, 0x598ad9:0x5a9f40, 0x5ae1fd:0x5ae990,
        0x456b4d:0x456d70, 0x5d4784:0x5ceab0, 0x5d478f:0x5d1bf0,
        0x5d5183:0x5ceab0, 0x5d518f:0x5d3700, 0x5d484f:0x5d4570,
        0x5d485a:0x5a9f40, 0x5d508f:0x5d51a0, 0x5d509a:0x5a9f40,
        0x5d45bd:0x5d46d0, 0x5d51ed:0x5d5300, 0x5d4723:0x5d18a0,
        0x5d5353:0x5d3560, 0x59e0fd:0x5a1e90, 0x5a1eea:0x5facb0,
        0x5facb3:0x5f50c0, 0x5fb122:0x5f7e40, 0x5fb14f:0x5fe740,
        0x5fb164:0x5fe820, 0x5fe78d:0x5fea00, 0x5fe86d:0x5fea90,
        0x5fea5b:0x5fef40, 0x5adcad:0x5ae610, 0x6929b9:0x693fa0,
    }
    for site,target in edges.items():
        data = read(site,5)[1]
        must(data[0] == 0xe8 and (site+5+struct.unpack('<i',data[1:])[0])&0xffffffff == target,
             'direct edge '+hex(site)+' -> '+hex(target))
        must(site in insn_map, 'recorded direct edge boundary '+hex(site))
    for site,target in {0x5ad690:0x5ae1b0,0x5b0160:0x456b00}.items():
        data = read(site,5)[1]
        must(data[0] == 0xe9 and (site+5+struct.unpack('<i',data[1:])[0])&0xffffffff == target,
             'page descriptor thunk '+hex(site))
        must(site in insn_map, 'recorded thunk boundary '+hex(site))
    checks.update(key_direct_edges=len(edges),descriptor_thunks=2)

    exact = {
        0x4adb2e:'c705f079fb0068f8c000', 0x4adb67:'8b5020', 0x4adb79:'8b5024',
        0x543772:'c703fcf7c000', 0x4c48e6:'bee811fb00',
        0x598a61:'8db368010000', 0x598ac6:'8b82a4010000', 0x598ace:'8db364010000',
        0x59b22e:'8b9098010000', 0x59b297:'8b8818010000', 0x59b2a1:'8b9004010000',
        0x59b2ac:'8b90a8010000', 0x5ad725:'8b8b2c020000', 0x5ad737:'8b826c010000',
        0x5fb10d:'8b90ac010000', 0x5fb11e:'40', 0x87af60:'b801000000c3',
        0x603810:'b864000000c3', 0x5f5d10:'c3', 0x692949:'83fb03',
        0x692965:'807e0a00', 0x6929af:'3b353039f900', 0x5ade20:'8b410cc3',
    }
    for va,hexbytes in exact.items():
        must(read(va,len(bytes.fromhex(hexbytes)))[1].hex() == hexbytes, 'key bytes '+hex(va))
        must(va in insn_map, 'key-byte instruction boundary '+hex(va))
    checks['key_exact_windows'] = len(exact)

    env = dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',
        GIT_TERMINAL_PROMPT='0',GIT_NO_REPLACE_OBJECTS='1')
    git = ['git','-c','remote.origin.promisor=false','-C',str(Path(args.repo))]
    sources = manifest['source_pins']
    commits = sorted({s['commit'] for s in sources})
    checked = 0
    for commit in commits:
        group = [s for s in sources if s['commit'] == commit]
        result = subprocess.run(git+['ls-tree',commit,'--']+[s['path'] for s in group],
            env=env,check=True,capture_output=True,text=True)
        tree = {line.split('\t',1)[1]:line.split()[2] for line in result.stdout.splitlines()}
        for source in group:
            must(tree.get(source['path']) == source['git_blob'], 'fixed tree/blob '+source['path'])
            result = subprocess.run(git+['cat-file','blob',source['git_blob']],env=env,capture_output=True)
            if result.returncode:
                errors.append('pinned blob missing locally; no fetch attempted: '+source['path'])
                continue
            data = result.stdout
            blob = hashlib.sha1(b'blob '+str(len(data)).encode()+b'\0'+data).hexdigest()
            must(blob == source['git_blob'], 'Git blob content '+source['path'])
            must(digest(data) == source['sha256'] and len(data) == source['bytes'], 'source SHA256/size '+source['path'])
            checked += 1
    checks.update(source_pins=len(sources),local_source_blobs_checked=checked,git_commits=commits)

    result = dict(status='PASS' if not errors else 'FAIL',
        scope='Bounded static byte/RTTI/edge/source verification only; no Client/Lua execution, runtime behavior acceptance, whole-program runner absence or T01 FULL-PASS claim.',
        checks=checks,errors=errors)
    print(json.dumps(result,ensure_ascii=False,indent=2))
    return 0 if not errors else 1


if __name__ == '__main__':
    try:
        sys.exit(main())
    except Exception as exc:
        print(json.dumps(dict(status='FAIL',errors=[type(exc).__name__+': '+str(exc)]),ensure_ascii=False,indent=2))
        sys.exit(1)
