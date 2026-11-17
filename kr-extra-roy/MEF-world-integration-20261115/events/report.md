# 既有 Server 事件如何抵達 Lua：004C、004E 與場景／page 限制

## 1. 結論與本輪增量

**已有可以讓 Server 事件抵達 Lua 狀態的具體路徑，但這些路徑各有接收物件與生命週期，不能直接作為普通戰鬥的死亡／清組通知。** 本輪將兩條具體候選從 application dispatch、native producer、owner、UI receiver，一直追到 Lua 能讀到的結果。這是條件式新 MEF 設計可以採用的既有能力分析，沒有發現原版首次載入新 `.mef` 的入口。

| 候選 | 本輪閉合的結果 | 適用界線 |
|---|---|---|
| `S2C004C → Tutorial.IsScenarioEnded(key)` | `CTutorial` secondary table 裝入 `4C4F20`；它把 packet `+2` 的 u16 key 對應值寫成 1。正常 Tutorial binding 的 getter 讀同一容器，回 Lua number | 普通 `CMissionField`／`CScenarioField` 的相同 slot 為空，後續 primary default 落到 invalid-message，沒有沿此路寫入該旗標 |
| `S2C004E → F43DA → OnYesTriggered()` | 共用 field handler `4B3570` 寫入 native selection token，建立一般 UI event；實際 MissionLobby state `4`／Tutorial page state `0xF` 的 consumer 呼固定零引數 callback；原版 qbase body 設 `g_yesTriggered=TRUE` | 要看**消費事件時**的 current page；普通 Mission state `5`／Scenario state `7` page 對此值走 default，沒有同一 OnYes 呼叫 |
| `OnEndTalk()` | 既有 named-calls 與 qbase 原件已證其零引數與 `g_scenePlaying=FALSE` body；本輪有限重驗該 body 作對照 | 沒有在本輪將它新增為普通 Server 事件橋，也沒有將局部 UI timer／input 導航擴成所有實際控制項的可達性結論 |

004C 的 Tutorial writer、既有 callback 名稱清冊與三個 qbase body 是前稿已知事實。**新增的是 004C 在兩種 ordinary field 的完整固定 dispatch 排除，以及 004E 從共同封包 handler 到指定 UI page、固定 callback 與 Lua 旗標的完整鏈。** FE1804 的 `Tutorial.Rebind` 寫入也在此明確核對，避免把正常 startup owner 誤寫成永不改變。[原件：`common_primary_initialize`、三個 field initializer、`selection_ack_handler`、page／callback windows；[前稿事件](../../MEF-entry-lifecycle-events-20261114/events.md)、[named calls](../../MEF-trigger-callers-20261115/named-calls/report.md)]

## 2. 原件、版本與證據範圍

| 項目 | 身分 |
|---|---|
| 分支／開始時 work parent | `extra/roy1`／`acc5b1e6d856bd31456fe2806044c3a09d5bbb43` |
| 最新 main 參考 | `060ed5163a67308f15aa32a91f3a6661e6e5b106` |
| 原件 BIN | `02-Tartaros.bin`；12,472,320 bytes；SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| 腳本 carrier | `06-Event.stp`；11,241,597 bytes；SHA-256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| 共用指示 | `09-02-PROJECT-SHARED-INSTRUCTIONS.md`；SHA-256 `624d808521354aa4fb00774839a25cac29e8fdbaa6029c66f39dc43bf7a1bb43` |

原件一律唯讀；不啟動 Client、不執行 Lua、不修改原資源或 Git。反編譯 `.c` 只作導航，關鍵呼叫、間接指標、vtable、table index、branch、參數與回值均以 BIN bytes 核對。

本文的原件 ID 對應 [native-windows.json](native-windows.json)，每筆含 VA、exclusive end、PE raw offset、完整 hex、SHA-256；code windows 另含從已確認起點解出的指令。可讀內容在 [native-windows.asm](native-windows.asm)。有型別 receiver、callback、選定 CFG／switch 計算在 [routes.json](routes.json)，固定 field tables 在 [field-dispatch-tables.json](field-dispatch-tables.json)。

[source-manifest.json](source-manifest.json) 對每個來源列出 commit、完整 path、Git blob、SHA-256 與角色。57 份導航 `.c` 固定於最新 main；已發布分析固定於工作 parent，不把尚未進 main 的 named-calls 等包假稱已存在於 main。[read-set.json](read-set.json) 區分完成閉合的具體路徑、局部導航與復用的既有結論。

同輪完整 network/frontend 證據引用 [wire/report.md](../wire/report.md) 與 [frontend-table.json](../wire/frontend-table.json)。這是同一交付包的 sibling dependency，manifest 保存其兩份原件／表格 JSON 的固定 hash，沒有虛填尚未提交時的 commit。入口 framing、lane2 與 frontend 的完整解析以 wire 分題為準，本分題不再重建一套不同封裝。

## 3. 004C／004E 先經同一條前端，再由 current field 決定效果

### 3.1 frontend 的完整固定表

同輪 wire 已逐指令讀完 `493170..494355`：3029 個 stride16 預設 entries，其後 **591 個固定 stores＝197 個 handler override 及相應 adjust／metadata**。`004C` 與 `004E` 均沒有 override，handler 是 `494360`、this-adjust 是 0；不能沿用較舊「195 個相鄰編碼樣式」清單來聲稱完整覆寫集合。

完整 CClient 為 `C`、callback holder 為 `C+148`、frontend subobject 為 `C+200`。`48AAD0` 由 frontend 讀 handler／adjust，正常預設以完整 `C` 作 receiver；`49439C` 再把訊息送到 `FD2CF8` SceneManager 的 `v+4=4FDA30`。詳細 ctor、holder 與 lane 條件見 wire 的 `frontend_registration_full`、`frontend_dispatch`、`client_packet_callback`、`client_constructor_prefix`、`client_initialize` 原件窗。[同輪 wire §3–4](../wire/report.md)

### 3.2 SceneManager 與 field 的兩層表

`4B7DC0` 初始化 SceneManager 表，default 為 `4B7EC0`；完整函式其後的 28 個固定 stores 對應 14 個 override，不覆寫 004C／004E。`4B7EC0` 取 SceneManager `+5EAC` 的 current field：非空時 tail-call 該物件 `v+4`，空時記錄錯誤並返回，不形成將事件存到未來場景的重播佇列。[原件 `scene_manager_initialize`、`scene_manager_current_field`]

所核三種 field 的實際 RTTI／vtable 如下。`v+4=4C4670` 先讀 `field+5EAC+8*opcode` 的 secondary handler；空時轉 `4FDA30` 讀 `field+4+8*opcode` 的 common primary handler。

| field 型別 | vtable | secondary 初始化 | 004C slot `+610C` | 004E slot `+611C` |
|---|---:|---|---|---|
| `CMissionField@Scene` | `C0705C` | `4BC6E0` 清 `+5EAC` 起的 `5EA8` bytes，再寫 5 個 handler | 0 | 0 |
| `CScenarioField@Scene` | `C073B4` | `4C46F0` 同範圍清零，再寫 2 個 handler | 0 | 0 |
| `CTutorial@Scene` | `C073E8` | `4C4AC0` 同範圍清零，再寫 1 個 handler | `4C4F20` | 0 |

common initializer `4ADD50..4AE380` 也已完整核對：先建立 3029 個 default `4B7D40` entries，之後 **202 個固定 stores＝101 個 handler override／metadata pairs**。004C 的 primary offset `+264` 沒有 override；004E 的 `+274` 在 `4ADF9D` 明確寫入 `4B3570`。以上不是只搜兩個位移未命中：重驗器分類完整 initializer 中的各項固定寫入，並保留三種 secondary initializer 的完整指令。[原件 `common_primary_initialize`、`mission_secondary_initialize`、`scenario_field_construct`、`tutorial_field_construct`；[完整固定表](field-dispatch-tables.json)]

`4B7D40` 也不是空函式：它直接 tail-call receiver 的 `v+C`。這三張 field vtable 的 `v+C=4227F0`，後者記錄 `Invalid message %d` 並回 `80004005`。因此在正常初始化、這些實際型別且表未被另外改寫的條件下，**普通 Mission／Scenario 收到004C的選定路徑是 invalid；CTutorial 才先命中 writer。** 004E 在三者均 secondary miss 後命中共用 `4B3570`。[原件 `field_secondary_dispatch`、`primary_dispatch`、`primary_default_to_vc`、`invalid_message`；三組 vtable／RTTI]

本結論不推廣成每個可能的 field subclass 都相同，也不排除執行期 table alias／改寫。它已足以排除「普通 Mission／Scenario 只要送004C，就自然更新 Tutorial flag」這個具體接法。

## 4. 004C：從 u16 key 到 Lua number，與真正的 owner

### 4.1 producer 與 map

`4C4F20` 的 native chain 是：

| 原件錨點 | 動作 |
|---|---|
| `4C4F72` | 取 message pointer |
| `4C4F75` | zero-extend message `+2` 的 u16 到 ECX |
| `4C4F7C` | EAX=`FC0F88`，選定容器 |
| `4C4F81/84` | 以該 key 呼 `4C2880` 取得對應 value 地址 |
| `4C4F89` | 寫 DWORD 1 |

本文以 **SCENE_FLAGS** 方便指稱 `FC0F88` 容器；這不是新增 Lua 全域，也不是從字面名稱推導出的資料型別。其 owner 是 `FC0F84`，容器位於 owner `+4`。writer 可見的 application view 為 `[u16 opcode, u16 key]`，需要至少4個可讀 bytes；函式自身未作 body 長度檢查。本分題不因此宣稱上游完全沒有 framing 驗證，也不推定官方每筆封包的總長一定恰好4。[原件 `scenario_end_writer`；[既有 native reader／clear 驗證](../../../shared/verified-knowledge/client-scenario-map-native-reader-and-clear.md)]

### 4.2 正常註冊確實接到同一 owner

startup 的 `48D7D4` 設 ESI=`FDF3C8` 正式 Lua wrapper，`48D7D9` 設 EAX=`FC0F84`，`48D7DE` 呼 `4A88E0`。後者 `4A88EB` 將 wrapper 存在 owner 開頭，再呼 Tutorial namespace registrar `4AA5A0`；registrar 於 `4AA5AB` 保存 FE1804=owner，於 `4AA5B7` 保存 FE1800=wrapper。[原件 `tutorial_startup_owner`、`tutorial_namespace_register`、`tutorial_binding_owner`]

`4A89AA → 4AB940` 是實際註冊呼叫。`4AB958` 將 native getter `4AA510` 放入 FE1880，`4AB998` 推入原字串 `IsScenarioEnded`，`4AB9A9` 推入 C closure target `4ACA40` 並建立 closure。這不是僅因 BIN 有同名字串就認定 API 可用。[原件 `scenario_end_getter_register`、`str_IsScenarioEnded`]

Lua 呼叫的結果鏈完整如下：

1. `4ACA40` 包裝傳入 Lua state，取 FE1880 作 target，於 `4ACA81` 呼 `4ACF90`。
2. `4ACF90` 先讀 FE1804 作 native receiver，再從該次 Lua state 的 stack `-1` 取參數。number 直接轉整數；可轉數字的 string 先轉換；其它值／轉換失敗走 key=0 分支。
3. `4ACFF0` 間接呼 `4AA510`。正常 owner 下，getter 對 owner `+4=FC0F88` 以此 key 呼 `4C2880`，讀出其 DWORD value。
4. `4ACFF8..4AD007` 將返回整數轉成 Lua number，TValue tag 明確是 **3**，並增加 stack top；外層 C thunk 回傳一個結果。

因此它的已證介面是**數值狀態**，不應把 native EAX 或一個名叫 `Is...` 的 API直接當 Lua boolean。Server writer 能提供的 key 範圍是 u16；新內容應使用相同數值 key，並明確比較返回值。FULL-PASS 既有 reader 證據另已閉合：valid container 中缺少 key 時會建立 value=0；這是既有結果，不在此重新聲稱為新發現。[原件 `scenario_end_lua_thunk`、`scenario_end_marshaller`、`scenario_end_native_getter`；同上 shared verified knowledge]

### 4.3 Rebind 與 reset 都不能省略

**FE1804 不是不可變常數。** `4AA647` 把 `4ABBE0` 實際註冊為 `Tutorial.Rebind`：該 thunk 讀 FE1800 的已保存 wrapper，呼 `4A2BB0` 轉換這個 wrapper 所指 Lua stack `-1`，然後在 `4ABBEA` 把 EAX 寫回 FE1804。這裡沒有 current-field lookup，也沒有替 ordinary field 安裝004C secondary writer。若改成不符合此 getter 所需 layout 的值，就不能沿用正常 `FC0F84+4` map 的已驗證契約；本稿不把任意 pointer 替換列為普通場景接法。[原件 `tutorial_binding_owner`、`tutorial_rebind_thunk`、`tutorial_rebind_convert`]

既有 Tutorial start 路徑 `4C4D3A/3F → 4A8A60` 以 `FC0F84` 作 owner，`4A8A87/94` 對 owner `+4` 呼 `823850` 清容器。這只復用已 FULL-PASS 的特定 clear caller，不擴張到全部生命週期。因此有兩個實際後果：

- 新完成通知若早於這次 start／reset 被處理，值可被後來清除，不能只靠「Server 先送了」判定新工作已可觀察。
- ordinary 場景沒有沿004C更新 map，不代表 getter 必定回0；先前殘留的1或 binding 改寫仍是不同問題。讀到1本身沒有附帶當次 instance、run generation 或新的封包身分。

既有 Tutorial 內容中，`RequestStartScenario(14)` 與 `IsScenarioEnded(14)` 的等待循環提供過一個實際使用例；它仍是有型別的 Tutorial 流程。該 key、QuestInfoID、SceneList 的 quest／scene雙鍵與世界 actor/group 身分不能因數值相同就互換。這些既有資料詳見 manifest pin 的 T16-111 報告與 [前稿 events](../../MEF-entry-lifecycle-events-20261114/events.md)，本輪沒有重新掃整份 TutorialMain 當新成果。

## 5. 004E：正向 Server→UI→Lua 橋接及其資訊量

### 5.1 token 存在哪裡、event 帶了什麼

共同 handler `4B3570` 在 `4B3595` 讀 message `+2` 的 u16，`4B3599` 取 `[FE18F8]`，`4B359F` 寫到該物件 `+8`。`506AD0` 的建立片段顯示：配置 `0x38` bytes、安裝 vtable `C0DD64`，`506E4A` 將物件指標寫入 FE18F8；其 RTTI 是 **CScenarioDescData**。這與前節 `FC0F88` Tutorial map 是不同 owner。[原件 `selection_ack_handler`、`selection_native_owner`、`CScenarioDescData_*`]

本稿將該值保留為 **opaque u16 selection token**。另一個既有 UI送出分支在 `6BC0F6/FB` 取同一物件 `+8`，於 `6BC132` 把其低16位放入 C2S0028 的 `+2`；該分支以 length `0x0D` 送出包含選擇內容的 application。這證明它與選擇回傳存在關聯，**不能單靠此結果把 token 改名成 ScenarioID、EntityId、monster group 或完成原因**。[原件 `selection_token_echo`；其 UI 輸入上游不作本輪新增可達性結論]

同一004E handler 在 `4B35D5/DA` 呼 `58AAD0(F43DA)`。helper 配置 `0x14` bytes 的一般 `FXUIEvent`：

| event offset | 完整寫入值 |
|---:|---|
| `+00` | vtable `C47B0C` |
| `+04` | `FFFFFFFF` |
| `+08` | `FFFFFFFF` |
| `+0C` | 0 |
| `+10` | `000F43DA` |

`58AB5F/64` 以 `F95C6C` 為 deque owner 呼 `804260` 追加 event。這個配置大小內的完整 payload **沒有 token、producer page、field、instance 或 script generation**；token 仍留在另一個 native 物件中，不能假設已隨 event 傳給 Lua。[原件 `enqueue_generic_ui_event`]

### 5.2 consumer 選的是當時的 current page

前輪已從真正 UI update 閉合：`58A250` 先消費 pending page，後經 `750550` 呼 queue pump `74F000`；後者逐筆重新讀 engine `+13C4` current page，再呼 page `v+15C(event)`。queue 追加不在當下執行 callback；current page 為空時也有 skip／丟棄的不同 gate。這裡復用該完整結果，不把相同 queue pump 再計為本輪新發現。[前輪 UI lifecycle §3.2–3.4](../../MEF-runtime-contracts-20261115/ui-lifecycle/report.md)

已核 page 的 `v+15C` 是 `595D20`。它將 `F435C < event < F4442` 送到 `v+198`，所以 F43DA 進入下面的具體 receiver：

| 實際 page | factory code／vtable | `v+198` | 對 F43DA 的已核選取 |
|---|---|---:|---|
| `CMissionLobbyPage` | state `4`／`C1D9A4` | `5B0720` | 先呼 `5B7F80`，選到 `5B8177 → 5B96E0` |
| `CTutorialPage` | state `0xF`／`C1F5F4` | `5C3370` | `5C3383/88` 比較，選到 `5C33A1 → 5C3610` |
| `CMissionFieldPage` | state `5`／`C1D1AC` | `5AD630` | base default 後，其額外 comparisons 均不匹配，返回 |
| `CScenarioFieldPage` | state `7`／`C1D62C` | `5AFE70` | base default 後，其額外 comparisons 均不匹配，返回 |

state4／0xF 的 factory 不是由類名猜測：`587A68` 安裝 MissionLobby vtable，`587ABE` 以 key4 插入；`588076` 安裝 TutorialPage vtable，`5880D8` 以 key0xF 插入。普通5／7 factory 身分復用前輪完整證據，本輪另核其 `+198` 指標與 handler。`CLobbyPage` 原生表 `C1EF14+198=5B7F80` 及 RTTI 同樣保存，並以 MissionLobby 的明確 factory／base call 接上，沒有從「Lobby」字面擴張到所有 UI 型別。[原件 `mission_lobby_factory`、`tutorial_page_factory`、四個 page handler、對應 vtable／COL／type records]

三個需要精確算出的 switch 如下。每個 index byte 與 target DWORD 都直接從 BIN 讀出：

| 函式 | F43DA 的計算 | 原件 byte／target | 結果 |
|---|---|---|---|
| `5B7F80` | `F43DA−F4364=76` | `[5B84D6]=1F`；`[5B8410]=5B8177` | Lobby 的正向 OnYes case |
| `59BD80` | `F43DA−F4361=79` | `[59C145]=1A`；`[59C0C8]=59C057` | common base return |
| `5A4310` 第二張表 | 第一個 range 以 F43DB 起算，F43DA 不在範圍；第二次 `F43DA−F4366=74` | `[5A44D0]=09`；`[5A4458]=5A43F0` | 更底層 base return |

`5B7F80`／普通 page 均會先進 `59BD80 → 5A4310`，所以這兩層 default 也一起核對，避免只看最外層 case 就漏掉 base副作用。對普通5／7 page的結論，限定於這個 event、這些固定 receiver 的完整選定 CFG。[原件 `base_page_dispatch_prefix`、`base_page_default_return`、`base_page_second_dispatch` 與三組 selected-index／target；[routes.json](routes.json)]

### 5.3 Lua 收到的是零引數通知，不是 typed key

Lobby 路徑 `5B9742`、Tutorial page 路徑 `5C3672` 都呼 `4AD0A0`，參數是正式 wrapper `FDF3C8`、wanted-results=0、固定名稱 `OnYesTriggered`。**wanted-results 不是 argument count；真正零引數來自前稿已核 `4AD0EF` 的 push0／`4AD0F3` protected-call。** 此處沒有把004E token 或 UI event pointer 推進 Lua 引數。[原件 `lobby_yes_callback`、`tutorial_yes_callback`；[既有 wrapper ABI](../../MEF-trigger-callers-20261115/named-calls/report.md)]

`4AD0A0` 仍要在該 VM 的 globals 查到可呼叫函式才會執行。若正常 qbase 已載入且定義未被改寫，其原件結果為：

| qbase 全域 | root 綁定 | body／結果 |
|---|---|---|
| `OnYesTriggered` | PC24 CLOSURE → PC25 SETGLOBAL，proto5 | 讀全域 `TRUE`，存入 `g_yesTriggered`，返回 |
| `CheckConfirmMessage` | PC52 → PC53，proto19 | 先看 `g_noTriggered`；若其不等於 `FALSE` 回0。否則 yes不等於 `FALSE` 才回1，其餘回0 |
| `OnEndTalk`，僅作既有語義對照 | PC32 → PC33，proto9 | 存 `g_scenePlaying=FALSE`，返回 |

此三個 body 都沒有 CALL／TAILCALL，不會自行讀 `.mef` 或執行下一個場景函式；要接續新內容，必須已有腳本工作讀旗標並在其合法 runner 上繼續。它們使用可變 Lua globals；本稿不假定先前 flag必定已重設，也不假定原版 body永不被替換。[Event 原件子集：[lua-evidence.json](lua-evidence.json)；既有 [script-consumers](../../MEF-trigger-callers-20261115/script-consumers/report.md)]

`Event/qbase.lua` 在原 carrier 的 block id為7378，stored raw offset `10618896`、length11836，還原 SHA-256 `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3`。本輪重驗只解析這個 member與上述三個 proto／root bindings，沒有重掃整份 Event資源，也沒有執行 bytecode。

兩個 native OnYes caller在 Lua call之後還會呼 `596E00`，再排 `F4358`。因此這不是純粹、不帶其它副作用的「遠端設旗標API」；採用原有 UI橋接必須保留適用 page與原有 UI流程。[同一 callback 原件窗]

## 6. 哪些情境已可成立，哪些仍不能借用

| 目標情境 | Client 已證能力 | 尚須滿足的實作條件 |
|---|---|---|
| Tutorial內，Server完成某個已知 scenario key後讓腳本繼續 | 004C在CTutorial寫1；正常getter可讀相同key的Lua number | Server保持對應流程／key；腳本已啟動且runner有效；通知不能被本次reset覆蓋；不以舊值認作本次完成 |
| 已核 MissionLobby／Tutorial page 中的既有確認流程 | 004E可排F43DA，正確currentpage會到零引數OnYes；既有qbase可供後續讀yes flag | queue消費時仍是適用page、callback已存在、yes/no初態與流程一致；保留UI後續效果 |
| 普通Mission／Scenario field用004C等待死亡或清組 | 本輪已證selectedroute落invalid，無此writer | 不能採這個接法；若需ordinary observer，須找真正適用的既有入口／getter，或列出必要的Client整合工作 |
| 普通戰鬥page用004E當通用wave完成通知 | native token寫入／queue仍存在，但普通5／7page不呼OnYes | 不能把「commonhandler存在」寫成ordinaryLua可見；page改換不是免費的背景事件介面 |
| 透過OnYes取得是哪隻actor、哪一組、哪一代run完成 | callback固定零引數，flag為共用global | 沒有形成typed identity／原因契約，額外未讀payload也不能自動補出Lua引數 |
| 從原生死亡畫面推定Lua已被通知 | 前稿000C／FSM死亡表現已有證據 | 本輪兩條事件鏈沒有補成ordinary死亡observer；不重列舊死亡鏈當新發現 |

這裡的可用情境指**已經有腳本被合法載入並排程後**，如何觀察既有事件。004C與004E都不是原版 `.mef` 內容傳輸／parser入口；成功到達 Lua 旗標也不等於新內容已完成首次載入。

## 7. Server 開發需求與後續有界分析

Server應實作的工作可以明確列出，無須等待取得官方Server原件：

1. **事件與內容的對應狀態。** 保存當前 instance、內容鍵、等待階段與接受條件。004C只有u16 key／map值；004E的Lua通知沒有typed key。由Server狀態管理重複、遲到與跨run事件，不在Client未讀的欄位中假裝已有generation保護。
2. **接收 owner與排程。** 使用004C時確認合法Tutorial流程；使用004E時遵循已核UI流程與page時序。場景初始化、page pending消費、event dequeue及腳本runner是不同環節，不能只用固定延遲把它們視為ready。
3. **結果讀取與reset。** 內容明確讀數值getter／yes-no結果並規範每次初態。要處理reset覆蓋、no優先、callback不存在／被改寫及runner已停止等情形；不能把共用global當帶instance身分的事件紀錄。
4. **ordinary功能若要下放，先定義所需observer。** 針對死亡、清組、互動或目標完成，要求來源、actor/group身分、完成值、重複語義及取消界線。004C／004E本輪結果不能滿足該通用typed observer；後續逆向應只追實際缺少的機制，與同輪 [identity](../identity/report.md) 的世界ID契約、[runner](../runner/report.md) 的可用tick owner合併評估。

仍屬Client有界待查的問題，是**普通場景是否另有符合所選功能的有型別observer／callback或可用getter**，以及必要的動態receiver型別。Server的事件規則、內容發布與合法狀態機則是開發需求；兩者不混列成「缺Server資料所以不能分析」。本輪已完成的004C／004E分派不需再重做，舊DoFile／Lua caller清冊也不是這個缺口的答案。

## 8. 唯讀重驗與最小交付

本包為10個檔案：本報告、native JSON／asm、field tables、routes、Lua子集、read-set、source manifest、verifier、verification result。最小發布包不複製57份導航 `.c`；其原始bytes在採集時逐一與固定Git blob及SHA-256對上。

有限集合是 **96個原件records、6,343 bytes、41個code windows、1,458條decoded instructions、9組具體RTTI／vtable、3組精確switch選取、35個selected direct-call operands、3個既有qbase proto**。原件window可能重疊，這些數字不是新函式數或全程式call graph。來源pin共70筆，其中57筆是導航檔；其餘為明列範圍的既有分析／靜態parser來源。

在repository root執行：

```sh
python -B kr-extra-roy/MEF-world-integration-20261115/events/verify_evidence.py \
  --bin /absolute/path/to/02-Tartaros.bin \
  --event-stp /absolute/path/to/06-Event.stp \
  --repo .
```

同輪wire預設位於 sibling `../wire`；若由scratch重驗，可加 `--wire-dir /absolute/path/to/wire`。有採集時導航原件者，可加 `--sources /absolute/path/to/sources`；不提供時輸出明確區分「Git tree身份已核」與「導航內容未重新提供」。

重驗器只讀原件與檔案、離線讀指定Git tree，不fetch、不checkout、不寫repository；解析Lua作資料，不執行Lua。它檢查BIN／STP全檔identity、PE raw映射、各window與指令邊界、完整固定table stores、selectedslot/default、vtable／RTTI、switch、owner／marshal／callback anchors、qbase原member與三個body、70個版本來源，以及同輪wire五個frontend原件窗與004C／004E查詢。成功結果stdout為JSON，固定 `status="PASS"`，範圍另註bounded static。[verification-result.json](verification-result.json)

PASS支持本報告的有限bytes與資料流可重現，不提供網路時限、任意runtime改寫、所有dynamicreceiver、或實際遊玩驗收的保證。
