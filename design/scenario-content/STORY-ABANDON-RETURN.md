# 主線放棄後返村與重開

2026-11-24再接續：[入場／清場演出取消](STORY-PRESENTATION-ABANDON.md)已補合法共用Town0038先Stop再載入。
兩新演出TCP＋原兩控制、獨立入場／清場兩Host與814HappyPath通過，52擊倒EXP保留／零未完獎勵。
舊段「尚未擴開」為前一分析快照；Intro／ReturnScene／Q15演出及人工v2仍未升格。

2026-11-24接續：[演出期間取消的原生清理界線](../../kr-extra-roy/SCENARIO-PRESENTATION-ABANDON-20261124/README.md)
已確認kind2送005D前不經同函式Stop支線；單純換field亦不是qco清理保證。
本文件Encounter／Portal成果保持，未據此擴開Intro／EnterScene／ClearScene／ReturnScene取消。

2026-11-24追加：[Q15未到村取消回廣場](QUEST15-ABANDON-RETURN.md)已另行實作及工程驗證。
下文原Q15待辦保留為本批一般主線完成時的範圍；原生倒地輸入與播放中演出仍未閉合。

2026-11-24。SERVER_DESIGN_CHOICE／NOT_NATIVE_MEF。承接
[模式2放棄確認來源](../../kr-extra-roy/SCENARIO-ABANDON-REQUEST-20261124/README.md)，
將已收到的既有`5D 00 00`接到一般主線的取消交易。這不是指定v2倒地按鍵／畫面驗收。

## 執行與保存政策

目前支援一般主線的Encounter與Portal階段，包含角色倒地的Encounter；必須已載入、
不是debug流程，且沒有待提交的主線轉換。依目前遊戲租約授權，若有房間須為唯一隊員兼owner。
沒有房間的合法主線也能取消。播放中的演出、結果頁、Q15首次進村橋接各自維持既有政策，
不由本批打開任意取消，也不把仍pending時的點擊排成另一筆故事事件。

取消先規劃同一QuestIndex／角色、Npc phase、node／scene歸零、任務所屬村莊及revision+1。
既有擊倒EXP先沿原提交路徑入帳。取消checkpoint經原SQLite lease／revision驗證成功後，
才發布世界變更與清除隊伍；讀取資產亦先於本次提交，沿既有返村初始化發布。
此snapshot不帶ScenarioCompletion，不領未完成的固定／清場／通關獎勵或熟練度。
沒有新增資料表、wire欄位、opcode或Client修改。

提交後清除本場scenario及未提交的場內清場累計，地面未領物件移除、投射物視覺結束、
當前輸入釋放；重用普通村莊初始化與已保存資產／NPC／任務條件快照。
隊伍政策與普通副本離隊一致：既有房間在成功後離開，送`0089/00`清理，再回任務所屬村莊。
這是Server政策，不宣稱原服必然返回同一位置；首次Q15到村的自動私密一人隊規則保持。
同一連線可再找NPC，重新編隊建立新的scenario／訪次，不需登出或重登。

## 正常驗證

準備教學／Q15進度，正常登入、廣場建隊、進村、自然對話完成Q117／Q118前置並開始Q119。
原版BND、原主線14773c31、循環候選ca070796及EXP policy60ca18e6，未修改原內容。
背包預備183×3經既有庫存claim服務提交，明示fixture，不冒充本次自然掉落／商店購買。

兩條loopback TCP路線分別在Encounter（未擊殺）及Portal（已取得8EXP）送005D/00。
兩路均保存同一未完成Q119的Npc游標、通關獎勵列0、資產一致、離隊清理與實際Town1/Map182，
同一登入連線再對話／編隊，回到新的第一圖Encounter及不同訪次GUID。
另有獨立原版BND／實際時計Host從正常入口完成相同取消與NPC重開；SQLite保存39008EXP、
183×3及未完成Q119，固定／通關獎勵列0。Host已停止、種子DB雜湊保持，現用服務未換版。

兩個route正流程單元測試驗Encounter／Portal的待提交隔離、同QuestIndex、零完成標記與重新建場；
原倒地／復活測試保留，另加倒地取消後可用村莊的分支。
Host／Inspect／Admin三Release零警告錯誤，807HappyPath零失敗略過。
初輪Encounter檢查器誤設必有持久化EXP列，已改用既有policy初始值；初輪Host工具漏收poll清理封包，
已改統一蒐集。兩種失敗紀錄、806／807原TRX、空背包與加強非空背包收據均保留，沒有修改玩法配合誤判。
非空SQL讀取工具亦修正tuple與JSON list的比對型別，保存取消時讀回資料後再斷言；沒有改Runtime。
完整[工程收據](../testing/story-abandon-20261124.receipt.json) SHA256
`f9940b451eca3dad3ad547f07a4f8b14d30a72bd2ca2e34325c4e7b0937be282`。

Q15取消／首次進村資格、演出中斷、原生倒地按鈕可達性與owner+5ED8型別仍各自待完成。
本批不跑重送／重登／故障／併發／安全／壓測，也不把同連線重新接未完成任務當作這些延後套件。
原生MEF、自然新帳號全程與指定v2人工狀態不因工程通過提升。
