# Q model 1086：ID／FILE 選擇已閉合，PRE 不參與此 catalog key

本輪把 Q119/3 的 model 1086 從「有同名 ActorList 與 Base descriptor」推進到原生 catalog producer／consumer 的同鍵鏈。**這條模型註冊路徑只用 Actor.ID 作數值 key；PRE 雖被轉成整數，結果隨即丟棄。** 因此不再要求為 Q model catalog 選 PRE1／2／5，也不能把 world Cluster 的 PRE1 帶入此 key。1086 的有效 FILE 為 `02_Stoncken`，原生查詢 basename 確為 `02_Stoncken.abf`。[原件視窗](native-evidence.json)、[當前結果](selection-result.json)

**完整 runtime 路徑仍保留 null，原因已縮成具體的快取／目錄與掛載證據。** 原生會從 `CHA_ABF` entry 取 directory 和 filename，再拼接交給 reader；它不是直接把 ActorList FILE 加上 `Mon/`。初始 `CHA_ABF` 可由 `fcs.flu` 建立；無快取的 fallback 則掃描 `Character/` 下的 `*.abf`，包含子目錄。現有 Base 中的真成員 `Mon/02_Stoncken.abf` 是可核的候選，尚未與該安裝的實際 entry、目錄及 mounted carrier 綁定。[selection-result.json](selection-result.json)

## 1. 原件及研究範圍

工作 branch 沿用 `extra/roy1`；研究基線 `5ef4ab8870ea1c65c6c7497901302d851f5c7a51`，main 導航讀集固定 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。治理沿用同包 resources 的固定讀集。此次只追 model 1086 的數值 key、ActorList producer、descriptor basename／prefix；未執行 Client、Lua、Server 或 archive 程式，沒有生成原生資源或 fcs 快取。[source-manifest.json](source-manifest.json)

| 原件 | SHA-256 | 本輪用途 |
|---|---|---|
| `02-Tartaros.bin` | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` | 原始 PE 指令、常值、資料流 |
| `07-Table.stp` | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` | 真 `_ActorList.xml` 的 1086 三列 |
| `Base.stp` | `1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957` | 完整 index 的同 basename 候選與選中 CharacterList |

Q119/3 三個 CreateObject 呼叫及已證的 low-WORD／預掃描規則，復用 [resources 原序列依賴](../resources/selected-dependencies.json) 和既有 `MEF-content-contracts-20261116/bridge`。本輪對四個已公開的預掃描／正式 consumer 視窗重新比對原 BIN bytes；沒有把這些舊成果重報為新發現。

## 2. category／PRE 的裁定

`0x540B10` 的原字串包含 `RegisterAllAvatarBase`。其 `0x540C07` 構造 `Table/_ActorList.xml`，以 `0x714770` 開啟，再讀 ACTORLIST／OBJCATEGORY／ACTOR。這是本次從原字串交叉引用追出的模型 catalog producer；不是另一路讀取名稱、SCALE、SPECIES 等屬性的 actor 統計表。

| 已核位置 | 原生資料流 | 結論 |
|---|---|---|
| `0x540D00`、`0x540D3D` | category 的 ID 轉整數，與 3 比較；等於 3 時略過該 category | category 是准入條件，未與 model ID 合成 key |
| `0x540DA9`、`0x540DB9` | Actor.ID 經十進位轉換，存入 `[ebp-0x150]` | 後續數值 key 的來源 |
| `0x540DCE`、`0x540DF3` | 查 PRE 並轉整數，回傳 EAX 未寫回 ID local，也未寫入另一個 catalog key | PRE 結果在這條註冊鏈未被採用 |
| `0x540DFB`、`0x6BDE40` | 傳入 ID local 的指標；helper 配置新節點後只將該 ID 複製到節點 +0C | 不是把前一個 PRE 回傳值暗中作為 key |
| `0x540E77`、`0x540E8F`、`0x540E9D` | 原 ID 作 `uint → string` map 的 key；FILE 字串賦值給 map value | 同 ID 的後列會覆寫 FILE 值 |
| `0x4F7DF0` | 以 node +0C 比較 uint key，存在時回傳原 node +10 的字串位置 | key 沒有 category／PRE tuple |

上述位置均保存完整指令邊界、file offset 和 byte hash；PRE 轉換後至 ID map 寫入的分支也包含於證據，而不只憑 decompiler 的變數名稱判讀。[native-evidence.json](native-evidence.json)

原 `_ActorList.xml` 中所有 ID=1086 的列如下；全表精確比對沒有另一個 category 的同 ID 列：

| category ID | category 內 Actor ordinal（從 0 起算） | ID | PRE | FILE |
|---:|---:|---:|---:|---|
| 1 | 256 | 1086 | 1 | `02_Stoncken` |
| 1 | 257 | 1086 | 2 | `02_Stoncken` |
| 1 | 258 | 1086 | 5 | `02_Stoncken` |

XML decoded SHA-256 為 `b01ae70817c79126b89292567e32d4c806c3ef31478b6a2eb96dcfd21e2c78f7`。依此原生賦值規則，這三列都寫入 `1086 → 02_Stoncken`，所以結果沒有歧義。最後來源列的 PRE 是 5，但 **catalog 並未保留或選定 PRE5**；這個數字只描述資料行次序。當前結果使用 `selected_PRE_status=NOT_A_MODEL_CATALOG_KEY_FIELD`，而不是缺少某個 PRE 的標記。此裁定不延伸到 world actor／怪物屬性 lookup。[selection-result.json](selection-result.json)

## 3. FILE → basename → 同一數值 alias → reader

`0x540FA0` 迭代暫存 ID map，取 FILE；`0x540FD8` 加上原常值 `.abf`。`0x54105C` 以 `CHA_ABF` 及這個 basename 呼叫 `0x716740`。entry 為 null 就跳過本次模型 catalog 註冊，因此「ActorList 有 ID」仍不等於 runtime model catalog 一定有記錄。

成功時，`0x5410AE` 至 `0x541167` 以 FILE stem 和資源 entry 的兩個字串呼叫 `0x79D610`；接著 `0x5411C4` 從同一暫存 map node 的 +0C 取原 ID，呼叫 `0x79D8E0(ID, stem)`，把數值 ID 指向同一個已註冊的模型記錄。這將 Q／預掃描使用的 1086 與 FILE 記錄接上，而不需要從 world entity 或 PRE 猜測。[native-evidence.json](native-evidence.json)

| 結構 | 欄位 | 經原件核對的內容 |
|---|---|---|
| `CHA_ABF` 找到的資源 entry | +00 | directory 字串 |
| 同一資源 entry | +1C | filename 字串 |
| 模型 catalog record | +00 | FILE stem：本例 `02_Stoncken` |
| 同一模型 record | +1C | 資源 entry 的 filename |
| 同一模型 record | +38 | 資源 entry 的 directory |
| 同一模型 record | +54 | reader 成功後寫入的 materialized resource 指標 |

`0x79D570` 以數值 model key 找 record，把 +38 的 directory 放入 reader 的 stack argument，把 +1C 的 filename 放入 EDX。`0x7AC4EE` 至 `0x7AC565` 先複製 directory，再 append filename，將合成字串交給 `0x714770`。所以這條轉換現已證明為：

```text
1086 -> FILE "02_Stoncken"
basename = FILE + ".abf"
entry = CHA_ABF.lookup(normalize(basename))
requested_path = entry.directory + entry.filename
```

這是研究用關係表示，並非可部署的 Client 或 Server 程式。lookup 的 basename 經 `0x7198B0`／CRT uppercase helper；`0x893704` 的預設分支將 ASCII a..z 轉大寫，另有 locale 分支。本例的 ASCII inventory key 為 `02_STONCKEN.ABF`。工具只用該 key 對本次 Base 名單找候選，不冒充完整 native locale、hash、碰撞或 package precedence 演算法。[native-evidence.json](native-evidence.json)

## 4. 為何完整 prefix 仍不可填死

### 4.1 `fcs.flu` 快取能提供 directory

`0x79916B` 先呼 `0x716440`。後者以 `rb` 開啟原常值 `fcs.flu`；不存在時回 false。快取入口會讀 8-byte header、`0x158` 大小的 group 記錄與 `0x218` 大小的 entry 記錄。針對本案真正需要的是 `CHA_ABF` 下 basename `02_STONCKEN.ABF` 所對應的 entry，而不是整套新 cache 格式實作。

`0x7166B7` 顯示每筆 entry 的 directory 位於 +10、filename 位於 +114；兩者傳入 `0x7198F0`，分別寫入資源 entry +00／+1C。故 runtime prefix 是這筆實際資料，不能由 ActorList 的 category 1 自行翻成 `Mon/`。[native-evidence.json](native-evidence.json)

### 4.2 無快取 fallback 是 `Character/` 遞迴目錄

`0x7991AC` 的原生呼叫註冊 `CHA_ABF`，pattern=`*.abf`，directory=`Character/`，recursive=1。`0x716240` 將這組值交 `0x718FB0`；後者組成 directory+pattern，呼叫 FindFirstFileA，遞迴加入子目錄，將發現的 directory 與 cFileName 分別保存。這證明有明確的預設目錄規則，**並不證明本次 Base 內的 `Mon/` 被掛在該目錄哪一層**。同名衝突、既有快取及不同安裝目錄也不能用本次 index 模擬填補。[native-evidence.json](native-evidence.json)

### 4.3 Base 的正向證據與剩餘缺口

本次 Base 的 830 個 index 成員中，與此 basename 相符的只有 `Mon/02_Stoncken.abf`；已實際解碼為 CharacterList，SHA-256 為 `60002f80fa587d3058ff764eab7df696e107040148016744ae48c7a3527985fd`。Character 宣告 `RelativePath="02_Stoncken/"`、`BaseFile="Stoncken_BASE.gb3"`；六個需要的 action 1、4、8、11、101、103 仍均存在，詳細 payload／effect／audio 缺口沿用 [資源報告](../resources/report.md)。[selection-result.json](selection-result.json)

現在已能填：`catalog_uint_key=1086`、`FILE=02_Stoncken`、`requested_descriptor_basename=02_Stoncken.abf`、`native_path_rule_status=PROVEN`。仍不能填 `native_selected_directory`、`native_selected_descriptor_path` 或 native open／parse／render 成功。**缺的已不是「哪一個 PRE」或「FILE 如何變 basename」，而是同版的實際 `CHA_ABF` directory／filename entry，與它指向哪個已掛載 carrier 的綁定。** 不以字面拼接 `Character/` + `Mon/` 來替代這項證據。

## 5. 對現有 Server／內容工具的直接影響

沿用 REQ-0019／REQ-0021 的原需求對應及目前 CANDIDATE 狀態，不新增正式需求、不改台帳。Town1 Q119 的依賴紀錄可立刻採用已證的數值 model key、FILE stem、descriptor basename，將 PRE 欄標為此 catalog 不適用；world actor 的 PRE 與屬性依舊分開保存。既有 Server 情節流程無需為了這個先前的假缺欄再增加一套 Q PRE 選擇規則。[原需求映射](../resources/dependency-contract.json)

下一筆來源需求可明確寫成：同版 `fcs.flu` 的 CHA_ABF 目標 entry，或無快取掃描所得的 directory／filename；配套安裝／mounted carrier root、覆蓋順序及 hash；之後再取得該 descriptor 需要的 GB3／DDS／EFF／WAV payload。若只得到 basename，不得將模型宣告、payload 齊備、native load 成功與 Server 完成／結算混成一種 ready。這仍是內容預驗與來源治理需求，沒有改動原生訊息或 Server 權威完成語義。

## 6. 可重現驗證

實際執行結果為 `PASS_REPRODUCIBLE_RESEARCH`：三份原件與 22 份 published pins；37 個有完整邊界的原 BIN 視窗共 3,366 bytes、15 個原字串；另外比對四個既有視窗共 3,551 bytes。重新讀原 ActorList 和 Base 後，三列來源、有效 FILE、唯一 basename 候選與六 action 宣告均與保存 JSON 相同。[verification-result.json](verification-result.json)

```sh
python kr-extra-roy/MEF-comprehensive-contracts-20261117/resource-selection/verify_evidence.py \
  --sources /path/to/supplied-originals \
  --supplemental /path/to/supplemental \
  --repo .
```

`--result` 可指定研究驗證收據的輸出檔；其餘來源僅讀。PASS 證明來源／原件節錄及本項研究可重現；`ready=false`、`deployment_artifact=false` 保持不變。`selected-dependencies.json` 的歷史三載體輸出不重寫；當前選擇鏈以本包 `selection-result.json` 為準，resources 的當前 prose／contract 已加交叉引用。
