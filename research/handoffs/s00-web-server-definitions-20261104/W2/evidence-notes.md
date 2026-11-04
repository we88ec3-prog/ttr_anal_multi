# W2 v2：三怪原件資料、引用與 AI 欄位完整證據

更新：2026-11-04 20:14（Asia/Taipei）。狀態`DRAFT_FOR_REVIEW`；以原ZIP、上傳Table與新Base進行有界資源核對。完整五份交付已更新為v2，原v1可由Git歷史取得。

## 1. 範圍、證據層級與核對方法

本次直接解析原始STPD/STPI目錄、block record與stored bytes；先驗載體SHA，再驗全部stored MD5，針對指定member解EX wrapper與zlib、驗EOF/解碼長度、SHA與XML。沒有執行歷史證據腳本、遊戲或Server；沒有重新分析BIN或MEF/loader。

| 原件 | SHA256 | 完整目錄／stored MD5 | 本次語意解析 |
| --- | --- | --- | --- |
| Table.stp | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` | 1,026／1,026 | 五份W2表、MonsterMatrices與CharacterMatrices。 |
| Character/Mon/Base.stp | `1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957` | 830／830 | 三份指定ABF全部94節點、419次屬性。 |

MD5是對全檔XOR-FF還原後、EX解碼前的member bytes比對同樣還原的block-record digest。decoded member另計SHA256。所有原件唯讀；新解出的完整XML／ABF留在本機，Git只收結構化分析與來源資訊。

原ZIP的130項raw SHA／size、110個Git blob來源仍保留。其local variant carrier宣告為`ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c`；該宣告不能用原Table hash覆寫。W2五份Table XML與本次原件解碼bytes逐一相符，因此其中四份skill表原本「不在原始member台帳」的版本問題已取得直接補證。其他4個Table member仍按既有原始台帳辨識，沒有假稱全部9個都在本輪重新解析。

來源機器紀錄：[source-index.json](source-index.json)、[table-stp-presence-audit.json](table-stp-presence-audit.json)、[base-stp-audit.json](base-stp-audit.json)。原始報告的source commit仍為`fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`；工作分支更新基準為`b70958607f453ccd9069ae0146b1325ff114b211`，不可把工作commit當原資源版本。

## 2. 三怪的12個ActorResource變體


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


`FILE`自身只有stem，但本次另直接驗出Base完整目錄的唯一同名ABF。下表與profile的`body_binding_basis`記錄這個明確字面／唯一member對照；它不自動證明runtime loader的選路或各PRE的override行為。

| ActorID | carrier member | decoded bytes | decoded SHA256 |
| ---: | --- | ---: | --- |
| 1001 | `Mon/00_HokyPoky.abf` | 3,744 | `3d817eb1d3c2e0839853f3d233771a3829470b8fdb9cd8391d920485cb95f633` |
| 1009 | `Mon/01_Moose.abf` | 3,931 | `d0ba2a3b0cd941e7a267f24c6ce68cb5f727d2f72a7ae9f21b1b51cd8cd3aa6b` |
| 1004 | `Mon/01_Nepenths.abf` | 4,018 | `6a581ad59dc5b009a8b155d7ef4aa45ec44c1753fb3936b2223f98dab50eca71` |

ABF本身沒有ActorID／PRE欄位。ActorID脈絡來自`_ActorList`，ABF source selector保留自己的Character／Animation結構；兩者不混成原件本來有的欄位。

## 3. 五表欄位與覆蓋盤點


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
- **SkillActiveTable**：469 個 `SKILL@no` 唯一，最小 `1`、最大 `3058`；查無 `1001/1009/1004`，亦查無本次矩陣的全部11個WORD（76、80、81、92、93、307、309、371、455、1593、1594）。這個有界陰性結果只針對所供 member，不代表整個 Client 沒有怪物技能資料。其他列的 `cooltime`／消耗／ATTACK 值不能挪來填三怪；本包亦未證明 `cooltime` 單位。
- **SkillMatrix**：只有兩筆匯入。第 3 行 `MatrixInfo@File="Table/Skill/Matrix/CharacterMatrices.xml"`；第 4 行 `MatrixInfo@File="Table/Skill/Matrix/MonsterMatrices.xml"`。兩個目標member原ZIP未附，本次均已從上傳Table原件取得並核對。
- **IndependentSkillEffect**：92 個 Index 唯一，範圍 `1..119` 且不連續；55 個 File 非空、37 個空。查無數值 `1001/1009/1004/76/307/371`；新矩陣WORD中僅92/93與Index數字碰撞，對應File為空與`B_Self-BasisDestructionTrap01.eff`，沒有跨域連接證據。空 File 不能變成可載入檔名；非空檔名存在也不代表三怪引用了該效果。


## 4. 原始怪物矩陣：完整11個目標cell

`Table/Skill/Matrix/MonsterMatrices.xml` decoded SHA256為`d83b2f311c8ab21779a6bde0371cd05d91b9c840588ad97002a6e64dcbd43539`，386,194 bytes。全表877個SkillMatrix、877個Matrix、1,698個Tier、4,752個Key。

| CharID | Matrix ID | tier | key→skill WORD |
| ---: | ---: | ---: | --- |
| 1001 | 0 | 0 | 1→76；2→307；3→371 |
| 1009 | 0 | 0 | 1→92；2→1593；4→93；5→1594 |
| 1004 | 0 | 0 | 1→80；2→309 |
| 1004 | 0 | 2 | 1→81；2→455 |

每列source selector是`/MatrixList/SkillMatrix[@CharID]/Matrix[@ID]/Tier[@tier]/Key[@key]/@skill`，直接原件行號存於profile／links。Matrix ID已證為0；PRE映射未證，actor_pre保持null。不能按key順序把Moose的四個WORD配成ABF兩個SKILL動畫，也不能把tier2自動套到PRE2。

可選玩家矩陣`Table/Skill/Matrix/CharacterMatrices.xml`已取得，90,731 bytes、SHA256 `78ca8db32ae323436d5c37b0162cca72a3c2b2a769924a63458dd087f96b7dad`；9個SkillMatrix／63個Matrix。它不是目標三怪的cell來源。

## 5. 原始ABF：47個動作與70次資源引用

三份body皆為`CharacterList/Character`，Character僅提供`RelativePath`與`BaseFile`。Animation原始屬性為`ID,File,CameraAttach,FrameSpeed,FaceIndex,Repeat,RepeatStartFrame,LagtimeType`；Effect／Sound子節點只含`File,Folder`。

| Actor | Character RelativePath | BaseFile | Animation | 去重clip | Effect子節點 | Sound子節點 |
| ---: | --- | --- | ---: | ---: | ---: | ---: |
| 1001 | `00_HokyPoky/` | `HokyPoky_BASE.gb3` | 15 | 11 | 2 | 3 |
| 1009 | `01_Moose/` | `Moose_BASE.gb3` | 16 | 13 | 3 | 3 |
| 1004 | `01_Nepenths/` | `Nepenths_BASE.gb3` | 16 | 6 | 3 | 3 |

全部47個Animation的FrameSpeed原字串為`40.000000`、RepeatStartFrame為`0.000000`、LagtimeType為`LightMelee`；本次沒有證明FrameSpeed物理單位，因此`fps=null`。ABF沒有frame count、duration、hit frame、SkillID、matrix/PRE mapping或AI決策欄位，也沒有明確Event節點。這個陰性結果只針對三份完整body，不擴張成其他資源或Client都沒有事件。

| Actor | Animation ID | clip File | Effect Folder+File |
| ---: | ---: | --- | --- |
| 1001 | 101 | `HokyPoky_SKILL01.gb3` | `Effect/Monster/M_HokyPoky-AttacK01.eff` |
| 1009 | 101 | `Moose_SKILL01.gb3` | `Effect/Monster/M_Moose-AttacK01.eff` |
| 1009 | 102 | `Moose_SKILL02.gb3` | `Effect/Monster/M_Moose-AttacK02.eff` |
| 1004 | 101 | `Nepenths_SKILL01.gb3` | `Effect/Monster/M_Nepenths-AttacK01.eff` |
| 1004 | 102 | `Nepenths_SKILL02.gb3` | `Effect/Monster/M_Nepenths-AttacK02.eff` |

另外三怪的slot35都引用`Effect/Assist/State/S_State-BasisDisband01.eff`。這是8次Effect引用、6個去重effect。47個slot的全部原值／行號與17個Effect/Sound子節點見 [base-body-notes.md](base-body-notes.md) 和 `base-stp-audit.json`；沒有只抽常用slot後聲稱全文完成。

1001與1009的slot4/6引用MOVE01，1004兩者引用WAIT01；三怪slot7引用DEAD，slot9引用ATTACKED。原值已知，但未驗各狀態觸發、可否位移、傷害提交或死亡結算時點。完整94節點中沒有能把11個matrix WORD連到這些Animation ID的明確欄位。

70次引用去重為50個：30個animation clip、3個base model、6個effect、8個sound、3個texture。Base的830個file member全為ABF；其中另有空的Ani/Mesh/Texture目錄，但不能把空目錄當作底下資源存在。對50個引用的exact path／basename查核在此Base均無命中；Table完整目錄也未提供這些實際媒體。RelativePath+File只是相對引用，沒有擅加`Mon/Avatar`或其他載體名稱。

`resource-references.csv`保存每次引用；`required-members.csv`只把6個effect及30個animation clip列成P2可選呈現需求。三個base模型、貼圖與聲音不阻擋本輪AI資料工作。取得clip也不能自動把總長換成起手、命中或冷卻。

## 6. 歷史consumer、原件複驗與適用限制

R-GENERAL來源：`git-evidence/kr/evidence/3d714c4c995d1d6c33cced5d70af3ebf1246a46583fb5f0cdbf65f280453f5f2.txt`；R-CONSUMERS來源：`git-evidence/kr/evidence/d90f8e9b9f64edcc6f5ae272c00365fe62c67132e51c68e1743fb52f41e3b585.txt`。檔名即原SHA256；完整Git blob及讀取範圍見source-index。

1001原報告76／307／371與移動clip提示、1004 WAIT提示，現在都有本次資源原件支持；新增1009及1004完整matrix和三份body全部動作。這只複驗上述資源主張，沒有把舊報告整篇／所有BIN函式升格。


R-GENERAL 記錄 `40F7F0 → FAB27C` 技能矩陣單例、初始化 `48D0A6/48D0B8 → 8180C0` 載入 MatrixInfo、`818430` 解析矩陣檔、`819220` 查找，以及 `81A8E0` 以 `tier<4/key<11` 讀 WORD。這能支持分開記錄「矩陣載入／查找」與「AI 決策」；本輪沒有重跑其原生驗證或以該值域替 Actor PRE 加上限制。

R-CONSUMERS 明示：`549980` 的 SubAI skill-condition 路徑在查矩陣前有 `model<=9` gate；`54F270` 為 availability predicate，沒有因此建立怪物 cooldown object 實例、選敵、攻擊命令或冷卻啟動機制；`54F330` 是資料 snapshot／UI 消費路徑。共用查表函式能處理怪物模型號，不足以將玩家／隊友 SubAI 直接接到怪物。

報告中限定 direct-call candidate graph 的範圍也保留：不能宣稱所有 runtime consumer、間接呼叫或外部模組已窮盡。T10 的既有退回與 T01 原審核狀態未因本次重用而改變。


### 原件新增的直接／未解關係

已閉合的有界資料關係是「ActorResource→FILE stem→唯一同名body」、「Matrix cell→skill WORD」、「body Animation ID→clip File」、「Animation ID→Effect/Sound Folder+File」。仍未閉合的是「PRE→Matrix/Tier」、「skill WORD→Animation ID／skill definition」，以及可自由由相容Server設計的AI決策與時序。

`reported_*`仍保存歷史報告，而`matrix_cells/animations`保存直接原件。兩套來源同時存在不代表重複的技能／動作。typed CSV把六個舊報告列標成`HISTORICAL_REPORTED_VALUE`，不再使用「目前raw missing」狀態。

## 7. ID domain 與反例


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


第三個原件反例：Moose的matrix skill WORD92／93，與IndependentSkillEffect Index92／93相同；Index92的File空、Index93為`B_Self-BasisDestructionTrap01.eff`。原Moose ABF引用的是`M_Moose-AttacK01/02.eff`，未給Index。故兩個`effect_index_present_in_supplied_member=true`只是數字集合命中，`skill_action_effect_binding`仍為`UNKNOWN`。

本次也不以archive member ID307與skill WORD307相同建立連結；archive index ID是另一個命名空間。

## 8. 五份Cluster中的55個target來源列


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


## 9. AI欄位、缺件與Server交付

九類AI欄位各保留來源線索與決策值分離：動作／效果字面已放raw arrays，決策`value/unit`仍null。受傷／死亡已可指向具體clip；原本「raw body未附所以不知道動作」的缺口已解除，剩下的是狀態時序／判定／consumer。選招已可引用11個WORD，但可用性、PRE關係、選敵與優先序無原始決策來源。

| 需求分類 | 本次狀態 | S00採用方式 |
| --- | --- | --- |
| M01–M04、M06原件 | 5項取得並核對 | 直接消費現行profile與來源，無需再要求上傳。 |
| M05 metadata/PRE、M07 skill provider | 2個未識別來源角色 | 按既有typed consumer與來源定位，不創造Monster.xml或以Animation101猜技能。 |
| M08–M43 | 36個P2可選呈現引用 | 需要clip/effect內容時才按明確字面取最小資源；不阻擋本輪盤點與ServerAI介面。 |
| W2-SRV-01..09 | 9項Server開發需求候選 | 追逐、感知、回位、選招、起手、命中、冷卻、受傷、死亡，由S00依已有Client相容介面明示政策。 |

具體玩家情境、已知Client／來源條件與未知邊界見 [unknowns.md](unknowns.md)；未重新建立正式REQ／RR台帳。真正未知的native wire／parser／consumer仍列Client待補證，原版Server內部演算法未知則不作停止Server設計的理由。

## 10. 完成判定與驗證界線

本次完成W2要求的三怪來源／AI欄位對照、精確body及matrix引用、最小來源需求與五份必交資料更新。schema提升到2.0.0，原schema的body必為null／matrix_variant必為null限制已按新來源更新；未取得的FPS、duration、PRE橋接與AI值仍受null約束。

整體驗證由`verify_inventory.py`直接讀原ZIP及兩載體；正式實跑結果保存於`validation-report.json`。另外Base核對器逐一驗830個stored MD5與三份完整XML，獨立consumer審核交叉核對47動作與70次引用。這些結果不自動提升T01 FULL-PASS、T16啟用、SPEC穩定度、Server實作或可玩狀態。

實際全文解析的是指定五表、兩個matrix、三個body與原五份Cluster；全archive目錄／digest核對不冒稱所有member全文研究。輸入原件、Client、Server及連段核心未修改；MEF與loader路線維持原排程。
