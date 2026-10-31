# W00-007 — runtime input merge WORD store 位址修正

**撤回**原 T10-7 將 `0x5467F1` 稱為 WORD store 的指令定位。BIN 證明 `5467F1` 是輸出 pointer load，真正寫入在 `5467F4`：

```asm
5467E0 E8 6B 03 00 00  call 546B50
5467EC E8 5F 05 00 00  call 546D50
5467F1 8B 55 10        mov edx,[ebp+10h] ; WORD* 指標
5467F4 66 89 1A        mov word [edx],bx ; 真正 16-bit store
5467F7 85 F6           test esi,esi
5467FB 8A 4C 24 0D     mov cl,[esp+0Dh]
5467FF 8B 55 0C        mov edx,[ebp+0Ch] ; 另一個指標
546802 0B C7           or eax,edi
546804 88 0A           mov byte [edx],cl
546806 0B C6           or eax,esi
```
`546804` 的 byte output 指標不同於 `5467F4` 的 WORD output，不能誤併。原三路 OR / input priority 等獨立主張**不因地址勘誤自動失效，亦未因此全文通過驗收**。W00 `007_pointer_load`、`007_word_store` bytes asserts PASS；`[0x5467D8,0x546810)` SHA256 `645af756a5a51d9d896bea1fe3a56a6dce27f08602708912afca697f59766388`。

---

**來源與完成界線：** KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`.text` 的 raw=VA−0x400C00、`.rdata` 的 raw=VA−0x401A00。保留舊稿 `kr-temp-roy/T10/20261027-191139-chatgpt-web-roy-T10-7-runtime-input-merge.md` 與 Git blob `d99588c94a6647acffb036ef497b66377d22e200`，正式 T01 通知 `T01-RETURN-T10-007-001`；另於同目錄提供 30 bytes asserts / 11 hashes 機讀文件。狀態是**勘誤已提出／待 T01 原生語意複驗**，非 RESOLVED、FULL-PASS、原版 Server 規則或已可玩。未修改原始 Client、T11 owner、正式 RR/S00 台帳或其他 Task 原稿。
