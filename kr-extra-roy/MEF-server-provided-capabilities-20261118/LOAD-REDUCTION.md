# 如何證明 MEF 有減少 Server 工作

這是待整合時採用的量測設計，不是本輪已取得的效能結果。Client 原生能力見 [全功能表](BINDING-OFFLOAD-MAP.md)；各 profile 的入口與生命期見 [delivery-profiles](delivery-profiles/report.md)。

## 1. 先分清節省了什麼

| 工作 | 優先安排 | 可檢查的節省 | 仍要記錄的成本 |
|---|---|---|---|
| 同一段內容的多步時間線與呈現 | 一次選擇已發布的 MEF，Client 自行 wait、執行與收尾 | Server 排程工作數、逐步內容事件數、相應 application bytes 是否減少 | 內容發布與快取、一次啟動／完成回報、Client 載入時間與 frame 成本 |
| 可獨立本地生成的物件 | MEF 定義批次／時機並使用已證 world 建立鏈 | 對所選本地用途，是否省去同等的個別生成控制工作 | 本地 ID／lifetime、模型依賴；共享敵對角色不得未接同步就算同等流程 |
| 條件驅動的關卡規則 | 本地可觀察就由 Client MEF 判定；否則把必要事件送入 Server MEF | 事件驅動求值能否取代每 tick 掃描；每個關卡重複 handler 是否減少 | 事件來源、規則求值 CPU、共同狀態與 adapter 次數 |
| 開出口與後續演出 | 點先配置；條件可觀察時 MEF 直接 setter，否則僅接最小條件邊 | 是否省去多個 UI／時間步；是否只剩一次必要點更新或事件邊 | 點已存在、category／key 正確、轉場／互動請求仍要對齊 |
| 結算、獎勵與進度 | MEF 計算規則；既有 adapter 集中提交與發布 | 每任務硬編碼減少；是否避免每個演出步驟寫 DB／重新求獎勵 | 結算計算及一次持久寫入仍有成本；不以藏掉存檔冒稱節省 |

沒有實測資料時不填「省 50% CPU」「少 90% 封包」等數字。原版 Client 本來就做的鏡頭、音訊和渲染，也不能全算成這次新增的 Server 節省。

**選對粒度：**Server MEF 已收 GroupCleared 後，用一次 `0047` 啟動「等待→演出→開門」finite 內容，不需要通用事件注入 Lua；可省中間步驟的 Server 編排。若原需求只有一次點開關，`0048` 的 application 是 6 bytes；所選 quest0 正常 Q 路線至少涉及 6-byte `0047`、8-byte `003F`、2-byte `00EB`，還有內容發布成本。不能為了使用 Client 腳本就宣稱這種單動作路線更省流量。MEF 規則可依內容粒度選兩種 adapter，仍符合 MEF 優先的開發方向。[點／場景契約](npc-progression/report.md)、[有限內容 wire](delivery-profiles/authoring-contract.md)

## 2. 比較相同玩家結果

基準與 MEF 版本要使用同一個正常流程、同一依賴版本、同一怪物／任務／獎勵規則以及相同玩家數。先確認「能生同一批需要的物件、滿足同一條件、開同一出口、得到並保存同一結果」，再比較工作量。

應記錄的量：

- Server：每個 run 的 timer／scheduler 呼叫數、MEF 規則求值次數與時間、world／封包 adapter 次數、application bytes、DB 提交次數與耗時。
- Client：內容載入耗時、該段 frame／update 成本、必要資源數量、開始與結束可觀察結果。比較本地負擔增加是否符合目標。
- 玩家流程：從進場到可操作、條件達成到出口可用、退出到獎勵／任務狀態顯示的時間。

這些是量測欄位設計；本包沒有新增原生 wire 欄位，也沒有宣稱現有協定已有全部 telemetry。先用已存在的 Server 記錄；需要新 Client 測量手段時另按既有專案規則處理。

## 3. 計算與判讀

若基準排程次數為 `B`、MEF 版本為 `M`，則節省次數是 `B - M`；只有 `B > 0` 才有節省比例 `(B - M) / B`。CPU、bytes 與 DB 提交各算各的，不能把「少寫幾個 handler」代入 CPU 比例。

若兩個版本都已用相同 native 動畫，動畫 tick 節省量可能為零；MEF 的收益可能是資料化與省去 Server 串接工作。若把規則搬到 Server Lua／另一個規則引擎後 CPU 沒下降，也仍可能減少程式維護量，但須據實記錄。

若普通戰鬥仍缺事件進入 Client MEF 的接口，先用 Server MEF 與已有 world adapter 完成玩法，記錄實際保留的運算；不能用不支援普通死亡查詢的 API 虛構全本地戰鬥，亦不用為了追求一次全下放而停住已可做的內容。

本項安排在新內容正常流程接通後；本輪只分析並保存量測契約，不執行壓測、多人併發或暫緩的異常測試。
