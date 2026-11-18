# GAME_RUNTIME_OBSERVATION：Q15 前世界地圖進村被擋

後續使用者已確認 Q15 主線能首次進村；首次當次返回廣場失敗、重登後往返正常。已選定首次到村自動不公開一人隊伍的 Server 方案，見 [後續觀察與修正](FIRST-VILLAGE-PRIVATE-PARTY.md)。本頁保留主線完成前的時間點與證據，不以後來完成覆寫舊紀錄。

2026-11-19 使用者在指定 v2 廣場選 Lv.1 馬德斯／Phindos，走隊伍配對→進入村莊，畫面出現「等級不足，無法進入」。這項實機不能標 NV-01 通過，也不能由文字直接推定角色等級門檻。

唯讀檢查目前未過期且最新的登入帳號，與剛購買／穿戴 2625 的帳號相同。其 Q15 bridge 保存 stage=1、2（角色 4），沒有 stage=4 ArrivalAuthorized，也沒有 local_story_runs。當前正常旅程尚未完成首次進村；既有較早里程碑保留，不直接改 DB 或授予完成。

當次 primary 日誌有 0052 清單查詢、0055、0053（50 bytes）與 005E，未見實際 003D 進村請求。這與既有有界來源一致：Client 5B6250 先經 4E2E70 查村莊資格 vector，再決定是否送 003D；false 使用「等級不足」提示，但 helper 本身沒有角色／冒險團等級比較。來源仍是 [正常入口分析](../../governance/client-variants/20261108-normal-village-entry/README.md)，不能以這句提示證明官方等級規則。

目前 Server-owned 正常旅行政策：Q15 的兩張圖、回村演出及進村提交完成後，首次進村保存 ArrivalAuthorized=4。重登由 ReadArrivalAuthorizedAsync 讀保存資格，廣場 snapshot 補 15，VillageAccessPackets 以 0080/1 發布；新的連線與正常後續村莊旅行沿該權威資料驗證。這是現行重建政策，不宣稱官方首村資格原則已完整還原。既有 NV-01 TCP／離線基準也明示完成首次村落劇情後才做該段。

給使用者的接續路線：回廣場與「主線劇情負責人」（NPC 10338）互動，重新開始 Q15，完成兩張圖及首次到村演出；之後回廣場再測世界地圖正常建隊進村。已提問是否能重新開始；沒有選項、無法入圖或流程途中卡住時，應記錄具體步驟並修復該入口，不以跳進村或改完成狀態代替。未完成場內戰鬥不承諾從中途續接。

本輪沒有改玩法、Client、資料庫進度或重新換版。商城 Garnet 重整已另獲「可以正常更新」的實機回覆，不能替代村莊驗收。截圖及唯讀摘要保留於本機 `outputs/cash-shop-manual-20261118/village-entry-prerequisite-observation.json`，公開內容只收雜湊與無帳號識別碼的摘要，見 [收據](normal-village-entry-20261119-observation.json)。
