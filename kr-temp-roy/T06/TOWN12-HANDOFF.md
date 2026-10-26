# 城鎮1／2切換 — roy 定向接續

首要目標依使用者2026-10-25指示：能切換最初城鎮1／2。本文件是分析／開發接續規格，不代表已可遊玩。

| 項目 | 城鎮1候選 | 城鎮2候選 | 證據狀態 |
|---|---|---|---|
| TownList | ID1 핀더스 | ID2 알스메르 | 目前資源表已觀察 |
| MapList | ID182 | ID183 | Map rows已觀察；與Town ID的關聯尚未證實 |
| MAP | town001D | town002D | 目前_MapList精確值 |
| BOUND | town001 | town002 | 目前_MapList精確值 |
| TRIGGER | town001.mef | town002.mef | 字串存在，不代表客戶端有MEF執行器 |
| 場景 | Town/town001D.fld、.mre | Town/town002D.fld、.mre | Town.stp索引及payload SHA已保存 |
| 碰撞 | BoundMap/town001.bnd | BoundMap/town002.bnd | BoundMap.stp索引及payload SHA已保存 |
| 小地圖 | MiniMap/town001.mmt | MiniMap/town002.mmt | MiniMap.stp索引及payload SHA已保存 |

資料在 evidence/town12-resource-bytes.json。不得把Town ID1/2直接填入Map selector：目前MapList ID1/2是mushroom資源。

## 原生有界依據

既有REA/Ghidra12.1.4的4F5640、4F7DF0、4DF510證據，已以原始KR SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` 重新綁定位元組與指令位址集合（evidence/map-byte-verification.json）。這是現有原生證據的獨立核對，不是本輪新的執行觀察。

- Loader在4F5813/4F5837/4F585B分別使用FB74C0/FB74B0/FB74D0，透過4F7DF0取元素。
- 換圖4DF585/4DF622/4DF9AC分別使用同三個容器；MAP名稱於4DF62A查詢，後續比較／更新；BOUND查詢後4DF9C7呼叫4DF1A0。4DF787呼叫7C1E00的更深資源作用尚未新展開。
- 4F7DF0偽碼標為void，不可據此實作成無回傳值：4F7EF5/4F7EFA實際將node+10地址放入EAX。helper side effects與完整錯誤處理仍未全部驗收。
- 同Map ID分支、同模型比較、碰撞名稱和Town context是不同概念；不能只替換一個fixture常數就宣稱完成城鎮切換。

## 具體未完成條件

1. 核對Town1/2→182/183的原生producer/consumer，分清Town context、Map selector、scene/module與實例識別；名稱只能提出候選。
2. 引用T05/T07的0012、0038、0069及控制器交接證據，核對舊場景清除、載入、actor描述、控制綁定的條件與順序；不得從本機送包順序直接推成官方規格。
3. 查合法出生點及地形／碰撞與場景依賴；900/900及NPC格點是本機合成值，不能移植到兩城鎮。
4. 取得足夠證據後，才為相容實作規劃目的地參數、錯誤回應、回城、隊伍實例與保存資料；本輪原始anal及遊戲資源維持唯讀。

## 使用者記憶（尚未原生核對）

廣場由所有玩家共用，以頻道區分。城鎮由玩家組隊進入。任務地圖亦組隊，有任務目標及多小關卡，完成／打完BOSS後結算回城鎮。

活動期間存在廣場版本；使用者不確定是登入換地圖或只更換裝飾。兩種可能都保留，不由季節名稱候選推定實際活動機制。活動廣場列次要查證，當前只優先城鎮1／2。
