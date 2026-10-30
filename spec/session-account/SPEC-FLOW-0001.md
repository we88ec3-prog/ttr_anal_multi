# SPEC-FLOW-0001 — KR 登入 → 選服連線 → 角色清單 → 選角 → 場景交接

**狀態：DRAFT / PARTIAL；流程契約尚未閉合，不可作為可連線 Server 完整實作規格。** 對象：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。此文件提供開發者的**已知步驟／未知前後條件**，不是推定原版官方 Server 設計。

## 有界證據對照

| Client 階段 | 可觀察且有來源的事實 | Server 開發需要但仍未知的部分 | 關聯 |
|---|---|---|---|
| 1. C→S 認證請求 | Client mode `0x52` 產生 E8/112-byte、mode `0x54`／其他產生 000F/214-byte 本地 payload，queue slot1；E8 輸出轉碼 CP_ACP 與前置 FBA808 global 路徑不同，不能互用 | launcher 何時選某 mode、E8 `+104..109` 局部未直接賦值六 bytes 的真實值／Server 政策、整條傳輸與 first-response 時序 | [SPEC-AUTH-0001](SPEC-AUTH-0001.md) |
| 2. S→C 登入結果 | 有效 LOGIN scene 二層表有 S2C app `0x0013→0x4C37A0`、`0x007A→0x4C3C10`；`0x13` status 在 `+0x16`（0+非空 UTF-16 名稱才局部成功；5 專用失敗），群組游標 `+0x92`；`0x7A` group count `+2`、游標 `+6`；group/child 消費 3+10n | 真實原版 Server 是否送這些 handler、回覆的完整 byte extent 與先後、token/租約、短包／無 NUL 行為及後續必要 C2S；**不假定** 0x13 成功就切線 | SPEC-AUTH-0001 |
| 3. 連線/選服 | 三個有界 KR Connect callsite 指向 port 8415(slot1)、8416(slot0)、8414(slot2)，其 pipeline 參數皆為2；`0x13` success+`+0x90==0` 先透過 `0x4C3170` 發 **本地** F4241，UI selection 需滿足額外 gate 才到 `0x4957C0`；均為**靜態 Client 路徑** | 是否在同一條 runtime 路徑依次連三個埠、真正選服觸發點、endpoint 權威、Session handoff/重連時序 | [SPEC-NET-0002](../protocol/SPEC-NET-0002.md) |
| 4. S→C 角色清單 | handler index2 使用有效路徑上的 `65+53*N` payload；選定 record 欄位可寫入 UI 資料 | 65-byte prefix 業務值、帳號授權、有效資源與 UI 更新、完整角色初始化回覆鏈 | [SPEC-CHAR-0001](SPEC-CHAR-0001.md) |
| 5. C→S 角色選擇 | T03 現有研究觀察到 command 42 的 4-byte 候選請求 | 42 的完整權威欄位、成功/失敗 S2C response pairing、角色初始化/切線狀態 | SPEC-CHAR-0001 |
| 6. Client 場景/教學資源 | `Event/SceneList.xml` 包含 `(1001,1)→tutorial_start` 靜態列；Client 有雙鍵 reader 組 `Event/Sequences/<funcName>.seq` 載入路徑 | **尚無原生關係證明**選角 `0x42` 回覆、首登旗標或任何 S2C payload 觸發 `(1001,1)`；也無法宣稱每個新角色必入教學 | [SPEC-SCENE-0001](../world/SPEC-SCENE-0001.md) |

**重要：**上表是不同研究覆蓋的相鄰功能，**不是已驗證的一條完整時序**。不得將表格的行順序寫成已觀察的原版 Client packet trace。

## 2026-10-30 RR-0003／RR-0005 有界交叉核對

- **S2C app opcode 可識別不等於真實回覆配對**：`0x0013`、`0x007A` 在 LOGIN 場景有 Native handler（`CLM-AUTH-0004`；T02 `CLM-NET-0030`），但 C2S E8/000F 與原始 Server 實際先回哪一包、用了哪個 frame marker、怎麼分 socket，沒有同一條觀測的 wire trace。
- **文字轉換有兩個層次**：`FBA808` 是 PE zero-tail 初始0之全域 codepage（runtime alias 未證）；E8 local payload builder 的輸出文字 WCTMB 直接使用 CodePage=0（CP_ACP），見 `CLM-AUTH-0003/0006`，不能把這兩條路徑偷換成固定 CP949/UTF8。
- **群組資料長度是 Producer 最低可讀 extent，不是原生安全核准**：`0x13` count `+0x1C`、cursor `+0x92`；`0x7A` count `+2`、cursor `+6`；group 3 bytes、child 10 bytes，缺少本地每筆 remaining-length guard（`CLM-AUTH-0005`）。
- **先有本地事件，不必立即建立 key0/key2**：`0x4C3170` 受 `+0x90==0` gate，通知 `F4241` 不等於網路 packet；選服 UI 還要有 record/mapping 和指標前提。T02 `RR-0005=ACCEPTED` 僅限已提交的局部 Client static handoff，`GAP-NET-0002` 仍 OPEN；T03 `RR-0003=IN_REVIEW`，`GAP-AUTH-0001` 尚未結案。
- **選角與教學不能借 AUTH 的成功分支補完**：`RR-0002=BLOCKED`、`RR-0008=IN_REVIEW`（截至本次核對）；既有場景資源 `(1001,1)` 及 S2C app `0x42` handler 不是已證的「選角成功即播放教學」規則。

此處是 [SPEC-AUTH-0001](SPEC-AUTH-0001.md) 和 [Phase B matrix](phase-b-message-matrix.md) 的有界交叉整理，不是新執行原始 Client、原版 Server 測試或 `RR-0003` 正式 `ACCEPTED`。

## 客戶端界面與 Server 設計分層

- **Client 相容規定**：只有精確已核對的 payload bytes/offsets、前提、handler 與分派邏輯可以作有限規格。
- **Server 自訂決策**：帳號驗證、DB、角色資料權威、首次登入條件、Session 維護方式，需獨立 ADR／需求，不可冒稱官方 Server 內部規則；決策也不能任意產生 Client 不認識的封包。
- **封包／資源分界**：`questIdx`、`sceneIdx`、`funcName` 是已確認的 Client 資源索引/腳本介面；**不是** `0x42` 回覆中已確認的三個網路欄位。

## 可交給獨立 Server 開發者的目前成果

可以分別實作 T02 framing 子集、E8/000F payload 解析、command2 roster 資料幾何，並於實作庫分開管理自己的帳號 Session；但**不能只依本文件完成原版 Client 的登入/選角/教學端到端運行**。

開發前的阻塞：`GAP-AUTH-0001`、`GAP-CHAR-0001`、`GAP-NET-0002`、`GAP-FLOW-0001`、`GAP-SCENE-0001`；研究請求 `RR-0002`、`RR-0003`、`RR-0005`、`RR-0008`。來源 `CLM-AUTH-0001..0006`、`CLM-NET-0007/0018..0020/0030`、`CLM-CHAR-0001/0002`、`CLM-SCENE-0001..0004`，全部 PARTIAL。**本規格沒有新增 wire conformance fixture 或運行證據，不可升 STABLE。**

## Iteration 21 — 創角入口與交易缺口（2026-10-31，DRAFT／非封包契約）

- `GAP-CHAR-0002`／`RR-0009 (QUEUED)`：目前沒有證明 KR Client 從 `command2 N=0` 或「新增角色」控制器到**可操作的創角對話框**的正向 scene/dialog/callback 鏈。T03 研究 UI event/scene gate，T06 協查同版本資源。UI 本地事件不等於 Client↔Server message。
- `GAP-CHAR-0003`／`RR-0010 (QUEUED)`：目前沒有可核定的建立角色 C2S builder 與 S2C 成功/拒絕 consumer 配對、方向別 layout、slot/frame/encoding、創角後 roster/init 時序；T03 為研究主責，T04/T02 提供欄位/transport 介面。
- **選角不是創角**：既有 C2S `0x42` 是選中既有角色的有界 Client builder；`RR-0002 BLOCKED` 處理選角結果，`RR-0007 IN_REVIEW` 處理 dispatcher，`RR-0008 IN_REVIEW` 處理選角到場景。新請求不得替代它們，也不能借用 S2C `0x42/0x43` 當創角回覆。
- **可實作限制**：此時只能做獨立的 Server-side domain mock / adapter fail-closed 設計，不可硬編任何未證的 Create opcode、初始數值、官方回覆結果或直接宣稱原版 Client 可以創角。正式台帳與原 Client 執行授權各自獨立。
