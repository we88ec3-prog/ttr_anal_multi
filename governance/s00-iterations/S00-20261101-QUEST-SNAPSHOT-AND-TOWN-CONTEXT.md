# S00：已完成任務snapshot、城鎮context與結算缺口

本輪接續新帳號完成教學→廣場的完整目標；v7結果卡保持有效，沒有再換版或操作Client。
Server目前只有首戰完成與角色取得的保存，沒有完整Quest14/16狀態或terminal tutorial保存。
本輪沒有把這個缺口用無條件completed bitmap遮蓋，先修正一個可獨立核對的城鎮初始化遺漏。

## 原資源：14→16→15依賴，不代表三者都完成

原始Table備份SHA `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`；
QuestInfo member SHA `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`。
選查記錄：

| Quest | 資源欄位 | 可用界線 |
| --- | --- | --- |
| 14 | type3、Town0、field18、giver/finisher10027；AcceptAction/CompleteAction type1 | field18不是物理Map18；目前scenario14勝利紀錄不是完整Quest14結算證書 |
| 16 | type2、Town0、Demand14、無field、giver/finisher10027；Reward type2/value50 | type2獎勵的意義／授予時機仍未由本輪確認，不直接稱金幣或EXP |
| 15 | type2、Town5、field19、Demand16、giver/finisher10338 | 廣場後續，非本輪教學出口前置，15/1開場不能當完成 |

這些欄位沒有指定一個新的官方教學terminal ACK。既有3F/1000/14也有載入失敗producer及
Lua清理／額外yield界線；不能因有序回報、NPC出現或玩家輸入就稱已找到官方Quest16結算。

## 006F是整份bitmap snapshot，不是任務ID列表

原始KR SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
沿既存REA/Ghidra保存結果及原件限定指令核對：

- `5020B0` 把 `502170` 放入FAB61C，`4FDA30`按object[opcode*2+1]分派；
  base FAB2A0的該槽對應006F。FAB5C4→5030C0對應0064，不能沿舊註解叫004C。
- `502170`先清目標向量，再在(L−2)為4的倍數條件下交`44AB70`複製DWORD，
  經`44AA10`逐word／bit轉為WORD任務ID。`44AA10`的值為wordIndex×32+bitIndex，
  存入16-bit元素；這是接收布局，並非授權Server把任何bit設1。
- 因接收會清舊向量，006F不能當只加14/16的delta。後續Server必須從該帳號權威資料
  組出完整已完成集合；不能讓一次局部回覆抹去別的已完成任務。
- `5030C0`讀payload+4 DWORD status並發本機UI事件，status0走清活動槽／重算等路徑；
  本輪沒有發現它可取代完整completed snapshot，也未恢復所有結算／獎勵操作。

說明用合成例：若權威集合**恰好**只有14/16，word0=(1<<14)|(1<<16)=0x14000，
候選payload是`6f 00 00 40 01 00`，不是把14、16排成兩個WORD。
此例僅為有明確標籤的說明資料，沒有向遊戲發送、沒有寫DB或宣稱官方captured traffic。

偽碼SHA：502170=`95841d2c0fdb71da09acf11ef1e2c39558ba90e09ef93813293d1b262fc39643`；
44AB70=`19c5ded3051f4ce7fe253d89342dee1b09845ddc49f9786c5e43fb0b545e6731`；
44AA10=`8bc1d005c785de19bbd1b290a7324bfd626fb14c7e09340ea2baf207410610a4`；
5030C0=`44ae4491b32cddda76d21f313b8d60579b65ad2003c34ed2aa11f275fbd25101`。
大型QuestMgr所有狀態、錯誤、UI與結算依賴未全文驗收，不作FULL-PASS。

## 可獨立修正：廣場缺少Town context

既存`4B1BF0` SHA `71e5ecefd45143f0c32bce1c4ae3e20784c6a4db5af44d22fec7d95ba3462065`
在38/type0支路更新城鎮資料，`4B2094`讀payload+3 WORD，`4B2098`寫FAB1BC，
之後以該Town交QuestMgr500240重算。500240的有限偽碼會依town及完成依賴篩選，
所以物理map511／NPC actor不能代替Town5業務context。
舊交接把4B208D標成town store不精確：該位址是singleton flag test，實際store在4B2098。
本輪檢查器已從函式入口的有效指令流核對正確兩條指令，不用錯位線性視窗判義。

候選source改為43進度後送38/type0/Town5，再發map511及既有reset／重建／NPC／綁定。
body9B、未知尾欄0是沿已使用布局的Server候選，Town5→map511仍不是官方對應證書。
它不發006F、不發0064，不改任何Quest完成或獎勵。

38/type0也呼叫552FC0；其有限支路按+3查字串、處理`.dds`並建立CFadeObject。
這是loading呈現的具體候選線索，**不是已證恢復完整載入畫面**、不是接收MEF、也不證
render在同步載圖前已畫出一幀。本輪沒有加固定延遲或修改Client來造轉場。

## 保存與驗收規劃

後續持久化需分開保存：Server判定的首戰結果、角色取得、教學流程milestone、Quest14/16
合法達成／結算與獎勵、terminal tutorial狀態。每項寫入須在同帳號當前lease交易中核對，
完成時間／來源與規則版本可追溯，再送完整snapshot。不能把milestone欄位直接改名為completed。
尚缺Quest14/16合法達成與結算鏈時，先保留缺口；單靠新增資料表不能解決語意不足。
現有first_battle_completed_at保持原義，不自動遷成Quest14/16完成。

本輪只接Town context source修正；沒有schema migration、006F sender或terminal persistence實作。
v7仍為原已部署版本，新修正準備供下一個有用批次，不中斷當前卡。
16個HappyPath cases通過，既有正常TCP／SQLite新帳號列新增檢查38/Town5位於map／重建之前，
再正常驗證NPC／移動停止。208方法／10正向／198待測不變；不是Client畫面／任務完成驗收。

`inspect_tutorial_exit_sources.py --quest-context --original-table ...`新增原資源metadata與
[8個限定指令視窗](evidence/S00-20261101-QUEST-SNAPSHOT-AND-TOWN-CONTEXT.json)。
QuestInfo展開2.5MB，超過舊工具1MB預設；僅該釘SHA資料以明確3MB上限解碼，其他caller
仍預設1MB，沒有把工具上限誤稱成資源錯誤或全局無界解壓。
錯序／重播、snapshot覆蓋、跨帳號、結算重複／中斷、過期lease、migration／恢復、併發、
安全及負載都記待測，不在本輪執行。REQ-0016/0017及完整goal未結案；formal admission、
normative pin、Task owner與APPROVED狀態不變。
