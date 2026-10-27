# T08-152 — B entry / control-block vtable 槽位入口邊界、交叉參照與身分鏈負證據

- Task：T08；研究者：`chatgpt-web roy`
- 研究日期：2026-10-27（Asia/Taipei）；檔名時間 22:54 為本段筆記建立時間標識。
- 來源：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本段重算）。
- 工具：GNU `objdump -D -b binary -mi386 -M intel`、Python `struct`/byte search；未執行客戶端，無執行時斷點驗證。
- `.text` 的這份 BIN 分析換算：`BIN offset = VA - 0x00401000`；`.rdata`：`BIN offset = VA - 0x00BD2000 + 0x007D0600`。**這兩式只適用於所述區域**，切勿將 `.text` 線性映射套到資料節。
- 上游原稿：T08-145～151；其中 T08-149 已提出 `0x00C4F6C0` 入口矛盾，T08-151 已提出控制區塊 `0x00C0760C` 矛盾。本段專門將地址、原始 bytes、指令邊界和全 BIN 常數出現位置交叉整理，並避免將疑點誤判為合法函式。

## 1. 新增結論與明確限制

1. `0x00C4F6C0` 候選 embedded vtable 的 `+0x04=0x007A8310` 指向既有 `0x007A8300` 函式 prologue **之後**；`+0x08=0x007A8E10` 位在 x87 `fld [ebx+0xD8]` 指令的 32-bit displacement 內。後者若以正常指令邊界執行，完全不會從 `0x007A8E10` 開始。
2. `0x00C0760C` 控制區塊候選表的 `+0x00=0x004CA660` 落在一段既有樹結構操作控制流程中；`+0x04=0x007A3920` 是 `0x007A391F: add esp,4` 三 byte 指令的中間位址（落於立即數 `04` 前／指令後兩 bytes），不是從已知 prologue 起始。
3. 原始 BIN 的 DWORD exact-match 掃描：`0x007A67C0` **零個**，`0x007A8310` **一個**（file offset `0x0084DCC4`），`0x007A8E10` **一個**（`0x0084DCC8`）；`0x007A3920` **七個**（`0x008016DC,0x00805C10,0x0080B538,0x0084DB64,0x0084DB78,0x0084DCD4,0x0084DCE8`）。這是 **raw DWORD** 命中，不等同已解碼的 code xref；不能由零命中宣稱 `0x007A67C0` 必定不可達。
4. `0x00C4F6C0` 地址常數僅有兩處原始 DWORD 命中（`0x003A40BC`, `0x003A4602`），與先前確認的同一 Host `+0x0C` constructor vptr 改寫相容；但**只證明建構流程寫入這個表，不證明 B consumer 的執行時 entry 會使用它**。
5. `0x00C0760C` 在 BIN 中只有一處 raw DWORD 命中（`0x000C98AC`），符合先前所述控制區塊建構流程中寫入表地址的個案；不證明表中兩目標為正確可呼叫 code entry。

## 2. `.rdata` DWORD 實際表格（逐項用 `struct.unpack_from('<I', BIN, offset)`）

`0x00C4F6C0` 換算 `0x0084DCC0`：

| slot | DWORD | 判定 |
|---|---|---|
| `+00` | `0x007AAA90` | 入口語義未確認 |
| `+04` | `0x007A8310` | 非 `0x007A8300` 正常 prologue；落在內部 |
| `+08` | `0x007A8E10` | 位於 `fld` displacement |
| `+0C` | `0x00C7F9F4` | 不應未經檢查繼續視為同一方法表 |
| `+10` | `0x007AAA40` | 下一個候選結構的槽位；不可跨表直接解讀 |
| `+14` | `0x007A3920` | 同一可疑目標亦出現在其他資料表 |

`0x00C0760C` 換算 `0x00805C0C`：

| slot | DWORD | 判定 |
|---|---|---|
| `+00` | `0x004CA660` | 落在既有樹操作流程內；暫不命名析構方法 |
| `+04` | `0x007A3920` | 非函式起始，屬 ABI／映射待解矛盾 |
| `+08` | `0x007A3950` | 亦位於既有執行區塊內，勿當確定第三槽 |
| `+0C` | `0x007848C0` | 表界不明 |

控制區塊 `+04` 與候選 embedded vtable 後續資料都出現 `0x007A3920`，但這只支持它在資料中的**複用**，不支持「兩類物件具相同生命週期函式」的語義；不同 vtable 的方法欄位大小、subobject offsets 仍需分別驗證。

## 3. BIN 指令邊界實證

```asm
; 0x007A8300 附近：欄位檢查位於正常 prologue 之後
007A8300  push ebp
007A8301  mov ebp,esp
007A8303  sub esp,4Ch
007A8306  mov eax,[00D61F20h]
007A830B  xor eax,ebp
007A830D  mov [ebp-08h],eax
007A8310  cmp dword ptr [edi+0ACh],0

; 0x007A8E10 屬於前述 fld displacement，中途切入並非有效線性入口
007A8E07  d9 9b b4 00 00 00    fstp dword ptr [ebx+0B4h]
007A8E0D  d9 83 d8 00 00 00    fld dword ptr [ebx+0D8h]
007A8E13  de d9                fcompp
007A8E15  df e0                fnstsw ax

; 0x007A3920：由 0x007A391F 延續，而非獨立入口
007A391D  33 d2                xor edx,edx
007A391F  83 c4 04             add esp,04h
007A3922  3b c2                cmp eax,edx
007A3924  74 2e                je 007A3954
007A3926  8b 4e 04             mov ecx,[esi+04h]
```

注意：`0x004CA660` 周邊反組譯也位於使用 ESI/EDI/樹節點的迴圈；與正常控制區塊 release 函式預期使用 ECX 作 this 的呼叫慣例不一致。然而在尚未取得準確的執行時 vptr、修正映射或刻意混淆機制前，不應直接宣稱 table 資料錯誤或有惡意改寫。

## 4. 與既有 B Queue 操作的控制／資料流對照

先前已核實的 producer / consumer 對照：

```asm
; B producer 0x007A67C0
007A67C0  push ebp
007A67C1  mov ebp,esp
007A67E8  mov edi,ecx            ; EDI = Host this
007A67ED  cmp dword ptr [edi+1Ch],0
007A67F7  cmp dword ptr [edi+124h],0
; ... 0x007A69E5 取 Host+0Ch，0x007A6A51 將 B.end 推進

; B consumer 0x007BB640
007BB6F6  mov ecx,[ecx+edi*4]   ; ECX = embedded entry pointer
007BB6F9  mov edx,[ecx]         ; entry.vptr
007BB6FB  mov eax,[edx+04h]    ; execute slot
007BB6FE  call eax              ; call 前 ECX=embedded entry
```

這裏 B consumer 使用 `ECX = Host+0x0C` 子物件；即使 constructor `0x007A5050` 寫入 `Host+0x0C` vptr，也仍須沿實際 producer `ECX` 起點追到 construction/control block 才能閉合型別。特別是若表中的 `0x007A8310` 確為執行時 execute，該位址按正常 x86 decode 並無自行建立 EBP、security cookie 的必要 prologue；這與直接以 `call eax` 進入的假設衝突。**衝突尚未解決，不能將候選 constructor 動態型別當成已證實。**

## 5. C++ 層級偽碼：已知與未知分開

```cpp
// Verified consumer shape (object semantics remain provisional)
for (size_t i = 0; i < selectedBEntries; ++i) {
    Entry* e = bVector[i];  // producer stores Host + 0x0C
    e->vptr[1](e);          // ECX=e; virtual slot +0x04
}

// Candidate construction only, NOT verified as the same runtime Entry type
void CandidateHostCtor(Host* host) {
    host->embeddedVptr = reinterpret_cast<void*>(0x00C4F6C0);
    // other fields, and later lifetime-specific vptr rewrites
}

// Hypothesis needing proof, not current conclusion:
// runtimeHost->embeddedVptr == 0x00C4F6C0 at B append/consume time
```

## 6. 反證與不能跳過的限制

- full BIN raw byte value 0 hits 並不排除 PC-relative、指令運算、DLL 轉跳、註冊後間接呼叫或資料被轉換的方式；目前仍**無法判定 `0x007A67C0` 的真實 caller**。
- 機器碼不對齊除了錯誤 table 解讀，也可能涉及 address-map 混用、反組譯來源並非同一版本、不同 RVA/VA 基準、函式指標值需偏移修正等；本段**沒有證明**任何單一根因。
- B vector 存入 embedded entry 且沒有明顯 retain，不等於已實證 use-after-free。T08-150/151 已發現引用控制區塊與 Host 的 holder 生存路徑，但尚未與 B append、執行及清理時序閉合。
- 未實際執行遊戲、未動態觀測 allocator、控制區塊、B entry 虛擬呼叫；所有 runtime type 都維持假設。

## 7. 下一段 T08-153 可驗證的工作

1. 統一核對 EXE PE headers／BIN 生成方式與 `.text`、`.rdata` 真正的 VA 映射；優先檢查同一程式碼函式是否有全局性地址偏移，不可對個別 vtable slot 私自補正。
2. 反向追查 `0x007A67C0` 的 vtable 或 registration path，探索非 4-byte 明文字值 xref；以 `0x007A67E8` 的 ECX/EDI 與 producer guards 為切入點。
3. 從 `owner+0x15C` 已確認的 host path 追間接更新 call target，對比實際 Host+0x0C embedded vptr 是否可能被額外改寫。
4. **尚未執行的** dynamic breakpoint 建議：`0x007A69E5` 觀察 Host / entry.vptr、`0x007A6A51` 觀察 manager B append、`0x007BB6F6` 比對 entry 指標與 vtable、`0x007BB6FE` call target 和 ECX、`0x007A5A51` 驗證候選析構中的 vptr 恢復。實際下斷點之前需重新確認載入基址／ASLR。
5. 若能證明執行時 vptr 與 `.rdata` 靜態資料不一致，必須追查修改者與時機；若一致則需專項調查 BIN map／指標有效性，不直接宣稱 C++ method resolved。

## 8. GitHub 狀態

本段原稿供 GitHub `kr-temp-roy/` 保存。提交與驗證結果需在實際 connector 動作完成後回填對話；文件本身不預先聲稱已成功 Push。另 T08-149～151 為不同完整原稿，不得用此文代替。