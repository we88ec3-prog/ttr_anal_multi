# 完整階段副本的裝備掉落與回村穿戴

2026-11-24。SERVER_DESIGN_CHOICE／**NOT_NATIVE_MEF**。
沿用[階段頭目與卷軸完整副本](PHASE-BOSS-LOOT-COMPLETE-DUNGEON.md)，新增獨立版本，保留原版。
不是重新實作已存在的掉落、裝備識別碼、穿戴或頭目階段引擎。

## 配套與來源

[新增關卡](phindos-stage462-case693-phase-equipment.scenario.json) SHA256
`15dcfca3ac3e2c7e0c0102dbcdb9ab17e9758ff126f8a2ab760fefd6e4533ee2`。
配對[階段 AI](integrated-attack-flags.monster-behavior.json)保持
`d4768b72eebab11ec675a5e5f4fc4116cb41d566f7b41caad5ab04c4f6b0a3e4`。
相對舊版只將 node2 的單筆卷軸掉落改為三筆：保留卷軸，新增兩件裝備；其餘 JSON 語意完全相同。
新裝備限定 `boss-arrival` 的 1086／PRE1，每場各一件、數量1。

|Product|Item|穿戴角色／部位|最低等級|來源對照|
|---|---|---|---|---|
|2725|2718|role4／slot1 武器|10|Shop6；既有三村商品與穿戴規則|
|10044|9907|role4／slot2 防具|0|Shop2；既有三村商品與穿戴規則|

[三村商品來源](three-village.town-trade.json) SHA256
`1bbc4efa629f258bec3b1f7f5cd8ad6fd81d68a95a051f891fe618dfe70ea5bc`，
保留 ShopInfo、Product、ItemTable2 的原始 SHA。Product／Item／職業部位取自既有來源對照，
不是本輪新增原生分析。指定怪物掉這兩件、必掉、數值平衡及外觀7都是 Server 候選內容；
**外觀7沿用舊裝備 fixture，尚無指定 v2 地面呈現驗收，不宣稱正式原生裝備掉落模型**。
本文件的「裝備掉落」指有來源映射、實例及可穿戴的道具，不表示官方掉落表已復原。

不提供虛構固定 metadata。以已存在的 `SERVER_GENERATED` 服務，由每次掉落 GUID 產生背包鍵；
物品以 quantity1 與同一 equipment_id 由拾取、背包移至穿戴位置。識別碼屬 Server 自有決策。
[既有穿戴封包](EQUIPMENT-WEAR-WIRE.md)、[拾取流程](GROUND-LOOT.md)保持。

## 正常流程與部署

正常廣場建一人隊→Town1→Stage462／Case693→node `10,1,3,5或6,4,2`→結果→Map182 原隊伍。
初始1004／第二圖1022的卷軸、支付1件的入口機關、分支開關、延後頭目、75%護衛與招式切換保持。
每場88EXP；卷軸共8件、入口支付1件，回村183×7，另獲武器與防具各1件。
回村後以正常 `0023` 穿戴，並核對 `0070`、`002C` 與 SQLite 同一實例，不以 SQL 寫入代替操作。
穿戴格與背包鍵從正常結果返回的 `0029` 背包初始化取得。

管理工作台保存並匯出原有三檔 ZIP，scenario／AI／manifest 雜湊綁定同一版。
普通狩獵場配套部署另須明確啟用既有裝備鍵與穿戴服務；不可只換 JSON。
Server 啟動設定為 `TARTAROS_LOCAL_TOWN_TRADE_PLAIN_EQUIPMENT_KEYS=SERVER_GENERATED` 與
`TARTAROS_LOCAL_EQUIPMENT_MODE=LOCAL_PHINDOS_EQUIPMENT_CANDIDATE`，並保留已釘選的三村商品表。
接受腳本新增 `-IncludeGeneratedEquipmentDrops`，只供明確的普通狩獵場配套；
它不選用舊的 equipment scenario、不改變本次保存版、不產生 Client 檔案。

## 驗證狀態

管理端正常 HTTP 保存／三檔匯出後，scenario 與 AI bytes 均與來源相同，隔離管理端已停止。
來源版兩 TCP 分別走 node5／6；每路七筆拾取（卷軸五筆共8件及裝備兩筆），
88EXP 一次結算、活頭目兩階段、投射物建立／退休守恆及原村原隊伍返回通過。

同一保存版另起兩場獨立實際時計 Host，正常廣場建隊、進村、六圖戰鬥、Space拾取、
機關付款、結果與回村後穿戴通過。兩場頭目同一 entity513，第一階段120HP、第二階段80HP；
階段身份來自唯讀診斷的 AttackId／旗標，加上同時的實際000D動作101，未宣稱回包含新階段 opcode。
每場回村穿戴前為183×7／2725×1／10044×1；穿戴後背包183×7，role4的slot1／2保存同一領取 GUID／鍵。
離線稽核確認 Host PID 不存在，再將已停止 fixture 的 DB／日誌複製到新目錄讀回：
拾取共183×8／2725×1／10044×1，兩件裝備各一筆、不同實例，最終累積39088EXP。
只在讀回副本允許 SQLite 日誌恢復，原 fixture 各檔 SHA 保持；不是故障或備份恢復套件。

三 Release 零警告／錯誤、810 HappyPath 零失敗／略過，五 Python 語法與啟動腳本語法通過。
收據：[phase-equipment-20261124.receipt.json](../testing/phase-equipment-20261124.receipt.json)，SHA256
`498a6aa7b7014b8f0eef2a668c3d96e94e2031776619eb0aa2113aaaf03e9f67`。
保存版 manifest SHA `308986e9ae6ea4d541e40a44cf8e0147e5b0d50ff483dfabd86836d6fdfd26c9`，
ZIP SHA `66304cc707602bfc983d667c7db9e5a597e0098eca9fc7dc731e5f93fea5a806`。

首批 TCP 呼叫使用大寫 AI SHA，原路線已通關但包外稽核字串比較失敗；修正呼叫端為小寫後另存兩路。
首個 Host 缺少裝備服務開關，啟動時正確拒絕 Product2725；補啟動選項後另存兩場。
失敗紀錄保留，未放寬來源／metadata 驗證；最終收據只採新通過場次。

工程帳號已準備教學／Q15／role4 Lv15，不算自然新帳號升級驗收。
TCP 測試時計與實際時計 Host 分開；指定 v2、地面外觀、人工穿戴畫面仍待驗。
既有非正流程套件保持待排程，未執行遊戲或修改 Client／原件，未換現用服務。
整體 MEF 功能與原生格式並未因此宣告完成。
