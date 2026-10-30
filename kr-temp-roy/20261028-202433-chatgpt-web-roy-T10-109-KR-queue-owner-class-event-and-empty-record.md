# T10-109 — KR 收包 queue 的 owner、分類來源、同步事件與零長度特例（BIN-first）

## 0. 版本及研究邊界

2026-10-28 Asia/Taipei。第一手 `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 x86 `.text` VA 起點 `0x401000`，raw `0x400`，以下 `.text` raw=VA−`0x400C00`。用 GNU objdump 指定 native 視窗直接核對；無遊戲執行、附加、patch 或實際抓包。此段承接 T10-108 的 `0x807D7F`（frame→queue）。其他 T10 原稿僅作導航，以下結論來自原始 BIN。

本段第一輪關鍵突破是**消除上一段對 `0x489920` 的不確定與一處容易誤讀的分類推論**：該函式是 lazy singleton getter，不是 classifier。分類由 caller 已取得的 context `+0xA080` 保存並以 stack arg 傳入 queue append；queue append 只在類別 2 額外 signal 專用事件。零長度紀錄也不會進一般分類 append，而經另一個 queue/計數路徑。

## 1. `0x489920` 完整 getter 與 side effect

```asm
00489920 55                         push ebp
00489942 b8 01 00 00 00             mov eax,1
00489947 84 05 cc 10 fc 00          test byte [0xFC10CC],al
0048994d 75 1f                      jne 0x48996e
0048994f 09 05 cc 10 fc 00          or dword [0xFC10CC],eax
0048995c e8 8f a6 37 00             call 0x803ff0
00489961 68 90 dc bc 00             push 0xBCDC90
00489966 e8 af 89 40 00             call 0x89231a
0048996e b8 d0 10 fc 00             mov eax,0xFC10D0
00489981 c3                         ret
```

對照 caller：

```asm
00807d7f 8b 44 24 28                mov eax,[esp+0x28]       ; record
00807d83 83 78 04 00                cmp dword [eax+4],0      ; record length
00807d87 8b 4c 24 24                mov ecx,[esp+0x24]       ; context
00807d8b 89 08                      mov [eax],ecx           ; record+0
00807d8d 75 0f                      jne 0x807d9e
00807d8f 50                         push eax
00807d90 e8 7b c5 ff ff             call 0x804310
00807d95 8b f8                      mov edi,eax
00807d97 e8 54 f9 ff ff             call 0x8076f0
00807d9c eb 14                      jmp 0x807db2
00807d9e 8b 89 80 a0 00 00          mov ecx,[ecx+0xA080]    ; caller-context selection
00807da4 51                         push ecx               ; category (candidate)
00807da5 50                         push eax               ; record pointer
00807da6 e8 75 1b c8 ff             call 0x489920        ; getter, does NOT consume stack args
00807dab 8b f8                      mov edi,eax          ; owner singleton
00807dad e8 ee c2 ff ff             call 0x8040a0        ; ret 8 consumes both args
```

**證明**：`0x489920` 的單一 `ret` 不清理 8-byte caller args，且回傳固定 `0xFC10D0`。所以 `0x807DA4` 的 context+`0xA080` 是傳給 `0x8040A0` 的第二個參數，而非傳給 getter 用來選擇 owner。應把 T10-108 第2節「`0x489920` 返回值/參數仍待確認」改讀為本段已閉合的資料流；不改原稿，保留此增量。

## 2. `0x8040A0`：分類別的雙 bucket append 與只有 category==2 的額外 signal

```asm
008040a3 8b 87 24 01 00 00          mov eax,[edi+0x124]    ; owner mutex/lock handle
008040aa 8b 5d 0c                   mov ebx,[ebp+0xc]      ; category
008040af ff 15 4c 22 bd 00          call dword [0xBD224C] ; lock-like imported call
008040b5 33 d2                      xor edx,edx
008040b7 38 94 3b 28 01 00 00       cmp [ebx+edi+0x128],dl ; toggle[category]
008040c1 0f 94 c2                   sete dl
008040c4 51                         push ecx                ; &arg8 record
008040c5 8d 04 5a                   lea eax,[edx+ebx*2]
008040c8 8d 04 40                   lea eax,[eax+eax*2]
008040cb 8d 34 c7                   lea esi,[edi+eax*8]    ; bucket stride 0x18
008040ce e8 8d 01 00 00             call 0x804260          ; append item
008040d3 8b 8f 24 01 00 00          mov ecx,[edi+0x124]
008040da ff 15 48 22 bd 00          call dword [0xBD2248]  ; unlock-like
008040e1 83 fb 02                   cmp ebx,2
008040e5 75 0d                      jne 0x8040f4
008040e7 8b 97 20 01 00 00          mov edx,[edi+0x120]   ; event handle
008040ee ff 15 d0 20 bd 00          call dword [0xBD20D0] ; signal-like imported call
008040f5 c2 08 00                   ret 8
```

`bucket = singleton + 0x18 * (2 * category + !toggle[category])`；鎖由 `owner+0x124` 取得；`0x804260` 使用傳入 record pointer 的地址。只對 `category == 2` 走 owner+`0x120` 的額外 IAT call。**單看 IAT 地址不足以宣告 API 名稱**；上述為訊號/鎖的行為性暫名，精確 import name 尚未在本段從 import descriptor 核對。這個特例提供 category2 優先被喚醒的結構依據，但不等於必定先被派送、也不表示 Server 接受攻擊。

同 `0x804100` consumer：其 `0x80410D` 從 `owner+0x128+category` 取 toggle；`0x80411F` 查當前 bucket `+0x10` 的 count；空時 `0x804196` 計算對應另一 bucket，若它也空 `0x804253` 回 AL=0；若另一 bucket 有值 `0x8041BA..0x8041D8` 修改 toggle，`0x8041E7` 以另一 bucket 呼叫 `0x542210` 取 item，於 `0x804225` 存到 caller output 並於 `0x80423D` 減 count。`0x804100` 中的分類仍是 argC，不是 frame 的 header opcode。

## 3. 零長度 record 改走另一條專用 queue：`0x8076F0`

```asm
008076f3 8b 45 08                  mov eax,[ebp+8]
008076f6 c7 00 00 00 00 00         mov dword [eax],0
008076fc c7 40 04 00 00 00 00      mov dword [eax+4],0
00807703 8b 47 58                  mov eax,[edi+0x58]
00807708 ff 15 4c 22 bd 00         call dword [0xBD224C]
0080770e 8d 4d 08                  lea ecx,[ebp+8]
00807712 8d 77 3c                  lea esi,[edi+0x3c]
00807715 e8 46 cb ff ff            call 0x804260
0080771a 8b 57 58                  mov edx,[edi+0x58]
0080771d ff 4f 54                  dec dword [edi+0x54]
00807721 ff 15 48 22 bd 00         call dword [0xBD2248]
00807729 c2 04 00                  ret 4
```

分支來自 `0x807D8D jne 0x807D9E` 的反面：如果長度為 0，先把 `record+0` 指向 context，再在 `0x8076F0` 將待 append record 的前兩 DWORD 設為0，轉送 `edi+0x3C` 為 base 的單一容器，並減少 `edi+0x54` 計數；**不會呼叫一般的 `0x8040A0`**。`0x804310` 前置 getter 的 `EDI=owner` 必須與 `0x8076F0` 的 EDI 相配；此次 native 指令已確認，但還沒從所有 callers 驗證 owner class 的 lifetime。零長度 record 是內部控制/釋放標記的可能性，不可宣稱是正常長度為0的 Server opcode，也不能斷言某 packet 丟失。

## 4. 事件來源與玩家情境驗收矩陣

| 玩家情境 | Client 已證條件 | C→S | S→C / queue | 動作結果 | 責任／證據 |
|---|---|---|---|---|---|
| 站立短按 Z（實際 bank 映射 Key44→ID13） | 前段 T10-101..103 證有條件 000A 產生；本段沒有改輸入決策 | 000A 在 gate 通過時存在發送準備路徑；socket send 次數未知 | 本段證明非零 frame record 可入分類 queue，但**未證其等同 000A 回覆** | 預播／Server 回覆→motion 因果未知 | Server 合法性、連段時窗不得臆造 |
| 收到非零 payload frame 且分類2 | `0x807D9E` 分支取 context+0xA080，`0x8040A0` append 並額外喚醒 owner+0x120 | 無新增上行證據 | 有條件分類2 queue→`0x804740`→`0x4930E0` 應用 key | 是否動作依 key/handler，這裡未證 | Client 分類喚醒行為已確認 |
| 收到非零 payload frame 且分類非2 | 一般 append 而不執行 category2 額外訊號 | 無新增 | 不可假設其他 callback 無結果 | 未知 | Client 封包分類非 wire opcode |
| 解出的 record len0 | `0x807D8D` 分歧走 `0x8076F0`，清 header + 單獨 append、計數減一 | 無新增 | 未經一般 category append | 未知；不是攻擊拒絕的證據 | 零長度特殊處理已確認 |
| 施放中再次按 Z 或移動 | 本段未追技能 phase/移動生產者 | 未新增；仍未知是否送出 | 未證有特定回覆與取消 | 未知 | 不使用自創連段時間常數 |

## 5. 第一輪門檻、未解與下段

**第1輪 T10-109 已達實質發現**：對上段未明 getter / classification def-use 給出直接 BIN 校正，並找到 category2 專用同步事件與 zero-length 分流，屬於可重現的新 native 控制與資料流；因此 T10-109-2、-3 **未啟動**。此停止理由僅適用本段有界主題，不等同 P0 網路→motion 完整驗收。

下段 T10-110 最優先：核對 `0x807B60` 的確切函式起點及直接 caller、owner/`+0xA080` 分類 writer；識別 `0xBD20D0` IAT 並確認 category2 的事件 consumer；找出 normal socket recv/overlapped completion→frame caller。另沿 `0x4930E0` 的 packet key13 / motion handler 回溯實際 actor motion；最後跨 T02 網路系統核對不假造 recv 的實際功能。`0x8076F0` owner 的 `+0x54` 計數代表什麼仍未知。完整原版 Server 判斷／wire 樣本未取得。

## 6. 重現命令

```bash
sha256sum Tartaros.bin
objdump -D -Mintel --start-address=0x489920 --stop-address=0x489982 Tartaros.bin
objdump -D -Mintel --start-address=0x807d7f --stop-address=0x807dc0 Tartaros.bin
objdump -D -Mintel --start-address=0x8040a0 --stop-address=0x8040f8 Tartaros.bin
objdump -D -Mintel --start-address=0x804100 --stop-address=0x804260 Tartaros.bin
objdump -D -Mintel --start-address=0x8076f0 --stop-address=0x80772c Tartaros.bin
```