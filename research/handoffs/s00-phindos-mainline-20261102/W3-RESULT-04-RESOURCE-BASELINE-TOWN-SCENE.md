# W3 批次04 — RESOURCE-BASELINE v1 核對、Town1 正常場景／controller 界線與 BND v2 解析依賴

> 工作分支：`extra/roy3`。使用者新提供的唯讀資料為 `27c1faf7d:research/handoffs/s00-phindos-mainline-20261102/RESOURCE-BASELINE.json`，Git blob **`5ac883881d3ab0c711ad7c0bdd84c4dd3c2e5cd6`**。本報告以該釘版作**資料來源**，不因其與工作分支 diverged 就合併其他 S00 需求／Server 變更。

標記：**R**＝保存的精確資源行或已釘 SHA 的 header 數值；**N(partial)**＝既存 KR BIN 有限原生紀錄／bulk Ghidra 文字，不是本輪重新做原檔 instruction-level 驗證；**I**＝有條件推論；**S**＝Server 重建設計建議；**U**＝未知。未執行或修改 Client/Server／測試環境、未操作網路協定，不更新正式 RR/APPROVED／Task owner，不重做 S00 的 AI/MEF 或連擊核心分析。

## A. 新精確唯讀資料的新增值及可直接採用的 typed IDs

新來源 `governance/inspect_phindos_mainline_resources.py`（Git blob `bccac21ba9709d70827f20291a39b2689b8e3dde`）指定 carrier SHA，透過唯讀 STPD 解出 BND、XML，對每一 decoded member 計 SHA256，並對 BND 只用 `struct.unpack_from('<IIIff', r, 0x20)` 讀 header。本批**已讀它的程式文字與 JSON 輸出，未有原始 STPD 或 KR BIN bytes 再次離線重跑**；請 T01 對 pinned 資料／流程做獨立複驗，勿把這份基準稱 native format FULL-PASS。

| Domain | 來源資源行／header | 可用範圍與限制 |
|---|---|---|
| `TownId`／`TownType` | `Town1 / TYPE1`；NPC 9 筆 | **R**，不等於任何 S2C scene subtype 或 controller kind。 |
| `MapSelector` | `182 = town001D / town001.mef / BOUND town001` | **R**，不能把 `0012 selector=1` 或 `0038 Town1` 當相同欄位。 |
| `QuestId 15` | `Town5` / `field19` / giver=finisher 10338 / Demand16 | **R**；Field 是任務域，不是 MapSelector19。 |
| `QuestId 117` | `Town1` / giver=finisher 10002 / Demand15 | **R**；要以合法完成15後的權威狀態判接取，不得 15/3 cutscene 自動標記。 |
| `QuestId 123/124` | giver=finisher **10048**，Demand122/123 | **R**：補足先前第一批只列 Quest124 的遺漏。 |
| `FieldId 19` | `CaseId 103` `STAGE=19`，`CHART_S_pathofpindus_01.xml` | **R**，QuestField/Case/MapFlow 仍分型，非自動選圖。 |
| `MapFlowNode1` | graph `x=360, y=372`，`MapSelector191` 100% | **R** 圖表節點位置與權重，**不是**玩家 Spawn(x,y)。 |
| `MapFlowNode2` | graph `x=360, y=276`，`MapSelector192` 100% | **R** 同上；node1→2 的實際觸發／合法完成另由 W2/S00。 |

已保存資料對應版本 **Town1 BND與兩份 Field19 BND**：

| Member | decoded SHA256 | header version | grid W×H | world X×Y | 世界單位到格的暫定比例 |
|---|---|---|---|---|---|
| `BoundMap/town001.bnd` | `30b383ac9eb2228601bd93fab21a79ed68c66d65751993fb0f32dcd294a061f6` | `0` | `768×768` | `1536×1536` | `768/1536 = 0.5 cell/unit` |
| `BoundMap/scenario_pathofpindus01.bnd` | `adb627155fc051aaa5a568ae57fe8731d388d58c2cf3244711078ef377321c58` | `2` | `768×768` | `768×768` | `768/768 = 1 cell/unit` |
| `BoundMap/scenario_pathofpindus02.bnd` | `89cc3d4b77d3cf0cdf64d45f610d7b987c704bc268881c13396e1375a2234fff` | `2` | `768×768` | `768×768` | `768/768 = 1 cell/unit` |

三者由同一 carrier `Map/BoundMap.stp` SHA256 `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8` 的 pinned resources 提供。**注意**：最後欄是依已存 header 做的幾何比例算術（I），不代表原生每個座標／圖層讀取與輸入採用同一語意。Town1 的 360/372 與 Field19 graph 360/372 絕不能互移，後者根本是圖表節點、不是 world spawn。

### Field19 v2 對現有 v0 工具的實際差異

- **已確認的資源 header 差異（R）**：`version=0→2`、`world extent=1536→768`，格數仍為 `768×768`；兩張 Field19 BND 的 decoded SHA 不同，不可把 Map191 的碰撞套 Map192。
- **已確認的程序文字（N(partial)）**：KR `830040` 讀 header+0x20 的欄位，**等於3** 時呼叫 `82F850`（0x534 header、descriptor stride0x28），**非3** 時呼叫 `82F660`（0x234 header、stride0x10）。所以 header `2` 在此分派視窗走**非3**路線。這是選擇器行為，**不是**兩個 v2 BND 已實測能被 `82F660` 正確解碼的證明。
- **現存 v0 讀器的精確角色澄清**：`governance/inspect_tutorial_bounds_resource.py` blob `e39cb00a9db90fbbea00844449b4b4da56520fae` 是**governance 離線檢查器**，含 `assert version==0`、寬高預設、zlib 32 descriptor 等。**並非在本庫已直接確認的 Server 生產碰撞解析器**。原先 W3-RESULT-02 把它寫成 `Server v0 reader` 的措辭應讀作「S00 目前選用的 v0 離線候選格式 reader」；不能依該工具宣稱現行 Server runtime 的實際 parser 實作。
- **未完成事項（U）**：尚缺兩份 Field19 BND 的 0x234 header 與 per-layer compressed/expanded/count/offset 真實資料、解碼後 32 層描述與 layer0/1 cell zero/nonzero 值的個別 SHA、runtime 是否接受 v2 的 fallback/後處理、玩家出生點與無障礙連通路徑。單有 header SHA 與 v2 號碼**不能改成 v0，也不能跳過檢查或「all-clear」**。

**S：允許後續實作的門檻**：離線以 pinned archive/decoded member SHA 檢查 exact version=2，選擇 `!=3` layout 的候選 `0x234`，檢查每個非空層的 offsets、輸出長度、層總數、解碼器 EOF／unused bytes，並針對兩張圖獨立取樣；唯有 T01 驗明原生 Client 解碼鏈與 layer0/1 實際語義後，S00 才決策加入分版本 reader。未驗一律 `UNKNOWN`（拒絕推定可走），不在此報告填座標。這也不是負向遊戲測試。

## B. Town1 正常 Scene/controller：「已排除的候選」與「尚未找到的真正入口」

延伸 [W3-RESULT-03](W3-RESULT-03-SCENE-NPC-ENTRY.md) 的小範圍探索，選讀**保存之 KR bulk pseudos**與原 T07 有限場景控制器報告。這些來源並未跑原始 BIN／client，亦非完整 call graph 證書：

| 原生入口／訊息 | 可見 native RTTI 或 controller | 判定 |
|---|---|---|
| `S2C005F` subtype2 | `4B99C0→4C46F0` 設 `CScenarioField`；原 T07 報告指 `4C4750` 建 `CFormationController` kind3 | N(partial)：一般 Scenario 候選；不代表正常 Town1。 |
| `005F` subtype4 | `4BC6A0` = `CMissionField`；既存初始化 `4BC750` 使用 `CSingleController` kind2 | N(partial)，不等於 TownType1。 |
| `005F` subtype6/9 | `CDuelField` / `CRaidField` | N(partial)，不等於 Town。 |
| `005F` subtype25/26/28 | `CInfiniteDungeonField`、`CEternalTowerField`、`CDailyDungeonField`（入口 `4564F0`、`4369D0`、`422FB0`） | N(partial)：補查三個舊報告未展開的 ctor；均無 Town 專屬標記。 |
| `S2C0069` subtype7/21/23/24 | `CSquare`（7/23/24）／`CDuelSquare`（21） | N(partial)，不得把 Square 與 Town 靠數值或資源名混為同一正常 scene。 |
| `S2C0060` | `4B8F50→4C13E0` 設 `CExpedition`，以 `4B7D50` 安裝並交 `4C22C0` 處理資料，條件下 enqueue C2S `00F5` | N(partial)：另查正向這個候選，不等於 Town；`S2C0060` 也**不是** `Map182` selector 或 Town1 business context。 |
| `0099/type3` 舊 `MissionRoom` 候選 | `4BCBA0` 已存場景入口可建立 `CMissionRoomController` kind1；**尚無** `0099/type3→Town1 normal scene→Map182` 直接閉環 | U：不許把 controller kind1、Town TYPE1、0099/type3 拼成原生可用發送序列。 |
| `4B7D50` scene install | 原報告可見先清舊 scene，再填 scene manager+0x5EAC，觸發新 scene vptr+0x10 | N(partial)：必要生命周期界線，不保證所選場景正確，也不證 Town ready。 |
| `S2C0012` | `4B24F0` 先 checkpoint/actor/controller reset，payload+2 DWORD → `4DF510` | N(partial)：只有 map selector 的資源載入線，不會自行辨認正常 Town Scene、NPC 對話或權威玩家 spawn。 |
| `S2C0038` type0 | `4B1BF0` 更新 Town context/QuestMgr | N(partial)：TownId=1 可作資源指定，但不等同場景與物理 MapID182 的官服配對。 |
| `S2C0014` | Scenario bounded ready 存在；Town active-scene callback 尚無足夠閉合 | U：不可只因發14或 S2C24 loading end 就宣稱可見且可走。 |

**本次查無明確正常 Town scene/controller 正向完整路線，故先記 UNKNOWN**，不是「原版 Client 不存在這個場景」或「可以採用 Square」。具體缺口為 `Server 觸發入口 opcode+subtype`、`Client 對應 ctor/RTTI`、`controller kind+owner`、`Map182 正常配對`、`role/meta/actor 重新建立`、`ready/loading/end/可操作 UI`；T01 應循 real producer/caller 追查，不用舊 Python fixture 冒充。

#### 可交付的正流程依賴排序（S，非正式原服 wire sequence）

1. **先驗權威業務入口**：Quest15 是 Town5/Field19，Town1/Quest117 的 prerequisite Demand15；查證權威 Quest15 的合法完成，不只場景結束。
2. **選正確 scene**：尚未知入口，不能把 `0038(TownId=1)` 當會自動建立場景。缺此 gate 不發無關 `005F/0069/0099`。
3. **Map**：合法 scene 後的 `MapSelector=182` 資源與 `BoundMap/town001`。因 `0012` 可 reset actor/controller，後續須重新檢查角色與 NPC 的實際 presence/bind；同 Map 快取分支不代表重建了 actors。
4. **Players**：自有角色 identity / ephemeral wire alias、角色 metadata、actor(model scale 1；非 Z 高度)、stats/parameters、控制器 rebind；僅依舊有 T04/T08/T09 有限 consumer 機制可設計，確切 Town 先後未證。
5. **NPCs**：以 Town1 精確九個 model IDs 與 QuestInfo giver 欄位建立**待掛接 roster**；世界 entityId、PRE1/model、位置、event category/subId、回覆與合法 spawn 未全證，不臆造任何點。Quest123 亦給 `10048`。
6. **可用後才 ready/loading end**：有界 23/24 是 UI 顯示候選，不是 scene 物件載入成功，也沒有新造 ready ACK 或固定 sleep。保持未採用/待人測分層，不做 Client/Server 操作。

## C. 對 T01 的逐項驗證輸入與限制

| P | 具體可驗子主張 | 需反證／完成條件 |
|---|---|---|
| P0 | 兩個 Field19 BND 的 SHA+header version2/world768 | 用 pinned `Map/BoundMap.stp` 離線重算兩 decoded members；查 0x234 descriptor 實際層佈局與完整 decode，而非僅比 header |
| P0 | `830040` version==3 才走 `82F850` | 原 BIN 指令/跳轉從入口到 call site 查明，並對 v2 實際材料檢查 `82F660` consumer；不能宣稱 parser 全文 FULL-PASS |
| P0 | 005F/0069/0060 已知場景分支不是 Town1 配對證據 | 追真正 Town scene/controller upstream，確立 opcode、subtype、RTTI、scene install、Map182 正向使用 |
| P0 | actor reset → rebind、NPC 互動 | 核對 `0012/07/08/0A/14/23/24` 條件與 Town NPC 10002 的 event category/subId、`001C/003C/003F/0036` producer 分流、後續 UI release；不得猜 001C 是所有 NPC 唯一路徑 |
| P1 | Town1 合法出生／返回點 | 來源要是能支援角色 spawn 的動態/靜態設定與可達路徑；FLD 物件、Portal 特效、graph x/y、演出座標不算。 |

### 明確未執行／未修改

不執行、附加、修補原 Client 或啟動 Server；不跑負向、重播、重登、往返、併發、故障、壓測。沒有執行在使用者本機使用的 STPD 讀取工具，只核對其 Git 文字與輸出。沒有修改舊報告、所有 Task owner、正式 RR、APPROVED，也沒有傳訊其他對話。T01 獨立查核後 S00 再決定 Server 採用。

## D. 精確來源 Git blobs

- `27c1faf7d:.../RESOURCE-BASELINE.json`: `5ac883881d3ab0c711ad7c0bdd84c4dd3c2e5cd6`.
- `27c1faf7d:governance/inspect_phindos_mainline_resources.py`: `bccac21ba9709d70827f20291a39b2689b8e3dde`.
- `kr/evidence/8762287177ecd19a4bf1b4a21c8e311a58733e962b1bacc28c6c1461e02b7bb3.txt`: `59254f10bcdc4acbcf51d68846e6e6b01454afb9` (T07 scene/controller limited matrix).
- `kr/evidence/0bab714e82d96b0f6a4165471fc52531ba4b250f63878e2721bdd706fb8bab37.txt`: `f03c89937b70386b4675cadca195d0b1f672f317`.
- `kr-bulk-roy/<KR_SHA>/functions/0x4b8f50.c`: `a1b5da758b1b0ffd0e36c32072e38e936ae55299`; `0x4c13e0.c`: `29a6b00f78b50b6e415db4f4575ca17ee81d1cd8` (0060→CExpedition).
- `kr-bulk-roy/<KR_SHA>/functions/0x4564f0.c`: `a3fd10e65f97db05218f6c4b719d46a34ecbcfd2`; `0x4369d0.c`: `91b3b5e702ed6b53546dca6832ca538efc8e9bfc`; `0x422fb0.c`: `03af79a11cfbf8648a4110086d82ad8b77ef79bf` (005F subtypes25/26/28).
- `kr-bulk-roy/<KR_SHA>/functions/0x4bcba0.c`: `928eed3f0f32e1bb120f256fc1b02172cd741f18` (MissionRoom kind1, not Town TYPE1 evidence).
- `kr-bulk-roy/<KR_SHA>/functions/0x830040.c`: `70a25b24145d02aff78a9cff5c4e78d3bf9f9569`; `0x82f660.c`: `e64f47137dce52e535b7f6a88ceb984c71e50c9b`; `0x82f850.c`: `c071ebc3d9992f7c03f77a161d5ceb4adf1e351c`.
- `governance/inspect_tutorial_bounds_resource.py`: `e39cb00a9db90fbbea00844449b4b4da56520fae`.
- Previously committed W3 reports and proofs retain their exact Git blob SHA; do not silently rewrite their historical source snapshots.
