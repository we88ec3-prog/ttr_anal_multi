# 剩餘來源與精確解除條件

`Master.stp` 已取得、可讀且已完整分析，不是待補件。其 897 筆 AttachedPackage 與 PackingRules 的對應證明的是掛載宣告；素材檔案、選取結果與解析成功仍各自需要證據。[Master 摘要](../MEF-P0-P1-master-continuation-20261117/master-resource-closure/master-summary.json)

本輪對所供應檔案與補充來源重新核對雜湊，也作有限名稱查詢；沒有取得新的 `fcs.flu`、Field、UI Lua 或其他缺失素材。這個結論只涵蓋 [source-availability.json](source-availability.json) 的查詢及已供應來源，不是使用者全部磁碟的檔案清單。

## 1. 最小補件順序

| 次序／對應項目 | 精確材料 | 能解除的問題 | 仍不能直接推論 |
|---|---|---|---|
| 1／P0 | 同版 `fcs.flu`；若本次 fcs 開啟失敗、reader 回 0，提供實際 cwd、`Character/`／`Map/Map/` loose-file 樹與屬性；同 group 同 basename 多候選時補列舉次序，或提供完整範圍的唯一性證明 | 確認本次採 cache／掃描分支後，依 group、entry、basename 與原插入次序固定首筆候選及 literal path；另核全域 FB79A8 分支狀態 | fcs record 沒有 per-entry packed flag；最終 provider／payload 是另一門檻。`fopen` 成功不是索引完整，不能自行做新 cache 當原版選檔結果 |
| 2／P2 | `Field.stp`，或由它取得的真實 `.mef` 成員，附原包 hash、member path／index、版本 | 固定正例 bytes，往實際開檔 consumer、格式分流、parser 與 executor 追 | `.mef` 副檔名、Master 封裝規則、MapList.TRIGGER 或 Lua parser 各自都不足以證明官方格式 |
| 3／P1 普通入口 | `UI/Component.stp` 所供應的 `UI/Component/TalkBox_Scenario_Panel.FTC`；同時保留 root UI provider／loose override 的安裝情境 | 本輪已定位 resource 212 的明確 UI 檔名；取得實際 XML child／layout／callback 內容後可沿實際選中子元件續查 | 工廠能建立某個元件，不代表此 FTC 真正選用它；找到對話框也不代表第一次腳本啟動 |
| 4／P1 普通入口、P2 接點 | `UI/LUA.stp` 與實際被引用的 script member；若 Field／FTC 指向其他載體，按該真引用追加 | 核正常內容是否建立 callback、哪個 VM 執行、誰持續更新、如何取消／重入 | 有 Lua 載體不等於它必然實作普通背景入口，也不等於官方 MEF 是 Lua |
| 5／P0、P1 聲畫 | 已選中的角色 Base／avatar、FLD、圖片、音效／語音、MMT、EFF、書本模型與後代 | 將已分析的真實演出和 Q119 旅程補成具備完整素材的內容 | provider 候選或同 stem 檔案不是 selected winner；原件到手也不等於已渲染／可聽／可玩 |

每份新材料先固定原版 hash、大小、來源及 member；不同 BIN 版本另建位址映射。只重驗受影響的依賴，不重做同一套 bindings。

## 2. 聲畫材料按依賴取得

以下延續 [前輪詳細清單](../MEF-P0-P1-master-continuation-20261117/SOURCE-REQUEST.md)，沒有將尚未選中的候選名稱改成「已存在」：

- **角色 descriptor**：`Character/Cha/Base.stp`、`Character/Npc/Base.stp`、`Character/Obj/Base.stp`。既有 Mon Base 保留原來源與 hash；先定真正 CHA_ABF entry，再展開 `Items.ipk / Include / RelativePath / BaseFile / TextureList`。
- **avatar 與動作／貼圖**：按選定 descriptor 展開。已知候選包括 `Character/Mon/Avatar/02_Stoncken.stp`、`00_Alphonso.stp`；父 provider 先查，不預設 avatar 包就是 winner。
- **場景 FLD**：舊兩例需要 `mushroom12D.fld`、`town014S.fld` 的真實 MAP_FLD entry；全 Q119 另有 mushroom01D／04D／07D、town001D 方向。`Field.stp` 的 xml／mef 規則沒有證明它供應這些 FLD，`town014S` 與 `town014` 也不混用。
- **圖片**：`Image/Base.stp`、`Image/Prologue.stp` 與實際選中 DDS／條件 ETF、portrait 與 UI 素材。只有原 path probe 為零才走已證的 ETF 替代；原檔解碼失敗不代表會自動再試 ETF。
- **聲音**：原安裝的 BGM024／147／148、Stoncken 音效／語音，以及 Q119 的 bodyfall／BGM003／選中 voice。本輪不創造未證的 `Sound/BGM.stp` 或任意 Monster 聲音包名稱。
- **七族其餘材料**：`Map/MiniMap.stp` 中實際 MMT 及其 texture／markers、`Synopsis.stp` 中 book01..04、`Effect/Effect.stp` 中 `Area\Zone\A_Zone_TutorialZone01.eff` 與後代。

## 3. 缺件數的適用範圍

| 既有分析範圍 | 已知缺件 | 正確讀法 |
|---|---|---|
| 舊 P0 的 Q119/3 與 Q2440/5 兩例 | 132 個依賴 node 中仍有 108 筆原前緣；13 個模型 descriptor payload 未取得 | 「前緣」包括來源與選取情境，不是 108 個獨立 STP 檔案 |
| 全 Q119 的 5 段演出 | 11 個不同模型中，4 個 descriptor 已有，7 個未有 | 缺 1478–1481、10002、10003、10047；這 7 個與舊 13 個有重疊、分母不同 |

本輪沒有取得新的上述 payload，因此不減少這些數字，也不用 `132−108` 算全功能完成率。詳見 [舊前緣](../MEF-P0-P1-master-continuation-20261117/master-resource-closure/p0-frontier-delta.json)、[全 Q119](../MEF-P0-P1-master-continuation-20261117/journey-families/contracts.json)。

## 4. 不是靠補素材即可解除的兩個接點

**普通背景入口 B** 還需要一條正常事件 → typed owner → 第一次本次內容 load／execute → 同 VM 持續 pump 的正向鏈，並核取消、重入與普通操控。FTC 或 UI Lua 是更精確的下一份內容來源；不能保證補件後一定存在該能力。

**world 結果→原 Lua** 還需要真正 callback／getter 的建立者、結果 storage、同 run／actor generation／事件身分與同 VM consumer。既有血量、傷害字、死亡 FSM、erase 分支都不是這個完整接點。Server 可先實作權威事件並投影到已知相容通道，不等待或假造一個未證的原 Client API。

解除來源條件後仍要進行 Server／內容整合與專案允許的正常遊玩驗收，才能說玩家確實能跑完旅程。
