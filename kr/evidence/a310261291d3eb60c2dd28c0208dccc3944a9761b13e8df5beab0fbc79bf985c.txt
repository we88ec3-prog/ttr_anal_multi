# T08-110：0x0079A5F0 多型介面取得

研究者：chatgpt-web roy。2026-10-27 Asia/Taipei。BIN SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91（本輪已用 sha256sum 驗證）；原始 x86 objdump 機器碼一級證據，函式名稱暫定。

## 新證據：介面從 manager+0xEC 取得

0x0079A5F0 的首參數是指向管理器指標的位址；若其指向 NULL 則回傳0。非NULL時檢查 once bit 0x00FB79E8，必要時呼叫 0x00798DE0 初始化，再讀取 [0x00FB76A8] 管理器的 +0xEC。若該欄非NULL，呼叫其 vtable+0x04；接著從 [EDI] 呼叫 vtable+0x08，最後回傳EDI。

~~~asm
0079A615 mov eax,[ebp+8]
0079A61A cmp DWORD PTR [eax],edi
0079A61C jne 0x79a633
0079A61E xor eax,eax
0079A630 ret 4
0079A649 call 0x798de0
0079A662 mov esi,[0xfb76a8]
0079A668 cmp DWORD PTR [esi+0xec],edi
0079A670 mov eax,[esi+0xec]
0079A678 mov edx,[ecx+0x4]
0079A67C call edx
0079A67E mov edi,[esi+0xec]
0079A684 mov eax,[edi]
0079A686 mov ecx,[eax+0x8]
0079A68A call ecx
0079A68C mov eax,edi
0079A69E ret 4
~~~

0x007D13A7 呼叫此函式，0x007D13BE 以回傳介面調用 vtable+0xE4；0x0079B52D 也呼叫此函式，其回傳介面上有 vtable+0xD4/+0xCC 派送。不能將此介面 vtable 跟場景物件 vtable 0x00C07554 合併。

~~~cpp
Interface* acquire(Manager** h) {
 if (!*h) return nullptr;
 initOnce();
 auto* iface = (*(Manager**)0x00FB76A8)->field_EC;
 if (iface) iface->virtual04(iface);
 iface->virtual08(iface);
 return iface;
}
~~~

已確認：查詢流程、一次性初始化、下游 dispatch references。合理推測：圖形調度介面。未確認：具體 vtable 目標與真實 C++ 類別。下一段111 驗證 bucket owner 來源。