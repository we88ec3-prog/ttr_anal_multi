# T03-D — W13～W16：空角色入口、Expedition 命名、結果事件、Account／Role 分界

> chatgpt-web roy，2026-10-31 18:46:54 Asia/Taipei；KR T03 / 工作分支 `t03/roy/chatgpt-web`。本報告回答規劃 D 的 **W13～W16**，對應已有 `RR-0009（SUBMITTED）`、`RR-0010（BLOCKED）` 的有界問題，但**不自行更改正式 RR、T01、S00 狀態**。W13「N=0 是否自動開命名對話框」尚無可驗證的正向原生鏈，必須保留 BLOCKER；不能因本批提交就寫成 GUI 已可用。

## 0. 原件、來源、目標與實際原生驗證

- 唯讀 KR `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本輪從上傳實體檔計算 SHA；未啟動、patch、附加原 Client，沒有官方 Server 原始封包。
- PE32/i386，ImageBase `0x400000`；`.text` VA `0x401000`/raw `0x400`/raw size `0x7D0200`，僅 .text 可用 `raw=VA−0x400C00`；`.rdata` VA `0xBD2000`/raw `0x7D0600`；`.data` VA `0xD61000`/raw `0x95E800`。RTTI/vtable 使用正確 .rdata 映射。
- 本輪對原始 BIN 以函式入口反組譯後定向核對 **121 個指令起點的 exact bytes（121/121 PASS）**，以及 4 個 vtable slots、3 個 MSVC RTTI 字串、4 個 bounded direct-E8 caller 集合；提供完整 121 檢查點資料嵌入的 [可重跑驗證器](./20261031-184654-chatgpt-web-roy-T03-D-verify.py)。驗證成功只是指定靜態證據，**不是 T01 FULL-PASS 或實際 UI/Server 行為**。
- 主線開工基準 `f6eeef02dfa3704aabb45349718cc9da4b35fbe0`，工作分支已包含 main（ahead4/behind0），本對話不新開 branch、不做空 Merge、不回推 main。
- 已核對 T01／S00 的正式 README、RR Inbox/index，與共用 FULL-PASS 入口。去重來源：E70（blob `ef778ac58ccdfd4013962b86a2aa33bf6f245d13`）、E73（`eeb598db5c9bee8909d97a3376c4637d382c3bac`）、E74（`f3d4f126c5ce6a60a871189ca44015dc4693b97b`）、E76（`672a884d84c8a6349c71b3059f1094d8e62b5fb0`）、E77（`7589e9c63f56f9a9d8737f825c46170ea9e64ac7`）、E78（`ae381dd784f8d492a5b760723c8912ad7be2531a`）、E79（`95ced26202c2aedf7ff57c87d4991eff00ad64ff`）。原稿在 `kr-extra-roy/`，不覆蓋其內容；E72 認為 full/delta roster 目的陣列不同之說法，已由 E79 正式限界勘誤：**共享同一 RoleStore pointer cell**。

## 1. W13：空角色名單並不自動證實命名 UI 會開啟

### 1.1 S2C app2 header 的名稱 writer、N=0／N>0 分流

從 T02 合法 business dispatch 到 `0x4B7F00` 的 S2C application `0x0002` consumer，先有獨立 header writer：

```asm
4B8075  6A 14                    push 14h              ; 20 WCHAR source
4B8077  8D 47 0C                 lea eax,[edi+0Ch]    ; incoming app2+0C
4B807B  6A 15                    push 15h              ; 21 WCHAR destination
4B807D  68 F2 38 F9 00           push 0F938F2h        ; Expedition name
4B8082  E8 77 BF 3D 00           call 893FFEh
4B8923  8B 4D 0C                 mov ecx,[ebp+0Ch]   ; payload byte count
4B8926  83 F9 41                 cmp ecx,41h
4B892F  83 C1 BF                 add ecx,-41h
4B8932  B8 B3 CF 21 35           mov eax,3521CFB3h
4B893F  C1 E9 05                 shr ecx,5            ; derived /53
4B894A  85 C9                    test ecx,ecx
4B894C  0F 84 CE 00 00 00        je 4B8A20h          ; N=0 -> common post
4B8952  8B 7C 24 28              mov edi,[esp+28h]
4B8956  83 C7 6F                 add edi,6Fh
4B8992  0F B6 07                 movzx eax,byte[edi] ; row local slot
4B8995  83 F8 09                 cmp eax,9
4B899A  69 C0 10 02 00 00        imul eax,eax,210h
4B89AD  E8 9E B7 01 00           call 4D4150h        ; role record
```

本地 row count `N=floor((L−65)/53)`（在 L>=65 路徑），L<65 局部取0；N=0 **只跳過** row loop 而去 `4B8A20` 共用後處理（mask、`4E5FB0` 等）。N>0 繼續依 slot 0..9、有效 pointer 和 role record 使用 `4D4150`，其 `record+0x5C=1` 是角色可用候選。**N=0 分支沒有正向的 open modal call，不能把角色數為零翻譯成『已開建名』**。

### 1.2 另一條可證的 UI ready 條件是 Expedition 名稱，而非 N

MSVC RTTI `.?AVCExpeditionPage@FUI@@`，vptr `0xC1C1A4`；依原始 `.rdata`：

| Vtable cell | Slot | Function | 有界功能 |
|---|---:|---|---|
| `C1C314` | 92 | `5A6510` | `F938F2` 名字→page ready |
| `C1C2AC` | 66 | `5A65A0` | 三組 control 的 local UI state |
| `C1C338` | 101 | `5A67D0` | local event consumer |

`5A6566 mov eax,0F938F2h`，`5A6570/5A6573/5A6576` 逐 UTF-16 WORD 掃 NUL；`5A657F je 5A658Bh`：名字為空時**本函式不寫 ready=1**；名字非空走 `5A6581 mov dword[page+0x144],1`。空名稱不代表其他路徑一定會把先前 ready 清零。`5A665F cmp [page+0x144],0` 再讓 `page+0x134` 子 owner 的 `+0xB0/+0xB4/+0xB8` 三個 control 分別執行 `virtual+0x94(0)`（未 ready）或 `virtual+0x94(1)`（ready）。該 virtual 的精確 visible/enabled 語意尚缺完整 callee/resource 驗證，保守稱 **UI state switch**。

這提供一個必須保留的反例：**S2C2 中 N=0、但 header +0x0C 已有非空遠征隊名稱時，Page 可以因名稱而 ready，並不要求存在角色。** 相反，N>0 role record 已填但 page/scene/GUI resource 未就緒時也不保證控件可用。

### 1.3 W13 缺環（精確，不用『尚待驗證』一語帶過）

已證 `CExpeditionCreateDialog@FUI@@` 的 RTTI/vptr `0xC35784`、slot87 `0x671FD0` 可收 local UI event，仍未證哪條 **N0-specific** event/scene writer 會真的建構、顯示或聚焦這個 Dialog。E70 的 `CEmployNewCharacter` cache `5AB020→5AB280` 與 UI owner `5C30FD/5C316A` 是另一類角色招聘 GUI，不應代替 Expedition 命名對話框。

對整個原始 .text 的 `E8 rel32` 候選掃描，目前可證的直呼集合包括 `4E5FB0←4B8A9C,4E2794`、`4D4150←4B89AD,4E2782`、`672180←672165`、`672570←5A6895`；**不包括 vtable dispatch／間接呼叫，不能從直呼陰性斷言 UI 不可能開**。

缺的具體正向鏈：

```text
S2C app2 → N=0 → common postprocess
   → [UNKNOWN] scene+UI controller N0-specific state/event writer
   → [UNKNOWN] actual CreateDialog owner/modal instantiation & GUI layout ID
   → [UNKNOWN] control lookup + visible/enabled + local event binding
   → CExpeditionCreateDialog event0x578 → F4244 → 672180
```

解除來源：(A) T03 追 `4B8A20/4E5FB0` state readers、Expedition page scene callback/virtual subscriber；(B) T06 提供同 KR 版本 **真正 GUI layout/control pack** 及 hash，確認 dialog/button/controlID，缺資源錯誤分支；現有 Table.stp 不足以當 GUI pack；(C) 若允許隔離的 synthetic Server/Client runtime test，需明確標 synthetic，分別驗 N0/N>0、header name空/非空、資源存在/不存在、data-written但UI not-ready。**W13 正向開窗仍受阻，但精確 blocker/解阻已交付。**

## 2. W14：CreateDialog 的 UI→C2S app0x003E 48B

### 2.1 RTTI／控件身份／確認與 local name validation

`CExpeditionCreateDialog` 的 vptr `0xC35784`，`0x671F35 mov [esi],0xC35784`；`C358E0 = vptr+87*4` 的指標為 **`0x671FD0`**。

```asm
672001 8B 41 10                 mov eax,[ecx+10h]     ; local event type
672004 3D 78 05 00 00           cmp eax,578h
67200F 8B 86 F4 00 00 00        mov eax,[esi+F4h]    ; button
672015 8B 40 20                 mov eax,[eax+20h]
672018 39 41 08                 cmp [ecx+8],eax      ; control identity
672021 8B BE F0 00 00 00        mov edi,[esi+F0h]    ; name edit
67203E 39 9F 18 01 00 00        cmp [edi+118h],ebx  ; text gate
67206F C7 40 10 44 42 0F 00     mov [eax+10h],F4244h ; local confirm
672154 3D 44 42 0F 00           cmp eax,F4244h
67215B 81 79 14 A7 06 00 00     cmp dword[ecx+14h],6A7h
672165 E8 16 00 00 00           call 672180h         ; name validator
```

`event0x578`、`F4244`、`0x6A7` 是**本地 UI/確認 namespace**，不是 C2S opcode。`0x672180..6724B1` 讀 `dialog+F0` 編輯欄位的 UTF-16 字串；`edit+0x11C<8` 代表 inline SSO 存放（否則 `[edit+0x108]` 指向 heap），**不是姓名8字限制**。字元驗證可見 ASCII 0–9/A–Z/a–z、非 ASCII classifier `FB7608`，及多組 local buffer compare `FB75C8/E8/D8/F8→81EB80`，不能從此推導官方命名允許字集/重名策略。

### 2.2 stack pointer 與 payload base（不能混用）

```asm
672505 56                      push esi                  ; UTF16 source
672506 8D 54 24 2A             lea edx,[esp+2Ah]         ; name dst
67250A B9 3E 00 00 00          mov ecx,3Eh
67250F 6A 15                   push 15h                  ; capacity 21 WCHAR
672511 52                      push edx
672512 66 89 4C 24 2C          mov word [esp+2Ch],cx    ; app opcode
672517 E8 31 09 22 00          call 892E4Dh
67251C 83 C4 0C                add esp,0Ch
67251F 83 3D 98 A7 FB 00 00    cmp dword[FBA798],0
672526 75 16                   jne 67253Eh              ; no queue
672528 8B 0D 54 A8 FB 00       mov ecx,[FBA854]        ; manager
672530 8B 40 10                mov eax,[eax+10h]
672533 6A 30                   push 30h                  ; payload length=48
672535 8D 54 24 24             lea edx,[esp+24h]        ; payload ptr
672539 52                      push edx
67253A 6A 00                   push 0                     ; slot0
67253C FF D0                   call eax                  ; virtual enqueue
```

令 `S=ESP` 在 `672505` 前。`push esi` 後的 `[esp+2A]` = `S+0x26`；再兩次 push 後的 opcode store `[esp+2C]` = `S+0x20`；送出前 push `0x30` 後的 `[esp+24]` 也是 `S+0x20`。所以 48B inner application payload：

| App-relative offsets | Byte size | Native scope |
|---|---:|---|
| `+0..+1` | 2 | LE16 `0x003E` |
| `+2..+5` | 4 | **UNKNOWN**；尚無足以定值的直接初始化 writer；不能假裝固定零 |
| `+6..+47` | 42 | UTF-16LE name destination，**21 WCHAR 容量**（包括 NUL 的必要空間），未使用 bytes 不保證全部清零 |
| total | **48** | manager slot0 local enqueue，**不是完整 TCP frame** |

`0x892E4D` 的 bounded copy 在容量耗盡且未 NUL 的路徑可將 destination 第一 WCHAR 清零並回報失敗；`0x67251C` 後呼叫者沒有再依該回值作 enqueue gate，而是檢查 `FBA798==0`。因此不能聲稱每個被 queue 的 payload 一定有有效姓名，或官方 Server 允許空名。對真正 socket、Conn/Lane/framing、WSASend 的時間與回傳，由 T02 的 send path 管理；本地 `virtual+0x10` 不等於 Server 收到。

## 3. W15：S2C app0x004A 的 signed result、local F4245、UI outcome

### 3.1 scene-specific handler，不能機械用 request+1 估回包

`0x4C14BE` 寫場景識別 DWORD `0x45585044`（記憶體小端 bytes `44 50 58 45`，而其他研究將此場景稱 EXPD）。同一初始化路徑 `0x4C14C8` 建 table：`0x4C14E1` 寫 `[scene+0x60FC]=0x4C21D0`，表基址 `scene+0x5EAC`、stride8 → `index(0x60FC-0x5EAC)/8=0x4A`；`0x4C14EB` 註冊相鄰 app0x68 的**另一個** handler。此路徑必須 active scene／T02 lane2 正常分派才可達，不能以資料指標存在證明 Server 實際發了0x4A，亦不可把 app0x68 誤當 ACK。

```asm
4C21D3 8B 45 08            mov eax,[ebp+8]
4C21D6 0F BF 48 02         movsx ecx,word[eax+2]   ; signed WORD at app+2
4C21DA 51                  push ecx
4C21DB 68 45 42 0F 00      push F4245h            ; local event ID
4C21E0 E8 9B 89 0C 00      call 58AB80h
4C21E8 33 C0               xor eax,eax
```

此 handler 本身在讀 +2 前沒有展示帶入 total length 的逐項檢查；合成測試須自己檢查至少4B和正確外框/scene。`F4245` 的本地 event `+0x10` 是事件 ID、`event+0x14` 是 sign-extended WORD result，**不是** incoming app+0x14。

### 3.2 正向結果 UI

`CExpeditionPage` vtable slot101 `0x5A67D0` 的 local switch，`F4245` 對應 `0x5A6886`：

```asm
5A688B 8B 8F 40 01 00 00     mov ecx,[edi+140h]   ; dialog owner
5A6895 E8 D6 BC 0C 00        call 672570h
5A689A 83 7B 14 01           cmp dword[event+14h],1
5A689E 0F 85 CF 00 00 00     jne 5A6973h
5A68AA E8 61 E0 04 00        call 5F4910h        ; control update
5A68B5 E8 96 E0 04 00        call 5F4950h        ; render name
5A68BA C7 87 44 01 00 00 01 00 00 00 mov [page+144h],1
672617 6A 14                 push 14h
672619 56                    push esi             ; edit name
67261A 6A 15                 push 15h
67261C 68 F2 38 F9 00        push F938F2h        ; shared Expedition name
672621 E8 D8 19 22 00        call 893FFEh
```

- `status==1`：`672570` 正常分支複製 dialog edit UTF-16 至 `F938F2`，本地 close/轉態；Page 依條件更新控件、顯示名稱、設 ready=1。**不是角色 record 建立成功**。
- `status==-1`／`-2`：各自分支的通知/局部 reset；`672790..6727AA` 對 dialog `+168/+160/+164/+14C` 寫零，後續可走 `virtual+0x90(1)`；不等於自動重發 C2S3E。
- `status==-3`／其它：另有不同提示/預設分支；無證據證明等同 -1/-2 的清 edit 或官方錯誤分類。不能猜 `-1=名稱重複`、`-2=角色滿額`。
- 相鄰 local `F4261` 在這個 Page event switch 落 default（E76），`F4278` 另有 `CPhaseSlot` 使用（E78），都不是本次建名 ACK。

**最重要未證連結：** 原版 Server 是否必然把 `C2S0x003E` 回應為 `S2C0x004A`，以及 `4A→S2C2 roster` 是否一定同筆 transaction、是否有成功/拒絕時序。這是**功能上強關聯的兩條 Client 靜態入口**，不是可宣稱已經抓到的官服 request–reply。需要同版本原版雙向多 Conn capture、Server handler/source，或新的 native request-state/response-state 正向因果證據。

## 4. W16：Account / Expedition / playable Role 為三個不同 Client state 領域

| 層級 | Native interface / source | 必須排除的錯誤推論 |
|---|---|---|
| **Account／Login** | B 項 `C2S E8/000F` slot1，`S2C 0x13` success/error、identity fields `Client+67E0/+67E4/+6898/+6899/+68A0`；C 項才選服/slot0與slot2 | 不等於 Expedition 名稱，也不能推出官服 Account DB 密碼規則 |
| **Expedition name** | 上述 `C2S3E` 48B 的 UI name+6；候選 `S2C4A` status1 local name copy；**獨立的 S2C app2** 可從 `payload+0x0C` 寫到**同一 `F938F2`**；`5A6510` 再由這個 name 控制 Page+144 ready | 共同 writer 不是 `3E→4A→2` 的官方固定順序；有名字 ≠ 有角色 |
| **Playable Role／Roster** | `S2C app2` 65+53*N records，`4D4150` 使用 `F94304+slot*0x210` 並設 `record+0x5C=1`；`S2C app0x2B` 2+53*N 另一個同 RoleStore 的增量 handler（E79）；`CEmployNewCharacter` 的另一個 `C2S0x33` 2B；既有角色選擇 `C2S0x42` 4B | 招募／創建 Role 不是 UI 自訂建 Expedition 名，且 `S2C app0x2B` 不是已證 C2S3E ACK |

因此兩個實際有用的反例：
1. `S2C2 N=0` 但 header 有名字：`F938F2` 可先被寫，Page 當次 init 若讀非空即可 ready=1，但角色列表仍沒有任何 slot 可操作。
2. `C2S3E` 後收到合法的 `S2C4A status1`：Page 可顯示已建立/載入的 Expedition 名，**不必已收到新的 S2C2/S2C2B 角色紀錄**。不能把此狀態當作角色進世界的成功。

真正可操作角色建立／招募的 C2S producer、配對 S2C accepted/rejected、roster/init 的**同筆**正向依賴仍屬後續 F 工作包和 `RR-0010`，不能因 D 的命名局部鏈已詳盡就把該 RR 標接受。既有 S2C `0xB6→F4278→Page role record UI` 是另一個可達的更新候選，不能等同同次建名 transaction。

## 5. 玩家情境／測試／失敗邊界

| 情境 | 有界 Client 可見路徑 | C→S | S→C／local effect | UNKNOWN／反例 |
|---|---|---|---|---|
| 空角色清單、名字空 | S2C2 N0 跳 row loop，F938F2 名稱空、Page init 不在此函式設 ready=1 | 不必然有3E | app2 header/page資料 | **未證開 modal，資源/scene 未閉合** |
| 空角色清單、既有名字 | S2C2 N0；header+0x0C → F938F2 | 不必然有3E | Page 有條件 ready=1／3控件狀態 | 不代表擁有角色 |
| 有角色但 Page 未 ready | S2C2 N>0 record+5C 可寫 | 仍可能有其它補資料請求（E74） | GUI 控件還要名字/資源/scene前提 | record flag不等於 GUI visible |
| 按建名、字串有效 | edit+F0／button identity／F4244確認後 | C2S3E 48B、slot0，受FBA798 gate | 不在此處證實回包 | +2..5 UNKNOWN／socket sent未知 |
| 姓名超過 bounded copy | `892E4D` 失敗路徑可清 name first WCHAR | 不保證被 local gate 阻止 enqueue | 不應做官方允許性推論 | 未初始化 bytes、字元合法性、RTC異常 |
| 收 S2C4A status1 | active scene table／本地 F4245 | 不必然同一3E request | F938F2、Page ready+UI controls | 官服配對/持久化/Role未知 |
| 收 S2C4A -1/-2/-3/other | 正負分支不同，部分清 edit state | 無證自動 retry | 本地提示／可能重新操作 | 官方 status semantics未知 |
| Role roster full/delta | S2C2/S2C2B 寫同 RoleStore | C2S26/24 另需條件 | 有紀錄不代表選角已批准 | 不屬 Expedition name ACK |

## 6. 四種責任移交與下一入口

- **Client 待逆向（未解）**：最優先 `S2C2 N=0 → active scene/ExpeditionPage listener → CExpeditionCreateDialog owner/modal open → control identity/visibility` 正向鏈；`C2S3E+2..5` 是否透過尚未發現的 alias writer 賦值；scene+LANE 的 app4A 所有覆蓋；完整 dialog 取消/失敗重新操作。這些不能以「原版 Server 不知道」取代查找。
- **Server 待開發（S00 去重）**：獨立 Account、Expedition 名稱與可操作 Role 的持久化/授權/重名/回覆/重試安全策略；按已證 Client 介面草擬候選 REQ，不冒充原服業務政策。現有 `SPEC-AUTH-0001 / SPEC-CHAR-0001 / SPEC-FLOW-0001` 和 `GAP-CHAR-0002/0003` 仍 DRAFT/OPEN，S00 決定 ADR/TEST。
- **跨功能待整合**：T02 framing/Conn/scene分派、T03 Login/Expedition、T04 Role 實際初值與招募、T05 入世界、T06 同版 GUI pack；不可私改其它主責。
- **待遊玩驗證**：在另外獲准的環境測 N0/N>0 × 名字空/非空 × GUI pack存在/缺失 × valid/invalid C2S3E × S2C4A 正負；官方原版交易需可信同版 capture/Server source。**未執行 Client**。

建議交 S00 的候選需求（不是新正式 RR/REQ ID）：`CANDIDATE-T03-EXPEDITION-NAME`（Account identity 之後 Expedition 建名/載入）、`CANDIDATE-T03-N0-DIALOG-ENTRY`（不可由 N0 直接假設 GUI）、`CANDIDATE-T03-ROLE-SEPARATION`（名稱/RoleStore分離）；由 S00 依現行流程去重。

## 7. W13～W16 研究驗收（不可冒充官服可玩）

| Work | 本次完成的可驗證交付 | 狀態與界線 |
|---|---|---|
| **W13** | N0/N>0 parser，header name 與 Page+144 ready 的原生關係、GUI 三 control、精確 UI 缺環與 T06/Trace 解阻條件 | **BOUNDED PARTIAL；N0→可見建立對話框仍 BLOCKED** |
| **W14** | 原生 RTTI/vtable/button/confirm/name validator、C2S3E stack 48B／slot0／gate／四個 UNKNOWN bytes | **Client sender local chain CLOSED；wire/runtime未驗** |
| **W15** | EXPD scene table 的 0x4A 入口，signed WORD+2→F4245→成功/錯誤 UI 結果 | **Client consumer local chain CLOSED；3E↔4A官服配對未證** |
| **W16** | Account/Expedition/Role 三層及 F938F2 兩來源、RoleStore 同陣列的反例／S00交接 | **Client state boundary CLOSED** |

本次為 D 功能主題的**有界原生研究交付**，不是 W13 正向開窗已通過，亦不是 `RR-0009 ACCEPTED`、`RR-0010 SUBMITTED/ACCEPTED`、T01 FULL-PASS 或 SPEC STABLE。完整驗證器及 machine-readable handoff 隨附。下一工作 E（W17～W20）處理 full/delta roster 與 role UI；F（W21～W24）繼續真正 playable role 建立／招募。
