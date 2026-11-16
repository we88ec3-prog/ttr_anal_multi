"""Private sequence projection -> public numeric model metadata only."""
from pathlib import Path
import json,hashlib
R=Path(r'E:\Tartaros\workspace');D=Path(__file__).parent;P=R/'CLIENT/evidence/20261107-alsmeer-mainline/scenes/scene-cue-projection.json'
raw=P.read_bytes();x=json.loads(raw.decode('utf-8-sig'));rows=[]
for s in x['scenes']:
 rows.append({'questId':s['questId'],'scene':s['scene'],'member':s['member'],'sequenceSha256':s['sha256'],'createdObjectModelIds':sorted({int(c['argsRaw'].split(',')[1]) for c in s['calls'] if c['function']=='CreateObject'}),'authority':'EXACT_CREATEOBJECT_ARGUMENT_IDS_NOT_MONSTER_ADMISSION'})
(D/'scene-created-models.json').write_bytes((json.dumps({'schema':'ALSMEER_SCENE_CREATED_MODEL_IDS_V1','privateProjectionSha256':hashlib.sha256(raw).hexdigest(),'rows':rows,'limitations':['Numeric model IDs only; no calls, sequence bodies or coordinates exported.','Creation in a presentation scene is not battle monster admission.']},indent=2)+'\n').encode())
print('derived model metadata scenes',len(rows))
