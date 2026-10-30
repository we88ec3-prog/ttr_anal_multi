# KR Bulk 集中品質檢查 — 第十五段：Rebind / DeleteAllObject 後置綁定鏈（2026-10-29）

**狀態：PARTIAL / BIN-FIRST BOUNDED CONTROL-AND-DATA-FLOW / NOT FULL-PASS**

## 1. 研究範圍與版本

延續第十四段 72 個名稱共用零回傳 stub `0x008DC2F0` 的發現，追查不同的 `Rebind`、`DeleteAllObject` 登錄、`0x00FE1F20/24/28` writer 及 callback target。

原始 `/mnt/data/Tartaros.bin`，12,472,320 bytes；本次實算 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。原生 x86 由原件 `.text` 切片交給 objdump 反組譯。ImageBase `0x400000`、`.text` raw `0x400` / RVA `0x1000`，故檔案 offset = VA - `0x400c00`。

已讀 GitHub `extra/roy2`：`0x55e620.c` blob `722114fdc266c65924a9f49e4fd2352ee13bf28e`；`0x5f5d10.c` blob `b3eb70c582e1e339fd1fe2c144eddb42298ce5ff`；`0x4a2bb0.c` blob `44189c8e6528080ff1df74330995a803d53682bd`；`0x6f57f0.c` blob `c1c463fc35609fa12d085884b4c78e3fed3db076`；`0x6f5680.c` blob `62178912414496219c1c47361277ed1c1e8e0ca2`。

## 2. 本段重大發現：Rebind 的 native target 並非偽碼資料列的缺漏

`0x0055E590` **在原始 BIN 中確實存在**，但 GitHub frozen `functions/0x55e590.c` 依指定路徑查詢得到 404。這是重要導航限制：**saved pseudocode missing ≠ 原生函式不存在**。

```asm
0055E590 A1 20 1F FE 00       mov eax,[0x00FE1F20]
0055E595 E8 16 46 F4 FF       call 0x004A2BB0
0055E59A A3 24 1F FE 00       mov [0x00FE1F24],eax
0055E59F 33 C0                xor eax,eax
0055E5A1 C3                   ret
```

故 callback 的原生行為是從 `0x00FE1F20` 讀到狀態，呼叫 `0x004A2BB0` 取得 EAX，寫入 `0x00FE1F24`，**回傳 0**。這不是單純空 stub，也不能從函式名推斷它會將前述 72 個名稱逐一改成不同 callback。

`0x004A2BB0` GitHub 偽碼反映一個由數值/可解析字串取得整數的路徑：對類型 3 的數值作 `ROUND`，類型 4 先嘗試解析，失敗回傳 0。這部分屬**偽碼待完整原生 CFG 複核**；本段已確證 `0x0055E595` 的 direct call 邊。

## 3. DeleteAllObject 及全域 writer 的實際效果

`0x0055E4F0` 在 `0x0055E508` 將 `0x005F5D10` 寫到 `0x00FE1F28`，隨後以 `0x0055E620` 建立 type 6 closure-like 記錄並透過 `0x006F57F0` 交付。原件的 `0x005F5D10`：

```asm
005F5D10 C3   ret
005F5D11 CC   int3
```

**直接確認**該被指定的 handler 是沒有額外指令的 return stub，而不是遊戲物件的實際刪除流程。

`0x0055E620` 在原始 BIN：

```asm
0055E620 55                    push ebp
0055E621 8B EC                 mov ebp,esp
0055E623 6A FF                 push -1
0055E625 68 C8 83 93 00        push 0x9383c8
0055E62A 64 A1 00 00 00 00     mov eax,fs:[0]
...
0055E656 8B 0D 24 1F FE 00     mov ecx,[0x00FE1F24]
0055E65C FF 15 28 1F FE 00     call dword ptr [0x00FE1F28]
0055E662 B8 01 00 00 00        mov eax,1
...
0055E675 C3                    ret
```

此 callback 透過全域 `0x00FE1F28` 執行**間接呼叫**，之後固定回傳 1。其初始值由 `0x0055E4F0` 的原生 writer 指向 `0x005F5D10`（純 ret），但其他 writer 是否在 runtime 更新該指標，未做全程 xref 搜索，**不能宣布 DeleteAllObject 永遠無效果**。

`0x00FE1F24` 同時受到兩個已確認 writer：
- `0x0055E428`：先設成 `0x00FE1EEC`。
- `0x0055E59A`：`Rebind` callback 執行後寫入 `FUN_004A2BB0` 的結果。

因此，前段「72 個名稱先綁同一個零回傳 stub」與這段「獨立的 Rebind / DeleteAllObject 流程」在目前觀察的結構上是**兩條相關但尚未證明彼此取代的路徑**。不能因為看見 `Rebind` 字串就推論它會一鍵重綁 72 個名字。

## 4. 上游導向與反證

`0x0055E410`：
```asm
0055E422 89 1D 20 1F FE 00       mov [0x00FE1F20],ebx
0055E428 C7 05 24 1F FE 00 ...    mov [0x00FE1F24],0x00FE1EEC
0055E4BA 6A 00                   push 0
0055E4BC 68 90 E5 55 00          push 0x0055E590
0055E4C1 E8 EA 70 19 00          call 0x006F55B0
0055E4CE E8 1D 73 19 00          call 0x006F57F0
```
`0x0055E4F0`：
```asm
0055E508 C7 05 28 1F FE 00 10 5D 5F 00
           mov [0x00FE1F28],0x005F5D10
0055E548 68 D0 A5 D6 00          push 0x00D6A5D0
0055E54D E8 BE 6F 19 00          call 0x006F5510
0055E559 68 20 E6 55 00          push 0x0055E620
0055E55E E8 4D 70 19 00          call 0x006F55B0
0055E56B E8 80 72 19 00          call 0x006F57F0
```

`0x006F57F0` frozen 偽碼顯示 16-byte slot 值搬移／upvalue-like 寫入／stack cursor 回退 `0x20`。此點尚未完整 BIN 複核，留待下一輪，不能逕稱 `Rebind` 的 table pointer 已被真正替換。

## 5. 分級結論與下一步

**已確認**：Rebind native callback 本體 `0x0055E590`；`0x00FE1F24` 至少兩個 writer；`0x00FE1F28` 的初始化 writer；`0x0055E620` 的間接 call 與固定回傳值；預設 handler `0x005F5D10` 只做 `ret`。

**合理推測**：這是一組 script/runtime 中的「重綁控制值」與「可替換的 delete-handler 轉接點」；因尚未列舉所有 writer、入口參數、資料消費者，不可確認完整 runtime lifecycle。

**尚待驗證**：`0x00FE1F28` 所有 xrefs、runtime 是否替換 handler；`0x004A2BB0` 全 CFG；`0x006F57F0` closure upvalue 邏輯；72 個名字是否確實由其他函式更新其 table value；腳本呼叫路徑與動態驗收。

**Client 待逆向**：上述 handler writer/callers 與 runtime 入口。  
**Server 待開發**：沒有本段證據導出新的 wire contract。  
**跨功能待整合**：Script、對話、場景、物件模組可引用 VA 與讀寫點，但不得將名稱當成已完成的功能。  
**待遊玩驗證**：未執行 client。  
**FULL-PASS**：仍由 T01 精確主張裁決，本段僅 PARTIAL。

第 1 輪已確認先前偽碼缺漏的實際原生 callback 與具體 writer/indirect call，達到重大新發現；第 2／3 輪未啟動。bulk 全量 `index → functions → raw` 111,054 筆完整性檢查仍阻塞於缺完整 checkout。
