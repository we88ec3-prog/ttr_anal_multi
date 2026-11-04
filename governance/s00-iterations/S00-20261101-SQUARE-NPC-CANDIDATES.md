# S00：廣場NPC名單、模型與暫定位置

接續REQ-0017出口候選，戰鬥v6實測仍待回；沒有更換服務／操作或修改Client。
本輪補上進廣場後的NPC actor資料候選，避免只有玩家與地圖。不是完整對話／任務驗收。

## 原始資料能支持什麼

新檢查器 `governance/inspect_square_npc_resources.py` 唯讀釘住現用及原始備份Table：
現用SHA `ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c`；
原始備份SHA `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。
`_TownList.xml`、`_ActorList.xml`兩member bytes相同；所選12個npctable row除NAME外的
欄位一致。這是精確選查，不擴張成所有資源／翻譯完整性證明。

Town5名單：10013、10014、10015、10016、10049、10050、10051、10069、10094、10101、
10026、10338。每個都有PRE1 actor模型記錄和NPC表記錄。Town5清單不是官方Map511對應或
NPC放置資料。原始／現用TownList member SHA
`bba254efd72fac0be6c51c6135423601effcbad02448f46aadec3324e449d660`，ActorList
`b01ae70817c79126b89292567e32d4c806c3ef31478b6a2eb96dcfd21e2c78f7`。

Character/Npc/Base.stp SHA `1b74183c48f7ca3c0e7185d3f814b31f4e2825e34d49087fc0c85115f2e0f92b`。
12個選定ABF皆有待機motion1。舊註解「NPC ABF沒有motion7」不能全稱沿用：本次12個中
Michel有7，其餘11個沒有7。Server候選用state1，不以dead state強迫播放7。
member SHA與有限動畫存在檢查詳[來源metadata](evidence/S00-20261101-SQUARE-NPC-RESOURCES.json)。

既存原始KR Ghidra4AE4D0 SHA
`0601c5f9add217052b3d17337643e399038c56f3dd697062fd9b20f1c2e8f6c1`中case6呼叫4D2120；
4D2120 SHA `48745f04df0598a73cde8ed3d7508a7f40d6690d34587c61256f0149500906cc`
是CNPC建構。此處只引用既存有限解析與26-byte actor row共用布局，不把完整接收函式或
未知欄位升FULL-PASS。entity低byte6與PRE1是不同欄位；scale1不是高度0。

## 舊位置有三個阻擋格

唯讀舊 `anal/plaza_npcs.py` 已明註「位置為900/900附近暫定值、MEF放置未知」。
所以這不是完全沒有留下分析；不能只照抄其「Native plaza NPCs」標題就認為座標原生。
本次檢查map511 square001 BND時，發現舊12點中3個來源層非0：

| model | 舊Server暫定座標 | 新Server暫定座標 |
| --- | --- | --- |
| 10050 | 950,940 | 930,910 |
| 10069 | 870,965 | 850,910 |
| 10094 | 890,965 | 870,910 |

其餘9點保留，完整表在metadata。新12點兩個來源層皆0，取樣按world1536→grid768轉換。
這仍只是靜態點，不證角色體積、動態override、可到達路徑、NPC朝向或官方正確位置。
舊檔／原始資源未改；未把原場景劇情NPC座標869/1052誤移植到另一張map。

Map/Map/Town.stp SHA `ccd66c13d6b0613372fe2d1f4c77f9ef906f12cb50b23ca791e1d429da55b0c8`，
Town/square001D.fld SHA `0b0ce7cf428c9aa4affc68a7b02aaae2feca963436bdd8c7a0054a93f7eb05f1`。
此有限FLD有351個Object tag，未找到上述NPC ID的十進位字串；不能由這一點宣稱所有
Client放置資料不存在、必須下載MEF或已排除alias／其他封裝。_PositionList亦不能僅憑名稱
當NPC位置表；本輪沒有建立NPC→該索引的映射。

## Server接線與限制

獨立EXIT候選在43後map／最後reset、玩家重建／綁定之後，送12筆0007/class6 actor，
entity0106..0C06，PRE1、各自model、scale1、state1。owner欄沿用舊NPC fixture的model值，
這是候選，沒有冒稱原生玩家帳號alias或官方完整body。再沿既有14 activation。
初始化與Host啟動前都檢查每個NPC點，避免路徑／資料或阻擋問題等到玩家走完才拋錯。

本輪**沒有加入0027互動點、38/Town5業務context、completed bitmap、Quest15接取或結算**。
沒有重用舊「15/1即完成15」與把QuestMgr5030C0標成4C的已知錯誤，也沒有修改Client對話距離。
NPC actor可顯示、能拾取／對話、任務可接、教學完成是不同驗收項；目前只準備第一項資料。

16個HappyPath合成cases通過；完整新帳號TCP／SQLite出口列檢查12個不同class6 entity、
精確model集合、PRE／scale／state，再走玩家移動／停止及heartbeat。
仍是合成fixture，不是遊戲畫面驗收。208方法／10正向／198暫緩不變。
原版放置、資源別名／缺檔、不同NPC互動、重複生成／跨場景清理、故障／併發／安全／壓測
記待測，現在不執行。Quest16結算與完成持久化、loading與實際同登入操作仍未完成。
normative pin、formal admission、Task owner及APPROVED狀態不變，整體goal保持進行中。
