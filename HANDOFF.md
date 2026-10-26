# 接續導覽

2026-10-26：使用者授權完整上傳 KR 大量反編譯。[T01-BULK-20261026-02](shared/integrations/T01-BULK-20261026-02/README.md) 保存全部偽碼、原始批次與逐函式審核狀態。111,054 個函式均未登記為完整函式語意審核完成；精確相關的有限證據另列，保留前批正式結論的限定。接續前先 fetch 並查本批次提交與狀態索引，不把已上傳當成已驗收。

2026-10-26 使用者政策更新：所有 KR／TC 任務接續前閱讀 [客戶端修改與封包恢復政策](shared/CLIENT-MODIFICATION-POLICY.md)。優先用封包／伺服器資料恢復流程；IP／Windows 相容性／翻譯以外的主程式修改先提出具體提案請使用者確認。既有執行限制與原始證據唯讀不變。

2026-10-24：整理版已完成，沒有執行中的盤點或遊戲程序需要接管。先讀REPORT及shared/task-readiness.json，不要恢復已完成的全量掃描或重建原生atlas。

下一步由使用者選定任務（例如KR T08），依AGENTS.md認領範圍。任務可獨立閱讀現有資料，但新分析仍需原檔和REA/Ghidra。台版只具背景／缺口資料。

仍有未分類來源與歷史外部引用；它們已明列為缺口，不能用檔名前綴、最新日期或相同功能名稱推定來源。需要某項缺口時才補取證據，不要為閉合全部導覽擴大範圍。

重要更正：AI固定出生點／怪物能力／傷害／追逐不能當原生規則；原版005F type6不是本機修補的Tutorial；000F不可直接按fixture名稱認成命中；4B18D4依路徑而非固定result0；4BC150不是有效函式入口。Frame-dispatch仍待原階段語意驗收。

可追溯性：原CHECKPOINT與初版catalog已封存在history/checkpoint-v1.json.gz；初版試包保留，新版使用exports/*-release.zip。原anal唯讀且未變更。重現與增量更新看REPRODUCE.md，避免只重跑初版builder覆蓋後續整理。

2026-10-26：使用者指定T07由其他對話接續；T06兩村切城的場景/reset/ready依賴與已存原生證據見[專項交接](shared/T07-TOWN-ENTRY-DEPENDENCY-HANDOFF.md)。T07尚未認領，不需重新全量反編譯。


本輪整合入口：[T01-20261026-01](shared/integrations/T01-20261026-01/README.md)。以該批次提交為接續基準；只整合 local-items.json 明列 SHA，未傳訊至其他對話。原工作區保留未提交狀態，不代表尚未整合；先比對批次 SHA 避免重複提交。


2026-10-27 本地整合入口：[T01-20261027-03](shared/integrations/T01-20261027-03/README.md)。來源為 origin/main f02dcb07 與凍結本地快照；34筆限定結論、9筆更正。尚未推送，請用引入本批次的本地 commit 接續；逐 SHA 去重，不以暫存目錄存在判斷尚未整合。未通知其他對話，T14分析維持暫停。
