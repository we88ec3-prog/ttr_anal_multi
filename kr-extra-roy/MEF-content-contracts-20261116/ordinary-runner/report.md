# 普通 Mission／Scenario 更新：checkpoint、UI 動態目標與背景 Lua runner 的界線

日期：2026-11-16（Asia/Taipei）。本稿承接 `extra/roy1` 的 `.mef` 分析，專門解析上一輪尚未定型的普通 field／page 更新目標。原件只讀；未執行 Client、Lua 或 Server，未修改遊戲資源。文中的「正常初始化」指已核 constructor／binding 路徑，不能涵蓋 runtime 改寫 vtable、替換資源或額外插入物件。

## 1. 本輪結論與必須更正的前稿用語

**上一輪列出的普通場景動態邊界，現在已能接到實際初始化與具體 native consumer：checkpoint 更新、訊息清單維護、底部狀態 UI、背包 UI，以及 Mission 隊伍名單 UI。這批證據沒有建立可由新增 Lua 內容登記、並在一般戰鬥操作持續有效時運行的背景 coroutine pump。** 有 native 更新來源，並不自動提供腳本 callback 契約；這個結論限於本稿列出的正常物件來源與所選 slot，不是全 Client 沒有其他 runner 的結論。〔F01–F15、U01–U12、B01–B17、I01–I15、A01–A05；[tables.json](tables.json)〕

先修正一個會影響後續設計的前稿分類。[R7 runner §7](../../MEF-world-integration-20261115/runner/report.md) 原文寫道：

> 普通field的base更新 `4ADB10`仍遍歷native actor list之v+20並呼field+24

`native actor list` 的稱呼過於寬泛，容易被誤解為一般世界角色／敵人的集合。**正確名稱應為：`4ADB10` 遍歷固定 `CCheckPointMgr @FB79F0` 的 checkpoint pointer vector `FB79F4..FB79F8`，對正常建立的 `CCheckPoint` 呼 `v+20`，最後再呼 field `v+24`。** 原件 `4ADB2E` 明寫 manager vptr `C0F868`；RTTI 是 `CCheckPointMgr`。已核 producer `4B2AF0` 配置 `0x108` bytes、呼 `543700`，後者寫 `CCheckPoint` vptr `C0F7FC`，然後把物件加入這個 vector。這條集合不能直接用來推論一般怪物、Server entity 或 Q event actor 的更新。〔F01、F06–F08；V/C/T_CCheckPointMgr、V/C/T_CCheckPoint〕

| 上輪邊界 | 本輪接上的正常物件與 target | 對新增 `.mef`／Lua 的實際意義 |
|---|---|---|
| `4ADB10` 元素 `v+20` | `CCheckPoint → 4CB000 → 4CA890`，另更新 `+F0` effect | 已知 checkpoint 的 native 位置／效果更新；不是一般世界 actor 枚舉接口。 |
| 普通 field `v+24` | Mission／Scenario 都是 `4C4890 → 4D7A20`，固定訊息 owner `FB11E8` | 字串指標清單與訊息 UI refresh；未建立新 Lua 工作入口。 |
| `59B1F0` 的 page `+164 → v+198` | Mission `CBottomMenuFrameField → 5D4780`；Scenario `CBottomMenuFrameScenario → 5D5180` | native 狀態列／技能等 UI 更新；可讀 current leader 的三組狀態數值，但沒有回傳到 Lua 的已證契約。 |
| page `+168` 選取 panel `v+1A8` | `CInventoryDialog` 的兩個正常子 panel：`CInventoryInsideWindow → 603430`、`CQuestInventoryInside → 5F5D10` | 前者維護背包物品 UI，後者 target 是 `ret`。 |
| Mission page `+22C → v+16C` | `CPartyAllianceListPanel → 6928B0` | 最多三個非自身 roster 項目的顯示／隱藏及 native UI 更新。 |

新 Lua 所需的背景排程契約，仍必須有具體的合法登記入口、owner、啟動條件、持續 tick、取消／重入與操作 gate 證據。不能把表中某個每次更新會被呼叫的 native 方法，直接視為可注入腳本工作的入口。上述方法內的巢狀 renderer、control、terrain、effect 動態目標，本稿明確保留範圍；沒有以 top-level 型別解析替代全子圖分析。

## 2. 原件與來源固定身分

| 項目 | 固定身分與用途 |
|---|---|
| 原件 | `02-Tartaros.bin`，12,472,320 bytes，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，PE32 i386，image base `0x400000` |
| 分析工作 parent | `88b22bcd750ea219bfc56580139396d0ee677644`，復用上一輪已發布的 runner／input-lifecycle 等證據 |
| 本輪 main 導航基線 | `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`，使用精確 commit，未以本地舊 `origin/main` 代替 |
| 導航資料 | 該 main 的 `kr-bulk-roy/<BIN SHA>/functions/*.c`；只協助定位與閱讀，關鍵資料流以 BIN 指令、vtable、RTTI 再核 |
| 復用界線 | 三個已閉合 T caller、普通 page factory／安裝與 Q 輸入雙 gate 沿用前稿；本稿不重作全域 Lua 名稱掃描或把歷史 claims 升格為 FULL-PASS |

[source-manifest.json](source-manifest.json) 將 89 份 Git 來源逐一 pin 住 `commit/path/blob/SHA-256/bytes`，區分導航與復用證據；[native-windows.json](native-windows.json) 保存原件 VA、raw offset、完整 bytes、hash 與指令；[native-windows.asm](native-windows.asm) 是對應可讀清單。每個 code window 都由指令邊界開始，尾端要求完整指令覆蓋，不把相鄰 thunk 或對齊 bytes 當成同一函式。

## 3. 普通 field：checkpoint 與訊息 owner

### 3.1 field 的更新 slot 與 manager 的真正來源

`CMissionField C0705C` 的 `v+18=423060`，`CScenarioField C073B4` 的 `v+18=4ADB10`；兩者的 `v+24=4C4890`。Mission 的 `423060` 先呼 `4ADB10`，再維護 `field+BD54/+BD58` 的 native 倒數；特定條件下走既有 4-byte app `0049` 發送路徑，之後清倒數旗標。這段 native 倒數不建立 coroutine 工作表，也不能只因它有時間值就視為新增腳本排程器。〔F01–F03；V_CMissionField、V_CScenarioField〕

`4ADB10` 的實際步驟如下：

1. 固定 manager 尚未建立時，`4ADB2E` 寫 `FB79F0=C0F868`，清 begin/end/capacity `FB79F4/FB79F8/FB79FC`，設 `FB7A04=1`。
2. 從 `FB79F4` 起，以 4-byte pointer 為單位遍歷至 `FB79F8`；`4ADB63` 取元素，`4ADB67` 讀元素 vtable `+20`，`4ADB6A` 呼叫。
3. `4ADB77..4ADB7E` 以原本 field receiver 呼自己的 `v+24`，最後回 0。

RTTI 的 manager／element 型別不同：manager 是 `CCheckPointMgr`；既有 producer `4B2AF0` 先清 manager，按 `(payload_length-2)/0x12` 的 row 數量配置、建構並追加 `CCheckPoint`。`543700` 的 constructor 寫入 `C0F7FC`，並初始化 `+F4/+F6/+F8/+FC/+100/+104/+105` 等 checkpoint 性質與原生 model/effect 狀態。歷史導航把這個 producer 放在 `0027` checkpoint 路由；**本輪新增的是 producer 到 vector／型別／tick 的原件證據，不是重驗完整 `0027` wire route 或 row 合法性**。〔F06–F07；MAIN 的 HISTORICAL-CLAIMS 只作導航，精確 pin 見 manifest〕

這裡可限定「由該 producer 正常建立的元素」；沒有追盡 runtime 所有 vector writer，也沒有推論新 Lua 能建立或替換這些 native 物件。

### 3.2 checkpoint 的 `v+20` 做什麼

`CCheckPoint C0F7FC` 的 `v+20=4CB000`。它先呼 `4CA890`，再在 `actor+F0` effect 非空時，以該 effect 呼 `550780`。`4CA890` 的所選內層 slot 已由同一具體 vtable 定型：

| slot／直接 target | 已核操作 | 範圍界線 |
|---|---|---|
| `v+38=4CAB30` | `+AC` dirty 時，向既有 terrain owner 取高度，再清 dirty | terrain 自身的 `v+0` concrete 實作沒有在本稿全部展開。 |
| `v+44=4CAB80` | 寫 `+A0/+A4` 位置；要求時設 dirty 並呼 `v+38` | 是 native 位置 writer，不是 Lua callback 登記接口。 |
| `v+54=4CABE0` | 以 native collision owner／候選位置處理後呼 `v+44` | collision 子系統不因本輪被宣稱全部閉合。 |
| `v+60=4CAD40` | 從 `+D0/+CC` 做移動速度運算 | 不是腳本時間工作表。 |
| `4CAD60` | `+D8/+DC` 位移平滑，接回已定型的 `v+54/+44` | 仍受原有 native 位置／方向狀態控制。 |
| effect `550780` | 維護 effect 的位置、附著對象及生命期；可接巢狀 effect／物件位置方法 | 保留 effect `+28 → v+14` 等動態邊界，不推成所有效果實作都沒有腳本能力。 |

完整 `4CA890` 還有 `+D4` 分支、`+E2&0x8000`、目標位置／剩餘計數及到點清理。這是 **checkpoint normal vtable 下的原生位移更新**。同輪 [observers](../observers/report.md) 另行解析 Q 的 `CEventActor` 樹與到點狀態，兩者不能因同用基底 actor 欄位而合併為同一集合或同一排程域。〔F08–F15；V_CCheckPoint〕

### 3.3 field `v+24` 的固定訊息 owner

兩種普通 field 的 `v+24` 均為 `4C4890`。它確保 owner 初始化後，`4C48E6` 明令 `ESI=FB11E8`，於 `4C48EB` 呼 `4D7A20`，正常返回值為 0。這裡沒有依 field 類型選出不同 Lua state。〔F03〕

`4D7A20` 遍歷 owner `+10C/+110` 的 UTF-16 字串指標 vector，計算各字串長度；**長度非零的分支移除該 pointer 並搬移尾端元素，長度為零的分支保留並前進**。不應僅依函式名稱把條件改述成「刪除空字串」或猜成時間到期。發生變更時 `4D7A97 → 4D6C90`，後者重建訊息資料並配置 `F4366` UI event，送往 `4072A0`。〔F04–F05〕

這條橋接接上先前已識別的 text-message logger／UI refresh。[前輪 events](../../MEF-entry-lifecycle-events-20261114/events.md) 的 N14–N18 仍是格式化與事件語義來源；本輪重核 `4D6C90`，沒有重驗 `4D4FA0` 的所有 formatter／所有 `F4366` consumer。`F4366` 不能因此被命名為敵人死亡、整組清空或可由 `.mef` 註冊的任務完成事件。

## 4. 普通 page 的共同初始化與底部 UI

### 4.1 先接 initializer，再接 tick

普通 page code 5/7 的 factory／currentpage 安裝承接 [R7 runner](../../MEF-world-integration-20261115/runner/report.md) 與既有 UI lifecycle。本輪原件將實際 slot 補齊：

| page | 具體 vtable | initializer `+108` | update `+184` | bottom descriptor getter `+1A4` |
|---|---|---|---|---|
| Mission 5 | `C1D1AC` | `5ACEA0 → 5AC3E0 → 598890` | `5AD6A0 → 59B1F0` | `5AD690` 是 `jmp 5AE1B0` |
| Scenario 7 | `C1D62C` | `5AFC30 → 5AC3E0 → 598890` | `5AFEB0 → 59B1F0` | `5B0160` 是 `jmp 456B00` |

共同 initializer 的原件 window `598A61..598ADE` 同時包含兩個關鍵 store 的來源：`59E0B0 → 5A9F40` 綁 `page+168`；接著以 page vtable `+1A4` 取得 descriptor，再由 `5A9F40` 綁 `page+164`。這兩個小 thunk 由原件直接保存，沒有因 bulk navigation 缺少單獨函式檔而把它們併進鄰接函式。`5A9F40/5A3840` 的 descriptor binding 與 `5ADE20` 回傳 descriptor `+C` window 也重新保存。〔U01–U12；V_CMissionFieldPage、V_CScenarioFieldPage〕

### 4.2 page `+164` 的型別與 receiver

| 初始化層 | Mission | Scenario |
|---|---|---|
| cached descriptor getter／singleton | `5AE1B0 / FE2DD0` | `456B00 / FC0C74` |
| descriptor constructor | `5AE990` | `456D70` |
| window 配置／resource | `0x384` bytes／`0x4B` | `0x384` bytes／`0x4B` |
| window vtable／RTTI | `C21B64 / CBottomMenuFrameField` | `C2208C / CBottomMenuFrameScenario` |
| window `+108` onload | `5D47B0` | `5D4FF0` |
| window `+380` 的 part 來源 | `5D4570 → 5D46D0 → 5D18A0` | `5D51A0 → 5D5300 → 5D3560` |
| part 配置／resource／RTTI | `0xD4 / 0x4E / CBottomMenuFieldPart` | `0xA4 / 0x4D / CBottomMenuScenarioPart` |
| window `v+198` | `5D4780` | `5D5180` |

`59B1F0` 在 `page+164` 非空時直接取其 `v+198`，這個呼叫處沒有另包 window visible-bit gate。兩種 target 都先呼共同 `5CEAB0`，再從 **bottom window 自己的 `+380`** 取得已綁定 part，分別呼 `5D1BF0/5D3700`。不能把這個 `+380` 套到 field 或 current actor。`5CEAB0` 接 native 狀態／按鈕／技能等 UI refresh helpers；本稿保存 dispatcher 與兩個完整狀態 consumer，未將每個巢狀 UI control 方法都升格為已解析。〔B01–B17；相應 vtable／RTTI records〕

### 4.3 正向發現：native current-leader 狀態觀測，但尚非 Lua observer

`5D1BF0` 和 `5D3700` 確實會取 current controller `[FBA7A4]`，呼其 `v+20` 得到當前 leader。Single／Formation／Tutorial 的 `v+20=5452B0` 型別證據沿用 [input-lifecycle tables](../../MEF-runtime-contracts-20261115/input-lifecycle/tables.json)，第 0 槽 getter／current leader 語義沿用 [R7 identity §3.1](../../MEF-world-integration-20261115/identity/report.md)；本輪保存其實際 UI caller 與消費資料流。當 controller／leader 存在，並滿足 `leader+158 != 0` 且 `[leader+158]+34 == 0`，UI 用以下三組原始欄位更新比例：

| 分子 | 分母 | 消費位置 |
|---|---|---|
| `leader+3C8` | `leader+3BC` | 對應 bar/control 的 `+D0`，接 `v+128`／`v+C8` 更新 |
| `leader+3CC` | `leader+3C0` | 第二個 bar/control |
| `leader+3D0` | `leader+3C4` | 第三個 bar/control |

分母小於 1 時比例置零；狀態 gate 不成立時走清空顯示分支，並有 native UI cache／dirty 判斷。比例是浮點計算與浮點欄位，不以反編譯器的整數指標表示推成整數除法。本稿只稱「三組原始狀態比例」，沒有憑位置猜 HP/MP/SP 的名稱。〔B08–B09〕

這個正向 consumer 對後續研究有用：**Client 具有讀 current leader 狀態並畫到 UI 的既有 native 路徑。** 但所選 receiver 是 current controller 的 leader，沒有任意 EntityId 查詢參數；已核返回端是 UI 更新，也沒有由這條路徑把狀態值入 Lua stack、觸發使用者 callback、比對事件群組全部死亡或登記 coroutine。其可用範圍不能直接擴張成 `.mef` 的一般世界狀態 API。

## 5. page `+168`：背包的兩個正常 selected panel

共同 initializer 的 `59E0B0` 取得 singleton descriptor `FE2C84`；constructor `5A1E90` 配置 `0x1B0` bytes，建立 `CInventoryDialog C290D4`，resource `0x65`。基底 `5F50C0` 將 dialog 的 panel vector `+104/+108/+10C` 清零，選取 index `+118` 初值為 0。這些是 **dialog 內欄位**，不能與 page 本身的同名 offset 混用。〔I01–I04；V_InventoryDescriptor、V_CInventoryDialog〕

其 `v+108=5FB0E0` 的 onload 先呼 concrete `v+1AC=87AF60`，後者返回 1；`5FB11E` 再加 1，對 vector resize 為 2。`5F7E40` 在擴大時把新增 pointer slots 清零。接著固定綁定：

| 正常 index | descriptor getter／constructor | window 來源 | `v+1A8` |
|---:|---|---|---|
| 0 | `5FE740 → 5FEA00`，resource `0x66` | 配置 `0x178`，`5FEF40` 寫 `C29314`，RTTI `CInventoryInsideWindow` | `603430` |
| 1 | `5FE820 → 5FEA90`，resource `0x67` | 配置 `0x110`，寫 `C02694`，RTTI `CQuestInventoryInside` | `5F5D10`，原件一個 `ret` |

`59B1F0` 在 page `+168` 非空、dialog `+28&0x100` 可見、選取 index 不等於 `0xFFFFFFFF` 時，從 dialog `+104[index]` 取 panel，再呼 panel `v+1A8`。這個 tick callsite 沒有額外的 vector-bound 或 selected-panel-null 檢查；本稿的正常兩個 panel 結論建立在已核 initializer 上，不是對任意 runtime index 安全性的保證。〔U01、I05–I10、I13–I15；相應 vtable/RTTI〕

`603430` 由自身 concrete `v+198=603810` 取得 **100** 個顯示 slot，遍歷 panel `+F4` 的物品 UI pointers，讀 item button `+250` 的 key、native item mapping／狀態，維護 `+2B4/+2B8` 等顯示計數與 cooldown／texture 更新。這裡的 `v+198` 是 **InventoryInsideWindow 的 slot-count getter**；它與上一節 bottom window 的 `v+198` 有完全不同 receiver／型別／語義。`603810` 的原件是 `mov eax,0x64; ret`。〔I11–I12〕

因此，這次把「所選 panel 的未知 vcall」縮小成兩個正常具體目標，並接到 native item UI 的 consumer。物品 UI 內仍有 render/control 方法及狀態 helper；沒有將其全部後繼都宣稱與 Lua 無關，也沒有從同一 slot number 推出任何可供 `.mef` 註冊的泛用 update interface。

## 6. Mission page `+22C`：最多三位非自身成員的 UI

Mission initializer `5ACEA0` 透過 `5ADC60 → 5A9F40` 綁 `page+22C`。getter 使用 singleton `FE2DB8`；descriptor constructor `5AE610` 配置 `0x98` bytes，寫 window vptr `C383F4`、resource `0x16`，RTTI 確認為 `CPartyAllianceListPanel`。其 `v+108=6926B0` 建立 `+8C/+90/+94` 三個 child panel，將各 child `+B0` mode 設為 0。〔U05、A01–A03；V/C/T_CPartyAllianceListPanel、AllianceDescriptor〕

在 `5AD6A0` 中，`5AD725` 取 page `+22C`，檢查 window `+28&0x100`，可見時呼 `v+16C=6928B0`。此處直接解參考，依賴正常 initializer 已完成；不能把它改述成無條件支援 null 的通用 hook。〔U02〕

`6928B0` 的選擇邏輯是讀固定 roster owner `[FB7258]` 的 `+28/+2C` vector，檢查 entry byte `+A`，把 entry 首 DWORD 與 `[F93930]` 比較以排除自身；最多取三項。`6929A9` 將 **entry 首 DWORD 的識別值** 載入 ESI，`6929B9` 把該值交給 `693FA0` 更新相應 child；不是把原始 entry pointer 當同一參數傳入。每個選到的 child 走 `v+94(1)`，剩餘 child 走 `v+94(0)`。〔A04〕

`693FA0` 依 child `+B0` mode 呼 native UI helper，將識別值寫到 child `+B4` 與內部 UI 欄位，再走 `68B260` 狀態 widget refresh。這是隊伍名單的 display consumer；未證明它產生 Lua 事件、辨識一般敵人群組或形成可由新腳本掛載的 scheduler。其 mode helpers 與 child control 虛擬方法保留為巢狀動態範圍。〔A05〕

## 7. 一般玩家操作與 Q：本輪能排除哪一種誤用

[既有 input-lifecycle](../../MEF-runtime-contracts-20261115/input-lifecycle/report.md) 已證兩層不同 owner：`Q.EnableInput`／既有 ordinary `00EB` handler 清 input mask 的 `0x2`，active Q tick 則在 coroutine pump 之前寫 current controller `+58=1`。只清第一層 mask 不會解除第二層；`M+2C` 的額外 gate 也是在 controller write 之後才擋住 `f_doCoTask`。本稿不重作該完整證據，也沒有從 UI 刷新持續存在推論 controller 控制 row 已恢復。

本輪新增的 concrete 普通 UI targets，沒有提供已證的「清 controller busy 同時讓新 qco 持續 tick」公開接口。這是說 **本輪尚未建立該契約**，不是宣稱完整 Q binding 表的每個 target、所有 Lua table runtime 改寫或全部 controller alias 都已排除。

同輪 [observers](../observers/report.md) 另有重要正向結果：Q `561520` 的 event-actor tree update loop 位於 `M+28/M+2C` 的 qco 分支之外。因此 **native actor 可續更新** 與 **Lua coroutine 可續 resume** 必須分開判斷。這條 Q actor loop 不屬於本文 `FB79F4..FB79F8` 的 checkpoint vector；也不能因停止 qco 後 native 移動仍可完成，就宣稱新 Lua 的 wait／callback 會持續被 pump。完整 CFG、Walk/Stop/Warp、到點清位與 `IsAllObjectsStopped` 契約以該分題為準。

對「現在可否把 `.mef` 串接起來」的含義，應依實際用途區分：既有有限 Q presentation／已閉合 T context 的載入與啟動可沿前稿的契約開發；普通戰鬥中持續跑新 Lua、同時保留一般玩家操作的 runner，不能因本輪補完 UI 型別就標為已完成。若新內容只需播放有限演出，沒有必要強行把它改成常駐背景工作；若確實需要背景任務，仍須下一條具體合法入口的證據。

## 8. Server 開發需求與研究剩餘範圍

| Server 開發／內容整合需求 | 本輪能提供的依據 | 尚不能代替的事情 |
|---|---|---|
| 以實際 scene／page／runner 支援矩陣安排內容生命週期 | ordinary UI、checkpoint 與既有 T/Q 的 owner 域已明確分開 | 不能只因 `.mef` 可被傳入，就推定任意時點都有 Lua executor 持續 tick。 |
| 需要 checkpoint 時使用既有 checkpoint 協定與型別契約 | 正常 producer、配置大小、constructor、manager vector、tick consumer 已接上 | 不把 checkpoint key 自動當世界 EntityId，也不把此 vector當敵人清單。完整封包／狀態仍是 Server 相容實作需求。 |
| 對一般戰鬥的敵人／群組／任務狀態採 Server 的明確權威狀態與回覆 | 本輪找到的是 current-leader HUD 與 roster UI consumer | HUD 欄位存在不等於 Lua 已有任意 actor observer；native顯示更新不等於任務完成回報。 |
| 有限 Q 收尾按實際 End／置鎖／解除次序實作 | input-lifecycle 已證 input mask 與 controller `+58` 不同，以及 normal quest0 End 可再置鎖 | 不以 `EnableInput`、對話框消失或一次 `003F` 單獨充當所有操作已恢復的驗收。 |
| 若產品需求是 ordinary 背景 Lua，先指定需要的合法 runner 契約 | 本輪縮小上輪列出的未定型邊界，沒有新增可登記的 coroutine pump | 不虛構 opcode、Callback、M+2C writer 或以 rebind／改 Client 取代原生功能。 |

以上 Server 發佈、狀態協調與相容 serializer 是 **Server 待開發需求**；官方 Server 的內部策略沒有被逆向出來，不應單獨列為 Client 逆向阻塞。

仍保留的具體研究範圍如下：

- 所選 native 更新內，尚未全部展開的 UI control／resource tree、terrain、collision、effect 動態方法。要研究其中是否有腳本能力，仍須明確 producer、receiver、vtable／callback 與實際 consumer，不能停在函式名字。
- runtime 修改 page/window 指標、checkpoint vector、Lua table 或 vtable 的來源。本文只涵蓋已核正常初始化，不保證所有執行狀態只有這些型別。
- 其他合法的 ordinary Lua 工作登記／pump 路徑，以及可解除 controller `+58` 又保留 qco tick 的公開接口。本文沒有發現並閉合這條鏈；保留為限定未證，不升格全程式陰性。
- native world actor 與 Q event actor 的身分對應、群組完成／死亡 observer，由同輪 [actors](../actors/report.md) 與 [observers](../observers/report.md) 分題處理；不以本文 UI 欄位代替它們。

本輪沒有找到新的 T caller，因此不另造一份未完成的 T 啟動／取消／重入流程。已發現的 native UI target，其啟動者、實際 receiver、tick 條件及 consumer 均在上表與原件中列出；頁面切換／隱藏不會因此被推論成任何 Lua 工作的建立或取消。

## 9. 唯讀重驗與交付界線

交付：`report.md`、`native-windows.json`、`native-windows.asm`、`tables.json`、`source-manifest.json`、`verify_evidence.py`、`verification-result.json`、`deliverables-manifest.json`。探索用 `.c`、builder 與工作資料留在 scratch；沒有提交新的完整原始遊戲 resource member。

```sh
python verify_evidence.py \
  --bin /workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin \
  --repo /workspace/scratch/b43c6175f310/ttr_anal_multi
```

已保存的 [verification-result.json](verification-result.json) 為 **PASS**：130 個 records、64 個 code windows、4,614 條指令、21,510 bytes、22 組 vtable／RTTI、42 條指定 direct edges、2 個 descriptor thunks、23 組指定原件 bytes，以及 89 份來源 pin／89 份本地 blob 內容。重驗器只讀原件與已存在 Git objects，不 fetch；指定 `objdump` 於 `end+15` 解碼並只取窗內指令，逐一核連續覆蓋、bytes、VA/raw、RTTI、slot、direct target 和固定來源 hash。

這個 PASS 表示有界靜態證據與來源可重現，**不表示已執行 Client、Lua、Server，不表示整體 `.mef` 玩法整合驗收，也不授予 T01 FULL-PASS 或全程式無其他 runner 的判定**。
