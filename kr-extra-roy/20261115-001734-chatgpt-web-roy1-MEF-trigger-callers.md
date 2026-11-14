# 誰觸發 MEF：地圖名稱查詢、真正的腳本入口與尚未閉合的 caller

> extra/roy1／KR 原件／本輪開始 2026-11-15 00:17:34 Asia/Taipei。使用者本輪要求：「請分析誰觸發.mef」；沿用同一對話「分析後上 git」授權。
>
> **總目標仍為階段性未完成。已找到觸發 `.mef` 名稱查詢的來源，尚未找到觸發新 `.mef` 首次載入、執行的正向 caller。** 本輪新增的是具體入口與資料流的核對，不能將候選排除結果提升為整個 Client 不支援 MEF、T01 FULL-PASS、RR ACCEPTED 或實機可玩。

## 1. 直接回答：目前能指認誰，不能指認誰

**如果「觸發」指讀取 MapList 的 `.mef` 名稱，已有 Server 地圖訊息的來源；如果指真正讀入並執行該 `.mef`，目前仍沒有成立的 caller。**

既有正向路徑是 `S2C 0x0012 → 4B24F0 → 4DF510 → 4DF58D → 4F7DF0`。它依 map ID 查 `FB74C0` 的 TRIGGER 名稱，例如 Map191 對應的 `S_pathofpindus01.mef`。然而，getter 返回的名稱沒有在這條路徑傳給檔案 reader 或 Lua loader；已初始化分支在 `4DF5B9` 便以 `lea eax,[ebp-10h]` 覆寫返回值。冷初始化分支也沒有把該名稱作為檔名參數傳入。這一段是前稿已證結果，本輪沿用並對照原件，不再算成新發現。[名稱儲存與 caller 基礎](MEF-parser-executor-storage-20261114/storage.md)、[本輪 root 資料流補證](MEF-trigger-callers-20261115/native-root/report.md)

因此，**不能把 `0x0012` 稱為「執行 MEF 的封包」**，也不能把「Server 已傳檔案」或「換圖時讀到 TRIGGER」當成內容已進入 executor。三個時點仍須分開：檔案可見、名稱被選到、內容被載入並第一次執行。

### 已證觸發來源對照

| 觸發來源 | 實際選到／呼叫的內容 | 能否據此指認新 MEF 的 caller |
|---|---|---|
| Server `S2C 0x0012` 的既有地圖流程 | MapList TRIGGER 的窄字串查詢；本路徑丟棄返回值 | **不能**；查詢與首次載入之間沒有已證 consumer |
| Server 已知 Quest 劇情入口，尤其 `0x0047` | SceneList 的 quest/scene key → 固定規則 `Event/Sequences/<funcName>.seq` → Q runner | 可觸發既有選中的 sequence；**不是任意 `.mef` 名稱或 bytes 介面** |
| Tutorial scene 的既有進場流程 | 固定 `Event/TutorialMain.lua` → `Tutorial_EntryPoint` | 是已知 Lua 首載入口；不是 MapList MEF 入口 |
| **本輪補閉的 Expedition page 初始化／特定 UI event** | 固定 `Event/TutorialMain.lua` → `Synopsis_EntryPoint` | 找到具體正常 UI caller，但檔名仍為 native 常數 |
| native 更新／對話／清理事件 | `f_doCoTask`、`t_doCoTask`、清理函式、旗標 callback 等已存在的 Lua function | 是執行或續行；本輪 caller 沒有提供新檔路徑 |
| Lua 已呼叫 `require`、`debug.debug`、既有 `DoFile` | module 名稱、stdin 命令、Lua 傳入的路徑 | 有 loader／parser 能力；**仍須找到正常流程首先呼叫它的具體位置與參數** |

表中舊 Quest／Tutorial／DoFile 能力分別復用 [entry/lifecycle 原稿](20261114-192949-chatgpt-web-roy1-MEF-entry-lifecycle-events.md) 與 [parser/executor 原稿](20261114-190624-chatgpt-web-roy1-MEF-parser-executor-storage.md)。本輪新 UI、stdlib 與 native 命名回呼證據見下列分題稿，沒有把舊清冊重列為新增進度。

## 2. 本輪最明確的新 caller：Expedition UI 觸發固定 Synopsis

本輪把原先已知的 `4C1E10 → 4A89C0` 向上追到兩個具體條件，並用原件 RTTI、constructor 和 vtable slot 核對物件身分。[完整入口、gate 與 bytes](MEF-trigger-callers-20261115/alternate-entry/report.md)

第一個是 **`CExpeditionPage` 初始化時 `[page+0x144]==0`**。`5A65A0` 在該條件下於 `5A66B3` 呼叫 `5A64B0`。本輪確認 constructor 初值為 0，但沒有將這個欄位猜成新帳號、劇情未完成或其他遊戲語意，也沒有假定 runtime 永遠維持初值。

第二個是 **`CExpeditionScene` 的 control 700 收到特定 UI event**。`5F4640` 在控制項查找及型別符合、綁定成功後，把 control 700 存到 `this+0xBC`；`5F46D0` 檢查輸入 `event+0x10==0x578`，且 sender ID 等於該 control 的 ID。符合時，Client 建立內部 event `0xF4248`，交 UI manager 的 current page。這條 event 入口不以 `page+0x144==0` 為 gate，不能與初始化入口的條件合併。

兩層間接派送已閉合：`750020 → current page v+0x15C`；當 receiver 是 `CExpeditionPage` 時，target 為 `595D20`，再以 `v+0x194 → 5A67D0` 處理該 event range。switch 對 `0xF4248` 選 `5A696E → 5A64B0`。`5A64B0` 還要求 `[D6A674]==0x45585044` 與非空 current scene，通過才進 `4C1E10`。

末端檔名及函式名有直接原件常數：

| Callsite | 原件資料 | 動作 |
|---|---|---|
| `4A8A31 / 4A8A36` | `C0687C = Event/TutorialMain.lua` | 將固定路徑交 `6F4A50` |
| `4A8A41 / 4A8A46` | `C06894 = Synopsis_EntryPoint` | 將固定名稱交 `6F4DD0` 呼叫 |

**這條線真正回答了「誰觸發 Synopsis 的 Lua」；尚未回答「誰觸發 MapList 的 `.mef`」。** `0xF4248` 是 Client 自己建構的 UI event，不能當成可由 Server 傳送的新 wire opcode。control 700 的可見標籤與 `0x578` 對應的操作名稱未讀到 layout 證據，本稿只使用已證的數值條件。

## 3. 其他候選追到實際用途後，為何沒有接成 MEF 入口

### 3.1 MapList root 的另一條名稱使用者其實讀 DamageSound

舊研究主要封閉 `FB74C0`、getter 與 accessor 的第一 consumer。本輪補查 collection root `FB7470` 本身，以及原 accessor 中保存於 ESI／EDI 的四個返回值。[root 別名完整分題](MEF-trigger-callers-20261115/native-root/report.md)

只針對 `FB7470` 的 little-endian DWORD，在 raw-backed `.text/.rdata/.data` 找到 155 個命中，全部位於 `.text`，落於 120 個函式。這是有限的直接 root 候選集合，並非所有計算式 alias 的窮盡證明。四個舊保存值與八個 `root → 4F6E80` 保存 EDI 的 caller，已補 caller 的後續覆寫／epilogue；冷初始化及通用 virtual sender 的全部傳遞性子圖仍另標界線。

最值得追的一條是 `55228C → 4F6F70`，它確實取得名稱、保存後在 `5522F0` 當參數傳入 `550580`。若只看「root 查到 filename、再傳給另一函式」，很容易誤認為所需 caller。原件 writer 卻明確以 **`Table/_DamageSound.xml`** 為來源，使用 `DAMAGESOUNDS / DSOUND / FILE`，把 `BaseFolder.PATH + DSOUND.FILE` 寫入 root `+0xA0`；key 為 `((ATTACK & 31)<<3)|(DEFENSE & 7)`。

reader 與 writer 使用同一容器，後續又閉合到 `80AF10 → 80E230` 建立的聲音物件。constructor 安裝 vtable `C51B50`，其 `+0x0C` 的原件 target 是 `80E4C0`；它將名稱交 `80AB00` 的聲音資源請求。這是依來源、欄位、物件型態和間接 target 排除，沒有只憑副檔名或 API 名稱猜用途。

### 3.2 Native 按名稱呼 Lua：本輪 caller 都提供固定名稱

本輪針對執行端的三種 wrapper 補 caller 與參數，避免只找檔案 loader 而漏掉「native 先呼 Lua 函式、該函式再載檔」的可能。[named-calls 分題](MEF-trigger-callers-20261115/named-calls/report.md)

| Wrapper／直接 caller 數 | 實際參數來源 | 結果 |
|---|---|---|
| `6F4DD0`：3 處 | 固定 `Synopsis_EntryPoint`、`Tutorial_EntryPoint`、`f_doCoTask`；NULL format | 呼叫已存在的 global function |
| `6F4F40`：2 處 | 固定 table `g_CharExplain`、method `GetExplain`、格式 `%d` 與一個整數 | 角色說明查詢；沒有 filename 參數 |
| `6F5A70`：1 處上游 `4AD0A0`；後者 11 處 caller | 固定 tick／cleanup／對話 callback 名稱，零個 Lua 引數 | 執行、清理或旗標回呼；沒有正常來包字串可替換 name 的已證資料流 |

四個 target 的限定 E9／absolute pointer 檢查沒有額外候選。這不涵蓋任意計算後位址或 runtime 改寫，不能稱全程式陰性。

三個需要確定 Lua 函式內容的回呼已接回 Event.stp 的 qbase 原件：`OnYesTriggered` 只寫 `g_yesTriggered=TRUE`；`OnEndTalk` 只寫 `g_scenePlaying=FALSE`；`CheckConfirmMessage` 讀 yes/no flags 並返回 0 或 1。完整 prototype 均無 CALL／TAILCALL；root 的 CLOSURE／SETGLOBAL binding 和每個 operand 均保存。`561F84 → 49B230` 返回 `FDF3C8` 的橋接亦已補核，確認該確認回呼使用同一正式 wrapper。[原始 Lua body 與 binding](MEF-trigger-callers-20261115/script-consumers/report.md)

### 3.3 真的拼接動態檔名的 scene helper，consumer 分別是相機與地形

選定已由前稿證明可經 SceneList `(15,2)` 選中的 `scenario_tuto1_1.seq`，不是任挑看似相關的字串。其 `PlayCameraNoWait("scenario_tuto1_1.cam",...)` 經 qbase proto 14 拼接 `Event/CameraWorks/`，呼 `CameraWorks.LoadRel`；本輪把 slot `FE1E30=54E990`、C closure、marshaller 和間接 call 接到 `796EE0`，後者按 `cameraworks/keyframe` 解析 XML。對應原件 `.cam` 也有這些元素。

同一 scene 的 `LoadMap("Square03D.fld")` 經 qbase proto 60 呼 `Q.LoadMap`；slot `FE2808=563C40` 與 marshaller 的間接 target 已核，後續 splitpath 取 basename 交既有 `7C1E00` 地形資源鏈。這兩條有變動 filename 的正向用途，不能拿來替代 MapList.TRIGGER → script loader。[完整資料流及選定原件](MEF-trigger-callers-20261115/script-consumers/report.md)

### 3.4 補出舊 parser caller 清冊之外的真實入口：`debug.debug`

`debug.debug → 701820` 確實註冊在正式 VM，且直接把 parser callback `6FE860` 交給 `6FE770`，**沒有經過 `6FE990`**。這修補了只看後者 direct-call 清冊的盲點。[stdlib／inline parser 分題](MEF-trigger-callers-20261115/alternate-entry/report.md)

但它的 producer 是 CRT stdin 的逐行讀取：`fgets(buffer,250,stream0)`，以 `strlen` 作 parser 長度，parse 成功後才用執行 thunk `6F5A50` 呼叫 closure。它首先需要已執行的 Lua 呼 `debug.debug()`；本輪沒有正常遊戲 UI／Server caller 將它啟動。250-byte 讀取與 NUL 長度規則，也不能當成任意二進位 `.mef` 傳輸機制。

`require → 70A830` 同樣有真實註冊與動態檔名能力：Lua argument 1 的 module 名稱經 `package.path` 模板替換，Lua searcher `70A510 → 6F6E60` 走 CRT 檔案路徑，再接既有 parser。預設模板為 `.lua`，`!` 展開成 executable directory；`LUA_PATH` 可影響設定。**設定存在不會自行呼叫 `require`**。本輪未找到正常原始腳本傳入 MEF module name 或把 path 改成 MEF 模板的具體 callsite，不能藉由 stdlib 能力跳過第一個 caller。

## 4. 這次補了什麼，還缺哪一段

本輪已從單純 loader 地址，往兩端補上 **觸發事件／caller 的輸入來源**及**名稱真正抵達的 consumer**。新增可確定的是：Synopsis 正常 UI 觸發條件、inline stdin parser、require 路徑來源、native 固定名稱執行 wrapper，以及音效／相機／地形三類容易混淆的名稱用途。

仍然缺少的是：**某個正常 Client 流程把可用的新 MEF 路徑或內容，實際交給 reader／parser，並在有效 state 上第一次執行。** 「有函式可呼」「有副檔名」「有傳檔機制」各自成立，不能把中間缺少的資料流補成已存在。

| 未解端點 | 下一步必須得到的證據 | 本輪已限定的範圍 |
|---|---|---|
| MapList TRIGGER 的另一個真實 consumer | 返回字元指標、複製出的路徑或 root `+0x50` 的實際 use-before-def，繼續到 reader 的參數 | 已知 `4DF510` 返回值未消費；155 個 direct root literals 及指定保存值的 caller 後續已記錄。若續查冷 helper，應針對仍帶值的 register，不重跑原清單 |
| 已載入 Lua 中的動態 loader／改寫 | 可達的 CALL／TAILCALL、callee 來源、實際 path/module 參數，以及 globals／table field 的寫入者 | 固定 qbase callback body 已閉合；任意 runtime alias 或全域重綁仍未作全 VM 證明 |
| 另一個未辨識 reader／parser 或外部模組 | 實際 callback 註冊、producer、buffer 長度與第一次執行 consumer | 本輪補到 debug 的 inline 反例，但它來源為 stdin；未將未取得的外部程式假定為 MEF 實作 |

S00 舊稿已解析 **Boot／Logic／Coroutine／ai**，也已檢查 Event 的 1,840 `.seq` 與 3 `.lua` 的限定 loader 內容；UI/Table 啟動及明列 DoFile 目標亦有前稿。這些是應復用的已做工作，**不再把本機工作目錄缺散檔寫成「Boot 還沒分析」的新阻塞**。本輪腳本支線起初重讀的 1,843 份 script 只作讀集揭露與版本核對，沒有充作新增全掃成果。[固定 S00 來源與復用界線](MEF-trigger-callers-20261115/script-consumers/source-manifest.json)

首次載入問題也不以「先取得官方 `.mef` 檔」為必要前置。真正需要的是可達且可重驗的 Client 入口與內容契約；之後才有依據設計相容內容。戰鬥事件、local actor 身分與長期 coroutine 的限制仍有效，但它們是首次載入之後的能力與整合問題，不混成同一個 caller 缺口。

## 5. 對 Server 開發的具體要求

以下是本輪對 Server 工作的界定，不代表已存在的 Server 功能全部未做。本輪沒有修改 Server；現有 Server 內容引擎、任務與戰鬥成果仍依既有治理記錄，不重列為完全未實作。

| 類別 | 需要開發、核對或接合的工作 |
|---|---|
| **Server 開發：既有事件／劇情** | 依已證 SceneList key、signed 16-bit 參數、有效 scene/controller 與 Q busy 狀態安排既有劇情。維護開始、結束、跳過、取消及重入的後端狀態；不連續預送多段 `0047` 造成 busy 分支改動目前播放旗標。這些條件沿用 entry/lifecycle 原稿。 |
| **Server 開發：檔案交付** | 若採前稿已證的預啟動 launcher 更新路徑，實作／核對 manifest、版本、壓縮與檔案身分、安裝位置、失敗復原及啟動順序。檔案成功寫入和遊戲資源可見、入口可選中、執行成功分開記錄。 |
| **Server 開發：遊戲規則與權威狀態** | 任務決策、群組／instance 狀態、持久化與合法流程可由相容 Server 設計，不要求還原官方 Server 內部演算法。只有已證的 Client 介面才能當 wire 契約使用。 |
| **Client 待逆向** | 新 MEF 的正向首次載入 caller 仍缺。不能透過 Server 猜一個 opcode、把 UI `0xF4248` 當封包，或只把 `.mef` 名稱塞進 map／scene 欄位補上此缺口。 |
| **跨功能待整合** | 將可見檔案、有效 selector、對應 parser/state、第一次執行、後續 tick 和取消接成同一條證據鏈。現有固定 Lua／sequence 能力可以作相容性基礎，不能直接宣稱它們已選中新增 MEF。 |
| **待遊玩驗證** | 實際入口條件、載入成功與結束／重入順序；進一步驗收 Client 取代指定 Server 操作時，需停掉該項 Server 操作後仍能完成。純 Server JSON 演算或畫面續播不等於 Client 已接手。 |

**目前可以推進已證的 Server 事件、劇情及交付需求；仍不能把「新增 `.mef` 自動執行」列為已取得完整 Client 契約的功能。** 這是入口能力的具體缺口，不是再尋找任意一個名稱帶 load 的函式就能結案。

## 6. 工作基準、證據與驗證

本輪沿用 `extra/roy1`，parent 為 `0a2503db089a4867cff5ef8bf6d7689333f12fd1`。main 查核基準固定為 `e66dadaa721671919cbbeb228ae3f26ad990c9e3`，沒有將它合併到工作分支。已閱讀使用者指定的 `02-PROJECT-SHARED-INSTRUCTIONS.md`，其本地來源 SHA-256 為 `624d808521354aa4fb00774839a25cac29e8fdbaa6029c66f39dc43bf7a1bb43`。只新增 `kr-extra-roy` 本輪原稿與補證，不新建 branch，不修改 owner、RR、派工或共用索引。

最新 main 對前三稿的整合有原件視窗重驗記錄，但沒有新增正向 MEF caller；本輪仍以自己的原件讀集界線作判斷，不把整合或 bytes 核對當功能驗收。來源 commit、path、blob、SHA 與原件身分集中於 [source-manifest.json](MEF-trigger-callers-20261115/source-manifest.json)。

| 第一手來源 | 本輪用途 |
|---|---|
| `02-Tartaros.bin`，12,472,320 bytes，SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` | 原生 caller、參數、保存值、registration、RTTI、vtable、parser 與 reader |
| `06-Event.stp`，11,241,597 bytes，SHA `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` | qbase 的指定 binding/prototype、選定 scene 原行與相機 XML |
| 前稿固定來源與 manifest | 復用 launcher 交付、TRIGGER 名稱儲存、原生 scene 選取、已知 loader 與資源路徑；不重新宣稱為新增分析 |

完整分題稿為 [native-root](MEF-trigger-callers-20261115/native-root/report.md)、[named-calls](MEF-trigger-callers-20261115/named-calls/report.md)、[script-consumers](MEF-trigger-callers-20261115/script-consumers/report.md)、[alternate-entry](MEF-trigger-callers-20261115/alternate-entry/report.md)。每份皆保留可證與未證範圍。原件擷取、候選與解碼資料一併保存；未提交原始 BIN/STP、完整解包內容或既有偽碼工作副本。

統一唯讀重驗方式與數量見 [證據包 README](MEF-trigger-callers-20261115/README.md)，實際輸出見 [verification-result.json](MEF-trigger-callers-20261115/verification-result.json)。核對包含原件身分、VA/raw 與 bytes、限定 caller/literal 集合、明確間接 target、Lua operands、選定資源以及固定 Git tree pins；偽碼只導航，沒有用偽碼簽名替代真實 ABI。

原件全程唯讀，沒有啟動／附加 Client、執行 Lua、修改資源或發送遊戲封包。**驗證通過只表示本包證據可重現；新的 MEF 觸發入口仍未證實。**
