# T10 roy 045–088：中段R0/R1交接

44份實際narrative已逐篇閱讀，未完成0份。`proposal.json`按功能去重16組：12 PARTIAL、2 UNKNOWN、2 REFUTED。每組`source_refs`是權威關聯，逐項保留精確blob/SHA、單一`[lo,hi]`行範圍及scope observation；`sources`保存逐篇處置、限制與精確原文摘錄。

兩個REFUTED只沿用已提交的既有反證：T01-RETURN-T10-062-001針對第12行特殊域初始化/普通clear順序；T01-RETURN-T10-063-001針對第12行捏造的writer ESI<=27 guard。其他清零、namespace與明示未知範圍仍可PARTIAL導航，不把整份FAILED來源變成所有子scope均無用，也不覆寫歷史FAILED。原文reset selector不命名為keydown/keyup，無guard不證明上游可輸入任意ID或有漏洞。

053/055/056沿continuation02：核心有界研究保留，錯位頭與泛稱指令已確認需限定；明示.byte尾部截斷/顯示續行不是語意反證。本批沒有引用continuation03未提交候選裁決，057/058/059均不因候選結果升級。

081/082取得正式內容定址XML是相對早稿缺料的研究進展。保留Type0/1、basic/Extra、ModKey及工作bank2的差異：預設Key/MapButton字面列不是現用配置、DIK producer證明或動作opcode。配置DWORD writer不等runtime phase byte writer；command68局部派送不等wire契約。

已對照`research/claims/index.json`。尚無與本批輸入/config/phase具體scope等價的canonical項；NET-0005/0006 transport、CLIENT-0019 actor slot與CLIENT-0022 scene dispatch只是相鄰研究，不能因方法/slot相同合併。本批`existing_claim_ids=[]`，根整合者可合併同輪T10其他scope的重複主張。沒有新Server SPEC適用契約，`affected_spec_ids=[]`。

`build_proposal.py`重建人工歸組，`validate.py`核對44來源身份、原文行號、權威refs及兩個反證隔離；結果見`validation.json`。重跑：repo根以`python -X utf8 -B`依序執行這兩支程式。驗證PASS不代表原生或全文通過。

R1在來源身份、限定主張、衝突與S00用途記錄後停止。後續若有具體設計阻塞，才問scan-code→非零phase、具體receiver→motion/queue/cancel、現用設定/fallback或list-ID值域；不展開全native重驗，不通知作者新錯誤，不改原稿/Task/全局/Git。本批新增NATIVE_VERIFIED及全文FULLPASS均為0。
