# MEF R14：Tutorial 提示點到 Lua 續行

[完整繁中主報告](../20261116-191747-chatgpt-web-roy1-MEF-tutorial-observation.md)｜[Server／內容開發交接](server-handoff.md)

本包接續 R13，閉合既有教學腳本中的「建立提示點→角色位置／映射輸入→category4 writer→控制器 progress→Lua getter→關點／下一段演出」。point+104、point+105、controller progress 是三份不同狀態。原版 API 已知部分復用 R11–R13，新增 producer/consumer、原版 Lua 操作與重用條件。

## 證據與重跑

- `native-evidence.json`：24個選定code window的VA、raw、長度、SHA256與指令數，15個關鍵hex節錄、4個data窗口、13個字串、14條direct call。完整window的bytes不重複序列化，可按原件與固定範圍重建；主稿有關鍵組譯與資料流。
- `resource-evidence.json`：四個STP member的物理位置與hash、11段選定Lua字與必要常數、少量XML屬性；不包含完整解包member。
- `source-manifest.json`：原件身分、既有Git來源及公開範圍。
- `verify_evidence.py`：Python 3與GNU objdump，唯讀檢查；不執行Client/Lua/Server，不連網或修改倉庫。
- `verification-result.json`：本輪實際stdout結果，synthetic cases僅是依原件推導的有限狀態模型。

```bash
python -B kr-extra-roy/MEF-tutorial-observation-20261116/verify_evidence.py \
  --bin /path/to/Tartaros.bin \
  --event /path/to/Event.stp \
  --table /path/to/Table.stp
```

不可用Python -O略去斷言；程式會拒絕。驗證器讀原件的明確member，不搜尋新MEF檔案，不輸出完整原Lua/XML。使用者須自行提供固定原件，Git沒有原始BIN/EXE/STP。

## 適用界線

結果限已證Tutorial controller/context；沒有宣稱普通場景可任意使用所有教學API。官方MEF首次自動載入／grammar仍未閉合，PASS不是T01 FULL-PASS、RR ACCEPTED、Server完成或遊玩驗收。Server權威戰鬥、交易與保存可保留，不要求全部移交MEF。

此包沿用既有extra/roy1；父提交89698a074cf9edde8a6da9e3f40002bbef8b32e3，main核對03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc。未修改其他Task、owner、Client或Server。本輪未重跑舊R11–R13全部驗證器；其來源復用與本輪新原件核對分開記錄。
