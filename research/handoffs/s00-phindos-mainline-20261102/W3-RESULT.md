# W3-RESULT — 馮德斯 Town1 進村初始化／NPC 介面（批次 01）

- 執行分支：`extra/roy3`；來源釘版：`017d85c88c2ca4651ed6e309a0c6173ac2cb362f`（先 fast-forward 本分支至此版）。
- 工單：[`W3-TOWN-RESOURCES-NPC.md`](W3-TOWN-RESOURCES-NPC.md)；共用前提：[`README.md`](README.md)。
- 分層：**R**＝原資源已保存的精確欄位／bytes；**N(partial)**＝既存 KR 原生局部指令或處理鏈、未由本輪重算原 BIN；**I**＝分析推論；**S**＝建議 Server 相容設計、非官服實錄；**U**＝未知或無安全值。
- 僅引用和交叉核對 GitHub 已保存的精確原稿／索引，未執行、附加、修改 Client，未操作 Server、未進行動態測試；本批不重跑 AI／MEF 與連擊主線，不變動任務 owner、既有退回或正式 RR／APPROVED。
- KR 原始目標在 `shared/targets.json` 登記 `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`、12,472,320 bytes、`included:false`。本作業環境無原檔，**無法親自重算原 BIN 的 SHA**，不可將 Git 上來源宣稱等同本機原檔校驗 PASS。已保存的原研究聲稱使用該版 KR，仍待 T01 原始指令／CFG／來源配套獨立驗證。
- 非原生全文 FULL-PASS，非 Server admission，非遊戲可玩驗收。

## 1. Town1 typed ID、資源與 scene 的硬性區分

| Typed domain / 使用途徑 | 可用值 | 證據 | 限制 |
|---|---|---|---|
| Town業務 context | `TownId=1`、`TownType.TYPE=1`、名稱 `핀더스` | R：`_TownList.xml`、`town-switch-review.json` | `TYPE=1` 是資源 TownType，**不是** 005F／0069 packet subtype。|
| 靜態地圖 selector 候選 | `MapList.ID=182` | R：`town12-resource-bytes.json` `map_row` | TownId1→Map182 **正常 runtime 關聯仍未官方封包驗明**；不能用 Map ID1。|
| 地圖／trigger／bounds 資源名 | `MAP=town001D`, `TRIGGER=town001.mef`, `BOUND=town001` | R：同上 | trigger 檔名不等於已證執行時機／server side MEF。|
| FLD + MRE | `Town/town001D.fld` / `.mre`（`Map\\Map\\Town.stp`） | R：同上 | FLD 場景裝飾／劇情畫面不可直接當角色 spawn。|
| Collision | `BoundMap/town001.bnd`（`Map\\BoundMap.stp`） | R：同上 | 函式、碰撞語意及可達起點另查。|
| Scene/Controller 安裝 | **U：正常 Town Scene / RTTI / controller** | N(partial)：`shared/T07-TOWN-ENTRY-DEPENDENCY-HANDOFF.md`；`T06/PACKET-RESTORATION-CONTRACT.md` | 0069/7 既存有界證據對應 `CSquare`，005F/6 對應 `CDuelField`；舊 0099/type3 `MissionRoom` 是候選、不能選為正常 Town。|
| S2C0038/Town context | 既存 `4B1BF0→4B2094/4B2098`：type0 時 `payload+3` WORD 寫 `FAB1BC` 並觸發 Quest 重算 | N(partial)：`S00-20261101-QUEST-SNAPSHOT-AND-TOWN-CONTEXT.md` | `0038/Town1` **不會自身確證** map182 已載、合法 spawn 或 scene 已 ready。|
| S2C0012/map | `4B24F0` 重置／清控制，`payload+2` DWORD 傳 `4DF510` | N(partial)：`T06/PACKET-RESTORATION-CONTRACT.md` | same-map cache 分支可能跳過顯式重載；不能用重送0012取代 rebind。|
| S2C0014/ready | `4C5930` 轉發 active scene virtual+2C | N(partial)：`T07` 交接 | Scenario ready 有局部證據，**Town ready consumer 未驗**；不宣稱收到0014即可完成 Town ready。|

### 已保存資源精確 SHA-256（解碼 member，非 Git blob）

| 項目 | member SHA-256 | 原始 carrier SHA-256 |
|---|---|---|
| `Town/town001D.fld` | `92c9684cdbebb7f8bda29e8687ed96540b9ebc84abaa3861cfe2fd719f1bf63f` | `ccd66c13d6b0613372fe2d1f4c77f9ef906f12cb50b23ca791e1d429da55b0c8` |
| `Town/town001D.mre` | `4a0429a4a95e8261e529967e6b02eee465e6c7b912e14158b2b0eaaca951b4f8` | 同上 |
| `BoundMap/town001.bnd` | `30b383ac9eb2228601bd93fab21a79ed68c66d65751993fb0f32dcd294a061f6` | `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8` |
| `MiniMap/town001.mmt` | `4be78e8eb1ffd01b20b7ed10f6a0556922ebba85cf170b4b8b38da10e3f19b0d` | `16675734497f560c740d35d810b4926fd0892a4839634544860caf2dd65b422f` |

`town001.bnd` 保存的首64 bytes 包含簽名 `MapTool Reinforce 1.0 Yogsothoth`；檔頭 offset `+0x20` 的 little-endian DWORD = 0、`+0x24/+0x28` = 768/768、`+0x2C/+0x30` = 1536.0/1536.0。此為 R：**v0、grid768×768、world1536×1536** 的選段 header 解讀；不是全格可走、不是合法出生點。T09 歷史 `830040` 用 `hdr+0x20 == 3` 決定 `82F850` 路線，其餘走 `82F660`（尚未全審）：不能把 v3 路線誤套 v0。

## 2. Town1 NPC 與主線關聯：介面可用值

`Table/_TownList.xml` Town ID1 的原順序恰有九筆：`10001, 10002, 10003, 10008, 10013, 10014, 10047, 10048, 10015`（R；這是 Town NPC roster，**不是** NPC spawn actor 網路封包、座標或所有可互動角色清單）。

| 靜態 NPC ID | 已發現的主線交接／任務資源關聯 | 限定結果 |
|---|---|---|
| `10002` | Quest117 `giver=finisher=10002`; Quest121、122、131、132 亦指向10002 | R：`town-scene-quest-join.json`；還需完整 Quest 資源／狀態與能否互動驗收 |
| `10047` | Quest118、119 `giver=finisher=10047` | R；118與119的 `field=28/26` 是 quest Field domain，非 Town Map182 |
| `10008` | Quest120 `giver=finisher=10008` | R；存在 Scene120/1與120/3 的不同 script |
| `10048` | Quest124 `giver=finisher=10048` | R；`field=17` 是另一個域 |
| `10001,10003,10013,10014,10015` | 本批未建立 Quest117→132 中的直接 giver 證據 | U；不得把沒有本批關聯當成永不互動／無功能 |

Quest117 `SceneList(117,1)` 對到 `Phindous_LittleTrouble`；保存 script 字面量 `LoadMap("town001D.fld")` 與 `RestoreMap` 的證據：可支持城鎮故事資源**關聯**，不等於 Server 玩家在 town001D 的合法 spawn。Quest132/5 的腳本甚至會使用 `town002d`，可反證「Quest Town=1 則每個場景只載 town001D」。Quest15 的 `pindos_talkevent` 是 Town5/Field19 後進村橋接候選，不應把事件播放視為 Quest15 已交付／完成。

## 3. NPC 可見 ≠ 可互動 ≠ 任務可接續：分流契約

| 層 | Client / 資源線索 | 已證／設計／未知 |
|---|---|---|
| NPC 名單 | TownList ID1 的九 ID | **R**：只給 model/table ID 名單 |
| 世界 actor 呈現 | 既存 `4AE4D0` S2C07/class6 26-byte record、`4D2120` CNPC；`scale=1` 是合理中性 Server 候選 | **N(partial)/S**：欄位布局參照 square/教程，不保證 Town1 NPC model/PRE/owner/entity/pose 已全核；每一筆必須分配非玩家的唯一 entity ID |
| NPC 位置與可點 | Town1 FLD、NPC table、潛在 MEF/event、碰撞 | **U**：未取得靜態 NPC→世界 x/y、朝向、互動距離，不能複製 square511 的暫定點或場景演出座標 |
| 互動送出 | 本地 F event、`C2S001C`、`003C`、`003F`、`0036` 可能不同來源 | **U**：須分開核對 producer、場景 gate、欄位與 Server response；不能把見到 NPC 或收到任意一種指令自動當任務接取 |
| Quest-giver / finisher | Quest117 / 118 / 119 / 120 / 121 / 122 / 124 / 131 /132 的 giver-join | **R**：只是靜態 ID 配對，W1/T16 再驗合法接取／完成／獎勵／保存及下一入口 |
| 對話鎖定與接續 | NPC event category、對應 Server 回應／本地 completion | **U/S**：若只觸發 UI 而無已核實下游，應保留互動未啟用狀態；不得回覆「完成」或 fabricated ACK |

## 4. 實作排程矩陣：先交可接線的狀態，再填未證值

> 以下為 **S：Server 設計候選**，不是原服 wire capture。每個轉換只允許正流程驗收；不執行本輪測試。

| 階段 | Server 可準備內容／依賴 | 放行條件／不可偷渡 |
|---|---|---|
| A. 入村意圖 | 已完成 Quest15 的權威狀態、玩家／隊伍 destination 權限；town context `1` 與 Map selector `182` 分兩個 typed 欄位 | Quest15 劇情／Scene15/3 不等於權威完成；W1 查清門檻 |
| B. Loading UI | 可引用 S00 既有 S2C23(category/index)→S2C24 的 start/end 界線 | 未證 Town1 所用 category/index 和真實時序；若不能支持不要固定選圖／sleep／造 map-ready ACK |
| C. Scene 選擇 | **阻塞**：正常 Town native RTTI、scene entry、controller 專屬封包與 ack | 禁用舊 `0099/3 MissionRoom`、`0069/7 CSquare`、`005F/6 CDuelField` 代替 Town；0038 僅業務 context |
| D. Map/bounds | `0012` 的候選 map selector 182；繫結 `town001.bnd` version0，world1536/768 grid | Map重置可能清 actor/control；same-map 不保證重新載圖；source member 對實機 build 配對仍須核 |
| E. Player / NPC | 同連線自有角色識別與 ephemeral alias；建立 player metadata→actor(scale1)→必要 stats/parameters→controller rebind；九 NPC entity 候選及 Quest 起點 ID | 參照已有 tutorial 的局部 `07/08/0A/12` consumer；精確原版 Town 序列未知；NPC model/PRE/位置須另證，不發虛構 actor |
| F. Ready / loading 結束 | 0014 對 active scene virtual+2C 的局部證據；S2C24 UI end 候選 | 必須在場景、地圖、actor、controller 前置已具備且正常渲染的範圍才驗；不假造 Client ready acknowledgment |
| G. NPC click / 主線 | 以 NPC model ID、world entity ID、questID、scene key 分型；依 W1／T16 的權威任務狀態決定是否提供互動 | 缺 `001C/003C/003F/0036` 正式 producer/body 與 response 時先維持未打通，不用「點即完成」 |

### Spawn／返回：可用數值與缺口

**R**：BND header 支持格尺寸和世界大小；**N(partial)**：舊 T09 `82CDF0` 與 `8330E0/837BE0` 有兩層零值查詢與 tile 建構的限定路線，但版本0的完整 byte→grid 消費前置仍未在本批覆蓋。**U**：官方玩家出生位置、返回 checkpoint、npc 所在格、actor 半徑、可達路徑、層語意與動態碰撞；FLD 靜物、Portal effect、graph node x/y、結算演出鏡頭座標不許轉充玩家位置。**S**：要啟用臨時重建政策，需另存 `spawn_source=server_candidate`、對應資源 SHA、選點理由及正流程人工可達驗收；在無證據時不得填一個假「合法 spawn」。

### 已知不用於本批的後續接口

`003D` 的村／廣場旅行、Town 開放 `7E/80` 另記為後續接口；不因此宣稱每張村地圖、解鎖狀態及返回座標已可用。Field19 兩份 BND `header version2` 對現用 v0 的差異另交批次02，不先改版本或回退全通行。

## 5. 證據索引（引用檔的 Git blob SHA）

- `shared/targets.json` — `88c3ca2e9dac95e78b66653365d7c1ac5b01a255`（目標版本宣告；非本機原檔 SHA 計算）。
- `kr-temp-roy/T06/evidence/_TownList.xml` — `a check of exact blob required`（原 Town NPC roster；本批引用已 fetch 的來源）。
- `kr-temp-roy/T06/evidence/town12-resource-bytes.json` — `1f8bca927dda9d46871950b39eb7416a4b382cc4`。
- `kr-temp-roy/T06/evidence/town-scene-quest-join.json` — `9ed2b4e6188ca566cc2527659b913d3657bb1b71`。
- `kr-temp-roy/T06/evidence/town-story-resource-association-review.json` — `00fb3e688ac3f23c1a310d5c7bc21739e6aa8c67`。
- `kr-temp-roy/T06/evidence/town-switch-review.json` — `dc6a8e54be2f13a1859b57b6c3aaafd68a8cd091`。
- `kr-temp-roy/T06/PACKET-RESTORATION-CONTRACT.md` — `05f0b7fed0e8badbba25340134e04be9b8bcd328`。
- `shared/T07-TOWN-ENTRY-DEPENDENCY-HANDOFF.md` — `1ec858d1a3db2f7cb959a6637d6e3455e04cc794`。
- `kr-extra-roy/20261030-chatgpt-web-roy-E66-RR0002-square-handshake-43-68-6A-and-dual-state-RTTI.md` — `a802e8482af20145476015c17ee3dda029558f6c`。
- `governance/s00-iterations/S00-20261101-LOADING-DISPLAY-LIFECYCLE.md` — `072d9516b1bcfc03959465da8b3feb4cacd410e7`。
- `governance/s00-iterations/S00-20261101-QUEST-SNAPSHOT-AND-TOWN-CONTEXT.md` — `197b56ad3bf2142dcfc5ebf3d0c631c2f7f15723`。
- `governance/s00-iterations/S00-20261101-SQUARE-NPC-CANDIDATES.md` — `642e293f3b80f64adeccf7e86427ecaa4b2528cf`。
- `kr-temp-roy/20261025-150501-claude-web-roy-T09-bnd-parser-and-tile-grid.md` — `42e0f03d1fd25eb2f41ba839d40d972ab007b1eb`。
- `kr-temp-roy/20261025-231329-claude-web-roy-T09-tile-builder-8330E0-blocked-bit.md` — `7cbf24625b41691c9630fbc02ffb05781d4aba0c`。

## 6. T01/S00 所需的精確下一步與延後驗收卡

1. **P0 Town native scene**：按址覆核 4B9090、4B99C0、4BBB70、4B7D50、4B24F0、4C5930；查正常 Town 的 scene owner、活躍 controller／UI、對應 scene init command；不能只因 type 名稱選 0099。
2. **P0 NPC producer**：分開找 NPC click / event 的本地 F event、C2S001C／003C／003F／0036 producer、payload 與相應 S2C consumer；鎖定前置和可解除狀態；再對照 Quest117 與其後主線（不重做 W1）。
3. **P0 position**：查 Town1 預設出生／返回 checkpoint 與進村 actor 布置來源；碰撞使用的 version0 解析器、正常可行走區域、臨時 policy 的正流程可重現性。
4. **P1 Field19**：兩份 BND version2，先對照 header/分派與所需 decoder／grid 語意，再判能否安全接用；見後續批次。
5. **正常人工驗收（待 S00 安排，**未執行**）**：已合法通過15→載 Town1 預期畫面→玩家模型／UI／控制可用→可見9 NPC／正常移動→可對10002啟動 Quest117 正流程且可正常返回畫面；只有實測各條完成才標項目通過。
6. **延期測試（不執行）**：取消、離村再返、重登、失敗／負向／重播、跨帳號、併發、故障與壓測；不得將暫緩標作成功。

### 本批交付判定

可用於 Server 開發排 schema / typed-ID / resource pins / roster / 分段依賴，但**正常 Town scene 安裝、出生、NPC 互動 producer 與確切封包順序未閉合**；T01 仍需獨立驗證，S00 再決定採用。相容設計假設不得回填原生欄位。
