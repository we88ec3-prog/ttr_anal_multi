"""Read-only KR resource inventory -> proposed functional Server work breakdown.
No native protocol claims, Client execution or original asset mutation.
"""
import argparse,hashlib,json,struct,zlib,xml.etree.ElementTree as ET
from pathlib import Path

TABLE='09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442'
FIELD='18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a'
def archive(path,sha):
 raw=path.read_bytes();assert hashlib.sha256(raw).hexdigest()==sha and raw[:4]==b'STPD'
 data=bytes(v^255 for v in raw);pos=struct.unpack_from('<I',data,4)[0]+8;files={}
 def node(parent,depth=0):
  nonlocal pos
  assert depth<64
  n=struct.unpack_from('<H',data,pos)[0];pos+=2;name=data[pos:pos+n].decode('ascii').rstrip('\0');pos+=n
  kind=data[pos];pos+=1;name='/'.join(filter(None,[parent,name]))
  if kind in (1,2):
   count=struct.unpack_from('<I',data,pos)[0];pos+=12
   for _ in range(count):node(name,depth+1)
  else:
   assert kind==0
   _,ident=struct.unpack_from('<II',data,pos);pos+=16;files[name]=ident
 node('');assert pos==len(data)
 off=struct.unpack_from('>I',data,12)[0];count=struct.unpack_from('<I',data,off)[0];blocks={}
 for i in range(count):
  ident,size,first,last=struct.unpack_from('<4I',data,off+4+i*32);assert size<=(last-first+1)*1024
  blocks[ident]=data[16+first*1024:16+first*1024+size]
 return {n:blocks[k] for n,k in files.items()}
def expand(raw):
 if raw[:2]!=b'EX':return raw
 mode=raw[2];n,size,off=struct.unpack_from('<III',raw,4);assert size<=8000000
 b=raw[off:off+n]
 if mode:
  key=[0x30,0xe7]
  for i in range(2,1024):key.append((key[i-2]+key[i-1]+0x13-(0x56 if i==0x17c else 0))&255)
  b=bytes(v^key[i%1024] for i,v in enumerate(b))
 b=zlib.decompress(b);assert len(b)==size;return b
def parse(b):
 for enc in ['utf-8-sig','euc-kr']:
  try:return ET.fromstring(b.decode(enc))
  except (UnicodeError,ET.ParseError):pass
 raise ValueError('Unsupported resource XML')
def main():
 p=argparse.ArgumentParser();p.add_argument('--table',type=Path,required=True);p.add_argument('--field',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
 assert not a.output.exists(),'Never overwrite an existing progress plan.'
 tab=archive(a.table,TABLE);field=archive(a.field,FIELD);sources={};errors=[]
 def xml(name,container=tab):
  raw=expand(container[name]);sources[name]=hashlib.sha256(raw).hexdigest();return parse(raw)
 town=xml('Table/_TownTypeList.xml');chap=xml('Table/SceneList.xml');quest=xml('Table/QuestInfo.xml')
 cases=xml('Table/_CaseList.xml');actors=xml('Table/_ActorList.xml');skills=xml('Table/CharSkill.xml')
 skill_tables=[xml('Table/'+n) for n in ['SkillActiveTable.xml','SkillPassiveTable.xml','SkillSupportTable.xml']]
 qmap={q.get('id'):q for q in quest};actor_map={(e.get('ID'),e.get('PRE')):e.attrib for c in actors if c.get('ID')=='1' for e in c}
 role_map={e.get('ID'):e.attrib for c in actors if c.get('ID')=='0' for e in c}
 features=[]
 def steps(names,known=False,open_note='待分析、實作及正流程驗收；資源存在不等於完成。'):
  out=[{'name':n,'kind':'開發','dev':'待分析','test':'未測','next':open_note} for n in names]
  if known:
   for e in out:e.update(dev='已實作',test='合成通過',next='指定工作副本正常路徑已有證據；其他入口不擴張認定。')
  out += [{'name':'指定工作副本正常流程驗收','kind':'工作副本人測','dev':'不列分母','test':'通過' if known else '未測','next':'有界工作副本結果，非未修改原版驗收。'},
          {'name':'未修改原版 Client 相容性驗收','kind':'原版驗收','dev':'不列分母','test':'未測','next':'未驗收；與修改工作副本、合成結果分開。'}]
  return out
 def item(ident,title,names,known=False,meta=None,note=''):
  return {'id':ident,'title':title,'meta':meta or {},'note':note,'steps':steps(names,known)}
 def feature(ident,title,category,items,priority='後續',scope='開發規劃；不是原版 Server 規格。'):
  f={'id':ident,'title':title,'category':category,'priority':priority,'scope':scope,'file':ident+'_'+title+'.xlsx','items':items}
  features.append(f);return f
 def generic(code,title,subs,category='共用系統',priority='後續',resource='使用者需求／S00功能分解'):
  items=[]
  for i,n in enumerate(subs.split('／'),1):
   items.append(item(code+f'-{i:02}',n,['資料與前置條件','請求／事件與權威規則','狀態變更與保存','回覆／畫面更新','正常流程整合測試'],meta={'來源':resource}))
  return feature(code,title,category,items,priority)
 generic('SYS01','帳號與登入','建立帳號／帳號驗證／登入成功回覆／Session與連線交接／登出','登入與世界','目前')
 generic('SYS02','選服與頻道切換','伺服器清單／分流清單／選服連接／頻道切換／角色與隊伍跨頻限制','登入與世界')
 generic('SYS03','冒險團與角色','冒險團命名／初始隊員／角色招募／角色切換／編隊與候補／角色等級與能力／冒險團成長','角色與養成')
 tutorial=[('全新帳號登入',True),('冒險團命名',True),('創帳號後劇情與序章對照',False),('初次進入遊戲劇情',True),('方向鍵移動與第一個T標記',True),('滑鼠移動說明劇情',True),('視角操作說明劇情',True),('Tab切換角色教學',True),('伊莉西亞顯示與編隊',True),('教學首戰進場與勝利返回',True),('首戰後招募接續',True),('蘋果房屋劇情與招募',True),('蘋果後續對話到廣場',True),('廣場人物NPC與移動停止',True),('教學任務結算獎勵與終態保存',False),('載入與轉場畫面確認',False),('未對應的序章場景分支盤點',False)]
 feature('TUT','新手任務主線','主線與內容',[item('TUT-'+f'{i:02}',n,['流程前置與入口','事件／封包處理','角色／場景初始化','結束接續與控制恢復','正流程Server測試'],k,{'來源':'既有教學人測及26個合成案例' if k else '使用者需求／SceneList chapter0待核對'},'首戰勝利流程通過，不表示連擊、受擊手感或MEF已通過。' if i==10 else '') for i,(n,k) in enumerate(tutorial,1)],'目前')
 generic('SYS04','廣場進入與互動','廣場進場／玩家與NPC生成／NPC互動區域／主線NPC互動／廣場控制恢復／廣場返回入口','登入與世界','目前')
 generic('SYS05','村莊切換與場景','城鎮入口／村莊切換／出生位置與碰撞／載入畫面／場景就緒交握／玩家NPC與控制初始化／跨村進度保存','登入與世界','目前')
 generic('SYS06','組隊與多人副本','邀請與接受／隊長與隊員／隊伍顯示／編隊同步／入場資格／全隊換場／隊伍戰鬥同步／戰利品分配／離隊與解散','社交與多人')
 generic('SYS07','副本戰鬥共用','關卡選擇／編隊設定／進場交握／玩家移動／普攻與連段／輸入佇列消費／技能施放／移動後攻擊／傷害命中／受擊硬直與冷卻／Buff與控制效果／死亡與復活／勝敗判定／結算獎勵／返回村莊','戰鬥','目前')
 generic('SYS08','怪物行動基礎','生成觸發／MEF格式與接收路徑研究／AI狀態與仇恨／追擊與尋路／警戒與返回／攻擊前搖與命中／攻擊積極性與冷卻／技能與階段轉換／受擊死亡與掉落／怪物同步與移除','戰鬥','目前')
 generic('SYS09','物品背包與掉落','物品實例與序號／背包欄位／取得與堆疊／消耗品使用／任務道具／掉落拾取／丟棄與刪除／背包擴充／物品保存','角色與養成',resource='ItemTable2.xml／ItemUsableTable.xml／InventoryExpandInfo.xml')
 generic('SYS10','裝備與能力','裝備資格／穿脫裝備／裝備能力計算／套裝效果／強化／精煉與隨機能力／裝備升級／外觀與染髮','角色與養成',resource='ItemSet.xml／ItemEnchant.xml／ItemLevelupInfoSet.xml／HairInfo.xml')
 generic('SYS11','倉庫與交易','倉庫開啟／存入取出／倉庫欄位與擴充／角色與冒險團倉庫邊界／玩家交易／交易確認與保存／交易板掛單與領取','經濟與物品',resource='使用者明確需求；TradeBoard.xml提供交易板資源線索，倉庫欄位另待分析')
 generic('SYS12','商店製作與貨幣','NPC商店購買／NPC商店出售／價格與貨幣帳本／製作配方／材料消耗／合成與鑑定／兌換與特殊貨幣／獎勵發放保存','經濟與物品',resource='ShopInfo.xml／Product.xml／ItemCompound.xml／UnidentifiedProduct.xml')
 generic('SYS13','一般任務共用','任務分類與解鎖／接取與放棄／擊殺目標／收集目標／對話與到達目標／提交與獎勵／每日或重複條件／每村支線內容盤點／任務保存與通知','主線與內容','後續',resource='QuestInfo.xml；目標類型與重複規則仍須驗證')
 generic('SYS14','劇情動畫共用','NPC對話／劇情資源索引／場景啟動／鏡頭與動畫／段落結束與接續／角色與控制恢復／分支與跳過規則／劇情進度保存','主線與內容','目前')
 generic('SYS15','聊天好友與社交','一般與隊伍聊天／私訊／頻道與廣播／好友清單／加入刪除好友／黑名單／社交動作','社交與多人')
 generic('SYS16','公會','建立與加入／成員與職位／公會聊天／公會成長聲望／公會裝飾／公會訓練場／公會資料保存','社交與多人',resource='GuildInfo.xml／GuildReputation.xml／GuildDecorationData.xml')
 generic('SYS17','挑戰與特殊副本','挑戰清單／Raid副本／每日副本／挑戰塔／無限副本／特殊增益與獎勵／各模式入退場與保存','特殊玩法',resource='ChallengeListTable.xml／RaidInfoTable.xml／DailyDungeonInfoTable.xml／ChallengeTowerData.xml／InfiniteDungeonBuffTable.xml')
 generic('SYS18','對戰與排名','對戰入口／隊伍與配對條件／對戰場景／勝敗與積分／隊伍排名／結算保存','特殊玩法',resource='Town TYPE5／TeamRank.xml；實際配對模式待確認')
 generic('SYS19','稱號收藏與外觀','稱號取得與裝備／劇情圖鑑與收藏／外觀服飾／外觀合成回收／契約與特殊養成／商城目錄與權益','角色與養成',resource='TitleInfo.xml／ScenarioBookContents.xml／AvatarRecycleTable.xml／RareAvatarComposeData.xml／ContractList.xml／CashProduct.xml')
 generic('SYS20','資料保存與營運','帳號角色任務保存／獎勵與物品一致性／日誌與診斷／本機管理後台／資料庫版本管理／備份與還原／權限與稽核／安全與負載／部署與版本切換','Server營運',resource='Server roadmap／SFD；非正流程測試仍依使用者要求暫緩')
 # Include known successful login/name slices without claiming every variant.
 for fid,ordinal in [('SYS01',2),('SYS01',3),('SYS01',4),('SYS02',3),('SYS03',1),('SYS04',1)]:
  f=next(x for x in features if x['id']==fid);it=f['items'][ordinal-1]
  for s in it['steps']:
   if s['kind']=='開發':s.update(dev='已實作',test='合成通過',next='目前指定工作副本正常路徑；其他變體不擴張認定。')
   elif s['kind']=='工作副本人測':s['test']='通過'
 # Per-region files. Chapter membership defines story inventory, not legal order.
 for order,t in enumerate([e for e in town if e.get('TYPE')=='1'],1):
  tid=t.get('ID');townchap=[c for c in chap if c.get('townId')==tid]
  qids=list(dict.fromkeys(s.get('questId') for c in townchap for s in c));label=f'第{order:02}村'+('馮德斯' if tid=='1' else f'Town{tid}')
  story=[]
  for ordinal,qid in enumerate(qids,1):
   q=qmap.get(qid);sc=list(dict.fromkeys(e.get('sceneIdx') for c in townchap for s in c if s.get('questId')==qid for e in s))
   title=(q.get('subject','') if q is not None else '') or '名稱待確認'
   names=['前置任務與解鎖條件','任務接取與NPC回覆']
   for n in sc:names += [f'場景{n}啟動與播放',f'場景{n}結束接續與控制恢復']
   names += ['任務目標與必要戰鬥接續','任務結束與交付','獎勵發放與保存','下一任務／換場銜接','正流程Server測試']
   meta={'QuestID':qid,'TownID':tid,'清單順序':ordinal,'章節ID':[c.get('chapterIdx') for c in townchap if any(s.get('questId')==qid for s in c)],'SceneID':sc,'原始名稱':title,'前置任務':[e.get('id') for e in q.findall('./Demands/Demand')] if q is not None else [],'任務自身Town':q.get('town') if q is not None else None,'FieldID':q.get('field') if q is not None else None}
   story.append(item(f'STORY-T{tid}-Q{qid}',f'任務第{ordinal}個｜Quest{qid}'+(' 前往馮德斯村' if qid=='15' else ''),names,meta=meta,note='資源清單順序非已證明遊玩順序；接取／結束條件仍需核對。'))
  if not story:story=[item(f'STORY-T{tid}-SCOPE','主線內容盤點',['核對章節與任務歸屬','補齊主線任務清單'])]
  feature(f'ST{order:02}',label+'主線','村落主線',story,'目前' if tid=='1' else '後續',f'Town{tid}，原名{t.get("NAME")}；依SceneList章節列主線，不將全部Town任務算主線。')
  allq=[q for q in quest if q.get('town')==tid or q.get('id') in qids]
  fieldids=sorted(set(q.get('field') for q in allq if q.get('field') and q.get('field')!='0'),key=int)
  dungeon=[];monsters={}
  for fieldid in fieldids:
   cs=[c for c in cases if c.get('STAGE')==fieldid];models=set();maps=set();refs=[]
   for c in cs:
    for key,sub in [('MAPFLOW','MapFlow'),('CLUSTER','Cluster')]:
     member='Field/'+sub+'/'+c.get(key,'');refs.append(member)
     if member not in field:errors.append({'member':member,'reason':'missing exact member'});continue
     try:root=xml(member,field)
     except (ValueError,KeyError,ET.ParseError) as ex:errors.append({'member':member,'reason':type(ex).__name__});continue
     if key=='MAPFLOW':maps.update(e.get('id') for e in root.iter() if e.tag.lower()=='map' and e.get('id'))
     else:
      for e in root.iter('OBJECT'):
       pair=(e.get('ID'),e.get('PRE'))
       if pair in actor_map:models.add(pair)
   for pair in models:monsters.setdefault(pair,set()).add(fieldid)
   dungeon.append(item(f'DUN-T{tid}-F{fieldid}',f'Field{fieldid} 副本內容',['所屬村落與開放條件核對','選關編隊與入場','場景地圖與碰撞','生怪觸發與關卡流程','關卡目標／Boss條件','勝敗結算與返回','獎勵與任務整合','正流程Server測試'],meta={'TownID':tid,'FieldID':fieldid,'CaseID':[c.get('ID') for c in cs],'MapID':sorted(maps,key=int),'候選怪物數':len(models),'資源':refs},note='由Quest.field與Case.STAGE同值建立內容候選；非已驗收副本歸屬／完整波次。'))
  if not dungeon:dungeon=[item(f'DUN-T{tid}-SCOPE','副本內容歸屬盤點',['盤點Field／Case／Map','補齊副本清單與正常路線'])]
  feature(f'DG{order:02}',label+'副本內容','村落副本',dungeon,'目前' if tid=='1' else '後續',f'目前Quest.field引用範圍；未保證包含所有獨立／活動副本。')
  mon=[]
  for pair,fs in sorted(monsters.items(),key=lambda v:(int(v[0][0]),int(v[0][1] or 0))):
   ar=actor_map[pair]
   mon.append(item(f'MON-T{tid}-{pair[0]}-P{pair[1]}',f'{pair[0]}｜{ar.get("NAME","")}', ['出場關卡與模型確認','生成條件與位置','能力與攻擊參數','AI與技能設定','傷害受擊死亡與掉落','關卡目標與同步整合','正流程Server測試'],meta={'TownID':tid,'ActorID':pair[0],'PRE':pair[1],'FieldID':sorted(fs,key=int),'原始名稱':ar.get('NAME'),'Actor分類':'1'},note='Cluster出現的Actor分類1候選；不證明全部敵人／波次或官方AI。'))
  if not mon:mon=[item(f'MON-T{tid}-SCOPE','怪物清單待補證',['核對Cluster／MEF與怪物歸屬','補齊怪物與Boss清單'])]
  feature(f'MO{order:02}',label+'怪物','村落怪物',mon,'後續','來源為目前副本候選Cluster引用；範圍不等於原版全怪物。')
 # Each character skill gets its own detail tab; levels remain metadata, not duplicated features.
 for char in skills:
  rid=char.get('ID');name='索瑪' if rid=='1' else role_map.get(rid,{}).get('NAME','角色'+rid)
  rows=[]
  for group in char:
   for sk in group.findall('SKILL'):
    sid=sk.get('ID');defs=[e for rt in skill_tables for e in rt if e.get('no')==sid]
    nm=next((e.get('name') for e in defs if e.get('name')), '名稱待確認')
    rows.append(item(f'SKILL-R{rid}-S{sid}',f'技能{sid}｜{nm}', ['學習解鎖與升級條件','技能欄與使用資格','消耗／冷卻／輸入佇列','施放動作與取消規則','目標命中與效果','同步與角色保存','正流程Server測試'],meta={'RoleID':rid,'SkillID':sid,'GroupID':group.get('ID'),'原始名稱':nm,'來源層級數':[len(e.findall('LEVEL')) for e in defs]},note='CharSkill引用清單；角色通用普攻原型不能當此技能完整完成。'))
  feature('SK'+rid.zfill(2),name+'技能','角色技能',rows,'目前' if rid=='1' else '後續','依CharSkill列出全部引用技能；保留韓文原名，未校對名稱不擅自翻譯。')
 overrides_path=Path(__file__).parent.parent/'initial-progress-overrides.json'
 if overrides_path.exists():
  overrides=json.loads(overrides_path.read_text(encoding='utf-8'))['items']
  for f in features:
   for it in f['items']:
    if it['id'] in overrides:it.update(overrides[it['id']])
 for f in features:
  ids=[i['id'] for i in f['items']];assert len(ids)==len(set(ids))
  for i in f['items']:
   for n,s in enumerate(i['steps'],1):s['id']=i['id']+f'-STEP{n:02}'
 result={'schema':'s00-functional-roadmap-v1','recorded_date':'2026-11-02','source_analysis_main':'f104d8083e9cff8408c39bb78af6fb467067b55b','private_implementation_commit':'1473173883b83c7a456e7816470273e81664972a','human_test_server_commit':'cd2a7bc70f3cfb92602628137bf65c5df81b0eb2','resource_carriers':{'Table':TABLE,'Field':FIELD},'resource_members':sources,'resource_errors':errors,'features':features,'limits':['S00 proposed work breakdown, not approved official Server protocol.','Progress is implemented development steps / defined development steps, not effort or native completeness.','Current human pass applies only to explicitly marked working-copy slices; original Client not verified.','Village ordinal is planning order of TYPE1 towns, not TownID.','Chapter membership and candidate Field/monster associations do not prove runtime order or complete content.']}
 a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_bytes((json.dumps(result,ensure_ascii=False,indent=2)+'\n').encode('utf-8'))
 print(json.dumps({'features':len(features),'subfeatures':sum(len(f['items']) for f in features),'steps':sum(len(i['steps']) for f in features for i in f['items']),'story_quests':sum(len(f['items']) for f in features if f['category']=='村落主線'),'resource_errors':len(errors)},ensure_ascii=False))
if __name__=='__main__':main()
