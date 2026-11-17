# P0：兩個完整既有 Scene 的內容依賴與選檔契約

本子題承接 `MEF-comprehensive-contracts-20261117` 的資源 P0，沿用 `extra/roy1`，基準 `ac7e668ef19b91f86f05074d660aba10612c9a5f`。原件唯讀；沒有執行 Client、Lua、Server 或封裝中的程式。

**已完成兩個原始函式的全部呼叫分析與可重跑的依賴展開：Q119/3、Q2440/5。實際載體選取與完整後代資源仍為 `BLOCKED_MISSING_ORIGINAL_SOURCE`、`ready=false`。** 本包不把此差別抹平成「資源已齊備」或「原生 MEF 已完成」。

| 檔案 | 用途 |
|---|---|
| [report.md](report.md) | 原生鏈、全部所選依賴、選檔優先序、缺件解除條件、Server 增量交接 |
| [scene-dependencies.json](scene-dependencies.json) | 兩函式 108 個 body calls 的覆蓋清單、typed selector、132 個依賴節點及原生路徑／候選／缺口 |
| [dependency-frontier.json](dependency-frontier.json) | 到達但尚缺原件的節點；不能假裝完整列出 13 份缺失模型描述檔的後代 |
| [member-evidence.json](member-evidence.json) | 實際讀取 member 的 block、offset、stored/decoded SHA；不附完整解出原文 |
| [native-evidence.json](native-evidence.json) | 新的有界原 BIN 指令、字串與 vtable；既有證據的逐窗 byte 複核 |
| [source-manifest.json](source-manifest.json) | 原件 SHA/bytes、published source commit／Git blob／SHA/bytes |
| [content_audit.py](content_audit.py) | 拒絕未支援構型的全 token 靜態 parser 與依賴圖產生器 |
| [verify_evidence.py](verify_evidence.py) | 原件／Git pins／指令邊界／資料再生比對；預設只讀 |
| [verification-result.json](verification-result.json) | 實際執行的固定驗證結果；不是遊玩或載入成功證據 |

## 重跑

需要 Python 3、GNU `objdump`、含基準 Git objects 的本 repository，以及原件目錄與補充材料目錄。以下在 repository 根目錄執行；`--sources`／`--supplemental` 換成持有原件的位置。

```bash
python -B kr-extra-roy/MEF-P0-content-contracts-20261117/content-dependencies/verify_evidence.py \
  --repo . \
  --sources /workspace/scratch/3e083e35831f/project_sources \
  --supplemental /workspace/scratch/3e083e35831f/analysis/supplemental_resources/ttr
```

預設 exit 0 表示本次**有界研究可再生且證據一致**。同一命令加 `--require-ready` 應回 exit 2，因為真實 cache/mount／必要描述與 payload 尚缺；它不會修改資料來「通過」。可加 `--result /獨立scratch目錄/verification-result.json` 保存回執。

若要重生三份依賴資料，可使用 `content_audit.py` 的同組來源參數並指定 `--output`。輸出只允許本子題目錄或 repository 外、與原件無重疊的獨立目錄；不得將 source/supplemental 目錄當輸出，也拒絕輸出 symlink。產生器只寫研究 JSON，不產生遊戲資源。`-O` 不適用於驗證器，避免既有讀取器的 assertions 被停用。

## 採用界線

請同時看父包 [Server 採用規格](../SERVER-ADOPTION.md)、[ABI 採用](../abi-adoption/) 與 [owner／cleanup](../execution-lifecycle/)；這些是相容 Server 的分析輸入，沒有修改正式 REQ、RR、T01、S00 狀態。REQ-0019／REQ-0021 的版本發派、內容預驗與玩家進度遷移仍列 **Server 待開發／跨功能待整合**。
