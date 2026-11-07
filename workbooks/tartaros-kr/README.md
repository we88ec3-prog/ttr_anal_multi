## 主要閱讀入口：功能開發規劃

2026-11-07更新：v34接入爾勒梅斯村Q133～144候選流程，90正流程合成通過、實機待測，正式結算／獎勵未完成。功能檔保留原章節分頁與ID：Q133～142在ST02，Q143／144在ST03（仍屬第2村出村段）；詳見各表的新說明與當前S00索引。銀行／裝備／商店／掉落撿取依使用者要求排在本村主線之後。

使用者已要求以功能與任務分頁管理進度，新的[開發功能總表與93份功能檔](functional-roadmap/README.md)放在functional-roadmap/。總表統計各功能；各功能第一張清單統計子功能，後續每任務／技能／內容各一頁。此新格式依使用者要求為多Sheet，原有19份分類台帳保留供證據與正式資料查詢。

# Tartaros KR — 分類工作台（S00 維護）

本目錄保存 **Tartaros Online KR** 的分析／Server 開發工作台；不含 TC 或 Asgard Online。首次整理日期：2026-11-02。原有19份分類台帳的每份 `.xlsx` **只有一個 Sheet**，同一分類固定存於同一個檔案，供 S00 後續原檔增量編輯，並非每次刪除重建。

## 收錄項目

- `00_儀表板.xlsx`、`01_功能總表.xlsx`、`02_封包總表.xlsx`、`03_封包欄位.xlsx`、`04_玩家流程.xlsx`、`05_Server開發.xlsx`、`06_測試驗收.xlsx`、`07_遊戲資源.xlsx`
- `08_研究證據.xlsx`、`09_研究請求.xlsx`、`10_Server需求.xlsx`、`11_規格索引.xlsx`、`12_缺口索引.xlsx`、`13_研究Task.xlsx`、`14_Server待辦.xlsx`、`15_來源清單.xlsx`、`16_人工補充.xlsx`、`17_版本來源.xlsx`、`使用說明.xlsx`
- `manifest.json`：首次資料來源、內容計數與覆蓋限制；`S00_工作台維護交接_20261102.md`：完整維護規則；`S00_Excel_增量更新.py`：讀取兩個本機 Git checkout 的正式資料，對既有 XLSX 依穩定 ID 作更新。

## 初版資料邊界（請勿誤判為原版完整證據）

初版逐筆收錄 `research/claims/index.json` 的 **189 筆 CLM ID** 與 `research/intake/index.json` 的 **653 筆 SRC ID**，但完整 claim assertion／limitations 與 SRC 的全部 SHA／路徑須由增量同步程式再補齊。`02_封包總表.xlsx` 的 **32 筆**與 `03_封包欄位.xlsx` 的 **55 筆**都只是已收錄候選，**不是原版 Client 封包全集**。

GitHub `main` 上的正式 RR、REQ、SPEC、GAP、CLM、SRC、TEST 台帳仍為唯一權威；此處是視圖與人工註記，不得從工作台反向提升研究驗證、規格成熟度、Server 可玩性。`S00` 負責整合 Server 需求與規劃；`T01` 審核原生證據；`T02`～`T16` 持續補證；`ttr_server_roy` 獨立管理 Server 實作。原版 Server-only 未知列為 Server 待開發需求，Client 必需 wire/parser/UI 未知列為 Client 待逆向。

## 全欄位同步（2026-11-02）

本次已依最新 main 同步正式資料：CLM189、SRC653、RR10、REQ9、SPEC7、GAP9、TEST6、KR Task16、Server SFD9，共908筆。更新11份既有工作簿；其他8份（含人工補充）保持原檔不變。

既有可讀欄位就地更新，表格右側新增 `正式JSON:<key>` 欄位，逐一保留來源記錄的所有原始欄位。陣列／物件使用完整 JSON；缺少欄位為空白，明確 null 為 `null`。超過單格限制的欄位分成 `(1/n)` 至 `(n/n)`，依序接合即可還原。完整欄位不等於全文原生驗收或實際可玩。

本次來源：分析 main `ee6e3f22b35b9053d38dfbfb3538d7030522bd43`；Server main `69c714c54fb5c802251736ee38ff37c19fba3c53`。版本中立的共用 Server 需求亦保留，明確 TC 記錄不納入 KR。

## Windows 增量更新

先確認兩個乾淨的 main checkout 已 `git pull --ff-only`。不要切換或覆寫其他研究工作樹；本次使用既有 main 分支的隔離工作目錄，未建立額外分支。

更新器保留 Python 資料來源讀取及 CLI，改由 JavaScript `@oai/artifact-tool` 修改現有 XLSX；不再需要 Python `artifact_tool`。使用 Codex bundled Node 與套件。先在本次執行目錄建立 `node_modules` junction，指向依賴載入器提供的 bundled node_modules，勿修改依賴資料夾。

```powershell
python .\workbooks\tartaros-kr\S00_Excel_增量更新.py `
  --workbooks .\workbooks\tartaros-kr `
  --analysis-dir . `
  --server-dir 'E:\Tartaros\ttr_server\ttr_server_roy' `
  --require-main `
  --node '<bundled node.exe 絕對路徑>' `
  --runner-dir '<本次執行目錄，含 node_modules junction>'

python .\workbooks\tartaros-kr\S00_workbook_verify.py `
  '<同一執行目錄>' --promote
```

第一步只匯出暫存候選，第二步以標準庫獨立核對已存檔資料、來源 JSON、既有 ID 列、未授權變更、樣式與工作表控制後，才備份並替換原檔，留下 `update-history/*.json`。人工摘要／備註與來源已不見的舊列保留。相同執行紀錄不可重複發布，以免覆寫原備份。更新器不會提交或推送 Git，也不改正式台帳／Server／Client。

**注意**：01功能、02封包、03欄位、04玩家流程、05Server開發、07資源仍屬人工核對視圖；這次未憑新台帳臆造內容。32筆封包與55筆欄位仍是候選清單，全集枚舉未完成。後續維護見 [全欄位同步紀錄](S00_全欄位同步_20261102.md)。

## 歷史首次基準

- 分析／規劃 `ttr_anal_multi`：`ac6aac673426459df2a778d20a80c623b8559a92`
- Server `ttr_server_roy`：`69c714c54fb5c802251736ee38ff37c19fba3c53`

首次發佈至 GitHub 不會修改上述原始分析資料，也不會自動建立新 Task、改變 RR 狀態或覆蓋 Server。

## 已知驗收結果補登（2026-11-02）

[驗收回填紀錄](S00_驗收回填_20261102.md)：HP流程8項指定修改工作副本通過、4項部分驗證、2項未涵蓋、1項尚未通過，另新增1項進村待開發。既有26個Server正流程合成案例另外彙總；6筆正式TEST未在本次重跑。未修改原版Client尚未驗收。這是既有證據補登，不是本次新增遊戲測試結果。

## 2026-11-04 main整合後同步

已依分析main d552852448d63755e55f97c314486c6b07e7f723及Server main a3478089164d24eeaec75839ee5c5b86cb36aad7，同步11份既有工作簿：CLM189、SRC762、RR10、REQ20、SPEC7、GAP9、TEST6、KR Task16、SFD13。保留人工備註／ID列／公式／樣式／sheet控制；獨立存檔驗證後才發布，來源與欄位清單見 update-history/20261104-002455.json。原始備份留在本機，不納入Git。

更新器修正為僅格式化各正式JSON欄，避免跨過夾在中間的人工欄位。第一次候選因06表人工欄W5樣式改動被檢核攔截，未覆寫；修正後完整保留檢核通過。功能規劃的人工進度與未測項目不因台帳同步升格。Server v18的28項合成正流程結果見當前S00整合報告，不等於正式6個TEST或真人驗收已全數通過。

## v19 進村旅程與最新玩家回報同步

依分析main 7bd1e72e0、Server main f6c1b171132365d94c9026605f4f5ad0ed81920d增量同步11份正式資料視圖；REQ20的runtime observations目前37筆，加入v18移動抖動／方向＋Z仍不能移動回報。更新與獨立存檔驗證收據為update-history/20261104-013756.json。另修正儀表板A2/A3仍顯示初版日期／舊SHA的來源標題，改為目前同步SHA與收據；本輪保留人工資料與樣式檢核見update-history/20261104-014004.json。

v19的30個HappyPath合成案例涵蓋至爾斯梅勒村的敘事旅程，真人待測、正式獎勵與EXP等仍待補；功能人工進度與6筆正式TEST未升格。移動問題保持待修。完整範圍與測試入口見governance/s00-iterations/S00-20261104-ALSMEER-STORY-CONTINUATION.md（相對repo root）。

## v20與明日Web派工同步（2026-11-04）

11份正式視圖依分析main fb6a78bf26fdfacdd5bc28ffcb1b63b011487307、Server main89504aa646a9a0039dc125fe0c61c4aafcceab1f完成存檔獨立驗證與發布，收據update-history/20261104-021501.json。REQ20目前runtime39、player/admin19，新增NPC距離、登入廣場／主線保存、MEF60%後再查等使用者需求。人工資料／ID／公式／樣式保留；6項正式TEST及功能人工進度未升格。v20正流程30項合成通過49秒、真人待驗收。原Web材料ZIP只在本機，不納入Git；W1/W2/W3提示詞見research/handoffs/s00-web-server-definitions-20261104/（repo root）。

## v34與正式資料同步（2026-11-07）

依分析main `a01b6f5c2e5ad3f11a801dd3bd04f34a30e55911` 與Server main `13bffdc967956140de1f1155e5221a88e31990de`，11份既有正式視圖完成全欄位同步，收據[20261107-205921.json](update-history/20261107-205921.json)。CLM189、SRC802、RR10、REQ21、SPEC7、GAP9、正式TEST6、KR Task16、SFD16。既有ID、人工欄、公式、樣式及工作表控制獨立存檔驗證後才替換，備份留本機。

更新器另修正正式表A2/A3數量與版本標題，避免表內已是21筆但表頭仍說9筆。正式TEST6未因90項HappyPath合成結果升格。ST02/ST03只回填本輪已接的場景／接續及合成測試，正式接取／目標／交付維持開發中、獎勵待開發，人測不變。全93份功能檔與總表獨立核對：4748細頁、45500步驟列、公式錯誤0；已實作子步驟257，人測通過仍19。這是既有拆分粒度的比例，不是Server工時或原版完整度。
