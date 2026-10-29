# T06 地圖與場景資源對應

<!-- S00-DISPATCH-BOOTSTRAP:v1 -->
## S00 跨 Task 收件／認領／回報開工檢查（正式）

**TC T06 每次開工必讀**：先同步最新 origin/main，閱讀本 README／T01 原有退回與 task.json，再查看 [T06 S00 收件箱](../../../research/dispatch/inbox/T06.md)、[唯一 RR 台帳](../../../research/requests/index.json) 及 [認領回報規則](../../../research/dispatch/README.md)。**只認領 `owner_task=T06` 且 `client_version=tc` 的請求**；可用 `python -B research/dispatch/dispatch.py show T06 --version tc`。認領需經 GitHub main 發布才有效；完成分析需附 Markdown/精確 blob SHA、SUBMITTED，再交 T01/S00 審查。不得套用 KR 位址、改寫歷史原稿或自動升格 FULL-PASS。


狀態：background-only-native-evidence-missing；負責人未認領。

## 範圍

地圖 ID、資源查詢及資源版本；不推定波次與 MEF 執行器

不重新實作遊戲規則、不執行目標；其他任務的核心函式僅引用

## 已有成果與缺口

- **資訊缺失**：台版缺乏對應遊玩功能的原生證據；不得套用韓版位址或結論。保護殼分析維持停止。
- **待補充開發**：取得原生依據後才能列出實作規格；目前不授權自行補值。台版缺乏對應遊玩功能的原生證據；不得套用韓版位址或結論。保護殼分析維持停止。

## 依賴、接續與驗收

依賴：版本共用證據。先核對SHA及更正，再認領具體方法；其他主責任務只引用。

- 僅整理既有資料；本輪不繼續解殼。
- 列明每項原生/部分/AI替代/缺失/待開發狀態與證據
- 交付已查範圍、缺口和遊玩影響，不以候選數或偽碼量驗收

## 證據

- [TC-UNPACK-FILE-INVENTORY-20261019.json](../../../unclassified/evidence/7490cbd7a808d648016d5fcc40efc21271412f0d343422801b43ab4cf7d46098.txt)
- [native-index/tc-analysis-paused-20261018.json](../../../unclassified/evidence/808031dfb8747466ccbcd5ce354606a85e5a4e5baa30ddbfd1c312a042d7f5f5.txt)
- [native-index/tc-mef-evidence.json](../../../tc/evidence/87c7644ca5c7f006faff01b86e7420cabeb7f7dffd3bc289c029350a9e5ae6cd.txt)
- [TC-MEF-RESOURCE-COMPARISON.md](../../../tc/evidence/d8ea7aa54df7ffdcabfe6110e49cf2f6c67939919e9c04fee1709d26e932510a.txt)
- [TC-STAGE10-CREATEFILE-DISK-RESOLVER-20261018.md](../../../unclassified/evidence/e58dfdfc8e3529affc1dee7574b99ddc8ce3c3e34c0d0feef389780f194b2477.txt)

舊報告與腳本只供審核，不直接執行；未打包歷史引用見task.json。部分原生證據不等於功能可玩驗收。
