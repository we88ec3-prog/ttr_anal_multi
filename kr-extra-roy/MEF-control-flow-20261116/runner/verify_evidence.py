#!/usr/bin/env python3
"""Read-only static verification; never executes Client, Lua, or supplied scripts."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--bin', required=True, help='Original 02-Tartaros.bin')
    parser.add_argument('--repo', required=True, help='Repository containing the pinned Git objects')
    args = parser.parse_args()
    bundle_dir = Path(__file__).resolve().parent
    pack = json.loads((bundle_dir/'native-windows.json').read_text())
    manifest = json.loads((bundle_dir/'source-manifest.json').read_text())
    contracts = json.loads((bundle_dir/'contracts.json').read_text())
    public_surface = json.loads((bundle_dir/'binding-candidates.json').read_text())
    data = Path(args.bin).read_bytes()
    errors = []
    checks = {}

    def must(value, label):
        if not value:
            errors.append(label)

    def digest(payload):
        return hashlib.sha256(payload).hexdigest()

    must(digest(data) == pack['binary']['sha256'] ==
         '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91', 'BIN SHA256')
    must(len(data) == pack['binary']['size'] == 12472320, 'BIN size')
    pe = struct.unpack_from('<I',data,0x3c)[0]
    must(data[:2] == b'MZ' and data[pe:pe+4] == b'PE\0\0', 'PE signatures')
    must(struct.unpack_from('<H',data,pe+4)[0] == 0x14c, 'i386 machine')
    opt = pe+24
    must(struct.unpack_from('<H',data,opt)[0] == 0x10b, 'PE32 format')
    image_base = struct.unpack_from('<I',data,opt+28)[0]
    must(image_base == int(pack['binary']['image_base'],16) == 0x400000, 'image base')
    section_base = opt+struct.unpack_from('<H',data,pe+20)[0]
    section_count = struct.unpack_from('<H',data,pe+6)[0]
    sections = []
    for index in range(section_count):
        off = section_base+40*index
        name = data[off:off+8].rstrip(b'\0').decode()
        vs,rva,rs,raw = struct.unpack_from('<4I',data,off+8)
        sections.append(dict(name=name,va=hex(image_base+rva),virtual_size=vs,raw_size=rs,raw=hex(raw)))
    must(sections == pack['sections'], 'PE section table')

    def read(va,length):
        for section in sections:
            start,raw = int(section['va'],16),int(section['raw'],16)
            if start <= va and va+length <= start+section['raw_size']:
                off = raw+va-start
                return off,data[off:off+length]
        raise ValueError('VA not wholly raw backed: '+hex(va))

    instruction_map = {}
    record_ids = set()
    instruction_count = 0
    code_count = 0
    for record in pack['records']:
        ident = record['id']
        must(ident not in record_ids,'unique record '+ident)
        record_ids.add(ident)
        va,end = int(record['va'],16),int(record['end'],16)
        raw,payload = read(va,record['length'])
        must(end-va == record['length'],'window extent '+ident)
        must(raw == int(record['raw'],16),'VA/raw mapping '+ident)
        must(payload.hex() == record['hex'] and digest(payload) == record['sha256'],'original bytes '+ident)
        if record['kind'] == 'string':
            must(payload == record['value'].encode()+b'\0','string '+ident)
        if record['kind'] != 'code':
            continue
        code_count += 1
        position = va
        joined = bytearray()
        for ins in record['instructions']:
            at = int(ins['va'],16)
            body = bytes.fromhex(ins['hex'])
            must(at == position,'instruction continuity '+ident+' '+hex(at))
            actual_raw,actual = read(at,len(body))
            must(actual_raw == int(ins['raw'],16) and actual == body,'instruction raw/bytes '+ident+' '+hex(at))
            must('(bad)' not in ins['asm'] and '.byte' not in ins['asm'],'valid decode '+ident+' '+hex(at))
            joined.extend(body)
            position += len(body)
            instruction_count += 1
            instruction_map[at] = ins
        must(position == end and bytes(joined) == payload,'complete decode '+ident)
        result = subprocess.run(['objdump','-D','-Mintel','--insn-width=16',
                                 '--start-address='+hex(va),'--stop-address='+hex(end+15),str(Path(args.bin))],
                                check=True,capture_output=True,text=True)
        decoded = []
        for line in result.stdout.splitlines():
            match = re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
            if match and va <= int(match[1],16) < end:
                decoded.append((int(match[1],16),bytes.fromhex(match[2]).hex(),match[3].strip()))
        expected = [(int(i['va'],16),i['hex'],i['asm']) for i in record['instructions']]
        must(decoded == expected,'independent objdump reproduction '+ident)
    checks.update(native_records=len(record_ids),code_records=code_count,
                  instruction_records=instruction_count,native_bytes=sum(r['length'] for r in pack['records']))

    for table in contracts['vtables']:
        vp,col,td=(int(table[k],16) for k in ['vtable','col','type_descriptor'])
        must(struct.unpack('<I',read(vp-4,4)[1])[0]==col,'vtable COL '+table['id'])
        must(struct.unpack('<I',read(col+12,4)[1])[0]==td,'RTTI type pointer '+table['id'])
        name=table['type_name'].encode()+b'\0'
        must(read(td+8,len(name))[1]==name,'RTTI type name '+table['id'])
        for offset,target in table['slots'].items():
            must(struct.unpack('<I',read(vp+int(offset,16),4)[1])[0]==int(target,16),'virtual slot '+table['id']+' '+offset)
    for switch in contracts['switches']:
        index=int(switch['event'],16)-int(switch['base'],16)
        must(index==switch['index'],'switch index '+switch['id'])
        selector=read(int(switch['map_byte_va'],16),1)[1][0]
        must(selector==switch['selector'],'switch selector '+switch['id'])
        target=struct.unpack('<I',read(int(switch['target_slot_va'],16),4)[1])[0]
        must(target==int(switch['target'],16),'switch target '+switch['id'])
    # These exact branches distinguish texture lifetime and fixed UI events
    # from Lua callable registration. They do not form an all-alias proof.
    fixed_edges={
        0x4ac500:0x4acd30, 0x4ac55a:0x4ace70,
        0x4a9bb8:0x553c90,0x4a9cc8:0x553c90,
        0x491f27:0x422ed0,0x491f2d:0x5537f0,
        0x4a9ee3:0x553740,0x492ef5:0x422ed0,0x492efa:0x5539a0,
        0x59bd90:0x5a4310,
    }
    for site,target in fixed_edges.items():
        payload=read(site,5)[1]
        must(payload[0]==0xe8 and (site+5+struct.unpack_from('<i',payload,1)[0])&0xffffffff==target,'direct edge '+hex(site))
        must(site in instruction_map,'edge instruction boundary '+hex(site))
    exact={
        0x4a9bbd:'c7074c69c000',0x4a9cd6:'c7077c69c000',
        0x4a9cdc:'894f64',0x4a9cdf:'895768',0x4a9d5f:'c7474000000000',
        0x80f010:'8b4114c3',0x87af60:'b801000000c3',0x5f5d10:'c3',
        0x491e75:'83b8ccbf000000',0x491e7c:'0f85c1000000',
    }
    for va,payload in exact.items():
        must(read(va,len(bytes.fromhex(payload)))[1].hex()==payload,'key instructions '+hex(va))
        must(va in instruction_map,'key instruction boundary '+hex(va))
    for relation in contracts['relations']:
        must(all(r in record_ids for r in relation['records']),'relation record references '+relation['id'])
    checked_bindings=0
    for member in public_surface['members']:
        reg=int(member['registrar'],16)
        native=int(member['native'],16)
        slot=int(member['slot'],16)
        closure=int(member['closure'],16)
        must(read(reg+0x18,10)[1]==b'\xc7\x05'+struct.pack('<II',slot,native),'binding native slot '+member['namespace']+'.'+member['name'])
        must(read(reg+0x69,5)[1]==b'\x68'+struct.pack('<I',closure),'binding closure '+member['name'])
        push=read(reg+0x58,5)[1]
        must(push[0]==0x68,'binding name push '+member['name'])
        ptr=struct.unpack_from('<I',push,1)[0]
        must(read(ptr,len(member['name'])+1)[1]==member['name'].encode()+b'\0','binding name '+member['name'])
        checked_bindings+=1
    checks.update(vtables=len(contracts['vtables']),switch_decisions=len(contracts['switches']),
                  key_direct_edges=len(fixed_edges),key_instruction_groups=len(exact),
                  relations=len(contracts['relations']),native_public_binding_tuples=checked_bindings)

    # Object reads only, with lazy fetch disabled. Missing local evidence is a
    # failure; the verifier never changes refs, index, worktree, or resources.
    env=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',
             GIT_TERMINAL_PROMPT='0',GIT_NO_REPLACE_OBJECTS='1')
    git=['git','-c','remote.origin.promisor=false','-C',str(Path(args.repo))]
    sources=manifest['source_pins']
    checked=0
    for commit in sorted({s['commit'] for s in sources}):
        group=[s for s in sources if s['commit']==commit]
        result=subprocess.run(git+['ls-tree',commit,'--']+[s['path'] for s in group],env=env,capture_output=True,text=True,check=True)
        tree={line.split('\t',1)[1]:line.split()[2] for line in result.stdout.splitlines()}
        for source in group:
            must(tree.get(source['path'])==source['git_blob'],'pinned tree/blob '+source['path'])
            result=subprocess.run(git+['cat-file','blob',source['git_blob']],env=env,capture_output=True)
            if result.returncode:
                errors.append('local pinned blob unavailable; no fetch attempted: '+source['path'])
                continue
            payload=result.stdout
            must(hashlib.sha1(b'blob '+str(len(payload)).encode()+b'\0'+payload).hexdigest()==source['git_blob'],
                 'Git blob SHA1 '+source['path'])
            must(len(payload)==source['bytes'] and digest(payload)==source['sha256'],'source bytes/SHA256 '+source['path'])
            if source['commit']==public_surface['source_commit'] and source['path']==public_surface['lb_source']:
                original_table=json.loads(payload)
                expected=[dict(name=r['name'],native=r['target'],registrar=r['registration_va'],slot=r['native_slot'],closure=r['wrapper']) for r in original_table]
                actual=[{key:r[key] for key in ['name','native','registrar','slot','closure']} for r in public_surface['members'] if r['namespace']=='lb']
                must(expected==actual and len(actual)==14,'reused lb14 binding source')
                checks['reused_lb_members']=len(actual)
            if source['commit']==public_surface['source_commit'] and source['path']==public_surface['tutorial_source']:
                original_table=json.loads(payload)['tutorial']
                expected=[{key:r[key] for key in ['name','native','registrar','slot','closure']} for r in original_table]
                actual=[{key:r[key] for key in ['name','native','registrar','slot','closure']} for r in public_surface['members'] if r['namespace']=='Tutorial']
                must(expected==actual and len(actual)==31,'reused Tutorial31 binding source')
                checks['reused_Tutorial_members']=len(actual)
            checked+=1
    checks.update(source_pins=len(sources),source_blobs_checked=checked,
                  pinned_commits=sorted({s['commit'] for s in sources}))
    result=dict(status='PASS' if not errors else 'FAIL',
                scope='Bounded static BIN bytes, decode, display types/lifetimes, fixed UI routing, native binding tuples and source pins only. No Client/Lua execution, ordinary-runner availability, gameplay acceptance or T01 FULL-PASS claim.',
                checks=checks,errors=errors)
    print(json.dumps(result,ensure_ascii=False,indent=2))
    return 0 if not errors else 1


if __name__ == '__main__':
    try:
        sys.exit(main())
    except Exception as exc:
        print(json.dumps(dict(status='FAIL',errors=[type(exc).__name__+': '+str(exc)]),ensure_ascii=False,indent=2))
        sys.exit(1)
