# 本輪整合審查與修正

本頁記錄本分析包內的交叉檢查；不取代 T01 全文原生驗證、S00 規格接受或遊玩驗收。原件只讀，既有已封研究包未改寫。

## 1. 目標與既有成果的交叉審查

交付／執行 profile 分題獨立審查 Root 的完整報告、方向、既有 Server 復用、P0／P1／P2、減負計畫、121 名稱表與七項功能機讀契約。NPC／任務分題另審查 Root 的玩家進度、結算／保存分工及有限作者契約。

已核對的方向：MEF 在 Server 開發範圍內；Client 執行與 Server 規則化的收益分開；官方格式不是門檻；有限 Q 不被普通背景 B 阻塞；既有任務／資產／保存未歸零；場景結束未被誤當任務／入帳成功。

交付分題最後再只讀審查 world 報告與機讀契約，確認 CMonster 生成／attach／敵方自主決策分界、動作／扣血／死亡／移除分界、既有 native 成本及普通 runner 的適用範圍均一致；並核對 Root 新增的有限清場路線，未見必修問題。

## 2. 發現並修正的問題

| 問題 | 修正 | 覆核結果 |
|---|---|---|
| 新 121 名稱機讀表複製了舊 catalog 的功能域 context／完成／清理通用句，個別列與自己的 ABI／consumer 矛盾 | 從本輪全部 121 列移除 `required_context`、`completion_boundary`、`cleanup_boundary`；保留逐 API 作用／限制、ABI 與來源。五個具體例補精確使用註記，域級工作建議明確不是逐 API 額外前提 | 交付分題再次只覆核此修正：舊欄位殘留 0，五列與 ABI／native constraints 一致。沒有要求字幕有 Q slot、時計有 renderer，或 direct ChangeMap 自動取得 Q backup |
| World 初稿使用了不存在的名稱 `Q.IsObjectStopped` | 改成正常名稱 `Q.IsAllObjectsStopped`，補全 Q 索引與空索引也回 1 的限制，pin 精確 observer 原稿 | 作者原件／契約 verifier 及 Root 名稱對照確認；不是新的怪物存活查詢 |
| 只有「本地條件」「Server 一次 0048」「待接通用事件橋」三種出口配置，容易誤把所有群清後 Client MEF 開門卡在事件橋 | 新增已證元件組合：Server MEF 收 GroupCleared→適用時點一次 0047 選已發布 finite 內容→Client 等待／演出／setter／End | 交付與 NPC 分題均確認不需要 event 注入常駐 Lua。Root／NPC 規格與機讀契約同步，保留未部署及選定 quest0 收尾界線 |

新增有限組合沒有改 wire，也不把 `003F` 當動作成功。單項開門若改走 `0047`／`003F`／`00EB` 不保證少封包；量測計畫已明列相對於一次 `0048` 的差別。這使「MEF 優先」依實際能力與工作量落地，而非所有動作一律加腳本包裝。

## 3. 來源更新與證據範圍

- 以目前已發布的功能追蹤與後續文件修正早期未完成狀態：已有波次、巡邏／追擊、結算、錢包、普通任務進度及熟練度不重新列成整套缺失。
- NPC 分題重核 type 3／SkillExp 的資料 consumer 與 `0022` 複製後讀取位置；舊文件的未解段保留歷史，不再作當前唯一結論。
- World 分題增加從正確入口解碼的普通 CMonster 更新、移動與技能 state 鏈，直接呼叫搜尋明列有限範圍，不推成全程式沒有敵方 AI。
- Delivery 分題的 22 個 native 窗口與 8 個 Lua 片段明列復用重驗；新成果是自製內容作者／交付契約，不重算新 loader 或 API。
- 小型原始 member 採身份／hash 與必要語意，不把完整 decoded member 或原始 BIN／STP 加入交付。

## 4. 整合驗證

Root verifier 重新核對來源身份、逐名 ABI、七項玩法範圍、有限 selector 組合、文件連結與所有交付檔案，並實際重跑三份只讀子驗證器。子包結果與保存收據對照；world 的每次 UTC 執行時間可不同，其他證據與結果欄必須完全相同。完整實際結果見 [verification-result.json](verification-result.json)。

本輪沒有執行目標 Lua、Client 或 Server，沒有新增實機／壓測／暫緩異常測試。P0／P1／P2 的內容接線與遊玩進度按開發計畫保留，不因離線 PASS 變成已部署或可玩。
