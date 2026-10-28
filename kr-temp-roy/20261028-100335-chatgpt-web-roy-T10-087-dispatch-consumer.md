# T10-087 — MapButton 13–16 phase dispatch、vtable 消費端邊界

研究標的：KR Tartaros.bin（SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，已本機驗證），PE32 .text VA 0x401000/raw 0x400；靜態 objdump -D -Mintel，未執行目標。

## 原始 x86

~~~asm
005961ed mov eax,ebx
005961ef call 0x761010
005961f4 xor edi,edi
0059623b cmp DWORD PTR ds:0xfb73e8,edi
00596245 mov esi,edi
00596247 mov BYTE PTR [ebp-0xe],0
0059624b mov [ebp-0x24],edi
0059624e call 0x6d4ce0
00596253 cmp BYTE PTR [ebp-0xf],0
00596257 je 0x596267
00596259 cmp edi,0xd
0059625c je 0x596267
0059625e cmp edi,0xe
00596261 jne 0x596386
00596267 cmp eax,0x1
0059626a jne 0x5962bc
00596273 mov edx,DWORD PTR [ecx]
00596275 mov eax,DWORD PTR [edx+0xec]
0059627b push edi
0059627c call eax
005962bc cmp eax,0x3
005962ce mov eax,DWORD PTR [edx+0xf0]
005962d4 push edi
005962d5 call eax
006d4d93 cmp esi,0x27
006d4d96 ja 0x6d4dae
006d4d98 movzx eax,BYTE PTR [esi+0xfb9004]
~~~

## 已確認資料流與限制

EDI 是迴圈 ID，透過 ESI=EDI 以非標準寄存器參數傳入 0x6D4CE0。MapButton ID 0..39（包括 13..16）會取得普通 phase byte。phase 1 與 3 通往不同 vtable byte offsets +0xEC/+0xF0，並有 0x761010 返回候選子物件優先及 this fallback 的條件路線；沒有確立 class/vptr 實址前不能命名 OnAttackPress / Release。

0xFB73E8 非零時，0x596259..0x596261 在此派送函式只放行 ID13/14；不表示全域停用 ID15/16。0x596201 附近另看候選物件 +0x28 bit13，須區分這個物件欄位與其他函式 +0x28 欄位。

0x6D4DC0 是配置 bank 查詢；由全 .text 搜尋直接 call 找到 0x594672、0x5946CB、0x59471B、0x5947FD、0x59484D、0x59492F、0x59497F、0x594CD4、0x594DC4、0x594EB4、0x594FA4、0x595094、0x595184、0x595274、0x595364、0x595454、0x595544、0x595634、0x595724、0x595814、0x595901、0x5959F4、0x5CD68A、0x5CE5BA、0x62B5BA、0x650E96、0x650F48、0x650FF6、0x6510A4。這只是直接 xref 清單，不是各 caller 的語義判決；T10-82 將 0x594610 部分鏈限定在 UI/文字用途。

兩條鏈之間仍缺 scan code→映射→**非零 phase writer** 的機器碼直接證明。沒有 Z 連按、V tap/hold、queue/cancel 的原版時窗證據；AI CHAIN_WINDOW=.65 不是原生規則。只讀分析，不修改其他 Task。