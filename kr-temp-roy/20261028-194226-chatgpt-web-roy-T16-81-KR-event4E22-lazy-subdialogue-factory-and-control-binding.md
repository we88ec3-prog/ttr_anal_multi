# KR T16-81 — Quest UI 事件 0x4E22 的延遲子物件配置、建構與控制項綁定

> 本檔為 T16-81 原生 BIN 證據完整版 GitHub 存檔；研究者 chatgpt-web roy，2026-10-28 19:42:26 Asia/Taipei。KR only。

## 來源、版本及方法
- 唯讀 /mnt/data/Tartaros.bin，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- Tartaros.exe SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 由 hashlib 與 objdump -d -Mintel 重新核對原始 BIN；PE32 x86，.text VA 0x00401000/raw 0x400/size 0x7D01F0；本段全部列出的函式 raw = VA - 0x00400C00。不同 PE 節不共用映射。
- 沒有執行、附加或修改 Client；沒有原始封包流量，也沒有 Server 原件。本段只做 KR T16，T02/T07/T14/T15 的主責保留。
- 上一段 T16-80 已確認 0x62E380 控件綁定；本段處理 0x62E360 的事件分派，檢查是否真的發送 Quest 接取封包。

## 1. 第 1 輪 T16-81：新的有限、完整原生功能鏈

### 1.1 0x62E360 事件入口
原生機器碼：`cmp DWORD PTR [ebp+8],0x4e22`，不符即返回；符合時 `lea esi,[ebp+8]; call 0x6306f0`。本函式最後 `ret 0xc`。此時 ESI 指向事件函式的原始 stack arguments，不是指向 CQuestListDlg 或 Quest cache。因而下游的 `[esi+4]` 和 `[esi+8]` 分別是第二、第三個堆疊參數，不能誤解成 UI 成員偏移。
已確認 event numeric `0x4E22`，但未確認它是 accept button；它與 T16-80 child ID `0x4E20` 不是可直接互換的值，亦非網路 opcode。

### 1.2 0x6306F0 的分支與 0x254 配置
```asm
630713: 8b 46 08           mov eax,DWORD PTR [esi+0x8]
630716: 85 c0              test eax,eax
630718: 74 7c              je 0x630796
63071a: 83 38 00           cmp DWORD PTR [eax],0x0
63071d: 75 63              jne 0x630782
63071f: 81 7e 04 2d 01 00 00 cmp DWORD PTR [esi+0x4],0x12d
630726: 74 0e              je 0x630736
630728: 6a 00              push 0x0
63072a: 68 c0 1f bf 00     push 0xbf1fc0
63072f: 68 78 20 bf 00     push 0xbf2078
630736: 68 54 02 00 00     push 0x254
63073b: e8 28 19 26 00     call 0x892068
630740: 83 c4 04           add esp,0x4
630743: 89 45 f0           mov DWORD PTR [ebp-0x10],eax
63074d: 85 c0              test eax,eax
63074f: 74 1b              je 0x63076c
630751: 8b c8              mov ecx,eax
630753: e8 78 02 00 00     call 0x6309d0
630758: 8b 4e 08           mov ecx,DWORD PTR [esi+0x8]
63075b: 89 01              mov DWORD PTR [ecx],eax
63076c: 8b 4e 08           mov ecx,DWORD PTR [esi+0x8]
63076f: 33 c0              xor eax,eax
630771: 89 01              mov DWORD PTR [ecx],eax
630782: 6a 00              push 0x0
630784: 68 c0 1f bf 00     push 0xbf1fc0
630789: 68 c8 20 bf 00     push 0xbf20c8
630790: ff 15 80 25 bd 00 call DWORD PTR ds:0xbd2580
```
CFG：`slot=[esi+8]` 若為 null 則直接返回；已存在 object 時走診斷分支；尚未建立而 `[esi+4]!=0x12D` 走錯誤／診斷；符合時配置 0x254 (596) bytes，成功後以 0x6309D0 建構並寫回 *slot；配置失敗寫回 null。這是 **type-gated lazy UI factory**；其 slot 不能當作封包或 Quest state writer。

### 1.3 0x6309D0 新物件 constructor 與雙 vptr
```asm
6309f5: 8b f1                 mov esi,ecx
6309fa: e8 81 3e 12 00       call 0x754880
630a01: 8d 86 5c 01 00 00    lea eax,[esi+0x15c]
630a0a: 50                   push eax
630a0b: c7 06 dc 67 c4 00    mov DWORD PTR [esi],0xc467dc
630a11: e8 0a ab 14 00       call 0x77b520
630a16: c6 86 58 01 00 00 01 mov BYTE PTR [esi+0x158],0x1
630a1d: c7 06 ac db c2 00    mov DWORD PTR [esi],0xc2dbac
630a23: 89 be 48 02 00 00    mov DWORD PTR [esi+0x248],edi
630a29: 89 be 4c 02 00 00    mov DWORD PTR [esi+0x24c],edi
630a2f: 89 be 50 02 00 00    mov DWORD PTR [esi+0x250],edi
630a35: 8b c6                 mov eax,esi
```
ECX=this，初始化父層（0x754880 尚未確認具體 C++ 類名）；先寫中間 vptr 0xC467DC，透過 0x77B520 初始化 this+0x15C 的內嵌成員；this+0x158 設定 byte 1；覆寫為最終 vptr **0x00C2DBAC**；三個 pointer slots (+0x248/+0x24C/+0x250) 清零，最後 return this。最終 vptr 的類別名需 RTTI 或符號另驗，不能以 T16 前述 Quest dialog 名稱直接強制命名。

### 1.4 0x630A50 子 UI 控件三欄位綁定
```asm
630a55: 8d be 48 02 00 00 lea edi,[esi+0x248]
630a5d: e8 ce 00 00 00    call 0x630b30
630a62: 8d 9e 4c 02 00 00 lea ebx,[esi+0x24c]
630a68: 68 08 52 00 00    push 0x5208
630a71: e8 7a ac e3 ff    call 0x46b6f0
630a76: 8d be 50 02 00 00 lea edi,[esi+0x250]
630a7c: 68 d0 52 00 00    push 0x52d0
630a83: e8 68 ac e3 ff    call 0x46b6f0
630a88: 8b 33             mov esi,DWORD PTR [ebx]
630a8d: 68 6b bf 00 00    push 0xbf6b
630a97: 8b ce             mov ecx,esi
630a99: e8 12 3a 11 00    call 0x7444b0
630a9e: c6 86 a4 00 00 00 01 mov BYTE PTR [esi+0xa4],0x1
630ab0: 83 bb 94 00 00 00 00 cmp DWORD PTR [ebx+0x94],0x0
630abf: 8b 01             mov eax,DWORD PTR [ecx]
630ac1: 8b 50 04          mov edx,DWORD PTR [eax+0x4]
630ac4: ff d2             call edx
630ac6: 3d 6b bf 00 00    cmp eax,0xbf6b
630ad3: c6 40 4c 01       mov BYTE PTR [eax+0x4c],0x1
```
0x630B30 以 child ID `0x526C` 呼叫 `0x746940`，以 vtable+0x04 結果比較 `0xC8`，成功回填 this+0x248；0x46B6F0 以 `0x5208`、`0x52D0` 回填 +0x24C 與 +0x250。後兩個控件呼叫 0x7444B0、設 +0xA4=1；在 child+0x94 非 null 及間接物件 vtable 型別碼等於 `0xBF6B` 時，寫入間接物件 +0x4C=1。這屬本地 child widget lookup / type checking / flag writes。上述指令與條件沒有直接證明 Quest accept request、packet builder 或網路 API。

### 1.5 0x630B30 指令邊界
```asm
630b41: 8b f1                mov esi,ecx
630b43: 68 6c 52 00 00       push 0x526c
630b48: e8 f3 5d 11 00       call 0x746940
630b4d: 8b f0                mov esi,eax
630b4f: 85 f6                test esi,esi
630b51: 75 52                jne 0x630ba5
630ba5: 8b 16                mov edx,DWORD PTR [esi]
630ba7: 8b 42 04             mov eax,DWORD PTR [edx+0x4]
630baa: 8b ce                mov ecx,esi
630bac: ff d0                call eax
630bae: 3d c8 00 00 00       cmp eax,0xc8
```
失敗或型別不符通往報錯 formatter / indirect import `[0xBD2580]`，本段不認定其 API 身分，亦不推斷會送出網路訊息。

## 2. 虛擬方法、raw 映射與版本檢查
| VA | raw | 原生確認 | 未確定部分 |
|---|---|---|---|
| 0x62E360 | 0x22D760 | event=0x4E22，傳參數堆疊位址給 0x6306F0 | UI 意義 |
| 0x62E380 | 0x22D780 | T16-80 控件綁定 | 控件 accept 事件 |
| 0x6306F0 | 0x22FAF0 | 檢查 slot / subtype 0x12D，配置 0x254 | 是否由 accept 按鈕觸發 |
| 0x6309D0 | 0x22FDD0 | constructor 最終 vptr 0xC2DBAC | 類名 |
| 0x630A50 | 0x22FE50 | 子控件 0x526C/0x5208/0x52D0 綁定、flags | 業務回呼 |
| 0x630B30 | 0x22FF30 | lookup 0x526C / type 0xC8 | 與 Quest cache 關係 |

## 3. C++ 偽碼（只表達資料流，非原版符號及 ABI）
```cpp
void event_62E360(uint32_t event, uint32_t subcode, void** slot) {
    if (event == 0x4E22) {
        // actual ESI points into incoming stack argument area
        factory_6306F0(&event);
    }
}
void factory_6306F0(uint32_t* args) {
    auto slot = (void**)args[2];
    if (!slot) return;
    if (*slot) { diagnostic(); return; }
    if (args[1] != 0x12D) { diagnostic(); return; }
    void* mem = alloc(0x254);
    *slot = mem ? constructor_6309D0(mem) : nullptr;
}
void* constructor_6309D0(void* self) {
    base_init_candidate(self);
    *(void**)self = (void*)0x00C467DC;
    embedded_init((char*)self + 0x15C);
    *(uint8_t*)((char*)self + 0x158) = 1;
    *(void**)self = (void*)0x00C2DBAC;
    *(void**)((char*)self+0x248) = nullptr;
    *(void**)((char*)self+0x24C) = nullptr;
    *(void**)((char*)self+0x250) = nullptr;
    return self;
}
```

## 4. 玩家情境 / 封包證據矩陣
| 情境 | Client local gate | C→S | S→C | Client cache/UI | Server 待開發 |
|---|---|---|---|---|---|
| event=0x4E22 | subtype==0x12D, output-slot empty, alloc 0x254 | 本函式鏈未見發包；整體是否發包 unknown | unknown | 子物件建立並回填 slot，非 Quest cache write | 無法用此事件推算 Quest 封包 |
| NPC 點接任務 | 未確認對應 UI 控件/event | opcode/length/fields unknown | handler unknown | accepted flag unknown | 接受/拒絕回覆格式待查 |
| Quest16 完成→Quest15 可接 | unknown | unknown | unknown | Quest/NPC 狀態 unknown | 任務規則不可由 Client 推測 |

## 5. 三輪門檻與下段方向
- **T16-81 第 1 輪：** 原生新功能鏈 0x62E360 → 0x6306F0 → 0x6309D0 → 0x630A50 → 0x630B30 / 0x46B6F0；確認成功、slot 已存在、subtype mismatch、配置失敗四類主要分支；辨明它是延遲子視窗工廠而非已確定封包 producer；建立新 vtable/三個 child pointer 欄位。達重大可驗證功能鏈增量。
- **T16-81-2：未啟動。** 第 1 輪已達標；不機械增加輪次。
- **T16-81-3：未啟動。** 同上。

下一段 T16-82：從最終 vtable `0x00C2DBAC` 及 child controls `0x526C/0x5208/0x52D0` 的實際事件 consumer 追 Quest 接取，必要時從 Quest cache writer/收包 dispatcher 反向交會。未取得 wire 証據前不能把 UI/event ID 與本地化訊息 ID 當 opcode。完整追查需要 UI 資源、真正 handler xref 與原始封包證據，缺失保持 unknown。

## 6. 提交界限
僅新增 T16 的 `kr-temp-roy/` 完整原稿；不修改其他 Task、catalog、owner、不提交原始 EXE/BIN。以前段證據作導航，以本段原始機器碼支持新的肯定主張。
