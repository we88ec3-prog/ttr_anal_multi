# MEF：三項 P0 接續分析與採用契約

日期：2026-11-17（Asia/Taipei）；工作分支：`extra/roy1`。本包逐項接續 [上一批 ANALYSIS-PLAN 的三項 P0](../MEF-comprehensive-contracts-20261117/ANALYSIS-PLAN.md)，原稿基準為 `ac7e668ef19b91f86f05074d660aba10612c9a5f`，治理／Server 對照基準為 `origin/main` 的 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。

**三項 P0 都已完成本輪可由現有原件驗證的分析與交接。ABI、helper 轉換與執行／收尾契約已形成可重現的有界成果；真實資源的選取與完整 payload 仍缺原件，故不能把三項發布條件全數標為完成。** 精確狀態在 [P0-COMPLETION.md](P0-COMPLETION.md) 與 [p0-status.json](p0-status.json)。研究包 PASS 只證明來源、衍生資料及分析器結果一致，不代表資源齊全、Server 已實作或 Client 已可玩。

## 本輪結論

| P0 工作 | 已交付 | 尚未跨越的界線 |
|---|---|---|
| 採用勘誤與 ABI | 121 binding 的版本化採用 catalog；75 個 qbase helper 的呼叫審計；新內容嚴格 preflight；原始 Boot 數值與零參數 EndSepia 的特例證據 | 原內容相容審讀與新內容政策分開；工具尚未接入實際 Server 內容流程 |
| 內容真實依賴 | 兩個原場景的完整函式，合計 108 次主體呼叫、17 次 Create、15 個模型；相機、地圖、對話、Prolog、圖片／聲音、附件、原生選檔規則及逐項缺件 | 只找到並解析 2 個選定模型 descriptor，另外 13 個缺原檔；mount／cache／實際 payload 也未齊，完整遞迴依賴及 runtime 選取仍 BLOCKED |
| 執行與收尾契約 | 22 類 owner、條件式清理偏序、兩個原場景的正常退出；有限效果／同 run 多 phase／獨立 run 三種契約 | 各 owner 的非同步完成不能合成不存在的 drain ACK；實際跨段內容、資源、Server 串接及正常遊玩仍另驗 |

兩個場景是 `Q119/3 → Phindous_YuriandRazed_Boss` 和 `Q2440/5 → Aisen_01_After`，各自完整審讀，**沒有把它們指定為可直接串起的兩段內容**。本輪沒有更改原版 Client、載入原 Lua、啟動 Client／Server、部署資源或更新正式 RR／T01／S00 狀態。

## 閱讀入口

| 文件 | 內容 |
|---|---|
| [REPORT.md](REPORT.md) | 重要原生增量、錯誤假設更正、跨題交叉核對與結論 |
| [P0-COMPLETION.md](P0-COMPLETION.md) | 按上一批 P0 完成條件逐項回報；Client／Server／整合／遊玩分層 |
| [abi-adoption/report.md](abi-adoption/report.md) | ABI、原 helper、Boot、EndSepia 特例與作者規則 |
| [content-dependencies/report.md](content-dependencies/report.md) | 兩場景全部直接依賴、已知遞迴邊與 native resolver |
| [execution-lifecycle/report.md](execution-lifecycle/report.md) | owner、模型工作／釋放、圖片、音樂、清理偏序及三種策略 |
| [SOURCE-REQUEST.md](SOURCE-REQUEST.md) | 解開真實資源缺口所需的精確材料與接續方式 |
| [SERVER-ADOPTION.md](SERVER-ADOPTION.md) | 沿既有 REQ-0019／REQ-0021 的增量 Server 開發需求 |
| [integration/README.md](integration/README.md) | 現行 Server 主線、Q119 scene 鍵、外部 schema 與 typed identity 對照 |
| [VALIDATION.md](VALIDATION.md) | 完整重跑方法、實際收據、PASS 的範圍 |

所有 JSON 都是本專案研究／採用資料，`NOT_NATIVE_MEF`；沒有宣稱這是官方 MEF grammar。完整原始 BIN／STP／ZIP 或解出的遊戲成員沒有複製到本包。來源 pin、原件身份、有限指令窗口、衍生摘要及只讀驗證器足以重現本輪結果。

## 最優先的接續工作

先補同版本 mount／cache 與 [指定資源原件](SOURCE-REQUEST.md)，沿既有依賴前緣增量解析；同步讓 Server 內容流程採用本包的 ABI、typed reference、owner 與結果分層契約。材料與整合具備後，驗證第一條正常旅程，再擴充其他 selector／功能族。普通戰鬥、任務、權威旗標、NPC 服務與保存等不依賴這批缺件的 Server 工作可繼續推進。

續作導讀：[20261117_1931_EXTRA-ROY_MEF-P0-analysis-handoff.md](20261117_1931_EXTRA-ROY_MEF-P0-analysis-handoff.md)。
