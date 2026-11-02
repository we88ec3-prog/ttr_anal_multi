# W3 批次03 — Town1 進場 scene 分派與 NPC event producer 有界補核

> `extra/roy3`；基準 `017d85c88c2ca4651ed6e309a0c6173ac2cb362f`。所有 RVA 是對 Git 已存 KR SHA256=`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` 的 **bulk Ghidra pseudocode 局部重讀**，本輪**沒有原 BIN 可重算 SHA 或新增原 BIN 指令級驗證**。因此下列標記 `N(partial)`，不是原始遊戲時序或全文 FULL-PASS。資源精確欄位 `R`，推論 `I`，Server 設計 `S`，阻塞 `U`。不修改／執行 Client/Server、不碰原稿/owner/RR，不觸及 AI/MEF/連擊。

## A. 005F、0069 的 subtype 是哪種場景？（本批可直接縮小誤用）

| S2C consumer / subtype | 已存 Client native constructor/read | 判定 | source blob |
|---|---|---|---|
| `005F` `param+2=2` | `0x4B99C0 → 0x4C46F0` 設 `Scene::CScenarioField::vftable` | `N(partial)`：可稱 `CScenarioField` 候選場景；**非**原生正常 Town scene 的充分證據 | `0x4b99c0.c` `05ec7813a395478f499aa24fd69274e985cf195c`; `0x4c46f0.c` `0a1a489500fe3f5f6712b2e808ea0a889e4f7877` |
| `005F/4` | `0x4B99C0 → 0x4BC6A0` `Scene::CMissionField` | `N(partial)`; 不用來充當正常 Town | `0x4bc6a0.c` `cc4c8c05361a028ac8a15fa2f247c222f225f6ea` |
| `005F/6` | `0x4B99C0` 直接 `Scene::CDuelField::vftable` | `N(partial)`; 場景類型不能因字面數字6被當成 Town/Quest | 同上 `0x4b99c0.c` |
| `005F/9` | `0x4B99C0 → 0x4C54E0` `Scene::CRaidField` | `N(partial)`; 不等於 Town | `0x4c54e0.c` `5fbfd27547d427603e1d86ebecf22248478af6e2` |
| `0069/7` | `0x4B9090 → 0x4BBB70` `Scene::CSquare` | `N(partial)`; TownType.TYPE1≠0069/7，不以 Square 取代 Town | `0x4b9090.c` `39f515bf903cb78e0121409fb08f67f2b47076c0`; `0x4bbb70.c` `314100f47196ab73d016cdd66479e36ba30921f5` |
| `0069/0x15` | `0x4B9090` 直接 `Scene::CDuelSquare` | `N(partial)`；不是 Town | 同上 |
| `0069/0x17、0x18` | `0x4B9090` 可見重用 Square constructor，另設 `[manager+0x69A8]` subtype | `N(partial)`；差異與 UI/控制行為須另查 | 同上 |
| `0099/type3` 舊候選 | 原交接稱 `MissionRoom`，**本批未找到可綁正常 Town 的證據** | `U`：不得把封包數字/字串命中視為可發送的進村指令 | `shared/T07-TOWN-ENTRY-DEPENDENCY-HANDOFF.md` `1ec858d1a3db2f7cb959a6637d6e3455e04cc794` |

**可以確認的只是部分 subtype 所建立的 RTTI，不是 Town1 最終場景**：Town1 靜態 `_TownTypeList.xml` 中 `TYPE1` 不會自動選 005F 的 subtype1 或 0069 的 subtype1。現仍需對 S00 實際路線追出「哪個 opcode、何種 subtype、哪個 RTTI、何個 controller、哪個 UI owner，最終 Map182」的**正向完整關聯**。不能憑上述候選自動發出 005F/2、005F/4 或 0069/7 進村。

`0x4B7D50`（pseudocode Git blob `dfe66e14a39ffd4d68182449f604df5160a49772`）會先檢查/銷毀舊 scene，改寫 manager `+0x5EAC` 為新 scene，呼叫新 scene vtable `+0x10`；這是 `N(partial)` 的**scene install 前置**，不是城鎮 `ready`，不應無理由插入另一個場景或重複清空角色。

`0x4C46F0` 還把 `0x4C5930` 掛到 CScenarioField 的局部 callback slot；未在這份保存 bulk 查到可獨立逐函式界定的 `0x4C5930.c`，所以本批**不得**憑 callback 位址宣稱正常 Town 0014 ready 已閉合。

## B. 0012 Map reset 與同 Map 再綁、actor / controller 依賴

| 正流程相位 | 已見 native 行為 | 對 Town1 的限制 |
|---|---|---|
| `S2C0012` 接收 | `0x4B24F0`：初始化 checkpoint manager（若需要），呼叫 `0x5449A0`、`0x544F50`、自 `payload+2` 取 `u32 mapSelector`，交 `0x4DF510` | `N(partial)`：opcode 的 `payload+2` 是 Map selector domain；想送182仍先要有正常 Town scene／切換證據。Git blob `df3d56524b41a748041e0e3cc33e91a2f210ba6a`。 |
| `0x4DF510` | 若新 map ID 等於 context `+0x48`，可走**同 ID**快取/更新路線後 return；否則設定新 ID、資源名、呼叫 `4DF1A0` 載入 BND 等 | `N(partial)`：看見同值比較 `*(float *)(param+0x48)==param2` 只是 decompiler 型別的非精確表示，實際參數是一個 u32 selector；不能把它當 float 位置／座標。Git blob `3a0ce713aebc54dad99b07c04f7c3f988fbdf4e1`。 |
| NPC actor 接收 | `0x4AE4D0` 用 `(len-2)/0x1a` 逐 26-byte 記錄；class6 走 `0x4D2120` `CNPC`，之後各 actor 共有 transform/meta/registry 更新 | `N(partial)`：`class=6` 不是 Town ID、NPC model ID 或任務 giver；跨場景 rebind 不可只沿用舊 actor。Git blobs `ed4bfc2201dd07ea17fe8b28fa02a12426a7948c`、`a86c2b6c285b85ab164aee8dcd94c27a30ab8762`。 |
| `0014` / loading UI | 舊研究顯示 0014 派往 active scene virtual+0x2C、23/24 可能開始/停止 loading 畫面 | `N(partial)＋U`：Town scene consumer 和實際 loading/switch/rebind/ready 相位未閉合。只沿已知 `23/24` UX 行為，不發假的 ready ack、成功旗標或場景載入已完成。 |

**S 建議最小分段**：先建立 `TownContext{townId:1}` 與 `MapResource{selector:182, map:town001D, bound:town001}` 的分型欄位；待已驗證的 native scene 安裝後，按已證相依序提供 map reset、metadata、玩家 actor、stats/parameters、controller binding、NPC actors、ready/loading end；**目前對 Town1 不承諾這是一條已完成驗證的總序列**。當 0012 清掉控制與 registry 或落入相同 map id path 時，應重核角色/ NPC 實際存在、controller owner、UI interactive，而不是只比較最後一個 selector。沒有 scene/出生點也不填假位置。

## C. NPC category3：本地 UI 事件與線上 001C 不是同一支路

**同樣為 `N(partial)`，已存 bulk 路徑的關鍵條件：**

| 消費端/producer | 來源及可見欄位 | 不可偷換 |
|---|---|---|
| `0x544070` 本地 event dispatch | 讀取 NPC/互動物件 `+0xF4` 的 `int16 category`、`+0xF6` 的 `int16 subId`。category=3 的可見路徑會檢查 scene/mode 狀態，並在部分條件中建立 `FXUIEventI2` event `0xF43D6` 或 `FXUIEventI3` event `0xF43D9` | `0x544070.c` blob `1e0d589c12552ab2ea00d88d0db9269b17b3c1b2`。本地事件不等同自動傳 `001C`，更不等於完成 Quest117。 |
| `0x544020` C2S001C producer | 使用物件 `+0xF4/+0xF6` 兩個 `u16`；生成 buffer `[u16 0x001C][u16 cat][u16 subId]`，合計 6 bytes；若 `DAT_00FBA798 == 0` 則透過 network vtable `+0x10` 送出 | `0x544020.c` blob `f744c803243011f691dee7ff259d5b7e254aae26`。**這只驗了此 producer 的一段**, 在 `544070` 的非 category3 支路才出現此呼叫候選；不能將 **Town1 nine NPC model ID** 直接填入 `category/subId`。 |
| 舊教程 category3 必發001C | 被後續工作紀錄明確撤回：`0x544070 category3` 選本地 `F4388/F43D9`（其他本地子路徑），`544020` 是另一支路 | 修正來源 `governance/s00-iterations/S00-20261101-TUTORIAL-EXIT-GATES.md` blob `54f53b06be4c6c0e72573fefd8c2f338081d09d1`，仍不得跨成正常 Town1 所有 NPC 的互動語義。 |
| C2S `003C`、`003F`、`0036` | **U**：需要逐個確認 producer call site、body、gate、Server S2C response；不能因 opcode 同時出現在 script/quest/scene 就合併 | 不補出自創 payload、NPC ACK、完成旗標或點NPC後的強制解鎖；正向互動 trace 是後續必要條件。 |

**Town1 NPC 交付表（資源已證 `R`，互動時序未證 `U`）**

| NPC model ID | Town1 roster | QuestInfo 對應候選 | 互動時必備的四個分型值 |
|---|---|---|---|
| 10002 | R | Quest117/121/122/131/132 giver/finisher | `npcModelId=10002`; `worldEntityId=未知`; `eventCategory/subId=未知`; `quest/scene=以 W1/T16 驗證` |
| 10047 | R | Quest118/119 | 同上，model ID=10047 |
| 10008 | R | Quest120 | 同上，model ID=10008 |
| 10048 | R | Quest124 | 同上，model ID=10048 |
| 10001/10003/10013/10014/10015 | R | 本批未發現相同主線 giver join | 角色/互動/方向/位置未知，**不是不能互動的結論** |

不把 `CNPC` type6 當怪物 class，或把 QuestInfo 的 giver/finisher model ID 當成 wire 的 worldEntityId；缺 NPC 模型來源、event category、座標、路由時可先留 typed schema 與 UI 接線，但不得假造 actor / invoke / ack。任務完整性及獎勵由 W1/S00 決定。

## D. 容易誤判的完成信號及 S00 決策矩陣

| 問題 | 原生局部/資源已可回答 | 仍需 T01/S00 |
|---|---|---|
| `005F/2` 可直接當 Town1 嗎？ | 否，看到 `CScenarioField` constructor，不等於正常 Town | Town 真正 scene RTTI、opcode/subtype、controller/UI 及與 Map182 的有向連結 |
| `0069/7` 可當 Town1 嗎？ | 否，看到 `CSquare` | Town 類場景可能是否沿用 Square 類別仍須獨立證，**不要憑此發包** |
| `0012/182` 後必然可動？ | 否，已有 checkpoint/control reset 和 map 資源路徑 | actor re-emit／bind／ready/native input permit 的正常順序及同圖快取情況 |
| NPC `10002` 一定發 `001C` 嗎？ | 否，10002 是 roster/quest model ID；`001C` 是 category/subId 的另一條 producer | 該 NPC 真正 event descriptor、分類、能互動的 UI 與回覆消息 |
| `0038 Town1` 可當地圖1／預設spawn嗎？ | 否，0038 是 Town context 的不同 typed domain | 真正 player spawn、collision v0 座標、return checkpoint |
| `S2C24` 或 `0014` 單獨結束即代表 ready 嗎？ | 否，前者是 loading UI end，後者 active-scene callback | 顯示及 UI、actor、controller、movement 正流程端到端 |

**下一個最小驗證包（尚未做／不代表必須等完整研究）**：查固定的 Town scene 進場封包及建構類別，核 `0038+0012+actor+bind+14` 的局部偏序，定位 NPC10002 真實 event descriptor 與 UI 完成 callback；把來源地址、byte windows、code xref 與可見 wire body 在 T01 檢查。現可交 Server 的是 **typed resource IDs、Town1 9 NPC 模型清單、Quest giver joins、版本格式 guard、協定分支排除**。無法交可驗證合法的 spawn 座標、完整 Town scene、NPC 完成/獎勵、可持久化之狀態。

## E. 不執行項目及證據索引

本批未執行任何 Client／Server、遊戲 DLL／BIN、重登、負向、重播、併發、故障／壓測。未修改原始 Client、Server、舊 bulk、原研究稿與正式需求規格。原 BIN 不在 Git，SHA僅核對來源紀錄。T01 接手獨立驗證，S00 審核採納；不可對窄 callback/文件 hash 標 FULL-PASS。

- `kr-bulk-roy/<KR SHA>/functions/0x4b9090.c`: `39f515bf903cb78e0121409fb08f67f2b47076c0`。
- `kr-bulk-roy/<KR SHA>/functions/0x4b99c0.c`: `05ec7813a395478f499aa24fd69274e985cf195c`。
- `kr-bulk-roy/<KR SHA>/functions/0x4bbb70.c`: `314100f47196ab73d016cdd66479e36ba30921f5`。
- `kr-bulk-roy/<KR SHA>/functions/0x4c46f0.c`: `0a1a489500fe3f5f6712b2e808ea0a889e4f7877`。
- `kr-bulk-roy/<KR SHA>/functions/0x4b7d50.c`: `dfe66e14a39ffd4d68182449f604df5160a49772`。
- `kr-bulk-roy/<KR SHA>/functions/0x4b24f0.c`: `df3d56524b41a748041e0e3cc33e91a2f210ba6a`。
- `kr-bulk-roy/<KR SHA>/functions/0x4df510.c`: `3a0ce713aebc54dad99b07c04f7c3f988fbdf4e1`。
- `kr-bulk-roy/<KR SHA>/functions/0x4ae4d0.c`: `ed4bfc2201dd07ea17fe8b28fa02a12426a7948c`。
- `kr-bulk-roy/<KR SHA>/functions/0x4d2120.c`: `a86c2b6c285b85ab164aee8dcd94c27a30ab8762`。
- `kr-bulk-roy/<KR SHA>/functions/0x544070.c`: `1e0d589c12552ab2ea00d88d0db9269b17b3c1b2`。
- `kr-bulk-roy/<KR SHA>/functions/0x544020.c`: `f744c803243011f691dee7ff259d5b7e254aae26`。
- `kr-temp-roy/T06/evidence/_TownList.xml`: `d6c0d9621da3782d889cea870bd918eb57809c2a`。
- `kr-temp-roy/T06/evidence/town-scene-quest-join.json`: `9ed2b4e6188ca566cc2527659b913d3657bb1b71`。
- `governance/s00-iterations/S00-20261101-TUTORIAL-EXIT-GATES.md`: `54f53b06be4c6c0e72573fefd8c2f338081d09d1`。
