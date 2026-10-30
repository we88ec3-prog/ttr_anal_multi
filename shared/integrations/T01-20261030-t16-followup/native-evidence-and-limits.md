# KR T16 本次限定原生更正：獨立證據與禁止外推

**原件 SHA256** `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；.text VA 0x401000/raw 0x400 => raw=VA-0x400C00；.rdata VA 0xBD2000/raw 0x7D0600 => raw=VA-0x401A00（只針對 .rdata）。

## A. 已符合精確通知修正範圍

### T01-RETURN-T16-002-9c70bd9f

- **裁決：RESOLVED（僅本 ID，非整篇原稿）。** 0x6F4A94 ESI=1；缺檔跳轉 0x6F4BCF，0x6F4C07 EAX=ESI；成功解析時以 ESI=0。修正 C++ 偽碼的 raw-status 極性。
- 來源：原稿與 T16 作者勘誤的 *精確 Git blob SHA*，見 [43 筆來源紀錄](notice-review.json)。修訂形式為保留歷史原文的獨立 erratum，不覆寫原稿。

### T01-RETURN-T16-005-82389c1b

- **裁決：RESOLVED（僅本 ID，非整篇原稿）。** 0x53FEB0 根函式 44 條連續可解碼指令、7 個直接分支目標均為指令起點；0x53FECF 非空轉換值，0x53FF0E 始終用 [ESI+40] 走原節點。
- 來源：原稿與 T16 作者勘誤的 *精確 Git blob SHA*，見 [43 筆來源紀錄](notice-review.json)。修訂形式為保留歷史原文的獨立 erratum，不覆寫原稿。

### T01-RETURN-T16-013-36353f64

- **裁決：RESOLVED（僅本 ID，非整篇原稿）。** 0x8438C0 根函式 47 條連續可解碼指令、6 個直接分支目標均為指令起點，雙 ret4；0x843901 signed cmp key,[best+C]，0x843904 jl 0x843915 排除 key<best。
- 來源：原稿與 T16 作者勘誤的 *精確 Git blob SHA*，見 [43 筆來源紀錄](notice-review.json)。修訂形式為保留歷史原文的獨立 erratum，不覆寫原稿。

### T01-RETURN-T16-046-2170ef08

- **裁決：RESOLVED（僅本 ID，非整篇原稿）。** Event.stp TutorialMain.lua proto5 PC20/40/136 原生 words 0080801C/0100801C/0080801C，Lua5.1 CALL 的 C=2 表示1個結果，而不是2個。
- 來源：原稿與 T16 作者勘誤的 *精確 Git blob SHA*，見 [43 筆來源紀錄](notice-review.json)。修訂形式為保留歷史原文的獨立 erratum，不覆寫原稿。

### T01-RETURN-T16-070-CONT02-C06

- **裁決：RESOLVED（僅本 ID，非整篇原稿）。** 0x807A8F marker 存 [ebp-2]、0x807A93 len 存 [ebp-4]，0x807AE2/807AE9 複製 DWORD，header 為 LE16(len)+LE16(1A68)。
- 來源：原稿與 T16 作者勘誤的 *精確 Git blob SHA*，見 [43 筆來源紀錄](notice-review.json)。修訂形式為保留歷史原文的獨立 erratum，不覆寫原稿。

### T01-RETURN-T16-070-CONT02-C09

- **裁決：RESOLVED（僅本 ID，非整篇原稿）。** 0x80620C/0x806234 以 connection+501C 為 stream 基準；callee+5004/+500C 即 connection+A020/+A028，buffer 始於 connection+5020。
- 來源：原稿與 T16 作者勘誤的 *精確 Git blob SHA*，見 [43 筆來源紀錄](notice-review.json)。修訂形式為保留歷史原文的獨立 erratum，不覆寫原稿。

### T01-RETURN-T16-070-CONT02-C13

- **裁決：RESOLVED（僅本 ID，非整篇原稿）。** 0x807BD8 BA33260000 為 mov edx,2633；0x807BDD C744242004000000 為 mov [esp+20],4。
- 來源：原稿與 T16 作者勘誤的 *精確 Git blob SHA*，見 [43 筆來源紀錄](notice-review.json)。修訂形式為保留歷史原文的獨立 erratum，不覆寫原稿。

### T01-RETURN-T16-071-CONT02-C05

- **裁決：RESOLVED（僅本 ID，非整篇原稿）。** 0x8068F3 push EAX 對應 OVERLAPPED conn+A050；0x8068F7 ECX=EAX+14；0x806909 push ECX 是 WSABUF conn+A064。
- 來源：原稿與 T16 作者勘誤的 *精確 Git blob SHA*，見 [43 筆來源紀錄](notice-review.json)。修訂形式為保留歷史原文的獨立 erratum，不覆寫原稿。

### T01-RETURN-T16-071-CONT02-C06

- **裁決：RESOLVED（僅本 ID，非整篇原稿）。** 0x806958 pop EDI；0x806959 pop ESI；0x80695A 33C0 xor EAX,EAX，保留原有錯誤回傳 0 行為。
- 來源：原稿與 T16 作者勘誤的 *精確 Git blob SHA*，見 [43 筆來源紀錄](notice-review.json)。修訂形式為保留歷史原文的獨立 erratum，不覆寫原稿。

### T01-RETURN-T16-071-CONT02-C08

- **裁決：RESOLVED（僅本 ID，非整篇原稿）。** PE .rdata VA BD2000/raw 7D0600；vtable C51748→raw 84FD48，11 slots，其 +0x10 槽為 8069A0。
- 來源：原稿與 T16 作者勘誤的 *精確 Git blob SHA*，見 [43 筆來源紀錄](notice-review.json)。修訂形式為保留歷史原文的獨立 erratum，不覆寫原稿。

### T01-RETURN-T16-071-CONT02-C14

- **裁決：RESOLVED（僅本 ID，非整篇原稿）。** 0x807DAB 8BF8 mov edi,eax；0x807DAD E8EEC2FFFF call 8040A0；舊重複 ellipsis 不是 ASM 指令。
- 來源：原稿與 T16 作者勘誤的 *精確 Git blob SHA*，見 [43 筆來源紀錄](notice-review.json)。修訂形式為保留歷史原文的獨立 erratum，不覆寫原稿。

## B. 直接原生局部資料（選錄）

```asm
006F4A94 BE 01 00 00 00         mov esi,1
006F4AA5 0F 84 24 01 00 00      je 6F4BCF
006F4C07 8B C6                  mov eax,esi
0053FECD FF D2                  call edx  ; result EAX
0053FECF 85 C0                  test eax,eax
0053FF0E 8B 76 40               mov esi,[esi+40] ; original node
00843901 3B 72 0C               cmp esi,[edx+0C]
00843904 7C 0F                  jl 843915 ; signed key<best => sentinel
00807A8F 66 89 45 FE            mov [ebp-2],ax ; marker
00807A93 66 89 55 FC            mov [ebp-4],dx ; length
00807AE2 8B 4D FC               mov ecx,[ebp-4]
00807AE9 89 08                  mov [eax],ecx
0080620C 8D 8E 1C 50 00 00      lea ecx,[esi+501C]
00806234 8D BE 1C 50 00 00      lea edi,[esi+501C]
00807BD8 BA 33 26 00 00         mov edx,2633
00807BDD C7 44 24 20 04 00 00 00 mov [esp+20],4
008068F3 50                     push eax ; conn+A050 OVERLAPPED
008068F7 8D 48 14               lea ecx,[eax+14] ; conn+A064 WSABUF
00806909 51                     push ecx ; WSABUF
0080695A 33 C0                  xor eax,eax
00807DAB 8B F8                  mov edi,eax
00807DAD E8 EE C2 FF FF         call 8040A0
```

- .rdata raw `0x84FD48` 依 little endian 11 DWORD 的 virtual targets：`806670,806CF0,806850,8068B0,8069A0,806A00,806AD0,806F60,806F80,806FC0,807090`；其中 5th slot（offset +0x10）= `0x8069A0`。
- Lua `Event/TutorialMain.lua`：member bytes 5480，SHA256 `662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809`。proto5 PC20=`0080801C` (B=1,C=2)、PC40=`0100801C` (B=2,C=2)、PC136=`0080801C` (B=1,C=2)；Lua5.1 C=2 含義為「1 result」，B-1 分別為 0/1/0 引數。

## C. 非本次通過、不得誤移交的範圍

1. `0x4ADD88 C7 80 F4 09 00 00 B0 ED 4A 00` 安裝 callback `0x4AEDB0`，該入口 `55 8B EC` 與 `0x4AF1E7 ret 0xC` 直接支持獨立函式；舊 T01 的 `0x4AEDAF` 反證失效。但 `T16-026` 原附錄完整 rooted CFG/全部語意還沒由 T01 審畢，仍 `READY_FOR_REVIEW`。
2. `0x8060FA cmp [esi+A0A4],0x12C`，`0x806104 jle` 是 signed `>300` gate；`0x804AFC` 減5、`0x804B13` 加5、`0x804AF0` reset0。不能將 A0A4 稱為 queue list count；完整 A078 資料流及作者原稿重複敘述未查盡，`T16-069` 未結案。
3. TutorialBase.lua member 1416 bytes，SHA256 `26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744`；修正 56-hex 誤引，但其 14 個通知的所有逐篇依賴與 Git 404 歷史語意仍待核。
4. T16-092 四個指令地址及 16 篇附錄 25 次局部 window 對錯已確認，**尚缺全圖 root JSON、所有 branch/calls 和衍生主張驗證**。不能用局部窗口一致性當作全文 pass。

## D. 重要責任界線

- **Client 待逆向**：Quest 接受/完成 C→S、S→C 回覆與 UI/NPC writer；涉及 callback 的動態接收者；session 異常與上下游完整資料流。
- **Server 待開發**：相容任務規則/拒絕/持久化，自行 ADR，不冒充官方內部決策。
- **跨功能待整合**：T02/T03 socket、T16 quest、T06 UI、T14 事件、T15 儲存對接。
- **待遊玩驗證**：原版 Client 未執行；沒有真實跨端遊玩/ACK 驗收。

純指令窗口與工具解碼**不能**作整份 T16 的 FULL-PASS、任何 RR `ACCEPTED` 或 SPEC `STABLE`。
