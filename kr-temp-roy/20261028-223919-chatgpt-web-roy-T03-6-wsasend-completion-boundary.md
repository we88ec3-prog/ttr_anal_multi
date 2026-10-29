# T03-6 — KR command 42 transport staging → WSASend/WSARecv 與 overlapped completion 邊界

- 研究者：chatgpt-web roy；2026-10-28 22:39:19 Asia/Taipei
- 研究標的：KR `Tartaros.bin`，大小 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀分析。目標未執行、hook 或 patch。
- PE image base 0x00400000；`.text` RVA 0x1000 / raw 0x400 → `.text` VA 0x00401000；本文 `.text` VA 到 raw = VA - 0x00400C00。`.rdata` VA 0x00BD2000 raw 0x007D0600；IAT 查原始 PE import directory。
- GitHub 分支 `t03/roy/chatgpt-web`，本段起始 main `2ba0a2cc72584622eb6bb944fc4f1fb84e63c355` 已合入分支；沿 T03-5 的 queue drain / 4-byte 與 6-byte staging frame 追進實際 Windows socket API。T02 負責共用 socket/framing，本文只登記 T03 的依賴鏈和新的原生 interface 事實。

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

**已證**：對 buffer 與 length、`channel+0xA0A8` 的 gate；使用 channel socket handle `[esi]`，準備 WSABUF-like layout `[esi+0xA050]`，具備 overlapped context (`+0xA0B8`)；若 API 回 `-1`，對 `0x3E5` 特殊處理並返回 2，其他錯誤返回 0；直接返回非 `-1` 時返回 1；入口 gate fail 返回 `-1`。`0x3E5` decimal 997，Windows WSA_IO_PENDING；這個符號解讀基於 WinSock API 慣例，實際欄位依彙編可見，並無伺服器接受選角的證明。

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

**已證**：非同步接收也使用相同 socket/context 家族，WSABUF-like 長度為 `0x1000`，buffer pointer 來自 channel `+0x5018`；錯誤時有虛擬錯誤回調和旗標更動。此處不含角色選擇結果的業務 parser，不能把網路收包等同 command43 或 command69。

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

`0x806E83` 比較 overlapped address 是否為傳送 WSABUF/context `channel+0xA050`；匹配後，用完成位元組數 `ECX` 更新計數及呼叫 `0x8077B0`。

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

**新增有界鏈**：送出 staging buffer (`channel+0x501C` 子物件) 在成功收到匹配的 overlapped 完成訊息、依完成長度更新後可部分刪除或整體清空；這不是 Server 的選角批准回包，而是傳送層 completion。`0x8077B0` 本身並不證實某個遊戲 opcode，亦不能將 buffer 消耗視為對端收到。

## 3. 第三個入口：接收 completion 與接收後續待驗

`0x806DE4` 比對 `channel+0xA030` 接收 overlapped context：

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
- 其次對 `0x8068B0` 的 caller / virtual socket queue consumer 做閉環，確認 T03-5 staging buffer `channel+0x5004` 是否在同一通道、同一 schedule 上傳給 WSASend WSABUF，並追 partial completion 及 retry。
- 再查可能的選角批准/拒絕 handler 與 T05 跨界，明確列實際 packet length、field offset 和 UI 結果。沒有找到不要猜。