# 教學、UI、小地圖與腳本輔助層：可用能力及正確入口

研究基準：2026-11-16，Asia/Taipei。沿用 `extra/roy1`，公開 parent `af97bbd29c892e031eef7a3bc3a98cb79f1be729`。原件為 KR BIN SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

## 1. 本章回答的能力問題

**腳本可以安排教學步驟、控制既有互動點、切入固定教學頁面、隱藏當前頁面的可見子視窗、讀取已知狀態、請求教學 scenario，以及重載既有小地圖元件。** 各動作有實際的 native consumer；它們分屬不同 owner，不能把名字相近的狀態混成一個通用事件接口。

本章新增核對 `lb.LoadMinimap` 的整數 ABI、BOUND→`.mmt` 讀取鏈；`Tutorial.HideUI` 的空排除集合與 typed current-page consumer；顯示設定／計時／診斷入口的實際效果。此外重新從原 Event.stp 解析 qbase，產出 **75 個頂層函式的完整導覽**，不再將 helper 名稱當成 75 種互相獨立的原生能力。教學控制、事件與 observer 已閉合部分直接引用固定前稿。

原件窗口、完整指令界線與 raw offset 在 [native-windows.json](native-windows.json)；可讀組譯在 [native-windows.asm](native-windows.asm)。本文方括號名稱均對應窗口 ID。來源包含 commit、path、Git blob、SHA-256、大小，見 [source-manifest.json](source-manifest.json)。bulk `.c` 只作導覽，最終以 BIN 指令為準。

## 2. 能安排哪些教學與互動流程

| 內容需求 | 已證入口與可達效果 | 使用條件／完成判斷 |
|---|---|---|
| 放置教學提示點 | `Tutorial.InsertTutorialCheckPoint` 查既有 TutCheckPointList row，建立 category 4 的 CCheckPoint | 位置、半徑與效果來自已有資料；此入口固定 category 4。 |
| 開關已登記互動點 | `Tutorial.SetCheckPointStatus(key,category,status)` → `0x544940`；與 S2C0048 使用同一 setter | 能改同一點互動可用狀態；出口等類型另有視覺分支。先要有該 key/category 的點。 |
| 限制／恢復指定輸入 mask | `Tutorial.SetKeymapEnabled(0/1)` | 用數字。1 清 mask `0x2`，0 設該 mask；不會順帶釋放其他 controller owner。 |
| 切換已支援鍵位配置 | `lb.ChangeKeymapType` 的 0／1 分支複製既有鍵位表 | 是鍵位配置，與是否允許輸入分開。 |
| 記錄／查詢教學控制旗標 | `Tutorial.SetControlStatus`／`GetControlStatus` | 正確 Tutorial controller 下使用已知 0..31 layout；native 沒有 index bounds check，越界 alias 不作功能。 |
| 等待玩家完成特定教學 UI 操作 | `GetTutorialState`、`CheckLeader`、`IsLeaderDialogOpened` | 分別是教學 state writer、領隊 model 判斷、記錄的 UI 分支旗標，各有自己的來源。 |
| 請求開始教學 scenario | `Tutorial.RequestStartScenario(key)` → C2S0040 | 發出意圖；不是本地直接完成 scenario。 |
| 收到教學 scenario 結束後續排下一步 | `Tutorial.IsScenarioEnded(key)` 讀 Tutorial owner 的 map，S2C004C 寫同 key 值 1 | 在對應 Tutorial receiver/context 可形成「請求→等待→繼續」。 |
| 顯示固定教學提示／雇用詢問 | `PostUIMessage_TutoMsg`／`PostUIMessage_EmployChar` | native 建固定 event 加整數 payload；由符合型別的當前頁面處理。 |

上述互動點、鍵位、控制旗標、UI state 與 scenario 的完整既有證據分別見：[互動點與原版使用例](../../../governance/client-variants/20261109-mef-town-services/scenario-controls.md)、[數值輸入 ABI](../../MEF-end-to-end-20261116/runner/report.md)、[教學 state 與固定角色流程](../../MEF-end-to-end-20261116/world/report.md)、[scenario 004C writer/reader](../../MEF-world-integration-20261115/events/report.md)、[固定 UI event consumer](../../MEF-control-flow-20261116/runner/report.md)。本章不把它們重算為新發現，也不要求這些教學能力先完成所有普通戰鬥機制才有價值。

### 2.1 RequestStartScenario 的精確意義

正常登記 `0x4AB8A0` 將 `FE187C` 指向 `0x4AA4D0`，closure `0x4AC9E0`。native 將 opcode WORD `0x0040` 和第一參數低 WORD 組成 **4-byte application request**。`FBA798==0` 才走 connection `v+0x10` 送出；沒有在此本地寫入完成旗標。[`registrar_Tutorial_RequestStartScenario`、`scenario_request`]

原版 TutorialMain 有 scenario 14 請求與同 key 輪詢的實例，已固定在前稿。內容作者可以重用這種編排方式，Server 則要接受合法情境請求、推進該教學流程並在適用 controller 發出已有相容結束事件。這是明確的 Server 開發需求，無須先建立「完全不靠 Server」的標準。

### 2.2 狀態數值不等於通用成功 ACK

`IsSynopsisSkipped` 正常 target `0x4A9320` 只讀 `FBA7A0`，closure 將值推成 Lua number。Tutorial entry `0x4A89C0` 先重設這個值，再載入 TutorialMain／呼 entry；R10 已證 native Stop 只有指定 quest/scene/參數分支會寫 skip。因而它能供特定簡介流程選支線，不是「任意內容已取消」的旗標。[`synopsis_getter`、`synopsis_reset_entry`；[R10 Stop 分支](../../MEF-control-flow-20261116/presentation/report.md)]

`IsLeaderDialogOpened` 的既有完整核對顯示它讀 `Tutorial owner+38=FC0FBC`。Tutorial page 的 F42DD 分支以 0／1 記錄切換；其中 show helper 可因 page gate 直接返回，caller 仍會寫 1。因此這個值可描述**所記錄的教學 UI 操作分支**，不能升格為嚴格的當幀可見性保證。[既有 observer 原件](../../MEF-content-contracts-20261116/observers/report.md)

## 3. 隱藏 UI 與切頁的真實作用

### 3.1 `Tutorial.HideUI()` 隱藏當前頁面的可見子視窗

正常 binding：`4AAF40 → FE1840=4A99D0 → closure 4AC400`。`4A99D0` 建一個空的 key 排除集合，交給 `58B450`；此處讀當前 `F95BD4` page，null 則返回，非 null 要先通過 virtual `+4` 回 `55000` 的 cast 檢查。[`registrar_Tutorial_HideUI`、`hide_ui_closure`、`hide_ui`、`hide_ui_cast`]

`5968F0` 遍歷 page 的 child list。對不在排除集合且 `child+28` 的 `0x100` 可見位元成立者，先將 `child+20` 的 key 存入 page `+A0` 記錄，再呼該 child 的 virtual `+94(0)`。因本入口傳的是空集合，這次沒有指定豁免 key。[`hide_ui_consumer`]

可採用的能力是「暫時隱藏適用當前頁面上原本可見的視窗」，而不是自由指定頁面、建立新對話框或改商店種類。它也沒有刪除世界 NPC、卸載場景或返回完成 token。恢復操作要由同一 UI owner 的已證流程配對，不能用任意 `SetUIPage` 代替。

### 3.2 `Tutorial.SetUIPage()` 固定選 page 15

native `4A9AE0` 不讀使用者提供的 page number：若 current page `0xFAADEC` 不是 `0xF`，就把 pending page `0xFAADF0` 設為 `0xF`；同頁則呼 `58A9A0`。原件完整指令見 `tutorial_page` 窗口。

`58A9A0` 另配置固定 event `F4355` 並交 UI queue。因此本入口是「選擇既有 Tutorial 頁面／同頁時送固定 F4355 刷新事件」，不表示 wrapper 同步完成整頁重建；既有 R10 已核這個 page 的型別與路由，不能將附加 Lua 參數當任意 page selector。[`tutorial_page`、`same_page_refresh`；[R10 頁面路由](../../MEF-control-flow-20261116/runner/report.md)]

## 4. `lb.LoadMinimap(mapKey)` 能重載什麼

### 4.1 從 Lua 參數到原生元件

`4A1D30` 正常登記 `FE17AC=4A1400`、closure `4A2320`。closure 經 `4A23E0` 讀 Lua 最後一格：number 或可轉換數字字串進 x87 `FISTP` 轉整數，其他 tag／失敗轉換成 0。這不是 texture path 參數，亦不把 Lua boolean 當數字 1。[`registrar_lb_LoadMinimap`、`minimap_lua`、`lb_integer_converter`]

native `4A1400` 將這個整數放 ECX，EDI 指向 `FDF3C4` holder，呼 `56CD10`。初始化 guard 只會在必要時把 holder 設 0／登記 exit callback，**沒有在本入口建立 minimap component**；後段直接使用該 pointer，所以前提是既有 UI 元件已安裝。[`minimap_native`、`minimap_dispatch`]

### 4.2 參數決定 BOUND 對應 descriptor

`56CD10` 先依 current field 的 mode byte 選 `townMinimap.mmm` 或 `fieldMinimap.mmm` marker 定義，再把傳入 map key 存成 lookup key。`56CE05` 的 receiver 明確為 `FB74D0`，呼 `4F7DF0`；這個索引在既有原件研究中對應 `_MapList.BOUND`，不是 `FB74C0` 的 TRIGGER。

非空結果組成 `Map/Minimap/<BOUND>.mmt`；空結果改用空字串。`56CE96→56E790` 載 descriptor，`56CE9D→56E6E0` 更新 `Map/Minimap/minimapSymbols.eif`。接著依現有 UI 資料更新元件欄位。`56E790` 的已收窗口有 resource 存在／XML load 分支，以及 `Minimap`、`WorldSize`、`TextureFile` 讀取；texture 送 `56E330`。[`minimap_dispatch`、`minimap_descriptor_start`、`minimap_symbols`、path data 窗口；[既有小地圖因果分析](../../../governance/client-variants/20261107-square-minimap/REPORT.md)]

`4F7DF0` 的缺 key 路徑會插入空字串，故不能把「getter 返回了 string object」視為資源存在。普通 native update 另在 `492650..492656` 取得同一 minimap pointer 並呼 `56F130`，與此載入入口不同。[`minimap_bound_getter`、`minimap_tick_caller`]

### 4.3 內容能採用的精確承諾

能做的是：以有來源的 map key，令既有 minimap 元件重新選取對應 BOUND descriptor、texture 和 marker 定義。需要的資料為該 map row、對應 `.mmt`、其 texture、symbols 與已初始化 UI context；它不會憑空補缺 descriptor，也不把 3D 場景換圖或 world checkpoint 建立包含在內。

沒有新成功值推回 Lua；外層 closure 的 `EAX=1` 是回傳個數，不能當成載入成功、合法 map key 或新建元件 ACK。本次不新增 `.mmt`、不換廣場、不部署資源；既有缺件與對齊需求留給內容發布／Server 地圖選擇開發與後續驗收。

## 5. 計時、顯示設定與診斷：原生有入口，但語義需按本體使用

| 名稱 | 實際 native 行為 | 內容規範應採用的界線 |
|---|---|---|
| `lb.GetTime()` | `4A0B70` 跳 `BD25A0`，原 import name 為 `WINMM.timeGetTime`；closure 用 signed DWORD `FILD` 寫 Lua number | 是本地系統計時來源，不是 Server 權威時鐘；32-bit 原值以 signed 解讀，不承諾永遠非負／單調。 |
| `lb.SetDebugLevel(n)` | `4A0AA0` 寫 `D63D78`，signed n≥9 時存 9 | 診斷控制；不能當玩法狀態或完成回報。這個本體沒有下限 clamp。 |
| `lb.PrintCurrSceneID()` | 正常 target `5F5D10` 僅 `RET` | 此 build 為空操作，不提供可用 scene ID query。 |
| `lb.ChangeResolution(a,b,c)` | closure→`4A2850` 三數值 ABI；`4A1330→6DEDF0` 存 render owner 的 +338/+33C/+340，前兩值亦到 +17C/+180；接現有 rendering mode 分支 | 確認有顯示重設入口。本文只列實際參數傳遞與保存，不補猜所有合法尺寸／第三值 enum；不是任務進度或換圖接口。 |

原件見 `gettime_thunk/gettime_import_jump/gettime_iat/gettime_import_name`、`debug_level`、`print_scene_stub/print_scene_closure`、`resolution_closure/resolution_converter/resolution_native/resolution_parameters`。GetTime 的 import 身分與原件數值轉換已直接核對，本文不以第三方平台文件替代本 build 的 ABI。

## 6. qbase 的 75 個函式如何使用

本次重新讀原 `Event.stp` 的 `Event/qbase.lua`，decoded SHA-256 `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3`，76 prototypes／906 instruction words。由 root prototype 的相鄰 `CLOSURE → SETGLOBAL`，完整產生 [helper-index.json](helper-index.json)。每列含名稱、prototype、固定參數數量、root PC、code SHA、直接讀寫的 globals 與 return-only 判斷；它是導覽資料，沒有發布完整 Lua member 或全部 bytecode。

| 類別 | 代表 helper | 應如何理解 |
|---|---|---|
| 發起動作 | WalkObject、AniObject、PlaySound、FadeOut、Dialogue | 有些呼 native 後只 yield 一次；不等於動作完成。完整 ABI／副作用由相應能力章解釋。 |
| 明確等待 | WaitForCamera、WaitForProlog、WaitForBook、WaitForObjectsStop、WaitForScene | 用各自的 getter／global 判斷，不能交換不同 owner 的 completion 語義。 |
| 參數加工 | ConvSpeedStepToMultiplier、PlayCameraNoWait、NumberPanel、CreateObject | helper 可能補值、換算、分流，和直接呼同名 Q API 不一定相同。 |
| 排程 | Register、f_registerCoroutine、f_doCoTask、yield | 正式 coroutine 的登記與執行；prepass Register 的效果不同。 |
| 僅讓出執行權 | StartLoading、EndLoading | 本體只引用 yield，沒有資源載入工作或完成 ACK。 |
| 本版本空函式 | OnNextTalk、Phase2、Phase3、Phase4、RevPhase4、RevPhase2 | prototype 只有 RETURN；不能把名稱當成已實作階段。 |
| 演出前後處理 | Phase1、RevPhase3、RevPhase1 | 是多個 UI／相機／輸入／顯示效果的合成流程；清理順序和 owner 必須沿用已證契約。 |

完整 75 列清單可由 JSON 精確檢查；[總能力手冊](../capability-catalog.md)按使用需求串到原生入口。`referenced_globals` 僅表示直接 GETGLOBAL 操作數，不能據此宣稱 native callback 已存在、動態呼叫已窮盡或每一條 branch 都會執行。

## 7. 開發交接與核對範圍

**Server 待開發**：為教學與互動內容保存有來源的 key/category/map/scene 對照；提供合法 scenario 開始與對應完成事件；按內容版本發布 minimap／UI／教學依賴；將意圖、原生顯示狀態與權威任務／資產提交分開。不能把 `RequestStartScenario` 的送出、observer 的 0／1 或 setter 表面回值當成完成提交。

**跨功能待整合**：安排正確 controller、current page、已初始化 minimap／render owner，配對輸入與 UI 的取得／恢復；將 helper 與 native API 的參數規格分別存入內容工具。已存在的腳本能力可以按功能逐項使用，不以是否完全替代普通戰鬥 Server 評分。

**待遊玩驗證**：合法教學內容的單一路徑，逐步看到提示、互動點切換、玩家操作、scenario 請求／結束、對應 UI／小地圖效果和恢復。原件靜態一致性不代替這些畫面與雙端結果驗收。

`verify_evidence.py` 對 BIN identity、44 個原件窗口／35 個 code windows、9 個選定正常 bindings、固定 Git sources 與全部 75 個 qbase export descriptor 重驗。它還獨立對照原件解析和既有 JSON，且明確驗證六個 return-only helper 與兩個 yield-only loading helper。PASS 不代表所有 API 全域語意、T01 FULL-PASS、RR ACCEPTED 或已實作 Server。
