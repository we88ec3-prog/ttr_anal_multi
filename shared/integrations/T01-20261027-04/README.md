# T01-20261027-04 成果來源審核與整合

日期：2026-10-27（Asia/Taipei）；操作者：Codex T01 integrator。分析來源：roy、chatgpt-web roy、claude-web roy。遠端基準 `f01094e66471f74e70bbf8a751312138b0f4b510`，上一批最終commit `b07c0c2f428af1bae9106d2ec5e8add55bbcb293`；本地來源 `08a08599c4dac2febab869523780cabf39806b69`／`codex/kr-t06-roy`。本批以最新遠端為基準，不以來源舊catalog覆蓋。

本輪保存242個本地來源版本與129份遠端報告，新增383個去重artifact、27筆限定觀察／缺口／AI重建分類與12筆更正。[本地清單](local-items.json)、[線上清單](online-items.json)逐項列任務、分析者、SHA、正式位置與處置。未連到限定結論的報告只納入來源索引，仍未逐項原生語意審核；保存不等於接受全部內容。

正式結論與更正位於 `shared/catalog.json`／SQLite，證據為 `kr/evidence/<SHA>.txt` 原bytes惰性副本。[接受範圍](accepted-claims.json)包含T07一般Scenario、0047/003F、空預選編隊、Case103預載key、0022結果與0033返回；線上T08資源／容器、T09輸入同步及T10 Bank／predicate只有明列範圍。原生已確認標記未新增，全部維持部分確認、資訊缺失或AI替代，沒有完整方法或遊玩驗收。

[12項更正](resolutions.json)按證據而非日期裁決：Case、STAGE、Quest與Map域分開；0047不同0045；結果角色說明確認亦可回0033；結果背景不是spawn；FE1A88/FE1AA0不同；名字樹／heap Provider不混型；5452C0 DWORD來源F93944以已存快取支持，不接受舊殘值說法。Knowledge base的未解owner條目未吸收129的具體指標鏈，保留兩版與論據。

T08同SHA報告129以PE `.text` VA401000→raw400，141/152卻使用平鋪VA-401000，差400。來源映射尚未統一，本輪不選猜根因、不私自補正vtable槽位、不登記指令中間為確定入口；候選型別、B consumer ABI與生命週期風險仍待核對。直接xref或raw DWORD零命中、特定reg寫入掃描都不是全程式不存在的證明。[方法引用](method-references.json)保留獨立入口缺口，所有既有entities與主責保持。

凍結截止UTC `2026-10-27T14:59:13.588412+00:00`。本地2791檔／385666350 bytes，可恢復副本 `work/T01-20261027-04/local-snapshot.zip` SHA `3792e087c92378f6cefdbf6da13afbaa0d2fdfd7b216fdd6a02ed33d84a805a5`；排除.git、已上傳bulk、exports/history等再生或歷史目錄。快照不提交，僅提交[SHA清單](frozen-inventory.json.gz)與本輪必要來源。[引用校驗](source-reference-audit.json)340項：314檔案SHA、23內嵌span與2既有catalog精確SHA成立；1外部引用未打包。[來源Git狀態](source-git-status.txt.gz)與[根目錄／bulk索引盤點](source-inventory-summary.json)另存；本地bulk索引與遠端完全同SHA，只對本輪引用的方法另核對個別bytes，不重做已完成全量分析。來源工作區未改動，原anal保持唯讀。

[未完成項目](pending.json)列出摘要完整原稿缺失、未逐項審核報告、缺少獨立入口與映射衝突。影片、現用資源及重建候選不當官方序列；官方勝利／發獎、004E ID、0038+5、合法村spawn與雙向旅行仍缺。既有T14分析狀態不因來源檔中的跨Task授權敘述改寫；本輪只審核已存成果，未展開功能逆向。TC無新增原生資料，不套KR地址。

[凍結後變更](post-freeze-changes.json)與之後新增的遠端提交不列本批已審核；推送前若需合併較新main，另記來源差異。每項是否已整合以來源SHA與claim範圍判斷，不以原暫存仍存在判斷。驗證見[validation.json](validation.json)，接續問題見[NEXT-QUERIES.md](NEXT-QUERIES.md)。

本批已正常推送 `origin/main`：[整合commit](https://github.com/we88ec3-prog/ttr_anal_multi/commit/3ee8df80feb347f1863805ac909cb3431cbd5d29)，SHA `3ee8df80feb347f1863805ac909cb3431cbd5d29`。實際遠端確認見[推送收據](push-receipt.json)，其他任務從此commit或包含它的較新main接續。本輪獨立分支為 `codex/t01-integration-20261027-04`。不發訊息到其他對話；受影響任務README／task.json及共用通知索引已留檔案入口。
