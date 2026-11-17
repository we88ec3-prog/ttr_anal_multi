#!/usr/bin/env python3
"""User-run publisher for the already authorized public research scope.
Requires an authenticated LOCAL checkout. Never creates a branch, forces a push,
rewrites history or includes unrelated files. Default writes; --verify-only is read-only
except updating origin's fetched tracking ref. No game or server program is executed.
"""
from __future__ import annotations
import argparse,hashlib,json,re,subprocess,sys
from pathlib import Path,PurePosixPath
BRANCH='extra/roy1'
ALLOWED_REMOTES={
 'https://github.com/we88ec3-prog/ttr_anal_multi',
 'https://github.com/we88ec3-prog/ttr_anal_multi.git',
 'git@github.com:we88ec3-prog/ttr_anal_multi.git',
 'git@github.com:we88ec3-prog/ttr_anal_multi',
 'ssh://git@github.com/we88ec3-prog/ttr_anal_multi.git',
}
SCOPES={'MEF-full-surface-native-continuation-20261116','MEF-feature-lifecycle-20261117',
        'MEF-world-identity-scene-interaction-20261117','MEF-transition-actor-event-20261117'}

def sha(b:bytes)->str:return hashlib.sha256(b).hexdigest()
def git(repo:Path,*args:str)->bytes:
    p=subprocess.run(['git','-C',str(repo),*args],stdout=subprocess.PIPE,stderr=subprocess.PIPE)
    if p.returncode:
        # Do not echo transport stderr which might contain user credentials.
        raise RuntimeError(f'git {args[0]} failed (exit {p.returncode}); inspect locally. No force/reset is attempted.')
    return p.stdout

def validate_manifest(m:dict)->list[dict]:
    if not re.fullmatch('[0-9a-f]{40}',m['expected_base']):raise ValueError('Invalid expected base')
    seen=set()
    for x in m['files']:
        p=PurePosixPath(x['path'])
        if p.is_absolute() or '..'in p.parts or '\\'in x['path'] or len(p.parts)!=3 or p.parts[0]!='kr-extra-roy' or p.parts[1]not in SCOPES:
            raise ValueError('Manifest path outside authorized research directories')
        if p.suffix.lower()in {'.exe','.bin','.stp','.lua','.seq','.mef'}:raise ValueError('Original/deployable resource excluded')
        if x['path']in seen:raise ValueError('Duplicate manifest path')
        seen.add(x['path'])
        if not re.fullmatch('[0-9a-f]{64}',x['sha256']):raise ValueError('Invalid content hash')
    if len(seen)!=m['file_count']:raise ValueError('Manifest count')
    return m['files']

def verify_commit(repo:Path,commit:str,files:list[dict])->list[dict]:
    checked=[]
    for x in files:
        content=git(repo,'cat-file','blob',f"{commit}:{x['path']}")
        if len(content)!=x['bytes']or sha(content)!=x['sha256']:
            raise RuntimeError('Published content mismatch: '+x['path'])
        blob=hashlib.sha1(b'blob '+str(len(content)).encode()+b'\0'+content).hexdigest()
        if blob!=x['git_blob']:raise RuntimeError('Git blob mismatch: '+x['path'])
        checked.append(dict(path=x['path'],sha256=x['sha256'],git_blob=blob))
    return checked

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--repo',required=True,type=Path)
    p.add_argument('--manifest',required=True,type=Path)
    p.add_argument('--patch',type=Path)
    p.add_argument('--verify-only',action='store_true')
    p.add_argument('--receipt',type=Path,default=Path('MEF-remote-publication-receipt.json'))
    a=p.parse_args();repo=a.repo.resolve();m=json.loads(a.manifest.read_text(encoding='utf-8'));files=validate_manifest(m)
    if git(repo,'remote','get-url','origin').decode().strip()not in ALLOWED_REMOTES:raise RuntimeError('Origin is not the approved repository URL')
    if git(repo,'symbolic-ref','--short','HEAD').decode().strip()!=BRANCH:raise RuntimeError('Checkout must already be on extra/roy1; no branch is created/switched')
    git(repo,'fetch','origin',f'refs/heads/{BRANCH}:refs/remotes/origin/{BRANCH}','refs/heads/main:refs/remotes/origin/main')
    if not a.verify_only:
        if not a.patch:raise ValueError('--patch required for publication')
        patch=a.patch.resolve();content=patch.read_bytes()
        if sha(content)!=m['patch_sha256']:raise RuntimeError('Patch SHA mismatch')
        paths=re.findall(rb'^diff --git a/([^\r\n ]+) b/([^\r\n ]+)$',content,re.M)
        if len(paths)!=len(files)or any(x!=y for x,y in paths)or {x.decode()for x,_ in paths}!={x['path']for x in files}:raise RuntimeError('Patch path set mismatch')
        if git(repo,'status','--porcelain','--untracked-files=all').strip():raise RuntimeError('Working tree/index must be clean; no files will be reset')
        local=git(repo,'rev-parse','HEAD').decode().strip();remote=git(repo,'rev-parse',f'origin/{BRANCH}').decode().strip()
        if local!=m['expected_base']or remote!=m['expected_base']:raise RuntimeError('Base changed; reconcile existing commits manually before publication')
        git(repo,'merge-base','--is-ancestor','origin/main','HEAD')
        git(repo,'apply','--check','--index',str(patch))
        git(repo,'-c','core.autocrlf=false','apply','--index','--whitespace=nowarn',str(patch))
        changed=git(repo,'diff','--cached','--name-only','-z').split(b'\0');changed={x.decode()for x in changed if x}
        if changed!={x['path']for x in files}:raise RuntimeError('Unexpected staged files; publication stopped without reset')
        # Compare index blobs before commit, independent of workstation line endings.
        for x in files:
            b=git(repo,'show',':'+x['path'])
            if sha(b)!=x['sha256']:raise RuntimeError('Staged content mismatch; stopped without reset')
        git(repo,'commit','-m','docs(mef): publish pending lifecycle, world, transition and event research')
        local=git(repo,'rev-parse','HEAD').decode().strip();verify_commit(repo,local,files)
        committed={x.decode() for x in git(repo,'diff-tree','--no-commit-id','--name-only','-r','-z',local).split(b'\0') if x}
        if committed!={x['path']for x in files}:raise RuntimeError('Commit changed unexpected paths; stopped before push')
        git(repo,'push','origin',f'{local}:refs/heads/{BRANCH}')
    git(repo,'fetch','origin',f'refs/heads/{BRANCH}:refs/remotes/origin/{BRANCH}')
    observed=git(repo,'rev-parse',f'origin/{BRANCH}').decode().strip()
    git(repo,'merge-base','--is-ancestor',m['expected_base'],observed)
    checked=verify_commit(repo,observed,files)
    live=git(repo,'ls-remote','origin',f'refs/heads/{BRANCH}').decode().split()
    if not live or live[0]!=observed:raise RuntimeError('Remote changed during verification; run --verify-only again')
    receipt=dict(status='REMOTE_CONTENT_VERIFIED',repository='we88ec3-prog/ttr_anal_multi',branch=BRANCH,remote_commit=observed,verified_files=len(checked),files=checked)
    a.receipt.write_text(json.dumps(receipt,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:v for k,v in receipt.items()if k!='files'},ensure_ascii=False,indent=2))

if __name__=='__main__':
    try:main()
    except (OSError,ValueError,KeyError,RuntimeError)as exc:
        print('STOPPED: '+str(exc),file=sys.stderr);sys.exit(1)
