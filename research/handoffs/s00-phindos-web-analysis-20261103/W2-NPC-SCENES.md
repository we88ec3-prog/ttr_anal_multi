# W2：NPC／對話／28段場景的事件與封包接續（P0）

你負責Client互動及劇情路由。先讀COMMON.md及scenes/INDEX.json，逐檔核對28段call inventory；
再讀S00-20261102-SCENE-NOTIFICATION-ORDER.md、T16任務介面／勘誤與有限native來源。

請完成：
- 每段列OpenTalkScene、phase／RestoreMap、鏡頭、演出角色與道具、endBehavior、下一場景的實際觸發；call literal與helper作用分開。
- 追廣場10338及村內劇情NPC點擊／選項 → event → 5008B0候選key／561760等local啟動 → 1C／36／3F各來源；列方向、長度、每欄位及分支。禁止發明通用ACK。
- 釐清561760、565720兩種啟動、561DB0清理／下一段、場景表與Chapter表如何連接；3F literal1不能當唯一成功條件。
- 對每段列Server需等待、需回覆或只記錄的事項，回覆依哪個精確consumer生效；控制何時鎖定／恢復。

首批優先：Quest15的10338點擊到15/1、15/1→15/2，以及15/3結束如何進普通村落。
最終交付scene-flow.json（28段）、npc-intents.csv、CONTROL-AND-HANDSHAKES.md、GAPS.md。
無法由派生資料閉合的helper／欄位列精確位址，不聲稱已驗原BIN。

## 可直接貼給Web AI的任務入口

請先閱讀共同規則：https://github.com/we88ec3-prog/ttr_anal_multi/blob/codex/s00-combat-priority-20261101/research/handoffs/s00-phindos-web-analysis-20261103/COMMON.md
然後執行本工作卡：https://github.com/we88ec3-prog/ttr_anal_multi/blob/codex/s00-combat-priority-20261101/research/handoffs/s00-phindos-web-analysis-20261103/W2-NPC-SCENES.md
依共同交付格式新增results/W2/下的成果，先交P0可開發資料與精確未知。
