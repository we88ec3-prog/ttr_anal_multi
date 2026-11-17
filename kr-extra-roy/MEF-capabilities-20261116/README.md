# `.mef` 能力與完整流程證據包

本包將研究焦點落在**內容可以編排哪些功能、如何正確呼叫、需要哪些資料，以及 Server 應完成哪些配合工作**。完整結論見 [主稿](../20261116-113220-chatgpt-web-roy1-MEF-capabilities.md)，開發交接見 [server-handoff.md](server-handoff.md)。

工作分支為既有 `extra/roy1`；直接承接已公開 R10 `af97bbd29c892e031eef7a3bc3a98cb79f1be729`。main 基準 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc` 已在其祖先鏈中。本輪不建分支，不修改正式 RR／REQ／Task 狀態。

## 如何閱讀

| 文件 | 用途 |
|---|---|
| [capability-catalog.md](capability-catalog.md) | 逐項查閱 121 個正常註冊名稱能做的事、限制與證據。涵蓋 Q、Tutorial、lb、Prolog、CameraWorks、ScenarioTalkTable、Fade 七個選定 namespace。 |
| [capability-index.json](capability-index.json) | 同一份目錄的機讀版本，保留 root／call site／registrar／slot／closure／native／name VA tuple。 |
| [helper-catalog.md](helper-catalog.md) | 原版 qbase 全部 75 個頂層函式的 prototype／參數／global 讀取導覽，區分空 helper 與只 yield 的 loading helper。 |
| [audiovisual/report.md](audiovisual/report.md) | KeyFrame 的實際進度與相機套用、相對座標、角度／距離、音樂 stream、音效、Fade 與擷取畫面轉場。 |
| [dialogue-ui/report.md](dialogue-ui/report.md) | 頭像多句對話、序章文字／語音、固定書本、字幕、數字／Miss／Block 面板、擊殺與 Critical 字樣。 |
| [world-npc/report.md](world-npc/report.md) | 世界 NPC 建立、Q 角色動作、CDoll 外觀工作佇列、互動點、原生商店／強化與資產更新。 |
| [control/report.md](control/report.md) | 教學與 scenario 編排、UI 顯示／固定頁面、map→BOUND 小地圖、計時與輔助入口。 |
| [flow-contract.json](flow-contract.json) | 內容／發布／入口／prepass／排程／效果／觀察／收尾／Server 續接的機讀流程；標示原件已證行為與條件式設計。 |
| [integration-review.md](integration-review.md) | 跨組人工審查、已修正的具體語意與保留界線。 |
| [source-manifest.json](source-manifest.json) | 固定原件身分、main／公開父稿、直接 Git 來源與發布範圍。 |
| [artifact-manifest.json](artifact-manifest.json) | 本次實際交付檔案完整清單、大小及 SHA-256。 |
| [verification-result.json](verification-result.json) | 總控實際唯讀核對結果，包含四組子結果、來源與去重後原件統計。 |

121 是這七個正常 static registration surface 的**介面名稱數**，包含 alias、stub 和有條件能力，不是 121 種獨立玩法或整個 Client API 總量。75 個 helper 是原 qbase root 的全部 closure exports；其直接讀取 globals 並不等於完整呼叫圖。

原生 `_MapList.TRIGGER` 到第一個 `.mef` loader／官方格式／executor 的未閉合部分仍明列。相容內容的可達 caller 與合法 context 依既有證據設計，不能以副檔名代替。普通戰鬥全面替代 Server 不屬本包的共同驗收門檻。

## 重跑核對

準備固定 Git objects，以及 `source-manifest.json` 所列原件。原件資料夾包含 `02-Tartaros.bin`、`01-Tartaros.exe`、`06-Event.stp`、`07-Table.stp` 與提供的 `09-02-PROJECT-SHARED-INSTRUCTIONS.md`；核對程式不下載原件。

```bash
python -B kr-extra-roy/MEF-capabilities-20261116/verify_evidence.py \
  --originals /path/to/project_sources \
  --repo /path/to/ttr_anal_multi
```

總控會核原件身分與固定 Git provenance、完整發布 allowlist、121 個 binding 的真實註冊指令、75 個 helper 導覽、各能力的證據路徑、流程分類及相對 Markdown 連結，再實跑四組 verifier，確認輸出與已保存結果一致。重疊 native 窗口逐 byte／指令比對並另算去重數量，避免重複片段被當成新增覆蓋。

本輪已另外實跑未變更的 R10 總控，結果保存在 [previous-r10-verification.json](previous-r10-verification.json)。預設比對它與固定公開 R10 結果；加 `--recheck-r10` 可再跑一次 R10，但不遞迴重跑已保存的更早輪次。個別子包的 CLI 及 selected member 讀集見各分題報告。

工具使用 Python 標準函式庫、GNU objdump 及本機 Git。這次環境的 Python／objdump 版本記在對白子結果；不同 disassembler 或 runtime 版本可能改變格式化輸出，不能只因工具差異改動原件／證據以湊成 PASS。

所有核對程式只讀原件、節錄證據與本地 Git objects，不 fetch、不修改 Git、不執行 Lua／Client／Server，不編譯或產生遊戲資源。stdout 為實際 JSON 結果。PASS 證明的是已列來源、位元組、結構與契約一致性，沒有代替 native 語義形式證明、T01 FULL-PASS、RR ACCEPTED、Server 實作或遊玩驗收。

## 公開交付

依使用者已給的授權，僅發布分析 Markdown、必要原件節錄 JSON／ASM、資料統計／索引／契約、來源 pins 與唯讀驗證器。原 BIN／EXE／STP、完整解包 member、完整 parsed scratch、工作中間檔與可部署遊戲內容均未納入。詳見 [publication-note.md](publication-note.md)。
