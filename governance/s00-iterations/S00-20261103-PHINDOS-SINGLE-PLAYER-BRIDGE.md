# S00：單人主線副本接續至馮德斯村的候選實作

使用者要求先完成「正常進入馮德斯村」，上Git後再開始人測；並明確更正：
**主線編隊頁進入的是單人任務副本，與多人組隊任務是不同項目。**
這是PLAYER_ADMIN_REQUEST，沒有新增遊戲實測，不捏造GAME_RUNTIME_OBSERVATION。
沿用REQ-0018廣場NPC及REQ-0019進村／整村主線，不另建同義REQ。

## 已接通的Server候選路線

新帳號正常教學保存與前置14/16發布 → 廣場靠近10338並確認本地15/1 →
40/15接取UI與47/15/2 → 正常15/2回報 → 空預選編隊50/4E → 玩家28確認 →
一般Scenario5F/type2 → Field19/Case103的map191與map192各自戰鬥 →
22/type0結果頁 → 玩家33返回 → 一般村落候選99/type3、Town1/map182、
15/3村落劇情 → 15/4 → 保存到達資格並完整重建村落player/NPC/checkpoint/control。

任務、場景、Field、Case、map、編隊echo token各自分域。只有Server遭遇全怪死亡、
死亡演出完成及逐階段資料保存，才可推進下一張圖／結果。3F literal1不當成勝利、
Quest15完成、發獎或Client已載入的證明。到達亦不等整村主線完成。

目前編隊限制為一名已擁有且已支援技能的出戰角色1/3/4；三角色隊伍的跟隨與技能
同步未完成，蘋果出戰未完成。**單人副本不等於原版只能選一名角色**；此為候選限制。
不會將這些缺項歸因為多人組隊未開放。多人邀請、匹配及多人任務不在本次路線內。

## 本輪採用來源與重建規則

- [v2碰撞讀取資格](S00-20261103-FIELD19-BOUNDS-V2.md)：原件三函式／11精確指令核對，
  Road191/192只允許精確SHA的v2，原v0及解壓／圖層／長度檢查保留。未改原檔。
- [怪物動畫資源](S00-20261103-FIELD19-ACTOR-RESOURCES.md)：選1001／1009的移動、
  攻擊101及死亡7；植物1004不套移動型AI。
- [村落配置與控制器](S00-20261103-PHINDOS-TOWN-LAYOUT.md)：Town1九名NPC成員、
  嚴格驗過的連續可走候選區與獨立玩家位置；未挪用劇情演員／NPC座標。
- [原T07釘定收件副本／有限證據](evidence/t07-phindos-intake-20261103/README.md)包含
  `STORY-AND-FREE-PARTY-INTERFACE`、`FIELD19-CASE103-ID-CONTRACT`、
  `SCENARIO-RESULT-AND-RETURN-INTERFACE`、`SCENE-ROUNDTRIP-INTERFACE`：
  50的可用mask／空預選／容量，4E只echo，5F2控制器kind3，38+7是Case103，
  +3是結果背景19，22一般結果及33返回，不沿用教學專用4C。
- [原件NPC意圖欄位查核](S00-20261103-PHINDOS-NPC-INTENT.md)驗過五個範圍／47項斷言：
  `544070`為NPC category3建立F43D9 I3，欄位依序NPC/category/NPC；保存的
  `5B9340`確認分支將nested event+18/+1C打包成1C的兩個WORD，並先呼叫本地scene。
  modal wrapper完整建立與生命週期仍未閉合，原I3不直接等同outer確認事件。
  這是選定分支的有界來源，不是所有NPC的通用ACK／官服完整發包全序。

每圖各用一組原cluster成員：node1的1001×3/1009×1、node2的1001×2/1009×2。
**選組、每圖四怪、全死自動下一圖、生成位置、HP／傷害／冷卻均為Server重建政策**，
不是從COUNT相加推得原版總怪數，也不是MEF控制／AI還原。
38+5未解、編隊token19、容量1、22中零統計與+9直接返回、MissionRoom作普通Town1、
位置與方向均保留候選標記。不將已知consumer包裝為官方sender已證。

## 保存與驗收分層

私有Server增加獨立Phindos component v1，Host只驗證不自動migration。
實際28確認後固定角色／現行lease，依序保存Accepted、FirstMapWon、SecondMapWon、
ArrivalAuthorized。每次核對同連線教學transfer／settlement及前置14/16。
沒有寫入Quest15完成key，沒有把待發獎勵標成paid，沒有把歷史帳號補成已走完本輪。

新增的正常TCP／SQLite案例已通過：從新帳號經完整教學、正常NPC／編隊、兩張真戰鬥、
結果返回、村落劇情、九NPC及村內移動停止；另直接SQL核對四階段與同lease、角色。
此案例用測試碰撞fixture；真實BND須另做候選程式的唯讀preflight。
完整正流程批次27項通過、0失敗／略過（15秒）；Host發行及LocalDev／Inspect工具
建置皆零警告／錯誤。實際C#讀取器對兩個精確BND執行，兩圖各五個生成點全可走。
未跑延後異常測試。
最後僅收緊教學招募階段在進村後的資格，再跑新增進村正常案例1項通過（4秒）並重新發行；
未擴大重跑其他已通過的測試。

尚未取得本輪人測結果；不能把這份報告、合成通過或上Git當成原版Client成功／
正式規格批准。Client程式／資源保持不動。已通過的教學到廣場人測不被改寫。

## 人測停止點

一次連測至馮德斯村：編隊先選伊莉西亞一人，完成兩張圖的正常戰鬥，按結果頁返回，
看完村落劇情；人物與NPC出現後走幾步、放開停止就停。不接下一個任務、不跳過教學。
遇到卡住、殘窗、不能攻擊／移動立即停；記錄最後畫面與載入畫面是否看見。
三角色／蘋果、重登、取消／重送、死亡恢復、併發、安全及壓測先留待測，不現在跑。
