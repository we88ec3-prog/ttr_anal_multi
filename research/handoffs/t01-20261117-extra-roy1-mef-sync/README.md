# T01：extra/roy1 → main MEF 整合檢核（2026-11-17）

本批依使用者「將 extra/roy1 同步到 main，並進行 T1 檢核」執行；T1 對應本庫 T01 整合審核。

來源 `extra/roy1@534746f194a889ebb34dda7471c2ae62d30a1dd1`，開工主線 `main@03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。主線是來源祖先，17 筆提交、608 個新增檔案可保留歷史快轉納入。未建立新遠端 branch；T01 記錄隨主線提交。

## 閱讀入口

| 目的 | 文件 |
| --- | --- |
| 看審核結果、適用邊界、Server 開發需求與延後項 | [完整 T01 報告](REPORT.md) |
| 核對 608 個原始來源的 blob／SHA256／SRC | [來源清單](source-provenance.json) |
| 重現來源、格式、PE 身份與研究封裝檢查 | [R0 收據](r0-audit.json)、[唯讀檢查工具](audit_sources.py) |
| 查看舊批次實際重跑與 parser／檔名差異 | [歷史批次檢核](history-review/report.md) |
| 查看 P0／全功能契約的獨立有界原生審核 | [P0 原生檢核](native-review/report.md) |
| 查看本輪結構檢核與完成狀態 | [整合收據](review-result.json) |

## 審核等級

R0 機械來源接收、R1 有限主張萃取、R2 關鍵反證及生命週期查證分別記錄。研究工具 PASS 表示指定輸入與範圍可重現；不自動認證整份報告、全部 native body、官方 MEF grammar、Server 實作或遊玩。

本批沒有新增 `NATIVE_VERIFIED`／共用 `FULL-PASS`，不修改 RR 接受、S00 規格成熟度、其他 Task owner 或歷史退回狀態。原始 BIN／EXE／STP／完整解包資源未加入 Git。

最新採用入口為 [P0 交接](../../../kr-extra-roy/MEF-P0-content-contracts-20261117/README.md) 與 [全功能契約](../../../kr-extra-roy/MEF-comprehensive-contracts-20261117/README.md)。歷史研究完整保留；已被反證的舊圖片模型須依勘誤處理。
