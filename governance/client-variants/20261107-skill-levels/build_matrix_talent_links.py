"""Bounded read-only projection of original matrix data, not a matrix setter."""
from pathlib import Path
import sys,json,hashlib,xml.etree.ElementTree as ET,collections
R=Path(r'E:\Tartaros\workspace'); OUT=Path(__file__).parent
sys.path.insert(0,str(R/'anal'));from stp_resources import Archive
a,w=Archive(R.parent/'origin/Table.stp'),Archive(R/'Table.stp')
catalog=json.loads((R/'runtime-observations/2026-11-05-all-skills/all-skills-catalog.json').read_text(encoding='utf-8-sig'))
manifest={}; sha=lambda b:hashlib.sha256(b).hexdigest()
def read(member):
    b,c=a.read(member),w.read(member);assert b==c
    if member in catalog['members']:assert sha(b)==catalog['members'][member]['original_sha256']
    manifest[member]={'member':member,'original_sha256':sha(b),'working_sha256':sha(c),'matched':True}
    return ET.fromstring(b)
def node(n):return {'tag':n.tag,'attributes':dict(n.attrib),'children':[node(x) for x in n]}
practices={p['id']:p for p in catalog['practices']}; root=read('Table/Skill/Matrix/CharacterMatrices.xml')
rows=[];talents={};counts=[]
for char in root:
    role=int(char.get('CharID'));allskills=set();base={}
    for matrix in char.findall('Matrix'):
        mid=int(matrix.get('ID'));builtin=[];keys=[]
        for p in matrix.findall('BuiltinPracticeList/Practice'):
            pid,level=int(p.get('PracticeID')),int(p.get('Level'));entry=practices[pid]
            assert entry['role']==role and entry['category']=='Talent'
            if pid not in talents:
                pr=read(entry['source']).find('Practice')
                talents[pid]={'role':role,'practice':pid,'source':entry['source'],'levels':[node(l) for l in pr.findall('LevelData')]}
            assert level in [int(l['attributes']['Level']) for l in talents[pid]['levels']]
            builtin.append({'practice':pid,'level':level,'source':entry['source']})
        for tier in matrix.findall('KeyInfo/Tier'):
            tid=int(tier.get('tier'))
            for k in tier:
                key,active=int(k.get('key')),int(k.get('skill'))
                if mid==0:base[(tid,key)]=active
                keys.append({'tier':tid,'column':key,'active':active,'changedFromMatrix0':base.get((tid,key))!=active})
                if 1<=key<=6:allskills.add(active)
        rows.append({'role':role,'matrix':mid,'requirements':[dict(x.attrib) for x in matrix.findall('Requirements/Require')],'builtinPractices':builtin,'keys':keys})
    counts.append({'role':role,'matrix0SixKeySlots':sum(1 for k in rows[-7]['keys'] if 1<=k['column']<=6),'uniqueSixKeyActivesAllMatrices':len(allskills)})
def save(name,obj):(OUT/name).write_bytes((json.dumps(obj,ensure_ascii=False,indent=2)+'\n').encode('utf-8'))
save('matrix-talent-links.json',{'schema':'tartaros-matrix-talent-links-v1','rows':rows,'roleCounts':counts,'builtinTalentDefinitions':list(talents.values()),'authority':'EXACT_RESOURCE_MATRIX_TO_BUILTIN_DECLARATION','limitations':['Matrix builtin declaration is not proof that learning a Talent changes matrix.','Matrix selection native/packet setter remains unproven in this projection.','Key skill is active skill ID, not Practice ID or motion.','No animation variant dispatch inferred.']})
save('matrix-source-members.json',list(manifest.values()))
print(json.dumps({'matrixRows':len(rows),'builtinTalentPractices':len(talents),'sourceMembers':len(manifest),'roleCounts':counts}))
