# MEF P0／P1／P2 續析與玩家進度

日期：2026-11-18（Asia/Taipei）。工作分支：`extra/roy1`；固定分析基準：`15d9501c203c6f656461b64f578a50c96e38a5ff`。本包接續原計畫的 **3 項 P0、4 項 P1、1 項 P2**，不新增 branch，不變更正式任務、REQ 或驗收狀態。

使用者要的是完成分析、上 Git，並用玩家能理解的方式交代各項進度。本包對八個工作項逐一給出已證事實、這輪增量、剩餘條件與下一個可驗收結果；仍缺原始材料或原生接點的能力保留未閉合。研究報告、離線驗證、Server 實作與實際遊玩分開記錄。

## 閱讀順序

| 文件 | 用途 |
|---|---|
| [PLAYER-PROGRESS](PLAYER-PROGRESS.md) | 給玩家看的 P0／P1／P2 進度及還缺什麼 |
| [COMPLETION](COMPLETION.md) | 原計畫八個工作項的逐項完成判定 |
| [REPORT](REPORT.md) | 本輪原生證據、勘誤與整合結論 |
| [SOURCE-REQUEST](SOURCE-REQUEST.md) | 精確補件、來源與每件能解除的問題 |
| [SERVER-REQUIREMENTS](SERVER-REQUIREMENTS.md) | 可立即接續的 Server 開發需求與驗收順序 |
| [REUSED-EVIDENCE](REUSED-EVIDENCE.md) | 哪些已有結論直接沿用，哪些候選不重複計算進度 |
| [status.json](status.json) | 機器可讀的八項狀態及未通過的能力條件 |
| [verification-result.json](verification-result.json) | 本輪實際執行的離線證據驗證結果 |

三份新原生分題為 [P0 資源選取](p0-selection/)、[P1 普通 UI 入口](p1-entry/)、[P2 官方格式接點](p2-format/)。檔案清單與雜湊由 [artifact-manifest.json](artifact-manifest.json) 固定；既有證據與原始資料身分由 [source-manifest.json](source-manifest.json) 固定。

## 已有材料與界線

`Master.stp` **現在可讀，且已納入前輪完整分析**。本輪仍使用同一份 SHA-256 `f59edc403213de3a3923cc47ebf44eb1812705e8693c3c196d122f51ab0c919d`；它是掛載及封裝宣告，沒有代替其他素材包。所有本輪位址只適用於 SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` 的 KR `Tartaros.bin`，不套用另一份 EXE 或其他版本。

本包只包含研究文書、衍生契約、有限原件節錄與可重跑的離線檢查程式。沒有執行或改動 Client、Lua、Server、目標 DLL，沒有發布完整遊戲原始檔或完整解包成員；沒有把研究工具 PASS 填成可遊玩。

## 原計畫與前輪

- [原 P0／P1／P2 分工及驗收定義](../MEF-comprehensive-contracts-20261117/ANALYSIS-PLAN.md)
- [前輪 Master、Q119、七族、入口與 world 結果](../MEF-P0-P1-master-continuation-20261117/README.md)
- [完整功能域與四層完成矩陣](../MEF-comprehensive-contracts-20261117/COMPLETION-MATRIX.md)

本包的本輪更正優先於被點名的舊句；其餘固定證據沿用。原計畫八個工作項全數有處置，不表示八項的功能驗收全數通過。

## 重跑本包

以本次已提供原件的本機路徑執行：

```bash
python -B kr-extra-roy/MEF-P0-P1-P2-continuation-20261118/verify_evidence.py \
  --repo /workspace/scratch/b43c6175f310/ttr_anal_multi \
  --sources /workspace/scratch/3e083e35831f/project_sources \
  --supplemental /workspace/scratch/3e083e35831f/analysis/supplemental_resources/ttr \
  --require-ready
```

在其他環境請替換這三個原件／repo 路徑，保留 source manifest 指定的檔名與版本。離線檢查實際重跑本輪三份 verifier，並核對完整交付集合、來源、八項進度及連結。

本版使用 `--require-ready` 的預期為 **證據檢查 PASS、readiness_gate=BLOCKED、exit 2**。這表示分析證據一致，但尚未取得全部素材／入口／官方格式，不代表驗證程式壞掉。省略該旗標時，證據本身通過則 exit 0；兩種模式都不會執行遊戲、Lua 或 Server。`--result <path>` 可另存重跑紀錄。
