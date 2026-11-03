# W3 批次02 — Field19 兩個 BND「版本 2」與 KR version0/version3 parser 的有限差異

> 研究狀態：`SOURCE_BACKED_PARTIAL / FORMAT_GATED / NO_RUNTIME`。基準 `017d85c88c2ca4651ed6e309a0c6173ac2cb362f`，工作分支 `extra/roy3`。此文**只**提供靜態 BND 格式、bounds 對接、資料驗收的可實作介面；不分析核心 AI/MEF、不做戰鬥連擊、不操作 Server/Client、不更新任務 owner、正式 RR／APPROVED。T01 獨立驗證與 S00 採用另行決定。

## 1. 版本和來源層級，不能互換

| Typed/domain | 輸入或保存值 | 資料等級／適用範圍 |
|---|---|---|
| KR 原始 BIN | `Tartaros.bin`、預期 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`、12,472,320 bytes | **來源清單**：`shared/targets.json`。此 repo 不含原 BIN，故本輪**沒有**重新核算 BIN SHA 或獨立完成指令驗證。 |
| Field19 (Quest15 相關) | `QuestInfo.field=19` | **R 資源欄位**；Field19 **不等於** MapList.ID19、Quest19、Town19 或 BND 格式版本。Quest15 是 Town5/giver10338，起點與完成由 W1/W2 繼續驗。 |
| Field19 場景 A | `MapList.ID=191`, `TRIGGER=S_pathofpindus01.mef`, `MAP=scenario_pathofpindus01D`, `BOUND=scenario_pathofpindus01` | **R 精確 MapList 行**，不代表 Case/CHART/Field 自動配對。 |
| Field19 場景 B | `MapList.ID=192`, `TRIGGER=S_pathofpindus02.mef`, `MAP=scenario_pathofpindus02D`, `BOUND=scenario_pathofpindus02` | **R 精確 MapList 行**，不同 selector/bounds，不能把第一張直接用於第二張。 |
| BND member A | `Map/BoundMap/scenario_pathofpindus01.bnd`（檔案 key 候選；STPD 內路徑預期 `BoundMap/scenario_pathofpindus01.bnd`） | **I from MAP/BOUND**：依既存 `4DF1A0` 以 `Map/BoundMap/<BOUND>.bnd` 形成檔名；本輪未有此 member 的完整來源 bytes/decoded SHA。 |
| BND member B | `Map/BoundMap/scenario_pathofpindus02.bnd`（STPD 同理） | **I from MAP/BOUND**；尚需用實際歸檔索引驗證存在、block ID、SHA。 |
| Field19 BND header | 工作卡指定兩 BND 的 `header version=2` | **工單已知／尚待本輪原檔複核**：本輪尚未取得兩份 decoded BND bytes，**不可**捏造各自格寬、世界寬、圖層數或安全起點，也不能憑這個值宣稱 Client loader 走 v2 專用路線。 |
| Town1 BND | `BoundMap/town001.bnd` 保存 decoded member SHA `30b383ac9eb2228601bd93fab21a79ed68c66d65751993fb0f32dcd294a061f6`、12,044 bytes、header `v0`、768×768 cells、world 1536×1536 | **R 來源舊檔的精確首64 bytes**（`town12-resource-bytes.json`）；不表示所有 768² cell 都可走，亦不代表出生點。 |

## 2. 以現存 KR bulk 原稿讀取真正的分派界線

所有下列為 **N(partial) 已存批次反編譯文字**，**不是**本次直接反組譯或全文 CFG FULL-PASS。基準皆指同一個 KR SHA。

| Native 位址 | 有限來源片段 | Git blob SHA | 可用判斷 |
|---|---|---|---|
| `0x830040` | `functions/0x830040.c` | `70a25b24145d02aff78a9cff5c4e78d3bf9f9569` | 先讀 0x34B header，檢查 offset+0x20 的 DWORD：**等於3** → `0x82F850`，**其他** → `0x82F660`。 |
| `0x82F660` | `functions/0x82f660.c` | `e64f47137dce52e535b7f6a88ceb984c71e50c9b` | `0x234` bytes header，逐層 `0x10` bytes descriptor stride、最多32層，發現非零 count 即配置、讀取/轉換/copy `count*4` bytes並建層。 |
| `0x82F850` | `functions/0x82f850.c` | `c071ebc3d9992f7c03f77a161d5ceb4adf1e351c` | `0x534` bytes header，逐層 `0x28` bytes descriptor stride、最多32層，相似的逐層處理／建層後處理 `82FA80`。 |
| `0x4DF1A0` | T09 既存 `20261025-145814-...-boundmap-collision-object-origin.md` | `cb8b772ccb49f6356f32d4b29d7169a0e8cc4f1e` | 組合 `Map/BoundMap/<name>.bnd` → `830040` → 建立 holder+0xA0 碰撞物件；空名或讀檔失敗時無可靠碰撞物件，不能「回全通」。 |

**直接與版本2相關的有限推論：**若 header+0x20 確為整數 `2`，`0x830040` 的**可見分支條件**會進 `82F660`（「非3」路徑），不會進 `82F850`（僅3）。這只說明 **route selection**，**不證** `82F660` 能把實際 Field19 version2 的所有欄位、壓縮塊和圖層安全解出，亦不證另一條第三方／Server v2 reader 已存在。版本2可能沿用0x234布局、另加欄位或根本需別種 branch；必須拿實際原檔選定區段驗算才能決定。

### Header 對照（從保存 pseudocode 和現用解析器）

| Layout | Header 起始與大小 | 32 條 descriptor 的步距 | 可見分派條件 | 不可推定 |
|---|---|---|---|---|
| 已驗 Server v0 靜態讀器 | header `0x234 = 0x34 + 32×0x10` | `0x10` | `governance/inspect_tutorial_bounds_resource.py` 明示僅 `version==0`，所以目前**拒絕2** | 不得把 `version==0` 的 assert 刪掉就稱支援2。 |
| KR native `82F660` | 讀 `0x234` | `0x10` | `header+0x20 != 3` | 並非已證「專屬 v0」；可能接收2但其資料正確性尚未驗。 |
| KR native `82F850` | 讀 `0x534 = 0x34 + 32×0x28` | `0x28` | `header+0x20 == 3` | 不得因2比較接近3而用3 layout，或拿0x28步距解析 version2。 |
| Field19 A/B | 任務卡稱兩 header 為2 | **U，需按各自 bytes 實測** | 按目前 KR dispatcher 候選走 `82F660` | 實際壓縮來源與層數、格尺寸、scale、兩層意義、3D/高度及與 Server 現用讀器的可比性均未驗。 |

現存 Server 候選 v0 reader 位於**僅讀**`governance/inspect_tutorial_bounds_resource.py`（Git blob `e39cb00a9db90fbbea00844449b4b4da56520fae`）：
- STPD carrier pin `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8`；原選 town000、scenario_town000、square001，**不含 Field19 兩 member**。
- 它讀 `struct.unpack_from('<IIIff', data, 0x20)` → version/gridW/gridH/worldX/worldY；assert version==0，W=H=768；描述符 `0x34 + i*16`：4個u32 `offset,compressed,expanded,count`；本地 zlib 解每個非空層、要求 `expanded=count*4` 及尾長一致；從兩層 DWORD cell `==0` 篩選 static clear。
- 這是一個**source-pinned narrow static parser**，不是 KR 原生整個 .bnd loader 或跨版本通用解析器。實際 v2 可能的通過或不通過，在本輪無版本2檔案 bytes 情況下**一律未知**。

## 3. 能交給 Server 的具體安全介面，不假造資料

資料結構可拆為以下 typed contract（**S 設計建議，非遊戲原生欄位格式**）：

```text
MapResourceCandidate {
  map_selector_id: 191 | 192 | 182;          // MapList domain
  map_member: string;  bound_member: string;  // asset lookup domain
  trigger_member: string;                      // not executable proof
  source_archive_sha256?: string;              // verified source pin before admission
  decoded_bnd_sha256?: string;                 // individually checked, never guessed
}
BoundsValidation {
  header_version: uint32;
  width_cells: uint32; height_cells: uint32;
  extent_x: float32; extent_y: float32;
  descriptor_stride: 0x10 | 0x28 | UNKNOWN;
  first_layer_count: uint32;
  second_layer_count: uint32;
  static_cell_decision: CLEAR | BLOCKED | UNKNOWN;
  parser_source_revision: string;
}
```

**先離線取得並 pin 的最小欄位與驗證順序（不操作 Server）：**

1. 對 `Map/BoundMap.stp` 的**相同 carrier**唯讀索引，只抽兩個名字 `scenario_pathofpindus01` / `02` 的 BND 至分開的新結果檔；記錄 carrier SHA、blockID、packed SHA、decoded SHA、bytes，嚴禁覆寫原始來源。
2. 各自在 offset `0x20` 讀 u32 version、`0x24/+0x28` grid、`0x2C/+0x30` float extents；確認 header length、檔案總長，無法滿足任何一項就回 `UNKNOWN` 而非 all-clear。
3. **只按真正 bytes**測試其 descriptor layout：每條可能 `0x10` 源（初段 0x34，至0x234）、整數記錄 count、offset/壓縮長度、展開長度；對比 `0x28` 路線只作鑑別，**不能讓不等於3的版本強制走 v3**。不要在 decoder 未通過時複用 Town1 或其他 field 的 layer。
4. 在無外部I/O的解析結果中核對 0x20個 descriptors，所有非空層的 count 與 grid 乘積、zlib consumption、無 unused/尾端遺留、解出每層的 SHA；都能解才按 **static layer0/1** 的 `both zero` 給候選 clear。越界／溢位／其他圖層、未知 bit 域均 `UNKNOWN`，不可降為 true。
5. `layer0/1` 的「both zero」是既存 T09 `82CDF0` 與 `8330E0/837BE0` 的有限 static collision 行為（T09 blob `7cbf24625b41691c9630fbc02ffb05781d4aba0c`），**不是**官方可行走全路徑、party spawn、敵怪碰撞、動態 barrier、持久化位置或因應任何 MEF 特效。
6. 只有 T01 核對兩筆檔案 bytes、Client 原生 decode 分支／尺寸／路徑正確後，S00 才能決策採 `v2 accepted as v0-layout after proof`、`v2 distinct decoder` 或 `not yet admitted`；不得靜默 `header.version=0`、忽略被擋圖層、借用另一個 BND 或固定人工 all-clear。

### 既有資料完整度

| 實作問題 | 目前可用 | 擋點 |
|---|---|---|
| Field19 是不是地圖 selector 19？ | **否**。Quest field 19 與 Map191/192 分開。 | 仍缺 W2 Case/CHART→地圖正規選擇。 |
| 兩張 map 的資源 lookup 字串？ | **可用**：Map191/192 的 MAP/BOUND/TRIGGER rows 與衍生 BND path。 | BND member index、SHA及 header bytes 尚未本輪重核。 |
| KR native v2 應走哪個 parser？ | **有界**：可見 `==3` 才走 `82F850`，version2 候選走 `82F660`。 | 缺 v2 實際 layout／條件與 decode 驗證。 |
| 是否現在可選 Field19 spawn？ | **不可**，官方／Server candidate 都沒有足夠資料。 | 缺兩個格圖、正常入場座標、角色半徑、離地碰撞與 reachability。 |
| 能否讓 Server 讀器支援 version2？ | **先要求雙檔逐一驗證**，不可只刪版號 assert。 | parser 的格式是否真兼容、source pin、正流程選點與官方 scene 時序。 |

## 4. 提交驗收及延後項

本批是針對工單「先 Town1 v0，再 Field19 v2」的**第二段格式差異**，不是研究完成或 runtime PASS。缺口優先序為：**P0** 兩個 Field19 BND 的實際來源與解出資料；**P0** v2 descriptor 分支/bytes 是否與 native `82F660` 對齊；**P0** 初始安全座標與路徑；**P1** 進入/返回、動態覆蓋；**P2** 其他 BND 版本。不納入核心 AI/MEF 及連擊分析。T01 接手獨立驗證，S00 決定 Server 採用；Client/Server 文件、二進位、帳號、測試程序均未修改／操作。

### 精確來源索引（Git blob SHA）

- 工卡 `W3-TOWN-RESOURCES-NPC.md`: `f3cfb04e3ab17da36a9878c96ef254626b2a11d3`; `W2-SCENARIO-RESULTS.md`: `3a7b1e6c2f53db6e3705387447908143deafb641`.
- `kr-temp-roy/T06/evidence/_MapList.xml`: `919cb8ba9afba11f7f042234d8796d3df34cd9a1`.
- `kr-temp-roy/T06/evidence/town12-resource-bytes.json`: `1f8bca927dda9d46871950b39eb7416a4b382cc4`.
- `governance/inspect_tutorial_bounds_resource.py`: `e39cb00a9db90fbbea00844449b4b4da56520fae`.
- `kr-temp-roy/20261025-145814-claude-web-roy-T09-boundmap-collision-object-origin.md`: `cb8b772ccb49f6356f32d4b29d7169a0e8cc4f1e`.
- `kr-temp-roy/20261025-150501-claude-web-roy-T09-bnd-parser-and-tile-grid.md`: `42e0f03d1fd25eb2f41ba839d40d972ab007b1eb`.
- `kr-temp-roy/20261025-231329-claude-web-roy-T09-tile-builder-8330E0-blocked-bit.md`: `7cbf24625b41691c9630fbc02ffb05781d4aba0c`.
- `kr-bulk-roy/<KR_SHA>/functions/{0x830040.c,0x82f660.c,0x82f850.c}`: see §2; all from saved unreviewed pseudocode.
- `shared/targets.json`: `88c3ca2e9dac95e78b66653365d7c1ac5b01a255`.
