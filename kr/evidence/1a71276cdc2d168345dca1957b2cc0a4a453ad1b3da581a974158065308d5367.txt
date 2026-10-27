# T08-149 — 候選 Host constructor caller 與 B entry vtable ABI 反證檢查

- Task：T08；研究者：`chatgpt-web roy`
- 分析時間：2026-10-27 22:29:34 CST（Asia/Taipei）
- 狀態：**T08-149 本地原稿，未 Commit/Push**
- 第一手資料：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本次已本機核算）；參照 T08-145～148 的接棒敘述（歷史背景而非新直接證據）。
- 映射：BIN 的 `.text` 調查使用 `offset=VA-0x00401000`；`.rdata` 使用 `offset=VA-0x00BD2000+0x007D0600`。本次以這兩套映射獨立讀取位元組。此 BIN 非直接以 EXE PE raw mapping 讀 `.text`。
- 工具：本機 Python 位元組讀取及 GNU `objdump -D -b binary -mi386 -M intel --adjust-vma`；未執行遊戲／未下動態斷點。

## 一、這一段新取得的直接證據

### 1. `0x007A5050` 的上游：三個直接 CALL，且各有 `0x170` bytes 配置

以 BIN 的 `.text` 線性映射掃描 x86 `E8 rel32`，並逐一確認目標絕對位址：

| call VA | 上游配置／參數 | 目標 |
|---|---|---|
| `0x004C825D` | `0x004C823F push 0x170; 0x004C8244 call 0x00891668`；`0x004C8258 movzx ecx,si; push ecx; 0x004C825C push eax` | `0x007A5050` |
| `0x004C850F` | `0x004C84EF push 0x170; 0x004C84F4 call 0x00891668`；`0x004C850A movzx ecx,bx; push ecx; 0x004C850E push eax` | `0x007A5050` |
| `0x006DC3EA` | `0x006DC3CD push 0x170; 0x006DC3D2 call 0x00891668`；`0x006DC3E8 push edi; 0x006DC3E9 push eax` | `0x007A5050` |

該函式進入時：

```asm
007A5077  mov esi, [ebp+08h]        ; 物件儲存地址（非 thiscall ECX）
007A507F  mov dword ptr [esi+04h], 00C4F64Ch
007A5086  mov dword ptr [esi+08h], 00C0F878h
007A508D  mov dword ptr [esi+0Ch], 00C4F66Ch
007A509E  mov eax, [ebp+0Ch]        ; 第二參數
007A50A5  mov dword ptr [esi], 00C4F67Ch
007A50AB  mov dword ptr [esi+04h], 00C4F690h
007A50B2  mov dword ptr [esi+08h], 00C4F6B0h
007A50B9  mov dword ptr [esi+0Ch], 00C4F6C0h
007A50C0  mov [esi+18h], eax
007A50C3  mov [esi+1Ch], ebx
007A50D0  call 007A5420h
```

**已確認**：至少上述三個建立站點會分配 `0x170` bytes，傳入物件指標與另一個參數，由 `0x007A5050` 初始化 `+0x0C` embedded vptr。由上游接著呼叫 `0x004CA860` 及 `0x004E1360`（三路中已檢視的共同模式），可知該新物件還會交給外部 wrapper／登記流程；**尚無完整證據**解釋該 wrapper 的語義、被回收時機、或如何流到 B producer。

### 2. `0x007A67C0` 對應 Host 的條件與 B entry pointer 本身

```asm
007A67E8  mov edi,ecx               ; producer 的 Host 來自 thiscall ECX
007A67ED  cmp dword ptr [edi+1Ch],0
007A67F7  cmp dword ptr [edi+124h],0
007A6804  cmp dword ptr [edi+0ACh],0
007A6827  mov ecx,[edi+70h]
...
007A69BE  cmp dword ptr [edi+8Ch],0
007A69D9  mov esi,[00FBA838h]
007A69DF  mov eax,[esi+0B8h]
007A69E5  add edi,0Ch               ; entry = Host + 0x0C
007A69EB  mov [ebp-14h],edi
...
007A6A2E  mov [eax],ecx             ; 特殊重疊情況的 append
007A6A4F  mov [eax],edi             ; 一般 append
007A6A51  add dword ptr [esi+0B8h],4
```

**已確認**：B entry 是 Host `+0x0C` 的地址，非複製出來的新 entry；B vector 為 `manager+0xB4/B8/BC`。`0x007A67C0` 的入口使用 **ECX=this**，與 constructor 的**兩個 stack arguments**屬不同呼叫規約，並不矛盾，但也**不能用 offset 類似當作身分證據**。

**新增重要負證據**：在此 BIN 線性程式碼候選區（前 `0x7D0000` 個 bytes）掃描 `E8 rel32`（direct call）、`E9 rel32`（near jump）、`68 imm32`（push target）與 `B8 imm32`（mov eax,target），沒有指向 `0x007A67C0` 的命中；掃描原始 4-byte 值 `C0 67 7A 00` 在**整個 BIN**亦無命中。這意味著不能只靠直接 xref 找上游，需追 virtual call／register-computed target、其他間接 dispatch 或確認這段是否實際可達。掃描的 opcode pattern 有解碼邊界與指令編碼覆蓋限制；**不能由此判定函式不可達**。

### 3. `0x00C4F6C0` vtable 內容有實際 ABI 不一致

採 `.rdata` 映射，`0x00C4F6C0 -> BIN file offset 0x0084DCC0`，逐 DWORD 如下：

| VA | 資料 DWORD | 判定 |
|---|---|---|
| `0x00C4F6C0` | `0x007AAA90` | `+0`，未在本段證實語義 |
| `0x00C4F6C4` | `0x007A8310` | `+4`，落在 `0x007A8300` 的函式序言**中段** |
| `0x00C4F6C8` | `0x007A8E10` | `+8`，落在 x87 指令**立即位元組／位址欄位中段** |
| `0x00C4F6CC` | `0x00C7F9F4` | `+0C`，可能是 RTTI metadata／下一個表界，尚未確認 |

對照真實指令邊界：

```asm
007A8300  push ebp
007A8301  mov ebp,esp
007A8303  sub esp,4Ch
007A8306  mov eax,[00D61F20h]
007A830B  xor eax,ebp
007A830D  mov [ebp-08h],eax
007A8310  cmp dword ptr [edi+0ACh],0    ; 中段而非正常函式入口
...
007A8E0D  fld dword ptr [ebx+0D8h]     ; 指令跨過 0x007A8E10
007A8E13  fcompp
```

`0x007A8E10` 實際原始 bytes 自該點開始是 `00 00 00 DE ...`，是**從既有 fld 指令的 displacement 中間切入**，不可直接宣稱為可呼叫 C++ 虛擬方法入口。`0x007A8310` 若獨立呼叫會跳過 EBP stack frame 建立及 security-cookie 初始化；因此同樣不能把它直接定名為合法 execute function。雖然這些 DWORD 在資料中真實存在，**它們作為實際 B execute／score slot 的解讀遭遇強烈反證**；仍應留意 VA/重定位、表佈局、code vs data 對應等根因，而非自行強制修正地址。

### 4. consumer 的實際 ABI 用法（供下一段與真正 vptr 對位）

```asm
007BB6F0  mov ecx,[esi+0B4h]         ; vector begin
007BB6F6  mov ecx,[ecx+edi*4]        ; ECX = embedded entry pointer
007BB6F9  mov edx,[ecx]              ; EDX = entry.vptr
007BB6FB  mov eax,[edx+04h]          ; slot +4 = execute
007BB6FE  call eax                   ; this = ECX；無額外 push
```

`slot+4` 必須能以 entry 指標為 ECX 的方式、直接被呼叫；若真是 `0x007A8310`，會與其所需的 EBP stack frame 不一致。因此 **候選 vptr `0x00C4F6C0` 尚不能被歸類為實際被消費的 B entry 型別**，除非有新的 pointer-time 證據或映射修正。

## 二、暫定資料流與偽碼

```cpp
// [已驗證骨架，型別名稱皆暫定]
void* createCandidate(unsigned id) {
    void* host = allocate(0x170);             // 0x00891668
    if (host) construct_007A5050(host, id);  // 三組 caller
    return host;                              // 後續交給 wrapper/登記流程
}

void maybeAppendB(Host* host /* ECX */) {
    if (!host->field_1C || !host->field_124) return;
    // 其他條件、迭代與呼叫見 0x007A67C0 ~ 0x007A69BE
    if (host->field_8C) {
        auto *manager = *(Manager**)0x00FBA838;
        auto *entry = (char*)host + 0x0C;
        appendWithOverlapGuard(manager->B, entry);
    }
}

void consumeB(Manager* m) {
    // 省略排序、上限及其他操作
    for (Entry* p : selectedEntries) {
        // 真正動態 entry->vptr 尚未確認是哪一張表！
        p->vptr->slot_04(p); // ECX=p, indirect CALL, no stack args
    }
}
```

## 三、與前段關係及結論分級

**已確認（本次機器碼）**
1. `0x007A5050` 有 3 個直接建構入口，3 個上游都分配 `0x170`；物件初始化會向 `+0x0C` 寫入 `0x00C4F6C0`。
2. `0x007A67C0` 的入列指標是 `ECX+0x0C`，而 consumer 對此 entry 依 `vptr+0x04` 直接進行 ECX-based 間接呼叫。
3. 表資料 `0x00C4F6C0` 的 `+4/+8` DWORD 雖可直接讀出，指向的位址在此 BIN 中分別落在已反組譯函式與 x87 指令內部；不可僅依 DWORD 當作執行入口。

**合理推測**
1. `0x007A5050` 建構的是一種可能被其他系統管理或註冊的 Host 類物件；offset 與 producer guards 相符，但未閉合 owner 身分。
2. 真正的 B producer 可能透過非 direct-call 途徑觸發 `0x007A67C0`，或候選函式的參照／反組譯界線仍需對照 Ghidra 原稿；僅是調查方向。

**未證實／不得聲稱**
1. 任一上述三個 allocated object 在運行時必然呼叫 `0x007A67C0`。
2. 消費時 entry vptr 一定等於 `0x00C4F6C0`，以及 slot `0x007A8310 / 0x007A8E10` 是有效 execute/score。
3. B execute 會直接填入全域 `[0x00FB7740]` 22 桶；或已存在 use-after-free。
4. 此段沒有完成動態斷點驗證；也沒有宣稱 GitHub 已更新。

## 四、下一步精準路線（T08-150）

1. 從三條 caller 的 `0x004CA860 / 0x004E1360` 後續 wrapper 資料流一路追到 Host 動態調用／析構；搜尋是否把指標送入能 dispatch `0x007A67C0` 的所有者。
2. 對 `0x007A67C0` 用 Ghidra function/raw 覆核真正 incoming references（包含 virtual、thunk、jump table），並就本次沒有 direct xref 的現象做解釋；以 BIN 驗證關鍵段。
3. 查 `0x00C4F6C0` 表的 section bytes 與 PE header / relocation 是否吻合；釐清 `0x007A8310` 與 `0x007A8E10` 為何指入函式中段。勿以看似合理的反編譯命名取代原始地址。
4. 若後續具動態測試條件，**尚未執行**：在 `0x007A69E5` 記 Host ECX、`Host+0x0C` 的實際 DWORD；在 `0x007BB6F6` 記入列 entry 與實際 vptr、`[vptr+4]`；在 `0x007BB6FE` 驗證其 call target；僅在觀測到有效 code pointer 後追到後續 22 桶寫入者。

## 五、研究環境及掃描限制

- 機器碼定點反組譯取自與 hash 相符之 BIN，不是以記憶或筆記捏造。
- 前述 `E8/E9/68/B8` 全位元組掃描是 pattern 掃描，不是控制流完整分析；對間接呼叫、其他寄存器上的 immediate、不同指令編碼及外部掛載程式無覆蓋能力。
- `.rdata` `0x00C4F6C0` 地址在 BIN 的讀值可再現，但本次沒有完整重建此 EXE 的 PE 重定位行為；所以 ABI 矛盾是待釐清的強反證，並非已證明『表是假的』。