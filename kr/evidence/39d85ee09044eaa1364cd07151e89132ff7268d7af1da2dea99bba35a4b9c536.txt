# MissionLobby／Town預載依賴與Server現況

roy／T07，必要跨T02/T05/T08/T14分析，待整合。原BIN SHA9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。使用REA6.5.0/Ghidra12.1.4 bulk、原件保存bytes；不啟動／附加遊戲或Server、不改client或原資源。

## 0099/type3的完整局部生命週期

0099/4B9320只接受BYTE+2==3，建立CMissionRoom（MISR），註冊4BCB40，再4B7D50同步install，完成後才寫全域mode3。vtable C07098取自原件：

|slot|函式|有限語意|
|---|---|---|
|+10|4BCBA0|init，清理指定manager、controller重用／新建kind1 CMissionRoomController、UI4|
|+14|4BCEB0|exit，553740及清FE18C8向量狀態；不是空hook，也不能當通用all-actor-clear|
|+18|4BCF60|tick，53FF50等、特定待顯示訊息向量；最後呼叫4ADB10|
|+2C|4B2570|ready，controller+4=1及既有UI/input flag條件；沒有map／綁定完整性驗證|

4ADB10更新CheckPointMgr中的checkpoint，然後呼叫scene v24。這是共享tick路徑，不在此擴充為每一個目標API呼叫已測。

5877F0的UI registry在key4放FUI::CMissionLobbyPage（建構沿5B5020共用頁），key2是CSquarePage、key1是CExpeditionPage。故UI4有具體原生類別依據，不是單純任意整數。前批kind1控制器的ready→5452C0→546100輸入路徑，以及548350→544A00 NPC互動仍成立。

以上支援**MissionRoom是有控制器／NPC互動的Lobby場景**，但沒有哪個上述函式直接說Town1/Map182。不能只看類別名或UI4便把正常村落場景歸屬標成已證；Server使用此候選時仍需明示重建政策與實際驗收。

## 0038的Town預載不能替代0012

0038/4B1BF0的type0（另有type5共通尾段）取WORD+3 TownID，傳540A40並寫FAB1BC供任務候選查詢。540A40→541C00解析TOWNLIST，選中Town ID後從NPCLIST取NPC ID/CATEGORY/PREFIX壓成預載ID，再541F90加入PRELOADLIST共用項、5417E0處理。預設NPC CATEGORY6、PREFIX1只屬預載ID編碼。

此路徑沒有因此讀出Map182或正常出生座標。原_TownList的Town1含NPC10047等，Town5含10338等，支持NPC預載／任務Town context；不等於NPC生成，亦不提供位置／互動範圍。正常進村仍需獨立0012/實體Map、同一reset世代的actor生成綁定與ready；不能把0038 Town1當成自動載入村落的捷徑。

## Server現況與更正

唯讀核對目前tutorial-plaza-v8/overlay/login_test_server.py：318行附近角色切換實際是**C2S000C、len6、DWORD角色ID**；334行附近廣場中的0040/0028明確只記plaza-instance-request-unimplemented。365行起仍只處理回Map511，沒有完整Field19一般副本／進村路線。

前批TOWN-UNLOCK-AND-TRAVEL-GATES.md曾把「Server將原003D教學切角舊fixture語意分開」列為開發項。**這個現有Server歸因撤回**：本次直接讀活動候選原始碼，未見003D handler；不能因舊分析／記憶就聲稱v8有那個分支。原生003D的Town合法性檢查更正不受影響。後續應新增方向與長度明確的Town旅行處理，而不是宣稱已修掉不存在的003D角色切換分支。原文保留以供追溯。

## Field19出口證據限制

本次Field.stp精確索引範圍：.mef及pathofpindus查詢只命中CHART與CLUST兩XML，未命中MEF成員。只代表這個carrier範圍，不能推成全client沒有腳本，也不能把叢集COUNT／Chart最後節點猜成官方勝利政策。已有TRIGGER檔名字串不能復原伺服器腳本內容。

## 必要後續

- 閉合正常Town1場景選擇與實際map／合法位置的來源；保持Town分類、場景type、Case103、Field19、Map191/192/182分域。
- Field19事件／勝利與0033結果返回後的15/3續接及提交，不假完成或直接傳村跳過副本。
- 世界地圖I1到配對Town選擇狀態的同步與003D旅行應答；村→廣場另核0042/0059 gate。
- 新獨立Server候選才接上述流程；目前v8和使用者資料未修改，沒有新增runtime成功證據。

7項有限局部核對、v8來源SHA與摘錄見mission-lobby-dependency-evidence.json。目標完整範圍保留，未達成進村／往返驗收。
