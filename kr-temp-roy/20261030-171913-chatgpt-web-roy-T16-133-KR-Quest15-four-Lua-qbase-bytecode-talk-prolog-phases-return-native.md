# T16-133 — Quest15 四段 Lua 的任務／劇情 UI、對話等待、Prolog 與返回控制（KR Event.stp Lua 5.1 + BIN-first）

- 時間（台灣）：`2026-10-30T17:19:13+08:00`；原稿：`chatgpt-web roy`；正式段號 **T16-133**，承接分支已完成 T16-132。
- 研究範圍：T16 專屬 ③「四段 Quest15 Scene Lua 對任務／UI 的作用與返回控制」，**只研究 Client 的任務/劇情可見行為與 native callback 界面；不反向占有 T06/T07 的通用資源／地圖引擎工作**。
- KR BIN **12,472,320 bytes**；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，Event.stp **11,241,597 bytes**；SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。全程唯讀、未執行、未 patch。`STPD` XOR-FF decode 僅用於原始資源靜態提取。
- 原生 BIN `.text` VA `0x401000` raw `0x400`，因此 `.text` raw=`VA−0x400C00`；`.rdata` VA `0xBD2000` raw `0x7D0600`；`.data` VA `0xD61000` raw `0x95E800`。**切勿把 `.data` raw offset 當作 `.text` offset**。
- GitHub 開工時 `main=94899b7bf99228215073d4c524773e4cdc7283bf`；`t16/roy/chatgpt-web` 對 main `ahead=9／behind=149`。依前段同一對話一次性同步規則**不重新 main→T16 Merge**；`T16` 無 S00 RR。T01 43 筆 `RESOLVED`，T16-117 的 author erratum 已在工作分支 `READY_FOR_REVIEW`、而 `main` 仍為 `NEEDS_FIX`，等待 T01 正式複驗，故**此稿不冒稱退回已結案**。
- 已先讀 T16-125/129/130/131/132 原稿及 `02/03` 規範；本次**新增**原始 Event.stp **Lua 5.1 compiled chunk** 真正解碼、共用腳本 wrapper 的 75 個子函式表、native `Q.*` callback 註冊／消費、OnEndTalk callback 與 Prolog wait loop。不是單純重複四個腳本文字。

## 1. 最終有界結論（證據分級）

### 1.1 [RAW EVENT] 真正 Scene 1–4 腳本與可見功能

- Scene1 `Square_Tutorial01` 與 Scene2 `scenario_tuto1_1` 使用 `Square03D.fld`、建立 ID10338 actor，並各呼叫 1、4 次 `OpenTalkScene(3,*)`。
- **Scene3 `pindos_talkevent`** 使用 `town001D.map`、物件 ID10047，四次 `OpenTalkScene(3,18/24/20/21)`；不同階段攝影機/行走/動畫及 `DoProlog(1)`，結尾 `Q.DeleteAllObject → RestoreMap → RevPhase1`。
- Scene4 `scenario_tuto2_1` 設 `SetTransitionType(0)`、`HideOriginalObjs(0)`、`LoadMap("")`，**沒有** `OpenTalkScene` 或 `DoProlog`，但仍執行 Phase/RevPhase 和 Q/map 清理。
- 四幕均沒有 script 直接呼叫 `AcceptQuest`、`CompleteQuest`、`Reward`、`SendPacket` 或 `S2C 0x74` 等字面命令；這只構成**這四份獨立 Lua 可見文字的否定範圍**，不是對整個 Lua VM/原版 Server 的全域否定證明。

### 1.2 [RAW STP / COMPILED LUA] qbase Lua 5.1 wrapper 真正行為

由同一份 XOR-FF decoded Event.stp 在原始 offset `0xA20810` 識別 Lua 5.1 signature `1B 4C 75 61 51 00 01 04 04 04 08 00`，按 Proto 佈局 **逐 byte** 解出主函式 `173` 條 instruction、`91` 常數、**75 個 nested prototypes**，完整 chunk `0xA20810..0xA2364C`，**11836 bytes**，SHA256 `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3`。

**來源限定**：資料目錄確有 `qbase.lua` 項目（XOR-FF decoded raw offset `0xAB87FD`），此 compiled chunk 的 top-level constants 與 qbase wrapper 名稱、`Q` API/Coroutine 語義吻合，故本文稱其為 **qbase 內容相符的 compiled chunk**；本次未完全重建 STPD 所有 directory index→blob slot 的泛用配對，故該命名仍保留此限定。可再由原始 STP index 或另一工具確認 exact mapping，不用假裝已完整通用解包。

- `OpenTalkScene(a,b)`：`g_scenePlaying=TRUE` → `ScenarioTalkTable.open(a,b, TRUE)` → `WaitForScene` → return。`WaitForScene` 呼叫 `yield`，反覆讀 `g_scenePlaying`，未變0時執行 `wait(100)`；`OnEndTalk` 是 `g_scenePlaying=FALSE` 的 writer。
- `OpenAutoTalkScene(a,b)` 只在傳入 `ScenarioTalkTable.open` 第三參數改為 FALSE；Quest15 四幕用的是 **OpenTalkScene**，**不得把 Lua 原始話題 (3,18 等) 解作 QuestID=3 或 SceneIdx=18**。
- `DoProlog(x)`：呼叫 `Q.Prolog(x)`，隨後 `WaitForProlog()`；後者反覆 `Q.IsPrologRunning()` 並等待條件解除（含 `yield`/`wait(100)`）。它沒有在 Lua 直接寫 `QuestOwner+0x5EB0`、發 C→S `0x36/0x3F`、呼叫 `Q.EndCutScene`；Prolog 子系統實際發生何 native 副作用需依 native callback 界面判定，不可寫成 server 持久化。
- `SetTransitionType(x)`、`HideOriginalObjs(x)` 是腳本全域旗標 `g_transitionIdx`、`g_hideOrigObjs` **writer**，Phase1／RevPhase1 是讀者，和 Server progress key 不同。
- `Phase1()`：設定 yes/no flags、`Q.DisableInput()`；視 hide flag 呼叫 `Q.DisableObjRender`；`ScenarioTalkTable.hideOtherUI`、`yield`；依 transition flag=1/2/3 不同畫面分流；2 類會 `Q.Transition(2,120)`、`Q.ShowLetterbox`；再 `Q.BeginCameraOverride()`。
- `Phase2`/`Phase3`/`Phase4`/`RevPhase4`/`RevPhase2` 的這份 qbase bytecode 子函式確實只有 `RETURN`；`RevPhase3()` 唯一可見操作是 `CameraWorks.Stop()`。**不得把空函式名稱推斷為地圖/任務完成的寫入**。
- `RevPhase1()`：`Q.EndCameraOverride`，依 transition flag 走 `Q.Transition/HideLetterbox` 或 fade，接著 `Q.EndSepia`、`Q.EndSlowMotion`、`ScenarioTalkTable.hide()`／`showOtherUI()`；若 hide flag 設置則 `Q.EnableObjRender`，再 `yield`、`Q.EnableInput`、`Q.EndCutScene`。因此腳本完成前的最後一段是**恢復玩家輸入、UI 及 cutscene state**，不是 Quest15 award。
- `ClearObjects()` 是 `Q.DeleteAllObject` 的轉接 wrapper；`LoadMap(path)` / `RestoreMap()` 只做 `Q.LoadMap(path)` / `Q.RestoreMap()` call。前者/後者的地圖引擎完整副作用不在本題 scope，**不把 RestoreMap 當成永久城鎮／Server 傳送或自動 NEXT 的證據**。
- `Register(fn)` 呼叫 `f_registerCoroutine(coroutine.create(fn))`；`f_doCoTask` 將 `Q.EndCutScene` 作 callback 傳給 coroutine scheduler。它與 `RevPhase1` 的 `Q.EndCutScene` 都是存在的界面，但實際呼叫次數/去重需要 scheduler runtime 及 native state 才能下定論。

### 1.3 [BIN] Lua wrapper 對應真實 native Q callback，還有 UI 結束通知

名稱註冊在 **兩層**，不可混為一談：

1. `0x55D6A0..0x55E29E` 的 script VM 環境初始化會處理 `OpenTalkScene/DoProlog/LoadMap/RestoreMap/Phase*` 等 global names，對應 Lua wrapper／上下文；其部份名稱註冊用 `0x8DC2F0` dummy `xor eax,eax; ret`，故**不能把註冊時的 dummy callback 誤作 Q.Prolog 本體**。
2. `0x566018/0x5674B8/0x567558/0x5675F8/0x567AF8/0x567B98` 等是**Q 的實際 method name→function pointer**：`Q.EndCutScene → 0x568A90`、`Q.DeleteAllObject → 0x569700`、`Q.LoadMap → 0x569760`、`Q.RestoreMap → 0x5697C0`、`Q.Prolog → 0x569AD0`、`Q.IsPrologRunning → 0x569B30`。原始碼為 `[0xFE2774]` Lua state 的 method registration，和 coroutine wrapper 完全不同層。
3. `0x569AD0→0x56A430` 將 Lua 參數轉整數後，**通過全域註冊的間接 callback `[0xFE282C]`**；`0x569B30` 對 `[0xFE2830]` 呼叫並將返回值轉 Lua number；`0x5697C0` 走 `[0xFE2780]/[0xFE280C]` 等具體 callback（依本稿切片）。在沒有對這些**注入的指標最新 writer/目標**證據前，不能稱原生 Prolog handler 一定更新任務/Server。
4. `0x6BD720` 以 `OnEndTalk` 字串透過 VM callback `0x4AD0A0` 執行本地 Lua method，並設定其自身 UI 欄位 `+0x9C=0`。與 compiled Lua 的 `OnEndTalk→g_scenePlaying=FALSE` 配合，可建立**對話 UI 通知→Lua 等待解除**的有界 producer/consumer；未認證原版每個 UI 關閉時刻與異常路徑。

### 1.4 研究終點與留存未知

**本段 T16-133 的目標已在 Client 任務/劇情層級有界完成**：四幕各自對話/Prolog/Phase/返回特性、編譯 Lua writer/readers、native Q binder/參數邊界與 UI end event producer，已由原始資源+BIN 相互驗證。**不能宣稱**原版 Server 接受／完成 Quest15、`DoProlog(1)` 帶來線上獎勵、場景 `(15,3)` 必然被選取、`RestoreMap` 地圖副作用全部分析完、UI callback runtime poll/失敗一定安全或玩家已實測可玩。

後續 T16-134 研究 Quest15 C→S/S→C 和 scene 事件因果；T16-135 做整合契約。所有跨 Task 缺口只標明所需 input，**S00 自行決定是否派工**。

## 2. 四幕任務/對話/UI/返回矩陣

| Scene/script | MAP & actor | Lua 劇情對話 | 額外任務/劇情操作 | Phase/返回 | 有無直接 Quest progress application producer |
|---|---|---|---|---|---|
| 1 `Square_Tutorial01` | `Square03D.fld`, actor 10338 | `(3,22)` 一次 | camera/wait | transition2; HideOriginalObjs1; Q.DeleteAllObject → RestoreMap → RevPhase1 | 此腳本文字未見 |
| 2 `scenario_tuto1_1` | `Square03D.fld`, actor 10338/1478..1481 | `(3,15),(3,16),(3,17),(3,25)` 四次 | animation/warp/camera/wait | transition2; HideOriginalObjs1; cleanup/restore/RevPhase1 | 此腳本文字未見 |
| 3 `pindos_talkevent` | `town001D.map`, actor 10047/1478..1481 | `(3,18),(3,24),(3,20),(3,21)` 四次 | `DoProlog(1)`, flying image and camera; Pindos dialog | transition2; HideOriginalObjs1; cleanup/restore/RevPhase1 | 此腳本文字未見；DoProlog ≠ quest award |
| 4 `scenario_tuto2_1` | `LoadMap("")`, no actor/UITalk | 無 | transition0; HideOriginalObjs0 | cleanup/restore/RevPhase1，無 mode2 letterbox 分支 | 此腳本文字未見 |

## 3. Lua compiled chunk 指令來源與反組譯法

- 原始 `Event.stp` XOR-FF chunk `0xA20810..0xA2364C`，字節 checksum `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3`；常數為 Lua TValue 類型（nil/boolean/double/string）；Proto 遞迴包含 code/constant/child Proto/lineinfo/locvar/upvalue。這份 chunk 的 `CLOSURE` / `SETGLOBAL` 明確把 nested proto i 指向 globals `OpenTalkScene` i16、`OnEndTalk` i8、`WaitForProlog` i11、`DoProlog` i45、`RestoreMap` i60、`Phase1` i66、`RevPhase1` i73 等。
- Lua5.1 指令為 32-bit little-endian；`op=i&63, A=(i>>6)&255, C=(i>>14)&511, B=(i>>23)&511, Bx=i>>14, sBx=Bx−131071`；RK operand>=256 表示 constant index `operand−256`。本稿 disassembler 只用靜態 bytecode，**沒有執行 Lua**。具體指令參數與常數見第5節，不把 VM 指令當 C++ function pointer。
- 不重複做 T16-129 的 Event SceneList XML load；本篇重點是 Scene Lua **怎樣透過真正 qbase wrapper 被解譯**，不是重新推導 `questIdx=15` 會何時命中。

## 4. 四段原始 Scene 文字 Lua（first-hand resource excerpt, full functions）

### Scene1: `Square_Tutorial01`

- `Event.stp` raw decoded offset `[0x96943E,0x9696A6)`, 616 bytes, SHA256 `e0a3e5809ea2d39116b4a11adb9e2d3c9173d89c16cdfe8343e8f7f563de5deb`。

```lua
-- Quest #15 / Scene #1 - Function Square_Tutorial01
function Square_Tutorial01()
	SetTransitionType(2)
	SetFinalMusic("")
	HideOriginalObjs(1)
	Phase1()

	LoadMap("Square03D.fld")
	MoveCamera(0.00, 0.00, 0.00)
	RotCamera(0.00, 1.57, 100.00)

	CreateObject(1, 10338, 869.00, 1052.00, 0, 0, FALSE, 0, 0)

	Phase2()
	Phase3()
	Phase4()

	PlayMusic("BGM040.ogg")
	PlayCameraNoWait("Square_Tutorial01_01.cam", 0, 0.00, 0.00, 0.00)
	wait(500)
	OpenTalkScene(3, 22)

	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(Square_Tutorial01)
```

### Scene2: `scenario_tuto1_1`

- `Event.stp` raw decoded offset `[0x96883E,0x968C4F)`, 1041 bytes, SHA256 `1ba55891d8ef770a868128ba0ebd18fff44524128e70d066b8faf67441f2b012`。

```lua
-- Quest #15 / Scene #2 - Function scenario_tuto1_1
function scenario_tuto1_1()
	SetTransitionType(2)
	SetFinalMusic("")
	HideOriginalObjs(1)
	Phase1()

	LoadMap("Square03D.fld")
	MoveCamera(869.00, 1037.00, 171.80)
	RotCamera(0.70, 1.47, 30.00)

	CreateObject(0, 10338, 869.00, 1052.00, 0, 0, FALSE, 0, 0)
	CreateObject(1, 1478, 864.00, 1032.00, 128, 0, FALSE, 1, 1)
	CreateObject(2, 1479, 869.00, 1027.00, 128, 0, FALSE, 1, 10)
	CreateObject(3, 1480, 869.00, 1042.00, 0, 0, FALSE, 1, 19)
	CreateObject(4, 1481, 874.00, 1032.00, 128, 0, FALSE, 1, 28)

	Phase2()
	Phase3()
	Phase4()

	OpenTalkScene(3, 15)
	OpenTalkScene(3, 16)
	OpenTalkScene(3, 17)
	PlayCameraNoWait("scenario_tuto1_1.cam", 0, 0.00, 0.00, 0.00)
	WarpObject(3, 869.000000, 1038.000000, 0.000000, 0, 1, 1)
	FaceObject(2, 10, 0)
	RotateObject(1, 50, 1)
	RotateObject(4, 206, 1)
	wait(500)
	OpenTalkScene(3, 25)

	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(scenario_tuto1_1)
```

### Scene3: `pindos_talkevent`

- `Event.stp` raw decoded offset `[0x8C1C3E,0x8C2276)`, 1592 bytes, SHA256 `3c848c3f678426bd46899c18cf923688900168e9638d9c8d7a694ebd9b7e09ee`。

```lua
-- Quest #15 / Scene #3 - Function pindos_talkevent
function pindos_talkevent()
	SetTransitionType(2)
	SetFinalMusic("BGM003.ogg")
	HideOriginalObjs(1)
	Phase1()

	LoadMap("town001D.map")
	MoveCamera(755.00, 416.00, 57.75)
	RotCamera(5.67, 1.33, 55.00)

	CreateObject(0, 1478, 751.00, 416.00, 128, 0, FALSE, 1, 1)
	CreateObject(1, 1479, 760.00, 416.00, 128, 0, FALSE, 1, 10)
	CreateObject(2, 1480, 755.00, 429.00, 0, 0, FALSE, 1, 19)
	CreateObject(3, 1481, 755.00, 421.00, 128, 0, FALSE, 1, 28)
	CreateObject(4, 10047, 734.00, 744.00, 0, 0, FALSE, 0, 0)

	Phase2()
	Phase3()
	Phase4()

	PlayMusic("BGM003.ogg")
	PlayCameraNoWait("tutorial_01_18.cam", 0, 0.00, 0.00, 0.00)
	wait(2000)
	OpenTalkScene(3, 18)
	PlayCameraNoWait("tutorial_01_18b.cam", 0, 0.00, 0.00, 0.00)
	wait(1000)
	WalkObject(2, 755.000000, 439.000000, 0.000000, 1, 4, 3)
	wait(1500)
	AniObject(2, 2, 1)
	RotateObject(2, 0, 1)
	wait(1000)
	OpenTalkScene(3, 24)
	PlayCamera("tutorial_01_19.cam", 0, 0.00, 0.00, 0.00)
	OpenTalkScene(3, 20)
	PlayCameraNoWait("tutorial_01_20.cam", 0, 0.00, 0.00, 0.00)
	wait(500)
	OpenTalkScene(3, 21)
	PlayCamera("tutorial_01_22.cam", 0, 0.00, 0.00, 0.00)
	ClearObjects()
	PlayCameraNoWait("tutorial_01_21.cam", 0, 0.00, 0.00, 0.00)
	PlayMusic("BGM007.ogg")
	wait(3000)
	FlyingObject("Image/Prologue/Phindous00_1.dds", 50, 35, 100, 9999, 0, 0)
	wait(4000)
	DelFlyingObject()
	DoProlog(1)
	PlayMusic("BGM003.ogg")

	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(pindos_talkevent)
```

### Scene4: `scenario_tuto2_1`

- `Event.stp` raw decoded offset `[0x96903E,0x9691D8)`, 410 bytes, SHA256 `d6ca315a6eb92441b1271a7e9581328e9a0689afbf95bdca2b0812b53eb4dda2`。

```lua
-- Quest #15 / Scene #4 - Function scenario_tuto2_1
function scenario_tuto2_1()
	SetTransitionType(0)
	SetFinalMusic("")
	HideOriginalObjs(0)
	Phase1()

	LoadMap("")
	MoveCamera(0.00, 0.00, 0.00)
	RotCamera(0.00, 1.57, 100.00)


	Phase2()
	Phase3()
	Phase4()


	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(scenario_tuto2_1)
```

## 5. qbase compiled Lua 5.1 function table + selected native-independent bytecode

| nested Proto | Global name | bytecode instructions | constants | 必要來源概念 |
|---:|---|---:|---:|---|
| 1 | `f_doCoTask` | 6 | 4 | `qco`, `doCoTask`, `Q`, `EndCutScene` |
| 8 | `OnEndTalk` | 3 | 2 | `g_scenePlaying`, `FALSE` |
| 9 | `WaitForScene` | 10 | 5 | `yield`, `g_scenePlaying`, `wait` |
| 11 | `WaitForProlog` | 12 | 6 | `yield`, `Q`, `IsPrologRunning`, `wait` |
| 16 | `OpenTalkScene` | 11 | 5 | `g_scenePlaying`, `TRUE`, `ScenarioTalkTable`, `open`, `WaitForScene` |
| 17 | `OpenAutoTalkScene` | 11 | 5 | `g_scenePlaying`, `TRUE`, `ScenarioTalkTable`, `open`, `WaitForScene` |
| 35 | `ClearObjects` | 4 | 2 | `Q`, `DeleteAllObject` |
| 45 | `DoProlog` | 7 | 3 | `Q`, `Prolog`, `WaitForProlog` |
| 59 | `LoadMap` | 5 | 2 | `Q`, `LoadMap` |
| 60 | `RestoreMap` | 4 | 2 | `Q`, `RestoreMap` |
| 62 | `SetTransitionType` | 2 | 1 | `g_transitionIdx` |
| 64 | `HideOriginalObjs` | 2 | 1 | `g_hideOrigObjs` |
| 66 | `Phase1` | 55 | 24 | `g_yesTriggered`, `TRUE`, `g_noTriggered`, `FALSE`, `Q`, `DisableInput`, `g_hideOrigObjs` |
| 67 | `Phase2` | 1 | 0 |  |
| 68 | `Phase3` | 1 | 0 |  |
| 69 | `Phase4` | 1 | 0 |  |
| 70 | `RevPhase4` | 1 | 0 |  |
| 71 | `RevPhase3` | 4 | 2 | `CameraWorks`, `Stop` |
| 72 | `RevPhase2` | 1 | 0 |  |
| 73 | `RevPhase1` | 63 | 24 | `Q`, `EndCameraOverride`, `g_transitionIdx`, `Transition`, `HideLetterbox`, `Fade`, `Start` |
| 74 | `Register` | 7 | 3 | `f_registerCoroutine`, `coroutine`, `create` |

### Compiled Lua function disassembly, raw opcode arguments and constants

以下每個 function 的 proto 由原始 qbase chunk 解析，`OP_RETURN` 若沒有其它 opcode 則為**真空函式**；`EQ/JMP` 需要 Lua5.1 控制流解釋，不能單獨依 `EQ` 名稱推論真假。

#### Proto 1: `f_doCoTask` — args=0, code=6

```text
  0: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'qco'
  1: SELF       A=0 B=0 C=257  RK 'doCoTask'
  2: GETGLOBAL  A=2 Bx=2 sBx=-131069  CONST 'Q'
  3: GETTABLE   A=2 B=2 C=259  RK 'EndCutScene'
  4: CALL       A=0 B=3 C=1
  5: RETURN     A=0 B=1 C=0
```

#### Proto 8: `OnEndTalk` — args=0, code=3

```text
  0: GETGLOBAL  A=0 Bx=1 sBx=-131070  CONST 'FALSE'
  1: SETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'g_scenePlaying'
  2: RETURN     A=0 B=1 C=0
```

#### Proto 9: `WaitForScene` — args=0, code=10

```text
  0: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'yield'
  1: CALL       A=0 B=1 C=1
  2: GETGLOBAL  A=0 Bx=1 sBx=-131070  CONST 'g_scenePlaying'
  3: EQ         A=1 B=0 C=258  RK 0.0
  4: JMP        A=0 Bx=131075 sBx=4
  5: GETGLOBAL  A=0 Bx=3 sBx=-131068  CONST 'wait'
  6: LOADK      A=1 Bx=4 sBx=-131067  CONST 100.0
  7: CALL       A=0 B=2 C=1
  8: JMP        A=0 Bx=131064 sBx=-7
  9: RETURN     A=0 B=1 C=0
```

#### Proto 11: `WaitForProlog` — args=0, code=12

```text
  0: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'yield'
  1: CALL       A=0 B=1 C=1
  2: GETGLOBAL  A=0 Bx=1 sBx=-131070  CONST 'Q'
  3: GETTABLE   A=0 B=0 C=258  RK 'IsPrologRunning'
  4: CALL       A=0 B=1 C=2
  5: EQ         A=0 B=0 C=259  RK 1.0
  6: JMP        A=0 Bx=131075 sBx=4
  7: GETGLOBAL  A=0 Bx=4 sBx=-131067  CONST 'wait'
  8: LOADK      A=1 Bx=5 sBx=-131066  CONST 100.0
  9: CALL       A=0 B=2 C=1
 10: JMP        A=0 Bx=131062 sBx=-9
 11: RETURN     A=0 B=1 C=0
```

#### Proto 16: `OpenTalkScene` — args=2, code=11

```text
  0: GETGLOBAL  A=2 Bx=1 sBx=-131070  CONST 'TRUE'
  1: SETGLOBAL  A=2 Bx=0 sBx=-131071  CONST 'g_scenePlaying'
  2: GETGLOBAL  A=2 Bx=2 sBx=-131069  CONST 'ScenarioTalkTable'
  3: GETTABLE   A=2 B=2 C=259  RK 'open'
  4: MOVE       A=3 B=0 C=0
  5: MOVE       A=4 B=1 C=0
  6: LOADBOOL   A=5 B=1 C=0
  7: CALL       A=2 B=4 C=1
  8: GETGLOBAL  A=2 Bx=4 sBx=-131067  CONST 'WaitForScene'
  9: CALL       A=2 B=1 C=1
 10: RETURN     A=0 B=1 C=0
```

#### Proto 17: `OpenAutoTalkScene` — args=2, code=11

```text
  0: GETGLOBAL  A=2 Bx=1 sBx=-131070  CONST 'TRUE'
  1: SETGLOBAL  A=2 Bx=0 sBx=-131071  CONST 'g_scenePlaying'
  2: GETGLOBAL  A=2 Bx=2 sBx=-131069  CONST 'ScenarioTalkTable'
  3: GETTABLE   A=2 B=2 C=259  RK 'open'
  4: MOVE       A=3 B=0 C=0
  5: MOVE       A=4 B=1 C=0
  6: LOADBOOL   A=5 B=0 C=0
  7: CALL       A=2 B=4 C=1
  8: GETGLOBAL  A=2 Bx=4 sBx=-131067  CONST 'WaitForScene'
  9: CALL       A=2 B=1 C=1
 10: RETURN     A=0 B=1 C=0
```

#### Proto 35: `ClearObjects` — args=0, code=4

```text
  0: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'Q'
  1: GETTABLE   A=0 B=0 C=257  RK 'DeleteAllObject'
  2: CALL       A=0 B=1 C=1
  3: RETURN     A=0 B=1 C=0
```

#### Proto 45: `DoProlog` — args=1, code=7

```text
  0: GETGLOBAL  A=1 Bx=0 sBx=-131071  CONST 'Q'
  1: GETTABLE   A=1 B=1 C=257  RK 'Prolog'
  2: MOVE       A=2 B=0 C=0
  3: CALL       A=1 B=2 C=1
  4: GETGLOBAL  A=1 Bx=2 sBx=-131069  CONST 'WaitForProlog'
  5: CALL       A=1 B=1 C=1
  6: RETURN     A=0 B=1 C=0
```

#### Proto 59: `LoadMap` — args=1, code=5

```text
  0: GETGLOBAL  A=1 Bx=0 sBx=-131071  CONST 'Q'
  1: GETTABLE   A=1 B=1 C=257  RK 'LoadMap'
  2: MOVE       A=2 B=0 C=0
  3: CALL       A=1 B=2 C=1
  4: RETURN     A=0 B=1 C=0
```

#### Proto 60: `RestoreMap` — args=0, code=4

```text
  0: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'Q'
  1: GETTABLE   A=0 B=0 C=257  RK 'RestoreMap'
  2: CALL       A=0 B=1 C=1
  3: RETURN     A=0 B=1 C=0
```

#### Proto 62: `SetTransitionType` — args=1, code=2

```text
  0: SETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'g_transitionIdx'
  1: RETURN     A=0 B=1 C=0
```

#### Proto 64: `HideOriginalObjs` — args=1, code=2

```text
  0: SETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'g_hideOrigObjs'
  1: RETURN     A=0 B=1 C=0
```

#### Proto 66: `Phase1` — args=0, code=55

```text
  0: GETGLOBAL  A=0 Bx=1 sBx=-131070  CONST 'TRUE'
  1: SETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'g_yesTriggered'
  2: GETGLOBAL  A=0 Bx=3 sBx=-131068  CONST 'FALSE'
  3: SETGLOBAL  A=0 Bx=2 sBx=-131069  CONST 'g_noTriggered'
  4: GETGLOBAL  A=0 Bx=4 sBx=-131067  CONST 'Q'
  5: GETTABLE   A=0 B=0 C=261  RK 'DisableInput'
  6: CALL       A=0 B=1 C=1
  7: GETGLOBAL  A=0 Bx=6 sBx=-131065  CONST 'g_hideOrigObjs'
  8: EQ         A=1 B=0 C=263  RK 0.0
  9: JMP        A=0 Bx=131074 sBx=3
 10: GETGLOBAL  A=0 Bx=4 sBx=-131067  CONST 'Q'
 11: GETTABLE   A=0 B=0 C=264  RK 'DisableObjRender'
 12: CALL       A=0 B=1 C=1
 13: GETGLOBAL  A=0 Bx=9 sBx=-131062  CONST 'ScenarioTalkTable'
 14: GETTABLE   A=0 B=0 C=266  RK 'hideOtherUI'
 15: CALL       A=0 B=1 C=1
 16: GETGLOBAL  A=0 Bx=11 sBx=-131060  CONST 'yield'
 17: CALL       A=0 B=1 C=1
 18: GETGLOBAL  A=0 Bx=12 sBx=-131059  CONST 'g_transitionIdx'
 19: EQ         A=0 B=0 C=269  RK 1.0
 20: JMP        A=0 Bx=131077 sBx=6
 21: GETGLOBAL  A=0 Bx=4 sBx=-131067  CONST 'Q'
 22: GETTABLE   A=0 B=0 C=270  RK 'Transition'
 23: LOADK      A=1 Bx=15 sBx=-131056  CONST 2.0
 24: LOADK      A=2 Bx=16 sBx=-131055  CONST 120.0
 25: CALL       A=0 B=3 C=1
 26: JMP        A=0 Bx=131095 sBx=24
 27: GETGLOBAL  A=0 Bx=12 sBx=-131059  CONST 'g_transitionIdx'
 28: EQ         A=0 B=0 C=271  RK 2.0
 29: JMP        A=0 Bx=131080 sBx=9
 30: GETGLOBAL  A=0 Bx=4 sBx=-131067  CONST 'Q'
 31: GETTABLE   A=0 B=0 C=270  RK 'Transition'
 32: LOADK      A=1 Bx=15 sBx=-131056  CONST 2.0
 33: LOADK      A=2 Bx=16 sBx=-131055  CONST 120.0
 34: CALL       A=0 B=3 C=1
 35: GETGLOBAL  A=0 Bx=4 sBx=-131067  CONST 'Q'
 36: GETTABLE   A=0 B=0 C=273  RK 'ShowLetterbox'
 37: CALL       A=0 B=1 C=1
 38: JMP        A=0 Bx=131083 sBx=12
 39: GETGLOBAL  A=0 Bx=12 sBx=-131059  CONST 'g_transitionIdx'
 40: EQ         A=0 B=0 C=274  RK 3.0
 41: JMP        A=0 Bx=131080 sBx=9
 42: LOADK      A=0 Bx=19 sBx=-131052  CONST 30.0
 43: GETGLOBAL  A=1 Bx=20 sBx=-131051  CONST 'Fade'
 44: GETTABLE   A=1 B=1 C=277  RK 'Start'
 45: LOADK      A=2 Bx=7 sBx=-131064  CONST 0.0
 46: MOVE       A=3 B=0 C=0
 47: CALL       A=1 B=3 C=1
 48: GETGLOBAL  A=1 Bx=22 sBx=-131049  CONST 'wait'
 49: MOVE       A=2 B=0 C=0
 50: CALL       A=1 B=2 C=1
 51: GETGLOBAL  A=0 Bx=4 sBx=-131067  CONST 'Q'
 52: GETTABLE   A=0 B=0 C=279  RK 'BeginCameraOverride'
 53: CALL       A=0 B=1 C=1
 54: RETURN     A=0 B=1 C=0
```

#### Proto 67: `Phase2` — args=0, code=1

```text
  0: RETURN     A=0 B=1 C=0
```

#### Proto 68: `Phase3` — args=0, code=1

```text
  0: RETURN     A=0 B=1 C=0
```

#### Proto 69: `Phase4` — args=0, code=1

```text
  0: RETURN     A=0 B=1 C=0
```

#### Proto 70: `RevPhase4` — args=0, code=1

```text
  0: RETURN     A=0 B=1 C=0
```

#### Proto 71: `RevPhase3` — args=0, code=4

```text
  0: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'CameraWorks'
  1: GETTABLE   A=0 B=0 C=257  RK 'Stop'
  2: CALL       A=0 B=1 C=1
  3: RETURN     A=0 B=1 C=0
```

#### Proto 72: `RevPhase2` — args=0, code=1

```text
  0: RETURN     A=0 B=1 C=0
```

#### Proto 73: `RevPhase1` — args=0, code=63

```text
  0: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'Q'
  1: GETTABLE   A=0 B=0 C=257  RK 'EndCameraOverride'
  2: CALL       A=0 B=1 C=1
  3: GETGLOBAL  A=0 Bx=2 sBx=-131069  CONST 'g_transitionIdx'
  4: EQ         A=0 B=0 C=259  RK 1.0
  5: JMP        A=0 Bx=131077 sBx=6
  6: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'Q'
  7: GETTABLE   A=0 B=0 C=260  RK 'Transition'
  8: LOADK      A=1 Bx=5 sBx=-131066  CONST 2.0
  9: LOADK      A=2 Bx=6 sBx=-131065  CONST 120.0
 10: CALL       A=0 B=3 C=1
 11: JMP        A=0 Bx=131095 sBx=24
 12: GETGLOBAL  A=0 Bx=2 sBx=-131069  CONST 'g_transitionIdx'
 13: EQ         A=0 B=0 C=261  RK 2.0
 14: JMP        A=0 Bx=131080 sBx=9
 15: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'Q'
 16: GETTABLE   A=0 B=0 C=260  RK 'Transition'
 17: LOADK      A=1 Bx=5 sBx=-131066  CONST 2.0
 18: LOADK      A=2 Bx=6 sBx=-131065  CONST 120.0
 19: CALL       A=0 B=3 C=1
 20: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'Q'
 21: GETTABLE   A=0 B=0 C=263  RK 'HideLetterbox'
 22: CALL       A=0 B=1 C=1
 23: JMP        A=0 Bx=131083 sBx=12
 24: GETGLOBAL  A=0 Bx=2 sBx=-131069  CONST 'g_transitionIdx'
 25: EQ         A=0 B=0 C=264  RK 3.0
 26: JMP        A=0 Bx=131080 sBx=9
 27: LOADK      A=0 Bx=9 sBx=-131062  CONST 30.0
 28: GETGLOBAL  A=1 Bx=10 sBx=-131061  CONST 'Fade'
 29: GETTABLE   A=1 B=1 C=267  RK 'Start'
 30: LOADK      A=2 Bx=3 sBx=-131068  CONST 1.0
 31: MOVE       A=3 B=0 C=0
 32: CALL       A=1 B=3 C=1
 33: GETGLOBAL  A=1 Bx=12 sBx=-131059  CONST 'wait'
 34: MOVE       A=2 B=0 C=0
 35: CALL       A=1 B=2 C=1
 36: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'Q'
 37: GETTABLE   A=0 B=0 C=269  RK 'EndSepia'
 38: CALL       A=0 B=1 C=1
 39: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'Q'
 40: GETTABLE   A=0 B=0 C=270  RK 'EndSlowMotion'
 41: CALL       A=0 B=1 C=1
 42: GETGLOBAL  A=0 Bx=15 sBx=-131056  CONST 'ScenarioTalkTable'
 43: GETTABLE   A=0 B=0 C=272  RK 'hide'
 44: CALL       A=0 B=1 C=1
 45: GETGLOBAL  A=0 Bx=15 sBx=-131056  CONST 'ScenarioTalkTable'
 46: GETTABLE   A=0 B=0 C=273  RK 'showOtherUI'
 47: CALL       A=0 B=1 C=1
 48: GETGLOBAL  A=0 Bx=18 sBx=-131053  CONST 'g_hideOrigObjs'
 49: EQ         A=1 B=0 C=275  RK 0.0
 50: JMP        A=0 Bx=131074 sBx=3
 51: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'Q'
 52: GETTABLE   A=0 B=0 C=276  RK 'EnableObjRender'
 53: CALL       A=0 B=1 C=1
 54: GETGLOBAL  A=0 Bx=21 sBx=-131050  CONST 'yield'
 55: CALL       A=0 B=1 C=1
 56: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'Q'
 57: GETTABLE   A=0 B=0 C=278  RK 'EnableInput'
 58: CALL       A=0 B=1 C=1
 59: GETGLOBAL  A=0 Bx=0 sBx=-131071  CONST 'Q'
 60: GETTABLE   A=0 B=0 C=279  RK 'EndCutScene'
 61: CALL       A=0 B=1 C=1
 62: RETURN     A=0 B=1 C=0
```

#### Proto 74: `Register` — args=1, code=7

```text
  0: GETGLOBAL  A=1 Bx=0 sBx=-131071  CONST 'f_registerCoroutine'
  1: GETGLOBAL  A=2 Bx=1 sBx=-131070  CONST 'coroutine'
  2: GETTABLE   A=2 B=2 C=258  RK 'create'
  3: MOVE       A=3 B=0 C=0
  4: CALL       A=2 B=2 C=0
  5: CALL       A=1 B=0 C=1
  6: RETURN     A=0 B=1 C=0
```

## 6. Native Q method 註冊、執行與返回界面

- 靜態 `Q` string 來源是 `.rdata` VA `0xC10604`；native method name strings 來自 `.data`，不能直接用 `.rdata` raw formula 換算。
- method registry `0x5674B8`→`0x569700`，`0x567558`→`0x569760`，`0x5675F8`→`0x5697C0`，`0x567AF8`→`0x569AD0`，`0x567B98`→`0x569B30`。第7節有逐 byte 證據。
- `Q.Prolog` 的 `0x569AD0→0x56A430` 會在 callback NULL/型別轉換失敗時走 fallback 0 參數，不能說 `DoProlog(1)` 在壞資料時必然仍收到1；正常 numeric value1 則可轉整數1傳給 callback。
- `Q.EndCutScene` 原生 callback `0x568A90` 從 `[0xFE2778]` 取得指標，再經 `[0xFE2780]` 間接呼叫；本題未遍歷該 pointer 的所有 writer，**不推定完整地圖/網路副作用**。
- `Q.DeleteAllObject` callback `0x569700` 也走 `[0xFE2804]`；`Q.RestoreMap` callback `0x5697C0` 走 `[0xFE280C]`。這是可確認的委派邊界，不可當做「後續函式都已解完」。
- OnEndTalk UI callback `0x6BD720` 具有 `0x4AD0A0("OnEndTalk")` 呼叫，此時 Lua `g_scenePlaying` 可被清零；**只是條件式本地事件**，並不證明 Server ack/完成。

## 7. BIN-first disassembly appendix (direct raw VA slices + SHA256)

`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=<VA> --stop-address=<VA> Tartaros.bin`；以下 starts 已核對為完整 opcode 指令起點。全部 slice SHA256 僅由原始 `Tartaros.bin` 擷取，而非從 T16 舊報告複製。

### N01. Scene Lua API binder table OpenTalkScene registration

- VA `[0x55D9FE,0x55DA39)`；raw `[0x15CDFE,0x15CE39)`；59 bytes；SHA256 `c5bf7fd5a59d3b7ec2d56fe2806ad5b0812158dce6f4e821d6d7081880a62f56`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0055d9fe <.data+0x15cdfe>:
  55d9fe:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55da03:	8b 30                	mov    esi,DWORD PTR [eax]
  55da05:	6a 00                	push   0x0
  55da07:	68 f0 c2 8d 00       	push   0x8dc2f0
  55da0c:	8b d8                	mov    ebx,eax
  55da0e:	e8 9d 7b 19 00       	call   0x6f55b0
  55da13:	8b 33                	mov    esi,DWORD PTR [ebx]
  55da15:	bf 20 03 c1 00       	mov    edi,0xc10320
  55da1a:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55da1f:	e8 6c 7d 19 00       	call   0x6f5790
  55da24:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55da29:	8b 30                	mov    esi,DWORD PTR [eax]
  55da2b:	6a 00                	push   0x0
  55da2d:	68 f0 c2 8d 00       	push   0x8dc2f0
  55da32:	8b d8                	mov    ebx,eax
  55da34:	e8 77 7b 19 00       	call   0x6f55b0
```

### N02. Scene Lua API binder table DoProlog registration

- VA `[0x55DE32,0x55DE6D)`；raw `[0x15D232,0x15D26D)`；59 bytes；SHA256 `60f96d921849e90bd27dece796085421ef27109b824aec31668121ec127e1f4a`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0055de32 <.data+0x15d232>:
  55de32:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55de37:	8b 30                	mov    esi,DWORD PTR [eax]
  55de39:	6a 00                	push   0x0
  55de3b:	68 f0 c2 8d 00       	push   0x8dc2f0
  55de40:	8b d8                	mov    ebx,eax
  55de42:	e8 69 77 19 00       	call   0x6f55b0
  55de47:	8b 33                	mov    esi,DWORD PTR [ebx]
  55de49:	bf ac 04 c1 00       	mov    edi,0xc104ac
  55de4e:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55de53:	e8 38 79 19 00       	call   0x6f5790
  55de58:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55de5d:	8b 30                	mov    esi,DWORD PTR [eax]
  55de5f:	6a 00                	push   0x0
  55de61:	68 f0 c2 8d 00       	push   0x8dc2f0
  55de66:	8b d8                	mov    ebx,eax
  55de68:	e8 43 77 19 00       	call   0x6f55b0
```

### N03. Scene Lua API binder table LoadMap/RestoreMap

- VA `[0x55E04C,0x55E0AD)`；raw `[0x15D44C,0x15D4AD)`；97 bytes；SHA256 `cbdabd7b68501cea7b48e6edf02cda7a6cf873274623e1e8af7aa2477575da05`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0055e04c <.data+0x15d44c>:
  55e04c:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e051:	8b 30                	mov    esi,DWORD PTR [eax]
  55e053:	6a 00                	push   0x0
  55e055:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e05a:	8b d8                	mov    ebx,eax
  55e05c:	e8 4f 75 19 00       	call   0x6f55b0
  55e061:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e063:	bf 4c 05 c1 00       	mov    edi,0xc1054c
  55e068:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e06d:	e8 1e 77 19 00       	call   0x6f5790
  55e072:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e077:	8b 30                	mov    esi,DWORD PTR [eax]
  55e079:	6a 00                	push   0x0
  55e07b:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e080:	8b d8                	mov    ebx,eax
  55e082:	e8 29 75 19 00       	call   0x6f55b0
  55e087:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e089:	bf 54 05 c1 00       	mov    edi,0xc10554
  55e08e:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e093:	e8 f8 76 19 00       	call   0x6f5790
  55e098:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e09d:	8b 30                	mov    esi,DWORD PTR [eax]
  55e09f:	6a 00                	push   0x0
  55e0a1:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e0a6:	8b d8                	mov    ebx,eax
  55e0a8:	e8 03 75 19 00       	call   0x6f55b0
```

### N04. Scene Lua API binder Phase1 and RevPhase1 registries

- VA `[0x55E156,0x55E194)`；raw `[0x15D556,0x15D594)`；62 bytes；SHA256 `76ab77a5502f84e2c515ac5486ea0a6a1fca52d7e029e99e7c9fa1f5d77f689c`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0055e156 <.data+0x15d556>:
  55e156:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e15b:	8b 30                	mov    esi,DWORD PTR [eax]
  55e15d:	6a 00                	push   0x0
  55e15f:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e164:	8b d8                	mov    ebx,eax
  55e166:	e8 45 74 19 00       	call   0x6f55b0
  55e16b:	83 c4 40             	add    esp,0x40
  55e16e:	bf b4 05 c1 00       	mov    edi,0xc105b4
  55e173:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e175:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e17a:	e8 11 76 19 00       	call   0x6f5790
  55e17f:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e184:	8b 30                	mov    esi,DWORD PTR [eax]
  55e186:	6a 00                	push   0x0
  55e188:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e18d:	8b d8                	mov    ebx,eax
  55e18f:	e8 1c 74 19 00       	call   0x6f55b0
```

### N05. RevPhase1 binder entry

- VA `[0x55E263,0x55E29E)`；raw `[0x15D663,0x15D69E)`；59 bytes；SHA256 `bb7cb9568daa46bf3cdac6471064138abcfbd986d37c09fa94c13e44c5ccabca`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0055e263 <.data+0x15d663>:
  55e263:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e268:	8b 30                	mov    esi,DWORD PTR [eax]
  55e26a:	6a 00                	push   0x0
  55e26c:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e271:	8b d8                	mov    ebx,eax
  55e273:	e8 38 73 19 00       	call   0x6f55b0
  55e278:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e27a:	bf f8 05 c1 00       	mov    edi,0xc105f8
  55e27f:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e284:	e8 07 75 19 00       	call   0x6f5790
  55e289:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e28e:	8b 30                	mov    esi,DWORD PTR [eax]
  55e290:	6a 00                	push   0x0
  55e292:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e297:	8b d8                	mov    ebx,eax
  55e299:	e8 12 73 19 00       	call   0x6f55b0
```

### N06. Native Q.EndCutScene API register function pointer

- VA `[0x566010,0x566041)`；raw `[0x165410,0x165441)`；49 bytes；SHA256 `ee8c18672263b747154a232c71fa74b94bf5ddcc1d3e755e935d03cab9df8b89`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00566010 <.data+0x165410>:
  566010:	8b 3d 74 27 fe 00    	mov    edi,DWORD PTR ds:0xfe2774
  566016:	8b 37                	mov    esi,DWORD PTR [edi]
  566018:	68 60 a2 d6 00       	push   0xd6a260
  56601d:	e8 ee f4 18 00       	call   0x6f5510
  566022:	8b 37                	mov    esi,DWORD PTR [edi]
  566024:	83 c4 04             	add    esp,0x4
  566027:	6a 00                	push   0x0
  566029:	68 90 8a 56 00       	push   0x568a90
  56602e:	e8 7d f5 18 00       	call   0x6f55b0
  566033:	8b 0f                	mov    ecx,DWORD PTR [edi]
  566035:	51                   	push   ecx
  566036:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  56603b:	e8 b0 f7 18 00       	call   0x6f57f0
  566040:	8b         	mov    edx,DWORD PTR ds:0xfe2774
```

### N07. Native Q.DeleteAllObject callback binder

- VA `[0x5674B0,0x5674E0)`；raw `[0x1668B0,0x1668E0)`；48 bytes；SHA256 `c4a72eb96016894588b20ecaf499f786b17bc10b1eeca158320500d3914157db`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005674b0 <.data+0x1668b0>:
  5674b0:	8b 3d 74 27 fe 00    	mov    edi,DWORD PTR ds:0xfe2774
  5674b6:	8b 37                	mov    esi,DWORD PTR [edi]
  5674b8:	68 34 a4 d6 00       	push   0xd6a434
  5674bd:	e8 4e e0 18 00       	call   0x6f5510
  5674c2:	8b 37                	mov    esi,DWORD PTR [edi]
  5674c4:	83 c4 04             	add    esp,0x4
  5674c7:	6a 00                	push   0x0
  5674c9:	68 00 97 56 00       	push   0x569700
  5674ce:	e8 dd e0 18 00       	call   0x6f55b0
  5674d3:	8b 0f                	mov    ecx,DWORD PTR [edi]
  5674d5:	51                   	push   ecx
  5674d6:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  5674db:	e8 10 e3 18 00       	call   0x6f57f0
```

### N08. Native Q.LoadMap callback binder

- VA `[0x567550,0x567580)`；raw `[0x166950,0x166980)`；48 bytes；SHA256 `8069af9a8e21205d7c6b60c58a0b82ac0349cc0dba2f54fdc0a2df78f44867e9`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00567550 <.data+0x166950>:
  567550:	8b 3d 74 27 fe 00    	mov    edi,DWORD PTR ds:0xfe2774
  567556:	8b 37                	mov    esi,DWORD PTR [edi]
  567558:	68 44 a4 d6 00       	push   0xd6a444
  56755d:	e8 ae df 18 00       	call   0x6f5510
  567562:	8b 37                	mov    esi,DWORD PTR [edi]
  567564:	83 c4 04             	add    esp,0x4
  567567:	6a 00                	push   0x0
  567569:	68 60 97 56 00       	push   0x569760
  56756e:	e8 3d e0 18 00       	call   0x6f55b0
  567573:	8b 0f                	mov    ecx,DWORD PTR [edi]
  567575:	51                   	push   ecx
  567576:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  56757b:	e8 70 e2 18 00       	call   0x6f57f0
```

### N09. Native Q.RestoreMap callback binder

- VA `[0x5675F0,0x567620)`；raw `[0x1669F0,0x166A20)`；48 bytes；SHA256 `abed18a69d22c6f4ff0a0e4d9afa5907441f1b25b4c53bbcee164f218e4501f7`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005675f0 <.data+0x1669f0>:
  5675f0:	8b 3d 74 27 fe 00    	mov    edi,DWORD PTR ds:0xfe2774
  5675f6:	8b 37                	mov    esi,DWORD PTR [edi]
  5675f8:	68 4c a4 d6 00       	push   0xd6a44c
  5675fd:	e8 0e df 18 00       	call   0x6f5510
  567602:	8b 37                	mov    esi,DWORD PTR [edi]
  567604:	83 c4 04             	add    esp,0x4
  567607:	6a 00                	push   0x0
  567609:	68 c0 97 56 00       	push   0x5697c0
  56760e:	e8 9d df 18 00       	call   0x6f55b0
  567613:	8b 0f                	mov    ecx,DWORD PTR [edi]
  567615:	51                   	push   ecx
  567616:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  56761b:	e8 d0 e1 18 00       	call   0x6f57f0
```

### N10. Native Q.DisableObjRender callback binder

- VA `[0x567690,0x5676C0)`；raw `[0x166A90,0x166AC0)`；48 bytes；SHA256 `49746ce9619d6ffde97ae8dffc84cc4e6c2ff398f784b10501b50c2fb2d6a2a7`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00567690 <.data+0x166a90>:
  567690:	8b 3d 74 27 fe 00    	mov    edi,DWORD PTR ds:0xfe2774
  567696:	8b 37                	mov    esi,DWORD PTR [edi]
  567698:	68 58 a4 d6 00       	push   0xd6a458
  56769d:	e8 6e de 18 00       	call   0x6f5510
  5676a2:	8b 37                	mov    esi,DWORD PTR [edi]
  5676a4:	83 c4 04             	add    esp,0x4
  5676a7:	6a 00                	push   0x0
  5676a9:	68 20 98 56 00       	push   0x569820
  5676ae:	e8 fd de 18 00       	call   0x6f55b0
  5676b3:	8b 0f                	mov    ecx,DWORD PTR [edi]
  5676b5:	51                   	push   ecx
  5676b6:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  5676bb:	e8 30 e1 18 00       	call   0x6f57f0
```

### N11. Native Q.EnableObjRender callback binder

- VA `[0x567730,0x567760)`；raw `[0x166B30,0x166B60)`；48 bytes；SHA256 `1bc29dc62f73936dbbb380c1a6619c45916f94adf108853b60d449124a2de4fb`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00567730 <.data+0x166b30>:
  567730:	8b 3d 74 27 fe 00    	mov    edi,DWORD PTR ds:0xfe2774
  567736:	8b 37                	mov    esi,DWORD PTR [edi]
  567738:	68 6c a4 d6 00       	push   0xd6a46c
  56773d:	e8 ce dd 18 00       	call   0x6f5510
  567742:	8b 37                	mov    esi,DWORD PTR [edi]
  567744:	83 c4 04             	add    esp,0x4
  567747:	6a 00                	push   0x0
  567749:	68 80 98 56 00       	push   0x569880
  56774e:	e8 5d de 18 00       	call   0x6f55b0
  567753:	8b 0f                	mov    ecx,DWORD PTR [edi]
  567755:	51                   	push   ecx
  567756:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  56775b:	e8 90 e0 18 00       	call   0x6f57f0
```

### N12. Native Q.Prolog callback binder

- VA `[0x567AF0,0x567B20)`；raw `[0x166EF0,0x166F20)`；48 bytes；SHA256 `e07e39ff97b6c377d3047df67623f17f92e73178b9afe5a7667e22d4572bddc9`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00567af0 <.data+0x166ef0>:
  567af0:	8b 3d 74 27 fe 00    	mov    edi,DWORD PTR ds:0xfe2774
  567af6:	8b 37                	mov    esi,DWORD PTR [edi]
  567af8:	68 d0 a4 d6 00       	push   0xd6a4d0
  567afd:	e8 0e da 18 00       	call   0x6f5510
  567b02:	8b 37                	mov    esi,DWORD PTR [edi]
  567b04:	83 c4 04             	add    esp,0x4
  567b07:	6a 00                	push   0x0
  567b09:	68 d0 9a 56 00       	push   0x569ad0
  567b0e:	e8 9d da 18 00       	call   0x6f55b0
  567b13:	8b 0f                	mov    ecx,DWORD PTR [edi]
  567b15:	51                   	push   ecx
  567b16:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  567b1b:	e8 d0 dc 18 00       	call   0x6f57f0
```

### N13. Native Q.IsPrologRunning callback binder

- VA `[0x567B90,0x567BC0)`；raw `[0x166F90,0x166FC0)`；48 bytes；SHA256 `365b08bdc73a7906f61e20db5ddd8efb95b2116e1de60c015fb5c17d39382e07`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00567b90 <.data+0x166f90>:
  567b90:	8b 3d 74 27 fe 00    	mov    edi,DWORD PTR ds:0xfe2774
  567b96:	8b 37                	mov    esi,DWORD PTR [edi]
  567b98:	68 d8 a4 d6 00       	push   0xd6a4d8
  567b9d:	e8 6e d9 18 00       	call   0x6f5510
  567ba2:	8b 37                	mov    esi,DWORD PTR [edi]
  567ba4:	83 c4 04             	add    esp,0x4
  567ba7:	6a 00                	push   0x0
  567ba9:	68 30 9b 56 00       	push   0x569b30
  567bae:	e8 fd d9 18 00       	call   0x6f55b0
  567bb3:	8b 0f                	mov    ecx,DWORD PTR [edi]
  567bb5:	51                   	push   ecx
  567bb6:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  567bbb:	e8 30 dc 18 00       	call   0x6f57f0
```

### N14. Native Q.EndCutScene C API callback

- VA `[0x568A90,0x568AE6)`；raw `[0x167E90,0x167EE6)`；86 bytes；SHA256 `9fdad3db2e2d8987f7c3289cf61f95a79611a3bdab5c294a5ff26f191c2212a7`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00568a90 <.data+0x167e90>:
  568a90:	55                   	push   ebp
  568a91:	8b ec                	mov    ebp,esp
  568a93:	6a ff                	push   0xffffffff
  568a95:	68 c8 83 93 00       	push   0x9383c8
  568a9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  568aa0:	50                   	push   eax
  568aa1:	83 ec 0c             	sub    esp,0xc
  568aa4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  568aa9:	33 c5                	xor    eax,ebp
  568aab:	50                   	push   eax
  568aac:	8d 45 f4             	lea    eax,[ebp-0xc]
  568aaf:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  568ab5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  568ab8:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  568abb:	33 c0                	xor    eax,eax
  568abd:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  568ac0:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  568ac3:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  568ac6:	8b 0d 78 27 fe 00    	mov    ecx,DWORD PTR ds:0xfe2778
  568acc:	ff 15 80 27 fe 00    	call   DWORD PTR ds:0xfe2780
  568ad2:	b8 01 00 00 00       	mov    eax,0x1
  568ad7:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  568ada:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  568ae1:	59                   	pop    ecx
  568ae2:	8b e5                	mov    esp,ebp
  568ae4:	5d                   	pop    ebp
  568ae5:	c3                   	ret
```

### N15. Native Q.DeleteAllObject C callback

- VA `[0x569700,0x569756)`；raw `[0x168B00,0x168B56)`；86 bytes；SHA256 `ee42902df1578d647fceebfb46560c93f198ba6ef096e9ecbdd199a0d9cb7213`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00569700 <.data+0x168b00>:
  569700:	55                   	push   ebp
  569701:	8b ec                	mov    ebp,esp
  569703:	6a ff                	push   0xffffffff
  569705:	68 c8 83 93 00       	push   0x9383c8
  56970a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  569710:	50                   	push   eax
  569711:	83 ec 0c             	sub    esp,0xc
  569714:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  569719:	33 c5                	xor    eax,ebp
  56971b:	50                   	push   eax
  56971c:	8d 45 f4             	lea    eax,[ebp-0xc]
  56971f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  569725:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  569728:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  56972b:	33 c0                	xor    eax,eax
  56972d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  569730:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  569733:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  569736:	8b 0d 78 27 fe 00    	mov    ecx,DWORD PTR ds:0xfe2778
  56973c:	ff 15 04 28 fe 00    	call   DWORD PTR ds:0xfe2804
  569742:	b8 01 00 00 00       	mov    eax,0x1
  569747:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  56974a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  569751:	59                   	pop    ecx
  569752:	8b e5                	mov    esp,ebp
  569754:	5d                   	pop    ebp
  569755:	c3                   	ret
```

### N16. Native Q.LoadMap C callback

- VA `[0x569760,0x5697BC)`；raw `[0x168B60,0x168BBC)`；92 bytes；SHA256 `f39e8f90689ed516389b0feaee97661d47187c12bdc1f844b8fb82af6f36a6a0`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00569760 <.data+0x168b60>:
  569760:	55                   	push   ebp
  569761:	8b ec                	mov    ebp,esp
  569763:	6a ff                	push   0xffffffff
  569765:	68 c8 83 93 00       	push   0x9383c8
  56976a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  569770:	50                   	push   eax
  569771:	83 ec 0c             	sub    esp,0xc
  569774:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  569779:	33 c5                	xor    eax,ebp
  56977b:	50                   	push   eax
  56977c:	8d 45 f4             	lea    eax,[ebp-0xc]
  56977f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  569785:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  569788:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  56978b:	33 c0                	xor    eax,eax
  56978d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  569790:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  569793:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  569796:	8b 0d 08 28 fe 00    	mov    ecx,DWORD PTR ds:0xfe2808
  56979c:	51                   	push   ecx
  56979d:	8d 45 e8             	lea    eax,[ebp-0x18]
  5697a0:	e8 5b 0b 00 00       	call   0x56a300
  5697a5:	83 c4 04             	add    esp,0x4
  5697a8:	b8 01 00 00 00       	mov    eax,0x1
  5697ad:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5697b0:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5697b7:	59                   	pop    ecx
  5697b8:	8b e5                	mov    esp,ebp
  5697ba:	5d                   	pop    ebp
  5697bb:	c3                   	ret
```

### N17. Native Q.RestoreMap C callback

- VA `[0x5697C0,0x569816)`；raw `[0x168BC0,0x168C16)`；86 bytes；SHA256 `12e10fc2b8025ab1a65e2f6db6c598c8cdbd9fd2276229a8453c802ad337b33c`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005697c0 <.data+0x168bc0>:
  5697c0:	55                   	push   ebp
  5697c1:	8b ec                	mov    ebp,esp
  5697c3:	6a ff                	push   0xffffffff
  5697c5:	68 c8 83 93 00       	push   0x9383c8
  5697ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5697d0:	50                   	push   eax
  5697d1:	83 ec 0c             	sub    esp,0xc
  5697d4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5697d9:	33 c5                	xor    eax,ebp
  5697db:	50                   	push   eax
  5697dc:	8d 45 f4             	lea    eax,[ebp-0xc]
  5697df:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5697e5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5697e8:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  5697eb:	33 c0                	xor    eax,eax
  5697ed:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  5697f0:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  5697f3:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  5697f6:	8b 0d 78 27 fe 00    	mov    ecx,DWORD PTR ds:0xfe2778
  5697fc:	ff 15 0c 28 fe 00    	call   DWORD PTR ds:0xfe280c
  569802:	b8 01 00 00 00       	mov    eax,0x1
  569807:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  56980a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  569811:	59                   	pop    ecx
  569812:	8b e5                	mov    esp,ebp
  569814:	5d                   	pop    ebp
  569815:	c3                   	ret
```

### N18. Native Q.Prolog C callback

- VA `[0x569AD0,0x569B2C)`；raw `[0x168ED0,0x168F2C)`；92 bytes；SHA256 `242004d94c540e53667325e2c6c77699156e133f465319a50124b0ef7d78e0a8`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00569ad0 <.data+0x168ed0>:
  569ad0:	55                   	push   ebp
  569ad1:	8b ec                	mov    ebp,esp
  569ad3:	6a ff                	push   0xffffffff
  569ad5:	68 c8 83 93 00       	push   0x9383c8
  569ada:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  569ae0:	50                   	push   eax
  569ae1:	83 ec 0c             	sub    esp,0xc
  569ae4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  569ae9:	33 c5                	xor    eax,ebp
  569aeb:	50                   	push   eax
  569aec:	8d 45 f4             	lea    eax,[ebp-0xc]
  569aef:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  569af5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  569af8:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  569afb:	33 c0                	xor    eax,eax
  569afd:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  569b00:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  569b03:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  569b06:	8b 0d 2c 28 fe 00    	mov    ecx,DWORD PTR ds:0xfe282c
  569b0c:	51                   	push   ecx
  569b0d:	8d 45 e8             	lea    eax,[ebp-0x18]
  569b10:	e8 1b 09 00 00       	call   0x56a430
  569b15:	83 c4 04             	add    esp,0x4
  569b18:	b8 01 00 00 00       	mov    eax,0x1
  569b1d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  569b20:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  569b27:	59                   	pop    ecx
  569b28:	8b e5                	mov    esp,ebp
  569b2a:	5d                   	pop    ebp
  569b2b:	c3                   	ret
```

### N19. Native Q.IsPrologRunning C callback start

- VA `[0x569B30,0x569B90)`；raw `[0x168F30,0x168F90)`；96 bytes；SHA256 `4d3f5a0efc53fe542f52533e26213f883d1a29825a29f1ee9c310189113b0e5a`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00569b30 <.data+0x168f30>:
  569b30:	55                   	push   ebp
  569b31:	8b ec                	mov    ebp,esp
  569b33:	6a ff                	push   0xffffffff
  569b35:	68 d8 87 93 00       	push   0x9387d8
  569b3a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  569b40:	50                   	push   eax
  569b41:	83 ec 0c             	sub    esp,0xc
  569b44:	56                   	push   esi
  569b45:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  569b4a:	33 c5                	xor    eax,ebp
  569b4c:	50                   	push   eax
  569b4d:	8d 45 f4             	lea    eax,[ebp-0xc]
  569b50:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  569b56:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  569b59:	33 c0                	xor    eax,eax
  569b5b:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  569b5e:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  569b61:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  569b64:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  569b67:	8b 0d 78 27 fe 00    	mov    ecx,DWORD PTR ds:0xfe2778
  569b6d:	ff 15 30 28 fe 00    	call   DWORD PTR ds:0xfe2830
  569b73:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  569b76:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  569b79:	db 45 08             	fild   DWORD PTR [ebp+0x8]
  569b7c:	c7 40 08 03 00 00 00 	mov    DWORD PTR [eax+0x8],0x3
  569b83:	dd 18                	fstp   QWORD PTR [eax]
  569b85:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  569b89:	b8 01 00 00 00       	mov    eax,0x1
  569b8e:	8b 4d              	mov    ecx,DWORD PTR [ebp-0xc]
```

### N20. Lua integer coercion and indirect Q.Prolog invocation

- VA `[0x56A430,0x56A4A3)`；raw `[0x169830,0x1698A3)`；115 bytes；SHA256 `ed9871da5aa7b7fb1b47dd2cdb5602c38d2554a686fe84960f2c53d470fcd479`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0056a430 <.data+0x169830>:
  56a430:	55                   	push   ebp
  56a431:	8b ec                	mov    ebp,esp
  56a433:	8b 08                	mov    ecx,DWORD PTR [eax]
  56a435:	83 ec 18             	sub    esp,0x18
  56a438:	53                   	push   ebx
  56a439:	8b 1d 78 27 fe 00    	mov    ebx,DWORD PTR ds:0xfe2778
  56a43f:	83 c8 ff             	or     eax,0xffffffff
  56a442:	e8 a9 ac 18 00       	call   0x6f50f0
  56a447:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  56a44a:	83 f9 03             	cmp    ecx,0x3
  56a44d:	74 2a                	je     0x56a479
  56a44f:	83 f9 04             	cmp    ecx,0x4
  56a452:	75 40                	jne    0x56a494
  56a454:	56                   	push   esi
  56a455:	8b 30                	mov    esi,DWORD PTR [eax]
  56a457:	57                   	push   edi
  56a458:	83 c6 10             	add    esi,0x10
  56a45b:	8d 7d f8             	lea    edi,[ebp-0x8]
  56a45e:	e8 fd d2 18 00       	call   0x6f7760
  56a463:	5f                   	pop    edi
  56a464:	5e                   	pop    esi
  56a465:	85 c0                	test   eax,eax
  56a467:	74 2b                	je     0x56a494
  56a469:	dd 45 f8             	fld    QWORD PTR [ebp-0x8]
  56a46c:	c7 45 f0 03 00 00 00 	mov    DWORD PTR [ebp-0x10],0x3
  56a473:	dd 5d e8             	fstp   QWORD PTR [ebp-0x18]
  56a476:	8d 45 e8             	lea    eax,[ebp-0x18]
  56a479:	dd 00                	fld    QWORD PTR [eax]
  56a47b:	dd 5d f0             	fstp   QWORD PTR [ebp-0x10]
  56a47e:	dd 45 f0             	fld    QWORD PTR [ebp-0x10]
  56a481:	db 5d fc             	fistp  DWORD PTR [ebp-0x4]
  56a484:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  56a487:	50                   	push   eax
  56a488:	8b cb                	mov    ecx,ebx
  56a48a:	ff 55 08             	call   DWORD PTR [ebp+0x8]
  56a48d:	33 c0                	xor    eax,eax
  56a48f:	5b                   	pop    ebx
  56a490:	8b e5                	mov    esp,ebp
  56a492:	5d                   	pop    ebp
  56a493:	c3                   	ret
  56a494:	33 c0                	xor    eax,eax
  56a496:	50                   	push   eax
  56a497:	8b cb                	mov    ecx,ebx
  56a499:	ff 55 08             	call   DWORD PTR [ebp+0x8]
  56a49c:	33 c0                	xor    eax,eax
  56a49e:	5b                   	pop    ebx
  56a49f:	8b e5                	mov    esp,ebp
  56a4a1:	5d                   	pop    ebp
  56a4a2:	c3                   	ret
```

### N21. OnEndTalk UI/native callback calls Lua function by name

- VA `[0x6BD720,0x6BD7E7)`；raw `[0x2BCB20,0x2BCBE7)`；199 bytes；SHA256 `357c1922b79144abbbb7683f5b12cfd20c2bbef9aa39c2af098cef690793ee3c`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

006bd720 <.data+0x2bcb20>:
  6bd720:	55                   	push   ebp
  6bd721:	8b ec                	mov    ebp,esp
  6bd723:	6a ff                	push   0xffffffff
  6bd725:	68 7c a7 93 00       	push   0x93a77c
  6bd72a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6bd730:	50                   	push   eax
  6bd731:	51                   	push   ecx
  6bd732:	56                   	push   esi
  6bd733:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6bd738:	33 c5                	xor    eax,ebp
  6bd73a:	50                   	push   eax
  6bd73b:	8d 45 f4             	lea    eax,[ebp-0xc]
  6bd73e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  6bd744:	8b f1                	mov    esi,ecx
  6bd746:	f6 05 a4 72 fb 00 01 	test   BYTE PTR ds:0xfb72a4,0x1
  6bd74d:	75 27                	jne    0x6bd776
  6bd74f:	83 0d a4 72 fb 00 01 	or     DWORD PTR ds:0xfb72a4,0x1
  6bd756:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  6bd75d:	e8 ee 20 de ff       	call   0x49f850
  6bd762:	68 e0 cf bc 00       	push   0xbccfe0
  6bd767:	e8 ae 4b 1d 00       	call   0x89231a
  6bd76c:	83 c4 04             	add    esp,0x4
  6bd76f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  6bd776:	ba a8 72 fb 00       	mov    edx,0xfb72a8
  6bd77b:	e8 c0 2d de ff       	call   0x4a0540
  6bd780:	f6 05 d4 f3 fd 00 01 	test   BYTE PTR ds:0xfdf3d4,0x1
  6bd787:	75 27                	jne    0x6bd7b0
  6bd789:	b8 01 00 00 00       	mov    eax,0x1
  6bd78e:	09 05 d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,eax
  6bd794:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  6bd797:	e8 e4 6b 03 00       	call   0x6f4380
  6bd79c:	68 d0 e6 bc 00       	push   0xbce6d0
  6bd7a1:	e8 74 4b 1d 00       	call   0x89231a
  6bd7a6:	83 c4 04             	add    esp,0x4
  6bd7a9:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  6bd7b0:	68 ac 02 c1 00       	push   0xc102ac
  6bd7b5:	6a 00                	push   0x0
  6bd7b7:	68 c8 f3 fd 00       	push   0xfdf3c8
  6bd7bc:	e8 df f8 de ff       	call   0x4ad0a0
  6bd7c1:	8b 06                	mov    eax,DWORD PTR [esi]
  6bd7c3:	8b 90 d4 00 00 00    	mov    edx,DWORD PTR [eax+0xd4]
  6bd7c9:	8b ce                	mov    ecx,esi
  6bd7cb:	ff d2                	call   edx
  6bd7cd:	c7 86 9c 00 00 00 00 	mov    DWORD PTR [esi+0x9c],0x0
  6bd7d4:	00 00 00 
  6bd7d7:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6bd7da:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6bd7e1:	59                   	pop    ecx
  6bd7e2:	5e                   	pop    esi
  6bd7e3:	8b e5                	mov    esp,ebp
  6bd7e5:	5d                   	pop    ebp
  6bd7e6:	c3                   	ret
```

### N22. ScenarioTalkTable native registration basis

- VA `[0x6BCFC0,0x6BD047)`；raw `[0x2BC3C0,0x2BC447)`；135 bytes；SHA256 `02cd9e9906a7e4eba911dc299d9437de7fb18c95d25fc8f8ac0be7c04ecfa93e`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

006bcfc0 <.data+0x2bc3c0>:
  6bcfc0:	b8 01 00 00 00       	mov    eax,0x1
  6bcfc5:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  6bcfc8:	84 05 d4 f3 fd 00    	test   BYTE PTR ds:0xfdf3d4,al
  6bcfce:	75 1f                	jne    0x6bcfef
  6bcfd0:	09 05 d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,eax
  6bcfd6:	88 45 fc             	mov    BYTE PTR [ebp-0x4],al
  6bcfd9:	e8 a2 73 03 00       	call   0x6f4380
  6bcfde:	68 d0 e6 bc 00       	push   0xbce6d0
  6bcfe3:	e8 32 53 1d 00       	call   0x89231a
  6bcfe8:	83 c4 04             	add    esp,0x4
  6bcfeb:	c6 45 fc 00          	mov    BYTE PTR [ebp-0x4],0x0
  6bcfef:	a1 c8 f3 fd 00       	mov    eax,ds:0xfdf3c8
  6bcff4:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  6bcff7:	89 71 08             	mov    DWORD PTR [ecx+0x8],esi
  6bcffa:	83 40 08 10          	add    DWORD PTR [eax+0x8],0x10
  6bcffe:	89 35 7c 31 fe 00    	mov    DWORD PTR ds:0xfe317c,esi
  6bd004:	89 35 80 31 fe 00    	mov    DWORD PTR ds:0xfe3180,esi
  6bd00a:	8b 35 c8 f3 fd 00    	mov    esi,DWORD PTR ds:0xfdf3c8
  6bd010:	bf 28 eb c3 00       	mov    edi,0xc3eb28
  6bd015:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  6bd01a:	e8 71 87 03 00       	call   0x6f5790
  6bd01f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  6bd026:	8b cb                	mov    ecx,ebx
  6bd028:	c7 03 9c 90 c4 00    	mov    DWORD PTR [ebx],0xc4909c
  6bd02e:	e8 4d 83 08 00       	call   0x745380
  6bd033:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6bd036:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6bd03d:	59                   	pop    ecx
  6bd03e:	5f                   	pop    edi
  6bd03f:	5e                   	pop    esi
  6bd040:	5b                   	pop    ebx
  6bd041:	8b e5                	mov    esp,ebp
  6bd043:	5d                   	pop    ebp
  6bd044:	c2 04 00             	ret    0x4
```

### N23. Native scene entry Event/SceneList pair lookup with state write

- VA `[0x565720,0x56578E)`；raw `[0x164B20,0x164B8E)`；110 bytes；SHA256 `6fd1483f22342272cb2c767abcda4759ed0c890f16733ae478732172f3a28fd8`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00565720 <.data+0x164b20>:
  565720:	55                   	push   ebp
  565721:	8b ec                	mov    ebp,esp
  565723:	83 e4 f8             	and    esp,0xfffffff8
  565726:	6a ff                	push   0xffffffff
  565728:	68 e8 fb 93 00       	push   0x93fbe8
  56572d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  565733:	50                   	push   eax
  565734:	83 ec 34             	sub    esp,0x34
  565737:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56573c:	33 c4                	xor    eax,esp
  56573e:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  565742:	53                   	push   ebx
  565743:	57                   	push   edi
  565744:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  565749:	33 c4                	xor    eax,esp
  56574b:	50                   	push   eax
  56574c:	8d 44 24 40          	lea    eax,[esp+0x40]
  565750:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  565756:	83 7e 28 00          	cmp    DWORD PTR [esi+0x28],0x0
  56575a:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  56575d:	c6 86 89 00 00 00 01 	mov    BYTE PTR [esi+0x89],0x1
  565764:	74 17                	je     0x56577d
  565766:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  565769:	50                   	push   eax
  56576a:	51                   	push   ecx
  56576b:	68 ac 06 c1 00       	push   0xc106ac
  565770:	e8 eb 83 18 00       	call   0x6edb60
  565775:	83 c4 0c             	add    esp,0xc
  565778:	e9 e8 02 00 00       	jmp    0x565a65
  56577d:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  565780:	bb 01 00 00 00       	mov    ebx,0x1
  565785:	89 56 38             	mov    DWORD PTR [esi+0x38],edx
  565788:	89 46 3c             	mov    DWORD PTR [esi+0x3c],eax
  56578b:	89 5e 28             	mov    DWORD PTR [esi+0x28],ebx
```

### N24. Common scene transition caller continuation

- VA `[0x561ED1,0x561F0B)`；raw `[0x1612D1,0x16130B)`；58 bytes；SHA256 `9c3730eb69f44b32f778ce4a8f4aba5fe9eb59bf29778cdd9b979b5b31b383eb`。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00561ed1 <.data+0x1612d1>:
  561ed1:	8b 47 3c             	mov    eax,DWORD PTR [edi+0x3c]
  561ed4:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  561ed7:	50                   	push   eax
  561ed8:	51                   	push   ecx
  561ed9:	68 68 0f fc 00       	push   0xfc0f68
  561ede:	e8 5d c7 f1 ff       	call   0x47e640
  561ee3:	33 db                	xor    ebx,ebx
  561ee5:	89 47 3c             	mov    DWORD PTR [edi+0x3c],eax
  561ee8:	3b c3                	cmp    eax,ebx
  561eea:	74 1f                	je     0x561f0b
  561eec:	8b 57 38             	mov    edx,DWORD PTR [edi+0x38]
  561eef:	50                   	push   eax
  561ef0:	52                   	push   edx
  561ef1:	8b f7                	mov    esi,edi
  561ef3:	e8 28 38 00 00       	call   0x565720
  561ef8:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  561efc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  561f03:	59                   	pop    ecx
  561f04:	5f                   	pop    edi
  561f05:	5e                   	pop    esi
  561f06:	5b                   	pop    ebx
  561f07:	8b e5                	mov    esp,ebp
  561f09:	5d                   	pop    ebp
  561f0a:	c3                   	ret
```

## 8. 按玩家情境重建的 Client / Server 界線與反例

| 情境 | 已證 Lua/Client 路徑 | 可能失敗/先決條件 | 不能斷言 |
|---|---|---|---|
| Scene1 first talk | Scene1 `OpenTalkScene(3,22)` → qbase open third arg TRUE → WaitForScene | ScenarioTalkTable UI 必須真的 open 與 callback OnEndTalk | 不能把 3 視 QID3／22 視 S2C opcode |
| Scene2 多段對話 | 四個相繼 `OpenTalkScene`，每次等待 `OnEndTalk` 清 g_scenePlaying | 任一 UI 未結束可能停在 coroutine wait | 不能假定直接一步跳過所有對話 |
| Scene3 Pindos 4 talks | Scene3 Scene3 talks18/24/20/21 加動畫/camera/waits | event playback/資源載入失敗、對話 callback 可卡住 | 不代表自動收到 Quest15 `0x46` complete ack |
| Scene3 Prolog | `DoProlog(1)` → Q.Prolog(1) → WaitForProlog → Q.IsPrologRunning | Prolog callback / runtime handle / wait returns unknown | 沒有原始 Server 任務給獎證據 |
| Scene3 Return | Q.DeleteAllObject → RestoreMap → RevPhase1 | 原生間接 callback 必須正常返回，Lua coroutine 未被中斷 | 不保證持久化位置或一定解鎖下一 Quest |
| Scene4 return | Transition0/hide0; empty LoadMap; no talks; cleanup/RevPhase1 | 空資源名處理取決於 Q.LoadMap handler | 不能當作 server logout / teleport packet |
| Script cancellation | Lua VM coroutine 停止／native callback 失敗 | `RevPhase1` 不一定跑到 EnableInput/EndCutScene | 不可宣稱每條異常路徑都安全恢復 UI |
| TalkBox Quest acceptance | Q15 mode2/mode3 Quest TalkBox 是另一套本地事件/UI，既有 T16-126～128 已證 | 不能混用 qbase ScenarioTalkTable | 此處四幕 `OpenTalkScene` 不會直接證明 C2S 0x36/0x3F |

**Client 待逆向**：ScenarioTalkTable.open 的所有 native UI 分支與 event callback 真正處理條件、`Q.Prolog` 注入 callback 的目標 writer、`Q.RestoreMap` UI/場景恢復後是否通知控制器 NEXT、`Q.EndCutScene` 間接目標的完整局部效應，以及 coroutine 在 VM 錯誤下是否強制 RevPhase1。這些不以『缺原版 Server』掩蓋，也不為了縮小任務而假裝已證。

**Server 待開發**：正確發出 Quest15 相關業務狀態更新，決定何時發任務/劇情鍵，支援進度、給獎、保存與合法重送策略；本段原始 Lua 沒有給出官方規則演算法。

**跨 Task 待整合**：地圖/Scene resource 存在性與版本、UI callback owner、網路 framing、原始 Table/SceneList rows、任務持久化等；**僅記錄依賴，不在本 Task 派工**，由 S00 自行決定。

**待遊玩驗證**：四幕是否按官方順序觸發；OpenTalkScene 各 `OnEndTalk` 回調時序；DoProlog 顯示與返回；Scene3 `RestoreMap` 實際當前地圖；未成功完成 quest 時重播、斷線／重登；沒有原版執行 trace。

## 9. T16 五研究進度與下輪入口

| 工作 | 狀態 | 交付 / 邊界 |
|---|---|---|
| T16-131 鍵值 writer | Client 有界完成 | NPC / S2C scene keys、FIRST/NEXT consumers |
| T16-132 觸發／排程 | Client 有界完成 | busy gate、NEXT 找不到、特殊事件、清鍵 |
| **T16-133 Lua 任務／UI／返回** | **本稿：Client 有界完成** | 四幕 raw Lua、compiled qbase、native Q callback + OnEndTalk，非 Server 完成 |
| T16-134 雙向封包與 scene | 下一研究 | 追同一事件/控制器狀態來源，確認業務 application packet 與 Scene3 不等價或有條件相關 |
| T16-135 E2E | 待研究 | 整合原生 Client 玩家流程、完成矩陣、精確未知/Server interface |

- 下輪需延用本篇 raw Event STP Lua & compiled qbase bytes `0xA20810..`，**不得重做一般性的全資源掃描**。
- 本地原稿在這裡已完整產生；**GitHub 提交及遠端 SHA 需以工具實際回覆為準**，本稿不事先聲稱已提交。
