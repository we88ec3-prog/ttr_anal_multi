# MEF 控制流程證據包（2026-11-16）

完整結論與當前進度請讀[主稿](../20261116-092138-chatgpt-web-roy1-MEF-control-flow.md)，開發交接見[server-handoff.md](server-handoff.md)。本包接續公開 R9 `ad9ea950216923b5e351a7501d38e006df57a4c6`，工作分支 `extra/roy1`，main 基準 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。

## 分題

| 目錄 | 內容 |
|---|---|
| [supervisor](supervisor/report.md) | outer／inner coroutine 的原版ABI、C-depth、yield、error、MoCo相容與取消限制；條件式新內容設計。 |
| [presentation](presentation/report.md) | End／Stop次序、camera works／snapshot、map backup、worldrender／slow、letterbox／sepia真實consumer與cleanupownership。 |
| [runner](runner/report.md) | lb／Tutorial固定binding、Skip／Scaling圖片、實際Gtick／draw／deferredcleanup，以及fixedUIevent的ordinary頁面反證。 |
| [world](world/report.md) | Q／Prolog公開面、CFlyingImage、typedPrologUI、Bookstate、原版Lua等待分支與ordinaryobserver界線。 |

[flow-contract.json](flow-contract.json)區分已證Client路徑、條件式內容設計、Server開發與未解Client依賴；[source-manifest.json](source-manifest.json)固定原件與Git來源；[artifact-manifest.json](artifact-manifest.json)固定本輪檔案清單與hash；[verification-result.json](verification-result.json)是實際唯讀重驗結果。

## 重跑

在有原件與所需固定Git物件的checkout中：

```bash
python -B kr-extra-roy/MEF-control-flow-20261116/verify_evidence.py \
  --originals /path/to/project_sources \
  --repo /path/to/ttr_anal_multi
```

原件目錄包含`02-Tartaros.bin`、`01-Tartaros.exe`、`06-Event.stp`、`07-Table.stp`與本輪提供的`09-02-PROJECT-SHARED-INSTRUCTIONS.md`。各自的大小／SHA-256見manifest。Coroutine原件沿用已有的固定Gitcarrier，不需再解包或上傳。

總控會核本輪完整inventory／hash、公開來源pins、分支基準祖先關係、相對Markdown連結、flow分類，以及四個分題verifier的實際結果。本次已另外實跑未變更的R9總控，保存於[前輪重驗結果](previous-r9-verification.json)；預設比對它與固定R9結果，加入`--recheck-r9`可再次執行R9並逐值比對。R9內已保存的R6–R8既有結果沿用，不再無差別擴大測試。

各verifier均只讀原件、證據與localGit物件，不fetch、不修改Git、不啟動Lua／Client／Server、不編譯或輸出遊戲資源。命令將JSON寫到stdout；若需保存，只將結果寫到分析輸出路徑。這種PASS不是native語義形式證明、T01 FULL-PASS、RR ACCEPTED、Server完成或遊戲驗收。

## 發布內容

本輪只提交研究Markdown、節錄JSON／ASM、來源／契約／驗證JSON與唯讀Python驗證器。原始BIN／EXE／STP、完整解包members、工作中間檔、可部署Lua／SEQ／MEF均未納入。詳見[publication-note.md](publication-note.md)。
