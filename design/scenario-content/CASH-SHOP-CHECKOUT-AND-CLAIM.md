# 商城付款、領取、時裝替換與過量存倉

2026-11-18 接續 [保管箱保存](CASH-SHOP-STORAGE.md)。來源基準為分析庫 `6bb0fd86e0490fa87453281677398cd11d76b4da`、私有 Server `d0e6e035bfb3c907a72826af74547f894a16629d`。本輪加入真正的付款與領取交易；工程驗證使用隔離錢包資金，不宣稱官方付款服務、指定 v2 遊玩或完整商城所有商品效果已完成。

## 原表投影與供貨政策

[商品目錄](kr-source.cash-shop.json)由 [build_catalog.py](../../governance/client-variants/20261118-cash-shop/build_catalog.py) 唯讀投影原 `CashProduct.xml → Product.xml → ItemTable2.xml`。來源 STP、三個 member 與 parser 都先核 SHA，不執行 Lua 或 Client。目錄含 1,311 個 Product、1,411 個價格選項，每列保留 Product、數量、期間、選項、整組價格、原順序的 1-based priceIndex、Item、class、堆疊上限與可穿戴資格。

| 來源／產物 | SHA-256 |
|---|---|
| 原 Table.stp | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |
| CashProduct.xml | `77b3f5d521f3c01948210f8c0895c6eb4e5b7d9a4bc6914e11d6608fd4bcd5e3` |
| Product.xml | `8c9262f81ca4dae6b62be5d3373bd06d6e96e7470b4227fc73c98fda4e88457c` |
| ItemTable2.xml | `7095f005d26a67694112ce4c89d2725478d2287181e639fb18956b3d0bf5e2e2` |
| kr-source.cash-shop.json | `1b760b16ab24c4ba4b6f96ac6ae2bdb2b98c6fbf34eaad9b7b777f579e89f4dd` |

檔案是 `LOCAL_CASH_SHOP_CATALOG_V1_NOT_NATIVE_MEF`，不是原資源。初版 Server 供貨政策只採 NOW_SELLING=1、SELLING_STATE=1、SELLING_TYPE=0、結束年 9999、期間 0，且排除 class 30 的直接效果分支。共有 898 個價格選項被標為 available。其餘列保留查證，不表示全部商品都能購買或使用；限時、促銷及特殊效果仍待獨立開發。這個篩選是相容服決策，不聲稱原服的今日上架規則。

## 購買與領取的提交邊界

正常廣場或村莊、有效遊戲租約下，C2S `00AC` 按原 `2+7*N` 讀取最多九列。請求沒有價格；Server 按四欄完整鍵查供貨目錄，對每列按原表的整組價格計費。同一 SQLite 寫入交易內檢查餘額、產生每列獨立的保管箱雙鍵、寫入記錄並扣 Garnet。九列以內全批提交；跨封包原子性沒有假稱原生。

提交後發布 `00DD → 00E3 → 00DF`：餘額、追加新保管箱列、明列結果。`00DF` 採來源的狀態 1，16-byte 列為 `1:u32, Product:u32, priceIndex:u32, 0:u32`，避免無列 fallback 將整個本地購物車誤當本批已付。第一欄 1 沿來源 fallback 的既有值，第四欄在已核 consumer 未讀。未提交時可走已知狀態 3 提示分支；這是 Server 拒絕策略，精確錯誤分類與文字仍待核，非正流程測試保持暫緩。

保管箱 key 由本機新 GUID 的前兩個 DWORD 產生，與背包 metadata 分開。時間原值採本機購買時的 Unix 秒，是 Server 選擇；原服保留期限／時基尚未證實。本輪只發永久品，沒有自行實作七日回收或期限入包。

C2S `00AD` 的雙鍵只查當前帳號。領取在同一寫入交易中合併可堆疊格、依原 `quan` 分配新格、產生時裝獨立 GUID／plain metadata，再刪除保管箱記錄。需要的格位不足時不提交。提交後先 `002C` 更新背包，再 `00E3` 以 Product=0 移除精確雙鍵。沒有把 S2C `00AD` 的同號 consumer 猜為本操作的成功 ACK：它會沿 `50A560 → F428B → 5B9180` 送到另兩個可見 UI，本輪不新增該回覆。此處選用既有背包與保管箱更新器，實際 UI 行為仍待驗。[原收發分析](../../governance/client-variants/20261118-cash-shop/README.md)、[保管箱欄位](../../governance/client-variants/20261118-cash-shop/BALANCE-AND-STORAGE.md)

## 時裝與多格堆疊

目錄中可穿戴的 class 17、18、19、32、36、37 分別對應格 6、7、8、9、10、11。工具要求原 EQUIP_POS_LIST 完全相符，USE_LIMIT 最多一列且只有已支援的 char 條件；資格不靠 Product 數值推測。Server 穿戴仍查帳號角色所有權。目錄 rule 隨已保存裝備 view 回送 Network 層，重開儲存層後可重建 `0070`，不把新時裝塞進三村普通商店售價表。

原背包的每商品唯一索引不能容納 400 本商品。本輪正常案例因此先發現 UNIQUE 錯誤，再升級 V26：新增 `cash_stack`，普通非獨立商品保持原單格唯一約束，商城來源格可依原上限分格。槽位、獨立裝備 ID 與交易原子性仍保留。倉庫對商城商品按相同上限驗證，允許背包已存在另一滿格時分批取回。

外觀沿既有 `00F9/00FA` adapter 加入上述六個裝備格；穿脫也遞增版本。既存修改 Client 快照 `anal/inventory-catalog-snapshot.json` 的固定 SHA 為 `8950cfb3741644876180421f23cf7e41f2407b2079e33a59fc28e1d15d7d3ab0`。864 個時裝 Item 中 862 個有 `(Item,0)` 鍵；兩個缺鍵不補造。測試 Item 13401 的 component type 為 11，與普通武器 type 1 分層。這只是既存快照查詢，不能代替指定 v2 視覺驗收。[投影](../../governance/client-variants/20261118-cash-shop/cash-equipment-models.json)、[重現工具](../../governance/client-variants/20261118-cash-shop/verify_equipment_models.py)。時裝 OPTION_LIST、套裝加成及更多屬性尚未接入戰鬥能力值，不宣稱只穿戴就完成全部數值效果。

## 正常流程工程驗證

隔離帳號使用正常 profile／命名與既有教學伊希莉亞授予接口，初始化 1,000 Garnet，從普通村莊 session 發出五列購物車：

| Product | 購買內容 | 費用 |
|---|---|---|
| 29769 × 2 列 | 各一件伊希莉亞時裝武器，Item 13401／slot 10 | 88 × 2 |
| 5238 × 2 列 | 各 200 本回復之書，原價格列索引 2 | 56 × 2 |
| 27461 | 一件內容點數書 | 18 |

付款共 306，餘額 694，購買時背包保持空。重開儲存層與正常世界初始化後五筆保管箱仍在；從實際 C2S 雙鍵逐筆領取後，保管箱為空，400 本分成 255／145。145 本存倉後分成 100／45 取回，總數仍為 400。兩件時裝各有獨立身分，依次穿上時 `0070` 先於背包刷新，`00FA` 含 Item 13401；舊件存第 79 格、重開後取回再替換，換下的新件及多餘 145 本可銷毀。末狀態只剩原 255 本、內容點數書與一件已穿時裝，Garnet 保持 694，LeeLoo／BP 未被商城扣改。

這是直接 session／SQLite 的 OFFLINE_SYNTHETIC 正流程，尚未取得商城專用完整 TCP 旅程與指定 v2 的實際入口、購物車結果視窗、領取、拖曳和渲染證據。第一次小樣本通過後，增加大量購物案例發現舊唯一索引問題；修正後才做最終完整 HappyPath。原陰性／故障／重送／安全與壓測不在本輪執行。

最終 Release Host 與檢查器建置均 0 warning／0 error；`Category=HappyPath` **565/565** 通過。目錄從原件重算後逐 byte 相符，既有 26 個購物車／餘額／保管箱原件視窗再次通過。既有修改 Client 快照投影另以固定 SHA 重現；這些都不提升指定 v2 實機狀態。

## 配置及接續

同日接續的 [TCP 正流程與 Host 配置驗證](CASH-SHOP-TCP-ACCEPTANCE.md) 已把新帳號旅程後的商城正常重登、付款、領取、時裝替換及銀行／銷毀接到實際 loopback socket；另完成 `-IncludeCashShop` 的隔離 Host preflight。前節「尚未取得 TCP」為本頁初版階段範圍，最新證據以接續頁為準。指定 v2 與其餘商品功能仍未完成。

Host 增加 `TARTAROS_LOCAL_CASH_SHOP_CATALOG_PATH`（絕對 `.cash-shop.json` 路徑）與 `TARTAROS_LOCAL_CASH_SHOP_CATALOG_SHA256`；必須配現有 `LOCAL_PHINDOS_GROCER_CANDIDATE` 交易模式。未提供目錄不開放新付款／領取。Server 私有 `content/` 保存同 SHA 投影；完整原資源及快照留本機，不上傳。

本輪沒有換版或操作 Client。批次實機項目集中到 CS-01；下一步補完整入口／TCP 對照、特殊商品與期限、時裝數值及未知模型鍵，再依排程驗收。
