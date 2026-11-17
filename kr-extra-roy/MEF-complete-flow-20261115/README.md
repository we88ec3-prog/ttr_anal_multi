# MEF 完整流程研究證據包

本包對應 [完整主稿](../20261115-060700-chatgpt-web-roy1-MEF-complete-flow.md)，保存 2026-11-15 06:07:00 Asia/Taipei 開始的續查。工作分支為 `extra/roy1`，研究 parent 為 `67021e609f56e45981aecf45533bdad084039a47`；本輪查核的 main 為 `909754f28bd2e54c8ede00e3a56021cf59facd14`。

**狀態：階段性未完成。** 資源取得、parser／executor、既有腳本生命週期與指定換場順序已有新增原件證據；原生正常流程如何首次選中並執行新 `.mef` 仍未有正向 caller。驗證器的 PASS 只適用於明列的原件、指令窗、資料及來源 pin。

## 1. 分題與用途

| 分題 | 主要新增證據 | 包內查核規模 |
|---|---|---|
| [resource-gates](resource-gates/report.md) | package／ordinary 分流、限制與 prefix owner、真實 MD5 provider、lookup／比較／probe 的差異 | 39 records；22 個 code windows；38 個指定 literal hits、12 個 direct callsites |
| [parser-executor](parser-executor/report.md) | 底層 text／binary parser、memory reader、直接 execute caller 及其實際 callable 來源 | 125 records；78 個 code windows；18 個有限 target；20＋4 個 execute callsites |
| [native-aliases](native-aliases/report.md) | MapList root 保存值跨冷分支、virtual target／receiver writer 與覆寫位置 | 198 records；150 個 code windows；29 個覆寫點、20 個 virtual bindings |
| [script-lifecycle](script-lifecycle/report.md) | numeric status／MULTRET、錯誤後流程、Lua 重入／父子工作／skip、兩階段內容契約 | 3 個 STP 成員；93 個 prototypes；1,536 個 instruction words；255 個 CALL／TAILCALL 來源；16 個新增 native windows |
| [scene-cancellation](scene-cancellation/report.md) | `005F` 真正 receiver、old exit／delete、new install／init、controller 與 UI queue | 60 records；35 個 code windows；6 個 vtable／RTTI；選定窗內 125 direct／34 indirect CALL |

各包統計的 window 或 source 可以重疊，**不能相加後稱為互不重複函式數**。導航偽碼僅供定位；native-aliases 中未重新讀取內容的導航項明列為 tree metadata pin，沒有冒充本輪讀過所有偽碼。

## 2. 原件與來源

本輪直接使用 `02-Tartaros.bin` 與 `06-Event.stp`。身分、大小、SHA-256、固定的來源 commit／path／Git blob 以及來源角色見 [source-manifest.json](source-manifest.json)。各分題另外保存詳細 read set；Lua 只重讀選定 3 個成員，沿用既有 S00 對其他 loader 的有限結論。

[artifact-manifest.json](artifact-manifest.json) 保存本次主稿、分題與重驗程式的檔案大小及 SHA-256。為避免自我雜湊循環，該表不包含它自己及統一重驗輸出；兩者仍受實際 Git commit 的 tree／blob 固定。parser 與 scene-cancellation 另附各自的交付 hash 表。

`sources/`、導航工作副本、建包腳本與原始 BIN/STP 不隨本包提交。缺少的 `Coroutine.lua` 內部 body、動態 callback、沒有閉合的首次載入 caller 等界線都保留在分題與主稿中。

## 3. 統一重驗

需求為 Python 3、Git、支援 i386 PE 的 GNU objdump，以及本 repository 已發布的 `MEF-parser-executor-storage-20261114/verify_evidence.py`。這是原件靜態重驗，不啟動 Client，也不執行 Lua。

```sh
python -B kr-extra-roy/MEF-complete-flow-20261115/verify_evidence.py \
  --originals /workspace/scratch/b43c6175f310/project_sources \
  --repo /workspace/scratch/b43c6175f310/ttr_anal_multi
```

使用其他工作目錄時替換兩個絕對路徑。若採稀疏 checkout，reference 文字可以透過 `--reference-text-cache <JSON>` 提供；格式為 `{ "repo-relative/path": "原始完整文字" }`，內容仍須符合來源 pin，不能用摘要代替。沒有可讀 reference 時，script-lifecycle 會在結果中明列 `NOT_READ`，不冒稱全文已核。

統一驗證檢查：

1. 原件與交付檔案 hash、來源 Git tree entries。
2. 五份分題的 bytes、原件解碼、有限 candidate sets、明列的 contract anchors 與選定 Lua operands。
3. 額外以 objdump 重新解碼 script-lifecycle 的 16 個新 native windows；各 code window 都多讀最多 15 bytes，再檢查真正的完整 instruction endpoint。
4. 本包 Markdown 的本地證據連結。

本輪實際統一執行結果見 [verification-result.json](verification-result.json)。各分題既有結果也保留原查核環境；例如 scratch 中曾核對的導航原文副本沒有提交，重驗時其 optional count 可為 0，固定 source tree pins 與原件仍須通過。

## 4. 完成與未完成的界線

本輪可提供開發用的路徑／bytes 契約、numeric status、雙 VM／yield 限制、指定失敗與取消順序，以及 Server 發布／排程／完成狀態需求。`.seq → DoFile(.mef)` 是有條件的新內容設計，未修改原資源、未宣稱是原生既存 caller。

本包不主張新 MEF 已接通，不替代執行與遊玩驗收，不把 source pin 或有界 bytes PASS 提升成 T01 FULL-PASS／RR ACCEPTED，也不以 Server 業務規則未知作為 Client 逆向的假阻塞。
