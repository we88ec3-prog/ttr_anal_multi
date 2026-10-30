# S00 — Server 需求統一台帳

[需求唯一索引](index.json) 的 REQ-* 是 **Server 需求管理**，不取代 RR 派工、GAP 未知、SPEC 契約、ADR 設計決議或 FB 實作缺陷。每一需求可有多筆來源紀錄（discoveries），**同一需求從不同來源再次出現時追加佐證，不複製 REQ ID**；若驗收目標確實不同，才建立新的 REQ 並記錄與舊需求的依賴。

## 三個正式來源

| `discoveries[].channel` | 來源情境與登記條件 | 必記內容 | 不代表 |
| --- | --- | --- | --- |
| `CODE_ANALYSIS` | 程式碼／反組譯分析時發現 Client 需要 Server 接收封包、回覆封包、提供資料、連線切換或狀態同步 | 與原始 Client 同版本的已登記 CLM、觀察內容、前置條件及 UNKNOWN | Server 在原版運行時必然發送、完整原版封包順序 |
| `GAME_RUNTIME_OBSERVATION` | 經**另行明確授權**直接執行遊戲、在允許的環境中確認畫面、收發、事件或錯誤處理 | Client 版本和 SHA、測試環境、重現步驟、實際觀察、去敏報告位置及授權記錄 | 靜態研究等於成功實測；單次測試足以證明所有版本或原版 Server 規則 |
| `PLAYER_ADMIN_REQUEST` | 玩家或管理員提出功能、管理及營運需求 | 來源角色 PLAYER/ADMINISTRATOR、原始具體需求、去敏的內部紀錄 | 原版 Client 一定支援、已通過批准或能直接添加未確認的 wire opcode |

歷史封包、舊版 Server 設定／日誌與協定文件若是玩家／管理員／維護者提供來要求研究、還原或改進功能，依使用者指示屬 **第 3 類 `PLAYER_ADMIN_REQUEST` 的 `discoveries[].reference_materials` 附件**（說明 `description`、`location`、`provenance_note`），**不是獨立第 5 類 origin**。文件可供之後的研究交叉核對，**不會自動證明原 Client 或 Server 的協定、封包順序或 byte layout**。現有台帳不虛構任何玩家曾提供的歷史附件。

安全、登入權限、帳號處置、管理員稽核、備份還原、營運監控與資料一致性等**均歸 PLAYER_ADMIN_REQUEST 中的管理員需求**（可在 category 使用 OPERATIONS / SERVER_DESIGN），**不新增第四類安全審查來源**。若是系統內部實作 bug，先走既有 FB；若玩家/管理員要求修正體驗或增設功能，才是產品需求。

另外建議可考慮將 `SERVER_IMPLEMENTATION_FEEDBACK`（Server 實作/整合測試中的新需求）作為**待使用者核准的第四種來源**，目前不在可用枚舉中；現有實作缺陷／規格回饋仍使用 [FB](../feedback/README.md) 進行分流，不暗中建立新來源。

## 單筆 REQ 的欄位與去重原則

- `id` 永久唯一；`status`: CANDIDATE → UNDER_REVIEW → APPROVED，或 DEFERRED/REJECTED。新增程式碼證據**不能自行提升狀態**；APPROVED 需維護者記錄。
- `category` 分 CLIENT_COMPATIBILITY、SERVER_DESIGN、PRODUCT_FEATURE、OPERATIONS，這是**需求類別而非來源**。
- `client_version`=kr/tc 時必須符合 [target SHA](../../shared/targets.json)；純 Server 需求可設 null，不能跨版本引用 Client CLM/SPEC。
- `need`、`acceptance_criteria` 分開描述「為何 Server 需要處理此事」與「何時可視為完成」。靜態 Client handler 只支援有界候選描述，不自動成為必須回應的正式 Server 規範。
- `discoveries` 為可追加來源；`claim_ids/rr_ids/gap_ids/spec_ids/adr_ids/feedback_ids` 綁定現有正式治理索引，而不是複製 RR、任意變更 Task owner 或創建影子 RR。
- 當請求增設管理員帳號封禁，雖同樣涉及角色/Session，但若成果、授權及驗收與角色清單不同，應**另建需求**；同一角色清單功能多次被程式碼/運行證實則沿用原 REQ。

## 示例：角色畫面所需資料

`REQ-0003` 先因 Client `command2` 接收 `65+53*N` 角色資料（`CLM-CHAR-0001/0002`）建立 `CODE_ANALYSIS` discovery；目前不能主張 Client 介面收到它就一定刷新。`REQ-0004` 獨立追蹤 UI 就緒、清單之後初始化的**不同驗收結果**。經授權有實際畫面或封包觀察，再補 `GAME_RUNTIME_OBSERVATION` 到對應 REQ。玩家提出角色排序或管理員提出角色檢視，若其成果不同則新建需求並標示關聯；安全權限、備份和操作稽核同屬第 3 類的管理員需求，僅有本人確實提出才建紀錄。

## S00 收件流程

1. 先尋找現有 REQ，確認是否相同交付及驗收條件；引用精確 Client SHA、已登記 CLM 或去敏化的 runtime/user 來源。
2. 先 CANDIDATE，再評估是否為原版 Client 相容必要、Server 可自訂、或玩家/管理員附加功能。若非原版行為，不寫成歷史 wire MUST。
3. Client unknown → 現有 GAP/RR，必要時才新增不重複的研究請求；Server 技術政策 → ADR；實作 bug → FB；需求批准與原生證據成熟度分開審核。
4. 後續分析/運行得證據時在原 REQ 追加 discovery，修正 `acceptance_criteria`，保留反證與 UNKNOWN，必要時拆分真實不同的需求。
5. 對已批准的 Server 需求進入獨立 Server 實作庫，並以 SPEC/TEST/ADR/FB 回饋結果；本倉庫**不直接實作 Server**。

## 檢查與限制

```bash
python -B governance/check_server_requirements.py --check
python -B governance/check_server_requirements.py --json
python -B -m unittest discover -s governance/tests -v
```

validator 只驗證索引、來源類別、連結、版本、提交的記錄路徑和基本完整性。它**不能驗證授權真實性、BIN 語意、玩家意願、遊戲真的啟動或 Server 相容性**。目前無 GAME_RUNTIME_OBSERVATION 或 PLAYER_ADMIN_REQUEST 實際條目，並非這兩種來源不可使用；是尚未收到具來源紀錄的實際需求。

## 需求到 Server 實作的分段交付順序（Iteration 11）

[REQ 分段目標與動態評估](../../governance/s00-requirement-slices.json) 將第一階段 `SLICE-LOBBY`（登入→選服→名單與角色畫面）與 `SLICE-CREATE`（創角入口／建立角色）及 `SLICE-ENTER-WORLD`（選角後進場）**分開驗收**。`SLICE-CREATE` 目前是 `DISCOVERY_REQUIRED`，不可擅自杜撰角色建立的 C2S/S2C 命令；它沒有獨立 REQ，是因尚無該功能的充分有界 Server 收發來源，不代表不需要研究。

執行 `python -B governance/server_requirement_slices.py --check` 和 `python -B governance/server_requirement_slices.py --format markdown`。結果從唯一 REQ/RR/GAP/SPEC 索引派生，只是只讀規劃 overlay；不會改既有 `s00-roadmap.json`，也不表示原版 Client 已能進入畫面。新對話用 [S00 交接入口](../../governance/S00-NEXT-CHAT.md)。
