# 馮德斯 E 級鍊石製作

## Client 入口與製作回覆

馮德斯 NPC 10015 的類型為 6。原表 `ItemExpertNPCTable.xml` 在此 NPC 的 `ReinforceItem → EnhanceStone → E_Grade` 提供 class 7、grade 1 的分類。Client 的 `639840` 把 NPC 資料帶入本地事件 `F4312`，`5B7750 → 5B8710 → 677080` 開啟製作視窗並載入 NPC 的表項。`CShopConsumptionDlg` 的數量確認事件 `F4426` 走 `674AB7 → 676630`。道具配方視窗 `CItemMakingRecipeDlg` 的 `607310` 亦有同形狀送出，兩者的開啟條件分開管理。

| 方向與命令 | 位置與格式 | 用途 |
|---|---|---|
| C2S `0089` | 7 bytes。命令 u16、`+2` Product u32 LE、`+6` 批數 u8。 | 傳出選取的配方 Product 和確認數量。 |
| S2C `002C` | 既有 12-byte 標頭及變更格位，每格 17 bytes。 | 更新 LeeLoo、Battle Point、材料及成品。若製作視窗登記了回呼，處理格位時數量增加可通知視窗。 |
| S2C `00AD` | Client 讀取至 `+4`。命令 u16、`+2` 有號狀態、`+3` 與 `+4` 各一個無號 byte。 | `4E2670 → 50A560` 送本地事件 `F428B`，`5B9180` 分流給當前開啟的 NPC 或配方視窗。 |

S2C `00AD` 的 handler 位址 `4E2670` 由 `4E1F5F` 登記在接收表的 `+0x56C`，表項指標偏移為 `4+8×command`，可用 `002C` 的 `+0x164` 交叉核對。NPC 視窗的 `6771D0` 會清掉製作回呼，狀態 0 走結果顯示，第一個計數小於第二個時走另一顯示分支。狀態 1 走未成功的結果顯示。兩個計數在官方 Server 分批失敗時的完整語意待證。重建 Server 的成功候選值為 `00, n, n`，整批未提交為 `01, 00, n`。成功次序採資產更新後再送結果，讓視窗回呼可在清除前讀到成品更新。S2C `0089` 仍是既有離隊清理方向。 [背包與錢包](../../governance/client-variants/20261109-mef-town-services/shop-asset-sync.md)

## 配方資料與材料鍵

`CItemCompoundTable` 的 `5190B0` 讀 `Table/ItemCompound.xml`，以 `RECIPE product` 索引，材料 `MATERIAL item/qty` 是每項兩個 32-bit 欄位。省略 `rate` 時 Client 解析為 100。這是表格的解析結果，官方 Server 的機率及其他配方條件仍待查證。

| Recipe Product | 輸出 | LeeLoo／批 | 每批材料 Item |
|---:|---|---:|---|
| 151 | Product 151 ×10 | 800 | 185×40、281×1、282×1、283×1、284×1 |
| 2524 | Product 2524 ×10 | 0 | 14874×3 |

`6767D0` 以配方材料 Item 查物品原表後呼叫 `508F90`，掃描背包格的 Item，累加合資格格位的數量。`508CB0` 以封包內的 Product 查商品表，再在每格分存解析後 Item（`+4`）與 Product（`+0xC`），數量在 `+8`。因此製作材料須先以 Product 映射到 Item，再回寫實際消耗的 Product 格位。Item 185 對應 Product 185。Item 281～284 分別對應一般 Product 281～284 與綁定 Product 23300～23303。Item 14874 是萬聖節糖果，對應 Product 15778；同號 Product 14874 是鎧甲。 [配方資源 SHA 及材料上下游](BLACKSMITH-EQUIPMENT-ENHANCEMENT.md#前兩村材料與費用)

依 Product 鍵掃描同版 `ShopInfo.xml` 的 `SHOP/PRODUCT NO`、`QuestInfo.xml` 的 `Quest/RewardsItem/Item idx`。貨單未列出上述 9 個材料 Product，任務表只在爾勒梅斯 Lv.120 的 Q106 列出 Product 185 一件。重建 Server 現以裝備分解取得結晶石、馮德斯三個狩獵場取得符石，原廠早期來源仍待核對。 [材料路線與待驗](PHINDOS-REFINE-MATERIAL-ROUTE.md)

## Server 進場與驗收

首版接馮德斯正常進村後、可操作且靠近 NPC 10015 的 Product 151。候選規則以配方的 `rate=100` 製作；SQLite 寫入交易中，以有效租約取得錢包及普通背包，依 Item 合計一般及綁定材料，按格位依序耗用。扣款、耗材、清格、新成品或原堆疊加量一次提交。成品上限 255，可用本次耗盡的材料格。提交前任何條件不符不變動已存資產。製作視窗沒有 NPC ID 欄位，Server 用互動場景與距離確認資格。

EQ-B03 驗證正常村莊、製作回覆及資產前後對照。指定 v2 畫面、原版正常取得全部早期材料、鍊石下游裝備強化仍待補。Product 2524 的中繼來源、道具配方視窗的使用資格及其他配方另列待查。 [EQ-B03 驗收](../testing/S00-CONTENT-BATCH-TESTS.md)

## 版本核對

原版 KR BIN、指定 v2 的下列視窗以各自 PE 映射核對一致。 [完整版本 SHA](ORDINARY-QUEST-READY-RESTORE.md)

| VA＋長度 | 共同 SHA-256 |
|---|---|
| `639840+4E` | `aa154cc4d20504dde69ff448367ab8a97cd0287c975a56cda2b31007e58bfc17` |
| `676630+105` | `a255260ad8e9e8e4553dc3c7294d9d709f2fdb8a145cdce8804a03ba358d54c5` |
| `607310+105` | `b44b1c75b98c7ddbc8e7aedd3a3c48f5ff1a249af74c0ea1f6932479be1e609e` |
| `674A8C+33` | `189ad25276d822d1bff3a5e5521641c892b87b5a58e583cd305a51f98832084b` |
| `5190B0+2E0` | `b4628e9f97a3416d3ab2aca81f5333b48f2e0dfebc626ec6162e42d127466a06` |
| `508CB0+C0` | `43ffa08f0d1ed0dfb59bb3ecebb48a6271cc21509438dac0656247c2017da8e9` |
| `508F90+146` | `273fd462d6c9d4ae96855167d94eecfcb95b3f8d85899f750846f3feaffaebba` |
| `4E1F5F+14` | `733f842013d5e39107e9ee768230c62ff0dadf0ca390e1a71f329dbcf38c00a8` |
| `4E2670+11` | `73ac21e7c6562e8b26bc0c43607972e8f91f48f9795de08ac29d3ac007efacd4` |
| `50A560+84` | `7abcaea372492cc06368c780c2fa19d2c7f4e0f2c4f4a67466186792be885f12` |
| `5B9180+4C` | `b4274a6f88d5ed8927186aaae72adbbb3165ef9b1c284305e0a2ef2be8cd0deb` |
| `6771D0+370` | `60e37bfb908214de811f8e7cb5c1c11a279644239cc8bf8f60d206c56d5d5b3c` |
