# W2 未知、Server 開發需求與解除條件

狀態：`DRAFT_FOR_REVIEW`。本頁的 `W2-U*`／`W2-SRV-*` 是此交付的局部引用鍵，**不是新建的正式 RR／REQ／SPEC 台帳**。請 S00 按既有流程去重、採用與登錄。材料來源版本、SHA與實際讀取範圍見 [source-index.json](source-index.json)。

## 1. 九類 AI 欄位：來源線索與決策值分開

下表的「無來源」特指**這三怪的可直接採用 AI 決策／判定值**，不否定已讀原件的 FILE/PRE 或舊報告的有限動畫／矩陣提示。

| 欄位 | 1001 | 1009 | 1004 | 已知來源線索與不能推廣的界線 | Server 候選需求 |
| --- | --- | --- | --- | --- | --- |
| 追逐 | 無來源/null | 無來源/null | 無來源/null | 舊報告：1001 slot4=`HokyPoky_MOVE01`；1004 slot4/6=`Nepenths_WAIT01`。無速度／路徑／停止條件；WAIT不等於永不移動。 | W2-SRV-01 |
| 感知 | 無來源/null | 無來源/null | 無來源/null | 五表未建立三怪的感知半徑、視線、仇恨或目標選取欄位。 | W2-SRV-02 |
| 回位 | 無來源/null | 無來源/null | 無來源/null | 未有回位距離、出生錨點、仇恨清除或HP重設的三怪來源。 | W2-SRV-03 |
| 選招 | 無來源/null | 無來源/null | 無來源/null | 舊報告1001 tier0 key1/2/3→76/307/371，只是matrix cell；無權重、時機或PRE對應。1004/1009無具體技能值。 | W2-SRV-04 |
| 起手 | 無來源/null | 無來源/null | 無來源/null | raw Actor/ABF未附；無frame/FPS/event。即使之後得動畫總長，也不是Server起手判定時間。 | W2-SRV-05 |
| 命中 | 無來源/null | 無來源/null | 無來源/null | 無三怪 skill→action→event/effect 的正向橋接。獨立Effect Index不能與skill WORD等值相接。 | W2-SRV-06 |
| 冷卻 | 無來源/null | 無來源/null | 無來源/null | SkillActive有`ACTIVEINFO@cooltime`，但無三怪row；單位、開始／清除時點與monster instance未證。`54F270`是可用性檢查。 | W2-SRV-07 |
| 受傷 | 無來源/null | 無來源/null | 無來源/null | 無受傷動作／硬直／打斷／恢復的三怪來源。 | W2-SRV-08 |
| 死亡 | 無來源/null | 無來源/null | 無來源/null | 無三怪死亡slot、結算與移除時點。不能把動畫結束當死亡權威事件或任務完成。 | W2-SRV-09 |

每個JSON profile都有完整九欄，無來源欄位同時保留 `value=null`、`unit=null`；來源字面／報告值與候選政策另列。`null` 不得在匯入時自動轉成0、false或預設節奏。

## 2. Client 待逆向／原始資源缺件

| 局部ID | 已讀範圍與已排除候選 | 精確缺口 | 解除條件／缺件鍵 |
| --- | --- | --- | --- |
| W2-U01 | `_ActorList` 的category1／3怪／12個PRE，只有FILE stem；舊報告稱查過ABF但未列完整member。 | `00_HokyPoky`、`01_Moose`、`01_Nepenths` 的carrier、完整member、副檔名及body SHA。 | 從S00既有member索引按精確stem取得實際名字及原bytes；W2-M02/03/04。不能先拼`.abf`或`Actor/Monster/`。 |
| W2-U02 | `SkillMatrix.xml`只有兩個MatrixInfo import；raw MonsterMatrices未提供。 | 三怪完整matrix cell、variant/tier/key，1001舊報告值的raw複驗與PRE映射。 | W2-M01精確member `Table/Skill/Matrix/MonsterMatrices.xml`；回傳實際carrier/member SHA，保留全部variant/tier/key。未證PRE=variant/tier。 |
| W2-U03 | CharSkill只含CHAR1..9。SkillActive469個`no`中無76/307/371及1001/1009/1004；IndependentSkillEffect92個Index亦無上述值。 | Monster技能WORD到實際定義、動畫slot、命中／效果事件的typed provider。 | 先M01及body，沿實際引用取M07。檔名仍未知，可能與M05/body同檔，不能要求一個憑空命名的技能檔。 |
| W2-U04 | 五表欄位完整盤點；未附已確認Monster table。 | Monster metadata與ActorResourceKey關係，以及欄位consumer。 | M05僅是來源角色未解，不是`Monster.xml`存在證明。若資料本來不含官方AI，轉為S00明示候選設計；不無限等待官方Server原碼。 |
| W2-U05 | 比較報告僅提供3個動畫slot引用；三怪raw body未附；沒有frames、FPS或events。 | 呈現clip時間、skill/action事件、hurt/death slot與實際載入引用。 | M02/03/04及其明確下層引用。標記動畫呈現時間的量綱及來源，Server時點另設欄位，不換算後直接套用。 |
| W2-U06 | 既有consumer報告將`549980/54AE70`限定hero≤9；`54F270`檢查remaining==0；`54F330`複製16-byte UI snapshot。 | 原生怪物指令來源／controller／結果消費接口尚未由本包閉合。 | 先由S00引用既有已證相容介面；若真的需要未知native wire／parser／writer，交原Task限定補證，不把缺失wire推作自由Server政策。此輪不重掃、執行／附加Client。 |

**沒有證據可以把玩家SubAI入口當Monster AI。** `549D54→54F270` 屬獨立的`549C60`，不屬`549980`；保留T10-026既有`NEEDS_FIX`。同樣使用樹helper不表示同一資料域。完整consumer適用條件與地址見 [consumer-notes.md](consumer-notes.md)。

目前可供S00抽取的清單是1個精確MonsterMatrices member、3個stem body；另列M05來源角色、M06可選玩家比較、M07取得第一輪資料後的條件式provider。**CSV的7筆不是7個已知檔名，也不是官方AI還原所需檔數的保證。** 不把29個未附的歷史README引用全升成W2必需品，不要求使用者自行補找檔案／影片／截圖。

## 3. Server 待開發：可獨立推進的相容行為契約

下列均為**候選政策／開發需求**；本輪不寫Server、不給官方數值、不宣稱S00已批准。可先做可配置介面與狀態轉移，數值由S00依玩家目標決策並保留版本。

| 局部需求 | 玩家情境與需要的行為 | 已有來源能提供什麼 | S00仍需決定／實作 |
| --- | --- | --- | --- |
| W2-SRV-01 追逐 | 玩家移動後，怪物能依規則接近／停止／重選目標。 | 3個ActorResource identity、FILE/PRE；有限MOVE/WAIT呈現提示。 | 移動／路徑介面、速度、停止條件；不得以1004 WAIT01永久禁止位移。 |
| W2-SRV-02 感知 | 怪物從有效玩家中決定是否進入戰鬥。 | 無三怪原生感知數值。 | 目標候選、同場景有效性、範圍／視線／仇恨與更新時機。 |
| W2-SRV-03 回位 | 目標離開或追逐越界後，怪物返回適當位置並恢復狀態。 | Cluster出現資料不等於出生世界座標或回位半徑。 | 出生錨點來源、leash條件、仇恨與HP重設；和W1場景／出生定義串接。 |
| W2-SRV-04 選招 | 在可用技能中依條件選擇，不能每隻怪堆專用if。 | 型別化matrix／skill引用介面；1001有3個舊報告候選值。 | 先消費已解析目錄，再配置距離、可用性、資源與優先序。未知引用不得默認可施放。 |
| W2-SRV-05 起手 | 起手、打斷、提交攻擊與動畫呈現同步。 | 目前無三怪frame/event資料；之後的clip資料僅提供呈現。 | 明訂起手／提交時點、可打斷階段與動畫參數，避免用clip總時長替代全部判定。 |
| W2-SRV-06 命中 | 攻擊造成可解釋、可重現的命中／傷害結果。 | 本包沒有三怪完整技能→命中事件鏈；既有共同戰鬥介面須另外引用其原稿。 | 目標／範圍判定、傷害交既有T12／Server契約、權威事件與結果同步；未知wire另補證。 |
| W2-SRV-07 冷卻 | 怪物施放／取消後按規則再次可用。 | `54F270`僅可用性predicate；SkillActive欄位未綁三怪。 | 時間單位、冷卻起算／取消／重設與next-usable狀態；不沿用舊自製v41或玩家fixture猜值。 |
| W2-SRV-08 受傷 | 怪物受擊後按設定反應，既有玩家連段核心維持其責任界線。 | 無三怪hurt slot／取消窗口原值。 | 受傷反應、硬直、取消／恢復；在Monster狀態介面配置，避免混入玩家SubAI限制。 |
| W2-SRV-09 死亡 | 怪物死亡後結算、通知任務與移除，呈現可以稍後結束。 | Actor identity與原生呈現引用的來源追蹤結構；沒有死亡時序數值。 | 死亡權威事件、結算／掉落／任務事件的一次性處理、移除條件，與T16/W1流程整合。 |

同一怪物可由資料profile描述不同PRE／場景設定，但**是否跨PRE共用技能／AI不能由同一FILE直接推出**。源資料的presentation、Server rule及runtime state應有各自欄位。此建議是候選資料／接口設計，未冒稱原版Server實作。

## 4. 跨功能待整合

- **W1／場景生怪**：55筆OBJECT只作來源出現清單。由W1/S00選定群組、合法spawn與場景node；再把確定的ActorResourceKey交給Monster profile。群組ID、ActorID、PRE與world entity ID各保留型別。
- **T10/T11／戰鬥**：先重用有明確來源及適用條件的共同接口。矩陣讀取並未決定目標或出招時機；不得利用本包順便改連段核心，或覆寫T10待修原稿。
- **T16／任務**：仍保留20 definitions、4 flows、8 scenario entries的`DRAFT_BLOCKED`。本W2 JSON不是原生MEF，完成資料格式轉換不等於可正式啟用；怪物動畫播放成功不是任務完成。
- **T01／S00接收**：Git blob／SHA對上只證來源身分。這次是W2使用者明確工作包，不是RR公開認領；沒有變更唯一RR台帳、owner或native_complete。後續由T01核對有界來源、S00採用Server需求，與真人驗收分開。

## 5. 待遊玩驗證（本輪未執行）

由S00在對應Server實作就緒後安排正常流程驗收：三怪載入正確FILE/PRE、玩家可看見其移動／起手／命中／受傷／死亡、技能事件與Server狀態一致、清怪／任務／出口接續正確。此清單不是現已通過的結果，也不要求上班中的使用者立刻補拍。

本輪沒有啟動Client、Server或舊證據腳本；沒有重做BIN／MEF搜尋，沒有更改原件。`verify_inventory.py`只檢查資料、來源與未知值保存，不證實動畫實際播放、原生怪物決策或可玩性。
