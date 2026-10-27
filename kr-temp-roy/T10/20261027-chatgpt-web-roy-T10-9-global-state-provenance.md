# KR T10-9 — FB9014 來源邊界與正常事件 writer 缺口
日期：2026-10-27 Asia/Taipei。來源 KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。BIN 唯讀，PE .text VA 0x401000/raw 0x400；不執行遊戲。
## 研究問題
T10-8 要求追查 FB9014 的正常鍵盤事件寫入者。本段以 little-endian 14 90 FB 00 掃描整份 BIN，找到 raw 0x146693、0x2CFC8A、0x2D0F17、0x2D3EB1、0x2D3F80 共五個精確常數出現位置；這些是 immediate 位址位元組所在位置，非全部指令起始位址。這種方法**不能**找到經基底指標、別名、offset 或其他模組的間接存取。
## 第一手組語
```asm
6D4A93 xor eax,eax
6D4A9C mov ds:[0xFB9004],eax
6D4AA1 mov ds:[0xFB9008],eax
6D4AA6 mov ds:[0xFB900C],eax
6D4AAB mov ds:[0xFB9010],eax
6D4AB0 mov ds:[0xFB9014],eax
6D4AB5 mov ds:[0xFB9018],eax
6D4ABA mov ds:[0xFB901C],eax
6D4ABF mov ds:[0xFB9020],eax
6D4AC4 mov ds:[0xFB9024],eax
6D4AC9 mov ds:[0xFB9028],eax
6D4B69 xor eax,eax
6D4B6B mov ds:[0xFB9004],eax
6D4B7F mov ds:[0xFB9014],eax
54728E mov ecx,[esi]
547290 movzx eax,BYTE PTR ds:[0xFB9014]
547297 cmp ecx,0x3
5472A0 jmp DWORD PTR [ecx*4+0x547370]
```
以上確認兩條**批次清零**路徑及一條**相位機讀取**路徑。正常時寫入非零值的 producer 尚未定位；不可將批次清零命名為 keyup callback，也不可將 FB9014 直接命名為 Z。T10-1 所知 500 ms 是狀態相位門檻，不等於連擊窗口。
## 暫定資料流與驗證等級
```
0x6D4A93 / 0x6D4B69 -> 清零 FB9004..FB9028
未知輸入 writer -> FB9014 -> 0x547240 -> 0x546780 -> input mask
```
已確認：五個直接地址引用、清零與取值指令。合理推測：這片連續記憶體存放多個已轉換輸入狀態。未證實：按鍵碼、Z 所屬 row、間接 writer、pressed/held/released 語義。
## 下一步
展開 0xFB9004 基底指標 writer、對照實際 Table/KeyMapping.xml，確認狀態事件 producer。較長原始逐址組語另保留在獨立本地 Markdown：20261027-chatgpt-web-roy-T10-9-global-state-provenance.md。