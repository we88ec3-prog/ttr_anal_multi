# Server 提供 MEF：交付與執行 profile

[完整繁中分析](report.md)｜[自製內容作者契約](authoring-contract.md)｜[發布與執行 manifest 範本](delivery-manifest.template.json)｜[機讀 profile](contracts.json)

目標是開發自製 Server MEF。可用的有限 Q、Tutorial 互動長流程、有限原生效果，依各自已證 adapter 分別實作；普通背景 B 是按玩法需求追進的擴充，官方 MEF grammar／Field.stp 不再是共同前置。

本包接合既有研究，沒有宣稱新發現傳檔 opcode 或背景 runner。最小範本以正確雙 VM guard，讓 Server 發布一份內容後，由 Client 自行 `wait→既有點 setter→End`；只存 Markdown 研究範本，不部署 `.seq`。

## 重驗

```bash
python -B kr-extra-roy/MEF-server-provided-capabilities-20261118/delivery-profiles/verify_evidence.py \
  --repo /path/to/ttr_anal_multi \
  --sources /path/to/project_sources
```

Python 標準庫與 GNU objdump；只讀原件、Git source pins、STPD／XML 與選定 Lua 指令字。結果見 [verification-result.json](verification-result.json)。不執行 Client／Lua／Server，不連網，不改 Git，不輸出完整遊戲 member。

## 證據檔

| 檔案 | 用途 |
|---|---|
| [source-manifest.json](source-manifest.json) | 30 個固定 Git commit／path／blob／hash 與 5 個原件身分；舊證據與新內容設計分開 |
| [native-proof.json](native-proof.json)、[native-proof.asm](native-proof.asm) | 22 個必要的既有 native 視窗，4,849 bytes；11 個精確錨點；標為復用重驗 |
| [resource-evidence.json](resource-evidence.json) | 11 個 member 的 hash／位置、5 組已有 selector 字面路徑、Master Event 宣告與舊 A1 候選衝突 |
| [lua-proof.json](lua-proof.json) | 8 個 qbase／Coroutine 選定片段、60 指令字；不執行、不發布完整原腳本 |
| [verify_evidence.py](verify_evidence.py) | 原件與 pinned upstream 證據對照、PE／指令邊界、資料接合與機讀狀態檢查 |

PASS 僅為有界靜態證據與契約自洽，不是新內容已發布、Server 已開發、T01 FULL-PASS 或遊玩驗收。
