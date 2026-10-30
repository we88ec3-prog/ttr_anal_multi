# S00 Iteration 21 — 零角色到原生創角：正式 RR 去重、派工與規格阻塞

日期：2026-10-31（Asia/Taipei）  
初始基準 main：`4ab3ce9a8a635d0b6862d6b552bf0b1098097b88`（Iteration 20）。  
KR 原檔 SHA256（依既有來源；本輪未重新計算）：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。  
**本輪是 S00 流程/規格缺口治理，不是 BIN-first 新逆向、原 Client 實測、正式 wire 契約的核准或 Server 功能實作。**

## 1. 完成本輪哪些正式變更

Iteration 20 已確認 E05 與 E06 沒有正式、獨立的完整正向證據閉環。這次依 `research/dispatch/README.md` 建立兩個**不同驗收結果**的 P0 研究請求，全部 `QUEUED`、`status=PENDING`；只有合併到 main 後才是可見待辦，且**不會自動喚醒 T03 Agent**。

| Gate | 已建立/引用 | 主責與協作 | 精確交付目標 | 截止狀態 |
| --- | --- | --- | --- | --- |
| E04 | RR-0002、RR-0007（既有）、GAP-CHAR-0001 | T03/T02 | S2C cmd2 `65+53×N` 的前提、零角色與 UI 條件，不能推得可見畫面 | 既有研究仍有 unknown |
| **E05** | **GAP-CHAR-0002、RR-0009** | T03 主責，T06 協查資源 | `N=0` 或新增按鈕 → 具可達性條件的 create dialog/control/callback 入口，含對照/失敗例 | **OPEN / QUEUED** |
| **E06** | **GAP-CHAR-0003、RR-0010** | T03 主責，T04 欄位，T02 framing | 原生「**建立**角色」C2S builder ↔ S2C 成功／錯誤 consumer、欄位寬度、slot/scene、失敗/重送/中斷及 create→roster/init | **OPEN / QUEUED** |
| E07 | 引用 RR-0010 與既有 RR-0002/7，非新增 RR | T03/T04 | Create result 持久化後實際重取角色清單、初始化、UI 更新；不能靠 Client handler 推定 Server 已存檔 | BLOCKED（產品驗收） |
| E08–E11 | **原 RR-0002 BLOCKED、RR-0008 IN_REVIEW** | T03/T07/T16 | 選中既有角色 → 真實正向回覆/state writer → tutorial first scene | 不轉移既有研究範圍 |

這兩個新請求僅連至現有 `SPEC-CHAR-0001`、`SPEC-FLOW-0001` 的 DRAFT/PARTIAL 阻塞清單，**不新增 SPEC、未批准任何實作資料**；沒有把 E05/E06 當「已驗證」。

## 2. 去重證明、已讀邊界與派工理由

本輪核對 Iteration 16/20 Gate 規劃、`governance/S00-LOBBY-CREATE-RESEARCH-QUESTIONS.md`、`research/requests/index.json`、`kr/tasks/T03/README.md` 與 `task.json`、`T04`/`T06` 的 README/task.json、`SPEC-CHAR/FLOW`、`GAP-CHAR-0001`、T03 收件箱及既有 UI15 predicate 草案。此為**限定檔案去重**，不代表逐檔全文搜尋歷史 KR 二進位或所有 Task 原稿。

- `RR-0002` 是 selection C2S `0x42` / S2C accept/error 的原生配對，已在 `BLOCKED` 提供解除條件；**不自動恢復**，亦不混用 Create。
- `RR-0007` 是特定 inbound app command/scene dispatcher，未保證創角按鈕或 create wire 的正向 producer/consumer。
- `RR-0008` 是選角結果到 scene key／`0x565720`、EndCutScene 分流，和新增角色的 request/response 不相同。
- `T03` 原有 F42EF/F4246/F4247/F4278／`0x665150` source-only UI 整理，並非 N=0 **真正 Create UI 已可見**。`T06` 的正式主責是地圖/場景資源；本次僅協助同版 UI 資源指認，**不將 T03 的 GUI 控制與 packet 研究轉給 T06**。
- `T04` 正式職責是角色初始化/初值來源；由 T03 主責 create request/response，T04 提供必要角色欄位的 Client 消費端和預設值來源，不將未證 Server DB schema 當成遊戲原規則。

此範圍分割是**S00 為減少重工的管理決策**，不是 T01 FULL-PASS 或 RR 的原生驗證。

## 3. RR-0009（E05）— 必要肯定證據與拒絕條件

**最低肯定鏈**：`command2 N=0 or Create button`（標明分支）→ 合法 scene 與 data-ready prerequisites → 控制事件 producer/subscribe → 真正 Create dialog 初始化與可操作 callback（條件式）。

必須提供：KR 版本 SHA、原件／資源函式或 key、Git 原稿路徑/Blob SHA、caller/callee、關鍵 flag/offset、guard／早返／反例及缺失的下游狀態。判定測試至少涵蓋 0 角、已有角、缺資源、list hit 但 data-fill 未達、UI handler 不在場景。

**不能用來通過**：單純證明 `65+53×N` roster parser、`0x665150` nonzero、F42EF 已定義、資源中有「Create」字樣。沒有正向 Native UI 路徑時可交代明確阻塞，但不能結案為 Create UI 已確認。

## 4. RR-0010（E06）— 必要肯定證據與拒絕條件

**最低肯定鏈**：使用者創角提交（具 UI/scene 前提）→ **建立角色** C2S producer（packet identity/length/field/encoding/connection）→ 真正對應 S2C result handler（接受/拒絕）→ create 後 roster/初始化所需更新與失敗路徑。

要求來源級補證（非猜測）：
1. C2S 原生 builder、方向、發送狀態、欄位有效範圍、名字/職業/外觀的**實際** Client 編碼／未知填 `UNKNOWN`，不能填想像的「角色職業預設值」。
2. S2C 真正消費者與許可、錯誤、重名等狀態；找不到原版 Server 配對就分離 source-only handler 和**待外部證據的交易**，不可配對 request+1。
3. create 成功後角色 ID 產生來源、可達 roster refresh、character init 的最小消息依賴；它們不能靠「Server 模擬自填」代替 native client path。
4. 當實際 Server 封包順序不能由單獨 KR Client 靜態推出，提供精確**解阻條件**，例如同版本可信原版 Server 實作或經另行授權的可信 runtime trace；**不能自行連線/執行原 Client**。

**硬性反證**：選擇現有角色的 C2S `42 00 XX YY`／S2C `0x42/0x43` 不能用來證明 Create opcode、成功 ACK 或狀態 enum。

## 5. T03 收件/認領/交付操作

- Canonical RR：`research/requests/index.json`；`RR-0009`、`RR-0010` 初始為 `QUEUED`；各有 append-only `dispatch.events` 的 S00 建立事件。
- 派生收件箱：`research/dispatch/inbox/T03.md`，以現有 `dispatch.py inbox_text` 邏輯重產；其他 Task 的收件箱不變（沒有獨立正式 RR 指派給 T04/T06）。
- T03 在**下一次新對話開工**時先處理既有 T01 `T01-RETURN-T03-006-LAYOUT-001 NEEDS_FIX` 與使用者明確優先要求，讀取最新 main 及此收件箱後自行認領。先執行 E05/GUI-source 以確認 Create 控制存在，再 E06／wire；允許並行證據查找但不可提前推斷 UI 已完成。
- 正式 `CLAIMED` 必須由研究者在**其工作分支**記錄 actor/base SHA，合併後生效；再 `IN_PROGRESS`、`SUBMITTED`（完整 Markdown + blob SHA）、T01 `IN_REVIEW`，最後由 S00 決定是否 `ACCEPTED`。目前未完成任何認領，Git 更新不會自動啟動 Agent。
- 本次 S00 使用治理工作分支，不改 T03 的 owner、task.json、T01 原稿/退回及 T03 原生研究分支的 commit 權限。

## 6. 後續規格與 Server 實作門檻

**保持四層分離**：

| 等級 | 可做 | 不可宣稱 |
| --- | --- | --- |
| 設計/派工 | 追蹤 RR/GAP、定義方向別所需輸出 | 原生已證，或有可用 Create packet |
| 有界原生靜態 | 具體 Client builder/consumer 與 branch 條件 | 原版 Server 一定按此順序回覆、Client 一定可見 |
| Server synthetic-domain | 零角色帳號、角色唯一性/持久化的自訂政策與離線整合測試 | 原版 KR Client 真的可以創角 |
| Original Client E2E | 另行獲授權的隔離版本測試後才能記錄 | 不能由本輪 CI 或任何 synthetic fixture 自動升級 |

下游 `ttr_server_roy` 可參考既有 C02/C03 的 internal-policy 設計，**這次沒有更動另一個 repository**。沒有 new opcode、name length、status enum、character quota、原 Server port 或教學初始狀態由 S00 被批准。

## 7. 下一步（Iteration 22 候選）

1. T03 按上述正式 RR 交付 E05/06，S00/T01 逐報告評議 source correctness 與能否形成方向別有限 SPEC；正式狀態依台帳重新核對，不因本文件存在而跳關。
2. 新設或擴展 **E07 create-result→roster/UI** 的獨立驗收條件，根據新證據評估是否由 `RR-0010` 完成，避免同義研究 RR。
3. 沿用 `RR-0002 BLOCKED` + `RR-0008 IN_REVIEW` 的 selection→tutorial 鏈；若缺的是原版 Server success pairing，完整記錄 blocker 而不是重做舊 BIN 分析。
4. E17-B/F/G/H 的 spawn、skill、damage、objective proof 仍屬 Iteration18 候選研究；先對現有 T08/T11/T12/T14 原稿去重再決定是否正式開 RR。

### 可重現結構檢查

- `python -B research/dispatch/dispatch.py check`：檢查 RR append-only 事件、GAP、收件箱的唯一對照。
- `python -B governance/validate_s00.py`、`python -B governance/check_s00_readiness.py --check`：確認 cross-reference 與計畫阻塞（BLOCKED 是合理結果）。
- 主分支 GitHub Actions 可執行上述既有治理檢查；**通過只是台帳完整，不是相容性／原生語意驗收**。
