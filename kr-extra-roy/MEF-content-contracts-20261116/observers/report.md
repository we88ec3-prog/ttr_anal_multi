# 可供新 MEF 使用的 observer：Q 走位完成、Tutorial 狀態與 UI 旗標

## 1. 本輪答案與研究終點

**新內容可以使用原版的「Q 腳本角色移動請求已停止」契約，並交由 Lua 決定後續演出。這條資料流已從註冊、角色欄位 writer、原生 update、getter 一直追到原版 qbase consumer。它不能表示普通戰鬥的敵人死亡、清組或任務完成。**

`Q.IsAllObjectsStopped()` 的實際問題是：Q manager 索引中的每個 actor，其 `WORD +E2` 的 `0x8000` 位元是否都已清除。空索引直接回傳數字 `1`。原版 `WaitForObjectsStop()` 先 `yield()`，之後只在 getter 等於數字 `0` 時繼續等待。這是一條可實作的演出控制流程，沒有把「停止」名稱推定成死亡或剩餘數量。[原件 `q_all_stopped_native`、`q_all_stopped_lua`；[Lua 原件 P24](lua-evidence.json)]

| 本輪候選 | 新增的確定結果 | 能否作普通戰鬥完成通知 |
|---|---|---|
| `Q.IsAllObjectsStopped` | 同一 Q owner、slot 索引、CEventActor 型別、移動位元 writer／clearer、native tick、Lua 數值回傳及 qbase 等待 consumer 已對齊 | 不能；它可供走位演出排序，並沒有讀取普通世界的敵人數、group 或死亡狀態 |
| `Tutorial.IsLeaderDialogOpened` | 正常 Tutorial binding 讀 owner `+38=FC0FBC`；實際 writer 是 Tutorial page 的 UI 分支，已核零／一寫入與 Lua 數字回傳 | 不能；旗標還可能與實際視窗可見性不同步 |
| `Tutorial.GetTutorialState` | binding、數字回傳、真正讀取的 `current controller+134`、Tutorial controller 初始化為零已確認 | 尚無可用的普通完成事件契約；初始化之後的有效 producer 未閉合，也不是讀 Tutorial binding owner 的旗標 |

本輪的有界終點是：把選中的 getter 接到實際欄位、writer、consumer，確認其正向用途，或保留精確未解邊界。**Q 走位 observer 與 Tutorial UI flag 的選定鏈已完成靜態閉合；普通戰鬥 death/group/result→Lua 的整體研究仍未完成。** 沒有重新把 004C、004E 或原有 000C 視覺死亡鏈列為新成果，也沒有宣告所有 Lua API 都不可能提供普通完成事件。

## 2. 原件、版本與可重驗資料

| 項目 | 固定身分 |
|---|---|
| 作業分支／work parent | `extra/roy1`／`88b22bcd750ea219bfc56580139396d0ee677644` |
| 本輪 main 參考 | `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`；由主研究者核對，沒有使用過期的本機 `origin/main` |
| 原始 BIN | `02-Tartaros.bin`；12,472,320 bytes；SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| Event carrier | `06-Event.stp`；11,241,597 bytes；SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| 原版 qbase | `Event/qbase.lua`；carrier stored offset `10618896`、length `11836`、block ID `7378`、first block `10370`；解碼 SHA-256 `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3` |

[native-windows.json](native-windows.json) 保存每個所選 code/data window 的 VA、exclusive end、PE raw offset、hex、SHA-256 及指令；[native-windows.asm](native-windows.asm) 是可讀版本。[bindings.json](bindings.json) 保存四個 Q selected bindings、Tutorial 的完整 31 個 regular registrations、selected vtable/RTTI 與浮點常數。[lua-evidence.json](lua-evidence.json) 只保存四個原件 prototype 及其 root binding，沒有上傳新解出的完整遊戲 member。

[source-manifest.json](source-manifest.json) 將 Git 導航及前稿固定至 commit、path、blob、SHA-256。`564880` 與 `4A9FD0` 的證明直接來自 BIN，沒有將相鄰 `.c` 誤作這兩個函式的反編譯來源。反編譯僅供導航；前稿只依 [read-set.json](read-set.json) 中的有限範圍復用。此包不啟動 Client、不執行 Lua、不修改原件、Server 或 Client。

本文所稱「已確認」是這個限定版本的靜態證據結果；[verification-result.json](verification-result.json) 的 `PASS` 是 bytes、結構與 selected-contract checks 通過，**不是 T01 全文 FULL-PASS、Server 已實作或可玩驗收**。

## 3. Q getter 的註冊、receiver 與真正回傳型別

### 3.1 名字確實接到這個 native getter

| 連接點 | 原件行為 |
|---|---|
| `560700 → 567780` | Q 初始化實際呼叫此 registrar |
| `567798` | `C7 05 18 28 FE 00 80 48 56 00`，寫 `FE2818=564880` |
| `5677D8` | 推入字串 `D6A47C`：`IsAllObjectsStopped` |
| `5677E9` | 推入 closure `5698E0` |
| `569917 / 56991D` | ECX 取 `[FE2778]`，間接呼 `[FE2818]` |
| `569929..569939` | 將 native EAX 整數經 FILD／FSTP 放成 Lua `TValue tag=3` 的 number，增加 stack top，回一個結果 |

這不是只搜尋到同名字串。正常啟動時 Q receiver 是 manager `M=FB73C0`，`FE2778` 保存該 receiver；前稿已核 `Rebind` 可改寫 receiver，因此本契約限於正常、有正確 layout 的 Q manager。沒有把任意指標 Rebind 當作世界 actor／Tutorial 接橋方法。[原件 `q_register_IsAllObjectsStopped`、`q_call_register_IsAllObjectsStopped`、`q_all_stopped_lua`；[前輪 owner／binding](../../MEF-runtime-contracts-20261115/input-lifecycle/report.md)]

### 3.2 Getter 只巡覽 Q actor 索引

`564880..5648F6` 的完整函式等價於以下**分析偽碼**：

```cpp
int IsAllObjectsStopped(QManager* M) {
    auto sentinel = *(Node**)(M + 0x1C);
    for (auto node = sentinel->first; node != sentinel; node = next(node)) {
        auto actor = *(Actor**)(node + 0x10);
        if ((*(uint16_t*)(actor + 0xE2) & 0x8000) != 0)
            return 0;
    }
    return 1;
}
```

`564898` 是 `66 85 B0 E2 00 00 00`，測試的確是 actor 的 word 欄位，而不是 node 的旗標。`56489F` 有位元時跳到 `5648F2` 回零；空表與巡覽結束走 `5648EB` 回一。其餘主體是樹迭代，沒有 world entity lookup、普通 actor 的 FSM、HP、group key 或剩餘數量讀取。這裡也沒有把空 actor 指標視為合法元素的保護分支。[原件 `q_all_stopped_native`]

Q tree 位於 `M+18`，sentinel pointer 在 `M+1C`，node `+10` 是 actor pointer。建立端的 full DWORD slot key、slot 低 BYTE 與 typeByte 合成的 actor `+04` WORD、配置 `0x438` 的 CEventActor，以及刪除／隱藏界線，由同輪 [actors/report.md](../actors/report.md) 保存。**本 getter 讀的是同一 Q 索引，不是以同數值去查普通戰鬥的世界 EntityId。**

## 4. 誰把「仍在移動」寫進去

### 4.1 原生 `Q.WalkObject` 有六個實際參數

註冊鏈是 `566E20 → FE27DC=563330`，closure `569340` 於 `56937A` 呼 `56AC30`。Marshaller 由 Lua stack **最後六個值** `-6..-1` 取參數，讀正常 Q receiver `FE2778`，在 `56AE41` 呼 native target。number 直接轉換；可轉數字的 string 先轉換；其他型別／無法轉換的值走零。整數欄位使用 FISTP，本文不在沒有證明浮點控制字的情況下承諾所有邊界值的 rounding policy。[原件 `q_register_WalkObject`、`q_walk_lua`、`q_walk_marshaller`]

| Native 位置 | 本文參數名 | 已核型別／用途 |
|---:|---|---|
| 1 | `slot` | 整數，對 `M+18` 以完整 key 查找 |
| 2 | `x` | float，目標位置第一分量 |
| 3 | `y` | float，目標位置第二分量 |
| 4 | `useAnimation` | 整數；非零才更換 motion 並更新 multiplier |
| 5 | `motionId` | 整數；有 animation gate 時送到 actor `v+68` |
| 6 | `speedMultiplier` | float；有 animation gate 時寫 actor `+434` |

因此內容應提供**精確六個參數**，不能把可選第七參數隨意附加在 direct `Q.WalkObject` 後面；它會令尾端相對索引整組偏移。`useAnimation` 應傳 numeric `0/1` 等已知數值；Lua boolean 不是這個 marshaller 接受的 number tag，會走零路徑。Marshaller 沒有推入一個可當作操作 ACK 的新 Lua 值，不能以 closure 的 C return count 推論走位成功。

`563330` 對 missing slot 或空 actor pointer 直接返回，不建立 actor。找到 actor 後，以 `56337E → 4D0CE0` 設定移動目標。**即使 `useAnimation=0`，移動請求仍會建立；只有 motion 與 `+434` 的更新被略過，速度倍率沿用舊值。** [原件 `q_walk_native`]

### 4.2 `4D0CE0` 寫的是 actor 移動請求

| Writer 錨點 | 欄位與意義 |
|---|---|
| `4D0CEB / 4D0CF4` | 寫 target pair 到 actor `+424/+428` |
| `4D0D8A` | 將 `+430` 設成 float `1,000,000,000`，供後續距離平方比較 |
| `4D0D5F / 4D0D7B` | local DWORD 低 word 歸零，高 word OR `8000` |
| `4D0DB6` | 將該 DWORD 寫到 actor `+E0`；所以 `WORD +E2` 的 `8000` 必被設起 |
| `4D0DBF / 4D0DC5` | 寫 direction byte 到 `+E4`，呼 actor `v+58` |

這個函式沒有完整初始化 local DWORD 高 word 的其他位元；證據只支持低 word 歸零、`E2&8000` 設起，**不支持把整個 E0 硬寫成唯一常數 `80000000` 來描述原版行為**。本輪把這項細節保留在 bytes 與契約，避免反編譯暫存變數掩蓋未初始化的其他 bits。[原件 `event_actor_walk_request`]

## 5. 誰更新位置、何時清除這個位元

### 5.1 實際 CEventActor 型別與虛擬方法

Q 建立的 CEventActor 在 `4D0BB8` 寫 primary vptr `C0C824`；COL 指向 type descriptor 的原字串 `.?AVCEventActor@@`。以下 targets 都直接從同一張原生表讀取，沒有用別種 actor 的相同 offset 代替。[原件 `event_actor_constructor`、`CEventActor_vtable`、`CEventActor_COL`、`CEventActor_type`]

| Slot | Target | 與本 observer 的關係 |
|---|---:|---|
| `v+20` | `4D0F80` | 先 `4C8580` common update，再呼 `4D0DD0` movement tick |
| `v+44` | `4C8B90` | 位置 setter，經 `4CAB80` 寫 `+A0/+A4` |
| `v+54` | `4D0F10` | 把本步移動量加到位置，接同一 `v+44` |
| `v+60` | `4D0F50` | 計算速度：`float(D0) × 約0.01 × CC × 434` |
| `v+68` | `4C8DA0` | 本鏈送 motion 的入口；沒有把動畫播完當作位元清除條件 |

基底初始化路徑也已補證：`4D0BAA → 4C7070`，後者 `4C7098/9B/9D` 將相同 allocation 傳給 `4CA730`。這個基本初始化函式在 `4CA7AD` 寫 `+D4=0`、`4CA7E7` 寫 `+E0=0`（包含 E2），並清 `+E4`。這是可見的初始化步驟，沒有宣稱之後所有 constructor／state callee 都不會再改動欄位。CEventActor 本層另設 `D0=100`、`CC=24`、`434=1`。[原件 `actor_base_constructor_prefix`、`basic_object_constructor`、`event_actor_constructor`、三個相關 float records]

### 5.2 Native actor update 與 Lua qco gate 不同

完整 `561520..561678` 顯示兩種工作依序存在：

1. 先看 `M+28`；非零時才寫 current controller `+58=1`，再看 `M+2C` 是否為零，決定是否呼 Lua 名稱 `f_doCoTask`。
2. 無論 `M+28=0`，或 `M+2C` 使 qco 暫停，分支都到 `5615E0`；這裡巡覽 `M+1C` sentinel 對應的 Q tree，於 `5615F0/5/F8` 對每個 node `+10` actor 呼 `v+20`。

因此，**只要外層 frame 確實呼到 Q manager update，已存在的 Q actor 仍可有 native 移動更新；這不代表普通戰鬥已獲得一個不受限制的背景 Lua scheduler。** actor 的位元可以先變成 clear，而等待中的 Lua coroutine 要等自己的 resume gate 成立後才讀到結果。外層 frame 的既有 caller `491ED7 → 561520` 與 Q entry／pause／終止生命週期按前稿復用；ordinary field、CCheckPointMgr 及 UI 的其他 update 不與這個 Q tree 混成同一容器。[原件 `q_actor_update_full`、`str_f_doCoTask`、`event_actor_tick`；[前稿 lifecycle](../../MEF-entry-lifecycle-events-20261114/lifecycle.md)；[ordinary runner](../ordinary-runner/report.md)]

### 5.3 Movement tick 的兩個 gate 與終止條件

`4D0DD0` 首先檢查 `actor+D4==0`，再檢查 `E2&8000`。第一個 gate 不滿足時直接返回，**沒有順手清掉 pending bit**。進入後取 `v+60` 速度，乘原 QWORD `C55B30=0.03333333507180214`，用 `E4` 索引 `FB8020/FB8024` 的兩分量方向表求 step。本常數不等於已證明每秒恰好三十次的 runtime 時序。[原件 `event_actor_walk_tick`、`event_actor_speed`、`float_tick_step`]

對普通有限數值，可將關鍵條件寫成：`d²` 為目前位置至目標的距離平方，`previous_d²=actor+430`，`step²` 為本步向量長度平方。

| 分支 | 原件選取 | 結果 |
|---|---|---|
| `d² ≤ previous_d²` 且 `3×step² ≤ d²` | `4D0E8E` 不跳、`4D0EB2` 不跳 | 記錄新的 d² 至 `+430`，呼 `v+54(step)` 繼續移動 |
| 距離變大，或 `3×step² > d²` | `4D0E8E → 4D0ED5`，或 `4D0EB2 → 4D0ED7` | 呼 `v+44(target,1)` 設目標位置、`v+68(1,1.0)`，再 `4D0EF9` 以 `7FFF` AND `WORD +E2` |

`v+54 → 4D0F10` 和終止分支共用 `v+44=4C8B90 → 4CAB80`，後者在座標不同時直接寫 actor `+A0/+A4`。這樣 getter 的 writer、clearer 與位置 consumer 才在同一個有型別的物件上閉合。此數學描述限於有限數值，不對 NaN／非正常輸入推定相同比較語意。[原件 `event_actor_step`、`actor_set_position`、`actor_position_fields`、`float_distance_factor`]

## 6. 明確停止／瞬移也能令 getter 完成

`Q.StopObject(slot)` 經 `567280` 註冊 native `5637E0`，thunk `5695E0` 及 `56A430` 由最後一個 Lua stack value 取整數 slot。有效 slot 上，`56381A` 呼 motion setter，`563821` 為 `66 21 8E E2 00 00 00`，直接清 `E2&8000`。它不要求角色先走到目標，也不要求死亡。[原件 `q_register_StopObject`、`q_stop_lua`、`q_one_integer_marshaller`、`q_stop_native`]

`Q.WarpObject` 的 native `5633B0..5634D7` 同樣先查 Q slot；`563409` 對原 E0 的高 word AND `7FFF`，再於 `563429` 寫回 E0，之後設定位置與方向。這也是可使停止判斷成立的具體 writer；不能由 getter 回一反推「角色自然完成整條路徑」。本輪只將 Warp 的 native clear 納入反例，沒有把其所有 Lua 參數契約重做成新結論。[原件 `q_register_WarpObject`、`q_warp_native`]

同輪 actors 已核兩個容易誤用的反例：`ShowObject` 只寫 `+42C`，其 render gate 不阻止 `v+20`；`DeleteObject` 註冊的 `476430` 只有 `ret 4`。所以 hide／這個同名 delete 不能當作本位元的停止 writer。實際 DeleteAll／Q 清理和 slot 移除仍按 actors 的完整生命週期證據使用。[同輪 actors](../actors/report.md)

## 7. 原版 qbase 已經如何消費這個結果

### 7.1 P24：先 yield，再依 numeric 0 等待

Event carrier 原件解出 76 個 prototypes、906 個指令 word；本包只新增保存 P24、P25、P26、P35 及各自 root binding。P24 的 root PC62/63 以 CLOSURE／SETGLOBAL 實際綁成 `WaitForObjectsStop`。其 code offset `5272`，11 個 words，常數為 `yield`、`Q`、`IsAllObjectsStopped`、`0`。[lua-evidence.json](lua-evidence.json)

```lua
-- 依原件 P24 還原的控制流程，僅供分析；本研究未執行。
function WaitForObjectsStop()
    yield()
    while Q.IsAllObjectsStopped() == 0 do
        yield()
    end
end
```

PC0/1 無條件先 yield；PC2..6 呼 getter 並比較數字零；PC7/8 yield；PC9 回 PC2。它需要可 resume 的 coroutine context，不是任意 named callback 內都能直接跑的同步等待。Lua 裡數字零並不等於 boolean false，因此內容應保留明確 numeric 比較，不能改成 `while not Q.IsAllObjectsStopped()`。

### 7.2 P26：七個 global 參數轉成六個 Q 參數

原版 global `WalkObject` 是 P26，root PC66/67；它有七個固定形參，**省略第四個位置參數**，實際傳給 Q 的是第 `1,2,3,5,6,7` 個值。第六個值為 `-1` 時換成 `4`；第七個值先經 P25 `ConvSpeedStepToMultiplier`。本稿不憑暫存器位置替被省略的第四個參數猜一個未證的座標名稱。[Lua P26 PC0..18、P25]

| Global `WalkObject` 位置 | 對應與處理 |
|---:|---|
| 1、2、3 | 傳 native slot、x、y |
| 4 | 原件 runtime wrapper 未轉交 Q |
| 5 | numeric animation gate |
| 6 | motionId；`-1` 轉 `4` |
| 7 | speedstep，先轉成倍率後傳給 native |

P25 的原版倍率對照是 `0→1`、`1→1.2`、`2→0.5`、`3→0.25`、`4→0.125`、`5→0`；其他值進 print 分支後回 `1`（該分支本身還需要可連接成字串的輸入）。P26 呼完 Q 後只 yield 一次，**不會自動等所有角色停止**。P35 的 global `StopObject` 則傳一個 slot 給 Q 後 yield 一次。[Lua P25、P26、P35]

這解釋了開發時必須區分的兩層契約：global wrapper 的七參數，與 `Q.WalkObject` 的六參數。前置掃描 VM 的同名 global API 另有資源依賴收集行為；不能只因 runtime 可以呼 Q，就跳過前置掃描所需的 global 入口。跨兩個 VM 的共同內容契約以同輪主稿／[bridge](../bridge/report.md) 為準。

### 7.3 不能忽略的等待生命週期

| 條件／反例 | 已證後果 |
|---|---|
| Q tree 為空 | getter 直接回 `1`；不證明世界敵人為零 |
| 多個不同腳本用途的 Q actor 同存 | getter 看全部索引元素；沒有傳入 actor/group filter |
| Stop 或 Warp 清位元 | 可以解除等待；不證明自然到達、死亡或某場戰鬥結果 |
| `actor+D4 != 0` | 本 tick 返回但不清 pending；可能繼續等 |
| multiplier 為零且未走到距離變大分支 | step 為零，可持續保持 pending；例如起始有限 d²≤1e9 的請求，animation gate 非零而套用原版 speedstep `5` 時會形成這個風險 |
| qco 被 pause／未 active | native actor loop 仍可能更新；Lua 等待本身要等 resume |
| wrapper／API 被後載入內容重定義，或 receiver 被 Rebind | 本原版 binding／body 的前提不再保證成立 |

這些是程式分支導出的內容契約，不是已經執行過遊戲的測試結果。新內容可以據此設計明確的 Stop／取消分支，但不能把 native return count 或空表完成偽裝成遊戲完成 ACK。

## 8. 另兩個 Tutorial getter 的正向資料與限制

### 8.1 `Tutorial.IsLeaderDialogOpened` 是 owner+38 的數字

完整 Tutorial root `4A88E0..4A89BF` 實際呼 31 個 regular registrars。`4AB800` 寫 `FE1878=54E740` 並註冊 closure `4AC970`；後者讀 `[FE1804]` 作 ECX、呼 native，將整數回傳轉 Lua number。`54E740..54E744` 只有 `MOV EAX,[ECX+38]; RET`。正常 owner `FC0F84` 下，欄位地址確為 `FC0FBC`。這與 world actor 或 current controller 都不是同一 receiver。[原件 `tutorial_binding_chain`、`tutorial_register_IsLeaderDialogOpened`、`tutorial_dialog_getter`、`tutorial_dialog_lua`；正常 owner／Rebind 按[前輪 events](../../MEF-world-integration-20261115/events/report.md)復用]

其可證 writer／consumer 如下：

| 階段 | 確切原件 |
|---|---|
| 初始化 | `47AED7` 清 ESI，正常 owner constructor `47AFA7` 寫 `FC0FBC=ESI=0` |
| UI dispatch | `CTutorialPage` vptr `C1F5F4`，`v+15C=595D20`；event `F42DD` 落在 `F42D7 < event < F434A`，因此呼 `v+18C=5C32D0` |
| 選定 page consumer | `5C32E3/EA/ED` 選中 `F42DD`，`5C3303 → 5C34B0` |
| toggle writer | `5C34B0` 讀 page `+224` window 的 `+28` bit `100`；關閉分支在 `5C3576` 寫 `FC0FBC=0`；另一分支在 `5C3593` 呼 `596E00` 後，於 `5C35F4` 寫 `FC0FBC=1` |
| Lua consumer | 下次呼 `Tutorial.IsLeaderDialogOpened()` 讀同一 DWORD，回 number |

這是 conditional UI-event→native flag→Lua getter 的正向鏈；本輪沒有宣稱兩個探索性的 UI component producer 的 owner、所有 input 可達性也已閉合，更沒有將本機 event `F42DD` 改稱 Server application opcode。[原件 `tutorial_owner_constructor_normal`、`CTutorialPage_vtable/COL/type`、`page_range_dispatch`、`tutorial_page_event_dispatch`、`tutorial_dialog_toggle`]

有一個不能省略的反例：`596E00` 在 page `+F0 != 0` 時可直接返回，還有不同 group/show 分支；caller `5C34B0` 仍在呼叫之後寫一。**因此此 getter 表示記錄的 UI 分支狀態，不能嚴格等同於此刻視窗一定已顯示。** 已核的 Tutorial page leave `5C3210..5C32CE` 沒有直接清這個絕對地址，不能把「換 page 就一定歸零」當作內容前提；此句不宣告它的所有間接清理 callee 都沒有其他副作用。[原件 `page_show_helper`、`tutorial_dialog_toggle`、`tutorial_page_leave`]

### 8.2 `Tutorial.GetTutorialState` 其實讀 current controller

`4AB440` 寫 `FE1860=4A9FD0`、註冊 closure `4AC700`。Thunk 雖然也設定 ECX 為 `[FE1804]`，native 函式 **完全不使用這個 receiver**：

```asm
004A9FD0  A1 A4 A7 FB 00        mov eax, [FBA7A4]
004A9FD5  8B 80 34 01 00 00     mov eax, [eax+134]
004A9FDB  C3                    ret
```

`CTutorialController` 的 vptr `C0FB1C` 與 RTTI 已對齊；其 ctor `548B99` 把該物件 `+134` 寫零。此 getter 沒有 null guard 或 current-controller type guard。前輪已確認 ordinary Single controller 的配置／layout 不與 Tutorial 相同，因此不能把所有普通場景的 current controller 都視為有同一有效 `+134` 欄位。[原件 `tutorial_register_GetTutorialState`、`tutorial_state_lua`、`tutorial_state_getter`、`tutorial_controller_constructor`、`CTutorialController_vtable/COL/type`；[前輪 identity](../../MEF-world-integration-20261115/identity/report.md)]

本輪對 controller code `544000..548DA0` 的定向導航沒有閉合一個 post-init completion producer；整個 `.text` 中 `34 01 00 00` 的 literal 命中也混有其他物件 layout、立即數與控制流程，不能由同 offset 搜尋充當 writer 證明。**這裡的精確未解項是：哪些實際 caller 以哪種 controller 寫入 +134，數值的語意與 reset 邊界為何。** 這是 Client 待逆向，不能偽裝成 Server 缺資料，也不能由初始化零推論該 getter永遠只回零。

31-entry 註冊表只證明 API 確實綁定；除本文及明確引用的舊鏈之外，不把它當作所有 target 的完整語意盤點。例如 IsIsiliaFound 的導航涉及固定世界 key 與 camera／screen gates，未在此提升成 group-completion observer。

## 9. 對新 MEF 與 Server 的實際交付

### 9.1 現在可採用的內容契約

在已建立／預載且仍由 Q 索引持有的 script actor 上，可以由 runtime coroutine 下達走位，透過 `WaitForObjectsStop` 接後續鏡頭、對話或演出分支；停止與取消可以使用已證 native clear。內容須明確保留 slot 所屬範圍、精確參數個數、numeric gate、有效倍率與 coroutine resume 條件。這能讓所選演出排序由 MEF 負責，是具體可用的 Client 能力。

這份 observer 契約不單獨提供新 `.mef` 的首次載入、prepass 資源集或 ordinary Lua runner。這三項與同輪 [actors](../actors/report.md)、[bridge](../bridge/report.md) 及 [ordinary runner](../ordinary-runner/report.md) 的條件合用；不能把一段示意 Lua 當作已驗證可直接載入的官方 `.mef` grammar。

### 9.2 必須分開移交的需求與未解項

| 分類 | 具體下一步／開發需求 | 已有介面及尚缺內容 |
|---|---|---|
| Server 待開發 | 定義哪些演出由 MEF 推進，哪些 authoritative 戰鬥結果仍由 Server 計算；指定 instance／run generation、成功／失敗／取消的業務語意 | 這是相容 Server 的規則選擇，不要求還原官方 Server 演算法 |
| Client 待逆向 | 普通 battle death/group/result 到 Lua 的有型別 observer 或可達事件橋 | 本輪 Q 位元與 Tutorial UI/state getter 不能填這個洞；需沿具體 native writer→有型別容器→已註冊 getter／callback consumer 繼續，不再重複已排除的 004C、004E 或單純000C視覺死亡鏈 |
| Client 待逆向 | `GetTutorialState` 的 post-init writer與 controller適用型別 | 已有 getter／binding／Tutorial ctor；下一步應追指標與 caller，不以全域搜 offset 當閉合 |
| 跨功能待整合 | 將 Q slot、資源依賴、雙 VM 內容及 coroutine生命週期放進同一最小內容單位 | 本輪只提供有明確前提的 movement／UI observer；實際橋接以同輪主稿判定 |
| 待遊玩驗證 | 自然到點、Stop／Warp解除、空表、多slot、pause／resume、頁面切換等選定情境 | 此輪只做靜態核對，未執行Client或Lua；沒有把示例或 verifier PASS當作遊玩結果 |

普通完成事件橋尚未找到，是 Client 機制缺口；Server 自行定義事件何時成立，是 Server 開發需求。兩者分別保留，避免把「Server內部不知道」當作繼續靜態研究的阻塞，也避免將未知 Client 介面直接丟給 Server 用猜的。

## 10. 重驗方式

在本 repository checkout、原件均可唯讀取得時執行：

```sh
python -B kr-extra-roy/MEF-content-contracts-20261116/observers/verify_evidence.py \
  --repo /path/to/ttr_anal_multi \
  --bin /path/to/02-Tartaros.bin \
  --event /path/to/06-Event.stp \
  --verify-sources
```

工具只讀原件、固定 Git objects 與證據包，停用 Git lazy fetch／optional locks，不執行 Lua。它重驗原件 hash、PE VA/raw、全部所選 bytes、連續指令邊界、registrar caller／slot／name／closure、vtable／RTTI、numeric return、Q bit writer／clearer／selected CFG，以及 selected qbase prototype 和 global binding。原始語意的推導仍以上文及精確適用界線為準。
