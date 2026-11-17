# 第十輪：公開 Lua 觀測面、飛行圖片與序章／書本完成狀態

## 1. 結論與本輪新增範圍

本輪從真正被初始化器呼叫的公開 Lua 註冊器出發，補閉合 **飛行圖片的建立／移除、序章的啟動／文字推進／關閉，以及書本的四階段演出完成**。這些結果能供 `.mef` 透過既有 Lua 演出流程使用；它們的 identity 與 completion 都屬於各自的演出 owner，仍不能拿來代替普通世界怪物、群組或戰鬥結果。

| 問題 | 本輪有界結論 | 狀態 |
|---|---|---|
| `Q.FlyingObject` 建立什麼、如何識別、何時刪除？ | 建立 RTTI `CFlyingImage`，取得共用飛行物件樹的 **DWORD 內部 handle**，只存 `M+40`；不 push 世界 ID。第七參數可令圖片持續停留。刪除先標記 `+14=0`，由共用 tick 清除 | 已閉合選定 API、型別、writer、reader 與 consumer |
| `Q.IsPrologRunning` 觀測什麼？ | 讀 `FC1B18` 的演出 active；開始、查表失敗、文字消費完、明確關閉均有原件 writer | 已閉合，包含 typed UI 路徑 |
| 有沒有真正可呼叫的關閉方法？ | **`Prolog.OnClose`** 是已註冊的 native action；其 owner 也是 `FC1B18`。不是讓 Lua 註冊敵人死亡 callback 的接口 | 新增正向公開 API |
| `Q.IsBookFlying` 何時回 0？ | 讀書本 owner `FC1BF8+74`；frame 驅動四種 `CBookState`，最後一階段的完成 predicate 成立才清零。中間另有 `FB72AC==0` gate | 已閉合選定演出狀態機，保留 gate 與資源限制 |
| 普通 actor／group 的 HP、死亡、清組、到達、結果 → Lua？ | 本輪已核候選仍未接出穩定 typed world identity 與普通結果 reader／callback 的完整連接 | **Client 待逆向** |
| HP、死亡、清組、勝敗、獎勵等權威規則由誰補？ | 仍須由 Server 實作對應權威狀態與生命週期；不能用圖片消失、序章 inactive 或書本播完當成戰鬥成功 | **Server 待開發** |

本輪的新證據與前輪基線分開保存。`Q` slot、`lb` local counter、CreateObjectEx 不回 ID、0007 hit skip、004C／004E ordinary gate、固定 Isilia，以及 Tutorial `current controller+134` UI writer 的既有結論不再作新發現重報。正式 `RR-0013` 在固定 main 的 owner 為 `T13`、`P0`、`QUEUED`；本包不處理其主責 ordinary hostile movement／attack producer，也沒有 claim／修改派工資料。[來源：`source-manifest.json` 中固定 R9 與 main Git 物件、`selected_request`。]

## 2. 證據、位址與驗證範圍

- BIN：`02-Tartaros.bin`，12,472,320 bytes，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- Event：`06-Event.stp`，11,241,597 bytes，SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。
- 本輪基線：R9 `ad9ea950216923b5e351a7501d38e006df57a4c6`；main `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。
- 本包有 **145 個原件窗口，其中 76 個 code 窗口**；每個保存 VA、raw offset、end-exclusive 範圍、完整 hex、SHA-256。code 另保存逐指令 ASM；jump table、RTTI、vtable 槽與常數均標為 data。
- `bindings.json` 保存 109 個有界 normal registration；`lua-evidence.json` 從原始 STPD 重新解析 qbase，選存 8 個 prototype。bulk `.c` 只作導航，每份固定 commit／blob／SHA，結論須回到 BIN 或原始 Lua bytes。

文件入口：[原件窗口](native-windows.json)、[ASM](native-windows.asm)、[公開 binding 清單](bindings.json)、[機讀契約](contracts.json)、[Lua 原件證據](lua-evidence.json)、[來源 pins](source-manifest.json)、[唯讀 verifier](verify_evidence.py)、[驗證結果](verification-result.json)。下文引用的窗口 ID 均可直接在原件窗口檔搜尋。

`PASS` 只代表原件 hash、PE 映射、窗口 bytes／反組譯邊界、Git pins、指定 binding／RTTI／分支與原始 Lua prototype 的靜態一致性。未啟動 Client、Lua 或 Server，沒有執行遊戲內測試，亦不是 T01 FULL-PASS。

## 3. 有邊界的公開面盤點

### 3.1 實際初始化根與 normal binding

| namespace | 實際初始化根 | normal 項數 | 覆蓋界線 |
|---|---:|---:|---|
| `lb` | `4A0950` | 14 | 逐個確認 `4A15B0` 起的 registrar、名稱、native slot、closure；沿用已證語意 |
| `Tutorial` | `4A88E0` | 31 | 逐個確認 `4AA680` 起的 registrar；包含 UI／control／固定 actor／scenario 介面 |
| `Q` | **`560600`** | 63 | 全部 normal registrar `565F20` 至 `5685E0`；`560700` 是此函式內的一個 call site，不是根函式入口 |
| `Prolog` | `55EE90 → 55FD70 → 55FE50` | 1 | `OnClose`；初始化使用共用 Lua wrapper `FDF3C8`，owner 綁定 `FC1B18` |

共 109 項。verifier 重新從 BIN 檢查每個根中的真實 `E8` call，以及 registrar `+18` 的 native slot assignment、`+58` 名稱、`+69` Lua closure。`Rebind` 不計入這個 normal 介面集合，本研究未用它或任何記憶體探測來改 owner。[窗口：`binding_lb_root`、`binding_tutorial_root`、`binding_q_root`、`binding_q_namespace`、`binding_prolog_namespace`、`prolog_constructor`；逐項證據：`bindings.json`。]

Expedition 沿用先前已證的 Tutorial／Synopsis shared VM 與 `Synopsis_EntryPoint` 啟動鏈；不因看見 Expedition 控制器就虛構一張同名獨立 Lua API 表。此處四個根的盤點也不涵蓋所有動態 Lua globals、所有 UI resource script 或全程式的其他 library，因此不能把這個有限集合寫成「整個 Client 沒有普通 observer」。[R7 `runner/report.md` 固定 pin。]

### 3.2 查詢／結果候選的具體分類

| 已註冊候選 | owner／實際讀取 | 本輪處置與普通 world 缺邊 |
|---|---|---|
| `lb.GetObjectCount` | `4A0A30`；前輪已證沒有形成有效世界物件總數的返回契約 | 沿用，不能拿來做死亡或清組計數 |
| `lb.GetTime` | `4A0B70 → [BD25A0]`；原始 import-by-name 是 `timeGetTime` | 時間來源；不是 actor／group getter |
| `Q.GetLeaderPosN` | 前輪已證 current controller 的 leader 位置分量 | 回數值位置，未回可列舉的 actor identity 或群組完成 |
| `Q.IsAllObjectsStopped` | 前輪已證 Q 自己的 actor slot tree 與停步 predicate | Q 演出停步；不能跨接 ordinary world group |
| `Q.IsCutSceneRunning` | normal receiver `FE2778`，native `489CF0` 讀 `M+28` | Q active 狀態 |
| `Tutorial.IsCutSceneRunning` | `4A97B0` 初始化同一 Q owner 後讀 `FB73E8=M+28` | 同一演出 owner；不是另一份戰鬥完成旗標 |
| `Q.IsPrologRunning`、`Q.IsBookFlying` | 本輪閉合的兩個獨立 singleton active | 詳見 §5、§6，均沒有世界 actor/group 參數 |
| `Tutorial.IsSynopsisSkipped` | `4A9320` 直接讀固定全域 `FBA7A0` | 保存 getter 原件；本包未重新閉合此格的完整 writer 語意，不能借 API 名稱宣稱 ordinary 結果 |
| `Tutorial.GetControlStatus` | 前輪已證 current controller 的 `+B4 + 4*index` | 必須保留已證 controller／合法用途；不能藉猜 index 當任意記憶體 getter |
| `Tutorial.GetTutorialState` | 前輪已證 current controller `+134` 的 Tutorial UI writer／reader | UI 進程旗標；不是普通敵人狀態 |
| `Tutorial.IsCharacterAvailable` | 前輪已證固定 roster entry，而非傳入 actor ID 的 lookup | 角色 roster 可用性；不是任意怪物 HP／存亡 |
| `Tutorial.IsIsiliaFound`、`CheckLeader` | R9 固定 Isilia／leader 模型與視認條件 | 限定對象；沒有一般 typed world observer 能力 |
| `Tutorial.IsLeaderDialogOpened` | R8 已證 leader dialog UI 條件 | UI 開啟狀態；不是怪物死亡或副本結果 |
| `Tutorial.IsScenarioEnded` | 前輪已證特定 scenario/controller／004C 路徑的邊界 | ordinary 接入仍未閉合，不能移用 Tutorial 結論 |
| `Q.FlyingObject`／`DelFlyingObject` | 共用飛行物件樹 + Q 自存的單一 handle | §4；image lifetime，不是 world actor identity |
| `Tutorial.RegisterSkipMessage`／`RegisterScalingObject`／`DestroyFlyingObjects` | 同輪 runner 已閉合 typed 圖像物件、Tutorial tracking 與共用 flying manager | 參數是圖片／尺寸，不是 Lua callable callback；刪除行為須看實際型別 |
| `Prolog.OnClose` | 已註冊的 no-argument close action | 可呼叫的正向 API，但不接受 callback，也不回 ordinary 結果 |

本輪 getter 短窗口見 `lb_time_import_thunk`、`time_import_iat`、`time_import_name`、`tutorial_skip_read`、`tutorial_cutscene_read`、`q_cutscene_read`、`q_cutscene_closure`；其餘沿用的結果均有 `source-manifest.json` 中 R7／R8／R9 固定報告 pins。Q camera attachment 的 slot consumer 由同輪 presentation 分題負責；本包不重做。

## 4. 飛行圖片：有 typed lifetime，沒有可供腳本使用的 world ID

### 4.1 binding、參數與正常 receiver

`Q.FlyingObject → 569950 → 56B2E0 → [FE281C]=564940`。converter 保存 normal receiver `[FE2778]`；它從 Lua 尾端讀六個 numeric 值，再讀第七個倒數位置的字串。原始 qbase P38 有七個 formal params，依原順序傳入 `Q.FlyingObject`，故正常參數契約如下。

| Lua 位置 | 轉換 | native 用途 |
|---:|---|---|
| 1 | 字串相容值；轉換失敗可成 null，沒有本包保證的有效路徑替代值 | texture path，複製到物件 `+48` 字串 |
| 2 | numeric／可解析 numeric string → x87 `FISTP` DWORD；不相容值走 0 | X 百分比，物件 `+68` |
| 3 | 同上 | Y 百分比，物件 `+6C` |
| 4 | 同上 | fade-in 計數，物件 `+1C`／`+28` |
| 5 | 同上 | hold 計數，物件 `+30`；受第七參數覆寫 |
| 6 | 同上 | fade-out 計數，物件 `+20`／`+2C` |
| 7 | 同上 | 非 0 時把 hold 改為 `-1` |

此處是 32-bit 整數轉換，不能擅自換成 Lua `floor` 或保證所有超界輸入的行為。位置 consumer `55FFF0` 用已設定的寬高計算 `xPercent*width/100`、`yPercent*height/100`；它是畫面圖像配置，沒有 world actor 的位置／EntityId lookup。[窗口：`flying_closure`、`seven_arg_converter`、`q_flying_create`、`flying_fade_constructor`、`flying_image_position`、`flying_resize`；原始 Lua：P38。]

### 4.2 建立、型別與內部 handle

`564940` 先呼 `564A60` 處理 Q 先前保存的圖片，再配置 `0x70` bytes。base constructor `553E90` 建立 path／fade 欄位，並設 `alive+14=1`、`protected+18=0`；之後 `5649AC` 寫 vptr **`C10748`**。該 vptr 的原始 COL／TypeDescriptor 閉合到 `CFlyingImage`，不是 `CActor`／`CMonster`。

initializer `v+4=560030` 載入 texture、存物件 `+44`，並把 fade state `+34` 設 1；`v+20=553C70` 設寬高並呼 `v+1C=55FFF0` 佈置位置。這些原生圖像 consumer 是區分其實際用途的證據，不依賴 API 名稱推測。[窗口：`q_flying_create`、`flying_fade_constructor`、`flying_image_load`、`flying_resize`、`flying_image_position`；`type_CFlyingImage_*`。]

接著它將 `(FB7398 的 DWORD, object*)` 插入 **`FB7358` 首棵 tree**，增加 `FB7398`，把剛使用的 key 寫到 **`M+40`**。`M=FB73C0` constructor 將這格初始化成 `FFFFFFFF`。這個 key 是飛行圖片 manager 的內部 key，和 Q actor slot、R9 固定 `F000` world entity、一般 world WORD identity 都是不同用途。

Lua closure 的 C `return 1` 是返回值數量，並未伴隨新的 handle／ID push；converter 也沒有把 native key轉成 Lua value。原始 P38 使用 `CALL` 的結果數 0，隨後只 `yield()` 一次。所以不能將直接呼叫後看到的既有 stack 值解釋成新 ID，也不能把 wrapper 返回解釋成圖片已播完。[窗口：`q_owner_constructor`、`q_flying_create`、`flying_closure`、`seven_arg_converter`；Lua P38 PC9–12。]

### 4.3 定時消失、明確刪除與共用清理

`CFlyingImage.v+14=553B60` 根據物件 `+34` 進行原生 tick 計數：state 1 接入 fade-in；state 2 遞減 fade-in counter 並調 alpha；state 3 遞減正的 hold counter，為 0 時進 state 4，**負值則留在 state 3**；state 4 做 fade-out，最後把 state 改 0；state 0 把 `alive+14` 清 0。這裡能證的是每次 native update 的計數，不能在沒有 scheduler 時基證據下把參數單位改說成毫秒。[窗口：`flying_fade_tick`、data `flying_fade_jump_table`；`constant_fade_alpha_max`。]

共用 tick 還有排程順序條件：runner F11 的 `553845..553872` 會依前項／自身 `+3C` 與 manager 狀態增加物件 `+24`；`CFadeObject` 在 state 1 先遞減這個等待 counter。因此有限 fade 並不保證所有圖片同時開始，也不能只用參數相加推算絕對結束時刻。明確刪除仍以 `alive+14` 作最後的移除判斷。[runner F11；本包 `flying_fade_tick`、`flying_fade_constructor`。]

`Q.DelFlyingObject → 5699B0 → 564A60` 不接收任意 caller ID。它以 `M+40` 查 `FB7358`，若找到非空 payload 就寫 `payload+14=0`，最後不論命中與否都把 `M+40` 設 `FFFFFFFF`。函式本身沒有 erase／destructor。真正共用 tick 由 runner 包 F11 證明：呼 `v+14` 後，以 `v+24` 的 **原值是否為 0** 決定 release／deleting destructor／erase；CFlyingImage 的 `v+24=80F010` 正是讀 `+14`。[本包：`q_flying_delete`、`delete_flying_closure`、`flying_alive_reader`、`flying_release_tick`、`flying_deleting_destructor`、`flying_base_destructor`；[同輪 runner](../runner/report.md) F11／F14。]

還有一個會影響 `.mef` 結束清理的跨 namespace 差異：CFlyingImage 的 `v+28=80F020` 讀 `+18`，constructor 將此格初始化為 0；SkipMessage／ScalingObject 的同槽卻固定回 1。runner F12 的 `553740` selective sweep 會清除 `v+28==0` 的物件，F13 `Tutorial.DestroyFlyingObjects` 在處理自身 tracking 後會呼叫該 sweep。因此，共用樹中符合此條件的 Q 圖片也會受清理，不能把該操作限定成「只刪 Tutorial tracking 內的圖」。這不會自動形成 Lua 完成值或 ordinary 死亡事件；後續 `Q.DelFlyingObject` 可以遇到已不存在的 handle 並走 miss 路徑。[本包：`flying_protection_reader`、`flying_fade_constructor`、`q_flying_delete`；runner F12／F13／F15。]

本鏈的實用能力是：用既有 API 顯示圖片、設計有限 fade 或持續 hold、再透過明確刪除／既有 cleanup 收尾。其限制是無 handle 回傳、無 group enumeration、無每張圖片的公開完成 query；資源／配置失敗及重入時機仍須在合法執行環境處理，沒有本輪 runtime 驗收。

## 5. 序章：公開 `Prolog.OnClose`、typed UI 與可輪詢的 active

### 5.1 公開方法確實存在，owner 不是 world actor

Prolog constructor `55EE90` 初始化 `FC1B18=0`，建立對話 queue 與內容查表結構，使用共用 Lua wrapper `FDF3C8` 呼 `55FD70` 建立 **`Prolog`** table，再呼 `55FE50` 註冊 **`OnClose`**。normal owner slot **`FE2768=&FC1B18`**，native slot **`FE276C=55F950`**，closure **`55FF10`**。其語意是直接關閉這個 singleton，不接收 Lua callable 或 actor ID。[窗口：`prolog_constructor`、`binding_prolog_namespace`、`binding_prolog_onclose`、`name_prolog_onclose`、`prolog_onclose_closure`。]

`Q.IsPrologRunning` 的 `564C50` 在需要時初始化 owner，然後讀 DWORD `FC1B18`；closure `569B30` 將 native 整數以 Lua number type 3 寫入 stack，前進 top `0x10`。這條有真正的值 push，和 §4 的圖片建立方法不同。[窗口：`q_prolog_read`、`prolog_getter_closure`。]

### 5.2 開始與失敗 writer

`Q.Prolog` 的 normal binding 接收一個 numeric 整數，`564BA0` 將它送到 `55F780`，並固定 owner 為 `FC1B18`。`55F780` 使用該整數查 owner `+40` 的 dialog table tree；這是對話內容 key，不是世界物件 ID。

owner 原先 inactive 時，`55F79C` 寫 1；原先 active 時先走 `55F5D0` 的前一份內容清理。查不到 key 或 payload 為空，會清理並在 `55F7CD` 寫 0。查到內容則保存 key 到 `+38`，清 exhaustion flag `+28`，將 stride `0x3C` 的對話內容複製到自己的 queue，呼 `55F470` 取第一筆，並將 fade phase `+2C` 設 1。[窗口：`q_prolog_start`、`prolog_start`、`prolog_pop_row`。]

因此 `IsPrologRunning()==0` 不能解釋成「內容成功完成」：初始化、查表失敗、主動關閉及正常消費完畢都可能到 0。它沒有額外錯誤碼、勝敗碼或普通 group 計數。

### 5.3 實際 native 推進與關閉路徑

實際 frame call 片段 `491EDC → 48A0B0` 取得 `FC1B18`，接著 `491EE1 → 55F9D0` 更新。`55F9D0` 在 active 時推進 fade phase `1→2→0`，之後推進目前文字顯示量。不能略過 `+2C==0` 條件而認為開始後任意一次輸入必定換頁。[窗口：`prolog_frame_caller`、`prolog_owner_get`、`prolog_update`、`presentation_interpolator`。]

本輪亦閉合實際 UI 型別：`5A3650` 配置 `0x8C`，設 vptr **`C3F5F4`**，原始 RTTI 為 `FUI::CPrologBookPanel`，cached UI ID 為 `0x11C`。只列下表有證方法槽，不把相鄰 COL／metadata 當方法。

| typed UI 路徑 | 原件條件與 consumer |
|---|---|
| `v+EC=6C0DA0` | key argument 為 `0xD` 時取得 `FC1B18`，呼 `55F960` |
| `v+140=6C0CD0` | event `+10==0x68` 時呼同一 `55F960`；另 `0x387` 分支只見 post `F4350`，本包未把它擴充成結果 callback |
| `v+D4=6C0CB0` | panel `+28` 的 bit 8 成立時，清理後 tail-jump `6C0E60`；後者在 singleton active 時呼 `55F8A0` |
| `v+15C=6C0E30` | event `+10==0x578` 且 UI target 相符時，呼本 panel 的 `v+D4` |

`55F960` 在 fade phase 0 時，先比較目前已顯示文字數；尚未顯示完則補到全部，已顯示完才取下一筆。`55F470` 消費自己的 queue，無下一筆時設 `owner+28=1`；`55F960` 見此值才呼 `55F8A0`。這是「對話 queue 消費完 → 關閉」的實際連接，不是名稱推論。[窗口：`prolog_panel_constructor`、`type_CPrologBookPanel_*`、`prolog_panel_key`、`prolog_panel_event`、`prolog_panel_event_close`、`prolog_panel_close_gate`、`prolog_panel_close`、`prolog_next`、`prolog_pop_row`。]

`Prolog.OnClose → 55F950` 也在 active 時直接到同一 `55F8A0`。該函式清理目前內容，`55F8D0` 清 active，並透過 `58AAD0` post **`F434F`**，另呼既有 cleanup helper。這些值是此處的 UI 事件；不能當成新網路 opcode、普通敵人死亡通知或 Server 結果承認。[窗口：`prolog_public_close`、`prolog_close`。]

### 5.4 原始 Lua consumer：`WaitForProlog`

原始 `Event/qbase.lua` P46 `DoProlog(arg)` 呼 `Q.Prolog(arg)` 並忽略返回值，然後呼 P12 `WaitForProlog`。P12 先 `yield()` 一次，接著反覆讀 `Q.IsPrologRunning()`：**只有值等於數字 1 才呼 `wait(100)` 並重查；不等於 1 就離開**。不是使用 Lua truthiness，也不是新註冊 callback。[Lua：P0 的 closure/global 配對，P12 PC0–11，P46 PC0–6。]

P8 的原始全域名 `PrologCloseCallback` 確實有 body：先印 `close!!`，再呼 `Prolog.OnClose()`，兩次呼叫均不收回傳值。但**本包未閉合某個 native runtime caller 會 dispatch 這個 Lua 全域名**；已證的 UI 關閉路徑直接進 native close helper。保留這個差別，避免用函式名稱或字串 xref 冒充事件 producer。[Lua：P0／P8；native typed UI 證據如上。]

## 6. 書本：flag writer／reader 與四個 typed state 的實際完成

### 6.1 啟動、型別與固定 owner

`Q.Book → 569D90 → 56A430 → 565140` 接受一個 numeric 整數；但 **`565140` 的完整 native body 沒有讀取或轉送這個 formal 參數**，而是選固定 owner **`B=FC1BF8`**，呼 `5826A0`。後者讀 `Table/Book.txt` 的兩組三分量配置，存到 B 的位置／角度欄位，再呼 `57F950`。不應將此 formal 整數解讀成 actor ID、group ID 或動態 world selector。[窗口：`book_closure`、`one_arg_converter`、`q_book_start`、`book_config_start`。]

constructor `57EF90` 建立四個 state，令每個 state `+4=B`，並關聯各自的模型；初始化 `B+74=FC1C6C=0`。原件 RTTI 與 slot 只證下列選定範圍：

| B 中的 state pointer | vptr／RTTI | enter | done `v+8` | tick `v+C` |
|---|---|---:|---:|---:|
| `B+44` | `C11294`／`Synopsis::CBookState1` | `580F90` | `580FB0` | `581090` |
| `B+48` | `C112B4`／`Synopsis::CBookState2` | `581190` | `581840` | `581300` |
| `B+4C` | `C112D4`／`Synopsis::CBookState3` | `580F90` | `580FB0` | `5818C0` |
| `B+50` | `C112F4`／`Synopsis::CBookState4` | `580F90` | `580FB0` | `5818C0` |

`57F950` 寫 `B+74=1`，準備演出資料，設 row index `B+70=0`、phase `B+6C=0`，將 current `B+54` 切到 **State1**。`57F930` 是共用 transition：舊 state `v+4` exit，替換 current，再呼新 state `v+0` enter。[窗口：`book_constructor`、`book_start`、`book_transition`、`type_CBookState1_*` 至 `type_CBookState4_*`。]

### 6.2 每幀 consumer 與 phase 結束

實際 frame 片段 `4927E8..492827` 初始化同一 owner，於 **`492822` 呼 `57FA40(B, delta)`**。`57FA40` 先看 `B+74`；active 時呼 current `v+C(delta)`，再呼 `v+8` done predicate。只有 predicate 非 0 才選 phase 分支：

| phase `B+6C` | predicate 完成後的行為 |
|---:|---|
| 0 / State1 | row index 歸 0，取第一 row，phase→1，切 State2 |
| 1 / State2 | 查下一 row；有下一筆則 phase→2／State3，否則 phase→3／State4 |
| 2 / State3 | row index 加 1，取該 row，phase→1，切回 State2 |
| 3 / State4 | **`57FBD4` 寫 `B+74=0`** |

`5809A0` 對 B 的 row vector 做 stride `0x34` 範圍檢查；這些是演出 row，並非世界物件列表或怪物群組。[窗口：`book_frame_caller`、`book_update`、data `book_phase_jump_table`、`book_row_lookup`。]

完成 predicate 也有原件依據。State1／3／4 的 shared updater `580FE0` 累加 `state+8 += delta`；`580FB0` 比較 **`state+8 × 30.0 > [[state+C]+4]+34`**。本包只將右邊稱模型欄位，不延伸成未證的伺服器時間或固定秒數。State1 的 tick 完整 body 以及 State3／4 的 tick 開頭，都實際呼該 updater。[窗口：`book_state_enter`、`book_state_time_update`、`book_state_time_done`、`book_state1_tick`、`book_state34_tick_prefix`、`constant_book_model_time_scale`。]

State2 另有行數推進：enter `581190` 清 `state+40` 與 `state+44`。tick 前段以 `delta × 400.0` 更新 `state+30` 的插值；一次完成才增加 `+40`，超過目前 row 中 stride `0x1C` 的 line vector 長度後 clamp 並設 **`+44=1`**。done `581840` 要求 **`state+44 != 0` 且 `FB72AC==0`**。本包保存這個真正 gate，沒有把它省略為「時間到了必定結束」，亦未擴張 `FB72AC` 整體 writer／reset 生命週期。[窗口：`book_state2_enter`、`book_state2_writer`、`book_state2_done`、`presentation_interpolator`、`constant_book_text_step_scale`、`constant_book_repeat_target768`。]

這條鏈的 closure 是有界的：已證 state flag、typed transition、所選 update／done 路徑與最後 clear；沒有證明無效資源、空資料或外部 gate 永不解除時仍可保證終止。也沒有將有限窗口當成全程式所有 `B+74` writer 的封閉集合。

### 6.3 原始 Lua consumer 與返回語意

`Q.IsBookFlying → 565270` 讀 **`FC1C6C=B+74`**；closure `569E50` 真正 push Lua number。原始 P53 `Book(arg)` 呼 `Q.Book(arg)`，隨後進 P13 `WaitForBook`。P13 和 P12 同構：先 yield 一次，**while getter==1，wait(100)，再查**。最後 phase clear 因而會使這個既有 Lua consumer 離開等待。[窗口：`q_book_read`、`book_getter_closure`；Lua P0／P13／P53。]

可把它用來等待這段演出停止 active，但它沒有勝敗 payload，也不能只靠 0 分辨「未開始」與「已完整播完」。是否需要額外管理取消／重入、以及該段演出之後如何回到既有任務流程，仍須遵守上層 runner 已證的啟停與清理契約。

## 7. 對 `.mef` 全流程的含意

已啟動且在合法 owner/context 的 `.mef` 腳本，可使用上述公開方法做出有序的演出步驟：圖片建立可先讓出一次；需持續圖片時要有清理；序章可使用既有 `DoProlog`，由原生對話內容／UI 推進收尾；書本可使用既有 `Book`，由 typed frame state machine 推進後讓 Lua 離開 wait。這是本輪取得的正向相容能力。

但不能把這些結果拼成未證的「普通敵人死亡→完成關卡」：

1. 三條鏈的 identity 分別是 flying-manager DWORD、prolog singleton/dialog key、book singleton/row index，沒有接回 ordinary world EntityId／group。
2. inactive 的來源可能包括初始化、內容查找失敗或明確關閉，沒有成功／失敗碼。
3. normal Lua action 的 `C return 1` 不能代替真正的 value push；qbase 的既有呼叫大多明確丟棄 action 的返回值。
4. `PrologCloseCallback` 的 Lua 定義與某 native dispatcher 真的呼它，是兩個不同證據問題。
5. 共用 flying cleanup 可跨 Tutorial tracking 影響 Q 圖片；所以「某張圖不見了」也不能當任務群組清空。

以上各點均可由 §4–§6 的 writer／reader／consumer 與原始 qbase 分支核對；沒有使用 Rebind、ReadMemory、猜 pointer、改資源或提出新 opcode 來補出不存在於證據中的能力。

## 8. 精確未決項與 Server 開發需求

### Client 待逆向

| 缺少的連接 | 具體驗收目標 |
|---|---|
| ordinary typed identity → 可呼叫 Lua 觀測接口 | 證明 normal 已註冊方法的參數、ID 位寬／型別與合法 owner，接到真正 world lookup；不能用 Q slot、圖片 handle 或固定 Isilia 替代 |
| HP／死亡／清組／到達 writer → Lua reader 或 callback | 必須同時指出 world writer、保存欄位／事件、Lua 值 push 或實際 named callback caller，以及普通模式的 consumer |
| group 身分與完成定義 | 查清 group membership、哪些移除／死亡原因會計入、是否只作用特定 controller，不能由泛稱 `GetObjectCount` 推斷 |
| ordinary result 啟動、終止與重入 | 分清 active／cancel／fail／success；證明該 consumer 在 ordinary world context 能啟動並持續得到更新 |
| 已選演出鏈剩餘邊界 | Book `FB72AC` 的完整生命週期、特定資源缺失時行為、`PrologCloseCallback` 的 native runtime caller；這些不影響本包已證的局部條件，但限制更強的結束保證 |

這份缺口表沒有宣稱「全程式不存在其他接口」。它記錄在已核 109 個 normal binding 與既有相關腳本／consumer 中，尚未取得哪幾條連接。RR-0013 的 hostile producer 主責仍維持原 owner。

### Server 待開發

Server 必須建立權威 HP／死亡、encounter group membership 與剩餘敵人計數，並定義移除、切圖、取消、重生與斷線是否計入。成功、失敗、獎勵與任務進度應由這份權威狀態決定，並處理重入、重複事件與收尾。

Server 對接 Client 時，只能採用已證的既有識別／事件契約；若 ordinary world result 到 Lua 的 Client 連接尚未閉合，就應把它留作 Client 待逆向依賴，不能把 Server 規則實作完成視為已經解決。演出完成可以作為編排條件，不能取代戰鬥權威判定。

## 9. 重現與交付

執行方式如下；verifier 只讀原件、固定本地 Git 物件與本包，`--out` 僅寫指定的衍生驗證結果。

```bash
python -B verify_evidence.py \
  --bin /path/to/02-Tartaros.bin \
  --event-stp /path/to/06-Event.stp \
  --repo /path/to/ttr_anal_multi \
  --out verification-result.json
```

本輪獨立 verifier 已通過。共用 consumer F11–F15 的五個窗口亦獨立回讀原始 BIN 核驗。確切檢查數與 peer 檔案 pins 以 `verification-result.json`／`source-manifest.json` 為準；其範圍包括 145 個 native 窗口、109 個有限 binding、7 個本輪 selected API、6 個 RTTI 型別與 qbase 的 8 個 selected prototype。書本／序章的 numeric equality 分支、圖片 wrapper 只 yield 一次、型別方法槽與兩個不同 active clear 都有固定契約檢查。

交付檔案均為研究證據與唯讀分析程式；本子任務沒有修改 repository／index／branch、Client／Server／Lua 原件或 RR owner。Git 整合與推送由主研究者在 `extra/roy1` 處理。
