# T03-8 — KR 接收 frame 後的雙路中繼：`807E50`、`804310/8076F0` 與 `489920/8040A0`

- 研究者：chatgpt-web roy；實際建立時間：2026-10-28 22:49:03 +08:00。
- 研究物件：KR `Tartaros.bin`；唯讀、沒有執行／修改目標、沒有真實 Server 抓包。
- BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本段於本機重新執行 SHA256 校驗。
- 原始 PE section（`objdump -h` 重新核對）：`.text` VA 0x401000、raw 0x400，故本段 `.text` raw=VA−0x400C00；`.rdata` VA 0xBD2000/raw 0x7D0600；`.data` VA 0xD61000/raw 0x95E800。
- GitHub 工作分支 `t03/roy/chatgpt-web`；開始時相對最新 `main` `behind_by=0`。前段為 `kr-temp-roy/20261028-224318-chatgpt-web-roy-T03-7-recv-frame-decode-boundary.md`；不要視 T02 共用傳輸元件為 T03 所有。

## 1. 題目、去重與第一輪

前段 T03-7 證實 WSARecv completion→`807B40`、frame magic/解碼、`807E50`。本段不重跑四種 frame magic，而是從 **`807D7F` 的 frame 完成之後**定向探查：`807E50` 有何資料契約、`804310` 是業務 dispatcher 嗎、`8076F0` 如何存資料、alternate `489920/8040A0` 做什麼、是否由此即可證明 command 42 回覆。

### 1.1 新發現：decode/stage 後仍有兩路通知，不能以一次 call 等同業務 handler

位址 0x807D70–0x807DB2，全部屬 `.text`：

```asm
807d70: lea ecx,[esp+0x2c]
807d74: push ecx
807d75: jmp 0x807d7a
807d77: push edi
807d78: mov edi,eax
807d7a: call 0x807e50
807d7f: mov eax,[esp+0x28]
807d83: cmp dword ptr [eax+0x4],0
807d87: mov ecx,[esp+0x24]
807d8b: mov [eax],ecx
807d8d: jne 0x807d9e
807d8f: push eax
807d90: call 0x804310
807d95: mov edi,eax
807d97: call 0x8076f0
807d9c: jmp 0x807db2
807d9e: mov ecx,[ecx+0xa080]
807da4: push ecx
807da5: push eax
807da6: call 0x489920
807dab: mov edi,eax
807dad: call 0x8040a0
807db2: movzx edx,word ptr [ebx]
807db5: add edx,[esp+0x20]
807db9: mov eax,[esp+0x14]
807dbd: mov eax,[eax+0x5000]
807dc3: mov edi,[esp+0x14]
807dc7: add ebx,edx
807dc9: sub eax,ebx
807dcb: cmp eax,4
807dce: jae 0x807bb0
```

**原生已確認**：分派條件是當前中繼物件 `+4` 是否為 0；0 走全域 `804310` → `8076F0`，非零走 `489920` → `8040A0`。`807D7A` 呼叫 `807E50` 後，在上述段落 **沒有以該函式 AL 回值作分派 gate**；分派路徑判斷基於 `[eax+4]`，不可稱作「已檢查解碼成功才投遞」的完整保證。`807DB2` 依 frame 長度及 header offset 移動輸入 cursor，較早的 `807BB0` 再處理下一筆。

### 1.2 `807E50` 的 0x1000 上限、長度寫入及資料拷貝

```asm
807e50: push ebp
807e51: mov ebp,esp
807e53: cmp esi,0x1000
807e59: jbe 0x807e61
807e5b: xor al,al
807e5d: pop ebp
807e5e: ret 4
807e61: mov eax,[ebp+8]
807e64: push esi
807e65: push eax
807e66: lea ecx,[edi+8]
807e69: push ecx
807e6a: call 0x89dbd0
807e6f: add esp,0xc
807e72: mov [edi+4],esi
807e75: mov al,1
807e77: pop ebp
807e78: ret 4
```

**已確認的 bounded contract**：`ESI` 為提供的長度；如果長度大於 4096，返回 AL=0 且這條路不執行 copy；否則複製 `ESI` bytes 至 `EDI+8`，更新 `EDI+4=ESI`，AL=1。注意 `EDI` 是 caller 安置的中繼記錄，並不是已確定的 packet handler，也不能將長度上限當作所有遊戲層訊息的完整限制。call `0x89DBD0` 的記憶體複製語意依當前 push 值與先前 CRT 辨認，不假定與 UI 掛鉤。

### 1.3 `804310` 是全域 receiver/queue 物件 getter + lazy init，非 T03 業務 dispatch

```asm
804310: push ebp
804332: mov eax,1
804337: test byte ptr [0xfe3354],al
80433d: jne 0x80435e
80433f: or dword ptr [0xfe3354],eax
80434c: call 0x807120
804351: push 0xbd0b90
804356: call 0x89231a
80435e: mov eax,0xfe3358
80436e: mov esp,ebp
804370: pop ebp
804371: ret
```

`804310` **返回固定全域地址** `0xFE3358`；`0xFE3354` 是 init guard，guard 未設置時呼叫 `807120`。未動態核對 `807120` 的完整初始化副作用；此函式本身沒有讀取具體角色封包 opcode、沒有以 opcode 查 handler table，故不可稱為角色回覆 dispatcher。`0xFE3358` 的精確正式類型仍待驗。

### 1.4 `8076F0`：加鎖／寫入另一個環形資料容器／遞減計數

```asm
8076f0: push ebp
8076f1: mov ebp,esp
8076f3: mov eax,[ebp+8]
8076f6: mov dword ptr [eax],0
8076fc: mov dword ptr [eax+4],0
807703: mov eax,[edi+0x58]
807706: push esi
807707: push eax
807708: call dword ptr [0xbd224c]
80770e: lea ecx,[ebp+8]
807711: push ecx
807712: lea esi,[edi+0x3c]
807715: call 0x804260
80771a: mov edx,[edi+0x58]
80771d: dec dword ptr [edi+0x54]
807720: push edx
807721: call dword ptr [0xbd2248]
807727: pop esi
807728: pop ebp
807729: ret 4
```

`[EDI+0x58]` 作為同步 API 參數（實際 IAT 功能需以 import 表與上下游再核）；`EDI+0x3C` 是傳遞給 `804260` 的容器位置。這是明確的 queue write 關聯，不是抽象「事件已交給遊戲 callback」。尤其 `8076F0` 會先將傳入記錄首兩個 dword 設零，接著 `804260` 收到的是當前 `ebp+8` 的地址；不能未經 `807120` 等資料來源驗證就宣稱該支線已帶有完整 decoded payload。

`804260` 的 bounded ring/slot writer 摘錄：

```asm
804260: push ebp
804263: mov eax,[esi+0x10]
804266: mov ecx,[esi+0xc]
804269: add ecx,eax
80426e: test cl,3
804273: add eax,4
804276: shr eax,2
804279: cmp [esi+8],eax
80427e: push esi
80427f: call 0x636f70
804284: mov eax,[esi+8]
804287: mov ebx,[esi+0xc]
80428b: add ebx,[esi+0x10]
80429a: mov edx,[esi+4]
80429d: cmp dword ptr [edx+edi*4],0
8042a3: push 0x10
8042a5: call 0x891268
8042b7: mov ecx,[esi+4]
8042ba: mov edx,[ecx+edi*4]
8042bd: and ebx,3
8042c0: lea ebx,[edx+ebx*4]
8042c7: mov eax,[ebp+8]
8042ca: mov ecx,[eax]
8042cc: mov [ebx],ecx
8042ce: inc dword ptr [esi+0x10]
```

新增的 **確認內容**：這條通路具備分桶／索引／16-byte block 分配及計數遞增，`804260` 並不解析 T03 封包內容，其主要操作是將傳入的 dword 寫入容器 slot。`8076F0` 與 `804260` 的每個欄位並非一定屬同一完整物件，依照各函式的寄存器來源區分。

### 1.5 非零分支 `489920` 與 `8040A0`：確實是不同路徑

```asm
489920: push ebp
489942: mov eax,1
489947: test byte ptr [0xfc10cc],al
48994d: jne 0x48996e
48994f: or dword ptr [0xfc10cc],eax
48995c: call 0x803ff0
489961: push 0xbcdc90
489966: call 0x89231a
48996e: mov eax,0xfc10d0
489980: pop ebp
489981: ret
8040a0: push ebp
8040a3: mov eax,[edi+0x124]
8040aa: mov ebx,[ebp+0xc]
8040ae: push eax
8040af: call dword ptr [0xbd224c]
8040b7: cmp byte ptr [ebx+edi+0x128],dl
8040c1: sete dl
8040c4: push ecx
8040c5: lea eax,[edx+ebx*2]
8040c8: lea eax,[eax+eax*2]
8040cb: lea esi,[edi+eax*8]
8040ce: call 0x804260
8040d3: mov ecx,[edi+0x124]
8040da: call dword ptr [0xbd2248]
8040e1: cmp ebx,2
8040e5: jne 0x8040f4
8040e7: mov edx,[edi+0x120]
8040ee: call dword ptr [0xbd20d0]
8040f5: ret 8
```

`489920` 是另一個 **lazy global getter**，`0xFC10CC` guard / `0xFC10D0` 基底；`8040A0` 使用這個全域 object's `+0x124` 作同步 API 參數，讀 `+0x128` 的 indexed flag，計算 subqueue index（`(flag_zero + 2*ebx)*3*8`），再呼叫同一個 `804260`；只有 `ebx==2` 走額外 `0xBD20D0` IAT 通知。這些是低層資料運送的具體條件，**不等同 command42 的批准、拒絕或 T05 轉場**。

### 1.6 接收解框尾端會保留未完成資料

```asm
807dc9: sub eax,ebx
807dcb: cmp eax,4
807dce: jae 0x807bb0
807dda: mov esi,[edi+0x5000]
807de6: sub esi,ebx
807e03: push esi
807e04: push ebx
807e05: push edi
807e06: call 0x8912f0
807e12: add edi,esi
807e14: mov [eax],edi
```

分派後依 frame 尺寸前進 cursor；不足 4 bytes 時對剩餘內容進行搬移並更新指標，支援下一次接收補齊。這個尾端不是 T03 回覆 handler。

## 2. 玩家情境 × C→S × S→C 對照

| 玩家情境 | Client 條件 | C→S | S→C | 本地結果 | Server／世界 | 證據 |
|---|---|---|---|---|---|---|
| 玩家確認可用角色 | `record+0x5C` 與傳送 gate，T03-3 | `42 00 XX YY` 經 T03-4～6 通道入列及傳輸機制；非每次成功送達的保證 | 尚未證實與 42 配對的特定原版 S→C | 未確認選角 UI 成功／失敗效果 | 原版批准規則未知 | C→S 部分已確認，S→C 未知 |
| 收到已符合格式的任一 frame | `807B40` 驗證長度與 magic，T03-7 | 不適用 | 解碼資料先寫 `807E50`，之後依 `record+4` 分派兩路 queue/通知 | 不能直接認定是角色結果 | 尚無配對 | transport 原生已確認 |
| 中繼記錄 `+4==0` | 接收後 branch | 不適用 | `804310` 全域 getter → `8076F0` → `804260` | 資料容器插入 | 非 T03 確認結果 | 原生已確認（容器） |
| 中繼記錄 `+4!=0` | 接收後 branch | 不適用 | `489920` 全域 getter → `8040A0` → `804260`，部分 index 觸發通知 | 通道／slot 狀態更新 | 非 T03 確認結果 | 原生已確認（容器） |

## 3. 反證、跨 Task 與重要限制

1. **不能將 `804310` 或 `489920` 稱作遊戲 opcode dispatcher**：原始指令顯示它們返回固定全域地址，並有 once/lazy init guard。
2. **不能將 `804260` 稱作選角確認 handler**：它將傳入 dword 放進分桶容器；不在這個有界函式內依據角色 ID、0x42、43/69 做業務判斷。
3. `807E50` 的返回值沒有在 `807D7F` 緊接著 gating，僅能依明確的 decode/frame paths 描述成功條件；不能提升所有異常資料的安全性假設。
4. `8040A0` 在 `EBX==2` 有額外通知，但通知事件是否連至 T03、其後的真正 payload consumer、poll/worker、packet command 域仍未定位。
5. `0x42 → 43/69` 僅本機測試推測；沒有原版 Server trace 或證實的 handler 連線，不能提升為原生完整回覆鏈。
6. 所有共用 socket、frame、queue、dispatcher 由 T02 主責；本段只為 T03 角色選角尋找必要介面。T04 保留角色初值、T05 真正世界轉場、T06 UI 資源。
7. 本段沒有執行 Client、沒有 packet capture、沒有原版 Server，亦未改寫其他 Task 原稿、owner 或 catalog。

## 4. 三輪深入門檻

- **T03-8 第 1 輪：已執行。** 由 `807D7F` 確認兩條解框後交接分支，並首次以 BIN 直接證明 `804310`/`489920` 是不同的 lazy global queue getter、`8076F0`/`8040A0` 各走不同同步與 `804260` slot-writer，而不是遊戲命令 handler；含 4096-byte memcpy gate 與尾段 frame consume，屬已取得可回溯、可用的功能鏈進展，結束本段。
- **T03-8-2 第 2 輪：未啟動**，因第 1 輪已取得有界重大新功能鏈。
- **T03-8-3 第 3 輪：未啟動**，同上。若後續需追真正 consumer，應另立 T03-9，不把未執行的輪次偽裝為驗證。

## 5. 下一正式段 T03-9 明確入口

- 從 `0xFE3358` 和 `0xFC10D0` 兩個全域容器的 **reader / poll / worker** 反查（包括 `0x807120`, `0x803FF0`, `0x804100`, `0x804260` 的 caller），定位哪一條真正帶 packet bytes 到應用層分派。
- 針對 0x42 已證 C→S 與可能的 43/69 reply，以 reader 的實際 command-domain case、payload/length/handler、成功失敗與 UI/Scene writer 反向配對。不同 namespace 的事件 F42EF、wire command 42 不要混用。
- 若 reader 僅在外部 resource/runtime 或其他 Task 中，提供具體引用與本地證據需求，勿自行猜配對。

## 6. 可重驗命令

```bash
sha256sum Tartaros.bin Tartaros.exe
objdump -h Tartaros.bin
objdump -D -M intel --section=.text --start-address=0x807d70 --stop-address=0x807e80 Tartaros.bin
objdump -D -M intel --section=.text --start-address=0x8040a0 --stop-address=0x804110 Tartaros.bin
objdump -D -M intel --section=.text --start-address=0x804260 --stop-address=0x804300 Tartaros.bin
objdump -D -M intel --section=.text --start-address=0x804310 --stop-address=0x804380 Tartaros.bin
objdump -D -M intel --section=.text --start-address=0x8076f0 --stop-address=0x807730 Tartaros.bin
objdump -D -M intel --section=.text --start-address=0x489920 --stop-address=0x489990 Tartaros.bin
```