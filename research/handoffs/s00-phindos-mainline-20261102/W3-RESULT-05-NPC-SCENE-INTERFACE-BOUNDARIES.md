# W3 批次05 — Town1 NPC 主線互動 producer 分流、Quest15→進村演出與正常 Town scene 的剩餘邊界

> **跨 Task 有限引用，不重新認領 T16/T07。** 分支 `extra/roy3`，基準為 KR 原始 BIN 聲明 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。本輪**只讀 Git 已保存的 T16 BIN-first 原稿**及 T09/T07，沒有實際 BIN 可重新驗 hash/CFG、沒有執行／附加／改 Client，沒有操作 Server。原 T16 限定結論按原文件引用，**不取代 T01 審核**，也不改 task owner、正式 RR/APPROVED、AI/MEF/連段研究。

## 1. 修正對 NPC category3 與 C2S001C 的過度二分

第一批 W3 表格已區分 `0x544070` 本地 event 和 `0x544020` 直接 `001C` 建構路線。**最新引用 T16-126/T16-127 的更完整限定鏈揭示：**

1. NPC/event instance 建構器 `0x543700` 把 **kind/category** 存 `object+0xF4` (WORD)、**event selector ID** 存 `+0xF6` (WORD)，vtable+0x64 的 handler 是 `0x544070`。這是 Client **事件物件**分類，不等於 `S2C07` 的 class6 CNPC actor 分類，也不等於 TownId1。
2. `0x544070` **kind3** 在特定世界／角色／mode gate 成立時可建立 **local `F43D9`** event，帶 selector `object+F6`；它**不是直接呼叫 `0x544020`** 的簡化路線。某些條件下也會產生 `F43D6`，不應把 local event 當成唯一 Server request。
3. `F43D9` 再經 `0x5B7F80→0x5B8167→0x5B9340`、outer `type=105BD, action=0x6A7` 與 nested `type=105BF` 的條件 gate，才把 event selector 交 `0x5008B0` 選「giver相符／type2／候選第一筆」Quest。其後的**另一條** `0x5B9453..0x5B9485` 會從 nested event `+0x18/+0x1C` 建立 `C2S001C` 6-byte application。**因此「category3 不直接走544020」不等於「category3 在任何下游都絕不產生001C」。**
4. 原 Quest15 NPC10338 的限定示例：**只有** event fields 保留 `kind=3,id=10338`、相關 wrapper gate 成立，才可推得 `1C 00 03 00 62 28` (LE16)，**不是**官方抓包，也沒有把 QuestID15 當該訊息第二欄；最終 local enqueue 亦不等於 socket send 或 Server 受理。
5. **Town1** 的 `10002、10047、10008、10048` 是 Quest giver 的 **NPC model/resource ID**，目前沒有證明其具體 `event +F4/+F6` 與 Quest15 NPC10338 完全相同，更不能把 `1C 00 03 00 [modelId]` 作必然封包。要以 Town1 真正的 event actor/item 記錄、scene mode 和 quest candidate list 驗證。

**來源**：T16-126 blob `ae6e38af9c7078c23c21ca793e49bbcbc31b8ea6`；T16-127 blob `4e8e07719e882b4525481641dce929dd9786b87d`；這些原稿有直接 KR 位址、原始 bytes SHA、內部 gate 和反例。本 W3 只是精確引用，並未重新執行其全套原檔驗證。

## 2. C2S producer 與 S2C consumer：必須分開的實作介面

| 分支／方向 | 有界原生 Client producer/consumer | **可安全界定**的 app body（不是完整網路 frame） | 對 Town1 的限制 |
|---|---|---|---|
| `C2S001C`，本地 NPC/event | 直接 `0x544020` 可建立 `[u16 001C][u16 kind][u16 selector]`；另有 F43D9→`0x5B9340/0x5B9453` nested event 路徑 | **6B**；兩個 WORD 由 event/object 欄位而非 QuestID 自動產生 | 需證每名 Town1 NPC 的 **event kind+selector**，不能填 QuestID117 或直接用資源 ID 猜。 |
| `C2S003F`，scene controller | `0x561760`（存 primary/secondary）→`0x561DB0` normal deferred gate→`0x4A39A0` enqueue | **8B 候選**：`[u16 003F][u16 primary][u16 secondary][u16 1]` | Quest15 示例有 `(15,1)`，並不會把所有 Town1 NPC 點擊立即轉成 `003F(117,1)`；busy / scene mode 可改路由，sender gate 前 pending 可能先清掉。 |
| `C2S0036`，獨立任務 UI submit | `0x4B3510` 讀 input+2 WORD；另 `0x636E10` 是具 action/mode gate 的 producer | **4B**：`[u16 0036][u16 QuestID]`，條件式可組 `36 00 75 00` 代表 Q117；**純算術示例，非抓包／未證 Town1 會送** | mode2 不能套 mode1 的 F4402 分支；不直接等於 quest 完成。 |
| `S2C0040`，QuestInfo/UI | `0x502270` 對 QID+state 分派；record AcceptAction type2 等條件可交 scene controller/顯示 mode2 TalkBox | 局部已見 `[u16 0040][u16 QID][u32 state]` | **原服回覆時機／與001C、003F的交易配對未知**；不能自稱點 NPC 必回 40。 |
| `S2C0045`，CompleteAction | QuestRecord `+0x44` 類型若2→`0x561760(QID,param)`，若3→另一個本地 event | QID 在 `+2`（依原 T16） | `45` 不是 `46` 也不是單獨發獎證書。 |
| `S2C0046`，Quest cache/UI | `state0` 可條件式更新 prereq 集合、F438C(mode3) | `QID+2`、`substate+4`，原稿限定 | **不直接**呼叫 scene controller 去啟動 Scene3；不等同完成 Q15 並已存檔／領獎。 |
| `S2C0047`，scene pair | `0x503040` 讀 `+2,+4` 兩個 signed WORD → `0x561760(primary,secondary)`；busy/scene branch 還有 gate | 合成例 `47 00 0F 00 03 00` 表示 (15,3)，**非官服實錄** | 它只進 controller 有條件 stage，不是直接調 `0x565720`／必播 `pindos_talkevent`。 |
| `C2S003C` | **U：Town1 specific producer 未閉合** | **沒有可採用的 Town1 payload 值** | 不以 opcode 名稱或 Quest15 其他 sender 作暗示；沿 W1/W2 的正常 Quest/Scenario 分工驗證。 |

**程式責任分型（S 設計）**：`NpcClicked{wireEntity,kind,eventSelector}`、`QuestCandidateSelected{questId}`、`ScenePairReported{primary,secondary}`、`QuestUiSubmitted{questId}` 是四種不同的觀測／業務事件；各自必要前置、去向與 Server 回應待 S00 決策。第一個事件不是直接標記完成；第二個不保證第三個；後兩個也不是授予獎勵的原生事實。把場景、Quest、Town、Map 和 NPC ID 均用獨立型別，絕對不靠相同數字視為相同 identity。

## 3. Quest15 Scene3 只證進村**演出畫面**，不能給玩家實體 spawn

T16-134 來源 blob `991fa3fbbb89622e264eaceb138725d597629e28` 有原 Event.stp `pindos_talkevent` 限定來源；`Event/SceneList.xml` 有 `(Quest15,Scene3)` 到該 script 的資源 join。該腳本**確有** `LoadMap("town001D.map")`、`CreateObject(4,10047,734,744,...)`、多個 `OpenTalkScene`、`DoProlog(1)` 和 `RestoreMap()`。這個 734/744 是**腳本 cutscene object 演出擺位**，不應移成 Town1 世界 `NPC10047` 固定位置或玩家 spawn。

`S2C0047(15,3)` 只是**合成 input** 的 pair，經 `0x561760` 狀態/忙碌 gate 與 `0x565720` 的 Event key hit、Lua/資源成功，才可能播放演出。Quest15 已完成、原版 Server 實際先後、腳本 `RestoreMap` 對正常 Town scene 的回切及 controller/UI ready 都還沒有官服相容性證書。Town1 正常場景入口**仍未知**，不能用此腳本相機或 CreateObject 取代 Server `0012/map182`、player actor/rebind 和 NPC roster。

## 4. Town scene constructor 的最終限定清單與缺口

舊 T09 對 `0x4ADD50` 的**19個建構呼叫點／18個不同 RTTI Scene 類**有一份 source-pinned list（Git blob `39de1599e7752d05f30ab6eb89673c7dc7093e4d`）；例如 `CSquare`, `CExpedition`, `CScenarioField`, `CMissionRoom`, `CTutorial`，並沒有名為 `CTown` 的已列類。**這只能反證「當前列出的18個都是叫 CTown 的場景」這種杜撰**，不能從舊 xref census 證明遊戲完全不存在 Town 專屬場景或斷言正常 Town 一定沿用 MissionRoom/Square。

已界定的 controller kind：CMissionRoom 的 `kind1`、CMissionField `kind2`、CScenarioField `kind3`、CTutorial `kind4`；**控制器 kind1 ≠ TownType TYPE1 ≠ 0099/type3**。正常 Town scene 的 *實際 Server 進入命令*、*stage / controller kind*、*Map182 進入時序*、*ready/UI* 尚未閉合。額外必須確認 `0012` map reset 會清 managed actors 與 controller 3 slots，因而正流程必須有明確 player alias/actor/config/rebind 和九 NPC 的來源、位置及點擊事件。沒有已證合法出生／返回點，不補猜。

## 5. 依來源可給 S00 的限制性實作優先序

| Priority | 可以先寫為 typed schema／資料準備 | 必須保留 UNKNOWN，等待 T01/S00 採用 |
|---|---|---|
| P0 | Town1/type1、Map182、BoundMap/town001、NPC9 model IDs；Quest117 giver10002、Quest123/124 giver10048 | **正常 Town scene opcode/RTTI/controller、具體 actor/event record、spawn** |
| P0 | 各 C2S/S2C opcode 的 domain、已知 producer/consumer 分流；Quest15 script 演出座標與 spawn 分離 | 交易因果、接取／結算／獎勵／保存、Quest117 NPC 點擊完整事件鏈 |
| P0 | 參照 pinned Field19 v2 headers 與 `830040: ==3 vs !=3` 解析分派 | version2 32層資料、static reachable route、Map191/192 位置資料、v2 parser admission |
| P1 | S00 loading 23/24 與 actor reset→rebind 的**相依關係** | Town1 loading category/index、client 畫面／controller ready 時點及人工正常遊玩驗收 |

後續人工正常驗收（**此次不執行**）：合法 Quest15 進村→正確 village UI/background→可見玩家／九 NPC→玩家控制可移動→NPC10002 互動且 Server 有合適回覆→Quest117 正常接取、達成、交付與下一任務進入；各節獨立記錄。取消、重登、往返、負向、重播、併發、故障、壓測均只列待排，不宣稱 PASS。

## 引用來源（Git blobs）

- T16-126 `kr-temp-roy/20261030-114038-chatgpt-web-roy-T16-126-KR-Quest15-study2-NPC10338-actor-constructor-F43D9-type2-event-mode2-TalkBox.md` — `ae6e38af9c7078c23c21ca793e49bbcbc31b8ea6`.
- T16-127 `kr-temp-roy/20261030-141801-chatgpt-web-roy-T16-127-KR-Quest15-study3-NPC10338-001C-003F-0036-sender-queue-native.md` — `4e8e07719e882b4525481641dce929dd9786b87d`.
- T16-134 `kr-temp-roy/20261031-154318-chatgpt-web-roy-T16-134-KR-Quest15-C2S-S2C-scene-trigger-causality.md` — `991fa3fbbb89622e264eaceb138725d597629e28`.
- T09/T06/T07 scene constructor census `kr-temp-roy/20261026-105531-claude-web-roy-T09-T06-T07-scene-handler-table-owners.md` — `39de1599e7752d05f30ab6eb89673c7dc7093e4d`.
- T07 controller-mapping reference `kr/evidence/8762287177ecd19a4bf1b4a21c8e311a58733e962b1bacc28c6c1461e02b7bb3.txt` — `59254f10bcdc4acbcf51d68846e6e6b01454afb9`.
- S00 `RESOURCE-BASELINE.json` pinned at `27c1faf7d`, blob `5ac883881d3ab0c711ad7c0bdd84c4dd3c2e5cd6`; 本組 W3 批次01–04 詳各原稿 blob。
