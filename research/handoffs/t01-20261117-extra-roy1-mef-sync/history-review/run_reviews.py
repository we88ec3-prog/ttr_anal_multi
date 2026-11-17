#!/usr/bin/env python3
"""Run already inspected, offline research verifiers; never execute the game."""
import concurrent.futures
import datetime
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys
import time

ROOT = Path(__file__).resolve().parent
REPO = Path('/workspace/scratch/b43c6175f310/ttr_anal_multi')
SOURCES = Path('/workspace/scratch/d850068ce350/project_sources')
ENV = dict(os.environ, GIT_NO_LAZY_FETCH='1', GIT_OPTIONAL_LOCKS='0',
           GIT_TERMINAL_PROMPT='0', GIT_NO_REPLACE_OBJECTS='1',
           PYTHONDONTWRITEBYTECODE='1', GIT_CONFIG_COUNT='1',
           GIT_CONFIG_KEY_0='protocol.allow', GIT_CONFIG_VALUE_0='never')

def run(job):
    label, argv = job
    command = [sys.executable, '-B', *map(str, argv)]
    start = datetime.datetime.now(datetime.timezone.utc).isoformat()
    tic = time.monotonic()
    p = subprocess.run(command, cwd=REPO, env=ENV, capture_output=True)
    out, err = ROOT / (label+'.stdout.json'), ROOT / (label+'.stderr.txt')
    out.write_bytes(p.stdout)
    err.write_bytes(p.stderr)
    row = dict(label=label, command=command, cwd=str(REPO),
               started_utc=start, elapsed_seconds=round(time.monotonic()-tic,3),
               returncode=p.returncode, stdout=out.name, stderr=err.name,
               stdout_sha256=hashlib.sha256(p.stdout).hexdigest(),
               stderr_sha256=hashlib.sha256(p.stderr).hexdigest())
    try:
        obj=json.loads(p.stdout)
        row['reported_status']=obj.get('status', obj.get('all_matched'))
    except (ValueError, AttributeError):
        row['reported_status']=None
    (ROOT/(label+'.command.json')).write_text(json.dumps(row,ensure_ascii=False,indent=2)+'\n')
    print(json.dumps(row,ensure_ascii=False),flush=True)
    return row

def aggregate_jobs():
    packages = ['trigger-callers-20261115','complete-flow-20261115',
                'end-to-end-20261116','control-flow-20261116','capabilities-20261116']
    for name in packages:
        args=[REPO/'kr-extra-roy'/('MEF-'+name)/'verify_evidence.py',
              '--originals',SOURCES,'--repo',REPO]
        if name=='end-to-end-20261116':args.append('--recheck-prior')
        yield name,args

if __name__=='__main__':
    jobs=list(aggregate_jobs())
    with concurrent.futures.ThreadPoolExecutor(max_workers=3) as pool:
        rows=list(pool.map(run,jobs))
    (ROOT/'aggregate-runs.json').write_text(json.dumps(rows,ensure_ascii=False,indent=2)+'\n')
