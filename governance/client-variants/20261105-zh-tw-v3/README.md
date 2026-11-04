目前狀態：[首次啟動資源錯誤／補齊fcs.flu](STARTUP-REGISTRY-REPAIR.md)。PE／字型等靜態子集通過不足以保證啟動；已補索引，人測待重新啟動。

# 2026-11-05 使用者指定 Client zh-TW v3

使用者明確要求：獨立一版跳過開頭年齡分級提示、NPC名稱與技能名稱／說明套用台版、套用台版字型。此為本次限定授權，不改其他Client政策，不把修改工作副本當原件驗收。

本機成品：workspace/CLIENT/build/zh-tw-v3/Tartaros.zh-tw-v3.exe；必須以CLIENT/build/Open-Tartaros-zh-tw-v3.cmd啟動，WorkingDirectory是新profile。原版/v2與現有資源保留，回復只需重新啟動原v2；不要對含junction目錄給未核對的遞迴刪除指令。

## 內容與靜態驗證

- EXE以SHA6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c為基準，只改2bytes，成品SHAf1a23ee3c410e4261aef5eddcb9b4bacbe185cfff50d83155d2c3842bf088cee。CLogin的grade visibility/counter改0，保留登入與其它等待；不是更改年齡／帳號驗證政策。
- Table文字overlay：NPC NAME359、Active名稱469、技能EXPLAIN469、Practice名稱與說明3846欄。只4member改文字，1022其餘member及玩法欄位完全保留；現有Talk/Synopsis翻譯保留。台版缺3NPC（10499/10537/10538）、1技能說明與55Practice身份未閉合欄位，保留原文；Passive/Support台版本身仍韓文，不猜譯。說明文字數值與KR玩法可能不同，不能因翻譯順手換消耗／CD／傷害。
- 台版msjh/msjhbd為主，保留KR必需的86字型item/size。只補268個未翻譯回退所需韓文字型glyph；兩份私有衍生字型保留TC所有cmap及水平metrics，hinting移除，1218可見字元全覆蓋。未安裝系統字型。實際顯示/排版仍待人測。
- 新profile含27個獨立runtime檔案與7個唯讀用途的static asset junction；UI與TC_UI是新副本。原件hash未改，未執行／附加遊戲。

第一次字型包的Name正則錯改ClassName，被獨立檢查退回；已保留NEEDS_FIX歷史，修正attribute邊界並加原ClassName不變斷言，新Font包SHA865f5d150c3d71110996f98e2bd8e7835ec917c2ccffccda171356624447b22f獨立重驗PASS_STATIC_ONLY。不可把首輪失敗隱藏，亦不可把靜態PASS當真人已啟動。

## 重建與資料界線

tools放回workspace/CLIENT/tools（stp_resources.py可置同資料夾；既有anal/stp_resources.py也可用）；先按各腳本source hash要求準備使用者本地原件、台版資源、現有story-v3與v2EXE。text工具有CLI選項，font工具依workspace相對位置。font fallback需要固定fonttools4.55.3，安裝到CLIENT/tools/deps；不需安裝系統字型。

依序執行text資源builder、font builder、font fallback builder、profile builder（--age-patch 指向本patch-plan）。profilebuilder拒絕覆寫不同輸出，沒有target啟動動作。所有raw BIN/EXE/STP/XML member/TTF/字串集合留本機，Git只保存工具、短patch、hash、統計及已限縮證據。未重新向先前遭拒的REA provider開原BIN；使用既有Git source與已知位址有界核對。

驗收：PENDING_USER。需要確認分級圖不出現、正常登入、廣場NPC台版名稱、技能名稱／說明及字型顯示。Server操控／技能耗量版本另按v28報告驗收。

字型重建第二次發現fontTools默認head時間取現在，已固定到TC來源created/modified；新profile／resource／manifest一致，兩次重建同hash且其餘tables與先前字型完全相同。新字型regular SHAa68f9bad944da2a8bdf22f3e37548c467c79f585a59dd6b448a3c0a1a268a8b6，bold d1d331318ef89b68e7477dd2d6a2f9c5024b1592cb7784dc285b1215f5f19a7a。獨立查核history保留ClassName與時間戳修正前的結果，不宣稱已真人顯示。
