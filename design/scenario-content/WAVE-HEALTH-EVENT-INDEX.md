# MEF 波次血量：由角色變更更新彙總

2026-11-22。SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。
依 [目前開發方向](../../kr-extra-roy/MEF-CURRENT-DIRECTION.md)及
[OPT-02](../../kr-extra-roy/MEF-level-functional-closure-20261118/rules-waves/optimization-contracts.json)
接續既有 Server MEF 執行器。官方容器復原已退出本次共同目標，不重啟舊格式搜尋。
目前已有事件／波次／互動點索引；本批只處理仍存在的波次成員血量重掃。

## 語意與實作邊界

舊 `ReportWaveHealth` 每次有效戰鬥 poll 掃描所有尚未清零的已生成波成員，
加總現有HP與最大HP，總HP改變時呼叫既有 observer。沒有變化的波也會重掃。
新實例級索引在生成時登記 actor→wave，在唯一已接受的敵方扣血位置更新該波總HP，
只將變更波加入dirty集合。初始群／計時／順序增援皆使用同一登記路徑。

- 在原 `ReportWaveHealth` phase 才派送，沒有在傷害callback立即開門或生怪。
- dirty波依原生成順序派送，不按命中順序重排。先前已派送且未變化不重送。
- 死亡角色仍保留最大HP分母；屍體延遲退休不縮小波次最大值。
- 波次清零只派送一次；空初始群不創造一個假波。
- 計時增援仍在血量回報之後、順序增援之前處理；新波首次回報保留至後續有效poll。
- 待生成必要波、聚合清場、投射物、勝利等待與屍體移除門檻保持原執行器負責。
- 未使用波血量observer的戰鬥不配置這個索引；每個combat／重訪各自建立，不共享可變血量。
- 不新增敵人治療／復活、任意HP寫入或Client自主AI。未來新增HP變更路徑必須同步更新索引並另驗。

## 工作量觀測

原本會掃過的活躍波成員數，以每次相同回報phase的成員數累計成 `referenceMemberVisits`；
新路徑記錄 `registeredMembers`、`acceptedHealthUpdates` 與 `dirtyWaveReports`。
這是有限正常內容的操作數核對，不是壓測、CPU節省比例或Client卸載量測。
診斷放在既有本機StageOne／Story觀察資料，不新增遊戲opcode或改玩法設定格式。

正流程需同時證明：獨立全掃參考的回報值／順序、死亡分母、計時／順序的原派送phase、
未生成波仍擋結束、原正常建隊副本的兩分支／75%頭目／機關／結算回村。
工程收據及指定v2人工仍分開；原件與現用服務不變。

## 已完成核對

新增三個正流程測試：獨立全掃參考模型的回報值／順序（98成員訪問、5次登記、6次HP變更）、
實際戰鬥的順序／計時波回報phase與待生成波阻擋通關、兩活怪20次正常等待poll。
等待案例的舊掃描基準40次，新索引只登記2個成員、0次HP變更、1次dirty波回報。
這是測試時鐘下的有限正常等待，不是壓測或CPU基準測試。

同一最終Inspector搭配舊Network `7c09d445522710f568442a54b98ca6be66ad0a1eb76f1d86c29cebd5aebc6ac4`
及新Network `605c2a412cea96c5db8b5c2b50ade9e3a87b62e0321cf6a4f96af3427eeff487`，
各跑完整Case693投射物候選兩分支。舊部署檔唯讀，只在新的隔離Inspector副本替換Network。
原BND、關卡29f4e12f、AI eaf55a17、NPC／建隊／入場／操作及測試時鐘皆相同。
兩分支各維持一次88EXP、存檔及同隊回村，頭目存活時75%旗標、增援、機關、投射物退休保持。

### 完整應用層回包的身分正規化

先前每房收據的 `Packets` 合計只保留20筆，不能證明整場完整封包一致。
本批補充primary交接之後的完整S2C應用層回包序列，以長度前綴及payload順序計SHA，
排除登入憑證／交接及0019排序排空回覆。只有指定隔離檢查模式保留本機原始回包，未把它們推Git。

原始SHA確實不同。定位後，每路只有57筆的登入 `wireAlias` 欄位不同：
它由既有 `LocalLobbyHandoffBroker` 隨機產生，不是血量／波次差異。
只依現有writer的明確欄位，把本隔離帳號的alias改為同一比較值；其他byte不改。

| writer形狀 | alias欄位 |
|---|---|
| 0008／26 bytes metadata | offset4 UINT32 |
| 0007／28 bytes owner actor、entity0100 | offset20 UINT32 |
| 000A／11 bytes bind | offset2 UINT32 |
| 00F9／00FA／14 bytes equipment | offset2 UINT32 |
| 001C／48 bytes known name | offset44 UINT32 |
| 008F member rows | offset8起，每9bytes的UserId |
| 008D directory rows | offset52起，每54bytes的OwnerId |

alias必須在metadata及自己的隊員列一致，僅替換值相等的這個帳號欄位。
未遮蔽時間、傷害、位置、模型、動作、物品、冷卻、旗標、結果或任意不明欄位。
正規化後，兩分支完整primary **3485／4094筆**與副本安裝至結果的 **3323／3932筆**
回包逐byte及順序一致。收據保留 `fullPrimaryReplyByteEqual=false`，沒有宣稱原始隨機身分byte相同。
早期部分封包／原始SHA不等的檢查紀錄保留，最終接受依上述完整、明示正規化的序列。

### 工作量與獨立Host

每路最終頭目node2的相同回報phase，舊重掃基準295成員訪問；
新路徑登記4成員、處理15次已接受HP變更、派送15個dirty波。
不使用波血量observer的其他房間沒有建立索引。
這不包含全戰鬥其他 `Health` 查詢，也不代表總CPU減少比例、timer優化或Client卸載。

同一新Network另於獨立完整Host，以基準整合候選424b8d5a、正常建隊／原BND／機關／通關，
唯讀DB核對88EXP及原隊伍回村。此控制使用真實排程；投射物變體的完整回包等價證據仍屬TCP，
不能混稱為相同變體已完成Host畫面驗收。Host完成後停止，來源DB SHA未變。

三個Release（Host／Inspector／Admin）建置零警告／錯誤，748/748 HappyPath、零略過。
TRX SHA256 `0767f10013f9a9fabcc65ed0e94bd995529a5a0a6705ffed82123505e07e84fe`。
[完整交叉核對收據](wave-health-event-index-validation.json) SHA256
`a814b72a7b543a3f1c1a704891efc98fb45157e5d712fb9295be2165a9bd9be0`。

本批只閉合既有accepted敵方HP變更的波次觀察優化。全戰鬥血量查詢、反向flag-consumer索引、
deadline queue、其他HP變更策略及剩餘玩家可見接口仍按既有計畫接續；
Client人工、自然新帳號及延後測試項不因這份工程收據提高狀態。
