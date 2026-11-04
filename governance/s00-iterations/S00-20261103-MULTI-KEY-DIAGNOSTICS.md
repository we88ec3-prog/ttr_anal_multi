# v16人測未通過與多鍵診斷準備

使用者在v16回報：按住上同時連點Z不能移動。之後補充依序送過上+Z、左+Z、下+Z、右+Z。沒有各組獨立結果，不能推定四組各自驗收失敗。此為REQ-0011追加GAME_RUNTIME_OBSERVATION；Server基準e01730c9eed62f9edbd25eb2453898e198032a38、Client工作副本SHA256 6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c，原件KR SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。

舊metadata核對：台北時間2026-11-03 03:16:26至03:17:30共152筆0A；payload_logged=false，只能證明收過輸入，不可由11B推導flags或direction。無法事後恢復四組按鍵的row內容。

診斷版不再修改遊玩判定。在既有明示啟用的本機progress debug功能下，新增最近2048筆控制actor輸入ring：sequence、UTC、flags、direction、world loaded/combat/moving/requestedMoving/direction前後狀態、reply kind/frame count。只記唯一控制actor的0A結構row，不記登入、帳密、完整payload、account/session識別或任意封包。連接新的測試連線清空ring；上限後捨最舊，資料在記憶體，不假稱完整永久封包存檔。

GET /local-test/progress/input-trace沿既有debug opt-in且僅loopback可讀。尚非輸入實體按鍵記錄器；物理按住／放開仍需玩家按步驟提供時間對照。紀錄於domain Handle之後、傳輸送出之前，reply count不等於已到達Client，未量測socket backlog。

27 Category=HappyPath通過（19秒），包含完整正常旅程的trace：released+Z使moving由真變假、held+Z保持moving、sequence有序。Host Release publish成功。這是診斷與既有流程回歸，不是多鍵問題修復或真人通過。其餘暫緩測試未執行。

## Web AI研究準備

[工作包](../../research/handoffs/s00-input-and-quest-reuse-20261103/README.md)收錄P0多方向／多動作鍵與P1共用任務Runtime。先回答8000真正語義及held/released是否可由wire區分，再制定Server適配規則；不以Z強制停步、方向鎖、最後一鍵或硬猜優先序取代證據。尚未派送／認領／原生驗證。

## v17啟用

分析／工作包76e6f9ba9a130bf8b8abb404f21ab75d18cb19ac、私有Server f95fe9099419b2bbb5f0daa71c6810d0c2b53d8e已push。2026-11-03 03:38 Asia/Taipei換版前明確核對並保存loopback8415/5082的v16 PID40356及完整Host路徑，僅停止該任務Host；v17 PID40044，路徑phindos-host-v17/Tartaros.Server.Host.exe，沿用accounts-phindos-v12.db。登入綁定／journey健康，input-trace GET200且未連接時為空陣列。Host DLL SHA256 41fc2f7529750f362f1c7c3049b4b2c7eedf22c0584f94c291b748111d6799cd；Network DLL SHA256 5c32b66e6022c8b56e3ca55b188adb9a462dd4d4fa3a82241a92b7f631d3d2d6。未操作Client或替玩家POST改進度。新診斷人測尚待。
