# W3-08 — Town1 完整碰撞資料與 town001.mef 相關實作交接

> 2026-11-02，`extra/roy3`。本輪依使用者新增 `BoundMap.stp` 與「town001.mef 可能需要實作，請整理實作所需內容」的要求交付。**已完成完整 Town1 BND 提取／靜態核對及 MEF 相關實作需求整理；不是完成原生 MEF parser、Server 開發或正常進村實機驗收。** 不修改 Client／Server／DB，不新增分支，不改 T16/T07/S00 owner 或 RR／FULL-PASS 狀態。

## 0. 結論與交付範圍

**目前能據以開發的是「Server 村落配置與事件協調」，不是一份已知格式的 `town001.mef`。** 原資源只證明 `_MapList.xml` 的 Map182 有 `TRIGGER="town001.mef"`，尚無實際 MEF 樣本、parser 或 Client 傳檔接口證據。Server 可以在明示重建政策下提供正常場景、角色、NPC、互動區域與任務接續，透過已證的 Client application 介面實現；不得虛構一個 `.mef` 格式或 opcode，假設 Client 會執行。

本輪新增原件證據解除了 W3-07 的 **「沒有完整 town001.bnd，無法檢查任一格」** 阻塞。靜態格資料、連通性與一個重建出生候選點均已可重現；**官方出生點、九 NPC 原位置／半徑、正常幾何與角色半徑／動態障礙的實機可用性，仍未確認**。不能把這兩種狀態混在一起。

交付檔：

- [evidence.json](W3-08-town001-implementation/evidence.json)：原件 SHA、BND descriptors／兩層 hash／值分布、三包檔名檢索範圍、連通區與候選點、Table 欄位、13 段 native 切片。
- [inspect_town001.py](W3-08-town001-implementation/inspect_town001.py)：標準庫唯讀復現工具；重用 SHA 釘版 W3-07 reader，可輸出反組譯；不執行原 Client、Lua 或 Server。
- [town001-design-draft.json](W3-08-town001-implementation/town001-design-draft.json)：**S：自訂 Server 配置草案，非原生 MEF schema**。`deployable=false`；未定欄位為 null，重建候選與生效值分開，避免範例被直接部署。

**分級**：R＝原件資料；N＝本輪原 BIN 有界指令；N-ref＝既有有界研究（本輪重跑 W3-07 的來源／切片 hash 核對，但不自封全文語意驗收）；A＝離線分析算法；S＝相容 Server 設計；U＝未知。下文封包皆為**包含 opcode 的 application body**，不冒稱官服錄包或 transport 完整 frame。

本輪遠端基準 `extra/roy3=1aeb8d2f684a09181cbc7af5062352c31cd2437a`；沿用本對話既有 `main=ac6aac673426459df2a778d20a80c623b8559a92` 開工檢查，不宣稱本輪重新同步 main，不進行 Merge。

## 1. 新增 BoundMap 原件：已解除哪一項阻塞？

### 1.1 原件與 member（R）

| 來源 | bytes | SHA256 |
|---|---:|---|
| BoundMap.stp | 20,772,373 | `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8` |
| BoundMap/town001.bnd | 12,044 | `30b383ac9eb2228601bd93fab21a79ed68c66d65751993fb0f32dcd294a061f6` |
| Tartaros.bin | 12,472,320 | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| Table.stp | 5,248,784 | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |
| Event.stp | 11,241,597 | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |

提取沿 STPD index／block table 與 XOR-FF，非在壓縮資料中搜尋任意近似字串。member 為 BND 本體，不再套用 EX；Table 的 EX decoding 則按既有 reader 個別處理。未將 STP、BND 或整層原始資料上傳 Git。

### 1.2 Header、層資料與完整解壓（R）

Header `+20 u32 version=0`、`+24/+28 u32 grid=768/768`、`+2C/+30 f32 world=1536/1536`。32 descriptors 位於 `+34`，stride16，四個 LE32 欄位為 `[offset, compressedBytes, expandedBytes, count]`；header 共 `0x234=564` bytes。

| layer | offset | compressed | expanded | count | DWORD 值分布 |
|---|---:|---:|---:|---:|---|
| 0 | 564 | 2,309 | 2,359,296 | 589,824 | 全部 0 |
| 1 | 2,873 | 9,171 | 2,359,296 | 589,824 | 0：63,091；1：526,733 |
| 2–31 | `FFFFFFFF` | 0 | 0 | 0 | 無資料；不是可尋址的全零層 |

層0 SHA：`96a12deebdc8a3421e923d2fc00a649326f0b5167b48ffd231941a415777308c`；層1 SHA：`c46905ffc0879326015c62f1bb7db8d666a4c8bbc235228c513b73bf4cd35965`。兩個 zlib stream 均 EOF 成立、無 unused/unconsumed bytes、展開大小及 count 相符；第二層尾端恰為檔案尾端。**不能只看層0全零就採 all-clear。**

**S：實作解碼器最小要求**：核對來源／member hash；只接受已支援的 version/layout；檢查 dimensions、有限且正的 world extent、descriptor 邊界、展開上限、count×4、stream EOF；空 descriptor 不 seek `FFFFFFFF`。本檔兩層連續，與 native sequential reader 相容。不得把這個結果擴張為其他版本、其他 BND 或所有32層語意已驗。

## 2. 原生 BND 消費鏈與座標換算（N）

本輪沿完整 BIN 核到下列有界鏈，而非只依 JSON header 猜零值可用：

```text
4DF1A0: Map/BoundMap/<name>.bnd
 → 830040: version==3 才走另一讀器，Town1 version0 → 82F660
 → 82F660: header 234h、32 descriptors、解壓 DWORD 層
 → 82FA80 → 8330E0 → 837BE0: 建立 tile/cache，非零 DWORD 轉占用 bit
 → 82FF10 → 82CBC0: 建查詢物件，綁定各層及 grid/world 比例
 → 82CDF0 → 832DA0: 查 layer0 和 layer1；兩者結果都零才回 true
```

| native 位址 | 本輪直接指令支持的主張 |
|---|---|
| `830095/83009E` | header version 比較3；非3呼叫 `82F660`。本輪工具仍只核定 Town1 v0，不用該分支替其他版本做保證。 |
| `82F6C0`、`82F6DD..82F722` | 讀 `0x234`；保存 grid/world，計算 `gridWidth/worldX`、`gridHeight/worldY`。 |
| `82F741..82F828` | 按 count 判非空，讀 compressed stream、解壓、複製 count×4，descriptor stride10h，32筆後重建 cache。 |
| `837C96..837CA3`、`837D08..837D2F` | 原格 index 依 row-major y×width+x；非零原 DWORD 才設對應 bit。 |
| `82FF9D..82FFDB` | 資源 cache `+1C+4*i` 依序綁查詢物件 `+24+4*i`；不要混用兩種物件同 offset。 |
| `82CC37..82CC5E` | 查詢物件 `+14/+18` 再保存 grid/world 比例。 |
| `82CE25..82CE3B` | x/y 乘上述比例，轉整數；`8FED25 cvttsd2si` 及其 fallback 為轉換鏈。 |
| `82CE40..82CE69` | 對查詢物件 `+28`、`+24` 各呼叫 `832DA0`，OR 結果為零才回1。 |

對有限、非負、界內 Town1 座標：`cx=floor(x*0.5)`、`cy=floor(y*0.5)`，raw index=`cy*768+cx`。一格對應2×2世界單位，不要把768當world邊長。native `82CE80` 另有界外 clamp；**S：Server 配置驗證應拒絕 NaN／Infinity／界外位置，不依 clamp 把錯誤位置偽裝成合法點。**

以上只支持**靜態兩層零值點判定的基礎**；不等於 native 完整尋路、角色圓盤／碰撞體掃掠、動態障礙、幾何高度、Portal 可達或所有狀態下的行走許可。`830230` 的後處理與 `82FA40` raw層釋放為既存載入鏈的一部分，本輪不擴張成所有 runtime override 都不存在。

## 3. 出生與 NPC 選點可用的分析結果（A／S，不冒稱原版佈置）

以「layer0==0 且 layer1==0」建立589,824格 mask，63,091格符合。採**四鄰接**分析得21個連通區；這是保守離線拓樸政策，不是還原 native pathfinder。依格數排序前三區：

| 本次分析 component ID | 格數 | 該區最深候選中心 x/y | 最近阻擋／外界 Chebyshev 格距 | 已核全零正方形 |
|---|---:|---|---:|---:|
| 4 | 30,282 | **(921,613)** | 19 | 37×37格 |
| 1 | 20,719 | (901,205) | 30 | 59×59格 |
| 6 | 11,777 | (755,571) | 18 | 35×35格 |

component 編號由本工具 row-major 首遇順序產生，**不是遊戲區域ID或RoomID**。主候選政策是「選格數最大區，再選距離最深點，同分取最小 y/x」，所以選 `(921,613)`，不是全圖距離最大點；最大區也**尚未證明就是正常村落街道**，仍需幾何對照。

候選 `(921,613)` 對應 cell `(460,306)`。其全零方塊為 cell x=442..478、y=288..324，對應 world 半開區間 `[884,958)×[576,650)`。以候選中心計，這個方塊內可提供37世界單位的軸向邊界距離；**這不是原生角色半徑**，也不是已批准的出生區域。實際 actor radius、動態物件與地圖視覺仍要確認。

兩個反例取樣（只是檢查前稿曾出現的數值，不提升來源）：

- `(900,900)` 兩層皆零、component4，但距離僅5格；舊合成數值仍不是官方出生點。
- Q15演出物件 `(734,744)` 兩層皆零，卻在 **component6**，距離僅1格；不在主候選 component4。不能因「演出使用這裡」或「格是零」就當作普通玩家出生點。

**S：選點驗收**：選定與普通幾何對齊的主區；保留角色半徑及設計餘裕；每個 NPC interaction 至少有一個玩家可達的 approach point，且符合 strict `distance²<radius²`。路徑應在膨脹障礙後的可走集合檢查，不只 endpoints。四鄰接不連通不代表官服永不可到達，可能有尚未知的門／傳送政策；**沒有來源就不要自造跨區連線**。

本輪沒有替九 NPC 填任意格點，也沒有把最大區候選當成實機已通過。原始位置可缺，但 S00 可選擇並標示重建 placement，無須等待官服資料庫；配置一旦採重建值，必須記錄來源、理由和正常遊玩驗收結果。

## 4. `town001.mef`：已知、未知與不應預設的事項

### 4.1 直接資源與已核入口

本輪原 Table 重讀：

```xml
<MAP ID="182" TRIGGER="town001.mef" MAP="town001D" BOUND="town001" />
```

`town001.mef` 是 **MapList.TRIGGER 的字串**。本輪檔名索引掃描 Table1026、Event7382、BoundMap1296個member，三包均無 `.mef` member；**只排除此三包的該副檔名索引，非全Client、改名、內嵌或官服Server檔案不存在的證明**。

S00 既有 `S00-20261101-MEF-RECEIVE-FEASIBILITY.md`（blob `21644921dd6b230f71d9c2faad559d4b0803d4dc`）已界定 MapList lookup 不等於 MEF 執行。本輪重新核 BIN：

```asm
4DF585 mov ecx,FB74C0
4DF58D call 4F7DF0          ; trigger string lookup
4DF592 test byte [FB75B0],1
4DF599 jne 4DF5B9           ; initialized branch
4DF5B9 lea eax,[ebp-10]     ; overwrites returned EAX
```

此**已初始化分支**沒有把 lookup 回傳字串送入 MEF parser。MAP/BOUND 各自有後續資源消費，不能反推 TRIGGER 必然也如此。helper、別名與所有模組未全窮盡；不得擴張成「Client 絕不可能有 MEF 功能」。

### 4.2 實作選擇（S）

| 路線 | 現在能做的事 | 必要界線 |
|---|---|---|
| **A：Server 村落配置＋事件協調（目前可開發）** | 定義正常場景、room、spawn、NPC/互動區域、任務入口及發布偏序；用既有 Client 訊息實現 | 是相容重建政策；配置名稱宜 `town001-definition-v1.json` 等，**不要聲稱它就是原版 MEF**。 |
| B：原始 MEF 的 Server importer／解譯器（有樣本後） | 解析原件到同一份內部 TownDefinition，再沿A發布狀態 | 尚缺樣本、magic/version、壓縮／編碼、record與typed-ID、座標／事件執行語意；不能先猜格式。 |
| C：Server傳MEF給Client執行 | 現在**沒有可實作契約** | 必須先有dispatch→長度／緩衝→解壓／parser→executor完整證據；不可發明opcode或把任意blob塞進既有封包。 |

`MapEffect .emf`、Lua演出、`005E` TriggerMsgList文字提示，均不能當作 MEF 替代格式。S00 的核心 AI／MEF 與連擊研究保持原範圍；W3只交**村落實作所需介面與配置缺口**，不另造戰鬥腳本引擎。

## 5. 村落配置實作時必須保留的內容

以下是 **S：內部 TownDefinition 設計需求，不是從不存在的 MEF 還原出來的欄位**。

| 模組 | 至少需要的資料／行為 | 已證來源與尚未決定項 |
|---|---|---|
| 身分／版本 | TownId、MapSelector、source_trigger_name、原件／資源SHA、definition版本 | R：Town1、Map182、town001D、town001；**Town與Map關聯採用政策仍須標明**，不靠同數字代換。 |
| 正常場景與實例 | scene方案、roomKey、instance/session、member/owner一致性 | N-ref：0099/3→CMissionRoom/kind1/UI4可消費；官方Town1配對未證，S00決策。 |
| 玩家出生／返回 | xy、朝向、採用來源、碰撞區、體積餘裕、返回policy | xy由0007；本輪提供靜態候選，active spawn仍null；不以演出xy、Bounds world中心或舊fixture替代。 |
| NPC配置 | resource model/PRE、唯一wire actorKey、xy、朝向、wire scale、生命週期 | 九NPC roster有R；座標／朝向／封包scale仍待政策；Table SCALE120不等於wire float120。 |
| 互動區域 | selector/kind、enabled、xy/radius、activation policy/flag、與NPC位置關聯 | N-ref：0027全量快照，18B/record；原九NPC的kind/radius/flags未拿到。 |
| NPC業務路由 | NPC服務／任務giver/finisher、候選與角色上下文、同一selector的處理 | class6 CNPC、checkpoint kind3、npctable TYPE是不同domain；不得所有NPC都套kind3。 |
| 任務與劇情 | Q15權威完成／key15、Town1上下文、Q117候選；獨立scene scheduler | Q15過場EndCutScene不是完成交易；使用T16/W1/S00既有結果，不自造原服ACK。 |
| 初始化協調 | destructive reset、room與owner/actor、binding、完整區域snapshot、ready/loading偏序 | N-ref：0012會清checkpoint與binding；current room為空會擋互動分支；14與Lua解鎖不是同一旗標。 |
| 來源與觀測 | 每個重建值的policy/approval、map generation、輸出app bytes、玩家畫面與事件結果 | 內部generation是Server資料，不新增Client未知欄位、packet或ready ACK。 |

### 5.1 Town1 九 NPC 的已知原資源值（R）

| model | PRE | FILE | Table SCALE | npctable TYPE | type2主線giver |
|---|---:|---|---:|---:|---|
|10001|1|01_Berta|120|0|—|
|10002|1|01_Elder|120|0|117/121/122/131/132|
|10003|1|01_Selien|120|0|—|
|10008|1|01_Hansen|120|0|120|
|10013|1|00_Ertale|120|1|—|
|10014|1|00_Skmaster|120|2|—|
|10047|1|01_Yuri01|100|0|118/119|
|10048|1|01_Yuri02|100|0|123/124|
|10015|1|00_Mixer|120|6|—|

「—」只表示這十筆主線沒有giver關聯，不代表無功能或可以忽略。`model` 不是 world entity key；NPC TYPE1/2/6不能直填checkpoint kind。任務型NPC的 `kind3/selector=modelId` 只列**有條件的Client路由候選**，未宣稱取自原Town1配置。

### 5.2 必須分離的 IDs 與 application 介面（N-ref）

| 介面 | 重要布局／消費效果 | 實作防錯 |
|---|---|---|
| C2S003D | 3B：u16 opcode＋u8 destination | UI目的地請求；不是載Map182或出生指令。 |
| S2C0099 | subtype3→正常MissionRoom/controller | 與0069/7廣場及Quest15 Lua controller分域。 |
| S2C0038 | app+2 subtype；type0/5讀WORD+3 Town；handler讀到+8 | Town context/preload不是0012；未核字段不得全部補0。 |
| S2C0012 | 最少6B；app+2 DWORD MapSelector | 清checkpoint及控制binding；後送07/0A/27必須考慮最後一次reset。 |
| S2C0008 | header4＋22*n；self owner record+14是room lookup key | ownerID、roomKey、actorKey不可交換；缺room可能發C8/C9且current room為NULL。 |
| S2C008E／008F | 建room cache／成員及self-bit2選current room | 008E本身不必然修正先前NULL pointer；需走已證writer。未知flags不猜。 |
| S2C0007 | header2＋26*n；record+0 u16 actorKey，**低BYTE同時class**；+4 model、+6/+10 xy、+14 scale、+18 owner | player class0、NPC class6；不是任意16-bit分配。已存在key會跳過新建，不可當重定位API。 |
| S2C000A | owner + signed-byte count＋4*n的兩WORD關聯 | 已存在owner/actor、自有身份匹配後才能綁；不以NPC model代填actorKey。 |
| S2C0027 | header2＋18*n；先清所有區域，再建本包全部 | 必須完整snapshot；區域不是NPC render actor。 |
| S2C0014 | MissionRoom ready→controller+4；非cutscene busy時清input bit0 | Lua EnableInput只清bit1；不能以收尾動畫代ready，loading end亦獨立。 |

精確0027 record順序：`u16 selector, i8 kind, u8 enabled, f32 x, f32 y, f32 radius, u8 activationPolicy, u8 flag`。可用kind需按consumer／業務分類確認；finite座標、正半徑、approved flags為Server配置政策。kind0還有Portal資源分支，不把它當通用NPC。

manual路線：activationPolicy==0、enabled、玩家確在 `distance²<radius²`、正確輸入／room／controller／UI gate成立才可能觸發。最近區域選擇與重複進出latch是Client原生行為；**S：Server仍須核角色與場景上下文，不信任Client聲稱已完成任務**。

## 6. 可採用的初始化與事件狀態機（S）

```text
Prepared（版本、碰撞、選點、配置與場景政策通過）
 → Entering（目的地／實例授權；選正常scene）
 → MapContext（Town context/preload 與 MapSelector 分開發布）
 → PostReset（最後一次0012及清場結束）
 → WorldObjects（room/membership、owner、player/NPC actors具備）
 → Bound（self current room有效、000A連到既存actor）
 → Interactive（發布全部0027；角色狀態／UI前置成立）
 → Ready（cutscene不忙、0014條件成立；loading end另處理）
 → 玩家正常走路／互動／Q117接取，各自記錄結果
```

這是實作相依偏序，不是還原官方唯一封包總順序。room cache先於self08是一路；後來8F的有效self分支建立current room是另一路。初始化不應靠固定sleep宣稱就緒，也不造Client未證的ACK。

事件處理分流：

1. **進入／返回村落**：選approved spawn與instance，不用Quest15 `RestoreMap` 代正常world資料。返回點是獨立Server政策，不能自稱已由BND得出。
2. **NPC互動**：建立視覺actor與區域後，保留001C事件kind/selector和003F/0036的不同producer。NPC10338或10002不是QuestID；0027區域觸發不代表接受／交付完成。
3. **接取／完成／下一任務**：合法狀態由Server權威判定並持久化，依已證Client介面更新；006F完整快照不能抹掉剛給的0074增量。Q117需key15及Town1等其他gate。
4. **劇情**：使用既有scene-key排程，播放與Quest交易分開；Q15 Scene3的town001D.map、Lua角色及鏡頭不登錄成正常NPC/出生配置。
5. **區域更新／再次換圖**：內部以map generation維持一致快照；若又送0012，須重建binding/checkpoint，不沿用過期「ready」。本輪只整理需求，不執行重入或負向測試。

## 7. 開發切片、決策清單與正流程驗收

| 開發切片 | 現在可提供 | 放行前仍需的決策／證據 |
|---|---|---|
| A. BND資源讀取／檢查 | 完整member、兩層、SHA、version0 layout及復現工具 | 將讀器接到Server的版本政策；不靠all-clear。 |
| B. TownDefinition | JSON草案、九NPC資源與typed domains | S00核准正常scene/Map182與Town1組合、採原件或重建來源。 |
| C. 放置規劃 | 連通區、清空餘裕、(921,613)候選 | 對齊正常幾何、選真正使用區、角色半徑、九NPC與approach路徑；原點缺失可用明示重建政策。 |
| D. 發布與綁定 | room/owner/actor/region/ready依賴 | 整合既有Server serializer及角色初始化；不得以本草案未知字段填0上線。 |
| E. NPC／Quest流程 | NPC10002→Q117等表、事件介面邊界 | 具體kind/selector/radius/flags及任務接受／完成／獎勵policy；沿S00既有規格。 |
| F. 原MEF importer | 預留adapter到TownDefinition | **非A–E的強制前置**；取得原樣本後才定格式。 |

正常驗收卡（本輪皆 **NOT_RUN**）：正常入村而非演出 → scene/map/context正確 → self room/member與owner/actor綁定一致 → approved spawn處可見可走 → 預期九NPC可見 → 每個已啟用區域在正確距離／輸入條件可互動 → NPC10002可進Q117正常流程 → UI與Server進度一致。每步分別記錄版本、typed IDs、app輸出與玩家可見結果；不以雜湊、compile或一張村落畫面冒充PASS。

取消、重登、重入、負向、競態、故障、安全與壓測依既有使用者政策延後，不在本輪執行；靜態格式／來源檢查不是遊戲行為測試。

## 8. 未知分層與本輪完成判定

**Client／原件尚待證**：原MEF樣本與格式、是否存在其他Client consumer／下載鏈；完整正常Town1幾何與部署資源對齊；尚未核定的NPC事件字段及service-specific route。不能把它們全說成官方Server內規。

**Server待設計／開發**：採用的normal-scene方案、spawn/return與NPC重建位置、互動區域配置、room/instance與Quest權威政策、發布偏序。這些可以由相容Server自行決策，不需要等待不存在的官服源碼，也不需預設實體MEF檔才能開發。

**待跨功能整合／遊玩驗證**：幾何、碰撞體、動態障礙、角色與房間初始化、NPC接取和過場收尾。W3正常進村整體仍不是已可玩。

**本輪完成的是「新增BoundMap完整靜態核對＋town001.mef相關實作交接」；不是MEF原格式復原或Server實作。** W3-07「缺完整BND」已解除；「缺原出生與NPC配置」改為有靜態依據可採重建policy，不繼續要求先取得MEF才能動工。草案保留 `deployable=false` 直到放置／字段／場景政策得到核准並驗收。

## 9. 復現與來源追溯

```powershell
python .\W3-08-town001-implementation\inspect_town001.py --sources <含四個原件的資料夾> --output <新的evidence.json> --check .\W3-08-town001-implementation\evidence.json
# 需要GNU objdump時另加：--assembly-dir <全新輸出目錄>
# 單獨使用下載包時，以 --prior-verifier 指向包內 W3-07-normal-town/verify.py
```

工具驗證舊reader SHA256 `977a58b576122d7027e810c3ab0c91b727a5cb5cfe3b80636fcb58094666dc47` 後才import；該reader只做離線STPD/EX與PE定位。輸出拒絕覆寫，原件唯讀。連通區/距離使用Python標準庫，不需Ghidra、遊戲啟動或網路。

W3-07完整報告 blob `1a408663f54ef20194ab1f94458fc3f53176718b`、manifest `e2f1ccd849b50d904eab81e93ff914982ebcaffa`、verify.py `2ccf5b18ce9a2ce91d82e1f39dfd6647c74a8559`；本輪重跑41 code/7 data/14 Table members的來源hash核對相符。**重跑hash不把原稿提升FULL-PASS**。

S00 MEF有限來源：報告 blob `21644921dd6b230f71d9c2faad559d4b0803d4dc`、byte-recheck blob `daf5c0b3ff3bad1daac32ccf586b9db4e83dacd6`。其中引用的 `anal/MAP-TRIGGER-CONSUMERS.md` 本分支精確路徑查詢404，本輪**沒有讀到該舊檔、不冒稱重跑42包稽核**。本輪只重驗明列BIN片段與三包現有原件索引。

作為定位而非第一手的bulk函式：82CDF0 blob `e5b0704f995690012b69b41b16987d56ee429277`；82CE80 `6ee729295e1e05fea8e7110aa59d80989efadae7`；82F660 `e64f47137dce52e535b7f6a88ceb984c71e50c9b`；82FA80 `09de0e19e3f73d630708341d02272978c9170fc1`；82FF10 `f5f2d960749d5acbef2e1d3973e15d09c41c31e9`；837BE0 `eeb447077aa933d239301db86338aff937150794`；4DF1A0 `eb25ba4eb0d2ba95dd8f98ef0e0d27400d084add`。肯定主張回到原BIN核對，切片raw/VA/hash列於evidence.json。
