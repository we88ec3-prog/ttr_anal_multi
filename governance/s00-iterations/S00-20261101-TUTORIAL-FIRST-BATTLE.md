# S00 — 首場教學戰鬥載入與返回候選

接續[NPC與編隊](S00-20261101-TUTORIAL-NPC-AND-FORMATION.md)及Iteration17/18的E17–E18。
使用者已確認伊莉西亞仍在、編隊頁可見，並確認目前預選伊莉西亞體驗正確；保持現狀。
本段延伸既有正常旅程。首輪實測新增編隊確認後無法進場問題，登記
**REQ-0014 GAME_RUNTIME_OBSERVATION**；正式SPEC／RR／GAP／ADR／TEST狀態不升格，規範pin仍dd69ec9。

## 原始來源與歷史實驗的界線

目標KR BIN SHA256仍為
`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
沿用已保存Ghidra按址原稿，唯讀PE／Capstone5.0.9核對選定片段。
[驗證器](../verify_legacy_login_sources.py)加
`--tutorial-pose --tutorial-npc-formation --tutorial-first-battle`，
[125片段／40限定windows](evidence/S00-20261101-TUTORIAL-FIRST-BATTLE-RECHECK.json)符合。
這不是REA整函式重分析、完整CFG、T01 FULL-PASS或官方Server回覆配對證據。

- 基本slot+1C4指4B1BF0（候選38）；既存來源讀type、map與group。
  舊type6沒有實際B0的紀錄不能用合成B0補作證明。本輪候選為type2/map190/group14。
- 候選5F/type2會走SCEF替換場景的歷史路線，可能使TUTO專用完成通知失去接收者。
  本輪不用5F或6E重建場景，也不移植舊Client保留TUTO修補。v1等待B0的前提已被反證，
  v2在正常編隊確認後連續送38、12地圖及角色／啟用資料，不再等B0。
  TUTO是否完整保留及正常返回仍須本輪遊戲實測。
- 基本slot+A4指4C5930（候選14），它派current-scene virtual+2C；TUTO vtable
  對應4B2570，其controller+4設1。不是直接寫controller+DC，亦不重跑TUTO初始化。
- TUTO在4C4AED登記scene-local4C→4C4F20。後者讀payload+2 scenario u16，
  呼叫4C2880查表並設完成1。**這不是QuestInfo14、獎勵或整個教學完成。**
- 0D的4B01C0讀actor、direction、motion與float；游標與9B記錄增量已核。
  舊「float是開始時間」說法不採用；候選採速度倍率1，不能沿用凍結動畫的0。
- 126／127／12C登記與row消費已限定核對：126為role byte與4B技能列；127另有
  preset/enabled；12C為role DWORD、selected byte及+8可用preset列。這證明消費形狀，
  不證明官方何時學技能、預設ID或冷卻／傷害政策。
- 70登記4E2400→509A80；既存偽碼有6B header、15B裝備列及slot／serial／item欄位。
  F9／FA外觀與revision、0F命中其餘欄位沿用舊候選，這輪未完成上下游語意核驗，
  保留PARTIAL，不能因傳送成功宣稱全欄位已證。
- Monster virtual+5C仍指4C8C40，actor第三float用scale1；不移植舊Client scale guard。
- **B0不是已證明的map-ready ACK**：帳號slot+744指4E40A0（候選E8），status+2為1
  時送2 bytes的B0；419070也有另一B0 sender。既存encounter-trigger-messages-audit已記錄
  status／cash-shop來源與非完整caller inventory限制。本輪重核這兩個sender片段，
  不把初次world碰巧收到B0或舊synthetic B0稱為戰場載入協定。

舊`anal/47-new-expedition-reference.md`、技能catalog與本機Server只供候選參考。
尤其`anal/tutorial-native-skills-v19.json`是歷史修改工作副本的ReadProcessMemory結果，
不是本輪唯讀資源或原始執行檔證據。技能ID、motion時長、位置及balance均分開標示。
沒有執行任何舊附加／注入／讀process工具，沒有修改Client或資源。

## 資源限定證據

[首cluster核對器](../inspect_first_tutorial_cluster.py)輸出
[metadata-only證據](evidence/S00-20261101-FIRST-TUTORIAL-CLUSTER.json)：
Field.stp SHA `18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a`，
CLUST_scenario_town000_01的set0/cluster1為OBJECTID1036、PRE1、COUNT1；
CHART_scenario_town000_01為map190、percent100。
**COUNT1只是一個cluster invocation，不足以證明Scenario14總共只有一波／一隻。**
該archive無MEF member不代表所有遊戲archive均無MEF；出生trigger／配置／總波數未知。

既有bounds核對器增加可選`--extract-battle-bnd`，只寫不存在的新輸出。
scenario_town000.bnd SHA
`7c98d3d5c5512cfe20f2946abc27c1c94424474ee6450fa3593693a4c5139bfc`，
768×768靜態兩層，C# reader確認候選玩家368/272、敵人376/272皆clear。
這些出生點是Server候選選擇，不是官方配置；不把靜態BND當作動態barrier。
原始資源不隨報告公開。

## Server規劃與本輪候選

| 段落 | 本輪開發 | 尚未完成／不能宣稱 |
| --- | --- | --- |
| 編隊確認 | 同connection已準備40/14，精確28/13B且role為已取得1/3/4；維持預選4 | 其餘欄位語意／官方編隊限制PARTIAL |
| 裝備準備 | current-lease同DB交易持久化固定starter kit，再送38 | 正式inventory、消耗／替換、原版裝備政策 |
| 載入 | 編隊確認後連續38、map190、actor／技能／裝備／bind、14、monster1036 | 不造B0 ACK；實際地圖／UI／輸入仍待驗收 |
| 普攻／技能 | Server單調時鐘、方向／距離、action deadline、damage／HP／死亡 | AI反擊、完整技能條件／成本／波次未完成 |
| 勝利／返回 | Server encounter判勝後同DB lease核對寫時間，再map188恢復保存位置、14及4C/14 | 玩家ACK不直接授勝；Quest14/16、獎勵／廣場另做 |

新opt-in `LOCAL_WORKING_COPY_TUTORIAL_FIRST_BATTLE_CANDIDATE`需要walking與battle
pinned bounds、既有expedition component，以及顯式離線tutorial component v1。
Host只驗證不自動遷移；global SQLite user_version仍2。component含progress revision／
first_battle_completed_at與account/role/slot裝備，FK既有ownership，不重置既有角色。
這只是首戰標記，尚無active-run／完整Quest/resume權威，不能拿來略過其餘任務。

單敵HP60、普攻20／X35／組合60、範圍45/65、impact200ms、清怪後750ms返回、
技能ID及冷卻／動畫時長是明示Server prototype政策，**不是還原完成的官方戰鬥規則**。
目前敵人靜止，無AI反擊、玩家受傷、成本、完整波次或獎勵；這些仍是正常流程開發缺口，
不因本輪合成通過就刪除E17相關要求，也不以跳教學／假Quest完成交付最終目標。

## 驗證與本機發布

13個HappyPath cases通過（5旅程rows、仍9方法／總207方法，198暫緩）。首戰列採
temp SQLite、all-clear bounds及可控單調clock：正常28後無B0亦收到地圖／裝備／skills、
三次普攻、HP67→33→0、Server勝利寫DB、返回保存位置及4C/14。
**它沒有執行Client，不證明實際戰場可玩。**

09:45:45 UTC本機換成first-battle-v1 Host，已有一致性SQLite snapshot並顯式遷移。
DLL SHA256：Network `0cd3613aec94019a420a301a07b0275749277082b0c1bfc930dbe77411a64984`；
Persistence `935936583fbd7769753066c11080d79ebb06d332d0aead0bacd52221b28c40e8`；
Protocol `0ac12506b88cc1f81446d33b12920ef7e18937cb3a0f3ea547579f342c183ea2`。
這是以私庫38a3ae3為基準的working-tree build。Client SHA仍
`6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`。
首輪人工回報「確認編隊後卡住／沒有進戰場」，另附圖確認仍是入場設定頁；圖SHA
`60e90a31491fb13d93a717f5295295571c1e935e9f24f3b20d852137adc72e9b`，原圖只留本機。
09:47:52.3440622 UTC觀察到C2S28/13B，09:47:52.5203–.5205寫出14/9/16/13B
raw frames（停止／位置及38載入候選）。之後仍有heartbeat，無新B0，使用者無法進場。
後續09:47:56與59的重按才Unavailable；不能把它們誤當第一次確認遭拒。
資料僅opcode／長度，未記body；第一筆選擇被接受及38已送有程式／長度對應，
不冒稱Client內部控制器狀態已讀取。

**根因是Server候選將B0誤當必需載入ACK，導致必要map／actor資料永遠等不到。**
v2在已授權28處直接送同步map12及初始化，保留TUTO；不偽造B0、不解除角色驗證、
不使用E8/status1誘發無關B0來冒充載入完成。13正流程重測通過。
09:58:51 UTC換版first-battle-v2，無新migration；實際重測結果待回。
v2 Network DLL SHA `3bfcd1e9cf6e7c12bce3c014ee5d517364b07044608bbd498d48c9bbeb41d8d9`；
Persistence／Protocol保持上列SHA。需求檢查14REQ／13runtime／0approved；30項治理
格式／來源檢查通過，這些不是新增Client或Server異常流程測試。
v1的測試成功只代表當時會回應合成B0，保留為不足證據，不能寫成首戰已通過。

### v2人工結果：地圖已換，UI／換場流程未完成

使用者確認「進場了但編隊頁還在」，並指出原版應有換場畫面，目前只有停頓後直接進場，
這在舊本機開發時也曾回報。新增截圖SHA
`3349e67246149bd9d4ce643150e8d687d8b3e134355dcbbd1e3795e48c5bf65b`；原圖留本機。
畫面可見戰場位置與敵人、入場設定對話框仍開著，不能宣稱角色已可正常戰鬥。
REQ-0014追加這筆GAME_RUNTIME_OBSERVATION及換場／關閉編隊頁驗收；不複製同義需求。
10:00:58.9155638 UTC觀察28/13B，隨後C8/C9與B6/10B；只記metadata，不推論B6為ready ACK。

**v2只解除了Server等待，未恢復完整原生場景／UI切換。** 下一版須核對loading state、
編隊頁生命周期、controller與TUTO coroutine的交接／返回；不能只送map12、加人工延遲、
模擬進度條或直接刪Client UI來掩蓋。舊5F2能建立SCEF controller/page7，但替換TUTO；
舊補丁保留TUTO的方案不採用。須同時設計有來源的進場與返回，不能先換SCEF再重播整段
教學冒稱resume。當前Host保持v2供證據定位，不再要求使用者在遮擋頁面下強行攻擊。

離線補讀Event/TutorialMain.lua（member SHA662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809）
確認root重設g_TutoEmployCharQuery／g_isTutorialRunning並重建entry函式；4A8A60清相關
執行狀態再載入entry。這是不能隨意6E重新初始化的補充警訊，不是已完成可恢復戰鬥契約。
目前Event.stp SHA2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b，
可能含歷史本地翻譯；只離線解析metadata，沒有執行Lua，也不將它當未修改原始資源驗收。

下一步按實際進場證據修正，再完成AI／戰鬥及Quest14、Quest16、離場／廣場；完整新帳號
旅程仍未達成。Replay／重登／競態／失敗／安全與壓測等只記待測，現在不執行。
