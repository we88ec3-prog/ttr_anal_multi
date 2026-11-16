# v10：直接讀取台版文字的翻譯候選

2026-11-08。從已使用的 v7 建立新 EXE，保留 v7/v8/v9 及所有原始資源。v8 存取違例、v9 啟動通過但介面仍韓文的歷史不變。v10 不沿用其 FCS 預載入程式；PE headers、所有 executable code section 與 v7 相同，僅替換已確認的文字路徑及九位角色的固定顯示名稱。

## 來源與範圍

沿用台版 Table.stp（SHA 見 metadata.json），按 key／ID 對齊韓版表格，只改顯示欄位。UIText 706、CommonMessages 446、SystemMessages 107、ScenarioBookContents 摘要 425、AreaDescription 名稱／說明 182、TownList 名稱 17 處。TownList 的台版原表本身仍為韓文，因此改從同村莊 ID 的台版 AreaDescription.NAME 取得中文，不以排列順序猜對應。

新增六個 TC_UI/*10.xml 配套，清單、SHA、欄位統計見 metadata.json。沿用 QuestTxt8.xml、v7 技能文字、v6 NPC 名稱及 v4 補韓文字型。這不是全介面中文完成：缺少對應、格式不一致、台版仍韓文的列保留原文，須依實際畫面繼續核對。

## 驗證及使用

獨立 XML tree 比對確認未改其他欄位、節點、排序或尾文；EXE headers／code、檔案 SHA、既有 fcs.flu、pack.gms 及舊版本保留檢查通過。新增文字字形覆蓋無缺字。未執行或附加遊戲，不能將靜態檢查算啟動、貼圖或翻譯人測通過。

直接從原目錄開啟 E:\Tartaros\workspace\Tartaros.ip-zh-tw-v10.exe。測試卡已送出：查看任務按鈕／摘要、世界地圖村名及房間介面，停在確認建隊之前。Runtime=PENDING_USER；Server 仍 v42，正常建隊進村修正尚未部署。此版不改技能、解鎖、等級、任務條件或 3D 資源。

Git 只保存工具、SHA 及分析，不上傳 EXE、XML、STP 或 dump。工具依賴本機既有 CLIENT/tools 與 anal helper；本資料夾不是獨立可執行的發行包。
