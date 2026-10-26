import pathlib,json,hashlib,xml.etree.ElementTree as ET,platform
OUT=pathlib.Path(__file__).resolve().parent;ROOT=OUT.parents[1];EV=OUT/'evidence'
def load(p):return json.loads(p.read_text(encoding='utf-8'))
def digest(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def dump(p,v):p.write_text(json.dumps(v,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
r=load(EV/'town-resource-audit.json')
types=[dict(x.attrib) for x in ET.parse(EV/'_TownTypeList.xml').getroot()]
world=[{'town_id':x.get('ID'),'info':dict(x.find('INFO').attrib)} for x in ET.parse(EV/'TownWorldListTable.xml').getroot()]
matrix=[]
for m in r['town_named_maps']:
    matrix.append({'map_id':int(m['ID']),'map':m['MAP'],'bound':m['BOUND'],'trigger':m['TRIGGER'],
      'fld':[x for x in m['resource_name_candidates']['MAP'] if x['member'].lower().endswith('.fld')],
      'mre':[x for x in m['resource_name_candidates']['MAP'] if x['member'].lower().endswith('.mre')],
      'bnd':[x for x in m['resource_name_candidates']['BOUND'] if x['member'].lower().endswith('.bnd')],
      'classification':'filename-selected candidate, not town transition eligibility'})
source=[]
for name,ranges in [('login_protocol.py',[(107,114),(128,149)]),('plaza_npcs.py',[(1,5),(17,25),(31,38),(67,71)]),('login_test_server.py',[(479,488)])]:
    p=ROOT.parent/'anal'/name;lines=p.read_text(encoding='utf-8').splitlines()
    source.append({'path':'anal/'+name,'sha256':digest(p),'ranges':[{'start':a,'end':b,'lines':lines[a-1:b]} for a,b in ranges]})
dump(EV/'ai-fixture-review.json',{'status':'待整合','tool':'build_review.py v1 / Python '+platform.python_version(),'sources':source,'observed':['plaza_map_response emits S2C 0x12 with constant map ID 511','plaza_entry_responses emits scene 7 with location bytes 1,1, marked experimental','PlazaNPCs.context emits 0x38/type0/town5','NPC and player XY coordinates are synthesized by the local implementation'],'inference':['Existing local server is not a generic all-town switching implementation'],'limits':['Source inspection only; no packets sent','Native claims in comments are not independently accepted here','T05 scene handoff / T07 controller reset / T04 actor fields are dependencies']})
dump(EV/'town-switch-review.json',{'status':'待整合','source_sha256':r['source']['sha256'],'module':'Table.stp + Map archives','tool':'build_review.py v1 / Python '+platform.python_version(),'evidence':['town-resource-audit.json','town-related-members.json','ai-fixture-review.json'], 'observations':{'townlist_count':len(r['towns']),'towntype_count':len(types),'townworld_count':len(world),'town_types':types,'world_entries':world,'resource_candidates':matrix},'accepted_scope':'Only present resource rows and index membership; no official town->map mapping or playability claim','limits':['Archive/client exact original build pairing unresolved','TownType/TownList/World table scopes differ; cannot use one table as complete destination roster','Do not use Town ID as Map ID','World bindno values are UI data until native consumer checked','_PortalList defines effect files, not a destination or spawn coordinate table','Index match does not validate FLD dependencies, collision semantics, height or safe spawn']})
with (OUT/'findings.jsonl').open('a',encoding='utf-8') as f:
    for ident,kind,evidence,finding in [('R02','observed-resource-data','town-switch-review.json','Recursive 40-archive index confirms exact FLD/MRE/BND member candidates for each selected map. Previous top-level basename probe was incomplete, not model absence.'),('R03','observed-source','ai-fixture-review.json','Local plaza map selector is fixed to 511; Town5 context and synthetic NPC/player XY are separate fixture choices; cannot generalize to native all-town switching.')]:
        f.write(json.dumps({'id':'T06-roy-'+ident,'integration_status':'pending','kind':kind,'source_sha256':r['source']['sha256'] if ident=='R02' else [s['sha256'] for s in source],'module':'Table.stp/Map' if ident=='R02' else 'anal local Python fixture','range':'exact member/block and source line ranges in linked record','tool':'Python '+platform.python_version(),'evidence':'evidence/'+evidence,'finding':finding,'conditions':['Offline current source snapshot only'],'limits':['No target execution or playability acceptance','Native and resource original build pairing unresolved']},ensure_ascii=False)+'\n')
dump(OUT/'changes.json',{'administrative_changes':['roy registered on T06 and 4F5640/4F7DF0/4DF510; JSON/SQLite updated'],'integrated':[],'pending':['R01','R02','R03'],'conflicts':['TownList incomplete relative to TownTypeList; no automatic ID/name join','Original resource/client build pairing unknown'],'formal_acceptance':'pending review'})
(OUT/'unknowns.md').write_text('''# KR T06 — 待整合缺口

- Town→Map：Town ID 1 對照 Map ID 1 為森林，不可直接相等。需查原生接收欄位及 Town lookup consumer；TownType/World 只作來源。
- 程式／資源 build：Table.stp 目前 SHA 已保存，但本機歷史有修改；不能宣稱它是原版 SHA 的正式配套。
- 場景與控制器：依賴 T05/T07 的 0012/0038/0069、清除舊場景及控制綁定順序；不複製主責結論。
- 可落地位置：目前900/900及NPC格點是本機fixture；必須有碰撞／高度及合法出生點原生依據，否則只能標為待開發相容策略。
- 切換許可／回應：官方目的地選擇、解鎖、失敗回應、回城流程與保存規則未證；列後端依賴，不自行補值。
- FLD/MRE/BND：索引存在不等於內容完整或可載入。需檢查 loader 路徑拼接、大小寫規則、依賴與資源版本。
- MEF：不因MapList有檔名就假設客戶端有執行器；本輪不展開波次／怪物AI。
''',encoding='utf-8')
p=load(OUT/'progress.json');p['completed']+=['40 archive resource index audit saved','TownType/World/Portal resource scope captured','Local AI plaza fixture source lines and hashes saved'];p['pending']=['REA long native query','native Town->Map source','accepted bounded integration','T05/T07 dependency handoff'];p['active_tool']='stdio REA town-session-status.json';dump(OUT/'progress.json',p)
print(json.dumps({'matrix_rows':len(matrix),'types':len(types),'world':len(world),'missing_fld':[m['map_id'] for m in matrix if not m['fld']],'missing_bnd':[m['map_id'] for m in matrix if not m['bnd']]}))
