# v42使用者回報：Q119後主線及顯示文字缺口

使用者依v42正常流程測試卡操作；指定v7 Client檔案SHA937486b989d0a1adcddd86f5224011f8b22907c61dd30c3772ad4179891299ec。未讀遊戲記憶體或獨立確認執行中EXE身份。Server實作d40b5c0／Host7684，原件SHA9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。新版整條人測未結案。

## 正常主線阻塞

使用者：打完巨大公雞副本後無法繼續，詢問雞湯是否需要未取得的任務道具。

Server story journal確認Q119 Result→ReturnScene5→完成回報；revision20已在Q120／NPC10008／Npc階段，debugDisplayLevel=null、無scenario instance。這證明敘事key已前進，並非副本結果頁未返回。查詢時ready=false，最後狀態僅作該次流程留存，不冒充仍有活躍Client連線。

原始QuestInfo memberSHA5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60：Q120要求Demand119、level8、giver/finisher10008；沒有物品需求。台版對應subject「塞內山的幽靈樹」、NPC「翰森」，台版level7不能拿來覆蓋韓版8。雞湯劇情不能擅自轉成一筆掉落要求。

既有GAP-PROGRESS-0001原為靜態風險，現在加入人測阻塞。Server正常角色仍固定level1/2/5且未實作EXP／升級，是目前直接可見的門檻缺口；未以記憶體觀察宣稱Client每個欄位數值。RR-0014持續補原生EXP／level呈現consumer，Server成長與正式結算另列；不發假任務道具、不用debug升級算正常通過。

## 翻譯回報

1. 結算頁的「미션 성공」（任務成功）、「스킬 숙련도」（技能熟練度）。
2. 主線說話者「핑코&탱이」（蘋果＆坦基）。
3. 任務名稱、Contents／說明、接受任務按鈕與部分獎勵標籤仍韓文。

本機原始台版FCS相同Code279／495已有中文，但現有掛載/lookup不能據靜態字串就算實機有效。v7 EXE內的說話者是既有硬編碼UTF16字串，由角色名稱表引用；NPC頭頂已翻譯不代表此表也翻譯。QuestInfo文字必須按ID及敘事身份配對，只改subject與顯示Contents，不複製台版等級／獎勵／前置或整表替換。

依翻譯持續授權製作新檔v8，保留舊版、fcs.flu、pack.gms與原件。實際顯示待測；不操作／附加遊戲。
