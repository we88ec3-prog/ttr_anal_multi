# W3 批次06 — Quest15 四段劇情：NPC 確認、任務接取、場景啟動、下一幕及玩家操作恢復（KR BIN-first）

> 交付：2026-11-02；原有工作分支 extra/roy3。使用者本次優先指定 Quest15 四段劇情及操作控制恢復，故從 W3 Town NPC/interface 擴展至該橋接流程，但不接管 T16 原稿、Task owner、RR/T01 審核或 Server 實作。本篇在原 W3-05 後**新增獨立原稿**，不覆寫其他研究者檔案。
>
> 結論分級：**R**＝原 KR 資源 bytes/逐字 Lua；**N**＝本輪直接 KR BIN disassembly／bytes 與控制流；**N-ref**＝引用既存有界 T16 Client 證據；**S**＝Server 相容實作設計候選（非官服規則）；**U**＝尚未確認；**NOT_RUN**＝未執行原 Client／Server。此報告不是 T01 FULL-PASS、RR ACCEPTED、S00 STABLE 或可玩驗收。

## 0. 本輪來源、分支核對與研究終點

- **已在本輪核原件 SHA256**：Tartaros.bin = 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；Tartaros.exe = 03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f；Event.stp = 2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b；Table.stp = 09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442。
- BIN PE32 x86 的本輪 .text VA/raw 映射為 raw=VA−0x400C00；直接以 objdump 讀原始 BIN 指令，並由 SHA256 封存切片。Event.stp 四段原始 Lua 在下列精確 offset 逐 byte XOR 0xFF 後重新計算 SHA256。**未執行、附加或修改遊戲程式、封包、資源、資料庫或 Server**。
- GitHub 開工：main ac6aac673426459df2a778d20a80c623b8559a92；extra/roy3 b58f3e20f4ae533d982e28bdd778a42547afd97b；compare main...extra/roy3 ahead=45/behind=0，已包含主線，未另開 branch 或 Merge。T16 main inbox 無待辦 RR；其 T01 既有退回以 README 實際狀態為準，並不藉本交付變更。
- **研究終點**：將四幕的真實資源、事件/接取的 Client 條件式入口、Chapter FIRST/NEXT/EndCutScene 的原生回呼、操作鎖定/恢復和 Quest117 下一步分開閉合。**不把無法由原 Client 靜態資料證明的官服發包時序、權威完成/給獎或真實遊玩當成本輪已證結論**。

## 1. 四段場景的原始 Event.stp 對照（R）

以下每段都是 Event.stp 中以原始容器 offset 直接 XOR 0xFF 提取的完整 Lua function，SHA256 是**解碼後該 function 字節**，與 Event/Sequences 打包腳本整體 SHA 不同。Chapter/Event 雙表的有序精確鍵由既存 W3-PHINDOS-SCENE-INDEX.json 與 W3-FULL-VILLAGE-MAINLINE-RESULT.md 對照；它們是資源順序，**不是原服已錄到的必播／發包序列**。

| typed scene key | function / 解碼區間 [start,end) | SHA256（解碼 function） | 玩家看得到的資源／事件 | 正常尾端 |
| --- | --- | --- | --- | --- |
| (15,1) | Square_Tutorial01；Event raw 0x96943E..0x969685，583B | ff7cdb9556a8043d2cec7f23dc4f4a4c83340857102867ba540ca4619dbc6764 | Square03D.fld、CreateObject(1,10338,869,1052,...)、OpenTalkScene(3,22) | Q.DeleteAllObject → RestoreMap → RevPhase1 |
| (15,2) | scenario_tuto1_1；raw 0x96883E..0x968C2F，1009B | 92350b2327a7f6f3a127402bd1f9a33065758d11126be53d72528fae027edb8d | Square03D.fld、NPC10338、1478–1481；OpenTalkScene(3,15/16/17/25)、鏡頭及移動 | 同上 |
| (15,3) | pindos_talkevent；raw 0x8C1C3E..0x8C2256，1560B | 81746ec045328fb0abdf9dbe4eba4023d653e851463db3d0a714bafec9cffe91 | town001D.map **演出地圖**，CreateObject(4,10047,734,744,...)；OpenTalkScene(3,18/24/20/21)，DoProlog(1) | 同上 |
| (15,4) | scenario_tuto2_1；raw 0x96903E..0x9691B8，378B | 9afbe28bfb9c9713fd132726a5814f65aaf4e3baae7046676bac44518f214a3e | SetTransitionType(0)、HideOriginalObjs(0)、LoadMap("")；**沒有 NPC 建立/對話** | 同上 |

四幕都在開頭執行 Phase1，正常尾端都執行 RevPhase4/3/2 → Q.DeleteAllObject → RestoreMap → RevPhase1。1/2/3 使用 transition2 + hideOriginalObjs1；第4幕使用 transition0 + hideOriginalObjs0。Scene3 的 object10047 **不等於** Q15 giver/finisher10338；town001D.map 是 cutscene LoadMap 文字，**不等於**正常 Town1 map selector182、Town1 合法玩家出生點或已完成的 Town scene/controller。

## 2. NPC10338 確認事件 → 接取顯示 → 劇情啟動：四條不同通道（N-ref／U）

QuestInfo 原件的 Q15：id15/type2/town5/field19/level1/giver10338/finisher10338/Demand16；完成 key16 亦須核對角色所在 town5、level、排除集合及當前候選重算。Chapter 資源列出 (15,1)～(15,4)；任務完成與是否何時播放這四幕不是同一個判定。

| 玩家情境 | Client 已有有界 producer／consumer | 有條件 app payload（**不是完整 TCP frame/官服抓包**） | 不能推斷／後續工作 |
| --- | --- | --- | --- |
| 玩家選到 NPC10338 | 0x543700 actor event kind寫+F4、selector寫+F6；0x544070 kind3 在角色/mode gate 可建立 F43D9；wrapper outer type105BD/action6A7 與 nested105BF 經 0x5B9340，0x5008B0 first eligible type2 giver=10338 可能取 QID15 | 0x5B9453 nested +18/+1C → C2S001C [u16 001C,u16 kind,u16 selector]；**只有欄位不變時**可能為 1C 00 03 00 62 28 | NPC 顯示、F43D9、本地候選與真正送達 Server 不等價；不能把 001C 的第二欄改寫為 QuestID15 |
| 玩家欲接 Quest15 | 0x5B9447 把候選 (15,1) 送 0x561760；0x561DB0 的 normal/deferred + sender gate 允許時 0x4A39A0 排 C2S003F | 條件式 (15,1) 為 3F 00 0F 00 01 00 01 00（四個 LE16） | busy、+89 mode、pending 先清/後送 gate 都可能使 003F 不入列；不是 ACK 或確保 Scene1 已載 |
| 接取型對話 UI | 收到 S2C0040 qid15/state0 經 0x502270→F438B/mode2；候選排除/cache 更新需過 Record/UI gate | app 至少 [u16 0040,u16 qid,u32 state]；040/0 不等於完成 | **未證**原服必在 001C 或 003F 後回 0040；mode2 不可直接假設使用 mode1 F4402→0036 |
| 其他任務提交 | 0x4B3510 可獨立構造 C2S0036 [u16 0036,u16 QID]；0x636E10 有 mode/action gate | Q15 只在該 producer 真以15為參數時構成 36 00 0F 00 | mode2、mode3 不能當作必然 C2S0036；必須另記錄玩家按鍵與 sender callback |
| 任務狀態/交付 | S2C0046(q15,sub0) 經 0x502B40 改 exclusion/prereq（Record subtype gate）及 F438C/mode3；S2C0074(15) 是 prereq 增量，006F 是**覆蓋型**完整快照 | 0046、0074、006F 分屬不同 Client state consumer | **0046 沒有直接呼叫 0x561760/0x565720**；Client cache ≠ Server DB/獎勵已寫 |
| 獨立 scene 鍵 | S2C0047 的兩個 signed WORD 經 0x503040→0x561760(primary,secondary)；另有章節物件 FIRST 0x47E890→0x47B5C0→0x565720 | 人工 (15,3) 測試向量 47 00 0F 00 03 00 **不是官服證據** | S2C0045 只在 QuestRecord.CompleteAction.type==2 時送 (qid,param)；Q15 的資源本批沒有可據以確立該 action2 的欄位，**禁止硬塞** |

引用 T16-127（C2S）、T16-128/134/135（S2C/控制器/因果）和 W3-05；上述既有結論是**有界重用**，本輪新增機器碼證據在第3節。目標路線是 NPC interaction → Client 候選及事件 → Server 相容接受決策（待 S00）→ UI/任務權威分離 → scene key 有效才啟動；**不存在「點 NPC 就直接視 Q15 已接/完成並跳 Scene3」這個已證捷徑**。

## 3. 本輪新增 BIN-first：Lua callback 的實際 target、輸入位元與 EndCutScene→NEXT

### 3.1 必要全域初始化／this 指標（N；新增）

原生函式/指標資料流：

~~~asm
0048D76B  mov esi,0xFDF3C8
0048D770  mov eax,0xFB73C0
0048D775  call 0x560600
0056060B  mov [eax],esi
0056060D  call 0x565E40
00565E4B  mov [0xFE2778],eax    ; lua Q callbacks' native receiver
0056061C  call 0x565FC0        ; binds EndCutScene
00565FD8  mov dword [0xFE2780],0x561DB0
00566018  push 0xD6A260       ; "EndCutScene" string
00566029  push 0x568A90       ; Q.EndCutScene Lua C function
00568AC6  mov ecx,[0xFE2778]
00568ACC  call dword [0xFE2780]
~~~

故在該**原生正常註冊路徑已執行且 callback 指標未被異常覆寫**時，Q.EndCutScene 的 this=0xFB73C0（SceneController）並直接進 0x561DB0；這比 T16-133 當時「EndCutScene indirect callback 未追到 target」的已知證據**新增了一個完整 target/receiver 鏈**。不等於原服任何場景必達 Lua 收尾或 Runtime 不可能中斷。

### 3.2 DisableInput/EnableInput：真正操作旗標（N；新增）

~~~asm
00566258  mov dword [0xFE2790],0x5629F0 ; DisableInput target
00566298  push 0xD6A298                  ; "DisableInput"
005662A9  push 0x568C20                  ; Lua C bridge
00568C56  mov ecx,[0xFE2778]
00568C5C  call dword [0xFE2790]
00562A3E  or dword [0xFB8830],0x2        ; disable: SET bit1

005661B8  mov dword [0xFE278C],0x562980 ; EnableInput target
005661F8  push 0xD6A28C                  ; "EnableInput"
00566209  push 0x568BC0                  ; Lua C bridge
00568BF6  mov ecx,[0xFE2778]
00568BFC  call dword [0xFE278C]
005629CE  and dword [0xFB8830],0xFFFFFFFD ; enable: CLEAR bit1
~~~

兩個 native 函式在更改旗標前都可能先測全域 0xFB7C14 bit0、執行一次性 helper 0x6D0750，不能從旗標單獨推論 player actor 已綁定或 map ready。此 0x02 是 **已證輸入開關的本地旗標操作**，但要證所有鍵盤、滑鼠與技能均被該 bit 阻止，仍需各使用端 xref（T09/T10/T11）和遊玩驗證。

### 3.3 RestoreMap：callback 實際指向另一個 native（N；新增）

~~~asm
005675B8  mov dword [0xFE280C],0x563FA0 ; Q.RestoreMap target
005697F6  mov ecx,[0xFE2778]
005697FC  call dword [0xFE280C]
00563FD7  test byte [0xFB75B0],0x1
00564013  mov eax,[esi+0x34]             ; SceneController owner-local key
00564023  mov ecx,0xFB74E0
00564028  call 0x47FDF0                   ; local container lookup
0056408C  lea edx,[esp+0x14]
00564090  mov ecx,0xFB74B0
00564095  call 0x4F7DF0
~~~

這是由 prior T16-133 未解的 RestoreMap indirect 再追至 **0x563FA0**，可證它有容器查找/清理的場景本地副作用，不是純空函式。其更多分支（例如 +0x54、容器/資源重建、World map 屬主）**未在本輪全部核完**；目前仍不能保證 RestoreMap 自動切至 Town1 Map182、合法 spawn 或完整 controller ready。也**不能**把 RestoreMap 直接當成 0x561DB0；腳本明確是先 RestoreMap，再在 RevPhase1 裡走 EndCutScene。

### 3.4 原編譯 Lua qbase 的結束順序（N-ref，結合本輪 native target）

既存 T16-133 由 Event.stp 原始 Lua5.1 qbase chunk 提取、各 Proto bytecode，四幕走同一套 helper：

1. **Phase1/Proto66**：Q.DisableInput → （hideOriginalObjs1時）Q.DisableObjRender → ScenarioTalkTable.hideOtherUI → yield → transition／letterbox／camera override。
2. **OpenTalkScene/Proto16**：g_scenePlaying=TRUE → ScenarioTalkTable.open(group,index,TRUE) → WaitForScene 循環 yield/wait；**OnEndTalk/Proto8** 才將 g_scenePlaying=FALSE。native 0x6BD720 有 0x4AD0A0("OnEndTalk")，不是 Server ACK。Scene3 的 **DoProlog/Proto45** 在 Q.Prolog(1) 後等 Q.IsPrologRunning 結束。
3. **RevPhase1/Proto73**：EndCameraOverride → 按 transition 做轉場/letterbox/fade → EndSepia、EndSlowMotion → talk UI hide/showOtherUI → 有條件 EnableObjRender → yield → **Q.EnableInput → Q.EndCutScene**。尾端這兩個呼叫**相鄰且有順序**，並非 SendQuestCompleted。
4. 若 Lua coroutine、Q.RestoreMap 或等待 UI callback 任一環節未返回，不能保證 RevPhase1 已到 Q.EnableInput；**禁止以「放完動畫自動解除鎖定」作無條件 Server 設計假設**。反之若觀察 bit1 已清但角色不能走，還須檢查 scene/actor/map/control 綁定，不應只補發 quest UI 封包。

### 3.5 新證 EndCutScene 導向的下一段/停播（N，延伸既有 T16-132）

~~~asm
00561DDC  mov edi,ecx                      ; receiver=0xFB73C0
00561DE0  cmp byte [edi+0x89],0
00561DE7  je 0x561F60                       ; non-scene/deferred branch
00561DF6  mov [edi+0x28],esi               ; active清零，限此條前置
00561ED1  mov eax,[edi+0x3C]               ; old scene
00561ED4  mov ecx,[edi+0x38]               ; primary
00561ED9  push 0xFC0F68                    ; Table Chapter SceneList
00561EDE  call 0x47E640                    ; ordered successor, NOT +1
00561EE5  mov [edi+0x3C],eax
00561EEA  je 0x561F0B                       ; successor 0
00561EF3  call 0x565720                    ; successor nonzero: EventScene lookup/load
00561F47  mov [edi+0x38],ebx               ; no-next clears key
00561F4A  mov [edi+0x3C],ebx
~~~

正確的**條件式正常結束鏈**是：

~~~text
Quest15 scene Lua 正常進入尾段
 → Q.DeleteAllObject
 → Q.RestoreMap → 0x5697C0 → 0x563FA0（場景恢復/容器處理）
 → RevPhase1:
    camera/letterbox/visual/UI cleanup → yield
    Q.EnableInput → 0x568BC0 → 0x562980 → FB8830 &= ~2
    Q.EndCutScene → 0x568A90 → 0x561DB0(SceneController)
       ├ [+89 scene-mode != 0] Table Chapter ordered NEXT( primary,oldScene )
       │    ├ next !=0 → 0x565720 → (key hit/VM success) 下一段 script
       │    └ next ==0 → local notify/cleanup，主鍵/次鍵清 0，不執行新 script
       └ [+89 scene-mode == 0] normal deferred/quest network branch，
            **不是**章節 NEXT（producer gates 仍須符合）
~~~

**重要修正**：過去只看到 0x561DB0 有 direct caller 0x561D7F、0x56288C，不能把 RestoreMap 直接說成 NEXT；本輪找到了 Q.EndCutScene→0x568A90→indirect 0x561DB0 的真實 callback binding。這證實了「Lua 結束後**有**原生通知場景 controller 的路線」，仍未證明特定玩家在 Q15 Scene1→2→3→4 的全程 runtime 時序、重入或 server broadcast ordering。下一幕由 Table ordered vector 選取，絕不能無資料自作 sceneIdx++。

### 3.6 新增直接 BIN slice hash／可重現位址

所有 SHA256 為本輪從同版 Tartaros.bin 原始 bytes 擷取；end exclusive，若最後 instruction 不完整，不以截斷指令作語意證據：

| VA slice [start,end) | raw slice [start−400C00,end−400C00) | bytes | SHA256 |
| --- | --- | ---: | --- |
| 565FC0..566040；EndCutScene binder | 1653C0..165440 | 128 | 3e1f24aca927c1729be0cf09e6d0d061bbd91ac726d4fc62146274b5fbe8ba29 |
| 568A90..568AF0；EndCutScene Lua bridge | 167E90..167EF0 | 96 | cfae9714d0028c3897b168a5c823157d28dccfc3c3af1b4dc782fd668bc9c3e3 |
| 566190..566210；EnableInput binder | 165590..165610 | 128 | 6f7aacce448821076973a115bfa40bdd8371aab3833fe0882df25662188efb8a |
| 566230..5662B0；DisableInput binder | 165630..1656B0 | 128 | b7504cdc4aa0698ecc9a21ece93143d1a9bc83dbc9da3e63bd2f58d1823d86dd |
| 562980..5629E4；EnableInput implementation | 161D80..161DE4 | 100 | ceec862640772fe34921a3a4fe90f70ffc2fe960a1c51fbeb4bc4dc034960ac3 |
| 5629F0..562A54；DisableInput implementation | 161DF0..161E54 | 100 | 2c22acb95c841b40ac2f01b80325c9b4c863f63b3f966283eea37aaf716e2576 |
| 561DB0..561F50；SceneController NEXT subset | 1611B0..161350 | 416 | d742c1843e904aa7cad8751b3ce3859b4c1a3218c51f68c626fd83078e4ff723 |

另外由 BIN 逐字驗了 0x48D770/0x48D775、0x56060D、0x565E4B、0x5675B8、0x5697F6/FC、0x563FA0..0x564117；上述源/目標 xref 精確地址已列於3.1、3.3。T16-133 有原始 qbase bytecode 及 Proto66/73 指令表；本輪不將先前 qbase code 再冒稱重新逆向一次。

## 4. 「四段結束後下一步」與 Quest117 的**兩種不同 next**

| next 層 | 來源／條件 | 已可實作或等待的界線 |
| --- | --- | --- |
| **Client 同章節下一幕** | EndCutScene 進 0x561DB0、scene-mode +89!=0、Table SceneList ordered successor 存在才呼叫 0x565720 | **N**：有此條 native callback、查表和載入鏈；**U**：原版 Server 對 Q15 在何時令 controller 進 scene-mode，四幕是否在單次連播／逐次選播 |
| **Quest 下一任務 Q117** | Q15 是 Town5/field19/Demand16、NPC10338 的進村橋接；Q117 在 Town1 NPC10002、Demand15；Town1 context=1 與 Map182/正常場景/actor/control 必須正確初始化 | **R**：靜態任務鏈與 NPC/資源；**S**：Server 權威 Q15 完成/獎勵/保存、prereq key15 快照與 Town1 context/Map182/NPC10002 互動是不同交易與 scene bootstrap；**U**：官服實際事件時序、正式正常 Town scene、合法出生點與接取回覆 |

切勿用 Q15 Scene3 的 Prolog、Scene4 的 RestoreMap/EndCutScene 或 UI mode3 作為 **Quest15 completed** 的唯一條件。Q117 是 Server/任務前置之下一入口，並非 Q15 Scene3 script 的隱式 Lua callback。W3 正常 Town1 map依賴、bounds、NPC roster/Spawn 的未解事項仍有效。

## 5. 給 S00 / Server 的正流程契約與驗收（全部 NOT_RUN）

| 順序 | 測試條件 | 要觀察／不能代換 |
| --- | --- | --- |
| A | 角色合法完成 Q16，任務 key16 在角色快照且 town5/level/排除相容，NPC10338 actor/event 存在 | Q15 candidate 可被正確挑出；NPC kind/selector/context 有源可追，不把 NPC modelId 直接當 network entityId |
| B | 玩家實際點 NPC10338 | 對照 local F43D9、條件式 001C/003F 與其真實 app/transport bytes；**先看是否真的送出**，不可把任一封包視作已接取 |
| C | Server 在已核准 policy 下接受任務、下發正確 UI/場景回覆 | 逐一驗 0040 mode2、scene 0047/controller、0036 的 producer gate；不能假定原服 request/ACK 必然一一對應 |
| D | 依既有 Table/Event 精確資源順序播放 (15,1),(15,2),(15,3),(15,4) 各自 Scene | 每幕 UI、NPC/演出資源、OnEndTalk、DoProlog wait、Phase1 DisableInput、RevPhase1 EnableInput；每次記 scene/controller keys +38/+3C、+28/+89 |
| E | 各幕正常播完 | 記錄 RestoreMap 0x563FA0、EnableInput bit0x02 清除、EndCutScene→0x561DB0→Table ordered NEXT/stop；若下一幕被啟動，應再次看到 Phase1 DisableInput；不得假設 NEXT 即 sceneIdx+1 |
| F | Q15 合法完成並正式進村 | Server 權威 Q15 completed+reward+持久化與 Client 006F/0074 key15 一致；Town1 正常 map182/bounds/player/NPC/controller ready 與 Q117 NPC10002 候選及互動分開驗證 |
| G | 角色在正式 Town1 可行走及點 NPC10002 | 原版 Client 真正移動/鍵鼠操作成功，且非僅 FB8830 bit已清；避免因 scene active 或角色 controller 未綁而「UI 解鎖但不能走」 |

**本輪只做靜態原件核對，表內全部 NOT_RUN**。取消、跳過、重入/掉線、重登、多角色競態、故障、安全/負向、壓測依使用者本階段測試政策列為 deferred，不冒稱 PASS。

### 尚缺精確證據／責任

- **Client 待逆向（T16/T07/T02）**：原版官服 001C/003F/0036 與 0040/0045/0046/0047 的實際 request/result 對應；NPC10338 世界 actor→事件 wrapper 的特定播放 gate；controller+89 的各次 runtime writer、15/1～15/4 實際切幕記錄；RestoreMap 0x563FA0 後半部副作用和 Q.EndCutScene 清理狀態是否有重入例外。上述各自有精確入口，不得誤丟成「全屬 Server-only」。
- **Server 待開發（S00）**：Q15 accept/complete/reward/snapshot（含 key15）權威交易、場景排程與 scene-key policy、Town1 正常入場與 NPC10002 可互動的合法配套。這些是相容重建可設計政策，**不是已還原官服內部演算法**。
- **跨功能待整合（T07/T08/T09/T16/S00）**：SceneController/Map182/正常 Town scene、BND/合法 spawn/ready/loading、NPC actor/entity/event、獨立 Quest UI 控制。不能以 Scene3 cutscene 的 x/y 當真實玩家位置。
- **待遊玩驗證**：真正 NPC 點擊、全部四幕、對話 callback、逐幕鎖輸入/解除、最後進 Town1 並可接 Q117，均尚未由本輪實機驗證。

## 6. 有界來源／新知與舊文差異

- **本輪新補（N）**：EndCutScene callback receiver 0xFB73C0、target 0x561DB0 的初始化→註冊→bridge→controller 全鏈；DisableInput 0x5629F0 SET FB8830 bit0x02；EnableInput 0x562980 CLEAR 同一 bit；RestoreMap target 0x563FA0；依此前 qbase 正常尾段順序可連到本地 NEXT/stop。每一項均有本輪直接 BIN 地址/bytes 與可重現 hash。
- **直接原件（R）**：Quest15 四段 Lua 原始 Event.stp XOR 擷取、函式 SHA256、NPC/object、dialogue、phase、不同 map 字面量、全部正常尾段。兩張 SceneList 及完整 QuestInfo/Chapter 來源另引用原 W3 資源解碼結果。
- **受限復用（N-ref）**：T16-127 blob 4e8e07719e882b4525481641dce929dd9786b87d；T16-132 blob 16550cf62fb2ecbd539e07f568982e1d18d9b942；T16-133 blob 72970ebc9b300f3b4911b21909756700d23be53c；T16-134 blob 991fa3fbbb89622e264eaceb138725d597629e28；T16-135 blob b0a15aaabe1fc2d86225c5d5466b6ab78564c29c。**這些不表示整篇 T16 FULL-PASS**。
- **W3 源**：W3-05 blob 6fa66a3ab7b4e6324182604cc7c0689b9eca2ecb；W3-FULL-VILLAGE-MAINLINE-RESULT blob c6900bd632002a0534f8484a4184f8ecc126c176；W3-PHINDOS-SCENE-INDEX.json blob 5f0c23901c455c5f44f7c4746536e980d6dc4b2e。
- **需更正舊限制的範圍**：T16-133 曾把 [FE2780]/[FE280C] 實際 writer/target 列為待追，故當時無法直接建立 Lua收尾→NEXT；本稿新增了精確 register writer，**是向前補證，不覆寫原作者的歷史說法或把全部 runtime 決策升格為已知**。
