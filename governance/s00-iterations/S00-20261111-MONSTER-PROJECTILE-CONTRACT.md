# S00：怪物投射物後端契約

SERVER_DESIGN_CHOICE／SERVER_RECONSTRUCTION_NOT_NATIVE_MEF。這是關卡內容／AI執行器擴充，
不是原生MEF復原，不提供新飛彈opcode，也不宣稱ActorAction會自動產生正確的飛行特效。
原有attacks未設定projectile時保持NormalMelee；正式故事與現行行為JSON不改。

## 資料

attacks[].projectile可選null或物件，明示speed、maximumDistance、hitRadius、maximumLifetimeSeconds。
speed單位為Server座標單位／秒，距離與半徑也是Server座標、lifetime為秒，非原版速度單位。
數值需有限且大於0；speed／maximumDistance最多512、hitRadius最多64、lifetime最多60秒。
原attackRange必須不大於maximumDistance；既有attackRange≤hitRange及前搖／恢復／冷卻規則保留。
projectile使用自己的掃掠半徑，hitRange不作飛彈命中距離。新物件不接受未知欄位。
沒有追蹤、曲線、範圍爆炸、連鎖、穿透、魔法傷害或原版投射物型別的隱含承諾。

## 執行

出招時固定面向，前搖到期的實際Server觀察tick才建立彈體；不回填更早發射時間，也不假設未觀察路徑。
彈體以固定方向直線前進，按單調時鐘積分。每次至多行進剩餘射程／壽命允許的距離；
射程端點的接觸時間按實際飛行距離計算，不誤用整個tick。玩家兩次Server位姿間用線性插值，
以相對移動掃掠圓檢查命中，因此不只看最後一個座標；此插值是Server重建政策，非Client命中回報。
每顆最多命中一次。地圖遮擋重用quarter-unit ground/BND trace，再核對接觸點至玩家的遮擋；
這是保守可走性近似，沒有原生投射物高度／碰撞層證明。

最多256個飛行＋待發射保留名額；選招時計入既有飛行與前搖，不用超額後默默丟掉攻擊。
命中走共用傷害／受擊／HP顯示，分類NormalProjectile，適用普通攻擊盾；不再以遠距離近戰冒充。
前搖中的攻擊可被既有死亡／暈眩／回位規則取消；已發射者獨立於施法者，死亡或回位不消除。
最後一隻死亡仍等待已發射彈體處理完才允許清場出口；Server移除施法者實體訊息亦延後至其彈體消失，
不保證Client會保留死亡模型。副本換圖的新combat不繼承彈體。玩家死亡的清理程式保留，驗證排至Deferred。

只有配置投射物的combat持續推進Server玩家位姿；既有未配置近戰流程不改。
診斷可讀飛行ID／source／XY／剩餘射程；flight ID只屬Server實例，從不冒充Client network EntityID。

## 發布與待辦

公開example-projectiles.monster-behavior.json可由typed loader讀取，但不是正式怪物內容。
動作101僅為既有出招候選，不主張該模型擁有箭／火球動畫。飛行特效、實際物種與動作對應仍需來源分析。
目前只有後端與合成場景驗證；不新增要求使用者立即測試的入口、不套正式主線、不啟用新版Host。
保留完整物種AI、召喚／多階段攻擊、飛行視覺與人測缺口，不因本批有飛行數學就稱整體MEF完成。
