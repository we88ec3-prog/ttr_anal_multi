# W1：馮德斯主線任務／章節／合法結算

指定extra/roy1。先讀[總卡](README.md)與本輪使用者優先序。沿用自己的授權分析分支，
勿再擴充目前可用的登入transport；本輪準備明天下班後Server開發需要的馮德斯資料。

1. 唯讀核對QuestInfo／QuestTalk／Chapter／SceneList／Event／本地UI consumer。
   候選鏈15→117→118→119→120→121→122→123→124→131→132，跨至Town2的133；
   確認哪些是完整主線、前置／插入條件、村內終點與離村橋段，不能只用Town1/type2宣告完成。
2. 每筆列接取NPC／完成NPC、Town／Field／Case／Map／scene ID各自domain；逐scene序列、
   C2S觸發、S2C consumer與完成後下一入口。先交15→117的最小正常接續，再延伸整鏈。
3. 接取／達成／交付／Quest完成／獎勵／角色授予／Town開放獨立；6F完整snapshot與74等
   增量不能混用。合法條件、交易、保存是Server須設計的部分，不等待不存在的官服後端源碼。
   但未知Client欄位／原生反應仍須補證。Reward type必須追consumer，不猜EXP或貨幣。
4. 整理角色／等級／已學技能／任務前置對主線的影響，分清Server可選的重建規則與原版事實；
   不用降低任務要求／直接設completed略過正常內容。
5. 交付JSON/CSV或Markdown矩陣：quest、prereq、NPC、scene、field/case/map、觸發／回覆、
   結算條件、reward型別、來源SHA／置信範圍／未知及正常人工驗收點。

保留原稿；新增本目錄W1-RESULT檔，Commit／Push後回精確commit及blob SHA。
不啟動／附加／修改Client，不操作Server，不改Task owner或正式RR。核心AI／MEF與連段由S00處理。
