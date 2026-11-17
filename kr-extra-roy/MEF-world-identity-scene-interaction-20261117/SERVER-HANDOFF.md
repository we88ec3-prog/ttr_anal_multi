# Server／內容交接：世界身分與事件、場景與互動

此文件是 `extra/roy1` 自有研究交接，不新增正式 RR／REQ ID、不修改 owner、Server原始碼或正式驗收狀態。完整依據見 [世界](WORLD-IDENTITY-EVENTS.md)、[場景](SCENE-INTERACTION.md) 與 [機讀契約](contracts.json)。

## 1. 可直接開始實作的 Server 工作

| 優先 | 需求 | 必須實作的約束 | 不能當成已有能力 |
|---|---|---|---|
| P0 | typed identity registry | 分開 worldEntity、Qslot、model、point(category,key)、relationKey、map、Case／Field、Server instance；記來源與生命期 | 數值相等不自動對應，counter不算可靠ACK |
| P0 | world actor發布與重綁 | 既有合法0007建立；relation record及actor先於S2C000A；清整槽後重綁倖存actor | 0007 hit不upsert；000A miss不晚到重播 |
| P0 | 死亡／移除規則 | Server決定權威死亡、存活群組與獎勵；state3重入去重；移除原因獨立保存 | 死亡動畫、fade、tree erase不是新死亡或群清事件 |
| P0 | map轉場協調 | 先定field/controller/page，明定舊actor保留或退休，再0012、依賴資料、points／控制關聯 | 0012不等於全清世界，同ID會先清points/slots而跳過資源重載 |
| P0 | point快照與delta | 0027全量、唯一雙鍵、合法位置；0048／Lua切換只用既有點，禁止過期跨圖操作 | delta不upsert；沒有native場景generation可新增 |
| P0 | loading／ready／Q收尾 | 分別管理0023/24、0014、Q End/003F/00EB；記未驗證狀態 | 0014只條件清mask1，00EB只清Q等待mask2；任一都不代表全部恢復 |
| P0 | 資源與內容版本 | 綁定原件build、SceneList／map表、實際解析到的資源hash與發布品 | key已寫入不代表resource成功；MEF副檔名不是loader已閉合 |
| P1 | 服務／持久化 | NPC/Shop／出口驗權限、價格、資產、通關、任務與重進一致性 | 開窗、local flag、003F均不等於權威提交 |
| P1 | trace與排他 | 記server-owned instance、選定ID、mapKey、發包順序與實際收到結果；同run／同scene排他 | 無Client證據的欄位要記未觀察，不能幻想有可讀memory/ACK |

這些是相容服設計，不宣稱官方 Server 的內部演算法已復原。Server 可以保留全部通關／戰鬥規則，同時使用已證的本地演出與互動能力。

## 2. 內容工具需要新增的靜態檢查

對 `Tutorial.DeleteObject`，參數須由已知合法低byte0的worldID反向綁定，而不是直接把fullEntityId塞進去；建立時檢查目標型別與controller持有政策。不要生成lowbyte1怪物或lowbyte6NPC的通用刪除指令，不要將回值當成功。

對普通 map轉場，先選 `0012` 或 `lb.ChangeMap` 的語意，不能把共同loader當整體等效。對 Q.LoadMap／RestoreMap，要求單一備份owner、無未解的巢狀使用、明確視覺/碰撞/小地圖一致性與退出政策。

對 points，定義每個map快照與切換步驟的雙鍵域；相同key出現在不同map不能互相沿用過期操作。正式執行與prepass仍按A1契約分離；本輪沒有產生可部署sequence。

## 3. 第一條正常流程驗收（定義，尚未執行）

建議先選一個已有可信資料的普通 Scenario／Mission 轉場，不把所有場景一次混測：

**已確認場景／角色快照 → 收尾舊內容 → 明定舊actor政策 → 0012 → 建立或確認所需world actor及relation record → 合法000A重綁 → 0027發布完整points → 合格0014／loading收尾 → A1切換唯一既有點 → 合格Q等待解除 → 玩家互動 → Server合法轉場／服務／保存。**

這不是宣稱官服每個實際封包必須照此總序；它是本輪consumer所要求偏序的相容測試安排。其他既有流程訊息如0038、角色資料及進場token，沿原規格處理，不擅自省略或填猜值。

驗收至少保存：版本與資源綁定、field/controller/page、worldID與point雙鍵、Server出站／入站訊息及順序、畫面／操控結果、持久化結果。沒有Client欄位觀測手段時，只能以已授權可得證據驗收，不建議偷加hook。

## 4. 四類未完成事項分開

**Server待開發：**上表registry、排序、條件、交易與保存。這些不是Client逆向缺口。

**Client待逆向：**普通world事件到Lua的typed橋、本地生成身分的可靠回報、官方MEF首次loader/grammar，以及不接管普通操控的首次入口B。既有native死亡/刪除證據不能替代。

**資料待綁定／跨功能整合：**指定轉場的真實relation record、原始chart/cluster carrier、portal key、合法spawn／bounds、內容與資源版本。已有W2關聯應直接復用；缺少精確資料時不猜。

**待遊玩驗證：**同場景實際操作、正確畫面/碰撞/小地圖、一次切點、恢復控制、轉場後重綁與Server保存。本輪只讀靜態驗證不提升這些狀態。

## 5. 非本輪交付

沒有新的網路opcode、記憶體getter、Lua callback注入、原始資源修改、執行／附加遊戲、Server正式handler實作或全功能完成宣告。測試中的重複、逾時、斷線等營運項先列契約，不擅自啟動專案暫緩的行為測試。
