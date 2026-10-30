# T16-122 — Quest16／③：NPC10027 操作後的三類 C→S application payload、TalkBox mode2 反證、sender vtable 與傳送佇列（KR BIN-first）

- 本稿生成：`2026-10-30T10:06:18+08:00`（Asia/Taipei）；標記：`chatgpt-web roy`；正式段號：**T16-122**，接 T16-121 的 Quest16-② bounded completion。
- 使用者目標：**完成 Quest16-③ 後上 GitHub**。本稿研究終點為 Quest16 相關的 Client 玩家行為→C→S application payload 各原生 producer、所有能由 Client 證實的送出門檻／先後條件、sender instance/vtable→接點/佇列→連線內 framing consumer。原版 Server 的回覆政策／究竟哪個封包「代表接受 Quest16」需有入站或 runtime pairing 才能成立，不在無證據下補齊。
- 原始證據：`/mnt/data/Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀離線 disassemble；未執行遊戲、未取得封包 capture。PE `.text` VA = `raw + 0x400C00`，`.rdata` 裡 vtable VA `0xC51748` raw `0x84FD48`，已以原件 LE DWORD 讀回。
- 證據分級：**[BIN]** 此段重新從原始 BIN bytes/組語核實；**[HIST]** 前段 T16-118/119/120/121 原稿；**[INF]** 需要特定 branch/資料條件的靜態推論；**[UNKNOWN]** 未能從本 Client 原始碼證實。**[NATIVE VERIFIED HERE] 只表示本段指定位元組已查，不等於 T01 FULL-PASS**。
- Git 開工基準：本次開始 main `2eba5d68701538504f405768b971bb3beedd5202`、branch `t16/roy/chatgpt-web` ahead9/behind12。`research/dispatch/inbox/T16.md` 沒有分派 RR；T01 Task README 未見當前需修項目。已按同一 ChatGPT 對話只做一次 main→T16 merge 的原約定（先前 PR#26），**本次不再自動 merge 最新 main**。本段只提交 T16 研究原稿至 T16 分支。
- 交叉來源：T16-118 Quest16 資源 `id=16,type=2,town=0,giver=10027,Demand=14`；T16-121 `0x40/state0/QID16→F438B→0x5B6D20→0x636520(mode2)`。這是上下文證據，**不等於本稿直接重新解包 Table.stp 或證實 Server request↔response 配對**。

## 0. 研究範圍與可驗收命題

1. NPC10027 操作送出哪些 C→S payload，producer 是否真的使用 QuestID16？
2. `0x561760(16,1)` 是立即發送還是保存狀態後再送，哪些分支會變成 `0x3F`？
3. `0x36` 的 producer、sender gate、任務 ID 來源是誰？對 Quest16 mode2 是否有**實際原生可達**產生點？
4. 所有 producer 呼叫的 `[0xFBA854]→vtable+0x10` 具體是誰？payload 在離開這個方法後如何排隊與 framing？
5. 先前 T16-114/117/121 容易誤解的 `0x36(QID16)`、`0x3F` 同步性與「NPC click→0x40」要如何更正；Server 需實作的 interface 與 Client 仍需 reverse 的部分各為何？

### 0.1 本段最終可證的 Quest16-③ 靜態鏈（**有條件、非 playable**）

```text
QuestInfo XML Demand14 / giver10027 / type2 [T16-118/121]
    → Client QuestOwner 過濾（QID16 可為唯一對應候選）[T16-121]
NPC click outer event type 0x105BD/action 0x6A7
    └ child type 0x105BF/+0x14 actor NPC10027 [BIN]
          ├ 0x5B9340 → 0x5008B0 → QID16
          │      └ 0x561760(16,1) → controller+0x38=16, +0x3c=1, +0x28=1
          │          └ [later periodic/controller branch gates] 0x561DB0
          │              └ 0x4A39A0 → app payload 3F 00 10 00 01 00 01 00 [conditional]
          └ 0x5B9340 → 0x1C actor two WORDs → app payload 1C 00 aa aa bb bb

OTHER 0x36 PRODUCERS (must NOT conflate):
    TalkBox mode1 only: 0x636B70 → UI F4402 → 0x636DE0/636E10
       → 36 00 word_at(TalkBox+0x88) [outer 0x105BD action 0x6A7, gate]
    Separate registered inbound/event handler: 0x4B3510
       → 36 00 word_at(inbound_msg+2) [gate]; registration slot +0x26C (~0x4D)

ALL known app producers at this site:
    gate [0xFBA798] == 0 → global sender [0xFBA854] → vtable+0x10
    → actual target 0x8069A0 → key/map lookup → Conn::0x8060D0
    → copied app bytes in connection queue → 0x8061A0 drain
    → 0x807A70 OR 0x807830 framing depends on Conn+0xA02C
    → WSASend transport function 0x8068B0 exists at sender vtable+0xC
```

Critical **NOT proven**: Quest16 mode2 click → F4402 → 0x36(16). Critical **not proven**: specific `0x3F` or `0x1C` received by official Server necessarily elicits `0x40(16,state0)`; such pairing must be cross-validated with T02/Quest16-④/real runtime.

## 1. 三類 application payload 的精確 schema

| 路徑／producer | application bytes（little endian） | 長度 | 來源欄位 | 觸發條件 | 已證／限制 |
|---|---|---:|---|---|---|
| NPC outer event `0x5B9340` | `1C 00 [child+0x18:u16] [child+0x1C:u16]` | 6B | NPC actor/event slots | outer 0x105BD, action 0x6A7, child0x105BF, sender gate0 | [BIN] 跟 QID16 不同；即使篩選沒有可用 QuestID 仍可能建包 |
| controller `0x4A39A0` | `3F 00 [arg1:u16] [arg2:u16] 01 00` | 8B | `0x561760` latched `controller+0x38/0x3C`，或其他 caller args | `0x561DB0` 的 periodic 分支條件／其他 0x561760 mode branch；sender gate0 | [BIN] `(16,1)` 會形成範例 bytes，但只有經過分支送出時成立 |
| TalkBox `0x636E10` | `36 00 [WORD*(TalkBox+0x88)]` | 4B | QuestTalk record 首個 WORD，不是 `TalkBox+0x80` | F4402、outer 0x105BD/action0x6A7、+0x88 非零、sender gate0 | [BIN] 可證 mode1，**不能**從 Quest16 mode2 推導發送 |
| registered `0x4B3510` | `36 00 [WORD*(input_msg+0x2)]` | 4B | 外部輸入訊息 +2 | sender gate0，handler 被真正分派 | [BIN] 單獨的 0x36 producer；槽位註冊 +0x26C，不是 Quest16 accept 證明 |

**所有表內長度都只是 Client 建立的 application payload 大小；不是 TCP 流量、加密/壓縮後網路封裝或含 framing header 的「最終包長」。**

## 2. NPC→controller：type2 候選及 independent 0x1C

- `0x5B9340` 先驗證 event 0x105BD/action0x6A7、child0x105BF；`0x5B93FF` 讀 child+0x14，透過 `0x5008B0` 查 type2 giver 候選。當前 QuestInfo 中 NPC10027 唯一相符 type2 為 QID16，且 Demand14/level/exclusion 等 gates 必須同時通過。`0x5B9447` 以 `push 1; push edi(QID)` 呼叫 `0x561760`。
- `0x5B944C` 才組別的 `0x1C` packet，資料為 child+0x18/+0x1C 的 WORDs。此段**不從 `edi(QID16)` 複製欄位**；因此不能寫成 `1C 00 10 00 ...`，也不能把它當 Quest16 accept。
- 本段特別修正「觸發 QID16」與「發出 0x1C」是同一事件函式中的**相鄰但不同 dataflow**；`0x1C` 送出不意味有任務候選被選中或被 Server 接受。

## 3. controller deferred 0x3F：state lifetime, timing, branches

- 在 `0x561760` 且 `controller+0x28=0` 等正常可用路徑，`0x5618E2` 讀入 argument1、argument2；`0x5618E9/EC` 保存至 `controller+0x38=QID`、`+0x3C=mode/arg2`；`0x5618EF` 保存 `controller+0x28=1`（此處 1 是控制器 flag，非 QuestID）。因此 `0x561760(16,1)` 讓上述值 `(16,1)` 暫存，**函式呼叫本身不等於立即 C2S**。
- `0x561760` 還有條件的立即 `0x3F` 呼叫 `0x5618C8`；先檢查 `[ebp+8]==0`、local mode/stage checks，並將 `arg1=0`，不能套用成 NPC10027 所選 QID16 路徑。
- deferred `0x561DB0` 的 `0x561F79..0x561FB5` 在 `controller+0x38 != 0`、後續環境／stage tests 允許才讀取 latched `(controller+0x38, +0x3C)` 送 `0x4A39A0`，所以 `(16,1)` 對應 `3F 00 10 00 01 00 01 00` 只在符合 branch 及 sender gate 的條件下成立。
- `0x561FB7..0x561FE0` 的另一分支會先經 `0x6BDE40` 更新 controller+0x3C，送出第二個參數未必仍是 1。`0x561DB0` 也受 `controller+0x89/0x28` 及其 stage route 所限，非所有 tick 都送出；非零 `+0x89` 會轉向 `0x565720` 等 scene lookup，而非本次 0x3F 直線。
- **Server 契約**：在收到 0x3F 且 `arg1=16,arg2=1,tail=1` 時，至少需識別這是 Client 場景/控制器進程所送的三個 u16，不能直接當作「已完成 Quest16」。

## 4. 0x36：TalkBox UI mode1 與第二個 handler producer 絕對分開

### 4.1 mode2 negative evidence (important correction)

- T16-121 證明 S2C `0x40(QuestID=16,state=0) → event action0xF438B → 0x5B6D20 → 0x636520`；此路徑在 `0x636520` 將 mode **2** 存入 TalkBox+0x90，QuestID16 到 TalkBox+0x80，giver10027 到 TalkBox+0x84，QuestTalk lookup ptr 到 TalkBox+0x88。
- `0x636B70`: 若 +0xAC>1 提前另行處理；其餘 +0x90=0 走文字繼續；**+0x90=1** 才走 `0x636BDF..0x636C08` 建 action **0xF4402**；+0x90=3 走 `0x636C89..0x636CFA` 的 local action **0xF438A**；**+0x90=2** 通常落到 `0x636CFA`，未產生 F4402。
- `0x636DE0`: UI event handler 在 `event+0x10==0xF4402` 才 call `0x636E10`。後者再核對 outer type0x105BD/action0x6A7、`TalkBox+0x88 != null`、`[0xFBA798]==0`，送 `36 00 WORD*(TalkBox+0x88)`；outer action0x6A8 分支只關閉 UI、沒建立 0x36。
- `TalkBox+0x88` 指向 `0x500F90` 返回的任務對話記錄，不能未驗就當 `QuestID16`（真正 QuestID16 存在 `+0x80`）。所以「Quest16 mode2 Click→0x36 10 00」**目前無原生路徑支援**，不能沿用 T16-117 optimistic expression；實際 mode2 連網可能由其他 handler/event/player flow 驅動，並非此按鍵直接送。

### 4.2 0x4B3510 is independent, inbound-message-driven 0x36 producer

- `0x4B3510` 從第一引數 pointer `[EBP+8]` 讀 WORD `[ptr+2]`，建立四個 stack bytes，內容 `36 00 <input WORD>`，在 `[0xFBA798]==0` 時用完全相同的 global sender virtual +0x10 方法送出；return stdcall `ret 0xC`。
- `0x4ADF8D` 在一張 handler table 寫入 `[EAX+0x26C]=0x4B3510`，而 `0x4ADD50` helper 為每一槽 `[EAX+4+8*i]` 設預設函式；單看這張表，+0x26C 算得槽 `i=(0x26C−4)/8=0x4D`，但在尚未重新完整閉合這張表到實際 wire dispatcher 之前，精確說法是**本張 handler table slot 0x4D**，不直接冒充 S2C wire opcode0x4D。
- 這是由某個輸入訊息觸發、以其 ID 回送 0x36 的**第二個真實 producer**；不能與 UI F4402 或 QID16 mode2 報為同一條 request；也不得以兩個 producer 為理由假設 `0x36` 在所有情況意義唯一。

## 5. 共用 sender instance：結束「虛擬函式未知」的原生閉合

- `0x8046D7` 以 0x5C 配置 sender object，`0x8046F2` 初始化 `0x803D60`，**`0x8046F7` 明確寫 vptr 0xC51748**，`0x80470F` 保存 sender instance 到全域 **`0xFBA854`**。這個寫入證明上述各個 producer 讀取 `[0xFBA854]` 時通常使用此具體型別；生命週期/空指標仍受初始化時序與斷線影響。
- `.rdata` `0xC51748` 直接按 4-byte LE 讀出 vtable：+0x00=`0x806670`, +0x04=`0x806CF0`, +0x08=`0x806850`, +0x0C=`0x8068B0`, +0x10=`0x8069A0`, +0x14=`0x806A00`, +0x18=`0x806AD0`, +0x1C=`0x806F60`。此處先前只有「virtual +0x10」的未知目標已被 **BIN 原件指標值**解決。
- `0x8069A0`: `[EBP+8]` 是該 virtual 呼叫者傳入的 routing key（Quest producers 均 `push 0`）；`0x8438C0` 在 sender+0x18 的 map 找 key，讀命中節點+0x10 的連線對象（為零時直接回0），當 len `[EBP+0x10]` 為零返回1，其他情況從 `[EBP+0x0C]` 取 payload pointer 並以 `(ptr,len)` call `0x8060D0`（ECX=找到的 Conn）。
- `0x8060D0`：對每一 Conn 的 `+0xA0A4` backlog/counter 先檢查上限0x12C；配置 buffer node `0x807470`（通常 0x1000 容量）、當 `len<=0x1000` 複製 `[arg ptr,len]` 到 node+0x8、node+0x4 存長度；`0x806060` 在 mutex/critical section 下把 node 加入 Conn+0xA074 linked queue、增加 Conn+0xA078 並將 Conn+0xA024 設 1。不能把 return queue success 當 WSASend success。
- `0x8061A0` 是此 queue 的 consumer，呼叫點 `0x804AD6` 與 `0x805228`（依 Conn+0xA0AC 可進入）。它依 `Conn+0xA02C` 的 framing mode 分流：mode0→`0x807A70`（4-byte prefix，內含 u16 0x1A68 和 u16 payload len，某些欄位實際寫成 32-bit length code），mode非0→`0x807830`（6-byte header、長度與 XOR/checksum 類處理），成功才消費佇列項；兩個 framing 函式都寫 Conn+0x5004/0x500C 緩衝區。
- `0x8068B0` 是同一 sender vtable +0x0C 的 WSASend native wrapper，使用 Conn I/O state，`0x806912` 經 import address `0xBD25B8` 呼叫 WSASend，非同步 pending `WSAGetLastError()==0x3E5` 走不同 return code。**不能**把 0x8069A0 及其成功返回視為 socket send，同樣不是「Server 已接收」。

## 6. Sequence & pseudo-C（按證據分級）

```cpp
// [BIN] high-level pseudo from verified machine instructions; temporary symbol names
void OnNpc105BD_6A7_105BF(const Event &outer, const Child &child) {
    auto questId = FindType2ByGiver(child.npcId_14, questOwner); // QID16 when gates hold
    ControllerSetCandidate(questId, 1); // may latch into controller+0x38/3c
    if (globalSendGate_FBA798 == 0) {
        uint16_t app[3] = {0x001C, child.word18, child.word1C};
        sender->virtual_0x10(/*routing key*/0, app, 6); // not using questId
    }
}
// [BIN + INF] deferred conditional (additional controller/stage gates omitted here)
void ControllerDeferredSend() {
    if (stageAllows && controller.ready && controller.key38 != 0) {
        sendApp3F((uint16_t)controller.key38, (uint16_t)controller.key3C, 1);
    }
}
void TalkBoxProcessEvent(const Event &evt) {
    if(evt.action == 0xF4402 && evt.outerType == 0x105BD &&
       evt.outerAction == 0x6A7 && talkBox.questTalkRecord != nullptr &&
       globalSendGate_FBA798 == 0) {
        sendApp36(talkBox.questTalkRecord->word0); // NOT talkBox.questId80
    }
}
void RegisteredHandler4B3510(const uint8_t *inboundPtr) {
    if (globalSendGate_FBA798 == 0)
        sendApp36(readLE16(inboundPtr+2));
}
int ConcreteSender_vfunc10(int key, const void *payload, int length) {
    Conn *c = sender.connByKey_18[key];
    if(!c) return 0;
    if(!length) return 1;
    return ConnectionEnqueue_8060D0(c, payload, length);
}
```

Caveats: this pseudocode condenses gates intentionally; the exact original machine branches, allocation failure paths and event ownership appear below. Do not use this illustrative code as a binary-perfect ABI implementation.

## 7. Application payload examples and non-equivalence

- For child event+18=`AA BB` and +1C=`CC DD`, C2S 0x1C bytes are `1C 00 AA BB CC DD` **irrespective of selected QuestID**.
- For controller `(arg1,arg2)=(16,1)` and sender gate0, 0x3F application bytes are **`3F 00 10 00 01 00 01 00`**, only conditional on deferred/other sender branch. If controller transformation changes second word, adapt it.
- If `TalkBox+88` record first WORD happened to be 16 and mode1 + F4402 route is reached, 0x36 bytes would be `36 00 10 00`. **Do not treat this hypothetical byte sequence as the native Quest16 mode2 user click result**.
- If 0x4B3510 input+2 is WORD 16, it would also send `36 00 10 00`, but its origin is **a registered message handler**, not the mode2 UI. Same bytes ≠ same trigger semantics.
- The 0x40 inbound `state=0/QID=16` from T16-121 triggers mode2 UI; **no proven original Server 0x3F↔0x40 causality**, and the original server may send state0 under distinct client actions. Server design must either obtain original traffic evidence or document a compatibility ADR.

## 8. Server compatibility and task interfaces (not official server algorithm)

1. **NPC interaction request:** handle the fact Client can enqueue 0x1C actor WORD pair (the actual mapping of these WORDs to NPC/session identity belongs T06/T07 plus actor evidence), do not equate both with quest id.
2. **Controller/stage signal:** recognize 0x3F `u16 arg1,u16 arg2,u16 tail(1)` as separate 8-byte payload (plus T02 framing), may be deferred; QID16 can occur in arg1 when controller state matches.
3. **0x36 messages:** receive 4-byte `u16 op,u16 id`; the ID is producer-dependent. If implementing Quest16 accept/turn-in via 0x36, require T16-④/T02 traffic/pairing or explicitly an ADR; do not infer from the mere existence of producer.
4. **Outbound framing is conditional:** T02 must select between observed `0x807A70` and `0x807830` modes based on connection state, plus account for async queue and virtual+0x0C wrapper. No invented single universal four/six-byte header.
5. **NPC response/UI:** T16-121 already verified inbound `0x40(quest16,state0)`→`0xF438B`→mode2 TalkBox. **Original Server dispatch/policy for generating this response remains unknown**. Client static applicability confirmed, not runtime sequence.
6. **Server storage/quests:** quest14 prereq, candidate key 16 and later quest15 requirement16 are Client data constraints; persisted state, quest rewards, anti-cheat, Server player progression and scene selection are independent Server implementation goals, not recoverable from Client alone.

## 9. Explicit open questions split by owner

**Client 待逆向（不虛稱已閉合）**

- `0x4ADF8D` registered message slot0x4D (`0x4B3510`) actual outer dispatch namespace/index: establish complete inbound decoder→handler invocation before naming it S2C wire opcode.
- Quest16 mode2 的實際按鍵/對話完成動作是否還有其他間接的 producer，以及 `QuestTalk` +0 是否與 QuestID16 相同：目前 mode2 normal local event **未**產生 F4402；其他 UI 自訂源、腳本和動態 handler 仍可能存在。此項不是以無證據的 0x36 補齊，而留待 T16-④/後續 UI 精查。
- 更精確的 `0x561DB0` 多環境分支、0x3F 的所有 controller stage paths 與不觸發例外，需要其 runtime stage conditions；本稿已明列在能由 Client 證明的 source→queue 有界流程。

**Server 待開發**

- 兼容 Server 自行定義 Quest16 NPC request 的回應策略；若選擇 0x40 state0/QID16，需依 T16-121 已知 Client 解析規格實作，不得假稱官方必然這樣配對；完成/拒絕/重試、有效 NPC、保存與獎勵需自訂具可驗收契約。

**跨功能待整合**

- T02: C→S framing mode, write queue, send/receive semantics and opcode namespace；T06 NPC targeting; T07 field/stage actor events; T03/T04 account/character initialization and quest state; T08 resources/events; T14 stage result; T15 persistency; T01 bounded FULL-PASS validation; S00 SPEC/GAP/TEST intake.

**待遊玩驗證**

- 실제 Server／Client 實機操作 NPC10027、原始應用封包與 framing 抓包、0x40 前後狀態／事件／mode2 TalkBox、不同 quest14 completed/not completed、網路斷線重連與 UI 回復。

## 10. Quest16 five-study tracking and next scope

| 子研究 | 狀態（本稿後） | 界線 |
|---|---|---|
| ① 資源／前置 | T16-118 有界完成 | Quest14 Demand、giver+town、type2 vector與候選 gates |
| ② NPC 互動與 mode2 TalkBox | T16-121 Client 靜態有界完成 | NPC候選和入站事件→UI各自靜態閉合；原版 Server 配對未證 |
| **③ C→S** | **T16-122 Client application producer→queue 靜態有界完成** | 0x1C／0x3F／雙0x36的原生 sender gates + stage/模式反證；Server配對／wire framing不越權 |
| ④ S→C/state/UI | 待正式研究 | `0x40` state0/1、`0x74` prereq word16、GUI 狀態/其他 response 與 handler pair |
| ⑤ Quest16→Quest15 | 待正式研究 | 前置鍵16下行、場景/npc10338、獎勵轉換及任務領取 |

**下一正式段號：T16-123／Quest16-④**。以 S2C `0x40` state分流、0x74前置 list、mode2 TalkBox 生命週期與 UI 反應為主，若 0x4D slot 到 wire dispatch 配對會影響④，應同段拉通。後續完成 Quest16⑤ 再研究 Quest15 五子研究與 Pindos village 端到端。

---

## 11. 原始 BIN disassembly appendix — all below slice hashes are first-hand

下列為本段重要指令鏈的原文；只有 code-like text / stable function start 可採作 32-bit Intel assembly。個別 slice stop 不保證剛好切在 ret，務必按 address/bytes 讀，不可把截斷末尾的 opcode 視為實際指令。請參考每段 SHA256 重新定址。

### A01. NPC producer/event assertion/QuestID and 0x1C

Native 0x105BD/6A7/0x105BF checks; type2 filtered QID; 0x1C explicit actor fields and sender gate.

證據：KR 原生 BIN `.text` raw `[0x1B8740,0x1B8898)`、VA `[0x5B9340,0x5B9498)`，344 bytes，slice SHA256 `69a5aadbc0a1ffa9d11ec62c74a1d8a40e201eee8d0e9192b5903e56aab4df99`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
005b9340 <.data+0x1b8740>:
  5b9340:	55                   	push   ebp
  5b9341:	8b ec                	mov    ebp,esp
  5b9343:	6a ff                	push   0xffffffff
  5b9345:	68 b7 73 94 00       	push   0x9473b7
  5b934a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b9350:	50                   	push   eax
  5b9351:	83 ec 0c             	sub    esp,0xc
  5b9354:	56                   	push   esi
  5b9355:	57                   	push   edi
  5b9356:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b935b:	33 c5                	xor    eax,ebp
  5b935d:	50                   	push   eax
  5b935e:	8d 45 f4             	lea    eax,[ebp-0xc]
  5b9361:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5b9367:	8b f1                	mov    esi,ecx
  5b9369:	8b 3d 80 25 bd 00    	mov    edi,DWORD PTR ds:0xbd2580
  5b936f:	85 f6                	test   esi,esi
  5b9371:	74 22                	je     0x5b9395
  5b9373:	8b 06                	mov    eax,DWORD PTR [esi]
  5b9375:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b9378:	ff d2                	call   edx
  5b937a:	3d bd 05 01 00       	cmp    eax,0x105bd
  5b937f:	75 04                	jne    0x5b9385
  5b9381:	8b c6                	mov    eax,esi
  5b9383:	eb 12                	jmp    0x5b9397
  5b9385:	6a 00                	push   0x0
  5b9387:	68 c0 1f bf 00       	push   0xbf1fc0
  5b938c:	68 18 21 bf 00       	push   0xbf2118
  5b9391:	6a 00                	push   0x0
  5b9393:	ff d7                	call   edi
  5b9395:	33 c0                	xor    eax,eax
  5b9397:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  5b939a:	81 f9 a7 06 00 00    	cmp    ecx,0x6a7
  5b93a0:	0f 85 f2 00 00 00    	jne    0x5b9498
  5b93a6:	8b 70 18             	mov    esi,DWORD PTR [eax+0x18]
  5b93a9:	85 f6                	test   esi,esi
  5b93ab:	74 20                	je     0x5b93cd
  5b93ad:	8b 06                	mov    eax,DWORD PTR [esi]
  5b93af:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b93b2:	8b ce                	mov    ecx,esi
  5b93b4:	ff d2                	call   edx
  5b93b6:	3d bf 05 01 00       	cmp    eax,0x105bf
  5b93bb:	74 12                	je     0x5b93cf
  5b93bd:	6a 00                	push   0x0
  5b93bf:	68 c0 1f bf 00       	push   0xbf1fc0
  5b93c4:	68 18 21 bf 00       	push   0xbf2118
  5b93c9:	6a 00                	push   0x0
  5b93cb:	ff d7                	call   edi
  5b93cd:	33 f6                	xor    esi,esi
  5b93cf:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b93d6:	75 27                	jne    0x5b93ff
  5b93d8:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b93df:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  5b93e6:	e8 75 6a f4 ff       	call   0x4ffe60
  5b93eb:	68 00 cf bc 00       	push   0xbccf00
  5b93f0:	e8 25 8f 2d 00       	call   0x89231a
  5b93f5:	83 c4 04             	add    esp,0x4
  5b93f8:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5b93ff:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  5b9402:	ba a0 b2 fa 00       	mov    edx,0xfab2a0
  5b9407:	e8 a4 74 f4 ff       	call   0x5008b0
  5b940c:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  5b9413:	0f b7 f8             	movzx  edi,ax
  5b9416:	75 27                	jne    0x5b943f
  5b9418:	b8 01 00 00 00       	mov    eax,0x1
  5b941d:	09 05 b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,eax
  5b9423:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  5b9426:	e8 45 6d fa ff       	call   0x560170
  5b942b:	68 10 d1 bc 00       	push   0xbcd110
  5b9430:	e8 e5 8e 2d 00       	call   0x89231a
  5b9435:	83 c4 04             	add    esp,0x4
  5b9438:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5b943f:	6a 01                	push   0x1
  5b9441:	57                   	push   edi
  5b9442:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  5b9447:	e8 14 83 fa ff       	call   0x561760
  5b944c:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  5b9453:	b8 1c 00 00 00       	mov    eax,0x1c
  5b9458:	66 89 45 e8          	mov    WORD PTR [ebp-0x18],ax
  5b945c:	66 8b 4e 18          	mov    cx,WORD PTR [esi+0x18]
  5b9460:	66 89 4d ea          	mov    WORD PTR [ebp-0x16],cx
  5b9464:	66 8b 56 1c          	mov    dx,WORD PTR [esi+0x1c]
  5b9468:	66 89 55 ec          	mov    WORD PTR [ebp-0x14],dx
  5b946c:	0f 85 e1 00 00 00    	jne    0x5b9553
  5b9472:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  5b9478:	8b 01                	mov    eax,DWORD PTR [ecx]
  5b947a:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  5b947d:	6a 06                	push   0x6
  5b947f:	8d 55 e8             	lea    edx,[ebp-0x18]
  5b9482:	52                   	push   edx
  5b9483:	6a 00                	push   0x0
  5b9485:	ff d0                	call   eax
  5b9487:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5b948a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b9491:	59                   	pop    ecx
  5b9492:	5f                   	pop    edi
  5b9493:	5e                   	pop    esi
  5b9494:	8b e5                	mov    esp,ebp
  5b9496:	5d                   	pop    ebp
  5b9497:	c3                   	ret
```

### A02. controller source + latched 0x38/0x3C

Controller+0x28/0x89 gates, immediate special arg1=0 sender; 16/1 latching.

證據：KR 原生 BIN `.text` raw `[0x160B60,0x160D45)`、VA `[0x561760,0x561945)`，485 bytes，slice SHA256 `6ac6fbc8a9ffc5b88ad7e3c633181202a13b6a78827c3650209e949899e7e4cc`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
00561760 <.data+0x160b60>:
  561760:	55                   	push   ebp
  561761:	8b ec                	mov    ebp,esp
  561763:	83 e4 f8             	and    esp,0xfffffff8
  561766:	6a ff                	push   0xffffffff
  561768:	68 2c fd 93 00       	push   0x93fd2c
  56176d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  561773:	50                   	push   eax
  561774:	83 ec 50             	sub    esp,0x50
  561777:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56177c:	33 c4                	xor    eax,esp
  56177e:	89 44 24 48          	mov    DWORD PTR [esp+0x48],eax
  561782:	53                   	push   ebx
  561783:	56                   	push   esi
  561784:	57                   	push   edi
  561785:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56178a:	33 c4                	xor    eax,esp
  56178c:	50                   	push   eax
  56178d:	8d 44 24 60          	lea    eax,[esp+0x60]
  561791:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  561797:	83 3d 18 ab fb 00 00 	cmp    DWORD PTR ds:0xfbab18,0x0
  56179e:	8b d9                	mov    ebx,ecx
  5617a0:	74 20                	je     0x5617c2
  5617a2:	0f 57 c0             	xorps  xmm0,xmm0
  5617a5:	f3 0f 11 05 24 ab fb 	movss  DWORD PTR ds:0xfbab24,xmm0
  5617ac:	00 
  5617ad:	e8 ae d8 ea ff       	call   0x40f060
  5617b2:	f3 0f 10 05 70 59 c5 	movss  xmm0,DWORD PTR ds:0xc55970
  5617b9:	00 
  5617ba:	f3 0f 11 80 ac 00 00 	movss  DWORD PTR [eax+0xac],xmm0
  5617c1:	00 
  5617c2:	83 7b 28 00          	cmp    DWORD PTR [ebx+0x28],0x0
  5617c6:	c6 83 89 00 00 00 00 	mov    BYTE PTR [ebx+0x89],0x0
  5617cd:	74 1a                	je     0x5617e9
  5617cf:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5617d2:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  5617d5:	50                   	push   eax
  5617d6:	51                   	push   ecx
  5617d7:	68 ac 06 c1 00       	push   0xc106ac
  5617dc:	e8 7f c3 18 00       	call   0x6edb60
  5617e1:	83 c4 0c             	add    esp,0xc
  5617e4:	e9 9d 05 00 00       	jmp    0x561d86
  5617e9:	f6 05 28 88 fb 00 01 	test   BYTE PTR ds:0xfb8828,0x1
  5617f0:	be 01 00 00 00       	mov    esi,0x1
  5617f5:	75 29                	jne    0x561820
  5617f7:	09 35 28 88 fb 00    	or     DWORD PTR ds:0xfb8828,esi
  5617fd:	c7 44 24 68 00 00 00 	mov    DWORD PTR [esp+0x68],0x0
  561804:	00 
  561805:	e8 46 e0 fe ff       	call   0x54f850
  56180a:	68 80 d5 bc 00       	push   0xbcd580
  56180f:	e8 06 0b 33 00       	call   0x89231a
  561814:	83 c4 04             	add    esp,0x4
  561817:	83 cf ff             	or     edi,0xffffffff
  56181a:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  56181e:	eb 03                	jmp    0x561823
  561820:	83 cf ff             	or     edi,0xffffffff
  561823:	80 3d f1 92 fb 00 00 	cmp    BYTE PTR ds:0xfb92f1,0x0
  56182a:	0f 84 ac 00 00 00    	je     0x5618dc
  561830:	83 7d 08 00          	cmp    DWORD PTR [ebp+0x8],0x0
  561834:	0f 85 a2 00 00 00    	jne    0x5618dc
  56183a:	e8 61 33 ea ff       	call   0x404ba0
  56183f:	83 b8 4c 5f 00 00 09 	cmp    DWORD PTR [eax+0x5f4c],0x9
  561846:	74 1c                	je     0x561864
  561848:	e8 53 33 ea ff       	call   0x404ba0
  56184d:	83 b8 4c 5f 00 00 04 	cmp    DWORD PTR [eax+0x5f4c],0x4
  561854:	74 0e                	je     0x561864
  561856:	e8 45 33 ea ff       	call   0x404ba0
  56185b:	83 b8 4c 5f 00 00 19 	cmp    DWORD PTR [eax+0x5f4c],0x19
  561862:	75 78                	jne    0x5618dc
  561864:	8b 73 78             	mov    esi,DWORD PTR [ebx+0x78]
  561867:	8d 55 0c             	lea    edx,[ebp+0xc]
  56186a:	52                   	push   edx
  56186b:	8d 4b 74             	lea    ecx,[ebx+0x74]
  56186e:	8d 44 24 14          	lea    eax,[esp+0x14]
  561872:	e8 49 4c ed ff       	call   0x4364c0
  561877:	39 30                	cmp    DWORD PTR [eax],esi
  561879:	74 5c                	je     0x5618d7
  56187b:	6a 0f                	push   0xf
  56187d:	e8 2e 3d 02 00       	call   0x5855b0
  561882:	8b f0                	mov    esi,eax
  561884:	e8 a7 3a 02 00       	call   0x585330
  561889:	50                   	push   eax
  56188a:	8d 4c 24 40          	lea    ecx,[esp+0x40]
  56188e:	e8 bd 09 ea ff       	call   0x402250
  561893:	8d 44 24 3c          	lea    eax,[esp+0x3c]
  561897:	50                   	push   eax
  561898:	c7 44 24 6c 01 00 00 	mov    DWORD PTR [esp+0x6c],0x1
  56189f:	00 
  5618a0:	e8 1b e0 ea ff       	call   0x40f8c0
  5618a5:	8b f8                	mov    edi,eax
  5618a7:	e8 84 52 f7 ff       	call   0x4d6b30
  5618ac:	8d 4c 24 3c          	lea    ecx,[esp+0x3c]
  5618b0:	c7 44 24 68 ff ff ff 	mov    DWORD PTR [esp+0x68],0xffffffff
  5618b7:	ff 
  5618b8:	e8 83 8b f9 ff       	call   0x4fa440
  5618bd:	e8 be 2d eb ff       	call   0x414680
  5618c2:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  5618c5:	51                   	push   ecx
  5618c6:	6a 00                	push   0x0
  5618c8:	e8 d3 20 f4 ff       	call   0x4a39a0
  5618cd:	e8 de 07 00 00       	call   0x5620b0
  5618d2:	e9 af 04 00 00       	jmp    0x561d86
  5618d7:	be 01 00 00 00       	mov    esi,0x1
  5618dc:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  5618e3:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  5618e6:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5618e9:	89 53 38             	mov    DWORD PTR [ebx+0x38],edx
  5618ec:	89 43 3c             	mov    DWORD PTR [ebx+0x3c],eax
  5618ef:	89 73 28             	mov    DWORD PTR [ebx+0x28],esi
  5618f2:	75 24                	jne    0x561918
  5618f4:	09 35 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,esi
  5618fa:	c7 44 24 68 02 00 00 	mov    DWORD PTR [esp+0x68],0x2
  561901:	00 
  561902:	e8 79 5b 02 00       	call   0x587480
  561907:	68 c0 cc bc 00       	push   0xbcccc0
  56190c:	e8 09 0a 33 00       	call   0x89231a
  561911:	83 c4 04             	add    esp,0x4
  561914:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  561918:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  56191f:	75 24                	jne    0x561945
  561921:	09 35 d0 ad fa 00    	or     DWORD PTR ds:0xfaadd0,esi
  561927:	c7 44 24 68 03 00 00 	mov    DWORD PTR [esp+0x68],0x3
  56192e:	00 
  56192f:	e8 5c c0 1e 00       	call   0x74d990
  561934:	68 70 cc bc 00       	push   0xbccc70
  561939:	e8 dc 09 33 00       	call   0x89231a
  56193e:	83 c4 04             	add    esp,0x4
  561941:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
```

### A03. controller deferred dispatch state

Per-frame controller function entry and gate state.

證據：KR 原生 BIN `.text` raw `[0x1611B0,0x161235)`、VA `[0x561DB0,0x561E35)`，133 bytes，slice SHA256 `37a835c6a31c556b298b8f15fd4e4ca1f37e599fc785639cbdb4f3b334cb7937`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
00561db0 <.data+0x1611b0>:
  561db0:	55                   	push   ebp
  561db1:	8b ec                	mov    ebp,esp
  561db3:	83 e4 f8             	and    esp,0xfffffff8
  561db6:	6a ff                	push   0xffffffff
  561db8:	68 64 fc 93 00       	push   0x93fc64
  561dbd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  561dc3:	50                   	push   eax
  561dc4:	83 ec 10             	sub    esp,0x10
  561dc7:	53                   	push   ebx
  561dc8:	56                   	push   esi
  561dc9:	57                   	push   edi
  561dca:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  561dcf:	33 c4                	xor    eax,esp
  561dd1:	50                   	push   eax
  561dd2:	8d 44 24 20          	lea    eax,[esp+0x20]
  561dd6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  561ddc:	8b f9                	mov    edi,ecx
  561dde:	33 f6                	xor    esi,esi
  561de0:	80 bf 89 00 00 00 00 	cmp    BYTE PTR [edi+0x89],0x0
  561de7:	0f 84 73 01 00 00    	je     0x561f60
  561ded:	39 77 28             	cmp    DWORD PTR [edi+0x28],esi
  561df0:	0f 84 aa 00 00 00    	je     0x561ea0
  561df6:	89 77 28             	mov    DWORD PTR [edi+0x28],esi
  561df9:	e8 52 24 ed ff       	call   0x434250
  561dfe:	bb 01 00 00 00       	mov    ebx,0x1
  561e03:	89 58 14             	mov    DWORD PTR [eax+0x14],ebx
  561e06:	84 1d d4 f3 fd 00    	test   BYTE PTR ds:0xfdf3d4,bl
  561e0c:	75 25                	jne    0x561e33
  561e0e:	09 1d d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,ebx
  561e14:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561e18:	e8 63 25 19 00       	call   0x6f4380
  561e1d:	68 d0 e6 bc 00       	push   0xbce6d0
  561e22:	e8 f3 04 33 00       	call   0x89231a
  561e27:	83 c4 04             	add    esp,0x4
  561e2a:	83 ce ff             	or     esi,0xffffffff
  561e2d:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561e31:	eb 03                	jmp    0x561e36
  561e33:	83 ce              	or     esi,0xffffffff
```

### A04. controller deferred 0x3F call sites

Separate 0x561FB0 and 0x561FE0 calls and branch-specific arg mutation.

證據：KR 原生 BIN `.text` raw `[0x161369,0x161410)`、VA `[0x561F69,0x562010)`，167 bytes，slice SHA256 `4696ef6b04e5094ab5c416682219383a5db2da142685b5052a4210148d0d1c43`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
00561f69 <.data+0x161369>:
  561f69:	89 77 28             	mov    DWORD PTR [edi+0x28],esi
  561f6c:	e8 df 22 ed ff       	call   0x434250
  561f71:	bb 01 00 00 00       	mov    ebx,0x1
  561f76:	89 58 14             	mov    DWORD PTR [eax+0x14],ebx
  561f79:	39 77 38             	cmp    DWORD PTR [edi+0x38],esi
  561f7c:	74 39                	je     0x561fb7
  561f7e:	68 44 03 c1 00       	push   0xc10344
  561f83:	53                   	push   ebx
  561f84:	e8 a7 92 f3 ff       	call   0x49b230
  561f89:	50                   	push   eax
  561f8a:	e8 11 b1 f4 ff       	call   0x4ad0a0
  561f8f:	6a ff                	push   0xffffffff
  561f91:	51                   	push   ecx
  561f92:	e8 99 92 f3 ff       	call   0x49b230
  561f97:	83 c4 04             	add    esp,0x4
  561f9a:	e8 b1 0b f4 ff       	call   0x4a2b50
  561f9f:	3b c3                	cmp    eax,ebx
  561fa1:	75 4e                	jne    0x561ff1
  561fa3:	e8 d8 26 eb ff       	call   0x414680
  561fa8:	8b 4f 3c             	mov    ecx,DWORD PTR [edi+0x3c]
  561fab:	8b 57 38             	mov    edx,DWORD PTR [edi+0x38]
  561fae:	51                   	push   ecx
  561faf:	52                   	push   edx
  561fb0:	e8 eb 19 f4 ff       	call   0x4a39a0
  561fb5:	eb 3a                	jmp    0x561ff1
  561fb7:	8d 5f 3c             	lea    ebx,[edi+0x3c]
  561fba:	8d 77 74             	lea    esi,[edi+0x74]
  561fbd:	53                   	push   ebx
  561fbe:	e8 7d be 15 00       	call   0x6bde40
  561fc3:	50                   	push   eax
  561fc4:	56                   	push   esi
  561fc5:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  561fc9:	e8 c2 48 ed ff       	call   0x436890
  561fce:	57                   	push   edi
  561fcf:	e8 cc 03 00 00       	call   0x5623a0
  561fd4:	e8 a7 26 eb ff       	call   0x414680
  561fd9:	8b 03                	mov    eax,DWORD PTR [ebx]
  561fdb:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  561fde:	50                   	push   eax
  561fdf:	51                   	push   ecx
  561fe0:	e8 bb 19 f4 ff       	call   0x4a39a0
  561fe5:	e8 c6 00 00 00       	call   0x5620b0
  561fea:	bb 01 00 00 00       	mov    ebx,0x1
  561fef:	33 f6                	xor    esi,esi
  561ff1:	f6 05 d4 f3 fd 00 01 	test   BYTE PTR ds:0xfdf3d4,0x1
  561ff8:	75 28                	jne    0x562022
  561ffa:	09 1d d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,ebx
  562000:	c7 44 24 28 04 00 00 	mov    DWORD PTR [esp+0x28],0x4
  562007:	00 
  562008:	e8 73 23 19 00       	call   0x6f4380
  56200d:	68 d0 e6         	push   0xbce6d0
```

### A05. 0x3F app buffer and common sender

Little-endian 4 words and `[0xFBA798]`, global vtable+0x10.

證據：KR 原生 BIN `.text` raw `[0xA2DA0,0xA2DEC)`、VA `[0x4A39A0,0x4A39EC)`，76 bytes，slice SHA256 `dbb0c12cfc16ef6738deb33fda9cb2b410be3aae67e89a6df6b71e7fd1711976`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
004a39a0 <.data+0xa2da0>:
  4a39a0:	55                   	push   ebp
  4a39a1:	8b ec                	mov    ebp,esp
  4a39a3:	83 ec 08             	sub    esp,0x8
  4a39a6:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a39ad:	66 8b 4d 08          	mov    cx,WORD PTR [ebp+0x8]
  4a39b1:	66 8b 55 0c          	mov    dx,WORD PTR [ebp+0xc]
  4a39b5:	b8 3f 00 00 00       	mov    eax,0x3f
  4a39ba:	66 89 45 f8          	mov    WORD PTR [ebp-0x8],ax
  4a39be:	b8 01 00 00 00       	mov    eax,0x1
  4a39c3:	66 89 4d fa          	mov    WORD PTR [ebp-0x6],cx
  4a39c7:	66 89 55 fc          	mov    WORD PTR [ebp-0x4],dx
  4a39cb:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  4a39cf:	75 15                	jne    0x4a39e6
  4a39d1:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a39d7:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a39d9:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a39dc:	6a 08                	push   0x8
  4a39de:	8d 45 f8             	lea    eax,[ebp-0x8]
  4a39e1:	50                   	push   eax
  4a39e2:	6a 00                	push   0x0
  4a39e4:	ff d2                	call   edx
  4a39e6:	8b e5                	mov    esp,ebp
  4a39e8:	5d                   	pop    ebp
  4a39e9:	c2 08 00             	ret    0x8
```

### A06. TalkBox mode1 F4402 vs mode2 fall-through

Specific mode branch: 1 creates F4402, 3 creates F438A, 2 falls through.

證據：KR 原生 BIN `.text` raw `[0x235F70,0x236115)`、VA `[0x636B70,0x636D15)`，421 bytes，slice SHA256 `cee27f2c412279b5363857755fb3217c1948e0ab3910bd7e7639e5cec99d5890`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
00636b70 <.data+0x235f70>:
  636b70:	55                   	push   ebp
  636b71:	8b ec                	mov    ebp,esp
  636b73:	83 e4 f8             	and    esp,0xfffffff8
  636b76:	6a ff                	push   0xffffffff
  636b78:	68 97 89 94 00       	push   0x948997
  636b7d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  636b83:	50                   	push   eax
  636b84:	83 ec 7c             	sub    esp,0x7c
  636b87:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  636b8c:	33 c4                	xor    eax,esp
  636b8e:	89 44 24 74          	mov    DWORD PTR [esp+0x74],eax
  636b92:	53                   	push   ebx
  636b93:	56                   	push   esi
  636b94:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  636b99:	33 c4                	xor    eax,esp
  636b9b:	50                   	push   eax
  636b9c:	8d 84 24 88 00 00 00 	lea    eax,[esp+0x88]
  636ba3:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  636ba9:	83 bf ac 00 00 00 01 	cmp    DWORD PTR [edi+0xac],0x1
  636bb0:	76 0c                	jbe    0x636bbe
  636bb2:	8b c7                	mov    eax,edi
  636bb4:	e8 a7 01 00 00       	call   0x636d60
  636bb9:	e9 3c 01 00 00       	jmp    0x636cfa
  636bbe:	8b 87 90 00 00 00    	mov    eax,DWORD PTR [edi+0x90]
  636bc4:	33 db                	xor    ebx,ebx
  636bc6:	3b c3                	cmp    eax,ebx
  636bc8:	75 0c                	jne    0x636bd6
  636bca:	8b f7                	mov    esi,edi
  636bcc:	e8 4f 01 00 00       	call   0x636d20
  636bd1:	e9 24 01 00 00       	jmp    0x636cfa
  636bd6:	83 f8 01             	cmp    eax,0x1
  636bd9:	0f 85 a5 00 00 00    	jne    0x636c84
  636bdf:	6a 14                	push   0x14
  636be1:	e8 82 a6 25 00       	call   0x891268
  636be6:	83 c4 04             	add    esp,0x4
  636be9:	3b c3                	cmp    eax,ebx
  636beb:	74 1b                	je     0x636c08
  636bed:	83 c9 ff             	or     ecx,0xffffffff
  636bf0:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  636bf3:	c7 00 0c 7b c4 00    	mov    DWORD PTR [eax],0xc47b0c
  636bf9:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  636bfc:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  636bff:	c7 40 10 02 44 0f 00 	mov    DWORD PTR [eax+0x10],0xf4402
  636c06:	8b d8                	mov    ebx,eax
  636c08:	8b 87 88 00 00 00    	mov    eax,DWORD PTR [edi+0x88]
  636c0e:	83 c0 4c             	add    eax,0x4c
  636c11:	50                   	push   eax
  636c12:	8d 74 24 4c          	lea    esi,[esp+0x4c]
  636c16:	e8 85 08 12 00       	call   0x7574a0
  636c1b:	6a 1f                	push   0x1f
  636c1d:	c7 84 24 94 00 00 00 	mov    DWORD PTR [esp+0x94],0x0
  636c24:	00 00 00 00 
  636c28:	e8 83 e8 f4 ff       	call   0x5854b0
  636c2d:	8b f0                	mov    esi,eax
  636c2f:	e8 fc e6 f4 ff       	call   0x585330
  636c34:	50                   	push   eax
  636c35:	8d 74 24 14          	lea    esi,[esp+0x14]
  636c39:	e8 b2 06 12 00       	call   0x7572f0
  636c3e:	57                   	push   edi
  636c3f:	53                   	push   ebx
  636c40:	8d 4c 24 50          	lea    ecx,[esp+0x50]
  636c44:	51                   	push   ecx
  636c45:	8b d6                	mov    edx,esi
  636c47:	52                   	push   edx
  636c48:	68 cf 00 00 00       	push   0xcf
  636c4d:	c6 84 24 a4 00 00 00 	mov    BYTE PTR [esp+0xa4],0x1
  636c54:	01 
  636c55:	e8 d6 06 dd ff       	call   0x407330
  636c5a:	83 c4 14             	add    esp,0x14
  636c5d:	8b c6                	mov    eax,esi
  636c5f:	50                   	push   eax
  636c60:	c6 84 24 94 00 00 00 	mov    BYTE PTR [esp+0x94],0x0
  636c67:	00 
  636c68:	e8 d3 09 12 00       	call   0x757640
  636c6d:	8d 4c 24 48          	lea    ecx,[esp+0x48]
  636c71:	51                   	push   ecx
  636c72:	c7 84 24 94 00 00 00 	mov    DWORD PTR [esp+0x94],0xffffffff
  636c79:	ff ff ff ff 
  636c7d:	e8 be 09 12 00       	call   0x757640
  636c82:	eb 76                	jmp    0x636cfa
  636c84:	83 f8 03             	cmp    eax,0x3
  636c87:	75 71                	jne    0x636cfa
  636c89:	8b 87 88 00 00 00    	mov    eax,DWORD PTR [edi+0x88]
  636c8f:	3b c3                	cmp    eax,ebx
  636c91:	74 67                	je     0x636cfa
  636c93:	8b 10                	mov    edx,DWORD PTR [eax]
  636c95:	52                   	push   edx
  636c96:	51                   	push   ecx
  636c97:	e8 94 8c dd ff       	call   0x40f930
  636c9c:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  636ca2:	83 c4 04             	add    esp,0x4
  636ca5:	8b d0                	mov    edx,eax
  636ca7:	e8 24 9b ec ff       	call   0x5007d0
  636cac:	0f b7 f0             	movzx  esi,ax
  636caf:	85 f6                	test   esi,esi
  636cb1:	74 47                	je     0x636cfa
  636cb3:	6a 18                	push   0x18
  636cb5:	e8 ae a5 25 00       	call   0x891268
  636cba:	83 c4 04             	add    esp,0x4
  636cbd:	85 c0                	test   eax,eax
  636cbf:	74 1e                	je     0x636cdf
  636cc1:	83 c9 ff             	or     ecx,0xffffffff
  636cc4:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  636cc7:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  636cca:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  636ccd:	c7 40 10 8a 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf438a
  636cd4:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  636cda:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  636cdd:	eb 02                	jmp    0x636ce1
  636cdf:	33 c0                	xor    eax,eax
  636ce1:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  636ce5:	e8 b6 dd dc ff       	call   0x404aa0
  636cea:	8d 4c 24 0c          	lea    ecx,[esp+0xc]
  636cee:	51                   	push   ecx
  636cef:	8d b0 5c 14 00 00    	lea    esi,[eax+0x145c]
  636cf5:	e8 66 d5 1c 00       	call   0x804260
  636cfa:	8b 8c 24 88 00 00 00 	mov    ecx,DWORD PTR [esp+0x88]
  636d01:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  636d08:	59                   	pop    ecx
  636d09:	5e                   	pop    esi
  636d0a:	5b                   	pop    ebx
  636d0b:	8b 4c 24 74          	mov    ecx,DWORD PTR [esp+0x74]
  636d0f:	33 cc                	xor    ecx,esp
  636d11:	e8 eb a2 25        	call   0x891001
```

### A07. TalkBox UI callback 0xF4402 and 0x36

TalkBox+0x88 record first WORD; action 0x6A7; virtual+0x10 send only with gate.

證據：KR 原生 BIN `.text` raw `[0x2361E0,0x2362D0)`、VA `[0x636DE0,0x636ED0)`，240 bytes，slice SHA256 `a385b5b3240f2f9586c8895779d8a6b3db4ca4932109ea896376319dc518b067`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
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

### A08. second 0x36 producer from inbound buf

Reads input+2 WORD, builds 36 00 ID, global sender.

證據：KR 原生 BIN `.text` raw `[0xB2910,0xB296C)`、VA `[0x4B3510,0x4B356C)`，92 bytes，slice SHA256 `71b378cac33808dc4419240471935b14535edabd107b8ca1bad0664f8b14793c`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
004b3510 <.data+0xb2910>:
  4b3510:	55                   	push   ebp
  4b3511:	8b ec                	mov    ebp,esp
  4b3513:	51                   	push   ecx
  4b3514:	b8 01 00 00 00       	mov    eax,0x1
  4b3519:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  4b351f:	75 13                	jne    0x4b3534
  4b3521:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  4b3527:	68 10 cf bc 00       	push   0xbccf10
  4b352c:	e8 e9 ed 3d 00       	call   0x89231a
  4b3531:	83 c4 04             	add    esp,0x4
  4b3534:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b353b:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b353e:	66 8b 51 02          	mov    dx,WORD PTR [ecx+0x2]
  4b3542:	b8 36 00 00 00       	mov    eax,0x36
  4b3547:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4b354b:	66 89 55 fe          	mov    WORD PTR [ebp-0x2],dx
  4b354f:	75 15                	jne    0x4b3566
  4b3551:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b3557:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b3559:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4b355c:	6a 04                	push   0x4
  4b355e:	8d 55 fc             	lea    edx,[ebp-0x4]
  4b3561:	52                   	push   edx
  4b3562:	6a 00                	push   0x0
  4b3564:	ff d0                	call   eax
  4b3566:	33 c0                	xor    eax,eax
  4b3568:	8b e5                	mov    esp,ebp
  4b356a:	5d                   	pop    ebp
  4b356b:	c2               	ret    0xc
```

### A09. dispatch table default 8-byte slot layout

Default table entry `eax+4+8*i`; does not alone prove wire index mapping.

證據：KR 原生 BIN `.text` raw `[0xAD150,0xAD18C)`、VA `[0x4ADD50,0x4ADD8C)`，60 bytes，slice SHA256 `bf7ece055957f47071aa496a0dd3853bc98f9c5e7461496548101c1a81422eef`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
004add50 <.data+0xad150>:
  4add50:	53                   	push   ebx
  4add51:	56                   	push   esi
  4add52:	8d 50 08             	lea    edx,[eax+0x8]
  4add55:	be d5 0b 00 00       	mov    esi,0xbd5
  4add5a:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4add5f:	90                   	nop
  4add60:	c7 42 fc 40 7d 4b 00 	mov    DWORD PTR [edx-0x4],0x4b7d40
  4add67:	89 0a                	mov    DWORD PTR [edx],ecx
  4add69:	83 c2 08             	add    edx,0x8
  4add6c:	4e                   	dec    esi
  4add6d:	75 f1                	jne    0x4add60
  4add6f:	ba 80 fb 4a 00       	mov    edx,0x4afb80
  4add74:	c7 40 34 30 7d 4b 00 	mov    DWORD PTR [eax+0x34],0x4b7d30
  4add7b:	89 48 38             	mov    DWORD PTR [eax+0x38],ecx
  4add7e:	c7 40 3c d0 e4 4a 00 	mov    DWORD PTR [eax+0x3c],0x4ae4d0
  4add85:	89 48 40             	mov    DWORD PTR [eax+0x40],ecx
  4add88:	c7 80 f4 09    	mov    DWORD PTR [eax+0x9f4],0x4aedb0
  4add8f:
```

### A10. second 0x36 handler table registration

Entry `[EAX+0x26C]=0x4B3510`, separate handler table slot.

證據：KR 原生 BIN `.text` raw `[0xAD34D,0xAD3AD)`、VA `[0x4ADF4D,0x4ADFAD)`，96 bytes，slice SHA256 `8b232829b9a2ec61624e15a60213d37e90414ba9720382cfd4f9ca0fd15b2a97`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
004adf4d <.data+0xad34d>:
  4adf4d:	c7 80 0c 02 00 00 10 	mov    DWORD PTR [eax+0x20c],0x4b2310
  4adf54:	23 4b 00 
  4adf57:	89 88 10 02 00 00    	mov    DWORD PTR [eax+0x210],ecx
  4adf5d:	c7 80 fc 03 00 00 c0 	mov    DWORD PTR [eax+0x3fc],0x4b23c0
  4adf64:	23 4b 00 
  4adf67:	89 88 00 04 00 00    	mov    DWORD PTR [eax+0x400],ecx
  4adf6d:	c7 80 4c 02 00 00 50 	mov    DWORD PTR [eax+0x24c],0x4b3350
  4adf74:	33 4b 00 
  4adf77:	89 88 50 02 00 00    	mov    DWORD PTR [eax+0x250],ecx
  4adf7d:	c7 80 5c 02 00 00 f0 	mov    DWORD PTR [eax+0x25c],0x4b34f0
  4adf84:	34 4b 00 
  4adf87:	89 88 60 02 00 00    	mov    DWORD PTR [eax+0x260],ecx
  4adf8d:	c7 80 6c 02 00 00 10 	mov    DWORD PTR [eax+0x26c],0x4b3510
  4adf94:	35 4b 00 
  4adf97:	89 88 70 02 00 00    	mov    DWORD PTR [eax+0x270],ecx
  4adf9d:	c7 80 74 02 00 00 70 	mov    DWORD PTR [eax+0x274],0x4b3570
  4adfa4:	35 4b 00 
  4adfa7:	89 88 78 02 00 00    	mov    DWORD PTR [eax+0x278],ecx
```

### A11. sender allocation and vptr/global assignment

Global `[0xFBA854]` and vptr `0xC51748` native assignment.

證據：KR 原生 BIN `.text` raw `[0x403AD7,0x403B19)`、VA `[0x8046D7,0x804719)`，66 bytes，slice SHA256 `05ea18d78f82206a829641213226ab33271d899298eec52eca5115411dca199c`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
008046d7 <.data+0x403ad7>:
  8046d7:	6a 5c                	push   0x5c
  8046d9:	e8 8a cb 08 00       	call   0x891268
  8046de:	8b f0                	mov    esi,eax
  8046e0:	83 c4 04             	add    esp,0x4
  8046e3:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  8046e6:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
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
  804717:	8b 35        	mov    esi,DWORD PTR ds:0xbd25a0
```

### A12. virtual+0x10 concrete `0x8069A0`

Map/find key0, Conn+0x10 pointer, payload ptr+len→8060D0; return values.

證據：KR 原生 BIN `.text` raw `[0x405DA0,0x405DF4)`、VA `[0x8069A0,0x8069F4)`，84 bytes，slice SHA256 `2eabc71734af1539f5a206bc30304d23178412fba8a43f67966705a004675c8a`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
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
  8069f3:	c2               	ret    0xc
```

### A13. Conn::enqueue from actual app bytes

Queue capacity 0x12c, allocation, <=0x1000 copy, 806060 enqueue.

證據：KR 原生 BIN `.text` raw `[0x4054D0,0x405591)`、VA `[0x8060D0,0x806191)`，193 bytes，slice SHA256 `b8a91d2db14f1edac4a7b379250ed8a006d4e5518958e978678a71f079df4509`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
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
  80618a:	5b                   	pop    ebx
  80618b:	8b e5                	mov    esp,ebp
  80618d:	5d                   	pop    ebp
  80618e:	c2 08 00             	ret    0x8
```

### A14. Conn::critical-section queue insert

Linked queue +0xA074, count +0xA078, flag +0xA024.

證據：KR 原生 BIN `.text` raw `[0x405460,0x4054CC)`、VA `[0x806060,0x8060CC)`，108 bytes，slice SHA256 `00daec472f276163c3b79ec9d9d3d79d707775b6749aa7f9099d116048e7aca0`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
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
  8060cb:	c2               	ret    0x4
```

### A15. Connection 0x8061A0 queue drain and mode choice

Choice of 0x807830 or 0x807A70 and queue iteration.

證據：KR 原生 BIN `.text` raw `[0x4055A0,0x40567C)`、VA `[0x8061A0,0x80627C)`，220 bytes，slice SHA256 `efc14964a027e1533b3b5705ea982c71c8036f1a700ccb7ee907e4bb73b74b3e`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
008061a0 <.data+0x4055a0>:
  8061a0:	55                   	push   ebp
  8061a1:	8b ec                	mov    ebp,esp
  8061a3:	6a ff                	push   0xffffffff
  8061a5:	68 2e 99 90 00       	push   0x90992e
  8061aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8061b0:	50                   	push   eax
  8061b1:	83 ec 24             	sub    esp,0x24
  8061b4:	53                   	push   ebx
  8061b5:	56                   	push   esi
  8061b6:	57                   	push   edi
  8061b7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8061bc:	33 c5                	xor    eax,ebp
  8061be:	50                   	push   eax
  8061bf:	8d 45 f4             	lea    eax,[ebp-0xc]
  8061c2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8061c8:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8061cb:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  8061d1:	50                   	push   eax
  8061d2:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x1
  8061d9:	c7 45 e8 00 00 00 00 	mov    DWORD PTR [ebp-0x18],0x0
  8061e0:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8061e6:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  8061ec:	8b 18                	mov    ebx,DWORD PTR [eax]
  8061ee:	3b d8                	cmp    ebx,eax
  8061f0:	0f 84 c4 01 00 00    	je     0x8063ba
  8061f6:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  8061f9:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  8061fc:	8d 47 08             	lea    eax,[edi+0x8]
  8061ff:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806202:	0f be 86 2c a0 00 00 	movsx  eax,BYTE PTR [esi+0xa02c]
  806209:	83 e8 00             	sub    eax,0x0
  80620c:	8d 8e 1c 50 00 00    	lea    ecx,[esi+0x501c]
  806212:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  806215:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  806218:	74 15                	je     0x80622f
  80621a:	48                   	dec    eax
  80621b:	74 01                	je     0x80621e
  80621d:	48                   	dec    eax
  80621e:	52                   	push   edx
  80621f:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  806222:	52                   	push   edx
  806223:	e8 08 16 00 00       	call   0x807830
  806228:	85 c0                	test   eax,eax
  80622a:	75 23                	jne    0x80624f
  80622c:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  80622f:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806232:	52                   	push   edx
  806233:	50                   	push   eax
  806234:	8d be 1c 50 00 00    	lea    edi,[esi+0x501c]
  80623a:	e8 31 18 00 00       	call   0x807a70
  80623f:	85 c0                	test   eax,eax
  806241:	0f 95 c0             	setne  al
  806244:	84 c0                	test   al,al
  806246:	0f 84 58 01 00 00    	je     0x8063a4
  80624c:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  80624f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806251:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  806254:	3b 9e 74 a0 00 00    	cmp    ebx,DWORD PTR [esi+0xa074]
  80625a:	74 1f                	je     0x80627b
  80625c:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  80625f:	89 08                	mov    DWORD PTR [eax],ecx
  806261:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806263:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  806266:	53                   	push   ebx
  806267:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  80626a:	e8 9d af 08 00       	call   0x89120c
  80626f:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806272:	83 c4 04             	add    esp,0x4
  806275:	ff 8e 78 a0 00 00    	dec    DWORD PTR [esi+0xa078]
  80627b:	f6       	test   BYTE PTR ds:0xfe3354,0x1
```

### A16. Queue consumer followed by post-send state

Queue removal, producer-consumer bounded conditions, special state.

證據：KR 原生 BIN `.text` raw `[0x40567B,0x4057D0)`、VA `[0x80627B,0x8063D0)`，341 bytes，slice SHA256 `220ab878e89931b943f4d6f57359f11bba06e9bb36373a96422084d5e226aed6`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
0080627b <.data+0x40567b>:
  80627b:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  806282:	8b d9                	mov    ebx,ecx
  806284:	75 27                	jne    0x8062ad
  806286:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  80628d:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806294:	e8 87 0e 00 00       	call   0x807120
  806299:	68 90 0b bd 00       	push   0xbd0b90
  80629e:	e8 77 c0 08 00       	call   0x89231a
  8062a3:	83 c4 04             	add    esp,0x4
  8062a6:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  8062ad:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  8062b2:	50                   	push   eax
  8062b3:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8062b9:	c7 07 00 00 00 00    	mov    DWORD PTR [edi],0x0
  8062bf:	c7 47 04 00 00 00 00 	mov    DWORD PTR [edi+0x4],0x0
  8062c6:	a1 74 33 fe 00       	mov    eax,ds:0xfe3374
  8062cb:	8b 0d 70 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3370
  8062d1:	03 c8                	add    ecx,eax
  8062d3:	f6 c1 03             	test   cl,0x3
  8062d6:	75 18                	jne    0x8062f0
  8062d8:	83 c0 04             	add    eax,0x4
  8062db:	c1 e8 02             	shr    eax,0x2
  8062de:	39 05 6c 33 fe 00    	cmp    DWORD PTR ds:0xfe336c,eax
  8062e4:	77 0a                	ja     0x8062f0
  8062e6:	68 64 33 fe 00       	push   0xfe3364
  8062eb:	e8 80 0c e3 ff       	call   0x636f70
  8062f0:	8b 3d 70 33 fe 00    	mov    edi,DWORD PTR ds:0xfe3370
  8062f6:	03 3d 74 33 fe 00    	add    edi,DWORD PTR ds:0xfe3374
  8062fc:	a1 6c 33 fe 00       	mov    eax,ds:0xfe336c
  806301:	8b f7                	mov    esi,edi
  806303:	c1 ee 02             	shr    esi,0x2
  806306:	3b c6                	cmp    eax,esi
  806308:	77 02                	ja     0x80630c
  80630a:	2b f0                	sub    esi,eax
  80630c:	8b 0d 68 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3368
  806312:	83 3c b1 00          	cmp    DWORD PTR [ecx+esi*4],0x0
  806316:	75 17                	jne    0x80632f
  806318:	6a 10                	push   0x10
  80631a:	e8 49 af 08 00       	call   0x891268
  80631f:	83 c4 04             	add    esp,0x4
  806322:	85 c0                	test   eax,eax
  806324:	74 56                	je     0x80637c
  806326:	8b 15 68 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3368
  80632c:	89 04 b2             	mov    DWORD PTR [edx+esi*4],eax
  80632f:	a1 68 33 fe 00       	mov    eax,ds:0xfe3368
  806334:	8b 0c b0             	mov    ecx,DWORD PTR [eax+esi*4]
  806337:	83 e7 03             	and    edi,0x3
  80633a:	8d 04 b9             	lea    eax,[ecx+edi*4]
  80633d:	85 c0                	test   eax,eax
  80633f:	74 05                	je     0x806346
  806341:	8b 55 ec             	mov    edx,DWORD PTR [ebp-0x14]
  806344:	89 10                	mov    DWORD PTR [eax],edx
  806346:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  80634b:	be 01 00 00 00       	mov    esi,0x1
  806350:	01 35 74 33 fe 00    	add    DWORD PTR ds:0xfe3374,esi
  806356:	29 35 7c 33 fe 00    	sub    DWORD PTR ds:0xfe337c,esi
  80635c:	50                   	push   eax
  80635d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  806363:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  806366:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806369:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  80636c:	8b f2                	mov    esi,edx
  80636e:	3b 8a 74 a0 00 00    	cmp    ecx,DWORD PTR [edx+0xa074]
  806374:	0f 85 7c fe ff ff    	jne    0x8061f6
  80637a:	eb 3e                	jmp    0x8063ba
  80637c:	8d 45 dc             	lea    eax,[ebp-0x24]
  80637f:	50                   	push   eax
  806380:	8d 4d d0             	lea    ecx,[ebp-0x30]
  806383:	c7 45 dc 00 00 00 00 	mov    DWORD PTR [ebp-0x24],0x0
  80638a:	e8 1a ad 08 00       	call   0x8910a9
  80638f:	68 a8 57 c8 00       	push   0xc857a8
  806394:	8d 4d d0             	lea    ecx,[ebp-0x30]
  806397:	51                   	push   ecx
  806398:	c7 45 d0 a4 2c bd 00 	mov    DWORD PTR [ebp-0x30],0xbd2ca4
  80639f:	e8 4c 66 09 00       	call   0x89c9f0
  8063a4:	83 be b4 a0 00 00 01 	cmp    DWORD PTR [esi+0xa0b4],0x1
  8063ab:	75 0d                	jne    0x8063ba
  8063ad:	83 7d e8 00          	cmp    DWORD PTR [ebp-0x18],0x0
  8063b1:	75 07                	jne    0x8063ba
  8063b3:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  8063ba:	8b 96 d4 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0d4]
  8063c0:	52                   	push   edx
  8063c1:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8063c7:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  8063ca:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  8063cd:	64 89 0d     	mov    DWORD PTR fs:0x0,ecx
```

### A17. Ordinary 4-byte framing `0x807A70`

Header len+4; constant 0x1A68; bounded connection buffer.

證據：KR 原生 BIN `.text` raw `[0x406E70,0x406F3C)`、VA `[0x807A70,0x807B3C)`，204 bytes，slice SHA256 `d6935ccf72a4093ab49150ab31cf2fb0c74f8822da47c5658e4b9eb5ce2667ca`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
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
  807b19:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  807b1c:	52                   	push   edx
  807b1d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b23:	5e                   	pop    esi
  807b24:	33 c0                	xor    eax,eax
  807b26:	5b                   	pop    ebx
  807b27:	8b e5                	mov    esp,ebp
  807b29:	5d                   	pop    ebp
  807b2a:	c2 08 00             	ret    0x8
  807b2d:	56                   	push   esi
  807b2e:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b34:	5e                   	pop    esi
  807b35:	33 c0                	xor    eax,eax
  807b37:	5b                   	pop    ebx
  807b38:	8b e5                	mov    esp,ebp
  807b3a:	5d                   	pop    ebp
  807b3b:	c2               	ret    0x8
```

### A18. Alternate 6-byte framing `0x807830`

Header len+6, payload xor, constraints; only selected branch.

證據：KR 原生 BIN `.text` raw `[0x406C30,0x406D3B)`、VA `[0x807830,0x80793B)`，267 bytes，slice SHA256 `6e198ee33386b50d116efd1837fc4c3402ac4150e68189ae5b2a24e98bb49aeb`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
00807830 <.data+0x406c30>:
  807830:	55                   	push   ebp
  807831:	8b ec                	mov    ebp,esp
  807833:	b8 38 10 00 00       	mov    eax,0x1038
  807838:	e8 33 8e 0a 00       	call   0x8b0670
  80783d:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  807842:	33 c5                	xor    eax,ebp
  807844:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  807847:	53                   	push   ebx
  807848:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  80784b:	56                   	push   esi
  80784c:	8b f1                	mov    esi,ecx
  80784e:	8b 06                	mov    eax,DWORD PTR [esi]
  807850:	57                   	push   edi
  807851:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  807854:	50                   	push   eax
  807855:	89 b5 cc ef ff ff    	mov    DWORD PTR [ebp-0x1034],esi
  80785b:	89 9d d4 ef ff ff    	mov    DWORD PTR [ebp-0x102c],ebx
  807861:	89 85 f0 ef ff ff    	mov    DWORD PTR [ebp-0x1010],eax
  807867:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80786d:	8d 47 06             	lea    eax,[edi+0x6]
  807870:	c7 85 e6 ef ff ff bb 	mov    DWORD PTR [ebp-0x101a],0x7d810bbb
  807877:	0b 81 7d 
  80787a:	66 89 bd e4 ef ff ff 	mov    WORD PTR [ebp-0x101c],di
  807881:	89 85 d8 ef ff ff    	mov    DWORD PTR [ebp-0x1028],eax
  807887:	3d 00 10 00 00       	cmp    eax,0x1000
  80788c:	0f 87 bb 01 00 00    	ja     0x807a4d
  807892:	85 ff                	test   edi,edi
  807894:	0f 84 b3 01 00 00    	je     0x807a4d
  80789a:	8b 96 0c 50 00 00    	mov    edx,DWORD PTR [esi+0x500c]
  8078a0:	03 d0                	add    edx,eax
  8078a2:	81 fa 00 40 00 00    	cmp    edx,0x4000
  8078a8:	76 0c                	jbe    0x8078b6
  8078aa:	8b 85 f0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1010]
  8078b0:	50                   	push   eax
  8078b1:	e9 9e 01 00 00       	jmp    0x807a54
  8078b6:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  8078bc:	8d 96 04 50 00 00    	lea    edx,[esi+0x5004]
  8078c2:	03 c1                	add    eax,ecx
  8078c4:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  8078ca:	8d 46 04             	lea    eax,[esi+0x4]
  8078cd:	89 8d dc ef ff ff    	mov    DWORD PTR [ebp-0x1024],ecx
  8078d3:	3b c8                	cmp    ecx,eax
  8078d5:	72 d3                	jb     0x8078aa
  8078d7:	3b ca                	cmp    ecx,edx
  8078d9:	73 cf                	jae    0x8078aa
  8078db:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8078e1:	3b d0                	cmp    edx,eax
  8078e3:	72 c5                	jb     0x8078aa
  8078e5:	8d 86 04 50 00 00    	lea    eax,[esi+0x5004]
  8078eb:	3b d0                	cmp    edx,eax
  8078ed:	73 bb                	jae    0x8078aa
  8078ef:	33 c0                	xor    eax,eax
  8078f1:	89 85 ec ef ff ff    	mov    DWORD PTR [ebp-0x1014],eax
  8078f7:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  8078fd:	8a 03                	mov    al,BYTE PTR [ebx]
  8078ff:	8a d0                	mov    dl,al
  807901:	80 f2 b6             	xor    dl,0xb6
  807904:	88 95 fc ef ff ff    	mov    BYTE PTR [ebp-0x1004],dl
  80790a:	0f b6 d0             	movzx  edx,al
  80790d:	b8 01 00 00 00       	mov    eax,0x1
  807912:	89 95 f8 ef ff ff    	mov    DWORD PTR [ebp-0x1008],edx
  807918:	3b f8                	cmp    edi,eax
  80791a:	0f 86 c9 00 00 00    	jbe    0x8079e9
  807920:	8d 57 ff             	lea    edx,[edi-0x1]
  807923:	83 fa 02             	cmp    edx,0x2
  807926:	0f 8c 8d 00 00 00    	jl     0x8079b9
  80792c:	8d 8d fd ef ff ff    	lea    ecx,[ebp-0x1003]
  807932:	83 c7 fd             	add    edi,0xfffffffd
  807935:	8b d3                	mov    edx,ebx
  807937:	2b d1                	sub    edx,ecx
  807939:	8d b5        	lea    esi,[ebp-0x1004]
```

### A19. Alternate mode write stage/checksum

XOR passes, integrity accumulations and payload copy.

證據：KR 原生 BIN `.text` raw `[0x406D3B,0x406E4E)`、VA `[0x80793B,0x807A4E)`，275 bytes，slice SHA256 `05bf7307a2cb1d85bc64567f459448a06184d6c4bc7ce5ddfb123b2724227406`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
0080793b <.data+0x406d3b>:
  80793b:	fc                   	cld
  80793c:	ef                   	out    dx,eax
  80793d:	ff                   	(bad)
  80793e:	ff 2b                	jmp    FWORD PTR [ebx]
  807940:	cb                   	retf
  807941:	2b f3                	sub    esi,ebx
  807943:	d1 ef                	shr    edi,1
  807945:	47                   	inc    edi
  807946:	89 8d d0 ef ff ff    	mov    DWORD PTR [ebp-0x1030],ecx
  80794c:	8d 4c 3f 01          	lea    ecx,[edi+edi*1+0x1]
  807950:	8d 43 01             	lea    eax,[ebx+0x1]
  807953:	89 b5 c8 ef ff ff    	mov    DWORD PTR [ebp-0x1038],esi
  807959:	89 8d e0 ef ff ff    	mov    DWORD PTR [ebp-0x1020],ecx
  80795f:	eb 06                	jmp    0x807967
  807961:	8b b5 c8 ef ff ff    	mov    esi,DWORD PTR [ebp-0x1038]
  807967:	8a 08                	mov    cl,BYTE PTR [eax]
  807969:	03 f0                	add    esi,eax
  80796b:	0f b6 1c 16          	movzx  ebx,BYTE PTR [esi+edx*1]
  80796f:	32 d9                	xor    bl,cl
  807971:	0f b6 c9             	movzx  ecx,cl
  807974:	66 01 8d ec ef ff ff 	add    WORD PTR [ebp-0x1014],cx
  80797b:	8a 48 01             	mov    cl,BYTE PTR [eax+0x1]
  80797e:	88 1e                	mov    BYTE PTR [esi],bl
  807980:	0f b6 18             	movzx  ebx,BYTE PTR [eax]
  807983:	8b b5 d0 ef ff ff    	mov    esi,DWORD PTR [ebp-0x1030]
  807989:	32 d9                	xor    bl,cl
  80798b:	0f b6 c9             	movzx  ecx,cl
  80798e:	66 01 8d f4 ef ff ff 	add    WORD PTR [ebp-0x100c],cx
  807995:	88 1c 06             	mov    BYTE PTR [esi+eax*1],bl
  807998:	83 c0 02             	add    eax,0x2
  80799b:	4f                   	dec    edi
  80799c:	75 c3                	jne    0x807961
  80799e:	8b 85 e0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1020]
  8079a4:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8079a7:	8b b5 cc ef ff ff    	mov    esi,DWORD PTR [ebp-0x1034]
  8079ad:	8b 9d d4 ef ff ff    	mov    ebx,DWORD PTR [ebp-0x102c]
  8079b3:	8b 8d dc ef ff ff    	mov    ecx,DWORD PTR [ebp-0x1024]
  8079b9:	3b c7                	cmp    eax,edi
  8079bb:	73 1a                	jae    0x8079d7
  8079bd:	8a 14 03             	mov    dl,BYTE PTR [ebx+eax*1]
  8079c0:	8a 5c 03 ff          	mov    bl,BYTE PTR [ebx+eax*1-0x1]
  8079c4:	32 da                	xor    bl,dl
  8079c6:	0f b6 d2             	movzx  edx,dl
  8079c9:	66 01 95 f8 ef ff ff 	add    WORD PTR [ebp-0x1008],dx
  8079d0:	88 9c 05 fc ef ff ff 	mov    BYTE PTR [ebp+eax*1-0x1004],bl
  8079d7:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8079dd:	03 95 ec ef ff ff    	add    edx,DWORD PTR [ebp-0x1014]
  8079e3:	01 95 f8 ef ff ff    	add    DWORD PTR [ebp-0x1008],edx
  8079e9:	8b 95 e4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x101c]
  8079ef:	66 8b 85 f8 ef ff ff 	mov    ax,WORD PTR [ebp-0x1008]
  8079f6:	89 11                	mov    DWORD PTR [ecx],edx
  8079f8:	66 89 41 04          	mov    WORD PTR [ecx+0x4],ax
  8079fc:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  807a02:	57                   	push   edi
  807a03:	8d 85 fc ef ff ff    	lea    eax,[ebp-0x1004]
  807a09:	50                   	push   eax
  807a0a:	83 c1 06             	add    ecx,0x6
  807a0d:	51                   	push   ecx
  807a0e:	e8 bd 61 09 00       	call   0x89dbd0
  807a13:	8b 85 d8 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1028]
  807a19:	8b 95 f0 ef ff ff    	mov    edx,DWORD PTR [ebp-0x1010]
  807a1f:	01 86 0c 50 00 00    	add    DWORD PTR [esi+0x500c],eax
  807a25:	01 86 04 50 00 00    	add    DWORD PTR [esi+0x5004],eax
  807a2b:	83 c4 0c             	add    esp,0xc
  807a2e:	52                   	push   edx
  807a2f:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807a35:	5f                   	pop    edi
  807a36:	5e                   	pop    esi
  807a37:	b8 01 00 00 00       	mov    eax,0x1
  807a3c:	5b                   	pop    ebx
  807a3d:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807a40:	33 cd                	xor    ecx,ebp
  807a42:	e8 ba 95 08 00       	call   0x891001
  807a47:	8b e5                	mov    esp,ebp
  807a49:	5d                   	pop    ebp
  807a4a:	c2 08 00             	ret    0x8
  807a4d:	8b         	mov    ecx,DWORD PTR [ebp-0x1010]
```

### A20. WSASend vtable+0x0C actual body

WSASend import, IOCP pending/error boundary—not direct app producer.

證據：KR 原生 BIN `.text` raw `[0x405CB0,0x405DA0)`、VA `[0x8068B0,0x8069A0)`，240 bytes，slice SHA256 `c26a1056da819945466e548176a1819382273a8abdc0f5599a9dd31728f59eec`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
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
  806995:	83 c8 ff             	or     eax,0xffffffff
  806998:	5b                   	pop    ebx
  806999:	5d                   	pop    ebp
  80699a:	c2 10 00             	ret    0x10
  80699d:	cc                   	int3
  80699e:	cc                   	int3
  80699f:	cc                   	int3
```

### A21. queue consumer scheduled by connection loop 1

Consumer invoked if Conn+0xA0AC is enabled; periodic producer not directly synchronous.

證據：KR 原生 BIN `.text` raw `[0x403EC0,0x403F20)`、VA `[0x804AC0,0x804B20)`，96 bytes，slice SHA256 `8eaa8c356c4c7268835616491e5c63e577742cabf6f04d6b9af169dcfc2297e0`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
00804ac0 <.data+0x403ec0>:
  804ac0:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804ac3:	8b 16                	mov    edx,DWORD PTR [esi]
  804ac5:	8b 34 82             	mov    esi,DWORD PTR [edx+eax*4]
  804ac8:	83 be ac a0 00 00 00 	cmp    DWORD PTR [esi+0xa0ac],0x0
  804acf:	0f 84 76 01 00 00    	je     0x804c4b
  804ad5:	56                   	push   esi
  804ad6:	e8 c5 16 00 00       	call   0x8061a0
  804adb:	85 c0                	test   eax,eax
  804add:	74 28                	je     0x804b07
  804adf:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  804ae5:	01 9e 94 a0 00 00    	add    DWORD PTR [esi+0xa094],ebx
  804aeb:	83 f8 05             	cmp    eax,0x5
  804aee:	73 0c                	jae    0x804afc
  804af0:	c7 86 a4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0a4],0x0
  804af7:	00 00 00 
  804afa:	eb 1e                	jmp    0x804b1a
  804afc:	83 c0 fb             	add    eax,0xfffffffb
  804aff:	89 86 a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],eax
  804b05:	eb 13                	jmp    0x804b1a
  804b07:	83 7d fc 00          	cmp    DWORD PTR [ebp-0x4],0x0
  804b0b:	74 0d                	je     0x804b1a
  804b0d:	01 9e 84 a0 00 00    	add    DWORD PTR [esi+0xa084],ebx
  804b13:	83 86 a4 a0 00 00 05 	add    DWORD PTR [esi+0xa0a4],0x5
  804b1a:	c7 45 ec 00 00 00  	mov    DWORD PTR [ebp-0x14],0x0
```

### A22. queue consumer scheduled by connection loop 2

Second invocation from connection loop, condition `Conn+0xA0AC`.

證據：KR 原生 BIN `.text` raw `[0x404610,0x404670)`、VA `[0x805210,0x805270)`，96 bytes，slice SHA256 `49bb5b3f42f2082b2da8d4913ca590180e4ad6c84bd2fa4f07e0a298e8d726d6`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
00805210 <.data+0x404610>:
  805210:	eb 03                	jmp    0x805215
  805212:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  805215:	8b 09                	mov    ecx,DWORD PTR [ecx]
  805217:	8b 34 b9             	mov    esi,DWORD PTR [ecx+edi*4]
  80521a:	83 be ac a0 00 00 00 	cmp    DWORD PTR [esi+0xa0ac],0x0
  805221:	0f 84 85 01 00 00    	je     0x8053ac
  805227:	56                   	push   esi
  805228:	e8 73 0f 00 00       	call   0x8061a0
  80522d:	85 c0                	test   eax,eax
  80522f:	74 28                	je     0x805259
  805231:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  805237:	ff 86 94 a0 00 00    	inc    DWORD PTR [esi+0xa094]
  80523d:	83 f8 05             	cmp    eax,0x5
  805240:	73 0c                	jae    0x80524e
  805242:	c7 86 a4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0a4],0x0
  805249:	00 00 00 
  80524c:	eb 1e                	jmp    0x80526c
  80524e:	83 c0 fb             	add    eax,0xfffffffb
  805251:	89 86 a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],eax
  805257:	eb 13                	jmp    0x80526c
  805259:	80 7b 10 00          	cmp    BYTE PTR [ebx+0x10],0x0
  80525d:	74 0d                	je     0x80526c
  80525f:	ff 86 84 a0 00 00    	inc    DWORD PTR [esi+0xa084]
  805265:	83 86 a4 a0 00 00 05 	add    DWORD PTR [esi+0xa0a4],0x5
  80526c:	c7 45 f4 00    	mov    DWORD PTR [ebp-0xc],0x0
```

### A23. Quest16 mode2 original UI invocation

T16-121 evidence re-read, event action F438B, 0x636520 arg mode2.

證據：KR 原生 BIN `.text` raw `[0x1B6120,0x1B6230)`、VA `[0x5B6D20,0x5B6E30)`，272 bytes，slice SHA256 `008d5218ad9ccb17a25063c6284e9fa5a9d2ad185812c66c4a8a9dd4c5dcbd06`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
005b6d20 <.data+0x1b6120>:
  5b6d20:	55                   	push   ebp
  5b6d21:	8b ec                	mov    ebp,esp
  5b6d23:	83 e4 f8             	and    esp,0xfffffff8
  5b6d26:	6a ff                	push   0xffffffff
  5b6d28:	68 2c 93 94 00       	push   0x94932c
  5b6d2d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b6d33:	50                   	push   eax
  5b6d34:	83 ec 10             	sub    esp,0x10
  5b6d37:	53                   	push   ebx
  5b6d38:	56                   	push   esi
  5b6d39:	57                   	push   edi
  5b6d3a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b6d3f:	33 c4                	xor    eax,esp
  5b6d41:	50                   	push   eax
  5b6d42:	8d 44 24 20          	lea    eax,[esp+0x20]
  5b6d46:	64 a3 00 00 00 00    	mov    fs:0x0,eax
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
```

### A24. TalkBox mode setup and QuestTalk pointer

QuestID vs giver vs mode vs QuestTalk; supports negative 0x36 claim.

證據：KR 原生 BIN `.text` raw `[0x235920,0x235B0E)`、VA `[0x636520,0x63670E)`，494 bytes，slice SHA256 `59e46e4d1324bd565c33307bcd274aa908fe8cfa1e0aa848e8e820c6ede8b935`。`objdump` 範圍以函式入口或已知指令邊界起始，跨邊界切片末尾須以後續相鄰切片核對。

```asm
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
  63670c:	c7 44      	mov    DWORD PTR [esp+0x40],0x1
  636713:
```

## 12. Vtable raw byte verification (not disassembly)

Raw 0x84FD48…0x84FD68; SHA256 `f3d64021ce790d865813ee57e7974ed6ef29f5bc69abe170ab0ffed4431fd37d`; original little-endian:

```text
70 66 80 00 f0 6c 80 00 50 68 80 00 b0 68 80 00 a0 69 80 00 00 6a 80 00 d0 6a 80 00 60 6f 80 00
vtable+0x00: 0x00806670
vtable+0x04: 0x00806CF0
vtable+0x08: 0x00806850
vtable+0x0C: 0x008068B0
vtable+0x10: 0x008069A0
vtable+0x14: 0x00806A00
vtable+0x18: 0x00806AD0
vtable+0x1C: 0x00806F60
```

This direct data read establishes the four application producer virtual dispatch to 0x8069A0 without guessing a C++ name. The 0x8068B0 network wrapper is a **different slot**.

## 13. Evidence discipline and final conclusion

**Quest16-③ is completed only as a bounded KR Client static analysis of C→S application packet producers and their enqueue/framing branch.** It is **not** a T01 FULL-PASS, not Server policy recovery, not a claim of actual accepted Quest16, and not a run-time packet trace. Any future new producer/handler discovered should extend/errata this manuscript rather than falsely rewrite this bounded result.

- [BIN] `0x1C` actor-word event packet; producer independent of quest ID.
- [BIN] `0x3F` controller packet can carry QID16, but it is stage/connection gated, may be delayed, and branch-specific second field may change.
- [BIN] `0x36` has at least two distinct original producers, neither proven to be a Quest16 mode2 click action; `TalkBox+0x88` points to QuestTalk, **not automatically QuestID16**.
- [BIN] `sender vtable+0x10 = 0x8069A0`, map to Conn, enqueue 0x8060D0→0x806060, drain 0x8061A0, mode-specific framing 0x807A70/0x807830; WSASend wrapper 0x8068B0 at different slot.
- [UNKNOWN] Official Server correlation/ACK, playability, per-account quest persistent state, complete opcode namespace of second 0x36 handler; separate T02/Quest16-④ work.

At manuscript generation time this local file has **no Git commit and no Git blob SHA**. After pushing, commit/blob identity must be independently read back from `t16/roy/chatgpt-web`; no claims of GitHub success are embedded into an unverified local draft.

