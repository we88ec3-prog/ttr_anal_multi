# 商城獨立資料夾改名

2026-11-19 使用者要求啟動 Server／管理端供測試，並指出商城資料夾不應使用
TC（繁中）名稱。這次只調整商城工作副本路徑及配套，其他開發維持暫停。

目前使用 `Mall/CashProducts.xml`，新主程式為
`Tartaros.ip-zh-tw-only-v2-mall-v2.exe`，SHA256
`76fc40da6e277ab1d683a410c475383545b67d97b5913771abf1610fff70d2e0`。
仍從指定原 v2 衍生，只修改同一個等長檔名字串；15 個 bytes 不同，其餘全部
bytes 相同。原版、指定 v2、mall-v1、舊 TC_Mall 與所有 STP 皆保留。
第一次 Mall XML 與現用 CashProduct member 逐 byte 相同，未套用隔離測試價。

載入鏈、普通 XML、singleton 重啟與原有校驗索引邏輯沿用
[既有有界來源](../../governance/client-variants/20261119-cash-external-files/README.md)。
本次另核對未修改的 Integrity.xml 不含 `mall/cashproducts.xml`，沿用既有
index-miss 路徑，未更動校驗規則。沒有執行／附加 Client。

管理端配套改輸出 `client/Mall/CashProducts.xml`，manifest 明列所需 mall-v2
EXE 與 SHA，發布說明也同步。舊包的 TC_Mall 路徑屬 mall-v1，不混用。
啟動器的 `-UseExternalMallClient` 選擇 mall-v2，並依 Mall 路徑核對配對 XML。
Server 仍保留舊版 EXE 精確 SHA 的既有准入；未放寬為任意檔案。

隔離 HTTP 正流程核對 ZIP 路徑、EXE manifest、同版下載一致及既有價格／列表
投影不變。建置、HappyPath、服務 PID／健康與資料保留結果見
`mall-folder-validation.json`。新工作副本的 Client 實機仍待使用者驗收。
