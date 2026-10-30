# T01 — t03/roy/chatgpt-web → main 真正合併、R0/R2 再驗證與整合收據

- 作業日期：2026-10-30，Asia/Taipei；使用者明確要求將 T03 研究分支併入 main 並執行驗證與整合。
- Repository：we88ec3-prog/ttr_anal_multi；Client 版本：KR，不借用 TC 結論。
- GitHub PR #46：https://github.com/we88ec3-prog/ttr_anal_multi/pull/46
- 合併前 main：744ecafc2399db5907b5b0a7ba147844506c10f0
- 合併前 T03：cfeda726bde096d3d2224b0fe69a309a6266e8d6
- 真實合併 Commit：7eeb6e090c2decfae9e9d08c1d40241a8af88fa6
- 獨立查 Git API Git commit：parents 精確為 [744ecafc2399db5907b5b0a7ba147844506c10f0, cfeda726bde096d3d2224b0fe69a309a6266e8d6]，tree=464b77c3359772cf19bdd94c2e2a5ff35d5bf0ce。使用 merge 而非 squash/cherry-pick/覆寫。
- 合併前分歧：GitHub compare main...t03 ahead_by 28、behind_by 18；PR #46 clean mergeable=true。合併後 compare main...t03 ahead_by=0、behind_by=19，證明來源分支歷史都成為 main 祖先；原分支保留。
- Merge Commit 與上一版 main 的 tree 差異只新增 03-PROJECT-T03-INSTRUCTIONS.md；blob=8f3f510691089d79d1b883b15b4b0062fda2a7db，遠端 main 讀回成功。此文件是早期 T03 固定參考文件，不取代最新 AGENTS、governance、requests/index.json 或本專案 02 共用規則。

## 來源身份與主張去重（R0/R1）
- RR-0003 完整原稿：kr-temp-roy/20261030-142513-chatgpt-web-roy-T03-RR0003-KR-auth-E8-000F-13-codepage-group-handoff.md
- 分支與合併後 main 的原稿 Git blob 均為 64c8c1a3429ae6ff177a84dee0d08ad69dba0b17；原稿早已由 T01 原樣引回 main，本次 Merge 沒有替換、重編或複製出衝突版本。
- 來源登記 SRC-0473：仍是 CONFLICT_CHECKED，source SHA256=e0ac3471052dac7a0c9222ed18966e8406ff6fb24b957643cad675b7aaff6bd7，identity/reference 未變。
- 現有 CLM-AUTH-0003、0004、0005 全仍為 PARTIAL 且標 NOT_FULL_PASS；依既有 T01 有界 R2 檔案辨認 codepage/global、0x13 對 0x7A 獨立 layout、group parser 局部範圍，不新增重複 claim 或虛構原生規則。
- 保留既有 R2 記錄：research/handoffs/t01-20261030-rr0003-t03-bounded-r2/20261030-143210-chatgpt-web-roy-T01-RR0003-auth-review.md；Git blob=a64cc2e0bb1c949ab4c84db699911f0001455431。

## 第一手目標再驗證（R2 bounded，2026-10-30）
- /mnt/data/Tartaros.bin 大小 12,472,320 bytes，當次重新計 SHA256=9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。
- /mnt/data/Tartaros.exe 大小 2,594,816 bytes，當次重新計 SHA256=03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f。
- BIN .text PE raw mapping：raw=VA-0x400C00；用本地唯讀 Python 重算既有 T01 R2 的十個原始區段 SHA256，依序全部一致：440790..440830、4A31B0..4A32D0、4A3360..4A3510、47F540..47F600、4C3080..4C3160、4C3170..4C3220、4C3220..4C3280、4C37A0..4C3BA0、4C3C10..4C3C60、4957C0..495850。
- 此輪只重新核對身份與原始 bytes 摘要，並重用上列已完成之 T01 原生 R2，不宣稱重新完整複驗每一條語意、所有資料別名、call graph 或執行時封包。
- 既有有界結論：0x52 narrow E8 與 0x54 wide 000F builder 分支；全域 FBA808 起始處於 .data virtual-zero，不保證實際 runtime codepage；LOGIN scene cmd13 以 payload+0x16 取 status，cmd7A 以 payload+2 取 count、payload+6 交 group parser；4C3080 本函式沒有可見的逐 child remaining-length guard。以上皆須保留上游 guard/scene/lane/Server 時序等限制。

## RR 與正式權威狀態核對
- 合併後 main research/requests/index.json blob=ccf58e1750a4a1b7a7faccd102313d943b5a9725；research/intake/index.json blob=ec1c7e1c95feca1e4d1c6ef9481defe6dc6bbb63；research/claims/index.json blob=339d54e4bb0ebb7fdf44f69e3f93ebc2ccf0424b。合併不更動這些台帳。
- T03：RR-0002 IN_PROGRESS、RR-0003 IN_REVIEW、RR-0008 QUEUED；T01 既有 T01-RETURN-T03-006-LAYOUT-001 仍 NEEDS_FIX。RR-0003 未因 merge 變成 ACCEPTED。
- 其他：RR-0001、0004、0006、0007 IN_REVIEW；RR-0005 ACCEPTED 僅為 S00 有界接受，不代表原生 FULL-PASS。
- 未改 kr/tasks/T03/README.md、task.json、owner、catalog、S00 索引、source 原稿或任何其他 Task 工作線。
- 上一次合併前 main 744ecafc2399db5907b5b0a7ba147844506c10f0 的 GitHub Actions S00 specification registry integrity run 41016583765 為 completed/success。PR #46 merge commit 初查 Actions list 尚無該 SHA 的 run，因此不能將上一輪 CI 綠燈冒稱本次合併 commit CI 已通過；需以後續 run/check 另行確認。

## 四種狀態與後續工作
- T01 原生：SRC 與十段 native bytes R0/R2 界線正確；原稿全文仍 PENDING/PARTIAL，不進共用 FULL-PASS。
- S00 RR：維持正式台帳，RR-0003 待 S00 審核 acceptance_criteria；不得由 T01 結案。
- S00 Server 規格：SPEC-AUTH/FLOW 等只能引用有限主張，缺口不因 merge 改為 STABLE/RESOLVED；原版 Server 政策與動態 response order 仍未知。
- Server 實作／可玩：無原始 Server/wire runtime，不宣稱已開發或 Client 可玩；角色選角完整 C2S→S2C→場景切換仍屬跨 Task 補證，先依 T03 RR-0002、RR-0008 及 T05 責任界線推進。
- 後續 T03 作者須修復 WSASend OVERLAPPED / WSABUF / atomic counter 誤稱之既有 NEEDS_FIX，提供修訂稿再由 T01 重審。本合併不變更退回判定。
