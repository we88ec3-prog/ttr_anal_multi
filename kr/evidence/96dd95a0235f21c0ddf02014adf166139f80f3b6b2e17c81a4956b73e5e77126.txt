# T01整合後增量：Quest15第二段與自由編隊

roy，待整合。原BIN SHA256：9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；既有REA6.5.0／Ghidra12.1.4 bulk，Python3.10.6／Capstone5.0.7核對原檔。未執行client、Lua或目標API。T14/T02/T08必要跨查由使用者本輪明確授權，舊暫停記錄保留但不再阻止此範圍。不是整份函式完備審核。

## 新確認的原生入口

**S2C0047可明確指定quest／scene**。5020B0初始化QuestMgr callback table，以FAB2A4為第0槽、stride8；FAB4DC寫503040，因此索引為47。原件50210B的mov bytes另已核對。503040讀message+2、+4兩個signed16，呼叫561760(quest,scene)。有效讀取下限6bytes，不含外層framing。Quest15/2可以表示為body `47 00 0f 00 02 00`；這是合法入口的參數化範例，不等於官方後端序列已取得。

先前0045／5027D0依Quest定義+54/+58的CompleteAction type/value，並不讀message+4當scene。Quest15原始定義沒有AcceptAction／CompleteAction，因此不能用`45,15,2`代替0047，亦不能用0040同步接取狀態期待自動播第二段。v8的3C分支仍有送45/15/1及錯誤註解，應在下一隔離版本移除；本輪沒有改現用v8。

561760前置：劇情manager+28必須0（沒有目前正在播放的劇情），否則只到錯誤路徑，不作排隊承諾；正常接受時記+38=quest、+3C=scene，+28=1，再依SceneList選資源。Quest15非零，會避開只適用quest0的額外條件，但仍需有效SceneList條目與資源。兩段對話不能同時預送；第一段需到正常終止點再啟第二段。

**C2S003F是劇情確認回報，並不表示任務完成。** qbase.RevPhase1先恢復UI／render，yield，EnableInput，再EndCutScene。565FC0把Q.EndCutScene接到561DB0（568A90 bridge）。普通+89=0路徑，當+28非0時先設+28=0；quest非零時呼叫CheckConfirmMessage，只有返回1才走4A39A0。4A39A0組8bytes：WORD3F、WORDquest、WORDscene、WORD1；FBA798==0才sender。其後才removeAllCoroutines、UI清理／還原與清+38/+3C。取消或非正常路徑不能憑沒有3F便捏造成功；本函式不送status0作失敗ACK。另一+89路徑行為不同，不泛化此成功回報到所有過場。

3F發送callsite早於EndCutScene全部清理完畢，不能把收到3F當作任意時刻所有UI均已消失；後續入站仍須依現有dispatcher／UI生命週期執行。不新增猜測ACK，不用固定sleep冒充原生規則。Server可按正確quest/scene/flag與自己的階段去重；不因重複3F重播或多次獎勵。

## 0050、004E、0028編隊介面

| 方向／欄位 | 原生資料流 | 確認界限 |
|---|---|---|
|S2C0050 WORD+2|4B3600把message DWORD0複製到FE18F8+0C，因此WORD+2到manager+0E；5082B0枚舉角色1..9，bit(id-1)表示可用|不能把它叫固定leader或QuestID|
|WORD+4|4B3600→manager+10；5083A0在尾部角色向量後加入此mask中的1..9|這是預先加入出戰集合；不是可用集合|
|BYTE+6|4B3600→manager+12→6BC850窗口+D8；6BC1A0在count>=D8時拒絕加入|容量有直接consumer，不只由畫面猜測|
|+7起WORD[]|count=floor((length-7)/2)；清manager+14向量後逐項u16→u32加入；5083A0先複製它|要空白隊伍，mask=0以外還必須清尾向量；7bytes無尾項會清掉前次預選|
|S2C004E WORD+2|4B3570→manager+8，排F43DA；正常Square UI 5B7F80→5B96E0→視窗helper596E00與F4358|0050寫資料本身沒有開窗；4E的ID是後續0028回傳值，不能將QuestID/FieldID/MapID混用|
|C2S0028|6BBFD0僅在確認事件、選取count非0時組包：WORD28、WORD(manager+8)、9個角色BYTE槽，共13bytes；先排F4356，再sender|取消按鈕只關UI不送0028；Server應驗合法角色、唯一性、數量與所屬階段，不能沿用第一戰固定leader4|

6BC850先清前次選取向量，5083A0結果為空時不進6BC1A0加入迴圈；+E0強制角色數也設0。6BC330確認按鈕啟用條件為當前選取向量非空。這支持先顯示空隊伍，玩家選至少一人後才可確認。窗口內部刷新有未完全復原的暫存變數／UI virtual呼叫，不能宣稱每個槽位繪圖已全面驗收。

對照影片9:19四個可用角色、三個空出戰欄：可準備隔離候選`0050 body=50 00 0f 00 00 00 03`（角色1..4可用，預選0，容量3，無尾角色）。此值組合是以影片加現有四人roster產生的重建候選，**不是官方抓包**；需由Server已解鎖角色資料限制mask，不能憑影片解鎖未取得角色。然後再004E(選定scenario-ID)開窗，避免先用舊編隊資料初始化。官方原序可否相反尚未證明，這只是避免舊資料的開發偏序。

## 可供Server接續的有限狀態鏈

1. 保留category3／5B9340本地先播15/1再送001C的已證路徑；收到正確3F(15,1,1)後，只同步一次必要0040接取狀態，再以0047(15,2)要求第二段。這是由原生入口導出的Server重建方案，不是官方封包全序。
2. 收到正確3F(15,2,1)且本連線確在第二段時，準備0050空預選資料，再004E開編隊；不送0064、不在6F位圖預標Quest15完成，不重播15/1。
3. 只有玩家實際0028確認且角色資料有效才進入副本準備。一般Scenario的005F/type2、kind3控制器、reset／ready用前批T07契約。0012後需重綁到當前控制器；不要用第一戰TUTO保留策略或唯一Isilia硬套一般副本。

這條鏈尚未指定004E的最終ID／38上下文／地圖的完整官方關係。資源Quest15.field=19與Case103.stage=19只是已存關聯；不能把19直接寫成004E、0028或map，也不能把Quest15當作已證的副本完成ID。需要接著核對Field19入場／結果消費者與資源查找。故目前不發布「完整進村」可玩版本。

## 剩餘工作與來源

- Field19/Case103的合法進場ID關係、0038上下文、map191/192局部順序與角色綁定；勝利、結算及村劇情15/3觸發。
- 馮德斯村地圖/context/出生資料、旅行入口與回廣場請求；往返不應重新接Quest15或預標完成。
- EndCutScene正常／取消／資源失敗時Server階段還原，及殘窗實際驗收。當前使用者不方便測試，不反覆要求。

工具觀察、資源快照與Server策略在上文分開標示。證據索引story-party-evidence.json包含本批關鍵檔SHA與7項局部原件核對；每批cache-0321*/0322*/0323*/0324*保留REA原raw/pseudo來源、雜湊與not_found，不為缺失入口重新全量反編譯。4B3630曾查無獨立函式，未採作證據。原有任務歸屬依catalog引用，新增跨Task只在本地SCOPE登記，不改owner。
