# T16-111 — Quest 14 續查：教學 Scenario 14 的 C→S／S→C／Lua 狀態閉環，以及 QuestInfo ID 14 原生未閉合界線

- 建檔：2026-10-30T00:35:35+08:00（Asia/Taipei），作者 `chatgpt-web roy`。
- **研究單位：Quest14-①～⑤ 的延續，主攻 Quest14-②③④⑤**；承接 T16-108/109/110/110-REV 原稿，不重新猜 RR-0005（它屬 T02 登入/Connect）。
- 原始 KR BIN：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；原始 Event.stp：SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。本次重新以 Python 真正讀取位元組驗證。
- 版本：**KR** 原始檔唯讀；不執行、修改、注入遊戲，不執行原始 Lua，不接觸真實 Server；TC 不外推。GNU objdump 使用從真實原件擷取之 `.text` bytes、`-m i386 -M intel`，非僅反編譯器摘要。
- PE 原檔：`.text` VA `0x401000` raw `0x400`，故本文所有 `.text` raw=`VA−0x400C00`；`.rdata` VA `0xBD2000` raw `0x7D0600`，`.data` VA `0xD61000` raw `0x95E800`。
- GitHub 開工 main SHA `e7416169fd20e4fcb0fe2c0b4d6207e4c9b443bc`；依 02/03 共用啟動規範執行 **main → `t16/roy/chatgpt-web` 單向同步**（PR #20，merge SHA `0c8692fd18f510f7634890d626c5a93cd89467b2`），再查 main...branch：ahead=23、behind=0。此為基線同步，**沒有將本研究 Markdown Commit/Push，也沒有改 main**。
- 判斷分級：`NATIVE-CONFIRMED`（指定 Client bytes、路由及 CFG）／`RESOURCE-CONFIRMED`（精確資源內容）／`BOUND`（有條件導出，未實際執行）／`UNKNOWN`（缺少原始 Client 關聯）／`SERVER-S00`（後端獨立設計，**不作為 T16 原生證據阻塞**）。

## A. 主張矩陣：Quest 14 到底還缺哪一項、這次解決了哪一項？

| Quest 14 固定五個子研究 | 前段缺口 | 本次驗證進展 | 截止本次的狀態 |
|---|---|---|---|
| ① QuestInfo 資源／前置 | 已讀 id=14，與 Scenario id14 namespace 待分離 | 本次重核 QuestInfo id14、id16 Demand14，以及 Lua 使用 id14 的不同來源；不存在二者相等的直接合約 | **① 靜態資料完成**（行為權威不是 XML） |
| ② 玩家觸發／教學 Lua | `RequestStartScenario(14)` 雖已知，先前未閉到本地 receiver | Lua Part2 `PlayAndWaitForScene(1000,8)` 後 `Tutorial.RequestStartScenario(14)`，其後 `IsScenarioEnded(14)` yield loop，真正 native receiver table 型別也已定 | **② Scenario14 觸發完成（有界）**；Quest14 接取／初始入口仍未知 |
| ③ C→S／傳送 | 曾有 0x40 四位元組 builder，與 Quest14 UI 尚未確認 | Lua native binding → `0x4AA4D0` → `40 00 0E 00`（長度4，slot0；只有在 gate 成立下排隊／成幀），沿用 T16-107 通用 transport | **③ Scenario14 請求 Client 介面完成（條件式）**；Quest14 accept/turn-in packet 不可自動認同 |
| ④ S→C／狀態／UI | T16-110 僅到 Scene 0x41/0x42/0x7F 記錄 writer，沒有「教學完成」的確切 Client flag | **新閉合 `Scene::CTutorial` 表 B index0x4C → handler `0x4C4F20` → `map[scenarioId]=1` ↔ Lua `IsScenarioEnded` 查同 map**；也核對 init clear/map miss | **④ Scenario14 結束旗標／Lua 消費完成（有界）**；QuestInfo ID14 的任務已完成/可交付與 UI 標記仍未確認 |
| ⑤ Quest14 完成 → Quest16 | XML `Quest16.Demands(14)` 已驗證，卻沒有 C++ Quest 状态 writer ↔ NPC UI 接續 | 客戶端腳本的 scenario-ended 不等於 Quest14 finished；明列 Quest16 可接／狀態回覆 Client 缺口；Server 前置演算法交 S00 | **⑤ 靜態前置完成、原生 Client 狀態閉環未完成** |

**這次的核心結論**：Quest 14 附近真正可證的「Scenario 14 請求→接受某種完成狀態→Lua 繼續」已形成一條完整條件式 Client 鏈。但 QuestInfo 任務 `id=14`、Scenario `id=14`、SceneList `(questIdx,sceneIdx)=(1000,8)` 是三種不同來源/namespace；在找不到共同欄位或 handler 之前，不能把腳本旗標等同任務完成，亦不能宣稱 Quest16 UI 可接或村莊已進場。

## B. 第一輪：從玩家教學 Lua 真正產生 Scenario 14 請求（②③）

### B.1 原始資源與 Lua 5.1 opcode）

- `Event.stp` 的 `Event/TutorialMain.lua` XOR view 位置 `0xA27810`，長度 `5480`，Lua 5.1 bytecode SHA256 `662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809`。本次以獨立 Python Lua 5.1 結構 reader 解析函式 proto，校對 proto5 `line=131..199`。
- proto5 `constants[9]="RequestStartScenario"`, `constants[10]=14.0`, `constants[11]="IsScenarioEnded"`, `[12]="FALSE"`；`constants[0]="PlayAndWaitForScene"`, `[1]=1000.0`, `[2]=8.0`。`1000/8` 是劇情／演出事件雙鍵，不是 `QuestInfo id=14`。
- PC 16–19 調用 `Tutorial.RequestStartScenario(14)`；PC 20–23 呼叫 `Tutorial.IsScenarioEnded(14)` 並取得一個結果；PC24–29 比較 Lua 全域 `FALSE`、呼叫 `yield()`、向後跳轉重查；PC30 以後進入 UI/Checkpoint 並繼續其他 scene。**Lua 是等待本地 status 變化，不是直接執行 Server 任務結算**。
- Lua 同段後續包含 `SetUIPage`、`SetCheckPointStatus(10016,...)`、`PlayAndWaitForScene(1000,10/12/13/14)`、`PostUIMessage_EmployChar` 等；沒有在同一 proto 中直接使用 `QuestInfo id14` 之權威完成 writer。

```text
TutorialMain.lua / proto5（驗證 Lua 5.1 opcode；RK 類常數索引 ≥256 要減去256）
000 | 0x00000005 | GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
001 | 0x00004041 | LOADK A=1 B=0 C=1 Bx=1 sBx=-131070
002 | 0x00008081 | LOADK A=2 B=0 C=2 Bx=2 sBx=-131069
003 | 0x0180401c | CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
004 | 0x0000c005 | GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
005 | 0x00410006 | GETTABLE A=0 B=0 C=260 Bx=260 sBx=-130811
006 | 0x00014041 | LOADK A=1 B=0 C=5 Bx=5 sBx=-131066
007 | 0x00018081 | LOADK A=2 B=0 C=6 Bx=6 sBx=-131065
008 | 0x0180401c | CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
009 | 0x0001c005 | GETGLOBAL A=0 B=0 C=7 Bx=7 sBx=-131064
010 | 0x0080401c | CALL A=0 B=1 C=1 Bx=513 sBx=-130558
011 | 0x0000c005 | GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
012 | 0x00410006 | GETTABLE A=0 B=0 C=260 Bx=260 sBx=-130811
013 | 0x00014041 | LOADK A=1 B=0 C=5 Bx=5 sBx=-131066
014 | 0x00020081 | LOADK A=2 B=0 C=8 Bx=8 sBx=-131063
015 | 0x0180401c | CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
016 | 0x0000c005 | GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
017 | 0x00424006 | GETTABLE A=0 B=0 C=265 Bx=265 sBx=-130806
018 | 0x00028041 | LOADK A=1 B=0 C=10 Bx=10 sBx=-131061
019 | 0x0100401c | CALL A=0 B=2 C=1 Bx=1025 sBx=-130046
020 | 0x0000c005 | GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
021 | 0x0042c006 | GETTABLE A=0 B=0 C=267 Bx=267 sBx=-130804
022 | 0x00028041 | LOADK A=1 B=0 C=10 Bx=10 sBx=-131061
023 | 0x0100801c | CALL A=0 B=2 C=2 Bx=1026 sBx=-130045
024 | 0x00030045 | GETGLOBAL A=1 B=0 C=12 Bx=12 sBx=-131059
025 | 0x00004017 | EQ A=0 B=0 C=1 Bx=1 sBx=-131070
026 | 0x80008016 | JMP A=0 B=256 C=2 Bx=131074 sBx=3
027 | 0x0001c005 | GETGLOBAL A=0 B=0 C=7 Bx=7 sBx=-131064
028 | 0x0080401c | CALL A=0 B=1 C=1 Bx=513 sBx=-130558
029 | 0x7ffd4016 | JMP A=0 B=255 C=501 Bx=131061 sBx=-10
030 | 0x0000c005 | GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
031 | 0x00434006 | GETTABLE A=0 B=0 C=269 Bx=269 sBx=-130802
032 | 0x0080401c | CALL A=0 B=1 C=1 Bx=513 sBx=-130558
033 | 0x0000c005 | GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
034 | 0x00438006 | GETTABLE A=0 B=0 C=270 Bx=270 sBx=-130801
035 | 0x0003c041 | LOADK A=1 B=0 C=15 Bx=15 sBx=-131056
036 | 0x00040085 | GETGLOBAL A=2 B=0 C=16 Bx=16 sBx=-131055
037 | 0x01444086 | GETTABLE A=2 B=2 C=273 Bx=1297 sBx=-129774
038 | 0x000480c5 | GETGLOBAL A=3 B=0 C=18 Bx=18 sBx=-131053
039 | 0x01c4c0c6 | GETTABLE A=3 B=3 C=275 Bx=1811 sBx=-129260
040 | 0x0200401c | CALL A=0 B=4 C=1 Bx=2049 sBx=-129022
041 | 0x0001c005 | GETGLOBAL A=0 B=0 C=7 Bx=7 sBx=-131064
042 | 0x0080401c | CALL A=0 B=1 C=1 Bx=513 sBx=-130558
043 | 0x00000005 | GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
044 | 0x00004041 | LOADK A=1 B=0 C=1 Bx=1 sBx=-131070
045 | 0x00050081 | LOADK A=2 B=0 C=20 Bx=20 sBx=-131051
046 | 0x0180401c | CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
047 | 0x00000005 | GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
048 | 0x00004041 | LOADK A=1 B=0 C=1 Bx=1 sBx=-131070
049 | 0x00054081 | LOADK A=2 B=0 C=21 Bx=21 sBx=-131050
050 | 0x0180401c | CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
051 | 0x0000c005 | GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
052 | 0x00458006 | GETTABLE A=0 B=0 C=278 Bx=278 sBx=-130793
053 | 0x0080401c | CALL A=0 B=1 C=1 Bx=513 sBx=-130558
```

### B.2 Lua call → native 0x40 packet builder

- T16-58/61/65 等先前 BIN 原件曾找到 `RequestStartScenario` Lua native callback registration，`0x4AB8F8` / `0x4AC9E0 → 0x4ACB70` 將 Lua number 轉成整數參數；slot writer `0x4AB8B8` 指向 `0x4AA4D0`。本文再次由原始 BIN 取 `0x4AA4D0` 的相同 bytes，**真正的 S2C 0x4C 與此 C2S 0x40 不能視為同一 opcode**。
- `0x4AA4D4` 檢查 `[0xFBA798]`；`0x4AA4DF` 設 `eax=0x40`；`0x4AA4E4` 寫本地 WORD `0x40`，`0x4AA4E8` 寫 `[ebp+8]` 的低16 bit；`0x4AA4F9` 送 length=4、`0x4AA4FF` 送 slot=0，`0x4AA501` 呼叫 network vtable+0x10。
- 當參數為14十進位：本地業務 payload 精確為 **`40 00 0E 00`**（小端）；只證 Client 嘗試提交到 queue；不能宣稱 Server 收到或接受。
- T16-107 通用底層已證全域 `[FBA854]` 的 RTTI 是 `CIocpNetwork`，vptr `0xC51748`、slot+0x10 `0x8069A0`，以 slot/key0 查 channel 再 `0x8060D0→0x806060` copy/enqueue；`0x804A40→0x8061A0` conditional drain，frame mode0 prefix `[len16,0x1A68]`，mode nonzero 走 0x0BBB XOR/checksum 又可能 fallback；`0x8068B0` 最後 WSASend-like IAT。**注意場景 RequestStartScenario 使用 slot0，而 inbound scene dispatcher 僅在回呼 channel2 才進入 Scene；這是不同欄位/路由，不能合併**。
- Plain 4-byte-payload 包含「可假設的本地 plaintext frame 寫法」`04 00 68 1A 40 00 0E 00`，但是否實際採 plain mode、端點及 Server 時序未知；**不是實測線上封包**。

## C. 第二輪：找到真正的 Tutorial Scene S→C handler 與 Scenario map writer（④）

### C.1 RTTI + class constructor + vtable 與場景專屬表 B（重大新閉合）

- 原始 PE RTTI：Scene constructor `0x4C4AC0` 使用 `0x4ADD50` 初始化基底 handler、清零 `this+0x5EAC` 起 `0x5EA8` bytes 的另一表，`0x4C4AD5` 安裝 `vtable=0xC073E8`；vptr-4 的 COL 指向 `0xC69E04`，其 TypeDescriptor `0xF7E1E0` 名字 **`.?AVCTutorial@Scene@@`**（原 BIN `.data` 字串）。由此原生確認是 `Scene::CTutorial`，而非僅靠 `TUTO` 字面推測。
- 具體專屬 handler 寫入：`0x4C4AED mov [this+0x610C],0x4C4F20`，`0x4C4AF7 mov [this+0x6110],0xBF2375`；B表以 `this+0x5EAC` 起、8-byte stride，所以 `(0x610C-0x5EAC)/8=0x4C`。此 index 0x4C 只有在 CTutorial 建構完成並已安裝為當前 Scene 時才導向此 handler；不同 Scene 的 override/基底 fallback 不得假設相同。
- `0x4930E0` 由 `CClient+0x140` embedded receive worker callback 進入，處理 business payload first WORD 命令索引；**接收 channel==2** 時轉到 current scene vtable+4 `0x4C4670`；該 Scene dispatcher 先使用表 B (`this+0x5EAC+8*index`)，若 null 才去表 A (`0x4FDA30` 和 `0x4ADD50` 設的基底表)。這條是一般有條件 S2C 路由，不等於同一回覆必然來自對應 C2S RequestStartScenario。
- 之前 T16-110 針對 Scene base A 表的 `0x41/0x42/0x7F` 解碼是**其它** S2C 記錄命令；在 CTutorial 0x4C 專屬 handler 找到後，不能把 `0x41/42/7F` 誤當 Scenario14 結束 flag 的唯一入口。

### C.2 `0x4C4F20` 真正 Client 狀態更新：key 16-bit，map value DWORD1

- `0x4C4F72 mov eax,[ebp+8]` 拿回已解框 business payload 指標；`0x4C4F75 movzx ecx,word [eax+2]` 讀 **payload offset+2 的 unsigned 16-bit 值**；`0x4C4F7C` 傳 global map base `0xFC0F88` 給 `0x4C2880` map operator[]；`0x4C4F89 mov DWORD[eax],1` 更新該鍵 value。`0x4C4F8F xor eax,eax`，`ret 0xC`。
- 對場景 `0x4C` 路由，首WORD應是 `0x004C`，次 WORD 為 key，則**最小具有此 handler 所讀欄位的解框後 payload 4 bytes**；若 key=14，本地內容形態 **`4C 00 0E 00`**。這是「可以驅動該 handler 的 Client contract 下限」，**不是從原版 Server 捕獲之樣本**，也不代表已驗證 wire frame prefix、實際 Server 是否下發 key14、Client 是否接受附加尾部。
- `0x4C4F20` 沒有在取 `[data+2]` 前看到本地 `len>=4` 檢查。因此設計相容 Server 時必須遵守已知最小資料要求；但不能單憑這點宣稱 network parser 無任何其他長度保護。

### C.3 `0x4C2880` 沒有 key 時插入 0、`IsScenarioEnded` read 有 side effect

- RB-tree-like `0x4C2880` 先比對 map key；沒命中便以 `[ebp-4]=0` 作新 value 的初始化值呼叫 `0x57EF20` 與 `0x4AB9E0`，返回 `node+0x10` value 指標；命中則直接返回 `existing_node+0x10`。不是在值不存在時返回不確定垃圾。
- `0x4AA510` 用 `this+4` 取得該 map，`call 0x4C2880`，讀 `*value_ptr`；因此 Lua 的 `IsScenarioEnded(14)` 反覆讀取時，如 key14 尚不存在，可能**先插入值0的記錄**；之後由 S2C handler 覆寫值1。

### C.4 最重要的新交叉證據：`0xFC0F88` 就是 Lua getter 的同一張 map

- `0x48D7D9 mov eax,0xFC0F84` → `0x48D7DE call 0x4A88E0`；`0x4A88ED call 0x4AA5A0` 將 EAX=owner 傳給 `0x4AA5AB mov [0xFE1804],eax`；這是 Lua native callback 所讀 `this` owner。
- `0x4AB958 mov [0xFE1880],0x4AA510`、`0x4AB998 push 0xD6AD80`（`IsScenarioEnded` 名稱）及 `0x4AB9A7..0x4AB9AE` 綁定 Lua `0x4ACA40`，故 getter 指向的是 *確切* `0x4AA510`。
- `0x4ACA76` 取 callback function pointer `FE1880` 並傳 `0x4ACF90`；`0x4ACF96 mov eax,[0xFE1804]` 取得上述 owner；`0x4ACFE6` 以浮點數轉成整數 key，`0x4ACFF0 call [ebp+C]` 最終呼叫 getter；結果以 Lua number 3 放回 Lua stack。
- `0x4AA510` 取 `this+4`，故 owner `0xFC0F84` + 4 = **`0xFC0F88`**，正好與 S2C handler 的 map base `0xFC0F88` 相同。此處**同一實體容器指標鏈**已被二條彼此獨立的原始函式證實，解決原先以事件名稱猜測的薄弱推論。

## D. 第三輪：場景進入/重置，訊息時序反證，Quest 與 Scenario 區分（①②④⑤）

- CTutorial 的 `0x4C4D3A mov esi,0xFC0F84; 0x4C4D3F call 0x4A8A60`；`0x4A8A87 lea edi,[esi+4]`、`0x4A8A94 call 0x823850` 清空**同一張 scenario state map**；另初始化腳本與本地資料，可能送出命令 0x000C（在該 helper 中 6-byte payload，與0x40/0x4C不能混成單一 Quest 進度訊息）。所以如果先接收 0x4C 再經此 init 清 map，先前 flag 可能被抹掉；需要 Client 的場景啟動先於結束回覆的有界時序。
- `0x4C4F20` 的 map writer **不包含**任何「QuestInfo id14 completed」、Quest16 unlocked、NPC10027 完成狀態、持久化或獎勵 Client writer 的直接指令。不能由同為數字14就宣稱它改寫正式任務。
- `QuestInfo.xml` 原始資源的 `id=14`：`type=3,town=0,field=18,level=1,giver=10027,finisher=10027,subtype=1`；`<CompleteAction type="1"/>`、`<AcceptAction type="1"/>`。這是 UI/靜態任務資料結構，不代表 Server 接收哪個 win status。
- `QuestInfo.xml` 的 `id=16` 有 `<Demands><Demand id="14"/></Demands>`，`id=15` 有 `<Demand id="16"/>`；前置鏈為原始資源宣告。**未見本次已定位的 0x4C map writer 連到 QuestInfo id=14 的資料 owner `[0xFB114C]` 或 Quest runtime owner `[0xFAB134]`。**
- 先前已定位 S2C local records 的 `0x4B2190`（scene base table A index66）、`0x4B2310`（index65）與 `0x4B23C0`（index127）、runtime record owner `0xFAB134`、UI `0x635CA0` 過濾及旗標 `B4/B5`，但**不可把 key 字面14、`0xF4266` event，或 `0x5DF3A0` mail attachment vtable 與 Quest14 直接等同**。相同 word/key 不是身份證據；T16-110-REV 的反證仍有效。
- `0x4930E0` 的 word+len check順序及 `0x4C4F20` 的 len 使用需以實際 native CFG/Caller 保留；static analysis 不構成 runtime crash exploit 或官方 socket sample。

### D.1 完整條件式玩家流程與必要資料

```text
Client: 教學場景 `Scene::CTutorial` 已建構／為當前 Scene
  ├─ init: 0x4C4D3A -> 0x4A8A60 -> 0x823850: clear FC0F88 map
  ├─ Lua `TutorialMain` Part2
  │    ├─ PlayAndWaitForScene(1000,8)
  │    ├─ Tutorial.RequestStartScenario(14)
  │    │     -> native 0x4AA4D0 builds C2S payload [40 00 0E 00]
  │    │     -> IF FBA798==0 then CIocpNetwork vtbl+10 -> send queue; socket later conditional
  │    └─ LOOP Tutorial.IsScenarioEnded(14) -> Lua yield if ==FALSE
Server S00 (design responsibility, NOT native evidence): decide scenario result/authority
Client receive conditional, application channel2 after IOCP/framing:
  -> 0x4930E0 payload WORD command index 0x4C
  -> 0x4C4670 Scene::CTutorial B-table[0x4C]
  -> 0x4C4F20 read payload WORD at +2 (scenario key)
  -> map_operator[](FC0F88,key)=1
  -> Lua callback 0x4ACA40 -> 0x4ACF90 -> 0x4AA510 (owner FC0F84, same map +4)
  -> IsScenarioEnded(key) returns 1; if key14, Lua Part2 loop can progress
  ... STILL UNKNOWN: QuestInfo ID14 authoritative completed -> Quest16 availability/Quest UI
```

### D.2 辨識必要資料與非必要的官方 Server 原始來源

| 介面 | Client native 已知必要欄位 | Client 已知前置 | 尚未閉合、不可猜的部分 |
|---|---|---|---|
| C2S Tutorial RequestStartScenario | business payload `WORD cmd=0x40; WORD scenarioId`，本地 4 bytes，呼叫 sender slot0 | Lua Part2 呼叫，`[FBA798]==0` 允許 queue-submit、connection slot0 映射存在 | 原 Server 接受/拒絕規則、何時回應、實際 mode/slot/endpoint，不是 T16 解碼器主張 |
| S2C ScenarioEnded Client consumer | unframed payload `WORD cmd=0x4C; WORD scenarioId`（4 bytes 對此 handler 已足夠），於 Scene::CTutorial 表 B、receiver channel2 | CTutorial 活躍，`0x4930E0` 進 scene；map 未被之後 init 再清除 | 其他可能的接收格式、是否有 Server ACK/finished 判定、欄位大於4 bytes的語義 |
| Lua UI progress | `IsScenarioEnded(scenarioId)` → map DWORD 0或1；Lua number 跟 `FALSE` 比 | Lua VM native 介面已註冊，getter owner FE1804 指 FC0F84 | UI 由哪些控件實際繪製 Quest14 completed，未從此 map 直接證實 |
| QuestInfo `id=14` Quest state | 靜態 Quest XML attrs/AcceptAction/CompleteAction，其他 record writer 候選非本次已綁定 | 需額外 Quest runtime authoritative state | **Quest14 accept/complete 的方向別 command、長度、欄位、scene UI consumer 尚未回推出 Client contract** |
| Quest16 available | QuestInfo `id=16` 有 Demand14，屬 Client 靜態前置宣告 | 真正 Quest14 completed/Quest UI update | Server policy 必須 S00 設計；Client 需要何種 state notification 還待 native 補證 |

## E. Client-only 可重現驗證與負例（不聲稱 Server 已如此運作）

以下全為從已驗證的原始指令推導的**離線規格／合成輸入設計**，不是實測遊戲回覆。

| 驗證條件（只限此 handler） | Client 預期局部影響／反證 |
|---|---|
| CTutorial active，payload `4C 00 0E 00`，channel2 routed | `0x4C4F20` 從+2取14，map[14]←1；Lua `IsScenarioEnded(14)` 可讀1 |
| 同一路由 payload `4C 00 0F 00` | map[15]←1，但 `IsScenarioEnded(14)` 若無其他 writer仍是0；反證「任何0x4C都結束Scenario14」 |
| 非 CTutorial Scene | Scene B[0x4C] 未證配置 `0x4C4F20`，可能 fallback base，不能保證更新FC0F88 |
| Lua 在沒有0x4C時先 IsScenarioEnded(14) | map operator[] 若 miss插入預設0；Lua 可保持 waiting；反證「讀取必是 side-effect-free」 |
| 先收到0x4C key14、之後才跑`0x4A8A60` | map clear 可能把 flag1清掉；反證「先收就永遠保留」 |
| data 長度少於4，或 header/channels不適用 | Handler本身未作 len>=4 guard；不可憑此聲稱是可合法提交的封包，也不應擬造健壯行為 |
| 收到0x4C key14 | **不證明** QuestInfo id14 completed、NPC10027交付、Quest16解鎖、獎勵入帳、DB persist |

## F. Quest14 交付 S00 的 Server 開發需求（不要拿 Server 內部規則阻塞 T16）

### F.1 建議 S00 建立草案 SPEC/GAP/TEST，而非正式宣稱官方協定

1. **SPEC-TUTO-14（建議草案）**：KR Client `0x40` 報文 WORD scenario id，vtable sender slot0、4-byte業務payload、enqueue/framing/WSASend條件；回覆 Client 0x4C WORD scenario id、CTutorial Scene+B 進入條件、0xFC0F88 map/ Lua flag effect，聲明此為 *Client acceptance contract* 而非原版 Server 證言。
2. **GAP-QUEST-14-CLIENT-STATE**：QuestInfo id14 的任務狀態由何種 S2C 命令/field/handler更新？完成後 Quest16 NPC available 之 Client consumer 是誰？owner 建議 T16，研究方向以 Scene 0x41/0x42/0x7F、FAB134、FB114C與UI旗標 B4/B5 交叉追 key，不能直接認成已關閉。
3. **ADR-QUEST-14-SERVER**：Scenario14 通關/失敗判定、任務 id14 狀態轉換、Quest16 解鎖、重入/幂等、持久化/角色scope等全部是 Server 自訂設計；T14/T15/T07 的其他分工需 S00 追蹤，不要求還原原版 Server 程式。
4. **TEST-TUTO-14-CLIENT-SYNTH**：把本報告 E 節合成 payload 當 offline unit-vector 或未實測 Client 的模型假說，標明 `SYNTHETIC_NOT_RUNTIME_VERIFIED`；不能將 test green 自動提升 T01 FULL-PASS 或 S00 STABLE。
5. **別的 Task 需定向核對的接口**：T02 framing/channel2/WSARecv保護；T07 CTutorial scene入場/清map時序；T14 Scenario14結果/結算政策；T15 progress snapshot；T06 Quest UI控件身份；T16 Quest14/16專屬 state handler/notification。引用接口，不修改主責或全域台帳。

### F.2 這次正式的研究完成邊界

- **可以正式結案（有界）：** Client tutorial Lua request/loop + native 0x40 builder + CTutorial 0x4C S2C completion map writer + Lua getter 同 map owner identity + init clear，含有效條件/失敗分支。
- **不能宣布已結案：** QuestInfo 任務14 本身正式 completed/accepted/turn-in S2C 封包與 Client state UI、Quest16可接之 Client必要資料，因為目前本輪原始 Client 中**仍缺這兩條具體身份／資料流證據**。這是 Client待分析項，不是「還需要原版Server實作」；S00可先規劃服務需求，但不能將未知字段當已核實Client協定。
- **下輪只追缺口，不再重複已閉合 Scenario14 loop**：以 `QuestInfo id14` 的 record/node 讀端、`Quest16` 靜態 Demands、`0x635CA0` 顯示旗標及 `0x4B2190/0x4B2310/0x4B23C0` S2C 狀態 writer 做 key/slot 對應、初始/交付/重登入 UI 讀端；若獨立來源無法再找到則向 S00 提交 GAP 供後端設計分離處理。
- Git：本輪僅產生本地研究原稿，未將本檔 commit/push；上一段 T01 43 READY_FOR_REVIEW 記錄不在本輪自動改 RESOLVED。

## G. 有界 C++ 形式偽碼（從 BIN 原始指令重建）

```cpp
// Local client behavior only: names invented to explain proved offsets; no Server pseudocode.
void Tutorial_RequestStartScenario(uint16_t id) {
  uint8_t payload[4] = {0x40,0x00,(uint8_t)id,(uint8_t)(id>>8)};
  if (global_FBA798 == 0) CIocpNetwork_Send(channel_key_0, payload, 4);
}
int ScenarioEndedMap_Get(Owner* owner_FC0F84, uint32_t id) {
  // 0x4AA510 -> operator[] 0x4C2880; missing id inserts default DWORD 0
  return operator_index_insert_zero(&owner_FC0F84->map_at_4, id);
}
int CTutorial_OnCommand_004C(const uint8_t* unframed_payload, size_t len_not_locally_guarded, int other) {
  // Only when 0x4C4670 Scene B dispatch selects this handler for active CTutorial.
  // Header word at offset0 is already consumed by dispatcher as command index.
  uint16_t scenarioId = read_le16(unframed_payload + 2);
  operator_index_insert_zero(&global_FC0F88, (uint32_t)scenarioId) = 1;
  return 0;
}
// Lua Part2: RequestStartScenario(14); while IsScenarioEnded(14)==FALSE: yield();
// These functions do NOT alone set QuestInfo questId14 completed or unlock questId16.
```

## H. 原始 x86 Assembly 證據與對應原件 raw bytes（此次從 BIN 即時切片）

讀法：下面每個組語塊從原始 BIN 原始 raw offset 提取，映射只在 `.text` 使用 raw=VA−0x400C00；包含正確 function entry 的塊才推斷 CFG。每個區塊另列前24 byte raw checksum/hex 以便驗證；切片末端可能為下一指令中途，該片段不作獨立語意推論。

### H01 C2S builder 0x0040 — VA `0x4aa4d0..0x4aa509`；raw `0xa98d0..0xa9909`

原件 byte 長度 `57`；SHA256 `e935bd11eb5ead7892c8aec25ddab1737f4f5b889669974b3bcfc859cc5dc028`；首 24-byte `55 8b ec 51 83 3d 98 a7 fb 00 00 66 8b 4d 08 b8 40 00 00 00 66 89 45 fc`。

```asm
  4aa4d0:	55                   	push   ebp
  4aa4d1:	8b ec                	mov    ebp,esp
  4aa4d3:	51                   	push   ecx
  4aa4d4:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4aa4db:	66 8b 4d 08          	mov    cx,WORD PTR [ebp+0x8]
  4aa4df:	b8 40 00 00 00       	mov    eax,0x40
  4aa4e4:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4aa4e8:	66 89 4d fe          	mov    WORD PTR [ebp-0x2],cx
  4aa4ec:	75 15                	jne    0x4aa503
  4aa4ee:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4aa4f4:	8b 11                	mov    edx,DWORD PTR [ecx]
  4aa4f6:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4aa4f9:	6a 04                	push   0x4
  4aa4fb:	8d 45 fc             	lea    eax,[ebp-0x4]
  4aa4fe:	50                   	push   eax
  4aa4ff:	6a 00                	push   0x0
  4aa501:	ff d2                	call   edx
  4aa503:	8b e5                	mov    esp,ebp
  4aa505:	5d                   	pop    ebp
  4aa506:	c2 04 00             	ret    0x4
```

### H02 CTutorial ctor + vptr + B-table slot0x4C — VA `0x4c4ac0..0x4c4b04`；raw `0xc3ec0..0xc3f04`

原件 byte 長度 `68`；SHA256 `e1a0928c0da336ceabf02254b2e983b676a8c62e96d459a5b61624df9ea62935`；首 24-byte `8b c6 e8 89 92 fe ff 68 a8 5e 00 00 8d 86 ac 5e 00 00 6a 00 50 c7 06 e8`。

```asm
  4c4ac0:	8b c6                	mov    eax,esi
  4c4ac2:	e8 89 92 fe ff       	call   0x4add50
  4c4ac7:	68 a8 5e 00 00       	push   0x5ea8
  4c4acc:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4c4ad2:	6a 00                	push   0x0
  4c4ad4:	50                   	push   eax
  4c4ad5:	c7 06 e8 73 c0 00    	mov    DWORD PTR [esi],0xc073e8
  4c4adb:	c7 05 74 a6 d6 00 4f 	mov    DWORD PTR ds:0xd6a674,0x5455544f
  4c4ae2:	54 55 54 
  4c4ae5:	e8 76 9d 3d 00       	call   0x89e860
  4c4aea:	83 c4 0c             	add    esp,0xc
  4c4aed:	c7 86 0c 61 00 00 20 	mov    DWORD PTR [esi+0x610c],0x4c4f20
  4c4af4:	4f 4c 00 
  4c4af7:	c7 86 10 61 00 00 75 	mov    DWORD PTR [esi+0x6110],0xbf2375
  4c4afe:	23 bf 00 
  4c4b01:	8b c6                	mov    eax,esi
  4c4b03:	c3                   	ret
```

### H03 CTutorial command0x4C runtime map writer — VA `0x4c4f20..0x4c4fa0`；raw `0xc4320..0xc43a0`

原件 byte 長度 `128`；SHA256 `6409b0e377c0c5fb5a64f92069c34bd7ec79c50ed62aebaa1d9c7747d7784041`；首 24-byte `55 8b ec 6a ff 68 9e 76 92 00 64 a1 00 00 00 00 50 a1 20 1f d6 00 33 c5`。

```asm
  4c4f20:	55                   	push   ebp
  4c4f21:	8b ec                	mov    ebp,esp
  4c4f23:	6a ff                	push   0xffffffff
  4c4f25:	68 9e 76 92 00       	push   0x92769e
  4c4f2a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c4f30:	50                   	push   eax
  4c4f31:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c4f36:	33 c5                	xor    eax,ebp
  4c4f38:	50                   	push   eax
  4c4f39:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c4f3c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c4f42:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c4f49:	75 27                	jne    0x4c4f72
  4c4f4b:	83 0d 80 0f fc 00 01 	or     DWORD PTR ds:0xfc0f80,0x1
  4c4f52:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4c4f59:	e8 52 5f fb ff       	call   0x47aeb0
  4c4f5e:	68 70 db bc 00       	push   0xbcdb70
  4c4f63:	e8 b2 d3 3c 00       	call   0x89231a
  4c4f68:	83 c4 04             	add    esp,0x4
  4c4f6b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4c4f72:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c4f75:	0f b7 48 02          	movzx  ecx,WORD PTR [eax+0x2]
  4c4f79:	8d 55 08             	lea    edx,[ebp+0x8]
  4c4f7c:	b8 88 0f fc 00       	mov    eax,0xfc0f88
  4c4f81:	89 4d 08             	mov    DWORD PTR [ebp+0x8],ecx
  4c4f84:	e8 f7 d8 ff ff       	call   0x4c2880
  4c4f89:	c7 00 01 00 00 00    	mov    DWORD PTR [eax],0x1
  4c4f8f:	33 c0                	xor    eax,eax
  4c4f91:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4c4f94:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c4f9b:	59                   	pop    ecx
  4c4f9c:	8b e5                	mov    esp,ebp
  4c4f9e:	5d                   	pop    ebp
  4c4f9f:	c2                   	.byte 0xc2
```

### H04 Map operator[] lookup / insert-0 / return value pointer — VA `0x4c2880..0x4c28f7`；raw `0xc1c80..0xc1cf7`

原件 byte 長度 `119`；SHA256 `8d7e68fbae935952f3c2911a7ca2d862f7c31f2f80b90427df4cb5bd15011bcd`；首 24-byte `55 8b ec 83 ec 0c 53 56 8b f0 8b 4e 04 8b 41 04 80 78 15 00 57 8b d9 75`。

```asm
  4c2880:	55                   	push   ebp
  4c2881:	8b ec                	mov    ebp,esp
  4c2883:	83 ec 0c             	sub    esp,0xc
  4c2886:	53                   	push   ebx
  4c2887:	56                   	push   esi
  4c2888:	8b f0                	mov    esi,eax
  4c288a:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  4c288d:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  4c2890:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4c2894:	57                   	push   edi
  4c2895:	8b d9                	mov    ebx,ecx
  4c2897:	75 1b                	jne    0x4c28b4
  4c2899:	8b 0a                	mov    ecx,DWORD PTR [edx]
  4c289b:	eb 03                	jmp    0x4c28a0
  4c289d:	8d 49 00             	lea    ecx,[ecx+0x0]
  4c28a0:	39 48 0c             	cmp    DWORD PTR [eax+0xc],ecx
  4c28a3:	7d 05                	jge    0x4c28aa
  4c28a5:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4c28a8:	eb 04                	jmp    0x4c28ae
  4c28aa:	8b d8                	mov    ebx,eax
  4c28ac:	8b 00                	mov    eax,DWORD PTR [eax]
  4c28ae:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4c28b2:	74 ec                	je     0x4c28a0
  4c28b4:	3b 5e 04             	cmp    ebx,DWORD PTR [esi+0x4]
  4c28b7:	74 07                	je     0x4c28c0
  4c28b9:	8b 02                	mov    eax,DWORD PTR [edx]
  4c28bb:	3b 43 0c             	cmp    eax,DWORD PTR [ebx+0xc]
  4c28be:	7d 2d                	jge    0x4c28ed
  4c28c0:	8b 0a                	mov    ecx,DWORD PTR [edx]
  4c28c2:	8d 7d f8             	lea    edi,[ebp-0x8]
  4c28c5:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  4c28c8:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4c28cf:	e8 4c c6 0b 00       	call   0x57ef20
  4c28d4:	53                   	push   ebx
  4c28d5:	8d 55 fc             	lea    edx,[ebp-0x4]
  4c28d8:	52                   	push   edx
  4c28d9:	8b ce                	mov    ecx,esi
  4c28db:	e8 00 91 fe ff       	call   0x4ab9e0
  4c28e0:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4c28e3:	83 c0 10             	add    eax,0x10
  4c28e6:	5f                   	pop    edi
  4c28e7:	5e                   	pop    esi
  4c28e8:	5b                   	pop    ebx
  4c28e9:	8b e5                	mov    esp,ebp
  4c28eb:	5d                   	pop    ebp
  4c28ec:	c3                   	ret
  4c28ed:	5f                   	pop    edi
  4c28ee:	5e                   	pop    esi
  4c28ef:	8d 43 10             	lea    eax,[ebx+0x10]
  4c28f2:	5b                   	pop    ebx
  4c28f3:	8b e5                	mov    esp,ebp
  4c28f5:	5d                   	pop    ebp
  4c28f6:	c3                   	ret
```

### H05 Map get used by Lua — VA `0x4aa510..0x4aa524`；raw `0xa9910..0xa9924`

原件 byte 長度 `20`；SHA256 `56570b9ffbec6f763df4e278d34c59620e6726cb5fbbe2c42da7151cfa41e8db`；首 24-byte `55 8b ec 8d 41 04 8d 55 08 e8 62 83 01 00 8b 00 5d c2 04 00`。

```asm
  4aa510:	55                   	push   ebp
  4aa511:	8b ec                	mov    ebp,esp
  4aa513:	8d 41 04             	lea    eax,[ecx+0x4]
  4aa516:	8d 55 08             	lea    edx,[ebp+0x8]
  4aa519:	e8 62 83 01 00       	call   0x4c2880
  4aa51e:	8b 00                	mov    eax,DWORD PTR [eax]
  4aa520:	5d                   	pop    ebp
  4aa521:	c2 04 00             	ret    0x4
```

### H06 Native owner pointer writer for Lua interface — VA `0x4aa5a0..0x4aa5bf`；raw `0xa99a0..0xa99bf`

原件 byte 長度 `31`；SHA256 `f71fe2616eb155abbef179a559c76a4e6d858188a6068526c9d29880f1882861`；首 24-byte `55 8b ec 51 53 8b 5d 0c 56 8b 33 a3 04 18 fe 00 8b 46 10 8b 48 44 57 89`。

```asm
  4aa5a0:	55                   	push   ebp
  4aa5a1:	8b ec                	mov    ebp,esp
  4aa5a3:	51                   	push   ecx
  4aa5a4:	53                   	push   ebx
  4aa5a5:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  4aa5a8:	56                   	push   esi
  4aa5a9:	8b 33                	mov    esi,DWORD PTR [ebx]
  4aa5ab:	a3 04 18 fe 00       	mov    ds:0xfe1804,eax
  4aa5b0:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4aa5b3:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  4aa5b6:	57                   	push   edi
  4aa5b7:	89 1d 00 18 fe 00    	mov    DWORD PTR ds:0xfe1800,ebx
  4aa5bd:	3b                   	.byte 0x3b
  4aa5be:	48                   	dec    eax
```

### H07 Owner FC0F84 comes into Lua registry — VA `0x48d7d4..0x48d7e3`；raw `0x8cbd4..0x8cbe3`

原件 byte 長度 `15`；SHA256 `9939e745f28ba70bffe91c51d7dc7254c511d56e657898937d431b14d1ee5d15`；首 24-byte `be c8 f3 fd 00 b8 84 0f fc 00 e8 fd b0 01 00`。

```asm
  48d7d4:	be c8 f3 fd 00       	mov    esi,0xfdf3c8
  48d7d9:	b8 84 0f fc 00       	mov    eax,0xfc0f84
  48d7de:	e8 fd b0 01 00       	call   0x4a88e0
```

### H08 Native Lua `IsScenarioEnded` callback registration — VA `0x4ab940..0x4ab9cf`；raw `0xaad40..0xaadcf`

原件 byte 長度 `143`；SHA256 `b51c5d850f478292bb4df87099e93b5760b4f39a90ed76a339b4b56c7ce2d8c5`；首 24-byte `55 8b ec 8b 45 08 53 8b 1d 00 18 fe 00 56 8b 33 57 8b 38 b8 ee d8 ff ff`。

```asm
  4ab940:	55                   	push   ebp
  4ab941:	8b ec                	mov    ebp,esp
  4ab943:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ab946:	53                   	push   ebx
  4ab947:	8b 1d 00 18 fe 00    	mov    ebx,DWORD PTR ds:0xfe1800
  4ab94d:	56                   	push   esi
  4ab94e:	8b 33                	mov    esi,DWORD PTR [ebx]
  4ab950:	57                   	push   edi
  4ab951:	8b 38                	mov    edi,DWORD PTR [eax]
  4ab953:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4ab958:	c7 05 80 18 fe 00 10 	mov    DWORD PTR ds:0xfe1880,0x4aa510
  4ab95f:	a5 4a 00 
  4ab962:	e8 19 9d 24 00       	call   0x6f5680
  4ab967:	8b 03                	mov    eax,DWORD PTR [ebx]
  4ab969:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4ab96c:	83 e8 10             	sub    eax,0x10
  4ab96f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4ab974:	74 06                	je     0x4ab97c
  4ab976:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4ab97a:	74 14                	je     0x4ab990
  4ab97c:	57                   	push   edi
  4ab97d:	68 c4 26 c4 00       	push   0xc426c4
  4ab982:	e8 36 77 3e 00       	call   0x8930bd
  4ab987:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4ab989:	83 c4 08             	add    esp,0x8
  4ab98c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4ab990:	8b 3d 00 18 fe 00    	mov    edi,DWORD PTR ds:0xfe1800
  4ab996:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab998:	68 80 ad d6 00       	push   0xd6ad80
  4ab99d:	e8 6e 9b 24 00       	call   0x6f5510
  4ab9a2:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab9a4:	83 c4 04             	add    esp,0x4
  4ab9a7:	6a 00                	push   0x0
  4ab9a9:	68 40 ca 4a 00       	push   0x4aca40
  4ab9ae:	e8 fd 9b 24 00       	call   0x6f55b0
  4ab9b3:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4ab9b5:	51                   	push   ecx
  4ab9b6:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4ab9bb:	e8 30 9e 24 00       	call   0x6f57f0
  4ab9c0:	8b 15 00 18 fe 00    	mov    edx,DWORD PTR ds:0xfe1800
  4ab9c6:	8b 02                	mov    eax,DWORD PTR [edx]
  4ab9c8:	83 c4 0c             	add    esp,0xc
  4ab9cb:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
```

### H09 Native Lua wrapper that calls binding — VA `0x4aca40..0x4aca9d`；raw `0xabe40..0xabe9d`

原件 byte 長度 `93`；SHA256 `b8b166fa190bc54ad4365226020532847406b080234591e98583a2b4aed0e676`；首 24-byte `55 8b ec 6a ff 68 c8 83 93 00 64 a1 00 00 00 00 50 83 ec 0c a1 20 1f d6`。

```asm
  4aca40:	55                   	push   ebp
  4aca41:	8b ec                	mov    ebp,esp
  4aca43:	6a ff                	push   0xffffffff
  4aca45:	68 c8 83 93 00       	push   0x9383c8
  4aca4a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4aca50:	50                   	push   eax
  4aca51:	83 ec 0c             	sub    esp,0xc
  4aca54:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4aca59:	33 c5                	xor    eax,ebp
  4aca5b:	50                   	push   eax
  4aca5c:	8d 45 f4             	lea    eax,[ebp-0xc]
  4aca5f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4aca65:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4aca68:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4aca6b:	33 c0                	xor    eax,eax
  4aca6d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4aca70:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4aca73:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4aca76:	8b 0d 80 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe1880
  4aca7c:	51                   	push   ecx
  4aca7d:	8d 55 e8             	lea    edx,[ebp-0x18]
  4aca80:	52                   	push   edx
  4aca81:	e8 0a 05 00 00       	call   0x4acf90
  4aca86:	83 c4 08             	add    esp,0x8
  4aca89:	b8 01 00 00 00       	mov    eax,0x1
  4aca8e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4aca91:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4aca98:	59                   	pop    ecx
  4aca99:	8b e5                	mov    esp,ebp
  4aca9b:	5d                   	pop    ebp
  4aca9c:	c3                   	ret
```

### H10 Lua numeric conversion and callback invocation — VA `0x4acf90..0x4ad019`；raw `0xac390..0xac419`

原件 byte 長度 `137`；SHA256 `6e8aec76b980d9ca1d74821b76457717fabf17e284fd3e182430bbb18e263674`；首 24-byte `55 8b ec 83 ec 14 a1 04 18 fe 00 53 8b 5d 08 8b 0b 89 45 fc 83 c8 ff e8`。

```asm
  4acf90:	55                   	push   ebp
  4acf91:	8b ec                	mov    ebp,esp
  4acf93:	83 ec 14             	sub    esp,0x14
  4acf96:	a1 04 18 fe 00       	mov    eax,ds:0xfe1804
  4acf9b:	53                   	push   ebx
  4acf9c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4acf9f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4acfa1:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4acfa4:	83 c8 ff             	or     eax,0xffffffff
  4acfa7:	e8 44 81 24 00       	call   0x6f50f0
  4acfac:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4acfaf:	83 f9 03             	cmp    ecx,0x3
  4acfb2:	74 2a                	je     0x4acfde
  4acfb4:	83 f9 04             	cmp    ecx,0x4
  4acfb7:	75 5c                	jne    0x4ad015
  4acfb9:	56                   	push   esi
  4acfba:	8b 30                	mov    esi,DWORD PTR [eax]
  4acfbc:	57                   	push   edi
  4acfbd:	83 c6 10             	add    esi,0x10
  4acfc0:	8d 7d f4             	lea    edi,[ebp-0xc]
  4acfc3:	e8 98 a7 24 00       	call   0x6f7760
  4acfc8:	5f                   	pop    edi
  4acfc9:	5e                   	pop    esi
  4acfca:	85 c0                	test   eax,eax
  4acfcc:	74 47                	je     0x4ad015
  4acfce:	dd 45 f4             	fld    QWORD PTR [ebp-0xc]
  4acfd1:	c7 45 f4 03 00 00 00 	mov    DWORD PTR [ebp-0xc],0x3
  4acfd8:	dd 5d ec             	fstp   QWORD PTR [ebp-0x14]
  4acfdb:	8d 45 ec             	lea    eax,[ebp-0x14]
  4acfde:	dd 00                	fld    QWORD PTR [eax]
  4acfe0:	dd 5d f4             	fstp   QWORD PTR [ebp-0xc]
  4acfe3:	dd 45 f4             	fld    QWORD PTR [ebp-0xc]
  4acfe6:	db 5d 08             	fistp  DWORD PTR [ebp+0x8]
  4acfe9:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4acfec:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4acfef:	50                   	push   eax
  4acff0:	ff 55 0c             	call   DWORD PTR [ebp+0xc]
  4acff3:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  4acff6:	8b 03                	mov    eax,DWORD PTR [ebx]
  4acff8:	db 45 0c             	fild   DWORD PTR [ebp+0xc]
  4acffb:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4acffe:	c7 41 08 03 00 00 00 	mov    DWORD PTR [ecx+0x8],0x3
  4ad005:	dd 19                	fstp   QWORD PTR [ecx]
  4ad007:	83 40 08 10          	add    DWORD PTR [eax+0x8],0x10
  4ad00b:	b8 01 00 00 00       	mov    eax,0x1
  4ad010:	5b                   	pop    ebx
  4ad011:	8b e5                	mov    esp,ebp
  4ad013:	5d                   	pop    ebp
  4ad014:	c3                   	ret
  4ad015:	33 c0                	xor    eax,eax
  4ad017:	eb d3                	jmp    0x4acfec
```

### H11 Reset scenario map on tutorial scene re-entry — VA `0x4a8a60..0x4a8b5d`；raw `0xa7e60..0xa7f5d`

原件 byte 長度 `253`；SHA256 `0f8b0f82b9127873e2c5ab4183b585bd333594efcc82d83d71f3aead9e4d7e66`；首 24-byte `55 8b ec 6a ff 68 4c a4 93 00 64 a1 00 00 00 00 50 83 ec 08 53 57 a1 20`。

```asm
  4a8a60:	55                   	push   ebp
  4a8a61:	8b ec                	mov    ebp,esp
  4a8a63:	6a ff                	push   0xffffffff
  4a8a65:	68 4c a4 93 00       	push   0x93a44c
  4a8a6a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a8a70:	50                   	push   eax
  4a8a71:	83 ec 08             	sub    esp,0x8
  4a8a74:	53                   	push   ebx
  4a8a75:	57                   	push   edi
  4a8a76:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a8a7b:	33 c5                	xor    eax,ebp
  4a8a7d:	50                   	push   eax
  4a8a7e:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a8a81:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a8a87:	8d 7e 04             	lea    edi,[esi+0x4]
  4a8a8a:	c7 05 a0 a7 fb 00 00 	mov    DWORD PTR ds:0xfba7a0,0x0
  4a8a91:	00 00 00 
  4a8a94:	e8 b7 ad 37 00       	call   0x823850
  4a8a99:	8d 7e 14             	lea    edi,[esi+0x14]
  4a8a9c:	e8 7f 89 3a 00       	call   0x851420
  4a8aa1:	bb 01 00 00 00       	mov    ebx,0x1
  4a8aa6:	83 cf ff             	or     edi,0xffffffff
  4a8aa9:	84 1d 54 73 fb 00    	test   BYTE PTR ds:0xfb7354,bl
  4a8aaf:	75 22                	jne    0x4a8ad3
  4a8ab1:	09 1d 54 73 fb 00    	or     DWORD PTR ds:0xfb7354,ebx
  4a8ab7:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4a8abe:	e8 0d a9 0a 00       	call   0x5533d0
  4a8ac3:	68 00 d1 bc 00       	push   0xbcd100
  4a8ac8:	e8 4d 98 3e 00       	call   0x89231a
  4a8acd:	83 c4 04             	add    esp,0x4
  4a8ad0:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4a8ad3:	89 1d b4 73 fb 00    	mov    DWORD PTR ds:0xfb73b4,ebx
  4a8ad9:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  4a8adf:	75 1e                	jne    0x4a8aff
  4a8ae1:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  4a8ae7:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4a8aea:	e8 91 e9 0d 00       	call   0x587480
  4a8aef:	68 c0 cc bc 00       	push   0xbcccc0
  4a8af4:	e8 21 98 3e 00       	call   0x89231a
  4a8af9:	83 c4 04             	add    esp,0x4
  4a8afc:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4a8aff:	b8 0f 00 00 00       	mov    eax,0xf
  4a8b04:	39 05 ec ad fa 00    	cmp    DWORD PTR ds:0xfaadec,eax
  4a8b0a:	74 07                	je     0x4a8b13
  4a8b0c:	a3 f0 ad fa 00       	mov    ds:0xfaadf0,eax
  4a8b11:	eb 05                	jmp    0x4a8b18
  4a8b13:	e8 88 1e 0e 00       	call   0x58a9a0
  4a8b18:	84 1d 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,bl
  4a8b1e:	75 13                	jne    0x4a8b33
  4a8b20:	09 1d 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,ebx
  4a8b26:	68 10 cf bc 00       	push   0xbccf10
  4a8b2b:	e8 ea 97 3e 00       	call   0x89231a
  4a8b30:	83 c4 04             	add    esp,0x4
  4a8b33:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a8b3a:	b8 0c 00 00 00       	mov    eax,0xc
  4a8b3f:	66 89 45 ec          	mov    WORD PTR [ebp-0x14],ax
  4a8b43:	89 5d ee             	mov    DWORD PTR [ebp-0x12],ebx
  4a8b46:	75 15                	jne    0x4a8b5d
  4a8b48:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a8b4e:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a8b50:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a8b53:	6a 06                	push   0x6
  4a8b55:	8d 45 ec             	lea    eax,[ebp-0x14]
  4a8b58:	50                   	push   eax
  4a8b59:	6a 00                	push   0x0
  4a8b5b:	ff d2                	call   edx
```

### H12 CTutorial invokes map clear — VA `0x4c4d3a..0x4c4d55`；raw `0xc413a..0xc4155`

原件 byte 長度 `27`；SHA256 `5d35199021475b979a6fcdb75c8245b6198b67386a48a3dbd30e843dd3898bf4`；首 24-byte `be 84 0f fc 00 e8 1c 3d fe ff 33 c0 8b 4c 24 18 64 89 0d 00 00 00 00 59`。

```asm
  4c4d3a:	be 84 0f fc 00       	mov    esi,0xfc0f84
  4c4d3f:	e8 1c 3d fe ff       	call   0x4a8a60
  4c4d44:	33 c0                	xor    eax,eax
  4c4d46:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4c4d4a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c4d51:	59                   	pop    ecx
  4c4d52:	5f                   	pop    edi
  4c4d53:	5e                   	pop    esi
  4c4d54:	5b                   	pop    ebx
```

### H13 Native Scene B table then A fallback dispatcher — VA `0x4c4670..0x4c46ef`；raw `0xc3a70..0xc3aef`

原件 byte 長度 `127`；SHA256 `37f57829353d3a7fadea370c9a7d0b6a0b45bca11565e09d5eadda96b2d71c4d`；首 24-byte `55 8b ec 8b 45 10 53 56 57 0f bf f8 8b f1 8b 9c fe ac 5e 00 00 85 db 75`。

```asm
  4c4670:	55                   	push   ebp
  4c4671:	8b ec                	mov    ebp,esp
  4c4673:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c4676:	53                   	push   ebx
  4c4677:	56                   	push   esi
  4c4678:	57                   	push   edi
  4c4679:	0f bf f8             	movsx  edi,ax
  4c467c:	8b f1                	mov    esi,ecx
  4c467e:	8b 9c fe ac 5e 00 00 	mov    ebx,DWORD PTR [esi+edi*8+0x5eac]
  4c4685:	85 db                	test   ebx,ebx
  4c4687:	75 17                	jne    0x4c46a0
  4c4689:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c468c:	50                   	push   eax
  4c468d:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4c4690:	50                   	push   eax
  4c4691:	51                   	push   ecx
  4c4692:	8b ce                	mov    ecx,esi
  4c4694:	e8 97 93 03 00       	call   0x4fda30
  4c4699:	5f                   	pop    edi
  4c469a:	5e                   	pop    esi
  4c469b:	5b                   	pop    ebx
  4c469c:	5d                   	pop    ebp
  4c469d:	c2 0c 00             	ret    0xc
  4c46a0:	8b 94 fe b0 5e 00 00 	mov    edx,DWORD PTR [esi+edi*8+0x5eb0]
  4c46a7:	6a 06                	push   0x6
  4c46a9:	68 6c 6c bf 00       	push   0xbf6c6c
  4c46ae:	52                   	push   edx
  4c46af:	e8 0a e2 3c 00       	call   0x8928be
  4c46b4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c46b7:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4c46ba:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4c46bd:	83 c4 0c             	add    esp,0xc
  4c46c0:	50                   	push   eax
  4c46c1:	51                   	push   ecx
  4c46c2:	52                   	push   edx
  4c46c3:	8b ce                	mov    ecx,esi
  4c46c5:	ff d3                	call   ebx
  4c46c7:	8b d8                	mov    ebx,eax
  4c46c9:	81 fb 05 40 00 80    	cmp    ebx,0x80004005
  4c46cf:	75 16                	jne    0x4c46e7
  4c46d1:	8b 84 fe b0 5e 00 00 	mov    eax,DWORD PTR [esi+edi*8+0x5eb0]
  4c46d8:	50                   	push   eax
  4c46d9:	57                   	push   edi
  4c46da:	68 74 6c bf 00       	push   0xbf6c74
  4c46df:	e8 7c 94 22 00       	call   0x6edb60
  4c46e4:	83 c4 0c             	add    esp,0xc
  4c46e7:	5f                   	pop    edi
  4c46e8:	5e                   	pop    esi
  4c46e9:	8b c3                	mov    eax,ebx
  4c46eb:	5b                   	pop    ebx
  4c46ec:	5d                   	pop    ebp
  4c46ed:	c2                   	.byte 0xc2
  4c46ee:	0c                   	.byte 0xc
```

### H14 CClient receive callback command extractor / channel gate — VA `0x4930e0..0x49315e`；raw `0x924e0..0x9255e`

原件 byte 長度 `126`；SHA256 `8a906120c0837c398f2bbdbc615535ab87dde1d2e6fea1a4f08634db094c5e75`；首 24-byte `55 8b ec 51 8b 45 0c 53 8b 5d 10 56 57 0f b7 38 8b f1 c6 45 ff 00 85 db`。

```asm
  4930e0:	55                   	push   ebp
  4930e1:	8b ec                	mov    ebp,esp
  4930e3:	51                   	push   ecx
  4930e4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4930e7:	53                   	push   ebx
  4930e8:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  4930eb:	56                   	push   esi
  4930ec:	57                   	push   edi
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
  493137:	8b f8                	mov    edi,eax
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  49313f:	81 ff 00 01 00 00    	cmp    edi,0x100
  493145:	75 0d                	jne    0x493154
  493147:	83 be 8c be 00 00 00 	cmp    DWORD PTR [esi+0xbe8c],0x0
  49314e:	74 04                	je     0x493154
  493150:	c6 45 ff 01          	mov    BYTE PTR [ebp-0x1],0x1
  493154:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  493158:	5f                   	pop    edi
  493159:	5e                   	pop    esi
  49315a:	5b                   	pop    ebx
  49315b:	8b e5                	mov    esp,ebp
  49315d:	5d                   	pop    ebp
```

### H15 old base Scene table command index65 state update and local event (contrast) — VA `0x4b2310..0x4b23bc`；raw `0xb1710..0xb17bc`

原件 byte 長度 `172`；SHA256 `fb0975abdd7d1c0e632f5f17ebd6da9a153f3de6f8dc91ca150eb49251a89c3b`；首 24-byte `55 8b ec 6a ff 68 7e c7 93 00 64 a1 00 00 00 00 50 56 57 a1 20 1f d6 00`。

```asm
  4b2310:	55                   	push   ebp
  4b2311:	8b ec                	mov    ebp,esp
  4b2313:	6a ff                	push   0xffffffff
  4b2315:	68 7e c7 93 00       	push   0x93c77e
  4b231a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b2320:	50                   	push   eax
  4b2321:	56                   	push   esi
  4b2322:	57                   	push   edi
  4b2323:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b2328:	33 c5                	xor    eax,ebp
  4b232a:	50                   	push   eax
  4b232b:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b232e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b2334:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b2337:	83 f8 02             	cmp    eax,0x2
  4b233a:	73 04                	jae    0x4b2340
  4b233c:	33 ff                	xor    edi,edi
  4b233e:	eb 06                	jmp    0x4b2346
  4b2340:	8d 78 fe             	lea    edi,[eax-0x2]
  4b2343:	c1 ef 02             	shr    edi,0x2
  4b2346:	85 ff                	test   edi,edi
  4b2348:	74 22                	je     0x4b236c
  4b234a:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b234d:	83 c6 02             	add    esi,0x2
  4b2350:	e8 0b cd f5 ff       	call   0x40f060
  4b2355:	0f b7 0e             	movzx  ecx,WORD PTR [esi]
  4b2358:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b235b:	66 8b 56 02          	mov    dx,WORD PTR [esi+0x2]
  4b235f:	51                   	push   ecx
  4b2360:	50                   	push   eax
  4b2361:	e8 ca b7 08 00       	call   0x53db30
  4b2366:	83 c6 04             	add    esi,0x4
  4b2369:	4f                   	dec    edi
  4b236a:	75 e4                	jne    0x4b2350
  4b236c:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  4b2373:	75 27                	jne    0x4b239c
  4b2375:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  4b237c:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b2383:	e8 f8 50 0d 00       	call   0x587480
  4b2388:	68 c0 cc bc 00       	push   0xbcccc0
  4b238d:	e8 88 ff 3d 00       	call   0x89231a
  4b2392:	83 c4 04             	add    esp,0x4
  4b2395:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4b239c:	68 66 42 0f 00       	push   0xf4266
  4b23a1:	e8 2a 87 0d 00       	call   0x58aad0
  4b23a6:	83 c4 04             	add    esp,0x4
  4b23a9:	33 c0                	xor    eax,eax
  4b23ab:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4b23ae:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b23b5:	59                   	pop    ecx
  4b23b6:	5f                   	pop    edi
  4b23b7:	5e                   	pop    esi
  4b23b8:	8b e5                	mov    esp,ebp
  4b23ba:	5d                   	pop    ebp
  4b23bb:	c2                   	.byte 0xc2
```

### H16 old base Scene table command index66 variable records (contrast) — VA `0x4b2190..0x4b2238`；raw `0xb1590..0xb1638`

原件 byte 長度 `168`；SHA256 `01ec1f3d5f468082367cabc393ecb933b96acd9f6a8f8cd647d9d57f5935e591`；首 24-byte `55 8b ec 83 e4 f8 6a ff 68 5c 7c 94 00 64 a1 00 00 00 00 50 83 ec 18 53`。

```asm
  4b2190:	55                   	push   ebp
  4b2191:	8b ec                	mov    ebp,esp
  4b2193:	83 e4 f8             	and    esp,0xfffffff8
  4b2196:	6a ff                	push   0xffffffff
  4b2198:	68 5c 7c 94 00       	push   0x947c5c
  4b219d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b21a3:	50                   	push   eax
  4b21a4:	83 ec 18             	sub    esp,0x18
  4b21a7:	53                   	push   ebx
  4b21a8:	56                   	push   esi
  4b21a9:	57                   	push   edi
  4b21aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b21af:	33 c4                	xor    eax,esp
  4b21b1:	50                   	push   eax
  4b21b2:	8d 44 24 28          	lea    eax,[esp+0x28]
  4b21b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b21bc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b21c3:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b21c6:	8d 46 04             	lea    eax,[esi+0x4]
  4b21c9:	bb 04 00 00 00       	mov    ebx,0x4
  4b21ce:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b21d2:	75 29                	jne    0x4b21fd
  4b21d4:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4b21db:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  4b21e2:	00 
  4b21e3:	e8 78 dc 04 00       	call   0x4ffe60
  4b21e8:	68 00 cf bc 00       	push   0xbccf00
  4b21ed:	e8 28 01 3e 00       	call   0x89231a
  4b21f2:	83 c4 04             	add    esp,0x4
  4b21f5:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b21fc:	ff 
  4b21fd:	0f bf 76 02          	movsx  esi,WORD PTR [esi+0x2]
  4b2201:	bf a0 b2 fa 00       	mov    edi,0xfab2a0
  4b2206:	e8 05 df 04 00       	call   0x500110
  4b220b:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  4b220e:	8b ff                	mov    edi,edi
  4b2210:	3b fb                	cmp    edi,ebx
  4b2212:	0f 86 ae 00 00 00    	jbe    0x4b22c6
  4b2218:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b221c:	0f b6 48 01          	movzx  ecx,BYTE PTR [eax+0x1]
  4b2220:	8d 70 01             	lea    esi,[eax+0x1]
  4b2223:	49                   	dec    ecx
  4b2224:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4b2228:	83 f9 0a             	cmp    ecx,0xa
  4b222b:	0f 87 95 00 00 00    	ja     0x4b22c6
  4b2231:	ff 24 8d e0 22 4b 00 	jmp    DWORD PTR [ecx*4+0x4b22e0]
```

### H17 native map initialization FC0F88 — VA `0x47aeb0..0x47af24`；raw `0x7a2b0..0x7a324`

原件 byte 長度 `116`；SHA256 `3b67c35e196848e4948f4a55a84661d6a81dbb9f6793ceaeb88732cf2ce6398c`；首 24-byte `55 8b ec 6a ff 68 da b6 90 00 64 a1 00 00 00 00 50 83 ec 24 53 56 a1 20`。

```asm
  47aeb0:	55                   	push   ebp
  47aeb1:	8b ec                	mov    ebp,esp
  47aeb3:	6a ff                	push   0xffffffff
  47aeb5:	68 da b6 90 00       	push   0x90b6da
  47aeba:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47aec0:	50                   	push   eax
  47aec1:	83 ec 24             	sub    esp,0x24
  47aec4:	53                   	push   ebx
  47aec5:	56                   	push   esi
  47aec6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47aecb:	33 c5                	xor    eax,ebp
  47aecd:	50                   	push   eax
  47aece:	8d 45 f4             	lea    eax,[ebp-0xc]
  47aed1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47aed7:	33 f6                	xor    esi,esi
  47aed9:	6a 18                	push   0x18
  47aedb:	c7 45 e8 84 0f fc 00 	mov    DWORD PTR [ebp-0x18],0xfc0f84
  47aee2:	89 35 90 0f fc 00    	mov    DWORD PTR ds:0xfc0f90,esi
  47aee8:	e8 7b 63 41 00       	call   0x891268
  47aeed:	83 c4 04             	add    esp,0x4
  47aef0:	3b c6                	cmp    eax,esi
  47aef2:	0f 84 ef 00 00 00    	je     0x47afe7
  47aef8:	a3 8c 0f fc 00       	mov    ds:0xfc0f8c,eax
  47aefd:	89 00                	mov    DWORD PTR [eax],eax
  47aeff:	a1 8c 0f fc 00       	mov    eax,ds:0xfc0f8c
  47af04:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  47af07:	a1 8c 0f fc 00       	mov    eax,ds:0xfc0f8c
  47af0c:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  47af0f:	a1 8c 0f fc 00       	mov    eax,ds:0xfc0f8c
  47af14:	bb 01 00 00 00       	mov    ebx,0x1
  47af19:	88 58 14             	mov    BYTE PTR [eax+0x14],bl
  47af1c:	8b 0d 8c 0f fc 00    	mov    ecx,DWORD PTR ds:0xfc0f8c
  47af22:	88                   	.byte 0x88
  47af23:	59                   	pop    ecx
```

### H18 Lua callback top-level registration/owner setup — VA `0x4a88e0..0x4a8924`；raw `0xa7ce0..0xa7d24`

原件 byte 長度 `68`；SHA256 `e190ec055c2eaea3b0777c86755dca8d8a8575e6b36f7e51cf1e5f884c1e53b8`；首 24-byte `55 8b ec 83 ec 08 8d 4d fc 56 51 89 30 e8 ae 1c 00 00 83 c4 08 50 e8 85`。

```asm
  4a88e0:	55                   	push   ebp
  4a88e1:	8b ec                	mov    ebp,esp
  4a88e3:	83 ec 08             	sub    esp,0x8
  4a88e6:	8d 4d fc             	lea    ecx,[ebp-0x4]
  4a88e9:	56                   	push   esi
  4a88ea:	51                   	push   ecx
  4a88eb:	89 30                	mov    DWORD PTR [eax],esi
  4a88ed:	e8 ae 1c 00 00       	call   0x4aa5a0
  4a88f2:	83 c4 08             	add    esp,0x8
  4a88f5:	50                   	push   eax
  4a88f6:	e8 85 1d 00 00       	call   0x4aa680
  4a88fb:	50                   	push   eax
  4a88fc:	e8 1f 1e 00 00       	call   0x4aa720
  4a8901:	50                   	push   eax
  4a8902:	e8 b9 1e 00 00       	call   0x4aa7c0
  4a8907:	50                   	push   eax
  4a8908:	e8 53 1f 00 00       	call   0x4aa860
  4a890d:	50                   	push   eax
  4a890e:	e8 ed 1f 00 00       	call   0x4aa900
  4a8913:	50                   	push   eax
  4a8914:	e8 87 20 00 00       	call   0x4aa9a0
  4a8919:	50                   	push   eax
  4a891a:	e8 21 21 00 00       	call   0x4aaa40
  4a891f:	50                   	push   eax
  4a8920:	e8                   	.byte 0xe8
  4a8921:	bb                   	.byte 0xbb
  4a8922:	21 00                	and    DWORD PTR [eax],eax
```

## I. 原始 Lua bytecode 的上/下游復核與精確常數表

```text
Part2 proto 5: lines 131–199, 158 x 4-byte instruction words (raw Event.stp XOR view).
Constants used by the request/response loop and downstream NPC/UI:
K[00] = 'PlayAndWaitForScene'
K[01] = 1000.0
K[02] = 8.0
K[03] = 'Tutorial'
K[04] = 'PostUIMessage_TutoMsg'
K[05] = 0.0
K[06] = 6.0
K[07] = 'yield'
K[08] = 1.0
K[09] = 'RequestStartScenario'
K[10] = 14.0
K[11] = 'IsScenarioEnded'
K[12] = 'FALSE'
K[13] = 'SetUIPage'
K[14] = 'SetCheckPointStatus'
K[15] = 10016.0
K[16] = 'CHECKPOINT_CATEGORY'
K[17] = 'NPC'
K[18] = 'CHECKPOINT_STATUS'
K[19] = 'ST_CLOSE'
K[20] = 10.0
K[21] = 12.0
K[22] = 'HideUI'
K[23] = 'PostUIMessage_EmployChar'
K[24] = 4.0
K[25] = 'g_TutoEmployCharQuery'
K[26] = 'TUTORIAL_PROGRESS_NUMBER'
K[27] = 'TUTORIAL_PINKOHOUSE'
K[28] = 'InsertTutorialCheckPoint'
K[29] = 'GetControlStatus'
K[30] = 'TUTORIAL_POINT'
K[31] = 'RegisterScalingObject'
K[32] = 'Image/Cut_in/Lenart_PinkoRoom.dds'
K[33] = 1024.0
K[34] = 512.0
K[35] = 13.0
K[36] = 'DestroyFlyingObjects'
K[37] = 'IsCharacterAvailable'
K[38] = 2.0
K[39] = 'ST_OPEN'
K[40] = 'TUTORIAL_STARTSCENARIO'
```

### Lua Part2 110–157：等待後仍有獨立 UI / 使用者選擇步驟（不是 Quest14 done writer）

```text
110 | 0x0000c005 | GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
111 | 0x00490006 | GETTABLE A=0 B=0 C=292 Bx=292 sBx=-130779
112 | 0x0080401c | CALL A=0 B=1 C=1 Bx=513 sBx=-130558
113 | 0x0000c005 | GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
114 | 0x00494006 | GETTABLE A=0 B=0 C=293 Bx=293 sBx=-130778
115 | 0x00098041 | LOADK A=1 B=0 C=38 Bx=38 sBx=-131033
116 | 0x0100801c | CALL A=0 B=2 C=2 Bx=1026 sBx=-130045
117 | 0x00030045 | GETGLOBAL A=1 B=0 C=12 Bx=12 sBx=-131059
118 | 0x00004017 | EQ A=0 B=0 C=1 Bx=1 sBx=-131070
119 | 0x80008016 | JMP A=0 B=256 C=2 Bx=131074 sBx=3
120 | 0x0001c005 | GETGLOBAL A=0 B=0 C=7 Bx=7 sBx=-131064
121 | 0x0080401c | CALL A=0 B=1 C=1 Bx=513 sBx=-130558
122 | 0x7ffd4016 | JMP A=0 B=255 C=501 Bx=131061 sBx=-10
123 | 0x0000c005 | GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
124 | 0x00458006 | GETTABLE A=0 B=0 C=278 Bx=278 sBx=-130793
125 | 0x0080401c | CALL A=0 B=1 C=1 Bx=513 sBx=-130558
126 | 0x0000c005 | GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
127 | 0x0045c006 | GETTABLE A=0 B=0 C=279 Bx=279 sBx=-130792
128 | 0x00098041 | LOADK A=1 B=0 C=38 Bx=38 sBx=-131033
129 | 0x0100401c | CALL A=0 B=2 C=1 Bx=1025 sBx=-130046
130 | 0x00064005 | GETGLOBAL A=0 B=0 C=25 Bx=25 sBx=-131046
131 | 0x00030045 | GETGLOBAL A=1 B=0 C=12 Bx=12 sBx=-131059
132 | 0x00004017 | EQ A=0 B=0 C=1 Bx=1 sBx=-131070
133 | 0x80008016 | JMP A=0 B=256 C=2 Bx=131074 sBx=3
134 | 0x0001c005 | GETGLOBAL A=0 B=0 C=7 Bx=7 sBx=-131064
135 | 0x0080401c | CALL A=0 B=1 C=1 Bx=513 sBx=-130558
136 | 0x7ffe0016 | JMP A=0 B=255 C=504 Bx=131064 sBx=-7
137 | 0x00030005 | GETGLOBAL A=0 B=0 C=12 Bx=12 sBx=-131059
138 | 0x00064007 | SETGLOBAL A=0 B=0 C=25 Bx=25 sBx=-131046
139 | 0x0000c005 | GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
140 | 0x00438006 | GETTABLE A=0 B=0 C=270 Bx=270 sBx=-130801
141 | 0x0003c041 | LOADK A=1 B=0 C=15 Bx=15 sBx=-131056
142 | 0x00040085 | GETGLOBAL A=2 B=0 C=16 Bx=16 sBx=-131055
143 | 0x01444086 | GETTABLE A=2 B=2 C=273 Bx=1297 sBx=-129774
144 | 0x000480c5 | GETGLOBAL A=3 B=0 C=18 Bx=18 sBx=-131053
145 | 0x01c9c0c6 | GETTABLE A=3 B=3 C=295 Bx=1831 sBx=-129240
146 | 0x0200401c | CALL A=0 B=4 C=1 Bx=2049 sBx=-129022
147 | 0x00000005 | GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
148 | 0x00004041 | LOADK A=1 B=0 C=1 Bx=1 sBx=-131070
149 | 0x00028081 | LOADK A=2 B=0 C=10 Bx=10 sBx=-131061
150 | 0x0180401c | CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
151 | 0x0000c005 | GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
152 | 0x00410006 | GETTABLE A=0 B=0 C=260 Bx=260 sBx=-130811
153 | 0x00068045 | GETGLOBAL A=1 B=0 C=26 Bx=26 sBx=-131045
154 | 0x00ca0046 | GETTABLE A=1 B=1 C=296 Bx=808 sBx=-130263
155 | 0x00014081 | LOADK A=2 B=0 C=5 Bx=5 sBx=-131066
156 | 0x0180401c | CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
157 | 0x0080001e | RETURN A=0 B=1 C=0 Bx=512 sBx=-130559
```

## J. 完成狀態、標記與後續可操作研究問題

| Quest 14 子研究 | 有界進度 | 下一個可反駁問題 |
|---|---|---|
| ① 靜態 resource | ✅ 完成 | XML quest14/quest16 Demand14已確證；仍不等同運行時判定 |
| ② 玩家觸發 | ✅ Scenario14 Lua 入口完成；⚠ Quest14 獨立 NPC acceptance 未證 | 哪個 native NPC/UI 函式在 QuestInfo id14 上進入接受/交付動作？ |
| ③ C→S | ✅ Scenario14 `0x40` 請求 builder+queue contract 完成；⚠ Quest14 accept/finish C2S 未配對 | `0x636E10` 的0x36 record ID 是否確實定位到 Quest14 id14？先找 record key namespace，再比對 C2S 方向與UI事件 |
| ④ S→C Client consumer | ✅ Scenario14 `0x4C` handler→map→Lua query 完成；⚠ Quest14 finished state/UI 未配對 | 在0x41/42/7F records、QuestInfo `FB114C` map、FAB134與UI控件之間，是否有確實 Quest14 ID14 的同一指標/record？ |
| ⑤ 完成後 Quest16 | ✅ QuestInfo Demand14 靜態關係；⚠ 角色 Quest state/UI與 Server reward政策另設計 | 哪條 native S2C notification 使 Quest16 可選？及這個UI如何消費已完成的14狀態？ |

**合規聲明**：本檔為 KR 原始 BIN 第一手靜態有界研究。沒有原版 Server 源碼不妨礙 Scenario14 Client 必需欄位驗證；Client 尚未解析的 QuestInfo id14 狀態仍需定向逆向，但 Server 決策/持久化應由 S00 管理，不能強行把未知 opcode/bytes 升格為正式 Spec。未執行原始 Client，也未將合成資料當成遊玩驗收。
