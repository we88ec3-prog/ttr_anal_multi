# S00 Iterations 14–21 — 原稿保存與交接

這個目錄保存 2026-10-30 原先在舊 ChatGPT 對話生成的 **完整草案** 與工作矩陣。已從使用者的檔案庫恢復原始 Markdown / JSON，並非由簡短對話摘要重寫。

## 文件與狀態

- Iteration 14：角色清單與 F42EF / 0x665150 Dialog 有界路徑；完整 Markdown。
- Iteration 15：角色資料與事件/UI 的未閉合連結；完整 Markdown 和 16 組 UI predicate JSON。
- Iteration 16：E00–E12，新帳號到第一個新手教學可操作畫面；完整 Markdown 和 13 個 gate / 16 個規劃測試情境。
- Iteration 17：E13–E26，Scenario 14、Quest 14/16、Quest 15 可接、退出教學及重登；完整 Markdown 和 14 個 gate / 25 個規劃測試情境。
- Iteration 18：在不更動 E00–E26 編號下，細化 E17 的怪物生成、AI 行動、角色普通攻擊、技能施放、傷害/死亡及勝負結算；完整 Markdown、10 個 E17 子閘門、20 個未執行的規劃測試情境 JSON 與 6 個候選研究題目（尚未建立正式 RR）。

Iterations 16–17 的正式流程編號合計 **E00–E26（27 個 gate）與 41 個規劃測試情境**；Iteration 18 的 10 個 E17 子閘門與 20 個規劃測試情境為額外細化草案，**不納入正式 E/TEST 台帳**，不是已執行或已通過的 Client 相容性測試。每份原稿內的「未上 Git」字樣保留為當時來源歷史描述；本目錄保存動作不代表將它們升格為正式穩定 SPEC。

## 研究證據限制

- Client BIN 部分已有 T03/T16 等原稿提供的限定靜態證據；這 4 輪沒有新增原生封包抓取或原版 Client 執行。
- 角色清單寫入、事件 producer/delivery、UI-ready、選角成功到 scene handoff 不能任意拼成已證 E2E。
- SceneList (1001,1)、Scenario 14、Quest 14、Event scene key 不能用相同數字推定共用 wire opcode。
- 教學結算、Quest 前置、持久化及場景轉換仍需按照 T07/T14/T15/T16 與相關研究逐項補證或作獨立 Server ADR。
- **不改動** research/requests/index.json、正式 REQ/GAP/SPEC/TEST 狀態、Task owner、其他 Task 原稿；**不新增正式 RR**。後續 RR 必須先去重，再以官方 dispatch/event 規則發布。
- **不改動** 獨立 ttr_server_roy 的開發實作；其原有契約 pin 如需升級，須另作設計審查與開發交接。

## 下次 S00 待辦

1. 對照最新 RR-0002、RR-0008 與 T03/T06/T07/T14/T15/T16 的既有研究，逐項去重創角、零角色 UI、教學完成與離場阻塞，再評估建立新的正式 RR。
2. 將 E00–E26 分段映射到目前正式 SPEC/GAP/TEST；只在已取得有界原生證據時更新相容契約，Server 專屬選擇使用 ADR。
3. 建立正式 E2E 測試規格，將 `planned`、`synthetic`、`native-static`、`runtime-verified` 分開；沒有授權不啟動原版 Client。
4. 以新帳號完成教學、退出至可操作非教學場景及重登進度一致作為產品交付目標，而不是以任一旗標更新當作完成。

**Git 基準**：原稿分析時 main @ dd69ec9de353a695d25c6db8e362ff471ea0c137；本次保留原稿原始基準，不假稱其與日後 main 完全等同。

## Iteration 19（2026-10-31，新規劃）

- [Iteration 19 — 新帳號至教學離場 E2E 整合與驗收](S00-20261031-ITERATION-19-END-TO-END-ACCEPTANCE.md)：在 Iteration 16–18 不變的 gate 基礎上，定義登入、創角、選角、教學戰鬥、Quest 結算、離場及重登的跨模組因果與四層驗收；列出 I19-P1～P4 和 I19-T01～T12（全部 PLANNED / NOT_RUN）。
- Iteration 19 是**新增規劃**，未將原有 E00–E26、E17-A～J 或正式 REQ/RR/SPEC/GAP/TEST 變更、升級；無原版 Client 測試與 Server 程式變更。

## Iteration 20（2026-10-31，逐 Gate 證據盤點與去重）

- [Iteration 20 詳細規劃](S00-20261031-ITERATION-20-GATE-TRIAGE-AND-RR-DEDUP.md)：依 Iteration 19 的下一輪建議，依序處理登入/空角色 UI、創角、選角進教學、E17 戰鬥、Quest 結算及教學離場/重登。對現有 8 個 RR 去重、建立新證據最小交付表與 I20-T01～T12 **未執行**的測試草案。
- [Iteration 20 全量機讀盤點](S00-ITERATION-20-GATE-EVIDENCE-TRACE.json)：E00–E26 **27 主 gate**、E17-A–J **10 子 gate**，逐列保存既有規劃狀態、owners、未解證據與 Iteration 16 草案引用的正式 ID，並附用來檢視的當時各索引 blob SHA／RR dispatch 快照。
- 仍只有正式 RR-0001..0008：RR-0002 BLOCKED、RR-0005 研究範圍 ACCEPTED、其他 IN_REVIEW（快照，不應代替重讀唯一 RR 索引）。**沒有**本輪新正式 RR/REQ/GAP/SPEC/TEST、原 Client 動態測試、Server 開發或規格升級；建議先審核既有 Txx 結果後再決定要不要發新的狹義 RR。

## Iteration 21（2026-10-31，正式 E05／E06 派工）

- [Iteration 21 詳細分析與正式派工](S00-20261031-ITERATION-21-CREATE-UI-WIRE-DISPATCH.md)：從 Iteration20 Gate Trace 的 E04→E05→E06 開始；在對照既有 RR-0002（選角，BLOCKED）、RR-0007（入站 dispatcher）、RR-0008（選角→場景）後，**新增** `GAP-CHAR-0002/0003` 與 `RR-0009`（零角色／創角 UI 正向入口）、`RR-0010`（真正創角 C2S/S2C 正向交易）。
- 兩個研究請求均 **P0 / QUEUED / 未認領**，T03 主責、T06 資源與 T04 欄位為定向協查。T03 生成收件箱已更新，唯一正式 RR 台帳從 8 增至 10；既有 8 個 RR 不變。
- `SPEC-CHAR-0001`／`SPEC-FLOW-0001` 仍 DRAFT/PARTIAL，僅加明確 blocker，不新增 Client 封包、Server 跨任務實作、原 Client runtime 或任何 FULL-PASS／SPEC STABLE。Git 合併不自動喚醒其他 Agent。
