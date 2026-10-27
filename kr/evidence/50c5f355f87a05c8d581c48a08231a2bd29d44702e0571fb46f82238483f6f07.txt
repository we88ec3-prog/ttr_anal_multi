# T08-109：Callback vtable 註冊及上游

研究者：chatgpt-web roy。2026-10-27 Asia/Taipei。BIN SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91（本輪已用 sha256sum 驗證）；原始 x86 objdump 機器碼一級證據，函式名稱暫定。

## 新證據
0x00799840：管理器+0xA0 為空時配置4 bytes callback，將 vptr=0x00C4FF8C 寫入 callback[0]，再寫到 manager+0xA0。manager+0x9C 另為參與者指標集合，逐筆調用參與者 vtable+0x10。

~~~asm
00799844 cmp DWORD PTR [esi+0xa0],0
0079984E push 4
00799850 call 0x891268
0079985C mov DWORD PTR [eax],0xc4ff8c
00799866 mov DWORD PTR [esi+0xa0],eax
0079986C mov ebx,[esi+0x9c]
00799880 mov eax,[ebx]
00799882 mov ecx,[eax+edi*4]
00799887 mov eax,[edx+0x10]
0079988A call eax
~~~

按 .rdata 映射 vptr 0xC4FF8C 的 4 個槽：+0x00=0x007D12E0；+0x04=0x005F5D10；+0x08=0x005F5D10；+0x0C=0x007D1310。此確證 0x007D1310 是 callback 的虛函式，不代表它的 owner 參數必定來自全域桶。0x007D12E0 改寫 this 的 vptr 為 0xC0F878，按傳入參數 bit0 可釋放本體，符合 deleting destructor 類形態。

上游：0x007AAD9F 在 ESI=0x00FB76A8 下呼叫 0x007997A0；0x007997A0 後續呼叫 0x00799840；0x007AAE20 對 0x00FB76A8 呼叫 0x007998A0。

~~~cpp
if (!mgr->callback_A0) { auto* cb=allocate(4); cb->vptr=0xC4FF8C; mgr->callback_A0=cb; }
for (auto* p : mgr->participants_9C) p->virtual10();
~~~

已確認：配置大小、vptr、函式槽、管理器註冊鏈。待驗：callback 0x007D1310 由誰調用，其 owner 實參是否指向全域22桶。下一段 110 追取得多型介面。