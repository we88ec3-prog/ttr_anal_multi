# T08-129 — 已解決：全域 22 桶 callback dispatcher、owner 指標身分鏈

研究時間：2026-10-27 18:43:34 Asia/Taipei。**未 Commit／Push**。

## 1. 來源、方法與結論分級

- 第一手原始檔：`Tartaros.bin`，本輪實測 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- PE `.text`：VA `0x00401000` 對應 file offset `0x400`；使用實際位元組與 GNU `objdump` x86/Intel 反組譯，對重要位置另行區段對齊重解碼；`.rdata` VA `0x00BD2000` 對 file offset `0x007D0600`。
- **已由 BIN 靜態確立**：`0x0079A320` 派送管理器 `+0xA0` 的 callback `vtable+0x0C`，傳入管理器 `+0x98` 指標；兩個已找到的 caller 均把 `EDI` 設為 `0x00FB76A8`，因此傳給 `0x007D1310` 的 owner 是**全域指標槽 `[0x00FB7740]` 的內容**。它確實可以消費全域 22 桶，而不是僅有「類似版型」的另一個 owner。
- **邊界**：本輪是靜態呼叫與指標身分證明，沒有執行遊戲；未由動態追蹤證實每次執行的實際值、呼叫頻率、所有分支可達性或逐幀發生。
- 舊段 T08-125～128 所述全部 22 count 清零與 bucket 階段遍歷為先前研究背景，本輪重驗了第 0 桶 count 寫零；其他桶的逐條 ASM 本輪未全部重抽，不冒稱新增獨立驗證。

## 2. 上游 caller：兩條獨立路徑設定相同 manager handle

```asm
004931F8  BF A8 76 FB 00       mov edi,0x00FB76A8
004931FD  E8 1E 71 30 00       call 0x0079A320

006DD3E6  BF A8 76 FB 00       mov edi,0x00FB76A8
006DD3EB  E8 30 CF 0B 00       call 0x0079A320
```

- 第一條位於 `0x004931FD`；前面可見 `0x004931E2 call 0x007991E0`，但那是條件初始化分支，不能推斷每輪必做。
- 第二條位於 `0x006DD3EB`；後續有 `0x006DD3F0` 以下對另一個 `ESI` 物件的 vtable `+0xA8` 呼叫，不能當成 callback 派送。
- 本輪使用 `E8 rel32` 位元組目標掃描及對齊的 objdump 交叉檢查，這是找到的兩個**直接** call site；不宣稱不存在所有其他間接 caller。

## 3. 真正的 dispatcher：`0x0079A320` 的 callback `+0x0C`

```asm
0079A320  55                    push ebp
0079A321  8B EC                 mov ebp,esp
  ; 此函式前段有例行初始化/其他 call；在此段之前沒有將 EDI 改成別的 owner。
0079A399  8B 8F A0 00 00 00     mov ecx,[edi+0xA0]
0079A39F  8B 01                 mov eax,[ecx]
0079A3A1  8B 97 98 00 00 00     mov edx,[edi+0x98]
0079A3A7  8B 40 0C              mov eax,[eax+0x0C]
0079A3AA  52                    push edx
0079A3AB  FF D0                 call eax
0079A3AD  8B 0F                 mov ecx,[edi]
0079A3AF  8B 11                 mov edx,[ecx]
0079A3B1  8B 42 0C              mov eax,[edx+0x0C]
0079A3B4  BE 01 00 00 00        mov esi,1
0079A3B9  56                    push esi
0079A3BA  56                    push esi
0079A3BB  56                    push esi
0079A3BC  FF D0                 call eax
```

**重要區分**：`0x0079A3AB` 的 `+0x0C` 針對 callback（`[edi+0xA0]`），而 `0x0079A3BC` 的另一個 `+0x0C` 針對 `[edi]` core 物件。這兩個虛擬呼叫的 `this` 與參數不能互換。

### Callback vtable 識別

`0x0079985C` 將 callback 唯一 vptr 設為 `0x00C4FF8C`，`0x00799866` 存到 manager `+0xA0`；在 `.rdata` 的 vtable（file offset `0x84E58C`）對應：

```text
[0x00C4FF8C + 0x00] = 0x007D12E0
[0x00C4FF8C + 0x04] = 0x005F5D10
[0x00C4FF8C + 0x08] = 0x005F5D10
[0x00C4FF8C + 0x0C] = 0x007D1310
```

因此沿正常構建的 callback 動態派送，`0x0079A3AB` 解析到 `0x007D1310`。`0x00799B6E` 是 `+0x04` 空方法，不是 consumer，舊段排除仍有效。

## 4. Owner 的完整位址／值身分鏈（核心新證據）

```text
caller #1 0x004931F8: EDI = literal 0x00FB76A8 ─┐
                                                     ├─> 0x0079A320
caller #2 0x006DD3E6: EDI = literal 0x00FB76A8 ─┘

0x0079A3A1: EDX = *(uint32_t *)(EDI + 0x98)
                   = *(uint32_t *)0x00FB7740
0x0079A3AA: push EDX
0x0079A3AB: callback->vtable[3](owner)
               => 0x007D1310( owner )
0x007D13C4: EBX = [EBP+8] = EDX (caller push)
             => EBX = *(uint32_t *)0x00FB7740
```

注意：**owner 是指標槽裡的「值」，不是 `0x00FB7740` 這個位址本身**。這個區分也是判定全域桶別名時必要的。

## 5. Consumer 對 owner 的實際使用及清零

```asm
007D1310  55                    push ebp
007D1311  8B EC                 mov ebp,esp
007D1398  8B 35 A8 76 FB 00     mov esi,[0x00FB76A8]   ; 另一個 manager/core 值，非 bucket owner
007D139E  68 A8 76 FB 00        push 0x00FB76A8
007D13A7  E8 44 92 FC FF        call 0x0079A5F0
007D13C4  8B 5D 08              mov ebx,[ebp+8]       ; owner = 全域桶 heap 指標
007D13C7  83 BB 04 40 00 00 00  cmp dword ptr [ebx+0x4004],0
007D13DC  8B 8C 93 04 20 00 00  mov ecx,[ebx+edx*4+0x2004]
007D13E3  8B 01                 mov eax,[ecx]
007D13E5  8B 50 0C              mov edx,[eax+0x0C]
007D13E8  6A 01                 push 1
007D13EA  56                    push esi
007D13EB  FF D2                 call edx
007D13FE  6A 03                 push 3
007D1400  68 A8 76 FB 00        push 0x00FB76A8
007D1405  C7 83 04 40 00 00 00  mov dword ptr [ebx+0x4004],0
```

`+0x4004` 為從 bucket base `EBX` 看第二桶（bucket index 1）的 count offset；`+0x2004` 是第二桶 entry array 起點。這是 0x2004 bytes/bucket 的結構一致性佐證。**不同虛擬層級**：`0x007D13EB` 的 `+0x0C` 是「各個 entry」的方法，不是 callback 本身的方法。

上輪 T08-127 已研究後段多個 stage 及尾段清零 22 count；現在藉由本輪已閉合的 owner 指標鏈，可以把該 consumer 確認為**存在真正全域 22 桶 dispatch 路徑**。但完整 22 段內部控制流程、每個 entry class 語義仍以 T08-127 原稿為準。

## 6. C++ 型別化示意（名字暫定，語義以 ASM 為準）

```cpp
struct Manager {
    // ...
    BucketHeap* bucket_owner; // +0x98, actual global slot 0x00FB7740 at the constant manager
    Callback* callback;       // +0xA0
};

void dispatcher_0079A320(Manager* manager_in_EDI) {
    // 先執行其他初始化/調度，不在此偽碼省略出論斷
    auto* cb = manager_in_EDI->callback;
    auto* owner = manager_in_EDI->bucket_owner;
    cb->vtable->slot_0C(cb, owner);
    // 隨後 manager_in_EDI->core->vtable->slot_0C(...three 1 arguments...)
}

void callback_slot_0C_007D1310(Callback* self_in_ECX, BucketHeap* owner_at_EBP_plus_8) {
    // ... manager 前置操作
    for (/* 多個 bucket stage，具體以 T08-127 為準 */) {
       // entry->vtable+0x0C(...)
       // count 歸零
    }
}
```

示意不宣稱 `Manager`/`BucketHeap` 為有符號證明的原始 C++ 類別名；因實際 assembly 以 `EDI` 傳 manager，不能任意改寫為一般 `thiscall` 的 ECX 參數。

## 7. 與先前段落的關係與修正

- **T08-125** 排除 `0x00799B6E`：正確，該處 `callback+0x04` 是空方法。
- **T08-126** 全域 `0x00FB7740` producers 與分配槽：本輪找到由 `0x0079A3A1` **間接透過 manager+0x98 取全域桶指標**的 consumer，解釋為何只掃 `[0x00FB7740]` 立即地址引用難以定位它。
- **T08-127** `0x007D1310` bucket stage／count 全清零：保留先前結論，現在與實際全域 owner 接上。
- **T08-128 / T08-129 階段稿**：「尚未證明 owner 等於全域 22 桶」這個證據缺口**在本輪已解決**；不是矛盾，而是新找到 `0x0079A320` 和兩個 caller 所致。
- **T08-118** 六係數 writer `0x00838430` 已解決；本輪未重跑。

## 8. 尚待驗證（不影響本段核心結論）

1. 真正執行頻率、精確遊戲生命週期階段（不可僅憑 caller 稱「每幀」）。
2. caller `0x004931FD` 與 `0x006DD3EB` 各自外層的完整觸發事件和場景語義。
3. 在 runtime 驗證 callback 非 null、全域 bucket heap 的實際值與 entry 派送（靜態已證明指標來源，runtime 尚未執行）。
4. 各 stage 的 entry class/vtable 對應及特殊事件語義。

### 如需動態二次驗證（本輪**未執行**）

在 `0x0079A3AB` 斷點記錄 `EDI`, `ECX`, `EDX`, `[0x00FB7740]`, `[ECX]`, `[[ECX]+0x0C]`，預期 `EDI=0x00FB76A8`、`EDX=[0x00FB7740]`、slot target `0x007D1310`；在 `0x007D1310` 斷點比對 `[ESP+4]` 與 `[0x00FB7740]`。亦可對清零點設 watchpoint。

## 9. T08-129 結案結論

**本段指定主問題已完成靜態證明**：真正 dispatcher 位於 `0x0079A320`，其 `0x0079A3AB` 透過 callback vtable+0x0C 呼叫 `0x007D1310`；兩個獨立 caller 保證進入 dispatcher 前 `EDI=0x00FB76A8`，owner 來源為 `[EDI+0x98]=[0x00FB7740]`。先前「只知有內嵌 consumer、不能確認消費全域桶」的限制已解除。**T08-129 結案；可由 T08-130 接續 caller 觸發條件／週期或分桶 entry 語義。**

GitHub 狀態：**未 Commit，未 Push**。此檔僅在本次工作環境生成，不會擅自覆寫別的 Agent。