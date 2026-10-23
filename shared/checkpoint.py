"""Bounded checkpoint: preserve partial inventory and validate existing exports."""
import datetime,hashlib,json,pathlib,shutil,subprocess,sys,zipfile
ROOT=pathlib.Path(__file__).resolve().parent.parent
def write(p,d):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(d,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
def sha(p):
    h=hashlib.sha256()
    with p.open('rb') as f:
        for b in iter(lambda:f.read(1048576),b''):h.update(b)
    return h.hexdigest()
def main():
    inventory=ROOT/'shared/manifests/source-inventory.jsonl';count=0;size=0;last=None;invalid=0
    with inventory.open(encoding='utf-8') as f:
        for line in f:
            try:r=json.loads(line)
            except json.JSONDecodeError:invalid+=1;continue
            count+=1;size+=r['bytes'];last=r['path']
    results=[]
    for task in ('T08','T09'):
        archive=ROOT/'exports'/f'kr-{task}.zip';out=ROOT/'validation'/f'isolated-{task}'
        if out.exists():raise RuntimeError('Verification directory already exists')
        with zipfile.ZipFile(archive) as z:
            for name in z.namelist():assert (out/name).resolve().is_relative_to(out.resolve())
            z.extractall(out)
        # Deny reads under original anal and both original target binaries.
        code="import sys,pathlib,runpy; root=pathlib.Path.cwd(); original=root.parents[2]/'anal'\ndef audit(event,args):\n if event=='open' and isinstance(args[0],(str,bytes)):\n  p=pathlib.Path(args[0]).resolve()\n  if p==original or original in p.parents or p.name=='Tartaros.bin':raise RuntimeError('Original source access forbidden: '+str(p))\nsys.addaudithook(audit)\nsys.argv=['handoff.py','verify']\nrunpy.run_path(str(root/'shared/handoff.py'),run_name='__main__')"
        cp=subprocess.run([sys.executable,'-c',code],cwd=out,capture_output=True,text=True,encoding='utf-8')
        result={'task':task,'zip':archive.relative_to(ROOT).as_posix(),'zip_sha256':sha(archive),'zip_bytes':archive.stat().st_size,'isolated_exit_code':cp.returncode,'validation':json.loads(cp.stdout) if cp.returncode==0 else {'stdout':cp.stdout,'stderr':cp.stderr}}
        results.append(result)
        assert cp.returncode==0,result
        assert out.resolve().is_relative_to((ROOT/'validation').resolve());shutil.rmtree(out)
        # Archive is validated; remove our generated redundant unpacked export only.
        unpacked=ROOT/'exports'/f'kr-{task}'
        if unpacked.exists():
            assert unpacked.resolve().is_relative_to((ROOT/'exports').resolve());shutil.rmtree(unpacked)
    plan=json.loads((ROOT/'shared/manifests/selection-plan.json').read_text(encoding='utf-8'))
    changed=[]
    for r in plan['entries']:
        p=ROOT.parent/'anal'/r['path']
        if sha(p)!=r['sha256']:changed.append(r['path'])
    catalog=json.loads((ROOT/'shared/catalog.json').read_text(encoding='utf-8'))
    checkpoint={'recorded_at':datetime.datetime.now(datetime.timezone(datetime.timedelta(hours=8))).isoformat(),'status':'user-requested-checkpoint; organization incomplete','reason':'User reports usage below 15 percent and requests current records/outputs','original_anal_mutations_performed':False,'selected_source_hashes_rechecked':len(plan['entries']),'changed_selected_sources':changed,'inventory':{'complete':False,'enumerated_file_count_at_start':105962,'hashed_records':count,'hashed_bytes':size,'last_complete_path':last,'invalid_tail_records':invalid,'resume_rule':'Reuse complete records only if path,size,mtime_ns are unchanged; hash new/changed/unrecorded files. Never truncate this partial inventory to restart.'},'exports':results,'catalog':{'artifacts':len(catalog['artifacts']),'tasks':len(catalog['tasks']),'claims':len(catalog['claims']),'ownership_seeds':len(catalog['entities']),'native_semantics_revalidated':False,'all_tasks_independent_analysis_ready':False},'remaining':['Finish missing source inventory records incrementally; archive full inventory compactly.','Resolve 641 historical/external references or explicitly narrow task evidence requirements; do not call these complete native handoffs.','Review version identity for unclassified selected sources; do not infer from filename.','Reduce ancillary tool-schema and unrelated stage-support records selected by automatic reference following.','Review task-specific evidence and expand ownership beyond 46 initial method seeds before parallel analysis.','Complete final capacity/exclusion classification report after full inventory; existing exports are review packages.'],'current_directory_bytes_before_checkpoint':sum(p.stat().st_size for p in ROOT.rglob('*') if p.is_file())}
    write(ROOT/'CHECKPOINT.json',checkpoint);write(ROOT/'validation/export-validation.json',results)
    print(json.dumps(checkpoint,ensure_ascii=False))
if __name__=='__main__':main()
