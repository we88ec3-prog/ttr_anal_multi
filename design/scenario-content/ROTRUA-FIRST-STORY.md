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

`-IncludeRotruaStory` 同時載入綁定 v4 的錢包政策，SHA-256 為 `ebe6ca418c0804c326274681a74f3d22d8c5754b5d915d48e3fbdee1af8a7462`。這份設定也包含前兩村十筆已核對的 LeeLoo 獎勵。離線從馮德斯重跑，確認新完成的 Q89 餘額增加 1,566、Battle Point 維持原值，且錢包流水只有一筆。

政策的 `backfillQuests` 指定可補發的任務，目前僅含 Q89。持有效登入工作階段時，Server 查該帳號在相容經驗政策下已結算的任務流水。若缺少同任務錢包流水，使用原結算版號補入 1,566 LeeLoo。餘額與流水在同一 SQLite 交易提交，由既有世界載入同步送出餘額。已領過 LeeLoo 的存檔再次登入時維持原餘額，經驗與主線進度均沿用已存紀錄。

實作時以 [舊主線](../../governance/client-variants/20261107-town2-mainline/resources/alsmeer-full-mainline-content-candidate.json) 為底，將附表的 `maps`、`quests` 依原順序追加，將原主線 SHA 與原任務順序追加至 `previousVersions`。Q119 的成長覆寫須改綁新主線 SHA。合併主線 SHA 為 `86edceb6952ac34dad4f7f15655dfa2553dcdc6fea211afc8b2c9c996eda1962`，啟用成長與 Q119 覆寫後的關卡圖 SHA 為 `93fada6720f966243c49fefbbf0dfdc6d95f37af1cfe4fcc81afac814fb438f9`。BND 從 Client 的 `Map/BoundMap.stp` 讀取 `BoundMap/<檔名>`。

重現合併檔時，`version` 設為 `rotrua-q89-candidate-v1`，`sourceBaselineSha256` 設為附表的 SHA-256 `a3350be7358293e79075018e5902526f309b37571b5784c16a78b9c2b11b7d3f`，其他上層欄位沿舊稿。輸出使用 UTF-8，兩空格縮排、LF 與末尾換行。

離線驗證從馮德斯沿正常入口走過 Q144，續接 Q65、Q66、Q89，走完五張圖、回村看完劇情。逐圖核對擊倒所需的總傷害，結算後參戰角色累計 284,287 EXP、Lv.18，地圖為 199。指定 v2 的劇情演出、出入口位置、怪物行為與結果畫面仍待驗收。

## 下一段 Q92、Q93 原表核對

Q92 依賴 Q89，Q93 依賴 Q92，兩者 NPC 均為 10056，要求 Lv.17。Q92 有一段城內對話，雖同樣記載 Field 37，播放地圖為 town003D。Q93 的 Field 37 唯一對應 Case 114，固定地圖順序 803 → 804 → 805 → 806 → 807。原表 type 2／4 為 43,273／2,196，可沿用已確認的 EXP／LeeLoo 結算通道。type 3 的 180 仍待確認。

| Map ID | BND | Q93 場景線索 |
|---:|---|---|
| 803 | iceman01.bnd | 無地圖專屬序列 |
| 804 | iceman04.bnd | 無地圖專屬序列 |
| 805 | iceman11.bnd | 無地圖專屬序列 |
| 806 | iceman10.bnd | 無地圖專屬序列 |
| 807 | iceman13.bnd | Scene 2 Boss、3 Boss_Clear、4 Boss_Clear2 |

Q93 Scene 1 是 Blank，Scene 5 After 暫時載入 town003N。Scene 2 建立 1035、1019，來源群組 30 有 1035／PRE 1 × 1，群組 6～11 有不同數量與 PRE 的 1019。Scene 3 的 1020 可在群組 34 找到，1124 僅出現在預載與演出。Server 可先以 1035 為必要頭目候選，與 1019 同場，Lv.17 的候選血量 507／117。逐圖群組與出生、出口、演出觸發時點須在接續實作驗證。

原件與工作目錄的 Chart 解碼 SHA 為 `7b679442a9d47cf4d12b00e273ade33a6b5c183535e6be0a48783db7dd64df74`，Cluster 為 `399a9991d68702f81b783e1a7eee0d5d4693dc55d269372e5a616130bbd17f1a`，兩邊一致。

Q93 的前四圖選群組 1、4、15、24，各兩隻 117 HP 普通怪。末圖用群組 30 與 6，1035 為 507 HP，與 117 HP 的 1019 同時入場。末圖入場播 Scene 2、清場播 3 和 4。出口用 Z 進結算，回村播放 Scene 5，提交任務和獎勵。這些為 Server 編排。 [Q92／Q93 五圖配置](rotrua-snowbattle.append.json) · [錢包政策](rotrua-q93.story-wallet.json)

新主線在原 Q89 版本後追加兩個任務及五圖，加入原 Q89 版本作為可接續的存檔來源。附表 SHA-256 為 `9b0cafa0bcf14b9f509c3f08bc2fb71531de450214c403c9cee5326bacd7f23f`，合併時用作 `sourceBaselineSha256`，`version` 設為 `rotrua-q93-candidate-v1`。合併主線 SHA 為 `feedfa432e408ab9edb6da3359d5d782dbeac882a06e549a78a560f22127aa40`。Q119 覆寫改綁該 SHA。主線基線關卡圖為 `9656eeeb40ad91ab175036e69c144bbd7c656d7c2f3e93ae1d4534971595f247`，啟用成長與 Q119 覆寫後為 `8185d93cf51ca9815b7c76db8ed1cbc274c62035a62533803eec00d2a53b31f4`。經驗 v5 延續 v2～v4 的門檻與獎勵；已保存的相容政策角色登入時以累計經驗更新政策版本。

離線從馮德斯進羅特魯亞並打完 Q93。五圖核對擊倒傷害總和、回村地圖 199，並確認入帳 43,273 EXP 和 2,196 LeeLoo。測試角色回村後為 Lv.19、327,560 EXP、滿血 950。v2 實機待驗。
