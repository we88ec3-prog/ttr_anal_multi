# Web AI共同規則與交付格式

這是使用者授權的遊戲Server分析工作，目標為明天開發馮德斯村完整劇情所需的資料。
分析庫：https://github.com/we88ec3-prog/ttr_anal_multi 。使用分支`codex/s00-combat-priority-20261101`；
工作卡資料在`research/handoffs/s00-phindos-web-analysis-20261103/`。不要只讀main而漏掉本包。
先讀AGENTS.md及shared/CLIENT-MODIFICATION-POLICY.md，並沿自己的原有分支／Task權限工作。

## 可直接開始的資料

- [目前採用分析入口](../../../governance/s00-iterations/S00-CURRENT-DEVELOPMENT-INDEX.md)。
- [QUEST-SCOPE](QUEST-SCOPE.json)：原始Table來源、77筆Town1任務及橋接15、章節1的9任務／28場景、跨Town候選依賴。
- [28段場景索引](scenes/INDEX.json)：每段分檔列原member SHA與literal calls；共1173個呼叫，未解析行0。
- [完整資源scope](RESOURCE-SCOPE.json)為上述總包；不用一次載入全量，先按分工選讀各scene。
- [前一批地圖／NPC／副本基準](../s00-phindos-mainline-20261102/RESOURCE-BASELINE.json)。

原始KR BIN SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
已保存REA/Ghidra `kr-bulk-roy/<SHA>/functions/`與raw Evidence可按精確位址選讀，不重跑全量反編譯。
原BIN、STP資源未隨本包公開；Web看不到本機E槽。沒有原檔時不得聲稱重新核對原始bytes。
本包由本機唯讀檢查器產生，原Table載體與member SHA已核對；本地Event可能有歷史翻譯，
只鎖定實際SHA，不認證為pristine。Call inventory不是helper語意或runtime完整證明。

## 現況與嚴格界線

新帳號正常教學到廣場已有人工通過。尚未實作正常馮德斯村進場。
目前Server怪物AI是重建程式，不是MEF。MEF接收／格式未知；S00自己處理核心AI／連擊。
不要執行／附加／修改Client、資源、帳密或Server，不提交GitHub Issues，不把待測試當通過。
Quest/Scene/Field/Case/Map/Town/actor/role是不同型別；Request/Notification/ACK也不同。
NPC某條1C路徑先有本地scene呼叫，3F literal1可由清理路徑產生；禁止猜通用播放ACK或直接完成任務。
演出座標不是一般玩家spawn；四個進村演出點在現有Server碰撞讀取器中blocked，不能照抄。

## 每項交付必填

1. **完整對照表**：觸發／前置 → Client producer／event → Server權威變更 → consumer／UI／scene → 正常下一步。
2. **機讀資料**：typed IDs、欄位／長度／方向、map與位置來源、條件／branch、reward／ownership，供Server直接實作。
3. **證據表**：source path、commit/blob或member SHA、位址／行／call、已證範圍；把原生事實、派生觀察、Server規則提案、UNKNOWN分欄。
4. **未知清單**：精確卡點及解除它需要的函式／資料；不要只寫「Server還需處理」或用猜值填滿。
5. **正常驗收卡**：明確操作與停點、預期畫面／保存狀態。負向／取消／重登／競態／故障／壓測只列待測，不執行。

沒有官服後端源碼不是不做Server規則的理由：可提出可實作的Server政策，明確命名與前置，
不得把它當原版事實。缺Client欄位／路由則保留UNKNOWN，不能用Server自訂掩蓋。
FULL-PASS須涵蓋精確版本與全部實質主張；hash／抽樣bytes PASS不等於全文原生驗收。

成果只新增於本包`results/Wn/`，不覆寫其他Task／歷史來源／owner／正式狀態。
有Git寫入能力時提交並push自己的授權分支，回覆精確commit與每檔blob SHA；
沒有則回覆完整檔案內容／patch與未推送狀態，不能聲稱上Git。
先交P0首批可開發資料，再補全；對話真的達長度上限就交checkpoint並停止。

## 開工前最新狀態

請補讀[實作狀態更新](CURRENT-IMPLEMENTATION-STATE.md)，勿把保存候選或合成發布視為live已支援進村。
