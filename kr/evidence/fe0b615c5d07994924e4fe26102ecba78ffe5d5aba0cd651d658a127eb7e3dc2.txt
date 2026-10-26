# T08 第七十四段：Type 1 元件的事件 8 狀態判斷鏈

分析者：chatgpt-web roy
核對時間：2026-10-27 02:23:55 Asia/Taipei (+0800)
原始樣本：Tartaros.bin，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91
原始依據：本機 objdump -d -Mintel 核對地址 0x004C7200–0x004C72E0、0x004CB2C0–0x004CB350、0x004C9ED0–0x004C9F32、0x004CB230–0x004CB2C0；直接讀取 PE .rdata vtable 指標。

## 1. 0x004CB2C0 是 Type 1 元件的 vtable +0x08

在 0x004C7282–0x004C7296：
```asm
004C7282 lea ecx,[esi+0x01]
004C7285 mov esi,[ebp-0x10]
004C7288 mov eax,ebx
004C728A call 0x004CB230
004C7291 mov ecx,0x01
004C7296 mov DWORD PTR [eax],0x00C0779C
```
0x004CB230 把 ECX 類型寫到 component+0x08，owner 指標寫到 component+0x04，之後建構器使用這個類型索引登記到 owner+0xF4+4*type。
.vtable 0x00C0779C：+0x00=0x004CB8E0，+0x04=0x005F5D10，+0x08=0x004CB2C0，+0x0C=0x005F5D10。
因此該事件狀態轉換函式是 **Type 1 vtable+0x08**，不同於 Type 3 的事件 7 方法以及 Type 4 的事件 8 方法。

## 2. 0x004C9ED0 遍歷 owner+0x3F4 狀態樹

```asm
004C9ED1 mov esi,[ecx+0x3f4]
004C9ED7 mov edx,[esi]
004C9ED9 xor eax,eax
004C9EDB cmp edx,esi
004C9EE0 test BYTE PTR [edx+0x13],0x1
004C9EE4 jne 0x004C9F2A
...
004C9F2A mov eax,0x1
004C9F2F pop esi
004C9F30 ret
```
樹節點 +0x15 用作哨兵判斷；符合節點位元旗標時回傳 1，無符合時回傳 0。暫命名 HasFlaggedStateNode，並無證據等同 HP=0 或死亡。

## 3. Type 1 狀態轉換器的事件 8 條件

```asm
004CB2C7 mov eax,[ebx+0x04]       ; owner
004CB2CA mov ecx,[eax+0x15c]      ; resource
004CB2D2 mov edi,[eax+0x38c]      ; prior event
004CB2DB test ecx,ecx
004CB2DF cmp DWORD PTR [eax+0x370],0
004CB2E8 mov esi,[ecx+0x11c]      ; resource field
004CB2F2 mov ecx,eax
004CB2F4 call 0x004C9ED0
004CB2F9 test eax,eax
004CB2FB je 0x004CB320
004CB2FD test esi,esi
004CB2FF je 0x004CB49E
004CB305 mov ecx,[ebx+0x04]
004CB308 fld1
004CB30C mov edx,[eax+0x68]
004CB313 push 0x08
004CB315 call edx
```
只有 HasFlaggedStateNode(owner)!=0 且 resource+0x11c 非零才進入該事件 8 分支；目前不能以此推論死亡語意。

## 4. 值得繼續追查

- 誰把 owner+0x3F4 狀態樹節點的 +0x13 bit0 設為 1，何時清除。
- 哪個函式透過 Type 1 component vtable+0x08 調度 0x004CB2C0。
- owner+0x15C 資源 +0x11C 指向何種資料；是否對應動作/特效狀態。
- 是否存在與 HP 更新或命令 26 直接相連的證據。

此次僅新增獨立分析筆記；未修改原始 PE 或其他 Agent 的目錄。
