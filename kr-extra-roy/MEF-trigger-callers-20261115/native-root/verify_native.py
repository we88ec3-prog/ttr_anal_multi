#!/usr/bin/env python3
"""Read-only byte/provenance recheck. Does not execute Client or Lua."""
from pathlib import Path
import argparse
import collections
import hashlib
import json
import struct
import subprocess


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('bin', type=Path, help='Original KR 02-Tartaros.bin')
    ap.add_argument('--repo', type=Path, help='Optionally check pinned Git tree entries without fetching blobs')
    args = ap.parse_args()
    home = Path(__file__).resolve().parent
    native = json.loads((home/'native-records.json').read_text())
    census = json.loads((home/'root-alias-census.json').read_text())
    manifest = json.loads((home/'source-manifest.json').read_text())
    original = args.bin.read_bytes()
    digest = hashlib.sha256(original).hexdigest()
    assert digest == native['target_sha256'] == manifest['original']['sha256']
    assert len(original) == native['target_length'] == manifest['original']['bytes']
    pe = struct.unpack_from('<I', original, 0x3c)[0]
    count = struct.unpack_from('<H', original, pe+6)[0]
    optional_size = struct.unpack_from('<H', original, pe+20)[0]
    base = struct.unpack_from('<I', original, pe+52)[0]
    sections=[]
    for i in range(count):
        p=pe+24+optional_size+i*40
        name=original[p:p+8].split(b'\0')[0].decode('ascii')
        vsize,rva,rsize,raw=struct.unpack_from('<4I',original,p+8)
        sections.append(dict(name=name,va=base+rva,virtual_size=vsize,raw=raw,raw_size=rsize))
    assert native['sections']==sections

    def get(va,size):
        for s in sections:
            if s['va'] <= va and va+size <= s['va']+s['raw_size']:
                raw=s['raw']+va-s['va']
                return s,raw,original[raw:raw+size]
        raise ValueError('Virtual-only or out of bounds: '+hex(va))

    ids={r['id']:r for r in native['records']}
    assert len(ids)==len(native['records'])
    for r in native['records']:
        va,end=int(r['va'],16),int(r['end_va_exclusive'],16)
        assert end-va==r['length']
        sec,raw,b=get(va,r['length'])
        assert raw==int(r['raw_offset'],16) and sec['name']==r['section']
        assert b.hex()==r['hex'] and hashlib.sha256(b).hexdigest()==r['sha256']
        if 'ascii' in r:
            assert b==r['ascii'].encode('ascii')+b'\0'
        if 'instructions' in r:
            cursor=va
            for ins in r['instructions']:
                assert int(ins['va'],16)==cursor
                h=bytes.fromhex(ins['hex'])
                assert b[cursor-va:cursor-va+len(h)]==h
                cursor+=len(h)
            assert cursor==end

    # The bounded exact-value census is reproducible without any disassembler.
    found=[]
    needle=bytes.fromhex(census['search_pattern'])
    for s in sections:
        if s['name'] not in ('.text','.rdata','.data'):
            continue
        p=s['raw'];end=p+s['raw_size']
        while True:
            p=original.find(needle,p,end)
            if p<0:break
            found.append((s['name'],s['va']+p-s['raw'],p))
            p+=1
    expected=[(r['section'],int(r['operand_va'],16),int(r['raw'],16)) for r in census['records']]
    assert found==expected
    assert len(found)==census['total_candidates']==155
    assert {x[0] for x in found}=={'.text'}
    assert len({x['function_start'] for x in census['records']})==census['distinct_functions']==120
    assert dict(collections.Counter(r['first_transfer'] for r in census['records']))==census['first_transfer_counts']
    for r in census['records']:
        w=ids[r['evidence_id']]
        off=int(r['operand_va'],16)-int(w['va'],16)
        assert bytes.fromhex(w['hex'])[off:off+4]==needle

    # Selected actual E8 edges and concrete virtual-target binding.
    calls={0x552291:0x4f6f70,0x5522f7:0x550580,0x55067d:0x80af10,
           0x80af98:0x80e230,0x80e530:0x80ab00,0x4f6858:0x4f9a60,
           0x4f6869:0x4f90b0,0x4f666a:0x72ee30,0x4f6694:0x72f110,
           0x491fce:0x4f6b80,0x49679b:0x4f6b20,0x4d6081:0x4f6d20,
           0x53cc38:0x4f6b20,0x4d60b5:0x4a4240}
    for site,target in calls.items():
        b=get(site,5)[2]
        assert b[0]==0xe8 and (site+5+struct.unpack_from('<i',b,1)[0])&0xffffffff==target
    assert struct.unpack('<I',get(0xc51b5c,4)[2])[0]==0x80e4c0
    for va,h in {0x80e260:'c706501bc500',0x491fe4:'8bf3',0x492005:'5e',
                 0x4967bc:'8d7a08',0x4d6587:'5f',0x53cc5e:'8b7db8',
                 0x804a75:'8b3558a8fb00',0x804fe0:'8b733c'}.items():
        assert get(va,len(h)//2)[2].hex()==h

    checked=0
    if args.repo:
        by_commit={}
        for r in manifest['source_records']:
            by_commit.setdefault(r['commit'],[]).append(r)
        for commit,rows in by_commit.items():
            listing=subprocess.check_output(['git','ls-tree','-r',commit,'--']+
                [r['path'] for r in rows],cwd=args.repo,text=True)
            entries={line.split('\t',1)[1]:line.split()[2] for line in listing.splitlines()}
            for r in rows:
                assert entries.get(r['path'])==r['git_blob'],r['path']
                checked+=1
    print(json.dumps(dict(result='BYTE_AND_SCOPE_CHECK_PASS',target_sha256=digest,
        native_windows=len(native['records']),exact_root_candidates=len(found),
        pinned_git_tree_entries_checked=checked,
        limitation='Bytes/census/selected edges only; not semantic FULL-PASS, arbitrary alias closure, or runtime MEF proof'),ensure_ascii=False))


if __name__=='__main__':
    main()
