# W00-063 — 索引清零 writer 的 gate 校正

原 T10-063 把 reader 的 `ESI<=0x27` gate 推及 writer `0x6D4CAE`：**撤回這個未經本 writer 支持的界限**。

```asm
6D4C20 8B 77 08             mov esi,[edi+8]
6D4C23 8D 8E EF D8 FF FF    lea ecx,[esi-2711h]
6D4C29 81 F9 0E 27 00 00    cmp ecx,270Eh
6D4C2F 77 51                ja 6D4C82
6D4C5D ...                  ; 範圍內 -> FDF630 tree 查找
6D4C7C C6 40 10 00          mov byte [eax+10h],0
6D4C82 ...                  ; 範圍外 -> FB7C14 lazy-init
6D4CAE C6 86 04 90 FB 00 00 mov byte [esi+FB9004],0
6D4CB5 8B 3F                mov edi,[edi] ; next entry
```
writer `6D4CAE` 的直接可達分支來自 `uint32(ESI−0x2711)>0x270E`，在 `6D4C82→6D4CAE` 之間**沒有** `ESI<=0x27` guard。上游 entry 生成/容器規則可能另限制值域，故**不宣稱實際越界、攻擊或可利用漏洞**。W00 bytes asserts `063_branch_to_unguarded`、`063_store` PASS；`[0x6D4C20,0x6D4CB5)` SHA256 `b2efec561007f06d23cc0712c3463c83ae102cf6471d66b8a1aa268e6b789c73`。reader 獨立觀察仍保留；需用相同 writer CFG 重新複驗。

---

**來源與完成界線：** KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`.text` 的 raw=VA−0x400C00、`.rdata` 的 raw=VA−0x401A00。保留舊稿 `kr-temp-roy/20261028-022217-chatgpt-web-roy-T10-063-indexed-reset-list-partition.md` 與 Git blob `82b83636f00ded1be14216c7529a686fad331a16`，正式 T01 通知 `T01-RETURN-T10-063-001`；另於同目錄提供 30 bytes asserts / 11 hashes 機讀文件。狀態是**勘誤已提出／待 T01 原生語意複驗**，非 RESOLVED、FULL-PASS、原版 Server 規則或已可玩。未修改原始 Client、T11 owner、正式 RR/S00 台帳或其他 Task 原稿。
