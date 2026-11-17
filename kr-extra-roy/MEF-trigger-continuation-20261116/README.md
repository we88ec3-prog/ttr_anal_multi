# MEF R13：互動點兩種觸發與重用／重進狀態

本包接續 [R12 完整互動點流程](../20261116-MEF-checkpoint-lifecycle.md)，補上前次中斷前未提交的 **mode0/非零觸發、+0x104 內部範圍狀態、最近有效候選選擇及再入限制**。完整繁中證據見 [主報告](../20261116-MEF-trigger-mode-continuation.md)。

[證據](evidence.json) 包含 12 段原件 BIN VA/raw/hex；[驗證器](verify_evidence.py) 會核對 KR SHA、PE32 section mapping 及節錄 bytes；[驗證結果](verification-result.json) 保存本輪重核。重跑：

```bash
python -B verify_evidence.py --bin /path/to/Tartaros.bin --evidence evidence.json
```

此報沒有證明 `point+0x104` 的 Lua getter；它只是 native 進出範圍狀態。亦不虛構官方 MEF 檔格式、Server-only 規則、按鍵編碼或新封包。只讀驗證不能代替 T01 FULL-PASS／Server 實作／遊玩驗收。本次僅改 `extra/roy1` 自有分析目錄，不發佈原始 BIN／EXE／STP。
