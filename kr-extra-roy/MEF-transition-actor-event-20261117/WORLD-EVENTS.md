# 三：普通世界結果的原生接收者、保存欄位與 Lua 缺邊

本題沿真正world事件producer追加BIN-first，不把教學progress、Q物件停止、圖片生命期或Server內部通關狀態當成普通Lua完成事件。**本輪閉合了新的原生資料鏈，但仍未找到普通死亡／清組結果到Lua的完整入口。**

## 1. 舊證據直接復用

000C按u16 EntityId找到actor FSM，state3為CDeadState；重複enter會重設死亡表現，fade不等於world erase。001A是移除且部分情況先清控制槽；它不自動代表死亡、擊殺或群組完成。local CreateObjectEx沒有可靠Lua ID回傳；0007 duplicate hit不是採用／對帳。以上不在本輪重新冒稱發現。

新增問題：普通Scenario收到帶兩個world ID的結果row後，還把它寫到哪裡？是否有可呼叫的原生reader，而不是僅看到傷害文字？

## 2. S2C000E的普通field實際分派

原件`4ADDEA`寫common table `[field+74]=436C40`，opcode=(74-4)/8=0E。`436C40`只有`mov eax,[ecx]; jmp [eax+28]`。

| 真實field | vtable+28 | 路徑 |
|---|---|---|
| CMissionField | C0705C+28→4B0640 | 共通結果handler |
| CScenarioField | C073B4+28→4C4920 | 先4B0640，返回0才追加CAIControl處理 |

RTTI／vtable及完整Scenario wrapper均保存在native-evidence。本輪只對4B0640的身分查找前綴作逐指令分析，沒有宣稱整份傷害／效果分派或HP演算法全部閉合。

4B0640前綴先查本地relationKey=F93930是否存在FAB148；再按13-byte row取得source u16、target u16，分別查FAB138。missing指標走診斷／跳過。row+4是raw type；其餘8 bytes本題不猜業務欄位，也不能逕自命名為生命週期／群組ID。

## 3. 正向新鏈：world pair→CAIControl保存→原生reader

```text
000E
 → current ordinary field v+28
 → Scenario 4C4920 → common result處理正常返回0
 → row kind 0/2/3，source/target WORD
 → ESI=FB7A28，54A8F0
 → CAIControl三槽記錄的target欄位
 → 54AA60按選定記錄取ID→FAB138查同一world actor
 → 原生caller使用actor pointer
```

4C4920暫存controller三個slot pointer於FB7A7C/78/80，處理row後清FB7A78..88。`548DA0`明確建owner `FB7A28`、vptr `C0FB70`；RTTI為`CAIControl`。這不是Tutorial owner FC0F84，也不是Q actor tree。

`54A8F0`在owner+A8起，stride0x10走三筆，找source及target是否屬其槽：

- source屬於槽時，在選定leader/mode等條件下更新owner+B0/C0/D0的target值。
- source不屬槽、target屬槽時，查source world actor，要求ID低byte0/1、`4C96B0`predicate成立、current state有效且state+34為0。之後寫對應slot的+0C；若+08為0也補寫+08。
- 這是可重寫的單一目標欄位，不是按死亡事件append的可靠事件queue。沒有序號、group或instance payload。

`4C96B0`實際讀current leader與actor各自+90，轉到W中的關係資料，呼4C6F60並與0x12比較；缺可用leader返回false，部分缺relation資料的路徑返回true。**不能將這個predicate改名為IsAlive或group-clear。** 本輪不重新為0x12賦予未證業務enum。

原生reader `54AA60`：依模式挑三槽記錄，再按參數選record+0／+8／+C的ID；零返回空，非零進world lookup，取node+10 actor pointer。reader的switch五個target保留為data，不將跳表解成指令。兩個直接caller 549686／549C94已核實際call及返回pointer使用，但其完整動作決策不在本輪重作。

另一個54A8F0直接caller436C1B也已讀完整wrapper436B70；它同樣先處理共通結果、篩type0/2/3、傳同一owner。其上游場景安裝未重新閉合，不把它加成第三種已證普通battle情境。

## 4. 為什麼有reader仍不能算Lua結果介面？

此reader返回原生actor pointer，沒有Lua TValue入棧、ID/lifetime/event payload或已證正常registered binding。與上一輪122個同型registrar／121個正式名稱的固定表比對，54A8F0、54AA60、4C96B0、501650均不是其中的直接native target。

這個比對只排除「它們本身已在該有限表被直接註冊」；不能排除包裝函式、計算式間接呼叫、外部模組或後續Lua修改。真正缺邊仍是**同一typed owner的結果如何由合法binding／callback被Lua取得**，而不是以無命中宣稱全Client不可能。

也不能藉raw pointer、Rebind或猜控制器index繞過這條證據缺口。本題沒有寫入記憶體、patch或執行Client。

## 5. 另查一條會回Server的路：000D→00DF，不是死亡回呼

選定的普通skill使用路線4B01C0，在world actor+9C等於本地relationKey、action WORD==0x12時，呼`501650(10)`。其上游為既有000D，不是000C死亡分支。

501650走metadata中的stride24記錄：type==11、event等於輸入、signed current<required才選record+0x14的WORD。**最後一筆符合者覆寫前值，即使其selector為0；最後結果0就不送。** 適用send guard下組6-byte C2S：`u16 00DF | u16 selected-record-key | u16 event-code`。

這是既有條件式原生意圖；沒有source/target EntityId、lifetime、group或Lua函式名。它證明部分原生事件可向Server報告，不證明Server能任意推Lua事件，也不能當成group-clear ACK。00DF其他caller未作全類型語義分類；本輪不據此重做任務系統。

## 6. 精確阻塞與下一個證據入口

| 邊 | 狀態 | 下一個解除證據 |
|---|---|---|
| world結果row→同型native owner保存 | 本輪閉合所選Scenario鏈 | 已有原件，不再重掃 |
| native保存→world actor reader | 本輪閉合54AA60選定完整body | 已有原件，不再用GetObjectCount猜 |
| owner/reader→Lua typed結果 | 未閉合 | 某正常binding或實際callback的producer，證明傳入同worldID及來源事件；不能只憑相同offset |
| 單次死亡→可靠group/lifetime | 未閉合Client觀察；Server可先實作 | 按同一實體生命期去重、群組成員與終止原因的權威契約；若要本地觀察須接到真正writer |
| 普通場景不接管輸入的首次腳本入口 | 沿用B阻塞 | 取得新而未排除的caller與正常page/context，不用004E／OnEndTalk舊候選重跑 |

下一輪僅當找到「註冊target或其已定型callee讀同一CAIControl／world事件資料」的新候選時才擴查這條路；否則保留這個有界阻塞，優先交付Server權威結果→既有有限內容觸發的整合規格。前者是Client待逆向，後者是Server待開發，不混為完成。
