# T16-105 — KR receiver 註冊表／runtime record writer → 條件過濾 → 物件旗標的有界新證據（BIN-first）

- 作者：`chatgpt-web roy`；本次研究記錄時間：`2026-10-29T21:11:36+08:00`（Asia/Taipei）。
- 範圍：KR T16 Quest & Story Progression。**本次為實際研究第一至第三輪合併的單一正式段 T16-105；並非 Quest S→C opcode 或 NPC/UI 動態已全部還原。**
- 權限：原始 BIN／EXE 唯讀、未啟動／附加／修改遊戲；**沒有研究稿 Commit／Push**，此文件是供下載的本地完整原稿。禁止提交 `04` 交接，禁止推 main。

## A. 遠端開工治理、派工與同步的可驗證記錄

1. 讀取本次上傳的 `02-PROJECT-SHARED-INSTRUCTIONS.md`、`03-PROJECT-T16-INSTRUCTIONS.md`、`04-T16-NEXT-CHAT(4).md`；權威以 GitHub 最新 main 為準。
2. GitHub main SHA：`e751b18922d205d86dea9f280cfd060f62752bc7`。已查 `AGENTS.md`、`kr/tasks/T16/README.md`、`task.json`、`research/dispatch/README.md`、`research/dispatch/inbox/T16.md`、`research/requests/index.json`、`shared/verified-knowledge/README.md` 及相關 T01 整合結果。
3. 開工前 T16 工作分支 HEAD：`a041f009671be43bf2ba001f128427ba521e72c4`；相對 main：diverged，Ahead 17、Behind 148。以 **head=main, base=t16/roy/chatgpt-web** 建立 [PR #16](https://github.com/we88ec3-prog/ttr_anal_multi/pull/16)，執行真正 **Merge commit** `5e40a867a577d83e55e759894cc5b0c3d7aff9fa`（只作預先授權的同步程序）。同步後 connector 反查 `main...t16/roy/chatgpt-web`：Ahead **18**、Behind **0**、merge base 為上述 main HEAD。不是覆蓋文件或反向 merge。
4. T16-104 完整原稿 `kr-temp-roy/20261028-234943-chatgpt-web-roy-T16-104-KR-dual-handler-tables-and-record-parser-boundary.md` 在已同步分支仍可讀，Git blob `5eb2af43b17e2969265ace0d0a2fbd367c260eb5`，未變。
5. RR 台帳當時 8 筆、沒有 `owner_task=T16`，T16 衍生 inbox 明示暫無待辦；沒有聲稱認領／修改 `CLAIMED` 或 `ACCEPTED`。KR/TC 隔離。
6. T16 README T01 退回共 **43** 條（35 筆階段 `NEEDS_FIX`；8 筆續批中 69 一筆 `NEEDS_QUALIFICATION`、70 三筆與 71 四筆 `NEEDS_FIX`）。按政策先確認其效力，因使用者本次**明確要求完成檢查後啟動 T16-105**，歷史修正版依原 T01 流程另行排程；未更改其狀態，也不以本段代替更正。T16-70 的 WORD 順序／stream-offset、T16-71 的 WSABUF/vtable raw、T16-92 的錯誤座標不在本段直接引用為已驗證。本文任何定位都以本次 BIN 原始位元組為準。
7. `shared/verified-knowledge/` 自述共 **7 個限定 FULL-PASS 子主張**，已查 receiver exact lookup/erase 等條目，但沒有發現直接替 T16 的 Quest socket→writer→NPC UI 提供完整路徑的驗證成果；FULL-PASS 須由 T01 認證，本文不自動升級。

## B. 第一手原件、版本及二進位地址換算

- KR `Tartaros.bin`：`12,472,320` bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- KR `Tartaros.exe`：`2,594,816` bytes；SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- PE header：`MZ`、`PE\0\0`，PE offset `0x120`，ImageBase `0x00400000`；NumberOfSections=4。各 section 從本次原件 PE header **重新讀出**，非僅沿用舊筆記：
- `.text` VA `0x00401000`、vsize `0x7D01F0`、raw `0x00000400`、rawsize `0x7D0200`
- `.rdata` VA `0x00BD2000`、vsize `0x18E07C`、raw `0x007D0600`、rawsize `0x18E200`
- `.data` VA `0x00D61000`、vsize `0x2873D8`、raw `0x0095E800`、rawsize `0x22B800`
- `.rsrc` VA `0x00FE9000`、vsize `0x5AF58`、raw `0x00B8A000`、rawsize `0x5B000`
- 本段程式指令全部位於 `.text`，因此使用 `raw = VA - 0x400C00`。**資料 VA 屬 `.rdata` 或 `.data` 時另行使用 section mapping**，例如指標表與跳表在 `.text` 的資料區不能被反組譯器錯判成可達指令。
- 靜態檢查工具：Python `struct`／`hashlib` 讀原始 bytes；`objdump` x86 Intel 只作 bytes 解碼，不是 Ghidra 語意認證。沒有真實遊戲封包或動態資料流觀測。

## C. 本段研究結果（先列嚴格邊界）

**有界新增原生證據：** 已從 `0x4B2190` 以原始 BIN 直接解碼出 11 路 local subtype 跳表、各路長度增量、前置退出與 error-log 續行；`0x53D840` 解析並建立／改寫 `0x18` bytes runtime 記錄中的確切欄位，`0x500E00` 從 `[0xFAB134]` 比對 `record+0x14、+0x8、+0x6`，用條件式產出 vector；`0x635CA0` 連續呼叫 `0x500950` 與 `0x500E00` 並將兩個結果向量是否非空轉為 `object+0xB4/+0xB5` bytes。`0x635F10` 在下一步處理指標樹／容器，而非目前已證的 NPC 顯示操作。

**仍未證：** 取得原始 receive frame 的確定 dispatcher 與其選取「index 66」的算式；網路 opcode/封包方向；`0x635CA0` 所屬類別是否 NPC/UI；Quest16 完成後 Quest15 變可接／接取回覆的實際結果；相容 Server 需要的精確 wire 格式。禁止把 `+0x214` table slot 或 `input[5]` subtype 直接命名為 S→C wire opcode。

## D. 第一輪 T16-105 — 兩張表、真正 dispatcher 的定位限制、parser 完整 jump table

### D.1 已證前段的兩張表與本段核對方式

- receiver object `0x4ADD50`：以 `[obj+4+8*i]` 的 8-byte entry 初始化 3029 個 callback/context；index 66 → `obj+0x214` 的 callable 被 `0x4ADF3D` 寫成 `0x4B2190`；預設 callable `0x4B7D40`。
- 另一張全域表 `0x4B7DC0`：`0xFD2CFC` 起每個 8-byte entry，預設 `0x4B7EC0`；用途／轉發方式有別。這是保留的 T16-104 limited finding；不能由相同 entry layout 推導兩表使用相同 runtime dispatcher。
- 針對 `0x4B2190`，本段對 **`0x4B22E0` 11 筆 DWORD 跳表原始 bytes** 直接以 little-endian `struct.unpack_from` 識別，不將 jump table 地址誤當可執行碼；`0x4B2231` 才是跳表 branch。從已知入口追到實際 error／return 路徑，未證 runtime caller 的 network 身分。
- 搜尋 8-byte entry stride 時，**`0x4BA790` 的 `[eax+esi*8]` 與 `[eax+esi*8+4]` 來自 `object+0x5EE8/0x5EEC` 動態 vector**，是前段已確認反例，不能誤報 handler 分派。僅以 constant `0xBD5`、`*8`、某 callback 的 immediate 參照也不能取代原生 socket dispatcher 來源證明。

### D.2 11 種 local subtype 分配（直接由兩張不同 jump table 重算）

`0x4B2190` 由 `[ebp+8]` 取 input、`[ebp+0xC]` 取長度／上界，`ret 0xC` 顯示三個 stack DWORD；第三參數語意仍未知。`0x4B21C6` 最初 cursor 為 input+4、`0x4B21C9` 累計長度為4；`0x4B221C` 讀下一 subtype byte（初始 offset +5），先做 `subtype−1` 的 unsigned 上界 ≤10。`0x4B2231` 跳到各自程式區。表如下，其中 writer 表代表 **writer 自己的 subtype 寫入分支**，不是 parser 的 dispatcher，也不能等同 network opcode。

| input[5] subtype | parser jump target | 該路徑累計長度增量 | writer subtype branch | 備註 |
|---:|---|---:|---|---|
| 1 | `0x4B2238` | `0xF` bytes | `0x53D90B` | 從原始 DWORD jump table 直接取得 |
| 2 | `0x4B2258` | `0xB` bytes | `0x53D93A` | 從原始 DWORD jump table 直接取得 |
| 3 | `0x4B2238` | `0xF` bytes | `0x53D952` | 從原始 DWORD jump table 直接取得 |
| 4 | `0x4B2240` | `0xD` bytes | `0x53D977` | 從原始 DWORD jump table 直接取得 |
| 5 | `0x4B2258` | `0xB` bytes | `0x53D9AD` | 從原始 DWORD jump table 直接取得 |
| 6 | `0x4B2240` | `0xD` bytes | `0x53D9BB` | 從原始 DWORD jump table 直接取得 |
| 7 | `0x4B2248` | `0xA` bytes | `0x53D9EA` | 從原始 DWORD jump table 直接取得 |
| 8 | `0x4B2248` | `0xA` bytes | `0x53DA09` | 從原始 DWORD jump table 直接取得 |
| 9 | `0x4B2250` | `0x9` bytes | `0x53DA3F` | parser 於 `0x4B2273` 命中 `[esi]==9`，直接循環，正常路徑不呼叫 writer；writer 表仍含此獨立入口 |
| 10 | `0x4B22C6` | 立即退出、不寫入 | `0x53DA3F` | parser 在第10類提前返回，writer 第10類地址僅為獨立跳表資料 |
| 11 | `0x4B2258` | `0xB` bytes | `0x53DA28` | 從原始 DWORD jump table 直接取得 |


- parser jump table VA `0x004B22E0`，raw `0x000B16E0`，原始 44 bytes hex：`38 22 4b 00 58 22 4b 00 38 22 4b 00 40 22 4b 00 58 22 4b 00 40 22 4b 00 48 22 4b 00 48 22 4b 00 50 22 4b 00 c6 22 4b 00 58 22 4b 00`；SHA256 `0c15c24517e7dd87b0cd322dc7c7d35510e084b31fd39fc4b471f3667677161d`。
- writer jump table VA `0x0053DA48`，raw `0x0013CE48`，原始 44 bytes hex：`0b d9 53 00 3a d9 53 00 52 d9 53 00 77 d9 53 00 ad d9 53 00 bb d9 53 00 ea d9 53 00 09 da 53 00 3f da 53 00 3f da 53 00 28 da 53 00`；SHA256 `87db1028aba184a8e37a341595604f71ffaf43569ebe3a79b1fa5412e4ad66d3`。
- `0x4B2262` 累計消耗長度 `ebx` 與總長 `edi` 比較；若超過則 `0x4B2266` push 字串並 call `0x6EDB60`。**程式是呼叫 reporter 後順序落到 `0x4B2273`，不是直接跳 error return**；在 reporter 正常返回的有界假設下繼續；未驗證 logger 是否 throw/abort。`0x4B2220` 令 `ESI=cursor+1`，`0x4B221C` 也從 `cursor+1` 讀 subtype；所以 `0x4B2273 cmp BYTE [esi],9` **確實重新檢查同一個 local subtype byte**。第9類在已證正常執行分支直接跳回 length gate、跳過 `0x53D840`；其他通過界線的 subtype 可繼續到 writer，第10類則更早由 jump table 直接退出。這是本機 parser 控制流，仍不等於 wire opcode。
- `0x4B22C6` `xor eax,eax` 後 `ret 0xC`；局部零返回不保證 Server 層拒絕或特定 UI 顯示。

### D.3 第一輪門檻

相對前段新增了整張 parser subtype/累計長度矩陣與越界 log 後續行的真實 CFG，但 **尚未找到 object table 或 global table 的 runtime caller，並未打通 socket→slot66**。第一輪不足以聲稱本段主要端到端目標完成，因此啟動第二輪同段深入。

## E. 第二輪 T16-105-2 — writer 的 0x18 byte 欄位與 record filter 的實際動態判斷

### E.1 `0x53D840`：既有記錄搜尋、建新與通用欄位寫入

- `0x53D848..0x53D865` 取第一個參數作 `[container+0x10]` 開始、`[container+0x14]` 結束的動態陣列，透過位元乘法將距離換算成 **0x18-byte stride** 的元素數。`0x53D86C..0x53D880` 搜尋 `WORD [record+2]==WORD [esi+4]`。找到時按 `0x18` 計算舊元素；找不到時 `0x53D8A8 call 0x5F84F0` 建新，再以 `[end-0x18]` 當元素。
- `0x53D8B6` 寫 `WORD [record+0x14] = WORD [ebp+0xC]`；在已知 caller `0x4B22AD`，來源是初始 `WORD [input+2]`（符號擴展後的低16 bits）。**這不是 record 的 lookup key；record 搜尋用 `record+2`**。
- 通用欄位表（來源 `esi` 指向 local parser 當前 record 的起點、不是確定的 network frame 起點）：

| 目的 record 偏移 | 寫入來源 | 原始指令 | 證據／限制 |
|---|---|---|---|
| `+0x00` WORD | byte `esi+2`，若 byte `esi+0 == 2` 則覆寫 0xFF | `0x53D8C6..CA`, `0x53D8E9..F3` | 類型含義 unknown |
| `+0x02` WORD | WORD `esi+4` | `0x53D8CD..D1` | 舊元素比對用此 key |
| `+0x04` WORD | byte `esi+1` | `0x53D8BE..C2` | writer subtype selector |
| `+0x06` WORD | 依 subtype 由 `esi+8/9/10` 等位置取值 | `0x53D90B..DA38` | 各分支不同，不能套一種固定 wire 格式 |
| `+0x08` WORD | 依 subtype 由 `esi+7/9` 等位置取值 | `0x53D913..DA34` | 供 filter 比較 |
| `+0x0A` byte | byte `esi+3` | `0x53D8D5..D9` | 意義 unknown |
| `+0x0B` byte | byte `esi+0` | `0x53D8E3..E6` | 意義 unknown |
| `+0x0C` DWORD | subtype-specific 合成數或直接來源 | `0x53D91B..DA3C` | 不可不檢查分支就命名狀態碼 |
| `+0x10` DWORD | byte `esi+6` zero-extend（4號另寫一次相同來源） | `0x53D8DC..E0` | 意義 unknown |
| `+0x14` WORD | caller input+2 WORD | `0x53D8B6..BA` | 後續 filter 以此比對別的 16-bit ID |

- writer 入口 `ret 8` 表示 caller 推入兩個 stack 參數，第三個暫存器來源 `ESI`；`0x4B22BC` 的現場 `ESI=[esp+14]` 由 `0x4B2224` 保存原指標。`record+6/+8` 是否描述進度，需要原生資源或實際封包對應；目前只可稱 **有號 WORD threshold**（filter 的 `jl` 是 signed）。

### E.2 `0x500E00` 是 record-consuming filter 而非 Quest S→C handler

- 入口 `ret 0xC`，依 `[ebp+8]` owner 的 `+0x5ED0` 開始，`0x500E62 mov count,0x14`，每步以 `0x500F5E add cursor,2` 推進，**最多20個 WORD slot**；每個非0 slot 的值以 `0x503D20` 在 `[owner+0x5EAC]` 指向的 lookup 結構查候選。
- `0x500EB5 cmp DWORD [eax+0x2C],ecx` 將找到的 lookup 物件之 offset +0x2C 與第2參數比較；失配 skip。
- 在 `0x500EF0..0x500F15`，`[0xFAB134]` 內建向量每筆 `0x18` bytes；先 `WORD [record+0x14]==di`，匹配才比較 `WORD [record+0x08]` 與 `WORD [record+0x06]`，`0x500F0E jl` **若 +8 signed WORD 小於 +6 signed WORD** 即 skip candidate。對沒有匹配的 runtime record，這一條特定 gate 不會排除該 candidate。
- `0x500F4C` 又檢查 lookup 候選 `[candidate+4]!=2`，符合時 `0x500F59 call 0x443D10` 把 candidate 加入 output vector（經 caller 傳來的第三參數）。因此「有 record 且閾值未達 → skip；record 不匹配或符號閾值條件不成立 → 可繼續其他 gate」是**有界條件分支**，不可反推 Quest 已完成／可接。
- `0x500F6D` 正常結尾 `mov eax,1` 是 **filter 函式返回值**；候選結果需看第三參數的 output vector，不能把 EAX=1 當作已領取任務。直接 caller 定位包含 `0x62F61F`、`0x62FB7F`、`0x635D67`；不同 owner/callee 來源尚需逐一驗證，不合併為同一場景。

### E.3 有界 writer→reader 接續，與反證

可證的靜態關係為：`0x4B2190 → 0x53D840 → [0xFAB134]`（writer data），及 `[0xFAB134] → 0x500E00`（consumer read）。`0x4B2190` 是否實際由 socket S→C 走入仍 unknown，且 `record+2` 的識別 key、`record+0x14` 的 lookup comparator key 分別來自不同 input 欄位，不能因數值可能相等就說同一 key。

第二輪新增對玩家候選狀態有用的完整 filter gate、writer fields 與 downstream caller，**但尚未確認 UI 所屬物件**。因此啟動第三輪。

## F. 第三輪 T16-105-3 — 具體 consumer 的旗標更新、候選容器、未閉合反證

### F.1 `0x635CA0`：兩個過濾器結果→兩個 byte flags

- 正常前提：`0x635CC9` 測 `[edi+0xB8]` 非零，否則直接返回；`EDI` 的動態類別/玩家畫面身份未知。建立兩個本地 vector：`[ebp-0x4C..-0x44]`、`[ebp-0x3C..-0x34]`。
- `0x635D18..D28` 以 `owner=[edi+0x84]`、固定 lazy owner `0xFAB2A0` 交 `0x500950`，結果寫第一 vector。
- `0x635D57..D67` 同一 owner 交 `0x500E00`，結果寫第二 vector；這些資料是 local candidate lists，不能因叫 state filter 就說 NPC 畫面已刷新。
- `0x635D6C..D84` 比較兩對向量 start/end：`setne dl` → `BYTE [edi+0xB4]`、`setne cl` → `BYTE [edi+0xB5]`。**這是兩個分開的 byte flags**，並非 `DWORD +0xB4`。這兩個旗標可能是兩種候選清單非空狀態，沒有足夠證據給原版 UI 文字語意。
- `0x635D97..D3D` 再從 `[edi+0xB8]+0x40/+0x44` 迭代 0x24-byte item，呼叫 `0x5243A0` 作篩選／查詢；其具體判斷仍需下游原件。`0x635E77` 將 `[edi+0x98]` 清零，非空集合時 `0x635E84` 呼叫 `0x89289D`，以除法餘數選出候選，寫 `[edi+0x94]`，再 `0x635EAC` 呼叫 `0x635F10`。集合空時 `0x635EB3..BF` 清 `[edi+0x94]` 並清樹 `edi+0x9C`。
- `0x635F10` 首先用 `edi+0x9C` 做容器 clear；再由全域 `[0xFE1BD0]` 的樹查 key，將 payload 指標填入 `edi+0x9C` 的容器，**非明確的 UI render call**，無法證明這一時刻已更新螢幕／NPC 標記；因此本段稱「狀態與候選容器更新」而非「NPC/UI 更新完成」。

### F.2 為何仍不能報告真正 receiver dispatcher

- `0x4ADF3D` 寫入 `receiver+0x214` 的 callable 只證明註冊，不證明收到 socket 資料時如何取得索引66。需要證明某個已完成 frame parser 產出有界 index、由特定 receiver object 的 base 取 `[base+4+index*8]` 和 context，按 ABI 推入 buffer/len/第三 arg，並透過那個 function pointer 進 `0x4B2190`。
- 全域表 `0xFD2CFC` 的預設 `0x4B7EC0` 會往 live receiver 的 vtable slot+4 轉發；內嵌表 default `0x4B7D40` 的 vtable trampoline 又不同；無 runtime object provenance 不得跨越兩者直接推定。
- 對具有 8-byte stride 的其他動態 vector 或 iterator 不可假陽性；`0x4BA790` 明確反例。此次未獲 network pcap／原版伺服器回包／runtime 錄像觀察，亦沒有原版 Server 內部狀態的證據。
- **即使這條 writer→filter→flag 的本機資料路徑成立，仍沒有確立 Quest16/15、NPC 可接旗標、UI 顯示時序、S→C opcode、ACK 或 C→S 接取/交付封包。**

### F.3 第三輪與停止門檻

本段第三輪已有重大而有界的下游實證增量：`0x635D67` 實際呼叫 reader、`0x635D7B/84` 寫兩個 state bytes、`0x635E9D` 候選選擇及 `0x635F10` 容器更新。但三輪仍無法解除最優先 dispatcher/wire 阻塞；依共用三輪規則，**在完成第三輪後以明確阻塞與下一段入口結束本正式段**，不假稱 network/UI 閉環已完成。

## G. 有界 C/C++ 偽碼（為解讀原生分支所寫，不是反編譯出原始型別）

```cpp
struct Record18 {
  uint16_t modeAt0;        // +0, subtype-dependent override possible
  uint16_t lookupKey2;     // +2, compared against parser record[+4]
  uint16_t subtype4;      // +4, from parser record[+1]
  int16_t threshold6;     // +6, compared signed by filter
  int16_t current8;       // +8
  uint8_t flagA;          // +A
  uint8_t flagB;          // +B
  uint32_t payloadC;      // +C
  uint32_t other10;       // +10
  uint16_t match14;       // +14, caller input[2:4]
  uint16_t notResolved16; // +16, no complete proof here
}; // 0x18 bytes by BIN stride, hypothetical typed names

// The input is a local parser buffer, not a proven wire packet.
void writeParsedRecord(Vector& cache, uint8_t* esi, int16_t outerID) {
  Record18* r = find_by_key(cache, little_u16(esi+4));
  if (!r) r = append_new(cache); // underlying 0x5F84F0 details omitted
  r->lookupKey2 = little_u16(esi+4);
  r->match14 = (uint16_t)outerID;
  r->modeAt0 = esi[0] == 2 ? 0xFF : esi[2];
  r->subtype4 = esi[1];
  r->flagA=esi[3]; r->flagB=esi[0]; r->other10=esi[6];
  // individual subtype handler writes +6,+8,+C; no invented wire semantics
}

// Schematic of a bounded subpath, subject to valid owner, lookup and memory.
void filterCandidates(const Owner* o, int group, Vector* dst) {
  for (int i=0; i<20; ++i) {
    int16_t id = ((const int16_t*)(o->dataAt5ED0))[i];
    if (!id) continue;
    auto* questMeta = lookup(o->lookupAt5EAC,id);
    if (!questMeta || questMeta->field2C != group) continue;
    bool below = false;
    for (auto& rec : globalCacheFAB134) {
       if (rec.match14 == (uint16_t)id && rec.current8 < rec.threshold6)
           below = true;
    }
    if (below) continue;
    auto* candidate = lookup(o->lookupAt5EAC,id);
    if (candidate && candidate->field4 != 2) dst->append(candidate);
  }
}
// Unknown: first-match/break semantics and independent gates must be
// preserved by real implementation; pseudo-code is only a schematic.

void refreshCandidateFlags(Object* object) {
  if (!object->fieldB8) return;
  Vector v1,v2;
  query500950(globalFAB2A0,object->field84,&v1);
  filter500E00(globalFAB2A0,object->field84,&v2);
  object->byteB4 = (v1.begin != v1.end);
  object->byteB5 = (v2.begin != v2.end);
  // downstream 0x24-byte item pass, 0x94 pointer and +0x9C tree changes
}
```

**偽碼限制：** `+0x5ED0` 是 input owner 相對偏移；`[0xFAB134]` 的 record vector 是另一個 pointer provenance；`edi+0xB4/B5` 是 consumer object 的 bytes；三者不能因 offset 相似而合併成同一 class。程式碼只是調查抽象且未覆蓋 exception/allocator/重入行為，若須實作 Server，應先有 wire 測試向量，不能直接採用本偽碼。

## H. 玩家情境 × Client/Server 端到端證據矩陣

| 玩家情境 | C→S opcode/長度/時序 | S→C wire 與真正 dispatch | 已證 Client 本地狀態 | 玩家可見 NPC／UI | 分工與驗收 |
|---|---|---|---|---|---|
| 初始 receiver 註冊 | unknown | `0x4ADF3D` 寫 slot 66 為 `0x4B2190`；frame → slot66 unknown | 3029 對 callback/context 初始化 | unknown | Client 待逆向 |
| 收到某種具 11 類 local subtype 的 buffer | unknown | `0x4B2190` 解析 buffer、長度 gate、writer；真正 S→C unknown | `0x53D840` 建／改 0x18-byte 記錄 | unknown | Client 局部確認、wire 待逆向 |
| 狀態產生候選項目 | unknown | unknown | `0x500E00` 根據 `record+14/+8/+6` 條件產生候選 vector | unknown | Client 已證局部 filter |
| 物件更新可用候選 | unknown | unknown | `0x635CA0` 兩候選 vector → `+B4/+B5` byte，並更新 `+94/+9C` | 動態物件型別和 UI 通知 unknown | 跨功能待整合 |
| Quest16 完成 → Quest15 可接 | **unknown** | **unknown** | 尚不能把上述 record 認定為這兩個 Quest ID | **unknown** | Client 待逆向、Server 待開發、待遊玩驗證 |
| 玩家接取 Quest15 或交付 Quest16 | **unknown** | 接取 ACK/拒絕 unknown | 本地 gate/packet builder unknown | unknown | Client 待逆向、跨 T02/T14/T15 整合 |

## I. 四種後續工作狀態與精確接棒目標

### Client 待逆向

1. **P0 dispatcher**：從 `0x4ADD50` 的物件來源尋找 callback table 的實際 read+indirect-call，釐清索引如何由 framing 解析，與 `0x4B7DC0` 的全域 forwarder 分離。建議以 Ghidra rooted CFG 掃 object offset `+4+8*i` callable dereference、`+8+8*i` context、`ret 0xC` 的三 stack 引數與呼叫者 socket receiver 為高信賴閉合條件。需同時查 `0x8076F0/0x8040A0` 等前段 T02/T16 已證 generic receive 邊界，不宜由 index 66 反推 wire opcode。
2. **P0 writer 來源**：查 `0x4B2190` 的精確 frame buffer provenance，必要時捕獲依法取得的原版 KR 封包並保留 SHA/長度/前後 20 bytes；沒有資料時只保留 local parser 有界事實。
3. **P0 player-visible**：查 `0x635CA0` 的 caller、`EDI` 動態 vtable/source、`object+B4/B5` readers，以及 `0x635F10` tree 的下游 UI layout/notification，核實是否 NPC 有可接/可交付顯示。可以從真正 UI object 建構者回溯，而不是看 slot/name 做語意猜測。
4. **P0 C→S**：從 Quest/NPC UI 點選接取/交付 action trace 到 packet builder、framer 和 `WSASend`，不要假定局部 4-byte command 代表送達。

### Server 待開發

已知本地 Client 消費某類 record/篩選所需欄位，但沒有確定的 wire 接口，故此時只能開 **GAP／DRAFT 調查性規格**，不得以 `0x18` bytes record 當 wire 封包或推定原版伺服器的 Quest16→15 decision/DB transaction。實際判定/持久化屬獨立 Server 開發及 T15/T14 跨界。

### 跨功能待整合

T02 接收 framing/dispatcher；T07 場景/NPC；T14 關卡結算；T15 持久化；T03/T04 角色初始 snapshot。不得在 T16 覆寫他們的研究原稿、owner/catalog。S00 若有正式 RR，以當時 main 的台帳決定，不自行新增/認領。

### 待遊玩驗證

須在有合法測試環境與實際相容 Server 的情況下，測試「Quest16 完成 → Quest15 可接 → 點擊接取 → Server 成功/拒絕回覆 → NPC/UI 更新 → 重登恢復」。現有靜態 BIN 不構成此測試已通過。

## J. 嚴格反證與錯誤防護清單

- T01 仍有 43 條 T16 退回；本文不更動它們、不得因本段引用判定已解決。
- `0x4B22E0` 與 `0x53DA48` 是資料表；其 raw bytes 不可用 disassembler 當作有效 opcode 指令。
- `index=66` 是特定內嵌 callback table offset，**非 wire opcode**；`input[5]` 是 local subtype byte，**非已證 S→C type**。
- `0x4B7EC0`／`0x4B7D40` 是不同預設 target，絕不能混用；`0x4BA790` 的 8-byte vector 非該表。
- `0x53D840` 中 `record+2` 與 `record+14` 分別來自不同來源 bytes；未經 mapping，不得合併名詞。
- `0x500F0E jl` 是 **signed** 16-bit 比較；`record+8 < record+6` 代表此特定 filter 排除，**不代表已確認任務成功/失敗**。
- `0x635D7B/84` 是 **兩個 byte** 寫入，不是同一 DWORD；尚未找到真正畫面 consumer。
- 0x62Fxxx 歷史有錯誤指令邊界，本文僅列 direct caller `0x62F61F/0x62FB7F` 作後續入口，不把未從正式函式根 re-decode 的附近位址組裝成完整 CFG。

## K. 原始 BIN 組語與 bytes 附錄（非對話摘要）

各摘錄以下列出這次原始 BIN 真正 bytes+VA，對應研究檢查與時間；**插入的 jump table 處未以組語輸出**，須用前述 DWORD 記錄。對太長的相關函式只摘取決定性入口、分支與副作用；全函式可由原件 SHA + raw offset 重現，不冒充已核完全部 exception/allocator path。

#### 原始機器碼區間 0x004ADD50–0x004ADD78（raw 0x000AD150–0x000AD178）

區間 SHA256（含所列截點，end-exclusive）`b0bb1200fcb1aa0a2bffe5ab38f2f8b71e14731d881d03ce8c83c154a4f38335`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  4add50:	53                   	push   ebx
  4add51:	56                   	push   esi
  4add52:	8d 50 08             	lea    edx,[eax+0x8]
  4add55:	be d5 0b 00 00       	mov    esi,0xbd5
  4add5a:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4add5f:	90                   	nop
  4add60:	c7 42 fc 40 7d 4b 00 	mov    DWORD PTR [edx-0x4],0x4b7d40
  4add67:	89 0a                	mov    DWORD PTR [edx],ecx
  4add69:	83 c2 08             	add    edx,0x8
  4add6c:	4e                   	dec    esi
  4add6d:	75 f1                	jne    0x4add60
  4add6f:	ba 80 fb 4a 00       	mov    edx,0x4afb80
  4add74:	c7 40 34 30    	mov    DWORD PTR [eax+0x34],0x4b7d30
```

#### 原始機器碼區間 0x004ADF3D–0x004ADF54（raw 0x000AD33D–0x000AD354）

區間 SHA256（含所列截點，end-exclusive）`c420a63f4005e71e8fbdb57bc38b95e4e91795cad2fbee174908a48fff61d8d0`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  4adf3d:	c7 80 14 02 00 00 90 	mov    DWORD PTR [eax+0x214],0x4b2190
  4adf44:	21 4b 00 
  4adf47:	89 88 18 02 00 00    	mov    DWORD PTR [eax+0x218],ecx
  4adf4d:	c7 80 0c 02 00 00 10 	mov    DWORD PTR [eax+0x20c],0x4b2310
  4adf54:	   
```

#### 原始機器碼區間 0x004B7DC0–0x004B7DDE（raw 0x000B71C0–0x000B71DE）

區間 SHA256（含所列截點，end-exclusive）`cba6123922fd505e8b40598916e4db8cf181e156fa53af216466b0e8e1d5c843`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  4b7dc0:	b8 00 2d fd 00       	mov    eax,0xfd2d00
  4b7dc5:	ba c0 7e 4b 00       	mov    edx,0x4b7ec0
  4b7dca:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4b7dcf:	90                   	nop
  4b7dd0:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  4b7dd3:	89 08                	mov    DWORD PTR [eax],ecx
  4b7dd5:	83 c0 08             	add    eax,0x8
  4b7dd8:	3d a8 8b fd 00       	cmp    eax,0xfd8ba8
  4b7ddd:	7c                 	jl     0x4b7dd0
```

#### 原始機器碼區間 0x004B7EC0–0x004B7EF0（raw 0x000B72C0–0x000B72F0）

區間 SHA256（含所列截點，end-exclusive）`7fc738a143fdfc7844f73f59a5b9417b76ac357eb73a92a1b965213261785d30`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  4b7ec0:	55                   	push   ebp
  4b7ec1:	8b ec                	mov    ebp,esp
  4b7ec3:	83 b9 ac 5e 00 00 00 	cmp    DWORD PTR [ecx+0x5eac],0x0
  4b7eca:	74 0e                	je     0x4b7eda
  4b7ecc:	8b 89 ac 5e 00 00    	mov    ecx,DWORD PTR [ecx+0x5eac]
  4b7ed2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b7ed4:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4b7ed7:	5d                   	pop    ebp
  4b7ed8:	ff e0                	jmp    eax
  4b7eda:	0f bf 4d 10          	movsx  ecx,WORD PTR [ebp+0x10]
  4b7ede:	51                   	push   ecx
  4b7edf:	68 f8 6d c0 00       	push   0xc06df8
  4b7ee4:	e8 77 5c 23 00       	call   0x6edb60
  4b7ee9:	83 c4 08             	add    esp,0x8
  4b7eec:	33 c0                	xor    eax,eax
  4b7eee:	5d                   	pop    ebp
  4b7eef:	c2               	ret    0xc
```

#### 原始機器碼區間 0x004B2190–0x004B21D4（raw 0x000B1590–0x000B15D4）

區間 SHA256（含所列截點，end-exclusive）`512c59ed3e22b0093473f36c4a9223698267ca8c84ea1141f73293e8b390da0e`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  4b2190:	55                   	push   ebp
  4b2191:	8b ec                	mov    ebp,esp
  4b2193:	83 e4 f8             	and    esp,0xfffffff8
  4b2196:	6a ff                	push   0xffffffff
  4b2198:	68 5c 7c 94 00       	push   0x947c5c
  4b219d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b21a3:	50                   	push   eax
  4b21a4:	83 ec 18             	sub    esp,0x18
  4b21a7:	53                   	push   ebx
  4b21a8:	56                   	push   esi
  4b21a9:	57                   	push   edi
  4b21aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b21af:	33 c4                	xor    eax,esp
  4b21b1:	50                   	push   eax
  4b21b2:	8d 44 24 28          	lea    eax,[esp+0x28]
  4b21b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b21bc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b21c3:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b21c6:	8d 46 04             	lea    eax,[esi+0x4]
  4b21c9:	bb 04 00 00 00       	mov    ebx,0x4
  4b21ce:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b21d2:	75 29                	jne    0x4b21fd
```

#### 原始機器碼區間 0x004B21FD–0x004B2238（raw 0x000B15FD–0x000B1638）

區間 SHA256（含所列截點，end-exclusive）`f1124f26811f357bba2c1dffba615ff96b68ef4f808137a8fa18e45ab7c6e451`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  4b21fd:	0f bf 76 02          	movsx  esi,WORD PTR [esi+0x2]
  4b2201:	bf a0 b2 fa 00       	mov    edi,0xfab2a0
  4b2206:	e8 05 df 04 00       	call   0x500110
  4b220b:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  4b220e:	8b ff                	mov    edi,edi
  4b2210:	3b fb                	cmp    edi,ebx
  4b2212:	0f 86 ae 00 00 00    	jbe    0x4b22c6
  4b2218:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b221c:	0f b6 48 01          	movzx  ecx,BYTE PTR [eax+0x1]
  4b2220:	8d 70 01             	lea    esi,[eax+0x1]
  4b2223:	49                   	dec    ecx
  4b2224:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4b2228:	83 f9 0a             	cmp    ecx,0xa
  4b222b:	0f 87 95 00 00 00    	ja     0x4b22c6
  4b2231:	ff 24 8d e0 22 4b 00 	jmp    DWORD PTR [ecx*4+0x4b22e0]
```

#### 原始機器碼區間 0x004B2238–0x004B2278（raw 0x000B1638–0x000B1678）

區間 SHA256（含所列截點，end-exclusive）`11da537907dfb27db9d506338c60c0499de6c839f367d4e0b702f7acd51f022d`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  4b2238:	83 c0 0f             	add    eax,0xf
  4b223b:	83 c3 0f             	add    ebx,0xf
  4b223e:	eb 1e                	jmp    0x4b225e
  4b2240:	83 c0 0d             	add    eax,0xd
  4b2243:	83 c3 0d             	add    ebx,0xd
  4b2246:	eb 16                	jmp    0x4b225e
  4b2248:	83 c0 0a             	add    eax,0xa
  4b224b:	83 c3 0a             	add    ebx,0xa
  4b224e:	eb 0e                	jmp    0x4b225e
  4b2250:	83 c0 09             	add    eax,0x9
  4b2253:	83 c3 09             	add    ebx,0x9
  4b2256:	eb 06                	jmp    0x4b225e
  4b2258:	83 c0 0b             	add    eax,0xb
  4b225b:	83 c3 0b             	add    ebx,0xb
  4b225e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b2262:	3b df                	cmp    ebx,edi
  4b2264:	76 0d                	jbe    0x4b2273
  4b2266:	68 bc 6c bf 00       	push   0xbf6cbc
  4b226b:	e8 f0 b8 23 00       	call   0x6edb60
  4b2270:	83 c4 04             	add    esp,0x4
  4b2273:	80 3e 09             	cmp    BYTE PTR [esi],0x9
  4b2276:	74 98                	je     0x4b2210
```

#### 原始機器碼區間 0x004B22AA–0x004B22DC（raw 0x000B16AA–0x000B16DC）

區間 SHA256（含所列截點，end-exclusive）`130b720f0cb83b40bf0e35dbbcd78cfe9bbddc7dc7141095bbf1690700b4de33`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  4b22aa:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b22ad:	0f bf 51 02          	movsx  edx,WORD PTR [ecx+0x2]
  4b22b1:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b22b6:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  4b22ba:	52                   	push   edx
  4b22bb:	50                   	push   eax
  4b22bc:	e8 7f b5 08 00       	call   0x53d840
  4b22c1:	e9 4a ff ff ff       	jmp    0x4b2210
  4b22c6:	33 c0                	xor    eax,eax
  4b22c8:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4b22cc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b22d3:	59                   	pop    ecx
  4b22d4:	5f                   	pop    edi
  4b22d5:	5e                   	pop    esi
  4b22d6:	5b                   	pop    ebx
  4b22d7:	8b e5                	mov    esp,ebp
  4b22d9:	5d                   	pop    ebp
  4b22da:	c2 0c              	ret    0xc
```

#### 原始機器碼區間 0x0053D840–0x0053D8F6（raw 0x0013CC40–0x0013CCF6）

區間 SHA256（含所列截點，end-exclusive）`314503ac77b4c95cf2c78a75b43a6bda6fecb33a849cb3764cfecfd9d43549d0`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  53d840:	55                   	push   ebp
  53d841:	8b ec                	mov    ebp,esp
  53d843:	83 ec 18             	sub    esp,0x18
  53d846:	53                   	push   ebx
  53d847:	57                   	push   edi
  53d848:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53d84b:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  53d84e:	2b 4f 10             	sub    ecx,DWORD PTR [edi+0x10]
  53d851:	83 c7 10             	add    edi,0x10
  53d854:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  53d859:	f7 e9                	imul   ecx
  53d85b:	c1 fa 02             	sar    edx,0x2
  53d85e:	8b c2                	mov    eax,edx
  53d860:	c1 e8 1f             	shr    eax,0x1f
  53d863:	03 c2                	add    eax,edx
  53d865:	b9 00 00 00 00       	mov    ecx,0x0
  53d86a:	74 28                	je     0x53d894
  53d86c:	8b 17                	mov    edx,DWORD PTR [edi]
  53d86e:	0f b7 5e 04          	movzx  ebx,WORD PTR [esi+0x4]
  53d872:	83 c2 02             	add    edx,0x2
  53d875:	66 39 1a             	cmp    WORD PTR [edx],bx
  53d878:	74 0c                	je     0x53d886
  53d87a:	41                   	inc    ecx
  53d87b:	83 c2 18             	add    edx,0x18
  53d87e:	3b c8                	cmp    ecx,eax
  53d880:	72 f3                	jb     0x53d875
  53d882:	33 c9                	xor    ecx,ecx
  53d884:	eb 0e                	jmp    0x53d894
  53d886:	8b 07                	mov    eax,DWORD PTR [edi]
  53d888:	8d 0c 49             	lea    ecx,[ecx+ecx*2]
  53d88b:	8d 04 c8             	lea    eax,[eax+ecx*8]
  53d88e:	33 c9                	xor    ecx,ecx
  53d890:	3b c1                	cmp    eax,ecx
  53d892:	75 22                	jne    0x53d8b6
  53d894:	33 d2                	xor    edx,edx
  53d896:	8d 45 e8             	lea    eax,[ebp-0x18]
  53d899:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  53d89c:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  53d89f:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  53d8a2:	89 4d f4             	mov    DWORD PTR [ebp-0xc],ecx
  53d8a5:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  53d8a8:	e8 43 ac 0b 00       	call   0x5f84f0
  53d8ad:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  53d8b0:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  53d8b3:	83 e8 18             	sub    eax,0x18
  53d8b6:	66 8b 4d 0c          	mov    cx,WORD PTR [ebp+0xc]
  53d8ba:	66 89 48 14          	mov    WORD PTR [eax+0x14],cx
  53d8be:	0f b6 56 01          	movzx  edx,BYTE PTR [esi+0x1]
  53d8c2:	66 89 50 04          	mov    WORD PTR [eax+0x4],dx
  53d8c6:	0f b6 4e 02          	movzx  ecx,BYTE PTR [esi+0x2]
  53d8ca:	66 89 08             	mov    WORD PTR [eax],cx
  53d8cd:	0f b7 56 04          	movzx  edx,WORD PTR [esi+0x4]
  53d8d1:	66 89 50 02          	mov    WORD PTR [eax+0x2],dx
  53d8d5:	0f b6 4e 03          	movzx  ecx,BYTE PTR [esi+0x3]
  53d8d9:	88 48 0a             	mov    BYTE PTR [eax+0xa],cl
  53d8dc:	0f b6 56 06          	movzx  edx,BYTE PTR [esi+0x6]
  53d8e0:	89 50 10             	mov    DWORD PTR [eax+0x10],edx
  53d8e3:	0f b6 0e             	movzx  ecx,BYTE PTR [esi]
  53d8e6:	88 48 0b             	mov    BYTE PTR [eax+0xb],cl
  53d8e9:	80 3e 02             	cmp    BYTE PTR [esi],0x2
  53d8ec:	75 08                	jne    0x53d8f6
  53d8ee:	ba ff 00 00 00       	mov    edx,0xff
  53d8f3:	66 89 10             	mov    WORD PTR [eax],dx
```

#### 原始機器碼區間 0x0053D8F6–0x0053D938（raw 0x0013CCF6–0x0013CD38）

區間 SHA256（含所列截點，end-exclusive）`6b4f37f77136d6de4ca9ea791228a9db8ad937077a4ada4b59e9dafaa9e498dd`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  53d8f6:	0f b6 4e 01          	movzx  ecx,BYTE PTR [esi+0x1]
  53d8fa:	49                   	dec    ecx
  53d8fb:	83 f9 0a             	cmp    ecx,0xa
  53d8fe:	0f 87 3b 01 00 00    	ja     0x53da3f
  53d904:	ff 24 8d 48 da 53 00 	jmp    DWORD PTR [ecx*4+0x53da48]
  53d90b:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d90f:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d913:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d917:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d91b:	0f b6 4e 0b          	movzx  ecx,BYTE PTR [esi+0xb]
  53d91f:	0f b7 56 0d          	movzx  edx,WORD PTR [esi+0xd]
  53d923:	49                   	dec    ecx
  53d924:	81 c9 00 01 00 00    	or     ecx,0x100
  53d92a:	c1 e1 10             	shl    ecx,0x10
  53d92d:	0b ca                	or     ecx,edx
  53d92f:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d932:	5f                   	pop    edi
  53d933:	5b                   	pop    ebx
  53d934:	8b e5                	mov    esp,ebp
  53d936:	5d                   	pop    ebp
  53d937:	c2               	ret    0x8
```

#### 原始機器碼區間 0x0053D93A–0x0053D96F（raw 0x0013CD3A–0x0013CD6F）

區間 SHA256（含所列截點，end-exclusive）`026f8326b0fe59c3cbfa5b8db714b9682a4eb2f678544bee51b062f8cf6845f9`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  53d93a:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d93e:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d942:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d946:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d94a:	5f                   	pop    edi
  53d94b:	5b                   	pop    ebx
  53d94c:	8b e5                	mov    esp,ebp
  53d94e:	5d                   	pop    ebp
  53d94f:	c2 08 00             	ret    0x8
  53d952:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d956:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d95a:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d95e:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d962:	0f b7 4e 0b          	movzx  ecx,WORD PTR [esi+0xb]
  53d966:	81 c9 00 00 00 03    	or     ecx,0x3000000
  53d96c:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
```

#### 原始機器碼區間 0x0053D9BB–0x0053D9EA（raw 0x0013CDBB–0x0013CDEA）

區間 SHA256（含所列截點，end-exclusive）`708ece9310d31f0f2a0215ed00f36948787e41f77f8a5e05b82bd855c8ffe9f6`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  53d9bb:	0f b6 56 08          	movzx  edx,BYTE PTR [esi+0x8]
  53d9bf:	66 89 50 06          	mov    WORD PTR [eax+0x6],dx
  53d9c3:	0f b6 4e 07          	movzx  ecx,BYTE PTR [esi+0x7]
  53d9c7:	66 89 48 08          	mov    WORD PTR [eax+0x8],cx
  53d9cb:	0f b6 56 09          	movzx  edx,BYTE PTR [esi+0x9]
  53d9cf:	0f b7 4e 0b          	movzx  ecx,WORD PTR [esi+0xb]
  53d9d3:	4a                   	dec    edx
  53d9d4:	81 ca 00 01 00 00    	or     edx,0x100
  53d9da:	c1 e2 10             	shl    edx,0x10
  53d9dd:	0b d1                	or     edx,ecx
  53d9df:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  53d9e2:	5f                   	pop    edi
  53d9e3:	5b                   	pop    ebx
  53d9e4:	8b e5                	mov    esp,ebp
  53d9e6:	5d                   	pop    ebp
  53d9e7:	c2 08 00             	ret    0x8
```

#### 原始機器碼區間 0x0053DA09–0x0053DA47（raw 0x0013CE09–0x0013CE47）

區間 SHA256（含所列截點，end-exclusive）`4941d60c62bd0d41af22ea62f3dcd3c989f88acf7403be1c969ec9392a867439`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  53da09:	0f b6 4e 08          	movzx  ecx,BYTE PTR [esi+0x8]
  53da0d:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53da11:	0f b6 56 07          	movzx  edx,BYTE PTR [esi+0x7]
  53da15:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53da19:	0f b6 4e 09          	movzx  ecx,BYTE PTR [esi+0x9]
  53da1d:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53da20:	5f                   	pop    edi
  53da21:	5b                   	pop    ebx
  53da22:	8b e5                	mov    esp,ebp
  53da24:	5d                   	pop    ebp
  53da25:	c2 08 00             	ret    0x8
  53da28:	0f b6 56 0a          	movzx  edx,BYTE PTR [esi+0xa]
  53da2c:	66 89 50 06          	mov    WORD PTR [eax+0x6],dx
  53da30:	0f b6 4e 09          	movzx  ecx,BYTE PTR [esi+0x9]
  53da34:	66 89 48 08          	mov    WORD PTR [eax+0x8],cx
  53da38:	0f b7 56 07          	movzx  edx,WORD PTR [esi+0x7]
  53da3c:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  53da3f:	5f                   	pop    edi
  53da40:	5b                   	pop    ebx
  53da41:	8b e5                	mov    esp,ebp
  53da43:	5d                   	pop    ebp
  53da44:	c2 08 00             	ret    0x8
```

#### 原始機器碼區間 0x00500E56–0x00500EBA（raw 0x00100256–0x001002BA）

區間 SHA256（含所列截點，end-exclusive）`6684418d4c33441a3a582fddde5cde03350936fed13d45daa05f9924920d39e1`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  500e56:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  500e59:	05 d0 5e 00 00       	add    eax,0x5ed0
  500e5e:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  500e62:	c7 44 24 14 14 00 00 	mov    DWORD PTR [esp+0x14],0x14
  500e69:	00 
  500e6a:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  500e6e:	0f b7 39             	movzx  edi,WORD PTR [ecx]
  500e71:	66 85 ff             	test   di,di
  500e74:	0f 84 e4 00 00 00    	je     0x500f5e
  500e7a:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  500e7d:	8b b2 ac 5e 00 00    	mov    esi,DWORD PTR [edx+0x5eac]
  500e83:	8d 44 24 18          	lea    eax,[esp+0x18]
  500e87:	0f bf df             	movsx  ebx,di
  500e8a:	50                   	push   eax
  500e8b:	8d 44 24 20          	lea    eax,[esp+0x20]
  500e8f:	8b ce                	mov    ecx,esi
  500e91:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  500e95:	e8 86 2e 00 00       	call   0x503d20
  500e9a:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  500e9d:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  500ea1:	3b c6                	cmp    eax,esi
  500ea3:	0f 84 b5 00 00 00    	je     0x500f5e
  500ea9:	83 c0 10             	add    eax,0x10
  500eac:	0f 84 ac 00 00 00    	je     0x500f5e
  500eb2:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  500eb5:	39 48 2c             	cmp    DWORD PTR [eax+0x2c],ecx
  500eb8:	0f 85        	jne    0x500f5e
```

#### 原始機器碼區間 0x00500EF0–0x00500F5E（raw 0x001002F0–0x0010035E）

區間 SHA256（含所列截點，end-exclusive）`1ed7baf508289c542080655f349ef9d12fea578d5045f068e3044d85aca717e3`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  500ef0:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  500ef5:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  500ef8:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  500efb:	3b c1                	cmp    eax,ecx
  500efd:	74 18                	je     0x500f17
  500eff:	90                   	nop
  500f00:	66 39 78 14          	cmp    WORD PTR [eax+0x14],di
  500f04:	75 0a                	jne    0x500f10
  500f06:	66 8b 50 08          	mov    dx,WORD PTR [eax+0x8]
  500f0a:	66 3b 50 06          	cmp    dx,WORD PTR [eax+0x6]
  500f0e:	7c 4e                	jl     0x500f5e
  500f10:	83 c0 18             	add    eax,0x18
  500f13:	3b c1                	cmp    eax,ecx
  500f15:	75 e9                	jne    0x500f00
  500f17:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  500f1a:	8b b0 ac 5e 00 00    	mov    esi,DWORD PTR [eax+0x5eac]
  500f20:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  500f24:	51                   	push   ecx
  500f25:	8d 44 24 24          	lea    eax,[esp+0x24]
  500f29:	8b ce                	mov    ecx,esi
  500f2b:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  500f2f:	e8 ec 2d 00 00       	call   0x503d20
  500f34:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  500f38:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500f3b:	74 05                	je     0x500f42
  500f3d:	83 c0 10             	add    eax,0x10
  500f40:	eb 02                	jmp    0x500f44
  500f42:	33 c0                	xor    eax,eax
  500f44:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  500f48:	85 c0                	test   eax,eax
  500f4a:	74 12                	je     0x500f5e
  500f4c:	83 78 04 02          	cmp    DWORD PTR [eax+0x4],0x2
  500f50:	74 0c                	je     0x500f5e
  500f52:	8b 7d 10             	mov    edi,DWORD PTR [ebp+0x10]
  500f55:	8d 44 24 18          	lea    eax,[esp+0x18]
  500f59:	e8 b2 2d f4 ff       	call   0x443d10
```

#### 原始機器碼區間 0x00635CC7–0x00635CEA（raw 0x002350C7–0x002350EA）

區間 SHA256（含所列截點，end-exclusive）`d945002f66b849eab11607507c9c696720d2cd29bf88e24891a86203900918f7`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  635cc7:	33 f6                	xor    esi,esi
  635cc9:	39 b7 b8 00 00 00    	cmp    DWORD PTR [edi+0xb8],esi
  635ccf:	0f 84 1f 02 00 00    	je     0x635ef4
  635cd5:	89 75 b4             	mov    DWORD PTR [ebp-0x4c],esi
  635cd8:	89 75 b8             	mov    DWORD PTR [ebp-0x48],esi
  635cdb:	89 75 bc             	mov    DWORD PTR [ebp-0x44],esi
  635cde:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  635ce1:	89 75 c4             	mov    DWORD PTR [ebp-0x3c],esi
  635ce4:	89 75 c8             	mov    DWORD PTR [ebp-0x38],esi
  635ce7:	89 75 cc             	mov    DWORD PTR [ebp-0x34],esi
```

#### 原始機器碼區間 0x00635D18–0x00635D2E（raw 0x00235118–0x0023512E）

區間 SHA256（含所列截點，end-exclusive）`8235a4f5a1e68ba75b371b8aa872b0e76bc73a93e0e7f59de9c1ecde75ceb4c0`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  635d18:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  635d1e:	8d 45 b4             	lea    eax,[ebp-0x4c]
  635d21:	50                   	push   eax
  635d22:	51                   	push   ecx
  635d23:	68 a0 b2 fa 00       	push   0xfab2a0
  635d28:	e8 23 ac ec ff       	call   0x500950
  635d2d:	f6       	test   BYTE PTR ds:0xfab29c,0x1
```

#### 原始機器碼區間 0x00635D57–0x00635D8A（raw 0x00235157–0x0023518A）

區間 SHA256（含所列截點，end-exclusive）`abc1a959335d44165c5ef681cbfa778c50bcadd4cc89fb6bf188b70eb216a88c`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  635d57:	8b 87 84 00 00 00    	mov    eax,DWORD PTR [edi+0x84]
  635d5d:	8d 55 c4             	lea    edx,[ebp-0x3c]
  635d60:	52                   	push   edx
  635d61:	50                   	push   eax
  635d62:	68 a0 b2 fa 00       	push   0xfab2a0
  635d67:	e8 94 b0 ec ff       	call   0x500e00
  635d6c:	8b 4d b4             	mov    ecx,DWORD PTR [ebp-0x4c]
  635d6f:	3b 4d b8             	cmp    ecx,DWORD PTR [ebp-0x48]
  635d72:	8b 45 c4             	mov    eax,DWORD PTR [ebp-0x3c]
  635d75:	0f 95 c2             	setne  dl
  635d78:	3b 45 c8             	cmp    eax,DWORD PTR [ebp-0x38]
  635d7b:	88 97 b4 00 00 00    	mov    BYTE PTR [edi+0xb4],dl
  635d81:	0f 95 c1             	setne  cl
  635d84:	88 8f b5 00 00 00    	mov    BYTE PTR [edi+0xb5],cl
```

#### 原始機器碼區間 0x00635E77–0x00635EC4（raw 0x00235277–0x002352C4）

區間 SHA256（含所列截點，end-exclusive）`2ded343ea7c048667c64c98e73334bf961720d83dba4722961e9b773f0462f07`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  635e77:	33 c0                	xor    eax,eax
  635e79:	89 87 98 00 00 00    	mov    DWORD PTR [edi+0x98],eax
  635e7f:	39 75 d4             	cmp    DWORD PTR [ebp-0x2c],esi
  635e82:	74 2f                	je     0x635eb3
  635e84:	e8 14 ca 25 00       	call   0x89289d
  635e89:	8b 5d d4             	mov    ebx,DWORD PTR [ebp-0x2c]
  635e8c:	99                   	cdq
  635e8d:	2b f3                	sub    esi,ebx
  635e8f:	c1 fe 02             	sar    esi,0x2
  635e92:	f7 fe                	idiv   esi
  635e94:	8b 87 98 00 00 00    	mov    eax,DWORD PTR [edi+0x98]
  635e9a:	8b 14 93             	mov    edx,DWORD PTR [ebx+edx*4]
  635e9d:	89 97 94 00 00 00    	mov    DWORD PTR [edi+0x94],edx
  635ea3:	8b 4a 14             	mov    ecx,DWORD PTR [edx+0x14]
  635ea6:	8b 14 81             	mov    edx,DWORD PTR [ecx+eax*4]
  635ea9:	52                   	push   edx
  635eaa:	8b c7                	mov    eax,edi
  635eac:	e8 5f 00 00 00       	call   0x635f10
  635eb1:	eb 14                	jmp    0x635ec7
  635eb3:	8d b7 9c 00 00 00    	lea    esi,[edi+0x9c]
  635eb9:	89 87 94 00 00 00    	mov    DWORD PTR [edi+0x94],eax
  635ebf:	e8 ac 0e 18 00       	call   0x7b6d70
```

#### 原始機器碼區間 0x00635F10–0x00635F41（raw 0x00235310–0x00235341）

區間 SHA256（含所列截點，end-exclusive）`7847c3401a6233336ecb0c3380225ee2b1efe3abefaf528087387e3e1c60c9e8`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  635f10:	55                   	push   ebp
  635f11:	8b ec                	mov    ebp,esp
  635f13:	83 ec 18             	sub    esp,0x18
  635f16:	56                   	push   esi
  635f17:	57                   	push   edi
  635f18:	8d b0 9c 00 00 00    	lea    esi,[eax+0x9c]
  635f1e:	e8 4d 0e 18 00       	call   0x7b6d70
  635f23:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  635f26:	85 ff                	test   edi,edi
  635f28:	0f 84 0d 01 00 00    	je     0x63603b
  635f2e:	8b 15 d0 1b fe 00    	mov    edx,DWORD PTR ds:0xfe1bd0
  635f34:	53                   	push   ebx
  635f35:	8b 4a 1c             	mov    ecx,DWORD PTR [edx+0x1c]
  635f38:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  635f3b:	80 78 71 00          	cmp    BYTE PTR [eax+0x71],0x0
  635f3f:	75 14                	jne    0x635f55
```

#### 原始機器碼區間 0x00635F6F–0x00635F8E（raw 0x0023536F–0x0023538E）

區間 SHA256（含所列截點，end-exclusive）`e81e8ab41e40c2159866cc21dc854d41aba608ba12e2d43409dd168fa88a6a68`。以下是同一原件 bytes 經 x86 objdump 解碼，**只可由明確入口／已證分支進入**，切口與跳表不可當作獨立函式。

```asm
  635f6f:	8b 00                	mov    eax,DWORD PTR [eax]
  635f71:	3b 42 1c             	cmp    eax,DWORD PTR [edx+0x1c]
  635f74:	0f 84 c0 00 00 00    	je     0x63603a
  635f7a:	8d 48 10             	lea    ecx,[eax+0x10]
  635f7d:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  635f80:	85 c9                	test   ecx,ecx
  635f82:	0f 84 b2 00 00 00    	je     0x63603a
  635f88:	8b 41 20             	mov    eax,DWORD PTR [ecx+0x20]
  635f8b:	8b 5e 0c             	mov    ebx,DWORD PTR [esi+0xc]
```

## L. 本段結論與 GitHub 可提交狀態

- 研究三輪實際執行：`T16-105`（11-way parser / table 邊界）；`T16-105-2`（0x18 writer→filter）；`T16-105-3`（candidate flags+容器與未知 dispatcher negative controls）。本地交付一份全文 Markdown，包含各輪入口／來源 bytes／反例／停止條件；沒有捏造第4輪。
- **重要且可證實的局部新發現**：runtime record filter 的確切 signed gate 與下游兩個不同 byte flags 的本機串接。不是 Quest S→C wire protocol 或 NPC UI 完整閉環。
- GitHub：同步 PR #16 已合併，Behind=0（檢查時 main SHA 如 A 節）。**本段新的 Markdown 未 Commit／Push，沒有遠端 Git blob SHA，也沒有 RR 狀態更動**。提交需使用者當次明確指示，且僅 `t16/roy/chatgpt-web`。
- 本地可保留的下一研究入口：receiver table 真正 dispatcher、`0x635CA0` caller/vtable/source 和 `+B4/+B5` readers、Quest16→15 原生 wire packet，並另安排 T01 勘誤批次。