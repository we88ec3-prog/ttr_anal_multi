# 2026-11-04 馮德斯至爾斯梅勒的共用主線旅程候選

## 本輪目標與驗收邊界

使用者要求：「你先繼續開發任務前進至爾斯梅勒村，我等等再測」。前一批v18/main整合保留，這輪準備完整可連測的旅程，不因單個未完成修正反覆換版。程式及本報直接main，不開新branch；Client EXE與資源不修改、不操作。

本輪接通的是**劇情／單人副本旅程**。正式Quest接取／目標評估／交付／獎勵／經驗值／新角色取得，仍有尚未綁定的業務與Client發布介面；本輪不以劇情receipt假稱正式任務結算，也不把原T16 DRAFT_BLOCKED資料直接改成啟用。既有S00獎勵顯示通道（type2的PartyExp文字、type4的Leeloo文字）限定證據保留；缺的是合法grant、所有權／換算與提交發布，不因新報告重寫成名稱完全未知。

## 原件與新補證

Town2的韓文資源名為알스메르，普通Map183→town002D／town002.bnd，與使用者指定爾斯梅勒對應。Town1的Map182保持既有候選配置。

- 本地Table carrier SHA256 ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c與T01原件carrier不同；本輪使用的QuestInfo、_MapList、_CaseList、_TownList **四個解碼member SHA均與T01原始carrier09e2cc48...一致**，腳本逐一固定驗證。沒有把整包差異藏掉。工作副本npctable有翻譯差異，不採其名稱當原生證據。
- Field carrier18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a，獨立讀回Case101/107/108/109的四Chart及四Cluster，補足T16當時缺的Case107資源。這只是解除資料缺件，不等於MEF觸發／合法勝利規則已恢復。
- BoundMap carrier07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8，18個Map所需BND逐檔pin；版本0/2的兩個完整靜態層驗證，不改header、不使用all-clear替代。
- NPC韓文提示從T16原件投影id-values.csv取出，來源npctable member SHA a727fceb64a8b58dc98983619fc73b131c15a6be1eec132c1124f2c57b4aa31d；區分同名NPC10047與10048。

可重現唯讀提取：governance/prepare_alsmeer_story_resources.py。逐member SHA、原始節點順序、cluster內容及候選安全位置見 evidence/S00-20261104-ALSMEER-RESOURCE-BASELINE.json。Chart編輯座標不當世界出生點；玩家／NPC／出口位置在BND明確可走矩形中由Server選取，並非官方MEF位置。

## 資料化路線與S00候選排程

| Quest | NPC | 劇情與副本旅程 |
| --- | --- | --- |
| 117 | 10002 라제드 | scene1，返回村莊控制 |
| 118 | 10047 유리 | scene1；Field28欄存在不代表此處自動進副本 |
| 119 | 10047 유리 | scene1；Field26/Case107，Map632→633→634→635；依Map的LoadMap/model對應進場2／Boss3／清怪後4／返回5 |
| 120 | 10008 | scene1→2→3（純敘事，含腳本內換景） |
| 121 | 10002 | scene1 |
| 122 | 10002 | scene1；Field27/Case108，Map636→637→638→639；進場2／Boss3／清怪後4／返回5 |
| 123 | 10048 유리 | scene1 |
| 124 | 10048 유리 | scene1；Field17/Case101，Map184→185→186→187，各圖進場2/3/4/5，清怪後6，返回7 |
| 131 | 10002 | scene1 |
| 132 | 10002 | scene1；Field28/Case109，Map640→641→642→643；scene2對應第三圖642的barley03D，Boss3／清怪後4／返回5，終點Town2/Map183 |

這是明示Server排程政策，不把Chapter sceneIdx順序或LoadMap字串直接宣稱為官方MEF cue。每圖先清本輪選定的有限cluster，保留戰鬥／可空揮，需走到出口按Z才前進；最後結果頁返回再播放後續。Q133與Town2後續任務不在此終點範圍。

## 可共用的實作與資料權責

- `LocalStoryRoute`：NPC、敘事、單人編隊、地圖進場scene、遭遇、清怪scene、手動portal、結果、返回、目的村。沒有每個Quest一份handler；不同任務由配置提供scene/map/case/cue。
- `LocalStoryRouteConfiguration`：版本化自訂JSON、typed domain、18圖的pin／BND、10任務、16node、NPC名與位置。**不是.mef**，不冒稱Client下載了官方MEF。
- `LocalTutorialWorldConnection.Story`：既有世界／combat／codec的適配。全新圖使用既有候選HP/SP/MP與monster agent初始化，跨圖資源／完整boss／掉落規則未恢復。
- `SqliteStoryProgressStore`：本機正常旅程需有同lease的Phindos stage4、有效session及owned role；80個有序navigation transition先提交再送world effect。新component三張表，不改global v2、不寫正式獎勵ledger、不把新scene回報直接寫入既有Quest settlement。
- Client prerequisites是本輪已提交**敘事milestone投影**，與正式結算／獎勵分開標記；進村橋接後可提供15gate。未核准的等級條件只保留LevelRaw，不以metadata假稱完整eligibility。正式level／EXP policy仍待補。
- 新測試段落Story117／119／122／124／132／Alsmeer沿原debug隔離：不改正常進度，不算正常通關。頁面列目前段落與NPC韓文名供玩家對照。
- `story-trace.jsonl`限量保存1C/3F/28/33/36的固定結構內容與前後旅程狀態，和0A大量輸入分開；成功Send的47/4E/22/12/38也加入限量回覆觀測。沒有帳密、任意payload、Client ACK或物理按鍵偽稱。

有限cluster選取為原表每組的前四個cluster依有向node順序各用一個。Monster PRE、官方波次／boss能力／勝利條件仍未有MEF；不得把COUNT叫整場怪數。每個任務的合法objective／turn-in／grant仍需後續對照，SFD-0013保持OPEN。

## 已做驗證／尚待真人

30個允許的HappyPath合成案例通過（最後一輪50秒）；新完整TCP／SQLite旅程覆蓋新帳號→既有教學→廣場→Quest15→10個敘事步驟→30段presentation→16個遭遇→手動出口／結果→Town2，並核對終點9NPC與移動停止、80筆checkpoint及debug後正常紀錄不變。原始真BND的read-only配置預檢另驗18Map、16node、9Goal NPC全部可站立；合成碰撞fixture本身不充作原件幾何證據。

曾修正合成測試讀庫的Pooling設定、以及加入prerequisite後讀包期待；最後一輪完整集合通過。其餘負向／重登／故障／競態／安全／壓測仍未執行。Client多鍵移動未因這次進村開發宣稱修好。

新旅程的Client窗口生命週期、NPC真實互動、scene自然退出及Map183操作均待玩家驗收。合成通過不能算「所有主線功能／正式結算已完成」。部署、來源commit與後續人測在本批收據補入。
