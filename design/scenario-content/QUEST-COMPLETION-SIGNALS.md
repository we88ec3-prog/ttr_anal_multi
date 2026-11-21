# 已交付普通任務旗標

2026-11-22，Server-owned scenario V1／NOT_NATIVE_MEF；對應 P0 E3。
訊號 `QuestCompleted` 帶 `quest`（既有 LocalPhindosHuntingQuest 目錄中 ushort
任務ID），不得帶 region／interaction／delay／wave／health／product／quantity。
只觀察已保存 Completed，Accepted／Ready 不算完成。這不是主線 QuestIndex，
不接受任意Quest ID，也不把Client任務日誌封包當資料來源。

正常 connection 持有效 SessionLease，以當前已授權參戰角色呼叫既有
ILocalPhindosHuntingQuestStore.ReadHuntingQuestAsync。普通任務完成紀錄屬帳號，
紀錄中的接取角色可不同於本場角色；參戰角色仍須由既有服務檢查已擁有。
只在可互動的本場節點觀察未達標訊號，每500ms最多一批，每個不同任務只讀一次；
全部達標即停止讀取，沒有這類訊號的舊內容不增加資料庫查詢。

完成後設立本場一次性旗標，供既有出口、互動、增援、屏障與危險區使用；
不修改任務、不交付、不給獎勵，也不消耗道具。此事件明確為 OpenOnce，
不是可撤銷的任務狀態門檻；Completed在現行正常服務為終態。未取得授權
快照不設旗標。換圖後只觀察新節點；既有旗標依run規則保留，離場／新run重新計算。

管理端訊號編輯新增事件與Quest ID欄位，保存／匯出沿用不可覆寫版本，
不自動發布。指定v2、非正流程及資料故障等待測安排維持。

## 整合候選與保存界線

獨立 `phindos-stage462-case693-quest-gate.scenario.json` 首圖出口同時要求
Q2842已交付與原有消耗機關成功；波次、頭目階段、兩分支、子彈呈現及88EXP不變。
配套AI沿用integrated-projectiles；原版BND與來源鎖定不變，原件／舊版保留。
啟動腳本選項 `IncludeQuestCompletionGate` 啟用既有普通任務服務；正常玩家
仍須親自交付任務，不因選此候選自動完成。此選項與獨立權重候選互斥。

檢查器的準備帳號先經既有store API接取／Ready／交付Q2842，再正式TCP登入；
任務獎勵在本場經驗基準之前，通關增量另驗88EXP。這不是自然NPC交付驗收。
管理端新欄位目前只有編譯／契約驗證，尚未列為瀏覽器互動通過。
Schema同步補上原已實作、但舊Schema遺漏的BagQuantityReached欄位與條件；
兩庫schema逐位元組一致。詳細結果見後續機器收據。

## 正流程驗證

Release Host／Inspector／Admin.Web皆零警告錯誤；HappyPath655/655。
兩條正式gateway元件loopback TCP路線均保留任務旗標至各圖出口、保存88EXP，
回同一村莊隊伍；包含原有消耗機關、波次、活頭目階段、分支及結算。
獨立Host設定預檢、兩庫Schema逐位元組與Quest／Bag正面樣本驗證通過。
三個新增單元案例涵蓋Accepted→Ready→Completed正常進度、跨角色帳號完成、
一次觀察釋放多消費者、規劃fork與換圖保存界線。
詳見 [機器收據](quest-completion-signals-validation.json)。

2026-11-22後續：[正常NPC／TCP接取交付補驗](../testing/QUEST-GATE-NPC-TCP-ROUTE.md)已完成兩路。先走Q117主線交接，再真實0036／001C接取交付Q2842，之後門檻副本88EXP與任務700EXP分別核對。這補上本文件原批次的prepared-record限制，Client、自然新帳號及獨立Host遊戲通關仍待驗。
