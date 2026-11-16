# S00：怪物索敵與回出生點

## 目的與來源

將關卡／MEF追蹤表中的索敵範圍、追擊邊界與回位做成可配置Server行為。
沿用既有MonsterBehavior JSON、逐出生aiProfile及既有生怪／位置／動作封包。
未新增原生程式分析結論；所有新增狀態和數值均為SERVER_RECONSTRUCTION，
NOT_NATIVE_MEF，不宣稱Client自主AI或官方平衡。

## 欄位與行為

|欄位|省略／null|指定數值後|
|---|---|---|
|aggroRange|保留原本主動交戰|玩家進入以怪物當前位置為圓心的範圍後進入交戰|
|leashRadius|不增加追擊邊界|以每隻怪物自己的出生點為圓心；玩家或怪物超出時回位|
|canPursue|true|false只禁止追擊；受拉引後仍可依leash回出生點|

新欄位皆可不填；正有限值，最多3600，兩者都有時aggroRange不得大於leashRadius。
省略欄位的既有正式profile不會改成新索敵規則。範例12／30只供作者示範，
不代表正式關卡數值。範圍內含圓周；每次AI Poll使用Server當前位置判斷。

待機怪物受正傷害也會進入交戰；已交戰後玩家走出aggroRange不會立刻清仇恨。
只有超出leash範圍才進入回位。回位會取消尚未命中的Server近戰與其動作等待，
暫不重新索敵或出招；玩家仍可對它造成傷害，不給無敵、不回血、保留攻擊冷卻。
回出生點後待機，下一次AI Poll才可重新索敵。超出leash的玩家不能讓它立即再追。

回位沿用Server速度、緩速、地面碰撞與每步最多0.25的軌跡檢查，直接送位置。
定身及暈眩會阻擋回位；它們消失後再繼續。到出生點就停止／待機，過程不送
地圖切換、重新生怪、任務完成、HP回復或Client目標抵達ACK。
直線回位遇障礙會停住並等待後續Poll重試，不瞬移、不穿牆；尚未實作繞路尋徑。

所有初始／順序增援／定時增援都各自保存自己的出生點，不能沿用玩家或第一怪位置。
回位怪物仍是活怪，必須正常擊敗才會滿足清組／出口條件。
同一時刻先更新交戰／回位狀態，再挑選本輪近戰攻擊者，避免回位者佔用出招名額。

## 診斷與交付

故事測試診斷增加monsterAgents：entity、model、當前x/y、homeX/homeY、health、
phase（DORMANT／ENGAGED／RETURNING／DEAD）。它是當次Server快照，不是Client回報。
資料schema與example-leash.monster-behavior.json放在design/scenario-content；
範例保留legacy與新增示範profile，尚未套用正式主線／未做Client人測。
攻擊選招、遠程、召喚、Boss階段與完整仇恨表仍列待開發。

323項受影響的正常旅程回歸通過；涵蓋範圍等待、追擊回位、HP與冷卻保留、
未命中近戰取消、受擊索敵、外部profile載入及定時怪物各自的出生點。
Host Release建置零警告／錯誤。公開範例經實際catalog載入與欄位檢查成功；
本批仍待換版與實機驗收，不以測試數量宣稱完整AI或MEF完成。
