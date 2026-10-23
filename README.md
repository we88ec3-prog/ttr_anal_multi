# Tartaros 可遊玩流程分工資料

2026-10-24：既有成果整理版完成。原生功能仍有缺口；本輪沒有執行遊戲或新增原生逆向分析。

## 入口

- [KR：15項任務](kr/README.md)
- [TC：15項背景／缺口任務](tc/README.md)
- [接續導覽](HANDOFF.md)、[AI工作規則](AGENTS.md)
- [完成報告](REPORT.md)、[詳細統計](REPORT.json)
- [使用與重現步驟](REPRODUCE.md)
- [T08 實體生成與移除](exports/kr-T08-release.zip)
- [T09 關卡內移動與同步](exports/kr-T09-release.zip)

ZIP位於本機exports，預設不提交Git；從Git下載者可用下方命令自行匯出。

## 本版內容

完整盤點原始anal的105,962檔、31.129 GiB。選入來源412檔，按SHA去重後407份；所有未選檔案的SHA、位置與排除原因亦已保存。原anal未修改。

KR／TC各15項任務，124筆狀態紀錄、104個方法項目。方法數不是有效函式總數；未分派項目先認領再分析。選入內容仍有166份版本歸屬不充分，保留unclassified。

## 使用

Python 3.10+，僅標準函式庫。在本目錄執行：

```powershell
python shared/handoff.py verify
python shared/handoff.py query --version kr --task T08
python shared/handoff.py export --version kr --task T08 --out exports/kr-T08-new
```

對AI可說：「先讀README、AGENTS與kr/tasks/T08，接續KR T08；核對來源SHA與AI替代標記，先認領範圍，不執行遊戲。」

原始Tartaros.bin不隨包提供；新分析需另外取得shared/targets.json指定SHA的原檔，以及REA/Ghidra。閱讀與校驗不需要原anal。證據.txt保留原始內容，包含歷史腳本，不能直接執行。

## 驗證與限制

T08/T09已完成獨立解壓、禁止原anal與目標執行檔讀取、任務查詢、文件連結檢查及竄改偵測。詳validation/release-tests.json。

這證明有限成果包可攜，不代表全部歷史證據閉合、原生規則已完整還原或遊戲可玩。每項task.json保留缺口；台版不套用韓版結論，保護殼保持停止。最新frame-dispatch保留原階段未驗收限制。

完整壓縮清單：shared/manifests/source-inventory.complete.jsonl.gz；納入／排除：dispositions.jsonl.gz；選入映射：source-map-v2.json。舊檢查點保存在history，Git預設排除它與可重新生成的ZIP。
