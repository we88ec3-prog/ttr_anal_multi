# KR T16-70 — 出站佇列消費、兩種封裝模式與入站 frame parser（BIN-first）

- 時間：2026-10-28T17:51:41+08:00；研究員：chatgpt-web roy；**僅 KR**。
- 唯讀原始檔：`/mnt/data/Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- PE `.text` VA 0x401000 / raw 0x400；`.rdata` VA 0xBD2000 / raw 0x7D0600；`.data` VA 0xD61000 / raw 0x95E800。以下 `.text` raw=VA−0x400C00。用 `objdump -D -Mintel -b pei-i386 -m i386 --start-address=... --stop-address=...` 離線核證；未執行或 patch 目標。
- 前段 [T16-69](20261028-170434-chatgpt-web-roy-T16-69-KR-virtual-dispatch-and-outbound-queue.md) 已確認 `0x4AA4D0 → [0xFBA854] vtable+0x10=0x8069A0 → 0x8060D0 → 0x806060`，四位元組原始內容 `40 00 nn nn` 條件式進入 `[connection+0xA074]` 佇列；本段刻意不重複解讀該本地 tag 為已驗證 wire opcode。

## 1. 第 1 輪重大新進展：出站佇列 consumer 與兩種 framing writer

### 1.1 `0x008061A0` 讀取與移除 `[connection+0xA074]` 出站節點

- `0x8061C8` 以 `[ebp+8]` 取得 connection pointer 至 `esi`；`0x8061CB` 讀 `[esi+0xA0D4]` 並透過 `IAT [0xBD224C]` 調用同步原語（實際 API 名稱尚未從 import table 核對）。
- `0x8061E6` 取 `[esi+0xA074]` list sentinel；`0x8061EC` 取首節點至 `ebx`；`0x8061EE` 如首節點==sentinel，跳至 `0x8063BA` 空佇列退出。
- `0x8061F6` 取 `[ebx+8]` 的 data node；`0x8061F9` 讀 `[data+4]` **已排隊的訊息長度**、`0x8061FC` 指到 `[data+8]` payload。
- `0x806202` 讀 byte `[connection+0xA02C]` 作模式選擇：0→`0x807A70`；非零→先試 `0x807830`，若回傳 0 則 fallback `0x807A70`。具體值1、2是否不同，由條件組合看似都走首次 `0x807830`，但尚未完整證明全部 enum 分支。
- `0x80623F` 成功回傳為非零；失敗跳 `0x8063A4`；成功時 `0x80624F` 起從雙向 linked list unlink，再 `0x89120C` 釋放 list node、`dec [connection+0xA078]`。是否完成網路傳送**不能僅因 queue node 被刪除就認定**；此處為複製至另一層待送緩衝的成功。
- `0x80636E` 成功時繼續迴圈直到 list sentinel；`0x8063BA` 解鎖（`[connection+0xA0D4]` 經 IAT `[0xBD2248]`）並回傳。

關鍵反組譯：

```asm
8061c8: mov esi,DWORD PTR [ebp+0x8]
8061cb: mov eax,DWORD PTR [esi+0xa0d4]
8061e0: call DWORD PTR ds:0xbd224c
8061e6: mov eax,DWORD PTR [esi+0xa074]
8061ec: mov ebx,DWORD PTR [eax]
8061ee: cmp ebx,eax
8061f0: je 0x8063ba
8061f6: mov edi,DWORD PTR [ebx+0x8]
8061f9: mov edx,DWORD PTR [edi+0x4]
8061fc: lea eax,[edi+0x8]
806202: movsx eax,BYTE PTR [esi+0xa02c]
806218: je 0x80622f
806223: call 0x807830
806228: test eax,eax
80622a: jne 0x80624f
80622f: mov eax,DWORD PTR [ebp-0x10]
80623a: call 0x807a70
80623f: test eax,eax
806246: je 0x8063a4
80625c: mov eax,DWORD PTR [ebx+0x4]
80625f: mov DWORD PTR [eax],ecx
806266: push ebx
80626a: call 0x89120c
806275: dec DWORD PTR [esi+0xa078]
80636e: cmp ecx,DWORD PTR [edx+0xa074]
806374: jne 0x8061f6
```

### 1.2 `0x00807A70`：4-byte frame，首 16-bit 固定欄位 `0x1A68`、次 16-bit 為原長度

`0x807A84` 讀 `[ebp+0x0C]` 原始 payload length；`0x807A8A` 立即值 `0x1A68` 寫入 `[ebp-2]`；`0x807A93` 將原長度低16位寫入 `[ebp-4]`；兩個局部 word 在記憶體形成 `[length16,0x1A68]`（little-endian；`[ebp-4]` 指向 header 起點）。實際資料寫入是 `0x807AE9 mov [eax],ecx`（其中 `ecx=[ebp-4]`），之後 payload `0x807AF2 memcpy`。

限制：payload length 非零，`len+4 <= 0x1000`，累計 `[edi+0x500C] + len+4 <= 0x4000`，另檢查 write pointer 及末端邊界；回傳 1 才算成功放入更低層的 **connection 內部緩衝** `[edi+0x5004]`，非 OS socket 送出證據。

```asm
807a84: mov edx,DWORD PTR [ebp+0xc]
807a87: lea ebx,[edx+0x4]
807a8a: mov eax,0x1a68
807a8f: mov WORD PTR [ebp-0x2],ax
807a93: mov WORD PTR [ebp-0x4],dx
807a97: cmp ebx,0x1000
807aa3: test edx,edx
807aab: mov ecx,DWORD PTR [edi+0x500c]
807ab1: add ecx,ebx
807ab3: cmp ecx,0x4000
807ae2: mov ecx,DWORD PTR [ebp-0x4]
807ae9: mov DWORD PTR [eax],ecx
807af2: call 0x89dbd0
807afa: add DWORD PTR [edi+0x500c],ebx
807b00: add DWORD PTR [esi],ebx
```

**注意此前段記錄的 4-byte `40 00 nn nn` 是 payload，本段新確認的 `length16 + frame marker 0x1A68` 是另一層 header；這兩種 `0x40` 與 `0x1A68` 不能混成同一 opcode namespace。** 此封裝分支中，對 `RequestStartScenario(n)` 的 payload length=4，若全部 gates 通過，預期內部 buffer 結構為 `04 00 68 1A 40 00 nn nn`（**根據靜態指令的條件式推導，未捕獲實際網路流量**）。

### 1.3 `0x00807830`：6-byte 的另一模式，對資料做異或與校驗累加

- `0x80786D` 計算總長度 `len+6`；`0x807870` 用 `mov dword [ebp-0x101A],0x7D810BBB` 與 `0x80787A mov word [ebp-0x101C],di` 構成六位元組 header，布局（記憶體位址由低到高）：`[len16][BB 0B 81 7D]`。**不可將 0x0BBB、0x7D81 立即視為 quest opcode**。
- `0x8078FD` 讀 payload 首 byte；`0x807901 xor dl,0xB6` 對首輸出 byte 做轉換；接下來 `0x807967...0x80799C` 的迴圈以相鄰輸入位元組 XOR 產生輸出，並累加 16-bit 中間總和；`0x8079BD...0x8079D0` 收尾；`0x8079E9...0x8079F8` 將總和寫入 header 的 `+4` word。需額外對照 `0x807B40` receiver 才能正式表述此分支完整編碼規格與校驗欄位的語意。
- `0x807A02...0x807A25` 將轉換後資料複製到 connection 的 `[+0x5004]` 指向的緩衝區，更新 `[+0x500C]`、`[+0x5004]`；回傳 1 代表進入本地 buffer。未驗證 socket 上是否還有後續 bytes、合併及傳送次數。

```asm
80786d: lea eax,[edi+0x6]
807870: mov DWORD PTR [ebp-0x101a],0x7d810bbb
80787a: mov WORD PTR [ebp-0x101c],di
807887: cmp eax,0x1000
80789a: mov edx,DWORD PTR [esi+0x500c]
8078a2: cmp edx,0x4000
8078fd: mov al,BYTE PTR [ebx]
807901: xor dl,0xb6
807967: mov cl,BYTE PTR [eax]
80796f: xor bl,cl
807974: add WORD PTR [ebp-0x1014],cx
8079e9: mov edx,DWORD PTR [ebp-0x101c]
8079ef: mov ax,WORD PTR [ebp-0x1008]
8079f6: mov DWORD PTR [ecx],edx
8079f8: mov WORD PTR [ecx+0x4],ax
807a0e: call 0x89dbd0
807a1f: add DWORD PTR [esi+0x500c],eax
807a25: add DWORD PTR [esi+0x5004],eax
```

### 1.4 `0x00807B40`：入站 frame parser 共用規格的交叉驗證（非 Quest S→C handler）

- `0x807BA2` 先要求至少4 bytes；`0x807BB0` 取最前2 bytes 為 16-bit 長度，不允許 0 或 >0x1000；`0x807BD4` 取 offset +2 的 16-bit frame discriminator。
- 若 discriminator==`0x2633`，頭長8；==`0x0BBB` 頭長6；==`0x1A68` 或 `0x22D7`，頭長4；其他值仍在預設4-byte branch，但不能由此推定未列出的 tag 都合法。`0x807C34...0x807C3E` 只有完整 `[length+header]` 才繼續。
- 此交叉證據支持 `0x807A70` 所用 `0x1A68` 和 `0x807830` 所用 `0x0BBB` 屬於不同 **frame 類型**，而不是原版 Quest 訊息 identifier。後續 payload decode/handler 還需要進一步定位。

```asm
807ba2: cmp eax,0x4
807bb0: movzx esi,WORD PTR [ebx]
807bb5: cmp si,cx
807bbe: mov edx,0x1000
807bc3: cmp si,dx
807bd4: movzx ecx,WORD PTR [ebx+0x2]
807bdd: mov edx,0x2633
807be5: cmp cx,dx
807bf2: mov DWORD PTR [esp+0x20],0x8
807bfc: mov edx,0xbbb
807c01: cmp cx,dx
807c0e: mov DWORD PTR [esp+0x20],0x6
807c18: mov edx,0x1a68
807c22: mov edx,0x22d7
807c2c: mov DWORD PTR [esp+0x20],0x4
807c34: mov ecx,esi
807c3a: add ecx,esi
807c3c: cmp ecx,eax
```

## 2. 更精確的資料流 / CFG

```text
Lua RequestStartScenario(n)
→ 0x4AA4D0 payload [40 00][uint16(n)]
→ gate [FBA798]==0
→ [FBA854] virtual +0x10 / 0x8069A0(channel0,payload,4)
→ local outbound queue +A074 (0x8060D0→0x806060)
→ consumer 0x8061A0(connection)
    → empty / failure: no frame success proof
    → for each node: payload ptr=node-data+8, length=node-data+4
       → mode [connection+A02C] 0: 0x807A70 (4-byte frame)
       → mode !=0: 0x807830 (6-byte frame) ; failure → fallback 0x807A70
       → framing success: move into connection buffer +5004/+500C
       → unlink outbound queue node, decrement +A078
→ further connection buffer flusher / actual socket send: UNKNOWN

Separate receive-side 0x807B40:
  length16 at +0, discriminator16 at +2, framing-specific header length,
  0x1A68/0x22D7 -> 4, 0x0BBB -> 6, 0x2633 -> 8
  → payload decode → quest dispatcher: UNKNOWN
```

## 3. 玩家情境／Client-S→C／Server 相容規格矩陣

| 玩家情境 | Client gate | C→S 已確認層次 | S→C | Client 狀態效果 | Server 待開發需求 |
|---|---|---|---|---|---|
| 請求開始 Scenario(n) | Lua binding、`[FBA798]==0`、channel0 lookup、queue capacity、framer buffer 空間與模式 | **本地訊息 4 bytes → queue consumer → 條件式 frame 封裝到 connection buffer**；frame type `0x1A68` 或首次嘗試 `0x0BBB`，非 Quest wire opcode 結論 | 未找到對應 ACK | unknown | 需依實際業務 opcode、回覆 handler 建立兼容接口；不可推測 Server 接受規則 |
| 教學通關/完成 | unknown | unknown | unknown | unknown | 待 T14 客戶端結果與 Quest consumer 證據 |
| Quest16 完成 → Quest15 可接 | unknown | unknown | unknown | unknown | 需解鎖／狀態更新資料，原版規則未證 |
| 玩家點擊接取 Quest15 | unknown | unknown | unknown | unknown | 需釐清接取請求、接受／拒絕與狀態快取 |
| 重登恢復 | unknown | unknown | unknown | unknown | P2；snapshot/保存方向仍 unknown |

## 4. 本輪限制／反證與下一個直接入口

- 已否定「`0x806060` 將資料直接寫 socket」的證據等級：本段實際發現**至少又有 outbound queue consumer 與 framing buffer**。不能把 `0x807A70` 成功等同作業系統已送出封包。
- `0x807B40` 是 frame parser，並**不是**已識別的 Quest-specific dispatcher；frame type `0x1A68`、`0x0BBB` 非 Quest opcode。缺實際收包 payload 還無法證明 Scenario 的回覆 ID。
- `0x807830` 的 XOR 與 checksum 需精確完整 mapping，尚未比對收端 6-byte header decoder；不能聲稱已完整解密協定。
- 立即下一段優先尋找 `[connection+0x5004/+0x500C]` 讀取者 → Winsock send/WSASend，定位 `0x8061A0` 被誰呼叫，以及 `0x807B40` 後的 app-level dispatcher → Quest/NPC writer；並從 quest 接取 UI 反追 C→S。
- 若 GitHub T02 已有 IAT/socket 解析，應引用其**已驗證**介面，不修改 T02 原稿。

## 5. 共用三輪深入門檻與 Git

**T16-70 第 1 輪已達重大新發現**：首次將前段有界的 4-byte queue 進一步關閉到「出站佇列 consumer → 兩種 frame writer → connection buffer」，並以另一個 native frame parser 精確交叉確認 discriminator 與長度欄位。這是新原生函式／CFG／格式層級的新增證據，非只列 xref。故 `T16-70-2`、`T16-70-3` **未啟動**。研究不等於已證 wire send 或 Quest 完整玩法。

**GitHub 未 Commit/Push**；文件僅放本地 `/mnt/data` 供下載。未修改其他 Task／catalog／owner。