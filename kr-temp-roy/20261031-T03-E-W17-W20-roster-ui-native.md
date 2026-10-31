# T03-E W17～W20 — KR 角色全量／增量名單 → 共享 RoleStore → UI／選角可用門檻（BIN-first）

> 作者：chatgpt-web roy。日期：2026-10-31（Asia/Taipei）；分支：`t03/roy/chatgpt-web`；使用者明確要求 E 並提交。任務依本地權威規劃 `T03-KR-NEXT-WORK-ROADMAP-20261031.md` 的 W17–W20。這是完整的**有界 Client 靜態研究交付**，不是 T01 FULL-PASS、原版 Server 交易驗收、畫面實測或可玩驗收。

## 0. 原件、驗證、去重與研究終點

- 直接唯讀分析同版 KR `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。兩個檔案 SHA 本輪重算。PE32/i386，ImageBase `0x400000`；`.text` VA `0x401000` raw `0x400` raw size `0x7D0200`，code raw=VA−`0x400C00`；`.rdata` VA `0xBD2000` raw `0x7D0600`；`.data` VA `0xD61000` raw `0x95E800`。未執行、修改、注入原始遊戲，未取得官服真實流量。
- 本輪使用 GNU objdump 在函式起點定向反組譯，再與原始 BIN raw bytes **485/485 個去重指令起點**比對 PASS；樣本範圍：W17 full header 40、W17 full row 101、W18 positive transport/record 134、W19 本地 UI 72、W20 mask/selection 138。另核 PE、`vtable C0D15C+4→4FDA30`、S2C B6 local switch map、record/packet stride。隨附自含原生驗證器 `20261031-T03-E-verify.py`（485 個原生 bytes 以壓縮字串存放，可解碼）。抽樣指令 byte 正確 **不等於 485 個函式語意已完全驗證**。
- 啟動時最新 main `ad1fda170734767c67dd0f62066a34ece34e118a`，T03 branch ahead6、behind0；已讀 AGENTS、T03 README/task、T01 退回、RR/inbox、shared FULL-PASS。主線 RR-0002 BLOCKED／RR-0003 IN_REVIEW／RR-0008 IN_REVIEW／RR-0009 ACCEPTED（僅限 blocker 交付）／RR-0010 BLOCKED。此批按使用者指示 E 優先，不自改 RR 台帳、他 Task owner、T01 RESOLVED 或 SPEC STABLE。
- 有界前稿：E70（blob `ef778ac58ccdfd4013962b86a2aa33bf6f245d13`）N0 建角 GUI blocker；E74（`f3d4f126c5ce6a60a871189ca44015dc4693b97b`）C2S26/24；E77（`7589e9c63f56f9a9d8737f825c46170ea9e64ac7`）B6/F4278；E79（`95ced26202c2aedf7ff57c87d4991eff00ad64ff`）S2C2B callback 與同 RoleStore pointer。**本輪新增**：完整 65B header 更多讀取來源、53B row 的全欄位映射、十筆 record 初始 flag0、full/delta 不同 side effects、invalid ID 仍可 queue C2S26、mask consumer、list-hit 與可用 record 分離，以及 click→C2S42 gate。

## 1. 整體有條件資料流（不是官服已證時序）

```text
[T02 已解 application 且 scene/callback 可分派]
   S2C 0x0002 → 4B7F00 → header → 4B8920
       count floor((len-65)/53)，row從 app+0x41 開始，每53B
       ID(row+2E)<=9 → 4D4150 → [F94304]+index*210，flag+5C=1
       全量專用：gated per-row C2S 0x26 3B，F94240 mask，post C2S0x24 2B
   S2C 0x002B → 493170/4943B0/4FDA30/4E2730
       count floor((len-2)/53)，row從app+2開始，每53B
       同一 [F94304]+index*210 → 4D4150
   full/delta → 4E5FB0 → local metric/有條件 UI 相關效果

[另一筆 S2C 0x00B6] → 4B5DD0 → local F4278(result=0)
   → CExpeditionPage 5A67D0→5A68D8→672F00
   → owner+0xD8 index，record+0x5C
       present →角色資料/控件；absent→673790 placeholder
[另一條 local F42EF]→5A69E8→665150 8B list entry + role flag
[玩家真實 control click]→5F47AC index→<=9且flag!=0
   →4A3B80 C2S 0x42 本地 sender（G 才驗 S2C 選角結果）
```

上述 incoming app 不保證官服按照 2→2B→B6 發包，`F4278/F42EF` 是本地事件，`record+5C` 是 Client 可用資料旗標，**都不是 Server 權限、已完成世界初始化或建角 ACK**。

## 2. W17：S2C 0x0002 全量，65B header 不只名字

### 2.1 額外 header reader 的本次原生確認

| app offset | Native VA / sink | 資料型別（未證業務意義不得補名） |
|---|---|---|
| `+2..5` | `4B803F mov edx,[edi+2]→4B8042 [F93930]` | DWORD，UNKNOWN |
| `+0x0C..0x33` | `4B8075..4B8082`→`F938F2` | 最多20 UTF-16 code units，目的容量21；Expedition 名稱，與 N 無關 |
| `+0x36..37` | `4B8103→F9420C` | WORD 擴 DWORD，UNKNOWN |
| `+0x38..39` | `4B80C5→F94208` | WORD 擴 DWORD，UNKNOWN |
| `+0x3A..3B` | `4B813A cmp word,0／4B813F setne→F94210` | bool，非已證授權 |
| `+0x3C` | `4B817D cmp byte,0／4B8180 sete→F94288` | **等於0時為1**，UNKNOWN |
| `+0x3D..40` | `4B81C0→F9428C` | DWORD，UNKNOWN |

表中未列 header bytes，**不代表 padding/0**；其它 helper 仍可讀。`4B8001` 寫本地 `FBA7B0=0x1E`，不是 header欄位。**關鍵安全界線**：`4B8923 cmp len,65` 出現於函式先前 header 讀取之後，作用是 row count floor，不能被稱為全函式先驗證完整63/65B 的安全總長 guard。

### 2.2 完整名單 row、發送與 mask

```asm
4B8923 8B 4D 0C              mov ecx,[ebp+0Ch]       ; app length
4B8926 83 F9 41              cmp ecx,65
4B892F 83 C1 BF              add ecx,-65
4B8932 B8 B3 CF 21 35        mov eax,0x3521CFB3    ; /53 magic
4B894C 0F 84 CE 00 00 00     je 4B8A20             ; N=0 only skips row loop
4B8956 83 C7 6F              add edi,0x6F          ; input+65+46
4B8992 0F B6 07              movzx eax,byte[edi]   ; row ID at +0x2E
4B8995 83 F8 09              cmp eax,9
4B8998 77 1B                 ja 4B89B5
4B899A 69 C0 10 02 00 00     imul eax,eax,0x210
4B89A0 03 05 04 43 F9 00     add eax,[F94304]
4B89A8 8D 57 D2              lea edx,[edi-0x2E]   ; actual 53B row start
4B89AD E8 9E B7 01 00        call 4D4150
4B89D9 0F B6 07              movzx eax,byte[edi]
4B89DC BA 26 00 00 00        mov edx,0x26
4B89E1 66 89 54 24 18        mov [esp+18],dx
4B89E6 88 44 24 1A           mov [esp+1A],al
4B89F7 6A 03                 push 3               ; 3B app payload
4B89FE 6A 00                 push 0               ; slot0
4B8A02 0F B6 0F              movzx ecx,byte[edi]
4B8A05 49                    dec ecx              ; ID−1
4B8A0B 66 D3 E2              shl dx,cl           ; local 16-bit mask
4B8A0E 83 C7 35              add edi,0x35        ; advance exactly53B
4B8A11 66 09 54 24 14        or [esp+14],dx
4B8A60 66 A3 40 42 F9 00     mov [F94240],ax
4B8A97 B9 E0 D9 F8 00        mov ecx,0xF8D9E0
4B8A9C E8 0F D5 02 00        call 4E5FB0
4B8AC4 B9 24 00 00 00        mov ecx,0x24
4B8ADB 6A 02                 push 2              ; 2B
4B8AE2 6A 00                 push 0              ; slot0
```

`N=floor((len−65)/53)`（len>=65），N=0時仍到共同 post 與 gated C2S24（不是「什麼也不做」）。逐筆 `C2S26` 由 `FBA798==0` 的本地 manager vtable+0x10 gate 決定是否 enqueue；**不是 socket已送達**。list-end `C2S24` 也受同 gate。

**新增反證：ID>9 只跳過 `4D4150` role record writer，並沒有直接跳過後面的 `4B89D9..4B8A11`。因此非法 ID 在此 handler 仍可能產生 C2S26、也參與 mask 計算。**C2S26 的發送不能用來證實角色已成功複製/可被選。ID=0 在 record writer 是合法索引，但 `mask shift ID−1` 的 x86 16-bit 結果是0；ID1為 bit0，ID9為bit8；更大 ID 會有 shift-count mod32／16-bit truncate，mask 本身不是權威合法 ID 篩選器。

### 2.3 53B row → 10×0x210 RoleStore 的精確轉換

`0x4D4150` 接受 EDX=row，ESI=role record；`4D4154 mov [esi+0x5C],1`，先設 local available flag，之後逐 UTF-16 WORD 直到 NUL、沒有本函式自身的 21-code-unit 長度 guard。**若 row 的 UTF-16 名稱未在前42B內終止，會繼續讀其他欄甚至 row 邊界，Server 生成器不能依賴 Client 必會安全拒絕**。

| Row-relative | Native reader | Record-relative |
|---|---|---|
| `+0..0x29` | `4D4160..416D` WCHAR until NUL | `+0x0C` name |
| `+0x2A..2D` | `4D4190 mov edx,[edx+2A]` | `+0x08` DWORD |
| `+0x2E` | `4D416F movzx eax,byte[edx+2E]` | `+0x04` DWORD index |
| `+0x2F` | `4D4176 movzx ecx,byte[edx+2F]` | `+0xD4` DWORD |
| `+0x30` | `4D4180 movzx eax,byte[edx+30]` | `+0xDC` DWORD |
| `+0x31..34` | `4D418A mov ecx,[edx+31]` | `+0x50` DWORD |
| local flag | `4D4154` | `+0x5C=1` |

`4E199E push 0x14A0→4E19A8 call 891268` 配置 `0x14A0=10×0x210` byte，`4E19C7/C9` 以 `0x4D3D00` ctor、stride0x210、count10 建十筆；`4D3D81` 將每筆 `record+0x5C=0`，`4E19DE` 將 RoleStore base pointer 寫入 `[F94304]`。這是本輪新直接驗證的**初始化方向**；不等於每次接收 full/delta 時都重建陣列。

## 3. W18：S2C app0x002B 增量名單，兩表正向路徑和非等價副作用

`0x493170` transport callback table base+0x208、stride0x10；`493375 mov edx,0x4943B0`、`49337A mov [eax+0x4B8],edx` ⇒ `(4B8−208)/10h=0x2B`。`494416` 取得 `[F8D9E0]` vptr，`49441D` 取 vptr+4，`494420 mov ecx,F8D9E0` 呼叫；`4E15C4` 設 singleton vptr `C0D15C`，實體 rdata `[C0D160]=0x4FDA30`。`4FDA30` 再用**另一張 stride8 table** 的 app index；`4E1E3F mov [eax+0x15C],4E2730`，`0x15C=4+0x2B*8`。因此不是靠孤立 helper 猜 opcode。

```asm
4E2734 8B 45 0C              mov eax,[ebp+0C]   ; length
4E273D 83 F8 02              cmp eax,2
4E2746 8D 48 FE              lea ecx,[eax-2]
4E2749 B8 B3 CF 21 35        mov eax,0x3521CFB3 ; /53
4E275F 8B 7D 08              mov edi,[ebp+8]
4E2762 83 C7 02              add edi,2          ; delta first row
4E2767 0F B6 47 2E           movzx eax,byte[edi+2E]
4E276B 83 F8 09              cmp eax,9
4E2770 69 C0 10 02 00 00     imul eax,eax,0x210
4E2776 03 86 24 69 00 00     add eax,[esi+0x6924]
4E2782 E8 C9 19 FF FF        call 4D4150
4E278A 83 C7 35              add edi,0x35
4E2794 E8 17 38 00 00        call 4E5FB0
```

此鏈 `ESI=this=0xF8D9E0`，所以 `ESI+0x6924=0xF94304` **就是 full 的同一 RoleStore pointer cell**，不是同格式但不同角色池。Delta `N=floor((len−2)/53)`，短於2時 N=0，2..54亦無完整 row；55B一列。非法 ID>9跳過writer但仍共同 post。**與 full 不同：本 delta handler `4E2730..279F` 不包含 per-row C2S26、end C2S24 或全量 mask F94240 的 writer**，不能在 Server 端假設兩封包可互換。

**新增生命週期警告：** 十筆 ctor 會先將 +5C=0，`4D4150` 使收到的每列=1；full和delta的已查 loop **沒有**在「未包含某個slot」時執行所有 slot+5C=0 的重置。`N=0` 是沒有 row writer，不等於**無條件撤銷舊角色**。不排除其它 owner/scene/destructor/alias 做 revoke；需要追全域 writer/重建和 session lifecycle，不能全稱否定角色移除能力。

`0x4E5FB0` 不是總會更新 GUI：它讀 role pointer 後 `4E5FEB→4D4590` 算角色集合 metric，與 cached `Client+0x68CC` 比較，分支還需 `+0x5F4C`/資源 gate，才可能新增本地提示/寫 `+0x68D0/+0x68CC`。**收到 delta 不等於可見介面必刷新**。

## 4. W19：S2C B6 → local F4278 → Expedition Page UI，與 F42EF 明細 event 分流

`4AE11D` base scene 8B stride S2C table `+0x5B4=4B5DD0`，即 index `(0x5B4-4)/8=0xB6`；`4AE12D` 的 index0xB7 是 `4B5E50` 不同 handler。`4B5E25 push0`、`4B5E27 push F4278`、`4B5E2C→58AB80` 為 **local event(result0)**，沒有在該 handler 讀取任何53B role欄位。`F4278` 另有 `CPhaseSlot` 事件來源（E78），並非 B6 專用。

`CExpeditionPage` vptr `C1C1A4` slot101 `5A67D0`，local map：`F4278−F4245=0x33`，`[5A69A0+33]=4`、`[5A6988+4*4]=5A68D8`。

```asm
5A68DD cmp dword[eax+14],0
5A68E1 jne 5A6973             ; nonzero result -> no refresh
5A68E7 mov edx,[page+138]     ; child owner
5A68EE xor ecx,ecx
5A68F0 call 672F00
5A68F5 mov ecx,[page+13C]
5A6903 call edx               ; child virtual+D4
672F46 mov eax,[owner+0xD8]   ; when ECX=0
672F80 cmp esi,9
672F85 mov ecx,[F94304]
672F8B imul esi,esi,0x210
672F91 mov eax,[ecx+esi+0x5C]
67315E test esi,esi
673160 je 673556
67355B call 673790            ; absent/invalid placeholder UI
```

這是**有條件**的 S2C→local→record→UI 鏈。需要正確 active scene/lane 分派、實際 Page listener、event result0、存在的 child owner，index<=9、RoleStore有效及 record flag；若無角色走 `673790` placeholder，**不是「Server拒絕」**。實際控件 visible/loaded/成功繪製的條件仍需 T06 GUI resources + runtime，不能由 event 已派發推導畫面已完成。

**另一條 F42EF 不是同一 event：** `5A69E8→5A6A28 call 665150`。`0x665150` 搜 `[FE1DF4]` local 8-byte stride list，entry byte0與 user ID比較，並以 `F94304+ID*0x210` 檢查 record+5C。僅 list-hit**且**record有效時 `66521E` 寫 dialog+0x110、`665230..6653B2` 填/調控件。其尾端 **`6653B4 xor eax,eax; 6653B6 test ebx,ebx; 6653B8 setne al`**，回傳代表**找到 list entry**（EBX），不保證 record+5C非零／已填 detail／角色被 Server 授權。`5A6A28` consumer 在 call 後仍用 dialog vtable+D0；`59A520` 另一 caller 有不同回傳 gate，不能全部混成一條 UI 規則。

## 5. W20：角色 ID、16-bit mask、local availability 和選角控件的不同 gates

| 領域 | Native identifier | 不可混淆 |
|---|---|---|
| Role slot | raw row byte `+0x2E`；record `+0x04`；array index<=9 | 不等於角色授權或 Server 實際數量 |
| Available record | ctor `4D3D81 +5C=0`；writer `4D4154 +5C=1` | full mask/GUI list hit 不是它 |
| Full mask | `4B8A05 ID−1`，`4B8A0B shl dx,cl`→`F94240` WORD | ID0可寫record但mask位0；id>9也能參與mask計算 |
| Mask consumer | `4D3FD4 record+4`→`4D3FDD shl eax,cl`→`4D3FDF [F94240]`→AND/boolean | **不等同檢查 record+5C** |
| Detail list | `FE1DF4` entry stride8；`665150` list-hit return | list-hit≠record usable |
| B6 Page selection | `672F00` ECX=0 時取 child owner+0xD8 | 不是 wire +0xD8 |
| Player click | `5F4787` compare event control identity；`5F47AC` UI value+1 | 必須再查 index/record 及 queue gate |

另有本次原件新核的**UI→選角 C2S 前置門檻**（選角回覆屬 G）：

```asm
5F4787 cmp edx,[ecx+20]     ; event-control identity
5F4790 mov eax,[ecx+CC]
5F479A mov eax,[eax+DC]
5F47A4 mov eax,[eax+20]     ; UI selector value if structures exist
5F47A9 or eax,-1            ; fallback when missing
5F47AC inc eax
5F47AD mov [UIOwner+C8],eax ; candidate zero-based index
5F47B3 call 404BA0
5F47B8 mov ecx,[Client+6924] ; RoleStore
5F47C4 cmp eax,9
5F47CD imul eax,eax,0x210
5F47D5 cmp dword[record+5C],0
5F47D9 je 5F4903             ; absent -> no select
5F47E7 call 414680
5F47F5 call 4A3B80           ; conditional C2S0x42 builder
```

此外 `5F486A`、`5F48D5` 另有不同控件、`UIOwner+0xCC` gate與 `4A3B80(index,mode0/mode2)`。不能由單一點擊推論所有選角 UI 相同。`66539D` 的 virtual+0x90(bool) 來自兩個本地顯示/比較數值，**不是直接由 +5C 控制的可見 disabled/enable 官方定義**。角色真實進場、S2C0x42/43 拒絕/成功要留給 G+T05，W20 只驗 local gate。

## 6. 玩家情境、合成反例與 Server 契約交接

| Case | S2C input | 已證 Client 結果 | C2S/未知 |
|---|---|---|---|
| FULL N0 | app2 65B；header name可空/非空 | prefix writer、mask=0、共同4E5FB0 | gate允許仍可 queue C2S24；不證清空所有舊record或開建角 |
| FULL ID1 | 65+53=118B，53B UTF16 name有NUL、row ID1 | record[1]+5C=1、mask bit0 | gated C2S26(ID1)，list-end C2S24 |
| FULL ID0 | 同上 ID0 | record[0]+5C=1，但 mask ID−1 的16-bit result0 | 仍可 queue C2S26，不能以mask推 flag |
| FULL ID10 | 同上 ID10 | **writer 被跳過**，後段仍計mask/post | gated C2S26 仍可能出現；不是有效角色 |
| FULL trailing | L=65+53N+r, 1..52 | 本地 loop floor，只處理 N個完整 row | 合成 Server 應拒絕非法尾段；不是官方 Client 原生 guard |
| DELTA N0 | app2B 2..54B | no row writer，仍4E5FB0 | 此 handler 無逐列26/list-end24；**不證全撤銷** |
| DELTA ID1 | app2B 55B | 同 RoleStore 的 record[1]+5C=1 | 不是招募/建角 ACK |
| DELTA ID10 | app2B 55B | skip row writer、仍 post | 無獨立 error enum |
| S2C B6 present | 正確 active scene/Page/result0/有效record | UI record/child virtual paths | 不證上游官服必然發 B6 |
| S2C B6 absent | flag0/invalid index | 673790 placeholder | 不是 Server rejected |
| F42EF list hit + flag0 | 8B list entry 存在 | 665150可能return1，**detail不填入** | local event，不是 wire |
| 玩家有效角色點擊 | control identity/index<=9/flag1 | 可達4A3B80 conditional C2S42 | 收到官方批准及切世界仍 UNKNOWN |

對 Server 開發的**相容要求候選**（交 S00 去重、非現成官服規則）：能構造完整的 app2 65B header、app2B 2B header、正確 53B row、UTF16 NUL 限於前21 WCHAR、0..9 role index；避免使用非法長度/額外殘留尾段；需要設計 Session/角色授權、全量或增量回覆、可能的撤銷/重選/重試、C2S26/24回應/忽略政策。**不能**要求原服「一定 app2→app2B→B6」，無原版網路 trace或 Server 原始碼。

## 7. 四類剩餘問題與解阻（不得用 Server-only 未知停止可做的 Client 分析）

- **Client 待逆向**：全域 record+0x5C reset/revoke writer（含 singleton reset/析構、scene切換），以及 full N0 遇到舊 RoleStore 是否重新建構；`FE1DF4` 列表 entry 的所有 producer/頁面 event listener、`665150` 的 visible/enabled 具體 callee、`673790` GUI資源、active scene 的 S2C2B 其它 override；G 工作包正向選角 S2C結果仍未知。
- **Server 待開發**：角色可操作權威、角色建立/招募/撤銷、full/delta 何時發、是否觸發 B6、DB/Session/角色初值、C2S26/24 的語意／回應由相容 Server 自主 ADR；請勿標成官服 MUST。
- **跨功能待整合**：T02 framing/Conn/dispatch，T03名單與UI，T04 playable role與初值，T05 進世界，T06 同版角色 GUI 資源；S00 既有 `SPEC-CHAR-0001`、`SPEC-FLOW-0001` 和 `GAP-CHAR-0001/2/3` 由 S00 正式去重，T03 不私改 owner/catalog。
- **待遊玩驗證**：另經使用者授權在隔離環境以**明示 synthetic** 的 full/delta/B6 測試角色畫面、缺席、失敗、重登；原版官服 C2S/S2C 因果配對須同版合法多 Conn pcap 或驗證過的 Server source。這次未執行 Client。

### 逐工作包結論

- **W17**：full prefix新欄位、53B row、N0/ID>9、C2S26/24、mask、短包反例 **Client 有界原生交付完成**；不等於 total-length 全程安全。
- **W18**：真實 0x2B network→singleton→handler、shared pointer、delta與full非等價及 reset 界線 **Client 有界完成**；全域角色撤銷未知。
- **W19**：B6→local F4278→Page→record或placeholder 與 F42EF list-hit 反例 **Client 有界完成**；資源/UI實測未完成。
- **W20**：index<=9、兩種 available/mask、list-hit及 UI→C2S42 gate **Client 有界完成**；button完整 enable/visible/Server批准屬 G/T05/T06 後續。

**沒有**將正式 RR-0009／RR-0010 或 T01 FULL-PASS 的狀態自行改寫。下個 F W21～W24 追真正可操作 Role 招募建立；G W25～W28 追選角回覆與切場，不把已有的局部 UI 資料等同端到端可玩。

## 8. 可重跑第一手核對

```bash
python -B 20261031-T03-E-verify.py /path/Tartaros.bin --exe /path/Tartaros.exe
# 485 / 485 original .text exact instruction starts + PE/vtable/event map/stride PASS
# 不執行遊戲、不聲稱 T01 FULL-PASS 或官服回覆時間
```

驗證腳本以經第一手反組譯定位的 485 個 `(VA,raw opcode bytes)` 內嵌，非 485 個完整函式語意驗證。SHA 不符就拒絕執行。所有 Git blob/commit ID 以實際上傳、遠端核對結果為準。
