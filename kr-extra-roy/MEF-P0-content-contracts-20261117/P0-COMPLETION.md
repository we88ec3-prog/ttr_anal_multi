# P0 完成條件與剩餘責任

本表逐項對照 [上一批規劃](../MEF-comprehensive-contracts-20261117/ANALYSIS-PLAN.md)。`COMPLETE_BOUNDED` 表示所寫範圍的原件分析／研究工具交付完成；不是正式 FULL-PASS，也不把 Server／整合／遊玩自動填為完成。機器可讀版本：[p0-status.json](p0-status.json)。

## 1. 採用勘誤與 ABI

| 完成條件 | 本輪結果 | 邊界 |
|---|---|---|
| 固定全部正常 binding 的參數與回值 | COMPLETE_BOUNDED：121 筆逐欄對照既有 ABI，四 stub／無 count producer 保持禁用 | 不推導新 Client API；producer 不是通用成功 ACK |
| 內容工具拒絕 arity／型別／無 producer 誤用 | COMPLETE_BOUNDED：嚴格資料 preflight、拒絕範例與來源污染防護 | 研究用作者檢查器；沒有 Lua 執行或 Server 部署 |
| 原 helper 與真實內容採用 | COMPLETE_BOUNDED：75 helper、兩個完整原場景、Boot 數值、Create／Walk 轉換 | 只在固定原件及未覆寫 global／binding 前提下成立 |
| 原 EndSepia 零參數與圖片勘誤 | COMPLETE_BOUNDED：特定 frame 推導 native 0；取消前圖與延後實體回收分列 | 新作者仍需顯式 arity；不泛化缺參數或回收完成 |
| 接入正式內容建置／載入流程 | SERVER_DEVELOPMENT／INTEGRATION_REQUIRED | 需在現有規格線採用版本、拒絕規則及結果語義 |

證據：[ABI 報告](abi-adoption/report.md)、[採用表](abi-adoption/adoption-catalog.json)、[原內容審讀](abi-adoption/original-call-review.json)、[EndSepia](abi-adoption/zeroarg-endsepia-contract.json)。

## 2. 內容真實依賴

| 完成條件 | 本輪結果 | 邊界 |
|---|---|---|
| 完整審讀所選場景 | COMPLETE_BOUNDED：Q119/3 與 Q2440/5，108 次函式主體呼叫，兩解析器逐項相符 | 兩個原場景，不代表所有 SceneList 內容都已審讀 |
| 納入顯式／隱式依賴 | COMPLETE_BOUNDED：17 次 Create、15 模型、action 1/4、default item、相機／地圖／對話／Prolog／視聽與已到達的遞迴邊 | 查詢嘗試與必要可見結果分開；13 descriptor 缺失後的子依賴不可憑空列齊 |
| 採 native identity、duplicate、mount 規則 | COMPLETE_BOUNDED：Actor 後寫覆寫、basename 首筆保留、Master 後續成功 binding 取代分列 | 相同 basename、Base 候選或鄰近 MapList row 都不等於已選檔 |
| 真實選檔及完整遞迴 payload | BLOCKED_MISSING_ORIGINAL_SOURCE | 缺 Master／cache／13 descriptor／Items.ipk／實際視聽與其他 payload；精確請求另列 |
| 內容可部署／畫面可用 | INTEGRATION_REQUIRED／PLAY_VALIDATION_REQUIRED | 審計已完成可達範圍，`ready=false`；原檔齊備後再驗選取與正常旅程 |

證據：[依賴報告](content-dependencies/report.md)、[完整場景圖](content-dependencies/scene-dependencies.json)、[未閉合前緣](content-dependencies/dependency-frontier.json)、[SOURCE-REQUEST.md](SOURCE-REQUEST.md)。本項不是 Server-only 未知；它確實缺少 Client 資源原件，故保留未閉合狀態。

## 3. 執行與收尾契約

| 完成條件 | 本輪結果 | 邊界 |
|---|---|---|
| 同一 context 的 owner 與釋放者 | COMPLETE_BOUNDED：22 類 owner，取得／持有／停止／排釋放／實體回收分列 | shared owner 不假定每 run 隔離 |
| model／parts／舊引用及非同步工作 | COMPLETE_BOUNDED：清樹前 state 1 release、強引用、normal Create immediate 1、producer 條件 | 沒有全引擎取消／drain 證明，也未把 generic pending 套成原場景事實 |
| 原場景清理與特殊參數 | COMPLETE_BOUNDED：兩原場景退出、條件式偏序、empty finalMusic、Start clear、EndSepia 0、圖片 fade-out 0 的先行 guard | 排程、phase 0、alive 0、實體釋放是不同時點；不保證固定 wall-clock |
| 有限／同 run／獨立 run 策略 | COMPLETE_BOUNDED：三個策略各有入口、owner 與退出條件 | 沒有挑兩個不相容 selector 假裝成可用 pair |
| 真正採用與正常旅程 | SERVER_DEVELOPMENT／INTEGRATION_REQUIRED／PLAY_VALIDATION_REQUIRED | 需綁實際內容、資源、合法入口、原回覆及業務結果 |

證據：[生命期報告](execution-lifecycle/report.md)、[owner ledger](execution-lifecycle/owner-ledger.json)、[清理圖](execution-lifecycle/cleanup-order.json)、[三策略](execution-lifecycle/run-contracts.json)。

## 4. 四層接續責任

| 層次 | 本輪後仍須做的工作 | 何時可視為該層完成 |
|---|---|---|
| Client 待逆向／原件補證 | 指定缺件與 runtime 選檔補證；若新功能要求全佇列 drain 或 state 3 同物件恢復，另找同 manager 的原生 producer／consumer | 真實新證據閉合指定主張；不能由 Server 自訂 token 取代原生證據 |
| Server 待開發 | ABI／內容版本檢查、typed reference、run 排程與 owner 政策、原回覆與業務提交分離 | 在既有 REQ／SPEC 工作線有實作與工程驗收；不要求官方 Server 內部實作 |
| 跨功能待整合 | 以真實 mount／payload 綁 selector、schema 與既有 adapter；選定一條正常內容旅程 | 各段真正串接，所有必要前置與無 ACK 限制都有處理 |
| 待遊玩驗證 | 指定 Client 的完整視聽、控制恢復、出口 Z、結果與返回 | 取得被允許的正常玩家流程證據，不能以分析器 PASS 代替 |

本包已提供所有本輪 P0 可交付的分析、工具與精確接續條件；**未把缺原件的資源發布門檻宣告完成**。沒有更動正式狀態，沒有新增平行 RR／REQ 台帳。
