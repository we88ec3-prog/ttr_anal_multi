# S00 Iteration 23 — E76–E79 應用：遠征隊命名、完整／增量角色清單、畫面就緒與新手流程

**日期**：2026-10-31（Asia/Taipei）；**類別**：設計/交接/有界研究審查；**基準**：KR SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。新來源為 [PR #65](https://github.com/we88ec3-prog/ttr_anal_multi/pull/65)（`extra/roy1`，merge `9df86e629d19b688850d5cad4dfda50691513c4e`），完整 E71–E75 前版審查見 [RR0010 原稿審查](S00-20261031-RR0010-EXTRA-ROY1-REVIEW.md)。

**執行界線**：本次從 GitHub 確認 E76～E79 八個新增報告/腳本與 blob；讀取同 KR SHA 已保存的 Ghidra 偽碼作**輔助交叉核對**，沒有原始 Tartaros.bin 供本工作環境獨立重跑 E76 58、E77 69、E78 或 E79 45 項原生位元組斷言。作者報告 PASS 不等於本輪重新執行；Ghidra 派生結果未逐函式正式 native FULL-PASS。**沒有啟動/連接/擷取原 Client 或原版 Server。**

## 1. RR-0010 逐項判定：新進展不能偷換標的

| 原五項驗收 | Iteration 23 有界新資料 | 此時判定 |
| --- | --- | --- |
| (1) Build/SHA、producer、consumer、fields、scene/slot/frame | E76 找到 `CExpeditionPage::ready`；E77 找到有條件 `S2C0xB6→local F4278→role UI`；E79 從 network callback table→Client singleton→index0x2B→`0x4E2730` 將增量角色 consumer 接通。C2S3E +2..5、實際外層 frame/Conn、名單 header 業務值仍 UNKNOWN | **PARTIAL（有新正向靜態鏈）** |
| (2) 真正建立可操作角色的 C2S→S2C accepted/rejected→roster/init、重名/重試/斷線 | E79 確認 app2 / app2B **同一個**角色記錄 pointer cell `0xF94304`，但沒有 original Server 的 3E→4A、33→2B 或 B6/2B 與建角的同交易因果；0x2B 不帶已證的建角結果 enum | **BLOCKED（核心未閉合）** |
| (3) local vs wire/domain 政策分離 | `F4245/F4278/F4261` 皆為本地 event；`F4278` 亦見於 `CPhaseSlot`，不可當 create 專屬；`0x42` 是選既有角色，不是建名 | **有界支持** |
| (4) 不破壞 RR-0002/0007/0008 | PR #65 只加報告/驗證器，既有主責/索引不變；E75 選角場景與 0x26 屬鄰接證據 | **符合研究工作邊界** |
| (5) 可重現證據、缺失/解除條件與交付 | 四份 E76–E79 原稿、檔案 blob、候選 checker；本工作環境**無 KR BIN 重跑**，也沒有 formally submitted RR 審查流程/原版 Server trace | **原稿已交、完整驗收未達** |

**正式結果**：`RR-0010 BLOCKED`、`GAP-CHAR-0003 OPEN`、`SPEC-CHAR-0001/SPEC-FLOW-0001 DRAFT/PARTIAL`。不假冒 `SUBMITTED/ACCEPTED`、T01 FULL-PASS、已可原 Client E2E。原 RR 問的是 **playable-character creation**；新增證據的 **expedition identity name** 是另一個可能的玩家階段。要避免「角色建立成功」的誤名與角色記錄的業務職責混淆。

## 2. 可用於 Server 的五個**獨立、條件式** Client 介面

| 階段 / 方向 | 原生來源摘要 | Server V1 設計行為（尚需契約批准） | 禁止假設 |
| --- | --- | --- | --- |
| Expedition 命名 **C2S 0x003E** | `CExpeditionCreateDialog→0x672180`；inner **48B**，slot0，opcode at +0 u16 LE，寬字元名字 **+6 / 21 WCHAR capacity**，+2..+5 UNKNOWN，`FBA798==0` 才 queue（E73/E78） | 先實作**離線解析/驗證與 DB 命名模型**；界限檢查、寬字元合法性/終止、去重與請求冪等為 Server-owned policy；保留未知 bytes，不拿來作 identity key | 不稱「原版 Server 接受的正式 0x3E 帳號封包」、不定 +2..5 全0、不把失敗 helper return 忽略視為可接受空名稱 |
| Candidate name result **S2C 0x004A** | 在有效 LOGIN/Expedition scene，`0x4C21D0` 讀 signed16 at **+2**→local `F4245`→`0x672570`；**1** 進本地名稱/UI ready，`-1/-2/-3/default` 走不同本地分支（E73/E76） | 在**合成/可關閉 adapter** 中測出不同值可進既有 Client handler 的條件；部署/正式配對待批准。初版內部 Domain return 不把 -1/-2/-3 映射成官方「重名/滿額」 | 未證 original Server 的 `3E→4A` request/reply、最短包外層前提、重複/斷線語意 |
| **S2C app 0x0002** full roster | Header **65B**，名字源 +0x0C 20 UTF-16 units→`F938F2`；每 row **53B** / record slot<=9，`0x4D4150`→record usable +0x5C；每 row 可 send C2S **0x26 3B**，結尾可 send C2S **0x24 2B**（E71/E74） | Server domain 的 FullRosterSnapshot DTO，將原本帳號與遠征隊名字、角色 slot 狀態分離；**只有在欄位證據/安全驗證足夠後**才允許封包 encoder。N=0 也需要合法完整 header | 不能把 65B prefix 全部補0後稱原版格式、不能把讀完 roster 視為 UI ready或 C2S0x26/0x24 必定成功抵達 Server |
| **S2C app 0x002B** incremental roster | E79 正向路由：network callback index2B `0x49337A→0x4943B0`→singleton `0xF8D9E0`→次表 index2B `0x4E2730`；**2+53×N**，row from +2，index<=9；與 app2 指向**同一 pointer cell `0xF94304`** | 定義 `ApplyRosterDelta` 與 `FullRosterSnapshot` 的**同一個版本化資料模型**；以相同 53B row writer 處理更新，禁止臆造 delete/clear 語意。可測同 slot 更新與重複訊息；DB 應 source-of-truth，Client 是投影 | 修正 E72「不同 destination」：**是相同陣列、不同 header/路徑**。app2B 不帶已證建角成功 status；**不可**稱它為 `0x0033`/ `0x003E` 的 ACK |
| **S2C 0x00B6** role UI notification | Base scene handler `0x4B5DD0` 產生本地 `F4278(0)`；`CExpeditionPage` event branch 在 scene/child/record 可達時，從 `0xF94304+slot*0x210` 的 `record+0x5C` 判定 UI/placeholder（E77/E78） | 定義獨立的 `RequestRoleUiRefresh` **候選能力**；先測已存在角色與不存在角色兩種 GUI predicate，不把 B6 和 app2B 綁成必然先後 | B6 handler 沒有本地讀取角色 ID payload；B7 是另一 handler；`F4278` 可從其他 Client 元件發出，**非角色已新增證明** |

### E76 新的 ready 交會

`CExpeditionPage` `0x5A6510` 讀 `F938F2` 非空時寫 `page+0x144=1`，`0x5A65A0` 再依此開/關三個控制的 vtable+0x94；另一條 `F4245(status=1)→0x5A67D0` 成功分支同樣更新 name/UI/flag。**這證明共享 Client-local 變數的兩個初始化入口**，不證可見頁面已建立、正確場景、服務端已保存角色或單一強制封包時序。失敗清除 edit 控制表示可再次輸入，不是自動網路重試；`F4261` 對此頁面是 default，不能拿 E75 的 F4261 當 Page ready。

## 3. 應用於新帳號 → 新手教學的流程拆解（E05/E06 原編號不改）

將現有 E05/E06/E07 具體切分為**設計子狀態**，不增改舊 Gate 編號：

| 階段 | Server-owned 層 | Client-compat bounded wire / UI gate | 完成條件與阻塞 |
| --- | --- | --- | --- |
| E04：登入／伺服器連線後 | 帳號權威；是否已有 ExpeditionProfile / PlayableRoster | 不依賴 WEB 建帳時自動創角；單一帳號資料存在≠ Client 已命名 | 使用原 REQ-0001/2 與 AUTH/NET GAP |
| **E05-A**：沒有 Expedition 名稱 | Server 分開帳號與 Expedition identity，保存 `Uninitialized/Pending/Named` 狀態（建議，非原版政策） | 由 S00 候選 `0x003E` 名稱輸入；N0 時真正對話框可達仍需 RR-0009/T06 | 尚未證空 roster 必自動顯示建名頁 |
| **E05-B**：名稱回應／頁面 ready | Server name validation/reservation/idempotency 可先離線開發；候選 response adapter 不預設啟用 | `0x004A` signed status→F4245；`F938F2`→page+0x144/三控件 | 未證 official `3E↔4A`，status -1/-2/-3 官方業務含義 UNKNOWN |
| **E06-A**：完整角色資料與可操作角色狀態 | 權威 roster / slots / 角色招募狀態（與建名不同）；persist + revision | `app2` full roster、`app2B` delta 寫**同一**角色陣列，`record+0x5C` 之後可能供 UI 讀取 | **未知**是哪個 Client C2S 建立/招募可操作角色、何時要求 2B |
| **E06-B**：角色 UI 展示與同步 | 角色 record 存在與 UI refresh 是不同事件 | 有條件 `S2C0xB6→F4278→角色/placeholder UI`；`0x26/0x24` 是 roster 後 C2S | 不能以 B6 代替 2B 正確資料，不能以 F4278 單獨稱成功 |
| E07+：選角、進入新手教學 | Session owns selection / initial world spawn / quest E00–E26 | **C2S0x42** select existing，場景/教學 `(1001,1)` 另證 | RR-0002/8 及 Scene/Quest GAP 未閉合；不能由上述 ready flag 自動跳關 |

**設計優先順序**：先建立帳號、Expedition 身分與角色模型的乾淨邊界，讓本地 Server 可以安全產生完整/增量**合成 DTO 測試**；再補 Client native scene/Conn/flags；最後才開啟 real-game-client-compat adapter。無實機不等於停止設計，但不能發明未知 wire bytes。

## 4. Server 開發可承接的工作（與 WEB 後台分離）

| Work package | 模組候選 | 先做且不需要原版 Client 的交付 | 原生接入 gate |
| --- | --- | --- | --- |
| **SR23-01** | `Tartaros.Account` / `Tartaros.Persistence` | `AccountId→ExpeditionProfile` 零或單一名稱模型（建議）、UTF-16/Unicode name policy 設計、唯一性、冪等與 rollback；**帳號不等於角色** | `C2S3E` 未確認 bytes 僅進 quarantine/telemetry，encoder/handler 尚不公開 |
| **SR23-02** | `Tartaros.Character` / `Persistence` | `RosterSnapshot`, `RosterDelta`, `RoleRecord`, `revision`、合法 slot 與衝突更新/重播；測 0、1、10 slots / duplicate | Client 2B 只證覆寫 53B record，**無已證刪除**；不得把 delete 定成官方 |
| **SR23-03** | `Tartaros.Protocol` / `Gateway` | 分離 app payload codec、frame、lane/scene admission、adapter feature gates：3E/4A、app2、2B、B6 四個獨立切換 | T02 確認 frame/Conn/scene，原件可驗長度/欄位後才能發 native 封包 |
| **SR23-04** | `Tartaros.Session` / UI integration design | NameReady／RosterHydrated／RoleUiPainted／RoleSelected 四個**獨立**測試觀察點，維持因果 ID 與操作次序，區分 Server 請求與 Client 本地事件 | 不自動使用 F4245/F4278 作 on-wire opcode |
| **SR23-05** | synthetic conformance | 規劃 24 項獨立測試：[Iteration 23 驗收矩陣](S00-20261031-ITERATION-23-ACCEPTANCE.md)，含 malformed、N0/1/10、repeat、reorder、failure/reset、bypass、unknown bytes | 原件/Client 實測未授權，全部 `PLAN_ONLY / NOT_RUN` |
| **SR23-06** | S00/T03/T04/T06/T02 | 指派最短剩餘問題：0x33 招募 action 真正結果、0x3E+2..5、2B/B6 先後與各 state writer、N0 進 create UI、0x42 進場、T02 frame/Conn | 仍以已存 RR-0010 / RR-0009 / RR-0002 去重，若新增不同成果才建正式 RR |

WEB Admin `REQ-0007` 建立的是**玩家帳號**，不要求同步建立 Expedition 名稱或可操作角色；WEB V1 IP+URL 的決定不變。Server V1 內部階段可新增自己的 policy ADR 草稿，但**沒有**在本輪批准原版官方密碼/名稱/角色限制。

## 5. 待辦證據與 formal 台帳的正確落點

1. `REQ-0003`（full roster）與 `REQ-0004`（UI ready）**沿用**，不要因多了一條 app2B 或 B6 就重複創同義 REQ；可在審核後加同版本 `CODE_ANALYSIS` discovery，但正式 REQ validator 要求**已存在 CLM ID 與來源**。E76–E79 目前為 T03 研究原稿/脚本，沒有在本輪 T01 正式建立可引用的新 CLM；不能拿舊 CLM 冒充 E79 的 native 驗證。
2. 「遠征隊身分命名與角色招募」是**不同可測業務成果**；應先在本設計規格標為 **candidate requirement split**，待 T03/T04 對應原生來源/是否與既有 REQ 去重後再正式建立新 `REQ`（需要新的 CLM 來源），而非因 UI 類名就臆造官方政策。
3. `GAP-CHAR-0003` 保持 OPEN，加入「E72 two destinations」被 E79 修正、已確認新 2B ingress + shared record pointer 的研究進度；既存 `RR-0010 BLOCKED` 的原始五項驗收不縮水。需要正式重派時，遵循 `BLOCKED→QUEUED→CLAIMED→IN_PROGRESS→SUBMITTED→IN_REVIEW`，不直接跳 `ACCEPTED`。
4. T03/T01 另有 `T01-RETURN-T03-006-LAYOUT-001 NEEDS_FIX`，不得以 E79 修正自動關閉。原 Client 真實 runtime 只能另經使用者授權；若隔離 Client＋自製 Server 測成功，也不等於官方 Server 原始交易。
5. 本次只更新 S00 設計、DRAFT SPEC、GAP 註記及**規劃測試**；不改獨立 `ttr_server_roy`、原本的 Client byte-level TEST index、正式封包 vector 或 RR status。

**下一個可交付給 Server 開發者的順序：** SR23-01 → SR23-02 → SR23-05（純領域/合成資料）→ SR23-03（僅有界 codec/feature gate）→ SR23-04（內部觀測與狀態機）→ 等 T02/T03 明確界定後再做 real wire adapter。這能持續降低之後實機出 BUG 的風險，同時不把無法證實的官方交易寫死進程式碼。
