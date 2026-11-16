# R12：MEF 互動點、NPC 與商店能力 — Server 開發需求交接

母稿：[R12 完整控制鏈](../20261116-MEF-checkpoint-lifecycle.md)。前稿：[R11 Server 交接](../MEF-capabilities-20261116/server-handoff.md)。本文件依現有 `REQ-0019`／`REQ-0021` 及城鎮服務需求交 S00 去重、合併；不是新正式 RR／REQ 清單，也不更動 Server、owner 或驗收狀態。

## 實作介面

本輪 BIN-first 來源支持：
- S2C `0027`：2-byte application opcode + N × 18-byte row，**先清舊 point vector 再重建**。row 是 key、signed category、enabled、XY、radius、兩個 tail bytes。[機讀契約](checkpoint-contract.json)
- S2C `0048`：6-byte application `u16 0x0048 | u16 key | u8 category | u8 status`；第一個匹配既有點才更新，不建立新的。
- 正式 Lua `Tutorial.SetCheckPointStatus(key,category,status)`：走同樣 native `0x544940→0x543B30`。
- C2S `001C`：部分 fallback 發 `u16 0x001C | u16 category | u16 key`，**不是所有 NPC／商店操作的共同入口**。

## 以玩家需求拆出的 Server 待開發項

| 優先 | 玩家情境 | Server 工作 | 接口限制／驗收條件 |
|---|---|---|---|
| P0 | 入城／進地圖看見正確全部互動點 | 編排合法完整 `0027` 快照；所有出口、NPC、Shop、教程點都要存在 | `applicationLength=2+18N`，不得只為新店下發局部 0027 而清掉其他點；無來源不猜座標 |
| P0 | 劇情進度使商店／NPC／出口開放 | 實作 `0048` 差量或與正式 Lua setter 協作，處理版本和順序 | 先 0027 後 0048；不存在點更新無效；狀態採 0/1 |
| P0 | 可互動點的身分、位置與距離正確 | 分別維護 point category/key、NPC、ShopNo、world EntityId、Q slot、map/scene typed IDs | category2 key=ShopNo，category3 key=NPC key；重複 (category,key) 導致第一筆優先，應拒絕 |
| P0 | 玩家點 NPC 出現對話或服務 | 遵循 category 與原資料表／UI handler，接上對話、任務條件、服務請求 | 禁止把 001C 當所有互動的必傳統一入口 |
| P0 | 交易、強化、販售真正生效 | 商品／材料／價格／裝備驗證，資產原子更新，原版結果格式，持久化 | 開啟 UI ≠ 交易完成；未證 Client 欄位不得猜補 |
| P1 | 換地圖、重連後保留已解鎖互動 | 按權威劇情狀態重建 0027 全量快照，避免舊 0048 覆寫 | 須按場景／版本保證正確集合與 enabled；無原生 run token 可直接塞進 wire |
| P1 | MEF/Server 同時切換同一點狀態 | 保存最新權威狀態，定義同一 (category,key) 的更新來源與順序，記錄清除/重建 | Lua 本地改動不自動保存；0048 不會建立點 |

**Server 應保留戰鬥、交易、世界與任務的權威判定**；MEF 可以編排玩家看到的角色、對白、鏡頭、教程、互動狀態。完成某一功能不是要求 MEF 取代整個 Server。

## 可驗收的正常路徑（尚未實機執行）

1. 選定有來源的合法 map、NPC／商店表、點位、模型與資源。
2. Server 發完整 0027，確認同場景各類點正確存在。
3. 同個 category/key 由 0048 或已啟動腳本改成啟用。
4. 玩家在距離內按互動鍵，記錄實際 category/key、UI 路由與**是否**產生 C2S。
5. Server 適當回覆服務或劇情，持久化金錢、裝備、任務／解鎖。
6. 退出／再入，Server 重發完整快照，狀態與持久化保持一致。

**Client 待逆向：**原生 MapList.TRIGGER→.mef 首次 loader/grammar/executor；需新增任意互動點時對應腳本公開 API 尚未證實。**跨功能待整合：**既有可達新內容入口、正確 prepass/formal 與共同 UI owner。**待遊玩驗證：**正常流程的真實畫面、TCP 與持久化。以上不得互相當成已完成。
