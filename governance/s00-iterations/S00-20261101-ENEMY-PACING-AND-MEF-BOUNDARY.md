# S00：首戰怪物節奏與MEF執行界線

接續REQ-0016既存v8人測回報「怪物攻擊積極性可能太高」。本輪S00自己核對來源與實作，
沒有新的人工戰鬥結果。AI／MEF與連擊維持最高優先，並未交由extra代查核心。

## 來源能支持的界線

KR原BIN SHA仍為`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
引用唯讀舊稿 `anal/MONSTER-STATE-TRANSITIONS-AND-SOURCES.md`、
`GENERAL-MONSTER-AI-COMPARISON.md`、`MONSTER-TICK-RELATION-AND-PRESENTATION.md`及
`SUBAI-ACTION-TRACE.md`，並選讀已存REA/Ghidra結果與重核原檔有界視窗。
舊稿所稱完整函式驗證只保留原先範圍，本輪不重新認證其全部主張。

- CMonster vtable`C0C9DC+24→4D1AF0`累積delta，依分支更新模型或呼叫`4C87D0`及virtual64。
  `4C87D0`最後呼叫目前FSM state的tick。存在怪物tick／狀態執行能力，不等於找到尋敵決策器。
  0.02／0.028571／0.033333／0.066667一類值是此更新分支條件，不能拿來當AI攻擊間隔。
- 既有隊友SubAI `549C60`在`549CFB cmp eax,9 / 549CFE ja 549DF3`限制施放者模型；
  model1036不通過這個入口。它能搜尋怪物作目標，不代表怪物可用同一施放者控制器。
- MEF換圖查找的未初始化helper `4F3D80`，可見會建立多個全域資料容器，包含FB74C4/C8；
  後段呼叫`4F4960`，再呼叫各表載入器，包含已知`4F5640` MapList載入。
  這縮小了初始化用途，但沒有完整窮盡所有下游，也不能因此宣稱所有MEF執行路線不存在。
- MapList的MEF字串查找、全域初始化、Map模型與碰撞載入、loading23/24顯示是不同界線。
  仍未定位「網路接收MEF內容→parser→生怪／AI」的可用opcode／格式，不能虛構傳檔。

[可重跑檢查器](../inspect_combo_state_boundaries.py)使用`--enemy-boundaries`：
[13視窗／5個vtable槽與原始SHA](evidence/S00-20261101-AI-MEF-EXECUTION-BOUNDARIES.json)。
只為限定byte／綁定證據，不是函式全集或原版AI驗收。
已存偽碼來源：`4F3D80=90b337985a4b549bbf4e166ae541ba1622d66a1b87a5408f7fed8632eddcf2e0`、
`4F4960=f24d09c24a1c495811ccbdee4f8398186c95444e702b08c7123b989747de013b`、
`4D1AF0=ec11641c9b2eebc56dac839033e77092c29e175574b9bdf0b946306ee165504c`。

## 本場教學的Server節奏修正

舊候選每怪各自1.5秒攻擊、無群體間隔，三怪抵達後可能密集出招。以下全部是
**Server重建規則，不是MEF、怪物資源或官方AI常數**，僅在既有expanded首戰使用：

- 群體兩次出招至少相隔800ms，每怪同時至少間隔2.4秒。
- 每次從上一個攻擊者的下一個位置循環找「活著、在近戰距離、動作已結束且冷卻已到」的怪。
  不因陣列排序讓第一隻壟斷；未到距離的怪不占名額，其他怪仍可追擊。
- 保留入場2秒觀察期、100ms決策、500ms起手後的距離檢查、875ms動作收尾與合法碰撞。
  躲開候選命中距離仍可避開此次傷害；已死亡的怪不再取得出招資格。
- 不降低傷害冒充受擊修復，不把等待期間改為靜止假怪，不新增Client／MEF接收介面。

與[連擊／受擊修正](S00-20261101-COMBO-RECOVERY-AND-HURT-COOLDOWN.md)合併為下一個有用版本。
當前Source測試24 HappyPath cases通過：新增三怪正常接近／輪流出招，在6.5秒內各怪均攻擊，
並核對群體與個體間隔、玩家實際扣血；既有正常首戰勝利、招募與出口合成旅程仍通過。
這不證明原版AI或Client手感；實際部署／人測另記。負向、重登、競態等仍暫緩。

## 仍待完成

MEF格式／接收／解譯、普通怪原生決策與權威來源、攻擊選招／仇恨／路徑、官方硬直／取消／
連段窗口，以及新帳號完整教學與合法結算保存仍未驗收。未將本場暫定規則套用馮德斯全部怪物。
