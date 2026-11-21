# 關卡旗標控制怪物招式

2026-11-22，自有MEF／Server-owned AI V1，NOT_NATIVE_MEF。
既有攻擊可選 `requiredFlags`（最多16個唯一旗標）與 `disabledByFlag`（一個旗標）。
省略兩欄維持既有選招；requiredFlags全部成立且disabledByFlag未成立，才可選招。
仍須同時通過原有HP區間、距離、個別冷卻、群體節奏與投射物容量條件。
互相矛盾的啟用／禁用同名旗標不接受；欄位名稱使用既有旗標命名規則。

接近距離也依可用招式計算，避免尚未啟用的遠程招式讓怪物停在遠處不攻擊。
沒有可用招式時，仍可依既有索敵、追擊及跟隨距離行動，不製造替代攻擊。
旗標在每次選招時讀目前instance狀態；不是重建／替換profile，不變更怪物
entity ID、HP、位置、仇恨、移速、冷卻或選招游標。已起手招式的傷害、時間
及投射物在起手時固定，之後設旗標不取消其起手、延遲命中或飛行；原有死亡／離場清理照舊。

每個實際引用的AI（node預設、逐怪、順序與定時增援）均須由載入器核對旗標
在該節點清場前可達，使用既有圖路徑交集／訊號依賴分析；不能引用另一分支
才有的旗標，或根本沒有producer的名稱。未使用的配套profile可保留，但實際
綁定時必須通過條件核對。普通副本、主線、RAID及工作台使用相同檢查。

怪物AI配套JSON可編輯兩欄，沿用同版關卡／AI保存與SHA發布；不自動改動
Client、現行Host或原資源。這是選招判定接入關卡規則，不聲稱Client自行執行AI。
原生效果仍用已有adapter，沒有新opcode或未證動作常數。

## 整合候選

Case693獨立配套 `phindos-stage462-case693-attack-flags.scenario.json` 對應
`integrated-attack-flags.monster-behavior.json`；保留原檔與先前候選。
只將最後一圖boss-arrival的1086改用新增的integrated-phase-boss-v1。
120HP不變，沿用動作101與已證Type43投射物adapter：
phase-one-shot在boss-phase-two前可選，旗標成立後phase-two-shot可選。
75%實際血量旗標仍同時召喚原有兩名增援；不直接設血量或換怪物。

啟動腳本 `IncludeAttackFlagPhases` 選擇整組SHA配套，與獨立權重／任務機關
候選互斥；不自動替換目前服務。原BND、正常建隊入口、原消耗機關、兩分支
與單場88EXP仍走既有領域服務。配套AI的旗標綁定也經主線／一般／RAID工作台
載入器同一規則檢查；未引用的新profile不影響其他節點。

指定v2的頭目起手／特效及自然新帳號完整流程仍待實機；未執行任何Client。

## 正流程驗證

Release Host／Inspector／Admin.Web皆零警告錯誤；HappyPath658/658。
三個新增正面案例核對實際波血量觸發、未取消既有起手傷害、同怪血量保留、
可用近程招式的接近距離、既有跨節點旗標保證及條件清單不可修改。

兩條正式gateway元件loopback TCP路線皆看到原120HP頭目三次phase-one-shot、
五次phase-two-shot，前後同一entity、血量單調下降；前階段無phase旗標且HP>90，
後階段旗標成立且HP<=90，未重建怪物。每路13枚投射物建立／清除、無跨圖殘留；
原機關、三次頭目區增援、兩分支、88EXP保存與原村莊隊伍返回均通過。
無新欄位的舊投射物配套兩路仍各5枚投射物、88EXP，原檔SHA保持。
獨立Host預檢核對實際配套SHA；完成後已關閉本次預檢Host，未更換既有服務。

詳見 [機器收據](monster-attack-flags-validation.json)。準備角色4／Lv15、受控時計、
同程序正式gateway socket證據不提升Client、自然新帳號或獨立部署Host遊玩狀態。
未量測CPU移轉，也未執行暫緩的非正流程矩陣。
