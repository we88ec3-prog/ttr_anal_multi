# `.mef` 可用的世界角色、NPC、外觀與商店互動能力

日期：2026-11-16。這是 R11 的 world／NPC 分題，重點是**已載入腳本能驅動哪些 Client 功能，以及把這些功能組成可互動 NPC 時還須接上哪些既有資料與服務**。原件裁決為 `02-Tartaros.bin`，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；Table 原件 SHA-256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。本輪未執行 Client、Lua 或 Server，未修改原件。

## 1. 可以做到什麼

**可以用腳本擺放世界角色／NPC 外觀、安排 Q 角色走位與動作、換用模型支援的 avatar／掛件、控制面部動畫及閃色，也可以切換已存在互動點的啟用狀態。** 商店則已有完整的「互動點 → 商店與 NPC 表 → 對話選單 → 買賣／強化視窗 → 請求與結果」Client 流程，能作為新內容的整合基礎。建立一個模型與建立這條服務流程，是需要分別準備的兩部分。[本包 `contracts.json` 的五條鏈；原件 `lb_create_ex`、`doll_apply`、`q_ani` 至 `q_flash`、`checkpoint_market_interaction`、`open_trade_consumer`、`open_enhance_consumer`]

| 想做的內容 | 已有可用能力 | 必須帶入的條件 |
|---|---|---|
| 在世界某處放角色／NPC | `lb.CreateObject`、`lb.CreateObjectEx` 實際配置角色，設定 XY、方向、模型及 scale，加入世界索引 | 模型必須有有效資源；新增物件使用本地 entity counter，Lua 呼叫沒有新推入 entity ID |
| 做可精確指名的演出角色 | `Q.CreateObject` 使用腳本給定 slot；可走位、瞬移、轉向、換動作、換表情、閃色 | slot 屬 Q 索引；動作／模型依賴須與預掃描及正式載入一致 |
| 更換已有世界角色外觀 | `lb.SetActorAvatar`、`AttachActorItem`、`DetachActorItem` 接到實際 CDoll 重建與 render consumer | 要有正確世界 entity key、有效 CDoll，以及模型支援的 avatar／掛件 descriptor |
| 放 Tutorial 的 Isilia | `Tutorial.InsertIsilia()` 依固定 layout 資料建立角色 | 固定 model 4、world ID `F000`、layout key 3；它不是任意 NPC 建立器 |
| 控制 NPC／商店互動是否可用 | `Tutorial.SetCheckPointStatus(key, category, status)` 改既有點的 `+105`，互動判斷會讀它 | 互動點須先存在；category 2 的 key 是 ShopNo，category 3 的 key 是 NPC key |
| 開啟既有商店買賣／強化功能 | 已有互動、NPC 選單與 UI 路由，可沿原版服務流程使用 | 正確 ShopInfo／NPC／Town／PRODUCT、適用頁面及 UI context；操作結果還需要 Server 交易與資產更新 |

這些能力來自已確認的 Lua binding 與 native consumer。它們不依賴把普通戰鬥完整改由 `.mef` 執行。本稿也不把「檔名以 `.mef` 結尾」當作自動載入保證；**腳本首次可達入口與資源載入，使用既有 bridge／loader 契約另行整合**。[固定前稿 `MEF-content-contracts-20261116/bridge/report.md`；來源完整固定於 `source-manifest.json`]

## 2. 三種角色容器，各有適用用途

| 容器／API | 具體物件與索引 | 適合用途 | 不應混用的識別碼 |
|---|---|---|---|
| `lb.CreateObject[Ex]` | 依 model 數值分類配置 `CPlayer`、`CMonster`、`CNPC`，加入 world owner `FAB130` 的 tree | 世界擺設、已知模型的本機 NPC／角色表現 | model ID、world entity ID、ShopNo 是不同欄位 |
| `Q.CreateObject` | 每個 model 類別都配置 `CEventActor`，由 Q owner 的 full DWORD slot 索引持有 | 場景演出、可指名的多角色動作與走位 | Q slot 不等於 world entity ID；兩個索引不共享同值身分 |
| `Tutorial.InsertIsilia` | 配置基底 `CActor`，固定 world key `F000` | 原 Tutorial 固定角色與 layout 流程 | 固定 key、模型 4、layout key 3 不是三個可自由替換的 Lua 參數 |

world `CNPC` 的 vptr 是 `C0CA9C`、RTTI 原字串 `.?AVCNPC@@`；Q actor 的 vptr 是 `C0C824`、RTTI 為 `.?AVCEventActor@@`。渲染物件是 `IS3D::CDoll`，vptr `C4F67C`。本包只把 `contracts.json` 列出的已核 method offsets 視為方法槽，沒有把相鄰 COL metadata 擴成方法。[原件 `npc_ctor`、各 `vtable_* / col_* / type_*`；Q 建立契約復用 `MEF-content-contracts-20261116/actors/{report.md,contracts.json}`]

### 2.1 `lb.CreateObjectEx` 的精確參數

正常 binding 是 `4A1830` 寫 native target `4A0F70`，Lua closure `4A2010` 接 conversion `4A25F0`。恰好六個參數時：

```text
lb.CreateObjectEx(model, x, y, scale, direction, attach)
```

| 位置 | conversion／native 用法 |
|---:|---|
| 1 model | 數值轉 signed DWORD；先按 signed 範圍選型，再把 low WORD 與類別 byte 組成 actor model key |
| 2、3 x／y | Lua number 或可轉數字字串轉 float32，交 actor `v+44` 位置 setter |
| 4 scale | 數值轉整數，乘既有全域倍率後交 `v+5C`；setter 存 actor `+B4`，再按既有倍率轉交 render object |
| 5 direction | 數值轉整數，`v+58=4C8C30` 消費 low BYTE，寫 actor `+B0` |
| 6 attach | 數值轉整數；非零會將新 actor 交給目前 controller 的 hook。這不是商店／互動點的附加選項 |

`lb.CreateObject(model,x,y,attach)` 只有四參數；原件 `4A0B40` 明確等同呼 `Ex(model,x,y,12,0,attach)`。不要把第四參數當 scale，也不要把方向值直接說成角度或把 XY 單位說成公尺；本輪沒有取得這種單位保證。[原件 `lb_create_wrapper`、兩個 create marshaller、`lb_create_ex`、`actor_direction`、`actor_scale`]

`lb` 的這一條分類是 **model < 10 → CPlayer；10 ≤ model ≤ 10000 → CMonster；model > 10000 → CNPC**。這是本地 native 分支，不是模型有效性檢查。Q 的 model 分類有自己的範圍，且不論類別都配置 CEventActor，不能把這個 `lb` 分支表套到 Q。[原件 `4A0FA3..4A103C`；固定 actors contracts 的 Q classification]

### 2.2 建立後怎樣到達畫面

`4A0F70` 建立 CNPC 後，寫 `WORD actor+04`、設定位置與方向、呼 `v+3C` 保存 model、呼 `v+30` 初始化表現，最後經 `4DFF30` 加入 world tree。**CNPC 的 `v+30=4D2820 → 4C7DF0(actor,1)`**；後者配置 `0x170` 的 CDoll，依 model low WORD 初始化並把 shared object 接到 actor `+15C/+160`，再設定 transform、avatar 與 motion。這個非零參數使 CDoll `+20=1`，立即提出模型工作，走 `7A8E70` 的 event／wait 路徑；CNPC 隨後還更新任務標記。基底／Q 的 `v+30=4C8050` 則傳 0，不能拿它代替 CNPC 的實際方法。[原件 `lb_create_ex`、`actor_model_id`、`npc_initialize_doll`、`actor_initialize_doll_entry`、`actor_initialize_doll`、`doll_ctor_prefix`、`doll_update_enqueue`；world register 的索引／duplicate 契約復用 R9]

本輪繼續追到既有普通世界 consumer：`4925A5 → 4E0200(FAB130,delta)` 先套用已完成模型工作，再逐 world tree node 的 `+10` actor 安排更新；`AnimateExecuter` 首槽 `4E0520` 呼 actor `v+24(delta)`。pool worker `6EE540` 從同 pool 的 executor `+38` 與每個十二 bytes slot 的 actor pointer 取回工作。對 CNPC，`v+24=4D28C0` 在其既有節流條件容許時接 `4C87D0 → 7A5C50`。draw 路徑 `4E0540 → 4E1470` 呼 actor `v+28`，CNPC 再接 common render → CDoll `v+8=7A63C0`。[原件 `frame_world_animate`、`world_animate`、`world_animate_executor`、`actor_pool_worker`、`npc_slow_tick`、`actor_doll_tick`、`world_draw`、`world_draw_iterator`、`npc_draw`、`actor_doll_draw`、`doll_draw_main`]

因此建立世界 actor 的正向結果包括模型表現與世界更新。CNPC render 依 packed model key 取顯示名稱，另以 model 的 low WORD 查 NPC 表的附加文字；其 update 還會用 NPC key 查既有任務資料並更新提示標記。這些都是既有資料驅動的效果，並不表示腳本已新增一份 NPC 對話、任務或商店規則。[原件 `npc_draw`、`npc_tick`、`npc_quest_marker`；本輪沒有將任務標記狀態當作新增任務／任務完成 API]

### 2.3 操作剛建立的 world actor 要處理身分契約

本地 counter `F7DE04` 的 low WORD 被寫入 actor，之後 counter 的 DWORD 加一；world tree 使用由 actor WORD ID 取出的 key。create 的 Lua conversion 沒有在 native call 後推入新 entity ID。故可以直接用 create 放置物件，但不能憑 `id = lb.CreateObjectEx(...)` 宣稱已拿到可供後續 avatar API 使用的穩定 handle。作者若需要明確的多角色演出身分，Q slot 已有直接契約；若要改世界角色，須有已成立的 world entity key 來源。[原件 `lb_create_ex`、`lb_create_ex_marshaller`；固定 R6 identity]

這裡不採用推算 counter、猜 pointer、ReadMemory 或 Rebind 來補成公開能力，也不因此否定已證的角色建立效果。

## 3. 外觀 API：已追到模型重建與 draw

三個 `lb` 外觀入口均先對 **world tree** 做 full DWORD entity key lookup，命中才操作 actor；它們不是拿 model ID 或 Q slot 查同一個物件。需要 actor `+15C` 有 CDoll，且 `+370` 表現已啟用。[原件 `lb_avatar`、`lb_attach`、`lb_detach`]

| API，均須精確參數個數 | 實際更改 | 資料域與條件 |
|---|---|---|
| `SetActorAvatar(entity, part, variant)` | 把 variant low WORD 寫 actor `+388`；CDoll 的 `+4C` map 以 low WORD part 作 key、low WORD variant 作 value | 已有模型資源且其 `+BC==0` 時，CDoll helper 直接略過 map 更新；相同值可直接返回；variant 0 會移除選擇 |
| `AttachActorItem(entity, appearanceItem)` | 以 appearanceItem low WORD 與 actor-model low WORD 查 render descriptor；有 model-specific／common fallback；把 item key 存到 descriptor `+20` 指定的 attachment key 下 | `lb` 固定另外兩個 helper 參數為 0。缺 descriptor 不會憑空產生掛件；這是模型掛件資源，不是 PRODUCT／背包授予 |
| `DetachActorItem(entity, attachmentKey)` | 從 CDoll `+5C` map 移除 supplied DWORD key，並處理 key+`0x10` | 第二參數是 map 的 attachment key；不能只因名稱成對，就把 attach 的 item ID 原樣拿來 detach |

avatar map 的 unsigned WORD compare／value store，已核 `7A0B10`、`7A0A90`；attachment map 使用 DWORD compare。`SetActorAvatar` 的 actor `+388` 寫入與 CDoll 的條件分支分開保存：不能看到前者已改，就宣布所有 NPC 的外觀都已換好。[原件 `doll_avatar`、`avatar_map_find`、`avatar_map_insert`、`doll_attach`、`doll_attachment_replace`、`doll_attachment_find`、`doll_detach`]

### 3.1 更新鏈的真正下游

1. avatar／attachment 變更把 `CDoll+28` dirty byte 設一。
2. `7A5C50` 只有在 dirty 非零，且 load state `+24` 不是 2／3 時，呼 `7A8E70`。後者把目前 model key、requested avatar map、requested attachment map 複製到 `0x74` request；清 dirty、設 load state 2，再送 `FC0E90` manager 的 `+28` queue。
3. worker 把同一 queue 取出，`79E980` 查 model catalog。有效資源分支透過 `79FBC0` 以 `(part<<16)|variant` 尋找 model avatar descriptors，合併明確要求的掛件，再由 `79EFC0` 建立準備套用的模型／掛件。選定掛件被具體化為 **`IS3D::CItem`**，不是背包 slot。
4. immediate 分支或 frame drain `79DB10` 都接 `7A90F0`。有效結果會把模型指標、active attachment map、face controller 與動作狀態套回同一 CDoll；成功分支把 load state 設 1。無有效結果分支清模型／face pointer 並設 state 3。
5. CDoll draw `7A63C0` 在模型、可見性與資源準備條件成立時，呼目前模型與 active attachments 的 render methods。

這條鏈證明 API 會驅動真實 native 表現流程；它不保證任意 ID 都有資源、請求立刻完成或每次呼叫都必定有畫面變更。載入失敗、尚在 state 2、特定模型不支援 avatar、畫面 gate 未通過，都保留在已見分支中。[原件 `doll_tick_dirty`、`doll_update_enqueue`、`doll_enqueue_manager`、`doll_worker_take`、`worker_queue_branch`、`worker_doll_process`、`doll_worker_process`、`doll_prepare_avatar_items`、`doll_item_materialize`、`doll_apply_deferred`、`doll_apply`、`doll_draw_main`]

## 4. Q 角色可以演哪些動作

Q 的建立、Move／Walk／Warp／Stop、停止等待及 Show 先前已有正向 consumer；本輪增加核對身體動畫、播放位置、方向、速度、面部與 flash。這使「用已知模型演一段 NPC 場景」有更完整的操作表。[固定 actors／observers／bridge；本包 `Q-actions` chain]

| direct Q API | 實際作用 | 不能混淆的語意 |
|---|---|---|
| `Q.AniObject(slot,motion,rate)` | 整數 motion 經 actor `v+68` 存 `+38C`，CDoll 存 action `+A8` 與 float rate `+104`，選動作並在 update 用 rate×delta 推進 | rate 是身體動畫倍率；不是第三個布林 loop 旗標 |
| `Q.AniSkip(slot,step)` | step 為整數，除目前 `[FBA7CC]+1360` 設定後，加到動畫位置；`7A6830` clamp 並套用目前 motion | 不是可任意解讀為毫秒的等待；也不是場景 skip |
| `Q.RotateObject(slot,direction,smooth)` | direction 取 low BYTE；smooth=0 走 immediate rendered-yaw 路徑，仍有 actor `+3A8`／render gate；非零保留 common direction update | 方向是 byte 域；本輪不把它寫成 degree |
| `Q.SpeedObject(slot,multiplier)` | float 倍率寫 `CEventActor+434`；movement `v+60` 消費它 | 與 AniObject 的動畫 rate 是不同欄位 |
| `Q.FaceObject(slot,faceId,duration)` | actor `v+6C` 要求 CDoll `+A0` 面部 controller；face ID 查其資源；duration<0 使用資源值，非負整數轉 float 覆寫 | 這是面部動作／表情，不是讓角色面向另一 actor |
| `Q.FlashObject(slot,mode,ticks)` | 寫 actor `+40C` mode、`+410` duration、`+414` counter；common update 呼 `4C9140` 作已知模式的顏色／透明度處理並遞減 | ticks 由 native update 消費，不是固定毫秒，也不是傷害／狀態效果 |

各 Q target 都先查 Q slot；不存在的 slot 或空 actor 會返回，不會替作者建立角色。新增三整數 APIs 的 shared conversion 是 `56A4B0`，AniSkip 是 `56A220`；AniObject、SpeedObject 的 float conversion 分別是 `56B0E0`、`56B210`。[原件 selected registrars／closures、`q_*_marshaller`、`q_ani` 至 `q_flash`、`actor_ani`、`doll_ani`、`actor_direction_tick`、`event_actor_speed`、`actor_flash_tick`]

Face 的下游已核：`4C9550 → 7D6730` 設 face key、duration、counter；CDoll update 呼 `7D65A0`，以 `delta×30` 推進資源狀態及 skin values。準備模型的 consumer 明確查 **`Face.SKIN`**。這足以把它歸為面部動畫能力；本輪沒有宣稱所有模型都有同一 face ID 表，也沒有把覆寫值說成毫秒。[原件 `q_face`、`actor_face`、`face_select`、`face_tick`、`doll_tick_motion_face`、`doll_face_skin`、`Face_SKIN_string`]

### 4.1 作者要選定 direct Q 或 global wrapper

上述表格列的是 `Q.*` native 層。原版 global wrapper 有額外參數轉換與 yield，例如 global WalkObject 七個參數轉成 direct Q.WalkObject 的六個參數，還會把 speed step 轉倍率。尾端相對 Lua stack 索引代表多加參數會移動讀取窗口；numeric gate 應使用數字 0／1，不能把 Lua boolean 的轉換假定成整數。[固定 `observers/report.md` 的 P25／P26；本包各 numeric marshaller]

清理也須用已證能力：**正常 `Q.DeleteObject` target 是 `476430` 的 stub，不是單物件刪除功能。** `Q.DeleteAllObject`／既有 ClearObjects 才有已證的批次清理流程。ShowObject 只改呈現 gate，不等同停止 actor 的 native 更新。[固定 actors/report.md、R10 control-flow 主線；本輪不重做刪除研究]

## 5. Tutorial 的固定物件與互動點控制

`InsertIsilia()` 查 Tutorial layout key 3，配置 `0x420` 的基底 CActor，設定 world ID `F000`、model 4、layout XY、direction 0、avatar 1 與初始動作。這可直接用於已知 Tutorial 佈置；它沒有 model／位置形參，不能改名為通用 NPC spawn API。名字含 InsertObject 的另一正常 Tutorial binding 仍是已知 stub。[原件 `tutorial_isilia`；固定 R9 world report]

`SetCheckPointStatus(key,category,status)` 則是可組合進事件流程的既有能力：`4A9460 → 544940` 在 point vector 內找 category+key，`543B30` 寫 `+105`，`544730` 的互動 gate 讀同一 byte。key 以 WORD 比對；category 經 signed BYTE 擴成 WORD；status 消費 low BYTE。找不到既有點時不會新增點。[原件 `tutorial_status`、`checkpoint_status_lookup`、`checkpoint_status_write`、`checkpoint_interaction_gate`]

選定 producer `S2C 0027 → 4B2AF0` 會先清舊點，再將每個 18 bytes row 交 `543700`，建立 category、key、XY、radius 與 enabled 等欄位。另一已知 Tutorial 插入路線的 ctor 類別固定為 4。**本稿有界地分開「現有點的狀態修改」與「放置 category 2／3 互動點」；沒有把同名 status API 擴成任意 NPC／商店點建立器。** [原件 `checkpoint_packet`、`checkpoint_ctor`；固定 town-npc 的兩條 ctor caller；未作全程式不存在其他間接 caller 的宣稱]

## 6. NPC 到商店 UI：既有正向流程

11/09 的 town-services 研究已把服務鏈接到具體 UI、request 與資產更新。本輪以固定 Git 內容復用其完整 caller 關係，並重新從 BIN 擷取下列關鍵 consumer；表格不把 UI event 數值當可任意呼叫的 Lua opcode。[來源 `governance/client-variants/20261109-mef-town-services/{town-npc.md,shop-services.md,shop-asset-sync.md}`；本包 `source-manifest.json`]

| 階段 | 已核資料流 | 對內容作者的意義 |
|---|---|---|
| 已存在 category 2 互動點 | point `+F6` 作 **ShopNo**，`544491 → 4FB910` 查 shop row | category 2 的 key 2 表示 shop 2；不能直接填 NPC 10030 代替 |
| ShopInfo | NO／TOWN／TYPE／NPC 分別存 row `+0/+4/+8/+C` | 配置商店與指定 NPC 分開於可見模型的 entity ID |
| 找對話 NPC | `5444AA` 由 row NPC 查 NPC 表；有 TALKSET 才建立 `F4388` 事件 | 服務對話使用既有 NPC 資料，不是 CreateObject 的 model 名稱 |
| 顯示對話 | `5B7F80` 的 F4388 路由 → `5B6B70 → 636520` TalkBox mode 0 | 需要對應頁面與 typed event／context |
| 選商品 | TalkBox／trade 路徑以 **current Town + NPC** 查 `4FB960` | 別的 town 的 ShopNo 能進前段，不保證後面的商品查找成立 |
| 選單 | NPC TYPE 選 menu；shop TYPE 1..4 可令 NPC TYPE 成為 11..14 | 正確 TYPE 讓原版服務選項出現 |
| 強化 | NPC TYPE 12 的 operation 29 → delegate `639EF0` → F42F6 → UI owner `+264` | 已有開 `CShopLevelupWnd` 的具體正向路線 |
| 買賣 | operation 4 → `6392A0` 發 F42EA → `5B8540` 保存 context、顯示 trade window | 顯示後仍會按 shop TYPE 走既有服務請求 |

普通 category 3 NPC 互動也可建立同一 F4388 對話事件。這表示 world actor 外觀與 interaction point 可以協同組成 NPC 場景；不應把只有外觀、沒有合適 category/key/context 的物件當成已完成商店。[原件 `checkpoint_npc_interaction`、`checkpoint_market_interaction`、`shop_lookup_key`、`shop_lookup_town_npc`、`shop_parser_fields`、`shop_type_to_npc_type`、`town_talk_consumer`、`town_talk_dispatch`、`talkbox_menu_type`、`menu_blacksmith`、`menu_enhance_delegate`、`menu_click`、兩組 `open_*`]

### 6.1 腳本能否直接傳一個 UI 編號就開店？

本包沒有宣稱有任意通用 `Tutorial.PostUIMessage`。已固定的正常 Tutorial public surface 是兩個專用入口：EmployChar 送固定 F431F、TutoMsg 送固定 F43FD；它們有自己的 payload 與頁面 consumer。它們不能因底層存在 generic UI router，就被改寫成可任意發 F42F6／F42EA 的公開 API。現在已證的商店開啟路線，是上表的既有 checkpoint／NPC menu 流程。[固定 R10 runner report 的 B06/B07、U01–U07]

若新內容要自動直接開服務窗，須再取得實際公開入口、typed payload、頁面與 service context 的完整契約；這列為 **Client 待逆向／跨功能待整合**，不假造 script 函式或要求 Server 猜一個 UI message。

## 7. Town1 有哪些可用資料：原件重驗範例

本輪重讀 Table STPD／EX，只保存選定列與 metadata。Town1 roster 是 `10001,10002,10003,10008,10013,10014,10015,10047,10048`；它列 NPC IDs，沒有給出本報告可用的官方 XY 配置。ShopInfo 的 Town1 有五店、42 筆 direct PRODUCT declarations：[原件 member SHA／sector locator 與選定值見 `resources.json`]

| ShopNo | TYPE | NPC | NPC TYPE | PRODUCT declarations | 在 Town1 roster／ActorList category 6 |
|---:|---:|---:|---:|---:|---|
| 1 | 1 | 10028 | 11 | 5 | 否／否 |
| 2 | 2 | 10030 | 12 | 27 | 否／否 |
| 3 | 3 | 10029 | 13 | 3 | 否／否 |
| 4 | 4 | 10031 | 14 | 6 | 否／否 |
| 70 | 7 | 10013 | 1 | 1 | 是／是，FILE=`00_Ertale` |

五個 NPC 都有 TALKSET。前四個服務 NPC 的 table／menu 存在，卻沒有 category 6 模型列；因此 `lb.CreateObjectEx(10030,...)` 雖會走 CNPC allocation，**不能僅據此宣布已可顯示鐵匠 10030 的模型**。相對地，category 6 的 10047／10048 有不同 FILE `01_Yuri01`／`01_Yuri02`；可作有 catalog 依據的角色外觀候選。FILE 列存在仍只是 catalog 事實，實際 archive 載入與畫面結果須待遊玩驗證。[`resources.json` selected_category6_models 與 Town1 join；固定 town-npc]

這些差異給了內容規劃具體選擇：可先選有資源的 NPC 外觀安排演出；若要承接既有商店服務，另外對齊 ShopNo、NPC table、互動點及 UI context。不能把 ShopNo／model／entity 三個值因同為數字而合併。

## 8. 買賣與強化的 Server 開發需求

Client 已提供輸入、確認、請求送出、結果提示與資產呈現機制。Server 的工作是實作這些服務的權威規則及相容回覆；這是商店功能本來需要的分工，不是要求 `.mef` 取代 Server。[固定 shop-services、shop-asset-sync；本包選定 request/result windows]

| 使用者操作 | 已核 Client 發送／接收 | Server 待開發 |
|---|---|---|
| 開一般 shop TYPE 1..4 | trade window 查 Town/NPC 後送 C2S `001C`，category 2 與 ShopNo；TYPE 5..7 另有 `0086` 分支 | 驗證目前地點與可用商店，建立正確服務 context；不能把所有類型都套一般商店 |
| 買商品 | C2S `0027`：opcode WORD、context BYTE、product DWORD、quantity BYTE | 驗證商品／數量／資金／背包，提交貨幣與物品變動，再發相容結果與資產更新 |
| 賣商品 | C2S `0020`：opcode WORD、bag kind／slot／quantity 三個 BYTE | 驗證 slot 與可販售物，計價並提交狀態；不能只回成功文字 |
| 裝備強化 | 已有確認 → `4A3BF0` 的 C2S `00A1`，10 bytes；S2C `00D9` 轉 F427C，再交 `686F40` 顯示結果 | 定義並實作相容的資格、消耗、成功／失敗／損壞與裝備變更；詳細欄位沿固定 11/09 設計，不將其他合成服務混為 00A1 |
| 更新玩家看到的資產 | S2C `002C → 509CE0` 寫 LeeLoo／BattlePoint，再按 17 bytes records 建立／清除 bag slot，並刷新 UI | 讓交易結果與最終資產一致；容量／初始 bag 另有既有 `0029` 路徑 |

S2C `0030` 的 buy／sell bits 與 success bit 是結果提示分支；強化成功 UI／音效同樣不是 item commit。實際資產同步另有 `002C` 等既有狀態更新，Server 必須提供相容的狀態結果。[原件 `trade_open_request`、`trade_context`、`buy_request`、`sell_request`、`enhance_request`、`trade_feedback`、`enhance_result_bridge`、`enhance_result_ui`、`asset_update_balance`、`asset_update_slots`]

其中 context BYTE 也不是 NPC ID：已核 `681E10` 的一般型別預設 context=1，TYPE 6→3、TYPE 5→4。具體商店資源與 Server 業務規則須一起驗收，不能把同一 serializer 的存在當作所有商店都已相容。[原件 `trade_context`；固定 shop-asset-sync]

## 9. 目前完成度與精確待辦

**本分題已把正向能力推到實際作用**：world actor 建立 → CDoll 與更新／draw；avatar／item 修改 → request／worker／apply／draw；Q 動作 → 各自欄位與 animation／movement／face／color consumer；checkpoint enabled → 互動查表 → 對話及商店 UI；既有買賣強化 → request／結果與資產呈現。新的內容作者可以據此決定哪些操作直接寫進腳本、哪些用既有表與互動流程組合。[五條 machine-readable chains]

| 分類 | 剩餘事項 | 本稿不冒充的成果 |
|---|---|---|
| Client 待逆向 | 新命名 `.mef` 在目標普通場景的具體 first caller；若需要，fresh lb actor ID 的公開取得方式；各模型完整 avatar／attachment／face ID catalogue；直接開服務 UI 的公開 typed 入口 | 不把檔案存在、counter 推算或任意 UI event 當已證 API |
| 跨功能待整合 | bridge／loader、資源依賴、Q slot；角色外觀與 checkpoint category/key；適用頁面和 service context | 不把本包的函式契約當已部署完整內容 |
| Server 待開發 | 商店資格、商品、定價、交易、強化及持久化；一致的結果與資產更新 | 不把 Server 尚未實作的規則誤列為 Client 未知語法 |
| 待遊玩驗證 | 新內容實際可達；有效模型外觀；Q 動作與表情；NPC 互動及買賣強化 UI；交易後狀態一致 | 不把靜態 verifier PASS 當 Client／Lua／端到端執行測試 |

普通敵人死亡／清組 observer 沒有被拿來當本輪所有能力的前置條件；本輪也未修改它原有的 Client 待逆向狀態。既有研究的 hostile control／RR 主責維持不動。

## 10. 證據與唯讀重驗

交付檔案：

- `native-windows.json`／`.asm`：158 個有界原件窗口，含 VA、raw、length、hex、SHA-256；131 個 code windows 保留逐指令 bytes／assembly。
- `bindings.json`：13 個選定的實際 normal binding、registrar、target、closure 與名稱。
- `contracts.json`：13 API 契約、五條能力鏈、四種 concrete RTTI、67 條 selected direct calls、31 個 instruction anchors，另分開 Client／Server／整合／遊玩事項。
- `resources.json`：Table 八個 member 的原件 locator／decoded hash 與選定 Town1／模型事實；不含完整原始 XML。
- `source-manifest.json`：main `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`、父 `af97bbd29c892e031eef7a3bc3a98cb79f1be729` 的固定 Git blob／內容 hash；bulk C 一律只標導航。
- `verify_evidence.py`／`verification-result.json`：唯讀重驗工具與實跑結果。

```sh
python -B kr-extra-roy/MEF-capabilities-20261116/world-npc/verify_evidence.py \
  --repo /path/to/ttr_anal_multi \
  --bin /path/to/02-Tartaros.bin \
  --table /path/to/07-Table.stp
```

工具讀取固定 Git objects，停用 lazy fetch／optional locks；重驗原件整檔 hash、PE VA→raw、window bytes／hash、逐指令邊界與 assembly、binding immediates、RTTI slots、直接 call／關鍵指令、Table selected rows，以及所有固定來源。STPD／EX parser 僅從已固定且已檢閱的分析工具載入，不執行任何原始 Lua／Client。

本包的 PASS 表示這些**有界靜態證據與原件一致**；不是 T01 ACCEPTED、原版 `.mef` 專屬 grammar 已還原，或新內容已完成遊玩驗收。

實跑結果為 **PASS**：158 windows／33,059 原件 bytes、13 bindings、四個 RTTI、67 direct calls、31 anchors、114 個 Git pins、八個 Table members。逐項數目與當次交付檔 hash 存於 `verification-result.json`。
