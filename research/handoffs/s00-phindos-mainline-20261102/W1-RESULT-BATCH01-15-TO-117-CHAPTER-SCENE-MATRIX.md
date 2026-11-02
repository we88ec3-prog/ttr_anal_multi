# W1-RESULT 首批 — 馮德斯（Town1）主線候選、15→117 接續、Chapter／SceneList 交叉核對界線

> **2026-11-02，extra/roy1，BATCH01/PARTIAL／可交 S00 的資源有界矩陣。** 本稿只交指定首批，完整村落主線及「合法接取／達成／獎勵／保存」的 Client wire 閉合尚未完成。不得把 Quest15 進村、完成 Quest117、或完成 Quest132 三種狀態混為同一個事件；更不能把到村直接算主線完成。本文件新增，不覆蓋舊研究，不改正式 RR/APPROVED、其他 Task owner、Server，也未執行、附加或修改 Client。AI／MEF 與連擊由 S00 自行處理，本稿不展開。

## 0. 權威來源、已核範圍與證據標籤

- 受派卡：[`W1-QUEST-CHAIN.md`](https://github.com/we88ec3-prog/ttr_anal_multi/blob/017d85c88c2ca4651ed6e309a0c6173ac2cb362f/research/handoffs/s00-phindos-mainline-20261102/W1-QUEST-CHAIN.md)，總卡同一 commit 的 `README.md`。
- 附加資源基準：[`RESOURCE-BASELINE.json`](https://github.com/we88ec3-prog/ttr_anal_multi/blob/27c1faf7d2fd1a03c97c0465657d9d34dd1cf6cd/research/handoffs/s00-phindos-mainline-20261102/RESOURCE-BASELINE.json)，精確 Git blob `5ac883881d3ab0c711ad7c0bdd84c4dd3c2e5cd6`。本首批 Quest/Case/Town/Map 欄位取自此 **pinned 靜態資源抽取快照**，不是此輪重新解包整包 Table。
- 本地原始 `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，已重新唯讀核檔；**沒有為這批尚未取得的 Quest Scene/native handlers 冒稱機器碼 FULL-PASS**。
- 本地 `Table.stp` SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`；`Event.stp` SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。pinned 基準中 `Table/QuestInfo.xml` 成員 SHA256 `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`，所註載體 SHA256 `ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c` **不同於本地 Table.stp**；不能據此宣稱本地檔中已直接取出相同成員。若要獨立核對成員，需要精確同版載體及經驗證的 STPD 解包。
- 對本地兩個 STPD 容器只做 **封裝目錄（STPI manifest）字串層級**檢查：Table 索引位址 `0x004F90B4`（十進位 `5214292`），Event 索引位址 `10889940`；兩包均可找到 `SceneList.xml` 名稱，Table 有 `QuestInfo.xml`／`QuestTalk.xml` 名稱。這是文件存在候選，不是其內容或 Quest↔scene join 已解析。檢索這兩份封裝目錄沒有名為 `Chapter` 的字串；**不能因此斷言遊戲沒有 Chapter 資源**，它可能存於其他載體、其他命名或內部資料。
- 證據分級：**P（pinned resource raw attributes）**、**L（local container manifest/hash）**、**J（相同數值的候選 join）**、**D（新 Server 自主設計）**、**U（沒有正向來源／未知）**。P/L 本身不等於 T01 NATIVE_VERIFIED；`STPI` 名稱只是 manifest。所有 Chapter/Scene、事件、獎勵 type 消費者列 U，不在這批冒稱已核。

## 1. 首批核心：Quest15 → Quest117 的最小正常接續

### 1.1 資料鏈（P）

**Quest15**：`id15,type2,subtype1,town5,field19,level1,giver10338,finisher10338, demand16`；raw reward `[type2:value2800,type4:value468]`。由 `_CaseList.xml` `Case103.STAGE=19` **只能建立 Field19 → Case103 的 J 級候選**；配套 `CHART_S_pathofpindus_01.xml` 兩個地圖節點各含 Map191、Map192，是 Field／Case／MapFlow 不同資料域。**不能將 Map191/192 座標當合法 spawn 或將 Scenario 結束直接等於 Quest15 結算**。

**Quest117**：`id117,type2,subtype1,town1,field未列,level1,giver10002,finisher10002,demand15`；raw reward `[type2:value710]`。`Town1` 的 pinned NPC 清單包含 `10002`，pinned Town1 Map 候選是 **Map182**（`TRIGGER=town001.mef, MAP=town001D, BOUND=town001`）；**不因此證明 NPC10002 已有可互動世界座標、可觸發 UI、會發哪個封包**。

### 1.2 為 Server 規劃提供的最小正向狀態機（D；不是 KR 原版 wire）

```text
Quest15 Accepted/Active --受信 Field19/Case103 正常結果--> ObjectiveReached
  --受信 NPC10338 / 原版 Client 結算 consumer 仍待查--> Quest15 Settled + RewardResolved + Persisted
  --Town1 可訪問條件另核--> Town1(Map182) Entered
  --NPC10002 正向互動/UI 能顯示 Quest117，Demand(15) 已完成--> Quest117 Offered
  --Client 合法接取請求及 Server 原子更新另核--> Quest117 Active
  --Quest117 原生完成目標/收尾對話另核--> Quest117 Settled + RewardResolved + Persisted
  --> Quest118 EligibleCandidate （需另外檢查 level5 與其它限制）
```

**不可跳過的界線**：① 進 Town1 不是 Quest15 已結算；② Quest15 結算不代表 Quest117 已接取；③ Quest117 接取不代表達成；④ 純 `Demand15`、`Level1` 是資料欄位，不是已證原生 Client UI gating；⑤ 必須查 reward type 2 的 Client consumer 後才可給對應經驗或貨幣；⑥ 角色授予／已學技能／Town unlock 不可因同 Quest 序號就自動推斷。最小 Server model 可以先把狀態分離及持久化接口做好，但 **Native 封包及實際玩家操作暫不得用推定值啟用**。

## 2. 十筆 Town1/type2 候選與 Chapter／SceneList 的矩陣

下表直接保留 `giver`/`finisher` 數字、`level`、`field`、`Demand` 和原始 Reward。`*` 表示**單以 `_CaseList.STAGE == QuestInfo.field` 做的候選 join**，不是原生的 Quest→Case 關係。所有行的 Chapter ID、SceneList `(chapter,scene)`、實際序列名稱、接取／完成事件均 **U（待讀對應資源內容）**，不得填入猜測的 ID。`—` 表示 QuestInfo 沒有該欄或此 pinned 子集沒有對應候選，**不是原版必定無場景**。

| Quest | Demand（前置 ID） | Level 欄 | Town / Field | Case 候選* | Giver / Finisher NPC | 原始 Reward `type:value` | Chapter / SceneList |
|---:|---:|---:|---|---|---|---|---|
| 15 | 16 | 1 | 5 / 19 | Case103* | 10338 / 10338 | 2:2800；4:468 | 未核定 |
| 117 | 15 | 1 | 1 / — | — | 10002 / 10002 | 2:710 | 未核定 |
| 118 | 117 | 5 | 1 / 28 | Case109* | 10047 / 10047 | 無列值 | 未核定 |
| 119 | 118 | 5 | 1 / 26 | Case107* | 10047 / 10047 | 2:5850；3:40；4:900 | 未核定 |
| 120 | 119 | 8 | 1 / — | — | 10008 / 10008 | 無列值 | 未核定 |
| 121 | 120 | 9 | 1 / — | — | 10002 / 10002 | 無列值 | 未核定 |
| 122 | 121 | 8 | 1 / 27 | Case108* | 10002 / 10002 | 2:9686；3:40；4:918 | 未核定 |
| 123 | 122 | 9 | 1 / — | — | 10048 / 10048 | 無列值 | 未核定 |
| 124 | 123 | 9 | 1 / 17 | Case101* | 10048 / 10048 | 2:13086；3:40；4:1440 | 未核定 |
| 131 | 124 | 10 | 1 / — | — | 10002 / 10002 | 無列值 | 未核定 |
| 132 | 131 | 10 | 1 / 28 | Case109* | 10002 / 10002 | 2:15850；3:40；4:1440 | 未核定 |
| 133 | 132 | 10 | 2 / 21 | — | 10053 / 10005 | 無列值 | 未核定 |

**逐筆可用範圍**（P/J）：

- Town1 的 **十筆** 是 `117,118,119,120,121,122,123,124,131,132`，全部 `type=2,subtype=1,town=1`；不等於原生章節已被證實完整。若要稱「馮德斯完整主線」，仍必須補 Chapter／SceneList、QuestTalk 和 Client 事件來源。
- `118`、`132` 指向 Field28；Case109 的 `STAGE=28` 是相等候選。`119` Field26→Case107 候選；`122` Field27→Case108 候選；`124` Field17→Case101 候選。這些 Case 的 MapID 未在本 pinned Map 子集中提供，不可套用 Town Map182 或 Case103 的 191/192。
- `117/120/121/123/131` 沒有 `field` 欄，不得填 `field=0` 或自行認為不用場景。`118/119` 的 level 都是5，而 `120` 是8、`121` 是9、`122` 又是8，**不能把 Level 字段直接當作全鏈單調遞增的強制解鎖規則**，應由 S00 與本機正常流程另核。
- `133` 是 **Town2/type2,field21,level10,giver10053,finisher10005,demand132**；它是跨村驗收分界，不列為 Town1 的第十一筆，也不把 `132` 的 reward 發放與 `133` 開啟混成同一結算。

## 3. Chapter／SceneList／QuestTalk 實際交叉核對：本批證據能否落地

| 必須映射的來源 | 已核內容 | 能用於本批的 join | 尚待證實（U） |
|---|---|---|---|
| `Table/QuestInfo.xml` | pinned 12 row 的屬性、Demand、Reward；member SHA 指定 | 15→117→…→132→133 的**靜態依賴有向邊** | 各 Quest 的實際 UI 開放條件／進度碼與事件關係 |
| `Table/_CaseList.xml` | pinned Case101/103/107/108/109 的 STAGE | 依 `field==STAGE` 列 J 級候選 | Quest 指向哪一個 Case 的真正選擇和場景 id |
| `Table/SceneList.xml` | 本地 STPI 目錄中看見檔名 | **沒有核對到任何 Quest→Chapter/Scene ID** | 內容解包、scene key、task event consumer、主線分支 |
| `Event/SceneList.xml` | 本地 STPI 目錄中看見檔名 | **沒有核對到任何 Quest→seq** | 內容解包、序列名稱、雙鍵、進場/返回 |
| `Table/QuestTalk.xml` | 本地 STPI 目錄中看見檔名 | 暫無 | NPC 對話 entry、accept/turn-in 分支與完整 UI case |
| `Chapter` | **本地兩份 STPI manifest 未找到同名條目** | 暫無 | 真正 Chapter 載體／名稱／scene/quest join；不能將檔名缺席當遊戲缺席 |

這是**資料來源層級的交叉核對／負向界線**；不是宣稱完成逐 Scene 的正向映射。原始檔有 `SceneList.xml` 名稱不足以推導單個 Quest 的 scene id。S00 可以先採用靜態 Demand 及 typed ID 作 DRAFT，但不可拿這張表宣稱已可播放完整馮德斯劇情。

## 4. 獎勵、持久化、角色授予與 Town 解鎖

**原始資源實錄（P）**：Quest15 `[2:2800,4:468]`；117 `[2:710]`；119 `[2:5850,3:40,4:900]`；122 `[2:9686,3:40,4:918]`；124 `[2:13086,3:40,4:1440]`；132 `[2:15850,3:40,4:1440]`；其餘本表行 `raw_rewards=[]`。**不准**把 `type=2/3/4` 填成金幣／EXP／道具，因缺 Client reward consumer 的原生證據；空列表也不能推出實際完整獎勵一定為零（可能由其它表／封包／任務事件給予）。

**Server 自設交易建議（D）**：每任務分開存 `Offered/Accepted/ObjectiveReached/TurnedIn/Settled`，至少以 `account/character+questId+settlementGeneration` 保證同一合法交付只結算一次，寫入 quest 狀態、實際獎勵、下一候選開放與保存成功的交易；受信場景結果要校驗 `Quest/Field/Case/Map` 不同域。這是為防誤結算的**設計提案**，不代表找到原版 Server 的 DB、封包或遊戲內規則，也不授權本輪做負向／重播／併發測試。

**Snapshot/Delta**：按工作卡須區分 `6F` 完整 snapshot 與 `74` 等增量；本批沒有對特定 Quest 的 native writer/consumer 做正向位址配對，所以**不能**把「6F 更新成功」或「收到 74」直接當成合法 Settled／獎勵與保存完成。角色取得、等級、已學技能、已通過場景、Town 開放屬不同資料域／狀態門檻，不能拿 Quest Demand 取代。

## 5. 首批 S00 可實作表與不可啟用範圍

| 介面/欄位 | 來源級別 | 首批允許交 S00 | 啟用門檻／未知 |
|---|---|---|---|
| `QuestId`, `DemandQuestIds[]`, `TownId`, `FieldId?`, `LevelField`, `Type`, `Subtype` | P | 以 pinned 來源建立**DRAFT 只讀候選圖／typed DTO** | 不是 Native UI 解鎖、不能直接跳任務 |
| `GiverNpcId`, `FinisherNpcId` | P | 建候選 NPC 關聯／正常操作核對卡 | NPC 互動 ID、world spawn、scene listener 尚 U |
| `FieldId -> CaseId` | J | 用於場景匹配檢查的候選集 | 需本機正流程／原生 handler 證明真正 join |
| `Town1 -> Map182`, `Field19/Case103 -> Map191,192` | P/J 分域 | 資源索引／UI 顯示查表 | 地圖 spawn、BND version2、SceneGraph 進場規則尚 U |
| `RawRewardType/Value` | P | 儲存不轉義的原始 reward tuple，待 consumer | 不准直接依 type 猜測經驗、貨幣或品項 |
| `QuestTake/Complete/TurnIn/Save S2C/C2S` | U | 建明確**未核准**的介面／追蹤點 | 尚缺 opcode、bytes、scene/state/event handler，不可開 Native wire |
| `Quest117 unlock after Quest15 settled` | P（Demand）+D | 可做正向 domain guard 的**草案** | 真正 Client 供任務 UI、角色等級/技能、Town 解鎖與 event 次序需核 |
| `Quest132 settled -> Quest133 candidate (Town2)` | P（Demand）+D | 避免把「到村」誤判全主線完成 | Chapter 真正終點／進下一村條件 U |

## 6. 只做正常流程的人工驗收卡（本批不執行）

1. 實機同版資源與 Player profile 確認後，正常完成 Quest15 的 Field19/Case103 達成、交 NPC10338／正規結算；分別記錄任務已接受、目標達成、獎勵、保存，不以到村取代。
2. 正常進入 Town1（Map182 候選），確認 NPC10002 的可見／可點／Quest117 offer 與需要的 UI case，**記錄真實 Chapter/SceneList key**。Quest117 的 Demand15 應以角色的已結算狀態對照。
3. 正常接受、達成、向 NPC10002 交付 Quest117，觀察合法 snapshot/delta 和 reward consumer，再確認 Quest118 是否可接及 Level5 欄影響。不使用造封包、負向、重播或強設 Quest completed。
4. 後續批次依法巡查 118→…→132 的 field、NPC 和 scene，分別記錄各筆結算、保存與 133 入口；**村主線驗收的終點需由 Chapter/SceneList 真實章節資料確認**。

## 7. 下批精確研究依賴／停止界線

- **優先取得同版 `SceneList`／Chapter／QuestTalk 成員完整內容及 SHA**，用真正 key 做 `Quest→Chapter→Scene→seq→local event→NPC` 正向 join（不把類似名稱當值）。這不是單靠本批 pinned Quest rows 可以補出來的。
- 再以既有 KR BIN bulk／原稿做限定核對：接任務、任務狀態、完整 snapshot 6F、增量 74、交付及 reward consumer 的實際 VAs、字段和 T01 source claim；不要直接重跑全部函式或重做 S00 的 AI／MEF／連擊。
- 分層交接：**Client 待逆向** scene/opcode/consumer；**Server 待開發** 權威 eligibility/once-only settlement/保存；**跨功能待整合** W2 Field/Case 結果、W3 Town1 NPC/合法座標；**待遊玩驗證** 正常人工 Quest15→117、完整 132/133 邊界。
- 首批完成判準僅是「資源快照 Demand／NPC／Level／Field／Case 候選矩陣及 15→117 最小 DRAFT 正向狀態機」；**不是整張 W1 工作卡完成，更不是整村主線可玩、T01 FULL-PASS 或 S00 APPROVED**。沒有本機負向／重播／重登／併發／故障／壓測。

**機讀資料**：[`W1-RESULT-BATCH01-QUEST-MATRIX.json`](W1-RESULT-BATCH01-QUEST-MATRIX.json)，精確 Git blob `7075789fb950612923cc4c93a09c5e92eb1f2821`；按每行 `chapter_id=null/scene_id=null` 保留未知；沒有用相似字段猜填。
