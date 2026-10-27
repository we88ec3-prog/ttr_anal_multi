# T08-115 — bucket callback 參數與 count 清零的責任界線

研究者：chatgpt-web roy；日期：2026-10-27（Asia/Taipei）。
原始來源：Tartaros.bin，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；本輪實際由本機 sha256sum 核實。以下 VA/ASM 由 BIN 的 objdump -d -Mintel 及 .rdata 原始位元組核對。若僅是結構相容，不推導成指標同一性。

## 0x007D1310 本體的指標來源

```asm
007D1398 mov esi,[0x00FB76A8]
007D139E push 0x00FB76A8
007D13A7 call 0x0079A5F0
007D13AE mov eax,[edi]
007D13B0 mov ecx,[eax+0xe4]
007D13B6 push 0
007D13B8 push 0x98
007D13BD push edi
007D13C2 call ecx
007D13C4 mov ebx,[ebp+8]
007D13C7 cmp dword ptr [ebx+0x4004],0
007D13DC mov ecx,[ebx+edx*4+0x2004]
007D13E5 mov edx,[eax+0x0c]
007D13E8 push 1
007D13EA push esi
007D13EB call edx
007D1405 mov dword ptr [ebx+0x4004],0
```

分桶 owner 在 EBX = [EBP+8]，即 callback 的第一個明示 stack parameter；不是 ECX 形式的 this，亦非本體中直接讀取 [0x00FB7740]。0x007D1310 同時借用全域 manager 值於 ESI 供每個 entry virtual0C 調用。這是兩個不同指標來源，不能混同。

## 已驗證其他分桶的階段

| index | entries base | count | stage | 清零 VA |
|---|---|---|---|---|
| 1 | EBX+0x2004 | EBX+0x4004 | 1 | 0x007D1405 |
| 2 | EBX+0x4008 | EBX+0x6008 | 2 | 0x007D1476 |
| 4 | EBX+0x8010 | EBX+0xA010 | 4 | 0x007D14FC |
| 15 | EBX+0x1E03C | EBX+0x2003C | 15 | 0x007D152C |

```asm
007D1452 mov ecx,[ebx+edx*4+0x4008]
007D145B mov edx,[eax+0xc]
007D145E push 2
007D1461 call edx
007D1476 mov dword ptr [ebx+0x6008],0
007D14E0 mov ecx,[ebx+edi*4+0x8010]
007D14EC push 4
007D14EF call edx
007D14FC mov [ebx+0xa010],edi
007D1510 mov ecx,[ebx+edi*4+0x1e03c]
007D151C push 0xf
007D151F call edx
007D152C mov dword ptr [ebx+0x2003c],0
```

上述 0x14FC 時 EDI 被清為0，故 count 清零；沒有證據顯示 entries[i] 被逐個釋放。

## callback+4 實例檢查

0x00799B63->0x00799B6E 的 manager+0xA0 callback vtable+4 呼叫，在 vptr=0x00C4FF8C 情況下落入 0x005F5D10，**不會進入 0x007D1310**。此路徑因此排除作為 bucket consumer 直接 caller。這是負向證據，可避免誤判。

```cpp
void callback_virtual0C(void* thisCb, BucketOwner* owner) {
  Interface* iface=acquireInterface(&globalManager);
  iface->virtualE4(iface,0x98,0);
  for(int idx: {1,2,4,15}){
    auto* b=(Bucket*)((char*)owner+idx*0x2004);
    for(int i=0;i<b->count;++i) b->entries[i]->virtual0C(globalManager,idx);
    b->count=0;
  }
}
```

偽碼只示意已驗證片段，原函式還有其他階段與介面調用；不能把 4 個桶當作完整遍歷集合。

## 尚待驗證

真正進入 callback vtable+0x0C 的 caller、傳入 owner 的值是否等於 [0x00FB7740]；尚未能定位。因此全域 bucket consumer 仍未知。下一段 116 對六係數的 alias、配置及外部幾何 consumer 重新界定。