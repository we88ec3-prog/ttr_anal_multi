#!/usr/bin/env python3
"""W1 BATCH03: read-only Event.stp dialogue-key audit.
Usage: python -B W1-RESULT-BATCH03-VERIFY.py /path/Event.stp
Does not execute the Client, decode EX XML, or prove quest settlement.
"""
import hashlib, json, re, struct, sys
from collections import defaultdict
from pathlib import Path

here=Path(__file__).resolve().parent
p=Path(sys.argv[1] if len(sys.argv)>1 else '/mnt/data/Event.stp')
raw=p.read_bytes()
assert hashlib.sha256(raw).hexdigest()=='2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b'
b=bytes(x^255 for x in raw)
stpi=struct.unpack_from('<I',b,4)[0]
assert raw[:4]==b'STPD' and raw[stpi:stpi+4]==b'STPI'
records=struct.unpack_from('<I',b,stpi-32)[0]+1
base=stpi-records*32
j2=json.loads((here/'W1-RESULT-BATCH02-EVENT-SCENE-MATRIX.json').read_text())
j3=json.loads((here/'W1-RESULT-BATCH03-DIALOGUE-KEYS.json').read_text())
from_source=defaultdict(list)
for row in j2['scenes']:
    fid=row['stpd_record_id']
    rec=b[base+32*fid:base+32*(fid+1)]
    id,n,first,last=struct.unpack_from('<4I',rec)
    assert id==fid and n>0
    data=b[first*1024+16:first*1024+16+n]
    assert hashlib.md5(data).hexdigest()==row['md5']==rec[16:32].hex()
    txt=data.decode('euc-kr')
    h=re.search(r'--\s*Quest\s*#\s*(\d+)\s*/\s*Scene\s*#\s*(\d+)\s*-\s*Function\s*([^\r\n]+)',txt)
    assert h and (int(h[1]),int(h[2]),h[3].strip())==(row['quest_id'],row['scene_id'],row['function'])
    assert re.search(r'\bRegister\(\s*'+re.escape(row['function'])+r'\s*\)',txt)
    keys=[[int(a),int(c)] for a,c in re.findall(r'\bOpenTalkScene\(\s*(\d+)\s*,\s*(\d+)\s*\)',txt)]
    prologs=[int(v) for v in re.findall(r'\bDoProlog\(\s*(\d+)\s*\)',txt)]
    from_source[row['quest_id']].append((row['scene_id'],keys,prologs))
assert len(j2['scenes'])==35 and len(from_source)==12
count=0
for row in j3['quests']:
    entries=sorted(from_source[row['quest_id']])
    assert [s for s,keys,pros in entries]==row['author_scene_ids']
    got=[v for s,keys,pros in entries for v in keys]
    prologs=[v for s,keys,pros in entries for v in pros]
    assert got==row['dialogue_keys_source_order'],row['quest_id']
    assert prologs==row['do_prolog_args'],row['quest_id']
    count+=len(got)
assert count==118
print('PASS: Event.stp SHA, 35 plaintext .seq MD5 and headers, 118 dialogue keys, DoProlog(1/2)')
print('LIMITS: dialogue-group is not proven Chapter ID; no Quest settlement, wire or rewards proven')
