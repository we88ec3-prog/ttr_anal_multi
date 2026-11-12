# T03-6 — KR command 42 transport staging → WSASend/WSARecv 與 overlapped completion 邊界（T01 勘誤完整修訂版）

- 研究者：chatgpt-web roy；原稿 2026-10-28 22:39:19 Asia/Taipei；**本勘誤版 2026-10-31 17:22:47 Asia/Taipei**，以新檔保存，未覆蓋歷史原稿。
- 研究標的：KR `Tartaros.bin`，大小 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀分析。目標未執行、hook 或 patch。
- PE image base 0x00400000；`.text` RVA 0x1000 / raw 0x400 → `.text` VA 0x00401000；本文 `.text` VA 到 raw = VA - 0x00400C00。`.rdata` VA 0x00BD2000 raw 0x007D0600；IAT 查原始 PE import directory。
- GitHub 分支 `t03/roy/chatgpt-web`，本段起始 main `2ba0a2cc72584622eb6bb944fc4f1fb84e63c355` 已合入分支；沿 T03-5 的 queue drain / 4-byte 與 6-byte staging frame 追進實際 Windows socket API。T02 負責共用 socket/framing，本文只登記 T03 的依賴鏈和新的原生 interface 事實。


## T01 勘誤補充 — 原始送收布局、stack 參數及否證界線（2026-10-31）

> 本版取原始 T03-6 全文逐處更正，**原檔保持不變**；舊版原稿 blob `28dc1c2e3e962c85e0187d75d219b9da5ec253aa`。本版原生證據經本次對所提供 `Tartaros.bin` 唯讀 SHA256、PE32 section 與精確指令比對（23 slices PASS）。復驗工具：[`kr-temp-roy/20261031-172247-chatgpt-web-roy-T03-A-verify-wsasend.py`](./20261031-172247-chatgpt-web-roy-T03-A-verify-wsasend.py)。T01 尚未對本修正版作 R3／全文 FULL-PASS；請定向複驗。

| 位置 / raw offset | 原始指令或 bytes | 證實的 pointer / API 意義 |
|---|---|---|
| `8068DE / 405CDE` | `8D 86 50 A0 00 00` / `lea eax,[esi+A050]` | send OVERLAPPED* = connection+A050 |
| `8068F3 / 405CF3` | `50` / `push eax` | WSASend 第六參數 `lpOverlapped` |
| `8068F7 / 405CF7` | `8D 48 14` / `lea ecx,[eax+14]` | WSABUF* = connection+A064；非 OVERLAPPED |
| `8068FC/806905` | `mov [eax+18],edi` / `mov [ecx],edx` | WSABUF.buf 指向傳入 buffer；WSABUF.len 為傳入長度 |
| `806909 / 405D09` | `51` / `push ecx` | WSASend 第二參數 `lpBuffers` |
| `80690A/806912` | `push edx` / `call [BD25B8]` | socket 來自 `[esi]`；IAT = WS2_32!WSASend |
| `806961/806968` | `add esi,A0B8; push esi; call [BD2284]` | pending 分支的 `InterlockedIncrement(connection+A0B8)` |
| `80697A/806981` | `add esi,A0B8; push esi; call [BD2284]` | 非 -1 分支同一 atomic counter |
| `806E7D/806E83` | `lea edi,[eax+A050]; cmp edx,edi` | completion 識別 send OVERLAPPED pointer |
| `806A0A/806A2E` | `lea eax,[esi+A030]; lea ecx,[eax+14]` | receive OVERLAPPED +A030；WSABUF +A044 |
| `806A3B/806A4C` | `mov [ecx],1000h; call [BD25BC]` | receive WSABUF.len 與 WSARecv IAT |
| `806DE4` | `lea edi,[eax+A030]` | completion 識別 receive OVERLAPPED |

**依實際 x86 stdcall 由右至左 push 重建 send 呼叫：**

```c
// connection = ESI, userBuffer = EDI, length = EDX
WSAOVERLAPPED* sendOv = (WSAOVERLAPPED*)(connection + 0xA050);
WSABUF* sendBuf = (WSABUF*)(connection + 0xA064);
sendBuf->len = length; sendBuf->buf = userBuffer;
WSASend(socket /* [ESI] */, sendBuf, 1,
        &stackSentBytes /* [EBP+0xC] */, 0, sendOv, NULL);
// returned -1 plus WSA_IO_PENDING -> helper result 2; normal -> 1;
// other WSA errors -> 0; input gate fail -> -1.
// Both pending and normal branches increment *(LONG*)(connection+A0B8).
```

其中 `[EBP+0xC]` 作為本函式局部暫存 bytes-sent，`[EBP+0x14]` 所指的外部 output 在 call 後被更新。這些為**本函式內可證的 WinSock 引數**，並非與 C2S42、Server 接收結果或選角成功相連的實際 wire trace。

**原始 T03-6 第 78、102、124、145、149、198 行已明確重訂位址／語意；**原始 199 行不搬移、不刪除。其餘 source 的 transport 與 session 關係繼續保留部分確認，不做整篇 FULL-PASS 宣稱。T01 退回 ID `T01-RETURN-T03-006-LAYOUT-001` 的下一步是來源版本／相應 CFG、completion 及跨 frame/connection 相對基準由 T01 核對，正式 `RESOLVED` 只由 T01 裁定。

---

## 0. 與既有研究去重／正式段號

T03-3：UI 選角事件和 command42 4-byte builder。T03-4：virtual send → queue copy。T03-5：`0x8061A0` queue dequeue → `0x807830` / `0x807A70` staging frame builder。以上不視為本次新發現。本段正式編號為 **T03-6**。既有 T03-1/2 於歷史分支以 `T03-LOGIN-01/02` 命名，不改動舊檔名。

## 1. 第一輪：原始 PE import、WSASend/WSARecv 與直接呼叫指令

`objdump -p` 原生 WS2_32.dll import 表：

```text
IAT RVA 0x007D25B8  WSASend  → VA 0x00BD25B8
IAT RVA 0x007D25BC  WSARecv  → VA 0x00BD25BC
IAT RVA 0x007D25CC  imported winsock error getter (name/ordinal須另外從完整 import 上下文確認)
```

原始 `.text` 的確切呼叫（非只依反編譯）：

```asm
806912: ff 15 b8 25 bd 00    call dword ptr [0x00BD25B8]   ; WSASend
806a4c: ff 15 bc 25 bd 00    call dword ptr [0x00BD25BC]   ; WSARecv
```

直接位元組、VA/raw：`0x806912` → raw `0x405D12`；`0x806A4C` → raw `0x405E4C`。上述 raw mapping 為原始 section 檔頭算得；無任何動態程式執行。

### 1.1 `0x8068B0`：WSASend 包裝／非同步返回分支

原始 instruction 摘錄：

```asm
8068b0: 55                    push ebp
8068b1: 8b ec                 mov ebp,esp
8068b6: 8b 7d 0c              mov edi,[ebp+0xc]
8068bb: 85 ff                 test edi,edi
8068bd: 0f 84 d0 00 00 00     je 0x806993
8068c3: 8b 55 10              mov edx,[ebp+0x10]
8068c6: 85 d2                 test edx,edx
8068c8: 0f 84 c5 00 00 00     je 0x806993
8068ce: 8b 75 08              mov esi,[ebp+0x8]
8068d1: 83 be a8 a0 00 00 00  cmp dword ptr [esi+0xa0a8],0
8068d8: 0f 85 b5 00 00 00     jne 0x806993
8068de: 8d 86 50 a0 00 00     lea eax,[esi+0xa050]
8068fc: 89 78 18              mov [eax+0x18],edi
806903: 6a 01                 push 1
806905: 89 11                 mov [ecx],edx
806907: 8b 16                 mov edx,[esi]
806909: 51                    push ecx
80690a: 52                    push edx
806912: ff 15 b8 25 bd 00     call dword ptr [0xbd25b8]
806920: 83 f8 ff              cmp eax,-1
806923: 75 55                 jne 0x80697a
806925: ff 15 cc 25 bd 00     call dword ptr [0xbd25cc]
80692d: 81 ff e5 03 00 00     cmp edi,0x3e5
806933: 74 2c                 je 0x806961
806959: 5e                    pop esi
80695a: 33 c0                 xor eax,eax
80695e: c2 10 00              ret 0x10
806961: 81 c6 b8 a0 00 00     add esi,0xa0b8
806967: 56                    push esi
806968: ff 15 84 22 bd 00     call dword ptr [0xbd2284]
806970: b8 02 00 00 00        mov eax,2
806977: c2 10 00              ret 0x10
80697a: 81 c6 b8 a0 00 00     add esi,0xa0b8
806980: 56                    push esi
806981: ff 15 84 22 bd 00     call dword ptr [0xbd2284]
806989: b8 01 00 00 00        mov eax,1
806990: c2 10 00              ret 0x10
806993: 5f                    pop edi
806995: 83 c8 ff              or eax,-1
80699a: c2 10 00              ret 0x10
```

**已證（更正）**：對 buffer 與 length、`connection+0xA0A8` 的 gate；使用 connection socket handle `[ESI]`。`0x8068DE` 的 `[ESI+0xA050]` 是 **WSAOVERLAPPED 起點**（以 EAX 傳入 `lpOverlapped`）；`0x8068F7` 的 `ECX=EAX+0x14=connection+0xA064` 才是 **WSABUF 起點**（`+0x14` 寫入 len、`+0x18` 寫入 buf pointer）；`connection+0xA0B8` 只在 `InterlockedIncrement` 路徑作計數器位址，**不是** WSASend 的 overlapped/context 參數。若 API 回 `-1` 且 error `0x3E5`（decimal 997，WSA_IO_PENDING），返回 2；其他 API 錯誤返回 0；直接非 -1 返回 1；入口 gate fail 返回 -1。此為原生靜態 call-argument 結論，不代表對端業務 ACK 或指定選角 packet 已實際送達。

**界線**：由於此函式不是直接調用 `0x4A3B80` 的 caller，它是共用 T02 transport；是否用於某個特定選角 session，需要從 staging buffer 的實際 consumer 與通道物件來源閉合，不能把 `WSASend` 存在等於 command42 必然已成功發送。

### 1.2 `0x806A00`：WSARecv 包裝

```asm
806a00: 55                    push ebp
806a06: 8b 75 08              mov esi,[ebp+8]
806a0a: 8d 86 30 a0 00 00     lea eax,[esi+0xa030]
806a22: 8b 8e 18 50 00 00     mov ecx,[esi+0x5018]
806a2b: 89 48 18              mov [eax+0x18],ecx
806a3b: c7 01 00 10 00 00     mov dword ptr [ecx],0x1000
806a41: 8b 16                 mov edx,[esi]
806a4c: ff 15 bc 25 bd 00     call dword ptr [0xbd25bc]  ; WSARecv
806a52: 83 f8 ff              cmp eax,-1
806a57: ff 15 cc 25 bd 00     call dword ptr [0xbd25cc]
806a5f: 81 fb e5 03 00 00     cmp ebx,0x3e5
806a67: 8b 17                 mov edx,[edi]
806a69: 8b 42 24              mov eax,[edx+0x24]
806a71: ff d0                 call eax
806a73: c7 86 a8 a0 00 00 01 mov dword ptr [esi+0xa0a8],1
```

**已證（接收布局補充）**：`0x806A0A` 形成 **receive OVERLAPPED=connection+0xA030**，`0x806A2E` 形成 **receive WSABUF=connection+0xA044**，`0x806A3B` 填入 len `0x1000`，buffer pointer 來自 connection+0x5018，`0x806A4C` 呼叫 WSARecv。接收 context 與傳送 context 是不同位址；錯誤時存在虛擬回調與狀態旗標變化。本段不含選角業務 parser，不可把 receive completion 等同 S2C 選角成功。

## 2. 送出完成事件到緩衝消耗：`0x806E7D`→`0x8077B0`

原始 `.text`：

```asm
806e7d: 8d b8 50 a0 00 00     lea edi,[eax+0xa050]
806e83: 3b d7                 cmp edx,edi
806e85: 0f 85 a5 fe ff ff     jne 0x806d30
806e8b: 01 4b 28              add [ebx+0x28],ecx
806e8e: ff 43 38              inc [ebx+0x38]
806e91: 39 b0 ac a0 00 00     cmp [eax+0xa0ac],esi
806e97: 74 12                 je 0x806eab
806e99: 8d b0 1c 50 00 00     lea esi,[eax+0x501c]
806e9f: 8b f9                 mov edi,ecx
806ea1: e8 0a 09 00 00        call 0x8077b0
806eab: 39 b0 28 a0 00 00     cmp [eax+0xa028],esi
806eb1: 0f 97 c1              seta cl
806eb4: 88 88 24 a0 00 00     mov [eax+0xa024],cl
```

`0x806E83` 比較完成事件的 **OVERLAPPED 指標**是否等於 **connection+0xA050**（`0x806E7D` 形成此位址）；此處不是 WSABUF 指標。匹配且通過後續條件時，以完成位元組數 `ECX` 更新 transport 計數，可能呼叫 `0x8077B0`。WSABUF 位於同一 connection 的 **+0xA064**。

```asm
8077b0: 53                    push ebx
8077b1: 8b 1e                 mov ebx,[esi]
8077b3: 53                    push ebx
8077b4: ff 15 4c 22 bd 00     call dword ptr [0xbd224c]
8077ba: 85 ff                 test edi,edi
8077bc: 78 5b                 js 0x807819
8077be: 8b 86 0c 50 00 00     mov eax,[esi+0x500c]
8077c4: 3b c7                 cmp eax,edi
8077c6: 72 51                 jb 0x807819
8077c8: 2b c7                 sub eax,edi
8077ca: 89 86 0c 50 00 00     mov [esi+0x500c],eax
8077d0: 74 3e                 je 0x807810
8077f7: 8d 44 37 04           lea eax,[edi+esi+4]
8077fd: e8 ce 63 09 00        call 0x89dbd0
807810: 8d 4e 04              lea ecx,[esi+4]
807813: 89 8e 04 50 00 00     mov [esi+0x5004],ecx
```

**新增有界鏈（更正限定）**：完成事件比對的是 **send OVERLAPPED=connection+0xA050**，而不是 `WSABUF` 或 `+0xA0B8` atomic counter。在匹配的完成分支且其他 gate 成立時，transport staging buffer（connection+0x501C 子物件）依完成長度可部分消耗或清空；`0x8077B0` 不等於 Server 收包或選角批准。counter+0xA0B8 的 `InterlockedIncrement` 是送出返回時另一個計數路徑，不能混用 pointer identity。

## 3. 第三個入口：接收 completion 與接收後續待驗

`0x806DE4` 比對 **receive OVERLAPPED=connection+0xA030**，而不是 receive WSABUF `connection+0xA044`：

```asm
806de4: 8d b8 30 a0 00 00     lea edi,[eax+0xa030]
806dea: 3b d7                 cmp edx,edi
806dec: 0f 85 8b 00 00 00     jne 0x806e7d
806df2: 01 4b 2c              add [ebx+0x2c],ecx
806df5: ff 43 3c              inc [ebx+0x3c]
806df8: 39 b0 ac a0 00 00     cmp [eax+0xa0ac],esi
806dfe: 0f 84 2c ff ff ff     je 0x806d30
806e04: 8d 50 18              lea edx,[eax+0x18]
806e08: e8 33 0d 00 00        call 0x807b40
806e0d: 85 c0                 test eax,eax
806e12: 74 0f                 je 0x806e23
806e14: 8b 13                 mov edx,[ebx]
806e16: 8b 52 14              mov edx,[edx+0x14]
806e1c: ff d2                 call edx
```

這構成可見的 receive completion → `0x807B40` 的資料處理入口，**但此輪未將 `0x807B40` → 具體 T03 packet router/character confirmation 邏輯閉合**。下一段首先反向定位 `0x807B40` 的解框與真正 dispatch 交接，查 T03 / T05 已有契約，再決定能否給 command42 配對原生 S→C handler。不可把測試 fixture 的 42→43/69 命名成原版協定。

## 4. 玩家情境矩陣與分工

| 玩家情境 | Client gate | C→S | 傳輸 API | S→C／回覆 | UI／世界效果 | 狀態 |
|---|---|---|---|---|---|---|
| 選角確認通過本地檢查 | 角色 `+0x5C` 可用、全域 sender gate、通道可用 | T03-3 `42 00 XX YY` → T03-4 queue → T03-5 4/6 prefix staging | 本段證實通用 WSASend 包裝和 completion/consume；實際該筆 queue→該 socket 完全同一事件需接合 | 未確認 | 不可推斷選角成功 | 部分確認 |
| queue 無項或 frame 不足 | 佇列 / buffer 條件失敗 | 無可證明的該筆 WinSock 成功 | transport skip/fail | 未確認 | 未確認 | 部分確認 |
| WSASend 直接完成 | 非 -1 API return | 已經呼叫 WSASend，傳送結果仍需含 completion 語意 | return1 | 不代表 Server business ack | 未確認 | 原生已確認（transport） |
| WSASend 非同步 pending | `-1` + `0x3E5` | pending | return2 | 待 completion | 未確認 | 原生已確認（transport） |
| 收到來源不明的 socket bytes | Recv 環境可用 | 不適用 | WSARecv → completion → `0x807B40` | 尚未查明真正選角 result handler | 未確認 | 部分確認 |

## 5. 三輪深入判定

- **第1輪 T03-6：已執行。** 從原始 PE import/IAT 定位 2 個 WS2_32 原生 API call，分析 WSASend 封包緩衝/異步狀態及 WSARecv；再從完成通知確認 `0x806E7D`→`0x8077B0` 會消耗 staging buffer，另找到 recv completion 下游 `0x807B40`。相較 T03-5 只到 frame staging，已有重大、新的、可核對的 transport 閉環增量。
- 第2輪 T03-6-2：**未啟動**；第1輪達成共用三輪規則的重大發現門檻。
- 第3輪 T03-6-3：**未啟動**；同上。

## 6. 原生 / AI / unknown 與限制

1. 原生已確認：PE WSASend/WSARecv IAT、直接 `call`；send/recv context 與 return/pending/error，send completion count → staging buffer consume；receive completion 可到 `0x807B40`。
2. 部分確認：上一段 4/6-byte staging 到實際同 socket WSASend 的全量支配/每次時序；目前能確認同 transport 家族，但不能在缺完整所有權與異步排程證據時說 4-byte command 必然寫出。
3. 未知：角色 42 Server 原版 reply opcode/fields、拒絕和批准分支、T05 世界轉入、socket endpoint 的特定 session 映射、真正 wire bytes 的擷取、接收資料何時被解密與投遞至 T03 handler。
4. AI 替代：本機 `42→43/69` 測試規則並非原生已驗證配對；任何固定角色、Server 策略、payload 值或登入資料來源都不能由此推為官方行為。
5. 跨 Task：`T02` 擁有通用 WinSock/transport/framing；T03 只引用 socket interface 并追角色選擇業務流。`T05` 擁有真正場景轉換；`T04` 原始角色資料權威；`T06` 控件真實 identity。未修改其他 Task owner 或 catalog。
6. 檢驗方式：`sha256sum Tartaros.bin`、`objdump -p` import、`objdump -D -M intel --section=.text` 的對應 VA instruction。未動態執行、沒有原版 Server、沒有原生 packet capture。給出 VA/raw 的各段使用同版 PE section offset；若另移植其他版本必須重驗。

## 7. T03-7 明確下一入口

- 優先 `0x807B40` receiver decode / stream framing，辨認解包後透過何 dispatcher 與業務 callback；只在有原始證據時將 reply 歸到 T03，避免當作 T02 共用 handler 認領。
- 其次對 `0x8068B0` 的 caller / virtual socket queue consumer 做閉環，確認 T03-5 staging buffer `connection+0x5004` 是否由同一 connection 的 **WSABUF=connection+0xA064（len/buf 欄位在 +0xA064/+0xA068）** 作資料來源，並追 partial completion 及 retry；**send OVERLAPPED=+0xA050、atomic count=+0xA0B8 是不同欄位**。
- 再查可能的選角批准/拒絕 handler 與 T05 跨界，明確列實際 packet length、field offset 和 UI 結果。沒有找到不要猜。