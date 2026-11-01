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
