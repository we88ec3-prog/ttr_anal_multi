# T01-20261027-03 線上／本地分析整合

日期：2026-10-27（Asia/Taipei）；操作者：Codex T01 integrator；分析來源：roy、線上報告所載 chatgpt-web／claude-web。遠端基準 `f02dcb07db788e81fc8de88bb68ca857c0516037`，本地來源 HEAD `08a08599c4dac2febab869523780cabf39806b69`。遠端：`https://github.com/we88ec3-prog/ttr_anal_multi.git`。

本輪接受34筆有條件結論，加入9筆更正；保存824個本地來源版本、34份線上報告，新增732個去重後artifact。正式結論在 `shared/catalog.json`／SQLite，原樣證據在 `kr/evidence/<SHA>.txt`；每項正式位置、任務、分析者與SHA見 [本地清單](local-items.json) 和 [線上清單](online-items.json)。 supporting source 保存不代表整個檔案或所有函式逐項審核通過。

[接受結論](accepted-claims.json)區分原生已確認、部分確認、AI替代、資訊缺失與待補充開發；原生標記僅對來源限定的靜態觀察成立。線上主張以保存的Ghidra來源SHA交叉引用，沒有重新證明完整機器碼語意。所有函式的完整語意審核仍為未記錄；[方法引用](method-references.json)列明獨立快取缺口與既有主責，未改派方法所有權。

[更正](resolutions.json)處理checkpoint容器、init/ready、DeleteObject ID、NPC延後001C、QuestMgr0064、表格欄位起點、event8上下文與相容觀察。原報告不覆蓋，舊結論依更正限制讀取。舊T02失敗fallback與checksum限制繼續有效。

快照截止於UTC `2026-10-26T18:30:16.048036+00:00`（臺北10月27日02:30）。2551檔／383145933 bytes，SHA `3ae1c1c4c8d4db165d3f025360d89e1b52d29ab203a7fe5dc969e1e81d339582`。可恢復副本 `work/T01-20261027-03/local-snapshot.zip` 保留在本地，不含.git、不提交整份歷史；[凍結清單](frozen-inventory.json.gz)可逐項比對。來源工作區與原anal保持未改動，沒有執行遊戲或目標API。

[來源引用校驗](source-reference-audit.json)共1699項，其中1495引用SHA與177內嵌span相符；25項外部／未打包引用與2項版本差異見[未完成清單](pending.json)。未帶入外部SERVER、原執行檔等資料，不據此宣稱官方端到端或原始資源完整。已上傳bulk保持不變，不將整份反編譯列為語意完成。

[凍結後變更](post-freeze-changes.json)不屬接受範圍，尤其後續scene-roundtrip新增檔；留下一輪。T14只整合既有成果，分析仍依使用者要求暫停；T02既有狀態與限制保留。TC沒有新增原生結論，不套用KR位址。

驗證結果見 [validation.json](validation.json)。閱讀與SHA驗證不需原anal；外部引用是未閉合的來源線索。必要查詢見 [NEXT-QUERIES.md](NEXT-QUERIES.md)。

接續基準為本地分支 `codex/t01-integration-20261027-03` 引入本檔的commit；使用 `git log --diff-filter=A -- shared/integrations/T01-20261027-03/README.md` 取得確切SHA。本輪只commit，尚未推送；不要假設origin/main已包含本批。實際commit收據留在本地outputs。其他任務先以清單SHA去重，再補限定缺口；未列明的來源內容與新變更不標完成。交接僅透過文件，未向執行中的其他對話發訊息。
