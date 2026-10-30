# T16-118 — Quest16／①：資源、Demand14、Reward50 的原生 loader→QuestRecord→type2 candidate 有界研究（KR，BIN-first）

- 作業者：`chatgpt-web roy`；檔案生成時間 `2026-10-30T04:24:14.012664+08:00`。
- 正式段號：**T16-118**（依 T16 工作分支已提交最新原稿 T16-117 後續；不是以 XML 的 QuestID 代替正式段號）。本檔為**本對話新研究**；未 Commit / Push，沒有 Git blob SHA。
- 本次範圍：**Quest16-① 資源與前置、Client loader 與可確認的資料結構傳遞**。Quest16 ②玩家觸發 ③C→S ④S→C/status/UI ⑤完成→Quest15，僅繼承前段既有有界事實，**不在本檔冒稱已完成**。
- KR BIN：`12,472,320` bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。EXE `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；Event STP `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；Table STP `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。原始二進位唯讀、未執行、未修補、未上傳 Git。
- PE 自原件解析 `.text` VirtualAddress=0x1000、raw pointer=0x400，ImageBase=0x400000，故 `.text` raw=`VA-0x400C00`。`.rdata` RVA=0x7D2000/raw=0x7D0600，故 `.rdata` raw=`VA-0xBD2000+0x7D0600`。
- GitHub 開工：`main=c1e4d5e9fda28ebb0cae66996cb092780aa2c6be`；T16 初始 HEAD `e916d4c9b5aa7bdc105ecfe42b9f551d26b88d43`，compare ahead4/behind2；本次事先授權一次性**main→T16** PR [#26](https://github.com/we88ec3-prog/ttr_anal_multi/pull/26) merge commit `8d45e99cc09b25b1744578fb9a2a4d226f78b5a8`，重新 compare ahead5/behind0。這是**同步**，不是研究原稿提交。此對話不再次自動 Merge。
- 已查最新 main `AGENTS.md`、`kr/tasks/T16/{README.md,task.json}` 的 T01 退回、`research/dispatch/README.md`、`research/dispatch/inbox/T16.md` 和 `research/requests/index.json`：T16 無分派 RR；未發現 NEEDS_FIX/FIXING；有既往 RESOLVED 和 43 筆歷史作者 READY_FOR_REVIEW 事項，不擅自改狀態。`RR-0005` 歸 **KR T02/extra/roy1**，不可併入 T16。
- `shared/verified-knowledge/README.md` 現有 7 個**有限**已核准子主張，並不構成本研究或整篇 Quest 功能的 T01 FULL-PASS。S00 專管規格發布／設計，不代表 Server 已開發。

## 1. 結果概要（證據分級）

### 1.1 既有源資源（T16-112／T16-117 提供的原始 XML 擷取，並非本段重新解密 Table.stp）

原件索引 `kr/evidence/5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60.txt`，Git blob `1c86c9ce4f2422f84269ed9eb641202fedb9fb63`；本次 GitHub connector 能查到此 blob SHA，但**大型全文讀回回傳空 content**，因此下列三筆內容係**明示承襲 T16-112、T16-117 對該 Git blob 的已整理原文**，不虛稱本次重新掃遍 4,798 Quest XML 或重新解包 Table.stp：

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

屬 XML 宣告的已知**靜態**條件：Quest16 `type=2`, `town=0`, `level=1`, `giver=finisher=10027`, `subtype=1`, `Demand14`, `Reward type2 value50`；**Quest16 無 field / AcceptAction / CompleteAction 欄位**（以先前來源記錄為限）。Q15 `Demand16`。不從 `RewardsEtc id=16` 推定該 id 被原生業務讀者核對，亦不把 reward 50 解釋為幣種/經驗值或已領取。

既有 T16-112 對源 XML 的靜態總表另指出 NPC10027 共關聯 Quest `14/16/1002/2742..2746`，QuestTalk.xml 無 14/15/16 同 ID 對話 mapping，SceneList.xml 無 questIdx14/16；這些屬**限定 namespace 的否證**，不是遊戲中無 NPC／劇情。

### 1.2 **本段新做的原始 BIN 逐條閉合**

**新增 A：Demand14 被資料載入器具體放進 record vector，與候選 gate 間可以按記憶體布局接上。**

1. `0x504BC5..0x504BE7` 對 `<Demands>/<Demand>` 做可缺省的節點選取；`0x504C72..0x504C8A` 讀 `id` 並以 `0x8917B4` 數字化；`0x504C24..0x504CB3` 增長從 `esp+0x74` 開始的 **DWORD 元素序列**，`esp+0x78` 為 end (因 `0x504CB0` 每次 `+4`)。
2. `0x50540D..0x505412` 把當次 QuestRecord 臨時物件源址 `old ESP+0x64` 送入 `0x5064D0`；其中 `0x506509..0x506517` 將 source record+`0x10` vector 交由 `0x7E8A90` 複製到 dest record+`0x10`；`0x506310` 在插入 QuestInfo map tree node 時再次複製 record。
3. `0x500631..0x500652` 用 Quest key 調 `0x503D20` 命中 QuestInfo map node，`[node+0x20]..[node+0x24]` 是 **node+0x10 payload 中的 record+0x10..+0x14 demand vector**，`0x50065D..0x5006AE` 逐 DWORD 要求比對 `QuestOwner+0x5EB0..+0x5EB4` 的**WORD** prerequisite key；只要缺少 Quest16 的 14 就 skip，不是 Server 判決。
4. 這條鏈建立了 **XML `Demand14` → 4B demand vector → map node payload → candidate rebuild 依 owner WORD key14 判定** 的實體來源連線。注意不同物件基底的相同偏移不能混稱；不暗示 14 必然已由 Server 授予。

**新增 B：Quest16 Reward(type2,value50) 被 parser 映射至 record 中的標量槽，不是自動發獎。**

1. `0x504CCD..0x504D23` 找子元素 `RewardsEtc`、`Reward`；`0x504D42..0x504DC2` 以 `type` 名字讀取數字至 EBX、`0x504D70..0x504DDD` 以 `value` 名字讀取數字至 EAX。
2. `0x504D96: lea ecx,[ebx-1]`、`0x504D99: cmp ecx,5`、`0x504D9E: jmp [0x505554+ecx*4]`；原生 6-entry target table 對應 `type1→0x504DE2`、**`type2→0x504DF4`**、`type3→0x504DEB`、`type4→0x504DFD`、`type5→0x504E06`、`type6→0x504E0F`。
3. **type2** 走 `0x504DF4 mov dword [esp+0xEC],EAX`。臨時源 record base 為 `esp+0x64`，相差 `0x88`；`0x5065BA..0x5065C0` 由 `source+0x88` 讀 DWORD，寫 `dest+0x88`。`0x506310` 又透過 `0x5064D0` 把資料複製進 map node payload（正常非 OOM 路徑）。因此 `Reward type2 value50` 在**正常 XML parse / numeric conversion 成功時**進入 QuestInfo 的**record-relative +0x88 DWORD 值 50**。
4. 此為**Client 靜態 reward metadata**，未見此函式呼叫 socket、發獎 handler 或角色財產 writer；`+0x88` 只可稱 QuestRecord reward-type2 位置，**不能稱金錢、經驗值、道具獎勵的實際授予位置**。
5. `RewardsEtc id="16"` 在局部 `0x504CCD..0x504E30` 未見對它的 `id` 做額外比對；**限定**為這一段 parser 的靜態觀察，不聲稱全遊戲無其他驗證。

**新增 C：type2 與多重候選門檻的記憶體對接已再次 BIN-first 交叉驗證。**

- `0x500240` 候選 rebuild 比對 `QuestRecord+0x20` 與 caller selector、`QuestRecord+0x0C` 與 level bound、owner `+0x5ED0` 20個 WORD exclusion、`Demands` 全集合 membership；只有全部滿足，候選 WORD ID 才進 owner `+0x5EC0`。
- `0x500A00` 的 `0x500A53` 先比 `QuestRecord+0x28` 與 selector，`0x500A58` 明確比 `QuestRecord+0x04 == 2`，才能 `0x500A64` push pointer；Quest16 **type2** 讀者確實存在。但 record+0x20 與 +0x28 兩個 selector 的來源語意尚不能用 `town=0` 單獨定論；須追 caller 的真實參數與 UI 事件。
- `0x500950` 只收 type1，所以不能再用 T16-116 的 type1 UI consumer 證 Quest16 顯示。`0x74,key14` S→C 的 QuestOwner 存 key、重算候選，是**既有 T16-116** 有界結論；本段新增的是 XML→record vector 和 reward +0x88 記憶體鏈。

### 1.3 Event 資源交叉證據（本次直接讀原件 XOR，非 QuestID 映射）

原始 `Event.stp` 的 STPD header 與部份內容使用 XOR FF；下列原文 token 可直接由原始檔 XOR 視圖搜尋，不需執行遊戲：

- `TUTORIAL_PINKOHOUSE`：encoded byte offset `0xa27287`（10,646,151）；XOR FF 還原確認。此為**字串存在**，不是已解析整個 Lua 控制流程。
- `TUTORIAL_STARTSCENARIO`：encoded byte offset `0xa272a9`（10,646,185）；XOR FF 還原確認。此為**字串存在**，不是已解析整個 Lua 控制流程。
- `tutorial_start`：encoded byte offset `0xa1c063`（10,600,547）；XOR FF 還原確認。此為**字串存在**，不是已解析整個 Lua 控制流程。
- `pindos_talkevent`：encoded byte offset `0x8c1c61`（9,182,305）；XOR FF 還原確認。此為**字串存在**，不是已解析整個 Lua 控制流程。
- `SceneList.xml`：encoded byte offset `0xab8819`（11,241,497）；XOR FF 還原確認。此為**字串存在**，不是已解析整個 Lua 控制流程。

既有 T16-108/112：原生 SceneList 無 questIdx=16；有 questIdx=15 的 4 筆演出腳本。Event token `TUTORIAL_PINKOHOUSE` 與 Quest16 韓文標題呼應，但**沒有唯一 `TUTORIAL_PINKOHOUSE→QuestInfo.id16` 的 native binding**，不可把 Lua checkpoint／ScenarioID 當作 QuestID16。

## 2. 端到端資料流與精確物件基底

```text
Table/QuestInfo.xml (來源：已存 Git XML 抽出，不是本次重解 Table.stp)
  └── Quest16 id=16, type=2, Demand14, Reward(type2)=50, NPC10027
       ↓ Client XML loader 0x504370→0x504740
  [Demands/Demand.id 14] --0x504C82--> u32(14) in stack +0x74..+0x78 vector
       ↓ 0x5064D0 copies record +0x10 vector; 0x506310 map insertion copy
  [RewardsEtc/Reward type=2,value=50] --0x504D96 jump table-->
       stack+0xEC (= source struct +0x88) --0x5065BA..C0--> record+0x88
       ↓ map node: key + payload (node+0x10 record origin)
  QuestInfo map tree (0x503D20)
       ↓ 0x500240: [node+0x20]/[node+0x24] = record Demand vector begin/end
  read demand DWORD 14 vs owner+0x5EB0..+0x5EB4 WORD prerequisite list
       + selector / level / owner+0x5ED0 exclusion gates
       ↓ all match
  QuestOwner+0x5EC0 WORD candidate ID16
       ↓ 0x500A00: type=2 AND record+0x28 selector match
  type2 pointer vector → 0x5008B0 / 0x500A80 consumers (T16-117)
       ↓ runtime NPC/event producer **未閉合**
  TalkBox selected QuestInfo16 → conditional app payload 36 00 10 00 (T16-114/117)
       ↓ response S→C pairing **未唯一確認**
  QuestOwner index 0x40 / 0x74 status handlers (T16-117/116)
```

**偏移對照：**

| 類別 | 欄位 | 真實基底與寬度 | 實證範圍 |
|---|---|---|---|
| XML Demand | `id=14` | XML string→`u32` | 0x504C82數字化，後入 4B vector |
| loader stack vector | `[esp+0x74]` begin, `[esp+0x78]` end | 每 entry DWORD | 0x504C67/0x504CB0 |
| record demand | `record+0x10` begin, `record+0x14` end | 0x5064D0 深複製 | 0x506509..517 |
| map node demand | `node+0x20` begin, `node+0x24` end | `node+0x10` payload base，非 record+0x20 | 0x500652/0x500655 |
| owner completed/prereq | `owner+0x5EB0..0x5EB4` | WORD list, entry 2B | 0x500661..0x50069E |
| owner candidate | `owner+0x5EC0..0x5EC4` | WORD list | 0x500A08..0x500A20 |
| owner excluded | `owner+0x5ED0` | 20 x WORD | 0x5004A3..0x5004C2 |
| reward kind/value | XML `type=2,value=50` | numeric parse EBX/EAX | 0x504D..0x504DDD |
| reward local | `esp+0xEC` | DWORD: record temp base+0x88 | 0x504DF4, 0x50540E |
| reward record | `record+0x88` | DWORD scalar metadata | 0x5065BA..0x5065C0 |
| QuestInfo type | `record+0x04` | DWORD==2 | 0x500A58 |
| type2 selector | `record+0x28` | DWORD compare to caller argument | 0x500A53 |

## 3. 三輪深入及研究停止邊界

**T16-118 第 1 輪（已執行）**：比對上次已知 Quest16/Q14/Q15 XML、Event namespace，重新驗證實檔 SHA 與 `.text/.rdata` 的 PE 映射。原件 Table.stp 非明文 XML；GitHub 超大 XML file connector 只能核 blob，不可虛稱二次解包。定位 BIN 原生 `Table/QuestInfo.xml`、`Demands`、`RewardsEtc` 路徑與 parser 的錯誤退出條件。源配置本身是既有證據，不充作重大新發現。

**T16-118-2 第 2 輪（已執行）**：沿原生 `0x504C24..0x504CBE` 找到 demand vector 4-byte entry、`0x504D96` reward 種類跳表、`0x504DF4` type2 value stack slot、`0x5064D0` copy helper 與 record +0x10/+0x88，形成新確證的 **XML→Client QuestRecord 實際資料欄位**，相對 T16-112/117 有獨立增量。

**T16-118-3 第 3 輪（已執行）**：沿 `0x5053FB→0x506310→0x505F70` 追 map node payload 與 owner candidate reader `0x500652`，證明 `node+0x20` 是 `record+0x10` 所在位置；沿 `0x500A00` 再驗 Quest16 type2 過濾，並以 Event.stp 原生 XOR token 作 namespace 反證。達成 Quest16-① **有界**資料來源→record→候選 Client 靜態功能鏈；沒有據此提升 ②～⑤ 或「可玩」。

**局限：** 以上未做原版 Client 動態、NPC10027 spawn/點擊、原版網路封包、Server acceptance、獎勵實際入帳驗證。不能由 loader 或 reward 欄位直接推導 socket 事件，亦不可把 Client key14 存在當成後端官方完成規則。B. full syntax remain not independently authenticated in this run; previous original extraction trace is retained.

## 4. 玩家情境／封包／本地狀態與 Server 責任矩陣

| 情境 | Client 本地前置 | C→S 應用 payload | S→C Client 已見 schema | Client 資料/UI 效果 | 缺口/Server 分工 |
|---|---|---|---|---|---|
| Quest16 XML 成功載入 | Table XML 可讀、QuestInfo root 有效、entry parse 成功 | 無直接封包證據 | 無直接收包證據 | type2 record / Demand14 vector / reward type2 scalar50 進 QuestInfo map | 靜態配置不等於角色任務進度 |
| Quest16 Demand14 未滿足 | 其他 gates 任意；owner prerequisite 缺 key14 | 無此路徑必然發送 | 未指定 | candidate rebuild skip 16 | Client 已證 prerequisite；Server 何時送 key另設計 |
| owner 有 key14、其餘門檻通過 | selector、level、20-slot exclusion 均合格 | 不會因 candidate 本身必發 | 既有 `0x74,key14` 是可能來源，非證必然當次到達 | 0x500240 可產生 ID16，再由 type2 0x500A00 篩選 | exact NPC/UI producer 尚待② |
| 玩家若於 TalkBox 選中 Quest16 且確認 | 選中 record16、action/type/gate 均符合 | **條件式** `36 00 10 00`，4B app payload（舊 T16-114/117） | 唯一 Q16 ACK **unknown** | TalkBox選擇/queue 路徑（舊證） | ③④須查確切 UI trigger/success/reject/turn-in |
| Server 發送 index0x74 key16 | 接收器和owner存在 | 未確認前置請求 | 條件式 app `74 00 10 00`（舊 T16-116） | owner prerequisite key16; 重算 Q15 candidate（其他 gates 須成立） | 原版何時送/決策未知；S00 ADR/TEST；⑤須查 Q15 UI |
| Quest16 預配置 reward=50 | XML reward type2 parsed | **無證據**此時發獎發包 | **無證據**此時 rewards S2C | QuestRecord +0x88 儲存 metadata | 實際獎勵授予與儲存 Server待開發；Client award UI另逆向 |

## 5. Quest16 五子研究狀態（本次結束）

| 子研究 | 狀態 | 已確證及下一個具體目標 |
|---|---|---|
| **① 資源、前置及 loader** | **本次 T16-118 有界研究已完成** | 原生 XML 到 Demand14/vector/map node/candidate 與 Reward type2=50 → record+0x88；不代表可玩 |
| ② 玩家觸發／NPC10027 | **待正式研究**（T16-117 已有局部 read-side） | NPC10027 exact event producer、selector +0x20/+0x28 源頭、0x5008B0/0x500A80 → TalkBox 準確連線 |
| ③ C→S | **待正式研究**（T16-114/117 有界條件式） | `0x36,QID16` 三模式不同語意、送出 gate、獨立 `0x1C` NPC 操作、是否有其他請求 |
| ④ S→C／狀態／UI | **待正式研究**（T16-116/117 局部 owner path） | 0x36 request → ACK 唯一配對、0x40 status cases、0x74 key16、UI redraw、reject/reward |
| ⑤ Quest16→Quest15 | **待正式研究**（XML Demand16 已證） | key16→Q15 type2→NPC10338→C2S；與 Event/SceneList `(15,1..4)`、馮德斯村 `town001D.map` 區分本地腳本與 Server world transfer |

## 6. 按責任歸類的剩餘項

- **Client 待逆向**：①已界定靜態 loader；② NPC10027 正確 runtime event producer/selector；③ type2 接取、交付、取消模式及實際 wire send；④唯一 S2C success/reject/狀態 writer、UI 是否即時刷新、獎勵消費者；⑤ Quest15 的 NPC10338、SceneList/world transition 真正收發 handler。
- **Server 待開發（交 S00 DRAFT SPEC/GAP/ADR/TEST）**：Quest14→16→15 prerequisite 及 accepted/completed/reward 規則、合法性/重連 snapshot/冪等/持久化、何時發 `0x74`、與 type2 reward50 對應的**自訂或可驗證**給獎政策，嚴禁稱為原版演算法。
- **跨 Task 待整合**：T02 framing/連線 slot、T03/T04 登入/角色、T06 NPC/TalkBox、T07 場景/世界、T14 教學關卡結果、T15角色保存；各自 owner 不變，未更動 S00 台帳或他人原稿。
- **待遊玩驗證**：沒有原版 Client/Server 聯測、沒有實測 Quest16 UI/NPC 接取、沒有真正獎勵變化或馮德斯村進入證據；靜態測試不代表遊玩成功。

### 下一正式研究方向（非本段已完成）

優先 Quest16-②：從 `0x5008B0`（特定 event 0x105BF 的首個 type2 candidate）及 `0x500A80` 4個 caller 回溯 NPC10027 的 event 0x105B9 產生者與 selector，分清 `record+0x20`、`record+0x28` 的使用情境與本地 `0xF000` 教學物件。確認玩家互動→TalkBox QID16，才能將 T16-114 已證 `0x36` 串成一條實際玩家操作鏈。

## 7. 原始 BIN assembly 與切片 SHA（`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`）

以下以正確函式入口或指令界線起始；對分段沒有覆蓋的函式部分不以線性反組譯冒充完整 CFG。Span SHA 是**目前原始 BIN 切片**，不是 Git object SHA。

### S01 QuestInfo parent loader / split QuestTalk: VA `0x00504370..0x00504400` / raw `0x103770..0x103800` / 144B / SHA256 `55bdf5abf7ad7f4fe6ba05496ac8a3fc5013b11050a10807179189f914226b19`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

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
```

### S02 QuestInfo file + root gate: VA `0x00504780..0x005048C0` / raw `0x103B80..0x103CC0` / 320B / SHA256 `38ecd1f731df438a1a01845e2ec33257211aee402bcbafd5e442505dba3372b7`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00504780 <.data+0x103b80>:
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

### S03 Accept/CompleteActions → Demands entry: VA `0x00504ADF..0x00504BEE` / raw `0x103EDF..0x103FEE` / 271B / SHA256 `fab984de3e2fc97c3ccaba57575d2b60b6439587880143301d94c8866c1c7b5a`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00504adf <.data+0x103edf>:
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
  504bed:	8d               	lea    ecx,[ecx+0x0]
```

### S04 Demand id / DWORD vector: VA `0x00504BF0..0x00504CCD` / raw `0x103FF0..0x1040CD` / 221B / SHA256 `51149bd7031dcf8756a0bba8e330863b8b190c7b70dbfa7e2ea71b9094ab215c`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00504bf0 <.data+0x103ff0>:
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

### S05 RewardsEtc/Reward type/value/jump table: VA `0x00504CCD..0x00504E30` / raw `0x1040CD..0x104230` / 355B / SHA256 `1780428cc844052e90a1113937705640751525dce63f95a190484a7ba2cbf3bf`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

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
```

### S06 record map copy producer: VA `0x005053FB..0x00505463` / raw `0x1047FB..0x104863` / 104B / SHA256 `2072aa31cee69c49e973b7b794bde457687a3eeff0d3dbedc16307f9b2cef66d`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005053fb <.data+0x1047fb>:
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
  50545f:	e8 5c f1 ff        	call   0x5045c0
```

### S07 deep copy (record+0x10,+0x88): VA `0x005064D0..0x00506604` / raw `0x1058D0..0x105A04` / 308B / SHA256 `92188e0ee64966f63ba6eef618458a45ef350465193a834f600005fc464e7c6f`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005064d0 <.data+0x1058d0>:
  5064d0:	55                   	push   ebp
  5064d1:	8b ec                	mov    ebp,esp
  5064d3:	6a ff                	push   0xffffffff
  5064d5:	68 83 d5 90 00       	push   0x90d583
  5064da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5064e0:	50                   	push   eax
  5064e1:	56                   	push   esi
  5064e2:	57                   	push   edi
  5064e3:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5064e8:	33 c5                	xor    eax,ebp
  5064ea:	50                   	push   eax
  5064eb:	8d 45 f4             	lea    eax,[ebp-0xc]
  5064ee:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5064f4:	8b f9                	mov    edi,ecx
  5064f6:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  5064f9:	8b 07                	mov    eax,DWORD PTR [edi]
  5064fb:	89 06                	mov    DWORD PTR [esi],eax
  5064fd:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  506500:	89 4e 04             	mov    DWORD PTR [esi+0x4],ecx
  506503:	8b 57 08             	mov    edx,DWORD PTR [edi+0x8]
  506506:	89 56 08             	mov    DWORD PTR [esi+0x8],edx
  506509:	8b 47 0c             	mov    eax,DWORD PTR [edi+0xc]
  50650c:	8d 4f 10             	lea    ecx,[edi+0x10]
  50650f:	51                   	push   ecx
  506510:	8d 56 10             	lea    edx,[esi+0x10]
  506513:	52                   	push   edx
  506514:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  506517:	e8 74 25 2e 00       	call   0x7e8a90
  50651c:	33 c0                	xor    eax,eax
  50651e:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  506521:	8b 4f 20             	mov    ecx,DWORD PTR [edi+0x20]
  506524:	89 4e 20             	mov    DWORD PTR [esi+0x20],ecx
  506527:	8b 57 24             	mov    edx,DWORD PTR [edi+0x24]
  50652a:	89 56 24             	mov    DWORD PTR [esi+0x24],edx
  50652d:	8b 4f 28             	mov    ecx,DWORD PTR [edi+0x28]
  506530:	89 4e 28             	mov    DWORD PTR [esi+0x28],ecx
  506533:	8b 57 2c             	mov    edx,DWORD PTR [edi+0x2c]
  506536:	89 56 2c             	mov    DWORD PTR [esi+0x2c],edx
  506539:	8b 4f 30             	mov    ecx,DWORD PTR [edi+0x30]
  50653c:	89 4e 30             	mov    DWORD PTR [esi+0x30],ecx
  50653f:	8b 57 34             	mov    edx,DWORD PTR [edi+0x34]
  506542:	89 56 34             	mov    DWORD PTR [esi+0x34],edx
  506545:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  506548:	89 4e 38             	mov    DWORD PTR [esi+0x38],ecx
  50654b:	8b 57 3c             	mov    edx,DWORD PTR [edi+0x3c]
  50654e:	89 56 3c             	mov    DWORD PTR [esi+0x3c],edx
  506551:	8b 4f 40             	mov    ecx,DWORD PTR [edi+0x40]
  506554:	89 4e 40             	mov    DWORD PTR [esi+0x40],ecx
  506557:	8b 57 44             	mov    edx,DWORD PTR [edi+0x44]
  50655a:	89 56 44             	mov    DWORD PTR [esi+0x44],edx
  50655d:	8b 4f 48             	mov    ecx,DWORD PTR [edi+0x48]
  506560:	89 4e 48             	mov    DWORD PTR [esi+0x48],ecx
  506563:	8d 4e 4c             	lea    ecx,[esi+0x4c]
  506566:	6a ff                	push   0xffffffff
  506568:	89 41 10             	mov    DWORD PTR [ecx+0x10],eax
  50656b:	50                   	push   eax
  50656c:	8d 47 4c             	lea    eax,[edi+0x4c]
  50656f:	33 d2                	xor    edx,edx
  506571:	c7 41 14 07 00 00 00 	mov    DWORD PTR [ecx+0x14],0x7
  506578:	50                   	push   eax
  506579:	66 89 11             	mov    WORD PTR [ecx],dx
  50657c:	e8 5f c1 ef ff       	call   0x4026e0
  506581:	8d 4f 68             	lea    ecx,[edi+0x68]
  506584:	8d 46 68             	lea    eax,[esi+0x68]
  506587:	51                   	push   ecx
  506588:	50                   	push   eax
  506589:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  50658d:	e8 fe 3c 0c 00       	call   0x5ca290
  506592:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  506596:	8b 57 78             	mov    edx,DWORD PTR [edi+0x78]
  506599:	89 56 78             	mov    DWORD PTR [esi+0x78],edx
  50659c:	8b 47 7c             	mov    eax,DWORD PTR [edi+0x7c]
  50659f:	89 46 7c             	mov    DWORD PTR [esi+0x7c],eax
  5065a2:	8b 8f 80 00 00 00    	mov    ecx,DWORD PTR [edi+0x80]
  5065a8:	89 8e 80 00 00 00    	mov    DWORD PTR [esi+0x80],ecx
  5065ae:	8b 97 84 00 00 00    	mov    edx,DWORD PTR [edi+0x84]
  5065b4:	89 96 84 00 00 00    	mov    DWORD PTR [esi+0x84],edx
  5065ba:	8b 87 88 00 00 00    	mov    eax,DWORD PTR [edi+0x88]
  5065c0:	89 86 88 00 00 00    	mov    DWORD PTR [esi+0x88],eax
  5065c6:	8b 8f 8c 00 00 00    	mov    ecx,DWORD PTR [edi+0x8c]
  5065cc:	89 8e 8c 00 00 00    	mov    DWORD PTR [esi+0x8c],ecx
  5065d2:	8b 97 90 00 00 00    	mov    edx,DWORD PTR [edi+0x90]
  5065d8:	81 c7 94 00 00 00    	add    edi,0x94
  5065de:	57                   	push   edi
  5065df:	8d 86 94 00 00 00    	lea    eax,[esi+0x94]
  5065e5:	50                   	push   eax
  5065e6:	89 96 90 00 00 00    	mov    DWORD PTR [esi+0x90],edx
  5065ec:	e8 1f 00 00 00       	call   0x506610
  5065f1:	8b c6                	mov    eax,esi
  5065f3:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5065f6:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5065fd:	59                   	pop    ecx
  5065fe:	5f                   	pop    edi
  5065ff:	5e                   	pop    esi
  506600:	8b e5                	mov    esp,ebp
  506602:	5d                   	pop    ebp
  506603:	c2               	ret    0x4
```

### S08 map node allocator / 2nd record copy: VA `0x00506310..0x005063AA` / raw `0x105710..0x1057AA` / 154B / SHA256 `dc7388e63f8401423e2433a766f4ac903c638eafefb2260f03afc37ce9a1fb1f`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00506310 <.data+0x105710>:
  506310:	55                   	push   ebp
  506311:	8b ec                	mov    ebp,esp
  506313:	6a ff                	push   0xffffffff
  506315:	68 f1 2f 91 00       	push   0x912ff1
  50631a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  506320:	50                   	push   eax
  506321:	83 ec 18             	sub    esp,0x18
  506324:	53                   	push   ebx
  506325:	56                   	push   esi
  506326:	57                   	push   edi
  506327:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50632c:	33 c5                	xor    eax,ebp
  50632e:	50                   	push   eax
  50632f:	8d 45 f4             	lea    eax,[ebp-0xc]
  506332:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  506338:	89 65 f0             	mov    DWORD PTR [ebp-0x10],esp
  50633b:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  50633e:	8b f9                	mov    edi,ecx
  506340:	68 b8 00 00 00       	push   0xb8
  506345:	e8 1e af 38 00       	call   0x891268
  50634a:	8b f0                	mov    esi,eax
  50634c:	33 c9                	xor    ecx,ecx
  50634e:	83 c4 04             	add    esp,0x4
  506351:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  506354:	3b f1                	cmp    esi,ecx
  506356:	74 67                	je     0x5063bf
  506358:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  50635b:	89 06                	mov    DWORD PTR [esi],eax
  50635d:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  506360:	89 56 04             	mov    DWORD PTR [esi+0x4],edx
  506363:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  506366:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  506369:	8d 46 0c             	lea    eax,[esi+0xc]
  50636c:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  50636f:	66 89 8e b4 00 00 00 	mov    WORD PTR [esi+0xb4],cx
  506376:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  506379:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  50637c:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  506380:	3b c1                	cmp    eax,ecx
  506382:	74 10                	je     0x506394
  506384:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  506386:	89 08                	mov    DWORD PTR [eax],ecx
  506388:	83 c0 04             	add    eax,0x4
  50638b:	8d 4b 04             	lea    ecx,[ebx+0x4]
  50638e:	50                   	push   eax
  50638f:	e8 3c 01 00 00       	call   0x5064d0
  506394:	8b c6                	mov    eax,esi
  506396:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  506399:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5063a0:	59                   	pop    ecx
  5063a1:	5f                   	pop    edi
  5063a2:	5e                   	pop    esi
  5063a3:	5b                   	pop    ebx
  5063a4:	8b e5                	mov    esp,ebp
  5063a6:	5d                   	pop    ebp
  5063a7:	c2 04 00             	ret    0x4
```

### S09 demand consumer: node+0x20 and owner WORD keys: VA `0x00500631..0x005006B0` / raw `0xFFA31..0xFFAB0` / 127B / SHA256 `116b9e9704f2aec24b4fa10502b835a32a1b028c56f2ab5077a46137a8938af4`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00500631 <.data+0xffa31>:
  500631:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  500635:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
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
```

### S10 candidate type2 read-side: VA `0x00500A00..0x00500A7B` / raw `0xFFE00..0xFFE7B` / 123B / SHA256 `73f6bdee58810216f295c9b65596023e45740b38bac68a3b38c1efa0e284bf2c`

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
  500a7a:	c2               	ret    0xc
```

### S11 0x505554 六槽 reward switch table（DATA，非程式）

VA `0x00505554`、raw `0x104954`；24-byte SHA256 `42121164a8411e3bee8473bd227ae709de13b7cecd8937ffad233ac25b4741e2`；原生小端 DWORD 依序 `0x504de2, 0x504df4, 0x504deb, 0x504dfd, 0x504e06, 0x504e0f`。反組譯不應把這 24 bytes 當指令。`type2 → target[1] = 0x504DF4` 有原始表作依據。

## 8. 非證實的假設與需保留的更正

1. 本段的正面結果是**Quest16-① Client metadata/struct**，不是 Quest16 已成功接取、完成或 rewards 已發。
2. 不把 `+0x88` 認為角色財產欄位；它是 QuestInfo record 的 metadata reward slot。真正 UI/角色狀態 consumer 需另一段查。
3. `0x500240` 只更新 owner candidate list；`0x500A00` 是 type2 filtering；都不是自動 UI redraw。T16-116 的 type1 UI 推論已由 T16-117 勘誤。
4. `0x74,key14`、`0x40,QID14`、`0x36,QID16` 的 opcode direction/domain/producer 不能混為同一個封包。
5. Table.stp 檔案當次確實存在且 hash 相符，但**未在本段成功重建完整 QuestInfo.xml bytes**。大型 GitHub XML fetch 取得 SHA 卻未取回內容，因此引用 T16-112/117 有版本標記的已完成抽取；若後續比對來源有衝突，須重新解包再作原件字節對照。
6. 這篇 Markdown 是本對話現生成的完整研究原稿，**未 Commit/Push、未獲 Git blob SHA**；此前 T16-106～117 在 T16 遠端分支保留不動。
