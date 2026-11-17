# 購物、換裝、銷毀與倉庫驗收

2026-11-18 S00 接續目標。分析基準為本庫 `c5db5fd2f6ab1122efeddf62a81d0d64680ea5c4`，Server 基準為 `94b4ddc61e08101afd2334d0916ed0d0bca2df43`。使用者要求購買後能在背包換裝，過多道具可銷毀或存倉，分析與規劃公開於本庫，Server 實作保留於私有庫。

## 正常流程的證據與缺口

| 使用情境 | 現行 Server 與離線證據 | 指定 v2 尚待核對 |
|---|---|---|
| 開 NPC 商店、購買 | 按目前 Town、ShopNo、距離、貨單及價格驗證，SQLite 原子提交錢包與背包，發布格位與交易提示 | 貨單、確認、入包及餘額畫面 |
| 購得裝備直接穿戴與替換 | 保存獨立裝備 ID 與 metadata，舊裝備回到新件原背包格；正常登入恢復 | 拖曳、裝備欄、能力面板與 3D 外觀 |
| 換下舊裝備存倉 | 護甲 11250 存第 79 格，重登到另一村取回後能再次穿戴；既有武器及卷軸跨村路線保留 | 銀行視窗、分頁、拖曳與格位同步 |
| 銷毀過多道具 | 整格銷毀卷軸及背包內 +1 裝備，移除強化列，保留快捷綁定並發布數量 0，正常登入仍維持結果 | 原生一次／二次確認及成功提示 |
| 背包與倉庫容量 | 背包 40→45→50 格、倉庫原有擴充接口與容量保存已實作 | TS-44 背包畫面；倉庫費率與 Garnet 畫面另依銀行規格 |
| 點數商城購買與領取 | 已接原表查價、付款／保管箱共同提交、領取入包、時裝替換與商城多格堆疊；商城 TCP 旅程及隔離 Host 配置通過，566 項正流程通過 | 指定 v2 入口／付款／領取／換裝及銷毀存倉；期限、特殊商品與時裝加成另待開發 |

NPC 商店、裝備、倉庫與銷毀已有各自規格及離線收據。點數商城也已接入共用資產交易，詳見 [付款與領取](CASH-SHOP-CHECKOUT-AND-CLAIM.md)。整體可用性仍須指定 v2 正常操作證據，不能將離線通過視為完整商城驗收。

最新接續 [商城道具使用](CASH-SHOP-CONSUMABLES.md)：5238 全資源回復、27461／27462 的 CP 入帳與商品冷卻已接；多格快捷總量、銷毀後保留計數及正常 TCP 使用入帳有專項覆蓋。時裝容量與套裝加成仍待開發。

再接續 [時裝資源容量](CASH-EQUIPMENT-RESOURCE-CAPACITY.md)：目錄 864 個 Item 的 SP／MP OPTION 已逐件核對，候選 Server 已接穿脫、同格替換、重讀、角色面板、戰鬥與回復。套裝與指定 v2 狀態保持待驗／待開發。

[NPC 買賣](PHINDOS-GROCER-TRADE.md) · [裝備穿戴](EQUIPMENT-WEAR-WIRE.md) · [倉庫](PHINDOS-BANK-VAULT.md) · [銷毀](BAG-ITEM-DESTRUCTION.md) · [批次驗收](../testing/S00-CONTENT-BATCH-TESTS.md)

## 點數商城來源導航

目標為原 KR BIN SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。以下地址取自已保存的大量反編譯，狀態為 `saved-unreviewed`，用途是縮小後續查證範圍。函式內容尚須原指令、交叉引用與收發上下游核對。

| 候選函式 | 已保存偽碼中的導航線索 | 偽碼 SHA-256 |
|---|---|---|
| `413300` | `FUI::CCashShopPanel` 建構 | `7e8cfdf3ca03be614d753326ed7bd847e6722104f80368c022079e68f788e540` |
| `511E40` | `CASH_PRODUCT_LIST`、`PRODUCT`、`PRICE` 解析 | `e621e131bb5fd6f23bef0c4dbcb024a5b321abe8383b4c0fd1e4f3400ae8ec67` |
| `5DBAF0` | `FUI::CItemSlotCashShopCart` 建構 | `b646e5efba83fff11d1246b68d3a2c41f83a94dc51fcc1dbb68233f4cb7610ad` |
| `5DBD40` | `FUI::CItemSlotCashShopInven` 建構 | `74cfc657b510f8da0b46374a5be4064c41d7808fbeccec0a51a73b5ed322a428` |

2026-11-18 追加 [購物車與保管箱收發核對](../../governance/client-variants/20261118-cash-shop/README.md)。原件與指定 v2 的 13 個視窗位元組相同，購物車 `00AC`、專用 S2C `00DF`、一般保管箱領取 C2S `00AD` 及相關結果 consumer 已定位。來源檢查同時核對原表 1,311 筆商品。付款幣別、保管箱身分、初始化及領取入包仍待接續，Server checkout 尚未實作。

同日追加 [餘額與保管箱欄位](../../governance/client-variants/20261118-cash-shop/BALANCE-AND-STORAGE.md)。`00DD` 已接入 Server 正常資產初始化與銀行擴充扣款後的餘額發布，本機沿用現有 Garnet。原件另定位 `00E2/00E3` 的 19-byte 保管箱列。購買與領取交易仍待實作，指定 v2 的餘額顯示加入既有 TS-06。

同日接續 [保管箱保存與初始化](CASH-SHOP-STORAGE.md)：V25 保存帳號雙鍵與原始欄位，正常世界初始化發布 `00E2` 全量及必要的 `00E3` 續列。兩筆資料為隔離 SQL 預置；564 項正流程測試及全新帳號 Q144／早期 RAID 離線回歸通過，沒有將預置升格為購買證據。

來源索引為 `kr-bulk-roy/<BIN SHA>/index.jsonl`，每個地址的 raw 路徑與 SHA 可由 `lookup.py <address> --metadata-only` 讀取。使用前沿用 [大量反編譯的審核邊界](../../shared/integrations/T01-BULK-20261026-02/README.md)。

## 點數商城接續驗收

1. 原 UI 入口、允許場景、開窗時向 Server 發出的請求，以及初始化所需的回覆。
2. 原表鍵、數量、期間、價格及版本化目錄已投影；本機沿用 Garnet。期限、促銷及特殊效果的業務規則仍待接續。
3. 購物車 C2S 與 S2C consumer 已接；[商城 TCP 旅程](CASH-SHOP-TCP-ACCEPTANCE.md)已驗證正常登入／primary、付款、領取、換裝、銀行及銷毀；原 Client 連線觀察仍待驗。
4. 購買提交至保管箱、C2S 雙鍵領取及背包／保管箱更新已接；指定 v2 開窗與格位顯示待驗。
5. 付款與記錄、領取與移除各自原子提交，獨立實例與重開保存已有正常證據。時限品未開放，時裝 OPTION_LIST／套裝加成待開發。
6. 已有實際 C2S 合成購買時裝及堆疊品的 session 路線，接換裝、銷毀、存倉；補 CS-01 的指定 Client 完整操作證據。

後續沿既有租約、持久化與背包發布元件補齊上述缺項。此頁是現行交付查核及接續計畫，正式 REQ／RR／GAP 的狀態仍以既有台帳為準。
