# W3：離線主線資料轉換與一致性檢查

本目錄讓 S00 在本機從同一份 W1/W2/W3 資料包，批次產生十個 Quest 的審閱用 catalog、逐欄來源對照與驗證報告。工具只使用 Python 標準庫，讀取既有 CSV／JSON 與本包明列的資源；不連線、不啟動 Client／Server、不讀玩家 DB，也不執行包內歷史證據腳本。

**轉換完成不代表任務已啟用。** 來源 T16 `kr-quest-runtime-20261103-v0.1.0` 的 `DRAFT_BLOCKED`、`null`、`UNKNOWN`、未綁定 policy、完成條件及獎勵 gate 均保留。輸出是自訂的離線審閱資料，**不是原生 MEF**，不提升正式 CLM／SPEC／ADR，也不代表新的原生 FULL-PASS、RR ACCEPTED 或遊玩驗收。

## 1. 執行方式

Python 3.10 以上，無外部依賴，不需要 `pip install`。先將使用者提供的 `Tartaros-Web-AI-W1-W2-W3-input.zip` 解壓到本機資料夾；`--input` 指向內有 `START-HERE.md`、`MANIFEST.json`、`git-evidence/`、`local-resources/` 的根目錄。

Windows PowerShell 範例（在本目錄執行）：

```powershell
py -3 convert_story_data.py --input "E:\Tartaros\W1-W2-W3-input" --output "E:\Tartaros\W3-output"
```

Linux／macOS：

```bash
python3 convert_story_data.py --input /path/to/W1-W2-W3-input --output /path/to/W3-output
```

輸出使用另一個資料夾；預設不覆寫既有產物。來源資料夾保持唯讀。重新產生時可指定新的輸出目錄；明確指定 `--overwrite` 也只允許替換工具自己的三個產物，不授權修改任何輸入。

`--quests 117,118,119` 可選擇本包已具完整 definition／CSV／S00 路線列的子集合。預設是本次指定的十個 Quest；新任務需要先提供同契約的來源資料，工具不從 ID 相鄰或缺失欄位自動編造後續旅程。未附對應來源時會逐項報告。

回傳碼：`0` 表示本次離線轉換的結構檢核通過，內容仍 `DRAFT_BLOCKED`；`1` 表示已產出報告但有資料／hash／引用或未支援的資料形狀，應先修正報告列出的來源問題；`2` 表示 CLI／輸出路徑／讀寫等無法完成交付的錯誤。`--help` 可顯示所有選項。

| 產物 | 用途 |
| --- | --- |
| `story-catalog.json` | 十個 Quest、typed ID、前後繼、NPC／scene 關聯、原始 definition、候選 flow／Scenario 與獨立 S00 路線投影 |
| `source-map.csv` | 輸出位置對回原 CSV 記錄／欄、JSON pointer、來源路徑／commit／內容 SHA／member SHA；不可把檔案 hash 當欄位語意認證 |
| `validation-report.json` | 來源完整性、結構／引用檢查、逐項未知／缺件／未支援條件、實際讀取範圍；與內容啟用狀態分開 |

本目錄附有針對使用者資料包實際產生的三個輸出，供 S00 直接比較。原始遊戲 member、STP、BIN、原 ZIP 不進 Git。

### Catalog 的主要入口

`quests[]` 每筆提供 `id`、`predecessors`、`successors`、完整的 `definition`、`catalog_projection`、`scene_bindings`、`npc_scene_associations` 與獨立的 `s00_route`。原 T16 flow／Scenario 保存在 `shared.flows`、`shared.scenario_entries`；補充的 Case 圖、Map 摘要、typed dictionary、原始關聯與 wire adapter 投影各自位於 `shared` 下。`external_quest_references` 保留選取範圍外的端點，`source_manifest` 保留來源校驗分類。

`s00_route.scene_cues` 是有限文法解析的候選 cue；原始自然語句保存在 `raw_description`。`trigger_condition=null`、`executable=false` 不會因副本圖存在而變成有效執行規則。這不是通用自然語言規劃器或 Quest runtime。

### Source-map 的位置語義

`output_pointer` 是 `story-catalog.json` 的 JSON pointer。`input_format=JSON_POINTER` 時，`input_pointer` 使用 RFC 6901；`CSV_CELL` 使用 1 起算、**不含 header** 的 `csv_record` 與 `column`，另有含 header 的實際 `csv_line_start/end`；Markdown 表列用 `line:N`，XML 原件用標示的 XPath。不同定位形式不可混用。`transformation` 區分原樣複製、CSV 型別轉換與候選路線投影。

`input_sha256` 是實際讀取的包內檔案；`source_sha256` 是該資料引用的原內容／member；`source_git_blob_sha1`、`source_commit`、`source_member`、`carrier_sha256` 另列。相同 bytes 在包內其他路徑出現，只能證內容一致，不證歷史 Git 路徑／commit 的收錄情況。

## 2. 十個 Quest 的關聯核對表

下表的 Quest／NPC／Field／Chapter／scene membership 來自 T16 原表投影；副本採用、scene 排程及終點來自 S00 明示候選路線。原表 ID 和候選排程保留不同證據分類。前後繼使用每筆 `Demands` 關係推得，不以數字排序推論。

| Quest | 宣告前置 → 後繼 | Giver／Finisher NPC | Field 原欄位 | S00 候選旅程 |
| --- | --- | --- | --- | --- |
| 117 | 15 → 118 | 10002 | 缺失，保留 `null` | scene1，返回村莊控制 |
| 118 | 117 → 119 | 10047 | 28 | 只有 scene1；不可從 Field28 自動選入 Case109 |
| 119 | 118 → 120 | 10047 | 26 | scene1；Case107，Map632→633→634→635；進場2／Boss3／清怪後4／返回5 |
| 120 | 119 → 121 | 10008 | 缺失，保留 `null` | scene1→2→3，純敘事；腳本內換景不等於副本入場 |
| 121 | 120 → 122 | 10002 | 缺失，保留 `null` | scene1 |
| 122 | 121 → 123 | 10002 | 27 | scene1；Case108，Map636→637→638→639；進場2／Boss3／清怪後4／返回5 |
| 123 | 122 → 124 | 10048 | 缺失，保留 `null` | scene1；10048 與同名 10047 是不同 NPC ID |
| 124 | 123 → 131 | 10048 | 17 | scene1；Case101，Map184→185→186→187；各圖進場2／3／4／5，清怪後6，返回7 |
| 131 | 124 → 132 | 10002 | 缺失，保留 `null` | scene1；Quest town1，Chapter2 town2 |
| 132 | 131 → 133 | 10002 | 28 | scene1；Case109，Map640→641→642→643；scene2 對應第三圖642，Boss3／清怪後4／返回5；終點 Town2／Map183 |

共 **10 個 Quest、30 個複合 scene key**。scene key 必須同時保留 QuestID 與 scene index；scene1 不是全域唯一 ID。Quest15、Quest133 是本輪邊界外的前置／後繼參照，不刪除、不當作缺失，也不擴張本輪為完整 Q133 旅程。

Q131／Q132 的 `Quest town=1` 與 `Chapter town=2` 分欄保存。Chapter membership 不等於玩家當前城鎮；不可用 Chapter town 覆蓋 Quest town 或合成出生地。

## 3. 語意與來源保全

### 原始事實、政策與候選

1. **原表／來源投影**：保留原 QuestID、NPCID、Field、Case、Map、Chapter、scene、raw attributes、原始 Demands、原有 presence／absence、來源 `evidence_kind` 與 SHA。
2. **T16 候選模型**：definition、flow、Scenario 不被重新解釋成已實作服務；原 activation、blocking issues、objective、reward、待綁定 predicate 逐項保留。
3. **S00 候選排程**：用獨立資料表達 NPC 敘事、編隊、地圖／scene cue、清怪、返回與終點。選定 cluster、排程及安全位置是 Server 重建政策，不是官方波次／MEF 的還原。
4. **使用者政策**：例如清怪後仍能戰鬥、走到傳送陣按 Z 才前進，沿用來源中的政策分類；不升格為原生程式事實。
5. **未知與未支援**：保留 `null`、`UNKNOWN`、原始描述及阻擋原因。空 CSV 欄位不填 0、false、無獎勵或無條件。

### 必須分開的事件

任務接取、敘事播放、scene receipt、編隊／Scenario admission、副本結果、返回村莊、合法 Quest 完成、獎勵入帳是不同階段。工具不建立「接取即完成」「scene 播完即付獎」「有 Field 就開副本」的隱含規則。Q118 的既有 Scenario 候選關聯可以保留為資料，但不因此成為這一段 S00 旅程的副本排程。

NPC resource ID 不當作 world EntityId 或 NPC event selector；formation token 保持 opaque，不轉成 Quest／Case ID。Field、Case、Map、Quest 即使數字相同也不可跨 domain 互換。Table/SceneList 與 Event/SceneList 的 namespace、來源 SHA 亦分開保存。

## 4. SHA 與缺件的判讀

本次上傳包 `MANIFEST.json` 指定來源分析 commit：`fb6a78bf26fdfacdd5bc28ffcb1b63b011487307`。T16 內另有自己的分析基準、補充分析及 Server 候選 commit；各自保留，不一律改成目前 main。

| 原件範圍 | 本輪判讀 |
| --- | --- |
| 上傳包 manifest 逐檔內容 | 核對實際 bytes／SHA256；每筆結果在驗證報告 |
| 本地 Table carrier | `ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c`，是 local variant，不等同 T01 原始 carrier |
| 有原始 member SHA 可比對者 | `_MapList.xml`、`_CaseList.xml`、`_TownList.xml`、`QuestInfo.xml`、`_ActorList.xml` 個別核對；載體不同不代表所有 member 不同 |
| 沒有既有原始 member 清單者 | `CharSkill.xml`、`SkillActiveTable.xml`、`Skill/SkillMatrix.xml`、`IndependentSkillEffect.xml` 保留 `NOT_IN_EXISTING_ORIGINAL_MEMBER_MANIFEST`，不宣稱符合原件 |
| Field Chart／Cluster | 本包有獨立 pin；Case107/108/101/109 補件可核對，但不解除合法完成／MEF／UI gate |
| 只有投影或歷史 hash 的 member | 列為原件未在本包直接讀到；不得用投影存在冒稱已重解原件 |
| T16 內部 manifest 宣告但本包未附的檔案 | 逐檔報告，與壞 hash／主線 ID 遺失分開，不為了消除報告而執行舊 validator |

沒有重新讀取 project 中另外附的 BIN／STP；本輪限於 W3 指定資料包完成離線轉換。未搜尋 MEF、未找影片、未要求玩家補拍截圖。

## 5. S00／Server 開發需求

以下是 T16 正式 Quest 模型尚待綁定的契約，供 S00 依既有流程去重登錄；不是新的正式 REQ 台帳，也沒有替 S00 核准規格。這不是現行 Server 的全面實作盤點：本包 S00 continuation 已記錄旅程、編隊、16 個遭遇、手動 portal、結果／返回與 80 個 checkpoint 的候選實作和正常合成驗證；本輪沒有讀取目前 Server 私庫或驗收該實作。

| 分類 | 可直接使用的內容 | 還需要完成的工作 |
| --- | --- | --- |
| **Server 待開發**：接取與資格 | 原表 Demands、NPC、raw level、typed IDs、候選 flow | 明確定義 progress scope、eligibility、acceptance、NPC visibility、角色限制及 repeat／branch policy；raw level 不自行變成核准規則 |
| **Server 待開發**：目標與結算 | 每 Quest 的 objective／reward 欄位及阻擋項 | 綁定合法目標證據、數量／作用域、完成 gate、交付／commit、reward grant domain／recipient／換算／持久化與發布；scene receipt 不充作結算 |
| **Server 待開發／整合**：Scenario 契約 | Field→Case 候選關聯、四條 S00 旅程、明示 scene cue 與資料來源 | 將既有 S00 候選 admission／formation／outcome／portal／result／return 服務與版本化內容、合法 Quest 完成／結算契約逐項綁定；未核准規則仍屬候選，有限 cluster 不當作官方總怪數 |
| **跨功能待整合** | 原有 flow／wire adapter／Scenario 欄位及本次 catalog | 將通用 handler 與審核後的資料綁定，逐項維持 NPC 對話／scene／loading／ready／world 生命周期；不需要為每個 Quest 另抄一份 handler |
| **Client 待逆向／介面待補證** | 包內已有限定 producer／consumer 來源 | 來源明列仍未閉合的 UI 意圖／回覆欄位、NPC dialog release、scene receipt 成敗辨識、cleanup／ready 與 callback 對應；正式 grant 策略及結算歸 Server，本輪不猜 wire 值、不改 Client |
| **待遊玩驗證** | 正常路線及逐 Quest 審閱資料 | 在 Server 實作與 S00 採用後另做原版 Client 正流程驗收；本輪未跑遊戲，來源 NOT_RUN 保留 |

S00 可先採用本工具作內容匯入前的檢核、來源追蹤與批次比較。各 Quest 能否啟用仍取決於具名條件與服務綁定，不能把 catalog 可讀或 hash 一致當成已具備完整遊玩規則。

## 6. 本輪範圍與 Git 邊界

本次使用者明確指定既有 `extra/roy3`，優先於工作包一般性的直接 main 指示。最新 main 政策與來源先核對，沿既有分支保存本目錄成果；不改其他 W1/W2、Task owner、RR 台帳、CLM／SPEC／ADR 或原 T16 包。

實際開工基準見 [preflight.json](preflight.json)，內容／原表獨立稽核及實際讀取清單見 [SOURCE-AUDIT.md](SOURCE-AUDIT.md) 與 [source-audit.json](source-audit.json)。所有本輪證據都是離線資料／程式驗證；未宣稱直接機器碼驗證或遊戲驗收。

## 7. 已完成的離線驗證

正式附檔對應 converter SHA256：

`5e9d8a99fe0bd092a4b34388d500e3a7c359ea8055a312843601334a601155dc`

| 檢核 | 實際結果 |
| --- | --- |
| 原包轉換 | PASS，0 errors；13 張 CSV／704 列 |
| 範圍 | 10 Quest、30 scene、60 NPC 關聯、2 個既有 T16 flow、5 個 T16 Scenario；4 條 S00 副本路線、18 個 Map 摘要 |
| 原件完整性 | MANIFEST 130 檔 SHA／大小吻合；含 MANIFEST 自身在內的 131 個輸入檔案前後不變 |
| 可重現 | 獨立啟動兩次 CLI，三個輸出逐 byte 相同 |
| 來源定位 | 10,798 筆全部核對來源 SHA、輸出 pointer 及輸入位置；5,781 個 CSV cell、4,793 個 JSON pointer、220 個 Markdown 行、4 個 XML 位置，0 定位錯誤 |
| 模型保真 | 選定 definitions、flows、Scenario 與原 JSON 精確相等，包含 `null`、來源、blockers 及啟用狀態；CSV 另行依契約解析比對 |
| 指定格式／引用約束 | 5 個拋棄式副本探針均取得預期診斷，且非因外層 checksum 失敗才攔下 |
| 啟用／遊戲 | 仍為 `DRAFT_BLOCKED`；未啟動 Client／Server、未執行舊證據腳本或本專案暫緩的遊戲測試 |

獨立正常輸入驗證器不 import converter，而是重新解析來源、兩次呼叫 CLI 並核對實際產物；79,186 個斷言是資料比較數量，不是遊戲測試案例數。詳細結果見 [verification-normal-report.json](verification-normal-report.json)。

五個格式探針依次是重複 QuestID、NPC association 指向另一 Quest 的 scene、flow Quest 參照混入 NPC domain、刪除 objective CSV 投影、同時改錯 canonical 與 CSV 的 town 欄位。探針只修改 temporary 副本，並重算副本 manifest，確認實質引用／原 XML 對照檢查能發現問題；這些人工資料不是原生證據。結果見 [verification-integrity-report.json](verification-integrity-report.json)。

重新執行（`--report` 指向來源目錄之外的報告檔）：

```powershell
py -3 verify_normal_input.py --input "E:\Tartaros\W1-W2-W3-input" --report "E:\Tartaros\W3-checks\normal.json"
py -3 verify_integrity_contracts.py --input "E:\Tartaros\W1-W2-W3-input" --report "E:\Tartaros\W3-checks\integrity.json"
```

這兩個驗證器固定驗收本次十 Quest 工作包；它們不宣稱涵蓋未來所有主線、完整 JSON Schema、所有錯誤輸入或遊戲行為。未來更換來源版本時應先核對新範圍與差異，再調整正常驗收預期。

`validation-report.json` 有 1,020 筆可定位的 UNKNOWN 記錄，包含同一政策在不同 Quest／欄位的重複作用點，**不是 1,020 個獨立功能缺口**。歷史 `MAP_GRAPH_RESOURCE_MISSING` 附上 `HISTORICAL_T16_SNAPSHOT` 及目前補充 members 的 hash 狀態；本包已補件的 Case 不會被誤稱仍缺原件。未支援／未綁定條件均保留，不以刪除未知換取 PASS。
