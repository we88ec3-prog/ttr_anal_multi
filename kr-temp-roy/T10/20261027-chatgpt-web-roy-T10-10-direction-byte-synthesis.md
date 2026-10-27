# KR T10-10 — 0x546850 四向輸入與離散角度合成
日期：2026-10-27 Asia/Taipei。原始 Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；唯讀 x86 BIN 靜態反組譯。符號名稱暫定。
## 任務
T10-7 指出 0x546780 同時消費 0x546850、0x546B50、0x546D50 的結果。本輪沿第一路展開 0x546850..0x546B45，區分方向 byte 合成與普攻 action bit。
## BIN 直接證據
```asm
5468AA movzx eax,BYTE PTR ds:[0xFB9005]
5468B6 cmp eax,ecx           ; ecx=1
5468E5 cmp BYTE PTR ds:[0xFB9005],0x2
5468EE sub DWORD PTR [ebp-0x18],ecx
546921 movzx eax,BYTE PTR ds:[0xFB9006]
54695C cmp BYTE PTR ds:[0xFB9006],0x2
546965 add DWORD PTR [ebp-0x18],ecx
546998 movzx eax,BYTE PTR ds:[0xFB9007]
5469D3 cmp BYTE PTR ds:[0xFB9007],0x2
5469DC sub edi,ecx
546A0E movzx eax,BYTE PTR ds:[0xFB9008]
546A49 cmp BYTE PTR ds:[0xFB9008],0x2
546A52 add edi,ecx
546A54 mov eax,[ebp-0x18]
546A5B mov bl,0x80
546A61 mov bl,0xA0
546A69 mov bl,0x60
546A77 mov bl,0xE0
546A7F mov bl,0x20
546A87 mov bl,0xC0
546A8F mov bl,0x40
546AE6 fld DWORD PTR ds:[0xFB8824]
546AEC fmul DWORD PTR [ebp-0x10]
546B07 add bl,dl
546B0C test edi,edi
546B10 cmp DWORD PTR [ebp-0x18],edi
546B15 xor eax,eax
546B2B mov eax,[ebp+0x8]
546B2E mov BYTE PTR [eax],bl
```
每個來源位元組為 1 或 2，對對應軸做 +/-1；組合軸的符號選擇 0x20 步距的方向位元組，隨後累加浮點量經整數轉換的 byte。兩軸均為 0 則返回 0，否則輸出 byte 並返回 1。尚未核定角度原點及單位。
## 偽碼草圖
```cpp
int x = isActive(FB9006)-isActive(FB9005);
int y = isActive(FB9008)-isActive(FB9007);
if (!x && !y) return 0;
*out = angleOctantByte(x,y)+quantizedAdjustment;
return 1;
```
isActive 對 1/2 同判成立，但不代表這兩個值在其他函式語義相同。
## 證據界線
已確認：四個實際地址、四向加減、離散角度與 byte 輸出。未確認：鍵盤上的實際方向鍵名稱、角度的正式資料型別、Z 普攻 bit、攻擊連段消費者。T10-11 繼續第二路輸入。
較長指令與分支摘錄保留於本地完整原稿：20261027-chatgpt-web-roy-T10-10-direction-byte-synthesis.md。