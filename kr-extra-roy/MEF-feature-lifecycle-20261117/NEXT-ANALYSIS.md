# 下一階段：把全功能清單轉成逐項可驗收的完整鏈

## 1. 先改變「完成」的計算方式

不再把找到API、bytes PASS、提案可寫、已有最小規格、已部署、遊玩通過混成單一完成率。121是已知正常名稱集合，36是分析群組，兩者都不是完整玩法總數。每一列分別記：

`可達入口 → 有來源參數/資源 → 正確owner與身份 → native效果 → 可觀察結果 → 正常收尾 → 重新進場/取消整合 → Server契約 → 遊玩結果`。

已有原件直接引用，只補缺邊；每輪至少令一個真實功能進入可實作契約，或把一個精確候選查到阻塞與解除入口。不能一直重跑相同sink掃描、MapList aliases或OnYes路線當進展。

## 2. 建議優先順序與具體交付

| 順序 | 題目／目標 | 靜態工作及下一個來源 | 交付／完成條件 |
|---|---|---|---|
| P0 | A後有限效果自然收尾 | 直接復用本輪553B60→5537F0→release/delete/erase及前輪FadeIn鏈；選一個實際合法資源/發布品 | 一個最小內容規格：明確path/hash、exact arity、有限參數、owner baseline、End與自然終點；不再重逆這些已閉合函式 |
| P0 | 共享效果取得／回收契約 | 以camera、Q actor、music為獨立題，不一次混入全部；沿既有Begin/End、Stop/Detach、DeleteAll的真正caller與次序 | 每題有成功／停止／未建立不同狀態、合法cleanup入口、全owner影響範圍，不能僅列一個cleanup名字 |
| P1 | 首次啟動與後續重用 | A1固定鍵/seen單次限制已明列；以選定新內容查看Start重置model job、舊Q tree、image最後handle及snapshot會否互相干擾 | 同一field第二次啟動的精確writer/consumer與持有資料，不靠重送／隨機新鍵掩蓋 |
| P1 | 全功能資料預驗 | 由現有原表及bindings檢查typed IDs、完整依賴、stub、數值/布林ABI、非空資料；本輪矩陣是入口 | 工具只輸出缺件/衝突/來源，不產生猜值；Q slot≠worldID≠ShopNo≠NPC，voice/圖片時基不同 |
| P2 | B非Q一次入口 | 固定CScenarioTalkBox型別後追+9C其他writer，或FE3184/6BD620其他可達間接caller；接到ordinary page/field事件來源 | 必須證明不先進Q／Lua的首次來源、資料可見、UI capture/輸入與返回後副作用；不靠未知UI event編號 |
| P2 | 普通world觀察 | 從使用者真正需要的單一事件（例如既有怪被移除）追world EntityId→writer→合法Lua reader/callback | 身份、原因與context閉合才算事件；不以Q到點、空計數、Tutorial flags替代 |
| 獨立線 | 官方MEF首次入口／格式 | 新的可追filename/bytes producer→resource reader→parser；若無新來源，不重掃同一批陰性literal集合 | 原件正向連接才可改官方MEF狀態；相容內容一直標NOT_NATIVE_MEF |

以上優先順序是建議，不改正式RR owner。普通戰鬥AI/命中/獎勵/持久化可以由Server開發並行推進，不等待整張Lua介面清單都變成自主權威。

## 3. 全功能工作應分成五條線，而非所有人反覆查同一入口

| 工作線 | 具體功能目標 | 下一個可核來源／與其他線交界 |
|---|---|---|
| 呈現與收尾 | 對白、文字／圖片、鏡頭、音訊、Q actor依各自owner形成完整內容契約 | 本輪已閉合的native鏈直接引用；補真正資料與替換/取消，先交有限圖片或FadeIn只是最先可交付案例，不取消其餘能力 |
| 世界身分與事件 | 一個真正world實體的建立→操作→移除，及玩家需要的單一死亡/完成事件 | 復用0007/world索引、lb本地配號與缺返回ID反證；與T13主責協調，不重做其AI研究，不用Q slot或猜counter繞過typed identity |
| 場景與互動 | 本地map load／restore、小地圖、既有point及輸入恢復到同一Server節點 | 既有4DF510、Q單份backup、BOUND、小地圖與0027/0048；補當次map/actor/point/ready順序，Server轉場與保存獨立 |
| UI／服務／教學 | 已有資料的NPC對話→服務UI→真實請求→結果呈現→退出 | 使用Town/NPC/ShopNo分域、已核服務路由與Tutorial適用context；商店價錢/強化/背包規則交Server，未證wire欄位才回Client逆向 |
| 入口／排程 | B的非Q首次入口與官方MEF filename/bytes來源分開追 | 只沿未排除、已定型的callee/writer；A已成立的有限入口不再每輪重證，官方格式不與相容內容混名 |

每條線共享同一份121名稱/36群組索引及已查範圍，交付以功能鏈而不是函式數衡量。若安排多位分析者，應由使用者/S00指定不重疊的責任與資料基線；本稿不自行認領或派工，也不新增branch。

## 4. 下輪可直接使用的研究指令

> 沿extra/roy1，先套用／核對尚未發布的兩輪完整研究包。以A後「一個有限本地效果自然完成並回收」為主要開發交接目標，優先有限Q圖片，若合法texture來源未具備則先選已初始化FadeIn。引用現有native鏈，僅為實際資料綁定、原resource可見性、Start/End與共享owner衝突補證。不能更改A1已固定版本／鍵，不配置猜值、不輸出可部署Client資源，先完成可審閱規格與缺件清單。並行整理camera／actor／music獨立cleanup契約；B與官方MEF作獨立待逆向，不要求全部戰鬥交給腳本。完成原件/契約核對後再按現有授權發布研究；沒有寫入工具時保留累積patch，不宣稱已推送。

## 5. 能提升效率的實際措施

**來源快取**：以BIN SHA和repo固定commit保存已驗函式、registrar、caller與原件節錄；只在原件、引入的新函式或該功能依賴變更時擴充。整合前可跑有界回歸，但不要把回歸指令數算作新發現。

**正反證一起保留**：例如「tick尾呼apply」不足以推論Stop後仍寫pose，本輪已查apply的playing guard並排除；此反證必須留在索引，避免下一輪再走同一錯路。

**由功能反推必要鏈**：先定最小玩家效果，再列owner與完成／清理；不因普通清組事件未閉合而停止分析圖片，也不因圖片能自然刪除而外推普通戰鬥已完成。

**先自然終止，再長期持有**：自然終止圖片/FadeIn只需一個合法開始；永久圖／角色／音軌要求第二個真正入口或明確保留政策。先做前者更容易交付可驗收的增量，而不是放棄後者。

**每次最後一眼看得懂**：回報哪個功能鏈已閉合、哪些新規格可開發、四類缺口、下一個確定來源與遠端真實SHA，不用121/223/PASS當功能完成率。
