"""R1 serialization of manually read early T10 narratives; no BIN/REA operations."""
from pathlib import Path
import json,hashlib,subprocess
D=Path(__file__).resolve().parent;R=D.parents[3]
I=json.loads((D.parent/'sources.json').read_text(encoding='utf-8'))
ROWS=[s for s in I['sources'] if s['scope']=='early']
TARGET='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
DEC='shared/integrations/T01-20261029-semantic-review/t10/DECISIONS.md'
CONT='shared/integrations/T01-20261029-continuation-02/t10/README.md'
ANCH='shared/integrations/T01-20261029-semantic-review/t10/semantic-anchors.json'
TASK='kr/tasks/T10/README.md'
CONFLICTS={
 'store-address-007':dict(description='T01-RETURN-T10-007-001：5467F1是載入out指標；WORD store在5467F4。主要三路OR與byte優先資料流仍有支持。',refs=[DEC,'shared/integrations/T01-20261029-semantic-review/t10/decisions.json'],disposition='隔離007 L16的store位址，不採該位址作hook／標註。只保留bit映射／三路合流子範圍PARTIAL；舊FAILED不變。',r2_if_needed='需精確機器碼時重用已存546780 CFG與DECISIONS指定反證；本輪不重驗。'),
 'function-owner-026':dict(description='T01-RETURN-T10-026-001：549D54屬獨立549C60根，非549980；前函式正常返回在549A34／549C4E。',refs=[DEC,'shared/integrations/T01-20261029-semantic-review/t10/decisions.json'],disposition='排除026 L137錯誤入口／caller／參數歸屬，保留局部slot=4與相鄰目標狀態作PARTIAL導航；031可作後續版本線索，不改舊FAILED。',r2_if_needed='需SubAI實參／所有權時依549C60精確根與受影響state/caller定向驗證。'),
 'reset-guard-order':dict(description='既有RETURN062／063區分ordinary先清40bytes再可選特殊初始化，且clear6D4CAE沒有reader的ESI<=27 guard。013已有正確guard差異提醒。',refs=[DEC],disposition='本scope保留013及REBASE02的清零/reader區隔；不採中期062／063錯誤順序或把reader guard搬到writer。',r2_if_needed='設計要依clear安全值域/初始化次序時使用既有精確CFG與list producer值域，不補guard。'),
 'historical-xml-gap':dict(description='早稿尚未取得KeyMapping本體是歷史研究狀態；已提交semantic-anchors保存兩份XML原件解析，不能繼續宣稱目前無XML。',refs=[ANCH,'kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt','kr/evidence/6c019693bf60589feb2f3ff6aec651f83ddc0d8103e1358f0ad9c19caf8ac973.txt'],disposition='保留loader／fallback與runtime設定不同的界線；早稿找檔需求僅作版本歷史，不作現行資產缺失或Z不存在的主張。',r2_if_needed='具體action/Key/ModKey規格使用時綁定相應XML SHA與完整loader/event caller。'),
 'historical-phase-gap':dict(description='早稿非零writer未找到、phase1/3未定pressed/released屬當時狀態；來源101新稿提出6D1480及前後frame比較與overlay。',refs=['kr-temp-roy/20261028-1843-chatgpt-web-roy-T10-101-phase-writer-consumption-and-transport.md'],disposition='不輸出現在不存在writer或phase語義永遠未知；把早期negative scan限制保存，後續101由late scope另處理，無品質自動繼承。',r2_if_needed='需要writer/poll/override的正式契約時依101精確版本及consumer時序定向核證。'),
 'combo-window':dict(description='README把CHAIN_WINDOW=.65及Server續段排程列AI替代；547240的500ms與SubAI >60次均不證combo/cancel/V時間。',refs=[TASK,DEC],disposition='所有Z/V/連段段數／取消／Server權威語義保持UNKNOWN；不把使用者操作敘述、時間常數、次數門檻當原生規範。',r2_if_needed='S00有具體戰鬥阻塞再按action row→input→motion completion/queue→Server回覆定向派工。'),
 'receiver-identity':dict(description='相同+3E8、virtual+2C、selector5與input index5不能證明同物件或同索引空間；33..44自己保留這些界限。',refs=['kr-temp-roy/T10/20261027-222750-chatgpt-web-roy-T10-36-indirect-dispatch-receiver-boundaries.md','kr-temp-roy/T10/20261027-223615-chatgpt-web-roy-T10-40-actor-init-versus-input-chain-evidence-matrix.md'],disposition='僅constructor/vptr/slot及局部writer導航；排除玩家V→selector5、factoryinstance==controlleractor的未證等價。',r2_if_needed='需要同一instance時查連續receiver傳遞/註冊/slot來源，不以offset或粗略call掃描替代。'),
 'registration-abi-candidate':dict(description='T10-41 L9將實例/FAB130在EAX與stack角色反寫的敘述，與已提交T08-200及既有4DFF30根圖的owner/actor ABI相反。',refs=['kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-200-registration-identity-and-duplicate.md','shared/integrations/T01-20261029-continuation-02/t08/native-cfg/004dff30.json'],disposition='R1不採T10-41 caller register角色；只保留actor+4 key、missing/duplicate與未證controller identity子集。列既有跨來源衝突待定向R2，不新開作者退回、不改歷史PARTIAL。',r2_if_needed='要精確呼叫約定時比對4AEC03根與4DFF30 owner/stackactor傳遞，勿直接重用原句。'),
 'appendix-boundary':dict(description='既有continuation02說明053/055/056的byte相符不等於錯位窗口頭為native指令；本scope附錄也只能作raw/局部來源而非全函式通過。',refs=[CONT,DEC],disposition='本R1只萃取明列敘述子範圍；不把附錄、E8候選、literal地址當完整CFG證明。',r2_if_needed='有精確位址使用需求時從已知入口重用canonical證據，保留原稿窗口類型。')
}

GROUPS=[
 ('timer','PARTIAL','早稿描述547240以state/tick及FB9014數值取樣、timeGetTime差嚴格大於500時轉換；這是有界時間分支，非combo或V時間規則。','547240/BD25A0正常分支與return碼',['尚未把所有runtime輸入/例外/跳表scope作新R3驗證'],['combo-window']),
 ('input-merge','PARTIAL','來源區分546780的2/3/4→08/80/40 WORD bits、三路回傳OR與byte優先選擇；彼此不是同一語義。','546780/546850/546B50/546D50輸入合流',['007 store位址錯誤必排除','不由mask命名Z或長按'],['store-address-007','combo-window']),
 ('bank-layout','PARTIAL','來源描述FB902C選三個280-byte映射Bank，各含16-byte row及DWORD vector；選Bank/載入設定不等於runtime key phase writer。','6D0750/6D1A70/FB8834/FB8AB4/FB8D34',['合法caller bank值域與完整非法輸入防護不保證','欄位解析/配置來源與玩家當前設定分開'],['historical-xml-gap']),
 ('keymap-loader','PARTIAL','來源把6D08F0與Table/KeyMapping.xml的Type/Key/MapButton/ModKey解析及6D0EB0 fallback分開；fallback常數不能直接當當前玩家Z映射。','6D08F0/6D0EB0/6D1BE0的設定路徑',['原稿未完整簽核schema/所有copy分支','XML已取得之後續來源不倒改早稿歷史'],['historical-xml-gap']),
 ('vector-copy','PARTIAL','來源描述4A8680以來源DWORD地址append-copy並處理擴容/alias；6D0Bxx位於較大XML控制流，不是獨立keydown函式。','4A8680及6D0Bxx資料設定流程',['不是已驗C++原型或完整所有權','不把append值直接命名VK或skill'],[]),
 ('mapping-query','PARTIAL','來源描述6D4DC0依域走普通Bank row或特殊容器、6D43F0可取節點內值且可能插入；不同caller有屬性／顯示用途，不等於鍵盤callback。','6D4DC0/6D43F0/6D1DA0及明列caller',['direct E8清單僅候選，不覆蓋間接caller','不同樹helper/owner不得按offset合併'],[]),
 ('state-reset-read','PARTIAL','來源區分6D4A30的batch/indexed zero與6D4CE0的ordinary/special reader；clear路不能借用reader<=27 guard，也不證keyup事件。','6D4C20/6D4CAE/6D4CE0/FB9004/FDF630',['list ID上游值域未閉合，不宣稱漏洞或任意整數安全','第一支reset時序依既有062反證限定'],['reset-guard-order','historical-phase-gap']),
 ('phase-routing','PARTIAL','來源描述5961C0普通0..39與擴展鍵分流、phase1/3後的EC/F0多態callback及keyed-tree攔截；早稿不辨完整owner。','596140/5961C0/59624E/59643F',['phase語義後續101是另一版本，不把早期未知當現行否定','附錄窗口不代表全caller/callee驗證'],['historical-phase-gap','appendix-boundary']),
 ('command68','PARTIAL','早稿描述548918實際索引28..37，在phase1及FBA798 gate下產生內部WORD68與byte後交virtual sender；不是十段普攻。','548918/548957/548985/FBA854 virtual10',['不將內部命令數字或局部sender自動當完整wire/Server契約','receiver及payload其他欄依來源邊界'],['combo-window','appendix-boundary']),
 ('command22','PARTIAL','來源把FB9015..18四個位址state1觸發參數1..4、50C640的WORD22局部請求及50CAC0 sender交接分開；不解成單Z連擊四段。','54883A..548883/50C640/50CAC0',['Server語義、各位址action mapping及完整transport不在此子集','virtual sender參數不是整TCP frame'],['combo-window']),
 ('direction-synthesis','PARTIAL','來源將546850四byte輸入、二維方向/angle合成、545F30/5464C0方向搜尋和4C90C0的+3A8旗標與攻擊/charge分離。','546850/545F30/5464C0/4C90C0',['浮點/座標單位與所有helper未知','256候選上限不是蓄氣時間或段數'],['combo-window']),
 ('pointer-branches','PARTIAL','來源描述546B50/546D50另有裝置、全域/receiver gate與座標門檻後的byte輸出，不能把三路資料全當Z攻擊。','546B50/546D50/FB1318與各局部gate',['滑鼠/畫面座標仍是暫名','不把controller+80或edge全域命名combo/debounce'],[]),
 ('availability','PARTIAL','來源把546100輸入mask、actor+3E8與54F270可用性predicate分層；predicate失敗但actor狀態非零仍可能允許，非施放/取消/扣除資源成功。','546100/5462DD/54827F/54F270及caller-specific gate',['不同controller/SubAI caller不合成全域combo graph','完整motion/queue/cooldown writer未由此驗收'],['combo-window']),
 ('matrix-tree','PARTIAL','來源描述54F270優先序flags分類及81A8E0的4×11 WORD表；54F4E0可get-or-insert，查entry+4為零不等同冷卻啟動或固定allow-list。','54F270/40F7F0/819220/81A8E0/54F4E0/54F7D0/54F6A0',['三低位同時設依優先序，不新增三鍵技能','4/11、tier及key數字不代表玩家蓄氣/段數'],['combo-window']),
 ('actor-state-read','PARTIAL','來源把actor+3E8作控制器predicate實參及54ADC0相等條件的讀取與其writer分開；不能只依同offset把不同receiver等同。','54ADC0/5462B4/54825D',['未知所有instance/value域','不是V鍵tier writer證據'],['receiver-identity']),
 ('subai-slots','PARTIAL','來源描述SubAI stride16 slot的候選/目標條件與state1/2/3/4及4/5/6 consumer；這不是玩家V線性蓄氣或冷卻階段。','549C60/549D7D/549E10/54A050的局部slot操作',['026錯歸549980的邊界/參數推論排除','目標幾何與完整狀態機/所有writer未閉合'],['function-owner-026','combo-window']),
 ('subai-count','PARTIAL','030描述actor狀態1/2下slot counter遞增且>60時選參數7/9、清counter；更新呼叫次數不是已知秒數或frame-rate。','548FF0/5490FB..549141',['7/9在入口是參數，未經轉換不能當matrix key/tier','正常分支/重置之外不推計時保證'],['combo-window']),
 ('candidate-fallback','PARTIAL','031描述549C60對-1參數採actor+3E8 fallback，並由54AA60/548D20轉換候選後接availability；參數7/9不可直當tier。','549C60/549D29/54AA60/548D20/549D54',['完整參數/receiver/轉換未作新R3','031僅後續來源線索，不替026舊FAILED洗白'],['function-owner-026']),
 ('selector-setter','PARTIAL','033/034來源把4CD6F0安裝C07B44 primary+2C→4CE7F0、selector5 signed-WORD value→+3E8及+364清理/條件重建分開。','4CD6F0/C07B44/C07B70/4CE7F0/4CE90A..4CE99D',['setter selector5不等輸入index5或VK_V','動態callsite/玩家instance/type與所有resource ownership不由此證明'],['receiver-identity']),
 ('factory-init','PARTIAL','035..040描述特定444-byte factory分支建構後同一instance欄位填充與virtual初始化，並非全部類型都如此，也未接入玩家controller slot。','4A0FD8/4AE609/4CD6F0/4AEBxx',['record來源當時未閉合，不能命名玩家鍵盤或Server直接setter','direct call候選非全部constructor來源'],['receiver-identity']),
 ('registration','PARTIAL','041/042描述actor+4 WORD key的主樹missing/duplicate分流及第二owner+18容器，須與controller+0C/slot來源分開。','4DFF30/4DFFB0/57E850/546137',['排除041 L9 caller register角色反向敘述','現有CLM-CLIENT-0030僅重用key/duplicate子scope，不繼承更高可信度'],['registration-abi-candidate','receiver-identity']),
 ('instance-identity','UNKNOWN','setter、factory登記、controller actor及virtual+2C caller間的同一instance鏈未由這批早稿閉合；236粗略候選不是236個真正setter caller。','033..044 receiver/vptr/slot與例子排除',['來源只導航，非證明原版不存在呼叫','跨任務同offset與數字巧合均不作規範'],['receiver-identity']),
 ('combo-boundary','UNKNOWN','這批早稿尚未閉合玩家連按/held自動續段、普攻↔技能motion/queue/cancel與Server權威契約；500ms、60次、0.65秒均不能替代。','T10/T11交界與使用者操作需求的明示缺口',['使用者行為觀察與BIN主張分級','不將早期缺口當後續所有來源永遠無證據'],['combo-window','historical-xml-gap','historical-phase-gap']),
 ('writer-search-boundary','UNKNOWN','早稿精確地址xref或零命中不能排除indexed/alias/DLL非零writer；未定位是該版研究狀態，後續101有具體新來源待另行整合。','FB9014/FB9004字面掃描與當時writer缺口',['不得繼續宣稱目前沒有writer或沒有KeyMapping原件','此組不是肯定的runtime機制'],['historical-phase-gap','historical-xml-gap'])
]

# idx is an explicitly checked immutable source-list locator, not a claim generator.
# Each observation is a manually read narrative range and bounded disposition.
OBS={
0:[('timer',31,36,'state/tick、無號>500分支，未解完整jump-table CFG與Z。',[]),('command68',152,156,'索引28..37的phase consumer與68虛擬送出，不當普攻。',[])],
1:[('input-merge',12,15,'狀態返回映射、5467F4 WORD輸出與三路OR/byte優先分離。',[]),('state-reset-read',94,97,'batch/indexed zero與special樹分流，不是非零writer。',['reset-guard-order'])],
2:[('combo-boundary',7,15,'現有輸入傳送與本地motion只作邊界，.65/Server續段屬自製。',['combo-window'])],
3:[('timer',11,32,'547240 state/tick與500數值差，來源當時IAT單位待核，下一稿更新。',[]),('combo-boundary',91,104,'未證Z→連段→socket及animation/cancel閉環。',[])],
4:[('timer',14,48,'更新IAT為timeGetTime與完整局部phase轉換表，不命名Z。',[]),('matrix-tree',80,121,'AL flags具優先序，actor資料byte非input WORD，分類碼不是段數。',[])],
5:[('matrix-tree',33,98,'54F4E0有miss配置/insert，非pure lookup；平衡只候選。',[]),('bank-layout',100,136,'6D0Bxx屬較大loader CFG，row vector DWORD append不是runtime Z writer。',[])],
6:[('keymap-loader',10,14,'KeyMapping loader、DefaultType/fallback與實際Z映射分離。',['historical-xml-gap']),('bank-layout',59,75,'Type0..2及280 stride，編碼欄位/register還有caveat。',[])],
7:[('vector-copy',10,34,'來源DWORD地址copy、alias分支與fallback值不能直讀Z。',[]),('mapping-query',50,81,'一般/特殊兩來源及lazy init，不是每次按鍵重載XML。',[])],
8:[('mapping-query',14,36,'29個E8候選及數個屬性/顯示caller，未定位physical callback。',[])],
9:[('mapping-query',14,29,'樹內返回指標/可能插入和容器init，不是長按時間更新。',[])],
10:[('input-merge',14,18,'保留三路mask/byte資料流；L16的5467F1 store地址排除，正確F4見DECISIONS。',['store-address-007'])],
11:[('availability',14,16,'mask低15清除與actor/方向gate不等於取消成功。',[]),('combo-boundary',29,35,'映射/writer/motion/權威缺口，不能拿fallback/.65補。',[])],
12:[('availability',90,96,'controller availability成功/失敗與+3E8別稱限制，仍有方向後段。',[])],
13:[('subai-slots',139,143,'僅保留slot=4、幾何/目標state1/2/3局部；L137歸549980的函式邊界全部隔離。',['function-owner-026'])],
14:[('matrix-tree',122,142,'flags優先序與tier/key形狀，不直接映Z/X/C/V或冷卻writer。',[])],
15:[('combo-boundary',166,179,'availability、SubAI及配置為三鏈；五項玩家transition需另外閉環。',[])],
16:[('actor-state-read',7,9,'actor+3E8相等predicate/兩controller讀者，非V writer。',[])],
17:[('subai-count',6,9,'candidate策略、state1/2 counter>60選7/9不證時間。',[])],
18:[('candidate-fallback',7,10,'正確549C60根的參數、-1 fallback及state4局部；與026錯界分開。',['function-owner-026']),('matrix-tree',255,269,'7/9入口參數需轉換，不能當matrix key或tier。',[])],
19:[('combo-boundary',153,168,'Z可自訂、V改招和四transition矩陣的實際阻塞，保持T11責任邊界。',[])],
20:[('selector-setter',355,358,'同稿追加selector5→branch3→signed value store，與input index5不同。',['receiver-identity']),('instance-identity',425,445,'追加結案限定writer/dispatch，不是玩家實例和V閉環。',['receiver-identity'])],
21:[('selector-setter',12,24,'constructor/vptr/primary2C/selector分派及與玩家receiver尚缺連線。',['receiver-identity'])],
22:[('factory-init',12,38,'兩direct callsource及444配置，只有限枚舉。',[]),('selector-setter',106,130,'value1條件下+364再生，不能當V蓄氣結束。',['receiver-identity'])],
23:[('instance-identity',10,15,'236粗略虛調候選非setter callers；尚無player event→selector5。',['receiver-identity'])],
24:[('factory-init',10,15,'特定type分支constructor→ESI→欄位/virtual初始化，不包含2C setter。',['receiver-identity'])],
25:[('direction-synthesis',10,15,'index5==0門檻、空間方向分支、+3A8不同於+3E8。',[])],
26:[('direction-synthesis',10,15,'空間查詢/方向樣本/最多256候選，不作combo或V時間。',[])],
27:[('instance-identity',10,14,'factory/setter/controller gate並列但缺同instance橋；方向helper不是3E8 writer。',['receiver-identity'])],
28:[('registration',9,12,'只取key/missing/duplicate與identity未知；L9 caller EAX/stack角色不採。',['registration-abi-candidate'])],
29:[('registration',9,12,'第二owner+18/+F8與controller+0C/slot不同來源，不合併。',['receiver-identity'])],
30:[('availability',9,12,'mask、actor3E8 fallback及清低15位，不命名8000取消位。',[])],
31:[('matrix-tree',9,12,'flags分類及skillID→entry+4判斷，不是cast指令。',[]),('availability',11,15,'predicate false不表示全禁，motion/cancel仍未閉合。',[])],
32:[('matrix-tree',32,41,'4x11 shape與三層查詢，非4/11段combo。',[]),('bank-layout',137,161,'3x280銀行、非完整alias xref與signed上界限制。',[])],
33:[('direction-synthesis',9,11,'四byte1/2同效果、角度byte與float調整，非Z。',[])],
34:[('pointer-branches',9,13,'裝置／global／caller gate和pointer座標式方向；不把edge或+80命名combo。',[])],
35:[('pointer-branches',9,12,'第三路init/ownerAPI/座標門檻與函式邊界，API未核不命名。',[])],
36:[('state-reset-read',6,18,'writer無<=27、getter有guard；不同前提不當漏洞或非零phase writer。',['reset-guard-order'])],
37:[('phase-routing',6,15,'兩direct call與phase1/3後多態分流；當時unknown需與後續101分開。',['historical-phase-gap'])],
38:[('command22',6,10,'四位址觸發不同參數與22命令/sender，非連擊四段。',[])],
39:[('combo-boundary',7,14,'三條消費路不能拼一條Zchain，數值/phase語義不可倒推。',[])],
40:[('writer-search-boundary',7,7,'literal命中不都是instruction起點，zero/read搜尋不能排aliaswriter。',['historical-phase-gap']),('combo-boundary',154,158,'當時未知保留版本，不把500/.65當combo。',[])],
41:[('phase-routing',7,7,'普通0..39與擴展鍵、interception/helper和EC/F0分流。',['historical-phase-gap'])],
42:[('command68',7,7,'實際28..37十筆與gate、68/07候選sender，不當十段普攻。',[])],
43:[('combo-boundary',7,7,'A/B/C三路及無animation/queue/held/cancel閉環；XML缺失是當時狀態。',['historical-xml-gap','historical-phase-gap'])],
44:[('availability',10,15,'同controller輸入→predicate的靜態交界，非cast start/finish。',[])],
45:[('matrix-tree',10,17,'矩陣/entry及get-or-insert有副作用，不等冷卻啟動。',[])],
46:[('availability',10,18,'四個callsite按各自caller實參/消費分離，不能拼普攻接技能。',[]),('subai-slots',15,15,'549D54後狀態4局部，函式歸屬按已存DECISIONS限制。',['function-owner-026'])],
47:[('combo-boundary',18,30,'四transition未證與T11候選分工，不把cmd22/68或timer當技能。',[])],
48:[('writer-search-boundary',6,11,'絕對地址模式只找部分zero/read，非完整writer搜尋。',['historical-phase-gap']),('writer-search-boundary',54,70,'不成立zero==keyup或沒搜到==不存在；XML缺失只是歷史。',['historical-xml-gap'])]
}

def blob(b):return hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()
def save(p,x):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(x,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
def build():
 assert len(ROWS)==49 and set(OBS)==set(range(49))
 sources=[]
 for idx,r in enumerate(ROWS):
  b=(R/r['source_file']).read_bytes();lines=b.decode('utf-8-sig').splitlines()
  assert hashlib.sha256(b).hexdigest()==r['source_sha256'] and blob(b)==r['source_blob_sha']
  for ref in [I['base_main'],I['source_head']]:assert subprocess.check_output(['git','rev-parse',ref+':'+r['source_file']],cwd=R,text=True).strip()==r['source_blob_sha']
  oo=[]
  for key,a,z,note,conf in OBS[idx]:
   assert 1<=a<=z<=len(lines)
   oo.append(dict(claim_key='early-'+key,source_lines=[a,z],source_excerpt='\n'.join(lines[a-1:z]),observation=note,conflict_keys=conf))
  sources.append(dict(source_file=r['source_file'],source_blob_sha=r['source_blob_sha'],source_sha256=r['source_sha256'],client_version='kr',target_sha256=TARGET,source_intake_id=r['source_intake_id'],historical_status=r['historical_status'],historical_status_unchanged=True,integration_proposed='CONFLICT_CHECKED',review_method='Manual actual narrative R1 extraction plus existing exact conflict records; no new BIN audit',claim_keys=sorted({o['claim_key'] for o in oo}),source_lines=[o['source_lines'] for o in oo],observations=oo,conflicts=sorted({c for o in oo for c in o['conflict_keys']}),disposition='Only cited narrative subsets with explicit exclusions; original historical FAILED/PARTIAL preserved. Not full-report certification.',affected_spec_ids=[],spec_disposition='Client input/action research navigation; no identified present S00 Phase-B SPEC requirement or S00 acceptance.'))
 groups=[]
 for key,level,assertion,scope,limits,conf in GROUPS:
  kk='early-'+key;refs=[dict(source_file=s['source_file'],source_blob_sha=s['source_blob_sha'],source_sha256=s['source_sha256'],source_lines=o['source_lines'],scope_observation=o['observation']) for s in sources for o in s['observations'] if o['claim_key']==kk]
  assert refs,key
  cc=sorted(set(conf)|{c for s in sources for o in s['observations'] if o['claim_key']==kk for c in o['conflict_keys']})
  groups.append(dict(key=kk,assertion=assertion,evidence_level=level,evidence_scope=scope,limits=limits+['各來源僅支持source_refs列明子集，不繼承整組或其他來源較高品質。','R1非全文FULLPASS／native_complete／runtime／Server規則驗收。'],conflicts=[dict(key=c,**CONFLICTS[c]) for c in cc],affected_spec_ids=[],existing_claim_ids=['CLM-CLIENT-0030'] if key=='registration' else [],existing_claim_reuse_scope='Key/missing/duplicate registration subset only; does not import caller-register ABI, shared identity or unrelated +88 predicate scope.' if key=='registration' else None,source_refs=refs,integration_proposed='CONFLICT_CHECKED',risk='R1 navigation; known contradicted claims excluded and concrete R2 gaps preserved',s00_acceptance='NOT_GRANTED'))
 assert {k for s in sources for k in s['claim_keys']}=={g['key'] for g in groups}
 p=dict(schema='t01-t10-roy-r1-proposal-v1',scope='early',base_main=I['base_main'],source_head=I['source_head'],target_sha256=TARGET,date='2026-10-29 Asia/Taipei',reviewer='Codex T01 review_t08_new',source_count=49,completed_sources=49,remaining_sources_in_scope=0,new_native_audits=0,native_promotions=0,historical_verdict_changes=0,groups=groups,sources=sources,conflict_registry=CONFLICTS,excluded_material='No continuation-03 draft was used.',canonical_reuse_checked='research/claims/index.json inspected; CLM-CLIENT-0030 fits registration subset. No existing canonical input/matrix/charge claim found; adjacent network facts are not widened to gameplay.',stop_reason='Source identity, actual bounded narrative, grouping and known conflict handling complete. R1 stop; S00-specific R2/R3 requests only.')
 save(D/'proposal.json',p);print(json.dumps(dict(sources=49,remaining=0,groups=len(groups),observations=sum(len(s['observations']) for s in sources),native_promotions=0)))
if __name__=='__main__':build()
