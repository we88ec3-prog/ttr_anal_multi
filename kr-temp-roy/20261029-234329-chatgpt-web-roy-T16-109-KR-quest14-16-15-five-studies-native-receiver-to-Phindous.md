# T16-109 — 新手教學 → Quest 14 → Quest 16 → Quest 15 → 馮德斯村：每 Quest 五子研究、接收端分派補證與虛擬 Server 工作項

- 研究日期：2026-10-29T23:43:29.557778+08:00（Asia/Taipei），KR-only、BIN-first，唯讀，不啟動／修改遊戲。
- **本次正式範圍是 T16 教學／任務／村莊**，不屬於任何 T02 登入連線 RR。上一輪錯誤將「RR-0005」用於 T16 的關聯在此明確撤銷；正式 RR-0005 原本是 T02「login result to Connect slot/port」，在 GitHub `main` 仍為 QUEUED，沒有認領、取消或刪除，避免無授權跨 Task 改動。本稿及之後 T16 研究均不以 RR-0005 為識別，無 GitHub 變更。
- GitHub 此次查證基準 `main=43c51f579cada3aa6257eb8467f65af281c3585b`、`t16/roy/chatgpt-web=6723fd0b0da2b870812450ee424574e96c10555b`，`main...T16` ahead=22, behind=0；T16 inbox 無 S00 RR；43 筆 T01 退回仍 `READY_FOR_REVIEW`（不等於通過）。研究材料已同步；**本次未 Commit/Push**。
- 本地原件 `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Event.stp`：11,241,597 bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。`Tartaros.exe` 參照 SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`（之前已驗）。
- PE `.text` VA 0x401000 raw 0x400：`raw=VA-0x400C00`；`.rdata` VA 0xBD2000 raw 0x7D0600；其它 section 不可套 `.text` mapping。GNU objdump 以 `-D -b binary -m i386 -M intel --adjust-vma=0x400C00` 從原始 raw bytes 逐段解碼。原始 bytes SHA256 和完整有限範圍 ASM 於附錄。
- 這是 **T16-108 端到端專題的延伸研究**。T16-108 已證 `QuestInfo` XML 前置以及 `Event.stp` Lua、Quest15 scene 與本地對話過場；本輪新增根植 BIN 的 **S→C 六段 dispatcher 與接收 key-list writer**、修正誤把 scene dispatcher 直接接在 CClient 回呼後的捷徑、提供每個 Quest 五項進度及開發驗收條件。
- **完成定義：** `已確認` 僅指有列出範圍內的第一手 Client 或資源事實；`部分` 指部分路徑成立但未知玩家端實際到達/業務身份；`未閉合` 指必要 Client 線尚缺；`Server 待開發` 指新服務端可自訂實作但必須遵守已證 Client 相容邊界。T01 FULL-PASS、S00 SPEC STABLE、Server 可玩均尚未取得，不虛報「完整進村可玩」。

## 0. 結論與最短主線

```text
教學 TutorialMain.lua Part1 / Part2
    ↓ Tutorial.RequestStartScenario(14) [原始 Lua + 0x4AA4D0 本地發送入口]
Scenario 14 開始與結果 [實際 S→C / 勝利 / Quest14 完成條件尚未知]
    ↓ XML: QuestInfo id 14  (tutorial Isilia, giver/finisher NPC 10027)
Quest 16 (tutorial Pinkopapa, NPC 10027) [QuestInfo Demand id=14]
    ↓ XML: QuestInfo id16 的完成/前置宣告 [正式 server writer/ACK 未知]
Quest 15 (to Phindous, NPC 10338) [QuestInfo Demand id=16]
    ↓ Event SceneList(15,1~4); (15,3) pindos_talkevent
本地 cutscene LoadMap('town001D.map') [與世界場景實際切換不同]
    ↓ T07 Scene 安裝 / ready / 真實角色生成 [尚未連接到 Quest15 回覆]
真正進入馮德斯村 [尚待原版 Client+新 Server 動態可玩驗收]
```

**注意：** QuestInfo `id=14`、Lua `RequestStartScenario(14)`、Event SceneList `(questIdx,sceneIdx)`、Scene type、wire command 數值屬**不同命名空間**。靜態同值不是原生封包／成功事件配對。

### 0.1 每個 Quest 的五個子研究（與用戶回報格式一致）

| Quest | ① 原件/前置/NPC | ② 玩家觸發/本地條件 | ③ C→S producer/發送 | ④ S→C handler/state/UI | ⑤ 完成/後續任務/進村 | 整體 |
|---|---|---|---|---|---|---|
| **14** | **已確認** | **部分**（Tutorial/Scenario14） | **部分**（0x40 本地訊息） | **部分**（共用有界接收鏈；Quest14 身份未知） | **未閉合** | 尚不可宣告 Quest14 完成 |
| **16** | **已確認** | **部分**（NPC 靜態 ID） | **未閉合** | **部分**（共用 parser+record；Quest16 身份未知） | **未閉合** | 尚不可宣告 Quest16 已完成 |
| **15** | **已確認** | **部分**（Quest15 場景/過場靜態） | **未閉合** | **部分**（共用 parser；Quest15 特定結果未知） | **部分**（`town001D.map` cutscene，非世界 ready） | 進村尚未可玩驗收 |

**目前具體研究位置：Quest 14，第④項 S→C 封包進入共用 dispatcher 並寫動態 record 的界面。** 已在本段取得重大有界新增，下一個決定性的 Client 缺口是把 14/16/15 quest-specific S→C payload 與 0x42 record、實際 Quest state writer／NPC/UI consumer 逐筆配對。

## 1. Quest 14 — 教學：伊希莉亞（`튜토리얼-이실리아`）

原始 `Table/QuestInfo.xml` 來自 GitHub source `kr/evidence/5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60.txt`（Git blob `1c86c9ce4f2422f84269ed9eb641202fedb9fb63`，已於 T16-108 全文核對；這裡**未把整份 QuestInfo 2.3MB 搬成本地 SHA 重新驗證**）。實有 `id=14,type=3,town=0,field=18,level=1,giver=10027,finisher=10027,subtype=1,CompleteAction type=1,AcceptAction type=1`，無 `<Demands>`。XML 無 Demands 不等於原 Server 無前置條件。

### Q14-1 原件 / NPC / 前置 — 已確認

- **原始來源**：QuestInfo `<Quest id="14"...>` 實際存在；T16-108 引用 source 原文。`QuestTalk.xml` 完整 4322 條查無同號 id14；不代表 Quest不存在或無任何 NPC 互動。
- **Client 還需分析**：Quest 靜態資料 `0x504740→0xFB114C` reader，NPC 10027 相關場景/對話能否直接引用該 Quest；NPC 身分/初始 spawn 屬 T04/T08。
- **Server 待開發**：角色任務主鍵 14 與 NPC 互動資料模型；`CompleteAction type=1` 的真實 Client/Server semantics 未證，不能自行認作「自動完成」。
- **可驗證界線**：XML 欄位本身已閉合；不等於觸發、完成或收發閉合。

### Q14-2 玩家教學操作 / Scenario14 本地 gate — 部分

- **已確認**：原始 `Event/TutorialMain.lua` Lua 5.1 bytecode Part2 透過 `Tutorial.RequestStartScenario(14)`，再 `Tutorial.IsScenarioEnded(14)` yield 輪詢，並繼續 `PlayAndWaitForScene(1000,10/12/13/14)`；Part1 先有鍵盤/滑鼠/鏡頭與 NPC checkpoint。本地 `tutorial_start` Event scene 為 `(1001,1)` 與 Lua `(1000,...)` 不同。
- **尚未閉合**：初次登入/選角→教學觸發、Scenario14 戰鬥何時認定成功、Scenario14→Quest14 完成有何真實對應、`IsScenarioEnded` 屬何種結束原因。
- **Server 待開發**：新手流程狀態機與可恢復的 checkpoint 策略；關卡成功/失敗後能讓 Lua 不再永遠 yield 的 Client 回覆。不可把本地 `IsScenarioEnded` true 直接當 Quest14 completed。

### Q14-3 原生 C→S 路徑 — 部分

- **已確認**：Lua binding `0x4AB8B8` slot `0xFE187C = 0x4AA4D0`；`0x4AC9E0/0x4ACB70` Lua-to-native wrapper 轉發；`0x4AA4D0` 產生 `WORD 0x0040` + 16-bit caller value、`[0xFBA798]==0` 才呼叫全域 sender `[0xFBA854]` vtable+0x10。T16-107 已追到 `CIocpNetwork` 發送入口與 queue/framing/WSASend 一般機制。
- **尚未閉合**：當次 payload 何時真的排程上線、當前連線 slot/mode；Server 真正如何判定 Scenario14 合法開始；`0x0040` 遠端用途不能超出本地 caller 的範圍。
- **Server 待開發**：依 Client 實際已證 wire framing 建立 Scenario14 request consumer，校驗連線角色/資源/關卡狀態（政策自行定義、非官方復原）；對退出/斷線給出相容結果事件。

### Q14-4 S→C / runtime quest record writer — 部分（本段新增主要內容）

- **已確認的共用路徑**見 §4：`0x4930E0`、`0x48AAD0`、`0x494360`、`0x4FDA30`、`0x4B7EC0`、`0x4C4670`、`0x4B2190`；最後 `0x500110` 與 `0x53D840` 修改客戶端 key-slot/record。若 current scene table 與全域 fallback 路由符合 §4，接收 payload 首 WORD `0x0042` 可進入所述 Scene handler（**這是 Client 的條件性分派規格，不是已證 Server 實際曾發這個封包**）。
- **尚未閉合**：`0x0042` record 內的 `[+2]` 16-bit key 不是已證 Quest14 ID；缺 Server 樣本與 Quest14 status flag 到 UI 的 writer→consumer 對應；`Quest14 complete→16 available` 不是這條 handler 已直接驗收的主張。
- **Server 待開發**：建立有限測試向量，確認 payload 長度/欄位及 Client UI side-effect；在獲得 Quest14 真實鍵映射前，Server 不能擅自發 `42 00 0e 00 ...` 冒充官方 Quest14 結果。

### Q14-5 Quest14 completion → Quest16 unlock — 未閉合

- **已確認**：Quest16 XML `Demand id=14`，所以下游任務資源顯式引用14。
- **未知**：Scenario14成功、Quest14 完成/交付、角色 quest state update、解鎖通知、NPC10027 提示及相關可靠性；缺實際 Server→Client 回覆/Client writer 與結果分支。
- **Server 待開發**：可持久化 Quest14 狀態（未接/進行/目標可完成/已交付）、管理 unlock 16 並發必要 Client-visible 通知；分支含失敗/退出/斷線/重登/重複接取與重複回覆。進行端到端遊玩驗收前保持 **BLOCKED-BY-WIRE/STATE**。

## 2. Quest 16 — 教學：平可爸爸（`튜토리얼-핑코파파`）

QuestInfo 來源欄位：`id=16,type=2,town=0,level=1,giver=10027,finisher=10027,subtype=1`、`Demands/Demand id=14`、`RewardsEtc id=16 → Reward type=2,value=50`。reward type 的實際語意未知。

### Q16-1 原件/前置 — 已確認

- XML 已證 16 的前置宣告為 Quest14；`QuestTalk.xml` 不含同號 16 mapping；NPC 10027 與 Q14 相同，**不能推出兩次互動共用同一 command**。
- Server 需求：任務設定、前置圖與可追蹤的角色完成狀態；不得把資源條件等同已證原版 Server 算法。

### Q16-2 玩家操作/NPC UI — 部分

- 客戶端 `0x5B6C86`（Quest 靜態表查找）→`0x636520`（TalkBoxDialog 子狀態）→`0x596E00` 互動模式，以及 `0x635CA0` 本地兩個列表布林，已在 T16-93/105/106/107 證實是共用 UI/lookup 機制。選取資料 `0x500F90` 來自 Scene-like `+0x5EAC` 容器，不能光因接近 Quest UI 就命名 NPC10027 的 Quest16 接取。
- 待補： NPC 10027 真正 control、選單 mode 0～3 意義、Quest16 item key 來源、按接取/交付時機與失敗分支。
- Server 需求：NPC 問候/可接/可交付清單、與角色 quest 可用性一致的狀態；若無 Client wire 的對話操作不得偽造封包。

### Q16-3 原生 C→S 接取/交付 — 未閉合

- 共用 `CTalkBoxDialog` 在本地 event `0x000F4402` / command identity `0x6A7`、`[0xFBA798]==0` 下可以建立 `WORD 0x0036 + selected record word` 的 4 bytes，再經 vtable+0x10 進入 sender；**但 record word 尚未映射 Quest16 接取命令**。事件 `0x6A8` 支線與 UI 事件無法無條件合併。
- 待補：Quest16 契約實際 request code/length、accept/submit/retry、由誰清掉已提交 flag，是否 NPC interaction 需要先一步 S2C list。
- Server 需求：基於原版 Client 真正會送的 request 設計 request dispatch；在未解之前 `0x36` 只屬本地共同訊息候選，不能寫死 Quest16 ID。

### Q16-4 S→C 更新 Quest16/可接 Quest15 — 部分（共用 Client 結構已證，特定配對未知）

- 已證 runtime key-list 為 `[FAB2A0]+0x5ED0` 20個 WORD（`0x500110`）、記錄 owner `[FAB134]` 的 0x18-byte entry array（`0x53D840`），以及 `0x500E00/0x500950` 資料查找和 `0x635CA0` 的兩個 bool。**這些不是自動已證 Quest16 status bit**。
- 待補：Quest16 key 實際出現在此表時的 ID/key 對應、是否來自 S2C 0x42/其他命令、由 handler 更新哪些 state、UI mode/更新條件及 server 失敗結果。
- Server 需求：統一的 NPC/任務列表或 snapshot sender、順序/去重/錯誤處理、Quest16 status 及 Quest15 unlock UI 反映；線上格式在證實前保持規格 GAP。

### Q16-5 完成/交付→Quest15 unlocked — 未閉合

- XML Quest15 `<Demand id="16" />` 提供**資源前置**。
- 待補：Quest16 是否必須進行 NPC 交付還是自動完成、獎勵與真正 state ACK、Quest15 NPC10338 解鎖順序、回城後 persistence。
- Server 需求：Quest16 完成寫入、Quest15 unlock 決策、角色 scope storage、重送冪等。不要在 Quest16 僅接取後自動標 Quest15 可接，除非 Client/runtime 補證。

## 3. Quest 15 — 前往馮德斯村（`핀더스 마을로`）

QuestInfo 來源欄位 `id=15,type=2,town=5,field=19,level=1,giver=10338,finisher=10338,subtype=1`、`Demands id=16`、`RewardsEtc id=15: (type=2,value=2800);(type=4,value=468)`。**XML 的 town=5 / field=19 不能直接與 `town001D.map` 或 wire scene type 視為相同 namespace。**

### Q15-1 Quest15 前置/原件/場景鍵 — 已確認

- QuestInfo 確認必需資源宣告 `Demand id=16`；Event/SceneList.xml 完整 1687 scenes 中，Quest scene key=15 確有 4 行：`(15,1) Square_Tutorial01`、`(15,2) scenario_tuto1_1`、`(15,3) pindos_talkevent`、`(15,4) scenario_tuto2_1`，四行 `endBehavior=0`。
- 本地 `Event.stp` `pindos_talkevent` **原始 1636 bytes**，SHA256 `79b563be567ef51cce081a8a843eede14962b3bea5bf8af8b69e65c73d0d1b7e`。T16-108 已保存完整原件 source，含 `LoadMap("town001D.map")`, `OpenTalkScene(3, 18/24/20/21)`, `DoProlog(1)`，最後 `RestoreMap()`。
- Server 需求：正確區別 quest id、scene key、世界 map selector、cutscene local map；不要把 SceneList XML 事件表當作 Server 發包清單。

### Q15-2 玩家接取/NPC/場景觸發 — 部分

- NPC10338 是 Quest15 XML giver/finisher；`scenario_tuto1_1` Event scene 也以 `CreateObject(0,10338,...)` 生成劇情 actor。**劇情 CreateObject 不等於世界實際 NPC 已生成**，也不證明 10338 就是特定 UI 控件。
- 本地 `0x565720` SceneList `(questIdx,sceneIdx)` tree reader→`Event/Sequences/<funcName>.seq` 生成/載入；`0x47B5C0` 來源有一個 state `+0x248`，EndCutScene 也能再次使用 scene loader。因此 **不能只憑 565720 被呼叫就說它是 Quest15 首次進村**。
- Server 需求：視 Client 實測時序推動正確場景事件/對話可見性；進場切換要配合 T07 現場 Scene 安裝與角色控制。

### Q15-3 C→S 接取/交付/要求進場 — 未閉合

- 0x0036、0x0040、0x0042 目前**各是不同 context 的本地/條件性訊息候選**，沒有任何一條原生鏈證明其中一個是 Quest15 接取或前往村莊 request。
- 待補：Quest15 玩家選項 callback、NPC/話題選項真實 ID、request payload、同連線順序、超時/拒絕/重試、進村是否另有 Scene transition C→S。
- Server 需求：完成相容 NPC quest accept/complete/scene request 的 wire 契約後，再設計 server handler、資料與驗收測試，不應把 local scene 15/3 作為網路 opcode。

### Q15-4 S→C 可接/進場指令與 Client 狀態 — 部分（共用鏈已追，特定結果未知）

- 共用 S→C dispatcher 到 Client handler 及 `0x500110→0x53D840→0x500E00` 的部分關聯已見 §4，但未找 Quest15 這一筆的真實 opcode/ID/status mapping。
- Scene map/field 的載入與 Quest15 cutscene 不同；`005F type6` 在原版特定情境代表 `CDuelField`，舊修補版「Tutorial」不能用作原始 S2C 規格。
- Server 需求：角色 quest snapshot、NPC可接列表、場景切換權威訊息／ready gating；T02/T07 主責連線與 Scene 並在 S00 整合 SPEC，原始 Client 要求未確認前不得發明 S2C bytes。

### Q15-5 實際世界進入馮德斯村 — 部分，最終驗收未通過

- **已確認本地過場**：`pindos_talkevent()` 在 `Phase1` 後 `LoadMap("town001D.map")`，隨後表演 NPC/角色/相機、`DoProlog(1)`，最終 `RestoreMap()`；這是 temporary Event scene 的資源/鏡頭，不等於世界 `scene ready`。
- **已確認原生世界 Scene 生命週期的共用機制**：`0x4B7D50` 釋放舊 Scene、寫入 `[global+0x5EAC]`，呼叫新 Scene vtable+0x10；`0x4B24F0` reset、`0x4C5930` ready 是其他已證原生函式但未配對 Quest15；T07 名義的建構 `0x4B9090/0x4BBB70` 不能從名字或舊註解直接認定此路徑就是馮德斯世界。
- **尚未閉合**：Quest15 實際 S2C scene/field/role spawn 參數與順序、進村後角色座標、NPC/控制器/區域資料初始化、ready/ACK、連線更換/重登與可能的失敗/拒絕/重試。
- **Server 待開發**：依已證 Client Scene 初始化機制產出相容村莊/角色/NPC/實體資料、保持正確場景類型、進場/重登狀態；以原版未修改 Client 能看見世界角色可移動、與 NPC 互動、無卡 loading 為驗收。**目前證據未滿足完整進村可玩**。

## 4. 本輪新增關鍵原生證據：S→C 真實多層 dispatch → Scene record writer

### 4.1 以 constructor 和指標實際證明五個不同的分派物件/表

1. `0x48AC81/0x48AC9A`：`CClient+0x148` 內嵌接收/transport 子物件首 DWORD 寫 `0xC05AEC`；該 vtable 首 slot `0x4930E0`。**不能把 `0x4930E0` 的 this 直接當 Scene**。
2. `0x48ACAC`：`CClient+0x200` 處另有 vtable `0xC05B04`；其 slot1（`0xC05B08`）是 `0x48AAD0`，**不是 `0x4C4670`**。在 `0x4930E0` 裡 `EDX=[[ECX+0xB8]+4]` 與 `ECX = old_ecx+0xB8`，因 `old_ecx=CClient+0x148`，所以是 `CClient+0x200`。
3. `0x48C027 LEA EAX,[EBX-8]` → `0x48C02A call 0x493170`；`0x493170` 初始化 CClient table 的 **3029 筆、16-byte stride**，預設 `callback=0x494360`、相鄰 flag=0、context=0xBF2375，再覆寫部分 command slots。`0x48AAD0` 確實用 `signed(word cmd)` * 16 查 callback，null 才退回自己的 vtable+0xC。此與 Scene 的 8-byte stride 是不同表。
4. `0x494360` 是 CClient 預設 callback；lazy 初始化 `[0xFD2CF8]` vtable `0xC06EB4`、`0x4B7DC0` 全域8-byte表，之後 `tail jmp [global-vptr+4]`。`0xC06EB8` 原始 RDATA DWORD **是 `0x4FDA30`**。所以 CClient 預設回呼不直接跳 Scene，而是全域表 B?（此處特稱**global fallback table**，不與 Scene 的表 B 混同）。
5. `0x4B7DC0` 為全域 `0xFD2CFC` 初始化 3029 筆 8-byte callback/context，預設 callback `0x4B7EC0`，另有少數 override。對 idx66 的位置 `0xFD2CFC+8*66=0xFD2F0C`，此初始化例程中未見該位置的特殊覆寫，故**初始化狀態是 default**；不代表 runtime 永遠不能被動態覆寫。
6. **全域 default `0x4B7EC0` 與 Scene 安裝有實際 connection**：`0x4B7EC3` 先檢查 `[global+0x5EAC]`，非零時取 Scene object 的 vptr+4 並 tail jmp；零則記錄訊息並返回0。global base `0xFD2CF8` 的 `+0x5EAC` 正是 `0xFD8BA4`。
7. `0x4B7D50` 在新 Scene 安裝時 `0x4B7D5F` 取舊 `[global+5EAC]`，非零時呼叫舊 Scene vtable+0x14/+0，並於 `0x4B7D82` 清空；接著 `0x4B7DA7 mov [global+0x5EAC],EDI`，`0x4B7DBC call [new scene vtable+0x10]`。真正的**當前場景指標 writer／recycle**已被 BIN 證實，並非看字串推斷。
8. 如果 Scene subclass slot+4=`0x4C4670`，則先查 Scene 專屬表 B `[scene+0x5EAC+8*cmd]`，null 才到表 A `[scene+4+8*cmd]` (`0x4FDA30`)；`0x4ADD50` 將表 A 3029 筆初始化，於 `0x4ADF3D` 寫 `[scene+0x214]=0x4B2190`。因 `0x214=4+8*66`，這是 **Scene table A index 66**。CScenarioField `0x4C46F0` 先全部清零表 B 再覆寫 index14/20，故在其初始化狀態 **cmd66 選 A handler 0x4B2190**。其它 Scene subclass 的表 B 是否在執行期覆寫 idx66，需各自驗證。

因此，條件滿足時存在**完整可重現的純 Client 靜態 dispatch path**：

```text
0x804740 dequeue/channel 2 (transport; details in T02/T16-108)
    → 0x4930E0, payload first WORD as command
    → +B8 from TCP subobject = CClient+0x200 vtable 0xC05B04 slot1
    → 0x48AAD0 CClient 16-byte dispatcher
      if command's client slot still default:
    → 0x494360 CClient default
    → 0xFD2CF8 vtable+4 → 0x4FDA30 global 8-byte table
      if command's global slot still default:
    → 0x4B7EC0 global fallback
      if currentScene pointer at 0xFD8BA4 !=0:
    → currentScene vtable+4 → 0x4C4670 for CScenarioField
      if Scene table B[66] ==0:
    → 0x4FDA30 Scene table A[66] → 0x4B2190
    → 0x500110 20-slot key list → 0x53D840 0x18-byte runtime record
```

**嚴格限定**：此鏈是函式指標、constructor 初始化、分派 CFG 條件的**可能到達路徑**，而非實際網路抓包及活場景 snapshot；任何上層 command table 的動態覆寫、scene pointer 為 null、table B 對 index66 的覆寫、parser 長度/類型失敗都能使實際行為不同。這也糾正了 T16-108/歷史 T02「`0x4930E0` 直接場景 `0x4C4670`」的易錯簡寫：中間實際至少經 CClient 16byte表及 global 8byte表兩層。

### 4.2 0x4B2190 中存在原生業務 payload 解析（**不先命名 quest opcode**）

- 回呼參數 `[EBP+8]` 指向 payload；`[EBP+0xC]` 是可用長度。`0x4B21FD movsx ESI,word [payload+2]` → `0x500110` 將此 16-bit key 加入 `FAB2A0+0x5ED0` 20 槽 WORD key list。`0x500110` 先掃描 **是否已有該值**；未命中才尋第一個 0 槽寫入。滿 20 槽無新位址可寫便返回。此是**直接第一次證實的 S2C-side key-list writer**，但 key 是否 Quest ID 未經 handler/UI 配對。
- `0x4B2210` 長度 `<=4` 直接返回；否則 `payload+4` 指向 subtype entries；讀 `entry[1]` 範圍 1..11，採 11-entry 跳表。有些 branch 可能記錄 error 而後繼續，不能單靠長度檢查稱為完整 parser 安全。
- subtypes entry 對 `consumed` 的增量如下（由原機器碼分支/跳表）：1→15, 2→11, 3→15, 4→13, 5→11, 6→13, 7→10, 8→10, 9→9, 10→直接退出, 11→11。
- `0x4B22AA` 再取 payload[2:4] key 與 `[FAB134]` record-owner 指標、單 entry pointer，呼叫 `0x53D840`。其中 `0x53D840` 的 index `word [entry+4]` 比對舊 record+2，沒有相同則 append 0x18 byte entry；更新 `+0x14`=上層 key、`+0x4`=entry[1]、`+0x0`=entry[2]、`+0x2`=word entry[4]、`+0xA`=entry[3]、`+0x10`=entry[6]、`+0xB`=entry[0]；type-specific branch 補上 +6/+8/+C；如果 entry[0]==2，`record+0=0x00FF` 覆寫。不能猜 `record+0x14` 就是 Quest16 completed flag。
- `0x500E00` 透過 `FAB2A0+0x5ED0` 靜態/執行期 key-list 與 `[FAB134]+0x10/+0x14` records 條件性過濾；`0x635CA0` 將兩個 filter 的列表非空轉為 TalkBox 的 B4/B5 旗標。**此證據不證明某個 Task 的完整 Server 應答**，但確有接收/容器/UI gate 的潛在 bridge。

#### 基於 BIN 實際分支的限界偽碼（不作為 Server 真正 parser 規格）

```cpp
// Receiver callback ABI is conditional on upstream currentScene and table routing.
void MaybeSceneCommand0x42(uint8_t* payload, uint32_t available) {
  int16_t key = read_i16_le(payload + 2); // upstream must actually carry >=4 bytes
  RegisterKey_500110(global_FAB2A0, key); // dedup, at most twenty WORDs
  if (available <= 4) return;
  int used = 4;
  const uint8_t* entry = payload + 4;
  while (used < available) {
    const int sub = entry[1];
    const int extras[] = {15,11,15,13,11,13,10,10,9,-1,11};
    if (sub < 1 || sub > 11 || extras[sub-1] < 0) return;
    // Native error branch can log and continue; do not imply memory-safe parsing.
    used += extras[sub-1];
    if (used > available) ReportError_6EDB60();
    if (sub != 9) UpdateRecord_53D840(owner_FAB134,key,entry);
    entry += extras[sub-1];
  }
}
```

### 4.3 重要反證、失敗與資源回收

- `0x4930E0` `len==0` 直接返回；channel!=2 不進此業務分派；若 payload 本身不足兩個 bytes，其讀第一 WORD 的安全保證在上游，不可直接臆測。
- `0x48AAD0` 每個 command 先有 CClient 自身 16-byte table；非預設 callback 可能攔截。對當前 payload 的實際 callback pointer 仍需 snapshot/其他寫入者交叉驗證。
- `0x4B7EC0` Scene 指標為 null 就記錄並返回0（不保證對遊戲有安全兜底）；`0x4B7D50` 安裝前會回收舊 Scene；world transition 前後狀態可能改變同一 command 的實際 handler。
- `0x4C4670` 若 Scene B 有 handler 優先使用；不存在才讀 A；`0x4B2190` 限 Scene A index66 的已證初始化，**不是所有 Scene 必然相同**。
- `0x500110` key list 最多20項，不覆寫滿額條目；0 key 能命中空槽而不一定新增有意義 key；需要測試非零 key 和清空/切場景時序。
- `0x4B2190` subtype10 分支直接返回；subtype越界、長度<=4皆不寫 runtime record。`0x53D840` record 有 append/replace，key 相同會覆寫欄位，不等於 Server 授權或發放獎勵。
- Scenario 14 `IsScenarioEnded(14)` 本地查詢、QuestInfo 14 的 Demand 依賴及 RecordKey 14 之間，沒有來源鏈足以三者畫等號。

## 5. 三 Quest 的 Server 工作拆解與執行/驗收依賴

| 功能（順序為研究優先，不代表原版真正 Server 流程） | 必需補證的 Client 動作及接收 | 新相容 Server 需開發 | 可驗證驗收／目前阻塞 |
|---|---|---|---|
| 首次教學建立 | 角色選中回覆→教程啟動 selector、第一個 Lua 入口 | 角色的 tutorial phase/checkpoint、world spawn 策略、登入後的有限 snapshot | 首次選角色可進教學、舊角色可恢復，缺 S2C 觸發 mapping |
| Scenario 14 開始 | Tutorial RequestStartScenario(14) → 0x40 builder、framing/connection | Scenario start handler、有效性檢查、切到關卡／結果狀態、失敗/退出 | Lua 開始且持續輪詢直到合法結果，缺實際回覆命令與 callback |
| Quest14 完成 | Server result → Client 角色 Quest14/可接16 writer | Quest14 completion、持久化、冪等、Quest16 availability 更新 | Quest14 UI 狀態可見，Quest16 解鎖；缺專用 S2C mapping |
| Quest16 接取/交付 | NPC10027 UI/選項→真實 C2S → S2C ack/cache | NPC list/accept/finish handler、前置 gate、任務獎勵 type2 需欄位查核 | 可接/交付並顯示下一任務；缺真實 opcode/payload |
| Quest15 可接/接取 | NPC10338 真實控制器/選擇→真實 request/response | 解鎖/接取/交付/對話事件關聯、重試 | 在已完成16後才顯示真正可接；缺 Quest15 ID/handler 結合 |
| Quest15 過場 | `(15,3) pindos_talkevent` caller/select 閘 | 依 client 已證 event selector 引導 cutscene；不將本地 LoadMap 當世界 scene | 看到完整本地過場，EndCutScene return 正常；缺 player action→scene key |
| 真正馮德斯村 world enter | T07 Scene type、0x4B7D50 install、reset/ready/actor/NPC/role authoritative state | town world scene packets, actor spawn, movement/interaction, persistence/reconnect | 原版未改 Client 進村可移動且 NPC 可互動；缺世界 scene response 字節與權威 spawn |

### 狀態到後續工作的標準分類

- **Client 待逆向**：Quest14/16/15 的真實 wire opcode/length/fields、NPC input callback、Server result S2C handler 與 Quest UI state writer、Quest15 world scene 進入訊息；Client command 0x42 是否以對應 ID 載入 Quest14/16/15 record。
- **Server 待開發**：登入與教程 phase、Scenario 14 進出與合法結果、Quest14/16/15 的角色狀態/任務前置/NPC列表/獎勵、Quest15 村莊場景快照/角色/對象、斷線冪等持久化。此為新 Server 需求，不是還原官方內部決策。
- **跨功能待整合**：T03 首登選角結果、T02 框架/IOCP、T07 town Scene、T14 戰鬥結果、T15 snapshot/persistence、T06 資源及 T08 人物/控制器，保留各 Task owner 不挪用其研究原稿。
- **待遊玩驗證**：所有結論均離線；原版 Client 無實際 Packet capture、無運作中的相容 Server 成果驗收。**本次不能稱「已實際抵達馮德斯村」。**

## 6. 每個 Quest 五子研究的有界完成條件（後續進度表的嚴格依據）

| Quest/子研究 | 本段真正完成的驗證範圍 | 仍需證明的最小直接邊 | 是否可單獨關閉研究題 |
|---|---|---|---|
| Q14-1 | QuestInfo id14 源值、無 Demands、NPC10027 | NPC runtime 唯一身份 | **資料範圍已證** |
| Q14-2 | Lua Part1/Part2 對 scenario14 的函式順序 | 首登觸發/場景控制與勝利/失敗分歧 | **部分** |
| Q14-3 | 0x40 native builder→send interface 以及共用 transport | scenario14 當次實際上線與接收回覆 | **部分** |
| Q14-4 | 新增有條件到 0x4B2190→0x500110→0x53D840 | Quest14 特定 payload key/結果與 UI writer | **部分** |
| Q14-5 | Quest16 Demand14 XML 依賴 | Quest14 complete/Quest16 unlock 的角色權威事件 | **未閉合** |
| Q16-1 | QuestInfo 16 Demand14/NPC10027 | Server 前置計算策略非 Client 來源 | **資料範圍已證** |
| Q16-2 | TalkBox/Quest map 各具本地 UI gate | NPC10027→Quest16 request upstream | **部分** |
| Q16-3 | 一般 0x36 UI 對話 builder 存在 | Quest16 accept/submit 的真正 builder | **未閉合** |
| Q16-4 | 共用 runtime record/key-filter/UI bool 機制 | Quest16 id/status S2C pairing | **部分** |
| Q16-5 | Quest15 Demand16 XML 依賴 | Quest16 completion ACK→Quest15 available | **未閉合** |
| Q15-1 | QuestInfo15 及 Event SceneList(15,1~4) 完整 | QuestInfo town/field→world namespace relation | **資料範圍已證** |
| Q15-2 | Event NPC10338 / Scene lookup paths | NPC button→scene(15,x) native call | **部分** |
| Q15-3 | 一般 UI/send framework | Quest15 specific C→S/拒絕/timeout | **未閉合** |
| Q15-4 | 共用 S2C Scene dispatcher + dynamic key record | Quest15 approval/scene result writer | **部分** |
| Q15-5 | pindos_talkevent town001D local cutscene; Scene install | S2C world/town scene type+role spawn+ready | **部分，未可玩** |

本稿的停止邊界是：**現有唯讀 KR BIN、Event.stp、公開 XML 足以閉合上述通用 Client 分派與所有純資源依賴，卻無法證明 Server 實際如何回覆 Quest15 與世界進場**；只憑這些資料不應自造封包。下一步須定向原生追查 Quest15 scene trigger、S2C 客戶端 handler 及跨 T07 的 scene/role writer；若仍缺實際連線封包，需原版 Client packet capture／相容 Server 白箱 test harness 才能進行端到端遊玩驗收。

## 7. 三輪深入紀錄（5 個相連子問題，全部檢查但不因單一發現停整段）

| 子問題 | R1 | R2 | R3 | 結束的有界理由 |
|---|---|---|---|---|
| A：Quest14 資源與 Lua 首端 | 重驗 XML、Lua/Scenario14 元件 | 比對 0x4AA4D0/wire sender 及負面證據 | 用新 S2C route 查是否建立 Quest14 id/scene pairing：仍無 | 原件與 Client request 已確認；具體 Quest14 result 需封包/動態 |
| B：Quest14/16 S2C runtime writer | 0x4930E0 callback vs 0x48AAD0 16-byte table | global 8-byte→Scene 8-byte與 0x4B7D50 writer | index66 parser→20-key list及 record writer | 在條件性 Client 解析處形成重大新功能鏈；但 quest ID 語意尚缺 |
| C：Quest16 NPC/UI C2S | 引用 T16-93/106 具體 UI caller | 區分 0x36 與 QuestID 欄位、mode分支 | 反查 Quest16 XML/Talk 對應；沒有同號 QuestTalk | 有界：未見原始 Quest16 accept payload；不得猜 |
| D：Quest15 Event script/scene key | 重驗 SceneList 四行 | 原始 pindos_talkevent hash、LoadMap/DoProlog | 對照 565720/EndCutScene 反例 | 有界：已證本地 Event 並非實際 town 世界切換 |
| E：進村 world／Client receiver | 4B7D50 Scene writer及 release | 0x4B7EC0 global pointer forwarding、CScenarioField 66 註冊 | T07 reset/ready/scene class 與 Quest15 無直接聯結，列 block | Scene lifecycle 已證，缺 Quest15 world S2C/role spawn |

以上每個 R1/R2/R3 表示本次實際執行的**查證/交叉驗證**，部分以 T16-108 的原件及先前已確認的原始 assembly 重新核驗，並非五份獨立的全新發現，也不冒充所有 Task 已完成。

## 8. 附錄 — 本次直接取自 `Tartaros.bin` 的完整有界原始 x86 bytes / assembly

以下均使用二進位原件直接擷取。每項列 half-open `[VA start,VA end)`、raw offset、slice SHA256。`objdump` 對函式外資料或跳表會解成無意義指令；以原始有效控制流為準。表 A/B/Client 3 種物件偏移均分開。

### CClient-ctor-subobjects — VA `0x0048AC76–0x0048ACB8`, raw `0x0008A076–0x0008A0B8`, SHA256 `d05209b6c7290064f9aa27a7a8c95e0e7ae8c092c04b9ebecd17301b8220ed8f`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0048ac76 <.data+0x8a076>:
  48ac76:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  48ac79:	8d 77 08             	lea    esi,[edi+0x8]
  48ac7c:	e8 1f 3e 25 00       	call   0x6deaa0
  48ac81:	8d 87 48 01 00 00    	lea    eax,[edi+0x148]
  48ac87:	e8 f4 96 37 00       	call   0x804380
  48ac8c:	c7 87 00 02 00 00 38 	mov    DWORD PTR [edi+0x200],0xc05b38
  48ac93:	5b c0 00 
  48ac96:	c6 45 fc 07          	mov    BYTE PTR [ebp-0x4],0x7
  48ac9a:	c7 00 ec 5a c0 00    	mov    DWORD PTR [eax],0xc05aec
  48aca0:	c7 07 9c 5a c0 00    	mov    DWORD PTR [edi],0xc05a9c
  48aca6:	c7 06 a4 5a c0 00    	mov    DWORD PTR [esi],0xc05aa4
  48acac:	c7 87 00 02 00 00 04 	mov    DWORD PTR [edi+0x200],0xc05b04
  48acb3:	5b c0 00 
  48acb6:	89 9f        	mov    DWORD PTR [edi+0xbf60],ebx
```

### CClient-transport-callback — VA `0x004930E0–0x00493160`, raw `0x000924E0–0x00092560`, SHA256 `5c7e1b4f2e3b2d473c67ec77dec8065f878ea7b70cd20af90cdae11b45ad89ab`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004930e0 <.data+0x924e0>:
  4930e0:	55                   	push   ebp
  4930e1:	8b ec                	mov    ebp,esp
  4930e3:	51                   	push   ecx
  4930e4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4930e7:	53                   	push   ebx
  4930e8:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  4930eb:	56                   	push   esi
  4930ec:	57                   	push   edi
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
  493137:	8b f8                	mov    edi,eax
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  49313f:	81 ff 00 01 00 00    	cmp    edi,0x100
  493145:	75 0d                	jne    0x493154
  493147:	83 be 8c be 00 00 00 	cmp    DWORD PTR [esi+0xbe8c],0x0
  49314e:	74 04                	je     0x493154
  493150:	c6 45 ff 01          	mov    BYTE PTR [ebp-0x1],0x1
  493154:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  493158:	5f                   	pop    edi
  493159:	5e                   	pop    esi
  49315a:	5b                   	pop    ebx
  49315b:	8b e5                	mov    esp,ebp
  49315d:	5d                   	pop    ebp
  49315e:	c2 10              	ret    0x10
```

### CClient-table-init — VA `0x00493170–0x004932B0`, raw `0x00092570–0x000926B0`, SHA256 `d863fd6906b2a0935d371a6b0d1e17f06f565378e88c055963dc91da2d6b81ad`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00493170 <.data+0x92570>:
  493170:	53                   	push   ebx
  493171:	56                   	push   esi
  493172:	57                   	push   edi
  493173:	bf 60 43 49 00       	mov    edi,0x494360
  493178:	33 db                	xor    ebx,ebx
  49317a:	8d 90 10 02 00 00    	lea    edx,[eax+0x210]
  493180:	be d5 0b 00 00       	mov    esi,0xbd5
  493185:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  49318a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  493190:	89 7a f8             	mov    DWORD PTR [edx-0x8],edi
  493193:	89 5a fc             	mov    DWORD PTR [edx-0x4],ebx
  493196:	89 0a                	mov    DWORD PTR [edx],ecx
  493198:	83 c2 10             	add    edx,0x10
  49319b:	4e                   	dec    esi
  49319c:	75 f2                	jne    0x493190
  49319e:	ba 80 47 49 00       	mov    edx,0x494780
  4931a3:	89 90 98 03 00 00    	mov    DWORD PTR [eax+0x398],edx
  4931a9:	ba b0 43 49 00       	mov    edx,0x4943b0
  4931ae:	89 90 48 10 00 00    	mov    DWORD PTR [eax+0x1048],edx
  4931b4:	ba b0 43 49 00       	mov    edx,0x4943b0
  4931b9:	89 90 c8 03 00 00    	mov    DWORD PTR [eax+0x3c8],edx
  4931bf:	ba b0 43 49 00       	mov    edx,0x4943b0
  4931c4:	89 90 08 04 00 00    	mov    DWORD PTR [eax+0x408],edx
  4931ca:	ba 60 48 49 00       	mov    edx,0x494860
  4931cf:	89 90 38 04 00 00    	mov    DWORD PTR [eax+0x438],edx
  4931d5:	ba 90 4a 49 00       	mov    edx,0x494a90
  4931da:	89 90 48 04 00 00    	mov    DWORD PTR [eax+0x448],edx
  4931e0:	ba d0 4c 49 00       	mov    edx,0x494cd0
  4931e5:	89 90 f8 04 00 00    	mov    DWORD PTR [eax+0x4f8],edx
  4931eb:	ba 50 47 49 00       	mov    edx,0x494750
  4931f0:	89 90 78 09 00 00    	mov    DWORD PTR [eax+0x978],edx
  4931f6:	ba f0 59 49 00       	mov    edx,0x4959f0
  4931fb:	89 90 a8 0f 00 00    	mov    DWORD PTR [eax+0xfa8],edx
  493201:	ba 60 5a 49 00       	mov    edx,0x495a60
  493206:	89 90 28 0f 00 00    	mov    DWORD PTR [eax+0xf28],edx
  49320c:	ba b0 43 49 00       	mov    edx,0x4943b0
  493211:	89 90 08 09 00 00    	mov    DWORD PTR [eax+0x908],edx
  493217:	ba b0 43 49 00       	mov    edx,0x4943b0
  49321c:	89 90 98 04 00 00    	mov    DWORD PTR [eax+0x498],edx
  493222:	ba b0 43 49 00       	mov    edx,0x4943b0
  493227:	89 90 e8 03 00 00    	mov    DWORD PTR [eax+0x3e8],edx
  49322d:	ba b0 43 49 00       	mov    edx,0x4943b0
  493232:	89 90 48 06 00 00    	mov    DWORD PTR [eax+0x648],edx
  493238:	ba b0 43 49 00       	mov    edx,0x4943b0
  49323d:	89 90 a8 04 00 00    	mov    DWORD PTR [eax+0x4a8],edx
  493243:	ba b0 43 49 00       	mov    edx,0x4943b0
  493248:	89 90 c8 04 00 00    	mov    DWORD PTR [eax+0x4c8],edx
  49324e:	ba b0 43 49 00       	mov    edx,0x4943b0
  493253:	89 90 18 15 00 00    	mov    DWORD PTR [eax+0x1518],edx
  493259:	ba b0 43 49 00       	mov    edx,0x4943b0
  49325e:	89 90 d8 04 00 00    	mov    DWORD PTR [eax+0x4d8],edx
  493264:	ba b0 43 49 00       	mov    edx,0x4943b0
  493269:	89 90 18 08 00 00    	mov    DWORD PTR [eax+0x818],edx
  49326f:	ba b0 43 49 00       	mov    edx,0x4943b0
  493274:	89 90 68 08 00 00    	mov    DWORD PTR [eax+0x868],edx
  49327a:	89 b0 9c 03 00 00    	mov    DWORD PTR [eax+0x39c],esi
  493280:	89 88 a0 03 00 00    	mov    DWORD PTR [eax+0x3a0],ecx
  493286:	89 b0 4c 10 00 00    	mov    DWORD PTR [eax+0x104c],esi
  49328c:	89 88 50 10 00 00    	mov    DWORD PTR [eax+0x1050],ecx
  493292:	89 b0 cc 03 00 00    	mov    DWORD PTR [eax+0x3cc],esi
  493298:	89 88 d0 03 00 00    	mov    DWORD PTR [eax+0x3d0],ecx
  49329e:	89 b0 0c 04 00 00    	mov    DWORD PTR [eax+0x40c],esi
  4932a4:	89 88 10 04 00 00    	mov    DWORD PTR [eax+0x410],ecx
  4932aa:	89 b0 3c 04 00 00    	mov    DWORD PTR [eax+0x43c],esi
```

### CClient-table-callsite — VA `0x0048C009–0x0048C038`, raw `0x0008B409–0x0008B438`, SHA256 `b98cedbe63d9c9a199fea4e169858e810043a95301819a813ef1eb872bca7374`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0048c009 <.data+0x8b409>:
  48c009:	8b 83 78 bf 00 00    	mov    eax,DWORD PTR [ebx+0xbf78]
  48c00f:	68 28 5b c0 00       	push   0xc05b28
  48c014:	68 f0 56 c0 00       	push   0xc056f0
  48c019:	50                   	push   eax
  48c01a:	68 fc 56 c0 00       	push   0xc056fc
  48c01f:	e8 dc 1c 26 00       	call   0x6edd00
  48c024:	83 c4 10             	add    esp,0x10
  48c027:	8d 43 f8             	lea    eax,[ebx-0x8]
  48c02a:	e8 41 71 00 00       	call   0x493170
  48c02f:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  48c036:	bf 01          	mov    edi,0x1
```

### CClient-16-byte-dispatch — VA `0x0048AAD0–0x0048AB68`, raw `0x00089ED0–0x00089F68`, SHA256 `8eab8912bc6b3904e9825f1a70c3515570e3655c374fb7bbe07d8fcbb95d4fb4`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0048aad0 <.data+0x89ed0>:
  48aad0:	55                   	push   ebp
  48aad1:	8b ec                	mov    ebp,esp
  48aad3:	83 ec 08             	sub    esp,0x8
  48aad6:	53                   	push   ebx
  48aad7:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  48aada:	0f bf c3             	movsx  eax,bx
  48aadd:	56                   	push   esi
  48aade:	89 45 10             	mov    DWORD PTR [ebp+0x10],eax
  48aae1:	03 c0                	add    eax,eax
  48aae3:	57                   	push   edi
  48aae4:	8b f9                	mov    edi,ecx
  48aae6:	8b 4c c7 0c          	mov    ecx,DWORD PTR [edi+eax*8+0xc]
  48aaea:	8d 34 c7             	lea    esi,[edi+eax*8]
  48aaed:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  48aaf0:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  48aaf3:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  48aaf6:	85 c0                	test   eax,eax
  48aaf8:	75 1b                	jne    0x48ab15
  48aafa:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  48aafd:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  48ab00:	8b 17                	mov    edx,DWORD PTR [edi]
  48ab02:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  48ab05:	53                   	push   ebx
  48ab06:	50                   	push   eax
  48ab07:	51                   	push   ecx
  48ab08:	8b cf                	mov    ecx,edi
  48ab0a:	ff d2                	call   edx
  48ab0c:	5f                   	pop    edi
  48ab0d:	5e                   	pop    esi
  48ab0e:	5b                   	pop    ebx
  48ab0f:	8b e5                	mov    esp,ebp
  48ab11:	5d                   	pop    ebp
  48ab12:	c2 0c 00             	ret    0xc
  48ab15:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  48ab18:	6a 06                	push   0x6
  48ab1a:	68 6c 6c bf 00       	push   0xbf6c6c
  48ab1f:	50                   	push   eax
  48ab20:	e8 99 7d 40 00       	call   0x8928be
  48ab25:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  48ab28:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  48ab2b:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  48ab2e:	83 c4 0c             	add    esp,0xc
  48ab31:	53                   	push   ebx
  48ab32:	51                   	push   ecx
  48ab33:	52                   	push   edx
  48ab34:	8d 8c 38 00 fe ff ff 	lea    ecx,[eax+edi*1-0x200]
  48ab3b:	ff 55 f8             	call   DWORD PTR [ebp-0x8]
  48ab3e:	8b f8                	mov    edi,eax
  48ab40:	81 ff 05 40 00 80    	cmp    edi,0x80004005
  48ab46:	75 15                	jne    0x48ab5d
  48ab48:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  48ab4b:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  48ab4e:	51                   	push   ecx
  48ab4f:	52                   	push   edx
  48ab50:	68 74 6c bf 00       	push   0xbf6c74
  48ab55:	e8 06 30 26 00       	call   0x6edb60
  48ab5a:	83 c4 0c             	add    esp,0xc
  48ab5d:	8b c7                	mov    eax,edi
  48ab5f:	5f                   	pop    edi
  48ab60:	5e                   	pop    esi
  48ab61:	5b                   	pop    ebx
  48ab62:	8b e5                	mov    esp,ebp
  48ab64:	5d                   	pop    ebp
  48ab65:	c2 0c 00             	ret    0xc
```

### CClient-global-default — VA `0x00494360–0x004943AC`, raw `0x00093760–0x000937AC`, SHA256 `0e40b5fca76c816b3677c994d5747405e088be2527a60e66ee39a059e9c8c323`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00494360 <.data+0x93760>:
  494360:	55                   	push   ebp
  494361:	8b ec                	mov    ebp,esp
  494363:	b8 01 00 00 00       	mov    eax,0x1
  494368:	84 05 f4 2c fd 00    	test   BYTE PTR ds:0xfd2cf4,al
  49436e:	75 2c                	jne    0x49439c
  494370:	09 05 f4 2c fd 00    	or     DWORD PTR ds:0xfd2cf4,eax
  494376:	c7 05 f8 2c fd 00 b4 	mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
  49437d:	6e c0 00 
  494380:	c7 05 a4 8b fd 00 00 	mov    DWORD PTR ds:0xfd8ba4,0x0
  494387:	00 00 00 
  49438a:	e8 31 3a 02 00       	call   0x4b7dc0
  49438f:	68 f0 dc bc 00       	push   0xbcdcf0
  494394:	e8 81 df 3f 00       	call   0x89231a
  494399:	83 c4 04             	add    esp,0x4
  49439c:	b9 f8 2c fd 00       	mov    ecx,0xfd2cf8
  4943a1:	a1 f8 2c fd 00       	mov    eax,ds:0xfd2cf8
  4943a6:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4943a9:	5d                   	pop    ebp
  4943aa:	ff e2                	jmp    edx
```

### Global-8-byte-table-init — VA `0x004B7DC0–0x004B7EC0`, raw `0x000B71C0–0x000B72C0`, SHA256 `fa48613974a308ddf6c2eb90bea82195fc9d77023c4c918585f5e6dc6bcb7f32`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004b7dc0 <.data+0xb71c0>:
  4b7dc0:	b8 00 2d fd 00       	mov    eax,0xfd2d00
  4b7dc5:	ba c0 7e 4b 00       	mov    edx,0x4b7ec0
  4b7dca:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4b7dcf:	90                   	nop
  4b7dd0:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  4b7dd3:	89 08                	mov    DWORD PTR [eax],ecx
  4b7dd5:	83 c0 08             	add    eax,0x8
  4b7dd8:	3d a8 8b fd 00       	cmp    eax,0xfd8ba8
  4b7ddd:	7c f1                	jl     0x4b7dd0
  4b7ddf:	c7 05 0c 2d fd 00 00 	mov    DWORD PTR ds:0xfd2d0c,0x4b7f00
  4b7de6:	7f 4b 00 
  4b7de9:	89 0d 10 2d fd 00    	mov    DWORD PTR ds:0xfd2d10,ecx
  4b7def:	c7 05 8c 8b fd 00 c0 	mov    DWORD PTR ds:0xfd8b8c,0x4b8dc0
  4b7df6:	8d 4b 00 
  4b7df9:	89 0d 90 8b fd 00    	mov    DWORD PTR ds:0xfd8b90,ecx
  4b7dff:	c7 05 fc 2f fd 00 50 	mov    DWORD PTR ds:0xfd2ffc,0x4b8f50
  4b7e06:	8f 4b 00 
  4b7e09:	89 0d 00 30 fd 00    	mov    DWORD PTR ds:0xfd3000,ecx
  4b7e0f:	c7 05 44 30 fd 00 90 	mov    DWORD PTR ds:0xfd3044,0x4b9090
  4b7e16:	90 4b 00 
  4b7e19:	89 0d 48 30 fd 00    	mov    DWORD PTR ds:0xfd3048,ecx
  4b7e1f:	c7 05 6c 30 fd 00 60 	mov    DWORD PTR ds:0xfd306c,0x4b9260
  4b7e26:	92 4b 00 
  4b7e29:	89 0d 70 30 fd 00    	mov    DWORD PTR ds:0xfd3070,ecx
  4b7e2f:	c7 05 c4 31 fd 00 20 	mov    DWORD PTR ds:0xfd31c4,0x4b9320
  4b7e36:	93 4b 00 
  4b7e39:	89 0d c8 31 fd 00    	mov    DWORD PTR ds:0xfd31c8,ecx
  4b7e3f:	c7 05 2c 32 fd 00 10 	mov    DWORD PTR ds:0xfd322c,0x4b9410
  4b7e46:	94 4b 00 
  4b7e49:	89 0d 30 32 fd 00    	mov    DWORD PTR ds:0xfd3230,ecx
  4b7e4f:	c7 05 3c 32 fd 00 00 	mov    DWORD PTR ds:0xfd323c,0x4b9500
  4b7e56:	95 4b 00 
  4b7e59:	89 0d 40 32 fd 00    	mov    DWORD PTR ds:0xfd3240,ecx
  4b7e5f:	c7 05 d4 31 fd 00 90 	mov    DWORD PTR ds:0xfd31d4,0x4b9b90
  4b7e66:	9b 4b 00 
  4b7e69:	89 0d d8 31 fd 00    	mov    DWORD PTR ds:0xfd31d8,ecx
  4b7e6f:	c7 05 e4 31 fd 00 60 	mov    DWORD PTR ds:0xfd31e4,0x4b9c60
  4b7e76:	9c 4b 00 
  4b7e79:	89 0d e8 31 fd 00    	mov    DWORD PTR ds:0xfd31e8,ecx
  4b7e7f:	c7 05 d4 34 fd 00 30 	mov    DWORD PTR ds:0xfd34d4,0x4b9d30
  4b7e86:	9d 4b 00 
  4b7e89:	89 0d d8 34 fd 00    	mov    DWORD PTR ds:0xfd34d8,ecx
  4b7e8f:	c7 05 24 2d fd 00 30 	mov    DWORD PTR ds:0xfd2d24,0x4b9630
  4b7e96:	96 4b 00 
  4b7e99:	89 0d 28 2d fd 00    	mov    DWORD PTR ds:0xfd2d28,ecx
  4b7e9f:	c7 05 0c 2e fd 00 70 	mov    DWORD PTR ds:0xfd2e0c,0x4b9770
  4b7ea6:	97 4b 00 
  4b7ea9:	89 0d 10 2e fd 00    	mov    DWORD PTR ds:0xfd2e10,ecx
  4b7eaf:	c7 05 f4 2f fd 00 c0 	mov    DWORD PTR ds:0xfd2ff4,0x4b99c0
  4b7eb6:	99 4b 00 
  4b7eb9:	89 0d f8 2f fd 00    	mov    DWORD PTR ds:0xfd2ff8,ecx
  4b7ebf:	c3                   	ret
```

### Global-fallback-scene-forward — VA `0x004B7EC0–0x004B7EF0`, raw `0x000B72C0–0x000B72F0`, SHA256 `7fc738a143fdfc7844f73f59a5b9417b76ac357eb73a92a1b965213261785d30`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004b7ec0 <.data+0xb72c0>:
  4b7ec0:	55                   	push   ebp
  4b7ec1:	8b ec                	mov    ebp,esp
  4b7ec3:	83 b9 ac 5e 00 00 00 	cmp    DWORD PTR [ecx+0x5eac],0x0
  4b7eca:	74 0e                	je     0x4b7eda
  4b7ecc:	8b 89 ac 5e 00 00    	mov    ecx,DWORD PTR [ecx+0x5eac]
  4b7ed2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7ed4:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b7ed7:	5d                   	pop    ebp
  4b7ed8:	ff e0                	jmp    eax
  4b7eda:	0f bf 4d 10          	movsx  ecx,WORD PTR [ebp+0x10]
  4b7ede:	51                   	push   ecx
  4b7edf:	68 f8 6d c0 00       	push   0xc06df8
  4b7ee4:	e8 77 5c 23 00       	call   0x6edb60
  4b7ee9:	83 c4 08             	add    esp,0x8
  4b7eec:	33 c0                	xor    eax,eax
  4b7eee:	5d                   	pop    ebp
  4b7eef:	c2               	ret    0xc
```

### Scene-install-recycle — VA `0x004B7D50–0x004B7DC0`, raw `0x000B7150–0x000B71C0`, SHA256 `aec02e527925bbab0eb169d2dc72839399cc7c3c9c8b55a43a0945395f8b4525`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004b7d50 <.data+0xb7150>:
  4b7d50:	51                   	push   ecx
  4b7d51:	85 ff                	test   edi,edi
  4b7d53:	75 0a                	jne    0x4b7d5f
  4b7d55:	68 cc 6d c0 00       	push   0xc06dcc
  4b7d5a:	e8 11 5f 23 00       	call   0x6edc70
  4b7d5f:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d65:	85 c9                	test   ecx,ecx
  4b7d67:	74 23                	je     0x4b7d8c
  4b7d69:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d6b:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4b7d6e:	ff d2                	call   edx
  4b7d70:	8b 8e ac 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eac]
  4b7d76:	85 c9                	test   ecx,ecx
  4b7d78:	74 12                	je     0x4b7d8c
  4b7d7a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7d7c:	8b 10                	mov    edx,DWORD PTR [eax]
  4b7d7e:	6a 01                	push   0x1
  4b7d80:	ff d2                	call   edx
  4b7d82:	c7 86 ac 5e 00 00 00 	mov    DWORD PTR [esi+0x5eac],0x0
  4b7d89:	00 00 00 
  4b7d8c:	a1 74 a6 d6 00       	mov    eax,ds:0xd6a674
  4b7d91:	50                   	push   eax
  4b7d92:	8b c8                	mov    ecx,eax
  4b7d94:	8b d0                	mov    edx,eax
  4b7d96:	c1 e9 08             	shr    ecx,0x8
  4b7d99:	51                   	push   ecx
  4b7d9a:	c1 ea 10             	shr    edx,0x10
  4b7d9d:	52                   	push   edx
  4b7d9e:	c1 e8 18             	shr    eax,0x18
  4b7da1:	50                   	push   eax
  4b7da2:	68 e0 6d c0 00       	push   0xc06de0
  4b7da7:	89 be ac 5e 00 00    	mov    DWORD PTR [esi+0x5eac],edi
  4b7dad:	e8 4e 5f 23 00       	call   0x6edd00
  4b7db2:	8b 07                	mov    eax,DWORD PTR [edi]
  4b7db4:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  4b7db7:	83 c4 14             	add    esp,0x14
  4b7dba:	8b cf                	mov    ecx,edi
  4b7dbc:	ff d2                	call   edx
  4b7dbe:	59                   	pop    ecx
  4b7dbf:	c3                   	ret
```

### Scene-vtable-class-init — VA `0x004C46F0–0x004C4745`, raw `0x000C3AF0–0x000C3B45`, SHA256 `4aa757af1b9bd22025f771de26027954c331490419556cbd697da66831bdf905`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004c46f0 <.data+0xc3af0>:
  4c46f0:	8b c6                	mov    eax,esi
  4c46f2:	e8 59 96 fe ff       	call   0x4add50
  4c46f7:	68 a8 5e 00 00       	push   0x5ea8
  4c46fc:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4c4702:	6a 00                	push   0x0
  4c4704:	50                   	push   eax
  4c4705:	c7 06 b4 73 c0 00    	mov    DWORD PTR [esi],0xc073b4
  4c470b:	c7 05 74 a6 d6 00 46 	mov    DWORD PTR ds:0xd6a674,0x53434546
  4c4712:	45 43 53 
  4c4715:	e8 46 a1 3d 00       	call   0x89e860
  4c471a:	b8 75 23 bf 00       	mov    eax,0xbf2375
  4c471f:	89 86 50 5f 00 00    	mov    DWORD PTR [esi+0x5f50],eax
  4c4725:	89 86 20 5f 00 00    	mov    DWORD PTR [esi+0x5f20],eax
  4c472b:	83 c4 0c             	add    esp,0xc
  4c472e:	c7 86 4c 5f 00 00 30 	mov    DWORD PTR [esi+0x5f4c],0x4c5930
  4c4735:	59 4c 00 
  4c4738:	c7 86 1c 5f 00 00 40 	mov    DWORD PTR [esi+0x5f1c],0x436c40
  4c473f:	6c 43 00 
  4c4742:	8b c6                	mov    eax,esi
  4c4744:	c3                   	ret
```

### Scene-8-byte-dispatch — VA `0x004C4670–0x004C46F0`, raw `0x000C3A70–0x000C3AF0`, SHA256 `2deecc04ff570b803612ebcd2157d86b0659367b80cc081f6a10de1a9c8c5223`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004c4670 <.data+0xc3a70>:
  4c4670:	55                   	push   ebp
  4c4671:	8b ec                	mov    ebp,esp
  4c4673:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c4676:	53                   	push   ebx
  4c4677:	56                   	push   esi
  4c4678:	57                   	push   edi
  4c4679:	0f bf f8             	movsx  edi,ax
  4c467c:	8b f1                	mov    esi,ecx
  4c467e:	8b 9c fe ac 5e 00 00 	mov    ebx,DWORD PTR [esi+edi*8+0x5eac]
  4c4685:	85 db                	test   ebx,ebx
  4c4687:	75 17                	jne    0x4c46a0
  4c4689:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c468c:	50                   	push   eax
  4c468d:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4c4690:	50                   	push   eax
  4c4691:	51                   	push   ecx
  4c4692:	8b ce                	mov    ecx,esi
  4c4694:	e8 97 93 03 00       	call   0x4fda30
  4c4699:	5f                   	pop    edi
  4c469a:	5e                   	pop    esi
  4c469b:	5b                   	pop    ebx
  4c469c:	5d                   	pop    ebp
  4c469d:	c2 0c 00             	ret    0xc
  4c46a0:	8b 94 fe b0 5e 00 00 	mov    edx,DWORD PTR [esi+edi*8+0x5eb0]
  4c46a7:	6a 06                	push   0x6
  4c46a9:	68 6c 6c bf 00       	push   0xbf6c6c
  4c46ae:	52                   	push   edx
  4c46af:	e8 0a e2 3c 00       	call   0x8928be
  4c46b4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c46b7:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4c46ba:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4c46bd:	83 c4 0c             	add    esp,0xc
  4c46c0:	50                   	push   eax
  4c46c1:	51                   	push   ecx
  4c46c2:	52                   	push   edx
  4c46c3:	8b ce                	mov    ecx,esi
  4c46c5:	ff d3                	call   ebx
  4c46c7:	8b d8                	mov    ebx,eax
  4c46c9:	81 fb 05 40 00 80    	cmp    ebx,0x80004005
  4c46cf:	75 16                	jne    0x4c46e7
  4c46d1:	8b 84 fe b0 5e 00 00 	mov    eax,DWORD PTR [esi+edi*8+0x5eb0]
  4c46d8:	50                   	push   eax
  4c46d9:	57                   	push   edi
  4c46da:	68 74 6c bf 00       	push   0xbf6c74
  4c46df:	e8 7c 94 22 00       	call   0x6edb60
  4c46e4:	83 c4 0c             	add    esp,0xc
  4c46e7:	5f                   	pop    edi
  4c46e8:	5e                   	pop    esi
  4c46e9:	8b c3                	mov    eax,ebx
  4c46eb:	5b                   	pop    ebx
  4c46ec:	5d                   	pop    ebp
  4c46ed:	c2 0c 00             	ret    0xc
```

### Scene-tableA-fallback — VA `0x004FDA30–0x004FDAB5`, raw `0x000FCE30–0x000FCEB5`, SHA256 `2b0eeca2535073d8cdef8a12cbc17abb286c4c98ddc8aff681f1ec07a533ac40`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004fda30 <.data+0xfce30>:
  4fda30:	55                   	push   ebp
  4fda31:	8b ec                	mov    ebp,esp
  4fda33:	51                   	push   ecx
  4fda34:	56                   	push   esi
  4fda35:	8b f1                	mov    esi,ecx
  4fda37:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4fda3a:	57                   	push   edi
  4fda3b:	0f bf f9             	movsx  edi,cx
  4fda3e:	8b 44 fe 04          	mov    eax,DWORD PTR [esi+edi*8+0x4]
  4fda42:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4fda45:	85 c0                	test   eax,eax
  4fda47:	75 1a                	jne    0x4fda63
  4fda49:	8b 06                	mov    eax,DWORD PTR [esi]
  4fda4b:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4fda4e:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  4fda51:	51                   	push   ecx
  4fda52:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4fda55:	51                   	push   ecx
  4fda56:	52                   	push   edx
  4fda57:	8b ce                	mov    ecx,esi
  4fda59:	ff d0                	call   eax
  4fda5b:	5f                   	pop    edi
  4fda5c:	5e                   	pop    esi
  4fda5d:	8b e5                	mov    esp,ebp
  4fda5f:	5d                   	pop    ebp
  4fda60:	c2 0c 00             	ret    0xc
  4fda63:	8b 4c fe 08          	mov    ecx,DWORD PTR [esi+edi*8+0x8]
  4fda67:	53                   	push   ebx
  4fda68:	6a 06                	push   0x6
  4fda6a:	8d 5c fe 08          	lea    ebx,[esi+edi*8+0x8]
  4fda6e:	68 6c 6c bf 00       	push   0xbf6c6c
  4fda73:	51                   	push   ecx
  4fda74:	e8 45 4e 39 00       	call   0x8928be
  4fda79:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4fda7c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4fda7f:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4fda82:	83 c4 0c             	add    esp,0xc
  4fda85:	52                   	push   edx
  4fda86:	50                   	push   eax
  4fda87:	51                   	push   ecx
  4fda88:	8b ce                	mov    ecx,esi
  4fda8a:	ff 55 fc             	call   DWORD PTR [ebp-0x4]
  4fda8d:	8b f0                	mov    esi,eax
  4fda8f:	81 fe 05 40 00 80    	cmp    esi,0x80004005
  4fda95:	75 11                	jne    0x4fdaa8
  4fda97:	8b 13                	mov    edx,DWORD PTR [ebx]
  4fda99:	52                   	push   edx
  4fda9a:	57                   	push   edi
  4fda9b:	68 74 6c bf 00       	push   0xbf6c74
  4fdaa0:	e8 bb 00 1f 00       	call   0x6edb60
  4fdaa5:	83 c4 0c             	add    esp,0xc
  4fdaa8:	5b                   	pop    ebx
  4fdaa9:	5f                   	pop    edi
  4fdaaa:	8b c6                	mov    eax,esi
  4fdaac:	5e                   	pop    esi
  4fdaad:	8b e5                	mov    esp,ebp
  4fdaaf:	5d                   	pop    ebp
  4fdab0:	c2 0c 00             	ret    0xc
  4fdab3:	cc                   	int3
  4fdab4:	cc                   	int3
```

### Scene-tableA-registration — VA `0x004ADD50–0x004ADDC0`, raw `0x000AD150–0x000AD1C0`, SHA256 `b7638270c9ae44c4b5a28b4d49b9199b5dde10c656ca96ffab24717d920d6abe`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004add50 <.data+0xad150>:
  4add50:	53                   	push   ebx
  4add51:	56                   	push   esi
  4add52:	8d 50 08             	lea    edx,[eax+0x8]
  4add55:	be d5 0b 00 00       	mov    esi,0xbd5
  4add5a:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4add5f:	90                   	nop
  4add60:	c7 42 fc 40 7d 4b 00 	mov    DWORD PTR [edx-0x4],0x4b7d40
  4add67:	89 0a                	mov    DWORD PTR [edx],ecx
  4add69:	83 c2 08             	add    edx,0x8
  4add6c:	4e                   	dec    esi
  4add6d:	75 f1                	jne    0x4add60
  4add6f:	ba 80 fb 4a 00       	mov    edx,0x4afb80
  4add74:	c7 40 34 30 7d 4b 00 	mov    DWORD PTR [eax+0x34],0x4b7d30
  4add7b:	89 48 38             	mov    DWORD PTR [eax+0x38],ecx
  4add7e:	c7 40 3c d0 e4 4a 00 	mov    DWORD PTR [eax+0x3c],0x4ae4d0
  4add85:	89 48 40             	mov    DWORD PTR [eax+0x40],ecx
  4add88:	c7 80 f4 09 00 00 b0 	mov    DWORD PTR [eax+0x9f4],0x4aedb0
  4add8f:	ed 4a 00 
  4add92:	89 88 f8 09 00 00    	mov    DWORD PTR [eax+0x9f8],ecx
  4add98:	c7 40 44 30 f5 4a 00 	mov    DWORD PTR [eax+0x44],0x4af530
  4add9f:	89 48 48             	mov    DWORD PTR [eax+0x48],ecx
  4adda2:	c7 40 54 20 f9 4a 00 	mov    DWORD PTR [eax+0x54],0x4af920
  4adda9:	89 48 58             	mov    DWORD PTR [eax+0x58],ecx
  4addac:	c7 40 04 f0 fa 4a 00 	mov    DWORD PTR [eax+0x4],0x4afaf0
  4addb3:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4addb6:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4addb9:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  4addbc:	c7 40 5c 60    	mov    DWORD PTR [eax+0x5c],0x4afe60
```

### Scene-index66-writer — VA `0x004ADF1D–0x004ADF64`, raw `0x000AD31D–0x000AD364`, SHA256 `300db7ae811c149db51b0faaecefd97173226b6e83d772645acfb211e7dd2d89`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004adf1d <.data+0xad31d>:
  4adf1d:	c7 80 a4 01 00 00 90 	mov    DWORD PTR [eax+0x1a4],0x4b3090
  4adf24:	30 4b 00 
  4adf27:	89 88 a8 01 00 00    	mov    DWORD PTR [eax+0x1a8],ecx
  4adf2d:	c7 80 c4 01 00 00 f0 	mov    DWORD PTR [eax+0x1c4],0x4b1bf0
  4adf34:	1b 4b 00 
  4adf37:	89 88 c8 01 00 00    	mov    DWORD PTR [eax+0x1c8],ecx
  4adf3d:	c7 80 14 02 00 00 90 	mov    DWORD PTR [eax+0x214],0x4b2190
  4adf44:	21 4b 00 
  4adf47:	89 88 18 02 00 00    	mov    DWORD PTR [eax+0x218],ecx
  4adf4d:	c7 80 0c 02 00 00 10 	mov    DWORD PTR [eax+0x20c],0x4b2310
  4adf54:	23 4b 00 
  4adf57:	89 88 10 02 00 00    	mov    DWORD PTR [eax+0x210],ecx
  4adf5d:	c7 80 fc 03 00 00 c0 	mov    DWORD PTR [eax+0x3fc],0x4b23c0
  4adf64:
```

### Scene-index66-parser — VA `0x004B2190–0x004B22D0`, raw `0x000B1590–0x000B16D0`, SHA256 `1b9adff1f9edf103f5df738dd73c350f029a3682f13890d1b74be8d7cbd728dc`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004b2190 <.data+0xb1590>:
  4b2190:	55                   	push   ebp
  4b2191:	8b ec                	mov    ebp,esp
  4b2193:	83 e4 f8             	and    esp,0xfffffff8
  4b2196:	6a ff                	push   0xffffffff
  4b2198:	68 5c 7c 94 00       	push   0x947c5c
  4b219d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b21a3:	50                   	push   eax
  4b21a4:	83 ec 18             	sub    esp,0x18
  4b21a7:	53                   	push   ebx
  4b21a8:	56                   	push   esi
  4b21a9:	57                   	push   edi
  4b21aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b21af:	33 c4                	xor    eax,esp
  4b21b1:	50                   	push   eax
  4b21b2:	8d 44 24 28          	lea    eax,[esp+0x28]
  4b21b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b21bc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b21c3:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b21c6:	8d 46 04             	lea    eax,[esi+0x4]
  4b21c9:	bb 04 00 00 00       	mov    ebx,0x4
  4b21ce:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b21d2:	75 29                	jne    0x4b21fd
  4b21d4:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4b21db:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  4b21e2:	00 
  4b21e3:	e8 78 dc 04 00       	call   0x4ffe60
  4b21e8:	68 00 cf bc 00       	push   0xbccf00
  4b21ed:	e8 28 01 3e 00       	call   0x89231a
  4b21f2:	83 c4 04             	add    esp,0x4
  4b21f5:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b21fc:	ff 
  4b21fd:	0f bf 76 02          	movsx  esi,WORD PTR [esi+0x2]
  4b2201:	bf a0 b2 fa 00       	mov    edi,0xfab2a0
  4b2206:	e8 05 df 04 00       	call   0x500110
  4b220b:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  4b220e:	8b ff                	mov    edi,edi
  4b2210:	3b fb                	cmp    edi,ebx
  4b2212:	0f 86 ae 00 00 00    	jbe    0x4b22c6
  4b2218:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b221c:	0f b6 48 01          	movzx  ecx,BYTE PTR [eax+0x1]
  4b2220:	8d 70 01             	lea    esi,[eax+0x1]
  4b2223:	49                   	dec    ecx
  4b2224:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4b2228:	83 f9 0a             	cmp    ecx,0xa
  4b222b:	0f 87 95 00 00 00    	ja     0x4b22c6
  4b2231:	ff 24 8d e0 22 4b 00 	jmp    DWORD PTR [ecx*4+0x4b22e0]
  4b2238:	83 c0 0f             	add    eax,0xf
  4b223b:	83 c3 0f             	add    ebx,0xf
  4b223e:	eb 1e                	jmp    0x4b225e
  4b2240:	83 c0 0d             	add    eax,0xd
  4b2243:	83 c3 0d             	add    ebx,0xd
  4b2246:	eb 16                	jmp    0x4b225e
  4b2248:	83 c0 0a             	add    eax,0xa
  4b224b:	83 c3 0a             	add    ebx,0xa
  4b224e:	eb 0e                	jmp    0x4b225e
  4b2250:	83 c0 09             	add    eax,0x9
  4b2253:	83 c3 09             	add    ebx,0x9
  4b2256:	eb 06                	jmp    0x4b225e
  4b2258:	83 c0 0b             	add    eax,0xb
  4b225b:	83 c3 0b             	add    ebx,0xb
  4b225e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b2262:	3b df                	cmp    ebx,edi
  4b2264:	76 0d                	jbe    0x4b2273
  4b2266:	68 bc 6c bf 00       	push   0xbf6cbc
  4b226b:	e8 f0 b8 23 00       	call   0x6edb60
  4b2270:	83 c4 04             	add    esp,0x4
  4b2273:	80 3e 09             	cmp    BYTE PTR [esi],0x9
  4b2276:	74 98                	je     0x4b2210
  4b2278:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b227f:	75 29                	jne    0x4b22aa
  4b2281:	b8 01 00 00 00       	mov    eax,0x1
  4b2286:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4b228c:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  4b2290:	e8 fb c9 02 00       	call   0x4dec90
  4b2295:	68 30 ce bc 00       	push   0xbcce30
  4b229a:	e8 7b 00 3e 00       	call   0x89231a
  4b229f:	83 c4 04             	add    esp,0x4
  4b22a2:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b22a9:	ff 
  4b22aa:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b22ad:	0f bf 51 02          	movsx  edx,WORD PTR [ecx+0x2]
  4b22b1:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b22b6:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  4b22ba:	52                   	push   edx
  4b22bb:	50                   	push   eax
  4b22bc:	e8 7f b5 08 00       	call   0x53d840
  4b22c1:	e9 4a ff ff ff       	jmp    0x4b2210
  4b22c6:	33 c0                	xor    eax,eax
  4b22c8:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4b22cc:	64 89 0d 00    	mov    DWORD PTR fs:0x0,ecx
```

### Key-list-writer-20slots — VA `0x00500110–0x00500153`, raw `0x000FF510–0x000FF553`, SHA256 `7eae3ef8339a1b6443d88e2ab6b21f71d181be4a78e6931796eb55f30de17b93`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500110 <.data+0xff510>:
  500110:	33 c0                	xor    eax,eax
  500112:	8d 8f d0 5e 00 00    	lea    ecx,[edi+0x5ed0]
  500118:	53                   	push   ebx
  500119:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  500120:	0f b7 19             	movzx  ebx,WORD PTR [ecx]
  500123:	3b de                	cmp    ebx,esi
  500125:	74 2a                	je     0x500151
  500127:	40                   	inc    eax
  500128:	83 c1 02             	add    ecx,0x2
  50012b:	83 f8 14             	cmp    eax,0x14
  50012e:	7c f0                	jl     0x500120
  500130:	33 c0                	xor    eax,eax
  500132:	8d 8f d0 5e 00 00    	lea    ecx,[edi+0x5ed0]
  500138:	66 83 39 00          	cmp    WORD PTR [ecx],0x0
  50013c:	74 0b                	je     0x500149
  50013e:	40                   	inc    eax
  50013f:	83 c1 02             	add    ecx,0x2
  500142:	83 f8 14             	cmp    eax,0x14
  500145:	7c f1                	jl     0x500138
  500147:	5b                   	pop    ebx
  500148:	c3                   	ret
  500149:	66 89 b4 47 d0 5e 00 	mov    WORD PTR [edi+eax*2+0x5ed0],si
  500150:	00 
  500151:	5b                   	pop    ebx
  500152:	c3                   	ret
```

### Record-0x18-key-and-field-writer — VA `0x0053D840–0x0053D938`, raw `0x0013CC40–0x0013CD38`, SHA256 `7e997fe05eb510028ab06ef413316a76aa569509b1f90a1993770bf4b3bfc8d2`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0053d840 <.data+0x13cc40>:
  53d840:	55                   	push   ebp
  53d841:	8b ec                	mov    ebp,esp
  53d843:	83 ec 18             	sub    esp,0x18
  53d846:	53                   	push   ebx
  53d847:	57                   	push   edi
  53d848:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53d84b:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  53d84e:	2b 4f 10             	sub    ecx,DWORD PTR [edi+0x10]
  53d851:	83 c7 10             	add    edi,0x10
  53d854:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  53d859:	f7 e9                	imul   ecx
  53d85b:	c1 fa 02             	sar    edx,0x2
  53d85e:	8b c2                	mov    eax,edx
  53d860:	c1 e8 1f             	shr    eax,0x1f
  53d863:	03 c2                	add    eax,edx
  53d865:	b9 00 00 00 00       	mov    ecx,0x0
  53d86a:	74 28                	je     0x53d894
  53d86c:	8b 17                	mov    edx,DWORD PTR [edi]
  53d86e:	0f b7 5e 04          	movzx  ebx,WORD PTR [esi+0x4]
  53d872:	83 c2 02             	add    edx,0x2
  53d875:	66 39 1a             	cmp    WORD PTR [edx],bx
  53d878:	74 0c                	je     0x53d886
  53d87a:	41                   	inc    ecx
  53d87b:	83 c2 18             	add    edx,0x18
  53d87e:	3b c8                	cmp    ecx,eax
  53d880:	72 f3                	jb     0x53d875
  53d882:	33 c9                	xor    ecx,ecx
  53d884:	eb 0e                	jmp    0x53d894
  53d886:	8b 07                	mov    eax,DWORD PTR [edi]
  53d888:	8d 0c 49             	lea    ecx,[ecx+ecx*2]
  53d88b:	8d 04 c8             	lea    eax,[eax+ecx*8]
  53d88e:	33 c9                	xor    ecx,ecx
  53d890:	3b c1                	cmp    eax,ecx
  53d892:	75 22                	jne    0x53d8b6
  53d894:	33 d2                	xor    edx,edx
  53d896:	8d 45 e8             	lea    eax,[ebp-0x18]
  53d899:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  53d89c:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  53d89f:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  53d8a2:	89 4d f4             	mov    DWORD PTR [ebp-0xc],ecx
  53d8a5:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  53d8a8:	e8 43 ac 0b 00       	call   0x5f84f0
  53d8ad:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  53d8b0:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  53d8b3:	83 e8 18             	sub    eax,0x18
  53d8b6:	66 8b 4d 0c          	mov    cx,WORD PTR [ebp+0xc]
  53d8ba:	66 89 48 14          	mov    WORD PTR [eax+0x14],cx
  53d8be:	0f b6 56 01          	movzx  edx,BYTE PTR [esi+0x1]
  53d8c2:	66 89 50 04          	mov    WORD PTR [eax+0x4],dx
  53d8c6:	0f b6 4e 02          	movzx  ecx,BYTE PTR [esi+0x2]
  53d8ca:	66 89 08             	mov    WORD PTR [eax],cx
  53d8cd:	0f b7 56 04          	movzx  edx,WORD PTR [esi+0x4]
  53d8d1:	66 89 50 02          	mov    WORD PTR [eax+0x2],dx
  53d8d5:	0f b6 4e 03          	movzx  ecx,BYTE PTR [esi+0x3]
  53d8d9:	88 48 0a             	mov    BYTE PTR [eax+0xa],cl
  53d8dc:	0f b6 56 06          	movzx  edx,BYTE PTR [esi+0x6]
  53d8e0:	89 50 10             	mov    DWORD PTR [eax+0x10],edx
  53d8e3:	0f b6 0e             	movzx  ecx,BYTE PTR [esi]
  53d8e6:	88 48 0b             	mov    BYTE PTR [eax+0xb],cl
  53d8e9:	80 3e 02             	cmp    BYTE PTR [esi],0x2
  53d8ec:	75 08                	jne    0x53d8f6
  53d8ee:	ba ff 00 00 00       	mov    edx,0xff
  53d8f3:	66 89 10             	mov    WORD PTR [eax],dx
  53d8f6:	0f b6 4e 01          	movzx  ecx,BYTE PTR [esi+0x1]
  53d8fa:	49                   	dec    ecx
  53d8fb:	83 f9 0a             	cmp    ecx,0xa
  53d8fe:	0f 87 3b 01 00 00    	ja     0x53da3f
  53d904:	ff 24 8d 48 da 53 00 	jmp    DWORD PTR [ecx*4+0x53da48]
  53d90b:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d90f:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d913:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d917:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d91b:	0f b6 4e 0b          	movzx  ecx,BYTE PTR [esi+0xb]
  53d91f:	0f b7 56 0d          	movzx  edx,WORD PTR [esi+0xd]
  53d923:	49                   	dec    ecx
  53d924:	81 c9 00 01 00 00    	or     ecx,0x100
  53d92a:	c1 e1 10             	shl    ecx,0x10
  53d92d:	0b ca                	or     ecx,edx
  53d92f:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d932:	5f                   	pop    edi
  53d933:	5b                   	pop    ebx
  53d934:	8b e5                	mov    esp,ebp
  53d936:	5d                   	pop    ebp
  53d937:	c2               	ret    0x8
```

### Record-subtype-extra-fields — VA `0x0053D93A–0x0053DA4C`, raw `0x0013CD3A–0x0013CE4C`, SHA256 `16e852f31d5c588e417b1b0db6680980e2a67c65da6d9c0664d9953d80adb371`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0053d93a <.data+0x13cd3a>:
  53d93a:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d93e:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d942:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d946:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d94a:	5f                   	pop    edi
  53d94b:	5b                   	pop    ebx
  53d94c:	8b e5                	mov    esp,ebp
  53d94e:	5d                   	pop    ebp
  53d94f:	c2 08 00             	ret    0x8
  53d952:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d956:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d95a:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d95e:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d962:	0f b7 4e 0b          	movzx  ecx,WORD PTR [esi+0xb]
  53d966:	81 c9 00 00 00 03    	or     ecx,0x3000000
  53d96c:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d96f:	5f                   	pop    edi
  53d970:	5b                   	pop    ebx
  53d971:	8b e5                	mov    esp,ebp
  53d973:	5d                   	pop    ebp
  53d974:	c2 08 00             	ret    0x8
  53d977:	0f b6 56 06          	movzx  edx,BYTE PTR [esi+0x6]
  53d97b:	89 50 10             	mov    DWORD PTR [eax+0x10],edx
  53d97e:	0f b6 4e 08          	movzx  ecx,BYTE PTR [esi+0x8]
  53d982:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d986:	0f b6 56 07          	movzx  edx,BYTE PTR [esi+0x7]
  53d98a:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d98e:	0f b6 4e 09          	movzx  ecx,BYTE PTR [esi+0x9]
  53d992:	0f b7 56 0b          	movzx  edx,WORD PTR [esi+0xb]
  53d996:	49                   	dec    ecx
  53d997:	81 c9 00 04 00 00    	or     ecx,0x400
  53d99d:	c1 e1 10             	shl    ecx,0x10
  53d9a0:	0b ca                	or     ecx,edx
  53d9a2:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d9a5:	5f                   	pop    edi
  53d9a6:	5b                   	pop    ebx
  53d9a7:	8b e5                	mov    esp,ebp
  53d9a9:	5d                   	pop    ebp
  53d9aa:	c2 08 00             	ret    0x8
  53d9ad:	8b 4e 07             	mov    ecx,DWORD PTR [esi+0x7]
  53d9b0:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d9b3:	5f                   	pop    edi
  53d9b4:	5b                   	pop    ebx
  53d9b5:	8b e5                	mov    esp,ebp
  53d9b7:	5d                   	pop    ebp
  53d9b8:	c2 08 00             	ret    0x8
  53d9bb:	0f b6 56 08          	movzx  edx,BYTE PTR [esi+0x8]
  53d9bf:	66 89 50 06          	mov    WORD PTR [eax+0x6],dx
  53d9c3:	0f b6 4e 07          	movzx  ecx,BYTE PTR [esi+0x7]
  53d9c7:	66 89 48 08          	mov    WORD PTR [eax+0x8],cx
  53d9cb:	0f b6 56 09          	movzx  edx,BYTE PTR [esi+0x9]
  53d9cf:	0f b7 4e 0b          	movzx  ecx,WORD PTR [esi+0xb]
  53d9d3:	4a                   	dec    edx
  53d9d4:	81 ca 00 01 00 00    	or     edx,0x100
  53d9da:	c1 e2 10             	shl    edx,0x10
  53d9dd:	0b d1                	or     edx,ecx
  53d9df:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  53d9e2:	5f                   	pop    edi
  53d9e3:	5b                   	pop    ebx
  53d9e4:	8b e5                	mov    esp,ebp
  53d9e6:	5d                   	pop    ebp
  53d9e7:	c2 08 00             	ret    0x8
  53d9ea:	0f b6 56 08          	movzx  edx,BYTE PTR [esi+0x8]
  53d9ee:	66 89 50 06          	mov    WORD PTR [eax+0x6],dx
  53d9f2:	0f b6 4e 07          	movzx  ecx,BYTE PTR [esi+0x7]
  53d9f6:	66 89 48 08          	mov    WORD PTR [eax+0x8],cx
  53d9fa:	0f b6 56 09          	movzx  edx,BYTE PTR [esi+0x9]
  53d9fe:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  53da01:	5f                   	pop    edi
  53da02:	5b                   	pop    ebx
  53da03:	8b e5                	mov    esp,ebp
  53da05:	5d                   	pop    ebp
  53da06:	c2 08 00             	ret    0x8
  53da09:	0f b6 4e 08          	movzx  ecx,BYTE PTR [esi+0x8]
  53da0d:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53da11:	0f b6 56 07          	movzx  edx,BYTE PTR [esi+0x7]
  53da15:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53da19:	0f b6 4e 09          	movzx  ecx,BYTE PTR [esi+0x9]
  53da1d:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53da20:	5f                   	pop    edi
  53da21:	5b                   	pop    ebx
  53da22:	8b e5                	mov    esp,ebp
  53da24:	5d                   	pop    ebp
  53da25:	c2 08 00             	ret    0x8
  53da28:	0f b6 56 0a          	movzx  edx,BYTE PTR [esi+0xa]
  53da2c:	66 89 50 06          	mov    WORD PTR [eax+0x6],dx
  53da30:	0f b6 4e 09          	movzx  ecx,BYTE PTR [esi+0x9]
  53da34:	66 89 48 08          	mov    WORD PTR [eax+0x8],cx
  53da38:	0f b7 56 07          	movzx  edx,WORD PTR [esi+0x7]
  53da3c:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  53da3f:	5f                   	pop    edi
  53da40:	5b                   	pop    ebx
  53da41:	8b e5                	mov    esp,ebp
  53da43:	5d                   	pop    ebp
  53da44:	c2 08 00             	ret    0x8
  53da47:	90                   	nop
  53da48:	0b d9                	or     ebx,ecx
  53da4a:	53                   	push   ebx
	...
```

### QuestUI-filter-500e00 — VA `0x00500E56–0x00500F65`, raw `0x00100256–0x00100365`, SHA256 `ad1a8a64f833f53960a7ff4f3792df4aa5c465aa3475e11582c0c8973514e27d`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500e56 <.data+0x100256>:
  500e56:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  500e59:	05 d0 5e 00 00       	add    eax,0x5ed0
  500e5e:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  500e62:	c7 44 24 14 14 00 00 	mov    DWORD PTR [esp+0x14],0x14
  500e69:	00 
  500e6a:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  500e6e:	0f b7 39             	movzx  edi,WORD PTR [ecx]
  500e71:	66 85 ff             	test   di,di
  500e74:	0f 84 e4 00 00 00    	je     0x500f5e
  500e7a:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  500e7d:	8b b2 ac 5e 00 00    	mov    esi,DWORD PTR [edx+0x5eac]
  500e83:	8d 44 24 18          	lea    eax,[esp+0x18]
  500e87:	0f bf df             	movsx  ebx,di
  500e8a:	50                   	push   eax
  500e8b:	8d 44 24 20          	lea    eax,[esp+0x20]
  500e8f:	8b ce                	mov    ecx,esi
  500e91:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  500e95:	e8 86 2e 00 00       	call   0x503d20
  500e9a:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  500e9d:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  500ea1:	3b c6                	cmp    eax,esi
  500ea3:	0f 84 b5 00 00 00    	je     0x500f5e
  500ea9:	83 c0 10             	add    eax,0x10
  500eac:	0f 84 ac 00 00 00    	je     0x500f5e
  500eb2:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  500eb5:	39 48 2c             	cmp    DWORD PTR [eax+0x2c],ecx
  500eb8:	0f 85 a0 00 00 00    	jne    0x500f5e
  500ebe:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  500ec5:	75 29                	jne    0x500ef0
  500ec7:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  500ece:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  500ed5:	00 
  500ed6:	e8 b5 dd fd ff       	call   0x4dec90
  500edb:	68 30 ce bc 00       	push   0xbcce30
  500ee0:	e8 35 14 39 00       	call   0x89231a
  500ee5:	83 c4 04             	add    esp,0x4
  500ee8:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  500eef:	ff 
  500ef0:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  500ef5:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  500ef8:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  500efb:	3b c1                	cmp    eax,ecx
  500efd:	74 18                	je     0x500f17
  500eff:	90                   	nop
  500f00:	66 39 78 14          	cmp    WORD PTR [eax+0x14],di
  500f04:	75 0a                	jne    0x500f10
  500f06:	66 8b 50 08          	mov    dx,WORD PTR [eax+0x8]
  500f0a:	66 3b 50 06          	cmp    dx,WORD PTR [eax+0x6]
  500f0e:	7c 4e                	jl     0x500f5e
  500f10:	83 c0 18             	add    eax,0x18
  500f13:	3b c1                	cmp    eax,ecx
  500f15:	75 e9                	jne    0x500f00
  500f17:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  500f1a:	8b b0 ac 5e 00 00    	mov    esi,DWORD PTR [eax+0x5eac]
  500f20:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  500f24:	51                   	push   ecx
  500f25:	8d 44 24 24          	lea    eax,[esp+0x24]
  500f29:	8b ce                	mov    ecx,esi
  500f2b:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  500f2f:	e8 ec 2d 00 00       	call   0x503d20
  500f34:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  500f38:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500f3b:	74 05                	je     0x500f42
  500f3d:	83 c0 10             	add    eax,0x10
  500f40:	eb 02                	jmp    0x500f44
  500f42:	33 c0                	xor    eax,eax
  500f44:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  500f48:	85 c0                	test   eax,eax
  500f4a:	74 12                	je     0x500f5e
  500f4c:	83 78 04 02          	cmp    DWORD PTR [eax+0x4],0x2
  500f50:	74 0c                	je     0x500f5e
  500f52:	8b 7d 10             	mov    edi,DWORD PTR [ebp+0x10]
  500f55:	8d 44 24 18          	lea    eax,[esp+0x18]
  500f59:	e8 b2 2d f4 ff       	call   0x443d10
  500f5e:	83 44 24 10 02       	add    DWORD PTR [esp+0x10],0x2
  500f63:	ff 4c            	dec    DWORD PTR [esp+0x14]
```

### Dialog-quest-consumer-635ca0 — VA `0x00635CA0–0x00635E40`, raw `0x002350A0–0x00235240`, SHA256 `1fa87269a7dade8b75541a046d613e8a2086c20b6322407c486f59495cb67815`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00635ca0 <.data+0x2350a0>:
  635ca0:	55                   	push   ebp
  635ca1:	8b ec                	mov    ebp,esp
  635ca3:	6a ff                	push   0xffffffff
  635ca5:	68 04 8a 94 00       	push   0x948a04
  635caa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  635cb0:	50                   	push   eax
  635cb1:	83 ec 40             	sub    esp,0x40
  635cb4:	53                   	push   ebx
  635cb5:	56                   	push   esi
  635cb6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  635cbb:	33 c5                	xor    eax,ebp
  635cbd:	50                   	push   eax
  635cbe:	8d 45 f4             	lea    eax,[ebp-0xc]
  635cc1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  635cc7:	33 f6                	xor    esi,esi
  635cc9:	39 b7 b8 00 00 00    	cmp    DWORD PTR [edi+0xb8],esi
  635ccf:	0f 84 1f 02 00 00    	je     0x635ef4
  635cd5:	89 75 b4             	mov    DWORD PTR [ebp-0x4c],esi
  635cd8:	89 75 b8             	mov    DWORD PTR [ebp-0x48],esi
  635cdb:	89 75 bc             	mov    DWORD PTR [ebp-0x44],esi
  635cde:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  635ce1:	89 75 c4             	mov    DWORD PTR [ebp-0x3c],esi
  635ce4:	89 75 c8             	mov    DWORD PTR [ebp-0x38],esi
  635ce7:	89 75 cc             	mov    DWORD PTR [ebp-0x34],esi
  635cea:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635cee:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  635cf5:	75 21                	jne    0x635d18
  635cf7:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  635cfe:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  635d02:	e8 59 a1 ec ff       	call   0x4ffe60
  635d07:	68 00 cf bc 00       	push   0xbccf00
  635d0c:	e8 09 c6 25 00       	call   0x89231a
  635d11:	83 c4 04             	add    esp,0x4
  635d14:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635d18:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  635d1e:	8d 45 b4             	lea    eax,[ebp-0x4c]
  635d21:	50                   	push   eax
  635d22:	51                   	push   ecx
  635d23:	68 a0 b2 fa 00       	push   0xfab2a0
  635d28:	e8 23 ac ec ff       	call   0x500950
  635d2d:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  635d34:	75 21                	jne    0x635d57
  635d36:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  635d3d:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  635d41:	e8 1a a1 ec ff       	call   0x4ffe60
  635d46:	68 00 cf bc 00       	push   0xbccf00
  635d4b:	e8 ca c5 25 00       	call   0x89231a
  635d50:	83 c4 04             	add    esp,0x4
  635d53:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635d57:	8b 87 84 00 00 00    	mov    eax,DWORD PTR [edi+0x84]
  635d5d:	8d 55 c4             	lea    edx,[ebp-0x3c]
  635d60:	52                   	push   edx
  635d61:	50                   	push   eax
  635d62:	68 a0 b2 fa 00       	push   0xfab2a0
  635d67:	e8 94 b0 ec ff       	call   0x500e00
  635d6c:	8b 4d b4             	mov    ecx,DWORD PTR [ebp-0x4c]
  635d6f:	3b 4d b8             	cmp    ecx,DWORD PTR [ebp-0x48]
  635d72:	8b 45 c4             	mov    eax,DWORD PTR [ebp-0x3c]
  635d75:	0f 95 c2             	setne  dl
  635d78:	3b 45 c8             	cmp    eax,DWORD PTR [ebp-0x38]
  635d7b:	88 97 b4 00 00 00    	mov    BYTE PTR [edi+0xb4],dl
  635d81:	0f 95 c1             	setne  cl
  635d84:	88 8f b5 00 00 00    	mov    BYTE PTR [edi+0xb5],cl
  635d8a:	89 75 d4             	mov    DWORD PTR [ebp-0x2c],esi
  635d8d:	89 75 d8             	mov    DWORD PTR [ebp-0x28],esi
  635d90:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  635d93:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  635d97:	8b 87 b8 00 00 00    	mov    eax,DWORD PTR [edi+0xb8]
  635d9d:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  635da0:	2b 48 40             	sub    ecx,DWORD PTR [eax+0x40]
  635da3:	b8 39 8e e3 38       	mov    eax,0x38e38e39
  635da8:	f7 e9                	imul   ecx
  635daa:	c1 fa 03             	sar    edx,0x3
  635dad:	8b c2                	mov    eax,edx
  635daf:	c1 e8 1f             	shr    eax,0x1f
  635db2:	03 c2                	add    eax,edx
  635db4:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  635db7:	0f 84 82 00 00 00    	je     0x635e3f
  635dbd:	89 75 ec             	mov    DWORD PTR [ebp-0x14],esi
  635dc0:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  635dc3:	8b 97 b8 00 00 00    	mov    edx,DWORD PTR [edi+0xb8]
  635dc9:	8b 5a 40             	mov    ebx,DWORD PTR [edx+0x40]
  635dcc:	03 5d ec             	add    ebx,DWORD PTR [ebp-0x14]
  635dcf:	53                   	push   ebx
  635dd0:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  635dd3:	e8 c8 e5 ee ff       	call   0x5243a0
  635dd8:	85 c0                	test   eax,eax
  635dda:	74 5a                	je     0x635e36
  635ddc:	8b 03                	mov    eax,DWORD PTR [ebx]
  635dde:	39 45 e8             	cmp    DWORD PTR [ebp-0x18],eax
  635de1:	7d 03                	jge    0x635de6
  635de3:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  635de6:	8d 45 f0             	lea    eax,[ebp-0x10]
  635de9:	3b c6                	cmp    eax,esi
  635deb:	73 2d                	jae    0x635e1a
  635ded:	8b c8                	mov    ecx,eax
  635def:	39 4d d4             	cmp    DWORD PTR [ebp-0x2c],ecx
  635df2:	77 26                	ja     0x635e1a
  635df4:	8b d8                	mov    ebx,eax
  635df6:	2b 5d d4             	sub    ebx,DWORD PTR [ebp-0x2c]
  635df9:	c1 fb 02             	sar    ebx,0x2
  635dfc:	3b 75 dc             	cmp    esi,DWORD PTR [ebp-0x24]
  635dff:	75 0b                	jne    0x635e0c
  635e01:	8d 45 d4             	lea    eax,[ebp-0x2c]
  635e04:	e8 a7 8c ea ff       	call   0x4deab0
  635e09:	8b 75 d8             	mov    esi,DWORD PTR [ebp-0x28]
  635e0c:	85 f6                	test   esi,esi
  635e0e:	74 20                	je     0x635e30
  635e10:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  635e13:	8b 04 9a             	mov    eax,DWORD PTR [edx+ebx*4]
  635e16:	89 06                	mov    DWORD PTR [esi],eax
  635e18:	eb 16                	jmp    0x635e30
  635e1a:	3b 75 dc             	cmp    esi,DWORD PTR [ebp-0x24]
  635e1d:	75 0b                	jne    0x635e2a
  635e1f:	8d 45 d4             	lea    eax,[ebp-0x2c]
  635e22:	e8 89 8c ea ff       	call   0x4deab0
  635e27:	8b 75 d8             	mov    esi,DWORD PTR [ebp-0x28]
  635e2a:	85 f6                	test   esi,esi
  635e2c:	74 02                	je     0x635e30
  635e2e:	89 1e                	mov    DWORD PTR [esi],ebx
  635e30:	83 c6 04             	add    esi,0x4
  635e33:	89 75 d8             	mov    DWORD PTR [ebp-0x28],esi
  635e36:	83 45 ec 24          	add    DWORD PTR [ebp-0x14],0x24
  635e3a:	ff 4d e4             	dec    DWORD PTR [ebp-0x1c]
  635e3d:	75 84                	jne    0x635dc3
  635e3f:	8b               	mov    ebx,DWORD PTR [ebp-0x2c]
```

## 9. Sources / re-verification

- 原始 BIN, Event.stp 及 `T16-108-SceneList-native-extracted.xml` 保存在目前容器；Event.stp extraction XML 為 T16-108 依 BIN native EX v1 codec 驗證。
- 原始 QuestInfo.xml GitHub main URL：`https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/kr/evidence/5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60.txt`。
- QuestTalk.xml GitHub main URL：`https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/kr/evidence/b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28.txt`。
- 完整上一段原稿 `20261029-232224-chatgpt-web-roy-T16-108-KR-tutorial-quest14-quest16-quest15-to-Phindous-end-to-end.md`：包括原始 Event scene Lua source 全文、TutorialMain.lua Part1/Part2 Lua opcode 指令、四個 script full bytes、QuestInfo/QuestTalk loader、TalkBoxDialog、send/receive/場景安裝 22 組原始 ASM；本報告在本文提供本次新確認的 20 組完整有界 ASM。**若需整個 108/109 資源原文，保留兩份原稿原始文件，不覆寫歷史。**
- 遠端 T16 先前原稿見 `t16/roy/chatgpt-web:kr-temp-roy/20261028-231937-chatgpt-web-roy-T16-102-KR-record-handler-registration-and-subtype-parser.md` 與 T16-105；T02 以前對 `0x4930E0` 的局部描述若省略 0x48AAD0/0x494360/global table，需按本次 raw disassembly 限定 scope。
- 研究結束沒有 GitHub 提交／推送／RR status 變動；沒有原始 Server packet capture、相容 Server 建置或實際遊戲操作。因此任何 `可玩完成` 均標 `未驗收`。
