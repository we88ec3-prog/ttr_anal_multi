# 鐵匠裝備強化

## Client 請求

馮德斯 Shop 2 的鐵匠是 NPC 10030，爾勒梅斯 Shop 6 是 NPC 10034。兩家 `ShopInfo.TYPE=2`，Client 依既有 NPC 服務類型 12 開啟 `CShopLevelupWnd`。普通買賣仍有獨立入口。 [NPC 與視窗分派](../../governance/client-variants/20261109-mef-town-services/shop-services.md)

`688BF0` 的背包路徑檢查種類 1、格號 1–100，讀相應 32-byte 格列。成功選取時 `689185–689199` 把兩值存到視窗 `+F4／+F8`。確認時 `686F0B–686F27` 依序取這兩欄及三個控制值傳給 `4A3BF0`。應用層長度為 10，欄位如下。

| 位移 | 欄位 | 證據 |
|---|---|---|
| 0 | `00A1:u16` | `4A3BF0` 建封包 |
| 2 | `bagKind:u8` | 視窗 `+F4`，普通背包路徑為 1 |
| 3 | `bagSlot:u8` | 視窗 `+F8`，普通背包使用 1–100 |
| 4 | `primarySelection:u32` | `686E6F` 自第一個子選單取值，選項 0／1／2 對應傳值 0／2／3。其他選項的語意待驗 |
| 8 | `secondarySelection:u8` | `686EBB` 自第二個子選單取值，無選取分支為 `FF` |
| 9 | `confirmFlag:u8` | 視窗 `+172h`，事件 `F437A` 確認／取消可寫入 1／0 |

指令證據可確立欄位來源和寬度。兩個選單的實際文字、平常點法帶哪個值，以及優惠券與保護材料的語意，仍需比對指定 v2。請求不含 Product、CustomItem ID、費用或結果。Server 應用背包格讀該件裝備的當前實例，再查等級和材料。

## 裝備等級與結果

選取裝備時，`688DF3–688E15` 使用背包格 `+10／+14` 兩個 DWORD 查 CustomItem。命中後 `688E1B` 讀 CustomItem `+30h`，加一作下一級，並限制下一級不高於 20。費用表解析器 `514F50` 會將 `LEVEL` 減一作索引。如此可以區分現有強化等級、目標級和角色等級。

S2C `007B` 由 `4E3160` 檢查版本 DWORD 1，再交 `4DCA20`。表頭 `+2` 是 u16 記錄數，資料從 `+8` 開始。每筆固定段為 27 bytes，前兩個 DWORD 是 CustomItem 查詢鍵，固定段 `+0Bh` 是其後 3-byte 附加列數。固定段 `+17h` 的 bit 0 成立時，附加列後的第一個 byte 讀入 CustomItem `+30h`，也就是強化視窗讀取的等級。其後還有另一個附加列計數 byte。若 bit 2 成立則另讀尾段。有存活的既有附加欄位時需保全它們。Server 將來應先發送提交後的背包與 CustomItem 更新，再通知結果。重登亦需回填強化資料，讓背包、倉庫及裝備查同一件實例。

S2C `00D9` 經 `4E3420 → 4DD060` 讀 `+2` 有號結果 byte，再送到強化視窗；0 走成功顯示。結果窗本身只提供 UI 回饋。其他狀態及更新順序仍待對照。 [裝備資料與背包查詢鍵](EQUIPMENT-WEAR-WIRE.md)

下列視窗依各自 PE 區段映射核對，原版 KR BIN 及指定 v2 的位元組一致。 [版本 SHA](ORDINARY-QUEST-READY-RESTORE.md)

| VA＋長度 | 共同 SHA-256 |
|---|---|
| `4A3BF0+50` | `26c39c85a6623ca6887d705ecfacaf63d7389f9ca494ccb8afdb8ca949520455` |
| `686E50+E0` | `ed7713e3b1db38d75f05c6b2d1132bf67813df6b47d6abaebb16139dc9e5a511` |
| `688BF0+100` | `dd1bfceaaef56cd8ca9c572a3b19a25e80ff15b0cab5f78991dd6ba560ed0a03` |
| `688DF0+A0` | `5fb956010054a6321b821318a1e309c2addca7f096a709e0c80ee10b5b527c8d` |
| `689080+120` | `504b0623468bb981d1da9cf88e0f89922978490dd0e303e6a8648d9680fa872c` |
| `4DCA20+110` | `945199b40db3c5f0c6e781cdad4bf9a4eea913488c1b58b94706a40e683275c0` |
| `4DCC70+C0` | `1ed019fed31e944f952e1d14bba8f4a22a5264305c6c083998f00fa453e18fec` |
| `4E3160+B0` | `9c46cf5d2cdabd915ee1a4363c4a71d9a15a286656c3ffe78cb2fa68e5765070` |
| `4DD060+A0` | `92582b20217e081bf6715158b8f24ffbc0c217f0038bf8094e0a9630fdb1c402` |

## 前兩村材料與費用

連接原版 ShopInfo、Product、ItemTable2，兩間鐵匠各有 27 件可強化商品，class 1／2／43 各九件，全部 Grade 1。Shop 2 的 Rank 全為 2，Shop 6 全為 3。以 class、rank 和目標 +1 查 `ItemEnchantCharge` 與 `ItemLevelupRequireTable`，得下列資料。

| 店家 | class | Rank | +1 費用（LeeLoo） | +1 石數 |
|---|---:|---:|---:|---:|
| 馮德斯 | 1／2／43 | 2 | 555／294／128 | 5／4／4 |
| 爾勒梅斯 | 1／2／43 | 3 | 945／504／224 | 6／5／5 |

Item 151 為 Grade 1 的 E 級鍊石，原說明指定用於 E 級裝備，可對應 Product 151／2524。2524 在 Shop 31／109 的對戰商店，前兩村現行普通貨單沒有此項。前兩村表列直接獎勵 Product 151 的 Q20、Q107、Q268、Q536～538 都標 Lv.120，早期正常旅程沒有開放。待確認可走的單人材料來源，避免把鍊金商店售賣的各色強化石當成同一品項。

`ItemCompound.xml` 提供另一條來源。Recipe 151 標記費用 800、輸出 10 顆，需 E 級結晶欄位 185 ×40，以及 281／282／283／284 各一。Recipe 2524 的費用欄為 0，輸出 10 顆，需材料欄 14874 ×3。後者在 ItemTable2 指向萬聖節糖果，對應 Product 15778；同號 Product 14874 則是上身鎧甲。這是查證 `MATERIAL item` 鍵空間的直接對照案例。應依製作視窗取表與材料消耗路徑確定實際鍵空間、提供者和前置，再決定可由正常單人路徑使用的配方。

`ItemLevelupSetIDMapping` 將 class 1 對到 Set 1，class 2／43 對到 Set 2。依 Rank 2／3 可各自找到 `ItemLevelupInfoSet` 的 Ratio 1／2，+1 兩組都是 100000／100000 成功。舊 `ItemEnchant` 的 EQUIP 1／LEVEL 1 另列 80／20。兩表不能視為同一強化機率，Server 仍須選定與實際入口相符的裁決表。能力值亦應沿 `ItemTable2` 的各項倍率表 ID 使用 `ItemStatLevelupRatioTable`，先核對累計、四捨五入和對應能力值。

| 解碼後資源 | SHA-256 |
|---|---|
| `ItemLevelupRequireTable.xml` | `717152d5fd1688f1227a4791a1442a5d36598741b987d81dc421b6ac1da6295b` |
| `ItemLevelupInfoSet.xml` | `ff2e4ac049a104875f97dd094a84d01417aa6ccb0fdc9ffa084d539d5fced384` |
| `ItemLevelupSetIDMapping.xml` | `190568c4b3cf00aeea95ad9ed8fdf387980b555cb5f43d897dc93d2584b05b2c` |
| `ItemStatLevelupRatioTable.xml` | `42e3748490e60ba763e802165c7ee4eb010cd4f68423ff06eede3a67ccdb731f` |
| `ItemCompound.xml` | `d4691667dabe8d107afc256c865b3f9c784d0bb7f7aa76ad8d2fe5f564a9c106` |

## Server 接續與驗收

本機進度頁可在正常前兩村各取 15 秒樣本。分開記錄開窗與確認，`00A1` 若符合已核對形狀，保留上述五欄，仍循一般輸入路徑。觀察工具沒有扣款、耗材、修改裝備或發成功回覆。Release 建置及 505 項 HappyPath 通過，其中合成 TCP 驗證正常進馮德斯後收到 10-byte `00A1` 五欄，接著仍正常回覆隊伍清單。指定 v2 側的實際發送待 EQ-B02。

可用的強化流程需要一筆 SQLite 交易同時核對租約、當前鐵匠、背包實例、目標級、石頭和 LeeLoo，保存結果後再同步物品。成功後穿上要反映能力值，經存倉、取回與重登仍保留同件實例。等材料取得與普通選單形狀有證據後，先串接無保護選項的普通強化，再驗證其他選項。 [EQ-B02 批次取證](../testing/S00-CONTENT-BATCH-TESTS.md)
