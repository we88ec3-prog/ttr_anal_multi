# S00：同圖順序波次與延遲增援

類別：SERVER_DESIGN_CHOICE／Server內容功能。自訂JSON，NOT_NATIVE_MEF。
未新增原生MEF格式、傳檔opcode、Client修改或官方生怪規則主張。

## 內容契約

沿用`LOCAL_SCENARIO_DEFINITION_V1_NOT_NATIVE_MEF`的有限地圖鏈。
每個node可選填`reinforcements`，未填為空，既有單波內容無須修改。
初始`encounters`仍是第一波。後續波次依陣列順序，例：

```json
{
  "reinforcements": [
    {
      "id": "second-wave",
      "delaySeconds": 2,
      "encounters": [{"model": 1009, "x": 506, "y": 500}]
    }
  ]
}
```

此例是合成測試座標與選擇，不代表任何正式地圖配置。實際內容需逐圖核對地形、
出生安全距離及任務規劃。波次可以逐出生選擇已有的`aiProfile`；未填繼承node設定。
`id`為同一node內唯一、非空的內容識別，不能當Client actor ID或模型ID。

上限：額外31波、每波1–255隻、初始加所有波次合計不超過255隻。
delaySeconds為有限數值0–3600，從Server確認上一波存活怪數為零時起算。
0表示同次Poll末尾生成下一波；本次已結算的命中不會追溯套用到剛生成的怪。
時間採每實例單調時鐘，沒有背景腳本或任意程式執行。

公開[完整schema](../../design/scenario-content/local-scenario-definition.schema.json)
另由typed loader檢查唯一ID、累計物件容量與跨節點引用等語意。
一般故事node也接受相同`reinforcements`欄位，編譯進共用關卡圖；
載入時核對所有波次地形及AI profile，而非只檢查第一波。

## 執行與結算

所有波次屬於node既有EncounterGroup。只有最後一波清除及既有勝利等待完成後，
adapter才可以送出聚合GroupCleared、保存該地圖勝利、開始戰後劇情或開啟出口。
等待增援期間不把地圖視為已通關，也不自動換圖。

同一combat物件延續玩家HP／MP／SP、冷卻、連段與既有資源回復規則。
換波不重建地圖、不重建玩家、不補滿資源、不另發獎勵。
怪物物件ID在同一地圖內單調分配；已死亡物件維持原死亡動畫及移除期限，
不重用其ID。新增一波的AI起始等待以該波生成時刻計算。

波次游標、增援計時及戰鬥狀態不寫入主線存檔。主線完成里程碑沿用既有交易；
重建副本combat從第一波開始。這不代表本輪執行了延期的重登／故障測試。
進度診斷列出當前零起算wave index與總波數，不能當Client已看見生成的ACK。

## 驗證及未完成界線

工程驗證涵蓋三波順序、延遲期間不生怪／不結算、不同actor ID、資源保留、
最後一波才開出口、一般故事內容編譯及唯讀集合、原單波旅程相容性。
313項受影響HappyPath回歸通過，另增的一般故事波次編譯測試單獨通過；
Host Release建置0警告／0錯誤。不能把合成通過當作實機驗收。

執行器已隨v90啟用；現行正式故事／scenario內容未新增波次，避免擅改逐圖生怪。
公開schema與Server使用的schema逐byte相同，SHA256為
`809a76c234b47d1a742fa0b88c7be1c5ca6c4192871abea40e1225772531963b`。
JSON解析與內部$ref完整性已檢查；typed loader及戰鬥流程由上述合成測試驗證。

本版是清波後順序增援。並行定時增援、進區／血量條件、分支、計數器、
任務道具條件、Boss階段、任意腳本及Client自主清組仍未實作／證實。
怪物決策、位置與傷害仍由既有Server戰鬥層控制，波次JSON沒有把它們交給Client。
