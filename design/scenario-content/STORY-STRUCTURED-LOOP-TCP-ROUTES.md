# 主線循環：正常 TCP 與獨立 Host 通關回村

2026-11-22。SERVER_DESIGN_CHOICE / OFFLINE_SYNTHETIC / NOT_NATIVE_MEF。
接續 [Story adapter 核心](STORY-STRUCTURED-LOOP-ADMISSION.md)，本批補上正常遊玩輸入的路線證據。
分析基準 `9f38e60491a4162dca7da52bc20045e2e3c3d97c`；私有 Server 基準
`98d555eebb22bf0cc933452d40d7208710cd6ea7`。沒有修改 Client／原件／舊版或現用 Host／使用者 DB。

## 本批結果

| 路線 | 正常訪問順序 | 實際擊殺 | 戰鬥 EXP | 最終 Q119 交易 | 完整增量 |
|---|---|---:|---:|---:|---:|
| 操作停止點 51 | 1 → 2 → 3 → 4 | 13 | 52 | 5,880 | 5,932 |
| 不操作停止點、達三輪上限 | 1 → 2 → 1 → 2 → 1 → 2 → 3 → 4 | 23 | 92 | 5,880 | 5,972 |

兩條路線各有同程序 TCP／獨立完整 Host 共四份收據。正常登入及 primary 交接、廣場建單人隊、
公開隊伍目錄、進村、由原 NPC 完成 Q117 對話再開始 Q119、原編成、原入場及清場劇情回報、
原版 BND 走位、普攻擊殺、正常停止點／出口、結果確認、返回劇情及村莊都已走通。
回村為 Town 1／map 182，原隊伍仍在等待目錄，Q120 開放；Q119 任務經驗表只有一筆。
任務交易是固定 5,850＋最後清場 10＋一次通關 20；逐訪戰鬥信用不在最終交易重複發放。

準備範圍明確分開：兩種檢查器都準備教學與 Q15 里程碑；獨立 Host 另準備角色 Lv.15。
Q117 以後使用正常輸入，沒有用 debug 切到 Q119，也沒有直接呼叫遊戲 Handle／Poll。
這不是自然全新帳號從教學一路練等的驗收。TCP 檢查器使用測試時鐘及只讀狀態觀測；
獨立 Host 使用不同 PID、真實時間排程，驅動器只有封包、靜態 BND 規劃及 DB 唯讀檢查。
兩個獨立 Host 完成後均核對 PID／部署 DLL 路徑並停止，來源 DB SHA 不變。

## 版本及驗證器契約

沿用候選 `story-q119-structured-loop.scenario.json`，SHA256
`ca0707961a10914fe25b7f1a3606020f0f1129e19154aa19a2349dfcfaa49089`。
原主線 SHA `14773c3184b201e6a369b753fbf1094972d792c1e2f8e10a4f67587714def50c`，
合併圖 SHA `ea5a473d55e3a2e8d27a6a42380e2db2c8183146005e47504303734e6e60f480`，
經驗政策 SHA `60ca18e680aecec6218f96b5d6d09baf781ff6e81ef7812f9372f4a2d90940ee`。
不放寬原圖、初始模型、敘事場景及主線進度綁定，不新增原生傳檔 opcode。

專用 TCP 檢查器須依目前 scenario node 動態遍歷，不使用舊固定四圖 foreach；
核對逐訪初始怪群、實際信用、最終 visit GUID 唯一性及停止／上限原因。
獨立 Host 必須等待原場景及地圖封包；停止操作須收到 category 1／key 51 已停用的狀態。
原主線清場會重送同圖作出口 presentation 重建，**同圖重建不等於新 visit**，
不可將已觀測的擊殺統計歸零。本批曾有驗證器時序／統計失敗，已修正並完整重跑；
沒有因此改 Server 狀態機、降低碰撞限制或把失敗收據當成通過。

[四路線交叉檢查收據](story-loop-normal-route-validation.json) SHA256
`7b98eeaf7e874c41ca93a5d92ab6ee6dfd7067dfd7147d02d4f13e51436f6931`。
Host／Inspector／Admin 三個 Release 建置零警告／錯誤；742/742 HappyPath 全通過、零略過。
TRX SHA256 `a0790d4018ceb7c959f4015907988df4204de9f66a1baaaabc84f511cd8d2cf6`。
歷史核心／設定收據維持原樣，不能將它原本的 false 欄位回填成當時已通關。

## 仍待完成

主線循環專用管理 profile、包含固定任務獎勵政策的版本預覽及不可變成對 ZIP 尚未完成；
普通主線工作台繼續拒絕循環發布，避免缺少主線獎勵 metadata 的草稿被誤發布。
逐項 HP／SP／MP／冷卻延續仍依既有核心測試與後續專項核對，這四份收據不宣稱已全部逐項驗收。
指定 v2 的劇情重播、鏡頭、標記、原生操作及顯示由使用者另驗；本批沒有新 GAME_RUNTIME_OBSERVATION 人測結果。
原生 MEF 傳入／載入、Client 自主生怪／完整 AI 仍未閉合；Server 自訂 schema 不可改稱原生 MEF。
自然新帳號全主線，以及重登／重送／敗退／故障／安全／併發／壓測維持獨立待測。
