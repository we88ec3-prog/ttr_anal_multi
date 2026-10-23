"""Curated scope and source selection; no binary analysis is performed here."""
TASKS=[
('T01','現有成果來源審核','逐行區分原生證據、歷史修補及 AI 替代；不重做功能解析','T02 T04 T08 T10 T13','MAINLINE-FLOW.md 06-runtime-login-fix.md 31-collision-grid-spawn-and-trace-crash.md 48-tutorial-battle-fixture.md','tutorial_battle.py tutorial_monster_ai.py movement_position.py movement_simulation.py login_protocol.py','版本與替代規則審核，不宣稱現在仍可玩',''),
('T02','共用通訊與封包框架','封包邊界、連線角色與分派；業務欄位交對應任務','','BATTLE-INPUT-TO-SOCKET.md RECEIVE-AND-SCENE-DISPATCH.md CONNECTION-ROLES-AND-HANDOFF.md NESTED-DATA-AND-TCP-TYPES.md','login_protocol.py','傳輸封裝與官方連線時序未完整確認','8069a0 8060d0 806060 8061a0 804a40 8068b0 806fc0'),
('T03','登入與角色選擇','登入選服選角與連線切換；不決定角色世界內初值','T02','LOGIN-MODULE-COMMAND-LINE-AND-AUTH.md 09-login-protocol.md 16-account-character-roster.md','login_protocol.py account_store.py','官方驗證規則與完整登入順序缺失；本機帳號規則是替代實作','440280'),
('T04','角色初始化','角色初始欄位及位置來源；生成傳輸介面由 T08 維護','T02 T06 T08','22-plaza-player-fixture.md 23-player-control-init.md MONSTER-PARAMETERS-AND-MOVEMENT-INITIALIZATION.md 31-collision-grid-spawn-and-trace-crash.md','login_protocol.py account_store.py new_expedition.py','900/900、固定地圖與戰鬥座標不是正式出生來源；能力、裝備初值未完整確認','4cad40'),
('T05','廣場進入與移動','廣場流程、移動回報與校正；共用 actor 運動由 T09 維護','T02 T04 T06 T09','25-plaza-map-initialization.md 26-player-movement-timing.md 30-plaza-collision-baseline.md 31-collision-grid-spawn-and-trace-crash.md POSITION-UPDATE-AND-MOVEMENT-WRITERS.md','movement_position.py movement_simulation.py','位置估計未含碰撞且不是客戶端位置回報；正式位置權威未知',''),
('T06','地圖與場景資源對應','地圖 ID、資源查詢及資源版本；不推定波次與 MEF 執行器','', 'MAPFLOW-CLUSTER-LOADING.md MAP-TRIGGER-CONSUMERS.md MAP-STATE-RESOURCE-AND-DRAW-CONSUMERS.md','tutorial_monster_config.py','資源與程式精確 build 配對、波次及座標來源未確認','4f3d80 4f4960 4f5640 4f7df0 4df510 56cd10'),
('T07','關卡進入與退出','場景安裝、地圖重設及就緒；生成與勝利分別由 T08/T14 維護','T02 T04 T06','SCENE-ENTRY-RESET-AND-READY.md SCENE-CONTROLLER-SELECTION.md MAINLINE-FLOW.md 48-tutorial-battle-fixture.md','new_expedition.py make_tutorial_transition_probe.py','原版005F type6建立CDuelField；測試修補改為恢復Tutorial；不能沿用可玩結論','4b99c0 4b7d50 4b24f0 4c5930 5449a0 544f50'),
('T08','實體生成與移除','0007 建立、登記、移除的資料介面；不制定生成時間或決策規則','T02 T06 T07','MONSTER-SPAWN-AND-CONTROL-BOUNDARY.md SCRIPT-OBJECT-CREATION-AND-OWNERSHIP.md LB-CREATE-OBJECT-ABI-AND-CONTROL.md','tutorial_battle.py tutorial_monster_config.py','數量、座標、時機、owner 正式來源及通用移除規則缺失','4ae4d0 4d1710 4dff30 4c6e50 4af920'),
('T09','關卡內移動與同步','共用 actor 移動、位置旗標、碰撞邊界及校正；不制定決策','T02 T04 T06 T08','NATIVE-MOVEMENT-CONSUMER.md ACTOR-TARGET-POSITION-SOURCE.md POSITION-UPDATE-AND-MOVEMENT-WRITERS.md SCRIPT-OBJECT-MOTION-BOUNDARY.md','movement_position.py tutorial_monster_ai.py','原生命令產生權責、碰撞細節及校正來源仍未知','4e0060 4e13f0 4d1ae0 4c8580 4ca890 4cabe0 4c89a0'),
('T10','普通攻擊與連段','輸入、連段及取消流程；傷害公式交 T12','T02 T04 T09','BATTLE-INPUT-TO-SOCKET.md BATTLE-CONTROLLER-SIDEPATHS.md CONTROL-AND-SKILL-SOURCE.md','tutorial_skill_cast.py','CHAIN_WINDOW=.65及服務端續段排程是自製；官方連段取消窗口未知','5452c0 5471b0'),
('T11','技能施放','技能計時與消費、消耗和施放裁決；共用攻擊輸入引用 T10','T02 T04 T10','CONTROL-AND-SKILL-SOURCE.md SKILL-MATRIX-CONSUMERS.md GENERAL-MONSTER-AI-COMPARISON.md','tutorial_skill_cast.py new_expedition.py','讀取技能矩陣不等於決策；官方冷卻與消耗裁決不完整','545e20'),
('T12','命中、傷害與死亡','戰鬥結果消費與死亡資料；不把顯示結果推成計算公式','T02 T08 T10 T11','BATTLE-RESULT-AND-AI-FEEDBACK.md kr-battle-frame-binding-20261023/REPORT.md','tutorial_battle.py tutorial_monster_ai.py','半徑45/65、傷害20/35/60、延遲.2皆為fixture；命中死亡復活權威缺失','4b0640'),
('T13','非玩家實體的行為來源','追查既有動作消費端的來源；不要求客戶端一定存在AI','T02 T08 T09 T10 T11','GENERAL-MONSTER-AI-COMPARISON.md BATTLE-AUTHORITY-TRACE.md MONSTER-STATE-TRANSITIONS-AND-SOURCES.md LOCAL-ACTOR-AND-AI-FRAMEWORK.md SUBAI-ACTION-TRACE.md','tutorial_monster_ai.py','自製追逐回家與攻擊規則不能當原生AI；原生來源與P2P權威未知','4e0200 4e0520 4d1af0 4c87d0'),
('T14','關卡目標、完成與獎勵','區分小任務、勝敗、結算及返回；保存介面交 T15','T02 T07 T08 T12 T15','QUEST-STATE-NOTIFICATIONS.md QUEST-FOLLOWUP-DELIVERY.md MAINLINE-FLOW.md 48-tutorial-battle-fixture.md','new_expedition.py tutorial_battle.py plaza_npcs.py','清怪後.75秒完成與預標scenario14/16為本機策略；正式目標獎勵條件缺失','500f90 5027d0 502b40 5030c0 500240'),
('T15','遊玩資料保存與恢復','跨登入需要保存的資料與恢復順序；不宣稱還原官方後端','T02 T03 T04','SQLITE-ACCOUNTS.md MAINLINE-FLOW.md kr-persistence-20261023/REPORT.md','account_store.py new_expedition.py plaza_npcs.py','本機SQLite帳號任務道具是替代；原生profile清理呼叫不是遊戲存檔','')]

EXTRA={
'T02':['native-index/battle-input-transport-audit.json'],
'T03':['native-index/login-module-command-audit.json'],
'T04':['native-index/monster-parameter-audit.json','native-index/monster-spawn-control-audit.json'],
'T05':['native-index/position-update-reset-audit.json'],
'T06':['native-index/mapflow-cluster-loading-audit.json','native-index/map-trigger-consumers-audit.json','native-index/map-state-consumers-audit.json','kr-phase1-20261022/semantic-records.json'],
'T07':['native-index/scene-entry-lifecycle-audit.json','native-index/scene-controller-audit.json'],
'T08':['native-index/monster-spawn-control-audit.json'],
'T09':['native-index/native-movement-consumer-audit.json','native-index/position-update-reset-audit.json','kr-frame-dispatch-20261023/frame-paths.json','kr-frame-dispatch-20261023/corrections.json','kr-frame-dispatch-20261023/identity.json'],
'T10':['native-index/battle-input-transport-audit.json','native-index/battle-controller-sidepaths-audit.json'],
'T11':['native-index/skill-matrix-consumer-audit.json','native-index/skill-timing-fixture-audit.json'],
'T12':['native-index/battle-result-route-audit.json','kr-battle-frame-binding-20261023/binding-records.json','kr-battle-frame-binding-20261023/binding-validation.json','CHECKPOINT-WIRE-AND-ACTION-NOTIFICATIONS.md','native-index/checkpoint-action-notifications-audit.json'],
'T14':['native-index/quest-state-notifications-audit.json','native-index/quest-followup-delivery-audit.json']}
TC_SOURCES=['TC-MEF-RESOURCE-COMPARISON.md','TC-UNPACK-FILE-INVENTORY-20261019.json','native-index/tc-mef-evidence.json','native-index/tc-analysis-paused-20261018.json','TC-STAGE10-CREATEFILE-DISK-RESOLVER-20261018.md']
COMMON=['MAIN-PROGRAM-FUNCTION-MAP.md','NATIVE-BEHAVIOR-MAP.md','native-index/method-atlas/summary.json','kr-unified-ledger-20261023/catalog.json','kr-boundaries-20261022/boundary-records.json','kr-boundaries-20261022/slot-dispositions.json']
DEFERRED=['kr-hit-resource-20261023/REPORT.md','kr-motion-sources-20261022/REPORT.md','kr-crt-startup-20261023/REPORT.md','kr-region-ledger-20261023/README.md']
