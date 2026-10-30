# T01 第六批 R2 — RR-0005／E56：key1 六種上游、雙 Connect、WSARecv/佇列返回值

> 2026-10-30（Asia/Taipei）；**T01 有界獨立查核**，非原作者 E57、非 E56 全稿 FULL-PASS、非 S00 對 RR-0005 的 ACCEPTED。

## 1. 版本、來源、審核終點

- KR `Tartaros.bin`：**12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`**，原件唯讀。PE32 .text VA 0x401000/raw 0x400，程式 raw=VA−0x400C00；.rdata VA 0xBD2000/raw 0x7D0600，raw=VA−0x401A00。
- 已提交的 E56 原稿：`kr-extra-roy/20261030-091559-chatgpt-web-roy-E56-RR0005-bounded-static-completion-transport-owner-retry-reply.md`，精確 Git blob `843889349bb58209c02221e720800f0e9e3ff9d8`、T01 `SRC-0451`。本次重讀 `AGENTS.md`、T01 工作流程、RR 登記及 T01 收件箱後，以主線 `d4639e45b1fbbaecb908f78822efa23141678a72` 的 RR-0005 **SUBMITTED/T02** 為審查基準；不修改 RR／owner／原作者分支。
- 從原件 .text 用 `objdump -w -D -b binary -m i386 -M intel --adjust-vma=0x401000` 按已知入口重解碼；**155 處指定完整指令 machine bytes、37 條直接 E8/E9/Jcc 位移、5 個 .rdata vtable DWORD** 逐條對照，均 PASS。另對全 .text 8,192,496 bytes 掃描裸 E8 rel32 到兩個 Connect helper，命中 **8 個候選**（key1 六、key0/key2 兩），其 6 個 key1 位置也在已知函式入口反組譯中證實。此掃描無法排除間接 caller；指定指令驗證不是所有相關函式完整 rooted CFG。完整機器碼定點清單 [JSON](native-verification-manifest.json) 及 [獨立重跑腳本](verify-native.py)。

## 2. E56 key1 六個 direct caller：不同目的的 payload／callback

| key1 call site | 第三引數 | helper 成功後所在函式可見行為 | 送出候選、不是 wire |
|---|---|---|---|
| `0x6D6377` | `push 0`（6D636E） | `test eax`，`jne 6D63E9`，動態 callback | 函式內無直接 queue |
| `0x6D6424` | `push 0`（6D641B） | `jne 6D6498`，動態 callback | 函式內無直接 queue |
| `0x6D6508` | **`push 1`**（6D64FF） | `6D651B` builder → manager virtual +0x10 | `6D6563 push 0x38`＝56B，key1 |
| `0x6D65C8` | `push 0`（6D65BF） | `6D664D` builder → virtual +0x10 | `6D6683 push 0x68`＝104B，key1 |
| `0x6D670C` | `push 0`（6D6709） | 多欄位 builder → virtual +0x10 | `6D687F push 0x2CE`＝718B，key1 |
| `0x6D696C` | `push 0`（6D6969） | 另一多欄位 builder → virtual +0x10 | `6D6ADF push 0x2CE`＝718B，key1 |

六個已證 direct E8 bytes 分別是 `e894f2dbff`、`e8e7f1dbff`、`e803f1dbff`、`e843f0dbff`、`e8ffeedbff`、`e89fecdbff`（順序同上），全部相對目標為 `0x495610`。第三引數非零進 `4956B8..49573B` 的 key0/key2 shutdown-by-key，並可能對舊 BF60/key1 shutdown；0 且 BF60 存在可在 `495741 jne 4957A0` 直接回1而**不新建 Conn**。新建時 `495751 push 2; 495753 push 1; 495755 push 0x20DF`＝key1/lane2/8415。**六個 caller 不是一個固定封包模板；從這裡不能決定任意 session 的第一個 wire。**

## 3. key0/key2 選服 Connect：真正判斷與成功條件

`0x4957C0` 的兩條已知直接 UI 上游是 `0x66C1A7`、`0x66C247`；來源選服 record 的 IPv4 字串、secondary dispatcher 仍依 E44/E45/T03 限定版本，本次不把 E56 的整段 UI handler 語意升 FULL-PASS。

```asm
4957e0 push 2; 4957e2 push 0; 4957e4 push 0x20e0; 4957ea call edx ; key0/lane2
4957f2 push 2; 4957f4 push 2; 4957fd push 0x20de; 495803 call edx ; key2/lane2
495807 test edi,edi; 495809 je 4959b0  ; key0 absent
49580f test ebx,ebx; 495811 je 49597e  ; key2 absent
...
495935 push 0x39; 49593b push 0; 49593d call edx  ; key0 local 57B application queue
49594a push edi; 49594b call edx               ; key0 recv-post
495958 push ebx; 495959 call edx               ; key2 recv-post
49595b mov [esi+0xbf64],edi                     ; key0 alias
495962 mov [esi+0xbf68],ebx                     ; key2 alias
495968 mov eax,1
```

**新增高風險限定結果**：不論 key0 helper 是否回傳零，`0x495803` 仍嘗試 key2 Connect，然後才逐一判斷。兩 Conn 指標均非零時，函式會嘗試局部入列及 recv-post，但 **沒有檢查三次 virtual call 的 EAX 回傳才寫 BF64/BF68 與回1**。key0 非零/key2 零時 `0x49597E..49598D` 對 key0 shutdown-by-key；反向則 `0x4959C1..4959D0` 對 key2 shutdown-by-key，函式回0。這是函式內條件，不是全域 retry、closesocket 或 Pool release 的證明。

第一個 key0 本地業務候選長 `0x39=57B`，builder 起首 WORD `0x0001`；其餘欄位取自全域/玩家資料 `0x404BA0` 及文字/bytes copy，不能把裸 57 bytes 當已驗證完整 TCP wire；key2 **在本函式內**沒有直接 send，不代表全遊戲 key2 永不送。

## 4. 反向核對 virtual methods：發送成功、投遞成功與 helper return=1 不同

從原生 .rdata `0xC51748` 的 manager vtable 精確確認：+0x10→`0x8069A0`（send-by-key queue），+0x14→`0x806A00`（WSARecv post），+0x18→`0x806AD0`（Connect），+0x24→`0x806FC0`（close-by-Conn）。不得將不同 object base 的相同 offset 合併。

### 4.1 `0x8069A0` 的三種返回

`0x8069B7 call 0x8438C0` 查 Manager key tree；缺 key / Conn value NULL 時 `0x8069CC xor eax,eax` → 0。若 Conn 存在但 `[ebp+0x10]` 長度為零，`0x8069DB mov eax,1` 即回1，**不須送資料**。只有正長度在 `0x8069EB call 0x8060D0` 轉為本地 message queue。不是呼叫該 virtual 就等於 queue 成功。

`0x8060D0` 有具體容量限制：`0x8060FA cmp [Conn+A0A4],0x12C; 0x806104 jle 0x80611C`，超過300時 `0x806106 xor eax,eax; ret 8`。因此即使已取得 Conn 且上游 key0 長57B，queue 仍有返回0的**條件式靜態分支**；`0x4957C0` 不檢查這個返回。另 `0x80615B cmp packetLength,0x1000` 超過4096會跳過該段 buffer copy／length store，之後仍進 `0x806177→0x806060`；本輪不把此點斷言成 runtime memory corruption，交 T02 擴查。

### 4.2 `0x806A00` 的 WSARecv 結果

`0x806A0A lea eax,[Conn+A030]` 準備 OVERLAPPED，`0x806A4C call [0xBD25BC]` 的 IAT 已由 KR PE import 解出 `WSARecv`。若回傳不是 -1，走 `0x806AAB`；若 -1，`0x806A57` 讀最後錯誤，`0x806A5F cmp ebx,0x3E5`（WSA_IO_PENDING/997），pending 也走 `0x806AAB`。非 pending 的硬性錯誤：`0x806A69 mov eax,[vtable+0x24]`，`0x806A71 call eax` close-by-Conn，`0x806A73 mov [Conn+A0A8],1`，`0x806AA2 xor eax,eax` 回0；正常/待完成在 `0x806AAB call 0x8065B0` 後由 `0x806AC3 mov eax,1` 回1。這不是已收到任何 Server payload。

**新的上游/下游組合：** `0x495610` 的 `0x495789..0x495794` post recv 方法返回結果未被檢查便寫 `BF60`；`0x4957C0` 也不檢查兩次 post recv 返回便寫 `BF64/BF68` 並回1。因此在 `0x806A00` 硬失敗的**條件式路徑**，Client 上層可能回1並保留走過 close 分支的 Conn pointer alias。此為**靜態可達風險**，不是實際重現 UAF、socket leak、IOCP race 或 Server 失敗。從單純的 `return 1` 推成三路皆穩定傳輸，屬不被原生證據支持的擴張。

## 5. 對 E56／舊 CLM 的裁決矩陣

| 主張 | T01 本輪證據範圍／等級 | 禁止擴張 |
|---|---|---|
| key1 六條上游及不同局部封包長度 | six direct E8 + 4 個長度/queue anchors，全數原生查到；**PARTIAL** | 間接 callers、builder 全 payload、第一個真實 wire |
| key0/key2 雙 helper Connect、先入列後兩次 recv | `0x4957C0` 正常與失敗分支 R2 驗證；**PARTIAL** | 此函式 return1 不證下游 queue/WSARecv 成功 |
| 上層可能忽略 recv-post 硬錯誤 | `0x806A00` 的 0/1、close-by-Conn 和三個 BF slot writer；**PARTIAL** | 不宣稱實際 UAF、跨 thread 競態或端到端網路結果 |
| same-key Conn 與 Pool/IOCP | 復用既存 `CLM-NET-0015..0017`，本輪不重新主張全域 ownership | oldConn 必然 close、永遠 leak 或所有異常都回收 |
| 0x0013/0x007A→選服 UI→首個 S2C | E56 既有 source-scoped，未完整重審全部 handler/合法長度 | 真實 first S2C opcode、固定 response 或原版 Server 端點 |

沒有確立需要源作者改稿的正面反證，因此**不創建 T02 NEEDS_FIX**；若後續證實 E56 其他肯定主張錯誤，依 T01 固定 README 退回流程處理。新增 CLM 按來源精確 blob 保留 R2 PARTIAL，尚未滿足 R3 full pass 或 `shared/verified-knowledge` 准入。

## 6. 待辦及 S00 邊界

- **Client 待逆向／T02**：key1 四組 builder 完整 byte offsets、callback 消費者；`0x8060D0` 容量滿載／異常分支的後續；`0x806A00` recv hard-fail 與 BF alias 重用／關閉／取消與 IOCP；`0x4957C0` 呼叫者 retry；0x13/0x7A secondary parser 最小合法長度與完整 first frame。
- **Server 待開發／S00**：可設計 Conn 建立≠I/O readiness、slot failure/retry、frame 整體格式的 DRAFT GAP／TEST；不能把原始 Client 的本地 pool 併入 Server 實作必要條件，亦不得臆造官方 first-response。
- **跨功能待整合**：T03 選服 UI record、T02 transport/framing、T16 業務 S2C/quest 串接。
- **待遊玩驗證**：同 session Connect/WSASend/WSARecv 真實成功順序、失敗回復、Server 實際收包與回覆時序；不能只說「需 runtime」而放棄仍能從 BIN 追的 Client builder/CFG。

**本批 R2 審核階段性完成但 E56 全文審核尚未完成。** 未更動 RR-0005 的 SUBMITTED、來源 Task 分支、S00 SPEC/TEST 或已准入 FULL-PASS 條目。