# RAID 1–3 關卡與 AI 配套

既有 RAID 的五圖 Server 關卡可以在 `/admin/scenarios` 選取 RAID 1、2、3，
沿用版本保存、AI 配對、原 BND 檢查及 ZIP 匯出。這是 `NOT_NATIVE_MEF` 的
Server 內容編輯，不能算原生 MEF 或 Client 自主 AI 的完成證據。

## 固定來源與可編範圍

|RAID|Stage／Case|基準檔 SHA-256|
|---|---|---|
|1|50／88|`e37997b09e30a425730b1c5a463ef3b6b561914233de90147fac6ac8cfac9a87`|
|2|51／89|`ab0630e952ffea353c1b4880dfa139f6701d65403af0a53e810e6bc7ca3e9c51`|
|3|52／90|`05d918b631c93fb1202fc39e3647a2f780cb0dabe723109532afa7d7fa7cc370`|

沿用 [RAID 入口與來源](EARLY-RAID-ENTRY.md)及其 15 張原 BND。來源範本仍以
固定 SHA 載入，不直接覆寫；編輯稿另存 SQLite 版本與匯出檔。驗證設定 SHA
包含原範本、RAID／Stage／Case、AI 基準與所有已讀 BND SHA，使用獨立 schema。
舊主線與狩獵場 profile 算法不變，歷史草稿仍依原 profile 選回。

可編出生、怪物、逐怪 AI、增援、訊號、屏障及出口位置／條件，但保留來源、
入口、節點／地圖、換圖目標集合、必要頭目身分與入場等級 7／12／17。
所有內容走共用圖、條件、AI 引用、巡邏及原 BND 可達性檢查。
現行 CP、成功／失敗結算與經驗書仍由挑戰領域處理；此編輯器要求關卡與怪物
EXP 為零、不配置地面掉落，避免編出執行器不會提交的獎勵。

## 管理端與 Host 載入

Admin 設定 `TARTAROS_ADMIN_RAID_SCENARIO_DIRECTORY`，指向三個固定範本的絕對目錄；
並設定 `TARTAROS_ADMIN_RAID_BOUNDS_DIRECTORY`。RAID 原 BND 與主線／一般狩獵場的
目錄分開；本機啟動器使用 `outputs/early-raid-bounds`，可用 `-RaidBoundsDirectory`
指定。來源可用時才啟用 RAID；保存／匯出均不自動發布、不更動玩家資料或 Client。

Host 保留原 `TARTAROS_LOCAL_RAID_ONE/TWO/THREE_SCENARIO_PATH` 與 `..._BOUNDS_DIR`，
另加該 RAID 的 `..._SCENARIO_OVERRIDE_PATH` 與 `..._SCENARIO_OVERRIDE_SHA256`。
兩個新鍵須成對設定；Host 先讀固定基準及 BND，再驗證覆蓋稿。
ZIP 清單提供覆蓋稿鍵，並提供既有共用 AI 的 `TARTAROS_LOCAL_MONSTER_BEHAVIOR_PATH`
及 `..._SHA256`。RAID 載入器現在也使用同一已固定 AI；它會影響其他共用該目錄
的關卡，因此配套仍須完整 Host 預檢，不能只看單個草稿通過。

```text
--raid-authoring-preflight <raid> <固定基準.scenario.json> <BND目錄>
<覆蓋稿.scenario.json> <覆蓋SHA> <AI檔> <AISHA>
```

此檢查器呼叫實際 Host reader，回報載入的 SHA、等級與五圖數量；它不啟動遊戲，
也不以預檢冒充正常入口／通關／指定 v2 實機。既有正常 RAID 證據保留原版本範圍。

## 2026-11-19 工程驗證

[收據](raid-workbench-validation.json)：三個針對性正流程及全部 631／631 HappyPath
通過，Host／檢查器／管理端 Release 建置零警告、零錯誤。針對性案例使用合成
地形，確認新增 AI 的 37 HP 已進入 Server 戰鬥實例；不宣稱 Client 動作。
三個 RAID 的隔離 HTTP 保存／配對匯出使用 15 張原 BND；AI-only 第二版、
第一版保留、ZIP 精確位元組與同工具重複下載均通過。三份實際匯出配套再經
Host loader 原 BND 預檢，所報 SHA 與 ZIP 相同。

管理端已更新至 19 組設定，瀏覽器確認 RAID 選項；四頁 200、部署組件 SHA、
loopback 與既有草稿指紋均核對。備份 `accounts-before-raid-workbench-20261119.db`。
遊戲 Host 保留，範例未發布；新覆蓋稿的正常 RAID 通關與指定 v2 尚未驗收。
初次隔離啟動混用主線 BND 目錄的問題已分開設定後重驗，不列成遊戲故障修復。

後續新增[單場正常入口驗證](../testing/RAID-NORMAL-ROUTE-INSPECTION.md)：三個基準
與三份實際匯出配套已從廣場建隊走到五圖戰鬥、成功結果、回廣場及經驗書交付。
這是準備角色／普通裝備／回復品的應用層六場收據；不是全新帳號養成、TCP 或
指定 v2 實機。上段的「新覆蓋稿正常通關未驗」是當時狀態，此補充限離線工程範圍。
