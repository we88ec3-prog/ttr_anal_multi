# 使用與可重現範圍

## 接手任務（不需要原anal）

1. 讀README、AGENTS及對應kr/tasks/Txx或tc/tasks/Txx。
2. 執行 `python shared/handoff.py verify`。
3. 執行 `python shared/handoff.py query --version kr --task T08`。
4. 原始Tartaros.bin不隨包提供；若要新增原生證據，另行取得shared/targets.json指定SHA，並準備REA/Ghidra。只有閱讀、查詢及校驗不需要引擎。
5. 個人使用獨立分支、自己的分析專案。先認領再工作，回傳新增證據、局部更正、未知與遊玩影響；不要直接改其他任務的主責結論。

匯出命令：

```powershell
python shared/handoff.py export --version kr --task T08 --out exports/kr-T08-new
```

輸出路徑必須不存在；ZIP與檔案清單會自動建立。第一層依賴任務以interface-context-only標記，未展開的任務依賴會列明。

## 整理者重建（需要原始分析封存）

原始分析檔位於同層anal，保持唯讀；所有建立程式只寫anal-multi。既有原生索引不重建。

本版建立順序為 inventory / resume_inventory → build_handoffs plan → build_handoffs build → refine_delivery → add_core_evidence → finalize_catalog → handoff export → validate_release → finish_organization。各步的選擇、引用、更正與驗證均保存在shared/manifests與validation。

不要直接在已發布資料上重跑早期builder：它會覆蓋後續增量。需要完全重現時，先建立獨立輸出副本及保存本版，使用相同原始SHA資料，依序重建。refine_delivery含歷史覆寫保護。

來源新增或變更時可用resume_inventory做增量盤點；未變更size/mtime的既有SHA會重用。這是效率策略，不是抵抗刻意偽造mtime的保證。重要選入來源於收尾另重新計算SHA。

## 明確限制

- 原封存的驗證腳本以惰性.txt附帶，依賴舊目錄、Capstone與原生索引，不能在交接包直接執行。
- verify驗證打包完整性、引用ID、定位及校驗值，不證明歷史語意正確，也不代表遊戲可玩。
- 已宣告但未打包的歷史引用保留為缺口，不會為閉合所有導覽而搬入全庫。
- 台版僅背景與缺口交接；韓版也只承諾任務文件的有限範圍。
