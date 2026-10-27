# T10-17 — FB9004 input-state writer Xref 核驗

來源：2026-10-27 Asia/Taipei；KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，12,472,320 bytes。PE .text VA 0x401000 ↔ raw 0x400；BIN 唯讀，objdump i386 Intel 靜態反組譯。地址為 VA；未命名類型及 C++ 語義暫定。不執行／修改目標。

## 機器碼位址掃描
BIN .text 中 0xFB9004 的 4-byte little-endian literal 命中七處：0x54895A、0x6D0876、0x6D1B03、0x6D4A9D、0x6D4B6C、0x6D4CB0、0x6D4D9B。0xFB9014 命中五處：0x547293、0x6D088A、0x6D1B17、0x6D4AB1、0x6D4B80。注意以上是 immediate 常數的位元組位址，不是每筆指令起始地址，且不涵蓋 register-base alias、DLL、其他映像或動態指標。

## 已核實指令
- 0x6D4A93 xor eax,eax；0x6D4A9C mov [0xFB9004],eax；0x6D4AB0 mov [0xFB9014],eax，屬批次清零。
- 0x6D4B69 xor eax,eax；0x6D4B6B mov [0xFB9004],eax；0x6D4B7F mov [0xFB9014],eax，再次清零。
- 0x6D4C20 mov esi,[edi+8]；0x6D4C23 lea ecx,[esi-0x2711]；0x6D4C29 cmp ecx,0x270E；0x6D4C7C mov byte [eax+0x10],0；0x6D4CAE mov byte [esi+0xFB9004],0。後者是索引寫零，並非 keydown 的非零 writer。
- 0x6D4D93 cmp esi,0x27；0x6D4D98 movzx eax,byte [esi+0xFB9004]；0x548957 movzx eax,byte [esi+0xFB9004]；0x54895E cmp eax,1：兩者為 read，不是 write。

## 本階段證據與新邊界
已確認輸入儲存體被清零、按索引讀取、擴展鍵在另一樹結構中處理。未找出 normal event 寫入非零 phase 1/2/3 的程式路徑。僅精確 absolute literal 搜尋不能用於否定間接 writer。0x6D4C20 清零支線與 getter 對 index 範圍的 gate 不同，仍需追上游限制。Z 是否等於 FB9014、鍵碼是否對應 0x5A、500ms 是否是普攻窗口，均未確認。

## 下一段
展開 0x5961C0 主迴圈與 0x596140 keyed interception，分清 state==1／3 的分派與服務對象。