# 商城完全復活卷軸的付款與戰鬥串接

2026-11-18 S00 接續；分析基準 `578b0bc8d37fd071129671ca4072ba0ed2788da3`、私有 Server 基準 `f25b49514231be9db1ae442b092e6b76cfe3ed4e`。本輪新增來源核對與兩條跨模組正流程證據，沿用既有消耗／復活實作，未換版或啟動 Client。

## 來源與採用界線

[唯讀核對工具](../../governance/client-variants/20261118-cash-shop/verify_revival.py)先核 Table.stp、archive reader 及四個 member 的固定 SHA，再檢查 Product、Item、CashProduct 與 ItemUsable 的 184 列。[來源收據](../../governance/client-variants/20261118-cash-shop/revival-source-verification.json) SHA-256 為 `9665a9144f622b77cf0cd6165f48c6118340345834f57306c77b1d822e2d2037`。所有原件唯讀。

| 原始資料 | 已確認內容 |
|---|---|
| Product 184 → Item 184 | 完全復活卷軸；class 26、堆疊上限 100 |
| CashProduct | 10／50／100 張分別 16／72／128 Garnet，永久商品價格列 |
| Item 說明 | 角色死亡時使用、全 gauge 100%、死亡懲罰恢復、4 秒再使用限制；COOLTIME group 3 |
| ItemUsable | Action 1／priority 5：SkillCast 437／Lv.1；Action 2／priority 8：REBIRTH rate 100；Action 3／priority 3：VALUE -800；Action 23／priority 2 |

來源文字及 action 記錄不等於所有效果已復原。現行 Server 候選在倒地時，經已有背包 `0021` 或快捷 `0022` 使用，原子扣件／保存商品冷卻，將 HP／SP／MP 回復到目前裝備容量並恢復存活。SkillCast 437 的原視聽、Action 3／23 的完整語意、死亡懲罰與狩獵場評級恢復仍未驗證；不因本輪通過而宣稱完全復活卷軸全部功能完成。

群組 3 仍與 CP 書共用持久化鎖定，但本次復活的 ready_at 為 4 秒，CP 書為 1 秒，沿用[既有商品冷卻策略](CASH-SHOP-CONSUMABLES.md)。復活本身不改 Garnet／LeeLoo／Battle Point／CP，也不新增死亡懲罰退款。官方評級、疲勞或其他扣分契約待補。

## 本機正流程驗證

私有 `CashRevivalPositiveTests.cs` 的兩個 HappyPath case 分別經背包與已綁定快捷欄：

1. 在 SQLite 隔離帳號完成冒險團命名、取得伊希莉亞，配置測試錢包 1,000 Garnet。以現行商城價格購買 184 ×10 與時裝 29769 ×1，扣 104，餘 896；逐筆領取，商城保管箱清空。
2. 村莊裝備 adapter 正常穿上時裝，快捷欄綁 184，發布數量 10。將保存的裝備資料載入獨立狩獵場，確認 HP 500、SP／MP 220。
3. 使用合成可走地面與明示的致命區域；起始 SP 25／MP 85 是夾具狀態，死亡由實際 hazard 傷害路徑產生。這不是全新帳號自然戰鬥或 Client 操作證據。
4. 倒地後各用背包或快捷請求一次。確認滿資源、快捷計數 9、group 3／4 秒與存活狀態；沒有生怪、換圖、結果或場景重建封包。怪物身分／位置／血量及節點、圖、路線、擊倒經驗、拾取、完成狀態保持原值。
5. 重開資產 store，讀回卷軸 9、錢包、CP 3,000、已穿時裝、快捷綁定及剩餘冷卻。原 combat instance 離開致命區域後可繼續輪詢，沒有重新進場。

這是 session／SQLite／world adapter 的 `OFFLINE_SYNTHETIC` 串接，不是本輪新增 TCP 或指定 v2 驗收。既有 TCP 商城正常旅程另見 [商城 TCP 驗收](CASH-SHOP-TCP-ACCEPTANCE.md)。首次專項測試因夾具未取得伊希莉亞而在穿裝前失敗；補上既有教學角色取得後兩例通過，保留失敗及成功 TRX，不修改產品資格檢查。完整回歸收據見 [驗證索引](cash-revival-validation.json)。

Release Host／檢查器均建置成功、零警告與錯誤；576／576 HappyPath 通過，完整 TRX SHA-256 `73d22c096bdb41a722aa083b113e71bde42cef90e0b4573b599dce86b7203b1f`。本輪沒有部署；沒有藉此重跑非正流程待測項。

## GAME_RUNTIME_OBSERVATION：CS-06

目前沒有新增實機問題觀察或產品修正；補齊「可付款入包但下游只用掉落夾具驗過」的覆蓋缺口。實機與換版維持暫停，CS-06 待排程：正常商城購買 10 張並領取，穿上已確認資源容量的時裝，進一般單人狩獵場，分兩次倒地驗背包與快捷使用。記錄滿資源、同場怪物與進度、冷卻、背包與快捷計數、視聽及重新移動；另記錄畫面上任何死亡評級、疲勞或懲罰前後值，不把未出現的效果列通過。
