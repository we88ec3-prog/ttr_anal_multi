# T01-20261028-06 線上與本地來源整合

日期：2026-10-28（Asia/Taipei）；操作者：Codex T01 integrator。分析來源：roy／chatgpt-web roy。遠端基準 `b8e97085c08833f66fbd06ee4ef3bf7d32276409`，前批 `ded455529468b01ce7d2640eebc46290e5d7ae7b`；本地來源 `08a08599c4dac2febab869523780cabf39806b69`／`codex/kr-t06-roy`。在獨立分支 `codex/t01-integration-20261028-06` 整合，不在dirty E:工作區pull。

遠端新增109提交／100份報告；本地新增變更4693檔。[本地清單](local-items.json)保存546個選定版本，[線上清單](online-items.json)逐份列來源SHA／分析者／正式位置／限定處置。新增509份去重artifact、29筆限定觀察／缺口、12筆更正。[接受範圍](accepted-claims.json)分類為原生已確認2（僅指定來源字節事實）、部分確認23、AI替代1、資訊缺失3；不是整份來源或函式皆通過。

T16「任務與劇情流程」已分KR/TC登記至catalog／SQLite，總32任務。兩版均owner null、state unclaimed、native_complete false；T04初始化、T07場景、T14關卡結算、T15保存與方法主責保持，不因新Task轉移舊功能。TC只接受其自身資源／字節與版本差異，沒有套KR native位址或opcode。

[資源來源校驗](resource-source-audit.json)：4409份deliverable清單SHA／大小、2107份資源manifest SHA與快照相符；指定carrier獨立重解96成員並比對6個直接來源檔，12個Lua chunk的216個prototype／3450指令字、常數與完整消耗皆核對，沒有執行Lua。[原件bytes校驗](online-byte-source-audit.json)含100份報告的14009個保存byte視窗，以及38個本地視窗，均與指定SHA原BIN的PE section映射相符；只是源bytes／局部算術／資料一致性，不等指令邊界、完整CFG或全部語意驗收。

[引用校驗](source-reference-audit.json)612項：561個檔案SHA與50個內嵌span相符，1外部歷史版本缺口保留。新證據解除線上T16沒有Lua/XML、T10沒有實體KeyMapping的資料阻塞；Tip/TutoQuest與Shout/HasQuest真實資源域、KR/TC Part1及獎勵差異分開。[更正](resolutions.json)也撤回003D角色切換排除與v8既有003D handler歸因，保留Town／場景／Map域；token只原樣回送，不猜Case103。PE/flat視角差異已有原件來源佐證，僅確指同raw時才作-400換算，不全域改方法或宣稱B queue ABI完整。

正式證據在 `kr/evidence/<SHA>.txt`、`tc/evidence/<SHA>.txt` 或共用出處的 `unclassified/evidence/<SHA>.txt`，保留原bytes且惰性。相同bytes跨版只去重儲存，各版attribution／carrier核對仍獨立，不推API同義。[方法引用](method-references.json)只引用既有entry，不新增錯誤入口或改派entities。

快照UTC `2026-10-27T21:21:04.144600+00:00`，7480檔／524796506 bytes，`work/T01-20261028-06/local-snapshot.zip` SHA `efefe216a1c5a92602fb8ee183814a549413a268cbfc22220c0e321ff9690af5`。排除.git、既存bulk與exports/history；不提交整份歷史或無關Item/Product等大表。[凍結清單](frozen-inventory.json.gz)、[全部新增處置](local-dispositions.json.gz)與[來源Git狀態](source-git-status.txt.gz)可恢復追溯。未選的資源／衍生text／baseline只保留原處與快照，未標已接受。

[未完成](pending.json)仍包括官方server勝利／獎勵、教學尾端到Quest16完成／Quest15可接、精確重登與角色scope、世界地圖同步、村spawn／往返，以及T10 phase到動作queue/cancel。候選Server helper／v9只保留明示AI重建，不部署、不把離線check當可玩驗收。工具原稿以.txt惰性保存，不執行歷史腳本。

驗證見[validation.json](validation.json)，下一步見[NEXT-QUERIES.md](NEXT-QUERIES.md)，[凍結後變更](post-freeze-changes.json)另批處理。本批已正常推送 origin/main：[整合commit](https://github.com/we88ec3-prog/ttr_anal_multi/commit/b8c95431063436d24ca473876b937e4a9152210d)，SHA `b8c95431063436d24ca473876b937e4a9152210d`；遠端確認與接續基準見[推送收據](push-receipt.json)。原E:及anal保持未覆蓋／未清理／唯讀，無遊戲啟動／附加、目標API、client或資源／帳號／存檔修改。其他任務依批次SHA去重；只透過檔案交接，未向其他對話發訊息。
