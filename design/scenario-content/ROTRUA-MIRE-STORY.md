# 羅特魯亞主線 Q146、Q147

QuestInfo 的前置為 Q145 → Q146 → Q147。Q146 與 Q147 由 NPC 10025 啟動，均要求 Lv.20。Q146 在城內播放 Scene 1。Q147 原表結束 NPC 為 10022，清場 Scene 4 已包含該 NPC，Server 依既有主線流程在清場、走出口及結果返回後提交。 [QuestInfo](../../kr-temp-roy/T06/evidence/original-QuestInfo.xml)

Q147 的 Field 40 對應 Case 117。Chart 唯一 NodeLink 依序指定 814～818，各圖選擇率 100%。Scene 1 為編隊前空白場景。Scene 2 與地圖 816 的模型一致。Scene 3 及 4 的暫時地圖為 icecrystal12X，Server 候選將它們排在地圖 818 的入場與清場，演出完成後重建原戰鬥圖 icecrystal13X。

| 地圖 | BND | 入場／清場劇情 | 候選群組 | 怪物 HP |
|---:|---|---|---|---|
| 814 | icecrystal02.bnd | 無 | 2 | 129 × 2 |
| 815 | icecrystal05.bnd | 無 | 8 | 129 × 2 |
| 816 | icecrystal08.bnd | 2／無 | 14 | 129 × 2 |
| 817 | icecrystal10.bnd | 無 | 19 | 129 × 2 |
| 818 | icecrystal13.bnd | 3／4 | 40、34 | 頭目 1038／PRE 1 為 559，1020 為 129 × 2 |

末圖的 1038 與 1020 均出現在 Scene 3，且有來源 Cluster。逐圖群組、頭目指定、演出時點及出入口是 Server 編排。出生與出口取自原版 BND 的可通行區。 [五圖配置](rotrua-mire-story.append.json)

| 原件與測試目錄一致的解碼成員 | SHA-256 |
|---|---|
| Field/MapFlow/CHART_S_Mirstory_01.xml | `60133f7c04c58cb5fe61d5d53c22cb611936af272f7d8732169fe1ff0263f976` |
| Field/Cluster/CLUST_S_Mirstory_01.xml | `b9fcd6c860757a4342b434ffc3a85b83c40a4ca3288fd54e3228714bf5ada58a` |
| Event/Sequences/Rotrua_MireStory_Boss.seq | `2d06c976b54c93c598663b5aa93300ead9d52d92fea11f575ff9e45ae0a8126f` |
| Event/Sequences/Rotrua_MireStory_Boss_Clear.seq | `7533d0f119775a1a61784dc0d4291d4a257948249a135bab1296862aeead3650` |

按 QuestInfo 的 type 2、4 結算 55,772 EXP 與 2,520 LeeLoo。type 3 的 180 用途待證。經驗政策 v8 固定相同 Lv.1～21 界線，保留 v2～v7 既有任務獎勵。 [錢包政策](rotrua-q147.story-wallet.json)

將附表地圖與任務追加至 Q145 版，`version` 設為 `rotrua-q147-candidate-v1`，`sourceBaselineSha256` 設附表 SHA-256 `d966936be7422ca261495becf0982daba15fa76429e95d92655cddb04f281f74`，將 Q145 版本與任務順序追加至 `previousVersions`。合併內容 SHA 為 `a2792c8ce020ae36959bd855a411f4b168e57f3bdbedca3da4fd9a4ecb0fe30b`。Q119 覆寫改綁該 SHA。基線關卡圖 SHA 為 `9c04e14eb32d7451e284f2ba2d440b0148ce899d9cf9fa61532ba1f59b4beae9`，啟用成長及 Q119 覆寫後為 `c6394bed30cffd36280da9333cb5db2c9db583031c1eab4afdc5273764d891a8`。

從馮德斯走完整段離線正流程，核對 Q147 五圖、逐圖傷害、場景完成回報、結果返回、回城封包及存檔。測試角色回到地圖 199 時仍 Lv.21，累計 482,407 EXP，滿血 1,000。v2 實際演出、操作與戰鬥節奏待驗。
