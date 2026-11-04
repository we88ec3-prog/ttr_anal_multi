本輪P0：[v21操控／NPC退回](S00-20261104-V21-CONTROLS-NPC-REVIEW.md)。展示頁與進廣場人測通過；村莊NPC／方向＋Z仍未通過。750ms修正33項合成通過但尚未換版，整批就緒前不要求重測。

本輪接續：[T01 W1/W2/W3複核與v21候選](S00-20261104-T01-W123-INTAKE-AND-V21-BOOTSTRAP.md)。

最新修正：[NPC三倍距離與登入回廣場](S00-20261104-NPC-RANGE-AND-SQUARE-RESUME.md)。真人驗收待測。

最新：[馮德斯→爾斯梅勒主線旅程候選](S00-20261104-ALSMEER-STORY-CONTINUATION.md)：共用敘事／Scenario骨架接10任務、16圖及Town2初始化；30個合成正流程通過。正式獎勵／EXP／角色取得與MEF仍有缺口，真人驗收待測。

最新：[2026-11-04 main整合與v18相容性修正](S00-20261104-MAIN-INTEGRATION-AND-COMPATIBILITY.md)：T10/T16與T01審核已接收整合；來源獨立核對，修正組合動作誤選與受擊FSM，保留全row及實際回覆診斷。共用任務仍DRAFT_BLOCKED，多鍵移動待實機時序。後續直接main，不開新分支。

最新工作包：[多鍵輸入與共用任務引擎](../../research/handoffs/s00-input-and-quest-reuse-20261103/README.md)，供明天Web AI分析；尚未派送／認領。P0輸入組合，P1任務資料化與共用流程。

最新：[v16移動意圖更正](S00-20261103-MOVEMENT-INTENT-V16.md)：撤除非戰鬥Z強制停步，方向放開與方向加Z分別驗證。v14/v15相關停步目標為錯誤解讀，真人修正結果待測。

# 2026-11-03 v15輸入說明／進度測試

[收包管線、同方向恢復與主線段落指定](S00-20261103-INPUT-PIPELINE-AND-PROGRESS-DEBUG.md)：修除v14方向鎖，本機測試頁可指定六個已實作段落；測試連線不回寫正常主線紀錄，27個正常／新授權debug案例通過，Client操作待測。

# 2026-11-03 v14與MEF遷移規劃

[v14修正](S00-20261103-PHINDOS-V14-CORRECTIONS.md)：出口改站上按Z、清怪後保留戰鬥與空揮、修正非戰鬥Z停步；27正常測試通過，人測待完成。[MEF遷移計畫](S00-20261103-MEF-IMPLEMENTATION-AND-MIGRATION-PLAN.md)列內容／AI搬移及原生格式Gate，尚非已實作MEF。

# 2026-11-03 v12人測與v13修正

[人測](S00-20261103-PHINDOS-V12-HUMAN-RESULT.md)確認到村、人物NPC／移動停止及換場畫面，並有三項缺陷；[v13修正](S00-20261103-PHINDOS-V13-CORRECTIONS.md)已通過正常合成測試，實際遊戲重測待完成。以下較早「人工未完成／自動換圖／40接取」敘述按其版本保留。

# 2026-11-03 最新進度

[單人主線進村候選](S00-20261103-PHINDOS-SINGLE-PLAYER-BRIDGE.md)已接通廣場NPC、兩圖戰鬥、結果返回與村落初始化；27個HappyPath通過，Host及工具建置通過。實際工作副本人測尚未完成。此為單人主線副本，與多人組隊不同；目前僅一角色出戰，三角色跟隨仍未完成。以下較早條目的未接通／未部署敘述為各版歷史。

# S00 目前開發採用的分析與規劃入口

分析、原始證據追溯、Server規劃及實測範圍保存在本公開分析庫。
Server實作程式只保存在使用者指定的私有ttr_server_roy，不複製到此庫。
本入口是目前主要採用資料的導覽，不宣稱所有探索、尚未採用的舊稿或第三方報告都已驗收。

目前工作分支：`codex/s00-combat-priority-20261101`，Draft PR102；未合併main。
原始bulk及歷史Task主張沿用原索引與限制，分支推送不等於正式規格批准。

- [舊Server資料採用界線](S00-20261101-LEGACY-SERVER-INTAKE-AUDIT.md)
- [冒險團命名與教學入口](S00-20261101-EXPEDITION-NAME-TUTORIAL-ENTRY.md)
- [移動輸入額度修正](S00-20261102-HOUSE-INPUT-CREDIT-STARVATION.md)
- [連擊與受擊候選](S00-20261101-COMBO-RECOVERY-AND-HURT-COOLDOWN.md)
- [怪物AI與MEF缺口](S00-20261101-ENEMY-PACING-AND-MEF-BOUNDARY.md)
- [任務結算接手](S00-20261101-T16-QUEST-SETTLEMENT-INTAKE.md)
- [獎勵顯示欄位核對](S00-20261102-QUEST-REWARD-CHANNELS.md)
- [新帳號登入卡點修復](S00-20261102-FRESH-LOGIN-NAME-LIMIT.md)
- [全新帳號教學人工結果](S00-20261102-FRESH-TUTORIAL-HUMAN-PASS.md)
- [目前進村階段規劃](S00-20261102-PHINDOS-ENTRY-MILESTONE.md)

[完整迭代索引](README.md)保留較早所有設計；
[馮德斯分析工作包](../../research/handoffs/s00-phindos-mainline-20261102/README.md)
列各對話工作與來源收件狀態。收到報告與T01獨立驗證／S00採用分開；目前不能說全部通過。

每項採用結論應記原始來源版本／SHA、有界核對工具／結果、Server設計選擇、
實際遊戲結果及未知。原始資源、本機帳密、帳號DB及私有Server程式不公開。
本輪新查的Quest15資源資料已補進上述進村規劃與可重跑工具；沒有只停留在對話摘要。

- [進村四段事件與碰撞資格核對](S00-20261102-PHINDOS-SEQUENCES-AND-BOUNDS.md)：演出與普通村落初始化分開，實際Server讀取器核對，不宣稱進村成功。

- [NPC本地劇情與通知方向](S00-20261102-SCENE-NOTIFICATION-ORDER.md)：1C前已有本地scene呼叫，3F literal1不作任務成功證明；採用typed欄位解析。

- [任務前置保存候選](S00-20261102-TUTORIAL-PREREQUISITES-STORE.md)：source-only，尚未接live發布，獎勵僅pending entitlement。
- [明日整村劇情Web AI工作包](../../research/handoffs/s00-phindos-web-analysis-20261103/README.md)：五張工作卡、77筆Town1任務、28段scene與分檔metadata、整合驗收格式。

- [任務前置明示發布與CSquare控制器核對](S00-20261102-TUTORIAL-PREREQUISITES-PUBLICATION.md)：26個正流程測試，模式預設關閉／未部署，普通Town1入口仍待證。

- [Quest15開場NPC／對話及控制候選](S00-20261102-QUEST15-INTRO-CONTROL.md)：原始目錄欄位分域、六筆文字存在性、限定控制恢復，未宣稱NPC／進村人測成功。

- [隔離前置測試準備](S00-20261102-ISOLATED-PREREQUISITES-PREP.md)：新空白資料庫與獨立發行檔，尚未換版。
- [場景啟動接收函式](S00-20261102-SCENE-START-CONSUMER.md)：確認0x47及兩個有號WORD，排程與任務授權仍待接通。

- [廣場 NPC 互動區域補齊](S00-20261102-SQUARE-NPC-INTERACTION.md)：0x27 完整清單、劇情後恢復與26個正流程測試；舊Server錯誤opcode／提前完成任務不可沿用。
