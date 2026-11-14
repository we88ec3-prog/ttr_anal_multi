# 羅特魯亞主線 Q94、Q108

韓版 QuestInfo 的前置為 Q93 → Q94 → Q108。兩個任務的發起與結束 NPC 均為 10012，要求 Lv.18。Q94 在城內播 Scene 1。Q108 的 Field 38 唯一對應 Case 115，Scene 1 開啟單人編隊，回村播 Scene 7。 [QuestInfo](../../kr-temp-roy/T06/evidence/original-QuestInfo.xml)

| 地圖 | BND | 入場／清場劇情 | 試行群組 | 怪物 HP |
|---:|---|---|---|---|
| 808 | adelrin01.bnd | 2／無 | 2 | 120 × 2 |
| 809 | adelrin02.bnd | 3／無 | 29 | 120 × 2 |
| 810 | adelrin04.bnd | 無 | 11 | 120 × 2 |
| 811 | adelrin12.bnd | 4／無 | 23 | 120 × 2 |
| 812 | town003.bnd | 5／6 | 28、17 | 頭目 1020／PRE 1 為 520，1002 為 120 × 2 |

原始 Chart 的唯一 NodeLink 依次指定 808～812，每圖選擇率 100%。Scene 4 的暫時演出使用 adelrin07X，位於第四節點的觸發時點採 Server 候選，演出結束後重建實際戰鬥圖 811。最後一圖的 town003N 是副本，通關後返回羅特魯亞城內圖 199。Scene 5 中的 1020 有來源 Cluster，Server 選它作為必要頭目。1124 未列入試行戰鬥群。所有怪物群分配、出生及出口為 Server 編排，位置使用原版 BND 可通行區。 [五圖配置](rotrua-lost-obolus.append.json)

| 原件與測試工作目錄比對一致的成員 | 解碼 SHA-256 |
|---|---|
| Field/MapFlow/CHART_S_Lostobolus_01.xml | `034a4f434a03b1948b7cab0f87cfa37d6b50c03e08c8ee4ba444523c2b6e94ae` |
| Field/Cluster/CLUST_S_Lostobolus_01.xml | `d2b3ef573a45182d40bf7df6d308c457b392b93492d3f9ee39bac104e6001a31` |
| Event/Sequences/Rotrua_LostObolus_Stage03.seq | `caae345cdbe3629f2c01592015e2466e6729cf5ec0f1db710d2292f4cb7f0199` |
| Event/Sequences/Rotrua_LostObolus_Boss.seq | `0410d6b4283867333933644b93ab7a55d56e9fbab25e88fee37200468e77d90a` |

Q108 依原表結算 47,450 EXP 與 1,728 LeeLoo。type 3 的 180 仍待確認。經驗政策 v6 保留 v2～v5 的門檻及獎勵，啟動時可用 `TARTAROS_LOCAL_STORY_EXPERIENCE_HISTORY__<index>__PATH` 和同索引 `__SHA256` 由舊到新指定歷史政策。錢包政策保留 Q89 已啟用的補發規則。 [錢包政策](rotrua-q108.story-wallet.json)

合併檔由 Q93 版本追加附表地圖和任務，並把 Q93 版本及舊任務序列追加到 `previousVersions`。`version` 設為 `rotrua-q108-candidate-v1`，附表 SHA 作為 `sourceBaselineSha256`。合併 SHA 為 `4a52188389046a3ba6a60616fb12375b57fd75d2d0749dea3f8904b257d6a988`。Q119 覆寫改綁合併檔 SHA。基線關卡圖 SHA 為 `740f8ecd2c2e67f7a5e4ab8d76ae9251500a8734dcc28caa9a99195b03f4d659`，成長與覆寫啟用後為 `1d73d7a06c8a7db19cb02827b10a285c24a67d8749d9c93c5c828b96a32d83e5`。

從馮德斯走完前置及 Q108 的原版碰撞離線正流程已通過。核對五圖怪物血量、讀取存檔、回城地圖、角色經驗及錢包封包。測試角色回村為 Lv.20、375,010 EXP、滿血 975。指定 v2 的演出、走路、戰鬥節奏和獎勵畫面待驗收。
