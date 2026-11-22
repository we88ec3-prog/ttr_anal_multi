# RAID 1～3 正常 TCP 通關與配套核對

2026-11-22；SERVER_DESIGN_CHOICE / OFFLINE_SYNTHETIC / NOT_NATIVE_MEF。
分析基準8f28f2c29f9164486ec73a958ca41f6330708e4c，私有Server基準5be6fd5697421a7ecfbda0fb56b880cf81758ced。
沿用[單場正流程](RAID-NORMAL-ROUTE-INSPECTION.md)及[固定RAID工作台](../scenario-content/RAID-SCENARIO-WORKBENCH.md)。
原始資料、三個固定來源與三份歷史管理端匯出稿均未修改。

這次補上此前缺少的真正socket：正常login／primary handoff、角色／廣場、穿戴／綁卷軸、建隊、選RAID、
開始、五圖原BND走位／攻擊／正常HP卷軸／出口、成功結果、確認及回廣場，全經loopback TCP。
世界更新由正式gateway排程呼叫，檢查器只前進測試時計及收送封包；TCP模式禁止呼叫直接game handler，
分支也不直接PollWorld。可讀觀察連線僅供診斷，不操作其遊戲世界。
心跳查詢是實際Server回覆的有序排空標記，不當成Client ACK。

使用與舊單場相同的prepared role4/Lv17、教學／Q15里程碑、普通武器2725／護甲11262及20張HP卷軸232。
物品是明示的隔離準備條件；穿戴、快捷綁定及使用經正常TCP handler。
低於60%且四秒冷卻結束才發一次正常卷軸輸入，核對回復最大HP的30%、扣件與冷卻；
沒有降低怪物強度、跳過戰鬥或新增Server自動補血。

六場全部通過，每場五圖，共30次原BND載入：

|路線|擊倒怪物|HP卷軸|經驗書|CP前／後|
|---|---:|---:|---:|---:|
|RAID1固定基準|16|3|2274×1|3000／3000|
|RAID2固定基準|20|3|2275×1|3000／3000|
|RAID3固定基準|18|4|2276×1|3000／3000|
|RAID1管理端r1配套|16|3|2274×1|3000／3000|
|RAID2管理端r1配套|20|3|2275×1|3000／3000|
|RAID3管理端r1配套|18|3|2276×1|3000／3000|

每場一個成功結果、一筆已交付獎勵，經驗書在廣場0024啟用前發布；普通角色EXP、故事狀態、
穿戴實例、其他背包與資金保持。正常成功返回執行原隊伍清理；不是主動離隊或敗退測試。
三條舊應用層基準控制也通過，新增TCP不是取代或改寫歷史應用層收據。

## 共用成對讀取契約

新增共用 `LocalScenarioBundleReader`，以固定工作台驗證同一schema的版本配套。
既有 `LocalStructuredLoopBundleReader` 保留原先必須為admitted loop profile的入口限制，呼叫共用邏輯；
沒有讓普通／RAID來源繞過各自authoring驗證，也未更動原ZIP／manifest格式。

讀取器核對manifest SHA、schema／authority／非原生聲明、固定profile identity、draft／revision、
精確版本檔名與成對scenario／AI SHA，再經該工作台原BND、來源圖與AI規則驗證。
settings必須與工作台預期鍵值完全相同，只把指定解壓目錄placeholder解析為實際資料檔路徑，不執行腳本或任意設定。
已有loop／經驗metadata時仍重算比對，原loop包仍要求完整metadata。

RAID預覽的minimum／maximum／completion EXP保持null，因書與CP由challenge領域發放；
不把一般關卡EXP的0或null誤作RAID獎勵。獨立重算的最大訪問為5，但不新增RAID loop能力。
三份歷史r1匯出稿在走TCP之前先用固定RAID基準／BND通過共用讀取器，證據保留profile／版本／兩個payload SHA。
領域正流程測試也驗三個RAID配套的匯出再讀取、專用slot及nullable reward；既有循環配套測試保留。

## 重現與驗收界線

```powershell
python -B tools/check-normal-raid-routes.py `
  --analysis-directory E:/Tartaros/workspace/s00-runtime-dev `
  --raid-bounds E:/Tartaros/workspace/outputs/early-raid-bounds `
  --story-bounds E:/Tartaros/workspace/outputs/fresh-early-raid-story-bounds `
  --output <新的輸出目錄> --tcp `
  --paired-bundle-directory <RAID1已解壓配套> `
  --paired-bundle-directory <RAID2已解壓配套> `
  --paired-bundle-directory <RAID3已解壓配套>
```

不加--tcp仍是舊應用層模式。新增CLI `--raid-normal-route-tcp` 沿用原參數序；
`--inspect-raid-bundle <raid> <固定基準> <BND目錄> <manifest絕對路徑> <manifestSHA>`
僅做成對來源／BND設定預檢，不能單獨當作通關。

[本批收據](raid-normal-tcp-validation.json)區分六場TCP與三場應用層控制，保留原stdout與配套manifest的SHA、
requests／frames／gateway polls、世界步進、資產及發書核對。回傳前依finally處置gateway及socket並刪除隔離DB，
各檢查器程序已正常結束。遊戲Host、管理端、使用者資料及Client未變更。

這是同程序內的真socket與測試時計，尚非獨立Host／真實時間驗收。指定v2、自然新帳號養成、
RAID loop adapter、巢狀／任意新Case及原生MEF／AI移轉仍OPEN。停權、重送、重登續關、敗退、故障、安全與壓測未執行。

最終三個Release零警告／錯誤，726/726 HappyPath、零略過；包含三個RAID讀取器正流程與既有循環相容性。
收據SHA256 `52ed3ec9c13e02d956f58c1764db18fd1ef967ac34d0dfe3b571d4a868354830`；TRX SHA256 `6790e83c1d280c47b96ad7d9e3dbb5616c32aaea413ddb7978f485d1695f775b`。
