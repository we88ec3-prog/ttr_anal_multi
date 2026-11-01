# S00 GAME_RUNTIME_OBSERVATION：v7廣場到達與戰鬥／互動缺口

## 授權、版本與實際回覆

使用者既有授權本人操作指定工作副本進行正常教學正流程；本輪依既有v7結果卡測試，
S00未操作／附加／修改Client。使用者後續自行點廣場NPC，另列正常互動觀察；非負向測試。
KR原始分析目標SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；
實測工作副本SHA本輪重新唯讀核對為
`6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`，不是原版Client互通驗收。
本機loopback v7部署來源 `0de80050c9a9f12f5666eaeb63a3e94c57529062`。

使用者先回覆：「已進廣場，人物與 NPC 出現且能移動停止」。補問戰鬥與轉場後回覆：

> 被攻擊不會出現受傷動作，且連點Z不會連段，進入廣場仍沒有轉場，點NPC要進行下一段劇情後沒反應且無法移動

兩者同時保留：到達／顯示／初始移動停止通過；受擊、連段、可見轉場及NPC互動失敗。
沒有證明X施放或所有三怪行為完整正常，也不能把「到達廣場」改寫成完整教學驗收通過。
NPC的精確ID、選項、發送事件及卡住原因尚未知，不擅指為10338或Quest15。

## 來源狀態與保存核對

唯讀CIM／netstat確認當時Host8252為指定v7 exe，primary／aux有Established連線；
health回報已有登入及tutorial entry。較早零流量只代表較早查詢時刻，不能沿用為目前狀態。
原始journal檔當時仍0B，未從空檔猜按鍵或scene事件。

SQLite唯讀摘要：global schema2、tutorial component v1，該既有隔離測試帳號有首戰勝利
紀錄與role1/2/3/4，progress revision3。tutorial progress只有account_id／revision／
first_battle_completed_at，沒有terminal tutorial欄位或已驗明Quest14/16獎勵交易。
首戰timestamp與角色授予可能來自前輪，不能證本輪從全新帳號一次跑完。
不公開帳密、帳號／session ID或原始資料列。完整目標仍未達成。

## 本輪修正準備與原生界線

1. Server原本在沒有active action時一律Start基本段0；正常放開、等動作結束後再按Z會回101。
   新增動作結束後0.4秒的Server候選接段寬限，正常短間隔可接102／103；移動或技能另清鏈。
   這不是官方取消／連擊窗口，亦未證實是使用者本輪症狀的唯一原因。
2. v7受擊只發0E傷害／HP，非死亡時沒有顯式受傷motion。唯讀pinned Isla.abf：ID9對應
   Isla_ATTACKED.asd；ASD單段20frames／40FPS／Delay0，名目0.5秒。member SHA分別
   `ebcb766e13989c480017ff560bcde6738a5d53c5b9bfaceb045b38ab74691e41`、
   `3ee9c851d61bd93d6a733289a3ba93a30debe11a4daabc9010836918fe4a30e6`。
   它只證動作資料，不證0E原生reaction gate／霸體／打斷／擊退規則。候選僅在伊莉西亞待機
   受非致死傷害時播放9，0.5秒後回idle；不鎖輸入、不打斷施放，合法新動作／移動可取代展示。
   [資源metadata／carrier SHA](evidence/S00-20261101-ISLA-HURT-RESOURCE.json)可用既有
   `inspect_tutorial_bounds_resource.members`與`inspect_first_tutorial_cluster.decode`唯讀重現，
   解碼euc-kr XML後選Animation ID9及該ASD的AnimationHeader／SpliteData；不執行腳本。
3. 廣場Town context／技能輸入暫存／多row支援先前已備源碼但不在v7，尚不能歸為本輪實測。
   原版loading仍未恢復；不能用強加sleep假稱原版轉場已修好。
4. 廣場NPC業務事件尚無完整Server回覆實作；可見NPC並不代表互動已支援。另記REQ-0018，
   保持戰鬥優先，待核對實際入口／任務／場景／控制恢復契約，不發猜測1D或自動完成Quest。

正常合成驗證新增「放開後再按」101→102→103及待機受擊motion9。此前測試把第三次按鍵
仍預期101，且使用首段時間給後段，已改為正常連段與對應名目片長；不以錯誤fixture維持斷段。
異常、取消邊界、重播、併發、死亡／恢復等按使用者政策列待測，未執行。
最後21個HappyPath合成案例通過；不代表v7人測缺口已在遊戲修復。
本輪未部署新Host，未再要求重測；等待整段修正可用後再安排。
