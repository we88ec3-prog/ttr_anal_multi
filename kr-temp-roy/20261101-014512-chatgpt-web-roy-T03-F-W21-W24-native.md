# T03-F W21～W24：可操作角色建立／招募，C2S33 多個來源與回覆／角色紀錄分界

> chatgpt-web roy，2026-11-01 Asia/Taipei。版本 KR；本次使用者明確要求 F 工作包並提交至既有 `t03/roy/chatgpt-web`。原始 `Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本輪已重新計算。PE32 i386 ImageBase `0x400000`；.text VA `0x401000` raw `0x400`，code raw=VA−`0x400C00`；.rdata VA `0xBD2000` raw `0x7D0600`。原件唯讀，不執行/修改 Client，未取得原版官服封包或 Server 原始碼。

**研究結論：W21 有新的正向原生證據；W22「真正建立可操作角色 request→匹配的 S2C accepted/rejected」及 W23「result→RoleStore／初值／拒絕重試」尚未閉合；W24 的精確阻塞及交接已提供。本批完成研究成果交付，不等於 RR-0010、創角功能或可玩驗收已完成。**

## 開工、去重與驗證

先讀 `02-PROJECT-SHARED-INSTRUCTIONS.md`、`03-PROJECT-T03-INSTRUCTIONS.md`，再查 `AGENTS.md`、T03 README/task.json、T01 README、S00 dispatcher/inbox、唯一 RR、共用 FULL-PASS。開工 main `b1fa730c99dbe2ff29f0ffed8b7a0448d6f4c460`，T03 分支 `a82d5c6c3070413bd8a7e9efa8ad8e9780f6c502`，比較 ahead9/behind0，main已為祖先，故无需空 merge；提交前再核對。T01 舊 T03-6 退回已在 T03 分支 A 勘誤等待 T01 複驗；本次依明確使用者指示優先 F，不自行 RESOLVED。正式 RR-0009 ACCEPTED **僅限定 E70 提交的第5條 GUI blocker 研究**，GAP-CHAR-0002依然OPEN，RR-0010 BLOCKED、GAP-CHAR-0003 OPEN，SPEC不因本稿提升。

去重：E71 原稿 `kr-extra-roy/20261031-010931-chatgpt-web-roy-E71-RR0010-create-C2S-candidates-S2C-roster-blocker.md` blob `57f809809e28d24cd9779549d95e9b269db4870b`；E77 blob `7589e9c63f56f9a9d8737f825c46170ea9e64ac7`；E78 blob `ae381dd784f8d492a5b760723c8912ad7be2531a`；E79 blob `95ced26202c2aedf7ff57c87d4991eff00ad64ff`；本分支 D/E 原稿。沒有覆蓋舊報告。

**本輪第一手 BIN-first 定向核驗：**用 GNU objdump 分析15個相關函式/基本區塊，對共507個不同合法 native instruction starts 比較確切原件 opcode bytes，507/507 PASS；另核5個 rdata vtable cells、2種RTTI類別、PE/SHA。附可重跑區域 hash/原生欄位 verifier；這不是 T01 FULL-PASS、507個完整函式語意驗證或 Client runtime。

## W21 — C2S app0x0033 不是只有單一 UI sender

### A. CEmployNewCharacter 的 event0x578 → 4A38D0

MSVC RTTI `.?AVCEmployNewCharacter@FUI@@`，vtable `C3F024` 的 slot87 `C3F180→6BF2A0`。其 slot80 `C3F164→65D550` 與 **另一類 CCharChangeDialog** 的 slot80 `C33DB4→65D550` 共用 local event source，不能由 `F4350` 認定它獨屬創角。

```asm
6BF2A3 mov eax,[ebp+8]           ; UI event
6BF2A6 cmp dword[eax+10],578h
6BF2B2 mov ecx,[esi+D0h]         ; control ptr
6BF2BB cmp edx,[ecx+20h]        ; event+8 control identity
6BF2BE jne 6BF2FF
6BF2C0 call 404BA0               ; Client owner
6BF2C5 cmp dword[eax+5F4Ch],1
6BF2CC jne 6BF2F5
6BF2CE call 49B230               ; if state==1 -> local UI
6BF2D5 call 6BFAE0               ; local UI action, not a network ACK
6BF2DA call 4054C0
6BF2DF call 58B510
6BF2EE call [vtable+D4h]
6BF2F5 call 414680               ; if state!=1
6BF2FA call 4A38D0
4A38D4 cmp dword[FBA798],0
4A38DB mov eax,33h
4A38E0 mov word[ebp-2],ax
4A38E4 jne 4A38FB
4A38E6 mov ecx,[FBA854]
4A38EE mov edx,[vtable+10h]
4A38F1 push 2                    ; length 2B
4A38F7 push 0                    ; manager slot0
4A38F9 call edx                  ; local enqueue only
```

只有 event/控件 matching、Client+5F4C!=1、FBA798==0 等條件才可能送出 **inner application payload `33 00`、2B、slot0**。沒有角色名字、造型、職業或出生地；不是完整 TCP frame，不證 Server 接受。本地 `6BFAE0` 包含 `fld1`、局部行為值3、`6FB9A0` 的 UI 動作；不能把 state==1 分支當招募成功。

### B. 新發現：F431F local event 消費者自建 0x33，沒有呼叫 4A38D0

`0x5AAE80` 依本地 event分支處理：

```asm
5AAEA9 cmp dword[edi+10h],F431Fh
5AAEB0 jne 5AAF31
5AAEB2 cmp dword[edi+14h],0
5AAEB6 je 5AAEEA              ; local result0 -> inline sender
5AAEB8 mov ecx,[esi+164h]    ; nonzero -> existing role detail
5AAED2 call 6BF310
5AAEDF call 596E00            ; GUI update
5AAF0A cmp dword[FBA798],0
5AAF11 mov edx,33h
5AAF16 mov word[ebp+0Ah],dx
5AAF1A jne 5AAF31
5AAF1C mov ecx,[FBA854]
5AAF24 mov eax,[vtable+10h]
5AAF27 push 2
5AAF29 lea edx,[ebp+0Ah]
5AAF2D push 0
5AAF2F call eax
```

這是**第二個獨立 code-site inline sender**。F431F 本身為 local event，不是 wire 0x431F。它至少有兩個原始 producer：(1) `4A98D0` 於 `4A9926 mov eax,[ebp+8]; 4A9929 push eax; 4A992A push F431F; 4A992F call 58AB80`，轉送本地值；(2) `6BA2C0` 比對 event+10=`0x578`、this+`0x10C` 控件的 +0x20 ID與event+8一致，再 `6BA2FD mov esi,[FE18F8]`、`6BA336 movzx ecx,byte[esi+29]`，`6BA33B push F431F`、`6BA340 call 58AB80`。其 rdata指標 cell `C3E2E8→6BA2C0`。**正向的實際 bus listener binding/active scene 仍未知；不能把 producer存在說成一定到指定 consumer，亦不能當官服 create ACK。**

### C. 新發現：參數0x0D的第三個 inline app33 sender

```asm
6BA730 cmp dword[ebp+8],0Dh
6BA737 jne 6BA744
6BA739 call 6BA360
6BA73E mov al,1
6BA384 cmp dword[FBA798],0
6BA38B mov eax,33h
6BA390 mov word[ebp-2],ax
6BA394 jne 6BA3AB
6BA396 mov ecx,[FBA854]
6BA39E mov edx,[vtable+10h]
6BA3A1 push 2
6BA3A3 lea eax,[ebp-2]
6BA3A7 push 0
6BA3A9 call edx
```

rdata cell `C3E278→6BA730`。`0x0D` 是該 callback **本地參數**，不可擅稱「Enter鍵／角色ID／封包opcode」。因此三個不同的本地 C2S33 builders 是 `4A38D0`、`5AAE80` inline、`6BA360` inline。只用 `E8→4A38D0` direct xref（確實僅見 `6BF2FA`）會漏掉後兩者。

### D. 角色 UI 的可用 flag 不是新建角色證明

`6BF310` direct E8 callers `5AAED2`、`5C36DE`；其有界正常分支 `6BF38F cmp esi,9`、`6BF39A imul eax,eax,0x210`、`6BF3A0 add eax,[F94304]`、`6BF3A6 cmp dword[eax+5C],0`、零則跳 `6BF8D3`，非零再有 `5C7190` 資源、`745060` 控件、`483F00` 顯示。這是**現存 RoleStore 資料顯示**，並非原版 Server 接受新招募或建角證據；slot、旗標、資源、scene均需成立。

## W22 — S2C accepted/rejected consumer 的逐一邊界

| 候選 | 本地已證 consumer／資料 | 禁止強行配對的理由 |
|---|---|---|
| S2C `0x0033` | `4B7DC0` first-level default `4B7EC0`，index0x33 理論 cell `FD2CFC+0x33*8=FD2E94`；本函式無直接覆寫，精確 absolute displacement 的 raw掃描也無此 cell | `4B7EC0` 在 `Client+5EAC` active scene存在時會跳 scene vtable+4，還有 indirect/secondary handler；不能說不存在或就是建角ACK |
| S2C `0x0002` | `4B7F00` full `65+53N`，`4D4150` 寫 RoleStore+5C | 沒有與某一 C2S33同筆 transaction 相關的 accepted/rejected 旗標 |
| S2C `0x002B` | `493170→4943B0→4FDA30→4E2730`，`2+53N` delta，與full共用 `[F94304]` | row更新不含已證專用 Server outcome，不可當33 ACK |
| S2C `0x00B6` | `4B5DD0→local F4278(0)`，Page UI依 active scene、index和flag條件刷新 | B6 handler不讀53B角色資料；F4278還有CPhaseSlot來源 |
| S2C `0x004A` | EXPD scene `4C21D0` signed word+2 → local F4245；成功1可寫 Expedition name `F938F2` | 遠征隊建名結果不等於新可玩角色 |
| C2S `0x0021/0x0027/0x0042` | `4A39F0` 可變長0x21有11個direct callers；`4A3720` 0x27 8B來自 `682A3F`；`4A3B80` 0x42為**已存在角色選擇** | 不能用 request+1 推 create response，且0x42不是create request |

一手 `.text` E8-rel32 的有限 direct caller 掃描：`4A38D0←6BF2FA`；`4A39F0←45D018,577988,5FF6E4,60049B,6004ED,600AE3,6010F2,6092B4,60AB5A,651F64,8FEA9F`；`4A3720←682A3F`；`6BF310←5AAED2,5C36DE`；`6BA360←6BA739`。**這只是 direct call 限定證據，不能排除 virtual/alias/callback。**

**W22 保持未閉合**：尚無證據把「真正 playable create request」與「某個 S2C approved/rejected result」及「指定角色 row寫入」串成相同交易；缺原版 Server source/capture不代表Client可查的 active scene和event alias都已結束。

## W23 — 已存在角色、負向結果、重複、取消與斷線

- `record+0x5C` 由合法 full/delta row writer設1，`6BF310` 僅以這個本地資料有效旗標判斷展示，不代表創建權限、DB持久化或世界出生初值。角色初值交T04，進世界交T05。
- 控件不符、event!=0x578、`FBA798!=0` 或 Employ特定分支 `Client+5F4C==1` 時，可能根本沒有此次 C2S33 queue；按 UI 並不保證 Server收到。
- F431F result0 可使另一 UI consumer 再 enqueue33；非零走已存在角色資料 GUI。此 local value 來自不同 producers，**不是原版Server accepted/rejected enum**。
- full/delta N=0在已查 handler只跳過 row writer，不能保證重新清掉所有舊可用角色；record+5C 撤銷／重建需追全域 owner/scene/Conn lifecycle。
- 重複提交、姓名重複、招募失敗、拒絕重送、取消與斷線的真正 Client pending→S2C UI/cleanup 仍未閉合；Server可選擇自行實作安全權限/冪等/持久化，不能冒充原版政策。

## W24 — RR0010 阻塞、Server需求及下一步

| 類別 | 未解事項與可解除來源 |
|---|---|
| **Client 待逆向** | `6BA2C0/4A98D0` 的 F431F producer→`5AAE80` listener/active scene 真實 subscription；`FE18F8+29` writer；`6BA730` 0x0D callback GUI resource／sender；Client+5F4C writer；S2C33 active-scene secondary handlers；RoleStore+5C revoke/reset 全域生命週期；T06 同 KR GUI pack |
| **Server 待開發** | Account/Expedition/Role分層權限、招募/創建、資料持久化、去重、回覆、重試/斷線和適當 full/delta/B6 UI更新；**不可宣稱原版33→2B/B6 MUST順序** |
| **跨功能待整合** | T02 framing/slot0/scene dispatch，T04真正角色初值，T05入世界，T06 GUI身份；由 S00既有 `SPEC-CHAR-0001/SPEC-FLOW-0001/GAP-CHAR-0003` 去重，不自建平行RR |
| **待遊玩驗證** | 合法相同KR版原官服成功／拒絕／duplicate／disconnect之multi-Conn封包＋GUI/scene時間，或verified原版Server handler；synthetic只證相容方案，不證官服交易 |

### 玩家情境／合成反例（尚非正式 TEST）

| 情境 | 有界 Client 效果／尚未知 |
|---|---|
| Employ event0x578、控件相符且5F4C≠1 | `4A38D0` 條件性 queue `33 00` 2B slot0；role create官方語義未知 |
| 相同控件但5F4C==1 | 局部 `6BFAE0` UI分支，不經 `4A38D0` |
| F431F result0 | `5AAE80` inline33 sender，需 FBA798 gate；producer/scene訂閱未知 |
| F431F非零 | `6BF310` 有效角色 detail UI，不能當Server create成功 |
| `6BA2C0` local event0x578 | control10C匹配後產生 F431F(value=[FE18F8]+29)，未證必達指定listener |
| `6BA730` callback param0x0D | `6BA360` inline33 sender，不能將0x0D命名成Enter |
| role slot>9 或flag0 | role detail不走正常資料分支；不是官服拒絕 |
| S2C2B 53B row | 寫共享 RoleStore；不是已證C2S33配對 ACK |
| duplicate/timeout/disconnect | Client完整retry/錯誤結果未閉合；Server設計要獨立定義 |

**結論**：W21 已交付 Client 有界正向；W22、W23 原定完整 create-result 目標**PARTIAL／BLOCKED**；W24 blocker/證據/Server手交完成。正式 `RR-0010` 仍 `BLOCKED`、T01 FULL-PASS和S00 ACCEPTED均另行審核。原件不執行、不修改，不回推main。

驗證：`python -B 20261101-014512-chatgpt-web-roy-T03-F-verify.py Tartaros.bin [Tartaros.exe]`。原研究者對15區域取507指令起點的 byte 實測全部 PASS，遠端驗證腳本再核相同 BIN及區域 SHA、vtable、RTTI；靜態證據不能取代Server replay與玩家可玩驗收。
