# T16-113 — Quest 14／子研究②：教學啟動、伊希莉亞本地互動與 Scenario14 觸發，BIN-first 端到端核對

- 作者：`chatgpt-web roy`；Asia/Taipei `2026-10-30T01:46:17+08:00`；當次使用者明確要求完成 **Quest14-②** 並將所有尚未提交的 T16-106～113 原稿推到唯一 T16 分支。
- GitHub 開工先核對 `main=075411db2978b17c864ec4df6694126d306c8351`、原 T16 HEAD `0c8692fd18f510f7634890d626c5a93cd89467b2`，實際執行單向 `main → t16/roy/chatgpt-web` PR #21 merge `2edd396824036c1334017fea60665dd5f9e5911a`；驗證後才開始研究。後續其他研究 commit 不在本段第一手 BIN 發現中。
- 本地原始 KR `Tartaros.bin`：12,472,320 B，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；KR `Tartaros.exe`：2,594,816 B，SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；`Event.stp`：11,241,597 B，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。原始資料唯讀，不 patch、不執行、不上傳；BIN `.text` VA−raw = `0x400C00`。`Event.stp` XOR 0xFF 後 Lua chunk 直接讀取，後附 bytecode，不依賴 AI 補寫腳本。
- 原生源 `QuestInfo.xml`（repo `kr/evidence/5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60.txt`，已於 T16-112 從 repo 原文核對）：Quest14 靜態配置、Quest16 Demand14。T16-111 原生 0x40→0x4C Scenario14 狀態閉環需沿用精確邊界。

## 0. 執行結論與「完成」界線

**本段重大增量不只是再次找到 `RequestStartScenario(14)`：**

1. 確認 `Scene::CTutorial` 初始化入口 `0x4C4D3F → 0x4A8A60` 清掉 scenario 狀態，並以 `0x6F4A50` 安裝教學 Lua 名稱，再以 `0x6F4DD0` 配置名為 **`Tutorial_EntryPoint`** 的 Lua 腳本進入點。這是 native→Lua 接入口；呼叫 `0x6F4DD0` 的當下是否立即執行 Lua，不能僅憑函式名稱斷言，需區分安裝與排程。原件 Lua `Tutorial_EntryPoint` → `t_executeCoFunction(TutorialMain)`；`TutorialMain` 先 `t_executeCoFunction(Tutorial_Part1)`、等其 coroutine 停止，再執行 `Tutorial_Part2`。
2. `Tutorial_Part1` 具有明確玩家進度 gate：鍵盤、滑鼠、鏡頭、角色切換、伊希莉亞本地物件出現及位置判斷，和 NPC checkpoint。`Tutorial.InsertIsilia` 原生 literal `0xD6AD24` / Lua wrapper `0x4AC830` / slot `[FE186C]=0x4AA070`；在 `0x4AA111` 將 **local object key `0xF000`** 放入本地 object，`0x4AA21B→0x4DFF30` 插入本地容器。這不是 XML 的 Quest giver NPC `10027`。
3. `Tutorial.IsIsiliaFound` literal `0xD6AD34` / wrapper `0x4AC890` / slot `[FE1870]=0x4AA240`；`0x4AA27C` 設 `WORD 0xF000`，`0x4AA2B8` 用 `[FAB138]` 容器查找；sentinel／無物件跳 `0x4AA486` 返回0。命中後讀物件位置、觀察者位置，再以 3D 距離、視距與面向條件進行多重比較，`0x4AA46B` 返回1；否則 `0x4AA486` 返回0。這是先前缺失的**本地玩家接近／發現 gate**，而非從 Server 回來的 quest-completion bit。
4. `Tutorial_Part2` 於劇情 `(1000,8)` 結束之後才 `Tutorial.RequestStartScenario(14)`，其後輪詢 `Tutorial.IsScenarioEnded(14)`。`0x4AA4D0` C→S business 4-byte `40 00 0E 00`（有 sender gate），及 `Scene::CTutorial` B-table index0x4C handler `0x4C4F20` 把 scenario map[14] 設1，已在 T16-111 原件驗證。這個觸發 **Lua 演出／教學條件驅動**，而非由本研究原生證據證明按過 Quest14 accept 按鈕。
5. Lua 的 `SetCheckPointStatus(10016, CHECKPOINT_CATEGORY.NPC, ST_CLOSE)` 使用 local checkpoint ID `10016`，不等同 QuestInfo `giver=10027`，也不等同 `0xF000` actor。Quest14 的 `AcceptAction type=1` 是 XML 靜態宣告，迄今尚無原生執行期鏈把它配到上述事件。故 **Q14-② 的玩家教學觸發／Scenario 入口可依明確有界範圍結案；正式 QuestInfo ID14 的 UI 手動接取/自動接取，仍需在 Q14-③/④ 的 quest state producer/consumer 檢查，不得冒稱已證。**

### 0.1 操作鏈 — 有界 Player→Client 因果

```text
CTutorial 被選為當前 Scene（場景建立條件屬 T03/T07 未完全閉合）
 -> CTutorial init 0x4C4D3F
 -> 0x4A8A60 reset [FC0F84+4] scenario map + Lua binding/entry registration
 -> Lua Tutorial_EntryPoint: t_executeCoFunction(TutorialMain)
 -> TutorialMain: Part1 coroutine, wait until coroutine exits
 -> Part1: keyboard/mouse/camera/leader/checkpoint gating
      -> Tutorial.InsertIsilia(): native new object key 0xF000
      -> Tutorial.IsIsiliaFound(): native lookup [FAB138] key 0xF000
         + scene position/distance/visibility conditions -> bool
      -> move to NPC tutorial checkpoint (local NPC/scene ID is NOT QuestInfo giver)
 -> TutorialMain: Part2
      -> PlayAndWaitForScene(1000,8)
      -> RequestStartScenario(14)
      -> C2S business payload 40 00 0E 00 (conditional queue; T16-111)
      -> await IsScenarioEnded(14)
      -> S2C business payload 4C 00 0E 00 routed on Scene::CTutorial (conditional)
      -> same scenario state map key 14 set1 → Lua poll progresses
 ... separate, still-unproven: QuestInfo id14 accepted/completed and Quest16 UI unlock
```

### 0.2 玩家事件及 Client 動態 effect matrix

| 玩家情境 | 觸發/門檻 | C→S | S→C | Client effect | 界線 |
|---|---|---|---|---|---|
| 進入教學場景 | CTutorial 成為 current scene 後 init | 0x4A8A60 有 `0x000C` 共6-byte另一種初始化發送候選 | 不屬本段業務 | Lua entry 註冊、scenario map 清空 | 不證首次登入一定教學，T03/T07 整合 |
| 教學操作鍵盤/滑鼠/鏡頭/角色 | Part1 的 `GetTutorialState`、`GetControlStatus` 和 `yield` 回圈 | **此 Lua 本地步驟無 direct C2S 主張** | unknown | coroutine 前進/顯示 checkpoint | 不可推為從來不發其他事件 |
| 顯示伊希莉亞 | `Tutorial.InsertIsilia` | native 0x4AA070 函式內**未定位本題特定 outgoing packet** | 無專屬回覆證據 | new local object, key `0xF000`, insert container | 與 giver10027不同 namespace |
| 玩家接近/找到伊希莉亞 | `Tutorial.IsIsiliaFound` poll | 不需由這個函式發包 | 不需以 quest S2C 作 bool | local object+distance/visibility gate → return0/1 | 遊戲互動需真正物件與玩家位置 |
| Part1 結束進 Part2 | coroutine completion | 未證專屬封包 | 未證 | 執行 Part2 的劇情與 checkpoint | local control flow |
| 啟動 Scenario14 | `(1000,8)` 後 Lua call `RequestStartScenario(14)` | 4 bytes `40 00 0E 00` slot0、gate `[FBA798]==0` | 等待後續 key14 的 scene0x4C 處理 | coroutine 進入 yield loop | 不是 QuestInfo ID14 manual accept request |
| 收 scenario14 結束訊息 | current CTutorial + receive channel2 + handler0x4C | 無 | 解框 business `4C 00 0E 00` 4bytes足夠讀欄位（**並非實測原版 Server**） | `map[14]=1`、Lua 等待結束 | 不等於 QuestInfo ID14 completed |
| 顯示 QuestInfo 正式接取選項 | QuestInfo id14 `AcceptAction type1` | **unknown** | **unknown** | **unknown** | 此問題未從 script/checkpoint 證明必然存在／不存在 |

## 1. 來源、流程與 ID 命名空間的反證

| 值 | 原始資料的位置／用途 | 不能誤稱 |
|---|---|---|
| `14` | QuestInfo.xml `<Quest id=14>` | 不能只看值14就等同 Scenario map key |
| `14` | Event/TutorialMain.lua `RequestStartScenario(14)`、`IsScenarioEnded(14)` | **此為 ScenarioID**，native scene map已證 |
| `10027` | QuestInfo Quest14 giver/finisher；Quest16同 NPC | 非 Lua checkpoint 10016，不是 Isilia local key0xF000 |
| `10016` | Lua `SetCheckPointStatus(...CHECKPOINT_CATEGORY.NPC...)` | 不是 QuestInfo NPC ID／wire opcode |
| `0xF000` | native `InsertIsilia` 在新本地物件 +4 設 WORD，`IsIsiliaFound` 查此 key | 不是 QuestInfo quest ID 或 NPC10027 |
| `(1000,8)` | SceneList.xml `questIdx=1000,sceneIdx=8` 演出索引 | 不是 QuestInfo 14 或 sceneId=14 |
| `(1001,1)` | `tutorial_start` Event sequence | 與 `(1000,1)` 是兩個鍵 |
| `0x40` | Lua→Client network sender 首 WORD | 不是 `Quest14 accept` 已證 contract |
| `0x4C` | CTutorial scene專屬 receive handler index | 不是 `Quest14 complete` 已證 contract |

QuestInfo 的 `<AcceptAction type="1"/>`／`<CompleteAction type="1"/>` 在 loader `0x504ADF`/`0x504B52` 被**解析為靜態欄位**，不表示 Client 當時執行接受或完成。完整 QuestTalk.xml 未包含 id14同號 `Quest`，只能作該檔的負例；SceneList 完整1,687行也無 questIdx14，不能證明無其他劇情。這些和本段的 runtime lua/native gating 是不同命名空間。

## 2. native callback registration 與型別／錯誤分支

- **初始入口**：`0x4C4D3A mov esi,0xFC0F84` → `0x4C4D3F call 0x4A8A60`。`0x4A8A87 lea edi,[esi+4]` → `0x823850` 清空 scenario map（與 T16-111 的 IsScenarioEnded map 同容器）。`0x4A8B5D` 從同一 owner 取 Lua 物件，`0x4A8B64` 傳 `0xC0687C` literal；`0x4A8B6F push 0xC068A8`，由原件字面解碼為 `Tutorial_EntryPoint`，`0x4A8B74 call 0x6F4DD0`。**資料進入腳本環境已證，立即開始執行的時序未證**。
- **InsertIsilia 名稱/函式指標**：`.data` VA `0xD6AD24` 字面；`0x4AB678 push 0xD6AD24`，`0x4AB689 push 0x4AC830` 作 Lua callback；`0x4AB638 mov [0xFE186C],0x4AA070` 是真正 native body slot；`0x4AC866 load [FE1804]`, `0x4AC86C call [FE186C]`。所以不是依 Lua API 名稱臆造 native 對應。若 actor 容器中沒有原始定位項，`0x4AA0BD` 比對 sentinel 可以 exit，未必創建。
- **InsertIsilia object**：`0x4AA0D0 push 0x420`→allocator；`0x4AA0EE call 0x4C7070`；`0x4AA10A` 把 local word 設 `0xF000`、`0x4AA116 mov [esi+4],dx`；`0x4AA121` 設 `object+0x90=0x10`；多個 virtual calls 初始化動畫/動作；`0x4AA21B push 0xFAB130`、`0x4AA222 call 0x4DFF30`。不從此推出 NPC JSON/server spawn。
- **IsIsiliaFound 字面+wrapper**：`0x4AB718 push 0xD6AD34`；`0x4AB729 push 0x4AC890`；`0x4AB6D8 mov [0xFE1870],0x4AA240`；`0x4AC8C7 mov ecx,[FE1804]`、`0x4AC8CD call [FE1870]`，再將 native bool 轉 Lua number type=3。非單純 `GetTutorialState` 回傳。
- **IsIsiliaFound native**：`0x4AA27C mov word [sp+0xC],0xF000`，`0x4AA2B8 mov ecx,0xFAB138`，`0x4AA2BD call 0x82EF00` 查容器；miss sentinel `0x4AA2C6..0x4AA2CC` → `0x4AA486` return0。命中讀 `[node+0x10]` object，`0x4AA2DD..0x4AA2E2` virtual +0x4C 得位置；若 `[FB76E4]!=0`，還需 `0x838800` 位置/世界可用性 gate。`0x4AA374..0x4AA3B5` 取當前物件位置並計向量差；`0x4AA3D8` 求長度經 `0x8FF870`，`0x4AA3ED..0x4AA3F7` 與 `.rdata` `0xC55770` 閾值比較；`0x4AA41E..0x4AA469` 再依 `.rdata` `0xC557E8`、由視角/姿態相依欄位檢查，成功 `0x4AA46B mov eax,1`；失敗 `0x4AA486 xor eax,eax`。**實際閾值不猜**；下方附錄保留所有比較指令。
- **GetTutorialState**：`0x4AB498` literal `0xD6ACF0`，slot `[FE1860]=0x4A9FD0`；`0x4A9FD0` 讀 `[[0xFBA7A4]+0x134]` 返回，這是本地 tutorial control 狀態，不是從 QuestInfo 任務完成 map 直接讀。命中失敗/無 owner 的 null safety 並未由此函式保證。
- **NPC checkpoint ID**：Part2 Lua `SetCheckPointStatus(10016, CHECKPOINT_CATEGORY.NPC, ST_CLOSE)`；這只是 script 自行呼叫、不是「NPC10016==Quest giver10027」。可以作 Server 規格避免混淆的限定主張，不需要 Server 自行猜 NPC 等號。

## 3. 原始 Lua 5.1 bytecode 驗證（三階段、原件位置與 CFG）

- `Event.stp` decoder：每 byte XOR `0xFF`；chunk `TutorialBase` decoded raw STP offset `0xA27010`, 1416 bytes；`TutorialMain` decoded raw STP offset `0xA27810`, 5480 bytes；均為 Lua5.1 bytecode (`1b 4c 75 61 51` header)。自實檔 parser 完整 consumed size；原本檔案的 `Event/TutorialMain.lua` 名稱來自既有 STP 目錄索引，不由檔案偏移憑空命名。
- `Tutorial_EntryPoint` 原件 `proto8`（Lua line274–276）呼叫 `t_executeCoFunction(TutorialMain)`；`TutorialMain` 原件 `proto7`（line223–273）先執行 Part1 coroutine/`t_isCoroutineAlive` loop，再 Part2。這是唯一可追原始指令的順序，不代表系統沒有其他 trigger condition。
- `Tutorial_Part1` `proto4`（line48–124）順序先 `GetTutorialState` yield gate，然後使用鍵盤/滑鼠/鏡頭 checkpoint；`InsertIsilia` 後用 `IsIsiliaFound`、`CheckLeader`/`IsLeaderDialogOpened`，再處理 `TUTORIAL_GOTO_NPC`。不能把 Lua yield 理解成原版 Server 中止或完成任務。
- `Tutorial_Part2` `proto5`（line131–199）在 PC16–19 `RequestStartScenario(14)`、PC20–29 yield直到`IsScenarioEnded(14)` 結果不是 FALSE；其後持續後續 Scene、employment/UI、NPC checkpoint、角色可用性等待。Scenario trigger 不直接執行 Quest14 的 XML `CompleteAction`。

## 4. 三輪工作紀錄及反證

**第一輪**：原始 Lua 兩個 proto bytecode 自 `Event.stp` 完整解碼，重新確認 native CTutorial init 進 `Tutorial_EntryPoint` 的字面與 `0x4A8B74` call，避免拿 `(1000,1)` 與 `(1001,1)` 冒充任務 ID。既有 T16-111 只完成 Part2 scenario send/receive，此輪新補接場景初始化、Lua 排程與 Part1 gating 上游。

**第二輪**：二進位精確 `D6AD24`/`D6AD34` 名稱字串追到各自 Lua wrapper、native function-pointer slot `[FE186C]`/`[FE1870]`；證明 `InsertIsilia` 物件 `0xF000` 的真實 allocation/insert 路徑。是新增可驗證函式與玩家 gate，不靠來源檔函式名稱。

**第三輪**：深入 `0x4AA240` 函式的 map lookup、sentinel、位置與距離/視距判斷、true/false returns，並交叉原始 XML NPC10027、Lua checkpoint10016，精確建立三者 namespace 區別；同時把 Quest14 AcceptAction 仍無 runtime path 的限制歸回 ③/④ 待查、不把原版 Server 正式 Quest 狀態判定當作本段完成前提。

## 5. Quest14 五個子研究現在狀態與未解責任分類

| 子研究 | 狀態 | 精確界線 |
|---|---|---|
| ① 資源/NPC/前置 | 已完成（T16-112） | QuestInfo/QuestTalk/Tutorial Lua/SceneList loader與靜態關聯 |
| **② 玩家觸發／本地教學操作** | **本段已完成有界玩家教學觸發鏈** | CTutorial init→Tutorial_EntryPoint→Part1 本地 Isilia gate→Part2 Scenario14 request。**QuestInfo ID14 的獨立 accept UI／auto-accept policy 仍 unknown；不能報告已證明所有任務接取選項** |
| ③ Client→Server | 部分（T16-111） | Scenario14 cmd0x40已證；正式 Quest14 accept/turn-in business packet/record ID 未證 |
| ④ Server→Client / Quest state / UI | 部分（T16-110-REV/111） | Scenario14 cmd0x4C→map完成；Quest14 accepted/completed記錄/Quest UI尚未證 |
| ⑤ Quest14 完成→Quest16 | 部分 | XML Demand14→16已證，實際Client dynamic unlock通知與NPC badge未證 |

**Client 待逆向**（後續 T16-③/④）：QuestInfo ID14 `AcceptAction`、`CompleteAction` 消費者；有無自動任務接取或與 Scenario14 分別的 manual accept；Quest14 record state S2C 格式；NPC10027 的真實 TalkBox/UI 生效；Quest16 unlocked UI consumer，首次登入/選角怎麼選到 CTutorial。

**Server 待 S00 設計**：相容 Server 應提供完整 Scenario14 begin/ended 回應、quest14權威進度及 quest16前置解鎖策略（不冒稱官方）；持久化/重送/失敗/斷線政策另走 ADR。若是 Client 本地判斷 Isilia 是否被找到，就不要要求 Server 實作「距離演算法」；真正進村則與 T07/T14/T15 整合。

**跨功能待整合**：首次選角 → CTutorial scene routing（T03/T07）、原生 Scenario14 連線和關卡結果（T02/T14）、NPC實體/互動（T08）。**待遊玩驗證**：真實 KR Client 操作鍵盤/靠近 Isilia/Scenario14 與 UI，離線證據只證 Client 程式邏輯不證遊玩測試成功。

**權限與狀態**：使用者本次明確授權上傳全部 T16 尚未提交原稿，目標 branch `t16/roy/chatgpt-web`；不反向合併 main，不上傳原始 BIN/EXE/STP，不提交 `04`。Git commit 結果需於完成後另在聊天回報、不得先預填虛假 SHA。T01 FULL-PASS、S00正式規格及可玩驗證仍獨立。

## Appendix A — 第一手 KR BIN 機器碼窗口（指令僅以既知正常函式/CFG 判讀）

### CTutorial scene native initialization — VA `0x004C4D26..0x004C4D59`, raw `0xC4126..0xC4159`

- 此 byte slice SHA256 `628d60277503ec30e21580fac03c9f2b2f710d5b97cff7254710ab2c65037aeb`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004c4d26 <.data+0xc4126>:
  4c4d26:	61                   	popa
  4c4d27:	fb                   	sti
  4c4d28:	ff 68 70             	jmp    FWORD PTR [eax+0x70]
  4c4d2b:	db bc 00 e8 e7 d5 3c 	fstp   TBYTE PTR [eax+eax*1+0x3cd5e7e8]
  4c4d32:	00 83 c4 04 89 5c    	add    BYTE PTR [ebx+0x5c8904c4],al
  4c4d38:	24 20                	and    al,0x20
  4c4d3a:	be 84 0f fc 00       	mov    esi,0xfc0f84
  4c4d3f:	e8 1c 3d fe ff       	call   0x4a8a60
  4c4d44:	33 c0                	xor    eax,eax
  4c4d46:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4c4d4a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c4d51:	59                   	pop    ecx
  4c4d52:	5f                   	pop    edi
  4c4d53:	5e                   	pop    esi
  4c4d54:	5b                   	pop    ebx
  4c4d55:	8b e5                	mov    esp,ebp
  4c4d57:	5d                   	pop    ebp
  4c4d58:	c3                   	ret
```

### Tutorial framework init and Lua registration — VA `0x004A8A60..0x004A8B84`, raw `0xA7E60..0xA7F84`

- 此 byte slice SHA256 `ea35cf819dc7da541323b97418231ff0d3747220d00257badd0750bb0da747e5`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004a8a60 <.data+0xa7e60>:
  4a8a60:	55                   	push   ebp
  4a8a61:	8b ec                	mov    ebp,esp
  4a8a63:	6a ff                	push   0xffffffff
  4a8a65:	68 4c a4 93 00       	push   0x93a44c
  4a8a6a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a8a70:	50                   	push   eax
  4a8a71:	83 ec 08             	sub    esp,0x8
  4a8a74:	53                   	push   ebx
  4a8a75:	57                   	push   edi
  4a8a76:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a8a7b:	33 c5                	xor    eax,ebp
  4a8a7d:	50                   	push   eax
  4a8a7e:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a8a81:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a8a87:	8d 7e 04             	lea    edi,[esi+0x4]
  4a8a8a:	c7 05 a0 a7 fb 00 00 	mov    DWORD PTR ds:0xfba7a0,0x0
  4a8a91:	00 00 00 
  4a8a94:	e8 b7 ad 37 00       	call   0x823850
  4a8a99:	8d 7e 14             	lea    edi,[esi+0x14]
  4a8a9c:	e8 7f 89 3a 00       	call   0x851420
  4a8aa1:	bb 01 00 00 00       	mov    ebx,0x1
  4a8aa6:	83 cf ff             	or     edi,0xffffffff
  4a8aa9:	84 1d 54 73 fb 00    	test   BYTE PTR ds:0xfb7354,bl
  4a8aaf:	75 22                	jne    0x4a8ad3
  4a8ab1:	09 1d 54 73 fb 00    	or     DWORD PTR ds:0xfb7354,ebx
  4a8ab7:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4a8abe:	e8 0d a9 0a 00       	call   0x5533d0
  4a8ac3:	68 00 d1 bc 00       	push   0xbcd100
  4a8ac8:	e8 4d 98 3e 00       	call   0x89231a
  4a8acd:	83 c4 04             	add    esp,0x4
  4a8ad0:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4a8ad3:	89 1d b4 73 fb 00    	mov    DWORD PTR ds:0xfb73b4,ebx
  4a8ad9:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  4a8adf:	75 1e                	jne    0x4a8aff
  4a8ae1:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  4a8ae7:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4a8aea:	e8 91 e9 0d 00       	call   0x587480
  4a8aef:	68 c0 cc bc 00       	push   0xbcccc0
  4a8af4:	e8 21 98 3e 00       	call   0x89231a
  4a8af9:	83 c4 04             	add    esp,0x4
  4a8afc:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4a8aff:	b8 0f 00 00 00       	mov    eax,0xf
  4a8b04:	39 05 ec ad fa 00    	cmp    DWORD PTR ds:0xfaadec,eax
  4a8b0a:	74 07                	je     0x4a8b13
  4a8b0c:	a3 f0 ad fa 00       	mov    ds:0xfaadf0,eax
  4a8b11:	eb 05                	jmp    0x4a8b18
  4a8b13:	e8 88 1e 0e 00       	call   0x58a9a0
  4a8b18:	84 1d 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,bl
  4a8b1e:	75 13                	jne    0x4a8b33
  4a8b20:	09 1d 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,ebx
  4a8b26:	68 10 cf bc 00       	push   0xbccf10
  4a8b2b:	e8 ea 97 3e 00       	call   0x89231a
  4a8b30:	83 c4 04             	add    esp,0x4
  4a8b33:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a8b3a:	b8 0c 00 00 00       	mov    eax,0xc
  4a8b3f:	66 89 45 ec          	mov    WORD PTR [ebp-0x14],ax
  4a8b43:	89 5d ee             	mov    DWORD PTR [ebp-0x12],ebx
  4a8b46:	75 15                	jne    0x4a8b5d
  4a8b48:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a8b4e:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a8b50:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a8b53:	6a 06                	push   0x6
  4a8b55:	8d 45 ec             	lea    eax,[ebp-0x14]
  4a8b58:	50                   	push   eax
  4a8b59:	6a 00                	push   0x0
  4a8b5b:	ff d2                	call   edx
  4a8b5d:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4a8b5f:	68 7c 68 c0 00       	push   0xc0687c
  4a8b64:	e8 e7 be 24 00       	call   0x6f4a50
  4a8b69:	8b 06                	mov    eax,DWORD PTR [esi]
  4a8b6b:	6a 00                	push   0x0
  4a8b6d:	6a 00                	push   0x0
  4a8b6f:	68 a8 68 c0 00       	push   0xc068a8
  4a8b74:	e8 57 c2 24 00       	call   0x6f4dd0
  4a8b79:	83 c4 0c             	add    esp,0xc
  4a8b7c:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a8b7f:	64 89 0d 00 00   	mov    DWORD PTR fs:0x0,ecx
```

### Lua binding registration: GetTutorialState — VA `0x004AB440..0x004AB4D9`, raw `0xAA840..0xAA8D9`

- 此 byte slice SHA256 `dd83e7a3f711531b820aeb7c0f53e0ab6d3334f08b74a7541cb69072d0520d0f`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004ab440 <.data+0xaa840>:
  4ab440:	55                   	push   ebp
  4ab441:	8b ec                	mov    ebp,esp
  4ab443:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ab446:	53                   	push   ebx
  4ab447:	8b 1d 00 18 fe 00    	mov    ebx,DWORD PTR ds:0xfe1800
  4ab44d:	56                   	push   esi
  4ab44e:	8b 33                	mov    esi,DWORD PTR [ebx]
  4ab450:	57                   	push   edi
  4ab451:	8b 38                	mov    edi,DWORD PTR [eax]
  4ab453:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4ab458:	c7 05 60 18 fe 00 d0 	mov    DWORD PTR ds:0xfe1860,0x4a9fd0
  4ab45f:	9f 4a 00 
  4ab462:	e8 19 a2 24 00       	call   0x6f5680
  4ab467:	8b 03                	mov    eax,DWORD PTR [ebx]
  4ab469:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4ab46c:	83 e8 10             	sub    eax,0x10
  4ab46f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4ab474:	74 06                	je     0x4ab47c
  4ab476:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4ab47a:	74 14                	je     0x4ab490
  4ab47c:	57                   	push   edi
  4ab47d:	68 c4 26 c4 00       	push   0xc426c4
  4ab482:	e8 36 7c 3e 00       	call   0x8930bd
  4ab487:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4ab489:	83 c4 08             	add    esp,0x8
  4ab48c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4ab490:	8b 3d 00 18 fe 00    	mov    edi,DWORD PTR ds:0xfe1800
  4ab496:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab498:	68 f0 ac d6 00       	push   0xd6acf0
  4ab49d:	e8 6e a0 24 00       	call   0x6f5510
  4ab4a2:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab4a4:	83 c4 04             	add    esp,0x4
  4ab4a7:	6a 00                	push   0x0
  4ab4a9:	68 00 c7 4a 00       	push   0x4ac700
  4ab4ae:	e8 fd a0 24 00       	call   0x6f55b0
  4ab4b3:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4ab4b5:	51                   	push   ecx
  4ab4b6:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4ab4bb:	e8 30 a3 24 00       	call   0x6f57f0
  4ab4c0:	8b 15 00 18 fe 00    	mov    edx,DWORD PTR ds:0xfe1800
  4ab4c6:	8b 02                	mov    eax,DWORD PTR [edx]
  4ab4c8:	83 c4 0c             	add    esp,0xc
  4ab4cb:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4ab4cf:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ab4d2:	5f                   	pop    edi
  4ab4d3:	5e                   	pop    esi
  4ab4d4:	5b                   	pop    ebx
  4ab4d5:	5d                   	pop    ebp
  4ab4d6:	c2 04 00             	ret    0x4
```

### Lua binding registration: InsertIsilia — VA `0x004AB620..0x004AB6B9`, raw `0xAAA20..0xAAAB9`

- 此 byte slice SHA256 `74c78c6ecee9bf679ad4b79c5cd23c4cc5f9acb9ae18d18a199fb764e5fb935b`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004ab620 <.data+0xaaa20>:
  4ab620:	55                   	push   ebp
  4ab621:	8b ec                	mov    ebp,esp
  4ab623:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ab626:	53                   	push   ebx
  4ab627:	8b 1d 00 18 fe 00    	mov    ebx,DWORD PTR ds:0xfe1800
  4ab62d:	56                   	push   esi
  4ab62e:	8b 33                	mov    esi,DWORD PTR [ebx]
  4ab630:	57                   	push   edi
  4ab631:	8b 38                	mov    edi,DWORD PTR [eax]
  4ab633:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4ab638:	c7 05 6c 18 fe 00 70 	mov    DWORD PTR ds:0xfe186c,0x4aa070
  4ab63f:	a0 4a 00 
  4ab642:	e8 39 a0 24 00       	call   0x6f5680
  4ab647:	8b 03                	mov    eax,DWORD PTR [ebx]
  4ab649:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4ab64c:	83 e8 10             	sub    eax,0x10
  4ab64f:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4ab654:	74 06                	je     0x4ab65c
  4ab656:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4ab65a:	74 14                	je     0x4ab670
  4ab65c:	57                   	push   edi
  4ab65d:	68 c4 26 c4 00       	push   0xc426c4
  4ab662:	e8 56 7a 3e 00       	call   0x8930bd
  4ab667:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4ab669:	83 c4 08             	add    esp,0x8
  4ab66c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4ab670:	8b 3d 00 18 fe 00    	mov    edi,DWORD PTR ds:0xfe1800
  4ab676:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab678:	68 24 ad d6 00       	push   0xd6ad24
  4ab67d:	e8 8e 9e 24 00       	call   0x6f5510
  4ab682:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab684:	83 c4 04             	add    esp,0x4
  4ab687:	6a 00                	push   0x0
  4ab689:	68 30 c8 4a 00       	push   0x4ac830
  4ab68e:	e8 1d 9f 24 00       	call   0x6f55b0
  4ab693:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4ab695:	51                   	push   ecx
  4ab696:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4ab69b:	e8 50 a1 24 00       	call   0x6f57f0
  4ab6a0:	8b 15 00 18 fe 00    	mov    edx,DWORD PTR ds:0xfe1800
  4ab6a6:	8b 02                	mov    eax,DWORD PTR [edx]
  4ab6a8:	83 c4 0c             	add    esp,0xc
  4ab6ab:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4ab6af:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ab6b2:	5f                   	pop    edi
  4ab6b3:	5e                   	pop    esi
  4ab6b4:	5b                   	pop    ebx
  4ab6b5:	5d                   	pop    ebp
  4ab6b6:	c2 04 00             	ret    0x4
```

### Lua binding registration: IsIsiliaFound — VA `0x004AB6C0..0x004AB759`, raw `0xAAAC0..0xAAB59`

- 此 byte slice SHA256 `b58b3553163d32002677e0c62c7f87e52f9951c9c80b4b038631ecba2f8ca90d`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004ab6c0 <.data+0xaaac0>:
  4ab6c0:	55                   	push   ebp
  4ab6c1:	8b ec                	mov    ebp,esp
  4ab6c3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ab6c6:	53                   	push   ebx
  4ab6c7:	8b 1d 00 18 fe 00    	mov    ebx,DWORD PTR ds:0xfe1800
  4ab6cd:	56                   	push   esi
  4ab6ce:	8b 33                	mov    esi,DWORD PTR [ebx]
  4ab6d0:	57                   	push   edi
  4ab6d1:	8b 38                	mov    edi,DWORD PTR [eax]
  4ab6d3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4ab6d8:	c7 05 70 18 fe 00 40 	mov    DWORD PTR ds:0xfe1870,0x4aa240
  4ab6df:	a2 4a 00 
  4ab6e2:	e8 99 9f 24 00       	call   0x6f5680
  4ab6e7:	8b 03                	mov    eax,DWORD PTR [ebx]
  4ab6e9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4ab6ec:	83 e8 10             	sub    eax,0x10
  4ab6ef:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4ab6f4:	74 06                	je     0x4ab6fc
  4ab6f6:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4ab6fa:	74 14                	je     0x4ab710
  4ab6fc:	57                   	push   edi
  4ab6fd:	68 c4 26 c4 00       	push   0xc426c4
  4ab702:	e8 b6 79 3e 00       	call   0x8930bd
  4ab707:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4ab709:	83 c4 08             	add    esp,0x8
  4ab70c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4ab710:	8b 3d 00 18 fe 00    	mov    edi,DWORD PTR ds:0xfe1800
  4ab716:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab718:	68 34 ad d6 00       	push   0xd6ad34
  4ab71d:	e8 ee 9d 24 00       	call   0x6f5510
  4ab722:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab724:	83 c4 04             	add    esp,0x4
  4ab727:	6a 00                	push   0x0
  4ab729:	68 90 c8 4a 00       	push   0x4ac890
  4ab72e:	e8 7d 9e 24 00       	call   0x6f55b0
  4ab733:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4ab735:	51                   	push   ecx
  4ab736:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4ab73b:	e8 b0 a0 24 00       	call   0x6f57f0
  4ab740:	8b 15 00 18 fe 00    	mov    edx,DWORD PTR ds:0xfe1800
  4ab746:	8b 02                	mov    eax,DWORD PTR [edx]
  4ab748:	83 c4 0c             	add    esp,0xc
  4ab74b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4ab74f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ab752:	5f                   	pop    edi
  4ab753:	5e                   	pop    esi
  4ab754:	5b                   	pop    ebx
  4ab755:	5d                   	pop    ebp
  4ab756:	c2 04 00             	ret    0x4
```

### Lua binding registration: checkpoint API — VA `0x004AA7C0..0x004AA859`, raw `0xA9BC0..0xA9C59`

- 此 byte slice SHA256 `fcb325fc24c55e3fe0ec015f125d96d7ba71df1f42c3d9f762285d5bc9cd2c46`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004aa7c0 <.data+0xa9bc0>:
  4aa7c0:	55                   	push   ebp
  4aa7c1:	8b ec                	mov    ebp,esp
  4aa7c3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4aa7c6:	53                   	push   ebx
  4aa7c7:	8b 1d 00 18 fe 00    	mov    ebx,DWORD PTR ds:0xfe1800
  4aa7cd:	56                   	push   esi
  4aa7ce:	8b 33                	mov    esi,DWORD PTR [ebx]
  4aa7d0:	57                   	push   edi
  4aa7d1:	8b 38                	mov    edi,DWORD PTR [eax]
  4aa7d3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4aa7d8:	c7 05 10 18 fe 00 30 	mov    DWORD PTR ds:0xfe1810,0x4a9430
  4aa7df:	94 4a 00 
  4aa7e2:	e8 99 ae 24 00       	call   0x6f5680
  4aa7e7:	8b 03                	mov    eax,DWORD PTR [ebx]
  4aa7e9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4aa7ec:	83 e8 10             	sub    eax,0x10
  4aa7ef:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4aa7f4:	74 06                	je     0x4aa7fc
  4aa7f6:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4aa7fa:	74 14                	je     0x4aa810
  4aa7fc:	57                   	push   edi
  4aa7fd:	68 c4 26 c4 00       	push   0xc426c4
  4aa802:	e8 b6 88 3e 00       	call   0x8930bd
  4aa807:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4aa809:	83 c4 08             	add    esp,0x8
  4aa80c:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4aa810:	8b 3d 00 18 fe 00    	mov    edi,DWORD PTR ds:0xfe1800
  4aa816:	8b 37                	mov    esi,DWORD PTR [edi]
  4aa818:	68 70 ab d6 00       	push   0xd6ab70
  4aa81d:	e8 ee ac 24 00       	call   0x6f5510
  4aa822:	8b 37                	mov    esi,DWORD PTR [edi]
  4aa824:	83 c4 04             	add    esp,0x4
  4aa827:	6a 00                	push   0x0
  4aa829:	68 70 bf 4a 00       	push   0x4abf70
  4aa82e:	e8 7d ad 24 00       	call   0x6f55b0
  4aa833:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4aa835:	51                   	push   ecx
  4aa836:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4aa83b:	e8 b0 af 24 00       	call   0x6f57f0
  4aa840:	8b 15 00 18 fe 00    	mov    edx,DWORD PTR ds:0xfe1800
  4aa846:	8b 02                	mov    eax,DWORD PTR [edx]
  4aa848:	83 c4 0c             	add    esp,0xc
  4aa84b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4aa84f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4aa852:	5f                   	pop    edi
  4aa853:	5e                   	pop    esi
  4aa854:	5b                   	pop    ebx
  4aa855:	5d                   	pop    ebp
  4aa856:	c2 04 00             	ret    0x4
```

### InsertIsilia local object and 0xF000 writer — VA `0x004AA070..0x004AA239`, raw `0xA9470..0xA9639`

- 此 byte slice SHA256 `8a20aa2b347b0dcc3a25c94384af2b6165bee0d7038c725ef067caded2e75933`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004aa070 <.data+0xa9470>:
  4aa070:	55                   	push   ebp
  4aa071:	8b ec                	mov    ebp,esp
  4aa073:	83 e4 f8             	and    esp,0xfffffff8
  4aa076:	6a ff                	push   0xffffffff
  4aa078:	68 e7 97 93 00       	push   0x9397e7
  4aa07d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4aa083:	50                   	push   eax
  4aa084:	83 ec 0c             	sub    esp,0xc
  4aa087:	56                   	push   esi
  4aa088:	57                   	push   edi
  4aa089:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4aa08e:	33 c4                	xor    eax,esp
  4aa090:	50                   	push   eax
  4aa091:	8d 44 24 18          	lea    eax,[esp+0x18]
  4aa095:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4aa09b:	8b f1                	mov    esi,ecx
  4aa09d:	8d 44 24 0c          	lea    eax,[esp+0xc]
  4aa0a1:	50                   	push   eax
  4aa0a2:	8d 4e 24             	lea    ecx,[esi+0x24]
  4aa0a5:	8d 44 24 14          	lea    eax,[esp+0x14]
  4aa0a9:	c7 44 24 10 03 00 00 	mov    DWORD PTR [esp+0x10],0x3
  4aa0b0:	00 
  4aa0b1:	e8 7a 04 00 00       	call   0x4aa530
  4aa0b6:	8b 76 28             	mov    esi,DWORD PTR [esi+0x28]
  4aa0b9:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  4aa0bd:	3b c6                	cmp    eax,esi
  4aa0bf:	0f 84 62 01 00 00    	je     0x4aa227
  4aa0c5:	8d 78 10             	lea    edi,[eax+0x10]
  4aa0c8:	85 ff                	test   edi,edi
  4aa0ca:	0f 84 57 01 00 00    	je     0x4aa227
  4aa0d0:	68 20 04 00 00       	push   0x420
  4aa0d5:	e8 8e 71 3e 00       	call   0x891268
  4aa0da:	83 c4 04             	add    esp,0x4
  4aa0dd:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4aa0e1:	c7 44 24 20 00 00 00 	mov    DWORD PTR [esp+0x20],0x0
  4aa0e8:	00 
  4aa0e9:	85 c0                	test   eax,eax
  4aa0eb:	74 0a                	je     0x4aa0f7
  4aa0ed:	50                   	push   eax
  4aa0ee:	e8 7d cf 01 00       	call   0x4c7070
  4aa0f3:	8b f0                	mov    esi,eax
  4aa0f5:	eb 02                	jmp    0x4aa0f9
  4aa0f7:	33 f6                	xor    esi,esi
  4aa0f9:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  4aa100:	ff 
  4aa101:	8b 06                	mov    eax,DWORD PTR [esi]
  4aa103:	33 c9                	xor    ecx,ecx
  4aa105:	66 89 4c 24 0c       	mov    WORD PTR [esp+0xc],cx
  4aa10a:	66 c7 44 24 0c 00 f0 	mov    WORD PTR [esp+0xc],0xf000
  4aa111:	66 8b 54 24 0c       	mov    dx,WORD PTR [esp+0xc]
  4aa116:	66 89 56 04          	mov    WORD PTR [esi+0x4],dx
  4aa11a:	8b 50 3c             	mov    edx,DWORD PTR [eax+0x3c]
  4aa11d:	6a 04                	push   0x4
  4aa11f:	8b ce                	mov    ecx,esi
  4aa121:	c7 86 90 00 00 00 10 	mov    DWORD PTR [esi+0x90],0x10
  4aa128:	00 00 00 
  4aa12b:	ff d2                	call   edx
  4aa12d:	8b 06                	mov    eax,DWORD PTR [esi]
  4aa12f:	8b 50 44             	mov    edx,DWORD PTR [eax+0x44]
  4aa132:	6a 01                	push   0x1
  4aa134:	83 c7 04             	add    edi,0x4
  4aa137:	57                   	push   edi
  4aa138:	8b ce                	mov    ecx,esi
  4aa13a:	ff d2                	call   edx
  4aa13c:	8b 06                	mov    eax,DWORD PTR [esi]
  4aa13e:	8b 50 58             	mov    edx,DWORD PTR [eax+0x58]
  4aa141:	6a 00                	push   0x0
  4aa143:	8b ce                	mov    ecx,esi
  4aa145:	ff d2                	call   edx
  4aa147:	f6 05 28 88 fb 00 01 	test   BYTE PTR ds:0xfb8828,0x1
  4aa14e:	bf 01 00 00 00       	mov    edi,0x1
  4aa153:	75 24                	jne    0x4aa179
  4aa155:	09 3d 28 88 fb 00    	or     DWORD PTR ds:0xfb8828,edi
  4aa15b:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  4aa15f:	e8 ec 56 0a 00       	call   0x54f850
  4aa164:	68 80 d5 bc 00       	push   0xbcd580
  4aa169:	e8 ac 81 3e 00       	call   0x89231a
  4aa16e:	83 c4 04             	add    esp,0x4
  4aa171:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  4aa178:	ff 
  4aa179:	d9 05 bc 90 fb 00    	fld    DWORD PTR ds:0xfb90bc
  4aa17f:	8b 06                	mov    eax,DWORD PTR [esi]
  4aa181:	dc 0d 78 5d c5 00    	fmul   QWORD PTR ds:0xc55d78
  4aa187:	8b 50 5c             	mov    edx,DWORD PTR [eax+0x5c]
  4aa18a:	51                   	push   ecx
  4aa18b:	8b ce                	mov    ecx,esi
  4aa18d:	d9 5c 24 14          	fstp   DWORD PTR [esp+0x14]
  4aa191:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  4aa195:	d9 1c 24             	fstp   DWORD PTR [esp]
  4aa198:	ff d2                	call   edx
  4aa19a:	8b c7                	mov    eax,edi
  4aa19c:	66 89 86 88 03 00 00 	mov    WORD PTR [esi+0x388],ax
  4aa1a3:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4aa1a9:	85 c0                	test   eax,eax
  4aa1ab:	74 11                	je     0x4aa1be
  4aa1ad:	83 be 70 03 00 00 00 	cmp    DWORD PTR [esi+0x370],0x0
  4aa1b4:	74 08                	je     0x4aa1be
  4aa1b6:	57                   	push   edi
  4aa1b7:	57                   	push   edi
  4aa1b8:	50                   	push   eax
  4aa1b9:	e8 e2 cc 2f 00       	call   0x7a6ea0
  4aa1be:	8b 16                	mov    edx,DWORD PTR [esi]
  4aa1c0:	8b 42 30             	mov    eax,DWORD PTR [edx+0x30]
  4aa1c3:	8b ce                	mov    ecx,esi
  4aa1c5:	ff d0                	call   eax
  4aa1c7:	8b 96 f0 00 00 00    	mov    edx,DWORD PTR [esi+0xf0]
  4aa1cd:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  4aa1d0:	8d 8e f0 00 00 00    	lea    ecx,[esi+0xf0]
  4aa1d6:	6a 14                	push   0x14
  4aa1d8:	ff d0                	call   eax
  4aa1da:	d9 e8                	fld1
  4aa1dc:	8b 16                	mov    edx,DWORD PTR [esi]
  4aa1de:	8b 42 68             	mov    eax,DWORD PTR [edx+0x68]
  4aa1e1:	51                   	push   ecx
  4aa1e2:	d9 1c 24             	fstp   DWORD PTR [esp]
  4aa1e5:	57                   	push   edi
  4aa1e6:	8b ce                	mov    ecx,esi
  4aa1e8:	ff d0                	call   eax
  4aa1ea:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4aa1f1:	75 28                	jne    0x4aa21b
  4aa1f3:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  4aa1f9:	c7 44 24 20 02 00 00 	mov    DWORD PTR [esp+0x20],0x2
  4aa200:	00 
  4aa201:	e8 8a 4a 03 00       	call   0x4dec90
  4aa206:	68 30 ce bc 00       	push   0xbcce30
  4aa20b:	e8 0a 81 3e 00       	call   0x89231a
  4aa210:	83 c4 04             	add    esp,0x4
  4aa213:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  4aa21a:	ff 
  4aa21b:	68 30 b1 fa 00       	push   0xfab130
  4aa220:	8b c6                	mov    eax,esi
  4aa222:	e8 09 5d 03 00       	call   0x4dff30
  4aa227:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4aa22b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4aa232:	59                   	pop    ecx
  4aa233:	5f                   	pop    edi
  4aa234:	5e                   	pop    esi
  4aa235:	8b e5                	mov    esp,ebp
  4aa237:	5d                   	pop    ebp
  4aa238:	c3                   	ret
```

### IsIsiliaFound local object lookup — VA `0x004AA240..0x004AA319`, raw `0xA9640..0xA9719`

- 此 byte slice SHA256 `773f584a9680f8b333bd5f2f6dba8db3649e373ee3455cb914b222972fc437ba`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004aa240 <.data+0xa9640>:
  4aa240:	55                   	push   ebp
  4aa241:	8b ec                	mov    ebp,esp
  4aa243:	83 e4 f8             	and    esp,0xfffffff8
  4aa246:	6a ff                	push   0xffffffff
  4aa248:	68 ca 6e 93 00       	push   0x936eca
  4aa24d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4aa253:	50                   	push   eax
  4aa254:	83 ec 4c             	sub    esp,0x4c
  4aa257:	56                   	push   esi
  4aa258:	57                   	push   edi
  4aa259:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4aa25e:	33 c4                	xor    eax,esp
  4aa260:	50                   	push   eax
  4aa261:	8d 44 24 58          	lea    eax,[esp+0x58]
  4aa265:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4aa26b:	33 c0                	xor    eax,eax
  4aa26d:	83 cf ff             	or     edi,0xffffffff
  4aa270:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4aa277:	66 89 44 24 0c       	mov    WORD PTR [esp+0xc],ax
  4aa27c:	66 c7 44 24 0c 00 f0 	mov    WORD PTR [esp+0xc],0xf000
  4aa283:	75 21                	jne    0x4aa2a6
  4aa285:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4aa28c:	89 44 24 60          	mov    DWORD PTR [esp+0x60],eax
  4aa290:	e8 fb 49 03 00       	call   0x4dec90
  4aa295:	68 30 ce bc 00       	push   0xbcce30
  4aa29a:	e8 7b 80 3e 00       	call   0x89231a
  4aa29f:	83 c4 04             	add    esp,0x4
  4aa2a2:	89 7c 24 60          	mov    DWORD PTR [esp+0x60],edi
  4aa2a6:	0f b7 4c 24 0c       	movzx  ecx,WORD PTR [esp+0xc]
  4aa2ab:	8d 54 24 0c          	lea    edx,[esp+0xc]
  4aa2af:	89 4c 24 0c          	mov    DWORD PTR [esp+0xc],ecx
  4aa2b3:	52                   	push   edx
  4aa2b4:	8d 44 24 14          	lea    eax,[esp+0x14]
  4aa2b8:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4aa2bd:	e8 3e 4c 38 00       	call   0x82ef00
  4aa2c2:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  4aa2c6:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  4aa2cc:	0f 84 b4 01 00 00    	je     0x4aa486
  4aa2d2:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  4aa2d5:	85 c9                	test   ecx,ecx
  4aa2d7:	0f 84 a9 01 00 00    	je     0x4aa486
  4aa2dd:	8b 01                	mov    eax,DWORD PTR [ecx]
  4aa2df:	8b 50 4c             	mov    edx,DWORD PTR [eax+0x4c]
  4aa2e2:	ff d2                	call   edx
  4aa2e4:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  4aa2eb:	8b f0                	mov    esi,eax
  4aa2ed:	75 25                	jne    0x4aa314
  4aa2ef:	b8 01 00 00 00       	mov    eax,0x1
  4aa2f4:	09 05 e8 79 fb 00    	or     DWORD PTR ds:0xfb79e8,eax
  4aa2fa:	89 44 24 60          	mov    DWORD PTR [esp+0x60],eax
  4aa2fe:	e8 dd ea 2e 00       	call   0x798de0
  4aa303:	68 e0 d2 bc 00       	push   0xbcd2e0
  4aa308:	e8 0d 80 3e 00       	call   0x89231a
  4aa30d:	83 c4 04             	add    esp,0x4
  4aa310:	89 7c 24 60          	mov    DWORD PTR [esp+0x60],edi
  4aa314:	83 3d e4 76 fb   	cmp    DWORD PTR ds:0xfb76e4,0x0
```

### IsIsiliaFound visibility/proximity logic and return — VA `0x004AA314..0x004AA49A`, raw `0xA9714..0xA989A`

- 此 byte slice SHA256 `5bd6de325eea1bde65aeca63e79916f60df62c65dcb799f5b53ac11247f6ae4b`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004aa314 <.data+0xa9714>:
  4aa314:	83 3d e4 76 fb 00 00 	cmp    DWORD PTR ds:0xfb76e4,0x0
  4aa31b:	74 29                	je     0x4aa346
  4aa31d:	d9 46 08             	fld    DWORD PTR [esi+0x8]
  4aa320:	8b 15 b0 76 fb 00    	mov    edx,DWORD PTR ds:0xfb76b0
  4aa326:	83 ec 0c             	sub    esp,0xc
  4aa329:	d9 5c 24 08          	fstp   DWORD PTR [esp+0x8]
  4aa32d:	d9 46 04             	fld    DWORD PTR [esi+0x4]
  4aa330:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  4aa334:	d9 06                	fld    DWORD PTR [esi]
  4aa336:	d9 1c 24             	fstp   DWORD PTR [esp]
  4aa339:	e8 c2 e4 38 00       	call   0x838800
  4aa33e:	85 c0                	test   eax,eax
  4aa340:	0f 84 40 01 00 00    	je     0x4aa486
  4aa346:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  4aa34d:	75 25                	jne    0x4aa374
  4aa34f:	83 0d e8 79 fb 00 01 	or     DWORD PTR ds:0xfb79e8,0x1
  4aa356:	c7 44 24 60 02 00 00 	mov    DWORD PTR [esp+0x60],0x2
  4aa35d:	00 
  4aa35e:	e8 7d ea 2e 00       	call   0x798de0
  4aa363:	68 e0 d2 bc 00       	push   0xbcd2e0
  4aa368:	e8 ad 7f 3e 00       	call   0x89231a
  4aa36d:	83 c4 04             	add    esp,0x4
  4aa370:	89 7c 24 60          	mov    DWORD PTR [esp+0x60],edi
  4aa374:	a1 e8 76 fb 00       	mov    eax,ds:0xfb76e8
  4aa379:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  4aa37c:	8b 11                	mov    edx,DWORD PTR [ecx]
  4aa37e:	8b 52 24             	mov    edx,DWORD PTR [edx+0x24]
  4aa381:	8d 44 24 28          	lea    eax,[esp+0x28]
  4aa385:	50                   	push   eax
  4aa386:	ff d2                	call   edx
  4aa388:	8b 08                	mov    ecx,DWORD PTR [eax]
  4aa38a:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4aa38d:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4aa390:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  4aa394:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  4aa398:	d8 26                	fsub   DWORD PTR [esi]
  4aa39a:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  4aa39e:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  4aa3a2:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  4aa3a6:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  4aa3aa:	d8 66 04             	fsub   DWORD PTR [esi+0x4]
  4aa3ad:	d9 5c 24 20          	fstp   DWORD PTR [esp+0x20]
  4aa3b1:	d9 44 24 18          	fld    DWORD PTR [esp+0x18]
  4aa3b5:	d8 66 08             	fsub   DWORD PTR [esi+0x8]
  4aa3b8:	d9 5c 24 24          	fstp   DWORD PTR [esp+0x24]
  4aa3bc:	d9 44 24 20          	fld    DWORD PTR [esp+0x20]
  4aa3c0:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  4aa3c4:	d9 44 24 24          	fld    DWORD PTR [esp+0x24]
  4aa3c8:	d9 c1                	fld    st(1)
  4aa3ca:	de ca                	fmulp  st(2),st
  4aa3cc:	d9 c2                	fld    st(2)
  4aa3ce:	de cb                	fmulp  st(3),st
  4aa3d0:	d9 c9                	fxch   st(1)
  4aa3d2:	de c2                	faddp  st(2),st
  4aa3d4:	dc c8                	fmul   st(0),st
  4aa3d6:	de c1                	faddp  st(1),st
  4aa3d8:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  4aa3dc:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  4aa3e0:	e8 8b 54 45 00       	call   0x8ff870
  4aa3e5:	d9 5c 24 10          	fstp   DWORD PTR [esp+0x10]
  4aa3e9:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  4aa3ed:	d9 05 70 57 c5 00    	fld    DWORD PTR ds:0xc55770
  4aa3f3:	df f1                	fcomip st,st(1)
  4aa3f5:	dd d8                	fstp   st(0)
  4aa3f7:	0f 86 89 00 00 00    	jbe    0x4aa486
  4aa3fd:	56                   	push   esi
  4aa3fe:	51                   	push   ecx
  4aa3ff:	e8 3c a3 f8 ff       	call   0x434740
  4aa404:	83 c4 04             	add    esp,0x4
  4aa407:	50                   	push   eax
  4aa408:	8d 7c 24 18          	lea    edi,[esp+0x18]
  4aa40c:	e8 9f 02 2f 00       	call   0x79a6b0
  4aa411:	e8 2a 58 23 00       	call   0x6dfc40
  4aa416:	8b 70 18             	mov    esi,DWORD PTR [eax+0x18]
  4aa419:	e8 22 58 23 00       	call   0x6dfc40
  4aa41e:	dd 05 e8 57 c5 00    	fld    QWORD PTR ds:0xc557e8
  4aa424:	d9 44 24 10          	fld    DWORD PTR [esp+0x10]
  4aa428:	8b 48 1c             	mov    ecx,DWORD PTR [eax+0x1c]
  4aa42b:	db f1                	fcomi  st,st(1)
  4aa42d:	76 53                	jbe    0x4aa482
  4aa42f:	d9 44 24 14          	fld    DWORD PTR [esp+0x14]
  4aa433:	db f2                	fcomi  st,st(2)
  4aa435:	dd da                	fstp   st(2)
  4aa437:	76 49                	jbe    0x4aa482
  4aa439:	83 c6 9c             	add    esi,0xffffff9c
  4aa43c:	89 74 24 10          	mov    DWORD PTR [esp+0x10],esi
  4aa440:	db 44 24 10          	fild   DWORD PTR [esp+0x10]
  4aa444:	79 06                	jns    0x4aa44c
  4aa446:	d8 05 80 56 c5 00    	fadd   DWORD PTR ds:0xc55680
  4aa44c:	df f1                	fcomip st,st(1)
  4aa44e:	dd d8                	fstp   st(0)
  4aa450:	76 32                	jbe    0x4aa484
  4aa452:	83 c1 9c             	add    ecx,0xffffff9c
  4aa455:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  4aa459:	db 44 24 10          	fild   DWORD PTR [esp+0x10]
  4aa45d:	79 06                	jns    0x4aa465
  4aa45f:	d8 05 80 56 c5 00    	fadd   DWORD PTR ds:0xc55680
  4aa465:	df f1                	fcomip st,st(1)
  4aa467:	dd d8                	fstp   st(0)
  4aa469:	76 1b                	jbe    0x4aa486
  4aa46b:	b8 01 00 00 00       	mov    eax,0x1
  4aa470:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  4aa474:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4aa47b:	59                   	pop    ecx
  4aa47c:	5f                   	pop    edi
  4aa47d:	5e                   	pop    esi
  4aa47e:	8b e5                	mov    esp,ebp
  4aa480:	5d                   	pop    ebp
  4aa481:	c3                   	ret
  4aa482:	dd d9                	fstp   st(1)
  4aa484:	dd d8                	fstp   st(0)
  4aa486:	33 c0                	xor    eax,eax
  4aa488:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  4aa48c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4aa493:	59                   	pop    ecx
  4aa494:	5f                   	pop    edi
  4aa495:	5e                   	pop    esi
  4aa496:	8b e5                	mov    esp,ebp
  4aa498:	5d                   	pop    ebp
  4aa499:	c3                   	ret
```

### Lua InsertIsilia wrapper — VA `0x004AC830..0x004AC890`, raw `0xABC30..0xABC90`

- 此 byte slice SHA256 `019c7059c53696dc25b9664b9f2355fdb331f59451985937cae3617f4dc88ad1`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004ac830 <.data+0xabc30>:
  4ac830:	55                   	push   ebp
  4ac831:	8b ec                	mov    ebp,esp
  4ac833:	6a ff                	push   0xffffffff
  4ac835:	68 c8 83 93 00       	push   0x9383c8
  4ac83a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ac840:	50                   	push   eax
  4ac841:	83 ec 0c             	sub    esp,0xc
  4ac844:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ac849:	33 c5                	xor    eax,ebp
  4ac84b:	50                   	push   eax
  4ac84c:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ac84f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4ac855:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ac858:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4ac85b:	33 c0                	xor    eax,eax
  4ac85d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4ac860:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4ac863:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4ac866:	8b 0d 04 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe1804
  4ac86c:	ff 15 6c 18 fe 00    	call   DWORD PTR ds:0xfe186c
  4ac872:	b8 01 00 00 00       	mov    eax,0x1
  4ac877:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4ac87a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4ac881:	59                   	pop    ecx
  4ac882:	8b e5                	mov    esp,ebp
  4ac884:	5d                   	pop    ebp
  4ac885:	c3                   	ret
  4ac886:	cc                   	int3
  4ac887:	cc                   	int3
  4ac888:	cc                   	int3
  4ac889:	cc                   	int3
  4ac88a:	cc                   	int3
  4ac88b:	cc                   	int3
  4ac88c:	cc                   	int3
  4ac88d:	cc                   	int3
  4ac88e:	cc                   	int3
  4ac88f:	cc                   	int3
```

### Lua IsIsiliaFound wrapper — VA `0x004AC890..0x004AC900`, raw `0xABC90..0xABD00`

- 此 byte slice SHA256 `f6278ddc589a9342b94751cca6d891edb1b5dc7ef0c969b9bec20403f156f23e`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004ac890 <.data+0xabc90>:
  4ac890:	55                   	push   ebp
  4ac891:	8b ec                	mov    ebp,esp
  4ac893:	6a ff                	push   0xffffffff
  4ac895:	68 d8 87 93 00       	push   0x9387d8
  4ac89a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ac8a0:	50                   	push   eax
  4ac8a1:	83 ec 0c             	sub    esp,0xc
  4ac8a4:	56                   	push   esi
  4ac8a5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ac8aa:	33 c5                	xor    eax,ebp
  4ac8ac:	50                   	push   eax
  4ac8ad:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ac8b0:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4ac8b6:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4ac8b9:	33 c0                	xor    eax,eax
  4ac8bb:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  4ac8be:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4ac8c1:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4ac8c4:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4ac8c7:	8b 0d 04 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe1804
  4ac8cd:	ff 15 70 18 fe 00    	call   DWORD PTR ds:0xfe1870
  4ac8d3:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  4ac8d6:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4ac8d9:	db 45 08             	fild   DWORD PTR [ebp+0x8]
  4ac8dc:	c7 40 08 03 00 00 00 	mov    DWORD PTR [eax+0x8],0x3
  4ac8e3:	dd 18                	fstp   QWORD PTR [eax]
  4ac8e5:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  4ac8e9:	b8 01 00 00 00       	mov    eax,0x1
  4ac8ee:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4ac8f1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4ac8f8:	59                   	pop    ecx
  4ac8f9:	5e                   	pop    esi
  4ac8fa:	8b e5                	mov    esp,ebp
  4ac8fc:	5d                   	pop    ebp
  4ac8fd:	c3                   	ret
  4ac8fe:	cc                   	int3
  4ac8ff:	cc                   	int3
```

### Lua native tutorial state getter — VA `0x004A9FD0..0x004A9FDC`, raw `0xA93D0..0xA93DC`

- 此 byte slice SHA256 `49ec099b4231b18fad1b20139c7b133e78d8d5eb249d56566ef42a8df4671a77`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004a9fd0 <.data+0xa93d0>:
  4a9fd0:	a1 a4 a7 fb 00       	mov    eax,ds:0xfba7a4
  4a9fd5:	8b 80 34 01 00 00    	mov    eax,DWORD PTR [eax+0x134]
  4a9fdb:	c3                   	ret
```

### Scene scenario request packet writer — VA `0x004AA4D0..0x004AA510`, raw `0xA98D0..0xA9910`

- 此 byte slice SHA256 `71263a85ac0ab468ae0aba3f19dfd1da6a42ef2f687f0415a3567ddb70366227`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004aa4d0 <.data+0xa98d0>:
  4aa4d0:	55                   	push   ebp
  4aa4d1:	8b ec                	mov    ebp,esp
  4aa4d3:	51                   	push   ecx
  4aa4d4:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4aa4db:	66 8b 4d 08          	mov    cx,WORD PTR [ebp+0x8]
  4aa4df:	b8 40 00 00 00       	mov    eax,0x40
  4aa4e4:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4aa4e8:	66 89 4d fe          	mov    WORD PTR [ebp-0x2],cx
  4aa4ec:	75 15                	jne    0x4aa503
  4aa4ee:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4aa4f4:	8b 11                	mov    edx,DWORD PTR [ecx]
  4aa4f6:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4aa4f9:	6a 04                	push   0x4
  4aa4fb:	8d 45 fc             	lea    eax,[ebp-0x4]
  4aa4fe:	50                   	push   eax
  4aa4ff:	6a 00                	push   0x0
  4aa501:	ff d2                	call   edx
  4aa503:	8b e5                	mov    esp,ebp
  4aa505:	5d                   	pop    ebp
  4aa506:	c2 04 00             	ret    0x4
  4aa509:	cc                   	int3
  4aa50a:	cc                   	int3
  4aa50b:	cc                   	int3
  4aa50c:	cc                   	int3
  4aa50d:	cc                   	int3
  4aa50e:	cc                   	int3
  4aa50f:	cc                   	int3
```

### CTutorial scenario-ended receive handler — VA `0x004C4F20..0x004C4FA0`, raw `0xC4320..0xC43A0`

- 此 byte slice SHA256 `6409b0e377c0c5fb5a64f92069c34bd7ec79c50ed62aebaa1d9c7747d7784041`；指令中的跳表、錯位切片及分支不可直接當作可執行路徑。

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004c4f20 <.data+0xc4320>:
  4c4f20:	55                   	push   ebp
  4c4f21:	8b ec                	mov    ebp,esp
  4c4f23:	6a ff                	push   0xffffffff
  4c4f25:	68 9e 76 92 00       	push   0x92769e
  4c4f2a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c4f30:	50                   	push   eax
  4c4f31:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c4f36:	33 c5                	xor    eax,ebp
  4c4f38:	50                   	push   eax
  4c4f39:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c4f3c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c4f42:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c4f49:	75 27                	jne    0x4c4f72
  4c4f4b:	83 0d 80 0f fc 00 01 	or     DWORD PTR ds:0xfc0f80,0x1
  4c4f52:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4c4f59:	e8 52 5f fb ff       	call   0x47aeb0
  4c4f5e:	68 70 db bc 00       	push   0xbcdb70
  4c4f63:	e8 b2 d3 3c 00       	call   0x89231a
  4c4f68:	83 c4 04             	add    esp,0x4
  4c4f6b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4c4f72:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c4f75:	0f b7 48 02          	movzx  ecx,WORD PTR [eax+0x2]
  4c4f79:	8d 55 08             	lea    edx,[ebp+0x8]
  4c4f7c:	b8 88 0f fc 00       	mov    eax,0xfc0f88
  4c4f81:	89 4d 08             	mov    DWORD PTR [ebp+0x8],ecx
  4c4f84:	e8 f7 d8 ff ff       	call   0x4c2880
  4c4f89:	c7 00 01 00 00 00    	mov    DWORD PTR [eax],0x1
  4c4f8f:	33 c0                	xor    eax,eax
  4c4f91:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4c4f94:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c4f9b:	59                   	pop    ecx
  4c4f9c:	8b e5                	mov    esp,ebp
  4c4f9e:	5d                   	pop    ebp
  4c4f9f:	c2               	ret    0xc
```

## Appendix B — `Event/TutorialMain.lua` 原始 Lua 5.1 bytecode，與 quest14-② 有關之所有本地函式

`PC` 從0起；`GETTABLE` 的 RK 常數 index = C−256（當 C>=256）。Lua C API 取回的回傳值不能將 `CALL C=1` 誤當 1 value，它是 0 個 Lua result；`CALL C=2` 才是 1 個 return。`EQ/JMP` 對應原件 bytecode，實際分支語意應連讀相鄰指令。下表是原始 opcode 靜態表，並非自行編寫的 Lua source。

### nested proto4 Lua line `48..124`（197 opcodes）

常數：

```text
000: 'Tutorial'
001: 'PostUIMessage_TutoMsg'
002: 0.0
003: 1.0
004: 'PlayAndWaitForScene'
005: 1000.0
006: 'ApplyDefaultCamera'
007: 'TUTORIAL_PROGRESS_NUMBER'
008: 'TUTORIAL_CHANGEKEYTYPE'
009: 'GetTutorialState'
010: 'FALSE'
011: 'yield'
012: 'TUTORIAL_KEYBOARD'
013: 'InsertTutorialCheckPoint'
014: 'GetControlStatus'
015: 'SetCheckPointStatus'
016: 'CHECKPOINT_CATEGORY'
017: 'TUTORIAL_POINT'
018: 'CHECKPOINT_STATUS'
019: 'ST_CLOSE'
020: 3.0
021: 'TUTORIAL_MOUSE'
022: 2.0
023: 4.0
024: 'TUTORIAL_CAMERA'
025: 'InsertIsilia'
026: 'IsIsiliaFound'
027: 6.0
028: 'TUTORIAL_LEADER_CHANGE'
029: 'CheckLeader'
030: 'IsLeaderDialogOpened'
031: 'TUTORIAL_LC_DLG_OPENED'
032: 7.0
033: 'TUTORIAL_GOTO_NPC'
```

原始 opcode：

```text
000: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
001: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
002: 0x00008041 LOADK A=1 B=0 C=2 Bx=2 sBx=-131069
003: 0x0000C081 LOADK A=2 B=0 C=3 Bx=3 sBx=-131068
004: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
005: 0x00010005 GETGLOBAL A=0 B=0 C=4 Bx=4 sBx=-131067
006: 0x00014041 LOADK A=1 B=0 C=5 Bx=5 sBx=-131066
007: 0x0000C081 LOADK A=2 B=0 C=3 Bx=3 sBx=-131068
008: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
009: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
010: 0x00418006 GETTABLE A=0 B=0 C=262 Bx=262 sBx=-130809
011: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
012: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
013: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
014: 0x0001C045 GETGLOBAL A=1 B=0 C=7 Bx=7 sBx=-131064
015: 0x00C20046 GETTABLE A=1 B=1 C=264 Bx=776 sBx=-130295
016: 0x00008081 LOADK A=2 B=0 C=2 Bx=2 sBx=-131069
017: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
018: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
019: 0x00424006 GETTABLE A=0 B=0 C=265 Bx=265 sBx=-130806
020: 0x0080801C CALL A=0 B=1 C=2 Bx=514 sBx=-130557
021: 0x00028045 GETGLOBAL A=1 B=0 C=10 Bx=10 sBx=-131061
022: 0x00004017 EQ A=0 B=0 C=1 Bx=1 sBx=-131070
023: 0x80008016 JMP A=0 B=256 C=2 Bx=131074 sBx=3
024: 0x0002C005 GETGLOBAL A=0 B=0 C=11 Bx=11 sBx=-131060
025: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
026: 0x7FFD8016 JMP A=0 B=255 C=502 Bx=131062 sBx=-9
027: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
028: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
029: 0x0001C045 GETGLOBAL A=1 B=0 C=7 Bx=7 sBx=-131064
030: 0x00C30046 GETTABLE A=1 B=1 C=268 Bx=780 sBx=-130291
031: 0x00008081 LOADK A=2 B=0 C=2 Bx=2 sBx=-131069
032: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
033: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
034: 0x00434006 GETTABLE A=0 B=0 C=269 Bx=269 sBx=-130802
035: 0x0000C041 LOADK A=1 B=0 C=3 Bx=3 sBx=-131068
036: 0x0100401C CALL A=0 B=2 C=1 Bx=1025 sBx=-130046
037: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
038: 0x00438006 GETTABLE A=0 B=0 C=270 Bx=270 sBx=-130801
039: 0x0000C041 LOADK A=1 B=0 C=3 Bx=3 sBx=-131068
040: 0x0100801C CALL A=0 B=2 C=2 Bx=1026 sBx=-130045
041: 0x00028045 GETGLOBAL A=1 B=0 C=10 Bx=10 sBx=-131061
042: 0x00004017 EQ A=0 B=0 C=1 Bx=1 sBx=-131070
043: 0x80008016 JMP A=0 B=256 C=2 Bx=131074 sBx=3
044: 0x0002C005 GETGLOBAL A=0 B=0 C=11 Bx=11 sBx=-131060
045: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
046: 0x7FFD4016 JMP A=0 B=255 C=501 Bx=131061 sBx=-10
047: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
048: 0x0043C006 GETTABLE A=0 B=0 C=271 Bx=271 sBx=-130800
049: 0x0000C041 LOADK A=1 B=0 C=3 Bx=3 sBx=-131068
050: 0x00040085 GETGLOBAL A=2 B=0 C=16 Bx=16 sBx=-131055
051: 0x01444086 GETTABLE A=2 B=2 C=273 Bx=1297 sBx=-129774
052: 0x000480C5 GETGLOBAL A=3 B=0 C=18 Bx=18 sBx=-131053
053: 0x01C4C0C6 GETTABLE A=3 B=3 C=275 Bx=1811 sBx=-129260
054: 0x0200401C CALL A=0 B=4 C=1 Bx=2049 sBx=-129022
055: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
056: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
057: 0x00008041 LOADK A=1 B=0 C=2 Bx=2 sBx=-131069
058: 0x0000C081 LOADK A=2 B=0 C=3 Bx=3 sBx=-131068
059: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
060: 0x00010005 GETGLOBAL A=0 B=0 C=4 Bx=4 sBx=-131067
061: 0x00014041 LOADK A=1 B=0 C=5 Bx=5 sBx=-131066
062: 0x00050081 LOADK A=2 B=0 C=20 Bx=20 sBx=-131051
063: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
064: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
065: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
066: 0x0001C045 GETGLOBAL A=1 B=0 C=7 Bx=7 sBx=-131064
067: 0x00C54046 GETTABLE A=1 B=1 C=277 Bx=789 sBx=-130282
068: 0x00008081 LOADK A=2 B=0 C=2 Bx=2 sBx=-131069
069: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
070: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
071: 0x00434006 GETTABLE A=0 B=0 C=269 Bx=269 sBx=-130802
072: 0x00058041 LOADK A=1 B=0 C=22 Bx=22 sBx=-131049
073: 0x0100401C CALL A=0 B=2 C=1 Bx=1025 sBx=-130046
074: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
075: 0x00438006 GETTABLE A=0 B=0 C=270 Bx=270 sBx=-130801
076: 0x00058041 LOADK A=1 B=0 C=22 Bx=22 sBx=-131049
077: 0x0100801C CALL A=0 B=2 C=2 Bx=1026 sBx=-130045
078: 0x00028045 GETGLOBAL A=1 B=0 C=10 Bx=10 sBx=-131061
079: 0x00004017 EQ A=0 B=0 C=1 Bx=1 sBx=-131070
080: 0x80008016 JMP A=0 B=256 C=2 Bx=131074 sBx=3
081: 0x0002C005 GETGLOBAL A=0 B=0 C=11 Bx=11 sBx=-131060
082: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
083: 0x7FFD4016 JMP A=0 B=255 C=501 Bx=131061 sBx=-10
084: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
085: 0x0043C006 GETTABLE A=0 B=0 C=271 Bx=271 sBx=-130800
086: 0x00058041 LOADK A=1 B=0 C=22 Bx=22 sBx=-131049
087: 0x00040085 GETGLOBAL A=2 B=0 C=16 Bx=16 sBx=-131055
088: 0x01444086 GETTABLE A=2 B=2 C=273 Bx=1297 sBx=-129774
089: 0x000480C5 GETGLOBAL A=3 B=0 C=18 Bx=18 sBx=-131053
090: 0x01C4C0C6 GETTABLE A=3 B=3 C=275 Bx=1811 sBx=-129260
091: 0x0200401C CALL A=0 B=4 C=1 Bx=2049 sBx=-129022
092: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
093: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
094: 0x00008041 LOADK A=1 B=0 C=2 Bx=2 sBx=-131069
095: 0x0000C081 LOADK A=2 B=0 C=3 Bx=3 sBx=-131068
096: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
097: 0x00010005 GETGLOBAL A=0 B=0 C=4 Bx=4 sBx=-131067
098: 0x00014041 LOADK A=1 B=0 C=5 Bx=5 sBx=-131066
099: 0x0005C081 LOADK A=2 B=0 C=23 Bx=23 sBx=-131048
100: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
101: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
102: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
103: 0x0001C045 GETGLOBAL A=1 B=0 C=7 Bx=7 sBx=-131064
104: 0x00C60046 GETTABLE A=1 B=1 C=280 Bx=792 sBx=-130279
105: 0x00008081 LOADK A=2 B=0 C=2 Bx=2 sBx=-131069
106: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
107: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
108: 0x00464006 GETTABLE A=0 B=0 C=281 Bx=281 sBx=-130790
109: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
110: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
111: 0x00468006 GETTABLE A=0 B=0 C=282 Bx=282 sBx=-130789
112: 0x0080801C CALL A=0 B=1 C=2 Bx=514 sBx=-130557
113: 0x00028045 GETGLOBAL A=1 B=0 C=10 Bx=10 sBx=-131061
114: 0x00004017 EQ A=0 B=0 C=1 Bx=1 sBx=-131070
115: 0x80008016 JMP A=0 B=256 C=2 Bx=131074 sBx=3
116: 0x0002C005 GETGLOBAL A=0 B=0 C=11 Bx=11 sBx=-131060
117: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
118: 0x7FFD8016 JMP A=0 B=255 C=502 Bx=131062 sBx=-9
119: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
120: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
121: 0x00008041 LOADK A=1 B=0 C=2 Bx=2 sBx=-131069
122: 0x0000C081 LOADK A=2 B=0 C=3 Bx=3 sBx=-131068
123: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
124: 0x00010005 GETGLOBAL A=0 B=0 C=4 Bx=4 sBx=-131067
125: 0x00014041 LOADK A=1 B=0 C=5 Bx=5 sBx=-131066
126: 0x0006C081 LOADK A=2 B=0 C=27 Bx=27 sBx=-131044
127: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
128: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
129: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
130: 0x0001C045 GETGLOBAL A=1 B=0 C=7 Bx=7 sBx=-131064
131: 0x00C70046 GETTABLE A=1 B=1 C=284 Bx=796 sBx=-130275
132: 0x00008081 LOADK A=2 B=0 C=2 Bx=2 sBx=-131069
133: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
134: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
135: 0x00474006 GETTABLE A=0 B=0 C=285 Bx=285 sBx=-130786
136: 0x0080801C CALL A=0 B=1 C=2 Bx=514 sBx=-130557
137: 0x00028045 GETGLOBAL A=1 B=0 C=10 Bx=10 sBx=-131061
138: 0x00004017 EQ A=0 B=0 C=1 Bx=1 sBx=-131070
139: 0x80054016 JMP A=0 B=256 C=21 Bx=131093 sBx=22
140: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
141: 0x00478006 GETTABLE A=0 B=0 C=286 Bx=286 sBx=-130785
142: 0x0080801C CALL A=0 B=1 C=2 Bx=514 sBx=-130557
143: 0x00028045 GETGLOBAL A=1 B=0 C=10 Bx=10 sBx=-131061
144: 0x00004017 EQ A=0 B=0 C=1 Bx=1 sBx=-131070
145: 0x80018016 JMP A=0 B=256 C=6 Bx=131078 sBx=7
146: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
147: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
148: 0x0001C045 GETGLOBAL A=1 B=0 C=7 Bx=7 sBx=-131064
149: 0x00C70046 GETTABLE A=1 B=1 C=284 Bx=796 sBx=-130275
150: 0x00008081 LOADK A=2 B=0 C=2 Bx=2 sBx=-131069
151: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
152: 0x80014016 JMP A=0 B=256 C=5 Bx=131077 sBx=6
153: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
154: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
155: 0x0001C045 GETGLOBAL A=1 B=0 C=7 Bx=7 sBx=-131064
156: 0x00C7C046 GETTABLE A=1 B=1 C=287 Bx=799 sBx=-130272
157: 0x00008081 LOADK A=2 B=0 C=2 Bx=2 sBx=-131069
158: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
159: 0x0002C005 GETGLOBAL A=0 B=0 C=11 Bx=11 sBx=-131060
160: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
161: 0x7FF8C016 JMP A=0 B=255 C=483 Bx=131043 sBx=-28
162: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
163: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
164: 0x00008041 LOADK A=1 B=0 C=2 Bx=2 sBx=-131069
165: 0x0000C081 LOADK A=2 B=0 C=3 Bx=3 sBx=-131068
166: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
167: 0x00010005 GETGLOBAL A=0 B=0 C=4 Bx=4 sBx=-131067
168: 0x00014041 LOADK A=1 B=0 C=5 Bx=5 sBx=-131066
169: 0x00080081 LOADK A=2 B=0 C=32 Bx=32 sBx=-131039
170: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
171: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
172: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
173: 0x0001C045 GETGLOBAL A=1 B=0 C=7 Bx=7 sBx=-131064
174: 0x00C84046 GETTABLE A=1 B=1 C=289 Bx=801 sBx=-130270
175: 0x00008081 LOADK A=2 B=0 C=2 Bx=2 sBx=-131069
176: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
177: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
178: 0x00434006 GETTABLE A=0 B=0 C=269 Bx=269 sBx=-130802
179: 0x00050041 LOADK A=1 B=0 C=20 Bx=20 sBx=-131051
180: 0x0100401C CALL A=0 B=2 C=1 Bx=1025 sBx=-130046
181: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
182: 0x00438006 GETTABLE A=0 B=0 C=270 Bx=270 sBx=-130801
183: 0x00050041 LOADK A=1 B=0 C=20 Bx=20 sBx=-131051
184: 0x0100801C CALL A=0 B=2 C=2 Bx=1026 sBx=-130045
185: 0x00028045 GETGLOBAL A=1 B=0 C=10 Bx=10 sBx=-131061
186: 0x00004017 EQ A=0 B=0 C=1 Bx=1 sBx=-131070
187: 0x80008016 JMP A=0 B=256 C=2 Bx=131074 sBx=3
188: 0x0002C005 GETGLOBAL A=0 B=0 C=11 Bx=11 sBx=-131060
189: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
190: 0x7FFD4016 JMP A=0 B=255 C=501 Bx=131061 sBx=-10
191: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
192: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
193: 0x00008041 LOADK A=1 B=0 C=2 Bx=2 sBx=-131069
194: 0x0000C081 LOADK A=2 B=0 C=3 Bx=3 sBx=-131068
195: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
196: 0x0080001E RETURN A=0 B=1 C=0 Bx=512 sBx=-130559
```

### nested proto5 Lua line `131..199`（158 opcodes）

常數：

```text
000: 'PlayAndWaitForScene'
001: 1000.0
002: 8.0
003: 'Tutorial'
004: 'PostUIMessage_TutoMsg'
005: 0.0
006: 6.0
007: 'yield'
008: 1.0
009: 'RequestStartScenario'
010: 14.0
011: 'IsScenarioEnded'
012: 'FALSE'
013: 'SetUIPage'
014: 'SetCheckPointStatus'
015: 10016.0
016: 'CHECKPOINT_CATEGORY'
017: 'NPC'
018: 'CHECKPOINT_STATUS'
019: 'ST_CLOSE'
020: 10.0
021: 12.0
022: 'HideUI'
023: 'PostUIMessage_EmployChar'
024: 4.0
025: 'g_TutoEmployCharQuery'
026: 'TUTORIAL_PROGRESS_NUMBER'
027: 'TUTORIAL_PINKOHOUSE'
028: 'InsertTutorialCheckPoint'
029: 'GetControlStatus'
030: 'TUTORIAL_POINT'
031: 'RegisterScalingObject'
032: 'Image/Cut_in/Lenart_PinkoRoom.dds'
033: 1024.0
034: 512.0
035: 13.0
036: 'DestroyFlyingObjects'
037: 'IsCharacterAvailable'
038: 2.0
039: 'ST_OPEN'
040: 'TUTORIAL_STARTSCENARIO'
```

原始 opcode：

```text
000: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
001: 0x00004041 LOADK A=1 B=0 C=1 Bx=1 sBx=-131070
002: 0x00008081 LOADK A=2 B=0 C=2 Bx=2 sBx=-131069
003: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
004: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
005: 0x00410006 GETTABLE A=0 B=0 C=260 Bx=260 sBx=-130811
006: 0x00014041 LOADK A=1 B=0 C=5 Bx=5 sBx=-131066
007: 0x00018081 LOADK A=2 B=0 C=6 Bx=6 sBx=-131065
008: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
009: 0x0001C005 GETGLOBAL A=0 B=0 C=7 Bx=7 sBx=-131064
010: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
011: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
012: 0x00410006 GETTABLE A=0 B=0 C=260 Bx=260 sBx=-130811
013: 0x00014041 LOADK A=1 B=0 C=5 Bx=5 sBx=-131066
014: 0x00020081 LOADK A=2 B=0 C=8 Bx=8 sBx=-131063
015: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
016: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
017: 0x00424006 GETTABLE A=0 B=0 C=265 Bx=265 sBx=-130806
018: 0x00028041 LOADK A=1 B=0 C=10 Bx=10 sBx=-131061
019: 0x0100401C CALL A=0 B=2 C=1 Bx=1025 sBx=-130046
020: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
021: 0x0042C006 GETTABLE A=0 B=0 C=267 Bx=267 sBx=-130804
022: 0x00028041 LOADK A=1 B=0 C=10 Bx=10 sBx=-131061
023: 0x0100801C CALL A=0 B=2 C=2 Bx=1026 sBx=-130045
024: 0x00030045 GETGLOBAL A=1 B=0 C=12 Bx=12 sBx=-131059
025: 0x00004017 EQ A=0 B=0 C=1 Bx=1 sBx=-131070
026: 0x80008016 JMP A=0 B=256 C=2 Bx=131074 sBx=3
027: 0x0001C005 GETGLOBAL A=0 B=0 C=7 Bx=7 sBx=-131064
028: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
029: 0x7FFD4016 JMP A=0 B=255 C=501 Bx=131061 sBx=-10
030: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
031: 0x00434006 GETTABLE A=0 B=0 C=269 Bx=269 sBx=-130802
032: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
033: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
034: 0x00438006 GETTABLE A=0 B=0 C=270 Bx=270 sBx=-130801
035: 0x0003C041 LOADK A=1 B=0 C=15 Bx=15 sBx=-131056
036: 0x00040085 GETGLOBAL A=2 B=0 C=16 Bx=16 sBx=-131055
037: 0x01444086 GETTABLE A=2 B=2 C=273 Bx=1297 sBx=-129774
038: 0x000480C5 GETGLOBAL A=3 B=0 C=18 Bx=18 sBx=-131053
039: 0x01C4C0C6 GETTABLE A=3 B=3 C=275 Bx=1811 sBx=-129260
040: 0x0200401C CALL A=0 B=4 C=1 Bx=2049 sBx=-129022
041: 0x0001C005 GETGLOBAL A=0 B=0 C=7 Bx=7 sBx=-131064
042: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
043: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
044: 0x00004041 LOADK A=1 B=0 C=1 Bx=1 sBx=-131070
045: 0x00050081 LOADK A=2 B=0 C=20 Bx=20 sBx=-131051
046: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
047: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
048: 0x00004041 LOADK A=1 B=0 C=1 Bx=1 sBx=-131070
049: 0x00054081 LOADK A=2 B=0 C=21 Bx=21 sBx=-131050
050: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
051: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
052: 0x00458006 GETTABLE A=0 B=0 C=278 Bx=278 sBx=-130793
053: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
054: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
055: 0x0045C006 GETTABLE A=0 B=0 C=279 Bx=279 sBx=-130792
056: 0x00060041 LOADK A=1 B=0 C=24 Bx=24 sBx=-131047
057: 0x0100401C CALL A=0 B=2 C=1 Bx=1025 sBx=-130046
058: 0x00064005 GETGLOBAL A=0 B=0 C=25 Bx=25 sBx=-131046
059: 0x00030045 GETGLOBAL A=1 B=0 C=12 Bx=12 sBx=-131059
060: 0x00004017 EQ A=0 B=0 C=1 Bx=1 sBx=-131070
061: 0x80008016 JMP A=0 B=256 C=2 Bx=131074 sBx=3
062: 0x0001C005 GETGLOBAL A=0 B=0 C=7 Bx=7 sBx=-131064
063: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
064: 0x7FFE0016 JMP A=0 B=255 C=504 Bx=131064 sBx=-7
065: 0x00030005 GETGLOBAL A=0 B=0 C=12 Bx=12 sBx=-131059
066: 0x00064007 SETGLOBAL A=0 B=0 C=25 Bx=25 sBx=-131046
067: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
068: 0x00410006 GETTABLE A=0 B=0 C=260 Bx=260 sBx=-130811
069: 0x00068045 GETGLOBAL A=1 B=0 C=26 Bx=26 sBx=-131045
070: 0x00C6C046 GETTABLE A=1 B=1 C=283 Bx=795 sBx=-130276
071: 0x00014081 LOADK A=2 B=0 C=5 Bx=5 sBx=-131066
072: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
073: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
074: 0x00470006 GETTABLE A=0 B=0 C=284 Bx=284 sBx=-130787
075: 0x00060041 LOADK A=1 B=0 C=24 Bx=24 sBx=-131047
076: 0x0100401C CALL A=0 B=2 C=1 Bx=1025 sBx=-130046
077: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
078: 0x00474006 GETTABLE A=0 B=0 C=285 Bx=285 sBx=-130786
079: 0x00060041 LOADK A=1 B=0 C=24 Bx=24 sBx=-131047
080: 0x0100801C CALL A=0 B=2 C=2 Bx=1026 sBx=-130045
081: 0x00030045 GETGLOBAL A=1 B=0 C=12 Bx=12 sBx=-131059
082: 0x00004017 EQ A=0 B=0 C=1 Bx=1 sBx=-131070
083: 0x80008016 JMP A=0 B=256 C=2 Bx=131074 sBx=3
084: 0x0001C005 GETGLOBAL A=0 B=0 C=7 Bx=7 sBx=-131064
085: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
086: 0x7FFD4016 JMP A=0 B=255 C=501 Bx=131061 sBx=-10
087: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
088: 0x00438006 GETTABLE A=0 B=0 C=270 Bx=270 sBx=-130801
089: 0x00060041 LOADK A=1 B=0 C=24 Bx=24 sBx=-131047
090: 0x00040085 GETGLOBAL A=2 B=0 C=16 Bx=16 sBx=-131055
091: 0x01478086 GETTABLE A=2 B=2 C=286 Bx=1310 sBx=-129761
092: 0x000480C5 GETGLOBAL A=3 B=0 C=18 Bx=18 sBx=-131053
093: 0x01C4C0C6 GETTABLE A=3 B=3 C=275 Bx=1811 sBx=-129260
094: 0x0200401C CALL A=0 B=4 C=1 Bx=2049 sBx=-129022
095: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
096: 0x00410006 GETTABLE A=0 B=0 C=260 Bx=260 sBx=-130811
097: 0x00014041 LOADK A=1 B=0 C=5 Bx=5 sBx=-131066
098: 0x00020081 LOADK A=2 B=0 C=8 Bx=8 sBx=-131063
099: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
100: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
101: 0x0047C006 GETTABLE A=0 B=0 C=287 Bx=287 sBx=-130784
102: 0x00080041 LOADK A=1 B=0 C=32 Bx=32 sBx=-131039
103: 0x00084081 LOADK A=2 B=0 C=33 Bx=33 sBx=-131038
104: 0x000880C1 LOADK A=3 B=0 C=34 Bx=34 sBx=-131037
105: 0x0200401C CALL A=0 B=4 C=1 Bx=2049 sBx=-129022
106: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
107: 0x00004041 LOADK A=1 B=0 C=1 Bx=1 sBx=-131070
108: 0x0008C081 LOADK A=2 B=0 C=35 Bx=35 sBx=-131036
109: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
110: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
111: 0x00490006 GETTABLE A=0 B=0 C=292 Bx=292 sBx=-130779
112: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
113: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
114: 0x00494006 GETTABLE A=0 B=0 C=293 Bx=293 sBx=-130778
115: 0x00098041 LOADK A=1 B=0 C=38 Bx=38 sBx=-131033
116: 0x0100801C CALL A=0 B=2 C=2 Bx=1026 sBx=-130045
117: 0x00030045 GETGLOBAL A=1 B=0 C=12 Bx=12 sBx=-131059
118: 0x00004017 EQ A=0 B=0 C=1 Bx=1 sBx=-131070
119: 0x80008016 JMP A=0 B=256 C=2 Bx=131074 sBx=3
120: 0x0001C005 GETGLOBAL A=0 B=0 C=7 Bx=7 sBx=-131064
121: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
122: 0x7FFD4016 JMP A=0 B=255 C=501 Bx=131061 sBx=-10
123: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
124: 0x00458006 GETTABLE A=0 B=0 C=278 Bx=278 sBx=-130793
125: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
126: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
127: 0x0045C006 GETTABLE A=0 B=0 C=279 Bx=279 sBx=-130792
128: 0x00098041 LOADK A=1 B=0 C=38 Bx=38 sBx=-131033
129: 0x0100401C CALL A=0 B=2 C=1 Bx=1025 sBx=-130046
130: 0x00064005 GETGLOBAL A=0 B=0 C=25 Bx=25 sBx=-131046
131: 0x00030045 GETGLOBAL A=1 B=0 C=12 Bx=12 sBx=-131059
132: 0x00004017 EQ A=0 B=0 C=1 Bx=1 sBx=-131070
133: 0x80008016 JMP A=0 B=256 C=2 Bx=131074 sBx=3
134: 0x0001C005 GETGLOBAL A=0 B=0 C=7 Bx=7 sBx=-131064
135: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
136: 0x7FFE0016 JMP A=0 B=255 C=504 Bx=131064 sBx=-7
137: 0x00030005 GETGLOBAL A=0 B=0 C=12 Bx=12 sBx=-131059
138: 0x00064007 SETGLOBAL A=0 B=0 C=25 Bx=25 sBx=-131046
139: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
140: 0x00438006 GETTABLE A=0 B=0 C=270 Bx=270 sBx=-130801
141: 0x0003C041 LOADK A=1 B=0 C=15 Bx=15 sBx=-131056
142: 0x00040085 GETGLOBAL A=2 B=0 C=16 Bx=16 sBx=-131055
143: 0x01444086 GETTABLE A=2 B=2 C=273 Bx=1297 sBx=-129774
144: 0x000480C5 GETGLOBAL A=3 B=0 C=18 Bx=18 sBx=-131053
145: 0x01C9C0C6 GETTABLE A=3 B=3 C=295 Bx=1831 sBx=-129240
146: 0x0200401C CALL A=0 B=4 C=1 Bx=2049 sBx=-129022
147: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
148: 0x00004041 LOADK A=1 B=0 C=1 Bx=1 sBx=-131070
149: 0x00028081 LOADK A=2 B=0 C=10 Bx=10 sBx=-131061
150: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
151: 0x0000C005 GETGLOBAL A=0 B=0 C=3 Bx=3 sBx=-131068
152: 0x00410006 GETTABLE A=0 B=0 C=260 Bx=260 sBx=-130811
153: 0x00068045 GETGLOBAL A=1 B=0 C=26 Bx=26 sBx=-131045
154: 0x00CA0046 GETTABLE A=1 B=1 C=296 Bx=808 sBx=-130263
155: 0x00014081 LOADK A=2 B=0 C=5 Bx=5 sBx=-131066
156: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
157: 0x0080001E RETURN A=0 B=1 C=0 Bx=512 sBx=-130559
```

### nested proto7 Lua line `223..273`（78 opcodes）

常數：

```text
000: 'Tutorial'
001: 'SetCheckPointStatus'
002: 10016.0
003: 'CHECKPOINT_CATEGORY'
004: 'NPC'
005: 'CHECKPOINT_STATUS'
006: 'ST_CLOSE'
007: 'yield'
008: 'SetControlStatus'
009: 10.0
010: 'TRUE'
011: 't_executeCoFunction'
012: 'Tutorial_Part1'
013: 't_isCoroutineAlive'
014: 'GetControlStatus'
015: 0.0
016: 'FALSE'
017: 'StopCutScene'
018: 't_removeCoroutine'
019: 1.0
020: 'TUTORIAL_POINT'
021: 2.0
022: 3.0
023: 'DeleteObject'
024: 240.0
025: 'Tutorial_Part2'
```

原始 opcode：

```text
000: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
001: 0x00404006 GETTABLE A=0 B=0 C=257 Bx=257 sBx=-130814
002: 0x00008041 LOADK A=1 B=0 C=2 Bx=2 sBx=-131069
003: 0x0000C085 GETGLOBAL A=2 B=0 C=3 Bx=3 sBx=-131068
004: 0x01410086 GETTABLE A=2 B=2 C=260 Bx=1284 sBx=-129787
005: 0x000140C5 GETGLOBAL A=3 B=0 C=5 Bx=5 sBx=-131066
006: 0x01C180C6 GETTABLE A=3 B=3 C=262 Bx=1798 sBx=-129273
007: 0x0200401C CALL A=0 B=4 C=1 Bx=2049 sBx=-129022
008: 0x0001C005 GETGLOBAL A=0 B=0 C=7 Bx=7 sBx=-131064
009: 0x0080401C CALL A=0 B=1 C=1 Bx=513 sBx=-130558
010: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
011: 0x00420006 GETTABLE A=0 B=0 C=264 Bx=264 sBx=-130807
012: 0x00024041 LOADK A=1 B=0 C=9 Bx=9 sBx=-131062
013: 0x00028085 GETGLOBAL A=2 B=0 C=10 Bx=10 sBx=-131061
014: 0x0180401C CALL A=0 B=3 C=1 Bx=1537 sBx=-129534
015: 0x0002C005 GETGLOBAL A=0 B=0 C=11 Bx=11 sBx=-131060
016: 0x00030045 GETGLOBAL A=1 B=0 C=12 Bx=12 sBx=-131059
017: 0x0100801C CALL A=0 B=2 C=2 Bx=1026 sBx=-130045
018: 0x00034045 GETGLOBAL A=1 B=0 C=13 Bx=13 sBx=-131058
019: 0x00000080 MOVE A=2 B=0 C=0 Bx=0 sBx=-131071
020: 0x0100805C CALL A=1 B=2 C=2 Bx=1026 sBx=-130045
021: 0x0000005A TEST A=1 B=0 C=0 Bx=0 sBx=-131071
022: 0x80058016 JMP A=0 B=256 C=22 Bx=131094 sBx=23
023: 0x00000045 GETGLOBAL A=1 B=0 C=0 Bx=0 sBx=-131071
024: 0x00C38046 GETTABLE A=1 B=1 C=270 Bx=782 sBx=-130289
025: 0x0003C081 LOADK A=2 B=0 C=15 Bx=15 sBx=-131056
026: 0x0100805C CALL A=1 B=2 C=2 Bx=1026 sBx=-130045
027: 0x00040085 GETGLOBAL A=2 B=0 C=16 Bx=16 sBx=-131055
028: 0x00808057 EQ A=1 B=1 C=2 Bx=514 sBx=-130557
029: 0x80030016 JMP A=0 B=256 C=12 Bx=131084 sBx=13
030: 0x00000045 GETGLOBAL A=1 B=0 C=0 Bx=0 sBx=-131071
031: 0x00C20046 GETTABLE A=1 B=1 C=264 Bx=776 sBx=-130295
032: 0x0003C081 LOADK A=2 B=0 C=15 Bx=15 sBx=-131056
033: 0x000400C5 GETGLOBAL A=3 B=0 C=16 Bx=16 sBx=-131055
034: 0x0180405C CALL A=1 B=3 C=1 Bx=1537 sBx=-129534
035: 0x00000045 GETGLOBAL A=1 B=0 C=0 Bx=0 sBx=-131071
036: 0x00C44046 GETTABLE A=1 B=1 C=273 Bx=785 sBx=-130286
037: 0x0080405C CALL A=1 B=1 C=1 Bx=513 sBx=-130558
038: 0x00048045 GETGLOBAL A=1 B=0 C=18 Bx=18 sBx=-131053
039: 0x00000080 MOVE A=2 B=0 C=0 Bx=0 sBx=-131071
040: 0x0100405C CALL A=1 B=2 C=1 Bx=1025 sBx=-130046
041: 0x00000003 LOADNIL A=0 B=0 C=0 Bx=0 sBx=-131071
042: 0x80008016 JMP A=0 B=256 C=2 Bx=131074 sBx=3
043: 0x0001C045 GETGLOBAL A=1 B=0 C=7 Bx=7 sBx=-131064
044: 0x0080405C CALL A=1 B=1 C=1 Bx=513 sBx=-130558
045: 0x7FF8C016 JMP A=0 B=255 C=483 Bx=131043 sBx=-28
046: 0x00000003 LOADNIL A=0 B=0 C=0 Bx=0 sBx=-131071
047: 0x00000045 GETGLOBAL A=1 B=0 C=0 Bx=0 sBx=-131071
048: 0x00C04046 GETTABLE A=1 B=1 C=257 Bx=769 sBx=-130302
049: 0x0004C081 LOADK A=2 B=0 C=19 Bx=19 sBx=-131052
050: 0x0000C0C5 GETGLOBAL A=3 B=0 C=3 Bx=3 sBx=-131068
051: 0x01C500C6 GETTABLE A=3 B=3 C=276 Bx=1812 sBx=-129259
052: 0x00014105 GETGLOBAL A=4 B=0 C=5 Bx=5 sBx=-131066
053: 0x02418106 GETTABLE A=4 B=4 C=262 Bx=2310 sBx=-128761
054: 0x0200405C CALL A=1 B=4 C=1 Bx=2049 sBx=-129022
055: 0x00000045 GETGLOBAL A=1 B=0 C=0 Bx=0 sBx=-131071
056: 0x00C04046 GETTABLE A=1 B=1 C=257 Bx=769 sBx=-130302
057: 0x00054081 LOADK A=2 B=0 C=21 Bx=21 sBx=-131050
058: 0x0000C0C5 GETGLOBAL A=3 B=0 C=3 Bx=3 sBx=-131068
059: 0x01C500C6 GETTABLE A=3 B=3 C=276 Bx=1812 sBx=-129259
060: 0x00014105 GETGLOBAL A=4 B=0 C=5 Bx=5 sBx=-131066
061: 0x02418106 GETTABLE A=4 B=4 C=262 Bx=2310 sBx=-128761
062: 0x0200405C CALL A=1 B=4 C=1 Bx=2049 sBx=-129022
063: 0x00000045 GETGLOBAL A=1 B=0 C=0 Bx=0 sBx=-131071
064: 0x00C04046 GETTABLE A=1 B=1 C=257 Bx=769 sBx=-130302
065: 0x00058081 LOADK A=2 B=0 C=22 Bx=22 sBx=-131049
066: 0x0000C0C5 GETGLOBAL A=3 B=0 C=3 Bx=3 sBx=-131068
067: 0x01C500C6 GETTABLE A=3 B=3 C=276 Bx=1812 sBx=-129259
068: 0x00014105 GETGLOBAL A=4 B=0 C=5 Bx=5 sBx=-131066
069: 0x02418106 GETTABLE A=4 B=4 C=262 Bx=2310 sBx=-128761
070: 0x0200405C CALL A=1 B=4 C=1 Bx=2049 sBx=-129022
071: 0x00000045 GETGLOBAL A=1 B=0 C=0 Bx=0 sBx=-131071
072: 0x00C5C046 GETTABLE A=1 B=1 C=279 Bx=791 sBx=-130280
073: 0x00060081 LOADK A=2 B=0 C=24 Bx=24 sBx=-131047
074: 0x0100405C CALL A=1 B=2 C=1 Bx=1025 sBx=-130046
075: 0x00064045 GETGLOBAL A=1 B=0 C=25 Bx=25 sBx=-131046
076: 0x0080405C CALL A=1 B=1 C=1 Bx=513 sBx=-130558
077: 0x0080001E RETURN A=0 B=1 C=0 Bx=512 sBx=-130559
```

### nested proto8 Lua line `274..276`（4 opcodes）

常數：

```text
000: 't_executeCoFunction'
001: 'TutorialMain'
```

原始 opcode：

```text
000: 0x00000005 GETGLOBAL A=0 B=0 C=0 Bx=0 sBx=-131071
001: 0x00004045 GETGLOBAL A=1 B=0 C=1 Bx=1 sBx=-131070
002: 0x0100401C CALL A=0 B=2 C=1 Bx=1025 sBx=-130046
003: 0x0080001E RETURN A=0 B=1 C=0 Bx=512 sBx=-130559
```
