# MEF 資源相依：三載體盤點、原序列閉合與唯讀預驗工具

本輪把「有 API／腳本名稱」往前推進成可重跑的資源相依審計：完整讀取附帶 Event、Table、BoundMap 的目錄，對原 Q119/3 的模型／動作、鏡頭、對白、音訊與地圖關係逐層核對，另核 Q2440/5 的一個原圖像依賴。接著從補充的 Base 取得真 `Mon/02_Stoncken.abf` 和六個需要的動作宣告，從 W1/W2/W3 ZIP 補到 Field26／Case107／Map635 的原資料關係；完整增補及來源界線見 §8。新增工具能指出欠缺的 carrier、未解的鍵轉換和版本資料，保留 `ready=false`。它不產生可部署腳本、原生 `.mef`、新座標或替代圖像。

**後續定向原件核對已補閉模型選擇鏈的一段：Q model 1086 的 catalog key 只用 Actor.ID，PRE 不參與；FILE 加 `.abf` 後查 `CHA_ABF`，reader 使用該 entry 的 directory+filename。** 實際 `fcs.flu` entry／目錄及 mount 版本仍未取得，所以完整 runtime path 保留 null。當前結論以 [resource-selection](../resource-selection/report.md) 為準，不再將 PRE 選擇列為此 Q model catalog 的缺欄。

**本包的新成果是相依圖與預驗工具，不是再次宣告舊 API 分析完成。** 模型預掃描、鏡頭 loader、對話 UI、STP 優先和 checksum 的 native 行為均明示復用；本次重新對原 BIN 核對其中 21 個既有視窗、10,981 bytes。其 PASS 僅代表固定來源與研究輸出可重現。[來源](source-manifest.json)、[原件復用](native-reuse-evidence.json)、[驗證收據](verification-result.json)

## 1. 來源及盤點邊界

工作 branch 為既有 `extra/roy1`；研究基線 `5ef4ab8870ea1c65c6c7497901302d851f5c7a51`。治理 readset 固定 main `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。所有原件只讀，沒有執行 Client、Lua 或 Server，沒有改原資源、分支、正式需求或任務狀態。[readset](governance-readset.json)

| 原載體 | SHA-256 | 完整目錄成員數 | 主要內容 |
|---|---|---:|---|
| `06-Event.stp` | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` | 7,382 | 5,535 `.cam`、1,840 `.seq`、3 `.lua`、SceneList 等 |
| `07-Table.stp` | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` | 1,026 | 1,015 XML，以及文字、Lua／BLT 成員 |
| `10-BoundMap.stp` | `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8` | 1,296 | 1,296 `.bnd` |

這三份 index 沒有 `.fld`、`.dds`、`.ogg`、`.wav` 或 `.mef` 成員；此處是**明示載體範圍**，不能擴成整個 Client 安裝缺件。實際掛載的其他包、散檔、版本覆蓋、locale、cwd 和快取均未由本讀集取得。完整成員名不公開搬移；保存排序後名稱摘要與 SHA，選中成員則保存 block ID、stored offset/length、stored/decoded hash。[carrier-inventory.json](carrier-inventory.json)、[member-evidence.json](member-evidence.json)

原 BIN 為 SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。STPD/EX 解碼使用已審讀並固定 hash 的既有 `MEF-world-identity-scene-interaction-20261117/stp_reader.py`；不執行 archive 內的成員。本包沒有使用 launcher EXE 得出新的結論。初始三載體輸出和後來補充的 Base/ZIP 輸出分開，避免把早先範圍內缺件誤寫成補證後仍完全沒有 descriptor。

## 2. 新增與復用範圍

| 項目 | 本輪處理 |
|---|---|
| Q119/3 原序列與 1086 演出例 | 既有 scenario-controls 已指出；本輪延伸為表、鏡頭、文字、音效及 BoundMap 的跨載體相依核對。 |
| 模型預掃描、low WORD、first-model、action gate | 復用 `MEF-content-contracts-20261116/bridge`；本輪只對選定原始直線序列重算具體集合。 |
| qbase 的鏡頭／音樂路徑前綴、對話顯示 catalog | 復用 `MEF-capabilities-20261116`；本輪核實實際原成員與缺少的依賴。 |
| Table 的 26 份有效文字表、50,222 文字列 | 舊 dialogue-ui 已有；本輪重核以確認選中 5 個 key 的來源與唯一 match，不列為新 census。 |
| 1,837 文字 seq → 鏡頭 literal 關係 | 新增有限完整 lexer 掃描、43 個 exact miss、case variant 及 SceneList 交叉核對。 |
| 5,535 cam 的結構觀測 | 新增資料形狀審計；清楚區分 Python parser 行為與原生 TinyXML/數字 parser。 |
| 可執行唯讀預驗器、缺欄契約 | 新增；只輸出研究 JSON，依賴未閉合時不放行 ready。 |
| Base / W1-W2-W3 補充資料 | 新增實際 bytes 核對：830 ABF index、選中 CharacterList／動作／轉依賴；ZIP 131 項與全部 130 份 manifest 記錄，9 份 Table 與原載體逐 byte 相同。 |

## 3. Q119/3：可正向閉合到哪一層

原 `Event/SceneList.xml` 唯一選中 `(questIdx=119, sceneIdx=3)`，`funcName=Phindous_YuriandRazed_Boss`、`endBehavior=0`。對應 `.seq` decoded SHA-256 為 `05abe5f9773c3b0b40d5a849f7d984b4f06f57d2e5a5fe8c931e83ec2d7b857a`。本包只保存 22 個相依呼叫節錄與其行號，不公開整份原序列。[selected-dependencies.json](selected-dependencies.json)

| 相依 | 原始請求與正向關係 | 本讀集已取得 | 仍未取得／不能推論 |
|---|---|---|---|
| 模型／動作 | 三個 Q slots 使用 model 1086；`Create/Ani/Walk` 宣告動作 | ActorList 三列同 FILE `02_Stoncken`；原生 ID key／PRE 排除、FILE+.abf 與 CHA_ABF 字串拼接已證；Base 有真 CharacterList 和六個動作宣告（§8） | 同版 CHA_ABF entry 的實際 directory／filename 與 mount 綁定，GB3／texture／effect／audio payload。 |
| 鏡頭 | `PlayCamera("Phin_YuriandRazed_Boss_01.cam",0,0,0,0)`；既有 qbase 加 `Event/CameraWorks/` | exact `.cam` 存在，兩個 keyframe 的 `framepos` 為 0、140 | 實際 native open、插值、畫面與完成等待未在本輪執行；framepos 不是承諾的毫秒。 |
| 對白 | `OpenTalkScene(12,11)` → 五列 Talk | 五個 key 1287..1291 均在有效 `04_Phindous.xml`；保留 face、字數與文字 hash | 顯示 actor 1/2/3 的擴充 catalog、頭像／face 圖、語音選擇與 payload。 |
| 音訊 | BGM024 及三個 Stoncken WAV | `MUSIC_BOSS` 名稱表對到 `Sound/BGM024.ogg`；三個 WAV 的 Sound rows 與 SoundBaseDir 均存在 | 聲音 bytes 不在三載體；設定表存在不能保證 stream／backend 已可播放。 |
| 地圖 | `LoadMap("mushroom12D.fld")`；相同 stem 可 join MapList | 七個 MapList 候選共同宣告 BOUND `mushroom12`；真 BND 存在。補充 ZIP 取得 Quest119/Case107/Field26 的 Map635 context（§8） | `.fld`／地形模型與貼圖 payload、實際 scene→node/instance、portal/spawn。這個 join 不證明 Q.LoadMap 在此會消費該 BND。 |

### 3.1 模型表與動作表是兩層

按已證的預掃描整數契約重算原呼叫，得到：

| Q slot WORD | Model WORD | Collector action WORD 集合 |
|---:|---:|---|
| 0 | 1086 | 1、4、8、11、101 |
| 1 | 1086 | 1、4 |
| 2 | 1086 | 1、4、8、11、103 |

計算保留 exact arity、第一次 model、low WORD、Create 新列 action=0→1，以及 Walk gate=0 不收集的規則。原第 40/41 行 gate 為 0 的 Walk 不因此新增 action；本例 action 11 另由後面的 Ani 明示加入。這是選定直線原資料的契約重算，不是執行 Lua，也沒有對所有分支做靜態求值。[舊 bridge 契約與原件 refs 見 source-manifest]

`_ActorList.xml` 中 model 1086 有 PRE 1、2、5 三列。後續原件追到 `540B10` 的 catalog producer：略過 category 3，僅以 Actor.ID 作 uint key，解析 PRE 後丟棄結果，再以 FILE 賦值；同 ID 後列覆寫 FILE，本例三列都是 `02_Stoncken`，所以沒有 Q catalog 的 PRE 選擇歧義。`79D570` 從 record +38／+1C 取 directory／filename，`7AC4C0` 按此順序拼接；實際 directory 來自 `CHA_ABF`，仍需同版 `fcs.flu` 或目錄掃描與掛載證據。原先的「PRE/category/FILE 轉換未證」已由 [resource-selection](../resource-selection/report.md) 收窄，world actor PRE 仍是另一個 domain。

初始三載體未含 descriptor；補充 Base 後已取得同 basename 的真 CharacterList 和所需六個 action declarations，但 **該 runtime entry 綁到此份 Base bytes、子資源 payload 與 native load 成功** 仍未閉合。初始 `selected-dependencies.json` 的 null 只代表其明示三載體範圍，Base／ZIP 的原資料補證在 `supplemental-audit.json`；當前選擇鏈以 `../resource-selection/selection-result.json` 為準。[native-reuse-evidence.json](native-reuse-evidence.json)、[supplemental-audit.json](supplemental-audit.json)

**原預掃描不是完整依賴檢查。** 它只在已證的 callback 範圍收集模型／動作和最後音樂字串，不會替內容工具保證圖像、對話顯示、相機、音訊、貼圖及轉依賴都齊備；模型 event 或 request 返回亦不等於全部資源成功。這正是獨立預驗器可立即補上的 Server／內容工具需求。

### 3.2 對白的文字、顯示身份與語音分開

`ScenarioTalk(12,11)` 的 display actor 依序為 `3,2,1,3,2`，talk key 為 `1287..1291`；五份文字記錄的 face 依序為 `8,6,6,8,2`。文字只保存 UTF-8 hash、字數和原表 locator，不另公開全部台詞。

本次讀取 **26 個有效 SET PATH**。Table index 另有 27 份 TalkTable member；「包內有成員」和「TalkTableSet 有效引用」不能混算。原 XML 中註解的 SET 不生效。這與既有 dialogue-ui 的 26／50,222 統計相符。

這三個 display actor 在 supplied `Table/npctable.xml` 沒有對應列，不能立即宣告角色 key 錯誤：既有 `5247D0` load order 明示還會讀 `Image/TalkNPC.xml` 延伸名稱、face group 與表情。該 image descriptor 不在三載體。**display actor、Q slot、model 和 world EntityId 是不同 domain**；值碰巧相等不構成映射。

native display 會以 talk key 呼語音 selector；實際 locale／版本／選中文件未取得。本包不把 key 1287 任意格式化為一個猜測的 `.ogg` 路徑。語音是可選還是必要，應由已選功能 profile 明示；本次不假定原生缺語音一定使場景失敗，也不以無聲可用推定完整視聽要求已達成。

### 3.3 音效表正向，payload 未到

`_Sound.xml` 原有 `SoundBaseDir Path="Sound/"`。三個原始請求在相應 Sound declaration 也有相同 File：

| 原請求 | Setting |
|---|---|
| `Sound/Monster/Stoncken/Stoncken_SKILL01.wav` | Battle |
| `Sound/Monster/Stoncken/Stoncken_SKILL03.wav` | Battle |
| `Sound/Monster/Stoncken/Stoncken_DEAD.wav` | Damage |

`PlayMusic("BGM024.ogg")` 依原 qbase 加 `Sound/`，`_SoundList.txt` 的 `MUSIC_BOSS` 亦指向同名。這些是名稱／設定相依，尚未取得音訊 payload。原 `SetFinalMusic("")` 不代表必須存在名為 `Sound/` 的檔案；RestoreMap 的 fallback 取決於先前狀態，本次不製造這類假缺件。

### 3.4 地圖 stem 不是 Map ID

`mushroom12D` 在 `_MapList.xml` 對到 ID `19、635、934、1722、1938、2154、3438`，而且有不同 TRIGGER 名稱。七列都宣告 BOUND `mushroom12`；BoundMap 中 exact 成員可定位與 hash。這讓「地圖相依所需的碰撞 carrier 是否在讀集」有答案，不能據此替 Server 選其中一個 Map ID、執行 TRIGGER、填出生點，或把 Q LoadMap 的演出圖和戰鬥／導航 context 合併。

## 4. 圖像相依：補齊原資料層的單一證據

原 Q2440/5 `Aisen_01_After` 第 59 行：

```lua
FlyingObject("Image/Prologue/Aisen00_1.dds", 50, 30, 100, 100, 0, 0)
```

原 seq 的 decoded SHA-256 為 `22131443cd236fd9498847353da3e7b8f8862f05cfab3258932e8158c9be3258`。本例保留原參數，沒有為測試修改 fade 或替圖。三載體都沒有這個 exact path，也沒有 ASCII casefold 候選；需要原 image carrier 才能驗 texture 本身。既有圖像生命週期／DelFlyingObject 的 native 研究直接復用，本節不重新宣告該整條生命週期是新發現。本輪只審這個圖像依賴，沒有把整份 Q2440/5 的其他模型／地圖宣告成完整閉合。[selected_image](selected-dependencies.json)

## 5. 全文字 seq 的鏡頭相依審計

### 5.1 掃描方法與計數範圍

1,840 個 seq 中，1,837 個為本工具可解碼的文字，3 個 `phin_01_1/2/3.seq` 是 Lua bytecode，明列排除並保留 hash。工具先用輕量 Lua lexer 剝 line/long comments，把 escaped short string 和 long string 當完整 token，再識別括號形式的直接全域呼叫；不會計入註解、字串中的示例或 `function PlayCamera(...)` 定義，也不把 `Q.PlayCamera(...)` 當成此 helper。8 個 SYN 反例涵蓋上述風險、decimal escape、動態 expression 與非括號形式。[resource_audit.py](resource_audit.py)、[verify_evidence.py](verify_evidence.py)

目前這個固定文本集合沒有 lexer error、未支援的相依呼叫語法或非 literal 的 PlayCamera 路徑。這不代表 runtime 沒有動態依賴：別名、計算路徑、bytecode、qbase 內部、間接 native caller 與實際分支可達性均不在此 census。數字是原文字呼叫的**語彙出現次數**，不是實際執行次數或遊戲完成率。

| 結果 | 數量 |
|---|---:|
| `PlayCamera`／`PlayCameraNoWait` literal 呼叫 | 6,080 |
| 不同完整要求路徑 | 5,403 |
| exact index miss | 43 次／43 路徑 |
| 其中只有 ASCII 大小寫不同的候選 | 1 |
| 連本工具 ASCII casefold 候選都沒有 | 42 |
| 43 筆中，seq basename 沒有 exact SceneList.funcName | 37 |
| 有 exact SceneList selector 的 miss | 6（含上述 1 個大小寫候選） |

不能把 43 說成 43 個「已觸發壞鏡頭」。37 筆沒有這個明示 selector；另外 6 筆也只有選表可見性，未實測被 Server 選中。未有 selector 不證明其他 DoFile／caller 不可能到達。完整逐筆節錄、原 seq hash、候選與 selector rows 在 [camera-audit.json](camera-audit.json)。

### 5.2 最適合優先取得的六筆來源

| SceneList 雙鍵 | 要求的 CameraWorks 名稱 | 本讀集結果 |
|---|---|---|
| 1929/1 | `Arnica_17_Talkevent_01.cam` | 有 `Arnica_17_talkevent_01.cam` 大小寫候選 |
| 1928/2 | `Arnica_16_test.cam` | 三載體無候選 |
| 1915/2 | `Arnica_Ninth_Stage01Clear_08.cam` | 三載體無候選 |
| 0/54 | `Rade_Poison10_03.cam` | 三載體無候選 |
| 0/54 | `Rade_Poison10_05.cam` | 三載體無候選 |
| 0/54 | `Rade_Poison10_04.cam` | 三載體無候選 |

這不是要求替換原檔或修補 Client；應先取得目標版本完整資源清單／mount 來源，再看原生 lookup 選的是哪份資料。Q119/3 的選定鏡頭本身有 exact 成員，沒有混入這個缺候選集合。

### 5.3 不把 Python exact/casefold 當原生 lookup

舊 resource-gates 已核 StdFile checksum provider 會轉斜線與小寫；那是 `Integrity.xml` lookup 的 key 處理，不能套為 STP filename ID 規則。舊 delivery 原件 `714C50` 的 mounted directory 比較及 `7155B0` 的節點 `+11C`／成員 `+44` ID 查找在此重新核 bytes。因此本包只標記 `CASE_VARIANT_CANDIDATE`，不直接把那一筆視為 native 已可開啟或已失敗。

package 優先、ordinary fallback、checksum、parse 和實際演出仍為不同階段。只要檔名「看起來對」就將 ready 設 true，會掩蓋 package precedence、載入版本或 checksum 的問題。[既有 resource-gates/report.md 與 delivery 視窗的固定 blob 見 source-manifest]

### 5.4 cam 結構觀測：不設錯誤的共通門檻

工具對 5,535 cam 做保留原 hash 的資料形狀審計。為讀取結構，分析副本先忽略開頭 BOM／ASCII whitespace，元素名採 ASCII folding；這不修改原檔，也不聲稱重現 TinyXML 的容錯或 numeric parser。

| 原資料形狀觀測 | 數量 | 對預驗政策的限制 |
|---|---:|---|
| leading BOM／ASCII whitespace | 43 | 通用 XML library 的 declaration-at-start 失敗不能直接當 Client 失敗。 |
| 大寫 KeyFrame tag | 86 | 不能用 Python 的大小寫敏感 `.findall('keyframe')` 誤報零關鍵幀。 |
| 重複可轉數字 framepos | 271 | 未證 native 限制前，不設「必須嚴格遞增」為原版合法性判決。 |
| 可轉數字 framepos 有遞減 | 5 | 保留順序與來源，另核選中 native interpolation／sorting 行為。 |
| Python float 不能接受的 token | 1 | `End02_04_Stage02Clear_01.cam` 的 `150l`；native 數字轉換可能不同，這不是原生拒絕證據。 |
| 本工具 XML parser 仍不能讀 | 3 | `alsmr_rotrua108.cam`、`boss_24_Nemesis_03.cam`、`mushroom09D_01.cam`；保留 error、prefix 與 hash。 |

可解析的資料沒有觀測到零 keyframes。上表各類可重疊，不相加當「故障檔案數」。本輪沒有自行修正 XML 或猜測替代值。要提升原生格式判決，先精確核選中 raw bytes → 原 TinyXML/數字 consumer；要提升遊玩判決，需另行觀測 target Client。

## 6. 可接入既有 Server 的預驗契約

[dependency-contract.json](dependency-contract.json) 明列 namespace、原載體 hash、member decoded hash、line/locator、請求路徑或 catalog key、轉換證據、exact 命中、case 候選、選定版本、子依賴和 `native_open_parse_render_result`。未取得的欄位用 null；不寫出部署內容。

預驗器的三個輸出階段應分開：

1. **分析成功**：固定讀集都處理完；缺件是有效結果。
2. **相依已解**：已選功能所必需的直接與轉依賴都有來源、正確 namespace 與有效版本。catalog 列和 payload 是兩個檢查。
3. **功能驗收**：原生選取／開檔／parse、畫面效果／等待、清理及 Server 權威流程各有相應證據。不能由第一步自動升格。

本輪已完成第 1 步，選定相依有部分第 2 步正向結果；原資料不足的欄位保持明示。`--require-ready` 會完成報告但返回 **2**。verifier 反過來要求這個拒絕存在，避免缺原始依賴時誤報完整可用。

### 6.1 映回原需求，而不新建重複台帳

| 原 ID／來源 | 本包可直接供實作使用 | 本包沒有完成的部分 |
|---|---|---|
| **REQ-0019**：馮德斯主線分析與 Server 實作準備 | Q119/3 typed keys、可核相依、原表版本/hash、具體 null 欄位；可接到已存在的 Server-owned scenario pipeline | 原始 quest eligibility、合法進度、清組／結果／返回／獎勵保存、整村主線與正常實機驗收。 |
| **REQ-0021**：Town2 完整主線及後續功能排序 | 相同預驗器／版本來源模型可復用；保留穩定完成任務 ID 前綴與歷史來源 | 本輪未做 Town2 逐任務 coverage，不因工具可用而宣稱 Town2、銀行、裝備、商店、掉落／拾取完成。 |
| **MEF-FUNCTIONAL-COMPLETION** | 沿既有自訂 JSON／typed adapter 推進完整功能；相依驗證可獨立開發，不必等待未知官方 `.mef` 格式 | 仍須分開 Client 待逆向、Server 開發、跨功能整合及遊玩驗收。 |

兩個 REQ 在 pinned main 均為 `CANDIDATE`。REQ-0019 對應 `GAP-FLOW-0001 / GAP-SCENE-0001 / GAP-PROGRESS-0001`；REQ-0021 對應前兩項。共同相關 SPEC 是 `SPEC-FLOW-0001 / SPEC-SCENE-0001 / SPEC-CHAR-0001`。這是**研究交付映射**，沒有更動原台帳或聲稱它們已驗收。[source-manifest 需求摘錄](source-manifest.json)

### 6.2 指定缺少的原始資料，避免籠統說「還缺 runtime」

| 類別 | 需要補入的資料／欄位 | 後續工作歸屬 |
|---|---|---|
| 模型／動作 | ID-only catalog key、PRE 不參與、FILE+.abf 與 directory+filename 規則已證；需同版 CHA_ABF entry／mount 綁定、avatar/part、GB3／texture／nested effect/audio payload/hash | 取得指定快取／目錄／版本欄位與缺少的 payload carrier；Server 內容工具保存完整轉依賴，不另造 Q PRE 選擇規則。 |
| 地圖 | 已取得 Field26/Case107/Map635 資料 context；還需目標 scene→node/instance 綁定、原 `.fld`／mesh／texture carrier；合法 portal/spawn 若需新內容另取正向來源 | Server context 與內容需求；不從 BND 文件名或 MapChart editor 座標推算官方流程。 |
| 對話顯示 | `Image/TalkNPC.xml`、display actors 1/2/3 的名字／頭像／face group 與 texture locator | 原資源資料缺口；Server 要維護 display key 與世界事件的明示對應。 |
| 音訊 | BGM024、三 WAV 的原 sound carrier；需要語音的 profile 另補選中 locale/version/key→path | 原資產與發布完整性；worker/device 與播放完成是另項整合驗收。 |
| 圖像 | `Image/Prologue/Aisen00_1.dds` 的原 carrier／bytes/hash | 原資產缺口；圖像壽命沿已證契約整合。 |
| 內容版本 | target install 的 mount 順序、散檔可見性、Integrity 內容、cwd、已載入／快取版本 | Server 發布與整合需求；不靠增加 Server opcode 或 Client patch 解決。 |

在資料補齊前，Server 仍能開發：manifest 格式、typed identity 驗證、缺件診斷、內容版本管理與現有 scene adapter 的前置檢查。這些應接入已存在功能，避免再造第二套關卡／資產保存機制。正式遊玩流程以主線既有實作及目標版本測試為準；本包沒有否認主線已完成的 Server 邏輯。

## 7. 重驗方式與結果

在本目錄執行，`--sources` 指向唯讀原件資料夾、`--repo` 指向含上述固定 commit 的研究 repo：

```bash
python resource_audit.py --sources /path/to/project_sources --repo /path/to/ttr_anal_multi --supplemental /path/to/supplemental_resources/ttr --output-dir /tmp/mef-resource-audit --require-ready
python verify_evidence.py --sources /path/to/project_sources --repo /path/to/ttr_anal_multi --supplemental /path/to/supplemental_resources/ttr --result /tmp/mef-resource-verification.json
```

第一條在此讀集應退出 2，留下完整缺欄結果；第二條成功應退出 0，結果為 `PASS_REPRODUCIBLE_RESEARCH` 且 `ready=false`。已實際核對 7 個原始／補充輸入（含共用指令）、21 份已發表 source pins（含兩份僅導航的偽碼）、20 份 main 治理 pins、21 個原件視窗，重新生成五份資料 JSON 並逐項比較，8 個 lexer 反例全符預期。補充來源版本若不同會拒絕套用原結論。[verification-result.json](verification-result.json)

不以 21 視窗、6,080 呼叫或 PASS 數量換算 MEF 完成率。不含整份原 BIN/STP、完整 Lua source/bytecode、全部鏡頭或原台詞；Git 可收錄本包的分析碼、摘要、bounded excerpts、locators/hash 與明示未解欄位。

## 8. 補充 Base／W1-W2-W3：已解除的資料缺口與剩餘邊

### 8.1 整包身分與真實讀取範圍

| 補充來源 | Bytes | SHA-256 | 本輪核對 |
|---|---:|---|---|
| `Base.stp` | 946,961 | `1854de2926ffe7c6172a4b350900f3b5b1e03d9f1757fc22d50b440515ec6957` | 全 index 830 項，全部為 `Mon/*.abf`；定向讀選中 descriptor。 |
| `Tartaros-Web-AI-W1-W2-W3-input.zip` | 967,327 | `7587e67dd012a020f0276c8cfd6b791ad07f8f5e7867931481c94aa30abf3e1a` | 全 131 項；manifest 的 130 個非 manifest 成員均逐 bytes/length/SHA 核對。19 項是 local resources，其餘為舊研究／說明資料。 |

ZIP 內舊 AGENTS／MEF 停止說明／提示詞只視為歷史資料，沒有取代當前使用者要求或 main 政策，也未執行其中的程式。整包及完整解包內容均不上 Git；保存全部目錄的摘要 hash、選中成員 locators、19 份 local-resource 的來源 metadata 和有界結論。來源只保留檔名／hash／bytes，不含私人檔案識別碼或存取 URL。[supplemental-audit.json](supplemental-audit.json)

ZIP manifest 將 Table 標為 local variant，不能因它宣稱 `original_member_sha_match` 就直接採信。本次把其中 **9 份 Table XML 實際 bytes** 與本輪原 `07-Table.stp` 解碼結果逐一比較，全部相同，包含 `_ActorList`、`_MapList`、`_CaseList`、QuestInfo。Field 來源則有 ZIP manifest 的宣告 carrier SHA `18a375bd478133df276df6e97833e03140900454d5f04298ea508d0b67fcb73a`，本輪未取得整份 Field.stp，因此只驗 ZIP 內 payload/hash，不宣稱重驗該整包或其 runtime mount。

Base 的 bytes 固定，但它與指定安裝版本的掛載／選用仍未由 runtime 觀測。830 項全在 `Mon`，沒有 stem `soma`；因此既有 A1／transition 的 model1 角色 descriptor **仍不能由這包補齊**。

### 8.2 真 CharacterList 及六個動作已取得

`Mon/02_Stoncken.abf` 是實際存在的 archive member，block 88、stored offset 91,152、stored length 651；解碼長度 5,477，SHA-256 `60002f80fa587d3058ff764eab7df696e107040148016744ae48c7a3527985fd`。根為 `CharacterList`，唯一 Character 的原 attributes 是 `RelativePath="02_Stoncken/"`、`BaseFile="Stoncken_BASE.gb3"`，並宣告 `Stoncken.dds`。

20 個 Animation declarations 中，選定 Q119 預掃描需要的六個 ID 都有明確 File：

| Action ID | 原 File | 選定 descriptor 的額外子依賴 |
|---:|---|---|
| 1 | `Stoncken_WAIT01.gb3` | 無直接 child |
| 4 | `Stoncken_MOVE01.gb3` | 無直接 child |
| 8 | `Stoncken_STUN.gb3` | 無直接 child |
| 11 | `Stoncken_KNOCKED.gb3` | 無直接 child |
| 101 | `Stoncken_SKILL01.gb3` | `Effect/Monster/M_Stoncken-AttacK01.eff`；`Sound/Monster/Stoncken/Stoncken_SKILL01.wav` |
| 103 | `Stoncken_SKILL03.gb3` | `Effect/Monster/M_Stoncken-AttacK03.eff`；`Sound/Monster/Stoncken/Stoncken_SKILL03.wav` |

這是具體進展：已能驗動作 key 宣告是否存在、擴展兩個 EFF 和兩個 WAV 子依賴，而不再只說「模型檔待取得」。六個動作保留原 FrameSpeed、Repeat、FaceIndex 等 attributes，但本輪不替每欄建立未驗的完整語義。

原生已證 model1086 會以 `02_Stoncken.abf` 查 `CHA_ABF`，本次 Base 中唯一同 basename 成員就是這份真 CharacterList。PRE 不參與此 model key；尚缺的是實際 cache／目錄 entry 和 mount 綁定，`native_selected_descriptor_path` 因此保持 null。reader 的 directory+filename 規則已證，但不能把 `Mon/` 或 `Character/Mon/` 自行填成實際 prefix。[定向選擇鏈](../resource-selection/report.md) 其八種 GB3／DDS basename（base、六 motions、一 texture）在四份 STP 和 ZIP local-resource 名稱中都無候選；四個顯式 Folder+File 子依賴亦無 payload。descriptor 可讀不等於模型、貼圖、聲音或特效已可呈現。

### 8.3 Q119 的 context 有原資料依據，Q variant 仍分開

本次可以做下列來源關係：

| 表／成員 | 原資料 |
|---|---|
| QuestInfo | Quest 119：town 1、field 26、giver/finisher 10047。 |
| `_CaseList.xml` | Case 107：STAGE 26、MAPFLOW `CHART_scenario_chicken_01.xml`、CLUSTER `CLUST_scenario_chicken_01.xml`。 |
| MapFlow chart | Node 1：title `S_chicken04`、type 3、Map 635、percent 100。 |
| Cluster | Cluster 19：OBJECT ID 1086、PRE 1、COUNT 1。 |
| 原 `_MapList.xml` | Map 635：MAP `mushroom12D`、BOUND `mushroom12`、TRIGGER `scenario_chicken04.mef`。 |

因此可以把先前七個同 stem MapList 候選中的 Map635 放入有來源的 Quest119／Field26 context，交 Server 內容工具與既有主線資料核對。這仍沒有證明 `Q119/3` 在何時／哪個 node 開始；world Cluster 的 PRE1 保留為 world 資料，後續原件已證 Q model catalog 不使用 PRE。MapChart 的 x/y 是編輯圖表欄位，本包未把它們匯出成怪物出生或 portal 座標。原 TRIGGER 名稱也未因新 ZIP 出現便變成已取得 `.mef` parser／payload。

**當前結果：descriptor/action/data context 與 ID→basename／reader 拼接規則有正向補證；實際目錄／mount 選擇、資產 payload 與 runtime 驗收仍各自待閉合。** 新來源已納入工具、source manifest 和實際重驗，不以舊三載體缺口隱藏這項進展，也不以新增一份 descriptor 宣告所有 MEF 資源完成。
