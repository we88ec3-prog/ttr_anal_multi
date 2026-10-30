# S00 Iterations 14–17 — 原稿保存與交接

這個目錄保存 2026-10-30 原先在舊 ChatGPT 對話生成的 **完整草案** 與工作矩陣。已從使用者的檔案庫恢復原始 Markdown / JSON，並非由簡短對話摘要重寫。

## 文件與狀態

- Iteration 14：角色清單與 F42EF / 0x665150 Dialog 有界路徑；完整 Markdown。
- Iteration 15：角色資料與事件/UI 的未閉合連結；完整 Markdown 和 16 組 UI predicate JSON。
- Iteration 16：E00–E12，新帳號到第一個新手教學可操作畫面；完整 Markdown 和 13 個 gate / 16 個規劃測試情境。
- Iteration 17：E13–E26，Scenario 14、Quest 14/16、Quest 15 可接、退出教學及重登；完整 Markdown 和 14 個 gate / 25 個規劃測試情境。

上述設計合計 **E00–E26（27 個 gate）與 41 個規劃測試情境**，不是已執行或已通過的 Client 相容性測試。每份原稿內的「未上 Git」字樣保留為當時來源歷史描述；本目錄保存動作不代表將它們升格為正式穩定 SPEC。

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
