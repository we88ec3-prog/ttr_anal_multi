# v8：結算／主線說話者／任務文字修正候選

使用者正常流程回報：[v42主線與文字缺口](../../s00-iterations/S00-20261108-V42-HUMAN-PROGRESSION-AND-TEXT-GAPS.md)，REQ-0022。沿用翻譯配套持續授權；沒有執行或附加遊戲。

交付本機 `Tartaros.ip-zh-tw-v8.exe`、`U8/StringTable.stp`、`TC_UI/QuestTxt8.xml`。從原遊戲根目錄直接開EXE，保留v7、既有v4字型及v5/v6/v7翻譯依賴；所有舊EXE、原始資源、fcs.flu、pack.gms保持SHA不變。檔案與來源SHA見[metadata](metadata.json)。Git不發布EXE、STP、完整XML/FCS或完整文字清單。

- UI：以台版同Code／同Class與節點結構的Contents.Data更新原locale13工作副本，645列文字；維持原Code與Locale。針對原數字caption路線，在既有baseline載入前掛載新U8文字包；掛載成功才將自訂翻譯baseline路徑UI→U8，失敗保留原路徑。現有TC／CSV回退仍保留。不是改語系來換掉3D資源。
- 說話者：依台版角色類別0／角色ID與FILE，更新9個既有UTF16顯示名稱；含蘋果＆坦基。字串容量與名稱指標表保留。
- 任務：按ID及type／town／giver／finisher／subtype配對，僅改subject與顯示Contents葉文字，共7714處。Contents內數值顯示不同或無法配對者保留。韓版Q120仍level8，不套台版7；前置、獎勵、掉落與數值未改。
- 字型：沿用原v4字型，新增翻譯字元覆蓋通過；台版文字中U+318D項目點號正規化為U+00B7。未對應的原韓文保留既有字型／翻譯限制，不能宣稱全遊戲已中文化。

靜態核對包含：新PE區段及分支邊界、受限差異範圍、XML全部非文字欄位不變、所有舊來源SHA不變。自訂解碼器僅模擬37條新增翻譯指令與6個mock掛載呼叫，核對暫存器／flags／stack及成功後路徑切換；沒有執行原生函式或OS API。這不證明真實掛載、字體呈現或畫面已通過，結果仍PENDING_USER。

重現：工具放在本機workspace/CLIENT/tools，需同目錄既有build_zh_tw_v3_text_resources.py、check_zh_tw_v3_glyphs.py與anal的Archive／PE／Capstone工具；原件另備。執行build_zh_tw_v8.py後再check_zh_tw_v8.py，不啟動遊戲。使用者自行開v8，先核對任務頁與名稱；結算及說話者於下一次正常流程核對。

v8只處理翻譯，Q119後等級／EXP主線阻塞仍未修復；不能把中文顯示或進度跳轉當正常主線通過。
