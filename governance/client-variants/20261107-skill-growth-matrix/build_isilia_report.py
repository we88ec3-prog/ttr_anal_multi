"""Summarize all27 Isilia active IDs without bridging level axes."""
from pathlib import Path
import json,re
D=Path(__file__).parent;x=json.loads((D/'isilia-27.json').read_text(encoding='utf-8-sig'));lines=['# Isilia27技能成長證據','', '一般技能等級、Talent scriptLevel、motion/effect資源變體為三個獨立軸。下表未宣稱它們一對一對應。台版文字只約束預期表現，不直接當韓版執行數值。','', '| active / 技能 | 一般技能數值等級 | Talent → scriptLevel | 已有資源變體 | Talent台版表現說明 |','|---|---|---|---|---|'];rules=[]
for r in x['rows']:
 ps=r['ordinarySkillLevels'];name=ps[0]['nameTc'];ordinary=[]
 for p in ps:
  lev=[l['learnedLevel'] for l in p['levels']]
  fields=', '.join(p['changedNumericFields']) or '未見變化'
  ordinary.append(f'P{p["practice"]}: L{min(lev)}..{max(lev)}; {fields}')
 ts={}
 for t in r['talentScriptLevels']:ts.setdefault(t['talentPractice'],[]).append(f'{t["talentLearnedLevel"]}→{t["scriptLevel"]}')
 talent='; '.join(f'T{k}: '+','.join(v) for k,v in ts.items()) or '無直接SkillScriptLevel modifier'
 variants=sorted({v for m in r['motionEffectCandidates'] for e in m['effects'] for v in e['variantTags']})
 desc=sorted({d['textExcerpt'] for t in r['talentScriptLevels'] for d in t['descriptions'] if d['language']=='tc'})
 lines.append('|'+ '|'.join([f'{r["active"]} / {name}','<br>'.join(ordinary),talent,','.join(variants) or 'UNRESOLVED exact join','<br>'.join(desc) or '—'])+'|')
 for t in r['talentScriptLevels']:
  for d in t['descriptions']:
   if d['language']!='tc':continue
   text=d['textExcerpt'];parsed=[]
   patterns=[('projectile_count',r'發射次數增加為\s*(\d+)','count'),('target_count',r'目標數增加為\s*(\d+)','count'),('cooldown_reduction',r'冷卻時間減少\s*(\d+)秒','seconds'),('duration_increase',r'持續時間增加\s*(\d+)秒','seconds')]
   for kind,pat,unit in patterns:
    if m:=re.search(pat,text):parsed.append({'kind':kind,'value':int(m[1]),'unit':unit})
   if parsed:rules.append({'role':4,'active':r['active'],'talentPractice':t['talentPractice'],'talentLearnedLevel':t['talentLearnedLevel'],'scriptLevel':t['scriptLevel'],'rules':parsed,'textExcerpt':text,'textSha256':d['textSha256'],'source':'TAIWAN Table/PracticeExplainTable.xml','authority':'EXPLICIT_REGIONAL_DESCRIPTION_ONLY_NOT_NATIVE_PARAMETER','runtimeVariant':'UNRESOLVED'})
(D/'ISILIA-27.md').write_bytes(('\n'.join(lines)+'\n').encode('utf-8'))
(D/'isilia-explicit-text-rules.json').write_bytes((json.dumps({'schema':'tartaros-isilia-description-rules-v1','rows':rules,'limitations':['Only exact matched Chinese wording is structured. Numeric tokens elsewhere are not auto-assigned a mechanic.','TC regional description has not been proven equivalent to KR runtime parameters or resource variant dispatch.']},ensure_ascii=False,indent=2)+'\n').encode('utf-8'))
print('isilia explicit descriptive rule rows',len(rules))
