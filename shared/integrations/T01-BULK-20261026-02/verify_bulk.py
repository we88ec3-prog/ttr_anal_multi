"""Read-only file/index SHA verification; no decompilation, target execution or original files."""
import pathlib,json,gzip,hashlib,collections,argparse,subprocess,threading
ROOT=pathlib.Path(__file__).resolve().parents[3];BATCH=pathlib.Path(__file__).resolve().parent
def sha(data):return hashlib.sha256(data).hexdigest()
def main():
    ap=argparse.ArgumentParser();ap.add_argument('--git-index',action='store_true');args=ap.parse_args()
    with gzip.open(BATCH/'source-files.json.gz','rt',encoding='utf-8') as f:manifest=json.load(f)
    if args.git_index:
        proc=subprocess.Popen(['git','-C',str(ROOT),'cat-file','--batch'],stdin=subprocess.PIPE,stdout=subprocess.PIPE)
        requests=['kr-bulk-roy/'+x['path'] if x['path']!='README.md' else 'kr-bulk-roy/README.source-before-upload.md' for x in manifest['files']]
        target=json.loads((ROOT/'shared/catalog.json').read_text(encoding='utf-8'))['targets']['kr']['sha256']
        requests+=['shared/catalog.json','kr-bulk-roy/'+target+'/index.jsonl']
        requests+=[x['path'] for x in json.loads((BATCH/'seed-dependencies.json').read_text(encoding='utf-8'))]
        requests+=['shared/integrations/T01-BULK-20261026-02/review-status.jsonl.gz'];request_order=iter(requests)
        def feed():proc.stdin.write(('\n'.join(':'+p for p in requests)+'\n').encode('utf-8'));proc.stdin.close()
        writer=threading.Thread(target=feed);writer.start()
    def read(rel):
        p=(ROOT/rel).resolve();assert p.is_relative_to(ROOT.resolve())
        if not args.git_index:return p.read_bytes()
        assert next(request_order)==rel;header=proc.stdout.readline().split();assert len(header)==3 and header[1]==b'blob',rel
        size=int(header[2]);data=proc.stdout.read(size);assert len(data)==size and proc.stdout.read(1)==b'\n';return data
    hashes={};total=0
    for row in manifest['files']:
        rel='kr-bulk-roy/'+row['path']
        if row['path']=='README.md':rel='kr-bulk-roy/README.source-before-upload.md'
        data=read(rel);assert len(data)==row['bytes'] and sha(data)==row['sha256'],rel;hashes[row['path']]=row['sha256'];total+=len(data)
    c=json.loads(read('shared/catalog.json'));target=c['targets']['kr']['sha256'];addresses=set();count=0
    index=read('kr-bulk-roy/'+target+'/index.jsonl').decode('utf-8').splitlines()
    for line in index:
        row=json.loads(line);assert row['status']=='ok' and row['source_sha256']==target;assert row['address'] not in addresses;addresses.add(row['address']);count+=1
        assert hashes[target+'/'+row['pseudocode_path']]==row['pseudocode_sha256']
        if row.get('batch_path'):assert hashes[target+'/'+row['batch_path']]==row['batch_sha256']
        else:assert sha(read(row['seed_evidence'].replace('\\','/')))==row['seed_evidence_sha256']
    states=set();status_addresses=set();related=0
    for line in gzip.decompress(read('shared/integrations/T01-BULK-20261026-02/review-status.jsonl.gz')).decode('utf-8').splitlines():
        row=json.loads(line);assert row['address'] not in status_addresses;status_addresses.add(row['address']);states.add(row['full_function_semantic_review']);related+=bool(row['related_bounded_evidence'])
        assert hashes[row['path'].removeprefix('kr-bulk-roy/')]==row['sha256']
    assert addresses==status_addresses and states=={'not-recorded'}
    if args.git_index:writer.join();assert proc.wait()==0
    return {'ok':True,'source_files':len(manifest['files']),'source_bytes':total,'functions':count,'review_status_rows':len(status_addresses),'full_function_review_not_recorded':len(status_addresses),'exact_related_bounded_evidence_functions':related,'verified_git_index':args.git_index,'semantic_review_performed':False}
if __name__=='__main__':print(json.dumps(main(),ensure_ascii=False))
