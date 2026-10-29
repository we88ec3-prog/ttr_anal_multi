# T16-112 — Quest 14／子研究①：原始 QuestInfo、NPC 資源群、前置圖、QuestTalk/SceneList 反證及 BIN loader 閉合（KR）

> 編寫：chatgpt-web roy；Asia/Taipei `2026-10-30T01:02:02+08:00`。獨立原稿，沒有研究原稿 Commit／Push。研究目標：**僅 Quest14-①（資源及前置宣告）**。不擅自對 Quest14-②③④⑤ 宣告完成。

## A. 結案判定與精確範圍

**Quest14-①「原始 Client 靜態任務資源、前置宣告、NPC ID、相關教學資源關聯與資料載入」已完成有界證據核對。** 並非 T01 FULL-PASS 或 S00 STABLE；不是原版 Server 任務判定演算法已還原。

- XML 權威資源：QuestInfo ID14 存在，無 `<Demands>` 子元素；`Quest16` 唯一直接 `<Demand id="14" />`，`Quest15` 再以 `<Demand id="16"/>` 形成**靜態** `14→16→15`；Quest14 無 Rewards 相關子元素（僅表示此筆 XML 未宣告）。
- Quest14 XML `type=3, town=0, field=18, level=1, giver=10027, finisher=10027, subtype=1, subject="튜토리얼-이실리아"`，子節點 `CompleteAction type=1`、`AcceptAction type=1`；「AcceptAction/CompleteAction=1 的執行期意思」需由 Client 消費者另證，**不能把配置字面譯為自動接取/自動完成**。
- QuestInfo 中 NPC `10027` 共連到八筆任務 ID：`14, 16, 1002, 2742, 2743, 2744, 2745, 2746`（其中 1002 是 synopsis，2742–2746 為鍵盤/滑鼠/鏡頭/角色選擇/戰鬥教學）。這是 NPC 配置 ID 關聯群，不是 NPC 3D 實體/會話或世界座標已核實。
- QuestInfo **只有 Quest14 使用 `field=18`**（在所讀同一原始資源範圍內）；不由此猜測 Field map ID 18 是否為 tutorial scenario 14 或實際場景名。
- QuestTalk **4,322 個自封閉 `<Quest .../>`**：沒有 id14/15/16；QuestTalk 是另一張對話文字映射，不等於 QuestInfo 不存在或不能對話。
- `Event/SceneList.xml` 1,687 筆：找不到 `questIdx=14`/`16`，但存在 `(1000,x)` 教學演出與 `(1001,1)=tutorial_start`。`QuestInfo id14`、`Tutorial.RequestStartScenario(14)`、`SceneList (1000,14)` 是**不同命名空間**；同號數字不能混算。

## B. 來源／治理／重現性

| 來源 | 原件版號或大小 | 原生性、驗證方式 |
|---|---|---|
| `/mnt/data/Tartaros.bin` | `12,472,320` bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` | **本次逐位元組重新計算 SHA**；BIN-first，只反組譯 PE `.text`，不執行/patch |
| `/mnt/data/Tartaros.exe` | `2,594,816` bytes；SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f` | **本次重新計算**，僅為原件識別 |
| `/mnt/data/Event.stp` | `11,241,597` bytes；SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` | **本次重新計算**；SceneList/ Lua 解 XOR /原生資源，不執行客戶端 |
| `Event/SceneList.xml` 自 STP 還原 | `158,269` bytes；SHA256 `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25` | `EX v1` 解壓是先前 T16-108；本次再次從已驗證本地抽出原文檢查其 1,687 筆 XML 節點（**本次未重新解一次壓縮**） |
| `Event/TutorialBase.lua` STP chunk | `0xA27010`, 1,416 bytes；SHA256 `26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744` | 本次直接由 STP XOR `FF` 取得 Lua 5.1 chunk，**自行解析所有 proto，消耗 1416 bytes** |
| `Event/TutorialMain.lua` STP chunk | `0xA27810`, 5,480 bytes；SHA256 `662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809` | 本次直接解 XOR+解析 Lua 5.1 chunk，消耗 5480 bytes |
| `Table/QuestInfo.xml` GitHub 原文 | `kr/evidence/5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60.txt`；舊筆記證實 Git blob `1c86c9ce4f2422f84269ed9eb641202fedb9fb63` | **本次重新由 GitHub main connector 讀全文**；檢索總共 4,798 個 Quest ID（ID 全部唯一）。未將完整 2.3MB XML 傳進此本地 Python 容器，因此未重算整份 XML SHA256；上述十六進位檔名是庫內來源識別，不冒充當場重算 |
| `Table/QuestTalk.xml` GitHub 原文 | `kr/evidence/b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28.txt` | **本次 connector 重讀全文**、按 `<Quest id=N .../>` 掃描 4,322 筆、14/15/16=不存在；未重算整份 SHA |

- 使用 GitHub 啟動檢查：`main=e7416169fd20e4fcb0fe2c0b4d6207e4c9b443bc`；`t16/roy/chatgpt-web=0c8692fd18f510f7634890d626c5a93cd89467b2`，`main...T16` ahead=23, behind=0。當時 T16 inbox 無待處理 RR，正式 RR 台帳 owner=T16 為 0；T01 README 已核對（`READY_FOR_REVIEW` 不是 `RESOLVED`，不能自認 FULL-PASS）。當次明確指示 Quest14-①，故聚焦此項而非展開其他 T01 異議修稿。
- 完整目標分離：QuestInfo 的欄位與引導是 Client 資源；原版 Server 如何授予已接／已完成、獎勵、角色保存是 S00 需設計的 Server 行為；反向 Client 的 Quest state writer/UI 還屬 Quest14-③④⑤，不能偷放進①的「已完成」。

## C. 第一輪：QuestInfo 全文資源查證與前置反向索引

> 下面 XML 為 GitHub 原件擷取，保留原始韓文字段、大小寫與欄位；沒有以翻譯取代原始屬性。單個 Quest 沒有的 tag 不代表 Server 沒有該機制。

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

### C.1 欄位語意分級

| XML 欄位/節點 | 可證的值／存在性 | 不能越界推斷 |
|---|---|---|
| `id` | 唯一配置標識 Quest14，整份資源 4,798 Quest ID 全不重複 | 不能等同 ScenarioID 14／接收 command `0x0E` |
| `type` | Quest14=3；Quest16=2；同一資源 type3 另有 synopsis/教學系列 | type3 究竟自動接取、特殊 UI 模式、教學模式須看 Client 消費者 |
| `town` | Quest14=0、Quest16=0 | 不等同 0x005F sceneType 或有效地圖／世界編號 |
| `field` | Quest14=18；Quest16 缺字段 | 不等同 Scenario14，不能斷言 server instance 或客戶端何時載入 field18 |
| `level` | Quest14=1 | 實際 Level gate/Server 可接取策略未由此證明 |
| `giver/finisher` | Quest14=10027／10027 | 10027 為配置 NPC ID；不證明世界 NPC 已 spawn 或哪個 UI 畫面跳出 |
| `subtype` | Quest14=1 | subtype 的語意及 enum 值需查 Client 消費者 |
| `subject` | `튜토리얼-이실리아` | 不等同 Client 對話文字 ID |
| `<AcceptAction type="1"/>` | 確有此子元素，無 `param` XML 字段 | 不證明玩家不須按接受鍵、或 Server 自動接受 |
| `<CompleteAction type="1"/>` | 確有此子元素，無 `param` | 不證明 Scenario14 旗標直接代表 Quest14 完成 |
| `<Demands>` | Quest14 此 tag 缺；Quest16 有 Demand14 | XML 無宣告前置不等於官方 Server 全無其他限制 |
| `<RewardsEtc/RewardsItem/Contents>` | Quest14 此幾項缺席 | 不應推斷遊戲不存在任務獎勵或進度事件（只是 XML 資源未宣告） |

### C.2 完整反向 Demand14 與教學群

**全 QuestInfo 4,798 ID 掃描結果：**直接 `<Demand id="14"/>` 的只有 Quest16；Quest15 直接 `<Demand id="16"/>`。因此完整**靜態**支配/前置圖中有 `14 → 16 → 15`，但 XML 不含 server transition logic。

NPC `10027` 共有 8 個 QuestInfo 配置行（全部 giver 和 finisher 均=10027）：

| ID | type | subject 原文 | 本筆特殊資訊 |
|---:|---:|---|---|
| 14 | 3 | `튜토리얼-이실리아` | `field=18`, `CompleteAction type=1`, `AcceptAction type=1` |
| 16 | 2 | `튜토리얼-핑코파파` | `Demand 14`, `Reward type=2 value=50` |
| 1002 | 3 | `시놉시스` | 自封閉 Quest 元素，沒有其他子元素 |
| 2742 | 3 | `튜토리얼-키보드입력` | `Reward type=2 value=10` |
| 2743 | 3 | `튜토리얼-마우스입력` | `Reward type=2 value=20` |
| 2744 | 3 | `튜토리얼-카메라` | `Reward type=2 value=30` |
| 2745 | 3 | `튜토리얼-캐릭터선택` | `Reward type=2 value=40` |
| 2746 | 3 | `튜토리얼-전투` | `Reward type=2 value=50` |

資源中的 `type=3` 也剛好只有 **7 筆**，即 Quest14、1002、2742–2746；這提供一條可測「教學類配置群」的線索，**不是**Client 已證 `type=3 == tutorial` 判斷或觸發式。唯一 `field=18` 的 QuestInfo 也是 Quest14，不能從僅一筆的關聯倒推出 map ID 相等。

### C.3 QuestTalk 缺失的正確表述

QuestTalk 是另一份 `Table/QuestTalk.xml`，根節點 `<QuestTalk>`；全篇 4,322 `<Quest id="..." .../>`，找不到 `id="14"`、`id="15"`、`id="16"`。**只能證明在此檔缺少同 ID 對話索引**；不能證明 NPC 10027 沒對話、不能證明 Quest 不存在，因為 Event Lua/TalkScene 可用不同鍵管理本地劇情與提示。

## D. 第二輪：原始 BIN XML 讀取／欄位辨識／條件分支（BIN-first）

### D.1 PE VA 與 raw 正確映射

KR BIN `.text`: VirtualAddress=0x00401000, PointerToRawData=0x00000400，故 `.text` raw=`VA−0x00400C00`；`.rdata`: VA 0x00BD2000, raw 0x007D0600。以這兩組分節映射在**本次原件**讀出以下 NULL 終止字串，不把 literal VA 當 .text 偏移：

| RDATA VA | 字面 |
|---|---|
| `0x00C0DB48` | `Table/QuestInfo.xml` |
| `0x00C0DB5C` | `Table/QuestTalk.xml` |
| `0x00C0DB70` | `QuestInfo` |
| `0x00C0DB94` | `subtype` |
| `0x00C0DB9C` | `level` |
| `0x00C0DBA4` | `giver` |
| `0x00C0DBAC` | `finisher` |
| `0x00C0DBB8` | `town` |
| `0x00C0DBC0` | `field` |
| `0x00C0DBC8` | `subject` |
| `0x00C0DBD0` | `AcceptAction` |
| `0x00C0DBE8` | `CompleteAction` |
| `0x00C0DBF8` | `Demands` |
| `0x00C0DC00` | `Demand` |
| `0x00C0DC08` | `RewardsEtc` |
| `0x00C0DC14` | `Reward` |
| `0x00C0DC24` | `RewardsItem` |
| `0x00C0DC38` | `Contents` |
| `0x00C0DC44` | `QuestTalk` |

### D.2 loader 真實上游、分開的 XML 入口及異常

- **`0x504370`** 組裝一個 QuestInfo 容器（`0x50439F push 0xB8` 配置紅黑樹 sentinel 節點，`0x5043B5` 檢查配置失敗），並**依序**在 `0x5043E9 call 0x504740` 載入 QuestInfo、`0x5043EF call 0x505570` 載入 QuestTalk。不能只從同一 caller 推斷兩個 XML 是同一張索引。
- **`0x504740`** 在 `0x50478B` 以 `ECX=0xC0DB48` 準備 QuestInfo 路徑呼叫 `0x72EE30`，`0x5047C6` 呼叫 `0x72F110`，`0x5047CB` 接著讀文件有效性旗標。若 gate 失敗則 `0x504831` 前退出；不是每次載入必成功。
- `0x504831` 將根節點字面 `QuestInfo` 交給 `0x72E2E0`，`0x504842` 檢查非零；miss 路徑 `0x504846→0x6EDB60` 記錄錯誤並返回失敗。不允許說即便檔案錯誤也必然有 Quest14 record。
- `0x5048C0..0x504A5E` 在迴圈中解析一筆 `<Quest>` 所在節點的 `subtype,level,giver,finisher,town,field,subject` 等，依字面調用 `0x7300A0` 取 attribute，再調 `0x8917B4` 作數字轉換（精確行為只據目前已見通用字串數字 helper 作候選，不宣稱它保證處理所有畸形數值）。Quest ID/type 在此前或間接節點處另取得；目前未把每個 stack slot 冒稱完整的 C++ struct layout。
- `0x504ADF` 用字面 `AcceptAction` 呼叫 `0x72E360` 找子元素，存在時讀 `type`（literal 位於 `0xBED1D0`）及 `param` (`0xC0DBE0`)；不存在時走 `0x504B52`。`0x504B52` 對 `CompleteAction` 做相似分支，缺席轉 `0x504BC5`。**配置有兩個 Action child 不等於原 Client 已執行這些 Action**。
- `0x504BC5` 查 `<Demands>`；`0x504BD9`/`0x504CBE` 尋找及巡迴子 `<Demand>`；存在時轉換其 id 值並累加候選清單，**證明 Client loader 確會讀 XML 中的 Demand graph**。若沒有 Demands 走 `0x504CCD`；Quest14 正屬此路徑形狀。
- 之後解析 RewardsEtc (`0x504CEB`)、RewardsItem (`0x504E4A` / `0x5051FD`) 與 Contents (`0x505242`) 等，最後 `0x5053FB..0x505438` 生成並插入已解析的 Quest record，`0x505464..0x505471` 迴圈推進到下一個 Quest node；`0x5054D3 mov eax,1` 是 successful loader return，**不等同成功完成任何 Quest**。

### D.3 原始機器碼出發的正確條件與錯誤邊

```text
QuestMgr initialize 0x504370
  ├─ allocate sentinel, OOM branch → 0x504522
  ├─ 0x5043E9 QuestInfo parser 0x504740
  │    ├─ open / parse gate 0x5047C6 / 0x5047CB, failure→0x504831
  │    ├─ root "QuestInfo" existence 0x504831 / 0x504842, miss→0x504846 log
  │    ├─ for each node attributes + action/demand/reward subtree
  │    ├─ 0x5053FB..0x505438 record insertion
  │    └─ 0x5054D3 return success(1)
  └─ 0x5043EF QuestTalk parser 0x505570, different root/index
```

**反證**：`0x5047xx` 只讀靜態資料，不是 Quest14 runtime C→S 接取封包 builder，也不證明 Server 的任務完成策略。Client Quest XML 存在，不表示原版角色狀態可獲得 Quest14。

## E. 第三輪：STP Tutorial Lua、SceneList 名稱空間交叉、NPC 同號與否證

### E.1 Event/TutorialBase.lua 原件 Lua 5.1 bytecode 已被重新解析

從 Event.stp XOR view 直接定位 chunk `0xA27010..0xA27598` （1,416 bytes），Lua 5.1 header `1B 4C 75 61 51`。Lua 反序列化器對根 proto 及 5 個 nested protos 全部讀完，精確 consumed=1,416。原始 constants/名稱包括：

```text
TUTORIAL_KEYBOARD, TUTORIAL_MOUSE, TUTORIAL_CAMERA,
TUTORIAL_LEADER_CHANGE, TUTORIAL_LC_DLG_OPENED, TUTORIAL_GOTO_NPC,
TUTORIAL_EMPTY, TUTORIAL_PINKOHOUSE, TUTORIAL_STARTSCENARIO,
TUTORIAL_CHANGEKEYTYPE
CHECKPOINT_CATEGORY: PORTAL, SAVEPOINT, MARKET, NPC, TUTORIAL_POINT, CLIENT_CUSTOM
CHECKPOINT_STATUS: ST_CLOSE, ST_OPEN, ST_MAX
```

這些是**本地 Lua 常數群**；原件沒有在這個 constant table 將它們與 QuestInfo id14 的 `type=3` 或 NPC10027 建立一對一映射。因此只能建立「教學 UI/輸入階段存在」的資源關聯，不能把 2742–2746 五個 Quest 宣告直接等同每個 checkpoint 執行結果。

### E.2 TutorialMain.lua 與 Quest14 資源界線

本次 STP chunk `0xA27810`, 5,480 bytes 以 Lua 5.1 parser 完整讀入，與 T16-111 的 `Tutorial_Part2` 一致：它用 native `Tutorial.RequestStartScenario(14)`，再 poll `Tutorial.IsScenarioEnded(14)`。**ScenarioId 14 已在 T16-111 有 `0x40` 發包／`0x4C` 本地結束 flag 的完整有界 Client 介面；但沒有此證據就不能反推 QuestInfo ID14 的 `AcceptAction`/`CompleteAction` 被同時觸發。**這部分的動態 Quest↔Scenario mapping 屬 Quest14-②③④⑤，而非 ① 源資料解讀。

### E.3 原始 SceneList 全集按 questIdx 精確負向核對

- `(questIdx=14, any sceneIdx)`：**0 筆**；`questIdx=16`：**0 筆**；這是只對本份 1,687 筆 SceneList 的精確負向結論，不代表 Event 完全沒有 Quest14 的任務動作或場景動畫。
- `(1000,sceneIdx)` 共 15 筆，包含 `sceneIdx=14` 的 `funcName=talkevent10_1`；此處的 `sceneIdx=14` **不是** `questIdx=14`，不可與 QuestInfo ID14 合併。
- `(1001,1)` 一筆：`tutorial_start`；不能與 Lua 的 `PlayAndWaitForScene(1000,1)` 合併。
- `(15,sceneIdx=1..4)` 四筆：`Square_Tutorial01`, `scenario_tuto1_1`, `pindos_talkevent`, `scenario_tuto2_1`。這是後續 Quest15 本地演出資源，有一段 script `LoadMap("town001D.map")`；與 Quest14 的 `field=18` 無 direct map ID 證據。

```text
Event/SceneList.xml relevant keys:

1000/1: talkevent1_1, endBehavior=0
1000/3: talkevent2_1, endBehavior=0
1000/4: talkevent3_1, endBehavior=0
1000/6: talkevent4_1, endBehavior=0
1000/7: talkevent5_1, endBehavior=0
1000/8: talkevent6_1, endBehavior=0
1000/9: tutorial5_1, endBehavior=0
1000/10: talkevent7_1, endBehavior=0
1000/12: talkevent8_1, endBehavior=0
1000/13: talkevent9_1, endBehavior=0
1000/14: talkevent10_1, endBehavior=0
1000/15: Synopsis_Tartaros, endBehavior=0
1000/16: Synopsis_Tartaros2, endBehavior=0
1000/17: Synopsis_Tartaros3, endBehavior=0
1000/18: Synopsis_Tartaros4, endBehavior=0
1001/1: tutorial_start, endBehavior=0
15/1: Square_Tutorial01, endBehavior=0
15/2: scenario_tuto1_1, endBehavior=0
15/3: pindos_talkevent, endBehavior=0
15/4: scenario_tuto2_1, endBehavior=0
```

### E.4 證據必要否定項

1. 不能從 QuestInfo `field=18` 宣稱 Scenario14 屬於 field18、或當然是在同一地圖執行；這缺實際 Client field/map selector 連線。
2. 不能把 `Quest14 type3` 和其他教學 type3 宣稱必然隱藏、auto-accept/auto-complete，必須查 runtime UI 消費分支。
3. QuestTalk 的同號缺席，不否定 NPC 顯示／對話：Lua/TalkScene 是獨立 namespace。
4. Quest14 沒有 `<Demands>`、`RewardsEtc`，只是配置缺席，不等於 Server 沒有狀態限制或發獎事件。
5. Quest14 的 `AcceptAction/CompleteAction` 由 loader 解析已證，**真正觸發處與執行後的 C2S/S2C UI**，分給 Quest14-②③④⑤。
6. 不使用舊的 `005F type6` tutorial fixture、RR-0005（屬 T02 登入）或不符合該版本的其他遊戲資源填補原生缺口。

## F. Quest 14 × 五子研究進度與 S00 交接

| Quest14 子研究 | 本次後狀態 | 目前精確邊界/後續項目 |
|---|---|---|
| **① QuestInfo 資源／前置／NPC ID** | **已完成（原生有界資源結案）** | 本篇已收齊 XML 原文、對 Quest16 的唯一反向 Demand14、NPC10027八筆靜態群、QuestTalk/SceneList 限定負例、Client BIN 原生 parser/Lua checkpoint 來源。**不包含 Server state 判定** |
| ② 玩家觸發／接取 | **部分** | Scenario14 請求的本地教學腳本路徑已由 T16-111 證，QuestInfo ID14 接取是否需 UI 操作、AcceptAction 的真正 runtime consumer 未追至 Quest14 專屬操作 |
| ③ C→S 發送 | **部分** | Scenario14 `cmd 0x40 + WORD id14` 已證，正式 Quest14 接取／交付 C→S 是否存在與其 opcode/長度/字段未閉合 |
| ④ S→C／狀態／UI | **部分** | CTutorial Scenario14 `0x4C + WORD id14` 更新 scenario flag 已證；Quest14 QuestInfo accepted/completed runtime owner + NPC badge/UI 仍不等同此 flag |
| ⑤ 完成 Quest14 → Quest16 | **部分** | XML 唯一直接 Demand14→Quest16 已證；Client 的 Quest14 completed→Quest16 可接入/UI 更新與 Server 下發資料仍需查 |

### 交接到 S00 — 屬於 Server 待設計，不是 T16-① 未完成

- **DRAFT Server state model**：為角色定義 `quest14`、`quest16` 與 `scenario14` 的權威狀態及關聯策略（不得假冒原版）；包含接受/完成/獎勵/解鎖/冪等/重登。S00 收納成 ADR/規格草案，實際 Server 開發另行處理。
- **T16 Client 待逆向但不屬①**：Quest14 的 `AcceptAction/CompleteAction` 消費者是否產生 C→S、S→C 任務記錄如何標示 Quest14 accepted/completed、NPC10027 badge/UI 如何更新、Quest16 允許接取時需何種 Client 資料。未知的 wire 欄位不可推給 S00 猜測。
- **待遊玩驗證**：原版 Client 的實際場景/NPC 出現與可接清單、14→16 顯示轉換、field18 的實際載入；本篇僅靜態反組譯／資源，不宣稱已實際遊玩。

## G. 三輪深入紀錄、完成理由

1. **第一輪**：本次重讀 GitHub 全 QuestInfo+QuestTalk 原文，核實 Quest14 8 屬性/2 Actions/無 Demands、Quest16 唯一直接反向 demand、NPC10027 的八筆教學群與 type3 七筆/field18 唯一性。產出超越 T16-108 的完整反向關聯和明確 negative。
2. **第二輪**：本機 KR BIN 直接重算 hash，反組譯 `0x504370/0x504740..0x5054D8` 並從 `.rdata` 獨立按正確 section raw offset 核對所有 key literal、loader CFG、查找字面與 optional 子元素、存入容器及失敗分支。
3. **第三輪**：本機 STP direct XOR 載入 Lua5.1 TutorialBase(1,416B) / TutorialMain(5,480B) 全 proto；SceneList 1,687 row key scan 證實 questIdx14/16缺席而 1000/1001 演出為獨立 namespace；把 ① 的已證資源邊界與②～⑤動態欠缺切開。

**停止/結案原因**：① 的「配置存在/唯一性、前置與跨資源名稱空間、Client parser/load path、失敗邊界」已由第一手 XML/BIN/STP 多來源有界閉合。繼續追 Quest14 accept/complete 動態通知應屬②③④⑤，不應要求①先還原所有 Server 行為或在①中無限追未知 socket；本篇不宣稱 T01 正式審核 FULL-PASS。

## H. 可重現 BIN 指令附錄（每條地址以 `VA − 0x400C00` 回算原始 raw）

所有反組譯由以下指令對**本次本地原件**重新產生（**不是**來自 Ghidra/舊偽碼）：

```bash
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
 --start-address=0x504370 --stop-address=0x504428 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
 --start-address=0x504740 --stop-address=0x5054d9 /mnt/data/Tartaros.bin
```

節錄之完整 disasm 區間，開頭以已驗證函式入口對齊；中途含函式資料或 branch-dependent code 時不可把線性 objdump 的所有行視為可執行 CFG，必須連分支使用。

### QuestManager parent loader 0x504370：VA `0x00504370..0x00504428` raw `0x103770..0x103828`, span SHA256 `29476c39d5b7b227795758f444a76610378645578342f2071d6bbfe6371076b2`
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
### QuestInfo parser open+root gate：VA `0x00504740..0x005048C0` raw `0x103B40..0x103CC0`, span SHA256 `96cc9a01d00c051bc741c10b7206ba7a0be59dd70d73dfe0990701364a58462a`
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
  504804:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50480b:	c7 84 24 8c 01 00 00 	mov    DWORD PTR [esp+0x18c],0xf
  504812:	0f 00 00 00 
  504816:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  50481d:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  504824:	00 
  504825:	e8 16 98 22 00       	call   0x72e040
  50482a:	33 c0                	xor    eax,eax
  50482c:	e9 a7 0c 00 00       	jmp    0x5054d8
  504831:	68 70 db c0 00       	push   0xc0db70
  504836:	8d 84 24 30 01 00 00 	lea    eax,[esp+0x130]
  50483d:	e8 9e 9a 22 00       	call   0x72e2e0
  504842:	3b c7                	cmp    eax,edi
  504844:	75 69                	jne    0x5048af
  504846:	68 7c db c0 00       	push   0xc0db7c
  50484b:	e8 10 93 1e 00       	call   0x6edb60
  504850:	c7 84 24 64 02 00 00 	mov    DWORD PTR [esp+0x264],0xffffffff
  504857:	ff ff ff ff 
  50485b:	83 c4 04             	add    esp,0x4
  50485e:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  504865:	94 23 bf 00 
  504869:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  504870:	72 10                	jb     0x504882
  504872:	8b 84 24 78 01 00 00 	mov    eax,DWORD PTR [esp+0x178]
  504879:	50                   	push   eax
  50487a:	e8 8d c9 38 00       	call   0x89120c
  50487f:	83 c4 04             	add    esp,0x4
  504882:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  504889:	c7 84 24 8c 01 00 00 	mov    DWORD PTR [esp+0x18c],0xf
  504890:	0f 00 00 00 
  504894:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  50489b:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  5048a2:	00 
  5048a3:	e8 98 97 22 00       	call   0x72e040
  5048a8:	33 c0                	xor    eax,eax
  5048aa:	e9 29 0c 00 00       	jmp    0x5054d8
  5048af:	8b 40 18             	mov    eax,DWORD PTR [eax+0x18]
  5048b2:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  5048b6:	3b c7                	cmp    eax,edi
  5048b8:	0f 84 c0 0b 00 00    	je     0x50547e
  5048be:	8b ff                	mov    edi,edi
```
### Quest item attrs and optional actions：VA `0x005048C0..0x00504BC5` raw `0x103CC0..0x103FC5`, span SHA256 `98e7a1067654ad85696e452927bdef964cd6bb35beb0ab600dcfa0c14f9a37a3`
```asm
005048c0 <.data+0x103cc0>:
  5048c0:	8d 4c 24 64          	lea    ecx,[esp+0x64]
  5048c4:	51                   	push   ecx
  5048c5:	e8 56 b0 ff ff       	call   0x4ff920
  5048ca:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  5048ce:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x1
  5048d5:	01 
  5048d6:	8b 11                	mov    edx,DWORD PTR [ecx]
  5048d8:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  5048db:	ff d0                	call   eax
  5048dd:	8d 78 44             	lea    edi,[eax+0x44]
  5048e0:	68 d0 d1 be 00       	push   0xbed1d0
  5048e5:	e8 b6 b7 22 00       	call   0x7300a0
  5048ea:	bb 10 00 00 00       	mov    ebx,0x10
  5048ef:	85 c0                	test   eax,eax
  5048f1:	74 19                	je     0x50490c
  5048f3:	83 c0 30             	add    eax,0x30
  5048f6:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  5048f9:	72 02                	jb     0x5048fd
  5048fb:	8b 00                	mov    eax,DWORD PTR [eax]
  5048fd:	85 c0                	test   eax,eax
  5048ff:	74 0b                	je     0x50490c
  504901:	50                   	push   eax
  504902:	e8 ad ce 38 00       	call   0x8917b4
  504907:	83 c4 04             	add    esp,0x4
  50490a:	eb 02                	jmp    0x50490e
  50490c:	33 c0                	xor    eax,eax
  50490e:	68 08 b8 bf 00       	push   0xbfb808
  504913:	89 44 24 68          	mov    DWORD PTR [esp+0x68],eax
  504917:	e8 84 b7 22 00       	call   0x7300a0
  50491c:	85 c0                	test   eax,eax
  50491e:	74 19                	je     0x504939
  504920:	83 c0 30             	add    eax,0x30
  504923:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504926:	72 02                	jb     0x50492a
  504928:	8b 00                	mov    eax,DWORD PTR [eax]
  50492a:	85 c0                	test   eax,eax
  50492c:	74 0b                	je     0x504939
  50492e:	50                   	push   eax
  50492f:	e8 80 ce 38 00       	call   0x8917b4
  504934:	83 c4 04             	add    esp,0x4
  504937:	eb 02                	jmp    0x50493b
  504939:	33 c0                	xor    eax,eax
  50493b:	68 94 db c0 00       	push   0xc0db94
  504940:	89 44 24 6c          	mov    DWORD PTR [esp+0x6c],eax
  504944:	e8 57 b7 22 00       	call   0x7300a0
  504949:	85 c0                	test   eax,eax
  50494b:	74 19                	je     0x504966
  50494d:	83 c0 30             	add    eax,0x30
  504950:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504953:	72 02                	jb     0x504957
  504955:	8b 00                	mov    eax,DWORD PTR [eax]
  504957:	85 c0                	test   eax,eax
  504959:	74 0b                	je     0x504966
  50495b:	50                   	push   eax
  50495c:	e8 53 ce 38 00       	call   0x8917b4
  504961:	83 c4 04             	add    esp,0x4
  504964:	eb 02                	jmp    0x504968
  504966:	33 c0                	xor    eax,eax
  504968:	68 9c db c0 00       	push   0xc0db9c
  50496d:	89 44 24 70          	mov    DWORD PTR [esp+0x70],eax
  504971:	e8 2a b7 22 00       	call   0x7300a0
  504976:	85 c0                	test   eax,eax
  504978:	74 19                	je     0x504993
  50497a:	83 c0 30             	add    eax,0x30
  50497d:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504980:	72 02                	jb     0x504984
  504982:	8b 00                	mov    eax,DWORD PTR [eax]
  504984:	85 c0                	test   eax,eax
  504986:	74 0b                	je     0x504993
  504988:	50                   	push   eax
  504989:	e8 26 ce 38 00       	call   0x8917b4
  50498e:	83 c4 04             	add    esp,0x4
  504991:	eb 02                	jmp    0x504995
  504993:	33 c0                	xor    eax,eax
  504995:	68 a4 db c0 00       	push   0xc0dba4
  50499a:	89 44 24 74          	mov    DWORD PTR [esp+0x74],eax
  50499e:	e8 fd b6 22 00       	call   0x7300a0
  5049a3:	85 c0                	test   eax,eax
  5049a5:	74 19                	je     0x5049c0
  5049a7:	83 c0 30             	add    eax,0x30
  5049aa:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  5049ad:	72 02                	jb     0x5049b1
  5049af:	8b 00                	mov    eax,DWORD PTR [eax]
  5049b1:	85 c0                	test   eax,eax
  5049b3:	74 0b                	je     0x5049c0
  5049b5:	50                   	push   eax
  5049b6:	e8 f9 cd 38 00       	call   0x8917b4
  5049bb:	83 c4 04             	add    esp,0x4
  5049be:	eb 02                	jmp    0x5049c2
  5049c0:	33 c0                	xor    eax,eax
  5049c2:	68 ac db c0 00       	push   0xc0dbac
  5049c7:	89 84 24 90 00 00 00 	mov    DWORD PTR [esp+0x90],eax
  5049ce:	e8 cd b6 22 00       	call   0x7300a0
  5049d3:	85 c0                	test   eax,eax
  5049d5:	74 19                	je     0x5049f0
  5049d7:	83 c0 30             	add    eax,0x30
  5049da:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  5049dd:	72 02                	jb     0x5049e1
  5049df:	8b 00                	mov    eax,DWORD PTR [eax]
  5049e1:	85 c0                	test   eax,eax
  5049e3:	74 0b                	je     0x5049f0
  5049e5:	50                   	push   eax
  5049e6:	e8 c9 cd 38 00       	call   0x8917b4
  5049eb:	83 c4 04             	add    esp,0x4
  5049ee:	eb 02                	jmp    0x5049f2
  5049f0:	33 c0                	xor    eax,eax
  5049f2:	68 b8 db c0 00       	push   0xc0dbb8
  5049f7:	89 84 24 94 00 00 00 	mov    DWORD PTR [esp+0x94],eax
  5049fe:	e8 9d b6 22 00       	call   0x7300a0
  504a03:	85 c0                	test   eax,eax
  504a05:	74 19                	je     0x504a20
  504a07:	83 c0 30             	add    eax,0x30
  504a0a:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504a0d:	72 02                	jb     0x504a11
  504a0f:	8b 00                	mov    eax,DWORD PTR [eax]
  504a11:	85 c0                	test   eax,eax
  504a13:	74 0b                	je     0x504a20
  504a15:	50                   	push   eax
  504a16:	e8 99 cd 38 00       	call   0x8917b4
  504a1b:	83 c4 04             	add    esp,0x4
  504a1e:	eb 02                	jmp    0x504a22
  504a20:	33 c0                	xor    eax,eax
  504a22:	68 c0 db c0 00       	push   0xc0dbc0
  504a27:	89 84 24 88 00 00 00 	mov    DWORD PTR [esp+0x88],eax
  504a2e:	e8 6d b6 22 00       	call   0x7300a0
  504a33:	85 c0                	test   eax,eax
  504a35:	74 19                	je     0x504a50
  504a37:	83 c0 30             	add    eax,0x30
  504a3a:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504a3d:	72 02                	jb     0x504a41
  504a3f:	8b 00                	mov    eax,DWORD PTR [eax]
  504a41:	85 c0                	test   eax,eax
  504a43:	74 0b                	je     0x504a50
  504a45:	50                   	push   eax
  504a46:	e8 69 cd 38 00       	call   0x8917b4
  504a4b:	83 c4 04             	add    esp,0x4
  504a4e:	eb 02                	jmp    0x504a52
  504a50:	33 c0                	xor    eax,eax
  504a52:	68 c8 db c0 00       	push   0xc0dbc8
  504a57:	89 84 24 8c 00 00 00 	mov    DWORD PTR [esp+0x8c],eax
  504a5e:	e8 3d b6 22 00       	call   0x7300a0
  504a63:	85 c0                	test   eax,eax
  504a65:	74 0c                	je     0x504a73
  504a67:	39 58 44             	cmp    DWORD PTR [eax+0x44],ebx
  504a6a:	8d 48 30             	lea    ecx,[eax+0x30]
  504a6d:	72 06                	jb     0x504a75
  504a6f:	8b 09                	mov    ecx,DWORD PTR [ecx]
  504a71:	eb 02                	jmp    0x504a75
  504a73:	33 c9                	xor    ecx,ecx
  504a75:	8b c1                	mov    eax,ecx
  504a77:	c7 44 24 5c 0f 00 00 	mov    DWORD PTR [esp+0x5c],0xf
  504a7e:	00 
  504a7f:	c7 44 24 58 00 00 00 	mov    DWORD PTR [esp+0x58],0x0
  504a86:	00 
  504a87:	c6 44 24 48 00       	mov    BYTE PTR [esp+0x48],0x0
  504a8c:	8d 70 01             	lea    esi,[eax+0x1]
  504a8f:	90                   	nop
  504a90:	8a 10                	mov    dl,BYTE PTR [eax]
  504a92:	40                   	inc    eax
  504a93:	84 d2                	test   dl,dl
  504a95:	75 f9                	jne    0x504a90
  504a97:	2b c6                	sub    eax,esi
  504a99:	50                   	push   eax
  504a9a:	51                   	push   ecx
  504a9b:	8d 4c 24 50          	lea    ecx,[esp+0x50]
  504a9f:	e8 cc df ef ff       	call   0x402a70
  504aa4:	8d 4c 24 48          	lea    ecx,[esp+0x48]
  504aa8:	51                   	push   ecx
  504aa9:	8d 84 24 b4 00 00 00 	lea    eax,[esp+0xb4]
  504ab0:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x2
  504ab7:	02 
  504ab8:	e8 73 b6 f3 ff       	call   0x440130
  504abd:	83 c4 04             	add    esp,0x4
  504ac0:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x1
  504ac7:	01 
  504ac8:	39 5c 24 5c          	cmp    DWORD PTR [esp+0x5c],ebx
  504acc:	72 0d                	jb     0x504adb
  504ace:	8b 54 24 48          	mov    edx,DWORD PTR [esp+0x48]
  504ad2:	52                   	push   edx
  504ad3:	e8 34 c7 38 00       	call   0x89120c
  504ad8:	83 c4 04             	add    esp,0x4
  504adb:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  504adf:	bf d0 db c0 00       	mov    edi,0xc0dbd0
  504ae4:	8b c6                	mov    eax,esi
  504ae6:	e8 75 98 22 00       	call   0x72e360
  504aeb:	85 c0                	test   eax,eax
  504aed:	74 63                	je     0x504b52
  504aef:	8d 78 44             	lea    edi,[eax+0x44]
  504af2:	68 08 b8 bf 00       	push   0xbfb808
  504af7:	e8 a4 b5 22 00       	call   0x7300a0
  504afc:	85 c0                	test   eax,eax
  504afe:	74 19                	je     0x504b19
  504b00:	83 c0 30             	add    eax,0x30
  504b03:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504b06:	72 02                	jb     0x504b0a
  504b08:	8b 00                	mov    eax,DWORD PTR [eax]
  504b0a:	85 c0                	test   eax,eax
  504b0c:	74 0b                	je     0x504b19
  504b0e:	50                   	push   eax
  504b0f:	e8 a0 cc 38 00       	call   0x8917b4
  504b14:	83 c4 04             	add    esp,0x4
  504b17:	eb 02                	jmp    0x504b1b
  504b19:	33 c0                	xor    eax,eax
  504b1b:	68 e0 db c0 00       	push   0xc0dbe0
  504b20:	89 84 24 a4 00 00 00 	mov    DWORD PTR [esp+0xa4],eax
  504b27:	e8 74 b5 22 00       	call   0x7300a0
  504b2c:	85 c0                	test   eax,eax
  504b2e:	74 19                	je     0x504b49
  504b30:	83 c0 30             	add    eax,0x30
  504b33:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504b36:	72 02                	jb     0x504b3a
  504b38:	8b 00                	mov    eax,DWORD PTR [eax]
  504b3a:	85 c0                	test   eax,eax
  504b3c:	74 0b                	je     0x504b49
  504b3e:	50                   	push   eax
  504b3f:	e8 70 cc 38 00       	call   0x8917b4
  504b44:	83 c4 04             	add    esp,0x4
  504b47:	eb 02                	jmp    0x504b4b
  504b49:	33 c0                	xor    eax,eax
  504b4b:	89 84 24 a4 00 00 00 	mov    DWORD PTR [esp+0xa4],eax
  504b52:	bf e8 db c0 00       	mov    edi,0xc0dbe8
  504b57:	8b c6                	mov    eax,esi
  504b59:	e8 02 98 22 00       	call   0x72e360
  504b5e:	85 c0                	test   eax,eax
  504b60:	74 63                	je     0x504bc5
  504b62:	8d 78 44             	lea    edi,[eax+0x44]
  504b65:	68 08 b8 bf 00       	push   0xbfb808
  504b6a:	e8 31 b5 22 00       	call   0x7300a0
  504b6f:	85 c0                	test   eax,eax
  504b71:	74 19                	je     0x504b8c
  504b73:	83 c0 30             	add    eax,0x30
  504b76:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504b79:	72 02                	jb     0x504b7d
  504b7b:	8b 00                	mov    eax,DWORD PTR [eax]
  504b7d:	85 c0                	test   eax,eax
  504b7f:	74 0b                	je     0x504b8c
  504b81:	50                   	push   eax
  504b82:	e8 2d cc 38 00       	call   0x8917b4
  504b87:	83 c4 04             	add    esp,0x4
  504b8a:	eb 02                	jmp    0x504b8e
  504b8c:	33 c0                	xor    eax,eax
  504b8e:	68 e0 db c0 00       	push   0xc0dbe0
  504b93:	89 84 24 ac 00 00 00 	mov    DWORD PTR [esp+0xac],eax
  504b9a:	e8 01 b5 22 00       	call   0x7300a0
  504b9f:	85 c0                	test   eax,eax
  504ba1:	74 19                	je     0x504bbc
  504ba3:	83 c0 30             	add    eax,0x30
  504ba6:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  504ba9:	72 02                	jb     0x504bad
  504bab:	8b 00                	mov    eax,DWORD PTR [eax]
  504bad:	85 c0                	test   eax,eax
  504baf:	74 0b                	je     0x504bbc
  504bb1:	50                   	push   eax
  504bb2:	e8 fd cb 38 00       	call   0x8917b4
  504bb7:	83 c4 04             	add    esp,0x4
  504bba:	eb 02                	jmp    0x504bbe
  504bbc:	33 c0                	xor    eax,eax
  504bbe:	89 84 24 ac 00 00 00 	mov    DWORD PTR [esp+0xac],eax
```
### Demand graph XML child iterator：VA `0x00504BC5..0x00504CCD` raw `0x103FC5..0x1040CD`, span SHA256 `d0af28e9668b0fdfcbe1e0062be95e0f90e657735923060e19a6ead3a73f6d35`
```asm
00504bc5 <.data+0x103fc5>:
  504bc5:	68 f8 db c0 00       	push   0xc0dbf8
  504bca:	8b c6                	mov    eax,esi
  504bcc:	e8 0f 97 22 00       	call   0x72e2e0
  504bd1:	85 c0                	test   eax,eax
  504bd3:	0f 84 f4 00 00 00    	je     0x504ccd
  504bd9:	bf 00 dc c0 00       	mov    edi,0xc0dc00
  504bde:	e8 7d 97 22 00       	call   0x72e360
  504be3:	8b d8                	mov    ebx,eax
  504be5:	85 db                	test   ebx,ebx
  504be7:	0f 84 e0 00 00 00    	je     0x504ccd
  504bed:	8d 49 00             	lea    ecx,[ecx+0x0]
  504bf0:	8b b3 94 00 00 00    	mov    esi,DWORD PTR [ebx+0x94]
  504bf6:	8d 7b 44             	lea    edi,[ebx+0x44]
  504bf9:	3b f7                	cmp    esi,edi
  504bfb:	74 27                	je     0x504c24
  504bfd:	8d 49 00             	lea    ecx,[ecx+0x0]
  504c00:	83 7e 28 10          	cmp    DWORD PTR [esi+0x28],0x10
  504c04:	8d 46 14             	lea    eax,[esi+0x14]
  504c07:	72 02                	jb     0x504c0b
  504c09:	8b 00                	mov    eax,DWORD PTR [eax]
  504c0b:	68 d0 d1 be 00       	push   0xbed1d0
  504c10:	50                   	push   eax
  504c11:	e8 9b f0 38 00       	call   0x893cb1
  504c16:	83 c4 08             	add    esp,0x8
  504c19:	85 c0                	test   eax,eax
  504c1b:	74 51                	je     0x504c6e
  504c1d:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  504c20:	3b f7                	cmp    esi,edi
  504c22:	75 dc                	jne    0x504c00
  504c24:	33 f6                	xor    esi,esi
  504c26:	8b 44 24 78          	mov    eax,DWORD PTR [esp+0x78]
  504c2a:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  504c2e:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  504c32:	3b c8                	cmp    ecx,eax
  504c34:	73 58                	jae    0x504c8e
  504c36:	8b d1                	mov    edx,ecx
  504c38:	8b 4c 24 74          	mov    ecx,DWORD PTR [esp+0x74]
  504c3c:	3b ca                	cmp    ecx,edx
  504c3e:	77 4e                	ja     0x504c8e
  504c40:	8b f2                	mov    esi,edx
  504c42:	2b f1                	sub    esi,ecx
  504c44:	c1 fe 02             	sar    esi,0x2
  504c47:	3b 44 24 7c          	cmp    eax,DWORD PTR [esp+0x7c]
  504c4b:	75 16                	jne    0x504c63
  504c4d:	b9 01 00 00 00       	mov    ecx,0x1
  504c52:	8d 44 24 74          	lea    eax,[esp+0x74]
  504c56:	e8 e5 15 1d 00       	call   0x6d6240
  504c5b:	8b 44 24 78          	mov    eax,DWORD PTR [esp+0x78]
  504c5f:	8b 4c 24 74          	mov    ecx,DWORD PTR [esp+0x74]
  504c63:	85 c0                	test   eax,eax
  504c65:	74 49                	je     0x504cb0
  504c67:	8b 0c b1             	mov    ecx,DWORD PTR [ecx+esi*4]
  504c6a:	89 08                	mov    DWORD PTR [eax],ecx
  504c6c:	eb 3e                	jmp    0x504cac
  504c6e:	85 f6                	test   esi,esi
  504c70:	74 b2                	je     0x504c24
  504c72:	83 7e 44 10          	cmp    DWORD PTR [esi+0x44],0x10
  504c76:	8d 46 30             	lea    eax,[esi+0x30]
  504c79:	72 02                	jb     0x504c7d
  504c7b:	8b 00                	mov    eax,DWORD PTR [eax]
  504c7d:	85 c0                	test   eax,eax
  504c7f:	74 a3                	je     0x504c24
  504c81:	50                   	push   eax
  504c82:	e8 2d cb 38 00       	call   0x8917b4
  504c87:	83 c4 04             	add    esp,0x4
  504c8a:	8b f0                	mov    esi,eax
  504c8c:	eb 98                	jmp    0x504c26
  504c8e:	3b 44 24 7c          	cmp    eax,DWORD PTR [esp+0x7c]
  504c92:	75 12                	jne    0x504ca6
  504c94:	b9 01 00 00 00       	mov    ecx,0x1
  504c99:	8d 44 24 74          	lea    eax,[esp+0x74]
  504c9d:	e8 9e 15 1d 00       	call   0x6d6240
  504ca2:	8b 44 24 78          	mov    eax,DWORD PTR [esp+0x78]
  504ca6:	85 c0                	test   eax,eax
  504ca8:	74 06                	je     0x504cb0
  504caa:	89 30                	mov    DWORD PTR [eax],esi
  504cac:	8b 44 24 78          	mov    eax,DWORD PTR [esp+0x78]
  504cb0:	83 c0 04             	add    eax,0x4
  504cb3:	89 44 24 78          	mov    DWORD PTR [esp+0x78],eax
  504cb7:	bf 00 dc c0 00       	mov    edi,0xc0dc00
  504cbc:	8b c3                	mov    eax,ebx
  504cbe:	e8 fd 96 22 00       	call   0x72e3c0
  504cc3:	8b d8                	mov    ebx,eax
  504cc5:	85 db                	test   ebx,ebx
  504cc7:	0f 85 23 ff ff ff    	jne    0x504bf0
```
### Quest Rewards/Contents and record insertion：VA `0x00504CCD..0x005054D9` raw `0x1040CD..0x1048D9`, span SHA256 `b33d2cc8cbe10a63c9ae526d358ad64717862fb07defc4cb270c9ba54dd62ca8`
```asm
00504ccd <.data+0x1040cd>:
  504ccd:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  504cd1:	8b 72 18             	mov    esi,DWORD PTR [edx+0x18]
  504cd4:	85 f6                	test   esi,esi
  504cd6:	0f 84 54 01 00 00    	je     0x504e30
  504cdc:	bf 10 00 00 00       	mov    edi,0x10
  504ce1:	39 7e 34             	cmp    DWORD PTR [esi+0x34],edi
  504ce4:	8d 46 20             	lea    eax,[esi+0x20]
  504ce7:	72 02                	jb     0x504ceb
  504ce9:	8b 00                	mov    eax,DWORD PTR [eax]
  504ceb:	68 08 dc c0 00       	push   0xc0dc08
  504cf0:	50                   	push   eax
  504cf1:	e8 bb ef 38 00       	call   0x893cb1
  504cf6:	83 c4 08             	add    esp,0x8
  504cf9:	85 c0                	test   eax,eax
  504cfb:	74 0c                	je     0x504d09
  504cfd:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  504d00:	85 f6                	test   esi,esi
  504d02:	75 dd                	jne    0x504ce1
  504d04:	e9 27 01 00 00       	jmp    0x504e30
  504d09:	85 f6                	test   esi,esi
  504d0b:	0f 84 1f 01 00 00    	je     0x504e30
  504d11:	bf 14 dc c0 00       	mov    edi,0xc0dc14
  504d16:	8b c6                	mov    eax,esi
  504d18:	e8 43 96 22 00       	call   0x72e360
  504d1d:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  504d21:	85 c0                	test   eax,eax
  504d23:	0f 84 07 01 00 00    	je     0x504e30
  504d29:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  504d30:	8b b0 94 00 00 00    	mov    esi,DWORD PTR [eax+0x94]
  504d36:	8d 78 44             	lea    edi,[eax+0x44]
  504d39:	bb 10 00 00 00       	mov    ebx,0x10
  504d3e:	3b f7                	cmp    esi,edi
  504d40:	74 23                	je     0x504d65
  504d42:	39 5e 28             	cmp    DWORD PTR [esi+0x28],ebx
  504d45:	8d 46 14             	lea    eax,[esi+0x14]
  504d48:	72 02                	jb     0x504d4c
  504d4a:	8b 00                	mov    eax,DWORD PTR [eax]
  504d4c:	68 08 b8 bf 00       	push   0xbfb808
  504d51:	50                   	push   eax
  504d52:	e8 5a ef 38 00       	call   0x893cb1
  504d57:	83 c4 08             	add    esp,0x8
  504d5a:	85 c0                	test   eax,eax
  504d5c:	74 47                	je     0x504da5
  504d5e:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  504d61:	3b f7                	cmp    esi,edi
  504d63:	75 dd                	jne    0x504d42
  504d65:	33 db                	xor    ebx,ebx
  504d67:	8b 77 50             	mov    esi,DWORD PTR [edi+0x50]
  504d6a:	3b f7                	cmp    esi,edi
  504d6c:	74 26                	je     0x504d94
  504d6e:	8b ff                	mov    edi,edi
  504d70:	83 7e 28 10          	cmp    DWORD PTR [esi+0x28],0x10
  504d74:	8d 46 14             	lea    eax,[esi+0x14]
  504d77:	72 02                	jb     0x504d7b
  504d79:	8b 00                	mov    eax,DWORD PTR [eax]
  504d7b:	68 1c dc c0 00       	push   0xc0dc1c
  504d80:	50                   	push   eax
  504d81:	e8 2b ef 38 00       	call   0x893cb1
  504d86:	83 c4 08             	add    esp,0x8
  504d89:	85 c0                	test   eax,eax
  504d8b:	74 37                	je     0x504dc4
  504d8d:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  504d90:	3b f7                	cmp    esi,edi
  504d92:	75 dc                	jne    0x504d70
  504d94:	33 c0                	xor    eax,eax
  504d96:	8d 4b ff             	lea    ecx,[ebx-0x1]
  504d99:	83 f9 05             	cmp    ecx,0x5
  504d9c:	77 78                	ja     0x504e16
  504d9e:	ff 24 8d 54 55 50 00 	jmp    DWORD PTR [ecx*4+0x505554]
  504da5:	85 f6                	test   esi,esi
  504da7:	74 bc                	je     0x504d65
  504da9:	39 5e 44             	cmp    DWORD PTR [esi+0x44],ebx
  504dac:	8d 46 30             	lea    eax,[esi+0x30]
  504daf:	72 02                	jb     0x504db3
  504db1:	8b 00                	mov    eax,DWORD PTR [eax]
  504db3:	85 c0                	test   eax,eax
  504db5:	74 ae                	je     0x504d65
  504db7:	50                   	push   eax
  504db8:	e8 f7 c9 38 00       	call   0x8917b4
  504dbd:	83 c4 04             	add    esp,0x4
  504dc0:	8b d8                	mov    ebx,eax
  504dc2:	eb a3                	jmp    0x504d67
  504dc4:	85 f6                	test   esi,esi
  504dc6:	74 cc                	je     0x504d94
  504dc8:	83 7e 44 10          	cmp    DWORD PTR [esi+0x44],0x10
  504dcc:	8d 46 30             	lea    eax,[esi+0x30]
  504dcf:	72 02                	jb     0x504dd3
  504dd1:	8b 00                	mov    eax,DWORD PTR [eax]
  504dd3:	85 c0                	test   eax,eax
  504dd5:	74 bd                	je     0x504d94
  504dd7:	50                   	push   eax
  504dd8:	e8 d7 c9 38 00       	call   0x8917b4
  504ddd:	83 c4 04             	add    esp,0x4
  504de0:	eb b4                	jmp    0x504d96
  504de2:	89 84 24 e4 00 00 00 	mov    DWORD PTR [esp+0xe4],eax
  504de9:	eb 2b                	jmp    0x504e16
  504deb:	89 84 24 e8 00 00 00 	mov    DWORD PTR [esp+0xe8],eax
  504df2:	eb 22                	jmp    0x504e16
  504df4:	89 84 24 ec 00 00 00 	mov    DWORD PTR [esp+0xec],eax
  504dfb:	eb 19                	jmp    0x504e16
  504dfd:	89 84 24 e0 00 00 00 	mov    DWORD PTR [esp+0xe0],eax
  504e04:	eb 10                	jmp    0x504e16
  504e06:	89 84 24 f0 00 00 00 	mov    DWORD PTR [esp+0xf0],eax
  504e0d:	eb 07                	jmp    0x504e16
  504e0f:	89 84 24 f4 00 00 00 	mov    DWORD PTR [esp+0xf4],eax
  504e16:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  504e1a:	bf 14 dc c0 00       	mov    edi,0xc0dc14
  504e1f:	e8 9c 95 22 00       	call   0x72e3c0
  504e24:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  504e28:	85 c0                	test   eax,eax
  504e2a:	0f 85 00 ff ff ff    	jne    0x504d30
  504e30:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  504e34:	8b 70 18             	mov    esi,DWORD PTR [eax+0x18]
  504e37:	85 f6                	test   esi,esi
  504e39:	74 28                	je     0x504e63
  504e3b:	bf 10 00 00 00       	mov    edi,0x10
  504e40:	39 7e 34             	cmp    DWORD PTR [esi+0x34],edi
  504e43:	8d 46 20             	lea    eax,[esi+0x20]
  504e46:	72 02                	jb     0x504e4a
  504e48:	8b 00                	mov    eax,DWORD PTR [eax]
  504e4a:	68 24 dc c0 00       	push   0xc0dc24
  504e4f:	50                   	push   eax
  504e50:	e8 5c ee 38 00       	call   0x893cb1
  504e55:	83 c4 08             	add    esp,0x8
  504e58:	85 c0                	test   eax,eax
  504e5a:	74 09                	je     0x504e65
  504e5c:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  504e5f:	85 f6                	test   esi,esi
  504e61:	75 dd                	jne    0x504e40
  504e63:	33 f6                	xor    esi,esi
  504e65:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  504e69:	85 f6                	test   esi,esi
  504e6b:	0f 84 b3 03 00 00    	je     0x505224
  504e71:	8b 74 24 20          	mov    esi,DWORD PTR [esp+0x20]
  504e75:	8b 16                	mov    edx,DWORD PTR [esi]
  504e77:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  504e7a:	8b ce                	mov    ecx,esi
  504e7c:	ff d0                	call   eax
  504e7e:	ff 84 24 dc 00 00 00 	inc    DWORD PTR [esp+0xdc]
  504e85:	33 db                	xor    ebx,ebx
  504e87:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  504e8b:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  504e8f:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  504e93:	bf 30 dc c0 00       	mov    edi,0xc0dc30
  504e98:	8b c6                	mov    eax,esi
  504e9a:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x3
  504ea1:	03 
  504ea2:	e8 b9 94 22 00       	call   0x72e360
  504ea7:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  504eab:	3b c3                	cmp    eax,ebx
  504ead:	0f 84 dc 01 00 00    	je     0x50508f
  504eb3:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  504eb7:	8b b7 94 00 00 00    	mov    esi,DWORD PTR [edi+0x94]
  504ebd:	83 c7 44             	add    edi,0x44
  504ec0:	3b f7                	cmp    esi,edi
  504ec2:	74 28                	je     0x504eec
  504ec4:	83 7e 28 10          	cmp    DWORD PTR [esi+0x28],0x10
  504ec8:	8d 46 14             	lea    eax,[esi+0x14]
  504ecb:	72 02                	jb     0x504ecf
  504ecd:	8b 00                	mov    eax,DWORD PTR [eax]
  504ecf:	68 fc 71 c0 00       	push   0xc071fc
  504ed4:	50                   	push   eax
  504ed5:	e8 d7 ed 38 00       	call   0x893cb1
  504eda:	83 c4 08             	add    esp,0x8
  504edd:	85 c0                	test   eax,eax
  504edf:	0f 84 b1 00 00 00    	je     0x504f96
  504ee5:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  504ee8:	3b f7                	cmp    esi,edi
  504eea:	75 d8                	jne    0x504ec4
  504eec:	c7 44 24 1c 00 00 00 	mov    DWORD PTR [esp+0x1c],0x0
  504ef3:	00 
  504ef4:	8b 77 50             	mov    esi,DWORD PTR [edi+0x50]
  504ef7:	3b f7                	cmp    esi,edi
  504ef9:	74 2d                	je     0x504f28
  504efb:	eb 03                	jmp    0x504f00
  504efd:	8d 49 00             	lea    ecx,[ecx+0x0]
  504f00:	83 7e 28 10          	cmp    DWORD PTR [esi+0x28],0x10
  504f04:	8d 46 14             	lea    eax,[esi+0x14]
  504f07:	72 02                	jb     0x504f0b
  504f09:	8b 00                	mov    eax,DWORD PTR [eax]
  504f0b:	68 1c dc c0 00       	push   0xc0dc1c
  504f10:	50                   	push   eax
  504f11:	e8 9b ed 38 00       	call   0x893cb1
  504f16:	83 c4 08             	add    esp,0x8
  504f19:	85 c0                	test   eax,eax
  504f1b:	0f 84 a2 00 00 00    	je     0x504fc3
  504f21:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  504f24:	3b f7                	cmp    esi,edi
  504f26:	75 d8                	jne    0x504f00
  504f28:	33 f6                	xor    esi,esi
  504f2a:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  504f2e:	8b 54 24 24          	mov    edx,DWORD PTR [esp+0x24]
  504f32:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  504f36:	89 7c 24 34          	mov    DWORD PTR [esp+0x34],edi
  504f3a:	89 74 24 38          	mov    DWORD PTR [esp+0x38],esi
  504f3e:	3b cb                	cmp    ecx,ebx
  504f40:	0f 83 d3 00 00 00    	jae    0x505019
  504f46:	8b c1                	mov    eax,ecx
  504f48:	3b d0                	cmp    edx,eax
  504f4a:	0f 87 c9 00 00 00    	ja     0x505019
  504f50:	8b f1                	mov    esi,ecx
  504f52:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  504f56:	2b f2                	sub    esi,edx
  504f58:	c1 fe 03             	sar    esi,0x3
  504f5b:	3b d9                	cmp    ebx,ecx
  504f5d:	0f 85 a4 00 00 00    	jne    0x505007
  504f63:	8b c3                	mov    eax,ebx
  504f65:	2b c2                	sub    eax,edx
  504f67:	c1 f8 03             	sar    eax,0x3
  504f6a:	3d fe ff ff 1f       	cmp    eax,0x1ffffffe
  504f6f:	0f 87 d2 05 00 00    	ja     0x505547
  504f75:	2b ca                	sub    ecx,edx
  504f77:	40                   	inc    eax
  504f78:	c1 f9 03             	sar    ecx,0x3
  504f7b:	3b c1                	cmp    eax,ecx
  504f7d:	0f 86 84 00 00 00    	jbe    0x505007
  504f83:	8b d1                	mov    edx,ecx
  504f85:	d1 ea                	shr    edx,1
  504f87:	bf ff ff ff 1f       	mov    edi,0x1fffffff
  504f8c:	2b fa                	sub    edi,edx
  504f8e:	3b f9                	cmp    edi,ecx
  504f90:	73 5c                	jae    0x504fee
  504f92:	33 c9                	xor    ecx,ecx
  504f94:	eb 5a                	jmp    0x504ff0
  504f96:	85 f6                	test   esi,esi
  504f98:	0f 84 4e ff ff ff    	je     0x504eec
  504f9e:	83 7e 44 10          	cmp    DWORD PTR [esi+0x44],0x10
  504fa2:	8d 46 30             	lea    eax,[esi+0x30]
  504fa5:	72 02                	jb     0x504fa9
  504fa7:	8b 00                	mov    eax,DWORD PTR [eax]
  504fa9:	85 c0                	test   eax,eax
  504fab:	0f 84 3b ff ff ff    	je     0x504eec
  504fb1:	50                   	push   eax
  504fb2:	e8 fd c7 38 00       	call   0x8917b4
  504fb7:	83 c4 04             	add    esp,0x4
  504fba:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  504fbe:	e9 31 ff ff ff       	jmp    0x504ef4
  504fc3:	85 f6                	test   esi,esi
  504fc5:	0f 84 5d ff ff ff    	je     0x504f28
  504fcb:	83 7e 44 10          	cmp    DWORD PTR [esi+0x44],0x10
  504fcf:	8d 46 30             	lea    eax,[esi+0x30]
  504fd2:	72 02                	jb     0x504fd6
  504fd4:	8b 00                	mov    eax,DWORD PTR [eax]
  504fd6:	85 c0                	test   eax,eax
  504fd8:	0f 84 4a ff ff ff    	je     0x504f28
  504fde:	50                   	push   eax
  504fdf:	e8 d0 c7 38 00       	call   0x8917b4
  504fe4:	83 c4 04             	add    esp,0x4
  504fe7:	8b f0                	mov    esi,eax
  504fe9:	e9 3c ff ff ff       	jmp    0x504f2a
  504fee:	03 ca                	add    ecx,edx
  504ff0:	3b c8                	cmp    ecx,eax
  504ff2:	0f 42 c8             	cmovb  ecx,eax
  504ff5:	51                   	push   ecx
  504ff6:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  504ffa:	e8 31 23 fe ff       	call   0x4e7330
  504fff:	8b 5c 24 28          	mov    ebx,DWORD PTR [esp+0x28]
  505003:	8b 54 24 24          	mov    edx,DWORD PTR [esp+0x24]
  505007:	85 db                	test   ebx,ebx
  505009:	74 63                	je     0x50506e
  50500b:	8b 0c f2             	mov    ecx,DWORD PTR [edx+esi*8]
  50500e:	89 0b                	mov    DWORD PTR [ebx],ecx
  505010:	8b 54 f2 04          	mov    edx,DWORD PTR [edx+esi*8+0x4]
  505014:	89 53 04             	mov    DWORD PTR [ebx+0x4],edx
  505017:	eb 55                	jmp    0x50506e
  505019:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  50501d:	3b d9                	cmp    ebx,ecx
  50501f:	75 44                	jne    0x505065
  505021:	8b c3                	mov    eax,ebx
  505023:	2b c2                	sub    eax,edx
  505025:	c1 f8 03             	sar    eax,0x3
  505028:	3d fe ff ff 1f       	cmp    eax,0x1ffffffe
  50502d:	0f 87 14 05 00 00    	ja     0x505547
  505033:	2b ca                	sub    ecx,edx
  505035:	40                   	inc    eax
  505036:	c1 f9 03             	sar    ecx,0x3
  505039:	3b c1                	cmp    eax,ecx
  50503b:	76 28                	jbe    0x505065
  50503d:	8b d1                	mov    edx,ecx
  50503f:	d1 ea                	shr    edx,1
  505041:	bb ff ff ff 1f       	mov    ebx,0x1fffffff
  505046:	2b da                	sub    ebx,edx
  505048:	3b d9                	cmp    ebx,ecx
  50504a:	73 04                	jae    0x505050
  50504c:	33 c9                	xor    ecx,ecx
  50504e:	eb 02                	jmp    0x505052
  505050:	03 ca                	add    ecx,edx
  505052:	3b c8                	cmp    ecx,eax
  505054:	0f 42 c8             	cmovb  ecx,eax
  505057:	51                   	push   ecx
  505058:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  50505c:	e8 cf 22 fe ff       	call   0x4e7330
  505061:	8b 5c 24 28          	mov    ebx,DWORD PTR [esp+0x28]
  505065:	85 db                	test   ebx,ebx
  505067:	74 05                	je     0x50506e
  505069:	89 3b                	mov    DWORD PTR [ebx],edi
  50506b:	89 73 04             	mov    DWORD PTR [ebx+0x4],esi
  50506e:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  505072:	83 c3 08             	add    ebx,0x8
  505075:	bf 30 dc c0 00       	mov    edi,0xc0dc30
  50507a:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  50507e:	e8 3d 93 22 00       	call   0x72e3c0
  505083:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  505087:	85 c0                	test   eax,eax
  505089:	0f 85 24 fe ff ff    	jne    0x504eb3
  50508f:	8b 84 24 fc 00 00 00 	mov    eax,DWORD PTR [esp+0xfc]
  505096:	8b 94 24 f8 00 00 00 	mov    edx,DWORD PTR [esp+0xf8]
  50509d:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  5050a1:	3b c8                	cmp    ecx,eax
  5050a3:	0f 83 8b 00 00 00    	jae    0x505134
  5050a9:	3b d1                	cmp    edx,ecx
  5050ab:	0f 87 83 00 00 00    	ja     0x505134
  5050b1:	8b bc 24 00 01 00 00 	mov    edi,DWORD PTR [esp+0x100]
  5050b8:	8b f1                	mov    esi,ecx
  5050ba:	2b f2                	sub    esi,edx
  5050bc:	3b c7                	cmp    eax,edi
  5050be:	75 54                	jne    0x505114
  5050c0:	8b c8                	mov    ecx,eax
  5050c2:	2b ca                	sub    ecx,edx
  5050c4:	c1 f9 04             	sar    ecx,0x4
  5050c7:	81 f9 fe ff ff 0f    	cmp    ecx,0xffffffe
  5050cd:	0f 87 74 04 00 00    	ja     0x505547
  5050d3:	2b fa                	sub    edi,edx
  5050d5:	41                   	inc    ecx
  5050d6:	c1 ff 04             	sar    edi,0x4
  5050d9:	3b cf                	cmp    ecx,edi
  5050db:	76 37                	jbe    0x505114
  5050dd:	8b c7                	mov    eax,edi
  5050df:	8b d0                	mov    edx,eax
  5050e1:	d1 ea                	shr    edx,1
  5050e3:	bf ff ff ff 0f       	mov    edi,0xfffffff
  5050e8:	2b fa                	sub    edi,edx
  5050ea:	3b f8                	cmp    edi,eax
  5050ec:	73 04                	jae    0x5050f2
  5050ee:	33 c0                	xor    eax,eax
  5050f0:	eb 02                	jmp    0x5050f4
  5050f2:	03 c2                	add    eax,edx
  5050f4:	3b c1                	cmp    eax,ecx
  5050f6:	0f 42 c1             	cmovb  eax,ecx
  5050f9:	50                   	push   eax
  5050fa:	8d 8c 24 fc 00 00 00 	lea    ecx,[esp+0xfc]
  505101:	e8 2a 0d 15 00       	call   0x655e30
  505106:	8b 84 24 fc 00 00 00 	mov    eax,DWORD PTR [esp+0xfc]
  50510d:	8b 94 24 f8 00 00 00 	mov    edx,DWORD PTR [esp+0xf8]
  505114:	83 e6 f0             	and    esi,0xfffffff0
  505117:	03 f2                	add    esi,edx
  505119:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  50511d:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  505121:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x4
  505128:	04 
  505129:	85 c0                	test   eax,eax
  50512b:	0f 84 81 00 00 00    	je     0x5051b2
  505131:	56                   	push   esi
  505132:	eb 71                	jmp    0x5051a5
  505134:	8b b4 24 00 01 00 00 	mov    esi,DWORD PTR [esp+0x100]
  50513b:	3b c6                	cmp    eax,esi
  50513d:	75 4d                	jne    0x50518c
  50513f:	8b c8                	mov    ecx,eax
  505141:	2b ca                	sub    ecx,edx
  505143:	c1 f9 04             	sar    ecx,0x4
  505146:	81 f9 fe ff ff 0f    	cmp    ecx,0xffffffe
  50514c:	0f 87 f5 03 00 00    	ja     0x505547
  505152:	2b f2                	sub    esi,edx
  505154:	8b d6                	mov    edx,esi
  505156:	41                   	inc    ecx
  505157:	c1 fa 04             	sar    edx,0x4
  50515a:	3b ca                	cmp    ecx,edx
  50515c:	76 2e                	jbe    0x50518c
  50515e:	8b c2                	mov    eax,edx
  505160:	d1 ea                	shr    edx,1
  505162:	be ff ff ff 0f       	mov    esi,0xfffffff
  505167:	2b f2                	sub    esi,edx
  505169:	3b f0                	cmp    esi,eax
  50516b:	73 04                	jae    0x505171
  50516d:	33 c0                	xor    eax,eax
  50516f:	eb 02                	jmp    0x505173
  505171:	03 c2                	add    eax,edx
  505173:	3b c1                	cmp    eax,ecx
  505175:	0f 42 c1             	cmovb  eax,ecx
  505178:	50                   	push   eax
  505179:	8d 8c 24 fc 00 00 00 	lea    ecx,[esp+0xfc]
  505180:	e8 ab 0c 15 00       	call   0x655e30
  505185:	8b 84 24 fc 00 00 00 	mov    eax,DWORD PTR [esp+0xfc]
  50518c:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  505190:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  505194:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x5
  50519b:	05 
  50519c:	85 c0                	test   eax,eax
  50519e:	74 12                	je     0x5051b2
  5051a0:	8d 54 24 24          	lea    edx,[esp+0x24]
  5051a4:	52                   	push   edx
  5051a5:	50                   	push   eax
  5051a6:	e8 55 7b ff ff       	call   0x4fcd00
  5051ab:	8b 84 24 fc 00 00 00 	mov    eax,DWORD PTR [esp+0xfc]
  5051b2:	83 c0 10             	add    eax,0x10
  5051b5:	89 84 24 fc 00 00 00 	mov    DWORD PTR [esp+0xfc],eax
  5051bc:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x1
  5051c3:	01 
  5051c4:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  5051c8:	33 db                	xor    ebx,ebx
  5051ca:	3b c3                	cmp    eax,ebx
  5051cc:	74 09                	je     0x5051d7
  5051ce:	50                   	push   eax
  5051cf:	e8 38 c0 38 00       	call   0x89120c
  5051d4:	83 c4 04             	add    esp,0x4
  5051d7:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  5051db:	8b 70 40             	mov    esi,DWORD PTR [eax+0x40]
  5051de:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  5051e2:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  5051e6:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  5051ea:	3b f3                	cmp    esi,ebx
  5051ec:	74 28                	je     0x505216
  5051ee:	bf 10 00 00 00       	mov    edi,0x10
  5051f3:	39 7e 34             	cmp    DWORD PTR [esi+0x34],edi
  5051f6:	8d 46 20             	lea    eax,[esi+0x20]
  5051f9:	72 02                	jb     0x5051fd
  5051fb:	8b 00                	mov    eax,DWORD PTR [eax]
  5051fd:	68 24 dc c0 00       	push   0xc0dc24
  505202:	50                   	push   eax
  505203:	e8 a9 ea 38 00       	call   0x893cb1
  505208:	83 c4 08             	add    esp,0x8
  50520b:	85 c0                	test   eax,eax
  50520d:	74 09                	je     0x505218
  50520f:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  505212:	3b f3                	cmp    esi,ebx
  505214:	75 dd                	jne    0x5051f3
  505216:	33 f6                	xor    esi,esi
  505218:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  50521c:	3b f3                	cmp    esi,ebx
  50521e:	0f 85 4d fc ff ff    	jne    0x504e71
  505224:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  505228:	8b 71 18             	mov    esi,DWORD PTR [ecx+0x18]
  50522b:	85 f6                	test   esi,esi
  50522d:	0f 84 c8 01 00 00    	je     0x5053fb
  505233:	bf 10 00 00 00       	mov    edi,0x10
  505238:	39 7e 34             	cmp    DWORD PTR [esi+0x34],edi
  50523b:	8d 46 20             	lea    eax,[esi+0x20]
  50523e:	72 02                	jb     0x505242
  505240:	8b 00                	mov    eax,DWORD PTR [eax]
  505242:	68 38 dc c0 00       	push   0xc0dc38
  505247:	50                   	push   eax
  505248:	e8 64 ea 38 00       	call   0x893cb1
  50524d:	83 c4 08             	add    esp,0x8
  505250:	85 c0                	test   eax,eax
  505252:	74 0c                	je     0x505260
  505254:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  505257:	85 f6                	test   esi,esi
  505259:	75 dd                	jne    0x505238
  50525b:	e9 9b 01 00 00       	jmp    0x5053fb
  505260:	85 f6                	test   esi,esi
  505262:	0f 84 93 01 00 00    	je     0x5053fb
  505268:	8b 76 18             	mov    esi,DWORD PTR [esi+0x18]
  50526b:	85 f6                	test   esi,esi
  50526d:	74 19                	je     0x505288
  50526f:	90                   	nop
  505270:	8b 16                	mov    edx,DWORD PTR [esi]
  505272:	8b 42 18             	mov    eax,DWORD PTR [edx+0x18]
  505275:	8b ce                	mov    ecx,esi
  505277:	ff d0                	call   eax
  505279:	85 c0                	test   eax,eax
  50527b:	0f 85 7d 02 00 00    	jne    0x5054fe
  505281:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  505284:	85 f6                	test   esi,esi
  505286:	75 e8                	jne    0x505270
  505288:	33 c0                	xor    eax,eax
  50528a:	8b d8                	mov    ebx,eax
  50528c:	85 c0                	test   eax,eax
  50528e:	0f 84 67 01 00 00    	je     0x5053fb
  505294:	8b b3 94 00 00 00    	mov    esi,DWORD PTR [ebx+0x94]
  50529a:	8d 7b 44             	lea    edi,[ebx+0x44]
  50529d:	3b f7                	cmp    esi,edi
  50529f:	74 28                	je     0x5052c9
  5052a1:	83 7e 28 10          	cmp    DWORD PTR [esi+0x28],0x10
  5052a5:	8d 46 14             	lea    eax,[esi+0x14]
  5052a8:	72 02                	jb     0x5052ac
  5052aa:	8b 00                	mov    eax,DWORD PTR [eax]
  5052ac:	68 d0 d1 be 00       	push   0xbed1d0
  5052b1:	50                   	push   eax
  5052b2:	e8 fa e9 38 00       	call   0x893cb1
  5052b7:	83 c4 08             	add    esp,0x8
  5052ba:	85 c0                	test   eax,eax
  5052bc:	0f 84 4a 02 00 00    	je     0x50550c
  5052c2:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  5052c5:	3b f7                	cmp    esi,edi
  5052c7:	75 d8                	jne    0x5052a1
  5052c9:	33 c0                	xor    eax,eax
  5052cb:	8d 78 10             	lea    edi,[eax+0x10]
  5052ce:	8b 4b 18             	mov    ecx,DWORD PTR [ebx+0x18]
  5052d1:	05 e8 03 00 00       	add    eax,0x3e8
  5052d6:	33 f6                	xor    esi,esi
  5052d8:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  5052dc:	3b ce                	cmp    ecx,esi
  5052de:	0f 84 ec 00 00 00    	je     0x5053d0
  5052e4:	8b 11                	mov    edx,DWORD PTR [ecx]
  5052e6:	8b 42 30             	mov    eax,DWORD PTR [edx+0x30]
  5052e9:	ff d0                	call   eax
  5052eb:	3b c6                	cmp    eax,esi
  5052ed:	0f 84 dd 00 00 00    	je     0x5053d0
  5052f3:	39 78 34             	cmp    DWORD PTR [eax+0x34],edi
  5052f6:	8d 48 20             	lea    ecx,[eax+0x20]
  5052f9:	72 02                	jb     0x5052fd
  5052fb:	8b 09                	mov    ecx,DWORD PTR [ecx]
  5052fd:	3b ce                	cmp    ecx,esi
  5052ff:	0f 84 cb 00 00 00    	je     0x5053d0
  505305:	33 d2                	xor    edx,edx
  505307:	c7 84 24 24 01 00 00 	mov    DWORD PTR [esp+0x124],0x7
  50530e:	07 00 00 00 
  505312:	89 b4 24 20 01 00 00 	mov    DWORD PTR [esp+0x120],esi
  505319:	66 89 94 24 10 01 00 	mov    WORD PTR [esp+0x110],dx
  505320:	00 
  505321:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x6
  505328:	06 
  505329:	8b c1                	mov    eax,ecx
  50532b:	89 74 24 58          	mov    DWORD PTR [esp+0x58],esi
  50532f:	c7 44 24 5c 0f 00 00 	mov    DWORD PTR [esp+0x5c],0xf
  505336:	00 
  505337:	88 54 24 48          	mov    BYTE PTR [esp+0x48],dl
  50533b:	8d 70 01             	lea    esi,[eax+0x1]
  50533e:	8b ff                	mov    edi,edi
  505340:	8a 10                	mov    dl,BYTE PTR [eax]
  505342:	40                   	inc    eax
  505343:	84 d2                	test   dl,dl
  505345:	75 f9                	jne    0x505340
  505347:	2b c6                	sub    eax,esi
  505349:	50                   	push   eax
  50534a:	51                   	push   ecx
  50534b:	8d 4c 24 50          	lea    ecx,[esp+0x50]
  50534f:	e8 1c d7 ef ff       	call   0x402a70
  505354:	8d 44 24 48          	lea    eax,[esp+0x48]
  505358:	50                   	push   eax
  505359:	8d 84 24 14 01 00 00 	lea    eax,[esp+0x114]
  505360:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x7
  505367:	07 
  505368:	e8 c3 ad f3 ff       	call   0x440130
  50536d:	83 c4 04             	add    esp,0x4
  505370:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x6
  505377:	06 
  505378:	39 7c 24 5c          	cmp    DWORD PTR [esp+0x5c],edi
  50537c:	72 0d                	jb     0x50538b
  50537e:	8b 4c 24 48          	mov    ecx,DWORD PTR [esp+0x48]
  505382:	51                   	push   ecx
  505383:	e8 84 be 38 00       	call   0x89120c
  505388:	83 c4 04             	add    esp,0x4
  50538b:	8d 54 24 1c          	lea    edx,[esp+0x1c]
  50538f:	8d 8c 24 cc 00 00 00 	lea    ecx,[esp+0xcc]
  505396:	e8 d5 04 00 00       	call   0x505870
  50539b:	6a ff                	push   0xffffffff
  50539d:	6a 00                	push   0x0
  50539f:	8d 94 24 18 01 00 00 	lea    edx,[esp+0x118]
  5053a6:	52                   	push   edx
  5053a7:	8b c8                	mov    ecx,eax
  5053a9:	e8 32 d3 ef ff       	call   0x4026e0
  5053ae:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x1
  5053b5:	01 
  5053b6:	83 bc 24 24 01 00 00 	cmp    DWORD PTR [esp+0x124],0x8
  5053bd:	08 
  5053be:	72 10                	jb     0x5053d0
  5053c0:	8b 84 24 10 01 00 00 	mov    eax,DWORD PTR [esp+0x110]
  5053c7:	50                   	push   eax
  5053c8:	e8 3f be 38 00       	call   0x89120c
  5053cd:	83 c4 04             	add    esp,0x4
  5053d0:	8b 73 40             	mov    esi,DWORD PTR [ebx+0x40]
  5053d3:	85 f6                	test   esi,esi
  5053d5:	74 18                	je     0x5053ef
  5053d7:	8b 16                	mov    edx,DWORD PTR [esi]
  5053d9:	8b 42 18             	mov    eax,DWORD PTR [edx+0x18]
  5053dc:	8b ce                	mov    ecx,esi
  5053de:	ff d0                	call   eax
  5053e0:	85 c0                	test   eax,eax
  5053e2:	0f 85 51 01 00 00    	jne    0x505539
  5053e8:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  5053eb:	85 f6                	test   esi,esi
  5053ed:	75 e8                	jne    0x5053d7
  5053ef:	33 c0                	xor    eax,eax
  5053f1:	8b d8                	mov    ebx,eax
  5053f3:	85 c0                	test   eax,eax
  5053f5:	0f 85 99 fe ff ff    	jne    0x505294
  5053fb:	8b 4c 24 64          	mov    ecx,DWORD PTR [esp+0x64]
  5053ff:	8d 94 24 a8 01 00 00 	lea    edx,[esp+0x1a8]
  505406:	89 8c 24 a4 01 00 00 	mov    DWORD PTR [esp+0x1a4],ecx
  50540d:	52                   	push   edx
  50540e:	8d 4c 24 68          	lea    ecx,[esp+0x68]
  505412:	e8 b9 10 00 00       	call   0x5064d0
  505417:	8b 74 24 3c          	mov    esi,DWORD PTR [esp+0x3c]
  50541b:	8d 84 24 a4 01 00 00 	lea    eax,[esp+0x1a4]
  505422:	50                   	push   eax
  505423:	8b ce                	mov    ecx,esi
  505425:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x8
  50542c:	08 
  50542d:	e8 de 0e 00 00       	call   0x506310
  505432:	50                   	push   eax
  505433:	56                   	push   esi
  505434:	8d 74 24 48          	lea    esi,[esp+0x48]
  505438:	e8 33 0b 00 00       	call   0x505f70
  50543d:	8d 8c 24 a8 01 00 00 	lea    ecx,[esp+0x1a8]
  505444:	51                   	push   ecx
  505445:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x1
  50544c:	01 
  50544d:	e8 6e f1 ff ff       	call   0x5045c0
  505452:	8d 54 24 64          	lea    edx,[esp+0x64]
  505456:	52                   	push   edx
  505457:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x0
  50545e:	00 
  50545f:	e8 5c f1 ff ff       	call   0x5045c0
  505464:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  505468:	8b 40 40             	mov    eax,DWORD PTR [eax+0x40]
  50546b:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  50546f:	85 c0                	test   eax,eax
  505471:	0f 85 49 f4 ff ff    	jne    0x5048c0
  505477:	33 ff                	xor    edi,edi
  505479:	bb 10 00 00 00       	mov    ebx,0x10
  50547e:	c7 84 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],0xffffffff
  505485:	ff ff ff ff 
  505489:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  505490:	94 23 bf 00 
  505494:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  50549b:	72 10                	jb     0x5054ad
  50549d:	8b 8c 24 78 01 00 00 	mov    ecx,DWORD PTR [esp+0x178]
  5054a4:	51                   	push   ecx
  5054a5:	e8 62 bd 38 00       	call   0x89120c
  5054aa:	83 c4 04             	add    esp,0x4
  5054ad:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  5054b4:	c7 84 24 8c 01 00 00 	mov    DWORD PTR [esp+0x18c],0xf
  5054bb:	0f 00 00 00 
  5054bf:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  5054c6:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  5054cd:	00 
  5054ce:	e8 6d 8b 22 00       	call   0x72e040
  5054d3:	b8 01 00 00 00       	mov    eax,0x1
  5054d8:	8b       	mov    ecx,DWORD PTR [esp+0x258]
```

## I. 最終與前稿差異

- T16-108 只列三筆 14/16/15 QuestInfo 與基本 loader/QuestTalk 負例。本篇新增**全文 4,798 Quest ID 唯一性、NPC10027八筆群、type3七筆完整集合、field18唯一、Demand14唯一**，並在原始 BIN 對 optional `AcceptAction`/`CompleteAction`/`Demands` 的實際 loader 分支做全文有界反組譯，補足①的完整資源關聯驗收。
- 不更改 T16-111 對 Scenario14 和 QuestInfo ID14 命名空間分離的結論；沒有把 STP 的 local effect 冒充 Server 資料。
- 沒有修改 GitHub main、T16 branch 的研究原稿或 S00 台帳（同步歷史另見前輪已完成的 main→T16 PR）。

