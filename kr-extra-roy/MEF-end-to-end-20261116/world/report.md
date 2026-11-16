# 第九輪：Tutorial 狀態 writer 與固定世界物件的 observer／清理流程

## 1. 本輪結論與新增進度

**這一輪閉合了兩條原版已有、可由 Lua 消費的具體流程：鍵位選擇確認使 `Tutorial.GetTutorialState()` 改變，以及固定世界物件 `F000` 的建立、幾何可見性查詢、最後刪除。兩條流程均不等同普通敵人死亡、清組或戰鬥結果通知。**

第八輪 `observers/report.md` 對 `current controller+134` 只確認初始化零與 getter，初始化後 producer 尚未接上。本輪找到真正的 `FUI::CTutoMsgDummy` callback `6BFE90`，確認 UI 分支在 `6C00E4` 寫入 `+134=1`，並接回原版 `TutorialMain.lua` 的 `Tutorial_Part1` 等待迴圈。這是一個具有實際 producer 與 consumer 的教學進度旗標，而非泛稱的敵人狀態。[原件 `tuto_dummy_event_handler`、`tutorial_state_getter`；[Lua P5](lua-evidence.json)]

另一條新增流程為：原版 `Tutorial.InsertIsilia()` 建立 `CActor`、寫 `WORD actor+04=F000` 並登記到普通 world index；`Tutorial.IsIsiliaFound()` 查同一 key，讀位置、相機與投影條件；原版 `TutorialMain` 最後呼 `Tutorial.DeleteObject(240)`，該 native 確實進入 world erase。**這個 DeleteObject 是有效的世界物件移除入口，與前輪已確認為空函式的 Q 同名 API 分屬不同契約。**[原件 `insert_isilia`、`is_isilia_found`、`tutorial_delete_object`、`world_erase`；Lua P5／P8]

| 問題 | 本輪已證結果 | 保留界線 |
|---|---|---|
| `GetTutorialState` 誰寫一 | Dummy 的確認 callback，在兩種鍵位選擇分支匯合後寫 current controller `+134=1` | 不是 HP、死亡、group 或 result；沒有全域唯一 writer 證明 |
| 重新進入是否一定清零 | 新 `CTutorialController` constructor 清零；選定 mode 4 重用路徑改呼 common reset | 此 reset 函式本體沒有直接清 `+134`，不能宣稱所有重入路徑均重設，也不能宣稱完全沒有其他 reset |
| Lua 能否讀實際 world object | `IsIsiliaFound` 確實經 world tree 查 `F000`，並回 Lua number `0/1` | key 固定、沒有 RTTI／model 確認、沒有任意 EntityId 參數 |
| Lua 能否清除此物件 | `DeleteObject(240)` 組成 `F000`，呼真實 world erase | API 只取參數低 BYTE，不能傳任意完整 WORD key；沒有 Lua ACK |
| `CheckLeader` 讀什麼 | current controller `v+20` 取到的物件，其 `WORD +88 == 3` | 比的是 model 欄位低 WORD，不是 EntityId，也不是敵人完成狀態 |
| 普通 death／清組／result→Lua | 本輪沒有得到新接橋證據 | 這是 Client 待逆向接點；Server 的權威 death／group／result 規則另列開發需求，不以 Tutorial 旗標代替 |

本稿保留第八輪以及 world integration 前稿的 Q slot、lb 身分、`0007`、`004C/004E`、普通死亡視覺鏈結果，不將它們重列為新增成果。正式 `RR-0013` 在固定 main 為 **T13／P0／QUEUED**，問題是普通 CMonster（1036 基線）的移動／攻擊 producer；本輪沒有承接、修改或重做其 hostile control 主責。[固定來源與 RR 原文](source-manifest.json)

## 2. 原件、版本與驗證範圍

| 來源 | 固定身分 |
|---|---|
| 原始 BIN | `02-Tartaros.bin`；12,472,320 bytes；SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| Event carrier | `06-Event.stp`；11,241,597 bytes；SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| 同步後 main 參考 | `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc` |
| 第八輪前稿公開同 tree 版本 | `dda39a65ca483f2b4539c6feb74e05dfcdbf7ac8` |
| TutorialMain 原件 member | `Event/TutorialMain.lua`；stored offset `10647568`；length `5480`；decoded SHA-256 `662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809` |
| TutorialBase 原件 member | `Event/TutorialBase.lua`；stored offset `10645520`；length `1416`；decoded SHA-256 `26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744` |

原本機第八輪提交 `c0c2ce5aa025b86a85a402071d4c0c18fcdbc2d5` 保留作歷史，公開來源的全部 blob／SHA-256／bytes 與它一致。[發布對照](../publication-note.md) 說明為何 commit metadata 不同。

[native-windows.json](native-windows.json) 保存 84 個 selected code/data windows 的 VA、exclusive end、PE raw offset、完整 hex、SHA-256 與逐條反組譯；其中 55 個是 code windows。[native-windows.asm](native-windows.asm) 是可讀副本。[contracts.json](contracts.json) 保存 8 條實際註冊 binding、選定有型別的 vtable slots、call relations、欄位與限制；raw data window 保留的相鄰 metadata 不自動算成該物件方法槽。

[lua-evidence.json](lua-evidence.json) 重新從原件的 STPD index 定位並解碼兩個 member，只保存 TutorialBase P0、TutorialMain P0／P5／P8 四個 selected prototype 的指令與常數，沒有匯出完整遊戲 member。[source-manifest.json](source-manifest.json) 固定 44 個 Git source pins；bulk `.c` 僅導航，語意證據以原件指令為準。

本分題沒有變更 repo、原件、Client 或 Server，沒有執行 Client／Lua，也沒有運用 ReadMemory、Rebind、猜 pointer 或新 opcode 宣稱既有相容能力。Git 同步、整合及提交由主研究者處理。

## 3. 確實存在的 Lua binding 與回傳型別

所有下列 API 都由 `4A88E0` 的實際 registrar call、registrar 寫 target slot、push 名稱／closure，接到指定 native。正常 Tutorial receiver 為 `FC0F84`，binding receiver slot 為 `FE1804`；但 GetTutorialState、DeleteObject、IsIsiliaFound、CheckLeader 本體主要讀全域，不可將 binding receiver 當作其實際狀態來源。[`tutorial_register_root`、各 `register_*`、thunks]

| Lua 名稱 | Registrar | Slot → native | Closure | 本輪用途 |
|---|---:|---|---:|---|
| `PostUIMessage_TutoMsg` | `4AAEA0` | `FE183C → 4A9950` | `4AC3A0` | 送出選定教學 UI message |
| `SetControlStatus` | `4AB300` | `FE1858 → 4A9F90` | `4AC640` | skip flag 的原版清除 consumer |
| `GetControlStatus` | `4AB3A0` | `FE185C → 4A9FB0` | `4AC6A0` | 讀 Tutorial `B4+4×index` |
| `GetTutorialState` | `4AB440` | `FE1860 → 4A9FD0` | `4AC700` | 讀 current controller `+134` |
| `DeleteObject` | `4AB580` | `FE1868 → 4A9FE0` | `4AC7D0` | 合成 type-byte 為零的 world key 後移除 |
| `InsertIsilia` | `4AB620` | `FE186C → 4AA070` | `4AC830` | 建立固定 `F000` 的 CActor |
| `IsIsiliaFound` | `4AB6C0` | `FE1870 → 4AA240` | `4AC890` | 固定物件幾何判定 |
| `CheckLeader` | `4AB760` | `FE1874 → 4AA4A0` | `4AC900` | 領隊 model 低 WORD 判定 |

`GetTutorialState`、`IsIsiliaFound`、`CheckLeader` 的 thunks 都將 native EAX 經 FILD／FSTP 寫入 Lua `TValue tag=3`，並增加 stack top，因此是 **Lua number**。不能改寫成 `not getter()` 來等待，因為 Lua number `0` 不等於 boolean false。原版等待碼比較 runtime global `FALSE`；本包保留這個原字樣，沒有把本次未重新追定義的 global 直接改說成 boolean。[`tutorial_state_thunk`、`is_isilia_found_thunk`、`check_leader_thunk`；Lua P5]

InsertIsilia、DeleteObject 和 PostUI 的 thunk 沒有推入新的成功值。即使 closure 的 C return count 是 `1`，也不構成一個新建立、具有成功語意的 Lua ACK，更不是物件 ID 回傳。

## 4. `+134` 的真正 producer 與 consumer

### 4.1 原版腳本先顯示鍵位選擇，再等待此旗標

TutorialBase P0 PC23／24 將 `TUTORIAL_PROGRESS_NUMBER.TUTORIAL_CHANGEKEYTYPE` 設為 number `9`。TutorialMain root P0 PC12／13 將 child P5 綁成 `Tutorial_Part1`。P5 的 PC12..26 是以下已由 bytecode 核對的分析偽碼：

```lua
-- 分析用還原；本研究未執行。
Tutorial.PostUIMessage_TutoMsg(
    TUTORIAL_PROGRESS_NUMBER.TUTORIAL_CHANGEKEYTYPE, 0)
while Tutorial.GetTutorialState() == FALSE do
    yield()
end
-- 原件下一段顯示 TUTORIAL_KEYBOARD。
```

PostUI closure 呼 `4ACD90`，由 stack 尾端 `-2/-1` 讀兩個整數：number 或可轉數字的 string 經 FISTP，其他值走零。實際原版 `9,0` 不受尾端偏移或非數字轉換的歧義影響。native `4A9950` 將 event `F43FD` 與兩參數交 `58AC30`；後者配置 `FXUIEventI2`，把 event code 放 `+10`、參數放 `+14/+18`，入 UI queue。其 vtable `C47BCC` 的 type getter 回 `105BA`，正好對應後述接收端要求。[`tutorial_post_message*`、`tutorial_two_integer_marshaller`、`ui_event_i2_producer`、`FXUIEventI2_*`]

### 4.2 接收者確實是同一個 CTutoMsgDummy

`CTutorialPage` primary vptr `C1F5F4` 的 `v+108=5C3040` 是所選初始化入口，`v+198=5C3370` 是所選 event callback。`5C3040` 於 `5C30D7` 取得 `5B0300` 的 dummy descriptor，將 `page+228` 作輸出地址送 `5A9F40`。descriptor constructor `5B0460` 配置 `0x130`，呼 `6BFB40` 建立 Dummy，存 descriptor `+C`，resource ID 為 `285`。[`tutorial_page_initialize`、`tuto_dummy_cache`、`tuto_dummy_descriptor_ctor`]

這裡的同一物件身分有實際資料流支持：descriptor `v+10=5ADE20` 回傳 `+C`；`5A9F40 → 5A3840`；後者 `5A3888` 將該 UI object 存進輸出 pointer。接著 `5C3370` 收到 `F43FD`，取 `[page+228]` 並於 `5C3396` 呼 `6C0170`。不是只因名稱相似就把兩個 UI 類型拼在一起。[`ui_cache_object_getter`、`ui_bind_descriptor`、`ui_bind_output`、`tutorial_page_handler`]

`6BFB40` 寫 primary vptr `C3F194`；COL／type descriptor 的原始字串是 `.?AVCTutoMsgDummy@FUI@@`。`v+114=6BFCA0` 綁定 child controls，`v+15C=6BFE90` 是真正 callback 入口。bulk 的 `6C0053.c` 只是此 callback 內部的延續，不能當成另一個獨立註冊入口。[`tuto_dummy_ctor`、`FUI_CTutoMsgDummy_*`、`tuto_dummy_event_handler`]

| Dummy 欄位 | Child resource ID | Helper 的 runtime type 要求 | 本輪關係 |
|---|---:|---:|---|
| `+84` | `200` | `301` | skip／確認對話來源 |
| `+C4` | `2500` | `C47C` | message 9 顯示的群組 |
| `+C8` | `2510` | `800` | 以 child `+28 bit200` 選 mapping 分支 |
| `+CC` | `2520` | `800` | 另一選項 child |
| `+D0` | `2530` | `301` | 確認來源 ID 比對 |

`6C0170` 要求 event type `105BA`；所選 UI 更新分支接受第二參數 `0/4/6/10`，並對第一參數做 **signed `<10`** 檢查，沒有在該分支補足下界。原版 `9,0` 走有效分支，`6C035E` 比較 message 是否等於 `9`，據此顯示 `+C4`。這不是承諾負數或任意 message 參數都安全的完整 API validation。[`tuto_dummy_show_message`、三個 child helpers]

### 4.3 確認分支匯合後寫入 `current controller+134=1`

整個 `6BFE90..6C0163` callback 中，所選成功路徑要求：

1. event `+10 == 0x578`。
2. event `+8 == [dummy+D0]+20`。
3. 依 `[dummy+C8]+28` 的 `0x200` 位元，選兩組 mapping 之一。
4. 兩分支都隱藏 `dummy+C4`，然後讀取 current controller `FBA7A4`；非 null 才寫 `+134=1`。

| 分支／錨點 | 原件行為 |
|---|---|
| choice bit 設起 | `444960` owner 的 `+4` mapping 複製至 `+504`；另一 mapping owner 的 `+4` 複製至 `+24`；送 `F43CC` payload `0` |
| choice bit 未設 | 用前者 `+284` 與後者 `+14`；送 `F43CC` payload `1` |
| `6C00E4` | `C7 80 34 01 00 00 01 00 00 00`，直接寫 `[eax+134]=1` |
| 接續 `6C010B / 6C013C` | 再送 UI events `F43CD` 與 `F4403` |
| `4A9FD0` getter | `mov eax,[FBA7A4]`；`mov eax,[eax+134]`；`ret` |

因此，**在這條原版教學流程中，該旗標的具體語意是鍵位選擇確認已走過此 callback**。本輪沒有替 mapping 值 `0/1` 猜測鍵盤配置的畫面名稱；沒有以 UI event 直接推論已經取得普通戰鬥授權。[`tuto_dummy_event_handler`、`tutorial_state_getter`；Lua P5 PC18..27]

UI queue 的通用派送、實體滑鼠／鍵盤事件如何抵達這個已註冊 callback，以及當時是否具備有效視窗、controller 與資源，仍是執行環境前提。本包是原版 producer／型別／欄位／Lua consumer 的有界靜態閉合，不是已執行過整段教學的 runtime 驗收。

### 4.4 初始化、重用與 skip 不能混為同一旗標

`CTutorialController` constructor `548B90` 先在 `548B99` 將 `+134` 寫零，另將 `+B4..+130` 共 32 個 DWORD flags 清零。`4C4B10` 的新建分支配置 `0x138` 並呼此 constructor；已有 current controller 且 mode `FBA7AC==4` 時，則呼 `544F50` 並跳過新 constructor。`544F50` 本體清 common fields／三個控制槽，沒有直接存取 `EDI+134`。[`tutorial_ctor`、`tutorial_scene_init`、`controller_common_reset`]

這個結果只足以否定「看到 common reset，就能保證 `+134` 重設」的推論。入口前後還有其他呼叫，且未窮舉全部生命周期及全部可能 writer；本稿不宣稱重入必然保留 `1` 或永遠不可能清零。

callback 的另一分支是 event `F4428`、type `105BD`、result `6A7`；它在 `6BFEEE` 寫 **current controller `+B4=1`**。這是 index 0 的 control status，與 `+134` 不同。原版 TutorialMain P8 PC23..40 用 `GetControlStatus(0)` 讀取，成立後清該 flag、呼 `StopCutScene`、移除 child coroutine，然後走共同清理。[`tuto_dummy_event_handler`、`get_control_status`；Lua P8]

`SetControlStatus` 的 native 依 `B4+4×index` 寫入，沒有邊界檢查；算術上 index `32` 會落到 `+134`。**這是越界 alias 的證據，不是可支援的 reset API，也不能拿來包裝普通物件 observer。** 新內容須尊重這組旗標的已知 0..31 layout 與正確 controller context。

## 5. 固定 F000：建立、幾何觀察、刪除

### 5.1 InsertIsilia 建立的是 CActor，身分不回傳給 Lua

`4AA070` 用正常 Tutorial owner `+24` 的 map，以 signed key `3` 呼 `4AA530`，與 owner `+28` sentinel 比較。有效 row 的資料是 node 內聯資料，不是另一次 world EntityId lookup；位置來源經 node `+14` 傳入 setter。缺 row 時返回。[`insert_isilia`、`tutorial_checkpoint_lookup`]

成功路徑配置 `0x420`，呼 `4C7070`；完整 constructor 在 `4C70CB` 寫 primary vptr `C07554`，RTTI 為 `.?AVCActor@@`。這是 **CActor**，不能改稱 CCharacter、CMonster 或 Q 的 CEventActor。對這個確定型別，selected slots 與使用如下：[`actor_constructor`、`CActor_*`]

| Slot／欄位 | 值或 target | 已證用途 |
|---|---|---|
| `WORD +04` | `F000` | 在 `4AA116` 寫入 world identity |
| `v+3C` | `4C6FB0`，參數 `4` | 寫 model `+88/+8C` |
| `+90` | `0x10` | native 明確寫入；此稿不另命名未閉合語意 |
| `v+44` | `4C8B90` | 設定 row 提供的位置 |
| `v+4C` | `4C8F90` | 回傳 actor `+A0` 位置位址 |
| `v+14` | `4C8360` | world erase 的清理 slot |
| `v+00` | `4C7B60` | deleting destructor |

`4AA222` 以 `EAX=actor`、stack owner `FAB130` 呼 `4DFF30`。其 key 來自 `WORD actor+04`，以 zero-extended key 查 owner `+8` tree，只有 missing key 才插入。duplicate 分支不把新物件接管進同一 key，不能把 repeated InsertIsilia 當作安全 replacement。[`world_register`；前稿 identity 的 allocation／duplicate 邊界]

此路徑要求 valid Tutorial row、有效資源與配置成功。native 在 allocation-null 分支之後仍會 dereference actor，並非完整的失敗安全 API。thunk 不提供新 ID 或 success ACK；可知的 `F000` 來自固定 native 常數，而非執行回傳。

### 5.2 IsIsiliaFound 的完整選定主體只做固定 key 的幾何判定

`4AA240..4AA49A` 重新組成 WORD `F000`、zero-extend，呼 `82EF00` 查 `FAB138`，以 `FAB13C` 為 sentinel；missing node 或 null payload 回零。命中後呼 payload `v+4C`。**這個 getter 沒有檢查 RTTI 或 model，因此若同 key 指向別種物件，它仍會對該物件呼相同 virtual slot。** 只有在前述唯一插入／有效生命周期前提下，才可把這裡的 payload 對齊為剛建立的 CActor。[`is_isilia_found`、`actor_position_getter`]

對正常有限數值、有效相機／render context，成功條件依序為：

| 條件 | 精確原件位置／關係 |
|---|---|
| 可選六平面測試 | `FB76E4 != 0` 時，將物件三分量位置交 `838800`，plane 資料來自 `FB76B0`；任何 plane 的 `a×x+b×y+c×z+d > 0` 回零 |
| 三分量數值門檻 | current camera holder `[FB76E8]+4` 的 `v+24` 回一組三分量；與 actor 位置逐分量相減，將三分量差的平方和交 `8FF870`，再將 helper 結果與 float `C55770=150` 比較，要求嚴格 `<150` |
| 投影 | `434740` 回 camera-system owner `FB76A8`，`79A6B0` 以該 context 的 viewport／view／projection 路徑計算投影 x、y |
| 畫面邊界 | 投影 x 與 y 各嚴格 `>100`，且嚴格小於 render width／height 減 `100`；margin double 在 `C557E8` |
| 結果 | 全部成立在 `4AA46B` 回整數 `1`；其他選定失敗分支回 `0`，thunk 推為 Lua number |

上述三分量來源是相機持有物件之 `v+24`，不能直接改稱玩家位置。選定 getter 在 `4AA388..4AA3DC` 完成分量差與平方和，`4AA3E0` 呼 `8FF870`，`4AA3ED..4AA3F7` 對 helper 結果作門檻比較。本包沒有納入 `8FF870` 的完整數學例程證據，因此只承諾這條精確數值流程，不在本結論把 helper 結果升格為已由本包閉合的歐氏距離。width／height 減 `100` 的原生整數路徑帶 unsigned-to-float 修正；上表的通常畫面範圍解釋以正常尺寸及有限輸入為前提，不外推到溢位、NaN 或壞資源。[`is_isilia_found`、`six_plane_test`、`project_position`、`render_settings_getter`、三個 float windows]

完整 selected getter 沒有 HP、死亡 FSM、group key、剩餘敵人數或任務 result 讀取；因此它提供的是固定 key 的幾何 observer。missing key 的 `0` 也可能只是沒有建立、已被移除、配置／登記沒有成功或 context 不符，不能解釋為「敵人已死」。

### 5.3 原版 Lua 已消費這個正向結果

TutorialMain P5 PC107..118 先呼 `Tutorial.InsertIsilia()`，然後反覆比較 `Tutorial.IsIsiliaFound() == FALSE`，yield 後回到查詢。PC119 起進入下一段教學。這證明它不是只有註冊而沒有 consumer 的名稱。[Lua P5]

後續 P5 PC134..161 以 `Tutorial.CheckLeader()` 等待，必要時根據 `IsLeaderDialogOpened` 更換 UI 提示。`CheckLeader` 的 `4AA4A0` 讀 current controller，呼 `v+20`；null actor 回零，否則 `WORD actor+88==3` 才回一。對 Tutorial controller，該 slot 的 target 是既有 leader getter `5452B0`，其 slot 語意沿用前稿的 typed controller 證據。這不是 `EntityId==3`，也不是 `InsertIsilia` 的 model 4 或 checkpoint row3。[`check_leader`、`CTutorialController_vtable`；固定前稿 events]

### 5.4 DeleteObject 取低 BYTE 組 key，240 才會到 F000

DeleteObject closure `4AC7D0` 呼 `4ACB70`，從最後一個 Lua 值讀整數：number 可直接轉換，可轉數字的 string 先轉；其他型別／轉換失敗走 `0`。轉換使用 FISTP，本稿不在未證浮點控制字下承諾任意小數、NaN、overflow 的結果。正常內容應提供精確一個有效整數參數。[`tutorial_delete_thunk`、`tutorial_one_integer_marshaller`]

`4A9FE0` 實際做法是：取 `[ebp+8]` 的低 BYTE，把 local WORD 清零，將這個 BYTE 寫入 WORD 的高位元組，再 zero-extend。對已形成的整數參數，可寫成：

```cpp
// 分析偽碼；不是完整16-bit EntityId介面。
uint16_t key = uint16_t(uint8_t(argument)) << 8;
world_remove(/* owner */ 0xFAB130, key);
```

| 整數參數 | 組成 key | 含義 |
|---:|---:|---|
| `240`／`0xF0` | `F000` | 原版清 Isilia 使用值 |
| `61440`／`0xF000` | `0000` | 直接傳完整 key 會截成低 BYTE `0` |
| `1` | `0100` | 固定低 byte 為零的另一 key |
| `496`／`0x1F0` | `F000` | 高於 BYTE 的部分被丟棄 |

`4AA057` 呼 `4DFBC0`。命中時，此 world erase 先巡三個 controller `v+1C` getter，再呼 payload `v+14`，接 `v+00(1)` deleting destructor，清 payload、呼 `7B6890` 移除 node。CActor 的 deleting destructor 是 `4C7B60 → 4C7B90`，flag 1 路徑再進 heap free。controller 的那些呼叫並不是已證 detach／清參照操作；不得以這個 API 任意刪除受控 actor，再假定所有控制參照均已安全處理。[`world_erase`、`actor_delete_dtor`；固定前稿 identity]

原版 TutorialMain P8 PC71..74 **確實傳 `240.0` 且不接收結果**，接著 PC75／76 呼 `Tutorial_Part2`。在此之前，P8 啟動 P5 child coroutine；child 正常結束或 skip 分支移除它後，都到共同清理：關閉三個教學 checkpoint，再刪 `F000`。所以這個刪除 consumer 不需要假設玩家一定完整跑過幾何等待，missing key 時 world erase 可直接返回。[Lua P8；`world_erase`]

## 6. 可供內容開發使用的能力與精確未知

以下「可用」是原版 native／Lua 靜態契約在適當 context 下存在，並不宣告任意 ordinary MEF 已有相同入口或 scheduler。

| 能力 | 已證可用範圍 | 仍不能承諾 |
|---|---|---|
| UI 確認後續流程 | 原版 Tutorial UI message9、已註冊 Dummy callback、`+134` getter 及原版等待 consumer | 一般場景可借用此旗標；重入必清零；遠端 Server 權威結果 |
| 固定世界物件可見性 | 真實 world index `F000` 的位置、相機條件與 Lua number 結果 | 任意 entity query、RTTI 驗證、名稱去重、generation 分辨、敵人死亡 |
| 固定世界物件清理 | `DeleteObject(240)` 到 `F000`，實際 cleanup／destructor／node erase | 任意 16-bit key；所有受控 actor 可安全刪；Server despawn ACK |
| 領隊選擇判斷 | current controller leader model 低 WORD `3` | world 身分、敵對判斷、擊殺／清組 |
| 普通世界完成訊號 | 本輪仍未找到通往已註冊 Lua 的普通 death/group/result 鏈 | 不能以沒有找到宣告全 client 絕無此能力 |

此次已追到原版 Lua 的必要 consumer，未停在找到 `+134` writer 或 `F000` 字面常數。但沒有進行全 library 掃描，也沒有重做 RR-0013 的普通 hostile instance／target／skill producer。後續研究應針對真正尚缺的關聯，而不是重複測相同 Q slot、lb counter 或普通 hit gate。

## 7. Server 開發需求

本節是 Server 開發需求，不是既有 Client 相容能力或已實作的 wire protocol。普通 world death／group／result 如何抵達已註冊 Lua consumer，是另外的 **Client 待逆向接點**；Server 需實作的權威身分、死亡、群組與結果規則則列於下表，兩者不互相代替。沒有新增／猜測 opcode；是否能沿現有 Client handler 接到內容邏輯，仍需獨立證明。

| Server 需求 | 為何仍需要 | 可核驗的完成標準 |
|---|---|---|
| 以場景／instance／生命週期管理 entity 身分 | 固定 `F000` 與截 BYTE 的刪除 API 沒有 generation 或碰撞保護 | 重複建立、重用 key、場景切換都不把舊實體事件套到新實體；Client 顯示 ID 與 Server entity 關係可追溯 |
| 權威 death／despawn 狀態與原因 | 幾何不可見、missing key、actor cleanup 都不能作為擊殺判定 | HP 到死亡、正常 despawn、轉場清理、斷線移除有明確分類；事件可去重且不重複給擊殺收益 |
| group／wave 成員與完成條件 | 沒有從本輪 observer 得到普通群組剩餘數量 | spawn 的成功／失敗、死亡／despawn、重新加入均納入組別狀態；完成條件只觸發一次 |
| result／任務進度提交 | Tutorial UI flag 或 Lua 演出終了不能代表權威戰鬥完成 | Server 按權威條件提交結果，重送／重連可恢復；重複事件不重複結算 |
| 明確的內容通知或查詢契約 | 普通 death/group/result→已註冊 Lua 的必要接點仍未閉合 | 對既有 Client 逐項證明接收端、欄位、dispatch、Lua consumer；若需要 Client 擴充，明確列為新增能力，不能由 Server 需求直接推定現有 Client 可用 |
| 教學進度與可見性只作局部流程條件 | 相機位置、UI 選擇及 `+134` 生命周期屬 Client 狀態 | Server 不以這些值直接決定擊殺／獎勵；需跨場景保存的教學進度與本地 UI flag 分別管理 |

## 8. 驗證方式與結果解讀

```bash
python verify_evidence.py \
  --bin /path/to/02-Tartaros.bin \
  --event-stp /path/to/06-Event.stp \
  --repo /path/to/ttr_anal_multi \
  --out verification-result.json
```

Verifier 讀取固定本地 Git objects（停用 lazy fetch）、原始 PE／STPD 和本包資料，重新核 SHA、raw mapping、逐條反組譯與邊界、選定 direct-call targets、binding／RTTI、原版 Lua member mapping／指令及 consumer。除可選 derived result 檔外不寫入輸入；不啟動 Client、Lua 或網路 session。

[verification-result.json](verification-result.json) 的 `PASS` 表示上述 selected bytes／結構／契約驗證通過。它不等於 T01 全文 FULL-PASS、普通 MEF 能力已全部閉合、Server 已開發完成，或遊戲可玩驗收。正式進度是：**Tutorial 狀態 writer 與固定 world observer／清理鏈已新增閉合；普通 world death／group／result→Lua 仍是 Client 待逆向接點。Server 的權威 death／group／result 規則則另列開發需求。**
