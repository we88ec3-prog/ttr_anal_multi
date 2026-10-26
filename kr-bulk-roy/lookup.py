"""Read one locally saved result with a strict output bound. Never starts analysis."""
import argparse,pathlib,json,hashlib,re,sys
sys.stdout.reconfigure(encoding='utf-8')
p=argparse.ArgumentParser();p.add_argument('address');p.add_argument('--sha',default='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91');p.add_argument('--max-chars',type=int,default=4000);p.add_argument('--metadata-only',action='store_true');a=p.parse_args();assert re.fullmatch('[0-9a-f]{64}',a.sha);assert re.fullmatch('0[xX][0-9a-fA-F]+',a.address);address=hex(int(a.address,16));assert 0<=a.max_chars<=16000
root=pathlib.Path(__file__).resolve().parent;out=root/a.sha;index=out/'index.jsonl';match=None
if index.exists():
 with index.open(encoding='utf-8') as f:
  for line in f:
   try:r=json.loads(line)
   except json.JSONDecodeError:continue # A concurrently written final line is not a completed record.
   if r.get('address')==address and (match is None or r.get('status')=='ok'):match=r
if match is None:print(json.dumps({'address':address,'status':'not-saved-yet','source_sha256':a.sha}));sys.exit(2)
assert match['source_sha256']==a.sha
if match['status']!='ok':print(json.dumps({'address':address,'status':match['status'],'error':str(match.get('error'))[:500]}));sys.exit(3)
path=(out/match['pseudocode_path']).resolve();assert path.is_relative_to(out.resolve());raw=path.read_bytes();assert hashlib.sha256(raw).hexdigest()==match['pseudocode_sha256'];text=raw.decode('utf-8').replace('\r\r\n','\n').replace('\r\n','\n').replace('\r','\n')
reference=match.get('batch_path',match.get('seed_evidence'));reference_sha=match.get('batch_sha256',match.get('seed_evidence_sha256'));reference_path=(out/reference) if 'batch_path' in match else (root.parent/reference);assert hashlib.sha256(reference_path.read_bytes()).hexdigest()==reference_sha
result={'address':address,'status':'saved-unreviewed','source_sha256':a.sha,'pseudocode_path':str(path),'pseudocode_sha256':match['pseudocode_sha256'],'evidence_path':str(reference_path),'evidence_sha256':reference_sha,'total_characters':len(text),'limitations':['Derived pseudocode view; source Evidence authoritative; no semantic or gameplay acceptance.']}
if not a.metadata_only:result.update(pseudocode=text[:a.max_chars],truncated=len(text)>a.max_chars)
print(json.dumps(result,ensure_ascii=False))
