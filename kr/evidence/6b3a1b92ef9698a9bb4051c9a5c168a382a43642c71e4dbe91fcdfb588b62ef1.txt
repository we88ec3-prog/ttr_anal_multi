# T08-150 — 0x170 Host 建構後的 0x10 控制區塊、指標移交及 B producer 身分鏈邊界

- Task / author: T08 / `chatgpt-web roy`
- 日期：20261027-223858 Asia/Taipei
- 狀態：本地完整研究原稿；**未 Commit / Push**。
- 一手來源：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本次重新計算）。
- 參考：本地 T08-149 完整研究原稿及 04 接棒文件；本段新增證據均直接採 BIN 位元組以 GNU objdump i386 反組譯檢查，**未進行動態測試**。
- 映射：BIN `.text` 定點讀取 `offset = VA - 0x00401000`。不可將此線性映射任意套用至 `.rdata`。

## 一、研究命題與結論

目標為把 `0x007A5050` 三個已確認的 allocation site（`0x004C825D`、`0x004C850F`、`0x006DC3EA`）往下追至持有者，再判斷是否會以 `ECX` 進入 `0x007A67C0`，以及候選 `+0x0C` 虛擬子物件是否能成為 B entry。

**新增實證**：三條 caller 都會經過 `0x004CA860`，建立獨立 **0x10 bytes 控制區塊**，控制區塊的 `+0x0C` 直接儲存所建構 Host 指標；後續 `0x004E1360` 將 `{Host*, control*}` 指標對移交至持久目的欄位，同時遞減舊持有者計數。`0x007A35C0` 是指標對替換及舊控制區塊引用計數處理 helper，不是 B producer。

**尚未閉合**：沒有在上述路徑發現直接呼叫 `0x007A67C0` 的證據；也沒有證明實際 B entry 使用 `0x00C4F6C0`。不應將控制區塊本身等同於 embedded entry。

## 二、三個建立站點與持有欄位

### A. `0x004C821C` 起：第一條建立及寫入

```asm
004C821C mov ebx,[ebp+08h]             ; 外層 owner / caller 參數
004C8221 cmp dword ptr [ebx+370h],edi  ; 非零則跳過初始化
004C822D mov eax,[ebx+8Ch]
004C8239 mov esi,[ebx+88h]             ; 當 +8C 為零時 fallback
004C823F push 170h
004C8244 call 00891668h                ; allocation
004C8258 movzx ecx,si
004C825B push ecx
004C825C push eax
004C825D call 007A5050h                ; Host constructor
004C8266 push eax                      ; Host *
004C8267 lea edx,[esp+18h]             ; 暫存指標對之地址
004C8272 push edx
004C827B call 004CA860h                ; 建立控制區塊和暫存 pair
004C8280 lea edi,[ebx+15Ch]            ; 目的欄位 
004C8286 lea eax,[esp+14h]             ; 暫存 pair
004C8292 call 004E1360h                ; move pair to owner+15C
004C829B mov esi,[esp+18h]             ; 讀取暫存控制指標以做清理
004C82A9 lock xadd [eax],ecx           ; 控制區塊 +4 引用計數遞減
004C82D3 mov eax,[edi]                 ; owner+15C 內的 Host*
004C82D9 call 007A72A0h                ; 後續初始化 (3 args)
004C8302 mov [ebx+370h],1              ; 初始化 guard
```

`+0x15C` **是外層 owner 的 pair 起點**（`+0x15C=Host*`、`+0x160=control*`），不是 Host 結構的欄位；此位址由 `lea edi,[ebx+15Ch]` 和 `0x004E1360` 的 `mov [edi],edx` / `mov [edi+4],ecx` 共同印證。

### B. `0x004C84DD` 起：第二條建立及移交

```asm
004C84DD mov eax,[esi+8Ch]
004C84E9 mov ebx,[esi+88h]             ; fallback
004C84EF push 170h
004C84F4 call 00891668h
004C850A movzx ecx,bx
004C850D push ecx
004C850E push eax
004C850F call 007A5050h
004C851A push eax
004C851B lea edx,[esp+18h]
004C8526 push edx
004C852F call 004CA860h
004C8534 lea eax,[esp+14h]
004C8540 call 004E1360h                ; EDI 是目的 pair，來源於先前流程
004C857A movzx eax,word ptr [esi+388h]
004C8581 mov ecx,[edi]
004C8587 call 007A72A0h
004C859C mov [esi+370h],1
```

和第一條共用 allocate → construct → 控制區塊 → move pair → `0x007A72A0` 形式；在此節選中 `EDI` 的起源需追進更早的 caller frame，不能僅依相似性無條件斷言此目的地址也必定是 `esi+15C`。

### C. `0x006DC3C0` 起：第三條建立及移交

```asm
006DC3C0 mov eax,[eax+10h]
006DC3C3 cmp dword ptr [eax+54h],0     ; 上游 gating
006DC3CD push 170h
006DC3D2 call 00891668h
006DC3E8 push edi                      ; ctor 第二參數
006DC3E9 push eax
006DC3EA call 007A5050h
006DC3F3 push eax
006DC3F4 lea ecx,[ebp-18h]
006DC3FE push ecx
006DC40D call 004CA860h
006DC412 lea eax,[ebp-18h]
006DC415 mov edi,esi                   ; 目的 pair 由 ESI 指示
006DC41E call 004E1360h
006DC42A mov edi,[ebp-14h]            ; 控制區塊後續 release
006DC45A mov eax,[esi]                ; 目的 pair 的 Host*
006DC461 call 007A72A0h
```

第三條有在進入 allocation 前的 lookup / gate，owner pair 是 `ESI` 所指，非上兩條相同 outer object。從 `0x006DC3C0` 的檢查與 `mov edi,esi` 不能直接推定 SIE / 外層型別。

## 三、控制區塊 `0x004CA860` 的逐欄證據

```asm
004CA889 mov ebx,[ebp+0Ch]            ; EBX = Host*
004CA88E push 10h                      ; 控制區塊 16 bytes
004CA893 call 00891668h
004CA89F mov ecx,1
004CA8A4 mov [eax+04h],ecx             ; strong-like count = 1
004CA8A7 mov [eax+08h],ecx             ; weak/control-like count = 1
004CA8AA mov dword ptr [eax],0C0760Ch ; control vtable
004CA8B0 mov [eax+0Ch],ebx             ; 關鍵：控制區塊持有 Host*
004CA8B8 push edi                      ; control*
004CA8B9 push ebx                      ; Host*
004CA8BA call 007A35C0h                ; ESI 指定目的 pair
004CA8C7 lea eax,[edi+08h]
004CA8CF lock xadd [eax],ecx           ; 控制區塊 +8 加 1
004CA8D3 mov ecx,[ebx+14h]            ; Host 內指向控制區塊的槽
004CA8E0 lock xadd [edx],eax           ; 舊控制 weak-like 計數減 1
004CA8ED mov [ebx+14h],edi            ; Host+14 = new control*
004CA8F0 mov [ebx+10h],ebx            ; Host+10 = self pointer
004CA904 ret 8
```

**確認的雙向 link**：控制區塊 `control+0x0C -> Host`、Host `+0x14 -> control`、Host `+0x10 -> Host`；其中 `+0x14` 與 `+0x10` 在 constructor 初期為 zero，故該綁定在 constructor 之後建立。強/弱計數語義依典型布局與兩套計數路徑高度相符，但未核對完整 vtable 析構前不視為已命名標準 `shared_ptr`。

### 指標對替換：`0x007A35C0`

```asm
007A35C4 mov ebx,[ebp+0Ch]            ; 新 control*
007A35C8 mov edi,[esi+04h]            ; 舊 control*
007A35CF lea eax,[edi+04h]
007A35D5 lock xadd [eax],ecx           ; 舊 strong-like --
007A35DB mov edx,[edi]
007A35DD mov eax,[edx]
007A35DF mov ecx,edi
007A35E1 call eax                      ; 可能釋放 managed object
007A35E3 lea ecx,[edi+08h]
007A35E9 lock xadd [ecx],edx           ; 舊 weak-like --
007A35FB pop edi
007A35FC mov [esi+04h],ebx            ; 新 control*
007A35FF mov [esi],eax                ; 新 Host*
007A3603 ret 8
```

`0x007A35C0` 不配置 B vector、不使用 `[0x00FBA838]`；它處理一對 pointer ownership 的替換，而非 producer。

## 四、指標對的搬移：`0x004E1360`

```asm
004E136E cmp esi,eax                 ; compare temporary address
004E1372 mov ecx,[eax+04h]          ; source.control
004E1375 mov [eax+04h],edx          ; source.control=0
004E1378 mov edx,[eax]              ; source.host
004E137A mov dword ptr [eax],0      ; source.host=0
004E1380 mov esi,[edi+04h]          ; old destination.control
004E1383 mov [edi+04h],ecx          ; destination.control=source.control
004E1386 mov [edi],edx              ; destination.host=source.host
004E1388 test esi,esi
004E1392 lock xadd [eax],ecx        ; old destination strong-like --
004E1398 mov edx,[esi]
004E139A mov eax,[edx]
004E139C mov ecx,esi
004E139E call eax
004E13A0 lea ecx,[esi+08h]
004E13A6 lock xadd [ecx],edx        ; old destination weak-like --
004E13B5 mov eax,edi
004E13BB ret
```

此 helper 是具有清空 source / 覆蓋 destination / release old destination 的 **move-like pair ownership 操作**。注意首個 `lea esi,[ebp-8]` 為局部偽結構指標，並非從它讀出 source；來源真正由 EAX 指定，目的由 EDI 指定。不能錯解成普通 8-byte `memcpy`。

## 五、constructor 內部的側證：`0x007A5050`

```asm
007A5077 mov esi,[ebp+08h]
007A508D mov dword ptr [esi+0Ch],00C4F66Ch
007A5094 mov [esi+10h],ebx
007A5097 mov [esi+14h],ebx
007A50B9 mov dword ptr [esi+0Ch],00C4F6C0h
007A50D9 push 14h                     ; Host 內部另外配置 0x14 bytes
007A50EE mov [esi+50h],eax            ; 內嵌容器 / sentinel node
007A5111 push 28h
007A5126 mov [esi+60h],eax
007A5149 push 28h
007A515E mov [esi+70h],eax
```

直接印證 `+0x10/+0x14` 在構造早期皆歸零，之後由 `0x004CA860` 寫回 self/控制區塊；亦可確認 `Host+0x70` 指向 constructor 所配置 `0x28` 大小的自我鏈結 sentinel，與 producer 的 `[edi+70h]` 走 linked structure 的觀察**相容**。這是強化候選身分的同位址證據，不等同實際 caller 身分已閉合。

## 六、B producer 可達性、vtable 與 ABI：保留反證邊界

- `0x007A67C0` 入口 `mov edi,ecx`，其 `+0x1C/+0x124/+0xAC/+0x70/+0x8C` guards 與本候選欄位相近；但 **沒有直接 caller 身分鏈**。
- 本次另以 BIN 全域原始 DWORD 掃描 `0x007A67C0 / 0x007A67D0 / 0x007A67E8 / 0x007A69D9 / 0x007A6A89`，**均無 literal reference**。這是針對所列常數的 pattern search，無法排除 register-computed branch、相對 CALL target、或 runtime relocation / dispatch；不可推論 `0x007A67C0` 不可達。
- T08-149 已確定 `.rdata` 中 `0x00C4F6C0` 的 `+0x04=0x007A8310`、`+0x08=0x007A8E10` 呈現嚴重入口矛盾；本段沒有取得可修正映射／入口邊界的新第一手證據，**沿用未解狀態，不宣稱已建立 B entry subtype**。
- Consumer `0x007BB6F6 → 0x007BB6FE` 以 `ECX=Host+0x0C` 與 `call [vptr+4]` 直接呼叫；這與被存於 holder pair 的 `Host*` 指標不同，後續需要追 holder 解參照後的 caller。
- 沒有在本次觀察 B execute 導致 `[0x00FB7740]` 22 桶計數直接變化，勿將 producer→consumer 先後視為因果證據。

## 七、暫定 C++ 偽碼（結構名未有符號證明）

```cpp
struct ControlCandidate {
    void** vptr;            // +0x00 = 0x00C0760C
    volatile int strong;    // +0x04, initial 1 (語義未完整證明)
    volatile int weak;      // +0x08, initial 1
    HostCandidate* p;       // +0x0C
};
struct HoldingPair { HostCandidate* p; ControlCandidate* ctrl; };

void constructAndAttach(HoldingPair* holder, unsigned id) {
    HostCandidate* h = (HostCandidate*)allocate(0x170);
    if (h) construct_007A5050(h,id);
    HoldingPair tmp = {};
    create_004CA860(&tmp,h); // 同時 link h->control +0x14
    movePair_004E1360(holder,&tmp); // 移入目的; 清空來源; release old
    if (holder->p) initialize_007A72A0(holder->p, ...);
}
```

`create_004CA860` 對 null/allocation failure 的處理及 `0x007A35C0` 各分支反例，應以上述 ASM 為準；偽碼只展示成功主路徑。

## 八、證據分級與下段目標

**已確認：** 0x170 allocated Host 指向 0x10 control block；control+0x0C 反向保存 Host 指標；Host+0x10 與 +0x14 由 `0x004CA860` 建立 link；`0x004E1360` 移交 pair 並釋放舊控制區塊；建構與 B producer 的 `+0x70` 欄位有具體相容結構。

**合理推測：** 這套 `0x10` block 是 shared-/weak-reference control block，具有保持 Host 活性之功能；需追 `0x00C0760C` 的虛擬釋放槽與引用來源才可確定所有權語義及生命週期。

**未知：** `0x007A67C0` 的實際 virtual caller、B entry 動態 vptr、候選 vtable 入口矛盾根因、B execute→22 桶 producer 的因果鏈、Host 在 B 清隊列前是否受持有者保護。

**下一段 T08-151 重點：** ①以 `[owner+0x15C]` 與第三條 `ESI` holder 作逆向/正向 xref，追 Host update 方法之 virtual dispatch；②查 `0x00C0760C` 控制區塊虛擬槽對象回收與 Host destructor 先後；③調查 B producer 的間接 call-site，並以 BIN 核對解碼邊界；④核對 `0x007A8310 / 0x007A8E10` 的 rdata/code 映射或 runtime vptr。

**GitHub 狀態：** 未 Commit / Push；研究內容只存在本地本文件。以上結論全為靜態分析，並未實測遊戲。