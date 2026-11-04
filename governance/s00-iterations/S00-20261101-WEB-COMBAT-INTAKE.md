# S00：收件 Web T10／T11 與多筆輸入實作

沿既有 REQ-0016 戰鬥優先處理；此為有限研究收件與 Server 修正，不新增未登記 CLM 的
CODE_ANALYSIS discovery、不更動 Task owner／T01 退回，也不把候選契約升級核准。
本輪只讀取既有 ChatGPT 對話與已提交檔案，未向其他對話送出訊息／派工。

## 來源版本

Web 分支 `t10/roy/chatgpt-web`，提交 `4064846ff77fbf3884fc84830ed35f60c9d8781d`：

- [T10 row 勘誤](https://github.com/we88ec3-prog/ttr_anal_multi/blob/4064846ff77fbf3884fc84830ed35f60c9d8781d/research/handoffs/s00-web-skill-gap-20261101/20261101-T10-NATIVE-ROW5-T01-ERRATA.md)，blob `adb3b4fd1557dd3fffb50f37699d89ef0b634586`。
- [T11 timer／gate 界線](https://github.com/we88ec3-prog/ttr_anal_multi/blob/4064846ff77fbf3884fc84830ed35f60c9d8781d/research/handoffs/s00-web-skill-gap-20261101/20261101-T11-KR-SKILL-012A-GATES-BOUNDARY.md)，blob `3691a72a7177c5fb91767cc01a4caf030375f304`。
- [交接](https://github.com/we88ec3-prog/ttr_anal_multi/blob/4064846ff77fbf3884fc84830ed35f60c9d8781d/research/handoffs/s00-web-skill-gap-20261101/20261101-T10-T11-S00-SERVER-HANDOFF.md)。

經 GitHub connector 讀取精確提交的三份原文，不以對話自述代替檔案。原稿未合 main，
本輪也不合併來源分支或改原稿；連結保留精確 commit 供重現。

## 有限核對與適用範圍

[重現工具](../verify_web_combat_intake_windows.py) 唯讀核對原始 KR BIN SHA
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，再比對兩份報告
Row A／B、sender、timer receiver／decrement／availability／hero helper 共七段指定 VA
半開視窗 SHA，全部吻合。[結果](evidence/S00-20261101-WEB-COMBAT-BYTE-WINDOWS.json)。
這只是 byte hash corroboration，沒有聲稱原稿整篇語意 FULL-PASS 或原版互通驗收。

T10 的有用更正：`000A` 是 6-byte header 加 N 筆 5-byte row，傳送仍有 gate；Row B
第五 byte 可保留 E4 snapshot，另一支才覆寫 B0，不能統稱固定 B0。Row A 的完整 def-use／
callback ABI 仍未閉合，WORD 高字與第五 byte 的通用遊戲語意不能補猜。

T11 有限接收布局與既有 S00 timer 分析相容；signed count/33 仍不證秒數，controller
更新頻率未閉合。hero model<=9 的 helper 不適用怪物1036；沒有得到官方 SP／MP 消耗、
首戰 Skill→Motion→Effect／TargetSkill 全鏈。因此目前不接線發送012A、不替換 Server
候選冷卻／消耗，也不把上輪0.4秒技能暫存說成 Web 已證的原版窗口。

## 本輪實際修正

私有 Server 原本只接受 `000A` 長度11；有效的多筆 row 封包會落到未實作路徑。
新增結構讀取器保留 `FirstWord／SecondWord／OpaqueByte`，不把最後 byte 命名成通用方向。
既有工作副本 adapter 仍沿用候選的 entity／flags／direction 對應，但現在能在多筆 row
中選出唯一對應受控 actor 的資料。header 不作 Server clock，其他 row 不作受控 actor
的輸入，也不把其他 row 的未知 flags 用來拒絕整包。

同一 FirstWord 多次出現時，完整 producer 語意仍待補證；讀取器不擅自合併、重排或採
last-wins。這個分支仍未實作，不聲稱所有合法000A producer 都已支援。現有單筆行為保留。

20 個 HappyPath 合成案例通過：新增結構測例逐筆保留不同 opaque byte；原有 TCP／SQLite
教學旅程改用「受控 row 位於三筆中間」啟動移動，再以單筆放開停止，實際經 Host adapter
核對移動／停止回覆與後續旅程。沒有把此合成案例當作本機遊戲已出現多筆輸入的觀察。
異常長度、重複 matching row、重播／併發／故障等仍列待測，未執行。

沒有改 Client／資源／DB／獎勵／完成旗標，也未更換 live v7 或重發人工卡。
完整技能規則、合法任務結算保存及真實新帳號完成教學進廣場仍待完成。
