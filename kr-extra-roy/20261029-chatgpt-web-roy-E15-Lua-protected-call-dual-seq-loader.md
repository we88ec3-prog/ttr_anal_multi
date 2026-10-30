# E15 — KR Lua protected-call ABI、雙路 SceneList→.seq loader 收斂（BIN-first）

日期 2026-10-29 Asia/Taipei，來源唯讀 `/mnt/data/Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。原始 `Event.stp` SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` 及 E06 已解 `SceneList.xml` SHA256 `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25` 為本段既有跨證據。本段實際只讀原始 BIN，未運行或 patch Client，不觸碰 main。

## 源核對

前段 E14 來源 `extra/roy1:kr-extra-roy/20261029-chatgpt-web-roy-E14-seq-resource-Lua-parser-execution.md`，blob SHA `fd3f0a30c186b40c13a382c3ed84de5ac7451e4f`。開工前對比 `main...extra/roy1`: ahead 14 / behind 2；保留與主線差異，不自動 merge。

## 第一輪：0x6FE770 真實 Lua protected-call wrapper

```asm
6FE770 push ebp
6FE773 sub esp,0x18
6FE778 mov esi,eax           ; Lua VM / state
6FE77A movzx eax,word [esi+0x34]
6FE77E mov cl,[esi+0x39]
6FE784 mov eax,[esi+0x14]
6FE787 sub eax,[esi+0x28]    ; saved top/base distance
6FE78B mov edi,[esi+0x74]
6FE791 mov eax,[ebp+0xC]
6FE797 mov ecx,[ebp+8]
6FE79A push eax
6FE79B push ecx
6FE79C push esi
6FE7A0 mov [esi+0x74],edx    ; temporary error-context link
6FE7A3 call 0x6FDBA0       ; guarded callback invocation
6FE7AE test eax,eax
6FE7B0 je 0x6FE84E        ; failure path, restores +0x74
6FE7B6 mov ebx,[esi+0x20]
6FE7B9 add ebx,[ebp+0x10]
6FE7BE push ebx
6FE7BF call 0x6FD860
6FE7CC mov eax,ebx
6FE7CE call 0x6FDA60
6FE7D3 mov ecx,[esi+0x28]
6FE7DD mov word [esi+0x34],dx
6FE7E3 mov [esi+0x14],eax
6FE7E6 mov edx,[eax]
6FE7E8 mov [esi+0xC],edx
6FE7EB mov edx,[eax+0xC]
6FE7EE mov [esi+0x18],edx
6FE7F4 mov edi,0x4E20
6FE7FC cmp [esi+0x30],edi
6FE81C call 0x6FDD10       ; conditional stack pressure
6FE827 mov eax,ebx         ; return code/number candidate
; all exit paths restore VM +0x74, including 0x6FE84E error
```

已證 `0x6FE770` 是 VM state/stack/frame 的 guarded call wrapper；更精確的 `[VM+0x14]` top、`+0x28` base、`+0x74` error handler linkage、`+0x34/+0x39` 狀態欄位只可標成**暫定角色**，除非追完 Lua 5.1 runtime 結構與 `0x6FDBA0`。

`0x6FDBA0` 更下游：

```asm
6FDBB0 mov eax,[ebp+8]    ; VM
6FDBB3 mov ecx,[ebp+0xC] ; callback ptr
6FDBB6 mov edx,[ebp+0x10]; callback arg
6FDBC9 mov ecx,[eax+0x70]
6FDBD3 mov [eax+0x70],edx ; temporary protected execution frame
6FDBDC call 0x8FCD50     ; establishes guard
6FDBE4 test eax,eax
6FDBE6 jne 0x6FDC0E
6FDBF0 call dword [ebp-0x60] ; **actual callback invocation**
6FDBF3 mov edx,[ebp-0x54]
6FDBF6 mov [esi+0x70],edx     ; restore error context
6FDC0E mov eax,[ebp-0x54]
6FDC14 mov [ecx+0x70],eax     ; failure restore
```

重大新增：不再只有 `0x6FE770`「受保護執行候選」稱呼；這裡已能以 `0x6FDBA0` 的 **indirect callback call + error-guard + restore** 機器碼確認受保護呼叫的實際骨架。惟還沒證明 callback `0x6F5A50` 與 Lua compile/run 的完整例外碼對應；不擅自把 `0x6FDBA0` 認成 lua_pcall 的一對一 ABI。

## 第二輪：E14 的重要校正——兩條 SceneList consumer 都能到真正的 .seq loader

E13 已找到場景雙鍵 `(questIdx,sceneIdx)` 讀者，雙方都組成 `Event/Sequences/<funcName>.seq`。E14 只在第二條 `0x5659D9` 證實直接 call `0x6F4A50`，卻沒有把第一條 `0x561AF3` 後面的完整 callee 實作納入。E15 回查確認：

```asm
561AEA call 0x55C5A0            ; singleton owner
561AF3 call 0x55D6A0            ; shared Lua environment setup
; 0x55D6A0 end:
55D7BB mov eax,[ebp+0xC]     ; path provided to shared init
55D7C1 push eax
55D7C2 call 0x6F4A50        ; **resource read/ Lua load interface**
55D7C7 mov eax,[ebp-4]
55D7D0 ret 8
; second reader:
5659B6 push 0xFE1EEC
5659BB call 0x55D6A0        ; same callee and internal 6F4A50
5659D6 push eax             ; a path argument
5659D9 call 0x6F4A50        ; second, explicit source load
```

**修正 E14**：第一條 reader 不可稱為「未證實 .seq 執行/載入」，因 `0x55D6A0` 本身已內含 `0x55D7C2 → 0x6F4A50`。第二條除了共享的內部 load，還有 `0x5659D9` 的額外 load call。完整二次載入的目的與 runtime 成敗仍未知，需追 E16。

新區分：
- 第一條 `0x561AF3`：透過共享 setup 函式內部 `0x55D7C2` **間接抵達** `0x6F4A50`。
- 第二條 `0x5659BB` + `0x5659D9`：先透過 shared setup 內部 `0x55D7C2` **間接抵達**，後再**直接呼叫一次** `0x6F4A50`。
- 若第二條兩次 load 的 path 是否相同，必須依 `0x55D6A0` arg2 和 `0x5659D6` 遞入的實際 SSO object 路徑逐一比對；尚不能視為 double-execution bug。
- `0x6F4A50` 會查資源、取 raw bytes、處理 BOM、交給 Lua parser 和 protected VM wrapper；失敗分支可能跳過執行。以上證實 **loader entry path**，不等於某個特定 `.seq` 在實際運行必然成功。

## 第三輪：現有直接 callsite 與玩家首登判定界線

對 KR .text raw bytes 做 direct E8 rel32 搜尋 `0x6F4A50`：15 處，包含 `0x55D7C2`、`0x5659D9`、`0x561C7D`，以及 `0x4A89B6`, `0x4A8A36`, `0x4A8B64` 等 Lua/scene 相關 callers。這表明資源 loader 是**跨功能共享介面**，不能因被 `TutorialMain.lua` 流程引用就稱它必定是 first-login scene gate。

`0x5658D0` 是 `0x5658C2` 之後的有序樹遍歷**內部迴圈標籤**，不是已證明的函式入口，因直接 E8 掃描對 `0x5658D0` 為零；其完整函式起始與 virtual/caller 上游需重新界定。`0x561C7D` 為第一條後續的直接 `0x6F4A50`，但 `0x561C40` 還有自有物件虛擬 callback/清理迴圈，不應將整段亂命名為多次重複執行 scene。

因此：
- **Client 已確認**：scene table index read → `.seq` path → common runtime setup → native resource read+Lua parse/protected invocation，有兩條可能路徑且第二條額外呼叫同類 interface。
- **Client 待逆向**：`0x6FDBA0` callback 正式 exception ABI、`0x55D6A0`/second caller 使用是否同一腳本、其上游 gate 和 player state、T03 `0x42` S→C response、首次登入選擇 `questIdx=1001/sceneIdx=1` 的實際 writer。
- **Server 待開發**：只能在獲得原生 Client wire/handler 前提下實作相容場景選擇與保存；目前沒有可宣告的官方 initial tutorial opcode。
- **跨 Task 待整合**：E13/E14 修正、T03/T06/T07/T16 原稿需 T01 以 claim-level 驗證；不可自行宣稱 FULL-PASS。
- **待遊玩驗證**：不曾啟動原 Client；Lua 片段存在／load 路徑不等於遊玩成功。

## 本輪重現證據

```bash
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x6fe770 --stop-address=0x6fe858 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x6fdba0 --stop-address=0x6fdc29 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x55d790 --stop-address=0x55d7d1 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x6f4b70 --stop-address=0x6f4bcc Tartaros.bin
```

三輪實際完成：一（protected wrapper native）、二（dual scene loader callee 連接）、三（direct callsite/first-login negative gate）；本段重大增量是首次確定 `0x6FDBA0` guarded indirect callback、第一條 scene reader 間接達 loader，並修正 E14 的舊界線。保留 `extra/roy1:kr-extra-roy/` 直至 T01 正式吸收；主線不改，不 Merge。
