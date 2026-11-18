# 本輪獨立覆核與採用修正

本頁記錄分析包的覆核，不更動正式RR／FULLPASS／人測或部署狀態。四個工作分題分開產出，root整合後再做交叉檢查。

## 原件交接獨立覆核

`level_outcomes` 使用自己的PE映射／rel32讀取器，重新比對finite-handoff的9窗口／2175 bytes、3字串、3個file vtable槽、7個call與9段條件／讀寫指令，並以fresh objdump讀Start、End、seen writer/reader。結果是 `PASS_FOR_DECLARED_STATIC_SCOPE`；保存了受覆核檔案hash與限制，見[獨立收據](outcomes-continuity/root-handoff-review.json)。

確認CSL.scn持久化路徑、003F可能來自seen-skip、重啟不保證未看、Q119清場兩次敘事提交／重建／完整0027。可跳過的選用演出不作唯一開門依據；若將來改成最後setter才開門，另設延後開點與generation ownership契約。

## 規則／時計覆核

`level_rules` 覆核finite-handoff與根20功能／9優化矩陣，沒有阻擋項。root採用了以下精確化：

- NodeDelay在清場劇情中仍計入經過時間，僅延後事件派送。
- 清場條件保留剩餘投射物、既有勝利／移除等待。
- 六種計時語意不寫成六個實體時鐘；期限排程沿用既有單調時計。
- 26筆flag引用是67檔合計，並非每場索引規模。
- 圖／條件固定點PASS明示戰鬥可完成、區域／互動可達等前提。
- BossDefeated的合成紀錄、延後Boss的私有離線紀錄、初始空場schema支援分開，避免擴大證據強度。

## 空間／內容計數覆核

`level_space` 獨立核對根報告與玩家表的1763／1753／10、其餘66檔1750、13點候選未套用、三個18步屏障繞路。root採用補句：二維中心與四鄰連通不證三維／身體尺寸／Client動態碰撞；局部障礙不等於出口授權漏洞；真封路需驗必要機關可達側和模型／碰撞配對。空間分題也覆核rules的幾何假設與計數。

## 結算／保存覆核

`level_outcomes` 覆核根L14–19與玩家表。root採用：一般副本實際收據與主線待結算預告分開；未完成主線重登須從NPC重開，但已領物品／已入帳擊倒XP保留；跨副本機關／波次旗標的缺口不擴大為帳號資產未保存；角色延續預設關閉且限同場；Q119所選成長配置首次完整5948EXP。

同時保留完全復活的死亡懲罰consumer、Raid主動退出／斷線CP政策、掉落外觀、具體退出UI各自缺口，不將它們混成復活／背包／保存全未實作。

## 最終一致性

根verifier重新執行四個只讀子分析、比對已保存收據及來源／原件／交付物hash，另檢查20功能、9優化、優先序計數、獨立覆核文件版本和Markdown連結。見[整包收據](verification-result.json)。這是分析可重現檢查，沒有藉此宣告目標程式執行或玩家驗收完成。

## 固定來源與導覽更新

發布前確認導覽頁會指向本輪新包，因此文檔證據改為從固定baseline Git物件核blob／bytes／SHA，不以後來可變導覽文字冒充舊來源。實際分析的scenario／schema／原生evidence與實際執行的Python helper仍保留工作樹與pin一致的檢查；原件身份也仍逐檔核對。這項調整讓文檔來源可重現，沒有放鬆實際資料或程式身份驗證。

## 最新main差異補核

發布前讀到main更新至7344eeb65198e2dd61684b66cf811021765ed8f5，root另釘5個相關文檔，結果分題再核4個完全復活／原入口來源。已採用較新已完成的離線串接，保留死亡懲罰、Scenario入口與v2缺口；未混成本輪執行。詳[最新來源補註](LATEST-MAIN-UPDATE.md)。
