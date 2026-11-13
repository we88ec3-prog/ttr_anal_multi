# 村莊商店入口

Town 1／Map 182 可由獨立 `.town-markets.json` 配置商店互動點。市場點用 category 2，key 填 `ShopNo`。Client 查原表取得商戶 NPC，再以目前 Town 與 NPC 找對話與貨單入口。常駐 NPC 用 category 3，key 填 NPC 模型 ID。兩種點必須同送一份完整 `0027`，因為 Client 會替換舊集合。沿用既有 NPC 的出場與任務流程，市場點不需要為四位無常駐模型證據的商戶另生 NPC。 [Client 封包與 ShopInfo 證據](../../governance/client-variants/20261109-mef-town-services/town-npc.md)

[馮德斯商店配置](phindos.town-markets.json)的 SHA-256 是 `fb72a0542bb1d2ab3e1c7f076fabbb34c56d880df5ee971a9d9159e670ddd23d`。ShopNo／NPC 配對來自上述原表，座標為 Server 候選配置。點位和 NPC 的選取圈分離，所有中心都須在靜態 BND 的可走格。目前範例涵蓋雜貨、鐵匠、飾品、煉金與銀行商店的入口。銀行商店與銀行存提款是不同功能。 [JSON Schema](local-town-markets.schema.json)

啟用一般主線後，同時設定 `TARTAROS_LOCAL_TOWN_MARKETS_PATH` 與 `TARTAROS_LOCAL_TOWN_MARKETS_SHA256`。市場配置各自以雜湊識別，主線資料與已保存的任務進度使用原版本。唯讀預檢使用下列參數。

```text
--town-markets <主線檔絕對路徑> <地圖目錄絕對路徑> <主線SHA> <市場配置絕對路徑> <市場配置SHA>
```

TS-01 驗收市場標記、商戶對話與貨單入口，以及既有任務 NPC 可操作。TS-02 驗收雜貨 183 的買賣與資產重登。TS-03 驗收銀行倉庫開窗、存取及重登。 [批次測試表](../testing/S00-CONTENT-BATCH-TESTS.md) · [雜貨買賣規格](PHINDOS-GROCER-TRADE.md) · [銀行道具倉庫](PHINDOS-BANK-VAULT.md)

## 三村配置 v2

[三村候選配置](phindos-alsmeer-rotrua.town-markets.json)的 SHA-256 為 `74e094442a2a1018bd977fcec2922234ce49c34e4889811356d5a6f2f1e8093c`。沿用同一組啟用參數，每個村莊在一個 `layouts` 項中宣告 Town、Map 與市場點。Server 依原始 ShopInfo 雜湊驗證村莊與店家配對，並檢查村莊或店號重複、BND 可走性、點位選取圈與 0027 筆數上限。 [v2 JSON Schema](local-town-markets-v2.schema.json)

| 村莊 | Town／Map | 雜貨、鐵匠、飾品、煉金、銀行商店的 ShopNo → NPC |
|---|---|---|
| 馮德斯 | 1／182 | 1→10028、2→10030、3→10029、4→10031、70→10013 |
| 爾勒梅斯 | 2／183 | 5→10032、6→10034、7→10033、8→10035、71→10013 |
| 羅特魯亞 | 3／199 | 9→10036、10→10038、11→10037、12→10039、72→10013 |

第二、三村新點位為 Server 候選，已用原 BND 的兩層靜態可走格核對，各村出生點都有連通路徑。進村只發布目前村莊的市場點與常駐 NPC，兩者合併為一份 `0027`。v2 為 Server 自訂配置。第二、三村的商店標記、對話、貨單及任務互動列入 TS-15，銀行支票與倉庫列入 TS-16。

## 常駐 NPC 座標覆寫

普通商店可在 v3 的市場列填入 `requiresCompletedQuest`。Server 確認該任務存在於主線配置，只在正常進度已完成任務後才把商店加入 `0027`，開店及買賣也套用同一條件。任務完成後的村莊重建會發布更新。進度指定的測試跳轉不解鎖這類商店。省略條件的市場點沿用既有行為，銀行使用自己的服務入口。 [馮德斯鐵匠開放範例](phindos-shop-unlock.town-placement.json)

同一組市場配置參數可載入 `LOCAL_TOWN_PLACEMENT_V3_NOT_NATIVE_MEF`。在對應村莊的 `npcPositions` 加入 `model`、`x`、`y`，即可移動該村既有 NPC。保留任務引用的模型 ID，未列出的 NPC 沿用主線座標。可在同一檔保存商店點，或在僅覆寫 NPC 的村莊填 `markets: []`。格式定義見 [v3 JSON Schema](local-town-placement-v3.schema.json)。

個別 NPC 可在同一列設定 `interactionRadius`，大於 0 且最多 9 個地圖單位。明確設定時，`0027` 的 category 3 互動圈、Server 主線 NPC 與銀行距離判定，以及市場圈重疊檢查均使用該半徑。省略時沿用原設定，預設 Client 6、Server 9。Client 的實際互動距離仍待驗收。

互動圈的半徑使用既有 `0027` 每列 `+12` 的 float32。Client 從 category 3 路徑送出 `001C`，內容包含分類及 NPC ID。上限 9 沿用現行 Server 授權距離。 [NPC 互動命令](../../governance/s00-iterations/S00-20261103-PHINDOS-NPC-INTENT.md) · [原設定與使用者需求](../../governance/s00-iterations/S00-20261104-NPC-RANGE-AND-SQUARE-RESUME.md)

Server 以覆寫後的座標驗證 BND 可走性、與商店選取圈的重疊及 `0027` 筆數。同一份有效座標用於人物出場、互動與任務 NPC 判定，主線雜湊和關卡圖雜湊不因座標調整改變。現有 v1、v2 市場配置仍可載入。

`npcPositions` 也可為既有常駐 NPC 指定 `direction`（0 至 255）。Server 將它寫入出場 `0007` 的 `+24`，省略時沿用原值，預設為 128。面向與 `0027` 互動圈無關。已知 Client 的 `0007` class 6 分支會建立 CNPC。範例面向由 Server 選定，實際朝向以 TS-25 驗收。 [Client NPC 建立路徑](../../governance/client-variants/20261109-mef-town-services/town-npc.md)

v3 的 `arrival` 可指定進村出生點 `x`、`y` 和面向 `direction`（0 至 255）。正常建隊進村和首次進入該村的主線流程使用同一配置。省略時沿用主線地圖預設值。只覆寫出生點的村莊可填 `markets: []`。

v3 載入時先確認實際出生點可站立，再沿 BND 兩層共同允許的格子搜尋四方向路徑。該村每個有效 NPC 與配置商店的中心都須連通。僅以對角相接的格子不算連通。`--town-markets` 預檢會列出生效的出生點與面向。Client 動態阻擋及實際互動以 TS-25、TS-27 驗收。

[三村範例](phindos-alsmeer-rotrua.town-placement.json)（SHA-256 `1f7054692ff49a5b4dc31e58fa560e7d1a046bd0da96fe6b026584fe32342cac`）保留 15 個市場點，將爾勒梅斯 NPC 10004 設為 (676,647)、面向 64，該村出生點為 (696,691)、面向 128。正式位置與面向仍以實機及來源核對為準。

## 三村買賣

[三村商品設定](three-village.town-trade.json)沿用既有交易服務的設定方式，載入時核對檔案 SHA-256 `1bbc4efa629f258bec3b1f7f5cd8ad6fd81d68a95a051f891fe618dfe70ea5bc`。124 筆條目由 `ShopInfo.xml` 的店家商品、`Product.xml` 的 LeeLoo 買賣價格與 `ItemTable2.xml` 的單件資料核對而來。三村雜貨、飾品與煉金貨單相同，鐵匠各有 27 件不同商品。銀行支票沿用三村共用的一筆定價。普通貨單延續已採用的 LeeLoo 政策，回復卷軸的原表 Battle Point 值保留為來源資訊。

買賣依當前村莊及已開貨單的店號授權。鐵匠、飾品與煉金商品各自佔格。新增品項需要已確認的入包欄位，配置檔提供定價與品項，測試時另填所需 metadata。第二、三村鐵匠商品的穿戴條件已接到 Server。 [三村穿戴規則](EQUIPMENT-WEAR-WIRE.md)

本機已提供可選的普通裝備識別鍵配置，適用於三村穿戴規則內的商品。回復卷軸、支票與煉金材料仍沿用各自的入包欄位設定。 [普通裝備識別鍵](EQUIPMENT-WEAR-WIRE.md#普通新裝備的本機識別鍵)
