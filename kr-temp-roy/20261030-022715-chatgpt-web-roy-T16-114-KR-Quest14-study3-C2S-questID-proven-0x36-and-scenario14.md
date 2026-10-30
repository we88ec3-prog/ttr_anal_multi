# T16-114 — Quest14-③：Client→Server 之 QuestInfo ID 追溯、對話確認 `0x36`、Scenario14 `0x40` 與教學初始化 `0x0C`（BIN-first）

- 研究者：`chatgpt-web roy`；檔案建立時間 Asia/Taipei `2026-10-30T02:27:15+08:00`。
- **範圍：KR Quest14 第③子研究**，確認原版 Client「玩家／腳本 → 本地條件 → message builder → queue/framer/socket」；不反推原版 Server 的內部 accept/turn-in 規則。
- 已核對 GitHub `main=54747b31a1c093704785d43b9c599f4bf7fb3907`，T16 分支 `afde51ba3be5ffd539f58d21724b916057c89821`，compare `ahead=26/behind=0`；此份研究未獲 Commit/Push 授權，不上傳 GitHub。main 可能之後更新，不能將此 SHA 當即時狀態。
- 原件 `KR Tartaros.bin`，12,472,320 B，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；原件唯讀，沒有運行／修改／上傳遊戲。
- 原件 `KR Tartaros.exe`，2,594,816 B，SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；原件唯讀，沒有運行／修改／上傳遊戲。
- 原件 `KR Event.stp`，11,241,597 B，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；原件唯讀，沒有運行／修改／上傳遊戲。
- `.text` VA=0x00401000, raw=0x400，故原始 BIN `.text` 區段 `raw=VA−0x00400C00`；`.rdata` VA0xBD2000, raw0x7D0600；不同 PE 區段不可沿用這個換算。所有 assembly 取自本次唯讀 KR BIN，不是聊天生成偽碼。
- 最新 `kr/tasks/T16/task.json` 明確排除原版 Server 內部前置、DB、任務判定；S00 收件箱無 T16 RR；T01 舊勘誤狀態由 T01 審核，本報告不宣稱 FULL-PASS。

## 0. 結論先行：③ 本輪的重要新證據及完成界線

**新發現 A（補足先前 T16-106/107/111/113 的實際缺口）：QuestInfo map 與 TalkBox 所用的 map 是同一個！**

`0x40F930` 回傳常數地址 `0xFAB2A0`，`0x500F90` 讀 `[ECX+0x5EAC]`，算式 `0xFAB2A0 + 0x5EAC = 0xFB114C`；而 `0x4FFEBD` 真正初始化 `[0xFB114C]` 是 `QuestInfo.xml` 的 map。`0x5B6C6E/0x5B6DAE/0x5B6EEE` 從事件 `+0x14` 抽一個 quest-like key，先向 `[FB114C]` 做 `0x503D20` 的 tree lookup，成功後把**相同 key**作為 TalkBox `0x636520` 的第3參數；mode1/2/3 的 `0x63666B/0x63669E/0x6366D1` 用此 key 呼叫 `0x500F90`，結果存在 `dialog+0x88`。這不是兩張不同的 owner record tree。

**新發現 B（XML `id` 真的延續到 C→S payload）：** `0x5048E0` 取得 XML `id` attribute、`0x8917B4` 轉數值，`0x504913` 在即將呼叫下一個 attribute getter、stack 已 `push` 4B 的環境下，`[ESP+0x68]` 實際對應先前暫存 QuestInfo record 基底 `[ESP_before_push+0x64]`（第0 DWORD）。後面 `0x5053FB` 從 `[ESP+0x64]` 複製樹 key，`0x50540E→0x5064D0` 將完整 QuestInfo record 複製到新 node value；`0x506310` 確認 node `+0xC` 是 key、`+0x10` 是 value，`0x500F90` 查找成功回 `node+0x10`。最後 `0x636E82` 讀 `word [dialog+0x88][0]`，因此這個 WORD 是 QuestInfo ID 的低16位（在既有、成功載入的 XML `id=14` 上為 `0x000E`）。

**新發現 C（具體可構成的 Quest14 對話 C→S）：** 當 `QuestInfo id14` 確實從上述事件/QuestInfo map 準備於 TalkBox mode1/2/3，`FUI::CTalkBoxDialog` 收到事件型別 `0xF4402`、其細分 type `0x105BD`、action `0x6A7`、`dialog+0x88 != nullptr`，且 `[0xFBA798]==0`，原生 `0x636E10` 構建**4-byte 業務 payload `36 00 0E 00`**，以 connection key0 交付 `CIocpNetwork.vtable+0x10`。這是**條件式 Client message contract**，而非動態觀測「玩家 Quest14 一定按過此鍵」。`0x6A8`、mode0、missing Quest id、無 selected record、network gate 關閉均不可宣稱同一路徑送 `0x36`。

**已知且獨立的教學訊息：** `0x4A8A60` 教學初始化在 gate 允許下寫 6 bytes：`0C 00 01 00 00 00`；`TutorialMain.lua` 的 `RequestStartScenario(14)` 透過 `0x4AA4D0` 在 gate 允許下建立4-byte `40 00 0E 00`。兩者與 `0x36` 是不同 builder、不同觸發，不能合併成「Quest14 接受封包」。

**③ 結案範圍判定**：已以原始 BIN 有界證明三條 Client C→S builder，其中 `0x36` 的 Quest ID 映射是此段新增重要進展，最終 mode0/plaintext 的 queue/WSASend 條件由 T16-107 既有原生鏈覆蓋。**不能宣稱 Quest14 的手動接受/交付為無條件出現，不能定義 mode1=接受、mode2=完成、mode3=交付，不能把 Scenario14 的 14 當 QuestInfo ID14，也不能將未證的 Server 內部 accept/finish 規則假稱已逆出。**

## 1. 從 Quest XML `id=14` 到 `[dialog+0x88][0]` 的十節點證據鏈

| 節點 | 原生 VA | 輸入→輸出、證據 | 反例／限制 |
|---|---|---|---|
| A | 0x4FFE60,0x4FFEBD | Quest manager 基底 `FAB2A0`；全域 `FB114C` 存 QuestInfo map root | 初始化為 lazy，可失敗 |
| B | 0x504740 | 從 `Table/QuestInfo.xml` 載入記錄，並讀 `id` 屬性 | XML parse failure 無有效 record |
| C | 0x504913 | 呼叫 `0x8917B4` 的轉數值結果 `id` 寫到 record+0（push 後偏移須還原） | 只有 parser valid/ID 可解析才有預期值 |
| D | 0x5053FB~0x505438 | `[ESP+0x64]` 當 tree key，`0x5064D0` 複製 record，`0x506310` + `0x505F70` map insert | 不同的 XML ID 不可被同一鍵混同 |
| E | 0x506384~0x50638F | RB tree node+0xC 保存 key；node+0x10 複製 QuestInfo value（record第一DWORD仍為 XML id） | node+0x10 並非 pointer-to-pointer |
| F | 0x5B6C6E,0x5B6C86 | UI事件來源 `event+0x14` 查同 `[FB114C]`，失敗即跳過 | 此 event+0x14 是否有14取決玩家實際 UI |
| G | 0x5B6CCF~0x5B6CE4 | 成功 branch 同一 key push 第3參數；mode=1 呼叫 `0x636520` | 另有 mode2/3，用其他顯示欄位 |
| H | 0x40F97E,0x500F97 | `0x40F930` returns `FAB2A0`；`FAB2A0+5EAC=FB114C`！`0x500F90` 查的就是這張 map | 真正 alias identity，非名字相似 |
| I | 0x63666B,0x636670 | mode1 `0x500F90` 按同 key 取得 node+0x10 存 `dialog+0x88` | mode0 保持 selected null |
| J | 0x636E82~0x636EA7 | `WORD [selected+0]` 與 cmd `0x0036` 組4B，network vcall +0x10；id14→`36 00 0E 00` | 受事件+gate+連線限制 |

### 1.1 兩個「14」的獨立類型
- QuestInfo XML id14 為 type3，NPC10027；它能經上表的**QuestInfo map 查找**進入 TalkBox 的選擇記錄。
- Lua ScenarioID14 則經 `RequestStartScenario` → `0x40` buffer；其 S2C `0x4C` 在 `Scene::CTutorial` 的 scenario-map 旗標已由 T16-111 確證。兩者雖同為14，並非這次 `0x36` message builder 的同一上游。
- 本次直接消除了「`0x36` 第二 WORD 是否就是 questID」的舊疑問，但**不會**由此消除「Quest14 是否曾被某一UI模式開啟」與「按下之後究竟是接受、完成還是領獎」的未知。

## 2. 三種/四種 TalkBox mode、事件來源與負向分支

| mode | 可達的上游例 | `0x636520` 後果 | `0x36` 機會 | 已確認語意邊界 |
|---:|---|---|---|---|
| 0 | `0x5B6BB2`，event type `0x105BE`，call site pushes mode0 | 清掉 `dialog+0x88`，呼叫 `0x635CA0` 過濾出 UI flags | **無 selected record 就無此 send** | 不能把 mode0 當接取成功 |
| 1 | `0x5B6C86→0x5B6CE4`，type `0x105B9`，Quest map hit | `0x500F90(id)` → `dialog+0x88`；讀 QuestInfo value `+0x30` 供文字 UI | action `0x6A7` 時有條件送 `0x36,id16` | 不把 mode1 自動等於接受 |
| 2 | `0x5B6DC6→0x5B6E24`，type `0x105B9`，Quest map hit | `0x500F90(id)`；讀 value `+0x34` 供文字 UI | 同一個 action+sender builder | mode2 的完成/交付語意仍需 UI 控件/文字對照 |
| 3 | `0x5B6F06→0x5B6F64`，type `0x105B9`，Quest map hit | `0x500F90(id)`；讀 value `+0x38` 供文字 UI | 同一個 action+sender builder | mode3 的語意仍需 UI 控件/文字對照 |

`0x636620` 由 `[dialog+0x90]` 分派 mode 0..3，其四個跳表 entries 已從原始 BIN little-endian 重算：`[0x636630,0x636654,0x636687,0x6366BA]`；mode≥4 不走上述 branch。mode1/2/3 的 message builder**不以 mode 當第二 WORD**，其傳送值始終是 Quest record 第一 WORD 的低16位，因此單一 `0x36,id` 無法靠 bytes 自行區分三個 UI 意圖；Server 可按當前 Quest 狀態定義處理方式，並由 S00 記為 ADR，而不能自稱原版 Server 真實規則。

### 2.1 具體 No-Send / No-Record / 空間與格式
1. Quest XML 未載入/查找失敗：`0x5B6C94→0x5B6D02`，不建立指定 mode 的 selected record。
2. `0x500F90` 對 sentinel miss 回0；`0x636676/0x6366A9/0x6366DC` 採 null branch UI close，不可發送。
3. `0x636DE0` 只在 event DWORD `0xF4402` 走 `0x636E10`；`0x636E21` 的 vcall type 必須等於 `0x105BD`；`0x636E45` action須`0x6A7`；`0x6A8`走無此 send 的虛擬UI後續。
4. `[dialog+0x88]==null` 在 `0x636E4C` 直接退出；`[0xFBA798]!=0` 跳過 network +0x10 call，只走 UI +0xD4。
5. network key0 在 `0x8069A0` map miss／connection null、`0x8060D0` 的 conn+A0A4>300、frame buffer不足、queue 未 drain、WSASend失敗，均不能由 builder 斷言 Server 已收到；與 T16-107 相同原生條件，本段只取必要原始段重驗。

## 3. Scenario14、教學初始化與 Quest14 對話請求三類 Client business payload

| 情境/來源 | 業務資料（little endian） | 實際 builder/條件 | 性質/證據 |
|---|---|---|---|
| CTutorial 初始化（可為任務進場旁路） | `0C 00 01 00 00 00`，6 bytes | `0x4A8B33..0x4A8B5B`，gate `[FBA798]==0`，slot0 | native 6B builder；**不稱 Quest14 accept** |
| Lua Part2 啟動 ScenarioID14 | `40 00 0E 00`，4 bytes | Lua `RequestStartScenario(14)` → `0x4AA4D0`，gate `[FBA798]==0`、slot0 | native4B builder + T16-111/113 Lua證據，**非 QuestInfo ID14 同名推導** |
| UI 指定 QuestInfo id14，mode1/2/3 且確認 | `36 00 0E 00`，4 bytes | event ID `F4402/105BD/6A7` → `0x636E10`，`dialog+0x88 != null`、gate0、slot0 | **本段新閉合 XML id→select record→send payload**。不指定 accept/finish intent |
| UI 旁路條件 `0x596EC0` | `49 00 01 00`，4 bytes，**沒有 questID欄位** | flags `[ESI+5]` 且 `[FBA798]==0`，同 sender接口 slot0 | 原生已存在；不可稱 Quest14 專屬 |

### 3.1 原生 transport 與可能的 frame（僅條件式）
`[FBA854]` 是由 `0x8046F1..0x80470F` 初始化的 `CIocpNetwork`，vptr `0xC51748`，slot+0x10→`0x8069A0`；`0x8060D0` 為小payload配 pending node，`0x806060` 在 lock 下 queue `A074` 並增加 `A078`，`0x804A40→0x8061A0` 按 connection mode flush，mode0 `0x807A70` 使用 `[length16,marker 0x1A68,payload]`，mode nonzero `0x807830` 使用 `[len16,0x0BBB,checksum16] + transformed payload`，成功/不足/回退有條件；`0x8068B0` 至 WSASend-like import。
mode0、length4 的**候選 frame bytes**：`04 00 68 1A 36 00 0E 00` 或 `04 00 68 1A 40 00 0E 00`；length6 的初始化：`06 00 68 1A 0C 00 01 00 00 00`。如果 connection mode!=0，則這些 plaintext bytes **不是**實際 wire buffer。這些是 native builder/framer 的條件推導，**非**封包擷取，亦不承諾 Server 收到。

## 4. 玩家情境→Client gate→C2S→S2C→Client效果→Server 待開發

| 玩家情境 | Client gate / 操作 | C→S | S→C／Client動作 | Server 規格 / 主責 |
|---|---|---|---|---|
| 載入教學 | current CTutorial→`0x4A8A60`，gate0 | 6B `0x0C` 初始化 | 無此對應結果定證；Lua初始 script | S00/T07 設計教學 entry/reentry，驗證初始化先後 |
| 到達 Scenario14 | Lua `(1000,8)`結束後 `RequestStartScenario(14)` | 4B `0x40` + scenario14 | CTutorial B-table index0x4C 收到key14→scenario map14=1；`IsScenarioEnded` Lua繼續 | T14/S00 scenario 開始/成功/失敗/重試政策與相容通知 |
| QuestInfo id14 進指定 TalkBox 模式 | 需 event+14=14、QuestInfo map hit、`dialog+0x88` 有效 | UI 6A7確認時 4B `0x36` + QID14，受全域 sender gate/conn狀態影響 | Quest14 accepted/complete ack/Quest UI 實際 S2C response **未證** | S00 設計 stateful 接受/交付/reject；T16-④仍要對S2C Client state/UI閉合 |
| 文字選項 mode1/2/3 | xml payload+0x30/+0x34/+0x38 供文字展示 | **同一種** `0x36+id` builder；mode未入此4B | 同一個 payload 無法知道 UI 原 mode；Server處理狀態以 ADR | T06 UI資源文字實證，S00 定義狀態與rejection，不等同官方 |
| 取消/擋送 | event6A8、selected null 或 `[FBA798]!=0` | **沒有本條 0x36 send** | UI可能走 vtable+0xD4；未證 S2C | 保留無作用/重試/錯誤通知設計 |
| Quest14完成→Quest16可接 | `<Demand id=14>` XML資源，非動態結果 | 不能用 `0x36` 或 `0x40` 自動代替 Q14完成 | 真正 Quest14 state writer／Q16 UI可接通知未證 | Server state/存檔/前置解鎖交S00/T15；Client待T16-④⑤ |

## 5. 有界 C/C++ 偽碼（手寫解碼，非原始來源）
```cpp
struct QuestXmlNodeValue { uint32_t id; /* +4 type, +... */ };
QuestXmlNodeValue* QuestInfoById(uint32_t id) {
    auto *questMgr = (void*)0xFAB2A0; // 0x40F930
    auto *questInfoMap = *(void**)((char*)questMgr + 0x5EAC); // [0xFB114C]
    auto *node = tree_find(questInfoMap, id); // 0x503D20 via 0x500F90
    return node != sentinel ? (QuestXmlNodeValue*)((char*)node + 0x10) : nullptr;
}
void PrepareTalkBoxByQuestEvent(Event105B9* ev, Controller* controller, int mode) {
    // mode 1/2/3 are different callers, not necessarily "accept/finish/turnin"
    uint32_t id = ev->field_14;
    if (!QuestInfoById(id)) return; // Quest map lookup in 0x5B6C/0x5B6D/0x5B6E
    Dialog* dlg = controller->dialog_224;
    dlg->selected_88 = QuestInfoById(id); // 0x636520 mode1/2/3; null possible
    // text = selected->field_30 / 34 / 38 according to mode
}
void OnTalkAction(Dialog* dlg, Event* e) {
    if (e->kind != 0xF4402 || e->type() != 0x105BD) return;
    if (e->action == 0x6A7 && dlg->selected_88) {
        uint16_t qid16 = (uint16_t)dlg->selected_88->id;
        uint8_t msg[4] = {0x36,0x00,(uint8_t)qid16,(uint8_t)(qid16>>8)};
        if (*(uint32_t*)0xFBA798 == 0) network().enqueue(/*key=*/0,msg,4);
        dlg->virtual_D4(); // local UI continuation, not S2C ack
    } else if (e->action == 0x6A8) dlg->virtual_D4();
}
```

## 6. 三輪深入紀錄與解釋限制

### T16-114 第一輪 — 求解 `0x36` 的 QuestInfo key/record identity（達重大新發現）
- 從 T16-107 的 `0x500F90` 前置呼叫 `0x40F930` 下追到初始化 `0x4FFE60`，直接解出 `0xFAB2A0 + 0x5EAC = 0xFB114C`，證明過去「不同 owner namespace 未知」在這條路徑其實同一個 QuestInfo map。沿 `0x5048E0` XML id→record-first DWORD→`0x506310` map insert→`node+0x10` value，最後至 `0x636E82`，得出了第二WORD身份的新一手證據。
- 本輪已達重大實質增量，但依使用者要求**完整完成 Quest14-③**，仍主動執行第二、第三輪深查 trigger/mode/transport；不因初輪成功便停止。
### T16-114-2 第二輪 — 三種 mode 與 UI 接取/交付的實際語意邊界
- native 逐段核對 `0x5B6C/0x5B6D/0x5B6E` 的 `0x105B9` event key lookup、mode push 1/2/3、`0x636620` branch table、`0x63666B/0x63669E/0x6366D1` query、不同文字欄位 0x30/34/38。`0x636E10` 只讀 `selected+0`，沒有把 mode 放入4-byte msg，也沒有專屬 accept/finish action bit。
- 因此 C2S **業務命令識別和 QuestID欄位**在本題已閉合；若要區分實際玩家接取與交付的 UI 模式，仍應用 T06 文字資源或原生 caller/控件 gating 進一步標註，而不是捏造三個 opcode。
### T16-114-3 第三輪 — sender queue/frame/socket 與相鄰教學請求反證
- 重驗 `0x636E10`、`0x4AA4D0`、`0x4A8A60` 的 bytes、length、sender gate 和 channel0；使用先前 T16-107 已核實 `CIocpNetwork` constructor/vtable/queue/frame/WSASend 有界鏈對照，並只取局部 machine code 再驗，不將網路 flush 視為無條件。
- `0x596F9F` 另有條件性 `0x00010049` 4B 常數訊息，它不攜帶 quest id 14；`0x36`、`0x40`、`0x0C` 三種亦不可互換。從這些候選的局部負證據不能宣稱 BIN 內絕無其他 C2S。
- 停止條件：取得「QuestInfo id14 -> UI selected record -> `0x36` message (4B) -> network vtable queue/framer」**本題完整可復原有界 Client 因果**；仍無法從本地 native 直接斷言 Quest14 type3 一定進 mode1/2/3，亦無法從4B訊息分辨原版 accept/turn-in 或 Server 回覆；此二者留具體界線，不拿原 Server 演算法阻塞 T16 的 Client C2S 封包格式。

## 7. 後續責任、精確未解事項與五項子研究狀態

**Client 待逆向**：Quest14 在遊玩時是否真的觸發 `0x105B9` 該三個 mode 的哪一個、QuestInfo type3 是否可在教學 UI 出現、實際取消/重試事件；Quest14 `0x36` 後的 S2C accept/finish cache/UI 的精確 handler；若另有不經 TalkBox 的 quest state request，尚需從其他 caller 證實。未實測完整 sender/receiver channel mode。

**Server 待開發 → S00**：在 Client 已證之 `0x36,QID16`、`0x40,ScenarioID16` 與初始化 `0x0C` request 各自建 DRAFT SPEC，擬定 Quest14 接取、完成/交付、拒絕、斷線重試、狀態持久化與Quest16解鎖的 Server-side state/ADR；**原版 Server 行為未知不作阻塞理由**。`0x36` 的 event mode 並未上 wire，不能要求 Server 按此欄位分流。
**跨功能待整合**：T02 channel0/mode/framing/WSASend, T06 TalkBox action/UI文字、T07 scene setup、T14 Scenario14結果、T15 角色 Quest 持久化。
**待遊玩驗證**：現階段沒有執行原始 Client / Socket capture；離線契約、成功 queue、實際傳達/回覆和 UI 成功是不同驗收層級。

| Quest14 子研究 | 進度 | 目前精確界線 |
|---|---|---|
| ① 資源、NPC、前置 | **已完成** T16-112 | type3/NPC10027/Demand14 loader/資源 |
| ② 玩家教學觸發 | **教學流程已完成（有界）** T16-113 | QuestInfo type3是否顯示 accept UI 仍未證 |
| **③ Client→Server** | **已完成有界原生封包結構與條件；動態操作配對未證** T16-114 | 新增 `0x36,id14` 可達 message、Scenario14 `0x40,id14` 與 init `0x0C` 分離；不得稱官方 Server接取/交付流程全閉合 |
| ④ Server→Client/任務狀態/UI | **部分** T16-110-REV/111 | ScenarioID14 `0x4C` 結束 map 已知，QuestInfo id14 accepted/completed cache/S2C/UI 未配對 |
| ⑤ Quest14完成→Quest16 | **部分** T16-108/112 | XML Quest16 Demand14；動態解鎖 UI 未證；Server政策交S00 |

## 8. BIN 原始組語及原始位元組證據附錄

所有下列 VA 位於原始 BIN `.text`，`raw_start = VA−0x400C00`；以 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`，**每個切片都有原始 bytes SHA256、起訖及文件可重新計算**。切片起點可能是合法指令根的中間上游上下文，僅採用所述正常入口與分支目標之完整指令，不解讀開頭非對齊雜訊；末端截斷一條指令不作語意證明。

### Quest manager singleton and map +0x5EAC identity — VA `0x0040F930..0x0040F992` raw `0x0000ED30`, 98 B, SHA256 `dbb158f723be91046a3090df28fa9c29fd2ae7da33c633bda5e201e11bbaa31e`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0040f930 <.data+0xed30>:
  40f930:	55                   	push   ebp
  40f931:	8b ec                	mov    ebp,esp
  40f933:	6a ff                	push   0xffffffff
  40f935:	68 ce 59 94 00       	push   0x9459ce
  40f93a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  40f940:	50                   	push   eax
  40f941:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  40f946:	33 c5                	xor    eax,ebp
  40f948:	50                   	push   eax
  40f949:	8d 45 f4             	lea    eax,[ebp-0xc]
  40f94c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  40f952:	b8 01 00 00 00       	mov    eax,0x1
  40f957:	84 05 9c b2 fa 00    	test   BYTE PTR ds:0xfab29c,al
  40f95d:	75 1f                	jne    0x40f97e
  40f95f:	09 05 9c b2 fa 00    	or     DWORD PTR ds:0xfab29c,eax
  40f965:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  40f96c:	e8 ef 04 0f 00       	call   0x4ffe60
  40f971:	68 00 cf bc 00       	push   0xbccf00
  40f976:	e8 9f 29 48 00       	call   0x89231a
  40f97b:	83 c4 04             	add    esp,0x4
  40f97e:	b8 a0 b2 fa 00       	mov    eax,0xfab2a0
  40f983:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  40f986:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  40f98d:	59                   	pop    ecx
  40f98e:	8b e5                	mov    esp,ebp
  40f990:	5d                   	pop    ebp
  40f991:	c3                   	ret
```

### Quest manager constructor global FB114C — VA `0x004FFE60..0x004FFEEA` raw `0x000FF260`, 138 B, SHA256 `bad37cd5a3df51f13a1bc4d94231fbc8b487d24aa4e9023f01fe3884da7bbd64`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004ffe60 <.data+0xff260>:
  4ffe60:	55                   	push   ebp
  4ffe61:	8b ec                	mov    ebp,esp
  4ffe63:	6a ff                	push   0xffffffff
  4ffe65:	68 7e 42 94 00       	push   0x94427e
  4ffe6a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ffe70:	50                   	push   eax
  4ffe71:	83 ec 18             	sub    esp,0x18
  4ffe74:	56                   	push   esi
  4ffe75:	57                   	push   edi
  4ffe76:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ffe7b:	33 c5                	xor    eax,ebp
  4ffe7d:	50                   	push   eax
  4ffe7e:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ffe81:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4ffe87:	c7 45 ec a0 b2 fa 00 	mov    DWORD PTR [ebp-0x14],0xfab2a0
  4ffe8e:	33 f6                	xor    esi,esi
  4ffe90:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4ffe93:	6a 10                	push   0x10
  4ffe95:	c7 05 a0 b2 fa 00 08 	mov    DWORD PTR ds:0xfab2a0,0xc0db08
  4ffe9c:	db c0 00 
  4ffe9f:	e8 c4 13 39 00       	call   0x891268
  4ffea4:	83 c4 04             	add    esp,0x4
  4ffea7:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4ffeaa:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4ffeae:	3b c6                	cmp    eax,esi
  4ffeb0:	74 09                	je     0x4ffebb
  4ffeb2:	8b f8                	mov    edi,eax
  4ffeb4:	e8 b7 44 00 00       	call   0x504370
  4ffeb9:	eb 02                	jmp    0x4ffebd
  4ffebb:	33 c0                	xor    eax,eax
  4ffebd:	a3 4c 11 fb 00       	mov    ds:0xfb114c,eax
  4ffec2:	89 35 50 11 fb 00    	mov    DWORD PTR ds:0xfb1150,esi
  4ffec8:	89 35 54 11 fb 00    	mov    DWORD PTR ds:0xfb1154,esi
  4ffece:	89 35 58 11 fb 00    	mov    DWORD PTR ds:0xfb1158,esi
  4ffed4:	89 35 60 11 fb 00    	mov    DWORD PTR ds:0xfb1160,esi
  4ffeda:	89 35 64 11 fb 00    	mov    DWORD PTR ds:0xfb1164,esi
  4ffee0:	89 35 68 11 fb 00    	mov    DWORD PTR ds:0xfb1168,esi
  4ffee6:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
```

### QuestInfo id XML parse and stack slot before next push — VA `0x005048BE..0x00504944` raw `0x00103CBE`, 134 B, SHA256 `d15b5e9a69da84b5ce6c83e66a6f0dff39f5cce7122c1c653f04c24428290a13`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005048be <.data+0x103cbe>:
  5048be:	8b ff                	mov    edi,edi
  5048c0:	8d 4c 24 64          	lea    ecx,[esp+0x64]
  5048c4:	51                   	push   ecx
  5048c5:	e8 56 b0 ff ff       	call   0x4ff920
  5048ca:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  5048ce:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x1
  5048d5:	01 
  5048d6:	8b 11                	mov    edx,DWORD PTR [ecx]
  5048d8:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  5048db:	ff d0                	call   eax
  5048dd:	8d 78 44             	lea    edi,[eax+0x44]
  5048e0:	68 d0 d1 be 00       	push   0xbed1d0
  5048e5:	e8 b6 b7 22 00       	call   0x7300a0
  5048ea:	bb 10 00 00 00       	mov    ebx,0x10
  5048ef:	85 c0                	test   eax,eax
  5048f1:	74 19                	je     0x50490c
  5048f3:	83 c0 30             	add    eax,0x30
  5048f6:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  5048f9:	72 02                	jb     0x5048fd
  5048fb:	8b 00                	mov    eax,DWORD PTR [eax]
  5048fd:	85 c0                	test   eax,eax
  5048ff:	74 0b                	je     0x50490c
  504901:	50                   	push   eax
  504902:	e8 ad ce 38 00       	call   0x8917b4
  504907:	83 c4 04             	add    esp,0x4
  50490a:	eb 02                	jmp    0x50490e
  50490c:	33 c0                	xor    eax,eax
  50490e:	68 08 b8 bf 00       	push   0xbfb808
  504913:	89 44 24 68          	mov    DWORD PTR [esp+0x68],eax
  504917:	e8 84 b7 22 00       	call   0x7300a0
  50491c:	85 c0                	test   eax,eax
  50491e:	74 19                	je     0x504939
  504920:	83 c0 30             	add    eax,0x30
  504923:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504926:	72 02                	jb     0x50492a
  504928:	8b 00                	mov    eax,DWORD PTR [eax]
  50492a:	85 c0                	test   eax,eax
  50492c:	74 0b                	je     0x504939
  50492e:	50                   	push   eax
  50492f:	e8 80 ce 38 00       	call   0x8917b4
  504934:	83 c4 04             	add    esp,0x4
  504937:	eb 02                	jmp    0x50493b
  504939:	33 c0                	xor    eax,eax
  50493b:	68 94 db c0 00       	push   0xc0db94
  504940:	89 44 24 6c          	mov    DWORD PTR [esp+0x6c],eax
```

### QuestInfo record→map key insertion call — VA `0x005053EF..0x00505464` raw `0x001047EF`, 117 B, SHA256 `618c616021a51672beaa2a704a545ca30f995ab59cb9d237cd15251f89ef20c0`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005053ef <.data+0x1047ef>:
  5053ef:	33 c0                	xor    eax,eax
  5053f1:	8b d8                	mov    ebx,eax
  5053f3:	85 c0                	test   eax,eax
  5053f5:	0f 85 99 fe ff ff    	jne    0x505294
  5053fb:	8b 4c 24 64          	mov    ecx,DWORD PTR [esp+0x64]
  5053ff:	8d 94 24 a8 01 00 00 	lea    edx,[esp+0x1a8]
  505406:	89 8c 24 a4 01 00 00 	mov    DWORD PTR [esp+0x1a4],ecx
  50540d:	52                   	push   edx
  50540e:	8d 4c 24 68          	lea    ecx,[esp+0x68]
  505412:	e8 b9 10 00 00       	call   0x5064d0
  505417:	8b 74 24 3c          	mov    esi,DWORD PTR [esp+0x3c]
  50541b:	8d 84 24 a4 01 00 00 	lea    eax,[esp+0x1a4]
  505422:	50                   	push   eax
  505423:	8b ce                	mov    ecx,esi
  505425:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x8
  50542c:	08 
  50542d:	e8 de 0e 00 00       	call   0x506310
  505432:	50                   	push   eax
  505433:	56                   	push   esi
  505434:	8d 74 24 48          	lea    esi,[esp+0x48]
  505438:	e8 33 0b 00 00       	call   0x505f70
  50543d:	8d 8c 24 a8 01 00 00 	lea    ecx,[esp+0x1a8]
  505444:	51                   	push   ecx
  505445:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x1
  50544c:	01 
  50544d:	e8 6e f1 ff ff       	call   0x5045c0
  505452:	8d 54 24 64          	lea    edx,[esp+0x64]
  505456:	52                   	push   edx
  505457:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x0
  50545e:	00 
  50545f:	e8 5c f1 ff ff       	call   0x5045c0
```

### QuestInfo node key + copied value constructor — VA `0x00506310..0x005063A0` raw `0x00105710`, 144 B, SHA256 `e6e321a7cba7f35cb5b7ad081057a1fbb12744e7a0cdd34d02e02259a035d1ce`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00506310 <.data+0x105710>:
  506310:	55                   	push   ebp
  506311:	8b ec                	mov    ebp,esp
  506313:	6a ff                	push   0xffffffff
  506315:	68 f1 2f 91 00       	push   0x912ff1
  50631a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  506320:	50                   	push   eax
  506321:	83 ec 18             	sub    esp,0x18
  506324:	53                   	push   ebx
  506325:	56                   	push   esi
  506326:	57                   	push   edi
  506327:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50632c:	33 c5                	xor    eax,ebp
  50632e:	50                   	push   eax
  50632f:	8d 45 f4             	lea    eax,[ebp-0xc]
  506332:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  506338:	89 65 f0             	mov    DWORD PTR [ebp-0x10],esp
  50633b:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  50633e:	8b f9                	mov    edi,ecx
  506340:	68 b8 00 00 00       	push   0xb8
  506345:	e8 1e af 38 00       	call   0x891268
  50634a:	8b f0                	mov    esi,eax
  50634c:	33 c9                	xor    ecx,ecx
  50634e:	83 c4 04             	add    esp,0x4
  506351:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  506354:	3b f1                	cmp    esi,ecx
  506356:	74 67                	je     0x5063bf
  506358:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  50635b:	89 06                	mov    DWORD PTR [esi],eax
  50635d:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  506360:	89 56 04             	mov    DWORD PTR [esi+0x4],edx
  506363:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  506366:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  506369:	8d 46 0c             	lea    eax,[esi+0xc]
  50636c:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  50636f:	66 89 8e b4 00 00 00 	mov    WORD PTR [esi+0xb4],cx
  506376:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  506379:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  50637c:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  506380:	3b c1                	cmp    eax,ecx
  506382:	74 10                	je     0x506394
  506384:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  506386:	89 08                	mov    DWORD PTR [eax],ecx
  506388:	83 c0 04             	add    eax,0x4
  50638b:	8d 4b 04             	lea    ecx,[ebx+0x4]
  50638e:	50                   	push   eax
  50638f:	e8 3c 01 00 00       	call   0x5064d0
  506394:	8b c6                	mov    eax,esi
  506396:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  506399:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
```

### QuestInfo copied value first word — VA `0x005064D0..0x0050656A` raw `0x001058D0`, 154 B, SHA256 `857a5f9857f26d9c93531681ed84155c6a1596901770b1a35b5706800130fb41`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005064d0 <.data+0x1058d0>:
  5064d0:	55                   	push   ebp
  5064d1:	8b ec                	mov    ebp,esp
  5064d3:	6a ff                	push   0xffffffff
  5064d5:	68 83 d5 90 00       	push   0x90d583
  5064da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5064e0:	50                   	push   eax
  5064e1:	56                   	push   esi
  5064e2:	57                   	push   edi
  5064e3:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5064e8:	33 c5                	xor    eax,ebp
  5064ea:	50                   	push   eax
  5064eb:	8d 45 f4             	lea    eax,[ebp-0xc]
  5064ee:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5064f4:	8b f9                	mov    edi,ecx
  5064f6:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  5064f9:	8b 07                	mov    eax,DWORD PTR [edi]
  5064fb:	89 06                	mov    DWORD PTR [esi],eax
  5064fd:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  506500:	89 4e 04             	mov    DWORD PTR [esi+0x4],ecx
  506503:	8b 57 08             	mov    edx,DWORD PTR [edi+0x8]
  506506:	89 56 08             	mov    DWORD PTR [esi+0x8],edx
  506509:	8b 47 0c             	mov    eax,DWORD PTR [edi+0xc]
  50650c:	8d 4f 10             	lea    ecx,[edi+0x10]
  50650f:	51                   	push   ecx
  506510:	8d 56 10             	lea    edx,[esi+0x10]
  506513:	52                   	push   edx
  506514:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  506517:	e8 74 25 2e 00       	call   0x7e8a90
  50651c:	33 c0                	xor    eax,eax
  50651e:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  506521:	8b 4f 20             	mov    ecx,DWORD PTR [edi+0x20]
  506524:	89 4e 20             	mov    DWORD PTR [esi+0x20],ecx
  506527:	8b 57 24             	mov    edx,DWORD PTR [edi+0x24]
  50652a:	89 56 24             	mov    DWORD PTR [esi+0x24],edx
  50652d:	8b 4f 28             	mov    ecx,DWORD PTR [edi+0x28]
  506530:	89 4e 28             	mov    DWORD PTR [esi+0x28],ecx
  506533:	8b 57 2c             	mov    edx,DWORD PTR [edi+0x2c]
  506536:	89 56 2c             	mov    DWORD PTR [esi+0x2c],edx
  506539:	8b 4f 30             	mov    ecx,DWORD PTR [edi+0x30]
  50653c:	89 4e 30             	mov    DWORD PTR [esi+0x30],ecx
  50653f:	8b 57 34             	mov    edx,DWORD PTR [edi+0x34]
  506542:	89 56 34             	mov    DWORD PTR [esi+0x34],edx
  506545:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  506548:	89 4e 38             	mov    DWORD PTR [esi+0x38],ecx
  50654b:	8b 57 3c             	mov    edx,DWORD PTR [edi+0x3c]
  50654e:	89 56 3c             	mov    DWORD PTR [esi+0x3c],edx
  506551:	8b 4f 40             	mov    ecx,DWORD PTR [edi+0x40]
  506554:	89 4e 40             	mov    DWORD PTR [esi+0x40],ecx
  506557:	8b 57 44             	mov    edx,DWORD PTR [edi+0x44]
  50655a:	89 56 44             	mov    DWORD PTR [esi+0x44],edx
  50655d:	8b 4f 48             	mov    ecx,DWORD PTR [edi+0x48]
  506560:	89 4e 48             	mov    DWORD PTR [esi+0x48],ecx
  506563:	8d 4e 4c             	lea    ecx,[esi+0x4c]
  506566:	6a ff                	push   0xffffffff
  506568:	89 41              	mov    DWORD PTR [ecx+0x10],eax
```

### QuestInfo tree unique insertion compares key — VA `0x00505F70..0x00506021` raw `0x00105370`, 177 B, SHA256 `81c61013ddcd673ae80a705bd2dc49e70d437f004da4acb4e567b8e511c3c794`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00505f70 <.data+0x105370>:
  505f70:	55                   	push   ebp
  505f71:	8b ec                	mov    ebp,esp
  505f73:	51                   	push   ecx
  505f74:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  505f77:	53                   	push   ebx
  505f78:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  505f7b:	57                   	push   edi
  505f7c:	8b 7a 04             	mov    edi,DWORD PTR [edx+0x4]
  505f7f:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  505f82:	80 b8 b5 00 00 00 00 	cmp    BYTE PTR [eax+0xb5],0x0
  505f89:	b1 01                	mov    cl,0x1
  505f8b:	88 4d fc             	mov    BYTE PTR [ebp-0x4],cl
  505f8e:	75 22                	jne    0x505fb2
  505f90:	8b 4b 0c             	mov    ecx,DWORD PTR [ebx+0xc]
  505f93:	3b 48 0c             	cmp    ecx,DWORD PTR [eax+0xc]
  505f96:	8b f8                	mov    edi,eax
  505f98:	0f 9c c1             	setl   cl
  505f9b:	88 4d fc             	mov    BYTE PTR [ebp-0x4],cl
  505f9e:	84 c9                	test   cl,cl
  505fa0:	74 04                	je     0x505fa6
  505fa2:	8b 00                	mov    eax,DWORD PTR [eax]
  505fa4:	eb 03                	jmp    0x505fa9
  505fa6:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  505fa9:	80 b8 b5 00 00 00 00 	cmp    BYTE PTR [eax+0xb5],0x0
  505fb0:	74 de                	je     0x505f90
  505fb2:	89 7d 0c             	mov    DWORD PTR [ebp+0xc],edi
  505fb5:	84 c9                	test   cl,cl
  505fb7:	74 34                	je     0x505fed
  505fb9:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  505fbc:	3b 38                	cmp    edi,DWORD PTR [eax]
  505fbe:	75 22                	jne    0x505fe2
  505fc0:	53                   	push   ebx
  505fc1:	6a 01                	push   0x1
  505fc3:	8d 4d 08             	lea    ecx,[ebp+0x8]
  505fc6:	8b c7                	mov    eax,edi
  505fc8:	51                   	push   ecx
  505fc9:	8b fa                	mov    edi,edx
  505fcb:	e8 30 01 00 00       	call   0x506100
  505fd0:	8b 10                	mov    edx,DWORD PTR [eax]
  505fd2:	5f                   	pop    edi
  505fd3:	89 16                	mov    DWORD PTR [esi],edx
  505fd5:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  505fd9:	8b c6                	mov    eax,esi
  505fdb:	5b                   	pop    ebx
  505fdc:	8b e5                	mov    esp,ebp
  505fde:	5d                   	pop    ebp
  505fdf:	c2 08 00             	ret    0x8
  505fe2:	8d 45 0c             	lea    eax,[ebp+0xc]
  505fe5:	e8 a6 02 00 00       	call   0x506290
  505fea:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  505fed:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  505ff0:	8b 48 0c             	mov    ecx,DWORD PTR [eax+0xc]
  505ff3:	3b 4b 0c             	cmp    ecx,DWORD PTR [ebx+0xc]
  505ff6:	7d 07                	jge    0x505fff
  505ff8:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  505ffb:	53                   	push   ebx
  505ffc:	50                   	push   eax
  505ffd:	eb c4                	jmp    0x505fc3
  505fff:	8d 43 10             	lea    eax,[ebx+0x10]
  506002:	50                   	push   eax
  506003:	e8 b8 e5 ff ff       	call   0x5045c0
  506008:	53                   	push   ebx
  506009:	e8 fe b1 38 00       	call   0x89120c
  50600e:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  506011:	83 c4 04             	add    esp,0x4
  506014:	5f                   	pop    edi
  506015:	89 0e                	mov    DWORD PTR [esi],ecx
  506017:	c6 46 04 00          	mov    BYTE PTR [esi+0x4],0x0
  50601b:	8b c6                	mov    eax,esi
  50601d:	5b                   	pop    ebx
  50601e:	8b e5                	mov    esp,ebp
  506020:	5d                   	pop    ebp
```

### Record lookup returns node+0x10 — VA `0x00500F90..0x00500FC4` raw `0x00100390`, 52 B, SHA256 `3bb8758a306096de8b08d5d71a42d00b11f193ecaa37d2d84d04581d9b040fb3`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500f90 <.data+0x100390>:
  500f90:	55                   	push   ebp
  500f91:	8b ec                	mov    ebp,esp
  500f93:	83 ec 08             	sub    esp,0x8
  500f96:	56                   	push   esi
  500f97:	8b b1 ac 5e 00 00    	mov    esi,DWORD PTR [ecx+0x5eac]
  500f9d:	8d 55 fc             	lea    edx,[ebp-0x4]
  500fa0:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500fa3:	52                   	push   edx
  500fa4:	8d 45 f8             	lea    eax,[ebp-0x8]
  500fa7:	8b ce                	mov    ecx,esi
  500fa9:	e8 72 2d 00 00       	call   0x503d20
  500fae:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  500fb1:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500fb4:	5e                   	pop    esi
  500fb5:	74 07                	je     0x500fbe
  500fb7:	83 c0 10             	add    eax,0x10
  500fba:	8b e5                	mov    esp,ebp
  500fbc:	5d                   	pop    ebp
  500fbd:	c3                   	ret
  500fbe:	33 c0                	xor    eax,eax
  500fc0:	8b e5                	mov    esp,ebp
  500fc2:	5d                   	pop    ebp
  500fc3:	c3                   	ret
```

### TalkBox mode0 UI different event — VA `0x005B6B77..0x005B6BD2` raw `0x001B5F77`, 91 B, SHA256 `976851887d1edd25f85243e5c555edd4b52585795b90fc5e0c5d07bc0628343a`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b6b77 <.data+0x1b5f77>:
  5b6b77:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6b79:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6b7c:	8b ce                	mov    ecx,esi
  5b6b7e:	ff d2                	call   edx
  5b6b80:	3d be 05 01 00       	cmp    eax,0x105be
  5b6b85:	75 04                	jne    0x5b6b8b
  5b6b87:	8b c6                	mov    eax,esi
  5b6b89:	eb 16                	jmp    0x5b6ba1
  5b6b8b:	6a 00                	push   0x0
  5b6b8d:	68 c0 1f bf 00       	push   0xbf1fc0
  5b6b92:	68 18 21 bf 00       	push   0xbf2118
  5b6b97:	6a 00                	push   0x0
  5b6b99:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6b9f:	33 c0                	xor    eax,eax
  5b6ba1:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  5b6ba4:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6baa:	6a 00                	push   0x0
  5b6bac:	6a 00                	push   0x0
  5b6bae:	51                   	push   ecx
  5b6baf:	8b 48 18             	mov    ecx,DWORD PTR [eax+0x18]
  5b6bb2:	e8 69 f9 07 00       	call   0x636520
  5b6bb7:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6bbd:	52                   	push   edx
  5b6bbe:	e8 4d 34 19 00       	call   0x74a010
  5b6bc3:	8b 87 24 02 00 00    	mov    eax,DWORD PTR [edi+0x224]
  5b6bc9:	50                   	push   eax
  5b6bca:	57                   	push   edi
  5b6bcb:	e8 30 02 fe ff       	call   0x596e00
  5b6bd0:	5f                   	pop    edi
  5b6bd1:	c3                   	ret
```

### QuestInfo UI lookup mode1 caller — VA `0x005B6C0C..0x005B6D15` raw `0x001B600C`, 265 B, SHA256 `03df410f66e0db5d90b67bd0a520043dc1aca7b1b765d820bbb2f31f2315bf8b`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b6c0c <.data+0x1b600c>:
  5b6c0c:	8b f1                	mov    esi,ecx
  5b6c0e:	8b fa                	mov    edi,edx
  5b6c10:	85 f6                	test   esi,esi
  5b6c12:	74 26                	je     0x5b6c3a
  5b6c14:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6c16:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6c19:	ff d2                	call   edx
  5b6c1b:	3d b9 05 01 00       	cmp    eax,0x105b9
  5b6c20:	75 04                	jne    0x5b6c26
  5b6c22:	8b de                	mov    ebx,esi
  5b6c24:	eb 16                	jmp    0x5b6c3c
  5b6c26:	6a 00                	push   0x0
  5b6c28:	68 c0 1f bf 00       	push   0xbf1fc0
  5b6c2d:	68 18 21 bf 00       	push   0xbf2118
  5b6c32:	6a 00                	push   0x0
  5b6c34:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6c3a:	33 db                	xor    ebx,ebx
  5b6c3c:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b6c43:	75 29                	jne    0x5b6c6e
  5b6c45:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b6c4c:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  5b6c53:	00 
  5b6c54:	e8 07 92 f4 ff       	call   0x4ffe60
  5b6c59:	68 00 cf bc 00       	push   0xbccf00
  5b6c5e:	e8 b7 b6 2d 00       	call   0x89231a
  5b6c63:	83 c4 04             	add    esp,0x4
  5b6c66:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6c6d:	ff 
  5b6c6e:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  5b6c71:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  5b6c77:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  5b6c7b:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5b6c7f:	51                   	push   ecx
  5b6c80:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b6c84:	8b ce                	mov    ecx,esi
  5b6c86:	e8 95 d0 f4 ff       	call   0x503d20
  5b6c8b:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5b6c8e:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5b6c92:	3b c6                	cmp    eax,esi
  5b6c94:	74 6c                	je     0x5b6d02
  5b6c96:	8d 70 10             	lea    esi,[eax+0x10]
  5b6c99:	85 f6                	test   esi,esi
  5b6c9b:	74 65                	je     0x5b6d02
  5b6c9d:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5b6ca4:	75 29                	jne    0x5b6ccf
  5b6ca6:	b8 01 00 00 00       	mov    eax,0x1
  5b6cab:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5b6cb1:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5b6cb5:	e8 d6 7f f2 ff       	call   0x4dec90
  5b6cba:	68 30 ce bc 00       	push   0xbcce30
  5b6cbf:	e8 56 b6 2d 00       	call   0x89231a
  5b6cc4:	83 c4 04             	add    esp,0x4
  5b6cc7:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6cce:	ff 
  5b6ccf:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6cd2:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6cd7:	8b 4e 28             	mov    ecx,DWORD PTR [esi+0x28]
  5b6cda:	52                   	push   edx
  5b6cdb:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6ce1:	6a 01                	push   0x1
  5b6ce3:	50                   	push   eax
  5b6ce4:	e8 37 f8 07 00       	call   0x636520
  5b6ce9:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6cef:	51                   	push   ecx
  5b6cf0:	e8 1b 33 19 00       	call   0x74a010
  5b6cf5:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6cfb:	52                   	push   edx
  5b6cfc:	57                   	push   edi
  5b6cfd:	e8 fe 00 fe ff       	call   0x596e00
  5b6d02:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5b6d06:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b6d0d:	59                   	pop    ecx
  5b6d0e:	5f                   	pop    edi
  5b6d0f:	5e                   	pop    esi
  5b6d10:	5b                   	pop    ebx
  5b6d11:	8b e5                	mov    esp,ebp
  5b6d13:	5d                   	pop    ebp
  5b6d14:	c3                   	ret
```

### QuestInfo UI lookup mode2 caller — VA `0x005B6D4C..0x005B6E55` raw `0x001B614C`, 265 B, SHA256 `58031c3de050c933444a61d8d5d3ac2cdcd6eb2f1641d5d532b3b4bb88127658`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b6d4c <.data+0x1b614c>:
  5b6d4c:	8b f1                	mov    esi,ecx
  5b6d4e:	8b fa                	mov    edi,edx
  5b6d50:	85 f6                	test   esi,esi
  5b6d52:	74 26                	je     0x5b6d7a
  5b6d54:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6d56:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6d59:	ff d2                	call   edx
  5b6d5b:	3d b9 05 01 00       	cmp    eax,0x105b9
  5b6d60:	75 04                	jne    0x5b6d66
  5b6d62:	8b de                	mov    ebx,esi
  5b6d64:	eb 16                	jmp    0x5b6d7c
  5b6d66:	6a 00                	push   0x0
  5b6d68:	68 c0 1f bf 00       	push   0xbf1fc0
  5b6d6d:	68 18 21 bf 00       	push   0xbf2118
  5b6d72:	6a 00                	push   0x0
  5b6d74:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6d7a:	33 db                	xor    ebx,ebx
  5b6d7c:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b6d83:	75 29                	jne    0x5b6dae
  5b6d85:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b6d8c:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  5b6d93:	00 
  5b6d94:	e8 c7 90 f4 ff       	call   0x4ffe60
  5b6d99:	68 00 cf bc 00       	push   0xbccf00
  5b6d9e:	e8 77 b5 2d 00       	call   0x89231a
  5b6da3:	83 c4 04             	add    esp,0x4
  5b6da6:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6dad:	ff 
  5b6dae:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  5b6db1:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  5b6db7:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  5b6dbb:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5b6dbf:	51                   	push   ecx
  5b6dc0:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b6dc4:	8b ce                	mov    ecx,esi
  5b6dc6:	e8 55 cf f4 ff       	call   0x503d20
  5b6dcb:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5b6dce:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5b6dd2:	3b c6                	cmp    eax,esi
  5b6dd4:	74 6c                	je     0x5b6e42
  5b6dd6:	8d 70 10             	lea    esi,[eax+0x10]
  5b6dd9:	85 f6                	test   esi,esi
  5b6ddb:	74 65                	je     0x5b6e42
  5b6ddd:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5b6de4:	75 29                	jne    0x5b6e0f
  5b6de6:	b8 01 00 00 00       	mov    eax,0x1
  5b6deb:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5b6df1:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5b6df5:	e8 96 7e f2 ff       	call   0x4dec90
  5b6dfa:	68 30 ce bc 00       	push   0xbcce30
  5b6dff:	e8 16 b5 2d 00       	call   0x89231a
  5b6e04:	83 c4 04             	add    esp,0x4
  5b6e07:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6e0e:	ff 
  5b6e0f:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6e12:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6e17:	8b 4e 28             	mov    ecx,DWORD PTR [esi+0x28]
  5b6e1a:	52                   	push   edx
  5b6e1b:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6e21:	6a 02                	push   0x2
  5b6e23:	50                   	push   eax
  5b6e24:	e8 f7 f6 07 00       	call   0x636520
  5b6e29:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6e2f:	51                   	push   ecx
  5b6e30:	e8 db 31 19 00       	call   0x74a010
  5b6e35:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6e3b:	52                   	push   edx
  5b6e3c:	57                   	push   edi
  5b6e3d:	e8 be ff fd ff       	call   0x596e00
  5b6e42:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5b6e46:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b6e4d:	59                   	pop    ecx
  5b6e4e:	5f                   	pop    edi
  5b6e4f:	5e                   	pop    esi
  5b6e50:	5b                   	pop    ebx
  5b6e51:	8b e5                	mov    esp,ebp
  5b6e53:	5d                   	pop    ebp
  5b6e54:	c3                   	ret
```

### QuestInfo UI lookup mode3 caller — VA `0x005B6E8C..0x005B6F95` raw `0x001B628C`, 265 B, SHA256 `a7162440ce8cf5c9c37a20f51522a3d125da6a54710fd40fdddce0ce62a1492e`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b6e8c <.data+0x1b628c>:
  5b6e8c:	8b f1                	mov    esi,ecx
  5b6e8e:	8b fa                	mov    edi,edx
  5b6e90:	85 f6                	test   esi,esi
  5b6e92:	74 26                	je     0x5b6eba
  5b6e94:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6e96:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6e99:	ff d2                	call   edx
  5b6e9b:	3d b9 05 01 00       	cmp    eax,0x105b9
  5b6ea0:	75 04                	jne    0x5b6ea6
  5b6ea2:	8b de                	mov    ebx,esi
  5b6ea4:	eb 16                	jmp    0x5b6ebc
  5b6ea6:	6a 00                	push   0x0
  5b6ea8:	68 c0 1f bf 00       	push   0xbf1fc0
  5b6ead:	68 18 21 bf 00       	push   0xbf2118
  5b6eb2:	6a 00                	push   0x0
  5b6eb4:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6eba:	33 db                	xor    ebx,ebx
  5b6ebc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b6ec3:	75 29                	jne    0x5b6eee
  5b6ec5:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b6ecc:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  5b6ed3:	00 
  5b6ed4:	e8 87 8f f4 ff       	call   0x4ffe60
  5b6ed9:	68 00 cf bc 00       	push   0xbccf00
  5b6ede:	e8 37 b4 2d 00       	call   0x89231a
  5b6ee3:	83 c4 04             	add    esp,0x4
  5b6ee6:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6eed:	ff 
  5b6eee:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  5b6ef1:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  5b6ef7:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  5b6efb:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5b6eff:	51                   	push   ecx
  5b6f00:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b6f04:	8b ce                	mov    ecx,esi
  5b6f06:	e8 15 ce f4 ff       	call   0x503d20
  5b6f0b:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5b6f0e:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5b6f12:	3b c6                	cmp    eax,esi
  5b6f14:	74 6c                	je     0x5b6f82
  5b6f16:	8d 70 10             	lea    esi,[eax+0x10]
  5b6f19:	85 f6                	test   esi,esi
  5b6f1b:	74 65                	je     0x5b6f82
  5b6f1d:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5b6f24:	75 29                	jne    0x5b6f4f
  5b6f26:	b8 01 00 00 00       	mov    eax,0x1
  5b6f2b:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5b6f31:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5b6f35:	e8 56 7d f2 ff       	call   0x4dec90
  5b6f3a:	68 30 ce bc 00       	push   0xbcce30
  5b6f3f:	e8 d6 b3 2d 00       	call   0x89231a
  5b6f44:	83 c4 04             	add    esp,0x4
  5b6f47:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6f4e:	ff 
  5b6f4f:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6f52:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6f57:	8b 4e 2c             	mov    ecx,DWORD PTR [esi+0x2c]
  5b6f5a:	52                   	push   edx
  5b6f5b:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6f61:	6a 03                	push   0x3
  5b6f63:	50                   	push   eax
  5b6f64:	e8 b7 f5 07 00       	call   0x636520
  5b6f69:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6f6f:	51                   	push   ecx
  5b6f70:	e8 9b 30 19 00       	call   0x74a010
  5b6f75:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6f7b:	52                   	push   edx
  5b6f7c:	57                   	push   edi
  5b6f7d:	e8 7e fe fd ff       	call   0x596e00
  5b6f82:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5b6f86:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b6f8d:	59                   	pop    ecx
  5b6f8e:	5f                   	pop    edi
  5b6f8f:	5e                   	pop    esi
  5b6f90:	5b                   	pop    ebx
  5b6f91:	8b e5                	mov    esp,ebp
  5b6f93:	5d                   	pop    ebp
  5b6f94:	c3                   	ret
```

### TalkBox selected quest record and text mode 0..3 — VA `0x00636520..0x0063670C` raw `0x00235920`, 492 B, SHA256 `316e233db3ae29095cb00c38289e884da7649199c459dd5258bbd429311a2541`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636520 <.data+0x235920>:
  636520:	55                   	push   ebp
  636521:	8b ec                	mov    ebp,esp
  636523:	83 e4 f8             	and    esp,0xfffffff8
  636526:	6a ff                	push   0xffffffff
  636528:	68 32 92 94 00       	push   0x949232
  63652d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  636533:	50                   	push   eax
  636534:	83 ec 28             	sub    esp,0x28
  636537:	53                   	push   ebx
  636538:	56                   	push   esi
  636539:	57                   	push   edi
  63653a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  63653f:	33 c4                	xor    eax,esp
  636541:	50                   	push   eax
  636542:	8d 44 24 38          	lea    eax,[esp+0x38]
  636546:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  63654c:	8b f1                	mov    esi,ecx
  63654e:	8b fa                	mov    edi,edx
  636550:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  636553:	8b 1d d0 1b fe 00    	mov    ebx,DWORD PTR ds:0xfe1bd0
  636559:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  63655d:	89 87 80 00 00 00    	mov    DWORD PTR [edi+0x80],eax
  636563:	51                   	push   ecx
  636564:	8d 4b 08             	lea    ecx,[ebx+0x8]
  636567:	8d 44 24 18          	lea    eax,[esp+0x18]
  63656b:	89 b7 84 00 00 00    	mov    DWORD PTR [edi+0x84],esi
  636571:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  636575:	e8 46 d3 20 00       	call   0x8438c0
  63657a:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  63657d:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  636581:	33 db                	xor    ebx,ebx
  636583:	3b c8                	cmp    ecx,eax
  636585:	74 05                	je     0x63658c
  636587:	8b 49 10             	mov    ecx,DWORD PTR [ecx+0x10]
  63658a:	eb 02                	jmp    0x63658e
  63658c:	33 c9                	xor    ecx,ecx
  63658e:	8b 87 bc 00 00 00    	mov    eax,DWORD PTR [edi+0xbc]
  636594:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  636597:	56                   	push   esi
  636598:	50                   	push   eax
  636599:	89 8f b8 00 00 00    	mov    DWORD PTR [edi+0xb8],ecx
  63659f:	89 97 90 00 00 00    	mov    DWORD PTR [edi+0x90],edx
  6365a5:	89 9f 88 00 00 00    	mov    DWORD PTR [edi+0x88],ebx
  6365ab:	e8 30 24 00 00       	call   0x6389e0
  6365b0:	6a 24                	push   0x24
  6365b2:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  6365b6:	e8 ad ac 25 00       	call   0x891268
  6365bb:	83 c4 04             	add    esp,0x4
  6365be:	3b c3                	cmp    eax,ebx
  6365c0:	0f 84 85 01 00 00    	je     0x63674b
  6365c6:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  6365ca:	89 00                	mov    DWORD PTR [eax],eax
  6365cc:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  6365d0:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  6365d3:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  6365d7:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  6365da:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  6365de:	c6 41 20 01          	mov    BYTE PTR [ecx+0x20],0x1
  6365e2:	8b 54 24 28          	mov    edx,DWORD PTR [esp+0x28]
  6365e6:	c6 42 21 01          	mov    BYTE PTR [edx+0x21],0x1
  6365ea:	53                   	push   ebx
  6365eb:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  6365ef:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  6365f5:	8b 97 80 00 00 00    	mov    edx,DWORD PTR [edi+0x80]
  6365fb:	8d 44 24 28          	lea    eax,[esp+0x28]
  6365ff:	50                   	push   eax
  636600:	a1 b4 1d fe 00       	mov    eax,ds:0xfe1db4
  636605:	51                   	push   ecx
  636606:	52                   	push   edx
  636607:	50                   	push   eax
  636608:	e8 43 5c ec ff       	call   0x4fc250
  63660d:	39 5c 24 2c          	cmp    DWORD PTR [esp+0x2c],ebx
  636611:	8b 87 90 00 00 00    	mov    eax,DWORD PTR [edi+0x90]
  636617:	0f 95 c1             	setne  cl
  63661a:	88 8f 8c 00 00 00    	mov    BYTE PTR [edi+0x8c],cl
  636620:	83 f8 03             	cmp    eax,0x3
  636623:	0f 87 e3 00 00 00    	ja     0x63670c
  636629:	ff 24 85 74 67 63 00 	jmp    DWORD PTR [eax*4+0x636774]
  636630:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636636:	8b 11                	mov    edx,DWORD PTR [ecx]
  636638:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63663b:	ff d0                	call   eax
  63663d:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636643:	8b 11                	mov    edx,DWORD PTR [ecx]
  636645:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  636648:	ff d0                	call   eax
  63664a:	e8 51 f6 ff ff       	call   0x635ca0
  63664f:	e9 b8 00 00 00       	jmp    0x63670c
  636654:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63665a:	8b 11                	mov    edx,DWORD PTR [ecx]
  63665c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63665f:	ff d0                	call   eax
  636661:	e8 ca 92 dd ff       	call   0x40f930
  636666:	8b c8                	mov    ecx,eax
  636668:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63666b:	e8 20 a9 ec ff       	call   0x500f90
  636670:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  636676:	3b c3                	cmp    eax,ebx
  636678:	74 73                	je     0x6366ed
  63667a:	8b 48 30             	mov    ecx,DWORD PTR [eax+0x30]
  63667d:	51                   	push   ecx
  63667e:	8b c7                	mov    eax,edi
  636680:	e8 8b f8 ff ff       	call   0x635f10
  636685:	eb 72                	jmp    0x6366f9
  636687:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63668d:	8b 11                	mov    edx,DWORD PTR [ecx]
  63668f:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  636692:	ff d0                	call   eax
  636694:	e8 97 92 dd ff       	call   0x40f930
  636699:	8b c8                	mov    ecx,eax
  63669b:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63669e:	e8 ed a8 ec ff       	call   0x500f90
  6366a3:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366a9:	3b c3                	cmp    eax,ebx
  6366ab:	74 40                	je     0x6366ed
  6366ad:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
  6366b0:	51                   	push   ecx
  6366b1:	8b c7                	mov    eax,edi
  6366b3:	e8 58 f8 ff ff       	call   0x635f10
  6366b8:	eb 3f                	jmp    0x6366f9
  6366ba:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  6366c0:	8b 11                	mov    edx,DWORD PTR [ecx]
  6366c2:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  6366c5:	ff d0                	call   eax
  6366c7:	e8 64 92 dd ff       	call   0x40f930
  6366cc:	8b c8                	mov    ecx,eax
  6366ce:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  6366d1:	e8 ba a8 ec ff       	call   0x500f90
  6366d6:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366dc:	3b c3                	cmp    eax,ebx
  6366de:	74 0d                	je     0x6366ed
  6366e0:	8b 48 38             	mov    ecx,DWORD PTR [eax+0x38]
  6366e3:	51                   	push   ecx
  6366e4:	8b c7                	mov    eax,edi
  6366e6:	e8 25 f8 ff ff       	call   0x635f10
  6366eb:	eb 0c                	jmp    0x6366f9
  6366ed:	8b 17                	mov    edx,DWORD PTR [edi]
  6366ef:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  6366f5:	8b cf                	mov    ecx,edi
  6366f7:	ff d0                	call   eax
  6366f9:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  6366ff:	8b 11                	mov    edx,DWORD PTR [ecx]
  636701:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  636704:	ff d0                	call   eax
  636706:	57                   	push   edi
  636707:	e8 44 f9 ff ff       	call   0x636050
```

### TalkBox action 0x6A7 and actual C2S bytes — VA `0x00636DE0..0x00636ED0` raw `0x002361E0`, 240 B, SHA256 `a385b5b3240f2f9586c8895779d8a6b3db4ca4932109ea896376319dc518b067`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636de0 <.data+0x2361e0>:
  636de0:	55                   	push   ebp
  636de1:	8b ec                	mov    ebp,esp
  636de3:	56                   	push   esi
  636de4:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  636de7:	57                   	push   edi
  636de8:	8b f9                	mov    edi,ecx
  636dea:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636df0:	8b 01                	mov    eax,DWORD PTR [ecx]
  636df2:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  636df5:	56                   	push   esi
  636df6:	ff d2                	call   edx
  636df8:	81 7e 10 02 44 0f 00 	cmp    DWORD PTR [esi+0x10],0xf4402
  636dff:	75 05                	jne    0x636e06
  636e01:	e8 0a 00 00 00       	call   0x636e10
  636e06:	5f                   	pop    edi
  636e07:	5e                   	pop    esi
  636e08:	5d                   	pop    ebp
  636e09:	c2 04 00             	ret    0x4
  636e0c:	cc                   	int3
  636e0d:	cc                   	int3
  636e0e:	cc                   	int3
  636e0f:	cc                   	int3
  636e10:	55                   	push   ebp
  636e11:	8b ec                	mov    ebp,esp
  636e13:	51                   	push   ecx
  636e14:	85 f6                	test   esi,esi
  636e16:	74 28                	je     0x636e40
  636e18:	8b 06                	mov    eax,DWORD PTR [esi]
  636e1a:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  636e1d:	8b ce                	mov    ecx,esi
  636e1f:	ff d2                	call   edx
  636e21:	3d bd 05 01 00       	cmp    eax,0x105bd
  636e26:	75 04                	jne    0x636e2c
  636e28:	8b c6                	mov    eax,esi
  636e2a:	eb 16                	jmp    0x636e42
  636e2c:	6a 00                	push   0x0
  636e2e:	68 c0 1f bf 00       	push   0xbf1fc0
  636e33:	68 18 21 bf 00       	push   0xbf2118
  636e38:	6a 00                	push   0x0
  636e3a:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  636e40:	33 c0                	xor    eax,eax
  636e42:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  636e45:	3d a7 06 00 00       	cmp    eax,0x6a7
  636e4a:	75 6d                	jne    0x636eb9
  636e4c:	83 bf 88 00 00 00 00 	cmp    DWORD PTR [edi+0x88],0x0
  636e53:	74 77                	je     0x636ecc
  636e55:	b8 01 00 00 00       	mov    eax,0x1
  636e5a:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  636e60:	75 13                	jne    0x636e75
  636e62:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  636e68:	68 10 cf bc 00       	push   0xbccf10
  636e6d:	e8 a8 b4 25 00       	call   0x89231a
  636e72:	83 c4 04             	add    esp,0x4
  636e75:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  636e7c:	8b 8f 88 00 00 00    	mov    ecx,DWORD PTR [edi+0x88]
  636e82:	66 8b 11             	mov    dx,WORD PTR [ecx]
  636e85:	b8 36 00 00 00       	mov    eax,0x36
  636e8a:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  636e8e:	66 89 55 fe          	mov    WORD PTR [ebp-0x2],dx
  636e92:	75 2c                	jne    0x636ec0
  636e94:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  636e9a:	8b 01                	mov    eax,DWORD PTR [ecx]
  636e9c:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  636e9f:	6a 04                	push   0x4
  636ea1:	8d 55 fc             	lea    edx,[ebp-0x4]
  636ea4:	52                   	push   edx
  636ea5:	6a 00                	push   0x0
  636ea7:	ff d0                	call   eax
  636ea9:	8b 17                	mov    edx,DWORD PTR [edi]
  636eab:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  636eb1:	8b cf                	mov    ecx,edi
  636eb3:	ff d0                	call   eax
  636eb5:	8b e5                	mov    esp,ebp
  636eb7:	5d                   	pop    ebp
  636eb8:	c3                   	ret
  636eb9:	3d a8 06 00 00       	cmp    eax,0x6a8
  636ebe:	75 0c                	jne    0x636ecc
  636ec0:	8b 17                	mov    edx,DWORD PTR [edi]
  636ec2:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  636ec8:	8b cf                	mov    ecx,edi
  636eca:	ff d0                	call   eax
  636ecc:	8b e5                	mov    esp,ebp
  636ece:	5d                   	pop    ebp
  636ecf:	c3                   	ret
```

### Conditional UI secondary 0x10049 producer — VA `0x00596F5E..0x00596FD3` raw `0x0019635E`, 117 B, SHA256 `e132db549a39b7c27de5bf9c9d733724b80dc7960d2a771c5374cbe115ce7758`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00596f5e <.data+0x19635e>:
  596f5e:	83 3e 01             	cmp    DWORD PTR [esi],0x1
  596f61:	75 19                	jne    0x596f7c
  596f63:	83 bb f4 00 00 00 00 	cmp    DWORD PTR [ebx+0xf4],0x0
  596f6a:	74 10                	je     0x596f7c
  596f6c:	8b 8b f4 00 00 00    	mov    ecx,DWORD PTR [ebx+0xf4]
  596f72:	8b 01                	mov    eax,DWORD PTR [ecx]
  596f74:	8b 90 d4 00 00 00    	mov    edx,DWORD PTR [eax+0xd4]
  596f7a:	ff d2                	call   edx
  596f7c:	80 7e 05 00          	cmp    BYTE PTR [esi+0x5],0x0
  596f80:	74 42                	je     0x596fc4
  596f82:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  596f89:	75 14                	jne    0x596f9f
  596f8b:	83 0d 14 13 fb 00 01 	or     DWORD PTR ds:0xfb1314,0x1
  596f92:	68 10 cf bc 00       	push   0xbccf10
  596f97:	e8 7e b3 2f 00       	call   0x89231a
  596f9c:	83 c4 04             	add    esp,0x4
  596f9f:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  596fa6:	c7 45 08 49 00 01 00 	mov    DWORD PTR [ebp+0x8],0x10049
  596fad:	75 15                	jne    0x596fc4
  596faf:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  596fb5:	8b 11                	mov    edx,DWORD PTR [ecx]
  596fb7:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  596fba:	6a 04                	push   0x4
  596fbc:	8d 45 08             	lea    eax,[ebp+0x8]
  596fbf:	50                   	push   eax
  596fc0:	6a 00                	push   0x0
  596fc2:	ff d2                	call   edx
  596fc4:	80 7e 04 00          	cmp    BYTE PTR [esi+0x4],0x0
  596fc8:	74 09                	je     0x596fd3
  596fca:	66 c7 83 b0 00 00 00 	mov    WORD PTR [ebx+0xb0],0x101
  596fd1:	01 01
```

### Tutorial scene startup 0x0C size6 — VA `0x004A8B18..0x004A8B79` raw `0x000A7F18`, 97 B, SHA256 `a153390c0cc7394783851e151e08f6befb1d7c7e75fdbca8c719f468997c0806`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004a8b18 <.data+0xa7f18>:
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
  4a8b5d:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4a8b5f:	68 7c 68 c0 00       	push   0xc0687c
  4a8b64:	e8 e7 be 24 00       	call   0x6f4a50
  4a8b69:	8b 06                	mov    eax,DWORD PTR [esi]
  4a8b6b:	6a 00                	push   0x0
  4a8b6d:	6a 00                	push   0x0
  4a8b6f:	68 a8 68 c0 00       	push   0xc068a8
  4a8b74:	e8 57 c2 24 00       	call   0x6f4dd0
```

### Scenario 0x40 size4 — VA `0x004AA4D0..0x004AA511` raw `0x000A98D0`, 65 B, SHA256 `103afc3ca48e755eece89b0c68593bafc60eba97f3e10bb8743c8e14942ed831`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004aa4d0 <.data+0xa98d0>:
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
  4aa509:	cc                   	int3
  4aa50a:	cc                   	int3
  4aa50b:	cc                   	int3
  4aa50c:	cc                   	int3
  4aa50d:	cc                   	int3
  4aa50e:	cc                   	int3
  4aa50f:	cc                   	int3
  4aa510:	55                   	push   ebp
```

### Tutorial inbound end flag 0x4C separate receiver — VA `0x004C4F20..0x004C4FA2` raw `0x000C4320`, 130 B, SHA256 `931f7d521dee63a85e3ee39ba19b1ca63feebd738cb4c05f916e3a9eba220c20`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004c4f20 <.data+0xc4320>:
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
  4c4f9f:	c2 0c 00             	ret    0xc
```

### Network actual constructor/vtable root — VA `0x008046ED..0x0080471F` raw `0x00403AED`, 50 B, SHA256 `ae39a5cafeac07f98e49d3885b1fd186e335a482350ca365a00ec63e531becec`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

008046ed <.data+0x403aed>:
  8046ed:	85 f6                	test   esi,esi
  8046ef:	74 10                	je     0x804701
  8046f1:	56                   	push   esi
  8046f2:	e8 69 f6 ff ff       	call   0x803d60
  8046f7:	c7 06 48 17 c5 00    	mov    DWORD PTR [esi],0xc51748
  8046fd:	8b ce                	mov    ecx,esi
  8046ff:	eb 02                	jmp    0x804703
  804701:	33 c9                	xor    ecx,ecx
  804703:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80470a:	8b 11                	mov    edx,DWORD PTR [ecx]
  80470c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  80470f:	89 0d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ecx
  804715:	ff d0                	call   eax
  804717:	8b 35 a0 25 bd 00    	mov    esi,DWORD PTR ds:0xbd25a0
  80471d:	ff d6                	call   esi
```

### Network slot+0x10 keyed enqueue — VA `0x008069A0..0x008069F5` raw `0x00405DA0`, 85 B, SHA256 `bfd9e3c39b554b63d20adbb6613865e58a4a3536a25841d3cb285125fe46edc3`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

008069a0 <.data+0x405da0>:
  8069a0:	55                   	push   ebp
  8069a1:	8b ec                	mov    ebp,esp
  8069a3:	51                   	push   ecx
  8069a4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8069a7:	56                   	push   esi
  8069a8:	8b f1                	mov    esi,ecx
  8069aa:	8d 4d 08             	lea    ecx,[ebp+0x8]
  8069ad:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  8069b0:	51                   	push   ecx
  8069b1:	8d 4e 18             	lea    ecx,[esi+0x18]
  8069b4:	8d 45 fc             	lea    eax,[ebp-0x4]
  8069b7:	e8 04 cf 03 00       	call   0x8438c0
  8069bc:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  8069bf:	3b 46 1c             	cmp    eax,DWORD PTR [esi+0x1c]
  8069c2:	5e                   	pop    esi
  8069c3:	74 07                	je     0x8069cc
  8069c5:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  8069c8:	85 c9                	test   ecx,ecx
  8069ca:	75 08                	jne    0x8069d4
  8069cc:	33 c0                	xor    eax,eax
  8069ce:	8b e5                	mov    esp,ebp
  8069d0:	5d                   	pop    ebp
  8069d1:	c2 0c 00             	ret    0xc
  8069d4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  8069d7:	85 c0                	test   eax,eax
  8069d9:	75 0b                	jne    0x8069e6
  8069db:	b8 01 00 00 00       	mov    eax,0x1
  8069e0:	8b e5                	mov    esp,ebp
  8069e2:	5d                   	pop    ebp
  8069e3:	c2 0c 00             	ret    0xc
  8069e6:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  8069e9:	50                   	push   eax
  8069ea:	52                   	push   edx
  8069eb:	e8 e0 f6 ff ff       	call   0x8060d0
  8069f0:	8b e5                	mov    esp,ebp
  8069f2:	5d                   	pop    ebp
  8069f3:	c2 0c              	ret    0xc
```

### Connection packet length/storage gate — VA `0x008060D0..0x0080618A` raw `0x004054D0`, 186 B, SHA256 `7856f4c3175c40634f6d3d81d3c8a0086d8c3512b28794e7ed8f1c5f98f0bcec`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

008060d0 <.data+0x4054d0>:
  8060d0:	55                   	push   ebp
  8060d1:	8b ec                	mov    ebp,esp
  8060d3:	6a ff                	push   0xffffffff
  8060d5:	68 5e 99 90 00       	push   0x90995e
  8060da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8060e0:	50                   	push   eax
  8060e1:	53                   	push   ebx
  8060e2:	56                   	push   esi
  8060e3:	57                   	push   edi
  8060e4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8060e9:	33 c5                	xor    eax,ebp
  8060eb:	50                   	push   eax
  8060ec:	8d 45 f4             	lea    eax,[ebp-0xc]
  8060ef:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8060f5:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  8060f8:	8b f1                	mov    esi,ecx
  8060fa:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  806101:	01 00 00 
  806104:	7e 16                	jle    0x80611c
  806106:	33 c0                	xor    eax,eax
  806108:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  80610b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806112:	59                   	pop    ecx
  806113:	5f                   	pop    edi
  806114:	5e                   	pop    esi
  806115:	5b                   	pop    ebx
  806116:	8b e5                	mov    esp,ebp
  806118:	5d                   	pop    ebp
  806119:	c2 08 00             	ret    0x8
  80611c:	b8 01 00 00 00       	mov    eax,0x1
  806121:	84 05 54 33 fe 00    	test   BYTE PTR ds:0xfe3354,al
  806127:	75 26                	jne    0x80614f
  806129:	09 05 54 33 fe 00    	or     DWORD PTR ds:0xfe3354,eax
  80612f:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806136:	e8 e5 0f 00 00       	call   0x807120
  80613b:	68 90 0b bd 00       	push   0xbd0b90
  806140:	e8 d5 c1 08 00       	call   0x89231a
  806145:	83 c4 04             	add    esp,0x4
  806148:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80614f:	bf 58 33 fe 00       	mov    edi,0xfe3358
  806154:	e8 17 13 00 00       	call   0x807470
  806159:	8b f8                	mov    edi,eax
  80615b:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  806161:	77 14                	ja     0x806177
  806163:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806166:	53                   	push   ebx
  806167:	50                   	push   eax
  806168:	8d 4f 08             	lea    ecx,[edi+0x8]
  80616b:	51                   	push   ecx
  80616c:	e8 5f 7a 09 00       	call   0x89dbd0
  806171:	83 c4 0c             	add    esp,0xc
  806174:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  806177:	57                   	push   edi
  806178:	e8 e3 fe ff ff       	call   0x806060
  80617d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  806180:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806187:	59                   	pop    ecx
  806188:	5f                   	pop    edi
  806189:	5e                   	pop    esi
```

### Connection queue path — VA `0x00806060..0x008060CE` raw `0x00405460`, 110 B, SHA256 `378338fd62742a163bc08eeab6a1785f2c4ff089aa4706abf3de76b6a6738187`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00806060 <.data+0x405460>:
  806060:	55                   	push   ebp
  806061:	8b ec                	mov    ebp,esp
  806063:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  806069:	57                   	push   edi
  80606a:	50                   	push   eax
  80606b:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806071:	8b be 74 a0 00 00    	mov    edi,DWORD PTR [esi+0xa074]
  806077:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  80607a:	8d 4d 08             	lea    ecx,[ebp+0x8]
  80607d:	51                   	push   ecx
  80607e:	52                   	push   edx
  80607f:	57                   	push   edi
  806080:	e8 7b 76 f4 ff       	call   0x74d700
  806085:	8b 8e 78 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa078]
  80608b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  806090:	2b d1                	sub    edx,ecx
  806092:	83 fa 01             	cmp    edx,0x1
  806095:	73 0a                	jae    0x8060a1
  806097:	68 34 20 bf 00       	push   0xbf2034
  80609c:	e8 8f 7a 07 00       	call   0x87db30
  8060a1:	41                   	inc    ecx
  8060a2:	89 8e 78 a0 00 00    	mov    DWORD PTR [esi+0xa078],ecx
  8060a8:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  8060ab:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  8060ae:	89 01                	mov    DWORD PTR [ecx],eax
  8060b0:	8b 96 d4 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0d4]
  8060b6:	52                   	push   edx
  8060b7:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8060bd:	c6 86 24 a0 00 00 01 	mov    BYTE PTR [esi+0xa024],0x1
  8060c4:	b8 01 00 00 00       	mov    eax,0x1
  8060c9:	5f                   	pop    edi
  8060ca:	5d                   	pop    ebp
  8060cb:	c2 04 00             	ret    0x4
```

### Plaintext frame header/payload selection — VA `0x00807A70..0x00807B1A` raw `0x00406E70`, 170 B, SHA256 `96b3ea585813476abfa373c33eec80b62a9a9fe55927f81533f4f49603dd4af1`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00807a70 <.data+0x406e70>:
  807a70:	55                   	push   ebp
  807a71:	8b ec                	mov    ebp,esp
  807a73:	83 ec 08             	sub    esp,0x8
  807a76:	53                   	push   ebx
  807a77:	56                   	push   esi
  807a78:	8b 37                	mov    esi,DWORD PTR [edi]
  807a7a:	56                   	push   esi
  807a7b:	89 75 f8             	mov    DWORD PTR [ebp-0x8],esi
  807a7e:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  807a84:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  807a87:	8d 5a 04             	lea    ebx,[edx+0x4]
  807a8a:	b8 68 1a 00 00       	mov    eax,0x1a68
  807a8f:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  807a93:	66 89 55 fc          	mov    WORD PTR [ebp-0x4],dx
  807a97:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  807a9d:	0f 87 8a 00 00 00    	ja     0x807b2d
  807aa3:	85 d2                	test   edx,edx
  807aa5:	0f 84 82 00 00 00    	je     0x807b2d
  807aab:	8b 8f 0c 50 00 00    	mov    ecx,DWORD PTR [edi+0x500c]
  807ab1:	03 cb                	add    ecx,ebx
  807ab3:	81 f9 00 40 00 00    	cmp    ecx,0x4000
  807ab9:	77 72                	ja     0x807b2d
  807abb:	8b 87 04 50 00 00    	mov    eax,DWORD PTR [edi+0x5004]
  807ac1:	8d b7 04 50 00 00    	lea    esi,[edi+0x5004]
  807ac7:	8d 0c 18             	lea    ecx,[eax+ebx*1]
  807aca:	89 4d 0c             	mov    DWORD PTR [ebp+0xc],ecx
  807acd:	8d 4f 04             	lea    ecx,[edi+0x4]
  807ad0:	3b c1                	cmp    eax,ecx
  807ad2:	72 45                	jb     0x807b19
  807ad4:	3b c6                	cmp    eax,esi
  807ad6:	73 41                	jae    0x807b19
  807ad8:	39 4d 0c             	cmp    DWORD PTR [ebp+0xc],ecx
  807adb:	72 3c                	jb     0x807b19
  807add:	39 75 0c             	cmp    DWORD PTR [ebp+0xc],esi
  807ae0:	73 37                	jae    0x807b19
  807ae2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807ae5:	52                   	push   edx
  807ae6:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  807ae9:	89 08                	mov    DWORD PTR [eax],ecx
  807aeb:	8b 06                	mov    eax,DWORD PTR [esi]
  807aed:	52                   	push   edx
  807aee:	83 c0 04             	add    eax,0x4
  807af1:	50                   	push   eax
  807af2:	e8 d9 60 09 00       	call   0x89dbd0
  807af7:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  807afa:	01 9f 0c 50 00 00    	add    DWORD PTR [edi+0x500c],ebx
  807b00:	01 1e                	add    DWORD PTR [esi],ebx
  807b02:	83 c4 0c             	add    esp,0xc
  807b05:	51                   	push   ecx
  807b06:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b0c:	5e                   	pop    esi
  807b0d:	b8 01 00 00 00       	mov    eax,0x1
  807b12:	5b                   	pop    ebx
  807b13:	8b e5                	mov    esp,ebp
  807b15:	5d                   	pop    ebp
  807b16:	c2 08 00             	ret    0x8
  807b19:	8b               	mov    edx,DWORD PTR [ebp-0x8]
```

### WSASend vtable dispatch — VA `0x008068B0..0x00806995` raw `0x00405CB0`, 229 B, SHA256 `d79bd22e4c7d4d23a8481900decc353faae0d807bc30d0f0f921811db56b2e56`
```asm

/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

008068b0 <.data+0x405cb0>:
  8068b0:	55                   	push   ebp
  8068b1:	8b ec                	mov    ebp,esp
  8068b3:	53                   	push   ebx
  8068b4:	56                   	push   esi
  8068b5:	57                   	push   edi
  8068b6:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8068b9:	8b d9                	mov    ebx,ecx
  8068bb:	85 ff                	test   edi,edi
  8068bd:	0f 84 d0 00 00 00    	je     0x806993
  8068c3:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  8068c6:	85 d2                	test   edx,edx
  8068c8:	0f 84 c5 00 00 00    	je     0x806993
  8068ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8068d1:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  8068d8:	0f 85 b5 00 00 00    	jne    0x806993
  8068de:	8d 86 50 a0 00 00    	lea    eax,[esi+0xa050]
  8068e4:	33 c9                	xor    ecx,ecx
  8068e6:	89 08                	mov    DWORD PTR [eax],ecx
  8068e8:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  8068eb:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  8068ee:	6a 00                	push   0x0
  8068f0:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  8068f3:	50                   	push   eax
  8068f4:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  8068f7:	8d 48 14             	lea    ecx,[eax+0x14]
  8068fa:	6a 00                	push   0x0
  8068fc:	89 78 18             	mov    DWORD PTR [eax+0x18],edi
  8068ff:	8d 45 0c             	lea    eax,[ebp+0xc]
  806902:	50                   	push   eax
  806903:	6a 01                	push   0x1
  806905:	89 11                	mov    DWORD PTR [ecx],edx
  806907:	8b 16                	mov    edx,DWORD PTR [esi]
  806909:	51                   	push   ecx
  80690a:	52                   	push   edx
  80690b:	c7 45 0c 00 00 00 00 	mov    DWORD PTR [ebp+0xc],0x0
  806912:	ff 15 b8 25 bd 00    	call   DWORD PTR ds:0xbd25b8
  806918:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  80691b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  80691e:	89 11                	mov    DWORD PTR [ecx],edx
  806920:	83 f8 ff             	cmp    eax,0xffffffff
  806923:	75 55                	jne    0x80697a
  806925:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  80692b:	8b f8                	mov    edi,eax
  80692d:	81 ff e5 03 00 00    	cmp    edi,0x3e5
  806933:	74 2c                	je     0x806961
  806935:	83 7b 58 00          	cmp    DWORD PTR [ebx+0x58],0x0
  806939:	74 1d                	je     0x806958
  80693b:	8b 36                	mov    esi,DWORD PTR [esi]
  80693d:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806943:	50                   	push   eax
  806944:	57                   	push   edi
  806945:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806948:	56                   	push   esi
  806949:	68 00 16 c5 00       	push   0xc51600
  80694e:	6a 02                	push   0x2
  806950:	e8 ab 9a ee ff       	call   0x6f0400
  806955:	83 c4 14             	add    esp,0x14
  806958:	5f                   	pop    edi
  806959:	5e                   	pop    esi
  80695a:	33 c0                	xor    eax,eax
  80695c:	5b                   	pop    ebx
  80695d:	5d                   	pop    ebp
  80695e:	c2 10 00             	ret    0x10
  806961:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806967:	56                   	push   esi
  806968:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  80696e:	5f                   	pop    edi
  80696f:	5e                   	pop    esi
  806970:	b8 02 00 00 00       	mov    eax,0x2
  806975:	5b                   	pop    ebx
  806976:	5d                   	pop    ebp
  806977:	c2 10 00             	ret    0x10
  80697a:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806980:	56                   	push   esi
  806981:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  806987:	5f                   	pop    edi
  806988:	5e                   	pop    esi
  806989:	b8 01 00 00 00       	mov    eax,0x1
  80698e:	5b                   	pop    ebx
  80698f:	5d                   	pop    ebp
  806990:	c2 10 00             	ret    0x10
  806993:	5f                   	pop    edi
  806994:	5e                   	pop    esi
```

## 9. 可復驗的定點檢查（皆為唯讀）
```sh
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe /mnt/data/Event.stp
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x636520 --stop-address=0x63670c /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x5048be --stop-address=0x504944 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x40f930 --stop-address=0x40f992 /mnt/data/Tartaros.bin
```

### 資源與前段參照（不是本段新原始來源）
- `kr/evidence/5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60.txt` 是完整 KR QuestInfo XML；Q14 `id14,type3,field18,giver/finisher10027`，Q16 `<Demand id="14"/>`，T16-112已逐字核對。
- T16-106/107 原生 TalkBox event、network class、queue/framing；T16-111 Scenario14 Lua→0x40、S2C0x4C map；T16-112 XML loader；T16-113 Part1/Part2/Isilia local. 本報告的**全新證據**是 `QuestInfo.id -> [FAB2A0+5EAC]` pointer identity+map payload->C2S second WORD，以及 3 modes 都能共用此 QuestID 送出。
- T16-110-REV 的 S2C 0x41/0x42/0x7F runtime record owner `[FAB134]` 跟這份**靜態 QuestInfo map** `[FB114C]` 是**不同**狀態來源；不能藉同一個 QID 串成完成 UI，仍需④獨立驗證。

**維護限制：** 本報告是作者端、有界 KR BIN-first 研究，不等於 T01 FULL-PASS、S00 SPEC STABLE 或完成可玩。未得到使用者 Commit/Push 授權，所以本次只提供可下載完整原稿，沒有研究 commit。
