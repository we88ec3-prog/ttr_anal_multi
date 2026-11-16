# W2：已上傳 Table.stp 的缺件定位補充

日期：2026-11-04 19:54:13（Asia/Taipei）。工作分支：`extra/roy2`。

使用者追問：「缺少的檔案是否在 Table stp 中？」

**答案：部分在。兩個矩陣 member 確實在已上傳的原件內；三個怪物 body 的同名 member 不在此 Table 的完整目錄。** 原 W2 是依提示詞完成的 W1/W2/W3 ZIP-only 盤點；`NOT_IN_UPLOADED_PACKAGE` 指該 ZIP 未附，不能延伸成使用者沒有提供包含它們的原始載體。本補充依這次提問直接檢查另已提供的 `07-Table.stp`。

狀態：`BOUNDED_RESOURCE_AUDIT_NOT_FULL_PASS`。本次沒有修改正式 CLM／SPEC／ADR、RR、T16 `DRAFT_BLOCKED` 或其他 Task 原稿。

## 1. 原件與完整性

| 項目 | 實測 |
| --- | --- |
| 原件 | 使用者上傳 `07-Table.stp`；遊戲載體名 `Table.stp` |
| 大小 | 5,248,784 bytes |
| SHA256 | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |
| STPD block table offset | 5,181,456 |
| STPI directory index offset | 5,214,292 |
| 目錄／member／block | 10／1,026／1,026 |
| 目錄完整性 | 解析至 EOF；member path／ID 唯一；member IDs 與 block IDs 完全一致 |
| stored MD5 | 1,026／1,026 符合 block record |

MD5 比對的是 archive-wide XOR `0xff` 還原後、EX 解碼前的 stored member bytes，與同樣還原的 block-record digest；不是直接對磁碟上加擾區段計算。指定 XML 另驗 EX extent、zlib EOF、解碼大小及 SHA256。

此 SHA 與既有 `research/handoffs/kr-quest-runtime-20261103-v0.1.0/evidence/source-members.json` 的原始 Table 載體一致。原 W2 ZIP 宣告的 local variant carrier 為 `ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c`，兩個載體 hash 不可互換。

## 2. 七筆缺件請求的本次定位

| 請求 | 原始需求 | 本次結果 |
| --- | --- | --- |
| W2-M01 | `Table/Skill/Matrix/MonsterMatrices.xml` | **直接確認存在並成功解碼**。本次已取得三怪矩陣，不再缺這份原件資料。 |
| W2-M02 | body stem `00_HokyPoky`，Actor1001 | 此 Table 的完整 member path 搜尋為0；另有既有腳本文字定位，見第4節。 |
| W2-M03 | body stem `01_Moose`，Actor1009 | 此 Table 的完整 member path 搜尋為0；另有既有腳本文字定位，見第4節。 |
| W2-M04 | body stem `01_Nepenths`，Actor1004 | 此 Table 的完整 member path 搜尋為0；另有既有腳本文字定位，見第4節。 |
| W2-M05 | 尚未識別的 Monster metadata provider | 尚未識別。本次沒有逐一分析所有 XML 內容，不能因沒有 `Monster.xml` 就聲稱 Table 沒有相關資料。 |
| W2-M06 | 可選 `Table/Skill/Matrix/CharacterMatrices.xml` | **直接確認存在並成功解碼**。9個 `SkillMatrix`，63個 `Matrix`。 |
| W2-M07 | 三怪矩陣 skill WORD 的實際定義 provider | 已取得11個原始 WORD；它們全不在這份 `SkillActiveTable.xml` 的 `SKILL/@no` 中，provider 仍待對接。相同數字的其他欄位不能直接連接。 |

兩個矩陣的 member 證據：

| member | ID | archive body offset | stored bytes | decoded bytes | decoded SHA256 |
| --- | ---: | ---: | ---: | ---: | --- |
| `Table/Skill/Matrix/MonsterMatrices.xml` | 307 | 381,968 | 20,789 | 386,194 | `d83b2f311c8ab21779a6bde0371cd05d91b9c840588ad97002a6e64dcbd43539` |
| `Table/Skill/Matrix/CharacterMatrices.xml` | 306 | 378,896 | 2,942 | 90,731 | `78ca8db32ae323436d5c37b0162cca72a3c2b2a769924a63458dd087f96b7dad` |

其中 archive member ID 307 與矩陣 skill WORD 307 只是不同 namespace 的同數字，不能視為資料關聯。

## 3. 三怪原始矩陣值

`MonsterMatrices.xml` 根節點為 `MatrixList`，總共877個 `SkillMatrix`、877個 `Matrix`、1,698個 `Tier`、4,752個 `Key`。三個目標 CharID 的全部矩陣列如下，共11個 key：

| CharID | Matrix ID | tier | key → skill WORD |
| ---: | ---: | ---: | --- |
| 1001 | 0 | 0 | 1 → 76；2 → 307；3 → 371 |
| 1004 | 0 | 0 | 1 → 80；2 → 309 |
| 1004 | 0 | 2 | 1 → 81；2 → 455 |
| 1009 | 0 | 0 | 1 → 92；2 → 1593；4 → 93；5 → 1594 |

欄位路徑為 `/MatrixList/SkillMatrix[@CharID]/Matrix[@ID]/Tier[@tier]/Key[@key]/@skill`，逐列 selector 已存入 `table-stp-presence-audit.json`。

1001 的76／307／371現在有直接原件支持，不再僅是舊報告提示。1004／1009原 ZIP 未含的具體矩陣也已取得。這些是可供 Server 建立引用對照的來源值；**仍未證明 Actor PRE 與 Matrix ID／tier 的對應，也未證明選招、起手、命中、冷卻或其他 AI 決策規則。**

11個 WORD（76、80、81、92、93、307、309、371、455、1593、1594）在直接解碼的 `Table/SkillActiveTable.xml` 中均無 `SKILL/@no` 命中。這只排除這份指定 member 的該欄位作為直接外鍵，不能推成整個 Client 沒有技能定義。

## 4. 三個 body 的負向結果與已有定位線索

對該原件全部1,026個 member path，採不分大小寫的 substring 搜尋：`00_HokyPoky`、`01_Moose`、`01_Nepenths` 均為0；不分大小寫 `.abf` suffix 搜尋也為0。

因此可確認此原件的目錄沒有這三個同名 body 或 `.abf` member。沒有擴大宣稱其他名稱的表、嵌入式內容、其他 archive 或 local variant 也不存在對應資料。

唯讀以下既有 Git 程式文字可取得下一個明確定位，**本次沒有執行它**：

- 來源：`governance/inspect_field19_actor_resources.py`。
- 讀取基準 commit：`1e19a7f5b663d01aefbd1724907a1c4016faa36e`。
- Git blob：`d1e9455789a6bdcd0e8097aaee1be0309fab8648`。
- 程式宣告的載體：`Character/Mon/Base.stp`。
- 宣告載體 SHA256：`1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957`。

| ActorID | 該程式組出的 member | 宣告的 decoded SHA256 |
| ---: | --- | --- |
| 1001 | `Mon/00_HokyPoky.abf` | `3d817eb1d3c2e0839853f3d233771a3829470b8fdb9cd8391d920485cb95f633` |
| 1009 | `Mon/01_Moose.abf` | `d0ba2a3b0cd941e7a267f24c6ce68cb5f727d2f72a7ae9f21b1b51cd8cd3aa6b` |
| 1004 | `Mon/01_Nepenths.abf` | `6a581ad59dc5b009a8b155d7ef4aa45ec44c1753fb3936b2223f98dab50eca71` |

此處的完整檔名與 `.abf` 來自已讀的程式字面與拼接規則，並非由 stem 猜出。本次沒有開啟或重驗 Base 載體，故狀態是 `EXISTING_CODE_LOCATION_DECLARATION_NOT_RAW_REVERIFIED`。舊程式僅選 PRE1，不能推成所有 PRE 的 body／動畫差異均已證明。

## 5. 五個既有 W2 XML 的版本補證

以下原件解碼 bytes 全部與 ZIP 的 `local-resources/` 對應 member 完全一致：

| member | decoded SHA256 |
| --- | --- |
| `Table/_ActorList.xml` | `b01ae70817c79126b89292567e32d4c806c3ef31478b6a2eb96dcfd21e2c78f7` |
| `Table/CharSkill.xml` | `604a22ddf9cb297bcfe14481fb8f96d2a2379dc20298fb6ac337378360947d64` |
| `Table/SkillActiveTable.xml` | `1ea831f270df757d760f4ff87d6bf509a64326a23614a305c8d767580f2a2139` |
| `Table/Skill/SkillMatrix.xml` | `8c58ea135c94dc2c6056a3e408cad76a79c1857d72e37b43e2b9b8869c897dc4` |
| `Table/IndependentSkillEffect.xml` | `a1e8be8e36a2feddf7eecaf6d006c45b1ae9e6f8b915072525f3b5f0c91e0070` |

因此先前「不在既有原始 member 台帳、原始版本未核實」的四份 skill 表，現在已由此原件直接補證。只對這五份 member 得出相符結論，不宣稱整個 local variant archive 相同。

## 6. 重現、審核及後續界線

本次新寫 [audit_table_stp.py](audit_table_stp.py)，只讀原件與輸入包，僅輸出分析 JSON。格式來源以文字閱讀復用：

- `governance/inspect_tutorial_bounds_resource.py`，blob `e39cb00a9db90fbbea00844449b4b4da56520fae`：STPD/STPI目錄與block格式。
- `governance/inspect_first_tutorial_cluster.py`，blob `3a8d1507c35d356c3b395c171a85249765c6a6a5`：EX header、mode1 key及zlib解碼。

從 repo root 重現：

```bash
python -B research/handoffs/s00-web-server-definitions-20261104/W2/audit_table_stp.py \
  --archive /path/to/07-Table.stp \
  --input /path/to/unpacked-W1-W2-W3-input \
  --report /path/to/new-presence-audit.json
```

Python 3.10+，僅標準函式庫。本次實際結果：`PASS`、1,026 members、11 target matrix keys、5個ZIP member byte comparison通過。另一個新寫唯讀解析流程獨立重讀原件，確認同一完整目錄、全部MD5、7份指定XML的SHA/size/offset、三怪矩陣值及5份ZIP相符；結果見 [table-stp-presence-independent-review.json](table-stp-presence-independent-review.json)。此為本補充的獨立資料複核，不是T01正式FULL-PASS。

本次使用者只詢問載體定位，原始 `monster-profiles.json`、schema、links、`required-members.csv` 與 `unknowns.md` 保留原 ZIP-only 契約；新證據獨立保存並由 README 標明。S00應同時讀取本補充，勿繼續將兩份矩陣列為無法取得的原件。

- **Client 證據待補**：Base body 的原件驗證、PRE／Matrix關係、矩陣WORD實際provider、動作／事件／效果引用與相關原生consumer；有些已有上述精確來源線索。
- **Server 待開發**：追逐／感知／回位／選招等相容Server規則仍依原 `unknowns.md` 的9項候選需求處理；不能因有矩陣就補猜官方AI。原版Server內部演算法未知不阻擋明確標識的Server設計。
- **跨功能待整合**：將本補充11筆原件矩陣與原12筆ActorResource變體納入可追溯資料模型，PRE對應保持未知，資料契約更新另行記錄版本。
- **待遊玩驗證**：本次未執行遊戲／Server，未證可玩性。

Git僅保存本分析、來源SHA、完整member名稱索引及新核對程式。原STP、完整解碼XML與其他遊戲資源未加入Git；沒有重啟MEF搜尋或loader研究。
