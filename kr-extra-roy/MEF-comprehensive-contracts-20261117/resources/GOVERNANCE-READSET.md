# 本輪治理 readset 與跨任務界線

固定 main：`03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`；本輪研究基線：`5ef4ab8870ea1c65c6c7497901302d851f5c7a51`。完整 path/blob/bytes 見 [governance-readset.json](governance-readset.json)，新增 MEF 功能追蹤及需求內容 SHA 見 [source-manifest.json](source-manifest.json)。原始共用指令檔也保存整檔 hash。

| readset | 已核事項／本輪處理 |
|---|---|
| AGENTS、shared/CLIENT-MODIFICATION-POLICY | 維持 extra/roy1、原件只讀、不改 Client、不以自訂格式冒稱原生 MEF；Server 缺口列開發需求。 |
| T01 README/task.json/inbox | owner 為 Codex/T01 整合；本次不替其判 claim admission 或 FULL-PASS。舊 README 的退回摘要不覆蓋目前 T16 的精確項目狀態。 |
| T06 README/task.json/inbox | owner roy、in-progress，map/resource ID 範圍；本次只定向讀相關 MAP/BOUND，相依審計不跨認領 T06，不改波次／執行器。 |
| T13 README/task.json/inbox | unclaimed；RR-0013 P0 QUEUED，普通 CMonster movement/attack producer（1036 baseline）另屬正式研究，不由本資源線代領。 |
| T16 README/task.json/inbox | unclaimed；目前 44 個固定退回標題皆 RESOLVED，含 T16-117-Q16-MODE2-C2S36-001。T16 Client wire/UI 優先和 Server 設計界線仍適用。 |
| research/dispatch README、requests index | RR-0008 的 T03 舊 extra/roy1 work 為 IN_REVIEW。當前使用者直接要求 MEF continuation，不自行新建／認領／關閉 RR。T06/T16 inbox 無新的 S00 指派。 |
| verified-knowledge README、T01-BULK-20261026-02 | 限定已驗結論繼續復用；map read/clear 或零回 stub 的確認不升格為所有 Lua 名稱 FULL-PASS。 |
| MEF-FUNCTIONAL-COMPLETION | 功能目標可沿自訂 Server-owned schema 與 typed adapter 開發；原生格式研究獨立。主線既有功能不能因本輪缺原資源而一律標未開發。 |
| design/requirements/index.json | REQ-0019/0021 維持 CANDIDATE；本包只映射資源工具及明確欠缺資料，不更動正式台帳。 |

T01/T06/T13/T16 的 README/task.json 以及各 inbox 都已實讀，另讀相關 RR 的具體內容。上述任務分工不是要求重新許可，也不阻止使用者已授權的 extra/roy1 研究與 Git 交付；它限定了本包不改其他任務 owner／狀態及不冒稱已獲審核。

## 已公開研究的盤點

本機舊 `analysis/r11` 的 publication receipt 只到 `f8f2c8bdbb984a7571e7bd7591941f1ddda08889`。目前研究 repo 已前進到 `5ef4ab887`；下列四個目錄的成果已包含在公開分支，文內舊「未推送／僅本機」敘述是歷史快照，本輪不當作待推送工作：

- `MEF-full-surface-native-continuation-20261116`
- `MEF-feature-lifecycle-20261117`
- `MEF-world-identity-scene-interaction-20261117`
- `MEF-transition-actor-event-20261117`

這些成果及更早的 bridge／capabilities／resource-gates 是本輪可直接復用的基礎。本包新增相依證據，不把完整 registrar census、post-End continuation、camera/music cleanup、world identity、既有原 Q119 演出或 A1 跨層契約當作新發現。
