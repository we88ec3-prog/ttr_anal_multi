# S00：戰鬥結果修正與三怪 Server 行為候選

接續 REQ-0016，戰鬥第一優先。這是可實作的有限 Client 介面與明示 Server 重建規則，
不是原版 AI／完整官方戰鬥規則。REQ-0017 的教學出口阻點保留，沒有強制提前完成任務。

## 必要修正：舊候選把0F當成命中

現用 C# Hit builder 沿用了舊本機候選的0F；這是實作未核對實際接收路由造成的錯誤，
不能因舊測試通過就保留。舊 `anal/tutorial_battle.py` 同樣錯誤，不可再直接引用其0F註解。

- `000E → 436C40` 為 scene virtual28；TUTO vtable C073E8+28 指向4B0640。
  接收器以2-byte header＋13-byte row讀 Source WORD0／Target WORD2、case BYTE4、
  effect BYTE5、DWORD+6及其他部分未知欄位。case0候選仍不代表完整傷害公式／狀態枚舉驗收。
- `000F → 4B19D0` 轉 controller virtual3C；TUTO controller C0FB1C+3C=545C50。
  545C50檢查0F後讀訊息+7，走 CANNOT_USE_SKILL／其他狀態提示，不能充當命中消費端。
- 角色4CE7F0、怪物4D1E10的parameter1顯示值乘約0.0001。
  原候選送100／67／33不是滿血／67%／33%；新候選用10000／6667／3333／0。
  此比例值與5C絕對生命資料分開，不把parameter1=300稱為血量300。

既有T12 `BATTLE-RESULT-AND-AI-FEEDBACK.md`、怪物parameter報告作有限來源引用；
本輪重新核對原始 SHA、TUTO兩個vtable槽、9個指令視窗與比例常數。
原始 BIN SHA256
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
[可重跑檢查器](../inspect_tutorial_combat_sources.py)與
[metadata／byte證據](evidence/S00-20261101-COMBAT-RESULT-AND-ANIMATION.json)。
它不是完整函式／分派／全部結果case的FULL-PASS；原始證據、Client與資源不修改。

## 動作資料與尚不能直接套用的時序

Character/Cha/Base.stp的Cha/Isla.abf：101…107對應七段SKILL01 ASD，108對應WSLASH、
109對應SSLASH。Character/Mon/Base.stp的03_Assassin.abf：101…103為技能，7為死亡，
4／6為移動動畫。相關11個ABF／ASD member與carrier SHA存於上述證據，不公開整份資源。

ASD包含SpliteData的FPS／StartFrame／EndFrame／Delay；105／106有多段，108有混合FPS
與負Delay。故不能把ABF Length一律除40當成所有動作時間，亦不能把Skill ID當Motion ID。
本輪確認資料配對，尚未閉合ASD parser時序、取消窗口與命中frame；候選impact仍明示200ms。

## Server候選的具體內容

新opt-in模式 `LOCAL_WORKING_COPY_TUTORIAL_COMBAT_CANDIDATE` 保留原05/1→09與TUTO返回，
啟用三個獨立monster entity101/201/301(hex)，model1036、PRE1、scale1。
三怪是依使用者影片觀察採用的 **Server重建配置**，不是從COUNT1或不存在的MEF推導官方總數。

玩家368/272；怪376/272、386/280、386/264。對pinned scenario_town000.bnd
`7c98d3d5c5512cfe20f2946abc27c1c94424474ee6450fa3593693a4c5139bfc`
唯讀解碼，四點兩個來源層皆0。這只證靜態格可走，不證官方出生位置／動態碰撞或完整路徑。
Host啟動前核對新增點，沒有用all-clear fallback代替實際資源。

| 項目 | Server重建政策／實作 | 原生限制 |
| --- | --- | --- |
| 初始化 | 每怪HP60、parameter1=10000、speed倍率100／base18 | speed欄位有來源；18及HP60為候選數值 |
| 行動 | 入場2秒後以Server pose尋玩家，每100ms決策，單次移動至多250ms、四分之一單位碰撞步進 | 不是官方仇恨／導航／AI；無MEF下載 |
| 播放／同步 | 000B移動、000C移動／待機狀態，0016同步Server位置；000D只在出招／死亡送一次 | 不反覆送技能播放來假裝尋敵；移動呈現仍需人測 |
| 近戰 | 距離10出招101；500ms後距離仍<=12才命中，傷害15；action875ms、間隔1.5秒 | 都是Server政策，非官方命中／冷卻／傷害 |
| 玩家 | HP500；技能可攻擊範圍內各存活怪；普攻20、X35、組合60 | 原攻擊幾何／公式仍部分未知 |
| 成本 | 初始SP/MP100；X消耗35/30，組合消耗80/0；不足不授權施放 | 參照資源原值建立策略；正式單位／裁決及冷卻UI未閉合 |
| 死亡／勝利 | HP0停止怪物移動／待命中，播放7，1秒後只刪該entity；三怪全滅且玩家存活才在1.25秒後走既有win持久化／返回 | 延遲為展示政策；不是完整官方結算／Quest14/16 |

玩家HP0會停止施放且不給勝利／返回資格，但正常失敗、復活／重進UI還未完成；不得宣稱完整失敗流程。
舊首戰模式保留單怪候選，0E與血條修正共用；只有明確新模式才啟用三怪、AI與成本。

## 驗證與人測範圍

14個HappyPath cases通過：既有SQLite/TCP正常旅程13例，外加一例受控clock／all-clear
fixture的三怪行動、出招／反向0E命中、玩家受傷、三次普攻全數擊敗、死亡移除與返回資格，
以及正常技能成本／多目標命中。共208方法／10正向方法／198暫緩。
合成fixture不是實際地圖／Client畫面驗收；實際出生點另有上列pinned來源格檢查。

下一人工段落：重開→正常教學→預設伊莉西亞編隊→先觀察怪物追擊／攻擊→Z連按／放開、
X技能→全部擊敗返回即停。先驗敵我動作、血條與命中感，不把目前能返教學當完整教學進廣場通過。
招募／後兩段劇情與REQ-0017不因本輪刪除。其餘異常／邊界／競態／恢復／安全及壓測只記待測。
normative pin `dd69ec9de353a695d25c6db8e362ff471ea0c137`、formal admission與所有APPROVED狀態不變。
