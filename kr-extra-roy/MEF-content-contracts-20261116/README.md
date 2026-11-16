# MEF 第八輪證據包：內容、Q 物件與 observer 契約

主報告：[20261116-024101-chatgpt-web-roy1-MEF-content-contracts.md](../20261116-024101-chatgpt-web-roy1-MEF-content-contracts.md)。

工作 branch 為 `extra/roy1`，parent `88b22bcd750ea219bfc56580139396d0ee677644`；main 導航基線固定為 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。本包只保留選定證據與可重現驗證，不附新解出的完整原遊戲 member，不執行或修改原件。

| 子目錄 | 內容 |
|---|---|
| [bridge](bridge/report.md) | 預掃描參數／collector → 模型工作 → 正式動作依賴 → CMotion request；新內容兩階段產生規則 |
| [actors](actors/report.md) | 正式 slot／actor ID／具體 CEventActor；Create／Move／Show、duplicate、空 DeleteObject 與真正 DeleteAll |
| [observers](observers/report.md) | Q pending bit writer／tick／getter／原版 Lua consumer；Tutorial UI/state getter 的適用範圍 |
| [ordinary-runner](ordinary-runner/report.md) | 更正 checkpoint vector 的型別；普通 field／page 初始化、UI targets 與背景 Lua runner 界線 |

## 總控重驗

```sh
python -B kr-extra-roy/MEF-content-contracts-20261116/verify_evidence.py \
  --originals /path/to/project_sources \
  --repo /path/to/ttr_anal_multi
```

originals 目錄須含既有 `02-Tartaros.bin`、`06-Event.stp`、`07-Table.stp` 與 `09-02-PROJECT-SHARED-INSTRUCTIONS.md`。需要 Python 3、Git、GNU objdump 及 manifest 指定的本地 Git objects；verifier 不下載缺少的物件，也不執行 Client／Lua。

單獨重驗 bridge、actors 或 ordinary-runner 時，以該子目錄的 `verify_evidence.py --bin /path/to/02-Tartaros.bin --repo /path/to/repo` 執行。observers 另加 `--event /path/to/06-Event.stp --verify-sources`。

[source-manifest.json](source-manifest.json) 固定原件、共用指示、上游差異與各子題來源；[artifact-manifest.json](artifact-manifest.json) 核主報及交付內容。總控 [verification-result.json](verification-result.json) 與各子題結果是靜態證據一致性 PASS，**不是新 MEF 已被遊戲執行、完整世界生怪替代或 T01 FULL-PASS**。

本輪的新 `.seq → DoFile(new.mef)` 仍是有條件的新內容設計，原版 MEF 第一 caller 未因 API 存在而成立。Server 缺口在主報列為 Server 開發需求；Client 未閉合機制另列具體待分析鏈。
