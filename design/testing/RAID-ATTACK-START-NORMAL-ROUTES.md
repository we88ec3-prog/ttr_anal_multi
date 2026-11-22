# RAID 1～3：實際起手事件的正常路線

2026-11-22，SERVER_DESIGN_CHOICE／OFFLINE_SYNTHETIC／NOT_NATIVE_MEF。
承接[怪物起手契約](../scenario-content/MONSTER-ATTACK-START-SIGNALS.md)，補齊先前
「RAID僅接線與建置」的工程驗證缺口，不回填舊收據，也不宣稱原生格式或人測通過。

三份新候選各沿用固定RAID範本的五圖、出生點、原版BND、等級與必要頭目。最後一圖
新增 MonsterAttackStarted，觀察初始組的指定頭目實際 `legacy-melee` 起手：

| RAID | Stage／Case | 頭目模型／PRE | 正常獎勵與返回 | 來源候選 |
|---|---|---|---|---|
| 1 | 50／88 | 1159／1 | 經驗書2274一本，回廣場 | [關卡檔](../scenario-content/phindos-raid1-stage50-case88-attack-start.scenario.json) |
| 2 | 51／89 | 1088／5 | 經驗書2275一本，回廣場 | [關卡檔](../scenario-content/alsmeer-raid2-stage51-case89-attack-start.scenario.json) |
| 3 | 52／90 | 1184／1 | 經驗書2276一本，回廣場 | [關卡檔](../scenario-content/rotrua-raid3-stage52-case90-attack-start.scenario.json) |

起手旗標或初始組 WaveCleared 其中一項成立後，設立 `raid-guards-trigger`，再由
FlagDelayElapsed 等0.5秒產生 `raid-guards-ready`，允許一名額外護衛生成。護衛沿用同圖
已有的非頭目模型及座標。這是自有編排，不把原版資源引用當作官方增援配置證據。
初始清除是明示替代來源；不偽造起手，也不移除必須擊倒護衛的通關條件。

三份候選由隔離Admin的標準 `raid-1`／`raid-2`／`raid-3` 工作台經HTTP保存並驗證，
下載同版scenario／AI／manifest。兩次下載位元組一致，來源候選與匯出內容解析相同。
一般RAID未提供獨立preview端點，使用既有「保存並驗證」及配套reader，不擴張loop預覽。
這批沒有操作瀏覽器GUI，也沒有替換目前使用者服務。

正常路線在最後一圖以正常移動接近指定頭目，在玩家開始攻擊前讓怪物實際出招。
唯讀Server診斷記錄 Entity257、模型／PRE、初始波次null與 `legacy-melee`；此時初始組
尚未清除，證明使用真正起手來源。待延遲到期及護衛生成後，繼續普通攻擊、必要時用已備妥
的HP回復卷軸，清除全部敵人並走原結果確認／返回廣場。沒有注入旗標或強制清敵。

[最終驗證收據](../scenario-content/raid-attack-start-validation.json)逐一綁定候選、實際保存
配套、六條TCP及三個獨立Host的SHA、實際事件與延遲狀態。六條TCP分開原版與新版各三場，
使用同程序測試時計；三個新版獨立Host則經正常登入／廣場建隊／RAID選擇與五圖戰鬥，
使用真實時間，保存獎勵後回廣場。每場一本書、CP3000及裝備／角色EXP／故事狀態保持，
隔離來源DB不變。RAID按原有成功流程返回廣場並清理隊伍，不能套用一般狩獵場的同隊回村主張。

HappyPath為776項，零失敗／跳過。未新增重複實作的單元測試；本批重點是補不同入口adapter
的實際正常通關。起手核心的五個正流程案例仍引用前批。建置與逐次輸出以私有執行文件及收據為準。

限制：READ_ONLY_SERVER_DIAGNOSTIC_NOT_CLIENT_ACK，未證Client動畫或自主AI。
這次完整路線均走存活頭目起手，初始清除替代來源僅經載入與內容驗證，未另跑整場路線。
Story新事件正常路線、指定v2、自然全新帳號及既有暫緩的錯誤／重登／併發／故障／安全／壓測
保持待驗。整體MEF目標未完成。
