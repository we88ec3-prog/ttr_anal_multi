# E14 — KR .seq resource→Lua load/compile/execute 界線、E13 錯誤校正（BIN-first）

日期 2026-10-29 Asia/Taipei；原始 Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。原件唯讀，未執行原版 Client 或 Lua；承接 `extra/roy1:kr-extra-roy/` E13。反組譯：`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`。本段未合併主線。

## I. E13 需正式校正：0x55E2E0 不是文件 reader

原生 `0x55D6A0`:

```asm
55D6A5 mov ebx,[ebp+8]
55D6A9 lea eax,[ebx+8]
55D6AD push eax
55D6B1 call 0x55E2E0
55D6B9 push 0
55D6BB push 0xBF2375
55D6C0 lea ecx,[ebx+0x18]
55D6C3 call 0x402A70
```

`0x55E2E0` 真正操作的是傳入的 **ordered node container/tree**：從 `[arg+4]` sentinel 沿 node 迴圈遍歷，`0x55E33B call 0x81CD10` 處理節點元素，`0x55E34B/0x55E354 call 0x89120C` 釋放；在 `0x55E3C6 call 0x73EBA0` 及 `0x55E3CE call 0x89120C` 清理剩餘樹節點，最後將 sentinel links 指向自身並 `mov [ebx+8],0`。此為 **容器重置／記憶體回收**，不是 script file load、compile 或 lua_execute；E13 「下游 0x55E2E0 需要追 reader」應修正為「下游 0x55E2E0 是清理初始化」。

`0x55D6A0` 後續 `0x6F55B0` 系列則是 native callback registration，e.g. `0x55D6CF push 0x55C940 → call 0x6F55B0`、`CreateObject`、`AniObject`、`WalkObject`、`WarpObject`；不能將這些等同來源腳本已跑。

## II. 重大新鏈：0x6F4A50 確實從資源查詢與 virtual read 進入 Lua 解析／執行

與 E13 只確認 `0x5659D9 call 0x6F4A50` 不同，本輪直接還原該 callee：

```asm
6F4A6A mov eax,[ebp+8]        ; path argument
6F4A80 mov cl,[eax]           ; copy NUL-terminated resource path to local buffer
6F4A8E push 0xBED1E0
6F4A93 push edx              ; local path buffer
6F4A99 call 0x714770        ; resource lookup
6F4A9E mov edi,eax
6F4AA3 test edi,edi
6F4AA5 je 0x6F4BCF         ; missing resource
6F4AAB mov eax,[edi]        ; resource vtable
6F4AAD mov edx,[eax+0x2C]
6F4AB2 call edx             ; resource length, subject to interface validation
6F4AB9 push eax             ; allocate len+1
6F4ABA call 0x87DC3D
6F4AC6 mov eax,[edx+0x38]  ; resource vtable +0x38
6F4AC9 push esi
6F4ACC call eax             ; obtains data pointer
6F4AD0 call 0x89DBD0       ; memcpy into local buffer
6F4AD5 mov [esi+ebx],0      ; ensure string terminator
6F4AEA cmp byte [ebx],0xEF ; UTF-8 BOM 0xEF 0xBB 0xBF branch
6F4AEF cmp byte [ebx+1],0xBB
6F4AF5 cmp byte [ebx+2],0xBF
6F4B09 xor eax,eax
6F4B0B call 0x6F7110      ; BOM case parse/compile interface
6F4B68 call 0x6FE990      ; non-BOM case parse/compile interface
6F4B89 push 0x6F5A50      ; Lua error handler callback
6F4B9A call 0x6FE770      ; Lua protected call / execution candidate
6F4BB0 test eax,eax        ; result gate
6F4BB8 mov esi,1
6F4BC4 call eax            ; vtable +4 resource release
6F4BC7 call 0x891D3D      ; free owned buffer
6F4BED if esi != 0 ...
6F4BFA call 0x6F47A0      ; post-success diagnostics/logging
6F4C07 mov eax,esi        ; boolean outcome
```

**重要精確化**：
- `0x6F4A50` 是真正的**資源查找→虛擬讀取→字串緩衝→Lua parser/loader→protected execution** 有界鏈，不可再稱單純字串傳遞。
- `0x6F4BFA→0x6F47A0` **不是** Lua 執行者：本輪直接驗證 `0x6F47A0` 檢查 Lua stack type 3/4、取出 message、呼叫 `0x8930BD` 格式化記錄並恢復 stack 16 bytes。它是結果訊息／記錄診斷相關介面。這是 E13 未知下游的重要修正。
- `0x6FE770` 屬 Lua protected call / execution **高度有根據的候選**（讀入資料後、調用解析介面後並將 callback `0x6F5A50` 傳入），但仍應再逐一拆其 Lua VM 異常與 return code 以確定 precise ABI。上述 `0x6F7110`、`0x6FE990` 亦不得冒充已完全辨識的 Lua C API 名稱。
- **存在缺失資源分支** `0x6F4AA5→0x6F4BCF`，且 `0x6F4A50` 的 parse/execute return boolean `ESI` 需追成功/失敗路徑；不能宣稱所有 `.seq` 均正常執行。

## III. 與兩條 SceneList consumer 的差別

`0x56592C` 路徑已經 E13 證實 `Event/Sequences/` + match `funcName` + `.seq`；`0x5659B6 push 0xFE1EEC → 0x55D6A0` 初始化腳本 runtime，然後 `0x5659D6 push path → 0x5659D9 call 0x6F4A50`。**此路徑現已實質閉合到檔案內容及 Lua parse/execution candidate**。

另一條 `0x561A8B..` 雖然同樣組 `.seq` path 並 `0x561AF3 call 0x55D6A0`，但本輪現有 `0x561AD0..0x561B32` 中未見其緊接著呼叫 `0x6F4A50`；故不能將兩條 caller 當成完全相同的執行時序，應追 `0x561B32..` 後續帶 `[this+0x70]` 的 consumer。

## IV. 玩家功能、Server 分工與尚未閉合部分

- **Client 原生已確認**：場景 pair 由 E13 的兩個 reader 查有序索引並產生 `Event/Sequences/<funcName>.seq` 路徑，其中 `0x5659D9` 確實呼叫能取資源 bytes、辨識 BOM、交給 Lua 解析及受保護執行候選的 `0x6F4A50`。
- **Client 待逆向**：`0x5658D0` 的 upstream player state/gate；`0x6FE770` 的精確 ABI、`Register(tutorial_start)` 如何被 Lua runtime 曝露及事件觸發的 C++ caller；T03 `0x42` response→首次教學選擇的實際 S→C handler；T07 scene-controller 具體場景類型。
- **Server 待開發**：相容 scene/state decision，**只在 Client wire 接收鏈已證實後**定義封包；不把 XML `1001/1` 當作官方 S→C opcode 或必發值。
- **跨 Task 待整合**：E06/E08/E13/E14 與 T03/T06/T07/T16；仍須 T01 驗證，E14 不能自宣 FULL-PASS。
- **待遊玩驗證**：本輪沒跑 Client、沒導入相容 Server，尚無 runtime 可玩認證。

## V. 重現及三輪門檻

```bash
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x55e2e0 --stop-address=0x55e410 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x6f4a50 --stop-address=0x6f4c18 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x6f47a0 --stop-address=0x6f4826 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x5659b5 --stop-address=0x565a22 Tartaros.bin
```

第 1 輪已拿到 `0x6F4A50` 真正的 resource→read→Lua→call chain，以及 `0x55E2E0` 的容器清理反證與 `0x6F47A0` 訊息記錄反證，為 E13 明確缺口的**重大新增**；E14-2、E14-3 未啟動，符合共用三輪規則。後續 E15 應將 `0x6FE770` 原生 call ABI 完整辨識，並追 `0x5658D0` / `0x561Axx` 的上游條件與 script 呼叫者。

保留 `extra/roy1:kr-extra-roy/` E01–E14 直到 T01 完整整合與驗收後才清理；不動 main、不自動 merge。
