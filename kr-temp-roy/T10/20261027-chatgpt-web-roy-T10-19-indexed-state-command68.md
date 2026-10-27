# T10-19 — 索引 28～37 的命令 0x68 與控制器分流

來源：2026-10-27 Asia/Taipei；KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，12,472,320 bytes。PE .text VA 0x401000 ↔ raw 0x400；BIN 唯讀，objdump i386 Intel 靜態反組譯。地址為 VA；未命名類型及 C++ 語義暫定。不執行／修改目標。

## 核心機器碼
0x548918 xor ebx,ebx；0x54891A lea esi,[ebx+0x1C]；0x548952 cmp esi,0x27；0x548957 movzx eax,byte [esi+0xFB9004]；0x54895E cmp eax,1；0x54897E cmp dword [0xFBA798],0；0x548985 mov ecx,0x68；0x54898A lea edx,[ebx+1]；0x54898D mov word [esp+0x14],cx；0x548992 mov byte [esp+0x16],dl；0x548998 mov ecx,[0xFBA854]；0x5489A0 mov eax,[eax+0x10]；0x5489AC call eax；0x5489AE inc esi；0x5489AF inc ebx；0x5489B0 cmp esi,0x26；0x5489B3 jl 0x548920。

## 精確迴圈範圍與更正
初值 0x1C=28，最終條件 signed less-than 0x26=38，迴圈索引為 28..37（十次），並非 28..39；前面的 cmp 0x27 是另一個 gate。state==1 時，在 0xFBA798 gate 許可下，把 WORD 0x68、BYTE (index-27) 交給 0xFBA854 的 virtual +0x10。這不是已確認的普攻十連段，也不知道實際封包服務端含義。

## 同一輸出函式的另一命令
0x5489B9 mov al,[esp+0x13]；0x5489BD test al,al；0x5489C8 mov ecx,0x7；0x5489CD mov word [esp+0x18],cx；0x5489D2 mov byte [esp+0x1A],al；0x5489D8 mov ecx,[0xFBA854]；0x5489E0 mov edx,[edx+0x10]；0x5489EC call edx。只有部分 actor/controller 狀態可提供這筆 byte，且 0x07 與 0x68 是兩個不同命令。

## 資料流模型及未解
for index 28..37: if state[index]==1 and sender gate passes -> send(0x68,index-27)。另有另一條 byte state -> send(0x07,byte)。這只是流程草圖，非原始 C++ 符號。沒有 KeyMapping.xml 內容能將其確證為 Z 或普通攻擊，也無 animation completion 的直接連結。建議下一段收斂與真正普攻 action 相關的 xref 證據。