# S00 / T01 Phase-A 索引驗證

採 Python 3.10+ 標準函式庫，不用 REA/Ghidra，亦不要求 Tartaros 原始 Client 執行。

在儲存庫根目錄：

```powershell
python -B governance/validate_s00.py
python -B -m unittest discover -s governance/tests -v
```

**檢查的內容：**JSON schema 標頭、項目 ID 唯一、SPEC/CLM/RR/GAP/ADR/TEST/FB/SRC 跨引用、KR/TC SHA 對應、必要檔案存在、來源 blob SHA256/SHA1 校驗與收件升格門檻、STABLE 最小硬性條件、NATIVE_VERIFIED 所需證據定位欄位。未知或未完成規格應維持 DRAFT。

**不能驗證的內容：**原生機器碼語意、封包欄位真值、Client 連線相容性、Server 可運作性。機械檢查綠燈**不會產生**FULL-PASS 或 STABLE 決策。現有舊 318 版台帳與退回原樣保留。

驗證涵蓋的是新工作流索引，不是全庫每一份原稿。若準備發佈相容性規格，仍需另外人工審核來源與實際測試。若沒有本地 Python，Agent 也能透過 GitHub 讀取索引並逐筆做相同的邏輯檢查。
