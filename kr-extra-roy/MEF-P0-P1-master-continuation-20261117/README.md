# MEF：Master 新來源、P0 閉合增量與 P1 全方向續析

工作 branch：`extra/roy1`。分析日期：2026-11-17（Asia/Taipei）。固定來源基準：`5ed4833b805949fabe260aea77e3fe0fd8e86bfa`，接續原 P0 發布 `534746f194a889ebb34dda7471c2ae62d30a1dd1` 及 T01 的限定審核。本包僅新增研究、衍生證據、檢查器與 Server 開發輸入。

**已實際讀取新 `Master.stp`，閉合掛載宣告缺口，並完成原規劃四個 P1 工作包的本輪有界分析。完整資源 ready、普通背景首次入口 B、world→同 run/generation Lua 出口與遊玩驗收，仍依證據維持未閉合。** 不將分析 PASS 等同原功能已實作或全部 MEF 已還原。

## 閱讀入口

| 目的 | 文件 |
|---|---|
| 整體新結論與影響 | [REPORT.md](REPORT.md) |
| P0／P1 完成狀態與各解除條件 | [P0-P1-COMPLETION.md](P0-P1-COMPLETION.md)、[status.json](status.json) |
| 新 Master、資源路由及真正 render loader | [master-resource-closure/report.md](master-resource-closure/report.md) |
| Q119 五段／四節點／返回與七個功能族 | [journey-families/REPORT.md](journey-families/REPORT.md) |
| 普通場景首次入口 B | [entry-b/report.md](entry-b/report.md) |
| world producer、HP／死亡／移除到 Lua 邊界 | [world-lua/report.md](world-lua/report.md) |
| Server 可直接接續的需求與驗收 | [SERVER-HANDOFF.md](SERVER-HANDOFF.md) |
| 精確補件及新材料取得後的順序 | [SOURCE-REQUEST.md](SOURCE-REQUEST.md)、[ANALYSIS-PLAN.md](ANALYSIS-PLAN.md) |
| 同行審查及修正 | [REVIEW-NOTES.md](REVIEW-NOTES.md) |
| 固定來源／交付完整性／實跑結果 | [source-manifest.json](source-manifest.json)、[artifact-manifest.json](artifact-manifest.json)、[verification-result.json](verification-result.json) |

## 重現

在含固定基準 Git objects 的工作副本，提供同一版原件目錄：

```sh
python -B kr-extra-roy/MEF-P0-P1-master-continuation-20261117/verify_evidence.py \
  --repo /absolute/path/ttr_anal_multi \
  --sources /absolute/path/project_sources \
  --supplemental /absolute/path/supplemental_resources/ttr
```

預設只讀：核來源、檔案集合、狀態及文件連結，並實際重跑四個新分題 verifier 和資源 `--require-ready` gate。分析一致時正常命令回傳 0；後者必須回傳 2，明示尚未達 ready。只有顯式 `--result /scratch/verification-result.json` 才寫 root 收據。分題命令及歷史 ABI／生命期／Server context 本輪重跑收據另見各文件和 `baseline-replay/`。

沒有執行 Client、Lua、Server、封裝內程式或目標 DLL；沒有提交原 BIN／STP／ZIP 或完整解包 member。所有 proposed Server 契約維持研究輸入，正式 REQ／RR／Task owner、T01 等級與 `native_complete` 不變。
