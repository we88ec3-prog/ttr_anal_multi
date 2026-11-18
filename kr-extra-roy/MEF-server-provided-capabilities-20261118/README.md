# MEF：Server 提供內容，優先交給 MEF 處理

**本輪依使用者 2026-11-18 的說明重新分析。MEF 開發算 Server 開發；生怪、戰鬥、群清、出口、結算、獎勵與保存都包含在內。能由 Client MEF 執行的工作優先下放，其他規則也可在 Server MEF 中執行，接既有通用服務。官方 MEF 復原不再是目標或共同門檻。**

分支 `extra/roy1`；分析基線 `60c1c1a5dc7a73902d9dbb50361d5148e8b30058`；已核對 main `5ed4833b805949fabe260aea77e3fe0fd8e86bfa`。本包是研究、契約與開發規劃交付，沒有執行／部署遊戲、Lua、Server 或修改原件。

## 閱讀順序

| 文件 | 回答的問題 |
|---|---|
| [玩家進度與缺項](PLAYER-PROGRESS.md) | 玩家能得到什麼？已有什麼？還需要接哪一段？ |
| [完整重新分析](REPORT.md) | 七項玩法如何由 MEF、Client native 與 Server adapter 合作？ |
| [方向決策](DECISIONS.md) | 如何修正舊的官方復原目標及 Server／MEF 分類？ |
| [既有 Server／MEF 成果復用](SERVER-REUSE.md) | 哪些引擎、波次、任務、獎勵與保存已經存在？ |
| [P0／P1／P2 開發計畫](DEVELOPMENT-PLAN.md) | 接下來以什麼順序實作，什麼結果才算完成？ |
| [121 個正常 binding 全表](BINDING-OFFLOAD-MAP.md) | 各接口真正可做什麼，有哪些參數／生命期限制？ |
| [Server 減負量測](LOAD-REDUCTION.md) | 怎麼分辨 CPU 外移、少派指令與減少硬編碼？ |

## 三份詳細分析

- [交付與執行 profile](delivery-profiles/report.md)：有限 Q、Tutorial 互動、native 效果延續與普通背景 B；附 [有限內容作者範本](delivery-profiles/authoring-contract.md) 及 [發布 manifest 範本](delivery-profiles/delivery-manifest.template.json)。
- [生怪、行動、戰鬥與群清](world-offload/report.md)：真正 world CMonster、本地 update、控制器／技能／HP／死亡與可觀察接口的具體邊界。
- [NPC、出口、任務、獎勵與保存](npc-progression/report.md)：既有點 setter、服務請求、任務／結算／帳本、Q119 自有規則模型與現有 adapter 接入。

## 機讀與驗證

[七項玩法能力契約](capability-plan.json)、[121 名稱機讀表](binding-offload-map.json)、[分層狀態](status.json)、[來源 pin](source-manifest.json)、[檔案 manifest](artifact-manifest.json)、[驗證收據](verification-result.json)、[整合審查](REVIEW-NOTES.md)。

```bash
python -B kr-extra-roy/MEF-server-provided-capabilities-20261118/verify_evidence.py \
  --repo /path/to/ttr_anal_multi \
  --sources /path/to/project_sources
```

驗證包含固定 Git 來源、原件身份、子包有界原件／資料證據、121 名稱與 ABI 的精確對應、七項功能範圍及檔案／連結。PASS 不表示新內容已部署、遊戲已驗收、T01 FULL-PASS 或 S00 規格已發布。

跨輪入口已更新為 [目前方向](../MEF-CURRENT-DIRECTION.md) 與本目錄 [工作指示](../AGENTS.md)。歷史研究包保留原 bytes 與證據，方向衝突依使用者本次說明處理；正式 owner／RR／主線實作及既有驗收紀錄未改寫。
