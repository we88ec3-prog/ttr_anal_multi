# W3：主線資料轉換及一致性工具

將下段提示詞貼到一個新的Web對話，並上傳同一份W1/W2/W3資料包。

```text
你負責W3：主線資料轉換及一致性工具。
先讀上傳資料包 START-HERE.md、MANIFEST.json，再讀git-evidence/中的本派工README與相關AGENTS政策。不要執行舊證據腳本或遊戲。MEF搜尋/loader追查等Server至少60%後再做；本輪不找影片、不要求使用者補拍截圖。不修改Client、不寫私有Server、不提升正式CLM/SPEC/ADR成熟度、不把自訂JSON叫原生MEF。Table carrier是local variant，逐member核對manifest的原始SHA符合欄；未知/不符須明列。只依本包資料完成能做的部分，缺件輸出精確member/ID清單，不要停下來等使用者回覆。T16原始包仍DRAFT_BLOCKED，不能藉轉換宣稱已可正式啟用。

成果獨立放W1/W2/W3對應資料夾，保留來源路徑/commit/memberSHA/欄位、原生已知/使用者政策/候選/未知界線。若你的環境確有repo寫入權限，依使用者政策直接main提交自己的目錄，不改其他工作的檔案、不新branch/force push；否則提供成果ZIP與git diff，不能聲稱已上Git。交付摘要須列實際讀過哪些檔案、可供Server直接使用哪些內容、哪些仍未知。

以本包T16 kr-quest-runtime-20261103-v0.1.0的CSV/JSON、source-index/source-members與S00 Quest117/118/119/120/121/122/123/124/131/132路線為輸入，開發Python標準庫離線工具。目的在讓後續主線批次處理，並非啟用T16 blocked package。
交付：convert_story_data.py、README.md、requirements（若純標準庫寫明無外部依賴即可）、轉出的story-catalog.json、source-map.csv與validation-report.json。CLI明確接受input/output路徑，預設不覆寫來源。保留原QuestID、NPCID、Field、Case、Map、scene、前置/後繼、接取/敘事/編隊/副本/返回的差異；未知不填0冒充值。檢查重複ID、遺失引用、scene關聯、domain混用、已知源SHA；未支援或缺資料逐項報告。不要把任務接取當完成、scene receipt當獎勵結算，或Q118的Field28欄位自動轉成必開副本。
正常輸入的離線轉換需可重跑得到一致語意輸出，不執行Server/Client，不跑本專案暫緩的遊戲負向/故障/併發套件。source-map須可追回原CSV列/JSON pointer；輸出保留DRAFT/UNKNOWN。完成標準：S00可在本機執行轉換並核對十個Quest的關聯，無須手填散落handler；所有未能表達的條件均列未知。
```
