# 羅特魯亞首段主線 Q65、Q66、Q89

韓版 QuestInfo 的 `Demands` 串成 Q144 → Q65 → Q66 → Q89。Q65 的 Field 469 是任務原表欄位，本次依場景資源安排為城內對話。Q66 也是城內對話。Q89 的 Field 36 唯一對應 Case 113，推薦 Lv.16。正常完成 Q144 的存檔依舊版的 22 個任務 ID 還原到第三村第一個 NPC。 [QuestInfo](../../kr-temp-roy/T06/evidence/original-QuestInfo.xml)

| 任務 | NPC | 入場劇情 | 返回 |
|---|---:|---|---|
| Q65 | 10022 | Scene 1 | 地圖 199 |
| Q66 | 10056 | Scene 1 | 地圖 199 |
| Q89 | 10056 | Scene 1 後進單人編隊 | 地圖 199 並播 Scene 7，再結算 |

| Q89 地圖 | 碰撞檔 | 入場／清場場景 | 試行群組 | HP |
|---|---|---|---|---|
| 798 | peridot01.bnd | 無 | 2 | 114 × 2 |
| 799 | peridot05.bnd | 2／無 | 26 | 114 × 6 |
| 800 | peridot10.bnd | 3／無 | 7 | 114 × 2 |
| 801 | peridot12.bnd | 4／無 | 23 | 114 × 3 |
| 802 | peridot09.bnd | 5／6 | 1、32 | 頭目 1019／PRE 1 為 494，1020 為 114 × 2 |

地圖順序取自 Chart 的唯一 NodeLink，所有地圖選項皆為 100%。Scene 2～6 的暫時地圖依次為 peridot05X、peridot10D、peridot12X、peridot09D、peridot09D。將同一張圖的 Scene 5 與 6 分派為入場與清場是 Server 候選。最後一圖頭目與小怪同時存在。Scene 5 有 1020，Scene 6 有 1019，兩者皆有來源 Cluster。1124 只在演出及預載中出現，候選未將它列為戰鬥目標。逐圖使用的群組、出生及出口均為 Server 配置。出生及出口取自原版 BND 的可通行區，正常流程清怪後到出口按 Z。 [五圖與任務設定](rotrua-first-story.append.json)

| 核對來源 | 解碼 SHA-256 |
|---|---|
| Table/QuestInfo.xml | `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60` |
| Table/_CaseList.xml | `a6282323e287900512e515be01927ae3f75fa0c1540e0261473530eb0487043a` |
| Field/MapFlow/CHART_S_peridot_01.xml | `81f032b2a317e2720165dd1b87c21a2320f13f6dbbea22947a7eb20fb8fa2537` |
| Field/Cluster/CLUST_S_peridot_01.xml | `5c5786b02445acc81b9ee2167e0c497c62d2beef6c1aa09697b101d6db2fc818` |
| Event/SceneList.xml | `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25` |

以上成員與五個 BND 實際比對原件及測試工作目錄，解碼後一致。Q89 結算採原表 type 2 的 39,123 EXP，由參戰角色領取。原表 type 4 的 1,566 LeeLoo 發到帳號錢包，與主線進度及經驗同一交易提交。回村劇情結束且場景就緒時，Server 用 `002C` 公布餘額。原表 type 3 的 180 用途待證。 [錢包政策](rotrua-q89.story-wallet.json)

`-IncludeRotruaStory` 同時載入綁定 v4 的錢包政策，SHA-256 為 `ab955b3e5ee294488666d475c9c175c43d236ee983cc27c4d14fb808481aa3a3`。這份設定也包含前兩村十筆已核對的 LeeLoo 獎勵。現有結算只有在該次新發主線經驗時才發 LeeLoo，已領過 Q89 經驗的存檔需要另行處理錢包補發。離線從馮德斯重跑，確認 Q89 餘額增加 1,566、Battle Point 維持原值，且錢包流水只有一筆。

實作時以 [舊主線](../../governance/client-variants/20261107-town2-mainline/resources/alsmeer-full-mainline-content-candidate.json) 為底，將附表的 `maps`、`quests` 依原順序追加，將原主線 SHA 與原任務順序追加至 `previousVersions`。Q119 的成長覆寫須改綁新主線 SHA。合併主線 SHA 為 `86edceb6952ac34dad4f7f15655dfa2553dcdc6fea211afc8b2c9c996eda1962`，啟用成長與 Q119 覆寫後的關卡圖 SHA 為 `93fada6720f966243c49fefbbf0dfdc6d95f37af1cfe4fcc81afac814fb438f9`。BND 從 Client 的 `Map/BoundMap.stp` 讀取 `BoundMap/<檔名>`。

重現合併檔時，`version` 設為 `rotrua-q89-candidate-v1`，`sourceBaselineSha256` 設為附表的 SHA-256 `a3350be7358293e79075018e5902526f309b37571b5784c16a78b9c2b11b7d3f`，其他上層欄位沿舊稿。輸出使用 UTF-8，兩空格縮排、LF 與末尾換行。

離線驗證從馮德斯沿正常入口走過 Q144，續接 Q65、Q66、Q89，走完五張圖、回村看完劇情。逐圖核對擊倒所需的總傷害，結算後參戰角色累計 284,287 EXP、Lv.18，地圖為 199。指定 v2 的劇情演出、出入口位置、怪物行為與結果畫面仍待驗收。
