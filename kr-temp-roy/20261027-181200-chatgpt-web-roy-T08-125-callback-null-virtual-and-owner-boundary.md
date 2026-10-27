# T08-125 — Callback +04 空方法與 +0C owner 實參分離

研究者：chatgpt-web roy｜2026-10-27 Asia/Taipei。來源：本機 `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪使用 sha256sum 重新計算一致）；機器碼由已存在 `t08_current_disasm.txt` 及原始 PE 的 x86 objdump 核對。GitHub 已完成 T08-124；本輪研究自125接續。

**證據約定**：已確認＝BIN 可重現；推測＝語義未獲符號/實際呼叫驗證；未知＝仍無直接證據。相同欄位偏移不可跨 C++ 物件型別混用。這是按研究主題完整保留的分段原稿，不將負向搜尋冒充不存在證明。

## 目標與結果
從 `0x005F5D10` 向回追 callback vtable，再確認 T08-121 對於 `0x00799B6E` 的排除結論。**新確認：`0x005F5D10` 的完整機器碼只有 `ret`**，不是另一條隱藏分桶消費函式。T08-121 的排除可升為「實際無操作」而非只有 vtable 槽位不同。

## 第一手 ASM
```asm
005F5D0C int3
005F5D10 ret
005F5D11 int3
005F5D12 int3
005F5D13 int3

00799844 cmp dword ptr [esi+0xa0],0
0079984E push 4
00799850 call 0x00891268
0079985C mov dword ptr [eax],0x00C4FF8C
00799866 mov dword ptr [esi+0xa0],eax

00799B63 mov ecx,[ebx+0xa0]
00799B69 mov edx,[ecx]
00799B6B mov eax,[edx+0x4]
00799B6E call eax

007D13C4 mov ebx,[ebp+0x8]
007D13C7 cmp dword ptr [ebx+0x4004],0
007D13DC mov ecx,[ebx+edx*4+0x2004]
007D13E3 mov eax,[ecx]
007D13E5 mov edx,[eax+0x0c]
007D13E8 push 1
007D13EA push esi
007D13EB call edx
```

## 語意與對照
`0x00C4FF8C` vtable slots：+00=`0x007D12E0`、+04=`0x005F5D10`、+08=`0x005F5D10`、+0C=`0x007D1310`。若呼叫處的 callback vptr 確為 0x00C4FF8C，則 `0x00799B6E` 只會執行一個立即返回的方法，沒有分桶 entries/count 的讀寫。其實際執行依然取決於 vptr 動態值；目前該 4-byte callback 初始化時確已寫入這張表。

`0x007D1310` 從 `[ebp+8]` 取 bucket base，entry 的 virtual +0x0C 是**另一個類型**的虛函式，不應將 entry vtable +0x0C 當成 callback 本體的 vtable +0x0C。

```cpp
struct Callback { void** vptr; }; // observed allocation size 4
void callbackVirtual04(Callback*) { return; } // observed 0x005F5D10
void callbackVirtual0C(Callback*, BucketOwner* owner) {
  // owner comes from [EBP+8], NOT identified as [0x00FB7740]
  for (...) owner->bucket[i].entries[j]->virtual0C(globalManager, i);
}
```

## 已確認／推測／未知
- **確認** `0x005F5D10` 為空方法；+04/+08 都指向它；callback +0C 指向 `0x007D1310`。
- **確認** 分桶 consumer 的參數 owner 是外部傳入 `[EBP+8]`。
- **未知** callback +0C 的實際 dispatcher 與 owner 參數值；因此未解決全域桶 consumer 身分。
- **T08-126** 完整分類全域指標直接 xrefs，檢查是否存在漏掉的 direct read/clear。