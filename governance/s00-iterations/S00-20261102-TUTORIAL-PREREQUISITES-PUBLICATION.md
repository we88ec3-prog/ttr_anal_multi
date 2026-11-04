# S00：明示opt-in的教學任務前置發布與CSquare控制器核對

接續[獨立保存候選](S00-20261102-TUTORIAL-PREREQUISITES-STORE.md)。
本輪加入提交後發布的adapter，但**目前執行中的v10仍未換版／未啟用，live DB未migration**。
Server重建政策不因此變成官方Quest算法；並未宣稱Quest15劇情或馮德斯村已可玩。

## Adapter與交易順序

新增明示設定`TARTAROS_LOCAL_TUTORIAL_PREREQUISITES_MODE`，唯一啟用值為
`LOCAL_WORKING_COPY_TUTORIAL_PREREQUISITES_CANDIDATE`；空值／OFF維持舊模式。
啟用必須同時使用已保存journey transfer候選；Host只verify新quest component，不自動初始化。

本connection正常Server勝利／返回、角色／裝備與10/12/13/14順序條件不變。
先保存同lease transfer，再呼叫獨立component的前置commit；回傳null就保留pending、不提前換場。
只有commit回傳的owner完整key集合能建6F snapshot，不拿Client自己上報的keys或partial delta組snapshot。

snapshot在普通廣場bootstrap的38/Town5及Map511之後、player重建／NPC生成之前送出。
C2S43仍只當既有init progress，不標為Client ready。這個發送時序是Server候選，須後續人工驗證。
獎勵entitlement仍PENDING_NATIVE_PUBLICATION；沒有發原生餘額／升級／技能或宣稱已付款。

## 實際正流程驗證

保留原來未啟用發布的所有正向案例，另加一條正常新帳號TCP旅程啟用發布。
接收端核對38、Map511之後是完整6F bytes `6f 00 00 40 01 00`，再正常player／NPC／移動停止。
獨立SQL核對owner revision2、keys14/16、來源settlement→transfer及原始type2/value50 pending權利。
新發布案例不在測試尾端再次呼叫commit冒充正常流程，來源即adapter的實際寫入。
共26個HappyPath通過，Host Release build零警告／錯誤；未執行暫緩測試。
沒有部署／live migration／Client操作，也不把合成6F接收當真遊戲Quest15已啟動。

## CSquare原始控制器核對

[唯讀檢核工具](../inspect_square_controller_init.py)及
[761-byte initializer、RTTI／vtable／8個assert](evidence/S00-20261102-SQUARE-CONTROLLER-INIT.json)。
KR BIN SHA仍為`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
原件RTTI確認C06FB0為CSquare，virtual+10指向4BBC10；原始bytes連續解碼至4BBF09，內部branch對齊。
4BBCC4設ESI=2，4BBD43與FBA7AC比較；相同種類走544F50 reset，不同時有548540建構路線。
4BBE86組43、4BBE94設末byte10、4BBEA6送4B；中間byte來自BL，保持opaque。

保存Ghidra有限來源：4B9090 SHA
`d31cab226005d9f6a81e85cf825638b4182f8ce16283b1c91c0262e534fde299`，
4BBC10 SHA `2e667eac98533d19bf480e4bf0cb98005a5ff812c999aeed45897d82759e8e78`。
4B9090的0x07／0x17／0x18分支可建立CSquare；不能因此直接認定Town1必走7或其正式wire順序。
這縮小普通村落的控制器候選，不是「沒有CTown RTTI，所以村落必是CSquare」的排除式證明。
helper語意、普通Town1入口、NPC／合法玩家spawn仍未全文驗收，沒有FULL-PASS提升。

## 未閉合項與資料表排除界線

本輪另唯讀看到_PortalList只有portal effect ID／state／file，沒有出生座標。
TownWorldListTable Town1有bindno100／visible／new，不能把UI／binding數值當map或spawn。
_PositionList為665筆宣告及數值列，未追consumer，不能取其中734/1106等數字直接當普通玩家位置。
這些探索未改資源，也沒有用未知表取代正常spawn證據。

下一步是NPC候選key及15/1之後狀態／場景接續，再普通村落的context／controller／spawn／NPC。
先做出有用整段才換版，不因本輪增加一個flag就要求玩家重跑教學。

補充資源均來自原始Table載體09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442；member SHA：

| member | SHA256 |
| --- | --- |
| Table/_PortalList.xml | 3140d4c0703181584de2dcab0a4a48c288cb21de887b692a2f584fc88639fa56 |
| Table/TownWorldListTable.xml | 4fd6bb23bed150da0e0b91ab8bf685e52c5090dd2728f6ee4378e2f587aec078 |
| Table/_PositionList.txt | 85515974c69306caef8dae1d0bb8552c11dd15f4327e5dcfa4a4742f67bcfbf9 |

只作精確資源範圍紀錄；上述表的完整native consumer與所有欄位語意未驗收。
