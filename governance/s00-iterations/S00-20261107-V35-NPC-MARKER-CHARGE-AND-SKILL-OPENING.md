# v35：主線標記、施放後退階及全角色技能接續

## 人測回報與需求來源

使用者回覆v34：可進村、移動正常，但NPC沒有主線任務標記。有限通過只涵蓋Town2進場與移動，Q133互動及後續主線未通過。此回報補入REQ-0021的GAME_RUNTIME_OBSERVATION，不把「沒有標記」改寫成已按Z失敗或Server拒絕。
另明確要求測試期間繼續開放所有角色技能，並說明技能施放後會解除蓄力；後兩項記PLAYER_ADMIN_REQUEST，不冒稱原生執行證明。
Client仍為v7工作副本SHA256 `937486b989d0a1adcddd86f5224011f8b22907c61dd30c3772ad4179891299ec`，Server v34來源`13bffdc967956140de1f1155e5221a88e31990de`。

## NPC標記：測試進度缺角色數值門檻

實際Server trace在Story133指定後發布Town2／Map183，完整6F鍵包含132及既有前綴；當前phaseNpc、giver10053，並非未套用進度指定。角色5C當時未在出站白名單，不能稱已在wire trace讀到等級；固定Isilia2／其他5的兩次發布來自v34實作核對。
[限定原生來源](../client-variants/20261107-town2-npc-marker/README.md)確認：500240取所有有效roleRecord+8的signed最大值，QuestInfo的level若較大就排除候選；Q133 raw level10。Town、Demand132、排除列表及giver等仍需成立。
候選經500A00／500A80→CNPC4D2360建立主線附屬標記；mode、actor+36C及效果可見性另列門檻，不能宣稱單改level必然修好所有標記。

Server修正只限明示進度指定：同一Rebuild的兩次5C都使用max(原測試等級,當前任務需求)，再發布6F。當次顯示等級同步列在測試診斷與頁面；不寫正式角色等級、EXP或修改QuestInfo/Client。正常主線仍需合法EXP／等級政策，不能用此測試供應冒充完成。固定35B的5C加入既有小型遊戲出站診斷，不擴收帳密／角色名稱封包。

## 技能施放後解除蓄力

依使用者要求，成功進階技能保留當次配置直至動作完成，隨後回基礎、保留角色／matrix／learned level／資源與active-ID冷卻deadline。只發布基礎技能組與parameter4=0，新增可用項用增量；不發全表CD reset。
舊進階鍵緩衝清除，避免同一mask退階後變成另一技能。失敗Start不設退階旗、不扣費或新增移動鎖。短V、長V、Tab本身不觸發技能消耗退階。此為隔離測試場候選政策，尚非原生蓄力state reset鏈已閉合。
初次測試用檔名篩選而未選到案例，不算通過；其後修正名義片長取整的測試邊界。正式整批驗證結果另補。

## 全角色技能：新增2項，剩餘87項仍在開發

[技能資料](../client-variants/20261107-all-skills-unlock/README.md)重讀98個指定原／工作member相符。Soma active1287／Practice14的146/147/148，以及Pipa active1289／Practice30的145/146/147，除ASD Header ID/NAME外完整動畫、效果、聲音結構與ABF片長相同。
各取最低motion作明示單動作預覽，不順播三次、不推定官方phase選擇。每項覆蓋7個matrix位置，共新增14個可測slot；總計156個distinct動畫候選、792／945slots，仍非156個完整技能。
索瑪此項LV1需600MP，測試選1000上限；蘋果需80SP／300MP。施放後按上述新規則退回基礎。

剩餘87：72項新配置缺對應動作、13項既有命名無明確橋、2項多Basis內容不同。不能把多Basis直接順播、把同鍵替換當動畫繼承，或把不明active硬套基礎動作。命中／傷害、投射物、目標、持續與特性script level仍各自保留缺口；空場動畫可用不等於戰鬥技能完成。
全角色開放工作未完成，不以本批兩項新增結案。後續按每角色／ID清單續查，已完成資料可立即供下一批使用。

## 工程檢核

最終93項Category=HappyPath全數通過約1分鐘，0失敗／略過。包含7個主線書籤兩次5C需達任務門檻且先於6F、各角色進階配置的動作完成後退階、兩個等價單動作的耗量／不重播，以及既有TCP／保存／操控／冷卻流程。
中間一輪92通過、1失敗是舊的matrix0可測數斷言仍119，而新內容為121；更新該覆蓋斷言後整批重跑，不將前一輪當全綠。
沒有執行Client、重演負流程或改正式角色數值。NPC標記與技能退階實機仍PENDING，部署回執另補。
先前使用者影片連結已列入剩餘清單，標示USER_SUPPLIED_NOT_REVIEWED；本輪網頁抓取5個連結皆cache miss，未據此補動畫或宣稱已看影片。

## v35部署

私有main `f49721abae5087855034774528675b182797357c`，2026-11-07台灣22:25啟用，PID8280。
核對舊v34 PID39276與exact路徑後一次換版，隔離SQLite先一致性備份；story內容SHA14773c…f50c、泳池與外部AI／場景設定保持。
Host DLL SHA256 `187fcbf5103af3cd027e1310075d154e474879be3e7b7595927a2456e7eee65d`；Network `c034102dbc2a9daa95da7e99ea05968d267d6307b260c8f85f0cd0c8918518d2`。
獨立重查Host存活及auth／journey／story皆健康。Client維持v7，不啟動／操作遊戲。
新短卡先測Q133主線標記／第一劇情，再測伊希莉亞進階X、索瑪及蘋果進階X+C退階；結果PENDING。
