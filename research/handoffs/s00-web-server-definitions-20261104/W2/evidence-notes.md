# W2：Actor 1001／1009／1004 技能與 AI 欄位證據

## 1. 本次交付的適用範圍

本次完成上傳包能支持的三怪資料盤點：`ActorResource → FILE/PRE`、矩陣匯入、既有報告記載的技能／動畫引用、九類 AI 欄位的來源界線，以及可交 S00 一次抽取的小包需求。這份文件與 [monster-profiles.json](monster-profiles.json)、[monster-skill-links.csv](monster-skill-links.csv)、[required-members.csv](required-members.csv)、[unknowns.md](unknowns.md) 配套使用；逐檔來源及核對結果見 [source-index.json](source-index.json)。

本輪僅讀包內原始 XML 與既有報告，沒有重新執行歷史證據腳本、遊戲、Client，沒有新增 BIN 機器碼驗證。所有「既有報告記載」均保留原審核限制；本交付不提升 CLM／SPEC／ADR／T01 成熟度，也不啟用仍為 `DRAFT_BLOCKED` 的 T16 資料包。AI 與連段核心由 S00 處理。

使用者本輪明確指定 `extra/roy2`。治理開工核對的 `main` 為 `4875b184370f6030902460d95003fa71f8e062cd`；分析資料以包內 `MANIFEST.json` 的 `source_analysis_commit = fb6a78bf26fdfacdd5bc28ffcb1b63b011487307` 固定。兩者用途不同，不能將後來的 Git 治理基準寫成原始資源版本。

## 2. 來源完整性與版本限制

處理次序為：讀原始 bytes → 計 SHA256／長度 → 比對包內 manifest → 依 XML 宣告編碼嚴格解碼 → 解析節點、屬性及來源行號。未以替換字元掩蓋解碼錯誤，未改寫原件。

本輪整體核對結果為 manifest 所列 **130 檔 raw SHA／長度符合**；其中 **110 個 `git-evidence/` 複本**已與來源 commit 的 Git blob 核對相符。這確認檔案來源與完整性，不等於報告的全部語意已重新原生驗證。[source-index.json](source-index.json) 保存可追溯結果。

五表均位於包內 `local-resources/`，不是提交到 Git 的原資源。它們的 local variant Table carrier SHA 由 manifest 宣告為：

`ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c`

| 來源 member（包內路徑加 `local-resources/`） | 原始 member SHA256 | manifest 的原始 member 符合欄 |
|---|---|---|
| `Table/_ActorList.xml` | `b01ae70817c79126b89292567e32d4c806c3ef31478b6a2eb96dcfd21e2c78f7` | `true` |
| `Table/CharSkill.xml` | `604a22ddf9cb297bcfe14481fb8f96d2a2379dc20298fb6ac337378360947d64` | `NOT_IN_EXISTING_ORIGINAL_MEMBER_MANIFEST` |
| `Table/SkillActiveTable.xml` | `1ea831f270df757d760f4ff87d6bf509a64326a23614a305c8d767580f2a2139` | `NOT_IN_EXISTING_ORIGINAL_MEMBER_MANIFEST` |
| `Table/Skill/SkillMatrix.xml` | `8c58ea135c94dc2c6056a3e408cad76a79c1857d72e37b43e2b9b8869c897dc4` | `NOT_IN_EXISTING_ORIGINAL_MEMBER_MANIFEST` |
| `Table/IndependentSkillEffect.xml` | `a1e8be8e36a2feddf7eecaf6d006c45b1ae9e6f8b915072525f3b5f0c91e0070` | `NOT_IN_EXISTING_ORIGINAL_MEMBER_MANIFEST` |

五表宣告均為 UTF-8。四份 skill 表的「原版未核實」必須保留；此狀態不是已知 SHA 不符，也不能因同一 carrier 或包內校驗通過而改成原版相符。`_ActorList` 的 `true` 另有包內 `git-evidence/research/handoffs/kr-quest-runtime-20261103-v0.1.0/evidence/source-members.json` 可對照，但本輪沒有重新讀取它記錄的原始 STP carrier。

## 3. 三怪的 12 個 ActorResource 變體

來源 selector 形式為：

`/ACTORLIST/OBJCATEGORY[@ID='1']/ACTOR[@ID='<ActorID>'][@PRE='<PRE>']`

本表所有列的 category 都是 `1`；`SPECIES="0"`、`SHOW_MINIMAP="1"`、`SHOW_PANEL="1"` 為共同來源 literal。未據此命名 AI 種族、推斷感知行為或驗證 UI 執行結果。

| ActorID | PRE | FILE 原始 stem | NAME 原文 | SCALE literal | NAMECOLOR literal | `_ActorList.xml` 行號 |
|---|---|---|---|---|---|---|
| 1001 | 1 | `00_HokyPoky` | 홍키퐁키 | `110` | `#f8de67` | 32 |
| 1001 | 2 | `00_HokyPoky` | 성난 홍키퐁키 | `110` | `#FAAA54` | 33 |
| 1001 | 3 | `00_HokyPoky` | 커다란 홍키퐁키 | `154` | `#FF4F3D` | 34 |
| 1001 | 6 | `00_HokyPoky` | 소환된 홍키퐁키 | 屬性不存在 | `#FAAA54` | 35 |
| 1001 | 7 | `00_HokyPoky` | 굶주린 홍키퐁키 | 屬性不存在 | `#FFOO2C` | 36 |
| 1009 | 1 | `01_Moose` | 무스 | `100` | `#f8de67` | 72 |
| 1009 | 3 | `01_Moose` | 커다란 무스 | `140` | `#FF4F3D` | 73 |
| 1009 | 4 | `01_Moose` | 어린 무스 | `70` | `#f8de67` | 74 |
| 1004 | 1 | `01_Nepenths` | 네펜데스 | `100` | `#f8de67` | 48 |
| 1004 | 2 | `01_Nepenths` | 성난 네펜데스 | `100` | `#FAAA54` | 49 |
| 1004 | 3 | `01_Nepenths` | 커다란 네펜데스 | `140` | `#FF4F3D` | 50 |
| 1004 | 6 | `01_Nepenths` | 소환된 네펜데스 | 屬性不存在 | `#f8de67` | 51 |

`1001/PRE7` 的顏色原值含兩個英文字母 **O**，不是數字零。本交付保留 `#FFOO2C`，不自動修成 `#FF002C`，也未推論 Client 如何處理它。三個缺少 `SCALE` 的列不補 `100`、`110` 或任何繼承值；單位與預設值仍需 consumer 證據。

`FILE` 只有 stem。三個名稱可精確用來索引後續抽取，但本包尚未證明對應 raw Actor／ABF 的 carrier、完整 member 路徑或副檔名。因此完整 filename、extension、body SHA 均保持未知，不將 `.abf` 或 `.actor` 補成事實。

## 4. 五表欄位與覆蓋盤點

下表是完整解析五份 XML 後取得的節點數與屬性集合；屬性存在不等於其語意、單位或目標怪物 consumer 已證明。

| member | 節點計數 | 實際屬性集合 |
|---|---|---|
| `_ActorList.xml` | ACTORLIST 1；OBJCATEGORY 5；ACTOR 5,361 | OBJCATEGORY：`ID`；ACTOR：`ID, PRE, FILE, NAME, NAMECOLOR, SCALE, SPECIES, SHOW_MINIMAP, SHOW_PANEL` |
| `CharSkill.xml` | CHARSKILL 1；CHAR 9；GROUP 27；SKILL 325 | CHAR／GROUP／SKILL 各有 `ID` |
| `SkillActiveTable.xml` | SKILLACTIVETABLE 1；SKILL 469；LEVEL 2,645；ACTIVEINFO 1,457；ATTACK 1,333；HEAL 78 | SKILL：`no, type, form, attribute, AtkLevel, DefLevel, name`；LEVEL：`val`；ACTIVEINFO：`hp, sp, mp, cooltime`；ATTACK／HEAL：`ratio, rev` |
| `Skill/SkillMatrix.xml` | Root 1；MatrixInfo 2 | MatrixInfo：`File` |
| `IndependentSkillEffect.xml` | SkillEffectList 1；Entry 92 | Entry：`Index, File` |

各表的限制如下：

- **Actor 表**：categories `0/1/3/6/7` 的列數分別為 `9/4436/343/370/203`；全表 `(category,ID,PRE)` 無重複。目標三怪只有上列 12 個 row。
- **CharSkill**：CHAR 僅 `1..9`，GROUP ID 為 `1/2/3`，325 個 SKILL ID 均唯一。沒有 CHAR1001／1009／1004。325 個數值都在 SkillActiveTable@no 集合內，只能記錄這個集合交集；本包沒有因此建立目標怪物或獨立效果的 consumer 連結。
- **SkillActiveTable**：469 個 `SKILL@no` 唯一，最小 `1`、最大 `3058`；查無 `1001/1009/1004`，亦查無既有報告提供的 `76/307/371`。這個有界陰性結果只針對所供 member，不代表整個 Client 沒有怪物技能資料。其他列的 `cooltime`／消耗／ATTACK 值不能挪來填三怪；本包亦未證明 `cooltime` 單位。
- **SkillMatrix**：只有兩筆匯入。第 3 行 `MatrixInfo@File="Table/Skill/Matrix/CharacterMatrices.xml"`；第 4 行 `MatrixInfo@File="Table/Skill/Matrix/MonsterMatrices.xml"`。兩個目標 body 均未隨包提供。
- **IndependentSkillEffect**：92 個 Index 唯一，範圍 `1..119` 且不連續；55 個 File 非空、37 個空。查無數值 `1001/1009/1004/76/307/371`。空 File 不能變成可載入檔名；非空檔名存在也不代表三怪引用了該效果。

## 5. 歷史技能／動畫與 consumer 證據

下列是包內歷史報告的限定重用；精確來源 commit 均為上列 `fb6a78bf…`，原檔名稱雖是 `.txt`，其內容是 Markdown 報告。沒有把 report SHA 當作 raw ABF 或矩陣 SHA。

| 代號 | 包內精確路徑 | SHA256 |
|---|---|---|
| R-GENERAL | `git-evidence/kr/evidence/3d714c4c995d1d6c33cced5d70af3ebf1246a46583fb5f0cdbf65f280453f5f2.txt` | `3d714c4c995d1d6c33cced5d70af3ebf1246a46583fb5f0cdbf65f280453f5f2` |
| R-CONSUMERS | `git-evidence/kr/evidence/d90f8e9b9f64edcc6f5ae272c00365fe62c67132e51c68e1743fb52f41e3b585.txt` | `d90f8e9b9f64edcc6f5ae272c00365fe62c67132e51c68e1743fb52f41e3b585` |

### 5.1 可以保存的引用

| ActorID | 已有報告記載 | 證據位置 | 仍未證明 |
|---|---|---|---|
| 1001 | matrix tier0，key1／2／3 → WORD 值76／307／371 | R-GENERAL 第42行 | raw MonsterMatrices body／SHA、matrix variant、PRE 對應、選招規則、skill→action→effect |
| 1001 | animation slot4 → `HokyPoky_MOVE01` | R-GENERAL 第20行 | raw Actor／ABF、PRE適用性、frames／FPS／事件／時長、追逐政策 |
| 1004 | slot4 → `Nepenths_WAIT01`；slot4與slot6均引用WAIT01 | R-GENERAL 第22及31行 | raw body／SHA、PRE適用性、是否可位移、攻擊動作／命中事件 |
| 1009 | 本包無可列出的 matrix cell 或動畫 slot | 五表完整解析及包內報告搜尋範圍 | 不能因無報告而宣稱沒有技能或動畫 |

`1004` 的 WAIT 引用不能證明它在所有情境都不位移；`1001` 的 MOVE 引用也不能給出速度、感知範圍或追逐結束條件。`PRE`、matrix variant、tier、key 是不同欄位；尚無 `PRE=tier` 或 `PRE=variant` 的證據。

### 5.2 consumer 的可用限制

R-GENERAL 記錄 `40F7F0 → FAB27C` 技能矩陣單例、初始化 `48D0A6/48D0B8 → 8180C0` 載入 MatrixInfo、`818430` 解析矩陣檔、`819220` 查找，以及 `81A8E0` 以 `tier<4/key<11` 讀 WORD。這能支持分開記錄「矩陣載入／查找」與「AI 決策」；本輪沒有重跑其原生驗證或以該值域替 Actor PRE 加上限制。

R-CONSUMERS 明示：`549980` 的 SubAI skill-condition 路徑在查矩陣前有 `model<=9` gate；`54F270` 為 availability predicate，沒有因此建立怪物 cooldown object 實例、選敵、攻擊命令或冷卻啟動機制；`54F330` 是資料 snapshot／UI 消費路徑。共用查表函式能處理怪物模型號，不足以將玩家／隊友 SubAI 直接接到怪物。

報告中限定 direct-call candidate graph 的範圍也保留：不能宣稱所有 runtime consumer、間接呼叫或外部模組已窮盡。T10 的既有退回與 T01 原審核狀態未因本次重用而改變。

## 6. ID domain 與反例

| domain | 本交付的識別方式 | 禁止的跨域推論 |
|---|---|---|
| ActorResource | `(category,actor_id,pre)` | 當成世界 EntityId，或只靠裸 ID/PRE 全域合併 |
| Cluster OBJECT | `(member,cluster_set,cluster,ID,PRE,occurrence)` 的來源列 | COUNT 當地圖總數、選定波次、擊殺條件；表中未提供 category 不能聲稱本輪驗證了 native category consumer |
| Matrix cell | 已證名稱範圍內的 CharID／variant／tier／key | PRE 等於 tier；矩陣載入等於選招決策 |
| SkillActive definition | `SKILL@no`，另帶 `LEVEL@val` | ActorID 或 Matrix WORD 相等就直接視為該列 |
| Animation | actor body 內的 slot／引用名稱 | 動畫編號等於 skill ID；播放時長等於起手、命中或Server節奏 |
| Independent effect | `Entry@Index → Entry@File` | Index 等於 SkillActive@no，或空File代表有效效果 |

兩個可重現反例：

1. `_ActorList` 的 `(ID=1,PRE=1)` 在 **category0** 為 `soma`，在 **category3** 為 `S_Item-Money01`。全域 key 必須保留 category。
2. `SkillActiveTable/SKILL[@no='1']@name` 是 `펀치볼`，`IndependentSkillEffect/Entry[@Index='1']@File` 是 `B_Self-BasisCure01.eff`。本包未提供連接兩者的 consumer；相等數字不是引用證據。此反例不否定未來可能找到的顯式 mapping。

## 7. 五份 Cluster 中的 55 個 target 來源列

五份 Cluster 皆先核對 raw SHA，再按宣告 `ks_c_5601-1987` 嚴格解碼。來源位於 `local-resources/Field/Cluster/`，carrier SHA 由 manifest 宣告為 `18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a`。

| member 檔名 | target OBJECT 列數 | 本輪 target ActorID/PRE | raw member SHA256 |
|---|---:|---|---|
| `CLUST_S_pathofAlsmeer_01.xml` | 11 | 1001/3；1004/1、3 | `d60f5d2b8a5acdc39a59f918001b0fca95d9ff6a444bf003fd492c4b712d4217` |
| `CLUST_S_pathofpindus_01.xml` | 6 | 1001/1；1009/1；1004/1 | `bf3cfce20eb7ef61d6e1961072a7084f09cfe1313f6a21dc04f2bb961767b182` |
| `CLUST_scenario_chicken_01.xml` | 16 | 1001/1；1009/1、3；1004/1 | `efd7b57cb299cac8b5281a64186f58705a5ae82c0238167d1cd7f71e5e528596` |
| `CLUST_scenario_razed_01.xml` | 12 | 1001/2；1004/1、3 | `02624b078f56e863d41ad32bdc336d0d41e5b7af791759dcd34090e321cf88dd` |
| `CLUST_scenario_ygg_01.xml` | 10 | 1001/2；1009/3；1004/1、3 | `8e0a465d74a3ecdc3f6ae8733ab5de95c303ab46b41072bc25caa09a00f3ba07` |

55 是來源列數，不是整場怪物數。本輪保留所有 target 的 group literal，未決定哪些 group 會被採用，未把它們對應到某張 map，也未導出出生座標、清怪條件或官方波次。逐列 selector／行號／SHA 由機器資料保存；這裡不重複整份列表。

這些列能決定後續抽取至少要注意的 PRE 集合：**1001=1/2/3、1009=1/3、1004=1/3**。它們在 category1 的 Actor 表都找到對應列，但該 literal match 不升級為新 BIN consumer 驗證。

## 8. 九類 AI 欄位的判定

下表對三怪都適用。標記針對 **Server 決策值／規則**；來源線索另列，不用報告中的動畫名填入 Server 數值。`monster-profiles.json` 的九類欄位均保持「無來源／null」，候選政策單獨保存，且不把 null 解讀成 0 或預設啟用。

| 欄位 | 已讀來源提供的線索 | 尚不能填入的值／規則 |
|---|---|---|
| 追逐 | 1001 MOVE、1004 WAIT 的歷史動畫引用 | 速度、路徑、距離、追逐起止與能否移動 |
| 感知 | 五表未建立三怪感知欄位 | 半徑、視線、仇恨、選敵與重選時點 |
| 回位 | 五表未建立三怪回位欄位 | 起點、距離、脫戰、清仇恨、恢復規則 |
| 選招 | 1001 有3個歷史矩陣cell；1009/1004 cell未取得 | 時機、權重、條件、PRE與matrix variant/tier關係 |
| 起手 | raw Actor／ABF 未提供 | 起手時長、起手可取消性、動作與Server時間對齊 |
| 命中 | SkillActiveTable有ATTACK結構，但沒有目標怪物對應 | 命中事件、範圍、傷害引用、skill/action/effect橋接 |
| 冷卻 | 有 `ACTIVEINFO@cooltime` 欄名、通用availability報告 | 三怪冷卻數值／單位／啟動時點／權威狀態 |
| 受傷 | raw受傷動作與consumer未提供 | 硬直、打斷、受傷狀態與恢復時點 |
| 死亡 | raw死亡動作與consumer未提供 | 判死、結算、播放、移除與重複通知邊界 |

即使日後取得 frames／FPS，也應先建立獨立的**呈現動畫時長**欄位；不能直接推導 Server 起手、命中、後搖、冷卻或 AI 排程。原版 Server 內部決策未知，應列為 S00 的 Server 開發需求；真正未知的 Client wire／parser／consumer 仍維持 Client 補證需求。

## 9. 最小缺件與 S00 採用方式

第一批是 **1 個精確 member 加 3 個精確 stem**，不是已證明四個完整檔名：

| 項目 | 已證 locator | 適用 Actor／PRE | 缺少它阻擋的結論 |
|---|---|---|---|
| 怪物矩陣 | `Table/Skill/Matrix/MonsterMatrices.xml`，來自 SkillMatrix.xml第4行 | CharID/model1001、1009、1004的所有variant/tier/key；PRE關係待證 | raw矩陣格、1009/1004技能引用、PRE與矩陣domain關係 |
| 1001 raw body | FILE stem `00_HokyPoky`；carrier/path/extension未知 | 表有PRE1/2/3/6/7；包內Cluster用1/2/3 | 完整動畫slot、動作／效果引用、frame/event資料 |
| 1009 raw body | FILE stem `01_Moose`；carrier/path/extension未知 | 表有PRE1/3/4；Cluster用1/3 | 同上；目前連歷史動作列也未提供 |
| 1004 raw body | FILE stem `01_Nepenths`；carrier/path/extension未知 | 表有PRE1/2/3/6；Cluster用1/3 | 核實WAIT引用、完整動作／效果與事件資料 |

S00 可依既有本機資源索引解析這三個 stem，抽出真正命中的 carrier/member，保留原始 SHA 與實際副檔名；不需要使用者逐檔尋找。`Table/Skill/Matrix/CharacterMatrices.xml` 已有精確匯入，屬可選比較資料，未列為三怪最小解阻條件。

本包沒有已確認的 Monster-stat table 名稱，故不虛構 `Monster.xml` 路徑。raw matrix/body 補齊後，如出現更多技能或效果引用，再按已證 edge 列最小下游 member；現在不要求全解 effects、不搜尋 MEF、不繼續暫緩的 loader 路線。

S00 現可直接使用 typed識別、12個raw變體、來源SHA、明確空值、既有報告線索與抽取清單，建立可審核的資料入口。S00仍須設計感知／仇恨／追逐回位／選招政策、戰鬥時序與冷卻／受傷／死亡狀態，明列候選設計來源。這些開發需求不冒稱原版官方AI；跨功能整合與真人遊玩驗收另行判定。

## 10. 實際閱讀範圍

前置全文閱讀：`START-HERE.md`、`MANIFEST.json`、`git-evidence/AGENTS.md`、本handoff的`README.md`與`W2-PROMPT.md`、`git-evidence/kr/tasks/T10/README.md`、`git-evidence/kr/tasks/T11/README.md`。本輪治理最新狀態與歷史審核限制由主工作線統一記錄。

實際語意解析／使用：本文件列出的五份Table XML、五份Cluster XML、R-GENERAL與R-CONSUMERS。包內其他檔案曾作精確名稱／ID／引用搜尋或完整性比對者，須依 `source-index.json` 的用途區分；校驗或搜尋命中不宣稱全文語意驗證。raw資源仍留在輸入包，本次Git僅提交分析成果與來源對照。
