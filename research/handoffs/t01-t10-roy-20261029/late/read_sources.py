import pathlib,json,re,hashlib,sys,os
os.environ['PYTHONDONTWRITEBYTECODE']='1';sys.dont_write_bytecode=True;sys.stdout.reconfigure(encoding='utf8')
D=pathlib.Path(__file__).resolve().parent;R=D.parents[3]
MASTER=json.loads((D.parent/'sources.json').read_text(encoding='utf8'))
Q=[x for x in MASTER['sources'] if x['scope']=='late'];assert len(Q)==34
def lines(q):
    b=(R/q['source_file']).read_bytes();assert hashlib.sha256(b).hexdigest()==q['source_sha256'];assert hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==q['source_blob_sha'];return b.decode('utf8').splitlines()
def narrative(q):
    fence=False;out=[]
    for n,l in enumerate(lines(q),1):
        if l.startswith('```'):fence=not fence;continue
        if fence or not l.strip():continue
        if re.match(r'^\s*(?:0x)?[0-9a-fA-F]{6,8}:',l):continue
        out.append((n,l))
    return out
if __name__=='__main__':
    lo,hi=map(int,sys.argv[1:3])
    for q in Q:
        if lo<=q['number']<=hi:
            ns=narrative(q)
            print('\n### '+q['source_file']+' total_lines='+str(q['lines'])+' prose_chars='+str(sum(len(s) for _,s in ns)))
            print('\n'.join(f'{n}: {s}' for n,s in ns))
