# 旗標數量條件的反向依賴索引

2026-11-22，SERVER_DESIGN_CHOICE／OFFLINE_SYNTHETIC／NOT_NATIVE_MEF。
這批實作既有優化待辦中 FlagsCountReached 的反向消費者索引，不新增條件語法、
Client介面或網路opcode。既有WatchedFlags／MinimumFlags與內容定義保持。

先前每次新旗標加入後，完整依宣告順序掃描此節點全部FlagsCountReached，直到不再新增
旗標。現在由唯讀節點索引將每個父旗標映射到實際監看的條件；新旗標只排入這些條件。
條件仍讀取當前實例的權威旗標集合，沒有把未成立的旗標、可達性或作者預覽當成已觸發。

工作集合按原宣告順序處理。新增旗標若影響本輪尚未經過的列，可在本輪檢查；若影響已經
經過的列，留到下一輪。持續到工作集合為空，才返回原呼叫者。這保留舊固定點的判定與
對外派送phase，不把條件閉合改成下一個world poll，也不提早啟動FlagDelayElapsed。
已成立條件不重複派送；同一輪多個父旗標排到同一列時合併工作。

每次Enter在既有loop／scope reset之後清空工作集合，為未成立的條件各排一次，處理繼承或
保留的父旗標。fork共用唯讀索引，但複製兩個工作集合、游標與計量，不共用執行狀態。
這批不建立跨實例旗標，也不改變既有scope保存／清除政策。

新增唯讀 `flagCountObservationWork`，在一般副本與Story診斷各自投影：

| 欄位 | 意義 |
|---|---|
| referenceCandidateRowsLowerBound | 每次Enter／成功加入外部旗標，舊完整掃描至少訪問一次全體條件列的累計下界；不含舊固定點額外輪次 |
| candidateRowsVisited | 實際取出處理的索引候選列 |
| watchedFlagsRead | 這些候選實際讀取的父旗標數 |
| dependencyEdgesVisited | 新旗標查到的反向監看邊數，包括已成立條件的跳過檢查 |
| entryRowsSeeded | Enter時排入的條件列數 |

下界不保證在每個中間快照或所有圖形中大於實際候選列；反向依賴可使一列再次排程。
這些計量不包含索引建立、字典與排序集合成本，不能換算CPU節省、吞吐或Client卸載。
其他旗標消費者與全域戰鬥血量查詢仍是各自工作。

## 驗證

[完整收據](flag-count-index-validation.json)綁定舊／新Network、相同Inspector、完整TCP、
實際Host、Story控制及TRX。保留舊Network4920f83b，兩邊使用同一Inspector及既有
Case693旗標延遲候選，排除檢查器改版及內容改版造成的差異。

- 新增三個HappyPath：獨立舊完整掃描oracle對照混合向前／反向依賴、無關定時旗標與正常
  靜止觀察；部分閉合後fork獨立及下一節點繼承；實際兩輪重訪、清除及重新成立。
- 兩條分支各自完整TCP回包一致，只正規化既有來源已定位的隨機角色wireAlias；不是任意
  刪除不同欄位。3669／4159個應用回包、敵群／擊倒經驗、旗標、延遲快照與結算保持。
- 所選路線每條舊候選列下界8對實際候選5，父旗標讀取13、反向邊3、入場種子2。
  此數值只屬此候選，沒有宣稱所有MEF內容都有相同比例。
- 同版獨立真實時計Host完成六圖、88EXP保存及原村同隊返回。Story同版測試時計TCP另跑
  r1出招三輪、r2初始清除停止／三輪，保持5984／5936／5984EXP、每輪獨立visit及一次Q119。
  Story這批沒有重跑獨立Host，先前收據維持各自的版本界線。
- Host／Inspect／Admin Release零警告／錯誤；HappyPath779項，零失敗／跳過。隔離Host
  已停止，來源DB不變，現用服務、原版Client及使用者進度保持。

最初對照誤選缺town001.bnd的狩獵場資料夾，停在舊版載入前置；改用既有完整資料夾後，
舊／新路線均完整通過。比較工具新增計量profile時的欄名整理錯誤，只以已保存回包重新稽核，
沒有因觀察失敗重啟已完成的遊戲路線。失敗與最終輸出分開保留。

指定v2、人測、自然全新帳號及暫緩的錯誤／重登／故障／安全／併發／壓測仍待驗。
Server診斷與綠燈不表示Client自主AI或全部MEF已完成。
