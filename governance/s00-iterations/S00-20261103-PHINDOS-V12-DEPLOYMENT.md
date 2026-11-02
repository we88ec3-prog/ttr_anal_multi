# S00：v12單人主線進村候選交付收據

2026-11-03 01:00（Asia/Taipei）啟用本機loopback測試版。

- 私有Server提交：`f1261c82d76b43918a8c268ed607a898d7341af6`，已推送
  `codex/tutorial-combat-priority-20261101`；未聲稱合併main。
- 採用的公開分析提交：`b40f47d9fffcd4bb69d9e988bfa96cf347dccaee`，已推送
  `codex/s00-combat-priority-20261101`；正式SPEC／ADR批准與原版驗收狀態不變。
- [實作範圍／來源／候選限制](S00-20261103-PHINDOS-SINGLE-PLAYER-BRIDGE.md)：
  主線編隊為單人任務副本，與多人組隊不同。目前僅一名角色1/3/4出戰。
- 27項Category=HappyPath通過、0失敗／略過（15秒）；最後招募階段條件收緊後，
  新進村案例另跑1項通過（4秒），重新發行。沒有執行暫緩異常測試。
- Host／LocalDev／唯讀Inspect Release建置零警告／錯誤。
  真實兩個Road BND由C#讀取器核對，各五個玩家／怪物生成點全可走。
- Host啟動時驗過六份碰撞SHA與所有所需元件；新隔離資料庫／新短測試帳號只提供登入，
  沒有預填冒險團、角色、勝利或任務進度。正常流程由玩家從頭產生。
- 健康檢查確認127.0.0.1:8415本機認證listener與journey adapter啟用。
  這不是遊戲畫面、劇情／戰鬥成功或原版Client相容性證明。
- 已發出從新帳號連測至馮德斯村移動停止的回饋卡；**人工結果PENDING**。
  未測117之後主線、三角色編隊／跟隨、蘋果出戰、多人組隊或MEF官方排程。
- Client SHA仍為既有指定工作副本`6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`，
  本輪沒有修改／啟動／操作Client。不得列為原始BIN人測通過。

本收據不公開帳密、帳號資料庫、私人Server程式或runtime原始日誌。
