# KR Bulk 集中品質檢查 — 第十三段：72 組 Closure/字串鍵寫入鏈的原生驗證（2026-10-29）

**PARTIAL / BIN-FIRST BOUNDED CHAIN / NOT FULL-PASS**

## 1. 來源版本

- 一手原件：`Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE32 x86，ImageBase `0x00400000`，`.text` RVA `0x1000`、raw `0x400`，故這些 `.text` 位址的 raw offset = VA − `0x00400C00`。
- 以 `objdump -D -b binary -m i386 -M intel --adjust-vma=VA` 對原件局部 bytes 反組譯，並與 GitHub frozen 偽碼比對。未執行遊戲。
- 原始偽碼 blob（全部由 GitHub `extra/roy2` 讀取）：`0x6f55b0`=`27a10426a1f267d2debd27c7b424558906f10980`；`0x6f5790`=`6967fa4070eb5435b82ef86377a0c62b61e2fd67`；`0x55e410`=`9af7ebf38355f16bc52b5f4545710efcf5afdd45`；`0x55e4f0`=`6592b7b2bf0fdce5e796f4141ca71893f2950142`。
- 額外讀取下游偽碼：`0x6f50f0`=`cce73b40695d9209bb5bd6c0af6f85d1fc43d129`；`0x6fec70`=`b76dad8daa34d709900d3d86e2dde2920e1ae781`；`0x6fb9a0`=`52085cd4ce81b6be11952b235e9c2bdd4ff24231`；`0x6f5510`=`4f54bf59f7b0a993a33508df0378d1f1f11bae9a`。其中後四者尚未於本段全部做完整 machine-code CFG 驗證，必須降級標註。

## 2. 本次已用原始 BIN 確認的 callee 行為

### 2.1 `0x006F55B0` — 建立 type 6 值並推入虛擬機／解譯器樣式的堆疊

入口 `VA 0x006F55B0`，raw `0x002F49B0`。原始指令可見：
```asm
006F55B3 mov eax,[esi+0x10]
006F55B6 mov ecx,[eax+0x44]
006F55BE cmp ecx,[eax+0x40]
006F55C1 jb  0x006F55CA
006F55C5 call 0x006FB3A0         ; capacity/fallback branch, semantic TBD
006F55DF mov edi,ebx
006F55E1 shl edi,4                ; param_2 * 16
006F55E4 lea eax,[edi+0x18]      ; allocation size
006F55F0 call 0x00700880
006F55FB mov [eax],edx
006F5600 mov [ecx+0x1c],eax
006F560C mov ecx,[ebp+8]
006F560F mov byte ptr [eax+4],6
006F5613 mov byte ptr [eax+6],1
006F5617 mov [eax+0xc],edx
006F561A mov [eax+0x7],bl
006F561D mov [eax+0x10],ecx
006F5620 sub [esi+0x8],edi
006F5661 mov ecx,[esi+0x8]
006F5665 mov [ecx],eax
006F5667 mov dword ptr [ecx+8],6
006F566E add dword ptr [esi+8],0x10
006F5674 ret
```
為避免上面中間省略式混淆，關鍵原生欄位寫入精確位址：
- `0x006F560F: C6 40 04 06` → `[eax+4]=6`（byte）
- `0x006F5613: C6 40 06 01` → `[eax+6]=1`（byte）
- `0x006F5617: 89 50 0C` → `[eax+0x0c]=edx`（dword）
- `0x006F561A: 88 58 07` → `[eax+7]=bl`（byte）
- `0x006F561D: 89 48 10` → `[eax+0x10]=ecx`（dword）
- `0x006F5667: C7 41 08 06 00 00 00` → `[[esi+8]+8]=6`（dword）。

**原生可確定**：透過 `ESI` 管理的狀態物件，為 closure-like 記錄配置 `0x18 + 0x10*param_2` bytes，保存指標／upvalue 數／類型 6，並將 16-byte stack slot 的寫入游標前移 `0x10`。稱為「closure-like」是依據結構的操作型態，不是來自原版符號名。`ESI` 為**非顯式傳入的暫存器狀態**，不可按一般 cdecl 的二參數函式理解。

### 2.2 `0x006F5790` — 使用 EDI 所指的 NUL 字串進行一個表寫入鏈

入口 raw `0x002F4B90`。原生指令：
```asm
006F579A mov ecx,esi
006F579C call 0x006F50F0
006F57A3 mov eax,edi
006F57A8 mov cl,[eax]
006F57AB test cl,cl
006F57AD jne 0x006F57A8      ; 掃描 NUL 字元
006F57B1 push eax           ; length
006F57B2 push edi           ; bytes
006F57B3 push esi           ; state
006F57B4 call 0x006FEC70
006F57BD mov eax,[esi+8]
006F57C3 sub eax,0x10
006F57D6 call 0x006FB9A0
006F57DE add dword ptr [esi+8],-0x10
006F57E6 ret
```

**原生可確定**：`EDI` 為字串鍵指標（由 `strlen` 型態的逐 byte 掃描確認）；`0x006FEC70` 接受 state、字串及長度；`0x006FB9A0` 隨後消費被選定的 stack slot、字串值及其他記錄，完成之後 `[esi+8]` 回退 `0x10`。實際資料結構比較類似 script table 的 key/value set，但尚未用該執行時符號或完整 native CFG 作正式名稱驗證。

### 2.3 caller / callee 拼接與上段 72 組關係

前段 `0x0055D7E0` 反覆執行：
```asm
0055D7EE push 0
0055D7F0 push 0x008DC2F0
0055D7F7 call 0x006F55B0
0055D7FE mov edi,0x00C1027C
0055D803 mov eax,0xFFFFD8EE
0055D808 call 0x006F5790
```
上段已在 BIN 確認兩 callee 分別各 72 次，72 個不同 EDI 常數。本段補足 callee 的資料消費方式：**每組把一個特定函式地址（如 `0x008DC2F0`）封裝成 type 6 closure-like value，並以 EDI 指向的字串鍵交由表操作路徑處理**。這不再只是「重複呼叫」現象，而是帶有 key/value 語意的有界 native chain。

## 3. 尾端交接處理

### `0x0055E410`（raw `0x0015D810`）

BIN 證據：
```asm
0055E422 mov [0x00FE1F20],ebx
0055E428 mov dword ptr [0x00FE1F24],0x00FE1EEC
0055E446 call 0x006F99A0
0055E44D mov dword ptr [edi+8],5
0055E454 add dword ptr [esi+8],0x10
0055E45D mov edi,0x00C10604
0055E467 call 0x006F5790
0055E473 call 0x006F5680
0055E48C cmp dword ptr [eax+8],5
0055E4BA push 0
0055E4BC push 0x0055E590
0055E4C1 call 0x006F55B0
0055E4CE call 0x006F57F0
0055E4E0 mov dword ptr [eax],0x00C10604
0055E4E9 ret
```
原始機器碼確認全域 `0x00FE1F20`、`0x00FE1F24` 的寫入，type 5 stack record，以及 `0x0055E590` callback-like target 的 closure-like 建立。GitHub 偽碼提到 `Rebind`，僅可作字串／功能候選名，不可直接視為完整行為。

### `0x0055E4F0`（raw `0x0015D8F0`）

```asm
0055E4F7 mov ebx,[0x00FE1F20]
0055E508 mov dword ptr [0x00FE1F28],0x005F5D10
0055E512 call 0x006F5680
0055E526 cmp dword ptr [eax+8],5
0055E548 push 0x00D6A5D0
0055E54D call 0x006F5510
0055E559 push 0x0055E620
0055E55E call 0x006F55B0
0055E56B call 0x006F57F0
0055E57B add dword ptr [eax+8],-0x10
0055E586 ret 4
```
原生可確定第二個全域 writer `0x00FE1F28` 與回呼地址 `0x0055E620` 的傳入，以及另一個字串型操作函式 `0x006F5510`。GitHub 偽碼包含 `DeleteAllObject`、`Error UseTable` 字串，這是功能性線索，仍未足以驗收所有 script 調用語意。

## 4. 下游結構解讀：明確降級的推測

- `0x006F50F0` GitHub 偽碼顯示 stack index `*0x10` 與不同負索引的地址映射；屬「類似 VM 值選取」強烈線索，尚未完成 native CFG。
- `0x006FEC70` 偽碼以 byte string/length 做 hash、bucket 比對與插入；「字串 key intern」為強烈推論，需完整 BIN 驗證。
- `0x006FB9A0` 偽碼含 table-like slot type 5、值複製、錯誤字串 `table index is nil`、`loop in settable`；「settable」為優勢推論但不應自行命名原版 API。
- `0x006F5510` 偽碼向 16-byte stack slot 寫入 type 4；很可能是 push string，但本段未逐項反組譯。

## 5. 待辦與責任界線

**Client 待逆向**：72 個 EDI 字串的實際內容、各 closure 函式 pointer 的完整清單與用途、`0x008DC2F0` 原生 body、`0x006FEC70/0x006FB9A0` 的完整 CFG，以及 `0x00FE1EF0` 的初始化與壽命。

**Server 待開發**：本段尚未抽出任何 Server wire contract，不據此增列任何 Server 實作義務。

**跨功能待整合**：本段原生 key/value 封裝結果可供 Script／UI／狀態模組 Task 依 VA 查詢，但不可自動改寫其原稿。

**待遊玩驗證**：沒有執行遊戲，也沒有動態 Lua／script API 驗證。

**FULL-PASS**：T01 精確主張審核前一律 PARTIAL。此函式鏈與 bulk 檔案全量 111,054 筆保存一致性為不同問題；後者本環境仍無完整 checkout。

## 6. 研究輪次與停止理由

第一輪已取得相較上一段的重大新證據：兩個關鍵 callee 的實際 native 構建／字串消費與 stack slot 操作；尾端 writer 亦定位為有界指令。按共用規範，本段第 2／3 輪未啟動。下一段應從 72 個 EDI 字串及 `0x008DC2F0` 實際 callback 的原件指令推進，而非重複枚舉 call 次數。
