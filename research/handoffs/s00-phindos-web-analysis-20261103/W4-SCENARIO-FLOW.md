# W4：全村劇情副本／關卡／目標／結果／返回（P1）

你負責必要戰鬥內容的協定與資料，不研究S00自己處理的MEF核心或連擊執行器。先讀COMMON.md、
QUEST-SCOPE、舊RESOURCE-BASELINE、W1/W2的可用首批；可先獨立盤點章節內field/case/map。

請完成：
- 建立每個劇情需要的Scenario/Field/Case/Map圖與難度／編隊token；優先Field19/Case103/Map191/192，再盤點fields17/26/27/28及其他確實必經內容。
- 證明何時真正進戰鬥，不能因scenario_tuto腳本名就假定battle；也不能因某body沒有StartBattle就推定整條流程可跳過。
- 編隊→進場交握→地圖／actor／目標→成功條件→結果演出→返回的Client介面，分清一般22/type0、33返回與教學4C。
- 每關列所需怪物／目標／波次／位置／勝利條件／掉落／獎勵來源；原MEF無資料則UNKNOWN，附可明示的Server重建政策提案，不把影片數量當資源COUNT。
- BNDv2／動態阻擋列實際layout與消費路徑，不改version、不all-clear。

首批優先：15及第一章實際必經的第一關，提供可編碼正常封包／狀態序列。
最終交付scenario-flow.json、OBJECTIVES.csv、FORMATION-RESULT-RETURN.md、GAPS.md。未證資料不得填假配置。

## 可直接貼給Web AI的任務入口

請先閱讀共同規則：https://github.com/we88ec3-prog/ttr_anal_multi/blob/codex/s00-combat-priority-20261101/research/handoffs/s00-phindos-web-analysis-20261103/COMMON.md
然後執行本工作卡：https://github.com/we88ec3-prog/ttr_anal_multi/blob/codex/s00-combat-priority-20261101/research/handoffs/s00-phindos-web-analysis-20261103/W4-SCENARIO-FLOW.md
依共同交付格式新增results/W4/下的成果，先交P0可開發資料與精確未知。
