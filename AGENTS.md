# 分工接續規則

## 跨 Task 驗收退回（以 Task README 通知，不使用 GitHub Issue）

- 各 Task **在新 ChatGPT 對話首次開工時**讀取自己的 kr/tasks/<TaskID>/README.md 中「T01 驗收退回事項」，優先處理 NEEDS_FIX、FIXING、READY_FOR_REVIEW、BLOCKED；沒有此節則照舊工作。同一對話續段沿用已讀內容，不因每次「請繼續下一段」重抓 GitHub。
- T01 先核對原始來源 SHA、PE 映射、指令邊界、驗證工具、完整主張與上下游；若是 T01 自己驗證器錯誤，先自行修復，不通知原作者。
- 確定需來源 Task 更正時，T01 在對應 Task README 的上述專區建立／更新固定 ID 的退回項；包含原稿完整路徑和 Git blob SHA、錯誤描述、原始反證、修復要求、完成條件、驗收來源。不使用 GitHub Issue。同一問題更新舊紀錄，不重複建立。
- T01 只可編輯其他 Task README 的退回專區；不可改原稿、Task owner、task.json、catalog、native_complete 或其他 Task 結論。
- 來源 Task 保留原稿，提供修正版或勘誤檔和新版 SHA，將項目更新為 READY_FOR_REVIEW。T01 複驗通過後才標記 RESOLVED；不得刪除歷史。
- 狀態流轉 NEEDS_FIX → FIXING → READY_FOR_REVIEW → RESOLVED。現有第一手證據無法再推進時方可標記 BLOCKED 並列解除條件。PARTIAL 僅是尚未全文驗完，不自動視為原稿有錯。
- FULL-PASS 必須限定版本及全部實質肯定主張的驗證範圍，抽樣位元組通過不等於全文 FULL-PASS，亦不等於整體 Task 的 native_complete。
- 保持各 Task 的原有分工、分支、提交授權和競爭修改核對要求。


## 已上傳的大量反編譯與審核狀態

使用 KR 原生證據前，先讀 [完整反編譯上傳與狀態索引](shared/integrations/T01-BULK-20261026-02/README.md)。`kr-bulk-roy/<目標SHA>/functions/` 與 `raw/` 已完整保存於 Git；按位址選讀，避免重做全量反編譯。`python -B kr-bulk-roy/review_status.py 0x4df510` 可查逐函式狀態。上傳、方法登記及來源被引用均不等於整個函式已逐項審核，既有正式結論僅在 catalog 指定的有限範圍成立。

## 使用者全任務政策（2026-10-26）

所有 KR／TC 任務先讀 [客戶端修改與封包恢復政策](shared/CLIENT-MODIFICATION-POLICY.md)。遊玩流程優先以封包／伺服器資料恢復；主程式調整以 IP、Windows 相容性、翻譯為主，其他修改須先提出具體方案並獲使用者確認。原始證據唯讀與既有不執行／附加等限制維持。本政策適用所有任務，不只 T06。

使用者指定「KR T08」時，先讀 README.md、HANDOFF.md、kr/tasks/T08/README.md與task.json，再查shared/catalog.json。TC同理。

- 主要目標：恢復可遊玩流程；本庫保存分析依據，不是原版伺服器實作。
- 僅離線讀取目標，不執行、附加遊戲或呼叫目標API。原始程式／資源／帳號／存檔不修改。
- 原生已確認、部分確認、AI替代、資訊缺失、待補充開發逐項區分。不得補猜值或把fixture當原生證據。
- 目標原檔另行取得，先核對shared/targets.json的SHA。位址不能跨KR/TC套用。
- 需要新的原生證據時使用REA技能與Ghidra；本庫不附引擎或保證對方已安裝。Python用於整理與核對。
- 先在task.json登記owner與工作範圍；shared/catalog.json的entities指定主責任務。未列方法先向整合者登記；共用方法只引用，不重複定義。
- 每人使用獨立Git分支與自己的分析專案。回傳新增結論、證據、SHA、範圍及未知項，由整合者處理衝突。不要以最新時間戳覆蓋相反證據。
- 證據.txt保留原資料，有些是歷史腳本；不得直接執行。絕對路徑只是歷史出處。
- verify通過只代表包內校驗；歷史引用未閉合、台版原生缺口及frame-dispatch未驗收限制仍有效。
- 不展開音效、CRT或保護殼等暫緩路線，除非使用者另有要求。

## T01 完整驗證共用知識（2026-10-28）

T01 對完全通過原生驗證的**精確結論／子流程**，依 [FULL-PASS 不按 Task 分類政策](shared/T01-FULL-PASS-UNCLASSIFIED-INTEGRATION-RULES.md) 整合至 [共用知識入口](shared/verified-knowledge/README.md)。共用知識依功能／協定／資料結構查找，不以 Task 當分類；原 Task、作者、原稿 blob SHA、版本與驗收責任仍保留作追溯。PARTIAL、source-only、bytes 抽查或整份報告未逐項語意驗證，不得升級 FULL-PASS。原版 Server 內部規則歸 Server 待開發，Client 未知封包與反應仍屬 Client 待逆向；兩者不能混淆。本政策不改其他 Task owner、catalog、原始研究和既有退回流程。


## Server 設計流程與 S00 跨 Task 派工（正式內部規則）

本庫已建立 [S00 規格整合流程](governance/s00-workflow.md)、[T01 風險分流與整合流程](governance/t01-integration-workflow.md)、[Server 規格入口](spec/README.md)。新收件/認領/回報規則在 main 發布後正式生效；不覆寫既有歷史原稿、Task owner、退回狀態或 FULL-PASS 嚴格要求。無 REA 的 Agent 可進行 S00 工作；需要原生補證再交 T02–T16。此流程不授權執行原版 Client、修改原件或接收外部 Issues。


<!-- S00-DISPATCH-BOOTSTRAP:v1 -->
## S00 收件箱開工檢查（每個 T01–T16 Agent 必讀）

**僅在新的 ChatGPT 對話首次開工時**，取得當時最新的 `origin/main` SHA，並閱讀對應版本 `kr/tasks/Txx/README.md` 或 `tc/tasks/Txx/README.md`（含 T01 驗收退回）、[S00 派工規則](research/dispatch/README.md)、[該 Task 收件箱](research/dispatch/inbox/T03.md)（改為自己 ID，如 T08）、[唯一 RR 請求台帳](research/requests/index.json)。可使用 `python -B research/dispatch/dispatch.py show T03 --version kr`（TC 改 `--version tc`）（替換 ID）檢視當前待辦。T01 讀 T01 review inbox；T02–T16 讀各自 Task 收件箱，按 `client_version=kr/tc` 嚴格分流。

**同一對話的後續段落／復工／交接**：沿用首次已核對的 main SHA、Task README、T01 退回、RR 台帳、收件箱及共用驗證索引，不要例行再次連線 GitHub、不必每段查 SHA 或重讀全套文件。只有使用者明確要求 GitHub 查詢／更新／同步／Commit／Push、研究需要首次取得尚未讀取的精確 Git 來源，或有可驗證的分支競爭／來源變更訊號時，才按需存取相關檔案；**進行實際寫入前仍必須核對當前目標分支與檔案 SHA，避免覆寫他人提交**。例外不代表要重做完整開工檢查。沿用舊快照的研究須註明其基準，不能聲稱本段已核對最新 main；收到新對話時再次完整核對。

**優先順序與授權**：既有 T01 NEEDS_FIX／FIXING 退回依原規則優先；本次使用者明確任務另列優先；S00 P0→P1 隨之排程。未經明確授權不得提交/推送研究原稿；只在 main 上已公開的 RR CLAIMED 才具跨 Agent 認領效力。提交原始研究成果後需 `SUBMITTED` 附報告檔與 Git blob SHA；T01 來源查核與 S00 規格接受分開，只有 S00 可結案。**GitHub 更新不會自動喚醒其他 ChatGPT Agent。** 不採 GitHub Issues，不更動原有 task.json／owner／historical FULL-PASS/FAILED 認定。


## S00 Server 需求三種來源（2026-10-30）

所有 Task 發現 Client 在程式碼中**需要 Server 收取 C2S、送出 S2C、維持狀態或處理錯誤**時，應於原作者分析原稿標示「Server需求候選」（版本、Native VA/raw、前提、分支、方向、已證與 UNKNOWN）；**不必等實機觀察或使用者另外提出需求，也不必先新建 RR**。其餘正式來源：經另行授權的遊戲實機觀察、使用者（玩家／管理員／維護者）要求。第 5 項舊協定／歷史 Server 資料按使用者指示歸於 USER_REQUEST 的參考附件，而非獨立來源。S00 維護 [來源政策](governance/S00-SERVER-REQUIREMENT-SOURCES.md) 和 [候選索引](spec/server-requirements/index.json)；原 Task 僅回報，不改他人研究，不把候選當原版 wire、SPEC STABLE 或准許執行 Client。
