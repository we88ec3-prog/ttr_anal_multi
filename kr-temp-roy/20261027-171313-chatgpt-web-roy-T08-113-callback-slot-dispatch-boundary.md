# T08-113 — callback 槽位與真正派送入口的區隔

研究者：chatgpt-web roy；日期：2026-10-27（Asia/Taipei）。
原始來源：Tartaros.bin，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；本輪實際由本機 sha256sum 核實。以下 VA/ASM 由 BIN 的 objdump -d -Mintel 及 .rdata 原始位元組核對。若僅是結構相容，不推導成指標同一性。

## 新發現：0x007998A0 調用 callback +0x04 而非 +0x0C

```asm
007998D7 mov ebx,[ebp+8]
007998DA push ebx
007998DF call 0x0079AC50
00799B63 mov ecx,[ebx+0xa0]
00799B69 mov edx,[ecx]
00799B6B mov eax,[edx+4]
00799B6E call eax
00799B70 mov ecx,[esi]
00799B72 mov edx,[ecx+8]
00799B75 push esi
00799B76 call edx
```

同一支函式的 0x00799B1A~0x00799B5E 另處理 manager+0xEC，並用 0x00737D40 傳遞 vptr 暫存 0x00C455F8 以及字串/註冊資訊，隨後才呼叫 callback+0x04。不可因它使用了 manager+0xA0 就把此位置判定為 0x007D1310 的呼叫者。

## vtable 原始位元組映射

rdata VA 0x00BD2000 / file offset 0x007D0600；0x00C4FF8C -> 0x0084E58C：

| vtable slot | target | 證據分級 |
|---|---|---|
| +0x00 | 0x007D12E0 | 已確認（可能 deleting destructor） |
| +0x04 | 0x005F5D10 | 已確認（本段直接呼叫） |
| +0x08 | 0x005F5D10 | 已確認 |
| +0x0C | 0x007D1310 | 已確認（分桶派送方法） |

0x00799840 的配置片段：
```asm
00799844 cmp dword ptr [esi+0xa0],0
0079984E push 4
00799850 call 0x00891268
0079985C mov dword ptr [eax],0x00C4FF8C
00799866 mov dword ptr [esi+0xa0],eax
```

## 初步資料流、指標來源與偽碼

此處 EBX 是 0x007998A0 的 [EBP+8] 管理器參數。回查 0x007AAE1B~0x007AAE20，呼叫時 push 0x00FB76A8，並非直接 push 全域桶 [0x00FB7740]。

```cpp
void task_7998A0(ManagerHandle *h) {
  /* ... 其他查詢及註冊 ... */
  auto* cb = h->callback_A0;
  cb->virtual04(); // 不是 bucketConsumer(+0x0c)
  auto* p = /* manager+0xEC 或 fallback */;
  p->virtual08(p);
}
```

## 尚待驗證

1. +0x0C 在 framework 中的實際虛擬呼叫點，特別是作為 callback 參數傳入的 registry。
2. 0x005F5D10 的語義及呼叫契約，不能因同一函式出現在兩個槽就假設與 +0x0C 等價。
3. 真正 owner 來自 [EBP+8]（於 0x007D1310），需另追其 caller。

下一段 114 核對 manager 與其所配置核心物件結構。