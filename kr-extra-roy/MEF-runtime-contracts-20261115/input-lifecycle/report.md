# 普通 Q 的輸入控制、結束後等待與實際解除入口

## 1. 結論與本輪新增範圍

**`Q.EnableInput()` 是有效的原生輸入 API，但不足以讓仍 active 的普通 Q 變成保留一般操作的背景 runner。** 它清除 `FB8830` 輸入 owner 的遮罩值 `0x2`；Q 更新另外在 current controller 的 `+58` 寫 1。兩者不是同一旗標，也不在同一階段消費。已閉合的更新順序是輸入彙整／過濾在前、controller 產生常規 `000A` row 在中、Q tick 在後。Q active 時，後者持續為下一次可達的 controller 消費設定 `+58`。〔本包 `q_enable_target`、`input_filter`、`client_update_order`、`controller_manager_update`、`q_tick`；復用 [controller-input.md](../../MEF-entry-lifecycle-events-20261114/controller-input.md)〕

**有限 Q 的「結束」也不等於「輸入已恢復」。** qbase 的 `RevPhase1` 確實先呼 `Q.EnableInput()`、再呼 `Q.EndCutScene()`；正常非 review、active、`M+38 == 0` 的 End 路徑會再設定 `0x2` 等待鎖，並建立附帶內部 event `F4322` 的等待對話框。本輪已找到後續明確解除入口：共用 field 的 **S2C app command `00EB → 4B6190 → 562250`**，以及特定場景 init／`Tutorial.StopCutScene`。`562250` 先移除附帶 `F4322` 的對話框，再清 `FB8830 & 0x2`。〔`qbase-tail.json`、`q_end_target`、`input_wait_lock`、`input_wait_unlock`、`unlock_packet_00eb`〕

`00EB` 是本版本已存在的 native unlock consumer；本輪**沒有證實官方 Server 固定以 `00EB` 回覆每一封 `003F`，也沒有重建 `00EB` 的完整 wire framing／長度規格**。此 handler 不讀額外 body，是已證的局部事實，不能因此把完整封包長度直接定為 2。它也沒有載入 `.mef`。本稿是既有有限 Q 執行流程的輸入生命週期補證，不是新 `.mef` 首次載入 caller。〔`ordinary_00eb`、`unlock_packet_00eb`〕

### 原件與版本

| 項目 | 固定身分 |
|---|---|
| 工作分支／HEAD | `extra/roy1`，`a16841ac67638da4b29605f186f355722e8cf106` |
| 導航 main | `ba5f96dfa94d734cbded291fb8887f50426bfa77`；未 merge |
| Client 原件 | `02-Tartaros.bin`，12,472,320 bytes，i386 PE32，ImageBase `00400000` |
| Client SHA-256 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| 資源原件 | `06-Event.stp`，11,241,597 bytes |
| Event SHA-256 | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |

以下 `M=&FB73C0` 是 Q manager；`W=&FDF3C8` 是正式 Lua wrapper；`I=&FB8830` 是輸入 owner；`C=[FBA7A4]` 是 current controller。`0x2` 指 **mask value 2／bit index 1**，不是 bit index 2。原件窗口均在 [native-windows.json](native-windows.json) 與 [native-windows.asm](native-windows.asm)，每窗保存 VA、raw、hex、長度及 SHA-256；本文引用的 `record id` 可直接定位。

## 2. Q 的公開 binding：從名稱到實際 target

`48D76B–48D775` 明確以 W、M 呼 `560600`。`56060B` 把 W 存到 `M+0`；`56060D → 565E40` 建立 Q 表／Rebind，接著呼 **63 個 regular registrar**。因此此初始化共提供 **64 個名稱，含 Rebind**。這是本函式的有界完整表，詳見 [tables.json](tables.json) 的 `q_regular_bindings`，不是全程式所有 Lua namespace 的清冊。〔`q_bootstrap_arguments`、`q_initialize`、`q_table_rebind_registration`、`q_regular_registrars`〕

| Q 名稱 | registrar | native target slot → target | Lua closure |
|---|---:|---|---:|
| `StartCutScene` | `565F20` | `FE277C → 561760` | `568A30` |
| `EndCutScene` | `565FC0` | `FE2780 → 561DB0` | `568A90` |
| `IsCutSceneRunning` | `566060` | `FE2784 → 489CF0` | `568AF0` |
| `EnableInput` | `5661A0` | `FE278C → 562980` | `568BC0` |
| `DisableInput` | `566240` | `FE2790 → 5629F0` | `568C20` |
| `Rebind` | `565E40` | 直接改 native receiver slot `FE2778` | `568790` |

原生初始表內沒有名為 `Q.Stop`、`Q.Pause`、`Q.Resume` 的 binding。已有 `StopObject`、`StopMusic` 等是其他 target，不能縮寫為停止 Q runner。`5624B0` 雖是已證 Q 停止／清理函式，沒有以 `Q.Stop` 出現在這份初始表；後文的公開停止名稱是另一個 namespace 的 `Tutorial.StopCutScene`。這個陰性只涵蓋上述初始註冊，不保證 Lua 後續不改表、不建立 alias，也不排除其他 native module 的額外註冊。

Enable wrapper 在 `568BF6` 從 `FE2778` 取 ECX，`568BFC` 呼 `[FE278C]`。Disable 對應 `568C56`／`568C5C`。兩者 native target 的狀態寫入均使用固定 I，不以 incoming ECX 指向的物件為 input owner。closure 返回的 `EAX=1` 是 **Lua C callback 的結果槽數量**；這些窗口沒有把「輸入成功」布林值入棧，不能把 1 解成成功 ACK。`IsCutSceneRunning` 則另有完整整數→Lua number 的入棧路徑，native target 讀 receiver `+28`。〔`q_enable_closure`、`q_disable_closure`、`q_is_running_closure`、`q_is_running_target`；回傳 ABI 復用 [script-lifecycle/report.md](../../MEF-complete-flow-20261115/script-lifecycle/report.md)〕

### Rebind 的精確界線

`568790` 取 `[FE2774]` 的 W，`568795 → 4A2BB0` 讀 **W 所持 Lua state 的 stack top `-1`**，接受 number 或可轉數值的 string，以 `FISTP` 轉成 32-bit 整數；不合型別／轉換失敗回 0。`56879A` 將結果寫入 `FE2778`。它不是直接從 wrapper 的 incoming Lua callback state 取值，故這裡不把它簡化為任何 coroutine context 下都相同的「最後一個參數」。〔`q_rebind_closure`、`q_rebind_number_conversion`〕

Rebind 改的是 binding receiver，沒有改 `M+28`、`M+2C` 或 `C+58`。外層 tick 仍透過 `422F40` 取得固定 M，與 Rebind 不同步改 owner；Enable／Disable 本身也仍寫固定 I。因此不能把 Rebind 當成公開背景執行／Pause／Resume 契約，更不能以構造不同 receiver 值取代既有物件生命週期。〔`q_manager_getter`、`client_update_order`、`q_enable_target`、`q_disable_target`〕

## 3. 第一層：輸入 owner 的遮罩不是單純 UI flag

`6D0750` 明確建立 `I=FB8830`，`6D0794` 將首 DWORD 清零，後續初始化三組 mapping arrays。Enable／Disable 各自先確保此 owner 已初始化，再作：

| API | 原件 | 實際寫入 |
|---|---|---|
| `Q.EnableInput()` | `5629CE` | `I.mask &= ~0x2` |
| `Q.DisableInput()` | `562A3E` | `I.mask |= 0x2` |

兩個 target 都不寫 Q active／pump gate，也不寫 current controller `+58`。它們也不清整個 mask。UI 在相同 owner 上另有 `58A773: OR 0x8`、`58A7E2: AND ~0x8`；清 0x2 不保證 mask 最終為 0。〔`input_owner_constructor`、`q_enable_target`、`q_disable_target`、`ui_mask_set8`、`ui_mask_clear8`〕

### 真正的遊戲輸入 consumer

| 層次 | 已核原件資料流 | 可證效果 |
|---|---|---|
| action 彙整 | `4914AC` 令 ECX=I，`4914B1 → 6D1480`；`6D191B` 取得 owner `+7D4` | 產生／更新 40-byte action transition array，`I+7D4=FB9004`。 |
| action 過濾 | `490DEF` 讀 `FAADFA`，`490DFC → 6D4A30`；`6D4B35` 比較 `I.mask` | 在對應分支 mask 非零，`6D4B69–6D4B98` 清 40 個 action bytes。 |
| hotkey 過濾 | `6D4BC8` 再檢 `I.mask`，接 `823850` | 清對應 hotkey tree 的狀態；不是只切某個視窗顯示旗標。 |
| 方向 mapper | `546780 → 546D50`，`546DAD` 檢 `I.mask` | mask 非零直接走返回 0；mask 為零仍有 foreground／裝置等既有條件。 |

`6D4A30` 還有 UI capture 參數和 consumed-action list：capture 非零的分支本身便會清 action 狀態。故「清了 0x2」只表示解除這個來源的限制，不保證所有輸入資料非零。它確實影響已證 action／方向控制資料流，不能命名為僅供 UI 使用的 flag。〔`input_action_aggregation`、`input_filter_caller`、`input_filter`、`input_direction_caller`、`input_direction_consumer`〕

## 4. 第二層：主更新先後與 controller `+58`

前稿已閉合 Single／Formation／Tutorial controller 的常規控制 row，這輪復用該結論，新增的是 **真正外層呼叫順序與 receiver**。`490FE0` 完整選定函式窗顯示：

| 同一次更新的先後 | 原件 | 操作 |
|---:|---|---|
| 1 | `4914B1 → 6D1480` | 以 I 彙整 action 狀態。 |
| 2 | `49152B → 58A250` | UI update 可調整輸入消費狀態／mask。 |
| 3 | `491530 → 490D40 → 6D4A30` | action／hotkey 的 mask 與 capture 過濾。 |
| 4 | `491CB6 → 4E0060` | current controller `v+2C` 更新，包含既有 `000A` row 路徑。 |
| 5 | `491CEC` | current field `v+18` 更新。 |
| 6 | `491ED0 → 422F40`、`491ED7 → 561520` | 以固定 M 更新 Q。 |

第 4、5 項與第 6 項各有 outer owner `+BFCC` gate；controller 與 Q 也有自己的 gate。本文沒有把一次函式可達順序說成任何狀態都必定每幀執行。〔`client_update_order`〕

`4E009B` 取得 `[FBA7A4]`，`4E00AD` 取 vtable `+2C`，`4E00B0` 實際呼叫。已證三種 controller 的 vtable slot 為 Single `548A90`、Formation `547F90`、Tutorial `548CB0`，均在其前置條件成立時接到共用 `5452C0`。`4E0060` 另外可依自身 owner `+AC` 設定 `C+58`，故 Q 不是已證的唯一來源。〔`controller_manager_update`、`vtable_CSingleController`、`vtable_CFormationController`、`vtable_CTutorialController`；復用 controller-input.md〕

共用 consumer 的原件意義維持前稿：`5458D8` 在 `+58 != 0` 時於 `5458E0` 清 row 的 control word、還原方向；buffer 足夠時仍可送出含零控制 row 的 `000A`。正常尾端 `545B83` 清 `+58`，但 controller `+04 == 0` 等早退可能略過該 reset。這不是「停止所有遊戲運作」或「任何攻擊／技能封包全部停止」的證據。〔本包重核 `reused_controller-input_P07/P09/P18`〕

Q tick 的順序則是：

1. `561587` 要求 `M+28 != 0`。
2. `5615BF` 取得 current controller，`5615C4` 寫 `C+58=1`。
3. `5615C7` 才檢查 `M+2C`；為 0 時呼 `f_doCoTask`，非零則跳過該命名呼叫。

所以在 active Q 內每次呼 `EnableInput()`，也只清第一層 I.mask；它不取消第二層 `C+58`。這裡**不是說 Enable 的同一個 mask 會被每個 Q tick 覆寫**：每次 Q tick 設定的是另一個 owner 的 `+58`。額外 pump gate `M+2C != 0` 也不提供保留控制的背景執行，它在 controller write **之後**才擋住 coroutine pump。該欄已知 constructor 零初值，非零 writer／合法公開控制方式仍未閉合；本輪不因名稱表沒有 Pause 就宣稱全程式沒有 writer。〔`q_tick`；欄位初始化復用 lifecycle.md〕

若 End 在這次 Q callback 內清掉 `M+28`，這次 tick 更早寫下的 `C+58` 已存在；下一個到達正常消費路徑的 controller 更新仍可能消費一次該限制，然後才 reset。這是由原件先後推得的條件結果，不能換算成固定「一幀後」或某個毫秒數的恢復承諾。

## 5. 有限 Q 收尾：Enable 之後，End 可能重新置鎖

### 5.1 原始 qbase 次序

`Event/qbase.lua` 的有界原件 member 位於 Event.stp stored offset `10618896`，長度 `11836`，XOR FF 後 SHA-256 為 `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3`。唯讀結構解析得到 76 個 prototypes；本輪只新增保存 `RevPhase1`（proto 74）尾端 9 個 words 與 constants，沒有執行 Lua。〔[qbase-tail.json](qbase-tail.json)〕

| proto 74 PC | 原件控制關係 |
|---|---|
| 54–55 | `yield()` |
| 56–58 | 取 `Q.EnableInput` 並呼叫 |
| 59–61 | 取 `Q.EndCutScene` 並呼叫 |
| 62 | return |

兩個 CALL 的 `B=1`、`C=1` 表示無參數、要求 **零個 Lua 結果**；不與 native C callback 的 `EAX=1` 混同。這只是既有表名稱 lookup 的原始次序；runtime Lua 若重綁 Q 欄位，不能仍無條件把名稱視為原始 native target。

### 5.2 `EndCutScene` 的關鍵分支

本輪完整重核 `561DB0`，延續既有正常／review 模式區分：

| 條件 | 已核行為 | 對輸入解除的意義 |
|---|---|---|
| 正常非 review、`M+28 == 0` | `561F63` 跳 `562091` 收尾 | 不經新的等待鎖路徑，也不能用重呼 End 保證清除既存 input mask。 |
| 正常非 review、active、`M+38 == 0` | `561F69` 清 active；`561FE0 → 4A39A0` 走既有 C2S `003F` 回報；`561FE5 → 5620B0` | `56210C` **重新 OR 0x2**，即使腳本前一行已 Enable。 |
| 正常非 review、active、`M+38 != 0` | 查 `CheckConfirmMessage`；條件符合才走既有回報；不經 `561FE5` | 本輪的重新置鎖結論不能無條件套到這一支。 |
| review 分支 | 清 active、移除 qco；可能啟動下一段 review sequence | 不能將一次 End 解成全流程永久 inactive。 |

正常 active 分支之後在 `56202D` 命名呼 `f_removeAllCoroutines`。因此 `003F` 的發送位置可以早於該次 coroutine／UI 收尾完成；它不是新載入成功、所有清理完成、戰鬥清怪或獎勵結算 ACK。`S2C 0031` 是另有明確 Stop 呼叫的 Mission handler，也不能與這個 **C2S 003F** 回報混用。〔`q_end_target`；回報及取消語義復用 [executor.md](../../MEF-parser-executor-storage-20261114/executor.md)、[lifecycle.md](../../MEF-entry-lifecycle-events-20261114/lifecycle.md)〕

`5624B0` 的 Stop 路徑也不能只看中途 mask：`56284A` 清 0x2，後面 `56288C → 561DB0` 又可能進入上述正常 quest0 的重置鎖分支。因此停止來源是否**在 Stop 返回後另呼 `562250`**，是判斷等待鎖最後狀態的關鍵。〔`q_stop_target`〕

## 6. F4322 對話框與 `562250`：解除動作本身已閉合

`5620B0` 設遮罩後，建立 `F4322` 內部 event，經 `58B270` 的 type `200` 對話框建立路徑。它不是將 F4322 當 wire opcode，也不是普通 page event queue 自動回呼的完成通知。

同輪 [ui-lifecycle/report.md](../ui-lifecycle/report.md) §4 已將型別、clone、tag owner、顯示／移除閉合到 **`CMsgBoxWaitAndEnableChat`**：event 附在 dialog 的物件內，`753440` 遍歷 UI active-dialog list，按所附 event ID 找到後關閉／移除。該型已核的空 handler、可見 flag 處理，以及普通 page 的 F4322 default 路徑，都不能代替本節的 input-mask clear。動態 child control 的未定 callback 保留於該分題的明確範圍；未推成所有 UI 行為的陰性。

`562250` 的本體則直接證明：`5622D1` push F4322，`5622D6` 令 EAX=`F94810`，`5622DB → 753440`；返回後，無條件在正常流程 `562307` 清 `I.mask & 0x2`。即使沒有匹配 dialog 被移除，後續 clear 也不依賴「找到對話框」的回傳值。它不 Stop Q、不改 `M+28`，也不清 current controller `+58`。〔`input_wait_unlock`〕

## 7. 誰真正觸發解除：13 個 direct caller 的來源

本輪先復用已知 13 個 direct call candidates，再將每一筆落回原件指令／caller prefix。清冊的範圍是 `.text` 中 **`E8 rel32 → 562250`**；不涵蓋所有間接引用、runtime 改寫或其他寫 I.mask 的方法。以下均為已核正向路徑，不把「只有 13 個 direct callers」說成全程式只可能從這裡解除。

### 7.1 普通 field 的 S2C app `00EB`

完整有界路由為：

| 原件邊 | 已核內容 |
|---|---|
| `49439C` | 封包 dispatch 的 receiver 明確為 `CSceneManager @FD2CF8`，其 `v+4 → 4FDA30`。 |
| `4B7DC0` | 初始化 primary table，default 全部填 `4B7EC0`，列出的特定 override 不含 `00EB`。 |
| `4B7EC0` | current scene 非零時，用 `[SceneManager+5EAC]` 的 `v+4` 轉交原參數。 |
| 普通 Scenario／Mission | 兩者 `v+4 = 4C4670`；先查 secondary table。 |
| constructor | `4C46F0`／`4BC6E0` 清 secondary table，`00EB` 的 slot 為 `+5EAC+8*EB=+6604`；這兩個初始化沒有覆寫該 slot。 |
| `4C4694 → 4FDA30` | secondary 為零時，以相同 field receiver 查 primary table。 |
| `4AE1FD` | `[field+75C]=4B6190`；`(75C-4)/8=EB`。 |
| `4B61E5 → 562250` | 不讀 payload／length、不 Stop，只執行明確解除。 |

這是**已初始化、沒有額外 runtime 覆寫的普通 Scenario／Mission**的實際 native 路由。當沒有 current scene，default 只走錯誤記錄；不能把 `00EB` 當作任何登入／無場景階段都有效的全域 unlock。callback 的局部 body 消費量為 0，也沒有新增本地回覆／清 active；完整封包合法性和官方 request／response 配對仍由 Server 整合需求處理。〔`scene_manager_packet_entry`、`scene_manager_callback_registration`、`scene_manager_forward_current`、`primary_packet_dispatch`、`ordinary_secondary_dispatch`、兩個 ordinary constructor、`common_field_callback_registration`、`unlock_packet_00eb`〕

### 7.2 全部 13 個 callers 與真正觸發來源

表內 subtype 均為 **十進位**，app command 以四位十六進位表示；這是現有場景封包的 native 效果分類，不是為了解鎖而建議任意切換場景。

| `562250` callsite | 所屬函式／類型 | 真正觸發來源 | clear 前的動作 |
|---:|---|---|---|
| `4B61E5` | `4B6190` 共用 field callback | S2C app `00EB`，上述 field route | 不 Stop。 |
| `4A98AD` | `4A9820` | `Tutorial.StopCutScene` 原生 binding | `4A987E → Stop(M,0)`。 |
| `424404` | `424370`，CDailyDungeonRoom init | `00FB` subtype 27 → `4B9D30` | Stop(M,0)，再 clear。 |
| `43441D` | `434390`，CEternalTowerDecision init | `0022` subtype 6 → ctor `434320` | Stop(M,0)，再 clear。 |
| `453F5D` | `453ED0`，CInfiniteDungeonDecision init | `0022` subtype 5 → ctor `453E60` | Stop(M,0)，再 clear。 |
| `4BB09F` | `4BB010`，CDecisionBase init | `0022` subtype 2／3／4／7 的 derived init 直接呼它 | Stop(M,0)，再 clear。 |
| `4BB5E6` | `4BB540`，CDuelSquare init | `0069` subtype 21 | Stop(M,0)，再 clear。 |
| `4BBCAB` | `4BBC10`，CSquare init | `0069` subtype 7／23／24 | Stop(M,0)，再 clear。 |
| `4BCC97` | `4BCBA0`，CMissionRoom init | `0099` subtype 3 → `4B9320` | Stop(M,0)，再 clear。 |
| `4BE56B` | `4BE4D0`，CDuelWaitRoom init | `00A8` subtype 5 → `4B9500` | Stop(M,0)，再 clear。 |
| `4C1658` | `4C15C0`，CExpedition init | `0060 → 4B8F50` 建立 Expedition | Stop(M,0)，再 clear。 |
| `4C443D` | `4C43B0`，CScenarioDecision init | `0022` subtype 0 | Stop(M,0)，再 clear。 |
| `4C5A64` | `4C59D0`，CRaidRoom init | `00A6` subtype 8 → `4B9410` | Stop(M,0)，再 clear。 |

11 個直接場景 hooks 都由原件 vtable `+10` 和 RTTI 定型，不依偽碼名稱猜測；本包保存各 hook 從 entry 到 clear call 的完整 prefix。CDecisionBase 另外閉合了四個實際 derived paths：MissionDecision `4BC220→4BB010`、RaidDecision `4C5030→4BB010`、GvGDuelDecision `4C0680→4BB010`、DailyDungeonDecision `4224C0→4BB010`。`0022` native switch 的 subtype 1 不在這項已證 direct-base-init 路徑內，未因同屬 Decision 字樣而擴張。〔`scene_init_unlocks`、`vtables`、`decision_subtype_targets`；`factory_*`、`unlock_init_*`、四個 derived init records〕

`0060`／`0069` 的原始分類復用 [E64](../../20261030-chatgpt-web-roy-E64-RR0002-expedition-square-69-subtype-and-full-E63-native-appendix.md)，本輪重核 factory、vtable 與解除 prefix；其餘表列路由新增原件窗口。沒有重建這些場景的全部 payload／玩法流程。

共同 `4B7D50` 在 `4B7DA7` **先安裝新 field pointer**，才於 `4B7DBC` 呼新 `v+10` init。因此表內場景解除是正常安裝後的動作，不是「先取消完畢才安裝新 field」的承諾。普通 `005F` subtype 2／4 的 Scenario／Mission init 不在 11 個 direct unlock hooks 中；前稿已證它們不保證 Q Stop／remove，不能把本表改寫成所有轉場必解鎖。〔`scene_replacement_helper`；復用 [scene-cancellation/report.md](../../MEF-complete-flow-20261115/scene-cancellation/report.md)〕

此外，Stop／End review 分支可能串下一段；上述 init 的 clear 也只處理 0x2，不能單憑呼叫到它便說 Q 永久 inactive、其他 mask 已零或 `000A` 立即恢復。

## 8. 對 Server 開發的具體要求

本輪給 Server 的新增可用資訊是 **現有輸入解除 consumer 與處理先後**。不需要因此提出修改 Client 的方案，但 Server 工作仍須落成狀態與相容封包契約。

| Server 開發需求 | 已有原生依據 | 必須維持的界線 |
|---|---|---|
| 有限 Q 完成後，將「結束回報」與「解除等待輸入」分成明確狀態 | 正常 quest0 End 可先送既有 `003F`、再設等待鎖；`00EB` 可解除 | 未證固定 `003F→00EB` 配對；不得把回報直接當清理完成 ACK。 |
| 在合法 current ordinary field 與業務狀態下，完成 `00EB` 既有消息的相容 serializer／排程 | 已證 default→ordinary secondary fallback→primary `00EB` handler | handler 不讀 body ≠ 完整 wire 長度已證；沿現有 framing 規格補齊，不能自造欄位或 opcode。 |
| 確保解除在相應 End／置鎖之後被 Client 處理 | 若先 clear、後 End，End 可重新 OR 0x2 | 依狀態／事件次序驗收，不以固定 delay 猜測。 |
| 場景退出與下一場進入採實際支援類型驗收 | 表列 room／decision init 會 Stop 後 clear；ordinary 005F type2/4 不具同一保證 | 不能為取得 unlock 副作用任意換 scene subtype；應符合該場景業務及既有資源條件。 |
| 普通戰鬥背景編排仍需合法 runner 契約 | Enable／00EB 都只清 mask，active Q 仍寫 controller+58 | 這兩個 API 不能作為常駐 Q 保留一般操作的證明。 |
| 收尾測試同時觀察兩層 owner 與已證控制 row | I.mask 和 C+58 分開消費，其他 capture／mask source 仍存在 | 不將對話框消失、active=0、一次零控制 row 或收到003F任何一項單獨當作全部恢復。 |

這些是 **Server 待開發／整合需求**；官方 Server 的內部策略不需要被猜成 Client 功能缺失。Coroutine/MoCo 的原件 body 已由同輪 [scheduler 分題](../scheduler/report.md) 補齊，其新執行／完成契約依該稿；`.mef` 首次載入 caller、普通 battle 事件／實體身分對齊仍承接主報告的具體未解項，本輪 unlock 發現不能替代它們。

## 9. 可重驗交付與剩餘範圍

最小交付為 `report.md`、`native-windows.json`、`native-windows.asm`、`tables.json`、`qbase-tail.json`、`source-manifest.json`、`verify_evidence.py`、`verification-result.json`、`deliverables-manifest.json`。導航 `.c`、builder、探索候選 JSON 留在 scratch，不需提交。來源 manifest pin 住 86 個既有 Git source paths／blob，分開標示導航與復用報告。

```sh
python verify_evidence.py \
  --bin /workspace/scratch/b43c6175f310/project_sources/02-Tartaros.bin \
  --event-stp /workspace/scratch/b43c6175f310/project_sources/06-Event.stp \
  --repo /workspace/scratch/b43c6175f310/ttr_anal_multi
```

重驗器只讀原件、以 objdump 解碼，核對 **208 個 records／33,261 bytes、77 個 code windows／8,759 instructions、64 個 Q bindings、13 個 direct unlock callers、11 個 init hooks、21 組 vtable／RTTI、qbase 的 76 個原始 prototypes 與選定 9 個 words**。窗口以 `end+15` 解碼、只收 `VA<end`，並要求指令精確連續覆蓋窗尾。這是靜態來源驗證，不是 Client/Lua 執行或 T01 FULL-PASS。

Git 檢查使用固定 `ls-tree` 身分及已存在本地檔案，**不重新 fetch**。若提供 `--source-cache` 指向既有導航 `.c` 複本，可額外重核其內容；本輪保存的驗證結果使用該 cache，86 份內容均核對相符。未提供 cache 時，未出現在稀疏工作樹的 source 會明示只核 fixed pin，不冒稱重新讀過內容。

剩餘界線包括：`00EB` 完整 wire 長度與官方配對、所有 runtime table 改寫、其他 mask alias／writer、`M+2C` 非零 writer、全部 UI dynamic-child callback，以及所有 controller／其他戰鬥通道。它們不影響本文已證「Enable 不能解除 active Q 的 C+58」「正常 quest0 End 重新置鎖」「00EB 與表列 caller 可清 0x2」的有界結論，也不被有限陰性擴張成全 Client 無其他支援。
