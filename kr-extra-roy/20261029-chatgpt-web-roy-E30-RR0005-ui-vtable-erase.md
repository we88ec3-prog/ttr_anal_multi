# E30 — RR-0005／RR-0001：事件接收器 vtable 與重複 connection key 的樹節點 erase

研究日期 2026-10-29 Asia/Taipei。原件 KR Tartaros.bin 12,472,320 bytes、SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；本輪 `sha256sum` 核對。唯讀、不執行、不修補。PE .text raw=VA-0x400C00；.rdata raw=VA-0xBD2000+0x7D0600。main 開工 b82ff0521ddbad67b700612493e7362a1d5fad66；當時 RR-0001、0005 均 QUEUED。extra/roy1 跨 Task 補證，不認領正式 RR、也不聲稱 0x13 login reply 已接通。

## 第一輪：0x66C620 的 vtable 路由而非直接 E8 caller

掃完整 executable 原始 .text 的 E8 rel32，沒有找到直接呼叫 0x66C620 的 matched 位址；此不等於函式無 caller。掃 BIN 中 0x66C620 little-endian 函式指標，恰好一處 raw offset `0x81AAF0`，是 .rdata VA `0xC1C4F0`。其前後 32-bit entries 原件為：

```text
VA C1C4D8 = 0x476430
VA C1C4DC = 0x75B110
VA C1C4E0 = 0x4067E0
VA C1C4E4 = 0x4067E0
VA C1C4E8 = 0x476430
VA C1C4EC = 0x476430
VA C1C4F0 = 0x66C620  <-- UI/event receiver method
VA C1C4F4 = 0x757180
VA C1C4F8 = 0x403DB0
VA C1C4FC = 0x757130
VA C1C500 = 0x406FC0
```

這直接證明有一個靜態函式指標表引用 0x66C620。根據前後項連續函式位址符合 C++ vtable 候選，但 **尚未定位該 vtable 的起點或物件 vptr 安裝指令**，故此處只標「vtable-like table」，不自行推 method slot 數值，也不能將它命名成 T03 0x13 response handler。必須從 VA 0xC1C4F0 附近對應的 vptr 安裝 xref / RTTI 開始向上找誰實際派送 0x709 / 0x70A / 0x578 事件。

此前 E29 已在 `0x66C620` 原生指令確認 `[event+0x10]` 之事件值 `0x709`、`0x70A`、`0x578`；其對象必須符合 object+0xF0/0xF4/0xF8 所指 UI 物件的 +0x20 identity，成立後可調用 `0x66C090` 再進 `0x4957C0`。目前仍沒有 CClient S2C `0x13` 封包消費者直接或間接呼叫本事件分派的證據。

## 第二輪：0x7B6890 是真正的有序樹 iterator erase（重新連接、平衡、釋放）

`0x806C91..0x806CB3` 中，transport+0x18 keyed tree 以 `0x8438C0` 尋找指定 connection key；非 end sentinel 時，將既有 iterator 傳入 `0x7B6890`。本輪直接反組譯 `0x7B6890..0x7B6AEB`：

```asm
7B6893 mov eax,[ebp+0x10]       ; erase target iterator
7B6899 cmp byte [eax+0x15],0    ; nil/sentinel protection
7B68B4 call 0x49E6A0           ; helper, precise iterator semantics pending
7B68E1 mov esi,[ebx+4]          ; parent
7B68E9 mov edx,[ebp+8]          ; tree container
7B68EF cmp [eax+4],ebx         ; tree root check
7B68F4 mov [eax+4],edi          ; root replacement
7B68FD mov [esi],edi           ; left-child replacement
7B6901 mov [esi+8],edi         ; right-child replacement
7B692D mov [eax],ecx          ; update leftmost
7B6959 mov [ecx+4],eax       ; successor / parent adjustment
7B69B3 mov byte [ebx+0x14],cl ; node color state
7B69E8 mov byte [ecx+0x14],bl
7B69F2 call 0x763F60         ; tree rebalance rotate helper
7B6A24 call 0x43E670         ; another rotate helper
7B6AC3 mov edx,[ebp-4]
7B6AC7 call 0x89120C         ; free removed node allocation
7B6AD5 pop edi
7B6AD6 pop esi
7B6AD7 pop ebx
7B6AD8 test eax,eax
7B6ADC dec eax
7B6ADD mov [ecx+8],eax       ; tree size decrement when nonzero
7B6AE6 mov [eax],ecx        ; return iterator
7B6AEB ret 0xC
```

因此 **key 已存在時會先從 transport lookup tree 真正移除舊的樹節點**，不是在原節點上原地覆寫 key/Conn*。 `0x7B6890` 的資料結構操作和 `0x57EF20` 新配置 0x18-byte node、`0x57E850` ordered insert 在 0x806AD0 caller 構成 erase→new node→insert 路徑。

### 重要生命週期限制

`0x7B6AC7` 釋放的是 **樹節點記憶體**，不能由此推論它也關閉原 connection socket 或析構 node+0x10 指向的 Conn*。舊 Conn* 的關閉/引用數計數/回收所有權須另外查其他 callsite（如 `0x805AF0`、virtual close `+0x24`）以及 .rdata iterator destructor，避免 Server 規格誤把 map replace 等於網路斷線。

## 第三輪：E26～E29 的有界鏈與仍未閉環

```text
UI/event [event+0x10] == 0x70A or 0x578
 → 0x66C620 (vtable-like table entry at 0xC1C4F0)
 → 0x66C090
 → 0x4957C0
 → 0x806AD0 (key0 or key2, port numeric 0x20E0 / 0x20DE)
 → key already exists? 0x8438C0 lookup → 0x7B6890 erase node
 → 0x57EF20 new tree node (key + Conn*) → 0x57E850 insert
 → 0x8069A0(key0) lookup → 0x8060D0 0x39 local payload enqueue
 → E19–E25 builder/scheduler/vtable WSASend + completion
```

上述流程帶有條件：event identity、connect socket success、tree insertion success、queue/scheduler gates 均需成立。這不能等同首次登入一定成功或已驗證 Server wire contract。特別是 0x66C620 尚未有 0x13 packet consumer 連結，0x70A/0x578 是本地 event 識別不是網路 opcode。

**已證新增**：0x66C620 direct-E8 scan empty 但實際存在 .rdata 0xC1C4F0 方法項；0x7B6890 並非覆值而是真正的紅黑樹式 erase，含 rotate/relink/free/count update。**未證**：UI vptr 安裝/真實 event producer、T03 0x13→event bridge、原 Conn* close/reuse、各 connection 首筆實際 wire frame。

分類：Client 待逆向 = event producer、Conn ownership、first packet；Server 待開發 = 保留相容契約，勿假定官方 account/port policy；跨功能待整合 = T02 RR-0001/0005 × T03 RR-0003；待遊玩驗證 = Client+replacement Server 送收/重連 trace。

三輪深入紀錄：第一輪 vtable-like method 關係；第二輪 erase 的 root/parent/rotation/free；第三輪反證「socket closed」與「已接 0x13」的不足。E30 為有界新證據，不代表正式 RR COMPLETED、S00 ACCEPTED 或 T01 FULL-PASS。

### 原件重驗

```bash
sha256sum Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x66c620 --stop-address=0x66c71b Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x7b6890 --stop-address=0x7b6aee Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x806c91 --stop-address=0x806cd8 Tartaros.bin
```

下一段 E31：優先由 vtable-like table 0xC1C4F0 對應之類別 constructor、instance registration 追真正 UI event sender；並反查 T03 0x13 response consumer 是否橋接。對 key replace，另找 `0x7B6890` erase 前後 socket close/release 的獨立實證。