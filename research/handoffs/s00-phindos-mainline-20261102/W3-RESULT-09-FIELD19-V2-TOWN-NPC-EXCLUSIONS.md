# W3-09 — Field19 兩張 BND v2 實檔、正常入村座標反證與 NPC 配置交接

> 2026-11-02；工作分支 extra/roy3。KR 原始檔唯讀靜態研究，不啟動或修改 Client／Server／DB。本批完成 Field19 v2 的原件資料與限定 Client parser 路線核對，補查 ExpeditionDeploy 座標、Town1 NPC TALKLIST、可復現的 Server 重建候選。**W3 全部可玩／原廠配置驗收仍未完成**。非 T01 FULL-PASS、RR ACCEPTED、S00 STABLE、原服錄包或部署許可。

## 0. 開工基準、證據分級與研究終點

已閱讀共用 02、main/AGENTS、W3 工作卡、派工包、W3-01～08、T01 review／有限共用驗證索引；開工 main=ac6aac673426459df2a778d20a80c623b8559a92，extra/roy3=1ca21c00cc729670a192a4d7b670736c503fc0c4。原件：KR BIN SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；BoundMap.stp SHA256 07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8；Table.stp SHA256 09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442。Event.stp 已核對 SHA256 2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b。

R=本輪原始資源直接解碼／SHA 核對；N=本輪原 BIN 有界機器指令；A=分析者離線連通／距離計算；S=相容 Server 自訂政策候選；U=未知。所有靜態格點的成立都不等於正常地圖幾何、原版合法 spawn、動態障礙、NPC 位置、實際 Client 執行或官服封包順序。不要跨 Tartaros KR／Asgard 或 TC 套用。

本輪只保留 W3 領域：村落、BND、NPC／互動與進村介面。MEF 原格式、核心 AI／連擊主線仍由 S00 處理；本文只列其 Server 介面缺口，不挪其他 Task owner。

## 1. Field19 version2：兩張原檔獨立解碼完成（R）

由 STPD 原索引／XOR-FF block table 唯讀提取；每個 member 單獨校驗。Map191 與 Map192 是不同地圖，不得共用 layer 或安全座標。

| 欄位 | Map191 / scenario_pathofpindus01.bnd | Map192 / scenario_pathofpindus02.bnd |
|---|---|---|
| Member SHA256 | adb627155fc051aaa5a568ae57fe8731d388d58c2cf3244711078ef377321c58 | 89cc3d4b77d3cf0cdf64d45f610d7b987c704bc268881c13396e1375a2234fff |
| 本體長 | 13,219 bytes | 16,563 bytes |
| Header +0x20；grid / world | version2；768×768 / 768×768 | version2；768×768 / 768×768 |
| Layer0: offset / zlib長 | 564 / 3,913 | 564 / 6,877 |
| Layer0: SHA256 | 0817284f950cdbaeecf8e41b9c3fa798ee6dcbd40759eb6a4e1a5514d2814a78 | 0deaf222e8120d43de5d2f52736f770807b79aa85bcc20ad48a8e9c840351d0b |
| Layer0: 0 / 1 格數 | 557,378 / 32,446 | 478,996 / 110,828 |
| Layer1: offset / zlib長 | 4,477 / 8,742 | 7,441 / 9,122 |
| Layer1: SHA256 | 31ae1857fc9e4b35f70c68ec540482c19f3fbb41487bf5f9bc55a02beeaed307 | 15ad4b5ea9bcad5404706c8ce2cb555d45b7c0a07a0bab6ddf765bbf6d924385 |
| Layer1: 0 / 1 格數 | 92,869 / 496,955 | 129,160 / 460,664 |
| 兩層皆0（靜態候選） | 72,495 格 | 37,530 格 |
| 四鄰接連通區 / 最大區 | 16 區 / 72,476 格 | 13 區 / 37,375 格 |

各非空層 count=589,824、expanded=2,359,296=4×count；兩份 zlib 都有 EOF，沒有 unused/unconsumed bytes；末層結尾精確等於檔案尾端。其餘30層 count=0，**offset=檔案尾端、compressed=expanded=0**；Town1 version0 的原檔空層是 offset=FFFFFFFF。這是原始 v2 與舊版本離線工具的真正差異；若碰撞工具同時硬性要求 version==0 與 FFFFFFFF sentinel，**需依已確認的格式支持版本2，而不是改版號或容忍任意壞 offset**。

本輪以原始BIN再次核對：0x830095 version==3 才分派 0x82F850；非3路線為 0x82F660。0x82F660 用 0x234 header 和16-byte descriptor stride，判 count 非零才處理壓縮層。因此 **這兩份 version2 實檔與此已見路徑可相容**，並非需要一個憑想像的 v2 專屬 loader。這是正常／有限分支與兩個樣本的證據，不宣稱所有version2檔、所有原生後處理或所有cache lifecycle FULL-PASS。Native 二層點查參見 0x82CDF0→0x832DA0，非零不是 all-clear。

## 2. 座標、連通與不得跨版本搬用的反例（A/S）

對 Field19 v2，世界extent與格網均為768，因此對界內非負有限(x,y)，cell=(floor(x),floor(y))；**不能把 Town1 version0 的 2×world換算移植到v2**。前輪 W3-08 的 topology() 工具針對 Town1 回傳世界中心 (2×cx+1,2×cy+1)，本輪僅復用它的 cell／連通區分析，再以 v2 比例重新推得 cell 中心：

| 地圖 | 最大連通區分析座標 (cell) | v2 世界中心候選 (S) | 靜態全零方塊 | 限制 |
|---|---|---|---|---|
| Map191 | (308,437) | (308.5,437.5) | 99×99 格 | 非原生出生點，須有副本入口／幾何／角色半徑／路徑驗證 |
| Map192 | (394,307) | (394.5,307.5) | 67×67 格 | 同上，不可直接移植Map191候選 |

Field19 MapFlow graph node的(360,372) **只是圖節點畫面座標，不是世界spawn**；即便強行當世界位置試取樣，Map191 的二層值為(0,0)，Map192 為(0,1)→靜態阻擋。這是禁止跨圖或把Graph座標當入場點的具體反例；不能因某張圖碰巧落零就提升為有效spawn。四鄰接與方形清空距離是離線保守政策，不等於Client native pathfinder。

## 3. 排除一份看似能提供正常村落出生點的表（R+N）

Table/ExpeditionPosition.xml：18,876B，SHA256 32bb0af6c80643fcd3d05894c206ec3d3c1a85fa4a1f253b426024fbe8a08d76。其 ExpeditionDeploy/Type idx1 有「핀더스 ~ 로트루아」角色 x/y（例如 Character idx1=810,465）；**不能直接將此當成正常Town1玩家或九NPC出生點**。

直接BIN證據：字串 Table/ExpeditionPosition.xml 位於0xC07210；0x4C0F4D push 0xC07210，0x4C0EC0讀取 ExpeditionDeploy Type/Character 配置；0x4C176E call 0x4C0EC0，隨後 0x4C17A3 add esi,0xEA60（十進位60000），0x4C17AF call 0x4DF510 載入特殊偏移地圖。此為 **Expedition展示/角色配置的限定分支**，並非證明常規 TownId=1→Map182 的玩家出生；不以圖中文字「馮德斯」取代 caller/consumer。

## 4. Town1 九個 NPC 的對話資源：服務分型與事件分型要分開（R）

Table/npctable.xml member SHA256 a727fceb64a8b58dc98983619fc73b131c15a6be1eec132c1124f2c57b4aa31d。NPC TALKSET 是原始文本候選與條件資料，不等於 NPC actor 出生封包、checkpoint kind、QuestId、Server對話回覆，也不代表 Client 必定選哪一段。

| NPC model | npctable.TYPE | TALKSET數 | 條件 TALKSET | 相關主線／服務 |
|---|---:|---:|---|---|
| 10001 | 0 | 7 | 4組 Demand TYPE1 VALUE1..4 | 非本十筆主線giver |
| 10002 | 0 | 7 | 4組 Demand TYPE1 VALUE1..4 | Q117/121/122/131/132 |
| 10003 | 0 | 7 | 4組 Demand TYPE1 VALUE1..4 | 非本十筆主線giver |
| 10008 | 0 | 7 | 4組 Demand TYPE1 VALUE1..4 | Q120 |
| 10013 | 1 | 11 | 5組 Demand TYPE3 MIN5/9/13/17/20、MAX24 | 銀行服務候選 |
| 10014 | 2 | 1 | 無 | 技能相關服務候選 |
| 10047 | 0 | 3 | 無 | Q118/119 |
| 10048 | 0 | 3 | 無 | Q123/124 |
| 10015 | 6 | 3 | 無 | 裝備製作相關服務候選 |

10047/10048 共享 TALK 值2356..2365，但兩個 model/NPC身分與 Quest 指向不同，不得合併。NPC TYPE1/2/6、checkpoint kind3、S2C0007 actor class6 仍是不同域。Quest117的 Demand15 與正常城鎮 context／場景／NPC事件／Server權威結算要分開。

## 5. 用 Town1 靜態碰撞產出「不可部署的 Server NPC 擺位候選」（A/S）

沿 W3-08 已解之 Town1 v0 BND：grid768×768/world1536×1536，二層皆0格63,091、四鄰接最大區30,282格；Server 重建候選玩家點(921,613)，未核准。依候選點周圍26世界單位半徑的九點排列，抽樣九NPC的 7×7 cell 正方形均二層皆0，點間最小距離16世界單位，全部位於該候選點的同一靜態連通區：10002=(947,613)、10047=(941,629)、10008=(925,639)、10048=(909,635)、10001=(897,621)、10003=(897,605)、10013=(909,591)、10014=(925,587)、10015=(941,597)。

**這是一個刻意集中、便於 Server 本地正流程 smoke 的分析者配置，不是原廠街道NPC位置或建議正式排版；deployable=false、approved=false。** 未核正常 FLD 模型與建築遮擋、角色/NPC半徑、Z高度、朝向、真實NPC事件 kind/selector/radius/flags、Quest/dialogue選擇及可見UI；原版九NPC座標仍 U。若 S00 拒絕集中替代，保留 W3-08 spawn 單點候選而不部署NPC座標，兩者都合理。不能將BND靜態零值當實機可走證書。

## 6. W3 結果、責任分流與 Server 開發需求

| W3原工作卡項目 | 本輪後狀態 | 需交給誰／下一個證據 |
|---|---|---|
| Town1資源/Map182、正常scene/controller | 靜態部分已證；0099/type3→CMissionRoom/kind1/UI4 是可消費方案，**官服Town1配對未證** | S00 決定相容正常進村方案；Server 實作＆實機 |
| Town1 BND version0／候選出生／回城 | 原件兩層及碰撞/候選已證；原版出生、回程和動態可走性 U | Server 開發採核准spawn/return政策；正常地圖幾何待實機 |
| Field19兩份 version2 BND | **本輪完成兩實檔完整靜態資料驗證**與native非3版parser路線 | Server 開發支援精確v2非3版layout+EOF空層及嚴格驗證；W2實際Field入/返流程另整合 |
| 九NPC/TALKLIST/主線關聯 | 原件身分與條件表可用；正常世界actor、checkpoint原位置和互動完整序列未閉 | Server開發提供九NPC actor、各服務路由及完整0027快照；S00核互動/對話/獎勵 |
| Q15過場 vs 真正進村 | W3-06/07已分開 cutscene Lua EndCutScene 與普通scene/map/room/actor/checkpoint/ready | Server開發分開劇情交易與世界初始化，不能以RestoreMap或S2C0047當入村證書 |
| MEF原始內容／解析 | 只有MapList.TRIGGER檔名；當前四原件沒有可確立原MEF樣本，核心MEF由S00主責 | S00續查其他STP/原Server資料；Server可先做配置／事件協調，不憑空發MEF包 |
| 可玩驗收 | **NOT_RUN** | S00/Server開發與使用者以未改原版KR Client實測；不能標全W3完成 |

**Server 必須開發（不是 Client 逆向阻塞）：** (S1) BND v0/v2 版式驗證和兩張 Field19 二層碰撞資料、無效尺寸/壓縮拒絕；(S2) Town1 正常scene/room instance、owner→player actor→controller binding、NPC actor、0027完整快照及ready/loading依賴；(S3) 核准玩家出生／回城點、九NPC放置及服務/任務交互配置；(S4) Q15 權威完成、Q117 eligibility、對話/獎勵/任務狀態保存及本地驗收日誌；(S5) Field19 Map191/192 進入、任務結果、返回及地圖解碼整合W2；(S6) 來源/政策版本記錄，禁用未核准草案的自動部署。以上屬需求提案／handoff，不代表S00已正式登錄REQ或Server已實作。

**Client/原件仍待逆向：** 官方正常Town1 S2C scene與Map182確切配對；原九NPC及checkpoint(kind/radius/XY/flag)配置與路由；獨立封包003C及服務NPC完整UI分支；若需純原版格式，真正town001.mef loader／解析器和原件。缺檔明列 Map/Map/Town.stp (含 Town/town001D.fld/.mre)、真正 town001.mef（或可信 placement/官服正常進村記錄）；檔名存在不證明內容在Client或Server。S00主責MEF核心，不替其認領。

**跨功能/待遊玩驗證：** T01 對本輪有界 native 主張獨立核對；W2 Field19 Scene/Case/return；W1/T16 Quest15→117及全村主線；S00審核選擇方案與真正Server實作；玩家畫面可移動、NPC九位可見可互動、Quest117合法接續皆 NOT_RUN。負向、重入、重登、並發等按既有政策延後。

## 7. 復現與交付

附 W3-09-field19/verify_v2.py（原件SHA釘版、重用W3-07/08工具精確SHA）、W3-09-field19/evidence-summary.json（兩個實檔、layer hashes、連通與source/byte windows）、供S00使用的非部署草案。於此研究交接同級目錄執行：python W3-09-field19/verify_v2.py --sources <原件目錄> --output <全新結果.json>；不覆寫、無網路、無Client/Server執行。兩個 native 關鍵code slice的 SHA 等在證據JSON；hash PASS不等於全文語意驗收。原始 member bytes/遊戲資源未上傳Git。

參照 W3-07/08 與 repo 既存 W3-RESULT-02/04/05/06、W2、S00 MEF 研究；不變更其證據與 owner。**本批完成 Field19 v2 靜態格式缺口，但整體 W3 尚未達全項可玩／原始配置認證。**
