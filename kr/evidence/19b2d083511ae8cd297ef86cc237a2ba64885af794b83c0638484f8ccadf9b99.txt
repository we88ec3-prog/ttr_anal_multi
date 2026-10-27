# T08-151 — 控制區塊雙階段釋放、Host +0x14 弱引用解除及 owner 更新分派邊界

- Task / analyst：T08 / `chatgpt-web roy`
- 研究時間：2026-10-27 22:44:26 Asia/Taipei
- 交付狀態：完整本地研究原稿，**未 Commit / Push**。
- 一手證據：`Tartaros.bin` 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本段重新核算）。
- 工具：以 Python byte offset 擷取、GNU `objdump -D -b binary -mi386 -M intel --adjust-vma` 反組譯。未執行遊戲、未下斷點。
- BIN `.text` 研究映射：`file offset = VA - 0x00401000`；`.rdata` 映射：`file offset = VA - 0x00BD2000 + 0x007D0600`。上述映射為本資料集既有假定；本文每處虛擬表地址皆與內容直接核對，**不能把指標值即視為合法入口**。
- 歷史依據：T08-149 / T08-150 本地原稿；已完成的 T08-145～148 交接摘要。此次新分析針對釋放分支，不將舊假說當新事實。

## 1. 本段判定與主要新結論

1. `0x004E1360` **先遞減舊 holder control+0x04**，結果為零才呼叫其 `vptr+0x00`；接著再遞減 `control+0x08`，結果為零才呼叫 `vptr+0x04`。是兩階段的強引用／控制區塊終結流程，而非單一 free，也非每次 holder 替換都會銷毀 Host。
2. `0x007A35C0` 提供同類型「替換 pair → 先 release 舊 strong → 再 release 控制區塊 weak」的獨立佐證；並存在計數未歸零即跳過 release 的分支。
3. `0x004CA860` 建立 `0x10`-byte control 並透過 `Host+0x14` **額外增加 `control+0x08` 計數**。`0x007A5A37～0x007A5A4F` Host 析構階段對 `Host+0x14` 同組計數減一、必要時才走 `vptr+0x04`。因此 `Host+0x14` 與 control+0x08 的雙向關係具有釋放對稱性。
4. `owner+0x15C` 的第一條 owner 初始化路徑在完成 pair 移交後，確實**讀取 holder 的 Host 指標**並傳入 `0x007A72A0`；此外依條件寫入 `Host+0x20=1` 並呼叫 `0x007A9270`。這是實際可觀察的 holder → Host 下游用途，但**不是 `0x007A67C0` 的直接呼叫身分鏈**。
5. 控制區塊常數 `0x00C0760C` 的 `.rdata` 前兩 DWORD 讀到 `0x004CA660 / 0x007A3920`，但是前者與目前 `.text` 反組譯的樹操作函式交疊，後者從 `0x007A3910` 函式中間切入。此 ABI 疑點與 T08-149 的 `0x00C4F6C0` 類似；**本文不把這些值命名為有效析構入口，不宣稱已反組出具體釋放函式內部**。

## 2. 核心結構（欄位的機器碼使用方式）

```
struct ControlBlockCandidate (size=0x10):
 +0x00 vptr           = 0x00C0760C     ; constructor 直接寫入
 +0x04 count_A        = 1              ; 建立、舊 holder 替換時減一
 +0x08 count_B        = 1              ; 建立後 Host+14 再加一；Host 析構時減一
 +0x0C managed_Host*  = Host           ; 建立時寫入

struct HolderPair (size=0x08):
 +0x00 Host*
 +0x04 ControlBlockCandidate*

HostCandidate (allocated 0x170 bytes):
 +0x0C embedded vptr  ; 候選 B entry vptr，真實 B dynamic type 尚未證實
 +0x10 self pointer   ; 建立後指向自己
 +0x14 control*       ; 建立後指向控制區塊，析構時遞減 count_B
 +0x20 flag byte      ; 某條外層初始化條件下設為 1
```

`count_A/count_B` 解作 strong-/weak-like 計數是由使用方式支持的語義命名，不是符號或 RTTI 直接證明 `std::shared_ptr`。同樣的 +0x04/+0x08 位移在 *其他* 型別不應直接套用。

## 3. `0x004E1360`: 替換 holder，兩階段引用釋放

實際位元組／反組譯選錄：

```asm
004E136E  cmp esi,eax           ; 特別路徑比較暫存位址與 source
004E1372  mov ecx,[eax+04h]    ; source.control
004E1375  mov [eax+04h],edx    ; source.control = 0
004E1378  mov edx,[eax]        ; source.host
004E137A  mov dword ptr [eax],0
004E1380  mov esi,[edi+04h]    ; old control = dest.control
004E1383  mov [edi+04h],ecx    ; dest.control = source.control
004E1386  mov [edi],edx        ; dest.host = source.host
004E1388  test esi,esi
004E138A  je 004E13B5
004E138C  lea eax,[esi+04h]
004E138F  or ecx,-1
004E1392  lock xadd [eax],ecx   ; count_A -= 1，flags 以新結果判斷
004E1396  jne 004E13B5        ; 結果非零：不進入終結路徑
004E1398  mov edx,[esi]        ; control.vptr
004E139A  mov eax,[edx]        ; slot +0
004E139C  mov ecx,esi          ; this=control
004E139E  call eax
004E13A0  lea ecx,[esi+08h]
004E13A3  or edx,-1
004E13A6  lock xadd [ecx],edx   ; count_B -= 1
004E13AA  jne 004E13B5
004E13AC  mov eax,[esi]
004E13AE  mov edx,[eax+04h]    ; slot +4
004E13B1  mov ecx,esi
004E13B3  call edx
004E13B5  mov eax,edi
004E13BB  ret
```

**精確條件**：x86 `xadd` 更新 ZF 反映算術結果，故原計數為 1 並減 1 才使 `jne` 不成立；這一點不應把 register 中返回的舊值和 flags 混為一談。`count_A` 未歸零時**沒有**立即解構舊 Host；若 `count_A` 歸零，先執行 vtable slot0，再遞減 `count_B`，只有 `count_B` 也歸零才執行 slot1。

**注意**：從函式直接反組譯只能確認虛擬呼叫順序與條件，不能在 vtable 目標入口矛盾尚未解開時直接宣稱 slot0 已執行何種 destructor/free 操作。

## 4. `0x007A35C0`: 第二條獨立的對照路徑

```asm
007A35C4  mov ebx,[ebp+0Ch]  ; new control
007A35C8  mov edi,[esi+04h]  ; old control
007A35CB  test edi,edi
007A35CD  je 007A35F8
007A35CF  lea eax,[edi+04h]
007A35D2  or ecx,-1
007A35D5  lock xadd [eax],ecx
007A35D9  jne 007A3614       ; count_A 非零 => 直接改寫 pair
007A35DB  mov edx,[edi]
007A35DD  mov eax,[edx]
007A35DF  mov ecx,edi
007A35E1  call eax             ; slot0，this=old control
007A35E3  lea ecx,[edi+08h]
007A35E6  or edx,-1
007A35E9  lock xadd [ecx],edx
007A35ED  jne 007A3606
007A35EF  mov eax,[edi]
007A35F1  mov edx,[eax+04h]
007A35F4  mov ecx,edi
007A35F6  call edx             ; slot1，this=old control
007A35F8  mov eax,[ebp+08h]
007A35FC  mov [esi+04h],ebx
007A35FF  mov [esi],eax
007A3603  ret 8
```

上述 `0x007A3606` 與 `0x007A3614` 是對同一新 pair 的分支收尾，並非新的 queue append。這條路徑再次明確將「替換外部持有物件」與「實際 B queue 入列」分離。

## 5. `0x004CA860` 新增弱引用與 Host destructor 對稱性

```asm
004CA88E  push 10h               ; control block 0x10 bytes
004CA893  call 00891668h
004CA89F  mov ecx,1
004CA8A4  mov [eax+04h],ecx      ; count_A=1
004CA8A7  mov [eax+08h],ecx      ; count_B=1
004CA8AA  mov [eax],0C0760Ch    ; vptr
004CA8B0  mov [eax+0Ch],ebx      ; managed Host
004CA8B8  push edi
004CA8B9  push ebx
004CA8BA  call 007A35C0h         ; 初次設定暫存 pair
004CA8BF  test ebx,ebx
004CA8C1  je 004CA8F3
004CA8C3  test edi,edi
004CA8C5  je 004CA8D3
004CA8C7  lea eax,[edi+08h]
004CA8CA  mov ecx,1
004CA8CF  lock xadd [eax],ecx    ; count_B += 1（Host 內部持有）
004CA8D3  mov ecx,[ebx+14h]    ; Host 舊 control
004CA8D6  test ecx,ecx
004CA8D8  je 004CA8ED
004CA8DA  lea edx,[ecx+08h]
004CA8DD  or eax,-1
004CA8E0  lock xadd [edx],eax   ; 舊 Host weak-like ref --
004CA8E4  jne 004CA8ED
004CA8E6  mov edx,[ecx]
004CA8E8  mov eax,[edx+04h]
004CA8EB  call eax             ; 舊 control slot1，ECX 仍為 control
004CA8ED  mov [ebx+14h],edi
004CA8F0  mov [ebx+10h],ebx
```

此處 `count_B` 初始化為 1 後還有一次加一，是理解生命週期重要補強：若 Host 非空，常見成功路徑將多出對控制區塊的弱型引用；釋放後 count_B 是否歸零由實際其他 holder/Host 回收順序決定。

Host 生命週期尾段：

```asm
007A5A26  lea edx,[ebx+2Ch]
007A5A29  push edx
007A5A2E  call 007A5520h
007A5A37  mov ecx,[ebx+14h]    ; Host -> control
007A5A3A  test ecx,ecx
007A5A3C  je 007A5A51
007A5A3E  lea eax,[ecx+08h]
007A5A41  or edx,-1
007A5A44  lock xadd [eax],edx   ; count_B -= 1
007A5A48  jne 007A5A51
007A5A4A  mov eax,[ecx]
007A5A4C  mov edx,[eax+04h]
007A5A4F  call edx             ; slot1，this=control
007A5A51  mov [ebx+0Ch],0C4F66Ch ; embedded vptr 回復到基底候選
007A5A58  mov [ebx+08h],0C0F878h
007A5A5F  mov [ebx+04h],0C4F64Ch
007A5A66  mov [ebx],0C4F468h
```

**順序限制**：此處可證明在該路徑執行時弱型計數與 vptr 還原動作的先後，不代表全部 Host 解構路徑皆必經此函式；也**不能證明 B vector consumer 已經跑完**。要判定 dangling entry/use-after-free，還須獨立證明調度與所有權保護的同一實例／同一幀順序。

## 6. `owner+0x15C` 實際使用（第一條 owner）

```asm
004C8280  lea edi,[ebx+15Ch]      ; holder destination
004C8292  call 004E1360h        ; move pair
004C82D3  mov eax,[edi]          ; Host* from holder
004C82D5  push ecx               ; outer +0x388 word
004C82D6  push 1
004C82D8  push eax
004C82D9  call 007A72A0h         ; direct call，Host* 當 stack argument
004C82DE  cmp byte ptr [ebp+0Ch],0
004C82E2  je 004C82F2
004C82E4  mov eax,[edi]
004C82E6  mov byte ptr [eax+20h],1
004C82EA  mov eax,[edi]
004C82EC  push eax
004C82ED  call 007A9270h
004C82F2  mov edx,[ebx]
004C82F4  mov edx,[edx+44h]
004C82F7  push 1
004C82F9  lea eax,[ebx+0A0h]
004C82FF  push eax
004C8300  mov ecx,ebx
004C8302  mov [ebx+370h],1
004C830C  call edx               ; 外層 owner vtable +0x44 方法
```

**已確認**：holder Host* 提供給 `0x007A72A0`，在某條件下提供給 `0x007A9270`；隨後透過 **outer owner**（ECX=EBX、vtable+44）虛擬呼叫外層方法。最後這個虛擬呼叫不能錯認成 `Host+0x0C` entry 的 vtable dispatch。`0x007A72A0` 是 `push Host*` 的 stack-argument 接口，不能因首參為 Host 就推定是 thiscall `0x007A67C0`。

## 7. vtable / ABI 仍未閉合：兩組同型疑點需共同檢查

按本研究的 `.rdata` offset 公式，直接從 BIN 讀 DWORD：

| vtable VA | slot0 | slot1 | slot2 | slot3 |
|---|---|---|---|---|
| `0x00C0760C` | `0x004CA660` | `0x007A3920` | `0x007A3950` | `0x007848C0` |
| `0x00C4F6C0` | `0x007AAA90` | `0x007A8310` | `0x007A8E10` | `0x00C7F9F4` |

具體反證：`0x004CA660` 位於 `0x004CA600` 起始的樹容器插入/旋轉類函式中段；`0x007A3920` 在 `0x007A3910` 開始、並已執行 alloc 的函式中段。若以這些 vtable 數值作完整函式入口，將跳過必要 prologue/參數狀態，不可直接認定其為 control 的 destroy/free 函式。舊候選表 `0x00C4F6C0` 同樣存在 `0x007A8E10` 落在指令中段的矛盾。

**待驗證假說**：可先從 `Tartaros.exe` 的 PE headers/section table 驗證是否應套用不同基底或 offset，並與 Ghidra 匯出逐點比對；若映射正確，再追 vtable 定義邊界及特殊 entry/thunk 的實際存在性。並無實際動態 vptr dump，不能聲稱已驗證這些地址在 runtime 執行。

## 8. 暫定 C++ 偽碼（精確路徑簡化表示）

```cpp
struct HostCandidate;  // 無正式 RTTI 類別名稱證明
struct ControlCandidate {
    void** vptr;                 // +0, written 0x00C0760C
    volatile int countA;        // +4
    volatile int countB;        // +8
    HostCandidate* managedHost; // +C
};
struct HolderPair { HostCandidate* host; ControlCandidate* control; };

void moveHolder(HolderPair& dest, HolderPair& source) {
    if (&source != /* special local alias checked in assembly */ nullptr) { /* see ASM */ }
    ControlCandidate* prior = dest.control;
    dest.host = source.host;
    dest.control = source.control;
    source = {};
    if (!prior) return;
    if (atomic_decrement(prior->countA) == 0) {
        virtualSlot0(prior);           // effect UNVERIFIED
        if (atomic_decrement(prior->countB) == 0)
            virtualSlot1(prior);       // effect UNVERIFIED
    }
}

void releaseHostAttachedControl(HostCandidate* host) {
    ControlCandidate* ctrl = host->control_at_0x14;
    if (ctrl && atomic_decrement(ctrl->countB) == 0)
        virtualSlot1(ctrl);           // actual target still requires ABI validation
}
```

註：上面 `moveHolder` 特殊 local alias 的示意行僅為提醒，**並非**完整可編譯還原；實際 `0x004E136E` 比較的是 `ESI=&local` 與 EAX source，不能誤寫為普通 source/dest equality 判斷。虛擬函式效果仍屬未知。

## 9. 三級證據分類

**直接確認（BIN static）**
- `0x004E1360` 的兩個原子遞減和條件 slot0/slot1 呼叫順序；`0x007A35C0` 的同類路徑。
- `0x004CA860` 建立 `0x10` control，初始化兩個計數並在 Host 非空路徑增加 count_B；`Host+0x14` 寫回 control。
- `0x007A5A37～0x007A5A51` 減掉 Host 綁定的 count_B，必要時觸發 slot1，之後還原多組 vfptr。
- `owner+0x15C` 的 host 參與 `0x007A72A0`、條件式 `0x007A9270` 與外層 owner virtual call 的控制流程。

**合理推測**
- `count_A` 與 `count_B` 分別扮演強引用與 weak/control-block 存活計數；slot0 類似 destroy managed object、slot1 類似 deallocate control。這符合序列與計數操作，但需要合法函式入口及其內容才能定性。
- 一般 holder 持有強型參考可能延長 Host 壽命；B queue 只保存 embedded raw pointer，並未顯示自己的 retain。

**未能確認／反證尚存**
- `0x00C0760C` slot 值與 `.text` 函式入口衝突；未證實任何具體 free routine。
- 未閉合 `0x007A5050` 物件與 `0x007A67C0` ECX 的 caller 身分鏈。
- 未取得 runtime B entry vptr，也未證明其真為 `0x00C4F6C0`。
- 未證實 B execute 導致 22 桶 count 增量；未證實 use-after-free 或安全的存活保證。

## 10. 建議 T08-152 後續工作

1. **先查 PE/映射與 vtable 數據對位**：優先解決控制區塊 vptr `0x00C0760C` 及 embedded `0x00C4F6C0` 兩張表的入口矛盾；以 EXE PE section/可能 runtime image layout 與 BIN、Ghidra `kr-bulk-roy` 逐點比對。勿因地址落在程式碼範圍就定為 callable。
2. 沿 `owner+0x15C` 的讀取/清空與外層 owner destructor，確認 Host 引用何時歸零；從 `0x007A72A0` / `0x007A9270` 的下游函式分派找 `0x007A67C0` 虛擬 slot/間接呼叫的可驗證鏈。
3. 沿 B vector append `0x007A69E5` 和 consumer `0x007BB6F6` 的兩側，在**相同實例**上交叉確認 wrapper 控制區塊指標、embedded entry vptr、owner 是否仍存活；若無靜態閉合，列未執行的動態斷點方案。
4. 追 `0x007BB640` 與全域 `[0x00FB7740]` 的 22 桶 consumer 實際物件生成來源，不把已確定的 dispatcher 順序當成直接因果。

## 11. 版本管理

- 本段研究原稿僅儲存在本地 Markdown；**未 Commit／Push**。
- 同樣尚未提交：T08-149、T08-150（以先前對話本地原稿為準）。