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

第二、三村新點位為 Server 候選，已用原 BND 的兩層靜態可走格核對，各村出生點都有連通路徑。進村只發布目前村莊的市場點與常駐 NPC，兩者合併為一份 `0027`。v2 為 Server 自訂配置。第二、三村的商店標記、對話、貨單及任務互動列入 TS-15，交易與銀行存取仍待接通。
