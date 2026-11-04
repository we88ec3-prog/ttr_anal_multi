# 一般副本：0022結果場景與0033返回入口

roy／T07，含必要T14/T02/T08/T06跨查，待整合。原BIN SHA9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，REA6.5.0/Ghidra12.1.4現成bulk、Python3.10.6/Capstone5.0.7原件bytes。未執行／附加client、未呼叫目標API、未發包或啟停服務。此文件補足一般副本結果介面，不重新定義TUTO004C。

## 場景結果入口

SceneManager在4B7DC0將FD2E0C寫4B9770；依base FD2CFC、stride8為**S2C0022**。4B9770讀BYTE message+2作結果模式。type0分配6104bytes，先4B9E30建CDecisionBase，再把vtable寫C07374、D6A674=53434544（SCED）；4B7D50安裝後呼叫新scene virtual+38。原件RTTI C07374[-4]→COL C69D60→type descriptor F7E194=`.?AVCScenarioDecision@Scene@@`，不是依歷史命名猜類別。

C07374+10=4C43B0，+38=4C4550；4C43B0停止／清理目前過場、清checkpoint，並將UI manager pending設8（已是8則58A9A0）；5877F0把state7註冊CScenarioFieldPage、state8註冊CScenarioResultPage。因此一般Scenario有獨立結果場景／頁面，不能直接套用TUTO場景的004C完成等待或005F/type6。

排除：先前候選005F/type9經4C54E0實際為CRaidField（RAIF），不是Scenario結果場景；0060/4B8F50是另一個頁面／場景安裝路線，本批不採作正常結果入口。沒有因候選函式存在就把它列為可發包方案。

## 0022/type0結果payload的已確認讀取

| 相對message欄位 | 4C4550行為 | 限制 |
|---|---|---|
|WORD+0|0022由SceneManager路由|不含外層framing|
|BYTE+2|必須0，否則報錯、條件送C2S0019（2bytes）並return80004005|不能用其他type假造Scenario結果|
|BYTE+3|本選定接收器未讀|未證其名稱、合法值及是否別處消費|
|DWORD+4|複製到FE18F8+24|其中BYTE+4為0時4BA8C0參數1，且6BA400選用不同結果文字；不泛化DWORD全體語意|
|DWORD+8|複製到manager+28|BYTE+9（即manager+29）控制結果按鈕是否先開另一視窗|
|DWORD+0C／+10|複製到manager+2C／+30|完整統計／獎勵欄位語意未還原，不猜值|
|WORD+14|複製到manager+34|有效讀取下限到+15，共22bytes，並非官方完整長度證明|

之後4C4550排F4297，呼叫4BA8C0(message[4]==0)，再helper。5AAE50收F4297呼叫6BA400刷新ScenarioComplete視窗。這證明結果資料的UI消費鏈，**不是Server何時有資格宣告勝利／發獎的規則**。

## 0038+3的新consumer：結果背景索引

40F060返回FAB130；0038/4B1BF0非town分支把WORD+3寫manager+90，即FAB1C0。4BA8C0拿FAB1C0作Table/_PositionList.txt索引（每筆五float），並呼叫4DF510(FAB130,50000+該值)。這是結果演出背景／位置的原生consumer，不能把0038+3當作0012實體地圖selector。

原始Table carrier SHA09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442；_PositionList.txt有665筆，索引19五float=734/1106/75/0/355；_SysMapList.xml有50019→victory_mushfarm。這與Case103.STAGE19／Quest15.field19可作重建配置對照，但本批不把五float稱為玩家出生點：它們由結果演出camera／模型相對擺位使用，村莊與戰鬥的合法spawn仍另缺。0038+5的完整語意仍未證。

4BA8C0先經virtual+30 snapshot控制器三槽可用角色（454070），再清已追到的actor manager，載結果背景、建立結果演出；後段舊controller種類不為0則清理／解構，建CEmptyController、FBA7AC=0、最後+4=1。故結果階段本來不能靠ready恢復行走；回村／廣場仍需合法CSquare安裝→Single控制器、最後reset後玩家重綁與ready，不能重用結果的EmptyController。

## 結果按鈕返回

6BA2C0只在目標按鈕click0x578，送內部F431F，帶BYTE(manager+29)，即原payload+9。5AAE80的F431F處理：參數非0時先關目前視窗、6BF310／596E00開另一視窗；參數為0才條件sender送**C2S0033，body僅WORD0033（2bytes）**。沒有目的地Town／Map ID，也沒有Quest ID，Server應只在自身當前結果階段接收。

本批只閉合零參數直接返回分支；非零的檢視視窗、其最終確認／取消仍需查，不得為了避殘窗就猜payload+9=0是官方值。結果按鈕送出0033不等於已回村；村莊安裝／資料與15/3劇情入口仍需Server接續。C2S0033亦不能反推官方必定回先前城鎮、廣場或馮德斯村。

## Server接續約束與未知

- 若採一般Scenario結果流程，先由有來源的達成狀態作結算決策，再按0022/type0接口準備資料；不能把第一個怪物HP0／clusterCOUNT相加作官方勝利。
- 只有合法當前結果的0033（含非零檢視後真正返回路徑）才啟動目的地轉場；Quest15/3可以透過前批已證0047啟動，但成功任務提交、播放時機和村莊資料偏序尚未完整證明。
- 村落可操作需kind2／玩家綁定、合法map/context/位置及過場正常解除。其後廣場↔村落旅行應獨立於一次性Quest15狀態。

7項原件靜態核對與來源SHA在scenario-result-evidence.json；工具限制與入口範圍保留。沒有建立新可玩版本、沒有實測進村或雙向旅行，所有新成果先待整合。
