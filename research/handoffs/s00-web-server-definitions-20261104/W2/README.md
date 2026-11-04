# W2 v2：三怪技能、動作與 AI 欄位對照

資料整合時間：2026-11-04 20:14（Asia/Taipei）。分支：`extra/roy2`。Schema：`2.0.0`。

**已完成本次可用材料範圍的 W2 工作：原 ZIP、已上傳原始 Table.stp 與新增 Base.stp 已整合回五份必交資料；三怪 body 與矩陣均已直接核對。** 現可交 S00 使用來源字典、矩陣清單、動畫與效果引用，以及明列的 Server 開發需求。資料狀態仍為 `DRAFT_FOR_REVIEW`；完整原生 AI、Server 實作與真人可玩驗收各有獨立完成條件。

## 1. 現在可直接使用的成果

| ActorID／category1 | 已直接核對的 Base member | 全部 Actor PRE | Matrix ID／tier／key→WORD | Animation 列數 |
| --- | --- | --- | --- | ---: |
| 1001 | `Mon/00_HokyPoky.abf` | 1、2、3、6、7 | Matrix0 tier0：1→76、2→307、3→371 | 15 |
| 1009 | `Mon/01_Moose.abf` | 1、3、4 | Matrix0 tier0：1→92、2→1593、4→93、5→1594 | 16 |
| 1004 | `Mon/01_Nepenths.abf` | 1、2、3、6 | Matrix0 tier0：1→80、2→309；tier2：1→81、2→455 | 16 |

資料來源分別為 `Table/_ActorList.xml`、`Table/Skill/Matrix/MonsterMatrices.xml` 與 `Character/Mon/Base.stp` 的上述三份 body。**表中的 PRE 和 Matrix／tier 仍是獨立欄位，沒有做 PRE=Matrix／tier 的假設。**

- **3個 profile、12個原始 ActorResource 變體**：NAME、NAMECOLOR、SCALE若存在、FILE及其他原值；保留 `(category, ActorID, PRE)` 複合鍵。
- **11筆原件矩陣 cell、47筆原件動畫設定**：每筆附載體SHA、member SHA、精確selector與行號。FrameSpeed字面值、Repeat及LagtimeType均保存，不推導未知單位。
- **8筆 Effect、9筆 Sound 子節點引用**：動作到Folder+File可直接追溯；子節點沒有命中幀或時間欄位。
- **122筆 typed 關聯**：98筆已知來源關聯、6筆歷史報告引用、9筆指定欄位無命中、9筆未建立的跨域關係。這不是122個可施放技能。
- **70次呈現資源引用、50個去重名稱**：30個動畫clip、3個Base模型、6個effect、8個sound、3個texture。全部使用來源字面，沒有猜其他封包名。
- **55筆原ZIP Cluster target出現列、27個AI決策欄位與9項Server開發需求候選**：AI未知值保持null；場景出現列不被加總成官方波次或整場怪物數。

精確數值與證據見 [evidence-notes.md](evidence-notes.md)、[base-body-notes.md](base-body-notes.md)、[table-stp-presence-audit.json](table-stp-presence-audit.json) 和 [base-stp-audit.json](base-stp-audit.json)。

## 2. 動作／效果已知，技能橋接與 AI 決策仍分開

| 項目 | 已知原件值 | 未由此證明的內容 |
| --- | --- | --- |
| 移動相關clip | 1001、1009的slot4/6引用MOVE01；1004的slot4/6引用WAIT01。 | 速度、追逐距離、路徑、停止或禁止位移規則。 |
| SKILL clip | 1001有101→SKILL01；1009／1004各有101/102→SKILL01/02及明確effect。 | 11個矩陣WORD各自對應哪個Animation ID；不能按數量、順序或同數字配對。 |
| 受傷／死亡呈現 | 三怪slot9引用ATTACKED、slot7引用DEAD；實際File字串已保存。 | 硬直、打斷、判死、結算與移除時點。 |
| FrameSpeed | 47筆均為原字串`40.000000`。 | 尚無consumer/clip證據可把它寫成已證FPS；body也沒有frame count或duration。 |
| Effect／Sound | 子節點只給File與Folder。 | 播放起點、hit frame、傷害裁決、冷卻或Server AI節奏。 |

一個實際反例：Moose矩陣WORD92／93，恰有同數字的IndependentSkillEffect Index92／93；後者File分別為空字串與`B_Self-BasisDestructionTrap01.eff`。ABF中Moose的SKILL效果卻是`M_Moose-AttacK01.eff`／`02.eff`。三者不能用數字直接建立外鍵。[consumer-notes.md](consumer-notes.md) 保留完整consumer、反例與既有審核限制。

## 3. 交付檔案與讀取契約

| 檔案 | 用途 |
| --- | --- |
| [monster-profile.schema.json](monster-profile.schema.json) | Draft2020-12、v2.0.0；約束已知來源與未知值，不是Server最終runtime schema。 |
| [monster-profiles.json](monster-profiles.json) | 三怪／12變體、原件body、11個`matrix_cells`、47個`animations`、27個AI未知欄位與9候選需求。 |
| [monster-skill-links.csv](monster-skill-links.csv) | 122筆typed關聯／反例範圍／未解橋接；含來源SHA、selector、source_refs及carrier驗證。 |
| [required-members.csv](required-members.csv) | 43筆來源需求紀錄，含5項已取得、2項未識別來源角色與36項可選呈現引用；見下節。 |
| [unknowns.md](unknowns.md) | Client真正缺口、Server開發需求、跨功能整合與待遊玩驗證。 |
| [resource-references.csv](resource-references.csv) | 70次精確資源引用，包含來源slot、File／Folder／RelativePath、去重所需欄位；未猜載體。 |
| [source-index.json](source-index.json) | 原ZIP130項、110個Git來源blob、兩個上傳載體、10個直接解碼member、原宣告與實測分層。 |
| [table-inventory.json](table-inventory.json) | 五表原欄位／數量、55筆Cluster引用、新矩陣資料及92/93跨域反例。 |
| [base-stp-audit.json](base-stp-audit.json)、[base-body-notes.md](base-body-notes.md) | 三body全部94個XML節點、419次屬性、47個slot、70次資源引用與語意界線。 |
| [verify_inventory.py](verify_inventory.py)、[validation-report.json](validation-report.json) | v2整體資料校驗器及實際結果。 |
| [audit_table_stp.py](audit_table_stp.py)、[audit_base_stp.py](audit_base_stp.py) | 新寫的唯讀載體核對器；不執行歷史證據腳本或遊戲。 |

### v1 到 v2 的差異

v1的五份必交資料只依輸入ZIP，原件補充當時另存筆記。v2已把新證據合入主要資料，消費端應使用`schema_version=2.0.0`：

- `body_carrier/member/extension/member_sha256`已從null改為本次實測值；`body_binding_basis`明示Actor FILE stem與唯一同名ABF的對應依據，runtime loader／PRE override沒有因此被標為驗證完成。
- `matrix_cells`與`animations`保存本次直接原件；`reported_matrix_cells`與`reported_animation_refs`保留舊報告原有證據層級，不能把其歷史null SHA誤讀為現在缺原件，也不可重複算入原始cell／slot總數。
- 兩個`matrix_imports.present_in_package=false`仍描述原ZIP未附；同列`present_in_uploaded_archive=true`及member SHA描述另已提供的Table原件。
- 原ZIP宣告的`carrier_sha256_declared`保留；`carrier_sha256_verified`另存實際原件hash，不能把local variant整包宣告換成原件hash。
- `matrix_variant=0`取自`Matrix@ID`；`actor_pre`仍null。`FrameSpeed`保留字串，`fps/frames/presentation_duration_ms/server_ai_duration_ms`均null。
- 九個AI欄位的`source_status=無來源`指尚無可直接採用的AI規則／數值；`related_source_link_ids`連到已知呈現／矩陣事實，`server_policy_candidates`另外保存待S00採用的契約。

CSV為UTF-8標準引號格式；`from_key/to_key/source_refs`是JSON字串，應用CSV與JSON解析器。空白actor_pre不是PRE0；`ABSENT_IN_SUPPLIED_MEMBER`只對指定member欄位成立。

## 4. 缺件清單的目前狀態

| 紀錄 | 數量 | 現況與處理 |
| --- | ---: | --- |
| M01–M04、M06 | 5 | `ACQUIRED_AND_VERIFIED`。MonsterMatrices、三份ABF、可選CharacterMatrices均已取得；不再要求抽取。 |
| M05、M07 | 2 | `UNRESOLVED_SOURCE_ROLE`。Monster metadata／PRE關係及skill WORD definition／Animation橋接尚未識別；不是兩個已知檔名。 |
| M08–M13 | 6 | `OPTIONAL_PRESENTATION`。ABF精確Effect Folder+File；需檢查實際效果內容時再按既有索引取最小檔。 |
| M14–M43 | 30 | `OPTIONAL_PRESENTATION`。各Animation的RelativePath+File；只有需要clip呈現內容或幀數時才取，不拿來猜AI節奏。 |

**43筆不是43個阻擋開發的缺檔。** 36個下游引用都明標P2、`server_policy_design_blocked=false`。模型、貼圖及聲音只在resource-references完整保存，沒有擴張為本輪AI必備檔案。引用路徑的相對基底、實際carrier/member未知者維持空白；不要求使用者自行找素材、拍影片或截圖。

## 5. 來源與本輪實際讀取範圍

| 載體 | bytes | SHA256 | 查核 |
| --- | ---: | --- | --- |
| 上傳原始Table.stp | 5,248,784 | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` | 1,026個member完整index／stored MD5；7個指定XML解碼。 |
| 新增Base.stp | 946,961 | `1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957` | 830個member完整index／stored MD5；三個指定ABF全文解析。 |

原輸入ZIP SHA256仍為`7587e67dd012a020f0276c8cfd6b791ad07f8f5e7867931481c94aa30abf3e1a`，manifest SHA為`4b6f14740df2ccfe1447ad84acac45ceb4752d67c4108d5c3f49335d0c9b96f3`。130／130項大小與SHA符合，110／110個Git證據blob可按來源commit `fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`重驗。

W2使用的五份Table XML均已與上傳原件的解碼bytes相符；先前四份skill表的原始版本未核實問題已補證。只對指定member作此結論，不宣稱整個local variant carrier與原件相同。完整目錄與MD5通過也不等於所有1,856個member都做過語意分析。

原始`1001/PRE7 NAMECOLOR=#FFOO2C`的字母O保留；1001/PRE6、PRE7及1004/PRE6的SCALE仍缺屬性，不補預設值。T16的20 definitions、4 flows、8 scenario entries仍為`DRAFT_BLOCKED`。

## 6. 重現與驗證

從repo root執行（`--input`接受原ZIP或已解壓目錄）：

```bash
python -B research/handoffs/s00-web-server-definitions-20261104/W2/verify_inventory.py \
  --input /path/to/Tartaros-Web-AI-W1-W2-W3-input.zip \
  --table-archive /path/to/Table.stp \
  --base-archive /path/to/Base.stp \
  --git-repo . \
  --report /path/to/new-validation-report.json
```

只有明確提供`--report`才寫新報告，輸入包與原件保持唯讀。校驗涵蓋schema、原件SHA與member bytes、12個PRE、11個matrix cell、47個Animation、8個Effect／9個Sound、來源索引、typed links、70次資源引用、36個可選請求、55個Cluster來源列，以及null／domain／runtime界線。負例用於阻擋把未知值改0、將FrameSpeed當FPS、猜PRE、使用未觀察副檔名及宣稱runtime ready。

實際結果與執行環境以 [validation-report.json](validation-report.json) 為準；這些資料校驗不是新的BIN語意驗收、正式T01 FULL-PASS、Server測試或真人遊玩。

## 7. Server可繼續的工作與歷史

S00可直接消費來源字典、原件矩陣與呈現引用，建立Monster資料入口及可配置狀態機。感知／追逐／回位／選招、起手／命中／冷卻、受傷／死亡權威規則依 [unknowns.md](unknowns.md) 的9項Server需求採用；未知native wire／parser／consumer仍由Client研究補證。這次沒有改Client／Server或連段核心，也沒有重啟MEF／loader路線。

本輪在既有`extra/roy2`作業，基準`b70958607f453ccd9069ae0146b1325ff114b211`；最新檢查main仍為`4875b184370f6030902460d95003fa71f8e062cd`。沒有新增分支或修改其他工作目錄。Git僅收分析、schema、核對器與來源索引，原STP／ABF／XML不提交。

先前 [20261104-195413-W2-table-stp-followup.md](20261104-195413-W2-table-stp-followup.md) 是尚未取得Base時的歷史補充；當時「原五份資料保留ZIP快照」的安排已由本次v2整合取代。完整v1仍可從歷史commit讀取。
