# 階段頭目與掉落的同版完整副本

2026-11-23開始、2026-11-24接續驗證。SERVER_DESIGN_CHOICE／**NOT_NATIVE_MEF**。
本批把已完成的[旗標階段招式](MONSTER-ATTACK-FLAGS.md)與[掉落編排版本](GROUND-LOOT-WORKBENCH.md)
整合成一份選定配套，再補獨立Host的實際時計出招驗證；沒有重新宣稱已存在的階段引擎為新實作。

## 選定內容

[完整關卡檔](phindos-stage462-case693-phase-loot.scenario.json) SHA256
`3f4891d41c4aa362876b2a17a6331a91d6ff79aca762879eabf87410d812ac68`，搭配既有
[階段AI](integrated-attack-flags.monster-behavior.json) SHA256
`d4768b72eebab11ec675a5e5f4fc4116cb41d566f7b41caad5ab04c4f6b0a3e4`。
它以掉落r3（`dcdb787a…`）為底，只把boss-arrival的1086綁定`integrated-phase-boss-v1`；
其他模型、出生、地圖、來源、波次、開關、分支、掉落與88EXP政策保持。沒有把各個不同候選默認成同時啟用。
配對AI的原共用profile逐筆與原AI相等；額外的integrated-projectile-v1未被本配置引用，不能把它算成已採用玩法。

正常入口是廣場建立一人隊→同隊進馮德斯村→Stage462選關→Case693六圖戰鬥→結果回Map182原隊伍。
Case由Server既有選擇／輪替決定，Client不是另選Case按鈕；本驗證隔離帳號首場核對為Case693，其他輪替Case未被此配套覆蓋。
兩路分別為node `10→1→3→5→4→2`及`10→1→3→6→4→2`。
一般入場等級與隊伍資格沿原服務；工程帳號已準備教學／Q15及索瑪Lv15，不算自然新帳號升級驗收。

|部分|同版設定|
|---|---|
|入口與消耗機關|初始1004掉Product183×2；正常拾取後key11支付1件才通行|
|第二圖掉落|兩隻初始1022各2件，原指定增援1022另1件；來源互不重疊|
|分支|原開關、清場與出口資格保持；選擇key3或key6走對應岔路|
|必要頭目|node2，boss-arrival的1086/PRE1，最大120HP；原具名身分及延後登場保持|
|第一階段|boss-phase-two尚未成立，可選phase-one-shot：5傷害、1.2秒個別冷卻|
|第二階段|實際頭目血量達75%設boss-phase-two，召喚原兩名護衛，並改選phase-two-shot：7傷害、0.8秒個別冷卻|
|共同招式呈現|既有動作101與Type43投射物；起手0.2秒、恢復0.5秒，沿原發射／碰撞／退休流程|
|結算|整場88EXP、一次完成結算；五筆掉落共8件，付款1件，空起始背包最後183×7|

階段只改可選招式，沒有換怪、重設HP／冷卻、改模型、替換profile或直接設旗標。
已起手攻擊仍依原時序完成。數值是既有Server候選設定，不是官方AI或平衡復原。

## 驗證與證據界線

標準工作台正常HTTP保存並匯出同版scenario／AI／manifest ZIP，原始檔與解壓後bytes相同，隔離Admin停止。
來源版兩TCP、實際保存版兩TCP與舊階段版兩TCP，共六條正常路線，各88EXP保存與原村原隊伍返回。
各路均觀察同一活頭目的兩個實際AttackId，階段前HP>90、階段後HP<=90，投射物建立／移除守恆。
新來源／保存版各8枚，舊階段控制各13枚；未宣稱兩個不同內容的投射物數必須相同。
新版本每場五筆掉落，舊階段控制仍三筆，沒有把新掉落量誤套舊配套。

保存版另以兩場獨立完整Host走兩條岔路，使用實際時計與正常socket輸入。
驅動器在頭目可攻擊時先停止玩家連打，觀察其正常出招，再繼續普攻到75%旗標，觀察第二階段後續戰。
不調時間、血量、旗標或AI，也不經診斷接口注入操作。每筆階段觀察立即落檔。
兩份收據均核對同一entity／1086／boss-arrival、頭目仍ACTIVE、全組未清除、實際000D動作101回包及
唯讀ActiveAttackId／HP／旗標；完整六圖後SQLite183×7、經驗39088、一次結算、原村原隊伍與投射物退休再核對。
兩場實際觀察皆為entity513、第一階段120HP、第二階段80HP；正常TCP的各路頭目起手為第一階段3次、第二階段5次。

000D兩階段都使用動作101，回包本身沒有AttackId；階段身分來自同時的Server診斷，不把相同動作封包當作新階段opcode。
這也不是Client動畫／命中特效ACK或原生MEF自主AI證據。

三Release零警告／錯誤、799 HappyPath零失敗／略過，四Python UTF-8語法通過。
收據：[boss-phase-loot-20261123.receipt.json](../testing/boss-phase-loot-20261123.receipt.json)。
資料夾沿用11月23日啟動批次名稱；文件記錄跨日，不改寫歷史時間。

首場驅動器在最後稽核把Python整數Product鍵當JSON字串鍵比較而失敗，原Host已按既有finally停止；
其DB已存183×7，失敗資料與舊驅動器保留。修正只涉及稽核鍵型別與立即保存觀察，不改Server或配套。
階段快照與完整通關證據只採修正後的新場，不把首場缺失的收據補標通過。

原件／種子DB／Client與現用服務保持，隔離服務全停止。指定v2的操作／演出、自然新帳號、
上批UI-DROP-01及其他MEF／延後套件未因此提高。配套部署沿用[普通狩獵場配套部署](NORMAL-HUNTING-BUNDLE-DEPLOYMENT.md)，
不自動換版目前服務。
