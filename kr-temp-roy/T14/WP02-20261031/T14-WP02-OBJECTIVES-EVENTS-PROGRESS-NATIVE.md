# T14-WP02 — 關卡目標、事件、進度狀態與雙向訊息邊界（KR BIN-first）

> 2026-10-31，T14 工作包 WP02-01～04。成果性質：**有界 Client 靜態研究交付**，不是原版 Server 目標達成規則或全部關卡目標類型完成驗證。WP03～WP08 不因此自動結案。

## 0. 來源、操作範圍與研究終點

- Repository：`we88ec3-prog/ttr_anal_multi`；工作分支 `t14/roy/chatgpt-web`。本次讀取 WP01 Git blob `6e65af816d1a5061484e7f21e79cdccce3595f3a`，原始工作基線 commit `0f37e0870217fd7caf2899e7a0b9df962377d009`；與當時 `main=ad1fda170734767c67dd0f62066a34ece34e118a` 有 11 筆未同步主線更新（T10／T01），未自行合併。
- **KR `Tartaros.bin`**：實際唯讀重算 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；12,472,320 bytes。`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。只以 BIN 做下列組語的原生校驗，二者不可混合 VA。
- `Event.stp` 實際 SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；`Table.stp` SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。本輪只做 carrier/string 定向核查，不宣稱解包後資源屬 pristine 廠商版本。
- GitHub 來源：`kr/tasks/T14/{README.md,task.json}`、`shared/integrations/T01-20261027-03/{accepted-claims,resolutions}.json`、`T01-20261027-04`、`T01-20261028-06`、`kr/evidence/1d78642b...txt`（T14 原始 scenario14 摘要）、`kr/evidence/0ef1b842...txt`（任務狀態）、`kr/evidence/bff92f47...txt`（任務事件→對話）、`kr/evidence/00c7ff83...txt`（一般結果場景）；指定函式偽碼導航在 `kr-bulk-roy/9741d.../functions/0x<va>.c`。
- 工作限定：唯讀 BIN/EXE/資源與來源；未啟動遊戲、未發包、未 patch、未執行封裝的歷史 Python/Lua、未更改 Server／其他 Task／RR。使用 GNU objdump `-d -M intel` 對原件反組譯，`verify_wp02_native.py` 重讀 PE header/section、SHA 與 21 個 bytes 錨點，`native-window-audit.json` 保存測試向量。
- 研究目標：找出**可證的**場景目標／子目標資料、怪物／互動類事件、事件→writer→consumer→UI、C2S/S2C 關聯與 unknown；現有原件可完成的有界鏈節需有證據。**未有界閉合的擊殺／波次→勝利計數器和獎勵判定不得標完成**。

## 1. WP02-01：實際資料來源與 ID 域

| 類型 | 第一手或既有有界入口 | 原生可證範圍 | 不可等同 |
| --- | --- | --- | --- |
| 教學 Scenario | `0x4AA4D0` 建 C2S `0040 + WORD scenario`；`0x4C4AC0` 設 Tutorial 處理器 `0x4C4F20`；`0x4AA510` 讀完成 map | 為「單個 Scenario ID 完成旗標」機制；在歷史 `TutorialMain` 快照，`RequestStartScenario(14)`、`IsScenarioEnded(14)` 有獨立條件 | 全關卡目標清單、怪物數、Quest ID、持久化完成 |
| 教學 checkpoint | `0x4A8C20`，字串 `Table/TutCheckPointList.xml`／`TutCheckPointList`／`CheckPoint`；`0x543700` 建物件；`0x544730` 做距離／latch gate；`0x544070` 在不同 category 下處理本地事件 | checkpoint 有 `category`、座標、`range`、`active`、`effect` 等讀取分支；其部分 category 可產生 UI 事件或 controller 本地寫入 | Quest 任務目標、擊殺統計、Server 發送勝利 |
| 一般 Scenario 結果 | `0x4B7DC0` SceneManager slot `0022` → `0x4B9770` type0 → `0x4C4550`，結果頁面 UI state8 | **結果收到後**的場景／UI 資料路徑；不同於教學 TUTO 004C | 戰鬥中每一子目標的計數器或 Server 判勝來源 |
| Quest 定義與進度 | BIN 內 `Table/QuestInfo.xml`、`Table/QuestTalk.xml`；`0x5020B0` QuestMgr 註冊；`0x4FDA30` 分派；`0x500240` 重算候選清單 | Quest 有獨立 ID（原版部分通知採 WORD ID）；記錄保存在 manager `+0x5EAC`，可接清單 `+0x5EC0`、進度相關清單／slot 各有用途 | 教學 scenario14 flag、Stage/Case/Map index、關卡結果 0022 |
| 戰鬥／Actor | T08 已存 `S2C0007` 26-byte 描述中的怪物建立局部鏈，T12 為傷害／死亡主責 | 怪物出現、消失、傷害和任務達標屬不同事件／決策層 | 「最後一怪消失」必等同關卡完成 |

**本次原件字符串確證（raw→VA，原版 BIN `.rdata`，直接 ASCII 查得，存在不代表 gameplay consumer 已閉合）**：

- `Table/TutCheckPointList.xml`：`raw 0x804EE0 → VA 0xC068E0`
- `Table/QuestInfo.xml`：`0x80C148 → 0xC0DB48`
- `Table/QuestTalk.xml`：`0x80C15C → 0xC0DB5C`
- `Event/TutorialMain.lua`：`0x804E7C → 0xC0687C`
- `IsScenarioEnded`：`0x968580 → 0xD6AD80`
- `RequestStartScenario`：`0x968568 → 0xD6AD68`
- `kQuestTypeMonsterHunt`：`0x812540 → 0xC13F40`
- `kQuestTypeDestroy`：`0x812508 → 0xC13F08`
- `kMissionSuccess`：`0x812664 → 0xC14064`；`kMissionFailed`：`0x812654 → 0xC14054`

這些 label 表示存在相關 UI/語系字串，**沒有證明擊殺、破壞、保護、計時等都具備原生目標計數器／任務事件分支**。Event.stp 的 carrier XOR-FF 視圖可找到 `TutorialMain` 及函式名，但不能把簡易文字檢出當作有效的完整 STP 解包、官方發行版鑑定或 Lua runtime trace。`Quest15/STAGE19/Case103/Map191/192` 必須保留各自的數值命名空間，不把 chart 座標當合法 spawn。

## 2. WP02-02：原生目標／互動事件的有界分支

### A. CheckPoint 類型 4 實際本地 writer（本輪新的直接 BIN 核對）

反編譯 `0x544070` 顯示按 checkpoint `+0xF4` 類型分支。原生對應指令：

```asm
0054409E  0F B7 86 F4 00 00 00  movzx eax,word ptr [esi+0xF4]
005443C0  BB 04 00 00 00        mov ebx,4
005443C5  66 3B C3              cmp ax,bx
005443C8  75 37                 jne 0x544401
005443CA  39 1D AC A7 FB 00     cmp dword ptr [0xFBA7AC],ebx
005443D0  0F 85 3D 03 00 00     jne 0x544713
005443D6  0F BF 86 F6 00 00 00  movsx eax,word ptr [esi+0xF6]
005443DD  8B 0D A4 A7 FB 00     mov ecx,[0xFBA7A4]
005443E3  C7 84 81 B4 00 00 00 01 00 00 00
                                  mov dword ptr [ecx+eax*4+0xB4],1
```

**限定結論**：checkpoint category=4 且 controller kind 值為 4 時，以其 `WORD +0xF6` 當索引，把 controller `+0xB4+index*4` 寫 1。這是**本地互動/檢查點旗標**的可驗證 writer；未證此索引與關卡擊殺數、Quest ID、Server 授權或通關旗標對應。該索引上下限在這個局部片段未見；完整 caller gate 與安全索引上界仍需續查。`0x544070` 其他 category（3、5、2、其他）具有不同分支和 UI/控制器依賴，不能統稱成「通用目標完成」。

### B. checkpoint 進入／離開與 latch

`0x544730` 直接從原件核到：
- `+0x105` active/enabled byte 為 0：立即回 0 並清輸出。
- 計算 player/input 的 `(x−checkpoint.x)^2+(y−checkpoint.y)^2`，與 `(+0xFC range)^2` 比較。
- `+0x100` 模式旗標與輸入參數決定是否接受；`+0x104` latch 狀態可抑制重複觸發，距離不合／退場時清 latch。
- 這裡不直接接收一個 stage/monster kill count、也未直接找到 C2S socket builder；**不構成「全 Client 不會發互動封包」的否定證明**。

`0x543700` 對 category 0、2、4 等各自創建/配置不同效果或控制物件，不能把 category4 的 controller 写入套到所有 checkpoint。`0x4A8C20` 以 TinyXML 風格讀入的配置是**本地導引/觸發資源**，不是已證原版 Server 任務目標定義表。T16 先前限定資源報告亦提醒 category4 range 在某構建分支會折半，應依**實際物件值**和進入 predicate 查驗，不只看 XML 數字。

### C. 其他目標型態的明確「未證範圍」

| 待查事件 | 本輪已核資料／候選入口 | 本輪所得 | 研究限制 |
| --- | --- | --- | --- |
| 怪物擊殺／消失 | T08 `0007` 生成、T12 個體傷害／死亡；T14 `0x4C4F20` flag writer | **未找到經驗證的 kill→目標計數→Scenario completion 直接鏈** | 不能把 HP0、S2C 刪除、scene actor count 或 cluster COUNT 當成勝利訊號；須另查 T08/T12 producer 與 T14 goal consumer |
| checkpoint／互動 | `0x4A8C20`、`0x543700`、`0x544730`、`0x544070` | **已確認** category4 local writer 及距離／latch gate | 寫 controller+0xB4 不等於寫 scenario map |
| Quest 状態更新 | QuestMgr `0x502B40`、`0x5030C0` 之 result=0 分支 | **已確認**在一定條件下更新進度類容器／可接清單 | 不能直接名為關卡擊殺目標 |
| 保護、波次、計時、採集、破壞 | 本輪 BIN 字串、既有 T08 事件/Actor 研究 | **沒有閉合其目標 writer／goal consumer** | 字串存在、怪物生成/消失已知，不代表全功能已實證 |

**反證範圍**：在完整原始 BIN `.text` 中只以 little-endian immediate `0x00FC0F88` 掃描 4-byte 序列，命中 3 個候選地址 `0x47B0A3 / 0x47B0BB / 0x4C4F7D`。`0x47B0A3`、`0x47B0BB` 的原生片段處理容器生命週期，`0x4C4F7D` 是本次 004C writer 的立即數。**這只是直接 4-byte literal xref 的覆蓋範圍**；不能排除透過偏移、別名、指標參數、virtual dispatch、複製或間接寫入的其他 producer，也不能用命中量證明沒有 kill counter。

## 3. WP02-03：writer → 本地 reader → 顯示／腳本效果

### Scenario14：真正閉合的局部「狀態－腳本」鏈

```text
歷史 TutorialMain 腳本：RequestStartScenario(14)
    ↓ 0x4AB8A0 註冊的 native adapter
0x4AA4D0：C2S 本體 WORD 0040 + WORD scenario（4 bytes；transport gate）
    ⋮   Server 的實際達成條件／回覆時機目前未知，虛線並非已證因果
    ↓ Scene::CTutorial 004C slot callback（0x4C4AC0）
0x4C4F20：message+2 unsigned WORD → 0x4C2880(0xFC0F88 map) → DWORD=1
    ↓ 同 TUTO 物件、FE1804 正確綁定、未被 init 清 map
0x4AA510：讀 this+4 map → 0x4ACA40／0x4ACF90 Lua number adapter
    ↓ 歷史 Lua snapshot（非官方 pristine 認證）
IsScenarioEnded(14) != FALSE(0) 時，原等待 thread 可在後續 tick/resume 繼續
    ↓ 歷史快照中的 UI/checkpoint10016/yield/後續過場（未做 runtime 驗收）
```

原生 bytes：
- `0x4C4F75` raw `0xC4375` = `0fb74802`（`movzx ecx, word ptr [eax+2]`）
- `0x4C4F84` raw `0xC4384` = `e8f7d8ffff`（call map accessor `0x4C2880`）
- `0x4C4F89` raw `0xC4389` = `c70001000000`（write DWORD 1）
- `0x4AA513` raw `0xA9913` = `8d4104`；`0x4AA519` = `e862830100`（讀 this+4 map）
- `0x4AA4DF` raw `0xA98DF` = `b840000000`；`0x4AA4F9` = `6a04`；`0x4AA501` = `ffd2`（本體長度 4、虛擬送出呼叫）

既有有界 T14 主張另指出：`0x4C2880` 缺項讀取可能插入 0、TUTO 初始化 `0x4A8A60` 會清 map 並重建 Lua entry、`0x4AA4D0` **不直接 reset**這個 map；後續 Lua thread/owner 不保留時，重發 004C 也不能必然完成整個教學。**本次沒有證明固定 ID14 以外的 Scenario 名稱、完整各步動畫或其他 UI 都可正常顯示**。

### Quest 進度：另一條 state + UI/對話通知鏈

依 `kr/evidence/0ef1b842...txt`、`bff92f47...txt` 與本輪原生 `0x502B40 / 0x5030C0` 結果分支：

```text
CClient 既有任務訊息表 0x493170 → 0x494440
     → CQuestMgr virtual +4 / 0x4FDA30
       → 0045 / 0x5027D0：任務提示／QUEST_READY 類通知（不能代替進度寫入）
       → 0046 / 0x502B40：WORD +2 questID，WORD +4 result；
          result=0 更新活動槽、+5EB0 條件集合、重算 +5EC0；發 F438C
       → 0064 / 0x5030C0：WORD +2 questID，DWORD +4 result；
          result=0 更新活動槽並重算 +5EC0，建立 UI notification
F438C → Lobby/Square 事件 0x5B6E60 → 記錄查找 →
mode3 後續對話 → 條件找到下一任務 → mode1 確認可送 C2S0036
```

原生本輪複核：
- `0x502C11` = `0fb74304`、`0x502C15` = `6685c0`：`0046` 使用 `WORD [message+4]` 作分支 gate；
- `0x503199` = `837f0400`：`0064` 對 `DWORD [message+4]` 是否為 0 分支；`0x5031A3` = `0fbf7702`：`WORD [message+2]` 為有號任務 ID；`0x5031A9` call `0x5000D0`，`0x5031BB` call `0x500240`。
- `0x5000D0` 清掉 manager `+0x5ED0` 的匹配 WORD（20 槽）並有其他 helper；`0x500240` 重算 `+0x5EC0` 候選清單。**它們並不直接銷毀 manager `+0x5EAC` 的任務定義記錄**。

這條確實能造成任務狀態通知與後續對話（受既有 UI 場景與條件限制），但不應把 `F438C`、`0046` 或 `0064` 當成「怪物每擊殺一次就會增加 HUD 目標計數器」的證據。**沒有原生證實的 stage objective HUD 數字 writer→text widget 連結，仍列 unknown。**

## 4. WP02-04：封包方向、狀態、可見效果的矩陣

| 玩家／場景事件 | C→S（是否確實送出） | S→C（已證接收） | writer / consumer | 玩家看到的效果與未知界線 |
| --- | --- | --- | --- | --- |
| Tutorial 腳本請求開始 scenario14 | `0x4AA4D0` 在傳送物件/旗標允許時組 `0040 + WORD 14`（4-byte **業務本體**；已見 virtual sender，不等於逐次 socket runtime 實證） | 不可推定每次一定配對 `004C` | 尚無完成旗標寫入；等待另一路更新 | 不等於成功開戰，Server 的接受/拒絕格式未知 |
| Tutorial 收到 scenario 完成訊息 | 未找到由 `0x4C4F20` 自動回送的 C2S；僅限此 handler | 在 TUTO handler 域為 `004C`；`+2` unsigned WORD ID；已讀下限4 bytes（不含 framing） | `0x4C4F20 → 0x4C2880` 寫 map=1；`0x4AA510` 讀；Lua wait 消費 | 同 TUTO 有效等待可離開條件；**勝利來源、HUD 數字、獎勵與持久化未知** |
| checkpoint category4 到達／本地觸發 | `0x544070` 該 category4 分支未見直接 packet builder；不可否定其他 callback | 本次無可確定配對 S2C | `controller+0xB4+index*4=1`（kind4 gate） | 可能作本地教學／互動進度；**沒有證成戰鬥關卡 goal 計數或 Server ACK** |
| QuestMgr 任務提示 | 無法由所選 handler 反推出 Client 發包 | `0045` handler `0x5027D0` | Quest record/`QUEST_READY` 等 UI 路徑 | 提示不等任務完成 |
| QuestMgr 結果更新 | 本次不虛構對應 C2S 請求／配對順序 | `0046`：WORD ID+2、WORD result+4；`0064`：WORD ID+2、DWORD result+4 | result=0 時清活動槽、重算可用清單；0046 的 `F438C` 可開後續對話 | 局部任務進度推進，**不同於 Scenario 勝利** |
| Quest 接下一任務 | 歷史可追條件下由對話發 `C2S0036`（4-byte body） | 不可指認 `0046` 或 `0064` 一定是 `0036` 的直接回覆 | 候選清單與 mode1 UI 選擇 | 玩家可操作的後續對話；前置條件需具體 Quest 記錄 |
| 怪物倒下／Actor 消失 | 直接 kill-report／達成上報 **unknown** | T08 Actor 生滅鏈存在；尚未證和 TUTO `004C` 的 wire 因果 | kill→目標 writer→勝利 consumer **未閉合** | 不能以 HP0 + 0.75 秒替代 Server 決策 |
| 一般 Scenario 顯示關卡結果 | 不應強填 C2S | `0022/type0` 的有界路由 `0x4B9770→0x4C4550` | 結果資料→ScenarioDecision→UI state8／`F4297` | 是**結果畫面**而不是 WP02 進度；完整獎勵欄位留 WP04/05 |

**wire 概念限定**：上表 opcode 指有記錄的原生 client 業務命令／handler namespace，不把「已見 handler 與局部 builder」一律升級成實際抓包驗證的完整 network frame。完整連線、framing/dispatch、業務訊息最終 socket 證據交 T02。不得猜正式結果時間/波次/獎勵。

## 5. PE 映射與定向組語稽核收據

- PE32 i386，image base `0x400000`；BIN `.text VA=0x401000 / raw=0x400 / raw size=0x7D0200`。
- 對 `0x004C4F75`：`raw = 0x4C4F75−0x401000+0x400=0xC4375`。對 `0x005443E3`：`raw 0x1437E3`。不可用 flat 映射假定不同 section 也必須平移。
- `verify_wp02_native.py` 在當次實際 KR BIN **21/21 錨點匹配**；反編譯函式來源會有丟失 register/dataflow 的情形，關鍵行為以上述直接 bytes／objdump 及有界前提為準。GitHub 兩份重播證據：`verify_wp02_native.py`、`native-window-audit.json`。
- **對照 T01**：`T01-20261027-03` 的 T14 `scenario-flag-writer`／`same-map-and-reset` 是有限原生主張；`T01-20261027-04` 的 `result22`／`return33` 是 T07 部分確認；`T01-20261028-06` 的 quest-vs-scene 更正要求不將 Scenario14、Quest16、script1000/14 混用。**全部不等於整 Task FULL-PASS**。
- 原始來源 URL（依確定版本或 report blob 查閱）：[T14 scenario14 archived evidence](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/1d78642bfec7b5005988a1c2121404a3daadd2f62ba1e0068f8918b314b1ae99.txt)、[Quest notification audit](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/0ef1b842dc4d34ce8bda1944d6556f00862febd2ec98393030ac1518b55d3c22.txt)、[Quest UI delivery audit](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/bff92f470c840f7737652274ebcaaa36aa06c16b9f85e09cd1d1847ea9428be3.txt)、[Scenario result archived evidence](https://github.com/we88ec3-prog/ttr_anal_multi/blob/f6eeef02dfa3704aabb45349718cc9da4b35fbe0/kr/evidence/00c7ff83c85dd8f01e882d82bf2d83fcf6eed2788d3fd60dbd69682b2764d977.txt)。

## 6. WP02 結果與明確剩餘研究目標（不得虛稱整個 WP02 已閉合）

| 子項 | 實際交付 | 靜態閉合判定 |
| --- | --- | --- |
| WP02-01 資料來源／ID | BIN 原始字串 VA/raw、CScenario/Tutorial、CheckPoint、QuestMgr、一般結果各自入口／ID 域 | **有界完成** |
| WP02-02 擊殺、互動與其他事件 | category4 checkpoint 本地 writer、distance/latch、quest 結果分支；怪物/波次/計時型的候選及反證限制 | **部分完成**：原版 kill→stage goal 及其他型態無可驗證完整鏈 |
| WP02-03 writer→consumer→UI | TUTO scenario14 flag→Lua等待（有同一 owner/資源快照前提）；Quest 結果→清單重算→通知/後續對話 | **代表性局部鏈已閉合**，stage kill HUD 計數器 writer/consumer 未閉合 |
| WP02-04 C2S／S2C | 0040 builder、004C handler、0045/0046/0064 QuestMgr handler、0022 結果交界；條件及方向矩陣 | **有界完成**，真實完整 wire frame、配對／時序與 kill-report 仍待 T02／後續 T14 |

**後續仍須留在 T14 Client 逆向的精確問題（不是 Server-only 缺口）**：
1. 除 `0x544070 category4` 與 `0x4C4F20` 外，能否從怪物死亡／指定物件觸發某個 stage goal writer？需 T08/T12 已驗原生 producer、callback/XREF/virtual target，追到 T14 的實際 consumer；只核查 FC0F88 直接 literal 不能取代完整別名分析。
2. 是否存在**數字型**任務目標 HUD？需 stage/scene 顯示頁與 listener／UI widget writer，從具體資料/事件 producer 追其所有消費路徑；不要從本地語系字串猜計數算法。
3. `0x544070` category4 寫入的控制器 `+0xB4` 陣列，由何處讀取？索引範圍與生命週期何在？需完整 controller reader、初始化與 reset。
4. `0040↔004C` 與任務 `0046/0064` 是否在實際關卡按固定先後出現？需 T02 分派／framing 与真實 trace（若存在）；在此之前不創作 Server 勝利判定或官方 ACK。
5. `Event.stp/Table.stp` 真實資源成員、Quest/Scenario/CheckPoint 定義、遊戲原版發行來源之認證；本輪僅 carrier SHA 與少量靜態字串，不能把本地快照升級為 pristine。

**需要 Server 自行設計而非 Client 未查完的問題**：正式關卡勝利／失敗、合法殺怪計數、獎勵、重試與持久化、發送時間及 exactly-once。交 S00/T15 以已證 Client 接口形成候選 SPEC/GAP/ADR，不在 T14 擅改唯一 RR 台帳或創造原版常數。另保留「跨功能待整合」與「待原版 Client 實際遊玩驗證」狀態。

**WP03 下一入口**：先釐清 `0022/type0` result 狀態是否由另一路勝敗輸入驅動，與 `0x4C4F20` 的 TUTO flag 有無交集；沿 T07 `0x4B9770 / 0x4C4550`、T14 `0x4C4F20` 與 T12/T08 的死亡/事件 producer 查完整 win/fail writer，不把這次局部完成當作整體勝利已核證。
