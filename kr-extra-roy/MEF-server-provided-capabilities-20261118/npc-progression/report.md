# Server 提供的 MEF：NPC、出口、任務結算與保存如何分工

日期：2026-11-18；工作分支 `extra/roy1`；證據基線 `60c1c1a5dc7a73902d9dbb50361d5148e8b30058`。本分題採使用者最新目標：**MEF 開發就是 Server 開發的一部分，能交給 MEF 的編排、資料與規則優先交給 MEF。** 工作目標是製作可玩的新內容，沒有將官方 MEF 復原或取得原 Field 套件列為前置。本輪不執行 Client、Server 或 Lua，也不變更正式規格、既有內容版本或資料庫。

## 1. 這次重新分析後的結論

**MEF 可以負責 NPC 演出與對話順序、已存在互動點的開關、任務條件與獎勵規則的定義，以及完成後接哪個節點／任務。既有 Server 已有主線與普通任務、交易、經驗、錢包、熟練度及持久化接線可重用；新增工作應集中在把 MEF 規則接到這些服務。** 不能再將所有結算、開門或獎勵功能統稱「Server 負責，所以 MEF 不處理」。[S01–S12；來源索引見 `source-manifest.json`]

要分清兩種實際效益：

| 執行方式 | MEF 負責的工作 | Server 可以少做的工作 | 仍在 Server 執行的工作 |
|---|---|---|---|
| Client 執行 Server 提供的 MEF | 對話、相機、等待、模型動作、已存在點的開關、已取得事實後的本地流程 | 逐句／逐動作／逐秒指令派送；單純演出計時；純表現分支 | 原有服務請求與需要共享的世界狀態；結算與存檔 |
| Server 執行 MEF 規則 | 任務前置、清組後開哪個出口、何時結算、受益角色、獎勵條目、下一任務 | 每關專用程式、重複條件分支、散落的獎勵常數；可在載入時編譯事件索引 | 規則判斷本身、交易、資料庫、必要發布。**不能因此宣稱 CPU 已移到 Client。** |
| 最小相容 adapter | 把既有請求／結果轉為 MEF 事件，把 MEF 決策交給既有服務 | 避免重新建一套商店、任務及保存系統 | 保留 legacy wire、身分與場景對照、一次提交及發送已提交結果 |

`NOT_NATIVE_MEF` 是既有 JSON 格式的來源標記，表示它不是原件格式證明；**不表示這些規則不能成為自有 MEF 系統的 Server 執行部分**。本包的 `authored-policy-example.json` 是自有內容模型與編譯／接線提案，尚未加入現行 loader；沒有將其直接宣稱為可送入 Client 的 Lua、既有 JSON schema 或新 wire opcode。[S02、S03、S12、S13]

main 已有「不用原版 MEF 格式作功能前置」及共用 `LocalScenarioDefinition`／`Entry → GroupCleared → InteractZ` 引擎方向。本輪修正 extra 研究中偏回復原目標的表述，接續既有引擎與 adapter 擴充，沒有另提一套替代事件引擎。[S27、S36]

## 2. 玩家功能逐項拆解

| 玩家看到的功能 | 優先放入 MEF 的內容 | 可直接復用的底層 | 新 MEF 仍須接的差額 |
|---|---|---|---|
| NPC 出場、走位、轉身與對話 | 模型／位置／演出 slot、動作與台詞順序、相機及等待 | `lb.CreateObject[Ex]` 的世界模型；`Q.CreateObject` 的演出角色；`ScenarioTalkTable.open` 的多列對白與本地推進 | 模型與文字依賴、可達執行 profile、world entity 與 Q slot 分開。`lb` 建立沒有新回傳 entity ID，不能用賦值假造 handle |
| 劇情結束後可以跟 NPC 說話 | 點的 category/key、啟用條件、本地演出結束後的開放步驟 | `Tutorial.SetCheckPointStatus(key,category,status)`；category 3 的 NPC 對話路徑 | 點須先安裝；頁面、Town 與 NPC 資格須一致。此 API 名稱雖有 Tutorial，實際查共用點集合，並非只改 category 4 |
| 完成任務後開放鐵匠 | 解鎖任務、ShopNo、座標、點狀態、貨單與價格規則 | 現有 town-placement v3 `requiresCompletedQuest`、商店／NPC 表、原生買賣／強化 UI | MEF 規則編譯／映射到既有市場配置與服務資格；Client 貨架依其本地表顯示，改 Server 價格不能假定畫面自動一致 |
| 買、賣、強化 | 可售品、定價、消耗、資格、強化政策與結果呈現順序 | 原生請求／結果與既有交易、背包、錢包服務 | MEF 規則輸入接現有交易；仍需同筆扣款／改道具／保存。沒有已證 Client Lua「改餘額／寫 DB」binding |
| 敵群清空後開出口 | 群組／旗標條件、開哪個點、開門前演出／等待、下一節點 | 入場 `S2C 0027` 預放點；MEF setter 或 `S2C 0048` 更新同一點；原生互動意圖 | 清組事實來自哪個已證 observer／adapter 必須明確。一般清組結果直接進 Lua 的通用橋尚未成立，不能以等待秒數代替 |
| 任務完成與領獎 | 達成條件、返回政策、獎勵清單、受益範圍、下一任務條件 | 主線 `ScenarioCompletion`、經驗帳本、錢包帳本、熟練度欄；普通任務 Accepted／Ready／Completed 服務 | 自有 MEF 規則版本與既有提交入口連接。既有提交時點須保持明確，不因看到結果頁就提早發獎 |
| 關遊戲再登入仍有進度 | 明確的持久 checkpoint／已完成任務／已領獎紀錄，以及回場該重建的 MEF 狀態 | 現有帳號／角色持久層、登入名冊、`006F`、普通任務 `0042` 回填、資產快照 | 將 MEF 可保存狀態映射到既有存檔欄與規則版本；不保存任意 coroutine 堆疊，不將本地旗標直接當資料庫事實 |

來源：NPC／商店為 S01、S04、S05；點為 S06、S07；目前 Server 接線為 S02、S03、S08–S12、S17。所有「可直接」都受已可達的執行入口、有效資料與當前 owner/context 限制；首次供應／執行 profile 由同包 delivery 分題處理。

## 3. 出口：可把開門交給 MEF，無須把整串流程留在 Server

### 3.1 直接可用的動作

`4A9460` 的 Lua 入口與 `4B32E0` 的 `0048` handler 最後都呼 `544940`。它在共用 point vector 找第一個 `(category,key)`，再呼 `543B30` 寫 `point+105`。特定類別也更新可見狀態；例如 category 0 的分支精確比較 `status==1`。`544730` 隨後讀同一 enabled byte，再判距離／輸入等條件。因此可以把「劇情完成 → 開出口」寫進 MEF，開點的 native 動作已有依據。[N-point-set、N-lua-status、N-point-lookup、N-point-gate；S06、S07]

入口 `0027` 會先清整份點集合，再以每列 18 bytes 建立；`0048` 和 Lua setter 皆不新增缺失點、不搬點。若要讓 Client MEF 自主開門，Server 在入場時就能一次提供關閉的出口點，以及同場必要 NPC／商店點；後續只需用本地 setter 切換。這樣可移走該開門動作的逐步下發，但**不能宣稱連最初點快照也可省掉**。[N-point-snapshot；S06]

### 3.2 四種配置，按訊號與執行方式選擇

| 配置 | 實際流程 | 減掉的工作 | 明確條件 |
|---|---|---|---|
| 本地演出條件 | 已安裝關閉點 → MEF 對話／鏡頭完成 → 本地 setter 開點 → 玩家正常互動 | Server 不需計時每段演出、逐步送點更新 | 開門條件可由該 MEF 真正觀察；本地對話結束只表示演出結束 |
| 現有 Server 清組事件 | 入場一次安裝點 → Server MEF 規則收 `GroupCleared` → 既有 `0048` 一次開點；前後演出仍本地跑 | 不需另寫每關開門程式，也不需為演出持續計時派送 | 這是現在可用的結果 adapter；清組判斷仍在現有系統，不能算 Client 自主清組 |
| 清組後選一段有限內容 | 入場安裝關閉點 → Server MEF 收 `GroupCleared` → 允許 Q 演出的安全時點一次 `0047` 選擇事先綁定的新內容 → Client 自行等待／演出／setter 開點／End → 按選定 profile 收尾 | 將清場後多個步驟的等待、演出與點開關交給 Client；Server 只選擇該段內容，不逐步派送 | **已有接口可組合的自有設計，未部署**；不需要通用事件進常駐 Lua 的橋。`0047` 只選已安裝內容，點／延遲等是建置時綁定資料，不是封包附帶參數 |
| 待接一般結果橋 | 入場一次安裝點 → 經明確 bridge 給同 run 的終端事實 → Client MEF 自行安排演出與開點 | 可將結果之後的計時、分支、開點步驟移至 Client | bridge 的公開入口、資料形狀與 run 關聯尚未成立；不創造 `OnGroupCleared`、`SendEvent` 等不存在 API |

第三種是現在可採用的接合路線：**清組條件由 Server MEF 確認，清組後的有限程序由 Client MEF 執行**。它沒有把 `GroupCleared` 注入任意常駐 coroutine；只需把該事件映射到已發布 selector。採同包作者範本的 quest 0 政策時，後續是既有 `003F` 與適用的 `00EB`；非零 quest 的 End 回報條件另按其 profile。需有正確內容版本、先安裝且唯一的點、Q 排他與可中斷普通操控的時點，並遵守 seen／重入契約。[同包有限內容作者契約](../delivery-profiles/authoring-contract.md)

這種方案的總封包可能多於只發一次 `0048`，效益是移走**多步清場程序**的 Server 計時與指令派送，不宣稱每種開門都更省封包。Server 保留原本清組及出口資格的依據；`003F` 僅按目前 run 的精確意義收尾，不證 setter 成功、任務達成或獎勵入帳。即使不接通一般 world 事件至 Lua，也能先做出這段有限內容。只有要保留普通操控並向長駐腳本動態送入一般事件時，才需要最後一種橋。[S06、S07、S12、S14、S36；`adapter-contracts.json` 的 `finite_dispatch_route`]

Q119 現有候選前三節點 `preRegisterClosed=false`、第四節點為 `true`。因此「四圖全部入場預放」是**自有內容新版建議**，不是說原配置本來如此；本輪不修改舊內容。前三圖沿現狀可在清組後以完整 `0027` 安裝出口；若採新版預放，編譯器須保持同場所有點並拒絕重複 key。第四圖既有預放政策可直接作先行案例。[S12；`data-evidence.json`]

玩家通過出口仍由既有原生互動流程及 Server 節點服務完成。C2S `001C` 只有 category/key，沒有目的地、Quest 或 run ID；同值 key 在新場景不自帶代數。MEF 在 Server 端定義「這個出口通往哪裡」，adapter 以本 session 當前副本／節點解析；不改 Client wire 加一個它不讀的 token。[S06、S07]

## 4. NPC 與商店：讓 MEF 定義內容，重用現有服務

### 4.1 可見 NPC、互動點與服務身分分開

`lb.CreateObjectEx` 能建立世界 actor 並接模型更新／繪製，`Q.CreateObject` 則以內容指定 slot 管演出角色。兩者都不自動建立 shop point。category 2 的 key 是 **ShopNo**，category 3 才以 NPC key 查相應資料；current Town 也是商品查找的一部分。[S01、S04]

實際例：Shop 2／Town 1 → NPC 10030／TYPE 12 → Product 2614 → Item 2607。原資料有 27 個商品宣告、5 組 TALKSET；Product 2614 買價 3700、賣價 370。既有模型表未列 category 6／10030，因此不應為了開鐵匠而強行建立不存在來源的商戶外觀。現有市場方案已讓互動點使用本地商戶 UI，並把普通常駐 NPC 與市場點合在同一份 `0027`。[R-shop2；S02、S04]

自有 MEF 可以直接擁有店舖位置、解鎖規則、貨單、價格與強化政策。**新增任務解鎖一家商店不需要每家店增加 Server 專用函式**：可編譯至現有 town-placement v3 的 `requiresCompletedQuest` 及 town-trade；若追求同場演出後即開店，點先安裝，Client MEF setter 控制呈現，交易 adapter 仍查同一條 MEF 資格規則。[S02]

### 4.2 商店互動已有 native 與 Server 端落點

| 入口／結果 | 已核形狀或效果 | MEF 的角色 |
|---|---|---|
| C2S `001C` | 一般 shop context 路線帶 category 2、ShopNo；其他 shop TYPE 有不同分支 | 宣告合法 Town／Shop 與可用條件，adapter 建當前服務 context |
| C2S `0027` | 買商品；opcode WORD、context BYTE、product DWORD、quantity BYTE | 提供品項、單價、數量／資格政策；提交沿既有交易服務 |
| C2S `0020` | 賣商品；bag kind／slot／quantity | 提供可售規則；adapter 以存檔實際物品計價、移除並入帳 |
| C2S `00A1`／S2C `00D9` | 強化請求／結果 UI 的既有路線 | 外移強化規則資料與呈現安排；裝備變更、扣款與保存沿既有服務 |
| S2C `0030`／`002C` | 前者是買賣結果提示；後者有金錢與背包狀態更新 | MEF 決定要做什麼；adapter 發布已提交的資產，提示不是入帳 |

S2C `0027` 與 C2S `0027` 同號而方向、欄位完全不同，機讀契約強制保留方向。直接 `OpenShop` 或任意 `Tutorial.PostUIMessage` 不是這 121 個正常 binding 中已建立的通用 API；因此新內容先使用既有互動點／選單鏈。需要自動開窗時，差額是**精確可達的公開 UI 入口與 context**，不是「等待官方 MEF」。[N-shop-lookup、N-trade-open、N-buy、N-sell、N-enhance、N-asset-balance、N-asset-slots；S01、S05、S14]

## 5. 任務條件：已有資料化規則與本地顯示，不必每條硬寫

任務前置、Town、NPC、等級、目標計數、清組與指定互動，都能成為 Server 執行 MEF 的規則。Client 端已有依 Quest 表、完成集合、等級與目標記錄計算任務標記／待交付清單的 consumer；可重用本地判斷與 UI，Server 不必逐幀替 NPC 決定圖示。[S08、S09、S10]

現行普通任務已記錄 Accepted、Ready 與目標計數，並有 87 項已接入任務的**既有離線收據**。接取提交後 `0040`，再由 `0042` 登錄目標；進度 `0041` 更新既有列，達標後 `0045`。重登回填 Accepted／Ready，領過報酬者使用 `006F`。這些不是本輪新執行或指定 Client 畫面驗收，卻是可接 MEF 的既有服務，不能再全部列成「Server 尚未開發」。[S09、S10]

原表 Content ID 加 1000 是已查的目標文字 key。例如 Q2842 的 Content 2938 對應 3938。Client 本地目標計數與待交判斷可用來顯示提示；Server MEF 規則仍以已接納的實際事件維護持久計數，不能把玩家看完說明當成買賣、擊倒或技能目標都已達成。以 Q2842 為例，可重用現有 `0036` 接取、`001C/category3/NPC10002` 候選對話／交付、同筆 700 EXP 與完成保存。其正常流程與既有主線同 NPC 優先政策皆已有明確設計。[S10、S11；R-q2842]

未知是「某種全新目標的實際事件如何進入規則引擎」，而不是所有任務規則都未知。已接入事件先用；新事件逐一補 adapter。Server MEF 亦可將已確認事件映射至 `0047`，選擇一段有限 Client 內容處理後續，不需要先有通用事件注入。任意 Client Lua 的 local variable 不是持久任務記錄，也沒有本包已證的任意目標上報 binding。

## 6. 結算、獎勵與保存：具體採用既有提交路線

### 6.1 Q119 已有可用的正常流程

原資料 Q119 要求 Q118、等級 5、Town 1、NPC 10047；現行候選四個節點為 Map 632／633／634／635。MEF 可定義四節點清組、出口、入場／清組／返回演出及終點條件。完成後接 Q120，但 Q120 還要求等級 8、NPC 10008。門檻保留為內容資料，不能只改敘事游標就讓玩家必然可接。[R-q119、R-q120、R-q119-route；S08、S12]

目前已發布的 Server 文件載有以下接線：

1. 正常副本走到終點、通過已定義出口並完成返回流程後，保存 `ScenarioCompletion`，內含 Quest、definition、catalog SHA、終點節點、出口與參戰角色。
2. 經驗規則 `tartaros.server.story-experience.v1` 提供門檻與每任務經驗，接收者採完成事件的參戰角色；同一 SQLite 交易保存主線進度、完成事件、經驗帳本與角色累積經驗。
3. `LOCAL_STORY_WALLET_V1_NOT_NATIVE_MEF` 為 Q119 定義 LeeLoo 900，綁定既有經驗政策 SHA；正常通關、返回並完成劇情後，主線、經驗及錢包同筆提交。帳號／Quest 帳本用於避免重複授予。
4. 較新的熟練度文件已將 RewardsEtc type 3 接到保存的帳號／Quest 結算記錄，Q119 為 40；最終出口時結果頁先顯示，**完成返回劇情及主線交易時才入帳**。
5. 提交後以角色 `005C`／`0034`、任務 `006F`、資產 `002C` 及適用帳號初始狀態更新，恢復 NPC 資格與下一任務。登入由持久紀錄重建。

以上是**已存在的 Server 實作／離線驗證文件記錄，本輪未重跑其 Server，也未閱到此 repo 外的即時部署程式**。新 MEF 接線應採用這些服務，而不是重建另一份錢包與存檔。[S03、S08、S17]

來源優先序按具體主張處理：S08 保留的早期「type 3 用途未查」已由較新 S03 的原件 consumer 與保存設計補足；S09 的早期 Ready-only 回填由 S10 的 Accepted／Ready／計數規格補足。舊段落不是目前缺口的唯一依據。強化亦以 S34 後續實作段落為準，沒有將它的早期取證計畫當成整個服務尚未存在。[S03、S09、S10、S34]

### 6.2 獎勵語意已比早期報告更完整

| Q119 原 RewardsEtc | 已核 Client 語意 | 自有 MEF／Server 採用 |
|---|---|---|
| type 2：5850 | PartyExp 顯示欄位 | 可作既有參戰角色經驗政策的配置來源；受益範圍、曲線與倍率採明確版本，不宣稱原服算法 |
| type 3：40 | `record+84 → UIText 164/kQuestRewardSkillExp`；主線結果第一列為 SkillExp | 使用現有熟練度授予與保存；不能沿早期「type 3 未知」文字繼續擱置 |
| type 4：900 | LeeLoo 顯示欄位 | 既有 story-wallet 規則與共用買賣錢包；交易後發布 `002C` |

本輪對 type 3 再核原 BIN。`4C4550` 實際分別複製 payload `+10` DWORD 到 manager `+30`、payload `+14` WORD 到 `+34`；因此 `6BA4C2` 讀 manager `+32` 的 DWORD 對應 application `+12..+15` 的四 bytes，並非另有一條直接從 `+12` 讀 DWORD 的指令。`6BA46B` 選 UIText `2C6/kSkillExp`，`6BA4DA` 選第一列數值控制項。原靜態文字表也確認 `164 → kQuestRewardSkillExp`。這封閉的是**結果顯示欄位**；提交仍沿上節的結算服務。[N-result-copy、N-result-skillexp、N-reward-type3-ui、N-label-164、N-label-2c6；S03、S15]

### 6.3 自有 MEF 的最小提交契約

自有規則引擎以既有事件計算 `OutcomeCandidate`，其中至少有內容版本、Quest、終點、通過出口、受益角色、獎勵方案與返回完成條件。這是 **Server 內部介面提案**，不是新增 Client wire，也不是虛構原生 Lua 函式。[`adapter-contracts.json`、`authored-policy-example.json`]

既有 settlement adapter 接到候選後，只做共用工作：以當前帳號／副本與已接納事件解析身分，套用同版本規則；依既有交易保存完成事件、獎勵帳本、角色／錢包／熟練度及敘事 checkpoint；提交成功後產生既有發布內容。**條件與金額在 MEF，通用交易在 adapter。** Server 端執行這段 MEF 仍算 MEF 功能，減少的是每任務專用程式；CPU、I/O 不會因改成規則檔而消失。

正常保存有三種資料，不能混成一個 completed 布林：副本曾達成終點、Quest 已結算及獎勵已入帳、重新登入要接哪段內容。MEF 宣告需要保存哪些業務 checkpoint；不必將逐幀相機、字幕位置或任意 Lua 堆疊寫 DB。現行普通任務已可保存部分進度；現行未完成主線副本的重登策略仍是重新進入副本，不因導入 MEF 就默認續到戰鬥中途。[S08–S10、S17]

### 6.4 結果畫面與返回按鈕也沿既有接口

一般 Scenario 的 `S2C 0022/type0` 安裝結果場景／頁面，與 Tutorial `004C` 不同。`C2S 0033` 的已核直接返回分支只有 opcode，沒有 Town／Quest。MEF 定義返回目的地與後續劇情；adapter 依當前結果狀態解析。不能用 `Q.RestoreMap` 替代 field、world actor、controller、points 與保存狀態的完整回城。[N-result-return；S07、S15]

結果畫面可以先顯示待結算獎勵，再沿既有返回條件入帳；應明確標記這是現有 Server 政策。任意 `Q.End`、`OnEndTalk`、`003F` 或畫面消失都不自動成為所有任務的提交證據。新內容要使用哪個完成回報，須由選定執行 profile 的明確契約連到已接受的當前步驟。

## 7. 建議實作順序與本輪完成度

| 優先序 | 本輪完成的分析 | 下一個可以實作的功能 | 精確缺項 |
|---|---|---|---|
| P0 | NPC／商店／點與普通互動正向路徑、可用 Lua setter、方向別 wire、現有任務與交易落點已對齊 | 使用既有入口發布一段 NPC 演出；演出後開啟已預放的出口或商店點 | 新 MEF 執行 profile／依賴綁定及正常流程畫面驗證；不缺官方 MEF |
| P1 | Q119 四節點、獎勵三種類別、返回與同筆保存、Q120資格的規則／adapter 分解完成 | Server 執行 MEF 條件／獎勵規則，接既有結算／存檔；清組後可用一次 `0047` 選有限內容，Client 自行演出並開點 | 自有內容模型到現有 scenario／experience／wallet／skillExp 的編譯或載入接線；所選 finite profile 的資料與安全時點。只有需要常駐動態事件注入時才另補一般結果橋 |
| P2 | 既有普通任務 Accepted／Ready／計數、商店解鎖與價格、登入回填可復用範圍已分清 | 共用事件索引與資料編譯器，新增任務／店舖只改 MEF 規則；保存明確 checkpoint | 新目標事件逐項接 adapter、Client 顯示表與 Server 規則一致、正常跨場景／重登驗收 |

本輪完成的是此分題的能力與責任分析、資料重驗與實作交接；**沒有把新 MEF 接線或指定 Client 遊玩標為完成**。既有文件中已完成的 Server 工作保留其原測試範圍，尚未接的項目只列差額，不重新列成整套缺失。

## 8. 減負如何驗收

先讓一條正常旅程可玩，再比較相同內容的兩種實作。記錄每次 run 的 Server 計時器數、純表現排程回呼數、演出逐步指令數與 bytes、規則評估次數、交易次數與耗時，以及 Client 是否完成相同對話／開門／回城。固定內容與測量範圍後才報差異。[`offload-plan.json`]

預期可移走的是台詞／相機／動畫的逐步編排、等待及已知本地條件後的開點。Server MEF 可以將任務規則與價格表資料化，並在載入時建立 event → rules 索引，免每次事件掃描不相干任務；這是設計提案，未量測不報 CPU 或網路百分比。結算交易、持久化及必要世界同步仍有成本。若目前已由 Client 原生 UI 自行推進，將同一件事稱為 MEF 不能再重複計算一次收益。

## 9. 證據、重跑與交付

- `source-manifest.json`：原件 SHA 與固定 Git commit／blob／檔案 SHA；特別納入較新的實作文件，避免使用早期未完成狀態覆蓋後續成果。
- `data-evidence.json`：只讀六個指定 Table member，保存 metadata／hash 與選定數值；沒有完整 member。
- `native-evidence.json`：指定原件窗口、位址、長度、hash；分開舊證據重核與本輪精確 consumer 接點。
- `capability-split.json`：12 項能力的 Client MEF／Server MEF／adapter 分工與尚缺事項。
- `adapter-contracts.json`：8 個既有／待接 adapter，方向別 wire 與提交邊。
- `authored-policy-example.json`：Q119 與商店／普通任務的自有內容提案，明示不可直接當既有 schema 或原生 Lua 載入。
- `offload-plan.json`：玩家情境、可移走的 Server 工作及測量項目。
- `verify_evidence.py`／`verification-result.json`：重跑固定 Git、原件窗口、指定資源與機讀分工的一致性；不執行目標程式。

```text
python -B kr-extra-roy/MEF-server-provided-capabilities-20261118/npc-progression/verify_evidence.py --repo /path/to/ttr_anal_multi --bin /path/to/02-Tartaros.bin --table /path/to/07-Table.stp
```

PASS 僅表示本包明列的有界原件／來源／內容一致性通過，不是 Server 重跑、Client 實機、資料庫提交、T01 FULL-PASS 或正式需求關閉。本輪沒有另起分支、改舊內容或進行 Git mutation。
