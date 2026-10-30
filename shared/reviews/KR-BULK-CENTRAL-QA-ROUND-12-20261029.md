# KR Bulk 集中品質檢查 — 第十二段：FUN_0055D7E0 完整原生呼叫序列（2026-10-29）

**PARTIAL / DIRECT BIN CONTROL-FLOW EVIDENCE / NOT FULL-PASS**

## 來源與驗證環境

- 第一手資料：使用者提供的 `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- PE32 x86，ImageBase `0x00400000`；`.text` RVA `0x1000`、raw `0x400`。對本段地址可使用 `RAW = VA - 0x400c00`。
- 使用本地 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x55d7e0` 反組譯原件 `.text` 範圍，另以 Python 逐一解碼 `E8 rel32` 的實際 caller/callee 相對位址，以及 `BF imm32` 目標常數。
- 比對 `extra/roy2` 現有 `kr-bulk-roy/<SHA>/functions/0x55d7e0.c`，該 Git blob `f97fc525bd23944f312c3eb5db595313c3192f69`；偽碼顯示大量 `FUN_006f55b0`、`FUN_006f5790` 重複呼叫，末端呼叫 `FUN_0055e410`、`FUN_0055e4f0`。

## 原生 CFG / 指令級新結論

已在 `0x0055D7E0–0x0055E2D2` 原始連續區域逐位址掃描相對 CALL。注意：此為有界反組譯掃描，不能據此聲稱全程不存在任何間接 CALL、跳入路徑、不同函式共享區段或額外間接分支。

| 原生 direct CALL 目標 | 確認次數 | 範圍／意義 |
|---|---:|---|
| `0x006F55B0` | **72** | 首次 `0x0055D7F7`；重複初始化／使用，實際語意待追 |
| `0x006F5790` | **72** | 首次 `0x0055D808`；與前項在重複序列中成對 |
| `0x0055E410` | **1** | `0x0055E2BC`，接近序列尾端 |
| `0x0055E4F0` | **1** | `0x0055E2C5`，接近函式返回前 |

進一步掃描 `BF <imm32>`、目標介於 `0x00C00000–0x00C20000` 的 load，得到 **72 個不同的 EDI 立即數**，恰與 72 組 `0x006F55B0` / `0x006F5790` 直接 CALL 計數一致。

### 第一組原始 x86 指令

```asm
0055D7E0  55                 push ebp
0055D7E1  8B EC              mov ebp,esp
0055D7E3  51                 push ecx
0055D7E4  A1 F0 1E FE 00     mov eax,dword ptr ds:[0x00FE1EF0]
0055D7E9  53                 push ebx
0055D7EA  56                 push esi
0055D7EB  8B 30              mov esi,[eax]
0055D7ED  57                 push edi
0055D7EE  6A 00              push 0
0055D7F0  68 F0 C2 8D 00     push 0x008DC2F0
0055D7F5  8B D8              mov ebx,eax
0055D7F7  E8 B4 7D 19 00     call 0x006F55B0
0055D7FC  8B 33              mov esi,[ebx]
0055D7FE  BF 7C 02 C1 00     mov edi,0x00C1027C
0055D803  B8 EE D8 FF FF     mov eax,0xFFFFD8EE
0055D808  E8 83 7F 19 00     call 0x006F5790
```

### 第一個重複單元的第二次

```asm
0055D80D  A1 F0 1E FE 00     mov eax,[0x00FE1EF0]
0055D812  8B 30              mov esi,[eax]
0055D814  6A 00              push 0
0055D816  68 F0 C2 8D 00     push 0x008DC2F0
0055D81B  8B D8              mov ebx,eax
0055D81D  E8 8E 7D 19 00     call 0x006F55B0
0055D822  8B 33              mov esi,[ebx]
0055D824  BF 84 02 C1 00     mov edi,0x00C10284
0055D829  B8 EE D8 FF FF     mov eax,0xFFFFD8EE
0055D82E  E8 5D 7F 19 00     call 0x006F5790
```

### 尾端直接呼叫與返回

```asm
0055E2A1  BF 64 02 C1 00     mov edi,0x00C10264
0055E2A6  8B 33              mov esi,[ebx]
0055E2A8  B8 EE D8 FF FF     mov eax,0xFFFFD8EE
0055E2AD  E8 DE 74 19 00     call 0x006F5790
0055E2B2  A1 F0 1E FE 00     mov eax,[0x00FE1EF0]
0055E2B7  50                 push eax
0055E2B8  8D 4D FC           lea ecx,[ebp-4]
0055E2BB  51                 push ecx
0055E2BC  E8 4F 01 00 00     call 0x0055E410
0055E2C1  83 C4 08           add esp,8
0055E2C4  50                 push eax
0055E2C5  E8 26 02 00 00     call 0x0055E4F0
0055E2CA  5F                 pop edi
0055E2CB  5E                 pop esi
0055E2CC  5B                 pop ebx
0055E2CD  8B E5              mov esp,ebp
0055E2CF  5D                 pop ebp
0055E2D0  C3                 ret
```

所列 `0x0055E2A1` 一帶位址以原件 0x0055E2A0 附近 bytes 手工／工具對位；後續其他研究可用完整原始指令再次核對。此段對終止地址及 tail 的語意只達到直接相對呼叫與返回層級。

### EDI 立即數樣本

- 第 1 組：`0x00C1027C`（`mov edi` 於 `0x0055D7FE`）。
- 第 2 組：`0x00C10284`（`0x0055D824`）。
- 第 3 組：`0x00C0DD40`（`0x0055D84A`）。
- 第 4 組：`0x00C0DD50`（`0x0055D870`）。
- 倒數 1 組：`0x00C10264`（`0x0055E2A1`）。
- 72 個不同立即數屬於本段原生指令位元組直接觀察；未證明它們是物件、登錄表、函式指標或可寫全域。

## 能確定及不能確定的事

**可確定**：`FUN_0055D7E0` 對兩個特定 direct CALL target 的重複數量各為 72，並且在已掃描區段末尾有兩個不同 direct CALL；源頭碼呈現大量展開而非直接一個短 loop。

**不可確定**：`0x006F55B0` 或 `0x006F5790` 的正式角色；`EDI` 常數實際資料型別、暫存器間資料依賴和副作用；是否有特殊控制分支跳過部分呼叫；有無更高層初始化／註冊副作用。暫不把函式命名為「事件註冊迴圈」或「角色動作初始化」。

## 與其他 Task 共用及下一步

- 可按 `0x0055D7E0`、callee `0x006F55B0`、`0x006F5790` 查詢同一證據鏈。
- 下一階段追查兩個 callee 的實際參數語意、`0x00FE1EF0` 來源、`0x008DC2F0` 與 72 個 EDI 指向的 .rdata/.data 內容，建立完整 dataflow 才能提升功能性主張。
- 完整 111,054 筆 `index.jsonl → pseudocode → raw` 雜湊核對仍阻塞於此環境沒有完整 checkout，不能因這次有 1 個實際函式證據而宣稱全量品質通過。
- 本研究為 QA 觀察，並未修改 `main`、其他 Task 原稿或 T01 正式 FULL-PASS 知識。
