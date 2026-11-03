# W1-RESULT BATCH04 — 使用者提供 SceneList 的版本比對、馮德斯 35 場正式索引與 Quest15→132→133 界線

> **來源限定／2026-11-02／extra/roy1**。本輪對使用者上傳的 `/mnt/data/SceneList.xml` 執行唯讀解析，並與原有 `Event.stp` 內可直接讀取的 35 份 `.seq` 做原始成員 MD5／header／函式對照；未執行、附加或修改 Client，未碰 Server；不重做 S00 自行負責的 AI／MEF／連擊。使用者已指出 QuestTalk 不要求解包，本輪**不要求補傳、不推論其內容**。本稿只新增來源與定向結論，不覆寫 BATCH01～03、正式 RR、APPROVED 或他人 Task。

## 1. 上傳 SceneList.xml 的身分及版別證據

| 項目 | 唯讀實證 | 級別／限制 |
|---|---|---|
| 上傳檔案 | `SceneList.xml` 158,269B；SHA256 `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25`；宣告 `encoding="euc-kr"`，根 `<SCENESET>` | **使用者提供的第一手 XML；不是從 Event.stp 重新解密** |
| Event 資源包 | `Event.stp` SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；其 `Event/SceneList.xml` 為 EX v1，成員 ID 7379，EX header 的**宣告 decodedLength 158,269** | 長度與上傳 XML 相符，但 **EX 尚未解開，不可說逐 byte 一致** |
| Table 資源包 | `Table.stp` SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`；`Table/SceneList.xml` 成員 ID 984、其宣告 decodedLength **65,494** | 和上傳的 158,269B 不同；不要引用錯包同名成員 |
| 35 筆 W1 比對 | Quest15／117～124／131～133 的 `(questIdx,sceneIdx,funcName)` **35/35** 與 Event.stp TTEX `.seq` 的 `Quest #／Scene #／Function` 且 MD5 正確的原始腳本一致 | **足以將這份 XML 作為 W1 的 source-matched author-time 兩鍵索引**；未證 runtime loader/封包觸發 |
| 全檔健全性 | XML **1,687** 個 scene rows、**1,685** 個不重複 `(questIdx,sceneIdx)` key；與 Event 原始 1,836 份含標頭的腳本交叉，可為 1,684 個 XML row 找到相同 key+fn 腳本。外圍 3 個 XML row 未對上（`2440/5 Aisen_01_After`、`9999/1 NONAME`、`9998/1 NONAME`） | 全域並非所有 `.seq` 均可當正式 SceneList entry；W1 **完全一致**。另有 W1 外 0/249、0/250 重複鍵，別泛化全域唯一性 |
| 原始 KR BIN | `Tartaros.bin` 12,472,320B；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` | 同 build 原始機器碼存在；**本輪 Scene 資源來源對照不等於原生 handler semantics FULL-PASS** |

### 精確的 W1 兩鍵資源契約（可給 S00 的 DRAFT 靜態表）

```text
(questIdx: integer, sceneIdx: integer) -> (funcName: string, endBehavior: integer)
Event/SceneList.xml (uploaded candidate) -> Event/Sequences/<funcName>.seq (verified existing STP member)
```

`endBehavior` 在所有這 35 筆的字面值都是 **0**，但其 Client 程式意義尚未完成原生 consumer 定向驗證；不能將 0 視為「已完成任務」、「達成結算」或「送獎勵」。上傳的 XML 只有 `questIdx/sceneIdx/funcName/endBehavior` 四欄，**沒有** `ChapterId`、NPC、結算／獎勵或網路 opcode，不能用它補填不存在欄位。

## 2. Quest 前置鏈 → SceneList 靜態矩陣（來源可分級）

前置與 NPC 由既有 W1 BATCH01 pinned `RESOURCE-BASELINE.json` 提供，Scene 名稱及 Scene 數則由**本輪上傳 XML+Event STP 雙來源驗證**，地圖和對話來自每份可直接讀取的 `.seq`。`Field↔Case` 仍屬候選 join，不把場景演出地圖當合法世界 spawn。

| Quest | BATCH01 前置／NPC／Field（pinned） | Scene 編號 | 字面 LoadMap（每筆聚合） | 原始 OpenTalkScene 呼叫數 |
|---:|---|---|---|---:|
| 15 | town5 / field19 / Demand16 / NPC10338 | 1,2,3,4 | `Square03D.fld`, `town001D.map`, `"" (blank)` | 9 |
| 117 | Town1 / Demand15 / NPC10002 | 1 | `town001D.fld` | 14 |
| 118 | Town1 / Field28 / Demand117 / NPC10047 | 1 | `town001D.fld` | 10 |
| 119 | Town1 / Field26 / Demand118 / NPC10047 | 1,2,3,4,5 | `"" (blank)`, `mushroom01D.fld`, `mushroom12D.fld`, `town001D.fld` | 9 |
| 120 | Town1 / Demand119 / NPC10008 | 1,2,3 | `town001D.fld`, `bluetree12C.fld` | 5 |
| 121 | Town1 / Demand120 / NPC10002 | 1 | `town001D.fld` | 6 |
| 122 | Town1 / Field27 / Demand121 / NPC10002 | 1,2,3,4,5 | `"" (blank)`, `bluetree01C.fld`, `bluetree10C.fld`, `town001D.fld` | 17 |
| 123 | Town1 / Demand122 / NPC10048 | 1 | `bluetree01C.fld` | 5 |
| 124 | Town1 / Field17 / Demand123 / NPC10048 | 1,2,3,4,5,6,7 | `"" (blank)`, `scenario_ygg01C.fld`, `scenario_ygg02C.fld`, `scenario_ygg03C.fld`, `scenario_ygg04C.fld`, `town001D.fld` | 16 |
| 131 | Town1 / Demand124 / NPC10002 | 1 | `town001D.fld` | 1 |
| 132 | Town1 / Field28 / Demand131 / NPC10002 | 1,2,3,4,5 | `"" (blank)`, `barley03D.fld`, `keep02D.fld`, `town002D.fld` | 18 |
| 133 | Town2 / Field21 / Demand132 / NPC10053→10005 | 1 | `town002D.fld` | 8 |

**重要源證限界：** Quests 119／122／124／132 有多個 Script 名稱包含 Stage、Boss、Clear／After，但那是**腳本作者命名和 SceneList 對應**，不是它們一定按 sceneIdx 順序由 Server 觸發，也不是自動結算的 Client opcode。BossClear script 的存在**不等於** `QuestCompleted`、發獎勵或寫資料庫。

## 3. 35 筆逐場 SceneList ↔ Event.stp `.seq` 完整列表

| Quest/Scene | SceneList.funcName = TTEX header = .seq base | 腳本成員 ID／MD5 | LoadMap literal | `OpenTalkScene` 的 group/key（順序） | Prolog |
|---|---|---|---|---|---|
| 15/1 | `Square_Tutorial01` | 7135 / `dd5f6c3c4cb3cc77c16d270ca0eddd13` | Square03D.fld | 3:22 | — |
| 15/2 | `scenario_tuto1_1` | 7133 / `8e6efc269ce27d1539f2ab04a764d962` | Square03D.fld | 3:15,3:16,3:17,3:25 | — |
| 15/3 | `pindos_talkevent` | 6851 / `8348e04c867cf6f8911315bea8312b82` | town001D.map | 3:18,3:24,3:20,3:21 | 1 |
| 15/4 | `scenario_tuto2_1` | 7134 / `b41083413750fc451b0b169675cd4558` | "" | — | — |
| 117/1 | `Phindous_LittleTrouble` | 6816 / `b15ddbfa5f24dd2ea5566aefa952cb64` | town001D.fld | 1:1,1:2,1:3,1:4,1:5,1:6,1:7,1:8,1:9,1:10,1:11,1:12,1:13,1:14 | — |
| 118/1 | `Phindous_YuriandRazed` | 6842 / `13f688a4e2aed14d9c4f2597819e9641` | town001D.fld | 12:1,12:2,12:3,12:4,12:5,12:6,12:7,12:8,12:9,12:19 | — |
| 119/1 | `Phindous_YuriandRazed_Blank` | 6844 / `04edd2eba6c644abb3d2699da276e340` | "" | — | — |
| 119/2 | `Phindous_YuriandRazed_Stage` | 6847 / `3f72b2e6d3aed4130321b690218dadc2` | mushroom01D.fld | 12:10 | — |
| 119/3 | `Phindous_YuriandRazed_Boss` | 6845 / `9943a93e8d794a2330c98f5b9fd7b5df` | mushroom12D.fld | 12:11 | — |
| 119/4 | `Phindous_YuriandRazed_BossClear` | 6846 / `dbedec3e4a79a97dd45d50cabb248dcf` | mushroom12D.fld | 12:12,12:13,12:14,12:15,12:16 | — |
| 119/5 | `Phindous_YuriandRazed_After` | 6843 / `46ccf87bf222ddac201eb1863b455462` | town001D.fld | 12:17,12:18 | — |
| 120/1 | `Phindous_Senerep_TalkEvent` | 6839 / `6702407215462810e4b81c36f6537f81` | town001D.fld | 13:1,13:2,13:3 | — |
| 120/2 | `Phindous_Senerep_TalkEvent2` | 6840 / `7e920f2e473cb772a3e961f9a87e8ee2` | bluetree12C.fld | 13:4 | — |
| 120/3 | `Phindous_Senerep_TalkEvent3` | 6841 / `2a13f13ed8b9d19ed804211d558ca8bc` | town001D.fld | 13:5 | — |
| 121/1 | `Phindous_RazedSave_TalkEvent` | 6838 / `7e541f629c6c8ded999871b09b8930bc` | town001D.fld | 14:1,14:2,14:3,14:22,14:23,14:4 | — |
| 122/1 | `Phindous_RazedSave_Blank` | 6834 / `788b84d3a321b185260e813b1f66fe01` | "" | — | — |
| 122/2 | `Phindous_RazedSave_Stage` | 6837 / `2b5bfc026b9536df38ad316777019bce` | bluetree01C.fld | 14:5 | — |
| 122/3 | `Phindous_RazedSave_Boss` | 6835 / `af0b8d47ed953a534ffc4c71e237d12f` | bluetree10C.fld | 14:6,14:7,14:8,14:9 | — |
| 122/4 | `Phindous_RazedSave_BossClear` | 6836 / `52f610edada3ddaf4d80c6aed5c58dd8` | bluetree10C.fld | 14:10 | — |
| 122/5 | `Phindous_RazedSave_After` | 6833 / `643f055e534ffb4554ca64909e38ac3c` | town001D.fld | 14:11,14:12,14:13,14:14,14:15,14:16,14:17,14:18,14:19,14:20,14:21 | — |
| 123/1 | `Phindous_NightofRitual_Talk_Event` | 6825 / `41163aac1e63cd5879bc0a8df90be842` | bluetree01C.fld | 15:1,15:2,15:3,15:4,15:5 | — |
| 124/1 | `Phindous_NightofRitual_Blank` | 6819 / `5bcb6eee8d08b3c8b41efb804980135c` | "" | — | — |
| 124/2 | `Phindous_NightofRitual_Stage` | 6822 / `d3b6552971c57fbbf746ffa2a9f763a9` | scenario_ygg01C.fld | — | — |
| 124/3 | `Phindous_NightofRitual_Stage02` | 6823 / `e0a9573e553c381f620bfb46b5e44ec2` | scenario_ygg02C.fld | — | — |
| 124/4 | `Phindous_NightofRitual_Stage03` | 6824 / `68c08c83c33e21b471e22af0b0a9be6d` | scenario_ygg03C.fld | — | — |
| 124/5 | `Phindous_NightofRitual_Boss` | 6820 / `cd5b3fe0c1d73e75d80852cc605f83ed` | scenario_ygg04C.fld | 15:6,15:7,15:8,15:9,15:10,15:11 | — |
| 124/6 | `Phindous_NightofRitual_Clear` | 6821 / `8e81f05f36d109e0164de7715021633c` | scenario_ygg04C.fld | 15:12,15:13,15:14,15:15 | — |
| 124/7 | `Phindous_NightofRitual_After` | 6818 / `02449b949a6be6663bc6e7dfbad68d27` | town001D.fld | 15:16,15:17,15:18,15:19,15:20,15:21 | — |
| 131/1 | `Phindous_pathofAlsmeer_Talkevent` | 6831 / `5dfaaf743f23e3447e2174cd74b1490b` | town001D.fld | 16:1 | — |
| 132/1 | `Phindous_pathofAlsmeer_Blank` | 6826 / `cb7d5e5254f652c0436f8873928b3f78` | "" | — | — |
| 132/2 | `Phindous_pathofAlsmeer_Stage` | 6830 / `b9b8f63017a482e63aa4a6f4e8063e74` | barley03D.fld | 16:2 | — |
| 132/3 | `Phindous_pathofAlsmeer_Boss` | 6827 / `a8e67d4a32e2a5341698ef5070276799` | keep02D.fld | 16:3,16:4,16:5 | — |
| 132/4 | `Phindous_pathofAlsmeer_Boss_Clear` | 6829 / `3f3bff1de1da4b50e092e4bd0f5a8f63` | keep02D.fld | 16:6,16:7,16:8,16:9,16:10,16:11 | — |
| 132/5 | `Phindous_pathofAlsmeer_Boss_After` | 6828 / `013107e9c6a136b78fc4ad84cb90e799` | town002D.fld | 16:12,16:13,16:14,16:15,16:16,16:17,16:18,16:19 | 2 |
| 133/1 | `Alsmeer_Justice_Talk01` | 5629 / `2ec4ba3204ddb1a5707de3afe1e0875c` | town002D.fld | 17:1,17:2,17:3,17:4,17:5,17:6,17:7,17:8 | — |

### 可直接定位的關鍵原始腳本（非正式 quest settle 觸發）

- **15/3**：`Event/Sequences/pindos_talkevent.seq`：原始 `LoadMap("town001D.map")`、`OpenTalkScene(3,18/24/20/21)`，`DoProlog(1)`；其後有 `Q.DeleteAllObject()` 與 `RestoreMap()`，**這些是演出/清場腳本，不能視為 Quest15 已合法結算**。
- **117/1**：`Event/Sequences/Phindous_LittleTrouble.seq`：`LoadMap("town001D.fld")`，`CreateObject(0,10002,...)` 是**演出物件**，`OpenTalkScene(1,1..14)`；NPC10002 與 BATCH01 Giver/Finisher 值吻合，卻不能因此知道真實交件封包、NPC 世界 spawn 或 Client 任務 offer 狀態。
- **118/1**：`Event/Sequences/Phindous_YuriandRazed.seq`：`CreateObject(0,10047,...)`，`OpenTalkScene(12,1..9/19)`，和 BATCH01 Quest118 NPC10047 有視覺對應，但原生接取 callback 未證。
- **119/1..5／122/1..5／124/1..7**：先後含 Blank、Stage、Boss、Clear、After 等**資源標記**；多場使用不同演出 `.fld` 名稱，不可強行對應 Case/MapID；由 W2 提供一般副本結果契約、T01 核驗。
- **132/5**：`Event/Sequences/Phindous_pathofAlsmeer_Boss_After.seq`，`LoadMap("town002D.fld")`、`OpenTalkScene(16,12..19)`、`DoProlog(2)`；此處已在 Quest132 的**劇情資源**中跨至 Town2。
- **133/1**：`Event/Sequences/Alsmeer_Justice_Talk01.seq` 也載入 `town002D.fld`，`OpenTalkScene(17,1..8)`，是 **Quest133/Town2** 的後續劇情；不能算為 Town1 的十筆之一。

### Scene cleanup 與「Quest settled」有嚴格分界

這 35 份 TTEX 劇情腳本末段都能找到 `Q.DeleteAllObject()`、`RestoreMap()`、`RevPhase1()` 等清場/恢復演出狀態呼叫；這是腳本生命週期，不是可證任務完成、資料庫保存或 Reward 授予。腳本內的 `OpenTalkScene(group,key)` 可做**腳本字面 dialogue lookup**，但第一參數不等同已證 `ChapterId`，第二參數不等於 Quest 完成子狀態。 `DoProlog(1|2)` 不等於世界解鎖/quest-settle，需獨立 Client consumer 證實。

## 4. 哪些已能交 S00 實作、哪些仍不能啟用

| 契約/資料 | 可否交 S00 | 分級 | 啟用注意 |
|---|---|---|---|
| W1 `(questId,sceneId)->funcName` 35 鍵 | **可**，DRAFT 版本鎖定資源索引 | 上傳 SceneList + 35 原始 Event `.seq` MD5 機讀一致 | 只做資源查表；**不是** Server 應送的 scene packet |
| `endBehavior=0`（35 筆） | **可保留原樣** | XML 字面值 | Client consumer 對 0 語意未證，不自動完成 |
| Quest15→117→…→132→133 demand/NPC | **沿用 BATCH01** | pinned QuestInfo attributes | 供 Server 設計 eligible draft；須區分 Accepted/Objective/TurnIn/Reward/Persisted |
| Dialogue group+key、LoadMap、TTEX actors | **可供劇情候選展示/查表** | 原始 Event `.seq` 字面呼叫（MD5） | `CreateObject` 演出坐標不是可行走出生點，不是權威 NPC world entity |
| Quest132/5 → `town002D.fld`, `DoProlog(2)` | **可做 Town2 劇情橋接候選** | 原始 Event `.seq` | 不等於 Server 可直接搬遷角色到 Town2 或 Quest132 完成 |
| 接取／進度／交件的 C2S、S2C snapshot6F/增量74、Reward type2/3/4 consumer | **不可啟用** | Client 原生必要接口待查 | 有 opcode/handler/欄位/T01 審核後才能定 Native wire |
| `Event/SceneList.xml` 的逐 byte 身分 | **未證** | EX header 158269 與 W1+多數 XML row 強一致 | 若 S00 需整包精確來源，需取得同版 EX v1 明文或可信解碼器，與上傳檔 SHA 相互驗證 |

## 5. 待完成 W1 的原生證據與最小後續依賴

1. **Client 待逆向**：本地 `questIdx/sceneIdx` 誰在何條封包/狀態下觸發、SceneList 雙鍵 resolver 到 `.seq` 的 native producer/consumer、`endBehavior` 的處理；Quest 15 與 117 的真正接取、任務/副本完成、NPC 交付封包；reward type 2/3/4 的 consumer 與 6F 完整快照/74 增量欄位及 scene 完成回覆。這些都不能由目前 SceneList 的四個欄位自動推出。
2. **Server 待開發（設計，不是 KR 原版事實）**：依 Quest Demand + 合法 NPC／場景／結果建立授權 eligibility、接受、達成、交付、結算、保存及一次性 reward；Quest15 敲定前不得為 Quest117 預設 completed，也不能把進 Town1 當結算；Quest132 reward/儲存完成後才考慮開啟 Quest133 候選。
3. **跨功能待整合**：W2 Field/Case 正常結果、W3 Town1 scene/NPC（含 map182 與 BND），T01 逐主張驗證及 S00 規格採用。S00 自行處理 AI/MEF/連擊，W1 不重做。
4. **待正常人工驗收**：確定一個同版 KR Client 的 Quest15 正規結果/交 NPC10338、Quest117 NPC10002 提供/接取/結算，隨後 Field28/26/27/17 各相應任務的正常副本返回及 Town2 133 入口；未做負向、重播、重登、故障、併發、壓測。

## 6. 可重現唯讀驗證／版本與提交

```bash
python -B W1-RESULT-BATCH04-VERIFY.py /path/SceneList.xml /path/Event.stp /path/Tartaros.bin /path/output
```

腳本核對 XML SHA/EUC-KR 樹、原始 BIN SHA、Event.stp xor-FF STPD 索引/record、每筆 MD5、TTEX header+Register、全域 1684/1687 交叉一致及 35/35 W1 正向匹配，並產生完整機讀 `W1-RESULT-BATCH04-SCENE-JOIN.json`。原始檔不修改，不執行 Client。**這是來源內容驗證，非 T01 FULL-PASS、Server 原生封包解碼或可玩驗收**。

**工作分支**：既有 `extra/roy1`（不新增）；需按最新 GitHub commit/blob 讀回驗證。源準備與提交不更動正式 RR、APPROVED、其他 Task 主責。