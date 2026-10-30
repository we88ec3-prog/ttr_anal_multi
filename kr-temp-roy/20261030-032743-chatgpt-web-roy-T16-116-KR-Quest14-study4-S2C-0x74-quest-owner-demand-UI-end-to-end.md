# T16-116 — Quest14-④：KR 原生 S→C `0x74` → Quest ID record → Quest16 Demand14 → UI 候選讀取（BIN-first）

- 任務：KR T16 Quest & Story Progression；作者 `chatgpt-web roy`；時間 `2026-10-30T03:27:43.691220+08:00`。
- 一手 Client `Tartaros.bin`：12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 原始 `.text` VA 0x401000, raw0x400，故 **BIN raw = VA − 0x400C00**；`.rdata` VA0xBD2000 raw0x7D0600。所有 assembly 下列由原始 BIN 直接 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 切片生成，非原程式碼／非 fixture。跳表、字串、RTTI、vtable 的資料不得當可執行指令。
- 開工 GitHub 最新 main 與 T16 branch 同為 `b333883409e7895c0a1ebb67b71346b499804c2a`（compare behind=0）。已查 `AGENTS.md`、T16 README/task.json、S00 inbox/RR、共同 FULL-PASS；無 T16 RR，沒有新增認領。使用者本次明確授權 Commit/Push **T16 分支**與尚未提交 T16-114/115。本段不更改 main、S00 或 T01。
- T01 `FULL-PASS`、源作者原生有界主張、S00 SPEC、真實遊玩四種狀態區分；本文不擅稱 T01 已將整個 T16-116 FULL-PASS。

## 0. 結論與重要新發現

**首次從原始 BIN 閉合 QuestInfo ID 任務狀態的「S→C 業務 payload → Quest 管理物件 callback → 已持有任務 key 的 WORD vector → QuestInfo Demand → 候選列表 → TalkBox/UI 消費」有界處理鏈。** 不是前段 T16-115 的 Scene index `0x41/0x42/0x7F` 猜測；新 S→C command 是 Client 頂層命令表 **index 116 (0x74)**，透過 `0x494440 → [QuestObject.vtable+4]=0x4FDA30 → QuestOwner slot116 = 0x503400`。分派步進及兩份表相互對齊已由原始 bytes 驗證；這補正前段缺少的真實 receiver→Quest writer 路徑。

Client 層對一筆資料 **`74 00 0E 00`**（little-endian，業務 payload，非 T02 framed ciphertext）的有界可證效果：若 Client 已初始化 Quest owner、收到命令 dispatch index 116、至少可讀 `+2` WORD，則 `0x503400` 向 `owner+0x5EB0/+0x5EB4` 16-bit ID vector **追加 0x000E (=14)**，接著 `0x500240` 重新建立 `owner+0x5EC0/+0x5EC4` 的任務候選表。QuestInfo XML 的 Quest16 有 `Demand id=14`，`0x500240` 實作「每項 Demand 必須在前者 vector 中找到」的 gate，缺失則排除 Quest16。當 14 存在時 **僅通過 Demand14 這一關**；level / 角色條件 / 城鎮 / state 等其他 gate 仍須滿足才可能加入候選，不能宣稱一收包 Quest16 就一定顯示。

**Client 實際效果**的已證範圍是 local vector append/rebuild 與後續候選讀者；**未證的語意**是原版 Server 為何／何時發 `0x74 00 0E 00`，是否代表正式「完成」或授權已交付、以及 UI 是否在 *當下立即* redraw。這些與 Client API 已閉合不是同一個主張。主動 refresh/binding 若仍缺，保留明確跨事件 UI unknown 而非捏造 instant redraw。

### 0.1 已證程序鏈

```text
S2C decoded business-command (conditional; not network framing)
  command index 116 (0x74), payload+2 WORD = quest key (e.g. 0x000E)
CClient command 16-byte-stride table initializer 0x493170
  registration @ 0x493747..0x493758: [base+0x948] = 0x494440
  index math: (0x948 - 0x208) / 0x10 = 116
CClient dispatcher 0x48AAD0:
  handler [dispatch+index*0x10+8]
wrapper 0x494440:
  [0xFAB2A0] vtable = 0xC0DB08; vtable+4 = 0x4FDA30
  passes payload ptr, length, same command index
Quest owner handler-table 0x5020B0:
  index116 function slot [0xFAB2A0+4+116*8] = [0xFAB644] = 0x503400
Quest owner dispatcher 0x4FDA30:
  ebp+0x10 command index (signed16), calls [owner+4+index*8]
Quest owner 0x503400:
  eax = [payload]+2; edi = owner+0x5EB0; call 0x44B4E0
  WORD ID appended, then 0x500240(owner, current selector = [0x40F060()+0x8C])
Quest availability builder 0x500240:
  candidate QuestInfo map @ owner+0x5EAC
  all QuestRecord Demands in record+0x20..+0x24 (DWORD ID entries)
  each needed ID searched as WORD in owner+0x5EB0..+0x5EB4
  candidate WORD ID appended to owner+0x5EC0..+0x5EC4 only if other gates pass
Quest-related TalkBox 0x635CA0:
  0x500950(owner,selector) and 0x500E00(owner,selector) consumer
  writes TalkBox/control +0xB4,+0xB5 availability flags
  The UI consumer runs when its own caller triggers; no proof of immediate redraw.
```

## 1. 第一輪：找到比 `0x41/0x42/0x7F` 更直接的 Quest 状態 handler

1. `0x5020B0` 建立 Quest owner 的 **8-byte stride callback table**。基準 `0xFAB2A0`，element callable 起始 `base+4`；table until `0xFB1150`。明確指派 `0xFAB61C=0x502170`、`0xFAB634=0x5033B0`、`0xFAB644=0x503400`。對應 index 分別是 111、114、116；它們不是 SceneOwner 的另一個 callback table。
2. **`0x503400`** 讀 incoming `payload+2` 的 WORD，交由 **`0x44B4E0`** 存進 QuestOwner 的 `+0x5EB0` 16-bit vector，緊接著拿當前 selector (`0x40F060()+0x8C`) 呼叫 **`0x500240`**。它不修改 Scenario14 的 `FC0F88` local map，也不是 `FAB134` 0x18-byte record writer。
3. **`0x44B4E0`** 實際行為由原生指令 `0x44B529 mov cx,[esi] ; 0x44B52C mov [eax],cx ; 0x44B52F add [edi+4],2` 確認是 DWORD pointer triple vector 的 `WORD` 追加（若資料指標落在自己 vector 區內，先保存 index 再擴容，仍 append；見 0x44B4E3..44B514）。不再把 handler 誤認為只會清空或不更新記錄。
4. **`0x502170`** 是 QuestOwner 的另一個 handler (index111)，會清理 +0x5EB0 vector 並依 `(available-2)&3==0` gate 執行 `0x44AB70` → `0x44AA10` 更新該容器，然後 rebuild `0x500240`。`0x5033B0` (index114) 清理 +0x5EB0 後 rebuild。這提供 snapshot/reset/add 三類 Client 更新路徑，三者皆須按原始 command index 判別；`0x502170` 的具體多筆元素語意、長度保護及有無 reject 仍有不同層級未知。

## 2. 第二輪：補上頂層 CClient → QuestManager 的實際分派

T16-115 只有 Scene handler。這次從 **頂層 Client 16-byte stride table** 確認 9 個命令索引轉發至 `0x494440`：

| top-level command index | command HEX | init slot offset | QuestOwner registered callback |
|---:|---|---|---|
| 64 | `0x40` | `+0x608` | `0x502270` |
| 69 | `0x45` | `+0x658` | `0x5027D0` |
| 70 | `0x46` | `+0x668` | `0x502B40` |
| 71 | `0x47` | `+0x678` | `0x503040` |
| 100 | `0x64` | `+0x848` | `0x5030C0` |
| 101 | `0x65` | `+0x858` | `0x5035D0` |
| 111 | `0x6F` | `+0x8F8` | `0x502170` |
| 114 | `0x72` | `+0x928` | `0x5033B0` |
| **116** | **`0x74`** | **`+0x948`** | **`0x503400`** |

**特別容易犯的索引錯誤**：top-level init code `0x493170` 從 `[object+0x208]` 開始建 table，`0x48AAD0` 的 `edi` 是 **callback-subobject base `object+0x200`**，其 callable `[edi+0x8 + index*0x10]`；**不可錯用 `(0x948-0x8)/16=148`**。正確索引 `(0x948-0x208)/16=116`，且和 Quest owner 8-byte stride `(0xFAB644 - 0xFAB2A4)/8=116` 完整吻合。九組登記是額外獨立交叉驗證。

頂層 `0x494440` `mov eax,[0xFAB2A0] ; mov edx,[eax+4] ; mov ecx,0xFAB2A0 ; call edx`。**原生 `.rdata` vtable** 在 VA 0xC0DB08, raw 0x80C108，`DWORD vtable[0] = 0x4FFF80`、`DWORD vtable[1] = 0x4FDA30`。`0x4FDA30` 以 `movsx edi,word[ebp+0x10]` 查 `[esi+edi*8+4]`，valid 時真正 `call` 目標並透傳 payload、length、command；沒有 callback 時走 vtable fallback。這使 **S→C index116 → QuestOwner index116** 不是猜想。

**端點命名限制**：這裏 `0x74` 是 Client 解碼後的 application command WORD，用於 dispatch；T02 完整 socket framing、連線 slot／加密／校驗由該 Task 所有，本段不偽造 wire frame byte offsets。此處 `74 00 0E 00` 是最小 **業務 payload** 示範，須加合法 framing 才能在網路上送出，且沒有原版實收 capture。`0x503400` 本地不顯式檢查可用長度，不能從此推導安全的整體 network min-frame。

## 3. 第三輪：Quest16 對 Quest14 的相依條件與 UI 消費閉合

### 3.1 QuestInfo 原生來源

原始 KR `Table/QuestInfo.xml` (GitHub `kr/evidence/5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60.txt`，非假造 fixture) 的關鍵記錄：

```xml
<Quest id="14" type="3" town="0" field="18" level="1" giver="10027" finisher="10027" subtype="1" subject="튜토리얼-이실리아">
  <CompleteAction type="1" />
  <AcceptAction type="1" />
</Quest>
<Quest id="16" type="2" town="0" level="1" giver="10027" finisher="10027" subtype="1" subject="튜토리얼-핑코파파">
  <Demands><Demand id="14" /></Demands>
  <RewardsEtc id="16"><Reward type="2" value="50" /></RewardsEtc>
</Quest>
```

在 `0x504BC5..0x504CCD` parser 處理 `<Demands>`，它把輸入 ID 解析為 DWORD array，留在 QuestRecord 的需求向量。`0x500652 mov edx,[record+0x24]; sub edx,[record+0x20]; sar edx,2` 以 DWORD 為單位判斷需求筆數。`0x500670` 取 `record+0x20`，`0x50068B mov esi,[esi]` 是 **u32 demanded id**；`0x500690 movzx ebx,word[eax] ; cmp ebx,esi` 以已收到的 owner u16 keys 比對；找不到執行 `0x50069E/0x5006A0 → 0x50077E` 跳過該候選。逐筆 Demand 全命中才走 `0x5006B0..0x50077A` 候選 WORD push 流程。

這給出 Quest16 的直接測試條件：`owner.completedOrUnlockedKeys` 不含14 → `Demand14` gate 不成立；收到 owner callback index116 追加 `14` → gate 可成立；之後若同時通過其他條件，Quest16 才會進入 `[owner+0x5EC0,+0x5EC4)`。此向量應用「前置滿足 key 集合」作技術命名；**是否嚴格等於 Server 完成清單或已領獎狀態，原生未證，故不使用 completedQuestDB 作原始命名**。

### 3.2 UI 後段：真實讀取者而非立即 redraw 推測

- `0x500240` 輸出 candidate QuestID vector +0x5EC0/+0x5EC4；不是直接 UI render 函式。`0x500950` 從此向量逐 WORD 取候選 ID，查 QuestInfo map +0x5EAC，再用 `QuestInfo payload+0x28 == selector` 與其他 gate 維持顯示類別，輸出 pointer vector。`0x500E00` 讀 20-slot key list +0x5ED0／`[FAB134]` 記錄，提供另一個 mode 的 pointer vector；不能兩者視為完全相同。
- 真實 UI 呼叫者 `0x635CA0`：`0x635D18..0x635D28` 呼叫 `0x500950(owner, control+0x84, outVecA)`，`0x635D57..0x635D67` 呼叫 `0x500E00(owner, control+0x84, outVecB)`；`0x635D6C..0x635D84` 以兩組 nonempty 結果寫 `control+0xB4 / +0xB5` bytes。其上游 `0x63664A` 是 TalkBox/context 更新呼叫者。**這是實際 Client consumer**；未證 S2C callback 同步觸發 UI 立即重繪，不得聲稱一收命令就彈出 Quest16。
- 資料路徑 `S2C → owner state vector → rebuilt quest candidates → TalkBox consumer` 已閉合到 UI read API，對於不同交互觸發的刷新時序與 NPC 是否立刻更新，列為 ⑤／待遊玩驗證，不阻擋本次④有界相容契約。

## 4. 玩家情境、收發與狀態矩陣

| 玩家情境 | Client C→S | S→C decoded business payload | 已證 native writer | 已證依賴/UI 讀取 | 仍未證 / Server 設計 |
|---|---|---|---|---|---|
| Lua 啟動 Scenario14 | `40 00 0E 00`，經 sender queue (T16-111/114) | `4C 00 0E 00`：Scene::CTutorial active 才有效 | `0x4C4F20` 讓 Scenario14 local map=1 | `Tutorial.IsScenarioEnded(14)` 輪詢 | ScenarioID14≠QuestInfoID14 的直接別名無證；Server 時機由 S00 |
| 玩家 TalkBox 選到 QuestInfo14 | `36 00 0E 00`，限 mode/gate (T16-114) | **不能假定回覆必然 `0x74`** | － | － | 哪種 UI mode 是接受或交付，仍 unknown |
| 已解碼的任務 key append S2C | 不要求已經發 `0x36`，回覆配對未知 | **`74 00 0E 00`**（條件式 Client handler schema） | `0x494440→0x4FDA30→0x503400` 加入 key14；`0x500240` rebuild | Quest16 Demand14 比對可以通過 | 原版 Server 何時發、是否代表 completed、封包最小合法 framing 不明 |
| 重新連線/任務狀態整批回填 | unknown | index `0x6F` (111)，`0x502170`，有長度 gate | 替換／重建 owner key vector +5EB0；`0x500240` | 對候選列表重算 | 每筆格式需另專門解析，不能宣稱完整 snapshot schema |
| 任務 key 清除/切換 | unknown | index `0x72` (114)，`0x5033B0` | 清理 owner key vector +5EB0；`0x500240` | 候選列表重算 | 真正 Server business timing unknown |
| NPC/UI 再次開啟候選列表 | event/lua/gate（T16-114） | 無需新的 S2C | `0x635CA0` 讀取 `0x500950/0x500E00` 結果 | `control+0xB4/+0xB5` | 當場 refresh、Quest16 可點時機/step callback 仍需與⑤交接 |

## 5. 可執行契約（僅 Client 已證）與防誤判

```cpp
// Pseudocode of conditional native Client behavior, NOT original source,
// NOT an original Server algorithm, NOR a self-contained wire frame.
void OnDecodedClientCommand(uint16_t topLevelCommand,
                            const uint8_t* payload, size_t available) {
    if (topLevelCommand == 0x0074) { // 116; application business command
        // Precondition: legal frame decoded, owner exists, enough input bytes.
        // Client's 0x503400 does not itself validate available >= 4;
        // T02 message framing/length gate must be handled separately.
        uint16_t key = ReadLE16(payload + 2);
        QuestOwnerAppendWord(questOwner.vec_5EB0_5EB4, key); // 0x44B4E0
        RebuildCandidates(questOwner, CurrentContextSelector()); // 0x500240
    }
}
void DemandFilter_500240(QuestInfoRec* candidate, QuestOwner* owner) {
    for (uint32_t needed : candidate->demands_20_24) {
        if (!WordVectorContains(owner->vec_5EB0_5EB4, needed)) return;
    }
    // Other static map, level, type, selection, already-in-lists, and context
    // gates are applied by actual 0x500240 CFG; do NOT unconditional append.
    if (OtherNativeGatesMatch(candidate, owner))
        AppendWord(owner->candidates_5EC0_5EC4, candidate->id);
}
```

**不能主張**：`0x74` 是伺服器的「成功交付 ACK」、所有 Quest14 的 UI 在 payload=14 時同步變完成、`0x6F` 全部變長格式已還原、`0x41/0x42/0x7F` 是 Quest14 completed writer、S00 已經完成 server 或 gameplay tests。**可以主張**：quest key14 可以透過命令 `0x74` 由 S2C handler 追加到 Client 任務 key vector，然後依 QuestInfo 的 Demand14 影響 Quest16 候選，並已有明確 UI pointer-vector 讀端。

## 6. 失敗、空值、狀態重播與安全邊界

- `0x4FDA30` handler slot NULL 時呼叫 vtable+0xC fallback，非視為未知索引都成功。callback 返回 HRESULT `0x80004005` 則 `0x6EDB60` 留有錯誤路徑。
- `0x503400` **沒有局部 length gate**，直接取 `payload+2`；因此沒有證據保證短於4 byte 的 payload 可以安全處理。不得用這個 native handler 作外部未驗證資料輸入。要尊重 T02 parser/transport length。
- `0x44B4E0` 使用 iterator/重分配邏輯，即使來源指向 vector 內部仍可 append；此 helper **不顯式去重**。重複 `0x74 key14` 可能在本地 vector 出現兩次；但 `0x500240` 做的是 membership test，重複是否造成 UI 次數變化需遊玩／完整循環查證。
- `0x500240` 在候選計算前重置 `+0x5EC0/+0x5EC4` 的有效 end，並非在收到 key 時直接向 UI 添加 Quest16。對於缺失 Demand、selector 不符、角色/等級 gate 不符，都會略過候選。
- **`0x5033B0`** 清理後 rebuild；`0x502170` 回填帶 `(len−2)%4==0` 的 parser gate，不能僅靠未對齊 4 byte 資料猜多筆 schema。
- 通用 Scene 8-byte handler table **不同**於 QuestOwner 8-byte handler table；同 index 116 不能在兩個不同 owner 間自動類比，須經本次已確認的頂層 `0x494440` 路由。
- 中途 Scene 交換／連線重建、重登 authoritative snapshot、Quest14 接取模式仍需串 T02/T03/T07/T15 的原生契約；未做真實 socket capture/Client 啟動。對於有界 Client callback 無需等原始 Server 判定程式才能提交。

## 7. Quest14 五項子研究狀態

| 子研究 | 現在狀態 | 重要邊界 |
|---|---|---|
| ① QuestInfo/前置/NPC | 已完成（T16-112） | 資源 schema 不是 Server 判定 |
| ② 本地教學／Isilia 找到／Scenario 觸發 | 有界完成（T16-113） | 本地 `0xF000` ≠ XML NPC10027；Quest14 接取模式另查 |
| ③ C→S | 有界完成（T16-114） | Quest14 `0x36 00 0E 00` 的 UI mode accepted/finish 仍需標 unknown |
| **④ QuestInfo S→C/狀態/UI** | **本段有界 Client 契約完成** | `0x74 key14` append → `0x500240` Demand14 → UI 讀端；不是官方 Server 何時回覆/立即 redraw |
| ⑤ Quest14 → Quest16 真實可接/回覆 | 待後續 | 須對 Quest16 實際 NPC/玩家互動、其他 gate、下一個 C2S/S2C 進行有界驗證 |

### 7.1 兩條重要名詞界線

`ScenarioID=14` 的 `0x40 →0x4C` 與 `QuestInfoID=14` 的 `0x36 → [unknown actual pairing] →0x74` **不是同一個 native state**。這次只驗證 `0x74` 是「若收到 ID14，任務前置清單更新並影響 Quest16」，**並未證明** `0x36` 後原版 Server 一定發出 `0x74`。

**`QuestOwner+0x5EB0` 的值應稱為『前置滿足 key 集合』**，不是已經證明接受清單／完成清單／領獎清單，因原版 Server 會發的條件沒有第一手原件。`QuestInfo Demand id=14` 靜態關係確定；Client 在取候選時以該集合查門檻確定。

## 8. 提供 S00 的 Server-facing 規格與任務分工

- `SPEC-Q14-CLIENT-QUEST-STATE-DRAFT`：Client 接收 decoded `0x74` + `u16 QuestID`，透過 QuestOwner callback key vector append/rebuild；`Quest16.Demand14` 必須在 client key vector 中，才可通過 prerequisite gate。T02 另合入 framing/完整長度／slot 門檻，S00 不能虛構 Server 原版交易時序。
- `SPEC-Q14-CLIENT-INIT-DRAFT`：`0x6F`/`0x72` 可能替換或清空同一狀態向量；若 Server 需讓重登後 Quest16 保持可接，須由 S00 與 T03/T15 決定 authoritative snapshot 一致性與回覆策略，不要依賴單次 UI event 剛好觸發。
- `ADR-Q14-SERVER-POLICY`：何時判定 Quest14 完成、是否要求已先接受、是否對 C2S `0x36` ACK、重試幂等、防重複、進度持久化由相容 Server 設計。**不得標成原版 Server 既有演算法**。
- `GAP-Q14-UI-IMMEDIATE-REFRESH`：已證有真實 UI `0x635CA0` 讀端，未證 callback 同步觸發 UI 重繪；給 ⑤與待遊玩驗證追查。
- `GAP-Q14-QUEST-TALK-MODE`：`0x36` 各 mode/已接取/完成交付語意尚未以原生 Client event 證明；保留 ②③ 的條件性限制，不能由本次 ④ 直接推導。
- `TEST-Q14-SYNTHETIC-DRAFT`（**未執行於遊戲**）：僅可作可重現靜態 contract 測試：index 116，payload `74 00 0E 00`，預設 owner 有 QuestInfo16 且其他 gate 通過時候選可含16；clear `0x72` 使 Demand14 停止滿足；未經原版 Client 測試不得提升為 NATIVE_RUNTIME_VERIFIED。

## 9. 此段實際研究輪次

- **T16-116 第一輪**：搜尋 QuestOwner 未分析的 callback `0x502170` / `0x5033B0` / `0x503400`；從 native 字節證明 `0x503400→0x44B4E0` 會把 `payload+2` WORD 存入 QuestOwner `+0x5EB0`，並觸發 `0x500240`。不再繼續以無關 Scene `0x41/0x42/0x7F` 猜測。
- **T16-116-2 第二輪**：獨立溯源頂層 `0x493170/0x493747 → 0x48AAD0 → 0x494440 → [Quest.vtable+4]=0x4FDA30 → [QuestOwner+4+116*8]`，找到 command `0x74` 的精確 S2C route，並校正 offset base `0x208` 的誤判風險。
- **T16-116-3 第三輪**：追 `0x500240` 依 `QuestInfo record+0x20` 4-byte demands 和 QuestOwner `+0x5EB0` u16 key vector 的 membership filter、候選 +5EC0 writer，再追 `0x500950/0x500E00 → 0x635CA0` UI flags。依使用者要求完整 Quest14-④ 的 Client 能力鏈，保留未證 immediate UI redraw 和原版 Server timing。

## 10. 已知前段研究與修訂關係

- T16-108 `QuestInfo.xml` 真正 XML 及教學 Lua/Scene；T16-109、T16-110、T16-110-REV、T16-111、T16-115 皆保留原文，本段是新證據而非覆寫舊稿；T16-114 C2S 路徑另獨立。
- `T16-115` 的「Quest14 正式任務 writer 與 UI 不明」限定主張：**現已由 index116 → 0x503400 → 0x500240 的新原生證據在『任務 key vector/candidate/UI讀端』層級補足**。但 `0x74` 的實際官方 Server 配對、完整已完成／已接受語意與 UI 當下 refresh 依舊未證，不宣稱 T16-115 當時錯報。
- `T16-110-REV` 對 `0x5DF3A0/F4266` 的反證持續有效；本段不以郵件附件 UI vtable 當任務刷新 listener。

## 11. 原始 BIN x86 assembly 證據附錄

每組取樣有獨立 SHA256（對抽出的 assembly 純文字做 sha，不是二進位指令 bytes SHA；原始 binary 整體 SHA 在開頭）。`objdump` 起始切片若落在指令中間的第一個錯位指令不得直接當邏輯。表中的等式均按上述原生偏移驗證。完整 assembly 一律 **保留原始機器碼節錄**，不能因聊天只回報摘要而刪掉。

### A01. Client 16-byte slot init, callable starts +0x208: VA `0x00493170..0x004931A0`, raw `0x00092570..0x000925A0`

片段文字 SHA256 `c4bdbcb47993a892473c5aa455e73ecc53e2112b1ddd1c86208edcf9cc627b2b`。

```asm
00493170 <.data+0x92570>:
  493170:	53                   	push   ebx
  493171:	56                   	push   esi
  493172:	57                   	push   edi
  493173:	bf 60 43 49 00       	mov    edi,0x494360
  493178:	33 db                	xor    ebx,ebx
  49317a:	8d 90 10 02 00 00    	lea    edx,[eax+0x210]
  493180:	be d5 0b 00 00       	mov    esi,0xbd5
  493185:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  49318a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  493190:	89 7a f8             	mov    DWORD PTR [edx-0x8],edi
  493193:	89 5a fc             	mov    DWORD PTR [edx-0x4],ebx
  493196:	89 0a                	mov    DWORD PTR [edx],ecx
  493198:	83 c2 10             	add    edx,0x10
  49319b:	4e                   	dec    esi
  49319c:	75 f2                	jne    0x493190
  49319e:	ba 80          	mov    edx,0x494780
```

### A02. Client register nine forwarding commands 64/69/70/71/100/101/111/114/116: VA `0x00493675..0x00493765`, raw `0x00092A75..0x00092B65`

片段文字 SHA256 `2450f82e4867f329e5d05915e9930f73168185479824c2854f7f50a2290cd2c7`。

```asm
00493675 <.data+0x92a75>:
  493675:	12 00                	adc    al,BYTE PTR [eax]
  493677:	00 ba b0 43 49 00    	add    BYTE PTR [edx+0x4943b0],bh
  49367d:	89 90 78 10 00 00    	mov    DWORD PTR [eax+0x1078],edx
  493683:	89 b0 7c 10 00 00    	mov    DWORD PTR [eax+0x107c],esi
  493689:	89 88 80 10 00 00    	mov    DWORD PTR [eax+0x1080],ecx
  49368f:	ba 40 44 49 00       	mov    edx,0x494440
  493694:	89 90 08 06 00 00    	mov    DWORD PTR [eax+0x608],edx
  49369a:	89 b0 0c 06 00 00    	mov    DWORD PTR [eax+0x60c],esi
  4936a0:	89 88 10 06 00 00    	mov    DWORD PTR [eax+0x610],ecx
  4936a6:	ba 40 44 49 00       	mov    edx,0x494440
  4936ab:	89 90 58 06 00 00    	mov    DWORD PTR [eax+0x658],edx
  4936b1:	89 b0 5c 06 00 00    	mov    DWORD PTR [eax+0x65c],esi
  4936b7:	89 88 60 06 00 00    	mov    DWORD PTR [eax+0x660],ecx
  4936bd:	ba 40 44 49 00       	mov    edx,0x494440
  4936c2:	89 90 68 06 00 00    	mov    DWORD PTR [eax+0x668],edx
  4936c8:	89 b0 6c 06 00 00    	mov    DWORD PTR [eax+0x66c],esi
  4936ce:	89 88 70 06 00 00    	mov    DWORD PTR [eax+0x670],ecx
  4936d4:	ba 40 44 49 00       	mov    edx,0x494440
  4936d9:	89 90 78 06 00 00    	mov    DWORD PTR [eax+0x678],edx
  4936df:	89 b0 7c 06 00 00    	mov    DWORD PTR [eax+0x67c],esi
  4936e5:	89 88 80 06 00 00    	mov    DWORD PTR [eax+0x680],ecx
  4936eb:	ba 40 44 49 00       	mov    edx,0x494440
  4936f0:	89 90 48 08 00 00    	mov    DWORD PTR [eax+0x848],edx
  4936f6:	89 b0 4c 08 00 00    	mov    DWORD PTR [eax+0x84c],esi
  4936fc:	89 88 50 08 00 00    	mov    DWORD PTR [eax+0x850],ecx
  493702:	ba 40 44 49 00       	mov    edx,0x494440
  493707:	89 90 58 08 00 00    	mov    DWORD PTR [eax+0x858],edx
  49370d:	89 b0 5c 08 00 00    	mov    DWORD PTR [eax+0x85c],esi
  493713:	89 88 60 08 00 00    	mov    DWORD PTR [eax+0x860],ecx
  493719:	ba 40 44 49 00       	mov    edx,0x494440
  49371e:	89 90 f8 08 00 00    	mov    DWORD PTR [eax+0x8f8],edx
  493724:	89 b0 fc 08 00 00    	mov    DWORD PTR [eax+0x8fc],esi
  49372a:	89 88 00 09 00 00    	mov    DWORD PTR [eax+0x900],ecx
  493730:	ba 40 44 49 00       	mov    edx,0x494440
  493735:	89 90 28 09 00 00    	mov    DWORD PTR [eax+0x928],edx
  49373b:	89 b0 2c 09 00 00    	mov    DWORD PTR [eax+0x92c],esi
  493741:	89 88 30 09 00 00    	mov    DWORD PTR [eax+0x930],ecx
  493747:	ba 40 44 49 00       	mov    edx,0x494440
  49374c:	89 90 48 09 00 00    	mov    DWORD PTR [eax+0x948],edx
  493752:	89 b0 4c 09 00 00    	mov    DWORD PTR [eax+0x94c],esi
  493758:	89 88 50 09 00 00    	mov    DWORD PTR [eax+0x950],ecx
  49375e:	ba d0 44 49 00       	mov    edx,0x4944d0
  493763:	89 90        	mov    DWORD PTR [eax+0xa58],edx
```

### A03. Client 16-byte stride dispatcher: VA `0x0048AAD0..0x0048AB69`, raw `0x00089ED0..0x00089F69`

片段文字 SHA256 `e5c4541e412e0b2c8d6c9fa59390352ed828d0c90515c37eb477cf5644cb8ce5`。

```asm
0048aad0 <.data+0x89ed0>:
  48aad0:	55                   	push   ebp
  48aad1:	8b ec                	mov    ebp,esp
  48aad3:	83 ec 08             	sub    esp,0x8
  48aad6:	53                   	push   ebx
  48aad7:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  48aada:	0f bf c3             	movsx  eax,bx
  48aadd:	56                   	push   esi
  48aade:	89 45 10             	mov    DWORD PTR [ebp+0x10],eax
  48aae1:	03 c0                	add    eax,eax
  48aae3:	57                   	push   edi
  48aae4:	8b f9                	mov    edi,ecx
  48aae6:	8b 4c c7 0c          	mov    ecx,DWORD PTR [edi+eax*8+0xc]
  48aaea:	8d 34 c7             	lea    esi,[edi+eax*8]
  48aaed:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  48aaf0:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  48aaf3:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  48aaf6:	85 c0                	test   eax,eax
  48aaf8:	75 1b                	jne    0x48ab15
  48aafa:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  48aafd:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  48ab00:	8b 17                	mov    edx,DWORD PTR [edi]
  48ab02:	8b 52 0c             	mov    edx,DWORD PTR [edx+0xc]
  48ab05:	53                   	push   ebx
  48ab06:	50                   	push   eax
  48ab07:	51                   	push   ecx
  48ab08:	8b cf                	mov    ecx,edi
  48ab0a:	ff d2                	call   edx
  48ab0c:	5f                   	pop    edi
  48ab0d:	5e                   	pop    esi
  48ab0e:	5b                   	pop    ebx
  48ab0f:	8b e5                	mov    esp,ebp
  48ab11:	5d                   	pop    ebp
  48ab12:	c2 0c 00             	ret    0xc
  48ab15:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  48ab18:	6a 06                	push   0x6
  48ab1a:	68 6c 6c bf 00       	push   0xbf6c6c
  48ab1f:	50                   	push   eax
  48ab20:	e8 99 7d 40 00       	call   0x8928be
  48ab25:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  48ab28:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  48ab2b:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  48ab2e:	83 c4 0c             	add    esp,0xc
  48ab31:	53                   	push   ebx
  48ab32:	51                   	push   ecx
  48ab33:	52                   	push   edx
  48ab34:	8d 8c 38 00 fe ff ff 	lea    ecx,[eax+edi*1-0x200]
  48ab3b:	ff 55 f8             	call   DWORD PTR [ebp-0x8]
  48ab3e:	8b f8                	mov    edi,eax
  48ab40:	81 ff 05 40 00 80    	cmp    edi,0x80004005
  48ab46:	75 15                	jne    0x48ab5d
  48ab48:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  48ab4b:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  48ab4e:	51                   	push   ecx
  48ab4f:	52                   	push   edx
  48ab50:	68 74 6c bf 00       	push   0xbf6c74
  48ab55:	e8 06 30 26 00       	call   0x6edb60
  48ab5a:	83 c4 0c             	add    esp,0xc
  48ab5d:	8b c7                	mov    eax,edi
  48ab5f:	5f                   	pop    edi
  48ab60:	5e                   	pop    esi
  48ab61:	5b                   	pop    ebx
  48ab62:	8b e5                	mov    esp,ebp
  48ab64:	5d                   	pop    ebp
  48ab65:	c2 0c 00             	ret    0xc
  48ab68:	cc                   	int3
```

### A04. Quest 0x494440 forwarding wrapper: VA `0x00494440..0x004944C2`, raw `0x00093840..0x000938C2`

片段文字 SHA256 `59eb91dc1397f627954411a063f0f839fa61879788c3628b92290e60db34725a`。

```asm
00494440 <.data+0x93840>:
  494440:	55                   	push   ebp
  494441:	8b ec                	mov    ebp,esp
  494443:	6a ff                	push   0xffffffff
  494445:	68 fe 7d 94 00       	push   0x947dfe
  49444a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  494450:	50                   	push   eax
  494451:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  494456:	51                   	push   ecx
  494457:	33 c5                	xor    eax,ebp
  494459:	50                   	push   eax
  49445a:	8d 45 f4             	lea    eax,[ebp-0xc]
  49445d:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  494463:	b8 01 00 00 00       	mov    eax,0x1
  494468:	84 05 9c b2 fa 00    	test   BYTE PTR ds:0xfab29c,al
  49446e:	75 26                	jne    0x494496
  494470:	09 05 9c b2 fa 00    	or     DWORD PTR ds:0xfab29c,eax
  494476:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  49447d:	e8 de b9 06 00       	call   0x4ffe60
  494482:	68 00 cf bc 00       	push   0xbccf00
  494487:	e8 8e de 3f 00       	call   0x89231a
  49448c:	83 c4 04             	add    esp,0x4
  49448f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  494496:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  494499:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  49449c:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  49449f:	50                   	push   eax
  4944a0:	a1 a0 b2 fa 00       	mov    eax,ds:0xfab2a0
  4944a5:	51                   	push   ecx
  4944a6:	52                   	push   edx
  4944a7:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4944aa:	b9 a0 b2 fa 00       	mov    ecx,0xfab2a0
  4944af:	ff d2                	call   edx
  4944b1:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4944b4:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4944bb:	59                   	pop    ecx
  4944bc:	8b e5                	mov    esp,ebp
  4944be:	5d                   	pop    ebp
  4944bf:	c2 0c 00             	ret    0xc
```

### A05. QuestOwner factory/init and vtable set: VA `0x004FFE60..0x004FFF4B`, raw `0x000FF260..0x000FF34B`

片段文字 SHA256 `8d4f564a0eb8d64a1108d67b455743b80bdbeb02ae2db856e97e88c39de0ee8c`。

```asm
004ffe60 <.data+0xff260>:
  4ffe60:	55                   	push   ebp
  4ffe61:	8b ec                	mov    ebp,esp
  4ffe63:	6a ff                	push   0xffffffff
  4ffe65:	68 7e 42 94 00       	push   0x94427e
  4ffe6a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ffe70:	50                   	push   eax
  4ffe71:	83 ec 18             	sub    esp,0x18
  4ffe74:	56                   	push   esi
  4ffe75:	57                   	push   edi
  4ffe76:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ffe7b:	33 c5                	xor    eax,ebp
  4ffe7d:	50                   	push   eax
  4ffe7e:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ffe81:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4ffe87:	c7 45 ec a0 b2 fa 00 	mov    DWORD PTR [ebp-0x14],0xfab2a0
  4ffe8e:	33 f6                	xor    esi,esi
  4ffe90:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  4ffe93:	6a 10                	push   0x10
  4ffe95:	c7 05 a0 b2 fa 00 08 	mov    DWORD PTR ds:0xfab2a0,0xc0db08
  4ffe9c:	db c0 00 
  4ffe9f:	e8 c4 13 39 00       	call   0x891268
  4ffea4:	83 c4 04             	add    esp,0x4
  4ffea7:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4ffeaa:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  4ffeae:	3b c6                	cmp    eax,esi
  4ffeb0:	74 09                	je     0x4ffebb
  4ffeb2:	8b f8                	mov    edi,eax
  4ffeb4:	e8 b7 44 00 00       	call   0x504370
  4ffeb9:	eb 02                	jmp    0x4ffebd
  4ffebb:	33 c0                	xor    eax,eax
  4ffebd:	a3 4c 11 fb 00       	mov    ds:0xfb114c,eax
  4ffec2:	89 35 50 11 fb 00    	mov    DWORD PTR ds:0xfb1150,esi
  4ffec8:	89 35 54 11 fb 00    	mov    DWORD PTR ds:0xfb1154,esi
  4ffece:	89 35 58 11 fb 00    	mov    DWORD PTR ds:0xfb1158,esi
  4ffed4:	89 35 60 11 fb 00    	mov    DWORD PTR ds:0xfb1160,esi
  4ffeda:	89 35 64 11 fb 00    	mov    DWORD PTR ds:0xfb1164,esi
  4ffee0:	89 35 68 11 fb 00    	mov    DWORD PTR ds:0xfb1168,esi
  4ffee6:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  4ffeea:	6a 30                	push   0x30
  4ffeec:	89 35 a0 11 fb 00    	mov    DWORD PTR ds:0xfb11a0,esi
  4ffef2:	e8 71 13 39 00       	call   0x891268
  4ffef7:	83 c4 04             	add    esp,0x4
  4ffefa:	3b c6                	cmp    eax,esi
  4ffefc:	74 4e                	je     0x4fff4c
  4ffefe:	a3 9c 11 fb 00       	mov    ds:0xfb119c,eax
  4fff03:	89 00                	mov    DWORD PTR [eax],eax
  4fff05:	a1 9c 11 fb 00       	mov    eax,ds:0xfb119c
  4fff0a:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  4fff0d:	a1 9c 11 fb 00       	mov    eax,ds:0xfb119c
  4fff12:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  4fff15:	a1 9c 11 fb 00       	mov    eax,ds:0xfb119c
  4fff1a:	c6 40 2c 01          	mov    BYTE PTR [eax+0x2c],0x1
  4fff1e:	8b 0d 9c 11 fb 00    	mov    ecx,DWORD PTR ds:0xfb119c
  4fff24:	c6 41 2d 01          	mov    BYTE PTR [ecx+0x2d],0x1
  4fff28:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  4fff2c:	e8 7f 21 00 00       	call   0x5020b0
  4fff31:	e8 ba 39 00 00       	call   0x5038f0
  4fff36:	b8 a0 b2 fa 00       	mov    eax,0xfab2a0
  4fff3b:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4fff3e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4fff45:	59                   	pop    ecx
  4fff46:	5f                   	pop    edi
  4fff47:	5e                   	pop    esi
  4fff48:	8b e5                	mov    esp,ebp
  4fff4a:	5d                   	pop    ebp
```

### A06. Quest 8-byte handler registration 0x5020B0: VA `0x005020B0..0x00502170`, raw `0x001014B0..0x00101570`

片段文字 SHA256 `274e2fed5058628a482781b42c8f41fa7b0090bb6217b8c828238a06be25bc88`。

```asm
005020b0 <.data+0x1014b0>:
  5020b0:	b8 a8 b2 fa 00       	mov    eax,0xfab2a8
  5020b5:	ba 40 7d 4b 00       	mov    edx,0x4b7d40
  5020ba:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  5020bf:	90                   	nop
  5020c0:	89 50 fc             	mov    DWORD PTR [eax-0x4],edx
  5020c3:	89 08                	mov    DWORD PTR [eax],ecx
  5020c5:	83 c0 08             	add    eax,0x8
  5020c8:	3d 50 11 fb 00       	cmp    eax,0xfb1150
  5020cd:	7c f1                	jl     0x5020c0
  5020cf:	c7 05 a4 b4 fa 00 70 	mov    DWORD PTR ds:0xfab4a4,0x502270
  5020d6:	22 50 00 
  5020d9:	89 0d a8 b4 fa 00    	mov    DWORD PTR ds:0xfab4a8,ecx
  5020df:	89 15 9c b4 fa 00    	mov    DWORD PTR ds:0xfab49c,edx
  5020e5:	89 0d a0 b4 fa 00    	mov    DWORD PTR ds:0xfab4a0,ecx
  5020eb:	c7 05 cc b4 fa 00 d0 	mov    DWORD PTR ds:0xfab4cc,0x5027d0
  5020f2:	27 50 00 
  5020f5:	89 0d d0 b4 fa 00    	mov    DWORD PTR ds:0xfab4d0,ecx
  5020fb:	c7 05 d4 b4 fa 00 40 	mov    DWORD PTR ds:0xfab4d4,0x502b40
  502102:	2b 50 00 
  502105:	89 0d d8 b4 fa 00    	mov    DWORD PTR ds:0xfab4d8,ecx
  50210b:	c7 05 dc b4 fa 00 40 	mov    DWORD PTR ds:0xfab4dc,0x503040
  502112:	30 50 00 
  502115:	89 0d e0 b4 fa 00    	mov    DWORD PTR ds:0xfab4e0,ecx
  50211b:	c7 05 c4 b5 fa 00 c0 	mov    DWORD PTR ds:0xfab5c4,0x5030c0
  502122:	30 50 00 
  502125:	89 0d c8 b5 fa 00    	mov    DWORD PTR ds:0xfab5c8,ecx
  50212b:	c7 05 cc b5 fa 00 d0 	mov    DWORD PTR ds:0xfab5cc,0x5035d0
  502132:	35 50 00 
  502135:	89 0d d0 b5 fa 00    	mov    DWORD PTR ds:0xfab5d0,ecx
  50213b:	c7 05 1c b6 fa 00 70 	mov    DWORD PTR ds:0xfab61c,0x502170
  502142:	21 50 00 
  502145:	89 0d 20 b6 fa 00    	mov    DWORD PTR ds:0xfab620,ecx
  50214b:	c7 05 34 b6 fa 00 b0 	mov    DWORD PTR ds:0xfab634,0x5033b0
  502152:	33 50 00 
  502155:	89 0d 38 b6 fa 00    	mov    DWORD PTR ds:0xfab638,ecx
  50215b:	c7 05 44 b6 fa 00 00 	mov    DWORD PTR ds:0xfab644,0x503400
  502162:	34 50 00 
  502165:	89 0d 48 b6 fa 00    	mov    DWORD PTR ds:0xfab648,ecx
  50216b:	c3                   	ret
  50216c:	cc                   	int3
  50216d:	cc                   	int3
  50216e:	cc                   	int3
  50216f:	cc                   	int3
```

### A07. Quest vtable slot+4 dispatcher: VA `0x004FDA30..0x004FDAB3`, raw `0x000FCE30..0x000FCEB3`

片段文字 SHA256 `2489ddf29a51bcdd2e64895faa08387965fe47365946e9848ac467d876ca789b`。

```asm
004fda30 <.data+0xfce30>:
  4fda30:	55                   	push   ebp
  4fda31:	8b ec                	mov    ebp,esp
  4fda33:	51                   	push   ecx
  4fda34:	56                   	push   esi
  4fda35:	8b f1                	mov    esi,ecx
  4fda37:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  4fda3a:	57                   	push   edi
  4fda3b:	0f bf f9             	movsx  edi,cx
  4fda3e:	8b 44 fe 04          	mov    eax,DWORD PTR [esi+edi*8+0x4]
  4fda42:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4fda45:	85 c0                	test   eax,eax
  4fda47:	75 1a                	jne    0x4fda63
  4fda49:	8b 06                	mov    eax,DWORD PTR [esi]
  4fda4b:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4fda4e:	8b 40 0c             	mov    eax,DWORD PTR [eax+0xc]
  4fda51:	51                   	push   ecx
  4fda52:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  4fda55:	51                   	push   ecx
  4fda56:	52                   	push   edx
  4fda57:	8b ce                	mov    ecx,esi
  4fda59:	ff d0                	call   eax
  4fda5b:	5f                   	pop    edi
  4fda5c:	5e                   	pop    esi
  4fda5d:	8b e5                	mov    esp,ebp
  4fda5f:	5d                   	pop    ebp
  4fda60:	c2 0c 00             	ret    0xc
  4fda63:	8b 4c fe 08          	mov    ecx,DWORD PTR [esi+edi*8+0x8]
  4fda67:	53                   	push   ebx
  4fda68:	6a 06                	push   0x6
  4fda6a:	8d 5c fe 08          	lea    ebx,[esi+edi*8+0x8]
  4fda6e:	68 6c 6c bf 00       	push   0xbf6c6c
  4fda73:	51                   	push   ecx
  4fda74:	e8 45 4e 39 00       	call   0x8928be
  4fda79:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  4fda7c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4fda7f:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4fda82:	83 c4 0c             	add    esp,0xc
  4fda85:	52                   	push   edx
  4fda86:	50                   	push   eax
  4fda87:	51                   	push   ecx
  4fda88:	8b ce                	mov    ecx,esi
  4fda8a:	ff 55 fc             	call   DWORD PTR [ebp-0x4]
  4fda8d:	8b f0                	mov    esi,eax
  4fda8f:	81 fe 05 40 00 80    	cmp    esi,0x80004005
  4fda95:	75 11                	jne    0x4fdaa8
  4fda97:	8b 13                	mov    edx,DWORD PTR [ebx]
  4fda99:	52                   	push   edx
  4fda9a:	57                   	push   edi
  4fda9b:	68 74 6c bf 00       	push   0xbf6c74
  4fdaa0:	e8 bb 00 1f 00       	call   0x6edb60
  4fdaa5:	83 c4 0c             	add    esp,0xc
  4fdaa8:	5b                   	pop    ebx
  4fdaa9:	5f                   	pop    edi
  4fdaaa:	8b c6                	mov    eax,esi
  4fdaac:	5e                   	pop    esi
  4fdaad:	8b e5                	mov    esp,ebp
  4fdaaf:	5d                   	pop    ebp
  4fdab0:	c2 0c 00             	ret    0xc
```

### A08. QuestOwner index116 0x503400 payload ID append and rebuild: VA `0x00503400..0x00503432`, raw `0x00102800..0x00102832`

片段文字 SHA256 `48ce0cc387d104b5f10368da940565f6c09a922e963299dfd736c17e681916a6`。

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

### A09. u16 vector append actual helper 0x44B4E0: VA `0x0044B4E0..0x0044B535`, raw `0x0004A8E0..0x0004A935`

片段文字 SHA256 `1fa1469aa9ce3c6badf5ae11c10b95137f4ff73bc6527c6800bfca16ab558650`。

```asm
0044b4e0 <.data+0x4a8e0>:
  44b4e0:	56                   	push   esi
  44b4e1:	8b f0                	mov    esi,eax
  44b4e3:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  44b4e6:	3b f0                	cmp    esi,eax
  44b4e8:	73 2c                	jae    0x44b516
  44b4ea:	8b 0f                	mov    ecx,DWORD PTR [edi]
  44b4ec:	3b ce                	cmp    ecx,esi
  44b4ee:	77 26                	ja     0x44b516
  44b4f0:	2b f1                	sub    esi,ecx
  44b4f2:	d1 fe                	sar    esi,1
  44b4f4:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  44b4f7:	75 07                	jne    0x44b500
  44b4f9:	8b c7                	mov    eax,edi
  44b4fb:	e8 b0 00 00 00       	call   0x44b5b0
  44b500:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  44b503:	85 c0                	test   eax,eax
  44b505:	74 28                	je     0x44b52f
  44b507:	8b 0f                	mov    ecx,DWORD PTR [edi]
  44b509:	66 8b 14 71          	mov    dx,WORD PTR [ecx+esi*2]
  44b50d:	66 89 10             	mov    WORD PTR [eax],dx
  44b510:	83 47 04 02          	add    DWORD PTR [edi+0x4],0x2
  44b514:	5e                   	pop    esi
  44b515:	c3                   	ret
  44b516:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  44b519:	75 07                	jne    0x44b522
  44b51b:	8b c7                	mov    eax,edi
  44b51d:	e8 8e 00 00 00       	call   0x44b5b0
  44b522:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  44b525:	85 c0                	test   eax,eax
  44b527:	74 06                	je     0x44b52f
  44b529:	66 8b 0e             	mov    cx,WORD PTR [esi]
  44b52c:	66 89 08             	mov    WORD PTR [eax],cx
  44b52f:	83 47 04 02          	add    DWORD PTR [edi+0x4],0x2
  44b533:	5e                   	pop    esi
  44b534:	c3                   	ret
```

### A10. u16 vector growth helper: VA `0x0044B5B0..0x0044B6A0`, raw `0x0004A9B0..0x0004AAA0`

片段文字 SHA256 `81f25a162eb442132c8f45e5278eeaecbd491724afb3e945ee6f86ffb4637ea4`。

```asm
0044b5b0 <.data+0x4a9b0>:
  44b5b0:	56                   	push   esi
  44b5b1:	8b f0                	mov    esi,eax
  44b5b3:	8b 16                	mov    edx,DWORD PTR [esi]
  44b5b5:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  44b5b8:	2b c2                	sub    eax,edx
  44b5ba:	d1 f8                	sar    eax,1
  44b5bc:	3d fe ff ff 7f       	cmp    eax,0x7ffffffe
  44b5c1:	76 0a                	jbe    0x44b5cd
  44b5c3:	68 78 23 bf 00       	push   0xbf2378
  44b5c8:	e8 63 25 43 00       	call   0x87db30
  44b5cd:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  44b5d0:	2b ca                	sub    ecx,edx
  44b5d2:	40                   	inc    eax
  44b5d3:	d1 f9                	sar    ecx,1
  44b5d5:	3b c1                	cmp    eax,ecx
  44b5d7:	76 2d                	jbe    0x44b606
  44b5d9:	57                   	push   edi
  44b5da:	8b d1                	mov    edx,ecx
  44b5dc:	d1 ea                	shr    edx,1
  44b5de:	bf ff ff ff 7f       	mov    edi,0x7fffffff
  44b5e3:	2b fa                	sub    edi,edx
  44b5e5:	3b f9                	cmp    edi,ecx
  44b5e7:	5f                   	pop    edi
  44b5e8:	73 0f                	jae    0x44b5f9
  44b5ea:	33 c9                	xor    ecx,ecx
  44b5ec:	3b c8                	cmp    ecx,eax
  44b5ee:	0f 42 c8             	cmovb  ecx,eax
  44b5f1:	51                   	push   ecx
  44b5f2:	e8 a9 00 00 00       	call   0x44b6a0
  44b5f7:	5e                   	pop    esi
  44b5f8:	c3                   	ret
  44b5f9:	03 ca                	add    ecx,edx
  44b5fb:	3b c8                	cmp    ecx,eax
  44b5fd:	0f 42 c8             	cmovb  ecx,eax
  44b600:	51                   	push   ecx
  44b601:	e8 9a 00 00 00       	call   0x44b6a0
  44b606:	5e                   	pop    esi
  44b607:	c3                   	ret
  44b608:	cc                   	int3
  44b609:	cc                   	int3
  44b60a:	cc                   	int3
  44b60b:	cc                   	int3
  44b60c:	cc                   	int3
  44b60d:	cc                   	int3
  44b60e:	cc                   	int3
  44b60f:	cc                   	int3
  44b610:	55                   	push   ebp
  44b611:	8b ec                	mov    ebp,esp
  44b613:	83 ec 10             	sub    esp,0x10
  44b616:	6a 18                	push   0x18
  44b618:	c7 05 9c 93 fb 00 00 	mov    DWORD PTR ds:0xfb939c,0x0
  44b61f:	00 00 00 
  44b622:	e8 41 5c 44 00       	call   0x891268
  44b627:	83 c4 04             	add    esp,0x4
  44b62a:	85 c0                	test   eax,eax
  44b62c:	74 34                	je     0x44b662
  44b62e:	a3 98 93 fb 00       	mov    ds:0xfb9398,eax
  44b633:	89 00                	mov    DWORD PTR [eax],eax
  44b635:	a1 98 93 fb 00       	mov    eax,ds:0xfb9398
  44b63a:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  44b63d:	a1 98 93 fb 00       	mov    eax,ds:0xfb9398
  44b642:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  44b645:	8b 0d 98 93 fb 00    	mov    ecx,DWORD PTR ds:0xfb9398
  44b64b:	b0 01                	mov    al,0x1
  44b64d:	88 41 14             	mov    BYTE PTR [ecx+0x14],al
  44b650:	8b 15 98 93 fb 00    	mov    edx,DWORD PTR ds:0xfb9398
  44b656:	88 42 15             	mov    BYTE PTR [edx+0x15],al
  44b659:	b8 94 93 fb 00       	mov    eax,0xfb9394
  44b65e:	8b e5                	mov    esp,ebp
  44b660:	5d                   	pop    ebp
  44b661:	c3                   	ret
  44b662:	8d 45 fc             	lea    eax,[ebp-0x4]
  44b665:	50                   	push   eax
  44b666:	8d 4d f0             	lea    ecx,[ebp-0x10]
  44b669:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  44b670:	e8 34 5a 44 00       	call   0x8910a9
  44b675:	68 a8 57 c8 00       	push   0xc857a8
  44b67a:	8d 4d f0             	lea    ecx,[ebp-0x10]
  44b67d:	51                   	push   ecx
  44b67e:	c7 45 f0 a4 2c bd 00 	mov    DWORD PTR [ebp-0x10],0xbd2ca4
  44b685:	e8 66 13 45 00       	call   0x89c9f0
  44b68a:	cc                   	int3
  44b68b:	cc                   	int3
  44b68c:	cc                   	int3
  44b68d:	cc                   	int3
  44b68e:	cc                   	int3
  44b68f:	cc                   	int3
  44b690:	a1 98 93 fb 00       	mov    eax,ds:0xfb9398
  44b695:	50                   	push   eax
  44b696:	e8 71 5b 44 00       	call   0x89120c
  44b69b:	59                   	pop    ecx
  44b69c:	c3                   	ret
  44b69d:	cc                   	int3
  44b69e:	cc                   	int3
  44b69f:	cc                   	int3
```

### A11. QuestOwner index111 snapshot/update: VA `0x00502170..0x00502270`, raw `0x00101570..0x00101670`

片段文字 SHA256 `1dcda2a5c57447ad0d4c70863462f398e9b67facb8ca31fc19e924c751ed0873`。

```asm
00502170 <.data+0x101570>:
  502170:	55                   	push   ebp
  502171:	8b ec                	mov    ebp,esp
  502173:	83 e4 f8             	and    esp,0xfffffff8
  502176:	6a ff                	push   0xffffffff
  502178:	68 e6 41 94 00       	push   0x9441e6
  50217d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  502183:	50                   	push   eax
  502184:	83 ec 18             	sub    esp,0x18
  502187:	53                   	push   ebx
  502188:	56                   	push   esi
  502189:	57                   	push   edi
  50218a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50218f:	33 c4                	xor    eax,esp
  502191:	50                   	push   eax
  502192:	8d 44 24 28          	lea    eax,[esp+0x28]
  502196:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  50219c:	8b d9                	mov    ebx,ecx
  50219e:	89 5c 24 10          	mov    DWORD PTR [esp+0x10],ebx
  5021a2:	8b 8b b4 5e 00 00    	mov    ecx,DWORD PTR [ebx+0x5eb4]
  5021a8:	8b b3 b0 5e 00 00    	mov    esi,DWORD PTR [ebx+0x5eb0]
  5021ae:	8d bb b0 5e 00 00    	lea    edi,[ebx+0x5eb0]
  5021b4:	3b f1                	cmp    esi,ecx
  5021b6:	74 1d                	je     0x5021d5
  5021b8:	8b c1                	mov    eax,ecx
  5021ba:	2b c1                	sub    eax,ecx
  5021bc:	d1 f8                	sar    eax,1
  5021be:	8d 1c 00             	lea    ebx,[eax+eax*1]
  5021c1:	53                   	push   ebx
  5021c2:	51                   	push   ecx
  5021c3:	56                   	push   esi
  5021c4:	e8 27 f1 38 00       	call   0x8912f0
  5021c9:	83 c4 0c             	add    esp,0xc
  5021cc:	03 de                	add    ebx,esi
  5021ce:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  5021d1:	8b 5c 24 10          	mov    ebx,DWORD PTR [esp+0x10]
  5021d5:	33 f6                	xor    esi,esi
  5021d7:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5021db:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  5021df:	89 74 24 1c          	mov    DWORD PTR [esp+0x1c],esi
  5021e3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5021e6:	83 c0 fe             	add    eax,0xfffffffe
  5021e9:	89 74 24 30          	mov    DWORD PTR [esp+0x30],esi
  5021ed:	a8 03                	test   al,0x3
  5021ef:	75 14                	jne    0x502205
  5021f1:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  5021f4:	83 c1 02             	add    ecx,0x2
  5021f7:	51                   	push   ecx
  5021f8:	8d 74 24 18          	lea    esi,[esp+0x18]
  5021fc:	e8 6f 89 f4 ff       	call   0x44ab70
  502201:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  502205:	8d 54 24 14          	lea    edx,[esp+0x14]
  502209:	52                   	push   edx
  50220a:	8b c7                	mov    eax,edi
  50220c:	e8 ff 87 f4 ff       	call   0x44aa10
  502211:	b8 01 00 00 00       	mov    eax,0x1
  502216:	84 05 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,al
  50221c:	75 21                	jne    0x50223f
  50221e:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  502224:	88 44 24 30          	mov    BYTE PTR [esp+0x30],al
  502228:	e8 63 ca fd ff       	call   0x4dec90
  50222d:	68 30 ce bc 00       	push   0xbcce30
  502232:	e8 e3 00 39 00       	call   0x89231a
  502237:	83 c4 04             	add    esp,0x4
  50223a:	c6 44 24 30 00       	mov    BYTE PTR [esp+0x30],0x0
  50223f:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  502244:	50                   	push   eax
  502245:	53                   	push   ebx
  502246:	e8 f5 df ff ff       	call   0x500240
  50224b:	85 f6                	test   esi,esi
  50224d:	74 09                	je     0x502258
  50224f:	56                   	push   esi
  502250:	e8 b7 ef 38 00       	call   0x89120c
  502255:	83 c4 04             	add    esp,0x4
  502258:	33 c0                	xor    eax,eax
  50225a:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  50225e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  502265:	59                   	pop    ecx
  502266:	5f                   	pop    edi
  502267:	5e                   	pop    esi
  502268:	5b                   	pop    ebx
  502269:	8b e5                	mov    esp,ebp
  50226b:	5d                   	pop    ebp
  50226c:	c2 0c 00             	ret    0xc
  50226f:	cc                   	int3
```

### A12. QuestOwner index114 clear/reset: VA `0x005033B0..0x00503400`, raw `0x001027B0..0x00102800`

片段文字 SHA256 `c1fe8b0ac0ec3d97d7308e43bf4a537f5a8bd2d430404799281d96648515fb78`。

```asm
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
```

### A13. QuestCandidate builder map+gates first half: VA `0x00500240..0x00500490`, raw `0x000FF640..0x000FF890`

片段文字 SHA256 `2e4ffc0e407dfa050bc649f5d93641cef199326f5bca7189ecbb62b29dda5f39`。

```asm
00500240 <.data+0xff640>:
  500240:	55                   	push   ebp
  500241:	8b ec                	mov    ebp,esp
  500243:	83 e4 f8             	and    esp,0xfffffff8
  500246:	6a ff                	push   0xffffffff
  500248:	68 19 02 94 00       	push   0x940219
  50024d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  500253:	50                   	push   eax
  500254:	83 ec 48             	sub    esp,0x48
  500257:	53                   	push   ebx
  500258:	56                   	push   esi
  500259:	57                   	push   edi
  50025a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50025f:	33 c4                	xor    eax,esp
  500261:	50                   	push   eax
  500262:	8d 44 24 58          	lea    eax,[esp+0x58]
  500266:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  50026c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  50026f:	8b 8b c4 5e 00 00    	mov    ecx,DWORD PTR [ebx+0x5ec4]
  500275:	8b bb c0 5e 00 00    	mov    edi,DWORD PTR [ebx+0x5ec0]
  50027b:	3b f9                	cmp    edi,ecx
  50027d:	74 1c                	je     0x50029b
  50027f:	8b c1                	mov    eax,ecx
  500281:	2b c1                	sub    eax,ecx
  500283:	d1 f8                	sar    eax,1
  500285:	8d 34 00             	lea    esi,[eax+eax*1]
  500288:	56                   	push   esi
  500289:	51                   	push   ecx
  50028a:	57                   	push   edi
  50028b:	e8 60 10 39 00       	call   0x8912f0
  500290:	83 c4 0c             	add    esp,0xc
  500293:	03 f7                	add    esi,edi
  500295:	89 b3 c4 5e 00 00    	mov    DWORD PTR [ebx+0x5ec4],esi
  50029b:	33 d2                	xor    edx,edx
  50029d:	89 54 24 44          	mov    DWORD PTR [esp+0x44],edx
  5002a1:	89 54 24 48          	mov    DWORD PTR [esp+0x48],edx
  5002a5:	89 54 24 4c          	mov    DWORD PTR [esp+0x4c],edx
  5002a9:	89 54 24 60          	mov    DWORD PTR [esp+0x60],edx
  5002ad:	33 db                	xor    ebx,ebx
  5002af:	8d 72 01             	lea    esi,[edx+0x1]
  5002b2:	bf 10 02 00 00       	mov    edi,0x210
  5002b7:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  5002be:	75 27                	jne    0x5002e7
  5002c0:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  5002c7:	c6 44 24 60 01       	mov    BYTE PTR [esp+0x60],0x1
  5002cc:	e8 bf 12 fe ff       	call   0x4e1590
  5002d1:	68 80 cc bc 00       	push   0xbccc80
  5002d6:	e8 3f 20 39 00       	call   0x89231a
  5002db:	c6 44 24 64 00       	mov    BYTE PTR [esp+0x64],0x0
  5002e0:	8b 54 24 4c          	mov    edx,DWORD PTR [esp+0x4c]
  5002e4:	83 c4 04             	add    esp,0x4
  5002e7:	83 fe 09             	cmp    esi,0x9
  5002ea:	77 1c                	ja     0x500308
  5002ec:	a1 04 43 f9 00       	mov    eax,ds:0xf94304
  5002f1:	03 c7                	add    eax,edi
  5002f3:	83 78 5c 00          	cmp    DWORD PTR [eax+0x5c],0x0
  5002f7:	74 0f                	je     0x500308
  5002f9:	85 c0                	test   eax,eax
  5002fb:	74 0b                	je     0x500308
  5002fd:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  500300:	3b c3                	cmp    eax,ebx
  500302:	7f 02                	jg     0x500306
  500304:	8b c3                	mov    eax,ebx
  500306:	8b d8                	mov    ebx,eax
  500308:	81 c7 10 02 00 00    	add    edi,0x210
  50030e:	46                   	inc    esi
  50030f:	81 ff a0 14 00 00    	cmp    edi,0x14a0
  500315:	7c a0                	jl     0x5002b7
  500317:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  50031a:	8b b1 ac 5e 00 00    	mov    esi,DWORD PTR [ecx+0x5eac]
  500320:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  500323:	8b 08                	mov    ecx,DWORD PTR [eax]
  500325:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  500329:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  50032d:	89 4c 24 10          	mov    DWORD PTR [esp+0x10],ecx
  500331:	3b c8                	cmp    ecx,eax
  500333:	0f 84 83 02 00 00    	je     0x5005bc
  500339:	8b 7c 24 48          	mov    edi,DWORD PTR [esp+0x48]
  50033d:	8d 49 00             	lea    ecx,[ecx+0x0]
  500340:	8b 5c 24 10          	mov    ebx,DWORD PTR [esp+0x10]
  500344:	33 f6                	xor    esi,esi
  500346:	83 c3 10             	add    ebx,0x10
  500349:	f6 05 90 93 fb 00 01 	test   BYTE PTR ds:0xfb9390,0x1
  500350:	0f 85 b2 00 00 00    	jne    0x500408
  500356:	83 0d 90 93 fb 00 01 	or     DWORD PTR ds:0xfb9390,0x1
  50035d:	c6 44 24 60 02       	mov    BYTE PTR [esp+0x60],0x2
  500362:	6a 18                	push   0x18
  500364:	89 35 9c 93 fb 00    	mov    DWORD PTR ds:0xfb939c,esi
  50036a:	e8 f9 0e 39 00       	call   0x891268
  50036f:	83 c4 04             	add    esp,0x4
  500372:	3b c6                	cmp    eax,esi
  500374:	0f 84 8e 02 00 00    	je     0x500608
  50037a:	a3 98 93 fb 00       	mov    ds:0xfb9398,eax
  50037f:	89 00                	mov    DWORD PTR [eax],eax
  500381:	a1 98 93 fb 00       	mov    eax,ds:0xfb9398
  500386:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  500389:	a1 98 93 fb 00       	mov    eax,ds:0xfb9398
  50038e:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  500391:	8b 15 98 93 fb 00    	mov    edx,DWORD PTR ds:0xfb9398
  500397:	c6 42 14 01          	mov    BYTE PTR [edx+0x14],0x1
  50039b:	a1 98 93 fb 00       	mov    eax,ds:0xfb9398
  5003a0:	c6 40 15 01          	mov    BYTE PTR [eax+0x15],0x1
  5003a4:	c6 44 24 60 03       	mov    BYTE PTR [esp+0x60],0x3
  5003a9:	6a 18                	push   0x18
  5003ab:	89 35 ac 93 fb 00    	mov    DWORD PTR ds:0xfb93ac,esi
  5003b1:	e8 b2 0e 39 00       	call   0x891268
  5003b6:	83 c4 04             	add    esp,0x4
  5003b9:	3b c6                	cmp    eax,esi
  5003bb:	0f 84 1e 02 00 00    	je     0x5005df
  5003c1:	a3 a8 93 fb 00       	mov    ds:0xfb93a8,eax
  5003c6:	89 00                	mov    DWORD PTR [eax],eax
  5003c8:	a1 a8 93 fb 00       	mov    eax,ds:0xfb93a8
  5003cd:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  5003d0:	a1 a8 93 fb 00       	mov    eax,ds:0xfb93a8
  5003d5:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  5003d8:	8b 0d a8 93 fb 00    	mov    ecx,DWORD PTR ds:0xfb93a8
  5003de:	c6 41 14 01          	mov    BYTE PTR [ecx+0x14],0x1
  5003e2:	8b 15 a8 93 fb 00    	mov    edx,DWORD PTR ds:0xfb93a8
  5003e8:	c6 42 15 01          	mov    BYTE PTR [edx+0x15],0x1
  5003ec:	68 10 d6 bc 00       	push   0xbcd610
  5003f1:	c7 05 b4 93 fb 00 01 	mov    DWORD PTR ds:0xfb93b4,0x1
  5003f8:	00 00 00 
  5003fb:	e8 1a 1f 39 00       	call   0x89231a
  500400:	83 c4 04             	add    esp,0x4
  500403:	c6 44 24 60 00       	mov    BYTE PTR [esp+0x60],0x0
  500408:	8b 15 98 93 fb 00    	mov    edx,DWORD PTR ds:0xfb9398
  50040e:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  500411:	8b 33                	mov    esi,DWORD PTR [ebx]
  500413:	8b c8                	mov    ecx,eax
  500415:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  500419:	75 18                	jne    0x500433
  50041b:	eb 03                	jmp    0x500420
  50041d:	8d 49 00             	lea    ecx,[ecx+0x0]
  500420:	83 79 0c 09          	cmp    DWORD PTR [ecx+0xc],0x9
  500424:	7e 04                	jle    0x50042a
  500426:	8b 09                	mov    ecx,DWORD PTR [ecx]
  500428:	eb 03                	jmp    0x50042d
  50042a:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  50042d:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  500431:	74 ed                	je     0x500420
  500433:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  500437:	8b ca                	mov    ecx,edx
  500439:	75 4a                	jne    0x500485
  50043b:	eb 03                	jmp    0x500440
  50043d:	8d 49 00             	lea    ecx,[ecx+0x0]
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
  50048b:	0f 85 b9 00 00     	jne    0x50054a
```

### A14. QuestCandidate builder skip existing and level gate: VA `0x00500490..0x00500635`, raw `0x000FF890..0x000FFA35`

片段文字 SHA256 `07880d656a03e7ccce03b4a85f6caabf0fa673264c8e8ff72e39278b019e4b27`。

```asm
00500490 <.data+0xff890>:
  500490:	00 8b 43 0c 3b 44    	add    BYTE PTR [ebx+0x443b0c43],cl
  500496:	24 18                	and    al,0x18
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
  500555:	75 52                	jne    0x5005a9
  500557:	8b 4a 08             	mov    ecx,DWORD PTR [edx+0x8]
  50055a:	80 b9 b5 00 00 00 00 	cmp    BYTE PTR [ecx+0xb5],0x0
  500561:	75 1e                	jne    0x500581
  500563:	8b 01                	mov    eax,DWORD PTR [ecx]
  500565:	80 b8 b5 00 00 00 00 	cmp    BYTE PTR [eax+0xb5],0x0
  50056c:	75 0f                	jne    0x50057d
  50056e:	8b ff                	mov    edi,edi
  500570:	8b c8                	mov    ecx,eax
  500572:	8b 01                	mov    eax,DWORD PTR [ecx]
  500574:	80 b8 b5 00 00 00 00 	cmp    BYTE PTR [eax+0xb5],0x0
  50057b:	74 f3                	je     0x500570
  50057d:	8b d1                	mov    edx,ecx
  50057f:	eb 24                	jmp    0x5005a5
  500581:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  500584:	80 b8 b5 00 00 00 00 	cmp    BYTE PTR [eax+0xb5],0x0
  50058b:	75 16                	jne    0x5005a3
  50058d:	8d 49 00             	lea    ecx,[ecx+0x0]
  500590:	3b 50 08             	cmp    edx,DWORD PTR [eax+0x8]
  500593:	75 0e                	jne    0x5005a3
  500595:	8b d0                	mov    edx,eax
  500597:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  50059a:	80 b8 b5 00 00 00 00 	cmp    BYTE PTR [eax+0xb5],0x0
  5005a1:	74 ed                	je     0x500590
  5005a3:	8b d0                	mov    edx,eax
  5005a5:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  5005a9:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  5005ad:	3b 50 04             	cmp    edx,DWORD PTR [eax+0x4]
  5005b0:	0f 85 8a fd ff ff    	jne    0x500340
  5005b6:	8b 54 24 48          	mov    edx,DWORD PTR [esp+0x48]
  5005ba:	8b f0                	mov    esi,eax
  5005bc:	8b 44 24 44          	mov    eax,DWORD PTR [esp+0x44]
  5005c0:	2b d0                	sub    edx,eax
  5005c2:	c1 fa 02             	sar    edx,0x2
  5005c5:	89 54 24 28          	mov    DWORD PTR [esp+0x28],edx
  5005c9:	c7 44 24 1c 00 00 00 	mov    DWORD PTR [esp+0x1c],0x0
  5005d0:	00 
  5005d1:	85 d2                	test   edx,edx
  5005d3:	0f 84 c1 01 00 00    	je     0x50079a
  5005d9:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  5005dd:	eb 56                	jmp    0x500635
  5005df:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  5005e3:	51                   	push   ecx
  5005e4:	8d 4c 24 30          	lea    ecx,[esp+0x30]
  5005e8:	89 74 24 24          	mov    DWORD PTR [esp+0x24],esi
  5005ec:	e8 b8 0a 39 00       	call   0x8910a9
  5005f1:	68 a8 57 c8 00       	push   0xc857a8
  5005f6:	8d 54 24 30          	lea    edx,[esp+0x30]
  5005fa:	52                   	push   edx
  5005fb:	c7 44 24 34 a4 2c bd 	mov    DWORD PTR [esp+0x34],0xbd2ca4
  500602:	00 
  500603:	e8 e8 c3 39 00       	call   0x89c9f0
  500608:	8d 44 24 24          	lea    eax,[esp+0x24]
  50060c:	50                   	push   eax
  50060d:	8d 4c 24 3c          	lea    ecx,[esp+0x3c]
  500611:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  500615:	e8 8f 0a 39 00       	call   0x8910a9
  50061a:	68 a8 57 c8 00       	push   0xc857a8
  50061f:	8d 4c 24 3c          	lea    ecx,[esp+0x3c]
  500623:	51                   	push   ecx
  500624:	c7 44 24 40 a4 2c bd 	mov    DWORD PTR [esp+0x40],0xbd2ca4
  50062b:	00 
  50062c:	e8 bf c3 39 00       	call   0x89c9f0
  500631:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
```

### A15. QuestCandidate Demand filter and candidate append: VA `0x00500635..0x005007A0`, raw `0x000FFA35..0x000FFBA0`

片段文字 SHA256 `b6e550decd5d417d2d5021fd3f696db0f4b800bcfefd4196f5bf4f16b9d8dd77`。

```asm
00500635 <.data+0xffa35>:
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
  50079e:	8b 54            	mov    edx,DWORD PTR [esp+0x44]
```

### A16. QuestTalk field/QuestInfo Demands parser: VA `0x00504BC5..0x00504D36`, raw `0x00103FC5..0x00104136`

片段文字 SHA256 `e8051931aef29538ecebe2d861cb06899b85d2417bee504e07fd9673212dda59`。

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
```

### A17. TalkBox UI consumer 0x635CA0: VA `0x00635CA0..0x00635E8A`, raw `0x002350A0..0x0023528A`

片段文字 SHA256 `0c90abe369ce8008e8b5b81555be88d6f621c3de70e80160552927ee2a8bd249`。

```asm
00635ca0 <.data+0x2350a0>:
  635ca0:	55                   	push   ebp
  635ca1:	8b ec                	mov    ebp,esp
  635ca3:	6a ff                	push   0xffffffff
  635ca5:	68 04 8a 94 00       	push   0x948a04
  635caa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  635cb0:	50                   	push   eax
  635cb1:	83 ec 40             	sub    esp,0x40
  635cb4:	53                   	push   ebx
  635cb5:	56                   	push   esi
  635cb6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  635cbb:	33 c5                	xor    eax,ebp
  635cbd:	50                   	push   eax
  635cbe:	8d 45 f4             	lea    eax,[ebp-0xc]
  635cc1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  635cc7:	33 f6                	xor    esi,esi
  635cc9:	39 b7 b8 00 00 00    	cmp    DWORD PTR [edi+0xb8],esi
  635ccf:	0f 84 1f 02 00 00    	je     0x635ef4
  635cd5:	89 75 b4             	mov    DWORD PTR [ebp-0x4c],esi
  635cd8:	89 75 b8             	mov    DWORD PTR [ebp-0x48],esi
  635cdb:	89 75 bc             	mov    DWORD PTR [ebp-0x44],esi
  635cde:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  635ce1:	89 75 c4             	mov    DWORD PTR [ebp-0x3c],esi
  635ce4:	89 75 c8             	mov    DWORD PTR [ebp-0x38],esi
  635ce7:	89 75 cc             	mov    DWORD PTR [ebp-0x34],esi
  635cea:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635cee:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  635cf5:	75 21                	jne    0x635d18
  635cf7:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  635cfe:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  635d02:	e8 59 a1 ec ff       	call   0x4ffe60
  635d07:	68 00 cf bc 00       	push   0xbccf00
  635d0c:	e8 09 c6 25 00       	call   0x89231a
  635d11:	83 c4 04             	add    esp,0x4
  635d14:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
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
  635d8a:	89 75 d4             	mov    DWORD PTR [ebp-0x2c],esi
  635d8d:	89 75 d8             	mov    DWORD PTR [ebp-0x28],esi
  635d90:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  635d93:	c6 45 fc 04          	mov    BYTE PTR [ebp-0x4],0x4
  635d97:	8b 87 b8 00 00 00    	mov    eax,DWORD PTR [edi+0xb8]
  635d9d:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  635da0:	2b 48 40             	sub    ecx,DWORD PTR [eax+0x40]
  635da3:	b8 39 8e e3 38       	mov    eax,0x38e38e39
  635da8:	f7 e9                	imul   ecx
  635daa:	c1 fa 03             	sar    edx,0x3
  635dad:	8b c2                	mov    eax,edx
  635daf:	c1 e8 1f             	shr    eax,0x1f
  635db2:	03 c2                	add    eax,edx
  635db4:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  635db7:	0f 84 82 00 00 00    	je     0x635e3f
  635dbd:	89 75 ec             	mov    DWORD PTR [ebp-0x14],esi
  635dc0:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  635dc3:	8b 97 b8 00 00 00    	mov    edx,DWORD PTR [edi+0xb8]
  635dc9:	8b 5a 40             	mov    ebx,DWORD PTR [edx+0x40]
  635dcc:	03 5d ec             	add    ebx,DWORD PTR [ebp-0x14]
  635dcf:	53                   	push   ebx
  635dd0:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  635dd3:	e8 c8 e5 ee ff       	call   0x5243a0
  635dd8:	85 c0                	test   eax,eax
  635dda:	74 5a                	je     0x635e36
  635ddc:	8b 03                	mov    eax,DWORD PTR [ebx]
  635dde:	39 45 e8             	cmp    DWORD PTR [ebp-0x18],eax
  635de1:	7d 03                	jge    0x635de6
  635de3:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  635de6:	8d 45 f0             	lea    eax,[ebp-0x10]
  635de9:	3b c6                	cmp    eax,esi
  635deb:	73 2d                	jae    0x635e1a
  635ded:	8b c8                	mov    ecx,eax
  635def:	39 4d d4             	cmp    DWORD PTR [ebp-0x2c],ecx
  635df2:	77 26                	ja     0x635e1a
  635df4:	8b d8                	mov    ebx,eax
  635df6:	2b 5d d4             	sub    ebx,DWORD PTR [ebp-0x2c]
  635df9:	c1 fb 02             	sar    ebx,0x2
  635dfc:	3b 75 dc             	cmp    esi,DWORD PTR [ebp-0x24]
  635dff:	75 0b                	jne    0x635e0c
  635e01:	8d 45 d4             	lea    eax,[ebp-0x2c]
  635e04:	e8 a7 8c ea ff       	call   0x4deab0
  635e09:	8b 75 d8             	mov    esi,DWORD PTR [ebp-0x28]
  635e0c:	85 f6                	test   esi,esi
  635e0e:	74 20                	je     0x635e30
  635e10:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  635e13:	8b 04 9a             	mov    eax,DWORD PTR [edx+ebx*4]
  635e16:	89 06                	mov    DWORD PTR [esi],eax
  635e18:	eb 16                	jmp    0x635e30
  635e1a:	3b 75 dc             	cmp    esi,DWORD PTR [ebp-0x24]
  635e1d:	75 0b                	jne    0x635e2a
  635e1f:	8d 45 d4             	lea    eax,[ebp-0x2c]
  635e22:	e8 89 8c ea ff       	call   0x4deab0
  635e27:	8b 75 d8             	mov    esi,DWORD PTR [ebp-0x28]
  635e2a:	85 f6                	test   esi,esi
  635e2c:	74 02                	je     0x635e30
  635e2e:	89 1e                	mov    DWORD PTR [esi],ebx
  635e30:	83 c6 04             	add    esi,0x4
  635e33:	89 75 d8             	mov    DWORD PTR [ebp-0x28],esi
  635e36:	83 45 ec 24          	add    DWORD PTR [ebp-0x14],0x24
  635e3a:	ff 4d e4             	dec    DWORD PTR [ebp-0x1c]
  635e3d:	75 84                	jne    0x635dc3
  635e3f:	8b 5d d4             	mov    ebx,DWORD PTR [ebp-0x2c]
  635e42:	3b de                	cmp    ebx,esi
  635e44:	74 31                	je     0x635e77
  635e46:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  635e48:	8b 55 e8             	mov    edx,DWORD PTR [ebp-0x18]
  635e4b:	39 11                	cmp    DWORD PTR [ecx],edx
  635e4d:	74 1e                	je     0x635e6d
  635e4f:	8d 43 04             	lea    eax,[ebx+0x4]
  635e52:	8b ce                	mov    ecx,esi
  635e54:	2b c8                	sub    ecx,eax
  635e56:	c1 f9 02             	sar    ecx,0x2
  635e59:	03 c9                	add    ecx,ecx
  635e5b:	03 c9                	add    ecx,ecx
  635e5d:	51                   	push   ecx
  635e5e:	50                   	push   eax
  635e5f:	53                   	push   ebx
  635e60:	e8 8b b4 25 00       	call   0x8912f0
  635e65:	83 c4 0c             	add    esp,0xc
  635e68:	83 ee 04             	sub    esi,0x4
  635e6b:	eb 03                	jmp    0x635e70
  635e6d:	83 c3 04             	add    ebx,0x4
  635e70:	3b de                	cmp    ebx,esi
  635e72:	75 d2                	jne    0x635e46
  635e74:	89 75 d8             	mov    DWORD PTR [ebp-0x28],esi
  635e77:	33 c0                	xor    eax,eax
  635e79:	89 87 98 00 00 00    	mov    DWORD PTR [edi+0x98],eax
  635e7f:	39 75 d4             	cmp    DWORD PTR [ebp-0x2c],esi
  635e82:	74 2f                	je     0x635eb3
  635e84:	e8 14 ca 25 00       	call   0x89289d
  635e89:	8b               	mov    ebx,DWORD PTR [ebp-0x2c]
```

### A18. TalkBox call site for consumer: VA `0x006365D0..0x00636705`, raw `0x002359D0..0x00235B05`

片段文字 SHA256 `8f2da9510d978df313d18b44c925fe4b658547e7ff2a39429a59762072d6f513`。

```asm
006365d0 <.data+0x2359d0>:
  6365d0:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  6365d3:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  6365d7:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  6365da:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  6365de:	c6 41 20 01          	mov    BYTE PTR [ecx+0x20],0x1
  6365e2:	8b 54 24 28          	mov    edx,DWORD PTR [esp+0x28]
  6365e6:	c6 42 21 01          	mov    BYTE PTR [edx+0x21],0x1
  6365ea:	53                   	push   ebx
  6365eb:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  6365ef:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  6365f5:	8b 97 80 00 00 00    	mov    edx,DWORD PTR [edi+0x80]
  6365fb:	8d 44 24 28          	lea    eax,[esp+0x28]
  6365ff:	50                   	push   eax
  636600:	a1 b4 1d fe 00       	mov    eax,ds:0xfe1db4
  636605:	51                   	push   ecx
  636606:	52                   	push   edx
  636607:	50                   	push   eax
  636608:	e8 43 5c ec ff       	call   0x4fc250
  63660d:	39 5c 24 2c          	cmp    DWORD PTR [esp+0x2c],ebx
  636611:	8b 87 90 00 00 00    	mov    eax,DWORD PTR [edi+0x90]
  636617:	0f 95 c1             	setne  cl
  63661a:	88 8f 8c 00 00 00    	mov    BYTE PTR [edi+0x8c],cl
  636620:	83 f8 03             	cmp    eax,0x3
  636623:	0f 87 e3 00 00 00    	ja     0x63670c
  636629:	ff 24 85 74 67 63 00 	jmp    DWORD PTR [eax*4+0x636774]
  636630:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636636:	8b 11                	mov    edx,DWORD PTR [ecx]
  636638:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63663b:	ff d0                	call   eax
  63663d:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636643:	8b 11                	mov    edx,DWORD PTR [ecx]
  636645:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  636648:	ff d0                	call   eax
  63664a:	e8 51 f6 ff ff       	call   0x635ca0
  63664f:	e9 b8 00 00 00       	jmp    0x63670c
  636654:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63665a:	8b 11                	mov    edx,DWORD PTR [ecx]
  63665c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63665f:	ff d0                	call   eax
  636661:	e8 ca 92 dd ff       	call   0x40f930
  636666:	8b c8                	mov    ecx,eax
  636668:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63666b:	e8 20 a9 ec ff       	call   0x500f90
  636670:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  636676:	3b c3                	cmp    eax,ebx
  636678:	74 73                	je     0x6366ed
  63667a:	8b 48 30             	mov    ecx,DWORD PTR [eax+0x30]
  63667d:	51                   	push   ecx
  63667e:	8b c7                	mov    eax,edi
  636680:	e8 8b f8 ff ff       	call   0x635f10
  636685:	eb 72                	jmp    0x6366f9
  636687:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63668d:	8b 11                	mov    edx,DWORD PTR [ecx]
  63668f:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  636692:	ff d0                	call   eax
  636694:	e8 97 92 dd ff       	call   0x40f930
  636699:	8b c8                	mov    ecx,eax
  63669b:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63669e:	e8 ed a8 ec ff       	call   0x500f90
  6366a3:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366a9:	3b c3                	cmp    eax,ebx
  6366ab:	74 40                	je     0x6366ed
  6366ad:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
  6366b0:	51                   	push   ecx
  6366b1:	8b c7                	mov    eax,edi
  6366b3:	e8 58 f8 ff ff       	call   0x635f10
  6366b8:	eb 3f                	jmp    0x6366f9
  6366ba:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  6366c0:	8b 11                	mov    edx,DWORD PTR [ecx]
  6366c2:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  6366c5:	ff d0                	call   eax
  6366c7:	e8 64 92 dd ff       	call   0x40f930
  6366cc:	8b c8                	mov    ecx,eax
  6366ce:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  6366d1:	e8 ba a8 ec ff       	call   0x500f90
  6366d6:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366dc:	3b c3                	cmp    eax,ebx
  6366de:	74 0d                	je     0x6366ed
  6366e0:	8b 48 38             	mov    ecx,DWORD PTR [eax+0x38]
  6366e3:	51                   	push   ecx
  6366e4:	8b c7                	mov    eax,edi
  6366e6:	e8 25 f8 ff ff       	call   0x635f10
  6366eb:	eb 0c                	jmp    0x6366f9
  6366ed:	8b 17                	mov    edx,DWORD PTR [edi]
  6366ef:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  6366f5:	8b cf                	mov    ecx,edi
  6366f7:	ff d0                	call   eax
  6366f9:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  6366ff:	8b 11                	mov    edx,DWORD PTR [ecx]
  636701:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  636704:	ff                 	call   eax
```

### A19. Scene handler 0x38 separate owner and quest rebuild: VA `0x004B1BF0..0x004B1E0F`, raw `0x000B0FF0..0x000B120F`

片段文字 SHA256 `326ea26369946195452901618d9dc0b47b39eb74bab4d8bab018d2bd7aaf8024`。

```asm
004b1bf0 <.data+0xb0ff0>:
  4b1bf0:	55                   	push   ebp
  4b1bf1:	8b ec                	mov    ebp,esp
  4b1bf3:	83 e4 f8             	and    esp,0xfffffff8
  4b1bf6:	6a ff                	push   0xffffffff
  4b1bf8:	68 7c 7d 94 00       	push   0x947d7c
  4b1bfd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b1c03:	50                   	push   eax
  4b1c04:	83 ec 08             	sub    esp,0x8
  4b1c07:	53                   	push   ebx
  4b1c08:	56                   	push   esi
  4b1c09:	57                   	push   edi
  4b1c0a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b1c0f:	33 c4                	xor    eax,esp
  4b1c11:	50                   	push   eax
  4b1c12:	8d 44 24 18          	lea    eax,[esp+0x18]
  4b1c16:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b1c1c:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b1c23:	bf 01 00 00 00       	mov    edi,0x1
  4b1c28:	75 29                	jne    0x4b1c53
  4b1c2a:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  4b1c30:	c7 44 24 20 00 00 00 	mov    DWORD PTR [esp+0x20],0x0
  4b1c37:	00 
  4b1c38:	e8 53 d0 02 00       	call   0x4dec90
  4b1c3d:	68 30 ce bc 00       	push   0xbcce30
  4b1c42:	e8 d3 06 3e 00       	call   0x89231a
  4b1c47:	83 c4 04             	add    esp,0x4
  4b1c4a:	83 ce ff             	or     esi,0xffffffff
  4b1c4d:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b1c51:	eb 03                	jmp    0x4b1c56
  4b1c53:	83 ce ff             	or     esi,0xffffffff
  4b1c56:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b1c5b:	50                   	push   eax
  4b1c5c:	e8 1f be 08 00       	call   0x53da80
  4b1c61:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b1c68:	75 20                	jne    0x4b1c8a
  4b1c6a:	09 3d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,edi
  4b1c70:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  4b1c74:	e8 17 d0 02 00       	call   0x4dec90
  4b1c79:	68 30 ce bc 00       	push   0xbcce30
  4b1c7e:	e8 97 06 3e 00       	call   0x89231a
  4b1c83:	83 c4 04             	add    esp,0x4
  4b1c86:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b1c8a:	f6 05 44 92 fd 00 01 	test   BYTE PTR ds:0xfd9244,0x1
  4b1c91:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4b1c94:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4b1c96:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b1c9b:	89 48 34             	mov    DWORD PTR [eax+0x34],ecx
  4b1c9e:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  4b1ca1:	89 50 38             	mov    DWORD PTR [eax+0x38],edx
  4b1ca4:	8a 4b 08             	mov    cl,BYTE PTR [ebx+0x8]
  4b1ca7:	88 48 3c             	mov    BYTE PTR [eax+0x3c],cl
  4b1caa:	75 24                	jne    0x4b1cd0
  4b1cac:	09 3d 44 92 fd 00    	or     DWORD PTR ds:0xfd9244,edi
  4b1cb2:	c7 44 24 20 02 00 00 	mov    DWORD PTR [esp+0x20],0x2
  4b1cb9:	00 
  4b1cba:	e8 51 27 0a 00       	call   0x554410
  4b1cbf:	68 c0 df bc 00       	push   0xbcdfc0
  4b1cc4:	e8 51 06 3e 00       	call   0x89231a
  4b1cc9:	83 c4 04             	add    esp,0x4
  4b1ccc:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b1cd0:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  4b1cd7:	c7 05 54 92 fd 00 00 	mov    DWORD PTR ds:0xfd9254,0x0
  4b1cde:	00 00 00 
  4b1ce1:	75 24                	jne    0x4b1d07
  4b1ce3:	09 3d b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,edi
  4b1ce9:	c7 44 24 20 03 00 00 	mov    DWORD PTR [esp+0x20],0x3
  4b1cf0:	00 
  4b1cf1:	e8 7a e4 0a 00       	call   0x560170
  4b1cf6:	68 10 d1 bc 00       	push   0xbcd110
  4b1cfb:	e8 1a 06 3e 00       	call   0x89231a
  4b1d00:	83 c4 04             	add    esp,0x4
  4b1d03:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b1d07:	6a 00                	push   0x0
  4b1d09:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  4b1d0e:	e8 9d 07 0b 00       	call   0x5624b0
  4b1d13:	0f b6 43 02          	movzx  eax,BYTE PTR [ebx+0x2]
  4b1d17:	83 e8 00             	sub    eax,0x0
  4b1d1a:	0f 84 cb 00 00 00    	je     0x4b1deb
  4b1d20:	83 e8 02             	sub    eax,0x2
  4b1d23:	74 5f                	je     0x4b1d84
  4b1d25:	83 e8 04             	sub    eax,0x4
  4b1d28:	0f 85 e0 00 00 00    	jne    0x4b1e0e
  4b1d2e:	f6 05 40 0e fc 00 01 	test   BYTE PTR ds:0xfc0e40,0x1
  4b1d35:	75 24                	jne    0x4b1d5b
  4b1d37:	09 3d 40 0e fc 00    	or     DWORD PTR ds:0xfc0e40,edi
  4b1d3d:	c7 44 24 20 05 00 00 	mov    DWORD PTR [esp+0x20],0x5
  4b1d44:	00 
  4b1d45:	e8 26 ea 08 00       	call   0x540770
  4b1d4a:	68 60 db bc 00       	push   0xbcdb60
  4b1d4f:	e8 c6 05 3e 00       	call   0x89231a
  4b1d54:	83 c4 04             	add    esp,0x4
  4b1d57:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b1d5b:	0f b7 53 07          	movzx  edx,WORD PTR [ebx+0x7]
  4b1d5f:	52                   	push   edx
  4b1d60:	bf 48 0e fc 00       	mov    edi,0xfc0e48
  4b1d65:	e8 16 ec 08 00       	call   0x540980
  4b1d6a:	0f b7 73 03          	movzx  esi,WORD PTR [ebx+0x3]
  4b1d6e:	e8 ed d2 f5 ff       	call   0x40f060
  4b1d73:	89 b0 8c 00 00 00    	mov    DWORD PTR [eax+0x8c],esi
  4b1d79:	83 ce ff             	or     esi,0xffffffff
  4b1d7c:	8d 7e 02             	lea    edi,[esi+0x2]
  4b1d7f:	e9 8a 00 00 00       	jmp    0x4b1e0e
  4b1d84:	f6 05 40 0e fc 00 01 	test   BYTE PTR ds:0xfc0e40,0x1
  4b1d8b:	75 24                	jne    0x4b1db1
  4b1d8d:	09 3d 40 0e fc 00    	or     DWORD PTR ds:0xfc0e40,edi
  4b1d93:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  4b1d9a:	00 
  4b1d9b:	e8 d0 e9 08 00       	call   0x540770
  4b1da0:	68 60 db bc 00       	push   0xbcdb60
  4b1da5:	e8 70 05 3e 00       	call   0x89231a
  4b1daa:	83 c4 04             	add    esp,0x4
  4b1dad:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b1db1:	0f b7 43 07          	movzx  eax,WORD PTR [ebx+0x7]
  4b1db5:	50                   	push   eax
  4b1db6:	bf 48 0e fc 00       	mov    edi,0xfc0e48
  4b1dbb:	e8 c0 eb 08 00       	call   0x540980
  4b1dc0:	f6 05 98 18 fe 00 01 	test   BYTE PTR ds:0xfe1898,0x1
  4b1dc7:	75 14                	jne    0x4b1ddd
  4b1dc9:	83 0d 98 18 fe 00 01 	or     DWORD PTR ds:0xfe1898,0x1
  4b1dd0:	68 20 e8 bc 00       	push   0xbce820
  4b1dd5:	e8 40 05 3e 00       	call   0x89231a
  4b1dda:	83 c4 04             	add    esp,0x4
  4b1ddd:	8b cb                	mov    ecx,ebx
  4b1ddf:	e8 dc 11 0a 00       	call   0x552fc0
  4b1de4:	bf 01 00 00 00       	mov    edi,0x1
  4b1de9:	eb 23                	jmp    0x4b1e0e
  4b1deb:	f6 05 98 18 fe 00 01 	test   BYTE PTR ds:0xfe1898,0x1
  4b1df2:	75 13                	jne    0x4b1e07
  4b1df4:	09 3d 98 18 fe 00    	or     DWORD PTR ds:0xfe1898,edi
  4b1dfa:	68 20 e8 bc 00       	push   0xbce820
  4b1dff:	e8 16 05 3e 00       	call   0x89231a
  4b1e04:	83 c4 04             	add    esp,0x4
  4b1e07:	8b cb                	mov    ecx,ebx
  4b1e09:	e8 b2 11 0a 00       	call   0x552fc0
  4b1e0e:	f6       	test   BYTE PTR ds:0xfb1378,0x1
```

### A20. Scene handler 0x38 call 0x500240: VA `0x004B2020..0x004B2110`, raw `0x000B1420..0x000B1510`

片段文字 SHA256 `1dd16ca434eb4604f927d3cd8f63a21e428618a25e713e9ab0bd888e7fb6053b`。

```asm
004b2020 <.data+0xb1420>:
  4b2020:	c7 05 30 a8 fb 00 00 	mov    DWORD PTR ds:0xfba830,0x0
  4b2027:	00 00 00 
  4b202a:	75 24                	jne    0x4b2050
  4b202c:	09 3d 40 0e fc 00    	or     DWORD PTR ds:0xfc0e40,edi
  4b2032:	c7 44 24 20 0a 00 00 	mov    DWORD PTR [esp+0x20],0xa
  4b2039:	00 
  4b203a:	e8 31 e7 08 00       	call   0x540770
  4b203f:	68 60 db bc 00       	push   0xbcdb60
  4b2044:	e8 d1 02 3e 00       	call   0x89231a
  4b2049:	83 c4 04             	add    esp,0x4
  4b204c:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b2050:	0f b7 4b 03          	movzx  ecx,WORD PTR [ebx+0x3]
  4b2054:	51                   	push   ecx
  4b2055:	bf 48 0e fc 00       	mov    edi,0xfc0e48
  4b205a:	e8 e1 e9 08 00       	call   0x540a40
  4b205f:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b2066:	75 25                	jne    0x4b208d
  4b2068:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4b206f:	c7 44 24 20 0b 00 00 	mov    DWORD PTR [esp+0x20],0xb
  4b2076:	00 
  4b2077:	e8 14 cc 02 00       	call   0x4dec90
  4b207c:	68 30 ce bc 00       	push   0xbcce30
  4b2081:	e8 94 02 3e 00       	call   0x89231a
  4b2086:	83 c4 04             	add    esp,0x4
  4b2089:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b208d:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b2094:	0f b7 53 03          	movzx  edx,WORD PTR [ebx+0x3]
  4b2098:	89 15 bc b1 fa 00    	mov    DWORD PTR ds:0xfab1bc,edx
  4b209e:	75 25                	jne    0x4b20c5
  4b20a0:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4b20a7:	c7 44 24 20 0c 00 00 	mov    DWORD PTR [esp+0x20],0xc
  4b20ae:	00 
  4b20af:	e8 dc cb 02 00       	call   0x4dec90
  4b20b4:	68 30 ce bc 00       	push   0xbcce30
  4b20b9:	e8 5c 02 3e 00       	call   0x89231a
  4b20be:	83 c4 04             	add    esp,0x4
  4b20c1:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4b20c5:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b20cc:	8b 35 bc b1 fa 00    	mov    esi,DWORD PTR ds:0xfab1bc
  4b20d2:	75 29                	jne    0x4b20fd
  4b20d4:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4b20db:	c7 44 24 20 0d 00 00 	mov    DWORD PTR [esp+0x20],0xd
  4b20e2:	00 
  4b20e3:	e8 78 dd 04 00       	call   0x4ffe60
  4b20e8:	68 00 cf bc 00       	push   0xbccf00
  4b20ed:	e8 28 02 3e 00       	call   0x89231a
  4b20f2:	83 c4 04             	add    esp,0x4
  4b20f5:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  4b20fc:	ff 
  4b20fd:	56                   	push   esi
  4b20fe:	68 a0 b2 fa 00       	push   0xfab2a0
  4b2103:	e8 38 e1 04 00       	call   0x500240
  4b2108:	f6 05 d4 b0 fa 00 01 	test   BYTE PTR ds:0xfab0d4,0x1
  4b210f:	75                 	jne    0x4b213a
```

### A21. Scene handler 0x5C other rebuild path: VA `0x004B3DA0..0x004B3ED0`, raw `0x000B31A0..0x000B32D0`

片段文字 SHA256 `d1f770dd0ec87f3253a529bc85a34387fa1dfd0d62ee7a21d93d8071b6ddd040`。

```asm
004b3da0 <.data+0xb31a0>:
  4b3da0:	55                   	push   ebp
  4b3da1:	8b ec                	mov    ebp,esp
  4b3da3:	6a ff                	push   0xffffffff
  4b3da5:	68 14 7c 94 00       	push   0x947c14
  4b3daa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b3db0:	50                   	push   eax
  4b3db1:	83 ec 20             	sub    esp,0x20
  4b3db4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b3db9:	33 c5                	xor    eax,ebp
  4b3dbb:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4b3dbe:	53                   	push   ebx
  4b3dbf:	56                   	push   esi
  4b3dc0:	50                   	push   eax
  4b3dc1:	8d 45 f4             	lea    eax,[ebp-0xc]
  4b3dc4:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b3dca:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b3dcd:	e8 ce 0d f5 ff       	call   0x404ba0
  4b3dd2:	8b 88 24 69 00 00    	mov    ecx,DWORD PTR [eax+0x6924]
  4b3dd8:	0f b6 46 02          	movzx  eax,BYTE PTR [esi+0x2]
  4b3ddc:	83 f8 09             	cmp    eax,0x9
  4b3ddf:	77 19                	ja     0x4b3dfa
  4b3de1:	69 c0 10 02 00 00    	imul   eax,eax,0x210
  4b3de7:	03 c8                	add    ecx,eax
  4b3de9:	83 79 5c 00          	cmp    DWORD PTR [ecx+0x5c],0x0
  4b3ded:	74 0b                	je     0x4b3dfa
  4b3def:	85 c9                	test   ecx,ecx
  4b3df1:	74 07                	je     0x4b3dfa
  4b3df3:	8b c6                	mov    eax,esi
  4b3df5:	e8 a6 03 02 00       	call   0x4d41a0
  4b3dfa:	e8 61 b2 f5 ff       	call   0x40f060
  4b3dff:	8b b0 8c 00 00 00    	mov    esi,DWORD PTR [eax+0x8c]
  4b3e05:	bb 01 00 00 00       	mov    ebx,0x1
  4b3e0a:	84 1d 9c b2 fa 00    	test   BYTE PTR ds:0xfab29c,bl
  4b3e10:	75 26                	jne    0x4b3e38
  4b3e12:	09 1d 9c b2 fa 00    	or     DWORD PTR ds:0xfab29c,ebx
  4b3e18:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4b3e1f:	e8 3c c0 04 00       	call   0x4ffe60
  4b3e24:	68 00 cf bc 00       	push   0xbccf00
  4b3e29:	e8 ec e4 3d 00       	call   0x89231a
  4b3e2e:	83 c4 04             	add    esp,0x4
  4b3e31:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4b3e38:	56                   	push   esi
  4b3e39:	68 a0 b2 fa 00       	push   0xfab2a0
  4b3e3e:	e8 fd c3 04 00       	call   0x500240
  4b3e43:	68 4c 6d c0 00       	push   0xc06d4c
  4b3e48:	b8 0c 00 00 00       	mov    eax,0xc
  4b3e4d:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4b3e50:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  4b3e57:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  4b3e5e:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  4b3e62:	e8 a9 74 f5 ff       	call   0x40b310
  4b3e67:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4b3e6a:	84 1d d4 b0 fa 00    	test   BYTE PTR ds:0xfab0d4,bl
  4b3e70:	75 1f                	jne    0x4b3e91
  4b3e72:	09 1d d4 b0 fa 00    	or     DWORD PTR ds:0xfab0d4,ebx
  4b3e78:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  4b3e7c:	e8 1f 65 35 00       	call   0x80a3a0
  4b3e81:	68 d0 cd bc 00       	push   0xbccdd0
  4b3e86:	e8 8f e4 3d 00       	call   0x89231a
  4b3e8b:	83 c4 04             	add    esp,0x4
  4b3e8e:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  4b3e91:	68 28 b0 fa 00       	push   0xfab028
  4b3e96:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  4b3e99:	e8 62 6c 35 00       	call   0x80ab00
  4b3e9e:	85 c0                	test   eax,eax
  4b3ea0:	74 09                	je     0x4b3eab
  4b3ea2:	8b 10                	mov    edx,DWORD PTR [eax]
  4b3ea4:	8b c8                	mov    ecx,eax
  4b3ea6:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4b3ea9:	ff d0                	call   eax
  4b3eab:	83 7d e8 10          	cmp    DWORD PTR [ebp-0x18],0x10
  4b3eaf:	72 0c                	jb     0x4b3ebd
  4b3eb1:	8b 4d d4             	mov    ecx,DWORD PTR [ebp-0x2c]
  4b3eb4:	51                   	push   ecx
  4b3eb5:	e8 52 d3 3d 00       	call   0x89120c
  4b3eba:	83 c4 04             	add    esp,0x4
  4b3ebd:	33 c0                	xor    eax,eax
  4b3ebf:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4b3ec2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b3ec9:	59                   	pop    ecx
  4b3eca:	5e                   	pop    esi
  4b3ecb:	5b                   	pop    ebx
  4b3ecc:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  4b3ecf:	33                 	xor    ecx,ebp
```

### A22. Scenario 0x4C handler (different namespace): VA `0x004C4F20..0x004C4FA0`, raw `0x000C4320..0x000C43A0`

片段文字 SHA256 `3f2f024962ff700f9648b15aedb7a764ad3ffba51567c598e197d1b3baae6b38`。

```asm
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

## 12. 證據與提交驗證檢查表

- [x] Client原始BIN SHA256、PE section mapping、bounds；不從 .data unloaded virtual zeroes 猜初值。
- [x] top-level **index 116** 以正確 base+0x208 stride 算式查原生 slot。
- [x] Quest owner vtable+4 和 8-byte callback 116 跨層核對。
- [x] `0x503400` payload+2 -> `0x44B4E0` WORD append -> `0x500240`。
- [x] Quest16 XML Demand14 與 `0x500240` DWORD Demand-vs-u16 membership。
- [x] candidate vector 下游 `0x500950`, `0x635CA0` UI flags。
- [x] S00 server-only decision 與 unknown client refresh 区分。
- [ ] 未有實際 Client runtime/S2C 捕獲，本研究不宣稱。
- [ ] 未獲 T01 整篇 FULL-PASS，不自稱。
- [ ] 原稿 Commit/Push 及遠端 Blob 驗證於提交後另行記錄，不在本文預先假稱。
