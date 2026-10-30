import pathlib,json,re,hashlib,sys,os
os.environ['PYTHONDONTWRITEBYTECODE']='1';sys.dont_write_bytecode=True
sys.stdout.reconfigure(encoding='utf8')
D=pathlib.Path(__file__).resolve().parent;R=D.parents[3]
LEDGER=R/'shared/integrations/T01-20261029-continuation-02/source-ledger.json'
Q=[q for q in json.loads(LEDGER.read_text(encoding='utf8'))['rows'] if q['task']=='T08' and 153<=q['number']<=200]
assert len(Q)==48
def read(q):
    b=(R/q['source']).read_bytes();assert hashlib.sha256(b).hexdigest()==q['sha256'];assert hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()==q['git_blob_sha']
    return b.decode('utf8').splitlines()
def narrative(q):
    rows=[];fence=False
    for n,line in enumerate(read(q),1):
        if line.startswith('```'):fence=not fence;continue
        if fence or not line.strip():continue
        if 'SHA256' in line or line.startswith('- 原件') or line.startswith('- 檔案'):continue
        rows.append(f'{n}: {line}')
    return '\n'.join(rows)
if __name__=='__main__':
    lo,hi=map(int,sys.argv[1:3])
    for q in Q:
        if lo<=q['number']<=hi:print('\n### '+str(q['number'])+' '+q['source']+'\n'+narrative(q))
