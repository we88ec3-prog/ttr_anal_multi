# W2：怪物技能與AI欄位對照

將下段提示詞貼到一個新的Web對話，並上傳同一份W1/W2/W3資料包。

```text
你負責W2：怪物技能與AI欄位對照。
先讀上傳資料包 START-HERE.md、MANIFEST.json，再讀git-evidence/中的本派工README與相關AGENTS政策。不要執行舊證據腳本或遊戲。MEF搜尋/loader追查等Server至少60%後再做；本輪不找影片、不要求使用者補拍截圖。不修改Client、不寫私有Server、不提升正式CLM/SPEC/ADR成熟度、不把自訂JSON叫原生MEF。Table carrier是local variant，逐member核對manifest的原始SHA符合欄；未知/不符須明列。只依本包資料完成能做的部分，缺件輸出精確member/ID清單，不要停下來等使用者回覆。T16原始包仍DRAFT_BLOCKED，不能藉轉換宣稱已可正式啟用。

成果獨立放W1/W2/W3對應資料夾，保留來源路徑/commit/memberSHA/欄位、原生已知/使用者政策/候選/未知界線。若你的環境確有repo寫入權限，依使用者政策直接main提交自己的目錄，不改其他工作的檔案、不新branch/force push；否則提供成果ZIP與git diff，不能聲稱已上Git。交付摘要須列實際讀過哪些檔案、可供Server直接使用哪些內容、哪些仍未知。

先Actor1001/1009/1004，從_ActorList、CharSkill、SkillActiveTable、SkillMatrix、IndependentSkillEffect與既有T10/T11報告建立ID→FILE/PRE→技能/動作/效果引用關係。先讀欄位與consumer報告，不假定同名ID屬同domain。每個追逐/感知/回位/選招/起手/命中/冷卻/受傷/死亡欄位標「已知來源值」「候選政策」「無來源」。保留ABF動畫時長與ServerAI節奏的區別，不從FPS或玩家SubAI入口推定怪物AI。
交付：monster-profile.schema.json、monster-profiles.json、monster-skill-links.csv、required-members.csv、unknowns.md。raw Actor/ABF與已確認Monster table不在包內，必須將引用解析到可證的精確檔名/名稱，未能證明副檔名就保留stem及理由，不虛構body內容。required-members列查得的carrier/member/ActorID/PRE、缺此檔會阻擋哪項結論；可讓S00之後一次解出小包。不要求使用者自己找檔。
完成標準：三隻怪均有可用/未知欄位對照、來源SHA與最小缺件清單；不交猜值版官方AI、不修改連段核心。
```
