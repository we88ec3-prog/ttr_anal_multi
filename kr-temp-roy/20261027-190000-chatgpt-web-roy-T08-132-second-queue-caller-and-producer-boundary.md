# T08-132 — 優先佇列第二 caller、A4 前置資料路徑與 B4 producer 證據邊界

研究時間：2026-10-27（Asia/Taipei）；本段只根據原始 BIN 靜態資料，不宣稱已動態驗證。

## 1. 來源與方法

- `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪 `sha256sum` 實測一致。
- 依既有 T08-129～131 所採 `.text` 映射 `file offset = VA - 0x401000` 擷取 BIN 的 VA `0x007B8E00..0x007BCF00`，以 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x7B8E00` 反組譯。此映射僅適用這個已交叉核對的程式碼片段，不泛化至所有 PE 節區。
- 另在 BIN 前 0x800000 bytes 檢查 `E8 rel32` 的目標地址。這是直接 call pattern 掃描，不含 `FF /2` 間接呼叫，也不能當作所有可達 caller 的完整證明。
- 本段沿用前段的暫名：`[0x00FBA838]` 所指 0x10C-byte owner 的 `+A4/+A8/+AC` 為 A 陣列、`+B4/+B8/+BC` 為待研究 priority queue、`+C8/+CC/+D0` 為第三陣列；各欄位語義不得依偏移類推。

## 2. 新發現：`0x007BB640` 至少有兩個直接 caller

以 `E8 rel32` 靜態目標比對掃描可見：

| call 地址 | 目標 | 說明 |
|---|---|---|
| `0x0079A394` | `0x007BB640` | T08-130 已有：全域22桶 dispatcher 前置階段 |
| `0x007BAC79` | `0x007BB640` | 本次新確認：另一函式內 A-array/物件派送之後執行 |

第二 caller 原始 bytes `E8 C2 09 00 00`。它並**不是** `0x0079A320` 的替代地址：有獨立的前置步驟，且能在其他呼叫圖位置執行；目前不能依兩個 call 推斷任一 caller 的每幀頻率。

## 3. 第二 caller 的 A 陣列處理

`0x007BABBE` 開始從當時 `ESI` 的 `+A4/+A8` 計算四位元組元素數量，並遍歷各 entry：

```asm
007BABBE mov edi,[esi+0xA8]
007BABC4 sub edi,[esi+0xA4]
007BABCC sar edi,2
007BABD3 mov ecx,[esi+0xA4]
007BABD9 mov edx,[ecx+ebx*4]
007BABDC mov eax,[edx+0x34]
007BABDF mov ecx,[0x00FBA838]
007BABE5 mov edx,[ecx+0x8C]
007BABEB push eax
007BABEC push edx
007BABED call 0x007E8640
007BABF2 inc ebx
007BABF3 cmp ebx,edi
```

這段將 A 陣列中元素 `+0x34` 的值與**全域 owner** `[0x00FBA838]` 所指物件 `+0x8C` 共同交給 `0x007E8640`。可確認其 A 陣列 traversal 與全域 owner 欄位被用作傳參，但**不能**在尚未分析 `0x007E8640` 的情況下斷定它直接往 B4 佇列 push entry。

其後如果 `ESI+0x8C` 非空，會執行不同物件的 `vtable+0x08`：

```asm
007BABF7 cmp dword ptr [esi+0x8C],0
007BAC00 mov ecx,[esi+0x8C]
007BAC06 mov eax,[ecx]
007BAC08 mov edx,[eax+8]
007BAC0B call edx
```

該 vtable+8 的呼叫對象是 `ESI+8C` 的物件，**不是** priority queue entry 的浮點評分介面。偏移一樣不能當成同一接口。

## 4. 第二 caller 的物件子陣列與呼叫排序佇列

另一段通過 `ESI+0x7C/+0x80` 取得指標陣列長度；對其元素 `EDI` 依狀態進入子容器遍歷：

```asm
007BAC0D mov ebx,[esi+0x80]
007BAC13 sub ebx,[esi+0x7C]
007BAC18 sar ebx,2
007BAC25 mov ecx,[esi+0x7C]
007BAC28 mov edi,[ecx+eax*4]
007BAC2B cmp dword ptr [edi+0x20],0
007BAC31 cmp dword ptr [edi+0x78],0
007BAC37 mov ecx,[edi+0x5C]
007BAC3A sub ecx,[edi+0x58]
...
007BAC54 mov edx,[edi+0x58]
007BAC57 mov ecx,[esi+edx+0x28]
007BAC5B mov eax,[ecx]
007BAC5D mov edx,[eax+8]
007BAC60 call edx
...
007BAC79 call 0x007BB640
```

**確認**：`0x007BAC79` 前有至少兩類 object dispatch，其一依子陣列元素的多型方法呼叫，之後呼叫優先佇列 consumer。`0x007BAC50` 暫用 `ESI` 作子陣列 byte offset，`0x007BAC6B` 從保存的 local 還原 `ESI`；因此不可將 `0x007BAC57` 的暫存器 `ESI` 視為全域 owner base。

**待證**：`0x007BAC79` 進入時 `ESI` 是否在所有分支均等於 `[0x00FBA838]`，仍須對此函式完整 prologue、初始化與其他對其 local 的別名進行嚴格核對。僅有早先 A 陣列處理不等於 owner 恆等式的證明。

## 5. 更新 `0x007BB550` 的非 producer 排除證據

前段指出其 `0x007BB61A` 明確做 `add edi,0xA4`，緊接著 `0x007BB623 call 0x007BB750`；這個 helper 的容器位址是 **A 陣列**，不是 B 佇列。更上游可見 `0x007EB807` 直接呼叫 `0x007BB550`，該 call 的上下文有浮點參數與名稱／字串處理，但這仍**不能**把 `0x007EB807` 稱為 B4 producer。

```asm
007BB600 mov ecx,[0x00FBA838]
007BB60D lea ecx,[esi+0x10]
007BB612 call 0x007BB120
007BB617 mov [esi+0x34],eax
007BB61A add edi,0xA4
007BB623 call 0x007BB750
```

另 `0x007BB550` 建立 0x38-byte entry，前段可見 `push 0x38`、`call 0x00891668`，並寫入 entry `+0x0C/+0x10/+0x30/+0x34` 等欄位。這個 entry 先進 A-array，尚無證據直接進 B queue。`0x007BB120` 的執行結果作為 entry `+0x34`，與上節 A 陣列取 `entry+0x34` 後呼叫 `0x007E8640`，形成可追的資料流：

```text
0x007EB807 -> 0x007BB550
  -> allocate 0x38-byte entry
  -> 0x007BB120 => entry+0x34
  -> append to owner+0xA4 via 0x007BB750
  ...
0x007BABBE..0x007BABF5
  -> iterate owner+0xA4
  -> entry+0x34 + [0x00FBA838]+0x8C -> 0x007E8640
```

**限制**：鏈中「append owner」的精確 owner this 的同一性仍需從 `0x007BB550` caller 的 `[EBP+8]` 與其入參來源核實；故本段只宣稱相同欄位版型/值流，並不宣稱同一 entry 在同一時點被匹配。

## 6. `+B4/+B8` writer 目前的具體證據邊界

在本輪反組譯的 `0x007B8E00..0x007BCF00` 中，直接帶 DWORD displacement `+0xB8` 的指令可確認：

- `0x007B8F7C`：建構 `mov [edi+0xB8],ebx`（ebx=0）；
- `0x007B91E8`：析構／重置 `mov [ebx+0xB8],esi`（esi=0）；
- `0x007BB664`、`0x007BB6D0`、`0x007BB705`：consumer 讀取；
- `0x007BB730`：consumer 將 `end` 重置為 `begin`。

**尚未找到**能明確讓 `+B8` 遞增的非建構 writer。這並**不**代表沒有 writer：writer 可能透過 `lea register,[owner+0xB4]` 配合通用 vector append helper、結構別名、直接修改 owner 的基址局部寄存器、或分處此掃描範圍之外。不能把負面局部掃描誇大成全程式不存在。

目前亦未解析出 B queue entry 的特定 vptr 與 `+4/+8` 實際類別方法，故不能聲稱它一定會生產全域 22 桶 entry。

## 7. 可交付之保守偽碼

```cpp
// 概念骨架；型別/欄位名只是本研究暫名
void additional_queue_phase_007BACxx(Unknown* stage) {
    for (auto* a : stage->array_A) {
        auto value = a->field_34;
        helper_007E8640(global_owner_00FBA838->field_8C, value);
    }
    if (stage->field_8C)
        stage->field_8C->virtual_08(); // distinct from sorted queue entry
    for (auto* group : stage->array_7C_80) {
        if (group->field_20 && !group->field_78)
            dispatch_group_children_slot_08(group);
    }
    process_priority_queue_007BB640();
}
```

`process_priority_queue_007BB640()` 的實際 owner 透過 `ESI` 而非標準 `this` 簽名傳遞；偽碼省略具體暫存器保存與例外護欄，**不可**用此宣稱 `stage` 與全域 owner 是同一實例。

## 8. 修正／未解／下段

**T08-132 新確認**：1) 優先佇列 consumer 有第二處直接 caller `0x007BAC79`；2) 此 caller 前的 A 陣列元素 `+34` 結合 `[0x00FBA838]+8C` 進 `0x007E8640`；3) 第二個多型 `vtable+8` 呼叫屬其他子物件，不是排序器評分 entry；4) 在局部直接欄位掃描中未定位 B queue append；5) `0x007BB550` 仍只是 A-array append，不能當 B-array producer。

**尚未解決**：`0x007E8640` 是否間接觸發 B queue producer；B queue entry 具體虛表；`0x007BAC79` 的 owner `ESI` 來源完整鏈；B queue `+B8` 的全程式別名 writer；優先佇列執行與全域 22 桶的直接因果關係。這些均不得假裝已經驗證。

**T08-133 建議**：追 `0x007E8640` 到其最深寫入者，尋找 owner `+B4` 指標經 `lea` 交給 vector insert helper 的候選；再由 B queue 的 entry vptr 追 slot `+4/+8` 以確定是哪些物件與哪種浮點評分。

**GitHub**：本文件建立時尚未提交；使用者本輪有明確授權提交 T08-129～132 未提交原稿，實際狀態以後續提交與遠端讀回報告為準。