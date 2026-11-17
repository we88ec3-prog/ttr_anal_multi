#!/usr/bin/env python3
from concurrent.futures import ThreadPoolExecutor
import json
from run_reviews import ROOT, REPO, SOURCES, run

K=REPO/'kr-extra-roy'
B=SOURCES/'02-Tartaros.bin'; E=SOURCES/'06-Event.stp'
T=SOURCES/'07-Table.stp'; M=SOURCES/'10-BoundMap.stp'
REST=ROOT/'restored'
PARSER=REST/'MEF-one-shot-study-20261116/verify_evidence.py'
jobs=[]
for name in ['checkpoint-20261116','trigger-continuation-20261116']:
    package=K/('MEF-'+name)
    jobs.append((name,[package/'verify_evidence.py','--bin',B,'--evidence',package/'evidence.json']))
jobs += [
 ('tutorial-observation-20261116',[K/'MEF-tutorial-observation-20261116/verify_evidence.py','--bin',B,'--event',E,'--table',T]),
 ('one-shot-study-20261116',[PARSER,'--bin',B,'--event',E]),
 ('one-shot-callbacks-20261116',[REST/'MEF-one-shot-callbacks-20261116/verify_evidence.py','--bin',B,'--event',E]),
 ('A-minimal-spec-20261116',[K/'MEF-A-minimal-spec-20261116/verify_evidence.py','--bin',B,'--event',E,'--prior',PARSER.parent]),
 ('full-surface-native-continuation-20261116',[K/'MEF-full-surface-native-continuation-20261116/audit.py','--bin',B,'--event',E,'--prior-parser',PARSER]),
 ('feature-lifecycle-20261117',[K/'MEF-feature-lifecycle-20261117/verify_evidence.py','--bin',B,'--event',E,'--prior-parser',PARSER,'--previous',K/'MEF-full-surface-native-continuation-20261116','--check-manifest']),
 ('world-identity-scene-interaction-20261117',[K/'MEF-world-identity-scene-interaction-20261117/verify_evidence.py','--bin',B,'--table-stp',T,'--event-stp',E,'--boundmap-stp',M]),
 ('transition-actor-event-20261117',[K/'MEF-transition-actor-event-20261117/verify_evidence.py','--bin',B,'--table-stp',T,'--event-stp',E,'--bound-stp',M]),
]
with ThreadPoolExecutor(max_workers=3) as pool:
    rows=list(pool.map(run,jobs))
(ROOT/'later-runs.json').write_text(json.dumps(rows,ensure_ascii=False,indent=2)+'\n')
