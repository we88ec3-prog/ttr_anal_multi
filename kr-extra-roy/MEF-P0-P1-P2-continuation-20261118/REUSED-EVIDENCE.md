# 已有證據、去重與本輪搜尋邊界

本包的固定 Git 基準為 `15d9501c203c6f656461b64f578a50c96e38a5ff`。下列內容已發布，原件沒有變更；直接沿用其範圍與限制，不把重列、重掃或重新閱讀計為新功能。

## 1. 原計畫各項的既有證據

| 工作項 | 沿用證據 | 本輪不能擴大成的主張 |
|---|---|---|
| P0 呼叫契約 | [ABI 報告](../MEF-comprehensive-contracts-20261117/abi/report.md)、[前輪重驗](../MEF-P0-P1-master-continuation-20261117/baseline-replay/abi.json)：121 bindings、33 marshallers、15 項已採用勘誤 | 不把名稱數量當玩家功能完成率；4 個 stub 不變成功能 |
| P0 真實依賴 | [Master 與 loader](../MEF-P0-P1-master-continuation-20261117/master-resource-closure/report.md)、[原前緣差異](../MEF-P0-P1-master-continuation-20261117/master-resource-closure/p0-frontier-delta.json) | 899 members／897 掛載不是 897 份素材已到手；同名 provider 候選不是實際 winner |
| P0 執行收尾 | [生命期契約](../MEF-P0-content-contracts-20261117/execution-lifecycle/report.md)、[前輪重驗](../MEF-P0-P1-master-continuation-20261117/baseline-replay/lifecycle.json)：22 owners、20 cleanup edges、3 run profiles | `Q.End`、003F、00EB 各自不能作所有畫面／聲音／角色的總完成通知 |
| P1 正常旅程 | [Q119 及七族](../MEF-P0-P1-master-continuation-20261117/journey-families/REPORT.md)、[契約](../MEF-P0-P1-master-continuation-20261117/journey-families/contracts.json) | 5 段 SEQ、4 節點、10 步資料旅程不是已實際通關 |
| P1 七族 | 同上：相機、聲音、圖片、書本／教學、世界 NPC／服務、互動點、場景／小地圖各有一個真實資料例 | 7／7 是這七個指定族的例子，不是所有素材／任意組合皆可用 |
| P1 普通入口 B | [前輪 typed receiver／Rebind／繼承 reader](../MEF-P0-P1-master-continuation-20261117/entry-b/report.md) | receiver 安裝或改綁本身不是第一次載入腳本；本輪會修正 binder 及 `+18` receiver 定型 |
| P1 world→Lua | [前輪 producer／HUD／AI／視覺 tick 與 draw](../MEF-P0-P1-master-continuation-20261117/world-lua/report.md)、[契約](../MEF-P0-P1-master-continuation-20261117/world-lua/contracts.json) | 傷害字、血條歸零、死亡狀態、刪除物件不是同一件事；沒有已證同 run／generation 的通用 Lua 通知 |
| P2 原格式 | [parser／executor](../MEF-parser-executor-storage-20261114/parser.md)、[有限 native alias 閉包](../MEF-complete-flow-20261115/native-aliases/report.md) | Lua parser 能接受內容不代表官方 `.mef` 就是 Lua；Field 宣告不提供 grammar |

## 2. 本輪已核對後停止重複的候選

### Tutorial 狀態 writer

較早報告曾保留 `Tutorial.GetTutorialState` 的 post-init writer。後續 [world 分題](../MEF-end-to-end-20261116/world/report.md) 已接到 `CTutoMsgDummy 6BFE90 → 6C00E4` 寫 controller `+134=1`，並接到原始 `TutorialMainPart1` 的 getter 迴圈。本輪採用後稿，不再把舊空白列為新發現，也不把固定教學狀態泛化為任意怪物結果。

### 最底層 Lua 執行 caller

本輪曾以原 BIN 做有限 E8／E9 與 literal 初查，核對 `6F5A50 / 6FC550 / 6FE1C0 / 6FE550 / 6FE770`。檢索既有結果後確認：[parser-executor 完整補查](../MEF-complete-flow-20261115/parser-executor/report.md) 已逐一分類 `6FE550` 的 20 個 direct caller 與 `6FE1C0` 的 4 個 direct caller；[alternate-entry](../MEF-trigger-callers-20261115/alternate-entry/report.md) 已分析 `debug.debug / require`；[runner](../MEF-end-to-end-20261116/runner/report.md) 已補 debug hook 的啟動與 consumer。

因此初查不再擴大成另一份同內容 census，也不計新增進度。既有 callable 來源涵蓋 stack、metatable、registry、VM register、標準庫與 coroutine；其分類是有限集合的值來源證據，**不能否定未取得腳本、計算後的間接呼叫、其他模組或動態 table/global 改寫**。普通 UI child 仍須由實際資源內容與 callback 建立者逐一接合，不能靠此集合宣稱 UI 永不執行腳本。

### 舊 native-root 冷支線

P2 已將後續 `native-aliases` 報告納入去重。已證的 world／font／sender／audio 分支不重算；本輪只保留精確 register-lifetime 勘誤與 Field 來源接點整理。各項新證據與停點見 [P2 分題](p2-format/)。

## 3. 重驗策略

新分題實際比對同一 BIN 原件窗、表、相對位址／來源 pin，並執行對應離線 verifier。根目錄檢查八個工作項、來源雜湊、Markdown 連結、交付檔案集合及未閉合 gate 的一致性。未變更的既有 ABI、收尾、Q119 和 world 契約採固定 commit 與原驗證紀錄；沒有為了增加 PASS 數而再次跑所有舊工具。

本輪新資料選取契約不得改變既有的 payload 缺件數、Q119 門的政策或完成旗標。舊兩場景 13 個缺 descriptor 與全 Q119 7 個缺 descriptor 是不同範圍，不相減、不相加冒稱整體缺件數。
