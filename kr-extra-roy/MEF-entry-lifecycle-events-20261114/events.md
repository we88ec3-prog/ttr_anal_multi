# 普通死亡、移除與教學互動到 Lua 的橋接：第三輪有界追查

日期：2026-11-14。分析分工：`binary_inventory`。固定導航基線：`552e05a024505a3773095f951c285216051ce2a1`。

## 結論

本輪補到兩條性質不同的實際功能鏈。

1. **既有 S2C `000C` 可以把指定世界 EntityId 的 `CMonster` 切入真正的 `CDeadState`。** 本輪新增的是從既有狀態封包入口，一直解析到 secondary vtable、state 3 配置、enter/update/exit 及其消費者。其可見效果包含死亡動作、`DEAD` 效果與模型淡出。這條鏈沒有因為名稱是「死亡」就自動成為 Lua 的死亡／群清通知。
2. **教學 checkpoint 互動確實有「native writer → Lua 數值 readback → 腳本後續動作」完整陽性鏈。** category 4、controller mode 4 的互動會寫 `CTutorialController` 的狀態陣列；`Tutorial.GetControlStatus` 真正把該值 push 成 Lua number；原件 `TutorialMain.lua` 輪詢點 1／2，收到後關閉點並播放下一幕。這個機制的模式與物件佈局限制非常具體，不能直接移作普通 Field19／Map191 的清怪通知。

三個候選支線已可作有界排除：死亡狀態的額外 `49D8E0` 分支是格式化診斷訊息；移除時 controller `v+1C` 三次呼叫實際是無副作用的 slot getter；Single／Formation 的 `v+14` 是控制槽與容器清理。**尚未閉合的缺邊是：普通戰鬥的 typed EntityId／instance／group 完成事件，如何寫入普通 Lua runtime 可讀的狀態或 callback。** 這項缺口需要繼續查既有 Client 入口，也需要列入相容 Server 的事件與身分契約；不能用新增一個 Client 不認識的 opcode 補過。

本稿沒有把「普通 Lua 是否可以持續 tick」當作群清觀察器的替代證據。即使同輪 `lifecycle.md` 已證普通 runtime 可 tick，腳本仍須有可辨識的事件資料來源。

## 範圍、來源與驗證程度

原件 `02-Tartaros.bin`：PE32 i386，image base `0x00400000`，12,472,320 bytes，SHA-256：

`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

原件 `06-Event.stp`：11,241,597 bytes，SHA-256：

`2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。

所有 VA 都只適用於上述 BIN。原件只讀，不執行／附加 Client，不執行 Lua，不修改 Client、Server、repo、index 或 branch。反編譯僅導航，關鍵支線由原始機器碼、PE mapping、RTTI 和 vtable 交叉確認。這是有界語意查驗，沒有升格為整個 Client 的 FULL-PASS 或全域不存在證明。

交付證據：

- `native-windows.json`：47 個指令窗口、4,019 bytes；26 個 data／string records；每筆包含 VA、raw offset、完整 hex、SHA-256，6 組 RTTI／vtable 與虛擬零初始化全域另存 `native-relations.json`。
- `native-windows.asm`：上述 47 個窗口的原件反組譯，指令 bytes 全部覆蓋窗口，無截斷 `.byte` 或 `(bad)`。跳躍表獨立保存為 data，未假裝成指令。
- `tutorial-script-evidence.json`：只讀兩個已知 STP 成員，原件 hash、完整 proto／指令字／常數／metadata 對照，以及本題選定的 Lua PC、stored／decoded hex。
- `source-manifest.json`：固定 commit、repo path、Git blob SHA-1、檔案 SHA-256；同輪分工稿另外標成 working analysis，沒有冒充固定 main 來源。
- `verify_evidence.py`：整合後的唯讀重驗器，命令見 `README.md`。

以下 `[Nxx]` 為 `native-windows.json` 的 events 群組 source_id；`D-`／`R-`／`T-` 為 vtable／RTTI 原件資料；`S-` 為原件字串。完整位址與 bytes 在證據檔中，不以反編譯命名取代它們。

### 沿用的既有範圍

下列事項是固定 main 已有的基線，本輪不當作新發現：`001A` 移除 actor、教學 `004C → IsScenarioEnded`、`0022 kClearCondition` 是文字、Q119/3 的有限演出、`GetObjectCount` 無有效 count、FB74C0 的 MEF 名稱儲存陰性，以及原件 MEF parser 尚未建立。沒有重掃副檔名、STP 全成員、MEF 全域字面指標、32 alias 或舊 16 個 lookup caller。

主要沿用來源為 `scenario-controls.md`、`S00-20261113-MONSTER-LOCAL-CONTROLLER-BOUNDARY.md`、T10 W06 與 T16-111。它們的固定版本在 source manifest，舊結論與本輪動態槽解析在下文分開。

## 一、既有 000C 到真正 CDeadState 的正向鏈

### 1. Handler view 和 world actor 的型別邊界

`4ADDC6` 把 `4B0130` 寫到共用收包表的既有 `000C` handler slot；這不是發現新 opcode。[N01]

`4B0130` 的 **handler-view** 算式與讀取如下：[N02]

| 項目 | 原件行為 |
|---|---|
| 長度 `L < 2` | count = 0 |
| 有效非負長度 `L >= 2` | count = floor((L − 2) / 3) |
| row `i` 的起點 | handler buffer + 2 + 3 × i |
| row + 0 | u16 world EntityId |
| row + 2 | sign-extended s8 StateId |
| actor 查找 | `40F060` 取 owner，對 owner+8 以 `82EF00` 有序查找；node+10 是 actor |
| 命中且 actor 非空 | actor+F0 的 secondary FSM，呼其 vtable+8，唯一顯式參數是 StateId |
| 缺 actor | 診斷後跳過該 row，沒有排隊等晚到的 actor |

長度須由上層提供與 buffer 一致的合法 handler view。本輪沒有重新定義外層 socket framing，也沒有把上述 2-byte 前綴等同完整傳輸層 header。實作應沿用既有封包契約。

native 關鍵點：`4B0160` 讀 u16、`4B0177` 查樹、`4B019A..4B01AE` 解析 actor+F0 的虛呼叫。這是以共享 EntityId 選中的世界 actor，與 Q 演出槽號不同；與本地 `lb.CreateObjectEx` 沒有回給 Lua 的 ID 也不能自行合併。

### 2. state 3 的身分由 constructor、RTTI 和 vtable 同時確認

`CMonster` primary vtable 為 `C0C9DC`；secondary FSM vtable 為 `C0CA64`，其 +8 明確指向 `4CA060`。RTTI type descriptor 名稱為 `.?AVCMonster@@`，secondary table 也屬同型別。[N03，D/R/T-CMonster，D/R/T-CMonster.ActorFSM]

`4D1710` constructor 的 `4D1749`／`4D174F` 安裝這兩個 table；`4D1773` 配置 `0x3C` bytes 的 state object。`4D178A` 傳入 state ID 3，`4D178D → 4CB230` 寫 owner 及 ID，`4D1792` 把該 state 的 vtable 設為 `C077CC`，`4D17C1` 插入 actor+F4+4×stateID。[N03、N04]

`C077CC` 的 RTTI 名稱是 **`.?AVCDeadState@ActorStates@@`**，不是從數字 3 猜出的名稱。[D/R/T-CDeadState]

| 物件／欄位 | 已確認含義 |
|---|---|
| actor + F0 | secondary FSM vtable |
| actor + F4 + 4×ID | 已建構的 state pointer |
| actor + 158 | 目前 state pointer，即 FSM receiver + 68 |
| state + 04 | 所屬 actor pointer |
| state + 08 | state ID，這個實例為 3 |
| state + 0C | transition 時寫入前一個 state 的 ID |
| state + 38 | 死亡效果的累計量，enter 歸零、update 加入傳入 dt |

### 3. Transition 和消費者已逐槽解析

`4CA060` 對 `newID != 0x1A` 且目標 slot 非空的情況，依序呼舊 state `v+0C`，複製前態 ID，更新 current pointer，再呼新 state `v+04`。[N05]

對 CDeadState，這三個槽與其更新鏈是：

| 步驟 | 實際 target | 可見消費 |
|---|---|---|
| enter，v+04 | `4CB590` | motion 7／speed 1.0、清附屬效果、timer=0、建立 `DEAD` 效果；可選診斷訊息 |
| update，v+08 | `4CB710` | 查模型動作進度；超過約 0.99 後累加 dt，上限 1；超過 0.5 後寫淡出色彩 |
| exit，v+0C | `4CB7D0` | 在模型有效時重設模型相關色彩／效果設定 |
| 額外槽，v+10 | `5F5D10` | 本 table 指向直接返回的空函式 [N47] |

enter 的 actor `v+68` 在 CMonster table 對到 `4C8DA0`；該 helper 寫 actor+38C 的 motion ID，再調模型動畫方法。state 的 `DEAD` 是原件 ASCII 字串 `C07778`，不是讀取 `.mef` 的檔案名。[N06、N11、S-effect]

每幀一側也有實際消費：CMonster `v+24 → 4D1AF0`，適用分支在 `4D1B6F` 呼 `4C87D0`；`4C88CE..4C88E0` 讀 actor+158 的 current state 並呼其 `v+8(dt)`，所以 state 3 的 update 並非只有孤立 vtable 名稱。[N09、N10]

數值 0.99／0.5／1 是原件算式；本稿沒有實測該 dt 與牆鐘時間的對應，不把它們寫成已驗證的秒數。[N07，F-progress，F-fade-start]

### 4. Server 可用的動作和事件缺邊須分開

在上述 handler 已被選用、world EntityId 對應已建立的 CMonster、state 3 slot 存在時，相容 Server 可使用既有狀態同步把它切成死亡呈現；這個局部入口沒有另以 Field19／Map191 或某一 MEF 名稱作 gate。進入動作時仍會呼前一 state 的 exit，因此前態與重入語意也須納入驗收。[N02、N05]

`4CA060` 沒有「newID 等於目前 ID 即略過」分支。重複 state 3 會再經 exit／enter，重設 timer，並可再次建立 enter 效果。因此未來若從 state enter 建立死亡計數，不能把每次 enter 都算成新的死亡；應帶同一實體生命週期的去重語意。這是由控制流推得的條件，尚非實機測量。

本輪所讀 enter/update/exit 沒有讀 instance ID、group ID 或增減群組存活數，也沒有直接呼已辨識的 Lua bridge；fade update 沒有呼 world actor removal。因此：

- **已證**：指定 EntityId 的死亡呈現動作可到達並由本地 update 消費。
- **未證**：Lua 已能讀取這個 actor 的死亡轉移／目前 state，或已收到一次 typed death callback。
- **未證**：多個死亡會被同一普通副本的 group observer 聚合為完成。
- **不等價**：死亡呈現、actor 被移除、權威死亡／勝利／獎勵提交。

未解析所有 renderer／effect 的間接實作、其他模組與所有 state transition producer；本輪沒有把這個有界陰性寫成「Client 絕對沒有事件系統」。

## 二、可選的死亡「通知」其實進入診斷訊息佇列

`4CB590` 有一條容易誤認成 observer 的分支。`4CB5F0` 只在 `FAB104 & 4` 為真時，取 actor+88，呼 `49D8E0`。`49D6A0` 初始化該 flags DWORD 為 0；這不是無條件的戰鬥事件通報。[N06、N12]

actor+88 是 model/composite identity 欄位；`4C6FB0` 的 setter 直接寫 +88/+8C。它不是先前查世界樹的 u16 EntityId，也沒有 group／instance 參數。[N44]

`49D8E0` 用該 composite key 查名稱，取其低 16 bits 與高位中的一個 byte+1，交給格式字串：

`사망 확인 '%s(%d, %d)'`，意為死亡確認名稱與兩個顯示數字。[N13、S-death]

`4D6C70 → 4D6BA0` 不是呼 Lua 的 varargs dispatcher，而是：配置 `0x24` bytes 的訊息記錄、設 record type=1、以寬字串格式化並複製到記錄+8、呼 `4D7B00` 放入訊息佇列。`4D7B00` 對 type 1 選 bucket 5；加入記錄／索引後，比較 count 與 50，超出時呼 `4D7C70`；本輪不進一步解釋該維護 helper 的全部語意。必要時再由 `4D6C90` 建立既有 UI event，vtable `C47B0C`、event code `0xF4366`，其其他顯式欄位為 -1、-1、0。[N14–N18，D-jumptable]

這條路徑的下游資料是**診斷文字記錄與 UI 刷新事件**。沒有把原 world EntityId／instance／group 放進上述 event object，也沒證到 Lua 對這份診斷文字的 consumer。本稿因此排除此分支作為本題需要的 typed ordinary death／group-clear bridge；不把所有 UI event 子系統都宣告成無 Lua。

其中 `4F3D80` 是已知 catalog initializer，本輪僅沿用其初始化性質，不把它重算成 MEF consumer。

## 三、移除過程的 controller 呼叫不是死亡廣播

`001A → actor removal` 是既有契約。本輪新增的是把 `4DFBC0` 裡未明確命名的 controller 虛呼叫與三個實際 vtable 對上。[N19]

`4DFBC0` 找到節點後，對 current controller 的 `v+1C` 分別傳 0、1、2，各呼一次，**三次返回值都直接忽略**。原件沒有把即將移除的 actor 或 EntityId 傳給這個槽，也沒有使用返回值寫一個狀態。[N19]

| 已辨識 controller | 原件 vtable | v+1C | v+14 |
|---|---:|---:|---:|
| CSingleController | C0FAC4 | 545290 | 545210 |
| CFormationController | C0FA14 | 545290 | 547750 |
| CTutorialController | C0FB1C | 545290 | 545210 |

三者的 `545290` 是完整可見的純 getter：以 unsigned 比較檢查 index，不在 0..2 時回 0；其餘回 `controller + 0x0C + index×0x0C` 的 actor pointer，沒有寫入、callback 或 dispatch。[N20，三組 D/R/T-controller]

接著 `4DFBC0` 呼 actor `v+14`、deleting destructor，再用 `7B6890(tree, &out_iterator, node)` 移除樹節點。CMonster `v+14` 實際是 `4D1F80 → 4C8360` 的 render/effect detach；這是 actor cleanup，不能把先前那三個 getter 命名成通知。[N19、N45，固定 bulk `4C8360`]

既有 `001A` 路徑另可在受控角色匹配時呼 controller `v+14`。本輪解析到的 Single/Tutorial `545210` 清三個 actor slot、相關旗標與 vector；Formation `547750` 做相同控制槽清理，另將 SubAI 三個全域欄位歸零。它們沒有在所讀 native 內容中寫 Tutorial point flags、scenario-ended map 或 Lua event。[N21、N22]

這裡排除的是**這三種已知 controller 的這些實際槽**。未對其他未辨識 controller、所有 destructor／render 介面或全 Client 的移除 hook 作全域否定。

## 四、教學互動到 Lua 再到動作：完整陽性對照

### 1. 真正的 producer 有 category 與 controller mode 雙重限制

既有 checkpoint 接近／互動測試 `544730` 先看 enabled byte+105，計算距離平方與半徑；依 checkpoint+100 選擇需要互動輸入或自動進入的分支，並更新 +104。這不能簡化為每一種點都一定要按 Z。[N32]

當流程進入 checkpoint dispatcher `544070`：

| 條件 | 行為 |
|---|---|
| category = 4，且 `[FBA7AC] == 4` | signed checkpoint key 取自 +F6；`5443E3` 寫 `[currentController + 0xB4 + 4×key] = 1` |
| category = 4，但 mode != 4 | 直接往結束路徑，沒有上述 flag writer |
| 一般 category 0 出口 | 不走 category 4 writer；經適用的 UI／模式分支後可到 `544020` 發 C2S `001C` intent |

`544020` 提交的 6-byte send buffer 是 u16 opcode `001C`、u16 category、u16 key，還需 `[FBA798]==0` 才呼 send interface。它本身沒有 instance／group／victory 欄位。本輪沒有將這個已知 C2S 意圖重新命名成 Lua callback。[N26–N31]

### 2. writer 的存放物件確實是 CTutorialController

`548B90` 建構 `CTutorialController`：`548B9F` 裝 `C0FB1C`，把 `+B4..+130` 的 32 個 DWORD 清零，`548C65` 寫全域 controller mode=4。`+134` 是另一欄位，不屬這 32 個 status slot。[N23，D/R/T-CTutorialController]

在已存在該 controller、checkpoint key 1／2 及前述互動 gate 下，producer 的寫入位置就是這份已初始化的狀態陣列。它攜帶的是教學 checkpoint key；不攜帶普通怪 EntityId、群組或副本世代。

### 3. GetControlStatus 的返回值不是只留在 EAX

已確認的 registration／wrapper／native readback 如下：[N33–N38，S-get]

| 層 | 精確證據 |
|---|---|
| native target 安裝 | `4AB3B8` 寫 `[FE185C] = 4A9FB0` |
| 名稱 | `4AB3F8` 推字串 `D6ACDC = GetControlStatus` |
| Lua closure | `4AB409` 推 `4AC6A0` |
| closure 下游 | `4AC6D6` 取 target，`4AC6E1 → 4ACF90` |
| 整數輸入 | `4ACF90` 從 Lua 值轉成整數；在 `4ACFF0` 呼 target |
| native getter | `4A9FB6` 取 FBA7A4；`4A9FBC` 回 `controller+B4+4×key` 的 DWORD |
| 真正 push 回 Lua | `4ACFF3` 保存 native EAX；`4ACFF8` 轉整數到浮點；`4ACFFE` 寫 type 3；`4AD005` 寫 number；`4AD007` 將 Lua top 增 0x10 |

因此此處確實有 **Lua 可讀取的狀態值**。這和同輪 identity 分工的 `CreateObjectEx` 不同：後者外層回 EAX=1，但 native 路徑沒有把新 EntityId push 成 Lua 結果。不能只見兩個 wrapper 都回 1，就認為兩者有相同的輸出 ABI。identity 分工稿是同輪 working analysis，整合稿預定為 `identity.md`，不冒充這份 main snapshot 的舊證據。

對應 `SetControlStatus` 的 native target `4A9F90` 直接寫同一個 controller array，沒有自行辨認其 subtype。[N34，S-set]

### 4. 原件 Lua 已讀取這個值並觸發後續動作

不是只有 binding 名稱。原 `Event.stp` 的兩個既有成員已針對性重讀、XOR restore，再用前輪唯讀 Lua 5.1 chunk reader 對照固定 main 保存的 JSON：

| 成員 | 原件 stored offset／length | decoded SHA-256 | 本輪比對 |
|---|---|---|---|
| Event/TutorialMain.lua | 10,647,568／5,480 | `662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809` | 11 proto、558 instruction words，所有常數及 metadata 一致 |
| Event/TutorialBase.lua | 10,645,520／1,416 | `26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744` | 6 proto、72 instruction words，所有常數及 metadata 一致 |

沒有執行 bytecode、沒掃其他成員、沒有把既有 JSON 的 `full_consumption` 直接當本輪成功；本輪 parser 確實讀完同一原件 chunk，且每份 proto 與既有資料一致。保存的 opcode 語意仍按靜態資料判讀，沒有宣稱實機驗收。

**本稿所有 Lua PC 都從 0 起算，區間末端為含端點。** `TutorialMain` proto0 的 PC12/13 把 child5 設為 `Tutorial_Part1`。其 proto5 有兩段明確的事件消費：[tutorial-script-evidence.json]

| 教學點 | 建立 | 等待 producer 的旗標 | 讀到後的 action consumer |
|---|---|---|---|
| key 1 | PC33–36：InsertTutorialCheckPoint(1) | PC37–46：GetControlStatus(1) 與 FALSE 比對，未完成則 yield 循環 | PC47–54：SetCheckPointStatus(1, TUTORIAL_POINT, ST_CLOSE)；PC60–63：PlayAndWaitForScene(1000, 3) |
| key 2 | PC70–73：InsertTutorialCheckPoint(2) | PC74–83：GetControlStatus(2) 與 FALSE 比對，未完成則 yield 循環 | PC84–91：SetCheckPointStatus(2, TUTORIAL_POINT, ST_CLOSE)；PC97–100：PlayAndWaitForScene(1000, 4) |

`TutorialBase` proto0 的常數及 SETTABLE 指令確認 `TUTORIAL_POINT=4`、`ST_CLOSE=0`、`ST_OPEN=1`。`SetCheckPointStatus → 4A9460 → 544940 → 543B30` 的既有 native action 契約沿用固定 main `scenario-controls.md`；本輪新增的是前面的事件 writer、readback ABI、佈局限制，以及這兩段 Lua consumer 的原件重核。

### 5. 為何不能照搬到普通 CMissionField

這項限制由同 offset 的實際配置證明，不依賴名稱 `Tutorial` 作推論。

CMission 建立 controller 的既有路徑在 `4BC847` 配置 **0xC0** bytes，`4BC865 → 548540` 建 `CSingleController`，`4BC874` 寫入 FBA7A4。[N24]

其 constructor 安裝 `C0FAC4`，`5485A1` 把一個 heap 物件指標寫到 **+B4**，`5485C6` 把另一 heap 物件指標寫到 **+B8**，`5485CC` 清 +BC，`5485D6` 設 mode=**2**。[N25，D/R/T-CSingleController]

所以：

- 普通 SingleController 路徑過不了 category 4 writer 的 mode=4 gate。
- Single 的 +B4/+B8 與 Tutorial 的 status[0]/status[1] 是不同欄位語意。全域 Lua namespace 註冊存在，不代表同一 native getter 對目前 receiver 的讀取具有相同含義。
- 不能把 `GetControlStatus(1)` 在普通 Single 模式回來的一個數字，解釋為教學點或怪群已完成；它會讀到另一種欄位。
- 不能拿 `SetControlStatus` 把這個普通物件的 +B4 後方當通用事件存放區；已確認的布局不支持此做法。

這裡具體排除 CMission／Single 直接借用教學陣列的方案。Map191 數字本身不是 controller subtype；其他進圖模式仍須以實際 field／controller 選擇證明，不能由普通地圖名稱代替該型別證據。

## 五、004C 陽性是另一份狀態，不要和上述 flags 混在一起

既有 `Scenario14` 教學完成鏈仍有效，但屬不同 native 儲存物件：`CTutorial` field 建構 `4C4AC0` 先建立共用接收設定，再在第二張表安裝 `4C4F20`；後者讀 handler buffer+2 的 u16 scenario key，將 `FC0F88` map 中的值設為 1。[N40、N41]

`IsScenarioEnded` 的 target 為 `4AA510`，receiver+4 的 map 經 `4C2880` 取值；binding 存在 FE1880。既有 T16-111 已連到 TutorialMain Part2 的 Scenario14 request／輪詢與後續動作，本輪將它列作沿用陽性，不當作找到普通副本清組事件。[N39、N42、N43，固定 T16-111]

兩種 storage 必須分清：

| API／事件 | native storage | 已有 producer 的限定 |
|---|---|---|
| GetControlStatus(key) | current `CTutorialController` +B4+4×key | category4 checkpoint，mode4；另有教學腳本 setter |
| IsScenarioEnded(key) | Tutorial script owner+4／FC0F88 的 map | CTutorial 接收表的既有 004C writer |
| ordinary CMonster 死亡 | actor FSM current pointer、CDeadState 的 owner/timer | 既有 000C 的 EntityId/state row；本輪未連到上述兩個 storage |

這兩個已知陽性足以證明 Client 有「資料狀態讓 Lua 決定後續動作」的實作模式；它們不足以證明普通 Field19／Map191 已有同樣的 group-clear producer。

## 六、對相容 Server 開發與 Client 替代範圍的具體要求

### 已有 Client 動作，可用既有契約驅動

| 子操作 | 可用條件 | 此輪新增的界線 |
|---|---|---|
| 指定普通怪死亡呈現 | 世界 actor 已存在；該 CMonster state3 已建構；既有 000C handler 可達 | 正向補到 CDeadState；不是 HP 計算或 group-complete event |
| 移除 actor | 沿用 001A EntityId／世界樹契約 | controller 三個讀槽不是 observer；不要把移除數當死亡數 |
| 教學互動後的本地編排 | Tutorial controller mode4、有效 checkpoint key、原腳本／可用 scheduler | writer、Lua pushnumber、實際腳本 action 已閉合；不需每一步都由 Server 指揮 |
| 改變已登記出口狀態 | 沿用 SetCheckPointStatus／0048 的同一 setter 與正確 key/category | action 能力既有，ordinary 清怪的條件來源仍是另一條缺邊 |

### Server 開發需求

1. **身分與生命週期**：維護 instance／群組成員／world EntityId 的關聯及世代，確保生成先於狀態或移除。000C 的 row 只有 EntityId／StateId，沒有群組或副本世代；不應憑 model ID 或 Q slot 補造關聯。
2. **死亡轉移的去重**：把權威死亡、顯示 state3、屍體／actor 移除分成可核對的步驟。重複 state3 不會被本 FSM 自動忽略；重複包、換圖或 EntityId 再利用不能重複累計群清。
3. **普通群清向腳本交付的相容介面**：若目標是「Server 只交付一次完成條件，Client 根據檔案自行開門／演出」，仍須找出未修改 Client 已存在的 packet／local event producer、writer 和普通 Lua reader。現有三個候選支線未提供該介面；這是 Server 可用能力的驗收條件，不是可直接指定新 opcode 的授權。
4. **沿用已識別輸出完成可用版本**：在群清 bridge 未閉合以前，可由 Server 維護遭遇條件，依既有 actor／checkpoint／scene 契約驅動 Client 已有消費者。這項安排與日後「一次條件事件，後續本地排程」應分別驗收，不能把現行封包編排說成已搬入 MEF。

### Client 尚未知、可精準接續的缺邊

| 尚未證的邊 | 已到達、可接續的實際節點 | 需要何種新證據 |
|---|---|---|
| actor death → ordinary Lua state | `4CA060` 的 state transition／`4CB590` enter；world actor key 已由 000C 選中 | 既有 hook、查詢 API 或 dispatcher 必須保留可辨識的 EntityId／生命週期，並有普通 Lua consumer |
| entity events → instance/group completion | 同一世界 actor 索引與目前 ordinary runtime | 群組成員來源、instance／map 切換範圍、去重／清除 writer，以及腳本讀到結果的方式 |
| ordinary checkpoint intent → ordinary Lua condition | category0 的 native interaction／既有 C2S001C | 既有 local callback 或相容下行回應到普通 Lua 的 reader；教學 category4 gate 不能直接替代 |
| 本地 lb 物件 → 群組可辨識成員 | 同輪 identity.md 的世界樹、CreateObjectEx／ID 回傳邊界 | 腳本可取得並持續追蹤的共享 ID，或已證可用且語意穩定的別名機制 |

上表是後續查證節點，沒有提議 patch Client hook。本輪排除的是指定候選，不以「未見」證明所有其他路徑都不存在。

### 待整合與實機驗收

靜態正向鏈不取代執行驗收。針對 ordinary instance 的候選應記錄：實際 field/controller subtype、actor 生成及共享 ID、state3 首次／重複進入、fade 與 001A 時序、map 切換清理、Lua event 被寫入和消費的確切一次性、群組成員及未死亡移除。出口驗收另對照預先登記、關閉／開啟、互動意圖和下一圖狀態。當這些條件一致，才把相應子操作列為由 Client 接替，而不是從動畫或訊息顯示推定勝利成立。

## 重現方式

本分題的 47 個指令窗口及 26 個 data／string records 已併入 `native-windows.json` 的 events／events-data 群組；各筆保留原始 source_id。`native-relations.json` 保存 vtable／RTTI／global 關係；`tutorial-script-evidence.json` 保存原件消費片段及 0-based PC。

依本目錄 `README.md` 使用 `verify_evidence.py` 唯讀重驗原 BIN、Event.stp、Table.stp 及固定 Git 來源。工具會核對 bytes、來源與 Lua 資料，不執行原始 Lua，也不產生實機相容性結論。
