# Tartaros KR — 分類工作台（S00 維護）

本目錄保存 **Tartaros Online KR** 的分析／Server 開發工作台；不含 TC 或 Asgard Online。首次整理日期：2026-11-02。每份 `.xlsx` **只有一個 Sheet**，同一分類固定存於同一個檔案，供 S00 後續原檔增量編輯，並非每次刪除重建。

## 收錄項目

- `00_儀表板.xlsx`、`01_功能總表.xlsx`、`02_封包總表.xlsx`、`03_封包欄位.xlsx`、`04_玩家流程.xlsx`、`05_Server開發.xlsx`、`06_測試驗收.xlsx`、`07_遊戲資源.xlsx`
- `08_研究證據.xlsx`、`09_研究請求.xlsx`、`10_Server需求.xlsx`、`11_規格索引.xlsx`、`12_缺口索引.xlsx`、`13_研究Task.xlsx`、`14_Server待辦.xlsx`、`15_來源清單.xlsx`、`16_人工補充.xlsx`、`17_版本來源.xlsx`、`使用說明.xlsx`
- `manifest.json`：首次資料來源、內容計數與覆蓋限制；`S00_工作台維護交接_20261102.md`：完整維護規則；`S00_Excel_增量更新.py`：讀取兩個本機 Git checkout 的正式資料，對既有 XLSX 依穩定 ID 作更新。

## 初版資料邊界（請勿誤判為原版完整證據）

初版逐筆收錄 `research/claims/index.json` 的 **189 筆 CLM ID** 與 `research/intake/index.json` 的 **653 筆 SRC ID**，但完整 claim assertion／limitations 與 SRC 的全部 SHA／路徑須由增量同步程式再補齊。`02_封包總表.xlsx` 的 **32 筆**與 `03_封包欄位.xlsx` 的 **55 筆**都只是已收錄候選，**不是原版 Client 封包全集**。

GitHub `main` 上的正式 RR、REQ、SPEC、GAP、CLM、SRC、TEST 台帳仍為唯一權威；此處是視圖與人工註記，不得從工作台反向提升研究驗證、規格成熟度、Server 可玩性。`S00` 負責整合 Server 需求與規劃；`T01` 審核原生證據；`T02`～`T16` 持續補證；`ttr_server_roy` 獨立管理 Server 實作。原版 Server-only 未知列為 Server 待開發需求，Client 必需 wire/parser/UI 未知列為 Client 待逆向。

## Windows 更新（從已同步的 main checkout 執行）

先將本 repo 與 `ttr_server_roy` 的本機 `main` 分別 `git pull --ff-only`，再在分析 repo 根目錄使用：

```powershell
python -m pip install artifact_tool
python .\workbooks\tartaros-kr\S00_Excel_增量更新.py `
  --workbooks .\workbooks\tartaros-kr `
  --analysis-dir . `
  --server-dir ..\ttr_server_roy `
  --require-main
```

上例 `--server-dir` 請按實際本機路徑替換。此程式只修改本機既有檔案、建立備份與 `update-history/`，**不會自動提交 Git**；S00 應核對差異和原版 Client 真實驗收後，依使用者明確授權提交。

**注意**：更新器只會同步官方機器台帳及 Server SFD 的既有對應欄位；封包、角色流程、Server 實作摘要等非機器來源資料仍需 S00 另外核對證據後人工增量修訂。先更新正式資料並不等於實際 Client 連線測試已通過。

## 歷史首次基準

- 分析／規劃 `ttr_anal_multi`：`ac6aac673426459df2a778d20a80c623b8559a92`
- Server `ttr_server_roy`：`69c714c54fb5c802251736ee38ff37c19fba3c53`

首次發佈至 GitHub 不會修改上述原始分析資料，也不會自動建立新 Task、改變 RR 狀態或覆蓋 Server。
