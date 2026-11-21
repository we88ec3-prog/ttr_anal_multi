# 有限次入口房間編譯

2026-11-22，自有MEF／NOT_NATIVE_MEF，P0 E2的正常入口接入。
第一版以Case693既有入口房間為範本，固定1..16次，完成後接回原1→3→5/6→4→2
主線圖序與頭目，只在原終點結算一次；不是動態循環或任意新Case。

Server logical node與Client CHART key分開：可選node.chartNode僅在明確啟用
LOCAL_FINITE_ENTRY_REPEAT_V1_NOT_NATIVE_MEF的Case693一般入口接受。canonical7個
原節點與map／原有投影邊保留，額外節點只可為入口map3430／CHART key10的有限
單鏈，最後進原node10，後續維持原圖序；其他模式拒絕此欄位。沒有新game opcode。

編譯器讀固定SHA的來源scenario、AI及.repeat.json計畫，保留來源不覆寫。
每次訪問有唯一logical node與遭遇群；前N-1次使用命名空間旗標與AI複本，最後
一次保留原node10及旗標名稱，外部引用因而代表最後一次已完成，而非第一次。
所有signal producer／requiredFlags／watchedFlags／afterFlag／barrier／hazard／
AI attack條件都按同一scope轉換。wave／hazard／checkpoint識別屬單次node，可重用。
每次重進重新建立timer、怪物與點，player資源沿用現有normal adapter規則。

計畫明確選VisitLocal旗標與PerVisit既有節點獎勵／掉落／消耗政策；原完成經驗
仍只發一次，不能把增加房間說成沒有增加獎勵。所有展開後的節點、旗標、AI、
最大路線經驗仍通過現有typed／地形／來源驗證及上限。編譯清單記來源與輸出SHA、
訪問順序、logical↔chart對應及獎勵政策。保存／編譯不等於發布或Client實機。

同圖仍按0012、0049 key10、owner重建及完整0027偏序執行。前圖必要怪死亡／
移除已入輸出、投射物退休及地面物品移除分開處理；0010只清owner type0，
不能當成enemy1／bullet2／drop3全清。ContextCase只在安裝時送，不逐visit重裝。
同key的001C無generation token，遲到輸入的完整辨識不列已驗；非正流程維持待測。
原生依據與目前Ghidra／bulk有界核對另附證據；不更動原件或Client。

## 編譯與部署契約

計畫schema見 [local-finite-entry-repeat-plan.schema.json](local-finite-entry-repeat-plan.schema.json)。
固定3次計畫SHA為4ae70bc3ead178155129a019117fb0bc66d5d728e4fc626a52bc4b64bf311267；
來源是flag-delay版c0b22c…與原AI d4768b…。輸出scenario為7e6939f41df7ef7a18ad450f3b228463ade2c9794b9a79908838c637345c02b4，
AI為063ae7deaca4669d30cfb54518f0cec7853425d8ec3a16843c6a07e3f78c2327；
[編譯清單](phindos-stage462-case693-repeat3.repeat-compilation.json)列全部來源、訪問與經驗。
logical11→12→10皆map3430／chart10，每場路線由88增為96EXP（多兩次各4），原完成20只發一次。

Host需顯式TARTAROS_LOCAL_FINITE_ENTRY_REPEAT_MODE，再使用既有Case693 scenario path／SHA
與全域AI path／SHA；IncludeFiniteEntryRepeats僅選這組固定3次配套，與其他候選互斥。
CLI編譯輸出新目錄、不覆寫舊檔；工作台普通範本維持原圖序限制，本版沒有新增repeat按鈕。
將編譯稿另設為baseline時，既有工作台可在固定圖序／chart投影內編排，不自動發布。

## 原生依據與待測

見 [有界native審核](FINITE-ENTRY-REPEAT-NATIVE-REVIEW.md)及
[37筆來源／17個重核窗口](finite-entry-repeat-native-review.json)。0012同圖仍清point／controller；
0049 consumer可再次匹配合法key10，但Acquire／Release不代表整體無副作用冪等；
0010只清type0而非怪／掉落／子彈。新focused Ghidra查詢300秒逾時，復查無active分析程序、
無留存Evidence，未重啟／未列新Ghidra通過，已關閉metadata session，沿用固定raw／bulk核對。

指定v2 FR-01待驗：正常建隊進村選關，三次入口各拾取183並消耗開門、point重新可按；
同圖owner與怪物／掉落／子彈不殘留，第三次後接回原圖序，單次96EXP回原隊伍。
鏡頭、小地圖、控制／latch與畫面仍待人測；不把0014當完整Client快照ACK。
重送／late001C／重連／故障／邊界及壓測仍維持暫緩，不宣稱動態無限loop或持久續關。

## 正流程驗證

Release Host／Inspector／Admin.Web均零警告錯誤，HappyPath669/669。
15個focused正面案例中含4個新增案例，涵蓋2／3訪問、chart投影、機關重啟、
最後訪問才形成外部旗標、明確獎勵倍數與編譯來源不變／重現。
重新編譯三檔逐位元組相同；scenario／AI／plan Schema驗證通過。

兩條正式gateway元件loopback TCP路線均為11→12→10→1→3→5或6→4→2；
前三次Map3430／chart10，累積擊倒EXP為4／8／12，每次從正常拾取取得一個183
並有獨立node11／12／10消耗receipt。只有最後一次產生原entry-paid，無中途結算。
每路只一筆96EXP結果、存檔與原村莊隊伍返回；24枚子彈建立／清除，無跨visit殘留。
舊flag-delay配套兩路維持88EXP／14枚。正式Host獨立預檢確認entry logical11、
chart10、opt-in mode、兩來源SHA與96EXP；已關閉自己的預檢Host，未換目前服務。

初次檢查器仍把0049 chart key當logical node，已修正為同時核對實際Server只讀
node、原生chart及map三者；沒有略過遊戲handler或手動設旗標。詳見
[機器收據](finite-entry-repeat-validation.json)。原BIN與v2完整SHA在驗證後保持。
本輪不以新Ghidra查詢逾時、同程序元件TCP或工具數量宣稱原Client實機通過。

Compiler v2 fixes output to LF before hashing. Initial Windows CRLF working-copy hashes in8336965 were normalized by Git; the v2 pair/receipt supersedes those values. Original outputs/history remain; source plan is unchanged. Verify indexed Git blob bytes against raw artifact hashes before publication.

後續管理端整合見 [有限入口重訪工作台](FINITE-REPEAT-WORKBENCH.md)：從已保存版本預覽與匯出2～16次配套，CLI仍可使用。
