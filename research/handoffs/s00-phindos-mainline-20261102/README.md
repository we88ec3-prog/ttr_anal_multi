# S00：2026-11-02馮德斯主線準備／派工包

使用者要求：「明天目標完成馮德斯村主線任務，請規劃明天可以請別人分析的資料，盡量讓
明天下班後能讓你直接開發Server到完成馮德斯村主線」。後續指定extra/roy1、2、3保持
派工，由T01驗證整合；對話達長度上限即停止向該對話派工，T01不能繼續時由S00接手。
最新優先序：**AI／MEF與戰鬥連擊由S00自己處理**；三個extra對話先做尚未用到的馮德斯資料。

本包是可交接規劃，不是承諾明晚一定完成、正式RR認領、Task owner轉移或原生APPROVED。
本機v8測試期間不因這份規劃換版。現有教學目標仍未完整達成，不以新範圍撤銷它。

## 候選範圍與交付順序

原始KR BIN SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
本輪唯讀pinned Table的QuestInfo member SHA與前輪原表一致：
`5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`。
進村橋接Quest15(town5/field19/Demand16)之後，Town1/type2有10筆線性Demand鏈：

`15 → 117 → 118 → 119 → 120 → 121 → 122 → 123 → 124 → 131 → 132 → 133(Town2)`

其中118/132有field28、119有26、122有27、124有17。這只是靜態篩選候選主線，
不能把town/type或ID遞增直接當完整玩家章節；W1須對照Chapter／SceneList／事件與跨Town邊界。
暫將131/132離村橋段也納入準備，133作下一村邊界，避免把「到村」誤當「村主線完成」。
每筆任務／場景都要有合法接取、達成、交付、保存、已驗明獎勵與下一入口；不是單純播放劇情。

| 工作包 | 指定對話 | 本輪責任 | 首批可用成果 |
| --- | --- | --- | --- |
| [W1](W1-QUEST-CHAIN.md) | extra/roy1 | 主線全鏈、章節／劇情、任務條件與獎勵域 | Quest15→117及每段狀態／scene表 |
| [W2](W2-SCENARIO-RESULTS.md) | extra/roy2 | 一般副本入場／編隊／進度／結果／返回介面 | Field19、Case103、Map191/192與22/33結果契約 |
| [W3](W3-TOWN-RESOURCES-NPC.md) | extra/roy3 | Town1場景／地圖／bounds／NPC互動與村初始化 | Town1、map182、NPC／控制與合法spawn缺口表 |
| [Review](T01-REVIEW.md) | T01 | 獨立驗證、反證、分域與整合 | 逐主張可用／退回表，不以hash PASS冒充全文 |

請分批交付，先交能解除Server開發缺口的部分，不等整個村全部完成才回覆。
下班前的目標資料包：狀態機／typed IDs、每段封包欄位與consumer、場景／資源SHA、
正流程時序、可用初值與缺口、合法達成／獎勵的Server設計責任、可直接照跑的人工驗收卡。
暫不做負向、取消／重入、重登、競態、故障、安全、壓測等；記錄待測即可。

## 已知防錯項

- Quest15／Field19／Case103／Map191/192／Town1／Map182是不同域；編隊token另存原樣echo。
- 原本教學TUTO的4C不可直接當一般Scenario完成；舊資料指向22/type0結果與C2S33返回，
  各欄位仍須核驗。舊Python Server、fixture及舊人測不是原生事實。
- Field19兩張BND的header version為2；目前教學／廣場候選只接version0，必須先釐清，
  不能用all-clear fallback或隨便改version標籤。Town1 BND為version0/world1536。
- 場景動畫／結果演出座標不是合法玩家spawn；NPC可見不等於互動／任務接續通過。
- MEF原生格式／接收與核心AI、連擊窗口由S00主查；extra只引用相關缺口，不重做該主線。

各對話沿既有授權分支新增報告，不覆寫原稿／其他Task owner／既有退回。回覆精確commit、
各檔blob SHA、來源版本、已證／推論／Server設計／未知。T01驗證與S00規格接受是兩步。
派工成功、研究完成、原生驗證、可玩驗收分開記錄；沒有明確長度上限訊號，不把idle誤判停用。
本包不建立定時自動化、不承諾無限背景輪詢；S00在持續工作期間檢查／補派，遇長度上限停派。
