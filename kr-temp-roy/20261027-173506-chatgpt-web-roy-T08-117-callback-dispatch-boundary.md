# T08-117 — Callback dispatch and pointer identity boundary

研究者：chatgpt-web roy；2026-10-27 Asia/Taipei。
一級來源：原始 Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，本輪重新核對。ASM 直接取自該 BIN 的 x86 反組譯。本 GitHub 筆記為完整研究結論與關鍵證據版本，本機另有較長的逐行 ASM 附錄。

## 新分析
T08-113 確認 vptr 0x00C4FF8C 虛槽 +0x04=0x005F5D10，+0x0C=0x007D1310。必須分清兩個 virtual slots。0x00799840 於 manager-handle+0xA0 為 NULL 時配置 4 bytes callback object；+0x9C 是另一個容納 participant pointers 的結構。

~~~asm
00799844 cmp DWORD PTR [esi+0xa0],0
0079984E push 4
00799850 call 0x891268
0079985C mov DWORD PTR [eax],0xc4ff8c
00799866 mov DWORD PTR [esi+0xa0],eax
0079986C mov ebx,[esi+0x9c]
00799880 mov eax,[ebx]
00799882 mov ecx,[eax+edi*4]
00799885 mov edx,[ecx]
00799887 mov eax,[edx+0x10]
0079988A call eax
00799B63 mov ecx,[ebx+0xa0]
00799B69 mov edx,[ecx]
00799B6B mov eax,[edx+4]
00799B6E call eax
~~~

0x00799B6E 因此直接調用 virtual +0x04，而不是 0x007D1310；它不能視為全域桶 consumer 的 caller。0x007D1310 實際的 [EBP+8] bucket owner 尚未證實等於 [0x00FB7740]。

## 新的獨立調度路徑
~~~asm
0049255B fld DWORD PTR [ebp+0xc]
0049255E push ecx
0049255F fstp DWORD PTR [esp]
00492562 push 0xfb76a8
00492567 call 0x799d20
~~~

此上游每次送入管理器 handle 地址而非直接送入核心物件 pointer。T08-118 將從此鏈找到六係數的非初始化寫入者。後續以 caller provenance 判定 callback consumer 身分，不跨 vtable 混合 +0x04/+0x0C/+0x10/+0x18。

### 保守偽碼
~~~cpp
if (!h->callback_A0) { cb=allocate(4); cb->vptr=0xC4FF8C; h->callback_A0=cb; }
for (auto *p : h->participants_9C) p->virtual10();
// 0x7998A0 then invokes callback->virtual04(), not virtual0C().
~~~

已確認：配置、vptr、負向 caller。未確認：分桶 owner runtime identity。