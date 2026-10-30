# T16-117 — Quest14／⑤：Quest14 key14 更新後 Quest16 type2 可接候選、NPC/UI 狀態與下一次 C→S／S→C（KR BIN-first）

- 研究者：`chatgpt-web roy`，Asia/Taipei `2026-10-30T03:45:17+08:00`。
- 任務主責：KR T16；本次僅 **Quest14-⑤**：完成 Quest14 之後，Client 如何判斷 Quest16 的 prerequisite、如何出現在任務候選、實際哪個 UI 讀取 type2、如何依玩家動作產生 Quest16 相關 C→S、可能接收哪些 QuestOwner 回覆。**不含原版 Server 成功／領獎／解鎖演算法**。
- 原始 KR `Tartaros.bin`：12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；原始 `Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。`Event.stp` SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。全部原件唯讀，沒有執行遊戲或 patch。
- 原始 BIN PE `.text` VA 0x401000／raw 0x400；`.text` `raw=VA-0x400C00`，以下全部 VA 標示；字串／data 在其他 section 必須另換算；`objdump` 單純 bytes 反組譯，非具有 symbols 的原始 source。
- 開工 GitHub `main=fb70e1325069c2069b428cf01ab57b4a4d7319c2`，T16 `t16/roy/chatgpt-web=3926c374a413fd0a9b1905bd055415bb74839fc2`，compare **behind=0、ahead=2**，新正式分析前 **已包含最新 main**；未觸發額外 Merge。已查 `AGENTS.md`、`kr/tasks/T16/{README.md,task.json}`、`research/dispatch/{README.md,inbox/T16.md}`、`research/requests/index.json`、`shared/verified-knowledge/README.md`；T16 inbox 無 RR，使用者當次指定 Quest14-⑤；歷史 T01 待審事項本次不擅改/標 RESOLVED。T01 FULL-PASS 只存在於已核准之子主張；此研究新主張未由 T01 FULL-PASS。
- **GitHub 授權：沒有要求 Commit/Push；本次僅產生本地 Markdown，不更動 `main`、T16 分支、RR、S00。** 正式段號承接上一筆遠端完整 T16-116，為 T16-117；沒有用「Quest14-5」取代正式段號。

## A. 本次核心結論：Quest16 type2 真正的候選消費路徑，及對 T16-116 的勘誤

**重大新發現：** 先前 T16-116 把 `0x500240 → 0x500950 / 0x500E00 → 0x635CA0` 作為候選 UI 的一般下游；但本輪原始 BIN 確認 `0x500950` 明確比較 `QuestRecord+4 == 1`，**Quest16 XML 為 `type=2`，所以 Quest16 不能由 `0x500950` 的 type1 pointer vector 輸出**。同時 `0x500E00` 有 `record+4==2` 的跳過分支（T16-100、T16-116），故也**不能在缺少額外條件的情況，把 `0x635CA0` 的兩個 flags 當成 Quest16 立即顯示的證據**。這是對既有 UI 解讀的限定勘誤，不刪除 T16-116 其他已驗證的 `0x74→key14→Demand14` 結論。

本輪從同一份 BIN 定位到 **`0x500A00`**：它也遍歷 `QuestOwner+0x5EC0..+0x5EC4` 的候選 WORD keys，但 **`0x500A58 cmp dword [record+4], 2`**，配合 `record+0x28 == selector`，把符合條件的 **type2** QuestRecord 指標放入 caller output vector。`0x5008B0` 經 `0x500A00`，在 type2 列表非空時取第一項 WORD ID；`0x500A80` 在特定執行期狀態 selector 下亦調 `0x500A00` 並把結果納入回傳數值分類，且真正被 `0x4D2422`、`0x5400A6`、`0x544162`、`0x56D09A` 的操作／狀態控制者消費。`0x5B9407` 在 `0x105BF`/action `0x6A7` event 路徑也用 `0x5008B0`，證明 type2 候選具 native UI/互動 read 端，**但事件中的個別 QuestID 與是否為 NPC10027／Quest16 尚未由本段定位為固定值**。

### A.1 五節點 Client 原生因果鏈

```text
QuestInfo.xml Quest14 ID14 / Quest16 ID16 type2 Demand ID14, town0, giver10027
  ↓ (本地原生 loader 已於 T16-112 證實)
QuestOwner callback index116 / S→C decoded 0x74,key14 (T16-116)
  0x494440 → 0x4FDA30 → 0x503400 → 0x44B4E0
  QuestOwner+5EB0..5EB4 prerequisite WORD key membership (含14)
  ↓
0x500240 重新建 QuestOwner+5EC0..5EC4 候選 ID
  已核驗：record selector match、level bound、20項 exclusion、Demand membership，皆須成立
  Quest16 Demand14 可以因 key14 由 miss → pass；其他 gate 不可略過
  ↓
**TYPE2** 0x500A00 (新確認)；不是 0x500950 type1
  record+0x28 == selector AND record+4 == 2 才加入 pointer vector
  ↓
0x5008B0 → 在 type2 結果中取首個候選 WORD ID (0代表沒有)
0x500A80 → 特定執行期 mode 下調 0x500A00，轉成分類結果
  ↓
caller 0x5B9407 的事件分支、0x4D2422 / 0x5400A6 / 0x544162 / 0x56D09A
  ↓
若另有 QuestEvent(type 0x105B9) 傳入 QuestID16：0x5B6C0C/0x5B6D4C/0x5B6E8C
  → QuestInfo map hit → TalkBox 選取 record+0x88 → event 0x6A7 → 0x636E10
  → C→S app payload [0x0036, 0x0010] = 36 00 10 00 (T16-114 native path)
```

**注意粗體條件**：上述最後的「若另有 type0x105B9 event 帶 QuestID16」屬**條件式可達 Client 行為**，不能用 type2 候選存在直接推斷已經真的按下 Quest16／出現 NPC10027／Server 必然接受。`0x500A80` 的數值分類不等於 Server accept 狀態碼，且 UI 依事件再執行 consumer，非 `0x74` callback 自動重繪。

## B. 第一輪 — 驗證 Quest14 → Quest16 最小 prerequisite 與完整候選 gate

### B.1 第一手資源的精確意義

本次直接復核 T16-112 從原始 KR `Table/QuestInfo.xml` 所提取的條目（GitHub main `kr/evidence/5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60.txt`）：

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
</Quest>
```

`Demand14` 是**靜態宣告**；`QuestOwner+5EB0` 是**執行期 prerequisite-key 集合**。前者如何被後者滿足由 `0x500240` 原生讀者直接核實，但不把「收到 key14」偷換成原版 Server 認可完成的具體時刻。

### B.2 0x500240 內部必要判斷（BIN）

- `0x50026F..0x50029B` 先清候選 `owner+0x5EC0/+0x5EC4` 有效 end；這是重建不是直接 UI push。
- `0x500317..0x500346` 走 QuestInfo map tree iterator，並取得本地上下文與 level 等門檻資料；不可由 XML 的 town=0 單獨推導世界/場景已載入。
- `0x500485..0x50048B`：由目前迭代記錄讀 `+0x20` 並與函式第二參數 selector 比對；不相符 `jne 0x50054A`，跳過。
- `0x500491..0x500498`：記錄 `+0x0C` 和當前推得的 level bound 比較，超出 `jg 0x50054A`，跳過。
- `0x50049E..0x5004BC`：遍歷 `owner+0x5ED0` 的 20 個 WORD exclusion keys，若與候選相同，跳過。這份 exclusion 不是 `owner+0x5EB0` 的 prerequisite set。
- `0x500631..0x500652`：以候選 key 查 QuestInfo map，確認非 sentinel，再取 demands 4-byte array 的 begin/end（具體 iterator/record 基準以附錄完整 ASM 為準；勿將 node+0x20 與 payload+0x20 混寫）。
- `0x50065D..0x5006B0`：遍歷每個 demanded DWORD ID，對 `owner+0x5EB0..+0x5EB4` WORD keys 比對；缺任何一筆 `je 0x50077E` skip。
- `0x5006B0..0x50077A`：只有全部 gates 成立才將候選 ID（WORD）push 進 `owner+0x5EC0..+0x5EC4`。

**限定測試結論**：其他 selector/level/exclusion 等 gates 都固定為合格、候選 Quest16 在 QuestInfo map 且未被其他狀態排除時：

- 不含 key14 → Quest16 的唯一 Demands 不滿足，不能進 candidate。
- 有 key14 → Demand14 **這一關**成立，若上述其餘條件同時通過，Quest16 可以進 candidate。
- 再收到 `0x72` reset 或 `0x6F` snapshot 若使 key14 不存在，便依已確認的更新後資料重新運算；不能稱 `0x74` key14 必然永久保存。

**證據邊界**：record+0x20 (iterated record) 與需求 array（`0x500652` 的 map lookup node+0x20）基底不同，不能盲目以相同 offset 合併；本輪確實核對原生指標生命週期而非引用舊摘要。

## C. 第二輪 — type2 真正 consumer：0x500A00 / 0x5008B0 / 0x500A80

### C.1 原生 `0x500950` vs `0x500A00` 型別篩選（重要修正）

- `0x500950`: `0x5009A0 movzx eax,word[ebx]` → `0x503D20` 查 QuestInfo node → `0x5009D3 cmp [eax+0x28],selector` → `0x5009D8 cmp dword [eax+4],1` → `0x443D10` 指標 push。
- `0x500A00`: 同樣使用 `owner+0x5EC0..+0x5EC4` 的 WORD keys；`0x500A53 cmp [eax+0x28],selector` → `0x500A58 cmp dword [eax+4],2` → `0x500A64 call 0x443D10`。
- 類型值來自 QuestInfo (`type=2` 對 Quest16)，**故目前 type2 才是 Quest16 正確的已證 Client 候選讀端**。T16-116 `0x635CA0` 雖然是 UI 真讀者，但因其 `0x500950` type1/`0x500E00` 排除type2，**不能直接作為 Quest16 type2 項目已顯示的證據**。保留 T16-116 的 S2C Quest key writer、candidate rebuild 與 Demand14 判定；僅修正/UI 路徑的類型推論。

### C.2 0x5008B0 → type2 ID 第一筆

- `0x5008F3 call 0x500A00`，然後 `0x5008F8..0x500909` 比對候選 begin/end，空時返回 0；非空 `0x500922..0x500930` 讀第一個 QuestRecord 的 `WORD [record+0]` 回傳。這是具體 **type2 候選 ID consumer**。
- `0x5B9407` 的真實 caller 將 QuestOwner 常量 `0xFAB2A0`、事件欄位 `[esi+0x14]` 送給 `0x5008B0`；此路徑判斷 action `0x6A7` / 事件 type `0x105BF`，並透過 `0x561760` 將候選 ID 送入另一個 Client 控制器。這是 type2 與玩家互動路徑的關聯，**但不等於必然 Quest16，因未證 `[esi+0x14]` 何時對應 NPC10027 的 selector**。

### C.3 0x500A80 → type2 狀態分類被其他 Client 模組實際使用

- `0x500ACB` 先取 `0x500950` type1，然後檢查 20-slot `owner+0x5ED0` 與 `0x500160` 結果。
- `0x500B20..0x500B5F` 當全域 `[0xF9392C]` 等於 `1,3,7,0x17,0x18` 其中之一時，另外呼叫 `0x500A00` type2；由是否空集合影響局部 decision fields，而非直接將結果發往 socket。
- `0x500C82..0x500D40` 根據不同記錄類型和條件回傳多種數字（已見 2,4,5 等）；**這是 Client 分流值，不能命名為「Quest16 已接受／可交付」而無進一步 vtable 和 UI 字串核對**。
- 原生確定四個 `0x500A80` caller：`0x4D2422`、`0x5400A6`、`0x544162`、`0x56D09A`；它們皆讀取返回整數並用分支/跳表進行不同後續，故不是 dead code。

## D. 第三輪 — Quest16 互動後 C→S 和候選 S→C；不能把不同封包混淆

### D.1 已證 `0x36 + QuestID16` （條件式，TalkBox 選中時）

T16-114 已證 `0x5B6C0C` (mode1)、`0x5B6D4C` (mode2)、`0x5B6E8C` (mode3)：三者都要求 event type `0x105B9` 且 `event+0x14` 為 QuestInfo map 存在的 key，傳給 `0x636520`。mode1/2/3 更新 `TalkBox+0x88` 選擇 record；`0x636DE0/0x636E10` 僅在 local event `0xF4402`, type `0x105BD`, action `0x6A7`、selected record非空、全域 `[0xFBA798]==0` 時才以 `CIocpNetwork` key0 vtable+0x10 建立 **`0x36,QID16`** 4-byte 業務 payload。

```text
when selectedQuest == QuestInfo.id 16 and correct TalkBox action/gates:
36 00 10 00       // [LE u16 command=0x36, LE u16 questID=16]
```

**這不是「玩家必定看得到／必定接受 Quest16」的直接證據**，也未見送出的 4 bytes 有 mode/accept/turnin 欄位。原版 Server 如何判定 accepted/completed/turn-in、拒絕/獎勵由 S00 規劃 ADR。實際 queue→framer→WSASend 的有界傳輸參見 T16-107/114；不是未經 T02 framing 的裸 TCP bytes。

### D.2 新確認的鄰近互動事件 `0x1C` 六位元組，不可誤當 Quest16 accept

在與 type2 候選 `0x5008B0` 同一 `0x5B93xx` caller 中，`0x5B944C..0x5B9485` 建立 C→S：

```text
1C 00 <u16 event+0x18> <u16 event+0x1C>   // 6-byte application payload
```

- event gate `action=0x6A7`、`type=0x105BF`，全域 sender gate `[0xFBA798]==0`，network key0。
- `0x5008B0` 回傳的 type2 first candidate ID 存入 `EDI` 並用於 `0x561760`；**`0x1C` 的兩個 WORD 來源是 event+0x18 / event+0x1C，並非直接把 candidate ID 寫入封包**。
- 因此 `0x1C` 雖鄰近 type2 候選與玩家操作，不能稱「Quest16 接取封包」；`0x36 00 10 00` 才是已在 TalkBox QuestInfo 路徑有條件證明的 QID16 message。

### D.3 新複驗 QuestOwner S→C index64 (`0x40`) 帶有任務事件分支，但不是已證 `0x36` 回覆

- QuestOwner 類別 callback `0x502270` 由頂層 `0x40` 索引路由（T16-116 註冊表），區別於 **C→S `0x40`** Lua RequestStartScenario 命令、CTutorial S→C `0x4C`。相同數值不能跨方向／owner 猜別名。
- `0x5022A1 mov eax,[payload+4]`：本地解析按 DWORD 狀態分為 ==0、==1 與其他三種路徑。`==0` 時 `0x5022FE` 建立本地事件 `0xF4281`，`0x502355` 取 `WORD [payload+2]` 建 `0xF438B`，呼叫 `0x500110` 更新本地 20-slot state，隨後 `0x500240` rebuild；後續有 QuestInfo lookup 及依記錄不同類別的演出/提示 branch。
- `==1` 時 `0x5026D3` 讀 `WORD [payload+2]` 以查 QuestInfo map，存在時進入另一條文字/通知處理分支；其他值僅走限定退出。
- 合法資料長度應受 T02 framing / parser 整體限制；因這裡讀 `payload+4` DWORD，**不能以僅4 bytes 模擬此 handler**。對於 `0x40 + QID16` 的示範，**至少需**足夠可讀 +4 DWORD，具體整體 wire frame長度、是否有額外必填欄位仍由別段嚴格確認。這是 Client 有界 handler schema，**未證明**玩家送 `0x36 00 10 00` 後原版 Server 一定回這個命令，也不能稱 `0xF4281`/`0xF438B` 一定代表接受成功。

### D.4 本地 UI 事件與實際重繪邊界

- `0x635CA0` 只在其 TalkBox/context caller `0x63664A` 執行時取兩組 pointer vector 並寫 +0xB4/+0xB5；它不是 Quest16 type2 的證據。
- `0x5008B0`, `0x500A80` 顯示 type2 確實被不同 Client 控制器讀取，但 **目前沒有可證 callback `0x503400` 同步呼叫 `0x5B9407` 或 TalkBox redraw**。
- 同樣，Quest16 `0x36` 只有在符合 TalkBox mode 與 local action 時有 C→S，玩家可能走不同 UI 及 `0x1C` 相鄰事件；不能把兩條業務指令混同。

## E. 玩家情境 → Client gate → C→S / S→C → local state/UI → S00 需求

| 玩家情境 | Client 本地條件 | C→S (application payload) | S→C (Client schema) | 原生 Client 更新/顯示 | Server 待開發或待證 |
|---|---|---|---|---|---|
| Q14 的 prerequisite 被登記 | 已解碼 command index 116, owner已建立 | 沒要求先發 `0x36` | `74 00 0E 00`（條件式） | append key14→`0x500240` 候選 rebuild | S00 決定何時／為何送，原版 Server policy 不求逆向 |
| Q16 Demand14 miss | QuestInfo16 Demand14；+5EB0缺 key14 | 無 | 無 | `0x5006A0 → 0x50077E` skip Q16 | S00 保持完整角色進度；Client gate有實證 |
| Q16 Demand14 hit，但其他門檻失敗 | selector/level/exclusion miss | 無 | 無 | `0x50054A` 等跳過；不產生type2項目 | 環境前置與初始化 T03/T07 |
| Q16 type2 候選合格 | candidate16存在、type2、selector相同 | 尚無必然發送 | 無必然 S2C | `0x500A00` 加入 type2 pointer vector；`0x5008B0`/`0x500A80` 是實際 readers | UI 事件時間/實際 NPC10027待遊玩／T16檢查 |
| 玩家在 TalkBox 選擇 Q16 | event `0x105B9(QID16)`，mode1/2/3, action6A7且未抑制 | **`36 00 10 00`** (4B) | 尚無原生請求回覆強配對 | `dialog+0x88` 指向 QuestInfo16，UI選擇後入network queue | S00 接受/交付/reject狀態規則，勿猜mode意義 |
| NPC/互動旁路 | action6A7/type105BF | `1C 00 u16 u16` (6B) | 未確認 | type2 first ID可交另控制器；不是0x1C直接ID欄位 | 不准把0x1C當Q16 accept |
| 客戶端收到 index0x40 事件類命令 | payload+4 DWORD值0/1，及+2 WORD key | 未知是否是前項回覆 | index0x40，8B以上本地讀取（非證實線上長度） | `0x502270` 依值分支；0時派F4281/F438B並重建候選，1時查QuestInfo轉提示 | S00 response timing/type、T02 framing、T16未證配對 |
| Q16 key16 加入 prerequisite list | S2C index0x74 WORD=16 | 不能預設玩家已交付 | `74 00 10 00`（條件式） | append key16→rebuild；可使 Quest15 的 Demand16 通過 | S00 決定何時送；Quest15解鎖為下一研究 |

## F. 給 S00 的具體交付（不是自行修改台帳）

**SPEC-Q14-TO-Q16-TYPE2-DRAFT**：在匹配 KR 原件 SHA 的 Client，`0x74,key14` 加入 prerequisite WORD key vector 並 rebuild，Quest16 type2 `Demand14` 是 necessary gate；type2 user-facing decision 必須使用 `0x500A00` 及其上游，而非誤用 `0x500950` 的 type1 filtered result。請先由 T01 驗證此限定子主張，再由 S00 將其納入相容性 DRAFT SPEC。

**SPEC-Q16-REQUEST-DRAFT**：選中 QuestInfo16、TalkBox mode1..3、confirm event時可構造 `0x36,0x0010` 4B application data；Server 需依自身權威 task state 處理 acceptance/turn-in/reject。任何狀態判定／冪等／持久化是 Server設計 ADR，不得冒稱原版行為。

**GAP-Q16-UI-EXACT-SELECTOR**：從 `0x74 key14` 的 candidate16 到 NPC10027 專屬 event105B9 的 runtime 產生者尚未直接連通；需要實際 Client 事件或精準別處的 native producer。不是因缺官方 Server 演算法而阻塞。

**GAP-Q16-C2S-S2C-PAIR**：`0x36,QID16` 之後哪些 S2C key/command、回覆成功／拒絕碼、如何更新 accepted/reward state 沒有由 Client code 建立唯一配對。可交 T16 新定向分析；`0x502270` 提供可見的 case0/1 local effect，而非完整回覆語意。

**TEST-Q16-OFFLINE-SYNTHETIC-DRAFT**（以下都是***預計***，沒有執行原版 Client）：(1) 缺 key14 不入 Q16 candidate；(2) key14 存在且 selector/level/exclusion 通過時可入 Q16 candidate；(3) type1 `0x500950` 不收 Q16、type2 `0x500A00` 可以收 Q16；(4) 被選中 QID16 的 TalkBox confirm 應建立 `36 00 10 00`，cancel則不以該路徑發送；(5) index0x40 payload+4為0/1分流應分別驗 local event/文本；(6) 不將 NPC操作 `0x1C` 當 Quest16 accept；(7) key16與 Quest15 Demand16 只在其他 gates 合格時可能聯動。

## G. 四類責任與 Quest14 五個子研究狀態

| 類別 | 明確交付／剩餘 |
|---|---|
| **Client 已確認** | Quest14 key14→`0x500240`→Quest16 Demand14 gate；**新增**type2 `0x500A00` + `0x5008B0`/`0x500A80` consumers；QuestInfo16 被 mode1..3 TalkBox 選中後 `0x36 00 10 00`；鄰近NPC event `0x1C` 與 `0x502270` S2C status0/1 分支的有限證據。|
| **Client 待逆向** | Q16 具體 NPC10027 runtime event producer→type2 selector；`0x36,QID16` 的權威成功/失敗 S2C 唯一配對、接受/交付語意；即時 UI redraw / NPC icon；S2C `0x40` 未細證完整 payload schema。這些不是 Server內部演算法。|
| **Server 待開發 / S00** | Q14 完成判斷、Q16 任務可接規則、拒絕、狀態幂等/重連回填、任務進度保存、何時發 `0x74,key14/16`、T02合法framing；正式SPEC/ADR/GAP/TEST 由 S00 決策與發布。|
| **跨功能/待遊玩** | T02 framing/slot，T06 NPC TalkBox UI 字串／事件，T07 場景／NPC spawn，T14 教學關卡，T15持久化；未啟動遊戲或量測原版網路，未驗證原始 NPC10027 上可點操作。|

| Quest14 子研究 | 狀態 | 目前驗收界線 |
|---|---|---|
| ① Quest14 資源/前置 | 已完成（T16-112） | 靜態 QuestInfo/NPC/type/loader |
| ② 教學觸發 | 已完成有界（T16-113） | Isilia 本地 object/Scenario 觸發；正式 Q14 UI獨立 |
| ③ C→S | 已完成有界（T16-114） | `0x36 id14`, `0x40 scenario14` 條件式 sender |
| ④ S→C/任務key/UI | 已完成有界（T16-116） | `0x74 key14` → prerequisite/候選；**UI type1/2須依本次勘誤** |
| **⑤ Quest14 → Quest16** | **本次完成「Client prerequisite → type2 consumer → 條件式 Quest16 選取/請求」有界分析** | NPC10027 event 具體時間與 Q16 accept/reject S2C配對 **仍屬 Client 待補證**；不可宣稱整個 Quest14 可玩或原版Server成功 |

**因此：此研究單位有完整、可重現的有界因果鏈與真實的新勘誤，可作 T16-117 交付；但「Quest14全部可玩」、「Quest16實際被Server接受」、「權威S2C成功/拒絕與 UI立刻刷新」**均未經實證，不能用有界研究結案取代這三個事實。若按最嚴格端到端可玩驗收，Quest14-⑤還有上列3個具體 Client gap；按本題 Client 靜態功能鏈研究，本次已完成足以交 S00 規劃的部分。

## H. 本段三輪深入、停止條件與反證

1. **T16-117 第1輪**：從 T16-116 的 `0x500240` 直接重驗 selector/level/20-slot exclusion/Demand14 4個不同 gate；確認 Q14 key14 不代表 Q16 無條件可接，且真正 candidate是 u16 ID vector。
2. **T16-117-2 第2輪**：沿候選 `0x5EC0` 搜索其所有主要 readers，發現 `0x500950` 只收 type1、Quest16 type2 **被排除**；定位 type2 `0x500A00`，並追實際 `0x5008B0`、`0x500A80` 及 5個含呼叫者的 UI/互動 read chain，屬真實功能缺口增量與前段修正。
3. **T16-117-3 第3輪**：追 `0x5B9407` 本地事件 `105BF/6A7` 至獨立的 `0x1C` six-byte sender，對照 `0x5B6C/5B6D/5B6E→0x636520→0x636E10` 已確認的 `0x36+QID16` 條件式 producer；再核 `0x502270` QuestOwner index0x40 S2C 的本地 status0/1 side effects，明確標示不能將其冒稱 `0x36` 的官方 ACK。已達完整新 type2 Client consumer 與下一 request producer 接棒鏈，故本正式段在可證邊界結案。

## I. 原生 BIN bytes／assembly：有地址、hash、可重現切片

以下均直接在這次從 `/mnt/data/Tartaros.bin` 的 raw bytes 提取並反組譯。每段指令前的地址與 hex bytes 由 `objdump` 產生；單一切片開始若位於前指令尾端，起頭可能不對齊，**不可把那種雜訊當證據**。所有分析只採用完整指令與正確跳轉上下文。原件與以下切片均不提交 GitHub，僅本 Markdown 為交付文件。

### S01 QuestOwner S2C key14 append: VA `0x005033B0..0x00503440`; raw `0x1027B0..0x102840`; 144 bytes; SHA256 `eb0277c592c2f0b93921cd21d4bb060c572f47a559bf7f9198eff5fe61975714`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005033b0 <.data+0x1027b0>:
  5033b0:	56                   	push   esi
  5033b1:	8b f1                	mov    esi,ecx
  5033b3:	8b 8e b4 5e 00 00    	mov    ecx,DWORD PTR [esi+0x5eb4]
  5033b9:	57                   	push   edi
  5033ba:	8b be b0 5e 00 00    	mov    edi,DWORD PTR [esi+0x5eb0]
  5033c0:	3b f9                	cmp    edi,ecx
  5033c2:	74 1e                	je     0x5033e2
  5033c4:	8b c1                	mov    eax,ecx
  5033c6:	2b c1                	sub    eax,ecx
  5033c8:	53                   	push   ebx
  5033c9:	d1 f8                	sar    eax,1
  5033cb:	8d 1c 00             	lea    ebx,[eax+eax*1]
  5033ce:	53                   	push   ebx
  5033cf:	51                   	push   ecx
  5033d0:	57                   	push   edi
  5033d1:	e8 1a df 38 00       	call   0x8912f0
  5033d6:	83 c4 0c             	add    esp,0xc
  5033d9:	03 df                	add    ebx,edi
  5033db:	89 9e b4 5e 00 00    	mov    DWORD PTR [esi+0x5eb4],ebx
  5033e1:	5b                   	pop    ebx
  5033e2:	e8 79 bc f0 ff       	call   0x40f060
  5033e7:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  5033ed:	50                   	push   eax
  5033ee:	56                   	push   esi
  5033ef:	e8 4c ce ff ff       	call   0x500240
  5033f4:	5f                   	pop    edi
  5033f5:	33 c0                	xor    eax,eax
  5033f7:	5e                   	pop    esi
  5033f8:	c2 0c 00             	ret    0xc
  5033fb:	cc                   	int3
  5033fc:	cc                   	int3
  5033fd:	cc                   	int3
  5033fe:	cc                   	int3
  5033ff:	cc                   	int3
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
  503432:	cc                   	int3
  503433:	cc                   	int3
  503434:	cc                   	int3
  503435:	cc                   	int3
  503436:	cc                   	int3
  503437:	cc                   	int3
  503438:	cc                   	int3
  503439:	cc                   	int3
  50343a:	cc                   	int3
  50343b:	cc                   	int3
  50343c:	cc                   	int3
  50343d:	cc                   	int3
  50343e:	cc                   	int3
  50343f:	cc                   	int3
```

### S02 QuestCandidate rebuild：selectors + level: VA `0x00500440..0x00500555`; raw `0xFF840..0xFF955`; 277 bytes; SHA256 `c922ca1b2b10d61b452cff6ecbda134bef066e06962a04f6d3cd5eda6bcca242`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500440 <.data+0xff840>:
  500440:	83 78 0c 09          	cmp    DWORD PTR [eax+0xc],0x9
  500444:	7d 05                	jge    0x50044b
  500446:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  500449:	eb 04                	jmp    0x50044f
  50044b:	8b c8                	mov    ecx,eax
  50044d:	8b 00                	mov    eax,DWORD PTR [eax]
  50044f:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  500453:	74 eb                	je     0x500440
  500455:	3b ca                	cmp    ecx,edx
  500457:	74 2c                	je     0x500485
  500459:	8b 41 10             	mov    eax,DWORD PTR [ecx+0x10]
  50045c:	8b 78 08             	mov    edi,DWORD PTR [eax+0x8]
  50045f:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  500463:	51                   	push   ecx
  500464:	8d 48 04             	lea    ecx,[eax+0x4]
  500467:	8d 44 24 2c          	lea    eax,[esp+0x2c]
  50046b:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  50046f:	e8 cc b0 f4 ff       	call   0x44b540
  500474:	39 38                	cmp    DWORD PTR [eax],edi
  500476:	8b 7c 24 48          	mov    edi,DWORD PTR [esp+0x48]
  50047a:	0f 94 c0             	sete   al
  50047d:	84 c0                	test   al,al
  50047f:	0f 84 c5 00 00 00    	je     0x50054a
  500485:	8b 53 20             	mov    edx,DWORD PTR [ebx+0x20]
  500488:	3b 55 0c             	cmp    edx,DWORD PTR [ebp+0xc]
  50048b:	0f 85 b9 00 00 00    	jne    0x50054a
  500491:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  500494:	3b 44 24 18          	cmp    eax,DWORD PTR [esp+0x18]
  500498:	0f 8f ac 00 00 00    	jg     0x50054a
  50049e:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  5004a1:	33 c0                	xor    eax,eax
  5004a3:	81 c1 d0 5e 00 00    	add    ecx,0x5ed0
  5004a9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  5004b0:	0f b7 11             	movzx  edx,WORD PTR [ecx]
  5004b3:	3b d6                	cmp    edx,esi
  5004b5:	0f 84 8f 00 00 00    	je     0x50054a
  5004bb:	40                   	inc    eax
  5004bc:	83 c1 02             	add    ecx,0x2
  5004bf:	83 f8 14             	cmp    eax,0x14
  5004c2:	7c ec                	jl     0x5004b0
  5004c4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5004c7:	8b 88 b4 5e 00 00    	mov    ecx,DWORD PTR [eax+0x5eb4]
  5004cd:	8b 80 b0 5e 00 00    	mov    eax,DWORD PTR [eax+0x5eb0]
  5004d3:	3b c1                	cmp    eax,ecx
  5004d5:	74 12                	je     0x5004e9
  5004d7:	0f b7 10             	movzx  edx,WORD PTR [eax]
  5004da:	3b d6                	cmp    edx,esi
  5004dc:	74 07                	je     0x5004e5
  5004de:	83 c0 02             	add    eax,0x2
  5004e1:	3b c1                	cmp    eax,ecx
  5004e3:	75 f2                	jne    0x5004d7
  5004e5:	3b c1                	cmp    eax,ecx
  5004e7:	75 61                	jne    0x50054a
  5004e9:	3b df                	cmp    ebx,edi
  5004eb:	73 36                	jae    0x500523
  5004ed:	8b 44 24 44          	mov    eax,DWORD PTR [esp+0x44]
  5004f1:	3b c3                	cmp    eax,ebx
  5004f3:	77 2e                	ja     0x500523
  5004f5:	2b d8                	sub    ebx,eax
  5004f7:	c1 fb 02             	sar    ebx,0x2
  5004fa:	8b f3                	mov    esi,ebx
  5004fc:	3b 7c 24 4c          	cmp    edi,DWORD PTR [esp+0x4c]
  500500:	75 16                	jne    0x500518
  500502:	b9 01 00 00 00       	mov    ecx,0x1
  500507:	8d 44 24 44          	lea    eax,[esp+0x44]
  50050b:	e8 30 5d 1d 00       	call   0x6d6240
  500510:	8b 7c 24 48          	mov    edi,DWORD PTR [esp+0x48]
  500514:	8b 44 24 44          	mov    eax,DWORD PTR [esp+0x44]
  500518:	85 ff                	test   edi,edi
  50051a:	74 27                	je     0x500543
  50051c:	8b 04 b0             	mov    eax,DWORD PTR [eax+esi*4]
  50051f:	89 07                	mov    DWORD PTR [edi],eax
  500521:	eb 20                	jmp    0x500543
  500523:	3b 7c 24 4c          	cmp    edi,DWORD PTR [esp+0x4c]
  500527:	75 12                	jne    0x50053b
  500529:	b9 01 00 00 00       	mov    ecx,0x1
  50052e:	8d 44 24 44          	lea    eax,[esp+0x44]
  500532:	e8 09 5d 1d 00       	call   0x6d6240
  500537:	8b 7c 24 48          	mov    edi,DWORD PTR [esp+0x48]
  50053b:	85 ff                	test   edi,edi
  50053d:	74 04                	je     0x500543
  50053f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  500541:	89 0f                	mov    DWORD PTR [edi],ecx
  500543:	83 c7 04             	add    edi,0x4
  500546:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  50054a:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  50054e:	80 ba b5 00 00 00 00 	cmp    BYTE PTR [edx+0xb5],0x0
```

### S03 QuestCandidate Demand14 + append: VA `0x00500630..0x005007A2`; raw `0xFFA30..0xFFBA2`; 370 bytes; SHA256 `1aaf66bf43aed463919aea0c88e3c47d9e7f27e14decbfa8a8cd36ef69f9c85c`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500630 <.data+0xffa30>:
  500630:	00 8b 74 24 14 8b    	add    BYTE PTR [ebx-0x74ebdb8c],cl
  500636:	54                   	push   esp
  500637:	24 10                	and    al,0x10
  500639:	52                   	push   edx
  50063a:	8d 44 24 28          	lea    eax,[esp+0x28]
  50063e:	8b ce                	mov    ecx,esi
  500640:	e8 db 36 00 00       	call   0x503d20
  500645:	8b 44 24 24          	mov    eax,DWORD PTR [esp+0x24]
  500649:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  50064c:	0f 84 2c 01 00 00    	je     0x50077e
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
  5006b3:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  5006b7:	0f b7 39             	movzx  edi,WORD PTR [ecx]
  5006ba:	8b 86 c4 5e 00 00    	mov    eax,DWORD PTR [esi+0x5ec4]
  5006c0:	81 c6 c0 5e 00 00    	add    esi,0x5ec0
  5006c6:	8d 54 24 18          	lea    edx,[esp+0x18]
  5006ca:	89 7c 24 18          	mov    DWORD PTR [esp+0x18],edi
  5006ce:	3b d0                	cmp    edx,eax
  5006d0:	73 61                	jae    0x500733
  5006d2:	8b 16                	mov    edx,DWORD PTR [esi]
  5006d4:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  5006d8:	3b d1                	cmp    edx,ecx
  5006da:	77 57                	ja     0x500733
  5006dc:	8b f9                	mov    edi,ecx
  5006de:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  5006e1:	2b fa                	sub    edi,edx
  5006e3:	d1 ff                	sar    edi,1
  5006e5:	3b c1                	cmp    eax,ecx
  5006e7:	75 38                	jne    0x500721
  5006e9:	2b c2                	sub    eax,edx
  5006eb:	d1 f8                	sar    eax,1
  5006ed:	3d fe ff ff 7f       	cmp    eax,0x7ffffffe
  5006f2:	0f 87 c8 00 00 00    	ja     0x5007c0
  5006f8:	2b ca                	sub    ecx,edx
  5006fa:	40                   	inc    eax
  5006fb:	d1 f9                	sar    ecx,1
  5006fd:	3b c1                	cmp    eax,ecx
  5006ff:	76 20                	jbe    0x500721
  500701:	8b d1                	mov    edx,ecx
  500703:	d1 ea                	shr    edx,1
  500705:	bb ff ff ff 7f       	mov    ebx,0x7fffffff
  50070a:	2b da                	sub    ebx,edx
  50070c:	3b d9                	cmp    ebx,ecx
  50070e:	73 04                	jae    0x500714
  500710:	33 c9                	xor    ecx,ecx
  500712:	eb 02                	jmp    0x500716
  500714:	03 ca                	add    ecx,edx
  500716:	3b c8                	cmp    ecx,eax
  500718:	0f 42 c8             	cmovb  ecx,eax
  50071b:	51                   	push   ecx
  50071c:	e8 7f af f4 ff       	call   0x44b6a0
  500721:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  500724:	85 c0                	test   eax,eax
  500726:	74 52                	je     0x50077a
  500728:	8b 16                	mov    edx,DWORD PTR [esi]
  50072a:	66 8b 0c 7a          	mov    cx,WORD PTR [edx+edi*2]
  50072e:	66 89 08             	mov    WORD PTR [eax],cx
  500731:	eb 47                	jmp    0x50077a
  500733:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  500736:	3b c1                	cmp    eax,ecx
  500738:	75 36                	jne    0x500770
  50073a:	8b 16                	mov    edx,DWORD PTR [esi]
  50073c:	2b c2                	sub    eax,edx
  50073e:	d1 f8                	sar    eax,1
  500740:	3d fe ff ff 7f       	cmp    eax,0x7ffffffe
  500745:	77 79                	ja     0x5007c0
  500747:	2b ca                	sub    ecx,edx
  500749:	40                   	inc    eax
  50074a:	d1 f9                	sar    ecx,1
  50074c:	3b c1                	cmp    eax,ecx
  50074e:	76 20                	jbe    0x500770
  500750:	8b d1                	mov    edx,ecx
  500752:	d1 ea                	shr    edx,1
  500754:	bb ff ff ff 7f       	mov    ebx,0x7fffffff
  500759:	2b da                	sub    ebx,edx
  50075b:	3b d9                	cmp    ebx,ecx
  50075d:	73 04                	jae    0x500763
  50075f:	33 c9                	xor    ecx,ecx
  500761:	eb 02                	jmp    0x500765
  500763:	03 ca                	add    ecx,edx
  500765:	3b c8                	cmp    ecx,eax
  500767:	0f 42 c8             	cmovb  ecx,eax
  50076a:	51                   	push   ecx
  50076b:	e8 30 af f4 ff       	call   0x44b6a0
  500770:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  500773:	85 c0                	test   eax,eax
  500775:	74 03                	je     0x50077a
  500777:	66 89 38             	mov    WORD PTR [eax],di
  50077a:	83 46 04 02          	add    DWORD PTR [esi+0x4],0x2
  50077e:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  500782:	83 44 24 10 04       	add    DWORD PTR [esp+0x10],0x4
  500787:	40                   	inc    eax
  500788:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  50078c:	3b 44 24 28          	cmp    eax,DWORD PTR [esp+0x28]
  500790:	0f 82 9b fe ff ff    	jb     0x500631
  500796:	8b 44 24 44          	mov    eax,DWORD PTR [esp+0x44]
  50079a:	85 c0                	test   eax,eax
  50079c:	74 0d                	je     0x5007ab
  50079e:	8b 54 24 44          	mov    edx,DWORD PTR [esp+0x44]
```

### S04 type1 QuestRecord consumer: VA `0x00500950..0x005009FD`; raw `0xFFD50..0xFFDFD`; 173 bytes; SHA256 `7b9267982d8155ae625260c520e3ec19c6c70d53bc8a42a827a61c0f932145da`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500950 <.data+0xffd50>:
  500950:	55                   	push   ebp
  500951:	8b ec                	mov    ebp,esp
  500953:	83 ec 0c             	sub    esp,0xc
  500956:	53                   	push   ebx
  500957:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  50095a:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  50095d:	56                   	push   esi
  50095e:	8b 33                	mov    esi,DWORD PTR [ebx]
  500960:	57                   	push   edi
  500961:	3b f1                	cmp    esi,ecx
  500963:	74 1e                	je     0x500983
  500965:	8b c1                	mov    eax,ecx
  500967:	2b c1                	sub    eax,ecx
  500969:	c1 f8 02             	sar    eax,0x2
  50096c:	8d 3c 85 00 00 00 00 	lea    edi,[eax*4+0x0]
  500973:	57                   	push   edi
  500974:	51                   	push   ecx
  500975:	56                   	push   esi
  500976:	e8 75 09 39 00       	call   0x8912f0
  50097b:	83 c4 0c             	add    esp,0xc
  50097e:	03 fe                	add    edi,esi
  500980:	89 7b 04             	mov    DWORD PTR [ebx+0x4],edi
  500983:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  500986:	8b 87 c4 5e 00 00    	mov    eax,DWORD PTR [edi+0x5ec4]
  50098c:	8b 9f c0 5e 00 00    	mov    ebx,DWORD PTR [edi+0x5ec0]
  500992:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  500995:	3b d8                	cmp    ebx,eax
  500997:	74 5b                	je     0x5009f4
  500999:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  5009a0:	0f b7 03             	movzx  eax,WORD PTR [ebx]
  5009a3:	8b b7 ac 5e 00 00    	mov    esi,DWORD PTR [edi+0x5eac]
  5009a9:	8d 4d fc             	lea    ecx,[ebp-0x4]
  5009ac:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  5009af:	51                   	push   ecx
  5009b0:	8d 45 f8             	lea    eax,[ebp-0x8]
  5009b3:	8b ce                	mov    ecx,esi
  5009b5:	e8 66 33 00 00       	call   0x503d20
  5009ba:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  5009bd:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  5009c0:	74 05                	je     0x5009c7
  5009c2:	83 c0 10             	add    eax,0x10
  5009c5:	eb 02                	jmp    0x5009c9
  5009c7:	33 c0                	xor    eax,eax
  5009c9:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  5009cc:	85 c0                	test   eax,eax
  5009ce:	74 1c                	je     0x5009ec
  5009d0:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  5009d3:	39 50 28             	cmp    DWORD PTR [eax+0x28],edx
  5009d6:	75 14                	jne    0x5009ec
  5009d8:	83 78 04 01          	cmp    DWORD PTR [eax+0x4],0x1
  5009dc:	75 0e                	jne    0x5009ec
  5009de:	8b 7d 10             	mov    edi,DWORD PTR [ebp+0x10]
  5009e1:	8d 45 fc             	lea    eax,[ebp-0x4]
  5009e4:	e8 27 33 f4 ff       	call   0x443d10
  5009e9:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  5009ec:	83 c3 02             	add    ebx,0x2
  5009ef:	3b 5d f4             	cmp    ebx,DWORD PTR [ebp-0xc]
  5009f2:	75 ac                	jne    0x5009a0
  5009f4:	5f                   	pop    edi
  5009f5:	5e                   	pop    esi
  5009f6:	5b                   	pop    ebx
  5009f7:	8b e5                	mov    esp,ebp
  5009f9:	5d                   	pop    ebp
  5009fa:	c2 0c 00             	ret    0xc
```

### S05 NEW type2 QuestRecord consumer: VA `0x00500A00..0x00500A7D`; raw `0xFFE00..0xFFE7D`; 125 bytes; SHA256 `7249341812963eb07e7eff57ed46c249bb791275e54364b6265debf16c55a929`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500a00 <.data+0xffe00>:
  500a00:	55                   	push   ebp
  500a01:	8b ec                	mov    ebp,esp
  500a03:	83 ec 0c             	sub    esp,0xc
  500a06:	53                   	push   ebx
  500a07:	57                   	push   edi
  500a08:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  500a0b:	8b 87 c4 5e 00 00    	mov    eax,DWORD PTR [edi+0x5ec4]
  500a11:	8b 9f c0 5e 00 00    	mov    ebx,DWORD PTR [edi+0x5ec0]
  500a17:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  500a1a:	3b d8                	cmp    ebx,eax
  500a1c:	74 57                	je     0x500a75
  500a1e:	56                   	push   esi
  500a1f:	90                   	nop
  500a20:	0f b7 03             	movzx  eax,WORD PTR [ebx]
  500a23:	8b b7 ac 5e 00 00    	mov    esi,DWORD PTR [edi+0x5eac]
  500a29:	8d 4d fc             	lea    ecx,[ebp-0x4]
  500a2c:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500a2f:	51                   	push   ecx
  500a30:	8d 45 f8             	lea    eax,[ebp-0x8]
  500a33:	8b ce                	mov    ecx,esi
  500a35:	e8 e6 32 00 00       	call   0x503d20
  500a3a:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  500a3d:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  500a40:	74 05                	je     0x500a47
  500a42:	83 c0 10             	add    eax,0x10
  500a45:	eb 02                	jmp    0x500a49
  500a47:	33 c0                	xor    eax,eax
  500a49:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  500a4c:	85 c0                	test   eax,eax
  500a4e:	74 1c                	je     0x500a6c
  500a50:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  500a53:	39 50 28             	cmp    DWORD PTR [eax+0x28],edx
  500a56:	75 14                	jne    0x500a6c
  500a58:	83 78 04 02          	cmp    DWORD PTR [eax+0x4],0x2
  500a5c:	75 0e                	jne    0x500a6c
  500a5e:	8b 7d 10             	mov    edi,DWORD PTR [ebp+0x10]
  500a61:	8d 45 fc             	lea    eax,[ebp-0x4]
  500a64:	e8 a7 32 f4 ff       	call   0x443d10
  500a69:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  500a6c:	83 c3 02             	add    ebx,0x2
  500a6f:	3b 5d f4             	cmp    ebx,DWORD PTR [ebp-0xc]
  500a72:	75 ac                	jne    0x500a20
  500a74:	5e                   	pop    esi
  500a75:	5f                   	pop    edi
  500a76:	5b                   	pop    ebx
  500a77:	8b e5                	mov    esp,ebp
  500a79:	5d                   	pop    ebp
  500a7a:	c2 0c 00             	ret    0xc
```

### S06 type2 first quest ID accessor: VA `0x005008B0..0x00500944`; raw `0xFFCB0..0xFFD44`; 148 bytes; SHA256 `aeee21cd72e41936104913bf9baa86f11b09632e77fa568f145237f67f62928c`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005008b0 <.data+0xffcb0>:
  5008b0:	55                   	push   ebp
  5008b1:	8b ec                	mov    ebp,esp
  5008b3:	83 e4 f8             	and    esp,0xfffffff8
  5008b6:	6a ff                	push   0xffffffff
  5008b8:	68 28 88 90 00       	push   0x908828
  5008bd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5008c3:	50                   	push   eax
  5008c4:	83 ec 18             	sub    esp,0x18
  5008c7:	56                   	push   esi
  5008c8:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5008cd:	33 c4                	xor    eax,esp
  5008cf:	50                   	push   eax
  5008d0:	8d 44 24 20          	lea    eax,[esp+0x20]
  5008d4:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5008da:	33 f6                	xor    esi,esi
  5008dc:	89 74 24 0c          	mov    DWORD PTR [esp+0xc],esi
  5008e0:	89 74 24 10          	mov    DWORD PTR [esp+0x10],esi
  5008e4:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5008e8:	8d 44 24 0c          	lea    eax,[esp+0xc]
  5008ec:	50                   	push   eax
  5008ed:	51                   	push   ecx
  5008ee:	52                   	push   edx
  5008ef:	89 74 24 34          	mov    DWORD PTR [esp+0x34],esi
  5008f3:	e8 08 01 00 00       	call   0x500a00
  5008f8:	8b 44 24 0c          	mov    eax,DWORD PTR [esp+0xc]
  5008fc:	3b 44 24 10          	cmp    eax,DWORD PTR [esp+0x10]
  500900:	75 20                	jne    0x500922
  500902:	3b c6                	cmp    eax,esi
  500904:	74 09                	je     0x50090f
  500906:	50                   	push   eax
  500907:	e8 00 09 39 00       	call   0x89120c
  50090c:	83 c4 04             	add    esp,0x4
  50090f:	33 c0                	xor    eax,eax
  500911:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  500915:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  50091c:	59                   	pop    ecx
  50091d:	5e                   	pop    esi
  50091e:	8b e5                	mov    esp,ebp
  500920:	5d                   	pop    ebp
  500921:	c3                   	ret
  500922:	8b 08                	mov    ecx,DWORD PTR [eax]
  500924:	0f b7 31             	movzx  esi,WORD PTR [ecx]
  500927:	50                   	push   eax
  500928:	e8 df 08 39 00       	call   0x89120c
  50092d:	83 c4 04             	add    esp,0x4
  500930:	66 8b c6             	mov    ax,si
  500933:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  500937:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  50093e:	59                   	pop    ecx
  50093f:	5e                   	pop    esi
  500940:	8b e5                	mov    esp,ebp
  500942:	5d                   	pop    ebp
  500943:	c3                   	ret
```

### S07 type2 owner/controller classification: VA `0x00500A80..0x00500BA5`; raw `0xFFE80..0xFFFA5`; 293 bytes; SHA256 `34c78b10ac84c9d00885457ec2c4bb6ddc4396e387ded8c76f34749fb6256f83`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500a80 <.data+0xffe80>:
  500a80:	55                   	push   ebp
  500a81:	8b ec                	mov    ebp,esp
  500a83:	83 e4 f8             	and    esp,0xfffffff8
  500a86:	6a ff                	push   0xffffffff
  500a88:	68 ce 01 94 00       	push   0x9401ce
  500a8d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  500a93:	50                   	push   eax
  500a94:	83 ec 48             	sub    esp,0x48
  500a97:	53                   	push   ebx
  500a98:	56                   	push   esi
  500a99:	57                   	push   edi
  500a9a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  500a9f:	33 c4                	xor    eax,esp
  500aa1:	50                   	push   eax
  500aa2:	8d 44 24 58          	lea    eax,[esp+0x58]
  500aa6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  500aac:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  500aaf:	33 ff                	xor    edi,edi
  500ab1:	89 7c 24 34          	mov    DWORD PTR [esp+0x34],edi
  500ab5:	89 7c 24 38          	mov    DWORD PTR [esp+0x38],edi
  500ab9:	89 7c 24 3c          	mov    DWORD PTR [esp+0x3c],edi
  500abd:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  500ac0:	8d 44 24 34          	lea    eax,[esp+0x34]
  500ac4:	50                   	push   eax
  500ac5:	53                   	push   ebx
  500ac6:	56                   	push   esi
  500ac7:	89 7c 24 6c          	mov    DWORD PTR [esp+0x6c],edi
  500acb:	e8 80 fe ff ff       	call   0x500950
  500ad0:	81 c6 d0 5e 00 00    	add    esi,0x5ed0
  500ad6:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  500ad9:	0f b7 0e             	movzx  ecx,WORD PTR [esi]
  500adc:	53                   	push   ebx
  500add:	52                   	push   edx
  500ade:	e8 7d f6 ff ff       	call   0x500160
  500ae3:	85 c0                	test   eax,eax
  500ae5:	0f 85 a3 00 00 00    	jne    0x500b8e
  500aeb:	47                   	inc    edi
  500aec:	83 c6 02             	add    esi,0x2
  500aef:	83 ff 14             	cmp    edi,0x14
  500af2:	7c e2                	jl     0x500ad6
  500af4:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  500afb:	75 23                	jne    0x500b20
  500afd:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  500b04:	c6 44 24 60 01       	mov    BYTE PTR [esp+0x60],0x1
  500b09:	e8 82 0a fe ff       	call   0x4e1590
  500b0e:	68 80 cc bc 00       	push   0xbccc80
  500b13:	e8 02 18 39 00       	call   0x89231a
  500b18:	83 c4 04             	add    esp,0x4
  500b1b:	c6 44 24 60 00       	mov    BYTE PTR [esp+0x60],0x0
  500b20:	a1 2c 39 f9 00       	mov    eax,ds:0xf9392c
  500b25:	33 ff                	xor    edi,edi
  500b27:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  500b2b:	83 f8 03             	cmp    eax,0x3
  500b2e:	74 14                	je     0x500b44
  500b30:	83 f8 01             	cmp    eax,0x1
  500b33:	74 0f                	je     0x500b44
  500b35:	83 f8 07             	cmp    eax,0x7
  500b38:	74 0a                	je     0x500b44
  500b3a:	83 f8 17             	cmp    eax,0x17
  500b3d:	74 05                	je     0x500b44
  500b3f:	83 f8 18             	cmp    eax,0x18
  500b42:	75 75                	jne    0x500bb9
  500b44:	89 7c 24 44          	mov    DWORD PTR [esp+0x44],edi
  500b48:	89 7c 24 48          	mov    DWORD PTR [esp+0x48],edi
  500b4c:	89 7c 24 4c          	mov    DWORD PTR [esp+0x4c],edi
  500b50:	8d 44 24 44          	lea    eax,[esp+0x44]
  500b54:	50                   	push   eax
  500b55:	53                   	push   ebx
  500b56:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  500b59:	53                   	push   ebx
  500b5a:	c6 44 24 6c 02       	mov    BYTE PTR [esp+0x6c],0x2
  500b5f:	e8 9c fe ff ff       	call   0x500a00
  500b64:	8b 44 24 44          	mov    eax,DWORD PTR [esp+0x44]
  500b68:	33 c9                	xor    ecx,ecx
  500b6a:	3b 44 24 48          	cmp    eax,DWORD PTR [esp+0x48]
  500b6e:	0f 95 c1             	setne  cl
  500b71:	8b f1                	mov    esi,ecx
  500b73:	3b c7                	cmp    eax,edi
  500b75:	74 09                	je     0x500b80
  500b77:	50                   	push   eax
  500b78:	e8 8f 06 39 00       	call   0x89120c
  500b7d:	83 c4 04             	add    esp,0x4
  500b80:	3b f7                	cmp    esi,edi
  500b82:	74 38                	je     0x500bbc
  500b84:	c7 44 24 14 01 00 00 	mov    DWORD PTR [esp+0x14],0x1
  500b8b:	00 
  500b8c:	eb 2e                	jmp    0x500bbc
  500b8e:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  500b92:	85 c0                	test   eax,eax
  500b94:	74 09                	je     0x500b9f
  500b96:	50                   	push   eax
  500b97:	e8 70 06 39 00       	call   0x89120c
  500b9c:	83 c4 04             	add    esp,0x4
  500b9f:	b8 03 00 00 00       	mov    eax,0x3
  500ba4:	8b             	mov    ecx,DWORD PTR [esp+0x58]
```

### S08 type2 classification later branches: VA `0x00500B90..0x00500D50`; raw `0xFFF90..0x100150`; 448 bytes; SHA256 `49a83320d566629de1a281edc7c6a04993cd36c1ccb017c5d5bbe07dc4dc068d`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500b90 <.data+0xfff90>:
  500b90:	24 34                	and    al,0x34
  500b92:	85 c0                	test   eax,eax
  500b94:	74 09                	je     0x500b9f
  500b96:	50                   	push   eax
  500b97:	e8 70 06 39 00       	call   0x89120c
  500b9c:	83 c4 04             	add    esp,0x4
  500b9f:	b8 03 00 00 00       	mov    eax,0x3
  500ba4:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  500ba8:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  500baf:	59                   	pop    ecx
  500bb0:	5f                   	pop    edi
  500bb1:	5e                   	pop    esi
  500bb2:	5b                   	pop    ebx
  500bb3:	8b e5                	mov    esp,ebp
  500bb5:	5d                   	pop    ebp
  500bb6:	c2 08 00             	ret    0x8
  500bb9:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  500bbc:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  500bc0:	8b 7c 24 34          	mov    edi,DWORD PTR [esp+0x34]
  500bc4:	2b cf                	sub    ecx,edi
  500bc6:	c1 f9 02             	sar    ecx,0x2
  500bc9:	33 d2                	xor    edx,edx
  500bcb:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  500bcf:	3b ca                	cmp    ecx,edx
  500bd1:	0f 84 d3 01 00 00    	je     0x500daa
  500bd7:	8b 83 c0 5e 00 00    	mov    eax,DWORD PTR [ebx+0x5ec0]
  500bdd:	8b 9b c4 5e 00 00    	mov    ebx,DWORD PTR [ebx+0x5ec4]
  500be3:	2b d8                	sub    ebx,eax
  500be5:	d1 fb                	sar    ebx,1
  500be7:	89 54 24 24          	mov    DWORD PTR [esp+0x24],edx
  500beb:	89 54 24 28          	mov    DWORD PTR [esp+0x28],edx
  500bef:	89 54 24 20          	mov    DWORD PTR [esp+0x20],edx
  500bf3:	0f 84 d2 00 00 00    	je     0x500ccb
  500bf9:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  500bfd:	33 c0                	xor    eax,eax
  500bff:	85 c9                	test   ecx,ecx
  500c01:	0f 84 ae 00 00 00    	je     0x500cb5
  500c07:	8b 54 24 1c          	mov    edx,DWORD PTR [esp+0x1c]
  500c0b:	0f b7 32             	movzx  esi,WORD PTR [edx]
  500c0e:	8b ff                	mov    edi,edi
  500c10:	8b 14 87             	mov    edx,DWORD PTR [edi+eax*4]
  500c13:	3b 32                	cmp    esi,DWORD PTR [edx]
  500c15:	74 0a                	je     0x500c21
  500c17:	40                   	inc    eax
  500c18:	3b c1                	cmp    eax,ecx
  500c1a:	72 f4                	jb     0x500c10
  500c1c:	e9 94 00 00 00       	jmp    0x500cb5
  500c21:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  500c24:	8b 90 ac 5e 00 00    	mov    edx,DWORD PTR [eax+0x5eac]
  500c2a:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  500c2d:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  500c30:	80 b8 b5 00 00 00 00 	cmp    BYTE PTR [eax+0xb5],0x0
  500c37:	75 1e                	jne    0x500c57
  500c39:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  500c40:	39 70 0c             	cmp    DWORD PTR [eax+0xc],esi
  500c43:	7d 05                	jge    0x500c4a
  500c45:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  500c48:	eb 04                	jmp    0x500c4e
  500c4a:	8b c8                	mov    ecx,eax
  500c4c:	8b 00                	mov    eax,DWORD PTR [eax]
  500c4e:	80 b8 b5 00 00 00 00 	cmp    BYTE PTR [eax+0xb5],0x0
  500c55:	74 e9                	je     0x500c40
  500c57:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  500c5a:	89 4c 24 2c          	mov    DWORD PTR [esp+0x2c],ecx
  500c5e:	3b c8                	cmp    ecx,eax
  500c60:	74 0b                	je     0x500c6d
  500c62:	3b 71 0c             	cmp    esi,DWORD PTR [ecx+0xc]
  500c65:	7c 06                	jl     0x500c6d
  500c67:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  500c6b:	eb 08                	jmp    0x500c75
  500c6d:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  500c71:	8d 4c 24 30          	lea    ecx,[esp+0x30]
  500c75:	8b 09                	mov    ecx,DWORD PTR [ecx]
  500c77:	3b c8                	cmp    ecx,eax
  500c79:	74 05                	je     0x500c80
  500c7b:	8d 41 10             	lea    eax,[ecx+0x10]
  500c7e:	eb 02                	jmp    0x500c82
  500c80:	33 c0                	xor    eax,eax
  500c82:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  500c85:	83 f8 04             	cmp    eax,0x4
  500c88:	75 11                	jne    0x500c9b
  500c8a:	83 7c 24 14 00       	cmp    DWORD PTR [esp+0x14],0x0
  500c8f:	75 6f                	jne    0x500d00
  500c91:	c7 44 24 24 01 00 00 	mov    DWORD PTR [esp+0x24],0x1
  500c98:	00 
  500c99:	eb 16                	jmp    0x500cb1
  500c9b:	83 f8 01             	cmp    eax,0x1
  500c9e:	0f 84 83 00 00 00    	je     0x500d27
  500ca4:	83 f8 02             	cmp    eax,0x2
  500ca7:	75 08                	jne    0x500cb1
  500ca9:	c7 44 24 28 01 00 00 	mov    DWORD PTR [esp+0x28],0x1
  500cb0:	00 
  500cb1:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  500cb5:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  500cb9:	83 44 24 1c 02       	add    DWORD PTR [esp+0x1c],0x2
  500cbe:	40                   	inc    eax
  500cbf:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  500cc3:	3b c3                	cmp    eax,ebx
  500cc5:	0f 82 32 ff ff ff    	jb     0x500bfd
  500ccb:	83 7c 24 14 00       	cmp    DWORD PTR [esp+0x14],0x0
  500cd0:	75 2e                	jne    0x500d00
  500cd2:	83 7c 24 24 00       	cmp    DWORD PTR [esp+0x24],0x0
  500cd7:	74 7c                	je     0x500d55
  500cd9:	85 ff                	test   edi,edi
  500cdb:	74 09                	je     0x500ce6
  500cdd:	57                   	push   edi
  500cde:	e8 29 05 39 00       	call   0x89120c
  500ce3:	83 c4 04             	add    esp,0x4
  500ce6:	b8 04 00 00 00       	mov    eax,0x4
  500ceb:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  500cef:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  500cf6:	59                   	pop    ecx
  500cf7:	5f                   	pop    edi
  500cf8:	5e                   	pop    esi
  500cf9:	5b                   	pop    ebx
  500cfa:	8b e5                	mov    esp,ebp
  500cfc:	5d                   	pop    ebp
  500cfd:	c2 08 00             	ret    0x8
  500d00:	85 ff                	test   edi,edi
  500d02:	74 09                	je     0x500d0d
  500d04:	57                   	push   edi
  500d05:	e8 02 05 39 00       	call   0x89120c
  500d0a:	83 c4 04             	add    esp,0x4
  500d0d:	b8 05 00 00 00       	mov    eax,0x5
  500d12:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  500d16:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  500d1d:	59                   	pop    ecx
  500d1e:	5f                   	pop    edi
  500d1f:	5e                   	pop    esi
  500d20:	5b                   	pop    ebx
  500d21:	8b e5                	mov    esp,ebp
  500d23:	5d                   	pop    ebp
  500d24:	c2 08 00             	ret    0x8
  500d27:	83 7c 24 14 00       	cmp    DWORD PTR [esp+0x14],0x0
  500d2c:	75 d2                	jne    0x500d00
  500d2e:	85 ff                	test   edi,edi
  500d30:	74 09                	je     0x500d3b
  500d32:	57                   	push   edi
  500d33:	e8 d4 04 39 00       	call   0x89120c
  500d38:	83 c4 04             	add    esp,0x4
  500d3b:	b8 02 00 00 00       	mov    eax,0x2
  500d40:	8b 4c 24 58          	mov    ecx,DWORD PTR [esp+0x58]
  500d44:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  500d4b:	59                   	pop    ecx
  500d4c:	5f                   	pop    edi
  500d4d:	5e                   	pop    esi
  500d4e:	5b                   	pop    ebx
  500d4f:	8b                 	mov    esp,ebp
```

### S09 UI type2 event caller + 6B producer: VA `0x005B9380..0x005B9499`; raw `0x1B8780..0x1B8899`; 281 bytes; SHA256 `6e2bf77e249e3c9dd5d1f4a30ca2917db5e4b0ade4db54153aad32a80d1f9ebb`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b9380 <.data+0x1b8780>:
  5b9380:	04 8b                	add    al,0x8b
  5b9382:	c6                   	(bad)
  5b9383:	eb 12                	jmp    0x5b9397
  5b9385:	6a 00                	push   0x0
  5b9387:	68 c0 1f bf 00       	push   0xbf1fc0
  5b938c:	68 18 21 bf 00       	push   0xbf2118
  5b9391:	6a 00                	push   0x0
  5b9393:	ff d7                	call   edi
  5b9395:	33 c0                	xor    eax,eax
  5b9397:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  5b939a:	81 f9 a7 06 00 00    	cmp    ecx,0x6a7
  5b93a0:	0f 85 f2 00 00 00    	jne    0x5b9498
  5b93a6:	8b 70 18             	mov    esi,DWORD PTR [eax+0x18]
  5b93a9:	85 f6                	test   esi,esi
  5b93ab:	74 20                	je     0x5b93cd
  5b93ad:	8b 06                	mov    eax,DWORD PTR [esi]
  5b93af:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b93b2:	8b ce                	mov    ecx,esi
  5b93b4:	ff d2                	call   edx
  5b93b6:	3d bf 05 01 00       	cmp    eax,0x105bf
  5b93bb:	74 12                	je     0x5b93cf
  5b93bd:	6a 00                	push   0x0
  5b93bf:	68 c0 1f bf 00       	push   0xbf1fc0
  5b93c4:	68 18 21 bf 00       	push   0xbf2118
  5b93c9:	6a 00                	push   0x0
  5b93cb:	ff d7                	call   edi
  5b93cd:	33 f6                	xor    esi,esi
  5b93cf:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b93d6:	75 27                	jne    0x5b93ff
  5b93d8:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b93df:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  5b93e6:	e8 75 6a f4 ff       	call   0x4ffe60
  5b93eb:	68 00 cf bc 00       	push   0xbccf00
  5b93f0:	e8 25 8f 2d 00       	call   0x89231a
  5b93f5:	83 c4 04             	add    esp,0x4
  5b93f8:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
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
  5b944c:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  5b9453:	b8 1c 00 00 00       	mov    eax,0x1c
  5b9458:	66 89 45 e8          	mov    WORD PTR [ebp-0x18],ax
  5b945c:	66 8b 4e 18          	mov    cx,WORD PTR [esi+0x18]
  5b9460:	66 89 4d ea          	mov    WORD PTR [ebp-0x16],cx
  5b9464:	66 8b 56 1c          	mov    dx,WORD PTR [esi+0x1c]
  5b9468:	66 89 55 ec          	mov    WORD PTR [ebp-0x14],dx
  5b946c:	0f 85 e1 00 00 00    	jne    0x5b9553
  5b9472:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  5b9478:	8b 01                	mov    eax,DWORD PTR [ecx]
  5b947a:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  5b947d:	6a 06                	push   0x6
  5b947f:	8d 55 e8             	lea    edx,[ebp-0x18]
  5b9482:	52                   	push   edx
  5b9483:	6a 00                	push   0x0
  5b9485:	ff d0                	call   eax
  5b9487:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5b948a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b9491:	59                   	pop    ecx
  5b9492:	5f                   	pop    edi
  5b9493:	5e                   	pop    esi
  5b9494:	8b e5                	mov    esp,ebp
  5b9496:	5d                   	pop    ebp
  5b9497:	c3                   	ret
  5b9498:	81         	cmp    ecx,0x6a8
```

### S10 NPC type2 event cancel continuation: VA `0x005B9498..0x005B958A`; raw `0x1B8898..0x1B898A`; 242 bytes; SHA256 `368d8b28d67280fcfca33f9276cf31432289a3b0033852ceca376ba000935ce7`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b9498 <.data+0x1b8898>:
  5b9498:	81 f9 a8 06 00 00    	cmp    ecx,0x6a8
  5b949e:	0f 85 af 00 00 00    	jne    0x5b9553
  5b94a4:	8b 70 18             	mov    esi,DWORD PTR [eax+0x18]
  5b94a7:	85 f6                	test   esi,esi
  5b94a9:	74 20                	je     0x5b94cb
  5b94ab:	8b 16                	mov    edx,DWORD PTR [esi]
  5b94ad:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  5b94b0:	8b ce                	mov    ecx,esi
  5b94b2:	ff d0                	call   eax
  5b94b4:	3d bf 05 01 00       	cmp    eax,0x105bf
  5b94b9:	74 12                	je     0x5b94cd
  5b94bb:	6a 00                	push   0x0
  5b94bd:	68 c0 1f bf 00       	push   0xbf1fc0
  5b94c2:	68 18 21 bf 00       	push   0xbf2118
  5b94c7:	6a 00                	push   0x0
  5b94c9:	ff d7                	call   edi
  5b94cb:	33 f6                	xor    esi,esi
  5b94cd:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  5b94d0:	8b 3d d0 1b fe 00    	mov    edi,DWORD PTR ds:0xfe1bd0
  5b94d6:	8d 55 f0             	lea    edx,[ebp-0x10]
  5b94d9:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  5b94dc:	52                   	push   edx
  5b94dd:	8d 4f 08             	lea    ecx,[edi+0x8]
  5b94e0:	8d 45 e8             	lea    eax,[ebp-0x18]
  5b94e3:	e8 d8 a3 28 00       	call   0x8438c0
  5b94e8:	8b 7f 0c             	mov    edi,DWORD PTR [edi+0xc]
  5b94eb:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  5b94ee:	3b c7                	cmp    eax,edi
  5b94f0:	74 61                	je     0x5b9553
  5b94f2:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  5b94f5:	85 c0                	test   eax,eax
  5b94f7:	74 5a                	je     0x5b9553
  5b94f9:	8b 48 40             	mov    ecx,DWORD PTR [eax+0x40]
  5b94fc:	3b 48 44             	cmp    ecx,DWORD PTR [eax+0x44]
  5b94ff:	74 52                	je     0x5b9553
  5b9501:	6a 1c                	push   0x1c
  5b9503:	e8 60 7d 2d 00       	call   0x891268
  5b9508:	8b f8                	mov    edi,eax
  5b950a:	83 c4 04             	add    esp,0x4
  5b950d:	89 7d e8             	mov    DWORD PTR [ebp-0x18],edi
  5b9510:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  5b9517:	85 ff                	test   edi,edi
  5b9519:	74 18                	je     0x5b9533
  5b951b:	e8 40 5b e5 ff       	call   0x40f060
  5b9520:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  5b9526:	8b 56 14             	mov    edx,DWORD PTR [esi+0x14]
  5b9529:	50                   	push   eax
  5b952a:	8b c7                	mov    eax,edi
  5b952c:	e8 4f aa 19 00       	call   0x753f80
  5b9531:	eb 02                	jmp    0x5b9535
  5b9533:	33 c0                	xor    eax,eax
  5b9535:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5b953c:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  5b953f:	e8 5c b5 e4 ff       	call   0x404aa0
  5b9544:	8d 55 e8             	lea    edx,[ebp-0x18]
  5b9547:	52                   	push   edx
  5b9548:	8d b0 5c 14 00 00    	lea    esi,[eax+0x145c]
  5b954e:	e8 0d ad 24 00       	call   0x804260
  5b9553:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5b9556:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b955d:	59                   	pop    ecx
  5b955e:	5f                   	pop    edi
  5b955f:	5e                   	pop    esi
  5b9560:	8b e5                	mov    esp,ebp
  5b9562:	5d                   	pop    ebp
  5b9563:	c3                   	ret
  5b9564:	cc                   	int3
  5b9565:	cc                   	int3
  5b9566:	cc                   	int3
  5b9567:	cc                   	int3
  5b9568:	cc                   	int3
  5b9569:	cc                   	int3
  5b956a:	cc                   	int3
  5b956b:	cc                   	int3
  5b956c:	cc                   	int3
  5b956d:	cc                   	int3
  5b956e:	cc                   	int3
  5b956f:	cc                   	int3
  5b9570:	55                   	push   ebp
  5b9571:	8b ec                	mov    ebp,esp
  5b9573:	6a ff                	push   0xffffffff
  5b9575:	68 b4 36 93 00       	push   0x9336b4
  5b957a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b9580:	50                   	push   eax
  5b9581:	83 ec 08             	sub    esp,0x8
  5b9584:	53                   	push   ebx
  5b9585:	56                   	push   esi
  5b9586:	57                   	push   edi
  5b9587:	a1 20 1f         	mov    eax,ds:0xd61f20
```

### S11 QuestInfo event mode1 QID lookup: VA `0x005B6C0C..0x005B6D15`; raw `0x1B600C..0x1B6115`; 265 bytes; SHA256 `03df410f66e0db5d90b67bd0a520043dc1aca7b1b765d820bbb2f31f2315bf8b`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b6c0c <.data+0x1b600c>:
  5b6c0c:	8b f1                	mov    esi,ecx
  5b6c0e:	8b fa                	mov    edi,edx
  5b6c10:	85 f6                	test   esi,esi
  5b6c12:	74 26                	je     0x5b6c3a
  5b6c14:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6c16:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6c19:	ff d2                	call   edx
  5b6c1b:	3d b9 05 01 00       	cmp    eax,0x105b9
  5b6c20:	75 04                	jne    0x5b6c26
  5b6c22:	8b de                	mov    ebx,esi
  5b6c24:	eb 16                	jmp    0x5b6c3c
  5b6c26:	6a 00                	push   0x0
  5b6c28:	68 c0 1f bf 00       	push   0xbf1fc0
  5b6c2d:	68 18 21 bf 00       	push   0xbf2118
  5b6c32:	6a 00                	push   0x0
  5b6c34:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6c3a:	33 db                	xor    ebx,ebx
  5b6c3c:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b6c43:	75 29                	jne    0x5b6c6e
  5b6c45:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b6c4c:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  5b6c53:	00 
  5b6c54:	e8 07 92 f4 ff       	call   0x4ffe60
  5b6c59:	68 00 cf bc 00       	push   0xbccf00
  5b6c5e:	e8 b7 b6 2d 00       	call   0x89231a
  5b6c63:	83 c4 04             	add    esp,0x4
  5b6c66:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6c6d:	ff 
  5b6c6e:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  5b6c71:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  5b6c77:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  5b6c7b:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5b6c7f:	51                   	push   ecx
  5b6c80:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b6c84:	8b ce                	mov    ecx,esi
  5b6c86:	e8 95 d0 f4 ff       	call   0x503d20
  5b6c8b:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5b6c8e:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5b6c92:	3b c6                	cmp    eax,esi
  5b6c94:	74 6c                	je     0x5b6d02
  5b6c96:	8d 70 10             	lea    esi,[eax+0x10]
  5b6c99:	85 f6                	test   esi,esi
  5b6c9b:	74 65                	je     0x5b6d02
  5b6c9d:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5b6ca4:	75 29                	jne    0x5b6ccf
  5b6ca6:	b8 01 00 00 00       	mov    eax,0x1
  5b6cab:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5b6cb1:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5b6cb5:	e8 d6 7f f2 ff       	call   0x4dec90
  5b6cba:	68 30 ce bc 00       	push   0xbcce30
  5b6cbf:	e8 56 b6 2d 00       	call   0x89231a
  5b6cc4:	83 c4 04             	add    esp,0x4
  5b6cc7:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6cce:	ff 
  5b6ccf:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6cd2:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6cd7:	8b 4e 28             	mov    ecx,DWORD PTR [esi+0x28]
  5b6cda:	52                   	push   edx
  5b6cdb:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6ce1:	6a 01                	push   0x1
  5b6ce3:	50                   	push   eax
  5b6ce4:	e8 37 f8 07 00       	call   0x636520
  5b6ce9:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6cef:	51                   	push   ecx
  5b6cf0:	e8 1b 33 19 00       	call   0x74a010
  5b6cf5:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6cfb:	52                   	push   edx
  5b6cfc:	57                   	push   edi
  5b6cfd:	e8 fe 00 fe ff       	call   0x596e00
  5b6d02:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5b6d06:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b6d0d:	59                   	pop    ecx
  5b6d0e:	5f                   	pop    edi
  5b6d0f:	5e                   	pop    esi
  5b6d10:	5b                   	pop    ebx
  5b6d11:	8b e5                	mov    esp,ebp
  5b6d13:	5d                   	pop    ebp
  5b6d14:	c3                   	ret
```

### S12 QuestInfo mode2 and mode3: VA `0x005B6D4C..0x005B6F95`; raw `0x1B614C..0x1B6395`; 585 bytes; SHA256 `21f7412ab09ed7e07c8809b713fbfc60e07e257aa8ae65deaa1d8b6149b8a6fa`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b6d4c <.data+0x1b614c>:
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
  5b6d7c:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b6d83:	75 29                	jne    0x5b6dae
  5b6d85:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b6d8c:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  5b6d93:	00 
  5b6d94:	e8 c7 90 f4 ff       	call   0x4ffe60
  5b6d99:	68 00 cf bc 00       	push   0xbccf00
  5b6d9e:	e8 77 b5 2d 00       	call   0x89231a
  5b6da3:	83 c4 04             	add    esp,0x4
  5b6da6:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6dad:	ff 
  5b6dae:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  5b6db1:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  5b6db7:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  5b6dbb:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5b6dbf:	51                   	push   ecx
  5b6dc0:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b6dc4:	8b ce                	mov    ecx,esi
  5b6dc6:	e8 55 cf f4 ff       	call   0x503d20
  5b6dcb:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5b6dce:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5b6dd2:	3b c6                	cmp    eax,esi
  5b6dd4:	74 6c                	je     0x5b6e42
  5b6dd6:	8d 70 10             	lea    esi,[eax+0x10]
  5b6dd9:	85 f6                	test   esi,esi
  5b6ddb:	74 65                	je     0x5b6e42
  5b6ddd:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5b6de4:	75 29                	jne    0x5b6e0f
  5b6de6:	b8 01 00 00 00       	mov    eax,0x1
  5b6deb:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5b6df1:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5b6df5:	e8 96 7e f2 ff       	call   0x4dec90
  5b6dfa:	68 30 ce bc 00       	push   0xbcce30
  5b6dff:	e8 16 b5 2d 00       	call   0x89231a
  5b6e04:	83 c4 04             	add    esp,0x4
  5b6e07:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6e0e:	ff 
  5b6e0f:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6e12:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6e17:	8b 4e 28             	mov    ecx,DWORD PTR [esi+0x28]
  5b6e1a:	52                   	push   edx
  5b6e1b:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6e21:	6a 02                	push   0x2
  5b6e23:	50                   	push   eax
  5b6e24:	e8 f7 f6 07 00       	call   0x636520
  5b6e29:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6e2f:	51                   	push   ecx
  5b6e30:	e8 db 31 19 00       	call   0x74a010
  5b6e35:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6e3b:	52                   	push   edx
  5b6e3c:	57                   	push   edi
  5b6e3d:	e8 be ff fd ff       	call   0x596e00
  5b6e42:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5b6e46:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b6e4d:	59                   	pop    ecx
  5b6e4e:	5f                   	pop    edi
  5b6e4f:	5e                   	pop    esi
  5b6e50:	5b                   	pop    ebx
  5b6e51:	8b e5                	mov    esp,ebp
  5b6e53:	5d                   	pop    ebp
  5b6e54:	c3                   	ret
  5b6e55:	cc                   	int3
  5b6e56:	cc                   	int3
  5b6e57:	cc                   	int3
  5b6e58:	cc                   	int3
  5b6e59:	cc                   	int3
  5b6e5a:	cc                   	int3
  5b6e5b:	cc                   	int3
  5b6e5c:	cc                   	int3
  5b6e5d:	cc                   	int3
  5b6e5e:	cc                   	int3
  5b6e5f:	cc                   	int3
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
  5b6ead:	68 18 21 bf 00       	push   0xbf2118
  5b6eb2:	6a 00                	push   0x0
  5b6eb4:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6eba:	33 db                	xor    ebx,ebx
  5b6ebc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b6ec3:	75 29                	jne    0x5b6eee
  5b6ec5:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b6ecc:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  5b6ed3:	00 
  5b6ed4:	e8 87 8f f4 ff       	call   0x4ffe60
  5b6ed9:	68 00 cf bc 00       	push   0xbccf00
  5b6ede:	e8 37 b4 2d 00       	call   0x89231a
  5b6ee3:	83 c4 04             	add    esp,0x4
  5b6ee6:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6eed:	ff 
  5b6eee:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  5b6ef1:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  5b6ef7:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  5b6efb:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5b6eff:	51                   	push   ecx
  5b6f00:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b6f04:	8b ce                	mov    ecx,esi
  5b6f06:	e8 15 ce f4 ff       	call   0x503d20
  5b6f0b:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5b6f0e:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5b6f12:	3b c6                	cmp    eax,esi
  5b6f14:	74 6c                	je     0x5b6f82
  5b6f16:	8d 70 10             	lea    esi,[eax+0x10]
  5b6f19:	85 f6                	test   esi,esi
  5b6f1b:	74 65                	je     0x5b6f82
  5b6f1d:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5b6f24:	75 29                	jne    0x5b6f4f
  5b6f26:	b8 01 00 00 00       	mov    eax,0x1
  5b6f2b:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5b6f31:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5b6f35:	e8 56 7d f2 ff       	call   0x4dec90
  5b6f3a:	68 30 ce bc 00       	push   0xbcce30
  5b6f3f:	e8 d6 b3 2d 00       	call   0x89231a
  5b6f44:	83 c4 04             	add    esp,0x4
  5b6f47:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6f4e:	ff 
  5b6f4f:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6f52:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6f57:	8b 4e 2c             	mov    ecx,DWORD PTR [esi+0x2c]
  5b6f5a:	52                   	push   edx
  5b6f5b:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6f61:	6a 03                	push   0x3
  5b6f63:	50                   	push   eax
  5b6f64:	e8 b7 f5 07 00       	call   0x636520
  5b6f69:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6f6f:	51                   	push   ecx
  5b6f70:	e8 9b 30 19 00       	call   0x74a010
  5b6f75:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6f7b:	52                   	push   edx
  5b6f7c:	57                   	push   edi
  5b6f7d:	e8 7e fe fd ff       	call   0x596e00
  5b6f82:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5b6f86:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b6f8d:	59                   	pop    ecx
  5b6f8e:	5f                   	pop    edi
  5b6f8f:	5e                   	pop    esi
  5b6f90:	5b                   	pop    ebx
  5b6f91:	8b e5                	mov    esp,ebp
  5b6f93:	5d                   	pop    ebp
  5b6f94:	c3                   	ret
```

### S13 TalkBox selected record + actual C2S: VA `0x00636DE0..0x00636ED0`; raw `0x2361E0..0x2362D0`; 240 bytes; SHA256 `a385b5b3240f2f9586c8895779d8a6b3db4ca4932109ea896376319dc518b067`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636de0 <.data+0x2361e0>:
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

### S14 NPC context conditional UI query by selected: VA `0x00636050..0x00636171`; raw `0x235450..0x235571`; 289 bytes; SHA256 `4496da76408aa936ca5e39e75869b735ca005de654fcfcd173ff4cb02428bc9f`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636050 <.data+0x235450>:
  636050:	55                   	push   ebp
  636051:	8b ec                	mov    ebp,esp
  636053:	6a ff                	push   0xffffffff
  636055:	68 6c 64 94 00       	push   0x94646c
  63605a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  636060:	50                   	push   eax
  636061:	83 ec 58             	sub    esp,0x58
  636064:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  636069:	33 c5                	xor    eax,ebp
  63606b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  63606e:	53                   	push   ebx
  63606f:	56                   	push   esi
  636070:	57                   	push   edi
  636071:	50                   	push   eax
  636072:	8d 45 f4             	lea    eax,[ebp-0xc]
  636075:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  63607b:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  63607e:	83 bb ac 00 00 00 01 	cmp    DWORD PTR [ebx+0xac],0x1
  636085:	76 12                	jbe    0x636099
  636087:	8b 8b bc 00 00 00    	mov    ecx,DWORD PTR [ebx+0xbc]
  63608d:	8b 01                	mov    eax,DWORD PTR [ecx]
  63608f:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  636092:	ff d2                	call   edx
  636094:	e9 d2 00 00 00       	jmp    0x63616b
  636099:	8b 83 90 00 00 00    	mov    eax,DWORD PTR [ebx+0x90]
  63609f:	85 c0                	test   eax,eax
  6360a1:	75 46                	jne    0x6360e9
  6360a3:	8b 8b bc 00 00 00    	mov    ecx,DWORD PTR [ebx+0xbc]
  6360a9:	8b 01                	mov    eax,DWORD PTR [ecx]
  6360ab:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  6360ae:	ff d2                	call   edx
  6360b0:	8b 83 94 00 00 00    	mov    eax,DWORD PTR [ebx+0x94]
  6360b6:	8b 48 18             	mov    ecx,DWORD PTR [eax+0x18]
  6360b9:	2b 48 14             	sub    ecx,DWORD PTR [eax+0x14]
  6360bc:	8b 93 98 00 00 00    	mov    edx,DWORD PTR [ebx+0x98]
  6360c2:	c1 f9 02             	sar    ecx,0x2
  6360c5:	42                   	inc    edx
  6360c6:	3b d1                	cmp    edx,ecx
  6360c8:	8b 8b bc 00 00 00    	mov    ecx,DWORD PTR [ebx+0xbc]
  6360ce:	8b 01                	mov    eax,DWORD PTR [ecx]
  6360d0:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  6360d3:	6a 01                	push   0x1
  6360d5:	7c 09                	jl     0x6360e0
  6360d7:	6a 00                	push   0x0
  6360d9:	ff d2                	call   edx
  6360db:	e9 8b 00 00 00       	jmp    0x63616b
  6360e0:	6a 01                	push   0x1
  6360e2:	ff d2                	call   edx
  6360e4:	e9 82 00 00 00       	jmp    0x63616b
  6360e9:	83 f8 01             	cmp    eax,0x1
  6360ec:	75 0f                	jne    0x6360fd
  6360ee:	8b 8b bc 00 00 00    	mov    ecx,DWORD PTR [ebx+0xbc]
  6360f4:	8b 01                	mov    eax,DWORD PTR [ecx]
  6360f6:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  6360f9:	ff d2                	call   edx
  6360fb:	eb 6e                	jmp    0x63616b
  6360fd:	83 f8 02             	cmp    eax,0x2
  636100:	75 0d                	jne    0x63610f
  636102:	8b 83 bc 00 00 00    	mov    eax,DWORD PTR [ebx+0xbc]
  636108:	e8 d3 2f 00 00       	call   0x6390e0
  63610d:	eb 5c                	jmp    0x63616b
  63610f:	83 f8 03             	cmp    eax,0x3
  636112:	75 39                	jne    0x63614d
  636114:	8b 83 88 00 00 00    	mov    eax,DWORD PTR [ebx+0x88]
  63611a:	85 c0                	test   eax,eax
  63611c:	74 e4                	je     0x636102
  63611e:	8b 00                	mov    eax,DWORD PTR [eax]
  636120:	50                   	push   eax
  636121:	51                   	push   ecx
  636122:	e8 09 98 dd ff       	call   0x40f930
  636127:	8b 8b 84 00 00 00    	mov    ecx,DWORD PTR [ebx+0x84]
  63612d:	83 c4 04             	add    esp,0x4
  636130:	8b d0                	mov    edx,eax
  636132:	e8 99 a6 ec ff       	call   0x5007d0
  636137:	0f b7 c0             	movzx  eax,ax
  63613a:	85 c0                	test   eax,eax
  63613c:	74 c4                	je     0x636102
  63613e:	8b 8b bc 00 00 00    	mov    ecx,DWORD PTR [ebx+0xbc]
  636144:	8b 11                	mov    edx,DWORD PTR [ecx]
  636146:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  636149:	ff d0                	call   eax
  63614b:	eb 1e                	jmp    0x63616b
  63614d:	8b 8b bc 00 00 00    	mov    ecx,DWORD PTR [ebx+0xbc]
  636153:	8b 11                	mov    edx,DWORD PTR [ecx]
  636155:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  636158:	ff d0                	call   eax
  63615a:	8b 8b bc 00 00 00    	mov    ecx,DWORD PTR [ebx+0xbc]
  636160:	8b 11                	mov    edx,DWORD PTR [ecx]
  636162:	8b 42 0c             	mov    eax,DWORD PTR [edx+0xc]
  636165:	6a 01                	push   0x1
  636167:	6a 01                	push   0x1
  636169:	ff d0                	call   eax
  63616b:	83 bb b8 00 00 00  	cmp    DWORD PTR [ebx+0xb8],0x0
```

### S15 TalkBox conditional 0x5007d0 event route: VA `0x00636C80..0x00636D00`; raw `0x236080..0x236100`; 128 bytes; SHA256 `e63b722d29da9fea52be86fd7b60ba2d244cef8ff7667b1d0c9e4091f01c92c2`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636c80 <.data+0x236080>:
  636c80:	12 00                	adc    al,BYTE PTR [eax]
  636c82:	eb 76                	jmp    0x636cfa
  636c84:	83 f8 03             	cmp    eax,0x3
  636c87:	75 71                	jne    0x636cfa
  636c89:	8b 87 88 00 00 00    	mov    eax,DWORD PTR [edi+0x88]
  636c8f:	3b c3                	cmp    eax,ebx
  636c91:	74 67                	je     0x636cfa
  636c93:	8b 10                	mov    edx,DWORD PTR [eax]
  636c95:	52                   	push   edx
  636c96:	51                   	push   ecx
  636c97:	e8 94 8c dd ff       	call   0x40f930
  636c9c:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  636ca2:	83 c4 04             	add    esp,0x4
  636ca5:	8b d0                	mov    edx,eax
  636ca7:	e8 24 9b ec ff       	call   0x5007d0
  636cac:	0f b7 f0             	movzx  esi,ax
  636caf:	85 f6                	test   esi,esi
  636cb1:	74 47                	je     0x636cfa
  636cb3:	6a 18                	push   0x18
  636cb5:	e8 ae a5 25 00       	call   0x891268
  636cba:	83 c4 04             	add    esp,0x4
  636cbd:	85 c0                	test   eax,eax
  636cbf:	74 1e                	je     0x636cdf
  636cc1:	83 c9 ff             	or     ecx,0xffffffff
  636cc4:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  636cc7:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  636cca:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  636ccd:	c7 40 10 8a 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf438a
  636cd4:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  636cda:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  636cdd:	eb 02                	jmp    0x636ce1
  636cdf:	33 c0                	xor    eax,eax
  636ce1:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  636ce5:	e8 b6 dd dc ff       	call   0x404aa0
  636cea:	8d 4c 24 0c          	lea    ecx,[esp+0xc]
  636cee:	51                   	push   ecx
  636cef:	8d b0 5c 14 00 00    	lea    esi,[eax+0x145c]
  636cf5:	e8 66 d5 1c 00       	call   0x804260
  636cfa:	8b 8c 24 88 00 00  	mov    ecx,DWORD PTR [esp+0x88]
```

### S16 QuestOwner S2C index64 callback header: VA `0x00502270..0x005023D9`; raw `0x101670..0x1017D9`; 361 bytes; SHA256 `9061a5d2e87eba84d82c964f826f6652ba3c57b6c7f969f8e5c1fe83791834a2`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00502270 <.data+0x101670>:
  502270:	55                   	push   ebp
  502271:	8b ec                	mov    ebp,esp
  502273:	6a ff                	push   0xffffffff
  502275:	68 a8 41 94 00       	push   0x9441a8
  50227a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  502280:	50                   	push   eax
  502281:	81 ec a4 00 00 00    	sub    esp,0xa4
  502287:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50228c:	33 c5                	xor    eax,ebp
  50228e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  502291:	53                   	push   ebx
  502292:	56                   	push   esi
  502293:	57                   	push   edi
  502294:	50                   	push   eax
  502295:	8d 45 f4             	lea    eax,[ebp-0xc]
  502298:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  50229e:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  5022a1:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  5022a4:	33 ff                	xor    edi,edi
  5022a6:	89 8d 54 ff ff ff    	mov    DWORD PTR [ebp-0xac],ecx
  5022ac:	3b c7                	cmp    eax,edi
  5022ae:	0f 85 16 04 00 00    	jne    0x5026ca
  5022b4:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  5022bb:	75 24                	jne    0x5022e1
  5022bd:	83 0d d4 ad fa 00 01 	or     DWORD PTR ds:0xfaadd4,0x1
  5022c4:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  5022c7:	e8 b4 51 08 00       	call   0x587480
  5022cc:	68 c0 cc bc 00       	push   0xbcccc0
  5022d1:	e8 44 00 39 00       	call   0x89231a
  5022d6:	83 c4 04             	add    esp,0x4
  5022d9:	83 ce ff             	or     esi,0xffffffff
  5022dc:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5022df:	eb 03                	jmp    0x5022e4
  5022e1:	83 ce ff             	or     esi,0xffffffff
  5022e4:	6a 18                	push   0x18
  5022e6:	e8 7d ef 38 00       	call   0x891268
  5022eb:	83 c4 04             	add    esp,0x4
  5022ee:	3b c7                	cmp    eax,edi
  5022f0:	74 1e                	je     0x502310
  5022f2:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  5022f5:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  5022f8:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  5022fb:	89 78 0c             	mov    DWORD PTR [eax+0xc],edi
  5022fe:	c7 40 10 81 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf4281
  502305:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50230b:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  50230e:	eb 02                	jmp    0x502312
  502310:	33 c0                	xor    eax,eax
  502312:	50                   	push   eax
  502313:	e8 38 87 08 00       	call   0x58aa50
  502318:	83 c4 04             	add    esp,0x4
  50231b:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  502322:	75 23                	jne    0x502347
  502324:	b8 01 00 00 00       	mov    eax,0x1
  502329:	09 05 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,eax
  50232f:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  502332:	e8 49 51 08 00       	call   0x587480
  502337:	68 c0 cc bc 00       	push   0xbcccc0
  50233c:	e8 d9 ff 38 00       	call   0x89231a
  502341:	83 c4 04             	add    esp,0x4
  502344:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  502347:	6a 18                	push   0x18
  502349:	e8 1a ef 38 00       	call   0x891268
  50234e:	83 c4 04             	add    esp,0x4
  502351:	3b c7                	cmp    eax,edi
  502353:	74 1f                	je     0x502374
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
  50237c:	0f b7 73 02          	movzx  esi,WORD PTR [ebx+0x2]
  502380:	8b bd 54 ff ff ff    	mov    edi,DWORD PTR [ebp-0xac]
  502386:	83 c4 04             	add    esp,0x4
  502389:	e8 82 dd ff ff       	call   0x500110
  50238e:	e8 cd cc f0 ff       	call   0x40f060
  502393:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  502399:	50                   	push   eax
  50239a:	8b f7                	mov    esi,edi
  50239c:	56                   	push   esi
  50239d:	e8 9e de ff ff       	call   0x500240
  5023a2:	0f b7 7b 02          	movzx  edi,WORD PTR [ebx+0x2]
  5023a6:	8b b6 ac 5e 00 00    	mov    esi,DWORD PTR [esi+0x5eac]
  5023ac:	8d 85 54 ff ff ff    	lea    eax,[ebp-0xac]
  5023b2:	50                   	push   eax
  5023b3:	8d 85 50 ff ff ff    	lea    eax,[ebp-0xb0]
  5023b9:	8b ce                	mov    ecx,esi
  5023bb:	89 bd 54 ff ff ff    	mov    DWORD PTR [ebp-0xac],edi
  5023c1:	e8 5a 19 00 00       	call   0x503d20
  5023c6:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5023c9:	8b 85 50 ff ff ff    	mov    eax,DWORD PTR [ebp-0xb0]
  5023cf:	3b c6                	cmp    eax,esi
  5023d1:	0f 84 d5 03 00 00    	je     0x5027ac
  5023d7:	8d 58              	lea    ebx,[eax+0x10]
```

### S17 QuestOwner index64 local event, rebuild: VA `0x005022E4..0x0050243B`; raw `0x1016E4..0x10183B`; 343 bytes; SHA256 `17c022c047afe6bf776afd97650c08cdcb1fd532888a650ed1f34f30f00a0a21`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005022e4 <.data+0x1016e4>:
  5022e4:	6a 18                	push   0x18
  5022e6:	e8 7d ef 38 00       	call   0x891268
  5022eb:	83 c4 04             	add    esp,0x4
  5022ee:	3b c7                	cmp    eax,edi
  5022f0:	74 1e                	je     0x502310
  5022f2:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  5022f5:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  5022f8:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  5022fb:	89 78 0c             	mov    DWORD PTR [eax+0xc],edi
  5022fe:	c7 40 10 81 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf4281
  502305:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  50230b:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  50230e:	eb 02                	jmp    0x502312
  502310:	33 c0                	xor    eax,eax
  502312:	50                   	push   eax
  502313:	e8 38 87 08 00       	call   0x58aa50
  502318:	83 c4 04             	add    esp,0x4
  50231b:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  502322:	75 23                	jne    0x502347
  502324:	b8 01 00 00 00       	mov    eax,0x1
  502329:	09 05 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,eax
  50232f:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  502332:	e8 49 51 08 00       	call   0x587480
  502337:	68 c0 cc bc 00       	push   0xbcccc0
  50233c:	e8 d9 ff 38 00       	call   0x89231a
  502341:	83 c4 04             	add    esp,0x4
  502344:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  502347:	6a 18                	push   0x18
  502349:	e8 1a ef 38 00       	call   0x891268
  50234e:	83 c4 04             	add    esp,0x4
  502351:	3b c7                	cmp    eax,edi
  502353:	74 1f                	je     0x502374
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
  50237c:	0f b7 73 02          	movzx  esi,WORD PTR [ebx+0x2]
  502380:	8b bd 54 ff ff ff    	mov    edi,DWORD PTR [ebp-0xac]
  502386:	83 c4 04             	add    esp,0x4
  502389:	e8 82 dd ff ff       	call   0x500110
  50238e:	e8 cd cc f0 ff       	call   0x40f060
  502393:	8b 80 8c 00 00 00    	mov    eax,DWORD PTR [eax+0x8c]
  502399:	50                   	push   eax
  50239a:	8b f7                	mov    esi,edi
  50239c:	56                   	push   esi
  50239d:	e8 9e de ff ff       	call   0x500240
  5023a2:	0f b7 7b 02          	movzx  edi,WORD PTR [ebx+0x2]
  5023a6:	8b b6 ac 5e 00 00    	mov    esi,DWORD PTR [esi+0x5eac]
  5023ac:	8d 85 54 ff ff ff    	lea    eax,[ebp-0xac]
  5023b2:	50                   	push   eax
  5023b3:	8d 85 50 ff ff ff    	lea    eax,[ebp-0xb0]
  5023b9:	8b ce                	mov    ecx,esi
  5023bb:	89 bd 54 ff ff ff    	mov    DWORD PTR [ebp-0xac],edi
  5023c1:	e8 5a 19 00 00       	call   0x503d20
  5023c6:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5023c9:	8b 85 50 ff ff ff    	mov    eax,DWORD PTR [ebp-0xb0]
  5023cf:	3b c6                	cmp    eax,esi
  5023d1:	0f 84 d5 03 00 00    	je     0x5027ac
  5023d7:	8d 58 10             	lea    ebx,[eax+0x10]
  5023da:	85 db                	test   ebx,ebx
  5023dc:	0f 84 ca 03 00 00    	je     0x5027ac
  5023e2:	8b 43 3c             	mov    eax,DWORD PTR [ebx+0x3c]
  5023e5:	83 e8 02             	sub    eax,0x2
  5023e8:	74 51                	je     0x50243b
  5023ea:	48                   	dec    eax
  5023eb:	75 5f                	jne    0x50244c
  5023ed:	e8 ce 30 f0 ff       	call   0x4054c0
  5023f2:	6a 18                	push   0x18
  5023f4:	e8 6f ee 38 00       	call   0x891268
  5023f9:	83 c4 04             	add    esp,0x4
  5023fc:	85 c0                	test   eax,eax
  5023fe:	74 2e                	je     0x50242e
  502400:	8b 4b 40             	mov    ecx,DWORD PTR [ebx+0x40]
  502403:	83 ca ff             	or     edx,0xffffffff
  502406:	50                   	push   eax
  502407:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  50240a:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  50240d:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  502414:	c7 40 10 06 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf4306
  50241b:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  502421:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  502424:	e8 27 86 08 00       	call   0x58aa50
  502429:	e9 7b 03 00 00       	jmp    0x5027a9
  50242e:	33 c0                	xor    eax,eax
  502430:	50                   	push   eax
  502431:	e8 1a 86 08 00       	call   0x58aa50
  502436:	e9 6e 03 00 00       	jmp    0x5027a9
```

### S18 QuestOwner index64 alternate status path: VA `0x005026CA..0x005027CC`; raw `0x101ACA..0x101BCC`; 258 bytes; SHA256 `c69ece0370a485f1de335936ac7c17ec185cc0c05dc59bcc825e558734615976`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005026ca <.data+0x101aca>:
  5026ca:	83 f8 01             	cmp    eax,0x1
  5026cd:	0f 85 d9 00 00 00    	jne    0x5027ac
  5026d3:	0f b7 53 02          	movzx  edx,WORD PTR [ebx+0x2]
  5026d7:	8b b1 ac 5e 00 00    	mov    esi,DWORD PTR [ecx+0x5eac]
  5026dd:	8d 85 50 ff ff ff    	lea    eax,[ebp-0xb0]
  5026e3:	50                   	push   eax
  5026e4:	8d 85 54 ff ff ff    	lea    eax,[ebp-0xac]
  5026ea:	8b ce                	mov    ecx,esi
  5026ec:	89 95 50 ff ff ff    	mov    DWORD PTR [ebp-0xb0],edx
  5026f2:	e8 29 16 00 00       	call   0x503d20
  5026f7:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5026fa:	8b 85 54 ff ff ff    	mov    eax,DWORD PTR [ebp-0xac]
  502700:	3b c6                	cmp    eax,esi
  502702:	0f 84 a4 00 00 00    	je     0x5027ac
  502708:	83 c0 10             	add    eax,0x10
  50270b:	3b c7                	cmp    eax,edi
  50270d:	0f 84 99 00 00 00    	je     0x5027ac
  502713:	bb 08 00 00 00       	mov    ebx,0x8
  502718:	39 58 60             	cmp    DWORD PTR [eax+0x60],ebx
  50271b:	72 05                	jb     0x502722
  50271d:	8b 78 4c             	mov    edi,DWORD PTR [eax+0x4c]
  502720:	eb 03                	jmp    0x502725
  502722:	8d 78 4c             	lea    edi,[eax+0x4c]
  502725:	6a 12                	push   0x12
  502727:	e8 84 2e 08 00       	call   0x5855b0
  50272c:	8b f0                	mov    esi,eax
  50272e:	e8 fd 2b 08 00       	call   0x585330
  502733:	8b cf                	mov    ecx,edi
  502735:	8d b5 58 ff ff ff    	lea    esi,[ebp-0xa8]
  50273b:	e8 d0 ae fe ff       	call   0x4ed610
  502740:	c7 45 fc 06 00 00 00 	mov    DWORD PTR [ebp-0x4],0x6
  502747:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  50274a:	72 02                	jb     0x50274e
  50274c:	8b 00                	mov    eax,DWORD PTR [eax]
  50274e:	50                   	push   eax
  50274f:	8d 4d 90             	lea    ecx,[ebp-0x70]
  502752:	e8 f9 fa ef ff       	call   0x402250
  502757:	8d 4d 90             	lea    ecx,[ebp-0x70]
  50275a:	bb 07 00 00 00       	mov    ebx,0x7
  50275f:	51                   	push   ecx
  502760:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  502763:	e8 58 d1 f0 ff       	call   0x40f8c0
  502768:	8b f8                	mov    edi,eax
  50276a:	e8 c1 43 fd ff       	call   0x4d6b30
  50276f:	be 08 00 00 00       	mov    esi,0x8
  502774:	39 75 a4             	cmp    DWORD PTR [ebp-0x5c],esi
  502777:	72 0c                	jb     0x502785
  502779:	8b 55 90             	mov    edx,DWORD PTR [ebp-0x70]
  50277c:	52                   	push   edx
  50277d:	e8 8a ea 38 00       	call   0x89120c
  502782:	83 c4 04             	add    esp,0x4
  502785:	33 c0                	xor    eax,eax
  502787:	89 5d a4             	mov    DWORD PTR [ebp-0x5c],ebx
  50278a:	c7 45 a0 00 00 00 00 	mov    DWORD PTR [ebp-0x60],0x0
  502791:	66 89 45 90          	mov    WORD PTR [ebp-0x70],ax
  502795:	39 b5 6c ff ff ff    	cmp    DWORD PTR [ebp-0x94],esi
  50279b:	72 0f                	jb     0x5027ac
  50279d:	8b 8d 58 ff ff ff    	mov    ecx,DWORD PTR [ebp-0xa8]
  5027a3:	51                   	push   ecx
  5027a4:	e8 63 ea 38 00       	call   0x89120c
  5027a9:	83 c4 04             	add    esp,0x4
  5027ac:	33 c0                	xor    eax,eax
  5027ae:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5027b1:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5027b8:	59                   	pop    ecx
  5027b9:	5f                   	pop    edi
  5027ba:	5e                   	pop    esi
  5027bb:	5b                   	pop    ebx
  5027bc:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  5027bf:	33 cd                	xor    ecx,ebp
  5027c1:	e8 3b e8 38 00       	call   0x891001
  5027c6:	8b e5                	mov    esp,ebp
  5027c8:	5d                   	pop    ebp
  5027c9:	c2 0c 00             	ret    0xc
```

### S19 Q16 type2 consumer 0x500A80 caller control A: VA `0x004D23F0..0x004D2440`; raw `0xD17F0..0xD1840`; 80 bytes; SHA256 `fc1bcf97900e777318887465fad93f0c97fb79f00de60169bf20e1e492581e1f`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004d23f0 <.data+0xd17f0>:
  4d23f0:	00 d8                	add    al,bl
  4d23f2:	45                   	inc    ebp
  4d23f3:	ec                   	in     al,dx
  4d23f4:	d9 5d ec             	fstp   DWORD PTR [ebp-0x14]
  4d23f7:	75 23                	jne    0x4d241c
  4d23f9:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4d2400:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4d2403:	e8 58 da 02 00       	call   0x4ffe60
  4d2408:	68 00 cf bc 00       	push   0xbccf00
  4d240d:	e8 08 ff 3b 00       	call   0x89231a
  4d2412:	83 c4 04             	add    esp,0x4
  4d2415:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4d241c:	56                   	push   esi
  4d241d:	68 a0 b2 fa 00       	push   0xfab2a0
  4d2422:	e8 59 e6 02 00       	call   0x500a80
  4d2427:	83 f8 06             	cmp    eax,0x6
  4d242a:	0f 87 b0 03 00 00    	ja     0x4d27e0
  4d2430:	ff 24 85 00 28 4d 00 	jmp    DWORD PTR [eax*4+0x4d2800]
  4d2437:	8b 83 20 04 00 00    	mov    eax,DWORD PTR [ebx+0x420]
  4d243d:	3b c7                	cmp    eax,edi
  4d243f:	74                 	je     0x4d2469
```

### S20 Q16 type2 consumer caller control B: VA `0x0054008F..0x005400C5`; raw `0x13F48F..0x13F4C5`; 54 bytes; SHA256 `24ef44333f04751566081499f03864203ede2a75d1cb60e1de4ddc5dea28c6d9`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0054008f <.data+0x13f48f>:
  54008f:	22 35 00 83 c4 04    	and    dh,BYTE PTR ds:0x4c48300
  540095:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  54009c:	ff 
  54009d:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  5400a0:	52                   	push   edx
  5400a1:	68 a0 b2 fa 00       	push   0xfab2a0
  5400a6:	e8 d5 09 fc ff       	call   0x500a80
  5400ab:	83 f8 05             	cmp    eax,0x5
  5400ae:	0f 87 1e 01 00 00    	ja     0x5401d2
  5400b4:	ff 24 85 f4 01 54 00 	jmp    DWORD PTR [eax*4+0x5401f4]
  5400bb:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  5400be:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  5400c1:	2b 01                	sub    eax,DWORD PTR [ecx]
  5400c3:	a9 fc          	test   eax,0xfffffffc
```

### S21 Q16 type2 consumer caller control C: VA `0x00544150..0x00544180`; raw `0x143550..0x143580`; 48 bytes; SHA256 `1c822ee51bd481a2dc85da348e7c899d6cac151ea511ee87648616d32b725232`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00544150 <.data+0x143550>:
  544150:	00 83 c4 04 c7 44    	add    BYTE PTR [ebx+0x44c704c4],al
  544156:	24 28                	and    al,0x28
  544158:	ff                   	(bad)
  544159:	ff                   	(bad)
  54415a:	ff                   	(bad)
  54415b:	ff 57 68             	call   DWORD PTR [edi+0x68]
  54415e:	a0 b2 fa 00 e8       	mov    al,ds:0xe800fab2
  544163:	19 c9                	sbb    ecx,ecx
  544165:	fb                   	sti
  544166:	ff 83 f8 05 74 7b    	inc    DWORD PTR [ebx+0x7b7405f8]
  54416c:	8b 35 d0 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1bd0
  544172:	8d 44 24 14          	lea    eax,[esp+0x14]
  544176:	50                   	push   eax
  544177:	8d 4e 08             	lea    ecx,[esi+0x8]
  54417a:	8d 44 24 14          	lea    eax,[esp+0x14]
  54417e:	89 7c            	mov    DWORD PTR [esp+0x18],edi
```

### S22 Q16 type2 consumer caller control D: VA `0x0056D080..0x0056D0B0`; raw `0x16C480..0x16C4B0`; 48 bytes; SHA256 `47195f2af687b1ebc20d0de7f61bdf8ffaf44753091f877dd1e34d64f7e1ac4f`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0056d080 <.data+0x16c480>:
  56d080:	00 e8                	add    al,ch
  56d082:	94                   	xchg   esp,eax
  56d083:	52                   	push   edx
  56d084:	32 00                	xor    al,BYTE PTR [eax]
  56d086:	83 c4 04             	add    esp,0x4
  56d089:	c7 84 24 08 01 00 00 	mov    DWORD PTR [esp+0x108],0xffffffff
  56d090:	ff ff ff ff 
  56d094:	53                   	push   ebx
  56d095:	68 a0 b2 fa 00       	push   0xfab2a0
  56d09a:	e8 e1 39 f9 ff       	call   0x500a80
  56d09f:	83 f8 06             	cmp    eax,0x6
  56d0a2:	0f 87 b5 0c 00 00    	ja     0x56dd5d
  56d0a8:	ff 24 85 d0 dd 56 00 	jmp    DWORD PTR [eax*4+0x56ddd0]
  56d0af:	6a                 	push   0x48
```

### S23 UI type1 flags (counterexample): VA `0x00635D18..0x00635D8B`; raw `0x235118..0x23518B`; 115 bytes; SHA256 `97546bb12c5bc0bdf9b0263123f2b698524ccba834f153e77ce2dcf4ce8af869`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00635d18 <.data+0x235118>:
  635d18:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  635d1e:	8d 45 b4             	lea    eax,[ebp-0x4c]
  635d21:	50                   	push   eax
  635d22:	51                   	push   ecx
  635d23:	68 a0 b2 fa 00       	push   0xfab2a0
  635d28:	e8 23 ac ec ff       	call   0x500950
  635d2d:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  635d34:	75 21                	jne    0x635d57
  635d36:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  635d3d:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  635d41:	e8 1a a1 ec ff       	call   0x4ffe60
  635d46:	68 00 cf bc 00       	push   0xbccf00
  635d4b:	e8 ca c5 25 00       	call   0x89231a
  635d50:	83 c4 04             	add    esp,0x4
  635d53:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635d57:	8b 87 84 00 00 00    	mov    eax,DWORD PTR [edi+0x84]
  635d5d:	8d 55 c4             	lea    edx,[ebp-0x3c]
  635d60:	52                   	push   edx
  635d61:	50                   	push   eax
  635d62:	68 a0 b2 fa 00       	push   0xfab2a0
  635d67:	e8 94 b0 ec ff       	call   0x500e00
  635d6c:	8b 4d b4             	mov    ecx,DWORD PTR [ebp-0x4c]
  635d6f:	3b 4d b8             	cmp    ecx,DWORD PTR [ebp-0x48]
  635d72:	8b 45 c4             	mov    eax,DWORD PTR [ebp-0x3c]
  635d75:	0f 95 c2             	setne  dl
  635d78:	3b 45 c8             	cmp    eax,DWORD PTR [ebp-0x38]
  635d7b:	88 97 b4 00 00 00    	mov    BYTE PTR [edi+0xb4],dl
  635d81:	0f 95 c1             	setne  cl
  635d84:	88 8f b5 00 00 00    	mov    BYTE PTR [edi+0xb5],cl
  635d8a:	89               	mov    DWORD PTR [ebp-0x2c],esi
```

## J. 確認清單 / 自行復算指令

```bash
sha256sum /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
  --start-address=0x500A00 --stop-address=0x500A7D /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
  --start-address=0x5008B0 --stop-address=0x500944 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 \
  --start-address=0x5B9380 --stop-address=0x5B9499 /mnt/data/Tartaros.bin
```

- 以上一手 BIN hash 與當次實檔一致，並非用 Github fixture 代替。
- T16-116、T16-114 源自原生 BIN 的已知限定主張本次挑重點復驗，不自動提升 T01 FULL-PASS。
- 本文以使用者目前明確任務要求交付本地 Markdown；GitHub 原稿、S00 規格／RR 台帳未被修改。未提交時**沒有 Git blob SHA 可報**。
