#!/usr/bin/env python3
"""Read-only original/pinned-source verifier for the bounded root-callee study.

PASS verifies bytes, PE mapping, exact target bindings, stated instruction sites,
and requested source pins. It does not prove whole-program absence or T01 FULL-PASS.
"""
import argparse, hashlib, json, os, pathlib, re, struct, subprocess

P=pathlib.Path(__file__).resolve().parent
def digest(b): return hashlib.sha256(b).hexdigest()
def blobhash(b): return hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--bin',required=True,type=pathlib.Path)
    ap.add_argument('--repo',type=pathlib.Path)
    ap.add_argument('--check-disassembly',action='store_true')
    ap.add_argument('--output',type=pathlib.Path)
    a=ap.parse_args()
    ev=json.loads((P/'native-records.json').read_text())
    flow=json.loads((P/'callee-dataflow.json').read_text())
    manifest=json.loads((P/'source-manifest.json').read_text())
    b=a.bin.read_bytes(); orig=ev['original']
    assert len(b)==orig['size'] and digest(b)==orig['sha256'], 'original identity mismatch'
    pe=struct.unpack_from('<I',b,0x3c)[0]
    assert b[pe:pe+4]==b'PE\0\0'
    n=struct.unpack_from('<H',b,pe+6)[0];osz=struct.unpack_from('<H',b,pe+20)[0];opt=pe+24
    ib=struct.unpack_from('<I',b,opt+28)[0]
    assert ib==int(orig['image_base'],16)
    sections=[]
    for i in range(n):
        o=opt+osz+40*i;vs,va,rs,ro=struct.unpack_from('<4I',b,o+8)
        sections.append(dict(name=b[o:o+8].rstrip(b'\0').decode(),va=hex(ib+va),virtual_size=vs,raw_offset=hex(ro),raw_size=rs))
    assert sections==orig['sections'],'section mapping mismatch'
    def raw(v):
        for s in sections:
            if int(s['va'],16)<=v<int(s['va'],16)+s['raw_size']:
                return int(s['raw_offset'],16)+v-int(s['va'],16)
        raise AssertionError('VA has no file bytes: '+hex(v))
    records={r['id']:r for r in ev['records']}
    assert len(records)==len(ev['records'])
    ins={}
    record_bytes=0; code_count=0
    for r in ev['records']:
        va=int(r['va'],16);end=int(r['end_exclusive'],16);ro=raw(va)
        assert ro==int(r['raw'],16) and end-va==r['length'], r['id']
        actual=b[ro:ro+r['length']]
        assert actual.hex()==r['hex'] and digest(actual)==r['sha256'],r['id']
        record_bytes+=r['length']
        if r['kind']=='code-window':
            code_count+=1;cursor=va
            for i in r['instructions']:
                v=int(i['va'],16);bs=bytes.fromhex(i['hex'])
                assert v==cursor and b[raw(v):raw(v)+len(bs)]==bs,r['id']
                cursor+=len(bs)
                if v in ins: assert ins[v]==i,(r['id'],i)
                ins[v]=i
            assert cursor==end,r['id']
            if a.check_disassembly:
                output=subprocess.check_output(['objdump','-D','-Mintel','--insn-width=16',f'--start-address={va}',f'--stop-address={end+15}',str(a.bin)],text=True)
                rows=[]
                for line in output.splitlines():
                    m=re.match(r'\s*([0-9a-f]+):\s+((?:[0-9a-f]{2} )+)\s*(\S.*)',line)
                    if m and int(m[1],16)<end:
                        v=int(m[1],16);bs=bytes.fromhex(m[2]);assert v+len(bs)<=end,'window ends inside instruction'
                        rows.append(dict(va=hex(v),hex=bs.hex(),asm=m[3]))
                assert rows==r['instructions'],r['id']+' disassembly mismatch'
    for d in flow['overwrites']:
        at=int(d['overwrite_va'],16)
        assert at in ins and ins[at]['hex']==d['hex'] and ins[at]['asm']==d['instruction'],d
    for v in flow['virtual_bindings']:
        slot=int(v['slot'],16)
        assert slot==int(v['vtable'],16)+int(v['offset'],16)
        assert struct.unpack_from('<I',b,raw(slot))[0]==int(v['target'],16),v
        assert v['evidence'] in records
    for w in flow['selected_receiver_writers']:
        at=int(w['instruction_va'],16)
        assert at in ins and ins[at]['hex']==w['hex'].replace(' ',''),w
    for imp in flow['imports']:
        slot=int(imp['iat'],16);nameva=int(imp['name_va'],16);desc=int(imp['descriptor_va'],16)
        assert struct.unpack_from('<I',b,raw(slot))[0]+ib+2==nameva,imp
        assert b[raw(nameva):raw(nameva)+len(imp['name'])+1]==imp['name'].encode()+b'\0'
        dllva=struct.unpack_from('<I',b,raw(desc)+12)[0]+ib
        assert b[raw(dllva):raw(dllva)+len(imp['dll'])+1]==imp['dll'].encode()+b'\0'
    source_pins=0;source_contents=0
    if a.repo:
        by_commit={}
        for s in manifest['source_records']:by_commit.setdefault(s['commit'],[]).append(s)
        env=dict(os.environ,GIT_NO_LAZY_FETCH='1')
        for commit,sources in by_commit.items():
            output=subprocess.check_output(['git','ls-tree','-r',commit,'--',*[s['path'] for s in sources]],cwd=a.repo,text=True,env=env)
            pins={line.split('\t',1)[1]:line.split()[2] for line in output.splitlines()}
            for s in sources:
                assert pins.get(s['path'])==s['git_blob'],s['path']+' fixed tree pin mismatch'
                source_pins+=1
                if s.get('local_content_verified'):
                    data=(a.repo/s['path']).read_bytes()
                    assert len(data)==s['bytes'] and digest(data)==s['sha256'] and blobhash(data)==s['git_blob'],s['path']+' local content mismatch'
                    source_contents+=1
    result=dict(status='PASS',original_sha256=orig['sha256'],records=len(records),code_windows=code_count,record_bytes=record_bytes,overwrite_sites=len(flow['overwrites']),virtual_bindings=len(flow['virtual_bindings']),receiver_writer_candidates=len(flow['selected_receiver_writers']),named_imports=len(flow['imports']),disassembly_redecoded=a.check_disassembly,source_tree_pins_checked=source_pins,local_source_contents_checked=source_contents,limits=['No Client/Lua execution. Original opened read-only.','Source navigation tree pins are not claims of reading the corresponding pseudocode contents.','Byte/target checks do not independently certify semantic negative closure, arbitrary runtime callbacks, external DLL internals, T01 FULL-PASS, or whole-program absence of MEF support.'])
    if a.output:a.output.write_text(json.dumps(result,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(result,ensure_ascii=False,indent=2))

if __name__=='__main__':main()
