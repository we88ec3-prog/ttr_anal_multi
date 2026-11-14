# MEF runtime contracts：排程、解除、UI 與 VM

對應 [主報告](../20261115-065342-chatgpt-web-roy1-MEF-runtime-contracts.md)。本輪開始於 **2026-11-15 06:53:42 Asia/Taipei**，沿用 `extra/roy1`；研究 parent `a16841ac67638da4b29605f186f355722e8cf106`，導航 main `ba5f96dfa94d734cbded291fb8887f50426bfa77`。

**原始 Coroutine body 的證據缺口已解除。新 `.mef` 正常首次載入 caller 仍未閉合，完整遊玩串接維持階段性未完成。** 本包新增的重點是已到達之工作的實際執行與收尾契約，不能將 bytes 重驗 PASS 當成端到端遊玩成功。

## 1. 分題

| 分題 | 新增且可重驗的結論 | 覆蓋範圍 |
|---|---|---|
| [scheduler](scheduler/report.md) | 找回既有 Coroutine carrier；`doCoTask` 不轉交 End callback；wait 毫秒／先 yield；resume、移除與 alive 的差異 | 完整 Coroutine 2,168 bytes／13 prototypes／187 words；qbase／TutorialBase 選定 bridge；1 個原始 seq 範例；55 個 native windows |
| [input-lifecycle](input-lifecycle/report.md) | Q 的兩層輸入限制；End 再設等待鎖；既有 00EB 解除；13 個 direct caller 接回 scene／binding 來源 | 208 records、77 code windows；64 個初始 Q bindings；13 caller／11 init hooks；21 組 vtable／RTTI |
| [ui-lifecycle](ui-lifecycle/report.md) | F4355 先切 pending 再向 current page dispatch；固定效果是 UI hide；F4322 是 wait dialog tag | 66 records、45 code windows；6 組 vtable／RTTI；5 組 switch 選取 |
| [vm-lifetime](vm-lifetime/report.md) | 正式與 prepass 所有權、29 個 guarded construction sites、25 個 caller EH maps；collection reset 不等於新 VM | 352 records、292 code windows；8 個函式 target／15 個 literal target 的有限 census |

records／windows 包含局部指令、重疊範圍、資料表；**不能加總為互不重複函式數**。各分題分別保留動態 callback、table 改寫、alias、失敗分支及 wire framing 的具體界線。

## 2. 原件與來源

直接原件為 `02-Tartaros.bin`、`06-Event.stp`，以及自既有 Git carrier 恢復的 `Coroutine.lua`。本輪沒有執行 Client／Lua，沒有改原始資源，沒有重新上傳一份原始 Coroutine 或完整 seq。

Coroutine 的既有來源在 `kr/evidence/c3feac03a40d24a54adf7615781cab175aa4876a2bdad8763987e413d0c2a808.txt`；它雖名為 `.txt`，內容是 2,168 bytes 的原始 Lua chunk。身分與歷史鏈見 [scheduler/provenance.json](scheduler/provenance.json)。不能用偽碼或文字摘要替代該輸入進行原件重驗。

[source-manifest.json](source-manifest.json) 保存本輪基準、共用指示與四個分題的 manifest pins；各分題自己的 manifest 保存精確 commit／path／Git blob／hash 與 read set。導航只供定位，BIN／STP／chunk bytes 才是語義依據。source tree pin、實際全文讀取、optional 工作副本重新比對分開記錄。

[artifact-manifest.json](artifact-manifest.json) 保存主稿及整包交付檔的 SHA-256。為避免循環，不雜湊它本身與統一重驗輸出；兩者仍由實際 Git tree 固定。UI／input 另保留各自的交付 manifest。

## 3. 統一唯讀重驗

需要 Python 3、Git、可解碼 i386 PE 的 GNU objdump，以及 repository 已發布的 `MEF-parser-executor-storage-20261114/verify_evidence.py`。

```sh
python -B kr-extra-roy/MEF-runtime-contracts-20261115/verify_evidence.py \
  --originals /workspace/scratch/b43c6175f310/project_sources \
  --repo /workspace/scratch/b43c6175f310/ttr_anal_multi \
  --coroutine /absolute/path/to/the/original/Coroutine.lua
```

`--coroutine` 指向原始 2,168 bytes。若完整 checkout 已含上節既有 carrier，便可省略該參數。另兩個目錄參數依實際工作區替換。

統一重驗會：

1. 核對交付檔 hash 與固定來源 Git tree identity。
2. 執行四份分題的唯讀 verifier，重新讀取原件 bytes、Lua operands／CFG、指令及資料表。
3. 額外用 objdump 檢查 scheduler native code windows 的完整指令尾端，避免 bytes 雖相同卻從截斷指令解讀。
4. 檢查本包 Markdown 的證據連結；稀疏 checkout 未出現的舊文件，僅接受已在研究 parent tree 的確切 path，不自動抓取。

Git 子程序停用 lazy fetch、optional locks 和互動 prompt。缺少必要 Git object 或原件時應明確失敗，不能自行下載後冒稱仍是純唯讀重驗。

結果見 [verification-result.json](verification-result.json)。分題自己的採集結果也保存；input／UI 的 source-content count 包含採集時 scratch 中的導航全文。統一重驗不附帶那些副本時，會據實顯示未重新提供導航內容，而固定 tree pins 與原件仍須通過。

## 4. 實作判斷

已可按精確契約規劃／實作有限內容的版本匯出、前置收集、正常結束、取消與 Server 狀態管理。Server 需求包括相容發布、執行代數／去重、合法 End 後解除、換場順序及權威結果保存。

仍不能宣稱新 `.mef` 自動掛載、active Q 可無干擾作為普通戰鬥常駐 runner，或完整戰鬥事件／entity identity 已接通。條件式 `.seq → DoFile(.mef)` 設計尚需真實可達且符合專案允許範圍的內容橋接。

主報告區分了已解決的證據缺口、Client 待逆向項目、Server 開發需求和後續 runtime 驗收。此包不更新 RR／owner／共用完成狀態，也不主張 T01 FULL-PASS。
