接續：[已追到頭頂名稱／職稱直接讀取入口與v6提案](../20261107-nameplate-read-path/README.md)，新配套XML待使用者確認，未建立v6。

最新人測：NPC頭頂名稱仍韓文，v5名稱修正未通過。見[實機退回](HUMAN-NAMEPLATE-REJECTION.md)，靜態結果不等於實際顯示。

# zh-TW v5 — NPC頭頂名稱／職稱（2026-11-07）

使用者明確同意v5提案，並詢問Server開發與測試進度。只新增原遊戲根目錄的
Tartaros.ip-zh-tw-v5.exe及TC_UI/Table.story-zh-tw-v5.stp，保留v4及全部原件。
沿用UI/Fnt4.stp與UI/Font/v4jh.ttf、v4jhbd.ttf，沒有新增／覆寫字型。

v4人測回覆：顯示正常、NPC對話名稱正常、頭頂名稱仍韓文。問題與方案見
../20261107-zh-tw-v4/NPC-NAMEPLATE-PROPOSAL.md。v5尚待實機驗證，不把該
有界v4結果升格為全翻譯／全場景或原件相容性驗收。

## 製作與驗證

- EXE SHA256 e8933203b03379bee6813082bb016fd14ffd42eac151c246bcd02fe8f203d5ea；
  相較v4只改0xbe8a19的一個byte，Table路徑v4改v5。年齡及字型路徑不再變更。
- 翻譯檔SHA256 aedba24dc9a0e828c275ebdce192f3af8661ded1b77d5088c2ea992965ec62ae。
  1026個member中僅Table/npctable.xml變更；其餘1025個解碼內容不變。
- 只有唯一NPC ID、TYPE及category6 actor FILE均相同的330筆可候選；非空台版
  文字覆蓋327個NAME、11個GUILD。10518/10519/10520重複ID及其他未閉合對應保留。
- XML完整節點／屬性／文字比對：只允許上述338欄不同，其他玩法與對話欄位不變。
  81個既有EXE/BIN/DLL/STP/FLU/GMS/TTF製作前後hash相同；未碰帳號設定或Server。
- 新翻譯涉及352個字元，兩份現有字型缺字0。檢查整份NPC表另外發現保留未譯列
  涉及105個字型未覆蓋字元；這不是新增翻譯造成的缺字，不另改已核准字型，
  完整NPC韓文回退覆蓋仍是已知限制，不能稱全表完全顯示。
- 驗證狀態PASS_STATIC_ONLY／PENDING_USER。沒有啟動、附加或操作遊戲。

本機製作工具CLIENT/tools/build_zh_tw_v5.py，拒絕覆寫輸出；需要既有
stp_resources、v3 font packing、text XML indexing與glyph checker工具。
原始EXE/STP/TTF及全文XML不放Git，只有工具、hash、欄位ID與有限報告。
直接從原遊戲目錄開啟v5.exe；回復只需開v4或v2，不需還原資源。
