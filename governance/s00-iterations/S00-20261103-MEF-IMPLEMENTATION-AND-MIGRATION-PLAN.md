> 2026-11-04 使用者最新排程：MEF樣本／檔案搜尋與載入鏈追查（原計畫P0／Web目標1）暫緩，Server開發至少60%以後再重啟。過去已查找至少一週，本輪不重掃、不派此項。既有缺口保留，不因暫緩宣稱已解決。進度需由功能開發總表追蹤，合成測試通過數不折算成百分比。可先整理既有資料與Server自訂definition，保持NOT_NATIVE_MEF。

# S00：MEF實作與Server硬編碼遷移計畫

使用者要求：「規劃.mef檔的實作，那些功能目前由Server操控的改由.mef操控」。
這是PLAYER_ADMIN_REQUEST與後續實作計畫，**不是MEF格式已還原或現在已啟用MEF**。
AI／MEF維持S00主責最高優先，連段核心同樣由S00處理。

## 目標與目前缺口

目標架構為「MEF／其引用的關卡與AI資料定義內容，Server解譯並執行實例狀態，
既有封包adapter同步Client」。怪物、波次、事件與出口不再散落於C#固定陣列及分支。
Server繼續持有帳號／角色所有權、血量／傷害／冷卻、合法移動與進度提交，MEF事件
必須通過這些執行條件。移到檔案的是內容及規則定義，不是取消Server執行與驗證。

[MEF接收可行性](S00-20261101-MEF-RECEIVE-FEASIBILITY.md)及
[AI執行界線](S00-20261101-ENEMY-PACING-AND-MEF-BOUNDARY.md)仍有效：
目前只找到MapList.TRIGGER檔名查詢，未取得可驗證的原生MEF樣本、完整parser或
網路接收→解壓→事件執行鏈。42包未命中是指定索引範圍的陰性結果，不等全Client缺檔。
EMF／地圖Light容器另域；loading23/24已有人測可見，也不因此證明它下載MEF。

尚不能保證原生MEF一定定義全部怪物AI；它也可能只引用AI或其他腳本／表。
需要逐欄位／呼叫鏈證明後才決定哪些資料實際來自MEF，不把各種資源統一改名為MEF。

## 遷移對照表

|目前私有Server的內容|目標資料與執行方式|可用依據／尚缺|
|---|---|---|
|LocalPhindosBridgeConfiguration固定出生／Encounter陣列|ScenarioDefinition的spawn group、位置、數量，由MEF reader及其引用資源建立|Chart／Cluster成員已知；原生MEF位置與排程未知|
|每圖四怪、全死打開出口|事件條件圖：group cleared→unlock exit；manual interact→下一node或結果|v14按玩家更正保留Z互動；原版MEF事件表未取得|
|固定portal位置／key／半徑及手動屬性|PortalDefinition與typed route；Runtime套到已知27/1C介面|原生介面已證；官方佈點與key仍未知|
|LocalTutorialCombat固定HP60、傷害、冷卻、範圍與群體節奏|MonsterDefinition／AIProfile；Runtime通用尋敵、移動、起手、命中與死亡狀態機讀取資料|部分Actor／ABF可用；官方AI／數值來源待追，不從動畫FPS猜AI間隔|
|怪物攻擊次序、追逐及近戰決策分支|可驗證的behavior／condition／action定義與受控執行器|先查MEF是否本體或引用，不能直接重用玩家SubAI入口|
|教學三怪與主線兩圖的固定遭遇|各自ScenarioDefinition、來源SHA、不同instance state|教學怪數來自影片／重建；不能冒稱原MEF原生波次|
|故事／戰鬥／出口流程散落連線類別|ScenarioRuntime事件與旅程adapter；任務前置、結果保存仍由domain核准|Quest／Field／Case／Map／scene／portal key保持分域|

角色輸入同步、連段buffer、TCP額度、登入／帳號與長期保存屬共用引擎／領域功能。
除非原件證明MEF定義其參數，先保留於Server，不為達成「搬檔案」任意改變權責。

## 開發順序與可交付成果

1. **P0樣本與原生入口**：按既有42包索引及指定原始備份查確切TRIGGER名稱／引用，
   先scenario_town000.mef、S_pathofpindus01/02.mef；記載體／member SHA與查找範圍。
   選讀4F5640→4F7DF0／4DF510及尚未閉合的consumer，不重做全量反編譯。
   交付MEF-SOURCE-INVENTORY與逐入口unknown表。無樣本就保留BLOCKED_BY_FORMAT，
   不產出偽原生MEF。
2. **P1格式與讀取器契約**：驗magic／version、長度與section、壓縮、字串／索引、
   opcode或event layout及每個consumer。先唯讀NativeMefReader輸出typed IR、來源SHA、
   未知區塊與unsupported清單；每個已支援版本要有真實樣本和精確欄位證據。
   若含腳本VM，另閉合bytecode／指令語意；不直接執行不明腳本。
3. **P2執行層分離**：ScenarioDefinition、SpawnGroup、Condition/Action、PortalDefinition、
   AIProfile與每實例ScenarioRuntime。定義只讀、狀態與玩家資料分開。先把現有候選規則
   做可比對的Server definition以驗adapter；這是過渡IR，**不是MEF復原已完成**。
   自訂JSON／腳本使用自己的副檔名與schema，不能寫成.mef混充原格式。
4. **P3第一個native-derived關卡**：先Field19/map191一圖，依已證MEF資料搬生怪、
   清怪開出口、Z互動；再map192→結果→村落。每搬一項刪對應C#固定內容來源，
   保留通用執行器與封包codec，避免硬編碼和MEF兩邊同時生效。
   無來源的欄位仍標Server重建，不補猜官方波次。
5. **P4怪物AI資料化**：先1001／1009，逐項遷移感知、仇恨、追逐／回位、選招、
   冷卻、攻擊起手與效果；1004植物需獨立定點行為，不套移動型追逐。
   動畫、技能、碰撞、傷害判定及網路輸出各自對照來源，不從模型存在推定AI完成。
6. **P5其他場景與正式切換**：教學、其他第1村副本逐圖接入。以map／definition SHA
   明示啟用，沿用獨立發布版本。原生格式或重要條件不支援時回報未支援，不靜默跳關。

以上是工程工作包，沒有新增／冒充正式RR、REQ、CLM或APPROVED規格。

## Server回傳MEF到Client的獨立Gate

若目標包含「Client接收並執行原生MEF」，需先交完整可核對鏈：
dispatch／方向與opcode、framing／長度／分片、內容來源與壓縮、parser版本、
resource載入、事件執行與控制／權威分工，以及一份真實樣本。
尚無此鏈時，先發展Server端MEF interpreter與現有狀態同步；不虛構blob回覆。
本計畫不修改Client或資源。若原生Client確無所需介面，須另提出具體方案供使用者確認，
不能因本次規劃要求便自動解除共用Client修改政策。

## 每階段驗收與優先項

- 來源驗收：sample／carrier／member SHA、格式欄位到consumer、未知清單；原生和自訂IR分開。
- 工程正流程：同一definition正常載入、生成預期group一次、正常AI追擊／攻擊／死亡、
  清怪後仍可攻擊、出口需走上按Z、下一圖／結果與合法旅程保存。
- 人測：教學→廣場→單人主線兩圖→村落。圖內清怪不退出戰鬥；非戰鬥Z停步另驗，不混淆。
- 先完成眼前三項v14修正，再做P0/P1；AI／MEF與連段保持最高優先，整村主線內容可並行準備。
- malformed檔案、未知version／opcode、重入／重送、併發、故障、安全／壓測等先列待測，
  不在目前正常流程排程執行。資料格式支援、候選Server正常通過與原始Client相容性分開記錄。

完成標準：至少一個關卡由**已證原生MEF及其明確引用**生成definition並驅動可玩的
完整事件／出口／怪物行為；對應硬編碼已移除、正常資料與人測有收據。
只有建立抽象類別、讀自訂JSON或把舊數字搬到檔案，不算原生MEF完成。
