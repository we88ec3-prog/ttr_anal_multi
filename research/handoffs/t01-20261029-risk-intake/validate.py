"""Run the new main's integrity/dispatch/conformance gates; never generate native verdicts."""
import pathlib,subprocess,sys,json,os,datetime,re
D=pathlib.Path(__file__).resolve().parent;R=D.parents[2];BASE='9d97ea37e'
env=dict(os.environ,PYTHONDONTWRITEBYTECODE='1',PYTHONUTF8='1')
commands=[
 ['governance/validate_s00.py'],['governance/check_s00_readiness.py','--check'],
 ['-m','unittest','discover','-s','governance/tests','-v'],
 ['research/dispatch/dispatch.py','check'],
 ['-m','unittest','discover','-s','research/dispatch/tests','-p','test_*.py','-v'],
 ['-m','unittest','discover','-s','conformance/protocol','-p','test_*.py','-v'],
 ['-m','unittest','discover','-s','conformance/character','-p','test_*.py','-v'],
 ['-m','unittest','discover','-s','conformance/session','-p','test_*.py','-v']]
checks=[]
for args in commands:
    p=subprocess.run([sys.executable,'-X','utf8','-B']+args,cwd=R,env=env,capture_output=True,text=True,encoding='utf8')
    checks.append(dict(command='python -X utf8 -B '+' '.join(args),returncode=p.returncode,stdout=p.stdout.strip(),stderr=p.stderr.strip()))
    assert p.returncode==0,checks[-1]
def old(p):return subprocess.check_output(['git','show',BASE+':'+p],cwd=R)
ledger='shared/integrations/T01-20261029-continuation-02/source-ledger.json';assert old(ledger)==(R/ledger).read_bytes()
for p in ['research/requests/index.json','shared/catalog.json','spec/spec-index.json','design/gaps/index.json']+[f'kr/tasks/{t}/task.json' for t in ['T01','T08','T10','T16']]:
    assert old(p).replace(b'\r\n',b'\n')==(R/p).read_bytes().replace(b'\r\n',b'\n'),p
for path,count in [('research/intake/index.json',10),('research/claims/index.json',16)]:
    before=json.loads(old(path))['items'];after=json.loads((R/path).read_text(encoding='utf8'))['items'];assert before==after[:count],path
src=json.loads((R/'research/intake/index.json').read_text(encoding='utf8'))['items'][10:]
assert len(src)==318 and sum(x['integration_status']=='CONFLICT_CHECKED' for x in src)==4 and sum(x['integration_status']=='REGISTERED' for x in src)==314
clm=json.loads((R/'research/claims/index.json').read_text(encoding='utf8'))['items'][16:]
assert len(clm)==4 and [x['evidence_level'] for x in clm].count('NATIVE_VERIFIED')==3 and clm[-1]['evidence_level']=='PARTIAL'
assert all(x.get('native_review_ref','').startswith('shared/integrations/T01-20261029-continuation-02/') for x in clm[:3])
assert not clm[-1]['native_review_ref'] and not any(x['integration_status']=='SPEC_CONSUMABLE' for x in src)
for p in D.glob('*.md'):
    for href in re.findall(r'\]\(([^)]+)\)',p.read_text(encoding='utf8')):
        if '://' not in href and not href.startswith('#') and href!='validation.json':assert (p.parent/href.split('#')[0]).is_file(),href
out=dict(ok=True,completed_utc=datetime.datetime.now(datetime.timezone.utc).isoformat(),checks=checks,new_sources=318,new_claims=4,history_ledger_rr_owners_catalog_specs_gaps_and_previous_rows_preserved=True,unpublished_drafts_promoted=False,spec_consumable=0,remaining_registration=0,remaining_claim_extraction=314,historical_remaining_not_fullpass=315,meaning='Mechanical/new-workflow integrity and offline synthetic regressions only; no new native semantic verdict or Client/Server acceptance.')
(D/'validation.json').write_bytes((json.dumps(out,ensure_ascii=False,indent=2)+'\n').encode())
print(json.dumps(dict(ok=True,gates=len(checks),new_sources=318,new_claims=4,remaining_registration=0,remaining_claim_extraction=314,historical_remaining=315),ensure_ascii=False))
