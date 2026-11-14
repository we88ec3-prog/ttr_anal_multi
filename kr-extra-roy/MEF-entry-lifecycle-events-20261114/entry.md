# 第三輪：普通副本／城鎮中，新 Lua 內容的實際可達入口

本稿由 `/root/receive_windows` 交主研究者整合。用途是確認未修改 KR Client 程式能從哪些有效觸發選取並執行內容，不追官方 `.mef` 發送歷史。使用者已授權本輪繼續分析後由主研究者上 Git；此子任務僅寫指定 scratch，不修改 repository／index／branch，不執行或修改 Client、Server、Lua 或原始載體。

## 1. 結論與完成範圍

**普通副本與城鎮已有一條可用的有限劇情入口：有效 S2C `0047` → Client 前端的任務管理器 → `(questIdx, sceneIdx)` → 已載入 `SceneList` 的 `funcName` → `Event/Sequences/<funcName>.seq` → 獨立預載 VM → 正式共用 Lua context。這條分派不要求目前場景是 `CScenarioField`。**

然而，以下三件事不能合併：

| 條件 | 已證能力／界線 |
|---|---|
| 原 Client 程式與原資源都不變 | Server 可要求播放資料表中已存在、資源可讀、符合狀態條件的劇情。 |
| 原 Client 程式不變，但事先提供相容的新資源 | 可沿既有鍵／路徑或新增本機 SceneList 鍵建立新內容候選；必須真的讓資源解析器取得新內容，並滿足兩個 VM 的契約。這是靜態相容方案，未在本輪實作或遊玩驗證。 |
| Server 只在遊戲封包中送任意 `.mef` 檔名或 bytes | 本入口沒有檔名／blob 欄位，也沒有把來包 bytes 交 Lua。尚無可直接使用的交付與登記通路。 |

**`0047` 會啟動劇情管理狀態，並非已證的不干擾戰鬥之常駐腳本服務。** 非零 quest 能避開一個特定場景類型／已看鍵 gate，仍不能免除 manager busy、Lua 初始化、資源、預載、畫面／物件操作及排程條件。`global DoFile` 與 `lb.DoFile` 的存在也不會自行產生新的外部觸發。

本輪新增的是前端 `0047` 的明確虛擬分派閉合、固定啟動路徑的上游、SceneList 的載入生命週期、另一個 review UI 入口的有界閉合，以及 Field19／Map191 與實際 `.seq` 選取之分域反例。既有 15 個 `6F4A50` caller 清冊、Lua parser、兩 VM／全域 context 及一般網路接收器陰性結果均復用，沒有宣稱為新發現。

## 2. 來源、工具與證據等級

- 原 `02-Tartaros.bin`：12,472,320 bytes，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 固定 main 導航快照：`552e05a024505a3773095f951c285216051ce2a1`。本輪用 `git show <commit>:<exact-path>` 取既有 bulk 函式；未重新全量反編譯。
- 最新基線：`governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md`，blob `6fc6018a3dd5119cbd927fa183cb4228229d0dd7`。其中 005F 類型、Case／Map／Stage 分域、TRIGGER 未閉合、三個 Quest 入口與初始化 Lua 檔名都是既有資料。
- 新原件證據在 `native-windows.json`／`.asm`：**46 個視窗、7,976 bytes**，各窗有 VA、raw offset、長度、完整 hex 與 SHA-256。PE32 位址由節區表換算，不靠偽碼參數型別推斷。
- `native-windows.json 的 entry-data 群組` 保存固定路徑、欄位名與 review RTTI 字串。`upstream-xrefs.json` 是有限指定目標的 E8／立即指標候選掃描；其陰性不能排除所有計算式間接呼叫。
- `selected-entry-resources.json` 只讀七個指定 member：SceneList、MapList、CaseList，以及 quest15 的四份 `.seq`。保存 carrier／member 身分與選定資料，未保存整個解碼 member、未執行腳本。

前稿交叉依據：`../MEF-parser-executor-storage-20261114/parser.md`、`../MEF-parser-executor-storage-20261114/executor.md`、`../20261114-183651-chatgpt-web-roy1-MEF-delivery-windows.md`；本輪排程整合依據是 `lifecycle.md`。這些內容的身分及本輪使用的精確 Git 來源列在 `source-manifest.json`。

## 3. `0047` 為何能在非 `CScenarioField` 場景到達 loader

### 3.1 它是前端任務轉發，不走 generic scene-null gate

設完整 Client 為 `C`。原件 `493170` 從 `C+208` 起，每個 command 使用 16 bytes 的前端項目。`4936D4` 放入函式 `494440`，`4936D9` 寫到 `[C+678]`；`(678−208)/10h = 47h`。`48AAD0` 由 command 索引這份表並呼叫非空函式。

`494440` 只在必要時建構任務 singleton，然後在 `494496..4944AF` 將原參數轉送 `FAB2A0` 的 vtable `+4`：

| 閉合點 | 原件證據 |
|---|---|
| Quest singleton vtable | `4FFE95` 寫 `[FAB2A0]=C0DB08`。 |
| 虛擬分派 | `C0DB08+4` 的原 DWORD 為 `4FDA30`。 |
| Quest command table | `5020B0` 從 `FAB2A4` 起，stride 8；`50210B` 寫 `[FAB4DC]=503040`，索引也是 `47h`。 |
| 接收參數 | `503098`、`50309C` 分別以 `movsx` 取 message `+4`／`+2` 的 signed WORD，再呼叫 `561760`。有效欄位存取下限是 6 bytes，不包含外層 framing。 |

這條路沒有經過 `4B7EC0` 查 current-scene 的 generic 路徑。因此，不能把先前「generic 分派時 scene 為空便丟棄」的規則套在 `0047`，也不能把 `0047` 限定成只有 `CScenarioField` 安裝後才有 handler。

**這並不證明 scene 為空時安全播放。** 後續劇情會操作共用 Lua、UI、資源與場景物件；前端能分派與整段執行前置成立是不同命題。正常 Client 初始化及有效遊戲 context 仍是 Server 排程條件。

### 3.2 兩個鍵確實選本機表，沒有檔名來源漏洞可省略

`503040` 傳入的兩個有號整數是 `561760` 的查找鍵。`561A1C..561A85` 以 manager `+0C` 的樹查 `(quest, scene)`，比較節點 `+0C`／`+10`，命中後才使用節點 `+14` 的字串。

路徑形成在同一函式內直接閉合：

1. `561A8D` 取固定字串 `C106D0 = Event/Sequences/`。
2. `561AB0` 取命中節點 `+14`，`561AC4` 附加該 `funcName`。
3. `561ACB` 取固定 `C106E4 = .seq`，`561AD4` 附加四個字元。
4. `561AF3 → 55D6A0` 在獨立預載 VM 讀取同一路徑並收集所需資源；同步預載與等待在正式載入前。
5. `561C7A` 取 `[manager]` 作 Lua wrapper，`561C7D → 6F4A50` 載入並執行正式 chunk。前稿已由原件閉合 `6F4A50 → 714770 → resource buffer → Lua parser/protected call`。

查無鍵時，`561A85` 跳 `561D7F`，再 `561D81 → 561DB0` 走結束邏輯，**不把兩個數字拼成檔名、不嘗試以 MapID 或 TRIGGER 作替代**。本稿不把這條結束呼叫說成有明確 wire failure ACK；既有 `3F` 的回報語意另有條件。

因此，新增網路數值鍵之前，Client 的表必須已存在對應列；只把一個新 `.mef` 或 `.lua` 放在磁碟上，不足以令 `0047` 選中它。此入口會附加 `.seq`，不能以「Lua loader 不檢查副檔名」省略路徑形成規則。

### 3.3 `561760` 的 gate：非零 quest 的精確意義

| gate | 原件行為 | 不能推成的結論 |
|---|---|---|
| manager `+28 != 0` | `5617C2` 比較；`5617CF..5617E4` 記錄後跳函式尾，沒有排入待播佇列。入口也會先將 `+89` 清零。 | 不能連續預送兩段並期待 Client 自動串接。 |
| `FB92F1==0` | `561823..56182A` 直接往正常接納分支。 | 不能由這個設定名稱推測所有遊戲狀態。 |
| quest 非零 | `561830..561834` 直接往 `5618DC`，避開下面的場景模式／已看鍵 gate。 | 不能解讀成不需載入、沒有 UI／輸入副作用、或任意 key 都有效。 |
| quest=0 且設定 byte 非零 | 只有 GameInfo `+5F4C` 為 `9`、`4`、`0x19`（十進位25）才再查 manager `+74` 的場景鍵集合；未命中才繼續載入，命中可走回報／略過分支。其他模式直接往接納。 | 不能把 type4／9／0x19 當成所有 `0047` 的白名單，更不能把 `0x19` 當 STAGE 十進位19。 |
| 接納 | `5618E9/EC` 保存 quest/scene 到 `+38/+3C`，`5618EF` 設 `+28=1`，之後做 UI／資源／腳本工作。 | 接納不是純粹的背景函式呼叫。 |

在此明確入口到選路徑的已核段中，沒有再查「玩家目前已接取同 quest」或「MapID 等於某值」的條件。Server 仍必須自行驗證連線階段、目前地圖／物件、任務進度及可用內容，不能把 Client 少做的一項商業規則當成 Server 可省略的條件。

busy 分支不能稱為「完全無副作用地忽略」：`5617C6` 清 `+89` 發生在 busy 分流之前；另一入口 `565720` 則先設 `+89=1` 再檢查 busy。兩者雖不將第二段排隊，仍可能改變既有播放的 normal／review 結束分支選擇，這也是 Server 不應盲目重送的具體理由。

兩個 WORD 是 **signed 16-bit**。Server 新增對照鍵時，必須符合其實際 signed 解碼與 SceneList 整數鍵，不可只用 XML 能寫更大正整數就假設 `0047` 能原樣表示。例如 review UI 的 `60001` 特例與此網路有號欄位不是同一個入口契約。

## 4. SceneList 的生產端與載入生命週期

`560170` 建構場景 manager，初始化容器；`560344 → 5607D0` 解析固定 `Event/SceneList.xml`。定向 E8 掃描只得到這一個 `5607D0` caller，所掃 `.text/.rdata/.data` 也沒有該入口的絕對指標候選。這是有界靜態結果，不是所有間接控制流的形式證明。

`560815` 的固定路徑交 XML document helper，`560845 → 72F110` 讀取。`56088A` 找 `SCENESET`；子列逐一讀 `questIdx`、`sceneIdx`、`funcName`。`560989/98D` 組兩個整數，字串複製後在 `5609B3/9C4` 交樹插入 helper，容器基址為 `FB73C8 = manager+8`，其樹頭指標是 `manager+0C`。

**`0047` 的每次觸發使用這份記憶體索引，不重新解析 SceneList。** 因此，若新內容靠新增鍵或更換 `funcName`，表的可見版本必須在此初始化前準備好，或另有已證的重新載入入口。目前沒有用 `0047` 自動刷新表的證據。若只更新相同已索引路徑下的檔案，仍有前稿已證的 STP 索引／快取與資源可見性條件，不能把磁碟寫入時間直接當作下一次 loader 所讀版本。

這不是要求取得官方傳檔紀錄：Server／內容部署可以設計自己的版本放行流程，但不能假造 Client 的 refresh opcode。

## 5. 固定啟動 Lua：由程式初始化選取，未由普通入場選取

既有 T16 清冊已列出啟動 caller。本輪從它們向上閉合了真實控制流程：

1. `4A2EC0` 的 bootstrap 成功分支到 `4A3046 → 48AB70` 建構 `CClient`。封裝管理初始化在先，這一點復用最新 baseline。
2. 建構式 `48AC79` 設 framework 子物件為 `C+8`，`48ACA6` 寫 vtable `C05AA4`；建構式尾 `48B113..48B13B` 明確載入三份固定檔。
3. `4A304B` 設 `ESI=C+8`，`4A305A → 6DEB40`。框架初始化成功支線 `6DEC18..6DEC1E` 呼叫 vtable `+28`；原 DWORD `C05ACC` 為 `48C6E0`。
4. `48C6E0` 內先載固定 UI／Table Lua，稍後 `48D775 → 560600` 綁場景 manager 的 wrapper，再載核心四份檔；`48D7DE → 4A88E0` 設教學的共用 wrapper。前稿已證正式環境 `W=&FDF3C8, L=[W]`。

| 初始化位置 | 原件實際固定路徑（保留大小寫） | context |
|---|---|---|
| `48B11D` | `Boot.lua` | `ECX=&FDF3C8` |
| `48B12C` | `Logic.lua` | 同上 |
| `48B13B` | `Coroutine.lua` | 同上 |
| `48CA11` | `UI/LUA/LuaUtil.lua` | 同上 |
| `48CA4D` | `Table/LUA/Tables.lua` | 同上 |
| `560796` | `Coroutine.lua` | `ESI` 是所綁定的同一 wrapper |
| `5607A2` | `Boot.lua` | 同上 |
| `5607AE` | `Logic.lua` | 同上 |
| `5607BA` | `Event/qbase.lua` | 同上 |

這些位置沒有以本次 Field、Case、Map 或封包字串選路徑。正常進場不會因 Map191 而把 `S_pathofpindus01.mef` 填入上述參數。它們支持「在既有固定 bootstrap 內容中安排程式啟動時的 Lua」這種內容方案；不支持「Server 到新 map 時要求固定檔重新執行」。

既有 baseline 已讀兩份 UI／Table Lua 及三個明列 `DoFile` 子檔，未見後續腳本載入或 MEF 關卡選擇。本輪不重掃這些內容。`global DoFile` 的註冊與 `lb.DoFile` 的間接 bridge 在前稿已閉合：**只有某份實際已被啟動的 Lua 呼叫它們，才會形成下一個 path→loader。** 已註冊 API 不能代替最初的 bootstrap／SceneList／其他 caller。

## 6. Field19／Map191 及城鎮：五種 selector 不得混用

### 6.1 場景類別實際由 `005F` 的 subtype 選擇

原件 `4B99C0` 的分支已在 main baseline；本輪取原 bytes 與兩個 constructor／init 做語意對照：

| 輸入 | 真正選取 | 後續局部效果 |
|---|---|---|
| S2C `005F`, BYTE+2=`2` | `4B9A55 → 4C46F0`，`CScenarioField`，vtable `C073B4` | init `4C4750` 重用／建立 kind3 Formation controller，UI 狀態7。 |
| S2C `005F`, BYTE+2=`4` | `4B9A76 → 4BC6A0`，`CMissionField`，vtable `C0705C` | init `4BC750` 重用／建立 Single controller，走此類型自己的 UI／旗標。 |
| `0012`, DWORD+2=`191` | 共用 `4B24F0` 先 reset，再 `4DF510` 以地圖 selector 查表 | 不是場景類別的自動判斷式，也不是 SceneList quest/scene 鍵。 |

所以「普通副本」的口語名稱不足以決定 type4。Field19/Case103 目前已分析的主線候選用 type2；普通 Mission 路線使用 type4。兩者選擇須由 Server 的具體玩法流程決定，不能因 MAP 名稱、`TRIGGER` 副檔名或某個數字相等而互換。

模式欄位可做原件位址閉合：`404BF4` 返回 GameInfo 基址 `F8D9E0`，`F8D9E0+5F4C=F9392C`；`4B9A26` 以 `movzx` 讀 `005F` BYTE+2，`4B9A32` 寫到 `F9392C`，再進場景 factory。故成功 type4 安裝路徑會使上述 gate 的當前模式為4，成功 type2 則為2。這是此轉場路徑的關係；欄位在分配／安裝之前已寫，不能視為對所有異常狀態都成立的「enum與物件必然一致」保證。本稿不替9或0x19另外硬命名。**STAGE19、005F 的 subtype、當前模式0x19(25)、Case103及Map191是分開的資料域。**

本輪原件也確認 `CScenarioField+14` 是 `8DC2F0` 空 leave hook；`CMissionField+14` 是 `4BBF10`，**不是 `4BCA90`**。後者是其他接收入口；本輪 scheduler 支線另查其 gate／清理，不可把它當作所有離場自動取消腳本的證據。

城鎮的 scene 安裝同樣獨立於地圖。既有 roundtrip／mission-lobby 文檔已區分 `0069` 的 Square 與 `0099/type3` 的 MissionRoom 候選，不能單看 Map182/Town1 就宣稱唯一場景類別。本輪只利用已證 `0047` 的前端路由：有效城鎮 context 可以有同一個有限劇情入口，不新增城鎮 subtype 或旅行封包假說。

### 6.2 三份原資源的精確分域

`selected-entry-resources.json` 是本輪對原載體的定向再核對；以下本身也有既有 Field19 分析支援，不當作新找到的 MEF。

| 資料域 | 值／來源 | 用途 |
|---|---|---|
| 邏輯 STAGE | `19` | `_CaseList` 的 STAGE 欄；與 Quest15 的 field 關係沿用基線。 |
| CASE | `103` | 原列 `STAGE=19, MAPFLOW=CHART_S_pathofpindus_01.xml, CLUSTER=CLUST_S_pathofpindus_01.xml`；0038 預載鍵沿用已證契約。 |
| 實體 MAP | `191` | `_MapList`: `MAP=scenario_pathofpindus01D`, `BOUND=scenario_pathofpindus01`, `TRIGGER=S_pathofpindus01.mef`。 |
| 下一實體 MAP | `192` | `scenario_pathofpindus02D`／`scenario_pathofpindus02`／`S_pathofpindus02.mef`。 |
| 城鎮 MAP | `182` | `town001D`／`town001`／`town001.mef`；不因此得到 TownID、場景類型或出生位置。 |
| 劇情 KEY | `(15,1..4)`、`(119,1..5)` 等 | SceneList 雙鍵，選擇 `.seq` 的 `funcName`；不自動等於 map／stage。 |

`4DF585..4DF58D` 確實以 MapID 查 `FB74C0` 的 TRIGGER 容器。但到 `4DF5B9` 開始下一個查找時已覆寫回傳暫存；本窗沒有把取得的字串交給 Lua。更後段的地形／碰撞／小地圖分支、0014 ready、0038 Case／Town 預載的陰性閉合沿用固定 main baseline，沒有重做全表掃描。

因此本輪仍未證實 **Map191 入場自動觸發 `S_pathofpindus01.mef` 的 consumer**。這個剩餘缺口是精確的資料流缺口；不是因未取得「原生 MEF」才拒絕分析，也不妨礙先使用正向已閉合的 `0047` 劇情能力。

### 6.3 四份原 `.seq` 是具體反例：相同 quest 不代表該地圖的關卡腳本

| SceneList 鍵 | `.seq` 檔名 | 腳本內的 `LoadMap` 字串 |
|---|---|---|
| `(15,1)` | `Square_Tutorial01.seq` | `Square03D.fld` |
| `(15,2)` | `scenario_tuto1_1.seq` | `Square03D.fld` |
| `(15,3)` | `pindos_talkevent.seq` | `town001D.map`，這是原字串，不擅改成 `.fld`。 |
| `(15,4)` | `scenario_tuto2_1.seq` | 空字串 `""`。 |

四份皆為 Lua source，頂層定義函式並 `Register(該函式)`，結尾包含 `RestoreMap()`；保存的選定行與完整解碼 SHA 可重跑核對。這些是劇情自身的場景操作，不能當成 Server 已安裝可戰鬥 Map191、載入它的 `.mef`、或完成 Field19 的證據。

## 7. 另一個 loader caller 已閉合為本機劇情回顧入口

T16 既有清冊中的 `5659D9 → 6F4A50` 位於 `565720`，本輪向上確認它不是新的任意檔名接收器：

- 原 vtable `C0312C` 的 `+15C`（`C03288`）指向 `47C5D0`。RTTI locator `C68B94` 指 type descriptor `F7D8E4`，字串是 `FUI::CScenarioReviewWnd`。
- `47C5D0` 處理本機 UI 事件 `578h`／`70Ah` 的選取分支；有效選取帶入 `47D810`。此函式在沒有隊伍或隊伍向量恰一筆的接受分支到 `47D530`；其他分支顯示提示。本稿只確認局部條件，不把它當所有 UI 開啟／解鎖條件的完備證明。
- `47D530` 保存選取記錄 `+248`／`+24C`，`47E890` 依選取的 quest 找本機已存 scene 集合並取第一鍵，`47D5B7 → 47B5C0`。
- `47B5C0` 若記錄 `+248==60001` 走教學特例；其餘在 `47B64A → 565720` 傳兩個整數，沒有把 UI 文字直接當路徑。
- `565720` 設 manager `+89=1`，仍檢查 `+28` busy，查同一個 SceneList 雙鍵，組相同 `Event/Sequences/<funcName>.seq`，先預載 VM 再正式 `6F4A50`。與 `561760` 相比，這個有界函式沒有相同的同步 preload wait 段；不能據此跳過資源或稱為普通戰鬥 runner。

`565720` 的另一個直接 caller 是 `561EF3`，位於既有 EndCutScene 的 review 續播分支；本輪 scheduler 附稿處理其結束／排程生命週期。至此已把這個已知 loader caller 上追至可辨識的本機 UI 觸發和有界鍵選擇。其菜單如何開啟、所有 ScenarioBook 解鎖政策不是本稿新增範圍，也不影響此入口仍被 SceneList／固定 `.seq` 路徑限制的結論。

## 8. 可交給 Server／內容開發的契約

### 已確認 Client 能力

- `0047` 在普通已安裝場景可到任務管理器與同一正式全域 Lua context，毋須替換成 Tutorial。共用 `561520 → f_doCoTask` 的逐幀泵與 outer owner `+BFCC` gate 由前稿及本輪 scheduler 支線閉合；此處依 scheduler 本輪的欄位證據表述，不另替未於該支線追 writer 的欄位命名。它與 Tutorial 專有 runner 必須分開。
- 已索引、可讀的 `.seq` 會先經資源預載 VM，再在正式 context 編譯／執行。普通場可以承載有限的 Q 劇情能力。
- bootstrap 和已啟動的 Lua 可呼叫已註冊的 `DoFile`／`lb.DoFile`，但必須有實際的初始 caller。

### Server／內容開發需求

1. 保留 connection／map／case／quest-scene 的分離欄位，使用既有 `0047` 的兩鍵契約；不增加未證的 filename/blob/ACK。
2. 把新內容的可見版本、SceneList 索引版本、依賴資源及正式 Lua 初始環境作放行條件。新增鍵要在索引載入前可見；不以發包後的固定 sleep 代替索引刷新。
3. 一次只要求一段可完成的劇情；busy 時原件不排隊。Client 的回報也不能自動等同資源成功、任務成功或一次獎勵交易。
4. 新 `.seq` 要符合雙 VM 契約：前置 VM 的 `Register` 會實際呼叫函式以收資源，只有有限 stub／collector；不能把正式環境的所有 `lb/Q/Tutorial` API 當成預載階段可用。正式執行及 coroutine 進度必須由對應 runner 支持。
5. 普通戰鬥期間持續生怪／判勝／背景更新，須另外完成 runtime scheduler、物件 ID、死亡／傷害 consumer 與場景清理的契約。`0047` 能啟動有限劇情，不能單獨填完這些 Server 缺口。
6. 遊戲內下發新檔、重組、登記及熱更新若要採用，必須找到真實 Client 接收／資源可見路徑；現有傳輸窗口本身不供應這項能力。

### 必要未知與精確下一步

| 尚未閉合 | 下一個有效證據目標 |
|---|---|
| Map191 自動啟動 TRIGGER | 從已定位的 `4DF58D` 回傳值或另一個能區分 Map191/192 的 consumer 找到實際 loader；不得只再掃 `.mef` 檔名。已排除範圍保留在 main baseline。 |
| 新內容的當次可見性 | 固定路徑 resolver／已載 package flag／索引重建入口及版本時序；本稿不把替換磁碟檔當成 live reload。 |
| 常駐普通戰鬥 Lua | 共用 qco 的狀態副作用、cancel/leave、可用 API 物件與事件生命周期；交本輪 scheduler／API 支線整合。 |
| 整段遊戲效果 | 有限候選內容與 Server 序列具體化後再做隔離遊玩驗證。本稿只有原件靜態閉合，沒有新增 runtime 成功紀錄。 |

## 9. 重跑與交付檔案

本分題的 46 個窗口與 14 個字串已併入 `native-windows.json` 的 entry／entry-data 群組；各筆保留原 tag、VA、raw、bytes 及 hash。`upstream-xrefs.json` 保留 12 個指定目標的有界搜尋結果；`selected-entry-resources.json` 保留七個指定原資源 member。

統一以本目錄 `README.md` 所列的 `verify_evidence.py` 命令重驗。工具會重新核對原件 bytes、候選範圍、選定資源與固定 Git 來源，沒有執行 Client／Lua。這些核對不是 T01 FULL-PASS、完整 MEF 功能或遊玩驗收。
