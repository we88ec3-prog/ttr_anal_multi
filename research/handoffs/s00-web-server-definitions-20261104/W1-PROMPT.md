# W1：副本事件與怪群資料定義

將下段提示詞貼到一個新的Web對話，並上傳同一份W1/W2/W3資料包。

```text
你負責W1：副本事件與怪群資料定義。
先讀上傳資料包 START-HERE.md、MANIFEST.json，再讀git-evidence/中的本派工README與相關AGENTS政策。不要執行舊證據腳本或遊戲。MEF搜尋/loader追查等Server至少60%後再做；本輪不找影片、不要求使用者補拍截圖。不修改Client、不寫私有Server、不提升正式CLM/SPEC/ADR成熟度、不把自訂JSON叫原生MEF。Table carrier是local variant，逐member核對manifest的原始SHA符合欄；未知/不符須明列。只依本包資料完成能做的部分，缺件輸出精確member/ID清單，不要停下來等使用者回覆。T16原始包仍DRAFT_BLOCKED，不能藉轉換宣稱已可正式啟用。

成果獨立放W1/W2/W3對應資料夾，保留來源路徑/commit/memberSHA/欄位、原生已知/使用者政策/候選/未知界線。若你的環境確有repo寫入權限，依使用者政策直接main提交自己的目錄，不改其他工作的檔案、不新branch/force push；否則提供成果ZIP與git diff，不能聲稱已上Git。交付摘要須列實際讀過哪些檔案、可供Server直接使用哪些內容、哪些仍未知。

針對Case101/103/107/108/109，讀local-resources/Table/_CaseList.xml、_MapList.xml、Field/MapFlow與Field/Cluster；對照S00 resource-baseline及T16 quest-scenario關聯。完整保留有向node順序、每個分支/機率、所有cluster set/group、怪物ID/PRE/count，而不只S00目前選定的第一cluster。MapFlow editor x/y不是world座標；不得將COUNT叫整場總數或把group順序猜成官方波次。
交付：scenario-definitions.json、scenario-definition.schema.json、source-map.csv、unknowns.md、README.md。定義SpawnGroup、Condition、Action、Portal與per-node scene cue，但每項必須有來源分類；位置、清怪條件、何時啟用出口等未證部分留null/UNKNOWN。手動Z、通道底端大型出口、入口安全距離列USER_POLICY，精確各圖佈點待副本實作，不找影片也不猜座標。提出由目前有限cluster候選遷移至definition的mapping；不改Server runtime。
完成標準：五個Case均有逐node與全部cluster盤點，Quest/Field/Case/Map/scene/portal-key分域，未知表可直接轉成Server待補項。
```
