# 入場／清場演出取消返村

2026-11-24。Server 接線已實作並通過工程正流程；**指定 v2 畫面／輸入與原生執行驗收未完成**。
沿用[主線戰鬥取消](STORY-ABANDON-RETURN.md)的有效租約、單人隊長、revision提交與資產保存政策。
本批只擴充目前已安裝Scenario的 `EnterScene`／`ClearScene`；不是Intro／ReturnScene／Q15演出取消。

## 原生入口與候選順序

[先前界線](../../kr-extra-roy/SCENARIO-PRESENTATION-ABANDON-20261124/README.md)仍成立：
模式2的005D請求自身不先Stop，005F換場景／003F回報也不等於清理完成。
本批接到Scenario真正繼承的既有0038，而不是送Mission專屬0031：

1. `4C46F2→4ADD50`填共用表，`4ADF2D`將`[receiver+1C4]`寫成`4B1BF0`。
   `0038×8+4=1C4`；Scenario自身初始化從`+5EAC`以後開始，沒有覆掉此共用槽。
2. `4B1D07..4B1D0E`取Q manager `FB73C0`，呼`5624B0(0)`，然後`4B1D13`才讀subtype。
   subtype0經既有Town分支；`4B2050`從payload+3讀Town WORD並交既有Town預載。
3. 因此選用已存在的9-byte村莊context，例如Town1的`38 00 00 01 00 00 00 00 00`，
   讓當前正常ready Scenario先處理active-Q Stop，再預載已提交的目的村。
   **這不是Stop-only封包**，它會寫context／預載，不能使用任意subtype或偽造Town值。

[town-stop-source.json](../../kr-extra-roy/SCENARIO-PRESENTATION-ABANDON-20261124/town-stop-source.json)，SHA256
`ea1c0fcccd2c72b41437dbefb4961a511d6a46b9d4ee4a8f2a19dbe5b433e0c4`。
驗證器另存[verify_town_stop.py](../../kr-extra-roy/SCENARIO-PRESENTATION-ABANDON-20261124/verify_town_stop.py)。
原件仍為KR `9741d197…`；沿用凍結REA／Ghidra與原件PE映射，不執行遊戲或改資源。

## 提交、載入與回報

先依既有取消交易提交同一未完成任務的Npc狀態、revision+1，沒有ScenarioCompletion。
提交成功後，僅本批演出取消將**原本的同一份**村莊0038從0043之後的快照提前，
放在0069/7載入交接之前；0043確認後仍送村莊map／角色／背包／NPC快照，**不重送0038**。
保留既有0089隊伍清理與目標Town，沒有新opcode、selector、cancelACK、Client或schema變更。
Encounter／Portal取消仍用原順序，不因本批更動其正常流程。

Stop最後可能進入End；非零quest仍受原CheckConfirmMessage條件影響，不能保證必送003F。
工程路線另模擬一次可能的正常Stop回報，放在Town loading期間；該回報不推進任務，
載入後仍是同任務Npc，不發完成獎勵。這不是重送／重登套件，也不宣稱所有延遲回報均已驗完。
Native Stop的主要清理仍有Q active guard，Server phase不是Client已清理ACK；
相機／map／actor／輸入呈現需指定v2另驗。

## 正常驗證

|路線|取消點與結果|
|---|---|
|TCP入場演出|Q119 scene2，未戰鬥即取消；0擊倒EXP、183×3保留；同連線NPC重開到新Encounter|
|TCP清場演出|Q119末圖scene4，13怪已入帳52EXP保留；5,880返回結算（5,850任務＋10清場＋20完成）未發，零Q119完成列；重開成功|
|原控制TCP|Encounter／Portal取消仍分別保留0／8擊倒EXP，資產與同連線NPC重開通過|
|兩場獨立實際時計Host|分別在入場scene2與四圖戰鬥後清場scene4取消；各場Town0038在69前且只一份；可能的Stop報告後仍Npc，0完成獎勵；同連線NPC／選角重開成功|

Host在正常Stop交接後，合成Client只退休當前已取消的那一筆scene，再等待新NPC scene；
這是驅動器的場景佇列，不是操作遊戲、修改Client或聲稱原生畫面清理成功。
停止Host後以DB／日誌副本讀回：各183×3、分別累積39,000／39,052EXP、零Q119完成獎勵，
同連線重開已保存QuestIndex2／Encounter。清場Host走`632→633→634→635`，保存完整同圖重建清單；
只在比較房間路線時收合相鄰同Map的重建，不刪原紀錄或當作少一次世代安裝。
原DB／日誌及seed SHA保持；重用已有冷讀副本時另核來源／副本SHA。
三Release零警告／錯誤、814HappyPath零失敗／略過，包含兩個新演出取消domain正流程。

收據：[story-presentation-abandon-20261124.receipt.json](../testing/story-presentation-abandon-20261124.receipt.json)，SHA256
`05144a7ca1a6de2608cb8ac284286cb968462f49f03c3622a814cd29fdce7199`。
初版工具的nullable／不存在scene診斷欄位、誤套另一配套的56擊倒預期、Host raw quest無Town欄位與舊scene佇列
各有修正與保留失敗資料；最終採實際0047、正式已提交Town及單一取消scene退休。工具修正不改Server接線。
兩條演出TCP原場次完成後只重做52EXP稽核，沒有為修正稽核重走戰鬥。
清場Host工具另修正重複前置與未等正式scene4派送的假設；沿原5秒報告等待觀察勝利／演出就緒，
沒有縮短Server清場或改時鐘。原入場專用收據另存保留，最終收據新增清場場次。

工程帳號已準備教學／Q15／Lv15與183×3，不算自然新帳號或新掉落驗收。
入場／清場各有獨立Host；Intro／ReturnScene／Q15演出及人工v2各自待補。
現用服務未換版，Client原件保持，延後套件與其它MEF缺口未因此提高，整體目標仍開啟。
