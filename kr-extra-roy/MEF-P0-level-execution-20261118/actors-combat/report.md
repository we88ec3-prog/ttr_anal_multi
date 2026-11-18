# P0-3 生怪與 P0-4 戰鬥完整能力分析

## 1. 結論與本輪終點

**MEF 已能編排生怪、巡邏、追敵、返家、依條件選招、命中、扣血、死亡與波次結果；現有 Server 實作提供了其中大部分規則執行服務。** Client 同時已有世界物件、動作與投射物的逐幀呈現能力。本輪把二者可接合的資料、ID、型別、生命期及剩餘 adapter 分開列明，沒有把「由 Server 執行」當成 MEF 不處理的理由。

本輪新增三組實質補證：

1. **本地 `lb.CreateObjectEx` 與 `0007` 封包生怪的初始化差額。** 兩者都能建立 `CMonster`，但 ID、group、relation key、variant、HP 表示及 controller 組合不同；另找到 `0000` selector 29 的確切 group writer。
2. **實際 Server 原碼的生怪與戰鬥執行鏈。** 不再只引用分析庫中的設計稿；固定 `e88ac0ad5fd6e911b28b1e61b6eedab3bfdfb4b4` 核對出生、攻擊選擇、傷害、死亡、波次 HP 與投射物服務。
3. **`0094 → CBullet` 的完整有界原生鏈。** 從封包欄位、同世界 owner、RTTI／vtable、方向／目標／座標飛行、動畫時計，到 `001A` 收尾／清除；並追到原 `Table/Blt2.blt` 的 228 個 Type 及其模型鍵／效果名稱 consumer。

P0-3/4 的**能力與整合需求分析**至此可交付；新內容、投射物視覺 adapter、選用的普通場景 Lua 觀察橋及完整 Client 自主敵方 AI 仍各有開發／驗收項目。最後兩項尚未證明有可直接套用的原生通路，不能寫成已實作或正式 RR-0013 已結案。這些選用路線不阻塞現有 Server 規則 MEF 做完整關卡。[能力與剩餘契約](capability-contracts.json)

### 來源與證據等級

| 層次 | 固定來源 | 本包採用方式 |
|---|---|---|
| 原生 Client | KR `02-Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` | 原 bytes、PE 位址映射、機器碼、RTTI／vtable、欄位及呼叫鏈。 |
| 原資料 | `07-Table.stp`，SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` | 只讀解碼 `Table/Blt2.blt`；不生成或改寫遊戲資源。 |
| 既有研究／內容 | 分析分支 `extra/roy1` 基線 `19005c9f8a8180e6f0deb00faf008a11ef98023f` | 復用已證子鏈；反編譯只作導航；authoring JSON 全量 schema／關係檢查。 |
| 實際 Server | 私有 `ttr_server_roy` commit `e88ac0ad5fd6e911b28b1e61b6eedab3bfdfb4b4` | 唯讀檢查具名類別／方法及語意；完整實作不發布到分析庫。 |
| 本輪建議 | 本包 JSON／本報告 | 明標 adapter、內容政策、優化及驗收需求；不當成既有 native API。 |

全部精確路徑、blob、bytes、SHA256 在 [source-manifest.json](source-manifest.json)。文中 B／D／R 編號對應 [native-evidence.json](native-evidence.json)；可讀機器碼見 [native-evidence.asm](native-evidence.asm)。包內的 `NATIVE_STATIC_CLOSED` 只表示本包有界主張的靜態鏈，不是 T01 FULL-PASS、S00 ACCEPTED 或遊玩通過。

## 2. P0-3：先分清四種角色，再接完整生怪

### 2.1 哪些物件能做什麼

| 路線 | 真正建立／操作的對象 | 玩家用途 | 能復用與需補的部分 |
|---|---|---|---|
| Q 演出角色 | Q 的演出 slot／`CEventActor` 域 | 走位、入場、動作、轉向、配合鏡頭與對話 | 已有演出 consumer；slot 與普通 world ID 分開。不能用 Q 全停止當敵人全死。 |
| `lb.CreateObjectEx` | model 10..10000 可進 `CMonster`；普通 world tree | 本地建立可更新／播放動作的怪物本體 | 同一世界 owner 與 frame 可用；明確 ID／配置、控制及終端事件仍需所選 local adapter。 |
| `0007` 普通 world actor | ID low byte 1 對應 `CMonster`，由封包給身分與配置 | 現有 Server 怪物、增援、頭目及後續封包更新 | 現有 Server `Spawn`／`SpawnReinforcement` 已使用此路線；是可直接復用的執行底層。 |
| 真正 Tutorial context | 三個角色槽、教學條件及其 controller | 教玩家移動、攻擊、切換角色，等待指定教學條件 | 教學 consumer 有自己的 owner；不能把其固定角色判斷當普通怪物 HP／死亡觀察器。 |

前兩輪已證的 Q、Tutorial、controller 事實沿用 [world-offload](../../MEF-server-provided-capabilities-20261118/world-offload/report.md) 與 [world-lua](../../MEF-P0-P1-master-continuation-20261117/world-lua/report.md)，不重算為本輪新發現。普通 world 建立與初始化則以 B01–B08、B35、D05、D15 重驗。

### 2.2 本地與封包初始化不能互相代換

`4A0F70` 的六個參數是 model、位置、scale、方向及 attach；model 10..10000 經 `4D1710` 建立 `CMonster`。`0007` 的 `4AE4D0` 由 ID 的 low byte 做 factory dispatch，type 1 的表項 `4AED94 → 4AE671` 同樣呼叫 `4D1710`。共同類別不代表共同初始化。[B03、B04、B35、D15]

| 欄位／階段 | 本地 `CreateObjectEx` | `0007` CMonster 路線 | MEF 對接含意 |
|---|---|---|---|
| world ID `actor+4` | 取程序級 counter 的 low WORD；函式之後遞增 counter | row+0 的 u16 | 本地 ID 需要回傳／映射或顯式配置；不能用 Lua 呼叫次數假定身分。 |
| 模型 `+88/+8C` | class／model compound；本路線沒有封包 PRE 參數 | low-byte class、`pre-1` 與 model 組合 | 應保留 type／model／pre 的 domain；不能把 Q model key 混用。 |
| group `+90` | 基礎建構值 127，六參數沒有此欄位 | row+24 的 byte | 已有後續 setter：0000 selector 29；需先有正確 world ID。 |
| relation key `+9C` | 基礎建構值 0 | row+18 的 u32 | group 與 relation key 是不同欄位；目前 local API 未提供同等設定。 |
| variant `+424` | 完整 `CMonster` 建構 body 與本地建立 body 未見顯式初始化這一欄 | row+23 的 byte，建模前寫入 | local profile 應補確定性初始化，不能把未見 writer 當固定 0。 |
| `+428`、`+41C` | 建構預設；本地沒有同等 packet metadata | variant==4 派生 `+428`；`+41C` 取 actor 資料 | 是呈現／actor metadata；不自行證明敵方決策。 |
| 初始 FSM | 本地明確 state 1／motion 1 | row+25 決定 state，之後建模 | 出生設定必須和出場／待機／可受攻擊規則一致。 |
| 移動 base `+CC` | 本地建立後設 60.0 | 現有 Server 另外送 0000 selector 5／6 | 場上移動速率要和 Server 判定速率配對。 |
| controller | attach 只呼叫「當前」controller 的既定 vtable 方法 | 普通怪物不因封包到達就獲得新的 Client 敵方 AI | 要看實際 controller／decision producer，不能以 attach 成功推論已會追擊。 |

以上是實際 writer／參數差額，不是要求復原官方 MEF。新 Server 提供的 MEF 可直接把出怪描述交給已存在的 `0007` 路線；若確實需要本地建立，才實作明確 ID、metadata、control 及觀察 adapter。

兩個既有身分限制仍需保留：`4DFF30` 不以重複 ID 取代原 actor；`0007` 查到既有 ID 後跳過整列。因此用相同 ID 再送一次 `0007`，不能當「接管本地怪／補齊配置」。本地計數器也不能宣稱是每副本獨立、不會碰撞的 allocator。[既有 identity 證據](../../MEF-world-integration-20261115/identity/report.md)、B04

### 2.3 新閉合：group 有封包 writer；正速度需要 signed 16-bit 限制

`0000 / 4AFAF0` 是 header 2 bytes、每列 6 bytes：world ID、selector、value。它由同世界 ID 找物件後呼叫 `v+2C`。對 `CMonster`，vtable `C0C9DC+2C → 4D1E10`，jump table 與 case map 的完整非預設分支如下。[B26、B27、D01、D05]

| selector | native branch | 實際 writer／用途 |
|---|---|---|
| 1 | `4D1E34` | `+3B0`，並更新 normalized HP bar。 |
| 5 | `4D1EFC` | signed16 → `+D0`，速度百分比因子。 |
| 6 | `4D1EB5` | signed16 → float `+CC`；首次另存 base 到 `+394`，後續更新比值。 |
| 23 | `4D1E6B` | `+3D4` 與名稱的等級顯示；不由此推論 HP／傷害成長。 |
| 29 | `4D1F0B` | signed16 → `+90` group。 |

所以「ordinary group 完全沒有 Client 設定入口」不成立。group setter 也沒有自動呼叫 `v+64` 重建 bar style、選取敵人或發出攻擊；`4C9580／4C6F60` 是關係查詢／bitmask 解析，`4D1F90` 消費關係與 variant 設定血條樣式。不同 consumer 對 127／找不到關係資料的處理不同，不能由 local group 127 單獨斷言「一定不可攻擊」。[B06–B08、B27]

**明確 Server 開發需求 AC-SPEED：**現有 schema 與 typed `ushort NativeMovementSpeed` 可接受到 65535，但 native selector 6 在 `4D1EBC` 使用 `movsx`；32768..65535 會被解成負數。對正常正速度，MEF 內容與 mapper 應共同限制 `1..32767`，或另訂明確可證的編碼。原 corpus 的 17 個 profile 出現都用 12 或 18，所以這是新增內容的範圍漏洞，不是聲稱現有 17 列已失效。[B19、B27；實際 `LocalMonsterBehaviorProfiles.Validate`；behavior-audit]

### 2.4 HP 有兩種表示，不能拿建構值當戰鬥真相

`CActor` 建構前段把 normalized 欄位 `+3B0/+3B4/+3B8` 設 0，六個 absolute resource 欄位 `+3BC..+3D0` 設 100。`CMonster` 初始型別標記為 1。這些是物件初始化值，不是本關怪物真正的 max HP。[B02、B03]

已證 `0000` selector 1 更新的是怪物 normalized HP；`0034` 才有 typed absolute resource writer。實際 Server 的敵人 HP 在 `EnemyAgent.Health/MaximumHealth`，`Spawn` 另送 normalized 10000；挨打後按 Server HP 比例更新 normalized bar。這條現有路線不需要假造「Client absolute 100 必定等於怪物實際 HP」，也不能從 Client 比例 getter 得到可靠死亡事件。[B26、B27；既有 world-lua 報告；`LocalTutorialCombat.Spawn/ApplyEnemyHit`]

## 3. P0-4：現有 Server 戰鬥能直接供 MEF 編排

以下來自固定版本的**實際程式**，每份檔案均有 bytes／Git blob／SHA256 pin。完整 C# 留在私有來源，分析庫只保存方法、欄位及語意。這不是本輪執行過 Server 的聲明。[source-manifest](source-manifest.json)

| 階段 | 現有落點 | 可供 MEF 使用的行為及精確界線 |
|---|---|---|
| 出生資料 | `LocalEncounterSpawn` | Model、X/Y、Pre、AiProfile、Patrol、DefeatExperience、MaximumHealth。Patrol 可驗證點數、可走路徑及 leash 內的完整回程。 |
| 個體建立 | `ResolveBehavior`、`Spawn`、`SpawnReinforcement` | `AiProfile` 覆寫／繼承；個體 max HP；ID 使用 `((ordinal)<<8)|1`。新波追加 actor，死亡動畫仍在時不重用舊 ID；新怪只有自己的 warmup，不重設舊怪節奏。 |
| 接敵 | `UpdateEnemyEngagement` | aggro 以當前怪物為圓心；leash 以出生點為圓心。正傷害可喚醒未接敵怪，返家中的怪保留返家承諾。 |
| 巡邏／追擊／返家 | `PollEnemies`、`ReturnEnemyHome`、`FindMonsterRoute` | 閒置巡邏、追逐、回出生點；逐步檢查 bounds。有限 detour 查找存在，4096 格上限；不是無條件任意地圖導航。返家繞路目前有 patrol 條件，不能泛稱全部怪永遠會繞牆回家。 |
| 攻擊選擇 | `ChooseEnemyAttack`、`HealthAdmits`、`AttackReady` | 從 cursor 起選第一個 HP 區間、距離、獨立 CD 與投射物容量都合格的招；成功出招才推進 cursor。低血招式列在候選表，不等於每次低血都強制使用。 |
| 群體節奏 | `LaunchEnemyAttack`、`PollEnemies` | encounter 級攻擊間隔、怪物輪替；其他存活怪仍可移動。前搖、後搖、招式 CD 分開。 |
| 近戰命中 | `PollEnemies` 的 `ImpactAt` 分支 | 前搖到期重新讀距離與攻擊路徑；符合 hitRange 才傷害。播放攻擊動作本身不判定命中。 |
| 玩家受傷 | `ApplyIncomingDamage` | 防禦服務、裝備防禦與成長；physical／magical／mental；受傷、恢復、HP／資源同步及死亡收尾。 |
| 怪物受傷／死亡 | `ApplyEnemyHit` | Server 扣 HP、發 hit 回饋／比例；HP 0 清 pending attack／控制狀態，播放死亡動作，排延後移除；正傷害擊倒觸發經驗／擊倒通知／掉落來源。 |
| 波次觀察 | `ReportWaveHealth`、`MonsterAgents` | waveId 對應成員區間，回報 current／maximum health 變更；runtime snapshot 有 HP、phase、active attack。這些已存在的 Server 事件／狀態可先接 MEF。 |
| 清場與返回 | `ReadyToReturn`、`ReadyToClearMissionNode` | 保留全部應生成波、HP 0、玩家存活、等待到期、敵方飛行結束、適用頭目條件；mission node 額外等所有敵人的 removal 已排送。最終各關卡 consumer 差異由 rules/gates 包接續。 |

`PollEnemies` 的現行節奏最低約 0.1 秒，單次移動時間上限 0.25 秒；碰撞位置、追擊／選招仍由 Server 計算，Client 收動作與位置作呈現。把這些規則寫成 MEF 會減少逐關硬寫邏輯；**CPU 外移則只計算真正交給 Client native 執行的工作，不能把資料化本身算成 Server 算力已下降。**[實際 `LocalTutorialCombat.PollEnemies`]

### 3.1 現有戰鬥資料的全量稽核

本輪固定分析基線中的全部 `design/scenario-content/*.monster-behavior.json`：8 檔、17 個 profile 出現、11 個不同名稱；相同名稱可存在於不同版本／案例檔，沒有把它們錯當全域重複。所有文件均通過現有 schema，加上依固定 typed loader 規則重建的靜態關係檢查；未執行 Server loader。[behavior-audit.json](behavior-audit.json)

| 文件 | profile 數 | 玩家可理解的內容 |
|---|---:|---|
| `example-attacks` | 1 | 一般招與低血近距離招，獨立冷卻／血量條件。 |
| `example-leash` | 2 | 原有近戰與會接敵／脫戰返家的示範。 |
| `example-projectiles` | 1 | 固定位置的直線投射物攻擊示範。 |
| `functional-lab-v93` | 2 | 接敵返家與固定位置怪，特定測試版本。 |
| `functional-lab-v94` | 2 | 調整接敵／leash 的測試版本。 |
| `functional-lab` | 3 | 返家、固定怪及血量階段靶。 |
| `phindos-stage1` | 4 | 一般怪、頭目與狩獵場配置。 |
| `story-q119-patrol` | 2 | 基礎怪與巡邏／接敵配置。 |

其中 7 個 profile 出現有明確 aggro+leash、5 個禁止追逐、2 個使用顯式招式列表，共 3 招，含 1 招 HP 條件及 1 招投射物。驗證還檢查 `followDistance < attackRange <= hitRange`、前搖≤後搖≤CD、aggro≤leash、招式 ID 唯一、HP 區間排序與投射物最大距離涵蓋出招距離。這是靜態內容可接受性，不是 17 個 profile 已全部實機驗收。

## 4. 新閉合的原生投射物鏈

### 4.1 入口、型別、owner 與欄位

common registration 的 `4ADFCD` 把 `4AF1F0` 寫入 handler map `+0x4A4 = 0x0094*8+4`。`4AF1F0` 按 header 2 bytes、每列 24 bytes 處理：先檢查 bullet ID 未存在，配置 `0x138`，呼叫 `4CBFF0`，以 source ID 找同世界 actor；source 存在才複製 `+9C/+90`、完成設定、初始化，最後 `4DFF30(&FAB130)` 插入。重複 ID 跳過；source 缺失不建立可用世界 bullet，也沒有等待 source 的 pending queue。[B09–B11]

RTTI 的 `.?AVCBullet@@`、COL 與 ctor 安裝 `C079FC` 互相對上。這不是由效果名稱猜出的類別。關鍵 vtable：`+20→4CC150`、`+24→4CC540`、`+2C→4CFE50`、`+30→4CC5D0`、`+14→4CC850`、`+00→4CC0D0`。[B11、D02–D04]

| 0094 row offset | 型別 | 消費方式 |
|---:|---|---|
| 0 | u16 | 來源 world ID，必須已存在。 |
| 2 | u16 | 新 bullet world ID。 |
| 4 | u16 | metadata Type，進 `+10C`，查 Blt2 的曲線／額外效果資料。 |
| 6 | u16 | visual Type，組成 `0x02000000 | value` 的模型鍵。 |
| 8、10 | **signed16** | 起點 X/Y，轉 float。 |
| 12 | f32 | scale，呼叫 `v+5C`。 |
| 16 | u8 | 方向。 |
| 17 | u16 | 毫秒數／1000.0，寫 `+130` duration。 |
| 19 | u8 | 1：world target；2：固定座標；其餘走方向分支。本契約保守選 0 表示方向。 |
| 20 | u16 | mode 1 是 target ID；mode 2 是**unsigned16** target X。 |
| 22 | u16 | mode 2 的**unsigned16** target Y；mode 0／1 的此值不作同等目標座標。 |

Server adapter 應精確產生 `2+24*n` bytes；正常正 duration 限 `1..65535` ms；不要把負座標 wrap 成無符號 target。兩個 Type 是不同欄位，原生沒有強迫兩者相同；採相同值可作本專案的清楚預設，但要明標內容政策。[B10；capability-contracts]

### 4.2 原資料來源也已接上

`82BB00` 的 literal 是 **`Table/Blt2.blt`**，不是猜測的 Bullet.xml。原 `07-Table.stp` 存在此成員，block 919，stored offset 3,065,872、length 76,528，decoded SHA256 `8fbc0c8d7ad5b43189f0858adff2d22a2945734dd553813027df1d614913bde0`。內容為 EUC-KR XML；只讀解析得到 228 個唯一 `Bullet Type`，連續 1..228。[B28、D12；bullet-resource-audit]

兩個已證 producer 使用同一 parser：

- startup `48CAAC..48CAF3` 清空並把 `FBAAE0` 傳給 parser；`FBAAE8` 是後續 `CBullet` 查曲線、地面／收尾效果的 tree sentinel。
- `4F5320` 另外讀入同表；`4F5486..4F5498` 將 Type 組成 class 2 model key，`4F5551` 寫 actor record `+38` 的效果檔名。`551FF0` 以同鍵 lookup，再從 `+38` 取名稱交給效果建立路線；class 2 不走 class 3 的額外副檔名拼接。

所以 0094 的 metadata Type／visual Type 已有原資料及同鍵 producer／consumer，不再是沒有材料來源的欄位。[B28–B34、D12–D14]

| 宣告項目 | 原表數量 | 意義 |
|---|---:|---|
| Bullet Type | 228 | 可選的宣告鍵；不等於 228 種傷害規則。 |
| 非空 main effect | 156 | 有主體效果檔名。 |
| 非空 ground targeting effect | 8 | 有地面瞄準效果宣告。 |
| 非空 impact effect | 119 | 有收尾效果宣告。 |
| Curve | 170 | 明確的 Altitude／Pow；其餘走 parser 的預設，不應假設一律平直。 |

例如 Type 22 有主體、地面及收尾效果，Curve 的 Pow=0／Altitude=50；Type 43 是 Pow=1／Altitude=0；Type 48 的 main／ground／impact 名稱都為空。這些例子直接顯示「有 Type」仍要按內容選對外觀與終止效果，不能一律當作可見飛彈。少量原欄位對照保存在 [bullet-resource-audit.json](bullet-resource-audit.json)，沒有把整個原表複製進 Git。

`Speed`、`Lifetime`、`Radius`、`SplashRadius` 的 XML 宣告會被 parser 讀入，但所追 `CBullet` ctor 只從 metadata node `+90/+94` 複製 Altitude／Pow；`0094` 與 `0000` 另給 duration／speed。**原表半徑或 Lifetime 存在，不代表這組 Client body 已會做傷害、碰撞、AOE 或自動回收。**所選效果的 payload／掛載及實際畫面仍列整合驗收，並非缺少官方 MEF 的停止條件。[B10–B13、B28、B29]

### 4.3 三種飛行模式與時計

world step 既有 `491CAF → 40F060 → 4E0060 → 4E13F0 → actor v+20` 遍歷同一 tree，所以新建 CBullet 進入普通 frame 更新。另 `4925A5 → 4E0200` 以 delta 枚舉同 tree；`AnimateExecuter` callback `C0CF2C→4E0520` 由 worker `6EE540` 取 stride 12 的 object，最後呼叫 `object v+24(delta)`。這補齊 CBullet 的位置與 elapsed 兩條 producer，而不只列 vtable 地址。[R_frame_world_step、R_world_step、R_world_step_iterator、B21–B25、D08]

| 模式 | `4CC150` 的已證行為 | 精確限制 |
|---|---|---|
| 方向 | 依方向表、`v+60` 速度與本地 frame 設定步進 X/Y | 基礎 constructor 的 base speed=0；需用 `0000` 的 selector 5／6 供速度。duration 到期不停止此分支。 |
| 目標 ID | 每次以 `+128` WORD 找 target，取其位置；target 不在則用先前 cache | 是畫面追隨目標位置；不等於 Server 傷害已改成追蹤彈。若一開始就沒 target，不能假定已有有效 cache。 |
| 固定座標 | 使用 +128/+12C 的 float target X/Y，取地面高度 | wire target 是 unsigned16；位置範圍與出生點 signed16 不對稱。 |

後兩種使用 `t = elapsed / duration`，沿起點至目標插值，橫向權重為 `t^(Pow+1)`，另加 `sin(t*3.1400001049)*Altitude` 的高度項。沒有 metadata 時 ctor 的 Altitude／Pow 是 0；有資料但缺 Curve 時應沿 parser 預設解讀，不能和 missing-record 混在一起。[B11、B12、B28、D11]

`4CC540` 增加 elapsed 並夾到 duration，同時更新主／地面效果；函式沒有 world erase、HP writer 或 Lua callback。`4E0200` 還可能縮放傳入的動畫 delta，故這個時計不能當 Server 戰鬥期限或命中確認。[B13、B22]

### 4.4 終止、命中與來源死亡分開

`001A / 4B28D0` 對 low byte 2／8／9 的物件先看 CBullet 欄位：目標模式、尚未收尾，且 elapsed/duration > 約 0.6 時，呼叫 `4CC8B0` 播放一次目標位置的 optional impact effect。之後共通 `4DFBC0` 呼叫 cleanup v+14、刪除 v+00、移出 tree。`4CC850` 停止／釋放主及地面效果。[B16、B17、B20、B36、D10]

這給 Server MEF 一個明確的終止出口；同時帶出三項對接條件：

1. duration／畫面抵達不會自動刪除 bullet，方向模式尤須在 Server 的 hit／block／range／lifetime／cancel／場景結束時送 `001A`。
2. 該 impact visual 由終止比例與 mode 觸發，不讀 Server 的「真的打中」原因；在超時或場景清理也不能拿它當傷害事件。
3. bullet ID 應另分配已知型別的安全生命期，保守選 low byte 2，與來源怪物 ID／Server flightId 分開；遲到、重複與轉場通知依 run/generation 處理。

## 5. 與現有 Server 投射物對接的精確範圍

`LocalMonsterProjectiles` 已有容量 256 的 **Server 非追蹤直線飛行**：前搖完成時才 Launch；方向在選招時固定；依單調時間推進，夾 range／lifetime；用移動玩家的相對掃掠圓及靜態 bounds／遮蔽處理命中，單次命中後移除。傷害走既有防禦／HP 服務。[實際 `LocalMonsterProjectiles`、`LocalTutorialCombat.Attacks/Projectiles/PollEnemies`]

已發出的飛行會繼續存在於來源死亡／返家之後；未發出的 pending attack 可被死亡、stun、leash 取消。`PollEnemies` 延後刪除仍有 active source flight 的來源怪，清場也等待敵方 flight 結束。這些生命期已存在，新的 visual adapter 應復用。[實際 `LocalTutorialCombat.PollEnemies/ApplyEnemyHit`、`LocalMonsterProjectiles.HasSource`]

**目前這份實際 Server source 明確沒有 native missile entity／flight visual packet。** 本輪找到了可實作視覺 adapter 的原生落點，沒有替 Server 加上 mapper。建議契約：

| Server MEF 狀態 | Client 呈現對接 | 必須保留 |
|---|---|---|
| 接受出招／前搖 | 既有 000D ActorAction | 已選招式、方向、前搖 deadline、instance。 |
| flight 正式 Launch | 新 0094；方向模式補 0000 selector 5／6 | flightId↔nativeEntityId↔generation；source 已生成；Type／效果版本；座標與時間範圍。 |
| 飛行中 | native v+20/v+24 自己更新畫面 | Server 仍按既有 swept collision 判定；必要校正不改變傷害語意。 |
| hit／碰壁／距離或壽命到期／取消 | 既有傷害結果與新 001A 回收各自處理 | 一次 hit、一次 terminal；impact visual 不作勝敗事件。 |
| source 死亡／場景結束 | 復用現有 source-flight 尾段及 scene 清理 | 不提前重用 ID；跨場景 generation 不承接舊傷害／物件。 |

方向模式最貼近目前非追蹤直線規則。若選 target 模式，Client 畫面會重新追 target 的位置；需要在內容中明確標為視覺選擇，不能暗中改成追蹤傷害。若希望飛行時就因目標移動改變碰撞軌跡，應另立 Server MEF 攻擊模式，不能把本輪視覺研究當它已實作。

負載方面，native 更新可避免新做「每畫格都由 Server 派送投射物座標」的呈現設計；現行 Server 本來就沒有這種 flight visual 封包，因此本輪**不聲稱現有封包量或碰撞 CPU 已降低某個百分比**。可先增加低派送量的完整視覺，再量測每 flight 的封包數、校正率、active flights、判定耗時及效果回收延遲。

## 6. 尚未閉合的選用 Client 路線與解除條件

本節保留真正 Client 未知，沒有把 Server 自訂規則未知混入。

| 未知／需求 | 已查範圍與排除路線 | 精確下一個證據或開發材料 |
|---|---|---|
| 普通 CMonster1036 自主敵方 decision producer | 本地／0007 ctor、world frame、Single／Formation controller、SubAI model<=9 gate；既有 000A supplied-relation follow、reset／display 候選。跟隨既給 target 不證自主找敵／選招。 | 一個把 ordinary monster instance 綁到具體 decision agent 的 assignment，接到它的 target／direction／skill writer；或本專案明確新增控制 adapter。不能只再提供 actor frame／extra-list writer。 |
| 普通 world lifecycle → 同 run/generation Lua 事件 | 既有 ordinary Lua observer 讀集、0000／000D／000E／0034／001A 與 Q／Tutorial predicates；已證顯示、HP、死亡動畫、刪除彼此獨立。 | 可發現並核對的註冊／回呼／owner 綁定，或新增 typed bridge，攜 entityId、run、generation、sequence、HP、cause；先可接現成 Server hooks。 |
| local CreateObjectEx 完整出生契約 | B01–B05、B35；本地 counterID、metadata 差額；既有重複 ID 跳過。selector29已補正，不再列完全無 setter。 | 若選這條路，新增 ID 回傳／明確配置、variant 初始化、合法 controller 及終端事件；不以同 ID 的 0007 冒充接管。 |
| 新投射物視覺整合 | 0094／Blt2／class2 effect model／CBullet frame／001A 已證；實際 Server flight source 已讀。 | Server packet mapper、entity allocator／生命期、所選效果 payload／mount／畫面驗收；不再要求官方 MEF 或不明的「Bullet XML」。 |

正式 RR-0013 仍沿 T13 的接受範圍管理；本包不更新 RR、owner 或正式台帳。T10 的既有 000A 五位元組列之 direction dataflow 退回也未被本包偷偷判為已修；本輪沒有依賴「row4 永遠來自 B0」這個未解說法。T11 的 skill matrix consumer 同樣不冒充普通怪物技能決策 producer。[固定 RR／T10／T11 pins；既有 authority、extra-control、controller 原稿]

## 7. 玩家能理解的進度與缺少項目

| 項目 | 已分析清楚／現在底層有什麼 | 還缺什麼 |
|---|---|---|
| 生怪 | 可指定怪種、位置、出生配置與個體身分；已有普通生怪／增援服務；補清本地怪與封包怪不同的初始化。 | 新 MEF 內容接入現有服務；若選本地生成，要補身分／配置／控制橋。 |
| 怪物行為 | 已有巡邏、接敵、追人、返家、輪替出招、血量／距離／冷卻條件。 | 新怪的數值／招式配置與玩法驗收；完整 Client 自主敵方 AI 屬另一個選用開發 profile。 |
| 打中與扣血 | 已有前搖後重新驗距離、防禦、HP、死亡與結果回饋；畫面動作和真正傷害已分清。 | 新關卡串事件與內容，不需重寫整套底層；普通 Lua 若要直接觀察則補 typed bridge。 |
| 飛彈／砲彈畫面 | 新找出方向、目標、定點三種 native 飛行與瞄準／收尾效果；228 筆資源鍵已對上。 | Server 視覺 packet adapter、ID 生命期與所選效果畫面驗收；不能說目前已全部在遊戲中顯示。 |
| 打完敵群的依據 | 已有 Server HP／擊倒／波次回報及待移除／飛行尾段狀態。 | 由 P0-5 等上層編排接清場／門／出口；不能把角色站住或消失當所有敵人已打倒。 |

## 8. 優化與實作建議順序

1. **先接現有 Server 規則 MEF。** 把選定關卡的 spawn／AiProfile／attacks／waveId 對接既有服務，沿用唯一 HP、death 與 wave event；同時修正正 native speed 範圍。這是具體可開發的 P0 內容接口。
2. **把出生配置先驗證並固定版本。** model／pre／variant／group／資源 Type／行為 profile 均在載入階段檢查；每個 instance 保留配置 hash。避免每 tick 查未驗證字典或在 actor 已出現後才發現不相容值。
3. **加入 CBullet 視覺 adapter。** 優先做一組已知素材、非追蹤直線招式；完整驗收出生順序、前搖、飛行、碰壁、來源死亡、最末飛行結束與轉場清理，再擴到 target／ground modes。
4. **以事件與有限時計減少不必要求值。** HP band、wave clear、return/death／flight terminal 觸發必要更新；保留需連續移動／掃掠判定的 active actors。若改成事件索引，需維持現有 poll 順序與 deadline 語意，交由 rules 包共同設計。
5. **按玩家需要選完整 Client 自主 profile。** 先定合法 instance owner、可回報事件及失敗／重入處理，再解 decision-agent assignment。現有 Q／Tutorial／native呈現下放可先做，不需等待這條較大的改造。

以上落為 [capability-contracts.json](capability-contracts.json) 的 4 組 adapter，可用於 Server 開發／整合規劃；沒有更改原 Server 實作、正式規格或生產資料。

## 9. MEF 用途分類建議

本題可整理為「生怪與增援」、「怪物行為與戰鬥」、「投射物呈現」及「角色演出」四個功能群。投射物呈現可併入根報告的 M03 戰鬥類；Q／world 動作則由 M06 演出類交叉引用。這些是可組合用途，不宣稱原生存在四種不同 MEF 檔案格式。

玩家角度看，一份關卡 MEF 可以連起：怪物在哪裡出現、何時接近玩家、用哪些招式、飛彈如何顯示、何時真的扣血、怪物倒下後還要等什麼。Server 提供規則和結果，Client 執行已證的物件／動作／效果更新；可由現成服務完成的部分優先復用。

## 10. 驗證與交付界線

本包重驗 **54 個原件視窗、15,166 bytes、4,044 條解碼指令、65 個型別／欄位／呼叫斷言**；65 個固定 Git source pin、10 個實際 Server 檔案 pin；8 份 authoring 檔／17 個 profile 的 schema 與 typed relations；原 Blt2 228 筆的成員 hash／計數與選中欄位。`verify_evidence.py` 會從原件、固定 Git object 及實際私有檔案重建這些結果；不只相信先前 manifest 的 MATCH 字樣。[verification-result.json](verification-result.json)

未執行 Client、Lua、Server，未改原件，未改正式 RR／owner／既有研究包。本包只寫 `actors-combat/`；Git stage／commit／push 由根代理統一處理。靜態驗證 PASS 的範圍是來源與證據可重現，部署、網路時序、效果掛載、效能與玩家驗收獨立記錄。
