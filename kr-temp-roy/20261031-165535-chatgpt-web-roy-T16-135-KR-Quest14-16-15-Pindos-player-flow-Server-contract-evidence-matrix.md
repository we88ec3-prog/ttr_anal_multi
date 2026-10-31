# T16-135 — Quest14 → Quest16 → Quest15 → Pindos：玩家端到端流程、Client 原生介面／Server 相容契約及驗收矩陣（KR）

- 研究者：`chatgpt-web roy`；本次產生時間 **`2026-10-31T16:55:35+08:00`**；正式研究段號 **T16-135**；上段 T16-134 Git blob `991fa3fbbb89622e264eaceb138725d597629e28`。本篇是**完整的整合型技術研究原稿及具體可交付 Server 規格候選**，不是前段聊天回顧。
- 靜態研究目標：把玩家從 Quest14 前置 → NPC10027／Quest16 → key16 解鎖 → town5／NPC10338／Quest15 → Quest15 狀態結果與 Pindos Scene3 的**所有已可證 Client 條件式鏈節**接上；每個節點寫出原生來源、前置、業務 application payload、入站 handler、持有狀態、UI/scene 效果、負例、Server 需實作與尚未確證部分。特別檢查 Quest15 交付與 Scene3 是否真正必然因果相接；**不以官方 Server 原始政策或運行流量做本段靜態研究達標門檻**。
- 使用者明確授權 **完成 T16-135 後 Commit/Push 到 `t16/roy/chatgpt-web`**，不得直接推 `main`，不得新增 branch。此對話上一輪已按使用者指示同步 `main`；本次開工 compare：`main=5897c5058a7386686efaeb6173c8ac11bd83c78b`, T16 同 SHA、`ahead=0/behind=0`，不再次無故 Merge。
- 最新 `main` T01 `T01-RETURN-T16-117-Q16-MODE2-C2S36-001` **RESOLVED**（只限勘誤，本報告和原稿不因此 FULL-PASS）；`research/dispatch/inbox/T16.md` 無待處理項，`research/requests/index.json` 無 owner_task=T16 RR。`task.json` 仍 `native_complete=false`：整個 T16 未完成，**不得改成 true**。同版共用 FULL-PASS 限定條目只按其各自主張復用，非 Quest 全文驗證。
- 第一手只讀 KR 原件：`Tartaros.bin` **12,472,320 B**，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Event.stp` **11,241,597 B**，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；`Table.stp` **5,248,784 B**，SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。未執行 Client、未動態附加、未修改原始檔、未取得原版 Server traffic。
- PE `ImageBase=0x400000`, `.text RVA=0x1000/raw=0x400`，原生 code raw=`VA−0x400C00`。附錄逐個從本次原件抽 bytes、各自列 SHA256 並反組譯；**附錄的 byte hash 是直接 BIN 證據**，不能拿多段重用前稿文字冒充重新驗證。標準 x86 little-endian，明示 signed/unsigned 欄位差異。
- **範圍宣告**：T16-135 本段「已完成」僅指**已知 Client 條件式互動、業務 application 佈局、場景鍵與 Server 交接契約之整合與具體測試矩陣**。官服原本的 C→S/S→C 特定 pairing、實際 Quest15 必播 Scene3、完整 XML row、transport framing/接收時序、真正可玩與發獎、T01 全文審核均**未證**，不宣稱它們已完成。

## A. 對玩家可見的逐階段操作與可實作的接受準則

| 玩家／角色節點 | Client 必要先決與可能行為（原生、有條件） | Server 相容端需要做的事（**自行決策，不是官方已證規則**） | 玩家應測什麼；有何反例 |
|---|---|---|---|
| **P0：角色進入 Quest14 前後** | Quest14 歷史來源 type3、NPC10027、`CompleteAction type1`；Client 可由 `0x74(key14)` 或 `0x6F` prereq snapshot 取得 key14，重新運算任務候選 | 定義 Quest14 通關/完成權威及何時給 key14；持久化角色進度 | 未得 key14 不應因同 NPC 自動出現 Q16；即使拿到 key14，town/level/exclusion 仍要通過 |
| **P1：可接 Quest16** | Quest16 `type2`、Demand14、town0、giver10027；`0x500240` 依 prereq/town/level/exclusion rebuild，`0x5008B0/0x500A00` 由 NPC selector 找可接 type2 首候選 | 確保該角色有相容初始狀態、解鎖和 NPC 上下文；不要把 `NPC10027` 當 QuestID | NPC 不存在、town 錯、level gate 失敗、Q16 被排除時不得保證選中16 |
| **P2：玩家點 NPC10027** | local action `F43D9` / nested `0x105BF+0x14=10027`、候選選出 QID16 → `0x561760(16,1)`；另可能 C→S `0x1C`、正常 deferred 時 `0x3F` | 接受/拒絕/延後業務事件與角色狀態由 Server 定義；要保留 0x1C 與 0x3F 的獨立語意 | 點 NPC 不代表 Quest16 已被 Server 接受，不能預測必然取得 `0x40` 回覆 |
| **P3：Quest16 對話／接取 UI** | 在 Client 收到 `0x40(qid16,state0)` 時，發出 `0x105B9/action F438B/QID16` → mode2 TalkBox；同時依條件更新 20-slot exclusion 及候選重算 | 若希望相容 Client 顯示該 UI，需按正確 application 資料形狀送訊息，並選擇與請求的合法時序 | `F438A`=mode1 不是此路；TalkBox+0x84 是 giver10027，不是 QID16；收包不等於獎勵已入帳 |
| **P4：Quest16 交付／完成回饋** | `0x45` 依 CompleteAction；`0x46(q16,substate0)` 可能移除 exclusion、寫 prereq key16、重建候選、F438C→mode3；`0x74(16)` 可單獨寫 key16，`0x6F` 可 snapshot 覆蓋 | Server 定義認證、條件檢查、進度保存/給獎的原子性；根據相容 Client 的狀態效果選擇合法更新方式 | `0x46` 不等於 `0x74`；`0x6F` 後送會替換先前增量 key，需測覆蓋與冪等 |
| **P5：Quest15 解鎖** | Quest15 `type2`、Demand16、town5、giver10338；`0x38` 提供 world/town selector、`0x74(16)` 或 `0x6F` bit16 令 Demand 通過並 rebuild | 定義角色何時允許進 town5，提供相容 world/NPC 場景及角色狀態 | key16 單獨不足；在 town0、錯世界、被排除時不得保證可接 Q15 |
| **P6：玩家點 NPC10338，接 Quest15** | type2 selector → QID15 → `0x561760(15,1)`，0x1C NPC context、條件式 0x3F；若收 `0x40(15,0)` 進 mode2 | 處理合法任務意圖，支援 UI 與任務狀態相容回覆 | 0x1C 內兩 WORD 是事件欄位，不一定是15；0x3F 也不是「成功接取」的直接證據 |
| **P7：Quest15 交付與劇情** | `0x46(15,0)`=任務狀態／mode3；**不直接**呼叫 `0x561760`。可能的場景來源是 `0x45` 的 CompleteAction type2、`0x40` 的 AcceptAction type2、獨立 `0x47(primary,secondary)`、章節物件 FIRST、scene controller NEXT | Server 分別設計任務完成/獎勵/Scene scheduling；不要把 0x46 和 0x47 合成一個「完成即播放」封包 | 是否確實選到 Scene3 必須有合法 resource record、controller gate 與場景 mapping；`0x47(15,3)` 只是**合成測試向量** |
| **P8：Pindos Scene3 播放／返回** | Event scene key 命中 `(15,3)` 才可能執行 `pindos_talkevent`：`town001D.map`、4次 Talk、`DoProlog(1)`、`RestoreMap()` | Server 保持玩家權威場景/角色進度、切回可玩狀態；具體策略經 S00 ADR | 腳本播放/DoProlog 不代表已發獎；回圖可能是臨時演出後還原，並非永遠落地 town001D |

**這張表是玩家流程的條件式契約，不是「官服每一步必定依這個封包次序回覆」的宣告。** P0→P8 的 UI、local cache 與後端持久化必須保持各自的權威界線，避免 Server 以看見 mode3 作為獎勵或 DB commit 的唯一判據。

## B. 固定 namespace、Client 物件及資源真實性

### B1. 已有資源文獻，且實體 loader/consumer 可再次確認的欄位

先前 T16-112/118/124/125 的 QuestInfo XML 擷取（**本次並未重新解壓整份 Table/QuestInfo.xml**）記錄：

```xml
<Quest id="14" type="3" town="0" field="18" level="1" giver="10027" finisher="10027" subtype="1"><CompleteAction type="1" /><AcceptAction type="1" /></Quest>
<Quest id="16" type="2" town="0" level="1" giver="10027" finisher="10027" subtype="1"><Demands><Demand id="14"/></Demands><RewardsEtc id="16"><Reward type="2" value="50"/></RewardsEtc></Quest>
<Quest id="15" type="2" town="5" field="19" level="1" giver="10338" finisher="10338" subtype="1"><Demands><Demand id="16"/></Demands></Quest>
```

這些值是**前段原始 XML 擷取的歷史來源聲稱**，其解析/寫入/過濾函式由本次 BIN 有界覆核；完整 Q15 的 AcceptAction/CompleteAction、type2/type4 reward `2800/468` 等元資料**不得以不存在的 XML node 假造**。此外 Quest16 reward(type2,value50) 只是 Client QuestRecord `+0x88` metadata，不是伺服器交易證據。Q15／Q16 的 `Demand` 等是本地候選先決，**不能**直接假定 Server 原版遵循同一權威 policy。

### B2. 區分的命名空間與欄位

| Namespace / owner | 欄位／數值 | 有證 Client 效果 | 非等價對象 |
|---|---|---|---|
| QuestInfo `Quest.id` | Q14=14，Q16=16，Q15=15；record+0x04 type | 按任務 ID 查 record、計算候選 | ChapterIndex、Server route、sceneId |
| QuestInfo `Demands` | record+0x10..14 DWORD IDs | 0x500240 用 owner prerequisite WORD keys 比對 | QuestOwner exclusion slots |
| `QuestOwner+0x5EB0/+0x5EB4` | prereq WORD vector | 0x74 append、0x72 reset、0x6F snapshot 可覆蓋、0x46 subtype0 條件 append | DB persisted reward、QuestState machine enum |
| `QuestOwner+0x5EC0` | current candidate WORD vector | 0x500240 重算、NPC type2 `0x5008B0` 取首個符合候選 | 通用 NPC/actor 列表 |
| `QuestOwner+0x5ED0` | 20 × WORD exclusion cache | 0x40 state0 加入、0x64/0x46 state0 移除、0x65 清空 | prerequisite key14/16 vector |
| QuestRecord `+0x20` | town filter（Q16:0/Q15:5） | 對 world current town 過濾 | `town001D.map`, Chapter primary=15 |
| QuestRecord `+0x28` | giver filter（10027/10338） | type2 NPC selector 比對 | event+0x18/1C、script NPC object10047 |
| QuestRecord `+0x3C/+0x40` | AcceptAction type/param | `0x40` subtype=2 門檻下才可 scene controller | `+0x44/+0x48` CompleteAction |
| QuestRecord `+0x44/+0x48` | CompleteAction type/param | `0x45` subtype=2 門檻下才可 controller | `0x46` state0 cache update |
| SceneController `0xFB73C0` | `+0x28` active、`+0x38/+0x3C` keys、`+0x89` scene-mode flag | 0x561760 / 0x565720 / 0x561DB0 gate/read/write | QuestOwner progress、Server completion |
| Table Chapter SceneList | `chapterIdx → ordered sceneIdx vector` | 0x47E890 FIRST / 0x47E640 NEXT | Event SceneList pair lookup；序列不得假設 +1 |
| Event SceneList | `(questIdx,sceneIdx) → funcName` | 0x565720 對場景鍵尋找 Lua script | 0x38 town selector、XML field19 |
| NPC actor | `instance+0xF4` kind, `+0xF6` selector | F43D9 event / 0x105BF | UI TalkBox+0x84 giver、0x105B9+0x14 qid |
| Scene3 原始 Lua | `CreateObject(...,10047)`, map `town001D.map` | 臨時 cutscene 演出 | Quest15 giver10338、存檔出生點 |

特別禁止：`type2` (QuestInfo record type)、`AcceptAction.type==2`、`mode2 TalkBox`、`Reward type2` 四種不同整數2混為一種；同樣禁止由 opcode `0x47` 的數字名稱推論 ChapterIndex 或 QuestID；0x422F40 只是 controller singleton accessor。

## C. 方向別 application schema（下列是 **local app payload**，不是 framing / TCP wire proof）

表中最小長度只指現有 producer/consumer 直接讀到的 bytes、**不代表 transport 實際 frame 的完整長度或通用 malformed 防護**。所有 WORD/DWORD 按 LE 表示，人工十六進位樣例不冒充抓包。

| 方向 | app command / 分支 | 原生 payload 布局（byte offset from app start） | 研究範圍、Client gate / consumer | 禁止誤稱 |
|---|---|---|---|---|
| C→S | `0x001C` | `[+0:u16]=0x001C, [+2:u16]=nested event+0x18, [+4:u16]=nested event+0x1C`；6B | `0x5B9340` NPC event，sender gate `0xFBA798==0` 並嘗試 enqueue | [+2] **不是**天然 QID15/16；未證 Server 收到 |
| C→S | `0x003F` | `[+0:u16]=0x003F,[+2:u16]=primary,[+4:u16]=secondary,[+6:u16]=1`；8B | controller `0x561DB0 → 0x4A39A0`，pending/模式/sender gate | QID=15、secondary=1 **僅特定輸入**；不是 accept ACK |
| C→S | `0x0036` | `[+0:u16]=0x0036,[+2:u16]=qid/producer WORD`；4B | `0x4B3510` 取 input+2；另外 `0x636E10` 在 action F4402 / mode1 限制下 | **不能**說任何 mode2／mode3 按鈕必發0x36；不能推官服 pairing |
| S→C | `0x0040` | `[+2:u16]=qid,[+4:u32]=state`；至少8B | `0x502270`，state0→`0x105B9/F438B`、mode2、exclusion insert/rebuild；state1 文字通知；其他 state 無法仿照0 | 不是直接 completion／發獎 ACK |
| S→C | `0x0045` | `[+2:i16]=qid`；至少4B | `0x5027D0` 查 QuestInfo；`CompleteAction` type2→controller `(qid,param)`、type3→另一 event、其餘通知 | **不**等於0x46、不是必播 Scene3 |
| S→C | `0x0046` | `[+2:u16]=qid,[+4:u16]=substate`；至少6B | `0x502B40`：sub0→排除移除、按 subtype record gate 新增 prerequisite、候選重建／F438C mode3；1..5異路 | state0 的 cache 變更不直接 call scene controller |
| S→C | `0x0047` | `[+2:i16]=primary,[+4:i16]=secondary`；至少6B | `0x503040 → 0x561760(primary,secondary)`；再經 active/scene busy 等門檻 | 不直接 `0x565720(15,3)`、不是 Quest15 completed |
| S→C | `0x0074` | `[+2:u16]=prereq key`；至少4B | `0x503400 → 0x44B4E0(owner+5EB0) → rebuild` | 不標記收取獎勵，不更新Scene key |
| S→C | `0x0072` | 已確認 handler 清空所有 prerequisite keys（完整 payload 在本稿不擴張） | reset prereq vector | 不等於移除 20-slot exclusions |
| S→C | `0x006F` | bitmask bulk snapshot，**完整 shape/length 需沿 T16-128/T02 複核** | 0x44AB70/0x44AA10 等負責重建 prerequisite vector | 會替換以前0x74/0x46增量，不是單筆追加 |
| S→C | `0x0064` / `0x0065` | 64 單筆 exclusion 移除／65 全量 exclusion 清空（header/狀態 gate 按 T16-123/128） | 與 0x72 prereq reset 不同 | 不可拿來清 key14/16 |
| S→C | `0x0038` | town/world selector writer（詳 T16-124；本稿不虛填所有 substate bytes） | 讓 world+0x8C 值變更並觸發候選重算 | `town5` 不能當作 chapter key5 |

**自製測試向量，均是 app payload，非 wire packet：**

```text
74 00 0E 00                 # S2C append prerequisite key14
74 00 10 00                 # S2C append prerequisite key16
40 00 10 00 00 00 00 00     # S2C Q16 state0, mode2 candidate/UI
40 00 0F 00 00 00 00 00     # S2C Q15 state0, mode2 candidate/UI
46 00 10 00 00 00           # S2C Q16 substate0, gated mode3 and optional key16
46 00 0F 00 00 00           # S2C Q15 substate0, gated mode3 and optional key15
47 00 0F 00 03 00           # S2C hypothetical explicit controller keys(15,3)
3F 00 0F 00 01 00 01 00     # C2S hypothetical controller(15,1), gate-dependent
36 00 0F 00                 # C2S hypothetical direct QID15 producer, gate-dependent
```

這些向量不應被寫入 S00 canonical wire sample、不能自動決定 Server 發送順序；實際應用層 parser 仍需 T02 framing/transport 校驗。若 fixture 的輸入 app buffer 尚未通過 transport/framer，不能推導其實際可達性。

## D. Client 端到端有條件資料與事件因果圖

```text
[歷史 XML Q14/type3 NPC10027] --Server/business decision UNKNOWN-->
       S2C 0x74(key14) / 0x6F(snapshot bit14)
        ↓ owner prereq WORD vector + candidate rebuild(0x500240)
[Quest16 type2/Demand14/town0/giver10027] --- gate selector、level、exclusion -->
  actor NPC10027 event +F6=10027 --> local action F43D9/type105BF
    ├─ 0x5008B0 → first type2 QID16 → controller 0x561760(16,1)
    │       └─ only normal deferred + gate → C2S 0x003F(16,1,1)
    └─ separately C2S 0x001C(event +0x18/+0x1C)
                 [Server request/response pairing NOT PROVEN]
       S2C 0x40(QID16,state0) -> F438B/QID16 -> QuestInfo map -> mode2 TalkBox
                + 20-slot exclusions update / candidate rebuild
       C2S 0x36 only under its independent mode/action/producer gate
                 [Server completion/award decision NOT PROVEN]
       S2C 0x46(QID16,sub0) -> excludes remove + optional prerequisite key16
       S2C 0x74(key16) or 0x6F(snapshot bit16) -> owner prereq vector
       S2C 0x38 / world town selector=5, level/exclusion gates → rebuild
[Quest15 type2/Demand16/town5/giver10338] --- independent gate -->
  actor NPC10338 -> local event F43D9/type105BF -> QID15
    ├─ 0x561760(15,1) -> gated C2S 0x003F(15,1,1)
    └─ independent C2S 0x001C NPC event context
             [Server pairing UNPROVEN]
       S2C 0x40(15,state0) -> F438B -> mode2 TalkBox + exclusion
       C2S 0x36 (another conditional producer)
       S2C 0x46(15,sub0) -> optional key15 + F438C -> mode3 TalkBox
                            X no *direct* sceneController call here
                            X cannot equate completion/award/Scene3
       S2C 0x45(15) [if completeAction.type==2] -->(15,record+0x48)
       S2C 0x40(15,state0) [if acceptAction.type==2] -->(15,record+0x40)
       S2C 0x47(primary,secondary) ---------------->controller 0x561760
       chapter object+0x248 → TableSceneList FIRST → 0x565720
       scene-running controller → TableSceneList NEXT (not +1) → 0x565720
       controller: busy/state gate +0x28/+0x89, keys +0x38/+0x3C
                    ↓ correct key pair and Event SceneList hit
       0x565720 → Event SceneList(15,3) → script loader → Lua Scene3
                    ↓ (possible) player playback
       map town001D / talks18,24,20,21 / DoProlog(1) / RestoreMap

       [No origin trace proves Q15 completion → 0x47(15,3) or 0x45 param3]
       [No native Q.Prolog/RestoreMap alone proves DB or award persistence]
```

### D1. 必要相反例與被排除的「錯誤完成捷徑」

1. **`0x46(15,0)` 沒有直接呼叫 Scene controller**：該 handler 確實有 QuestOwner 與 UI 副作用，但不能用「已找到 mode3」替代場景因果。若其他排程器跨 event 間接進場，需另外有原生 callback link，不能用否證直接 CALL 推成全程不可能。
2. **`0x40`/`0x45` action descriptor 不相同**：+0x3C/+0x40（AcceptAction）與 +0x44/+0x48（CompleteAction）分開；不能從 QuestInfo.type2 或 Reward.type2 推導必走 action2／param3。
3. **`0x47` 的兩個 WORD**只進 `0x561760`。`0x422F40` 返回 singleton this pointer，而非把鍵轉成 Scene3；controller 可能 busy、defer、normal 發 0x3F，甚至不直接 script load。
4. **NEXT**由 Table Chapter ordered vector 求 successor；沒有 row 時不能硬碼 `sceneIdx++` 或一律「Scene1→Scene2→Scene3→Scene4」。FIRST 缺／特殊 key `0xEA61` 都有不進普通 Scene 入口的控制流。
5. **Scene3 Lua**是演出資源，`DoProlog(1)`、`RestoreMap()` 受注入 callback／coroutine/error gate 影響；不能當成 Server Quest15 獎勵確認或永久村莊出生點。
6. **0x36 的 mode1 action F4402 限定**：T16-117 的舊泛化已被 T01 修正，不能復活「mode1..3 都必發 0x36」的錯誤；另 `0x4B3510` 獨立 producer 存在。

## E. 伺服器規格交接：可開發的責任界線、候選需求與不變量

下列是提供 S00 去重/正式建立的 **Server 需求候選（不是已核准的 REQ ID）**。核對 `design/requirements/index.json` 現有 REQ-0001..0008（登入/角色/WebAdmin/網路等）**沒有直接對應 Quest14/16/15 專屬 REQ**；不得擅自把本篇命名成 `REQ-0009` 或標 APPROVED。正式 SPEC 目前以 `SPEC-NET-0001/0002/0003`、`SPEC-SCENE-0001` 及其部分界線為可追溯的依賴；**尚無對此 Quest 交易已核准的 STABLE 契約**。

| 候選需求（暫定名稱，非正式 ID） | Server 相容決策／實作責任 | Client 對外可核對介面 | S00 應建立/核對的受影響關聯 |
|---|---|---|---|
| QUEST-PLAYER-STATE | 角色隔離保存前置鍵14/16、可接／已接／已完成狀態與適當世代/重連快照 | 0x74 append、0x6F snapshot、0x72 clear 與候選重算；同步/快照不同於 DB 交易 | 新 Quest SPEC + state consistency GAP + reconnect TEST；T15/T03/T04 參與 |
| QUEST-NPC-CONTEXT | 驗證 NPC10027/10338、人物/場景/權限，辨識 C2S 0x1C 事件 context；拒絕非法/重播 | 0x1C 6B 的來源是 nested event+18/1C；QID 取自**另外**的候選路徑 | NPC context/actor mapping 與 T08/T07；避免把 [+2] 直接當 QID |
| QUEST-CONTROLLER-INTENT | 獨立識別 C2S 0x3F 的主鍵/次鍵與 deferred gate，與 0x1C/0x36 不合併 | 0x3F u16×4 layout、controller+28/+89 gating | T02 framing/queue; Scene/T16 功能契約；重送/拒絕測試 |
| QUEST-UI-RESULT | 針對合法接取／交付設計可被 Client 消費的 0x40/0x45/0x46 與錯誤/重試結果，保持 mode2/mode3分別 | F438B→mode2、F438C→mode3；+0x80 QID、+0x84 giver | T06 UI、Quest SPEC 的 success/failure state 表，不推官服 ACK 配對 |
| QUEST-UNLOCK | 明確規劃 Q14 令 Q16 候選、Q16 令 Q15 候選、world town5 限制 | key14/16、world+8C、rebuild、20-slot exclusion | Quest SPEC, T07 world, T15 persistence, 避免 client cache重建與 DB 混淆 |
| QUEST-REWARD-TRANSACTION | 在後端對任務發獎、變更進度/版本與重放冪等；要確保授予一次 | QuestRecord reward metadata 50、2800/468 待複核；Client 不可證實獎勵實際落帳 | S00 ADR 定義相容 reward policy；T14/T15 交接；禁稱官服原規則 |
| SCENE-KEY-SCHEDULING | 決定何時送合法場景鍵與劇情條件；Scene3 是另一獨立觸發/記錄責任 | 0x45/0x40 type2 resource key、0x47 pair、FIRST/NEXT/`0x565720` | T07 scene/loader，分清 XML action descriptor 未證與 script already present |
| SCENE-INTERRUPTION-RECOVERY | 在 Client runtime 場景中斷、busy、無索引／腳本載入失敗後協調回收/恢復 | controller+28/+89、0x6EDB60 deferred、Lua RestoreMap/RevPhase1 | T06/T07/T15，設 TEST 覆蓋 retry/scene fallback；不可假想 client所有失敗自復原 |
| QUEUE-TRANSPORT-CONTRACT | 依實際角色 session 與連線 slot 將 app payload 正確 framing/encrypt/送達 | 0xFBA798 只表示 enqueue gate；T02 0x1A68/0x0BBB/recv dispatcher 等 | T02 SPEC-NET-0001..3; 避免直接把本文 app HEX 寫在 TCP socket |

### E1. 實作者必須保持的資料不變量（Server 自訂約束，非官服已知策略）

- **角色權威分離**：同帳號不同角色的 Quest/Reward/Scene 狀態不得共享；Server receipt/decision 不能只因 Client 已顯示 dialogue 作成功處理。
- **完成交易**：同一可重試 Quest 完成/獎勵行為需要冪等 key 或其他防雙領方案；**具體 DB schema/演算法由 Server 決定**，不是 Client 可反推。
- **快照與增量一致性**：若發 `0x46`/`0x74` 後又發舊 `0x6F` snapshot，Client prerequisite 會被覆蓋而失去 key；相容 Server 必須提供一致的狀態發布策略與重新進圖/重登測試。
- **提示與權威分離**：mode2 表示可建構接取類 UI，mode3 表示完成類提示；任一 UI 都不是 Server 已發獎證據，也不得以 Client 本地 exclusion 20 slots 當成 DB 唯一狀態。
- **劇情權威分離**：Quest15 完成後是否播放 `(15,3)` 必須有 S00 決策、已校對資料/相容 scene key、T07 gating 與測試；暫不能以 `0x46` 無條件實作「完成即 Scene3」。
- **合成向量不可變官服真值**：本篇 0x47(15,3) 只供 Client 有界解析/dispatch 驗證，S00 對實機預期序列要等 runtime/source補證。

### E2. 具體接收/處理建議（設計候選偽碼；不冒稱 Client native）

```cpp
// SERVER DESIGN CANDIDATE ONLY, not recovered official server.
void handleQuestNpcContext(Session s, NpcEvent app1C) {
    requireAuthorizedCharacter(s);
    auto context = resolveNpcEvent(s.character, app1C.eventWords);  // mapping UNPROVEN
    if (!context.valid) { rejectOrIgnoreByApprovedPolicy(); return; }
    // Determine eligible quest and reply under S00-approved policy;
    // 0x1C itself must NOT be decoded as raw QuestID without a mapping.
}
void handleQuestController(Session s, ControllerIntent app3F) {
    requireAuthorizedCharacter(s);
    // Validate primary and secondary separately. This is NOT identical to 0x1C/0x36.
    applyApprovedSceneOrQuestIntentPolicy(s, app3F.primary, app3F.secondary);
}
void publishQuestState(Character c, QuestState state) {
    // Atomic server-side truth/persistence is separate from client hints.
    // Validate 0x40, 0x46, 0x74, 0x6F layout and exact ordering first.
    // Scene scheduling and rewards are separate authority paths.
}
```

## F. 具體互通與回歸測試契約（全數目前 `NOT_RUN`；fixtures ≠ 原生抓包）

每條測試均需至少記錄：KR 原始檔 SHA、Server build/commit、帳號角色匿名 ID、連線 slot / transport mode、輸入 app bytes & 外框 bytes（若已捕得）、Client local cache/事件、NPC/UI/Scene 可見結果、角色重登前後狀態、失敗/超時、回歸紀錄；無原版 Client 執行權時只能以**離線合成 parser/handler**預演，不能勾成 PASS。驗收由 S00／Server 開發與測試人員另行負責。

| ID | 測試情境／人工前置 | 應核對的 Client branch / Server 決策要求 | 目前 |
|---|---|---|---|
| QTEST-01 | 無 key14，玩家到 NPC10027 | Q16 Demand14 失敗；不假設 Quest16 自動接取 | NOT_RUN |
| QTEST-02 | 合法 `0x74(14)`，world town0/level/20-slot 合格 | key14 寫入、候選 rebuild 可能有 Q16 | NOT_RUN |
| QTEST-03 | 同 QTEST-02，但 Q16 exclusion 中存在16 | candidate 不應無條件包含16 | NOT_RUN |
| QTEST-04 | Q16 type2 NPC 10027，正確 kind3/action/event gate | QID16 選入 controller；0x1C 若 sender gate0 嘗試 enqueue | NOT_RUN |
| QTEST-05 | NPC10027 事件 `+18/+1C` 與 QID16 數值不同 | 0x1C 仍以原 event words 編碼；禁止伺服器直接解讀為16 | NOT_RUN |
| QTEST-06 | controller primary16/secondary1，normal/deferred/sender gate 成立 | 0x3F 8B producer；不把0x1C當相同事件 | NOT_RUN |
| QTEST-07 | controller busy、特殊 mode，或 sender gate 非0 | 0x3F 不得被測試預期成必送；要觀察 deferred/skip | NOT_RUN |
| QTEST-08 | 合成 `0x40(16,state0)`，QuestInfo16 可查 | F438B→mode2 TalkBox，exclusion16 更新/候選重建 | NOT_RUN |
| QTEST-09 | 合成 `0x40(16,state1)` | 文字通知分支，不得直接當 mode2 新接取 | NOT_RUN |
| QTEST-10 | mode2 UI 動作；不滿足 F4402/mode1 | 不能預設 0x636E10→0x36，另查獨立 producer | NOT_RUN |
| QTEST-11 | 合成 `0x46(16,sub0)` 且記錄 subtype!=3 | 移 exclusion，寫 prereq key16、F438C mode3（UI gate） | NOT_RUN |
| QTEST-12 | 合成 `0x46(16,sub0)` 但 record miss/subtype==3 | 不可假定新增 key16，需維持反例 | NOT_RUN |
| QTEST-13 | `0x74(16)` 後合法 world town5 + level | Q15 Demand16 通過可候選，NPC10338 type2 select | NOT_RUN |
| QTEST-14 | 只有 key16，仍在 world town0 或 Q15 exclusion 存在 | Q15 不必出現；不可固定 NPC 結果 | NOT_RUN |
| QTEST-15 | `0x6F` snapshot 不含 key16、晚於0x74 | key16 可能被覆蓋，Q15 不可保證仍可接；需 Server 版本/順序策略 | NOT_RUN |
| QTEST-16 | 玩家 NPC10338 正常互動，type2 QID15 | controller(15,1)、0x1C event context、0x3F 條件分流 | NOT_RUN |
| QTEST-17 | S2C `0x40(15,0)`，QuestInfo15 命中 | F438B→mode2 UI、exclusion/cache 效果 | NOT_RUN |
| QTEST-18 | 合成 `0x46(15,0)`，record subtype!=3 | mode3、可能 key15、候選 rebuild；**無 0x46 直接 Scene3 call** | NOT_RUN |
| QTEST-19 | S2C `0x45(15)`，CompleteAction type2,param3 | pair(15,3) 送 controller；真正 resource action 值仍未核實 | NOT_RUN |
| QTEST-20 | S2C `0x45(15)`，CompleteAction type3 / record miss | 走 F4306 / skip 等相反分支，不送相同 pair | NOT_RUN |
| QTEST-21 | S2C `0x40(15,0)`，AcceptAction type2,param3 | pair(15,3) 可送 controller；不能據此稱完成 | NOT_RUN |
| QTEST-22 | 合成 `0x47(15,3)`，controller idle vs busy | signed WORD pair；idle gate 寫鍵、busy 轉 0x6EDB60；不得保證立即腳本 | NOT_RUN |
| QTEST-23 | Event SceneList 無 `(15,3)` | 0x565720 map miss，不用近似名稱拼 script | NOT_RUN |
| QTEST-24 | Chapter FIRST vector 空或 special key0xEA61 | 不自動設為scene3；走正確 special/miss branch | NOT_RUN |
| QTEST-25 | Chapter NEXT current不在 list 或已到尾 | successor=0，清鍵或結束；不可 +1 | NOT_RUN |
| QTEST-26 | Scene3 Lua 成功 | 驗證四段對話、DoProlog(1)、RestoreMap、RevPhase1、實際 UI/input 恢復 | NOT_RUN |
| QTEST-27 | Scene3 Lua 腳本 callback失敗/中斷 | 要量測是否 RevPhase1 到達；不預設 UI 一定恢復 | NOT_RUN |
| QTEST-28 | 同角色重登，Server 報快照/增量，Q16已完成Q15未完成 | key16、world、NPC、scene、任務與 UI 不矛盾；驗證持久化 | NOT_RUN |
| QTEST-29 | 重播 Q16 / Q15 completion 指令 | Server 不重複給獎；Client 0x46/0x74/0x6F 排序無錯亂 | NOT_RUN |
| QTEST-30 | 兩不同角色／跨帳號事件重播 | 僅相應角色更新，非法事件拒絕，無跨角色 unlock/發獎 | NOT_RUN |
| QTEST-31 | 錯誤長度、checksum、分段/合包 | 應由 T02 確認 framing/decoder 才能測；local app min width 不作 transport 驗證 | NOT_RUN |
| QTEST-32 | Scene3 之後進正常村莊地圖 | 確認 `RestoreMap` 不等於永久 position；對照 Server scene/角色權威 | NOT_RUN |

**驗收必要區分**：`QTEST-08/17` 只驗「S2C payload → Client mode2 UI」；`QTEST-11/18` 只驗「mode3／progress cache」；`QTEST-22～27` 才驗「scene key→Lua」。任何一組單獨 PASS 都**不能**將 Quest16→Quest15→Pindos 的官方同一局端到端設為 PASS。必須另外拿到相容 Server 實機追蹤與經核准的完整規格，才可開展真正 E2E 接受測試。

## G. 四種研究缺口的正確交接與可操作解除條件

| 分類 | 仍未證的精確鏈節 | 可解除阻塞的材料／責任、對契約的影響 |
|---|---|---|
| **Client 待逆向** | Quest15 `AcceptAction/CompleteAction.type/param` 真實完整 XML、reward 2800/468 節點 | 直接解包完整 Table/QuestInfo.xml 或具原始 bytes/hash 的可信擷取，確認 Q15 的 action type==2 與 param 是否為3；否則 0x40/45→Scene3 只可列 conditional |
| **Client 待逆向** | `Table/SceneList.xml` Chapter 真實 rows、chapter key、sceneIdx 順序（是否包含 `(15,3)`） | 原件 STPD 解包後對 Chapter vector FIRST/NEXT 載入器比對；缺 row 時不能預設 Scene1→2→3→4 |
| **Client 待逆向** | controller busy `0x6EDB60` 的所有 deferred replay、副作用；Lua `RestoreMap`→scene NEXT 真正間接 callback | 定向追目標函式入口／注入 writer、vtable、event queue poll；不能僅說「需要 Server」就停止本地探索 |
| **Client 待逆向** | `0x45` subtype3 UI end/文字等所有細部、0x36 independent producer 的 button pairing | 依 T16-128/134 的 Caller 再定向回查，避免 mode2 submit 假陽性 |
| **Server 待開發** | 玩家接/交/完成校驗、reward50/未知 Q15 reward、合法回覆時序與持久化 | S00 審查後建立 Quest SPEC/GAP/ADR；Server 依原生 payload schema 自選策略；不得倒寫官服真值 |
| **Server 待開發** | Session/Role 權威、重放防護、角色 progress snapshot、NPC/scene intent 綁定 | T03/T04/T15 給角色/會話生命週期、Server transaction/version 策略；保持 App vs transport 界線 |
| **跨功能待整合** | 真正網路外框/連線 slot；NPC 場景物件可見/點擊；場景 loader/restore；關卡勝敗結果 | T02/T08/T07/T06/T14/T15 提供已證接口及驗收，T16 不自行覆寫他 Task 的成果 |
| **待遊玩驗證** | 玩家從 Q14 連續接 Q16、完成、解鎖 Q15、Scene3 播放及返回 | 獲授權以原始 Client 對接相容 Server，保存時間序列與角色 state 前後 snapshot；單靠離線反組譯無法替代 |

已查 `spec/spec-index.json`、`design/gaps/index.json`、`design/requirements/index.json`、`spec/world/SPEC-SCENE-0001.md`、`spec/IMPLEMENTER-HANDOFF.md`：目前 SPEC-SCENE-0001 僅為 DRAFT/PARTIAL 的靜態資源鏈，還不是任務接/交/完成及原版 Server 封包 pairing 的 normatively stable 規格。本篇提供的是 S00 去重/審核輸入，不建立新 RR 或平行台帳；不代替 T01 主張級審核，不推動 `task.json.native_complete`。

## H. 證據鏈索引與舊稿修正的正確使用方式

| 前稿／遠端 Git blob | 本篇具體復用範圍 | 關鍵修正／限制 |
|---|---|---|
| T16-118／`3ad1553532ea46d0fdcd846e0ac379933b431cd4`（commit） | Q16 Demand14、record reward50 loader、candidate gate | 不把 reward50 metadata 當貨幣入帳；記錄舊 XML 擷取來源 |
| T16-121／`e5d48e09ac8604ac39ce0dc584bb20308d927b54` | NPC10027 → type2 QID16；S2C 0x40 state0→F438B→**mode2** | 反對以 F438A mode1 或 +0x84 giver 硬接 QID16 |
| T16-122／`d056bb2d0ff4ee136e13f2ff8c034434a61b2d87` | 0x1C/0x3F/0x36 C2S sender/queue | 0x36 獨立 mode/action producer，不合併為單一 accept opcode |
| T16-123／`0df4598be826c4b6fea0627278b77b3026ecd52e` | 0x40/64/65/72/74 state/cache effect | 0x40/exclusion 與 0x74/prereq 效果不同 |
| T16-124／`79d147affae5e54b688876a1a1ae9765a6edfbaa` | 16→15 Demand16、world town5、NPC10338 gate | 0x38 world selector 不等於 ChapterIndex 或合法 Scene3 |
| T16-125／`983535d340331f03ca1e253bc1d73e26bb08dd8f` | Q15 resources & four scenes | Q15 2800/468 未從完整實體 XML 第一手重取，不能宣稱已證財物 |
| T16-126／`ae6e38af9c7078c23c21ca793e49bbcbc31b8ea6` | NPC10338 actor kind/selector event | actor producer gate/instance來源不同於 UI asset |
| T16-127／`4e8e07719e882b4525481641dce929dd9786b87d` | Q15 0x1C/0x3F/0x36 三 producer | pending flag 與 sender gate、副作用不能推必然發送 |
| T16-128／`bddbc8f94c32a3a69a43537be0631f7be3cb9a79` | Q15 0x40/45/46/47/6F/UI、record+3C/44 | 0x46 state0 不直接等於完成發獎或 Scene3 |
| T16-129／`edaaa5a94c56576eba8bf5c2ad5ff65ff6431c80` | Event SceneList native loader + Lua Scene3 | resource存在≠ runtime必達 |
| T16-130／`2085ab6b507c56c8be5003f00546c96a53f705b6` | Table Chapter FIRST/NEXT | 排除 `next=old+1` 的偽假設 |
| T16-131／`354ec7c6d226a720b74d54f17c289a3b6ca33295` | 0x47 input、controller writer、scene object primary key | primary/secondary不是自動等於 QuestID、scene3 |
| T16-132／`16550cf62fb2ecbd539e07f568982e1d18d9b942` | busy/miss/special/next/no-successor | 避免掉入 always-play 或 always-reset happy path |
| T16-133／`72970ebc9b300f3b4911b21909756700d23be53c` | Lua compiled qbase/Scene3 Prolog/RestoreMap | Prolog callback writer/真實 UI 恢復仍不全確證 |
| T16-134／`991fa3fbbb89622e264eaceb138725d597629e28` | 跨雙向封包與 Scene3 的有界因果反例；`0x422F40` singleton | 0x46 不是 scene command；0x45/40 是 type/param gate；0x47 不保證直接執行 |

> 資料溯源提醒：其他前段在過去時間產生的 SHA/進度只用作該時點原稿身份，**本篇最新 Git 開工與對外提交狀態另以即時遠端為準**。所有肯定結論限定 KR 原件 SHA；即使某些 T01/R2 已抽查，不能擴充成全文 FULL-PASS。當中的 XML 與原始 Table.stp 完整列尚有明確原件限制，已與本篇直接 BIN slice 分層。

## I. 本次獨立 BIN-first 附錄（每片完整原始 byte SHA256、VA/raw、Intel x86 asm）

本附錄重新直接取自已校驗的 `/mnt/data/Tartaros.bin`。小節 `VA [start,end)` 的位元組 SHA256 並非先前筆記 hash 的複製；可用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=... --stop-address=...` 重現。線性 objdump 在區段**首尾可能落在 caller 前一個指令尾端或資料**，因此只對已在前段 CFG 驗證／下列寫明的指令地址解讀，不將可疑邊界反組譯當肯定主張；函式的完整 side effects 必須參照對應原稿與 caller/consumer。

### N01 — NPC event→type2 QID selector與 controller(候選 ID,1) 的直接 call；C2S 分路需看相鄰 sender gate

- VA `[0x005B93FF,0x005B9452)`; raw `[0x1B87FF,0x1B8852)`; 83 bytes; SHA256 `8f32346ea3fb0cf7ceb038cc751536052f8925a2ea2d370290cdfc77fdcace0f`.

```asm
005b93ff <.data+0x1b87ff>:
  5b93ff:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  5b9402:	ba a0 b2 fa 00       	mov    edx,0xfab2a0
  5b9407:	e8 a4 74 f4 ff       	call   0x5008b0
  5b940c:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  5b9413:	0f b7 f8             	movzx  edi,ax
  5b9416:	75 27                	jne    0x5b943f
  5b9418:	b8 01 00 00 00       	mov    eax,0x1
  5b941d:	09 05 b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,eax
  5b9423:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  5b9426:	e8 45 6d fa ff       	call   0x560170
  5b942b:	68 10 d1 bc 00       	push   0xbcd110
  5b9430:	e8 e5 8e 2d 00       	call   0x89231a
  5b9435:	83 c4 04             	add    esp,0x4
  5b9438:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5b943f:	6a 01                	push   0x1
  5b9441:	57                   	push   edi
  5b9442:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  5b9447:	e8 14 83 fa ff       	call   0x561760
  5b944c:	83 3d 98 a7 fb 00  	cmp    DWORD PTR ds:0xfba798,0x0
```

### N02 — QuestOwner Demand gate：record demands vs prereq WORD list

- VA `[0x00500650,0x005006B4)`; raw `[0xFFA50,0xFFAB4)`; 100 bytes; SHA256 `bbedfcaeded121d970f4b6ee5cbf612ee4515129f5e59dc2be377bbdf95cdb21`.

```asm
00500650 <.data+0xffa50>:
  500650:	00 00                	add    BYTE PTR [eax],al
  500652:	8b 50 24             	mov    edx,DWORD PTR [eax+0x24]
  500655:	2b 50 20             	sub    edx,DWORD PTR [eax+0x20]
  500658:	33 ff                	xor    edi,edi
  50065a:	c1 fa 02             	sar    edx,0x2
  50065d:	85 d2                	test   edx,edx
  50065f:	74 4f                	je     0x5006b0
  500661:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  500664:	8b 8e b4 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eb4]
  50066a:	8b b6 b0 5e 00 00    	mov    esi,DWORD PTR [esi+0x5eb0]
  500670:	8b 40 20             	mov    eax,DWORD PTR [eax+0x20]
  500673:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  500677:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  50067b:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  50067f:	3b c1                	cmp    eax,ecx
  500681:	0f 84 f7 00 00 00    	je     0x50077e
  500687:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  50068b:	8b 36                	mov    esi,DWORD PTR [esi]
  50068d:	8d 49 00             	lea    ecx,[ecx+0x0]
  500690:	0f b7 18             	movzx  ebx,WORD PTR [eax]
  500693:	3b de                	cmp    ebx,esi
  500695:	74 07                	je     0x50069e
  500697:	83 c0 02             	add    eax,0x2
  50069a:	3b c1                	cmp    eax,ecx
  50069c:	75 f2                	jne    0x500690
  50069e:	3b c1                	cmp    eax,ecx
  5006a0:	0f 84 d8 00 00 00    	je     0x50077e
  5006a6:	83 44 24 18 04       	add    DWORD PTR [esp+0x18],0x4
  5006ab:	47                   	inc    edi
  5006ac:	3b fa                	cmp    edi,edx
  5006ae:	72 cb                	jb     0x50067b
  5006b0:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  5006b3:	8b             	mov    ecx,DWORD PTR [esp+0x10]
```

### N03 — 0x74 prerequisite writer / candidate rebuild

- VA `[0x00503400,0x00503432)`; raw `[0x102800,0x102832)`; 50 bytes; SHA256 `cf7ba5ab73d9e69346b714c15548280c18cad07818ee32cb5c99109e061e48a7`.

```asm
00503400 <.data+0x102800>:
  503400:	55                   	push   ebp
  503401:	8b ec                	mov    ebp,esp
  503403:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  503406:	56                   	push   esi
  503407:	8b f1                	mov    esi,ecx
  503409:	57                   	push   edi
  50340a:	83 c0 02             	add    eax,0x2
  50340d:	8d be b0 5e 00 00    	lea    edi,[esi+0x5eb0]
  503413:	e8 c8 80 f4 ff       	call   0x44b4e0
  503418:	e8 43 bc f0 ff       	call   0x40f060
  50341d:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  503423:	50                   	push   eax
  503424:	56                   	push   esi
  503425:	e8 16 ce ff ff       	call   0x500240
  50342a:	5f                   	pop    edi
  50342b:	33 c0                	xor    eax,eax
  50342d:	5e                   	pop    esi
  50342e:	5d                   	pop    ebp
  50342f:	c2 0c 00             	ret    0xc
```

### N04 — S2C 0x40 state0 F438B/QID event 原生 writer

- VA `[0x00502355,0x0050237C)`; raw `[0x101755,0x10177C)`; 39 bytes; SHA256 `7a0418e34a0d242acc5a4800973da02372bf7809817c0531bc28be981556f70e`.

```asm
00502355 <.data+0x101755>:
  502355:	0f b7 4b 02          	movzx  ecx,WORD PTR [ebx+0x2]
  502359:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  50235c:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  50235f:	89 78 0c             	mov    DWORD PTR [eax+0xc],edi
  502362:	c7 40 10 8b 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf438b
  502369:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50236f:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502372:	eb 02                	jmp    0x502376
  502374:	33 c0                	xor    eax,eax
  502376:	50                   	push   eax
  502377:	e8 d4 86 08 00       	call   0x58aa50
```

### N05 — 0x45 QuestRecord lookup 入口

- VA `[0x005027FB,0x00502831)`; raw `[0x101BFB,0x101C31)`; 54 bytes; SHA256 `22fe62a59fdf6fb1312ae69a5f6b7338c2803555a3024c52c235a108dbca3f2b`.

```asm
005027fb <.data+0x101bfb>:
  5027fb:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5027fe:	8b b1 ac 5e 00 00    	mov    esi,DWORD PTR [ecx+0x5eac]
  502804:	0f bf 78 02          	movsx  edi,WORD PTR [eax+0x2]
  502808:	8d 4d 90             	lea    ecx,[ebp-0x70]
  50280b:	51                   	push   ecx
  50280c:	8d 45 98             	lea    eax,[ebp-0x68]
  50280f:	8b ce                	mov    ecx,esi
  502811:	89 7d 90             	mov    DWORD PTR [ebp-0x70],edi
  502814:	e8 07 15 00 00       	call   0x503d20
  502819:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  50281c:	8b 5d 98             	mov    ebx,DWORD PTR [ebp-0x68]
  50281f:	3b de                	cmp    ebx,esi
  502821:	0f 84 f9 02 00 00    	je     0x502b20
  502827:	83 c3 10             	add    ebx,0x10
  50282a:	33 f6                	xor    esi,esi
  50282c:	3b de                	cmp    ebx,esi
  50282e:	0f 84 ec       	je     0x502b20
```

### N06 — 0x45 CompleteAction 分流到 scene controller

- VA `[0x00502878,0x0050289E)`; raw `[0x101C78,0x101C9E)`; 38 bytes; SHA256 `b380bc3a7f10c47f1116a8878a2aa0d4e6cbc352d23f787f0acfb3a963c03687`.

```asm
00502878 <.data+0x101c78>:
  502878:	a1 02 00 00 33       	mov    eax,ds:0x33000002
  50287d:	c0 50 e8 cc          	rcl    BYTE PTR [eax-0x18],0xcc
  502881:	81 08 00 e9 94 02    	or     DWORD PTR [eax],0x294e900
  502887:	00 00                	add    BYTE PTR [eax],al
  502889:	8b 53 48             	mov    edx,DWORD PTR [ebx+0x48]
  50288c:	52                   	push   edx
  50288d:	57                   	push   edi
  50288e:	e8 ad 06 f2 ff       	call   0x422f40
  502893:	8b c8                	mov    ecx,eax
  502895:	e8 c6 ee 05 00       	call   0x561760
  50289a:	bf 0f 00 00        	mov    edi,0xf
```

### N07 — 0x46 inbound state event+分流 gate

- VA `[0x00502BA2,0x00502BE9)`; raw `[0x101FA2,0x101FE9)`; 71 bytes; SHA256 `7e95994f6a2d80cf481cbe6d1b7bf01f4904d3aa2b057af3135e137d1b8fd89e`.

```asm
00502ba2 <.data+0x101fa2>:
  502ba2:	6a 18                	push   0x18
  502ba4:	e8 bf e6 38 00       	call   0x891268
  502ba9:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  502bac:	33 f6                	xor    esi,esi
  502bae:	83 c4 04             	add    esp,0x4
  502bb1:	3b c6                	cmp    eax,esi
  502bb3:	74 1f                	je     0x502bd4
  502bb5:	0f b7 4b 04          	movzx  ecx,WORD PTR [ebx+0x4]
  502bb9:	89 70 0c             	mov    DWORD PTR [eax+0xc],esi
  502bbc:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  502bbf:	89 78 08             	mov    DWORD PTR [eax+0x8],edi
  502bc2:	c7 40 10 82 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf4282
  502bc9:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  502bcf:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502bd2:	8b f0                	mov    esi,eax
  502bd4:	f6 05 d0 ad fa 00 01 	test   BYTE PTR ds:0xfaadd0,0x1
  502bdb:	75 23                	jne    0x502c00
  502bdd:	b8 01 00 00 00       	mov    eax,0x1
  502be2:	09 05 d0 ad fa 00    	or     DWORD PTR ds:0xfaadd0,eax
  502be8:	89               	mov    DWORD PTR [ebp-0x4],eax
```

### N08 — 0x46 state0 的 QuestOwner/exclusion/key gate

- VA `[0x00502D85,0x00502DCF)`; raw `[0x102185,0x1021CF)`; 74 bytes; SHA256 `44a1c3fee84fb35e98cb5ade2e432bcc93730d2484912344820a318752684f26`.

```asm
00502d85 <.data+0x102185>:
  502d85:	d1 bc 00 e8 8d f5 38 	sar    DWORD PTR [eax+eax*1+0x38f58de8],1
  502d8c:	00 83 c4 04 c7 45    	add    BYTE PTR [ebx+0x45c704c4],al
  502d92:	fc                   	cld
  502d93:	ff                   	(bad)
  502d94:	ff                   	(bad)
  502d95:	ff                   	(bad)
  502d96:	ff 6a 00             	jmp    FWORD PTR [edx+0x0]
  502d99:	68 58 73 fb 00       	push   0xfb7358
  502d9e:	b8 02 00 00 00       	mov    eax,0x2
  502da3:	8b ce                	mov    ecx,esi
  502da5:	e8 36 09 05 00       	call   0x5536e0
  502daa:	0f bf 73 02          	movsx  esi,WORD PTR [ebx+0x2]
  502dae:	8b 55 d8             	mov    edx,DWORD PTR [ebp-0x28]
  502db1:	e8 1a d3 ff ff       	call   0x5000d0
  502db6:	85 ff                	test   edi,edi
  502db8:	74 1e                	je     0x502dd8
  502dba:	83 7f 08 03          	cmp    DWORD PTR [edi+0x8],0x3
  502dbe:	74 18                	je     0x502dd8
  502dc0:	0f b7 43 02          	movzx  eax,WORD PTR [ebx+0x2]
  502dc4:	8b 7d d8             	mov    edi,DWORD PTR [ebp-0x28]
  502dc7:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  502dca:	81 c7 b0 5e 00     	add    edi,0x5eb0
```

### N09 — 0x47 兩個 signed WORD → singleton scene controller

- VA `[0x00503095,0x005030AC)`; raw `[0x102495,0x1024AC)`; 23 bytes; SHA256 `1491333b97446bef9357e87539cc6115d06abdce6d1a036f27308a279b997061`.

```asm
00503095 <.data+0x102495>:
  503095:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  503098:	0f bf 48 04          	movsx  ecx,WORD PTR [eax+0x4]
  50309c:	0f bf 50 02          	movsx  edx,WORD PTR [eax+0x2]
  5030a0:	51                   	push   ecx
  5030a1:	52                   	push   edx
  5030a2:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  5030a7:	e8 b4 e6 05 00       	call   0x561760
```

### N10 — scene singleton accessor return=this (不是 pair 轉換)

- VA `[0x00422F8E,0x00422F9F)`; raw `[0x2238E,0x2239F)`; 17 bytes; SHA256 `aa711e331d916b324f5c4968af328426ba8dabf6a26787db50ec64b2e77c9e18`.

```asm
00422f8e <.data+0x2238e>:
  422f8e:	b8 c0 73 fb 00       	mov    eax,0xfb73c0
  422f93:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  422f96:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  422f9d:	59                   	pop    ecx
  422f9e:	8b                 	mov    esp,ebp
```

### N11 — C2S 0x36 independent producer / sender gate

- VA `[0x004B3534,0x004B3569)`; raw `[0xB2934,0xB2969)`; 53 bytes; SHA256 `1359f8fa22a7468571ac0048ed1bc347f88ca74864bb76076972524d1a35e5b6`.

```asm
004b3534 <.data+0xb2934>:
  4b3534:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4b353b:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b353e:	66 8b 51 02          	mov    dx,WORD PTR [ecx+0x2]
  4b3542:	b8 36 00 00 00       	mov    eax,0x36
  4b3547:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  4b354b:	66 89 55 fe          	mov    WORD PTR [ebp-0x2],dx
  4b354f:	75 15                	jne    0x4b3566
  4b3551:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4b3557:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b3559:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4b355c:	6a 04                	push   0x4
  4b355e:	8d 55 fc             	lea    edx,[ebp-0x4]
  4b3561:	52                   	push   edx
  4b3562:	6a 00                	push   0x0
  4b3564:	ff d0                	call   eax
  4b3566:	33 c0                	xor    eax,eax
  4b3568:	8b                 	mov    esp,ebp
```

### N12 — TalkBox mode1 F4402 action限定，不可套 mode2

- VA `[0x00636DF8,0x00636E10)`; raw `[0x2361F8,0x236210)`; 24 bytes; SHA256 `e59ee6c3c43284f11560d91838899f1121027750acfcc631ef033c5aa4022437`.

```asm
00636df8 <.data+0x2361f8>:
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
```

### N13 — scene controller local key writer(+38/+3C)與 active

- VA `[0x005618D7,0x005618F4)`; raw `[0x160CD7,0x160CF4)`; 29 bytes; SHA256 `0176f0d97009877d7834c06a883ef2a98165f66f0c8ebe55c7f319735c86a027`.

```asm
005618d7 <.data+0x160cd7>:
  5618d7:	be 01 00 00 00       	mov    esi,0x1
  5618dc:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  5618e3:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  5618e6:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5618e9:	89 53 38             	mov    DWORD PTR [ebx+0x38],edx
  5618ec:	89 43 3c             	mov    DWORD PTR [ebx+0x3c],eax
  5618ef:	89 73 28             	mov    DWORD PTR [ebx+0x28],esi
  5618f2:	75 24                	jne    0x561918
```

### N14 — controller scene-NEXT 查 Table successor、nonzero才重入

- VA `[0x00561ED1,0x00561EF7)`; raw `[0x1612D1,0x1612F7)`; 38 bytes; SHA256 `89e6aa6af1aedf9a92f17066900c0120c1e44466b14b0285f70a22cc83e11d23`.

```asm
00561ed1 <.data+0x1612d1>:
  561ed1:	8b 47 3c             	mov    eax,DWORD PTR [edi+0x3c]
  561ed4:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  561ed7:	50                   	push   eax
  561ed8:	51                   	push   ecx
  561ed9:	68 68 0f fc 00       	push   0xfc0f68
  561ede:	e8 5d c7 f1 ff       	call   0x47e640
  561ee3:	33 db                	xor    ebx,ebx
  561ee5:	89 47 3c             	mov    DWORD PTR [edi+0x3c],eax
  561ee8:	3b c3                	cmp    eax,ebx
  561eea:	74 1f                	je     0x561f0b
  561eec:	8b 57 38             	mov    edx,DWORD PTR [edi+0x38]
  561eef:	50                   	push   eax
  561ef0:	52                   	push   edx
  561ef1:	8b f7                	mov    esi,edi
  561ef3:	e8 28 38 00        	call   0x565720
```

### N15 — scene lookup入口 conditional key writer

- VA `[0x0056577D,0x00565795)`; raw `[0x164B7D,0x164B95)`; 24 bytes; SHA256 `7af43c25ba83264dd7897554c784f4f61c7b7db61baea5fa753bbe53582182ac`.

```asm
0056577d <.data+0x164b7d>:
  56577d:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  565780:	bb 01 00 00 00       	mov    ebx,0x1
  565785:	89 56 38             	mov    DWORD PTR [esi+0x38],edx
  565788:	89 46 3c             	mov    DWORD PTR [esi+0x3c],eax
  56578b:	89 5e 28             	mov    DWORD PTR [esi+0x28],ebx
  56578e:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  565794:	75                 	jne    0x5657bf
```

### N16 — Table Chapter FIRST reader進入函式

- VA `[0x0047E890,0x0047E8E8)`; raw `[0x7DC90,0x7DCE8)`; 88 bytes; SHA256 `b50ec468b6038bf5d8973e63d0aa1c854bab54322ef2256d449b687dda1b474f`.

```asm
0047e890 <.data+0x7dc90>:
  47e890:	55                   	push   ebp
  47e891:	8b ec                	mov    ebp,esp
  47e893:	6a ff                	push   0xffffffff
  47e895:	68 b8 8a 90 00       	push   0x908ab8
  47e89a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47e8a0:	50                   	push   eax
  47e8a1:	83 ec 14             	sub    esp,0x14
  47e8a4:	53                   	push   ebx
  47e8a5:	56                   	push   esi
  47e8a6:	57                   	push   edi
  47e8a7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47e8ac:	33 c5                	xor    eax,ebp
  47e8ae:	50                   	push   eax
  47e8af:	8d 45 f4             	lea    eax,[ebp-0xc]
  47e8b2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47e8b8:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e8bb:	8b 58 04             	mov    ebx,DWORD PTR [eax+0x4]
  47e8be:	8b 33                	mov    esi,DWORD PTR [ebx]
  47e8c0:	3b f3                	cmp    esi,ebx
  47e8c2:	74 67                	je     0x47e92b
  47e8c4:	8b 7e 10             	mov    edi,DWORD PTR [esi+0x10]
  47e8c7:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  47e8ca:	51                   	push   ecx
  47e8cb:	8d 4f 34             	lea    ecx,[edi+0x34]
  47e8ce:	8d 45 08             	lea    eax,[ebp+0x8]
  47e8d1:	e8 fa e5 0a 00       	call   0x52ced0
  47e8d6:	8b 7f 38             	mov    edi,DWORD PTR [edi+0x38]
  47e8d9:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e8dc:	3b c7                	cmp    eax,edi
  47e8de:	75 61                	jne    0x47e941
  47e8e0:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  47e8e4:	75 41                	jne    0x47e927
  47e8e6:	8b 46              	mov    eax,DWORD PTR [esi+0x8]
```

### N17 — Table Chapter NEXT reader入參/非零 gate

- VA `[0x0047E640,0x0047E68A)`; raw `[0x7DA40,0x7DA8A)`; 74 bytes; SHA256 `d61cc0b5948dc78deefdf189ae0bbe74752eec6de574ee8adc2ddcbf77f83428`.

```asm
0047e640 <.data+0x7da40>:
  47e640:	55                   	push   ebp
  47e641:	8b ec                	mov    ebp,esp
  47e643:	6a ff                	push   0xffffffff
  47e645:	68 b8 8a 90 00       	push   0x908ab8
  47e64a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47e650:	50                   	push   eax
  47e651:	83 ec 14             	sub    esp,0x14
  47e654:	53                   	push   ebx
  47e655:	56                   	push   esi
  47e656:	57                   	push   edi
  47e657:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47e65c:	33 c5                	xor    eax,ebp
  47e65e:	50                   	push   eax
  47e65f:	8d 45 f4             	lea    eax,[ebp-0xc]
  47e662:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47e668:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  47e66b:	83 7d 0c 00          	cmp    DWORD PTR [ebp+0xc],0x0
  47e66f:	0f 84 86 00 00 00    	je     0x47e6fb
  47e675:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e678:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  47e67b:	8b 07                	mov    eax,DWORD PTR [edi]
  47e67d:	89 45 10             	mov    DWORD PTR [ebp+0x10],eax
  47e680:	3b c7                	cmp    eax,edi
  47e682:	74 77                	je     0x47e6fb
  47e684:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  47e687:	8d 4d 0c             	lea    ecx,[ebp+0xc]
```

### N18 — scene object key經 FIRST 前段（調用/分派）

- VA `[0x0047D575,0x0047D5A0)`; raw `[0x7C975,0x7C9A0)`; 43 bytes; SHA256 `f1e99d0922585a8f3b1e6378fedceeb21beccf1e9654e7297985e5f786a6f140`.

```asm
0047d575 <.data+0x7c975>:
  47d575:	84 05 64 0f fc 00    	test   BYTE PTR ds:0xfc0f64,al
  47d57b:	75 26                	jne    0x47d5a3
  47d57d:	09 05 64 0f fc 00    	or     DWORD PTR ds:0xfc0f64,eax
  47d583:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47d58a:	e8 51 07 00 00       	call   0x47dce0
  47d58f:	68 f0 da bc 00       	push   0xbcdaf0
  47d594:	e8 81 4d 41 00       	call   0x89231a
  47d599:	83 c4 04             	add    esp,0x4
  47d59c:	c7 45 fc ff    	mov    DWORD PTR [ebp-0x4],0xffffffff
```

### N19 — S2C 0x40 accept action2 downstream controller producer

- VA `[0x00502420,0x0050244C)`; raw `[0x101820,0x10184C)`; 44 bytes; SHA256 `aa7dff2120d3a46d0ae1f5d64b662b9128e69c5d87eae981bc4e18b1a4187b9c`.

```asm
00502420 <.data+0x101820>:
  502420:	00 89 48 14 e8 27    	add    BYTE PTR [ecx+0x27e81448],cl
  502426:	86 08                	xchg   BYTE PTR [eax],cl
  502428:	00 e9                	add    cl,ch
  50242a:	7b 03                	jnp    0x50242f
  50242c:	00 00                	add    BYTE PTR [eax],al
  50242e:	33 c0                	xor    eax,eax
  502430:	50                   	push   eax
  502431:	e8 1a 86 08 00       	call   0x58aa50
  502436:	e9 6e 03 00 00       	jmp    0x5027a9
  50243b:	8b 4b 40             	mov    ecx,DWORD PTR [ebx+0x40]
  50243e:	51                   	push   ecx
  50243f:	57                   	push   edi
  502440:	e8 fb 0a f2 ff       	call   0x422f40
  502445:	8b c8                	mov    ecx,eax
  502447:	e8 14 f3 05 00       	call   0x561760
```

### N20 — S2C 0x45 完成 action2 downstream controller producer

- VA `[0x0050283F,0x0050289E)`; raw `[0x101C3F,0x101C9E)`; 95 bytes; SHA256 `780337f4381ce2743c04e146bb4145a5cc7f93397239e6a075aabce7b781f41e`.

```asm
0050283f <.data+0x101c3f>:
  50283f:	e8 7c 2c f0 ff       	call   0x4054c0
  502844:	6a 18                	push   0x18
  502846:	e8 1d ea 38 00       	call   0x891268
  50284b:	83 c4 04             	add    esp,0x4
  50284e:	3b c6                	cmp    eax,esi
  502850:	74 2a                	je     0x50287c
  502852:	8b 4b 40             	mov    ecx,DWORD PTR [ebx+0x40]
  502855:	83 ca ff             	or     edx,0xffffffff
  502858:	50                   	push   eax
  502859:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  50285c:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  50285f:	89 70 0c             	mov    DWORD PTR [eax+0xc],esi
  502862:	c7 40 10 06 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf4306
  502869:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50286f:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502872:	e8 d9 81 08 00       	call   0x58aa50
  502877:	e9 a1 02 00 00       	jmp    0x502b1d
  50287c:	33 c0                	xor    eax,eax
  50287e:	50                   	push   eax
  50287f:	e8 cc 81 08 00       	call   0x58aa50
  502884:	e9 94 02 00 00       	jmp    0x502b1d
  502889:	8b 53 48             	mov    edx,DWORD PTR [ebx+0x48]
  50288c:	52                   	push   edx
  50288d:	57                   	push   edi
  50288e:	e8 ad 06 f2 ff       	call   0x422f40
  502893:	8b c8                	mov    ecx,eax
  502895:	e8 c6 ee 05 00       	call   0x561760
  50289a:	bf 0f 00 00        	mov    edi,0xf
```

### N21 — S2C mode2 TalkBox consumer 進入函式

- VA `[0x005B6D20,0x005B6D7C)`; raw `[0x1B6120,0x1B617C)`; 92 bytes; SHA256 `7ae65ab11a7dec55b236e065f561781050f260dff964ac9ea306e71d159c81f8`.

```asm
005b6d20 <.data+0x1b6120>:
  5b6d20:	55                   	push   ebp
  5b6d21:	8b ec                	mov    ebp,esp
  5b6d23:	83 e4 f8             	and    esp,0xfffffff8
  5b6d26:	6a ff                	push   0xffffffff
  5b6d28:	68 2c 93 94 00       	push   0x94932c
  5b6d2d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b6d33:	50                   	push   eax
  5b6d34:	83 ec 10             	sub    esp,0x10
  5b6d37:	53                   	push   ebx
  5b6d38:	56                   	push   esi
  5b6d39:	57                   	push   edi
  5b6d3a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b6d3f:	33 c4                	xor    eax,esp
  5b6d41:	50                   	push   eax
  5b6d42:	8d 44 24 20          	lea    eax,[esp+0x20]
  5b6d46:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5b6d4c:	8b f1                	mov    esi,ecx
  5b6d4e:	8b fa                	mov    edi,edx
  5b6d50:	85 f6                	test   esi,esi
  5b6d52:	74 26                	je     0x5b6d7a
  5b6d54:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6d56:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6d59:	ff d2                	call   edx
  5b6d5b:	3d b9 05 01 00       	cmp    eax,0x105b9
  5b6d60:	75 04                	jne    0x5b6d66
  5b6d62:	8b de                	mov    ebx,esi
  5b6d64:	eb 16                	jmp    0x5b6d7c
  5b6d66:	6a 00                	push   0x0
  5b6d68:	68 c0 1f bf 00       	push   0xbf1fc0
  5b6d6d:	68 18 21 bf 00       	push   0xbf2118
  5b6d72:	6a 00                	push   0x0
  5b6d74:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6d7a:	33 db                	xor    ebx,ebx
```

### N22 — S2C mode3 TalkBox consumer 進入函式

- VA `[0x005B6E60,0x005B6EAD)`; raw `[0x1B6260,0x1B62AD)`; 77 bytes; SHA256 `aa55394430fd1917caf77b1fffee71a4990974fec6ce87f56544fdbeae67772c`.

```asm
005b6e60 <.data+0x1b6260>:
  5b6e60:	55                   	push   ebp
  5b6e61:	8b ec                	mov    ebp,esp
  5b6e63:	83 e4 f8             	and    esp,0xfffffff8
  5b6e66:	6a ff                	push   0xffffffff
  5b6e68:	68 2c 93 94 00       	push   0x94932c
  5b6e6d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b6e73:	50                   	push   eax
  5b6e74:	83 ec 10             	sub    esp,0x10
  5b6e77:	53                   	push   ebx
  5b6e78:	56                   	push   esi
  5b6e79:	57                   	push   edi
  5b6e7a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b6e7f:	33 c4                	xor    eax,esp
  5b6e81:	50                   	push   eax
  5b6e82:	8d 44 24 20          	lea    eax,[esp+0x20]
  5b6e86:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5b6e8c:	8b f1                	mov    esi,ecx
  5b6e8e:	8b fa                	mov    edi,edx
  5b6e90:	85 f6                	test   esi,esi
  5b6e92:	74 26                	je     0x5b6eba
  5b6e94:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6e96:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6e99:	ff d2                	call   edx
  5b6e9b:	3d b9 05 01 00       	cmp    eax,0x105b9
  5b6ea0:	75 04                	jne    0x5b6ea6
  5b6ea2:	8b de                	mov    ebx,esi
  5b6ea4:	eb 16                	jmp    0x5b6ebc
  5b6ea6:	6a 00                	push   0x0
  5b6ea8:	68 c0 1f bf 00       	push   0xbf1fc0
```

### N23 — QuestInfo XML Demand parser/value conversion 對應

- VA `[0x00504C72,0x00504C9C)`; raw `[0x104072,0x10409C)`; 42 bytes; SHA256 `415ff3ffad5d57e3d10ac969a93bcb876f1c9f84d49e92767b79386ec59c7a06`.

```asm
00504c72 <.data+0x104072>:
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
  504c99:	8d 44 24           	lea    eax,[esp+0x74]
```

### N24 — QuestInfo XML reward type2 mapping/type gate

- VA `[0x00504D90,0x00504E07)`; raw `[0x104190,0x104207)`; 119 bytes; SHA256 `93d4f94d3208cabded95a02e61756ab893d18f20daacb5d90a5f632fd2acf468`.

```asm
00504d90 <.data+0x104190>:
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
  504e06:	89       	mov    DWORD PTR [esp+0xf0],eax
```

## J. 原始 Event.stp（XOR-FF）獨立字串交叉核對

本次對 Event.stp **raw bytes 逐 byte XOR FF token 檢索**，以下為來源位置，而非 GitHub 二手摘錄；這只驗證 Scene3 的 Lua 原文存在，**不驗證其已被 runtime 選中、Script loader 一定成功**。

| token | raw file offset | 驗證方式 |
|---|---:|---|
| `town001D.map` | `0x8C1CF2` (9182450) | raw encoded token `byte ^ 0xFF` |
| `OpenTalkScene(3, 18)` | `0x8C1F03` (9182979) | raw encoded token `byte ^ 0xFF` |
| `OpenTalkScene(3, 24)` | `0x8C1FE8` (9183208) | raw encoded token `byte ^ 0xFF` |
| `OpenTalkScene(3, 20)` | `0x8C2037` (9183287) | raw encoded token `byte ^ 0xFF` |
| `OpenTalkScene(3, 21)` | `0x8C2098` (9183384) | raw encoded token `byte ^ 0xFF` |
| `DoProlog(1)` | `0x8C21C9` (9183689) | raw encoded token `byte ^ 0xFF` |
| `RestoreMap()` | `0x8C2235` (9183797) | raw encoded token `byte ^ 0xFF` |
| `pindos_talkevent` | `0x8C1C61` (9182305) | raw encoded token `byte ^ 0xFF` |

Scene3 註解 `-- Quest #15 / Scene #3` raw offset `0x8C1C3E`。`Table.stp` 尾部可觀察到 XOR-FF 編碼的檔名 `QuestInfo.xml`、`SceneList.xml`，**檔名索引不等於其 XML records 已完整解包**。因此不能以這些 token 的存在填造 Quest15 action parameter 或 Chapter order。

## K. 研究結案判定與遠端提交／後續步驟

### T16-135 本段達標判定

**Client E2E 條件式整合契約：BOUNDED COMPLETE**。本篇完成：玩家 P0–P8 情境、10+ 業務 application 方向／欄位／gate、本地 prerequisite/exclusion/selector/record/action、NPC event→candidate/controller/sender、Quest16 mode2／Quest15 mode2+mode3、0x45/0x40/0x47/Chapter FIRST/NEXT 的獨立 scene key、Scene3 Lua/RestoreMap、Server 需求候選、32 組正反測試、24 段獨立 BIN slice、Event 原始 token 溯源，以及四分類精確未知/解除條件。它不是「Client 真實在線一條路跑完」或「Server 已開發」的宣告。

### 尚未達成、不可偷渡的更大目標

- T16 整體 `native_complete=false`、Quest15 原始 CompleteAction/SceneList ordered row 仍待精確原始資料；若使用者日後要求證明「Quest15 完成必播 Scene3」，需要先有 resource rows/確切 original trigger/實際運行或封包配對。**此次交付不會把此尚未證明的命題標成完成**。
- **下一步優先順序建議**：(1) 依 Table.stp 原件專查 QuestInfo/SceneList 行與 action type/param，（2）由 T16/T07 對 controller `0x6EDB60` busy/deferred、Lua Prolog/RestoreMap 回調補證，（3）S00 正式收取 Quest Server 需求候選、依已證 Client 欄位立 SPEC/GAP/TEST，（4）相容 Server 接入原版 Client 後跑逐階段實測與重登一致性。
- 未因本稿改動 `task.json`、S00 RR/REQ、其他 Task 或 FULL-PASS；完整 Markdown 存在於 T16 原稿目錄，提交前再次確認遠端 HEAD 和同名路徑，**只有實際收到 GitHub commit/blob 回報後才能聲稱已上傳**。

