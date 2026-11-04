# Quest Runtime wire 適配契約

**版本：0.1.0｜分類：Server 候選設計｜用途：供 S00 設計接口及漸進採用。**

共用 Quest Runtime 應輸出 typed domain command／event，由有版本的適配器選擇已核對的 Client consumer／producer，再交既有編碼器處理 application body 與 transport framing。任務內容和 Runtime 不直接組 byte 陣列，不以 opcode 數字代替任務語意。本文件與本包 JSON schema 都是自訂 Server 候選格式，**不是原生 MEF，也不是已恢復的原 Server 規則**。

完整逐欄資料見 [quest-wire-map.csv](quest-wire-map.csv) 與 [quest-wire-evidence.json](quest-wire-evidence.json)。JSON 保留來源 registry、Git blob SHA1、內容 SHA256、長度種類、scene/controller 條件、receipt、持久化邊界、BLOCKED 欄位與未知。本文件規定這些資料如何進入接口，沒有將部分原生證據升格為完整協定或實機驗收。

## 1. 證據與版本邊界

| 分類 | 允許表達 | 不可跨越的邊界 |
| --- | --- | --- |
| Client 事實 | 原 BIN／資源的有界欄位、分派、狀態寫入、UI或腳本效果 | 不能由此恢復原 Server 的合法完成、資產歸屬、資料庫或交易時點 |
| 使用者要求 | 單人 Scenario、清怪後保留戰鬥、站上 portal 按 Z 才轉圖／結果、debug 不寫正常紀錄 | 是這個 Server 的需求，不能寫成原 BIN 已證政策 |
| Server 候選 | 本文件的 domain API、pending slot、持久化／發布順序；現行獨立 Server 的配置與 matcher | 不冒稱官服 wire sequence、原生 MEF、或已驗收所有任務 |
| 未知 | `null`、CSV空欄、具名 BLOCKED 與解除條件 | 不轉成0、false、空獎勵、已完成、無需等待或其他隱含預設 |

固定來源版本如下；後續引用須保留 commit／blob／內容 SHA，不能只寫「最新 T16」。

| 來源 | 固定版本 | 主要內容 |
| --- | --- | --- |
| 分析 main | `83959c0e7e65ab01348b285f03c285f487077610` | T16 原稿與勘誤、T07/T09/T14既有成果、W1結果與W2/W3工作卡 |
| 補充分析 | `76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac` | NPC視窗與scene交接、portal、reward顯示域；不宣稱已在上述main |
| 獨立 Server 候選 | `f95fe9099419b2bbb5f0daa71c6810d0c2b53d8e` | 現行教學／Quest15橋接的配置、編碼器與connection流程 |
| 原 KR BIN | SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` | 本包有界原生主張的目標版本 |

W2/W3在固定main的檔案是工作卡，不把計畫當研究成果。一般結果與返回以已存在的T07/T14來源補足。[S07] [S08] T16-117是研究段號，與Quest117分開；mode2→C2S36的舊主張依固定勘誤撤回，不重新開立owner或RR。[S01]

## 2. 四層接口與責任

| 層 | 輸入／輸出 | 責任 |
| --- | --- | --- |
| Quest Runtime | `QuestId`、flow/node、目標、前置、domain事件 | 判定候選任務狀態、合法節點遷移及提交要求；不依賴opcode、封包offset或Scene vtable |
| NPC／Presentation／Scenario／World服務 | `SceneRef`、`NpcRef`、`ScenarioEntryRef`、`MapGraphRef`、typed intent／outcome | 管理對話、場景、單人編隊、instance、map/NPC/actor、portal、result、return；保留教學hook；多人party獨立 |
| Context-bound Protocol Adapter | domain command ↔ 已辨識的C2S observation／S2C presentation | 選擇確切方向、manager／Scene／controller、body shape及已核對欄位；維護Server內部pending上下文 |
| 既有 codec／transport | application body ↔實際connection/framing | 延用既有序列化、連線和封包編碼器；本包不另造transport header或直接socket寫入路徑 |

例如Runtime發出`ScenePlayRequested(SceneRef(15,2))`，Presentation服務查適配綁定、檢查當前phase與controller需求，Protocol Adapter才可選S2C47。C2S3F解碼後只形成`SceneControllerReportObserved`；Runtime若要改目標或結算，仍要獨立的目標證據與政策。收到報告、建立結果頁、提交instance terminal、提交Quest settlement、發放獎勵，是不同事件。[S02] [S03] [S05] [S07]

上述名稱是Server候選domain名稱，不是原生封包名稱。C2S適配器是**Server consumer，證據來自Client producer**；S2C適配器是**Server producer，證據來自Client consumer**。兩個方向不得只因opcode相同而共用同一業務handler。

## 3. Context dispatch 與typed ID

每個可用adapter binding至少應攜帶以下資訊：

| 欄位 | 用途 |
| --- | --- |
| `client_build_sha`、`adapter_contract_version` | 對上既有有界Client證據；不同binary不得默默沿用VA／結構 |
| `direction`、`connection_context`、`channel` | 區分C2S／S2C及實際傳輸路徑；channel值只填該來源閉合的值 |
| `dispatch_owner` | 區分頂層CClient callback、SceneManager、QuestMgr、current Scene |
| `expected_scene_class`、`controller_kind`、`controller_mode` | 防止同opcode在另一Scene／controller進入不同handler |
| `server_context_generation`、`flow_instance_id`、`node_id` | Server自己的phase／世代與待處理節點，不是Client新增欄位 |
| `opcode`、`subtype`、`body_shape_ref` | 選擇對應長度、欄位、signedness與效果；未知subtype不套最接近的模板 |

CClient的頂層callback可能先攔截；fallback到current Scene時，table B override優先於A。QuestMgr有自己的表，不能將其slot與Scene A或CClient stride混算。現有資料中，S2C23／24是在CClient dispatcher origin=`C+0x200`、stride16的頂層callback；S2C37則可由特定Decision的table B覆寫。[S06] [S09] [S12]

typed ID不可藉數字相等省略：`Quest15 ≠ Field19 ≠ Case103 ≠ Map191/192`，現行`FormationToken19`也不因值相同就等於Field19。NPC template、場內entity、portal/checkpoint key、objective record key、scene primary key各自保留domain。`001C`和`0041/0042/007F`中的key沒有一律綁定QuestId；`0038+3`也不是無條件MapId。[S02] [S04] [S06] [S08] [S14]

## 4. 欄位／長度與未知值契約

所有offset都相對**包含2-byte opcode的application body**；多位元組欄位依所引Client資料流採little endian。這裡不包括TCP framing、加密／壓縮或外層header。

| 長度描述 | 意義 | 不代表什麼 |
| --- | --- | --- |
| `exact_producer_bytes` | 指定Client producer或明示Server候選確實組出的body長度 | 所有相同opcode的唯一長度、或全Scene通用格式 |
| `minimum_bytes_accessed` | 指定consumer讀取到的最低byte範圍 | 官服完整封包長度、合法尾端、或已驗證的上游安全length gate |
| `length_formula` | 已證固定row或變長entry走法 | entry全部業務語意、最大數量或所有失敗分支皆已閉合 |
| `all_required_field_meanings_resolved` | 當前欄位語意覆蓋程度 | Runtime實測、Server合法值政策或發布時序已批准 |

原生以`i16`讀取的scene pair／lookup key，不能只因本包ID為正值就把signedness省去。反過來，wire的窄欄位也不定義所有資源ID的寬度；adapter需在有證據的綁定中做可表示性檢查。`ret 0x0C`是native stack清理，不是12-byte body宣告。[S03]

**`null`／空欄不是可序列化的猜值。** 若必要欄位、typed binding或合法業務值未知，該adapter必須維持BLOCKED，讓上層知道哪一項無法發布。若現有Server候選使用明示值，例如result body的零值或13-byte編隊matcher，應以獨立candidate binding保存來源、用途與限制；不能將該值回填成原生確定值，也不能提升所有同opcode列為可用。[S07] [S13] [S14]

欄位全集、各列unknowns與source_sha以兩份wire資料檔為準。下節是採用約束，不替代機讀定義。

## 5. 核心opcode的採用與誤用邊界

| 方向／opcode | 已證shape或下限 | 可用效果／條件 | 不得推導 |
| --- | --- | --- | --- |
| C2S001C，NPC路徑 | producer6B；`+2:u16`、`+4:u16`來自巢狀事件 | NPC互動意圖，需綁producer／NPC與當前flow | 第一個WORD一律QuestId；意圖本身是接受、目標成功或結算 |
| C2S001C，portal路徑 | producer6B；`+2 category:u16`、`+4 checkpointKey:u16` | 普通category0、當前controller及checkpoint gate成立 | body含XY、Map、Quest、kill count或通關證明 |
| C2S0036 | producer4B；`+2:u16`取`WORD*([TalkBox+88])` | 已閉合mode1/F4402及指定action；另有獨立relay producer | mode2／mode3都送QuestInfo.id；36↔40為已證唯一request/reply |
| C2S003F | producer8B；primary、secondary、reportValue各u16 | controller報告；此producer寫reportValue1 | 渲染成功、UI清理完成、合法Quest完成、資產入帳 |
| S2C0040 | consumer至少8B；`+2 qid:u16`、`+4 status:u32` | status0先排F438B／mode2 UI，再查AcceptAction；改exclusion/candidate | 安靜ACK；無AcceptAction就無窗；status是byte |
| S2C0045 | consumer至少4B；`+2:i16` lookup key | 按CompleteAction走scene／local event／其他UI分支 | 普遍完成、發獎或Quest15必定scene3 |
| S2C0046 | consumer至少6B；qid:u16、substate:u16 | substate0改exclusion、條件append prerequisite、F438C→mode3 | 與40／45／47同義；直接播放下一scene；Server已settled |
| S2C0047 | consumer至少6B；primary/secondary為i16 | `503040→561760`，受controller忙碌／mode等gate約束 | 無條件播放成功；ID加一；附帶Quest完成 |
| S2C0048 | consumer至少6B；key:u16、category:i8、enable:u8 | 對既有checkpoint比對key/category，更新enable | scene ACK、instance完成或普通Quest狀態更新 |
| S2C006F | 對齊copy shape為`2+4N`，tail是u32 bitset | 先清prerequisite vector，再由set bits重建；全量替換 | u16 QuestId array、delta、永遠保留先前74／46效果 |
| S2C0074 | consumer至少4B；`+2 prerequisiteKey:u16` | 不去重append，再重建candidate | 唯一writer；自動冪等；durable完成／發獎 |
| S2C0037 | 已見selector byte+2；完整契約仍BLOCKED | Mission／Raid／DailyDungeon Decision的table B override | 通用Quest接口、普通Scenario可任意用、已證C2S37 |
| S2C0022/type0 | consumer至少22B，見§8 | 安裝ScenarioDecision、結果資料與UIstate8 | type0/1是勝敗enum、所有欄位都是reward、已保存Quest |
| C2S0033 | producer2B，僅opcode | 特定result UI分支的return request | body含Town/Map/Quest/retry/award ACK；發出即已回村 |

NPC／scene／prerequisite列引用T16原稿與勘誤。[S01] [S02] [S03] [S04] [S05] Portal列引用固定補充分析與本包有限原件補證；0037引用T09/T14的適用Scene範圍。[S07] [S09] [S11] Result／return引用T07/T14。[S07] [S08]

另有三類不能省略的binding：

- **0038 context**：至少讀取9-byte header，subtype決定Town selector／其他context與結果背景；+5 WORD完整語意未知。它可能清理過場或重建candidate，不是單純Map install。[S04] [S08]
- **0041/0042/007F objective records**：41是value/key pair更新；42／7F有不同owner、record寬度與變長entry。完整entry語意、目標domain綁定仍有BLOCKED。F4266可在未命中record時出現，不能用事件存在判斷Quest完成。[S06]
- **004E／0050／0028 formation**：token與allowed/ordered角色資料屬Scenario適配；現行Server的0028精確13B、owned leader及零tail要求是候選matcher。不能當作所有原生編隊的完整普遍政策。[S13] [S14] [S15]

## 6. Correlation：Server pending slot，不新增Client echo

Client的001C、003F、0033等body沒有本包新設的nonce／flow instance ID。**Server不可要求未修改的Client在原封包新增echo、transaction ID或generation。** 本文件所稱correlation是Server自己的pending slot及上下文配對，不是新wire欄位。

候選`PendingPresentation`可保存：connection/session reference、flow instance、node、Server context generation、預期Scene/controller、已請求的scene pair、預期opcode/body shape、request dispatch狀態與收到的observation。這些資料留在Server。入站仍依原body解析，再用當前pending slot判斷是否符合所等待的事件。

例如等待scene(15,2)時，C2S3F只提供primary15、secondary2、reportValue及其原生shape；Server可以查目前是否確實等待這一pair，不能從這些bytes證明它帶有新的唯一請求編號。對無key的C2S33，只能依目前「等待此instance的結果返回」phase及connection context配對。[S02] [S07] [S08]

此機制有必須保留的限制：

- 若相同pair或無key命令跨兩個不同flow世代重用，舊receipt與新receipt可能在wire上不可區分。Server內部generation本身不能使Client封包突然具備世代證明。
- 不允許同一connection同時放置多個wire形狀無法區分的pending操作；是否序列化、如何取消／換Scene，是明示Server候選政策。
- 發送成功或收到3F不等於畫面成功；pending slot只記錄請求／報告證據。`receipt_observed`與`objective_proven`、`settlement_committed`分欄。
- 本包不宣稱exactly-once網路傳輸、斷線後自動恢復或重送已驗證。相關情形只列設計／待測；本輪不執行。

## 7. NPC窗、劇情對話與scene cleanup

對話生命週期需要四個不同primitive／observation：NPC互動意圖、NPC TalkBox呈現／關閉、scene內對話結束、scene controller報告。統一寫成`scene_finished`會遺失必要條件。

### 7.1 NPC TalkBox不是劇情對話

S2C40/status0先建立F4281與F438B；F438B攜帶qid，`5B7FFF→5B6D20→636520(mode2)`可顯示NPC對話。排入發生在AcceptAction查詢之前。故Quest15原表沒有AcceptAction，仍不能把40當無窗同步。[S03] [S10]

mode1的F4402路徑在合法送0036後呼叫dialog virtual+0xD4；指定取消action也可關窗而不送36。mode2／mode3與它不同，未建立通用Server close command或可觀察closed ACK。[S01] [S02] 因此`dialogue.dismiss`可以存在於Server候選流程語彙，但其所需adapter／closed barrier未閉合時必須BLOCKED，不能靠一次C2S36或任意003F補作證明。

劇情Lua的`OpenTalkScene`另設`g_scenePlaying=TRUE`並由`WaitForScene`等待。`6BD720→4AD0A0("OnEndTalk")`解除該本地旗標；這不等於NPC TalkBox的close，也沒有在此證明一個網路close ACK。[S16]

### 7.2 003F早於部分cleanup

已核原生次序為：`561FB0`呼叫`4A39A0`送正常報告，才到`561FF1`共同尾段；`56202D`移除coroutine，`56207B`還原UI，`562091/562094`清目前primary/secondary。因此Server收到003F時，不可宣告全部UI已清理完成；固定sleep也沒有成為原生barrier的證據。[S10]

現行Quest15的最小採用方式是在15/1→15/2移除額外40，保留既有前置、NPC意圖、控制恢復與47。這個方案針對已定位的額外開窗來源；不另猜「安靜接取opcode」，也不保證已解掉所有modal生命週期。正常流程仍需逐步觀察沒有NPC窗覆蓋、第二段scene與後續編隊可用。[S10] [S13]

Accepted的domain提交時點和NPC UI呈現分離。現行Server候選在合法編隊確認／入場附近保存接受階段，不應因移除40而丟棄該合法記錄，也不把這一Quest15政策變成所有任務唯一的接受模板。[S10] [S13]

## 8. Scenario、portal、result與return

### 8.1 Portal是意圖入口，清怪與退出分兩個事件

S2C27替換完整checkpoint集合，row為18B：key:u16、category:i8、enabled:u8、x/y/radius:f32、automatic:u8、auxiliary:u8。需要保留的其他checkpoint不能因一次portal發布意外遺漏。category0的有效半徑為wire radius乘`0.800000011920929`，距離判定為嚴格小於；automatic0要求動作鍵，非0可入圈即觸發。其視覺scale倍率另算，不作碰撞半徑。[S11]

S2C48對既有checkpoint更新enable；本包最小原BIN補證為table A slot+244→4B32E0，讀+2/+4/+5，經544940比對checkpoint+F6/+F4，再於543B77寫+105。完整圖像效果callee的所有CFG未因此升格FULL-PASS。完整bytes與slice SHA在wire evidence指向的原件補證中。

合法001C(category0,key)到達後，由Scenario服務檢查當前instance/node、已開門、Server自己的pose及權威clear predicate，再產生node-exit。清怪只開出口；戰鬥保留，直到玩家在portal按Z後才轉圖／result。這是本次使用者要求及現行候選採用的政策，並非原MEF已恢復的出口條件。[S11] [S13] [S14]

固定補充portal文件內較早的automatic1／停止戰鬥候選已不符合目前要求。其原生欄位與測距結果可復用，舊政策不可抄入新內容；現行候選採automatic0並保留combat。出口座標、key1/2、半徑、容差與FormationToken19都須標candidate，不能從欄位存在推成原版配置。[S11] [S13] [S14]

### 8.2 教學保留hook

教學C2S40的4B body是scenario request，與S2C40的8B以上Quest UI回覆完全不同。TUTO S2C4C把local map[scenarioKey]寫1，使`IsScenarioEnded`可繼續Lua；一般5F/type2替換Scene後，不可仍假設原TUTO owner/coroutine持續接收。保留教學服務分支，不能用一般ScenarioDecision或Quest完成替代此本地續行訊號。[S07] [S15]

### 8.3 Result body只閉合儲存與部分UI用途

0022/type0的欄位為opcode、+2 signed subtype、+3未解byte、+4/+8/+12/+16各DWORD、+20 WORD，consumer讀取至少22B。+4 DWORD低byte影響零／非零文字及演出；+8 DWORD內的byte+9影響直接返回或角色資訊分支。其他數值的完整業務含義與+3合法值仍未知，不能填XP、reward、win/lose、reason的猜值。[S07] [S08]

進入ScenarioDecision會替換舊Scene、清checkpoint、切UIstate8、建EmptyController；ready不等於恢復玩家移動。結果按鈕的指定零參數分支才直接送2B的C2S33，非零可先開角色資訊，其他確認模式另有分支。C2S33沒有目的地；Server依已授權的result phase選擇return target，再調用World／Scenario服務安裝場景、map、NPC、actor與controller。返回村莊可操作、instance完成、Quest結算是不同可觀察結果。[S07] [S08]

載入顯示23／24只處理loading呈現，不能作map-ready ACK；0038 context也不能替代map／actor bundle。若某個流程需要完整初始化receipt而尚未找到native wire證據，要保留未知，不能新增Client echo或把CSquare43初始化進度改名為已可玩。[S12] [S13]

## 9. Reward display、domain grant與發布三層分離

`RewardsEtc` loader與UI的較新有限證據已閉合以下顯示映射，來源blob為`537eadcf1687838769880a32c97ed83f96d3f60a`。[S17]

| raw type | Client record offset | Client顯示域 | 尚不能據此指定 |
| --- | --- | --- | --- |
| 2 | `+0x88` | text0x15F，`kQuestRewardPartyExp` | Server資產key、角色／隊伍歸屬、等級換算、發放時機、發布opcode |
| 4 | `+0x7C` | text0x163，`kQuestRewardLeeloo` | Server帳本域、收受範圍、實發倍率、發布opcode |
| 3 | `+0x84` | 未閉合 | 任何經驗／貨幣／角色推定 |

兩個已閉合UI顯示路徑都乘F94364；這不是已證Server實發倍率。Quest16的type2/value50、Quest15的type2/value2800與type4/value468是資源原值；不能把50叫貨幣，也不能從PartyExp label推定所有owned角色平均分配。[S17]

資料應分開保留`client_display_domain`、`grant_domain`、`recipient_scope`、conversion policy與`publication_adapter`。後四者無證時為null/BLOCKED。item／currency／character／experience各類更新需要其自身有來源的Client發布介面；6F／74、46、22、003F都不能充當獎勵入帳封包或完成交易。

候選結算順序可設為：先核對合法目標與交付policy，再原子提交Quest terminal、RewardLedger／實際資產變化及待發布intent，最後由已核對adapter發布。這是Server設計；當grant或publication所需欄位仍未知時，不將pending狀態偽裝為已發獎。本包沒有實作或執行交易、重送、斷線／恢復測試。

## 10. 漸進採用與驗收邊界

第一階段保留已通教學及Quest15專用路徑，以facade抽出typed事件、adapter binding、scene pair、Scenario入口及portal/result/return節點。待各binding有來源與scope，再把可共用部分移入內容資料；真正的TUTO owner/coroutine等差異繼續保留hook。不能先刪專用流程，再靠每個Quest補if填回缺口。

Quest117的無field單scene、Quest118的Field28單scene、Quest119的Field26多scene提供不同靜態形狀，但不證明各自合法目標與結算。NEXT依章節scene vector查找，不是Quest或Scene數值加一。後續內容應沿已核對前置／章節／scene建立graph，不以「把全部scene播放完」當整村完成。[S04] [S18]

本輪所有runtime採用卡均為**NOT_RUN／待測**。正常驗收需觀察NPC窗關閉及scene交接、正規編隊／入場、清怪後仍可戰鬥、站門按Z、result／return、回村控制，並對照保存的正常玩家進度。debug快進／退回只驗定位與局部呈現，不算正常通關、不回寫正常紀錄。先前人工觀察保留其build/SHA與通過步驟，不向未觀察的任務、結果或整村主線擴張。

## 固定來源索引

以下連結均固定commit。詳細Git blob SHA1、內容SHA256和每列引用範圍見`quest-wire-evidence.json`的`sources`。

| 來源 | 內容 |
| --- | --- |
| [S01] | T16-117固定勘誤：mode1／2／3與C2S36 |
| [S02] | T16-127：001C／003F／0036 producer |
| [S03] | T16-128：QuestMgr訊息、prerequisite cache與UI |
| [S04] | T16-130：章節scene vector FIRST／NEXT |
| [S05] | T16-134：C2S／S2C scene觸發因果 |
| [S06] | T16-110 REV：41／42／7F record contract與未解綁定 |
| [S07] | T14 WP03：結果、返回、教學與一般Scenario差異 |
| [S08] | T07：一般副本0022／0033與結果背景 |
| [S09] | T09：table A／B與Decision override，保留derived限制 |
| [S10] | 補充分析：40的NPC窗與3F cleanup次序 |
| [S11] | 補充分析：portal原生欄位／觸發；舊Server政策另行區分 |
| [S12] | Loading23／24：CClient callback與非ready ACK |
| [S13] | 現行Server候選connection流程 |
| [S14] | 現行Server候選編碼器與配置 |
| [S15] | 教學NPC與formation有界來源 |
| [S16] | T16-133：qbase、四段Lua與本地對話生命週期 |
| [S17] | RewardsEtc儲存與Client顯示域 |
| [S18] | W1 scene list來源核對；非整村通關 |

[S01]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T16-T01-returns-20261030/errata/T16-117-Q16-MODE2-C2S36-T01-erratum.md "T16-117固定勘誤：mode1/2/3與C2S36"
[S02]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261030-141801-chatgpt-web-roy-T16-127-KR-Quest15-study3-NPC10338-001C-003F-0036-sender-queue-native.md "T16-127：001C/003F/0036 producer"
[S03]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261030-144014-chatgpt-web-roy-T16-128-KR-Quest15-study4-S2C-0040-0045-0046-0047-006F-0074-mode2-mode3-state-UI.md "T16-128：QuestMgr訊息、cache與UI"
[S04]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261030-155219-chatgpt-web-roy-T16-130-KR-Pindos-Table-SceneList-chapter-sequence-Scene3-return-BIN-first.md "T16-130：章節scene vector FIRST/NEXT"
[S05]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261031-154318-chatgpt-web-roy-T16-134-KR-Quest15-C2S-S2C-scene-trigger-causality.md "T16-134：C2S/S2C因果與限制"
[S06]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261030-002349-chatgpt-web-roy-T16-110-REV-Quest14-study4-client-S2C-contract-S00-handoff.md "T16-110 REV：41/42/7F record contract"
[S07]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/T14/WP03-20261101/T14-WP03-WIN-FAIL-ABORT-REENTRY-NATIVE.md "T14 WP03：結果／返回／教學差異"
[S08]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr/evidence/00c7ff83c85dd8f01e882d82bf2d83fcf6eed2788d3fd60dbd69682b2764d977.txt "T07：一般副本0022／0033"
[S09]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261027-044428-claude-web-roy-T09-bulk-actor-classes-movement-formulas-table-A-full.md "T09：table A/B與Decision override，保留derived限制"
[S10]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/S00-20261103-PHINDOS-ACCEPTANCE-UI.md "補充：40的NPC窗與3F cleanup次序"
[S11]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/S00-20261103-FIELD19-PORTAL-GATE.md "補充：portal原生欄位／觸發；文內舊Server政策另行區分"
[S12]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/governance/s00-iterations/S00-20261101-LOADING-DISPLAY-LIFECYCLE.md "Loading23/24：CClient callback與非ready ACK"
[S13]: https://github.com/we88ec3-prog/ttr_server_roy/blob/f95fe9099419b2bbb5f0daa71c6810d0c2b53d8e/src/Tartaros.Network/LocalTutorialWorldConnection.cs "現行Server候選connection流程"
[S14]: https://github.com/we88ec3-prog/ttr_server_roy/blob/f95fe9099419b2bbb5f0daa71c6810d0c2b53d8e/src/Tartaros.Protocol/KrPhindosBridgeCandidateProtocol.cs "現行Server候選編碼器與配置"
[S15]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/governance/s00-iterations/S00-20261101-TUTORIAL-NPC-AND-FORMATION.md "教學NPC與formation有界來源"
[S16]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/kr-temp-roy/20261030-171913-chatgpt-web-roy-T16-133-KR-Quest15-four-Lua-qbase-bytecode-talk-prolog-phases-return-native.md "T16-133：qbase與四段Lua對話"
[S17]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac/governance/s00-iterations/S00-20261102-QUEST-REWARD-CHANNELS.md "RewardsEtc儲存與Client顯示域"
[S18]: https://github.com/we88ec3-prog/ttr_anal_multi/blob/83959c0e7e65ab01348b285f03c285f487077610/research/handoffs/s00-phindos-mainline-20261102/W1-RESULT-BATCH04-SCENELIST-RECONCILED.md "W1：scene list來源核對，非整村通關"
