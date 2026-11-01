# S00 — 工作副本登入回覆、選服畫面與主線交接觀察

日期：2026-11-01。需求歸入既有 REQ-0001／REQ-0002 的
`GAME_RUNTIME_OBSERVATION`，不另建同義 REQ。靜態研究基準為公共庫
`ac6aac673426459df2a778d20a80c623b8559a92`；私庫開發基準為
`69c714c54fb5c802251736ee38ff37c19fba3c53`，本次實測使用尚未提交的
reply experiment 工作樹，不能把基準 commit 當作包含本次實作。

## 授權與版本

使用者明確允許開啟指定遊戲工作副本測試，並同意以隔離測試帳號完成
本機 127.0.0.1:8415 正常登入；先前兩個指定 EXE 的操作授權見
[啟動紀錄](S00-20261101-STANDARD-USER-CLIENT-LAUNCH.md)。本輪後段使用者
停止 Computer Use 並接手操作；後續只讀 Server 日誌及開發，不代操作 UI。
只測新帳號至教學進廣場正流程，其他案例留在[待測清單](../../design/testing/TUTORIAL-HAPPY-PATH-AND-DEFERRED-TESTS.md)。

- 實測：`Tartaros.ip-zh-tw-only-v2.exe`，SHA256
  `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`。
- 靜態研究原 KR BIN SHA256
  `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- Windows 一般權限 launcher、隔離 SQLite、loopback 8415/8416/8414，
  HTTP health 5082；沒有修改遊戲 EXE、原始證據或 Windows UAC。
- 本文不包含測試帳密、原始封包、grant、Session ID 或 DB。

## 實際正流程觀察

| UTC 時間 | 證據及限定結論 |
| --- | --- |
| 06:09:50 | 登入 RX118，AUTHSTARTED／AUTHACCEPTED，TXSTART／TXCOMPLETED163；隨後收到8B，記錄 LOGINUNKNOWNAPPLICATION 後正常結束此 login socket。沒有保存 payload，不能將8B推定為特定 opcode。 |
| 登入後、06:11:02 前 | Computer Use 獨立確認「伺服器選擇」畫面，左側 `테스트`，選擇後右側出現韓文分流項目；選取分流後「連接」可按。這是指定工作副本 M3 UI 證據。 |
| 06:11:02–03 | 正常按「連接」後 auxiliary 與 primary 各 ACCEPT；primary RX63，PRIMARYHANDOFFUNAVAILABLE 後 CLOSE。當次 grant 設計為60秒，操作距簽發約72秒；通用事件無法區分 shape／proof／expiry，不能只憑時間宣稱精確原因。 |
| 06:19:18 | 新 Host run／新遊戲正常登入再次 AUTHACCEPTED、TXCOMPLETED163；使用者停止工具前未再完成 UI 交接確認。 |
| 06:25:46 | 後續人工接手期間 RX118、AUTHSTARTED、AUTHREJECTED，尚無足夠證據定位原因；不是成功選服證據，也不安排錯誤帳密測試。 |

本機去敏 metadata 位於
`runtime-observations/2026-11-01/local-login-auth/reply-runtime-logs/` 與
`reply-runtime-final-logs/`，其下 `reply-experiment/primary/`、`auxiliary/`
各有獨立 run／connection 記錄。這些是本機證據定位，不是已上傳的原始
封包附件；公開本文保留有界摘要。未抓原始封包，未證原始 KR／官方 Server 相容。

## 修正需求與工程實作

REQ-0001：C02 成功後必須實際送出 Client 可消費的回覆，不能只停在
AUTHACCEPTED。私庫以明確 opt-in 接上既有 app13 candidate 與 raw frame；
預設 auth-only 不變。M3 已有本工作副本畫面證據，正式 SPEC 仍 DRAFT/PARTIAL。

REQ-0002：先啟動兩個 loopback listener 再公布分流；login 完成後保留
一次性 grant，primary 以同一 SQLite provider 原子轉移 exact lease。
正常人工選服窗口改為兩分鐘且不超過 C02 原 lease，增加獨立 shape 事件，
後續必須取得 PRIMARYHANDOFFACCEPTED 才可聲稱真遊戲交接通過。
這個期限與 grant 語意是 Server-owned design，並非原版 Server 規則。

選服 row、flags、未命名欄位與 raw frame 模式採用明示的本機實驗選擇；
來源只是既有 [choice copy](S00-20261101-LOGIN-CHOICE-COPY-AND-REPLY-CANDIDATE.md)、
[57B builder／交接方案](S00-20261101-PRIMARY-LOBBY-HANDOFF.md) 與
SPEC-NET-0001／0002、SPEC-AUTH-0001。沒有新 BIN 研究、T01 FULL-PASS 或
官方 first-wire pairing；不得把實驗取代規範 pin 或啟用 native admission。

## 尚未完成

實際 primary 身分交接尚待人工正常操作驗證；primary 尚無 roster 回覆，
角色畫面／創角 wire／教學／廣場均未完成。私庫新增真 TCP＋SQLite 的
合成正向交接測試只證工程前置，不證遊戲旅程。現有7個正向、198個暫緩
方法定義；正常操作遇到阻塞應調查，其餘故障／過期／重播／併發專項不重跑。
REQ 保持 CANDIDATE，RR/GAP/CLM/SPEC/ADR/正式 TEST 與 native admission 不升格。
