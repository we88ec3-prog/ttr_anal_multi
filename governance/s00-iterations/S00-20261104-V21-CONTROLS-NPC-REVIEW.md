# v21 人測退回與操控優先修正（尚未換版）

## 使用者觀察與本批界線

使用者回覆 v21：「展示頁與進廣場正常，但仍不能對話，方向鍵與Z也仍有問題，操縱問題非常重要請一起處理後再測試」。展示頁停留／按鈕進廣場按該工作副本列通過；Story117 村莊 NPC 與方向＋Z 保持未通過。使用者要求整批準備好後再測，不派零碎測試卡。

環境：Server main 8a13678cee8d58d566498c9d097b3bd2377410da；原始目標 KR 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，實測 EXE 6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c，仍是既有工作副本相容性，不是原件全文驗收。沒有修改／操作／附加 Client。

## 本機證據

已保存到 runtime-observations/2026-11-04-v21-controls-npc/snapshot 與 status.json。複製時三個執行中的 .game-tcp.lock 無法讀取，明列排除，不宣稱完整程序快照。原 journal 留原處；公開只收範圍／hash，不上傳原始連線資料。

- 本輪 gameplay trace 183 列、46 筆 row：8000/0 共29、0000/0 共14、0001/1 共3。出站 0B與0C各47、位置16共18；可核對回送頻率，不可反推實體按鍵時刻。
- 這次快照中，0B出站未關聯input batch的列只有登入初始Stop；沒有證據顯示750ms watchdog在本輪實際觸發。因此其程式缺陷修正不能直接宣稱解決v21畫面抖動根因。
- story trace 僅42、43及兩筆B0，沒有1C/3F/36 NPC或劇情意圖。不能把「Server 距離 gate 拒絕」說成既證根因，更不能透過自動播放代替對話修好。
- Story117 指定已套用；目前 NPC10002、Town1、Npc phase、revision0。當時 Server 估算位置約753.981/686.108，目標 NPC778/702；此值不是 Client 位置讀回。

## 有界來源複核

使用已存在的 Git bulk 衍生文字與本機歷史分析，不開原始 BIN、不重啟 MEF 搜尋。bulk 保存不是逐函式 FULL-PASS，以下是 source-shaped 有界判讀。

- T10 的 input-contract/server-integration 已證：8000不是physical held。正常 Single 的 held方向＋Z 與 released方向＋Z可以生成相同 row；以 action-only 清移動或沿用上一方向，都不能稱還原實體按鍵。
- 546100／5452C0 可省略未變的移動報告。現行 750ms silence-stop 是 Server 候選政策，無從把沉默判定成 release。
- 4AFE60 寫 actor E2/E4/B0及 controlled actor feedback；4CA890依 E2 moving推進位置。歷史 anal/44-full-character-switch-and-movement.md 記載 prediction 對照曾只有跑步動畫無位移，最後恢復echo並關掉0.8s watchdog。故本輪不採「省略所有本機0B即可修復」的假設。歷史使用者結果僅作歷史證據，未重演舊工具／附加 Client。
- 4B2AF0／543700／544730／544A00 保持18B checkpoint列、manual enabled及半徑內原生互動路徑；544070 kind3經本機Quest/UI gates，5B9340再條件式送1C。不能把原0A按Z任意轉成NPC事件。
- 4B1BF0的Town context同步寫Town與重算候選；502170的6F重算候選。debug入口現碼已有_storyInScenario=true，會送99/3；故撤除「debug從廣場漏送InstallTown」假設，未再塞重複99。

來源 blob／SHA 清單見 evidence/20261104-v21-controls-source.json。未改Task全文審核或native_complete。

## 已準備的工程變更（未部署）

1. 移除普通Poll的750ms無報告強停；明確停止報告、cast/hurt及教學／劇情轉段的既有Stop保留。不把no-observation當released或實體held。
2. Server估算位置不再每次Advance最多計750ms；保持30 units/sec候選與靜態碰撞，最多遍歷有限地圖對角線，以避免長時間無變更造成無界計算。位置仍非原服值／Client讀回，action-only估算缺口仍在。
3. 補入固定世界初始化出站99/27/6F/14/24的日誌白名單，可追scene/context/checkpoint/activation，沒有增加帳密或任意payload記錄。
4. 33個HappyPath合成測試通過約61秒。新增長按不變報告＋silent Poll＋明確neutral的生命週期案例；舊合成750ms期待及其後return位置改為顯式neutral後的位置。第一次7個案例失敗均因後續仍期待舊309.5座標，已修正為同一顯式neutral路徑的317後重跑全部通過；不隱藏初次失敗。

這些變更不等於方向＋Z或NPC已修復。沒有換版、沒有新真人測試卡；v21仍為現行執行版。

## 仍需解決的P0

- 需要確認既有Client通路是否有獨立移動生命週期／ack／availability上下文能消歧；若實際可觀測序列相同，必須明列資訊限制，不能再用last-key、Z強停、timeout或虛構物理edge宣稱修好。
- 普通場景的action-only目前仍按movement-report候選清moving，故持續按方向＋Z的需求尚未達成。保持REQ-0011 OPEN/CANDIDATE。
- 村莊NPC尚無原生上行事件，保持REQ-0019未通過。需在同一操控修正批次核對控制器／Quest候選／checkpoint啟用與實際互動，避免只放大Server半徑或無條件跳劇情。
- 不改Client、不套用新MEF／影片猜值、不擴大暫緩測試。只有整批有可審閱修正與工程檢核後才請使用者再測。
