# 戰鬥全域敵群血量彙總

2026-11-22開始、11-23完成驗證。SERVER_DESIGN_CHOICE／OFFLINE_SYNTHETIC／NOT_NATIVE_MEF。
接續既有全域Health查詢待辦；不改內容格式、血量平衡或Client介面。

原本 `LocalTutorialCombat.Health` 每次查詢皆加總所有已生成敵人的Health，包含尚保留的
死亡物件。現在每場戰鬥首次查詢時掃描並建立彙總，後續讀取同一數值：

首次建立、敵人HP與其彙總更新、敵群加入與其彙總更新共用同一短鎖；診斷也可能讀Health，
不能讓尚未完成的首次加總覆蓋已接受的更新。callback在此鎖外沿用原順序執行，不在鎖內等待。
這不是整個戰鬥狀態的併發驗收，相關暫緩測試狀態保持。

- 唯一既有敵人扣血入口接受實際damage後，先更新彙總，再更新該敵人的Health；既有
  擊倒／掉落callback收到的是已更新後的狀態。波次血量觀察仍沿用原派送phase。
- 增援仍先完成原本的出生驗證、封包與物件建立，加入敵群後才將新成員血量加入已啟用的
  彙總。未曾查詢時不額外初始化；首次查詢直接讀當時完整敵群。
- 空初始組可建立0彙總，定時增援出生時仍加回正血量。舊敵人死亡保留0，沒有把死亡動畫
  刪除當成扣血，也沒有重用物件身分。
- 每個combat各自持有彙總，換圖建立新combat會重建敵群彙總；玩家狀態延續仍由原策略處理。
- 對外 `Health` 保持checked int結果；內部long累計避免把原getter的整數溢位檢查提早到
  增援出生階段。本批只驗正常可接受資料，數值邊界測試仍待排程。

清場仍須全部必要波已生成、血量歸零、原本的移除時限／投射物／必要頭目等條件成立。
這批沒有替換這些判定，也沒有把所有敵人遍歷一律刪除。Boss選擇、移除集合與AI目標掃描
仍是各自既有路徑，不能用這個彙總代替。

新增唯讀 `totalHealthObservationWork`，投影到既有StageOne／Story診斷：

| 欄位 | 意義 |
|---|---|
| queryCount | 原Health getter被讀取次數 |
| referenceMemberVisits | 這些成功正常查詢若仍使用原Sum所訪問的成員數，包含死亡成員 |
| initializationMemberReads | 首次建立彙總讀取的成員數 |
| spawnMemberReads | 已建立彙總後，出生路徑讀取的新成員數 |
| healthChangeUpdates | 彙總啟用後的非零扣血更新次數，不是傷害數字總和 |
| cacheInitialized | 是否已發生首次查詢 |

不同操作成本並不相等，這些數字不能換成CPU、吞吐或Client卸載；其餘戰鬥與診斷掃描
及短鎖成本也未算入。所選兩條路線的六圖讀取／更新數量，僅適用該實際內容。

## 驗證

[完整收據](total-health-validation.json)保存舊／新Network與相同Inspector SHA、完整
TCP比對、逐圖工作量、同版Host及Story控制。舊Network1683977e保持唯讀。

- 三個新增HappyPath對照獨立MonsterAgents逐筆加總，經真正輸入／命中／死亡／順序及
  定時增援後核對總量與返回gate；沒有波次observer時也有效。另驗空初始組等待出生、
  callback即時看到正確總量、正常重複查詢只初始化一次，以及兩場戰鬥彼此隔離。
- 兩條普通Case693分支的完整primary／dungeon回包一致，只正規化既有已定位的隨機
  wireAlias。敵群、逐圖血量、旗標、延遲快照與88EXP結算保持。
- 頭目房每路原查詢成員訪問2966次；新彙總首次讀1名、增援讀3名、更新15次。原逐波
  血量、必要增援與投射物機制未改。這是工作量，不是整體Server CPU節省證據。
- 同版獨立真實時計Host正常登入、建隊進村、六圖通關、保存88EXP並同隊回村。Story
  三條測試時計TCP控制維持出招三輪5984、初始清除停止5936／三輪5984，以及每輪visit
  與一次Q119結算；不把此次普通Host證據套用成新的Story獨立Host驗收。
- Host／Inspect／Admin Release零警告／錯誤，HappyPath782項、零失敗／跳過。隔離Host
  停止，來源DB、現用服務、原件與使用者進度保持。

指定v2、人測、自然全新帳號、Client自主AI及既有暫緩測試仍各自待驗。正常功能回歸與
工程計量不代表全部MEF完成。
