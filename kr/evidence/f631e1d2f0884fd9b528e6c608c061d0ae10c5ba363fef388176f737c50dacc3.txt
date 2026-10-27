# T08-114 — 0x470-byte manager 內核物件建構與不同 vptr

研究者：chatgpt-web roy；日期：2026-10-27（Asia/Taipei）。
原始來源：Tartaros.bin，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；本輪實際由本機 sha256sum 核實。以下 VA/ASM 由 BIN 的 objdump -d -Mintel 及 .rdata 原始位元組核對。若僅是結構相容，不推導成指標同一性。

## 上游分配與建構鏈

```asm
007997C4 push 0x470
007997C9 call 0x00891268
007997DF mov ecx,[ebp+8]
007997E2 mov edi,eax
007997E4 call 0x00839940
007997FA mov [esi],eax
0079981A mov eax,esi
0079981C call 0x00799840
00799830 ret 4
```

caller 0x007AAD9A: mov esi,0x00FB76A8；0x007AAD9F: call 0x007997A0。由此可確證管理器指標槽與分配出來的 0x470-byte 核心物件之關聯；管理器本體及 callback 4-byte 物件是兩層獨立配置。

## 0x00839940 的具體建構證據

```asm
0083996D mov esi,ecx
00839970 mov [ebp-0x158],edi
0083997C call 0x00849850
00839986 mov dword ptr [edi],0x00C53F44
0083998C mov [edi+0xe8],ebx
00839992 mov [edi+0xec],esi
00839998 lea esi,[edi+0xf0]
008399A4 call 0x008637F0
008399B3 mov [esi+0x40],eax
008399C2 lea esi,[edi+0x134]
008399D2 call 0x008637F0
008399E1 mov [esi+0x40],eax
008399F0 lea esi,[edi+0x178]
00839A00 call 0x008637F0
```

0x00839940 的 THIS 應以 EDI 指向配置返回；ECX 另代表 constructor parameter，寫入 +0xEC。因此 0x0079A5F0 使用的 manager->+0xEC 有明確建構期來源，而不是任意 global pointer。

新增配置證據：
```asm
00839A63 push 0x90
00839A7E mov [edi+0x3c4],eax
00839AB6 push 0x90
00839AD1 mov [edi+0x3d4],eax
00839B09 push 0x90
00839B24 mov [edi+0x3e4],eax
00839BAF push 0x24
00839BC7 mov [edi+0x464],eax
00839B58 mov eax,0xf
00839B5D mov [edi+0x40c],eax
00839B63 mov [edi+0x408],ebx
```

## vtable 不可混淆

對 0x00C53F44（file offset 0x00852544）逐 DWORD 讀取：+0x00=0x00839D70、+0x04=0x0083A120、+0x08=0x0083A130、+0x0C=0x0083A250、+0x10=0x0083A570、+0x14=0x0083A5A0。與 callback vtable 0x00C4FF8C 完全不同。

```cpp
Core* create(ManagerHandle* h, void* context) {
  Core* c=(Core*)allocate(0x470);
  c->vptr=0xC53F44;
  c->field_EC=context;
  /* multiple embedded subobjects + allocated container sentinels */
  h->core=c;
  ensureCallback(h);
  return c;
}
```

這是概念性偽碼：0x839940 尚未完整還原所有 exceptional paths；核心配置確定，容器語義部分暫定。

## 已確認／待驗

已確認不同配置大小及 vptr、+0xEC 來源、+0xF0/+0x134/+0x178 三個子結構初始化、0x90-byte 三次分配。未知是否與 22 桶持有者相同，不能把 +0xEC 與 +0x98 錯認成同型別欄位。下一段 115 沿 0x007D1310 的 owner 實參追查。