# 商城回復之書與 CP 書使用

2026-11-18 接續 [商城 TCP 驗收](CASH-SHOP-TCP-ACCEPTANCE.md)，基準為分析庫 `4ebe80fbc5cdcdb180ac13a2db7d54d3906354f5` 與私有 Server `4b78aa0ae5e78775be3211efcec8d3d88b1ffea1`。付款、保管箱與一般背包流程沿用；本輪補原本只能領取、尚不能使用的三種商品。

## 固定來源及效果範圍

來源仍為 KR Table.stp SHA `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。新增 [唯讀核對工具](../../governance/client-variants/20261118-cash-shop/verify_consumables.py) 與 [收據](../../governance/client-variants/20261118-cash-shop/consumable-verification.json)，先核 archive、parser 與每個 member SHA。`ItemUsableTable.xml` 按原 cp949 解碼，未改原件。

| 資料 | SHA-256 |
|---|---|
| Product.xml | `8c9262f81ca4dae6b62be5d3373bd06d6e96e7470b4227fc73c98fda4e88457c` |
| ItemTable2.xml | `7095f005d26a67694112ce4c89d2725478d2287181e639fb18956b3d0bf5e2e2` |
| ItemUsableTable.xml | `30970e8d4cffe80d6ad18552fb93601e4b0a5a8e6cfa2030064fd44192ef038c` |
| StatusList.xml | `9be878f847ab75401bf8bd81d943773d3e98ec05bbc36364f4cf8f6c00a70161` |

| Product → Item | 原表與本輪 Server 行為 | 冷卻 |
|---|---|---|
| 5238 → 5206 | class 5、quan 255；EXPLAIN 為 HP／SP／MP 100%。存活且任一資源未滿時，扣一件並各自回到目前上限 | group 1，4 秒，沿用同群回復物品 |
| 27461 → 7639 | class 21、quan 100；ItemUsable 唯一 Action 11／priority 5／VALUE 2000。普通廣場／村莊背包使用後增加 2,000 CP | 原 COOLTIME group 3，說明 1 秒 |
| 27462 → 7640 | class 21、quan 100；同 Action／priority，VALUE 4000。增加 4,000 CP | 原 group 3，說明 1 秒 |

5238 沿已有 class 5 的 `0021` 背包與 `0022` 快捷使用接口、角色資源發布，沒有宣稱本輪復原了新的 SkillCast 或視聽演出。兩本 CP 書沿已有 CP 消耗交易與 `00ED` 絕對餘額，沒有只改面板或由 Client 裁定入帳。既有小額 CP 商品仍使用自己的 group 6／1 秒。

群組 3 也被完全復活卷軸使用，其說明為 4 秒。本輪按商品決定本次 ready_at：CP 書 1 秒、復活卷軸沿用 4 秒，仍共用同一群組的持久化鎖定。登入恢復以保存的剩餘時間為準，不把 group 3 全域改為 1 秒。這是原欄位與文字約束下的相容服時間策略；官方所有組合的業務規則未宣稱完整復原。

## 多格道具與保存

V27 保留全部資產，在 recovery quickbar 既有 product CHECK 追加 5238。`00B7` shape、原 Client、schema 全域版本與正式協定 pin 不變。

商城的 400 本可分為 255／145。快捷綁定及登入恢復合計同 Product 的非獨立格，使用時從最低格扣一件；直接背包使用仍按請求的實際格。消耗回覆保存該格剩量與全背包總量，快捷欄顯示總量。銀行增減後也由完整資產重算。銷毀其中一格時，只減少該格數量，不把仍有庫存的快捷欄計數清零。

CP 使用在同一 SQLite 交易刷新當日餘額、檢查有效租約／格位／Product、檢查該群冷卻、扣一件、增加 CP 與保存 ready_at。仍保留已知 Client 有號比較的 32,767 表示界線；本輪不啟動邊界或重送測試。

## 正常流程證據

已購回復之書的專項 HappyPath 以兩筆 200 本實際付款／領取起始，Garnet 1,000→888。快捷欄顯示 400；一般副本 session 在 HP／SP／MP 125／25／85 時使用，實際資源變為 500／100／100，格位數量為 254／145、快捷總數 399。重開儲存層仍恢復綁定與群組 1 冷卻，銷毀 145 本那格後，快捷計數正確剩 254，Garnet 不變。

兩個 CP 書專項各從原價購買／領取兩件開始，第一次使用後重開讀回餘額、剩一件與 group 3／1,000ms。前進測試時鐘一秒後再次正常使用，最終 CP 為 7,000／11,000。這裡只驗正常到期後使用，沒有啟動暫緩的冷卻拒絕／重送案例。

既有新帳號 TCP 商城路線追加已付 27461 的背包 `0021`：收到 `002C → 00ED → 00B7`，餘額 3,000→5,000；最終正常重登後 CP 5,000 保存、書已消耗、主線快照不變。舊 TCP 文件的未使用書籍版本及舊收據保留；最新差異以本頁為準。

以上為 OFFLINE_SYNTHETIC／候選 TCP 證據，指定 v2 的正常使用、提示、快捷圖示與效果仍待 CS-02；本輪未操作 Client 或換版。

最終 Release Host 與檢查器建置均為 0 warning／0 error，完整 `Category=HappyPath` **569/569** 通過。[工程收據](cash-consumables-validation.json)保留 TRX SHA 與實際計數。原表核對工具亦以指定 STP 成功重現，原件及原始 member 沒有加入 Git。

## 時裝加成的接續界線

同時核對原 StatusList：12 為 SP 增加、13 為 MP 增加；已買時裝 29769／Item 13401 的兩個 OPTION 都為 120。不能把這兩個值加到物攻／魔攻。現有六項攻防加總器尚未處理這類容量屬性，下一段需連同最大資源、角色面板、戰鬥建立／換圖延續、回復與卸裝後封頂一起設計及驗證；套裝與其他狀態也分開保留。這份來源核對不標為時裝加成已實作，也不以資源名稱推定所有比例或官方結算公式。
