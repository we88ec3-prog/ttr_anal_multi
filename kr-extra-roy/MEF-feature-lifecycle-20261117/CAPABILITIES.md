# 全能力索引：從已登記名稱到玩家功能

本表是已知121個正常名稱的逐項分組，不是整個Client／官方MEF功能全集。方法逐列見 `capability-lifecycle.tsv`；語意沿固定來源復用，本輪只補 `current_native_records` 指定的生命週期。沒有把未部署寫成完成。

|功能|名稱數|本輪原件增量|完成／清理邊界|
|---|---:|---|---|
|診斷、時鐘與顯示設定|3|復用；不是本輪新發現|回傳本地時計或設定；不表示遊戲進度 顯示重設依原生renderer；不與任務成功混用|
|不可採用的計數查詢|1|復用；不是本輪新發現|不能據此判斷清怪／群組完成 不適用|
|已確認空操作|4|復用；不是本輪新發現|不產生名稱所暗示效果 不能用stub清理物件|
|載入相容Lua內容|1|復用；不是本輪新發現|native回傳個數不等於載入成功；與全域DoFile契約不同 新exports/相同VM跨run須管理|
|本地換圖與演出地圖備份|3|復用；不是本輪新發現|畫面載入不是Server轉場完成 有取得才Restore；backup不是可巢狀stack|
|小地圖重載|1|復用；不是本輪新發現|沒有新成功ACK UI元件owner生命周期|
|本地世界角色建立|2|復用；不是本輪新發現|可到CDoll更新／draw；不回新EntityId 世界owner的既有生命周期；不是Q slot cleanup|
|世界角色外觀與掛件|3|復用；不是本輪新發現|worker/apply完成才有表現；無通用Lua ACK detach按attachment key，不以appearanceItem代替|
|鍵位與輸入mask|4|復用；不是本輪新發現|清mask不清controller busy／UI capture 只清自己持有的mask；需既有End/release流程|
|有限Q啟停|6|補End後owner／清理連接|running0不是成功；003F可來自skip；Stop與End不同 必要cleanup在End之前；End不是所有owner reset|
|既有出口／NPC／市場點狀態|1|復用；不是本輪新發現|命中第一個既有點；沒有可靠成功值 0/1狀態與0027重建分開；不能建立新點|
|教學提示點建立|1|復用；不是本輪新發現|成功Insert不清舊progress，也不是upsert point.enabled/latch/controller.progress三者獨立|
|教學可觀察狀態|3|復用；不是本輪新發現|GetControlStatus回number，0在Lua仍truthy；UI state另域 重建points不重置controller progress|
|教學scenario請求與等待|2|復用；不是本輪新發現|0040意圖；004C指定key=1可供Lua輪詢 owner場景clear按原生生命週期|
|固定教學角色／可用性查詢|5|復用；不是本輪新發現|不是任意world EntityId／HP／死亡query Delete的參數編碼需引用原件，不把F000原樣套用|
|特定UI、教學頁面與記錄|6|復用；不是本輪新發現|記錄flag不必然等於當幀visible；skip非通用成功 同owner還原UI；不可任意SetUIPage取代|
|教學追蹤圖片|3|復用；不是本輪新發現|圖像不是callback註冊；取消與實體釋放不同時點 Destroy只按其tracking/owner語意，不當所有Q圖清除|
|Q演出物件|14|補End後owner／清理連接|到點清movement bit；AllStopped空樹亦true；Stop不delete DeleteAll涵蓋全部Q樹且等待模型job；DeleteObject是stub|
|領隊位置分量|1|復用；不是本輪新發現|位置數值不是物件handle或群組結果 不適用|
|KeyFrame相機工作|8|補End後owner／清理連接|IsEnded涵蓋stopped/null/空資料，不是資源成功；Stop使apply停止 停止/解除current/配對snapshot還原分開；不能盲pop|
|Q角色相機跟隨|2|補End後owner／清理連接|stop gate與model node存在分開 Stop先對正確current，Detach僅清指標；配對Pop另行|
|相機快照與預設視角|5|復用；不是本輪新發現|Pop先restore/erase再比label；不是冪等查找 只有自己的push才可pop，ApplyDefault不等同snapshot|
|鏡頭位置、角度、震動|4|復用；不是本輪新發現|Move/Set同target；第三Rot參數距離；effect無成功handle 既有快照或預設策略；effect有自己limit|
|共享背景音樂|5|補End後owner／清理連接|淡至0不等於Stop/release；同名Play可不重啟 StopMusic清整個pool及雙slot，不是只停自己的track|
|一般音效與voice group|2|復用；不是本輪新發現|helper只yield；沒有單次完成值或ID native channel回收；本組無單次停止binding|
|全畫面淡幕|5|復用；不是本輪新發現|FadeIn到0自清active；FadeOut到255保留；count不是ms Fade.End(nonzero)清alpha；End(0)可保留覆蓋|
|擷取畫面轉場|1|復用；不是本輪新發現|native capture/update完成後release；helper只yield 依原生phase及renderer teardown|
|褐色色調|2|復用；不是本輪新發現|EndSepia要求phase4，後續4→5→6→0 獨立phase機制；不清其他overlay|
|世界角色繪製閘門|2|補End後owner／清理連接|只控制選定controller/world-tree draw，不等於停simulation 持有者明確Enable；normal End不清該flag|
|特定actor動畫縮放|2|補End後owner／清理連接|flag非0或countdown>0才用約0.2 delta；不是Server clock EndSlowMotion只清flag；countdown須分開|
|上下黑邊|2|補End後owner／清理連接|以獨立flag繪製；normal End不清 持有者Hide，非End自動清理|
|Q飛行圖片|2|補End後owner／清理連接|finite phase→alpha0→phase0→alive0→release/delete/erase；-1 hold不自結束 Del只標記最近handle，下一合格manager tick回收；不能清所有歷史圖|
|多句頭像對話|5|復用；不是本輪新發現|OnEndTalk先於native隱藏尾段；g_scenePlaying不是業務結果 hide/show同owner配對；voice共用；資料清理不同於任務提交|
|序章文字與語音|4|復用；不是本輪新發現|inactive可能完成/失敗/取消；Q.Dialogue不是世界頭上聊天 Prolog.OnClose native action；不是callback註冊|
|固定書本演出|2|復用；不是本輪新發現|參數被忽略；最後state完成才clear；voice gate可阻塞 Stop/自然結束不同；不可用active0猜原因|
|字幕與數字／Miss／Block／擊殺字樣|4|復用；不是本輪新發現|helper yield不是播完；數字不修改HP 各native owner消費與回收，非Server結果ACK|

## 完成狀態如何讀
- 已登記名稱與有效native target：已知有界集合；stub/無效計數另列。
- 能力子鏈：依原報告有條件成立，不代表任意Mission/Scenario都可直接開始。
- 跨功能部署：各新發布品、資源hash、實際key、owner排他及收尾入口仍須落實。
- Server開發：規則／資料／交易／進度與保存獨立，不要求腳本全面接替。
- 遊玩：本輪未執行任何Client/Lua/Server；沒有新增通過記錄。

**四個stub＋一個無可靠計數契約的query不能列成五項可用玩法；alias/同target也不是獨立玩法數。**
