"""Serialize manually read R1 source observations. No native analysis or global writes."""
from pathlib import Path
import json,hashlib,subprocess
D=Path(__file__).resolve().parent;R=D.parents[3]
BASE='610a822b15346c9e0b69edd4e104c2076f2b59ac'
TARGET='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
PACK=R/'research/handoffs/t01-t08-roy-20261029/sources.json'
INDEX=json.loads(PACK.read_text(encoding='utf-8'))
HASH_REF='shared/integrations/T01-20261029-semantic-review/t08-new/return-items.json'
MAP_REF='shared/integrations/T01-20261029-semantic-review/t08-early/mapping-reviews.json'
TASK_REF='kr/tasks/T08/README.md'
CONFLICTS={
 'heap-index-tree':dict(description='7B86F0/7B8680 相關 heap 名稱索引被早稿稱為 tree/RB erase；既有反證為7B868B..AC hash/mask/bucket及7B86DE→719B20 list unlink/free，不能當排序樹結論。',refs=[HASH_REF,TASK_REF],disposition='僅排除 heap 索引的排序樹／RB 斷言；保留查名稱／payload／呼叫資料流作PARTIAL導航，不連帶否定相鄰內嵌樹。',r2_if_needed='需要 heap 名稱容器精確類型時重用上述確證反證並定向補來源勘誤；本輪不重驗。'),
 'manager-is-provider':dict(description='096/097 從0x8C manager 登記路徑連到 heap 多型Provider的推論，098已指出首DWORD是ID，099區分address/value兩容器，100另找0xB4 Provider。',refs=['kr-temp-roy/20261027-114418-chatgpt-web-roy-T08-098-name-registry-provider-type-separation.md','kr-temp-roy/20261027-115552-chatgpt-web-roy-T08-099-dual-global-name-container-disambiguation.md','kr-temp-roy/20261027-134325-chatgpt-web-roy-T08-100-heap-provider-vtable-binding-clone.md'],disposition='排除0x8C manager等同heap Provider／Binding及錯連容器的部分；後稿只作具版本PARTIAL更正來源，不改早稿歷史判決。',r2_if_needed='正式規格需要具體Provider時才查指定constructor/vptr/insert資料流。'),
 'owner-not-resolved':dict(description='104/105 從consumer未直接讀FB7740不能推出一定不同實例；後續129有相反owner說法但既有mapping裁決FAILED，不能擇新覆舊。',refs=['kr-temp-roy/T08-KNOWLEDGE-BASE.md',MAP_REF],disposition='共同保留實際owner／alias未解，僅允許候選consumer導航；既不斷言等同全域桶也不斷言必定不同。',r2_if_needed='S00需要consume/reset順序時依精確PE座標追owner指標到global heap，先處理129來源映射。'),
 'plane-writer-stale':dict(description='102–105當時未找到係數writer；KB後續列838430/799D20更新鏈，故早期搜尋未命中不能作現在不存在writer的結論。',refs=['kr-temp-roy/T08-KNOWLEDGE-BASE.md'],disposition='只保留camera/正規化/alias語義未知；不把歷史未找到升格不存在寫入者；後續writer導航交middle來源處理。',r2_if_needed='若規格依賴係數來源或方向，引用118–120精確版本定向核證。'),
 'reader-later-located':dict(description='089/090/092的resource+20 reader未定位是當時狀態；093L118/198列7BD8D0具體讀取者。',refs=['kr-temp-roy/20261027-103853-chatgpt-web-roy-T08-093-resource-update-completion-dispatch.md'],disposition='不輸出reader不存在／仍完全未定位；保留同offset不同allocation的辨識限制，7BD8D0僅PARTIAL導航。',r2_if_needed='需要完成條件精確浮點/NaN契約時查7BD8D0指定分支，不按動畫長度命名。'),
 'legacy-coordinate':dict(description='歷史flat標籤與PE VA不可拼接；既有24份來源mapping判決及Task退回保留。',refs=[MAP_REF,TASK_REF],disposition='保留座標/來源SHA群組界線；排除錯標VA所衍生caller/vtable等價；不將text -400套到rdata指標或所有早期來源。',r2_if_needed='需要映射衝突來源之正式事實時逐blob核PE/raw/完整CFG。'),
 'spawn-policy-unknown':dict(description='Client row/owner欄與本地fixture不證Server出生時機、波次、AI決策或權威。',refs=[TASK_REF],disposition='僅資料介面導航；Server決策缺口和Client未解分開，無生成時間/策略規範。',r2_if_needed='出現具體協定欄位/順序阻塞再交T02/T08/T06/T07定向。'),
 'old-rejection-withdrawn':dict(description='82EF00 lower-bound-only舊拒因已撤銷，尾端存在等值條件；不能繼續引用它反駁exact-key用途。',refs=[TASK_REF,'shared/integrations/T01-20261028-27/README.md'],disposition='移除已撤銷拒因；本輪未重驗函式，不由撤銷直接升NATIVE_VERIFIED。',r2_if_needed='若需要新R3結論，重用精確已審scope或定向驗證。')
}

# These are manually chosen bounded content groups, not filename-derived claims.
GROUPS=[
 ('components','PARTIAL','來源描述共用／CMonster建構會把依component+8索引的元件指標存到owner+F4表，並有25槽清理；不賦予事件或遊戲規則名稱。','4D1710/4C7070/4C9F90/4CB230/4C7B90局部構造與表操作',['正常路/配置失敗與全部例外未在R1驗證','至少已列元件不是全元件集合'],[]),
 ('owner-setter','PARTIAL','來源將primary vtable+68解析為4C8DA0，描述寫owner+38C並由+15C/+370 gate轉送參數；事件碼意義保持未知。','4CB2C0→C0C9DC+68→4C8DA0局部路徑',['不同runtime類別與secondary vptr不得套用','不是AI或動畫狀態規則'],[]),
 ('linked-lookup','PARTIAL','來源描述515790以unsigned DWORD key查有序容器，輸出node/sentinel；7A7800另有重映射與下游查找，不能把返回節點直接當Actor。','515790與7A7800指定lookup資料流',['R1不重驗實際STL型別或完整caller','各sentinel flag位移不同'],[]),
 ('upstream-entry','PARTIAL','來源把541130附近node+C列為傳給79D8E0的key來源，並指出更新候選來自既存node+28，不能當新建物件。','541130/79D8E0局部key與pointer/control-block更新',['完整八DWORD stack建構及上游node來源仍未閉合','不賦予遊戲語義'],[]),
 ('string-lookup','PARTIAL','來源描述716740以字串查找後把node+28調整+3C交7197E0，並非直接返回payload或建立Actor。','716740指定字串轉換/查找/forward窗口',['字串及返回C++型別未解','不與其他名稱容器只按offset等同'],[]),
 ('scene-dispatch','PARTIAL','來源描述global/scene table的8-byte stride、default forwarding與scene handler index7；transport拆框與wire opcode對應仍未確立。','4B7DC0/4B7EC0/4ADD50/4C4670與4AE4D0引用',['不把同容量或內部command直接當wire協定','關鍵封包契約需R2'],['spawn-policy-unknown']),
 ('actor-interface','PARTIAL','來源描述0007按前置2 bytes及26-byte row處理、以actor key去重並有4DFF30登記；主樹、其他狀態/資源容器與Server生成政策須分開。','4AE4D0/4D1710/4DFF30及相關lookup/registration來源描述',['不宣告完整bounds、全部類型或deallocation通過','Server時機/AI/owner權威未知'],['spawn-policy-unknown','old-rejection-withdrawn']),
 ('event-meaning','UNKNOWN','元件virtual+4/+8的實際調度者與事件7/8的遊戲含義未被這些來源閉合；不能命名死亡或認為命令151直接觸發事件8。','type1/3/4元件、4CB2C0/4CB590/4CB850和狀態旗標疑問',['unknown不是否定其存在','不從相同事件數值合併不同slot'],[]),
 ('state-resources','PARTIAL','來源把狀態樹批次更新與128個狀態資源槽的按需建立／稍後回收分開；局部缺<128檢查不等於可利用漏洞。','4D2Fxx/4C9840/4C83C0/4C8580及owner+164/+36C',['合法ID領域/上游bounds和清理時機未全證','不推固定frame頻率或Server狀態規則'],[]),
 ('update-schedule','UNKNOWN','真正場景物件vtable+20上層調度與固定更新頻率未在此來源集合中閉合；Binding/manager同offset不能替代scene receiver。','C07554+20/4C8580與資源管理更新鏈的連結缺口',['僅Client未知導航','不判定原版不存在更新'],[]),
 ('pool-lifecycle','PARTIAL','來源把7C-byte資源取得／reset／解除、mode控制的延後容器與直接清理路徑、+5C與+60計數分開，容器可復用而非只待刪除。','7DCFB0/7BE5B0/7BE5F0/7DD1A0/7DD1F0/7DD100及mode控制',['各來源覆蓋不同步驟；不推全所有權/並行安全','mode/gate精確已審部分只引用CLM-CLIENT-0002原scope'],[]),
 ('binding-resolution','PARTIAL','來源描述7BDF90按item+4名稱查索引，對node+24 payload virtual+10取得item+8 Binding，與7BE0F0解綁及resource+74流程標記成對；+74=1不保證每項成功。','7BDF90/7BE0F0/7DC510局部解析與清理介面',['排除heap索引排序樹/RB稱呼','不把0x8C manager當heap多型Provider','未知virtual/失敗/ownership不補猜'],['heap-index-tree','manager-is-provider']),
 ('name-containers','PARTIAL','099以FE173C字面地址對比[FE173C]內容區分相鄰內嵌管理容器與heap名稱索引；節點+24不能證明payload同型，0x8C首DWORD是順序ID。','7B7DA0/7D7139/7B82D0/7BDF90/7DCEE0來源級身分辨識',['僅採後稿明示更正與來源對應','不沿用所有container共用7B86F0排序樹的錯說'],['manager-is-provider','heap-index-tree']),
 ('provider-clone','PARTIAL','100描述heap索引7DC660接收0xB4多型Provider，C50A8C+10→7F21A0建立Binding複本，須與0x8C ID管理器及+84次級receiver分開。','7DC660/7D6EC4/7D6F51/7F15B0/7F1650/7F21A0',['完整複製/引用計數/資源回收與全部vtable邊界未驗','不推所有Provider均此類'],['manager-is-provider']),
 ('numeric-transforms','PARTIAL','來源描述2C-byte變換、子項輸出與有序有限float的resource+20最大值聚合；實際量綱、座標系與遊戲名稱未確定。','7BE150/77E910/77E800/77E880的來源級數值流程',['不宣稱camera/世界座標/動畫長度','NaN、零除、手性與全部helper未閉合'],[]),
 ('wrapper-provenance','PARTIAL','090/091等來源將30-byte wrapper+2C持有的7C-byte資源與wrapper自身欄位區分；同為+20不能當同物件或真正reader證據。','7B8230/7F6F50/C511CC/7FF7xx/7FF8xx資料來源',['vtable鄰近資料不自動延長表長','早期resource+20 reader未知已由093提出具體後續來源'],['reader-later-located']),
 ('resource-update','PARTIAL','093描述7BD8D0累加resource+1C、處理子項virtual與變換，讀resource+20並有條件設+6C；不把phase、完成訊號當動畫時間或必然立即free。','7BD8D0/7BD7E0/7BDF00/7BDF40與+6C消費鏈',['精確x87/NaN、所有virtual及所有權未R1深驗','早期reader缺口按093版本限定更新'],['reader-later-located']),
 ('active-transfer','PARTIAL','094來源將7A86B0與7A87D0列為共同上游依序調度，並描述未完成資源由+108/+120轉入+10C active list後清槽；不等同actor登記。','7A5DBA/7A5DD9/7A87D0/75A6F0/7A6830',['複合gate與管理器具體類別未閉合','完整時序/所有權/釋放條件不推廣'],[]),
 ('binding-gates','PARTIAL','101描述Binding+7C與+80兩旗標分離：7F2520反轉測試結果寫+80，7BDF40僅在特定三重gate派送+18；不是所有更新都停用。','7F2520/7F2320/7F23B0/7BDF40與C50A8C/C50ABC',['不猜死亡/停止/鎖定語義','所有alias寫入者與clone ownership未知'],[]),
 ('geometry-meaning','UNKNOWN','六組四float係數測試與三／四參數入口可作研究導航，但係數物理意義、相機視錐／半徑、正規化方向與NaN契約尚未閉合；早期未找到writer不是不存在writer。','838800/838860/FB76B0及後續writer導航',['只以UNKNOWN交S00，不規範相機或渲染','118–120後續writer待對應精確來源scope'],['plane-writer-stale']),
 ('bucket-producers','PARTIAL','102/103/105來源描述FB7740的22×2004-byte桶、局部<800限制與append寫入者；producer、配置、清理不等同consumer或每幀reset。','798F26/FB7740/7F23B0及其他明列append窗口',['不推每個index合法或entry同型','0x2C058恰等22*2004；排除102 L24孤立「大於」錯字'],[]),
 ('bucket-owner','UNKNOWN','7D13xx/7D17xx候選dispatch/reset路的實際owner是否等於FB7740全域heap仍須精確alias證據；相似stride或未直接讀global均不足判相同／不同。','104/105候選consumer、KB限制與129映射衝突',['不輸出全域consumer已證實或必定不同實例','未接通scene主迴圈'],['owner-not-resolved','legacy-coordinate']),
 ('coordinate-boundary','PARTIAL','reaudit來源區分PE映射與歷史flat標籤，text受影響位置的標籤差不能自動移動rdata內真實指標或全程式所有函式。','reaudit-01/02的PE/raw/VA與來源群組限制',['本輪不重跑native/自動校正原稿','已FAILED映射版本與Task退回維持'],['legacy-coordinate']),
 ('script-cleanup','PARTIAL','reaudit-02把script DeleteAllObject的owner/tree及virtual清理與GameInfo主樹分開；DeleteObject註冊與no-op不能證明通用Actor erase或最終回收。','563A70/823850/5666A0/476430來源級局部介面',['動態類型、完整引用清理與GameInfo同步未閉合','不擬定移除封包/Server時間'],[])
]

# Each line-range observation was chosen after reading the actual narrative.
# filename suffix is only a stable locator for that explicitly written observation.
OBS=[
 ('T08-CMonster-constructor.md',[('components',7,29,'建構三種配置／owner+F4索引表；元件ID與欄位用途仍未知。',[])]),
 ('T08-owner-vtable-68.md',[('owner-setter',12,35,'primary與+F0次級vptr分開；+38C setter及條件轉送。',[])]),
 ('T08-lookup-515790.md',[('linked-lookup',8,40,'exact-lookup輸出node/sentinel，不直接回Actor；含不同helper旗標offset。',[])]),
 ('T08-upstream-key-source.md',[('upstream-entry',19,40,'node+C為key、candidate+28來源；八DWORD呼叫上下文不只單一push。',[])]),
 ('T08-string-indexed-lookup-716740.md',[('string-lookup',21,39,'字串查找後adjust+3C forward，不是直接Actor建立。',[])]),
 ('T08-CMonster-inherited-components.md',[('components',11,27,'父／派生共用元件表；至少1/2/3/5，fallback+158不證model資源。',[])]),
 ('T08-dispatch-composite-id.md',[('scene-dispatch',11,35,'global/scene表及三參數轉送；transport未對上。',[]),('actor-interface',39,61,'row計數及composite打包；record[2]==0時32-bit underflow，不可縮成byte。',['spawn-policy-unknown'])]),
 ('T08-object-tree-lifecycle.md',[('actor-interface',11,44,'FAB138去重／反向讀取與FC0E90/FAB148分離，4C6E50不是插入證據。',['old-rejection-withdrawn']),('actor-interface',54,59,'這一版尚未定位insert/remove，不把當時未知說成現行不存在。',[])]),
 ('T08-component-destruction-25-slots.md',[('components',29,38,'25槽0..24與+158表外；virtual0(1)不能冒充virtual4事件。',[]),('event-meaning',40,44,'事件7/8語義與具體網路移除中間鏈未知。',[])]),
 ('T08-type1-event8-flagged-tree.md',[('event-meaning',19,21,'Type1 virtual8與Type3/4 virtual4要分離。',[]),('event-meaning',37,67,'flagged state及resource+11C gate不證HP0或死亡。',[])]),
 ('T08-state-tree-resource-lifetime.md',[('state-resources',9,37,'狀態樹清空不同步清128槽，索引上游界限未知。',[])]),
 ('T08-079-state-reconcile.md',[('state-resources',4,15,'+36C倒數後128槽對照狀態樹回收；151更新與即時清槽分離。',[])]),
 ('T08-080-object-update.md',[('state-resources',4,4,'共用update轉接與+36C/128槽關聯更新。',[]),('pool-lifecycle',14,14,'解除資源與pool/direct分支的來源摘要，固定頻率未知。',[])]),
 ('T08-081-shared-cleanup.md',[('state-resources',4,4,'更新vtable及倒數初值/首次30行為。',[]),('pool-lifecycle',6,6,'子項清理、manager+44選路和array free；不等於同時釋放wrapper/resource。',[])]),
 ('T08-082-pool-consumer.md',[('pool-lifecycle',4,14,'+7C/+80容器消費、mode排空及+5C/+60計數分離。',[])]),
 ('T08-083-reuse-pool.md',[('pool-lifecycle',4,13,'取得先pop/reset再新建，池可復用；mode與計數來源區分。',[])]),
 ('T08-084-resource-templates.md',[('pool-lifecycle',4,4,'復用局部reset與新配置7C/初始化欄位分開。',[]),('binding-resolution',6,6,'名稱predicate/virtual清理只作索引介面導航，排除排序樹措辭。',['heap-index-tree'])]),
 ('T08-085-template-binding.md',[('binding-resolution',5,6,'item名稱→node+24 virtual10→item+8，resolution後+74=1。',['heap-index-tree']),('numeric-transforms',27,38,'多float數值流程未命名渲染/世界座標。',[])]),
 ('T08-086-registry-transform.md',[('name-containers',5,11,'FE173C為heap配置指標，cleanup後置零。',['heap-index-tree']),('numeric-transforms',13,13,'數值變換helper組合，矩陣/旋轉細節未定。',[])]),
 ('T08-087-registry-transform-binding.md',[('name-containers',5,5,'heap指標與FE1740相鄰容器分離，不合併型別。',['heap-index-tree']),('numeric-transforms',7,16,'數值寫回bound child與+74，不只是local temporary。',[])]),
 ('T08-088-transform-quaternion-aggregate.md',[('numeric-transforms',5,16,'2C變換／quaternion與finite ordered最大值；手性/物理意義不定。',[])]),
 ('T08-089-aggregate-reader-audit.md',[('wrapper-provenance',14,36,'指出另一40-byte allocation的+20不證pooled resource reader；早期reader未知後由093補。',['reader-later-located']),('numeric-transforms',4,12,'resource+20最大值writer錨點。',[])]),
 ('T08-090-pool-pointer-provenance.md',[('wrapper-provenance',6,25,'直接resource返回與30-byte wrapper+2C持有來源分離。',['reader-later-located'])]),
 ('T08-091-wrapper-vtable-resource.md',[('wrapper-provenance',6,24,'wrapper表／+2C持有、setter及release；鄰表長度與+20消費不推廣。',['reader-later-located'])]),
 ('T08-092-resource-update-dispatch.md',[('binding-gates',23,32,'child null/byte/+80三重gate及wrapper+2C轉入resource。',[]),('resource-update',57,60,'累加float phase仍為暫名；未找到reader是早期狀態。',['reader-later-located'])]),
 ('T08-093-resource-update-completion-dispatch.md',[('resource-update',47,118,'7BD8D0累加、transform、AND結果及有序完成條件，+20讀取者被明列。',['reader-later-located']),('update-schedule',194,203,'所有Binding實作/主場景調度尚未閉合，不以active-list代替。',[])]),
 ('T08-094-manager-update-resource-ownership.md',[('active-transfer',23,25,'共同上游依序調度且不同scene主迴圈。',[]),('active-transfer',107,118,'completed/reset/pair轉移多分支，+108/+120轉入list再清槽。',[])]),
 ('T08-095-binding-name-resolution-lifecycle.md',[('binding-resolution',37,44,'名稱payload virtual10與解綁/+74成對，不能據+74保證全成功。',['heap-index-tree','manager-is-provider']),('binding-resolution',105,109,'這一版Provider/Binding方法仍unknown；後續099/100來源分開追溯。',['manager-is-provider'])]),
 ('T08-096-provider-registration-refcount.md',[('name-containers',13,18,'只保留8C管理器計數/初始化與不能混binding+80；排除連成heap Provider與樹稱呼。',['manager-is-provider','heap-index-tree']),('update-schedule',95,100,'完整節點/實作/回滾與scene主迴圈是明示未知。',[])]),
 ('T08-097-tree-node-provider-link.md',[('name-containers',14,16,'719B90的node+24拷貝只表示payload來源；不保留L10跨容器Provider等價。',['manager-is-provider']),('binding-resolution',17,18,'heap lookup virtual10寫Binding與兩dispatch槽分開。',['heap-index-tree','manager-is-provider']),('update-schedule',81,85,'明示型別／上游／主調度尚未知。',[])]),
 ('T08-098-name-registry-provider-type-separation.md',[('name-containers',13,15,'指出8C首DWORD是ID不是vptr，不能當heap Provider。',['manager-is-provider']),('name-containers',19,28,'本版仍把D7139叫同一索引；只保留地址與內容必須分離的待解導航，099已更正。',['manager-is-provider','heap-index-tree'])]),
 ('T08-099-dual-global-name-container-disambiguation.md',[('name-containers',12,20,'顯式更正098：address/value及兩容器；不合併payload。',['manager-is-provider','heap-index-tree']),('name-containers',35,41,'登記stack容器/名稱/payload與heap pointer解參照區分。',['heap-index-tree'])]),
 ('T08-100-heap-provider-vtable-binding-clone.md',[('provider-clone',10,15,'找到heap insert/0xB4 Provider及clone slot，分離8C manager。',['manager-is-provider']),('provider-clone',61,64,'完整ownership/複製、flag寫入者和主調度未閉合。',[])]),
 ('T08-101-binding-state-virtual-dispatch.md',[('binding-gates',11,18,'+80反轉Boolean、+7C獨立gate、secondary adjust thunk及clone非單純淺拷貝。',[]),('binding-gates',63,66,'未知所有alias寫入者與ownership，不把800上限當動畫數。',[])]),
 ('T08-102-plane-test-binding-initialization-global-buckets.md',[('geometry-meaning',13,16,'six coefficient測試但frustum/死亡/動畫名稱不成立。',['plane-writer-stale']),('bucket-producers',24,28,'22*2004恰等2C058；排除同句大於錯字，secondary pointer append不證consumer。',[])]),
 ('T08-103-plane-buffer-bucket-producers.md',[('bucket-producers',10,14,'配置/直接append與未知consumer分離；非全alias掃描。',[]),('geometry-meaning',354,358,'半空間為推測，writer當時未找到不等於不存在。',['plane-writer-stale'])]),
 ('T08-104-dispatch-consumer-ownership.md',[('bucket-owner',12,16,'記錄候選consumer並保留未證全域owner，不能因非直接global load推不同實例。',['owner-not-resolved']),('bucket-owner',180,198,'alias/實際基址與主調度為明示缺口。',['owner-not-resolved','plane-writer-stale'])]),
 ('T08-105-global-buckets-plane-writers.md',[('bucket-owner',46,57,'候選consumer基址和逐位元組xref限制，不是完整指標身份證明。',['owner-not-resolved','plane-writer-stale'])]),
 ('T08-105-extended-six-plane-readers-and-bucket-ownership.md',[('geometry-meaning',55,86,'三float/四float閾值入口與NaN不能簡化，radius仍推測。',['plane-writer-stale']),('bucket-producers',101,125,'22桶配置與額外append；EBX加count未追不能一概count++。',[]),('bucket-owner',129,146,'多階段dispatch/reset可導航，actual owner/alias仍未解。',['owner-not-resolved','plane-writer-stale'])]),
 ('T08-integrated-reaudit-01.md',[('coordinate-boundary',11,15,'明示正式任務scope及PE/flat座標差，不混指標或把bytes當全文pass。',['legacy-coordinate']),('actor-interface',140,181,'保留source-level建立/控制槽/移除缺口，不補Server authority/AI。',['spawn-policy-unknown'])]),
 ('T08-integrated-reaudit-02-spawn-registration-and-script-cleanup.md',[('actor-interface',11,16,'count/typejump/duplicate診斷/node配置來源描述，不宣稱全部失敗生命期。',['spawn-policy-unknown']),('script-cleanup',17,18,'script owner清理與GameInfo及no-op DeleteObject分開。',[]),('coordinate-boundary',22,22,'不能統一-400全部function label或跨群拼caller。',['legacy-coordinate'])]),
 ('T08-KNOWLEDGE-BASE.md',[('name-containers',53,65,'摘要保留address/value與8C/Provider分離；正式native仍回精確原稿。',['heap-index-tree','manager-is-provider']),('bucket-owner',87,97,'長期明示全域consumer/owner未知及版本衝突，不接受KB自稱穩定作R3。',['owner-not-resolved','legacy-coordinate']),('geometry-meaning',67,83,'後續writer導航與camera語義未知並存，早期writer未找到已非現況。',['plane-writer-stale'])])
]

def blob(b):return hashlib.sha1(b'blob '+str(len(b)).encode()+b'\0'+b).hexdigest()
def save(p,x):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(json.dumps(x,ensure_ascii=False,indent=2)+'\n',encoding='utf-8')
def build():
 rows=[x for x in INDEX['sources'] if x['scope']=='early'];assert len(rows)==42 and len(OBS)==42
 sources=[];seen=set()
 for suffix,observations in OBS:
  matches=[x for x in rows if x['source_file'].endswith(suffix)];assert len(matches)==1,suffix
  r=matches[0];assert r['source_file'] not in seen;seen.add(r['source_file']);b=(R/r['source_file']).read_bytes();lines=b.decode('utf-8-sig').splitlines()
  assert hashlib.sha256(b).hexdigest()==r['source_sha256'];assert blob(b)==r['source_blob_sha']
  assert subprocess.check_output(['git','rev-parse',BASE+':'+r['source_file']],cwd=R,text=True).strip()==r['source_blob_sha']
  oo=[]
  for key,start,end,note,conflicts in observations:
   assert 1<=start<=end<=len(lines)
   oo.append(dict(claim_key='early-'+key,source_lines=[start,end],source_excerpt='\n'.join(lines[start-1:end]),observation=note,conflict_keys=conflicts))
  sources.append(dict(source_file=r['source_file'],source_blob_sha=r['source_blob_sha'],source_sha256=r['source_sha256'],client_version='kr',target_sha256=TARGET,source_intake_id=r['source_intake_id'],historical_status=r['historical_status'],historical_status_unchanged=True,integration_proposed='CONFLICT_CHECKED',review_method='R0 identity and R1 actual narrative reading; bounded source observations only, no new native audit',claim_keys=sorted({o['claim_key'] for o in oo}),source_lines=[o['source_lines'] for o in oo],observations=oo,conflicts=sorted({c for o in oo for c in o['conflict_keys']}),affected_spec_ids=[],spec_disposition='Downstream Client navigation only; no demonstrated current S00 Phase-B SPEC dependency; S00 acceptance not granted.'))
 groups=[]
 for key,level,assertion,scope,limits,conflicts in GROUPS:
  kk='early-'+key;refs=[dict(source_file=s['source_file'],source_blob_sha=s['source_blob_sha'],source_sha256=s['source_sha256'],source_lines=o['source_lines'],scope_observation=o['observation']) for s in sources for o in s['observations'] if o['claim_key']==kk]
  if not refs:continue
  allconf=sorted(set(conflicts)|{c for s in sources for o in s['observations'] if o['claim_key']==kk for c in o['conflict_keys']})
  groups.append(dict(key=kk,assertion=assertion,evidence_level=level,evidence_scope=scope,limits=limits+['R1來源整合，不是全文通過、函式通過、native_complete、runtime或Server驗收。'],conflicts=[dict(key=c,**CONFLICTS[c]) for c in allconf],affected_spec_ids=[],existing_claim_ids=['CLM-CLIENT-0002'] if key=='pool-lifecycle' else [],existing_claim_reuse_scope='Only mode/gate normal-path subset under original CLM scope; other lifecycle steps remain PARTIAL.' if key=='pool-lifecycle' else None,source_refs=refs,risk='R1 with known conflicts quarantined; any normative native or protocol use requires targeted R2/R3',integration_proposed='CONFLICT_CHECKED',s00_acceptance='NOT_REQUESTED_OR_GRANTED'))
 assert {k for s in sources for k in s['claim_keys']}=={g['key'] for g in groups}
 save(D/'proposal.json',dict(schema='t01-t08-roy-r1-proposal-v1',scope='early',base_main=BASE,source_head=INDEX['source_head'],target_sha256=TARGET,reviewer='Codex T01 review_t08_new',date='2026-10-29 Asia/Taipei',source_count=len(sources),completed_sources=42,remaining_sources_in_scope=0,all_sources_registered_or_preexisting=True,new_native_audits=0,native_promotions=0,historical_verdict_changes=0,groups=groups,sources=sources,conflict_registry=CONFLICTS,stop_reason='R0 identity, bounded scope, source-level dedup and known conflict dispositions completed; R1 stop condition met. Do not launch general re-audit.',global_progress_note='These42 are disjoint from middle48/late48; root computes total138 progress.'))
 print(json.dumps(dict(completed=42,remaining_in_scope=0,groups=len(groups),observations=sum(len(s['observations']) for s in sources),native_promotions=0),ensure_ascii=False))
if __name__=='__main__':build()
