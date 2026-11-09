# 馮德斯商店｜NPC 身分、販售、強化與交易的離線驗證

適用 KR 主程式 `Tartaros.bin` SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` 與 `Table.stp` SHA-256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。以原 STP/STPI 目錄、EX 解碼後 XML、PE 指令、RTTI、vtable、呼叫者與事件消費者定向查證。舊 Ghidra 偽碼用於定位，關鍵欄位與分派另從原 BIN 讀取。沒有執行遊戲、修改 Client、傳送封包或測量實際原服交易。以下命令均指小端應用層內容，只有對應的 subsystem／方向／狀態下才有這些語意。

## 哪些商店功能能交給關卡規則

- **服務提供者與入口可由關卡規則選擇。** 在選定的鎮中，若以原生可互動的 NPC 身分呈現，Client 有實際的依 NPC 類型顯示選單、以鎮和 NPC 配對本機店表及處理點選的實作。關卡可定義「何時讓哪個商人可互動」與候選佈點。此次沒有建立普通鎮自製 MEF 的腳本載入、產生具原生互動身分 NPC、寫新服務表三者的完整鏈。只在鏡頭內擺出演出物件，不能代替商店 checkpoint、服務鍵與交易資格。
- **商品陳列與強化視窗有既有 Client 資料及程式。** 馮德斯鐵匠 NPC 10030 的強化入口能直接追到原件；Server 不需自行拼畫面。未證腳本能為任意 NPC 注入全新商品、改寫本機選單或重新定義強化語意。相容服應先引用同版店號、商人、商品和既有服務。
- **購物、賣回、強化會對外送出請求。** 原生另外有結果 UI。重建規則可以描述允許的服務、價目來源、條件、消耗與結果策略，實際扣款、物品異動和持久保存是 Server 開發需求。客戶端確認視窗、成功文字或成功聲都不構成交易提交證據。

## Town 1 原表

| Shop.NO | NPC | Shop.TYPE | 名稱釋義 | 商品列數 | NPC 表 TYPE |
|---:|---:|---:|---|---:|---:|
| 1 | 10028 | 1 | 雜貨店 | 5 | 11 |
| 2 | 10030 | 2 | 鐵匠舖 | 27 | 12 |
| 3 | 10029 | 3 | 飾品店 | 3 | 13 |
| 4 | 10031 | 4 | 鍊金店 | 6 | 14 |
| 70 | 10013 | 7 | 銀行商店 | 1 | 1 |

五個店共 42 筆商品列。`ShopInfo.xml` 的資料列沒有位置欄位。`_TownList.xml` 的 Town 1 名單有 9 個 ID，五個商店 NPC 中只含 10013。其餘四個店不可因缺席就判定不存在，也不能用這兩張表推定原服 X/Y。銀行商店有貨品不能替代其餘銀行功能驗證。雜貨店列出商品 183，`Product.xml` 的 183 對到道具 183「一般復活卷軸」，LEELOO=2000、SELL_LEELOO=200。這組數字是原表基準。鐵匠的 27 筆是貨架資料，強化選項另由服務選單解出。

## 原生服務分派與商店開啟

1. `4FB9C0`（CShopMgr 資料載入）在 `4FBA0B` 送入 `Table/ShopInfo.xml`。表列 NO、TOWN、TYPE、NPC 及 PRODUCT.NO 分別由 `4FBB6D/4FBB9F/4FBBCD/4FBBFB/4FBD70` 附近的 XML 取值流程使用。每列長 0x3C。條件 `1≤Shop.TYPE≤4` 時，`4FBD15 → 526F60` 依 NPC ID 找表，`4FBD2B add ecx,0xA; 4FBD2E mov [eax+0x20],ecx` 將商店類型映至 NPC 類型。TYPE7 不走這個覆寫。選單 `6389FC..638A3D` 用 NPC ID 查 FE1BD0 的資料樹，取同一欄 +20，作為 byte key 查本地選單向量。 `638A66..638AA3` 枚舉功能選項。
2. 點擊委派 `638DE0` 比對 UI 控制 ID，槽基底 +D8、每槽4 bytes。初始化 `6370C0` 為 NPC 類型 12 寫入選項 29（`637D61/D68/DBC`）、10 與4。功能29的目的欄位 `+D8+29×4=+14C` 在 `638810` 綁 `639EF0`；`639F17` 建本地 FoxUI 事件 F42F6，`5B7750` 中該分支 `5B77F2` 取得 UI owner+264 供視窗操作。強化結果回傳亦在 `5B8CF7` 取相同 +264，之後呼叫 `686F40` 的強化回饋。對應 RTTI 為 `FUI::CShopLevelupWnd`，vtable C3718C，UI cache ID 173。由此可具體歸屬 10030 的原生強化入口，不以「鐵匠」名稱推理。功能4呼叫 `6392A0`，F42EA 的 `5B8540` 將事件的兩個值放入 shop window +F4/+F8，再顯示交易視窗。
3. CShopTradeWnd（vtable C36BBC，+D0 為 683D30）在 `683D9B → 4FB960` 用兩鍵查 `[row+4]=town、[row+C]=NPC`（`4FB990/995`，stride 0x3C）。命中後檢查 row+8 類型。普通類型1–4的此分支，`683DD4..683DF1` 以 shop row 開頭的 NO 組 `C2S 001C, u16 2, u16 Shop.NO`，6 bytes；`683DF1..683DFB` 走既有 sender slot0。這與出口的同號 001C 有不同類別／資料鍵。TYPE5–7 的分支在 `683DC6 → 4A36E0`，以窗口 +F8 傳入 ID 的低 WORD，送 4 bytes `0086 + u16`。兩段均有傳送條件。此界線不證 API 能對全新 ID 建店。
4. 原表另有 Town1 的 NPC 10015「裝備製作職人」（npctable.TYPE=6），`ItemExpertNPCTable.xml` 有該 NPC 專頁、條件與 ITEM 節點，和 `ItemCompound.xml` 配方、`ReinforceStoneCompound.xml` 強化石合成另屬資料域。裝備製作、裝備升級、石頭合成與一般購買應分服務實作，不能把 00A1 套為所有強化／合成的通用封包。此輪不宣告其餘服務的所有 wire／授權閉合。

## 普通購買、賣回與強化

| 玩家操作 | 原始 Client 發送 | 已證接收效果 | 待開發或再查 |
|---|---|---|---|
| 單項購買 | `6823C0` 有 QUANTITYDATA_BUYITEM；`682640` 計價格與本機金額、記 selected product 與 quantity 在 +160/+164。確認事件 F43AC → `682218 → 682A00`，`682A3F → 4A3720` 寫 `0027:u16, windowContext:u8, product:u32, quantity:u8`，8B。context 來自視窗 +D0，未將它猜成 NPC ID | 一般 S2C 表 `4ADFFD` 為 +184→4B3760，即 opcode 0030。取 payload+2 WORD。0x10 分支加 bit0 走字串索引 DF=kShopBuy，部分不成功分支 E0=kShopBuyFail | 單一店的合法商品、數量、價目、可用幣別、足額、入包及餘額落盤。證據未將特定請求與每一種回覆固定配對，也未證 0030 會落帳 |
| 背包單格賣回 | `51C712..51C74D` 自 Product 的 SELL_LEELOO 寫 +34；`602ABB` 取價乘數量並建立 F43AE 賣出確認。確認後 `5FF57F → 602740 → 4A37B0`，`4A37C9` 寫 0020；5B 單項包由 3 個 bytes 提供。這條已查路徑的三項為背包種類 1、選取格索引與數量 | S2C 0030 在沒有0x10、但有0x08 且 bit0成立時選 E1=kShopSell，普通失敗分支 E2=kShopSellFail | 驗所有權、格位、數量、可售性、回收價、出包與入帳。異常碼／批次出售／完整背包同步另查 |
| 裝備強化 | CShopLevelupWnd vtable +15C=686B90，F43A9 確認路徑 `686F23 → 4A3BF0`；`4A3C03` 設 00A1，`4A3C31..39` 送 slot0 的10B。欄位寬度為 u16 opcode、u8、u8、u32、u8、u8；依視窗所選資料填入，保留尚未命名的欄位 | CGlobalStatus 分派 `4E1ECF` 在 +6CC 登錄 4E3420，即 00D9。4E348A→4DD060，4DD0C6 從 payload+2 讀有號結果 byte；4DD0D3將其送入 F427C UI event，5B7C9B→5B8CC0→686F40。值0通過 686F72/74 選中 686FB4 的 WEAPON_LEVELUP_SUCCESS；其他結果各有分支 | 驗物品實例、等級、類型、材料／費用；授予實際成功／失敗／損壞、更新背包與屬性、持久化。需配對狀態增量與回覆順序，不能只送成功視窗 |

`ItemEnchant.xml` 由 `514600` 載入 EQUIP_LEVELUP／EQUIP_REINFORCE，`ItemEnchantCharge.xml` 由 `514740` 載入。同一版例子是 EQUIP=1/LEVEL=1 的原列 SUCCESS=80、FAIL=20、BROKEN=0、RATIO=10；另費用表 CLASS=1/RANK=1/LEVEL=1 的 CHARGE=375。這些是兩表各自的資料樣本；沒有由這兩列單獨決定一件具體裝備的收費或最終伺服器亂數。

## 查證對照值

| 原 XML 成員 | 解碼後 SHA-256 |
|---|---|
| Table/ShopInfo.xml | `2c61fee77c6a8b24bdb350d1639818a2d9f871562c9b97eb51a3d15416699b0b` |
| Table/npctable.xml | `a727fceb64a8b58dc98983619fc73b131c15a6be1eec132c1124f2c57b4aa31d` |
| Table/_TownList.xml | `bba254efd72fac0be6c51c6135423601effcbad02448f46aadec3324e449d660` |
| Table/Product.xml | `8c9262f81ca4dae6b62be5d3373bd06d6e96e7470b4227fc73c98fda4e88457c` |
| Table/ItemEnchant.xml | `76f3e1c67175fbedcbc3c18885c5b01ca0aad32fe227fd73b9b6c9ccb4e2832a` |
| Table/ItemEnchantCharge.xml | `6751fa43022be88a87d80c4f2e52c0a354128afe5278daa510f169062feb0990` |
| Table/ItemExpertNPCTable.xml | `3b4ea6a952e4551528340b2ca8f66e97d34a463a0999dbcc4795758b622fe2b0` |
| Table/ItemCompound.xml | `d4691667dabe8d107afc256c865b3f9c784d0bb7f7aa76ad8d2fe5f564a9c106` |
| Table/ReinforceStoneCompound.xml | `d1d6f575bcd5c4a7afa75509f245c16ed6997544dcc699528ee33f8ed6138f42` |

最小驗收案例為同一 Town1 先選雜貨 10028、核對 183 顯示與購/售，再選鐵匠 10030 核對原生強化選單。測試應分別保留傳入的識別、請求、裁決後持有數、金額或裝備等級及重登結果。資料列與本輪原始 bytes 只證現有 Client 接口；原服持久化規則、完成即時操作與自製 MEF 執行入口均未實測。
