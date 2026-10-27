# KR T10-15 — 多鍵消費與命令 0x22 送出邊界

來源：KR Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；.text VA 0x401000/raw 0x400；2026-10-27 Asia/Taipei。BIN 唯讀靜態反組譯，不執行遊戲。函式語義與 C++ 名稱均暫定。以下為可獨立理解的技術筆記；更長的逐址組語另在同名本地原稿。

## 新觀察
`0x54883A,0x548852,0x548864,0x548876` 分別測試四個不同位址 FB9015、FB9016、FB9017、FB9018 是否為 1。符合時依次傳參數 1、2、3、4 至 `0x50C640`；另 `0x548888` 測試 FB901B，符合條件時根據 actor 狀態設定局部 byte 0x80。

`0x50C640` 使用 `slot=ecx+arg*16`，檢查 slot+0xC 非零及 slot+4 非零，再做查樹與其他 gate；可行時組成 WORD 0x22、BYTE index 與來自 slot+8 的 DWORD，透過 `0x50CAC0` 交給網路類 virtual +0x10。故不能把四個鍵位址解釋為同一 Z 的四次普攻段數。

### BIN 錨點
```asm
54883A cmp BYTE PTR [0xFB9015],1
54884D call 0x50C640
548852 cmp BYTE PTR [0xFB9016],1
54885F call 0x50C640
548864 cmp BYTE PTR [0xFB9017],1
548871 call 0x50C640
548876 cmp BYTE PTR [0xFB9018],1
548883 call 0x50C640
50C64D shl esi,4
50C652 cmp BYTE PTR [esi+0xC],0
50C65C cmp DWORD PTR [esi+4],0
50C6BE mov ecx,0x22
50C6C8 mov BYTE PTR [ebp-6],bl
50C6CB call 0x50CAC0
50CAC0 cmp DWORD PTR [0xFBA798],0
50CAD4 push 7
50CAD7 push 0
50CAD9 call eax
```

### 證據級別
已確認：四獨立 state source、slot index、0x22 request packing、virtual sender delegation。尚未驗證 0x22 的伺服器語義、四個鍵的實際 XML 映射、此路徑是否涉及攻擊；不把 command number 當作遊戲名稱。

## 提交來源和可重現性
BIN 使用原本 PE .text section 映射；每個地址均為 VA。上述組語是逐址節錄；完整連續片段保留在該段獨立本地原稿，遠端版不是逐字的本地長版替身。