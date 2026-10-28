# T03-16 — KR 接收 worker 上游 vtable+0x48 輸出槽：ESP 別名與生命週期實證

- 日期：2026-10-28 23:50:41 Asia/Taipei；分析者 `chatgpt-web roy`。
- 原件：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，當段重新核對。
- `.text` VA 0x401000/raw 0x400；`.text` 中 raw offset = VA − 0x400C00。
- 使用原始 PE + GNU objdump 的靜態 BIN-first 檢查；未執行 client、未修改檔案、沒有封包擷取或原版 Server。
- 前段 `T03-15` 已標出 `0x4918C1`/`0x491905` vtable+0x48、`0x49197F` 父物件取值，惟當時輸出槽是否同一位置保留限制。本段針對這個缺口進行 stack-slot SSA / call-boundary 重核。`02-PROJECT-SHARED-INSTRUCTIONS.md` 三輪門檻適用。

## 重要新發現與證據分級

**原生已確認（有界）：** 兩分支 `0x4918AF`/`0x4918F3` 皆先 `lea [esp+0x14]` 取得輸出槽位址，接著推入三個 DWORD 並在 `[esp+0x20]` 寫入零；因 `0x20 - 3*4 == 0x14`，該寫入指向**同一槽**。其後再推入另外兩個 DWORD，以 vtable+0x48 呼叫，將輸出槽位址作為其中的 stack argument。成功回到原 stack frame 之後，`0x49197F` 從 `[esp+0x20]` 讀取的是同一組函式內原先以輸出槽為用途的局部變數（注意這段之前 stack cleanup 及不同分支仍須完整追蹤）。本段可將上段的「清零槽與傳入輸出槽可能相同」收斂為**確切相同**，但尚未將所有 post-call stack-slot alias 強判為同一個 parent pointer 值。

**另一個生命週期證據：** 在兩條 vtable+0x48 呼叫後的各自支路，`0x4918C3` / `0x491907` 讀取局部輸出指標；`0x49191B` 共用出口如指標非零，經其自身 vtable+0x8 呼叫釋放/結束動作。可確認是一個具有虛擬 +0x8 方法的介面物件，具體 COM 類別/方法名稱未由 BIN 確認。特別注意 `0x49197F` 的 worker parent 槽和 `0x49191B` 這個介面槽**不應僅憑 offset 字面相同就合併**；下列指令顯示在分支與暫存期間存在不同局部位置。

**尚未確認：** vtable+0x48 的實際函式位址、`0x80486D` worker vtable+0 的 target、原生 command 0x42 對應 S→C handler、選角批准/拒絕、T05 世界轉場。

## Round 1 — 兩分支精確 stack arithmetic

### A 分支（`0x4918AF`）

```asm
4918a5: 8b 4c 24 3c           mov ecx,[esp+0x3c]
4918a9: 8b 41 10              mov eax,[ecx+0x10]
4918ac: 83 c4 1c              add esp,0x1c
4918af: 8d 4c 24 14           lea ecx,[esp+0x14]
4918b3: 51                    push ecx
4918b4: 53                    push ebx
4918b5: 53                    push ebx
4918b6: 89 5c 24 20           mov [esp+0x20],ebx
4918ba: 8b 10                 mov edx,[eax]
4918bc: 8b 52 48              mov edx,[edx+0x48]
4918bf: 53                    push ebx
4918c0: 50                    push eax
4918c1: ff d2                 call edx
4918c3: 8b 44 24 14           mov eax,[esp+0x14]
4918d3: ff 15 f4 25 bd 00     call dword ptr [0xbd25f4]
4918d9: eb 40                 jmp 0x49191b
```

取 `S=ESP(0x4918AF)`；`lea` 目標 `S+0x14`。執行 3 次 `push` 後 ESP=`S-0x0C`，故 `mov [esp+0x20]` 的位址是 `S+0x14`；**與 lea 的輸出槽精確一致**。第五次 push 之後，經 vtable call；對該 call 的參數清理型態必須由實際 target / calling convention 確定，不能單靠此片段斷言 caller 後所有 ESP offset 一律不變。

### B 分支（`0x4918F3`）

```asm
4918e9: 8b 74 24 3c           mov esi,[esp+0x3c]
4918ed: 8b 46 10              mov eax,[esi+0x10]
4918f0: 83 c4 1c              add esp,0x1c
4918f3: 8d 54 24 14           lea edx,[esp+0x14]
4918f7: 52                    push edx
4918f8: 53                    push ebx
4918f9: 53                    push ebx
4918fa: 89 5c 24 20           mov [esp+0x20],ebx
4918fe: 8b 08                 mov ecx,[eax]
491900: 53                    push ebx
491901: 50                    push eax
491902: 8b 41 48              mov eax,[ecx+0x48]
491905: ff d0                 call eax
491907: 8b 54 24 14           mov edx,[esp+0x14]
491910: 8b 4e 10              mov ecx,[esi+0x10]
491913: e8 28 5f 24 00        call 0x6d7840
```

與 A 同樣，經 3 次 push 由 `S` 變為 `S-0x0C`，`S-0x0C+0x20=S+0x14`。`0x4918FA` 即清空要以 `0x4918F7` 傳出的局部輸出槽；先前只說「可能同槽」是不夠精確的。

## Round 2 — 介面物件與 worker 父物件不能混認

```asm
49191b: 8b 44 24 14           mov eax,[esp+0x14]
49191f: 3b c3                 cmp eax,ebx
491921: 74 08                 je 0x49192b
491923: 8b 10                 mov edx,[eax]
491925: 50                    push eax
491926: 8b 42 08              mov eax,[edx+0x8]
491929: ff d0                 call eax
49197f: 8b 7c 24 20           mov edi,[esp+0x20]
491983: 8d 9f 40 01 00 00     lea ebx,[edi+0x140]
491989: 53                    push ebx
49198a: e8 b1 2d 37 00        call 0x804740
```

`0x49191B` 局部變數 offset `+0x14` 和 `0x49197F` 的 offset `+0x20` **不是相同位址**（兩處在正常執行中同屬同一函式的 ESP 基準，僅在被呼叫函式完成正常清理條件成立時）。vtable+0x48 呼叫的輸出物件具有另一個 vtable+0x8 消費/釋放入口；其結果可能經中介影響下一階段 parent，但不能說 vtable+0x48「直接 new parent」。

額外原生 `0x6D7840` 核查：它自身是一個大的介面/格式中繼處理函式，先透過 `esi->vtable+0x30`，然後呼叫 `ds:[0xBD2618]`，對結果物件呼叫 `vtable+0x48`，再呼叫 `ds:[0xBD2614]`、`0x6D79B0` 等。它沒有直接以清晰的 `mov [parent+0x140],imm_vtable` 指令進行 worker vtable 寫入。這條路徑可能反映額外的介面生命週期，**不能因此解出選角業務 opcode**。

```asm
6d785f: 8b 06                 mov eax,[esi]
6d7861: 8b 50 30              mov edx,[eax+0x30]
6d786b: ff d2                 call edx
6d789d: 8b 41 48              mov eax,[ecx+0x48]
6d78a0: ff d0                 call eax
6d78b6: ff 15 14 26 bd 00     call dword ptr [0xbd2614]
6d78ca: e8 e1 00 00 00        call 0x6d79b0
```

## Round 3 — 反證、上游來源與停止判斷

1. 前段 T03-15 `0x4918B6` / `0x4918FA` 的 output alias 未閉合：**已完成位址等式驗證**，兩分支皆成立。這是原生機器碼確定的新資料別名鏈。
2. "+0x48" 是 `eax` 所指另一個虛擬介面（`eax=[ [esi+0x10] ]` 等），**不是** `parent+0x140` worker 的 vtable。`0x80486D` 的目標還要找父物件首次配置/寫入。
3. `0x49191B` 使用另一個 local offset 做 vtable+8 呼叫；與 `0x49197F` offset 不同。指標具體型別與這個呼叫的 release 語意仍屬推測，不能只以 COM 慣例當原生已確認。
4. `0x6D7840` 說明共通介面物件有更深的間接流；這次的本地直接分析未建立其與選角 S→C 回包的任何配對。
5. 第一輪：ESP SSA 證實兩分支 output-slot alias；第二輪：局部槽分離與 `0x6D7840` 交叉驗證；第三輪：未證實 target 的否證與需保留之不確定性。**第一輪已取得可核對的主要新發現**，第二三輪為實際補足 caller/callee 與反證；未宣稱完成 server reply。

## 玩家情境 / 完成度矩陣

| 目標 | 已確認 Client | Client 待逆向 | Server 待開發 / 跨功能 |
|---|---|---|---|
| 選角 C→S | T03-3..6 command 42 builder、queue、frame、WinSock transport | 此角色同一 session 的實際 send capture | 相容 Server 回應規格須待 native S→C 查明 |
| 接收與業務投遞 | T03-7..12 decode、lane reader、worker callback interface | `worker.vtable[0]` 實作、原生 opcode/handler | T02 transport ↔ T03 business 邊界待串接 |
| 上游 worker 來源 | 本段 2 路 +0x48 out-param alias / distinct local consumer | 指向 parent 的分配、實際 vtable writer | 不得以介面 getter 推測 Server 選角批准 |
| 世界轉場 | 暫無本段新轉場證據 | 選角批准後轉場狀態 writer | 與 T05 跨功能整合、正式可玩測試 |

## 下一段 T03-17

優先從 `0x49197F` 使用的 `[esp+0x20]` 找完整 writer / 帶有此局部槽的上游函式註冊，確認是否真的為 worker 父物件，以及其建構時 vtable 的寫入（直接常數、複製或繼承）。另可用 PE import table 與相關 COM GUID 常數去辨識 `vtable+0x48` 的介面領域，以避免把圖形/系統介面處理錯認成網路接收業務。即使找到 COM 介面，也要以真正的 worker callback / wire opcode 證據做 T03 選角認定。不可使用測試 fixture 42→43/69 作官方協定。

## Git / 證據政策

僅提交本段完整 Markdown 到 `t03/roy/chatgpt-web`，不修改 main、T01 驗證目錄或其他 Task。未動態執行，無原版 Server 數據。原始檔未更動。