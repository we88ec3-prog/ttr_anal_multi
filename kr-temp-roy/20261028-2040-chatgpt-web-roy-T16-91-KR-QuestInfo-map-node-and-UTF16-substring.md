# T16-91 — KR QuestInfo 靜態容器 map 節點、UTF-16 substring 與狀態 writer 證據邊界

> chatgpt-web roy，2026-10-28 約 20:40 Asia/Taipei（精確秒數以 GitHub commit 為準）。接續已驗證的 T16-90。本文只處理 KR T16 原生 Client。

## 0. 研究對象與原件

- `/mnt/data/Tartaros.bin` 實際 SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；大小 12,472,320 bytes。
- `/mnt/data/Tartaros.exe` 實際 SHA256：`03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- BIN 是 PE32 x86；.text VMA `0x00401000` raw `0x400`，故本段 .text 所有原生 VA 的 raw = VA − `0x00400C00`；.rdata VA/raw 差 `0x00401A00`（不沿用早期錯誤映射）。
- 靜態唯讀 objdump：`objdump -D -Mintel --start-address=... --stop-address=... /mnt/data/Tartaros.bin`。沒有執行、修改或附加 Client，沒有原始 Server 或網路抓包；GitHub 研究記錄只供導航。
- 已先讀 `02-PROJECT-SHARED-INSTRUCTIONS.md`、`03-PROJECT-T16-INSTRUCTIONS.md`，承接 `kr-temp-roy/...T16-90-KR-QuestInfo-QuestTalk-map-writers.md`。不改其他 Task owner/catalog。

## 1. 第一輪 T16-91 — 0x4026E0 實際為 UTF-16 字串截取／複製，不是 Quest state writer

T16-90 將 `0x4026E0` 列為「資料處理」及尚待驗證的複製範圍；這次直接展開其 .text 指令，已可確認是 generic string helper：`this=ECX` 目的字串、`[ebp+8]` 來源字串、`[ebp+0xC]` 來源起點、`[ebp+0x10]` 欲複製的最大字元數。

```asm
4026e0: push ebp
4026e1: mov ebp,esp
4026e4: mov ebx,DWORD PTR [ebp+0xc]   ; start
4026e8: mov esi,ecx                   ; destination
4026ea: mov ecx,DWORD PTR [ebp+0x8]   ; source
4026ee: mov edi,DWORD PTR [ecx+0x10]  ; source UTF16 length
4026f1: cmp edi,ebx
4026f3: jae 0x4026ff
4026f5: push 0xbed210
4026fa: call 0x87db7d                ; start > len: range diagnostic
4026ff: mov eax,DWORD PTR [ebp+0x10] ; requested count
402702: sub edi,ebx                   ; available chars
402704: cmp eax,edi
402706: cmovb edi,eax                 ; min(requested,available)
402709: cmp esi,ecx                   ; source == destination?
40270b: jne 0x40272c
40270d: push 0xffffffff
40270f: add edi,ebx
402711: push edi
402712: mov ecx,esi
402714: call 0x402400
402719: push ebx
40271a: push 0x0
40271c: mov ecx,esi
40271e: call 0x402400
402723: pop edi
402724: mov eax,esi
402729: ret 0xc
40272c: cmp edi,0x7ffffffe
402732: jbe 0x40273e
402734: push 0xbed200
402739: call 0x87db30
40273e: mov eax,DWORD PTR [esi+0x14] ; destination capacity
402741: cmp eax,edi
402743: jae 0x40276d
402745: mov eax,DWORD PTR [esi+0x10]
402748: push eax
402749: push edi
40274a: mov ecx,esi
40274c: call 0x402490
402797: mov eax,esi
402799: mov edx,DWORD PTR [ebp+0xc]
40279c: lea ebx,[edi+edi]             ; UTF16 byte length
40279f: push ebx
4027a0: lea ecx,[ecx+edx*2]          ; source+start*2
4027a3: push ecx
4027a4: push eax
4027a5: call 0x89dbd0                ; byte-copy helper
4027ad: cmp DWORD PTR [esi+0x14],0x8
4027b1: mov DWORD PTR [esi+0x10],edi ; length in UTF16 code units
4027b6: mov eax,DWORD PTR [esi]
4027ba: mov WORD PTR [ebx+eax],0x0  ; terminating WCHAR 0
4027c4: ret 0xc
4027c7: mov eax,esi
4027c9: xor edx,edx
4027cb: mov WORD PTR [ebx+eax],dx
4027d4: ret 0xc
```

注意中段條件跳轉有多條 capacity/zero-length/heap 路徑；以上是**指令摘錄，不等同從第一行到最後一行無分支連續執行**。`+0x10` 是字串長度，`+0x14` 是容量，容量 8 以下採 small-string buffer，這些是**字串物件**欄位，不是 QuestInfo row 欄位。

### 1.1 實際 QuestInfo loader 中的呼叫 ABI

```asm
50538b: lea edx,[esp+0x1c]
50538f: lea ecx,[esp+0xcc]
505396: call 0x505870            ; get or create tree map value
50539b: push 0xffffffff          ; copy to end
50539d: push 0x0                 ; source start 0
50539f: lea edx,[esp+0x118]
5053a6: push edx                 ; source temporary UTF16 string
5053a7: mov ecx,eax              ; target is returned map value
5053a9: call 0x4026e0           ; copy UTF16 text, no wire/state logic
5053b6: cmp DWORD PTR [esp+0x124],0x8
5053be: jb 0x5053d0
5053c0: mov eax,DWORD PTR [esp+0x110]
5053c7: push eax
5053c8: call 0x89120c           ; release temporary heap buffer
```

因此 `0x505870` 返回的是可寫入 UTF-16 string 的指標，與 QuestInfo 原生 XML 行中的文字資料建置有關；不能再把 `0x4026E0` 認作 quest state writer。

## 2. 第二輪 T16-91-2 — 0x505870 的搜尋、插入與值指標

`0x505870` 使用 `[ECX+4]` 的 tree sentinel，從 `[sentinel+4]` 起搜尋，每個節點以 `node+0xC` 的 signed integer key 與 `[EDX]` 比較，以 `node+0x2D` 判斷是否為 sentinel。遇到已存在的 key，回傳 `node+0x10`；不存在則建立。

```asm
50589a: mov esi,ecx
50589c: mov ecx,DWORD PTR [esi+0x4]  ; sentinel
50589f: mov eax,DWORD PTR [ecx+0x4]
5058a2: cmp BYTE PTR [eax+0x2d],0x0
5058aa: mov ecx,DWORD PTR [edx]
5058b0: cmp DWORD PTR [eax+0xc],ecx
5058b5: mov eax,DWORD PTR [eax+0x8]
5058ba: mov edi,eax
5058bc: mov eax,DWORD PTR [eax]
5058be: cmp BYTE PTR [eax+0x2d],0x0
5058c4: cmp edi,DWORD PTR [esi+0x4]
5058c9: mov eax,DWORD PTR [edx]
5058cb: cmp eax,DWORD PTR [edi+0xc]
5058ce: jge 0x505966                   ; existing key
5058e9: mov edx,DWORD PTR [edx]        ; absent key
505903: call 0x402800                 ; construct temporary string
505908: lea edx,[ebp-0x30]
50590c: mov ecx,esi
505912: call 0x5063f0                 ; allocate 0x30 node
505917: push edi
50591e: call 0x505e40                 ; RB-tree insertion routing
505923: mov esi,DWORD PTR [ebp-0x50]
505961: lea eax,[esi+0x10]           ; newly inserted value
505966: lea eax,[edi+0x10]           ; existing value
505969: mov ecx,DWORD PTR [ebp-0xc]  ; SEH restore
505983: ret
```

沒有理由把這個 RB-tree 的 key 當成動態 Quest 狀態，也沒有追到 WSASend／WSARecv。此處是 **本機 static Quest XML 的 key → UTF-16 value mapping**。

## 3. 第三輪 T16-91-3 — 實際 0x30 bytes 節點建構與插入 helper

### 3.1 0x5063F0 新節點

```asm
50641b: mov ebx,DWORD PTR [ebp+0x8]
506420: push 0x30
506422: call 0x891268                   ; allocate 0x30 bytes
506435: mov eax,DWORD PTR [edi+0x4]
506438: mov DWORD PTR [esi],eax
50643a: mov ecx,DWORD PTR [edi+0x4]
50643d: mov DWORD PTR [esi+0x4],ecx
506440: mov eax,DWORD PTR [edi+0x4]
506443: mov DWORD PTR [esi+0x8],eax
506446: lea eax,[esi+0xc]
50644c: mov WORD PTR [esi+0x2c],dx
50645e: mov ecx,DWORD PTR [ebx]
506460: mov DWORD PTR [eax],ecx       ; key at node+0xC
506462: lea ecx,[eax+0x4]              ; string at node+0x10
506468: mov DWORD PTR [ecx+0x14],0x7   ; initial capacity
50646f: mov DWORD PTR [ecx+0x10],0x0   ; initial length
506473: mov WORD PTR [ecx],dx
506476: call 0x402800                 ; copy value string
50647b: mov eax,esi
50648e: ret 0x4
```

因此 node layout 有界：
```text
node+0x00, +0x04, +0x08   3 tree link pointers (initial sentinel)
node+0x0C                 signed integer key
node+0x10..+0x27          UTF-16 string object (capacity+0x14 relative)
node+0x2C                 flags/color or reserved bytes (exact semantic unknown)
allocation total         0x30 bytes
```
`0x505E40` 從 `this+0x8` 看容器 count、`this+0x4` 看 sentinel，依 node `+0xC` 比較決定 `0x480760` 插入方向；它還有重複鍵處理，不能認為 XML 行一定逐行新增節點。

```asm
505e4e: cmp DWORD PTR [edi+0x8],0x0
505e56: mov eax,DWORD PTR [edi+0x4]
505e59: push esi
505e5a: push 0x1
505e5c: push ebx
505e5d: call 0x480760
505e77: mov ecx,DWORD PTR [esi+0xc]
505e7a: cmp ecx,DWORD PTR [eax+0xc]
505e83: push esi
505e84: push 0x1
505e86: push ebx
505e87: call 0x480760
505e9b: mov eax,DWORD PTR [ecx+0x8]
505e9e: mov edx,DWORD PTR [eax+0xc]
505eaa: push esi
505eab: push 0x0
505ead: push ebx
505eae: call 0x480760
```

這是真正的 **XML → keyed RB-tree node → UTF-16 value** 新功能鏈，不是網路 Quest completion。

## 4. 三輪結果與門檻

| 輪次 | 實證進展 | 是否達重大進展 |
|---|---|---|
| T16-91 | 重新解碼 0x4026E0 UTF-16 substring 實際函式，排除先前的 Quest writer 懷疑 | 排誤證據，仍待下游 |
| T16-91-2 | 0x505870 key lookup / create / return value pointer 完整分支 | 已閉合核心關係 |
| T16-91-3 | 0x5063F0 分配 0x30 node、key/string 佈局，0x505E40 插入 | 完整三輪鏈 |

以上三輪均針對同一問題且各有原生新證據；達標後結束本正式段，下一段 **T16-92**。

## 5. Client/Server 情境矩陣

| 玩家情境 | Client gate 或靜態資料 | C→S | S→C | Client 任務狀態／UI | Server 相容需求 |
|---|---|---|---|---|---|
| 啟動載入 QuestInfo | XML loader key 查詢/插入 + UTF16 value 文字資料已確認 | unknown | unknown | 靜態表完成載入，是否應用到 UI 待驗證 | 不從資源表建立虛構封包 |
| NPC 接取 Quest | 操作 callback unknown；靜態 Quest info 可用 | unknown | unknown | 動態 cache writer unknown | 待 Client wire 證據 |
| 完成或交付 Quest | XML CompleteAction 解析可見、consumer unknown | unknown | unknown | 任務完成狀態 writer unknown | Server 原版算法未知 |
| Quest16→Quest15 解鎖 | 靜態資料與依賴的具體值未查 | unknown | unknown | unknown | 前置條件需原始來源 |

## 6. 下一段導航

1. T16-92 **優先**由 QuestInfo 真正 key/value 的 read-side xref 或 NPC 接任務 C→S caller、Quest cache S→C writer 查起，而非繼續研究 generic STL container。
2. 追 `0x504370` caller 與 QuestInfo tree owner consumer；判明是否存在本機直接計算「可接任務」或只呈現 Server snapshot。
3. 若 3 輪查無有界 Quest 業務封包鏈，明示 unknown，不得把 XML ID、UI callback、`0x40` local payload 直接定義成 wire opcode。
4. 保留原生/AI fixture 分界，不修改 T02/T07/T14/T15。

## 7. 地址 raw mapping

| VA | .text raw |
|---|---|
| 0x4026E0 | 0x1AE0 |
| 0x402400 | 0x1800 |
| 0x402490 | 0x1890 |
| 0x505396 | 0x104796 |
| 0x5053A9 | 0x1047A9 |
| 0x505870 | 0x104C70 |
| 0x505E40 | 0x105240 |
| 0x5063F0 | 0x1057F0 |
