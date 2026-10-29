# T01 第三批 R2：KR 同 key 重連時舊 Conn／Pool／IOCP 指標分離

2026-10-30 (Asia/Taipei)。**T01 限定原生審核，不是 T02 作者 E51/E52、不等於 RR ACCEPTED、整份 FULL-PASS 或 Server 規格完成。**

## 研究基準與來源
KR `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`.text` VA `0x401000`、raw `0x400`，指令窗口 `raw=VA-0x400C00`。於本地原件唯讀跑 `T01-20261030-batch3-verify.py`，**47 個定點指令 bytes + 15 個 E8/Jcc 直接目標全數通過**。這是 R2 定點交叉驗證，**非完整 rooted CFG**。

開工 main `eadabf33f31da542db32ddf1d10cabea5a020ea4`；RR-0005 已由 T02 / `extra/roy1` 正式認領為 `ACTIVE / CLAIMED`，不能再引用前批 `QUEUED` 舊快照。此次沒有修改 RR 或原作者原稿。主要來源 E48 blob `39285bbf723876d58ebdd9f74e197bd0499f3d03`、E49 `8f4b0ca731fdc8d0d8c9f264e4c85a956bd5e7d2`、E50 `f4bd62ce69cf96cc35b566bf62721a586f4f51c7`；參照 T16-97 `417d81dc3b8301530a7e29ba75bbf282df6953e9`、T03-6 `28dc1c2e3e962c85e0187d75d219b9da5ec253aa` 及既有 `CLM-NET-0013` 反證。

## A. Pool 可重用 Conn 與新 Conn 建構
```asm
806b14 push 1
806b16 call 805950
806b1b mov ebx,eax
806b1d test ebx,ebx
806b1f je 806cd7
806b29 mov dword [ebx+A0B4],2
806b33 mov [ebx+A080],eax
806b8a mov [ebx],eax     ; socket handle
```
`0x805950` 在 Pool mutex 下若 `Pool+0x20 != 0`，走 `0x80598B→0x542210` 取可重用 Conn，`0x8059E9→0x805F50` reset，`0x8059F3` 使 `Conn+A0AC=1`，`0x8059F9` 加 `Pool+0x44`。若 pool 沒有 available 項、輸入允許，`0x805A03 push 0xA0D8` 配置新物件，`0x805A1B→0x805CA0` 初始化，`0x805A54` 同樣設 A0AC=1，`0x805A62` 釋放 pool mutex。**Conn* 地址可再利用，不能用相同 pointer 值代替 connection generation。**

## B. 重複 key 的 Manager tree 替換，不等同舊 Conn 已 close/free
```asm
806c87 call [BD2278]     ; CreateIoCompletionPort
806c94 lea esi,[edi+18]  ; manager tree
806c9e call 8438C0       ; key lookup
806ca7 cmp eax,[edi+1C]  ; end/sentinel
806caa je 806cb8
806cb3 call 7B6890       ; found: tree erase
806cb8 mov edx,[ebp+10]
806cc3 mov [esp+18],ebx  ; new Conn*
806cc7 call 57EF20       ; new map node allocation
806cd2 call 57E850       ; new map node insertion
806cdd mov eax,ebx       ; new Conn*
```
`0x57EF26 push 0x18` 配置 tree node，再由 `0x57EF52..0x57EF59` 複製 key/Conn pointer；`0x7B6890` 的 `0x7B6899` 是 node+0x15 sentinel gate、`0x7B68B4→0x49E6A0` iterator successor，後續 red-black 連結再平衡。**本函式區段沒有獨立呼叫 Pool+48 enqueue `805AF0` 或 socket close `806FC0`**；但 `7B6890` 未完成全部 value destructor 函式／CFG 審查，因此只能證明「tree erase 與 pool close 是不同層次」，不可宣稱 erase 永不觸發深層 Conn release。

## C. IOCP completion key 與新 manager key-map 不是同一件事
```asm
806c7b call 806620
806c82 push 0
806c84 push ebx          ; new Conn* as completion key
806c85 push edx          ; hIOCP
806c86 push esi          ; socket
806c87 call [BD2278]    ; CreateIoCompletionPort
806d7b lea edx,[ebp-1C] ; GQCS out lpCompletionKey
806d7f lea eax,[ebp-24] ; GQCS out lpOverlapped
806d84 call [BD2274]    ; GetQueuedCompletionStatus
806d92 mov eax,[ebp-1C] ; complete event Conn*
806de4 lea edi,[eax+A030] ; RX OVERLAPPED identity
806e7d lea edi,[eax+A050] ; TX OVERLAPPED identity
```
在同 key map 替換之後，舊 socket 的完成事件若仍攜帶當時 `Conn*` completion key，GQCS consumer 並**不需要重新查 Manager[key]** 才取得該指標。因此 map 替換本身不能保證舊 Conn 沒有 outstanding IOCP callback。這是**靜態可達條件**，不是聲稱舊 callback 必然發生、也不是跨執行緒／Cancel 安全性證明。另外 `806C87` 回值在隨後路徑未見顯式 `test eax` 成功 gate，不可把建立新 map node 推論成 IOCP association 必然成功。

## D. 舊結論的跨 Task 分層處置
- E48 的 `49B070`「manager map detach」已由 E49/E50 反證：它是 `FBA858` singleton getter，真正 map tree erase 在 `806CB3`。保留 E48 歷史 blob，不覆寫它。
- Pool+48 producer `805AF0`（Connect failure）與 `8066A0`（manager teardown）在已見路徑設定 `Conn+14=0`；Pool+28 用此值 unlink tracking node，Pool+48 再以 `Conn+A0B8==0` gating 回收。**不能由 key-map erase 自動推論走過其中任一 pool producer。**
- `Conn+A0B8` 在已見 WSASend synchronous success/pending 路徑 +1，匹配 GQCS send completion success/failure −1；RX 的 `A030` 和 `A0BC` 另有控制。不可稱它涵蓋所有 RX IO。T03-6 對 OVERLAPPED/WSABUF offset 錯誤已由 T01 `CLM-NET-0013` 裁決，不新增同題退回。
- T16-107 的 local `0x36` queue、frame、socket，與 Quest14/16/15 S2C 業務 parser/Scenario14 的 ID 是不同域。queue≠實際 wire send≠Server 處理≠任務完成 ACK。

## E. 研究結果、GAP 與下一步
T02 **Client 待逆向**：`7B6890` 所有 value destructor、`Conn+14` 全部 writers、舊 Conn 於 manager replace/close/Pool+48/IOCP 中的 ownership、重用 ABA、取消/錯誤 balance、同一次登入真實首筆 wire 與 response。T16 **Client 待逆向**：Quest 專用 S2C 完成消息、NPC/UI writer。S00 **Server 待設計**：可用有限 client precondition 建 GAP/TEST 草案，但不能臆造 Client wire 格式或宣稱 SPEC STABLE。未做遊玩測試。

本批第一輪取得 Pool reuse-vs-new → key tree replace → IOCP completion key 的**重大有界增量**；按共用三輪門檻第2/3輪未啟動。沒有新增 FULL-PASS、SPEC_CONSUMABLE、RR accepted，也沒有整篇原稿全文逐句重新驗證。
