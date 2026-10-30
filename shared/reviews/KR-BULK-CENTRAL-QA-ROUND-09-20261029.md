# KR Bulk QA 第九段 — JSONL 前置驗證加強（2026-10-29）

狀態：**PARTIAL / NOT FULL-PASS**。工作分支 `extra/roy2`。

## 來源與問題

第八段 `kr_bulk_preflight.py` 在索引非空且兩個目錄存在時就回報 `PREFLIGHT_ONLY_READY_FOR_FULL_AUDIT`，即使索引只有一行 `{}`。這種「ready」容易被誤讀為符合真實資料前提。

本段修改工具為 v2：對索引逐行讀取並計算 SHA256，同時記錄實際行數、唯一地址、JSON 損壞、來源 SHA 不符、非法地址、重複地址，只有所有結構檢查通過且行數達到預期 111054 才回報 ready。**預期行數是既有 T01 凍結批次的記錄，用於預檢，不是新掃描得到的統計**。

## 驗證及邊界

在本地以同邏輯的測試版本執行 9 種 fixture，結果 **9/9 passed，0 errors**，涵蓋缺檔、缺目錄、空檔、有效資料、行數不足、重複地址、壞 JSON、來源 SHA 不符、非法地址。本地測試版本與 GitHub 提交版存在程式排版及測試模組載入方式差異，**不聲稱已對提交 blob 位元組逐一執行測試**；正式 GitHub 版本需由完整 checkout 執行 `python -m unittest discover -s shared/reviews/tools -p 'test_kr_bulk_preflight.py' -v`。

目前容器 `git ls-remote` 仍回報 `Could not resolve host: github.com`，GitHub connector 無法完整讀取大型 `index.jsonl`。因此未執行 111054 筆正式資料檢查，無真實行數分布、缺檔或雜湊差異統計。

## 改動

- `shared/reviews/tools/kr_bulk_preflight.py`（新 schema `kr-bulk-preflight-v2`）
- `shared/reviews/tools/test_kr_bulk_preflight.py`（9 個 fixture 定義）
- 本技術報告及跨 Task 導覽

## 待解決

1. 具完整 checkout 的環境執行 v2，保存 index SHA、實際行數及任何例外。
2. 前置檢查只有 index 結構層級，仍需接續 `bulk_integrity_audit.py` 做逐引用檔案 SHA256。
3. 最後才由 T01 按精確原生主張進行 FULL-PASS；索引完整不代表遊戲函式語意完整。
