# 下一階段：逐篇語意驗收尚未完成

從本批推送收據所列commit或包含它的較新main接續；先核對 [source-ledger.json](source-ledger.json) 的完整路徑、blob SHA與SHA256，不以段號或檔名去重。範圍凍結於318篇；凍結之後的來源另立批次。

1. 先處理對應Task README的NEEDS_FIX。FAILED原稿保留原SHA；修正版須用獨立SHA，逐項複驗受影響的控制流、資料流、上下游與偽碼，不能把舊版改判FULL-PASS。
2. T08早期：24篇映射來源逐點改正PE標籤，再重建真正caller/callee／表值關係；153補erase輸出iterator ABI，155/157重解正確指令界線。154/156 getter說法與158的更正關係待完整裁決。79～100實際21篇後續未開始；101～129及160～169的閱讀／CFG保存不等逐篇完成。
3. T08後期：依 [phase-checkpoint.json](t08-new/phase-checkpoint.json) 補全部未簽核主張、被呼叫者與碼塊。173/183/187/196已具體退回；不要把hash/list名稱索引和actor ordered tree混同。
4. T10：依 [decisions.json](t10/decisions.json) 每篇碼塊行號及內容SHA繼續；007、026、062、063的地址、函式歸屬、時序及不存在的guard須修正。11來源內14條局部主張不等11篇全文通過。
5. T16：先補 [pending-sources.json](t16/pending-sources.json) 的25篇及 [pending-findings.md](t16/pending-findings.md)；再逐篇補足其餘72篇全部肯定主張。56字的錯誤TutorialBase SHA不可當合法SHA256，修正來源身份後再查Lua/XML；Lua CALL C=2是1個result。不得把歷史環境缺檔當成當前永久缺失。
6. 新准入正式共用知識前，逐一確認必要原件、PE/VA/raw、指令界線、全部相關CFG及資料流、反例、來源版本與範圍。其餘局部支持只留審核台帳。Client未知、Server待開發、跨功能整合、遊玩待驗證分開，不猜值。

本批三項精確FULL-PASS和69個原稿反證不會自動完成其餘主張；318篇全文FULL-PASS仍為0。使用者的階段收尾僅凍結進度，沒有撤銷品質門檻。
