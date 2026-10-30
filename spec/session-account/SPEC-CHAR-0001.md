# SPEC-CHAR-0001 — KR command 2 角色清單有限契約

**DRAFT / PARTIAL**｜KR SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。資料形狀僅在有效資源/狀態且路徑進入 0x4B7F00 角色迴圈時適用。

共享 dispatch handler index 2 對應這個消費者。完整 payload = **65-byte prefix + 53-byte records**；第一筆起點 +65；完整筆數為 floor((payload_len-65)/53)。**另一個 0x4E2730 consumer 用的是 2-byte prefix**，尚未確認命令號，不可混用。64-byte 以下不代表原版會安全拒絕，因為此前已有 header 讀取。

| Record offset | 有限 Client 消費 | 未知 |
|---|---|---|
| +0 | NUL 終止 UTF-16 name copy | 名稱政策/容量防護 |
| +0x2A | u32 → UI+8 | 正式業務意義 |
| +0x2E | u8 ID（觀察比較 <=9 且有效目標指標），→ UI+4 | 官方合法 ID 集合及去重 |
| +0x2F | u8 → UI+0xD4 | 業務意義 |
| +0x30 | u8 → UI+0xDC | 業務意義 |
| +0x31 | u32 → UI+0x50 | 業務意義 |

0x4D4150 對有效記錄寫入 UI+0x5C=1，只證明此記錄可用旗標，**不代表畫面刷新、成功選角或世界轉場**。清單後還會有初始化請求（包含 26+ID），回覆配對不完整。選角 command42 的完整請求/回覆仍缺。

`conformance/character/` 為人造記錄格式的測試，不是真實回覆或角色合法性。保守拒絕未終止 name／短 header 是**測試器政策**，非原版確認行為。

來源：`CLM-CHAR-0001`、`CLM-CHAR-0002`（PARTIAL）；`kr/evidence/7a594f0ba64354a1c22fa2a6fe22f45e3a29699fb2bf5f73c2023e8113b9cac7.txt`；`GAP-CHAR-0001`、`RR-0002`、`TEST-CHAR-0001`。

## Iteration 21 — 創角入口與交易缺口（2026-10-31，DRAFT／非封包契約）

- `GAP-CHAR-0002`／`RR-0009 (QUEUED)`：目前沒有證明 KR Client 從 `command2 N=0` 或「新增角色」控制器到**可操作的創角對話框**的正向 scene/dialog/callback 鏈。T03 研究 UI event/scene gate，T06 協查同版本資源。UI 本地事件不等於 Client↔Server message。
- `GAP-CHAR-0003`／`RR-0010 (QUEUED)`：目前沒有可核定的建立角色 C2S builder 與 S2C 成功/拒絕 consumer 配對、方向別 layout、slot/frame/encoding、創角後 roster/init 時序；T03 為研究主責，T04/T02 提供欄位/transport 介面。
- **選角不是創角**：既有 C2S `0x42` 是選中既有角色的有界 Client builder；`RR-0002 BLOCKED` 處理選角結果，`RR-0007 IN_REVIEW` 處理 dispatcher，`RR-0008 IN_REVIEW` 處理選角到場景。新請求不得替代它們，也不能借用 S2C `0x42/0x43` 當創角回覆。
- **可實作限制**：此時只能做獨立的 Server-side domain mock / adapter fail-closed 設計，不可硬編任何未證的 Create opcode、初始數值、官方回覆結果或直接宣稱原版 Client 可以創角。正式台帳與原 Client 執行授權各自獨立。


## 2026-10-31 S00 RR-0010 後續驗證（E71–E74；有界 Client 靜態研究，非正式 wire transaction）

[完整 S00 逐條審查](../../governance/s00-iterations/S00-20261031-RR0010-EXTRA-ROY1-REVIEW.md)（PR #63，`extra/roy1`）。**此節更新 Iteration 21 歷史「RR 已 QUEUED/未知 create opcode」的現況，不刪改當時原始研究與狀態快照。**

- **建名是遠征隊／玩家身分，而不等於新增可操作角色。** T03 E73 在 `CExpeditionCreateDialog` 找到名稱 edit→本地 confirm `F4244`→有條件 **C→S inner `0x003E` 48B、slot0** 的 builder：opcode 在 `+0..1`，UTF-16 name buffer 起於 `+6`（21 WCHAR 容量，含終止字元）；`+2..5` 值 **UNKNOWN**，其餘未用 buffer bytes 不保證為零。所述精確 byte-level 證據來自 T03 作者的 KR BIN verifier；S00 本輪用已存反編譯交叉核對寬字元名稱/send，不冒稱親自重跑原始 BIN 或 T01 FULL-PASS。
- **候選結果消費**：LOGIN scene 有 **S→C `0x004A`** consumer，讀 signed word at `+2` → **本地** `F4245`；result `1` 可更新 `F938F2` 名稱及 UI，`-1/-2/-3` 各有分支但**不知官方含義**。缺少原版 Server 的 `0x003E↔0x004A` request–reply 配對及實際 Client scene/Conn 與 frame trace，**不是已完成官方建角 ACK 契約**。
- **清單共用名稱**：S→C `app2` header `+0x0C` 的 name copy 到**同一個** `F938F2`，名單 65B prefix + 53B/row；逐 row 可能送 C→S `0x26` 3B，結尾 `0x24` 2B。shared global 不等於 `0x004A→app2` 時序、創角成功或世界初始化。E75（RR-0002）找到的 S→C `0x26` 另是 4+5N consumer，**不能**將 C2S/S2C 的同值 opcode 視為已配對。
- **不同事件不可混淆**：`CEmployNewCharacter` 的 C2S `0x33` 僅2B、不含創角姓名；C2S `0x42` 是已存在角色 selection。既有 RR-0009 UI 入口、RR-0002 選角與 RR-0010 真正建角→roster 因果分離。
- **狀態不提升**：截至本次驗證 RR-0010 **BLOCKED**（非 ACCEPTED）、GAP-CHAR-0003 **OPEN**；本規格 **DRAFT/PARTIAL**。本節可供 Server-side 模型/合成向量設計，但不得硬填 `0x3E+2..5`、錯誤碼、初始數值或推定原版 request/reply/可遊玩。


## Iteration 23（E76–E79）— 共同 role array、UI ready、增量回覆（仍 DRAFT/PARTIAL）

**有界新證據及服務端設計門檻：** [Iteration 23 完整規劃](../../governance/s00-iterations/S00-20261031-ITERATION-23-EXPEDITION-ROSTER-PLAN.md)、[24 項未執行測試](../../governance/s00-iterations/S00-20261031-ITERATION-23-ACCEPTANCE.md)。KR SHA 同前；來源 E76～E79 是 T03 原始 BIN source-first 作者報告與可重跑 checker，本 S00 工作環境未獨立重新跑原始 BIN，採同版保存 Ghidra 偽碼交叉查證。**本節更新 E72 的「不同 destination」錯誤，保留舊稿作歷史，不覆寫來源。**

| S2C incoming | Client 有界資料形狀／寫入 | 原生前提與限制 |
| --- | --- | --- |
| `app 0x0002`（full） | `65 + 53*N`；name at `header+0x0C` 20 UTF-16 code units → `F938F2`；53B rows→`0x4D4150`→`[F94304]+slot*0x210` 的 role record `+0x5C=1`；per-row C2S `0x26` 3B、final C2S `0x24` 2B | 先有其他 header 讀取，row count 的 `len>=65` 不代表短 header 無風險；有效 slot `<=9` 是本地上界，不代表官方可用角色 ID |
| **`app 0x002B`（incremental）** | E79：network callback index2B `0x4943B0`→singleton `0xF8D9E0`→內層 table index2B `0x4E2730`；`2 + 53*N`、row from +2，row+0x2E slot<=9→**同一個** role record array／`0x4D4150`，N=0 仍到 `0x4E5FB0` | `[this+0x6924]` 當 `this=0xF8D9E0` 等於 **`[0xF94304]`**；不同 header、不代表兩個 DB 名單；不含已證 create status，也沒有已證 delete/clear、original Server 觸發/時序 |

**畫面事件是第三個獨立邊界**：E76 `CExpeditionPage 0x5A6510` 讀非空 `F938F2` 設 `page+0x144=1`，`0x5A65A0` 依 flag 控三個控制狀態；E73 的 `S2C0x4A` 成功狀態1經 `F4245` 也可獨立設 same ready flag。E77 `S2C0xB6` 在有效 base scene → `0x4B5DD0` → **local** `F4278(0)`，`CExpeditionPage 0x5A67D0` 條件滿足時 `0x672F00` 按 child index 從 `F94304` 讀 usable `+0x5C`，有資料走 UI，否則 placeholder；B6 無原生已證角色 ID payload，`F4278` 也有 `CPhaseSlot` 本地來源。E76 的 `F4261` 對 Expedition Page 是 default branch，不能混成 ready event。

**重要否決**：`CEmployNewCharacter→C2S0x0033` 2B ≠ `CExpeditionCreateDialog→C2S0x003E` 48B；`0x004A` signed outcome ≠ 已證 original Server 建角 ACK；`0x002B` 更新同一資料陣列 ≠ 建立/刪除 playable role 的正式 Server 動作；`C2S0x0042` 仍是選既有角色。Original `0x3E↔0x4A`、`0x33↔0x2B`、`0x4A→app2/2B/B6` 的跨 wire 因果、角色數初值、連線與失敗碼語意均 **UNKNOWN**。

**Server 相容性規劃**：建立 `FullRosterSnapshot` / `ApplyRosterDelta` **同一 RoleStore**，另外 `ExpeditionProfile` 存名字，保留 `NameReady`／`RosterHydrated`／`RoleUiReady` 三個不同 gate；只在 T02/T03/T04 證明欄位與封包前提後才啟用 native encoder。狀態仍 `SPEC-CHAR-0001 DRAFT/PARTIAL`、`GAP-CHAR-0003 OPEN`、`RR-0010 BLOCKED`。


## Iteration 24（E80／RR-0002）— 選角 C2S42 欄位／角色資料安全界線

來源：[E80 原始研究](../../kr-extra-roy/20261031-0414-chatgpt-web-roy-E80-RR0002-selection-UI-roster-square-new-server-contract.md) 與 [S00 Iteration 24](../../governance/s00-iterations/S00-20261031-ITERATION-24-SELECTION-SQUARE-HANDOFF.md)。E80 屬 RR-0002（選擇已存在角色），**不是 RR-0010 建立角色或遠征隊建名 ACK**。本 S00 回合核對 E80 原稿與同版 KR Ghidra 偽碼；無原始 Tartaros.bin 重新執行作者 117 項原生及合成檢查。

- **C2S 0x0042**：0x4A3B80 有條件在 slot0 queue 4B inner body：u16LE cmd=0x0042，offset+2 roleIndex u8，offset+3 mode u8。ExpeditionScene 事件 0x70A 的 child index+1 在部分 UI 分支需角色記錄 +0x5C 可用且索引<=9；另有 button mode0/mode2 和 ExpeditionDialog 選角入口，UI guard 不是完全一致。
- **Client local pending 不是已送封包**：部分 ExpeditionScene 按鈕 caller 在 builder 返回後設 scene+0xCC=1，但 FBA798!=0 時根本不會 queue；Server 必須用自己的 Session/lease/timeout/idempotency，不以此 flag 推算 ACK。
- **full roster header/角色0風險**：S2C app2 使用 65B prefix +53N record，row count gate 之前已讀 header +2/+0x0C/+0x36..+0x40；record index 原生上界是<=9，但後續 mask 用 1<<(ID-1)，ID0 有不一致風險。Server 初期提出僅輸出 ID1..9 是防呆規則、**不是 KR 官方角色合法範圍**。
- **共用角色資料不是官方建立交易**：E79 S2C app2（完整）與 app2B（增量）寫同一 F94304 角色陣列；E80 C2S42 僅選已存在角色。C2S3E 建名、C2S33 招募候選、S2C2B 更新、S2CB6 UI、C2S42 選角是不同子流程；不擅寫 Server 一定把它們串在同一交易。

未知：官方 C2S42 accepted/rejected S2C、mode2 業務語意、失敗重試 UI、Square world 初始化；RR-0010 的「創建角色→roster」因果仍未證。狀態 **DRAFT/PARTIAL**、RR-0002/0010 **BLOCKED**、相應 GAP **OPEN**。
