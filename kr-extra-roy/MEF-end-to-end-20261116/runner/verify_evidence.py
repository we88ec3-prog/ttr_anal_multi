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
    xrefs = json.loads((bundle_dir/'scoped-xrefs.json').read_text())
    manifest = json.loads((bundle_dir/'source-manifest.json').read_text())
    contracts = json.loads((bundle_dir/'contracts.json').read_text())
    public_surface = json.loads((bundle_dir/'public-surface-review.json').read_text())
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

    # Recompute byte-pattern candidate sets. The result is bounded to these
    # encodings and sections; it is not a whole-program alias/call-graph proof.
    def candidates(target):
        direct=[]
        literals=[]
        for section in sections:
            if section['name'] not in ['.text','.rdata','.data']:
                continue
            start,raw = int(section['va'],16),int(section['raw'],16)
            body=data[raw:raw+section['raw_size']]
            if section['name'] == '.text':
                for off in range(len(body)-4):
                    if body[off] in [0xe8,0xe9] and (start+off+5+struct.unpack_from('<i',body,off+1)[0])&0xffffffff == target:
                        direct.append(dict(va=hex(start+off),raw=hex(raw+off),kind='E8' if body[off]==0xe8 else 'E9',hex=body[off:off+5].hex()))
            needle=struct.pack('<I',target)
            off=body.find(needle)
            while off >= 0:
                literals.append(dict(va=hex(start+off),raw=hex(raw+off),section=section['name'],hex=needle.hex()))
                off=body.find(needle,off+1)
        return dict(target=hex(target),direct=direct,literal=literals)

    for target in xrefs['targets']:
        must(candidates(int(target['target'],16)) == target,'census '+target['target'])
        for candidate in target['direct']:
            must(int(candidate['va'],16) in instruction_map,'candidate confirmed instruction boundary '+candidate['va'])
    must(candidates(0xfb73ec)['literal'] == xrefs['q_pause_literal']['literal'],'Q pause literal census')
    must([r['va'] for r in xrefs['q_pause_literal']['literal']] == ['0x560241'],'single constructor pause operand')
    checks.update(censused_hook_targets=len(xrefs['targets']),q_pause_literal_candidates=len(xrefs['q_pause_literal']['literal']))

    fixed_edges = {
        0x6fc5ae:0x6fb660,0x6fb68e:0x6fdde0,0x6fb6e7:0x6fdde0,
        0x6fe2d1:0x6fdde0,0x6fe34c:0x6fdde0,0x6fe3c3:0x6fdde0,
        0x6fe4d3:0x6fe3a0,0x7013ec:0x6fe550,0x701639:0x701400,
        0x701647:0x701450,0x701685:0x6f57f0,0x6f7420:0x6f7200,
        0x4ac070:0x4acb70,0x4a23c0:0x4a23e0,0x4a14b0:0x6d1be0,
        0x4acb82:0x6f50f0,0x4a23f2:0x6f50f0,0x5615d8:0x6f4dd0,
    }
    for site,target in fixed_edges.items():
        body=read(site,5)[1]
        must(body[0]==0xe8 and (site+5+struct.unpack_from('<i',body,1)[0])&0xffffffff==target,
             'fixed direct edge '+hex(site)+' -> '+hex(target))
        must(site in instruction_map,'edge boundary '+hex(site))
    exact_bytes = {
        0x6fc59e:'ff4f40',0x6fb684:'ba03000000',0x6fb68b:'894640',
        0x6fb6e0:'ba02000000',0x6fe3bb:'ba01000000',0x6fe42f:'c7459804000000',
        0x6fde83:'c6463900',0x6fde87:'ff5594',0x6fde92:'c6463901',
        0x6fe474:'c6463900',0x6fe478:'ff5590',0x6fe483:'c6463901',
        0x7016a8:'895944',0x7016ab:'884138',0x7016ae:'89513c',0x7016b1:'895140',
        0x6f7437:'8a4738',0x6f743a:'884638',0x6f743d:'8b4f3c',0x6f7448:'894640',
        0x6f7443:'8b5744',0x6f744c:'895644',0x701714:'3d20137000',
        0x4aa918:'c7051818fe00c0944a00',0x4a1de8:'c705b017fe0040144a00',
        0x4acb7f:'83c8ff',0x4a23ef:'83c8ff',0x4acbc1:'db5dfc',0x4a2431:'db5dfc',
        0x4ac078:'b801000000',0x4a23c8:'b801000000',
        0x4a9515:'83253088fb00fd',0x4a9550:'830d3088fb0002',
        0x4a149a:'83f801',0x4a14a5:'053488fb00',0x4a14ab:'68348dfb00',
        0x6d1d4a:'83f928',0x56023f:'891dec73fb00',0x5615c4:'897058',0x5615c7:'837f2c00',
    }
    for va,value in exact_bytes.items():
        must(read(va,len(bytes.fromhex(value)))[1].hex()==value,'key instruction '+hex(va))
        must(va in instruction_map,'key instruction boundary '+hex(va))
    must(struct.unpack('<II',read(0xc0be90,8)[1]) == (0xc42e68,0x701510),'sethook registration row')
    event_names=['call','return','line','count','tail return']
    for i,name in enumerate(event_names):
        ptr=struct.unpack('<I',read(0xc0be08+4*i,4)[1])[0]
        must(read(ptr,len(name)+1)[1]==name.encode()+b'\0','hook event enum '+str(i))
    must([e['name'] for e in contracts['hook_events']]==event_names,'contract enum agrees with BIN')
    for relation in contracts['relations']:
        must(all(r in record_ids for r in relation['records']),'relation record references '+relation['from'])
    checks.update(key_direct_edges=len(fixed_edges),key_instructions=len(exact_bytes),hook_event_names=5,relations=len(contracts['relations']))

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
            if source['commit']==public_surface['source']['commit'] and source['path']==public_surface['source']['path']:
                must(digest(payload)==public_surface['source']['sha256'],'public surface source digest')
                original_table=json.loads(payload)
                expected=[dict(name=r['strings'][0]['value'],native=r['stores'][0]['value'],registrar=r['registrar'],closure=r['callbacks'][0]['callback'])
                          for r in original_table['q_regular_bindings']]
                actual=[{key:r[key] for key in ['name','native','registrar','closure']} for r in public_surface['q_public_bindings']]
                must(expected==actual and len(actual)==63,'complete Q public surface copied from fixed source')
                must(public_surface['q_rebind']==original_table['q_rebind'],'Q rebind source')
                checks['reused_q_public_bindings']=len(actual)
            checked+=1
    checks.update(source_pins=len(sources),source_blobs_checked=checked,
                  pinned_commits=sorted({s['commit'] for s in sources}))
    result=dict(status='PASS' if not errors else 'FAIL',
                scope='Bounded static BIN bytes, decode, caller encodings, field/table edges and fixed source pins only. No Client/Lua execution, ordinary-runner availability, gameplay acceptance or T01 FULL-PASS claim.',
                checks=checks,errors=errors)
    print(json.dumps(result,ensure_ascii=False,indent=2))
    return 0 if not errors else 1


if __name__ == '__main__':
    try:
        sys.exit(main())
    except Exception as exc:
        print(json.dumps(dict(status='FAIL',errors=[type(exc).__name__+': '+str(exc)]),ensure_ascii=False,indent=2))
        sys.exit(1)
