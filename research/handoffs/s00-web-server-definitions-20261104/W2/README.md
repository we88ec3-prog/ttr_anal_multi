# W2：Actor1001／1009／1004 技能與 AI 欄位對照

日期：2026-11-04（Asia/Taipei）。工作分支：`extra/roy2`。

**本包完成上傳材料範圍內的三怪欄位盤點、typed 引用與缺件交付，可供 S00 建立資料模型、安排最小資源抽取及決定 Server 政策。它仍是 `DRAFT_FOR_REVIEW` 的證據資料包；沒有取得三怪的完整原生技能／AI 定義。**

**2026-11-04 19:54（Asia/Taipei）原件補充：**使用者追問缺件是否在已上傳的 `Table.stp`，已直接核對該原件的完整 1,026 個 member。`MonsterMatrices.xml` 與 `CharacterMatrices.xml` 確實存在，三怪共11個矩陣 key 已取得來源值；五個 W2 Table XML 也全數與此原件解碼 bytes 相符。三個 body stem 及 `.abf` 成員均不在此 Table 的 member index；既有治理腳本文字指向 `Character/Mon/Base.stp`，該載體未在本次重驗。完整結果、精確路徑、SHA 與範圍見 [原件補充核對](20261104-195413-W2-table-stp-followup.md)／[機器可讀結果](table-stp-presence-audit.json)。下列原始盤點及原五份必交資料仍保留 **ZIP-only 快照**；其中「缺件／原始版本未核實」不應再解讀為本補充之後的完整可用來源狀態。補充沒有提升正式審核或 runtime 成熟度。

使用者本次明確指定 `extra/roy2` 並要求上 Git，優先於輸入提示詞的預設 main。開工核對 main `4875b184370f6030902460d95003fa71f8e062cd`，既有 `extra/roy2` 的 `44e91057a9a3f9ba7a2fcac8c5bca53c7899f5bb` 為其祖先，已在同一分支 fast-forward 到該基準。本輪新增成果只在本 `W2/` 目錄；不更改 Task owner、RR／CLM／SPEC／ADR 或其他工作原稿。

## 1. 直接可用的資料

| ActorID（category 1） | FILE 原值；僅已證 stem | `_ActorList` 全部 PRE | 五份已提供 Cluster 引用的 PRE | 既有報告提示，非本輪 raw body 驗證 |
| --- | --- | --- | --- | --- |
| 1001 | `00_HokyPoky` | 1、2、3、6、7 | 1、2、3 | tier0 key1/2/3 → 76/307/371；動畫 slot4 → `HokyPoky_MOVE01` |
| 1009 | `01_Moose` | 1、3、4 | 1、3 | 沒有可證的 target-specific 技能／動作明細 |
| 1004 | `01_Nepenths` | 1、2、3、6 | 1、3 | 動畫 slot4、6 → `Nepenths_WAIT01`；沒有具體技能 ID |

S00 現在可直接使用下列資料：

- **三個 profile／12 個 ActorResource 變體**：原字面 NAME、NAMECOLOR、SCALE（若存在）、FILE、SPECIES、SHOW_MINIMAP、SHOW_PANEL；每筆有 source member、SHA、selector 與行號。鍵為 `(category, ActorID, PRE)`，不能省去 category。
- **38 筆 typed 關聯**：14 筆原件字面關聯、6 筆明標來源層級的舊報告關聯、9 筆指定檔案範圍內的無命中、9 筆未解橋接。消費端必須檢查 `status`；38 筆不是38個可執行技能連結。
- **五表欄位清單與55筆 Cluster 目標引用**：保留場景來源、原始群組欄位與 PRE；沒有把所有群組當選定波次，也沒有將 COUNT 加總成整場總怪數或把 editor 座標當世界座標。
- **27 個 AI 欄位與9項 Server 開發需求候選**：每怪的追逐、感知、回位、選招、起手、命中、冷卻、受傷、死亡欄位均明標來源狀態。缺值保持 `null`；政策候選與來源值分開。

上述表格與計數的原件欄位、完整 SHA、反例見 [evidence-notes.md](evidence-notes.md) 和 [table-inventory.json](table-inventory.json)；consumer 及既有審核限制見 [consumer-notes.md](consumer-notes.md)。

## 2. 交付檔案與契約

| 檔案 | 用途 |
| --- | --- |
| [monster-profile.schema.json](monster-profile.schema.json) | JSON Schema Draft2020-12；約束這次三怪證據盤點、完整九類 AI 欄位及未知值。不是 Server 執行引擎的最終 AI schema。 |
| [monster-profiles.json](monster-profiles.json) | 三怪與12變體、兩個矩陣 import、報告提示、27未知 AI 欄位、9個未批准政策候選。 |
| [monster-skill-links.csv](monster-skill-links.csv) | typed domain 關聯／無命中／未解邊，附來源 commit、blob、member SHA、selector、缺件 ID。 |
| [required-members.csv](required-members.csv) | S00 可直接消費的最小缺件與後續條件式引用清單；7筆請求記錄不等於7個必須取得的實體檔。 |
| [unknowns.md](unknowns.md) | Client 待逆向、Server 待開發、跨功能待整合、待遊玩驗證；每項解除條件與責任。 |
| [source-index.json](source-index.json) | 全包130檔 SHA/size、110個 Git blob 的來源版本、逐member版本限制、實際讀取層級及開工政策基準。 |
| [table-inventory.json](table-inventory.json) | 五表節點／欄位／數量、typed ID 反例與55筆 Cluster 原值引用。 |
| [evidence-notes.md](evidence-notes.md) | 表格與引用的完整分析。 |
| [consumer-notes.md](consumer-notes.md) | 既有 T10/T11 consumer 功能與不能推廣到怪物的界線。 |
| [verify_inventory.py](verify_inventory.py)、[validation-report.json](validation-report.json) | 本輪自寫、只讀輸入的資料校驗器及實際結果；不執行包內舊腳本。 |

### JSON 讀取原則

`source_status` 有三種語意：

| 狀態 | 可以怎麼使用 |
| --- | --- |
| `已知來源值` | 必須再看 `evidence_kind`。`raw_member_literal` 是本輪 XML 原字面；`existing_report_not_raw_reverified` 是舊報告內容，不能升格成本輪原生驗證。 |
| `候選政策` | 本輪供 S00 設計／去重登錄的 Server 契約；`approved_by_s00=false`，沒有猜填官方數值。 |
| `無來源` | `value=null`、`unit=null`。`null` 不是0、立即施放、零冷卻、永久存活或不可移動。 |

三個 FILE 引用的 `body_carrier/body_member/body_extension/body_member_sha256` 全為 `null`。舊報告叫它們 ABF，卻沒有列出精確 carrier/member；因此本包保留 stem，沒有自行接 `.abf`。矩陣的 `actor_pre/matrix_variant` 也為 `null`；**PRE、matrix variant、tier、key、skill WORD、SkillActive no、animation slot、effect Index 是不同欄位／domain**。

本 schema 固定了本輪的已證界線。例如把未知 cooldown 改為0、猜 `.abf` 或把 `runtime_ready` 改為 true 都應驗證失敗。將來取得新來源時，須附新 SHA、更新對照與 schema 版本，再交 S00 採用；不是在現有欄位中直接塞入猜值。

### CSV 讀取原則

CSV 為 UTF-8、標準引號跳脫；複合鍵欄位 `from_key/to_key` 及 `source_refs` 是 JSON 字串，不能以字串切逗號解析。多 ID 清單以分號分隔。空白 `actor_pre` 表示未確定／未指定，不是 PRE0，也不表示已驗證適用所有 PRE。

`monster-skill-links.csv` 的 `ABSENT_IN_SUPPLIED_MEMBER` 只表示在列出的 member SHA 沒有數字命中，並未主張整個 Client 沒有資料。`UNRESOLVED` 的邊不能當成已建立的外鍵。

## 3. 最小缺件交給 S00 一次處理

| 記錄 | 分類 | 已可指定的內容 | 會阻擋的結論 |
| --- | --- | --- | --- |
| W2-M01 | 核心：精確 member | `Table/Skill/Matrix/MonsterMatrices.xml` | 三怪 raw 矩陣、1009/1004 技能清單、1001舊值複驗；PRE 對應仍須另外查證。 |
| W2-M02 | 核心：精確 stem | `00_HokyPoky`；1001全部5個 PRE | 實際 body、動作／事件／動畫及後續引用。 |
| W2-M03 | 核心：精確 stem | `01_Moose`；1009全部3個 PRE | 同上；本包沒有1009的具體動作提示。 |
| W2-M04 | 核心：精確 stem | `01_Nepenths`；1004全部4個 PRE | 同上；複驗 WAIT01 引用，不能先定義固定不動 AI。 |
| W2-M05 | 未解析的來源角色 | 待確認的 Monster metadata 與上述 ActorID/PRE 的來源 | 檔名、carrier 未知；不得發明 `Monster.xml`。 |
| W2-M06 | 可選玩家比較 | `Table/Skill/Matrix/CharacterMatrices.xml` | 玩家矩陣／CharSkill 比較；不阻擋三怪最小資料包。 |
| W2-M07 | 取得矩陣／body 後才列實體檔 | 1001舊報告 WORD 76/307/371及後續三怪實際技能引用的 provider | skill→action→effect、成本／冷卻等引用；來源可能與M05或body重疊，須去重。 |

因此第一輪抽取目標是 **1個精確 member＋3個已證 stem**，另附 Monster metadata 的來源問題。`Table.stp` 在矩陣請求中只標為依 Table import 推出的**候選載體**，列出已提供 Table carrier 的宣告 SHA 供比對；沒有宣稱未上傳的矩陣 body 已在該載體中實測。S00 可從既有 member 索引解出小包，回傳實際 carrier/member/suffix/SHA。這不是要求使用者自行找檔，也不重啟 MEF／全包掃描。

## 4. 來源、版本與本輪真正驗證的範圍

輸入 ZIP：`Tartaros-Web-AI-W1-W2-W3-input.zip`。

- ZIP SHA256：`7587e67dd012a020f0276c8cfd6b791ad07f8f5e7867931481c94aa30abf3e1a`。
- MANIFEST SHA256：`4b6f14740df2ccfe1447ad84acac45ceb4752d67c4108d5c3f49335d0c9b96f3`。
- Git 證據來源 commit：`fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`；**110/110** 個 `git-evidence` 副本的本地 Git blob SHA 與該 commit tree 相符。
- 外層 manifest **130/130** 的大小及 raw SHA 相符；實際有131檔，多出的就是 manifest 自身。
- 九個 Table member 中，**5個符合包內原始 member 台帳，4個原始版本尚未核實**。W2的 `_ActorList` 屬前者；`CharSkill`、`SkillActiveTable`、`Skill/SkillMatrix`、`IndependentSkillEffect` 屬後者。四者不是 hash 不符，也不能把 local variant carrier 當作原始 carrier。
- T16內層清單的55檔中，本包提供53檔，現存 **53/53** 相符；`requirements.txt` 與 `validate_content.py` 未附。本輪沒有執行舊驗證程式。20 definitions、4 flows、8 scenario entries 仍全為 `DRAFT_BLOCKED`。

**本輪直接讀取／解析的技術來源**為五個目標 Table XML、五個 Cluster XML、一般怪物比較與 Skill-matrix consumer 報告，以及相關 T10/T11 README、T01退回／來源審核、既有資源台帳。逐檔 `read_scope` 區分完整閱讀、特定欄位／選段及僅算 hash；130檔完整性通過不代表130檔全文語意審核。最新 Git policy／Task metadata 僅作開工檢查，沒有擴大本包技術來源。

保留 `1001/PRE7 NAMECOLOR=#FFOO2C` 的字母 O，以及1001/PRE6、PRE7與1004/PRE6缺少SCALE的事實；不補預設值。所有原始資源與 ZIP 均未加入 Git。

## 5. 驗證與後續使用

校驗器需要 Python 3.10+ 與 `jsonschema`；本輪實際以 `jsonschema 4.26.0` 執行 Draft2020-12 驗證。從 repo root 可使用：

```bash
python research/handoffs/s00-web-server-definitions-20261104/W2/verify_inventory.py --input <解壓後的輸入包目錄> --git-repo .
```

`--git-repo` 可省略；省略時不重新查 commit tree，回報會明示該檢查未要求。只有顯式提供 `--report <路徑>` 才寫出新的驗證報告，且不得寫入輸入包。輸入包保持唯讀。

本輪資料驗證通過：schema、12筆原始變體、55筆Cluster引用、來源 SHA、38筆typed關聯、27個未知值與5個反例測試。反例覆蓋「未知值改0」「少一類AI欄位」「猜副檔名」「宣告可執行」「假設PRE→matrix variant」。這些是資料交付檢查，沒有新的 BIN 語意驗證、Server執行或真人遊玩驗收。

S00 可以先接 typed 資料匯入、來源追蹤和可配置 AI 狀態機的介面；數值與權威判定依 [unknowns.md](unknowns.md) 的 Server 開發需求決策。原生 wire／parser／動畫事件的缺口仍保留為 Client 證據需求，官方 Server 演算法未知不阻擋明標候選的相容 Server 設計。本輪未將 T16 `DRAFT_BLOCKED` 轉為可啟用，也未修改連段核心。
