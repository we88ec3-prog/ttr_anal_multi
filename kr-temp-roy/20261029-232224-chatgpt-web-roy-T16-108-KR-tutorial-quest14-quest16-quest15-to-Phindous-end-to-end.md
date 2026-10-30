# T16-108 — KR 教學 → Quest 14 → Quest 16 → Quest 15 → 馮德斯村：端到端大型專題（BIN-first，五子問題）

- 作業者 `chatgpt-web roy`，時區 Asia/Taipei，研究日期：2026-10-29T23:22:24+08:00
- **主要證據原件**：`/mnt/data/Tartaros.bin` 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。`Tartaros.exe` 2,594,816 bytes，SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；`Event.stp` 11,241,597 bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。**本次直接重新計算上述三個本地 SHA。**
- `Event.stp` 中 `Event/SceneList.xml` 本次再次按原生 `EX` v1 演算法解壓，158,269 bytes，SHA256 `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25`，有 1,687 個 SCENE 節點。`TutorialMain.lua` 是 Lua 5.1 binary chunk，本次從 STP 解 XOR 原位元組，按 chunk 格式解析 instructions/constant table，SHA256 `662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809`。
- `Table/QuestInfo.xml` 原文**透過 GitHub connector 的 `main` 內容端點讀得**，路徑 `kr/evidence/5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60.txt`，Git blob `1c86c9ce4f2422f84269ed9eb641202fedb9fb63`。XML 路徑中的 SHA 是既有來源識別，此次**沒有將整份 2.3MB XML 拉到本地獨立重新算 hash**；因此逐行 XML 主張標記「GitHub 文件原文已讀」，非「本地 XML hash 重算」。QuestTalk 來自 `kr/evidence/b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28.txt`，已由 connector 查核全文 4,322 個 Quest 元素。
- PE：ImageBase `0x400000`；`.text` VA `0x401000` raw `0x400`，`.rdata` VA `0xBD2000` raw `0x7D0600`；本稿 `.text` `raw=VA-0x400C00`；其餘節另按 PE mapping，**不可套用 `.text` 常數做 .rdata raw**。全部 bounded ASM 由本次實際 BIN 以 GNU `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 解碼。這是靜態、唯讀、未執行/附加遊戲、未擷取真實網路封包、未修改 Server/Client。
- 研究治理快照（本次沿用同對話前輪已核對）：`main=43c51f579cada3aa6257eb8467f65af281c3585b`，`t16/roy/chatgpt-web=6723fd0b0da2b870812450ee424574e96c10555b`，`main...T16` ahead 22/behind 0；T16 T01 43 筆 `READY_FOR_REVIEW`（不是 `RESOLVED`），T16 收件箱無新項。**沒有建立 Commit/Push，也沒有 RR 認領**。RR-0005 實際 owner 是 T02 且問題為登入結果→Connect slot/port；本段依使用者更正明確採 **T16-108 教學至村莊專題**，不把它冒稱 RR-0005 交付、SUBMITTED 或 ACCEPTED。

## 摘要：已查明的任務與確定性

**QuestInfo.xml 的原始資源條件宣告清楚構成：`Quest 14 → Quest 16 → Quest 15`。** 其中 Quest16 `<Demands><Demand id="14"/></Demands>`；Quest15 `<Demand id="16"/>`。這是資源**宣告的前置圖**，不是原版 Server 實際驗收／發包已確認。先前「尚未讀到 QuestInfo 15/16」的歷史缺口於**本次**透過 GitHub 原文取得而更新；原稿保留作歷史，不擅改原稿或 T01 狀態。

此外 `TutorialMain.lua` Part2 以原生 bytecode **實際呼叫 `Tutorial.RequestStartScenario(14)`，並 loop `Tutorial.IsScenarioEnded(14)`**。`14` 在此首先是腳本傳入的 scenario selector，不能直接與 `QuestInfo id=14` 或 server wire opcode 合併成同一 namespace，儘管它們需要跨證據查明。

**Quest 15 的 `Event/SceneList.xml`** 有 sceneIdx `1 Square_Tutorial01`、`2 scenario_tuto1_1`、`3 pindos_talkevent`、`4 scenario_tuto2_1`；STP 的原文 `pindos_talkevent` 腳本確實 `LoadMap("town001D.map")`、呼叫 `OpenTalkScene`、`DoProlog(1)`。這是進入馮德斯村的**原始本地事件劇本與地圖資源線索**，**不是 Server 已下發正式場景/地圖封包、世界 scene object 已安裝或角色真正抵達**的證明。

### 端到端地圖：每條箭頭分級

```text
[Client TutorialMain/Tutorial_EntryPoint]         原生 Lua / 原生載入已證
  ├─ Part1: keyboard/mouse/camera/leader/NPC checkpoint 與 Scene(1000,1..)
  └─ Part2: RequestStartScenario(14) -> IsScenarioEnded(14) (輪詢)
                  │ C2S msg 0x0040 local builder + sender 有界可證
                  ▼
     [Scenario 14 回覆/成功判定]               actual S2C/勝利判定未知
                  │ 需要跨 T14/T07 的結算／返回
                  ▼
  [QuestInfo id=14 教學-伊希莉亞]              XML 原生存在；completion wire unknown
                  │ XML Demand 14（是 16 的前置宣告）
                  ▼
  [QuestInfo id=16 教學-平可爸爸]            town=0, giver/finisher=10027
                  │ XML Demand 16（是 15 的前置宣告）
                  ▼
  [QuestInfo id=15 前往馮德斯村]             town=5 field=19 giver/finisher=10338
                  │ Quest15 SceneList 1,2,3,4 (本地場景表)
                  ├─ Square03D.fld (scenes 1/2)
                  └─ scene 3 script: LoadMap("town001D.map") → DoProlog(1)
                  ▼
      [真正 server-directed 村莊 transition / loading / role spawn]
                      尚無業務回覆/Client state writer 閉環
```

## 子問題一：任務順序、角色/NPC、靜態條件的權威來源

**研究問題**：教學到村莊實際列有哪些 Quest ID，哪些只是 Event scene key；能否取得原件中的前置、NPC、zone、場景？

- **第 1 輪（source first / BIN 交叉）**：讀 `QuestInfo.xml` 的 `14/16/15` 原文、QuestTalk 全文，對照 BIN `0x504370→0x504740/0x505570` 的不同 loader。取得 14→16→15 的 `<Demands>` 宣告，不再僅從歷史研究計畫猜 ID。
- **第 2 輪（native reader/CFG/反證）**：原始 `0x5043E9 call 0x504740` 讀 `Table/QuestInfo.xml`（RDATA VA `0xC0DB48`）；`0x5043EF call 0x505570` 另讀 `Table/QuestTalk.xml`（`0xC0DB5C`）。兩者並列不同 loader；`QuestTalk` 全文**查無 id=14、15、16**，這只代表對話映射未列，**不是**這三項 Quest 不存在。`0x5043B5→0x504522` 分配失敗邊界與各 loader `0x5047C6/0x5055E7` load result gate 均存在。
- **第 3 輪：未啟動**，因 XML 原件、BIN 兩讀入函式與 absence 反證形成可驗證界線；完整 Server 接取判定並非可以由 XML 唯讀直接得出。

| 任務 | 韓文 subject（來源原文） | 其它 XML 原欄位 | 前置 XML | 要分析的 Client 節點 | 相容 Server 開發工作（不是官方算法） |
|---|---|---|---|---|---|
| **Quest 14** | `튜토리얼-이실리아`（教學－伊希莉亞） | `type=3, town=0, field=18, level=1, giver=10027, finisher=10027, subtype=1`；`CompleteAction type=1`, `AcceptAction type=1` | 無 `<Demands>` 子元素 | 教學觸發→quest 14 完成訊息；狀態是否與 scenario 14 共用；回應 handler、NPC UI | 保存角色任務狀態、教學完成事件與應答；**尚不能指定 wire id/格式或默認完成時機** |
| **Quest 16** | `튜토리얼-핑코파파`（教學－平可爸爸） | `type=2, town=0, level=1, giver=10027, finisher=10027, subtype=1`，`RewardsEtc id=16`：`Reward type=2 value=50`（type 的具體業務意義未知） | `<Demand id="14"/>` | 14→16 變可接的實際 S2C，NPC 10027 的接取/交付 C2S，Client 狀態/UI 更新 | 前置 gate、接取/完成/交付流程、狀態回覆與資源中獎勵字段映射；wire/持久化待設計和補證 |
| **Quest 15** | `핀더스 마을로`（前往馮德斯村） | `type=2, town=5, field=19, level=1, giver=10338, finisher=10338, subtype=1`；`RewardsEtc id=15`：`Reward type=2 value=2800` 與 `type=4 value=468`（不擅認貨幣/EXP） | `<Demand id="16"/>` | 可接清單 UI→10338→接取/完成回覆；SceneList 雙鍵與村莊安裝/ready | Quest15 前置檢查、NPC 提示/接取/轉場協調、村莊可用性及角色狀態保存；先由 T02/T07/T16 確認 S2C 才固化封包 |

原始 QuestInfo 擷取（保留原欄位，非人工補全）：

```xml
<Quest id="14" type="3" town="0" field="18" level="1" giver="10027" finisher="10027" subtype="1" subject="튜토리얼-이실리아">
  <CompleteAction type="1" />
  <AcceptAction type="1" />
</Quest>
<Quest id="16" type="2" town="0" level="1" giver="10027" finisher="10027" subtype="1" subject="튜토리얼-핑코파파">
  <Demands><Demand id="14" /></Demands>
  <RewardsEtc id="16"><Reward type="2" value="50" /></RewardsEtc>
</Quest>
<Quest id="15" type="2" town="5" field="19" level="1" giver="10338" finisher="10338" subtype="1" subject="핀더스 마을로">
  <Demands><Demand id="16" /></Demands>
  <RewardsEtc id="15"><Reward type="2" value="2800" /><Reward type="4" value="468" /></RewardsEtc>
</Quest>
```

**證據邊界**：`level=1` 等欄位是配置，非 Server 現行守門條件。`town=5` 在 QuestInfo、`town001D.map` 在 Event script，**缺一條原生映射指令**可證兩個識別域完全同義；它們只應按玩家流程聯合驗證。

## 子問題二：真正的教學步驟 → scenario 14 C→S，原生腳本 CFG

**研究問題**：進入教學後做哪些明確的本地操作；是否真的呼叫 scenario14；其 call 到 native send 何處為止？

- **第 1 輪（原始 Lua bytecode + Event 原文）**：從 STP 取 `Event/TutorialMain.lua`、解析 Lua 5.1 header/常數與各 nested Proto；`Tutorial_Part1`（line 48–124）處理鍵盤、滑鼠、鏡頭、領隊切換、前往 NPC 等；`Tutorial_Part2`（line 131–199）的確依序 `PlayAndWaitForScene(1000,8)`、`Tutorial.RequestStartScenario(14)`、`Tutorial.IsScenarioEnded(14)` 輪詢，後續 `PlayAndWaitForScene(1000,10/12/13/14)`、兩輪角色操作 UI/等待、NPC 10016 checkpoint。**Lua 中的 scene1000/14 不是 QuestInfo id14**。
- **第 2 輪（native callback writer/caller/callee）**：`0x4AB8B8 mov [0xFE187C],0x4AA4D0`，`0x4AB909 push 0x4AC9E0; call 0x6F55B0` 完成 Lua bridge 的註冊入口；`0x4ACB27/0x4ACB61` 經 `call [ebp-0x18]` 間接執行 native writer（型別/失敗分支見下方 ASM）；`0x4AA4D0` 設 `word=0x40` 與另一 WORD 參數，`[0xFBA798]==0` 時呼叫 `[0xFBA854] vtable+0x10`（packet queue 及 WSASend transport 已在 T16-107/T02 局部連接）。這是**有條件的 Client 發送 interface**，不是已證所有遊玩條件必定發出完整封包。
- **第 3 輪（loop/timeout/failure/反證）**：Lua Part2 在 `IsScenarioEnded(14)` 不等於 `FALSE` 前以 `yield` 循環；本地沒有確定超時/拒絕出口；之後 `g_TutoEmployCharQuery` 的兩組 wait 與 reset，可見 UI 控制屬本地協程。`RequestStartScenario(14)` 的字面 `14.0` 傳入橋接後實際可能轉 int；原始 Server 對端的 ACK、勝利條件及回到 TUTO 的確切時序均不可由這段 Lua 推出。

新手教學本地子步驟（是 **Lua 狀態節點**，不是另外的 Server Quest）：

| 區段 | 原生 Lua 可見行為 | Client 需補證 | Server 可能需要提供的相容接口 |
|---|---|---|---|
| 初始／鏡頭 | `PlayAndWaitForScene(1000,1)`；`Event/SceneList.xml` 有 `1001/1=tutorial_start`，但兩者不是相同 pair | 第一次進入 Tutorial 的 gate、真正 `(questIdx,sceneIdx)` 預設值與 script loader | 首登場景選擇/恢復狀態（完整 S2C 尚未知） |
| 鍵盤／滑鼠 | `InsertTutorialCheckPoint(1/2)`、`GetControlStatus`、`SetCheckPointStatus`、`yield` | checkpoint writer、UI trigger 與是否需要送包 | 僅在 Client 要求權威回覆的操作上實作；不把所有 checkpoint 都做成虛構封包 |
| 鏡頭／領隊／NPC | `IsIsiliaFound`、`CheckLeader`、`IsLeaderDialogOpened`、`TUTORIAL_GOTO_NPC` | NPC 10027／10016 身分對照，關閉點/下一階段 | NPC 接取/交付與是否由 server 介入，需先證 wire |
| Scenario 14 | `RequestStartScenario(14)` → `IsScenarioEnded(14)` loop | local 0x40 參數/實際 socket、S2C completed writer | 任務關卡啟動/退出、結果回傳及 Quest14 更新；勝負由新 Server 自訂，但要滿足原 Client 契約 |
| Part2 後半 | `PostUIMessage_EmployChar(4)`、`(2)`、`g_TutoEmployCharQuery` 等待；`PlayAndWaitForScene(1000,13/14)` | UI 事件何時解除 wait，場景是否等待 Server ACK | 角色新手流程狀態維護、重登恢復，不預填 NPC/quest 收發 |

有界偽碼（省略未驗證的 Lua 插入/註冊與異常）：

```lua
-- directly based on proto index 5; scenario 14 numeric namespace retained
PlayAndWaitForScene(1000, 8)
Tutorial.PostUIMessage_TutoMsg(0, 6)
yield()
Tutorial.PostUIMessage_TutoMsg(0, 1)
Tutorial.RequestStartScenario(14)
while Tutorial.IsScenarioEnded(14) == FALSE do yield() end
Tutorial.SetUIPage()
Tutorial.SetCheckPointStatus(10016, CHECKPOINT_CATEGORY.NPC, CHECKPOINT_STATUS.ST_CLOSE)
-- scenes 1000/10, 1000/12, 1000/13, 1000/14 and UI waits follow
```

**反證**：`PlayAndWaitForScene(1000,14)` 的 `1000` 為 scene domain，不能被誤當 Quest14；`IsScenarioEnded` 是本地狀態查詢，不等同 Server 已發勝利回覆或完成 Quest14。

## 子問題三：結果通知、Quest 狀態、NPC/UI 消費者與 Server 權威缺口

**研究問題**：收到什麼才讓 Quest14 完成，Quest16 可接、完成，再讓 Quest15 可接？是否能證實實際的 S2C opcode、容器 writer 與結果？

- **第 1 輪（transport → application 靜態界線）**：複核 `0x804740` queue pop→CClient `0x4930E0`，後者在非零長度與 channel==2 時由 payload[0:2] 取 WORD 命令，再向 `[CClient+0xB8]` 場景 vtable+4 呼叫；`0x4C4670` 先查 `[scene+0x5EAC+8*index]` 個別表 B，null 才 `0x4FDA30` 回退 `[scene+4+8*index]` 表 A。這是**通用接收分派路徑**，尚無一個收到的 Quest14/16/15 專屬 S2C 回覆可以與之配對。
- **第 2 輪（看似 Quest 但其實 XML 解析的反證）**：`0x53FD80..0x53FDF2` 把 `HasQuest/HasCompletableQuest/HasScenario` 交 XML parser `0x72E2E0`，條件式 `0x53FEB0` 輸入至本地記錄；它**不是**直接伺服器任務完成 writer 的證據。`0x5043E9/EF` 讀取靜態 QuestInfo/QuestTalk 也不是角色持久化狀態寫入。
- **第 3 輪（具體停界）**：查明此次原始 BIN 沒有可由現有來源直接閉合的 `scenario14 success ACK → Quest14 complete → Quest16 available/complete → Quest15 available` 完整回應簽名；只能將已證「通用路由」與未證「業務 handler」分開。**不能以尚未找到配對就推斷遊戲沒有此訊息**；仍缺原版動態封包、已驗證 opcode table / handler writer / T14 結算。真正 Server decision 屬設計，**但 Client wire 缺口仍是 T16 待逆向**。

最低可做的 Server-side 狀態模型（**明確為相容實作設計候選，非原版協定**）：

```text
(roleId, tutorialPhase, scenario14Session/result,
 quest14:{available,accepted,completed,turnedIn},
 quest16:{available,accepted,completed,turnedIn},
 quest15:{available,accepted,completed,turnedIn},
 sceneKey, townKey)
```

- 前置評估可用 Quest XML Demand 宣告設計，但 Server 何時發給 Client、任務是 auto-accept 還是 NPC 對話後 accept 尚不明；先寫成 DRAFT interface/GAP，不作真實封包 schema。
- 必須具備 Server-side role scope、冪等接取/交付、重登重傳 snapshot、錯誤/拒絕處理；這些是**開發建議**，不代表原版 Server 已驗證使用同樣的欄位或資料表。
- 要補的 Client：每個 Quest 的 request builder／reply handler／cache writer／NPC badge/UI 變化；尤其 `+0xB4/+0xB5` 旗標與 Quest UI 的實際別名關係未完全證明。

## 子問題四：Quest15 NPC 接取、對話和本地 Event scene 雙鍵圖

**研究問題**：Quest16 完成後如何使 Quest15 可接，玩家操作後有哪些本地腳本與網路接口？

- **第 1 輪（完整原件 SceneList）**：Event.stp 的 EX v1 原生解碼，得 `Quest15` sceneIdx 1,2,3,4 的 funcName。`questIdx=15` 是 **Event/SceneList.xml 的 namespace**，與 `QuestInfo id=15` 數值相同，但從 `QuestInfo` 到 Event script 的觸發 edge 尚未證實。
- **第 2 輪（native reader 到 script）**：`0x560815` 原 BIN 引用 `Event/SceneList.xml`；`0x5608D9 / 0x560911 / 0x56093D` 分別訪問 `questIdx/sceneIdx/funcName`，再 `0x568950` 節點建立與 `0x568680` 雙鍵插入。`0x561A1C`、`0x5658D0` 為兩組查找/建立 `Event/Sequences/<funcName>.seq` 的讀取端（E13/E16），`0x565720` 於執行中還可能由 `EndCutScene` 二次調用；不保證首次登入就調它。
- **第 3 輪（對話 UI 與發送候選、排除）**：T16-107 的 `0x636520→0x500F90→[dialog+0x88]` 與 `0x636DE0/0x636E10` 選中記錄 → local `36 00 XX XX` → `CIocpNetwork` v+0x10 → queue → framing → WSASend 已有有界通用證據；然而 `0x36`**尚未配對到 Quest15 NPC 10338 的「接取」動作**，該值來自對話選擇紀錄 first WORD，沒有來源證明它就是 Quest ID。`0x6A7` 是本地 event 值，不是 S2C/C2S 協定 ID。

Quest15 的四個實際可讀 Event scene（請勿把 scene list 的序列順序誤作執行時序）：

| SceneList `(15,sceneIdx)` | `funcName` | 原始 script 可見關鍵動作 | 尚須確認 |
|---|---|---|---|
| 1 | `Square_Tutorial01` | `LoadMap("Square03D.fld")`、建立 `10338` 物件、`OpenTalkScene(3,22)` | 何時初始化／是否由 Server 開場/任務接受驅動 |
| 2 | `scenario_tuto1_1` | `LoadMap("Square03D.fld")`、`OpenTalkScene(3,15/16/17/25)`、角色物件與鏡頭 | Scene pair selected by whose state? C→S/S→C pending |
| 3 | `pindos_talkevent` | **`LoadMap("town001D.map")`**、`OpenTalkScene(3,18/24/20/21)`、`DoProlog(1)`、`RestoreMap()` | 這是本地過場地圖；尚未證實真正村莊世界 scene/角色 spawn |
| 4 | `scenario_tuto2_1` | `LoadMap("")`、`RestoreMap()` | 空地圖字串不能推成進入村莊或 reset 命令 |

QuestInfo `id15 giver/finisher=10338` 與 Scene15/1 CreateObject 10338 **是兩份原始來源的相同數字對照**，構成良好的 NPC 身分候選，但不自動閉合該場景的事件觸發與 quest-accept wire。

## 子問題五：馮德斯村進場、scene install、reset/ready 與回收／失敗分支

**研究問題**：村莊進場究竟是本地 cutscene 讀取資源還是真正 Server 指示的世界場景切換？

- **第 1 輪（Event script/MapList 線索）**：Event.pindos scene3 確認本地 `town001D.map`；T06/T07 交接中 `MapList 182→town001D/BOUNDtown001` 有資源映射，但正常 Town1/Town2 的 server 指示/MapList 數值尚未完整驗證；`town=5` 是 QuestInfo 配置，**不可直接當 T07 map type 或 182**。
- **第 2 輪（native receive scene switch branch）**：`0x4B9090` 入口讀 input `+2` 的 signed BYTE，減 7 後用 byte table `0x4B924C` / jump table `0x4B9238` 分派 `type=7..24` 的多個場景構造/安裝路徑：部分呼叫 `0x4BBB70→0x4ADD50` 並裝 `0xC06FB0` vtable，再呼叫 `0x4B7D50` 安裝；部分設 `[CClient-like +0x69A8]` 常數 7、0x17、0x18。這可證**類別安裝候選路徑及按資料型別分流**，但沒有直接證明是哪個 type 對應真正 Town1，更不能把它等同 `town=5`。
- **第 3 輪（reset/ready/失敗分支與反證）**：`0x4B24F0` 看到 `0x4DF510` map selector helper，`0x4C5930` 僅 `jmp [vtable+0x2C]` 的 trampoline，非自帶 ready logic；`0x4BBB70` 建構 Scene subobject 時 `memset(scene+0x5EAC,0,0x5EA8)`、安裝本地 callback；不能因近接而認定它就是 town-ready handler。`0x4B9090` 的 `type` 越界會跳到 `0x4B922C`，allocation failed 有 null 分支，scene slot 安裝由 `0x4B7D50` 執行且有回收/舊 scene 清理待證。**尚無 Quest15 指定此 type/連線序列、玩家 spawn/ready 回覆及進村成功 state**。T07/T06 已提醒原版 `005F type6` 屬 `CDuelField` 且舊 fixture Tutorial patch 不能用來判定 Town。

Server 相容工作必須拆成：角色當前 scene/town 權威、符合 Client 既有 scene-type 的初始通知、進場/ready handshake、spawn/actor lifecycle、錯誤/重試及回城持久化。**具體封包 opcode/type/順序必須等 T07/T02/T16 補完，不能現在寫成官方規格**。

## 橫跨五題：按工作責任分類的分析與開發清單

| 玩家節點 | Client 待逆向（定位到具體最小阻塞） | Server 待開發（依已確認需求、wire 仍待證） | 跨 Task | 優先級 |
|---|---|---|---|---|
| 角色初登/教學啟動 | T03 `0x42` S2C 與 tutorial gate→ `Tutorial_EntryPoint`、`0x565720` pair writer | 角色 tutorialPhase、首次/重登選擇；避免固定認定 (1001,1) | T03/T04/T07 | P0 |
| 教學本地 checkpoints | Lua Part1 控制 gate；判定哪些操作實際發 C→S | 只對已證 Client 要求的操作回應，其他保留本地腳本 | T16/T08 | P1 |
| scenario 14 | `0x40` builder→framing→對應 S2C/handler/quest cache writer | 建立場次、接收成功/失敗、發相容回覆 | T02/T14/T07 | P0 |
| Quest14 | scenario結果→任務完成通知、Quest14 UI/dialog | Quest14 接取/完成/交付與持久化、失敗/重試 | T16/T15 | P0 |
| Quest16 | Demand14 反映至 NPC10027、接取 C2S→S2C→status | Quest16 解鎖、接受、完成、交付、角色 state | T16/T04/T15 | P0 |
| Quest15 | Demand16→NPC10338、`0x36` 是否有關、接受/拒絕 handler | Quest15 解鎖、NPC 互動與接受/完成回覆 | T16/T06/T15 | P0 |
| 村莊 cutscene/世界安裝 | `(15,3)` script→ scene vtable install、map id、ready、真正 spawn | 場景權威、town entrance、session ready/spawn/復原 | T07/T02/T08/T06 | P0 |

**最小相容 Server 階段性驗收（設計候選，不是現成已可玩）**：① 原 Client 成功啟動教學；② scenario14 的開始及有效結果回覆被 Client 接受；③ Quest14、16、15 依次出現合適的 UI／接取／完成狀態；④ NPC10338 可觸發 Quest15 事件；⑤ 原 Client 依真實 server scene message 建立馮德斯村場景並正確 ready/spawn；⑥ 中斷/重登不重複結算。**這 6 項目前沒有全部原生 wire/state writer 可供自動化 conformance**，不得把設計清單當已實現。

## 端到端缺口清單（按證據種別）

- **Client 待逆向**：`0x42` selection S2C → tutorial gate；`0x40` scenario14 的確定連線與回覆；Quest14/16/15 狀態 writer / NPC refresh / accept/turn-in C2S；SceneList pair `15/1..4` 的實際 selector/writer；T07 town type、socket/ready/spawn/回收、失敗路徑。
- **Server 待開發**：任務前置、接取/完成/交付、scenario14 結算、角色/關卡/場景權威、快照/持久化；需待確認 wire contract 後實作兼容 serializer/dispatcher。官方原 Server 規則不要求逆向，開發者若自行制定需在 S00 ADR 註明。
- **跨 Task 待整合**：T03 選角回覆；T02 transport；T07 town install；T14 關卡合法成功；T15 角色任務快照；T06 MapList／資源；T01 嚴格原生驗收/S00 契約整合。**不私自改其他主責**。
- **待遊玩驗證**：未在原版 Client 上執行，沒有原服 capture；靜態資源序列不能替代玩家可玩通關證明。

## 跨來源反證／歷史更正

1. 舊 T16-47/T16-64 說 Quest15/16 XML 原文尚未取得：當時成立；這次已經從 GitHub `main` 讀到兩筆與 Quest14，應記錄**時間限定的進度更新**，不是去改寫舊稿。
2. SceneList `(1001,1)` 記的是 `tutorial_start`，而 `TutorialMain.lua` Part1/2 使用 `(1000,x)`；不能把二者數值合併；它們都不是 QuestInfo `<Quest id>`。
3. QuestTalk 缺 id14/15/16 只否證「這三個 ID 在 QuestTalk 有同號 talk mapping」，不否證 QuestInfo、cutscene scene table。
4. `QuestInfo Demand` 表示**XML 的資料宣告**；原 Server 採用何種條件／順序／自動觸發、是否玩家必須逐一接取仍無確證。
5. `0x36` 的 payload second WORD 是 dialogue record first WORD，不是已證 Quest15 id；`0x40` 是 scenario request local buffer，而不是所有操作都有 wire code 0x40；`0x0BBB`/`0x1A68` 等 transport magic 不能當 Quest opcode。
6. `pindos_talkevent LoadMap("town001D.map")` 是**過場腳本**；若沒有 Server scene state/ready/實際角色 spawn，不能宣稱已進入馮德斯村。原版 `005F type6` 與先前修補 fixture Tutorial 必須隔離。

## 研究輪次總表與本段停止原因

| 子問題 | 實際深入輪次 | 有界結果 | 剩餘證據障礙 | 是否已處理至可驗證界線 |
|---|---|---|---|---|
| 1 Quest14→16→15 原件 | 2 | XML 兩條 Demand、兩 loader、QuestTalk negative | 原版 Server 權威行為 | 是：資源範圍閉合；Server 內規不虛構 |
| 2 Lua→scenario14 | 3 | Lua 5.1 proto CFG、native slot/writer/queue | S2C/實際 Server 結算 | 是：native producer 已有界，未冒稱回覆 |
| 3 Quest S2C state | 3 | 通用 route verified、假 writer 排除 | Quest 專用 handler + capture 未取得 | 是：停在有名且可繼續的 handler/writer 缺口 |
| 4 Quest15 UI/script | 3 | 4 個 Event scene/本地原文、UI send 候選 | scene selector 與 NPC accept wire | 是：原始 script 確定，觸發邊未證 |
| 5 Town 安裝/ready | 3 | scene switch branch、vtable/writer、trampoline 反證 | type→town、ready/spawn、真實 runtime | 是：有界原生通路已知但世界落地未閉合 |

**停止條件**不是「找到一個重大發現」：五題各自對已取得的原生與原始資源形成 bounded conclusion，對不能從現有靜態資料/現有分工獨立補足之點明列具體缺口；**整個端到端玩家流程尚未驗收完成**，且本稿不聲稱原始 Server 回覆已還原。正式段號只計 **T16-108**，不另立 108-2/-3。

## 可重現檢驗腳本與直接 callers 統計

```python
# 同 SHA 的 Tartaros.bin；只查 direct E8 rel32，不能排除間接/虛擬參照
import struct
from pathlib import Path
b=Path('Tartaros.bin').read_bytes(); base=0x400C00
for target in (0x504740,0x505570,0x5607D0,0x565720,0x636E10):
    hits=[i+base for i in range(0x400,0x7D0600-5) if b[i]==0xE8
          and i+base+5+struct.unpack_from('<i',b,i+1)[0]==target]
    print(hex(target),[hex(h) for h in hits])
# result: 504740←5043E9; 505570←5043EF; 5607D0←560344;
# 565720←47B64A/561EF3; 636E10←636E01.
```

Source URLs: `https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/kr/tasks/T16/README.md`; `https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/kr/evidence/5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60.txt`; `https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/kr/evidence/b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28.txt`；T16-107 local reference：`20261029-225956-chatgpt-web-roy-T16-107-KR-TalkBox-to-CIocpNetwork-queue-frame-and-selection-producer.md`；E06/E08/E13/E16：`kr-extra-roy/`；T07 town handoff：`shared/T07-TOWN-ENTRY-DEPENDENCY-HANDOFF.md`。GitHub 主張（舊筆記）和本次直接 BIN/static source 結論分離。

## 附錄 A — 原始 Event.stp 對應場景完整 source（檔案 byte 範圍、SHA256）

### tutorial_start — XOR decoded STP `[0xA1C010,0xA1C21A)`, 522 bytes, SHA256 `1fc158a28915b6f0047941cb8a5c00534aa81c5538d153f1f05b5b2ff012eedc`

```lua
-- TTEX Talk Scene File: DO NOT EDIT BY HAND
-- Quest #1001 / Scene #1 - Function tutorial_start
function tutorial_start()
	SetTransitionType(0)
	SetFinalMusic("")
	HideOriginalObjs(1)
	Phase1()

	LoadMap("town000D.map")
	MoveCamera(223.00, 140.00, 200.00)
	RotCamera(4.18, 1.06, 12.00)


	Phase2()
	Phase3()
	Phase4()

	PlayCamera("tutorial_00_1.cam", 0, 0.00, 0.00, 0.00)

	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(tutorial_start)
```

### Square_Tutorial01 — XOR decoded STP `[0x969410,0x9696A4)`, 660 bytes, SHA256 `fd645921073cedafe1410173d973aa62746ebca1a844832147e1e6df0a6c1852`

```lua
-- TTEX Talk Scene File: DO NOT EDIT BY HAND
-- Quest #15 / Scene #1 - Function Square_Tutorial01
function Square_Tutorial01()
	SetTransitionType(2)
	SetFinalMusic("")
	HideOriginalObjs(1)
	Phase1()

	LoadMap("Square03D.fld")
	MoveCamera(0.00, 0.00, 0.00)
	RotCamera(0.00, 1.57, 100.00)

	CreateObject(1, 10338, 869.00, 1052.00, 0, 0, FALSE, 0, 0)

	Phase2()
	Phase3()
	Phase4()

	PlayMusic("BGM040.ogg")
	PlayCameraNoWait("Square_Tutorial01_01.cam", 0, 0.00, 0.00, 0.00)
	wait(500)
	OpenTalkScene(3, 22)

	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(Square_Tutorial01)
```

### scenario_tuto1_1 — XOR decoded STP `[0x968810,0x968C4D)`, 1085 bytes, SHA256 `7150ff5686bf6ca8c81ff54faad1faf91578ba2a55e192c64f63a8853a50064f`

```lua
-- TTEX Talk Scene File: DO NOT EDIT BY HAND
-- Quest #15 / Scene #2 - Function scenario_tuto1_1
function scenario_tuto1_1()
	SetTransitionType(2)
	SetFinalMusic("")
	HideOriginalObjs(1)
	Phase1()

	LoadMap("Square03D.fld")
	MoveCamera(869.00, 1037.00, 171.80)
	RotCamera(0.70, 1.47, 30.00)

	CreateObject(0, 10338, 869.00, 1052.00, 0, 0, FALSE, 0, 0)
	CreateObject(1, 1478, 864.00, 1032.00, 128, 0, FALSE, 1, 1)
	CreateObject(2, 1479, 869.00, 1027.00, 128, 0, FALSE, 1, 10)
	CreateObject(3, 1480, 869.00, 1042.00, 0, 0, FALSE, 1, 19)
	CreateObject(4, 1481, 874.00, 1032.00, 128, 0, FALSE, 1, 28)

	Phase2()
	Phase3()
	Phase4()

	OpenTalkScene(3, 15)
	OpenTalkScene(3, 16)
	OpenTalkScene(3, 17)
	PlayCameraNoWait("scenario_tuto1_1.cam", 0, 0.00, 0.00, 0.00)
	WarpObject(3, 869.000000, 1038.000000, 0.000000, 0, 1, 1)
	FaceObject(2, 10, 0)
	RotateObject(1, 50, 1)
	RotateObject(4, 206, 1)
	wait(500)
	OpenTalkScene(3, 25)

	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(scenario_tuto1_1)
```

### pindos_talkevent — XOR decoded STP `[0x8C1C10,0x8C2274)`, 1636 bytes, SHA256 `79b563be567ef51cce081a8a843eede14962b3bea5bf8af8b69e65c73d0d1b7e`

```lua
-- TTEX Talk Scene File: DO NOT EDIT BY HAND
-- Quest #15 / Scene #3 - Function pindos_talkevent
function pindos_talkevent()
	SetTransitionType(2)
	SetFinalMusic("BGM003.ogg")
	HideOriginalObjs(1)
	Phase1()

	LoadMap("town001D.map")
	MoveCamera(755.00, 416.00, 57.75)
	RotCamera(5.67, 1.33, 55.00)

	CreateObject(0, 1478, 751.00, 416.00, 128, 0, FALSE, 1, 1)
	CreateObject(1, 1479, 760.00, 416.00, 128, 0, FALSE, 1, 10)
	CreateObject(2, 1480, 755.00, 429.00, 0, 0, FALSE, 1, 19)
	CreateObject(3, 1481, 755.00, 421.00, 128, 0, FALSE, 1, 28)
	CreateObject(4, 10047, 734.00, 744.00, 0, 0, FALSE, 0, 0)

	Phase2()
	Phase3()
	Phase4()

	PlayMusic("BGM003.ogg")
	PlayCameraNoWait("tutorial_01_18.cam", 0, 0.00, 0.00, 0.00)
	wait(2000)
	OpenTalkScene(3, 18)
	PlayCameraNoWait("tutorial_01_18b.cam", 0, 0.00, 0.00, 0.00)
	wait(1000)
	WalkObject(2, 755.000000, 439.000000, 0.000000, 1, 4, 3)
	wait(1500)
	AniObject(2, 2, 1)
	RotateObject(2, 0, 1)
	wait(1000)
	OpenTalkScene(3, 24)
	PlayCamera("tutorial_01_19.cam", 0, 0.00, 0.00, 0.00)
	OpenTalkScene(3, 20)
	PlayCameraNoWait("tutorial_01_20.cam", 0, 0.00, 0.00, 0.00)
	wait(500)
	OpenTalkScene(3, 21)
	PlayCamera("tutorial_01_22.cam", 0, 0.00, 0.00, 0.00)
	ClearObjects()
	PlayCameraNoWait("tutorial_01_21.cam", 0, 0.00, 0.00, 0.00)
	PlayMusic("BGM007.ogg")
	wait(3000)
	FlyingObject("Image/Prologue/Phindous00_1.dds", 50, 35, 100, 9999, 0, 0)
	wait(4000)
	DelFlyingObject()
	DoProlog(1)
	PlayMusic("BGM003.ogg")

	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(pindos_talkevent)
```

### scenario_tuto2_1 — XOR decoded STP `[0x969010,0x9691D6)`, 454 bytes, SHA256 `8d15efad87d4afa4b613675064367f0ed92bd25a5cd8ec2254a3eeade68c6fbb`

```lua
-- TTEX Talk Scene File: DO NOT EDIT BY HAND
-- Quest #15 / Scene #4 - Function scenario_tuto2_1
function scenario_tuto2_1()
	SetTransitionType(0)
	SetFinalMusic("")
	HideOriginalObjs(0)
	Phase1()

	LoadMap("")
	MoveCamera(0.00, 0.00, 0.00)
	RotCamera(0.00, 1.57, 100.00)


	Phase2()
	Phase3()
	Phase4()


	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(scenario_tuto2_1)
```

## 附錄 B — Lua 5.1 逐指令 / constant table：Part1、Part2、主程序（BIN/STP 原始 bytecode）

### nested proto 4: source lines 48–124; 197 instructions, 34 constants

常數索引：
```text
[0] 'Tutorial'
[1] 'PostUIMessage_TutoMsg'
[2] 0.0
[3] 1.0
[4] 'PlayAndWaitForScene'
[5] 1000.0
[6] 'ApplyDefaultCamera'
[7] 'TUTORIAL_PROGRESS_NUMBER'
[8] 'TUTORIAL_CHANGEKEYTYPE'
[9] 'GetTutorialState'
[10] 'FALSE'
[11] 'yield'
[12] 'TUTORIAL_KEYBOARD'
[13] 'InsertTutorialCheckPoint'
[14] 'GetControlStatus'
[15] 'SetCheckPointStatus'
[16] 'CHECKPOINT_CATEGORY'
[17] 'TUTORIAL_POINT'
[18] 'CHECKPOINT_STATUS'
[19] 'ST_CLOSE'
[20] 3.0
[21] 'TUTORIAL_MOUSE'
[22] 2.0
[23] 4.0
[24] 'TUTORIAL_CAMERA'
[25] 'InsertIsilia'
[26] 'IsIsiliaFound'
[27] 6.0
[28] 'TUTORIAL_LEADER_CHANGE'
[29] 'CheckLeader'
[30] 'IsLeaderDialogOpened'
[31] 'TUTORIAL_LC_DLG_OPENED'
[32] 7.0
[33] 'TUTORIAL_GOTO_NPC'
```

```text
000 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
001 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
002 LOADK        A= 1 B=  0 C=  2 Bx=     2 0.0
003 LOADK        A= 2 B=  0 C=  3 Bx=     3 1.0
004 CALL         A= 0 B=  3 C=  1 Bx=  1537 
005 GETGLOBAL    A= 0 B=  0 C=  4 Bx=     4 'PlayAndWaitForScene'
006 LOADK        A= 1 B=  0 C=  5 Bx=     5 1000.0
007 LOADK        A= 2 B=  0 C=  3 Bx=     3 1.0
008 CALL         A= 0 B=  3 C=  1 Bx=  1537 
009 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
010 GETTABLE     A= 0 B=  0 C=262 Bx=   262 C:'ApplyDefaultCamera'
011 CALL         A= 0 B=  1 C=  1 Bx=   513 
012 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
013 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
014 GETGLOBAL    A= 1 B=  0 C=  7 Bx=     7 'TUTORIAL_PROGRESS_NUMBER'
015 GETTABLE     A= 1 B=  1 C=264 Bx=   776 C:'TUTORIAL_CHANGEKEYTYPE'
016 LOADK        A= 2 B=  0 C=  2 Bx=     2 0.0
017 CALL         A= 0 B=  3 C=  1 Bx=  1537 
018 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
019 GETTABLE     A= 0 B=  0 C=265 Bx=   265 C:'GetTutorialState'
020 CALL         A= 0 B=  1 C=  2 Bx=   514 
021 GETGLOBAL    A= 1 B=  0 C= 10 Bx=    10 'FALSE'
022 EQ           A= 0 B=  0 C=  1 Bx=     1 
023 JMP          A= 0 B=256 C=  2 Bx=131074 target_pc=27
024 GETGLOBAL    A= 0 B=  0 C= 11 Bx=    11 'yield'
025 CALL         A= 0 B=  1 C=  1 Bx=   513 
026 JMP          A= 0 B=255 C=502 Bx=131062 target_pc=18
027 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
028 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
029 GETGLOBAL    A= 1 B=  0 C=  7 Bx=     7 'TUTORIAL_PROGRESS_NUMBER'
030 GETTABLE     A= 1 B=  1 C=268 Bx=   780 C:'TUTORIAL_KEYBOARD'
031 LOADK        A= 2 B=  0 C=  2 Bx=     2 0.0
032 CALL         A= 0 B=  3 C=  1 Bx=  1537 
033 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
034 GETTABLE     A= 0 B=  0 C=269 Bx=   269 C:'InsertTutorialCheckPoint'
035 LOADK        A= 1 B=  0 C=  3 Bx=     3 1.0
036 CALL         A= 0 B=  2 C=  1 Bx=  1025 
037 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
038 GETTABLE     A= 0 B=  0 C=270 Bx=   270 C:'GetControlStatus'
039 LOADK        A= 1 B=  0 C=  3 Bx=     3 1.0
040 CALL         A= 0 B=  2 C=  2 Bx=  1026 
041 GETGLOBAL    A= 1 B=  0 C= 10 Bx=    10 'FALSE'
042 EQ           A= 0 B=  0 C=  1 Bx=     1 
043 JMP          A= 0 B=256 C=  2 Bx=131074 target_pc=47
044 GETGLOBAL    A= 0 B=  0 C= 11 Bx=    11 'yield'
045 CALL         A= 0 B=  1 C=  1 Bx=   513 
046 JMP          A= 0 B=255 C=501 Bx=131061 target_pc=37
047 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
048 GETTABLE     A= 0 B=  0 C=271 Bx=   271 C:'SetCheckPointStatus'
049 LOADK        A= 1 B=  0 C=  3 Bx=     3 1.0
050 GETGLOBAL    A= 2 B=  0 C= 16 Bx=    16 'CHECKPOINT_CATEGORY'
051 GETTABLE     A= 2 B=  2 C=273 Bx=  1297 C:'TUTORIAL_POINT'
052 GETGLOBAL    A= 3 B=  0 C= 18 Bx=    18 'CHECKPOINT_STATUS'
053 GETTABLE     A= 3 B=  3 C=275 Bx=  1811 C:'ST_CLOSE'
054 CALL         A= 0 B=  4 C=  1 Bx=  2049 
055 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
056 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
057 LOADK        A= 1 B=  0 C=  2 Bx=     2 0.0
058 LOADK        A= 2 B=  0 C=  3 Bx=     3 1.0
059 CALL         A= 0 B=  3 C=  1 Bx=  1537 
060 GETGLOBAL    A= 0 B=  0 C=  4 Bx=     4 'PlayAndWaitForScene'
061 LOADK        A= 1 B=  0 C=  5 Bx=     5 1000.0
062 LOADK        A= 2 B=  0 C= 20 Bx=    20 3.0
063 CALL         A= 0 B=  3 C=  1 Bx=  1537 
064 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
065 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
066 GETGLOBAL    A= 1 B=  0 C=  7 Bx=     7 'TUTORIAL_PROGRESS_NUMBER'
067 GETTABLE     A= 1 B=  1 C=277 Bx=   789 C:'TUTORIAL_MOUSE'
068 LOADK        A= 2 B=  0 C=  2 Bx=     2 0.0
069 CALL         A= 0 B=  3 C=  1 Bx=  1537 
070 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
071 GETTABLE     A= 0 B=  0 C=269 Bx=   269 C:'InsertTutorialCheckPoint'
072 LOADK        A= 1 B=  0 C= 22 Bx=    22 2.0
073 CALL         A= 0 B=  2 C=  1 Bx=  1025 
074 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
075 GETTABLE     A= 0 B=  0 C=270 Bx=   270 C:'GetControlStatus'
076 LOADK        A= 1 B=  0 C= 22 Bx=    22 2.0
077 CALL         A= 0 B=  2 C=  2 Bx=  1026 
078 GETGLOBAL    A= 1 B=  0 C= 10 Bx=    10 'FALSE'
079 EQ           A= 0 B=  0 C=  1 Bx=     1 
080 JMP          A= 0 B=256 C=  2 Bx=131074 target_pc=84
081 GETGLOBAL    A= 0 B=  0 C= 11 Bx=    11 'yield'
082 CALL         A= 0 B=  1 C=  1 Bx=   513 
083 JMP          A= 0 B=255 C=501 Bx=131061 target_pc=74
084 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
085 GETTABLE     A= 0 B=  0 C=271 Bx=   271 C:'SetCheckPointStatus'
086 LOADK        A= 1 B=  0 C= 22 Bx=    22 2.0
087 GETGLOBAL    A= 2 B=  0 C= 16 Bx=    16 'CHECKPOINT_CATEGORY'
088 GETTABLE     A= 2 B=  2 C=273 Bx=  1297 C:'TUTORIAL_POINT'
089 GETGLOBAL    A= 3 B=  0 C= 18 Bx=    18 'CHECKPOINT_STATUS'
090 GETTABLE     A= 3 B=  3 C=275 Bx=  1811 C:'ST_CLOSE'
091 CALL         A= 0 B=  4 C=  1 Bx=  2049 
092 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
093 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
094 LOADK        A= 1 B=  0 C=  2 Bx=     2 0.0
095 LOADK        A= 2 B=  0 C=  3 Bx=     3 1.0
096 CALL         A= 0 B=  3 C=  1 Bx=  1537 
097 GETGLOBAL    A= 0 B=  0 C=  4 Bx=     4 'PlayAndWaitForScene'
098 LOADK        A= 1 B=  0 C=  5 Bx=     5 1000.0
099 LOADK        A= 2 B=  0 C= 23 Bx=    23 4.0
100 CALL         A= 0 B=  3 C=  1 Bx=  1537 
101 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
102 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
103 GETGLOBAL    A= 1 B=  0 C=  7 Bx=     7 'TUTORIAL_PROGRESS_NUMBER'
104 GETTABLE     A= 1 B=  1 C=280 Bx=   792 C:'TUTORIAL_CAMERA'
105 LOADK        A= 2 B=  0 C=  2 Bx=     2 0.0
106 CALL         A= 0 B=  3 C=  1 Bx=  1537 
107 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
108 GETTABLE     A= 0 B=  0 C=281 Bx=   281 C:'InsertIsilia'
109 CALL         A= 0 B=  1 C=  1 Bx=   513 
110 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
111 GETTABLE     A= 0 B=  0 C=282 Bx=   282 C:'IsIsiliaFound'
112 CALL         A= 0 B=  1 C=  2 Bx=   514 
113 GETGLOBAL    A= 1 B=  0 C= 10 Bx=    10 'FALSE'
114 EQ           A= 0 B=  0 C=  1 Bx=     1 
115 JMP          A= 0 B=256 C=  2 Bx=131074 target_pc=119
116 GETGLOBAL    A= 0 B=  0 C= 11 Bx=    11 'yield'
117 CALL         A= 0 B=  1 C=  1 Bx=   513 
118 JMP          A= 0 B=255 C=502 Bx=131062 target_pc=110
119 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
120 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
121 LOADK        A= 1 B=  0 C=  2 Bx=     2 0.0
122 LOADK        A= 2 B=  0 C=  3 Bx=     3 1.0
123 CALL         A= 0 B=  3 C=  1 Bx=  1537 
124 GETGLOBAL    A= 0 B=  0 C=  4 Bx=     4 'PlayAndWaitForScene'
125 LOADK        A= 1 B=  0 C=  5 Bx=     5 1000.0
126 LOADK        A= 2 B=  0 C= 27 Bx=    27 6.0
127 CALL         A= 0 B=  3 C=  1 Bx=  1537 
128 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
129 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
130 GETGLOBAL    A= 1 B=  0 C=  7 Bx=     7 'TUTORIAL_PROGRESS_NUMBER'
131 GETTABLE     A= 1 B=  1 C=284 Bx=   796 C:'TUTORIAL_LEADER_CHANGE'
132 LOADK        A= 2 B=  0 C=  2 Bx=     2 0.0
133 CALL         A= 0 B=  3 C=  1 Bx=  1537 
134 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
135 GETTABLE     A= 0 B=  0 C=285 Bx=   285 C:'CheckLeader'
136 CALL         A= 0 B=  1 C=  2 Bx=   514 
137 GETGLOBAL    A= 1 B=  0 C= 10 Bx=    10 'FALSE'
138 EQ           A= 0 B=  0 C=  1 Bx=     1 
139 JMP          A= 0 B=256 C= 21 Bx=131093 target_pc=162
140 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
141 GETTABLE     A= 0 B=  0 C=286 Bx=   286 C:'IsLeaderDialogOpened'
142 CALL         A= 0 B=  1 C=  2 Bx=   514 
143 GETGLOBAL    A= 1 B=  0 C= 10 Bx=    10 'FALSE'
144 EQ           A= 0 B=  0 C=  1 Bx=     1 
145 JMP          A= 0 B=256 C=  6 Bx=131078 target_pc=153
146 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
147 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
148 GETGLOBAL    A= 1 B=  0 C=  7 Bx=     7 'TUTORIAL_PROGRESS_NUMBER'
149 GETTABLE     A= 1 B=  1 C=284 Bx=   796 C:'TUTORIAL_LEADER_CHANGE'
150 LOADK        A= 2 B=  0 C=  2 Bx=     2 0.0
151 CALL         A= 0 B=  3 C=  1 Bx=  1537 
152 JMP          A= 0 B=256 C=  5 Bx=131077 target_pc=159
153 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
154 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
155 GETGLOBAL    A= 1 B=  0 C=  7 Bx=     7 'TUTORIAL_PROGRESS_NUMBER'
156 GETTABLE     A= 1 B=  1 C=287 Bx=   799 C:'TUTORIAL_LC_DLG_OPENED'
157 LOADK        A= 2 B=  0 C=  2 Bx=     2 0.0
158 CALL         A= 0 B=  3 C=  1 Bx=  1537 
159 GETGLOBAL    A= 0 B=  0 C= 11 Bx=    11 'yield'
160 CALL         A= 0 B=  1 C=  1 Bx=   513 
161 JMP          A= 0 B=255 C=483 Bx=131043 target_pc=134
162 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
163 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
164 LOADK        A= 1 B=  0 C=  2 Bx=     2 0.0
165 LOADK        A= 2 B=  0 C=  3 Bx=     3 1.0
166 CALL         A= 0 B=  3 C=  1 Bx=  1537 
167 GETGLOBAL    A= 0 B=  0 C=  4 Bx=     4 'PlayAndWaitForScene'
168 LOADK        A= 1 B=  0 C=  5 Bx=     5 1000.0
169 LOADK        A= 2 B=  0 C= 32 Bx=    32 7.0
170 CALL         A= 0 B=  3 C=  1 Bx=  1537 
171 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
172 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
173 GETGLOBAL    A= 1 B=  0 C=  7 Bx=     7 'TUTORIAL_PROGRESS_NUMBER'
174 GETTABLE     A= 1 B=  1 C=289 Bx=   801 C:'TUTORIAL_GOTO_NPC'
175 LOADK        A= 2 B=  0 C=  2 Bx=     2 0.0
176 CALL         A= 0 B=  3 C=  1 Bx=  1537 
177 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
178 GETTABLE     A= 0 B=  0 C=269 Bx=   269 C:'InsertTutorialCheckPoint'
179 LOADK        A= 1 B=  0 C= 20 Bx=    20 3.0
180 CALL         A= 0 B=  2 C=  1 Bx=  1025 
181 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
182 GETTABLE     A= 0 B=  0 C=270 Bx=   270 C:'GetControlStatus'
183 LOADK        A= 1 B=  0 C= 20 Bx=    20 3.0
184 CALL         A= 0 B=  2 C=  2 Bx=  1026 
185 GETGLOBAL    A= 1 B=  0 C= 10 Bx=    10 'FALSE'
186 EQ           A= 0 B=  0 C=  1 Bx=     1 
187 JMP          A= 0 B=256 C=  2 Bx=131074 target_pc=191
188 GETGLOBAL    A= 0 B=  0 C= 11 Bx=    11 'yield'
189 CALL         A= 0 B=  1 C=  1 Bx=   513 
190 JMP          A= 0 B=255 C=501 Bx=131061 target_pc=181
191 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
192 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'PostUIMessage_TutoMsg'
193 LOADK        A= 1 B=  0 C=  2 Bx=     2 0.0
194 LOADK        A= 2 B=  0 C=  3 Bx=     3 1.0
195 CALL         A= 0 B=  3 C=  1 Bx=  1537 
196 RETURN       A= 0 B=  1 C=  0 Bx=   512 
```

### nested proto 5: source lines 131–199; 158 instructions, 41 constants

常數索引：
```text
[0] 'PlayAndWaitForScene'
[1] 1000.0
[2] 8.0
[3] 'Tutorial'
[4] 'PostUIMessage_TutoMsg'
[5] 0.0
[6] 6.0
[7] 'yield'
[8] 1.0
[9] 'RequestStartScenario'
[10] 14.0
[11] 'IsScenarioEnded'
[12] 'FALSE'
[13] 'SetUIPage'
[14] 'SetCheckPointStatus'
[15] 10016.0
[16] 'CHECKPOINT_CATEGORY'
[17] 'NPC'
[18] 'CHECKPOINT_STATUS'
[19] 'ST_CLOSE'
[20] 10.0
[21] 12.0
[22] 'HideUI'
[23] 'PostUIMessage_EmployChar'
[24] 4.0
[25] 'g_TutoEmployCharQuery'
[26] 'TUTORIAL_PROGRESS_NUMBER'
[27] 'TUTORIAL_PINKOHOUSE'
[28] 'InsertTutorialCheckPoint'
[29] 'GetControlStatus'
[30] 'TUTORIAL_POINT'
[31] 'RegisterScalingObject'
[32] 'Image/Cut_in/Lenart_PinkoRoom.dds'
[33] 1024.0
[34] 512.0
[35] 13.0
[36] 'DestroyFlyingObjects'
[37] 'IsCharacterAvailable'
[38] 2.0
[39] 'ST_OPEN'
[40] 'TUTORIAL_STARTSCENARIO'
```

```text
000 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'PlayAndWaitForScene'
001 LOADK        A= 1 B=  0 C=  1 Bx=     1 1000.0
002 LOADK        A= 2 B=  0 C=  2 Bx=     2 8.0
003 CALL         A= 0 B=  3 C=  1 Bx=  1537 
004 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
005 GETTABLE     A= 0 B=  0 C=260 Bx=   260 C:'PostUIMessage_TutoMsg'
006 LOADK        A= 1 B=  0 C=  5 Bx=     5 0.0
007 LOADK        A= 2 B=  0 C=  6 Bx=     6 6.0
008 CALL         A= 0 B=  3 C=  1 Bx=  1537 
009 GETGLOBAL    A= 0 B=  0 C=  7 Bx=     7 'yield'
010 CALL         A= 0 B=  1 C=  1 Bx=   513 
011 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
012 GETTABLE     A= 0 B=  0 C=260 Bx=   260 C:'PostUIMessage_TutoMsg'
013 LOADK        A= 1 B=  0 C=  5 Bx=     5 0.0
014 LOADK        A= 2 B=  0 C=  8 Bx=     8 1.0
015 CALL         A= 0 B=  3 C=  1 Bx=  1537 
016 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
017 GETTABLE     A= 0 B=  0 C=265 Bx=   265 C:'RequestStartScenario'
018 LOADK        A= 1 B=  0 C= 10 Bx=    10 14.0
019 CALL         A= 0 B=  2 C=  1 Bx=  1025 
020 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
021 GETTABLE     A= 0 B=  0 C=267 Bx=   267 C:'IsScenarioEnded'
022 LOADK        A= 1 B=  0 C= 10 Bx=    10 14.0
023 CALL         A= 0 B=  2 C=  2 Bx=  1026 
024 GETGLOBAL    A= 1 B=  0 C= 12 Bx=    12 'FALSE'
025 EQ           A= 0 B=  0 C=  1 Bx=     1 
026 JMP          A= 0 B=256 C=  2 Bx=131074 target_pc=30
027 GETGLOBAL    A= 0 B=  0 C=  7 Bx=     7 'yield'
028 CALL         A= 0 B=  1 C=  1 Bx=   513 
029 JMP          A= 0 B=255 C=501 Bx=131061 target_pc=20
030 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
031 GETTABLE     A= 0 B=  0 C=269 Bx=   269 C:'SetUIPage'
032 CALL         A= 0 B=  1 C=  1 Bx=   513 
033 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
034 GETTABLE     A= 0 B=  0 C=270 Bx=   270 C:'SetCheckPointStatus'
035 LOADK        A= 1 B=  0 C= 15 Bx=    15 10016.0
036 GETGLOBAL    A= 2 B=  0 C= 16 Bx=    16 'CHECKPOINT_CATEGORY'
037 GETTABLE     A= 2 B=  2 C=273 Bx=  1297 C:'NPC'
038 GETGLOBAL    A= 3 B=  0 C= 18 Bx=    18 'CHECKPOINT_STATUS'
039 GETTABLE     A= 3 B=  3 C=275 Bx=  1811 C:'ST_CLOSE'
040 CALL         A= 0 B=  4 C=  1 Bx=  2049 
041 GETGLOBAL    A= 0 B=  0 C=  7 Bx=     7 'yield'
042 CALL         A= 0 B=  1 C=  1 Bx=   513 
043 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'PlayAndWaitForScene'
044 LOADK        A= 1 B=  0 C=  1 Bx=     1 1000.0
045 LOADK        A= 2 B=  0 C= 20 Bx=    20 10.0
046 CALL         A= 0 B=  3 C=  1 Bx=  1537 
047 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'PlayAndWaitForScene'
048 LOADK        A= 1 B=  0 C=  1 Bx=     1 1000.0
049 LOADK        A= 2 B=  0 C= 21 Bx=    21 12.0
050 CALL         A= 0 B=  3 C=  1 Bx=  1537 
051 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
052 GETTABLE     A= 0 B=  0 C=278 Bx=   278 C:'HideUI'
053 CALL         A= 0 B=  1 C=  1 Bx=   513 
054 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
055 GETTABLE     A= 0 B=  0 C=279 Bx=   279 C:'PostUIMessage_EmployChar'
056 LOADK        A= 1 B=  0 C= 24 Bx=    24 4.0
057 CALL         A= 0 B=  2 C=  1 Bx=  1025 
058 GETGLOBAL    A= 0 B=  0 C= 25 Bx=    25 'g_TutoEmployCharQuery'
059 GETGLOBAL    A= 1 B=  0 C= 12 Bx=    12 'FALSE'
060 EQ           A= 0 B=  0 C=  1 Bx=     1 
061 JMP          A= 0 B=256 C=  2 Bx=131074 target_pc=65
062 GETGLOBAL    A= 0 B=  0 C=  7 Bx=     7 'yield'
063 CALL         A= 0 B=  1 C=  1 Bx=   513 
064 JMP          A= 0 B=255 C=504 Bx=131064 target_pc=58
065 GETGLOBAL    A= 0 B=  0 C= 12 Bx=    12 'FALSE'
066 SETGLOBAL    A= 0 B=  0 C= 25 Bx=    25 'g_TutoEmployCharQuery'
067 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
068 GETTABLE     A= 0 B=  0 C=260 Bx=   260 C:'PostUIMessage_TutoMsg'
069 GETGLOBAL    A= 1 B=  0 C= 26 Bx=    26 'TUTORIAL_PROGRESS_NUMBER'
070 GETTABLE     A= 1 B=  1 C=283 Bx=   795 C:'TUTORIAL_PINKOHOUSE'
071 LOADK        A= 2 B=  0 C=  5 Bx=     5 0.0
072 CALL         A= 0 B=  3 C=  1 Bx=  1537 
073 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
074 GETTABLE     A= 0 B=  0 C=284 Bx=   284 C:'InsertTutorialCheckPoint'
075 LOADK        A= 1 B=  0 C= 24 Bx=    24 4.0
076 CALL         A= 0 B=  2 C=  1 Bx=  1025 
077 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
078 GETTABLE     A= 0 B=  0 C=285 Bx=   285 C:'GetControlStatus'
079 LOADK        A= 1 B=  0 C= 24 Bx=    24 4.0
080 CALL         A= 0 B=  2 C=  2 Bx=  1026 
081 GETGLOBAL    A= 1 B=  0 C= 12 Bx=    12 'FALSE'
082 EQ           A= 0 B=  0 C=  1 Bx=     1 
083 JMP          A= 0 B=256 C=  2 Bx=131074 target_pc=87
084 GETGLOBAL    A= 0 B=  0 C=  7 Bx=     7 'yield'
085 CALL         A= 0 B=  1 C=  1 Bx=   513 
086 JMP          A= 0 B=255 C=501 Bx=131061 target_pc=77
087 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
088 GETTABLE     A= 0 B=  0 C=270 Bx=   270 C:'SetCheckPointStatus'
089 LOADK        A= 1 B=  0 C= 24 Bx=    24 4.0
090 GETGLOBAL    A= 2 B=  0 C= 16 Bx=    16 'CHECKPOINT_CATEGORY'
091 GETTABLE     A= 2 B=  2 C=286 Bx=  1310 C:'TUTORIAL_POINT'
092 GETGLOBAL    A= 3 B=  0 C= 18 Bx=    18 'CHECKPOINT_STATUS'
093 GETTABLE     A= 3 B=  3 C=275 Bx=  1811 C:'ST_CLOSE'
094 CALL         A= 0 B=  4 C=  1 Bx=  2049 
095 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
096 GETTABLE     A= 0 B=  0 C=260 Bx=   260 C:'PostUIMessage_TutoMsg'
097 LOADK        A= 1 B=  0 C=  5 Bx=     5 0.0
098 LOADK        A= 2 B=  0 C=  8 Bx=     8 1.0
099 CALL         A= 0 B=  3 C=  1 Bx=  1537 
100 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
101 GETTABLE     A= 0 B=  0 C=287 Bx=   287 C:'RegisterScalingObject'
102 LOADK        A= 1 B=  0 C= 32 Bx=    32 'Image/Cut_in/Lenart_PinkoRoom.dds'
103 LOADK        A= 2 B=  0 C= 33 Bx=    33 1024.0
104 LOADK        A= 3 B=  0 C= 34 Bx=    34 512.0
105 CALL         A= 0 B=  4 C=  1 Bx=  2049 
106 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'PlayAndWaitForScene'
107 LOADK        A= 1 B=  0 C=  1 Bx=     1 1000.0
108 LOADK        A= 2 B=  0 C= 35 Bx=    35 13.0
109 CALL         A= 0 B=  3 C=  1 Bx=  1537 
110 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
111 GETTABLE     A= 0 B=  0 C=292 Bx=   292 C:'DestroyFlyingObjects'
112 CALL         A= 0 B=  1 C=  1 Bx=   513 
113 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
114 GETTABLE     A= 0 B=  0 C=293 Bx=   293 C:'IsCharacterAvailable'
115 LOADK        A= 1 B=  0 C= 38 Bx=    38 2.0
116 CALL         A= 0 B=  2 C=  2 Bx=  1026 
117 GETGLOBAL    A= 1 B=  0 C= 12 Bx=    12 'FALSE'
118 EQ           A= 0 B=  0 C=  1 Bx=     1 
119 JMP          A= 0 B=256 C=  2 Bx=131074 target_pc=123
120 GETGLOBAL    A= 0 B=  0 C=  7 Bx=     7 'yield'
121 CALL         A= 0 B=  1 C=  1 Bx=   513 
122 JMP          A= 0 B=255 C=501 Bx=131061 target_pc=113
123 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
124 GETTABLE     A= 0 B=  0 C=278 Bx=   278 C:'HideUI'
125 CALL         A= 0 B=  1 C=  1 Bx=   513 
126 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
127 GETTABLE     A= 0 B=  0 C=279 Bx=   279 C:'PostUIMessage_EmployChar'
128 LOADK        A= 1 B=  0 C= 38 Bx=    38 2.0
129 CALL         A= 0 B=  2 C=  1 Bx=  1025 
130 GETGLOBAL    A= 0 B=  0 C= 25 Bx=    25 'g_TutoEmployCharQuery'
131 GETGLOBAL    A= 1 B=  0 C= 12 Bx=    12 'FALSE'
132 EQ           A= 0 B=  0 C=  1 Bx=     1 
133 JMP          A= 0 B=256 C=  2 Bx=131074 target_pc=137
134 GETGLOBAL    A= 0 B=  0 C=  7 Bx=     7 'yield'
135 CALL         A= 0 B=  1 C=  1 Bx=   513 
136 JMP          A= 0 B=255 C=504 Bx=131064 target_pc=130
137 GETGLOBAL    A= 0 B=  0 C= 12 Bx=    12 'FALSE'
138 SETGLOBAL    A= 0 B=  0 C= 25 Bx=    25 'g_TutoEmployCharQuery'
139 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
140 GETTABLE     A= 0 B=  0 C=270 Bx=   270 C:'SetCheckPointStatus'
141 LOADK        A= 1 B=  0 C= 15 Bx=    15 10016.0
142 GETGLOBAL    A= 2 B=  0 C= 16 Bx=    16 'CHECKPOINT_CATEGORY'
143 GETTABLE     A= 2 B=  2 C=273 Bx=  1297 C:'NPC'
144 GETGLOBAL    A= 3 B=  0 C= 18 Bx=    18 'CHECKPOINT_STATUS'
145 GETTABLE     A= 3 B=  3 C=295 Bx=  1831 C:'ST_OPEN'
146 CALL         A= 0 B=  4 C=  1 Bx=  2049 
147 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'PlayAndWaitForScene'
148 LOADK        A= 1 B=  0 C=  1 Bx=     1 1000.0
149 LOADK        A= 2 B=  0 C= 10 Bx=    10 14.0
150 CALL         A= 0 B=  3 C=  1 Bx=  1537 
151 GETGLOBAL    A= 0 B=  0 C=  3 Bx=     3 'Tutorial'
152 GETTABLE     A= 0 B=  0 C=260 Bx=   260 C:'PostUIMessage_TutoMsg'
153 GETGLOBAL    A= 1 B=  0 C= 26 Bx=    26 'TUTORIAL_PROGRESS_NUMBER'
154 GETTABLE     A= 1 B=  1 C=296 Bx=   808 C:'TUTORIAL_STARTSCENARIO'
155 LOADK        A= 2 B=  0 C=  5 Bx=     5 0.0
156 CALL         A= 0 B=  3 C=  1 Bx=  1537 
157 RETURN       A= 0 B=  1 C=  0 Bx=   512 
```

### nested proto 7: source lines 223–273; 78 instructions, 26 constants

常數索引：
```text
[0] 'Tutorial'
[1] 'SetCheckPointStatus'
[2] 10016.0
[3] 'CHECKPOINT_CATEGORY'
[4] 'NPC'
[5] 'CHECKPOINT_STATUS'
[6] 'ST_CLOSE'
[7] 'yield'
[8] 'SetControlStatus'
[9] 10.0
[10] 'TRUE'
[11] 't_executeCoFunction'
[12] 'Tutorial_Part1'
[13] 't_isCoroutineAlive'
[14] 'GetControlStatus'
[15] 0.0
[16] 'FALSE'
[17] 'StopCutScene'
[18] 't_removeCoroutine'
[19] 1.0
[20] 'TUTORIAL_POINT'
[21] 2.0
[22] 3.0
[23] 'DeleteObject'
[24] 240.0
[25] 'Tutorial_Part2'
```

```text
000 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
001 GETTABLE     A= 0 B=  0 C=257 Bx=   257 C:'SetCheckPointStatus'
002 LOADK        A= 1 B=  0 C=  2 Bx=     2 10016.0
003 GETGLOBAL    A= 2 B=  0 C=  3 Bx=     3 'CHECKPOINT_CATEGORY'
004 GETTABLE     A= 2 B=  2 C=260 Bx=  1284 C:'NPC'
005 GETGLOBAL    A= 3 B=  0 C=  5 Bx=     5 'CHECKPOINT_STATUS'
006 GETTABLE     A= 3 B=  3 C=262 Bx=  1798 C:'ST_CLOSE'
007 CALL         A= 0 B=  4 C=  1 Bx=  2049 
008 GETGLOBAL    A= 0 B=  0 C=  7 Bx=     7 'yield'
009 CALL         A= 0 B=  1 C=  1 Bx=   513 
010 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 'Tutorial'
011 GETTABLE     A= 0 B=  0 C=264 Bx=   264 C:'SetControlStatus'
012 LOADK        A= 1 B=  0 C=  9 Bx=     9 10.0
013 GETGLOBAL    A= 2 B=  0 C= 10 Bx=    10 'TRUE'
014 CALL         A= 0 B=  3 C=  1 Bx=  1537 
015 GETGLOBAL    A= 0 B=  0 C= 11 Bx=    11 't_executeCoFunction'
016 GETGLOBAL    A= 1 B=  0 C= 12 Bx=    12 'Tutorial_Part1'
017 CALL         A= 0 B=  2 C=  2 Bx=  1026 
018 GETGLOBAL    A= 1 B=  0 C= 13 Bx=    13 't_isCoroutineAlive'
019 MOVE         A= 2 B=  0 C=  0 Bx=     0 
020 CALL         A= 1 B=  2 C=  2 Bx=  1026 
021 TEST         A= 1 B=  0 C=  0 Bx=     0 
022 JMP          A= 0 B=256 C= 22 Bx=131094 target_pc=46
023 GETGLOBAL    A= 1 B=  0 C=  0 Bx=     0 'Tutorial'
024 GETTABLE     A= 1 B=  1 C=270 Bx=   782 C:'GetControlStatus'
025 LOADK        A= 2 B=  0 C= 15 Bx=    15 0.0
026 CALL         A= 1 B=  2 C=  2 Bx=  1026 
027 GETGLOBAL    A= 2 B=  0 C= 16 Bx=    16 'FALSE'
028 EQ           A= 1 B=  1 C=  2 Bx=   514 
029 JMP          A= 0 B=256 C= 12 Bx=131084 target_pc=43
030 GETGLOBAL    A= 1 B=  0 C=  0 Bx=     0 'Tutorial'
031 GETTABLE     A= 1 B=  1 C=264 Bx=   776 C:'SetControlStatus'
032 LOADK        A= 2 B=  0 C= 15 Bx=    15 0.0
033 GETGLOBAL    A= 3 B=  0 C= 16 Bx=    16 'FALSE'
034 CALL         A= 1 B=  3 C=  1 Bx=  1537 
035 GETGLOBAL    A= 1 B=  0 C=  0 Bx=     0 'Tutorial'
036 GETTABLE     A= 1 B=  1 C=273 Bx=   785 C:'StopCutScene'
037 CALL         A= 1 B=  1 C=  1 Bx=   513 
038 GETGLOBAL    A= 1 B=  0 C= 18 Bx=    18 't_removeCoroutine'
039 MOVE         A= 2 B=  0 C=  0 Bx=     0 
040 CALL         A= 1 B=  2 C=  1 Bx=  1025 
041 LOADNIL      A= 0 B=  0 C=  0 Bx=     0 
042 JMP          A= 0 B=256 C=  2 Bx=131074 target_pc=46
043 GETGLOBAL    A= 1 B=  0 C=  7 Bx=     7 'yield'
044 CALL         A= 1 B=  1 C=  1 Bx=   513 
045 JMP          A= 0 B=255 C=483 Bx=131043 target_pc=18
046 LOADNIL      A= 0 B=  0 C=  0 Bx=     0 
047 GETGLOBAL    A= 1 B=  0 C=  0 Bx=     0 'Tutorial'
048 GETTABLE     A= 1 B=  1 C=257 Bx=   769 C:'SetCheckPointStatus'
049 LOADK        A= 2 B=  0 C= 19 Bx=    19 1.0
050 GETGLOBAL    A= 3 B=  0 C=  3 Bx=     3 'CHECKPOINT_CATEGORY'
051 GETTABLE     A= 3 B=  3 C=276 Bx=  1812 C:'TUTORIAL_POINT'
052 GETGLOBAL    A= 4 B=  0 C=  5 Bx=     5 'CHECKPOINT_STATUS'
053 GETTABLE     A= 4 B=  4 C=262 Bx=  2310 C:'ST_CLOSE'
054 CALL         A= 1 B=  4 C=  1 Bx=  2049 
055 GETGLOBAL    A= 1 B=  0 C=  0 Bx=     0 'Tutorial'
056 GETTABLE     A= 1 B=  1 C=257 Bx=   769 C:'SetCheckPointStatus'
057 LOADK        A= 2 B=  0 C= 21 Bx=    21 2.0
058 GETGLOBAL    A= 3 B=  0 C=  3 Bx=     3 'CHECKPOINT_CATEGORY'
059 GETTABLE     A= 3 B=  3 C=276 Bx=  1812 C:'TUTORIAL_POINT'
060 GETGLOBAL    A= 4 B=  0 C=  5 Bx=     5 'CHECKPOINT_STATUS'
061 GETTABLE     A= 4 B=  4 C=262 Bx=  2310 C:'ST_CLOSE'
062 CALL         A= 1 B=  4 C=  1 Bx=  2049 
063 GETGLOBAL    A= 1 B=  0 C=  0 Bx=     0 'Tutorial'
064 GETTABLE     A= 1 B=  1 C=257 Bx=   769 C:'SetCheckPointStatus'
065 LOADK        A= 2 B=  0 C= 22 Bx=    22 3.0
066 GETGLOBAL    A= 3 B=  0 C=  3 Bx=     3 'CHECKPOINT_CATEGORY'
067 GETTABLE     A= 3 B=  3 C=276 Bx=  1812 C:'TUTORIAL_POINT'
068 GETGLOBAL    A= 4 B=  0 C=  5 Bx=     5 'CHECKPOINT_STATUS'
069 GETTABLE     A= 4 B=  4 C=262 Bx=  2310 C:'ST_CLOSE'
070 CALL         A= 1 B=  4 C=  1 Bx=  2049 
071 GETGLOBAL    A= 1 B=  0 C=  0 Bx=     0 'Tutorial'
072 GETTABLE     A= 1 B=  1 C=279 Bx=   791 C:'DeleteObject'
073 LOADK        A= 2 B=  0 C= 24 Bx=    24 240.0
074 CALL         A= 1 B=  2 C=  1 Bx=  1025 
075 GETGLOBAL    A= 1 B=  0 C= 25 Bx=    25 'Tutorial_Part2'
076 CALL         A= 1 B=  1 C=  1 Bx=   513 
077 RETURN       A= 0 B=  1 C=  0 Bx=   512 
```

### nested proto 8: source lines 274–276; 4 instructions, 2 constants

常數索引：
```text
[0] 't_executeCoFunction'
[1] 'TutorialMain'
```

```text
000 GETGLOBAL    A= 0 B=  0 C=  0 Bx=     0 't_executeCoFunction'
001 GETGLOBAL    A= 1 B=  0 C=  1 Bx=     1 'TutorialMain'
002 CALL         A= 0 B=  2 C=  1 Bx=  1025 
003 RETURN       A= 0 B=  1 C=  0 Bx=   512 
```

## 附錄 C — 本次直接擷取的原始 x86 assembly 完整有界區段、raw SHA256

**注意**：`.text` bytes 為檢查的原件，函式分界需要由實際 CFG 入口確認；線性 objdump 可能跨入其它函式、padding 或 jump table。以下每一檔的 start/end **只是驗證區間**，不得宣稱切片本身為完整函式。

### tutorial_entry: VA `0x004A8A8A–0x004A8B85` / raw `0x000A7E8A–0x000A7F85` (`[start,end)`); SHA256 `aee7eb468ea6bb228bf0d272005bad4d9afb8f663d3cd0e8fdf0472fb3cd99c4`

```asm
004a8a8a <.data+0xa7e8a>:
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
  4a8b7f:	64 89 0d 00 00 00  	mov    DWORD PTR fs:0x0,ecx
```

### tutorial_native_callback: VA `0x004AB8B0–0x004AB94D` / raw `0x000AACB0–0x000AAD4D` (`[start,end)`); SHA256 `17df78535235d963d2f543d4b207befa35d1d131913f703f9762de0911a3da47`

```asm
004ab8b0 <.data+0xaacb0>:
  4ab8b0:	57                   	push   edi
  4ab8b1:	8b 38                	mov    edi,DWORD PTR [eax]
  4ab8b3:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4ab8b8:	c7 05 7c 18 fe 00 d0 	mov    DWORD PTR ds:0xfe187c,0x4aa4d0
  4ab8bf:	a4 4a 00 
  4ab8c2:	e8 b9 9d 24 00       	call   0x6f5680
  4ab8c7:	8b 03                	mov    eax,DWORD PTR [ebx]
  4ab8c9:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4ab8cc:	83 e8 10             	sub    eax,0x10
  4ab8cf:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4ab8d4:	74 06                	je     0x4ab8dc
  4ab8d6:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4ab8da:	74 14                	je     0x4ab8f0
  4ab8dc:	57                   	push   edi
  4ab8dd:	68 c4 26 c4 00       	push   0xc426c4
  4ab8e2:	e8 d6 77 3e 00       	call   0x8930bd
  4ab8e7:	8b 1b                	mov    ebx,DWORD PTR [ebx]
  4ab8e9:	83 c4 08             	add    esp,0x8
  4ab8ec:	83 43 08 f0          	add    DWORD PTR [ebx+0x8],0xfffffff0
  4ab8f0:	8b 3d 00 18 fe 00    	mov    edi,DWORD PTR ds:0xfe1800
  4ab8f6:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab8f8:	68 68 ad d6 00       	push   0xd6ad68
  4ab8fd:	e8 0e 9c 24 00       	call   0x6f5510
  4ab902:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab904:	83 c4 04             	add    esp,0x4
  4ab907:	6a 00                	push   0x0
  4ab909:	68 e0 c9 4a 00       	push   0x4ac9e0
  4ab90e:	e8 9d 9c 24 00       	call   0x6f55b0
  4ab913:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4ab915:	51                   	push   ecx
  4ab916:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4ab91b:	e8 d0 9e 24 00       	call   0x6f57f0
  4ab920:	8b 15 00 18 fe 00    	mov    edx,DWORD PTR ds:0xfe1800
  4ab926:	8b 02                	mov    eax,DWORD PTR [edx]
  4ab928:	83 c4 0c             	add    esp,0xc
  4ab92b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4ab92f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ab932:	5f                   	pop    edi
  4ab933:	5e                   	pop    esi
  4ab934:	5b                   	pop    ebx
  4ab935:	5d                   	pop    ebp
  4ab936:	c2 04 00             	ret    0x4
  4ab939:	cc                   	int3
  4ab93a:	cc                   	int3
  4ab93b:	cc                   	int3
  4ab93c:	cc                   	int3
  4ab93d:	cc                   	int3
  4ab93e:	cc                   	int3
  4ab93f:	cc                   	int3
  4ab940:	55                   	push   ebp
  4ab941:	8b ec                	mov    ebp,esp
  4ab943:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ab946:	53                   	push   ebx
  4ab947:	8b 1d 00 18 fe 00    	mov    ebx,DWORD PTR ds:0xfe1800
```

### scenario_sender: VA `0x004AA4D0–0x004AA555` / raw `0x000A98D0–0x000A9955` (`[start,end)`); SHA256 `19b8c594b62e2c4ab26881fac638e962fafd1ddb7548a94134d82ddbad1df414`

```asm
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
  4aa510:	55                   	push   ebp
  4aa511:	8b ec                	mov    ebp,esp
  4aa513:	8d 41 04             	lea    eax,[ecx+0x4]
  4aa516:	8d 55 08             	lea    edx,[ebp+0x8]
  4aa519:	e8 62 83 01 00       	call   0x4c2880
  4aa51e:	8b 00                	mov    eax,DWORD PTR [eax]
  4aa520:	5d                   	pop    ebp
  4aa521:	c2 04 00             	ret    0x4
  4aa524:	cc                   	int3
  4aa525:	cc                   	int3
  4aa526:	cc                   	int3
  4aa527:	cc                   	int3
  4aa528:	cc                   	int3
  4aa529:	cc                   	int3
  4aa52a:	cc                   	int3
  4aa52b:	cc                   	int3
  4aa52c:	cc                   	int3
  4aa52d:	cc                   	int3
  4aa52e:	cc                   	int3
  4aa52f:	cc                   	int3
  4aa530:	55                   	push   ebp
  4aa531:	8b ec                	mov    ebp,esp
  4aa533:	51                   	push   ecx
  4aa534:	53                   	push   ebx
  4aa535:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4aa538:	56                   	push   esi
  4aa539:	8b f1                	mov    esi,ecx
  4aa53b:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  4aa53e:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  4aa541:	80 79 41 00          	cmp    BYTE PTR [ecx+0x41],0x0
  4aa545:	75 1f                	jne    0x4aa566
  4aa547:	57                   	push   edi
  4aa548:	0f b7 3b             	movzx  edi,WORD PTR [ebx]
  4aa54b:	eb 03                	jmp    0x4aa550
  4aa54d:	8d 49 00             	lea    ecx,[ecx+0x0]
  4aa550:	66 39 79 0c          	cmp    WORD PTR [ecx+0xc],di
  4aa554:	7d                 	jge    0x4aa55b
```

### scenario_lua_bridge: VA `0x004AC9E0–0x004ACBA0` / raw `0x000ABDE0–0x000ABFA0` (`[start,end)`); SHA256 `0cb97101376a22477c6eadc6c851ea9d4687f2e8b7fcb709cd6ae83bac2a397a`

```asm
004ac9e0 <.data+0xabde0>:
  4ac9e0:	55                   	push   ebp
  4ac9e1:	8b ec                	mov    ebp,esp
  4ac9e3:	6a ff                	push   0xffffffff
  4ac9e5:	68 c8 83 93 00       	push   0x9383c8
  4ac9ea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ac9f0:	50                   	push   eax
  4ac9f1:	83 ec 0c             	sub    esp,0xc
  4ac9f4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ac9f9:	33 c5                	xor    eax,ebp
  4ac9fb:	50                   	push   eax
  4ac9fc:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ac9ff:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4aca05:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4aca08:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4aca0b:	33 c0                	xor    eax,eax
  4aca0d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4aca10:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4aca13:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4aca16:	8b 0d 7c 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe187c
  4aca1c:	51                   	push   ecx
  4aca1d:	8d 45 e8             	lea    eax,[ebp-0x18]
  4aca20:	e8 4b 01 00 00       	call   0x4acb70
  4aca25:	83 c4 04             	add    esp,0x4
  4aca28:	b8 01 00 00 00       	mov    eax,0x1
  4aca2d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4aca30:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4aca37:	59                   	pop    ecx
  4aca38:	8b e5                	mov    esp,ebp
  4aca3a:	5d                   	pop    ebp
  4aca3b:	c3                   	ret
  4aca3c:	cc                   	int3
  4aca3d:	cc                   	int3
  4aca3e:	cc                   	int3
  4aca3f:	cc                   	int3
  4aca40:	55                   	push   ebp
  4aca41:	8b ec                	mov    ebp,esp
  4aca43:	6a ff                	push   0xffffffff
  4aca45:	68 c8 83 93 00       	push   0x9383c8
  4aca4a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4aca50:	50                   	push   eax
  4aca51:	83 ec 0c             	sub    esp,0xc
  4aca54:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4aca59:	33 c5                	xor    eax,ebp
  4aca5b:	50                   	push   eax
  4aca5c:	8d 45 f4             	lea    eax,[ebp-0xc]
  4aca5f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4aca65:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4aca68:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4aca6b:	33 c0                	xor    eax,eax
  4aca6d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4aca70:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4aca73:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4aca76:	8b 0d 80 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe1880
  4aca7c:	51                   	push   ecx
  4aca7d:	8d 55 e8             	lea    edx,[ebp-0x18]
  4aca80:	52                   	push   edx
  4aca81:	e8 0a 05 00 00       	call   0x4acf90
  4aca86:	83 c4 08             	add    esp,0x8
  4aca89:	b8 01 00 00 00       	mov    eax,0x1
  4aca8e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4aca91:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4aca98:	59                   	pop    ecx
  4aca99:	8b e5                	mov    esp,ebp
  4aca9b:	5d                   	pop    ebp
  4aca9c:	c3                   	ret
  4aca9d:	cc                   	int3
  4aca9e:	cc                   	int3
  4aca9f:	cc                   	int3
  4acaa0:	55                   	push   ebp
  4acaa1:	8b ec                	mov    ebp,esp
  4acaa3:	83 ec 18             	sub    esp,0x18
  4acaa6:	a1 0c 18 fe 00       	mov    eax,ds:0xfe180c
  4acaab:	8b 0d 04 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe1804
  4acab1:	53                   	push   ebx
  4acab2:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4acab5:	56                   	push   esi
  4acab6:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4acab9:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  4acabc:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4acabe:	57                   	push   edi
  4acabf:	83 c8 ff             	or     eax,0xffffffff
  4acac2:	e8 29 86 24 00       	call   0x6f50f0
  4acac7:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4acaca:	83 f9 03             	cmp    ecx,0x3
  4acacd:	74 26                	je     0x4acaf5
  4acacf:	83 f9 04             	cmp    ecx,0x4
  4acad2:	75 5f                	jne    0x4acb33
  4acad4:	8b 30                	mov    esi,DWORD PTR [eax]
  4acad6:	83 c6 10             	add    esi,0x10
  4acad9:	8d 7d f8             	lea    edi,[ebp-0x8]
  4acadc:	e8 7f ac 24 00       	call   0x6f7760
  4acae1:	85 c0                	test   eax,eax
  4acae3:	74 4e                	je     0x4acb33
  4acae5:	dd 45 f8             	fld    QWORD PTR [ebp-0x8]
  4acae8:	c7 45 f8 03 00 00 00 	mov    DWORD PTR [ebp-0x8],0x3
  4acaef:	dd 5d f0             	fstp   QWORD PTR [ebp-0x10]
  4acaf2:	8d 45 f0             	lea    eax,[ebp-0x10]
  4acaf5:	dd 00                	fld    QWORD PTR [eax]
  4acaf7:	dd 5d f8             	fstp   QWORD PTR [ebp-0x8]
  4acafa:	dd 45 f8             	fld    QWORD PTR [ebp-0x8]
  4acafd:	db 5d 08             	fistp  DWORD PTR [ebp+0x8]
  4acb00:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4acb03:	89 55 fc             	mov    DWORD PTR [ebp-0x4],edx
  4acb06:	8b 3b                	mov    edi,DWORD PTR [ebx]
  4acb08:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  4acb0b:	83 ee 20             	sub    esi,0x20
  4acb0e:	83 7e 08 04          	cmp    DWORD PTR [esi+0x8],0x4
  4acb12:	74 40                	je     0x4acb54
  4acb14:	e8 b7 ea 24 00       	call   0x6fb5d0
  4acb19:	85 c0                	test   eax,eax
  4acb1b:	75 1f                	jne    0x4acb3c
  4acb1d:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  4acb20:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  4acb23:	52                   	push   edx
  4acb24:	33 f6                	xor    esi,esi
  4acb26:	56                   	push   esi
  4acb27:	ff 55 e8             	call   DWORD PTR [ebp-0x18]
  4acb2a:	5f                   	pop    edi
  4acb2b:	5e                   	pop    esi
  4acb2c:	33 c0                	xor    eax,eax
  4acb2e:	5b                   	pop    ebx
  4acb2f:	8b e5                	mov    esp,ebp
  4acb31:	5d                   	pop    ebp
  4acb32:	c3                   	ret
  4acb33:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4acb3a:	eb ca                	jmp    0x4acb06
  4acb3c:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  4acb3f:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  4acb42:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  4acb45:	72 07                	jb     0x4acb4e
  4acb47:	8b c7                	mov    eax,edi
  4acb49:	e8 52 e8 24 00       	call   0x6fb3a0
  4acb4e:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  4acb51:	83 ee 20             	sub    esi,0x20
  4acb54:	8b 36                	mov    esi,DWORD PTR [esi]
  4acb56:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  4acb59:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  4acb5c:	52                   	push   edx
  4acb5d:	83 c6 10             	add    esi,0x10
  4acb60:	56                   	push   esi
  4acb61:	ff 55 e8             	call   DWORD PTR [ebp-0x18]
  4acb64:	5f                   	pop    edi
  4acb65:	5e                   	pop    esi
  4acb66:	33 c0                	xor    eax,eax
  4acb68:	5b                   	pop    ebx
  4acb69:	8b e5                	mov    esp,ebp
  4acb6b:	5d                   	pop    ebp
  4acb6c:	c3                   	ret
  4acb6d:	cc                   	int3
  4acb6e:	cc                   	int3
  4acb6f:	cc                   	int3
  4acb70:	55                   	push   ebp
  4acb71:	8b ec                	mov    ebp,esp
  4acb73:	8b 08                	mov    ecx,DWORD PTR [eax]
  4acb75:	83 ec 18             	sub    esp,0x18
  4acb78:	53                   	push   ebx
  4acb79:	8b 1d 04 18 fe 00    	mov    ebx,DWORD PTR ds:0xfe1804
  4acb7f:	83 c8 ff             	or     eax,0xffffffff
  4acb82:	e8 69 85 24 00       	call   0x6f50f0
  4acb87:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4acb8a:	83 f9 03             	cmp    ecx,0x3
  4acb8d:	74 2a                	je     0x4acbb9
  4acb8f:	83 f9 04             	cmp    ecx,0x4
  4acb92:	75 40                	jne    0x4acbd4
  4acb94:	56                   	push   esi
  4acb95:	8b 30                	mov    esi,DWORD PTR [eax]
  4acb97:	57                   	push   edi
  4acb98:	83 c6 10             	add    esi,0x10
  4acb9b:	8d 7d f8             	lea    edi,[ebp-0x8]
  4acb9e:	e8 bd          	call   0x6f7760
```

### quest_loader_entry: VA `0x00504370–0x00504428` / raw `0x00103770–0x00103828` (`[start,end)`); SHA256 `29476c39d5b7b227795758f444a76610378645578342f2071d6bbfe6371076b2`

```asm
00504370 <.data+0x103770>:
  504370:	55                   	push   ebp
  504371:	8b ec                	mov    ebp,esp
  504373:	6a ff                	push   0xffffffff
  504375:	68 a3 42 92 00       	push   0x9242a3
  50437a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  504380:	50                   	push   eax
  504381:	81 ec 78 01 00 00    	sub    esp,0x178
  504387:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50438c:	33 c5                	xor    eax,ebp
  50438e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  504391:	53                   	push   ebx
  504392:	56                   	push   esi
  504393:	50                   	push   eax
  504394:	8d 45 f4             	lea    eax,[ebp-0xc]
  504397:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  50439d:	33 f6                	xor    esi,esi
  50439f:	68 b8 00 00 00       	push   0xb8
  5043a4:	89 bd 8c fe ff ff    	mov    DWORD PTR [ebp-0x174],edi
  5043aa:	89 77 08             	mov    DWORD PTR [edi+0x8],esi
  5043ad:	e8 b6 ce 38 00       	call   0x891268
  5043b2:	83 c4 04             	add    esp,0x4
  5043b5:	3b c6                	cmp    eax,esi
  5043b7:	0f 84 65 01 00 00    	je     0x504522
  5043bd:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  5043c0:	89 00                	mov    DWORD PTR [eax],eax
  5043c2:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  5043c5:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  5043c8:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  5043cb:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  5043ce:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  5043d1:	bb 01 00 00 00       	mov    ebx,0x1
  5043d6:	88 98 b4 00 00 00    	mov    BYTE PTR [eax+0xb4],bl
  5043dc:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  5043df:	88 99 b5 00 00 00    	mov    BYTE PTR [ecx+0xb5],bl
  5043e5:	57                   	push   edi
  5043e6:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5043e9:	e8 52 03 00 00       	call   0x504740
  5043ee:	57                   	push   edi
  5043ef:	e8 7c 11 00 00       	call   0x505570
  5043f4:	8d 95 48 ff ff ff    	lea    edx,[ebp-0xb8]
  5043fa:	52                   	push   edx
  5043fb:	e8 20 b5 ff ff       	call   0x4ff920
  504400:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  504403:	c7 85 48 ff ff ff 61 	mov    DWORD PTR [ebp-0xb8],0xea61
  50440a:	ea 00 00 
  50440d:	c7 85 4c ff ff ff 02 	mov    DWORD PTR [ebp-0xb4],0x2
  504414:	00 00 00 
  504417:	84 1d e4 5a fe 00    	test   BYTE PTR ds:0xfe5ae4,bl
  50441d:	75 24                	jne    0x504443
  50441f:	09 1d e4 5a fe 00    	or     DWORD PTR ds:0xfe5ae4,ebx
  504425:	68 c4 5a         	push   0xfe5ac4
```

### quest_load_QI: VA `0x00504740–0x0050480A` / raw `0x00103B40–0x00103C0A` (`[start,end)`); SHA256 `bb15a0aa6261c8dc271d83f449073c44a4b2edc2562c9aff83def073a1cc4aab`

```asm
00504740 <.data+0x103b40>:
  504740:	55                   	push   ebp
  504741:	8b ec                	mov    ebp,esp
  504743:	83 e4 f8             	and    esp,0xfffffff8
  504746:	6a ff                	push   0xffffffff
  504748:	68 3d 42 92 00       	push   0x92423d
  50474d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  504753:	50                   	push   eax
  504754:	81 ec 48 02 00 00    	sub    esp,0x248
  50475a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50475f:	33 c4                	xor    eax,esp
  504761:	89 84 24 40 02 00 00 	mov    DWORD PTR [esp+0x240],eax
  504768:	53                   	push   ebx
  504769:	56                   	push   esi
  50476a:	57                   	push   edi
  50476b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  504770:	33 c4                	xor    eax,esp
  504772:	50                   	push   eax
  504773:	8d 84 24 58 02 00 00 	lea    eax,[esp+0x258]
  50477a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  504780:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  504783:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50478a:	51                   	push   ecx
  50478b:	b9 48 db c0 00       	mov    ecx,0xc0db48
  504790:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  504794:	e8 97 a6 22 00       	call   0x72ee30
  504799:	33 ff                	xor    edi,edi
  50479b:	89 bc 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],edi
  5047a2:	8b 8c 24 4c 01 00 00 	mov    ecx,DWORD PTR [esp+0x14c]
  5047a9:	bb 10 00 00 00       	mov    ebx,0x10
  5047ae:	39 9c 24 60 01 00 00 	cmp    DWORD PTR [esp+0x160],ebx
  5047b5:	73 07                	jae    0x5047be
  5047b7:	8d 8c 24 4c 01 00 00 	lea    ecx,[esp+0x14c]
  5047be:	57                   	push   edi
  5047bf:	8d b4 24 30 01 00 00 	lea    esi,[esp+0x130]
  5047c6:	e8 45 a9 22 00       	call   0x72f110
  5047cb:	80 bc 24 70 01 00 00 	cmp    BYTE PTR [esp+0x170],0x0
  5047d2:	00 
  5047d3:	74 5c                	je     0x504831
  5047d5:	c7 84 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],0xffffffff
  5047dc:	ff ff ff ff 
  5047e0:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  5047e7:	94 23 bf 00 
  5047eb:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  5047f2:	72 10                	jb     0x504804
  5047f4:	8b 94 24 78 01 00 00 	mov    edx,DWORD PTR [esp+0x178]
  5047fb:	52                   	push   edx
  5047fc:	e8 0b ca 38 00       	call   0x89120c
  504801:	83 c4 04             	add    esp,0x4
  504804:	8d 8c 24 2c 01 00  	lea    ecx,[esp+0x12c]
```

### quest_load_QT: VA `0x00505570–0x00505600` / raw `0x00104970–0x00104A00` (`[start,end)`); SHA256 `d95da1fd603a3b2dd86d23d29d10b3cfa367a8aeb8520c68c938f4bb6d6154d9`

```asm
00505570 <.data+0x104970>:
  505570:	55                   	push   ebp
  505571:	8b ec                	mov    ebp,esp
  505573:	83 e4 f8             	and    esp,0xfffffff8
  505576:	6a ff                	push   0xffffffff
  505578:	68 7b 28 92 00       	push   0x92287b
  50557d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  505583:	50                   	push   eax
  505584:	81 ec 98 00 00 00    	sub    esp,0x98
  50558a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50558f:	33 c4                	xor    eax,esp
  505591:	89 84 24 90 00 00 00 	mov    DWORD PTR [esp+0x90],eax
  505598:	53                   	push   ebx
  505599:	56                   	push   esi
  50559a:	57                   	push   edi
  50559b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5055a0:	33 c4                	xor    eax,esp
  5055a2:	50                   	push   eax
  5055a3:	8d 84 24 a8 00 00 00 	lea    eax,[esp+0xa8]
  5055aa:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5055b0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5055b3:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  5055b7:	51                   	push   ecx
  5055b8:	b9 5c db c0 00       	mov    ecx,0xc0db5c
  5055bd:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  5055c1:	e8 6a 98 22 00       	call   0x72ee30
  5055c6:	33 db                	xor    ebx,ebx
  5055c8:	89 9c 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],ebx
  5055cf:	8b 4c 24 44          	mov    ecx,DWORD PTR [esp+0x44]
  5055d3:	bf 10 00 00 00       	mov    edi,0x10
  5055d8:	39 7c 24 58          	cmp    DWORD PTR [esp+0x58],edi
  5055dc:	73 04                	jae    0x5055e2
  5055de:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  5055e2:	53                   	push   ebx
  5055e3:	8d 74 24 28          	lea    esi,[esp+0x28]
  5055e7:	e8 24 9b 22 00       	call   0x72f110
  5055ec:	38 5c 24 68          	cmp    BYTE PTR [esp+0x68],bl
  5055f0:	74 4f                	je     0x505641
  5055f2:	c7 84 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],0xffffffff
  5055f9:	ff ff ff ff 
  5055fd:	c7 44 24     	mov    DWORD PTR [esp+0x24],0xbf2394
  505604:	 
```

### npc_dialog_ui: VA `0x00636D00–0x00636ED0` / raw `0x00236100–0x002362D0` (`[start,end)`); SHA256 `a9fa761a6648e3e69de77013be9317aa349b8e9177db9654f12087484a01d16b`

```asm
00636d00 <.data+0x236100>:
  636d00:	00 64 89 0d          	add    BYTE PTR [ecx+ecx*4+0xd],ah
  636d04:	00 00                	add    BYTE PTR [eax],al
  636d06:	00 00                	add    BYTE PTR [eax],al
  636d08:	59                   	pop    ecx
  636d09:	5e                   	pop    esi
  636d0a:	5b                   	pop    ebx
  636d0b:	8b 4c 24 74          	mov    ecx,DWORD PTR [esp+0x74]
  636d0f:	33 cc                	xor    ecx,esp
  636d11:	e8 eb a2 25 00       	call   0x891001
  636d16:	8b e5                	mov    esp,ebp
  636d18:	5d                   	pop    ebp
  636d19:	c3                   	ret
  636d1a:	cc                   	int3
  636d1b:	cc                   	int3
  636d1c:	cc                   	int3
  636d1d:	cc                   	int3
  636d1e:	cc                   	int3
  636d1f:	cc                   	int3
  636d20:	51                   	push   ecx
  636d21:	8b 86 94 00 00 00    	mov    eax,DWORD PTR [esi+0x94]
  636d27:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  636d2a:	2b 50 14             	sub    edx,DWORD PTR [eax+0x14]
  636d2d:	8b 8e 98 00 00 00    	mov    ecx,DWORD PTR [esi+0x98]
  636d33:	41                   	inc    ecx
  636d34:	c1 fa 02             	sar    edx,0x2
  636d37:	3b ca                	cmp    ecx,edx
  636d39:	7d 14                	jge    0x636d4f
  636d3b:	89 8e 98 00 00 00    	mov    DWORD PTR [esi+0x98],ecx
  636d41:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  636d44:	8b 0c 88             	mov    ecx,DWORD PTR [eax+ecx*4]
  636d47:	51                   	push   ecx
  636d48:	8b c6                	mov    eax,esi
  636d4a:	e8 c1 f1 ff ff       	call   0x635f10
  636d4f:	56                   	push   esi
  636d50:	e8 fb f2 ff ff       	call   0x636050
  636d55:	59                   	pop    ecx
  636d56:	c3                   	ret
  636d57:	cc                   	int3
  636d58:	cc                   	int3
  636d59:	cc                   	int3
  636d5a:	cc                   	int3
  636d5b:	cc                   	int3
  636d5c:	cc                   	int3
  636d5d:	cc                   	int3
  636d5e:	cc                   	int3
  636d5f:	cc                   	int3
  636d60:	83 b8 ac 00 00 00 00 	cmp    DWORD PTR [eax+0xac],0x0
  636d67:	57                   	push   edi
  636d68:	74 3f                	je     0x636da9
  636d6a:	8b 88 ac 00 00 00    	mov    ecx,DWORD PTR [eax+0xac]
  636d70:	85 c9                	test   ecx,ecx
  636d72:	74 35                	je     0x636da9
  636d74:	8b b8 a4 00 00 00    	mov    edi,DWORD PTR [eax+0xa4]
  636d7a:	ff 80 a8 00 00 00    	inc    DWORD PTR [eax+0xa8]
  636d80:	03 ff                	add    edi,edi
  636d82:	03 ff                	add    edi,edi
  636d84:	3b b8 a8 00 00 00    	cmp    edi,DWORD PTR [eax+0xa8]
  636d8a:	77 0a                	ja     0x636d96
  636d8c:	c7 80 a8 00 00 00 00 	mov    DWORD PTR [eax+0xa8],0x0
  636d93:	00 00 00 
  636d96:	49                   	dec    ecx
  636d97:	89 88 ac 00 00 00    	mov    DWORD PTR [eax+0xac],ecx
  636d9d:	75 0a                	jne    0x636da9
  636d9f:	c7 80 a8 00 00 00 00 	mov    DWORD PTR [eax+0xa8],0x0
  636da6:	00 00 00 
  636da9:	50                   	push   eax
  636daa:	e8 a1 f2 ff ff       	call   0x636050
  636daf:	5f                   	pop    edi
  636db0:	c3                   	ret
  636db1:	cc                   	int3
  636db2:	cc                   	int3
  636db3:	cc                   	int3
  636db4:	cc                   	int3
  636db5:	cc                   	int3
  636db6:	cc                   	int3
  636db7:	cc                   	int3
  636db8:	cc                   	int3
  636db9:	cc                   	int3
  636dba:	cc                   	int3
  636dbb:	cc                   	int3
  636dbc:	cc                   	int3
  636dbd:	cc                   	int3
  636dbe:	cc                   	int3
  636dbf:	cc                   	int3
  636dc0:	55                   	push   ebp
  636dc1:	8b ec                	mov    ebp,esp
  636dc3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  636dc6:	83 78 10 64          	cmp    DWORD PTR [eax+0x10],0x64
  636dca:	75 09                	jne    0x636dd5
  636dcc:	57                   	push   edi
  636dcd:	8b f9                	mov    edi,ecx
  636dcf:	e8 9c fd ff ff       	call   0x636b70
  636dd4:	5f                   	pop    edi
  636dd5:	5d                   	pop    ebp
  636dd6:	c2 04 00             	ret    0x4
  636dd9:	cc                   	int3
  636dda:	cc                   	int3
  636ddb:	cc                   	int3
  636ddc:	cc                   	int3
  636ddd:	cc                   	int3
  636dde:	cc                   	int3
  636ddf:	cc                   	int3
  636de0:	55                   	push   ebp
  636de1:	8b ec                	mov    ebp,esp
  636de3:	56                   	push   esi
  636de4:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  636de7:	57                   	push   edi
  636de8:	8b f9                	mov    edi,ecx
  636dea:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636df0:	8b 01                	mov    eax,DWORD PTR [ecx]
  636df2:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  636df5:	56                   	push   esi
  636df6:	ff d2                	call   edx
  636df8:	81 7e 10 02 44 0f 00 	cmp    DWORD PTR [esi+0x10],0xf4402
  636dff:	75 05                	jne    0x636e06
  636e01:	e8 0a 00 00 00       	call   0x636e10
  636e06:	5f                   	pop    edi
  636e07:	5e                   	pop    esi
  636e08:	5d                   	pop    ebp
  636e09:	c2 04 00             	ret    0x4
  636e0c:	cc                   	int3
  636e0d:	cc                   	int3
  636e0e:	cc                   	int3
  636e0f:	cc                   	int3
  636e10:	55                   	push   ebp
  636e11:	8b ec                	mov    ebp,esp
  636e13:	51                   	push   ecx
  636e14:	85 f6                	test   esi,esi
  636e16:	74 28                	je     0x636e40
  636e18:	8b 06                	mov    eax,DWORD PTR [esi]
  636e1a:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  636e1d:	8b ce                	mov    ecx,esi
  636e1f:	ff d2                	call   edx
  636e21:	3d bd 05 01 00       	cmp    eax,0x105bd
  636e26:	75 04                	jne    0x636e2c
  636e28:	8b c6                	mov    eax,esi
  636e2a:	eb 16                	jmp    0x636e42
  636e2c:	6a 00                	push   0x0
  636e2e:	68 c0 1f bf 00       	push   0xbf1fc0
  636e33:	68 18 21 bf 00       	push   0xbf2118
  636e38:	6a 00                	push   0x0
  636e3a:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  636e40:	33 c0                	xor    eax,eax
  636e42:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  636e45:	3d a7 06 00 00       	cmp    eax,0x6a7
  636e4a:	75 6d                	jne    0x636eb9
  636e4c:	83 bf 88 00 00 00 00 	cmp    DWORD PTR [edi+0x88],0x0
  636e53:	74 77                	je     0x636ecc
  636e55:	b8 01 00 00 00       	mov    eax,0x1
  636e5a:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  636e60:	75 13                	jne    0x636e75
  636e62:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  636e68:	68 10 cf bc 00       	push   0xbccf10
  636e6d:	e8 a8 b4 25 00       	call   0x89231a
  636e72:	83 c4 04             	add    esp,0x4
  636e75:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  636e7c:	8b 8f 88 00 00 00    	mov    ecx,DWORD PTR [edi+0x88]
  636e82:	66 8b 11             	mov    dx,WORD PTR [ecx]
  636e85:	b8 36 00 00 00       	mov    eax,0x36
  636e8a:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  636e8e:	66 89 55 fe          	mov    WORD PTR [ebp-0x2],dx
  636e92:	75 2c                	jne    0x636ec0
  636e94:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  636e9a:	8b 01                	mov    eax,DWORD PTR [ecx]
  636e9c:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  636e9f:	6a 04                	push   0x4
  636ea1:	8d 55 fc             	lea    edx,[ebp-0x4]
  636ea4:	52                   	push   edx
  636ea5:	6a 00                	push   0x0
  636ea7:	ff d0                	call   eax
  636ea9:	8b 17                	mov    edx,DWORD PTR [edi]
  636eab:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  636eb1:	8b cf                	mov    ecx,edi
  636eb3:	ff d0                	call   eax
  636eb5:	8b e5                	mov    esp,ebp
  636eb7:	5d                   	pop    ebp
  636eb8:	c3                   	ret
  636eb9:	3d a8 06 00 00       	cmp    eax,0x6a8
  636ebe:	75 0c                	jne    0x636ecc
  636ec0:	8b 17                	mov    edx,DWORD PTR [edi]
  636ec2:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  636ec8:	8b cf                	mov    ecx,edi
  636eca:	ff d0                	call   eax
  636ecc:	8b e5                	mov    esp,ebp
  636ece:	5d                   	pop    ebp
  636ecf:	c3                   	ret
```

### npc_record_lookup: VA `0x00500F90–0x00501050` / raw `0x00100390–0x00100450` (`[start,end)`); SHA256 `ae0649a62c91acd750fffb487cd1d5d13222970cb845c7e49bdc24e536780db4`

```asm
00500f90 <.data+0x100390>:
  500f90:	55                   	push   ebp
  500f91:	8b ec                	mov    ebp,esp
  500f93:	83 ec 08             	sub    esp,0x8
  500f96:	56                   	push   esi
  500f97:	8b b1 ac 5e 00 00    	mov    esi,DWORD PTR [ecx+0x5eac]
  500f9d:	8d 55 fc             	lea    edx,[ebp-0x4]
  500fa0:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500fa3:	52                   	push   edx
  500fa4:	8d 45 f8             	lea    eax,[ebp-0x8]
  500fa7:	8b ce                	mov    ecx,esi
  500fa9:	e8 72 2d 00 00       	call   0x503d20
  500fae:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  500fb1:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500fb4:	5e                   	pop    esi
  500fb5:	74 07                	je     0x500fbe
  500fb7:	83 c0 10             	add    eax,0x10
  500fba:	8b e5                	mov    esp,ebp
  500fbc:	5d                   	pop    ebp
  500fbd:	c3                   	ret
  500fbe:	33 c0                	xor    eax,eax
  500fc0:	8b e5                	mov    esp,ebp
  500fc2:	5d                   	pop    ebp
  500fc3:	c3                   	ret
  500fc4:	cc                   	int3
  500fc5:	cc                   	int3
  500fc6:	cc                   	int3
  500fc7:	cc                   	int3
  500fc8:	cc                   	int3
  500fc9:	cc                   	int3
  500fca:	cc                   	int3
  500fcb:	cc                   	int3
  500fcc:	cc                   	int3
  500fcd:	cc                   	int3
  500fce:	cc                   	int3
  500fcf:	cc                   	int3
  500fd0:	55                   	push   ebp
  500fd1:	8b ec                	mov    ebp,esp
  500fd3:	83 e4 f8             	and    esp,0xfffffff8
  500fd6:	6a ff                	push   0xffffffff
  500fd8:	68 86 01 94 00       	push   0x940186
  500fdd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  500fe3:	50                   	push   eax
  500fe4:	83 ec 40             	sub    esp,0x40
  500fe7:	53                   	push   ebx
  500fe8:	56                   	push   esi
  500fe9:	57                   	push   edi
  500fea:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  500fef:	33 c4                	xor    eax,esp
  500ff1:	50                   	push   eax
  500ff2:	8d 44 24 50          	lea    eax,[esp+0x50]
  500ff6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  500ffc:	33 c9                	xor    ecx,ecx
  500ffe:	33 db                	xor    ebx,ebx
  501000:	89 4c 24 3c          	mov    DWORD PTR [esp+0x3c],ecx
  501004:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  501008:	89 4c 24 44          	mov    DWORD PTR [esp+0x44],ecx
  50100c:	89 4c 24 58          	mov    DWORD PTR [esp+0x58],ecx
  501010:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  501014:	8d 79 01             	lea    edi,[ecx+0x1]
  501017:	be 10 02 00 00       	mov    esi,0x210
  50101c:	8d 64 24 00          	lea    esp,[esp+0x0]
  501020:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  501027:	75 27                	jne    0x501050
  501029:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  501030:	c6 44 24 58 01       	mov    BYTE PTR [esp+0x58],0x1
  501035:	e8 56 05 fe ff       	call   0x4e1590
  50103a:	68 80 cc bc 00       	push   0xbccc80
  50103f:	e8 d6 12 39 00       	call   0x89231a
  501044:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  501048:	83 c4 04             	add    esp,0x4
  50104b:	c6 44 24 58 00       	mov    BYTE PTR [esp+0x58],0x0
```

### quest_item_writer: VA `0x0053FD70–0x0053FEB9` / raw `0x0013F170–0x0013F2B9` (`[start,end)`); SHA256 `ea3e7fc01a778a103c20e4ab4f3b9a9c28f226562d68e9d8e99d5fd22a083280`

```asm
0053fd70 <.data+0x13f170>:
  53fd70:	eb 04                	jmp    0x53fd76
  53fd72:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  53fd76:	68 e4 f4 c0 00       	push   0xc0f4e4
  53fd7b:	8b c3                	mov    eax,ebx
  53fd7d:	e8 5e e5 1e 00       	call   0x72e2e0
  53fd82:	8b f8                	mov    edi,eax
  53fd84:	68 ec f4 c0 00       	push   0xc0f4ec
  53fd89:	8b c3                	mov    eax,ebx
  53fd8b:	e8 50 e5 1e 00       	call   0x72e2e0
  53fd90:	8b f0                	mov    esi,eax
  53fd92:	68 f8 f4 c0 00       	push   0xc0f4f8
  53fd97:	8b c3                	mov    eax,ebx
  53fd99:	e8 42 e5 1e 00       	call   0x72e2e0
  53fd9e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  53fda2:	68 0c f5 c0 00       	push   0xc0f50c
  53fda7:	8b c3                	mov    eax,ebx
  53fda9:	e8 32 e5 1e 00       	call   0x72e2e0
  53fdae:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  53fdb2:	85 ff                	test   edi,edi
  53fdb4:	74 0c                	je     0x53fdc2
  53fdb6:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  53fdba:	51                   	push   ecx
  53fdbb:	8b c7                	mov    eax,edi
  53fdbd:	e8 ee 00 00 00       	call   0x53feb0
  53fdc2:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  53fdc6:	85 f6                	test   esi,esi
  53fdc8:	74 0b                	je     0x53fdd5
  53fdca:	8d 57 10             	lea    edx,[edi+0x10]
  53fdcd:	52                   	push   edx
  53fdce:	8b c6                	mov    eax,esi
  53fdd0:	e8 db 00 00 00       	call   0x53feb0
  53fdd5:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  53fdd9:	85 c0                	test   eax,eax
  53fddb:	74 09                	je     0x53fde6
  53fddd:	8d 4f 20             	lea    ecx,[edi+0x20]
  53fde0:	51                   	push   ecx
  53fde1:	e8 ca 00 00 00       	call   0x53feb0
  53fde6:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  53fdea:	85 c0                	test   eax,eax
  53fdec:	74 09                	je     0x53fdf7
  53fdee:	8d 57 30             	lea    edx,[edi+0x30]
  53fdf1:	52                   	push   edx
  53fdf2:	e8 b9 00 00 00       	call   0x53feb0
  53fdf7:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  53fdfb:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  53fdff:	8d 7c 24 24          	lea    edi,[esp+0x24]
  53fe03:	be dc 18 fe 00       	mov    esi,0xfe18dc
  53fe08:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  53fe0c:	e8 0f f1 03 00       	call   0x57ef20
  53fe11:	50                   	push   eax
  53fe12:	56                   	push   esi
  53fe13:	8d 74 24 34          	lea    esi,[esp+0x34]
  53fe17:	e8 34 ea 03 00       	call   0x57e850
  53fe1c:	33 f6                	xor    esi,esi
  53fe1e:	8b 5b 40             	mov    ebx,DWORD PTR [ebx+0x40]
  53fe21:	3b de                	cmp    ebx,esi
  53fe23:	0f 85 cc fe ff ff    	jne    0x53fcf5
  53fe29:	bb 10 00 00 00       	mov    ebx,0x10
  53fe2e:	c7 84 24 c0 00 00 00 	mov    DWORD PTR [esp+0xc0],0xffffffff
  53fe35:	ff ff ff ff 
  53fe39:	c7 44 24 34 94 23 bf 	mov    DWORD PTR [esp+0x34],0xbf2394
  53fe40:	00 
  53fe41:	39 9c 24 94 00 00 00 	cmp    DWORD PTR [esp+0x94],ebx
  53fe48:	72 10                	jb     0x53fe5a
  53fe4a:	8b 8c 24 80 00 00 00 	mov    ecx,DWORD PTR [esp+0x80]
  53fe51:	51                   	push   ecx
  53fe52:	e8 b5 13 35 00       	call   0x89120c
  53fe57:	83 c4 04             	add    esp,0x4
  53fe5a:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  53fe5e:	c7 84 24 94 00 00 00 	mov    DWORD PTR [esp+0x94],0xf
  53fe65:	0f 00 00 00 
  53fe69:	c7 84 24 90 00 00 00 	mov    DWORD PTR [esp+0x90],0x0
  53fe70:	00 00 00 00 
  53fe74:	c6 84 24 80 00 00 00 	mov    BYTE PTR [esp+0x80],0x0
  53fe7b:	00 
  53fe7c:	e8 bf e1 1e 00       	call   0x72e040
  53fe81:	8b 8c 24 b8 00 00 00 	mov    ecx,DWORD PTR [esp+0xb8]
  53fe88:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  53fe8f:	59                   	pop    ecx
  53fe90:	5f                   	pop    edi
  53fe91:	5e                   	pop    esi
  53fe92:	5b                   	pop    ebx
  53fe93:	8b 8c 24 a0 00 00 00 	mov    ecx,DWORD PTR [esp+0xa0]
  53fe9a:	33 cc                	xor    ecx,esp
  53fe9c:	e8 60 11 35 00       	call   0x891001
  53fea1:	8b e5                	mov    esp,ebp
  53fea3:	5d                   	pop    ebp
  53fea4:	c3                   	ret
  53fea5:	cc                   	int3
  53fea6:	cc                   	int3
  53fea7:	cc                   	int3
  53fea8:	cc                   	int3
  53fea9:	cc                   	int3
  53feaa:	cc                   	int3
  53feab:	cc                   	int3
  53feac:	cc                   	int3
  53fead:	cc                   	int3
  53feae:	cc                   	int3
  53feaf:	cc                   	int3
  53feb0:	55                   	push   ebp
  53feb1:	8b ec                	mov    ebp,esp
  53feb3:	51                   	push   ecx
  53feb4:	56                   	push   esi
  53feb5:	68 a0 f4 c0        	push   0xc0f4a0
```

### scenario_scene_dispatch: VA `0x004C4670–0x004C4750` / raw `0x000C3A70–0x000C3B50` (`[start,end)`); SHA256 `96233882f6fd28f6b106524c13692d7e9122e6cf84fce19698a125b91ec96856`

```asm
004c4670 <.data+0xc3a70>:
  4c4670:	55                   	push   ebp
  4c4671:	8b ec                	mov    ebp,esp
  4c4673:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c4676:	53                   	push   ebx
  4c4677:	56                   	push   esi
  4c4678:	57                   	push   edi
  4c4679:	0f bf f8             	movsx  edi,ax
  4c467c:	8b f1                	mov    esi,ecx
  4c467e:	8b 9c fe ac 5e 00 00 	mov    ebx,DWORD PTR [esi+edi*8+0x5eac]
  4c4685:	85 db                	test   ebx,ebx
  4c4687:	75 17                	jne    0x4c46a0
  4c4689:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c468c:	50                   	push   eax
  4c468d:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4c4690:	50                   	push   eax
  4c4691:	51                   	push   ecx
  4c4692:	8b ce                	mov    ecx,esi
  4c4694:	e8 97 93 03 00       	call   0x4fda30
  4c4699:	5f                   	pop    edi
  4c469a:	5e                   	pop    esi
  4c469b:	5b                   	pop    ebx
  4c469c:	5d                   	pop    ebp
  4c469d:	c2 0c 00             	ret    0xc
  4c46a0:	8b 94 fe b0 5e 00 00 	mov    edx,DWORD PTR [esi+edi*8+0x5eb0]
  4c46a7:	6a 06                	push   0x6
  4c46a9:	68 6c 6c bf 00       	push   0xbf6c6c
  4c46ae:	52                   	push   edx
  4c46af:	e8 0a e2 3c 00       	call   0x8928be
  4c46b4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  4c46b7:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4c46ba:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4c46bd:	83 c4 0c             	add    esp,0xc
  4c46c0:	50                   	push   eax
  4c46c1:	51                   	push   ecx
  4c46c2:	52                   	push   edx
  4c46c3:	8b ce                	mov    ecx,esi
  4c46c5:	ff d3                	call   ebx
  4c46c7:	8b d8                	mov    ebx,eax
  4c46c9:	81 fb 05 40 00 80    	cmp    ebx,0x80004005
  4c46cf:	75 16                	jne    0x4c46e7
  4c46d1:	8b 84 fe b0 5e 00 00 	mov    eax,DWORD PTR [esi+edi*8+0x5eb0]
  4c46d8:	50                   	push   eax
  4c46d9:	57                   	push   edi
  4c46da:	68 74 6c bf 00       	push   0xbf6c74
  4c46df:	e8 7c 94 22 00       	call   0x6edb60
  4c46e4:	83 c4 0c             	add    esp,0xc
  4c46e7:	5f                   	pop    edi
  4c46e8:	5e                   	pop    esi
  4c46e9:	8b c3                	mov    eax,ebx
  4c46eb:	5b                   	pop    ebx
  4c46ec:	5d                   	pop    ebp
  4c46ed:	c2 0c 00             	ret    0xc
  4c46f0:	8b c6                	mov    eax,esi
  4c46f2:	e8 59 96 fe ff       	call   0x4add50
  4c46f7:	68 a8 5e 00 00       	push   0x5ea8
  4c46fc:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4c4702:	6a 00                	push   0x0
  4c4704:	50                   	push   eax
  4c4705:	c7 06 b4 73 c0 00    	mov    DWORD PTR [esi],0xc073b4
  4c470b:	c7 05 74 a6 d6 00 46 	mov    DWORD PTR ds:0xd6a674,0x53434546
  4c4712:	45 43 53 
  4c4715:	e8 46 a1 3d 00       	call   0x89e860
  4c471a:	b8 75 23 bf 00       	mov    eax,0xbf2375
  4c471f:	89 86 50 5f 00 00    	mov    DWORD PTR [esi+0x5f50],eax
  4c4725:	89 86 20 5f 00 00    	mov    DWORD PTR [esi+0x5f20],eax
  4c472b:	83 c4 0c             	add    esp,0xc
  4c472e:	c7 86 4c 5f 00 00 30 	mov    DWORD PTR [esi+0x5f4c],0x4c5930
  4c4735:	59 4c 00 
  4c4738:	c7 86 1c 5f 00 00 40 	mov    DWORD PTR [esi+0x5f1c],0x436c40
  4c473f:	6c 43 00 
  4c4742:	8b c6                	mov    eax,esi
  4c4744:	c3                   	ret
  4c4745:	cc                   	int3
  4c4746:	cc                   	int3
  4c4747:	cc                   	int3
  4c4748:	cc                   	int3
  4c4749:	cc                   	int3
  4c474a:	cc                   	int3
  4c474b:	cc                   	int3
  4c474c:	cc                   	int3
  4c474d:	cc                   	int3
  4c474e:	cc                   	int3
  4c474f:	cc                   	int3
```

### inbound_business: VA `0x004930E0–0x00493180` / raw `0x000924E0–0x00092580` (`[start,end)`); SHA256 `4db6a91cdf398da3ac39366a5b3809d3dc60f4928e3c1312890a4d973ce975fc`

```asm
004930e0 <.data+0x924e0>:
  4930e0:	55                   	push   ebp
  4930e1:	8b ec                	mov    ebp,esp
  4930e3:	51                   	push   ecx
  4930e4:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4930e7:	53                   	push   ebx
  4930e8:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  4930eb:	56                   	push   esi
  4930ec:	57                   	push   edi
  4930ed:	0f b7 38             	movzx  edi,WORD PTR [eax]
  4930f0:	8b f1                	mov    esi,ecx
  4930f2:	c6 45 ff 00          	mov    BYTE PTR [ebp-0x1],0x0
  4930f6:	85 db                	test   ebx,ebx
  4930f8:	75 0b                	jne    0x493105
  4930fa:	5f                   	pop    edi
  4930fb:	5e                   	pop    esi
  4930fc:	33 c0                	xor    eax,eax
  4930fe:	5b                   	pop    ebx
  4930ff:	8b e5                	mov    esp,ebp
  493101:	5d                   	pop    ebp
  493102:	c2 10 00             	ret    0x10
  493105:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  493108:	83 e8 02             	sub    eax,0x2
  49310b:	75 47                	jne    0x493154
  49310d:	53                   	push   ebx
  49310e:	57                   	push   edi
  49310f:	8d 86 e0 be 00 00    	lea    eax,[esi+0xbee0]
  493115:	e8 d6 80 24 00       	call   0x6db1f0
  49311a:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  493120:	8b 96 b8 00 00 00    	mov    edx,DWORD PTR [esi+0xb8]
  493126:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  493129:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  49312c:	57                   	push   edi
  49312d:	8d 8e b8 00 00 00    	lea    ecx,[esi+0xb8]
  493133:	53                   	push   ebx
  493134:	50                   	push   eax
  493135:	ff d2                	call   edx
  493137:	8b f8                	mov    edi,eax
  493139:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  49313f:	81 ff 00 01 00 00    	cmp    edi,0x100
  493145:	75 0d                	jne    0x493154
  493147:	83 be 8c be 00 00 00 	cmp    DWORD PTR [esi+0xbe8c],0x0
  49314e:	74 04                	je     0x493154
  493150:	c6 45 ff 01          	mov    BYTE PTR [ebp-0x1],0x1
  493154:	0f b6 45 ff          	movzx  eax,BYTE PTR [ebp-0x1]
  493158:	5f                   	pop    edi
  493159:	5e                   	pop    esi
  49315a:	5b                   	pop    ebx
  49315b:	8b e5                	mov    esp,ebp
  49315d:	5d                   	pop    ebp
  49315e:	c2 10 00             	ret    0x10
  493161:	cc                   	int3
  493162:	cc                   	int3
  493163:	cc                   	int3
  493164:	cc                   	int3
  493165:	cc                   	int3
  493166:	cc                   	int3
  493167:	cc                   	int3
  493168:	cc                   	int3
  493169:	cc                   	int3
  49316a:	cc                   	int3
  49316b:	cc                   	int3
  49316c:	cc                   	int3
  49316d:	cc                   	int3
  49316e:	cc                   	int3
  49316f:	cc                   	int3
  493170:	53                   	push   ebx
  493171:	56                   	push   esi
  493172:	57                   	push   edi
  493173:	bf 60 43 49 00       	mov    edi,0x494360
  493178:	33 db                	xor    ebx,ebx
  49317a:	8d 90 10 02 00 00    	lea    edx,[eax+0x210]
```

### scene_pair_reader: VA `0x00565720–0x0056583F` / raw `0x00164B20–0x00164C3F` (`[start,end)`); SHA256 `ae566213220a74b2609375f0f843bc1db51fa93805fc616cf6f90eb74083c3a4`

```asm
00565720 <.data+0x164b20>:
  565720:	55                   	push   ebp
  565721:	8b ec                	mov    ebp,esp
  565723:	83 e4 f8             	and    esp,0xfffffff8
  565726:	6a ff                	push   0xffffffff
  565728:	68 e8 fb 93 00       	push   0x93fbe8
  56572d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  565733:	50                   	push   eax
  565734:	83 ec 34             	sub    esp,0x34
  565737:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56573c:	33 c4                	xor    eax,esp
  56573e:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  565742:	53                   	push   ebx
  565743:	57                   	push   edi
  565744:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  565749:	33 c4                	xor    eax,esp
  56574b:	50                   	push   eax
  56574c:	8d 44 24 40          	lea    eax,[esp+0x40]
  565750:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  565756:	83 7e 28 00          	cmp    DWORD PTR [esi+0x28],0x0
  56575a:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  56575d:	c6 86 89 00 00 00 01 	mov    BYTE PTR [esi+0x89],0x1
  565764:	74 17                	je     0x56577d
  565766:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  565769:	50                   	push   eax
  56576a:	51                   	push   ecx
  56576b:	68 ac 06 c1 00       	push   0xc106ac
  565770:	e8 eb 83 18 00       	call   0x6edb60
  565775:	83 c4 0c             	add    esp,0xc
  565778:	e9 e8 02 00 00       	jmp    0x565a65
  56577d:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  565780:	bb 01 00 00 00       	mov    ebx,0x1
  565785:	89 56 38             	mov    DWORD PTR [esi+0x38],edx
  565788:	89 46 3c             	mov    DWORD PTR [esi+0x3c],eax
  56578b:	89 5e 28             	mov    DWORD PTR [esi+0x28],ebx
  56578e:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  565794:	75 29                	jne    0x5657bf
  565796:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  56579c:	c7 44 24 48 00 00 00 	mov    DWORD PTR [esp+0x48],0x0
  5657a3:	00 
  5657a4:	e8 d7 1c 02 00       	call   0x587480
  5657a9:	68 c0 cc bc 00       	push   0xbcccc0
  5657ae:	e8 67 cb 32 00       	call   0x89231a
  5657b3:	83 c4 04             	add    esp,0x4
  5657b6:	83 cf ff             	or     edi,0xffffffff
  5657b9:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  5657bd:	eb 03                	jmp    0x5657c2
  5657bf:	83 cf ff             	or     edi,0xffffffff
  5657c2:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  5657c9:	75 20                	jne    0x5657eb
  5657cb:	09 1d d0 ad fa 00    	or     DWORD PTR ds:0xfaadd0,ebx
  5657d1:	89 5c 24 48          	mov    DWORD PTR [esp+0x48],ebx
  5657d5:	e8 b6 81 1e 00       	call   0x74d990
  5657da:	68 70 cc bc 00       	push   0xbccc70
  5657df:	e8 36 cb 32 00       	call   0x89231a
  5657e4:	83 c4 04             	add    esp,0x4
  5657e7:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  5657eb:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  5657f2:	8b 0d bc 5b f9 00    	mov    ecx,DWORD PTR ds:0xf95bbc
  5657f8:	8b 15 c0 5b f9 00    	mov    edx,DWORD PTR ds:0xf95bc0
  5657fe:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  565802:	f3 0f 10 44 24 10    	movss  xmm0,DWORD PTR [esp+0x10]
  565808:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  56580c:	f3 0f 11 86 84 00 00 	movss  DWORD PTR [esi+0x84],xmm0
  565813:	00 
  565814:	75 24                	jne    0x56583a
  565816:	09 1d 90 43 f9 00    	or     DWORD PTR ds:0xf94390,ebx
  56581c:	c7 44 24 48 02 00 00 	mov    DWORD PTR [esp+0x48],0x2
  565823:	00 
  565824:	e8 67 bd f7 ff       	call   0x4e1590
  565829:	68 80 cc bc 00       	push   0xbccc80
  56582e:	e8 e7 ca 32 00       	call   0x89231a
  565833:	83 c4 04             	add    esp,0x4
  565836:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  56583a:	f6 05 d4 ad fa   	test   BYTE PTR ds:0xfaadd4,0x1
```

### scene_source_caller: VA `0x0047B5C0–0x0047B68A` / raw `0x0007A9C0–0x0007AA8A` (`[start,end)`); SHA256 `d9d09e21b34a5d808d3d4aa095d7ab5c2a3e91dbf3dad7d1aa3d26fdb99882b3`

```asm
0047b5c0 <.data+0x7a9c0>:
  47b5c0:	55                   	push   ebp
  47b5c1:	8b ec                	mov    ebp,esp
  47b5c3:	83 e4 f8             	and    esp,0xfffffff8
  47b5c6:	6a ff                	push   0xffffffff
  47b5c8:	68 7c 10 94 00       	push   0x94107c
  47b5cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b5d3:	50                   	push   eax
  47b5d4:	51                   	push   ecx
  47b5d5:	56                   	push   esi
  47b5d6:	57                   	push   edi
  47b5d7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b5dc:	33 c4                	xor    eax,esp
  47b5de:	50                   	push   eax
  47b5df:	8d 44 24 10          	lea    eax,[esp+0x10]
  47b5e3:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b5e9:	8b f9                	mov    edi,ecx
  47b5eb:	81 bf 48 02 00 00 61 	cmp    DWORD PTR [edi+0x248],0xea61
  47b5f2:	ea 00 00 
  47b5f5:	75 11                	jne    0x47b608
  47b5f7:	80 bf 6c 02 00 00 00 	cmp    BYTE PTR [edi+0x26c],0x0
  47b5fe:	75 4f                	jne    0x47b64f
  47b600:	57                   	push   edi
  47b601:	e8 4a 02 00 00       	call   0x47b850
  47b606:	eb 47                	jmp    0x47b64f
  47b608:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  47b60f:	75 29                	jne    0x47b63a
  47b611:	83 0d b8 73 fb 00 01 	or     DWORD PTR ds:0xfb73b8,0x1
  47b618:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  47b61f:	00 
  47b620:	e8 4b 4b 0e 00       	call   0x560170
  47b625:	68 10 d1 bc 00       	push   0xbcd110
  47b62a:	e8 eb 6c 41 00       	call   0x89231a
  47b62f:	83 c4 04             	add    esp,0x4
  47b632:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  47b639:	ff 
  47b63a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47b63d:	8b 8f 48 02 00 00    	mov    ecx,DWORD PTR [edi+0x248]
  47b643:	50                   	push   eax
  47b644:	51                   	push   ecx
  47b645:	be c0 73 fb 00       	mov    esi,0xfb73c0
  47b64a:	e8 d1 a0 0e 00       	call   0x565720
  47b64f:	f6 05 64 0f fc 00 01 	test   BYTE PTR ds:0xfc0f64,0x1
  47b656:	75 29                	jne    0x47b681
  47b658:	b8 01 00 00 00       	mov    eax,0x1
  47b65d:	09 05 64 0f fc 00    	or     DWORD PTR ds:0xfc0f64,eax
  47b663:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47b667:	e8 74 26 00 00       	call   0x47dce0
  47b66c:	68 f0 da bc 00       	push   0xbcdaf0
  47b671:	e8 a4 6c 41 00       	call   0x89231a
  47b676:	83 c4 04             	add    esp,0x4
  47b679:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  47b680:	ff 
  47b681:	8b 97 4c 02 00 00    	mov    edx,DWORD PTR [edi+0x24c]
  47b687:	8b 8f 48       	mov    ecx,DWORD PTR [edi+0x248]
```

### town_candidate: VA `0x004B9090–0x004B9230` / raw `0x000B8490–0x000B8630` (`[start,end)`); SHA256 `07917ce073bfcd3a4b454f891a397760d766f36c35fced7d2402b26ed97c849c`

```asm
004b9090 <.data+0xb8490>:
  4b9090:	55                   	push   ebp
  4b9091:	8b ec                	mov    ebp,esp
  4b9093:	83 e4 f8             	and    esp,0xfffffff8
  4b9096:	6a ff                	push   0xffffffff
  4b9098:	68 3e 71 94 00       	push   0x94713e
  4b909d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b90a3:	50                   	push   eax
  4b90a4:	83 ec 08             	sub    esp,0x8
  4b90a7:	53                   	push   ebx
  4b90a8:	56                   	push   esi
  4b90a9:	57                   	push   edi
  4b90aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b90af:	33 c4                	xor    eax,esp
  4b90b1:	50                   	push   eax
  4b90b2:	8d 44 24 18          	lea    eax,[esp+0x18]
  4b90b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b90bc:	8b d9                	mov    ebx,ecx
  4b90be:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b90c1:	0f be 48 02          	movsx  ecx,BYTE PTR [eax+0x2]
  4b90c5:	8d 41 f9             	lea    eax,[ecx-0x7]
  4b90c8:	83 f8 11             	cmp    eax,0x11
  4b90cb:	0f 87 5b 01 00 00    	ja     0x4b922c
  4b90d1:	0f b6 90 4c 92 4b 00 	movzx  edx,BYTE PTR [eax+0x4b924c]
  4b90d8:	ff 24 95 38 92 4b 00 	jmp    DWORD PTR [edx*4+0x4b9238]
  4b90df:	68 54 bd 00 00       	push   0xbd54
  4b90e4:	e8 7f 81 3d 00       	call   0x891268
  4b90e9:	83 c4 04             	add    esp,0x4
  4b90ec:	85 c0                	test   eax,eax
  4b90ee:	74 07                	je     0x4b90f7
  4b90f0:	e8 7b 2a 00 00       	call   0x4bbb70
  4b90f5:	eb 02                	jmp    0x4b90f9
  4b90f7:	33 c0                	xor    eax,eax
  4b90f9:	8b f8                	mov    edi,eax
  4b90fb:	8b f3                	mov    esi,ebx
  4b90fd:	e8 4e ec ff ff       	call   0x4b7d50
  4b9102:	e8 99 ba f4 ff       	call   0x404ba0
  4b9107:	c7 80 a8 69 00 00 07 	mov    DWORD PTR [eax+0x69a8],0x7
  4b910e:	00 00 00 
  4b9111:	e9 ab 00 00 00       	jmp    0x4b91c1
  4b9116:	68 54 bd 00 00       	push   0xbd54
  4b911b:	e8 48 81 3d 00       	call   0x891268
  4b9120:	8b f0                	mov    esi,eax
  4b9122:	83 c4 04             	add    esp,0x4
  4b9125:	85 f6                	test   esi,esi
  4b9127:	74 25                	je     0x4b914e
  4b9129:	e8 22 4c ff ff       	call   0x4add50
  4b912e:	c7 06 7c 6f c0 00    	mov    DWORD PTR [esi],0xc06f7c
  4b9134:	c7 05 74 a6 d6 00 55 	mov    DWORD PTR ds:0xd6a674,0x44535155
  4b913b:	51 53 44 
  4b913e:	e8 5d 23 00 00       	call   0x4bb4a0
  4b9143:	8b fe                	mov    edi,esi
  4b9145:	8b f3                	mov    esi,ebx
  4b9147:	e8 04 ec ff ff       	call   0x4b7d50
  4b914c:	eb 73                	jmp    0x4b91c1
  4b914e:	33 f6                	xor    esi,esi
  4b9150:	8b fe                	mov    edi,esi
  4b9152:	8b f3                	mov    esi,ebx
  4b9154:	e8 f7 eb ff ff       	call   0x4b7d50
  4b9159:	eb 66                	jmp    0x4b91c1
  4b915b:	68 54 bd 00 00       	push   0xbd54
  4b9160:	e8 03 81 3d 00       	call   0x891268
  4b9165:	83 c4 04             	add    esp,0x4
  4b9168:	85 c0                	test   eax,eax
  4b916a:	74 07                	je     0x4b9173
  4b916c:	e8 ff 29 00 00       	call   0x4bbb70
  4b9171:	eb 02                	jmp    0x4b9175
  4b9173:	33 c0                	xor    eax,eax
  4b9175:	8b f8                	mov    edi,eax
  4b9177:	8b f3                	mov    esi,ebx
  4b9179:	e8 d2 eb ff ff       	call   0x4b7d50
  4b917e:	e8 1d ba f4 ff       	call   0x404ba0
  4b9183:	c7 80 a8 69 00 00 17 	mov    DWORD PTR [eax+0x69a8],0x17
  4b918a:	00 00 00 
  4b918d:	eb 32                	jmp    0x4b91c1
  4b918f:	68 54 bd 00 00       	push   0xbd54
  4b9194:	e8 cf 80 3d 00       	call   0x891268
  4b9199:	83 c4 04             	add    esp,0x4
  4b919c:	85 c0                	test   eax,eax
  4b919e:	74 07                	je     0x4b91a7
  4b91a0:	e8 cb 29 00 00       	call   0x4bbb70
  4b91a5:	eb 02                	jmp    0x4b91a9
  4b91a7:	33 c0                	xor    eax,eax
  4b91a9:	8b f8                	mov    edi,eax
  4b91ab:	8b f3                	mov    esi,ebx
  4b91ad:	e8 9e eb ff ff       	call   0x4b7d50
  4b91b2:	e8 e9 b9 f4 ff       	call   0x404ba0
  4b91b7:	c7 80 a8 69 00 00 18 	mov    DWORD PTR [eax+0x69a8],0x18
  4b91be:	00 00 00 
  4b91c1:	b8 01 00 00 00       	mov    eax,0x1
  4b91c6:	84 05 90 43 f9 00    	test   BYTE PTR ds:0xf94390,al
  4b91cc:	75 20                	jne    0x4b91ee
  4b91ce:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  4b91d4:	c7 44 24 20 00 00 00 	mov    DWORD PTR [esp+0x20],0x0
  4b91db:	00 
  4b91dc:	e8 af 83 02 00       	call   0x4e1590
  4b91e1:	68 80 cc bc 00       	push   0xbccc80
  4b91e6:	e8 2f 91 3d 00       	call   0x89231a
  4b91eb:	83 c4 04             	add    esp,0x4
  4b91ee:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b91f1:	0f be 41 02          	movsx  eax,BYTE PTR [ecx+0x2]
  4b91f5:	39 05 2c 39 f9 00    	cmp    DWORD PTR ds:0xf9392c,eax
  4b91fb:	74 05                	je     0x4b9202
  4b91fd:	a3 2c 39 f9 00       	mov    ds:0xf9392c,eax
  4b9202:	0f b6 51 03          	movzx  edx,BYTE PTR [ecx+0x3]
  4b9206:	a1 88 1a fe 00       	mov    eax,ds:0xfe1a88
  4b920b:	89 50 18             	mov    DWORD PTR [eax+0x18],edx
  4b920e:	0f b6 49 04          	movzx  ecx,BYTE PTR [ecx+0x4]
  4b9212:	89 48 1c             	mov    DWORD PTR [eax+0x1c],ecx
  4b9215:	33 c0                	xor    eax,eax
  4b9217:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4b921b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b9222:	59                   	pop    ecx
  4b9223:	5f                   	pop    edi
  4b9224:	5e                   	pop    esi
  4b9225:	5b                   	pop    ebx
  4b9226:	8b e5                	mov    esp,ebp
  4b9228:	5d                   	pop    ebp
  4b9229:	c2 0c 00             	ret    0xc
  4b922c:	51                   	push   ecx
  4b922d:	68 28 6e         	push   0xc06e28
```

### town_candidate2: VA `0x004BBB70–0x004BBD20` / raw `0x000BAF70–0x000BB120` (`[start,end)`); SHA256 `62e083a824123f2354b4b1ff1658497ce780dfebfd275eb72ce84f0284f15dd6`

```asm
004bbb70 <.data+0xbaf70>:
  4bbb70:	56                   	push   esi
  4bbb71:	8b f0                	mov    esi,eax
  4bbb73:	e8 d8 21 ff ff       	call   0x4add50
  4bbb78:	c7 06 b0 6f c0 00    	mov    DWORD PTR [esi],0xc06fb0
  4bbb7e:	c7 05 74 a6 d6 00 52 	mov    DWORD PTR ds:0xd6a674,0x53515552
  4bbb85:	55 51 53 
  4bbb88:	e8 13 00 00 00       	call   0x4bbba0
  4bbb8d:	8b c6                	mov    eax,esi
  4bbb8f:	5e                   	pop    esi
  4bbb90:	c3                   	ret
  4bbb91:	cc                   	int3
  4bbb92:	cc                   	int3
  4bbb93:	cc                   	int3
  4bbb94:	cc                   	int3
  4bbb95:	cc                   	int3
  4bbb96:	cc                   	int3
  4bbb97:	cc                   	int3
  4bbb98:	cc                   	int3
  4bbb99:	cc                   	int3
  4bbb9a:	cc                   	int3
  4bbb9b:	cc                   	int3
  4bbb9c:	cc                   	int3
  4bbb9d:	cc                   	int3
  4bbb9e:	cc                   	int3
  4bbb9f:	cc                   	int3
  4bbba0:	68 a8 5e 00 00       	push   0x5ea8
  4bbba5:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4bbbab:	6a 00                	push   0x0
  4bbbad:	50                   	push   eax
  4bbbae:	e8 ad 2c 3e 00       	call   0x89e860
  4bbbb3:	b8 75 23 bf 00       	mov    eax,0xbf2375
  4bbbb8:	83 c4 0c             	add    esp,0xc
  4bbbbb:	c7 86 a4 5f 00 00 50 	mov    DWORD PTR [esi+0x5fa4],0x4c5c50
  4bbbc2:	5c 4c 00 
  4bbbc5:	89 86 a8 5f 00 00    	mov    DWORD PTR [esi+0x5fa8],eax
  4bbbcb:	c7 86 d4 5f 00 00 50 	mov    DWORD PTR [esi+0x5fd4],0x4c5c50
  4bbbd2:	5c 4c 00 
  4bbbd5:	89 86 d8 5f 00 00    	mov    DWORD PTR [esi+0x5fd8],eax
  4bbbdb:	c7 86 ec 61 00 00 50 	mov    DWORD PTR [esi+0x61ec],0x4bc050
  4bbbe2:	c0 4b 00 
  4bbbe5:	89 86 f0 61 00 00    	mov    DWORD PTR [esi+0x61f0],eax
  4bbbeb:	c7 86 fc 61 00 00 a0 	mov    DWORD PTR [esi+0x61fc],0x4bbfa0
  4bbbf2:	bf 4b 00 
  4bbbf5:	89 86 00 62 00 00    	mov    DWORD PTR [esi+0x6200],eax
  4bbbfb:	c7 86 04 62 00 00 e0 	mov    DWORD PTR [esi+0x6204],0x4bbae0
  4bbc02:	ba 4b 00 
  4bbc05:	89 86 08 62 00 00    	mov    DWORD PTR [esi+0x6208],eax
  4bbc0b:	c3                   	ret
  4bbc0c:	cc                   	int3
  4bbc0d:	cc                   	int3
  4bbc0e:	cc                   	int3
  4bbc0f:	cc                   	int3
  4bbc10:	55                   	push   ebp
  4bbc11:	8b ec                	mov    ebp,esp
  4bbc13:	83 e4 f8             	and    esp,0xfffffff8
  4bbc16:	6a ff                	push   0xffffffff
  4bbc18:	68 3d 49 94 00       	push   0x94493d
  4bbc1d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4bbc23:	50                   	push   eax
  4bbc24:	83 ec 10             	sub    esp,0x10
  4bbc27:	53                   	push   ebx
  4bbc28:	56                   	push   esi
  4bbc29:	57                   	push   edi
  4bbc2a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4bbc2f:	33 c4                	xor    eax,esp
  4bbc31:	50                   	push   eax
  4bbc32:	8d 44 24 20          	lea    eax,[esp+0x20]
  4bbc36:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4bbc3c:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  4bbc43:	bf 01 00 00 00       	mov    edi,0x1
  4bbc48:	75 29                	jne    0x4bbc73
  4bbc4a:	09 3d b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,edi
  4bbc50:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  4bbc57:	00 
  4bbc58:	e8 13 45 0a 00       	call   0x560170
  4bbc5d:	68 10 d1 bc 00       	push   0xbcd110
  4bbc62:	e8 b3 66 3d 00       	call   0x89231a
  4bbc67:	83 c4 04             	add    esp,0x4
  4bbc6a:	83 cb ff             	or     ebx,0xffffffff
  4bbc6d:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4bbc71:	eb 03                	jmp    0x4bbc76
  4bbc73:	83 cb ff             	or     ebx,0xffffffff
  4bbc76:	6a 00                	push   0x0
  4bbc78:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  4bbc7d:	e8 2e 68 0a 00       	call   0x5624b0
  4bbc82:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  4bbc89:	75 20                	jne    0x4bbcab
  4bbc8b:	09 3d b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,edi
  4bbc91:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  4bbc95:	e8 d6 44 0a 00       	call   0x560170
  4bbc9a:	68 10 d1 bc 00       	push   0xbcd110
  4bbc9f:	e8 76 66 3d 00       	call   0x89231a
  4bbca4:	83 c4 04             	add    esp,0x4
  4bbca7:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4bbcab:	e8 a0 65 0a 00       	call   0x562250
  4bbcb0:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4bbcb6:	8b 01                	mov    eax,DWORD PTR [ecx]
  4bbcb8:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4bbcbb:	ff d2                	call   edx
  4bbcbd:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4bbcc4:	be 02 00 00 00       	mov    esi,0x2
  4bbcc9:	75 20                	jne    0x4bbceb
  4bbccb:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  4bbcd1:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  4bbcd5:	e8 b6 2f 02 00       	call   0x4dec90
  4bbcda:	68 30 ce bc 00       	push   0xbcce30
  4bbcdf:	e8 36 66 3d 00       	call   0x89231a
  4bbce4:	83 c4 04             	add    esp,0x4
  4bbce7:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  4bbceb:	68 30 b1 fa 00       	push   0xfab130
  4bbcf0:	e8 9b 41 02 00       	call   0x4dfe90
  4bbcf5:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4bbcfc:	75 24                	jne    0x4bbd22
  4bbcfe:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  4bbd04:	c7 44 24 28 03 00 00 	mov    DWORD PTR [esp+0x28],0x3
  4bbd0b:	00 
  4bbd0c:	e8 7f 2f 02 00       	call   0x4dec90
  4bbd11:	68 30 ce bc 00       	push   0xbcce30
  4bbd16:	e8 ff 65 3d 00       	call   0x89231a
  4bbd1b:	83 c4 04             	add    esp,0x4
  4bbd1e:	89 5c            	mov    DWORD PTR [esp+0x28],ebx
```

### scene_reset: VA `0x004B24F0–0x004B2630` / raw `0x000B18F0–0x000B1A30` (`[start,end)`); SHA256 `593be6da0bbfc2e3cbf520ae6ec505f2531e4858dd1374b78316bcc64dc4422f`

```asm
004b24f0 <.data+0xb18f0>:
  4b24f0:	55                   	push   ebp
  4b24f1:	8b ec                	mov    ebp,esp
  4b24f3:	b9 01 00 00 00       	mov    ecx,0x1
  4b24f8:	84 0d ec 79 fb 00    	test   BYTE PTR ds:0xfb79ec,cl
  4b24fe:	75 34                	jne    0x4b2534
  4b2500:	09 0d ec 79 fb 00    	or     DWORD PTR ds:0xfb79ec,ecx
  4b2506:	33 c0                	xor    eax,eax
  4b2508:	68 70 d2 bc 00       	push   0xbcd270
  4b250d:	c7 05 f0 79 fb 00 68 	mov    DWORD PTR ds:0xfb79f0,0xc0f868
  4b2514:	f8 c0 00 
  4b2517:	a3 f4 79 fb 00       	mov    ds:0xfb79f4,eax
  4b251c:	a3 f8 79 fb 00       	mov    ds:0xfb79f8,eax
  4b2521:	a3 fc 79 fb 00       	mov    ds:0xfb79fc,eax
  4b2526:	89 0d 04 7a fb 00    	mov    DWORD PTR ds:0xfb7a04,ecx
  4b252c:	e8 e9 fd 3d 00       	call   0x89231a
  4b2531:	83 c4 04             	add    esp,0x4
  4b2534:	57                   	push   edi
  4b2535:	68 f0 79 fb 00       	push   0xfb79f0
  4b253a:	e8 61 24 09 00       	call   0x5449a0
  4b253f:	8b 3d a4 a7 fb 00    	mov    edi,DWORD PTR ds:0xfba7a4
  4b2545:	e8 06 2a 09 00       	call   0x544f50
  4b254a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4b254d:	8b 48 02             	mov    ecx,DWORD PTR [eax+0x2]
  4b2550:	51                   	push   ecx
  4b2551:	e8 0a cb f5 ff       	call   0x40f060
  4b2556:	50                   	push   eax
  4b2557:	e8 b4 cf 02 00       	call   0x4df510
  4b255c:	b8 00 01 00 00       	mov    eax,0x100
  4b2561:	5f                   	pop    edi
  4b2562:	5d                   	pop    ebp
  4b2563:	c2 0c 00             	ret    0xc
  4b2566:	cc                   	int3
  4b2567:	cc                   	int3
  4b2568:	cc                   	int3
  4b2569:	cc                   	int3
  4b256a:	cc                   	int3
  4b256b:	cc                   	int3
  4b256c:	cc                   	int3
  4b256d:	cc                   	int3
  4b256e:	cc                   	int3
  4b256f:	cc                   	int3
  4b2570:	55                   	push   ebp
  4b2571:	8b ec                	mov    ebp,esp
  4b2573:	6a ff                	push   0xffffffff
  4b2575:	68 7c b2 93 00       	push   0x93b27c
  4b257a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b2580:	50                   	push   eax
  4b2581:	53                   	push   ebx
  4b2582:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b2587:	33 c5                	xor    eax,ebp
  4b2589:	50                   	push   eax
  4b258a:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b258d:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b2593:	a1 a4 a7 fb 00       	mov    eax,ds:0xfba7a4
  4b2598:	bb 01 00 00 00       	mov    ebx,0x1
  4b259d:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  4b25a0:	84 1d b8 73 fb 00    	test   BYTE PTR ds:0xfb73b8,bl
  4b25a6:	75 26                	jne    0x4b25ce
  4b25a8:	09 1d b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,ebx
  4b25ae:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b25b5:	e8 b6 db 0a 00       	call   0x560170
  4b25ba:	68 10 d1 bc 00       	push   0xbcd110
  4b25bf:	e8 56 fd 3d 00       	call   0x89231a
  4b25c4:	83 c4 04             	add    esp,0x4
  4b25c7:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4b25ce:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
  4b25d5:	75 2a                	jne    0x4b2601
  4b25d7:	84 1d 14 7c fb 00    	test   BYTE PTR ds:0xfb7c14,bl
  4b25dd:	75 1b                	jne    0x4b25fa
  4b25df:	09 1d 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,ebx
  4b25e5:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4b25e8:	e8 63 e1 21 00       	call   0x6d0750
  4b25ed:	68 30 d5 bc 00       	push   0xbcd530
  4b25f2:	e8 23 fd 3d 00       	call   0x89231a
  4b25f7:	83 c4 04             	add    esp,0x4
  4b25fa:	83 25 30 88 fb 00 fe 	and    DWORD PTR ds:0xfb8830,0xfffffffe
  4b2601:	33 c0                	xor    eax,eax
  4b2603:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4b2606:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b260d:	59                   	pop    ecx
  4b260e:	5b                   	pop    ebx
  4b260f:	8b e5                	mov    esp,ebp
  4b2611:	5d                   	pop    ebp
  4b2612:	c2 0c 00             	ret    0xc
  4b2615:	cc                   	int3
  4b2616:	cc                   	int3
  4b2617:	cc                   	int3
  4b2618:	cc                   	int3
  4b2619:	cc                   	int3
  4b261a:	cc                   	int3
  4b261b:	cc                   	int3
  4b261c:	cc                   	int3
  4b261d:	cc                   	int3
  4b261e:	cc                   	int3
  4b261f:	cc                   	int3
  4b2620:	55                   	push   ebp
  4b2621:	8b ec                	mov    ebp,esp
  4b2623:	83 ec 0c             	sub    esp,0xc
  4b2626:	a1 a4 a7 fb 00       	mov    eax,ds:0xfba7a4
  4b262b:	57                   	push   edi
  4b262c:	c7 40 04 00    	mov    DWORD PTR [eax+0x4],0x0
```

### scene_ready: VA `0x004C5930–0x004C5AA0` / raw `0x000C4D30–0x000C4EA0` (`[start,end)`); SHA256 `8ffc7aae09c8cc3dc0a566deb9903e6a9cec1247345b008a595aa7f63c1dee31`

```asm
004c5930 <.data+0xc4d30>:
  4c5930:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c5932:	ff 60 2c             	jmp    DWORD PTR [eax+0x2c]
  4c5935:	cc                   	int3
  4c5936:	cc                   	int3
  4c5937:	cc                   	int3
  4c5938:	cc                   	int3
  4c5939:	cc                   	int3
  4c593a:	cc                   	int3
  4c593b:	cc                   	int3
  4c593c:	cc                   	int3
  4c593d:	cc                   	int3
  4c593e:	cc                   	int3
  4c593f:	cc                   	int3
  4c5940:	55                   	push   ebp
  4c5941:	8b ec                	mov    ebp,esp
  4c5943:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  4c5947:	56                   	push   esi
  4c5948:	8b f1                	mov    esi,ecx
  4c594a:	c7 06 38 5b c0 00    	mov    DWORD PTR [esi],0xc05b38
  4c5950:	74 09                	je     0x4c595b
  4c5952:	56                   	push   esi
  4c5953:	e8 b4 b8 3c 00       	call   0x89120c
  4c5958:	83 c4 04             	add    esp,0x4
  4c595b:	8b c6                	mov    eax,esi
  4c595d:	5e                   	pop    esi
  4c595e:	5d                   	pop    ebp
  4c595f:	c2 04 00             	ret    0x4
  4c5962:	cc                   	int3
  4c5963:	cc                   	int3
  4c5964:	cc                   	int3
  4c5965:	cc                   	int3
  4c5966:	cc                   	int3
  4c5967:	cc                   	int3
  4c5968:	cc                   	int3
  4c5969:	cc                   	int3
  4c596a:	cc                   	int3
  4c596b:	cc                   	int3
  4c596c:	cc                   	int3
  4c596d:	cc                   	int3
  4c596e:	cc                   	int3
  4c596f:	cc                   	int3
  4c5970:	68 a8 5e 00 00       	push   0x5ea8
  4c5975:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4c597b:	6a 00                	push   0x0
  4c597d:	50                   	push   eax
  4c597e:	e8 dd 8e 3d 00       	call   0x89e860
  4c5983:	b8 75 23 bf 00       	mov    eax,0xbf2375
  4c5988:	83 c4 0c             	add    esp,0xc
  4c598b:	c7 86 a4 5f 00 00 50 	mov    DWORD PTR [esi+0x5fa4],0x4c5c50
  4c5992:	5c 4c 00 
  4c5995:	89 86 a8 5f 00 00    	mov    DWORD PTR [esi+0x5fa8],eax
  4c599b:	c7 86 d4 5f 00 00 50 	mov    DWORD PTR [esi+0x5fd4],0x4c5c50
  4c59a2:	5c 4c 00 
  4c59a5:	89 86 d8 5f 00 00    	mov    DWORD PTR [esi+0x5fd8],eax
  4c59ab:	c7 86 bc 61 00 00 b0 	mov    DWORD PTR [esi+0x61bc],0x4c5cb0
  4c59b2:	5c 4c 00 
  4c59b5:	89 86 c0 61 00 00    	mov    DWORD PTR [esi+0x61c0],eax
  4c59bb:	c7 86 e4 63 00 00 10 	mov    DWORD PTR [esi+0x63e4],0x424610
  4c59c2:	46 42 00 
  4c59c5:	89 86 e8 63 00 00    	mov    DWORD PTR [esi+0x63e8],eax
  4c59cb:	c3                   	ret
  4c59cc:	cc                   	int3
  4c59cd:	cc                   	int3
  4c59ce:	cc                   	int3
  4c59cf:	cc                   	int3
  4c59d0:	55                   	push   ebp
  4c59d1:	8b ec                	mov    ebp,esp
  4c59d3:	83 e4 f8             	and    esp,0xfffffff8
  4c59d6:	6a ff                	push   0xffffffff
  4c59d8:	68 0f 58 94 00       	push   0x94580f
  4c59dd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c59e3:	50                   	push   eax
  4c59e4:	83 ec 08             	sub    esp,0x8
  4c59e7:	53                   	push   ebx
  4c59e8:	56                   	push   esi
  4c59e9:	57                   	push   edi
  4c59ea:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c59ef:	33 c4                	xor    eax,esp
  4c59f1:	50                   	push   eax
  4c59f2:	8d 44 24 18          	lea    eax,[esp+0x18]
  4c59f6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c59fc:	83 cb ff             	or     ebx,0xffffffff
  4c59ff:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  4c5a06:	8d 73 02             	lea    esi,[ebx+0x2]
  4c5a09:	75 24                	jne    0x4c5a2f
  4c5a0b:	09 35 b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,esi
  4c5a11:	c7 44 24 20 00 00 00 	mov    DWORD PTR [esp+0x20],0x0
  4c5a18:	00 
  4c5a19:	e8 52 a7 09 00       	call   0x560170
  4c5a1e:	68 10 d1 bc 00       	push   0xbcd110
  4c5a23:	e8 f2 c8 3c 00       	call   0x89231a
  4c5a28:	83 c4 04             	add    esp,0x4
  4c5a2b:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4c5a2f:	6a 00                	push   0x0
  4c5a31:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  4c5a36:	e8 75 ca 09 00       	call   0x5624b0
  4c5a3b:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  4c5a42:	75 20                	jne    0x4c5a64
  4c5a44:	09 35 b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,esi
  4c5a4a:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4c5a4e:	e8 1d a7 09 00       	call   0x560170
  4c5a53:	68 10 d1 bc 00       	push   0xbcd110
  4c5a58:	e8 bd c8 3c 00       	call   0x89231a
  4c5a5d:	83 c4 04             	add    esp,0x4
  4c5a60:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4c5a64:	e8 e7 c7 09 00       	call   0x562250
  4c5a69:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4c5a6f:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c5a71:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4c5a74:	ff d2                	call   edx
  4c5a76:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4c5a7d:	75 24                	jne    0x4c5aa3
  4c5a7f:	09 35 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,esi
  4c5a85:	c7 44 24 20 02 00 00 	mov    DWORD PTR [esp+0x20],0x2
  4c5a8c:	00 
  4c5a8d:	e8 fe 91 01 00       	call   0x4dec90
  4c5a92:	68 30 ce bc 00       	push   0xbcce30
  4c5a97:	e8 7e c8 3c 00       	call   0x89231a
  4c5a9c:	83 c4 04             	add    esp,0x4
  4c5a9f:	89             	mov    DWORD PTR [esp+0x20],ebx
```

### inbound_FC: VA `0x00804740–0x00804904` / raw `0x00403B40–0x00403D04` (`[start,end)`); SHA256 `8664bdbb54585dd2f7ab35b48bf70560178c348353f04210e61c9e04f6c7180a`

```asm
00804740 <.data+0x403b40>:
  804740:	55                   	push   ebp
  804741:	8b ec                	mov    ebp,esp
  804743:	6a ff                	push   0xffffffff
  804745:	68 9c 9a 90 00       	push   0x909a9c
  80474a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  804750:	50                   	push   eax
  804751:	83 ec 4c             	sub    esp,0x4c
  804754:	53                   	push   ebx
  804755:	56                   	push   esi
  804756:	57                   	push   edi
  804757:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  80475c:	33 c5                	xor    eax,ebp
  80475e:	50                   	push   eax
  80475f:	8d 45 f4             	lea    eax,[ebp-0xc]
  804762:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  804768:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  80476b:	f6 05 cc 10 fc 00 01 	test   BYTE PTR ds:0xfc10cc,0x1
  804772:	75 27                	jne    0x80479b
  804774:	83 0d cc 10 fc 00 01 	or     DWORD PTR ds:0xfc10cc,0x1
  80477b:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  804782:	e8 69 f8 ff ff       	call   0x803ff0
  804787:	68 90 dc bc 00       	push   0xbcdc90
  80478c:	e8 89 db 08 00       	call   0x89231a
  804791:	83 c4 04             	add    esp,0x4
  804794:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80479b:	a1 f0 11 fc 00       	mov    eax,ds:0xfc11f0
  8047a0:	6a 01                	push   0x1
  8047a2:	50                   	push   eax
  8047a3:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [ebp-0x10],0x0
  8047aa:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  8047b0:	33 c0                	xor    eax,eax
  8047b2:	8d 7b 04             	lea    edi,[ebx+0x4]
  8047b5:	b9 0b 00 00 00       	mov    ecx,0xb
  8047ba:	8d 73 30             	lea    esi,[ebx+0x30]
  8047bd:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  8047bf:	89 45 a8             	mov    DWORD PTR [ebp-0x58],eax
  8047c2:	89 45 ac             	mov    DWORD PTR [ebp-0x54],eax
  8047c5:	89 45 b0             	mov    DWORD PTR [ebp-0x50],eax
  8047c8:	89 45 b4             	mov    DWORD PTR [ebp-0x4c],eax
  8047cb:	89 45 b8             	mov    DWORD PTR [ebp-0x48],eax
  8047ce:	89 45 bc             	mov    DWORD PTR [ebp-0x44],eax
  8047d1:	89 45 c0             	mov    DWORD PTR [ebp-0x40],eax
  8047d4:	89 45 c8             	mov    DWORD PTR [ebp-0x38],eax
  8047d7:	89 45 cc             	mov    DWORD PTR [ebp-0x34],eax
  8047da:	66 89 45 d0          	mov    WORD PTR [ebp-0x30],ax
  8047de:	b9 0b 00 00 00       	mov    ecx,0xb
  8047e3:	8d 75 a8             	lea    esi,[ebp-0x58]
  8047e6:	8d 7b 30             	lea    edi,[ebx+0x30]
  8047e9:	f3 a5                	rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
  8047eb:	8b 3d a0 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25a0
  8047f1:	ff d7                	call   edi
  8047f3:	8b 8b 84 00 00 00    	mov    ecx,DWORD PTR [ebx+0x84]
  8047f9:	89 43 30             	mov    DWORD PTR [ebx+0x30],eax
  8047fc:	2b 43 10             	sub    eax,DWORD PTR [ebx+0x10]
  8047ff:	8d 51 fc             	lea    edx,[ecx-0x4]
  804802:	3b c2                	cmp    eax,edx
  804804:	76 0d                	jbe    0x804813
  804806:	c7 45 ec 04 00 00 00 	mov    DWORD PTR [ebp-0x14],0x4
  80480d:	c6 43 58 01          	mov    BYTE PTR [ebx+0x58],0x1
  804811:	eb 03                	jmp    0x804816
  804813:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  804816:	33 f6                	xor    esi,esi
  804818:	89 73 50             	mov    DWORD PTR [ebx+0x50],esi
  80481b:	89 73 54             	mov    DWORD PTR [ebx+0x54],esi
  80481e:	ff d7                	call   edi
  804820:	89 43 38             	mov    DWORD PTR [ebx+0x38],eax
  804823:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  804826:	83 fe 02             	cmp    esi,0x2
  804829:	75 0c                	jne    0x804837
  80482b:	ff d7                	call   edi
  80482d:	89 43 40             	mov    DWORD PTR [ebx+0x40],eax
  804830:	c7 43 54 00 00 00 00 	mov    DWORD PTR [ebx+0x54],0x0
  804837:	56                   	push   esi
  804838:	8d 45 f0             	lea    eax,[ebp-0x10]
  80483b:	50                   	push   eax
  80483c:	b8 d0 10 fc 00       	mov    eax,0xfc10d0
  804841:	e8 ba f8 ff ff       	call   0x804100
  804846:	84 c0                	test   al,al
  804848:	0f 84 82 01 00 00    	je     0x8049d0
  80484e:	8b ff                	mov    edi,edi
  804850:	ff d7                	call   edi
  804852:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804855:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804858:	8b 13                	mov    edx,DWORD PTR [ebx]
  80485a:	8b 12                	mov    edx,DWORD PTR [edx]
  80485c:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  80485f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  804862:	51                   	push   ecx
  804863:	50                   	push   eax
  804864:	8d 46 08             	lea    eax,[esi+0x8]
  804867:	50                   	push   eax
  804868:	8b 06                	mov    eax,DWORD PTR [esi]
  80486a:	50                   	push   eax
  80486b:	8b cb                	mov    ecx,ebx
  80486d:	ff d2                	call   edx
  80486f:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  804872:	ff d7                	call   edi
  804874:	2b 45 e8             	sub    eax,DWORD PTR [ebp-0x18]
  804877:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  80487a:	8b f8                	mov    edi,eax
  80487c:	8b 03                	mov    eax,DWORD PTR [ebx]
  80487e:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  804881:	57                   	push   edi
  804882:	56                   	push   esi
  804883:	51                   	push   ecx
  804884:	8b cb                	mov    ecx,ebx
  804886:	ff d2                	call   edx
  804888:	83 ff 28             	cmp    edi,0x28
  80488b:	76 16                	jbe    0x8048a3
  80488d:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804890:	8b 03                	mov    eax,DWORD PTR [ebx]
  804892:	8b 93 8c 00 00 00    	mov    edx,DWORD PTR [ebx+0x8c]
  804898:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  80489b:	57                   	push   edi
  80489c:	56                   	push   esi
  80489d:	51                   	push   ecx
  80489e:	52                   	push   edx
  80489f:	8b cb                	mov    ecx,ebx
  8048a1:	ff d0                	call   eax
  8048a3:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  8048aa:	75 27                	jne    0x8048d3
  8048ac:	b8 01 00 00 00       	mov    eax,0x1
  8048b1:	09 05 54 33 fe 00    	or     DWORD PTR ds:0xfe3354,eax
  8048b7:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  8048ba:	e8 61 28 00 00       	call   0x807120
  8048bf:	68 90 0b bd 00       	push   0xbd0b90
  8048c4:	e8 51 da 08 00       	call   0x89231a
  8048c9:	83 c4 04             	add    esp,0x4
  8048cc:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  8048d3:	c7 06 00 00 00 00    	mov    DWORD PTR [esi],0x0
  8048d9:	c7 46 04 00 00 00 00 	mov    DWORD PTR [esi+0x4],0x0
  8048e0:	8b 0d b0 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe33b0
  8048e6:	51                   	push   ecx
  8048e7:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8048ed:	a1 a4 33 fe 00       	mov    eax,ds:0xfe33a4
  8048f2:	8b 15 a0 33 fe 00    	mov    edx,DWORD PTR ds:0xfe33a0
  8048f8:	03 d0                	add    edx,eax
  8048fa:	f6 c2 03             	test   dl,0x3
  8048fd:	75 18                	jne    0x804917
  8048ff:	83 c0 04             	add    eax,0x4
  804902:	c1 e8              	shr    eax,0x2
```

### net_frame: VA `0x008061A0–0x0080637F` / raw `0x004055A0–0x0040577F` (`[start,end)`); SHA256 `95d7c63dbb8a6b3c210731aabed0e673f42b12cd599a0b5d4a5b5fede42be7c0`

```asm
008061a0 <.data+0x4055a0>:
  8061a0:	55                   	push   ebp
  8061a1:	8b ec                	mov    ebp,esp
  8061a3:	6a ff                	push   0xffffffff
  8061a5:	68 2e 99 90 00       	push   0x90992e
  8061aa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8061b0:	50                   	push   eax
  8061b1:	83 ec 24             	sub    esp,0x24
  8061b4:	53                   	push   ebx
  8061b5:	56                   	push   esi
  8061b6:	57                   	push   edi
  8061b7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8061bc:	33 c5                	xor    eax,ebp
  8061be:	50                   	push   eax
  8061bf:	8d 45 f4             	lea    eax,[ebp-0xc]
  8061c2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  8061c8:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8061cb:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  8061d1:	50                   	push   eax
  8061d2:	c7 45 e4 01 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x1
  8061d9:	c7 45 e8 00 00 00 00 	mov    DWORD PTR [ebp-0x18],0x0
  8061e0:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8061e6:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  8061ec:	8b 18                	mov    ebx,DWORD PTR [eax]
  8061ee:	3b d8                	cmp    ebx,eax
  8061f0:	0f 84 c4 01 00 00    	je     0x8063ba
  8061f6:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  8061f9:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  8061fc:	8d 47 08             	lea    eax,[edi+0x8]
  8061ff:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806202:	0f be 86 2c a0 00 00 	movsx  eax,BYTE PTR [esi+0xa02c]
  806209:	83 e8 00             	sub    eax,0x0
  80620c:	8d 8e 1c 50 00 00    	lea    ecx,[esi+0x501c]
  806212:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  806215:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  806218:	74 15                	je     0x80622f
  80621a:	48                   	dec    eax
  80621b:	74 01                	je     0x80621e
  80621d:	48                   	dec    eax
  80621e:	52                   	push   edx
  80621f:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  806222:	52                   	push   edx
  806223:	e8 08 16 00 00       	call   0x807830
  806228:	85 c0                	test   eax,eax
  80622a:	75 23                	jne    0x80624f
  80622c:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  80622f:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806232:	52                   	push   edx
  806233:	50                   	push   eax
  806234:	8d be 1c 50 00 00    	lea    edi,[esi+0x501c]
  80623a:	e8 31 18 00 00       	call   0x807a70
  80623f:	85 c0                	test   eax,eax
  806241:	0f 95 c0             	setne  al
  806244:	84 c0                	test   al,al
  806246:	0f 84 58 01 00 00    	je     0x8063a4
  80624c:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  80624f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806251:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  806254:	3b 9e 74 a0 00 00    	cmp    ebx,DWORD PTR [esi+0xa074]
  80625a:	74 1f                	je     0x80627b
  80625c:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  80625f:	89 08                	mov    DWORD PTR [eax],ecx
  806261:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806263:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  806266:	53                   	push   ebx
  806267:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  80626a:	e8 9d af 08 00       	call   0x89120c
  80626f:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806272:	83 c4 04             	add    esp,0x4
  806275:	ff 8e 78 a0 00 00    	dec    DWORD PTR [esi+0xa078]
  80627b:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  806282:	8b d9                	mov    ebx,ecx
  806284:	75 27                	jne    0x8062ad
  806286:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  80628d:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806294:	e8 87 0e 00 00       	call   0x807120
  806299:	68 90 0b bd 00       	push   0xbd0b90
  80629e:	e8 77 c0 08 00       	call   0x89231a
  8062a3:	83 c4 04             	add    esp,0x4
  8062a6:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  8062ad:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  8062b2:	50                   	push   eax
  8062b3:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  8062b9:	c7 07 00 00 00 00    	mov    DWORD PTR [edi],0x0
  8062bf:	c7 47 04 00 00 00 00 	mov    DWORD PTR [edi+0x4],0x0
  8062c6:	a1 74 33 fe 00       	mov    eax,ds:0xfe3374
  8062cb:	8b 0d 70 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3370
  8062d1:	03 c8                	add    ecx,eax
  8062d3:	f6 c1 03             	test   cl,0x3
  8062d6:	75 18                	jne    0x8062f0
  8062d8:	83 c0 04             	add    eax,0x4
  8062db:	c1 e8 02             	shr    eax,0x2
  8062de:	39 05 6c 33 fe 00    	cmp    DWORD PTR ds:0xfe336c,eax
  8062e4:	77 0a                	ja     0x8062f0
  8062e6:	68 64 33 fe 00       	push   0xfe3364
  8062eb:	e8 80 0c e3 ff       	call   0x636f70
  8062f0:	8b 3d 70 33 fe 00    	mov    edi,DWORD PTR ds:0xfe3370
  8062f6:	03 3d 74 33 fe 00    	add    edi,DWORD PTR ds:0xfe3374
  8062fc:	a1 6c 33 fe 00       	mov    eax,ds:0xfe336c
  806301:	8b f7                	mov    esi,edi
  806303:	c1 ee 02             	shr    esi,0x2
  806306:	3b c6                	cmp    eax,esi
  806308:	77 02                	ja     0x80630c
  80630a:	2b f0                	sub    esi,eax
  80630c:	8b 0d 68 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3368
  806312:	83 3c b1 00          	cmp    DWORD PTR [ecx+esi*4],0x0
  806316:	75 17                	jne    0x80632f
  806318:	6a 10                	push   0x10
  80631a:	e8 49 af 08 00       	call   0x891268
  80631f:	83 c4 04             	add    esp,0x4
  806322:	85 c0                	test   eax,eax
  806324:	74 56                	je     0x80637c
  806326:	8b 15 68 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3368
  80632c:	89 04 b2             	mov    DWORD PTR [edx+esi*4],eax
  80632f:	a1 68 33 fe 00       	mov    eax,ds:0xfe3368
  806334:	8b 0c b0             	mov    ecx,DWORD PTR [eax+esi*4]
  806337:	83 e7 03             	and    edi,0x3
  80633a:	8d 04 b9             	lea    eax,[ecx+edi*4]
  80633d:	85 c0                	test   eax,eax
  80633f:	74 05                	je     0x806346
  806341:	8b 55 ec             	mov    edx,DWORD PTR [ebp-0x14]
  806344:	89 10                	mov    DWORD PTR [eax],edx
  806346:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  80634b:	be 01 00 00 00       	mov    esi,0x1
  806350:	01 35 74 33 fe 00    	add    DWORD PTR ds:0xfe3374,esi
  806356:	29 35 7c 33 fe 00    	sub    DWORD PTR ds:0xfe337c,esi
  80635c:	50                   	push   eax
  80635d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  806363:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  806366:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806369:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  80636c:	8b f2                	mov    esi,edx
  80636e:	3b 8a 74 a0 00 00    	cmp    ecx,DWORD PTR [edx+0xa074]
  806374:	0f 85 7c fe ff ff    	jne    0x8061f6
  80637a:	eb 3e                	jmp    0x8063ba
  80637c:	8d 45 dc             	lea    eax,[ebp-0x24]
```

### scene_list_loader: VA `0x005607D0–0x00560A30` / raw `0x0015FBD0–0x0015FE30` (`[start,end)`); SHA256 `eec1cffe334a718075e6a0ba8ca308c12b0d5103c463a65d0db1ed6d4f7c40dc`

```asm
005607d0 <.data+0x15fbd0>:
  5607d0:	55                   	push   ebp
  5607d1:	8b ec                	mov    ebp,esp
  5607d3:	83 e4 f8             	and    esp,0xfffffff8
  5607d6:	6a ff                	push   0xffffffff
  5607d8:	68 71 2f 92 00       	push   0x922f71
  5607dd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5607e3:	50                   	push   eax
  5607e4:	81 ec d8 00 00 00    	sub    esp,0xd8
  5607ea:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5607ef:	33 c4                	xor    eax,esp
  5607f1:	89 84 24 d0 00 00 00 	mov    DWORD PTR [esp+0xd0],eax
  5607f8:	53                   	push   ebx
  5607f9:	56                   	push   esi
  5607fa:	57                   	push   edi
  5607fb:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  560800:	33 c4                	xor    eax,esp
  560802:	50                   	push   eax
  560803:	8d 84 24 e8 00 00 00 	lea    eax,[esp+0xe8]
  56080a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  560810:	8d 44 24 64          	lea    eax,[esp+0x64]
  560814:	50                   	push   eax
  560815:	b9 68 06 c1 00       	mov    ecx,0xc10668
  56081a:	e8 11 e6 1c 00       	call   0x72ee30
  56081f:	33 db                	xor    ebx,ebx
  560821:	89 9c 24 f0 00 00 00 	mov    DWORD PTR [esp+0xf0],ebx
  560828:	83 bc 24 98 00 00 00 	cmp    DWORD PTR [esp+0x98],0x10
  56082f:	10 
  560830:	8b 8c 24 84 00 00 00 	mov    ecx,DWORD PTR [esp+0x84]
  560837:	73 07                	jae    0x560840
  560839:	8d 8c 24 84 00 00 00 	lea    ecx,[esp+0x84]
  560840:	53                   	push   ebx
  560841:	8d 74 24 68          	lea    esi,[esp+0x68]
  560845:	e8 c6 e8 1c 00       	call   0x72f110
  56084a:	84 c0                	test   al,al
  56084c:	0f 84 d4 01 00 00    	je     0x560a26
  560852:	8b 0d cc 73 fb 00    	mov    ecx,DWORD PTR ds:0xfb73cc
  560858:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  56085b:	52                   	push   edx
  56085c:	b9 c8 73 fb 00       	mov    ecx,0xfb73c8
  560861:	e8 2a 52 00 00       	call   0x565a90
  560866:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  56086b:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  56086e:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  560873:	89 00                	mov    DWORD PTR [eax],eax
  560875:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  56087a:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  56087d:	68 7c 06 c1 00       	push   0xc1067c
  560882:	8b c6                	mov    eax,esi
  560884:	89 1d d0 73 fb 00    	mov    DWORD PTR ds:0xfb73d0,ebx
  56088a:	e8 51 da 1c 00       	call   0x72e2e0
  56088f:	3b c3                	cmp    eax,ebx
  560891:	0f 84 8f 01 00 00    	je     0x560a26
  560897:	68 8c 33 c0 00       	push   0xc0338c
  56089c:	e8 3f da 1c 00       	call   0x72e2e0
  5608a1:	8b f0                	mov    esi,eax
  5608a3:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5608a7:	3b f3                	cmp    esi,ebx
  5608a9:	0f 84 77 01 00 00    	je     0x560a26
  5608af:	eb 04                	jmp    0x5608b5
  5608b1:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  5608b5:	8b 06                	mov    eax,DWORD PTR [esi]
  5608b7:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  5608ba:	8b ce                	mov    ecx,esi
  5608bc:	ff d2                	call   edx
  5608be:	3b c3                	cmp    eax,ebx
  5608c0:	0f 84 51 01 00 00    	je     0x560a17
  5608c6:	c7 44 24 38 0f 00 00 	mov    DWORD PTR [esp+0x38],0xf
  5608cd:	00 
  5608ce:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  5608d2:	88 5c 24 24          	mov    BYTE PTR [esp+0x24],bl
  5608d6:	8d 78 44             	lea    edi,[eax+0x44]
  5608d9:	68 88 06 c1 00       	push   0xc10688
  5608de:	c6 84 24 f4 00 00 00 	mov    BYTE PTR [esp+0xf4],0x1
  5608e5:	01 
  5608e6:	e8 b5 f7 1c 00       	call   0x7300a0
  5608eb:	3b c3                	cmp    eax,ebx
  5608ed:	74 1e                	je     0x56090d
  5608ef:	83 c0 30             	add    eax,0x30
  5608f2:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  5608f6:	72 02                	jb     0x5608fa
  5608f8:	8b 00                	mov    eax,DWORD PTR [eax]
  5608fa:	3b c3                	cmp    eax,ebx
  5608fc:	74 0f                	je     0x56090d
  5608fe:	50                   	push   eax
  5608ff:	e8 b0 0e 33 00       	call   0x8917b4
  560904:	83 c4 04             	add    esp,0x4
  560907:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  56090b:	eb 04                	jmp    0x560911
  56090d:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  560911:	68 94 33 c0 00       	push   0xc03394
  560916:	e8 85 f7 1c 00       	call   0x7300a0
  56091b:	3b c3                	cmp    eax,ebx
  56091d:	74 1c                	je     0x56093b
  56091f:	83 c0 30             	add    eax,0x30
  560922:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  560926:	72 02                	jb     0x56092a
  560928:	8b 00                	mov    eax,DWORD PTR [eax]
  56092a:	3b c3                	cmp    eax,ebx
  56092c:	74 0d                	je     0x56093b
  56092e:	50                   	push   eax
  56092f:	e8 80 0e 33 00       	call   0x8917b4
  560934:	83 c4 04             	add    esp,0x4
  560937:	8b f0                	mov    esi,eax
  560939:	eb 02                	jmp    0x56093d
  56093b:	33 f6                	xor    esi,esi
  56093d:	68 94 06 c1 00       	push   0xc10694
  560942:	e8 59 f7 1c 00       	call   0x7300a0
  560947:	3b c3                	cmp    eax,ebx
  560949:	74 0d                	je     0x560958
  56094b:	83 78 44 10          	cmp    DWORD PTR [eax+0x44],0x10
  56094f:	8d 48 30             	lea    ecx,[eax+0x30]
  560952:	72 06                	jb     0x56095a
  560954:	8b 09                	mov    ecx,DWORD PTR [ecx]
  560956:	eb 02                	jmp    0x56095a
  560958:	33 c9                	xor    ecx,ecx
  56095a:	8b c1                	mov    eax,ecx
  56095c:	8d 78 01             	lea    edi,[eax+0x1]
  56095f:	90                   	nop
  560960:	8a 10                	mov    dl,BYTE PTR [eax]
  560962:	40                   	inc    eax
  560963:	3a d3                	cmp    dl,bl
  560965:	75 f9                	jne    0x560960
  560967:	2b c7                	sub    eax,edi
  560969:	50                   	push   eax
  56096a:	51                   	push   ecx
  56096b:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  56096f:	e8 fc 20 ea ff       	call   0x402a70
  560974:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  560978:	6a ff                	push   0xffffffff
  56097a:	53                   	push   ebx
  56097b:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  56097f:	51                   	push   ecx
  560980:	bf 0f 00 00 00       	mov    edi,0xf
  560985:	8d 4c 24 54          	lea    ecx,[esp+0x54]
  560989:	89 44 24 4c          	mov    DWORD PTR [esp+0x4c],eax
  56098d:	89 74 24 50          	mov    DWORD PTR [esp+0x50],esi
  560991:	89 7c 24 68          	mov    DWORD PTR [esp+0x68],edi
  560995:	89 5c 24 64          	mov    DWORD PTR [esp+0x64],ebx
  560999:	88 5c 24 54          	mov    BYTE PTR [esp+0x54],bl
  56099d:	e8 9e 26 ea ff       	call   0x403040
  5609a2:	68 c8 73 fb 00       	push   0xfb73c8
  5609a7:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  5609ab:	c6 84 24 f4 00 00 00 	mov    BYTE PTR [esp+0xf4],0x2
  5609b2:	02 
  5609b3:	e8 98 7f 00 00       	call   0x568950
  5609b8:	8d 54 24 1c          	lea    edx,[esp+0x1c]
  5609bc:	52                   	push   edx
  5609bd:	68 c8 73 fb 00       	push   0xfb73c8
  5609c2:	8b f0                	mov    esi,eax
  5609c4:	e8 b7 7c 00 00       	call   0x568680
  5609c9:	be 10 00 00 00       	mov    esi,0x10
  5609ce:	39 74 24 5c          	cmp    DWORD PTR [esp+0x5c],esi
  5609d2:	72 0d                	jb     0x5609e1
  5609d4:	8b 44 24 48          	mov    eax,DWORD PTR [esp+0x48]
  5609d8:	50                   	push   eax
  5609d9:	e8 2e 08 33 00       	call   0x89120c
  5609de:	83 c4 04             	add    esp,0x4
  5609e1:	88 9c 24 f0 00 00 00 	mov    BYTE PTR [esp+0xf0],bl
  5609e8:	89 7c 24 5c          	mov    DWORD PTR [esp+0x5c],edi
  5609ec:	89 5c 24 58          	mov    DWORD PTR [esp+0x58],ebx
  5609f0:	88 5c 24 48          	mov    BYTE PTR [esp+0x48],bl
  5609f4:	39 74 24 38          	cmp    DWORD PTR [esp+0x38],esi
  5609f8:	72 0d                	jb     0x560a07
  5609fa:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  5609fe:	51                   	push   ecx
  5609ff:	e8 08 08 33 00       	call   0x89120c
  560a04:	83 c4 04             	add    esp,0x4
  560a07:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  560a0b:	89 7c 24 38          	mov    DWORD PTR [esp+0x38],edi
  560a0f:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  560a13:	88 5c 24 24          	mov    BYTE PTR [esp+0x24],bl
  560a17:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  560a1a:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  560a1e:	3b f3                	cmp    esi,ebx
  560a20:	0f 85 8b fe ff ff    	jne    0x5608b1
  560a26:	c7 84 24 f0 00 00 00 	mov    DWORD PTR [esp+0xf0],0xffffffff
  560a2d:	ff ff ff  
```

## 附錄 D — 本段檔案保全、交接與授權

- 不含原版 `Event.stp`、BIN、EXE、提取出的資源 XML/完整檔案；只包括研究上必要的 Lua 原文片段與 assembly / 量測 hash，避免上傳/散佈整個資源包。
- 當前**僅 `/mnt/data` 本地 Markdown**；未 Commit/Push；尚無本篇 Git blob，請勿填造提交 SHA。若未來由使用者授權提交，在 `t16/roy/chatgpt-web` 上先核對目標 branch SHA 與競爭變更、再提交完整原稿並讀回。
- 不變更 RR-0005、T01 43 筆退回狀態、`AGENTS.md`、T02/T03/T07 等主責和 `task.json`。
- S00 需要新專項 RR 時，由整合者按正式台帳建立；不把本地研究當已認領或已接受。
