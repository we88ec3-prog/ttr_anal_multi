# T16-127 — Quest15／③：NPC10338 C→S 0x1C／controller 0x3F／0x36 非等價路徑、sender/queue 與失敗分支（KR，BIN-first）

- 建檔：`2026-10-30T14:18:01+08:00`；任務 **T16-127**；繼承 T16-126（Quest15-②），對話研究者 `chatgpt-web roy`。
- 研究原件：KR `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Event.stp` 11,241,597 bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；唯讀。BIN 是分析證據，不是私有 Server 實作，也未啟動或 patch 程式。
- PE image base 0x400000，`.text` 0x401000 raw 0x400，所有本稿 `.text` VA 對應 `raw = VA - 0x400C00`；`.rdata` VA0xBD2000 raw0x7D0600。原件 slice SHA256 與 objdump 指令對應；來源 32-bit x86，採記憶體 little-endian。
- GitHub 新工作開始核對：`main` = `edbf681af76909abbdcb82d6ba223bfbc27b3619`，T16 工作分支較 main `ahead=1, behind=47`（檢查瞬間）；依本**同一對話**規定不得重做 main→T16 Merge。本檔預備獲明確指令上傳至 `t16/roy/chatgpt-web`，不得合回 main。
- 最新 `main`：`research/dispatch/inbox/T16.md` 無 S00 RR，台帳 `research/requests/index.json` 無 owner T16；T01 `kr/tasks/T16/README.md` 退回 `T01-RETURN-T16-117-Q16-MODE2-C2S36-001` 仍 **NEEDS_FIX**。該退回指出 T16-117 mode1～3 對 0x36 的泛化錯誤，已由 T16-121／122 提供原生反證；**正式針對117的 erratum 仍應獨立提交，不能假裝此處已解 T01 退回。** 此輪按使用者指示先完成 Quest15-③。
- 共用 FULL-PASS 索引已查；未將任何本稿新主張冒升 `NATIVE_VERIFIED`、`T01 FULL-PASS`、S00 `STABLE`、原版 Server 完成或遊玩驗證。

## A. Quest15-③ 的可驗收問題與結論

研究終點是**原生 Client 條件式**的 NPC10338 玩家互動 → application packet producers → sender gate / vtable / queue，及 UI mode2 不發 `0x36` 的反證。不以原版 Server 回覆配對、實際連網或 Quest15 完成演算法為前提；那是 S00/T02／Quest15-④／Server 開發與 runtime 調查的獨立問題。

| 問題 | 可證的 native 結果 | 尚未證實／不能等同 |
|---|---|---|
| 角色種類、NPC ID 從何而來 | `0x4B2BD5` 傳來源記錄欄位給 `0x543700`；ctor 寫 `+0xF4` kind、`+0xF6` ID | Lua Scene1/2 `CreateObject(10338)` 是否必經此 ctor／玩家實際點擊時序 |
| 哪個玩家互動事件生產者 | `0x544070` 在 kind=3、狀態／模式判斷後，可由 `0x5442CC` 建立 type 0x105BF、action F43D9 的物件；`+0x14` ID、`+0x18` kind、`+0x1C` ID | 並非任意 kind=3 點擊皆走到 F43D9；原件中的事件包裝與傳遞順序仍有外層 gate |
| 如何選到 Quest15 | `0x5B7F80` action F43D9 dispatch → `0x5B8167` → `0x5B9340` 檢驗 outer type105BD /action6A7，nested type105BF → `0x5008B0` 首個符合的 type2+giver；若 Q15 是第一個符合項，可得到 WORD15 | 不能把 inner F43D9 直接當 outer 6A7，或保證所有資料時機必選 Q15 |
| NPC 的 C2S 0x1C | `0x5B9453..0x5B9485` 將巢狀事件 `+0x18/+0x1C` 兩個 WORD 寫入 `0x1C` application buffer；sender gate `[0xFBA798]==0` 才調用 virtual+0x10 | `0x1C` 不帶選出的 QuestID15；非每次點擊必然 send 成功 |
| `0x1C` 對 NPC10338 的可判示例 | 若 wrapper 保留 ctor 事件 kind3、id10338 → `1C 00 03 00 62 28`（10338=0x2862），每欄 LE16 | 包裝前後未做全 runtime trace；**條件式 payload，不是抓包實測** |
| controller 何時 0x3F | `0x5B9447` 以 `(candidateID,1)` 呼叫 `0x561760`；在 controller `+0x28==0` 時，保存 `+0x38=candidateID`、`+0x3C=1`、`+0x28=1`；之後 `0x561DB0` 的特定 mode/state/gate 導向 `0x4A39A0` 建 8B 0x3F | latch 不等於 enqueue；也不保證永久 retry；alternate branch 可能進 0x565720 scene lookup |
| `0x3F` 對 Q15 的可判示例 | 保持 `(15,1)` 並走 `0x561FB0`，sender gate=0 時 application bytes `3F 00 0F 00 01 00 01 00` | `+0x3C` 可被其他分支改寫；不能認為所有呼叫都帶 `(15,1)` |
| Quest15 mode2 是否直接建 0x36 | `0x636B70` `mode==1` 才建立 F4402；`0x636DE0` 僅在 action F4402 呼叫 `0x636E10`。mode2 不經這條 UI 構造支線；有獨立的 `0x4B3510` 0x36 producer | 不能宣稱「Quest15 永遠不發 0x36」；不能把其他 producer 的 0x36 改稱 mode2 accept |
| application 真正去哪裡 | `0xFBA854` vtable `0xC51748` +0x10=`0x8069A0` → 找連線 key0 → `0x8060D0` 複製到 buffer node → `0x806060` Conn+0xA074 queue/+0xA078 count | queue ACK 非 WSASend、非官方 Server 處理；final framing 與 WSASend 交 T02 |

### A.1 本次新增的兩個關鍵邊界

1. **事件內可攜帶 NPC kind/id，而非 QuestID**。`0x5442E5...0x54431C` 是先從 actor `+F4/+F6` 填到 local event `+18/+1C`；`0x5B945C/0x5B9464` 是從已收到的 nested event 這兩欄填 `0x1C` 封包。當來源、外層 105BD／6A7、nested 105BF 與資料未變時，可具體推得 kind3、10338 封包位元組。選出的 QuestID 是 `EDI`，不被用於此 `0x1C` 兩欄。
2. **pending flag 在 C2S 發送 gate 之前清除**：`0x561F69` 將 `controller+0x28=0`，其後 `0x561F9F` 才決定是否到 `0x561FA3..0x561FB0`。因此遇到後續 gate 失敗，不能宣稱 pending 一定保留並待下個 tick 重試；另一條 `+0x89 != 0` 走 controller／scene 相關路徑。這是原生必要反例，不能只列 0x3F happy path。

## B. Client 條件式鏈（不是 Server 時序保證）

```text
actor source record ID=10338/kind=3 [if confirmed at runtime]
  → 0x4B2BD5 → 0x543700 actor+F4(kind3),+F6(ID10338)
  → vtable+0x64 = 0x544070: kind 3, local mode/proximity/gates
  → 0x5442CC: 0x105BF F43D9 event {+14=10338,+18=3,+1C=10338}
  → local event framework / wrapper [outer0x105BD/action6A7 not automatically implied]
  → 0x5B7F80 F43D9 dispatch → 0x5B8167 → 0x5B9340
       ├ inner+14 → 0x5008B0(QuestOwner, giver=10338) → candidate Q15 [conditional]
       │              → 0x561760(QID15,1) sets pending flag +0x28 and latches +0x38/+0x3C
       │                   ├ later 0x561DB0(+0x89=0,pending=1,gate passes) → 0x4A39A0
       │                   │                                     3F 00 0F 00 01 00 01 00
       │                   ├ pending cleared; failed gate: 0x3F may not be sent
       │                   └ +0x89 nonzero / scene condition → 0x565720 (not 0x3F direct)
       └ inner+18/+1C → 5B9453 1C 00 03 00 62 28 [same fields preserved, sender gate=0]
                         → shared sender 0x8069A0→0x8060D0→0x806060(queue)

Separate inbound Client capability, not proven original request/response pair:
  S2C 0x40 (QuestID15,state0) → F438B → 0x5B6D20 → mode2 TalkBox
  mode1-only F4402 UI → 0x636E10 possible C2S 0x36 [NOT a direct mode2 result]
  independent handler 0x4B3510 also produces 0x36 [different input origin]
```

## C. 衝突與反證專區

- `0x500A80` 與 `0x5008B0` **不是同一個函式**：actor `0x544162` 的比較結果 `==5` 控制事件變體分支；nested giver type2 first-hit 是 `0x5B9407` 的 `0x5008B0`，再呼叫 `0x500A00` 做實際 candidate 過濾。actor 先判斷事件模式，不能將結果 5 改當 QuestID15。
- `0x5008B0` 是在當前候選 WORD vector 上尋首個符合 type2 和 giver 的任務，不是保證 Q15 排序第一；Quest15 還需 QuestOwner key16、town5、level、excluded list 等門檻。`0x74(16)` 是 Client 前置資料寫入，並不直接建 C2S。
- `0x5442CC` 內層事件 `{type=0x105BF, action=0xF43D9}` 和 `0x5B9340` 要求的 `{outer type=0x105BD, outer action=0x6A7, inner type=0x105BF}` 的**事件命名空間不同**；本次證實 local fields 的原生對應及 consumer，但實際 event framework wrapper 是否逐次保留並送達，仍受 runtime 與另一派送鏈 gate 影響。
- 0x1C 是 `1C 00 kind WORD id WORD`，QID15 只是同一 handler 的另一條資料流。即使 candidate=0，也必須先分析 controller、sender gate；不能把 `0x1C` 等同 QID15 accept。
- `0x561760` 有 `controller+0x28!=0` 的早退分支；也有 `arg1==0`、特殊 stage 的立即送 0x3F 分支，不能把它當 `0x561760(15,1)` 的必然行為。
- `0x561DB0` 先 clear `+0x28` 再檢查 deferred 0x3F gate，並可能變更 `controller+0x3C`，或走 `0x565720`；沒有持續重送保證。
- `0x636B70` 的 mode2 難以得到 mode1 `0xF4402` 事件，`0x636E10` 的 WORD 來自 `WORD*([TalkBox+0x88])`，不等於 `TalkBox+0x80` QuestID。T16-117 D.1/D.3 必須在正式 erratum 更正；不能聲稱所有 mode 都 0x36。
- `0x4B3510` 是第二個 0x36 producer，並有本地 handler table `0x4ADF8D` +0x26C 註冊；但該 8-byte stride table 的槽 index 不經實際 dispatcher 核對不可直接當網路 opcode。
- 三份 application payload 長度 **6/8/4 bytes**；`0x807A70`／`0x807830` 依 conn mode 做不同 frame 封裝，不能把 application 長度報成最終 wire frame，亦不能從 `0x8060D0` return1 推論網路成功。

## D. Controller／sender CFG、生命週期與具體測試矩陣

| Scenario | Native gate／source | 本地可觀測 Client 行為 | Server／runtime 邊界 |
|---|---|---|---|
| Q15 未列候選 | Demand16/region/level/排除不過 | 0x5008B0 可返回0；0x561760 可能仍接收 0 ID | NPC 0x1C 可與 QID 選擇獨立 |
| NPC10338 的 inner object 可達，outer wrapper 6A7 | 0x105BD → 0x105BF，nested+18=3,+1C=10338、sender gate0 | 0x1C application `1C 00 03 00 62 28` enqueue attempt | frame/TCP arrival 無保證 |
| sender gate非0 | 0x5B944C/0x4A39A6 | bytes 仍可建於 stack；不 virtual call | 不是 Server 拒收，甚至未入列 |
| controller pending已非0 | 0x5617C2 先檢查 +0x28 | `0x561760` 不覆寫同一筆 QID latch 而走另一條 message/debug path | 不推斷已送或重試 |
| Q15 latch `(15,1)`，normal controller後續 gate允許 | 0x561F79...+0x4A2B50==1，再 sender gate0 | 0x3F `3F 00 0F 00 01 00 01 00` enqueue attempt | 未證回覆 opcode0x40 |
| normal controller後續 gate不允許 | 0x561F69 clears +0x28, 0x561FA1 branch | **不送這個 deferred 0x3F**；pending flag 已清 | 不保證下一tick重送 |
| controller other subbranch arg1==0 | 0x561FB7 / 0x6BDE40 changes arg2 | 可能發 0x3F 但不帶 QID15 | 勿當 Q15 request |
| controller +0x89 非0 | 0x561DE0...、0x47E640/0x565720 | 場景相關 effect，可能不走 0x561FB0 | 與 T07 場景整合 |
| S2C 0x40(15,state0) | 過往 T16-121/124/126、原生對照 | mode2 TalkBox，可顯示 Q15 | 不認證 0x3F↔0x40 Server 配對 |
| mode1 UI event F4402 | `0x636B70` mode1 branch、`0x636DE0` handler | 有條件 producer 0x36 `[WORD*QuestTalk+0]` | 不能移用至 Quest15 mode2 |
| 另一輸入 handler 0x4B3510 | `input+2` WORD、sender gate0 | 0x36 `[input+2]` enqueue | 原生 Server input opcode 需 T02/④ 證據 |
| Conn backlog > 0x12C | 0x8060D0 Conn+0xA0A4 check | queue return0 / no copy | 非 Server 拒收 |
| Conn routing key0 not found | 0x8069A0 map lookup misses | return0 | 非 Server 拒收 |

### D.1 可供相容 Server 的**條件式** fixture（非官方錄包）

```text
1C 00 03 00 62 28     # NPC kind3 ID10338 (if original event fields forwarded unchanged)
3F 00 0F 00 01 00 01 00  # Controller Q15,secondary1,tail1 (if branch permits)
36 00 0F 00           # hypothetical only: OTHER producer input WORD=15; NOT mode2 click proof
```

不可將 fixture 傳回標註成官方抓包、Client 必然發送或 Server 必然接受；要觀察實際順序、首次與重複 NPC 對話、失敗/取消、各 conn framing、重連狀態，需遊玩 trace／T02/T07 協作。

### D.2 最小概念偽碼（符號名均暫定）

```cpp
void Actor::OnInteraction() {
    if (kind_0xF4 != 3) return other_kind_actions();
    if (local_mode_tests_allow_F43D9()) {
        Event* evt = make_event(0x105BF, 0xF43D9);
        evt->selector_0x14 = actor_id_0xF6;
        evt->npc_kind_0x18 = kind_0xF4;
        evt->npc_id_0x1C = actor_id_0xF6;
        queue_local_event(evt); // specific wrapper / timing needs native or runtime validation
    }
}
void HandleOuterNpcEvent(Outer* outer) {
    if (!isType(outer,0x105BD) || outer->action!=0x6A7) return other_case();
    Inner* evt = validateType(outer->inner_0x18,0x105BF);
    uint16_t quest = firstEligibleType2Giver(evt->selector_0x14); // Q15 conditional
    controller->LatchQuest(quest,1);     // no immediate 0x3F implied
    if (senderGate_0xFBA798 == 0)
        sender->EnqueueApp(0, {u16(0x1C),u16(evt->kind_0x18),u16(evt->id_0x1C)}, 6);
}
void Controller::ConditionalLaterStep() {
    if (pending_0x28) {
        pending_0x28 = 0; // crucial BEFORE some send gates
        if (sceneFlag_0x89 == 0 && quest_0x38 && specificStageGate())
             send_0x3F(quest_0x38, secondary_0x3C); // gate & other branches remain
        else alternate_action();
    }
}
void send_0x3F(uint16_t a,uint16_t b){
    if(senderGate_0xFBA798==0)
       sender->EnqueueApp(0,{u16(0x3F),a,b,u16(1)},8);
}
```

### D.3 與既有研究的明確範圍關係

- T16-123：確認 0x40/64/65/72/74 的**入站**狀態分支，僅供本段推斷候選存在的必要條件；不把 quest 完成/獎勵混入本段 C2S。
- T16-124：Q16 key16→Q15 Demand16、town5 selector及 NPC10338 的條件式 type2 first-hit；本段不重做整篇 XML/Scene reader，只驗證必要候選和 C2S 原生 call site。
- T16-125：Quest15 Scene1～4、物件10338／10047 資料源；場景資源存在並非 runtime 物件已點擊。
- T16-126：原生 actor constructor、vtable+0x64、F43D9 event router；本段向 C2S +0x18/+0x1C 與 controller queue 延伸，並保存未閉合 wrapper gate。
- T16-121／122：mode2與mode1的負面證據、sender vtable 與共享 queue；本段重新以 KR BIN 對關鍵 VA/bytes 交叉重驗並指出 pending flag 的先清後送分支。

## E. 未解項及分工，**不納入③有界研究已完成的肯定主張**

- **Client 待逆向**：`0x5854B0 → 0x58B270` local event 的 action F43D9，至 `0x5B7F80` 實際接收的 type0x105BD/action0x6A7 nested wrapper 之所有擁有者/生命週期；完整 0x500A80 返回 `5` 與 scene state 的條件、所有 emitter caller；`0x4B3510` handler table 到實際 wire dispatcher；`0x561DB0` 所有 stage source／timer 系列的 runtime gate；Quest15 mode2 其他 UI 按鍵是否間接經別種 handler 送出封包。此些需跨 T07/T02 或 T16後續時序研究；不得誤判 Client 必然送出。
- **Server 待開發**：明確定義收到 NPC `0x1C` kind/id 的權限與角色相容策略、收到 controller `0x3F` 的 `arg1/arg2/tail` 如何解讀及配對 Q15，是否送 `0x40(15,state0)`、拒絕／結束情境、前置條件與持久化；如無原版 traffic 應以 ADR 標識選擇。
- **跨 Task 待整合**：T02 application payload vs 0xA02C framing/IOCP；T07 觸發區／town5 scene與事件 wrapper；T03/T04 登入角色與前置 snapshot；T14 關卡結算；T15 QuestID 後端保存。S00 可採有限主張建 DRAFT 契約，不宣告 SPEC STABLE。
- **待遊玩驗證**：原版 Client 實際 click NPC10338 在不同進度／town／scene 的完整出站序列、重複點擊、0x3F 何時入列與可能丟失、回覆/取消/轉場、重登；這不是 T16-③ 目前能宣稱的 runtime 證據。

## F. Quest15 五研究與交付結論

| Quest15 子研究 | 狀態 |
|---|---|
| ① 資源、Demand16、獎勵 schema、四場景 | T16-125 有界完成 |
| ② NPC10338 actor 事件→type2／mode2 TalkBox | T16-126 有界完成 |
| **③ C→S producers、gates、queue** | **T16-127 Client 靜態有界完成**（含尚未 runtime-verified 外層 wrapper、實際配對） |
| ④ S→C 狀態／UI 結果 | 下一個正式研究目標 T16-128（先核對遠端段號） |
| ⑤ Quest15 後續村莊／劇情 | 待研究 |

**「Quest15-③ 有界完成」只涵蓋 native Client 已知 C→S producer、memory dataflow、branch gate 與 sender queue，並非所有未知一概已關閉；研究目標不需要原版 Server 內部實作才能以這個證據邊界完成。**

## G. KR 原始 BIN disassembly／byte SHA256（所列均由本輪原件重新生成）

所有地址的 disassembly 都以已檢查的 instruction start address 切入；後面的 `end exclusive` 只作 hash/slice 證據界線，若最後一條指令部分超出切片，應以相鄰上下文再核對，不拿半條指令當完整推論。確定的 .text VA→raw 常數為 `0x400C00`。

### A01. Record → ctor caller (kind/id arguments)

- BIN VA `[0x4B2BAE,0x4B2BE0)`; raw `[0xB1FAE,0xB1FE0)`; 50 bytes; SHA256 `969f0b180f7711605bd6c1ab26c86d32075620ba36f3f45388aa505b9b8b1f4b`.

```asm
004b2bae <.data+0xb1fae>:
  4b2bae:	0f b6 57 01          	movzx  edx,BYTE PTR [edi+0x1]
  4b2bb2:	d9 47 fc             	fld    DWORD PTR [edi-0x4]
  4b2bb5:	0f b6 0f             	movzx  ecx,BYTE PTR [edi]
  4b2bb8:	52                   	push   edx
  4b2bb9:	0f b6 57 f3          	movzx  edx,BYTE PTR [edi-0xd]
  4b2bbd:	51                   	push   ecx
  4b2bbe:	52                   	push   edx
  4b2bbf:	0f b7 57 f0          	movzx  edx,WORD PTR [edi-0x10]
  4b2bc3:	51                   	push   ecx
  4b2bc4:	8d 4f f4             	lea    ecx,[edi-0xc]
  4b2bc7:	d9 1c 24             	fstp   DWORD PTR [esp]
  4b2bca:	52                   	push   edx
  4b2bcb:	66 0f be 57 f2       	movsx  dx,BYTE PTR [edi-0xe]
  4b2bd0:	0f b7 d2             	movzx  edx,dx
  4b2bd3:	52                   	push   edx
  4b2bd4:	50                   	push   eax
  4b2bd5:	e8 26 0b 09 00       	call   0x543700
  4b2bda:	8b f0                	mov    esi,eax
  4b2bdc:	eb 02                	jmp    0x4b2be0
  4b2bde:	33 f6                	xor    esi,esi
```

### A02. Actor ctor type/id writer

- BIN VA `[0x543700,0x5437A1)`; raw `[0x142B00,0x142BA1)`; 161 bytes; SHA256 `ccaab075b3f36c53fd0beec67184efbe48c6c5dfd68494647412dc9b715f67dd`.

```asm
00543700 <.data+0x142b00>:
  543700:	55                   	push   ebp
  543701:	8b ec                	mov    ebp,esp
  543703:	6a ff                	push   0xffffffff
  543705:	68 28 98 92 00       	push   0x929828
  54370a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  543710:	50                   	push   eax
  543711:	83 ec 28             	sub    esp,0x28
  543714:	53                   	push   ebx
  543715:	56                   	push   esi
  543716:	57                   	push   edi
  543717:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  54371c:	33 c5                	xor    eax,ebp
  54371e:	50                   	push   eax
  54371f:	8d 45 f4             	lea    eax,[ebp-0xc]
  543722:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  543728:	8b f9                	mov    edi,ecx
  54372a:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  54372d:	8a 45 18             	mov    al,BYTE PTR [ebp+0x18]
  543730:	8b f3                	mov    esi,ebx
  543732:	89 5d cc             	mov    DWORD PTR [ebp-0x34],ebx
  543735:	88 45 f3             	mov    BYTE PTR [ebp-0xd],al
  543738:	e8 f3 6f f8 ff       	call   0x4ca730
  54373d:	33 d2                	xor    edx,edx
  54373f:	89 93 f0 00 00 00    	mov    DWORD PTR [ebx+0xf0],edx
  543745:	66 8b 45 10          	mov    ax,WORD PTR [ebp+0x10]
  543749:	66 8b 4d 0c          	mov    cx,WORD PTR [ebp+0xc]
  54374d:	f3 0f 10 45 14       	movss  xmm0,DWORD PTR [ebp+0x14]
  543752:	89 55 fc             	mov    DWORD PTR [ebp-0x4],edx
  543755:	66 89 83 f6 00 00 00 	mov    WORD PTR [ebx+0xf6],ax
  54375c:	8a 45 20             	mov    al,BYTE PTR [ebp+0x20]
  54375f:	88 83 f8 00 00 00    	mov    BYTE PTR [ebx+0xf8],al
  543765:	8b 45 1c             	mov    eax,DWORD PTR [ebp+0x1c]
  543768:	89 83 00 01 00 00    	mov    DWORD PTR [ebx+0x100],eax
  54376e:	0f b6 45 f3          	movzx  eax,BYTE PTR [ebp-0xd]
  543772:	c7 03 fc f7 c0 00    	mov    DWORD PTR [ebx],0xc0f7fc
  543778:	66 89 8b f4 00 00 00 	mov    WORD PTR [ebx+0xf4],cx
  54377f:	f3 0f 11 83 fc 00 00 	movss  DWORD PTR [ebx+0xfc],xmm0
  543786:	00 
  543787:	88 93 04 01 00 00    	mov    BYTE PTR [ebx+0x104],dl
  54378d:	88 83 05 01 00 00    	mov    BYTE PTR [ebx+0x105],al
  543793:	d9 83 a0 00 00 00    	fld    DWORD PTR [ebx+0xa0]
  543799:	8d b3 a0 00 00 00    	lea    esi,[ebx+0xa0]
  54379f:	d9 07                	fld    DWORD PTR [edi]
```

### A03. Actor kind3 state and 0x500A80 conditional event split

- BIN VA `[0x54409C,0x5441E7)`; raw `[0x14349C,0x1435E7)`; 331 bytes; SHA256 `cbf886238df49f8246f4f956ab03632b83b529f17a8e109e20356a8d386424db`.

```asm
0054409c <.data+0x14349c>:
  54409c:	8b f1                	mov    esi,ecx
  54409e:	0f b7 86 f4 00 00 00 	movzx  eax,WORD PTR [esi+0xf4]
  5440a5:	66 83 f8 03          	cmp    ax,0x3
  5440a9:	0f 85 11 03 00 00    	jne    0x5443c0
  5440af:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  5440b5:	8b 01                	mov    eax,DWORD PTR [ecx]
  5440b7:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  5440ba:	ff d2                	call   edx
  5440bc:	8b f8                	mov    edi,eax
  5440be:	85 ff                	test   edi,edi
  5440c0:	74 5e                	je     0x544120
  5440c2:	d9 87 a0 00 00 00    	fld    DWORD PTR [edi+0xa0]
  5440c8:	d8 a6 a0 00 00 00    	fsub   DWORD PTR [esi+0xa0]
  5440ce:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  5440d2:	d9 87 a4 00 00 00    	fld    DWORD PTR [edi+0xa4]
  5440d8:	d8 a6 a4 00 00 00    	fsub   DWORD PTR [esi+0xa4]
  5440de:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  5440e2:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  5440e6:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  5440ea:	e8 db ac 3b 00       	call   0x8fedca
  5440ef:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  5440f3:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  5440f7:	8b 1f                	mov    ebx,DWORD PTR [edi]
  5440f9:	dc 05 28 58 c5 00    	fadd   QWORD PTR ds:0xc55828
  5440ff:	51                   	push   ecx
  544100:	d9 5c 24 18          	fstp   DWORD PTR [esp+0x18]
  544104:	d9 44 24 18          	fld    DWORD PTR [esp+0x18]
  544108:	d9 1c 24             	fstp   DWORD PTR [esp]
  54410b:	e8 40 73 f7 ff       	call   0x4bb450
  544110:	8b 53 58             	mov    edx,DWORD PTR [ebx+0x58]
  544113:	2c 80                	sub    al,0x80
  544115:	0f b6 c0             	movzx  eax,al
  544118:	83 c4 04             	add    esp,0x4
  54411b:	50                   	push   eax
  54411c:	8b cf                	mov    ecx,edi
  54411e:	ff d2                	call   edx
  544120:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  544127:	0f b7 86 f6 00 00 00 	movzx  eax,WORD PTR [esi+0xf6]
  54412e:	0f bf f8             	movsx  edi,ax
  544131:	75 29                	jne    0x54415c
  544133:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  54413a:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  544141:	00 
  544142:	e8 19 bd fb ff       	call   0x4ffe60
  544147:	68 00 cf bc 00       	push   0xbccf00
  54414c:	e8 c9 e1 34 00       	call   0x89231a
  544151:	83 c4 04             	add    esp,0x4
  544154:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  54415b:	ff 
  54415c:	57                   	push   edi
  54415d:	68 a0 b2 fa 00       	push   0xfab2a0
  544162:	e8 19 c9 fb ff       	call   0x500a80
  544167:	83 f8 05             	cmp    eax,0x5
  54416a:	74 7b                	je     0x5441e7
  54416c:	8b 35 d0 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1bd0
  544172:	8d 44 24 14          	lea    eax,[esp+0x14]
  544176:	50                   	push   eax
  544177:	8d 4e 08             	lea    ecx,[esi+0x8]
  54417a:	8d 44 24 14          	lea    eax,[esp+0x14]
  54417e:	89 7c 24 18          	mov    DWORD PTR [esp+0x18],edi
  544182:	e8 39 f7 2f 00       	call   0x8438c0
  544187:	8b 76 0c             	mov    esi,DWORD PTR [esi+0xc]
  54418a:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  54418e:	3b c6                	cmp    eax,esi
  544190:	0f 84 7d 05 00 00    	je     0x544713
  544196:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  544199:	85 c0                	test   eax,eax
  54419b:	0f 84 72 05 00 00    	je     0x544713
  5441a1:	8b 48 40             	mov    ecx,DWORD PTR [eax+0x40]
  5441a4:	3b 48 44             	cmp    ecx,DWORD PTR [eax+0x44]
  5441a7:	0f 84 66 05 00 00    	je     0x544713
  5441ad:	6a 1c                	push   0x1c
  5441af:	e8 b4 d0 34 00       	call   0x891268
  5441b4:	8b f0                	mov    esi,eax
  5441b6:	83 c4 04             	add    esp,0x4
  5441b9:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5441bd:	c7 44 24 28 01 00 00 	mov    DWORD PTR [esp+0x28],0x1
  5441c4:	00 
  5441c5:	85 f6                	test   esi,esi
  5441c7:	0f 84 26 03 00 00    	je     0x5444f3
  5441cd:	e8 8e ae ec ff       	call   0x40f060
  5441d2:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  5441d8:	50                   	push   eax
  5441d9:	8b d7                	mov    edx,edi
  5441db:	8b c6                	mov    eax,esi
  5441dd:	e8 9e fd 20 00       	call   0x753f80
  5441e2:	e9 0e 03 00 00       	jmp    0x5444f5
```

### A04. Actor producer F43D9 event writes +14,+18,+1C

- BIN VA `[0x5442CC,0x54431F)`; raw `[0x1436CC,0x14371F)`; 83 bytes; SHA256 `18e83f78cbaaad6dc739473abc27af657f0a7e0f2814ef8637450472e9d36cda`.

```asm
005442cc <.data+0x1436cc>:
  5442cc:	53                   	push   ebx
  5442cd:	e8 1e 58 ff ff       	call   0x539af0
  5442d2:	e8 e9 11 ec ff       	call   0x4054c0
  5442d7:	6a 20                	push   0x20
  5442d9:	e8 8a cf 34 00       	call   0x891268
  5442de:	83 c4 04             	add    esp,0x4
  5442e1:	85 c0                	test   eax,eax
  5442e3:	74 3e                	je     0x544323
  5442e5:	0f b7 8e f6 00 00 00 	movzx  ecx,WORD PTR [esi+0xf6]
  5442ec:	0f b7 96 f4 00 00 00 	movzx  edx,WORD PTR [esi+0xf4]
  5442f3:	0f bf d2             	movsx  edx,dx
  5442f6:	0f bf c9             	movsx  ecx,cx
  5442f9:	83 cb ff             	or     ebx,0xffffffff
  5442fc:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  5442ff:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  544302:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  544309:	c7 40 10 d9 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf43d9
  544310:	c7 00 e4 7b c4 00    	mov    DWORD PTR [eax],0xc47be4
  544316:	89 78 14             	mov    DWORD PTR [eax+0x14],edi
  544319:	89 50 18             	mov    DWORD PTR [eax+0x18],edx
  54431c:	89 48 1c             	mov    DWORD PTR [eax+0x1c],ecx
```

### A05. F43D9 event emitter delivery call site

- BIN VA `[0x54431F,0x5443C0)`; raw `[0x14371F,0x1437C0)`; 161 bytes; SHA256 `15cff4fd2e6689b79c06155e5d3278578f3bc9998c701b0ca105b0be1f6274a8`.

```asm
0054431f <.data+0x14371f>:
  54431f:	8b f0                	mov    esi,eax
  544321:	eb 05                	jmp    0x544328
  544323:	33 f6                	xor    esi,esi
  544325:	83 cb ff             	or     ebx,0xffffffff
  544328:	e8 73 07 ec ff       	call   0x404aa0
  54432d:	8b 80 c4 13 00 00    	mov    eax,DWORD PTR [eax+0x13c4]
  544333:	50                   	push   eax
  544334:	56                   	push   esi
  544335:	83 ec 1c             	sub    esp,0x1c
  544338:	8b cc                	mov    ecx,esp
  54433a:	89 64 24 3c          	mov    DWORD PTR [esp+0x3c],esp
  54433e:	68 fc d1 be 00       	push   0xbed1fc
  544343:	e8 08 df eb ff       	call   0x402250
  544348:	c7 44 24 4c 03 00 00 	mov    DWORD PTR [esp+0x4c],0x3
  54434f:	00 
  544350:	c7 44 24 38 21 00 00 	mov    DWORD PTR [esp+0x38],0x21
  544357:	00 
  544358:	e8 53 11 04 00       	call   0x5854b0
  54435d:	8b f0                	mov    esi,eax
  54435f:	8d 54 24 38          	lea    edx,[esp+0x38]
  544363:	52                   	push   edx
  544364:	8d 44 24 38          	lea    eax,[esp+0x38]
  544368:	8b ce                	mov    ecx,esi
  54436a:	e8 81 fd 02 00       	call   0x5740f0
  54436f:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  544372:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  544376:	3b c6                	cmp    eax,esi
  544378:	74 0d                	je     0x544387
  54437a:	83 c0 10             	add    eax,0x10
  54437d:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  544381:	72 0a                	jb     0x54438d
  544383:	8b 00                	mov    eax,DWORD PTR [eax]
  544385:	eb 06                	jmp    0x54438d
  544387:	cc                   	int3
  544388:	b8 fc d1 be 00       	mov    eax,0xbed1fc
  54438d:	83 ec 1c             	sub    esp,0x1c
  544390:	8b cc                	mov    ecx,esp
  544392:	89 64 24 54          	mov    DWORD PTR [esp+0x54],esp
  544396:	50                   	push   eax
  544397:	e8 b4 de eb ff       	call   0x402250
  54439c:	68 cf 00 00 00       	push   0xcf
  5443a1:	89 5c 24 6c          	mov    DWORD PTR [esp+0x6c],ebx
  5443a5:	e8 c6 6e 04 00       	call   0x58b270
  5443aa:	83 c4 44             	add    esp,0x44
  5443ad:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5443b1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5443b8:	59                   	pop    ecx
  5443b9:	5f                   	pop    edi
  5443ba:	5e                   	pop    esi
  5443bb:	5b                   	pop    ebx
  5443bc:	8b e5                	mov    esp,ebp
  5443be:	5d                   	pop    ebp
  5443bf:	c3                   	ret
```

### A06. Event action router entry

- BIN VA `[0x5B7F80,0x5B7FB5)`; raw `[0x1B7380,0x1B73B5)`; 53 bytes; SHA256 `f2396ef149d6a50e7dbcd6d7b71e5ec75edd7cfefbdc881a62aa3ee42905e8c2`.

```asm
005b7f80 <.data+0x1b7380>:
  5b7f80:	55                   	push   ebp
  5b7f81:	8b ec                	mov    ebp,esp
  5b7f83:	83 ec 08             	sub    esp,0x8
  5b7f86:	53                   	push   ebx
  5b7f87:	56                   	push   esi
  5b7f88:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  5b7f8b:	56                   	push   esi
  5b7f8c:	8b d9                	mov    ebx,ecx
  5b7f8e:	e8 ed 3d fe ff       	call   0x59bd80
  5b7f93:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  5b7f96:	05 9c bc f0 ff       	add    eax,0xfff0bc9c
  5b7f9b:	3d db 00 00 00       	cmp    eax,0xdb
  5b7fa0:	0f 87 e3 03 00 00    	ja     0x5b8389
  5b7fa6:	0f b6 80 60 84 5b 00 	movzx  eax,BYTE PTR [eax+0x5b8460]
  5b7fad:	57                   	push   edi
  5b7fae:	ff 24 85 94 83 5b 00 	jmp    DWORD PTR [eax*4+0x5b8394]
```

### A07. Action F43D9 router branch→NPC consumer

- BIN VA `[0x5B8167,0x5B8177)`; raw `[0x1B7567,0x1B7577)`; 16 bytes; SHA256 `226642f7dba89e793cd5b2ae260b741d1b6d05a528ccbdddb43e02e8a184fd0d`.

```asm
005b8167 <.data+0x1b7567>:
  5b8167:	8b ce                	mov    ecx,esi
  5b8169:	e8 d2 11 00 00       	call   0x5b9340
  5b816e:	5f                   	pop    edi
  5b816f:	5e                   	pop    esi
  5b8170:	5b                   	pop    ebx
  5b8171:	8b e5                	mov    esp,ebp
  5b8173:	5d                   	pop    ebp
  5b8174:	c2 04 00             	ret    0x4
```

### A08. Outer+inner event validation, type2 chosen ID and 0x1C producer

- BIN VA `[0x5B9340,0x5B9498)`; raw `[0x1B8740,0x1B8898)`; 344 bytes; SHA256 `69a5aadbc0a1ffa9d11ec62c74a1d8a40e201eee8d0e9192b5903e56aab4df99`.

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

### A09. Candidate first-hit type2 helper

- BIN VA `[0x5008B0,0x500944)`; raw `[0xFFCB0,0xFFD44)`; 148 bytes; SHA256 `aeee21cd72e41936104913bf9baa86f11b09632e77fa568f145237f67f62928c`.

```asm
005008b0 <.data+0xffcb0>:
  5008b0:	55                   	push   ebp
  5008b1:	8b ec                	mov    ebp,esp
  5008b3:	83 e4 f8             	and    esp,0xfffffff8
  5008b6:	6a ff                	push   0xffffffff
  5008b8:	68 28 88 90 00       	push   0x908828
  5008bd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5008c3:	50                   	push   eax
  5008c4:	83 ec 18             	sub    esp,0x18
  5008c7:	56                   	push   esi
  5008c8:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5008cd:	33 c4                	xor    eax,esp
  5008cf:	50                   	push   eax
  5008d0:	8d 44 24 20          	lea    eax,[esp+0x20]
  5008d4:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5008da:	33 f6                	xor    esi,esi
  5008dc:	89 74 24 0c          	mov    DWORD PTR [esp+0xc],esi
  5008e0:	89 74 24 10          	mov    DWORD PTR [esp+0x10],esi
  5008e4:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5008e8:	8d 44 24 0c          	lea    eax,[esp+0xc]
  5008ec:	50                   	push   eax
  5008ed:	51                   	push   ecx
  5008ee:	52                   	push   edx
  5008ef:	89 74 24 34          	mov    DWORD PTR [esp+0x34],esi
  5008f3:	e8 08 01 00 00       	call   0x500a00
  5008f8:	8b 44 24 0c          	mov    eax,DWORD PTR [esp+0xc]
  5008fc:	3b 44 24 10          	cmp    eax,DWORD PTR [esp+0x10]
  500900:	75 20                	jne    0x500922
  500902:	3b c6                	cmp    eax,esi
  500904:	74 09                	je     0x50090f
  500906:	50                   	push   eax
  500907:	e8 00 09 39 00       	call   0x89120c
  50090c:	83 c4 04             	add    esp,0x4
  50090f:	33 c0                	xor    eax,eax
  500911:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  500915:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  50091c:	59                   	pop    ecx
  50091d:	5e                   	pop    esi
  50091e:	8b e5                	mov    esp,ebp
  500920:	5d                   	pop    ebp
  500921:	c3                   	ret
  500922:	8b 08                	mov    ecx,DWORD PTR [eax]
  500924:	0f b7 31             	movzx  esi,WORD PTR [ecx]
  500927:	50                   	push   eax
  500928:	e8 df 08 39 00       	call   0x89120c
  50092d:	83 c4 04             	add    esp,0x4
  500930:	66 8b c6             	mov    ax,si
  500933:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  500937:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  50093e:	59                   	pop    ecx
  50093f:	5e                   	pop    esi
  500940:	8b e5                	mov    esp,ebp
  500942:	5d                   	pop    ebp
  500943:	c3                   	ret
```

### A10. Candidate records kind type2+giver filter

- BIN VA `[0x500A00,0x500A7D)`; raw `[0xFFE00,0xFFE7D)`; 125 bytes; SHA256 `7249341812963eb07e7eff57ed46c249bb791275e54364b6265debf16c55a929`.

```asm
00500a00 <.data+0xffe00>:
  500a00:	55                   	push   ebp
  500a01:	8b ec                	mov    ebp,esp
  500a03:	83 ec 0c             	sub    esp,0xc
  500a06:	53                   	push   ebx
  500a07:	57                   	push   edi
  500a08:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  500a0b:	8b 87 c4 5e 00 00    	mov    eax,DWORD PTR [edi+0x5ec4]
  500a11:	8b 9f c0 5e 00 00    	mov    ebx,DWORD PTR [edi+0x5ec0]
  500a17:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  500a1a:	3b d8                	cmp    ebx,eax
  500a1c:	74 57                	je     0x500a75
  500a1e:	56                   	push   esi
  500a1f:	90                   	nop
  500a20:	0f b7 03             	movzx  eax,WORD PTR [ebx]
  500a23:	8b b7 ac 5e 00 00    	mov    esi,DWORD PTR [edi+0x5eac]
  500a29:	8d 4d fc             	lea    ecx,[ebp-0x4]
  500a2c:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500a2f:	51                   	push   ecx
  500a30:	8d 45 f8             	lea    eax,[ebp-0x8]
  500a33:	8b ce                	mov    ecx,esi
  500a35:	e8 e6 32 00 00       	call   0x503d20
  500a3a:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  500a3d:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500a40:	74 05                	je     0x500a47
  500a42:	83 c0 10             	add    eax,0x10
  500a45:	eb 02                	jmp    0x500a49
  500a47:	33 c0                	xor    eax,eax
  500a49:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500a4c:	85 c0                	test   eax,eax
  500a4e:	74 1c                	je     0x500a6c
  500a50:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  500a53:	39 50 28             	cmp    DWORD PTR [eax+0x28],edx
  500a56:	75 14                	jne    0x500a6c
  500a58:	83 78 04 02          	cmp    DWORD PTR [eax+0x4],0x2
  500a5c:	75 0e                	jne    0x500a6c
  500a5e:	8b 7d 10             	mov    edi,DWORD PTR [ebp+0x10]
  500a61:	8d 45 fc             	lea    eax,[ebp-0x4]
  500a64:	e8 a7 32 f4 ff       	call   0x443d10
  500a69:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  500a6c:	83 c3 02             	add    ebx,0x2
  500a6f:	3b 5d f4             	cmp    ebx,DWORD PTR [ebp-0xc]
  500a72:	75 ac                	jne    0x500a20
  500a74:	5e                   	pop    esi
  500a75:	5f                   	pop    edi
  500a76:	5b                   	pop    ebx
  500a77:	8b e5                	mov    esp,ebp
  500a79:	5d                   	pop    ebp
  500a7a:	c2 0c 00             	ret    0xc
```

### A11. Controller latch: early pending gate, special immediate 0x3F, normal save

- BIN VA `[0x561760,0x561945)`; raw `[0x160B60,0x160D45)`; 485 bytes; SHA256 `6ac6fbc8a9ffc5b88ad7e3c633181202a13b6a78827c3650209e949899e7e4cc`.

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

### A12. Later controller timer/continuation call

- BIN VA `[0x56287E,0x562891)`; raw `[0x161C7E,0x161C91)`; 19 bytes; SHA256 `9dabcfff64c01b52a3936adc93cb6c0132340cd855eacc53f95c5561c442e8fc`.

```asm
0056287e <.data+0x161c7e>:
  56287e:	b8 58 73 fb 00       	mov    eax,0xfb7358
  562883:	e8 b8 0e ff ff       	call   0x553740
  562888:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  56288c:	e8 1f f5 ff ff       	call   0x561db0
```

### A13. Controller scene-vs-network state branch

- BIN VA `[0x561DB0,0x561F60)`; raw `[0x1611B0,0x161360)`; 432 bytes; SHA256 `249f4491e25f146a9c4db1bfb831877e9d881270d683d508d010f78832366b0d`.

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
  561e33:	83 ce ff             	or     esi,0xffffffff
  561e36:	68 ec 06 c1 00       	push   0xc106ec
  561e3b:	6a 00                	push   0x0
  561e3d:	68 c8 f3 fd 00       	push   0xfdf3c8
  561e42:	e8 59 b2 f4 ff       	call   0x4ad0a0
  561e47:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  561e4e:	75 20                	jne    0x561e70
  561e50:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  561e56:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  561e5a:	e8 21 56 02 00       	call   0x587480
  561e5f:	68 c0 cc bc 00       	push   0xbcccc0
  561e64:	e8 b1 04 33 00       	call   0x89231a
  561e69:	83 c4 04             	add    esp,0x4
  561e6c:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561e70:	d9 87 84 00 00 00    	fld    DWORD PTR [edi+0x84]
  561e76:	83 ec 08             	sub    esp,0x8
  561e79:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  561e7d:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  561e81:	d9 54 24 04          	fst    DWORD PTR [esp+0x4]
  561e85:	d9 1c 24             	fstp   DWORD PTR [esp]
  561e88:	e8 93 7b 02 00       	call   0x589a20
  561e8d:	8a 9f 88 00 00 00    	mov    bl,BYTE PTR [edi+0x88]
  561e93:	e8 08 2d ea ff       	call   0x404ba0
  561e98:	88 98 c4 68 00 00    	mov    BYTE PTR [eax+0x68c4],bl
  561e9e:	eb 03                	jmp    0x561ea3
  561ea0:	83 ce ff             	or     esi,0xffffffff
  561ea3:	f6 05 64 0f fc 00 01 	test   BYTE PTR ds:0xfc0f64,0x1
  561eaa:	75 25                	jne    0x561ed1
  561eac:	83 0d 64 0f fc 00 01 	or     DWORD PTR ds:0xfc0f64,0x1
  561eb3:	c7 44 24 28 02 00 00 	mov    DWORD PTR [esp+0x28],0x2
  561eba:	00 
  561ebb:	e8 20 be f1 ff       	call   0x47dce0
  561ec0:	68 f0 da bc 00       	push   0xbcdaf0
  561ec5:	e8 50 04 33 00       	call   0x89231a
  561eca:	83 c4 04             	add    esp,0x4
  561ecd:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
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
  561f0b:	f6 05 c0 0f fc 00 01 	test   BYTE PTR ds:0xfc0fc0,0x1
  561f12:	75 25                	jne    0x561f39
  561f14:	83 0d c0 0f fc 00 01 	or     DWORD PTR ds:0xfc0fc0,0x1
  561f1b:	c7 44 24 28 03 00 00 	mov    DWORD PTR [esp+0x28],0x3
  561f22:	00 
  561f23:	e8 28 6f 17 00       	call   0x6d8e50
  561f28:	68 b0 db bc 00       	push   0xbcdbb0
  561f2d:	e8 e8 03 33 00       	call   0x89231a
  561f32:	83 c4 04             	add    esp,0x4
  561f35:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561f39:	8b 47 34             	mov    eax,DWORD PTR [edi+0x34]
  561f3c:	50                   	push   eax
  561f3d:	b9 c8 0f fc 00       	mov    ecx,0xfc0fc8
  561f42:	e8 e9 74 17 00       	call   0x6d9430
  561f47:	89 5f 38             	mov    DWORD PTR [edi+0x38],ebx
  561f4a:	89 5f 3c             	mov    DWORD PTR [edi+0x3c],ebx
  561f4d:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  561f51:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  561f58:	59                   	pop    ecx
  561f59:	5f                   	pop    edi
  561f5a:	5e                   	pop    esi
  561f5b:	5b                   	pop    ebx
  561f5c:	8b e5                	mov    esp,ebp
  561f5e:	5d                   	pop    ebp
  561f5f:	c3                   	ret
```

### A14. Controller clears pending before conditional 0x3F call

- BIN VA `[0x561F60,0x561FF1)`; raw `[0x161360,0x1613F1)`; 145 bytes; SHA256 `a092e3d406740e3acaf021c9f20768648879e0426dfc56a43ca27dc18496e9fb`.

```asm
00561f60 <.data+0x161360>:
  561f60:	39 77 28             	cmp    DWORD PTR [edi+0x28],esi
  561f63:	0f 84 28 01 00 00    	je     0x562091
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
```

### A15. 3F application producer with sender gate

- BIN VA `[0x4A39A0,0x4A39EC)`; raw `[0xA2DA0,0xA2DEC)`; 76 bytes; SHA256 `dbb0c12cfc16ef6738deb33fda9cb2b410be3aae67e89a6df6b71e7fd1711976`.

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

### A16. Another 0x3F-capable controller input: message fields +2/+4

- BIN VA `[0x503095,0x5030BF)`; raw `[0x102495,0x1024BF)`; 42 bytes; SHA256 `987fbc8d4bcd525044f70e149a30f4a2a05ec6cc3db22d84aba10769735769b2`.

```asm
00503095 <.data+0x102495>:
  503095:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  503098:	0f bf 48 04          	movsx  ecx,WORD PTR [eax+0x4]
  50309c:	0f bf 50 02          	movsx  edx,WORD PTR [eax+0x2]
  5030a0:	51                   	push   ecx
  5030a1:	52                   	push   edx
  5030a2:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  5030a7:	e8 b4 e6 05 00       	call   0x561760
  5030ac:	33 c0                	xor    eax,eax
  5030ae:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5030b1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5030b8:	59                   	pop    ecx
  5030b9:	8b e5                	mov    esp,ebp
  5030bb:	5d                   	pop    ebp
  5030bc:	c2 0c 00             	ret    0xc
```

### A17. TalkBox mode1 F4402 branch (mode2 counterexample)

- BIN VA `[0x636BBE,0x636C35)`; raw `[0x235FBE,0x236035)`; 119 bytes; SHA256 `c269fc5e5d25da4863d39b8ec7531426a12070438067bc095b05baa051359341`.

```asm
00636bbe <.data+0x235fbe>:
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
```

### A18. TalkBox mode3 distinct local event branch

- BIN VA `[0x636C84,0x636CFA)`; raw `[0x236084,0x2360FA)`; 118 bytes; SHA256 `3099070a534bbe39f8a0239dea9968031f3be268fcf9163a577c36de611f0e66`.

```asm
00636c84 <.data+0x236084>:
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
```

### A19. UI gate F4402 only

- BIN VA `[0x636DE0,0x636E0C)`; raw `[0x2361E0,0x23620C)`; 44 bytes; SHA256 `03e1c88531b048287a744098a903893e36141054427acb318eb25c45e6acc61c`.

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
```

### A20. 0x36 producer through TalkBox record first WORD

- BIN VA `[0x636E10,0x636EAC)`; raw `[0x236210,0x2362AC)`; 156 bytes; SHA256 `f55bf2389039ebc7247e71041672e4aca3ed4cf3d7fd2e8b39c03feccb8a5a68`.

```asm
00636e10 <.data+0x236210>:
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
  636eab:	8b         	mov    eax,DWORD PTR [edx+0xd4]
```

### A21. Independent 0x36 producer input msg+2

- BIN VA `[0x4B3510,0x4B356E)`; raw `[0xB2910,0xB296E)`; 94 bytes; SHA256 `9891095427f348356bf833aa4f0aaac4ffecedaa4ec11a6931c768cc6306c9d3`.

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
  4b356b:	c2 0c 00             	ret    0xc
```

### A22. Sender virtual target key→Connection map

- BIN VA `[0x8069A0,0x8069F6)`; raw `[0x405DA0,0x405DF6)`; 86 bytes; SHA256 `15bfdafb9caef08f72626dffb2508c7568a9f251e13013959d0b965c1c16d3f1`.

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
  8069f3:	c2 0c 00             	ret    0xc
```

### A23. Conn copy/overflow/queue path

- BIN VA `[0x8060D0,0x806191)`; raw `[0x4054D0,0x405591)`; 193 bytes; SHA256 `b8a91d2db14f1edac4a7b379250ed8a006d4e5518958e978678a71f079df4509`.

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

### A24. Conn queue locking node and count

- BIN VA `[0x806060,0x8060CE)`; raw `[0x405460,0x4054CE)`; 110 bytes; SHA256 `378338fd62742a163bc08eeab6a1785f2c4ff089aa4706abf3de76b6a6738187`.

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
  8060cb:	c2 04 00             	ret    0x4
```

### A25. Frame mode with 4-byte prefix: not application length

- BIN VA `[0x807A70,0x807B19)`; raw `[0x406E70,0x406F19)`; 169 bytes; SHA256 `0b817e97902d7a0c9f4ffb2789f4b15930c9950fc032da2318722fd8ada209ac`.

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
```

### A26. Frame mode with 6-byte header and transformed stream

- BIN VA `[0x807830,0x807892)`; raw `[0x406C30,0x406C92)`; 98 bytes; SHA256 `5f871c52cc33322d1902be058e2dcef7807e8bb420f31a42e739ad6221208ac1`.

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
```

### A27. Event vtable type=0x105BF runtime getter

- BIN VA `[0x753B60,0x753B66)`; raw `[0x352F60,0x352F66)`; 6 bytes; SHA256 `bacb798ff871afbef35661b88cf93cb2063d5319df25abf678857e964e21d368`.

```asm
00753b60 <.data+0x352f60>:
  753b60:	b8 bf 05 01 00       	mov    eax,0x105bf
  753b65:	c3                   	ret
```

## H. 可重現的 source scanner／commit 注意

```bash
sha256sum /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x5b9340 --stop-address=0x5b9498 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x561f60 --stop-address=0x561ff1 /mnt/data/Tartaros.bin
```

上列為分析方法示例，前綴與負載碼不可當作官方原版抓包。GitHub 遠端 blob 與 commit 必須在成功 push 並讀回後於對話回報，不先虛構。
