# 分工接續規則

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
