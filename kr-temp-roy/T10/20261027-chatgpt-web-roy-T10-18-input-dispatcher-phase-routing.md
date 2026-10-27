# T10-18 — 0x5961C0 輸入事件 tick 與虛函式分派

來源：2026-10-27 Asia/Taipei；KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，12,472,320 bytes。PE .text VA 0x401000 ↔ raw 0x400；BIN 唯讀，objdump i386 Intel 靜態反組譯。地址為 VA；未命名類型及 C++ 語義暫定。不執行／修改目標。

## 函式邊界
0x596140..0x5961B9 為獨立 helper；0x5961BC～0x5961BF 為 int3，0x5961C0 有新 prologue。僅掃描 direct E8 call 未找到 0x5961C0 呼叫者，不表示它未被 vtable/指標呼叫。

## 主要路徑的 BIN 證據
0x5961EF call 0x761010；0x596201 mov eax,[eax+0x28]；0x596204 shr eax,0xD；0x59623B cmp [0xFB73E8],edi；0x59624E call 0x6D4CE0；0x596259 cmp edi,0xD；0x59625E cmp edi,0xE；0x596267 cmp eax,1；0x596275 mov eax,[edx+0xEC]；0x59627C call eax；0x596299 push 1；0x59629D call 0x596140；0x5962BC cmp eax,3；0x5962CE mov eax,[edx+0xF0]；0x5962D5 call eax；0x596386 inc edi；0x596387 cmp edi,0x28；0x59638A jl 0x596245。

故一般鍵索引是 0..39；state 1 和 3 觸發不同 vtable +EC、+F0 的可能分支，還有 0xD/0xE 特例與 controller/owner flag gating。不可把這兩個狀態未經證實譯為 keydown/keyup。

## 0x596140 的具體攔截作用
0x59614E lea ecx,[esi+0x80]；0x59615A call 0x82EF00；0x596179 cmp eax,1；0x596183 mov eax,[edx+0xEC]；0x59618B cmp eax,3；0x596195 mov eax,[edx+0xF0]；0x59619C call eax；0x59619E test al,al；0x5961A9 xor al,al；0x5961B3 mov al,1。可見它按 key 查樹/關聯容器，沿匹配對象呼叫相位方法，返回是否有攔截者；不應直接命名為 Z 連段 callback。

## 擴展鍵分支
0x596390 test byte [0xFDF3EC],1；0x5963A7 call 0x6D1DA0；0x5963F9 mov ecx,[0xFDF624]；0x59643F call 0x6D4CE0；0x596444 cmp eax,1；0x596456 mov edx,[eax+0xEC]；0x5964E3 cmp eax,3；0x5964F5 mov eax,[edx+0xF0]。這是另一個依節點鍵值迭代的路徑，不是一般鍵陣列延伸。

## 未決事項
0x5961C0 的虛擬 owner、非零 state writer、Z 實際索引及攻擊動畫下一段的 callback 仍未知。下一段分析 0x548918 另一個索引消費者，避免混淆封包與攻擊狀態。