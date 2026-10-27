# KR T10-13 — 間接索引輸入狀態的清零與讀取

來源：KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；.text VA 0x401000/raw 0x400；2026-10-27 Asia/Taipei。BIN 唯讀靜態反組譯，不執行遊戲。函式語義與 C++ 名稱均暫定。以下為可獨立理解的技術筆記；更長的逐址組語另在同名本地原稿。

## 新增結論
0x6D4C20 遍歷容器，從 [edi+8] 讀出鍵值 esi。當 (esi-0x2711)<=0x270E（無號比較）時，以 0x82EF00 查 0xFDF630 所屬的樹並把找到節點的 +0x10 byte 清零；否則在 lazy initialization gate 之後執行 `mov BYTE PTR [esi+0xFB9004],0`。這是實際的間接 indexed writer，但證明的是**清零**，不是生成 pressed/held 的非零事件。

另一函式 0x6D4CE0 在擴展鍵值範圍走上述樹 lookup、讀 node+0x10；一般鍵值則先 `cmp esi,0x27`，僅對索引 0..39 以 `movzx eax,BYTE PTR [esi+0xFB9004]` 讀取；非法索引返回 0。因此與 T10-9 的「只找到直接 FB9014 寫入引用」並不矛盾：先前掃描確實漏了帶 index 的間接地址。

### 組語錨點
```asm
6D4C20 mov esi,[edi+8]
6D4C23 lea ecx,[esi-0x2711]
6D4C29 cmp ecx,0x270e
6D4C2F ja 0x6D4C82
6D4C6C call 0x82EF00
6D4C7C mov BYTE PTR [eax+0x10],0
6D4CAE mov BYTE PTR [esi+0xFB9004],0
6D4D05 lea eax,[esi-0x2711]
6D4D0B cmp eax,0x270e
6D4D5D movzx eax,BYTE PTR [eax+0x10]
6D4D93 cmp esi,0x27
6D4D98 movzx eax,BYTE PTR [esi+0xFB9004]
```

### 證據界線
已確認兩種 backing source 與索引讀／清零。清除分支不具與 getter 相同的 <=0x27 check，尚須核對上游傳入值的限制；不能斷言安全接受任意 key 值。Z 在陣列第幾項、哪裡把值設成 1/2/3、何時消費作普攻仍未知。

## 提交來源和可重現性
BIN 使用原本 PE .text section 映射；每個地址均為 VA。上述組語是逐址節錄；完整連續片段保留在該段獨立本地原稿，遠端版不是逐字的本地長版替身。