# Case 693 有限重複房間：有界 native 審核

日期：2026-11-22。public 基準 `8e0265b07dddbc868799fefdc5e0590f5aa15512`。本工作只讀既有報告、固定 SHA 的保存偽碼／指令與原件，未執行／附加 Client，未修改原件或 repo。完整來源絕對路徑、canonical repo 相對路徑、SHA 與實際重核窗口在 `source-review.json`。

## 結論與可開發範圍

可把有限 visit 的獨立 Server node IDs 11、12、10 投影到同一實體 map 3430 與既有 CHART key 10，第三次保留原 node 10，再接原有 1 → 3 → 5 或 6 → 4 → 2 的 boss／結果流程。這是 Server 的有限內容編排，不是聲稱原服 MEF 本來如此。

已讀的完整 `4B3350` consumer 沒有「不能再次選同 key」、visited-set、只接受大於目前 key、或必須 CHART 相鄰的判斷。因此未知的其他 UI／callback 不能當成整個有限重複方案不可開發的理由。仍需保留既有有效 Case、場景、資源與完整轉場前提。

## 0049、Case 與實體 map 分開

1. S2C **0049** 的 application+2 是 u16 chart node key；不是 003B，也不是實體 MapID。`4B3350` 每次將該 WORD 寫入 world+94，沒有先拿它和舊值去重。
2. 它從目前 context 的 Case key 查 Stage 資料，作 Acquire／Release，掃描 16-byte CHART rows，比對 row+8 的 key，再由 row+0C 選相機旋轉值。既有合法 key 10 可以再被匹配；不需要把 Server 虛擬 node 11／12 傳給這個 consumer。
3. 重選同一合法 key 的選擇值／相機值可相同，但**不能把整個 handler 宣稱為無副作用冪等**。Stage refcount+48 的 Acquire／Release 可觸發 `53E120 / 53E1D0` 載入／釋放。
4. `0038/type2` 的 `4B1BF0` 安裝／重置 context，從 application+7 取 Case，交 `540980`。目前 normal adapter 只在 install 時發送此 context，後續 node 保留 field／Case。沒有已證需求要求每個重複 visit 再發一次 0038；不應以重裝 context 代替 visit 換代。
5. 物理載入由 S2C 0012 的 application+2 u32 mapKey 獨立提供。不能把 virtual node、chart key、Case 與 physical map 混成同一欄位。

本段 4B3350 語意來自完整已保存偽碼，本輪新 focused REA 查詢逾時，復查無active provider程序或留存Evidence；未重啟查詢，沿用已重核原件的既有raw／bulk有界證據；不把該偽碼單獨升為整函式 FULL-PASS。

## 0012 同圖仍有必要清理

原件 `4B24F0..4B2566`：先 `5449A0` 清 checkpoint collection，再 `544F50` reset 當前 controller，然後呼 `4DF510(world,mapKey)`。

`4DF53E` 比對 mapKey 相同會跳到 `4DFA13` 的音樂處理，省略後段 graphics／Bound／minimap 資源重載；但前面的 points／controller 清理已發生。因此：

- 同圖不能沿用前一 visit 的 point latch／status 當成新狀態；重新發完整 0027。
- 0048 只改既存的第一個 category/key，不建立 missing point，不能替代 0027。
- 不假設 0012 已清所有 world actor。使用已清場／明確退休的 actor 生命期。
- 不改成 `lb.ChangeMap`，該路線少了 0012 的 points／controller 前置。

這些窗口來自既有 gates-transitions／world-identity native evidence，已重新對原 BIN 與指定 v2 檔案 bytes 核對。

## 0010 Reset 的實際作用

已復用 T07 保存的 `character-reset.json` 與 `reset-core.json`，沒有重新猜測 opcode：

- S2C 0010 的實際 consumer 為 `4B1A30`，呼 `4DFD40(0)`，按 world ID 的 low byte 刪除 **type 0** 物件。
- 接著呼當前 controller 的 v+14、清 world+F8，並清 world+18 關聯集合。
- 它不是全 world 清理，不會因名稱叫 Reset 就刪掉敵人 type 1、投射物 type 2、掉落 type 3。
- 192-byte `4B1A30` 線性保存窗口包含相鄰入口與 padding，不把它全部宣稱為單一函式。其 SHA 為 `2b7955d1511435cc0dfe15f6b5b578936c95a1afd6b98dfd067bf4c767225bf7`。
- `4DFD40` 340-byte 窗口 SHA 為 `80d6437892b2d1d69f60e5ad2bcc7a1b3e1c6594db7cc566ac5d03772389c6cf`。

兩份 legacy 證據共五窗已全部再對原 BIN／指定 v2 核對相同；不因它們是歷史文字而省略身份核對。

## 同圖 owner 與 points 的正向偏序

root 採用的既有 normal pipeline 可保持以下順序，不需新 opcode：

1. `ReadyToClearMissionNode`：必要敵人已倒下，移除訊息已入輸出；physical flights 結束，visuals 退休。
2. 處理前 visit 未拾取掉落的 RemovalPackets，以及仍需明確退休的事件物件／效果。
3. S2C 0012 map3430；S2C 0049 chart key10。
4. 0010 刪除原 owner type0／清 controller 及 relation；發布目前 alias 的 Metadata，再建立 owner ActorForAccount。
5. 000A 綁定 alias 與新 owner 0x0100。已證 consumer 要求 relation record 與 actor 都已存在，不能先綁定再等 actor 自動補接。
6. 發當前 visit 的完整 0027（出口、互動點、marker 同一集合）與新敵人快照；最後 0014 ready、loading end。

這是沿用 Server 已存在的候選偏序，並依有界 native 契約檢查其必要依賴，不是官方封包錄影或新的實機驗收。0014 本身只設指定 ready／mask 狀態，不能當成 actor／controller／point 快照的完整 ACK。

## 世代與尚未實測限制

- Server 的 visit/node ID、計時、flag、掉落、敵人、投射物及獎勵範圍要獨立；MapID 相同不表示仍是同一 visit。
- 001C native payload 只有 category/key，沒有 run／generation；同值的遲到舊意圖無法從 payload 單獨辨識。保留目前 phase、pending、current node 與權威位姿／出口合法性檢查，不發明 Client 不讀的 token。
- 新 point 初始化、清舊 latch 與實際 held-key 行為，以及同圖重複時的鏡頭／小地圖／出生位置／可操作性，都仍需指定 Client 人測；本審核沒有操作遊戲或測試重送／重登案例。
- 沒有主張整個 Client 絕不存在其他 key 依賴或 callback；所核 0049 consumer 沒有相鄰限制，足以供這次有限 Server 編排採用，剩餘實機限制另留。

## 本輪核對範圍

原 BIN SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；指定 v2 SHA `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`。共重新核對 **17 個既有 raw windows**，所有保存 SHA／bytes 符合原 BIN，對應指定 v2 bytes 全相同。來源 readset 共 37 筆，包含已讀完整偽碼、既有有界報告／證據，以及必要的 private normal adapter 身份；沒有把 private Server 原碼複製到此筆記。
