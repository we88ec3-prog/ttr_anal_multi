#!/usr/bin/env python3
"""Read-only verifier for the bounded native runner evidence; never executes Lua."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys


def sha256(b):
    return hashlib.sha256(b).hexdigest()


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin', required=True)
    ap.add_argument('--repo', required=True)
    ap.add_argument('--event-stp', required=True)
    args = ap.parse_args()
    base = Path(__file__).resolve().parent
    errors = []
    checks = {}

    def must(cond, label):
        if not cond:
            errors.append(label)

    pack = json.loads((base / 'native-windows.json').read_text())
    tables = json.loads((base / 'tables.json').read_text())
    xrefs = json.loads((base / 'scoped-xrefs.json').read_text())
    manifest = json.loads((base / 'source-manifest.json').read_text())
    b = Path(args.bin).read_bytes()
    must(len(b) == pack['binary']['size'], 'BIN size')
    must(sha256(b) == pack['binary']['sha256'], 'BIN SHA256')
    pe = struct.unpack_from('<I', b, 0x3C)[0]
    must(b[:2] == b'MZ' and b[pe:pe+4] == b'PE\0\0', 'PE signature')
    must(struct.unpack_from('<H', b, pe+4)[0] == 0x14C, 'PE machine i386')
    opt = pe+24
    must(struct.unpack_from('<H', b, opt)[0] == 0x10B, 'PE32 optional header')
    imagebase = struct.unpack_from('<I', b, opt+28)[0]
    must(imagebase == int(pack['binary']['image_base'], 16), 'image base')
    sec_count = struct.unpack_from('<H', b, pe+6)[0]
    sec_off = opt+struct.unpack_from('<H', b, pe+20)[0]
    sections = []
    for i in range(sec_count):
        p = sec_off+40*i
        name = b[p:p+8].rstrip(b'\0').decode()
        vs, rva, rs, raw = struct.unpack_from('<4I', b, p+8)
        sections.append((name, imagebase+rva, vs, rs, raw))

    def read(va, length):
        for name, start, vs, rs, raw in sections:
            if start <= va and va+length <= start+rs:
                p = raw+va-start
                return p, b[p:p+length]
        raise ValueError('not raw-backed: '+hex(va))

    def u32(va):
        return struct.unpack('<I', read(va, 4)[1])[0]

    records = pack['records']
    byid = {r['id']: r for r in records}
    must(len(byid) == len(records), 'unique evidence IDs')
    insn_map = {}
    code_count = 0
    instruction_count = 0
    for r in records:
        va, end, length = int(r['va'],16), int(r['end'],16), r['length']
        raw, payload = read(va, length)
        must(raw == int(r['raw'],16), r['id']+' VA/raw')
        must(end-va == length, r['id']+' extent')
        must(payload.hex() == r['hex'], r['id']+' bytes')
        must(sha256(payload) == r['sha256'], r['id']+' SHA256')
        if r['kind'] != 'code':
            continue
        code_count += 1
        position = va
        joined = bytearray()
        for ins in r['instructions']:
            addr = int(ins['va'],16)
            data = bytes.fromhex(ins['hex'])
            must(addr == position, r['id']+' instruction continuity at '+hex(addr))
            must(read(addr,len(data))[0] == int(ins['raw'],16), r['id']+' instruction raw')
            must(read(addr,len(data))[1] == data, r['id']+' instruction bytes')
            must('(bad)' not in ins['asm'] and '.byte' not in ins['asm'], r['id']+' invalid decode')
            position += len(data)
            joined.extend(data)
            insn_map[addr] = ins
            instruction_count += 1
        must(position == end and bytes(joined) == payload, r['id']+' whole instruction coverage')
        result = subprocess.run(['objdump','-D','-Mintel','--insn-width=16',
            '--start-address='+hex(va), '--stop-address='+hex(end), str(Path(args.bin))],
            check=True,capture_output=True,text=True)
        decoded = []
        for line in result.stdout.splitlines():
            m = re.match(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2}\s+)+)\s*(.*)',line)
            if m and va <= int(m[1],16) < end:
                decoded.append((int(m[1],16),bytes.fromhex(m[2]).hex(),m[3].strip()))
        expected = [(int(i['va'],16),i['hex'],i['asm']) for i in r['instructions']]
        must(decoded == expected, r['id']+' objdump reproduction')
    checks.update(native_records=len(records), code_records=code_count,
                  instruction_records=instruction_count, native_bytes=sum(r['length'] for r in records))

    for vt in tables['vtables']:
        va = int(vt['vtable'],16)
        col = int(vt['col'],16)
        td = int(vt['type_descriptor'],16)
        must(u32(va-4) == col, vt['label']+' COL')
        must(u32(col+12) == td, vt['label']+' type descriptor')
        typename = vt['type_name'].encode()+b'\0'
        must(read(td+8,len(typename))[1] == typename, vt['label']+' RTTI name')
        for off, target in vt['slots'].items():
            must(u32(va+int(off,16)) == int(target,16), vt['label']+' slot '+off)
    checks['vtables'] = len(tables['vtables'])

    sw = tables['review_event_switch']
    idx = int(sw['event'],16)-int(sw['base'],16)
    must(idx == int(sw['index'],16), 'review switch index')
    sel = read(int(sw['byte_address'],16),1)[1][0]
    must(sel == int(sw['selector'],16), 'review switch selector')
    must(u32(int(sw['dword_address'],16)) == int(sw['target'],16), 'review switch target')

    # Assert important semantic edges as exact native instructions rather than
    # trusting source labels. No register emulator or whole-program claim.
    edges = {
        0x47CA45:0x4A8B90,0x4C19AE:0x4A8B90,0x4C4E8A:0x4A8B90,
        0x5B8AB8:0x47C980,0x5B7983:0x5BAF70,0x63A15E:0x4072A0,
        0x47B601:0x47B850,0x47BACE:0x4A89C0,0x4C1FFC:0x4A89C0,
        0x4C4D3F:0x4A8A60,0x47CA7E:0x47B6B0,0x4C1A2F:0x4C2050,
        0x5A64FF:0x4C1E10,0x5B55A5:0x5A9F40,0x5C18FD:0x47C370,
        0x6359F6:0x6370C0,0x5B1C37:0x5C2C60,
    }
    for site,target in edges.items():
        data=read(site,5)[1]
        must(data[0]==0xE8 and (site+5+struct.unpack('<i',data[1:])[0])&0xffffffff==target,
             'direct edge '+hex(site)+'→'+hex(target))
        must(site in insn_map, 'edge recorded at instruction boundary '+hex(site))
    checks['key_direct_edges'] = len(edges)
    exact = {
        0x63882E:'c7815801000030a16300',
        0x63A157:'c7401037430f00',
        0x7508A4:'8b9084010000',
        0x7508AA:'ffd2',
        0x8DC2F0:'33c0c3',
        0x5ADE20:'8b410cc3',
        0x7B3250:'8b4104c3',
    }
    for va,h in exact.items():
        must(read(va,len(bytes.fromhex(h)))[1].hex()==h,'key bytes '+hex(va))
    checks['key_exact_windows'] = len(exact)

    targets = {int(t,16) for t in xrefs['targets']}
    actual = {hex(t):{'e8':[],'e9':[],'literal':[]} for t in targets}
    for name,va,vs,rs,raw in sections:
        if name not in ['.text','.rdata','.data']:
            continue
        content=b[raw:raw+rs]
        if name=='.text':
            for i in range(len(content)-4):
                if content[i] not in [0xE8,0xE9]:continue
                target=(va+i+5+struct.unpack_from('<i',content,i+1)[0])&0xffffffff
                if target in targets:
                    actual[hex(target)]['e8' if content[i]==0xE8 else 'e9'].append(hex(va+i))
        for target in targets:
            start=0
            while True:
                found=content.find(struct.pack('<I',target),start)
                if found<0:break
                start=found+1
                actual[hex(target)]['literal'].append(dict(va=hex(va+found),raw=hex(raw+found),section=name))
    for target,r in xrefs['targets'].items():
        for form in ['e8','e9']:
            must(actual[target][form] == [x['callsite'] for x in r[form]], 'bounded xrefs '+target+' '+form)
        must(actual[target]['literal']==r['literal'],'bounded literal xrefs '+target)
    checks['bounded_xref_targets']=len(targets)
    checks['known_T_direct_callers']=len(actual['0x4a8b90']['e8'])
    checks['Lobby_direct_callers']=len(actual['0x5b87b0']['e8'])
    checks['registered_review_page_codes']=[x['code'] for x in tables['registered_review_pages']]

    stp=Path(args.event_stp).read_bytes()
    stpid=next(x for x in manifest['originals'] if x['filename']=='06-Event.stp')
    must(len(stp)==stpid['size'] and sha256(stp)==stpid['sha256'],'Event.stp identity')
    lua=tables['tutorial_part2_tail_reuse']
    payload=stp[lua['stored_offset']:lua['stored_offset']+lua['length']]
    decoded=bytes(x^0xFF for x in payload)
    must(payload.hex()==lua['stored_hex'] and sha256(payload)==lua['stored_sha256'],'selected Lua stored bytes')
    must(decoded.hex()==lua['decoded_hex'] and sha256(decoded)==lua['decoded_sha256'],'selected Lua XOR bytes')
    for i,ins in enumerate(lua['instructions']):
        word=struct.unpack_from('<I',decoded,i*4)[0]
        must(word==int(ins['word'],16),'selected Lua instruction word '+str(ins['pc']))
        must(ins['pc']==lua['pc_start']+i,'selected Lua PC coverage')
    checks['reused_Lua_tail_words']=len(lua['instructions'])

    env=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',GIT_TERMINAL_PROMPT='0')
    git=['git','-c','remote.origin.promisor=false','-C',str(Path(args.repo))]
    sources=manifest['git_sources']
    commits=sorted({s['commit'] for s in sources})
    checked=0
    for commit in commits:
        group=[s for s in sources if s['commit']==commit]
        cmd=git+['ls-tree',commit,'--']+[s['path'] for s in group]
        out=subprocess.run(cmd,env=env,check=True,capture_output=True,text=True).stdout
        tree={line.split('\t',1)[1]:line.split()[2] for line in out.splitlines()}
        for s in group:
            must(tree.get(s['path'])==s['blob'],'Git pin '+commit+':'+s['path'])
            # Partial-clone objects must already exist locally. Explicitly do
            # not ask Git for permission to download a missing object.
            cp=subprocess.run(git+['cat-file','blob',s['blob']],env=env,capture_output=True)
            if cp.returncode:
                errors.append('local pinned blob unavailable (no fetch): '+s['path'])
                continue
            value=cp.stdout
            blob=hashlib.sha1(b'blob '+str(len(value)).encode()+b'\0'+value).hexdigest()
            must(blob==s['blob'],'Git blob content '+s['path'])
            if s.get('sha256'):
                must(sha256(value)==s['sha256'],'Git source SHA256 '+s['path'])
            if s.get('size') is not None:
                must(len(value)==s['size'],'Git source size '+s['path'])
            checked+=1
    checks.update(git_source_pins=len(sources),local_source_blobs_checked=checked,git_commits=commits)
    result=dict(status='PASS' if not errors else 'FAIL',
        scope='Bounded static evidence integrity and concrete native edges only; no Client/Lua execution, no T01 FULL-PASS or gameplay acceptance claim.',
        checks=checks,errors=errors)
    print(json.dumps(result,ensure_ascii=False,indent=2))
    return 0 if not errors else 1


if __name__ == '__main__':
    try:
        sys.exit(main())
    except Exception as exc:
        print(json.dumps(dict(status='FAIL',scope='bounded static verification',errors=[type(exc).__name__+': '+str(exc)]),ensure_ascii=False,indent=2))
        sys.exit(1)
