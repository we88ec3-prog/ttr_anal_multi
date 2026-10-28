# T16-92 — KR Quest XML 全域 owner、真正 read-side consumer 與資料邊界（BIN-first）

研究者 `chatgpt-web roy`；2026-10-28 20:43:41 Asia/Taipei。範圍：T16，KR Client 靜態唯讀分析。**本段突破是 Quest 靜態資料的 owner→reader 閉合，不是任務接取封包閉合。**

## 1. 一手來源及地址換算

- `/mnt/data/Tartaros.bin` 實測 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `/mnt/data/Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- x86 PE `.text` VA 0x00401000/raw 0x400：text raw = VA−0x00400C00；`.rdata` raw=VA−0x00401A00；`.data` raw=VA−0x00402800。
- 靜態 `objdump -D -M intel` + original raw `E8 rel32` target scan + exact little-endian global VA reference scan。由 GitHub `main` T16-91 及 T16-90 導航，不以筆記取代機器碼。
- 先讀專案 `02-PROJECT-SHARED-INSTRUCTIONS.md`、`03-PROJECT-T16-INSTRUCTIONS.md`。未啟動/修改 Client，無原版 Server/封包擷取，未修改其他 Task。

## 2. T16-92 第一輪 — 首次確定 Quest XML loader 所建物件的全域 owner

原版 `0x004FFE60` 為編譯器生成風格的 lazy static initialization。分配 0x10-byte object，呼叫 T16-89 已知的 `0x504370`（後者按順序呼叫 `0x504740` QuestInfo XML loader 與 `0x505570` QuestTalk XML loader），並將返回物件寫入 global `[0x00FB114C]`：

```asm
4ffe87: c7 45 ec a0 b2 fa 00    mov DWORD PTR [ebp-0x14],0xfab2a0
4ffe93: 6a 10                   push 0x10
4ffe95: c7 05 a0 b2 fa 00 08 db c0 00  mov DWORD PTR ds:0xfab2a0,0xc0db08
4ffe9f: e8 c4 13 39 00          call 0x891268
4ffea7: 89 45 f0                mov DWORD PTR [ebp-0x10],eax
4ffeae: 3b c6                   cmp eax,esi
4ffeb0: 74 09                   je 0x4ffebb
4ffeb2: 8b f8                   mov edi,eax
4ffeb4: e8 b7 44 00 00          call 0x504370
4ffeb9: eb 02                   jmp 0x4ffebd
4ffebb: 33 c0                   xor eax,eax
4ffebd: a3 4c 11 fb 00          mov ds:0xfb114c,eax
4ffec2: 89 35 50 11 fb 00       mov DWORD PTR ds:0xfb1150,esi
4ffece: 89 35 58 11 fb 00       mov DWORD PTR ds:0xfb1158,esi
4ffed4: 89 35 60 11 fb 00       mov DWORD PTR ds:0xfb1160,esi
4ffeda: 89 35 64 11 fb 00       mov DWORD PTR ds:0xfb1164,esi
4ffee0: 89 35 68 11 fb 00       mov DWORD PTR ds:0xfb1168,esi
4fff2c: e8 7f 21 00 00          call 0x5020b0
4fff31: e8 ba 39 00 00          call 0x5038f0
```

`0x004FFE60` 初始化完成後 `[FB114C]` 是 Quest 相關 object 的**可讀全域 owner 候選且已由下方多個 read xref 直接證明**。它是否僅含 XML 靜態表或是否也持動態狀態，不能只憑全域名字猜。`0xFB1150…` 其他欄位被初始化零，不能直接冠名為 Quest state。

原始 E8 rel32 scan `0x504370` 直接 call 僅 `0x004FFEB4`（指令邊界透過 objdump 確認）；字元序列在 `.text` 的結構化 immediate 掃描 `[FB114C]` 全 BIN 共有 15 個數值引用候選，以下只列經反組譯核實的讀／寫位置。數量是靜態掃描命中，不等同 15 個確證 caller。

## 3. T16-92 第一輪延伸 — Global 的實際 reader 0x62E579 與 0x62E5D6

```asm
62e535: f6 05 9c b2 fa 00 01   test BYTE PTR ds:0xfab29c,0x1
62e542: 75 23                   jne 0x62e567
62e544: 83 0d 9c b2 fa 00 01   or DWORD PTR ds:0xfab29c,0x1
62e552: e8 09 19 ed ff         call 0x4ffe60
62e567: 89 75 d0                mov DWORD PTR [ebp-0x30],esi
62e56a: 8b 35 4c 11 fb 00      mov esi,DWORD PTR ds:0xfb114c
62e570: 8d 4d d0                lea ecx,[ebp-0x30]
62e573: 51                      push ecx
62e574: 8d 45 c8                lea eax,[ebp-0x38]
62e577: 8b ce                   mov ecx,esi
62e579: e8 a2 57 ed ff         call 0x503d20
62e57e: 8b 4d c8                mov ecx,DWORD PTR [ebp-0x38]
62e581: 3b 4e 04                cmp ecx,DWORD PTR [esi+0x4]
62e584: 74 08                   je 0x62e58e
62e586: 83 c1 10                add ecx,0x10
62e589: 89 4d d0                mov DWORD PTR [ebp-0x30],ecx
62e58e: c7 45 d0 00 00 00 00   mov DWORD PTR [ebp-0x30],0x0
62e595: f6 05 9c b2 fa 00 01   test BYTE PTR ds:0xfab29c,0x1
62e5ac: e8 af 18 ed ff         call 0x4ffe60
62e5be: 8b 35 4c 11 fb 00      mov esi,DWORD PTR ds:0xfb114c
62e5c7: 8b 55 cc                mov edx,DWORD PTR [ebp-0x34]
62e5ce: 50                      push eax
62e5d1: 8b ce                   mov ecx,esi
62e5d6: e8 45 57 ed ff         call 0x503d20
62e5db: 8b 76 04                mov esi,DWORD PTR [esi+0x4]
62e5de: 8b 45 c8                mov eax,DWORD PTR [ebp-0x38]
62e5e1: 3b c6                   cmp eax,esi
62e5e3: 74 05                   je 0x62e5ea
62e5e5: 8d 78 10                lea edi,[eax+0x10]
62e5ea: 33 ff                   xor edi,edi
```

**資料流：** guarded lazy init `0x4FFE60` → `[FB114C]` → `ECX` → `0x503D20` map lookup。其回傳 node pointer 與 owner sentinel `[owner+4]` 比較；成功時計算 `node+0x10` 的資料值地址，失敗清零。後續 `0x62E5F7` 對查得資料 `+0x4C` 所在的 UTF-16 文字建立暫存字串，`0x62E659 call 0x759ED0` 使用該文字；見以下原生片段。

```asm
62e5ec: 8b 55 d0                mov edx,DWORD PTR [ebp-0x30]
62e5ef: 85 d2                   test edx,edx
62e5f1: 0f 84 95 00 00 00       je 0x62e68c
62e5f7: 83 c2 4c                add edx,0x4c
62e5fa: bf 08 00 00 00          mov edi,0x8
62e5ff: 39 7a 14                cmp DWORD PTR [edx+0x14],edi
62e604: 8b 12                   mov edx,DWORD PTR [edx]
62e620: 66 8b 08                mov cx,WORD PTR [eax]
62e629: 75 f5                   jne 0x62e620
62e62f: 50                      push eax
62e630: 52                      push edx
62e631: 8d 4d ac                lea ecx,[ebp-0x54]
62e634: e8 27 3b dd ff          call 0x402160
62e639: 8b b3 08 01 00 00       mov esi,DWORD PTR [ebx+0x108]
62e63f: 81 c6 e8 00 00 00       add esi,0xe8
62e651: 6a 7d                   push 0x7d
62e653: 6a 7b                   push 0x7b
62e655: 8d 55 ac                lea edx,[ebp-0x54]
62e658: 52                      push edx
62e659: 56                      push esi
62e65a: e8 71 b8 12 00          call 0x759ed0
62e677: 8b 8b 08 01 00 00       mov ecx,DWORD PTR [ebx+0x108]
62e67f: 8b 82 c8 00 00 00       mov eax,DWORD PTR [edx+0xc8]
62e685: ff d0                   call eax
```

此 UI 文字的具體控件角色和任務接取關係需另驗；函式 `0x759ED0` 的完整參數型別未知。這段是**已確認存在 read-side consumer 與字串展示用途候選**，不是收封包後改動動態任務狀態的證據。

## 4. T16-92 第二輪 — 獨立 reader 0x5B6C86 與比較條件

另一組 caller 在不同 `.text` 區域，直接從同一 global 取 owner，再以 `EBX+0x14` 的值當查找鍵：

```asm
5b6c45: 83 0d 9c b2 fa 00 01  or DWORD PTR ds:0xfab29c,0x1
5b6c54: e8 07 92 f4 ff         call 0x4ffe60
5b6c6e: 8b 43 14                mov eax,DWORD PTR [ebx+0x14]
5b6c71: 8b 35 4c 11 fb 00       mov esi,DWORD PTR ds:0xfb114c
5b6c77: 8d 4c 24 14             lea ecx,[esp+0x14]
5b6c7b: 89 44 24 14             mov DWORD PTR [esp+0x14],eax
5b6c7f: 51                      push ecx
5b6c80: 8d 44 24 1c             lea eax,[esp+0x1c]
5b6c84: 8b ce                   mov ecx,esi
5b6c86: e8 95 d0 f4 ff          call 0x503d20
5b6c8b: 8b 76 04                mov esi,DWORD PTR [esi+0x4]
5b6c8e: 8b 44 24 18             mov eax,DWORD PTR [esp+0x18]
5b6c92: 3b c6                   cmp eax,esi
5b6c94: 74 6c                   je 0x5b6d02
5b6c96: 8d 70 10                lea esi,[eax+0x10]
5b6c99: 85 f6                   test esi,esi
5b6c9b: 74 65                   je 0x5b6d02
5b6cd0: 8b 53 14                mov edx,DWORD PTR [ebx+0x14]
5b6ce4: e8 37 f8 07 00          call 0x636520
5b6ce9: 8b 8f 24 02 00 00       mov ecx,DWORD PTR [edi+0x224]
5b6cf0: e8 1b 33 19 00          call 0x74a010
5b6cf5: 8b 97 24 02 00 00       mov edx,DWORD PTR [edi+0x224]
5b6cfd: e8 fe 00 fe ff          call 0x596e00
```

可確定：相同 Quest global owner 被另一 consumer 搜尋，**只在找到有效 node** 分支呼叫 `0x636520`、`0x74A010`、`0x596E00`；這是 state/UI 相關本機 consumer 候選，但動作類型（open detail/dialogue/select）不可僅依地址或相鄰 code 判定。

另外獨立 caller `0x62F719`：

```asm
62f706: 8b 35 4c 11 fb 00      mov esi,DWORD PTR ds:0xfb114c
62f717: 8b ce                   mov ecx,esi
62f719: e8 02 46 ed ff         call 0x503d20
62f71e: 8b 45 ec                mov eax,DWORD PTR [ebp-0x14]
62f721: 3b 46 04                cmp eax,DWORD PTR [esi+0x4]
62f724: 74 05                   je 0x62f72b
62f726: 83 c0 10                add eax,0x10
62f72b: 33 c0                   xor eax,eax
62f72d: 89 45 f0                mov DWORD PTR [ebp-0x10],eax
62f730: 85 c0                   test eax,eax
62f732: 74 16                   je 0x62f74a
62f734: 39 78 04                cmp DWORD PTR [eax+0x4],edi
62f737: 75 11                   jne 0x62f74a
62f73c: 8d 45 f0                lea eax,[ebp-0x10]
62f745: e8 c6 45 e1 ff         call 0x443d10
62f74a: 83 c3 02                add ebx,0x2
62f74d: 81 fb 98 11 fb 00      cmp ebx,0xfb1198
62f753: 0f 8c 48 ff ff ff      jl 0x62f6a1
```

**新資料流：** 有以 `[FB1198]` 作迴圈界線、每輪 `EBX += 2` 的其他數據源，經 Quest global 取某個 key，再檢查讀回值 `+4 == EDI`，符合則把 `node+0x10` 傳給 `0x443D10`。這是 Quest XML 資料對本地列表/過濾條件的讀取；`[FB1198]` 的本體與此 loop 的業務語意，尚需追查，不將其宣告成 Quest list S→C snapshot。

## 5. 0x503D20 的精確性與多個 caller 邊界

```asm
503d20: 55                      push ebp
503d23: 51                      push ecx
503d25: 8b 5d 08                mov ebx,DWORD PTR [ebp+0x8]
503d29: 8b f1                   mov esi,ecx
503d2b: 8b 56 04                mov edx,DWORD PTR [esi+0x4]
503d2e: 8b 4a 04                mov ecx,DWORD PTR [edx+0x4]
503d31: 80 b9 b5 00 00 00 00    cmp BYTE PTR [ecx+0xb5],0x0
503d3b: 8b 3b                   mov edi,DWORD PTR [ebx]
503d40: 39 79 0c                cmp DWORD PTR [ecx+0xc],edi
503d43: 7d 05                   jge 0x503d4a
503d45: 8b 49 08                mov ecx,DWORD PTR [ecx+0x8]
503d4a: 8b d1                   mov edx,ecx
503d4c: 8b 09                   mov ecx,DWORD PTR [ecx]
503d58: 8b 4e 04                mov ecx,DWORD PTR [esi+0x4]
503d5e: 3b d1                   cmp edx,ecx
503d62: 8b 33                   mov esi,DWORD PTR [ebx]
503d64: 3b 72 0c                cmp esi,DWORD PTR [edx+0xc]
503d6e: 5e                      pop esi
503d6f: 89 08                   mov DWORD PTR [eax],ecx
503d75: c2 04 00                ret 0x4
503d78: 89 4d fc                mov DWORD PTR [ebp-0x4],ecx
503d81: 89 08                   mov DWORD PTR [eax],ecx
503d87: c2 04 00                ret 0x4
```

此 lookup 的 sentinel/節點標記偏移 **`+0xB5`**，與 T16-91 所述 0x30-byte map node `+0x2D` 不同。前段 T16-91 中 0x505870 的 0x30-byte node 是**另一個映射／容器**，不可將兩者結構混同。全域 Quest owner 0x10 bytes 指向的主 map 其 sentinel 在 `owner+4`，符合 T16-89 的 0xB8 bytes sentinel node。**本段新增明確區分 Quest 主資料 map 與 QuestInfo 額外 key→UTF16 字串 map。**

## 6. 三輪門檻

- **T16-92（第一輪）**：關閉此前未知的 owner/consumer 關係：`0x4FFE60 → 0x504370 → QuestInfo+QuestTalk XML → [0xFB114C] → 0x503D20 → 0x62E579/0x62E5D6`；且確認查找成功與失敗分支。這是不同於重新敘述 loader 的重大原生上下游發現。依專案條件第 2、3 輪非強制。
- **T16-92-2（第二輪）**：實際擴展 `0x5B6C86` 的另一種讀取情境，與 `0x62F719` 對欄位 `+4` 的比較與條件性 consumer，釐清多個本地 consumer。
- **T16-92-3**：未啟動（已在前兩輪達成完整重大新鏈）。

## 7. 玩家情境與 Client↔Server 證據矩陣

| 情境 | Client 本地 gate / 現存資料 | C→S opcode/length | S→C handler / fields | Client 狀態/UI | Server 相容開發 |
|---|---|---|---|---|---|
| 啟動載入 QuestInfo/QuestTalk | 全域 `[FB114C]` lazy initialization 加載 XML；0x503D20 可用 key 查找 | unknown | unknown | 主 Quest map 已有讀取者；不是動態狀態證據 | 不憑 XML loader 發明通訊 |
| 查看某 Quest 資料 | `0x62E579` 找主 map node、取 string 並交 UI helper | unknown | unknown | 本地文字處理已證、具體 UI 元素 unknown | 尚無特殊協定證據 |
| 用其他物件指定 key 操作 | `0x5B6C86` 從 `[EBX+0x14]` 查找，存在後呼叫其他本地 method | unknown | unknown | 部分確認；事件業務意義待查 | unknown |
| NPC 接取/交付任務 | handler 未定位 | unknown | unknown | Quest 動態 cache writer 未定位 | 由實際原版 Client request/response 再開發 |
| Quest16→Quest15 解鎖 | 前置 XML values unavailable | unknown | unknown | unknown | 原版 Server 狀態裁決未知 |

## 8. 後續 T16-93

直接由 `0x5B6C86 → 0x636520/0x596E00` 的已知成功分支查 UI 行為是否有 Quest accept producer；另追 `0x62E579 → 0x759ED0` 的 UI 寫入是否更新任務標記，再比對 T02 已知 packet queue/dispatcher。從其他同屬 `[FB114C]` 的 direct xrefs 追讀者，與真正 Quest cache writer 區分。**不得把本地 Quest XML node 地址當 wire opcode，未找到發包 ≠ 沒有發包。**

## 9. text VA/raw 速查

| VA | raw |
|---|---|
| 0x004FFE60 | 0x000FF260 |
| 0x004FFEB4 | 0x000FF2B4 |
| 0x00504370 | 0x00103770 |
| 0x00503D20 | 0x00103120 |
| 0x005B6C86 | 0x001B6086 |
| 0x0062E579 | 0x0022D979 |
| 0x0062F719 | 0x0022EB19 |