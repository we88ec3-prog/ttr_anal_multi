# T01 批次 02：extra/roy3 W3 資源／Field19 BND／Town1 NPC 與 Scene 邊界逐主張驗證

審核日：2026-11-02 Asia/Taipei。審核標準：**R**=pinned resource row/header；**N(partial)**=本人對原始 KR BIN 選定真指令/局部分支核驗；**I**=推論；**S**=相容 Server 設計候選，非原服；**U**=未知。**R 與 N 對不同實體各自成立，不可把 PINNED JSON 當作已完整解碼的原始 STPD 成員。**

本稿只覆核特定 W3 主張，並連結同分支第一批 `T01-REVIEW-BATCH01-000E-LOADING.md`，**不更改 S00 規格、PR102、APPROVED/RR、其他 Task owner、舊稿、不執行/附加/修改 Client 或 Server**；不做負向、重播、重登、併發、故障或壓測。AI／MEF 和連擊核心交 S00。

## 0. 精確 frozen 來源與真正讀取原件

| 來源 | 精確 commit / blob | 內容與本批權重 |
|---|---|---|
| S00 W3 工作卡 `research/handoffs/s00-phindos-mainline-20261102/T01-REVIEW.md` | `017d85c88c2ca4651ed6e309a0c6173ac2cb362f` / `96950f0bf7e9b3eb59712efee2d5f0fccb52776a` | T01 職責、分批與禁令 |
| `RESOURCE-BASELINE.json` | `27c1faf7d` / `5ac883881d3ab0c711ad7c0bdd84c4dd3c2e5cd6` | 限定的 typed resource 資料 |
| `W3-RESULT.md` | `58851e4ea2404f2370e8c4310df7384519fdc80e` / `e9a9c16cd04a93acdbbda1fb623ce18e379858a3` | Town1、九 NPC、map 結構與未知 |
| `W3-RESULT-02-FIELD19-BND.md` | 同上 / `81dba42d96f6d923cbd19f640b0758fe10065adf` | Field19 BND version gate |
| `W3-RESULT-04-RESOURCE-BASELINE-TOWN-SCENE.md` | 同上 / `7ae7e67cf72e31d42f7ef261c6ebeaa5136749d8` | 新 pinned 源、Town scene 尋找界線 |
| `W3-RESULT-05-NPC-SCENE-INTERFACE-BOUNDARIES.md` | 同上 / `6fa66a3ab7b4e6324182604cc7c0689b9eca2ecb` | nested F43D9→001C、spawn/cutscene 區別 |
| 原生以前件 T16-126/127、T09/T07、E41 | W3-05 原文列精確 blob | 本輪**引用前件定位，再重新核選定第一手指令**，不把舊 decompile 全量重作 |

已本人重新唯讀 hash：
- `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `Event.stp`：11,241,597 bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
- `Table.stp`：5,248,784 bytes，SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。
- 原始 PE32/I386、ImageBase 0x400000，`.text` VA0x401000/raw0x400，code VA→raw=`VA−0x400C00`；非 `.text` 不能套此式。

**來源限制非常重要：** pinned `RESOURCE-BASELINE.json` 中 Table 類成員聲明 carrier SHA `ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c`，**不等於這一輪掛載的 `Table.stp` SHA `09e2cc...`**；W3 BND 三件成員則以 `Map/BoundMap.stp` carrier SHA `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8` 釘版，本輪**沒有**該 carrier 原始 bytes。故 T01 只校對 pinned JSON/研究相符與原始 BIN decoder 分派，**不能聲稱本輪已獨立解出兩張 Field19 BND 全層**。更不應以現在手上的別版 Table carrier 無聲替換其來源。

## 1. 各主張逐一核對與 S00 可用界線

| 主張 ID | 來源／第一手證據 | 限定 T01 裁決 | 可用值／不得擅填 |
|---|---|---|---|
| **PHI-W3-01** Town / map / field / case typed IDs | baseline `town1.ID=1, TYPE=1`；`maps 182=town001D/town001.mef/BOUND town001`；`Quest15.field=19`；`Case103.STAGE=19`；`Map191/192` 分別為 `scenario_pathofpindus01/02` | **R（pinned resource）**，未獨立重解確切 Table XML | `TownId1`、`MapSelector182`、`QuestField19`、`CaseId103`、`MapSelector191/192` 分型保存。不能把 19 或 1 當 map ID，也不可把 Town TYPE1 當 controller kind1 |
| **PHI-W3-02** Quest15→117→132 | baseline 的 `quest_rows`：15 Demand16、Town5/giver10338；117 Demand15、Town1/giver10002；至132 Demand131，133 Town2/Demand132。Quest123 與124 均 giver10048 | **R（pinned）**。靜態單一 prerequisite chain，不是 Client 線上自動接受/保存/獎勵時序 | 可作正流程任務資料入口；只有完成 Quest15 的 Server 權威狀態才能考慮117，`Scene15/3` 演出不等於正式完成；無證獎勵及後繼觸發不可填造 |
| **PHI-W3-03** 九個 Town1 NPC | pinned roster 原順序 `10001,10002,10003,10008,10013,10014,10047,10048,10015`；Quest117 giver10002、Quest118/119 giver10047、120 giver10008、123/124 giver10048 | **R 僅資源表 ID/關聯**，沒有一筆的 Town1 dynamic event object／world entity ID／合法 x/y 獨立完成 | 資料模型採 `NpcResourceId` 與 `WorldEntityId` 分離；不可將九個值直接當可點擊 actor IDs 或產生假 spawn |
| **PHI-W3-04** BND header version2 vs Town v0 | baseline pinned `town001.bnd` v0/grid768²/world1536²，`scenario_pathofpindus01/02.bnd` 各 v2/grid768²/world768² 且 distinct SHA | **R：來源釘版資料**；無原 `Map/BoundMap.stp` carrier，**T01 本輪未完成 resource bytes 獨立核對** | 不允許把 Field19 兩個 v2 改標 v0、混用兩張 collision 或使用全通行 fallback；算術比例 0.5/1 cell per unit ≠ 原生座標轉換／合法 spawn |
| **PHI-W3-05** `830040` 版本分派 | **真原生** `83007B..8300C9` 從有效入口連續 objdump：`830080 push1;830082 push34h` 將 0x34B header 讀入 local `EBP-0x38`；`830095 cmp dword[ebp-18h],3`，此 local offset 相對 local header 為 `+0x20`；`83009A je 8300B5`，否則 `83009E E8 BDF5FFFF→82F660`，相等時 `8300B6 E895F7FFFF→82F850` | **N(partial) BIN-first R2 本輪新增確認**，特定分派條件/控制流已見；函式全部 failure/可達性未滿審 | **Header=2 會選 !=3 分派**（當它通過前段 read 與 header 值真為2），但**不等於 `82F660` 已證可讀 version2 的 layers** |
| **PHI-W3-06** 兩 decoder 的確切 request | `82F6C0 push 0x234`、`82F8B1 push 0x534` 本輪讀原生 bytes；W3 對應 stride0x10 vs0x28 與32層引用保存 bulk | **N(partial)** 可確定各該正常分支從 stream 讀 0x234／0x534 bytes；stride/count 計算尚未在本批對所有 loop 狀態逐指令驗 | **絕不**據此宣稱 Field19 v2 32層已成功解壓；需 pinned decoded BND 原件、descriptor/count/offset、合法 tile 及可達坐標正向核對 |
| **PHI-W3-07** `543700` event 欄位身份 | 真 native `543755 66 89 83 F6 00 00 00` => event+F6 WORD selector；`543778 66 89 8B F4 00 00 00` => event+F4 WORD category/kind；此為**event object**，非 S2C07 class6 CNPC actor 或 TownType1 | **N(partial)，限函式可見 writer**；所建物件如何綁 Town1 NPC 未證 | Client event kind / selector 作獨立欄位；**不可以** NPC resource ID 直接填 event selector |
| **PHI-W3-08** `544070` category3 的來源 | 真 native `54409E movzx eax,WORD[esi+F4]`；`5440A5 cmp ax,3`。原始 `544309 mov [eax+10],0xF43D9` 在該 handler 有效分支建 local event，`[eax+18/1C]` 由上游 local 欄位寫入 | **N(partial)**：category3 是分流與**可能建立 F43D9**；不是 category3 必直接呼叫 `544020` | 不能把「不是直接 `544020`」誤寫成「任何 category3 下游都不會 `001C`」；具體 owner/scene/mode gate 仍須滿足 |
| **PHI-W3-09** nested F43D9→001C 下游 | `5B937A cmp eax,105BD`、`5B939A cmp ecx,0x6A7`、`5B93B6 cmp eax,105BF`；`5B9453 mov eax,1Ch`，`5B945C mov cx,[esi+18h]`，`5B9464 mov dx,[esi+1Ch]`，`5B946C jne 5B9553` 測全域 gate；`5B9485 call eax` network manager virtual+10 / 6-byte local app candidate | **N(partial)**：conditional nested event 的直接 app bytes 來源已驗；**尚未證實 Town1 任何 NPC 對應的 nested event** | **有界 schema** `[u16 001C][u16 nestedEvent+18][u16 nestedEvent+1C]`、length6，還需 owner/action gate、FBA798==0、sender/connection；不等於 Socket 已送或 Server 已受理。Quest15 NPC10338 的 `1C 00 03 00 62 28` 僅是給定 kind/selector 的合成例，**不是**真封包或 Town1 值 |
| **PHI-W3-10** NPC／Quest 對話其它分支 | W3-05 引 T16-127：`003F` scene pair 8B candidate、`0036` Quest ID 4B candidate、S2C `0040` state、`0045/46/47` 各不同 consumer，`003C` Town1 producer 未證 | **舊原稿有限路線引用，本輪只為 interface 去重，不重驗所有 callback；PARTIAL** | `NpcClicked`、`QuestCandidateSelected`、`QuestUiSubmitted`、`ScenePair` 分型；不能拿任一 click 當合法完成、不能以 `0036(Q117)` 合成式當已發現官方順序 |
| **PHI-W3-11** `0012` map selector | `4B254D mov ecx,[payload+2]`（DWORD），`4B2557 E8 B4CF0200→4DF510`，前有 map/controller reset helper `5449A0`、`544F50` | **N(partial)** 局部 map consumer；同 map 快取／active scene/role rebind 未完成 | 只把 `MapSelector182` 作資源候選。**沒有證據** S2C0012 會順便選 Town scene、生成九 NPC、合法 spawn 或解除控制 |
| **PHI-W3-12** 正常 Town1 Scene/controller | W3-04 搜索過 `005F` Scenario/Mission/Duel、`0069` Square、`0060` Expedition、`0099/type3` MissionRoom 候選；仍無 `TownId1→active scene RTTI/controller→Map182` 正向鏈 | **U，這是缺口不是「不存在」的否證**。本輪沒有正確完整入口，亦未對所有 scene 建構與回調全圖重新驗 | **不可**用 Square、MissionRoom、controller kind1、TownType1 等數字相似替代；`0038 TownId1` 與 `0014 ready` 也不是足夠的 positive scene+spawn 配對 |
| **PHI-W3-13** cutscene 座標與 spawn | 第一手 Event.stp 原件，raw `0x8C1C3E` 經 XOR-FF 200 bytes 的 SHA256 `2a5ae4ac764beb2aeec7522ab7947914c8af81a5300c36e8831921bcb582474d`，header為 `Quest #15 / Scene #3 - Function pindos_talkevent`；另 Quest15 scene2 raw `0x96883E` SHA `b376fd83fb6a2527897edf39cf9a721677f88479db517778a258ad6e0aa4fe3c` | **N/R：原 Event script token 真實性已證**；完整 script/scene 觸發與 World spawn 未驗 | W3 文本所列 `CreateObject(4,10047,734,744,...)` 視為**演出物件座標**，不可拿當 Town1 NPC 固定位置、玩家出生點、合法回村點。Field19 MapFlow graph (360,372)/(360,276) 也只是圖節點不是 spawn |

## 2. 獨立核驗計數與 byte/ABI

本批針對本工作卡的**新 T01 機器碼與 Event 原件**：**19/19 指令錨點、3/3 direct E8 rel32 目標、2/2 Event XOR-FF script 200-byte SHA256** 通過；實際原件 hash 均吻合。機讀稽核收據見同目錄 `T01-REVIEW-BATCH02-W3-AUDIT.json`。這是選定正向指令與來源 check，**不是**對 `82F660` 全部 layer 解碼、`0x544070` 所有分支、NPC scene/Town1 runtime 或原版官服策略全文 FULL-PASS。

```asm
830095 83 7D E8 03           cmp dword [ebp-18h],3  ; header+20
83009A 74 19                 je 8300B5            ; only value3
83009E E8 BD F5 FF FF        call 82F660          ; non3
8300B6 E8 95 F7 FF FF        call 82F850          ; equals3
82F6C0 68 34 02 00 00        push 234h            ; reader request
82F8B1 68 34 05 00 00        push 534h
543755 66 89 83 F6 00 00 00 mov word [ebx+F6],ax  ; event selector
543778 66 89 8B F4 00 00 00 mov word [ebx+F4],cx  ; event kind
54409E 0F B7 86 F4 00 00 00 movzx eax,word [esi+F4]
5440A5 66 83 F8 03           cmp ax,3
544309 C7 40 10 D9 43 0F 00 mov dword [eax+10],F43D9
5B937A 3D BD 05 01 00        cmp eax,105BDh
5B939A 81 F9 A7 06 00 00     cmp ecx,6A7h
5B93B6 3D BF 05 01 00        cmp eax,105BFh
5B9453 B8 1C 00 00 00        mov eax,1Ch
5B945C 66 8B 4E 18           mov cx,word [esi+18]
5B9464 66 8B 56 1C           mov dx,word [esi+1C]
5B9485 FF D0                 call eax             ; manager vtable+10
```

備註：上述 `5B9453` 是**條件式 nested emitter**。全域 `[FBA798]` gate、兩層 event type/action、stage/scene callback、連線 sender 才決定實際能否排送。**不是**直接 `544020` 這一條 builder，也不能把 nested +18/+1C 與 event object 的 +F4/+F6 當同一記憶體結構。

## 3. 交 S00 的可實作分階段欄位（不是准入/APPROVED）

1. **立即可建 typed resource registry（S00 自決）**：`TownId=1, TownType=1`、`MapSelector=182, MapName=town001D, BoundName=town001`；`QuestField=19, CaseId=103, MapSelector191/192`；Quest15 的 Demand16、Quest117 的 Demand15；九筆 Town1 NPC **資源 ID**。以上是 pinned 靜態資料／尚非 wire 契約。
2. **Field19 BND 載入的保守門檻**：需取得兩個 version2 decoded 原件、驗實際 `0x234` header/stride 0x10、32層 descriptor 的 offsets/count、decompressed byte SHA，依具體 layer0/1 語意找正常可走與可用出生。**目前 v2 ACCEPTABLE=UNKNOWN**，不能關閉 Gate 或套 all-clear。
3. **Town1 scene 入口與角色重新佈建**：正常 Town scene opcode/subtype/RTTI/controller、`Map182` 時序、`0012` reset 後 player actor/alias/controller/NPC roster 何時重新建立仍 UNKNOWN。**禁止使用 005F Scenario / 0069 Square / 0099 MissionRoom 的假替代**。
4. **NPC 點擊／主線交接**：只能依合法 event kind/selector 得到可能的 `001C` local payload；`NPC Resource10002` 並不自然等於 nested event selector10002。須有實際 Town1 event object record、Scene state 及正常 S2C callback 才能提出 Quest117 首包和 UI 承接。不得「看見 NPC＝接到 Quest117」，也不得「Scene15/3 已播＝Quest15 已發獎／持久化」。
5. **S00 loading 的有限擴充**：沿第一批可引用 `23/24` begin/end，本批沒有發現 Town1 專用 category/index 或真實可走 ready；不可預設 loading-end 能修正 Town Scene 缺口。

**停止界線與下一批**：W1/ W2 尚無使用者傳來的精確新研究 commit，此批**未假稱驗收**；只在 S00 提供後按原封存版本接續。若 S00 需要更深的原生 decoder/Quest117 event 某一 positive 路線，再以 exact VA 和 pinned member bytes 定向補證，不重新開 AI/MEF 與連擊核心。正式 S00 SPEC/APPROVED 及 PR102 均不屬 T01 本批權限。

提交目標只有既有 `t01/roy/chatgpt-web`。**結論：R0 + 有界 N(partial)/R2，一部分可交 S00 作資料／Schema 輸入，其餘 UNKNOWN；未建立新的全文 FULL-PASS。**
