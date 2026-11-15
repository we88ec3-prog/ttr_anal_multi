# 馮德斯與爾勒梅斯裝備分解

## 原版入口與結果

韓版 `_TownList.xml` 在 Town 1 與 Town 2 均列出 NPC 10015。該 NPC 在 `npctable.xml` 是裝備製作職人、TYPE 6。Client `639890` 建立本地事件 `F4313`，`5B7750` 的對應分支以 `+0x278` 開啟分解窗。放入物品時，`6797B0` 接受背包 1、格位 1～100，讀 Product 記錄 `+0x3C` 的可分解欄位，再記住選取格位。此欄位由 `CProductTable` 讀取 `CAN_BE_DISMANTLED`。Client 另檢查背包空格並對帶有特定 CustomItem 狀態的物品顯示確認。

| 方向 | 格式 | Client 用途 |
|---|---|---|
| C2S `0067` | 命令 u16 LE、`+2` 背包種類 u8、`+3` 1 起算的格位 u8，共 4 bytes。 | 確認分解後由 `678DD0` 送出。 |
| S2C `00AE` | 命令 u16 LE、`+2` signed status。成功狀態為 0，其後每筆 8 bytes，首 4 bytes 為 Product，末 2 bytes 為數量。 | `4E2690 → 50A5F0` 用 `(len − 3) / 8` 算筆數，對每筆派送 `F428A`，再以 `F4289` 送狀態。每筆中間 2 bytes 未被此路徑讀取。 |
| S2C `002C` | 既有背包格位及錢包更新。 | 分解結果窗只讀產出明細，實際物品由背包同步更新。 |

`4E1F6F` 將 `4E2690` 登記在接收表 `+0x574`，依 `4+8×command` 對應 `00AE`。`5B9120 → 679150` 以 Product 查物品後繪製產出圖示與數量，`5B90D0 → 678EF0` 完成提示與成功動作。未提交的候選結果使用 1，走通用失敗顯示。S2C `0067` 的既有快捷欄清除是另一方向與長度。 [背包同步](../../governance/client-variants/20261109-mef-town-services/shop-asset-sync.md)

## 來源與暫定產量

`TalkTable/04_Phindous.xml` 的 31710 說明分解固定產出碎片與結晶石，31711 列出有機率取得額外強化／鍊石。原版每件裝備的確切數量、可選掉落機率和格位排序未取得。連接 `ShopInfo → Product → ItemTable2`，馮德斯 Shop 2 及爾勒梅斯 Shop 6 各有 27 件 E 級武器、上裝或下裝，均標記可分解，Rank 分別為 2 和 3。E 級結晶石是 Item／Product 185。Item 16466 是 E 級裝備碎片，Product 為 18012。兩者堆疊上限皆為 255。

| 承認的來源 | Server 暫定結晶石 | Server 暫定裝備碎片 |
|---|---:|---:|
| 馮德斯 Shop 2，Rank 2 | 4 | 1 |
| 爾勒梅斯 Shop 6，Rank 3 | 6 | 1 |

首版在正常 Town 1／2、角色可操作且靠近該 NPC 時，接受目前背包內這 54 個 Product 的普通獨立實例。綁在角色身上的裝備與帶有未支援 CustomItem 狀態的裝備不進入拆解交易。單一有效租約交易刪除原裝備、發放兩種材料並複用可用空格，全部成功才保存。無額外費用。提交後先送 `002C`，再以 `00AE` 顯示本次增量。2×Rank 結晶石和固定一枚碎片是進度與經濟測試用的 Server 規則。機率產物待另案核對。

Q2849（Lv.8）的目標是按開裝備分解按鈕，Q2850 需要 Q2849 且目標是開鐵匠升級視窗。保留兩個按鈕事件的獨立驗收，分解物品只驗本身的資產與畫面。鍊石配方 151 的另一組材料為 Item 281～284。`ItemRandomCapsule.xml` 的 NO 12714（Product 12981，符文箱）列這四種輸出，現有普通商店與普通任務報酬均無此箱。重建 Server 的早期單人來源另以馮德斯狩獵場實作。 [材料路線](PHINDOS-REFINE-MATERIAL-ROUTE.md)

## 版本與實機

資料來源 SHA-256 為 KR `_TownList.xml` `bba254efd72fac0be6c51c6135423601effcbad02448f46aadec3324e449d660`、`TalkTable/04_Phindous.xml` `91cb3684a6e9bef06ff4f9d454a6d4bfcc81ac41b247e245555dac0d1eda92d4`、`ItemRandomCapsule.xml` `5d29ada7df7cb094adb0367eac504df62eaa44d34d5dbf6c6bf4c6d780ac79ea`。 [基礎商品資料](BLACKSMITH-EQUIPMENT-ENHANCEMENT.md)

原版 KR BIN 與指定 v2 以下視窗各依 PE 區段映射核對一致。 [版本 SHA](ORDINARY-QUEST-READY-RESTORE.md)

| VA＋長度 | 共同 SHA-256 |
|---|---|
| `639890+38` | `e7c2ffcd0bc01c1db511edf23ba593345e8d541547759754abe25456f121e2fe` |
| `6797B0+240` | `4e636effe8d841f481e91fc14bf4462461b7ac0f9a709055896b077dc0df4e38` |
| `678DD0+118` | `95aeb08cd544abe5860248535c519c00f13d62f04ecbd30b48c440f5f9022d25` |
| `4E1F6F+14` | `75e043e93718ab48340e5eab40ee9dd7c85c69c6ca0425238f807491e9fede3d` |
| `4E2690+18` | `2741f0cac3540cc321f8347ee4e38d79581d60e7b04838b9b6b0be850bf55989` |
| `50A5F0+FA` | `544ef3fd714507c843bd829a9b311be480a5490fcb14bc8bdfa938f39da45033` |
| `5B90D0+47` | `e54bdebd9c7f8fbd94fc7516d6dee20de20a0110e0b79525845b17e2f4f5eb9b` |
| `5B9120+52` | `187b910efd0f62d95301884a1f10400a539c0a63734198c7ac7f03bb6398f01f` |
| `678EF0+155` | `01ade9a2579086173b46dad65afbc825b38564d0b756f77339bfb59697849a15` |

EQ-B04 先核對分解開窗，接著以可拆普通裝備確認資產及重登。馮德斯 Q2849／2850 的開窗事件及指定 v2 的圖示、提示仍待查。 [批次驗收](../testing/S00-CONTENT-BATCH-TESTS.md)
