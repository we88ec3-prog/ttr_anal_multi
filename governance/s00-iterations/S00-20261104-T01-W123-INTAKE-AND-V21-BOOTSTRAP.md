# S00 — T01 W1/W2/W3複核、v20玩家回報與v21候選

## 基準與T01結果

已依使用者要求同步main，T01整合終點f2cc1a896f09430e2a325aa6920426c916dbe40c包含extra/roy1/2/3的三次merge（21a6d7cc、db2636eb、f2cc1a89）。讀回「整合驗證上Git」對話，T01明記只檢閱各包驗證結果、未獨立重跑全部驗證器，未授FULL-PASS。先前81a49342屬T10/T16上一批，不能把它誤當本輪新W1/W2/W3審查。

本輪40個新增檔案逐一核對f2cc1a89 Git blob SHA及內容SHA256，登記SRC-0763～0802，總SRC802。原稿保持原樣，claim空、不提升SPEC/ADR/RR。來源身份收據見evidence/20261104-w123-review/SOURCE-IDENTITIES.json。

## S00獨立複核

- W1：使用原上傳ZIP逐項hash校驗；獨立對照Case／MapFlow NodeLink有向順序、MapList MAP/BOUND/TRIGGER、全部ClusterSet／group／每個OBJECT的ID/PRE/COUNT與來源；schema校驗及627個source-map引用hash通過。5 Case、18 node、143 group、186 OBJECT rows。World位置／官方波次／清怪與出口條件仍未知。檢核器最初把MapList欄名寫成MODEL，已改為原欄名MAP後重跑通過，不改來源資料。
- W2：重新讀取原Table.stp SHA09e2cc48…a442與本機Mon/Base.stp SHA1854de29…6957；直接重跑交付的新唯讀驗證器，130個包內member、110個Git來源blob、10個archive member、11個matrix cell、三個ABF及47個animation literal/8Effect/9Sound子節點核對通過；122 typed link及27個未知AI值保留。這包含資料schema拒收錯誤升格的靜態mutation，不是暫緩的Server負向遊戲套件。未重新做BIN/consumer原生驗證，不從FrameSpeed40猜FPS、PRE不等matrix/tier、matrixWORD不等animation ID。
- W3：實際以新目錄執行兩次converter，輸出逐byte相同，131個輸入檔名/bytes不變；79186個離線資料核對通過，10 Quest／30 scene、10798個source-map定位引用核對無錯。DRAFT_BLOCKED/runtime_enabled=false、正式完成／獎勵gate保留。

上述結果收據在evidence/20261104-w123-review/。這些是資料／來源／離線轉換複核，不是T01全文FULL-PASS、原生MEF或Client真人驗收。

## v20重新啟動與玩家觀察

原v20指定Host未運行，2026-11-04 22:18:22 +08:00重新啟動原build89504aa646a9a0039dc125fe0c61c4aafcceab1f，PID29432，精確路徑server-host-v20/Tartaros.Server.Host.exe。loopback8415/5082及auth/journey/story health正常；沿用測試DB，不遷移、不覆寫舊journal/發行檔，新增restart日誌。

使用者回報：「登入會在廣場OK，廣場NPC可正常對話，但村莊NPC無法對話」，並確認村莊是從測試頁選「馮德斯主線117前」到達。此為指定工作副本SHA6f92ba12…b3c對loopback v20的玩家操作結果；agent未操作Client。僅記登入落點／廣場NPC通過，未補猜兩次登入的精確操作數，也不把村莊未通過寫成人測成功。

持續journal有14:20:52Z的Story117 queued/applied，但沒有相應1C/3F/36故事事件，之後連線被玩家重登替換，memory ring清掉。故不能推斷有NPC封包被Server距離拒絕；目前線索偏向Client本地互動／任務候選清單。原始本機日誌不放Git。

使用者另更正：「登進遊戲後應該會先進入類似角色選擇頁的地方，而不是目前的直接進入廣場」，確認先看到冒險團角色、再按按鈕進廣場。登入固定落點廣場是在選擇頁確認之後，不表示省略展示頁。

## v21候選修改與權責

1. A0只送非空60角色展示；已完成教學帳號的saved snapshot保存在連線待處理狀態。F5等自動bootstrap不換場。待收到已有來源形狀的4B C2S42（owned role及mode0/2分欄，未知業務含義保留）才授權此次Square transfer、送69並等43。新帳號命名／首次教學不變；不改Client，不把A0當使用者點擊。
2. Town角色初始化先送Town context／Map／Rebuild與5C角色等級，再送完整6F並建立NPC27區域。502170會按當時Town/角色狀態調500240重算候選；原程式500240讀已存在角色+5C及等級。v20快照在重建前，可能形成空清單；此為有界因果候選，仍待真人證明，不能宣稱找到唯一根因。
3. 將主線Town初始化、QuestFinished、正常進村及Story117/Phindos debug等入口共用同一快照時序，移除外層早送／覆蓋；保持角色stats在snapshot之前。沒有重發正式獎勵或修改normal completion。新增server pose/radius顯示與固定4B42/B0/43取證，仍不含帳密任意payload或實體按鍵宣稱。
4. 依W1獨立核對輸出Server來源目錄IR，保留全部143群及PRE/COUNT；明示EXPLICIT_GROUP_SELECTION_REQUIRED，不自動變成波次／佈點／AI。另開發唯讀目錄讀取與現有16圖選群一致性檢核，不在遊戲Host自動啟用。原native MEF保持未恢復；搜尋仍等開發60%。

原始二進位檔交REA工具開啟被自動審查拒絕，理由是可能交給未明示分析服務。本輪沒有繞過拒絕去重開原件，僅使用已存在Git反編譯文字與歷史本機證據；精確來源blob及範圍在EXISTING-CLIENT-SOURCE-REVIEW.json。未新增原件語意FULL-PASS。

角色頁／NPC首輪修改的30個HappyPath合成案例通過61秒；新增W1目錄兩個正向檢核的結果與發行收據待本批完成後補入。副本共通佈點／大型portal／入口安全距離仍按使用者排程逐副本確認；輸入抖動／方向加Z仍OPEN，不混為本輪修復。

## 最終工程驗證

新增來源目錄後共32項HappyPath通過61秒；19項需求治理測試、S00 registry與dispatch checker通過。目錄第一次交叉檢核誤將既有「第一個ClusterSet」政策當成set ID0，Case108第一個set實為1；已修正為必須明確指定EXISTING_FIRST_CLUSTERSET_POLICY、再按原宣告順序取該set。沒有改W1原資料或遊戲選群。來源目錄SHA3622d06355672dd27df6053f2a1147319d274d83a46b0977cff0b13f8e8e70dc，保留5Case／143群；目前Host不自動載入此目錄，不變更v20已有怪群／座標。

角色頁等待與村莊NPC候選快照時序仍待真人測試；未把合成32項折算為正式6項TEST、Client原件相容性或開發60%。廣場登入／NPC的人測通過只按使用者本次陳述登記。將在同一批完成後換版，不零碎換版。
