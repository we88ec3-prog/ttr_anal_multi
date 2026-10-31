# T03-C — W09～W12 選服、群組／頻道、UI 事件、多 Conn 切換與失敗界線（KR BIN-first）

> 作者：chatgpt-web roy；2026-10-31 18:36:19 Asia/Taipei；Repository：`we88ec3-prog/ttr_anal_multi`；唯一工作分支 `t03/roy/chatgpt-web`。本批為 T03 專用 C 工作包，尚無其獨立正式 RR，主要關聯 `RR-0003 / GAP-AUTH-0001` 與相鄰 `RR-0002 / GAP-CHAR-0001`。未修改其他 Task、S00 正式台帳或既有原稿。

**一手原件**：唯讀 `Tartaros.bin` 大小 12,472,320，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本輪均從實檔重新計算。PE32/i386，image base `0x400000`，`.text` VA `0x401000`、raw `0x400`、VA→raw=`VA−0x400C00`；`.rdata` `0xBD2000`、raw `0x7D0600`；`.data` `0xD61000`、raw `0x95E800`。**本輪於本機對 113 個合法已知指令起點取原 BIN 原始 bytes 比對 GNU objdump 結果，113/113 PASS**；[可重跑腳本](./20261031-183619-chatgpt-web-roy-T03-C-verify.py)保留其中 C 核心代表性指令與 PE、連線欄位、事件、算術的獨立 byte 斷言。原始遊戲沒有執行、hook 或 patch；沒有原版 Server 封包或實機 UI 截圖。每個靜態 slice PASS 不是 T01 全文 FULL-PASS。

## 0. 工作終點、來源去重、分工

- **W09**：確定 S2C 0x13／0x7A 群組/頻道筆數、兩級儲存、endpoint 由哪幾個 byte 傳至本地可選 record、如何查回；包含零組、停用列、缺項。
- **W10**：確定 UI control／event producer→consumer 和 selection resolver，分辨何時純本地切換、何時有條件呼叫 Connect；不可臆造選服 C2S 專用 opcode。
- **W11**：確定 key1（LOGIN）與 key0/key2 helper 的端點、slot、局部首包和跨連線 gate；T02 的通用 Winsock/IOCP 直接引用而不佔其主責。
- **W12**：區分失敗情境（沒有群組、無效 row、null Conn、一個 Conn 成功另一個失敗、舊 Conn 關閉、UI 取消／再次點擊）；判明哪些根本沒有自動重試證據。
- **既有來源**：T03-B 原稿 `kr-temp-roy/20261031-182406-chatgpt-web-roy-T03-B-W05-W08-auth-BIN-first.md`，Git blob `e5463936b7b48421219c0e0c83d5d4bf9b07b09f`；T03 RR3 原稿 blob `64c8c1a3429ae6ff177a84dee0d08ad69dba0b17`；E69 blob `98546ce73206e2b8f6fede78d83923af7a76cf5b`。T02 E56 連線有界原稿 `kr-extra-roy/20261030-091559-chatgpt-web-roy-E56-RR0005-bounded-static-completion-transport-owner-retry-reply.md`，blob `843889349bb58209c02221e720800f0e9e3ff9d8`；E60 分派 blob `2ca02f3870d79d3217abf39b8651c43226eb77d6`。本次新增定向確認較具體的 **group→UI 識別/stride** 與 **0x709/0x70A/0x578 三個局部事件分支**；不重複宣稱重新發現 T02 已有 socket/IOCP。
- 最新 main 開工基準 `f6eeef02dfa3704aabb45349718cc9da4b35fbe0`；分支在開工時 ahead 3、behind 0，已包含 main，故不另做空 merge。T01 舊 T03-6 退回在 `main` 仍標 NEEDS_FIX；T03 工作分支 A 勘誤 READY_FOR_REVIEW，待 T01 正式複驗；本次 C 不更動此審核。

## 1. W09：S2C 群組／頻道 → Client 選項物件、識別與 endpoint

### 1.1 有效登入場景及二種不相容的入站布局

底層 T02：正確外框/connection/lane2 → first-level default/LOGIN scene → `0x4C3220` 註冊 S2C `0x13→0x4C37A0`、`0x7A→0x4C3C10`。這是**可達 handler**，非原版 Server 的真實必然發送次序。

| S2C application command | 解析前提 | count | 第一組起點 | child 資料 |
| --- | --- | --- | --- | --- |
| `0x0013` | status=0 且 UTF-16 name 非空，且有效 LOGIN scene | `DWORD payload+0x1C` | `payload+0x92` | 每組 3B + 10B×childCount |
| `0x007A` | 有效 LOGIN scene 與 handler | `DWORD payload+2` | `payload+6` | 同 `0x4C3080` 迴圈 |

`0x4C3080` 在入口取得 `[FE1B54]` 之指標並加8，再由 `0x4C4240` 清理既有候選；`groupCount==0` 在 `0x4C30AA` 跳 `0x4C314A`，**仍呼叫本地事件 `F4243`**。非零時 `4C30BE movzx ecx,WORD [ebx]` 讀 group ID；`4C30C1 add edi,3` 跳過 group header，`4C30C4 call 507510` 登記 group；其 childCount 是 `[ebx+2]`。每列 `4C30E2/0x4C30EF` 等讀 `row[4..7]` 為四個 unsigned octet，`4C30F6` 指向 `.rdata+ BFB050` 的 `"%d.%d.%d.%d"` 作文字格式化（`4C3102→4C4330`）；`4C30FF add edi,0xA` 即使列被濾掉仍前進。只有 `4C3107 row[8]` 非零，才會在 `4C3112` 讀 `LE16 row[0..1]`、`4C311A` 讀 `row[9]`、`4C312A call 507610` 放進列表。

```asm
4C3099 8B 35 54 1B FE 00    mov esi,[FE1B54]
4C30A5 E8 96 11 00 00       call 4C4240           ; clear previous
4C30AA 85 DB                test ebx,ebx         ; 0 groups still notification
4C30BE 0F B7 0B             movzx ecx,word[ebx] ; group id
4C30C1 83 C7 03             add edi,3
4C30C4 E8 47 44 04 00       call 507510
4C30C9 80 7B 02 00          cmp byte[ebx+2],0   ; childCount
4C30F6 68 50 B0 BF 00       push 0xBFB050       ; IPv4 dotted decimal fmt
4C30FF 83 C7 0A             add edi,10
4C3107 0F B6 4E 08          movzx ecx,byte[esi+8]
4C3112 0F B7 06             movzx eax,word[esi]
4C311A 0F B6 56 09          movzx edx,byte[esi+9]
4C312A E8 E1 44 04 00       call 507610
4C314A 68 43 42 0F 00       push 0xF4243
```

**資料/格式不能超過已證：** row+2..3 仍未確認用途；row+8 只能稱「本地 append filter」，不能命名成原版 Server online/可登入；row+9 不可認成 padding，因它以 EDX 傳 `507610` 並在 `507657 mov [ebp-68],edx` 保存。四個 IPv4 octets 是原始 Client 消費的 endpoint 候選，非現代部署權威 IP。正確建立合成 payload 要求 `L13 ≥ 0x92 + Σ(3+10*n_i)` 或 `L7A ≥ 6 + Σ(...)`，**這是工程保護的最小覆蓋範圍**，不是原版 Client 每筆都驗證總長。對空群組的 `0x13`，仍有身份／狀態欄位與先行 optional notice 的其它讀取前提，不可用 cursor 起點=最小通用長度。

### 1.2 兩級容器、顯示 record、查找鍵的新直接驗證

- `0x507510` 由 group ID（`ECX`）、群組容器（`EDX`）建立／查找群組資訊，帶著名稱/列表 metadata；`5075C0 mov edi,[esi+0x18]`、`5075CE call 507BA0` 進下游容器。這是**本地資料操作**，不是向 Server 要求 group 名稱的 C2S。
- `0x507610` 對已通過 row[8] 的列作本地記錄：從栈參數取 group-related object、row識別等，`507654 mov [ebp-6C],ecx`、`507657 mov [ebp-68],edx` 保留兩種輔助參數；`507695 movzx ecx,si`、`50769B shl ecx,16`、`50769E or ecx,edi` 形成兩個 **16-bit 值合成的 DWORD key**，供 `5076AF call 47FDF0` 查找。受 `0x5076CC` 的 fallback/名稱格式及 helper gate 控制，`507721→507B10` 更新下游 record。此時不必猜官方 group/row ID 的長期配置策略。
- `0x507750` 與 `0x5078C0` 是兩條獨立 Client 查詢路徑，入口各讀 `container+0x18` 的 group 数量；`5077A3`／`507913` 對 group/item 識別作 compare；二級 child 陣列從 `+0x40` 到 `+0x44`，以 **0x60 bytes 每元素**步進（`507851 add [ebp+8],0x60` 與其對稱路徑），並查第二個控制/選擇值。未匹配時清零 EAX 回傳 NULL；並非任意選擇 index 都有有效 endpoint。重要：其中 `[edx]/[...+0x40]` 比的是本地記錄欄位，而非網路封包 offset。
- UI 顯示/更新 `0x66B910` 明確引用同一 `FE1B54` (`66B93C`)、`66B94A→66C720`，再從 UI item `+0xFC/+0x100` 範圍比較、迴圈 `66B9D5→66C830`，最後 `66B9E3→66BA20`、`66B9E9→66BBD0` 更新。這是一段**可達的本地刷新函式**；目前未以完整 local-event bus callback 登記證明「任何 `F4243` 當下必直接呼叫 `66B910`」，因此正向的直接訂閱／時間序列仍是 Client 待補查項，不能硬說同步刷新已發生。

```asm
507657 89 55 98             mov [ebp-68],edx       ; row+9 source carried
507695 0F B7 CE             movzx ecx,si
50769B C1 E1 10             shl ecx,16
50769E 0B CF                or ecx,edi
5076AF E8 3C 87 F7 FF       call 47FDF0            ; composite key lookup
507721 E8 EA 03 00 00       call 507B10            ; record append/update
5077A3 39 02                cmp [edx],eax          ; first-level match
5077EA 8B 48 44             mov ecx,[eax+44]      ; child end
507851 83 45 08 60          add dword[ebp+8],60h ; child stride
50784C 39 0C 02             cmp [edx+eax],ecx     ; second-level match
66B93C A1 54 1B FE 00       mov eax,[FE1B54]
66B94A E8 D1 0D 00 00       call 66C720
66B9D5 E8 56 0E 00 00       call 66C830
```

## 2. W10：三種 UI 事件，各有不同 gate，不能等同 C2S

### 2.1 事件消費者 `0x66C620`：type / control identity / actual callee

```asm
66C629 8B 48 10             mov ecx,[eax+10h]           ; event type
66C62C 81 F9 09 07 00 00    cmp ecx,0709h
66C637 8B 8E F0 00 00 00    mov ecx,[esi+F0h]
66C643 E8 88 F5 FF FF       call 66BBD0                 ; matching f0 control id
66C667 81 F9 0A 07 00 00    cmp ecx,070Ah
66C678 3B 51 20             cmp edx,[ecx+20h]          ; f4 control identity
66C68D 6A 00                push 0                       ; control virtual+90
66C6B9 E8 D2 F9 FF FF       call 66C090
66C6C4 81 F9 78 05 00 00    cmp ecx,0578h
66C6D5 3B 51 20             cmp edx,[ecx+20h]          ; f8 control identity
66C711 33 C9                xor ecx,ecx                  ; selects alternate resolver mode
66C713 E8 78 F9 FF FF       call 66C090
```

- **event 0x709**：當 `event+0x08 == control(f0)+0x20`，呼叫 `66BBD0` 刷新/顯示路徑；與 `0x70A` 選列/連線不同。
- **event 0x70A**：必須 `event+0x08 == control(f4)+0x20`；先對 `f4/f0/f8` 三個 control 的 virtual `+0x90` 傳0，再從 `event+0x18` 取得 record，讀取其 `+0x20` 以 ECX 傳給 `66C090`。無正向匹配不會因此呼叫此 resolver。
- **event 0x578**：必須 `event+0x08 == control(f8)+0x20`；先對 `f4/f0/f8` 清/隱藏（virtual+0x90 參數0），再以 **ECX=0** 呼叫同一 `66C090`（`66C711 xor ecx,ecx`）。它是**另一種 selection resolver 模式**，不能與 0x70A 同型；event numeric = 本地事件類型，非 wire opcode，也不能因 event 578 在其它 UI 也出現就推斷此處創角 ACK。
- 在 `66C620` 本身沒找到向 Network Manager enqueue 的直接 `vtable+0x10`；真正可能建連的是 resolver 內 `0x4957C0`。**在 `0x66C620` 未證另有「選服確認 C2S command」**，不可憑事件碼杜撰 payload。

### 2.2 resolver `0x66C090`：缺失/無效路徑必不可省

`0x66C0C1` 沿 `eventArg+F0→child+CC→child+DC→value+20` 求第一個候選，空中間節點時存 `-1`；當輸入 ECX=0，`0x66C0F9` 另從 `eventArg+F4` 結構求另一個候選，缺失時也用 `-1`。這些是**本地 control pointer 與選項值**，不是 from-wire 相對 offset。之後：
```asm
66C132 E8 89 B7 E9 FF       call 5078C0
66C141 E8 0A B6 E9 FF       call 507750
66C146 F6 05 90 43 F9 00 01 test byte[F94390],1
66C17E 83 3D 94 42 F9 00 00 cmp dword[F94294],0
66C18B 85 DB                test ebx,ebx
66C193 85 F6                test esi,esi
66C1A7 E8 14 96 E2 FF       call 4957C0           ; conditional branch A
66C21D 83 FB 04             cmp ebx,4
66C22A 83 FB 05             cmp ebx,5
66C233 85 F6                test esi,esi
66C247 E8 74 95 E2 FF       call 4957C0           ; conditional branch B
```
最重要的 guard 是 `F94294 !=0`、某個 group/item record 非 NULL、以及另一個 mapping 結果有效；一條分支還依 `mappedCode==4/0/5` 分流。因此**有效 group 數據／有 UI 點擊／call resolver 不必然 call Connect**。本函式處理部份成功後還有 `D63DCC` 寫入及 UI control 相對值更新；這是本地效果，不能自動當成新 Server ACK。

這裡只可用「對應兩級選項查找和有條件的 Connect」描述，不將 `mappedCode==4/5` 直接賦予官方頻道狀態文字；無 T06 同版 layout/control identity 時不可說螢幕上必定顯示哪一格。

## 3. W11：key1 LOGIN、key0/key2 選服連線與本地首包

### 3.1 key1 初始連線 helper（`0x495610`）

`0x495610` 帶一個本地前置旗標 `F94390`、`F941C0` 的重設與 UI/初始化分支。`0x4956F7`、`0x495707` 依條件透過 manager virtual+0x20 處理既有 key/connection；`0x49574E..5B` 構造 **key1、port `0x20DF`、lane 2** 的 connect request，`0x49575D` 非 NULL 才走 `0x495781` manager vtable+0x14 register/recv，然後 `495794 mov [client+BF60],conn`；NULL 時 `0x495763..7E` 走失敗/返回0。**key1 不是 key0/key2，也不能借用 BF58 作「第四 socket」**。此為 T02 E56 的有界介面，本輪核對原始 `0x495610`/BF60 bytes，只將相容條件交給 T03 UI。

### 3.2 key0/key2 建連 helper（`0x4957C0`）

```asm
4957E0 6A 02                push 2               ; lane
4957E2 6A 00                push 0               ; key0
4957E4 68 E0 20 00 00       push 20E0h
4957EA FF D2                call edx             ; manager Connect virtual+18
4957F2 6A 02                push 2
4957F4 6A 02                push 2               ; key2
4957FD 68 DE 20 00 00       push 20DEh
495803 FF D2                call edx
495807 85 FF                test edi,edi          ; key0 Conn*
49580F 85 DB                test ebx,ebx          ; key2 Conn*
495817 83 BE 60 BF 00 00 00 cmp dword[esi+BF60],0 ; old key1 live
495838 E8 A2 0B 37 00       call 8063E0
495853 E8 78 08 37 00       call 8060D0         ; local app 0x007E of key1, gated
49585E C7 80 B0 A0 00 00 01 00 00 00 mov dword[oldkey1+A0B0],1
495868 C7 86 60 BF 00 00 00 00 00 00 mov dword[client+BF60],0
495935 6A 39                push 39h             ; 57B application payload
49593B 6A 00                push 0               ; key0
49593D FF D2                call manager virtual+10
49595B 89 BE 64 BF 00 00    mov [client+BF64],edi ; key0 slot
495962 89 9E 68 BF 00 00    mov [client+BF68],ebx ; key2 slot
495968 B8 01 00 00 00       mov eax,1            ; helper success
```

**前置條件：** 兩次 manager Connect 都回傳非 NULL，且後段的預備資料與 queue/helper 正常可繼續。正向已找到：若 key1 BF60 存在，`0x495838` 開始進入 shutdown／app0x7E 相關清理，`0x49585E` 設 old Conn+0xA0B0，`0x495868` 清 BF60；接著 `0x495872` sleep(0x190) = 400 ms（`0x190=400`），它是本地時序，不表示一定等官方 Server ACK。

新 key0 首次可見 sender 從 `Client+67E0`、`+67E4`、`+67FA`、`+6898`、`+6899`、`+68A0` 組成本地 0x39-byte application payload：
- `0x49587F` 設 leading WORD `0x0001`；
- `0x4958B8` 讀 `+67E0` DWORD；
- `0x4958C6/8D4`、`0x4958E0/8EC` 以不超過 10 個寬字元為容量來源的局部 copy helper 寫不同寬字串欄；
- `0x4958F5` 取 `+6898` BYTE，`0x495908/914` 取 `+6899` 窄字串容量5，`0x495921/927` 取 `+68A0` DWORD；
- `0x495935` 以 payload len=0x39、slot0 enqueue，`49594A`／`495959` manager virtual+0x14 啟動 key0/key2 接收，`49595B/62` 更新 BF64/BF68。

**真正發包的界線：** 本地 enqueue 0x39 不等於未轉換的 wire packet=57 bytes，也不等於 WSASend 成功或 Server 接受連線；key2 在本 helper 沒有直接 first-app send，不能升級為整個 Client 永遠不對 key2 send。key0/key2 helper 回傳1 不是「已登入角色」。

### 3.3 三個 key 的本地來源，絕不混用

| Conn key | 來源/port（KR 原生常數） | manager / Client slot | 局部用途與限制 |
|---|---|---|---|
| **key1** LOGIN | `0x495610`, `0x20DF` = 8415 | `Client+BF60` | 登入 E8/000F/回覆的前提；舊 key1 有條件清理 |
| **key0** choice/game | `0x4957C0`, `0x20E0` = 8416 | `Client+BF64` | 有條件送出第一筆 app0x0001、0x39B 本地 payload |
| **key2** parallel | `0x4957C0`, `0x20DE` = 8414 | `Client+BF68` | 此 helper 啟動接收，不證原版 Server first response |

以上 port 是 Client literal，不是現代部署建議或原版 Server IP/負載平衡策略；連線 endpoint 應由選服資料與本地 resolver 查出（參看 W09/W10）。`BF58` 沒有已證 socket slot owner 身份。

## 4. W12：失敗、重試、返回與釋放的反例

| 情境 | 原始 native 分支 | Client 已證的局部效果 | 禁止過度推論 |
|---|---|---|---|
| S2C groupCount=0 | `4C30AA→4C314A` | reset list，仍 `F4243` | `F4243` 不表示玩家看到非空列表 |
| childCount=0 | `4C30C9→4C3140` | group 被登記，沒有 child append | 不把 group ID 當 endpoint |
| row[8]=0 | `4C310E→4C312F` | 跳過 `507610`，仍 +10 byte cursor | 不把 row+9 認作此時已保存 |
| 選擇值無效／不存在 | `507750/5078C0` 兩級查找／NULL | `66C090` 走分流/其它本地 UI 狀態 | 事件已發生≠連線必達 |
| 控件不符 | `66C620` 三分支各比較 `event+8` vs `control+20` | 不會走該分支的 refresh/resolve | 相同 event 類型不代表其它控件也生效 |
| key1 Conn NULL | `49575F→495763` | 此 helper return0，不保存 BF60 | 不證 OS socket closed 的所有路徑 |
| key0 成功，key2 NULL | `49580F/811→49597E` | manager virtual+20 清 key0、記錄本地錯誤、return0 | **沒有本函式自動重撥** |
| key0 NULL，key2 也 NULL | `495807/809→4959B0`，`4959BD` | 記錄失敗、依 key2 是否有指標決定附加清理，return0 | 不把 null 指標當成功 Connect |
| key0 NULL，key2 非 NULL | `4959BD→4959C1..D0` | manager virtual+20 清 key2、return0 | 不證整個 UI 不可再次嘗試 |
| key0/key2 都非 NULL | `495817` 起 | 可能先清舊 key1，產生新 key0 首包，啟用 recv，保存 BF64/BF68，return1 | local success≠Server ACK、遊戲進場 |
| CloseByPtr 的呼叫與 Pool | `806FC0` 路徑與 T02 E56 | 可能 shutdown/closesocket/Pool+28/48，受旗標與 pending 限制 | same-key map erase 不必然等於立即關底層 OS socket |
| UI 另一個點選/返回 | `66C620` 多次事件可重入相同 resolver | 存在新的 UI 觸發機會 | **沒有已證 timer-based retry／退回登入畫面的完整正向鏈** |

注意 `0x4959B0` 是 **key0 NULL** error 路徑，若 key2 非 NULL 才會往 `0x4959C1` 另處理；`0x49597E` 是 **key2 NULL** 而 key0 非 NULL 的路徑。只寫「連線失敗」會丟失回收哪個成功 Conn 的重要判斷。另 `0x4957C0` 會無條件先嘗試兩個 Connect 再測其返回值（先 key0 再 key2）；null 後清理是 function-local 行為，不能據此決定 OS error / retry policy。

**尚未閉合**：1) 任意 UI 控件關閉/取消回登入 scene 的全部 listener、local event/connection cleanup；2) 有無其他 timer／外部事件驅動的全域 retry/重連；3) key0/key2 connect 成功後原版 Server 第一筆 S2C opcode、業務回覆和先後順序；4) 具有 runtime 真實 socket 的釋放/併發 lifetime。這些須另用 Client 全 xref、event mapper、T02 IOCP、原版 trace 補證。**不以無實包阻止既有 Client 靜態鏈交付**，但也不能標「整套選服已可玩」。

## 5. 玩家情境的 C→S／S→C／UI／Server 需求矩陣

| 玩家情境 | S→C/資料來源 | UI／Client 消費 | C→S/transport | Server 待開發、仍未知 |
|---|---|---|---|---|
| 登入成功並取得群組 | 有效 LOGIN scene S2C13 status0+name+群組 | `4C3080` 登記、`F4243`／有條件 `F4241` | 此步不是必然選服發包 | Server 須輸出相容清單；原版登入/端點策略 UNKNOWN |
| 後續清單更新 | S2C7A `+2 count/+6 cursor` | reset/重建 `FE1B54` group/child；local `F4243` | 無已證 dedicated query | 何時補發/列表順序是 Server policy UNKNOWN |
| 選單沒有可用頻道 | group0/row[8]=0/查找 NULL | 可能刷新空 UI；resolver 不能有效取得目標 | 未證會發新的 app request | Server 需保證自訂合法長度、欄位，不能以 CLIENT 有防護當前提 |
| 先選 group | 控件0x709 matching | `66BBD0` 刷新 group/child 內容 | 在此 handler 無直接 send | UI 資源 identity 與實際可見性仍需 T06/runtime |
| 點選有效 channel | 控件0x70A matching→mapped record | `66C090` 檢查 5078C0/507750、F94294 | 成立後 key0/key2 Connect；key0 C2S app0x0001 len0x39 本地 enqueue | 原版 Server 如何接受/拒絕、first S2C UNKNOWN |
| 另一個選擇入口 | 控件0x578 matching→ECX=0 | 同 resolver 不同候選來源及分支 | 可以走另一條有條件 Connect | 不能視為與0x70A同個 UI 控件或官方身份策略 |
| 任一 connect 失敗 | Client local manager return NULL | 回傳0/清成功側 Conn、局部錯誤 | 首包正常路徑不成立 | 重試頻率/錯誤 UI 由實際 Client+Server 契約補證 |
| 兩條連線成功 | 端點以可選 row 查得 | 保存 BF64/BF68、關閉舊 BF60 前提 | key0 app0x0001/0x39、key2 recv post | 必須等待真實 S2C 和場景處理，絕非進入世界就緒 |

**不能製造**：「0x709/70A/578 就是選服 C2S」、「SERVER 必先下 0x7A」、「0x13 success 無需玩家輸入必然開始 key0/key2」、「E8/000F、0x13 和 key0 app1 是同一 payload base」、「選服成功就是 C2S42 選角成功」。C02/B 工作包早已分出三種不同 opcode / local event / frame namespace。

## 6. Server 需求交接／不修改 S00 正式台帳

- **Client 已證可實作相容介面**：LOGIN scene 消費 0x13／0x7A 的 count/cursor 兩套布局；群組每筆3B/頻道每筆10B、IPv4 bytes +4..7、過濾 flag +8、保留資料+9、group/row查找鍵；選擇後可有條件建 key0:8416、key2:8414；key1:8415 是原先 LOGIN；key0 首 local app0x0001 len0x39，資料來源為 0x13 更新的身份欄位。
- **Server 待開發**：合法 group 資料與 endpoint、可連兩路服務、Session/角色 ownership 驗證、跨 Conn 首包的狀態協調、斷線/重試策略、auth失敗／場景返回等；這些是新相容 Server 自訂決策，不是假稱舊版官方內部實作。若要認定連線已被 Server 接受，需收到並解析相應下游實包/handler。
- **推薦供 S00 去重/納入的候選需求**（不另建平行 RR/REQ 台帳）：`CANDIDATE-REQ-T03-CHOICE-LIST-SAFE`：相容 S2C13/7A group+rows 並嚴格檢查合成 payload 長度與字串；`CANDIDATE-REQ-T03-CONN-HANDOFF`：支援所選 endpoint 下 key0/key2 與 key0 app1 首包、key1 可清理；`CANDIDATE-REQ-T03-CHOICE-ERRORS`：接收 Client 的失敗與再操作，定義 Server-specific rejection/disconnect/Session 機制。S00 決定正式 REQ/ADR/SPEC/TEST 名稱與時機。
- **受影響但未更改**：`SPEC-AUTH-0001`、`SPEC-FLOW-0001`、`GAP-AUTH-0001`、`GAP-NET-0002`（由 T02 owner）、`TEST` 需增合成 group0/row0/invalid selection/key1 fail/key0 fail/key2 fail/雙連線/重登測試矩陣。S00 可使用有界事實，但不能自動提升 SPEC STABLE / GAP RESOLVED。

## 7. 精確工作結果、品質與驗證矩陣

| WID | 已閉合的原生 Client 範圍 | 仍未知與驗收階段 |
|---|---|---|
| **W09** | group header/child loop、4 octets、row8/row9、`507510→507610` group/row容器、`507750/5078C0` 0x60 record lookup、`66B910` 列表顯示刷新候選 | `F4243` 的所有 listener/event bus 實際回呼與 GUI layout；**局部業務鏈完整，事件必達尚未全域閉合** |
| **W10** | `66C620` 0x709/70A/578 控件 identity 與 `66C090` 查找/fallback/Connect gate | 舊 GUI 實際可見/取消功能、額外異步事件；本地網路查詢 opcode 不造假 |
| **W11** | `495610` key1 8415 BF60；`4957C0` key0 8416 BF64/key2 8414 BF68、key0 0x39B app1、old key1 有條件 cleanup | 全域 socket/IOCP 壽命屬 T02，原版首筆 S2C 未知 |
| **W12** | null/map/row/兩 Conn fail 的分支及 close-by-pointer T02 參照 | 自動 timer retry、UI error文案與完整回登入畫面路徑尚未閉合，不能稱已完成端到端 runtime |

本項四組在**已指定的 Client 靜態研究邊界**完成原生補證與工程交接；所有未知在上表明確保留，並非宣稱每條 UI callback/重連生命週期 100% 靜態閉合。若以「完整 UI 回到登入＋所有 timer retry」為驗收條件，該子方向仍待下一個專項補證而不是藉本批結果標 FULL-PASS。本批**沒有對應新 RR 需 SUBMITTED**；RR-0003 在 main 仍 `IN_REVIEW`，RR-0002 `BLOCKED`，由 T01/S00 另決定審核與規格採納。 

### 自身實際驗證與可重做工具

- 本地使用 `sha256sum Tartaros.bin Tartaros.exe`，`objdump -f -h` 核對 PE/image base/section，`objdump -D -M intel --section=.text --start-address=VA --stop-address=END Tartaros.bin` 定向讀各入口；全程唯讀。
- 研究所用指令範圍：`4C3080..3169`、`507510..600`、`507610..742`、`507750..8B7`、`5078C0..A2F`、`66B910..BA17`、`66BBD0..C04F`、`66C090..C271`、`66C620..C71B`、`495610..7B9`、`4957C0..9E3`、`806AD0..CF0`、`806FC0..7090`，其中核心113處原始 opcode bytes 對同版實檔全部 PASS。
- [`20261031-183619-chatgpt-web-roy-T03-C-verify.py`](./20261031-183619-chatgpt-web-roy-T03-C-verify.py) 與 [`20261031-183619-chatgpt-web-roy-T03-C-handoff.json`](./20261031-183619-chatgpt-web-roy-T03-C-handoff.json) 為可重跑檢查與機器交接。若後續有新版本不同 SHA，**不可**把本檔的地址、opcode、port 套用而不重新驗證。

下一研究方向（依既定 T03 規劃）：D／E 的角色建立入口／全量與增量角色名單，或有專門 S00/T01 指派時再補 `F4243 listener`、T06 UI layout、time-based retry。不能把「本批交付完成」轉寫成正式 RR/T01 的接受狀態。
