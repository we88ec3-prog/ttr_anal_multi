#!/usr/bin/env python3
"""Verify the R10 MEF research package against originals and pinned local Git.

Read-only: no fetch, Git mutation, Lua/Client/Server execution, game packet,
resource compilation or extraction. JSON is printed to stdout. Sub-verifiers
read their own evidence and original files without writing results. R9 was
rechecked for this delivery; --recheck-r9 explicitly repeats that prior check.
"""
import argparse
from concurrent.futures import ThreadPoolExecutor, as_completed
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys
from urllib.parse import unquote
sys.dont_write_bytecode=True

def require(ok,why):
    if not ok:raise ValueError(why)
def sha(b):return hashlib.sha256(b).hexdigest()
def blob(b):return hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()
def load(p):return json.loads(p.read_text())

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--originals',type=Path,required=True)
    ap.add_argument('--repo',type=Path,required=True)
    ap.add_argument('--recheck-r9',action='store_true')
    args=ap.parse_args();repo=args.repo.resolve();originals=args.originals.resolve();package=Path(__file__).resolve().parent
    manifest=load(package/'source-manifest.json');inventory=load(package/'artifact-manifest.json');flow=load(package/'flow-contract.json')
    env=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',GIT_NO_REPLACE_OBJECTS='1',GIT_TERMINAL_PROMPT='0',PYTHONDONTWRITEBYTECODE='1')
    gitcmd=['git','-c','remote.origin.promisor=false','-c','maintenance.auto=false','-C',str(repo)]
    def git(*parts):return subprocess.run(gitcmd+list(parts),env=env,capture_output=True,check=True).stdout
    def path(rel):
        p=(repo/rel).resolve();require(p.is_relative_to(repo),'Path escapes repo: '+rel);return p
    def exists(rel):
        if path(rel).is_file():return True
        return subprocess.run(gitcmd+['cat-file','-e',manifest['git']['work_parent']+':'+rel],env=env,stdout=subprocess.DEVNULL,stderr=subprocess.DEVNULL).returncode==0
    originals_checked=[]
    for r in manifest['originals']+[manifest['provided_instructions']]:
        b=(originals/r['file']).read_bytes();require(len(b)==r['bytes'] and sha(b)==r['sha256'],'Original identity: '+r['file']);originals_checked.append(r['file'])
    g=manifest['git']
    require(g['branch']=='extra/roy1' and g['new_branch_created'] is False,'Existing requested branch')
    require(git('rev-parse',g['work_parent']+'^{tree}').decode().strip()==g['work_parent_tree'],'Public R9 parent tree')
    git('merge-base','--is-ancestor',g['main_baseline'],g['work_parent'])
    require(g['main_already_ancestor'] is True and g['formal_task_statuses_modified'] is False,'Unchanged synchronized baseline and formal statuses')

    recorded=set()
    for r in inventory['files']:
        rel=r['path'];require(rel==manifest['primary_report'] or rel.startswith(manifest['package_path']+'/'),'Deliverable scope')
        require(rel not in recorded,'Duplicate artifact');recorded.add(rel);b=path(rel).read_bytes()
        require(len(b)==r['bytes'] and sha(b)==r['sha256'],'Artifact hash: '+rel)
        require(b'\0' not in b,'Research deliverable unexpectedly contains binary NUL: '+rel)
    excluded=set(inventory['excluded_self_or_generated_paths'])
    actual={p.relative_to(repo).as_posix() for p in package.rglob('*') if p.is_file()};actual.add(manifest['primary_report'])
    require(actual-excluded==recorded,'Complete package inventory')
    require(excluded=={manifest['package_path']+'/artifact-manifest.json',manifest['package_path']+'/verification-result.json'},'Only self and aggregate generated result excluded')
    require(all(Path(p).suffix in {'.md','.json','.asm','.py'} for p in actual),'Only analysis/excerpt/verifier file types')
    require(not any('/_work/' in p or '/__pycache__/' in p for p in actual),'No work or bytecode cache included')
    require(all(manifest['publication'][k] is False for k in ['raw_originals_included','full_unpacked_resources_included','new_deployable_game_resources_included']),'Publication excludes originals/unpacked/deployable resources')

    source_groups={n:load(package/n/'source-manifest.json') for n in ['supervisor','presentation','runner','world']}
    pins=list(manifest['references'])
    pins+=source_groups['supervisor']['references']+[source_groups['supervisor']['coroutine_original']]
    pins+=source_groups['presentation']['references']
    pins+=source_groups['runner']['source_pins']
    pins+=source_groups['world']['git_sources']+[source_groups['world']['parser_source']]
    normalized={}
    for r in pins:
        p=dict(commit=r['commit'],path=r['path'],git_blob=r.get('git_blob',r.get('blob')),bytes=r.get('bytes',r.get('size')),sha256=r['sha256'])
        require(p['git_blob'] and p['bytes'] is not None,'Complete source identity')
        require(p['commit'] in {g['main_baseline'],g['work_parent']},'All new direct pins use public main or R9')
        key=(p['commit'],p['path'])
        if key in normalized:require(normalized[key]==p,'Conflicting source pin: '+p['path'])
        normalized[key]=p
    blobs={}
    for p in normalized.values():
        bsha=git('rev-parse',p['commit']+':'+p['path']).decode().strip();require(bsha==p['git_blob'],'Source commit/path/blob: '+p['path'])
        if bsha not in blobs:blobs[bsha]=git('cat-file','blob',bsha)
        b=blobs[bsha];require(blob(b)==bsha and sha(b)==p['sha256'] and len(b)==p['bytes'],'Source contents: '+p['path'])
    for r in source_groups['world']['peer_sources']:
        p=(package/'world'/r['path']).resolve();require(p.is_relative_to(package),'Peer remains in package')
        b=p.read_bytes();require(len(b)==r['bytes'] and sha(b)==r['sha256'],'Frozen runner/world peer source')

    old_result_path='kr-extra-roy/MEF-end-to-end-20261116/verification-result.json'
    old_pin=normalized[(g['work_parent'],old_result_path)]
    old_result=json.loads(blobs[old_pin['git_blob']]);expected=json.loads(json.dumps(old_result))
    for r in expected['previous_rounds'].values():r['rechecked_this_run']=False
    previous=load(package/'previous-r9-verification.json')
    require(previous==expected and previous['status']=='PASS','Actual saved R9 rerun matches fixed R9 output except explicit prior-rerun flags')

    stages={r['id']:r for r in flow['stages']};require(len(stages)==len(flow['stages']),'Unique flow stages')
    require(flow['work_parent']==g['work_parent'] and flow['original_sha256']==manifest['originals'][0]['sha256'],'Flow source identity')
    for s in stages.values():
        require(s['classification'] in {'CLIENT_CONFIRMED_BOUNDED','DESIGN_CONDITIONAL','SERVER_DEVELOPMENT'} and s['owner'] and s['preconditions'] and s['limits'],'Explicit stage classification and limits')
        require(exists(s['evidence']),'Flow evidence exists: '+s['evidence'])
    adj={i:set() for i in stages}
    for edge in flow['edges']:
        require(edge['source'] in stages and edge['target'] in stages and edge['condition'],'Conditional graph edge');adj[edge['source']].add(edge['target'])
    reachable={'deliver'};todo=['deliver']
    while todo:
        for t in adj[todo.pop()]-reachable:reachable.add(t);todo.append(t)
    require(reachable==set(stages),'Every described analysis stage is reachable')
    require(all(stages[n]['classification']=='DESIGN_CONDITIONAL' for n in ['formal','module','supervisor','entry','wait','cleanup']),'New content remains design')
    require('end' in adj['cleanup'] and 'external_failure' in adj['cleanup'],'Cleanup completion and failure are separate')
    require(flow['original_mef_entry']['classification']=='CLIENT_UNRESOLVED' and flow['original_mef_entry']['restore_map_receiver_is_trigger_root'] is False,'Native MEF first caller remains unresolved')
    require(flow['ordinary_gameplay']['classification']=='CLIENT_UNRESOLVED' and len(flow['ordinary_gameplay']['required_joins'])==3,'Ordinary gameplay joins remain open')
    require(all(v is False for v in flow['validation'].values()),'No execution/deployment/formal acceptance claimed')
    sc=load(package/'supervisor/supervisor-contract.json');pc=load(package/'presentation/contracts.json')
    require(sc['scheduling']['registered_threads']==['outer_only'] and sc['scheduling']['inner_registered_in_qco'] is False,'One registered outer; child private')
    require(sc['scheduling']['outer_moco_resume_arguments']==sc['scheduling']['inner_resume_arguments']==0,'No invented resume payload')
    require(sc['boundaries']['wrap_yielding_entry_in_pcall'] is False and sc['cancellation']['external_remove_runs_cleanup'] is False,'Yield/cancellation boundary retained')
    require(sc['cleanup']['End_then_Stop_is_recovery'] is False and pc['end_stop']['end_then_stop_repairs_all_presentation'] is False,'Shared End/Stop boundary')
    require(pc['end_stop']['stop_cancels_all_tutorial_images'] is False and pc['end_stop']['observer_zero_proves_normal_completion'] is False,'Typed image cleanup and observer cancellation retained')
    order=[r['step'] for r in pc['conditional_cleanup_order']]
    require(order.index('restore_owned_map')<order.index('release_owned_q_actors')<order.index('release_owned_camera_override')<order.index('end_once'),'Cleanup order agrees with selected native reference')
    require(pc['sepia']['subsequent_native_update_phases']==[5,6,0] and pc['world_presentation']['server_time_control'] is False,'Deferred effect and time ownership')

    link_count=0;tree_only=set()
    for r in inventory['files']:
        if not r['path'].endswith('.md'):continue
        src=path(r['path'])
        for target in re.findall(r'\[[^\]\n]*\]\(([^)\n]+)\)',src.read_text()):
            target=target.split('#',1)[0]
            if not target or re.match(r'^[A-Za-z][A-Za-z0-9+.-]*:',target):continue
            p=(src.parent/unquote(target)).resolve();require(p.is_relative_to(repo),'Markdown link escapes repo')
            rel=p.relative_to(repo).as_posix();require(exists(rel),'Missing link: '+r['path']+' -> '+target)
            if not p.exists():tree_only.add(rel)
            link_count+=1

    def run(script,options):
        r=subprocess.run([sys.executable,'-B',str(script)]+[str(x) for x in options],env=env,cwd=repo,capture_output=True,text=True)
        require(r.returncode==0,'Verifier failed '+str(script)+'\n'+r.stdout[-4000:]+r.stderr[-4000:])
        j=json.loads(r.stdout);require(j['status']=='PASS','Verifier did not pass: '+str(script));return j
    groups={}
    def subgroup(name):
        opts=['--bin',originals/'02-Tartaros.bin','--repo',repo]
        if name in {'supervisor','world'}:opts+=['--event-stp',originals/'06-Event.stp']
        current=run(package/name/'verify_evidence.py',opts)
        require(current==load(package/name/'verification-result.json'),'Current subgroup output equals saved actual result: '+name)
        return current
    with ThreadPoolExecutor(max_workers=4) as pool:
        pending={pool.submit(subgroup,n):n for n in ['supervisor','presentation','runner','world']}
        for job in as_completed(pending):groups[pending[job]]=job.result()
    groups={n:groups[n] for n in sorted(groups)}
    if args.recheck_r9:
        repeated=run(repo/'kr-extra-roy/MEF-end-to-end-20261116/verify_evidence.py',['--originals',originals,'--repo',repo])
        require(repeated==previous,'Repeated R9 output equals saved rerun')

    # Shared excerpts must not silently disagree at a decoded instruction VA.
    addresses={};counts={};ranges=[]
    for n in groups:
        native=load(package/n/'native-windows.json');records=native.get('records',native.get('windows'))
        counts[n]=dict(native_records=len(records),code_windows=sum(r['kind']=='code' for r in records),bytes_with_overlap=sum(r['length'] for r in records),instructions_with_overlap=sum(len(r.get('instructions',[])) for r in records))
        for r in records:
            ranges.append((int(r['va'],0),int(r['end'],0)))
            for i in r.get('instructions',[]):
                v=int(i['va'],0)
                if v in addresses:require(addresses[v]==i['hex'],'Conflicting shared native instruction at '+hex(v))
                addresses[v]=i['hex']
    union=0;end=-1
    for a,b in sorted(ranges):
        if b>end:union+=b-max(a,end);end=b
    result=dict(status='PASS',scope='Read-only originals, fixed public sources, package integrity, shared native consistency and bounded design contracts; not execution or formal semantic acceptance',git=g,original_identities=originals_checked,artifact_files=len(recorded),total_deliverable_files=len(actual),unique_commit_path_pins=len(normalized),unique_source_blobs=len(blobs),source_commits=sorted({p['commit'] for p in normalized.values()}),peer_pins=len(source_groups['world']['peer_sources']),flow=dict(stages=len(stages),conditional_edges=len(flow['edges']),failure_boundaries=len(flow['failure_boundaries'])),markdown_links=dict(checked=link_count,sparse_tree_only_targets=sorted(tree_only)),native_summary=counts,unique_native_instruction_starts=len(addresses),unique_excerpted_native_bytes=union,subgroup_results=groups,previous_r9=dict(recorded_status=previous['status'],saved_rerun_sha256=sha((package/'previous-r9-verification.json').read_bytes()),compared_to_pinned_public_result=True,rechecked_this_invocation=args.recheck_r9,r6_r7_r8_repeated=False),client_executed=False,lua_executed=False,server_executed=False,game_resources_modified=False,limits=manifest['coverage_notes']+['PASS is not T01 FULL-PASS, RR ACCEPTED, implemented server or gameplay validation','Original native MEF first caller and ordinary gameplay joins remain unresolved'])
    print(json.dumps(result,ensure_ascii=False,indent=2))

if __name__=='__main__':
    try:main()
    except (ValueError,KeyError,OSError,subprocess.CalledProcessError) as e:
        print(json.dumps(dict(status='FAIL',error=str(e)),ensure_ascii=False,indent=2),file=sys.stderr);sys.exit(1)
