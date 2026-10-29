# E21 — RR-0001 / RR-0004：connection framed bytes → vtable +0x0C → WSASend（KR BIN-first）

研究：2026-10-29 Asia/Taipei。原始 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪重新 `sha256sum` 驗證。只讀檔，不執行原遊戲；.text raw = VA - 0x400C00；.rdata raw = VA - 0xBD2000 + 0x7D0600。最新 main SHA `5cb495f4561833e0a123bbded14b76266ac1f201`，RR-0001/RR-0004 QUEUED；本段跨 Task 補證不修改 owner、main 或 RR。

## 第一輪：重大閉環：先前「WSASend 尚無 caller」是 direct-E8 調查邊界，實際由 virtual method 呼叫

掃原始 .text 直接 E8 rel32，`0x8068B0` **沒有 direct E8 caller**；不代表沒有 caller。原生 .rdata vtable：
- `0xC51748` → `0x806670`
- `0xC5174C` → `0x806CF0`
- `0xC51750` → `0x806850`
- **`0xC51754` → `0x8068B0`**（vtable+0x0C）；原始 BIN raw 0x84FD54 儲存 little endian `b0 68 80 00`。
- `0xC51758` → `0x8069A0`

`0x804B21` 到 `0x804B5A` 具備完整參數傳遞：

```asm
804B21 cmp dword ptr [esi+0xA028],0
804B28 je 0x804C4B                   ; no buffered bytes
804B2E mov eax,[esi+0xA0B8]
804B34 test eax,eax
804B36 jg 0x804C4B                   ; in-flight / blocked gate
804B3C mov eax,[esi+0xA028]          ; length
804B42 mov ecx,[0xFBA854]            ; interface receiver
804B48 mov edx,[ecx]                 ; receiver vtable
804B4A mov edx,[edx+0x0C]            ; vfunc
804B4D lea edi,[ebp-0x14]            ; output count pointer
804B50 push edi
804B51 push eax                       ; byte length
804B52 lea eax,[esi+0x5020]          ; frame bytes buffer
804B58 push eax
804B59 push esi                       ; connection
804B5A call edx
804B5C test eax,eax
804B5E jne 0x804B7C
804B60 push esi
804B61 call 0x8063E0                 ; on send-wrapper failure: pending list flush
804B66 mov ecx,[0xFBA854]
804B6C mov eax,[ecx]
804B6E mov edx,[eax+0x24]
804B71 push 0
804B73 push esi
804B74 call edx                      ; another transport virtual operation
804B76 mov [esi+0xA0A8],ebx
```

當 `[0xFBA854]` 的物件 vptr 為 `0xC51748`（該 vtable 的記憶體位址由 `0x8046F9` 和 `0x8066CB` 原生常數引用支持），**vfunc+0x0C 的唯一已解目標即 `0x8068B0`**。這使 E20 分離的 outgoing buffer and actual socket wrapper 首次有可重現 virtual-call 關聯。語意屬 **conditional vtable resolution**；還要核對實際 runtime `[0xFBA854]` 動態型別生命週期，不能宣稱所有可能替代 vtable 均相同。

## 第二輪：virtual WSASend ABI 及失敗分支

```asm
8068B6 mov edi,[ebp+0xC]            ; frame pointer
8068C3 mov edx,[ebp+0x10]           ; byte length
8068CE mov esi,[ebp+8]              ; connection
8068D1 cmp dword ptr [esi+0xA0A8],0
8068D8 jne 0x806993                 ; blocked
8068DE lea eax,[esi+0xA050]         ; OVERLAPPED
8068F3 push eax                     ; OVERLAPPED*
8068F7 lea ecx,[eax+0x14]           ; WSABUF
8068FC mov [eax+0x18],edi           ; WSABUF.buf
806905 mov [ecx],edx                ; WSABUF.len
806909 push ecx                     ; LPWSABUF
80690A push edx                     ; socket handle was loaded from [esi]
806912 call dword ptr [0xBD25B8]    ; WSASend
806920 cmp eax,-1
806923 jne 0x80697A                 ; accepted / immediate success
806925 call dword ptr [0xBD25CC]    ; WSAGetLastError
80692D cmp edi,0x3E5                ; WSA_IO_PENDING
806933 je 0x806961                  ; pending = not generic failure
806958 pop edi
806959 pop esi
80695A xor eax,eax                   ; zero return on non-pending error
80695E ret 0x10
```

`0x804B5C` 檢查的是 virtual wrapper **返回值**；非零才不走 `0x8063E0`。這不代表 `WSASend` 同步傳完所有 bytes；`WSA_IO_PENDING` 是非同步佇列接受狀態，完成時間/bytes written 需 completion callback 再追。前面 `0x8068B0` 也檢查 frame ptr、length 非零、`conn+A0A8` guard。此一有界功能鏈已真正從 `conn+0x5020` framed bytes 和 `conn+A028` buffered length 到達 socket API，較 E20 有重大進展。

## 第三輪：E20 `0xFE3368` 不能強行接到 WSASend

E20 已證全域 `0xFE3368` 分段指標容器有兩個 producers（`0x8061A0` 和 `0x8063E0`），目前 **沒有** static read → vcall `0x804B5A` 的證據。真正已閉合的 **另一條**連線本地輸出鏈是：

```text
connection+0xA074 pending nodes
  → 0x8061A0 frame builder 0x807830 / 0x807A70
  → connection+0x5020 buffered frame / connection+0xA028 length
  → 0x804B21 gate on buffered length + 0xA0B8
  → 0x804B5A through [0xFBA854] vtable+0x0C
  → (vptr == 0xC51748) 0x8068B0
  → WSABUF / OVERLAPPED → WSASend
```

原生相容需求：Server 端須接受實際 frame headers、payload transform，但最初哪條 connection、第一個 packet、解碼時序仍需 RR-0001；`A02C` indirect writer、builder 失敗進入另一 frame 的實際 wire 仍需 RR-0004。 **不可宣稱全部 RR 已完成、登入可玩、或某個初始官方 opcode 已確認。**

### direct callsite / 排除誤判

原始 BIN .text 的 rel32 E8 callsite for `0x8061A0`: `0x804AD6`, `0x805228`；for `0x8063E0`: `0x495839`, `0x804B61`, `0x804BB9`, `0x8052B3`, `0x805313`, `0x805FDA`, `0x806021`。這些僅是同步/flush 來源，不代表都在直接送 socket。根據 `0xC51754` 的 vtable entry，對 `0x8068B0` direct E8 zero count 不構成無 caller 的反證。

## 重現

```bash
sha256sum Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x804b21 --stop-address=0x804ba5 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x8068b0 --stop-address=0x806970 Tartaros.bin
```

```python
from pathlib import Path
b=Path('Tartaros.bin').read_bytes()
raw=0xC51754-0xBD2000+0x7D0600
assert int.from_bytes(b[raw:raw+4],'little')==0x8068B0
```

三輪實作情況：第 1 輪 virtual dispatch caller/target 閉合已達重大新發現；第 2 輪補足 WSASend 失敗/非同步；第 3 輪辨清兩條資料結構的不同證據範圍。未在原件執行測試。跨 Task 證據寫入 extra/roy1；RR 台帳及 main 不改。下一段 E22 優先查 `0x8046F9`、`0x8066CB` vptr 安裝路徑與非同步 completion `0xA0B8`；再把第一筆 frame 及 mode/fallback 與 RR-0001/0004 acceptance 接合。
