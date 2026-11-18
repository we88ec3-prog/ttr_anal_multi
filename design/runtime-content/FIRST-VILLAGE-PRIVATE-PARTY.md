# GAME_RUNTIME_OBSERVATION：首次主線進村與返回廣場

2026-11-19 使用者確認能從廣場主線完成首次戰鬥並進村；首次到村當次無法用世界地圖返回廣場。重登後，正常建隊進村及村莊返回廣場都可用。這補正了前一份 [Q15 前置觀察](NORMAL-VILLAGE-ENTRY-20261119-OBSERVATION.md)：Q15 首次到村已有使用者回報，首次同連線返回仍失敗。

使用者另選定方案：「自動建立不公開的一人隊伍，讓 NPC 與返回廣場都可用」。這是本輪 Server 玩法政策授權，不是原服自動建隊的來源證明。

## 成因與必要的隊伍資料

原 Server 在無隊伍的劇情村莊以 0069/7 安裝 CSquare，等 0043 後才送 Town/map/NPC。WorldMap 的 649D50 在 F9392C==7 時，返回廣場控制項只關閉視窗，不建立 F4392／不送 0042。故即使 Server 的返回 handler 已存在，Client 仍可能沒有請求。

既有 0099/3 走 4B9320、CMissionRoom、kind1 controller／UI4，完成後寫 F9392C=3。548350 的 NPC 互動前檢查隊伍物件，因此不能只改場景而不發布隊伍。來源沿 [既有村莊控制器界線](../../governance/s00-iterations/evidence/t07-phindos-intake-20261103/post-t01/MISSION-LOBBY-AND-TOWN-PRELOAD-DEPENDENCIES.md) 與 [原場景回程](../scenario-content/VILLAGE-SQUARE-RETURN.md)。原版 9741d197… 與指定 v2 6f92ba12… 的選定世界地圖／場景安裝視窗已唯讀比對，完整 SHA 及位址收於接續收據，不當成全函式或官服 producer 驗收。

當次 primary connection 2 有正常 Q15 演出／編隊與到村，但沒有 0042 返回；connection 3 重登後可見 003D／0042 多次往返。這與使用者回報及 scene7 短路吻合，日誌不記 payload，不能單獨證明所有點擊意圖。

## 已授權的首次到村政策

只有自然 Q15 的 ArrivalAuthorized=4 先成功保存，才進入自動隊伍分支。沒有隊伍時建立容量 1、名稱「首次進村」、Kind2／Town1、不公開的真實 Server 目錄房間；同步租約連線、角色、隊長及本人旗標。已有自己擁有的一人隊伍則沿用，不踢離多人／他人隊伍。沒有提前補完成或改資料庫旗標。

沿既有 0099/3 安裝村莊後，在 Town context／map／人物／NPC／ready 之前發布 001C、008E、008F（本人＋隊長 0x0006）。0099/3 路線不等待廣場專屬 0043。交易與銀行沿同一 Town/bootstrap，所有場景與隊伍資料先於 NPC 操作就緒。返回廣場沿既有一人隊伍旅行政策保留該私密房間，明確離隊仍使用原功能。

Host 在啟用正常主線設定時採此政策，health 的 localStoryScenario.firstVillageParty 為 PRIVATE_SOLO_AFTER_COMMITTED_Q15。網路元件另以 autoFirstVillageParty 選項明示；舊測試／debug／其他組合不因此被默認自動建隊。主線單人編隊本身仍由原有 0028 控制，這份村莊隊伍是另一步 Server 狀態。

## 進度前的清單鎖定界線

Server 的正常進村資格仍要求已完成 Q15，到村前不發布 Town1 的 0080，不允許 003D 越過該資格。Client 的列表外觀另有規則：64B240 從 4A7810 取村莊最低等級，與 4D43D0 的角色最高等級比較，再設定 row+260 與鎖頭控制項；這段不查 Q15 資格 vector。因此 Lv.1 列看似開放，不代表 Server 已准許進村。

尚未取得能僅靠既有 Server 封包讓這個鎖頭同時反映 Q15 的來源。此項維持待開發；不假改角色等級、不覆寫 TownWorldList、不修改 Client 或捏造 UI opcode。使用者要求「主線前鎖定」分成 Server 入場資格（已執行）與 Client 外觀（未完成）。

## 驗證與後續

正常新帳號 TCP 商城旅程現在於 Q15 首次到村立即檢查 0099/3、容量1／不公開欄位、本人隊長，再同連線 0042 返回廣場、保留已賺資格、正常離隊及另建一人隊伍進村，接續原 Q117～Q144 與商城回歸。初次測試使用僅接受 DA 的讀取 helper 而失敗，接續夾具又未處理「沒有配置狩獵大廳」時的 69/43 而逾時；更正正流程交握後專項通過，失敗 TRX 保留。

既有手動離隊後的無隊伍村莊仍沿 Single/scene7 候選，這次沒有普遍解決該路線返回廣場或清單視覺鎖定。多人隊伍、特殊故障等維持原待測清單。新政策的指定 v2 NPC 互動、首次不重登返回廣場與完整主線仍需實機重測；既有帳號完成的 Q15 不會被重設，須另用新測試帳號驗首次流程。證據見 [接續收據](first-village-private-party-validation.json)。

最終 Release Host／檢查器零警告零錯誤，完整 HappyPath 591／591 通過。隔離 Host 預檢確認政策並自行退出、零隔離 listener；核對原 Host PID／部署路徑後只換版本機遊戲服務 31508 → 34532。新 health 確認政策，管理端 30276 保持 HTTP 200。已請使用者另建新測試帳號驗首次流程，結果待回。

使用者其後回覆「之後再測試」：首次到村修正的實機驗收延後，未指定日期，仍是待測；沒有新增通過結果。遊戲 Host 與管理端保持開啟。
