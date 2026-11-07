# v44：招募清除封包勘誤

v43送0060時誤用2B008B；原生539DF0實際註冊008B→53A8C0（修改隊伍名稱／容量，需要不同長度內容），008C→53A940才清招募狀態。此錯誤可能使Client讀取不足資料，v43測試卡撤回。這是本次來源索引換算及複核漏失，不歸因遊戲原件或使用者操作。

[機械換算](../client-variants/20261108-normal-village-entry/registration-arithmetic-v2.json)直接從原始539DF0函式邊界反組譯，各handler offset都按command=(offset-4)/8計算；8A/B/C/D/E/F與88/89/90逐條列出。另一舊主張「0088也必定清隊伍」退回，0089才有已核對清理流程。舊來源metadata保留並加勘誤警告，不把當時驗證改寫為從未失敗。

Server改用008C，正常合成旅程加入公開→私人UI狀態切換斷言；105HappyPath通過，0失敗／略過，51秒。v43的105項沒有覆蓋此私人分支，不能支持原先錯誤主張。正常房間實機仍待回；使用者明確稍後一起測試，現在繼續開發，不重複催測。部署狀態後補。

公開列表／離隊／加入的新來源另見directory-list-and-leave.json及directory-join-producer.json；未因取得producer就宣稱完整加入或多人服務已開發完成。

部署：v44已啟用，PID30596／source1e739c3c552414cb99db6d085107ab2170fbb8bf，四埠與健康狀態獨立核對、DB已備份；[收據](evidence/S00-20261108-V44-DEPLOYMENT.json)。使用者稍後一起測，暫不新增催測提問。
