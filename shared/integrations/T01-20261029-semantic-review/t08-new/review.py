"""Reproducible static evidence capture; never executes target code.

Semantic verdicts are maintained by the reviewer in results.json, separately
from these mechanical source/decoder checks.
"""
import pathlib,sys,json,re,hashlib,struct,collections,subprocess
HERE=pathlib.Path(__file__).resolve().parent
R=HERE.parents[3]
from native_reader import B,H,sections,data,offset,cfg,md,save
QUEUE=json.loads((HERE/'assigned-sources.json').read_text(encoding='utf-8'))
ROWS=[x for x in QUEUE['rows'] if x['task']=='T08' and x['number']>=170]
def prose(t):
    return re.sub(r'^```(?:asm|text|bash|sh).*?^```\s*$', '[assembly retained in source/evidence]', t,flags=re.M|re.S)
def blob(b):return hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()
def source(num):
    row=next(x for x in ROWS if x['number']==num);p=R/row['source'];b=p.read_bytes()
    assert blob(b)==row['git_blob_sha'];assert hashlib.sha256(b).hexdigest()==row['sha256']
    return row,b.decode('utf-8-sig')
def dump(num):
    row,t=source(num);print(prose(t))
def evidence():
    # Decode quoted assembly statements at the quoted VA. This is a source
    # consistency screen, not a substitute for function-entry CFG review.
    allrows=[]
    for row in ROWS:
        _,t=source(row['number']);checks=[]
        for line in t.splitlines():
            m=re.match(r'\s*([0-9a-fA-F]{6,8}):\s+((?:[0-9a-fA-F]{2}\s+)+)([^\s].*)?',line)
            if not m:continue
            a=int(m[1],16);bs=bytes.fromhex(m[2]);actual=data(a,len(bs));ins=next(md.disasm(data(a,15),a,count=1),None)
            checks.append(dict(va=hex(a),quoted_bytes=bs.hex(' '),actual_bytes=actual.hex(' '),bytes_equal=bs==actual,quoted_assembly=m[3] or '',decoded=ins.mnemonic+' '+ins.op_str if ins else None,decoded_size=ins.size if ins else None,quote_complete_instruction=bool(ins and len(bs)==ins.size)))
        allrows.append(dict(source=row['source'],number=row['number'],sha256=row['sha256'],git_blob_sha=row['git_blob_sha'],assembly_checks=checks))
    save(HERE/'source-assembly-audit.json',dict(target_sha256=H,sections=sections,reports=allrows,limitation='per-address decoder checks do not prove instruction boundaries or semantic correctness'))
    print('reports',len(allrows),'statements',sum(len(x['assembly_checks']) for x in allrows),'byte mismatches',sum(not c['bytes_equal'] for x in allrows for c in x['assembly_checks']))
def capture(entries):
    for a in entries:
        d=cfg(a);save(HERE/'native-cfg'/f'{a:08x}.json',d)
        print(hex(a),len(d['instructions']),'instructions',len(d['overlaps']),'overlaps')
    save(HERE/'target.json',dict(sha256=H,bytes=len(B),sections=sections,analysis='offline recursive reachable x86 decoding; calls/EH/indirect targets reviewed separately',decoder='Capstone 5.0.6 from installed Ghidra wheel'))
def support():
    raw=next(s for s in sections if s['name']=='.text');calls=collections.defaultdict(list)
    bs=B[raw['raw']:raw['raw']+raw['virtual_size']]
    for k in range(len(bs)-4):
        if bs[k]==0xe8:
            site=raw['va']+k;dest=site+5+struct.unpack_from('<i',bs,k+1)[0]
            calls[dest].append(dict(site=hex(site),bytes=bs[k:k+5].hex(' ')))
    targets=set()
    for row in ROWS:
        _,t=source(row['number']);targets.update(int(s,16) for s in re.findall(r'0x([0-9a-fA-F]{6,8})',t))
    save(HERE/'direct-e8-candidates.json',dict(target_sha256=H,section=raw,limitation='raw-byte candidates only; no caller instruction boundary or runtime guarantee',targets=[dict(target=hex(t),count=len(calls[t]),sites=calls[t]) for t in sorted(targets)]))
    pe=struct.unpack_from('<I',B,0x3c)[0];opt=pe+24;irva=struct.unpack_from('<I',B,opt+104)[0];p=offset(0x400000+irva);imports=[]
    def cstr(a):o=offset(a);return B[o:B.index(0,o)].decode('ascii')
    while any(B[p:p+20]):
        original,_,_,name,first=struct.unpack_from('<IIIII',B,p);p+=20;dll=cstr(0x400000+name);q=offset(0x400000+(original or first));k=0
        while True:
            v=struct.unpack_from('<I',B,q+k*4)[0]
            if not v:break
            imports.append(dict(iat=hex(0x400000+first+k*4),dll=dll,name='#'+str(v&0xffff) if v&0x80000000 else cstr(0x400000+v+2)));k+=1
    save(HERE/'imports.json',dict(target_sha256=H,imports=imports))
    # Bind each function entry to saved Ghidra acquisition metadata without
    # inheriting the decompiler's semantic verdict or CFG omissions.
    corpus=pathlib.Path('E:/Tartaros/workspace/anal-multi/kr-bulk-roy')/H
    idx={int(r['address'],16):r for r in map(json.loads,(corpus/'index.jsonl').open(encoding='utf-8')) if r.get('status')=='ok'}
    out=[]
    for p in sorted((HERE/'native-cfg').glob('*.json')):
        a=int(p.stem,16);r=idx.get(a);out.append(dict(entry=hex(a),independent_cfg_file=p.relative_to(HERE).as_posix(),ghidra_index_record=r,entry_status='registered-ghidra-entry' if r else 'not-in-bulk-index; explicit-call-target-or-manual-boundary-required'))
    save(HERE/'entry-provenance.json',dict(target_sha256=H,functions=out))
    for a in [0xbd224c,0xbd2248,0xbd2228,0xbd2210]:print(hex(a),next(x for x in imports if x['iat']==hex(a)))
if __name__=='__main__':
    if sys.argv[1]=='prose':
        for n in sys.argv[2:]:dump(int(n))
    elif sys.argv[1]=='evidence':evidence()
    elif sys.argv[1]=='cfg':capture([int(a,16) for a in sys.argv[2:]])
    elif sys.argv[1]=='support':support()
    elif sys.argv[1]=='show':
        for x in sys.argv[2:]:
            for i in cfg(int(x,16))['instructions']:print(i['va'],i['bytes'],i['mnemonic'],i['operands'])
