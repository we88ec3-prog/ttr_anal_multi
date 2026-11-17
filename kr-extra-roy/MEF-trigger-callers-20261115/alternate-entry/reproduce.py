#!/usr/bin/env python3
"""Read-only verifier for the bounded alternate-Lua-trigger evidence package.

No Client, Lua chunk, historical project script, or network operation is run.
The optional repository check inspects pinned Git tree entries only.
"""
from pathlib import Path
import argparse, hashlib, json, re, struct, subprocess

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin',required=True,type=Path)
    ap.add_argument('--repo',type=Path)
    ap.add_argument('--objdump',default='objdump')
    args=ap.parse_args()
    home=Path(__file__).resolve().parent
    expected=json.loads((home/'native-windows.json').read_text())
    xrefs=json.loads((home/'scoped-xrefs.json').read_text())
    manifest=json.loads((home/'source-manifest.json').read_text())
    tables=json.loads((home/'tables.json').read_text())
    b=args.bin.read_bytes()
    assert len(b)==expected['target_size']
    assert hashlib.sha256(b).hexdigest()==expected['target_sha256']
    pe=struct.unpack_from('<I',b,0x3c)[0]
    assert b[pe:pe+4]==b'PE\0\0'
    machine,count=struct.unpack_from('<HH',b,pe+4)
    assert machine==0x14c
    opt=pe+24
    assert struct.unpack_from('<H',b,opt)[0]==0x10b
    base=struct.unpack_from('<I',b,opt+28)[0]
    optsize=struct.unpack_from('<H',b,pe+20)[0]
    secs=[]
    for i in range(count):
        p=opt+optsize+i*40
        vs,rva,rs,raw=struct.unpack_from('<IIII',b,p+8)
        secs.append(dict(name=b[p:p+8].rstrip(b'\0').decode(),va=base+rva,
                         virtual_size=vs,raw=raw,raw_size=rs))
    assert secs==expected['sections']
    def locate(va,size=1):
        for s in secs:
            if s['va']<=va and va+size<=s['va']+s['raw_size']:
                return s,s['raw']+va-s['va']
        raise ValueError(f'no raw bytes for {va:X}+{size:X}')
    def take(va,size):
        _,p=locate(va,size)
        return b[p:p+size]
    def u(va):return struct.unpack('<I',take(va,4))[0]
    def cstr(va):
        _,p=locate(va); return b[p:b.index(0,p)].decode('ascii')
    insn_count=0
    for row in expected['windows']:
        va=int(row['va'],16); end=int(row['end_exclusive'],16)
        sec,raw=locate(va,end-va); data=b[raw:raw+end-va]
        assert row['raw']==f'0x{raw:08X}' and row['section']==sec['name']
        assert len(data)==row['length'] and data.hex()==row['hex'],row['id']
        assert hashlib.sha256(data).hexdigest()==row['sha256'],row['id']
        if row['kind']=='cstring':
            assert data[:-1].decode('ascii')==row['value'] and data[-1]==0
        if row['kind']=='code':
            out=subprocess.check_output([args.objdump,'-D','-Mintel','--insn-width=16',
                 f'--start-address={va}',f'--stop-address={end}',str(args.bin)],text=True)
            records=[]; cursor=va
            for line in out.splitlines():
                m=re.match(r'^\s*([0-9a-f]+):\s*((?:[0-9a-f]{2}\s)+)\s*(.*)$',line)
                if not m:continue
                at=int(m[1],16); bb=bytes.fromhex(m[2]); asm=m[3].strip()
                assert at==cursor and asm and '(bad)' not in asm and not asm.startswith('.byte'),row['id']
                records.append((at,bb))
                cursor+=len(bb)
            assert cursor==end and b''.join(x[1] for x in records)==data,row['id']
            assert [(f'0x{v:08X}',bb.hex()) for v,bb in records]==[(r['va'],r['hex']) for r in row['instructions']]
            insn_count+=len(records)
    target_map={int(r['target'],16):r for r in xrefs['targets']}
    direct={t:[] for t in target_map}
    for sec in secs:
        if sec['name']!='.text':continue
        payload=b[sec['raw']:sec['raw']+sec['raw_size']]
        for p in range(len(payload)-4):
            if payload[p] not in (0xe8,0xe9):continue
            t=(sec['va']+p+5+struct.unpack_from('<i',payload,p+1)[0])&0xffffffff
            if t in target_map and t<0xc00000 and t!=0xf4248:
                direct[t].append(dict(va=f"0x{sec['va']+p:08X}",raw=f"0x{sec['raw']+p:08X}",
                                      opcode=f'{payload[p]:02x}',hex=payload[p:p+5].hex()))
    for t,row in target_map.items():
        hits=[]
        for sec in secs:
            if sec['name'] not in ('.text','.rdata','.data'):continue
            payload=b[sec['raw']:sec['raw']+sec['raw_size']]
            p=payload.find(struct.pack('<I',t))
            while p>=0:
                hits.append(dict(va=f"0x{sec['va']+p:08X}",raw=f"0x{sec['raw']+p:08X}",section=sec['name']))
                p=payload.find(struct.pack('<I',t),p+1)
        assert hits==row['literal_le32'] and direct[t]==row['raw_E8_E9_candidates'],row['target']
    # Explicit semantic anchor values: registration, RTTI, vtables and switch target.
    assert u(0xc0be4c)==0x701820 and u(0xc0b9c4)==0x70a830
    assert u(0xc0c0e4)==0x70b3b0 and u(0xc0c114)==0x701e00
    assert u(0xc0b958)==0x70a510
    assert cstr(u(0xc0be48))=='debug' and cstr(u(0xc0b9c0))=='require'
    assert u(0xc1c1a4+0x108)==0x5a65a0 and u(0xc1c1a4+0x15c)==0x595d20
    assert u(0xc1c1a4+0x194)==0x5a67d0
    assert u(0xc280f4+0x114)==0x5f4640 and u(0xc280f4+0x15c)==0x5f46d0
    assert cstr(u(u(0xc1c1a0)+12)+8)=='.?AVCExpeditionPage@FUI@@'
    assert cstr(u(u(0xc280f0)+12)+8)=='.?AVCExpeditionScene@FUI@@'
    index=take(0x5a69a0+(0xf4248-0xf4245),1)[0]
    assert index==tables['switch_event']['table_index']==3
    assert u(0x5a6988+index*4)==0x5a696e
    imports_rva=struct.unpack_from('<I',b,opt+96+8)[0]
    desc=base+imports_rva; used=[]
    while any(take(desc,20)):
        oft,_,_,name,first=struct.unpack('<IIIII',take(desc,20)); idx=0
        while u(base+(oft or first)+4*idx):
            hintname=u(base+(oft or first)+4*idx)
            if base+first+4*idx==0xbd2114:
                used.append(dict(iat='0x00BD2114',dll=cstr(base+name),name=cstr(base+hintname+2)))
            idx+=1
        desc+=20
    assert used==tables['imports_used']
    pinned=0; local_sources=0
    if args.repo:
        by_commit={}
        for row in manifest['sources']:by_commit.setdefault(row['commit'],[]).append(row)
        for commit,rows in by_commit.items():
            out=subprocess.check_output(['git','ls-tree','-r',commit,'--']+[r['path'] for r in rows],cwd=args.repo,text=True)
            entries={line.split('\t',1)[1]:line.split()[2] for line in out.splitlines()}
            for r in rows:
                assert entries.get(r['path'])==r['git_blob'],r['path']
                pinned+=1
    for row in manifest['sources']:
        if 'local_copy' not in row:continue
        path=home/row['local_copy']
        if not path.exists():continue
        body=path.read_bytes()
        assert len(body)==row['size'] and hashlib.sha256(body).hexdigest()==row['sha256']
        assert hashlib.sha1(f'blob {len(body)}\0'.encode()+body).hexdigest()==row['git_blob']
        local_sources+=1
    print(json.dumps(dict(status='PASS_BOUNDED_REPRODUCTION',binary_sha256=hashlib.sha256(b).hexdigest(),
          native_windows=len(expected['windows']),decoded_instructions=insn_count,xref_targets=len(target_map),
          pinned_git_tree_entries=pinned,optional_local_source_copies=local_sources,
          scope='Fixed native windows, pointer/branch anchors, finite candidate xrefs and pinned provenance only; no full-function or T01 FULL-PASS claim.'),ensure_ascii=False,indent=2))

if __name__=='__main__':main()
