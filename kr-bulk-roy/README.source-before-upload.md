# KR 本機大量反編譯（roy）

依使用者明確授權保存大量反編譯；AI token 優先，原文只存本機，按需讀取。

- 每個目標以完整 SHA256 分資料夾，禁止混用不同 EXE/BIN。
- 本輪目標為已核對的原始 Tartaros.bin，並未把 Tartaros.exe 當成相同檔案。
- `raw/` 保存 REA 原始批次結果；`functions/` 保存逐函式偽碼；`index.jsonl` 保存地址、狀態、來源及雜湊；`status.json` 保存執行進度；`journal.jsonl` 保存操作事件。
- 所有輸出均為**未審核原生工具結果／待整合**。函式候選、成功筆數及輸出量不代表語意完成率、完整原始碼或可遊玩驗收。
- `functions/*.c` 是方便閱讀的衍生文字，Windows text-write 可能轉換換行；原始偽碼字串以對應 raw JSON／seed Evidence 為準。21份初始seed的來源、輸出hash與平台文字寫入一致性已另存 `seed-verification.json`。
- 批次擷取不改變其他任務的方法主責；正式結論仍由各任務查證後增量整合。
- 原程式、anal、資源、帳號與存檔保持唯讀；只使用 Ghidra 靜態分析，不執行／附加遊戲或呼叫目標 API。
- `bulk_decompile.py` 先等待已啟動的 T06 story2 查詢正常關閉，避免同時啟動兩份 Ghidra；再列出原生函式，優先 T06 與已登記方法，按16筆批次輸出其餘 .text 內非 external／非 thunk 候選。
- 重跑會核對既有成功輸出的 SHA，跳過已保存地址；失敗有獨立紀錄。不得把失敗或略過項當成成功。

T06 接續檢查點：`../kr-temp-roy/T06/CHECKPOINT.md`。

按位址選讀（預設最多4000字元；不會啟動新反編譯）：

```powershell
python -B anal-multi/kr-bulk-roy/lookup.py 0x55d7e0 --metadata-only
python -B anal-multi/kr-bulk-roy/lookup.py 0x55d7e0 --max-chars 4000
```

尚未保存會回傳 `not-saved-yet`；成功輸出仍標為 `saved-unreviewed`。


2026-10-26 收尾：上述BIN SHA批次exec38795正常exit0、nativeclose成功、queueempty。索引111054唯一ok（含21既有seed）、0擷取失敗；不代表語意、ABI或可玩驗收。收尾稽核在kr-temp-roy/T06/evidence/bulk-acquisition-completion-review-v1.json。Tartaros.exe未納入此批。
