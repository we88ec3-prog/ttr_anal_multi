# T01-20261027-05 接續來源審核

日期：2026-10-27（Asia/Taipei）；操作者：Codex T01 integrator；來源分析者：chatgpt-web roy／roy（既存快取）。遠端來源基準 `892a08e30ebcbe680d3171144e5bda35b2b6f79f`。本地來源HEAD `08a08599c4dac2febab869523780cabf39806b69`／`codex/kr-t06-roy`。本輪fetch後遠端無新提交，本地對前批快照逐SHA比對亦無新增／變更；因此不重複提交舊來源目錄，而接續上一批89份及更早16份source-only報告，共105份。

[逐份處置](online-items.json)記錄105份來源SHA、正式artifact位置、分析者、linked claim與未解項目；全部來源原檔與正式副本SHA相符。[內部算術檢查](report-internal-audit.json)1703處可直接重算的相對call/jump目標自洽，**這只驗文字內部一致性，不證原BIN相符、指令入口有效或完整CFG成立**。未執行原檔、附加遊戲、呼叫目標API或修改原始資源。

正式增量：25筆限定觀察／缺口、13筆更正、58份新的去重支持artifact。報告本身已在前批保存，本批按既有SHA去重；新支持證據只是把已上傳bulk中本輪引用的內容納入正式惰性 `kr/evidence/<SHA>.txt`，沒有重跑反編譯。[支持來源](supporting-items.json)與[方法引用](method-references.json)列原始SHA／路徑與既有主責，不把方法或parent raw整體標審核完成。正式結論與更正在catalog JSON／SQLite，[接受範圍](accepted-claims.json)與[更正](resolutions.json)可獨立閱讀。

新增要點：7BD8D0補足resource+20讀取者、變換／wrapper／resource不同配置、binding+7C與+80不同gate、active list持有轉移；T10的timeGetTime嚴格>500ms狀態門檻、三路輸入OR與byte優先選擇、一般／擴展phase資料、28..37命令索引，以及SubAI計數／tier／controller實例界線。全部維持部分確認或資訊缺失，沒有新增全面原生已確認標記。

T08-130自己記載PE raw400與flat raw0讀到不同bytes，進一步表明前批映射問題仍須核對。本輪保留兩者，未推根因、私自補正vtable、將中間地址當確定函式或執行dynamic建議。B queue型別、ABI、排程頻率、生命週期仍缺；來源自稱已確認不直接升正式native完整通過。

新共用[來源審核索引](../../source-review-status.json) 以SHA追蹤最新來源審核，包含先前批次。前批pending清單保留歷史；本批105份已從單純來源索引進到限定內容／缺口處置，**不代表105份完整報告或全函式語意均完成**。[仍需查證](pending.json)保留完整語意、摘要原稿、來源映射、T10鍵位／動畫queue／cancel等缺口；先前source-only來源已逐份給處置，但完整語意仍未通過。T14、TC、全部owner/state與方法歸屬保持。

快照UTC `2026-10-27T15:22:26.433714+00:00`，2791檔／385666350 bytes，可恢復副本 `work/T01-20261027-05/local-snapshot.zip` SHA `ec7041f559e75bbe25aebe28c262c985b727916095ed5408f468a07c58e084d7`；不含.git與已保存bulk／exports／history，副本不提交。[凍結清單](frozen-inventory.json.gz)與[來源Git狀態](source-git-status.txt.gz)保存本地未提交狀態。原E:未切分支、pull、覆蓋或清理，原anal唯讀。[凍結後變更](post-freeze-changes.json)不屬接受範圍。

驗證結果見[validation.json](validation.json)，後續問題見[NEXT-QUERIES.md](NEXT-QUERIES.md)。本批已正常推送 origin/main：[整合commit](https://github.com/we88ec3-prog/ttr_anal_multi/commit/f15b2c0f7c7669afe408de14bb9a61f0e57e4268)，SHA `f15b2c0f7c7669afe408de14bb9a61f0e57e4268`；實際遠端確認見[推送收據](push-receipt.json)。其他任務以此commit或包含它的較新main接續；獨立分支 `codex/t01-integration-20261027-05`。其他任務依最新逐SHA清單去重；交接僅用文件，未傳訊至其他對話。

補入早期16份報告時，對構造／網路／場景已覆蓋內容連回既有claim及更正；另外新增兩條T09局部碰撞／BND表示觀察。未整份接受早期彙總草稿。
