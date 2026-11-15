#!/usr/bin/env python3
"""Read-only aggregate verification of bounded MEF world-integration evidence.

Checks original identities, artifact hashes, fixed Git tree/source pins and each
subgroup's static reproducer. Never runs Client/Lua, sends packets or fetches Git.
"""
import argparse
from collections import defaultdict
import hashlib
import json
import os
from pathlib import Path
import re
import subprocess
import sys

sys.dont_write_bytecode=True
HERE=Path(__file__).resolve().parent
ENV=dict(os.environ,GIT_NO_LAZY_FETCH='1',GIT_OPTIONAL_LOCKS='0',
         GIT_TERMINAL_PROMPT='0',GIT_NO_REPLACE_OBJECTS='1',PYTHONDONTWRITEBYTECODE='1')
def check(ok,message):
    if not ok:raise AssertionError(message)
def sha(data):return hashlib.sha256(data).hexdigest()
def load(path):return json.loads(path.read_text(encoding='utf-8'))
def pins_in(value):
    """Normalize explicit source identities; a pin is not a claim of full reading."""
    if isinstance(value,dict):
        if 'commit' in value and 'path' in value:
            blob=next((value[k] for k in ('git_blob','blob','git_blob_sha1') if k in value),None)
            if blob:yield value['commit'],value['path'],blob
        if all(k in value for k in ('repo_commit','repo_path','repo_blob')):
            yield value['repo_commit'],value['repo_path'],value['repo_blob']
        for child in value.values():yield from pins_in(child)
    elif isinstance(value,list):
        for child in value:yield from pins_in(child)

def main():
    ap=argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--originals',type=Path,required=True)
    ap.add_argument('--repo',type=Path,required=True)
    args=ap.parse_args();repo=args.repo.resolve();originals=args.originals.resolve()
    manifest=load(HERE/'source-manifest.json');artifacts=load(HERE/'artifact-manifest.json')
    for row in artifacts['files']:
        path=repo/row['path'];data=path.read_bytes()
        check(len(data)==row['bytes'] and sha(data)==row['sha256'],'Artifact identity: '+row['path'])
    for row in manifest['originals']:
        data=(originals/row['file']).read_bytes()
        check(len(data)==row['bytes'] and sha(data)==row['sha256'],'Original identity: '+row['file'])
    instruction=manifest['shared_instructions']
    check(sha((originals/instruction['file']).read_bytes())==instruction['sha256'],'Shared instruction identity')

    normalized={}
    sources=[manifest]
    for group in manifest['subgroups']:
        path=HERE/group['manifest']
        check(sha(path.read_bytes())==group['sha256'],'Subgroup manifest hash: '+group['name'])
        sources.append(load(path))
    for source in sources:
        for commit,path,blob in pins_in(source):
            check(re.fullmatch('[0-9a-f]{40}',commit) and re.fullmatch('[0-9a-f]{40}',blob),'Complete source object identity')
            key=(commit,path)
            check(key not in normalized or normalized[key]==blob,'Conflicting source pin: '+path)
            normalized[key]=blob
    by_commit=defaultdict(dict)
    for (commit,path),blob in normalized.items():by_commit[commit][path]=blob
    for commit,expected in by_commit.items():
        out=subprocess.check_output(['git','-c','core.quotePath=false','ls-tree','-r',commit,'--',*sorted(expected)],cwd=repo,env=ENV,text=True)
        actual={}
        for line in out.splitlines():
            header,path=line.split('\t',1);actual[path]=header.split()[2]
        check(actual==expected,'Offline Git tree identities: '+commit)

    results={}
    for group in manifest['subgroups']:
        options=[arg.replace('{repo}',str(repo)).replace('{originals}',str(originals)) for arg in group['args']]
        run=subprocess.run([sys.executable,'-B',str(HERE/group['verifier']),*options],cwd=repo,env=ENV,capture_output=True,text=True)
        check(run.returncode==0,group['name']+' verifier failed:\n'+run.stdout+run.stderr)
        result=json.loads(run.stdout)
        check(result.get('status')=='PASS','Missing PASS: '+group['name'])
        results[group['name']]=result

    checked=0;tree_only=[]
    for path in [repo/manifest['primary_report'],*sorted(HERE.rglob('*.md'))]:
        body=path.read_text(encoding='utf-8')
        for target in re.findall(r'(?<!!)\[[^\]]+\]\(([^\s)]+)(?:\s+[^)]*)?\)',body):
            if re.match(r'^[a-zA-Z][a-zA-Z0-9+.-]*:',target) or target.startswith('#'):continue
            local=(path.parent/target.split('#',1)[0]).resolve()
            check(local.is_relative_to(repo),'Documentation link outside repo: '+target)
            checked+=1
            if local==HERE/'verification-result.json' or local.is_file():continue
            rel=local.relative_to(repo).as_posix()
            out=subprocess.check_output(['git','-c','core.quotePath=false','ls-tree',manifest['work_parent'],'--',rel],cwd=repo,env=ENV,text=True).strip()
            check(out and out.split('\t',1)[1]==rel,'Missing evidence link: '+str(path)+' -> '+target)
            tree_only.append(rel)
    print(json.dumps(dict(status='PASS',scope='Bounded static original-byte, selected dataflow, Lua-bytecode-as-data, source identity and SYN arithmetic checks only',work_parent=manifest['work_parent'],main_baseline=manifest['main_baseline'],artifact_files=len(artifacts['files']),unique_commit_path_pins=len(normalized),source_commits=sorted(by_commit),markdown_links=dict(checked=checked,tree_only_sparse_paths=sorted(set(tree_only))),subgroup_results=results,client_executed=False,lua_executed=False,network_transmitted=False,limits=['First new MEF caller remains a conditional content-integration requirement','Ordinary combat runner and typed actor/event integration are not fully proved','No runtime or gameplay validation; no T01 FULL-PASS or shared status change']),ensure_ascii=False,indent=2))

if __name__=='__main__':main()
