# T16-46 — KR Lua 5.1 原生教學腳本的 prototype／opcode／協程與條件分支核查

- 研究者 `chatgpt-web roy`；KR T16（不涉及 TC）；日期 `2026-10-28T10:16:06+08:00`。
- SHA256(KR BIN) `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，size `12472320`；原檔唯讀。
- GitHub `we88ec3-prog/ttr_anal_multi`, main 最近 commit 查詢回報 `4b2f7cc8295df4256b7b1c1f94a33083c2f8a7c1`（commit 搜尋的最近項，非 ref 原子鎖定）；未改 catalog/owner。
- 證據標示：「原生已確認」僅限本輪實際解析位元組／讀取 XML；「部分確認」為本地 script 與 client 邊界；「資訊缺失」為無 server writer/packet 的結果；不可推成可玩驗收。


## 1. 直接來源和驗算

- GitHub `kr/evidence/662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809.txt`：GitHub connector 以 Base64 傳回 bytecode，Lua header `1B 4C 75 61 51 00 01 04 04 04 08 00 00 00`，原始資源 SHA256 `662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809`；5480 bytes。
- GitHub `kr/evidence/d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3.txt`，原始資源 SHA256 `d6e01d85194f452d56961252d797a0e671d7e34a11fe07e96155220f27ee4cc3`；11836 bytes。
- 本輪以 Lua 5.1 32-bit little endian header（int=4, size_t=4, instruction=4, lua_Number=8）逐一解碼 proto 的 code、constant、子 proto 與 debug line/local/upvalue，兩檔分別消耗 `5480/5480`、`11836/11836` bytes，未讀取越界。解析證據不等於執行 Lua，也不等於 callback 皆被執行。

## 2. 原生已確認的函式邊界

| Lua chunk | proto | source lines | instruction words | constants | 已見關鍵 API |
|---|---:|---:|---:|---:|---|
| TutorialMain | root 0 | 0–0 | 25 | 13 | 將具名函式註冊至 Lua 全域環境 |
| TutorialMain | 1 | 6–12 | 17 | 5 | StartCutScene/IsCutSceneRunning |
| TutorialMain | 2 | 18–24 | 13 | 7 | SetKeymapEnabled/PushCamera/RegisterSkipMessage |
| TutorialMain | 3 | 26–34 | 22 | 10 | PlayMusic/PlayAndWaitForScene |
| TutorialMain | 4 | 36–42 | 12 | 6 | DestroyFlyingObjects/PopCamera |
| TutorialMain | 5 | 48–124 | 197 | 34 | Tutorial_Part1: GetTutorialState/GetControlStatus/InsertTutorialCheckPoint/SetCheckPointStatus/CheckLeader/IsLeaderDialogOpened |
| TutorialMain | 6 | 131–199 | 158 | 41 | Tutorial_Part2: RequestStartScenario/IsScenarioEnded/PostUIMessage_EmployChar/IsCharacterAvailable |
| TutorialMain | 7 | 205–221 | 28 | 10 | PlaySynopsisMain、t_executeCoFunction/t_isCoroutineAlive |
| TutorialMain | 8 | 223–273 | 78 | 26 | TutorialMain、Part1 協程、Part2 銜接 |
| TutorialMain | 9 | 274–276 | 4 | 2 | Tutorial_EntryPoint |
| TutorialMain | 10 | 278–280 | 4 | 2 | Synopsis_EntryPoint |
| qbase | root | 0–0 | 173 | 91 | 定義 scene/coroutine 相關全域函式 |
| qbase | 1–75 | 5–552 | 合計 733 | 各自不同 | 75 個子原型，Q/CameraWorks/ScenarioTalkTable/EndCutScene |

註：`TutorialMain` 指令數 25+17+13+22+12+197+158+28+78+4+4 = **558**；`qbase` root 173 + 子原型 733 = **906**；`qbase` 共 76 prototypes。以上計數為真正解析 code 段後相加，不是憑檔名猜測。

## 3. Lua opcode 與跳轉錨點

Lua 5.1 `OP` = low six bits、`A=(instr>>6)&255`、`C=(instr>>14)&511`、`B=(instr>>23)&511`、`Bx=instr>>14`、`sBx=Bx-131071`；跳轉目標 `next_pc+sBx`，以 proto-local 零基 PC 表示。例：

```text
Part1(proto5): pc23 JMP sBx=+3 target=27; pc26 JMP sBx=-9 target=18
Part1(proto5): pc43 JMP sBx=+3 target=47; pc46 JMP sBx=-10 target=37
Part1(proto5): pc80 JMP sBx=+3 target=84; pc83 JMP sBx=-10 target=74
Part1(proto5): pc115 JMP sBx=+3 target=119; pc118 JMP sBx=-9 target=110
Part1(proto5): pc139 JMP sBx=+22 target=162; pc161 JMP sBx=-28 target=134
Part1(proto5): pc187 JMP sBx=+3 target=191; pc190 JMP sBx=-10 target=181
Part2(proto6): pc26 JMP sBx=+3 target=30; pc29 JMP sBx=-10 target=20
Part2(proto6): pc61 JMP sBx=+3 target=65; pc64 JMP sBx=-7 target=58
Part2(proto6): pc83 JMP sBx=+3 target=87; pc86 JMP sBx=-10 target=77
Part2(proto6): pc119 JMP sBx=+3 target=123; pc122 JMP sBx=-10 target=113
Part2(proto6): pc133 JMP sBx=+3 target=137; pc136 JMP sBx=-7 target=130
TutorialMain(proto8): pc22 JMP sBx=+23 target=46;
                     pc29 JMP sBx=+13 target=43; pc42 JMP sBx=+3 target=46;
                     pc45 JMP sBx=-28 target=18
```

原生已確認：這些都是實際 opcode 的 pc/branch。`EQ` 和 `TEST` 控制跳過下一條 JMP 時，需按 Lua 5.1 flag 語意理解，不可只看 `JMP` 方向推定 `true/false`。未追到 server 狀態寫入，僅可稱 client Lua 條件協程。

## 4. Part1／Part2 的細部呼叫順序證據

### Part1 原生 opcode 錨點

```text
pc 18 GETGLOBAL Tutorial; pc20 CALL -> 2 returns; pc21 GETGLOBAL FALSE; pc22 EQ; pc23 JMP target27
pc 24 GETGLOBAL yield; pc25 CALL; pc26 JMP target18
pc 37 GETGLOBAL Tutorial; pc39 LOADK; pc40 CALL -> 2 returns; pc41 GETGLOBAL FALSE; pc42 EQ
pc 44 GETGLOBAL yield; pc45 CALL; pc46 JMP target37
pc 134 GETGLOBAL Tutorial; pc136 CALL ->2 returns; pc137 GETGLOBAL FALSE; pc138 EQ
pc 139 JMP target162; pc 159 GETGLOBAL yield; pc160 CALL; pc161 JMP target134
```

原始常數表包含 `TUTORIAL_KEYBOARD`, `TUTORIAL_MOUSE`, `TUTORIAL_CAMERA`, `TUTORIAL_LEADER_CHANGE`, `TUTORIAL_GOTO_NPC`, `InsertIsilia`, `IsIsiliaFound`, `CheckLeader`, `IsLeaderDialogOpened`。字串來源存在確實，具體 Lua 方法名應由 `GETTABLE` 的 RK 常數參數結合前一個 `GETGLOBAL Tutorial` 追蹤，而不是把所有 `Tutorial` 當作單一方法呼叫。上一輪僅看字串，今輪新增精確 prototype／CFG anchors。

### Part2 原生 opcode 錨點

```text
pc 58  GETGLOBAL g_TutoEmployCharQuery
pc 59  GETGLOBAL FALSE
pc 60  EQ
pc 61  JMP target65
pc 62  GETGLOBAL yield; pc63 CALL
pc 64  JMP target58
pc 65  GETGLOBAL FALSE
pc 66  SETGLOBAL g_TutoEmployCharQuery

pc 130 GETGLOBAL g_TutoEmployCharQuery
pc 131 GETGLOBAL FALSE
pc 132 EQ
pc 133 JMP target137
pc 134 GETGLOBAL yield; pc135 CALL
pc 136 JMP target130
pc 137 GETGLOBAL FALSE
pc 138 SETGLOBAL g_TutoEmployCharQuery
```

**新結論：** `g_TutoEmployCharQuery` 在 Part2 內有兩組獨立的等待／清旗標迴圈。這是 Lua 全域協作旗標，而非已證實的 server Quest16 state；它出現在兩段等待序列，後面均會執行清零。`RequestStartScenario` 與 `IsScenarioEnded` 確實存在 Part2 的函式常數表，但上表尚未解出其完整參數和結果驗證方式，不能自動將前述等待迴圈視為其 server acknowledgment。

### TutorialMain 協程調度

```text
proto8 pc15 GETGLOBAL t_executeCoFunction
proto8 pc16 GETGLOBAL Tutorial_Part1
proto8 pc17 CALL (B=2,C=2)
proto8 pc18 GETGLOBAL t_isCoroutineAlive
proto8 pc20 CALL (B=2,C=2)
proto8 pc22 JMP target46; pc45 JMP target18
proto8 pc38 GETGLOBAL t_removeCoroutine; pc40 CALL
proto8 pc75 GETGLOBAL Tutorial_Part2; pc76 CALL (B=1,C=1)
```

**原生已確認：** Part1 由 coroutine 執行並受存活查詢與迴圈控制；Part2 在該控制分支收束後直接呼叫。`t_removeCoroutine` 在異常／取消候選路徑出現，但必須聯繫 GetControlStatus/StopCutScene 的實際布林條件才可定義為取消。

## 5. qbase 角色／不應混為進度保存

- `qbase` prototype 10 `WaitForScene`、11 `WaitForCamera`、12 `WaitForProlog`、13 `WaitForBook`：有 `yield` 和向後 JMP 等待循環。
- prototypes 17、18 的 `OpenTalkScene` / `OpenAutoTalkScene` 使用 `g_scenePlaying=TRUE`、`ScenarioTalkTable.open`、`WaitForScene`。
- prototype 74（lines 518–547）包含 `EndCameraOverride`, `ScenarioTalkTable.hide`, `showOtherUI`, `EnableObjRender`, `EnableInput`, `EndCutScene`。
- prototype 75（lines 550–552）以 `f_registerCoroutine`／`coroutine.create` 包裝。這是 scene/UI/coroutine 生命週期，不是本輪已見的 Quest completion writer。

## 6. 仍需補全的閉環與 cross-task 邊界

1. **DEFERRED-LOCAL-RESOURCE** `Event/TutorialBase.lua` SHA256 `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744`，本地 `kr-temp-roy/T16-local-20261028/evidence/resources/kr/Event/TutorialBase.lua`；GitHub evidence 指定路徑 404，缺 6 prototypes/72 instruction words 及 Tutorial API 實作橋接。
2. 客戶端 C++ 中 `Tutorial` 物件方法索引與 Lua `GETTABLE` RK 常數的對應，缺逐方法分派；此處不能升級 server writer 語意。
3. `scenario14` 返回進度如何綁接 Part2 的 `IsScenarioEnded`，仍需 T14/T07 原生結果界面與 server ACK。不能替代其主責。
4. Quest16 完成／Quest15 接取之間的 server 資料流仍 **資訊缺失**；本段完成 Lua 結構／分支，不代表教學全節點已還原。
