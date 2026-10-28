# KR T16-72 — 收包後雙佇列路由與 T16-71 分派入口語意勘誤（BIN-first）

- 研究時間：2026-10-28 18:40:30 Asia/Taipei；研究者：chatgpt-web roy；僅 KR。
- BIN `/mnt/data/Tartaros.bin`：12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本輪透過 `sha256sum` 實際核驗。
- 唯讀分析、未執行原版 Client、未修改其他 Task、未 Git commit/push。
- BIN PE `.text` VA `0x401000` / raw `0x400`，本篇涉及 `.text` 時 raw = VA − `0x400C00`；未將此式跨 section 套用。以 `objdump -D -Mintel -b pei-i386 -m i386` 直接反組譯。

## 1. 本輪問題與關鍵勘誤

T16-71 將 `0x804310` / `0x489920` 記為「application dispatch candidates」，此判斷**僅對它們位於 parser 下游位置成立**，不得解讀為本身解析 opcode／執行 Quest handler。本輪直接驗證兩者均為 lazy singleton accessor：

```asm
804332: mov eax,1
804337: test BYTE PTR [0xfe3354],al
80433d: jne 0x80435e
80433f: or DWORD PTR [0xfe3354],eax
80434c: call 0x807120
80435e: mov eax,0xfe3358
804371: ret

489942: mov eax,1
489947: test BYTE PTR [0xfc10cc],al
48994d: jne 0x48996e
48994f: or DWORD PTR [0xfc10cc],eax
48995c: call 0x803ff0
48996e: mov eax,0xfc10d0
489981: ret
```

兩者返回**各自的全域物件地址**，而不是處理「push eax」提供的 packet argument。前段追蹤時將 `call 0x804310`／`call 0x489920` 獨立視為分派器不足精確。本輪確認實際具副作用的 consumer 是其後的 `0x8076F0` 和 `0x8040A0`，屬大幅縮小 handler 定位邊界的新結果。

## 2. 收包解析後 CFG 與上下游

```asm
807d7a: call 0x807e50              ; 在條件／校驗通過時把 payload 複製到 frame object
807d7f: mov eax,[esp+0x28]       ; prepared frame object
807d83: cmp DWORD PTR [eax+4],0  ; stored payload length
807d87: mov ecx,[esp+0x24]       ; connection context
807d8b: mov [eax],ecx            ; frame object+0 = connection pointer
807d8d: jne 0x807d9e
807d8f: push eax
807d90: call 0x804310            ; get/init singleton 0xfe3358
807d95: mov edi,eax
807d97: call 0x8076f0            ; queue A consumer
807d9c: jmp 0x807db2
807d9e: mov ecx,[ecx+0xa080]    ; context + A080 (queue subtype/tag candidate)
807da4: push ecx
807da5: push eax
807da6: call 0x489920            ; get/init singleton 0xfc10d0
807dab: mov edi,eax
807dad: call 0x8040a0            ; queue B consumer
```

**本輪首次證實：** parser 在 `frame object+4` 大小為零及非零時分為兩條資料路徑；兩條不是直接 quest opcode handlers，而是進入不同的共享緩衝／佇列。對第二條 additional argument 來源 `connection+0xA080`，尚不能命名業務 opcode。分支根據 decoded prepared frame object size，而非直接根據 Quest ID。

`0x807E50` 有 `esi <= 0x1000` guard，複製來源 `[ebp+8]` 的 `esi` bytes 至 `edi+8`，並寫入 `[edi+4]=esi`；此處 frame object 基本佈局可確定為 `{connection*, payloadLength, payload[... ]}`，但尚不能推出最終 Quest wire packet 本身布局。

```asm
807e53: cmp esi,0x1000
807e59: jbe 0x807e61
807e5b: xor al,al
807e61: mov eax,[ebp+8]
807e64: push esi
807e65: push eax
807e66: lea ecx,[edi+8]
807e69: push ecx
807e6a: call 0x89dbd0            ; memcpy-like copy
807e72: mov [edi+4],esi
807e75: mov al,1
```

注意：zero-length 分支不等於 Server 命令必然為空；要追 `0x8075B0` 準備 frame 的物件來源與 buffer 剩餘資料才能確定。

## 3. 佇列 A — singleton 0xFE3358 / 0x8076F0

```asm
8076f3: mov eax,[ebp+8]
8076f6: mov DWORD PTR [eax],0
8076fc: mov DWORD PTR [eax+4],0
807703: mov eax,[edi+0x58]        ; synchronization handle
807708: call DWORD PTR [0xbd224c] ; lock candidate
80770e: lea ecx,[ebp+8]
807712: lea esi,[edi+0x3c]
807715: call 0x804260            ; append 4-byte unit to segmented container
80771a: mov edx,[edi+0x58]
80771d: dec DWORD PTR [edi+0x54]  ; counter, exact convention pending
807721: call DWORD PTR [0xbd2248] ; unlock candidate
```

此函式在追加前**把 object 前 8 bytes 清零**，所以不能將其視為直接保留 `0x807D8B` 的 `connection*` 供 Quest handler 使用。`0x804260` 具配置 16-byte segment 和 `inc [esi+0x10]`，證實佇列容器的本地儲存動作。`0x8076F0` 是 **queue producer**，不是最終 gameplay consumer。`0x807120` 初始化 singleton，需在後續查其 callback/consumer 管道。

## 4. 佇列 B — singleton 0xFC10D0 / 0x8040A0

```asm
8040a3: mov eax,[edi+0x124]
8040aa: mov ebx,[ebp+0xc]       ; second argument passed from connection+A080
8040af: call DWORD PTR [0xbd224c] ; lock
8040b7: cmp BYTE PTR [ebx+edi+0x128],0
8040c1: sete dl
8040c5: lea eax,[edx+ebx*2]
8040c8: lea eax,[eax+eax*2]
8040cb: lea esi,[edi+eax*8]     ; 24-byte lane descriptor
8040c4: push ecx                ; pointer to [ebp+8] frame object
8040ce: call 0x804260          ; append
8040d3: mov ecx,[edi+0x124]
8040da: call DWORD PTR [0xbd2248] ; unlock
8040e1: cmp ebx,2
8040e7: mov edx,[edi+0x120]
8040ee: call DWORD PTR [0xbd20d0] ; conditional signal candidate
```

`0x8040A0` 按第二參數索引內部 lane，對 `ebx==2` 還有一條額外呼叫。**不能據此宣稱恰有三個 Quest 通訊 channel**：索引合法範圍、具體 channel 意義和 `0xbd20d0` API 名稱尚需 IAT 核對。`0x803FF0` 具有全域物件初始化、配置、同步 handle 設定，與直接 Quest handler 身分不相容。

`0x804100` 經 `[esi+0x10]` 檢查是否有可讀項、從段式容器讀 4 bytes 寫到 output，並更新計數；是更有價值的 **consumer-side dequeue** 入口。接續應找 call sites 和每個 lane 的工作執行器，沿 frame object+8 找 opcode handler。

## 5. 原版與待開發界線及玩家情境矩陣

| 玩家情境 | Client local gate | C→S | S→C | Client Quest/NPC/UI | Server 待開發 | 等級 |
|---|---|---|---|---|---|---|
| 啟動教學 Scenario | 原有 FBA798==0 等 | T16-69～71 已有靜態 WSASend 路徑，wire opcode 未確立 | 收包底層存在，尚未對應 Scenario 回覆 | unknown | 回覆語意待業務 handler | 部分確認 |
| 接收任務更新／通知 | `807B40` decode / length guard | unknown | generic frame → `807E50` → `8076F0`（zero-size）或 `8040A0`（nonzero-size） | 尚未進入 Quest consumer | 欄位／狀態通知待證 | 原生已確認通用路由、Quest unknown |
| Quest16 完成／Quest15 可接 | unknown | unknown | generic route only | unknown | 解鎖規則與回覆規格 unknown | unknown |
| NPC 點擊接取 Quest15 | unknown | unknown | generic route only | unknown | 接取與 ACK 規格 unknown | unknown |
| 重登恢復 Quest | 未查 P2 | unknown | unknown | unknown | 保存方式未知 | unknown |

## 6. 三輪研究門檻與下一入口

- 第一輪 T16-72：重新核對兩個「dispatch candidate」；證明它們只是 lazy singleton accessors，真正 data consumers 是兩個佇列寫入者，並確認 length-based branch、frame layout、B lane selection。這是**修正先前錯誤語意、明確辨認未知 consumer 所在層級**的技術增量。
- 研究仍未找出 Quest opcode／handler，故第 2、3 輪不能冒稱完成。本次未能在佇列 dequeue 的 caller／handler 註冊鏈取得可驗證閉合，保留正式段號 T16-72 的業務端尚未完成狀態；不虛報完成 Quest 解鎖。
- 下一入口：`0x804100` 佇列 B dequeue callers，`0x8076F0` 佇列 A consumers、`0x807120` A singleton initialization callback、`0x803FF0` B worker setup、`0x8075B0` frame allocator，定位 `frame+8` 真正命令讀取者後，才解析 opcode 與 Quest state writer；並平行追 NPC UI accept packet producer。
- 本次僅完成可驗證的收包佇列分流與勘誤，尚無完整 Quest16→Quest15 行為閉環。不可拿後端自製 fixture 充作原生回覆。

## 7. 復現命令

```bash
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe
objdump -D -Mintel -b pei-i386 -m i386 --start-address=0x807d55 --stop-address=0x807dc5 /mnt/data/Tartaros.bin
objdump -D -Mintel -b pei-i386 -m i386 --start-address=0x804310 --stop-address=0x804372 /mnt/data/Tartaros.bin
objdump -D -Mintel -b pei-i386 -m i386 --start-address=0x489920 --stop-address=0x489982 /mnt/data/Tartaros.bin
objdump -D -Mintel -b pei-i386 -m i386 --start-address=0x8040a0 --stop-address=0x80412d /mnt/data/Tartaros.bin
objdump -D -Mintel -b pei-i386 -m i386 --start-address=0x8076f0 --stop-address=0x80772c /mnt/data/Tartaros.bin
```

## 8. 第 2 輪增量：定位 B queue 的實際 dequeue worker（已達重大進展）

本輪以 `.text` E8 rel32 raw pattern 掃描、重新計算每個 target VA，再用 objdump 驗證指令邊界；`0x804100` 只找到兩個 direct call sites：**`0x804841`、`0x8049B2`**，皆位於 `0x804740` 起的同一工作函式。`0x8076F0` 與 `0x8040A0` 各只找到來自 `0x807D97`／`0x807DAD` 的直接呼叫，但不能排除間接呼叫。

```asm
804823: mov [ebp+8],esi                ; lane index initially 0
804826: cmp esi,2
804837: push esi                      ; lane index
804838: lea eax,[ebp-0x10]
80483b: push eax                      ; out frame pointer
80483c: mov eax,0xfc10d0             ; queue B object
804841: call 0x804100                ; dequeue
804846: test al,al
804848: je 0x8049d0                 ; empty -> next lane
804852: mov esi,[ebp-0x10]          ; popped frame object
804855: mov ecx,[ebp+8]             ; lane index
804858: mov edx,[ebx]
80485a: mov edx,[edx]                ; worker vtable+0x00
80485f: mov eax,[esi+4]             ; payload length
804862: push ecx                     ; lane
804863: push eax                     ; length
804864: lea eax,[esi+8]
804867: push eax                     ; payload
804868: mov eax,[esi]               ; connection ptr
80486a: push eax
80486b: mov ecx,ebx
80486d: call edx                      ; actual next business consumer (virtual)
80499f: cmp DWORD PTR [ebp-0x1c],0
8049a3: jne 0x8049c7
8049a5: mov eax,[ebp+8]
8049a8: push eax
8049a9: lea ecx,[ebp-0x10]
8049ac: push ecx
8049ad: mov eax,0xfc10d0
8049b2: call 0x804100                ; drain again after callback
8049bf: jne 0x804850
8049da: inc esi                      ; next lane
8049de: cmp esi,6
8049e1: jl 0x804826
```

**重要新確認：** B queue 有至少 `lane 0..5` 的 worker drain loop；`frame object` 中的 connection pointer、payload pointer (`+8`) 與 length (`+4`) 連同 lane 傳入**worker vtable +0x00**。相較前輪「只知收包後入列」，現在首次掌握「解框後 packet 怎樣抵達業務 callback」的實際資料流。這不是 Quest 專用證據；它是一條通用 packet consumption path。

worker 另外呼叫 `vtable +0x0C`（`0x80487C–0x804886`）與在延遲超過 `0x28` 時計入 `vtable +0x08`（`0x804888–0x8048A1`），只能定為處理完成／計時候選，不能據此命名 Quest ACK。

### 更新後的最精確鏈

```text
WSARecv → 0x807B40 decode → 0x807E50 packet object
  ├─ packet length == 0 → 0x804310 singleton → 0x8076F0 queue A
  └─ packet length != 0 → 0x489920 singleton → 0x8040A0 queue B lane
       → worker 0x804740 → 0x804100 dequeue
       → popped packet {connection, len, payload[0..]} 
       → worker vtable+0x00(connection, payload, len, lane)
       → task-specific handler: STILL UNKNOWN
```

下一個需要確定 **worker object 的具體 vtable 初始化及 +0x00 target**，然後由該 callback 的 `payload[0]` 或其他欄位追真正 opcode switch / dispatch table。此處還未證明 `0x0040` 對應收包訊息。

**三輪門檻：** 第一輪足以勘誤，第二輪取得可驗證重大進展（`0x804100` → `0x804740` worker → 虛擬業務 callback），故正式 T16-72 可依規範結束，`T16-72-3` **未啟動（第二輪已達標）**。第 3 輪並未執行，不虛構內容。下一正式段 T16-73 追 worker vtable target、Quest handler、NPC accept C→S。