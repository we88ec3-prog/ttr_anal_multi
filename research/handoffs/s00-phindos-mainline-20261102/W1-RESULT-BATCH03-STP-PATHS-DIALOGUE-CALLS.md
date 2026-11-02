# W1-RESULT BATCH03 — QuestTalk／SceneList 在 STP 內的精確位置與 118 筆可讀劇情對話呼叫

> 2026-11-02 / `extra/roy1` / **PARTIAL first-hand resource extraction**；延續 W1 BATCH01/02（不修改舊原稿）。只分析已有 `Event.stp`、`Table.stp` 與已核來源；不操作 Client／Server，不更動 RR、APPROVED 或其他 Task owner。此為資源腳本**字面呼叫**，不是 Client native event dispatch、Quest 已接取/已達成/已結算的證據。AI/MEF/連擊由 S00 另查。

## 1. 回答補檔問題：不是另一套 SceneList

`SceneList.xml` 共有兩個不同的虛擬路徑，**均在現有 STP**。`QuestTalk.xml` 亦在現有 `Table.stp`，不需重新傳同 SHA 的 pack。

| 已提供的實體封裝 | 遊戲邏輯路徑（folder+member） | STPI catalog index | 實體 member record ID | member 裡的資料 | 解碼狀態 |
|---|---|---:|---:|---|---|
| `/mnt/data/Table.stp` | `Table/QuestInfo.xml` | 976 | **977** | `EX 01 00`, size 204056（宣告還原 2503464） | 原始 EX 封裝，未還原 XML |
| `/mnt/data/Table.stp` | `Table/QuestTalk.xml` | 977 | **978** | `EX 01 00`, size 52404（宣告還原 342958） | 同上 |
| `/mnt/data/Table.stp` | `Table/SceneList.xml` | 983 | **984** | `EX 01 00`, size 3404（宣告還原 65494） | 同上 |
| `/mnt/data/Event.stp` | `Event/SceneList.xml` | 7378 | **7379** | `EX 01 00`, size 14000（宣告還原 158269） | 同上 |

**檔案身分**：`Table.stp` SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`；`Event.stp` SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。來源為已上傳實體檔的 `STPD`+`STPI`、各筆 32B metadata、1024B block 位址及 16B `EX` header。索引內只存 basename；`Table/...`、`Event/...` 為資源路徑命名，而非容器裡真的另有可直接檔案系統開啟的子目錄。**STPI catalog ID 和實體 record ID 差 1**；不能拿相鄰 row 解讀為 SceneList。

上一批 BATCH02 已收錄完整 member length/header/MD5 與讀法。本批無變更兩個封裝格式。對 `EX v1` 的壓縮／加密處理尚未從已驗證原始碼建立完整解碼器；直接嘗試 zlib/gzip/raw-deflate/bzip2/LZMA 並非已核准的解碼。**「過去有分析」不等於本批已得到明文 XML**：既有 pinned QuestInfo 快照的來源是不同 SHA 的 Table 載體；若 T01/S00 另有這四份 XML 真正明文或同版已驗解包器，可直接使用其可追溯來源，而非再次要求使用者提供原始 STP。

## 2. 本次新完成的分析：原始劇情 `.seq` 中 118 次對話呼叫

對 BATCH02 全部 35 份原生 `.seq` 按 **實體 record ID** 唯讀讀取，逐筆驗 metadata MD5、`-- Quest #... / Scene #... - Function ...` header、`Register(function)`；以 `EUC-KR` 成功解析 `OpenTalkScene(group,index)`、`DoProlog(n)`、相位及 `LoadMap`。**35/35 原始 MD5 與函式驗證通過；共找到 118 次 `OpenTalkScene` 字面呼叫**。下表 key 的順序是依腳本內出現次序（不是遊戲 runtime 時序；不同 Scene 的實際播放次序由另一路入口決定）。

| Quest ID | 原始 `.seq` Scene | 對話 group 第一參數 | 呼叫數 | 逐次 `group:index`（劇情腳本原始次序） | `DoProlog` |
|---:|---|---|---:|---|---|
| 15 | 1,2,3,4 | 3 | 9 | 3:22; 3:15; 3:16; 3:17; 3:25; 3:18; 3:24; 3:20; 3:21 | 1 |
| 117 | 1 | 1 | 14 | 1:1; 1:2; 1:3; 1:4; 1:5; 1:6; 1:7; 1:8; 1:9; 1:10; 1:11; 1:12; 1:13; 1:14 | — |
| 118 | 1 | 12 | 10 | 12:1; 12:2; 12:3; 12:4; 12:5; 12:6; 12:7; 12:8; 12:9; 12:19 | — |
| 119 | 1,2,3,4,5 | 12 | 9 | 12:10; 12:11; 12:12; 12:13; 12:14; 12:15; 12:16; 12:17; 12:18 | — |
| 120 | 1,2,3 | 13 | 5 | 13:1; 13:2; 13:3; 13:4; 13:5 | — |
| 121 | 1 | 14 | 6 | 14:1; 14:2; 14:3; 14:22; 14:23; 14:4 | — |
| 122 | 1,2,3,4,5 | 14 | 17 | 14:5; 14:6; 14:7; 14:8; 14:9; 14:10; 14:11; 14:12; 14:13; 14:14; 14:15; 14:16; 14:17; 14:18; 14:19; 14:20; 14:21 | — |
| 123 | 1 | 15 | 5 | 15:1; 15:2; 15:3; 15:4; 15:5 | — |
| 124 | 1,2,3,4,5,6,7 | 15 | 16 | 15:6; 15:7; 15:8; 15:9; 15:10; 15:11; 15:12; 15:13; 15:14; 15:15; 15:16; 15:17; 15:18; 15:19; 15:20; 15:21 | — |
| 131 | 1 | 16 | 1 | 16:1 | — |
| 132 | 1,2,3,4,5 | 16 | 18 | 16:2; 16:3; 16:4; 16:5; 16:6; 16:7; 16:8; 16:9; 16:10; 16:11; 16:12; 16:13; 16:14; 16:15; 16:16; 16:17; 16:18; 16:19 | 2 |
| 133 | 1 | 17 | 8 | 17:1; 17:2; 17:3; 17:4; 17:5; 17:6; 17:7; 17:8 | — |

### 2.1 主要正向資料流與四個容易誤用的點

- **Quest117** Scene1，檔案 `Event/Sequences/Phindous_LittleTrouble.seq`，STPD member 6816、MD5 `b15ddbfa5f24dd2ea5566aefa952cb64`：含 14 次 `OpenTalkScene(1,1)`～`(1,14)`。這是實際 script 中供 **對話查找**的二維鍵，不是 `Quest117` 已自動接取或 reward type 2 可解釋的證據。`LoadMap("town001D.fld")`、`CreateObject(...10002...)` 可與 QuestInfo giver/finisher NPC10002 做有界交叉，但 CreateObject 是演出而非 Town1 互動實體。
- **Quest118 與119 共用對話 group12**。118.Scene1 包含 `(12,1..9)` 後接 `(12,19)`，119.Scene2～5 才包含 `(12,10..18)`；**group/index 不能作簡單遞增的任務狀態機**，也不能憑 `group=12` 宣告是正式 Chapter12，因 SceneList／QuestTalk 的 EX 明文仍未知。
- **Quest121、122 共用 group14**。Quest121.Scene1 的次序是 `(14,1),(14,2),(14,3),(14,22),(14,23),(14,4)`，Quest122 的多個 scene 則有 `(14,5..21)`。這證明該對話索引並非簡單「任務 ID / 場景 ID / index」且有**非單調存取**；Server 不能按連續 index 假設劇情完成。
- **Quest131、132 共用 group16，132.Scene5** 在 `LoadMap("town002D.fld")` 的演出中依序呼叫 `(16,12)` 到 `(16,19)`，隨後呼叫 `DoProlog(2)`；Quest15.Scene3 `pindos_talkevent.seq` 另有 `DoProlog(1)`。這是**腳本層級**的尾端轉場及序章資源連結，不是 Quest132 獎勵已發放、Town2 已權威解鎖、持久化或合法 spawn。Quest133 是另一本 group17 的 `(17,1..8)`；不得把它算作 Town1 第十一筆 Quest。

原始 `.seq` 每段均有 `Phase1...Phase4`、`RevPhase...`、`Q.DeleteAllObject()`、`RestoreMap()` 的資源呼叫（純動畫生命周期），不能拿它們代替 Client/Server 的 Quest settlement transaction。`OpenTalkScene` 是特定腳本 API 呼叫，**不等同 QuestTalk.xml 中的 NPC 互動事件**。上述 group 值建議暫稱 `dialogue_group_id`，不能在未核對 Table／Event SceneList 前提升為 chapter。

## 3. 可核對的直接原始碼摘錄（不是反編譯）

```lua
-- Quest #117 / Scene #1 - Function Phindous_LittleTrouble
LoadMap("town001D.fld")
CreateObject(0, 10002, 734.00, 741.00, 0, 1, FALSE, 0, 0)
OpenTalkScene(1, 1)
-- ... through OpenTalkScene(1, 14), each call interleaved with animation/camera actions
```

```lua
-- Quest #121 / Scene #1 - Function Phindous_RazedSave_TalkEvent
-- talk calls in source order (indexes are deliberately nonmonotonic)
OpenTalkScene(14,1) ; OpenTalkScene(14,2) ; OpenTalkScene(14,3)
OpenTalkScene(14,22) ; OpenTalkScene(14,23) ; OpenTalkScene(14,4)
```

```lua
-- Quest #132 / Scene #5 - Function Phindous_pathofAlsmeer_Boss_After
LoadMap("town002D.fld")
OpenTalkScene(16,12)   -- ... later OpenTalkScene(16,19)
DoProlog(2)
Q.DeleteAllObject()
RestoreMap()
```

上面有壓縮呈現省略號／單行多呼叫的示意，**不構成可直接覆寫 Client 的原始 Lua 全文**。精確所有原始 call 列表和每個 `.seq` member SHA/MD5、offset 由同行 JSON 提供，查原封裝取得字面原文即可。

## 4. W1 可交付 S00 的新增 typed 素材；不可啟用範圍

| 項目 | 本批事實與證據級別 | 用於 Server 時可做什麼 | 尚不可做什麼 |
|---|---|---|---|
| `(QuestId, SceneId, FunctionName)` | resource-native 標頭 + MD5，BATCH02 | 建劇情映射候選、正常人工驗收腳本 | 不得因腳本存在宣稱 Source→Client scene handler 已閉合 |
| `(DialogueGroupId, DialogueIndex)` | **本批直接 from 35 .seq 的 118 次呼叫** | 以 exact pair 驗 Script 路由／在資源目錄查對話明文 | 不能代替 `QuestTalk` 與 SceneList 入口，不能把 `group` 猜成 Chapter ID |
| `DoProlog(1/2)` | Quest15.Scene3、Quest132.Scene5 字面調用 | 為進村及跨村劇情建立正常流程觀察點 | 不能把 Prolog 已播放等同主線 Settled 或 Town2 解鎖 |
| Quest Demand / Field / giver/finisher | BATCH01 pinned `RESOURCE-BASELINE` | 只讀前置與 NPC 候選，與 dialogue keys 交叉查資源 | Reward type2/3/4、6F snapshot/74 delta、合法交付封包仍缺 Client/native consumer |
| SceneList／QuestTalk 明文 | STPI metadata **已定位但是 EX 未解** | 待驗證的解包器/同版 plaintext 後可追原生索引與 UI 互動 | 目前不能以此補 UI acceptance、任務結算 opcode 或 Server 值 |

## 5. 現在到底需要補什麼檔案？

**不急著請使用者再上傳 STP；目前沒有缺少完整封裝。** 若現有專案或其他分析曾取得**同版明文**，只要提供其位置／解包工具而非新增另一套資料來源：

- `/mnt/data/Table.stp` 内 `QuestInfo.xml`（logical `Table/QuestInfo.xml`），record 977，及 `QuestTalk.xml` record978、`SceneList.xml` record984；
- `/mnt/data/Event.stp` 内 `SceneList.xml`（logical `Event/SceneList.xml`），record7379。

若沒有可驗證的解包版本，才需要上述 4 份 **解包後的原始 XML（保留 SHA／版本）**，優先 `Table/SceneList.xml`、`Event/SceneList.xml`、`Table/QuestTalk.xml`，最後 `Table/QuestInfo.xml` 用於交叉核對 pinned 基準。**這是解碼方法／明文之缺口，不是原始包缺檔。** 

### 分類交接

- **Client 待逆向**：EX v1 解包原生 routine／字串密鑰是否存在；`OpenTalkScene` 實際 consumer、SceneList／QuestTalk 映射、合法接取/達成/交付、reward type2/3/4、6F/74 本地處理／場景完成狀態。
- **Server 待開發**：任務前置權威、接取/結算原子交易、once-only reward/persist、Town1→Town2 open gating，由 S00 以 ADR 規劃，不把本批對話 group 直接當持久化值。
- **跨功能待整合**：W2 Field/Case 結果及 W3 Town1 NPC/Map182，S00 AI/MEF 與連擊以其成果引用；T01 限定主張驗證後才能升級品質。
- **待遊玩驗證**：只記錄**正向** Quest15 場景3／Quest117 NPC10002 對話串、Quest132 After/DoProlog2 的正常時序，不做重播／重登／負向／併發／故障／壓測。

## 6. 重現指令／品質界線

```bash
python -B W1-RESULT-BATCH03-VERIFY.py /path/Event.stp /path/W1-RESULT-BATCH02-EVENT-SCENE-MATRIX.json
```

先核完整 `Event.stp` SHA，再用 member record MD5 和原生 TTEX 標頭／Register/function 逐筆核 **35/35**，抽取 118 次 `OpenTalkScene`、`DoProlog` 及相位資料；這不是 BIN native FULL-PASS，因本輪主要第一手來源是 `.seq` 資源。完整 Event `.seq` 原稿不修改，正式 RR/APPROVED/Server 不動。之後由 T01 複驗、S00 決定是否導入 DRAFT 資源契約。
